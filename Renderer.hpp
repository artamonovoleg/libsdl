//
// Created by kaygalle on 14.08.2020.
//

#ifndef SDL_RENDERER_HPP
#define SDL_RENDERER_HPP

#include <SDL2/SDL.h>

namespace sdl
{
    class Texture;
    class Window;

    class Renderer
    {
        private:
            SDL_Renderer *_renderer = nullptr; // Manage SDL object
        public:
            Renderer(Window &w);
            ~Renderer(void);

            void clearRenderer(void);
            void renderCopy(sdl::Texture &texture);
            void presentRenderer(void);

            SDL_Renderer *get(void);
    };
}

#endif //SDL_RENDERER_HPP
