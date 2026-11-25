//
// Created by shengye on 2026/11/25.
//

#ifndef INC_32H723_COMMAND_H
#define INC_32H723_COMMAND_H
#include "main.h"
#include <string.h>
// 指令的最小长度
#define COMMAND_MIN_LENGTH 4
// 循环缓冲区大小
#define BUFFER_SIZE 128
// 循环缓冲区
uint8_t buffer[BUFFER_SIZE];

uint8_t Command_Write(uint8_t *data, uint8_t length);

uint8_t Command_GetCommand(uint8_t *command);

#endif //INC_32H723_COMMAND_H
