cmake_minimum_required(VERSION 3.17)
project(sdl)

set(CMAKE_CXX_STANDARD 14)

add_executable(sdl main.cpp Events.cpp)
target_link_libraries(sdl SDL2 SDL2_ttf)