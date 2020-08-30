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

            // Bg color
            Uint8 _r = 0x00;
            Uint8 _g = 0x00;
            Uint8 _b = 0x00;
        public:
            Window(std::string title, int x, int y, int w, int h, Uint32 flag);
            ~Window();

            void clear();
            void present();

            void drawText(Text &text);
            void drawPoint(Point p);
            void drawLine(Point start, Point end);

            int getWidth();
            int getHeight();
            void getWindowSize(int *width, int*height);

            void setBgColor(Uint32 color);
    };
}