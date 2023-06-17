/**
 * @file    LightCtrl_hw_config.c
 * @author  Mina-Karam
 * @brief   This file contains the hw configuration of the light control module
 * @date    17/6/2023
*/

#include "LightCtrl_hw_config.h"

// Buffer to store received UART data
uint8_t gu8_rxData = false;

/* ------------- LED Configuration ------------- */
static void LED_Init()
{
  // Enable GPIO peripheral clock for LED
  __HAL_RCC_GPIOA_CLK_ENABLE();

  // Configure GPIO pin for LED
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = GPIO_PIN_5; // LED pin
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // Turn off the LED initially
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, GPIO_PIN_RESET);
}

/* ------------- Button Configuration ------------- */
static void Button_Init()
{
  // Enable GPIO peripheral clock for buttons
  __HAL_RCC_GPIOB_CLK_ENABLE();

  // Configure GPIO pins for buttons
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = GPIO_PIN_12 | GPIO_PIN_13; // Button pins
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

/* ------------- PWM Configuration ------------- */
static void PWM_Init()
{
  TIM_HandleTypeDef htim;

  // Enable PWM peripheral clock
  __HAL_RCC_TIM3_CLK_ENABLE();

  // Configure the PWM timer
  htim.Instance = TIM3;
  htim.Init.Prescaler = 0; // Set the prescaler value
  htim.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim.Init.Period = 1000; // Set the period value
  htim.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  HAL_TIM_PWM_Init(&htim);

  // Configure PWM channel for LED
  TIM_OC_InitTypeDef sConfig;
  sConfig.OCMode = TIM_OCMODE_PWM1;
  sConfig.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfig.OCFastMode = TIM_OCFAST_DISABLE;
  sConfig.Pulse = 500; // Set the pulse width
  HAL_TIM_PWM_ConfigChannel(&htim, &sConfig, TIM_CHANNEL_1);

  // Start PWM output for LED
  HAL_TIM_PWM_Start(&htim, TIM_CHANNEL_1);
}

/* ------------- UART Configuration ------------- */
static void UART_Init()
{
  UART_HandleTypeDef huart;

  // Enable UART peripheral clock
  __HAL_RCC_USART2_CLK_ENABLE();

  // Configure UART pins
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin = GPIO_PIN_2 | GPIO_PIN_3; // UART pins
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  // Configure UART parameters
  huart.Instance = USART2;
  huart.Init.BaudRate = 9600; // Set the baud rate
  huart.Init.WordLength = UART_WORDLENGTH_8B;
  huart.Init.StopBits = UART_STOPBITS_1;
  huart.Init.Parity = UART_PARITY_NONE;
  huart.Init.Mode = UART_MODE_TX_RX;
  huart.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart.Init.OverSampling = UART_OVERSAMPLING_16;
  HAL_UART_Init(&huart);

  // Start receiving UART data
  HAL_UART_Receive_IT(&huart, &gu8_rxData, 1);
}

void LightCtrl_HW_Init(void) 
{
  LED_Init();
  Button_Init();
  PWM_Init();
  UART_Init();
}

