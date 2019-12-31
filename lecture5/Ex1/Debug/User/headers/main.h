#ifndef __MAIN_H
#define __MAIN_H

#include "stm32f30x.h"
#include "uart.h"

/************************ GPIO configuration definitions ************************/
#define GPIOn							GPIOC						// Port
#define Pin_TX_Mode 					GPIO_MODER_MODER10_1		// TX Pin -> AF Mode
#define Pin_RX_Mode						GPIO_MODER_MODER11_1		// RX Pin -> AF Mode

#define Pin_TX_OUTType				    0x00						// TX -> Output
#define Pin_TX_PUPD						((uint32_t)0x00100000)	    // TX -> PullUP

#define Pin_TX_Speed					GPIO_OSPEEDER_OSPEEDR10	    // TX Pin Speed -> High speed
#define Pin_RX_Speed					GPIO_OSPEEDER_OSPEEDR11	    // RX Pin Speed -> High speed

#define Pin_TX_AF						((uint32_t)0x0500)		    // GPIO_AFRH_AFRH2
#define Pin_RX_AF						((uint32_t)0x05000)		    // GPIO_AFRH_AFRH3

/************************ UART configuration definitions ************************/
#define USARTn 							UART4						// Uart
#define USART_BaudRate				    0xea6 						// 9600 BaudRate (36Mhz/9600)		
#define USART_WordLength			    ((uint32_t)0x00000000) 	    // 8bit data word

void initRCC(void);
void initGPIO(GPIO_TypeDef *GPIOx);

#endif
