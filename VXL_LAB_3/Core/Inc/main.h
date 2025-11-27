/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2025 STMicroelectronics.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define INPUT_MODE_Pin GPIO_PIN_1
#define INPUT_MODE_GPIO_Port GPIOA
#define INPUT_INCREASE_Pin GPIO_PIN_2
#define INPUT_INCREASE_GPIO_Port GPIOA
#define INPUT_SET_Pin GPIO_PIN_3
#define INPUT_SET_GPIO_Port GPIOA
#define LED_RED_1_Pin GPIO_PIN_4
#define LED_RED_1_GPIO_Port GPIOA
#define LED_AMBER_1_Pin GPIO_PIN_5
#define LED_AMBER_1_GPIO_Port GPIOA
#define LED_GREEN_1_Pin GPIO_PIN_6
#define LED_GREEN_1_GPIO_Port GPIOA
#define LED_RED_2_Pin GPIO_PIN_7
#define LED_RED_2_GPIO_Port GPIOA
#define SEG71_0_Pin GPIO_PIN_1
#define SEG71_0_GPIO_Port GPIOB
#define SEG71_1_Pin GPIO_PIN_2
#define SEG71_1_GPIO_Port GPIOB
#define SEG72_2_Pin GPIO_PIN_10
#define SEG72_2_GPIO_Port GPIOB
#define SEG72_3_Pin GPIO_PIN_11
#define SEG72_3_GPIO_Port GPIOB
#define SEG72_4_Pin GPIO_PIN_12
#define SEG72_4_GPIO_Port GPIOB
#define SEG72_5_Pin GPIO_PIN_13
#define SEG72_5_GPIO_Port GPIOB
#define SEG72_6_Pin GPIO_PIN_14
#define SEG72_6_GPIO_Port GPIOB
#define LED_AMBER_2_Pin GPIO_PIN_8
#define LED_AMBER_2_GPIO_Port GPIOA
#define LED_GREEN_2_Pin GPIO_PIN_9
#define LED_GREEN_2_GPIO_Port GPIOA
#define EN0_Pin GPIO_PIN_14
#define EN0_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_15
#define EN1_GPIO_Port GPIOA
#define SEG71_2_Pin GPIO_PIN_3
#define SEG71_2_GPIO_Port GPIOB
#define SEG71_3_Pin GPIO_PIN_4
#define SEG71_3_GPIO_Port GPIOB
#define SEG71_4_Pin GPIO_PIN_5
#define SEG71_4_GPIO_Port GPIOB
#define SEG71_5_Pin GPIO_PIN_6
#define SEG71_5_GPIO_Port GPIOB
#define SEG71_6_Pin GPIO_PIN_7
#define SEG71_6_GPIO_Port GPIOB
#define SEG72_0_Pin GPIO_PIN_8
#define SEG72_0_GPIO_Port GPIOB
#define SEG72_1_Pin GPIO_PIN_9
#define SEG72_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
