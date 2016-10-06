#include "encoder.h"

void init_encoder(void) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef encoder;
	encoder.GPIO_Mode = GPIO_Mode_IPU;
	encoder.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1;
	GPIO_Init(GPIOA, &encoder);

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

	TIM_TimeBaseInitTypeDef timer;
	TIM_TimeBaseStructInit(&timer);
	timer.TIM_Prescaler = 0;
	timer.TIM_Period = 256;
	timer.TIM_CounterMode = TIM_CounterMode_Down | TIM_CounterMode_Up;
	TIM_TimeBaseInit(TIM2, &timer);

	TIM_EncoderInterfaceConfig(TIM2, TIM_EncoderMode_TI1, TIM_ICPolarity_Rising,
			TIM_ICPolarity_Rising);
	// TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
	// NVIC_EnableIRQ(TIM2_IRQn);

	TIM_Cmd(TIM2, ENABLE);
}

uint16_t getEncoderValue(void) {
	return TIM_GetCounter(TIM2);
}
