/********************************************************************
* Copyright (C) 2003-2018 Texas Instruments Incorporated.
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
/*********************************************************************
* file: cslr_pdsp.h
*
* Brief: This file contains the Register Description for PA Packet 
*        Processing Unit (PPU)   
*
*********************************************************************/
#ifndef CSLR_PA_PPU_H_
#define CSLR_PA_PPU_H_

#include <ti/csl/cslr.h>

#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_cp_timer16.h>
#include "cslr_pa_lut1.h"
#include "cslr_pa_lut2.h"
#include "cslr_pa_pcheck.h"
#include "cslr_pa_pdsp.h"

#ifdef __cplusplus
extern "C" {
#endif

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Pa_pdspControl_statusRegs PDSP_CONTROL_STATUS;
    volatile Uint8 RSVD0[0x400 - sizeof(CSL_Pa_pdspControl_statusRegs)]; 
    CSL_Pa_pdspDebugRegs PDSP_DEBUG;
    volatile Uint8 RSVD1[0x400 - sizeof(CSL_Pa_pdspDebugRegs)];
    CSL_Cp_timer16Regs CP_TIMER;
    volatile Uint8 RSVD2[0x800 - sizeof(CSL_Cp_timer16Regs)];
    CSL_Pa_lut1Regs  LUT1;  
    volatile Uint8 RSVD3[0x400 - sizeof(CSL_Pa_lut1Regs)];
    CSL_Pa_lut2Regs  LUT2;  
    volatile Uint8 RSVD4[0x800 - sizeof(CSL_Pa_lut2Regs)];
    CSL_Pa_pcheckRegs PCHECK;
    volatile Uint8 RSVD5[0x2400 - sizeof(CSL_Pa_pcheckRegs)];
    volatile Uint32 PDSP_IRAM[0xC00];
} CSL_Pa_ppuRegs;


#ifdef __cplusplus
}
#endif

#endif
