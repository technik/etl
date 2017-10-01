//----------------------------------------------------------------------------------------------------------------------
// Mapping of common etl functionality to arduino-like syntax
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#ifndef _ETL_ARDUINOETL_H_
#define _ETL_ARDUINOETL_H_

#include "etl/hal/gpio_pin.h"

// Pin state tags, useful for specialization of digitalWrite
struct PinLow_t;
struct PinHigh_t;

namespace {
	PinLow_t Low;
	PinHigh_t High;
}

// digitalWrite overloads
template<typename OutputPin_>
void digitalWrite(const OutputPin_& _pin, PinLow_t) {
	_pin.setLow();
}

template<typename OutputPin_>
void digitalWrite(const OutputPin_& _pin, PinHigh_t) {
	_pin.setHigh();
}

#endif // _ETL_ARDUINOETL_H_