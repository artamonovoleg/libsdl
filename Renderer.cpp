//
// Created by kaygalle on 14.08.2020.
//

#include "Renderer.hpp"
#include "temp.hpp"
#include "Texture.hpp"
#include "Window.hpp"

sdl::Renderer::Renderer(sdl::Window &w)
{
    if ((_renderer = SDL_CreateRenderer(w.get(), -1, SDL_RENDERER_ACCELERATED)) == nullptr)
        throw Exception("Failed to create renderer");
}

sdl::Renderer::~Renderer(void)
{
    if (_renderer != nullptr)
        SDL_DestroyRenderer(_renderer);
}

void sdl::Renderer::clearRenderer(void)
{
    SDL_RenderClear(_renderer);
}

void sdl::Renderer::renderCopy(sdl::Texture &texture)
{
    SDL_RenderCopy(_renderer, texture.get(), texture.getSrcRect(), texture.getDstRect());
}

void sdl::Renderer::presentRenderer(void)
{
    SDL_RenderPresent(_renderer);
}

SDL_Renderer *sdl::Renderer::get(void)
{
    return _renderer;
}




