#include "Game.h"



Game::Game(SDL_Window* window, SDL_Renderer* renderer, int windowWidth, int windowHeight) :
    placementModeCurrent(PlacementMode::wall),
    level(renderer, windowWidth / tileSize, windowHeight / tileSize) ,
    mainHpBar(renderer,tileSize*9,tileSize/2),
    spawnT(0.25f),roundT(5.0f)
    {

    if (window != nullptr && renderer != nullptr) {


          std::ifstream readFile("highestPoint.txt");
          mainHpBar.maxHP=mainTowerHp;

        mix_chunkSpawnUnit= SoundLoader::loadSound("Data/Sounds/spawn.ogg");
        gameOFont = FontLoader::loadFont("Warriatron3DStraight-OGGvp.otf",200);
         gameFont=FontLoader::loadFont("arial.ttf",65);

         readFile >> highestPoint;



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
                if (isGameOver()==false) {
                    update(dT,renderer);

                }


                draw(renderer);

            }
        }
        std::ofstream writeFile("highestPoint.txt", std::ios::out | std::ios::trunc);
       if (writeFile.is_open()) {
        writeFile << highestPoint;
        writeFile.close();}
    }
}


Game::~Game() {
    TextureLoader::deallocateTextures();
   SoundLoader::deallocateSounds();
  FontLoader::deallocateFonts();
}

bool Game::isGameOver()
{
    return mainTowerHp==0;
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

    if (mouseDownStatus > 0 &&isGameOver()==false) {
        switch (mouseDownStatus) {
        case SDL_BUTTON_LEFT:
            switch (placementModeCurrent) {
            case PlacementMode::wall:
                if(mouseDownThisFrame&& maxBlockcanBuild>0 &&
                   level.isTileWall((int)posMouse.x, (int)posMouse.y )==false
                   &&level.isMainTower( (int)posMouse.x, (int)posMouse.y )==false
                    )
                   {
                       level.setTileWall((int)posMouse.x, (int)posMouse.y, true);

                        maxBlockcanBuild--;}
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
       highestPoint=std::max(highestPoint,point);

      updateSpawnUnits(renderer,dT);


}
void Game::updateSpawnUnits(SDL_Renderer *renderer,float dT)
{
   spawnT.countDown(dT);
   if(listUnits.empty() && unitCount==0)
   {   roundT.countDown(dT);
       if(roundT.timeSIsZero()==true)
     {  lv++;
       unitCount=15;
       maxBlockcanBuild+=2;
       roundT.resetToMax();


     }
   }
   if(unitCount>0 && spawnT.timeSIsZero())
   {
       addUnit(renderer,level.getRanSpawnerLocation());
       unitCount--;

        if ( mix_chunkSpawnUnit != nullptr)
           Mix_PlayChannel(-1, mix_chunkSpawnUnit, 0);

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
            else point++;
           it=listUnits.erase(it);
           increase=false;
          }
          if(mainTowerHp<=0) {mainTowerHp=0;break;}
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
      SDL_RenderClear(renderer);

SDL_SetRenderDrawColor(renderer,255, 255, 255, 255);


        SDL_Rect Menurect = { 0, 720, 1200, 180 };
         SDL_RenderFillRect(renderer, &Menurect);

          level.draw(renderer, tileSize);



        std::string lvlText = "Level: " + std::to_string(lv);
        lvlSurface=   TTF_RenderText_Solid(gameFont,
                                           lvlText.c_str(), {0, 0, 0});
        lvlTexture=SDL_CreateTextureFromSurface(renderer,lvlSurface);
        SDL_Rect lvlRect={50,720+50,300,80};
        SDL_FreeSurface(lvlSurface);
        SDL_RenderCopy(renderer, lvlTexture,nullptr, &lvlRect );

        std::string pointText = "Score: " + std::to_string(point);
        pointSurface=   TTF_RenderText_Solid(gameFont,
                                             pointText.c_str(), {0, 0, 0});
        pointTexture=SDL_CreateTextureFromSurface(renderer,pointSurface);
        pointRect={400,720+50,300,80 } ;
        SDL_FreeSurface(pointSurface);
        SDL_RenderCopy(renderer, pointTexture,nullptr, &pointRect);


         std::string hpointText = "Highest : " + std::to_string(highestPoint);
        highestPointSurface=   TTF_RenderText_Solid(gameFont,
                                                hpointText.c_str(), {0, 0, 0});
        highestPointTexture=SDL_CreateTextureFromSurface(renderer,highestPointSurface);
        highestPointRect={750,720+50,300,80 } ;
        SDL_FreeSurface(highestPointSurface);
        SDL_RenderCopy(renderer, highestPointTexture,nullptr, &highestPointRect);

       mainHpBar.setHP(mainTowerHp,
                       (int)((25-9)/2)*tileSize,
                       0);
         mainHpBar.render();

    for (auto& unitSelected : listUnits)
        if(unitSelected != nullptr)unitSelected->draw(renderer, tileSize);

    for (auto& selectedTurret : listTurrets)
        selectedTurret.draw(renderer, tileSize);

    for(auto&selectedProjectile : listProjectiles)
        selectedProjectile.draw(renderer,tileSize);


          if(isGameOver()==true)
  {


        gameOverSurface = TTF_RenderText_Solid(gameOFont,
        "Game Over", {255, 0, 0});
           gameOverTexture = SDL_CreateTextureFromSurface(renderer, gameOverSurface);
         int GOtextWidth, GOtextHeight;
        SDL_QueryTexture(gameOverTexture,
                          nullptr, nullptr, &GOtextWidth, &GOtextHeight);
        gameOverRect = { (1200 - GOtextWidth) / 2,
                         (720 - GOtextHeight) / 2,
                          GOtextWidth,
                          GOtextHeight };

            SDL_FreeSurface(gameOverSurface);
        SDL_RenderCopy(renderer, gameOverTexture,nullptr, &gameOverRect);
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
