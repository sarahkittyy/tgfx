#pragma once

#include "tgfx/color.hpp"
#include "tgfx/primitive/point.hpp"
#include "tgfx/screen.hpp"
#include "tgfx/style.hpp"
#include "tgfx/util/vec2.hpp"

namespace tgfx
{

/**
 * @brief A primitive 1-wide line.
 * 
 * @remarks If the two line vertices are of different colors,
 * the colors inbetween will be interpolated.
 * 
 */
class line : public drawable
{
public:
	/**
	 * @brief Initialize the line
	 * 
	 * @param a The first point
	 * @param b The second point.
	 */
	line(point a, point b);

	/// Set point A
	void set_point_a(point pt);
	/// Get point A
	point get_point_a() const;
	/// Set point B
	void set_point_b(point pt);
	/// Get point B.
	point get_point_b() const;

private:
	/// drawable::draw() override.
	void draw(screen& scr) const;

	point m_a;   /// Point a
	point m_b;   /// Point b
};

}

/**
 * @example primitives/primitives.cpp
 * 
 */