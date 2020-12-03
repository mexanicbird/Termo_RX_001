/*******************
 rvrobotics.ru
 RV_ST7735_ver_1.0
 Ruslan Vorovchenko
*******************/
#ifndef RV_ST7735_H
#define RV_ST7735_H

#include <stdint.h>
#include <string.h>

//С†РІРµС‚Р°
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

#define dX 1
#define dY 2

#define LCD_ST7735_CS_0   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_RESET);
#define LCD_ST7735_CS_1   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_14, GPIO_PIN_SET);
#define LCD_ST7735_A0_0   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_RESET);
#define LCD_ST7735_A0_1   HAL_GPIO_WritePin(GPIOB, GPIO_PIN_12, GPIO_PIN_SET);
#define LCD_ST7735_RES_0  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_RESET);
#define LCD_ST7735_RES_1  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_15, GPIO_PIN_SET);
#define LCD_ST7735_LED_0  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_RESET);
#define LCD_ST7735_LED_1  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_13, GPIO_PIN_SET);

#define LCD_DELAY	10

#define RGB16(color) (uint16_t)(((color & 0xF80000) >> 8) | ((color & 0x00FC00) >> 5) | ((color & 0x0000F8) >> 3))

int abs(int x);//модуль числа uint8_t
void RV_ST7735_LED_ON(void);//включить подсветку
void RV_ST7735_LED_OFF(void);//выключить подсветку
void RV_ST7735_SEND(uint8_t data);//передача данных по SPI
void RV_ST7735_SEND_CMD(uint8_t cmd);//посылка команды
void RV_ST7735_SEND_DATA(uint8_t data);//посылка данных
void RV_ST7735_AT(uint8_t startX, uint8_t startY, uint8_t stopX, uint8_t stopY);//определение рабочей области
void RV_ST7735_INIT(void);//инициализация дисплея
void RV_ST7735_FILLRECT(uint8_t startX, uint8_t startY, uint8_t stopX, uint8_t stopY, uint16_t color);//рисование заполненного прямоугольника
void RV_ST7735_PIXEL(uint8_t x, uint8_t y, uint16_t color);//рисование пиксела
void RV_ST7735_LINE(int x0, int y0, int x1, int y1, uint16_t color);//рисование линии
void RV_ST7735_RECT(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint16_t color);//рисование незаполненного прямоугольника
void RV_ST7735_CIRCLE(uint16_t x0, uint16_t y0, uint16_t radius, uint16_t color, uint16_t fill);//рисование круга/окружности
void RV_ST7735_CHAR(uint8_t x, uint8_t y, uint8_t chr, uint16_t charColor, uint16_t bkgColor);//рисование символа
void RV_ST7735_STRING(uint8_t x, uint8_t y, uint8_t str[], uint16_t charColor, uint16_t bkgColor);//рисование строки
#endif
