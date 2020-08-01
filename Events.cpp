#include "Events.hpp"
#include <iostream>
bool sdl::Events::_keys[COUNT_KEYS] = { false };
bool sdl::Events::_buttons[6] = { false };

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

        switch (_event.type)
        {
            case SDL_MOUSEBUTTONDOWN:
                _buttons[_event.button.button] = true;
                break;
            case SDL_MOUSEBUTTONUP:
                _buttons[_event.button.button] = false;
                break;
            default:
                break;
        }
    }

    
}

bool sdl::Events::InputGetButton( int button )
{
    return _buttons[button];
}

void sdl::Events::getMousePosition( int * x, int * y )
{
    SDL_GetMouseState(x, y);
}

bool sdl::Events::InputGetKey( SDL_KeyCode key )
{
    return _keys[key];
}