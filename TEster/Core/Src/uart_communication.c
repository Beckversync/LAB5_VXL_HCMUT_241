#include "uart_communication.h"
#include <stdint.h>
#include <stdio.h>
#define INIT		0
#define READ_ADC	1
#define SHOW_ADC	2
uint8_t state_uart_communiation_fsm = INIT;
uint32_t adc_value = 0;
void uart_communiation_fsm(){
	switch(state_uart_communiation_fsm){
	case INIT:
		state_uart_communiation_fsm = READ_ADC;
		break;
	case READ_ADC:
		if(read_adc_flag){
			read_adc_flag = 0;
			ok_flag = 0;
			adc_value = HAL_ADC_GetValue(&hadc1);
			uint8_t adc_str[20];
			uint16_t size = sprintf(adc_str, "!ADC=%d#\r\n", adc_value);
			HAL_UART_Transmit(&huart2, adc_str, size, 1000);
			set_timeout_ok(300);//3 seconds
			state_uart_communiation_fsm = SHOW_ADC;
		}
		break;
	case SHOW_ADC:
		if(ok_flag || read_adc_flag){
			state_uart_communiation_fsm = READ_ADC;
			return;
		}
		if(get_timeout_ok()){
			set_timeout_ok(300);
			uint8_t adc_str[20];
			uint16_t size = sprintf(adc_str, "!ADC=%d#\r\n", adc_value);
			HAL_UART_Transmit(&huart2, adc_str, size, 1000);
		}
		break;
	default: break;
	}
}
