#include <stdio.h>

#include "LOGGER.h"

void logger_log(E_LogType logtype, char* log_msg)
{
    if(logtype == LOG_FATAL)
    {
        printf("ERROR: %s/n", log_msg);
    }
    else if (logtype == LOG_WARNING)
    {
        printf("WARNING: %s/n", log_msg);
    }
    else if(logtype == LOG_INFO)
    {
        printf("INFO: %s/n", log_msg);
    }
}

