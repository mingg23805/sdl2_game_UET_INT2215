#include<SDL_image.h>
#include<bits/stdc++.h>
#include "SDL_u.h"
#include "menu.h"
#include"gameplay.h"
using namespace std;
bool quit = false;

Enemy enm;

int main( int argc, char* args[] )
{    enm.SerialNum=1;
enm.MakeParameter();
    initSDL(window,renderer);
   SDL_Event e;
   makePathandLocation();

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            } else if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT) {
                    quit=QuitMenu(renderer,e);
                }
            }
        }

        renderDemoMap(renderer);
        enm.RunAction(renderer,EnemyPath);

        SDL_RenderPresent(renderer);

    }
   quitSDL(window,renderer);
    return 0;
}
