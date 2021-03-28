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
 *   @file  csl_rac_regsFEAux.h
 *
 *   @brief
 *      This file contains all the API operation prototypes for RAC COMMON CSL
 *      for the FrontEnd interface
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002, 2003, 2004, 2005, 2006, Texas Instruments, Inc.
 *  @n   Use of this software is controlled by the terms and conditions found
 *  @n   in the license agreement under which this software has been supplied.
 *  ===========================================================================
 *  \par
 */
#ifndef CSL_RAC_FE_AUX_H
#define CSL_RAC_FE_AUX_H

#include <ti/csl/src/ip/rac/V0/csl_rac_regs.h>
#include <ti/csl/src/ip/rac/V0/csl_rac_regsFETypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* =============================================================================
 * FE Management Function Declarations
 * =============================================================================
 */

extern void CSL_RAC_FE_enable (
	CSL_RAC_Handle              hRac
);

extern void CSL_RAC_FE_disable (
	CSL_RAC_Handle              hRac
);

extern CSL_RAC_FE_transferState CSL_RAC_FE_getStatus (
	CSL_RAC_Handle              hRac
);

extern CSL_RAC_FE_gccpStatus CSL_RAC_FE_getGccpStatus (
	CSL_RAC_Handle              hRac,
	Uint8                       gccpId
);

extern void CSL_RAC_FE_setInputBufferDepth (
	CSL_RAC_Handle              hRac,
	Uint8                       ibDepth
);

extern void CSL_RAC_FE_setMaxCyclesPerIteration (
	CSL_RAC_Handle              hRac,
	Uint16                      maxCyclesNb
);

extern Uint16 CSL_RAC_FE_getWatchDogStatus (
	CSL_RAC_Handle              hRac
);

extern CSL_RAC_FE_wdInterruptStatus CSL_RAC_FE_getWatchDogInterruptStatus (
	CSL_RAC_Handle              hRac
);

extern void CSL_RAC_FE_setTimestamp (
	CSL_RAC_Handle              hRac,
	CSL_RAC_FE_Timestamp_req    *timestamp
);

extern void CSL_RAC_FE_getTimestamp (
	CSL_RAC_Handle              hRac,
	CSL_RAC_FE_Timestamp_req    *timestamp
);

extern void CSL_RAC_FE_softwareReset (
	CSL_RAC_Handle              hRac
);

extern CSL_RAC_FE_resetStatus CSL_RAC_FE_getResetStatus (
	CSL_RAC_Handle              hRac
);

extern void CSL_RAC_FE_startSoftwareIteration (
	CSL_RAC_Handle              hRac
);

#ifdef __cplusplus
}
#endif

#endif
