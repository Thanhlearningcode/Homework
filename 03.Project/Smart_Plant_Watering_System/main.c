#include <stdio.h>
#include <unistd.h> // dùng cho sleep()
#include "Config.h"
#include "System_Status.h"
#include "Sensors.h"
#include "Actuators.h"
#include "Buttons.h"
#include "Watering_Logic.h"

int main(void) {
    System_Config config = {
        .moisture_min_threshold = MOISTURE_MIN_THRESHOLD,
        .moisture_max_threshold = MOISTURE_MAX_THRESHOLD,
        .watering_duration_sec = SENSOR_CHECK_INTERVAL_MS,
        .check_interval_sec = MANUAL_WATER_DURATION_SEC,
        .mode = MODE_AUTO
    };

    Sensor_Init();
    Pump_Init();
    Led_Init();
    Buttons_Init();
    Logic_Init(&config);

    while (1) {
        if (Auto_Toggle_pressed()) {
            config.mode = (config.mode == MODE_AUTO) ? MODE_MANUAL : MODE_AUTO;
            printf("\n[INFO] Chuyển chế độ: %s\n", config.mode == MODE_AUTO ? "TỰ ĐỘNG" : "THỦ CÔNG");
            turn_Pump_Off();
        }

        if (config.mode == MODE_AUTO) {
            SensorData data = read_Sensors();
            process_Watering_Logic(&config, &data);
        } else {
            handle_Manual_Override(&config);
        }

        
    }

    return 0;
}