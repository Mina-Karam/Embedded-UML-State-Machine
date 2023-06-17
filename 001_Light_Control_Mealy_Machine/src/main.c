#include "stm32f4xx_hal.h"
#include "stm32f4xx_it.h"
#include "LightCtrl.h"

#define LED_PIN                               GPIO_PIN_5
#define LED_GPIO_PORT                         GPIOA

#define PUSH_BUTTON_1_PIN                     GPIO_PIN_10
#define PUSH_BUTTON_2_PIN                     GPIO_PIN_11
#define PUSH_BUTTON_GPIO_PORT                 GPIOA

#define GPIOA_CLK_ENABLE()                    __HAL_RCC_GPIOA_CLK_ENABLE()

static void HW_Init() 
{
  /* ------------- Clock Enable ------------- */
  GPIOA_CLK_ENABLE();

  /* ------------- LED Initlization ------------- */
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = LED_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(LED_GPIO_PORT, &GPIO_InitStruct);

  /* ------------- PUSH BUTTON Initlization ------------- */
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = PUSH_BUTTON_1_PIN | PUSH_BUTTON_2_PIN;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
  HAL_GPIO_Init(PUSH_BUTTON_GPIO_PORT, &GPIO_InitStruct);
}

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  HAL_Init();
  LED_Init();

  while (1)
  {
    HAL_GPIO_TogglePin(LED_GPIO_PORT, LED_PIN);

    HAL_Delay(1000);

    uint8_t event;

    // if()
    // {
        event = 'x';
        if(event == 'x')
        {
            light_state_machine(OFF);
        }
        else if(event == 'o')
        {
            light_state_machine(ON);
        }
    // }
  }
}