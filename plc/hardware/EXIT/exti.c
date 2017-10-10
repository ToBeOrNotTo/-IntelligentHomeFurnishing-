#include "exti.h"
#include "sys.h"
#include "iic_master.h"
#include "jpstm32_gpio.h"
#include "jpstm32_sysclk.h"
#include "Debug_usart.h"

volatile u8 value =0;
//�ⲿ�ж�4�������
void EXTI0_IRQHandler(void)
{ 
	EXTI->PR=1<<0;  //���LINE�ϵ��жϱ�־λ  
	IIC_M_Start();
	IIC_M_Send_Byte(0XBA);
	if(IIC_M_Wait_Ack()){IIC_M_Stop(); return ;}
	value = IIC_M_Read_Byte(0);
	IIC_M_Stop();
	put_c(1,&value);
	PCxOut(1)=0;
	delayMs(50);
	PCxOut(1)=1;
	EXTI->PR=1<<0;  //���LINE�ϵ��жϱ�־λ 
}		   
//�ⲿ�жϳ�ʼ������
//��ʼ��PA0/PE2/PE3/PE4Ϊ�ж�����.
void EXTIX_Init(void)
{
  RCC->APB2ENR|=1<<2;
	GPIOA->CRL&=0xfffffff0;
	GPIOA->CRL|=0x00000008;
	Ex_NVIC_Config(GPIO_A,0,RTIR); 			//�����ش���
  
	MY_NVIC_Init(2,0,EXTI0_IRQChannel,2);	//��ռ2�������ȼ�0����2	   
}












