#ifndef enemy
#define enemy

#include"game.h"
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


#endif //enemy
