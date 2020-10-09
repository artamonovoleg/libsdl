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
            /*
                _surface - Store text surface
                _textRect - Store text position, text box width/height
            */
            SDL_Surface *_surface;
            SDL_Rect _textRect;
        public:
            Text(Font &font, std::string text, SDL_Color fg_color);
            ~Text (); 
            // Set position of text box
            void setPos(int x, int y);
            
            SDL_Rect* getRect();
            SDL_Surface* getSurface();
    };
}