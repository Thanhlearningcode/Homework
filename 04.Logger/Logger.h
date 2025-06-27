#ifndef _LOGGER_H_
#define _LOGGER_H_
#include <stdio.h>
#include <stdarg.h>
#include <time.h>


typedef enum 
{
    LOG_EMERGENCY = 0,
    LOG_ALERT,
    LOG_CRITICAL,
    LOG_ERROR,
    LOG_WARNING,
    LOG_NOTICE,
    LOG_INFO,
    LOG_DEBUG
} LogLevel;

void Logger_Init      (LogLevel level, const char* path_file);
void Logger_Set_Level (LogLevel level);
void Logger_Close     (void);
void Logger_Log       (LogLevel level, const char* file, int line, const char* format, ...);

#define Log_Message(level, format, ...) \
        Logger_Log (level, __FILE__, __LINE__, format, ##__VA_ARGS__)


#endif /* _LOGGER_H_ */