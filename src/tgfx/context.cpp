#include <chrono>
#include <thread>
#include "tgfx/context.hpp"

namespace tgfx
{

context::context()
	: m_open(true),
	  m_framerate(15)
{
	// Clear the screen on context creation
	clear();
}

context::~context()
{
}

void context::set_framerate(float framerate)
{
	m_framerate = framerate;
}

float context::get_framerate() const
{
	return m_framerate;
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

void context::render()
{
	// If we're not passed the necessary amount of time to wait between frames,
	// sleep for the remaining time.
	if (m_clock.elapsed() <= time::seconds(1.f / m_framerate))
	{
		time left = time::seconds(1.f / m_framerate) - m_clock.elapsed();
		std::this_thread::sleep_for(std::chrono::duration<double>(left.as_seconds()));
		m_clock.restart();
	}
	//* Begin rendering here
	//std::string screen_content = "\033[H\033[J";
	std::string screen_content = m_screen.flush();
	// Output the screen content.
	std::cout << screen_content;
}

vec2u context::size() const
{
	return m_screen.size();
}

}