#include "tgfx/util/time.hpp"

namespace tgfx
{

time::time()
{
}

time::time(long long ns)
	: m_time(ns)
{
}

time time::seconds(double seconds)
{
	return time(seconds * 1e9);
}

time time::milliseconds(double ms)
{
	return time(ms * 1e6);
}

time time::nanoseconds(long long ns)
{
	return time(ns);
}

const double time::as_seconds() const
{
	return m_time.count() / 1e9;
}

const double time::as_milliseconds() const
{
	return m_time.count() / 1e6;
}

const long long time::as_nanoseconds() const
{
	return m_time.count();
}

time time::operator+(const time& other) const
{
	return time::nanoseconds(m_time.count() + other.m_time.count());
}

time time::operator-(const time& other) const
{
	return time::nanoseconds(m_time.count() - other.m_time.count());
}

time& time::operator+=(const time& other)
{
	*this = operator+(other);
	return *this;
}

time& time::operator-=(const time& other)
{
	*this = operator-(other);
	return *this;
}

time time::operator-() const
{
	return time(-m_time.count());
}

const bool time::operator==(const time& other) const
{
	return m_time == other.m_time;
}

const bool time::operator!=(const time& other) const
{
	return !(*this == other);
}

const bool time::operator<(const time& other) const
{
	return m_time < other.m_time;
}

const bool time::operator>(const time& other) const
{
	return m_time > other.m_time;
}

const bool time::operator>=(const time& other) const
{
	return (*this > other) || (*this == other);
}

const bool time::operator<=(const time& other) const
{
	return (*this < other) || (*this == other);
}

}