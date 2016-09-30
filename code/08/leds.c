#include "leds.h"

void init_leds() {
	// RCC->APB2ENR |= 0x00000008;
	// RCC->APB2ENR |= 1 << 3;
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;

	GPIOB->CRL &= ~GPIO_CRL_MODE0_0;
	GPIOB->CRL |= GPIO_CRL_MODE0_1;
	GPIOB->CRL &= ~GPIO_CRL_CNF0;
}
