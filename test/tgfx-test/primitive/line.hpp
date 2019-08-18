#pragma once

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "tgfx/tgfx.hpp"

TEST(line, Constructor)
{
	using namespace tgfx;

	line l(point({ 0, 0 }, color(0, 0, 0)),
		   point({ 5, 5 }, color(127, 127, 255)));

	EXPECT_EQ(l.get_point_a().get_position(), vec2u(0, 0));
	EXPECT_EQ(l.get_point_a().get_color(), color(0, 0, 0));
	EXPECT_EQ(l.get_point_b().get_position(), vec2u(5, 5));
	EXPECT_EQ(l.get_point_b().get_color(), color(127, 127, 255));
}