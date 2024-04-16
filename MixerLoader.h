#pragma once
#include<string>
#include<SDL_mixer.h>
#include<bits/stdc++.h>

class MixerLoader
{
    public:
  static  Mix_Chunk* loadMix(std::string filename);
   static void deallocateMix();

    private:
  static std::unordered_map<std::string, Mix_Chunk*> umapMixLoaded   ;
};
