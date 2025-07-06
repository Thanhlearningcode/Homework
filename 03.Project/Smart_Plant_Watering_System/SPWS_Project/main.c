#include <stdio.h>
#include <unistd.h> // sleep()
#include "Config.h"
#include "System_Status.h"
#include "Sensors.h"
#include "Actuators.h"
#include "Buttons.h"
#include "Watering_Logic.h"

int main(int argc, char const* argv[])
{
    System_Config config = 
    {
        .moisture_min_threshold = MOISTURE_MIN_THRESHOLD,
        .moisture_max_threshold = MOISTURE_MAX_THRESHOLD,
        .watering_duration_sec  = SENSOR_CHECK_INTERVAL_MS,
        .check_interval_sec     = MANUAL_WATER_DURATION_SEC,
        .mode                   = MODE_AUTO
    };

    Sensor_Init();
    Actuators_Pumb* pump = Pump_Init();
    Button_Systems* _btn = Buttons_Init();
    Led_Init();
    Logic_Init(&config);

    if (!pump || !_btn) 
    {
        printf("Init failed!\n");
        return -1;
    }

    while (1) 
    {
        /*Giả sử nút số 0 là nút chuyển chế độ*/ 
        if (Auto_Toggle_pressed(_btn, 0)) 
        {
            config.mode = (config.mode == MODE_AUTO) ? MODE_MANUAL : MODE_AUTO;
            printf("\n[INFO] Chuyển chế độ: %s\n", config.mode == MODE_AUTO ? "TỰ ĐỘNG" : "THỦ CÔNG");
            turn_Pump(pump, 0, PUMP_OFF); // Tắt bơm số 0
        }

        if (config.mode == MODE_AUTO) 
        {
            SensorData data = read_Sensors();
            process_Watering_Logic(&config, &data, pump);
        } else 
        {
            handle_Manual_Override(&config, pump, _btn);
        }

        sleep(1); // Thêm delay để mô phỏng
    }

    return 0;
}
