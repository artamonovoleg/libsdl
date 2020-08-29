#include "Window.hpp"

sdl::Window::Window(std::string title, int x, int y, int w, int h, Uint32 flag)
{
    _window = SDL_CreateWindow(title.c_str(), x, y, w, h, flag);
    _surface = SDL_GetWindowSurface(_window);
}

sdl::Window::~Window()
{
    SDL_DestroyWindow(_window);
}

void sdl::Window::clear()
{
    SDL_FillRect(_surface, nullptr, SDL_MapRGB(_surface->format, 0x00, 0x00, 0x00));
}

void sdl::Window::present()
{
    SDL_UpdateWindowSurface(_window);
}

void sdl::Window::drawText(Text &text)
{
    SDL_BlitSurface(text.getSurface(), nullptr, _surface, text.getRect());
}

void sdl::Window::drawPoint(Point p)
{
    if (p.position.x >= 0 && p.position.x < _surface->w && p.position.y >= 0 && p.position.y < _surface->h)
        *((Uint32*)(_surface->pixels) + (p.position.x + p.position.y * _surface->w)) = p.color;
}