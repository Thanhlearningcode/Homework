#ifndef _SYSTEM_STATUS_H_
#define _SYSTEM_STATUS_H_

#include <stdbool.h>
#include "stdio.h"

#define BUTTON_COUNT     2
#define PUMP_WATER_COUNT 1
#define LED_COUNT        1
typedef enum 
{
  FAIL = 0,
  OK   = 0,
} System_Init;
typedef enum
{
    MODE_AUTO = 0,
    MODE_MANUAL
} System_State;

typedef enum
{
    PUMP_OFF = 0,
    PUMP_ON
} Pump_State;

typedef enum
{
    BUTON_ON = 0,
    BUTON_OFF
} Button_State;

typedef enum 
{
    LED_NORMAL = 0,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR
} LED_Status;

typedef enum
{
  BUTTON_1 = 0,
  BUTTON_2
} Buttons;

typedef struct 
{
    int soil_moisture_percent;
    float air_temperature_celsius;
} SensorData;

typedef struct 
{
    LED_Status leds[LED_COUNT];
} Led_Systems;

typedef struct 
{
    Pump_State pumps[PUMP_WATER_COUNT];
} Actuators_Pumb;

typedef struct 
{
    Button_State buttons[BUTTON_COUNT];
} Button_Systems;

typedef struct {
    int moisture_min_threshold;
    int moisture_max_threshold;
    int watering_duration_sec;
    int check_interval_sec;
    System_State mode;
} System_Config;

#endif /* _SYSTEM_STATUS_H_ */