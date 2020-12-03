/*******************
 rvrobotics.ru
 RV_ST7735_ver_1.0
 Ruslan Vorovchenko
*******************/
#include "RV_ST7735.h"
#include "font.h"
#include "stm32f1xx_hal.h"
extern SPI_HandleTypeDef hspi1;

//������ ����� ( � ������� �� �������� ��� uint8_t
int abs(int x) {
  if (x < 0)
    return (uint8_t)(-x);
  else
    return (uint8_t)(x);
}
//�������� ���������
void RV_ST7735_LED_ON(void) {
	LCD_ST7735_LED_1;
}
//��������� ���������
void RV_ST7735_LED_OFF(void) {
	LCD_ST7735_LED_0;
}
//�������� ������ �� SPI
void RV_ST7735_SEND(uint8_t data) {
	HAL_SPI_Transmit(&hspi1, &data, 1, 10);
}
//������� �������
void RV_ST7735_SEND_CMD(uint8_t cmd) {
  LCD_ST7735_A0_0;
  RV_ST7735_SEND(cmd);
}
//������� ������
void RV_ST7735_SEND_DATA(uint8_t data) {
  LCD_ST7735_A0_1;
  RV_ST7735_SEND(data);
}
//����������� ������� �������
void RV_ST7735_AT(uint8_t startX, uint8_t startY, uint8_t stopX, uint8_t stopY) {
	RV_ST7735_SEND_CMD(0x2A);
	RV_ST7735_SEND_DATA(0x00);
	RV_ST7735_SEND_DATA(startX + dX);
	RV_ST7735_SEND_DATA(0x00);        
	RV_ST7735_SEND_DATA(stopX + dX);
	
	RV_ST7735_SEND_CMD(0x2B);
	RV_ST7735_SEND_DATA(0x00);
	RV_ST7735_SEND_DATA(startY + dY);
	RV_ST7735_SEND_DATA(0x00);       
	RV_ST7735_SEND_DATA(stopY + dY);
}
//������������� �������
void RV_ST7735_INIT(void) {
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_1LINE;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_4;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLED;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLED;
  hspi1.Init.CRCPolynomial = 10;
  HAL_SPI_Init(&hspi1);
    
  LCD_ST7735_CS_0;
  LCD_ST7735_RES_0;
  HAL_Delay(LCD_DELAY);
  LCD_ST7735_RES_1;
  HAL_Delay(LCD_DELAY);
  RV_ST7735_SEND_CMD(0x11);
  HAL_Delay(LCD_DELAY);
  RV_ST7735_SEND_CMD(0x3A);
  RV_ST7735_SEND_DATA(0x05);
  RV_ST7735_SEND_CMD(0x36);
  RV_ST7735_SEND_DATA(0x68);
  RV_ST7735_SEND_CMD(0x29);
  LCD_ST7735_CS_1;
}
//��������� ������������ ��������������
void RV_ST7735_FILLRECT(uint8_t startX, uint8_t startY, uint8_t stopX, uint8_t stopY, uint16_t color) {
  uint8_t x;
  uint8_t y;
  LCD_ST7735_CS_0;
  RV_ST7735_AT(startX, startY, stopX, stopY);
  RV_ST7735_SEND_CMD(0x2C);
  for (y = startY; y <= stopY; y++)
		for (x = startX; x <= stopX; x++) {
      RV_ST7735_SEND_DATA((uint8_t) ((color & 0xFF00) >> 8));
      RV_ST7735_SEND_DATA((uint8_t) (color & 0x00FF));
    }
  LCD_ST7735_CS_1;
}
//��������� �������
void RV_ST7735_PIXEL(uint8_t x, uint8_t y, uint16_t color) {
  LCD_ST7735_CS_0;
  RV_ST7735_AT(x, y, x, y);
  RV_ST7735_SEND_CMD(0x2C);
  RV_ST7735_SEND_DATA((uint8_t) ((color & 0xFF00) >> 8));
  RV_ST7735_SEND_DATA((uint8_t) (color & 0x00FF));
  LCD_ST7735_CS_1;
}
//��������� �����
void RV_ST7735_LINE(int x0, int y0, int x1, int y1, uint16_t color) {
	uint8_t temp = 0;
  uint8_t steep = 0;
  if((abs(y1 - y0)) > (abs(x1 - x0)))
    steep = 1;
  else
    steep = 0;
  if (steep) {
    temp = x0;
    x0 = y0;
    y0 = temp;
    temp = x1;
    x1 = y1;
    y1 = temp;
  }
  if (x0 > x1) {
    temp = x0;
    x0 = x1;
    y0 = temp;
    temp = y0;
    x1 = y1;
    y1 = temp;
  }
  int dx = x1 - x0;
  int dy = abs(y1 - y0);
  int error = dx / 2;
  int ystep = (y0 < y1) ? 1 : -1;
  int y = y0;
  for (int x = x0; x <= x1; x++) {
    RV_ST7735_PIXEL(steep ? y : x, steep ? x : y, color);
    error -= dy;
    if (error < 0) {
      y += ystep;
      error += dx;
    }
  }
}
//��������� �������������� ��������������
void RV_ST7735_RECT(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color) {
	RV_ST7735_FILLRECT(x1, y1, x2, y1, color);
	RV_ST7735_FILLRECT(x1, y2, x2, y2, color);
	RV_ST7735_FILLRECT(x1, y1, x1, y2, color);
	RV_ST7735_FILLRECT(x2, y1, x2, y2, color);
}
//��������� �����/����������
void RV_ST7735_CIRCLE(uint16_t x0, uint16_t y0, uint16_t radius, uint16_t color, uint16_t fill) {
	int x = -radius;
	int y = 0;
	int err = 2 - 2 * radius;
	int e2;
	do {
		if (!fill) {
			RV_ST7735_PIXEL(x0 - x, y0 + y, color);
			RV_ST7735_PIXEL(x0 + x, y0 + y, color);
			RV_ST7735_PIXEL(x0 + x, y0 - y, color);
			RV_ST7735_PIXEL(x0 - x, y0 - y, color);
		}
		else {
			RV_ST7735_LINE(x0 - x, y0 - y, x0 - x, y0 + y, color);
			RV_ST7735_LINE(x0 + x, y0 - y, x0 + x, y0 + y, color);
		}
		e2 = err;
		if (e2 <= y) {
			err += ++y * 2 + 1;
			if (-x == y && e2 <= x)
				e2 = 0;
		}
		if (e2 > x)
			err += ++x * 2 + 1;
	} while (x <= 0);
}
//��������� �������
void RV_ST7735_CHAR(uint8_t x, uint8_t y, uint8_t chr, uint16_t charColor, uint16_t bkgColor) {
	uint8_t i;
	uint8_t j;
  uint8_t h;
	uint8_t k;
  uint16_t color;
  LCD_ST7735_CS_0;
	RV_ST7735_AT(x, y, x + 12, y + 8);
	RV_ST7735_SEND_CMD(0x2C);
	for (i = 0; i < 7; i++)
		for (k = 2; k > 0; k--) {
      uint8_t chl = NewBFontLAT[((chr - 0x20) * 14 + i + 7 * (k - 1))];
      chl = chl << 2 * (k - 1);
      if (k == 2)
				h = 6;
			else
				h = 7;
      for (j = 0; j < h; j++) {			
        if (chl & 0x80)
					color = charColor;
				else
					color = bkgColor;
        chl = chl << 1;
        RV_ST7735_SEND_DATA((uint8_t) ((color & 0xFF00) >> 8));
        RV_ST7735_SEND_DATA((uint8_t) (color & 0x00FF));
      }
    }
 	for (j = 0; j < 13; j++) {
    RV_ST7735_SEND_DATA((uint8_t) ((bkgColor & 0xFF00) >> 8));
    RV_ST7735_SEND_DATA((uint8_t) (bkgColor & 0x00FF));
  }
  LCD_ST7735_CS_1;
}
//��������� ������
void RV_ST7735_STRING(uint8_t x, uint8_t y, uint8_t str[], uint16_t charColor, uint16_t bkgColor) {
	while (*str != 0) {
		RV_ST7735_CHAR(x, y, *str, charColor, bkgColor);
		y += 8;
		str++;
	}
}
