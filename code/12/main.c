#include "main.h"

u16 temperature = 0;

int main(void) {
	init_mcu();

	while (1) {
		switch (getState()) {
		case DISPLAY_TIME:
			pwmBlink();
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
			GPIO_ResetBits(GPIOB, GPIO_Pin_0);
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
