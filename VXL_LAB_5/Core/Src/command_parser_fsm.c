/*
 * command_parser_fsm.c
 *
 *  Created on: 26 thg 11, 2025
 *      Author: huynh
 */

#include "command_parser_fsm.h"
#include "global.h"
#include "string.h"

uint8_t command_index = 0;
uint8_t command_parser_status = INIT_COMMAND_PARSER;

void command_parser_fsm(void){
    switch (command_parser_status) {
    case INIT_COMMAND_PARSER:
        if (temp != '\r' && temp != '\n') {
            command_index = 0;
            if (command_index < MAX_BUFFER_SIZE - 1) {
                command_data[command_index] = temp;
                command_index++;
            }
            command_parser_status = START;
        }
        break;

    case START:
        if (temp == '\r' || temp == '\n') {
            command_data[command_index] = '\0';  // latch string

            // default
            command_flag = 0;

            // Check !RST#
            if (command_index == 5 &&
                command_data[0] == '!' &&
                command_data[1] == 'R' &&
                command_data[2] == 'S' &&
                command_data[3] == 'T' &&
                command_data[4] == '#') {
                command_flag = 1;
            }
            // Check !OK#
            else if (command_index == 4 &&
                     command_data[0] == '!' &&
                     command_data[1] == 'O' &&
                     command_data[2] == 'K' &&
                     command_data[3] == '#') {
                command_flag = 2;
            }

            // Reset next line
            command_index = 0;
            command_parser_status = INIT_COMMAND_PARSER;
        }
        else {
            // Adding char in a line
            if (command_index < MAX_BUFFER_SIZE - 1) {
                command_data[command_index] = temp;
                command_index++;
            }
        }
        break;

    default:
        command_parser_status = INIT_COMMAND_PARSER;
        break;
    }
}
