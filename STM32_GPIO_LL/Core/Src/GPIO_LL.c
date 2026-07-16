/*
 * GPIO_LL.c
 *
 *  Created on: Jul 16, 2026
 *      Author: shoja
 */

#include "stm32f4xx_ll_gpio.h"
#include "stm32f4xx_ll_bus.h"

void LED_init(void)
{
    /*Enable GPIOA Clock*/
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOA);

    /*PA5 Configuration*/
    //Pin mode
    LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
    //Speed setting
    LL_GPIO_SetPinSpeed(GPIOA, LL_GPIO_PIN_5, LL_GPIO_SPEED_FREQ_LOW);
    //Setting output type
    LL_GPIO_SetPinOutputType(GPIOA, LL_GPIO_PIN_5,LL_GPIO_OUTPUT_PUSHPULL);
    //Pull-up/Pull-down setting
    LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_5, LL_GPIO_PULL_NO);
}
