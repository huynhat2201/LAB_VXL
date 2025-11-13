/*
 * scheduler.c
 *
 *  Created on: 13 thg 11, 2025
 *      Author: huynh
 */


#include "scheduler.h"

// mảng task toàn cục
static sTask SCH_tasks[SCH_MAX_TASKS];

void SCH_Init(void){
  for (uint32_t i=0;i<SCH_MAX_TASKS;i++){
    SCH_tasks[i].pTask = 0;
    SCH_tasks[i].Delay = 0;
    SCH_tasks[i].Period= 0;
    SCH_tasks[i].RunMe = 0;
  }
}

uint8_t SCH_Add_Task(void (*pFunction)(void), uint32_t DELAY, uint32_t PERIOD){
  for (uint32_t i=0;i<SCH_MAX_TASKS;i++){
    if (SCH_tasks[i].pTask == 0){
      SCH_tasks[i].pTask  = pFunction;
      SCH_tasks[i].Delay  = DELAY;
      SCH_tasks[i].Period = PERIOD;
      SCH_tasks[i].RunMe  = 0;
      return (uint8_t)i;                 // trả về ID task
    }
  }
  return 0xFF; // đầy
}

uint8_t SCH_Delete_Task(uint32_t id){
  if (id>=SCH_MAX_TASKS || SCH_tasks[id].pTask==0) return 1; // không có gì để xóa
  SCH_tasks[id].pTask = 0;
  SCH_tasks[id].Delay = 0;
  SCH_tasks[id].Period= 0;
  SCH_tasks[id].RunMe = 0;
  return 0;
}

// ISR timer 10ms sẽ gọi hàm này
void SCH_Update(void){
  for (uint32_t i=0;i<SCH_MAX_TASKS;i++){
    if (!SCH_tasks[i].pTask) continue;
    if (SCH_tasks[i].Delay == 0){
      if (SCH_tasks[i].RunMe < 255) SCH_tasks[i].RunMe++; // đánh dấu đến hạn
      if (SCH_tasks[i].Period) SCH_tasks[i].Delay = SCH_tasks[i].Period; // nạp lại
    } else {
      SCH_tasks[i].Delay--;
    }
  }
}

// gọi trong while(1)
void SCH_Dispatch_Task(void){
  for (uint32_t i=0;i<SCH_MAX_TASKS;i++){
    if (SCH_tasks[i].pTask && SCH_tasks[i].RunMe){
      SCH_tasks[i].RunMe--;
      (*SCH_tasks[i].pTask)();                 // chạy task
      if (SCH_tasks[i].Period == 0){           // one-shot -> xóa
        SCH_Delete_Task(i);
      }
    }
  }
}
