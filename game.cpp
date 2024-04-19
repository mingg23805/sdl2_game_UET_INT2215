#include "Game.h"



Game::Game(SDL_Window* window, SDL_Renderer* renderer, int windowWidth, int windowHeight) :
    placementModeCurrent(PlacementMode::wall),
    level(renderer, windowWidth / tileSize, windowHeight / tileSize) ,
    spawnT(0.25f),roundT(5.0f)
    {

    if (window != nullptr && renderer != nullptr) {


        textureOverlay = TextureLoader::loadTexture(renderer, "Overlay.bmp");
      //  mix_chunkSpawnUnit= SoundLoader::loadSound("Data/Sounds/shoot.ogg");

        auto time1 = std::chrono::system_clock::now();
        auto time2 = std::chrono::system_clock::now();

        const float dT = 1.0f / 60.0f;


        bool running = true;
        while (running) {
            time2 = std::chrono::system_clock::now();
            std::chrono::duration<float> timeDelta = time2 - time1;
            float timeDeltaFloat = timeDelta.count();

            if (timeDeltaFloat >= dT) {
                time1 = time2;

                processEvents(renderer, running);
                update(dT,renderer);
                draw(renderer);
            }
        }
    }
}


Game::~Game() {
    TextureLoader::deallocateTextures();
   // lv=0;
  // SoundLoader::deallocateSounds();
}



void Game::processEvents(SDL_Renderer* renderer, bool& running) {
    bool mouseDownThisFrame = false;
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            running = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            mouseDownThisFrame = (mouseDownStatus == 0);
            if (event.button.button == SDL_BUTTON_LEFT)
                mouseDownStatus = SDL_BUTTON_LEFT;
            else if (event.button.button == SDL_BUTTON_RIGHT)
                mouseDownStatus = SDL_BUTTON_RIGHT;
            break;
        case SDL_MOUSEBUTTONUP:
            mouseDownStatus = 0;
            break;

        case SDL_KEYDOWN:
            switch (event.key.keysym.scancode) {

            case SDL_SCANCODE_ESCAPE:
                running = false;
                break;

            case SDL_SCANCODE_1:
                placementModeCurrent = PlacementMode::wall;
                break;
            case SDL_SCANCODE_2:
                placementModeCurrent = PlacementMode::turret;
                break;


            case SDL_SCANCODE_H:
                overlayVisible = !overlayVisible;
                break;
            }
        }
    }



    int mouseX = 0, mouseY = 0;
    SDL_GetMouseState(&mouseX, &mouseY);

    Vector2D posMouse((float)mouseX / tileSize, (float)mouseY / tileSize);

    if (mouseDownStatus > 0) {
        switch (mouseDownStatus) {
        case SDL_BUTTON_LEFT:
            switch (placementModeCurrent) {
            case PlacementMode::wall:

                level.setTileWall((int)posMouse.x, (int)posMouse.y, true);
                break;
            case PlacementMode::turret:

                if (mouseDownThisFrame&&
                    level.isTileWall((int)posMouse.x, (int)posMouse.y )&&
                     isTurretAt( posMouse.x, posMouse.y )==false  )
                    addTurret(renderer,posMouse);
                break;
            }
            break;


        case SDL_BUTTON_RIGHT:

            level.setTileWall((int)posMouse.x, (int)posMouse.y, false);


            break;
        }
    }
}



void Game::update(float dT,SDL_Renderer *renderer) {

     updateUnits(dT);
    for(auto&selectedTurret : listTurrets)
      selectedTurret.update(dT,listUnits,renderer,listProjectiles );


   updateProjectiles(dT);

      updateSpawnUnits(renderer,dT);

      if(mainTowerHp<=0) std::cout<<"youLose";
}
void Game::updateSpawnUnits(SDL_Renderer *renderer,float dT)
{
   spawnT.countDown(dT);
   if(listUnits.empty() && unitCount==0)
   {   roundT.countDown(dT);
       if(roundT.timeSIsZero()==true)
     {  lv++;
       unitCount=15;
       roundT.resetToMax();


     }
   }
   if(unitCount>0 && spawnT.timeSIsZero())
   {
       addUnit(renderer,level.getRanSpawnerLocation());
       unitCount--;

        //if ( mix_chunkSpawnUnit != nullptr)
        //    Mix_PlayChannel(-1, mix_chunkSpawnUnit, 0);

        spawnT.resetToMax();
   }

}
void Game::updateUnits(float dT)
{
    auto it= listUnits.begin();
    while( it!=listUnits.end() )
    {
     bool increase=true;
        if(*(it)!=nullptr)
        {
          (*it)->update(dT,level,listUnits);

           if((*it) -> checkALive()==false )
          { if( (*it)->hasReachedTarget(level) ) mainTowerHp--;
           it=listUnits.erase(it);
           increase=false;
          }
        }
        if(increase)
            it++;
    }
}
void Game::updateProjectiles(float dT)
{
    auto it=listProjectiles.begin();
    while(it!=listProjectiles.end())
    {
        (*it).update(dT,listUnits);
        if((*it).getCollison())
        {
            it=listProjectiles.erase(it);

        }
        else
        {
            it++;
        }
    }

}
void Game::draw(SDL_Renderer* renderer) {

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_RenderClear(renderer);



    level.draw(renderer, tileSize);

    for (auto& unitSelected : listUnits)
        if(unitSelected != nullptr)unitSelected->draw(renderer, tileSize);



    for (auto& selectedTurret : listTurrets)
        selectedTurret.draw(renderer, tileSize);

        for(auto&selectedProjectile : listProjectiles)
     selectedProjectile.draw(renderer,tileSize);



    if (textureOverlay != nullptr && overlayVisible) {
        int w = 0, h = 0;
        SDL_QueryTexture(textureOverlay, NULL, NULL, &w, &h);
        SDL_Rect rect = { 40, 40, w, h };
        SDL_RenderCopy(renderer, textureOverlay, NULL, &rect);
    }

    SDL_RenderPresent(renderer);
}



void Game::addUnit(SDL_Renderer* renderer, Vector2D posMouse) {
      std::shared_ptr<Unit> newUnit = std::make_shared<Unit>(renderer, posMouse);

    newUnit->getStrongerUnit(lv);

    listUnits.push_back(newUnit);
}



void Game ::addTurret(SDL_Renderer* renderer, Vector2D posMouse)
{
   Vector2D pos( (int)posMouse.x+0.5f,(int)posMouse.y+0.5f);
   listTurrets.push_back(Turret(renderer,pos));

}

void Game::removeUnitsAtMousePosition(Vector2D posMouse) {
    for (int count = 0; count < listUnits.size(); count++) {
        auto& unitSelected = listUnits[count];
        if (unitSelected->checkOverlap(posMouse, 0.0f)) {
            listUnits.erase(listUnits.begin() + count);
            count--;
        }
    }
}
void Game ::removeTurretsAtMousePosition(Vector2D posMouse)
{
    for(auto it =listTurrets.begin();it!=listTurrets.end();)
    {
        if((*it).checkOnTile((int )posMouse.x ,(int) posMouse.y ))
            it=listTurrets.erase(it);
        else it++;

    }

}
bool  Game:: isTurretAt(float x ,float y )
{
     for ( Turret& turret : listTurrets) {

            if (turret.checkOnTile((int) (x) ,(int) (y) )) {

                return true;
            }
        }

        return false;

}
