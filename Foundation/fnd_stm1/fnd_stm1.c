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

IfxStm_CompareConfig g_STMConf;

IFX_INTERRUPT(stm1IsrTxHandler, 1, ISR_PRIORITY_STM1);

uint32 canopen_timer = 0;
uint32 canopen_next_time = 1;
volatile uint32 canopen_last_time = 0;

uint32 canopen_elapsed_time = 0;
uint32 canopen_value_time = 0;

void setTimer(TIMEVAL value)
{
    // IfxStm_setSleepMode(&MODULE_STM1, IfxStm_SleepMode_disable);
    canopen_value_time = value;
    value = value < 1000 ? 1000 : value;
    IfxStm_increaseCompare(&MODULE_STM1, g_STMConf.comparator, value);
    // IfxStm_setSuspendMode(&MODULE_STM1, IfxStm_SuspendMode_none);
}

TIMEVAL getElapsedTime(void)
{
    // IfxStm_setSleepMode(&MODULE_STM1, IfxStm_SleepMode_enable);
    // IfxStm_setSuspendMode(&MODULE_STM1, IfxStm_SuspendMode_soft);
    canopen_elapsed_time = ((STM1_TIM1.B.STM_35_4 + TIMEVAL_MAX) - canopen_last_time) % TIMEVAL_MAX;

    if (canopen_elapsed_time < 50)
    {
        ;
    }
    return ((STM1_TIM1.B.STM_35_4 + TIMEVAL_MAX) - canopen_last_time) % TIMEVAL_MAX;
}

void stm1IsrTxHandler(void)
{
    IfxStm_clearCompareFlag(&MODULE_STM1, g_STMConf.comparator);
    canopen_last_time = STM1_TIM1.B.STM_35_4;
    TimeDispatch();
}

void fnd_stm1_init(void)
{
    IfxStm_initCompareConfig(&g_STMConf);
    g_STMConf.triggerPriority = ISR_PRIORITY_STM1;
    g_STMConf.compareOffset = IfxStm_ComparatorOffset_4;
    g_STMConf.typeOfService = IfxSrc_Tos_cpu1;
    g_STMConf.ticks = IfxStm_getTicksFromMicroseconds(&MODULE_STM1, 10);
    IfxStm_initCompare(&MODULE_STM1, &g_STMConf);
}
