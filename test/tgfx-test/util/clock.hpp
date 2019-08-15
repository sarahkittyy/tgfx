#pragma once

#include <chrono>
#include <thread>
#include "gtest/gtest.h"
#include "tgfx/util/clock.hpp"

TEST(clock, Working)
{
	using tgfx::clock;
	using namespace std::chrono_literals;

	clock c;
	std::this_thread::sleep_for(1s);
	EXPECT_NEAR(c.elapsed().as_seconds(), 1, 0.02);
	EXPECT_NEAR(c.restart().as_seconds(), 1, 0.02);
	// Clock is now restarted
	EXPECT_NEAR(c.elapsed().as_seconds(), 0, 0.02);
}