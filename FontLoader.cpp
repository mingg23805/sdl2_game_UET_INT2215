#include "FontLoader.h"

std::unordered_map<std::string, TTF_Font*> FontLoader::loadedFonts;

TTF_Font* FontLoader::loadFont(const std::string& filename, int fontSize) {
    std::string key = filename + "_" + std::to_string(fontSize);
    auto found = loadedFonts.find(key);

    if (found != loadedFonts.end()) {
        return found->second;
    }
    else {
            std::string filepath="Data/Fonts/"+filename;
        TTF_Font* font = TTF_OpenFont(filepath.c_str(), fontSize);
        if (font != nullptr) {
            loadedFonts[key] = font;
            return font;
        }
    }
}

void FontLoader::deallocateFonts() {
    while (!loadedFonts.empty()) {
        auto it = loadedFonts.begin();
        if (it->second != nullptr) {
            TTF_CloseFont(it->second);
            it->second = nullptr;
        }
        loadedFonts.erase(it);
    }
}
