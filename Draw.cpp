#include "Draw.hpp"

void sdl::Draw::drawPoint( point p )
{
    if (p.pos.x >= 0 && p.pos.x <= sdl::Surface::getWidth() && p.pos.y >= 0 && p.pos.y <= sdl::Surface::getHeight())
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
        p.color = p1.color;
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
            p.color = p1.color;
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
        p.color = p1.color;
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
            p.color = p1.color;
            drawPoint(p);
        }
    }
}