//----------------------------------------------------------------------------------------------------------------------
// limited size vector
//----------------------------------------------------------------------------------------------------------------------
#pragma once

#include <cstdint>

namespace etl {
	
	// A container with vector interface, but with static array-like memory of capacitt N
	template<class T, std::size_t N> struct limited_vector
	{
		using value_type = T;
		using pointer = T*;
		using const_pointer = const T*;
		using reference = T&;
		using const_reference = const T&;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;
		using iterator = T*;
		using const_iterator = const T*;

		limited_vector() : _m_end(&_m_elements[0]) {}
		constexpr limited_vector(std::size_t n) : _m_end(&_m_elements[0]) {}

		// Iterator access
		iterator					begin	() noexcept			{ return _m_elements; }
		constexpr const_iterator	begin	() const noexcept	{ return _m_elements; }
		iterator					end		() noexcept			{ return _m_end; }
		const_iterator				end		() const noexcept	{ return _m_end; }

		// Size
		bool				empty	() const noexcept { return false; }
		size_type 			size	() const noexcept { return end()-begin(); }
		constexpr size_type capacity() const noexcept { return N; }

		reference					operator[]	(size_type n)					{ return _m_elements[n]; }
		constexpr const_reference	operator[]	(size_type n)	const			{ return _m_elements[n]; }

		reference					at			(size_type n)					{ return _m_elements[n]; }
		constexpr const_reference	at			(size_type n)	const			{ return _m_elements[n]; }
		reference					front		()								{ return _m_elements[0]; }
		constexpr const_reference	front		()				const			{ return _m_elements[0]; }
		reference					back		()								{ return _m_end-1; }
		constexpr const_reference	back		()				const			{ return _m_end-1; }
		constexpr T*				data		()				noexcept		{ return _m_elements; }
		constexpr const T*			data		()				const noexcept	{ return _m_elements; }

	private:
		pointer _m_end = begin();
		T _m_elements[N];
	};
}