#include <stdio.h>

#include "Led_Driver.h"

int main() 
{
    if (Led_Init(10) == 0)
    {
        printf("Failed to initialize LED strip.\n");
        return -1;
    }

    printf("LED strip initialized with %zu pixels.\n", Get_Count_Led_Pixel());

    uint32_t* buffer = Get_Led_Buffer();
    for (size_t i = 0; i < Get_Count_Led_Pixel(); ++i)
     {
        if (buffer[i] != 0) 
        {
            printf("Error: Pixel %zu is not initialized to 0.\n", i);
        }
    }

    /* Setting color*/
    Led_Set_Pixels_Colors(0, 255, 0, 0);     // Pixel 0: Red
    Led_Set_Pixels_Colors(9, 0, 0, 255);     // Pixel 9: Blue
    Led_Set_Pixels_Colors(4, 255, 255, 255); // Pixel 4: White

    // Get buffer và in log
    buffer = Get_Led_Buffer();
    printf("Pixel 0 color:  0x%08X\n", buffer[0]);  // Expect 0x0000FF00
    printf("Pixel 4 color:  0x%08X\n", buffer[4]);  // Expect 0x00FFFFFF
    printf("Pixel 9 color:  0x%08X\n", buffer[9]);  // Expect 0x000000FF

    
    Led_Fill(0, 255, 0); // Green
    buffer = Get_Led_Buffer();
    printf("\nAfter fill with Green:\n");
    for (size_t i = 0; i < Get_Count_Led_Pixel(); ++i) 
    {
        printf("Pixel %zu color: 0x%08X\n", i, buffer[i]); // Expect 0x00FF0000
    }

    Led_Shutdown();
    printf("LED strip shutdown.\n");

    return 0;
}
