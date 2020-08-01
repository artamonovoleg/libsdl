#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "mysdl.hpp"

namespace sdl
{
    class Texture
    {
        private:
            Texture() = default;
            static SDL_Texture * _texture;
        public:
            // Default texture creator. Take window size as parameters
            static SDL_Texture * createTexture ( void );
            // Own sizes for texture
            static SDL_Texture * createTexture ( int width, int height );
            // Set current texture
            static void setTexture( SDL_Texture * texture );
            // Getter
            static SDL_Texture * getTexture( void ) { return _texture; };
    };
}

#endif