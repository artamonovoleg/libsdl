#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <string>

#include "Font.hpp"

namespace sdl
{
    class Text
    {
        private:
            SDL_Surface *_surface;
            SDL_Rect _textRect;
        public:
            Text(Font &font, std::string text, SDL_Color color);
            ~Text (); 

            void setPos(int x, int y);

            SDL_Rect *getRect();
            SDL_Surface *getSurface();
    };
}