#ifndef __UTILS_H__
#define __UTILS_H__

#include "stm32f10x.h"

#define SYSTICK_MAX_VALUE 16777215
#define ONE_SECOND SYSTICK_MAX_VALUE

void init_pll(void);
void delay(uint32_t time);

#endif /* __UTILS_H__ */
