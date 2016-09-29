#include "main.h"

int main(void) {
	init_mcu();

	while (1) {
		GPIOB->ODR ^= GPIO_ODR_ODR0;
		delay(ONE_SECOND);
	}
}

void init_mcu() {
	init_pll();
	init_leds();
}
