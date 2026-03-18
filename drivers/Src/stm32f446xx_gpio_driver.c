#include <stdint.h>

#include "stm32f446_gpio_driver.h"

void GPIO_PeriClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI);

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	uint32_t temp = 0;
	//MODE
	if (pGPIOHandle->GPIO_PinConfig->GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		temp = (pGPIOHandle->GPIO_PinConfig->GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(3 << pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber);
		pGPIOHandle->pGPIOx->MODER |= temp;

	}else
	{

	}
	temp = 0;

	//SPEED
	temp = (pGPIOHandle->GPIO_PinConfig->GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDER &= ~(3 << pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OSPEEDER |= temp;
	temp = 0;

	//PUPD control
	temp = (pGPIOHandle->GPIO_PinConfig->GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(3 << pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber);
	pGPIOHandle->pGPIOx->PUPDR |= temp;
	temp = 0;

	//OUTPUT Type
	temp = (pGPIOHandle->GPIO_PinConfig->GPIO_PinOPType << pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER &= ~(3 << pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= temp;
	temp = 0;

	//ALT FUNC
	if ((pGPIOHandle->GPIO_PinConfig->GPIO_PinMode == GPIO_MODE_ALTFN)){
		uint8_t temp1, temp2;
		temp1 = pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber / 8;
		temp2 = pGPIOHandle->GPIO_PinConfig->GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF <<  (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |= (pGPIOHandle->GPIO_PinConfig->GPIO_PinAltFunMode << (4 * temp2));
	}

}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t ENorDI);
void GPIO_IRQHandling(uint8_t PinNumber);
