#include "Uart_Driver.h"
#include "SensorManager_Singleton.h"
#include "Adc.h"
int main(void)
{   
    Uart_Builder builder = UART_Builder_Init();
    Uart_Config_t config = builder
        .setBaudrate(&builder, 115200)
        ->setParity(&builder, 0)
        ->setStopBits(&builder, 1)
        ->setDataBits(&builder, 8)
        ->build(&builder);

    UART2_Config(config);
            UART2_SendString("Hello,My name is Thanh!\r\n");



    SensorManager* sm = SensorManager_GetInstance();

    while(1) 
    {
        UART2_SendString("Hello,My name is Thanh!\r\n");
        SensorManager_CollectData(sm);
        SensorManager_UploadToDatabase(sm);
        // Delay đơn giản
        for(volatile int i=0; i<1000000; i++);
    }
}
