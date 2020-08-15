//
// Created by kaygalle on 15.08.2020.
//

#include "Window.hpp"
#include "Exception.hpp"

sdl::Window::Window(int width, int height)
{
    if ((_window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI)) == nullptr)
    {
        throw Exception("Failed to create window");
    }
}

sdl::Window::~Window(void)
{
    if (_window != nullptr)
        SDL_DestroyWindow(_window);
}

SDL_Window *sdl::Window::get(void) { return _window; }

int sdl::Window::getWidth(void)
{
    int width;
    SDL_GetWindowSize(_window, &width, nullptr);
    return width;
}

int sdl::Window::getHeight(void)
{
    int height;
    SDL_GetWindowSize(_window, nullptr, &height);
    return height;
};




