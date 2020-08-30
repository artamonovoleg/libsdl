#pragma once

#include <SDL2/SDL.h>

namespace sdl
{
    class EventHandler
    {
        private:
            static SDL_Event _event;
            // Keyboard state
            static const Uint8 *last_frame;
            static const Uint8 *current_frame;
            // 
        public:
            static bool isClosed;

            static void initialize();
            static void update();
            static bool inputGetKey(SDL_Scancode scancode);
            static bool inputGetKeyDown(SDL_Scancode scancode);
            static bool inputGetKeyUp(SDL_Scancode scancode);
    };
}