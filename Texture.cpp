#include "Texture.hpp"

SDL_Texture * sdl::Texture::_texture = nullptr;

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
    _texture = texture;
    SDL_UnlockTexture(_texture);
	SDL_RenderCopy(sdl::Window::getRenderer(), texture, NULL, NULL);
	SDL_RenderPresent(sdl::Window::getRenderer());
}