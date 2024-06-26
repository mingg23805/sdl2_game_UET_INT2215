#pragma once
#include <queue>
#include <vector>
#include <string>
#include <SDL.h>
#include "Vector2D.h"
#include "TextureLoader.h"



class Level
{
private:
    enum class Type : int {
    block,
    wall,
    spawner,
    cantbuilt
    };
private:

	static const unsigned char flowDistanceMax = 255;

	struct Tile {
		Type type = Type:: block;
		int flowDirectionX = 0;
		int flowDirectionY = 0;
		unsigned char flowDistance = flowDistanceMax;
	};


public:
	Level(SDL_Renderer* renderer, int setTileCountX, int setTileCountY);
	void draw(SDL_Renderer* renderer, int tileSize);
	bool isTileWall(int x, int y);
	void setTileWall(int x, int y, bool setWall);
	Vector2D getTargetPos();
	Vector2D getFlowNormal(int x, int y);
	Type getTileType(int x, int y);
	void setTileType(int x,int y,Type TileType);
	Vector2D getRanSpawnerLocation();
	bool isMainTower(int x,int y);
	bool tileCantBuilt(int x,int y);

private:
	void calculateFlowField();
	void calculateDistances();
	void calculateFlowDirections();


	std::vector<Tile> listTiles;
	const int tileCountX, tileCountY;

	const int targetX = 0, targetY = 0;

	SDL_Texture* textureTileWall = nullptr,

		*textureTileTarget = nullptr,
		*textureTileEmpty = nullptr,
		*textureTileSpawner = nullptr;
};
