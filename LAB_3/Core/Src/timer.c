/*
 * timer.c
 *
 *  Created on: Oct 29, 2025
 *      Author: huynh
 */

//--- main header --------------------------------

#include "timer.h"

//--- Variables ----------------------------------

//- Local Variables ------------------------------
int TIMECYCLE 		= 0;
int one_sec_counter = 0;

//--- Functions Definition -----------------------

void init_SoftwareTimer(uint32_t HCLK, uint32_t Prescaler, uint32_t Period){
	TIMECYCLE = ((1000 * (Prescaler + 1) * (Period + 1)) / (HCLK));
}

void set_one_sec_timer(){
	one_sec_counter = 1000/TIMECYCLE;
	one_sec_flag = 0;
}

void timer_Run(){
	--one_sec_counter;
	if(one_sec_counter <= 0){
		one_sec_flag = 1;
	}
	if(one_sec_counter == 750/TIMECYCLE || one_sec_counter == 500/TIMECYCLE ||
	   one_sec_counter == 250/TIMECYCLE || one_sec_counter <= 0){
		blinky_led_flag = 1;
	}
	if(one_sec_counter == 500/TIMECYCLE || one_sec_counter <= 0){
		seg_flag = 1;
	}
}
