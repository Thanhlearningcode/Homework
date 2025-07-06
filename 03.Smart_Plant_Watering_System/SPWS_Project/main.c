#include <stdio.h>
#include <unistd.h>
#include "Config.h"
#include "System_Status.h"
#include "Sensors.h"
#include "Actuators.h"
#include "Buttons.h"
#include "Watering_Logic.h"

int main(void)
{
    System_Config config = {
        .moisture_min_threshold = MOISTURE_MIN_THRESHOLD,
        .moisture_max_threshold = MOISTURE_MAX_THRESHOLD,
        .watering_duration_sec  = MANUAL_WATER_DURATION_SEC,
        .check_interval_sec     = SENSOR_CHECK_INTERVAL_MS,
        .mode                   = MODE_AUTO
    };

    Sensor_Init();
    Actuators_Pumb* pump = Pump_Init();
    Button_Systems* buttons = Buttons_Init();
    Led_Systems* led_state = Led_Init();
    Logic_Init(&config);

    if (!pump || !buttons || !led_state) 
    {
        printf("[ERROR] Init failed!\n");
        return -1;
    }

    while (1) 
    {
        if (Auto_Toggle_pressed(buttons, 0)) 
        {
            config.mode = (config.mode == MODE_AUTO) ? MODE_MANUAL : MODE_AUTO;
            printf("\n[INFO] Switched mode: %s\n", config.mode == MODE_AUTO ? "AUTO" : "MANUAL");
            turn_Pump(pump, 0, PUMP_OFF);
            set_Led_Status(led_state, LED_NORMAL); // reset led
        }

        if (config.mode == MODE_AUTO) 
        {
            SensorData data = read_Sensors();
            process_Watering_Logic(&config, &data, pump, led_state);
        } 
        else 
        {
            handle_Manual_Override(&config, pump, buttons, led_state);
        }

        sleep(1);
    }

    free(pump);
    free(buttons);
    free(led_state);

    return 0;
}
