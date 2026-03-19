#include "stm32f446xx.h"


void delay(void)
{
	for (uint32_t i = 0 ; i < 500000 ; i++);
}
int main(void){
	//LED Toggle
	GPIO_Handle_t GPIOLed;
	GPIOLed.pGPIOx = GPIOA;
	GPIOLed.GPIO_PinConfig->GPIO_PinMode = GPIO_PIN_NO_5;
	GPIOLed.GPIO_PinConfig->GPIO_PinMode = GPIO_MODE_OUT;
	GPIOLed.GPIO_PinConfig->GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIOLed.GPIO_PinConfig->GPIO_PinOPType = GPIO_OP_TYPE_PP;
	GPIOLed.GPIO_PinConfig->GPIO_PinPuPdControl = GPIO_NO_PUPD;

	GPIO_PeriClkCtrl(GPIOA, ENABLE);
	GPIO_Init(&GPIOLed);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);
		delay();
	}
	return 0;
}
