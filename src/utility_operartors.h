////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Standard templates library. Freestanding implementation.
// Created by Carmelo J. Fern�ndez-Ag�era Tortosa, a.k.a. Technik
// On March 15th, 2012
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma once

namespace std
{
	// Inequality operator
	template<class T>
	inline bool operator != (const T& a, const T& b)
	{
		return ! (a == b);
	}
	// bigger than comparison
	template<class T>
	inline bool operator > ( const T& a, const T& b)
	{
		return b < a;
	}
	// lessOrEqualThan comparison
	template<class T>
	inline bool operator <= (const T& a, const T& b)
	{
		return ! (b < a);
	}
	// moreOrEqualThan comparison
	template<class T>
	inline bool operator >= (const T& a, const T& b)
	{
		return !(a < b);
	}
}	// namespace std