#include "tgfx/primitive/point.hpp"

namespace tgfx
{

point::point(vec2u pos, color col)
	: m_pos(pos), m_col(col)
{
}

void point::set_position(vec2u pos)
{
	m_pos = pos;
}

vec2u point::get_position() const
{
	return m_pos;
}

void point::set_color(color col)
{
	m_col = col;
}

color point::get_color() const
{
	return m_col;
}

void point::draw(screen& scr) const
{
	/// Set the point's pixel.
	scr.set_pixel(m_pos, screen::pixel(' ', style().bg_on(m_col)));
}

}