#include "EventHandler.hpp"

Uint8* sdl::EventHandler::_keys;
Uint8* sdl::EventHandler::_mouse_buttons;

SDL_Event sdl::EventHandler::_event;
bool sdl::EventHandler::isClosed;
bool sdl::EventHandler::scrollDown;
bool sdl::EventHandler::scrollUp;

void sdl::EventHandler::Init()
{
    _keys = new Uint8 [256];
    _mouse_buttons = new Uint8 [3];
    isClosed = false;
    
    scrollUp = false;
    scrollDown = false;
    
    for (int i = 0; i < 256; i++)
    {
        _keys[i] = State::None;
    }

    for (int i = 0; i < 3; i++)
    {
        _mouse_buttons [i] = State::None;
    }
}

void sdl::EventHandler::PollEvents()
{
    while (SDL_PollEvent(&_event))
    {
        switch (_event.type)
        {
            case SDL_QUIT:
                isClosed = true;
            break;
            case SDL_KEYDOWN:
                if ((int)_event.key.repeat == 0)
                    _keys[_event.key.keysym.scancode] = State::Pressed;
                else
                    _keys[_event.key.keysym.scancode] = State::Held;
            break;
            case SDL_KEYUP:
                _keys[_event.key.keysym.scancode] = State::Released;
            break;
            case SDL_MOUSEWHEEL:
                if (_event.wheel.y > 0)
                {
                    scrollUp = true;
                    scrollDown = false;
                }
                else
                if (_event.wheel.y < 0)
                {
                    scrollDown = true;
                    scrollUp = false;
                }
            break;
            case SDL_MOUSEBUTTONDOWN:
                _mouse_buttons[_event.button.button] = State::Pressed;
            break;
            case SDL_MOUSEBUTTONUP:
                _mouse_buttons[_event.button.button] = State::Released;
            break;
            break;
            default:
            break;
        }
    }
}

bool sdl::EventHandler::InputGetKey(SDL_Scancode scancode)
{
    return (_keys[scancode] == State::Pressed || _keys[scancode] == State::Held);
}

bool sdl::EventHandler::InputGetKeyDown(SDL_Scancode scancode)
{
    if (_keys[scancode] == State::Pressed)
    {
        _keys[scancode] = State::Held;
        return true;
    }
    else
        return false;
}

bool sdl::EventHandler::InputGetKeyUp(SDL_Scancode scancode)
{
    if (_keys[scancode] == State::Released)
    {
        _keys[scancode] = State::None;
        return true;
    }
    return false;
}

void sdl::EventHandler::GetMousePosition(int &x, int &y)
{
    SDL_GetMouseState(&x, &y);
}

bool sdl::EventHandler::IsScrollingDown()
{
    if (scrollDown == true)
    {
        scrollDown = false;
        return true;
    }
    else
        return false;
}

bool sdl::EventHandler::IsScrollingUp()
{
    if (scrollUp == true)
    {
        scrollUp = false;
        return true;
    }
    else
        return false;
}

bool sdl::EventHandler::InputGetButton(int button)
{
    return ((_mouse_buttons[button] == State::Held) || _mouse_buttons[button] == Pressed);
}

bool sdl::EventHandler::InputGetButtonDown(int button)
{
    if (_mouse_buttons[button] == State::Pressed)
    {
        _mouse_buttons[button] = State::Held;
        return true;
    }
    else
        return false;    
}

bool sdl::EventHandler::InputGetButtonUp(int button)
{
    if (_mouse_buttons[button] == State::Released)
    {
        _mouse_buttons[button] = State::None;
        return true;
    }
    else
        return false;
}