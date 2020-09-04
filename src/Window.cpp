#include "Window.hpp"
#include "Color.hpp"

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
    SDL_FillRect(_surface, nullptr, SDL_MapRGB(_surface->format, _r, _g, _b));
}

void sdl::Window::present()
{
    SDL_UpdateWindowSurface(_window);
}

void sdl::Window::drawText(Text &text)
{
    SDL_BlitSurface(text.getSurface(), nullptr, _surface, text.getRect());
}

void sdl::Window::putPixel(int x, int y, Uint32 color)
{
    if (x >= 0 && x < _surface->w && y >= 0 && y < _surface->h)
        *((Uint32*)(_surface->pixels) + (x + y * _surface->w)) = color;
}

void sdl::Window::drawLine(int x1, int y1, Uint32 start_color, int x2, int y2, Uint32 end_color)
{
    int x, y, xe, ye;
    Uint32 color;

    int dx = x2 - x1;
    int dy = y2 - y1;
    int dx1 = abs(dx);
    int dy1 = abs(dy);
    int px = 2 * dy1 - dx1;
    int py = 2 * dx1 - dy1;
    if (dy1 <= dx1)
    {
        if (dx >= 0)
        {
            x = x1;
            y = y1;
            xe = x2;
        }
        else
        {
            x = x2;
            y = y2;
            xe = x1;
        }
        color = sdl::Color::mix_color(start_color, end_color, sdl::Color::percent(x1, x2, x));

        putPixel(x, y, color);

        for (int i = 0; x < xe; i++)
        {
            x++;
            if (px < 0)
                px = px + 2 * dy1;
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    y++;
                else
                    y--;
                px = px + 2 * (dy1 - dx1);
            }
            color = sdl::Color::mix_color(start_color, end_color, sdl::Color::percent(x1, x2, x));

            putPixel(x, y, color);
        }
    }
    else
    {
        if (dy >= 0)
        {
            x = x1;
            y = y1;
            ye = y2;
        }
        else
        {
            x = x2;
            y = y2;
            ye = y1;
        }
        color = sdl::Color::mix_color(start_color, end_color, sdl::Color::percent(x1, x2, x));

        putPixel(x, y, color);

        for (int i = 0; y < ye; i++)
        {
            y++;
            if (py <= 0)
                py = py + 2 * dx1;
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    x++;
                else
                    x--;
                py = py + 2 * (dx1 - dy1);
            }
            color = sdl::Color::mix_color(start_color, end_color, sdl::Color::percent(x1, x2, x));

            putPixel(x, y, color);
        }
    }
}

int sdl::Window::getWidth()
{
    int width;
    SDL_GetWindowSize(_window, &width, nullptr);
    return width;
}

int sdl::Window::getHeight()
{
    int height;
    SDL_GetWindowSize(_window, nullptr, &height);
    return height;
}

void sdl::Window::getWindowSize(int *width, int *height)
{
    SDL_GetWindowSize(_window, width, height);
}

void sdl::Window::setBgColor(Uint32 color)
{
    _r = (color >> 16) & 0xFF;
    _g = (color >> 8) & 0xFF;
    _b = (color) & 0xFF;
}

void sdl::Window::setFullscreenMode()
{
    SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN);
}