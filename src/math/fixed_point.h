//----------------------------------------------------------------------------------
// Fixed point arithmetic
//----------------------------------------------------------------------------------
#pragma once

#include <cstdint>

namespace etl::math {

	template<auto num_bits_>
	constexpr auto next_byte_size()
	{
		if constexpr(num_bits_ == 0)
			return 0;
		else
			return (num_bits_-1)/8+1;
	}

	// Internal storage types
	template<uint8_t byte_size_>
	struct storage_traits;

	template<>
	struct storage_traits<1> { using value_type = uint8_t; };

	template<>
	struct storage_traits<2> { using value_type = uint16_t; };

	template<>
	struct storage_traits<3> { using value_type = uint32_t; };

	template<>
	struct storage_traits<4> { using value_type = uint32_t; };

	// Fixed point number
	template<uint8_t integer_, uint8_t fractional_>
	struct UFixed
	{
		static constexpr uint8_t int_bits = integer_;
		static constexpr uint8_t fract_bits = fractional_;
		static constexpr uint8_t total_bits = integer_ + fractional_;
		static constexpr uint8_t byte_size = next_byte_size<total_bits>();
		using storage = typename storage_traits<byte_size>::value_type;

		// Construction
		UFixed() = default;

		template<uint8_t shift_, typename T>
		static UFixed fromRawUFixed (T x)
		{
			static_assert(shift_ <= fract_bits);
			constexpr auto shift = fract_bits-shift_;
			UFixed result;
			result.raw = storage(x)<<shift;
			return result;
		}

	private:
		storage raw;
	};

}	// namespace etl::math
