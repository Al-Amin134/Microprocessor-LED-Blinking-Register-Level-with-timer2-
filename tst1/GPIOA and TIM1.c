#define RCC_BASE 0x40021000
#define GPIOA 0x40010800
#define DELAY 1000000
#define RCC_APB2ENR *(volatile unsigned int *)(RCC_BASE+0X18)
#define GPIOA_CRH *(volatile unsigned int *) (GPIOA + 0X04)
#define GPIOA_BSRR *(volatile unsigned int *) (GPIOA + 0X10)
	
//BY USING TIMER1
#define TIM1 0x40012C00
#define TIM1_CR1 *(volatile unsigned int*)(TIM1+0X00)
#define TIM1_PSC *(volatile unsigned int*)(TIM1+0X28)
#define TIM1_ARR *(volatile unsigned int*)(TIM1+0X2C)
#define TIM1_SR *(volatile unsigned int*)(TIM1+0X10)
#define GPIOA_ODR *(volatile unsigned int*)(GPIOA+0X0C)
int main()
{
	RCC_APB2ENR |=(1U<<20);
	GPIOA_CRH &=~(0XF<<20);
	GPIOA_CRH &=~(1U<<20);
	GPIOA_CRH |=(1U<<21);
	GPIOA_CRH	&=~(1U<<22);
	GPIOA_CRH &=~(1U<<23);
	
	RCC_APB2ENR |=(1U<<11);
	TIM1_PSC = 7999;
	TIM1_ARR = 999;
	TIM1_CR1 |=(1U<<0);
	
	while(1)
	{
		if(TIM1_SR & (1U<<0)){
			TIM1_SR &=~(1U<<0);
			GPIOA_ODR^=(1U<<13);
			
		}
		
	}
	
}
