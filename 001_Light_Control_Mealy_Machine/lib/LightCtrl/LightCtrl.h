/**
 * @file    LightCtrl.h
 * @author  Mina-Karam
 * @brief   This file contains the headers of the light control module
 * @date    17/6/2023
*/

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __LIGHT_CTRL_H
#define __LIGHT_CTRL_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Exported types ------------------------------------------------------------*/
typedef enum{
  Light_Off,
  Light_Dim,
  Light_Med,
  Light_Full,
  Total_Light_States
}Light_State_t;

/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
#define OFF                 (0)
#define ON                  (1)

#define LIGHT_BRIGHT_OFF    (0)
#define LIGHT_BRIGHT_DIM    (25)
#define LIGHT_BRIGHT_MED    (85)
#define LIGHT_BRIGHT_FULL   (255)

#define PIN_LED             (9)

/* Exported functions ------------------------------------------------------- */
void light_state_machine(uint8_t u8_event);

#endif /* __LIGHT_CTRL_H */