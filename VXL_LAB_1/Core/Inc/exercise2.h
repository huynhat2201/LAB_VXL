/*
 * exercise2.h
 *
 *  Created on: Sep 26, 2025
 *      Author: huynh
 */

#ifndef INC_EXERCISE2_H_
#define INC_EXERCISE2_H_

int state_ex2 = 10;

void threeLed() {
	if ((5 < state_ex2) && (state_ex2 <= 10)) {
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	}

	if ((2 < state_ex2) && (state_ex2 <= 5)){
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, RESET);
	}

	if ((0 < state_ex2) && (state_ex2 <= 2)){
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
		HAL_GPIO_WritePin(LED_GREEN_GPIO_Port, LED_GREEN_Pin, SET);
	}
	state_ex2--;

	if (state_ex2 == 0) {
		state_ex2 = 10;
	}
}

#endif /* INC_EXERCISE2_H_ */
