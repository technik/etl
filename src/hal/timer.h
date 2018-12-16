//----------------------------------------------------------------------------------------------------------------------
// Timer peripherals
//----------------------------------------------------------------------------------------------------------------------
#pragma once

#include "io_register.h"

namespace etl::hal {

	template<
		class Tcnt_,
		class OcrA, class OcrB,
		class TccrA, class TccrB, class TccrC,
		class Tifr, class Timsk>
	struct Timer
	{
		//
	};


#if defined (__AVR_ATmega328P__)
	using Tccr1a = IORegister<0x80>;
	using Tccr12 = IORegister<0x81>;
	using Tccr1c = IORegister<0x82>;

	using Tcnt1 = IORegister16<0x84>;
	using Icr1 = IORegister16<0x86>;
	using Ocr1a = IORegister16<0x88>;
	using Ocr1b = IORegister16<0x8a>;

	using Timsk1 = IORegister<0x6f>;
	using Tifr1 = IORegister<0x36>;
#endif

}	// namespace etl::hal