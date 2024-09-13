/** @file: TASKMNGR.h
 * ------------------------------------------------------------------------------
 *  @brief Function prototypes for Task Manager implementaion
 *
 *  @details Task Manager is a event based task management implementation for
 *           hard realtime systems, for those RTOS is not suitable. 
 *           Tasks can be pushed by periodic, sporadic functions or interrups. 
 *           The dispacher function pulls the task which has the highest priority
 *           (lowest in number) and executes it until the end. 
 *           There is no preemtion. In case an urgent task is received during the 
 *           execution of a low priority task, it has to be wait until the low 
 *           priority task finishes its execution.  Therefore, all tasks should 
 *           be implemented as nonblocking. Since only one task executed in one 
 *           cyle there is no overhead coming from shared variable protection 
 *           mechanisms. The purpose of Task Manager library is maximaxing the 
 *           CPU utilization while executing the time critical jobs with 
 *           minumum latency. Thanks to determisitic structure of the library 
 *           timing analysis of the systems are expected to be simpler and having 
 *           less uncertainity.  
 *
 *  @author Volkan Salma <volkan.salma@vsapps.nl>,   Start Date: 13 Sep 2026
 *
 *  Major Changes: None
 *  
 *  @copyright Copyright (C) 2024, VSApps Engineering Solutions, www.vsapps.nl
 * ------------------------------------------------------------------------------
 */
#ifndef __TASKMNGR_H__
#define __TASKMNGR_H__

/* Standard headers */

/* Application headers */
#include "VSAPPS_globals.h"
#include "TASKMNGR_config.h"

/* EXTERN macro: */
#ifdef __TASKMNGR_IMPORT__
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Constants */

/* Types */
typedef enum E_TaskID;

typedef struct taskmanager_TASK_CONF
{
    E_TaskID id;            /* unique id of the task */
    uint8_t priority;       /* priority of the task 0 is the highest priority */
    uint8_t que_size;       /* how many tasks can be kept before processing */
    size_t  payload_size;   /* the size of one payload data item */
    void    *p_payload_data; /* starting address of payload data array for a task */
}taskmanager_TASK_CONF;

/* Structures */

/* Global variables */
struct taskmngr_LaneInfo
{
    uint8_t priority;              /* assigned priority of a lane, 0 is the highest priority */
    uint8_t lane_length;           /* how many tasks can be kept in the task que */
    void    *ring_buffer_array;    /* pointer to the array which keeps the task object data */
}taskmngr_TaskInfo;


struct TaskConf
{
    void*   data;               /* pointer to the payload task data */
    void*   data_unit_size;     /* size of one payload data */
    void*   exe_function;       /* task function to be executed */
};


struct typedef TaskQue
{
    Ringbuffer [taskque_PRIORTY_LEVELS]
}TaskQue, *p_TaskQue;


/* Function prototypes */
EXTERN void tasmngr_setup();

EXTERN void taskmngr_dispatch();

EXTERN bool taskmngr_push_task(void* TaskData, uint8_t priority);

#undef __TASKMNGR_IMPORT__
#undef EXTERN
#endif // #define __TASKMNGR_H__

