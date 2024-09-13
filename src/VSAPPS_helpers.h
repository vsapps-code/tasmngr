/** @file: VSAPPS_helpers.h
 * ------------------------------------------------------------------------------
 *  @brief Function prototypes for VSAPPS general helper functions
 *  @author Volkan Salma <volkan.salma@vsapps.nl>,   Start Date: 11 Sep 2026
 *
 *  Major Changes: None
 *  
 *  @copyright Copyright (C) 2024, VSApps Engineering Solutions, www.vsapps.nl
 * ------------------------------------------------------------------------------
 */
#ifndef __VSAPPS_HELPERS_H__
#define __VSAPPS_HELPERS_H__

/* Standard headers */

/* Application headers */
#include "VSAPPS_globals.h"

/* EXTERN macro: */
#ifdef __VSAPPS_HELPERS_IMPORT__
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Constants */

/* Types */

/* Structures */

/* Global variables */

/* Function prototypes */
/*
 * Function: vsapps_memcpy
 * ------------------------------------------------------------------------------
 *   @brief Copies the data from source (pointing by src pointer) to destination
 *
 *   @param p_dest[in]:         pointer which points to destination memory adress
 *   @param p_src[in]:          pointer which points to destination memory adress
 *   @param length[in]:         length of the memory to be copied 
 *                              (1 means size of uint8_t)
 *
 *   @return: void
 */
EXTERN void vsapps_memcpy(void *p_dest, void *p_src, size_t length);

/*
 * Function: vsapps_memset
 * ------------------------------------------------------------------------------
 *   @brief Fills the destination memory with the given value
 *
 *   @param p_dest[in]:     pointer of RBuffer object to be initialized
 *   @param value[in]:      pointer to the array which keeps the data
 *   @param len[in]:        size of one element to be kept in the buffer 

 *
 *   @return: void:         
 */
EXTERN void vsapps_memset(void *p_dest , uint8_t value,  uint16_t len);

#undef __RBUFFER_IMPORT__
#undef EXTERN
#endif // #define __RBUFFER_H__