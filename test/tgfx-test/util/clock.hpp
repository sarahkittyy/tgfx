#pragma once

#include <chrono>
#include "gtest/gtest.h"
#include "tgfx/util/clock.hpp"

TEST(clock, Working)
{
	using tgfx::clock;
	using namespace std::chrono_literals;

	clock c;
	EXPECT_NEAR(c.elapsed().as_seconds(), 0, 0.001);

	//TODO: mocking std::this_thread::sleep() to make quick and reliable tests
}