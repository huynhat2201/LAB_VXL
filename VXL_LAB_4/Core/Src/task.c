/*
 * task.c
 *
 *  Created on: 13 thg 11, 2025
 *      Author: huynh
 */


// task.c
#include "task.h"
#include "scheduler.h"
#include "input_reading.h"     // có button_reading()
#include "timer.h"             // có timer_Run()
#include "led_7_segment.h"     // có toggle7SEG()
#include "fsm_traffic_mode.h"  // có fsm_traffic_mode(


extern void getKeyInput(void);
extern void timer_Run(void);
extern void toggle7SEG(uint8_t num);
extern void fsm_traffic_mode(void);

void Task_GetKeyInput(void){ button_reading(); }      // 10ms
void Task_TimerRun(void){    timer_Run();    }      // 10ms
void Task_7SEG_Scan(void){   toggle7SEG(1);  }      // 10ms
void Task_FSM_Traffic(void){ fsm_traffic_mode(); } // 1000ms
void Task_FSM_Input(void){ fsm_input_processing(); }
