#include "Logger.h"

int main()
{
    Logger_Init(LOG_INFO,   "Log/log.txt");

    Log_Message(LOG_INFO,    "System initialized.");
    Log_Message(LOG_WARNING, "Low battery detected at %d%%", 20);
    Log_Message(LOG_ERROR,   "Failed to open sensor file: %s", "sensor.txt");

    Logger_Close();
    return 0;
}
