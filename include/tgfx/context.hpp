#pragma once

#include <sys/ioctl.h>

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