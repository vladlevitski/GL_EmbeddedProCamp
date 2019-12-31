#include "main.h"

void initRCC()
{
	RCC->APB1ENR |= RCC_APB1ENR_UART4EN;
	RCC->AHBENR |= RCC_AHBENR_GPIOCEN;
}

void initGPIO(GPIO_TypeDef* GPIOx)
{
	GPIOx->MODER |= (Pin_TX_Mode | Pin_RX_Mode);
	GPIOx->OTYPER |= Pin_TX_OUTType; 
	GPIOx->OSPEEDR |= (Pin_TX_Speed | Pin_RX_Speed);
	GPIOx->PUPDR |= Pin_TX_PUPD;
	GPIOx->AFR[1] |= (Pin_TX_AF | Pin_RX_AF);
}

int main()
{
	SystemInit();
	initRCC();
	initGPIO(GPIOn);
	
	init(USARTn);
	open(USARTn);
	
	while (1)
	{		
		if (USARTn->ISR & USART_ISR_RXNE)
		{
			write(USARTn, read(USARTn));
		}	
	}
	return 0;
}
