#ifndef SDL_U_H
#define SDL_U_H


#include<bits/stdc++.h>
#include <SDL.h>
#include<SDL_image.h>
extern SDL_Window* window;
extern SDL_Renderer *renderer;

void logSDLError(std:: ostream& os ,const std :: string &msg , bool fatal=false);
void initSDL(SDL_Window* & window, SDL_Renderer* &renderer);
void quitSDL(SDL_Window* & window, SDL_Renderer* &renderer);
SDL_Texture* loadTexture(std :: string path ,SDL_Renderer* renderer);

void renderPicture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) ;
void MakeDemoMap( );
void renderDemoMap(SDL_Renderer* renderer);
 class Enemy {
public:
    Enemy(SDL_Renderer* renderer, const std::vector<std::pair<int, int>>& path, float speed);
    void loadFrames(int num, const std::string& action);
    void render(SDL_Renderer* renderer, int x, int y);
    void move();
    void updateAnimation();
    void loadAnimation();
    int getScreenX() const { return screenX; }
    int getScreenY() const { return screenY; }

private:
    SDL_Texture* texture;
    SDL_Rect frames[4];
    int currentFrame;
    std::vector<std::pair<int, int>> path;
    size_t currentPathIndex;
    float speed;
    int x, y;
    int screenX, screenY;
    enum Direction { UP, DOWN, LEFT, RIGHT };
    Direction direction;
    SDL_Renderer* renderer;
};
class tower
{   SDL_Texture* texture;
    int x; int y;
    int range;
    int ad;
    int speed;
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
Enemy enemy(renderer, path, 2.0f);

#endif //SDL_U_H
