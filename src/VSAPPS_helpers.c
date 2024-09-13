/** @file: VSAPPS_helpers.c
 * ------------------------------------------------------------------------------
 *  @brief Function implementations for VSAPPS general helper functions. 
 *  @author Volkan Salma <volkan.salma@vsapps.nl>
 *
 *  Copyright (C) 2024, VSApps Engineering Solutions, www.vsapps.nl
 * ------------------------------------------------------------------------------
 */

/* Standard headers */

/* Application headers */

/* Self module import */
#define __VSAPPS_HELPERS_IMPORT__
#include "VSAPPS_helpers.h"

/* Private macros and constants */

/* Private types */

/* Private globals */

/* Private functions */

/* Implementation of public functions */
void vsapps_memcpy(void *p_dest, void *p_src, size_t length)
{
    uint8_t *p_src_ = (uint8_t*)p_src;
    uint8_t *p_dest_ = (uint8_t*)p_dest;

    for (size_t i = 0; i < length; i++)
    {
        p_dest_[i] = p_src_[i];
    }
}

void vsapps_memset(void *p_dest , uint8_t value,  uint16_t len)
{
    uint8_t *p = p_dest;

    while( len-- )
    {
        *p++ = value;
    }
}