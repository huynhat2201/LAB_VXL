/*
 * fsm_traffic_mode.c
 *
 *  Created on: Oct 29, 2024
 *      Author: ACER
 */

//--- Private Include ----------------------------

#include "fsm_traffic_mode.h"

//--- Variables ----------------------------------

//- Global Variables -----------------------------
uint8_t traffic_mode  = 0;
uint8_t light_mode 	  = 0;

//- Private Variables ----------------------------
uint8_t light_pattern = 0;

uint8_t red 		  = 5;
uint8_t amber 		  = 2;
uint8_t green 		  = 3;
uint8_t red_counter   = 5;
uint8_t amber_counter = 2;
uint8_t green_counter = 3;


// Đếm còn lại theo hướng (độc lập A/B) – dùng trong AUTO
static uint8_t ct_A = 0; // Hướng A: RED hoặc GREEN/AMBER tùy state
static uint8_t ct_B = 0; // Hướng B: RED hoặc GREEN/AMBER tùy state
//--- Functions Definition -----------------------

//- Private Functions ----------------------------
void config_leds(uint8_t pattern){
	HAL_GPIO_WritePin(LED_RED_1_GPIO_Port, 	 LED_RED_1_Pin,   (0x20 & pattern));
	HAL_GPIO_WritePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin, (0x10 & pattern));
	HAL_GPIO_WritePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin, (0x08 & pattern));
	HAL_GPIO_WritePin(LED_RED_2_GPIO_Port, 	 LED_RED_2_Pin,   (0x04 & pattern));
	HAL_GPIO_WritePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin, (0x02 & pattern));
	HAL_GPIO_WritePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin, (0x01 & pattern));
}

//- Init Traffic Modes ---------------------------
/*void init_auto_mode(void){
	red_counter   = red;
	amber_counter = amber;
	green_counter = green;
	led_buffer[0] = red_counter / 10;
	led_buffer[1] = red_counter % 10;
	led_buffer[2] = green_counter / 10;
	led_buffer[3] = green_counter % 10;
	flag_l 		  = 0;
	seg_flag 	  = 0;
	toggle7SEG(0);
	config_leds(0x1e);
	set_one_sec_timer();
}*/

void init_auto_mode(void){
    red_counter   = red;
    amber_counter = amber;
    green_counter = green;

    // NEW: đếm độc lập theo state đầu tiên (STATUS_RED_GREEN)
    ct_A = red;    // A = RED
    ct_B = green;  // B = GREEN

    led_buffer[0] = ct_A / 10;
    led_buffer[1] = ct_A % 10;
    led_buffer[2] = ct_B / 10;
    led_buffer[3] = ct_B % 10;

    flag_l = 0; seg_flag = 0;
    toggle7SEG(0);
    config_leds(0x1e);
    set_one_sec_timer();
}


void init_red_config_mode(void){
	led_buffer[0] = 0 / 10;
	led_buffer[1] = 2 % 10;
	led_buffer[2] = red / 10;
	led_buffer[3] = red % 10;
	seg_flag 	  = 0;
	red_counter   = red;
	blinky_led_flag = 0;
	toggle7SEG(0);
	config_leds(0x1b);
	set_one_sec_timer();
}

void init_amber_config_mode(void){
	led_buffer[0] = 0 / 10;
	led_buffer[1] = 3 % 10;
	led_buffer[2] = amber / 10;
	led_buffer[3] = amber % 10;
	seg_flag 	  = 0;
	amber_counter = amber;
	blinky_led_flag = 0;
	toggle7SEG(0);
	config_leds(0x2d);
	set_one_sec_timer();
}

void init_green_config_mode(void){
	led_buffer[0] = 0 / 10;
	led_buffer[1] = 4 % 10;
	led_buffer[2] = green / 10;
	led_buffer[3] = green % 10;
	seg_flag 	  = 0;
	green_counter = green; //0;
	blinky_led_flag = 0;
	toggle7SEG(0);
	config_leds(0x36);
	set_one_sec_timer();
}

//- Traffic Modes --------------------------------

