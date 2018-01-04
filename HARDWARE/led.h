#ifndef __LED_H
#define __LED_H

#include "stm8s003.h"

#define LED0_ON			PA_ODR |= (1<<3)	//输出高电平
#define LED0_OFF		PA_ODR &= ~(1<<3)	//输出低电平

void LED_Init(void);

#endif
