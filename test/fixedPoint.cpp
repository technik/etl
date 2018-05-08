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
	assert ((a+b)/2 == 350);
	return 0;
}