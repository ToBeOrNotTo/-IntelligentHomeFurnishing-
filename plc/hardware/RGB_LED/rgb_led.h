#ifndef __RGB_LED_H_
#define __RGB_LED_H_

#include "jpstm32_gpio.h"
#include "sys.h"

#define GuangDian PBin(0)
#define DuiShe PBin(1)
#define BaoJing PBout(8)
#define Warn_LED PBout (9)

void RGB_LED_Init();
#endif