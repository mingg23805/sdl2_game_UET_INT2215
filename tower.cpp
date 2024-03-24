#include"tower.h"
Tower::Tower() : x_pos(0), y_pos(0), width(120), height(240), lv(1),upgradeBaseCost(150){}
void Tower::TowerParameter(int type,SDL_Renderer * renderer)
{
    switch(type)
    {
    default:
    case archer :
        {  bullet= loadTexture("picture/tower/arrow.png",renderer);
            texture= loadTexture("picture/tower/archer_tower.png",renderer);
            range=400;
            damage=20;
            fireRate=2 ;
            cost=150;
            rangeToAdd=150;
            damageToAdd=20;

        }
    case rock :

        {   bullet= loadTexture("picture/tower/rock.png",renderer);
            texture= loadTexture("picture/tower/rock_tower.png",renderer);
            range=250;
            damage=40;
            fireRate=1.25 ;
            cost=175;
            rangeToAdd=100;
            damageToAdd=25;
             }
    }
}

