#include "Watering_Logic.h"
#include <stdio.h>
#include <time.h>

void Logic_Init(System_Config* config)
{
    printf("[LOGIC] Init: AUTO mode, ngưỡng min: %d, max: %d\n",
     config->moisture_min_threshold, config->moisture_max_threshold);
}
void process_Watering_Logic(System_Config* config, SensorData* data,
                            Actuators_Pumb* pump, Led_Systems* led)
{
    static Pump_State pump_state = PUMP_OFF;
    static time_t start_time = 0;

    if (!pump || !led || !config || !data) {
        printf("[ERROR] Null pointer in process_Watering_Logic\n");
        return;
    }

    if (pump_state == PUMP_OFF && data->soil_moisture_percent < config->moisture_min_threshold)
    {
        turn_Pump(pump, 0, PUMP_ON);
        set_Led_Status(led, LED_WATERING);
        pump_state = PUMP_ON;
        start_time = time(NULL);
        printf("[AUTO] Start watering. Moisture: %.2f%%\n", data->soil_moisture_percent);
    }

    if (pump_state == PUMP_ON)
    {
        time_t elapsed = time(NULL) - start_time;
        if (data->soil_moisture_percent >= config->moisture_max_threshold
            || elapsed >= config->watering_duration_sec)
        {
            turn_Pump(pump, 0, PUMP_OFF);
            set_Led_Status(led, LED_NORMAL);
            pump_state = PUMP_OFF;
            printf("[AUTO] Stop watering. Moisture: %.2f%%, Duration: %ld sec\n",
                   data->soil_moisture_percent, elapsed);
        }
    }
}

void handle_Manual_Override(System_Config* config, Actuators_Pumb* pump,
                            Button_Systems* button, Led_Systems* led)
{
    static time_t manual_start_time = 0;
    static int is_manual_watering = 0;

    if (!config || !pump || !button || !led) 
    {
        printf("[ERROR] Null pointer in handle_Manual_Override\n");
        return;
    }

    if (!is_manual_watering && Manual_Water_pressed(button, config))
    {
        turn_Pump(pump, 0, PUMP_ON);
        set_Led_Status(led, LED_WATERING);
        manual_start_time = time(NULL);
        is_manual_watering = 1;
        printf("[MANUAL] Start watering for %d sec\n", config->watering_duration_sec);
    }

    if (is_manual_watering)
    {
        time_t elapsed = time(NULL) - manual_start_time;
        if (elapsed >= config->watering_duration_sec)
        {
            turn_Pump(pump, 0, PUMP_OFF);
            set_Led_Status(led, LED_NORMAL);
            is_manual_watering = 0;
            printf("[MANUAL] Finished watering. Duration: %ld sec\n", elapsed);
        }
    }
}