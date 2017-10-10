#ifndef __RGB_LED_H
#define __RGB_LED_H

#include "jpstm32_gpio.h"

#define R_LED			PAxOut(8)                   //ºìÉ«LED
#define G_LED			PAxOut(11)									//ÂÌÉ«LED
#define B_LED			PAxOut(12)									//À¶É«LED


void RGB_LED_Init();











#endif
