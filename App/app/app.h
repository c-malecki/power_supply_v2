#ifndef __APP_H__
#define __APP_H__

#include "stm32g4xx_hal.h"
#include <stdint.h>
#include <stdbool.h>
#include "common.h"
#include "display.h"
#include "led.h"
#include "power.h"
#include "temperature.h"

typedef enum {
    APP_STATE_INIT = 0,
    APP_STATE_CHECK_POWER,
    APP_STATE_CHECK_TEMPERATURE,
    APP_STATE_CHECK_DISPLAY
} App_States;

extern const char *_App_State_Lookup[];

typedef struct
{
    Dsp_Ctrl_t display_controller;
    LED_Controller_t led_controller;
    Pwr_Ctrl_t power_controller;
    Temp_Ctrl_t temperature_controller;
    App_States state;
    _Error_t error;
} App_t;

void App_Init(App_t *app, I2C_HandleTypeDef *i2c_handle);
void App_Run(App_t *app);
void App_ErrorCheck(App_t *app);

#endif // __APP_H__