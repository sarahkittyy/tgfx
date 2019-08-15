#include "tgfx/color.hpp"

namespace tgfx
{

color::color(uint8_t r, uint8_t g, uint8_t b)
	: r(r), g(g), b(b)
{
}

uint32_t color::to_integer() const
{
	uint32_t r = r;
	uint32_t g = g;
	uint32_t b = b;
	uint32_t a = 0xFF;

	return r << 24 | g << 16 | b << 8 | a;
}

void color::from_integer(uint32_t integer)
{
	r = (integer & 0xFF000000) >> 24;
	g = (integer & 0x00FF0000) >> 16;
	b = (integer & 0x0000FF00) >> 8;
}

std::string color::to_hex_color() const
{
	std::stringstream ss;
	ss << "#" << std::hex << (to_integer() >> 8);
	return ss.str();
}

}