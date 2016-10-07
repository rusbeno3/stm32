#include "main.h"

int main(void) {
	init_mcu();

	uint8_t time[4];
	timeToDigits(17, 40, time);

	while (1) {
		switch (getState()) {
		case DISPLAY_TIME:
			displayTime(time);
			break;

		case DISPLAY_TEMPERATURE:
			break;

		case SET_HOURS:
			break;

		case SET_MINUTES:
		default:
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
	init_max7219(5);
}
