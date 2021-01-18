#include <iostream>
#include "libsdl.hpp"

int main()
{
    int width = 800;
    int height = 600;
    sdl::Init();
    sdl::Window window("SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);

    sdl::Font font ("../res/Roboto-Regular.ttf", 24);
    sdl::Text text(font, "Hello world! \n New Line", sdl::Color::HexToSdl(0xFFFFFF));
    sdl::Text text1(font, "Hello world!", sdl::Color::HexToSdl(0xFF00FF));
    text.SetPos(250, 0);

    window.SetClearColor(0x505050);


    while (!window.ShouldClose())
    {
        window.Clear();
        window.DrawText(text);
        window.DrawText(text1);
        window.PutPixel(width / 2, height / 2, 0XFFFF00);
        window.DrawLine(0, 0, 0xFF00FF, width, height, 0X00FFFF);
        window.Present();

        if (sdl::EventHandler::InputGetKeyDown(SDL_SCANCODE_A))
            std::cout << "Click A" << std::endl;
        if (sdl::EventHandler::IsScrollingUp())
            std::cout << "Scroll up" << std::endl;
        if (sdl::EventHandler::InputGetButtonUp(SDL_BUTTON_LEFT))
            std::cout << "LKM" << std::endl;
        sdl::EventHandler::Update();
    }
}