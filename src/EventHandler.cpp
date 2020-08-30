#include "EventHandler.hpp"

SDL_Event sdl::EventHandler::_event;

bool sdl::EventHandler::isClosed = false;
const Uint8 *sdl::EventHandler::last_frame;
const Uint8 *sdl::EventHandler::current_frame;

void sdl::EventHandler::initialize()
{
    current_frame = SDL_GetKeyboardState(nullptr);
    last_frame = current_frame;
}

void sdl::EventHandler::update()
{
    SDL_PumpEvents();
    // last_frame = current_frame;
    current_frame = SDL_GetKeyboardState(nullptr);

    while (SDL_PollEvent(&_event))
    {
        switch (_event.type)
        {
            case SDL_QUIT:
                isClosed = true;
            break;
            default:
            break;
        }
    }
}

bool sdl::EventHandler::inputGetKey(SDL_Scancode scancode)
{
    return current_frame[scancode];
}

// NOT WORK. NEED TIMER FOR last_frame 

bool sdl::EventHandler::inputGetKeyDown(SDL_Scancode scancode)
{
    return (last_frame[scancode] != current_frame [scancode] && last_frame[scancode] == 0);
}

bool sdl::EventHandler::inputGetKeyUp(SDL_Scancode scancode)
{
    return (last_frame[scancode] != current_frame [scancode] && last_frame[scancode] == 1);
}