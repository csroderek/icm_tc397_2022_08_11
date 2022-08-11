/*
 * fnd_stm1.c
 *
 *  Created on: 2022Äê8ÔÂ11ÈÕ
 *      Author: Litao
 */

#include "fnd_stm1.h"
#include "IfxStm.h"
#include "timerscfg.h"

#define ISR_PRIORITY_STM1 70

Ifx_TickTime g_ticksFor100us;
IfxStm_CompareConfig g_STMConf;

IFX_INTERRUPT(stm1IsrTxHandler, 1, ISR_PRIORITY_STM1);

uint32 canopen_timer = 0;
uint32 canopen_next_time = 1;
uint32 canopen_last_time = 0;

uint32 canopen_dispatch_cnt = 0;

void timerForCan(void)
{
    canopen_timer = (canopen_timer + 1) % TIMEVAL_MAX;
    if (canopen_timer == canopen_next_time)
    {
        canopen_last_time = canopen_timer;
        canopen_dispatch_cnt++;
        TimeDispatch();
    }
}

void setTimer(TIMEVAL value)
{
    canopen_next_time = (canopen_next_time + value) % TIMEVAL_MAX;
}

TIMEVAL getElapsedTime(void)
{
    return ((canopen_timer + TIMEVAL_MAX) - canopen_last_time) % TIMEVAL_MAX;
}

void stm1IsrTxHandler(void)
{
    IfxStm_increaseCompare(&MODULE_STM1, g_STMConf.comparator, g_ticksFor100us);
    timerForCan();
}

void fnd_stm1_init(void)
{
    g_ticksFor100us = IfxStm_getTicksFromMicroseconds(&MODULE_STM1, 100);
    IfxStm_initCompareConfig(&g_STMConf);
    g_STMConf.triggerPriority = ISR_PRIORITY_STM1;
    g_STMConf.typeOfService = IfxSrc_Tos_cpu1;
    g_STMConf.ticks = g_ticksFor100us;
    IfxStm_initCompare(&MODULE_STM1, &g_STMConf);
}
