/**
 * \file IfxEvadc_cfg.c
 * \brief EVADC on-chip implementation data
 *
 * \version iLLD_1_0_1_12_0_1
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxEvadc_cfg.h"

/******************************************************************************/
/*-----------------------Exported Variables/Constants-------------------------*/
/******************************************************************************/

volatile Ifx_SRC_SRCR *IfxEvadc_cfg_srcAddresses[(IFXEVADC_NUM_ADC_PRIMARY_GROUPS * 4) + (IFXEVADC_NUM_ADC_SECONDARY_GROUPS * 4) + (IFXEVADC_NUM_FAST_COMPARE_CHANNELS * 4) + (IFXEVADC_NUM_ADC_COMMON_GROUPS * 4)] = {
/* Primary Group 0*/
    &SRC_VADCG0SR0,
    &SRC_VADCG0SR1,
    &SRC_VADCG0SR2,
    &SRC_VADCG0SR3,
/* Primary Group 1*/
    &SRC_VADCG1SR0,
    &SRC_VADCG1SR1,
    &SRC_VADCG1SR2,
    &SRC_VADCG1SR3,
/* Primary Group 2*/
    &SRC_VADCG2SR0,
    &SRC_VADCG2SR1,
    &SRC_VADCG2SR2,
    &SRC_VADCG2SR3,
/* Primary Group 3*/
    &SRC_VADCG3SR0,
    &SRC_VADCG3SR1,
    &SRC_VADCG3SR2,
    &SRC_VADCG3SR3,
/* Primary Group 4*/
    &SRC_VADCG4SR0,
    &SRC_VADCG4SR1,
    &SRC_VADCG4SR2,
    &SRC_VADCG4SR3,
/* Primary Group 5*/
    &SRC_VADCG5SR0,
    &SRC_VADCG5SR1,
    &SRC_VADCG5SR2,
    &SRC_VADCG5SR3,
/* Primary Group 6*/
    &SRC_VADCG6SR0,
    &SRC_VADCG6SR1,
    &SRC_VADCG6SR2,
    &SRC_VADCG6SR3,
/* Primary Group 7*/
    &SRC_VADCG7SR0,
    &SRC_VADCG7SR1,
    &SRC_VADCG7SR2,
    &SRC_VADCG7SR3,

/* Secondary Group 0*/
    &SRC_VADCG8SR0,
    &SRC_VADCG8SR1,
    &SRC_VADCG8SR2,
    &SRC_VADCG8SR3,
/* Secondary Group 1*/
    &SRC_VADCG9SR0,
    &SRC_VADCG9SR1,
    &SRC_VADCG9SR2,
    &SRC_VADCG9SR3,
/* Secondary Group 2*/
    &SRC_VADCG10SR0,
    &SRC_VADCG10SR1,
    &SRC_VADCG10SR2,
    &SRC_VADCG10SR3,
/* Secondary Group 3*/
    &SRC_VADCG11SR0,
    &SRC_VADCG11SR1,
    &SRC_VADCG11SR2,
    &SRC_VADCG11SR3,

/* Fast Compare Channel 0*/
    &SRC_VADCFC0SR0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
/* Fast Compare Channel 1*/
    &SRC_VADCFC1SR0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
/* Fast Compare Channel 2*/
    &SRC_VADCFC2SR0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
/* Fast Compare Channel 3*/
    &SRC_VADCFC3SR0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
/* Fast Compare Channel 4*/
    &SRC_VADCFC4SR0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
/* Fast Compare Channel 5*/
    &SRC_VADCFC5SR0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
/* Fast Compare Channel 6*/
    &SRC_VADCFC6SR0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,
/* Fast Compare Channel 7*/
    &SRC_VADCFC7SR0,
    NULL_PTR,
    NULL_PTR,
    NULL_PTR,

/*Common Group 0*/
    &SRC_VADCCG0SR0,
    &SRC_VADCCG0SR1,
    &SRC_VADCCG0SR2,
    &SRC_VADCCG0SR3,
/*Common Group 1*/
    &SRC_VADCCG1SR0,
    &SRC_VADCCG1SR1,
    &SRC_VADCCG1SR2,
    &SRC_VADCCG1SR3
};
