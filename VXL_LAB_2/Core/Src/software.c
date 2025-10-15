/*
 * software.c
 *
 *  Created on: Oct 14, 2025
 *      Author: huynh
 */


#include "software.h"


int timer_flag[TIMERS];
int timer_counter[TIMERS];

void setTimer(int index, int duration){
	if (index < TIMERS) {
		timer_counter[index] = duration;
		timer_flag[index] = 0;
	}
}

void timerRun(){
	for (int i = 0; i < TIMERS; i++){
		if (timer_counter[i] > 0) {
			timer_counter[i]--;
			if (timer_counter[i] == 0){
				timer_flag[i] = 1;
			}
		}
	}
}
