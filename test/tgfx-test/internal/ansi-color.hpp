#pragma once

#include "gtest/gtest.h"
#include "tgfx/internal/ansi-color.hpp"

#undef COLOR_MODE_TRUE
#undef COLOR_MODE_256
#undef COLOR_MODE_16

TEST(ansi_color, MODE_16)
{
#define COLOR_MODE_16
	using namespace tgfx::internal;
	EXPECT_EQ(get_color_escape_code(color()), "\u001b[30m");
#undef COLOR_MODE_16
}

TEST(ansi_color, MODE_256){
#define COLOR_MODE_256

#undef COLOR_MODE_256
}

TEST(ansi_color, MODE_TRUE)
{
#define COLOR_MODE_TRUE

#undef COLOR_MODE_TRUE
}