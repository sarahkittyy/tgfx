#include <iomanip>
#include <iostream>
#include <thread>
#include "tgfx/tgfx.hpp"

int main()
{
	using std::cout;
	using std::endl;

	tgfx::time t1(tgfx::time::seconds(5));
	tgfx::time t2(tgfx::time::milliseconds(3250));
	tgfx::time t3(tgfx::time::nanoseconds(6000000));

	// Conversion operations
	cout << t1.as_seconds() << endl;		// = 5
	cout << t1.as_milliseconds() << endl;   // = 5000
	cout << t1.as_nanoseconds() << endl;	// = 5000000000

	// Binary operands.
	cout << (t1 + t2).as_seconds() << endl;		   // = 8.25
	cout << (t2 + t3).as_milliseconds() << endl;   // = 3256
	cout << (t1 - t3).as_nanoseconds() << endl;	// = 4994000000

	// Comparisons
	cout << std::boolalpha;
	cout << (t1 < t2) << endl;									   // false
	cout << (t1 > t2) << endl;									   // true
	cout << (t1 == t2 + tgfx::time::milliseconds(1750)) << endl;   // true

	///////////////////////////////

	// Start a clock
	tgfx::clock clock;

	// - sleep for 2 seconds -
	using namespace std::chrono_literals;
	cout << "sleeping for 2 seconds..." << endl;
	std::this_thread::sleep_for(2s);
	// - - -

	// Print the elapsed clock time.
	cout << clock.elapsed().as_seconds() << endl;   // = around 2
	// Restart the clock.
	clock.restart();
	// Print the now elapsed clock time.
	cout << clock.elapsed().as_seconds() << endl;   // = around 0

	return 0;
}