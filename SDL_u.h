#ifndef SDL_U_H
#define SDL_U_H


#include<string>
#include<iostream>
#include <SDL.h>
#include<string.h>
#include<SDL_image.h>
using namespace std;
void logSDLError(ostream& os , const string &msg , bool fatal=false);
void initSDL(SDL_Window* & window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* & window, SDL_Renderer* &renderer);
SDL_Texture* loadTexture( string path ,SDL_Renderer* renderer);



#endif SDL_U_H
