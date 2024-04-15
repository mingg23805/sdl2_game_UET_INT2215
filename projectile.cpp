#include"projectile.h"
const float Projectile::speed=10,Projectile::size=0.2,
            Projectile::distanceTravelMax=5;//= turretRange

Projectile::Projectile(SDL_Renderer* renderer,Vector2D setPos, Vector2D setDirectionNormal) :
    pos(setPos) ,directionNormal(setDirectionNormal)
{
    texture=TextureLoader::loadTexture(renderer,"Projectile.bmp");
}

void Projectile:: update(float dT,std::vector<std::shared_ptr<Unit>>& listUnits)
{         float distanceMove=speed*dT;
         pos+=directionNormal*distanceMove;
         distanceTraveled+=distanceMove;

         if(distanceTraveled>=distanceTravelMax)
         {
             collision=true;
         }
         checkCollision(listUnits);
}
bool Projectile::getCollison()
{

    return collision;
}
void Projectile::checkCollision(std::vector<std::shared_ptr<Unit>>& listUnits)
{

}
void Projectile::draw(SDL_Renderer*renderer ,int tileSize)
{
    if(renderer!=nullptr)
    {
        int w,h;
        SDL_QueryTexture(texture,NULL,NULL,&w,&h);
        SDL_Rect rect={
            (int)(pos.x*tileSize)-w/2,
            (int)(pos.y*tileSize)-h/2,
            w,
            h
        };
        SDL_RenderCopy(renderer,texture,NULL,&rect);
    }
}
