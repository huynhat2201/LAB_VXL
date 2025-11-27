/*
 * global.h
 *
 *  Created on: 26 thg 11, 2025
 *      Author: huynh
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"

#define MAX_BUFFER_SIZE	30

#define INIT_COMMAND_PARSER	0
#define START				1
#define END					2

extern uint8_t temp;
extern uint8_t buffer[];
extern uint8_t index_buffer;
extern uint8_t buffer_flag;

extern uint8_t command_flag;
extern uint8_t command_data[];
extern uint32_t ADC_value;

#endif /* INC_GLOBAL_H_ */
