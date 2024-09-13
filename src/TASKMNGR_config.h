/** @file: TASKMNGR_config.h
 * ------------------------------------------------------------------------------
 *  @brief Application specific configuration for VSApps TASKMNGR library 
 *
 *  @details This file is an application configuration example
 *           which uses TASKMNGR to utilize its tasks     
 *
 *  @author Volkan Salma <volkan.salma@vsapps.nl>,   Start Date: 13 Sep 2026
 *
 *  Major Changes: None
 *  
 *  @copyright Copyright (C) 2024, VSApps Engineering Solutions, www.vsapps.nl
 * ------------------------------------------------------------------------------
 */
#ifndef __TASKMNGR_CONFIG_H__
#define __TASKMNGR_CONFIG_H__

/* Standard headers */

/* Application headers */
#include "TASKMNGR.h"

/* EXTERN macro: */

/* Constants */
#define taskmngr_TOTAL_TASK_COUNT  (4)     /* How many tasks exist */

/* Task Identifiers */
const E_TaskID E_TaskID =
{
    TASK_PERIODIC   = 0,
    TASK_SPORADIC   = 1,
    TASK_FAST       = 2,
    TASK_IDLE       = 3
};

/* Types */

/* Structures */

/* Global variables */

/* Function prototypes */

