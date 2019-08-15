#include "tgfx/util/clock.hpp"

namespace tgfx
{

clock::clock()
{
	restart();
}

time clock::restart()
{
	time el = elapsed();
	m_start = std::chrono::high_resolution_clock::now();
	return el;
}

time clock::elapsed() const
{
	// For convenience
	namespace chrono = std::chrono;

	// Get the current timepoint.
	auto now = chrono::high_resolution_clock::now();
	// Subtract the start time from the current time to get elapsed time, storing it
	// in a `time` duration.
	time el =
		time::nanoseconds(
			chrono::duration_cast<chrono::nanoseconds>(now - m_start).count());
	return el;   // Return that duration.
}

}