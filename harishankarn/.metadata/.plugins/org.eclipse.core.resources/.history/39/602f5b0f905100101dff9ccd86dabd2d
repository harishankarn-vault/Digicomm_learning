// Find where the led is connected to the board in schematic
// Board : STM32F429ZI
// Port: Port G
// Pin: 13 [MODER bit 27:26]
// Address Bus : AHB1 180 MHZ @ GPIO - G

// address G start : 0x4002 1800
// address G end : 0x4002 1BFF

// AHB1 start : 0x4002 0000
// AHB1 end : 0x4001 3FFF

// RCC base : 0x4002 3800 - 0x4002 3BFF

#define PERHI_BASE          (0x40000000UL)

#define AHB1PERIPH_OFFSET   (0x00020000UL)
#define AHB1PERIPH_BASE     (PERHI_BASE + AHB1PERIPH_OFFSET)  	// 0x4002 0000

#define GPIOG_OFFSET        (0x1800UL)                  		// relative to AHB1 base
#define GPIOG_BASE          (AHB1PERIPH_BASE + GPIOG_OFFSET)	// 0x4002 1800

#define RCC_OFFSET  		(0x3800UL)  // RCC relative to AHB1 base
#define RCC_BASE			(AHB1PERIPH_BASE + RCC_OFFSET)		// 0x4002 3800

#define AHB1EN_R_OFFSET		(0x30UL)
#define RCC_AHB1EN_R		(*(volatile unsigned int *)(RCC_BASE + AHB1EN_R_OFFSET))

#define MODE_R_OFFSET 		(0x00UL)
#define GPIOG_MODE_R		(*(volatile unsigned int *)(GPIOG_BASE + MODE_R_OFFSET))

#define OD_R_OFFSET			(0x14)
#define GPIOG_OD_R			(*(volatile unsigned int *)(GPIOG_BASE + OD_R_OFFSET))

#define GPIOGEN  			(1U<<6)

#define PIN13				(1U<<13)
#define LED_PIN 			PIN13

int main(void){
	/* 1. Enable clock access to GPIOG */
	RCC_AHB1EN_R |= GPIOGEN;

	/* 2. set PG13 as output pin */
	GPIOG_MODE_R |= (1U<<26); 	// sets only Bit 26 to one
	GPIOG_MODE_R &= ~(1U<<27);	// sets only Bit 27 to zero

	while(1){

		/* 3. Set PG13 to high*/
		// GPIOG_OD_R |= LED_PIN;

		/* 4. Toggle experiment*/
		GPIOG_OD_R ^= LED_PIN;
		for(int i=0;i<100000;i++);

	}
}



