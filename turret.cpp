#include"turret.h"
const float pi=3.14159;

Turret::Turret(SDL_Renderer* renderer ,Vector2D setPos) :
    pos(setPos), angle(0)
    {
       textureTurretOn= TextureLoader::loadTexture(renderer,"Turret On.bmp") ;
       textureTurretUnder=TextureLoader::loadTexture(renderer,"Turret Under.bmp");
       speedAngular=pi;
    }
void Turret::update(float dT)
{
    angle+=speedAngular*dT;
    if(angle>2*pi)
        angle=angle-2*pi;

}
void Turret::draw(SDL_Renderer* renderer,int tileSize)
{
   drawTurretPart(renderer,textureTurretOn,0,tileSize);
   drawTurretPart(renderer,textureTurretUnder,5,tileSize);

}
void Turret::drawTurretPart(SDL_Renderer* renderer,
                            SDL_Texture* selectedTexture,int offset,int tileSize)
{
      if(renderer!=nullptr && selectedTexture!=nullptr)
      {
          int w,h;
         SDL_QueryTexture(selectedTexture,NULL,NULL,&w,&h);
         SDL_Rect rect={
         pos.x*tileSize - w/2+offset,
         pos.y*tileSize - h/2+offset,
         w,
         h

         };
       SDL_RenderCopyEx(renderer,selectedTexture,NULL,&rect,
                        angle*180/pi,NULL,SDL_FLIP_NONE);
      }

}
