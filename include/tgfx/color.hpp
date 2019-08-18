#pragma once

#include <cstdint>
#include <iomanip>
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
	color();
	/// Initialize from RGB values.
	color(uint8_t r, uint8_t g, uint8_t b);
	/// Convert the color from a coor integer.
	color(uint32_t integer);

	/// Converts the color to a 32-bit color integer.
	uint32_t to_integer() const;
	/// Convert the color to a readable hex format.
	std::string to_hex_color() const;
	/// Convert this color to a printable ansi-escape code.
	std::string to_ansi_escape(bool foreground = true) const;

	/// Returns true if the two colors are identical.
	bool operator==(const color& other) const;
	/// Returns true if the two colors aren't identical.
	bool operator!=(const color& other) const;

	/// Red component
	uint8_t r;
	/// Green component
	uint8_t g;
	/// Blue component
	uint8_t b;
};

}

/**
 * @brief Example usage of basic color operations and conversions.
 * 
 * @example color/color.cpp
 * 
 */