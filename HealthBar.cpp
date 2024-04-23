#include "HealthBar.h"

HealthBar::HealthBar(SDL_Renderer* renderer,
                      int maxWidth, int height)
    : renderer(renderer), maxWidth(maxWidth), height(height) {


}

HealthBar::~HealthBar() {
}

void HealthBar::render() {
   SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
   SDL_RenderDrawRect(renderer, &outerRect);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &innerRect);
}

void HealthBar::setHP(int currentHP ,int x, int y) {
    currentHP = currentHP;
    outerRect = { x-1, y-1, maxWidth+2, height+2 };
    innerRect = { x, y,(int)((float)(currentHP) / maxHP * maxWidth) , height };

}
