#include "pwm.h"

void init_pwm(void) {
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE);

	GPIO_InitTypeDef pwmGPIO;
	pwmGPIO.GPIO_Pin = GPIO_Pin_1;
	pwmGPIO.GPIO_Mode = GPIO_Mode_AF_PP;
	pwmGPIO.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &pwmGPIO);

	// TIM3, channel 4
	TIM_TimeBaseInitTypeDef pwm;
	TIM_OCInitTypeDef pwmOC;
	uint16_t PrescalerValue = 0;

	pwm.TIM_Period = 1000;
	pwm.TIM_Prescaler = PrescalerValue;
	pwm.TIM_ClockDivision = 0;
	pwm.TIM_CounterMode = TIM_CounterMode_Up;

	TIM_TimeBaseInit(TIM3, &pwm);

	pwmOC.TIM_OCMode = TIM_OCMode_PWM1;
	pwmOC.TIM_OutputState = TIM_OutputState_Enable;
	pwmOC.TIM_Pulse = 50;
	pwmOC.TIM_OCPolarity = TIM_OCPolarity_High;

	TIM_OC4Init(TIM3, &pwmOC);
	TIM_OC4PreloadConfig(TIM3, TIM_OCPreload_Enable);

	TIM_ARRPreloadConfig(TIM3, ENABLE);

	TIM_Cmd(TIM3, ENABLE);
}

void pwmBlink(void) {
	for (uint16_t i = 0; i < 1000; i++) {
		TIM_SetCompare4(TIM3, i);
		delay(1000);
	}
	for (uint16_t i = 1000; i >= 1; i--) {
		TIM_SetCompare4(TIM3, i);
		delay(1000);
	}
}
