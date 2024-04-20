#pragma once
#include <iostream>
#include <SDL.h>
#include "Game.h"
//#include<SDL_mixer.h>
#include<SDL_ttf.h>
#include<TextureLoader.h>

class MenuGame {
public:
    MenuGame(SDL_Window* window, SDL_Renderer* renderer, int windowWidth, int windowHeight);
    void displayMenu();

private:
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;
    int m_windowWidth;
    int m_windowHeight;
};
