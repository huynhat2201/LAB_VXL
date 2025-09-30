/*
 * Exercise7.h
 *
 *  Created on: Sep 29, 2025
 *      Author: huynh
 */

#ifndef INC_EXERCISE7_H_
#define INC_EXERCISE7_H_

void clearAllClock(void)
{
    // Loop through all 12 LEDs and turn them off
    for (int i = 0; i < 12; i++) {
        HAL_GPIO_WritePin(LED_GPIO_Port[i], LED_Pin[i], GPIO_PIN_SET); // Turn off each LED
    }
}

#endif /* INC_EXERCISE7_H_ */
