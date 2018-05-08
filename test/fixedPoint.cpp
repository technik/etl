//-----------------------------------------------------------------------------
// Animation system unit test
//-----------------------------------------------------------------------------

#include <anim/poses.h>
#include <anim/interpolator.h>

using AnimPose = anim::Pose<25>;

int main()
{
	AnimPose a;
	a.bone(0) = 0;
	AnimPose b;
	b.bone(0) = 10;

	constexpr int nSteps = 20;
	AnimPose solvedPoses[nSteps + 1];
	AnimInterpolator linear;
	linear.solve(a,b,nSteps,solvedPoses);

	return 0;
}