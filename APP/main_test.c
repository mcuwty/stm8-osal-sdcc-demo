#include "stm8s003.h"
#include "led.h"

//硬件定时器初始化，设定系统时钟
void TIM2_Init(void)
{
	CLK_PCKENR1 |= (1<<5);					//使能TIM2时钟

	TIM2_PSCR = 0; 							//配置 TIM2 预分频，2^4 = 16 分频，则计时频率1MHz
	TIM2_ARRH = 50000/256; 					//自动重装值，1ms中断
	TIM2_ARRL = 50000%256;
	TIM2_CNTRH = 1000/256;					//计时器值
	TIM2_CNTRL = 1000%256;
	TIM2_CR1 |= 0x81; 						//使能TIM2及自动重装载
	TIM2_IER |= 0x01; 						//使能TIM2溢出中断
	__asm rim __endasm;                     //使能全局中断
}

//TIM2中断函数
void TIM2_UPDATE_IRQHandler(void) __interrupt 13
{
	static unsigned int conut = 0;
	TIM2_SR1 &=~(0x01);						//清除中断标志	

	conut++;
	if(conut>=100)
	{
		PA_ODR = ~PA_ODR;
		conut = 0;
	}
}

int main(void)
{
	CLK_CKDIVR = 0x00;			//系统时钟不分频，等于内部高速时钟16MHz
	LED_Init();
	TIM2_Init();
    // Usart_Init(115200);
    // Usart_Printf("STM8 Run OSAL System !\r\n");

	while(1)
	{
		// static unsigned int i = 0;

		// i++;
		// if(i>60000)
		// {
		// 	i=0;
		// 	PA_ODR = ~PA_ODR;
		// }
	}
}
