/*
 * uart_communication_fsm.c
 *
 *  Created on: 26 thg 11, 2025
 *      Author: huynh
 */

#include "uart_communication_fsm.h"
#include "global.h"
#include "software_timer.h"
#include <stdio.h>
#include <string.h>

ADC_HandleTypeDef hadc1;
UART_HandleTypeDef huart2;

uint8_t uart_com_status = WAIT_FOR_RST;
uint8_t ADC_value_memory = 0;
uint8_t str[30];



void uart_communication_fsm(){
	switch (uart_com_status){
	case WAIT_FOR_RST:
	        if (command_flag == 1) {
	            ADC_value = HAL_ADC_GetValue(&hadc1);
	            ADC_value_memory = ADC_value;
	            command_flag = 0;
	            uart_com_status = SENDING;
	        }
	        break;

	case SENDING:
		HAL_UART_Transmit(&huart2, (void *)str,  sprintf(str, "!ADC=%ld# \r\n", ADC_value), 1000);
		uart_com_status = WAIT_FOR_OK;
		setTimer(0, 3000);
		break;

	case WAIT_FOR_OK:
	        if (command_flag == 2) {
	            command_flag = 0;
	            uart_com_status = WAIT_FOR_RST;
	        }
	        else if (timer_flag[0] == 1) {
	            // If timeout of 3s without !OK#, resend
	            uart_com_status = SENDING;
	        }
	        break;

	    default:
	        uart_com_status = WAIT_FOR_RST;
	        break;
	}
}
