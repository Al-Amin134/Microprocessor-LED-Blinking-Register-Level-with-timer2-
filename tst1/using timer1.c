#define RCC_BASE  		      0x40021000   
#define GPIOC_BASE 		      0x40011000    
#define DELAY 			        2000000


#define RCC_APB2ENR    		 (*(volatile unsigned int *)(RCC_BASE + 0x18))
#define GPIOC_CRH     		 (*(volatile unsigned int *)(GPIOC_BASE + 0x04))
#define GPIOC_ODR    		   (*(volatile unsigned int *)(GPIOC_BASE + 0x0c))
#define GPIOC_BSRR 		     *(volatile unsigned int *) (GPIOC_BASE + 0x10)


#define TIM1 0x40012C00
#define TIM1_CR1          *(volatile unsigned int *)(TIM1 + 0x00)
#define TIM1_PSC          *(volatile unsigned int *)(TIM1 + 0x28)
#define TIM1_ARR          *(volatile unsigned int *)(TIM1 + 0x2c)
#define TIM1_SR           *(volatile unsigned int *)(TIM1 + 0x10)
			


int main()
{
	 RCC_APB2ENR |=(1u<<4);
	 GPIOC_CRH &=~(0xF<<20);
	 GPIOC_CRH &=~(1u<<20);
	 GPIOC_CRH |=(1u<<21);
	 GPIOC_CRH &=~(1u<<22);
	 GPIOC_CRH &=~(1u<<23);
	
	RCC_APB2ENR |=(1u<<11);
	
	TIM1_CR1  |=(1u<<0);
	TIM1_ARR = 1000;
	TIM1_PSC = 7999;
	
	 while(1)
	 {
			if(TIM1_SR&(1u<<0))
			{
				TIM1_SR &=~(1u<<0);
				GPIOC_ODR ^=(1u<<13);
			}
	 }
}
