#pragma once

#include<SDL.h>
#include"Vector2D.h"
#include<bits/stdc++.h>
#include<memory>
#include"TextureLoader.h"


class Projectile
{ public:
    Projectile(SDL_Renderer* renderer,Vector2D setPos, Vector2D setDirectionNormal);
    void update(float dT);
    void draw(SDL_Renderer* renderer,int tileSize);
private:
    Vector2D pos, directionNormal;
     static const float speed,size;
     SDL_Texture * texture=nullptr;
};
