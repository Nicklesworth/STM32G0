// -----------------------------------------------------------------------------
// This file is licensed under the terms described in the LICENSE
// file located in the root directory of this source tree.
// -----------------------------------------------------------------------------
#include "systime.h"
#include "timer_helpers.h"

TIM_HandleTypeDef hSysTimer;
volatile uint32_t timer_high = 0;

void SysTime_Init(TIM_TypeDef* TIMER, uint32_t IRQn, uint32_t irq_priority)
{
	uint32_t freq_in = Timer_GetClockFreq(TIMER);
	uint32_t prescaler = (freq_in / TICKS_PER_SECOND) - 1;
	
	hSysTimer.Instance               = TIMER;
	hSysTimer.Init.Prescaler         = prescaler;
	hSysTimer.Init.CounterMode       = TIM_COUNTERMODE_UP;
	hSysTimer.Init.Period            = 0xFFFF;
	hSysTimer.Init.ClockDivision     = 0;
	hSysTimer.Init.RepetitionCounter = 0;
	hSysTimer.Init.AutoReloadPreload = 0;
	HAL_TIM_Base_Init(&hSysTimer);
	HAL_TIM_Base_Start_IT(&hSysTimer);
	
	HAL_NVIC_SetPriority(IRQn, irq_priority, 0);
	HAL_NVIC_EnableIRQ(IRQn);
}

void SysTime_IRQ(void)
{
	timer_high += 0x10000;
}

ticks_t SysTime_GetTicks(void)
{
    uint32_t high1;
    uint32_t high2;
    uint16_t cnt;

    do
    {
        high1 = timer_high;
        cnt   = hSysTimer.Instance->CNT;
        high2 = timer_high;	// If overflow occurred in this routine, re-read the timer
    }
    while (high1 != high2);

    return high1 | cnt;
}

ticks_diff_t SysTime_GetDiff(ticks_t now)
{
	return 0;
}

void SysTime_Delay(ticks_t ticks)
{

}