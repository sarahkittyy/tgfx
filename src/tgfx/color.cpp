#include "tgfx/color.hpp"
#include "tgfx/internal/ansi-color.hpp"

namespace tgfx
{

color::color()
	: r(0), g(0), b(0)
{
}

color::color(uint8_t r, uint8_t g, uint8_t b)
	: r(r), g(g), b(b)
{
}

color::color(uint32_t integer)
{
	r = (integer & 0xFF000000) >> 24;
	g = (integer & 0x00FF0000) >> 16;
	b = (integer & 0x0000FF00) >> 8;
}

uint32_t color::to_integer() const
{
	uint32_t r32 = r;
	uint32_t g32 = g;
	uint32_t b32 = b;
	uint32_t a32 = 0xFF;

	return (r32 << 24) | (g32 << 16) | (b32 << 8) | (a32 << 0);
}

std::string color::to_hex_color() const
{
	std::stringstream ss;
	ss << "#" << std::hex << std::left << std::setfill('0') << std::setw(6) << (to_integer() >> 8);
	return ss.str();
}

std::string color::to_ansi_escape(bool foreground) const
{
	return internal::get_color_escape_code(*this, foreground);
}

bool color::operator==(const color& other) const
{
	return r == other.r && g == other.g && b == other.b;
}

bool color::operator!=(const color& other) const
{
	return !operator==(other);
}

}