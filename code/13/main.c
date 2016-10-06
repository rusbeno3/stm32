#include "main.h"

u16 temperature = 0;

int main(void) {
	init_mcu();

	// 22h 53m 20s
	// setTime(22*60*60 + 53*60 + 20);

	while (1) {
		switch (getState()) {
		case DISPLAY_TIME:
			if (RTC_GetCounter() % 2)
				GPIO_SetBits(GPIOB, GPIO_Pin_0);
			else
				GPIO_ResetBits(GPIOB, GPIO_Pin_0);
			break;

		case DISPLAY_TEMPERATURE:
			GPIO_SetBits(GPIOB, GPIO_Pin_0);
			delay(50000);
			GPIO_ResetBits(GPIOB, GPIO_Pin_0);
			delay(50000);
			break;

		case SET_HOURS:
			GPIO_SetBits(GPIOB, GPIO_Pin_0);
			delay(getEncoderValue() * 10000);
			GPIO_ResetBits(GPIOB, GPIO_Pin_0);
			delay(getEncoderValue() * 10000);
			break;

		case SET_MINUTES:
		default:
			pwmBlink();
			break;
		}
	}
}

void init_mcu() {
	init_pll();
	init_leds();
	init_ds18b20(DS18B20_Resolution_12_bit);
	init_button();
	init_encoder();
	init_pwm();
}
