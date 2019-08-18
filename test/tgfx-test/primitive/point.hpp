#pragma once

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "tgfx/color.hpp"
#include "tgfx/primitive/point.hpp"
#include "tgfx/screen.hpp"
#include "tgfx/util/vec2.hpp"

TEST(point, Point)
{
	tgfx::point p(tgfx::vec2u(0, 0));
	EXPECT_EQ(p.get_color(), tgfx::color(0, 0, 0));
	EXPECT_EQ(p.get_position(), tgfx::vec2u(0, 0));
	p.set_color(tgfx::color(127, 127, 255));
	p.set_position(tgfx::vec2u(20, 15));
	EXPECT_EQ(p.get_position(), tgfx::vec2u(20, 15));
	EXPECT_EQ(p.get_color(), tgfx::color(127, 127, 255));
}