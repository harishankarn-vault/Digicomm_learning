#include "stm32f429xx.h"
#include "header.h"
#define addr 0x42
/*void i2c2_gpio()
{
	//Enable the clock for I2C peripheral.
	RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;
	
	//Enable the clock for GPIO port F.
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	
	// Select the mode for GPIO 
	
	//clear the bits for PF0(SDA) and PF1(SCL)
	GPIOF->MODER &= ~( 3<<(0*2) | 3<<(1*2));
	
	//Setting the bits for pin 0 and 1
	GPIOF->MODER |= (2 << (0*2) | 2 << (1*2));
	
	//Set output type to open drain, PF0 and PF1
	GPIOF->OTYPER |= (1<<0) | (1<<1);
	
	//Set output speed to high
	GPIOF->OSPEEDR |= (2 << (0*2) | 2 << (1*2));
	
	//Set the port to pull up 
	GPIOF->PUPDR &= ~((3 << (0 * 2)) | (3 << (1 * 2)));
	GPIOF->PUPDR |= (1 << (0*2) | 1 << (1*2));
	
	//Set GPIO Port B as alternate function register.
	GPIOF->AFR[0] &= ~( (0xF << (0*4)) | (0xF  << (1*4)));
	GPIOF->AFR[0] |= ( 4 << (0*4) | 4 << (1*4));	
}
*/
void i2c2_gpio()
{
	//Enable the clock for GPIO port B
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	
	//Enable the clock for I2C peripheral.
	RCC->APB1ENR |= RCC_APB1ENR_I2C2EN;

	// Select the mode for GPIO 
	
	//clear the bits for PB10(SCL) and PB11(SDA)
	GPIOB->MODER &= ~( 3<<(10*2) | 3<<(11*2));	
	//Setting the bits as AF(10) for pin 10 and 11
	GPIOB->MODER |= (2 << (10*2) | 2 << (11*2));
	
	//Set output type to open drain, PB10 and PB11
	GPIOB->OTYPER |= (1<<10) | (1<<11);
	
	//Set output speed to high
	GPIOB->OSPEEDR |= (2 << (10*2) | 2 << (11*2));
	
	//Set the port to pull up 
	GPIOB->PUPDR &= ~((3 << (10 * 2)) | (3 << (11 * 2)));
	GPIOB->PUPDR |= (1 << (10*2) | 1 << (11*2));
	
	//Set GPIO Port B as alternate function register.
	GPIOB->AFR[1] &= ~( (0xF << ((10-8)*4)) | (0xF  << ((11-8)*4)));
	GPIOB->AFR[1] |= ( 4 << ((10-8)*4) | 4 << ((11-8)*4));	
}

void i2c2_config()
{
	I2C2->CR1=0;
	//By default i2c will be operating in slave mode
	
	//setting the clk
	//I2C2->CR2 = 16;
	 I2C2->CR2 = 36;
//	 I2C2->CR2 = 42;
	//I2C2->CR2 = 45;
	
	//Set own slave address
	I2C2->OAR1 = (addr<<1);
	
	//Set ADDMODE bit as 0, as we are choosing 7 bit address
	I2C2->OAR1 &= ~(I2C_OAR1_ADDMODE);
	
	//I2C2->CCR=80;//16MHz
	I2C2->CCR=180;//36MHz
	//I2C2->CCR=210;//42MHz
	//I2C2->CCR=225;//45MHz
	
	//I2C2->TRISE = 17;//16MHz
	I2C2->TRISE = 37;//36MHz
	//I2C2->TRISE = 43;//42MHz
	//I2C2->TRISE = 46;//45MHz
	
	//Enable the ACK
	I2C2->CR1 |= I2C_CR1_ACK;
	
	//Enable the peripheral
	I2C2->CR1 |= I2C_CR1_PE;
	
	
}
char slave_receive()
{
	volatile uint16_t temp;
	while(!(I2C2->SR1 & I2C_SR1_ADDR));
	 temp=I2C2->SR1 | I2C2->SR2;
	
	//wait for the RXNE is set
	while(!(I2C2->SR1 & I2C_SR1_RXNE)); 
	
	//read the received byte
	char rec = I2C2->DR;
	
	//wait for the STOP bit to set
	while(!(I2C2->SR1 & I2C_SR1_STOPF));
	temp=I2C2->SR1;
	I2C2->CR1 |=0;
	
	return rec;
}
	
	
	
	