/*
 * fsm_traffic_mode.h
 *
 *  Created on: Oct 29, 2025
 *      Author: huynh
 */

#ifndef INC_FSM_TRAFFIC_MODE_H_
#define INC_FSM_TRAFFIC_MODE_H_

//--- Private Include ----------------------------

#include "main.h"
#include "global.h"
#include "timer.h"
#include "led_7_segment.h"

//--- Variables ----------------------------------

extern uint8_t traffic_mode;
extern uint8_t light_mode;

//--- Functions Declaration ----------------------

void init_fsm_traffic_mode(void);
void fsm_traffic_mode(void);
void fsm_traffic_auto(void);

#endif /* INC_FSM_TRAFFIC_MODE_H_ */
