#pragma once
#include<SDL.h>
#include<memory>
#include"TextureLoader.h"
#include"Vector2D.h"
#include<bits/stdc++.h>
#include"Unit.h"

class Turret
{ private:
    Vector2D pos;
    float angle;

    SDL_Texture *textureTurretOn=nullptr,
                *textureTurretUnder=nullptr;
    public:
    Turret(SDL_Renderer *renderer ,Vector2D setPos);
    void update(float dT);
     float speedAngular ;//omega
     float range;

    std::weak_ptr<Unit> findEUnit(std::vector<std::shared_ptr<Unit>>& listUnits );

    void draw(SDL_Renderer* renderer,int tileSize);
    void drawTurretPart(SDL_Renderer* renderer,SDL_Texture* selectedTexture,
                        int tileSize);
    bool checkOnTile(int x,int y);
    	static const float size;

};
