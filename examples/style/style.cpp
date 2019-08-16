#include <iostream>
#include "tgfx/tgfx.hpp"

int main()
{
	// For terminal setup / cleanup.
	tgfx::context ctx;

	tgfx::style style;
	style.bold_on();
	style.italic_on();

	// Blue text
	style.fg_on(tgfx::color(60, 60, 255));
	// Dark grey background
	style.bg_on(tgfx::color(60, 60, 60));

	std::cout << style << "Hello, World!" << std::endl;
	return 0;
}