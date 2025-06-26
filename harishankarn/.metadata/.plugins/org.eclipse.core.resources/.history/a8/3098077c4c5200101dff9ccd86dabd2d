/*	Find where USB B connection is connected with board via UART/USART
 *	Board : STM32F429ZI
 * 	This USB communicates via Virtual COMM Port through USART1
 * 	USART1 address : 0x4001 1000 - 0x4001 13FF
 * 	TX_Port: Port A
 * 	TX_Pin: 9
 *
 *	RX_Port: Port A
 *	RX_Pin: 10
 *
 *	Address Bus : APB2 90 MHZ @ USART1
 *
 * 	USART1 uses GPIOA : PA09(TX) PA10(RX)
 * 	So,
 * 		- need to map with alternate function mapping in Data sheet
 * 		- find type of alternate function (AF7)
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


