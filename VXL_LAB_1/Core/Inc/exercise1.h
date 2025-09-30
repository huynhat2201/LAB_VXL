/*
 * exercise1.h
 *
 *  Created on: Sep 26, 2025
 *      Author: huynh
 */

#ifndef INC_EXERCISE1_H_
#define INC_EXERCISE1_H_

int state_ex1 = 0;

void twoLed() {
	if (state_ex1 == 0) {
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, RESET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, SET);
	}

	if (state_ex1 == 2){
		HAL_GPIO_WritePin(LED_RED_GPIO_Port, LED_RED_Pin, SET);
		HAL_GPIO_WritePin(LED_YELLOW_GPIO_Port, LED_YELLOW_Pin, RESET);
	}

	state_ex1++ ;

	if (state_ex1 > 3) {
		state_ex1 = 0;
	}
}

#endif /* INC_EXERCISE1_H_ */
