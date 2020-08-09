#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include "libsdl.hpp"

namespace sdl
{
    class Texture
    {
        private:
            Texture(){};
            static SDL_Texture * _texture;
            static SDL_Rect * _srcRect;
            static SDL_Rect * _dstRect;
        public:
            // Default texture creator. Take window size as parameters
            static SDL_Texture * createTexture ( void );
            // Own sizes for texture
            static SDL_Texture * createTexture ( int width, int height );
            // Set current texture
            static void setTexture( SDL_Texture * texture );
            static void setTexture( SDL_Texture * texture, SDL_Rect * srcrect, SDL_Rect * dstrect );
            // Getters
            static SDL_Texture * getTexture( void ) { return _texture; };
            static SDL_Rect * getSrcRect( void ) { return _srcRect; };
            static SDL_Rect * getDstRect( void ) { return _dstRect; };
    };
}

#endif