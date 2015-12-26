/*
 * Copyright 2015 Alexander Melnikov
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#ifndef LEDS_H_
#define LEDS_H_

#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @name LED pin definitions
 * @{
 */
#define LED_GREEN_PIN       (0)
#define LED_GREEN_GPIO      GPIO_PIN(PORT_A, LED_GREEN_PIN)

#define LED_YELLOW_PIN      (1)
#define LED_YELLOW_GPIO     GPIO_PIN(PORT_A, LED_YELLOW_PIN)
/** @} */

/**
 * @name Macros for controlling the on-board LEDs.
 * @{
 */
#define LED_GREEN_ON        gpio_clear(LED_GREEN_GPIO)
#define LED_GREEN_OFF       gpio_set(LED_GREEN_GPIO)
#define LED_GREEN_TOGGLE    gpio_toggle(LED_GREEN_GPIO)

#define LED_YELLOW_ON       gpio_clear(LED_YELLOW_GPIO)
#define LED_YELLOW_OFF      gpio_set(LED_YELLOW_GPIO)
#define LED_YELLOW_TOGGLE   gpio_toggle(LED_YELLOW_GPIO)
/** @} */


/**
 * @brief Initialize the boards on-board LEDs
 *
 * The LEDs initialization is hard-coded in this function. As the LED is soldered
 * onto the board it is fixed to its CPU pins.
 *
 * @return              0 on success
 * @return              -1 on error
 */
void leds_init(void);

#ifdef __cplusplus
} /* end extern "C" */
#endif

#endif /* LEDS_H_ */
