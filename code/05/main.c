#include "main.h"

int main(void) {
	init_mcu();

	while (1) {
		GPIOB->ODR ^= GPIO_ODR_ODR0;
		delay(1000);
	}
}

void init_mcu() {
	init_pll();
	init_leds();
	SysTick_Config(SystemCoreClock/1000);
}
