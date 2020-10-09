#include "Text.hpp"
#include <vector>
#include <sstream>

sdl::Text::Text(Font &font, std::string text, SDL_Color fg_color)
{
    _textRect.x = 0;
    _textRect.y = 0;

    std::stringstream ss(text);
    std::string s;
    std::vector<std::string> lines;

    int max_width = 0;

    while (getline(ss, s, '\n')) 
    {
        lines.push_back(s);
        if ((int) s.length() > max_width)
            max_width = s.length();
    }

    max_width *= font.getSize();
    _surface = SDL_CreateRGBSurface(0, max_width, lines.size() * font.getSize(), 32, 0xff000000, 0x00ff0000, 0x0000ff00, 0x000000ff);

    int current_y = 0;

    for (std::string& s : lines)
    {
        SDL_Surface* temp_s = TTF_RenderText_Blended(font.get(), s.c_str(), fg_color);
        SDL_Rect temp_r = {0, current_y, temp_s->w, temp_s->h};
        SDL_BlitSurface (temp_s, nullptr, _surface, &temp_r);
        current_y += font.getSize();
    }
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