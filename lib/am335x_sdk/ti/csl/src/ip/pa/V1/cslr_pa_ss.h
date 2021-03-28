/********************************************************************
 * Copyright (C) 2011-2018 Texas Instruments Incorporated.
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
#ifndef CSLR_PA_SS_V1_H_
#define CSLR_PA_SS_V1_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#include "cslr_pa_ra.h"
#include "cslr_ra_bridge.h"
#include "cslr_ra_lut1_cfg.h"
#include "cslr_ra_lut1_dbg.h"
#include "cslr_pa_stats.h"
#include "cslr_pa_ppu.h"
#include "cslr_pa_cluster.h"
#include "cslr_cpsw_thread_mapper.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for MAILBOX
\**************************************************************************/
typedef struct  {
    volatile Uint32 MBOX_SLOT[4];
} CSL_Pa_ssMailboxRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Pa_ssMailboxRegs MAILBOX[16];
    volatile Uint8 RSVD0[0x400 - sizeof(CSL_Pa_ssMailboxRegs)*16];
    CSL_Ra_bridgeRegs   RA_BRIDGE;
    volatile Uint8 RSVD1[0x100 - sizeof(CSL_Ra_bridgeRegs)];
    CSL_Cpsw_thread_mapperRegs   CPSW_THREAD_MAPPER;
    volatile Uint8 RSVD2[0x300 - sizeof(CSL_Cpsw_thread_mapperRegs)];
    CSL_Pa_raRegs  RA;
    volatile Uint8 RSVD3[0x5800 - sizeof(CSL_Pa_raRegs)];
    CSL_Pa_stats_controlRegs   STATS_CONTROL;
    volatile Uint8 RSVD4[0x2000 - sizeof(CSL_Pa_stats_controlRegs)];
    volatile Uint32 QUERY_STATS[0x1000];
    volatile Uint32 COLLECT_STATS[0x1000];
    volatile Uint8 RSVD5[0x10000];
    volatile Uint32 SRAM[0x2000];
} CSL_Pa_ssRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* MBOX_SLOT */

#define CSL_PA_SS_MBOX_SLOT_STATUS_BITS_MASK (0xFFFFFFFFu)
#define CSL_PA_SS_MBOX_SLOT_STATUS_BITS_SHIFT (0x00000000u)
#define CSL_PA_SS_MBOX_SLOT_STATUS_BITS_RESETVAL (0x00000000u)

#define CSL_PA_SS_MBOX_SLOT_RESETVAL     (0x00000000u)

/* STREAMSWITCH_REVISION */

#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_MINOR_MASK (0x0000003Fu)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_MINOR_SHIFT (0x00000000u)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_MINOR_RESETVAL (0x00000000u)

#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_CUSTOM_MASK (0x000000C0u)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_CUSTOM_SHIFT (0x00000006u)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_CUSTOM_RESETVAL (0x00000000u)

#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_MAJOR_MASK (0x00000700u)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_MAJOR_SHIFT (0x00000008u)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_MAJOR_RESETVAL (0x00000000u)

#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_RTL_MASK (0x0000F800u)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_RTL_SHIFT (0x0000000Bu)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_RTL_RESETVAL (0x00000000u)

#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_MODULE_MASK (0x0FFF0000u)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_MODULE_SHIFT (0x00000010u)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_MODULE_RESETVAL (0x00000000u)

#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_SCHEME_MASK (0xC0000000u)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_SCHEME_SHIFT (0x0000001Eu)
#define CSL_PA_SS_STREAMSWITCH_REVISION_REV_SCHEME_RESETVAL (0x00000000u)

#define CSL_PA_SS_STREAMSWITCH_REVISION_RESETVAL (0x00000000u)

/* STREAMSWITCH_SOFT_RESET */

#define CSL_PA_SS_STREAMSWITCH_SOFT_RESET_TXSTA_MASK (0x00000007u)
#define CSL_PA_SS_STREAMSWITCH_SOFT_RESET_TXSTA_SHIFT (0x00000000u)
#define CSL_PA_SS_STREAMSWITCH_SOFT_RESET_TXSTA_RESETVAL (0x00000006u)

#define CSL_PA_SS_STREAMSWITCH_SOFT_RESET_TXSTB_MASK (0x00000700u)
#define CSL_PA_SS_STREAMSWITCH_SOFT_RESET_TXSTB_SHIFT (0x00000008u)
#define CSL_PA_SS_STREAMSWITCH_SOFT_RESET_TXSTB_RESETVAL (0x00000006u)

#define CSL_PA_SS_STREAMSWITCH_SOFT_RESET_RESETVAL (0x00000606u)


/* PDSP_RAM */

#define CSL_PA_SS_SRAM_RAM_MASK      (0xFFFFFFFFu)
#define CSL_PA_SS_SRAM_RAM_SHIFT     (0x00000000u)
#define CSL_PA_SS_SRAM_RAM_RESETVAL  (0x00000000u)

#define CSL_PA_SS_SRAM_RESETVAL      (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
