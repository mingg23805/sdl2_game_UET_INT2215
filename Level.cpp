#include "Level.h"



Level::Level(SDL_Renderer* renderer, int setTileCountX, int setTileCountY) :
    tileCountX(setTileCountX), tileCountY(setTileCountY),
    targetX(setTileCountX / 2), targetY(setTileCountY / 2) {
    textureTileWall = TextureLoader::loadTexture(renderer, "Tile Wall.bmp");
    textureTileTarget = TextureLoader::loadTexture(renderer, "Tile Target.bmp");
    textureTileSpawner=TextureLoader::loadTexture(renderer,"Tile Spawner.bmp");
    textureTileEmpty = TextureLoader::loadTexture(renderer, "Tile Empty.bmp");
    textureTileArrowUp = TextureLoader::loadTexture(renderer, "Tile Arrow Up.bmp");
    textureTileArrowUpRight = TextureLoader::loadTexture(renderer, "Tile Arrow Up Right.bmp");
    textureTileArrowRight = TextureLoader::loadTexture(renderer, "Tile Arrow Right.bmp");
    textureTileArrowDownRight = TextureLoader::loadTexture(renderer, "Tile Arrow Down Right.bmp");
    textureTileArrowDown = TextureLoader::loadTexture(renderer, "Tile Arrow Down.bmp");
    textureTileArrowDownLeft = TextureLoader::loadTexture(renderer, "Tile Arrow Down Left.bmp");
    textureTileArrowLeft = TextureLoader::loadTexture(renderer, "Tile Arrow Left.bmp");
    textureTileArrowUpLeft = TextureLoader::loadTexture(renderer, "Tile Arrow Up Left.bmp");

    size_t listTilesSize = (size_t)tileCountX * tileCountY;
    listTiles.assign(listTilesSize, Tile{});

    setTileType(tileCountX-1,0,Type::spawner);
    setTileType(0,0,Type::spawner);
    setTileType(0,tileCountY-1,Type::spawner);
    setTileType(tileCountX-1,tileCountY-1,Type::spawner);


    calculateFlowField();
}



void Level::draw(SDL_Renderer* renderer, int tileSize) {

   for (int y = 0; y < tileCountY; y++) {
        for (int x = 0; x < tileCountX; x++) {
            if ( (x+y) %2 == 0 )  SDL_SetRenderDrawColor(renderer,240,240,240,255);
            else  SDL_SetRenderDrawColor(renderer,225,225,225,255);

            SDL_Rect rect ={x* tileSize ,y*tileSize,tileSize,tileSize};
            SDL_RenderFillRect(renderer,&rect);
        }
    }



   for (int y = 0; y < tileCountY; y++) {
        for (int x = 0; x < tileCountX; x++) {
            if (getTileType(x,y)== Type::spawner) {
                SDL_Rect rect = { x * tileSize, y * tileSize, tileSize, tileSize };
                SDL_RenderCopy(renderer, textureTileSpawner, NULL, &rect);
            }

        }
    }

    if (textureTileTarget != nullptr) {
        SDL_Rect rect = { targetX * tileSize, targetY * tileSize, tileSize, tileSize };
        SDL_RenderCopy(renderer, textureTileTarget, NULL, &rect);
    }

    for (int y = 0; y < tileCountY; y++) {
        for (int x = 0; x < tileCountX; x++) {
            if (getTileType(x,y)==Type::wall) {
                SDL_Rect rect = { x * tileSize, y * tileSize, tileSize, tileSize };
                SDL_RenderCopy(renderer, textureTileWall, NULL, &rect);
            }

        }
    }
}



void Level::drawTile(SDL_Renderer* renderer, int x, int y, int tileSize) {
    SDL_Texture* textureSelected = textureTileEmpty;


    int index = x + y * tileCountX;
    if (index > -1 && index < listTiles.size() &&
        x > -1 && x < tileCountX &&
        y > -1 && y < tileCountY) {
        Tile& tileSelected = listTiles[index];


        if (tileSelected.flowDirectionX == 0 && tileSelected.flowDirectionY == -1)
            textureSelected = textureTileArrowUp;
        else if (tileSelected.flowDirectionX == 1 && tileSelected.flowDirectionY == -1)
            textureSelected = textureTileArrowUpRight;
        else if (tileSelected.flowDirectionX == 1 && tileSelected.flowDirectionY == 0)
            textureSelected = textureTileArrowRight;
        else if (tileSelected.flowDirectionX == 1 && tileSelected.flowDirectionY == 1)
            textureSelected = textureTileArrowDownRight;
        else if (tileSelected.flowDirectionX == 0 && tileSelected.flowDirectionY == 1)
            textureSelected = textureTileArrowDown;
        else if (tileSelected.flowDirectionX == -1 && tileSelected.flowDirectionY == 1)
            textureSelected = textureTileArrowDownLeft;
        else if (tileSelected.flowDirectionX == -1 && tileSelected.flowDirectionY == 0)
            textureSelected = textureTileArrowLeft;
        else if (tileSelected.flowDirectionX == -1 && tileSelected.flowDirectionY == -1)
            textureSelected = textureTileArrowUpLeft;

    }

    if (textureSelected != nullptr) {
        SDL_Rect rect = { x * tileSize, y * tileSize, tileSize, tileSize };
        SDL_RenderCopy(renderer, textureSelected, NULL, &rect);
    }
}


