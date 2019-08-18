#pragma once

#include "tgfx/screen.hpp"

namespace tgfx
{

/**
 * @brief Inheritable drawable class. Passed to tgfx::context for rendering to the screen.
 * 
 */
class drawable
{
public:
	/// Virtual DTor for inheritance
	virtual ~drawable();

protected:
	/// Called by the context in context.draw(). Inherit to define rendering to the screen.
	virtual void draw(screen& scr) const = 0;

	// For context to call this->draw()
	friend class screen;
};

}

/**
 * @brief Demonstration of primitives and custom drawables.
 * 
 * @image html examples/screenshots/primitives.cpp.png
 * 
 * @example primitives/primitives.cpp
 * 
 */