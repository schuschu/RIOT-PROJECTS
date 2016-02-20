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
