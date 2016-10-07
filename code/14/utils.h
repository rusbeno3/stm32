#ifndef __UTILS_H__
#define __UTILS_H__

#include "stm32f10x.h"

#define SYSTICK_MAX_VALUE 16777215
#define ONE_SECOND SYSTICK_MAX_VALUE

typedef enum {
	DISPLAY_TIME,
	DISPLAY_TEMPERATURE,
	SET_HOURS,
	SET_MINUTES
} STATES_t;

STATES_t getState(void);
void setState(STATES_t newState);

void init_pll(void);
void delay(uint32_t time);
void timeToDigits(uint8_t hours, uint8_t minutes, uint8_t* result);

#endif /* __UTILS_H__ */