void fsm_mode_auto(void){
	switch(light_mode){
	case STATUS_RED_GREEN:
		/*config_leds(0x1e);
		if(one_sec_flag == 1){
			set_one_sec_timer();
			flag_l = (--green_counter == 0);
			--red_counter;
		}
		if(flag_l == 1){
			flag_l = 0;
			light_mode = STATUS_RED_AMBER;
			green_counter = green;
			break;
		}
		if(seg_flag == 1){
			seg_flag = 0;
			led_buffer[0] = red_counter / 10;
			led_buffer[1] = red_counter % 10;
			led_buffer[2] = green_counter / 10;
			led_buffer[3] = green_counter % 10;
			toggle7SEG(1);
		}*/

		config_leds(0x1e);
		if(one_sec_flag == 1){
		    set_one_sec_timer();
		    if(ct_A) --ct_A;             // A = RED
		    if(ct_B) --ct_B;             // B = GREEN
		}
		if(ct_B == 0){                   // B GREEN -> AMBER (A vẫn RED)
		    ct_B = amber;
		    // chuyển sang RED_AMBER
		    light_mode = STATUS_RED_AMBER;
		}
		if(seg_flag == 1){
		    seg_flag = 0;
		    led_buffer[0] = ct_A / 10;
		    led_buffer[1] = ct_A % 10;
		    led_buffer[2] = ct_B / 10;
		    led_buffer[3] = ct_B % 10;
		    toggle7SEG(1);
		}

		break;
	case STATUS_RED_AMBER:
		/*config_leds(0x1d);
		if(one_sec_flag == 1){
			set_one_sec_timer();
			flag_l = (--amber_counter == 0);
			--red_counter;
		}
		if(flag_l == 1){
			flag_l = 0;
			light_mode = STATUS_GREEN_RED;
			red_counter = red;
			amber_counter = amber;
			break;
		}
		if(seg_flag == 1){
			seg_flag = 0;
			led_buffer[0] = red_counter / 10;
			led_buffer[1] = red_counter % 10;
			led_buffer[2] = amber_counter / 10;
			led_buffer[3] = amber_counter % 10;
			toggle7SEG(1);
		}*/

		config_leds(0x1d);
		if(one_sec_flag == 1){
		    set_one_sec_timer();
		    if(ct_A) --ct_A;          // A vẫn RED
		    if(ct_B) --ct_B;          // B = AMBER
		}
		if(ct_B == 0){
		    // B AMBER -> RED, đồng thời A RED -> GREEN (điểm đồng bộ)
		    ct_B = red;               // B = RED
		    ct_A = green;             // A = GREEN
		    light_mode = STATUS_GREEN_RED;
		}
		if(seg_flag == 1){
		    seg_flag = 0;
		    led_buffer[0] = ct_A / 10;
		    led_buffer[1] = ct_A % 10;
		    led_buffer[2] = ct_B / 10;
		    led_buffer[3] = ct_B % 10;
		    toggle7SEG(1);
		}
		break;
	case STATUS_GREEN_RED:
		/*config_leds(0x33);
		if(one_sec_flag == 1){
			set_one_sec_timer();
			flag_l = (--green_counter == 0);
			--red_counter;
		}
		if(flag_l == 1){
			flag_l = 0;
			light_mode = STATUS_AMBER_RED;
			green_counter = green;
			break;
		}
		if(seg_flag == 1){
			seg_flag = 0;
			led_buffer[0] = green_counter / 10;
			led_buffer[1] = green_counter % 10;
			led_buffer[2] = red_counter / 10;
			led_buffer[3] = red_counter % 10;
			toggle7SEG(1);
		}*/

		config_leds(0x33);
		if(one_sec_flag == 1){
		    set_one_sec_timer();
		    if(ct_A) --ct_A;          // A = GREEN
		    if(ct_B) --ct_B;          // B = RED
		}
		if(ct_A == 0){                // A GREEN -> AMBER
		    ct_A = amber;
		    light_mode = STATUS_AMBER_RED;
		}
		if(seg_flag == 1){
		    seg_flag = 0;
		    led_buffer[0] = ct_A / 10;
		    led_buffer[1] = ct_A % 10;
		    led_buffer[2] = ct_B / 10;
		    led_buffer[3] = ct_B % 10;
		    toggle7SEG(1);
		}

		break;

	case STATUS_AMBER_RED:
		/*config_leds(0x2b);
		if(one_sec_flag == 1){
			set_one_sec_timer();
			flag_l = (--amber_counter == 0);
			--red_counter;
		}
		if(flag_l == 1){
			flag_l = 0;
			light_mode = STATUS_RED_GREEN;
			red_counter = red;
			amber_counter = amber;
			break;
		}
		if(seg_flag == 1){
			seg_flag = 0;
			led_buffer[0] = amber_counter / 10;
			led_buffer[1] = amber_counter % 10;
			led_buffer[2] = red_counter / 10;
			led_buffer[3] = red_counter % 10;
			toggle7SEG(1);
		}*/

		config_leds(0x2b);
		if(one_sec_flag == 1){
		    set_one_sec_timer();
		    if(ct_A) --ct_A;          // A = AMBER
		    if(ct_B) --ct_B;          // B = RED
		}
		if(ct_A == 0){
		    // A AMBER -> RED, đồng thời B RED -> GREEN (điểm đồng bộ)
		    ct_A = red;               // A = RED
		    ct_B = green;             // B = GREEN
		    light_mode = STATUS_RED_GREEN;
		}
		if(seg_flag == 1){
		    seg_flag = 0;
		    led_buffer[0] = ct_A / 10;
		    led_buffer[1] = ct_A % 10;
		    led_buffer[2] = ct_B / 10;
		    led_buffer[3] = ct_B % 10;
		    toggle7SEG(1);
		}

		break;
	default:
		break;
	}
}