Vector2D Level ::getRanSpawnerLocation()
{
    std::vector<int>listSpawner;
    for(int i=0;i<listTiles.size();i++)
    {
        auto& tileSelected =listTiles[i];
        if(tileSelected.type==Type::spawner) listSpawner.push_back(i);
    }
    if(listSpawner.empty()==false)
    {
        int index= listSpawner[rand()%  listSpawner.size() ];
        return Vector2D( (float)(index% tileCountX) +0.5 ,(float)( index/tileCountX )+0.5 );
    }
    return Vector2D(0.5,0.5);
}
bool Level::isTileWall(int x, int y) {
  return getTileType(x,y)==Type::wall;
}


void Level::setTileWall(int x, int y, bool setWall) {
    if(getTileType(x,y)!=Type::spawner)
    {
        if(setWall==true)
            setTileType(x,y,Type::wall);
        else
            setTileType(x,y,Type::block);
    }

}

Level::Type Level::getTileType(int x ,int y)
{
   int index= x+y*tileCountX;
   if(index>-1 && index<listTiles.size()
      && x>-1 && x<tileCountX
      && y>-1 && y<tileCountY)
        return listTiles[index].type;


};
void Level::setTileType(int x,int y,Type TileType)
{
    int index= x+y*tileCountX;
   if(index>-1 && index<listTiles.size()
      && x>-1 && x<tileCountX
      && y>-1 && y<tileCountY)
        listTiles[index].type= TileType;
   calculateFlowField();

}
Vector2D Level::getTargetPos() {
    return Vector2D( (float)targetX+ 0.5f, (float)targetY + 0.5f);
}


void Level::calculateFlowField() {
    int indexTarget = targetX + targetY * tileCountX;
    if (indexTarget > -1 && indexTarget < listTiles.size() &&
        targetX > -1 && targetX < tileCountX &&
        targetY > -1 && targetY < tileCountY) {

        for (auto& tileSelected : listTiles) {
            tileSelected.flowDirectionX = 0;
            tileSelected.flowDirectionY = 0;
            tileSelected.flowDistance = flowDistanceMax;
        }


        calculateDistances();
        calculateFlowDirections();
    }
}


void Level::calculateDistances() {
    int indexTarget = targetX + targetY * tileCountX;

    std::queue<int> listIndicesToCheck;
    listTiles[indexTarget].flowDistance = 0;
    listIndicesToCheck.push(indexTarget);

    const int listNeighbors[][2] = { { -1, 0}, {1, 0}, {0, -1}, {0, 1} };

    while (listIndicesToCheck.empty() == false) {
        int indexCurrent = listIndicesToCheck.front();
        listIndicesToCheck.pop();

        for (int count = 0; count < 4; count++) {
            int neighborX = listNeighbors[count][0] + indexCurrent % tileCountX;
            int neighborY = listNeighbors[count][1] + indexCurrent / tileCountX;
            int indexNeighbor = neighborX + neighborY * tileCountX;

            if (indexNeighbor > -1 && indexNeighbor < listTiles.size() &&
                neighborX > -1 && neighborX < tileCountX &&
                neighborY > -1 && neighborY < tileCountY &&
                listTiles[indexNeighbor].type != Type::wall) {

                if (listTiles[indexNeighbor].flowDistance == flowDistanceMax) {

                    listTiles[indexNeighbor].flowDistance = listTiles[indexCurrent].flowDistance + 1;
                    listIndicesToCheck.push(indexNeighbor);
                }
            }
        }
    }
}


void Level::calculateFlowDirections() {
    const int listNeighbors[][2] = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
        {1, 0}, {1, -1}, {0, -1}, {-1, -1} };

    for (int indexCurrent = 0; indexCurrent < listTiles.size(); indexCurrent++) {
        if (listTiles[indexCurrent].flowDistance != flowDistanceMax) {

            unsigned char flowFieldBest = listTiles[indexCurrent].flowDistance;


            for (int count = 0; count < 8; count++) {
                int offsetX = listNeighbors[count][0];
                int offsetY = listNeighbors[count][1];

                int neighborX = offsetX + indexCurrent % tileCountX;
                int neighborY = offsetY + indexCurrent / tileCountX;
                int indexNeighbor = neighborX + neighborY * tileCountX;


                if (indexNeighbor > -1 && indexNeighbor < listTiles.size() &&
                    neighborX > -1 && neighborX < tileCountX &&
                    neighborY > -1 && neighborY < tileCountY) {
                    if (listTiles[indexNeighbor].flowDistance < flowFieldBest) {
                        flowFieldBest = listTiles[indexNeighbor].flowDistance;
                        listTiles[indexCurrent].flowDirectionX = offsetX;
                        listTiles[indexCurrent].flowDirectionY = offsetY;
                    }
                }
            }
        }
    }
}



Vector2D Level::getFlowNormal(int x, int y) {
    int index = x + y * tileCountX;
    if (index > -1 && index < listTiles.size() &&
        x > -1 && x < tileCountX &&
        y > -1 && y < tileCountY)
        return Vector2D((float)listTiles[index].flowDirectionX, (float)listTiles[index].flowDirectionY).normalize();

    return Vector2D();
}
