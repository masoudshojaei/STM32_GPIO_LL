/*
 * GPIO_LL.h
 *
 *  Created on: Jul 16, 2026
 *      Author: shoja
 */

#ifndef INC_GPIO_LL_H_
#define INC_GPIO_LL_H_

void LED_init(void);
void LED_Blink_Fast(void);
void Button_init(void);
uint8_t Button_read(void);
void LED_OFF(void);
#endif /* INC_GPIO_LL_H_ */
