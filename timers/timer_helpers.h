// -----------------------------------------------------------------------------
// This file is licensed under the terms described in the LICENSE
// file located in the root directory of this source tree.
// -----------------------------------------------------------------------------
#ifndef TIMER_HELPERS_H_
#define TIMER_HELPERS_H_

#include "local_types.h"
#include "stm32g0xx_hal.h"

uint32_t Timer_GetClockFreq(TIM_TypeDef* TIMER);

#endif // TIMER_HELPERS_H_
