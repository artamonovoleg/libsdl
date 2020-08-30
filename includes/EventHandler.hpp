#pragma once

#include <SDL2/SDL.h>

namespace sdl
{
    class EventHandler
    {
        private:
            static Uint8* _keys;
            static SDL_Event _event;

            enum State
            {
                None,
                Pressed,
                Held,
                Released,
            };

        public:
            static bool isClosed;
            static void initialize();
            static void update();
            static bool inputGetKey(SDL_Scancode scancode);
            static bool inputGetKeyDown(SDL_Scancode scancode);
            static bool inputGetKeyUp(SDL_Scancode scancode);
    };
}