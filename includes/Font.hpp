#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace sdl
{
    class Font
    {
        private:
            // Manage SDL object
            TTF_Font *_font = nullptr; 
        public:
            // Path to font
            Font(std::string path, int ptsize);
            ~Font();
            // Get SDL object
            TTF_Font *get();
    };
}