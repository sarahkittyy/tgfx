#pragma once

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
	/// Returns the dot product of this vector and another vector.
	template <typename OtherNumber>
	Number dot(const vec2<OtherNumber>& other) const
	{
		return (x * other.x) + (y * other.y);
	}

	/// X
	Number x;
	/// Y
	Number y;
};

}