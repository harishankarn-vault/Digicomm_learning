#include "stm32f429xx.h"
#include "header.h"
#define addr 0x42
volatile char r;
 
void init_config()
{
	i2c1_gpio_config();
	i2c1_config();
	i2c2_gpio();
	i2c2_config();
	sys_config();
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	
	GPIOG->MODER &= ~( 3<<(14*2));
	
	GPIOG->MODER |= (1 << (14*2));
}
int main()
{
	init_config();
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	
	GPIOG->MODER &= ~(3<<(13*2));

	GPIOG->MODER |= (1 << (13*2));

	
	  I2C1_start();
		I2C1_write(addr,'A');
	  r = slave_receive();

	while (1)
{
    if (r == 'A')
    {
        GPIOG->ODR |= (1 << 13);  // Turn ON LED on PG13
    }
    else
    {
        GPIOG->ODR &= ~(1 << 13); // Turn OFF LED
    }
}
	
}