#include "Events.hpp"
#include <iostream>
bool sdl::Events::_keys[COUNT_KEYS] = { false };
bool sdl::Events::_buttons[COUNT_BUTTONS] = { false };
SDL_Event sdl::Events::_event;

void sdl::Events::handleInput( void )
{
    while (SDL_PollEvent(&_event))
    {
        // Keyboard
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

        // Mouse
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

bool sdl::Events::InputGetButtonDown( int button )
{
    static bool last_state [COUNT_BUTTONS];
    static bool current_state;
    static bool isClicked;

    current_state = sdl::Events::InputGetButton( button );
    if ( current_state != last_state [button] && last_state [button] == false )
        isClicked = true;
    else
        isClicked = false;

    last_state [button] = current_state;

    return isClicked;
}

bool sdl::Events::InputGetButtonUp ( int button )
{
    static bool last_state [COUNT_BUTTONS];
    static bool current_state;
    static bool isReleased;

    current_state = sdl::Events::InputGetButton( button );
    if ( current_state != last_state [button] && last_state [button] == true )
        isReleased = true;
    else
        isReleased = false;

    last_state [button] = current_state;

    return isReleased;
}

