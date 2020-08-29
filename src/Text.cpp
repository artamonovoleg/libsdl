#include "Text.hpp"

sdl::Text::Text (Font &font, std::string text, SDL_Color color)
{
    _surface = TTF_RenderText_Blended (font.get(), text.c_str(), color);
    _textRect.x = 0;
    _textRect.y = 0;
    _textRect.w = _surface->w;
    _textRect.h = _surface->h;
}

sdl::Text::~Text()
{
    SDL_FreeSurface (_surface);
}

void sdl::Text::setPos(int x, int y)
{
    _textRect.x = x;
    _textRect.y = y;
}

SDL_Rect *sdl::Text::getRect()
{
    return &_textRect;
}

SDL_Surface *sdl::Text::getSurface()
{
    return _surface;
}