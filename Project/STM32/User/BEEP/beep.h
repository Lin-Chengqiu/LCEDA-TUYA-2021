#ifndef __BEEP_H
#define __BEEP_H	 
#include "stm32f10x.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//��������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
#define BEEP_ON  			GPIO_SetBits(GPIOA,GPIO_Pin_8);
#define BEEP_OFF 			GPIO_ResetBits(GPIOA,GPIO_Pin_8);
void BEEP_Init(void);	//��ʼ��
		 				    
#endif

