//
// Created by kaygalle on 15.08.2020.
//

#ifndef SDL_FONT_HPP
#define SDL_FONT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace sdl
{
    class Font
    {
        private:
            TTF_Font *_font;
        public:
            Font(const char *file, int ptsize);
            ~Font(void);

            TTF_Font *get(void);
    };
}

#endif //SDL_FONT_HPP
