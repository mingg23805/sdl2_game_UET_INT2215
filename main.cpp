#include<SDL_image.h>
#include<bits/stdc++.h>
#include "SDL_u.h"
#include "menu.h"
#include"gameplay.h"
using namespace std;
bool quit = false;
vector<Enemy> enemy;
void makeVectorEnemy(vector<Enemy>enemy)
{
   for(int i=1;i<=5;i++)
   {  Enemy enm;
     enm.SerialNum=i;
     enm.MakeParameter();
     enm.hp=50;
       enemy.push_back(enm);
   }
    //1 2 3 normalEnemy 4 5 strongEnemy
}
int main( int argc, char* args[] )
{

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
        enemy[1].loadImg(1,renderer,"run");
        enemy[1].show(renderer,0,660,enemy[1].RunCurrentFrame);
       // enemy[1].EnemyAction(renderer);
        SDL_RenderPresent(renderer);

    }
   quitSDL(window,renderer);
    return 0;
}
