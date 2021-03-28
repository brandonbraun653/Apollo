/**  
 * @file cpts_ts_cmp.h
 *
 * @brief 
 *  Holds all the constants and API definitions required by the example
 *  application to run.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2015, Texas Instruments, Inc.
 * 
 *  Redistribution and use in source and binary forms, with or without 
 *  modification, are permitted provided that the following conditions 
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright 
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the 
 *    documentation and/or other materials provided with the   
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/
#ifndef _CPTS_TS_CMP_H_
#define _CPTS_TS_CMP_H_

#ifdef __cplusplus
extern "C" {
#endif

/* C Standard library Include */
#include <string.h>

 /* c99 types */
#include <stdint.h>

/* Chip Level definitions include */
#include <ti/csl/csl_chip.h>

/* CSL EMAC include */
#include <ti/csl/csl_cpsw.h>

#ifndef __LINUX_USER_SPACE
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Memory.h>
#include <xdc/runtime/Error.h>
#include <ti/sysbios/family/c64p/Hwi.h>
#include <ti/sysbios/family/c64p/EventCombiner.h> 
#else
#include "armv7/linux/fw_test.h"
/* Socket Includes */
#include "./armv7/linux/sockutils.h"
#include "./armv7/linux/sockrmmsg.h"
/* Semaphore Includes */
#include <semaphore.h>
#include <errno.h>
#endif

extern void Config_CPTS (uint32_t toggle);
extern void CycleDelay (int32_t count);
extern void CycleDelayTo (int32_t time);
extern void passPowerUp (void);
extern void APP_exit (int32_t code);

#ifdef __LINUX_USER_SPACE
extern void* Cpts_TsCmpApp (void *args);
#else
extern void Cpts_TsCmpApp (void);
#endif

#ifndef __LINUX_USER_SPACE
extern volatile unsigned int cregister TSCL;
#endif /* __LINUX_USER_SPACE */

#ifdef __cplusplus
}
#endif

#endif /* _CPTS_TS_CMP_H_ */
/* Nothing past this point */

