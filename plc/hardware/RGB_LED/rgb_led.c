#include "RGB_LED.h"
#include "sys.h"
//LEDR--->PA8
//G11
//B12

void RGB_LED_Init()
{
	
	RCC->APB2ENR |=1<<3;//ʱ���ź�
	//PAout(11)=1;
	GPIOB->CRL &=0XFFFFFF00;	//���ùܽ�ģʽ
	GPIOB->CRL |=0x00000088;
	GPIOB->CRH &=0XFFFFFF00;	
	GPIOB->CRH |=0x00000033;
	//GPIOB->ODR |=1<<8;
	
	
	//PAout(12)=0;
	/*
	RCC->APB2ENR |=1<<2;
	GPIOA->CRH &=0XFFF0FFFF;	//�������
	GPIOA->CRH |=0x00030000;
	GPIOA->ODR |=1<<12;*/
	//PBout(8)=1
	//01010101 & 11111111=
}
/*
void RGB1_LED_Init()
{
	
	RCC->APB2ENR |=1<<3;
	GPIOB->CRH &=0XFFFFFFF0;	//�������
	GPIOB->CRH |=0x00000003;
	GPIOB->ODR |=1<<8;
}*/