/*
 * exercise9.c
 *
 *  Created on: Oct 14, 2025
 *      Author: huynh
 */

#include "exercise9.h"

const int MAX_LED_MATRIX = 8;
int index_led_matrix = 0;
uint8_t matrix_buffer[8] = {0x00, 0x18, 0x24, 0x42, 0x7e, 0x42, 0x42, 0x42}; // Letter 'A'
// {00000000, 00011000, 00100100, 01000010, 01111110, 01000010, 01000010, 01000010}

// Arrays to hold the GPIO ports and pins for ENM0 to ENM7
GPIO_TypeDef* ENMx_GPIO_Port[8] = {
    ENM0_GPIO_Port, ENM1_GPIO_Port, ENM2_GPIO_Port, ENM3_GPIO_Port,
	ENM4_GPIO_Port, ENM5_GPIO_Port, ENM6_GPIO_Port, ENM7_GPIO_Port
};

int ENMx_Pin[8] = {
	ENM0_Pin, ENM1_Pin, ENM2_Pin, ENM3_Pin,
	ENM4_Pin, ENM5_Pin, ENM6_Pin, ENM7_Pin
};

void updateLEDMatrix(int index) {
	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, SET); // Turn off all rows initially
	HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, SET);
	HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, SET);
	HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, SET);
	HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, SET);
	HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, SET);
	HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, SET);
	HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, SET);

	// Make sure the input is in valid range
    if (index >= MAX_LED_MATRIX) {
    	index = index % 8;
    }

    // Turn on corresponding columns
    // (1 << i): shift the number 1 left by i bits
    // (1 << 0) = 00000001, (1 << 2) = 00000100...
    // For example:
    // matrix_buffer[2] & (1 << 0), i = 0
    // 00100100 & 00000001 = 00000000 => COL0 is off
    // matrix_buffer[2] & (1 << 2), i = 2
    // 00100100 & 00000100 = 00000100 => COL2 is on
    // And so on
    for (int i = 0; i < 8; i++) {
    	 if (matrix_buffer[index] & (1 << i)) {
    		 HAL_GPIO_WritePin(ENMx_GPIO_Port[i], ENMx_Pin[i], RESET);
    	 } else {
    		 HAL_GPIO_WritePin(ENMx_GPIO_Port[i], ENMx_Pin[i], SET);
    	 }
    }

    // Turn on corresponding rows
    switch(index) {
    case 0:
    	HAL_GPIO_WritePin(ROW0_GPIO_Port, ROW0_Pin, RESET);
    	break;

    case 1:
        HAL_GPIO_WritePin(ROW1_GPIO_Port, ROW1_Pin, RESET);
        break;

    case 2:
        HAL_GPIO_WritePin(ROW2_GPIO_Port, ROW2_Pin, RESET);
        break;

    case 3:
        HAL_GPIO_WritePin(ROW3_GPIO_Port, ROW3_Pin, RESET);
        break;

    case 4:
        HAL_GPIO_WritePin(ROW4_GPIO_Port, ROW4_Pin, RESET);
        break;

    case 5:
        HAL_GPIO_WritePin(ROW5_GPIO_Port, ROW5_Pin, RESET);
        break;

    case 6:
        HAL_GPIO_WritePin(ROW6_GPIO_Port, ROW6_Pin, RESET);
        break;

    case 7:
        HAL_GPIO_WritePin(ROW7_GPIO_Port, ROW7_Pin, RESET);
        break;
    }
}
