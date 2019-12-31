#ifndef UART_H
#define UART_H

#include "stm32f30x.h"
#include "main.h"

/**
 * Function init USART.
 * @param USARTx UART structure to define
 */
void init(USART_TypeDef* USARTx);

/**
 * Function open the USART.
 * @param USARTx UART structure
 */
void open(USART_TypeDef* USARTx);

/**
 * Function read data from UART.
 * @param USARTx UART structure
 * @return data from UART
 */
int read(USART_TypeDef* USARTx);

/**
 * Function write data to UART.
 * @param USARTx UART structure
 * @param data Represetns integer value for write to UART
 */
void write(USART_TypeDef* USARTx, int data);

/**
 * Function close the USART.
 * @param USARTx UART structure
 */
void close(USART_TypeDef* USARTx);

/**
 * Function deinit the USART.
 * @param USARTx UART structure
 */
void deinit(USART_TypeDef* USARTx);

#endif
