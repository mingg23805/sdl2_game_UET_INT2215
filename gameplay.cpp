#include "gameplay.h"
enum elemental
{   fire ,
    water,
    ice,
    lightning,
};
class Enemy

{
    SDL_Texture* texture;
    double x;
    double y;
    double hp;
    double dmg;
    int speed;
    elemental elm;
};


class tower
{   SDL_Texture* texture;
    double x; double y;
    double range;
    double ad;
    elemental elm;
    double speed;
    int cost;
   class bullet
   { double x;
    double y;
    SDL_Texture *texture;
   };

} ;
class player
{   int Main_hp;
     double x;double y;
    int money;
};
class Map
{ public:
    SDL_Texture* texture;



}demomap;
void renderDemoMap(SDL_Renderer* renderer)
{
    demomap.texture= loadTexture("map.png", renderer);
    SDL_Rect rect = {1360, 20, 120, 120};

    SDL_RenderCopy(renderer ,demomap.texture, NULL, NULL);
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Đặt màu vẽ là trắng
    SDL_RenderDrawRect(renderer, &rect);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(demomap.texture);
}
std:: vector <std:: pair<int ,int >>MapBlock;
std:: vector <std:: pair<int ,int >>TowerLocation;
void MakeDemoMap( )
{  for(int i=0;i<=1320/120;i++)
   MapBlock.push_back(std::make_pair( 120*i , 600+60 )) ;

   MapBlock.push_back(std::make_pair(  480, 120*4+60 ) );
   MapBlock.push_back(std::make_pair( 480 , 120*3+60 ) );
   MapBlock.push_back(std::make_pair( 600 +60 , 120*3+60 ) );
   MapBlock.push_back(std::make_pair( 600+60 , 120*2+60 ) );
   MapBlock.push_back(std::make_pair( 600+60 , 120+60 ) );
   for(int i=6;i<16;i++)
   MapBlock.push_back(std::make_pair( 120*i+60, 120*2+60 ) );
   TowerLocation.push_back(std::make_pair( 300 , 500 )) ;
 TowerLocation.push_back(std::make_pair( 300 , 820 )) ;
 TowerLocation.push_back(std::make_pair( 820 , 360 )) ;
 TowerLocation.push_back(std::make_pair( 500 , 250 )) ;
 TowerLocation.push_back(std::make_pair( 1200 , 340 )) ;
 TowerLocation.push_back(std::make_pair( 1520 , 340 )) ;
 TowerLocation.push_back(std::make_pair( 1360 , 20 )) ;


}

