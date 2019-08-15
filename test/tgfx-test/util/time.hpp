#pragma once

#include "gtest/gtest.h"

#include "tgfx/util/time.hpp"

TEST(time, Conversions)
{
	using tgfx::time;
	time t(time::seconds(5));
	EXPECT_EQ(t.as_nanoseconds(), 5000000000);
	EXPECT_EQ(t.as_milliseconds(), 5000);
	EXPECT_EQ(t.as_seconds(), 5);
	t = time(time::milliseconds(220));
	EXPECT_EQ(t.as_nanoseconds(), 220000000);
	EXPECT_EQ(t.as_milliseconds(), 220);
	EXPECT_EQ(t.as_seconds(), 0.22);
}

TEST(time, Equality)
{
	using tgfx::time;

	time a(time::seconds(4));
	time b(time::milliseconds(4000));
	time c(time::nanoseconds(4000000000));
	time d(time::milliseconds(3999));

	EXPECT_TRUE(a == b);
	EXPECT_FALSE(a != b);
	EXPECT_TRUE(a == c);
	EXPECT_FALSE(a != c);
	EXPECT_TRUE(a != d);
	EXPECT_FALSE(a == d);
	EXPECT_TRUE(b == c);
	EXPECT_TRUE(b != d);
	EXPECT_TRUE(a != d);
}

TEST(time, Comparisons)
{
	using tgfx::time;

	time a(time::seconds(12));
	time b(time::milliseconds(4250));
	time c(time::nanoseconds(5000000000));
	time d(time::milliseconds(5000));

	EXPECT_TRUE(a > b);
	EXPECT_TRUE(a >= b);
	EXPECT_FALSE(a < b);
	EXPECT_FALSE(a <= b);
	EXPECT_TRUE(c >= d);
	EXPECT_TRUE(c <= d);
	EXPECT_FALSE(c > d);
	EXPECT_FALSE(c < d);
	EXPECT_TRUE(b < d);
	EXPECT_TRUE(b <= d);
	EXPECT_FALSE(b > d);
	EXPECT_FALSE(b >= d);
}

TEST(time, Arithmetic)
{
	using tgfx::time;

	time a(time::seconds(3));
	time b(time::milliseconds(200));
	time c(time::nanoseconds(3000000000));

	EXPECT_EQ(a + b, time::seconds(3.2));
	EXPECT_EQ(a - b, time::seconds(2.8));
	EXPECT_EQ(c - a, time::seconds(0));
	EXPECT_EQ(a + b + c, time::milliseconds(3000 + 200 + 3000));
	EXPECT_EQ(a + b - c, time::milliseconds(200));
}