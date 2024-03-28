#include<SDL_image.h>
#include<bits/stdc++.h>
#include "SDL_u.h"
#include "menu.h"
#include"enemy.h"
#include"game.h"
using namespace std;
bool quit = false;
Enemy enm;
Tower t;
int choosetower=0;
int main( int argc, char* args[] )
{    enm.SerialNum=1;
     enm.MakeParameter();
     t.TowerParameter(1,renderer);
     t.TowerParameter(2,renderer);



    initSDL(window,renderer);
   SDL_Event e;
   makePathandLocation();

    while (!quit)
        {
        renderDemoMap(renderer);
        enm.RunAction(renderer,EnemyPath);
     while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;}
                 if (e.type == SDL_MOUSEBUTTONDOWN) {
                if (e.button.button == SDL_BUTTON_LEFT)
                chooseTower(e,choosetower,renderer);}

        }
        SDL_RenderPresent(renderer);

    }
   quitSDL(window,renderer);
    return 0;
}
