#include "Watering_Logic.h"
#include <stdio.h>
#include <time.h>

void Logic_Init(System_Config* config)
{
    printf("[LOGIC] Init: AUTO mode, ngưỡng min: %d, max: %d\n",
     config->moisture_min_threshold, config->moisture_max_threshold);
}

void process_Watering_Logic(System_Config* config, SensorData* data, Actuators_Pumb* pump)
{
    static Pump_State pump_state = PUMP_OFF;
    static time_t start_time = 0;

    if (pump_state == PUMP_OFF && data->soil_moisture_percent < config->moisture_min_threshold)
    {
        // Bật bơm số 0
        turn_Pump(pump, 0, PUMP_ON);
    //    set_Led_State(LED_WATERING);
        pump_state = PUMP_ON;
        start_time = time(NULL);
    }

    if (pump_state == PUMP_ON)
    {
        time_t elapsed = time(NULL) - start_time;
        if (data->soil_moisture_percent >= config->moisture_max_threshold
            || elapsed >= config->watering_duration_sec)
        {
            turn_Pump(pump, 0, PUMP_OFF);
        //    set_Led_State(LED_NORMAL);
            pump_state = PUMP_OFF;
        }
    }
}

void handle_Manual_Override(System_Config* config, Actuators_Pumb* pump, Button_Systems* button)
{
    static time_t manual_start_time = 0;
    static int is_manual_watering = 0;

    /*Check button is pressed*/ 
    if (!is_manual_watering && Manual_Water_pressed(button, config)) 
    {
        printf("[MANUAL] Bắt đầu tưới thủ công trong %d giây...\n", config->watering_duration_sec);
        turn_Pump(pump, 0, PUMP_ON);              // Bật bơm số 0
    //    set_Led_Status(LED_WATERING);
        manual_start_time = time(NULL);
        is_manual_watering = 1;
    }

    /*Check wate is out of stock*/
    if (is_manual_watering)
    {
        time_t elapsed = time(NULL) - manual_start_time;
        if (elapsed >= (config->watering_duration_sec))
        {
            turn_Pump(pump, 0, PUMP_OFF);         
         //   set_Led_State(LED_NORMAL);
            printf("[MANUAL] Đã kết thúc tưới thủ công.\n");
            is_manual_watering = 0;
        }
    }
}