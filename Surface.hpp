#ifndef SURFACE_HPP
#define SURFACE_HPP

#include "libsdl.hpp"

namespace sdl
{
    class Surface
    {
        private:
            Surface() = default;
            static Uint32 rmask, gmask, bmask, amask;
            static SDL_Surface * _surface;
            static int _width;
            static int _height;
        public:
            // Default surface creator. Take window size as parameters
            static SDL_Surface * createSurface ( void );
            // Own sizes for surface
            static SDL_Surface * createSurface ( int width, int height );
            // Set current surface
            static void setSurface( SDL_Surface * surface );
            
            // Getters
            static SDL_Surface * getSurface( void ) { return _surface; };

            static int getWidth( void ) { return _width; };
            static int getHeight( void ) { return _height; };
    };
}

#endif