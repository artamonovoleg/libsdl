//
// Created by kaygalle on 14.08.2020.
//

#ifndef SDL_TEMP_HPP
#define SDL_TEMP_HPP

#include "Vectors.hpp"
#include "Events.hpp"
#include "Renderer.hpp"
#include <iostream>
struct point
{
    vec3i pos;
    Uint32 color;
};

namespace sdl
{
    class Exception : std::exception
    {
        private:
            std::string _msg;
        public:
            explicit Exception(std::string msg) : _msg(std::move(msg)) {};

            void getError(void)
            {
                std::cerr << _msg << std::endl;
            };
    };
}

#endif //SDL_TEMP_HPP