void mode_red_config(void){
	if(flag_i == 1){
		flag_i = 0;
		red_counter = (((++red_counter) == 100) ? 2 : red_counter);
	}
	/*if(flag_s == 1){
		flag_s = 0;
		red = red_counter;
	}*/

	if(flag_s == 1){
	    flag_s = 0;
	    if (red_counter < 2) red_counter = 2;   // tổng >= 2 để chia tối thiểu 1-1
	    red = red_counter;

	    // ràng buộc còn lại
	    if (amber >= red) amber = red - 1;      // 1 .. red-1
	    if (amber == 0)   amber = 1;
	    green = red - amber;                    // green là phần còn lại
	}


	if(seg_flag == 1){
		seg_flag = 0;
		led_buffer[2] = red_counter / 10;
		led_buffer[3] = red_counter % 10;
		toggle7SEG(1);
	}
}

void mode_amber_config(void){
	if(flag_i == 1){
		flag_i = 0;
		amber_counter = (((++amber_counter) == 100) ? 1 : amber_counter);
	}
	/*if(flag_s == 1){
		flag_s = 0;
		amber = ((amber_counter >= red) ? 1 : amber_counter);
		amber_counter = amber;
	}*/

	if(flag_s == 1){
	    flag_s = 0;
	    // amber trong [1, red-1]
	    if (amber_counter == 0) amber = 1;
	    else                    amber = amber_counter;
	    if (amber >= red)       amber = (red > 1) ? (red - 1) : 1;

	    green = red - amber;
	    if (green == 0){ green = 1; amber = red - green; }
	    amber_counter = amber;   // đồng bộ hiển thị
	}


	if(seg_flag == 1){
		seg_flag = 0;
		led_buffer[2] = amber_counter / 10;
		led_buffer[3] = amber_counter % 10;
		toggle7SEG(1);
	}
}

void mode_green_config(void){
	if(flag_i == 1){
		flag_i = 0;
		green_counter = (((++green_counter) == 100) ? 1 : green_counter);
	}
	/*if(flag_s == 1){
		flag_s = 0;
		green = (red - amber);
		green_counter = green;
	}*/

	if(flag_s == 1){
	    flag_s = 0;
	    uint8_t g = (green_counter == 0) ? 1 : green_counter;
	    if (g >= red) g = red - 1;      // green trong [1, red-1]
	    green = g;

	    amber = red - green;            // amber là phần còn lại
	    if (amber == 0){ amber = 1; green = red - amber; }
	    green_counter = green;          // đồng bộ hiển thị
	}


	if(seg_flag == 1){
		seg_flag = 0;
		led_buffer[2] = green_counter / 10;
		led_buffer[3] = green_counter % 10;
		toggle7SEG(1);
	}
}

//- Global Functions -----------------------------
void init_fsm_traffic_mode(){
	traffic_mode = MODE_AUTO;
	light_mode = STATUS_RED_GREEN;
	init_auto_mode();
}

void fsm_traffic_mode(void){
	switch(traffic_mode){
	case MODE_AUTO:
		if(flag_m == 1){
			flag_m = 0;
			traffic_mode = MODE_RED_CONFIG;
			init_red_config_mode();
			break;
		}
		//TODO
		fsm_mode_auto();
		break;
	case MODE_RED_CONFIG:
		if(flag_m == 1){
			flag_m = 0;
			traffic_mode = MODE_AMBER_CONFIG;
			init_amber_config_mode();
			break;
		}
		//TODO
		if(blinky_led_flag == 1){
			blinky_led_flag = 0;
			HAL_GPIO_TogglePin(LED_RED_1_GPIO_Port, LED_RED_1_Pin);
			HAL_GPIO_TogglePin(LED_RED_2_GPIO_Port, LED_RED_2_Pin);
		}
		mode_red_config();
		break;
	case MODE_AMBER_CONFIG:
		if(flag_m == 1){
			flag_m = 0;
			traffic_mode = MODE_GREEN_CONFIG;
			init_green_config_mode();
			break;
		}
		//TODO
		if(blinky_led_flag == 1){
			blinky_led_flag = 0;
			HAL_GPIO_TogglePin(LED_AMBER_1_GPIO_Port, LED_AMBER_1_Pin);
			HAL_GPIO_TogglePin(LED_AMBER_2_GPIO_Port, LED_AMBER_2_Pin);
		}
		mode_amber_config();
		break;
	case MODE_GREEN_CONFIG:
		if(flag_m == 1){
			flag_m = 0;
			traffic_mode = MODE_AUTO;
			init_fsm_traffic_mode();
			break;
		}
		//TODO
		if(blinky_led_flag == 1){
			blinky_led_flag = 0;
			HAL_GPIO_TogglePin(LED_GREEN_1_GPIO_Port, LED_GREEN_1_Pin);
			HAL_GPIO_TogglePin(LED_GREEN_2_GPIO_Port, LED_GREEN_2_Pin);
		}
		mode_green_config();
		break;
	default:
		break;
	}
	if(one_sec_flag == 1){
		set_one_sec_timer();
	}
}





