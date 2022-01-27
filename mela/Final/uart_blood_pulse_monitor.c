//Use STM32F10x Standard Peripherals Library Drivers

/* Scheduler includes --------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "stm32f10x.h"
#include "delay.h"
#include "tsprintf.h"
#include <String.h>
#define TX_POINTER_BUFFER      8
#define Count_interval_limit	300

int8_t *TxData[TX_POINTER_BUFFER];
uint8_t i = 0;//subscript i for ring buffer array *TxData[]
uint8_t	k = 0;//subscript k for ring buffer array *TxData[]
static uint8_t trigger_flag=0;//
static uint8_t count_trigger_ondelay;//
static uint16_t count_interval_cycle;//
static uint16_t pulse_count;//

//structure declaration
GPIO_InitTypeDef GPIO_InitStructure;
USART_InitTypeDef USART_InitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
EXTI_InitTypeDef EXTI_InitStructure;

//prototype declaration
void EXT_ClkSet(void);
void RCC_Configuration(void);
void GPIO_Configuration(void);
void USART3_Configuration(void);
void USART3_Send_String(const int8_t String[]);
void NVIC_Configuration(void);
void EXTI_Interrupt_Configuration(void);
void Pulse_frequency(void);
void prvTask_pulse(void *pvParameters);
void prvTask_led(void *pvParameters);
void prvTask_monitor(void *pvParameters);

int main(void){
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	EXT_ClkSet();
	RCC_Configuration();
    GPIO_Configuration();
    USART3_Configuration();
    NVIC_Configuration();
    EXTI_Interrupt_Configuration();

	xTaskCreate(prvTask_pulse, (signed portCHAR *)"pulse", 192, NULL, 1, NULL);
	xTaskCreate(prvTask_led, (signed portCHAR *)"led", 192, NULL, 1, NULL);
	xTaskCreate(prvTask_monitor, (signed portCHAR *)"monitor", 192, NULL, 1, NULL);
	vTaskStartScheduler();
	while(1);
	return 0;
}

void EXT_ClkSet(void){
	//system clock setting(8MHzÅj
	RCC_DeInit();//RCC System reset
	RCC_HSEConfig(RCC_HSE_ON);//Enable HSE
	ErrorStatus HSEStartUpStatus;
	HSEStartUpStatus=RCC_WaitForHSEStartUp();//Wait till HSE is ready
	if (HSEStartUpStatus==SUCCESS){
		RCC_HCLKConfig(RCC_SYSCLK_Div1);//HCLK=SYSCLK
		RCC_PCLK1Config(RCC_HCLK_Div4);//PCLK1=HCLK/4 (APB1 18MHz /TIMxCLK 36MHz)
		RCC_PCLK2Config(RCC_HCLK_Div1);//PCLK2=HCLK (APB2 72MHz)
		RCC_PLLConfig(RCC_PLLSource_HSE_Div1,RCC_PLLMul_9);//PLLCLK = 8MHz * 9 = 72MHz
		RCC_PLLCmd(ENABLE);//Enable PLL
		while (RCC_GetFlagStatus(RCC_FLAG_PLLRDY)==RESET){}
		RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
		while (RCC_GetSYSCLKSource()!=0x08){}
	}
}

void RCC_Configuration(void){
	//USART3 APB1
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	//GPIO,AFIO(for remap) APB2
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA
						| RCC_APB2Periph_GPIOB
						| RCC_APB2Periph_GPIOC
						| RCC_APB2Periph_AFIO, ENABLE);
}

void GPIO_Configuration(void){
	//PC10 USART3_TX setting
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	//PC11_USART3_RX setting
	GPIO_StructInit(&GPIO_InitStructure);
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);
	//PC10-12 USART3TX,RX remap
	GPIO_PinRemapConfig(GPIO_PartialRemap_USART3, ENABLE);
	//PA8 input setting
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_IN_FLOATING;//GPIO pullup input
	GPIO_Init(GPIOA, &GPIO_InitStructure);//PA8 input setting
	//PB6 output setting
	GPIO_InitStructure.GPIO_Pin   = GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Mode  = GPIO_Mode_Out_PP;//GPIO pushupull output
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);
}

void USART3_Configuration(void){
	//USART3
	USART_InitStructure.USART_BaudRate=9600;
	USART_InitStructure.USART_WordLength=USART_WordLength_8b;
	USART_InitStructure.USART_StopBits=USART_StopBits_1;
	USART_InitStructure.USART_Parity=USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode=USART_Mode_Rx | USART_Mode_Tx;
	USART_Init(USART3, &USART_InitStructure);
	//USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);//Enable USART3 RX interrupt
	USART_Cmd(USART3, ENABLE);
}

void NVIC_Configuration(void){
	//USART3
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	//EXTI
	NVIC_InitStructure.NVIC_IRQChannel = EXTI9_5_IRQn;//EXTI(9-5)
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
}

void EXTI_Interrupt_Configuration(void){
	//GPIOA_8
	GPIO_EXTILineConfig(GPIO_PortSourceGPIOA, GPIO_PinSource8);
	EXTI_InitStructure.EXTI_Line = EXTI_Line8;
	EXTI_InitStructure.EXTI_Mode = EXTI_Mode_Interrupt;
	EXTI_InitStructure.EXTI_Trigger = EXTI_Trigger_Rising;
	EXTI_InitStructure.EXTI_LineCmd = ENABLE;
	EXTI_Init(&EXTI_InitStructure);
}

void USART3_Send_String(const int8_t String[]){
	TxData[k++] = (int8_t *)String;
	if (k == TX_POINTER_BUFFER){//return to the top at the end of Ring buffer
		k = 0;
	}
	USART_ITConfig(USART3, USART_IT_TXE, ENABLE);
	if (k == i){
		while(k != i){}
	}
}

void Pulse_frequency(void){
	if(trigger_flag==1){
		if((count_trigger_ondelay<10)&&((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8))==1)){
			trigger_flag=1;
			++count_trigger_ondelay;
		}
		else if((count_trigger_ondelay<10)&&((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8))==0)){
			trigger_flag=0;//trigger flag reset
		}
		else if((count_trigger_ondelay==10)&&((GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8))==1)){
			pulse_count=6000/count_interval_cycle;//Get pulse count
			count_interval_cycle=0;//counter reset
			trigger_flag=0;//trigger flag reset
		}
	}
	++count_interval_cycle;
	if(count_interval_cycle>Count_interval_limit){
		count_interval_cycle=Count_interval_limit;//count_interval_cycle
	}
}

void prvTask_pulse(void *pvParameters){

	while(1){
		Pulse_frequency();
		vTaskDelay(10/portTICK_RATE_MS);
	}
}

void prvTask_led(void *pvParameters){

	while(1){
		if (GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_8) == RESET) {
			GPIO_SetBits(GPIOB, GPIO_Pin_6);//LED on
		}
		else{
			GPIO_ResetBits(GPIOB, GPIO_Pin_6);//LED off
		}
		vTaskDelay(100/portTICK_RATE_MS);
	}
}

void prvTask_monitor(void *pvParameters){
static int8_t String_pulse_count[6];
	while(1){
		tsprintf(String_pulse_count,"%d",pulse_count);//
		USART3_Send_String(String_pulse_count);//
		USART3_Send_String("\r\n");//
		vTaskDelay(1000/portTICK_RATE_MS);
	}
}
void USART3_IRQHandler(void){
	if(USART_GetITStatus(USART3, USART_IT_TXE) != RESET){
		if(*TxData[i] == '\0'){
			i++;//shift to next string
			if (i == TX_POINTER_BUFFER){//return to the top at the end of Ring buffer
				i = 0;
			}
			if (i == k){
				USART_ITConfig(USART3, USART_IT_TXE, DISABLE);
			}
		}
	    else{
	    	USART_SendData(USART3, *TxData[i]);
	    	TxData[i]++;
	    }
	}
}

void EXTI9_5_IRQHandler(void){
	if(EXTI_GetITStatus(EXTI_Line8) != RESET){
		EXTI_ClearITPendingBit(EXTI_Line8);
		trigger_flag=1;//interrupt trigger ON
		count_trigger_ondelay=0;//ondelay counter reset
	}
}
