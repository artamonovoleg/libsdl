#include "libsdl.hpp"

namespace sdl
{
    void drawPoint(sdl::Surface &surface, point p)
    {
        *(((Uint32 *) surface.get()->pixels) + (int(p.pos.x) + int(p.pos.y) * surface.get()->w)) = p.color;
    }

    void drawLine(sdl::Surface &surface, point p0, point p1)
    {
        int x, y, xe, ye;
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
                x = x1;
                y = y1;
                xe = x2;
            } else
            {
                x = x2;
                y = y2;
                xe = x1;
            }
            p.pos.x = x;
            p.pos.y = y;
            p.color = p0.color;
//            p.color = mixColor(p0.color, p1.color, lerp(p0.pos.x, p1.pos.x, p.pos.x) );
            drawPoint(surface, p);
            for (int i = 0; x < xe; i++)
            {
                x++;
                if (px < 0)
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
                p.color = p0.color;
//                p.color = mixColor(p0.color, p1.color, lerp(p0.pos.x, p1.pos.x, p.pos.x) );
                drawPoint(surface, p);
            }
        } else
        {
            if (dy >= 0)
            {
                x = x1;
                y = y1;
                ye = y2;
            } else
            {
                x = x2;
                y = y2;
                ye = y1;
            }
            p.pos.x = x;
            p.pos.y = y;
            p.color = p0.color;
//            p.color = mixColor(p0.color, p1.color, lerp(p0.pos.x, p1.pos.x, p.pos.x) );
            drawPoint(surface, p);
            for (int i = 0; y < ye; i++)
            {
                y++;
                if (py <= 0)
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
                p.color = p0.color;
//                p.color = mixColor(p0.color, p1.color, lerp(p0.pos.x, p1.pos.x, p.pos.x) );
                drawPoint(surface, p);
            }
        }
    }

    class Rect
    {
        private:
            SDL_Rect _rect;
        public:
            Rect(int x, int y, int w, int h)
            {
                _rect.x = x;
                _rect.y = y;
                _rect.w = w;
                _rect.h = h;
            };
            ~Rect() = default;

            SDL_Rect *get(void) { return &_rect; };

    };

    class Font
    {
        private:
            TTF_Font *_font;
        public:
            Font(const char *file, int ptsize)
            {
                if((_font = TTF_OpenFont(file, ptsize)) == nullptr)
                    throw Exception("Failed to read font");
            };
            ~Font(void)
            {
                if(_font != nullptr)
                    delete _font;
            }

            TTF_Font *get(void) { return _font; };

    };

}

int main(void)
{
    int width = 500;
    int height = 500;

    try
    {
        sdl::Window window(width, height);
        sdl::Renderer renderer(window);

        // Font part
        TTF_Init();

        sdl::Font font("./19554.ttf", 24);
        SDL_Color textColor = {0, 255, 0, 255};
        sdl::Surface textSurface(TTF_RenderText_Solid(font.get(), "Hello World", textColor));
        TTF_Quit();

        sdl::Rect textRect(100, 100, textSurface.get()->w, textSurface.get()->h);
        sdl::Texture textTexture(renderer, textSurface);
        textTexture.setRects(nullptr, textRect.get());
        //

        //Draw part
        sdl::Texture drawTexture(renderer, width, height);


        point p;
        p.pos = {260, 260, 0};
        p.color = 0x00ffff;
        point p1;
        p1.pos = {width, height, 0};
        p1.color = 0x00ffff;
        //
        while (!sdl::Events::InputGetKey(SDLK_ESCAPE))
        {
            renderer.clearRenderer();
            drawTexture.fillRect(0x000000);

            sdl::drawPoint(drawTexture.getSurface(), p);
            sdl::drawLine(drawTexture.getSurface(), p, p1);

            drawTexture.updateTexture();
            textTexture.updateTexture();
            renderer.renderCopy(drawTexture);
            renderer.renderCopy(textTexture);

            renderer.presentRenderer();

            sdl::Events::handleInput();
        }
    }
    catch (sdl::Exception &exception)
    {
        exception.getError();
    }
}
