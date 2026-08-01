/*
 * This file is licensed under the terms described in the LICENSE
 * file located in the root directory of this source tree.
 */

#ifndef DEBUG_CONSOLE_H_
#define DEBUG_CONSOLE_H_

#include "local_types.h"
#include "stm32g0xx_hal.h"

extern UART_HandleTypeDef hDebugUART;

#ifdef __cplusplus
extern "C" {
#endif

void DebugConsole_Init(USART_TypeDef* UART);

#ifdef __cplusplus
}
#endif

#endif // DEBUG_CONSOLE_H_
