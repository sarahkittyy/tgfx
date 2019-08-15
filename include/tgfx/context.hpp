#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
#include <chrono>
#include <iostream>

#include "tgfx/screen.hpp"
#include "tgfx/util/clock.hpp"
#include "tgfx/util/vec2.hpp"

namespace tgfx
{

class drawable;

/**
 * @brief The main graphical context for tgfx. Attaches to console, used for graphics i/o.
 * 
 */
class context
{
public:
	/// Constructs the context.
	context();
	/// Destroys the context.
	~context();

	/// False after close() is called. Use this as a condition for a rendering loop.
	const bool open() const;
	/// Flags the context to close, making open() return false.
	void close();

	/// Clears the screen buffer..
	void clear();
	/// Draws a drawable to the graphical buffer, to be rendered on render().
	void draw(const drawable& draw);
	/**
	 * @brief Renders all buffered drawables drawn by draw() to the terminal.
	 * 
	 * @param framerate The framerate, in renders / second, to render at.
	 */
	void render(unsigned int framerate = 15);

	/// Returns the width / height of the terminal, in characters.
	const vec2u size() const;

private:
	/// True when initialized, falseified when close() is called. makes open() return false.
	bool m_open;
	/// The main screen to render drawables to.
	screen m_screen;
	/// Clock for timing the render() framerate.
	clock m_clock;
};

}