/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
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
#include "main.h"
#include "adc.h"
#include "dac.h"
#include "i2c.h"
#include "opamp.h"
#include "stm32g4xx_hal.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdint.h>
#include <stdio.h>

#include "SEGGER_RTT.h"
#include "app.h"
#include "power.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
static App_t app;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int _write(int file, char *ptr, int len)
{
    SEGGER_RTT_Write(0, ptr, len);
    return len;
}
/* USER CODE END 0 */

/**
 * @brief  The application entry point.
 * @retval int
 */
int main(void)
{

    /* USER CODE BEGIN 1 */

    /* USER CODE END 1 */

    /* MCU Configuration--------------------------------------------------------*/

    /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
    HAL_Init();

    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* Configure the system clock */
    SystemClock_Config();

    /* USER CODE BEGIN SysInit */

    /* USER CODE END SysInit */

    /* Initialize all configured peripherals */
    MX_GPIO_Init();
    MX_ADC2_Init();
    MX_ADC5_Init();
    MX_DAC1_Init();
    MX_DAC2_Init();
    MX_TIM2_Init();
    MX_TIM3_Init();
    MX_TIM6_Init();
    MX_ADC1_Init();
    MX_I2C3_Init();
    MX_OPAMP4_Init();
    MX_OPAMP6_Init();
    /* USER CODE BEGIN 2 */
    app.state = APP_STATE_INIT;
    App_Init(&app, &hi2c3);
    /* USER CODE END 2 */

    /* Infinite loop */
    /* USER CODE BEGIN WHILE */
    while (1) {
        printf("Chan: 3VB on\r\n");
        Pwr_Chan_Toggle(&app.power_controller, PWR_CHAN_3V3);
        HAL_Delay(5000);

        //

        printf("Buck: 5V on\r\n");
        Pwr_Buck_Toggle(&app.power_controller, PWR_BUCK_5V);
        HAL_Delay(2000);

        printf("Chan: 5VB on\r\n");
        Pwr_Chan_Toggle(&app.power_controller, PWR_CHAN_5V);
        HAL_Delay(5000);

        //

        printf("Buck: 12V on\r\n");
        Pwr_Buck_Toggle(&app.power_controller, PWR_BUCK_12V);
        HAL_Delay(5000);

        //

        printf("Buck: VVAR on\r\n");
        Pwr_Buck_Toggle(&app.power_controller, PWR_BUCK_VVAR);
        HAL_Delay(2000);

        printf("Chan: VVAR on\r\n");
        Pwr_Chan_Toggle(&app.power_controller, PWR_CHAN_VVAR);
        HAL_Delay(5000);

        //

        printf("All off\r\n\n");

        Pwr_Chan_Toggle(&app.power_controller, PWR_CHAN_3V3);
        Pwr_Chan_Toggle(&app.power_controller, PWR_CHAN_5V);
        Pwr_Chan_Toggle(&app.power_controller, PWR_CHAN_VVAR);

        Pwr_Buck_Toggle(&app.power_controller, PWR_BUCK_5V);
        Pwr_Buck_Toggle(&app.power_controller, PWR_BUCK_12V);
        Pwr_Buck_Toggle(&app.power_controller, PWR_BUCK_VVAR);
        HAL_Delay(5000);
        /* USER CODE END WHILE */

        /* USER CODE BEGIN 3 */
    }
    /* USER CODE END 3 */
}

/**
 * @brief System Clock Configuration
 * @retval None
 */
void SystemClock_Config(void)
{
    RCC_OscInitTypeDef RCC_OscInitStruct = { 0 };
    RCC_ClkInitTypeDef RCC_ClkInitStruct = { 0 };

    /** Configure the main internal regulator output voltage
     */
    HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1_BOOST);

    /** Initializes the RCC Oscillators according to the specified parameters
     * in the RCC_OscInitTypeDef structure.
     */
    RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    RCC_OscInitStruct.HSEState = RCC_HSE_ON;
    RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
    RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    RCC_OscInitStruct.PLL.PLLM = RCC_PLLM_DIV6;
    RCC_OscInitStruct.PLL.PLLN = 85;
    RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
    RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
    RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
    if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
        Error_Handler();
    }

    /** Initializes the CPU, AHB and APB buses clocks
     */
    RCC_ClkInitStruct.ClockType =
        RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
    RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

    if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4) != HAL_OK) {
        Error_Handler();
    }

    /** Enables the Clock Security System
     */
    HAL_RCC_EnableCSS();
}

