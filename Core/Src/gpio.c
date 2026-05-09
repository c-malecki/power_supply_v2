/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    gpio.c
  * @brief   This file provides code for the configuration
  *          of all used GPIO pins.
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

/* Includes ------------------------------------------------------------------*/
#include "gpio.h"

/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/*----------------------------------------------------------------------------*/
/* Configure GPIO                                                             */
/*----------------------------------------------------------------------------*/
/* USER CODE BEGIN 1 */

/* USER CODE END 1 */

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
     PA1   ------> SharedAnalog_PA1
*/
void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOG_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LED_DATA_GPIO_Port, LED_DATA_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, BUCK_5V_EN_Pin|BUCK_12V_EN_Pin|BUCK_VVAR_EN_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, HSSW_5VB_Pin|HSSW_3V3B_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : NC_Pin NCC0_Pin NCC2_Pin NCC4_Pin
                           NCC6_Pin NCC7_Pin */
  GPIO_InitStruct.Pin = NC_Pin|NCC0_Pin|NCC2_Pin|NCC4_Pin
                          |NCC6_Pin|NCC7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : NCG10_Pin */
  GPIO_InitStruct.Pin = NCG10_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(NCG10_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RTRY_SW_Pin BTN_DSP_TOGGLE_Pin BTN_VVAR_TOGGLE_Pin BTN_5VB_TOGGLE_Pin */
  GPIO_InitStruct.Pin = RTRY_SW_Pin|BTN_DSP_TOGGLE_Pin|BTN_VVAR_TOGGLE_Pin|BTN_5VB_TOGGLE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : RTRY_CLK_Pin */
  GPIO_InitStruct.Pin = RTRY_CLK_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(RTRY_CLK_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : NCA0_Pin NCA2_Pin NCA3_Pin NCA10_Pin
                           NCA15_Pin */
  GPIO_InitStruct.Pin = NCA0_Pin|NCA2_Pin|NCA3_Pin|NCA10_Pin
                          |NCA15_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : OPAMP_3V3A_Pin */
  GPIO_InitStruct.Pin = OPAMP_3V3A_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_ANALOG;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(OPAMP_3V3A_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : LED_DATA_Pin */
  GPIO_InitStruct.Pin = LED_DATA_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LED_DATA_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : NCB0_Pin NCB11_Pin NCB12_Pin NCB5_Pin
                           NCB6_Pin NCB7_Pin NCB8_Pin NCB9_Pin */
  GPIO_InitStruct.Pin = NCB0_Pin|NCB11_Pin|NCB12_Pin|NCB5_Pin
                          |NCB6_Pin|NCB7_Pin|NCB8_Pin|NCB9_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BUCK_5V_EN_Pin BUCK_12V_EN_Pin BUCK_VVAR_EN_Pin */
  GPIO_InitStruct.Pin = BUCK_5V_EN_Pin|BUCK_12V_EN_Pin|BUCK_VVAR_EN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : HSSW_5VB_Pin HSSW_3V3B_Pin */
  GPIO_InitStruct.Pin = HSSW_5VB_Pin|HSSW_3V3B_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLDOWN;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : BTN_3V3B_TOGGLE_Pin */
  GPIO_InitStruct.Pin = BTN_3V3B_TOGGLE_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(BTN_3V3B_TOGGLE_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI2_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI2_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 2 */

/* USER CODE END 2 */
