#include "EventHandler.hpp"

Uint8* sdl::EventHandler::_keys;
SDL_Event sdl::EventHandler::_event;
bool sdl::EventHandler::isClosed;

void sdl::EventHandler::initialize()
{
    _keys = new Uint8 [256];
    isClosed = false;

    for (int i = 0; i < 256; i++)
    {
        _keys[i] = State::None;
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
