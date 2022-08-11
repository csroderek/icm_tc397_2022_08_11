/*
 * fnd_led.c
 *
 *  Created on: 2022Äê7ÔÂ8ÈÕ
 *      Author: Litao
 */

#include "fnd_led.h"
#include "IfxPort.h"
#include "aurix_pin_mappings.h"

void fnd_led_set_state(uint8 index, uint8 state)
{
    IfxPort_State action = (state == 0) ? IfxPort_State_low : IfxPort_State_high;

    if (index == 0)
    {
        IfxPort_setPinState(IFXCFG_PORT_LED1.port, IFXCFG_PORT_LED1.pinIndex, action);
    }
    else if (index == 1)
    {
        IfxPort_setPinState(IFXCFG_PORT_LED2.port, IFXCFG_PORT_LED2.pinIndex, action);
    }
    else if (index == 2)
    {
        IfxPort_setPinState(IFXCFG_PORT_LED3.port, IFXCFG_PORT_LED3.pinIndex, action);
    }
    else if (index == 3)
    {
        IfxPort_setPinState(IFXCFG_PORT_LED4.port, IFXCFG_PORT_LED4.pinIndex, action);
    }
}

void fnd_led_test_task(void *arg)
{
	while (TRUE)
	{
		for (uint8 i = 0; i < 4; i++)
		{
			fnd_led_set_state(i, 1);
			vTaskDelay(100);
		}
		for (uint8 i = 0; i < 4; i++)
		{
			fnd_led_set_state(i, 0);
			vTaskDelay(100);
		}
	}
	vTaskDelete(NULL);
}
