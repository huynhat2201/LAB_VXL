/*
 * exercise5.c
 *
 *  Created on: Oct 14, 2025
 *      Author: huynh
 */

#include "exercise5.h"
#include "exercise1.h"
#include "exercise3.h"

int hour =  23;
int minute = 58;
int second = 0;

void updateClockBuffer(){

	led_buffer[0] = hour/10;
	led_buffer[1] = hour%10;
	led_buffer[2] = minute/10;
	led_buffer[3] = minute%10;
}
