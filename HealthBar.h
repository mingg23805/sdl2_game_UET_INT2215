#pragma once

#include <SDL.h>

class HealthBar {
public:
    HealthBar(SDL_Renderer* renderer, int maxWidth, int height);
    ~HealthBar();

    void render();

    void setHP(int currentHP, int x, int y);
    int currentHP;
    int maxHP;

private:
    SDL_Renderer* renderer;
    int maxWidth;
    int height;


    SDL_Rect outerRect;
    SDL_Rect innerRect;
};
