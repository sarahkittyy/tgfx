#include <iostream>
#include "tgfx/util/vec2.hpp"

int main()
{
	using std::cout;
	using std::endl;

	// Typedef for tgfx::vec2<float>
	tgfx::vec2f v;
	tgfx::vec2f w(5, 12);

	// Vector x/y access
	v.x = 3;
	v.y = 4;

	// Vectors can be printed to streams, will return formatted as (x, y)
	cout << "v = " << v << ", w = " << w << endl;
	// Vector addition / subtraction
	cout << "v + w = " << v + w << endl;
	cout << "v - w = " << v - w << endl;
	// Vector negation
	cout << "-v = " << -v << endl;
	// Vector-scalar multiplication
	cout << "2v = " << v * 2 << endl;
	cout << "v/2 = " << v / 2.f << endl;
	// Hypotenuse calculation
	cout << "v.hypot() = " << v.hypot() << endl;   // = 5
	cout << "w.hypot() = " << w.hypot() << endl;   // = 13
	// Dot product
	cout << "v . w = " << v.dot(w) << endl;

	return 0;
}