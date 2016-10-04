#include "main.h"

u16 temperature = 0;

int main(void) {
	init_mcu();

	while (1) {
		switch (getState()) {
		case DISPLAY_TIME:
			// turn on LED1
			break;

		case DISPLAY_TEMPERATURE:
			// turn on LED2
			break;

		case SET_HOURS:
			// turn on LED3
			break;

		case SET_MINUTES:
		default:
			// turn off all LEDs
			break;
		}
	}
}

void init_mcu() {
	init_pll();
	init_leds();
	init_ds18b20(DS18B20_Resolution_12_bit);
	init_button();
}
