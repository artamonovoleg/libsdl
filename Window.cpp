#include <iostream>

#include "Window.hpp"

bool sdl::Window::isCreated = false;
SDL_Window * sdl::Window::_window = nullptr;
SDL_Renderer * sdl::Window::_renderer = nullptr;

int sdl::Window::_width = 0;
int sdl::Window::_height = 0;

Uint32 sdl::Window::_bgcolor = 0xFFFFFF;

void sdl::Window::initWindow( int width, int height )
{
    if (isCreated == false)
    {
        _width = width;
        _height = height;

        _window = SDL_CreateWindow( "SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _width, _height, SDL_WINDOW_SHOWN );
        _renderer = SDL_CreateRenderer( _window, -1, SDL_RENDERER_ACCELERATED );
        sdl::Texture::setTexture( sdl::Texture::createTexture( width, height ) );
        sdl::Surface::setSurface( sdl::Surface::createSurface( width, height ) );
        isCreated = true;
    }
    else
    {
        std::cerr << "YOU CAN CREATE ONLY ONE WINDOW. PROGRAM STOPPED" << std::endl;
        exit(-1);
    }
    
}

void sdl::Window::Update( void )
{
    SDL_UpdateTexture(sdl::Texture::getTexture(), NULL, sdl::Surface::getSurface() -> pixels, sdl::Surface::getSurface() -> pitch);
    SDL_RenderCopy(_renderer, sdl::Texture::getTexture(), NULL, NULL);
    SDL_RenderPresent(_renderer);

    // Surface clear
    SDL_FillRect(sdl::Surface::getSurface(), NULL, _bgcolor);
    // Input
    sdl::Events::handleInput();
}