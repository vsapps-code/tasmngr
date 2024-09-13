#ifndef __LOGGER_H_
#define __LOGGER_H_

typedef enum t_E_LogType
{
    LOG_FATAL   = 0,
    LOG_WARNING = 1,
    LOG_INFO    = 1
} E_LogType;

void logger_log(E_LogType log_type, char* log_msg);

#endif // define __LOGGER_H