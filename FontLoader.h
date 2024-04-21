
#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <unordered_map>
#include <string>

class FontLoader {
public:
    static std::unordered_map<std::string, TTF_Font*> loadedFonts;

    static TTF_Font* loadFont(const std::string& filename, int fontSize);

    static void deallocateFonts();
};
