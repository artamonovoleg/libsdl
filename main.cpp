#include <iostream>
#include <utility>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Vectors.hpp"
#include "Events.hpp"
#include "temp.hpp"
#include "Renderer.hpp"
#include "Window.hpp"
#include "Surface.hpp"
#include "Texture.hpp"

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

        TTF_Font *verdanaFont = TTF_OpenFont("./19554.ttf", 24);
        SDL_Color textColor = {0, 255, 0, 255};
        SDL_Surface *txt = TTF_RenderText_Solid(verdanaFont, "Hello World", textColor);
        sdl::Surface textSurface(txt);

        TTF_Quit();
        SDL_Rect textRect;
        textRect.x = 100;
        textRect.y = 100;
        textRect.w = textSurface.get()->w;
        textRect.h = textSurface.get()->h;
        sdl::Texture textTexture(renderer, textSurface);

        //Draw part
        sdl::Texture drawTexture(renderer, width, height);
        //
//        SDL_Surface
        textTexture.setRects(nullptr, &textRect);
        int x = 250;
        int y = 250;
        while (!sdl::Events::InputGetKey(SDLK_ESCAPE))
        {
            renderer.clearRenderer();
            textTexture.getSurface().get();
            drawTexture.fillRect(0x000000);
            textTexture.fillRect(0x000000);

            *(((Uint32 *)drawTexture.getSurface().get()->pixels) + (int(x) + int(y) * drawTexture.getSurface().get()->w)) = 0xff0000;

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
