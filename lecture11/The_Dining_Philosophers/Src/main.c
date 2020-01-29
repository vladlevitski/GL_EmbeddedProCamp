/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */
#define STACK_SIZE 200
#define PRIORITY 100
/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
osThreadId defaultTaskHandle;
/* USER CODE BEGIN PV */
StaticTask_t xTaskBuffer4,xTaskBuffer5;
StackType_t xStack4[STACK_SIZE],xStack5[STACK_SIZE];
TaskHandle_t xsHandle4 = NULL,xsHandle5 = NULL;
SemaphoreHandle_t xSemaph12,xSemaph23,xSemaph34,xSemaph45,xSemaph51;
QueueHandle_t xQueue;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
void StartDefaultTask(void const * argument);

/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

#define mdelay 40//portMAX_DELAY
#define tdelay 20

char tblink(short b_start,short b_end)
{
  if(((short)( TIM3 -> CNT ) > b_start) && ((short)( TIM3 -> CNT ) < b_end))
  {
    return 1;
  }
  return 0;
}

void vTaskPhilosopher1()
{
	static char on_off=0;
	char t_on_off,id;
	for(;;)
	{
		osDelay(1);
		id = 1;
		xQueueSendToBack( xQueue, &id, 0 );
		do{
		xQueuePeek( xQueue, &id, 0 );
		}while(id != 1);

		if( xSemaphoreTake( xSemaph51, mdelay ) == pdTRUE )
		{
			if( xSemaphoreTake( xSemaph12, mdelay ) == pdTRUE )
			{
				t_on_off = tblink(1000,10000);
				if(t_on_off != on_off)
				{
					on_off = t_on_off;
					if(on_off)
					{
						GPIOE -> BSRR = GPIO_BSRR_BS_8;
					}
					else
					{
						GPIOE -> BSRR = GPIO_BSRR_BR_8;
					}
				}
				osDelay(tdelay);
				xSemaphoreGive( xSemaph12 );
			}
			else
			{
				GPIOE -> BSRR = GPIO_BSRR_BS_14;
			}
			xSemaphoreGive( xSemaph51 );
		}
		else
		{
			GPIOE -> BSRR = GPIO_BSRR_BS_13;
		}
		xQueueReceive( xQueue, &id, 0 );
	}

}

void vTaskPhilosopher2()
{
	static char on_off=0;
	char t_on_off,id;
	for(;;)
	{
		osDelay(1);
		id = 2;
		xQueueSendToBack( xQueue, &id, 0 );
		do{
		xQueuePeek( xQueue, &id, 0 );
		}while(id != 2);

		if( xSemaphoreTake( xSemaph12, mdelay ) == pdTRUE )
		{
			if( xSemaphoreTake( xSemaph23, mdelay ) == pdTRUE )
			{
				t_on_off = tblink(2000,8000) + tblink(12000,18000);
				if(t_on_off != on_off)
				{
					on_off = t_on_off;
					if(on_off)
					{
						GPIOE -> BSRR = GPIO_BSRR_BS_9;
					}
					else
					{
						GPIOE -> BSRR = GPIO_BSRR_BR_9;
					}
				}
				osDelay(tdelay);
				xSemaphoreGive( xSemaph23 );
			}
			else
			{
				GPIOE -> BSRR = GPIO_BSRR_BS_14;
			}
			xSemaphoreGive( xSemaph12 );
		}
		else
		{
			GPIOE -> BSRR = GPIO_BSRR_BS_13;
		}
		xQueueReceive( xQueue, &id, 0 );
	}

}

void vTaskPhilosopher3()
{
	static char on_off=0;
	char t_on_off,id;

	for(;;)
	{
		osDelay(1);
		id = 3;
		xQueueSendToBack( xQueue, &id, 0 );
		do{
		xQueuePeek( xQueue, &id, 0 );
		}while(id != 3);

		if( xSemaphoreTake( xSemaph23, mdelay ) == pdTRUE )
		{
			if( xSemaphoreTake( xSemaph34, mdelay ) == pdTRUE )
			{
				t_on_off = tblink(5000,15000);
				if(t_on_off != on_off)
				{
					on_off = t_on_off;
					if(on_off)
					{
						GPIOE -> BSRR = GPIO_BSRR_BS_10;
					}
					else
					{
						GPIOE -> BSRR = GPIO_BSRR_BR_10;
					}
				}
				osDelay(tdelay);
				xSemaphoreGive( xSemaph34 );
			}
			else
			{
				GPIOE -> BSRR = GPIO_BSRR_BS_14;
			}
			xSemaphoreGive( xSemaph23 );
		}
		else
		{
			GPIOE -> BSRR = GPIO_BSRR_BS_13;
		}
		xQueueReceive( xQueue, &id, 0 );
	}

}

