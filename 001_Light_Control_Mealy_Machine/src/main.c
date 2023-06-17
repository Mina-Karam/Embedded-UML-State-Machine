#include "stm32f4xx_hal.h"
#include "stm32f4xx_it.h"
#include "LightCtrl.h"

#define LED_PIN                               GPIO_PIN_5
#define LED_GPIO_PORT                         GPIOA

#define PUSH_BUTTON_1_PIN                     GPIO_PIN_10
#define PUSH_BUTTON_2_PIN                     GPIO_PIN_11
#define PUSH_BUTTON_GPIO_PORT                 GPIOA

#define GPIOA_CLK_ENABLE()                    __HAL_RCC_GPIOA_CLK_ENABLE()

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  HAL_Init();
  LightCtrl_HW_Init();

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