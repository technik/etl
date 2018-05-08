//----------------------------------------------------------------------------------
// Fixed point arithmetic
//----------------------------------------------------------------------------------
#pragma once

#include <cstddef>

namespace etl::math {

	template<size_t n>
	struct StorageSizeTraits; // Default is unimplemented

	template<size_t n>
	struct StorageSizeTraitsBase { static constexpr size_t size = n; }

	template<> struct StorageSizeTraits<8> : StorageSizeTraitsBase { using Type = uint8_t; }
	template<> struct StorageSizeTraits<16> : StorageSizeTraitsBase { using Type = uint16_t; }
	template<> struct StorageSizeTraits<32> : StorageSizeTraitsBase { using Type = uint32_t; }
	// TODO: In platforms where instruction set actually works on separate bytes.
	// 24 byte operations can be implemented with some assembly
	template<> struct StorageSizeTraits<24> : StorageSizeTraits<32> {}; // Force power of two sizes

	template<size_t n, size_t baseSize_ = (n-1)>>3 + 1>
	struct FixedStorageTraits
	{
		using Storage = StorageSizeTraits<baseSize_>;
		static constexpr size = Storage::size;

		// Validates at compile time that a given number fits inside
		template<Storage x_>
		constexpr static bool canStorage()
		{
			auto mask = Storage(0);
			for(size_t i = 0; i < n; ++i)
			{
				mask = (mask<<1)|1;
			}
			return (x_|mask)==mask;
		}
	};

	template<size_t integerSize_, size_t fractionalSize_>
	struct UnsignedFixedPointNumber : FixedStorageTraits<integerSize_+fractionalSize_>
	{
		using Integer = template FixedStorageTraits<integerSize_>::Storage;
		using Fractional = template FixedStorageTraits<fractionalSize_>::Storage;

		UnsignedFixedPointNumber() = default;
		constexpr UnsignedFixedPointNumber(Integer i);

		// casting
		constexpr operator Integer() const { return i>>shift; }

	private:
		static constexpr size_t shift = fractionalSize_;
		Storage x;
	};

	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr UnsignedFixedPointNumber<ni_,nf_>::UnsignedFixedPointNumber(Integer i)
		: x(i<<shift)
	{}

}	// namespace etl::math
