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

#include "xtimer.h"

#ifdef MODULE_DHT
#include <dht.h>
#endif

#ifdef SERVICE_EXAMPLE_SERVICE_1
#include <example_service_1.h>
#endif

#include "leds.h"

#define DHT_DEV1_PIN        (2)
#define DHT_DEV1_GPIO       GPIO_PIN(PORT_A, DHT_DEV1_PIN)

#define OWARE_PIN           (3)
#define OWARE_GPIO          GPIO_PIN(PORT_A, OWARE_PIN)

/* set interval to 1 second */
#define INTERVAL (1000000U)

int main(void)
{
    /* initialize the boards LEDs */
    leds_init();

    LED_GREEN_ON;
    LED_YELLOW_ON;

    //printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    //printf("This board features a(n) %s MCU.\n", RIOT_MCU);

#ifdef SERVICE_EXAMPLE_SERVICE_1
    example_service_1_routine();
#endif
/*
#ifdef MODULE_XTIMER
    uint32_t last_wakeup = xtimer_now();
    while(1) {
        xtimer_usleep_until(&last_wakeup, INTERVAL);
        printf("slept until %"PRIu32"\n", xtimer_now());
    }
#endif
*/

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


    printf("\n");

    return 0;
}
