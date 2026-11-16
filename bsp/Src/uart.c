//
// Created by shengye on 2026/11/13.
//
#include "main.h"
#include "uart.h"

#include "tim.h"
#include "usart.h"

 void bsp_uart_send(int8_t a)
{
     HAL_UARTEx_ReceiveToIdle_DMA(&huart10, (uint8_t*)&a, 1);

    HAL_TIM_PWM_Start_DMA(&htim12, TIM_CHANNEL_2,a,100);
}
 void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
 {
  HAL_UART_Transmit_DMA(&huart10, (uint8_t*)&Size, Size);
 }

