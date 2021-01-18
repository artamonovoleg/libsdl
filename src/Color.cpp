#include "Color.hpp"

int sdl::Color::Lerp(int start, int end, float percentage)
{
    return ((int)((1 - percentage) * start + percentage * end));
}

float sdl::Color::Percent(int start, int end, float current)
{
    float placement;
	float distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

Uint32 sdl::Color::MixColor(Uint32 c1, Uint32 c2, float percent)
{
    int r;
	int g;
	int b;

	if (c1 == c2)
		return (c1);
	r = Lerp((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, percent);
	g = Lerp((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, percent);
	b = Lerp(c1 & 0xFF, c2 & 0xFF, percent);
	return (r << 16 | g << 8 | b);
}

SDL_Color sdl::Color::HexToSdl(Uint32 color)
{
    SDL_Color ret;
    ret.r = (color >> 16) & 0xFF;
    ret.g = (color >> 8) & 0XFF;
    ret.b = (color) & 0xFF;
    return ret;
}