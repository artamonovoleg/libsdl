#ifndef DRAW_HPP
#define DRAW_HPP

#include "mysdl.hpp"

struct point
{
    vec3f pos;
    Uint32 color;
};

namespace sdl
{
    class Draw
    {
        private:

        public:
            static void drawPoint( point p );
            static void drawLine( point p1, point p2 );
    };
};

#endif