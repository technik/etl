//-----------------------------------------------------------------------------
// Animation system unit test
//-----------------------------------------------------------------------------

#include <cassert>
#include <math/fixedPoint.h>

using Real = etl::math::UFixed<11,5>;

int main()
{
	Real a;
	Real b;
	a = 500;
	b = 200;
	auto t = (a+b)/2;
	assert (t == 350);
	a = 1023;
	b = a;
	assert ((a+b)/2 == 1023);
	return 0;
}