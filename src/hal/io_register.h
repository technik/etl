//----------------------------------------------------------------------------------------------------------------------
// Registers inside the I/O mapping memory
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#ifndef _ETL_HAL_IOREGISTER_H_
#define _ETL_HAL_IOREGISTER_H_

#include <cstddef>
#include <cstdint>
#include <avr/io.h>

namespace etl {
	namespace hal {

		template<class RegT_, std::ptrdiff_t location_>
		struct RegisterBase
		{
			static constexpr std::ptrdiff_t	location = location_;
			using value = RegT_;
			using reference = volatile value&;
			using pointer = volatile value*;

			// Run time accessors
			void	operator=	(value _x)	{ *reinterpret_cast<pointer>(location_) = _x; }
			operator value		()	const 	{ return *reinterpret_cast<pointer>(location_); }
			operator reference	()			{ return *reinterpret_cast<pointer>(location_); }

			// Individual pin management
			template<value bit_>
			static void setBit() {
				*reinterpret_cast<pointer>(location_) |= bitmask<bit_>();
			}

			template<value bit_>
			static void clearBit() {
				*reinterpret_cast<pointer>(location_) &= ~bitmask<bit_>();
			}

			template<value bit_>
			static value isBitSet() {
				return *reinterpret_cast<pointer>(location_) & bitmask<bit_>();
			}

		protected:
			RegisterBase() = default; // This prevents the class to be instantiated without deriving

			template<value bit_>
			static constexpr value bitmask()	{
				static_assert(bit_<8*sizeof(value), "bit_ is out of the scope of this register");
				return (1<<bit_);
			}
		};

		template<std::ptrdiff_t location_>
		struct IORegister : RegisterBase<std::uint8_t, location_>
		{
			// Delete default methods
			IORegister(const IORegister&) = delete;
			IORegister& operator=(const IORegister&) = delete;
		};

		template<std::ptrdiff_t location_>
		struct IORegister16 : RegisterBase<std::uint16_t, location_>
		{
			// Delete default methods
			IORegister(const IORegister&) = delete;
			IORegister& operator=(const IORegister&) = delete;

			// High and Low bytes of this register
			using low = IORegister<location_>;
			using high = IORegister<location_+1>;
		};

	}
}

#endif // _ETL_HAL_IOREGISTER_H_