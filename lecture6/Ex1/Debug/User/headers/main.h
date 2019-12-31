#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f30x.h"
#include "stm32f30x_it.h"

/************************ GPIO configuration definitions ************************/

/************************ UART configuration definitions ************************/

void initRCC(void);
void initGPIO(void);
void initNVIC(void);
void initUART(void);
void initAll(void);

#endif
