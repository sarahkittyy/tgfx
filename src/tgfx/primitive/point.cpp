#include "tgfx/primitive/point.hpp"

namespace tgfx
{

point::point(vec2u pos, color col)
	: m_pos(pos), m_col(col)
{
}

void point::draw(screen& scr) const
{
	/// Set the point's pixel.
	scr.set_pixel(m_pos, screen::pixel(' ', style().bg_on(m_col)));
}

}