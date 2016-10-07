#include "max7219.h"

typedef enum {
	REG_NO_OP 			= 0x00 << 8,
	REG_DIGIT_0 		= 0x01 << 8,
	REG_DIGIT_1 		= 0x02 << 8,
	REG_DIGIT_2 		= 0x03 << 8,
	REG_DIGIT_3 		= 0x04 << 8,
	REG_DIGIT_4 		= 0x05 << 8,
	REG_DIGIT_5 		= 0x06 << 8,
	REG_DIGIT_6 		= 0x07 << 8,
	REG_DIGIT_7 		= 0x08 << 8,
	REG_DECODE_MODE 	= 0x09 << 8,
	REG_INTENSITY 		= 0x0A << 8,
	REG_SCAN_LIMIT 		= 0x0B << 8,
	REG_SHUTDOWN 		= 0x0C << 8,
	REG_DISPLAY_TEST 	= 0x0F << 8,
} MAX7219_REGISTERS;

typedef enum {
	DIGIT_1 = 1, DIGIT_2 = 2, DIGIT_3 = 2, DIGIT_4 = 2
} MAX7219_Digits;

void max7219_clean(void);
void sendData(uint16_t data);

static uint16_t SYMBOLS[] = { 0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70,
		0x7F, 0x7B, 0x00 };

void init_max7219(uint8_t intensivity) {
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_IOPAEN, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2ENR_SPI1EN, ENABLE);

	GPIO_InitTypeDef pins;
	SPI_InitTypeDef spi;

	pins.GPIO_Mode = GPIO_Mode_AF_PP;
	pins.GPIO_Speed = GPIO_Speed_50MHz;
	pins.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_7; // MISO, SCK
	GPIO_Init(GPIOA, &pins);

	pins.GPIO_Mode = GPIO_Mode_Out_PP;
	pins.GPIO_Pin = GPIO_Pin_6; // CS
	GPIO_Init(GPIOA, &pins);
	GPIO_SetBits(GPIOA, GPIO_Pin_6);

	spi.SPI_Direction = SPI_Direction_1Line_Tx;
	spi.SPI_DataSize = SPI_DataSize_16b;
	spi.SPI_CPOL = SPI_CPOL_Low;
	spi.SPI_CPHA = SPI_CPHA_1Edge;
	spi.SPI_NSS = SPI_NSS_Soft;
	spi.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_16;
	spi.SPI_FirstBit = SPI_FirstBit_MSB;
	spi.SPI_Mode = SPI_Mode_Master;

	SPI_Init(SPI1, &spi);
	SPI_Cmd(SPI1, ENABLE);

	SPI_NSSInternalSoftwareConfig(SPI1, SPI_NSSInternalSoft_Set);

	max7219_setIntensivity(intensivity);
	max7219_clean();
}

void max7219_setIntensivity(uint8_t intensivity) {
	if (intensivity > 0x0F)
		return;
	sendData(REG_SHUTDOWN | 0x01);
	sendData(REG_DECODE_MODE | 0x00);
	sendData(REG_SCAN_LIMIT | 0x03);
	sendData(REG_INTENSITY | intensivity);
}

void max7219_clean() {
	sendData(REG_DIGIT_0 | 0x00);
	sendData(REG_DIGIT_1 | 0x00);
	sendData(REG_DIGIT_2 | 0x00);
	sendData(REG_DIGIT_3 | 0x00);
}

void sendData(uint16_t data) {
	SPI_I2S_SendData(SPI1, data);
	while (SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_BSY) == SET);
	GPIO_ResetBits(GPIOA, GPIO_Pin_6);
	// asm("nop");
	GPIO_SetBits(GPIOA, GPIO_Pin_6);
}

uint16_t getSymbol(uint8_t number) {
	return SYMBOLS[number];
}

void displayTime(uint8_t* array) {
	sendData(REG_SHUTDOWN | 0x01);
	sendData(REG_DECODE_MODE | 0x00);
	sendData(REG_SCAN_LIMIT | 0x03);
	sendData(REG_DIGIT_0 | getSymbol(array[0]));
	sendData(REG_DIGIT_1 | getSymbol(array[1]) | (1 << 7)); // +dot
	sendData(REG_DIGIT_2 | getSymbol(array[2]));
	sendData(REG_DIGIT_3 | getSymbol(array[3]));
}

void displayTemperature(uint8_t* array) {
	sendData(REG_SHUTDOWN | 0x01);
	sendData(REG_DECODE_MODE | 0x00);
	sendData(REG_SCAN_LIMIT | 0x03);
	sendData(REG_DIGIT_0 | 0x00);
	sendData(REG_DIGIT_1 | getSymbol(array[0]));
	sendData(REG_DIGIT_2 | getSymbol(array[1]) | (1 << 7));
	sendData(REG_DIGIT_3 | getSymbol(array[2]));
}

void displayEncoder(uint8_t* array) {
	sendData(REG_SHUTDOWN | 0x01);
	sendData(REG_DECODE_MODE | 0x00);
	sendData(REG_SCAN_LIMIT | 0x03);
	sendData(REG_DIGIT_0 | 0x00);
	sendData(REG_DIGIT_1 | getSymbol(array[1]));
	sendData(REG_DIGIT_2 | getSymbol(array[2]));
	sendData(REG_DIGIT_3 | getSymbol(array[3]));
}
