#ifndef WATERING_LOGIC_H
#define WATERING_LOGIC_H

#include "System_Status.h"
#include "Actuators.h"
#include "Buttons.h"

void Logic_Init(System_Config* config);
void process_Watering_Logic(System_Config* config, SensorData* data,
                            Actuators_Pumb* pump, Led_Systems* led);
void handle_Manual_Override(System_Config* config, Actuators_Pumb* pump,
                            Button_Systems* button, Led_Systems* led);
                           
#endif /* WATERING_LOGIC_H */ 