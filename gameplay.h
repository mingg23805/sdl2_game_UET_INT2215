#ifndef gameplay
#define gameplay
#include<bits/stdc++.h>
#include"SDL_u.h"
#include<SDL.h>
#include<SDL_image.h>
extern std:: vector <std:: pair<int ,int >>MapBlock;
extern std:: vector <std:: pair<int ,int >>TowerLocation;
void renderPicture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) ;
void MakeDemoMap( );
void renderDemoMap(SDL_Renderer* renderer);

#endif gameplay
