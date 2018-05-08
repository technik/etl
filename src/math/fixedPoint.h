//----------------------------------------------------------------------------------
// Fixed point arithmetic
//----------------------------------------------------------------------------------
#pragma once

#include <cstdint>

namespace etl::math {

	template<size_t n>
	struct StorageSizeTraits; // Default is unimplemented

	template<typename T>
	struct StorageSizeTraitsBase {
		static constexpr size_t size = sizeof(T);
		using Type = T;
	};

	template<> struct StorageSizeTraits<8> : StorageSizeTraitsBase<uint8_t> {};
	template<> struct StorageSizeTraits<16> : StorageSizeTraitsBase<uint16_t> {};
	template<> struct StorageSizeTraits<32> : StorageSizeTraitsBase<uint32_t> {};
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
	struct UFixed : FixedStorageTraits<integerSize_+fractionalSize_>
	{
		using Integer = template FixedStorageTraits<integerSize_>::Storage;
		using Fractional = template FixedStorageTraits<fractionalSize_>::Storage;

		UFixed() = default;
		constexpr UFixed(Integer i);

		// casting
		constexpr operator Integer() const { return i>>shift; }

	private:
		static constexpr size_t shift = fractionalSize_;
		Storage x;
	};

	// External operators
	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr UFixed<ni_,nf_> operator+(const UFixed_<ni_,nf_>& a, const UFixed<ni_,nf_>& b)
	{
		UFixed<ni_,nf_> result;
		result.x = a.x+b.x; // Maintain precision by avoiding castings
		return result;
	}

	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr UFixed<ni_,nf_> operator-(const UFixed_<ni_,nf_>& a, const UFixed<ni_,nf_>& b)
	{
		UFixed<ni_,nf_> result;
		result.x = a.x-b.x; // Maintain precision by avoiding castings
		return result;
	}

	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr UFixed<ni_,nf_> operator*(const UFixed_<ni_,nf_>& a, const UFixed<ni_,nf_>& b)
	{
		UFixed<ni_,nf_> result;
		// TODO: Can possibly have better precision using a bigger size temporary.
		result.x = (a.x*b.x)>>shift;
		return result;
	}

	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr UFixed<ni_,nf_> operator/(const UFixed_<ni_,nf_>& a, const UFixed<ni_,nf_>& b)
	{
		UFixed<ni_,nf_> result;
		result.x = (a.x/b.x)<<shift; // Maintain precision by avoiding castings
		return result;
	}

	// Inline implementation
	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr UFixed<ni_,nf_>::UFixed(Integer i)
		: x(i<<shift)
	{}

}	// namespace etl::math