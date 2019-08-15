#pragma once

#include <sys/ioctl.h>

#include "tgfx/util/vec2.hpp"

namespace tgfx
{

class context
{
public:
	context();
	~context();

	void clear();
	void render();
};

}