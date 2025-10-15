/*
 * exercise10.c
 *
 *  Created on: Oct 14, 2025
 *      Author: huynh
 */


#include "exercise10.h"
#include "exercise9.h"

void LEDanimation() {
	// By default, a binary number is read from right (bit 0) to left (bit 7)
	// And the LED matrix lights up from left to right (ROW to ROW7)
	// So shifting a binary number to the right will cause the LED matrix display to shift to the left

   	for (int i = 0; i < 8; i++) {
         // Check if the rightmost bit (bit 0) is 1
   		 uint8_t carry = (matrix_buffer[i] & 00000001);

         // Shift the row (LED matrix display) to the left by 1 and push the carry bit back to the right position (bit 7)
   		 matrix_buffer[i] = (matrix_buffer[i] >> 1) | (carry << 7);  // Left shift + carry to bit 7
	}
}
