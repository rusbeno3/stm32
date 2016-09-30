#ifndef __STM32F10x_IT_H__
#define __STM32F10x_IT_H__

#include "stm32f10x.h"

#include "leds.h"

void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);

void EXTI3_IRQHandler(void);

#endif /* __STM32F10x_IT_H__ */
