#pragma once

#include <sys/ioctl.h>
#include <unistd.h>
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

	/// Set the context framerate.
	void set_framerate(unsigned int framerate);
	/// Get the context framerate.
	unsigned int get_framerate() const;

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
	 * @remarks Causes the current rendering thread to sleep not enough time has passed based on the framerate.
	 */
	void render();

	/// Returns the width / height of the terminal, in characters.
	const vec2u size() const;

private:
	/// True when initialized, falseified when close() is called. makes open() return false.
	bool m_open;
	/// The main screen to render drawables to.
	screen m_screen;
	/// Clock for timing the render() framerate.
	clock m_clock;
	/// The framerate to run at, in frames / second..
	unsigned int m_framerate;
};

}