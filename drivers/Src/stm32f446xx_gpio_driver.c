#include <stdint.h>

#include "stm32f446_gpio_driver.h"

void GPIO_PeriClkCtrl(GPIO_RegDef_t *pGPIOx, uint8_t ENorDI);

void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	uint32_t temp = 0;

	if (pGPIOHandle->GPIO_PinConfig->GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		temp = (pGPIOHandle->GPIO_PinConfig->GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig->GPIO_PinMode));
		pGPIOHandle->pGPIOx->MODER = temp;

	}else
	{

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
