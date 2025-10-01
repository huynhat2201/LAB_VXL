/*
 * exercise8.h
 *
 *  Created on: Sep 29, 2025
 *      Author: huynh
 */

#ifndef INC_EXERCISE8_H_
#define INC_EXERCISE8_H_

void setNumberOnClock(int num)
{
    // Make sure that the input number is within the valid range (0 to 11)
    num = num % 12;

    int index = (num == 0) ? 11 : (num - 1);

    HAL_GPIO_WritePin(LED_GPIO_Port[index], LED_Pin[index], GPIO_PIN_RESET);
}

#endif /* INC_EXERCISE8_H_ */
