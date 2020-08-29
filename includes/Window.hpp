#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "Text.hpp"
#include "Point.hpp"

namespace sdl
{
    class Window
    {
        private:
            SDL_Window *_window = nullptr;
            SDL_Surface *_surface = nullptr;
        public:
            Window(std::string title, int x, int y, int w, int h, Uint32 flag);
            ~Window();

            void clear();
            void present();

            void drawText(Text &text);
            void drawPoint(Point p);
    };
}