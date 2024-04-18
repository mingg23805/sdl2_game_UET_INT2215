#include"MixerLoader.h"
 std::vector<std::string> MixerLoader::umapMixLoaded   ;
std::string MixerLoader::loadMix(std::string filename)
{  if(filename!="")
    {auto found =std::find(umapMixLoaded.begin(),umapMixLoaded.end(),
                           filename);

      if(found!=umapMixLoaded.end())
       {
          int index= std::distance(umapMixLoaded.begin(),found);
        return umapMixLoaded[index];
       }
      else{
        std::string filepath="Data/Sounds/"+filename;
             umapMixLoaded.push_back(filepath);
             return filepath;
            }
         }
}


void MixerLoader::deallocateMix()
{
         PlaySound(NULL, NULL, 0);
    while(umapMixLoaded.empty()==false)
    {
        auto it = umapMixLoaded.begin();
       umapMixLoaded.erase(it);


    }

}
