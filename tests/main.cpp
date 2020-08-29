#include "Font.hpp"
#include "Text.hpp"
#include "Window.hpp"
#include "Color.hpp"

int main()
{
    int width = 800;
    int height = 600;
    sdl::Window window("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
    bool isClosed = false;

    SDL_Event event;
    
    sdl::Font font ("./res/Roboto-Regular.ttf", 24);
    sdl::Text text(font, "Hello world!", sdl::Color::hex_to_sdl(0xFFFFFF));
    text.setPos(250, 0);

    while (!isClosed)
    {
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    isClosed = true;
                break;
                default:
                    break;
            }
        }
        window.clear();
        window.drawText(text);
        window.drawPoint(Point {vec2i (width / 2, height / 2), 0xff00ff});
        window.drawLine(Point {vec2i(0, 0), 0xff0000}, Point {vec2i(width, height), 0xffff00});
        window.present();
    }
}