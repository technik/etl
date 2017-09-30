//----------------------------------------------------------------------------------------------------------------------
// General Purpose I/O pin
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#ifndef _ETL_HAL_GPIOPIN_H_
#define _ETL_HAL_GPIOPIN_H_

#include "gpio_port.h"

namespace etl {
	namespace hal {

		template<class Port_, uint8_t pin_>
		class OutputPin_base {
		public:
			void setLow 	();
			void setHigh	();
			void toggle		();
		};

		template<class Port_, uint8_t pin_>
		class InputPin_base {
		public:
			// TODO: Internal pull up?

			bool isLow		() const;
			bool isHigh		() const;
		};
	
		template<class Port_, uint8_t pin_>
		class GPIOPin : public InputPin_base<Port_,pin_>, public OutputPin_base<Port_,pin_>{
		public:
			// Configure pin direction
			void configureAsOutput	();
			void configureAsInput	();

			// Output
			void setLow 	();
			void setHigh	();
			void toggle		();

			// Input
			bool isLow		() const;
			bool isHigh		() const;
		};

		template<class Port_, uint8_t pin_>
		class OutputPin : public OutputPin_base<Port_,pin_> {
		public:
			OutputPin(); // Configures pin direction
		};

		template<class Port_, uint8_t pin_>
		class InputPin : public InputPin_base<Port_,pin_> {
		public:
			InputPin(); // Configures pin direction
		};

	}
}

#endif // _ETL_HAL_GPIOPIN_H_