/*
 * software_timer.c
 *
 *  Created on: 26 thg 11, 2025
 *      Author: huynh
 */


#include "software_timer.h"
#define TICK 10


int timer_flag[10];
int timer_counter[10];

void setTimer(int index, int counter) {
    timer_flag[index] = 0;
    timer_counter[index] = counter / TICK;
}

void timerun() {
    for (int i = 0; i < 10; i++) {  // Corrected loop condition
        if (timer_counter[i] >= 0) {
            timer_counter[i]--;
            if (timer_counter[i] <= 0) {
                timer_flag[i] = 1;
            }
        }
    }
}
