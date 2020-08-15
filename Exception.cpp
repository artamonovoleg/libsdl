//
// Created by kaygalle on 15.08.2020.
//

#include "Exception.hpp"

void sdl::Exception::getError(void)
{
    std::cerr << _msg << std::endl;
};
