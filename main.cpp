#include <iostream>
#include <SDL.h>
#include "Game.h"
#include<SDL_mixer.h>
#include<SDL_ttf.h>


int main(int argc, char* args[]) {

	srand(time(NULL));

	if (SDL_Init(SDL_INIT_VIDEO  ) < 0 ) {
		std::cerr << "Error: Couldn't initialize SDL = " << SDL_GetError() << std::endl;
		return 1;
	}
	else {

        if (  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2,2048) < 0) {
        std::cerr << "SDL_Mixer could not initialize! SDL_Mixer Error: " << Mix_GetError() << std::endl;
       SDL_Quit();
       return -1;
    }
          if (TTF_Init() == -1) {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

		SDL_Window* window = SDL_CreateWindow("Tower Base Defense",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,1200, 900, 0);
		//	Mix_Music* music = Mix_LoadMUS("Data/Sounds/music.mp3");

		if (window == nullptr) {
			std::cout << "Error: Couldn't create window = " << SDL_GetError() << std::endl;
			return 1;
		}
		else {

			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
				SDL_RENDERER_PRESENTVSYNC);

			if (renderer == nullptr) {
				std::cout << "Error: Couldn't create renderer = " << SDL_GetError() << std::endl;
				return 1;
			}
			else {

				SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);



                 int playWindowWidth = 1200

                 , playWindowHeight = 720;


//                 Mix_PlayMusic(music, -1) ;
				Game game(window, renderer, playWindowWidth, playWindowHeight);


				SDL_DestroyRenderer(renderer);
			}


			SDL_DestroyWindow(window);

		}

        //Mix_FreeMusic(music);
       Mix_CloseAudio();
		TTF_Quit();
		SDL_Quit();
	}
	return 0;
}
