#include"MixerLoader.h"
 std::unordered_map<char*, Mix_Chunk*> SoundLoader::umapSoundsLoaded;


Mix_Chunk* SoundLoader::loadSound(char* filename) {
    if (filename != "") {
        auto found = umapSoundsLoaded.find(filename);

        if (found != umapSoundsLoaded.end()) {
            return found->second;
        }
        else {

            Mix_Chunk* mix_Chunk = Mix_LoadWAV(filename);
            if (mix_Chunk != nullptr) {


                umapSoundsLoaded[filename] = mix_Chunk;

                return mix_Chunk;
            }
        }
    }

    return nullptr;
}



void SoundLoader::deallocateSounds() {

    Mix_HaltChannel(-1);

    while (umapSoundsLoaded.empty() == false) {
        auto it = umapSoundsLoaded.begin();
        if (it->second != nullptr)
            Mix_FreeChunk(it->second);

        umapSoundsLoaded.erase(it);
    }
}


