#include "main.h"
#include "uart.h"
#include "command.h"
#include "tim.h"
#include "usart.h"

typedef UART_HandleTypeDef bsp_uart_handle_t;

static bsp_uart_handle_t *handle[BSP_UART_DEVICE_COUNT] ={

 [E_UART_10] = &huart10

};

/**
 * @brief  初始化对应串口 DMA 接收
 */
void bsp_uart_rx_init(bsp_uart_e device)
{
 if (device >= BSP_UART_DEVICE_COUNT || handle[device] == NULL) return;
 HAL_UARTEx_ReceiveToIdle_DMA(handle[device], buffer, BUFFER_SIZE);

 // 可选：关闭 DMA 半传输中断，避免触发多余的回调
 __HAL_DMA_DISABLE_IT(handle[device]->hdmarx, DMA_IT_HT);
}

 void bsp_uart_send(bsp_uart_e device, const uint8_t *data, const uint32_t len)
{
 HAL_UART_Transmit(handle[device], data, len, HAL_MAX_DELAY);
}



 void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
 {
 //代码。。。。。。。。
 bsp_uart_e device;
 for (device = 0; device < BSP_UART_DEVICE_COUNT; device++) {
  if (handle[device] == huart) break;
 }
 if (device >= BSP_UART_DEVICE_COUNT) return;

   bsp_uart_send(E_UART_10,buffer,1);

 HAL_UARTEx_ReceiveToIdle_DMA(huart, buffer, BUFFER_SIZE);
 };

