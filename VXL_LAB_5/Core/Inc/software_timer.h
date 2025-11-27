/*
 * software_timer.h
 *
 *  Created on: 26 thg 11, 2025
 *      Author: huynh
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[10];
extern int timer_counter[10];

void setTimer(int index, int counter);
void timerun();


#endif /* INC_SOFTWARE_TIMER_H_ */
