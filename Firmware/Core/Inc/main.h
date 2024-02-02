/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f4xx_hal.h"

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
#define SS4_B_CTRL0_Pin GPIO_PIN_2
#define SS4_B_CTRL0_GPIO_Port GPIOE
#define SS4_B_CTRL1_Pin GPIO_PIN_3
#define SS4_B_CTRL1_GPIO_Port GPIOE
#define SS4_B_CTRL2_Pin GPIO_PIN_4
#define SS4_B_CTRL2_GPIO_Port GPIOE
#define SS4_B_CTRL3_Pin GPIO_PIN_5
#define SS4_B_CTRL3_GPIO_Port GPIOE
#define OUTPUT_LEDS_OUT_Pin GPIO_PIN_1
#define OUTPUT_LEDS_OUT_GPIO_Port GPIOC
#define MULTISENSE_SS2_A_Pin GPIO_PIN_0
#define MULTISENSE_SS2_A_GPIO_Port GPIOA
#define MULTISENSE_SS2_B_Pin GPIO_PIN_1
#define MULTISENSE_SS2_B_GPIO_Port GPIOA
#define MULTISENSE_SS4_A_Pin GPIO_PIN_2
#define MULTISENSE_SS4_A_GPIO_Port GPIOA
#define MULTISENSE_SS4_B_Pin GPIO_PIN_3
#define MULTISENSE_SS4_B_GPIO_Port GPIOA
#define PS_VBAT_Pin GPIO_PIN_4
#define PS_VBAT_GPIO_Port GPIOA
#define PDM_TEMP_Pin GPIO_PIN_5
#define PDM_TEMP_GPIO_Port GPIOA
#define SD_nDETECT_Pin GPIO_PIN_5
#define SD_nDETECT_GPIO_Port GPIOC
#define CTRL1_Pin GPIO_PIN_9
#define CTRL1_GPIO_Port GPIOE
#define SS2_A_CTRL1_Pin GPIO_PIN_10
#define SS2_A_CTRL1_GPIO_Port GPIOE
#define SS2_A_CTRL2_Pin GPIO_PIN_12
#define SS2_A_CTRL2_GPIO_Port GPIOE
#define CTRL1E13_Pin GPIO_PIN_13
#define CTRL1E13_GPIO_Port GPIOE
#define SS2_B_CTRL1_Pin GPIO_PIN_15
#define SS2_B_CTRL1_GPIO_Port GPIOE
#define SS2_B_CTRL2_Pin GPIO_PIN_10
#define SS2_B_CTRL2_GPIO_Port GPIOB
#define SS4_B_SEL2_Pin GPIO_PIN_12
#define SS4_B_SEL2_GPIO_Port GPIOB
#define SS4_B_SEL1_Pin GPIO_PIN_13
#define SS4_B_SEL1_GPIO_Port GPIOB
#define SS4_B_SEL0_Pin GPIO_PIN_14
#define SS4_B_SEL0_GPIO_Port GPIOB
#define SS4_B_SEn_Pin GPIO_PIN_15
#define SS4_B_SEn_GPIO_Port GPIOB
#define SS4_A_SEL2_Pin GPIO_PIN_8
#define SS4_A_SEL2_GPIO_Port GPIOD
#define SS4_A_SEL1_Pin GPIO_PIN_9
#define SS4_A_SEL1_GPIO_Port GPIOD
#define SS4_A_SEL0_Pin GPIO_PIN_10
#define SS4_A_SEL0_GPIO_Port GPIOD
#define SS4_A_SEn_Pin GPIO_PIN_11
#define SS4_A_SEn_GPIO_Port GPIOD
#define SS2_B_SEL1_Pin GPIO_PIN_12
#define SS2_B_SEL1_GPIO_Port GPIOD
#define SS2_B_SEL0_Pin GPIO_PIN_13
#define SS2_B_SEL0_GPIO_Port GPIOD
#define SS2_B_SEn_Pin GPIO_PIN_14
#define SS2_B_SEn_GPIO_Port GPIOD
#define SS2_A_SEL1_Pin GPIO_PIN_15
#define SS2_A_SEL1_GPIO_Port GPIOD
#define SS2_A_SEL0_Pin GPIO_PIN_6
#define SS2_A_SEL0_GPIO_Port GPIOC
#define SS2_A_SEn_Pin GPIO_PIN_7
#define SS2_A_SEn_GPIO_Port GPIOC
#define LED2_Pin GPIO_PIN_6
#define LED2_GPIO_Port GPIOD
#define LED1_Pin GPIO_PIN_7
#define LED1_GPIO_Port GPIOD
#define SS4_A_CTRL0_Pin GPIO_PIN_8
#define SS4_A_CTRL0_GPIO_Port GPIOB
#define SS4_A_CTRL1_Pin GPIO_PIN_9
#define SS4_A_CTRL1_GPIO_Port GPIOB
#define SS4_A_CTRL2_Pin GPIO_PIN_0
#define SS4_A_CTRL2_GPIO_Port GPIOE
#define SS4_A_CTRL3_Pin GPIO_PIN_1
#define SS4_A_CTRL3_GPIO_Port GPIOE

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
