#include "gtest/gtest.h"

#include "tgfx-test/color.hpp"
#include "tgfx-test/context.hpp"
#include "tgfx-test/drawable.hpp"
#include "tgfx-test/internal/ansi-color.hpp"
#include "tgfx-test/primitive/line.hpp"
#include "tgfx-test/primitive/point.hpp"
#include "tgfx-test/screen.hpp"
#include "tgfx-test/style.hpp"
#include "tgfx-test/util/clock.hpp"
#include "tgfx-test/util/time.hpp"
#include "tgfx-test/util/vec2.hpp"

int main(int argc, char** argv)
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}