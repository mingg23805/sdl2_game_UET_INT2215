#ifndef MENU
#define MENU


#include<string>
#include<iostream>
#include <SDL.h>
#include<string.h>
#include<SDL_image.h>
#include"SDL_u.h"
using namespace std;
void renderButton(SDL_Texture* texture, int x, int y);
void MakeMenuGame(SDL_Renderer *renderer);
bool QuitMenu(SDL_Renderer *renderer,SDL_Event& e);
#endif MENU
