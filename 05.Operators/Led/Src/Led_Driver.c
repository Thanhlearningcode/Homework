#include "Led_Driver.h"
#include <stdio.h>
#include <stdlib.h>

#define MAKE_COLOR(r,g,b) \
        (uint8_t)r |(uint8_t)g <<8 | (uint8_t)b << 16 

static uint32_t* led_buffer = NULL;
static size_t    number_pixcels = 0;

bool Led_Init (size_t num_pixels)
{
    if (num_pixels == 0)
    {
        printf("Need Parameter\n");
        return NOT_OK;
    }

    led_buffer = (uint32_t*)calloc(num_pixels,num_pixels*sizeof(uint32_t));
    number_pixcels = num_pixels;

    if (!led_buffer)
    {
        printf("Led Buffer is not created\n");
        return NOT_OK;
    }
    return OK;
}

void Led_Shutdown() 
{
    if (led_buffer)
    {
        free(led_buffer);
        led_buffer = NULL;
        printf("Deleted buffer\n");
    }
}

void Led_Set_Pixels_Colors (size_t index, uint8_t r, uint8_t g, uint8_t b)
{
    if (!led_buffer || index > number_pixcels)
    {
        printf("Error to create Pixels\n");
    }

    uint32_t set_color = MAKE_COLOR(r,g,b);
    led_buffer[index] = set_color;
}

void Led_Fill (uint8_t r, uint8_t g, uint8_t b)
{
    if (!led_buffer)
    {
        printf("Error to create Pixels\n");
        return;
    }

    const uint32_t set_color = MAKE_COLOR(r,g,b);
    for (size_t i=0;i<number_pixcels;i++)
    {
        *(led_buffer + i) = set_color;
    }
}

void Led_Clear()
{
    Led_Fill(0,0,0);
}

const uint32_t* Get_Led_Buffer()
{
    return (uint32_t*)led_buffer;
}

size_t Get_Count_Led_Pixel()
{
    return number_pixcels;
}