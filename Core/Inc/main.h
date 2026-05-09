/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
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
#include "stm32g4xx_hal.h"

#include "stm32g4xx_nucleo.h"

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
#define NC_Pin GPIO_PIN_13
#define NC_GPIO_Port GPIOC
#define RCC_OSC32_IN_Pin GPIO_PIN_14
#define RCC_OSC32_IN_GPIO_Port GPIOC
#define RCC_OSC32_OUT_Pin GPIO_PIN_15
#define RCC_OSC32_OUT_GPIO_Port GPIOC
#define RCC_OSC_IN_Pin GPIO_PIN_0
#define RCC_OSC_IN_GPIO_Port GPIOF
#define RCC_OSC_OUT_Pin GPIO_PIN_1
#define RCC_OSC_OUT_GPIO_Port GPIOF
#define NCG10_Pin GPIO_PIN_10
#define NCG10_GPIO_Port GPIOG
#define NCC0_Pin GPIO_PIN_0
#define NCC0_GPIO_Port GPIOC
#define RTRY_SW_Pin GPIO_PIN_1
#define RTRY_SW_GPIO_Port GPIOC
#define RTRY_SW_EXTI_IRQn EXTI1_IRQn
#define NCC2_Pin GPIO_PIN_2
#define NCC2_GPIO_Port GPIOC
#define RTRY_CLK_Pin GPIO_PIN_3
#define RTRY_CLK_GPIO_Port GPIOC
#define NCA0_Pin GPIO_PIN_0
#define NCA0_GPIO_Port GPIOA
#define NCA1_Pin GPIO_PIN_1
#define NCA1_GPIO_Port GPIOA
#define NCA2_Pin GPIO_PIN_2
#define NCA2_GPIO_Port GPIOA
#define NCA3_Pin GPIO_PIN_3
#define NCA3_GPIO_Port GPIOA
#define BUCK_VVAR_DAC_Pin GPIO_PIN_4
#define BUCK_VVAR_DAC_GPIO_Port GPIOA
#define BUCK_5V_DAC_Pin GPIO_PIN_5
#define BUCK_5V_DAC_GPIO_Port GPIOA
#define BUCK_3V3_DAC_Pin GPIO_PIN_6
#define BUCK_3V3_DAC_GPIO_Port GPIOA
#define NCA7_Pin GPIO_PIN_7
#define NCA7_GPIO_Port GPIOA
#define NCC4_Pin GPIO_PIN_4
#define NCC4_GPIO_Port GPIOC
#define LED_DATA_Pin GPIO_PIN_5
#define LED_DATA_GPIO_Port GPIOC
#define NCB0_Pin GPIO_PIN_0
#define NCB0_GPIO_Port GPIOB
#define NCB1_Pin GPIO_PIN_1
#define NCB1_GPIO_Port GPIOB
#define INA_5VB_ADC2_IN12_Pin GPIO_PIN_2
#define INA_5VB_ADC2_IN12_GPIO_Port GPIOB
#define FAN_TACH_TIM2CH3_Pin GPIO_PIN_10
#define FAN_TACH_TIM2CH3_GPIO_Port GPIOB
#define OPAMP_3V3B_ADC1_IN14_Pin GPIO_PIN_11
#define OPAMP_3V3B_ADC1_IN14_GPIO_Port GPIOB
#define OPAMP_3V3A_ADC1_IN11_Pin GPIO_PIN_12
#define OPAMP_3V3A_ADC1_IN11_GPIO_Port GPIOB
#define BUCK_5V_EN_Pin GPIO_PIN_13
#define BUCK_5V_EN_GPIO_Port GPIOB
#define BUCK_12V_EN_Pin GPIO_PIN_14
#define BUCK_12V_EN_GPIO_Port GPIOB
#define BUCK_VVAR_EN_Pin GPIO_PIN_15
#define BUCK_VVAR_EN_GPIO_Port GPIOB
#define NCC6_Pin GPIO_PIN_6
#define NCC6_GPIO_Port GPIOC
#define NCC7_Pin GPIO_PIN_7
#define NCC7_GPIO_Port GPIOC
#define INA_VVAR_ADC5_IN1_Pin GPIO_PIN_8
#define INA_VVAR_ADC5_IN1_GPIO_Port GPIOA
#define INA_20V_ADC5_IN2_Pin GPIO_PIN_9
#define INA_20V_ADC5_IN2_GPIO_Port GPIOA
#define NCA10_Pin GPIO_PIN_10
#define NCA10_GPIO_Port GPIOA
#define HSSW_5VB_Pin GPIO_PIN_11
#define HSSW_5VB_GPIO_Port GPIOA
#define HSSW_3V3B_Pin GPIO_PIN_12
#define HSSW_3V3B_GPIO_Port GPIOA
#define NCA15_Pin GPIO_PIN_15
#define NCA15_GPIO_Port GPIOA
#define BTN_DSP_TOGGLE_Pin GPIO_PIN_10
#define BTN_DSP_TOGGLE_GPIO_Port GPIOC
#define BTN_DSP_TOGGLE_EXTI_IRQn EXTI15_10_IRQn
#define BTN_VVAR_TOGGLE_Pin GPIO_PIN_11
#define BTN_VVAR_TOGGLE_GPIO_Port GPIOC
#define BTN_VVAR_TOGGLE_EXTI_IRQn EXTI15_10_IRQn
#define BTN_5VB_TOGGLE_Pin GPIO_PIN_12
#define BTN_5VB_TOGGLE_GPIO_Port GPIOC
#define BTN_5VB_TOGGLE_EXTI_IRQn EXTI15_10_IRQn
#define BTN_3V3B_TOGGLE_Pin GPIO_PIN_2
#define BTN_3V3B_TOGGLE_GPIO_Port GPIOD
#define BTN_3V3B_TOGGLE_EXTI_IRQn EXTI2_IRQn
#define T_SWO_Pin GPIO_PIN_3
#define T_SWO_GPIO_Port GPIOB
#define FAN_PWM_TIM3_CH1_Pin GPIO_PIN_4
#define FAN_PWM_TIM3_CH1_GPIO_Port GPIOB
#define NCB5_Pin GPIO_PIN_5
#define NCB5_GPIO_Port GPIOB
#define NCB6_Pin GPIO_PIN_6
#define NCB6_GPIO_Port GPIOB
#define NCB7_Pin GPIO_PIN_7
#define NCB7_GPIO_Port GPIOB
#define NCB8_Pin GPIO_PIN_8
#define NCB8_GPIO_Port GPIOB
#define NCB9_Pin GPIO_PIN_9
#define NCB9_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
