#include "Led_Driver.h"
#include <stdio.h>
#include <stdlib.h>

static uint32_t* led_buffer = NULL;
static size_t led_num_pixels = 0;

bool Led_Init (size_t num_pixels)
{
    if (num_pixels == 0)
    {
        printf("Paremeters is nothing = 0\n");
        return NOT_OK;
    }

    led_buffer = (uint32_t*)calloc(num_pixels,num_pixels*sizeof(uint32_t));
    led_num_pixels = num_pixels;

    for (size_t i=0; i<led_num_pixels; i++)
    {
        led_buffer[i] = 0;
    }
    if (!led_buffer)
    {
        printf("Led Buffer is not created\n");
        return NOT_OK;
    }
 
    return OK;
}

void Led_Shutdown()
{
    if(led_buffer)  //< Check led_buffer is exist 
    {
        free(led_buffer);
        led_buffer = NULL;
        printf("Led buffer is deleted\n");
    }
}
void Led_Set_Pixels_Colors (size_t index, uint8_t r, uint8_t g, uint8_t b)
{
    if (!led_buffer || (index > led_num_pixels))
    {
        printf("Check led init\n");
        return ;
    }

    uint32_t buffer_pixel = r  | g << 8 | b << 16;
    led_buffer[index] = buffer_pixel;
}

void Led_Fill (uint8_t r, uint8_t g, uint8_t b)
{
     if (!led_buffer )
    {
        printf("Check led init\n");
        return ;
    }

    const uint32_t set_color = r  | g << 8 | b << 16;
    for (size_t i=0;i<=led_num_pixels;i++)
    {
        *(led_buffer +i) = set_color;
    }
}

void Led_Clear ()
{
    Led_Fill(0,0,0);
    // const uint32_t set_color = 0;
    // for (int i=0;i<=led_num_pixels;i++)
    // {
    //     *(led_buffer +i) = set_color;
    // }
}

uint32_t* Get_Led_Buffer() {
    return led_buffer;
}

size_t Get_Count_Led_Pixel() {
    return led_num_pixels;
}
