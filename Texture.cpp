#include "Texture.hpp"

SDL_Texture * sdl::Texture::_texture = nullptr;
SDL_Rect * sdl::Texture::_srcRect = NULL;
SDL_Rect * sdl::Texture::_dstRect = NULL;

SDL_Texture * sdl::Texture::createTexture( void )
{
    return (SDL_CreateTexture(sdl::Window::getRenderer(), SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, Window::getWidth(), Window::getHeight()));
}

SDL_Texture * sdl::Texture::createTexture( int width, int height )
{
    return (SDL_CreateTexture(sdl::Window::getRenderer(), SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, width, height));
}

void sdl::Texture::setTexture( SDL_Texture * texture )
{
    _dstRect = NULL;
    _srcRect = NULL;
    SDL_UnlockTexture(_texture);
	SDL_RenderCopy(sdl::Window::getRenderer(), texture, NULL, NULL);
	SDL_RenderPresent(sdl::Window::getRenderer());
    _texture = texture;
}

void sdl::Texture::setTexture( SDL_Texture * texture, SDL_Rect * srcrect, SDL_Rect * dstrect )
{
    _dstRect = dstrect;
    _srcRect = srcrect;
    SDL_UnlockTexture(_texture);
	SDL_RenderCopy(sdl::Window::getRenderer(), texture, srcrect, dstrect);
	SDL_RenderPresent(sdl::Window::getRenderer());
    _texture = texture;
}