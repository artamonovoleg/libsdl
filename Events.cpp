#include "Events.hpp"

bool sdl::Events::_keys[COUNT_KEYS] = { false };
SDL_Event sdl::Events::_event;

void sdl::Events::handleInput( void )
{
    while (SDL_PollEvent(&_event))
    {
        if (_event.key.keysym.sym < COUNT_KEYS)
        {
            switch (_event.type)
            {
                case SDL_KEYDOWN:
                    _keys[_event.key.keysym.sym] = true;
                    break;
                case SDL_KEYUP:
                    _keys[_event.key.keysym.sym] = false;
                    break;
                default:
                    break;
            }
        }
    }
}

bool sdl::Events::InputGetKey( SDL_KeyCode key )
{
    return _keys[key];
}