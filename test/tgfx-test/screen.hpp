#pragma once

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "tgfx/screen.hpp"
#include "tgfx/style.hpp"
#include "tgfx/util/vec2.hpp"

TEST(screen, Pixels)
{
	using tgfx::screen;
	using tgfx::style;
	using tgfx::vec2u;
	using pixel = tgfx::screen::pixel;

	screen s;
	std::string str = "Hello, World!";
	for (size_t i = 0; i < str.size(); ++i)
	{
		s.set_pixel(vec2u(5 + i, 5), pixel(str[i], style().bold_on().italic_on()));
	}

	for (size_t i = 0; i < str.size(); ++i)
	{
		EXPECT_EQ(s.get_pixel(vec2u(5 + i, 5)).ch, str[i]);
		EXPECT_EQ(s.get_pixel(vec2u(5 + i, 5)).fmt, style().italic_on().bold_on());
	}
}