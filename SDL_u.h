#ifndef SDL_U_H
#define SDL_U_H


#include<bits/stdc++.h>
#include <SDL.h>
#include<SDL_image.h>
extern SDL_Window* window;
extern SDL_Renderer *renderer;
const int FPS = 60;
void logSDLError(std:: ostream& os ,const std :: string &msg , bool fatal=false);
void initSDL(SDL_Window* & window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* & window, SDL_Renderer* &renderer);
SDL_Texture* loadTexture(std :: string path ,SDL_Renderer* renderer);

void renderPicture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) ;
void MakeDemoMap( );
void renderDemoMap(SDL_Renderer* renderer);
#endif //SDL_U_H
