/*
 * display7Seg.c
 *
 *  Created on: Oct 14, 2025
 *      Author: huynh
 */

#include "display7Seg.h"

void display7SEG(int num) {

	int segment_patterns[10] = {
			0b1000000, // 0 segments a, b, c, d, e, f
			0b1111001, // 1 segments b, c
			0b0100100, // 2 segments a, b, d, e, g
			0b0110000, // 3 segments a, b, c, d, g
			0b0011001, // 4 segments b, c, e, f
			0b0010010, // 5 segments a, c, d, f, g
			0b0000010, // 6 segments a, c, d, e, f, g
			0b1111000, // 7 segments a, b, c
			0b0000000, // 8 all segments
			0b0010000  // 9 segments a, b, c, d, f, g
	    };

	    if (num < 0 || num > 9) return;

	    int pattern = segment_patterns[num];

	    HAL_GPIO_WritePin(SEG_0_GPIO_Port, SEG_0_Pin, (pattern & 0b0000001) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(SEG_1_GPIO_Port, SEG_1_Pin, (pattern & 0b0000010) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(SEG_2_GPIO_Port, SEG_2_Pin, (pattern & 0b0000100) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(SEG_3_GPIO_Port, SEG_3_Pin, (pattern & 0b0001000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(SEG_4_GPIO_Port, SEG_4_Pin, (pattern & 0b0010000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(SEG_5_GPIO_Port, SEG_5_Pin, (pattern & 0b0100000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(SEG_6_GPIO_Port, SEG_6_Pin, (pattern & 0b1000000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}
