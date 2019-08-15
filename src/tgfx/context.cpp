#include "tgfx/context.hpp"

namespace tgfx
{

context::context()
	: mOpen(true)
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

void context::draw(const drawable&)

	void context::clear()
{
	std::cout << "\033[H\033[J";
}

const vec2u context::size() const
{
	winsize ws;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	return vec2u(ws.ws_col, ws.ws_row);
}

}