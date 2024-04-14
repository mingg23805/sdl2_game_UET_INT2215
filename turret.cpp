#include"turret.h"
const float pi=3.14159;
Turret::Turret(SDL_Renderer* renderer ,Vector2D setPos) :
    pos(setPos), angle(0),range(5.0)
    {
       textureTurretOn= TextureLoader::loadTexture(renderer,"Turret On.bmp") ;
       textureTurretUnder=TextureLoader::loadTexture(renderer,"Turret Under.bmp");
       speedAngular=pi;
    }
void Turret::update(float dT,std::vector<std::shared_ptr<Unit>>&listUnits )
{   if(auto unitTargetSP= unitTarget.lock())
    {  if(unitTargetSP->checkALive()==false
           or (unitTargetSP->getPos()-pos).magnitude()>range )
            unitTarget.reset();
    }
    if(unitTarget.expired())
    unitTarget=findEUnit(listUnits);
    if(auto unitTargetSP=unitTarget.lock())
    {
        Vector2D directionNormalTarget= (unitTargetSP->getPos()-pos).normalize();
        float angleToTarget= directionNormalTarget.angleBetween(Vector2D(angle));

        if(std:: abs(angleToTarget)!=0 )
        {
            float angleMove= -copysign(speedAngular*dT,angleToTarget);
            if(std::abs(angleMove)> std::abs(angleToTarget)) angle=directionNormalTarget.angle();
            else                                   angle+=angleMove;
        }

    }

}
void Turret::draw(SDL_Renderer* renderer,int tileSize)
{

     drawTurretPart(renderer,textureTurretUnder,tileSize);
     drawTurretPart(renderer,textureTurretOn,tileSize);


}
void Turret::drawTurretPart(SDL_Renderer* renderer,
                            SDL_Texture* selectedTexture,int tileSize)
{
      if(renderer!=nullptr && selectedTexture!=nullptr)
      {
		int w,h;
		SDL_QueryTexture(selectedTexture,NULL,NULL,&w,&h);

		SDL_Rect rect = {
			(int)(pos.x*tileSize)-w/2,
			(int)(pos.y*tileSize)-h/2,
			 w,
			 h };
		SDL_RenderCopyEx(renderer,selectedTexture,NULL,&rect,
                   angle*180/pi,NULL,SDL_FLIP_NONE);
	}

}
bool Turret::checkOnTile(int x,int y)
{

    return ( (int)(pos.x) == x&& (int) (pos.y) ==y );
}
std::weak_ptr<Unit> Turret::findEUnit(std::vector<std::shared_ptr<Unit>>& listUnits )
  {
      std::weak_ptr<Unit> closetUnit;
      float closetDistance=0;
      for(auto& selcetedUnit :listUnits )
      {

          if(selcetedUnit!=nullptr)
        {
            float currentDistance=( pos-selcetedUnit->getPos( )).magnitude();
            if(currentDistance<range &&
               (closetUnit.expired() or currentDistance< closetDistance))
            {
                closetUnit=selcetedUnit;
                closetDistance=currentDistance;
            }
          }
      }
      return closetUnit;
  }
