#ifndef WINDOW_HPP
#define WINDOW_HPP
#include "libsdl.hpp"

namespace sdl
{
    class Window
    {
        public:
            static void initWindow( int width, int height );
            static void Update( void );
            
            // Setters
            static void setBgColor( Uint32 color );
            // Getters
            static SDL_Window * getWindow( void ) { return _window; };
            static SDL_Renderer * getRenderer( void ) { return _renderer; };
            static int getWidth( void ) { return _width; };
            static int getHeight( void ) { return _height; };

        private:
            Window() = default;

            // SDL values
            static SDL_Window * _window;
            static SDL_Renderer * _renderer;
            // Allow only one instance
            static bool isCreated;

            // Window parameters
            static int _width;
            static int _height;
            static Uint32 _bgcolor;

    };
}

#endif