/*
 * exercise5.h
 *
 *  Created on: Sep 28, 2025
 *      Author: huynh
 */

#ifndef INC_EXERCISE5_H_
#define INC_EXERCISE5_H_



int state_ex51 = 10;
int state_ex52 = 10;
int cnt_ex5 = 5;

void led7Seg_Traffic() {
// Traffic lights of Left and Right
	  if ((5 < state_ex51) && (state_ex51 <= 10)) {
		  HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin,  RESET);
		  HAL_GPIO_WritePin(LED_YELLOW_X_GPIO_Port, LED_YELLOW_X_Pin, SET);
		  HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, SET);
	  }

	  if ((2 < state_ex51) && (state_ex51 <= 5)) {
		  HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, SET);
		  HAL_GPIO_WritePin(LED_YELLOW_X_GPIO_Port, LED_YELLOW_X_Pin, SET);
	  	  HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, RESET);
	  }

	  if ((0 < state_ex51) && (state_ex51 <= 2)) {
		  HAL_GPIO_WritePin(LED_RED_X_GPIO_Port, LED_RED_X_Pin, SET);
		  HAL_GPIO_WritePin(LED_YELLOW_X_GPIO_Port, LED_YELLOW_X_Pin, RESET);
	  	  HAL_GPIO_WritePin(LED_GREEN_X_GPIO_Port, LED_GREEN_X_Pin, SET);
 	  }


	  // Traffic lights of Top and Bottom
	  if ((7 < state_ex52) && (state_ex52 <= 10)) {
		  HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, SET);
		  HAL_GPIO_WritePin(LED_YELLOW_Y_GPIO_Port, LED_YELLOW_Y_Pin, SET);
		  HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, RESET);
	  }

	  if ((5 < state_ex52) && (state_ex52 <= 7)) {
		  HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, SET);
	  	  HAL_GPIO_WritePin(LED_YELLOW_Y_GPIO_Port, LED_YELLOW_Y_Pin, RESET);
	  	  HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, SET);
	  }

	  if ((0 < state_ex52) && (state_ex52 <= 5)) {
	  	  HAL_GPIO_WritePin(LED_RED_Y_GPIO_Port, LED_RED_Y_Pin, RESET);
	   	  HAL_GPIO_WritePin(LED_YELLOW_Y_GPIO_Port, LED_YELLOW_Y_Pin, SET);
	   	  HAL_GPIO_WritePin(LED_GREEN_Y_GPIO_Port, LED_GREEN_Y_Pin, SET);
	  }

	  display7SEG(cnt_ex5--);
	  state_ex51--;
	  state_ex52--;

	  if (state_ex51 == 0) state_ex51 = 10;

	  if (state_ex52 == 0) state_ex52 = 10;

	  	  	  // Counter will be counted by the Left and Right side traffic light
	  if(cnt_ex5 == 0) {
	  	 if ((state_ex51 == 10) || (state_ex51 == 0)) {
	  		cnt_ex5 = 5;
	  	  }

	  	  if (state_ex51 == 5) {
	  		cnt_ex5 = 3;
	  	  }

	  	  if (state_ex51 == 2) {
	  		cnt_ex5 = 2;
	  	  }
	  }

}


#endif /* INC_EXERCISE5_H_ */
