#include "RGB_LED.h"
#include "sys.h"
#include "jpstm32_sysclk.h"
#include "TP4115.h"
#include "WS2812B.h"

#include "CO2.h"
#include "SHT20.h"
#include "myiic.h"
#include "BH1750.h"
#include "Debug_usart.h"
#include "ZigBee_usart.h"
#include "veml6070.h"


#define Board_ID 01

#define Board1 1
#define Board2 0
#define Board3 0
#define Board4 0
#define Board5 0




unsigned char send_test[5]={0x01,0x02,0x03,0x04,0x05};
extern volatile u8 Usart1_RFinish;
extern u8 USART1_Tx_Buffer[USART_BUFFER_LEN];
extern volatile u16 USART1_TX_Len;
u16 M_Value;
extern volatile u8 R_Finish;//ZigBee接收完成标记位
extern u8 zigbee_buffer[ZIGBEE_BUFFER_LEN];
unsigned char TX_Buffer[17]={0XCC, 0XCC, 0X00, 0XFF, 0XFF,\
														0X02, 0X00, 0X00, 0X00, 0X00, \
														0X00, 0X00, 0X00, 0X00, \
														0X00, 0X00, 0xFF};

int main()	
{
	Stm32_Clock_Init(9);
	delayInit(72);
	JTAG_Set(01);
	zigbee_usart_init(36, 57600);
	
#if Board1
	PT4115_Init();
#endif

#if Board2
	CO2_Init();
	IIC_Init();
	BH1750_Init();
	VEML6070_Set();
#endif
		while(1)
	{
#if Board1
		if(R_Finish)
		{
			R_Finish = 0;
			if(zigbee_buffer[5] == Board_ID)
			{
				PT4115_Change(zigbee_buffer[6],zigbee_buffer[7],\
										zigbee_buffer[8],zigbee_buffer[9]);
			}
		}
#endif
		
	#if Board2
		CO2_Measure(&TX_Buffer[6],&TX_Buffer[7]);//co2 
		
		SHT20_Original_TEMP(&M_Value);           //温度
		TX_Buffer[8] = M_Value>>8;
		TX_Buffer[9] = M_Value;
		
		SHT20_Original_HUM(&M_Value);            //湿度
		TX_Buffer[10] = M_Value>>8;
		TX_Buffer[11] = M_Value;
		
		BH1750_Original_Measure(&M_Value);      //光照强度
		TX_Buffer[12] = M_Value>>8;
		TX_Buffer[13] = M_Value;
		
		VEML6070_Measure(&M_Value);							//紫外线
		TX_Buffer[14] = M_Value>>8;
		TX_Buffer[15] = M_Value;
		
		zigbee_send(17, TX_Buffer);
		delayMs(1000);
	#endif
		
	}
	

return 0;
}