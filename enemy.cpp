#include "enemy.h"
Enemy::Enemy() : numFrames(0), CurrentFrame(0), texture(nullptr),currentPathIndex(1),x_pos(0) ,y_pos(660.0){}

Enemy::~Enemy() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}
void Enemy::MakeParameter()
{
     width =  380;
    height = 296;
    for (int i=0;i<20;i++) {

        frame_clip[i].x = i * width;
        frame_clip[i].y = 0;
        frame_clip[i].w = width;
        frame_clip[i].h = height;
    }

    numFrames = 20;
}

void Enemy::loadImg(int SerialNum, SDL_Renderer* renderer, const std::string& action ) {
    std:: string num="";
    num+=char(SerialNum+48);
     std:: string path="picture/enemy/"+ num+"_"+action+".png";
      texture=loadTexture(path,renderer);


}

void Enemy::show(SDL_Renderer* renderer,float x_pos,float y_pos) {
    SDL_Rect destRect = {(int)( x_pos),(int) (y_pos), 120, 120 }; // Vị trí và kích thước của animation
    SDL_RenderCopy(renderer, texture, &frame_clip[CurrentFrame], &destRect);
   SDL_DestroyTexture(texture);
}

void Enemy::RunAction(SDL_Renderer* renderer, std::vector<std::pair<int, int>> EnemyPath) {
    std:: string action="run";
    loadImg(SerialNum,renderer,action);

 float distancePerFrame = 120.0/(float) FPS; //4 don vi khung hinh/s

    float targetX = EnemyPath[currentPathIndex].first;
    float targetY = EnemyPath[currentPathIndex].second;
    if ( x_pos <targetX or y_pos > targetY )
    {   if( x_pos<targetX) x_pos=x_pos+distancePerFrame;
        if(y_pos>targetY) y_pos=y_pos-distancePerFrame;

    }
    else
    {currentPathIndex = (currentPathIndex +1) % EnemyPath.size() ;}
     show(renderer, x_pos, y_pos);
    CurrentFrame = (CurrentFrame + 1) % numFrames;

     SDL_Delay(1000/FPS);

}
/*void Enemy::DeadAction(SDL_Renderer* renderer)
{

    std::string action="dead";
    loadImg(SerialNum,renderer,action);
    show(renderer, x_pos, y_pos);
    DeadCurrentFrame = DeadCurrentFrame + 1;

     SDL_Delay(1000/FPS);


}
void Enemy :: EnemyAction( SDL_Renderer* renderer )
{
  if(currentPathIndex<=EnemyPath.size())
    RunAction(renderer,EnemyPath);
    else
    {
        AttackAction(renderer);
    }


}*/
