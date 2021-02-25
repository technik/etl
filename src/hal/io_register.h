//----------------------------------------------------------------------------------------------------------------------
// Registers inside the I/O mapping memory
//----------------------------------------------------------------------------------------------------------------------
#pragma once

#include <cstddef>
#include <cstdint>
#ifndef SITL
#include <avr/io.h>
#endif

namespace etl {
	namespace hal {

#ifdef SITL
		template<class RegT_, std::ptrdiff_t location_>
		struct HWRegisterAccess
		{
			using value = RegT_;
			using reference = value&;
			using pointer = value*;

			static pointer getHwPtr() { return &sHWReg; }

		private:
			static inline RegT_ sHWReg{};
		};
#else
		template<class RegT_, std::ptrdiff_t location_>
		struct HWRegisterAccess
		{
			using value = RegT_;
			using reference = volatile value&;
			using pointer = volatile value*;

			static inline pointer getHwPtr() { return reinterpret_cast<pointer>(location_); }
		};
#endif

		template<class RegT_, std::ptrdiff_t location_>
		struct RegisterBase : HWRegisterAccess<RegT_,location_>
		{
			static constexpr std::ptrdiff_t	location = location_;
			using value = HWRegisterAccess<RegT_,location_>::value;
			using reference = HWRegisterAccess<RegT_,location_>::reference;
			using pointer = HWRegisterAccess<RegT_,location_>::pointer;
			using HWRegisterAccess<RegT_, location_>::getHwPtr; // Work around GCC complaining about getHwPtr

			// Run time accessors (static)
			static void set(value _x)
			{
				*getHwPtr() = _x;
			}

			static void setOr(value _x)
			{
				*getHwPtr() |= _x;
			}

			static void setAnd(value _x)
			{
				*getHwPtr() &= _x;
			}

			static value read()
			{
				return *getHwPtr();
			}

			static void setMasked(value val, value mask)
			{
				auto regVal = read() & ~mask;
				set(val | regVal);
			}

			// Run time accessors (instance)
			void	operator=	(value _x)	{ *getHwPtr() = _x; }
			operator value		()	const 	{ return *getHwPtr(); }
			operator reference	()			{ return *getHwPtr(); }


			// Individual pin management
			template<value bit_>
			static void setBit() {
				*getHwPtr() |= bitmask<bit_>();
			}

			template<value bit_>
			static void clearBit() {
				*getHwPtr() &= ~bitmask<bit_>();
			}

			template<value bit_>
			static value isBitSet() {
				return *getHwPtr() & bitmask<bit_>();
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
			IORegister() = default;
			// Delete default methods
			IORegister(const IORegister&) = delete;
			IORegister& operator=(const IORegister&) = delete;
			using RegisterBase<std::uint8_t, location_>::operator=;
		};

		template<std::ptrdiff_t location_>
		struct IORegister16 : RegisterBase<std::uint16_t, location_>
		{
			IORegister16() = default;
			// Delete default methods
			IORegister16(const IORegister16&) = delete;
			IORegister16& operator=(const IORegister16&) = delete;
			using RegisterBase<std::uint16_t, location_>::operator=;

			// High and Low bytes of this register
			using Low = IORegister<location_>;
			using High = IORegister<location_+1>;
		};

	}
}
