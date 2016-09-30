#include "stm32f10x_it.h"

void HardFault_Handler() {
	while(1);
}

void MemManage_Handler() {
	while(1);
}

void BusFault_Handler() {
	while(1);
}

void UsageFault_Handler() {
	while(1);
}

static volatile uint8_t flag = 0;

void EXTI3_IRQHandler(void) {
	if (flag) {
		GPIOB->ODR |= GPIO_ODR_ODR0;
		flag = 0;
	} else {
		GPIOB->ODR &= ~GPIO_ODR_ODR0;
		flag = 1;
	}
	EXTI->PR |= EXTI_PR_PR3;
}
