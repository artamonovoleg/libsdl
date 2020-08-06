#include "Draw.hpp"

float sdl::Draw::lerp( float a, float b, float t )
{
    return ( a + t * ( b - a ) );
}

float sdl::Draw::r_lerp( float a, float b, float t)
{   
    return ( ( t - a ) / ( b - a ) );
}

Uint32 sdl::Draw::mixColor( Uint32 color1, Uint32 color2, int percent )
{
    vec3i rgb1;
    vec3i rgb2;
    vec3i retColor;
    Uint32 ret;

    rgb1.x = color1 >> 16;
    rgb1.y = ( color1 >> 8 ) & 0xff;
    rgb1.z = color1 & 0xff;

    rgb2.x = color2 >> 16;
    rgb2.y = ( color2 >> 8 ) & 0xff;
    rgb2.z = color2 & 0xff;

    retColor.x = (int)((1 - percent) * rgb1.x + percent * rgb2.x);
    retColor.y = (int)((1 - percent) * rgb1.y + percent * rgb2.y);
    retColor.z = (int)((1 - percent) * rgb1.z + percent * rgb2.z);
    ret = ( retColor.x << 16 | retColor.y << 8 | retColor.z );
    
    return ret;
}

void sdl::Draw::drawPoint( point p )
{
    if (p.pos.x >= 0 && p.pos.x < sdl::Surface::getWidth() && p.pos.y >= 0 && p.pos.y < sdl::Surface::getHeight())
        *(((Uint32 *)sdl::Surface::getSurface() -> pixels) + (int(p.pos.x) + int(p.pos.y)* sdl::Surface::getSurface() -> w)) = p.color;
}

void sdl::Draw::drawLine( point p0, point p1 )
{
    int x,y,xe,ye;
    int x1 = p0.pos.x;
    int x2 = p1.pos.x;
    int y1 = p0.pos.y;
    int y2 = p1.pos.y;
    point p;
    int dx = x2 - x1;
    int dy = y2 - y1;
    int dx1 = fabs(dx);
    int dy1 = fabs(dy);
    int px = 2 * dy1 - dx1;
    int py = 2 * dx1 - dy1;
    if (dy1 <= dx1)
    {
        if (dx >= 0)
        {
            x=x1;
            y=y1;
            xe=x2;
        }
        else
        {
            x=x2;
            y=y2;
            xe=x1;
        }
        p.pos.x = x;
        p.pos.y = y;
        p.color = mixColor(p0.color, p1.color, lerp(p0.pos.x, p1.pos.x, p.pos.x) );
        drawPoint(p);
        for (int i = 0; x < xe; i++)
        {
            x++;
            if( px < 0 )
                px = px + 2 * dy1;
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    y++;
                else
                    y--;
                px = px + 2 * (dy1 - dx1);
            }
            
            p.pos.x = x;
            p.pos.y = y;
            // p.color = p1.color;
            p.color = mixColor(p0.color, p1.color, lerp(p0.pos.x, p1.pos.x, p.pos.x) );
            drawPoint(p);
        }
    }
    else
    {
        if (dy >= 0)
        {
            x = x1;
            y = y1;
            ye = y2;
        }
        else
        {
            x = x2;
            y = y2;
            ye = y1;
        }
        p.pos.x = x;
        p.pos.y = y;
        // p.color = p1.color;
        p.color = mixColor(p0.color, p1.color, lerp(p0.pos.x, p1.pos.x, p.pos.x) );
        drawPoint(p);
        for (int i = 0; y < ye; i++)
        {
            y++;
            if ( py <= 0 )
                py = py + 2 * dx1;
            else
            {
                if ((dx < 0 && dy < 0) || (dx > 0 && dy > 0))
                    x++;
                else
                    x--;
                py = py + 2 * (dx1 - dy1);
            }
            p.pos.x = x;
            p.pos.y = y;
            // p.color = p1.color;
            p.color = mixColor(p0.color, p1.color, lerp(p0.pos.x, p1.pos.x, p.pos.x) );
            drawPoint(p);
        }
    }
}
