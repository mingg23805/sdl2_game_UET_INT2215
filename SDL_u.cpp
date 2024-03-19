
#include "SDL_u.h"
SDL_Window* window;
SDL_Renderer *renderer;
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const std:: string WINDOW_TITLE="TOWER DEFENSE";
void logSDLError( std:: ostream& os , const std::string &msg , bool fatal)
{
  os<<msg<<"Error :" <<SDL_GetError()<<std:: endl;
  if(fatal)
  {
      SDL_Quit();
      exit(1);

  }

};
void initSDL(SDL_Window* & window, SDL_Renderer* &renderer)
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
        logSDLError(std::cout,"SDL_INIT",true);
    window=SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT , SDL_WINDOW_SHOWN );
    if(window==nullptr)
        logSDLError(std::cout,"CreateWindow",true);
       renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC)   ;

     if(renderer==nullptr)
        logSDLError(std::cout,"RENDERER",true);
};
void quitSDL(SDL_Window* & window, SDL_Renderer* &renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
SDL_Texture* loadTexture( std ::  string path ,SDL_Renderer* renderer)
{
 SDL_Texture* newTexture = NULL;
 SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
 if ( loadedSurface == NULL )
std:: cout << "Unable to load image " << path << " SDL_image Error: "
 << IMG_GetError() << std::endl;
 else {
 newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
 if( newTexture == NULL )
 std::cout << "Unable to create texture from " << path << " SDL Error: "
 << SDL_GetError() <<std:: endl;
SDL_FreeSurface( loadedSurface );
 }

 return newTexture;
}

