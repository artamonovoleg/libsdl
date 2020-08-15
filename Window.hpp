//
// Created by kaygalle on 14.08.2020.
//

#ifndef SDL_WINDOW_HPP
#define SDL_WINDOW_HPP
#include <SDL2/SDL.h>

namespace  sdl
{
    class Window
    {
        private:
            SDL_Window *_window = nullptr; // Manage SDL object
        public:
            Window(int width, int height);
            ~Window(void);

            SDL_Window *get(void);
            int getWidth(void);
            int getHeight(void);
    };
}

#endif //SDL_WINDOW_HPP
