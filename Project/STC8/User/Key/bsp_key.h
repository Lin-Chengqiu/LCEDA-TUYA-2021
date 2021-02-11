#ifndef __KEY_H
#define	__KEY_H


#include "include.h"

sbit KEY1 = P3^7;
sbit KEY2 = P3^6;
 /** �������±��ú�
	*  ��������Ϊ�ߵ�ƽ������ KEY_ON=1�� KEY_OFF=0
	*  ����������Ϊ�͵�ƽ���Ѻ����ó�KEY_ON=0 ��KEY_OFF=1 ����
	*/
#define KEY_ON	1
#define KEY_OFF	0

void Key_init(void);
void KeyScan(void);

#endif /* __KEY_H */

