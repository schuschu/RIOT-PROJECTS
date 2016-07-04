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

/*

nRF24
IRQ - PA2
CE  - PA3
CSN - PA4
SCK - PA5
MI  - PA6
MO  - PA7

 */

#include <stdio.h>

#include <periph/gpio.h>

#include <xtimer.h>
#include <dht.h>
#include <dht_params.h>

#include <board.h>

#include <example_service_1.h>

extern dht_t dht_devs[];

int main(void)
{
  gpio_init(LED_GREEN_GPIO, GPIO_OUT);
  gpio_init(LED_YELLOW_GPIO, GPIO_OUT);

  gpio_set(LED_GREEN_GPIO);

  puts("Hello World!");

  printf("You are running RIOT on a(n) %s board.\n", RIOT_BOARD);
  printf("This board features a(n) %s MCU.\n", RIOT_MCU);

  example_service_1_routine();


  puts("DHT temperature and humidity sensor test application\n");

  /* periodically read temp and humidity values */
  while (1) {
      for (unsigned i = 0; i < DHT_NUMOF; i++) {
          dht_t *dev = &dht_devs[i];
          int16_t temp, hum;
          int16_t dec_temp, dec_hum, int_temp, int_hum;

          if (dht_read(dev, &temp, &hum) == -1) {
              puts("error reading data");
              continue;
          }

          /* split up values into integral and fractional parts for nicer
           * printing
           * TODO: this should be done in some kind of library... */
          int_temp = temp / 10;
          dec_temp = temp  - (int_temp * 10);
          int_hum = hum / 10;
          dec_hum = hum - (int_hum * 10);

          printf("DHT device #%i - ", i);
          printf("temp: %i.%i°C, ", int_temp, dec_temp);
          printf("relative humidity: %i.%i%%\n", int_hum, dec_hum);

          xtimer_usleep(2000 * MS_IN_USEC);
      }
  }

  return 0;
}
