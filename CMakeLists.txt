cmake_minimum_required(VERSION 3.17)
project(sdl)

set(CMAKE_CXX_STANDARD 14)

add_executable(sdl main.cpp Events.cpp Renderer.cpp Renderer.hpp Window.hpp Texture.hpp Surface.hpp Texture.cpp Surface.cpp Window.cpp Exception.cpp Exception.hpp Point.hpp libsdl.hpp Rect.cpp Rect.hpp Font.cpp Font.hpp)
target_link_libraries(sdl SDL2 SDL2_ttf)