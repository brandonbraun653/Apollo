/**
* @file icss_emacCommon.h
* @brief Contains common macros and function definitions
*
*/

/* Copyright (C) {2016} Texas Instruments Incorporated - http://www.ti.com/ 
*
*   Redistribution and use in source and binary forms, with or without 
*   modification, are permitted provided that the following conditions 
*   are met:
*
*     Redistributions of source code must retain the above copyright 
*     notice, this list of conditions and the following disclaimer.
*
*     Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the 
*     documentation and/or other materials provided with the   
*     distribution.
*
*     Neither the name of Texas Instruments Incorporated nor the names of
*     its contributors may be used to endorse or promote products derived
*     from this software without specific prior written permission.
*
*   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/


#ifndef ICSS_COMMON_H
#define ICSS_COMMON_H


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __LINUX_USER_SPACE
#include <time.h>   /* for nanosleep() */
#endif

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/**
 * @brief definition for a generic protocol callback function
 */
typedef int32_t (*ICSS_EmacCallBack)(void* arg, void* arg2);

/**
 * @brief Generic callback configuration for protocol specific callbacks
 */
typedef struct
{
    ICSS_EmacCallBack callBack;
    void * userArg;
} ICSS_EmacCallBackConfig;


/* For  backward compatibility */
#define ICSSEMAC_CallBackConfig ICSS_EmacCallBackConfig

/**
 * @brief MAC configuration structure
 */
typedef struct
{
    ICSS_EmacCallBackConfig* rxRTCallBack;
    ICSS_EmacCallBackConfig* learningExCallBack;
    ICSS_EmacCallBackConfig* txCallBack;
	ICSS_EmacCallBackConfig* rxCallBack;
} ICSS_EmacCallBackObject;

/* For  backward compatibility ICSS_EmacCallBackObject */
#define ICSSEMAC_CallBackObject ICSS_EmacCallBackObject

/**
* @brief Mask for clearing Link Interrupt bit in MDIO Register
*
*/
#define ICSS_MDIO_LINKINT_RAW_MASK_OFFSET   (0x14U)

/*!
 *  @brief Macro indicating true value
 */
#define TRUE_VAL 1U

/*!
 *  @brief Macro indicating false value
 */
#define FALSE_VAL 0U

/*!
 *  @brief Generic typedef to typecast to any pointer
 */
typedef void*       Handle;

/* ========================================================================== */
/*                           Static Inline Fxns                               */
/* ========================================================================== */

#ifdef __LINUX_USER_SPACE
static inline void linux_sleep_ns(int ns) {
    struct timespec ts;
    ts.tv_sec = 0; \
    ts.tv_nsec = ns; \
    nanosleep(&ts, NULL);
}
#endif


#ifdef __cplusplus
}
#endif

#endif /* ICSS_COMMON_H */
