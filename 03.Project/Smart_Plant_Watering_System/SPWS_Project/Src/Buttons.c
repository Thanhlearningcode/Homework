#include "Buttons.h"
#include <stdlib.h>
Button_Systems* Buttons_Init(void)
{
    Button_Systems* _btn = (Button_Systems*)calloc(1,sizeof(Button_Systems));
    if (_btn == NULL)
    {
        printf("Faile to init button\n");
        return NULL;
    }

    for (int i=0;i<=BUTTON_COUNT;i++)
    {
        _btn->buttons[i] = BUTON_OFF;
    }

    printf("Buttons Init OK (all OFF)\n");
    return _btn;
}

int Auto_Toggle_pressed (Button_Systems* _button, Buttons index)
{
    if (!_button)
    {
        printf("Button pointer NULL!\n");
        return FAIL;
    }

    if (index<0 || index >BUTTON_COUNT)
    {
        printf("Exceed value of buttons\n");
        return FAIL;
    }

    _button->buttons[index] = (_button->buttons[index] == BUTON_ON) ? BUTON_OFF : BUTON_ON;
    printf("Button is toggle: %s\n",(_button->buttons[index] == BUTON_ON) ? "ON" : "OFF" );
    return OK;
}

int Manual_Water_pressed(Button_Systems* _button, System_Config* state)
{
    if (!_button  || state->mode == MODE_AUTO) 
    {
        printf("Fail to press button[%d] water and status[%d]\n",_button->buttons[BUTTON_2],state->mode);
        return FAIL;
    }

    if (state->mode == MODE_MANUAL)
    {

    }
    return OK;
}