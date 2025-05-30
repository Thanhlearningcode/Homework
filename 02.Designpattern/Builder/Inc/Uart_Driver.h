#ifndef UART_DRIVER_H
#define UART_DRIVER_H

#include "Uart_Builder.h"
#include "stm32f4xx.h"

void UART1_Config(Uart_Config_t config);
void UART1_SendChar(char c);
void UART1_SendString(const char *str);
char UART1_ReceiveChar(void);

// Hàm khởi tạo UART2
void UART2_Config(Uart_Config_t config);

void UART2_SendChar(char c);

void UART2_SendString(const char *str);

char UART2_ReceiveChar(void);
#endif
