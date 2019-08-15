#pragma once

#include <chrono>
#include "tgfx/util/time.hpp"

namespace tgfx
{

/**
 * @brief A clock class for timing events.
 * 
 */
class clock
{
public:
	/// Initializes and starts the clock.
	clock();

	/// Resets the clock back to 0, returning the elapsed time since the last restart.
	time restart();
	/// Returns the time elapsed since last restart, without restarting the clock.
	time elapsed() const;

private:
	/// Marks the point of last restart() call.
	std::chrono::system_clock::time_point m_start;
};

}