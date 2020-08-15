//
// Created by kaygalle on 15.08.2020.
//

#include "Font.hpp"
#include "Exception.hpp"

sdl::Font::Font(const char *file, int ptsize)
{
    if((_font = TTF_OpenFont(file, ptsize)) == nullptr)
        throw Exception("Failed to read font");
}

sdl::Font::~Font(void)
{
    if( _font != nullptr)
        free(_font);
};

TTF_Font *sdl::Font::get(void) { return _font; }


