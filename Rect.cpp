//
// Created by kaygalle on 15.08.2020.
//

#include "Rect.hpp"

sdl::Rect::Rect(int x, int y, int w, int h)
{
    _rect.x = x;
    _rect.y = y;
    _rect.w = w;
    _rect.h = h;
}

SDL_Rect *sdl::Rect::get(void) { return &_rect; }