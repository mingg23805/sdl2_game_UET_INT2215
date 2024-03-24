#ifndef game
#define game

#include"SDL_u.h"



class player
{   int Main_hp;
     double x;double y;
    int money;

};
class Map
{ public:
    SDL_Texture* texture;
    int lv;

};
extern std:: vector <std:: pair<int ,int >>EnemyPath;
extern std:: vector <std:: pair<int ,int >>TowerLocation;
void renderPicture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) ;
void makePathandLocation();
void renderDemoMap(SDL_Renderer* renderer);


#endif //game
