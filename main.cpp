#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Vectors.hpp"
#include "Events.hpp"

class Exception
{
    private:
        std::string _msg;
    public:
        Exception(std::string msg) : _msg(msg) {};
        void getError(void)
        {
            std::cerr << _msg << std::endl;
        };
};

class Window
{
    private:
        SDL_Window *_window; // Manage SDL object
    public:
        Window (int width, int height)
        {
            if ((_window = SDL_CreateWindow("SDL Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_ALLOW_HIGHDPI)) == nullptr)
                throw Exception("Failed to create window");
        };

        ~Window(void)
        {
            if (_window != nullptr)
                SDL_DestroyWindow(_window);
        };

        SDL_Window *get(void)
        {
            return _window;
        }

        int getWidth(void)
        {
            int width;
            SDL_GetWindowSize(_window, &width, nullptr);
            return width;
        };

        int getHeight(void)
        {
            int height;
            SDL_GetWindowSize(_window, nullptr, &height);
            return height;
        };
};

class Renderer
{
    private:
        SDL_Renderer *_renderer; // Manage SDL object
    public:

        Renderer(Window &w)
        {
            if ((_renderer = SDL_CreateRenderer(w.get(), -1, SDL_RENDERER_ACCELERATED)) == nullptr)
                throw Exception("Failed to create renderer");
        };

        ~Renderer(void)
        {
            if(_renderer != nullptr)
                SDL_DestroyRenderer(_renderer);
        }

        SDL_Renderer *get(void)
        {
            return _renderer;
        }


};

class Surface
{
    private:
        SDL_Surface *_surface;
    public:
        Surface(int width, int height)
        {
            Uint32 rmask, gmask, bmask, amask;

            rmask = 0x000000ff;
            gmask = 0x0000ff00;
            bmask = 0x00ff0000;
            amask = 0xff000000;
            if((_surface = SDL_CreateRGBSurface(0, width, height, 32, rmask, gmask, bmask, amask)) == nullptr)
                throw Exception("SDL_CreateRGBSurface");
        }

        Surface(SDL_Surface *surface)
        {
            if((_surface = surface) == nullptr)
                throw Exception("Null surface");
        }

        ~Surface(void)
        {
            if (_surface != nullptr)
                SDL_FreeSurface(_surface);
        }

        SDL_Surface *get(void)
        {
            return _surface;
        }

};

class Texture
{

};


int main(void)
{
    int width = 500;
    int height = 500;

    try
    {
        Window window(width, height);

        Renderer renderer(window);

        // Font part
        TTF_Init();

        TTF_Font *verdanaFont = TTF_OpenFont("./19554.ttf", 24);
        SDL_Color textColor = {0, 255, 0, 255};
        SDL_Surface *txt = TTF_RenderText_Solid(verdanaFont, "Hello World", textColor);
        Surface textSurface(txt);

        TTF_Quit();
        SDL_Rect textRect;
        textRect.x = 100;
        textRect.y = 100;
        textRect.w = textSurface.get()->w;
        textRect.h = textSurface.get()->h;
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer.get(), textSurface.get());
        //

        // Draw part
        Surface drawSurface(width, height);
        SDL_Texture *drawTexture = SDL_CreateTexture(renderer.get(), SDL_PIXELFORMAT_ARGB8888,
                                                     SDL_TEXTUREACCESS_STREAMING,
                                                     width, height);
        //

        while (!sdl::Events::InputGetKey(SDLK_ESCAPE))
        {
            SDL_FillRect(drawSurface.get(), nullptr, 0x000000);
            SDL_FillRect(textSurface.get(), &textRect, 0x000000);

            *(((Uint32 *) drawSurface.get()->pixels) +
              (int(width / 2) + int(height / 2) * drawSurface.get()->w)) = 0xffff00;

            SDL_UpdateTexture(drawTexture, nullptr, drawSurface.get()->pixels, drawSurface.get()->pitch);
            SDL_UpdateTexture(textTexture, &textRect, textSurface.get()->pixels, textSurface.get()->pitch);


            SDL_RenderCopy(renderer.get(), drawTexture, nullptr, nullptr);
            SDL_RenderCopy(renderer.get(), textTexture, nullptr, &textRect);

            SDL_RenderPresent(renderer.get());

            sdl::Events::handleInput();
        }
    }
    catch (Exception &exception)
    {
        exception.getError();
    }
}
