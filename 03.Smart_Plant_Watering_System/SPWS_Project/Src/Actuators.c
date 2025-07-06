#include "Actuators.h"

static const char* led_state_messages[] = 
{
    [LED_NORMAL]              = "[LED] Xanh (Bình thường)\n",
    [LED_WATERING]            = "[LED] Vàng (Đang tưới)\n",
    [LED_LOW_MOISTURE_ALERT]  = "[LED] Đỏ (Độ ẩm thấp)\n",
    [LED_ERROR]               = "[LED] Đỏ nhấp nháy (Lỗi)\n"
};

Actuators_Pumb* Pump_Init(void)
{
    Actuators_Pumb* pum_state = (Actuators_Pumb*)calloc(1,sizeof(Actuators_Pumb));
    if (!pum_state)
    {
        printf("PUMP-STATE faile to create\n");
        return FAIL;
    }

    for (int i =0;i<BUTTON_COUNT;i++)
    {
        pum_state->pumps[i] = PUMP_OFF;
    }

    printf("[PUMP Init]- Created\n");
    return pum_state;
}
void turn_Pump(Actuators_Pumb* _pump,int index, Pump_State state )
{
    if (_pump)
    {
        _pump->pumps[index] = state;
        return;
    }
    printf("Fail to turn Pump:%d\n",(unsigned int)_pump->pumps[index]);
}

Pump_State get_Pump_State(Actuators_Pumb* _pump,int index)
{   
    if (_pump)
    {
        return _pump->pumps[index];
    }
    
    printf("Faile to return Pump-state\n");
    return FAIL; 
}

void Led_Init(void)
{
    Led_Systems* led_state = (Led_Systems*)calloc(1,sizeof(Led_Systems));
    if (!led_state)
    {
        printf("Faile to init led\n");
        return;
    }

    led_state->status = LED_NORMAL;
    printf("Led Init is ok\n");
}

void set_Led_Status(Led_Systems* _led, LED_Status led_status)
{
    if (_led)
    {
        _led->status = led_status;
    }
    printf("Set Led Status is ok: %d\n",_led->status);
}

LED_Status get_Led_Status(Led_Systems* _led)
{
    if (!_led)
    {
        printf("Led pointer NULL!\n");
        return LED_ERROR;
    }
    return _led->status;
}