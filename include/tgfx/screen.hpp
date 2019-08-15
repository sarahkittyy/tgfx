#pragma once

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
	/// Init the screen.
	screen();

	/// Flushes the screen to a printable string.
	std::string flush();

	/// Draws a drawable object to the screen.
	void draw(const drawable& drawable);

private:
};

}