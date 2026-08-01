// -----------------------------------------------------------------------------
// This file is licensed under the terms described in the LICENSE
// file located in the root directory of this source tree.
// -----------------------------------------------------------------------------
#ifndef SYSTIME_H_
#define SYSTIME_H_

#include "local_types.h"
#include "stm32g0xx_hal.h"

#define TICKS_PER_MICROSECOND	1
#define TICKS_PER_MILLISECOND	(TICKS_PER_MICROSECOND * 1000)
#define TICKS_PER_SECOND		(TICKS_PER_MILLISECOND * 1000)

typedef uint32_t ticks_t;
typedef int32_t ticks_diff_t;

extern TIM_HandleTypeDef hSysTimer;

void SysTime_Init(TIM_TypeDef* TIMER, uint32_t IRQn, uint32_t irq_priority);	// Suggest using TIM6 or TIM7 as they're the most basic
void SysTime_IRQ(void);
ticks_t SysTime_GetTicks(void);
ticks_diff_t SysTime_GetDiff(ticks_t now);
void SysTime_Delay(ticks_t ticks);

#endif // SYSTIME_H_
