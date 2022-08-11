/*
 * fnd_led.h
 *
 *  Created on: 2022Äê7ÔÂ8ÈÕ
 *      Author: Litao
 */

#ifndef FOUNDATION_FND_LED_FND_LED_H_
#define FOUNDATION_FND_LED_FND_LED_H_

#include "Ifx_Types.h"

void fnd_led_set_state(uint8 index, uint8 state);

void fnd_led_test_task(void *arg);

#endif /* FOUNDATION_FND_LED_FND_LED_H_ */
