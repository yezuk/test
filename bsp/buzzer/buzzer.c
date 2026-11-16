//
// Created by shengye on 2026/11/13.
//
#include "buzzer.h"
#include "stm32h7xx_hal.h"
#include "tim.h"
void warning_buzzer()
    {
    __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_2, 6500);
    HAL_Delay(100);
    __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_2, 0);
    HAL_Delay(100);
    __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_2, 6500);
    HAL_Delay(100);
    __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_2, 0);
    HAL_Delay(100);
    __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_2, 6500);
    HAL_Delay(100);
    __HAL_TIM_SET_COMPARE(&htim12, TIM_CHANNEL_2, 0);
    }