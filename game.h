#pragma once
#include<bits/stdc++.h>
#include <SDL.h>
#include "Unit.h"
#include "Level.h"
#include"timer.h"
#include"turret.h"
#include"projectile.h"
#include"MixerLoader.h"
#include"FontLoader.h"
#include"HealthBar.h"





class Game
{
private:
	enum class PlacementMode {
		wall,
		turret
	} placementModeCurrent;


     TTF_Font* gameOFont=nullptr;
     TTF_Font* gameFont=nullptr;

    SDL_Surface* gameOverSurface=nullptr;
    SDL_Texture* gameOverTexture=nullptr;
    SDL_Rect gameOverRect={0,0,0,0};

    SDL_Surface* pointSurface=nullptr;
    SDL_Texture* pointTexture=nullptr;
    SDL_Rect pointRect={0,0,0,0};

    SDL_Surface* lvlSurface=nullptr;
    SDL_Texture* lvlTexture=nullptr;
    SDL_Rect lvlRect={0,0,0,0};


    SDL_Surface*  highestPointSurface=nullptr;
    SDL_Texture*  highestPointTexture=nullptr;
    SDL_Rect      highestPointRect={0,0,0,0 } ;




    SDL_Surface*  numCanBuiltSurface=nullptr;
    SDL_Texture*  numCanBuiltTexture=nullptr;
    SDL_Rect      numCanBuiltRect={0,0,0,0 } ;

    SDL_Texture* turtext=nullptr;
    SDL_Rect      turRect={0,0,0,0 } ;

    Mix_Chunk* mix_chunkSpawnUnit=nullptr;
public:
	Game(SDL_Window* window, SDL_Renderer* renderer, int windowWidth, int windowHeight);
	~Game();
     int mainTowerHp=20;
     int point=0;
     int highestPoint;
     int maxBlockcanBuild=4;

private:
	void processEvents(SDL_Renderer* renderer, bool& running);

	void update(float dT,SDL_Renderer *renderer);
	void updateSpawnUnits(SDL_Renderer *renderer ,float dT);
	void updateUnits(float dT);
	void updateProjectiles(float dT);
	void draw(SDL_Renderer* renderer);
	void addUnit(SDL_Renderer* renderer, Vector2D posMouse);
    void addTurret(SDL_Renderer* renderer, Vector2D posMouse);
    bool isGameOver();
	void removeUnitsAtMousePosition(Vector2D posMouse);
    void removeTurretsAtMousePosition(Vector2D posMouse);

    bool  isTurretAt(float x ,float y );
	int mouseDownStatus = 0;

	const int tileSize = 48;
	Level level;

	std::vector<std::shared_ptr<Unit>> listUnits;//ptr tro den cung 1 dt
	std::vector<Turret>listTurrets;
    std::vector<Projectile> listProjectiles;
    Timer spawnT ,roundT;

    int unitCount;
    int lv=0;
	bool overlayVisible = true;
//	Mix_Music*music= Mix_LoadMUS("Data/Sounds/music.mp3");
   HealthBar mainHpBar;



};
