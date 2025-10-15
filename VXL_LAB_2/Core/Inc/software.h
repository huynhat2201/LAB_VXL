/*
 * software.h
 *
 *  Created on: Oct 14, 2025
 *      Author: huynh
 */

#ifndef INC_SOFTWARE_H_
#define INC_SOFTWARE_H_

#include "main.h"

#define TIMERS 10

extern int timer_flag[TIMERS];
extern int timer_counter[TIMERS];

void setTimer(int index, int duration);

void timerRun();

#endif /* INC_SOFTWARE_H_ */
