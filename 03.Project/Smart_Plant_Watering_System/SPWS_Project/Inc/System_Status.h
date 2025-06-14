#ifndef _SYSTEM_STATUS_H_
#define _SYSTEM_STATUS_H_

typedef enum
{
    MODE_AUTO = 0,
    MODE_MANUAL
} SystemState;

typedef enum
{
    PUMP_OFF = 0,
    PUMP_ON
} PumpState;

typedef enum 
{
    LED_NORMAL = 0,
    LED_WATERING,
    LED_LOW_MOISTURE_ALERT,
    LED_ERROR
} LEDStatus;

typedef struct 
{
    int soil_moisture_percent;
    float air_temperature_celsius;
} SensorData;

typedef struct {
    int moisture_min_threshold;
    int moisture_max_threshold;
    int watering_duration_sec;
    int check_interval_sec;
    SystemState mode;
} System_Config;

#endif /* _SYSTEM_STATUS_H_ */