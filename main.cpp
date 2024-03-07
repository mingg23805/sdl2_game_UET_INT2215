#include<string>
#include<iostream>
#include <SDL.h>
#include <stdio.h>
#include<SDL_image.h>
#include "SDL_u.h"
#include "menu.h"
using namespace std;
SDL_Window* window;
SDL_Renderer *renderer;
int main( int argc, char* args[] )
{

   initSDL(window,renderer);
   Make_MenuGame(renderer);
   SDL_Delay(2000);
   //quitSDL(window,renderer);

   return 0;
}
