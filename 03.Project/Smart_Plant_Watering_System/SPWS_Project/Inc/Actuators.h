#ifndef ACTUATORS_H
#define ACTUATORS_H

#include "System_Status.h"

void Pump_Init(void);
void turn_Pump_On(void);
void turn_Pump_Off(void);
Pump_State get_Pump_State(void);

void Led_Init(void);
void set_Led_Status(LED_Status status);

#endif // ACTUATORS_H