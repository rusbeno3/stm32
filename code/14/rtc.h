#ifndef __RTC_H__
#define __RTC_H__

#include "stm32f10x.h"

#define BACKUP_REGISTER_VALUE 0xA5A5

void rtc_init(void);
void setTime(uint32_t time);

#endif /* __RTC_H__ */
