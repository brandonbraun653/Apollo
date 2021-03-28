/********************************************************************
 * Copyright (C) 2003-2015 Texas Instruments Incorporated.
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
* file: cslr_bcp.h
*
* Brief: This file contains the Register Description for bcp
*
*********************************************************************/
#ifndef CSLR_BCP_H_
#define CSLR_BCP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

/* Common */
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_glbl_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_tm_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_tm_mmr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_dio_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_dio_mmr.h>

/* Downlink modules */
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_crc_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_crc_mmr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_rm_lte_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_rm_xcdma_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_rm_wimax_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_enc_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_enc_mmr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_int_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_int_mmr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_mod_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_mod_mmr.h>

/* Uplink modules */
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_rd_lte_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_rd_mmr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_rd_xcdma_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_ssl_lte_wimax_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_ssl_wcdma_fdd_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_ssl_wcdma_tdd_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_dnt_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_dnt_mmr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_cor_hdr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_cor_mmr.h>
#include <ti/csl/src/ip/bcp/V0/cslr_bcp_cdmahp_mmr.h>

/**************************************************************************\
* Register Overlay Structure for the common interrupt registers
\**************************************************************************/
typedef struct {
    volatile Uint32 INTR_IRS;
    volatile Uint32 INTR_IRS_SET;
    volatile Uint32 INTR_IRS_CLR;
    volatile Uint32 INTR_EN;
    volatile Uint32 INTR_EN_SET;
    volatile Uint32 INTR_EN_CLR;
    volatile Uint32 INTR_EN_STS;
} CSL_Bcp_IntRegs;

/**************************************************************************\
* Register Overlay Structure for Data Logger
\**************************************************************************/
typedef struct  {
    volatile Uint32 DLG_GLOBAL_HDR; /* Data logger control Register */
    volatile Uint32 DLG_TM_SW_TIMESTAMP; /* Data logger control Register */
    volatile Uint32 DLG_HW_TIMESTAMP_ENG_ERR; /* Data logger control Register */
    volatile Uint8 RSVD0[4];
} CSL_Bcp_DataLoggerRAMEntry; /* Data Logger */

/**************************************************************************\
* Register Overlay Structure for the common Data Logger registers
\**************************************************************************/
typedef struct  {
    volatile Uint32 DLG_CONTROL;
    volatile Uint32 DLG_STATUS;
    volatile Uint32 DLG_GLOBAL_HDR;
} CSL_Bcp_DataLoggerRegs;

/**************************************************************************\
* Register Overlay Structure for the common Data Logger RAM
\**************************************************************************/
typedef struct  {
    CSL_Bcp_DataLoggerRAMEntry DLG_DATA_LOG[256];
} CSL_Bcp_DataLoggerRAM;

#endif
