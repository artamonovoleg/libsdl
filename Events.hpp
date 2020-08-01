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
            static bool _buttons[6];
            static SDL_Event _event;
        public:
            static void handleInput ( void );
            static void getMousePosition( int * x, int * y );
            static bool InputGetKey ( SDL_KeyCode key);
            static bool InputGetButton( int button );
    };
}

#endif