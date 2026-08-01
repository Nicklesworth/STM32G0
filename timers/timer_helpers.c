// -----------------------------------------------------------------------------
// This file is licensed under the terms described in the LICENSE
// file located in the root directory of this source tree.
// -----------------------------------------------------------------------------
#include "timer_helpers.h"

uint32_t Timer_GetClockFreq(TIM_TypeDef* TIMER)
{
    RCC_ClkInitTypeDef clk;
    uint32_t latency;

    HAL_RCC_GetClockConfig(&clk, &latency);

    uint32_t pclk = HAL_RCC_GetPCLK1Freq();

    if (clk.APB1CLKDivider == RCC_HCLK_DIV1)
    {
        return pclk;
    }
    else
    {
        return pclk * 2;
    }
}
