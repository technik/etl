//----------------------------------------------------------------------------------------------------------------------
// General Purpose I/O pin
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#ifndef _ETL_HAL_GPIOPIN_H_
#define _ETL_HAL_GPIOPIN_H_

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
		class GPIOPin : public InputPin_base, public OutputPin_base{
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
		class OutputPin : public OutputPin_base {
		public:
			OutputPin(); // Configures pin direction
		};

		template<class Port_, uint8_t pin_>
		class InputPin : public InputPin_base {
		public:
			InputPin(); // Configures pin direction
		};

	}
}

#endif // _ETL_HAL_GPIOPIN_H_