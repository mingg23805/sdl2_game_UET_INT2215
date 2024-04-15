#pragma once
#include<SDL.h>
#include<memory>
#include"TextureLoader.h"
#include"Vector2D.h"
#include"projectile.h"
#include"Unit.h"
#include"timer.h"
#include<bits/stdc++.h>

class Turret
{ private:
    Vector2D pos;
    float angle;
    Timer timeDelay;

    SDL_Texture *textureTurretOn=nullptr,
                *textureTurretUnder=nullptr;
    std::weak_ptr<Unit> unitTarget;

      bool updateAngle(float dT);
      void shootProjectile(SDL_Renderer* renderer,std::vector<Projectile>& listProjectiles);

    public:
    Turret(SDL_Renderer *renderer ,Vector2D setPos);
    void update(float dT,std::vector<std::shared_ptr<Unit>>&listUnits
                    ,SDL_Renderer* renderer,std::vector<Projectile>& listProjectiles);
     float speedAngular ;//omega
     float range;


    std::weak_ptr<Unit> findEUnit(std::vector<std::shared_ptr<Unit>>& listUnits );

    void draw(SDL_Renderer* renderer,int tileSize);
    void drawTurretPart(SDL_Renderer* renderer,SDL_Texture* selectedTexture,
                        int tileSize);
    bool checkOnTile(int x,int y);
    	static const float size;

};
