#pragma once

#include <cmath>
#include <sstream>
#include "tgfx/internal/ansi-color-lut.hpp"

namespace tgfx
{

class color;

namespace internal
{

/**
 * @brief Gets a printable escape code that changes the color of the outputted text.
 * 
 * @param in The input color.
 * @param foreground true for foreground escape codes, false for background escape codes.
 * @return std::string A printable escape code to change the outputted text's color.
 * 
 * @remarks The input color will be rounded to the nearest compatible color based on the COLOR_MODE CMake configuration setting.
 */
std::string get_color_escape_code(const color& in, bool foreground = true);

}

}