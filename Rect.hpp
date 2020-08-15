//
// Created by kaygalle on 15.08.2020.
//

#ifndef SDL_RECT_HPP
#define SDL_RECT_HPP

#include <SDL2/SDL.h>

namespace sdl
{
    class Rect
    {
        private:
            SDL_Rect _rect;
        public:
            Rect(int x, int y, int w, int h);
            ~Rect() = default;

            SDL_Rect *get(void);
    };
}

#endif //SDL_RECT_HPP
