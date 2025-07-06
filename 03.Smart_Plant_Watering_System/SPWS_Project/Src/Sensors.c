#include "Sensors.h"
#include <stdio.h>
#include <stdlib.h>

void Sensor_Init(void) 
{
    printf("[SENSORS] Init OK\n");
}

SensorData read_Sensors(void) 
{
    SensorData data;
    /*Mô phỏng giá trị ngẫu nhiên*/ 
    data.soil_moisture_percent = rand() % 101;   // 0-100%
    data.air_temperature_celsius = 20 + rand() % 15; // 20-35 độ
    printf("[SENSORS]-MOISTURE: %d%%, TEMPERATURE: %f°C\n", data.soil_moisture_percent, data.air_temperature_celsius);
    return data;
}
