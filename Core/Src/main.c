/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "stdbool.h"
#include "stdio.h"
#include "RV_ST7735.h"
#include "mb.h"
#include "mbport.h"
#include "user_mb_app.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
bool flag1; // флаги для моргалки
unsigned long t1, t2; // для отсчета времени
uint8_t tx_buffer1[] = "Termocontrol system\n\r"; // создаем буфер с текстом
uint8_t tx_buffer2[] = "Termometer varables:\n\r"; // создаем буфер с текстом
uint8_t tx_buffer3[] = "\n\r"; // создаем буфер с текстом
uint8_t tx_buffer4[] = "\n\r"; // создаем буфер с текстом
uint8_t msg1[64];  // буффер для числа
uint8_t msg2[64];  // буффер для числа
uint8_t msg3[64];  // буффер для числа
uint8_t msg4[64];  // буффер для числа
uint8_t msg5[64];  // буффер для числа
uint8_t msg6[64];  // буффер для числа
uint8_t msg7[64];  // буффер для числа
uint8_t msg8[64];  // буффер для числа
uint8_t msg9[64];  // буффер для числа
uint8_t msg10[64];  // буффер для числа
float x2 = 33.12;// число
float termo_1 = 11.1;
float  termo_2 = 22.1;
float  termo_3 = 33.1;
float  termo_4 = 44.1;
float  termo_5 = 55.1;
float  termo_6 = 66.1;
float  termo_7 = 77.1;
float  termo_8 = 88.1;
float  termo_9 = 99.1;
float  termo_10 = 0.1;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart1;

/* USER CODE BEGIN PV */
uint8_t Dev_ID[8][8]={0};
uint8_t Dev_Cnt;
char str1[60];
char TT1[10];
char TT2[10];
char TT3[10];
char TT4[10];
char TT5[10];
char TT6[10];
char TT7[10];
char TT8[10];

int TTv1;
int TTv2;
int TTv3;
int TTv4;
int TTv5;
int TTv6;
int TTv7;
int TTv8;


/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI1_Init(void);
static void MX_TIM4_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
extern uint16_t usSRegInBuf[];
void Huart(){
	 if(HAL_GetTick() - t2 >=3000) {
		 t2 = HAL_GetTick();
	 }
}

