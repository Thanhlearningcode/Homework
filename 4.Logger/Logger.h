#ifndef _LOGGER_H_
#define _LOGGER_H_
#include <stdio.h>
#include <stdarg.h>
#include <time.h>

#define log_message(level, fmt, ...) \
        logger_log (level, __FILE__, __LINE__, fmt, ##__VA_ARGS__)

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
} Loglevel;

void Logger_Init      (Loglevel level, const char *logfile_path);
void Logger_Set_Level (Loglevel level);

#endif /* _LOGGER_H_ */