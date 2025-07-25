/* Implementing timer function
 *
 * Datasheet Block diagram : TIM2 APB1 bus @ 45 MHz
 * Default Crystal MHz = 16MHz
 * */

#include "timer.h"
#define TIM2EN	 	(1U<<0)
#define SYSCLK		16000000
#define TIM2_CR_CEN	(1U<<0)

/*Time out ever 1 second*/
void tim2_1hz_init(void){
	/*Enable clock access*/
	RCC->APB1ENR |= TIM2EN;

	/* While setting value do n-1 since counting starts from 0*/
	/*Set Pre-scaler value*/
	TIM2->PSC = 1600 - 1; // 16000000/1600 = 10000

	/*Set Auto reload value*/
	TIM2->ARR =  10000 -1; // 10000/10000 = 1

	/*CLear Timer*/
	TIM2->CNT = 0;

	/*Enable Timer*/
	TIM2->CR1 |= TIM2_CR_CEN;
}

