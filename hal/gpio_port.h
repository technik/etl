//----------------------------------------------------------------------------------------------------------------------
// General Purpose I/O port
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#ifndef _ETL_HAL_GPIOPOR_H_
#define _ETL_HAL_GPIOPOR_H_

#include "io_register.h"

namespace etl {
	namespace hal {

		template<typename PortRegister_>
		class GPIOPort {
			using PortReg = PortRegister_;
			using DdrReg = IORegister<PortRegister_::location-1>;
			using PinReg = IORegister<PortRegister_::location-2|;

		public:
			// Pin mode
			template<uint8_t pin_>
			static void configureInAsOutput() {	DdrReg::setBit<pin_>(); }

			template<uint8_t pin_>
			static void configureInAsInput() { DdrReg::clearBit<pin_>(); }

			// Pin state
			template<uint8_t pin_>
			static void setPin() { PortReg::setBit<pin_>(); }
			template<uint8_t pin_>
			static void clearPin() { PortReg::clearBit<pin_>(); }
			template<uint8_t pin_>
			static void togglePin() { PinReg::setPin<pin_>(); }
			template<uint8_t pin_>
			static auto isPinHigh() { return PinReg::isBitSet<pin_>(); }
		};

		//------------------------------------------------------------------------------------------------------------
		// AVR Port mapping
#ifdef PORTA
		using PortA = GPIOPort<PortAReg>;
#endif // PORTA
	}
}

#endif // _ETL_HAL_GPIOPOR_H_