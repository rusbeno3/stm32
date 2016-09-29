#include "main.h"

int main(void) {
	init_mcu();

	while (1) {
		GPIOB->ODR |= GPIO_ODR_ODR0;
		for (uint32_t i = 0; i < 1e5; i++)
			asm("nop");
		GPIOB->ODR &= ~GPIO_ODR_ODR0;
		for (uint32_t i = 0; i < 1e5; i++)
			asm("nop");
//		GPIOB->ODR ^= GPIO_ODR_ODR0;
//		for (u32 i = 0; i < 1e5; i++);
	}
}

void init_mcu() {
	init_pll();
	init_leds();
}
