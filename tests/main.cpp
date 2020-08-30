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
            static SDL_Event event;
            static bool isClosed;
            static Uint8 *_keys;
            static void initialize();
            static void update();

            static bool inputGetKeyDown(SDL_Scancode scancode);
    };
}

bool sdl::EventHandler::isClosed;
SDL_Event sdl::EventHandler::event;
Uint8 *sdl::EventHandler::_keys = new Uint8 [256];

void sdl::EventHandler::initialize()
{
    isClosed = false;
    for (int i = 0; i < 256; i++)
    {
        _keys[i] = 0;
    }
}

void sdl::EventHandler::update()
{
    // SDL_PumpEvents();

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_QUIT:
                isClosed = true;
            break;
            case SDL_KEYDOWN:
                if ((int) event.key.repeat == 0)
                {
                    std::cout << (int) event.key.repeat << event.key.keysym.scancode << std::endl;
                    _keys[event.key.keysym.scancode] = 1;
                }
                else
                {
                    _keys[event.key.keysym.scancode] = 0;
                }
                
            break;
            case SDL_KEYUP:
                _keys[event.key.keysym.scancode] = 0;
            break;
            default:
            break;
        }
    }
}

bool sdl::EventHandler::inputGetKeyDown(SDL_Scancode scancode)
{
    return (_keys[scancode] == 1);
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