void vTaskPhilosopher4()
{
	static char on_off=0;
	char t_on_off,id;
	for(;;)
	{
		osDelay(1);
		id = 4;
		xQueueSendToBack( xQueue, &id, 0 );
		do{
		xQueuePeek( xQueue, &id, 0 );
		}while(id != 4);

		if( xSemaphoreTake( xSemaph34, mdelay ) == pdTRUE )
		{
			if( xSemaphoreTake( xSemaph45, mdelay ) == pdTRUE )
			{
				t_on_off = tblink(200,3500) + tblink(9200,10800) + tblink(18000,19000);
				if(t_on_off != on_off)
				{
					on_off = t_on_off;
					if(on_off)
					{
						GPIOE -> BSRR = GPIO_BSRR_BS_11;
					}
					else
					{
						GPIOE -> BSRR = GPIO_BSRR_BR_11;
					}
				}
				osDelay(tdelay);
				xSemaphoreGive( xSemaph45 );
			}
			else
			{
				GPIOE -> BSRR = GPIO_BSRR_BS_14;
			}
			xSemaphoreGive( xSemaph34 );
		}
		else
		{
			GPIOE -> BSRR = GPIO_BSRR_BS_13;
		}
		xQueueReceive( xQueue, &id, 0 );
	}

}

void vTaskPhilosopher5()
{
	static char on_off=0;
	char t_on_off,id;
	for(;;)
	{
		osDelay(1);
		id = 5;
		xQueueSendToBack( xQueue, &id, 0 );
		do{
		xQueuePeek( xQueue, &id, 0 );
		}while(id != 5);

		if( xSemaphoreTake( xSemaph45, mdelay ) == pdTRUE )
		{
			if( xSemaphoreTake( xSemaph51, mdelay ) == pdTRUE )
			{
				t_on_off = tblink(0,5000) + tblink(8100,11800) + tblink(18000,20000);
				if(t_on_off != on_off)
				{
					on_off = t_on_off;
					if(on_off)
					{
						GPIOE -> BSRR = GPIO_BSRR_BS_12;
					}
					else
					{
						GPIOE -> BSRR = GPIO_BSRR_BR_12;
					}
				}
				osDelay(tdelay);
				xSemaphoreGive( xSemaph51 );
			}
			else
			{
				GPIOE -> BSRR = GPIO_BSRR_BS_14;
			}
			xSemaphoreGive( xSemaph45 );
		}
		else
		{
			GPIOE -> BSRR = GPIO_BSRR_BS_13;
		}
		xQueueReceive( xQueue, &id, 0 );
	}

}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */
  

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  // Configure LED3, LED4, LED5, LED6, LED7, LED8, LED9 and LED10
  RCC -> AHBENR    |= 0x00200000;//GPIOE clock enable
  GPIOE -> MODER   |= 0x55550000;//PE8-15 output
  GPIOE -> OSPEEDR |= 0xFFFF0000;//PE8-15
  RCC -> APB1ENR	 |= 0x00000002;//__TIM3_CLK_ENABLE();
  
  TIM3 -> PSC = 7199;
  TIM3 -> ARR = 19999;
  TIM3 -> CR1 |= 0x00000001;
  /* USER CODE END 2 */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  
  xSemaph12 = xSemaphoreCreateMutex();
  xSemaph23 = xSemaphoreCreateMutex();
  xSemaph34 = xSemaphoreCreateMutex();
  xSemaph45 = xSemaphoreCreateMutex();
  xSemaph51 = xSemaphoreCreateMutex();
  
  if( xSemaph12 == NULL ){GPIOE -> BSRR = GPIO_BSRR_BS_15;}
  if( xSemaph23 == NULL ){GPIOE -> BSRR = GPIO_BSRR_BS_15;}
  if( xSemaph34 == NULL ){GPIOE -> BSRR = GPIO_BSRR_BS_15;}
  if( xSemaph45 == NULL ){GPIOE -> BSRR = GPIO_BSRR_BS_15;}
  if( xSemaph51 == NULL ){GPIOE -> BSRR = GPIO_BSRR_BS_15;}
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  xQueue = xQueueCreate( 5, sizeof( char ) );
  /* USER CODE END RTOS_QUEUES */

  /* Create the thread(s) */
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  TaskHandle_t xHandle1,xHandle2,xHandle3;

  if( xTaskCreate ( vTaskPhilosopher1, "Task 1", 128, NULL, PRIORITY, &xHandle1 ) != pdPASS )
  {;}/* The task was not created successfully. */
  else {;}

  if( xTaskCreate ( vTaskPhilosopher2, "Task 2", 128, NULL, PRIORITY, &xHandle2 ) != pdPASS )
  {;}/* The task was not created successfully. */
  else {;}

  if( xTaskCreate ( vTaskPhilosopher3, "Task 3", 128, NULL, PRIORITY, &xHandle3 ) != pdPASS )
  {;}/* The task was not created successfully. */
  else {;}

  xsHandle4 = xTaskCreateStatic(vTaskPhilosopher4,"StaticTask4",STACK_SIZE,(void*)1,PRIORITY,xStack4,&xTaskBuffer4);

  xsHandle5 = xTaskCreateStatic(vTaskPhilosopher5,"StaticTask5",STACK_SIZE,(void*)1,PRIORITY,xStack5,&xTaskBuffer5);

  /* USER CODE END RTOS_THREADS */

  /* Start scheduler */
  osKernelStart();
  
  /* We should never get here as control is now taken by the scheduler */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_BYPASS;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used 
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN 5 */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END 5 */ 
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
