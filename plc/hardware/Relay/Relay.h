#ifndef __RELAY_H_
#define __RELAY_H_

#include "jpstm32_gpio.h"

#define Relay1_Set			PAxOut(5)
#define Relay2_Set			PAxOut(4)

void Relay_Gpio_Init();



#endif
