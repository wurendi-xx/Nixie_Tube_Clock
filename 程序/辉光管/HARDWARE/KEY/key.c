#include "stm32f10x.h"
#include "key.h"
#include "sys.h" 
#include "oled.h" 
#include "delay.h"
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//ALIENTEKս��STM32������
//������������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//�޸�����:2012/9/3
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) ������������ӿƼ����޹�˾ 2009-2019
//All rights reserved									  
//////////////////////////////////////////////////////////////////////////////////  
								    
//������ʼ������
void KEY_Init(void) //IO��ʼ��
{ 
 	GPIO_InitTypeDef GPIO_InitStructure;
 
 	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);//ʹ��PORTA,PORTEʱ��

//	GPIO_InitStructure.GPIO_Pin  = GPIO_Pin_8|GPIO_Pin_9|GPIO_Pin_10|GPIO_Pin_11|GPIO_Pin_12|GPIO_Pin_13|GPIO_Pin_14;//KEY0-KEY2
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //���ó���������
	 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		 //�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 //IO���ٶ�Ϊ50MHz
 	GPIO_Init(GPIOB, &GPIO_InitStructure);//��ʼ��GPIOE2,3,4

}
u8 KEY_Scan(u8 mode)
{	 
	u8 temp=0;
	static u8 key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������
	ROW_OUT();
	delay_us(10);
	PBout(8)=0;PBout(9)=0;PBout(10)=0;PBout(11)=0;PBout(12)=1;PBout(13)=1;PBout(14)=1;
	COL_IN();
	if(key_up&&(PBin(8)==1||PBin(9)==1||PBin(10)==1||PBin(11)==1))
	{
		delay_ms(10);//ȥ���� 
		key_up=0;
		OLED_Clear();
		if(PBin(8)==1)temp=1;
		else if(PBin(9)==1)temp=4;
		else if(PBin(10)==1)temp=7;
		else if(PBin(11)==1)temp=10;
		
		COL_OUT();
		delay_us(10);
		PBout(8)=1;PBout(9)=1;PBout(10)=1;PBout(11)=1;PBout(12)=0;PBout(13)=0;PBout(14)=0;
		ROW_IN();
		if(PBin(12)==1)
			return temp;
		else if(PBin(13)==1)
			return temp+=1;
		else if(PBin(14)==1)
			return temp+=2;
		
	}
	else if(PBin(8)==0&&PBin(9)==0&&PBin(10)==0&&PBin(11)==0)
		key_up=1; 	    
 	return 0;// �ް�������
}
