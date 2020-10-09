#include "Font.hpp"

sdl::Font::Font(std::string path, int ptsize) : _ptsize(ptsize)
{
    TTF_Init();
    _font = TTF_OpenFont(path.c_str(), ptsize);
}

sdl::Font::~Font()
{
    TTF_CloseFont(_font);
    TTF_Quit();
}

int sdl::Font::getSize()
{
    return _ptsize;
}

TTF_Font *sdl::Font::get()
{
    return _font;
}
