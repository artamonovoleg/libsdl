#include "Font.hpp"
#include "Text.hpp"
#include "Window.hpp"
#include "Color.hpp"
#include "EventHandler.hpp"

#include <iostream>

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

    // WORK ON EVENT
        sdl::EventHandler::initialize();
    //

    while (!sdl::EventHandler::isClosed)
    {
        window.clear();
        window.drawText(text);
        window.drawText(text1);
        window.putPixel(width / 2, height / 2, 0XFFFF00);
        window.drawLine(0, 0, 0xFF00FF, width, height, 0X00FFFF);
        window.present();

        // EVENT
        if (sdl::EventHandler::inputGetKeyDown(SDL_SCANCODE_A))
            std::cout << "Click A" << std::endl;
        if (sdl::EventHandler::isScrollingUp())
            std::cout << "Scroll up" << std::endl;
        if (sdl::EventHandler::inputGetButtonUp(SDL_BUTTON_LEFT))
            std::cout << "LKM" << std::endl;
        sdl::EventHandler::update();
    }
}