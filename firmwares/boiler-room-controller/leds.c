/*
 * Copyright 2015 Alexander Melnikov
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <stdio.h>

#include "periph/gpio.h"

#include "leds.h"

/***********************************************************************
 * public API implementation
 **********************************************************************/

 void leds_init(void)
 {
     gpio_init(LED_GREEN_GPIO, GPIO_DIR_OUT, GPIO_NOPULL);
     gpio_init(LED_YELLOW_GPIO, GPIO_DIR_OUT, GPIO_NOPULL);
 }
