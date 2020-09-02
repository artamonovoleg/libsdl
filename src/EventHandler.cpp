#include "EventHandler.hpp"

Uint8* sdl::EventHandler::_keys;
Uint8* sdl::EventHandler::_mouse_buttons;

SDL_Event sdl::EventHandler::_event;
bool sdl::EventHandler::isClosed;
bool sdl::EventHandler::scrollDown;
bool sdl::EventHandler::scrollUp;

void sdl::EventHandler::initialize()
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

void sdl::EventHandler::update()
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

bool sdl::EventHandler::inputGetKey(SDL_Scancode scancode)
{
    return (_keys[scancode] == State::Pressed || _keys[scancode] == State::Held);
}

bool sdl::EventHandler::inputGetKeyDown(SDL_Scancode scancode)
{
    if (_keys[scancode] == State::Pressed)
    {
        _keys[scancode] = State::Held;
        return true;
    }
    else
        return false;
}

bool sdl::EventHandler::inputGetKeyUp(SDL_Scancode scancode)
{
    if (_keys[scancode] == State::Released)
    {
        _keys[scancode] = State::None;
        return true;
    }
    return false;
}

void sdl::EventHandler::getMousePosition(int &x, int &y)
{
    SDL_GetMouseState(&x, &y);
}

bool sdl::EventHandler::isScrollingDown()
{
    if (scrollDown == true)
    {
        scrollDown = false;
        return true;
    }
    else
        return false;
}

bool sdl::EventHandler::isScrollingUp()
{
    if (scrollUp == true)
    {
        scrollUp = false;
        return true;
    }
    else
        return false;
}

bool sdl::EventHandler::inputGetButtonDown(int button)
{
    if (_mouse_buttons[button] == State::Pressed)
    {
        _mouse_buttons[button] = State::Held;
        return true;
    }
    else
        return false;    
}

bool sdl::EventHandler::inputGetButtonUp(int button)
{
    if (_mouse_buttons[button] == State::Released)
    {
        _mouse_buttons[button] = State::None;
        return true;
    }
    else
        return false;
}