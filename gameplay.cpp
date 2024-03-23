#include "gameplay.h"

Map demomap;
std:: vector <std:: pair<int ,int >>EnemyPath;
std:: vector <std:: pair<int ,int >>TowerLocation;
 void makePathandLocation()
 {
      for(int i=0;i<=480/120;i++)
   EnemyPath.push_back(std::make_pair( 120*i , 600+60 )) ;

   EnemyPath.push_back(std::make_pair(  480, 120*4+60 ) );
   EnemyPath.push_back(std::make_pair( 480 , 120*3+30 ) );
   EnemyPath.push_back(std::make_pair( 600 +90 , 120*3+30 ) );
   EnemyPath.push_back(std::make_pair( 600+90 , 120*2+60 ) );
   EnemyPath.push_back(std::make_pair( 600+90 , 120+30 ) );

   for(int i=6;i<=1700/120;i++)
 EnemyPath.push_back(std::make_pair( 120*i+60, 120+30 ) );


 TowerLocation.push_back(std::make_pair( 300 , 500 )) ;
 TowerLocation.push_back(std::make_pair( 300 , 820 )) ;
 TowerLocation.push_back(std::make_pair( 820 , 360 )) ;
 TowerLocation.push_back(std::make_pair( 500 , 250 )) ;
 TowerLocation.push_back(std::make_pair( 1200 , 340 )) ;
 TowerLocation.push_back(std::make_pair( 1520 , 340 )) ;
 TowerLocation.push_back(std::make_pair( 1360 , 20 )) ;

 }
 void renderDemoMap(SDL_Renderer* renderer)
{  //map
    demomap.texture= loadTexture("picture/map/map.png", renderer);
    SDL_RenderCopy(renderer ,demomap.texture, NULL, NULL);

    //castle
    SDL_Texture * MainTowerTexture= loadTexture("picture/map/castle.png ",renderer);
    SDL_Rect destinationRect = { 1720, 20, 300, 280 };
    SDL_RenderCopy(renderer, MainTowerTexture, NULL, &destinationRect);

 SDL_DestroyTexture(MainTowerTexture);
    SDL_DestroyTexture(demomap.texture);
    // tower Location

   for(auto x : TowerLocation)
   {
       SDL_Rect rect = {x.first,x.second , 120, 120};
       SDL_Texture * slot = loadTexture("picture/map/slot.png", renderer);
       SDL_RenderCopy(renderer,slot,NULL, &rect);
       SDL_DestroyTexture(slot);
   }





    //button ui hpbar
    SDL_Texture * TowerButton= loadTexture("picture/map/towerbutton.png",renderer);
    SDL_Texture * Archer = loadTexture("picture/tower/archer_tower_button.png",renderer);
    SDL_Texture * Rock = loadTexture("picture/tower/rock_tower_button.png",renderer);

    SDL_Rect ArcherRect= {1920-240,1080-180,240,180};
    SDL_Rect RockRect = { 1920-240*2,1080-180,240,180};



    SDL_RenderCopy(renderer,TowerButton,NULL,&ArcherRect);
    SDL_RenderCopy(renderer,Archer,NULL,&ArcherRect);

    SDL_RenderCopy(renderer,TowerButton,NULL,&RockRect);
    SDL_RenderCopy(renderer,Rock,NULL,&RockRect);


    SDL_DestroyTexture(TowerButton);
    SDL_DestroyTexture(Archer);
    SDL_DestroyTexture(Rock);

    SDL_Texture * Status = loadTexture("picture/map/Status.png",renderer);

    SDL_Rect StatusRect={0,0,360,480};
    SDL_RenderCopy(renderer,Status,NULL,&StatusRect);
    SDL_DestroyTexture(Status);



 }
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
