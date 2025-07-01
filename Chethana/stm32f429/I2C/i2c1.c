#include "stm32f429xx.h"
#include "header.h"
#define addr 0x42
void i2c1_gpio_config()
{
	//Enable the clock for GPIO port B.
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	
	//Enable the clock for I2C peripheral.
	RCC->APB1ENR |= (1<<21);
	
	
	/* Select the mode for GPIO */
	
	//clear the bits for PB6(SCL) and PB7(SDA)
	GPIOB->MODER &= ~( 3<<(6*2) | 3<<(7*2));
	
	//Setting the bits for pin 6 and 7
	GPIOB->MODER |= (2 << (6*2) | 2 << (7*2));
	
	//Set output type to open drain, PB6 and PB7
	GPIOB->OTYPER |= (1<<6) | (1<<7);
	
	//Set output speed to high
	GPIOB->OSPEEDR |= (2 << (6*2) | 2 << (7*2));
	
	//Set the port to pull up 
	GPIOB->PUPDR &= ~(1 << (6*2) | 1 << (7*2));
	GPIOB->PUPDR |= (1 << (6*2) | 1 << (7*2));
	
	//Set GPIO Port B as alternate function register.
	GPIOB->AFR[0] |= ( 4 << (6*4) | 4 << (7*4));
}	

void i2c1_config()
{
	I2C1->CR1=0;
	//reset the I2C
	//when SWRST bit is set, it resets the peripheral
	I2C1->CR1 |= (1<<15);
	I2C1->CR1 &= ~(1<<15);
	
	//setting up the peripheral clk
	/* Note : From stm32 cube id3 clk configuration table, APB1 runs on 
	    36MHz
	   From keil, system configuration, the system clk is 16MHz, i am confused
	   which to use, so i will be writing both.
	  From the data sheet, APB1 runs on 45MHz, if we want to use 45MHz, 
	  we should manually write the clk configuration again.
	  
	*/
	
	//I2C1->CR2 |= (16<<0);
	 I2C1->CR2 |= (36<<0);
	//I2C1->CR2 |= (42<<0);
	//I2C1->CR2 |=(45<<0);
	
	//Clk control Register
	//I2C1->CCR=80;//16MHz
	I2C1->CCR=180;//36MHz
		//I2C1->CCR=210;//42MHz
	//I2C1->CCR=225;//45MHz
	
	// I2C1->TRISE = 17;//16MHz
	I2C1->TRISE = 37;//36MHz
	//I2C1->TRISE = 43;//42MHz
	//I2C1->TRISE = 46;//45MHz
	
	//Enable the peripheral using I2C_CR1 register.
	I2C1->CR1 |=I2C_CR1_PE;
	
}
void I2C1_start()
{
	//Set the START bit.
	// Setting the START bit causes the interface to generate a Start condition and
//	to switch to master mode

	I2C1->CR1 |=I2C_CR1_START;//start condition is ntg 
	
	//wait till SB bit is set, indicates the start condition is sent
	while(!(I2C1->SR1 & I2C_SR1_SB));
	
	
}
void I2C1_stop()
{
	//Set the STOP bit to stop the communication
	I2C1->CR1 |= I2C_CR1_STOP;
}
void I2C1_write(uint8_t add,char data)
{
	//send the address, send address and set R/W bit as 0.
	I2C1->DR=(add << 1) | (0 << 0);
	
	//Wait for the address bit to be set, 
	//ADDR is set means the address matches with that of the slave
	while(!(I2C1->SR1 & I2C_SR1_ADDR));

	//Read the SR1 and SR2 registers to clear the ADDR bit
	uint8_t temp = I2C1->SR2 | I2C1->SR1;
	//(void)I2C1->SR2;
	
	//The hardware sets the AF bit, if no ACK is received.
	if (I2C1->SR1 & I2C_SR1_AF)
		{
        I2C1->SR1 &= ~I2C_SR1_AF;  // Clear NACK flag
        I2C1_stop();  // Stop transmission
			     GPIOG->ODR |= (1 << 14); 
        return;  // Exit on error
    }
	
	
	//Transmit the data
	//I2C1->DR=data;
	//wait for the txe bit to set
	//If TXE bit is set, that means the DR is empty
	while(!(I2C1->SR1 & I2C_SR1_TXE));
	
	//Transmit the data
	I2C1->DR=data;
	
	//wait for the BTF bit to set
	while(!(I2C1->SR1 & I2C_SR1_BTF));
		I2C1_stop();
}


void I2C_writemulti(uint32_t *data,uint8_t size)
{
	//wait for the txe bit to set
	while(!(I2C1->SR1 & I2C_SR1_TXE));
	while(size)
	{
		//wait for the txe bit to set
		while(!(I2C1->SR1 & I2C_SR1_TXE));
	I2C1->DR = (volatile uint32_t) *data++;
		size--;
	}
	while(!(I2C1->SR1 & I2C_SR1_BTF));
}
	