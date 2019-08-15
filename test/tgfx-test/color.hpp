#pragma once

#include <cstdint>

#include "gtest/gtest.h"
#include "tgfx/color.hpp"

TEST(color, Construction)
{
	using tgfx::color;

	color c;
	EXPECT_EQ(c.r, 0);
	EXPECT_EQ(c.g, 0);
	EXPECT_EQ(c.b, 0);

	c = color(127, 127, 255);
	EXPECT_EQ(c.r, 127);
	EXPECT_EQ(c.g, 127);
	EXPECT_EQ(c.b, 255);

	c.b = (uint8_t)256;
	EXPECT_EQ(c.b, 0);
}

TEST(color, IntegerConversion)
{
	using tgfx::color;

	color c(127, 127, 255);
	EXPECT_EQ(c.to_integer(), 0x7f7fffff);
	c.from_integer(0x00FF7f00);
	EXPECT_EQ(c.r, 0);
	EXPECT_EQ(c.g, 255);
	EXPECT_EQ(c.b, 127);
}

TEST(color, HexConversion)
{
	using tgfx::color;

	color a(25, 50, 75);
	EXPECT_STRCASEEQ(a.to_hex_color().c_str(), "#19324b");
	color b(127, 127, 255);
	EXPECT_STRCASEEQ(a.to_hex_color().c_str(), "#7f7fff");
}