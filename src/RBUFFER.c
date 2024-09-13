/** @file: rbuffer.c
 * ------------------------------------------------------------------------------
 *  @brief Function implementaion for a queue (FIFO) implementaion kept in a 
 *         ring buffer datastructure.
 * 
 *  @author Volkan Salma
 *
 *  Copyright (C) 2024, VSApps Engineering Solutions, www.vsapps.nl
 * ------------------------------------------------------------------------------
 */

/* Standard headers */

/* Application headers */

#define __RBUFFER_IMPORT__
#include "RBUFFER.h"

/* Private macros and constants */

/* Private types */

/* Private globals */

/* Private functions */

/* Implementation of public functions */
void rbuffer_init(p_RBuffer me,
                void* p_buffer_array,
                uint8_t elem_size_byte,
                uint8_t buffer_size
                )
{
    me->p_data = p_buffer_array;
    me->elem_size_byte = elem_size_byte;
    me->buffer_size = buffer_size;
    me->head_index = 0;
    me->tail_index = 0;
    vssapps_memset(p_buffer_array, -1, (buffer_size * elem_size_byte));
}

bool rbuffer_push_one_elem(p_RBuffer me,
                            void* p_data_in)
{
    uint8_t buffer_size = me->buffer_size;
    uint8_t head_index = me->head_index;
    uint8_t elem_size_byte = me->elem_size_byte;

    bool data_pushed = false;
    uint8_t next_head_index = (head_index + 1) % buffer_size;

    if ( next_head_index == me->tail_index )
    {
        /* head reaches to tail, do not write */
        data_pushed = false;
    } 
    else 
    {
        /* there is still place, write one element copying byte by byte */
        vsapps_memcpy(me->p_data + (head_index * elem_size_byte),
                    p_data_in, elem_size_byte);

        /* update the head index */
        me->head_index = next_head_index;

        data_pushed = true;
    }

    return data_pushed;
}

bool rbuffer_pop_one_elem(p_RBuffer me,
                            void* p_data_out) 
{
    uint8_t buffer_size = me->buffer_size;
    uint8_t tail_index = me->tail_index;
    uint8_t elem_size_byte = me->elem_size_byte;

    bool data_popped = false;
    uint8_t next_tail_index = (tail_index + 1) % buffer_size;

    if ( tail_index == me->head_index )
    {
        /* tail reached to head, can not be read */
        data_popped = false;
    }
    else
    {
        /* there is still data to be read, one data can be read */
        vsapps_memcpy(p_data_out,
                        (void*)(me->p_data + (tail_index * elem_size_byte)),
                        elem_size_byte);

        me->tail_index = next_tail_index;
        data_popped = true;
    }

    return data_popped;
}
