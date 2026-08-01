/*
 * This file is licensed under the terms described in the LICENSE
 * file located in the root directory of this source tree.
 */

#include "debug_console.h"
#include "debug_console_conf.h"
#include "stm32g0xx_hal.h"

#define DEBUG_CONSOLE_BAUD_RATE	115200

static UART_HandleTypeDef handle;

void DebugConsole_Init(void)
{
	handle.Instance             = DEBUG_CONSOLE_UART;
	handle.Init.BaudRate        = DEBUG_CONSOLE_BAUD_RATE;
	handle.Init.WordLength      = UART_WORDLENGTH_8B;
	handle.Init.StopBits        = UART_STOPBITS_1;
	handle.Init.Parity          = UART_PARITY_NONE;
	handle.Init.Mode            = UART_MODE_TX;
	handle.Init.HwFlowCtl       = UART_HWCONTROL_NONE;
	handle.Init.OverSampling    = UART_OVERSAMPLING_16;
	handle.Init.OneBitSampling  = UART_ONE_BIT_SAMPLE_DISABLE;
	handle.Init.ClockPrescaler	= UART_PRESCALER_DIV1;
	HAL_UART_Init(&handle);

	GPIO_InitTypeDef gpio_init;
	gpio_init.Pin               = DEBUG_CONSOLE_TX_PIN;
	gpio_init.Mode              = GPIO_MODE_AF_PP;
	gpio_init.Pull              = GPIO_NOPULL;
	gpio_init.Speed             = GPIO_SPEED_FREQ_VERY_HIGH;
	gpio_init.Alternate	        = DEBUG_CONSOLE_TX_AF;
	HAL_GPIO_Init(DEBUG_CONSOLE_TX_PORT, &gpio_init);
}

int __io_putchar(int ch)
{
	HAL_UART_Transmit(&handle, (uint8_t*)&ch, 1, HAL_MAX_DELAY);
	return 0;
}
