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
#include "UART.h"

#define GPIOGEN  			(1U<<6)

#define PIN13				(1U<<13)
#define LED_PIN 			PIN13

char key;

int main(void){
	usart1_rxtx_init();
	/* 1. Enable clock access to GPIOG */
	RCC->AHB1ENR |= GPIOGEN;

	/* 2. set PG13 as output pin */
	GPIOG->MODER |= (1U<<26); 	// sets only Bit 26 to one
	GPIOG->MODER &= ~(1U<<27);	// sets only Bit 27 to zero

	while(1)
	{
		key = usart1_read();
		if (key == '1'){
			GPIOG->ODR |=  LED_PIN;
		}
		else{
			GPIOG->ODR &=  ~LED_PIN;
		}
	}
}


