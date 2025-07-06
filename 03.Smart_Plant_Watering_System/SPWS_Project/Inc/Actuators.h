#ifndef ACTUATORS_H
#define ACTUATORS_H

#include "System_Status.h"
#include <stdbool.h>
#include <stdlib.h>

Actuators_Pumb* Pump_Init(void);
void turn_Pump(Actuators_Pumb* _pump,int index, Pump_State state );
Pump_State  get_Pump_State(Actuators_Pumb* _pump,int index);

Led_Systems* Led_Init(void);
void set_Led_Status(Led_Systems* _led, LED_Status led_status);
LED_Status get_Led_Status(Led_Systems* _led);
#endif // ACTUATORS_H