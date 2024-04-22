#pragma once
#include <vector>
#include <SDL.h>
#include "Vector2D.h"
#include "Level.h"
#include "TextureLoader.h"
#include <memory>
#include"timer.h"
#include"HealthBar.h"
class Game;



class Unit
{
public:
	Unit(SDL_Renderer* renderer, Vector2D setPos);
	void update(float dT, Level& level, std::vector<std::shared_ptr<Unit> >& listUnits);
	void draw(SDL_Renderer* renderer, int tileSize);
	bool checkOverlap(Vector2D posOther, float sizeOther);
    bool checkALive();
    Vector2D getPos();
    void hploss(int dmg);
   bool hasReachedTarget(Level& level);
    void getStrongerUnit(int &lv)
    {
        this->maxHp=2+lv;
        this->speed= 0.8f+ (float)(lv) * (0.5f);
        this->currentHp=maxHp;
        hpBar.maxHP=maxHp;
        hpBar.currentHP=maxHp;

    }
private:


	Vector2D pos;
     Timer timeJustHurt;
     int maxHp;
     int currentHp;
     float speed;
	static const float size;
	SDL_Texture* texture = nullptr;
	 HealthBar hpBar;

};
