//-------------------------------------------------------------
// Copyright 2021 Carmelo J Fdez-Aguera
// 
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software
// and associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
// 
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#pragma once
#include "../gpio_pin.h"

using Pin0 = etl::hal::GPIOPin<etl::hal::PortE,0>;
using Pin1 = etl::hal::GPIOPin<etl::hal::PortE,1>;
using Pin2 = etl::hal::GPIOPin<etl::hal::PortE,4>;
using Pin3 = etl::hal::GPIOPin<etl::hal::PortE,5>;
using Pin4 = etl::hal::GPIOPin<etl::hal::PortG,5>;
using Pin5 = etl::hal::GPIOPin<etl::hal::PortE,3>;
using Pin6 = etl::hal::GPIOPin<etl::hal::PortH,3>;
using Pin7 = etl::hal::GPIOPin<etl::hal::PortH,4>;

using Pin8 = etl::hal::GPIOPin<etl::hal::PortH,5>;
using Pin9 = etl::hal::GPIOPin<etl::hal::PortH,6>;
using Pin10 = etl::hal::GPIOPin<etl::hal::PortB,4>;
using Pin11 = etl::hal::GPIOPin<etl::hal::PortB,5>;
using Pin12 = etl::hal::GPIOPin<etl::hal::PortB,6>;
using Pin13 = etl::hal::GPIOPin<etl::hal::PortB,7>;

using LedPin = Pin13::Out;

using Pin14 = etl::hal::GPIOPin<etl::hal::PortJ,1>;
using Pin15 = etl::hal::GPIOPin<etl::hal::PortJ,0>;
using Pin16 = etl::hal::GPIOPin<etl::hal::PortH,1>;
using Pin17 = etl::hal::GPIOPin<etl::hal::PortH,0>;
using Pin18 = etl::hal::GPIOPin<etl::hal::PortD,3>;
using Pin19 = etl::hal::GPIOPin<etl::hal::PortD,2>;
using Pin20 = etl::hal::GPIOPin<etl::hal::PortD,1>;
using Pin21 = etl::hal::GPIOPin<etl::hal::PortD,0>;

// Bottom header
using Pin22 = etl::hal::GPIOPin<etl::hal::PortA,0>;
using Pin23 = etl::hal::GPIOPin<etl::hal::PortA,1>;
using Pin24 = etl::hal::GPIOPin<etl::hal::PortA,2>;
using Pin25 = etl::hal::GPIOPin<etl::hal::PortA,3>;
using Pin26 = etl::hal::GPIOPin<etl::hal::PortA,4>;
using Pin27 = etl::hal::GPIOPin<etl::hal::PortA,5>;
using Pin28 = etl::hal::GPIOPin<etl::hal::PortA,6>;
using Pin29 = etl::hal::GPIOPin<etl::hal::PortA,7>;

using Pin30 = etl::hal::GPIOPin<etl::hal::PortC,7>;
using Pin31 = etl::hal::GPIOPin<etl::hal::PortC,6>;
using Pin32 = etl::hal::GPIOPin<etl::hal::PortC,5>;
using Pin33 = etl::hal::GPIOPin<etl::hal::PortC,4>;
using Pin34 = etl::hal::GPIOPin<etl::hal::PortC,3>;
using Pin35 = etl::hal::GPIOPin<etl::hal::PortC,2>;
using Pin36 = etl::hal::GPIOPin<etl::hal::PortC,1>;
using Pin37 = etl::hal::GPIOPin<etl::hal::PortC,0>;

using Pin38 = etl::hal::GPIOPin<etl::hal::PortD,7>;
using Pin39 = etl::hal::GPIOPin<etl::hal::PortG,2>;
using Pin40 = etl::hal::GPIOPin<etl::hal::PortG,1>;
using Pin41 = etl::hal::GPIOPin<etl::hal::PortG,0>;

using Pin42 = etl::hal::GPIOPin<etl::hal::PortL,7>;
using Pin43 = etl::hal::GPIOPin<etl::hal::PortL,6>;
using Pin44 = etl::hal::GPIOPin<etl::hal::PortL,5>;
using Pin45 = etl::hal::GPIOPin<etl::hal::PortL,4>;
using Pin46 = etl::hal::GPIOPin<etl::hal::PortL,3>;
using Pin47 = etl::hal::GPIOPin<etl::hal::PortL,2>;
using Pin48 = etl::hal::GPIOPin<etl::hal::PortL,1>;
using Pin49 = etl::hal::GPIOPin<etl::hal::PortL,0>;

using Pin50 = etl::hal::GPIOPin<etl::hal::PortB,3>;
using Pin51 = etl::hal::GPIOPin<etl::hal::PortB,2>;
using Pin52 = etl::hal::GPIOPin<etl::hal::PortB,1>;
using Pin53 = etl::hal::GPIOPin<etl::hal::PortB,0>;

// Analog headers
using Pin54 = etl::hal::GPIOPin<etl::hal::PortF,0>;
using Pin55 = etl::hal::GPIOPin<etl::hal::PortF,1>;
using Pin56 = etl::hal::GPIOPin<etl::hal::PortF,2>;
using Pin57 = etl::hal::GPIOPin<etl::hal::PortF,3>;
using Pin58 = etl::hal::GPIOPin<etl::hal::PortF,4>;
using Pin59 = etl::hal::GPIOPin<etl::hal::PortF,5>;
using Pin60 = etl::hal::GPIOPin<etl::hal::PortF,6>;
using Pin61 = etl::hal::GPIOPin<etl::hal::PortF,7>;

using Pin62 = etl::hal::GPIOPin<etl::hal::PortK,0>;
using Pin63 = etl::hal::GPIOPin<etl::hal::PortK,1>;
using Pin64 = etl::hal::GPIOPin<etl::hal::PortK,2>;
using Pin65 = etl::hal::GPIOPin<etl::hal::PortK,3>;
using Pin66 = etl::hal::GPIOPin<etl::hal::PortK,4>;
using Pin67 = etl::hal::GPIOPin<etl::hal::PortK,5>;
using Pin68 = etl::hal::GPIOPin<etl::hal::PortK,6>;
using Pin69 = etl::hal::GPIOPin<etl::hal::PortK,7>;