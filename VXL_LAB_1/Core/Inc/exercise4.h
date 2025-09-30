/*
 * exercise4.h
 *
 *  Created on: Sep 26, 2025
 *      Author: huynh
 */

#ifndef INC_EXERCISE4_H_
#define INC_EXERCISE4_H_

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

	    HAL_GPIO_WritePin(GPIOB, SEG_A_Pin, (pattern & 0b0000001) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG_B_Pin, (pattern & 0b0000010) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG_C_Pin, (pattern & 0b0000100) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG_D_Pin, (pattern & 0b0001000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG_E_Pin, (pattern & 0b0010000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG_F_Pin, (pattern & 0b0100000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
	    HAL_GPIO_WritePin(GPIOB, SEG_G_Pin, (pattern & 0b1000000) ? GPIO_PIN_SET : GPIO_PIN_RESET);
}

int state_1 = 10;
int state_2 = 10;
int counter = 0;

void ledTraffic() {
	// Traffic lights of Left and Right
	if ((5 < state_1) && (state_1 <= 10)) {
		HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_X_GPIO_Port, LED_YELLOW_X_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, SET);
	}
	if ((2 < state_1) && (state_1 <= 5)) {
		HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_X_GPIO_Port, LED_YELLOW_X_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, RESET);
	}
	if ((0 < state_1) && (state_1 <= 2)) {
		HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_X_GPIO_Port, LED_YELLOW_X_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, SET); }

	// Traffic lights of Top and Bottom
	if ((7 < state_2) && (state_2 <= 10)) {
		HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_Y_GPIO_Port, LED_YELLOW_Y_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, RESET);
	}
	if ((5 < state_2) && (state_2 <= 7)) {
		HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_Y_GPIO_Port, LED_YELLOW_Y_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, SET);
	}
	if ((0 < state_2) && (state_2 <= 5)) {
		HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_Y_GPIO_Port, LED_YELLOW_Y_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, SET);
	}

	state_1--;
	state_2--;

	if (state_1 == 0) state_1 = 10;
	if (state_2 == 0) state_2 = 10;
	if(counter >= 10) counter = 0;
	display7SEG(counter++);
}

#endif /* INC_EXERCISE4_H_ */
