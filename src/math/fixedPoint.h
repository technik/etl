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

	constexpr size_t nextByteSize(size_t n) {
		return ((n-1)/8 + 1)*8;
	}

	template<size_t n>
	struct FixedStorageTraits
	{
		using StorageTraits = StorageSizeTraits<nextByteSize(n)>;
		using Storage = typename StorageTraits::Type;
		static constexpr size_t size = StorageTraits::size;

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
		using Integer = typename FixedStorageTraits<integerSize_>::Storage;
		using Fractional = typename FixedStorageTraits<fractionalSize_>::Storage;

		UFixed() = default;
		constexpr UFixed(Integer i);

		// casting
		constexpr explicit operator Integer() const { return x>>shift; }

		// Basic arithmetic
		constexpr UFixed operator+(const UFixed& b) const;
		constexpr UFixed operator-(const UFixed& b) const;
		constexpr UFixed operator/(const UFixed& b) const;

		constexpr UFixed operator/(unsigned b) const;
		constexpr UFixed operator/(int b) const { return (*this)/unsigned(b); }

		constexpr bool operator==(const UFixed& b) const { return x==b.x; }
		constexpr bool operator==(unsigned b) const { return x==(b<<shift); }
		constexpr bool operator==(int b) const { return (*this)==unsigned(b); }

	private:
		static constexpr size_t shift = fractionalSize_;
		Storage x;
	};

	// External operators
	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr auto UFixed<ni_,nf_>::operator+(const UFixed& b) const -> UFixed
	{
		UFixed<ni_,nf_> result;
		result.x = x+b.x; // Maintain precision by avoiding castings
		return result;
	}

	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr auto UFixed<ni_,nf_>::operator-(const UFixed& b) const -> UFixed
	{
		UFixed<ni_,nf_> result;
		result.x = x-b.x; // Maintain precision by avoiding castings
		return result;
	}

	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr auto UFixed<ni_,nf_>::operator/(const UFixed& b) const -> UFixed
	{
		UFixed<ni_,nf_> result;
		result.x = (x/b.x)<<shift; // Maintain precision by avoiding castings
		return result;
	}

	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr auto UFixed<ni_,nf_>::operator/(unsigned b) const -> UFixed
	{
		UFixed<ni_,nf_> result;
		result.x = x/b;
		return result;
	}

	// Inline implementation
	//------------------------------------------------------------------------------
	template<size_t ni_, size_t nf_>
	constexpr UFixed<ni_,nf_>::UFixed(Integer i)
		: x(i<<shift)
	{}

}	// namespace etl::math
