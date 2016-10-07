#ifndef __MAX7219_H__
#define __MAX7219_H__

#include "stm32f10x.h"

void init_max7219(uint8_t intensivity);

void displayTemperature(uint8_t* array);
void displayTime(uint8_t* array);
void displayEncoder(uint8_t* array);

void max7219_setIntensivity(uint8_t intensivity);

#endif /* __MAX7219_H__ */
