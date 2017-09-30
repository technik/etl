//----------------------------------------------------------------------------------------------------------------------
// General Purpose I/O pin
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#ifndef _ETL_HAL_GPIOPIN_H_
#define _ETL_HAL_GPIOPIN_H_

#include "gpio_port.h"

namespace etl {
	namespace hal {

		//----------------------------------------------------------------------
		template<class Port_, uint8_t pin_>
		struct OutputPin_base {
			void setLow 	() { Port_::clear<pin_>();	}
			void setHigh	() { Port_::set<pin_>();	}
			void toggle		() { Port_::toggle<pin_>();	}
		};

		//----------------------------------------------------------------------
		template<class Port_, uint8_t pin_>
		struct InputPin_base {
			bool isHigh		() const { return Port_::isPinHigh<pin_>(); }
		};
	
		//----------------------------------------------------------------------
		template<class Port_, uint8_t pin_>
		struct GPIOPin
			: InputPin_base<Port_,pin_>
			, OutputPin_base<Port_,pin_>{
		public:
			// Configure pin direction
			void configureAsOutput	() { Port_::configurePinAsOutput<pin_>(); }
			void configureAsInput	() { Port_::configurePinAsInput<pin_>(); }
		};

		//----------------------------------------------------------------------
		template<class Port_, uint8_t pin_>
		struct OutputPin : OutputPin_base<Port_,pin_> {
		public:
			OutputPin() { Port_::configurePinAsOutput<pin_>(); }
		};

		//----------------------------------------------------------------------
		template<class Port_, uint8_t pin_>
		struct InputPin : InputPin_base<Port_,pin_> {
		public:
			InputPin() { Port_::configurePinAsInput<pin_>(); }
		};

	}
}

#endif // _ETL_HAL_GPIOPIN_H_