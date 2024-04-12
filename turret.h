#pragma once
#include<SDL.h>
#include"TextureLoader.h"
#include"Vector2D.h"
#include<bits/stdc++.h>

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
    void draw(SDL_Renderer* renderer,int tileSize);
    void drawTurretPart(SDL_Renderer* renderer,SDL_Texture* selectedTexture,
                        int tileSize);
    bool checkOnTile(int x,int y);
    	static const float size;

};
