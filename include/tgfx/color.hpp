#pragma once

#include <cstdint>
#include <ios>
#include <sstream>
#include <string>

namespace tgfx
{

/**
 * @brief Stores an RGB color, and has methods for converting it to/from different formats. 
 * 
 * @remarks Alpha is always 0xFF (255)
 */
class color
{
public:
	/// Defaults to black (0, 0, 0)
	color(uint8_t r = 0, uint8_t g = 0, uint8_t b = 0);

	/// Converts the color to a 32-bit color integer.
	uint32_t to_integer() const;
	/// Converts the color from a 32-bit color integer.
	void from_integer(uint32_t integer);

	/// Convert the color to a readable hex format.
	std::string to_hex_color() const;


	/// Red component
	uint8_t r;
	/// Green component
	uint8_t g;
	/// Blue component
	uint8_t b;
};

}