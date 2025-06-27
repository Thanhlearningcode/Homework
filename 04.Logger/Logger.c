#include "Logger.h"
#include <stdarg.h>
#include <time.h>
#include <stdlib.h> 
static LogLevel current_level = LOG_DEBUG;
static FILE* log_file = NULL;

static const char* Level_To_String(LogLevel level) 
{
    switch (level)
    {
        case LOG_EMERGENCY: return "EMERGENCY";
        case LOG_ALERT:     return "ALERT";
        case LOG_CRITICAL:  return "CRITICAL";
        case LOG_ERROR:     return "ERROR";
        case LOG_WARNING:   return "WARNING";
        case LOG_NOTICE:    return "NOTICE";
        case LOG_INFO:      return "INFO";
        case LOG_DEBUG:     return "DEBUG";
        default:            return "UNKNOWN";
    }
}

static void Get_Current_Time (char* buffer, size_t size) 
{
    time_t now = time(NULL);
    struct tm* t = localtime(&now);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", t);
}

void Logger_Init(LogLevel level, const char* path_file)
{
    current_level = level;
    if (path_file) {
        
        char command[128];
        snprintf(command, sizeof(command), "mkdir -p %s", "Log");
        system(command);

        log_file = fopen(path_file, "a");
    }
}

void Logger_Set_Level(LogLevel level)
 {
    current_level = level;
}

void Logger_Close(void) 
{
    if (log_file) 
    {
        fclose(log_file);
        log_file = NULL;
    }
}

void Logger_Log(LogLevel level, const char* file, int line, const char* format, ...) 
{
    if (level > current_level) return;

    char timestamp[20];
    Get_Current_Time(timestamp, sizeof(timestamp));

    FILE* output = (level <= LOG_WARNING) ? stderr : stdout;

    va_list args;
    va_start(args, format);

    fprintf(output, "[%s] [%s] [%s:%d] - ", timestamp, Level_To_String(level), file, line);
    vfprintf(output, format, args);
    fprintf(output, "\n");
    fflush(output);

    if (log_file)
     {
        fprintf(log_file, "[%s] [%s] [%s:%d] - ", timestamp, Level_To_String(level), file, line);
        va_start(args, format);  
        vfprintf(log_file, format, args);
        fprintf(log_file, "\n");
        fflush(log_file);             //< This functions is referened from chatgpt
    }

    va_end(args);
}
