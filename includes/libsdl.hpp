#include "Color.hpp"
#include "EventHandler.hpp"
#include "Font.hpp"
#include "Text.hpp"
#include "Vector.hpp"
#include "Window.hpp"

namespace sdl
{
    static void Init()
    {
        sdl::EventHandler::Init();
    }
}