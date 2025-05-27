#include "Gpio.h"
#include "Uart_Driver.h"
#include <stdio.h>

void delay(volatile uint32_t count) {
    while(count--) {
        __NOP();
    }
}

 extern void UART1_Config(Uart_Config_t config);  

int main(void) 
{
    GPIOA_Pin5_Output_Init();
    Uart_Builder builder = UART_Builder_Init();
   

    Uart_Config_t config = builder
        .setBaudrate(&builder, 115200)
        ->setParity(&builder, 0)
        ->setStopBits(&builder, 1)
        ->setDataBits(&builder, 8)
        ->build(&builder);

    UART2_Config(config);
  //  UART1_SendString("UART Ready1111!\r\n");
         // Print the configured UART parameters
    while(1) 
    {
     UART2_SendString("Hello,My name is Thanh!\r\n");
    // char c = UART2_ReceiveChar();  // Nhận ký tự từ terminal
    //  UART2_SendChar(c);             // Phản hồi lại
     //   GPIOA_Pin5_Toggle();
        delay(3000000);
    }
}
