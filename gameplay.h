#ifndef gameplay
#define gameplay

#include"SDL_u.h"
class Enemy {
public:
    Enemy();
    ~Enemy();
    SDL_Texture* texture;
    int SerialNum;
    float hp;
    void MakeParameter();
    void loadImg(int SerialNum, SDL_Renderer* renderer,const std:: string& action);
    void show(SDL_Renderer* renderer,float x_pos,float y_pos);
    void RunAction(SDL_Renderer* renderer,std::vector<std::pair<int, int>> EnemyPath);
    void AttackAction(SDL_Renderer* renderer);
    void DeadAction(SDL_Renderer* renderer);
    void EnemyAction(SDL_Renderer* renderer);

private:
    int x_pos;
    int y_pos;
    int width;
    int height;
    SDL_Rect frame_clip[20];
    int numFrames;
    int CurrentFrame;
    int currentPathIndex;
};



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
#endif //gameplay
