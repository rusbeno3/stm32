#ifndef __LEDS_H__
#define __LEDS_H__

#include "stm32f10x.h"

typedef enum {
	LED1, LED2, LED3,
} LED;

void init_leds(void);

#endif /* __LEDS_H__ */
