/* Output Compare
 * This program will be implemented using PA5
 * PA5->(alternate function connected)->TIM2_CH1
 */


#include <stdio.h>		// Standard Input/Output library
#include "ADC.h"
#include "UART.h"
#include "systick.h"
#include "LED.h"
#include "timer.h"

uint32_t sensor_value;

int main(void){

	usart1_tx_init();
	LED_init();
	tim2_1hz_init();
	while(1)
	{
		/*Waiting for UIF*/
		while (!(TIM2->SR & TIM2_SR_UIF)) {}

		/*Clear UIF*/
		TIM2->SR &= ~TIM2_SR_UIF;

		printf("A Second pasted!!\n\r");
		LED_toggle(0);
		// systickDelayMs(1000);
	}
}


