/*
 * Copyright (C) 2014 Freie Universität Berlin
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
 * @author      Kaspar Schleiser <kaspar@schleiser.de>
 * @author      Ludwig Ortmann <ludwig.ortmann@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>

#include <board.h>

#ifdef MODULE_DHT
#include <dht.h>
#endif

#include <example_service_1.h>

#include "leds.h"

#define DHT_DEV1_PIN        (2)
#define DHT_DEV1_GPIO       GPIO(PORT_A, DHT_DEV1_PIN)

#define OWARE_PIN           (3)
#define OWARE_GPIO          GPIO(PORT_A, OWARE_PIN)



int main(void)
{
    /* initialize the boards LEDs */
    leds_init();

    LED_GREEN_ON;
    LED_YELLOW_ON;

    printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    example_service_1_routine();

#ifdef MODULE_DHT
    dht_t dht_dev1;
    int ret = dht_init(&dht_dev1, DHT21, DHT_DEV1_GPIO);
    printf("DHT inited: %d\n", ret);

    float h = 0;
    float t = 0;
    ret = dht_read(&dht_dev1, &h, &t);
    printf("DHT ret: %d; hum: %d; temp: %d\n", ret, (int)h, (int)t);
    printf("DHT hum: %f\n", h);
#endif



    return 0;
}
