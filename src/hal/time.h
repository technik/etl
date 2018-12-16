//----------------------------------------------
// Basic timing
//----------------------------------------------
#pragma once
#include <chrono>

namespace etl::hal {

	void init_system_clock();
	
	// Uses timer1 with 1/8 prescaler for a resolution of half a microsecond
	class system_clock
	{
	public:
		using rep = uint32_t;
		using period = std::ratio<1,16000000/8>;
		using duration = std::chrono::duration<rep,period>;
		using time_point = std::chrono::time_point<system_clock>;

		static time_pont now();
	};
}