#include <iomanip>
#include <ios>
#include <iostream>
#include "tgfx/color.hpp"

int main()
{
	// Init a light blue color
	tgfx::color color;
	color.r = 127;
	color.g = 127;
	color.b = 255;
	// Other options:
	// tgfx::color(127, 127, 255)
	// tgfx::color(0x7f7fff)

	// Output: 7f7fff
	std::cout << std::hex << color.to_integer() << std::dec << std::endl;
	// Output: #7f7fff
	std::cout << color.to_hex_color() << std::endl;
	/*
	Output is COLOR_MODE dependent. Will return differently based on terminal color mode.
	Example for True Color output:
	*/
	//Output: \u001b[38;2;127;127;255 m
	std::cout << "\\u001b" + color.to_ansi_escape().substr(1) << std::endl;
}