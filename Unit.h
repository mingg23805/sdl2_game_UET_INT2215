#pragma once
#include <vector>
#include <SDL.h>
#include "Vector2D.h"
#include "Level.h"
#include "TextureLoader.h"
#include <memory>
#include"timer.h"
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

    int maxHp=2;
    int currentHp=maxHp;

private:
	Vector2D pos;
     Timer timeJustHurt;
	static const float speed;
	static const float size;
	SDL_Texture* texture = nullptr;
};
