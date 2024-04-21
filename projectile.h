#pragma once

#include<SDL.h>
#include"Vector2D.h"
#include<bits/stdc++.h>
#include<memory>
#include"TextureLoader.h"
#include"Unit.h"


class Projectile
{ public:
    Projectile(SDL_Renderer* renderer,Vector2D setPos, Vector2D setDirectionNormal);
    void update(float dT,std::vector<std::shared_ptr<Unit>>& listUnits);
    void draw(SDL_Renderer* renderer,int tileSize);
    bool getCollison();
private:
    void checkCollision(std::vector<std::shared_ptr<Unit>>& listUnits);

    int getCriticalDMG(int critRate);
    Vector2D pos, directionNormal;
     static const float speed,size,distanceTravelMax;
     float distanceTraveled=0;
     SDL_Texture * texture=nullptr;
     bool collision=false;
};
