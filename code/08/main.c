#include "main.h"

u16 temperature = 0;

int main(void) {
	init_mcu();

	while (1) {
		temperature = ds18b20_getTemperature();
		delay(ONE_SECOND);
	}
}

void init_mcu() {
	init_pll();
	init_leds();
	init_ds18b20(DS18B20_Resolution_12_bit);
	init_button();
}
