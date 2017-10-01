//----------------------------------------------------------------------------------------------------------------------
// Mapping of common etl functionality to arduino-like syntax
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#ifndef _ETL_ARDUINOETL_H_
#define _ETL_ARDUINOETL_H_

#include "hal/gpio_pin.h"

// Pin state tags, useful for specialization of digitalWrite
struct PinLow_t {};
struct PinHigh_t {};

namespace {
	PinLow_t Low;
	PinHigh_t High;
}

// digitalWrite overloads
template<typename OutputPin_>
void digitalWrite(OutputPin_& _pin, PinLow_t) {
	_pin.setLow();
}

template<typename OutputPin_>
void digitalWrite(OutputPin_& _pin, PinHigh_t) {
	_pin.setHigh();
}

// Arduino boards
namespace etl { namespace arduino {
	// Pin properties group, so we can map pins using clearer syntax without redundancy
	template<typename Port_, uint8_t pin_>
	struct pin_traits {
		using Port = Port_;
		static constexpr uint8_t pin = pin_;
	};
}}

#ifdef ARDUINO_AVR_UNO
	// Digital pins
	using Pin0	= etl::arduino::pin_traits<etl::hal::PortD,0>;
	using Pin1	= etl::arduino::pin_traits<etl::hal::PortD,1>;
	using Pin2	= etl::arduino::pin_traits<etl::hal::PortD,2>;
	using Pin3	= etl::arduino::pin_traits<etl::hal::PortD,3>;
	using Pin4	= etl::arduino::pin_traits<etl::hal::PortD,4>;
	using Pin5	= etl::arduino::pin_traits<etl::hal::PortD,5>;
	using Pin6	= etl::arduino::pin_traits<etl::hal::PortD,6>;
	using Pin7	= etl::arduino::pin_traits<etl::hal::PortD,7>;
	using Pin8	= etl::arduino::pin_traits<etl::hal::PortB,0>;
	using Pin9	= etl::arduino::pin_traits<etl::hal::PortB,1>;
	using Pin10	= etl::arduino::pin_traits<etl::hal::PortB,2>;
	using Pin11	= etl::arduino::pin_traits<etl::hal::PortB,3>;
	using Pin12	= etl::arduino::pin_traits<etl::hal::PortB,4>;
	using Pin13 = etl::arduino::pin_traits<etl::hal::PortB,5>;
#endif // ARDUINO_AVR_UNO

// ------- Pin wrapping classes -----------
// Output Pin
template<typename Pin_>
struct OutputPin : etl::hal::OutputPin<typename Pin_::Port, Pin_::pin> {};
// Input Pin
template<typename Pin_>
struct InputPin : etl::hal::InputPin<typename Pin_::Port, Pin_::pin> {};
// Input/Output Pin
template<typename Pin_>
struct DigitalPin : etl::hal::GPIOPin<typename Pin_::Port, Pin_::pin> {};

#endif // _ETL_ARDUINOETL_H_