/*
 * Copyright (C) 2015 Alexander Melnikov <avmelnikoff@gmail.com>
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @defgroup    boards_lctech-stm32f103c-mini Shenzhen LC Technology Co., Ltd STM32F103C8T6
 * @ingroup     boards
 * @brief       Board specific files for the Shenzhen LC Technology Co., Ltd STM32F103C8T6 board.
 * @{
 *
 * @file
 * @brief       Board specific definitions for the Shenzhen LC Technology Co., Ltd stm32f103c-mini board.
 *
 * @author      Alexander Melnikov <avmelnikoff@gmail.com>
 */

#ifndef BOARD_H_
#define BOARD_H_

#include <stdint.h>

#include "cpu.h"
//#include "periph/gpio.h"
#include "periph_conf.h"

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @name Define the nominal CPU core clock in this board
 */
//#define F_CPU               CLOCK_CORECLOCK

/**
 * @brief Use the 2nd UART for STDIO on this board
 */
#define UART_STDIO_DEV      UART_DEV(0)

/**
 * @name Define the UART to be used as stdio and its baudrate
 * @{
 */
//#define STDIO               UART_0
//#define STDIO_BAUDRATE      (115200)
//#define STDIO_RX_BUFSIZE    (64U)
/** @} */

/**
 * @name xtimer configuration
 * @{
 */
//#define XTIMER              TIMER_0
//#define XTIMER_CHAN         0
//#define XTIMER_SHIFT        0
#define XTIMER_MASK         (0xffff0000) //0 /* llt 32-bit since combined */
#define XTIMER_BACKOFF      5
/** @} */

/**
 * @name LED pin definitions
 * @{
 */
#define LED_GREEN_GPIO      GPIO_PIN(PORT_A,0)
#define LED_YELLOW_GPIO     GPIO_PIN(PORT_A,1)
/** @} */

/**
 * @name Macros for controlling the on-board LEDs.
 * @{
 */
/*
#define LED_GREEN_ON        gpio_clear(LED_GREEN_GPIO)
#define LED_GREEN_OFF       gpio_set(LED_GREEN_GPIO)
#define LED_GREEN_TOGGLE    gpio_toggle(LED_GREEN_GPIO)

#define LED_YELLOW_ON       gpio_clear(LED_YELLOW_GPIO)
#define LED_YELLOW_OFF      gpio_set(LED_YELLOW_GPIO)
#define LED_YELLOW_TOGGLE   gpio_toggle(LED_YELLOW_GPIO)
*/
/** @} */

/**
 * @name ENC28J60 pin configuration
 * @{
 */
#define ENC28J60_PARAM_SPI    SPI_0
#define ENC28J60_PARAM_CS     GPIO_PIN(PORT_B,0)
#define ENC28J60_PARAM_INT    GPIO_PIN(PORT_B,2)
#define ENC28J60_PARAM_RESET  GPIO_PIN(PORT_B,1)
/** @} */


/**
 * @brief Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);

#ifdef __cplusplus
} /* end extern "C" */
#endif

#endif /* BOARD_H_ */
/** @} */
