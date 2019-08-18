#include "tgfx/primitive/line.hpp"

namespace tgfx
{

line::line(point a, point b)
	: m_a(a), m_b(b)
{
}

void line::set_point_a(point pt)
{
	m_a = pt;
}

point line::get_point_a() const
{
	return m_a;
}

void line::set_point_b(point pt)
{
	m_b = pt;
}

point line::get_point_b() const
{
	return m_b;
}

void line::draw(screen& scr) const
{
	// Interpolate from m_a to m_b
	for (float t = 0; t < 1; t += 0.01f)
	{
		vec2f p1 = m_a.get_position();
		vec2f p2 = m_b.get_position();
		// Interpolated position.
		vec2u pos = ((p2 - p1) * t) + p1;

		color c1 = m_a.get_color();
		color c2 = m_b.get_color();
		// Interpolated color.
		color col = color(c2.r - c1.r, c2.g - c1.g, c2.b - c1.b);
		col.r *= t;
		col.g *= t;
		col.b *= t;
		col.r += c1.r;
		col.g += c1.g;
		col.b += c1.b;

		// Draw the point.
		point p(pos, col);
		scr.draw(p);
	}
}

}