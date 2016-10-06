#ifndef __DS18B20_H__
#define __DS18B20_H__

#include "stm32f10x.h"

#include "utils.h"

typedef enum {
	DS18B20_Resolution_9_bit 	= 0x1F,
	DS18B20_Resolution_10_bit 	= 0x3F,
	DS18B20_Resolution_11_bit 	= 0x5F,
	DS18B20_Resolution_12_bit 	= 0x7F
} DS18B20_Resolution;

void init_ds18b20(DS18B20_Resolution resolution);
void setResolution(DS18B20_Resolution resolution);
uint16_t ds18b20_getTemperature();

#endif /* __DS18B20_H__ */
