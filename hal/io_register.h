//----------------------------------------------------------------------------------------------------------------------
// Registers inside the I/O mapping memory
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#ifndef _ETL_HAL_IOREGISTER_H_
#define _ETL_HAL_IOREGISTER_H_

#include <avr_stl/cstddef>
#include <avr_stl/cstdint>
#include <avr/io.h>

namespace etl {
	namespace hal {

		template<std::ptrdiff_t location_>
		struct IORegister {
			static constexpr auto location = location_;
			using value = std::uint8_t;
			using reference = volatile value&;
			using pointer = volatile value*;

			// Run time accessors
			void	operator=	(value _x)	{ *reinterpret_cast<pointer>(location_) = _x; }
			operator value		()	const	{ return *reinterpret_cast<pointer>(location_); }
			operator reference	()			{ return *reinterpret_cast<pointer>(location_); }

			// Individual pin management
			template<uint8_t pin_>
			static void setBit() {
					reference(*this) |= bitmask<pin_>();
			}

			template<uint8_t pin_>
			static void clearBit() {
				reference(*this) &= ~bitmask<pin_>();
			}

		private:
			template<uint8_t pin_>
			static constexpr uint8_t bitmask()	{
				static_assert(pin_<8, "pin_ is out of the scope of this register");
				return (1<<pin_);
			}

		};

		//------------------------------------------------------------------------------------------------------------
		// AVR Port mapping
#if defined (__AVR_ATmega2560__)
		typedef IORegister<0x20> PinAReg;
		typedef IORegister<0x21> DdrARReg;
		typedef IORegister<0x22> PortAReg;
#endif


	}
}

#endif // _ETL_HAL_IOREGISTER_H_