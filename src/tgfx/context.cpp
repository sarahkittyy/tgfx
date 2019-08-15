#include "tgfx/context.hpp"

namespace tgfx
{

context::context()
	: m_open(true)
{
	// Clear the screen on context creation
	clear();
}

context::~context()
{
	// Clear the screen when the context is destroyed.
	clear();
}

const bool context::open() const
{
	return m_open;
}

void context::close()
{
	m_open = false;
}

void context::clear()
{
	m_screen.flush();
}

void context::draw(const drawable& draw)
{
	m_screen.draw(draw);
}

void context::render(unsigned int framerate)
{
	// For only rendering with the given framerate.
	if (m_clock.elapsed() >= time::seconds(1.f / (float)framerate))
	{
		m_clock.restart();
		std::string screen_content = m_screen.flush();
		std::cout << "\033[H\033[J";
	}
}

const vec2u context::size() const
{
	winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	return vec2u(ws.ws_col, ws.ws_row);
}

}