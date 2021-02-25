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
		using PinEReg	= IORegister<0x2c>;
		using DdrEReg	= IORegister<0x2d>;
		using PortEReg	= IORegister<0x2e>;
		using PinFReg	= IORegister<0x2f>;
		using DdrFReg	= IORegister<0x30>;
		using PortFReg	= IORegister<0x31>;
		using PinGReg	= IORegister<0x32>;
		using DdrGReg	= IORegister<0x33>;
		using PortGReg	= IORegister<0x34>;
		using PinHReg	= IORegister<0x100>;
		using DdrHReg	= IORegister<0x101>;
		using PortHReg	= IORegister<0x102>;
		using PinJReg	= IORegister<0x103>;
		using DdrJReg	= IORegister<0x104>;
		using PortJReg	= IORegister<0x105>;
		using PinKReg	= IORegister<0x106>;
		using DdrKReg	= IORegister<0x107>;
		using PortKReg	= IORegister<0x108>;
		using PinLReg	= IORegister<0x109>;
		using DdrLReg	= IORegister<0x10a>;
		using PortLReg	= IORegister<0x10b>;
#endif // __AVR_ATmega328P__ || __AVR_ATmega2560__

#ifdef __AVR_ATmega128__ 
		using PortAReg = IORegister<0x3b>;
		using PortBReg = IORegister<0x38>;
		using PortCReg = IORegister<0x35>;
		using PortDReg = IORegister<0x32>;
		using PortEReg = IORegister<0x23>;
		using PortFReg = IORegister<0x82>;
		using PortGReg = IORegister<0x85>;
#endif // __AVR_ATmega128__
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
#ifdef PORTE
		using PortE = GPIOPort<PortEReg>;
#endif
#ifdef PORTF
		using PortF = GPIOPort<PortFReg>;
#endif
#ifdef PORTG
		using PortG = GPIOPort<PortGReg>;
#endif
#ifdef PORTH
		using PortH = GPIOPort<PortHReg>;
#endif
#ifdef PORTJ
		using PortJ = GPIOPort<PortJReg>;
#endif
#ifdef PORTK
		using PortK = GPIOPort<PortKReg>;
#endif
#ifdef PORTJ
		using PortL = GPIOPort<PortLReg>;
#endif
	}
}

#endif // _ETL_HAL_GPIOPOR_H_