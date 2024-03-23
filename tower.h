#ifndef tower
#define tower
#include"gameplay.h"
enum TowerType {
    archer = 1,
    rock = 2
};
class Tower {
public:
    Tower();
    ~Tower();
    int GetType() {return type;}
    void LoadImg(SDL_Renderer* renderer);
    void Show(SDL_Renderer* renderer, float x, float y);
    void Shoot(SDL_Renderer* renderer, std::vector<Enemy>& Enemy);
    void TowerParameter(int type );
      private:
    int type;

    int x_pos;
    int y_pos;
    int width;
    int height;

    SDL_Texture* texture;
    int lv;
    int range;
    int damage;
    float fireRate;

    int upgradeBaseCost;
	int rangeToAdd;
	int damageToAdd;
    int cost;

};


#endif //tower
