#ifndef __ENCODER_H__
#define __ENCODER_H__

#include "stm32f10x.h"

void init_encoder(void);
uint16_t getEncoderValue(void);

#endif /* __ENCODER_H__ */
