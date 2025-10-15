/*
 * exercise9.h
 *
 *  Created on: Oct 14, 2025
 *      Author: huynh
 */

#ifndef INC_EXERCISE9_H_
#define INC_EXERCISE9_H_

#include "main.h"

const int MAX_LED_MATRIX;
int index_led_matrix;
uint8_t matrix_buffer[8];

void updateLEDMatrix(int index);

#endif /* INC_EXERCISE9_H_ */
