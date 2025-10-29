/*
 * global.h
 *
 *  Created on: Oct 29, 2025
 *      Author: huynh
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

//--- Private Include ----------------------------

#include "main.h"

//--- Variables ----------------------------------

extern uint8_t flag_l;
extern uint8_t flag_m;
extern uint8_t flag_i;
extern uint8_t flag_s;

extern uint8_t one_sec_flag;
extern uint8_t seg_flag;
extern uint8_t blinky_led_flag;

//--- Private Defines ----------------------------

//- Necessities ----------------------------------
#define N0_OF_BUTTONS 3

//- TRAFFIC MODES --------------------------------
#define MODE_AUTO			1
#define MODE_RED_CONFIG		2
#define MODE_AMBER_CONFIG	3
#define MODE_GREEN_CONFIG	4

//- TRAFFIC LIGHT AUTOMATIC MODE -----------------
#define STATUS_RED_GREEN	11
#define STATUS_RED_AMBER	12
#define STATUS_GREEN_RED	13
#define STATUS_AMBER_RED	14

//- TRAFFIC BUTTONS ------------------------------
#define BUTTON_MODE		0
#define BUTTON_INCREASE	1
#define BUTTON_SET		2

#endif /* INC_GLOBAL_H_ */
