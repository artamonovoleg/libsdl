#pragma once

#include <SDL2/SDL.h>

namespace sdl
{
    class Window;
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
            static bool isClosed;
            friend class Window;
        public:
            static void Init();
            static void Update();
            static bool InputGetKey(SDL_Scancode scancode);
            static bool InputGetKeyDown(SDL_Scancode scancode);
            static bool InputGetKeyUp(SDL_Scancode scancode);
            static void GetMousePosition(int &x, int &y);
            static bool IsScrollingUp();
            static bool IsScrollingDown();
            static bool InputGetButton(int button);
            static bool InputGetButtonDown(int button);
            static bool InputGetButtonUp(int button);
    };
}