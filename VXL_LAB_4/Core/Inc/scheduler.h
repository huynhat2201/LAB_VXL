/*
 * scheduler.h
 *
 *  Created on: 13 thg 11, 2025
 *      Author: huynh
 */

#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

#include "main.h"

typedef struct {
  void   (*pTask)(void);
  uint32_t Delay;     // còn lại bao nhiêu tick đến lần chạy kế
  uint32_t Period;    // chu kỳ (tick). 0 = one-shot
  uint8_t  RunMe;     // số lần đến hạn (do ISR tăng)
} sTask;

#ifndef SCH_MAX_TASKS
#define SCH_MAX_TASKS  16     // đủ 5–10 task Lab3
#endif

// API chính (đúng yêu cầu Lab4)
void        SCH_Init(void);
uint8_t     SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD);
uint8_t     SCH_Delete_Task(uint32_t taskID);
void        SCH_Update(void);          // gọi trong ISR timer 10ms
void        SCH_Dispatch_Task(void);  // gọi trong while(1)

#endif /* INC_SCHEDULER_H_ */
