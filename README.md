# libsdl

Example of usage

#include "libsdl.hpp"

int main()
{
    sdl::Window::initWindow( 1920, 1080 );
    while ( !sdl::Events::InputGetKey(SDLK_ESCAPE))
    {
        sdl::Window::Update();
    }
}
