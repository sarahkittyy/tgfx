#include "tgfx/drawable.hpp"
#include "tgfx/screen.hpp"

namespace tgfx
{

screen::screen()
{
}

std::string screen::flush()
{
	return "owo";
}

void screen::draw(const drawable& drawable)
{
	drawable.draw(*this);
}

}