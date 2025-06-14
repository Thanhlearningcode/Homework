#ifndef WATERING_LOGIC_H
#define WATERING_LOGIC_H

#include "System_Status.h"

void Logic_Init(System_Config* config);
void process_Watering_Logic(System_Config* config, SensorData* data);
void handle_Manual_Override(System_Config* config);

#endif /* WATERING_LOGIC_H */ 