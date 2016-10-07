#include "button.h"

void init_button() {
	// PA3 - floating input
	GPIOA->CRL &= ~GPIO_CRL_MODE3;
	GPIOA->CRL |= GPIO_CRL_CNF3_1;
	GPIOA->CRL &= ~GPIO_CRL_CNF3_0;

	NVIC_EnableIRQ(EXTI3_IRQn);
	EXTI->IMR |= EXTI_IMR_MR3;
	EXTI->RTSR |= EXTI_RTSR_TR3;
	EXTI->FTSR &= ~EXTI_FTSR_TR3;
}
