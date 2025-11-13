/*
 * fsm_input_processing.h
 *
 *  Created on: Oct 29, 2025
 *      Author: huynh
 */

#ifndef INC_FSM_INPUT_PROCESSING_H_
#define INC_FSM_INPUT_PROCESSING_H_

//--- Private Include ----------------------------

#include "main.h"
#include "global.h"
#include "input_reading.h"

//--- Functions Declaration ----------------------

void fsm_input_processing(void);

//--- Private Defines ----------------------------

#define BUTTON_STATE_RELEASE	1
#define BUTTON_STATE_PRESSED	2
#define BUTTON_STATE_PRESSED_1S	3


#endif /* INC_FSM_INPUT_PROCESSING_H_ */
