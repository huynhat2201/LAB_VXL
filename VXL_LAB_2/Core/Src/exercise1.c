/*
 * exercise1.c
 *
 *  Created on: Oct 14, 2025
 *      Author: huynh
 */


#include "exercise1.h"
#include "display7Seg.h"

int status = 0;

void twoLed(void){
	switch(status) {
		case 0:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
			display7SEG(1);
			status = 1;
			break;

		case 1:
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			display7SEG(2);
			status = 0;
			break;
		}
}
