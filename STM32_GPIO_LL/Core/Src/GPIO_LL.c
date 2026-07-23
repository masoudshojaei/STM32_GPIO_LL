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
void LED_Blink_Fast(void)
{
    LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_5); /* Toggle PA5 */
    // or we can write the code like this:
    //LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5); /* Turn off PA5 */
    //LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_5);     /* Turn on PA5 */
    for (volatile int i = 0; i < 50000; i++); /* Delay */
}
/* Adding Button initialization on board bush button PC13 */
void Button_init(void)
{
    /* Enable GPIOC Clock */
    LL_AHB1_GRP1_EnableClock(LL_AHB1_GRP1_PERIPH_GPIOC);

    /* PC13 Configuration */

    // Pin mode: input
    LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_13, LL_GPIO_MODE_INPUT);

    // Pull-up: button is active-low
    LL_GPIO_SetPinPull(GPIOC, LL_GPIO_PIN_13, LL_GPIO_PULL_UP);
}
uint8_t Button_read(void)
{
    return LL_GPIO_IsInputPinSet(GPIOC, LL_GPIO_PIN_13) ? 0 : 1; /* Return 1 if button is pressed, 0 otherwise */
}
void LED_OFF(void)
{
    LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5); /* Turn off PA5 */
}