/* USER CODE BEGIN 4 */
void HAL_TIM_IC_CaptureCallback(TIM_HandleTypeDef *htim)
{
    // TODO: issue #28: set flag and handle logic outside of interrupt
    Temp_Ctrl_t *ctrl = &app.temperature_controller;
    if (htim->Instance == TIM5 && htim->Channel == HAL_TIM_ACTIVE_CHANNEL_2) {
        ctrl->fan.value_cur = HAL_TIM_ReadCapturedValue(htim, TIM_CHANNEL_2);
        ctrl->fan.last_tick = HAL_GetTick();

        if (!ctrl->fan.first_cb) {
            if (ctrl->fan.value_cur >= ctrl->fan.value_last) {
                ctrl->fan.value_diff = ctrl->fan.value_cur - ctrl->fan.value_last;
            } else {
                ctrl->fan.value_diff =
                    (0xFFFFFFFF - ctrl->fan.value_last) + ctrl->fan.value_cur + 1;
            }

            if (ctrl->fan.value_diff > 0) {
                ctrl->fan.rpm = 30000000.0f / (float)ctrl->fan.value_diff;
            }
        }

        ctrl->fan.value_last = ctrl->fan.value_cur;
        ctrl->fan.first_cb = 0;
    }
}

void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    if (htim->Instance == TIM2)
        HAL_TIM_PWM_Stop_DMA(htim, TIM_CHANNEL_2);
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
    // static uint32_t last_press_rotary = 0;
    static uint32_t last_press_3v3 = 0;
    static uint32_t last_press_5v = 0;
    static uint32_t last_press_var = 0;
    static uint32_t last_press_menu = 0;
    uint32_t now = HAL_GetTick();

    switch (GPIO_Pin) {

    case BTN_VVAR_TOGGLE_Pin:
    {
        // TODO: issue #30: adjust debounce time to get buttons to stable toggle
        if (now - last_press_var < 75) {
            return;
        }
        last_press_var = now;
        app.power_controller.channels[PWR_CHAN_VVAR].toggle_pending = true;
        printf("GPIO_BTN_VVAR\r\n\n");
        break;
    }

    case BTN_5VB_TOGGLE_Pin:
    {
        if (now - last_press_5v < 75) {
            return;
        }
        last_press_5v = now;
        app.power_controller.channels[PWR_CHAN_5V].toggle_pending = true;
        printf("GPIO_BTN_5V\r\n\n");
        break;
    }

    case BTN_3V3B_TOGGLE_Pin:
    {
        if (now - last_press_3v3 < 75) {
            return;
        }
        last_press_3v3 = now;
        app.power_controller.channels[PWR_CHAN_3V3].toggle_pending = true;
        printf("GPIO_BTN_3V3\r\n\n");
        break;
    }

    case BTN_DSP_TOGGLE_Pin:
    {
        if (now - last_press_menu < 75) {
            return;
        }
        last_press_menu = now;
        printf("GPIO_BTN_DSP\r\n\n");
        break;
    }

        // case RTRY_SW_Pin:
        //     if (now - last_press_rotary < 50)
        //         return;
        //     last_press_rotary = now;
        //     app.power_controller->chan_var->rotary.pressed = true;
        //     break;

        // case BTN_DSP_MENU_Pin:
        // {
        // TODO: update display to show menu
        // rotary now becomes control
        // }
    }
}
/* USER CODE END 4 */

/**
 * @brief  This function is executed in case of error occurrence.
 * @retval None
 */
void Error_Handler(void)
{
    /* USER CODE BEGIN Error_Handler_Debug */
    /* User can add his own implementation to report the HAL error return state */
    __disable_irq();
    while (1) { }
    /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
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
    /* User can add his own implementation to report the file name and line
       number, ex: printf("Wrong parameters value: file %s on line %d\r\n", file,
       line) */
    /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
