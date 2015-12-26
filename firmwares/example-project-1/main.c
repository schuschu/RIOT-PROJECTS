/*
 * Copyright (C) 2015 Alexander Melnikov
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     examples
 * @{
 *
 * @file
 * @brief       Hello World application
 *
 * @author      Alexander Melnikov <avmelnikoff@gmail.com>
 *
 * @}
 */

#include <stdio.h>

#include <board.h>

#include <example_service_1.h>

int main(void)
{
    puts("Hello World!");

    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    example_service_1_routine();

    return 0;
}
