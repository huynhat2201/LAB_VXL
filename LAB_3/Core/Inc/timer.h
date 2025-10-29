/*
 * timer.h
 *
 *  Created on: Oct 29, 2025
 *      Author: huynh
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

//--- Private Include ----------------------------

#include "main.h"
#include "global.h"

//--- Functions Declaration ----------------------

void init_SoftwareTimer(uint32_t HCLK, uint32_t Prescaler, uint32_t Period);
void set_one_sec_timer();
void timer_Run();

//--- Private Defines ----------------------------

#endif /* INC_TIMER_H_ */
