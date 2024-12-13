#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

#include "global.h"


void set_timeout_ok(int duration);
uint8_t get_timeout_ok();

void set_timer_blink_led(int duration);
uint8_t get_timer_blink_led();

void timer_run();

#endif /* INC_SOFTWARE_TIMER_H_ */
