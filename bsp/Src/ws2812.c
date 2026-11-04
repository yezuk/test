//
// Created by shengye on 2026/11/4.
//

#include "ws2812.h"

volatile uint8_t RGB_BIT_Buffer[RGB_BIT];
volatile uint8_t buffer[RGB_BIT*LED_NUMS];
volatile LEDType LED[LED_NUMS];


void WS2812_Update()
{
	HAL_SPI_Transmit_DMA(&hspi1,buffer,RGB_BIT*LED_NUMS);
}

/**
create 24 byte sent by SPI using RGB values.
*/
static void WS2812_CreatData(uint8_t R,uint8_t G,uint8_t B)
{
    uint8_t temp[RGB_BIT] = {0};
    for (uint8_t i=0;i<8;i++){
        temp[7-i] =  (G & 0x01) ? WS2812_1 : WS2812_0;
        G = G >> 1;
    }
    for (uint8_t i=0;i<8;i++){
        temp[15-i] =  (R & 0x01) ? WS2812_1 : WS2812_0;
        R = R >> 1;
    }
    for (uint8_t i=0;i<8;i++){
        temp[23-i] =  (B & 0x01) ? WS2812_1 : WS2812_0;
        B = B >> 1;
    }
    memcpy(RGB_BIT_Buffer, temp, RGB_BIT);
}

/**
cook the whole buffer made by many(16 pieces) RGB_BIT_Buffers.
*/
static void WS2812_MakeBuffer()
{
	for(uint16_t i=0;i < LED_NUMS;i++)
	{
		WS2812_CreatData(LED[i].R,LED[i].G,LED[i].B);
		memcpy(buffer + i * RGB_BIT, RGB_BIT_Buffer, RGB_BIT);
	}
}



void WS2812_TurnOff()
{
	for(uint16_t i=0;i<LED_NUMS*24;i++)
	{
		buffer[i]=WS2812_0;
	}
}


/**
an led of position will bright with color value
pos is [0 , max-1]
*/
static void WS2812_Color_Pos(uint32_t color,uint16_t Pos)
{
	uint8_t R,G,B;
	uint16_t i;

	R=(color >> 16 ) & 0x00FF;
	G=(color >> 8  ) & 0x0000FF;
	B=(color 	   ) & 0x0000FF;

	WS2812_CreatData(R,G,B);
	if(Pos < LED_NUMS && Pos >=0)
	{
		memcpy(buffer + RGB_BIT * Pos, RGB_BIT_Buffer,RGB_BIT);
	}
	else
	{
		WS2812_TurnOff();
	}
}



void WS2812_Show_Wheel()
{
	static uint16_t i=0;
	i++;
	WS2812_Color_Pos(0xFF0000,(i)%16);
	WS2812_Color_Pos(0XFF7F00,(i+1)%16);
	WS2812_Color_Pos(0XFFFF00,(i+2)%16);
	WS2812_Color_Pos(0X7FFF00,(i+3)%16);
	WS2812_Color_Pos(0X00FF00,(i+4)%16);
	WS2812_Color_Pos(0X00FF7F,(i+5)%16);
	WS2812_Color_Pos(0X00FFFF,(i+6)%16);
	WS2812_Color_Pos(0X007FFF,(i+7)%16);
	WS2812_Color_Pos(0X0000FF,(i+8)%16);
	WS2812_Color_Pos(0X7F00FF,(i+9)%16);
	WS2812_Color_Pos(0XFF00FF,(i+10)%16);
	WS2812_Color_Pos(0XFF007F,(i+11)%16);
	WS2812_Color_Pos(0XFF0000,(i+12)%16);
	WS2812_Color_Pos(0XFF7F00,(i+13)%16);
	WS2812_Color_Pos(0XFFFF00,(i+14)%16);
	WS2812_Color_Pos(0X7FFF00,(i+15)%16);
	WS2812_Update();
}
 