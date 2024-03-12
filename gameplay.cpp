#include "gameplay.h"
class Map
{ public:
    SDL_Texture* texture;



}demomap;
std:: vector <std:: pair<int ,int >>EnemyPath;
std:: vector <std:: pair<int ,int >>TowerLocation;
void MakeDemoMap( ){
    for(int i=0;i<=1320/120;i++)
   EnemyPath.push_back(std::make_pair( 120*i , 600+60 )) ;

   EnemyPath.push_back(std::make_pair(  480, 120*4+60 ) );
   EnemyPath.push_back(std::make_pair( 480 , 120*3+60 ) );
   EnemyPath.push_back(std::make_pair( 600 +60 , 120*3+60 ) );
   EnemyPath.push_back(std::make_pair( 600+60 , 120*2+60 ) );
   EnemyPath.push_back(std::make_pair( 600+60 , 120+60 ) );

   for(int i=6;i<16;i++)
    EnemyPath.push_back(std::make_pair( 120*i+60, 120+60 ) );


 TowerLocation.push_back(std::make_pair( 300 , 500 )) ;
 TowerLocation.push_back(std::make_pair( 300 , 820 )) ;
 TowerLocation.push_back(std::make_pair( 820 , 360 )) ;
 TowerLocation.push_back(std::make_pair( 500 , 250 )) ;
 TowerLocation.push_back(std::make_pair( 1200 , 340 )) ;
 TowerLocation.push_back(std::make_pair( 1520 , 340 )) ;
 TowerLocation.push_back(std::make_pair( 1360 , 20 )) ;}
void renderDemoMap(SDL_Renderer* renderer)
{
    demomap.texture= loadTexture("picture/map/map.png", renderer);
    SDL_RenderCopy(renderer ,demomap.texture, NULL, NULL);
    SDL_Texture * MainTowerTexture= loadTexture("picture/map/castle.png ",renderer);
    SDL_Rect destinationRect = { 1720, 20, 300, 280 };
    SDL_RenderCopy(renderer, MainTowerTexture, NULL, &destinationRect);
    SDL_DestroyTexture(MainTowerTexture);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(demomap.texture);
}
Enemy::Enemy(SDL_Renderer* renderer, const std::vector<std::pair<int, int>>& path, float speed)
    : renderer(renderer), path(path), currentPathIndex(0), speed(speed), x(0), y(0), screenX(0), screenY(0), direction(UP) {
    texture = nullptr;
    currentFrame = 0;
}

void Enemy::loadFrames(int num, const std::string& action) {
    for (int i = 0; i <20; ++i) {
        std:: string numstring;
        if (i<10) numstring="_00"+ std :: to_string(i);
            else numstring="_0"+std :: to_string(i);
        std::string imagePath ="picture/enemy/"+std::to_string(num)+"/"+std::to_string(num)+"_enemies_1"+action+numstring+".png";
        loadTexture(imagePath,renderer);
         frames[i] = { i * 32, 0, 32, 32 };
    }
}
void Enemy::render(SDL_Renderer* renderer, int x, int y) {
    SDL_Rect destinationRect = { x, y, 120, 120 };
    SDL_RenderCopy(renderer, texture, &frames[currentFrame], &destinationRect);
}
void Enemy::move() {
    if (currentPathIndex < path.size()) {
        int nextX = path[currentPathIndex].first;
        int nextY = path[currentPathIndex].second;

        if (x < nextX) {
            direction = RIGHT;
        } else if (x > nextX) {
            direction = LEFT;
        } else if (y < nextY) {
            direction = DOWN;
        } else if (y > nextY) {
            direction = UP;
        }
        switch (direction) {
            case UP:
                y -= speed;
                break;
            case DOWN:
                y += speed;
                break;
            case LEFT:
                x -= speed;
                break;
            case RIGHT:
                x += speed;
                break;
            default:
                break;
        }

        // Cập nhật vị trí vẽ
        screenX = x - 60;
        screenY = y - 60;

        // Tăng chỉ số của vector đường đi khi đến điểm tiếp theo
        if (x == nextX && y == nextY) {
            ++currentPathIndex;
        }
    }
}

void Enemy::updateAnimation() {
    currentFrame = (currentFrame + 1) % 4;
}
void Enemy :: loadAnimation()
{
    while (true) {


         move();
        updateAnimation();

        SDL_RenderClear(renderer);
        render(renderer, 0, 0);
        SDL_RenderPresent(renderer);
}

}
