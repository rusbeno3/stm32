#include "utils.h"

void init_pll(void) {
	RCC_DeInit();
	
	RCC_HSICmd(ENABLE);
	while (!RCC_GetFlagStatus(RCC_FLAG_HSIRDY));
	
	RCC_PLLConfig(RCC_PLLSource_HSI_Div2, RCC_PLLMul_6);
	
	RCC_PLLCmd(ENABLE);
	while (!RCC_GetFlagStatus(RCC_FLAG_PLLRDY));
	
	FLASH_SetLatency(FLASH_Latency_1);
	FLASH_PrefetchBufferCmd(FLASH_PrefetchBuffer_Enable);
	
	RCC_HCLKConfig(RCC_SYSCLK_Div1);
	RCC_PCLK1Config(RCC_HCLK_Div1);
	RCC_PCLK2Config(RCC_HCLK_Div1);
	
	RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
	while (RCC_GetSYSCLKSource() != 0x08);
	SystemCoreClockUpdate();
}

void delay(uint32_t time) {
  if (time > SYSTICK_MAX_VALUE)
    return;
  SysTick->CTRL &= ~SysTick_CTRL_TICKINT_Msk;
  SysTick->CTRL |= SysTick_CTRL_CLKSOURCE_Msk;
  SysTick->LOAD = (SystemCoreClock / 1000000 * time);
  SysTick->VAL = 0;
  SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
  while (!(SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk));
  SysTick->CTRL &= ~SysTick_CTRL_COUNTFLAG_Msk;
  SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk;
}
