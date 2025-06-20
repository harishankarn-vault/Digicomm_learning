// Find where the led is connected to the board in schematic
// Board : STM32F103C8T6
// Port: Port c
// Pin: 13
// Address Bus : APB2 180 MHZ @ GPIO - G

// address C start : 0x4001 1000
// address C end : 0x4001 13FF

// APB2 start : 0x4001 0000
// APB2 end : 0x4001 3FFF

// RCC base : 0x4002 1000 - 0x400213FF

#define PERHI_BASE          (0x40000000UL)

#define APB2PERIPH_OFFSET   (0x00010000UL)
#define APB2PERIPH_BASE     (PERHI_BASE + APB2PERIPH_OFFSET)  	// 0x4001 0000

#define GPIOC_OFFSET        (0x1000UL)                  		// relative to APB2 base
#define GPIOC_BASE          (APB2PERIPH_BASE + GPIOC_OFFSET)	// 0x4001 1000

#define RCC_BASE            (0x40021000UL)  // RCC base is fixed on AHB, not relative to APB2

#define APB2EN_R_OFFSET     (0x18UL)
#define RCC_APB2EN_R        (*(volatile unsigned int *)(RCC_BASE + APB2EN_R_OFFSET))

#define GPIOC_CRH_OFFSET    (0x04UL)
#define GPIOC_CRH           (*(volatile unsigned int *)(GPIOC_BASE + GPIOC_CRH_OFFSET))

#define OD_R_OFFSET         (0x0CUL)
#define GPIOC_OD_R          (*(volatile unsigned int *)(GPIOC_BASE + OD_R_OFFSET))

#define GPIOCEN             (1U<<4)

#define PIN13				(1U<<13)
#define LED_PIN 			PIN13

/*
 * (1U<<26) // sets only Bit 26 to one
 * &= ~(1U<<27) // sets only Bit 27 to zero
 */

int main(void){
	/* 1. Enable clock access to GPIOC */
	RCC_APB2EN_R |= GPIOCEN;

	/* 2. Set PC13 as output pin */
	GPIOC_CRH &= ~(0xF << 20);		// Clear CNF and MODE for pin 13 (bits 23:20)
	GPIOC_CRH |=  (0x1 << 20);		// MODE = 01 (Output, max 10 MHz), CNF = 00 (Push-pull)

	while(1){
		/* 3. Toggle PC13 */
		GPIOC_OD_R ^= LED_PIN;
		for(int i=0; i<100000; i++);  // crude delay
	}
}
