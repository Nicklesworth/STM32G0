/*
 * This file is licensed under the terms described in the LICENSE
 * file located in the root directory of this source tree.
 */

#include "debug_console.h"
#include "stm32g0xx_hal.h"

#define DEBUG_CONSOLE_BAUD_RATE	115200

UART_HandleTypeDef hDebugUART;

void DebugConsole_Init(USART_TypeDef* UART)
{
	hDebugUART.Instance             = UART;
	hDebugUART.Init.BaudRate        = DEBUG_CONSOLE_BAUD_RATE;
	hDebugUART.Init.WordLength      = UART_WORDLENGTH_8B;
	hDebugUART.Init.StopBits        = UART_STOPBITS_1;
	hDebugUART.Init.Parity          = UART_PARITY_NONE;
	hDebugUART.Init.Mode            = UART_MODE_TX;
	hDebugUART.Init.HwFlowCtl       = UART_HWCONTROL_NONE;
	hDebugUART.Init.OverSampling    = UART_OVERSAMPLING_16;
	hDebugUART.Init.OneBitSampling  = UART_ONE_BIT_SAMPLE_DISABLE;
	hDebugUART.Init.ClockPrescaler	= UART_PRESCALER_DIV1;
	HAL_UART_Init(&hDebugUART);
}

int __io_putchar(int ch)
{
	HAL_UART_Transmit(&hDebugUART, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
	return 0;
}
