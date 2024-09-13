/** @file: AppExample.c
 * ------------------------------------------------------------------------------
 *  @brief  Example application to demonstrate the usage of 
 *          VSAPPS Task Manager Library
 *  @author Volkan Salma <volkan.salma@vsapps.nl>
 *
 *  Copyright (C) 2024, VSApps Engineering Solutions, www.vsapps.nl
 * ------------------------------------------------------------------------------
 */

/* Standard headers */
#include <pthread.h>

/* Application headers */
#include "VSAPPS_globals.h"
#include "LOGGER.h"
#include "TASKMNGR.h"

/* Self module import */

/* Private macros and constants */

/* Private types */

/* Private globals */
/* TASKQUE configuration */
STATIC const struct taskmngr_LaneInfo taskmanager_TASK_CONF[] =
{
/*      Priority                                                   */       
/*      |               Queue size                                       */
/*      |               |       Adress of Taskdata buffer                    */    
/*      |               |       |                                            */

        {taks_id, 0,             10,     &lane_data[0],  taks_deadline, task_function, timeout_function};
        {1,             5,      &lane_data[0]  };
        {2,             5,      &lane_data[0]  };
        {NULL,          NULL,   NULL           };       /* table termination */
}

/* Private functions */
void* periodic_event_feed_example(void *vargp)
{
    char periodic_event_payload[100];

    while(1)
    {
        /* Create random text consists of 100 chars */

        tasmngr_push_task(id, &periodic_event_payload);
        usleep(100 * 1000); /* 100 ms */
    }
}

void* task_function_for_periodic_events(void* payload, taskmngr_TaskData stats)
{

    logger_log(LOG_INFO, "Periodic event called: call latency: \n");
}

void* timeout_function(taskmngr_E_TaskIDs taskId, taskmngr_TaskData stats)
{
    logger_log(LOG_WARNING, "!! Deadline missed for: call latency: \n");
}

int main()
{
    pthread_t thread_periodic;
    pthread_t thread_sporadic;
    pthread_t thread_fast;
    
    logger_log(LOG_INFO, "-> AppExample started\n");
    
    /* Configuration of task manager */ 
    /* !! needs to be called before the first event !! */
    tasmngr_setup(&taskmanager_TASK_CONF);

    /* Event feeder threads */
    pthread_create(&thread_periodic, NULL, periodic_event_feed_example, NULL);
    pthread_create(&thread_sporadic, NULL, sporadic_event_feed_example, NULL);
    pthread_create(&thread_fast, NULL, fast_event_feed_example, NULL);

    while( true )
    {
        taskmngr_dispatch();
    }

    logger_log(LOG_INFO, "-> AppExample terminated\n");
    return 0;
}

/* Implementation of public functions */
