#include "exti.h"

#define GPIOAEN   		(1U<<0) // Enable clock for GPIOA
#define SYSCFGEN		(1U<<14)
#define SYSCFG_EXTICR4

void pa0_exti_init(void){
	/*Disable global interrupt*/
	__disable_irq();

	/*Enable Clock access to GPIOA*/
    RCC->AHB1ENR |= GPIOAEN;

	/*Enable clock access for SYSCFGEN module which EXTI is part of*/
	RCC->APB2ENR |= SYSCFGEN;

	/*Explicitly making port 0 input*/
	GPIOA->MODER &= ~(3U<<0);

	/*Select PORTA for EXTI0*/
	SYSCFG->EXTICR[0] &= ~(0xF<<0); //clearing

	/*Un-mask the EXTI from IMR*/
	EXTI->IMR |= (1U<<0);

	/*Set Falling edge trigger*/
	EXTI->FTSR |= (1U<<0);

	/*Enable EXTI0 line in NVIC*/
	NVIC_EnableIRQ(EXTI0_IRQn);

	/*Enable global interrupt*/
	__enable_irq();
}
