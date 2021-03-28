/**  
 * @file cpsw_singlecore.h
 *
 * @brief 
 *  Holds all the constants and API definitions required by the example
 *  application to run.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2009-2014, Texas Instruments, Inc.
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
#ifndef _CPSW_MGMT_H_
#define _CPSW_MGMT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdlib.h>
#include <xdc/runtime/System.h>

#ifdef SIMULATOR_SUPPORT
/** Number of ports in the ethernet subsystem */
#undef          NUM_PORTS
#define         NUM_PORTS                   CSL_CPSW_NUM_PORTS

#else

#ifndef NUM_PORTS
/** Number of ports in the ethernet subsystem (default for EVM) */
#define         NUM_PORTS                   3u

#endif

#endif /* SIMULATOR_SUPPOR */


/* Define LoopBack modes */  
#define CPSW_LOOPBACK_NONE           0   /* No Loopback */
#define CPSW_LOOPBACK_INTERNAL       1   /* SGMII internal Loopback */
#define CPSW_LOOPBACK_EXTERNAL       2   /* Loopback outside SoC */
#define CPSW_LOOPBACK_SERDES         3   /* SGMII Serdes Loopback */
extern int cpswLpbkMode;
extern int cpswSimTest;
extern void CycleDelay (int32_t count);

#ifdef __cplusplus
}
#endif

#endif /* _CPSW_MGMT_H_ */
/* Nothing past this point */
