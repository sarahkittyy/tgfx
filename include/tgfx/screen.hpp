#pragma once

#include <unordered_map>

#include "tgfx/style.hpp"
#include "tgfx/util/vec2.hpp"

namespace tgfx
{

class drawable;

/**
 * @brief Controls how drawable objects translate to pixels on the screen.
 * 
 */
class screen
{
public:
	/// A single screen pixel.
	struct pixel
	{
		/// Constructor, with default settings.
		pixel(char ch = ' ', style fmt = style().reset_on());
		char ch;	 /// The char rendered to that pixel.
		style fmt;   /// The styling applied to that pixel.
	};

	/// Init the screen.
	screen();

	/// Flushes the screen to a printable string.
	std::string flush();

	/// Draws a drawable object to the screen.
	void draw(const drawable& drawable);

	/// Set a pixel on the screen.
	void set_pixel(vec2u pos, const pixel& pixel);

	/// Get the pixel at the given position.
	pixel& get_pixel(vec2u pos);

	/// Get the size of the output terminal.
	vec2u size() const;

private:
	/// Mapping of pixels to x/y positions.
	std::unordered_map<vec2u, pixel, vec2u::hasher> m_screen;
};

}