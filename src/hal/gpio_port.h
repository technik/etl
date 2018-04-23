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
			static typename PinReg::value isPinHigh() volatile { return PinReg::template isBitSet<pin_>(); }
		};

		//------------------------------------------------------------------------------------------------------------
		// AVR Port register mapping
#if defined (__AVR_ATmega2560__)
		using PinAReg	= IORegister<0x20>;
		using DdrARReg	= IORegister<0x21>;
		using PortAReg	= IORegister<0x22>;
#endif

#if defined (__AVR_ATmega328P__) || defined (__AVR_ATmega2560__)
		using PinBReg	= IORegister<0x23>;
		using DdrBReg	= IORegister<0x24>;
		using PortBReg	= IORegister<0x25>;
		using PinCReg	= IORegister<0x26>;
		using DdrCReg	= IORegister<0x27>;
		using PortCReg	= IORegister<0x28>;
		using PinDReg	= IORegister<0x29>;
		using DdrDReg	= IORegister<0x2a>;
		using PortDReg	= IORegister<0x2b>;
#endif // __AVR_ATmega328P__ || __AVR_ATmega2560__
		//------------------------------------------------------------------------------------------------------------
		// AVR Port mapping
#ifdef PORTA
		using PortA = GPIOPort<PortAReg>;
#endif // PORTA
#ifdef PORTB
		using PortB = GPIOPort<PortBReg>;
#endif
#ifdef PORTC
		using PortC = GPIOPort<PortCReg>;
#endif
#ifdef PORTD
		using PortD = GPIOPort<PortDReg>;
#endif
	}
}

#endif // _ETL_HAL_GPIOPOR_H_