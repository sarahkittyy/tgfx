#include "tgfx/tgfx.hpp"

int main()
{
	tgfx::context ctx;

	// Draw a line from the top-left corner to the bottom-right.
	tgfx::line line(tgfx::point({ 0, 0 }, tgfx::color(0, 0, 0)),
					tgfx::point(ctx.size(), tgfx::color(255, 255, 255)));

	while (ctx.open())
	{
		ctx.clear();

		// Render the line.
		ctx.draw(line);

		ctx.render();
	}

	return 0;
}