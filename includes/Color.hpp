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
            static int Lerp(int start, int end, float percentage);
            static float Percent(int start, int end, float current);
            static Uint32 MixColor(Uint32 c1, Uint32 c2, float percent);
            static SDL_Color HexToSdl(Uint32 color);
    };    
}