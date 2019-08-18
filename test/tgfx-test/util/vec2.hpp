#pragma once

#include "gtest/gtest.h"
#include "tgfx/util/vec2.hpp"

TEST(vec2, Constructor)
{
	using namespace tgfx;

	vec2f v(3, 4);
	EXPECT_EQ(v.x, 3);
	EXPECT_EQ(v.y, 4);

	v = vec2f();
	EXPECT_EQ(v.x, 0);
	EXPECT_EQ(v.y, 0);

	v = { 5, 3.f };
	EXPECT_EQ(v.x, 5);
	EXPECT_EQ(v.y, 3);
}

TEST(vec2, Assignment)
{
	using namespace tgfx;

	vec2f v;
	v.x = 8;
	v.y = 3;
	EXPECT_EQ(v.x, 8);
	EXPECT_EQ(v.y, 3);
}

TEST(vec2, Arithmetic)
{
	using namespace tgfx;

	vec2f v(3, 4);
	vec2f w(5, 6);
	vec2f sum = v + w;
	EXPECT_EQ(sum.x, 8);
	EXPECT_EQ(sum.y, 10);
	vec2f diff = v - w;
	EXPECT_EQ(diff.x, -2);
	EXPECT_EQ(diff.y, -2);
	v += w;
	EXPECT_EQ(v.x, sum.x);
	EXPECT_EQ(v.y, sum.y);
	v -= w;
	v -= w;
	EXPECT_EQ(v.x, diff.x);
	EXPECT_EQ(v.y, diff.y);
	v			 = vec2f(3, 4);
	vec2f scaled = v * 5;
	EXPECT_EQ(scaled.x, 15);
	EXPECT_EQ(scaled.y, 20);
	vec2f cut = v / 5;
	EXPECT_EQ(cut.x, 0.6f);
	EXPECT_EQ(cut.y, 0.8f);
	scaled *= 2;
	EXPECT_EQ(scaled.x, 30);
	EXPECT_EQ(scaled.y, 40);
	cut /= 3;
	EXPECT_EQ(cut.x, 0.2f);
	EXPECT_EQ(cut.y, 0.8f / 3.f);
}

TEST(vec2, Comparisons)
{
	using namespace tgfx;

	vec2f a(1, 2);
	vec2f b(2, 1);
	vec2f c(4, 3);
	vec2i d(4, 3);

	EXPECT_TRUE(a == a);
	EXPECT_TRUE(b == b);
	EXPECT_TRUE(c == c);
	EXPECT_TRUE(d == d);
	EXPECT_FALSE(a != a);
	EXPECT_FALSE(b != b);
	EXPECT_FALSE(c != c);
	EXPECT_FALSE(d != d);

	EXPECT_FALSE(a == b);
	EXPECT_FALSE(a == c);
	EXPECT_FALSE(a == d);
	EXPECT_TRUE(a != b);
	EXPECT_TRUE(a != c);
	EXPECT_TRUE(a != d);
	EXPECT_FALSE(b == c);
	EXPECT_FALSE(b == d);
	EXPECT_TRUE(c == d);
	EXPECT_FALSE(c != d);
}

TEST(vec2, DotProduct)
{
	using namespace tgfx;

	vec2f a(5, 3);
	vec2f b(2, 4);

	EXPECT_EQ(a.dot(b), 22);
	EXPECT_EQ(b.dot(a), 22);
}

TEST(vec2, Hypotenuse)
{
	using namespace tgfx;

	vec2f a(3, 4);
	vec2f b(5, 12);
	vec2f c(std::sqrt(5.f), std::sqrt(3.f));

	EXPECT_EQ(a.hypot(), 5);
	EXPECT_EQ(b.hypot(), 13);
	EXPECT_FLOAT_EQ(c.hypot() * c.hypot(), 8);
}

TEST(vec2, Stringify)
{
	using namespace tgfx;

	vec2f x(3.8f, 8.9f);
	vec2f y(2.2f, 4.2f);

	EXPECT_EQ(std::string(x), "(3.8, 8.9)");
	EXPECT_EQ(std::string(y), "(2.2, 4.2)");
}

TEST(vec2, OStream)
{
	using namespace tgfx;

	vec2f x(3.4f, 100.2024f);
	std::ostringstream oss;
	oss << x;
	EXPECT_EQ(oss.str(), "(3.4, 100.202)");
}