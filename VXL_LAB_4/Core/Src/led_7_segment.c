/*
 * led_7_segment.c
 *
 *  Created on: Oct 29, 2025
 *      Author: huynh
 */

//--- Private Include ----------------------------

#include "led_7_segment.h"

//--- Variables ----------------------------------

//- Global Variables -----------------------------
const int MAX_LED = 4;
int led_buffer[4] = {0,0,0,0};

//- Local Variables ------------------------------
uint8_t number_Code[10] = {0x01, 0x4F, 0x12, 0x06, 0x4C, 0x24, 0x20, 0x0F, 0x00, 0x04};
uint8_t index_led 		= 0;

//--- Functions Definition -----------------------

//- Local Functions ------------------------------
void display7SEG1(int num){
	//---0---
	//-5   1-
	//---6---
	//-4   2-
	//---3---
	HAL_GPIO_WritePin(SEG71_0_GPIO_Port, SEG71_0_Pin, (0x40 & number_Code[num]));
	HAL_GPIO_WritePin(SEG71_1_GPIO_Port, SEG71_1_Pin, (0x20 & number_Code[num]));
	HAL_GPIO_WritePin(SEG71_2_GPIO_Port, SEG71_2_Pin, (0x10 & number_Code[num]));
	HAL_GPIO_WritePin(SEG71_3_GPIO_Port, SEG71_3_Pin, (0x08 & number_Code[num]));
	HAL_GPIO_WritePin(SEG71_4_GPIO_Port, SEG71_4_Pin, (0x04 & number_Code[num]));
	HAL_GPIO_WritePin(SEG71_5_GPIO_Port, SEG71_5_Pin, (0x02 & number_Code[num]));
	HAL_GPIO_WritePin(SEG71_6_GPIO_Port, SEG71_6_Pin, (0x01 & number_Code[num]));
}

void display7SEG2(int num){
	//---0---
	//-5   1-
	//---6---
	//-4   2-
	//---3---
	HAL_GPIO_WritePin(SEG72_0_GPIO_Port, SEG72_0_Pin, (0x40 & number_Code[num]));
	HAL_GPIO_WritePin(SEG72_1_GPIO_Port, SEG72_1_Pin, (0x20 & number_Code[num]));
	HAL_GPIO_WritePin(SEG72_2_GPIO_Port, SEG72_2_Pin, (0x10 & number_Code[num]));
	HAL_GPIO_WritePin(SEG72_3_GPIO_Port, SEG72_3_Pin, (0x08 & number_Code[num]));
	HAL_GPIO_WritePin(SEG72_4_GPIO_Port, SEG72_4_Pin, (0x04 & number_Code[num]));
	HAL_GPIO_WritePin(SEG72_5_GPIO_Port, SEG72_5_Pin, (0x02 & number_Code[num]));
	HAL_GPIO_WritePin(SEG72_6_GPIO_Port, SEG72_6_Pin, (0x01 & number_Code[num]));
}

//- Global Functions -----------------------------
void update7SEG(int index){
	switch(index){
	case 0:
		display7SEG1(led_buffer[0]);
	    break;
	case 1:
		display7SEG1(led_buffer[1]);
	    break;
	case 2:
		display7SEG2(led_buffer[2]);
		break;
	case 3:
		display7SEG2(led_buffer[3]);
		break;
	default:
		break;
	}
	/*HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, !(0 == index || 2 == index));
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, !(1 == index || 3 == index));*/
	HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin,
	                  (index == 0 || index == 1) ? GPIO_PIN_RESET : GPIO_PIN_SET);
	HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin,
	                  (index == 2 || index == 3) ? GPIO_PIN_RESET : GPIO_PIN_SET);
}

void toggle7SEG(uint8_t num){
	/*switch(index_led & num){
	case 0:
		update7SEG(1);
		update7SEG(3);
		index_led = 1;
		break;
	case 1:
		update7SEG(0);
		update7SEG(2);
		index_led = 0;
		break;
	default:
		break;
	}*/

	static uint8_t idx = 0;
	  if (!num){ /* tắt cả */ idx = 0; return; }
	  update7SEG(idx ? 2 : 0);
	  idx ^= 1;
}
