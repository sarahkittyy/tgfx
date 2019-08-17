#include <sys/ioctl.h>
#include <unistd.h>
#include "tgfx/drawable.hpp"
#include "tgfx/screen.hpp"

namespace tgfx
{

screen::pixel::pixel(char ch, style fmt)
	: ch(ch), fmt(fmt)
{
}

screen::screen()
{
}

std::string screen::flush()
{
	// Output stringstream.
	std::ostringstream out;
	// Iterate over all pixels, left-right, top-down.
	for (uint32_t x = 0; x < size().x; ++x)
	{
		for (uint32_t y = 0; y < size().y; ++y)
		{
			// Get and output the pixel.
			const pixel& p = get_pixel(vec2u(x, y));
			out << p.fmt << p.ch;
		}
		out << "\n";
	}

	// Finally, clear the screen map.
	m_screen.clear();
	// Stringify and return the output.
	return out.str();
}

void screen::draw(const drawable& drawable)
{
	drawable.draw(*this);
}

void screen::set_pixel(vec2u pos, const screen::pixel& pixel)
{
	m_screen[pos] = pixel;
}

screen::pixel& screen::get_pixel(vec2u pos)
{
	return m_screen[pos];
}

vec2u screen::size() const
{
	winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	return vec2u(ws.ws_col, ws.ws_row);
}

}