#include "Surface.hpp"

Uint32 sdl::Surface::rmask = 0;
Uint32 sdl::Surface::gmask = 0;
Uint32 sdl::Surface::bmask = 0;
Uint32 sdl::Surface::amask = 0;

SDL_Surface * sdl::Surface::_surface = nullptr;

int sdl::Surface::_width;
int sdl::Surface::_height;

SDL_Surface * sdl::Surface::createSurface( void )
{
    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0x000000ff;
    #else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        amask = 0xff000000;
    #endif

    return (SDL_CreateRGBSurface(0, Window::getWidth() , Window::getHeight(), 32, rmask, gmask, bmask, amask));
}

SDL_Surface * sdl::Surface::createSurface( int width, int height )
{
    _width = width;
    _height = height;

    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        rmask = 0xff000000;
        gmask = 0x00ff0000;
        bmask = 0x0000ff00;
        amask = 0x000000ff;
    #else
        rmask = 0x000000ff;
        gmask = 0x0000ff00;
        bmask = 0x00ff0000;
        amask = 0xff000000;
    #endif

    return (SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask));
}

void sdl::Surface::setSurface( SDL_Surface * surface )
{
    _width = surface -> w;
    _height = surface -> h;
    _surface = surface;
    SDL_UpdateTexture(sdl::Texture::getTexture(), NULL, surface->pixels, surface->pitch);
	SDL_RenderCopy(sdl::Window::getRenderer(), sdl::Texture::getTexture(), NULL, NULL);
	SDL_RenderPresent(sdl::Window::getRenderer());
}