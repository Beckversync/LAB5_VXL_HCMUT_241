#include "comand_parser.h"
#include <stdint.h>
#include "stm32f1xx_hal.h"
#include <string.h>
#include"global.h"
uint8_t read_adc_flag = 0;
uint8_t ok_flag = 0;

#define INIT 	0
#define RST 	1
#define OK 	2

uint8_t state_command_parser_fsm = INIT;

uint8_t check_is_ok(){
    uint8_t str_ok[4] = "!OK#";
    uint8_t index_buffer_tem = (index_buffer == 0) ? MAX_BUFFER_SIZE - 1 : index_buffer - 1;
    for(uint8_t i = 3;; i--){
        if(buffer[index_buffer_tem] != str_ok[i])
            return 0;
        index_buffer_tem = (index_buffer_tem == 0) ? MAX_BUFFER_SIZE - 1 : index_buffer_tem - 1;
        if(i == 0)
            break;
    }
    uint8_t data_send[20] = "!receive OK#\r\n";
	HAL_UART_Transmit(&huart2, data_send, sizeof(data_send) - 1, 1000);
    return 1;
}
uint8_t check_is_rst(){
    uint8_t str_ok[5] = "!RST#";
    uint8_t index_buffer_tem = (index_buffer == 0) ? MAX_BUFFER_SIZE - 1 : index_buffer - 1;
    for(uint8_t i = 4;; i--){
        if(buffer[index_buffer_tem] != str_ok[i])
            return 0;
        index_buffer_tem = (index_buffer_tem == 0) ? MAX_BUFFER_SIZE - 1 : index_buffer_tem - 1;
        if(i == 0)
        	break;
    }
    uint8_t data_send[20] = "!receive RST#\r\n";
	HAL_UART_Transmit(&huart2, data_send, sizeof(data_send) - 1, 1000);
    return 1;
}
void command_parser_fsm(){
	switch(state_command_parser_fsm){
	case INIT:
		state_command_parser_fsm = RST;
		break;
	case RST:
		if(check_is_rst()){//nếu có lệnh RST
			//đánh dấu cờ
			read_adc_flag = 1;
			state_command_parser_fsm = OK;
		}
		break;
	case OK:
		if(check_is_ok()){//nếu nhận OK
			//Đánh cờ ok
			ok_flag = 1;
			state_command_parser_fsm = RST;
			return;
		}
		if(check_is_rst()){//nếu trg hơp RST
			//bật cờ
			read_adc_flag = 1;
			return;
		}
		break;
	default: break;
	}
}
