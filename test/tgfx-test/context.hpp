#pragma once

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "tgfx/context.hpp"

TEST(context, OpenClose)
{
	using tgfx::context;

	context c;
	EXPECT_TRUE(c.open());
	c.close();
	EXPECT_FALSE(c.open());
}