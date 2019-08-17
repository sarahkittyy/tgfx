#pragma once

#include "tgfx/color.hpp"
#include "tgfx/drawable.hpp"
#include "tgfx/screen.hpp"
#include "tgfx/style.hpp"
#include "tgfx/util/vec2.hpp"

namespace tgfx
{

/**
 * @brief A basic point primitive. Renders a single point onto the terminal.
 * 
 */
class point : public drawable
{
public:
	/**
	 * @brief Init the point
	 * 
	 * @param pos The point's position
	 * @param col The point's color.
	 */
	point(vec2u pos, color col = color(0, 0, 0));

private:
	/// drawable::draw() override.
	virtual void draw(screen& scr) const;

	/// The point position
	vec2u m_pos;
	/// The point color.
	color m_col;
};

}