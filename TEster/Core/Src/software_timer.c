#include "software_timer.h"

int timeout_ok_count;
uint8_t timeout_ok_flag;
void set_timeout_ok(int duration){
	timeout_ok_count = duration;
	timeout_ok_flag = 0;
}
uint8_t get_timeout_ok(){
	return timeout_ok_flag;
}

int timer_blink_led_count;
uint8_t timer_blink_led_flag;
void set_timer_blink_led(int duration){
	timer_blink_led_count = duration;
	timer_blink_led_flag = 0;
}
uint8_t get_timer_blink_led(){
	return timer_blink_led_flag;
}

void timer_run(){
	timeout_ok_count --;
	if(timeout_ok_count <= 0){
		timeout_ok_flag = 1;
	}

	timer_blink_led_count --;
	if(timer_blink_led_count <= 0){
		timer_blink_led_flag = 1;
	}
}
