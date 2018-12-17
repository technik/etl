//----------------------------------------------------------------------------------------------------------------------
// Buran autopilot
// Created by Carmelo J. Fdez-Agüera Tortosa (a.k.a. Technik)
// On 2013/Aug/03
//----------------------------------------------------------------------------------------------------------------------
// Placement new

#ifndef _BBDUINO_CORE_MEMORY_NEW_H_
#define _BBDUINO_CORE_MEMORY_NEW_H_

#include <stddef.h>

void * operator new (size_t, void *);

#endif // _BBDUINO_CORE_MEMORY_NEW_H_