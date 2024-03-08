
#include "SDL_u.h"
const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;
const string WINDOW_TITLE="TOWER DEFENSE";
void logSDLError(ostream& os , const string &msg , bool fatal)
{
  os<<msg<<"Error :" <<SDL_GetError()<<endl;
  if(fatal)
  {
      SDL_Quit();
      exit(1);

  }

};
void initSDL(SDL_Window* & window, SDL_Renderer* &renderer)
{
    if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
        logSDLError(cout,"SDL_INIT",true);
    window=SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED,
                SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,SCREEN_HEIGHT , SDL_WINDOW_SHOWN );
    if(window==nullptr)
        logSDLError(cout,"CreateWindow",true);
       renderer= SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED |
                                              SDL_RENDERER_PRESENTVSYNC)   ;

     if(renderer==nullptr)
        logSDLError(cout,"RENDERER",true);
};
void quitSDL(SDL_Window* & window, SDL_Renderer* &renderer)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
SDL_Texture* loadTexture( string path ,SDL_Renderer* renderer)
{
 SDL_Texture* newTexture = NULL;
 SDL_Surface* loadedSurface = IMG_Load( path.c_str() );
 if ( loadedSurface == NULL )
 cout << "Unable to load image " << path << " SDL_image Error: "
 << IMG_GetError() << endl;
 else {
 newTexture = SDL_CreateTextureFromSurface( renderer, loadedSurface );
 if( newTexture == NULL )
 cout << "Unable to create texture from " << path << " SDL Error: "
 << SDL_GetError() << endl;
SDL_FreeSurface( loadedSurface );
 }

 return newTexture;
}


