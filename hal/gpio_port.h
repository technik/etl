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
			using PinReg = IORegister<PortRegister_::location-2>;

		public:
			// Pin mode
			template<uint8_t pin_>
			static void configurePinAsOutput() { DdrReg::template setBit<pin_>(); }

			template<uint8_t pin_>
			static void configurePinAsInput() { DdrReg::template clearBit<pin_>(); }

			// Pin state
			template<uint8_t pin_>
			static void setPin() { PortReg::template setBit<pin_>(); }
			template<uint8_t pin_>
			static void clearPin() { PortReg::template clearBit<pin_>(); }
			template<uint8_t pin_>
			static void togglePin() { PinReg::template setBit<pin_>(); }
			template<uint8_t pin_>
			static typename PinReg::value isPinHigh() { return PinReg::template isBitSet<pin_>(); }
		};

		//------------------------------------------------------------------------------------------------------------
		// AVR Port mapping
#ifdef PORTA
		using PortA = GPIOPort<PortAReg>;
#endif // PORTA
	}
}

#endif // _ETL_HAL_GPIOPOR_H_