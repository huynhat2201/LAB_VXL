/*
 * exercise10.h
 *
 *  Created on: 1 thg 10, 2025
 *      Author: huynh
 */

#ifndef INC_EXERCISE10_H_
#define INC_EXERCISE10_H_

int cnt_sec = 0;
int const hour = 0;                 // Example input
int const minute = 30;
int const second = 0;

int hourPos = hour % 12;            // Get the positions on clock
int minutePos = (minute / 5) % 12;  //
int secondPos = (second / 5) % 12;  //

void updateClock(int hrPos, int minPos, int secPos) {
	setNumberOnClock(hourPos);
	setNumberOnClock(minutePos);
	setNumberOnClock(secondPos);
}

void simpleAnalogClock(void) {
	// Reset the clock before running
    clearAllClock();

    // Turn on LEDs for hours, minutes, and seconds
    updateClock(hourPos, minutePos, secondPos);

    // for simulation in class
   /* cnt_sec++;
    if (cnt_sec == 5){
    	secondPos++;
    	cnt_sec = 0;
    }*/

    secondPos++; // for record video

    if (secondPos > 11) {
        minutePos++;
        secondPos = 0;
    }

    // Move the minute hand forward when seconds overflow
    if (minutePos > 11) {
        hourPos++;
        minutePos = 0;
    }

    // Move the hour hand forward when minutes overflow
    if (hourPos > 11) {
        hourPos = 0;
    }
}
#endif /* INC_EXERCISE10_H_ */
