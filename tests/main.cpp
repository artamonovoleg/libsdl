#include "Font.hpp"
#include "Text.hpp"
#include "Window.hpp"
#include "Color.hpp"

#include <iostream>

namespace sdl
{
    class EventHandler
    {
        private:
        public:
            enum State
            {
                None,
                Pressed,
                Held,
                Released
            };
            static SDL_Event event;
            static bool isClosed;
            static void initialize();
            static void update();
    };
}

bool sdl::EventHandler::isClosed;
SDL_Event sdl::EventHandler::event;

void sdl::EventHandler::initialize()
{
    isClosed = false;
}

void sdl::EventHandler::update()
{
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                isClosed = true;
            break;
            case SDL_KEYDOWN:
                std::cout << "Down: " << event.key.keysym.scancode << std::endl;
            break;
            case SDL_KEYUP:
                std::cout << "Up: " << event.key.keysym.scancode << std::endl;
            break;
            default:
            break;
        }
    }
}

int main()
{
    int width = 800;
    int height = 600;
    sdl::Window window("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    sdl::Font font ("./res/Roboto-Regular.ttf", 24);
    sdl::Text text(font, "Hello world!", sdl::Color::hex_to_sdl(0xFFFFFF));
    sdl::Text text1(font, "Hello world!", sdl::Color::hex_to_sdl(0xFF00FF));
    text.setPos(250, 0);
    text1.setPos(250, 20);

    window.setBgColor(0x505050);

    sdl::EventHandler::initialize();

    while (!sdl::EventHandler::isClosed)
    {
        window.clear();
        window.drawText(text);
        window.drawText(text1);
        window.drawPoint(Point {vec2i (width / 2, height / 2), 0xFF00FF});
        window.drawLine(Point {vec2i(0, 0), 0xff0000}, Point {vec2i(width, height), 0xFFFF00});
        window.present();

        sdl::EventHandler::update();
    }
}