#ifndef __IIC_MASTER_H_
#define __IIC_MASTER_H_
#include "sys.h" 

//IO��������
#define SDA_M_IN()  {GPIOB->CRL&=0XFFFF0FFF;GPIOB->CRL|=8<<12;}	//PB3����ģʽ
#define SDA_M_OUT() {GPIOB->CRL&=0XFFFF0FFF;GPIOB->CRL|=3<<12;} //PB3���ģʽ
//IO��������	 
#define IIC_M_SCL    PBout(4) //SCL
#define IIC_M_SDA    PBout(3) //SDA	 
#define READ_M_SDA   PBin(3)  //����SDA 

//��ʼ��IIC
void IIC_M_Init(void);
//����IIC��ʼ�ź�
void IIC_M_Start(void);
//����IICֹͣ�ź�
void IIC_M_Stop(void);
//�ȴ�Ӧ���źŵ���
//����ֵ��1������Ӧ��ʧ��
//        0������Ӧ��ɹ�
u8 IIC_M_Wait_Ack(void);
//����ACKӦ��
void IIC_M_Ack(void);
//������ACKӦ��		    
void IIC_M_NAck(void);
//IIC����һ���ֽ�
//���شӻ�����Ӧ��		  
void IIC_M_Send_Byte(u8 txd);
//��1���ֽڣ�ack=1ʱ������ACK��ack=0������nACK   
u8 IIC_M_Read_Byte(unsigned char ack);






#endif
