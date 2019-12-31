#include "uart.h"

void init(USART_TypeDef* USARTx)
{
	USARTx->BRR |= USART_BaudRate;
	USARTx->CR1 |= USART_WordLength;
}

void open(USART_TypeDef* USARTx)
{
	USARTx->CR1 |= USART_CR1_UE;
	USARTx->CR1 |= USART_CR1_RE;
	USARTx->CR1 |= USART_CR1_TE;
}

int read(USART_TypeDef* USARTx)
{	
	return (USARTx->RDR & (USART_RDR_RDR));
}

void write(USART_TypeDef* USARTx, int data)
{
	USARTx->TDR = (data & (USART_TDR_TDR));
}

void close(USART_TypeDef* USARTx)
{
	USARTx->CR1 &= ~USART_CR1_UE;
	USARTx->CR1 &= ~USART_CR1_RE;
	USARTx->CR1 &= ~USART_CR1_TE;
}

void deinit(USART_TypeDef* USARTx)
{
	close(USARTx);
	USARTx->BRR &= ~(USART_BaudRate);
	USARTx->CR1 &= ~(USART_WordLength);
}