void Blink(){
	 if (flag1 == 1) {
		 if (HAL_GetTick() - t1 >= 2000) {
			 flag1 = 0;
			 t1 = HAL_GetTick();
		 }
	 }
	 if (flag1 == 0) {
	 		 if (HAL_GetTick() - t1 >= 300) {
	 		flag1 = 1;
	 		t1 = HAL_GetTick();
	 		 }
	 	HAL_GPIO_WritePin(GPIOC, DO1_Pin, flag1);
	 	 }

 }
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t status;
	uint8_t dt[8];
	uint16_t raw_temper;
	float temper;
	char c;
	uint8_t i;
	static uint32_t lock_nesting_count = 0;
	void __critical_enter(void)
	{
	    __disable_irq();
	    ++lock_nesting_count;
	}
	void __critical_exit(void)
	{
	    /* Unlock interrupts only when we are exiting the outermost nested call. */
	    --lock_nesting_count;
	    if (lock_nesting_count == 0) {
	        __enable_irq();
	    }
	}
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

	t1 = HAL_GetTick(); // для моргалки
	t2 = HAL_GetTick(); // для юарта
	flag1 = 1;

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  MX_TIM4_Init();
  /* USER CODE BEGIN 2 */

	RV_ST7735_INIT();
	RV_ST7735_LED_ON();
	RV_ST7735_FILLRECT(0, 0, 160, 128, CYAN);
	RV_ST7735_STRING( 90, 35, (uint8_t *) "DESIGN", WHITE, BLACK);
	HAL_Delay(600);
	RV_ST7735_STRING( 80, 50, (uint8_t *) "BY", WHITE, BLACK);
	HAL_Delay(600);
	RV_ST7735_STRING( 70, 17, (uint8_t *) "MEXANICBIRD", WHITE, BLACK);
	HAL_Delay(3000);
	RV_ST7735_FILLRECT(0, 0, 160, 128, BLACK);

	port_init();
	status = ds18b20_init(NO_SKIP_ROM);
	sprintf(str1,"Init Status: %d\r\n",status);
	sprintf(str1,"Dev count: %d\r\n", Dev_Cnt);
	for(i=1;i<=Dev_Cnt;i++)
	{
	  sprintf(str1,"Device %d\r\n", i);
	  sprintf(str1,"ROM RAW: %02X %02X %02X %02X %02X %02X %02X %02X\r\n",
	    Dev_ID[i-1][0], Dev_ID[i-1][1], Dev_ID[i-1][2], Dev_ID[i-1][3],
	    Dev_ID[i-1][4], Dev_ID[i-1][5], Dev_ID[i-1][6], Dev_ID[i-1][7]);
	  sprintf(str1,"Family CODE: 0x%02X\r\n", Dev_ID[i-1][0]);
	  sprintf(str1,"ROM CODE: 0x%02X%02X%02X%02X%02X%02X\r\n", Dev_ID[i-1][6], Dev_ID[i-1][5],
	    Dev_ID[i-1][4], Dev_ID[i-1][3], Dev_ID[i-1][2], Dev_ID[i-1][1]);
	  sprintf(str1,"CRC: 0x%02X\r\n", Dev_ID[i-1][7]);
	}

	eMBInit( MB_RTU, 0x0A, &huart1, 115200, &htim4 );
    eMBEnable( );


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
   for(i=1;i<=Dev_Cnt;i++)
   {
      ds18b20_MeasureTemperCmd(NO_SKIP_ROM, i);
   }
   HAL_Delay(800);

     ds18b20_ReadStratcpad(NO_SKIP_ROM, dt, 1);
     raw_temper = ((uint16_t)dt[1]<<8)|dt[0];
     if(ds18b20_GetSign(raw_temper)) c='-';
     else c='+';
     temper = ds18b20_Convert(raw_temper);
     temper = temper + 0.4;
     sprintf(TT1,"%c%.1f   ",c, temper);
     TTv1 = temper*100;

     ds18b20_ReadStratcpad(NO_SKIP_ROM, dt, 2);
     raw_temper = ((uint16_t)dt[1]<<8)|dt[0];
     if(ds18b20_GetSign(raw_temper)) c='-';
     else c='+';
     temper = ds18b20_Convert(raw_temper);
     sprintf(TT2,"%c%.1f   ",c, temper);
     temper = temper + 0.0;
     TTv2 = temper*100;

     ds18b20_ReadStratcpad(NO_SKIP_ROM, dt, 3);
     raw_temper = ((uint16_t)dt[1]<<8)|dt[0];
     if(ds18b20_GetSign(raw_temper)) c='-';
     else c='+';
     temper = ds18b20_Convert(raw_temper);
     temper = temper + 0.1;
     sprintf(TT3,"%c%.1f   ",c, temper);
     TTv3 = temper*100;

     ds18b20_ReadStratcpad(NO_SKIP_ROM, dt, 4);
     raw_temper = ((uint16_t)dt[1]<<8)|dt[0];
     if(ds18b20_GetSign(raw_temper)) c='-';
     else c='+';
     temper = ds18b20_Convert(raw_temper);
     temper = temper + 0.0;
     sprintf(TT4,"%c%.1f   ",c, temper);
     TTv4 = temper*100;

     ds18b20_ReadStratcpad(NO_SKIP_ROM, dt, 5);
     raw_temper = ((uint16_t)dt[1]<<8)|dt[0];
     if(ds18b20_GetSign(raw_temper)) c='-';
     else c='+';
     temper = ds18b20_Convert(raw_temper);
     temper = temper + 0.0;
     sprintf(TT5,"%c%.1f   ",c, temper);
     TTv5 = temper*100;

     ds18b20_ReadStratcpad(NO_SKIP_ROM, dt, 6);
     raw_temper = ((uint16_t)dt[1]<<8)|dt[0];
     if(ds18b20_GetSign(raw_temper)) c='-';
     else c='+';
     temper = ds18b20_Convert(raw_temper);
     temper = temper - 0.1;
     sprintf(TT6,"%c%.1f   ",c, temper);
     TTv6 = temper*100;

     ds18b20_ReadStratcpad(NO_SKIP_ROM, dt, 7);
     raw_temper = ((uint16_t)dt[1]<<8)|dt[0];
     if(ds18b20_GetSign(raw_temper)) c='-';
     else c='+';
     temper = ds18b20_Convert(raw_temper);
     temper = temper - 0.6;
     sprintf(TT7,"%c%.1f   ",c, temper);
     TTv7 = temper*100;

     ds18b20_ReadStratcpad(NO_SKIP_ROM, dt, 8);
     raw_temper = ((uint16_t)dt[1]<<8)|dt[0];
     if(ds18b20_GetSign(raw_temper)) c='-';
     else c='+';
     temper = ds18b20_Convert(raw_temper);
     temper = temper + 0.2;
     sprintf(TT8,"%c%.1f   ",c, temper);
     TTv8 = temper*100;

     usSRegInBuf[0] = TTv1;
     usSRegInBuf[1] = TTv2;
     usSRegInBuf[2] = TTv3;
     usSRegInBuf[3] = TTv4;
     usSRegInBuf[4] = TTv5;
     usSRegInBuf[5] = TTv6;
     usSRegInBuf[6] = TTv7;
     usSRegInBuf[7] = TTv8;

     HAL_Delay(150);

	 RV_ST7735_STRING( 140, 15, (uint8_t *) "TEMPERATURE", CYAN, BLACK);
	 RV_ST7735_STRING( 130, 25, (uint8_t *) "MEASURING", CYAN, BLACK);
	 RV_ST7735_STRING( 120, 35, (uint8_t *) "SYSTEM", CYAN, BLACK);

	 RV_ST7735_STRING(90, 5, (uint8_t *) "TERMO-01", WHITE, BLACK);
	 RV_ST7735_STRING(90, 78, (uint8_t *) (char *)TT1, WHITE, BLACK);

	 RV_ST7735_STRING(80, 5, (uint8_t *) "TERMO-02", WHITE, BLACK);
	 RV_ST7735_STRING(80, 78, (uint8_t *) (char *)TT2, WHITE, BLACK);

	 RV_ST7735_STRING(70, 5, (uint8_t *) "TERMO-03", WHITE, BLACK);
	 RV_ST7735_STRING(70, 78, (uint8_t *) (char *)TT3, WHITE, BLACK);

	 RV_ST7735_STRING(60, 5, (uint8_t *) "TERMO-04", WHITE, BLACK);
	 RV_ST7735_STRING(60, 78, (uint8_t *) (char *)TT4, WHITE, BLACK);

	 RV_ST7735_STRING(50, 5, (uint8_t *) "TERMO-05", WHITE, BLACK);
	 RV_ST7735_STRING(50, 78, (uint8_t *) (char *)TT5, WHITE, BLACK);

	 RV_ST7735_STRING(40, 5, (uint8_t *) "TERMO-06", WHITE, BLACK);
	 RV_ST7735_STRING(40, 78, (uint8_t *) (char *)TT6, WHITE, BLACK);

	 RV_ST7735_STRING(30, 5, (uint8_t *) "TERMO-07", WHITE, BLACK);
	 RV_ST7735_STRING(30, 78, (uint8_t *) (char *)TT7, WHITE, BLACK);

	 RV_ST7735_STRING(20, 5, (uint8_t *) "TERMO-08", WHITE, BLACK);
	 RV_ST7735_STRING(20, 78, (uint8_t *) (char *)TT8, WHITE, BLACK);

   Blink(); // вызываем моргалку
   eMBPoll();
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_1LINE;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 71;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 49;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim4, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */

  /* USER CODE END TIM4_Init 2 */

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 115200;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */

  /* USER CODE END USART1_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(DO1_GPIO_Port, DO1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, AO_Pin|LED_Pin|CS_Pin|RESET_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(RS485_RTS_GPIO_Port, RS485_RTS_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : DO1_Pin */
  GPIO_InitStruct.Pin = DO1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(DO1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PB11 */
  GPIO_InitStruct.Pin = GPIO_PIN_11;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : AO_Pin LED_Pin CS_Pin RESET_Pin */
  GPIO_InitStruct.Pin = AO_Pin|LED_Pin|CS_Pin|RESET_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : RS485_RTS_Pin */
  GPIO_InitStruct.Pin = RS485_RTS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(RS485_RTS_GPIO_Port, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
