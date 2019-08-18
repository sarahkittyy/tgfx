#pragma once

#include <chrono>

namespace tgfx
{

/**
 * @brief Utility class for handling durations of time.
 * 
 */
class time
{
public:
	/// Construct the time instance.
	time();

	/// Return a time instance configured to the given number of seconds.
	static time seconds(double seconds);
	/// Return a time instance configured to the given number of milliseconds
	static time milliseconds(double ms);
	/// Return a time duration from nanosecondos
	static time nanoseconds(long long ns);

	/// Get this time duration in seconds.
	const double as_seconds() const;
	/// Get this time duration in millseconds.
	const double as_milliseconds() const;
	/// Get this time duration in nanoseconds.
	const long long as_nanoseconds() const;

	/// Add two times together.
	time operator+(const time& other) const;
	/// Subtract another time from this time, returning the result.
	time operator-(const time& other) const;
	/// Add another time duration to this time.
	time& operator+=(const time& other);
	/// Subtract a duration from this duration.
	time& operator-=(const time& other);
	/// Negate this time duration.
	time operator-() const;

	/// Returns true if and only if the two times are equal.
	const bool operator==(const time& other) const;
	/// Returns true if and only if the two times are inequal.
	const bool operator!=(const time& other) const;
	/// Returns true if the lhs duration is shorter than the rhs
	const bool operator<(const time& other) const;
	/// Returns true if the lhs duration is longer than the rhs
	const bool operator>(const time& other) const;
	/// Returns true if the lhs duration is longer or equal to the rhs duration
	const bool operator>=(const time& other) const;
	/// Returns true if the lhs duration is shorter or equal to the rhs duration
	const bool operator<=(const time& other) const;

private:
	/// For construction in time::seconds() / time::milliseconds(), initializes with nanoseconds.
	time(long long ns);

	/// The private std::chrono duration, in nanoseconds.
	std::chrono::duration<long long, std::nano> m_time;
};

}

/**
 * @brief Example usage of tgfx::clock and tgfx::time for timing code.
 * 
 * @example timing/timing.cpp
 * 
 */