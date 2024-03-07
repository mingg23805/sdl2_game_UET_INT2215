#include "menu.h"

void renderButton(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) {
    SDL_Rect destinationRect = { x, y, 600, 300 };

    SDL_RenderCopy(renderer, texture, NULL, &destinationRect);
}
void Make_MenuGame( SDL_Renderer *renderer )
{   SDL_Texture* settingsButtonTexture = loadTexture("setting.jpg",renderer);
    SDL_Texture* startButtonTexture = loadTexture("start.jpg",renderer);
    SDL_Texture* quitButtonTexture = loadTexture("quit.jpg",renderer);
    SDL_Texture* background= loadTexture("menu_background.jpg",renderer);
    SDL_RenderCopy(renderer ,background, NULL, NULL);
    renderButton(renderer,settingsButtonTexture, 1920/2-300, 1080/2-300/2);
    renderButton(renderer,startButtonTexture, 1920/2-300, 1080/2-300-300/2 );
    renderButton( renderer,quitButtonTexture, 1920/2-300, 1080/2+300-300/2);
    SDL_RenderPresent(renderer);
}
/*void renderMenu() {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Render menu options
    // You can use SDL_Texture to render images for menu items

    // Present the renderer
    SDL_RenderPresent(renderer);
}
void menu_function()
{



}*/
