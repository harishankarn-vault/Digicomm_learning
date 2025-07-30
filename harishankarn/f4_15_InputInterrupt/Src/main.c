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
#include "exti.h"

static void exti_callback();

int main(void){

	pa0_exti_init();
	usart1_tx_init();
	while(1)
	{
	}
}

static void exti_callback(){
	printf("button pressed\n\r");
	for(int i=0;i<1000000;i++){}
	LED_ON();
}

void EXTI0_IRQHandler(void){
	if(EXTI->PR & LINE0){
		EXTI->PR |= LINE0;  // Clear interrupt flag by writing 1
		exti_callback();    // Your custom logic
	}
}


