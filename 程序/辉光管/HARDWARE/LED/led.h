#ifndef __LED_H
#define __LED_H	 
#include "sys.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//LED��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/2
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 
typedef enum
{
   TUBE_1=1,TUBE_2,TUBE_3,TUBE_4,TUBE_5,TUBE_6
} TUBEn_e;

void Glow_tube_init(void);
void Choose_num(int show_num);
void Choose_tube(TUBEn_e tube_num);		 
void Glow_tube_Show_num(TUBEn_e tube_num,int show_num); //�Թ����ʾ���֣�tube_numΪ�Թ�ܱ�ţ�show_numΪҪ��ʾ����
#endif
