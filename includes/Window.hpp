#pragma once

#include <SDL2/SDL.h>
#include <string>

#include "Text.hpp"
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
            void Clear();
            // Present updated window surface
            void Present();

            // Parameters - text box. Blit two surface in one
            void    DrawText(Text &text);
            // Put pixel on window surface
            void    PutPixel(int x, int y, Uint32 color);
            void    DrawLine(int x1, int y1, Uint32 start_color, int x2, int y2, Uint32 end_color);

            int     GetWidth();
            int     GetHeight();
            void    GetWindowSize(int *width, int*height);

            // Set new _r _g _b
            void    SetClearColor(Uint32 color);
            void    SetFullscreenMode();

            bool    ShouldClose();
    };
}