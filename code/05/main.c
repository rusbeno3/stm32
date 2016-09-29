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
//	SysTick->LOAD = 24000000UL/1000 - 1;
//	SysTick->VAL = 24000000UL/1000 - 1;
//	SysTick->CTRL= SysTick_CTRL_CLKSOURCE_Msk |
//	                SysTick_CTRL_TICKINT_Msk   |
//	                SysTick_CTRL_ENABLE_Msk;
	SysTick_Config(SystemCoreClock/1000);
}
