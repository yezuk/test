//
// Created by shengye on 2026/11/4.
//

#ifndef INC_32H723_LED_H
#define INC_32H723_LED_H

#endif //INC_32H723_LED_H
#ifndef WS2812_H
#define WS2812_H

#include "string.h"
#include "main.h"
#include "spi.h"

#define	WS2812_0	0xC0
#define	WS2812_1	0xF0
#define	WS2812_RST	0x00
#define LED_NUMS   	16
#define RGB_BIT   	24

typedef struct
{
    uint8_t R;
    uint8_t G;
    uint8_t B;
}LEDType;


/**
turn off all leds
*/
void WS2812_TurnOff();
void WS2812_Show_Wheel();
void WS2812_Update();
#endif