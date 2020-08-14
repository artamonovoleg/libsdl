//
// Created by kaygalle on 14.08.2020.
//

#include "Texture.hpp"

sdl::Texture::Texture(sdl::Renderer &renderer, int width, int height) : _renderer(renderer), _surface(width, height)
{
    if ((_texture = SDL_CreateTexture(_renderer.get(), SDL_PIXELFORMAT_ARGB8888,
                                      SDL_TEXTUREACCESS_STREAMING, width, height)) == nullptr)
    {
        throw Exception("SDL_CreateTexture");
    }
}

sdl::Texture::Texture(sdl::Renderer &renderer, sdl::Surface &surface) : _renderer(renderer), _surface(surface)
{
    if ((_texture = SDL_CreateTextureFromSurface(_renderer.get(), _surface.get())) == nullptr)
        throw Exception("SDL_CreateTextureFromSurface");
}

sdl::Texture::~Texture(void)
{
    _surface.null();
    if (_texture != nullptr)
        SDL_DestroyTexture(_texture);
}

SDL_Texture *sdl::Texture::get(void) { return _texture; }

sdl::Surface &sdl::Texture::getSurface(void) { return _surface; }

SDL_Rect *sdl::Texture::getSrcRect(void) { return _srcRect; }

SDL_Rect *sdl::Texture::getDstRect(void) { return _dstRect; }

void sdl::Texture::setRects(SDL_Rect *srcRect, SDL_Rect *dstRect)
{
    _srcRect = srcRect;
    _dstRect = dstRect;
}

void sdl::Texture::fillRect(Uint32 color)
{
    SDL_FillRect(_surface.get(), _dstRect, color);
}

void sdl::Texture::updateTexture(void)
{
    SDL_UpdateTexture(_texture, _dstRect, _surface.get()->pixels, _surface.get()->pitch);
}




