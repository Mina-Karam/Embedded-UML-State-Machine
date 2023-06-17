/**
 * @file    LightCtrl.c
 * @author  Mina-Karam
 * @brief   This file contains the implemntation of the light control module
 * @date    17/6/2023
*/

/* Includes ------------------------------------------------------------------*/
#include "LightCtrl.h"

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
Light_State_t current_state = Light_Off;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
static void light_change_intensity(uint8_t pin, uint8_t intensity)
{

}

void light_state_machine(uint8_t u8_event)
{
  switch (current_state)
  {
    case Light_Off:
      {
        switch (u8_event)
        {
          case OFF:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_OFF); /* --Ignore-- */
            current_state = Light_Off;
            break;
          }

          case ON:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_DIM);
            current_state = Light_Dim;
            break;
          }

          default:
          {
            /* Do Nothing */
            break;
          }
        }
        break;
      }
      
    case Light_Dim:
      {
        switch (u8_event)
        {
          case OFF:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_OFF);
            current_state = Light_Off;
            break;
          }
          
          case ON:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_MED);
            current_state = Light_Med;
            break;
          }

          default:
          {
            /* Do Nothing */
            break;
          }
        }
        break;
      }
    case Light_Med:
      {
        switch (u8_event)
        {
          case OFF:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_OFF);
            current_state = Light_Off;
            break;
          }
          
          case ON:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_FULL);
            current_state = Light_Full;
            break;
          }

          default:
          {
            /* Do Nothing */
            break;
          }
        }
        break;
      }
    case Light_Full:
      {
        switch (u8_event)
        {
          case OFF:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_OFF);
            current_state = Light_Off;
            break;
          }
          
          case ON:
          {
            light_change_intensity(PIN_LED,LIGHT_BRIGHT_DIM);
            current_state = Light_Dim;
            break;
          }

          default:
          {
            /* Do Nothing */
            break;
          }
        }
        break;
      }

    default:
    {
      /* Do Nothing */
      break;
    }
  }
}
