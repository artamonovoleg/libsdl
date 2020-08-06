#ifndef DRAW_HPP
#define DRAW_HPP

#include "libsdl.hpp"

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
            static float lerp( float a, float b , float t);
            static float r_lerp( float a, float b , float t);
            static Uint32 mixColor( Uint32 color1, Uint32 color2, int percent );

            static void drawPoint( point p );
            static void drawLine( point p1, point p2 );
    };
};

#endif