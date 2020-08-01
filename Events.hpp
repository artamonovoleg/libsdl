#ifndef EVENTS_HPP
#define EVENTS_HPP

#include "libsdl.hpp"

#define COUNT_KEYS 332
namespace sdl
{
    class Events
    {
        private:
            static bool _keys[COUNT_KEYS];
            static SDL_Event _event;
        public:
            static void handleInput ( void );
            static bool InputGetKey ( SDL_KeyCode key);
    };
}

#endif