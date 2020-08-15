//
// Created by kaygalle on 14.08.2020.
//

#ifndef SDL_TEXTURE_HPP
#define SDL_TEXTURE_HPP

#include <SDL2/SDL.h>
#include "Renderer.hpp"
#include "Surface.hpp"

namespace sdl
{
    class Texture
    {
        private:
            /* Manage SDL fields */
            SDL_Texture *_texture = nullptr;
            SDL_Rect *_srcRect = nullptr;
            SDL_Rect *_dstRect = nullptr;

            Renderer &_renderer;
            Surface _surface;
        public:
            Texture(Renderer &renderer, int width, int height);
            Texture(Renderer &renderer, Surface &surface);
            ~Texture(void);

            SDL_Texture *get(void);
            Surface &getSurface(void);
            SDL_Rect *getSrcRect(void);
            SDL_Rect *getDstRect(void);

            void setRects( SDL_Rect* srcRect, SDL_Rect* dstRect);

            void fillRect(Uint32 color);
            void updateTexture(void);
    };
}
#endif //SDL_TEXTURE_HPP
