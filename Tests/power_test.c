#include <stdbool.h>
#include <stdio.h>
#include <inttypes.h>
#include "stm32g4xx_hal.h"
//
#include "app.h"
#include "power.h"
#include "tests.h"
#include "common.h"

void Test_Power(App_t *app)
{
    printf("Chan: 3VB on\r\n");
    Pwr_Chan_Toggle(&app->power_controller, PWR_CHAN_3V3);
    HAL_Delay(5000);

    //

    printf("Buck: 5V on\r\n");
    Pwr_Buck_Toggle(&app->power_controller, PWR_BUCK_5V);
    HAL_Delay(2000);

    printf("Chan: 5VB on\r\n");
    Pwr_Chan_Toggle(&app->power_controller, PWR_CHAN_5V);
    HAL_Delay(5000);

    // //

    // printf("Buck: 12V on\r\n");
    // Pwr_Buck_Toggle(&app->power_controller, PWR_BUCK_12V);
    // HAL_Delay(5000);

    // //

    // printf("Buck: VVAR on\r\n");
    // Pwr_Buck_Toggle(&app->power_controller, PWR_BUCK_VVAR);
    // HAL_Delay(2000);

    // printf("Chan: VVAR on\r\n");
    // Pwr_Chan_Toggle(&app->power_controller, PWR_CHAN_VVAR);
    // HAL_Delay(5000);

    // //

    // // read current/voltage

    // // 0

    // printf("All off\r\n\n");

    // Pwr_Chan_Toggle(&app->power_controller, PWR_CHAN_3V3);
    // Pwr_Chan_Toggle(&app->power_controller, PWR_CHAN_5V);
    // Pwr_Chan_Toggle(&app->power_controller, PWR_CHAN_VVAR);

    // Pwr_Buck_Toggle(&app->power_controller, PWR_BUCK_5V);
    // Pwr_Buck_Toggle(&app->power_controller, PWR_BUCK_12V);
    // Pwr_Buck_Toggle(&app->power_controller, PWR_BUCK_VVAR);
    // HAL_Delay(5000);
}