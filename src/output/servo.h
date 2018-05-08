//----------------------------------------------------------------------------------------------------------------------
// Analog servos
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#include <hal/gpio_pin.h>

namespace etl::output {

	template<class Timer, class OutputPin_>
	struct PWMServo
	{
		void setPosition(Radianls) const;
		void setPosition(Degrees) const;
	};

}	// namespace etl::output