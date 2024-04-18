#pragma once
#include<bits/stdc++.h>
#include <SDL.h>
#include "Unit.h"
#include "Level.h"
#include"timer.h"
#include"turret.h"
#include"projectile.h"

#include <windows.h>
#include<mmsystem.h>
class Game
{
private:
	enum class PlacementMode {
		wall,
		turret
	} placementModeCurrent;


public:
	Game(SDL_Window* window, SDL_Renderer* renderer, int windowWidth, int windowHeight);
	~Game();


private:
	void processEvents(SDL_Renderer* renderer, bool& running);

	void update(float dT,SDL_Renderer *renderer);
	void updateSpawnUnits(SDL_Renderer *renderer ,float dT);
	void updateUnits(float dT);
	void updateProjectiles(float dT);
	void draw(SDL_Renderer* renderer);
	void addUnit(SDL_Renderer* renderer, Vector2D posMouse);
    void addTurret(SDL_Renderer* renderer, Vector2D posMouse);

	void removeUnitsAtMousePosition(Vector2D posMouse);
    void removeTurretsAtMousePosition(Vector2D posMouse);

	int mouseDownStatus = 0;

	const int tileSize = 48;
	Level level;

	std::vector<std::shared_ptr<Unit>> listUnits;//ptr tro den cung 1 dt
	std::vector<Turret>listTurrets;
    std::vector<Projectile> listProjectiles;
    Timer spawnT ,roundT;

    int unitCount=0;
    int lv=0;

    LPCSTR  mix_chunkSpawnUnit;
	SDL_Texture* textureOverlay = nullptr;
	bool overlayVisible = true;
};
