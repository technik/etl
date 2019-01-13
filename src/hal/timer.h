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
	struct Timer {};


#if defined (__AVR_ATmega328P__)
	using Tccr1a = IORegister<0x80>;
	using Tccr1b = IORegister<0x81>;
	using Tccr1c = IORegister<0x82>;

	using Tcnt1 = IORegister16<0x84>;
	using Icr1 = IORegister16<0x86>;
	using Ocr1a = IORegister16<0x88>;
	using Ocr1b = IORegister16<0x8a>;

	using Timsk1 = IORegister<0x6f>;
	using Tifr1 = IORegister<0x36>;
#endif
#if defined (__AVR_ATmega128__)
	struct Tccr1a : IORegister<0x4f>
	{
		enum CompareOutMode
		{
			Diconected = 0,
			ToggleOnCompareMatch = 1,
			ClearOnCompareMatch = 2,
			SetOnCompareMatch = 3
		};

		static constexpr uint8_t MaskCOMA = (1<<7)|(1<<6);
		static constexpr uint8_t MaskCOMB = (1<<5)|(1<<4);
		static constexpr uint8_t MaskCOMC = (1<<3)|(1<<2);

		static void setChannelA(CompareOutMode compareMode)
		{
			auto comAVal = ((uint8_t)compareMode) << 6;
			setMasked(comAVal, MaskCOMA);
		}

		static void setChannelB(CompareOutMode compareMode)
		{
			auto comAVal = ((uint8_t)compareMode) << 4;
			setMasked(comAVal, MaskCOMB);
		}

		static void setChannelC(CompareOutMode compareMode)
		{
			auto comAVal = ((uint8_t)compareMode) << 2;
			setMasked(comAVal, MaskCOMC);
		}
	};

	struct Tccr1b : IORegister<0x4e>
	{
		enum ClockSelect
		{
			stop = 0,
			f_clk = 1,
			f_clk_div8 = 2,
			f_clk_div64 = 3,
			f_clk_div256 = 4,
			f_clk_div1024 = 5,
			ext_fall = 6,
			ext_rise = 7 
		};
	};
	using Tccr1c = IORegister<0x7a>;

	using Tcnt1 = IORegister16<0x4c>;
	using Icr1 = IORegister16<0x46>;
	using Ocr1a = IORegister16<0x4a>;
	using Ocr1b = IORegister16<0x48>;

	using Timsk = IORegister<0x57>;
	using Tifr = IORegister<0x56>;

	struct Timer1
	{
		using ClockSelect = Tccr1b::ClockSelect;

		template<ClockSelect clk>
		void setClockSource()
		{
			Tccr1b::setMasked((uint8_t)clk, 0x07);
		}
		
		Tccr1b tccrb;
	};
#endif

}	// namespace etl::hal