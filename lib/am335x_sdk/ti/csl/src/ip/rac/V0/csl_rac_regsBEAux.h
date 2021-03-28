/* =============================================================================
 *   Copyright (c) Texas Instruments Incorporated 2002, 2003, 2004, 2005, 2006
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

/**
 *   @file  csl_rac_regsBEAux.h
 *
 *   @brief
 *      This file contains all the API operation prototypes for RAC COMMON CSL
 *      for the BackEnd interface
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002, 2003, 2004, 2005, 2006, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par
 */
#ifndef CSL_RAC_BE_AUX_H
#define CSL_RAC_BE_AUX_H

#include <ti/csl/src/ip/rac/V0/csl_rac_regs.h>
#include <ti/csl/src/ip/rac/V0/csl_rac_regsBETypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* =============================================================================
 * BETI Management Function Declarations
 * =============================================================================
 */

extern void CSL_RAC_BETI_enable (
	CSL_RAC_Handle              hRac
);

extern void CSL_RAC_BETI_disable (
	CSL_RAC_Handle              hRac
);

extern CSL_RAC_BETI_statusBit CSL_RAC_BETI_getStatus (
	CSL_RAC_Handle              hRac
);

extern void CSL_RAC_BETI_setWatchDog (
	CSL_RAC_Handle              hRac,
	Uint16                      nbCyclesToReload
);

extern Uint32 CSL_RAC_BETI_getWatchDogStatus (
	CSL_RAC_Handle              hRac,
	Uint8                       gccpId
);

extern CSL_RAC_BETI_wdInterruptStatus CSL_RAC_BETI_getWatchDogInterruptStatus (
	CSL_RAC_Handle              hRac,
	Uint8                       gccpId
);

extern CSL_RAC_BETI_odbtStatusBit CSL_RAC_BETI_getOdbtStatus (
	CSL_RAC_Handle              hRac,
	Uint8                       odbtEntryId
);

/* =============================================================================
 * BEII Management Function Declarations
 * =============================================================================
 */

extern void CSL_RAC_BEII_enable (
	CSL_RAC_Handle              hRac
);

extern void CSL_RAC_BEII_disable (
	CSL_RAC_Handle              hRac
);

extern void CSL_RAC_BEII_setMasterMask (
	CSL_RAC_Handle              hRac,
	Uint8                       cpuId,
	CSL_RAC_BEII_interrupt      cpuIntContrlEnable
);

extern void CSL_RAC_BEII_getInterruptStatus (
	CSL_RAC_Handle                  hRac,
	Uint8                           cpuId,
	CSL_RAC_BEII_interruptStatus    *cpuIntStatus
);

extern void CSL_RAC_BEII_setCycleOverflowMask (
	CSL_RAC_Handle              hRac,
	Uint8                       cpuId,
	Uint8                       gccpId,
	CSL_RAC_BEII_interrupt      interruptEnable
);

extern void CSL_RAC_BEII_setFifoOverflowMask (
	CSL_RAC_Handle              hRac,
	Uint8                       cpuId,
	Uint8                       gccpId,
	CSL_RAC_BEII_interrupt      interruptEnable
);

extern void CSL_RAC_BEII_setSequencerIdleMask (
	CSL_RAC_Handle              hRac,
	Uint8                       cpuId,
	Uint8                       gccpId,
	CSL_RAC_BEII_interrupt      interruptEnable
);

extern void CSL_RAC_BEII_setBeWatchDogMask (
	CSL_RAC_Handle              hRac,
	Uint8                       cpuId,
	Uint8                       gccpId,
	CSL_RAC_BEII_interrupt      interruptEnable
);

extern void CSL_RAC_BEII_setBetiEotMask (
	CSL_RAC_Handle              hRac,
	Uint8                       cpuId,
	CSL_RAC_BEII_interrupt      interruptEnable
);

extern void CSL_RAC_BEII_setBetiObbtRdCrossingMask (
	CSL_RAC_Handle              hRac,
	Uint8                       cpuId,
	CSL_RAC_BEII_interrupt      interruptEnable
);

extern void CSL_RAC_BEII_setBetiOdbtRdCrossingMask (
	CSL_RAC_Handle              hRac,
	Uint8                       cpuId,
	CSL_RAC_BEII_interrupt      interruptEnable
);

extern void CSL_RAC_BEII_setFeWatchDogMask (
	CSL_RAC_Handle              hRac,
	Uint8                       cpuId,
	CSL_RAC_BEII_interrupt      interruptEnable
);

extern Uint32 CSL_RAC_BETI_getObbtRdCrossingStatus (
	CSL_RAC_Handle              hRac
);

extern Uint32 CSL_RAC_BETI_getOdbtRdCrossingStatus (
	CSL_RAC_Handle              hRac
);

extern Uint32 CSL_RAC_BETI_getEotInterruptStatus (
	CSL_RAC_Handle              hRac,
	Uint8 cpuId
);

/* =============================================================================
 * VBUS Stats Register Access Function Declarations
 * =============================================================================
 */

extern Uint32 CSL_RAC_Stats_getCfgTotalAccess (
	CSL_RAC_Handle              hRac
);

extern Uint32 CSL_RAC_Stats_getCfgWriteAccess (
	CSL_RAC_Handle              hRac
);

extern Uint32 CSL_RAC_Stats_getCfgReadAccess (
	CSL_RAC_Handle              hRac
);

extern Uint32 CSL_RAC_Stats_getSlaveTotalAccess (
    CSL_RAC_Handle              hRac
);

extern Uint32 CSL_RAC_Stats_getSlaveWriteAccess (
	CSL_RAC_Handle              hRac
);

extern Uint32 CSL_RAC_Stats_getSlaveReadAccess (
	CSL_RAC_Handle              hRac
);

extern Uint32 CSL_RAC_Stats_getMasterLowPrioAccess (
	CSL_RAC_Handle              hRac
);

extern Uint32 CSL_RAC_Stats_getMasterHighPrioAccess (
	CSL_RAC_Handle              hRac
);

extern void CSL_RAC_HP_FD_CTL_setDataPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_HP_FD_CTL_setObdPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_HP_FPE_setDataPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_HP_FPE_setObdPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_FD_CTL_setDataPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_FD_CTL_setObdPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_FD_DATA_setDataPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_FD_DATA_setObdPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_FPE_setDataPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_FPE_setObdPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_FT_setDataPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_FT_setObdPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_PM_setDataPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_PM_setObdPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_PD_setDataPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_PD_setObdPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_SPE_setDataPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_SPE_setObdPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_SIP_setDataPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

extern void CSL_RAC_LP_SIP_setObdPriority (
	CSL_RAC_Handle              hRac,
	Uint8                       priorityVal
);

#ifdef __cplusplus
}
#endif

#endif
