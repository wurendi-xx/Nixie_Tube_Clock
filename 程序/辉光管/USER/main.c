#include "led.h"
#include "delay.h"
#include "key.h"
#include "sys.h"
#include "usart.h"
#include "SWJ.h"
#include "led.h"
#include "timer.h"
#include "rtc.h" 	
#define SET_FINISH 1
#define SETTTING 2
#define WAIT_SET 0
/************************************************
 ALIENTEKս��STM32������ʵ��23
 IIC ʵ�� 
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

 				 	
	int value=0;
	u8 set_flag=0,set_count=0;
	int bai=0,shi=0,ge=0;
 int main(void)
 {	 
	delay_init();	    	 //��ʱ������ʼ��	  
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//�����ж����ȼ�����Ϊ��2��2λ��ռ���ȼ���2λ��Ӧ���ȼ�
	Glow_tube_init();
	RTC_Init();
//	uart_init(115200);
//	TIM3_Int_Init(5000-1,36-1);
//	RTC_Set(2018,5,8,12,25,30); 
	while(1)
	{

	}
}
