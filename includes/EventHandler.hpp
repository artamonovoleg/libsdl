#pragma once

#include <SDL2/SDL.h>

namespace sdl
{
    class EventHandler
    {
        private:
            static Uint8* _keys;
            static Uint8* _mouse_buttons;
            
            static SDL_Event _event;

            enum State
            {
                None,
                Pressed,
                Held,
                Released,
            };

            static bool scrollUp;
            static bool scrollDown;

        public:
            static bool isClosed;
            static void initialize();
            static void update();
            static bool inputGetKey(SDL_Scancode scancode);
            static bool inputGetKeyDown(SDL_Scancode scancode);
            static bool inputGetKeyUp(SDL_Scancode scancode);
            static void getMousePosition(int &x, int &y);
            static bool isScrollingUp();
            static bool isScrollingDown();
            static bool inputGetButton(int button);
            static bool inputGetButtonDown(int button);
            static bool inputGetButtonUp(int button);
    };
}