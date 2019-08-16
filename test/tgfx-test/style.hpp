#pragma once

#include <sstream>
#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include "tgfx/color.hpp"
#include "tgfx/style.hpp"

/*
! IMPORTANT NOTE

These are, in a way, "meta-tests"
tgfx::style has 6 identical sets of members:
 - bold
 - faint
 - italic
 - underline
 - strikeout
 - blink
 
We use the upcoming #define macro to auto-generate identical tests for each of them.
*/

#define STYLEPOINT_TEST(point)                      \
	TEST(style, point)                              \
	{                                               \
		using tgfx::style;                          \
                                                    \
		style s;                                    \
		EXPECT_EQ(s.point(), style::state::IGNORE); \
		s.point##_on();                             \
		EXPECT_EQ(s.point(), style::state::ON);     \
		s.point##_on();                             \
		EXPECT_EQ(s.point(), style::state::ON);     \
		s.point##_off();                            \
		EXPECT_EQ(s.point(), style::state::OFF);    \
		s.point##_off();                            \
		EXPECT_EQ(s.point(), style::state::OFF);    \
		s.point##_ignore();                         \
		EXPECT_EQ(s.point(), style::state::IGNORE); \
		s.point##_ignore();                         \
		EXPECT_EQ(s.point(), style::state::IGNORE); \
                                                    \
		s.point(style::state::ON);                  \
		EXPECT_EQ(s.point(), style::state::ON);     \
		s.point(style::state::OFF);                 \
		EXPECT_EQ(s.point(), style::state::OFF);    \
		s.point(style::state::IGNORE);              \
		EXPECT_EQ(s.point(), style::state::IGNORE); \
	}


STYLEPOINT_TEST(bold)
STYLEPOINT_TEST(faint)
STYLEPOINT_TEST(italic)
STYLEPOINT_TEST(underline)
STYLEPOINT_TEST(blink)
STYLEPOINT_TEST(strikeout)

/*
This macro is used twice for fg() and bg() methods
*/
#define STYLE_COLOR_TEST(layer)                                     \
	TEST(style, layer)                                              \
	{                                                               \
		using tgfx::style;                                          \
		using tgfx::color;                                          \
                                                                    \
		style s;                                                    \
		EXPECT_EQ(s.layer(), style::state::IGNORE);                 \
                                                                    \
		ASSERT_FALSE(s.layer##_color());                            \
                                                                    \
		s.layer##_on(color(125, 123, 220));                         \
		EXPECT_EQ(s.layer(), style::state::ON);                     \
		ASSERT_TRUE(s.layer##_color());                             \
		EXPECT_EQ(s.layer##_color().value(), color(125, 123, 220)); \
		s.layer##_off();                                            \
		EXPECT_EQ(s.layer(), style::state::OFF);                    \
		EXPECT_FALSE(s.layer##_color());                            \
		s.layer##_ignore();                                         \
		EXPECT_EQ(s.layer(), style::state::IGNORE);                 \
                                                                    \
		s.layer(style::state::OFF);                                 \
		EXPECT_EQ(s.layer(), style::state::OFF);                    \
		s.layer(style::state::ON, color(10, 20, 30));               \
		EXPECT_EQ(s.layer(), style::state::ON);                     \
		ASSERT_TRUE(s.layer##_color());                             \
		EXPECT_EQ(s.layer##_color().value(), color(10, 20, 30));    \
		s.layer(style::state::ON);                                  \
		EXPECT_EQ(s.layer(), style::state::ON);                     \
		ASSERT_TRUE(s.layer##_color());                             \
		EXPECT_EQ(s.layer##_color().value(), color());              \
                                                                    \
		s.flush();                                                  \
		EXPECT_EQ(s.layer(), style::state::IGNORE);                 \
	}

STYLE_COLOR_TEST(fg)
STYLE_COLOR_TEST(bg)

TEST(style, reset)
{
	using tgfx::style;

	style s;
	EXPECT_EQ(s.reset(), style::state::OFF);
	s.reset_on();
	EXPECT_EQ(s.reset(), style::state::ON);
	s.reset_off();
	EXPECT_EQ(s.reset(), style::state::OFF);
	s.reset(style::state::ON);
	EXPECT_EQ(s.reset(), style::state::ON);
	s.reset(style::state::OFF);
	EXPECT_EQ(s.reset(), style::state::OFF);
	s.reset(style::state::ON);
	EXPECT_EQ(s.reset(), style::state::ON);
	s.flush();
	EXPECT_EQ(s.reset(), style::state::OFF);
}

TEST(style, output)
{
	using tgfx::color;
	using tgfx::style;

	style s;
	using namespace ::testing;
	EXPECT_THAT(s.code(), IsEmpty());
	s.bg_on(color(255, 127, 0));
	s.fg_on(color(0, 10, 100));
	s.bold_on();
	s.italic_on();
	EXPECT_THAT(s.code(), HasSubstr(color(255, 127, 0).to_ansi_escape(false)));
	EXPECT_THAT(s.code(), HasSubstr(color(0, 10, 100).to_ansi_escape()));
	EXPECT_THAT(s.code(), HasSubstr("\u001b[1m"));
	EXPECT_THAT(s.code(), HasSubstr("\u001b[3m"));
	EXPECT_THAT(s.code(), Not(HasSubstr("\u001b[4m")));
	EXPECT_THAT(s.code(), Not(HasSubstr("\u001b[4m")));
	s.underline_on();
	s.bold_ignore();
	s.italic_off();
	EXPECT_THAT(s.code(), HasSubstr("\u001b[4m"));
	EXPECT_THAT(s.code(), Not(HasSubstr("\u001b[3m")));
	EXPECT_THAT(s.code(), Not(HasSubstr("\u001b[1m")));
	EXPECT_THAT(s.code(), Not(HasSubstr("\u001b[21m")));
	EXPECT_THAT(s.code(), HasSubstr("\u001b[23m"));
	s.reset_on();
	s.blink_on();
	EXPECT_THAT(s.code(), EndsWith("\u001b[0m"));
}

TEST(style, flush)
{
	using tgfx::color;
	using tgfx::style;

	style s;
	using namespace ::testing;
	EXPECT_THAT(s.code(), IsEmpty());
	s.bg_on(color(255, 127, 0));
	s.fg_on(color(0, 10, 100));
	s.bold_on();
	s.italic_on();
	s.faint_off();
	s.strikeout_off();
	s.underline_ignore();

	s.flush();
	EXPECT_THAT(s.code(), IsEmpty());
}

TEST(style, ostream)
{
	using tgfx::color;
	using tgfx::style;

	style s;
	using namespace ::testing;
	EXPECT_THAT(s.code(), IsEmpty());
	s.bg_on(color(255, 127, 0));
	s.fg_on(color(0, 10, 100));
	s.bold_on();
	s.italic_on();
	s.faint_off();
	s.strikeout_off();
	s.underline_ignore();

	std::ostringstream ss;
	ss << s;
	EXPECT_EQ(ss.str(), s.code());
}