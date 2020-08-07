# libsdl
[![C/C++ CI](https://github.com/artamonovoleg/libsdl/workflows/C/C++%20CI/badge.svg?branch=master)](https://github.com/artamonovoleg/libsdl/actions)
## Usage:


```cpp
#include "libsdl.hpp"
int main()
{
    sdl::Window::initWindow( 1920, 1080 );
    while ( !sdl::Events::InputGetKey(SDLK_ESCAPE))
    {
        sdl::Window::Update(); // Handle input , update surface
    }
}
```
