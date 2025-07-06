#ifndef _LED_DRIVER_H_
#define _LED_DRIVER_H_

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#define COLOR_RED      255, 0, 0
#define COLOR_GREEN    0, 255, 0
#define COLOR_BLUE     0, 0, 255
#define COLOR_WHITE    255, 255, 255
#define COLOR_BLACK    0, 0, 0

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