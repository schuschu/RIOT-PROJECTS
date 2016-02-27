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

#include "board.h"

#include "periph/cpuid.h"
#include "periph/adc.h"
#include "periph/spi.h"

#include "net/ipv6/addr.h"
#include "net/gnrc/netif.h"
#include "net/gnrc/ipv6/netif.h"

#include "xtimer.h"

#ifdef MODULE_DHT
#include "dht.h"
#endif

#ifdef SERVICE_EXAMPLE_SERVICE_1
 #include "example_service_1.h"
#endif

#include "leds.h"

#define ADC_TEMP_V25        1.43
#define ADC_TEMP_AVG_SLOPE  4.3

#define DHT_DEV1_PIN        (2)
#define DHT_DEV1_GPIO       GPIO_PIN(PORT_A, DHT_DEV1_PIN)

#define OWARE_PIN           (3)
#define OWARE_GPIO          GPIO_PIN(PORT_A, OWARE_PIN)


/* set interval to 1 second */
#define INTERVAL (1000000U)

int main(void)
{
    //printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
    //printf("This board features a(n) %s MCU.\n", RIOT_MCU);

    /* initialize the boards LEDs */
    leds_init();

    /* Initialize ADC */
    printf("Initializing ADC... ");
    if (adc_init(ADC_0, ADC_RES_12BIT) == 0) {
        puts("[OK]\n");
    }
    else {
        puts("[Failed]");
        return 1;
    }

    LED_GREEN_ON;
    LED_YELLOW_ON;

#ifdef MODULE_DHT
    dht_t dht_dev1;

    printf("Initializing DHT sensor at GPIO_%ld... ", (long)DHT_DEV1_GPIO);
    if (dht_init(&dht_dev1, DHT21, DHT_DEV1_GPIO) == 0) {
        puts("[OK]\n");
    }
    else {
        puts("[Failed]");
        return 1;
    }
#endif


#ifdef SERVICE_EXAMPLE_SERVICE_1
    example_service_1_routine();
#endif

    /* CPUID */
    uint8_t cpuidbuf[CPUID_ID_LEN];
    cpuid_get(&cpuidbuf);
    printf("cpuid: ");
    for (uint8_t i = 0; i < sizeof (cpuidbuf); i++) {
        printf("0x%02x ", cpuidbuf[i]);
    }
    puts("");

    /* get the first IPv6 interface and prints its address */
/*
    kernel_pid_t ifs[GNRC_NETIF_NUMOF];
    size_t numof = gnrc_netif_get(ifs);
    if (numof > 0) {
        gnrc_ipv6_netif_t *entry = gnrc_ipv6_netif_get(ifs[0]);
        for (int i = 0; i < GNRC_IPV6_NETIF_ADDR_NUMOF; i++) {
            if ((ipv6_addr_is_link_local(&entry->addrs[i].addr)) && !(entry->addrs[i].flags & GNRC_IPV6_NETIF_ADDR_FLAGS_NON_UNICAST)) {
                char ipv6_addr[IPV6_ADDR_MAX_STR_LEN];
                ipv6_addr_to_str(ipv6_addr, &entry->addrs[i].addr, IPV6_ADDR_MAX_STR_LEN);
                printf("My address is %s\n", ipv6_addr);
            }
        }
    }
*/
    /* Main loop */
    float h, t;
    while (1) {
        LED_GREEN_ON;

#ifdef MODULE_DHT
        if (dht_read(&dht_dev1, &h, &t) == -1) {
            puts("error reading data");
        }
        printf("DHT: hum: %d; temp: %d\n", (int)h, (int)t);
#endif

        puts("ADC: reading channel...");
        int v16 = adc_sample(ADC_0, 16);
        if (v16 < 0) {
            puts("[Failed]");
        }
        else {
            puts("[OK]");

            float volts = v16 * 3.3 / 4095;

            printf("ADC: ch16: %d;\n", v16);
            printf("ADC: mV: %d; T: %d;\n", (int)volts, (int)((ADC_TEMP_V25 - volts) / ADC_TEMP_AVG_SLOPE) + 25 );
        }

        LED_GREEN_OFF;

        xtimer_usleep(2000 * MS_IN_USEC);
    }

    printf("\n");

    return 0;
}
