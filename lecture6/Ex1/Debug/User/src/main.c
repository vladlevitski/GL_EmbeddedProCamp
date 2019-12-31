#include "main.h"

USART_InitTypeDef uartInitStructure;
NVIC_InitTypeDef nvicInitStructure;
GPIO_InitTypeDef gpioInitStructure;

void initRCC()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_UART4, ENABLE);
}

void initGPIO()
{
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_5);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_5);
	
	gpioInitStructure.GPIO_OType = GPIO_OType_PP;
	gpioInitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	gpioInitStructure.GPIO_Pin = GPIO_Pin_10;
	gpioInitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	gpioInitStructure.GPIO_Mode = GPIO_Mode_AF;
	
	GPIO_Init(GPIOC, &gpioInitStructure);
	
	gpioInitStructure.GPIO_OType = GPIO_OType_PP;
	gpioInitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
	gpioInitStructure.GPIO_Pin = GPIO_Pin_11;
	gpioInitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	gpioInitStructure.GPIO_Mode = GPIO_Mode_AF;
	
	GPIO_Init(GPIOC, &gpioInitStructure);
}

void initNVIC()
{
	nvicInitStructure.NVIC_IRQChannel = UART4_IRQn;
	nvicInitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	nvicInitStructure.NVIC_IRQChannelSubPriority = 0;
	nvicInitStructure.NVIC_IRQChannelCmd = ENABLE;
	
	NVIC_Init(&nvicInitStructure);
}

void initUART()
{
	USART_StructInit(&uartInitStructure); 
	USART_Init(UART4, &uartInitStructure);
	USART_ITConfig(UART4, USART_IT_RXNE, ENABLE);	
	USART_Cmd(UART4, ENABLE);
}

void initAll()
{
	initRCC();
	initGPIO();
	initNVIC();
	initUART();
}

int main()
{
	SystemInit();
	initAll();
	while (1)
	{
		
	}
	return 0;
}
