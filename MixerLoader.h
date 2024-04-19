#pragma once
#include <string>
#include <unordered_map>
#include <SDL_mixer.h>



class SoundLoader
{
public:
	static Mix_Chunk* loadSound(char* filename);
	static void deallocateSounds();


private:
	static std::unordered_map<char*, Mix_Chunk*> umapSoundsLoaded;
};
