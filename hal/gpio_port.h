//----------------------------------------------------------------------------------------------------------------------
// General Purpose I/O port
//----------------------------------------------------------------------------------------------------------------------
#pragma once
#ifndef _ETL_HAL_GPIOPOR_H_
#define _ETL_HAL_GPIOPOR_H_

namespace etl {
	namespace hal {

		template<typename PortRegister_>
		class GPIOPort {
			using Port = PortRegister_;
			typedef Register<typename PORT_::PointedT, PORT_::location-1>	DDR;
			typedef Register<typename PORT_::PointedT, PORT_::location-2>	PIN;
		};

	}
}

#endif // _ETL_HAL_GPIOPOR_H_