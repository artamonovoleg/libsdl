#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "Text.hpp"
#include "Point.hpp"
#include "Vector.hpp"

namespace sdl
{
    class Window
    {
        private:
            /* Manage SDL objects
                _window - Store SDL window
                _surface - Store window surface
            */
            SDL_Window *_window = nullptr;
            SDL_Surface *_surface = nullptr;

            // Bg color
            Uint8 _r = 0x00;
            Uint8 _g = 0x00;
            Uint8 _b = 0x00;
        public:
            Window(std::string title, int x, int y, int w, int h, Uint32 flag);
            ~Window();
            // Fill window surface with bg color
            void clear();
            // Present updated window surface
            void present();

            // Parameters - text box. Blit two surface in one
            void drawText(Text &text);
            // Put pixel on window surface
            void putPixel(int x, int y, Uint32 color);
            void drawLine(int x1, int y1, Uint32 start_color, int x2, int y2, Uint32 end_color);

            int getWidth();
            int getHeight();
            void getWindowSize(int *width, int*height);

            // Set new _r _g _b
            void setBgColor(Uint32 color);
            void setFullscreenMode();
    };
}