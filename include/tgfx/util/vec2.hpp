#pragma once

#include <cmath>
#include <ostream>
#include <sstream>
#include <string>

namespace tgfx
{

/**
 * @brief A simple X/Y vector
 * 
 * @tparam Number Any C++ numerical type.
 */
template <typename Number>
class vec2
{
public:
	/// Initializes the vector to (x, y). Defaults to (0,0 )
	vec2(Number x = 0, Number y = 0)
		: x(x), y(y)
	{
	}

	/// Converts the x/y point to a readable human format.
	operator std::string() const
	{
		std::ostringstream oss;
		oss << "(" << x << ", " << y << ")";
		return oss.str();
	}

	/// Adds two vectors, resulting in v + w = (v.x + w.x, v.y + w.y)
	template <typename OtherNumber>
	vec2 operator+(const vec2<OtherNumber>& other) const
	{
		return vec2(x + other.x, y + other.y);
	}
	/// Subtracts two vectors, resulting in v - w = (v.x - w.x, v.y - w.y)
	template <typename OtherNumber>
	vec2 operator-(const vec2<OtherNumber>& other) const
	{
		return operator+(-other);
	}
	/// Negates the vector, returning (-x, -y)
	vec2 operator-() const
	{
		return vec2(-x, -y);
	}
	/// Adds another vector onto this vector, resulting in v += w => v = (v.x + w.x, v.y + w.y)
	template <typename OtherNumber>
	vec2& operator+=(const vec2<OtherNumber>& other)
	{
		x += other.x;
		y += other.y;
		return *this;
	}
	/// Subtracts another vector from this vector, resulting in v -= w => v = (v.x - w.x, v.y - w.y)
	template <typename OtherNumber>
	vec2& operator-=(const vec2<OtherNumber>& other)
	{
		x -= other.x;
		y -= other.y;
		return *this;
	}

	/// Multiplies a vector by a scalar. v * c = (cx + cy)
	template <typename Scalar>
	vec2 operator*(const Scalar& other) const
	{
		return vec2(x * other, y * other);
	}
	/// Divides a vector by a scalar. v / c = (x/c + y/c)
	template <typename Scalar>
	vec2 operator/(const Scalar& other) const
	{
		return vec2(x / other, y / other);
	}
	/// Multiplies this vector by a scalar.
	template <typename Scalar>
	vec2& operator*=(const Scalar& other)
	{
		x *= other;
		y *= other;
		return *this;
	}
	/// Divides this vector by a scalar.
	template <typename Scalar>
	vec2& operator/=(const Scalar& other)
	{
		x /= other;
		y /= other;
		return *this;
	}
	/// Returns true if and only if the vectors are exactly identical.
	template <typename OtherNumber>
	constexpr bool operator==(const vec2<OtherNumber>& other) const
	{
		return (x == other.x) && (y == other.y);
	}
	/// Returns true if and only if hte vectors are not exactly identical.
	template <typename OtherNumber>
	constexpr bool operator!=(const vec2<OtherNumber>& other) const
	{
		return !operator==(other);
	}

	/// Returns the dot product of this vector and another vector.
	template <typename OtherNumber>
	Number dot(const vec2<OtherNumber>& other) const
	{
		return (x * other.x) + (y * other.y);
	}

	/// Return the hypotenuse of the vector.
	Number hypot() const
	{
		return std::sqrt(x * x + y * y);
	}

	/// X
	Number x;
	/// Y
	Number y;
};

/// Common typedefs.
typedef vec2<float> vec2f;
typedef vec2<int> vec2i;
typedef vec2<unsigned int> vec2u;

}

// ostream Overload
template <typename Number>
std::ostream& operator<<(std::ostream& os, const tgfx::vec2<Number>& vector)
{
	os << std::string(vector);
	return os;
}

/**
 * @brief Example usage of tgfx::vec2 and various vector calculations.
 * 
 * @example vec2/vec2.cpp
 * 
 */