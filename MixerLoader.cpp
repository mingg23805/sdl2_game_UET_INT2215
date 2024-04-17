#include"MixerLoader.h"
 std::unordered_map<std::string, Mix_Chunk*> MixerLoader::umapMixLoaded   ;
Mix_Chunk* MixerLoader::loadMix(std::string filename)
{   if( filename != "")
    { auto found =umapMixLoaded.find(filename);

      if(found!=umapMixLoaded.end())
        return found->second;

      else{
        std::string filepath="Data/Sounds/"+filename;

        Mix_Chunk* mix_chunk=Mix_LoadWAV(filepath.c_str());
        if( mix_chunk!=nullptr ){
            umapMixLoaded[filename]=mix_chunk;
            return mix_chunk;
        }
      }
     }
return nullptr;
}

void MixerLoader::deallocateMix()
{
      Mix_HaltChannel(-1);
    while(umapMixLoaded.empty()==false)
    {
        auto it =umapMixLoaded.begin();
        if(it->second!=nullptr)
            Mix_FreeChunk(it->second);

        umapMixLoaded.erase(it);


    }

}
