/*
 * Copyright (C) 2015 Alexander Melnikov <avmelnikoff@gmail.com>
 *
 * This file is subject to the terms and conditions of the GNU Lesser General
 * Public License v2.1. See the file LICENSE in the top level directory for more
 * details.
 */

/**
 * @ingroup     boards_lctech-stm32f103c8t6
 * @{
 *
 * @file
 * @brief       Board specific implementations for the lctech-stm32f103c8t6 board
 *
 * @author      Alexander Melnikov <avmelnikoff@gmail.com>
 *
 * @}
 */

#include "board.h"
#include "periph/gpio.h"

void board_init(void)
{
    /* initialize the CPU */
    cpu_init();
}
