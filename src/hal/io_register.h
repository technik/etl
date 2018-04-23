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

		template<std::ptrdiff_t location_>
		struct IORegister {
			static constexpr auto location = location_;
			using value = std::uint8_t;
			using reference = volatile value&;
			using pointer = volatile value*;

			// Run time accessors
			void	operator=	(value _x)	{ *reinterpret_cast<pointer>(location_) = _x; }
			operator value		()	const 	{ return *reinterpret_cast<pointer>(location_); }
			operator reference	()			{ return *reinterpret_cast<pointer>(location_); }

			// Individual pin management
			template<uint8_t bit_>
			static void setBit() {
				*reinterpret_cast<pointer>(location_) |= bitmask<bit_>();
			}

			template<uint8_t bit_>
			static void clearBit() {
				*reinterpret_cast<pointer>(location_) &= ~bitmask<bit_>();
			}

			template<uint8_t bit_>
			static value isBitSet() {
				return *reinterpret_cast<pointer>(location_) & bitmask<bit_>();
			}

			// Delete default methods
			IORegister(const IORegister&) = delete;
			IORegister& operator=(const IORegister&) = delete;

		private:
			template<uint8_t bit_>
			static constexpr uint8_t bitmask()	{
				static_assert(bit_<8, "bit_ is out of the scope of this register");
				return (1<<bit_);
			}

		};

	}
}

#endif // _ETL_HAL_IOREGISTER_H_