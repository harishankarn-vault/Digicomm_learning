#ifndef UART_H_
#define UART_H_

#include "stm32f4xx.h"	// STM32F4 library
#include <stdint.h>		// Standard C library
#include <unistd.h>		// POSIX (Unix standard) header
void usart1_tx_init(void);
void usart1_rxtx_init(void);
char usart1_read(void);
void usart1_rx_interrupt_init(void);

#define SR_RXNE			(1U<<5)

#endif /* UART_H_ */
