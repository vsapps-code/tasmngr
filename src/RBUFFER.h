/** @file: rbuffer.h
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
#ifndef __RBUFFER_H__
#define __RBUFFER_H__

/* Standard headers */

/* Application headers */
#include "VSAPPS_globals.h"

/* EXTERN macro: */
#ifdef __RBUFFER_IMPORT__
    #define EXTERN
#else
    #define EXTERN extern
#endif

/* Constants */

/* Types */
enum rbuffer_Direction {
    rbuffer_NORTH,
    rbuffer_EAST,
    rbuffer_SOUTH,
    rbuffer_WEST
};

/* Structures */
typedef struct RBuffer
{
    void* p_data;
    uint8_t elem_size_byte;
    uint8_t buffer_size;
    uint8_t head_index;
    uint8_t tail_index;
}RBuffer, *p_RBuffer;

/* Global variables */

/* Function prototypes */
/*
 * Function: rbuffer_init
 * ------------------------------------------------------------------------------
 *   @brief initializes the RBuffer object data
 *
 *   @param p_RBuffer[in]:      pointer of RBuffer object to be initialized
 *   @param p_buffer_array[in]: pointer to the array which keeps the data
 *   @param elem_size[in]:      size of one element to be kept in the buffer 
 *   @param buffer_size[in]:    max number of elements can be kept in the 
 *                              buffer
 *
 *   @return: void
 */
EXTERN void rbuffer_init(p_RBuffer p_RBuffer,
                        void *p_buffer_array,
                        uint8_t elem_size,
                        uint8_t buffer_size);

/*
 * Function: rbuffer_push_one_elem
 * ------------------------------------------------------------------------------
 *   @brief Pushes one element to the ringbuffer object
 *
 *   @param me[in]:         pointer of RBuffer ringbuffer object
 *   @param p_data_in[in]:  pointer to the structure to be pusshed to ring buffer
 *
 *   @return: bool:         returns true in case the push is successfull
 *                          returns false in case the ring buffer is full and 
 *                                  the data could not be inserted
 */
EXTERN bool rbuffer_push_one_elem(p_RBuffer me,
                                void *p_data_in);

/*
 * Function: rbuffer_pop_one_elem
 * ------------------------------------------------------------------------------
 *   @brief Pushes one element to the ringbuffer object
 *
 *   @param me[in]:         pointer of RBuffer ringbuffer object
 *   @param p_data_out[in]: pointer to the structure to be pusshed to ring buffer
 *
 *   @return: bool:         returns true there is data and pop is successfull
 *                          returns false if there is no data to be popped
 */
EXTERN bool rbuffer_pop_one_elem(p_RBuffer me,
                                void *p_data_out);

#undef __RBUFFER_IMPORT__
#undef EXTERN
#endif // #define __RBUFFER_H__