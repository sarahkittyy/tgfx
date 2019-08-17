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
	// Move cursor to 0,0
	out << "\u001b[0,0H";
	// Iterate over all pixels, left-right, top-down.
	for (uint32_t y = 0; y < size().y; ++y)
	{
		for (uint32_t x = 0; x < size().x; ++x)
		{
			// Get the previous position
			int stream_pos = x + y * size().x;
			stream_pos--;
			int last_x = stream_pos % size().x;
			int last_y = stream_pos / size().x;
			// Get the current pixel.
			const pixel& p = get_pixel(vec2u(x, y));

			// Only change the ansi escape code if it's different than the
			// previous one.
			if (get_pixel(vec2u(last_x, last_y)).fmt != p.fmt)
				out << p.fmt;

			// Output the character.
			out << p.ch;
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