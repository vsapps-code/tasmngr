/** @file: TASKQUE.h
 * ------------------------------------------------------------------------------
 *  @brief Function prototypes for queue (FIFo) implementaion kept in a 
 *         ring buffer datastructure.
 *
 *  @details Queue implementaion as ring buffer (a.k. circular buffer) is an 
 *  object implementaion to keep/manage any user data type (including user 
 *  defined structures) in an array whose memory needs to be supplied by the 
 *  caller. The implementation is type agnostic. Push and Pop operations deals 
 *  with one element only.  Implementaion is for one producer thread and one 
 *  consumer thread. For this use case there is no locking/critical section usage 
 *  is required.    
 *
 *  @author Volkan Salma <volkan.salma@vsapps.nl>,   Start Date: 8 Sep 2026
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

/* EXTERN macro: */
#ifdef __TASKMNGR_IMPORT__
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Constants */
#define taskmngr_PRIORTY_LEVELS  (5) /* How many seperate priority levels exist */

/* Types */

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
    void*   time_out_func;      /* timeout function to be executed in deadline exceed*/
};

struct TaskData;
{
    uint16_t push_timestamp;
    uint16_t pop_timestamp;
    uint16_t proccessed_timestamp;
    uint16_t deadline_total;
    uint16_t wcet_push_to_pop;
    uint16_t wcet_execution;
    uint16_t wcet_total;
    uint16_t deadline_miss_count;
    uint8_t last_index_task_payload;
}TaskData;

struct typedef TaskQue
{
    Ringbuffer [taskque_PRIORTY_LEVELS]
}TaskQue, *p_TaskQue;


/* Function prototypes */
EXTERN bool taskmngr_push_task(void* TaskData, uint8_t priority);

EXTERN bool taskmngr_pop_task(void* TaskData);

