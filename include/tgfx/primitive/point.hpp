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

	/// Set the position of the point
	void set_position(vec2u pos);
	/// Get the point's position.
	vec2u get_position() const;
	/// Set the point's color
	void set_color(color col);
	/// Get the point's color.
	color get_color() const;

private:
	/// drawable::draw() override.
	virtual void draw(screen& scr) const;

	/// The point position
	vec2u m_pos;
	/// The point color.
	color m_col;
};

}

/**
 * @brief Demonstration of primitives and custom drawables.
 * 
 * @example primitives/primitives.cpp
 * 
 */