#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

namespace sdl
{
    class Font
    {
        private:
            TTF_Font *_font = nullptr;
        public:
            Font(std::string path, int ptsize);
            ~Font();

            TTF_Font *get();
    };
}