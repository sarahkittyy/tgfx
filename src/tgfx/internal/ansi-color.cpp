#include "tgfx/color.hpp"
#include "tgfx/internal/ansi-color.hpp"

namespace tgfx::internal
{

std::string get_escape_code(const color& in, bool foreground)
{
	/// The escape code to append to, and then return.
	std::stringstream code;
	code << "\u001b[";

	//* Calculates the adjusted color distance of two colors if they were 3D vectors.
	// We could square root it, but we don't need the value itself,
	// so we can just compare the squares and get the same result.
	auto dist = [in](const color& other) -> float {
		float dr = in.r - other.r;
		float dg = in.g - other.g;
		float db = in.b - other.b;
		// Color weights (see below)
		dr *= 0.30f;
		dg *= 0.59f;
		db *= 0.11f;
		// Return the distance
		return (dr * dr) + (dg * dg) + (db * db);
	};

	//! https://en.wikipedia.org/wiki/Color_difference
	//! ^ We weigh the color difference according to here, to adjust for human color perspective differences.
	//* w(r) = 0.30
	//* w(g) = 0.59
	//* w(b) = 0.11

#ifdef COLOR_MODE_16

	auto available_end = COLORS.begin();
	std::advance(available_end, 16);

	// Find the code in the first 16 available colors in the LUT that most closeley matches `in`.
	uint8_t color_code = std::min(COLORS.begin(), available_end,
								  [&dist](const std::pair<uint8_t, uint32_t>& a,
										  const std::pair<uint8_t, uint32_t>& b) {
									  /// Get the two colors from the color integers in the map.
									  color a_col(a.second);
									  color b_col(b.second);
									  /// Return the one with the lower distance to the original color.
									  return dist(a_col) < dist(b_col);
								  })
							 ->first;

	// Special flags we can determine from the resulting color.
	bool bright = color_code > 7;

	// Output the resulting ANSI code to the stream
	code << (bright ? "1;" : "") << ((foreground ? 30 : 40) + (color_code % 8)) << " m";

#elif COLOR_MODE_256
	// Foreground / background modifier.
	code << (foreground ? "38" : "48");
	code << ";5;";

	// Find the color in the color lookup table of which dist() returns the lowest.
	// We take that value and append it to `code`
	code << std::min(COLORS.begin(), COLORS.end(),
					 [&dist](const std::pair<uint8_t, uint32_t>& a,
							 const std::pair<uint8_t, uint32_t>& b) {
						 /// Get the two colors from the color integers in the map.
						 color a_col(a.second);
						 color b_col(b.second);
						 /// Return the one with the lower distance to the original color.
						 return dist(a_col) < dist(b_col);
					 })
				->first;

	code << " m";

#elif COLOR_MODE_TRUE
	// Foreground / background modifier.
	code << (foreground ? "38;2" : "48;2");
	code << ";";
	// We can directly use RGB in COLOR_MODE_TRUE
	code << in.r << ";" << in.g << ";" << in.b << " m";
#endif
	return code.str();
}

}