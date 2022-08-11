/*
 * fnd_stm1.h
 *
 *  Created on: 2022Äê8ÔÂ11ÈÕ
 *      Author: Litao
 */

#ifndef FOUNDATION_FND_STM1_FND_STM1_H_
#define FOUNDATION_FND_STM1_FND_STM1_H_

#include "Ifx_Types.h"
#include "canfestival.h"

void fnd_stm1_init(void);

void setTimer(TIMEVAL value);

TIMEVAL getElapsedTime(void);

#endif /* FOUNDATION_FND_STM1_FND_STM1_H_ */
