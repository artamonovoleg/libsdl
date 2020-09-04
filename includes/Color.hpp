#pragma once

#include <SDL2/SDL.h>

namespace sdl
{
    class Color
    {
        private:
            Color () = default;
            ~Color () = default;
        public:
            static int lerp(int start, int end, float percentage);
            static float percent(int start, int end, float current);
            static Uint32 mix_color(Uint32 c1, Uint32 c2, float percent);
            static SDL_Color hex_to_sdl(Uint32 color);
    };    
}