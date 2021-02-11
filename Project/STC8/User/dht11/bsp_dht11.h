#ifndef __DHT11_H
#define	__DHT11_H

#include "include.h"
/************************** DHT11 �������Ͷ���********************************/
typedef struct
{
	uint8_t  humi_int;		//ʪ�ȵ���������
	uint8_t  humi_deci;	 	//ʪ�ȵ�С������
	uint8_t  temp_int;	 	//�¶ȵ���������
	uint8_t  temp_deci;	 	//�¶ȵ�С������
	uint8_t  check_sum;	 	//У���
		                 
} DHT11_Data_TypeDef;

/************************** DHT11 �����궨��********************************/
#define      macDHT11_Dout_0	                            (P17 = 0)
#define      macDHT11_Dout_1	                            (P17 = 1)

#define      macDHT11_Data			                          P17 

/************************** DHT11 �������� ********************************/
void                     DHT11_Init                      ( void );
uint8_t                  DHT11_Read_TempAndHumidity      ( DHT11_Data_TypeDef * DHT11_Data );

#endif /* __DHT11_H */







