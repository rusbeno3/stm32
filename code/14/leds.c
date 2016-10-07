#include "leds.h"

void init_leds() {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);

	GPIO_InitTypeDef LED;
	LED.GPIO_Pin = GPIO_Pin_0;
	LED.GPIO_Speed = GPIO_Speed_2MHz;
	LED.GPIO_Mode = GPIO_Mode_Out_PP;

	GPIO_Init(GPIOB, &LED);
}
