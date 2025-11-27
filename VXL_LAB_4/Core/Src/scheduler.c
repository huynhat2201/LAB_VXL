/*
 * scheduler.c
 *
 *  Created on: Nov 14, 2025
 *      Author: huynh
 */

#include "scheduler.h"
#include "task.h"
#include <stdlib.h>

#define TICK 10

sTask SCH_tasks_G[SCH_MAX_TASK];
uint8_t current_index_task = 0;

void SCH_Init(void) {
	current_index_task = 0;
	    for (int i = 0; i < SCH_MAX_TASK; i++) {
	        SCH_tasks_G[i].pTask  = 0;
	        SCH_tasks_G[i].Delay  = 0;
	        SCH_tasks_G[i].Period = 0;
	        SCH_tasks_G[i].RunMe  = 0;
	        SCH_tasks_G[i].TaskID = 0;
	    }
}

void SCH_Add_Task(void (*pFunction)(), uint32_t DELAY, uint32_t PERIOD) {
	if (current_index_task < SCH_MAX_TASK) {
		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY / TICK;
		SCH_tasks_G[current_index_task].Period = PERIOD / TICK;
		SCH_tasks_G[current_index_task].RunMe = 0;

		SCH_tasks_G[current_index_task].TaskID = current_index_task;
		current_index_task++;
	}
}
void SCH_Update(void) {
	for (int i = 0; i < current_index_task; i++) {
		if (SCH_tasks_G[i].Delay > 0) {
			SCH_tasks_G[i].Delay--;
		} else {
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Tasks(void) {
    for (int i = 0; i < current_index_task; i++) {
        if (SCH_tasks_G[i].RunMe > 0) {
            SCH_tasks_G[i].RunMe--;
            SCH_tasks_G[i].pTask();

            if (SCH_tasks_G[i].Period == 0) {
                SCH_Delete(i);
                i--;
            }
        }
    }
}

void SCH_Delete(uint32_t ID) {
    if (ID >= current_index_task) return;

    for (uint32_t i = ID; i + 1 < current_index_task; i++) {
        SCH_tasks_G[i] = SCH_tasks_G[i + 1];
    }

    current_index_task--;

    // Delete final slot
    SCH_tasks_G[current_index_task].pTask  = 0;
    SCH_tasks_G[current_index_task].Delay  = 0;
    SCH_tasks_G[current_index_task].Period = 0;
    SCH_tasks_G[current_index_task].RunMe  = 0;
    SCH_tasks_G[current_index_task].TaskID = 0;
}
