#include "menu.h"

void renderButton(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) {
    SDL_Rect destinationRect = { x, y, 800, 300 };
    SDL_RenderCopy(renderer, texture, NULL, &destinationRect);
    SDL_DestroyTexture(texture);
    }
void MakeMenuGame( SDL_Renderer *renderer )
{
    SDL_Texture* settingsButtonTexture = loadTexture("picture/menugame/setting.png",renderer);
    SDL_Texture* startButtonTexture = loadTexture("picture/menugame/start.png",renderer);
    SDL_Texture* quitButtonTexture = loadTexture("picture/menugame/quit.png",renderer);
    SDL_Texture* background= loadTexture("picture/menugame/menu.png",renderer);
    SDL_RenderCopy(renderer ,background, NULL, NULL);
    renderButton(renderer,settingsButtonTexture, 1920/2-400, 1080/2 +50);
    renderButton(renderer,startButtonTexture, 1920/2-400, 1080/2+ 50 - 200);
    renderButton( renderer,quitButtonTexture, 1920/2-400, 1080/2+ 50 + 200);
    SDL_DestroyTexture(background);
}
bool QuitMenu(SDL_Renderer* renderer ,SDL_Event& e)
{
    int mouseX = e.button.x;
    int mouseY = e.button.y;

    if (mouseX >= 1920 / 2 - 400 && mouseX <= 1920 / 2 - 400 + 800 &&
        mouseY >= 1080 / 2 + 200 +50 && mouseY <= 1080 / 2 + 200 + 300 + 50) {
        return true;

    }

else return false;
}
/*void MakeChooseMap
{


}*/
bool ChooseMap(SDL_Renderer* renderer ,SDL_Event& e)
{
    int mouseX = e.button.x;
    int mouseY = e.button.y;
    if (mouseX >= 1920 / 2 - 400 && mouseX <= 1920 / 2 - 400 + 800 &&
        mouseY >= 1080 / 2 - 200 +50  && mouseY <= 1080 / 2 - 200  + 300 + 50 ) {
        return true;

    }

else return false;
}
