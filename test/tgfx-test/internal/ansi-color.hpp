#pragma once

#include "gtest/gtest.h"
#include "tgfx/color.hpp"
#include "tgfx/internal/ansi-color.hpp"

#ifdef COLOR_MODE_16

TEST(ansi_color, MODE_16)
{
	using namespace tgfx::internal;
	using tgfx::color;
	EXPECT_EQ(get_color_escape_code(color()), "\u001b[30m");
	EXPECT_EQ(get_color_escape_code(color(128, 128, 128)), "\u001b[1;30m");
	EXPECT_EQ(get_color_escape_code(color(), false), "\u001b[40m");
	EXPECT_EQ(get_color_escape_code(color(128, 128, 128), false), "\u001b[1;40m");

	EXPECT_EQ(get_color_escape_code(color(255, 255, 255)), "\u001b[1;37m");
	EXPECT_EQ(get_color_escape_code(color(192, 192, 192)), "\u001b[37m");
	EXPECT_EQ(get_color_escape_code(color(255, 255, 255), false), "\u001b[1;47m");
	EXPECT_EQ(get_color_escape_code(color(192, 192, 192), false), "\u001b[47m");
}

#elif COLOR_MODE_256

TEST(ansi_color, MODE_256)
{
	using namespace tgfx::internal;
	using tgfx::color;

	EXPECT_EQ(get_color_escape_code(color(0x880000ff)), "\u001b[38;5;88 m");
	EXPECT_EQ(get_color_escape_code(color(0x87af5eff)), "\u001b[38;5;107 m");
	EXPECT_EQ(get_color_escape_code(color(0xaf0000ff)), "\u001b[38;5;124 m");
	EXPECT_EQ(get_color_escape_code(color(0x880000ff), false), "\u001b[48;5;88 m");
	EXPECT_EQ(get_color_escape_code(color(127, 127, 255), false), "\u001b[48;5;105 m");
}

#elif COLOR_MODE_TRUE

TEST(ansi_color, MODE_TRUE)
{
	using namespace tgfx::internal;
	using tgfx::color;
}

#endif