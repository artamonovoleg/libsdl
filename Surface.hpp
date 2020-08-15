//
// Created by kaygalle on 14.08.2020.
//

#ifndef SDL_SURFACE_HPP
#define SDL_SURFACE_HPP
#include <SDL2/SDL.h>

namespace sdl
{
    class Surface
    {
        private:
            SDL_Surface *_surface = nullptr;
        public:
            Surface(int width, int height);
            Surface(SDL_Surface *surface);
            ~Surface(void);

            SDL_Surface *get(void);

            void null();
    };
}
#endif //SDL_SURFACE_HPP
