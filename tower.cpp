#include"tower.h"
Tower::Tower() : x_pos(0), y_pos(0), width(120), height(240), lv(1),upgradeBaseCost(150){}
void Tower::TowerParameter(int type,SDL_Renderer * renderer)
{
    switch(type)
    {
    default:
    case archer :
        {
            texture= loadTexture("picture/tower/archer_tower.png");
            range=400;
            damage=20;
            firerate=1.5 ;
            cost=150;
            rangeToAdd=150;
            damageToAdd=20;

        }
    case rock :

        {
            texture= loadTexture("picture/tower/archer_tower.png");
            range=250;
            damage=40;
            firerate=1 ;
            cost=175;
            rangeToAdd=100;
            damageToAdd=25;
             }
    }


}

