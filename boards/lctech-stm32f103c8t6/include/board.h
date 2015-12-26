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
#include "periph/gpio.h"
#include "periph_conf.h"

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @name Define the nominal CPU core clock in this board
 */
#define F_CPU               CLOCK_CORECLOCK

/**
 * @name Define the UART to be used as stdio and its baudrate
 * @{
 */
#define STDIO               UART_0
#define STDIO_BAUDRATE      (115200)
#define STDIO_RX_BUFSIZE    (64U)
/** @} */

/**
 * @name Assign the hardware timer
 */
#define HW_TIMER            TIMER_0

/**
 * @brief Initialize board specific hardware, including clock, LEDs and std-IO
 */
void board_init(void);

#ifdef __cplusplus
} /* end extern "C" */
#endif

#endif /* BOARD_H_ */
/** @} */
