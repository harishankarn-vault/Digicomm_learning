#ifndef TIMER_H_
#define TIMER_H_
#include "stm32f4xx.h"
#define TIM2_SR_UIF	(1U<<0)

void tim2_1hz_init(void);

#endif /* TIMER_H_ */
