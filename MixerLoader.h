#pragma once
#include<string>
#include <windows.h>
#include<mmsystem.h>
#include <vector>
#include <algorithm>

class MixerLoader
{
    public:
  static std::string loadMix(std::string filename);
   static void deallocateMix();

    private:
  static std::vector<std::string> umapMixLoaded   ;
};
