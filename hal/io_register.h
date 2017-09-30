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
			using reference = value&;
			using pointer = value*;

			void	operator=					(value _x)	{ *reinterpret_cast<volatile pointer>(location_) = _x; }
			operator value				()			const	{ return *reinterpret_cast<volatile pointer>(location_); }
			operator volatile reference	()					{ return *reinterpret_cast<volatile pointer>(location_); }
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