#ifndef BUTTONS_H
#define BUTTONS_H

#include "System_Status.h"


Button_Systems* Buttons_Init(void);
int Auto_Toggle_pressed (Button_Systems* _button, Buttons index);
int Manual_Water_pressed(Button_Systems* _button, System_Config* state);
#endif // BUTTONS_H
