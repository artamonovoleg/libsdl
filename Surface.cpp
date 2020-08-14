//
// Created by kaygalle on 14.08.2020.
//

#include "Surface.hpp"

sdl::Surface::Surface(int width, int height)
{
    Uint32 rmask, gmask, bmask, amask;

    rmask = 0x000000ff;
    gmask = 0x0000ff00;
    bmask = 0x00ff0000;
    amask = 0xff000000;
    if ((_surface = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask)) == nullptr)
        throw Exception("SDL_CreateRGBSurface");
}

sdl::Surface::Surface(SDL_Surface *surface)
{
    if ((_surface = surface) == nullptr)
        throw Exception("Null surface");
}

sdl::Surface::~Surface(void)
{
    if (_surface != nullptr)
        SDL_FreeSurface(_surface);
}

SDL_Surface *sdl::Surface::get(void) { return _surface; }

void sdl::Surface::null()
{
    _surface = nullptr;
}

