#include "stm32f4xx.h"

#define GPIOEN (1U<<0)
#define PIN7 (1U<<7)
#define PIN6 (1U<<6)
#define PIN8 (1U<<8)

#define RED PIN6
#define YELLOW PIN7
#define GREEN PIN8

#define RED_OFF (1U<<22)
#define YELLOW_OFF (1U<<23)
#define GREEN_OFF (1U<<24)

typedef struct
{
	uint32_t red;
	uint32_t yellow;
	uint32_t green;
}TrafficDelay;

TrafficDelay time = {
	    15600000,  // RED delay (~approx, not real seconds)
	    6550000,   // YELLOW delay
	    14550900
};
void delay(uint32_t time)
{
    for(uint32_t i = 0; i < time; i++) {}
}
int main(void)
{
		RCC->AHB1ENR |= GPIOEN;

		GPIOA->MODER |= (1U<<12);
		GPIOA->MODER &=~ (1U<<13);

		GPIOA->MODER |= (1U<<14);
		GPIOA->MODER &=~ (1U<<15);

		GPIOA->MODER |= (1U<<16);
		GPIOA->MODER &=~ (1U<<17);


	while(1)
		{

		// RED ONN
			GPIOA->BSRR = RED|YELLOW_OFF|GREEN_OFF;

			delay(time.red);

			// GREEN ON
			GPIOA->BSRR = GREEN|YELLOW_OFF|RED_OFF;
	        delay(time.yellow);


	        // YELLOW ON
	    	GPIOA->BSRR = YELLOW|RED_OFF|GREEN_OFF;
	        delay(time.green);

		}


}

