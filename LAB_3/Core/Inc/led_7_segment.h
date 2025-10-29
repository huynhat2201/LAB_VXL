/*
 * led_7_segment.h
 *
 *  Created on: Oct 29, 2025
 *      Author: huynh
 */

#ifndef INC_LED_7_SEGMENT_H_
#define INC_LED_7_SEGMENT_H_

//--- Private Include ----------------------------

#include "main.h"
#include "global.h"

//--- Variables ----------------------------------

//- Global Variables -----------------------------
extern const int MAX_LED;
extern int led_buffer[4];
extern uint8_t index_led;

//--- Functions Declaration ----------------------

void update7SEG(int index);
void toggle7SEG(uint8_t num);

#endif /* INC_LED_7_SEGMENT_H_ */
