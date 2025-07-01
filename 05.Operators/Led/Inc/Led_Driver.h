#ifndef _LED_DRIVER_H_
#define _LED_DRIVER_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

typedef enum 
{
    NOT_OK = 0,
    OK,
} Led_State;

bool Led_Init (size_t num_pixels);
void Led_Shutdown ();
void Led_Set_Pixels_Colors (size_t index, uint8_t r, uint8_t g, uint8_t b);
void Led_Fill (uint8_t r, uint8_t g, uint8_t b);
void Led_Clear ();
const uint32_t* Get_Led_Buffer();
size_t Get_Count_Led_Pixel();



#endif /*_LED_DRIVER_H_*/