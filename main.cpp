#include<bits/stdc++.h>
#include<SDL_image.h>
#include "SDL_u.h"
#include "menu.h"
#include"gameplay.h"

using namespace std;

bool quit = false;

SDL_Window* window;
SDL_Renderer *renderer;
int main( int argc, char* args[] )
{

   initSDL(window,renderer);
   SDL_Event e;

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
    }
       // MakeMenuGame(renderer);
   quitSDL(window,renderer);
    return 0;
}
