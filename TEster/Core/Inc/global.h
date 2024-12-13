
#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "main.h"
#include "comand_parser.h"
#include "uart_communication.h"
#include "software_timer.h"


extern uint8_t read_adc_flag;
extern uint8_t ok_flag;

extern uint8_t is_begin;          // flag using to indicate receiving '!'
extern uint8_t temp;              // character received from UART
#define MAX_BUFFER_SIZE 128       // Kích thước tối đa của buffer
extern uint8_t buffer[256]; // Buffer lưu dữ liệu UART
extern uint8_t index_buffer;      // Chỉ số của buffer

// UART và ADC handle (đã được cấu hình trong CubeMX)
extern UART_HandleTypeDef huart2; // Được định nghĩa trong main.c hoặc các file liên quan
extern ADC_HandleTypeDef hadc1;

extern uint8_t buffer_flag;       // it will set when receive '#' after '!' and other bytes data

#endif /* INC_GLOBAL_H_ */
