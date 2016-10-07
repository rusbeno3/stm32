#include "rtc.h"

void rtc_init(void) {
	/* Backup data register value is not correct or not yet programmed (when
	 the first time the program is executed) */
	if (BKP_ReadBackupRegister(BKP_DR1) != BACKUP_REGISTER_VALUE) {
		/* Enable PWR and BKP clocks */
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);

		/* Allow access to BKP Domain */
		PWR_BackupAccessCmd(ENABLE);

		/* Reset Backup Domain */
		BKP_DeInit();

		/* Enable LSE */
		RCC_LSEConfig(RCC_LSE_ON);

		/* Wait till LSE is ready */
		while (RCC_GetFlagStatus(RCC_FLAG_LSERDY) == RESET) {
		}

		/* Select LSE as RTC Clock Source */
		RCC_RTCCLKConfig(RCC_RTCCLKSource_LSE);

		/* Enable RTC Clock */
		RCC_RTCCLKCmd(ENABLE);

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();

		/* Set RTC prescaler: set RTC period to 1sec */
		RTC_SetPrescaler(32767); /* RTC period = RTCCLK/RTC_PR = (32.768 KHz)/(32767+1) */

		/* Wait until last write operation on RTC registers has finished */
		RTC_WaitForLastTask();

		// set 00
		setTime(1000);

		BKP_WriteBackupRegister(BKP_DR1, BACKUP_REGISTER_VALUE);
	} else {
		RCC_APB1PeriphClockCmd(RCC_APB1Periph_PWR | RCC_APB1Periph_BKP, ENABLE);
		PWR_BackupAccessCmd(ENABLE);
		RCC_RTCCLKCmd(ENABLE);
	}

	RCC_ClearFlag();
}

void setTime(uint32_t time) {
	RTC_WaitForLastTask();
	RTC_SetCounter(time);
	RTC_WaitForLastTask();
}
