//
// Created by kaygalle on 15.08.2020.
//

#ifndef SDL_EXCEPTION_HPP
#define SDL_EXCEPTION_HPP

#include <iostream>

namespace sdl
{
    class Exception : std::exception
    {
        private:
            std::string _msg;
        public:
            explicit Exception(std::string msg) : _msg(std::move(msg)) {};

            void getError(void);
    };
}

#endif //SDL_EXCEPTION_HPP
