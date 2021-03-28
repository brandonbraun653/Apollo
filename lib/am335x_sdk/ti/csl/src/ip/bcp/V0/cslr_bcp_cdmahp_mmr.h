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
/* file: cslr_bcp_cdmahp.h
*
* Brief: This file contains the Register Description for bcp_cdmahp
*
*********************************************************************/
#ifndef CSLR_BCP_CDMAHP_MMR_H_
#define CSLR_BCP_CDMAHP_MMR_H_

#include <ti/csl/cslr.h>

#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for TCHAN
\**************************************************************************/
typedef struct  {
    volatile Uint32 TCHAN_GCFG_REG_A; /* The Tx Channel Configuration Register A contains real-time control and status information for the Tx DMA channel.  The fields in this register can safely be changed while the channel is in operation. */
    volatile Uint32 TCHAN_GCFG_REG_B; /* The Tx Channel Configuration Register B is used to initialize the default return queue information for the Tx DMA channel.  This register may only be written when the channel is disabled (tx_enable is 0). */
    volatile Uint8 RSVD0[24];
} CSL_Bcp_cdmahpTchanRegs; /* TCFG */

/**************************************************************************\
* Register Overlay Structure for RCHAN
\**************************************************************************/
typedef struct  {
    volatile Uint32 RCHAN_GCFG_REG_A; /* The Rx Channel Configuration Register A contains real-time control and status information for the Rx DMA channel.  The fields in this register can safely be changed while the channel is in operation. */
    volatile Uint8 RSVD0[28];
} CSL_Bcp_cdmahpRchanRegs; /* RCFG */

/**************************************************************************\
* Register Overlay Structure for TCHAN_SCHED
\**************************************************************************/
typedef struct  {
    volatile Uint32 TCHAN_SCHED_CFG_REG; /* The Tx Channel N Scheduler Configuration Register contains static configuration information which affects the conditions under which each channel will be given an opportunity to use the Tx DMA unit(s).  The fields in this register are as follows: */
} CSL_Bcp_cdmahpTchan_schedRegs; /* TXS */

/**************************************************************************\
* Register Overlay Structure for RFLOW
\**************************************************************************/
typedef struct  {
    volatile Uint32 RFLOW_CFG_REG_A; /* The Rx Flow N Configuration Register A contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_B; /* The Rx Flow N Configuration Register B contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_C; /* The Rx Flow N Configuration Register C contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_D; /* The Rx Flow N Configuration Register D contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.  The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_E; /* The Rx Flow N Configuration Register E contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.  The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_F; /* The Rx Flow N Configuration Register F contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   This register is OPTIONAL.  The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_G; /* The Rx Flow N Configuration Register G contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   This register is OPTIONAL.  The fields in this register are as follows: */
    volatile Uint32 RFLOW_CFG_REG_H; /* The Rx Flow N Configuration Register H contains static configuration information for the Rx DMA flow.  The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled.   This register is OPTIONAL.  The fields in this register are as follows: */
} CSL_Bcp_cdmahpRflowRegs; /* RFLOW */

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    volatile Uint8 RSVD0[81920];
    volatile Uint32 REVISION_REG; /* The Revision Register contains the major and minor revisions for the module. */
    volatile Uint32 PERF_CTRL_REG; /* The performance control register contains fields which can be used to adjust the performance of the CDMAHP in the system. */
    volatile Uint32 EMU_CTRL_REG; /* The emulation control register is used to control the behavior of the DMA when the emususp input is asserted. */
    volatile Uint32 PRI_CTRL_REG; /* The priority control register is used to control the priority of the transactions which the DMA generates on it's master interface. */
    volatile Uint32 QM0_BA_REG; /* This register is used to provide a pointer to the base address to the Queues region of Queue Manager 0. */
    volatile Uint32 QM1_BA_REG; /* This register is used to provide a pointer to the base address to the Queues region of Queue Manager 1. */
    volatile Uint32 QM2_BA_REG; /* This register is used to provide a pointer to the base address to the Queues region of Queue Manager 2. */
    volatile Uint32 QM3_BA_REG; /* This register is used to provide a pointer to the base address to the Queues region of Queue Manager 3. */
    volatile Uint8 RSVD1[8160];
    CSL_Bcp_cdmahpTchanRegs TCHAN[8];
    volatile Uint8 RSVD2[7936];
    CSL_Bcp_cdmahpRchanRegs RCHAN[8];
    volatile Uint8 RSVD3[7936];
    CSL_Bcp_cdmahpTchan_schedRegs TCHAN_SCHED[8];
    volatile Uint8 RSVD4[8160];
    CSL_Bcp_cdmahpRflowRegs RFLOW[64];
} CSL_Bcp_cdmahpRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* TCHAN_GCFG_REG_A */

#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_A_TX_ENABLE_MASK (0x80000000u)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_A_TX_ENABLE_SHIFT (0x0000001Fu)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_A_TX_ENABLE_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_A_TX_TEARDOWN_MASK (0x40000000u)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_A_TX_TEARDOWN_SHIFT (0x0000001Eu)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_A_TX_TEARDOWN_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_A_TX_PAUSE_MASK (0x20000000u)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_A_TX_PAUSE_SHIFT (0x0000001Du)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_A_TX_PAUSE_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_A_RESETVAL (0x00000000u)

/* TCHAN_GCFG_REG_B */

#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_B_TX_FILT_EINFO_MASK (0x40000000u)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_B_TX_FILT_EINFO_SHIFT (0x0000001Eu)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_B_TX_FILT_EINFO_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_B_TX_FILT_PSWORDS_MASK (0x20000000u)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_B_TX_FILT_PSWORDS_SHIFT (0x0000001Du)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_B_TX_FILT_PSWORDS_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_B_TX_AIF_MONO_MODE_MASK (0x01000000u)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_B_TX_AIF_MONO_MODE_SHIFT (0x00000018u)
#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_B_TX_AIF_MONO_MODE_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_TCHAN_GCFG_REG_B_RESETVAL (0x00000000u)

/* RCHAN_GCFG_REG_A */

#define CSL_BCP_CDMAHP_RCHAN_GCFG_REG_A_RX_ENABLE_MASK (0x80000000u)
#define CSL_BCP_CDMAHP_RCHAN_GCFG_REG_A_RX_ENABLE_SHIFT (0x0000001Fu)
#define CSL_BCP_CDMAHP_RCHAN_GCFG_REG_A_RX_ENABLE_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RCHAN_GCFG_REG_A_RX_TEARDOWN_MASK (0x40000000u)
#define CSL_BCP_CDMAHP_RCHAN_GCFG_REG_A_RX_TEARDOWN_SHIFT (0x0000001Eu)
#define CSL_BCP_CDMAHP_RCHAN_GCFG_REG_A_RX_TEARDOWN_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RCHAN_GCFG_REG_A_RX_PAUSE_MASK (0x20000000u)
#define CSL_BCP_CDMAHP_RCHAN_GCFG_REG_A_RX_PAUSE_SHIFT (0x0000001Du)
#define CSL_BCP_CDMAHP_RCHAN_GCFG_REG_A_RX_PAUSE_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RCHAN_GCFG_REG_A_RESETVAL (0x00000000u)

/* TCHAN_SCHED_CFG_REG */

#define CSL_BCP_CDMAHP_TCHAN_SCHED_CFG_REG_PRIORITY_MASK (0x00000003u)
#define CSL_BCP_CDMAHP_TCHAN_SCHED_CFG_REG_PRIORITY_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_TCHAN_SCHED_CFG_REG_PRIORITY_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_TCHAN_SCHED_CFG_REG_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_A */

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_EINFO_PRESENT_MASK (0x40000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_EINFO_PRESENT_SHIFT (0x0000001Eu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_EINFO_PRESENT_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_PSINFO_PRESENT_MASK (0x20000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_PSINFO_PRESENT_SHIFT (0x0000001Du)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_PSINFO_PRESENT_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_ERROR_HANDLING_MASK (0x10000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_ERROR_HANDLING_SHIFT (0x0000001Cu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_ERROR_HANDLING_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_DESC_TYPE_MASK (0x0C000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_DESC_TYPE_SHIFT (0x0000001Au)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_DESC_TYPE_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_PS_LOCATION_MASK (0x02000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_PS_LOCATION_SHIFT (0x00000019u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_PS_LOCATION_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_SOP_OFFSET_MASK (0x01FF0000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_SOP_OFFSET_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_SOP_OFFSET_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_DEST_QMGR_MASK (0x00003000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_DEST_QMGR_SHIFT (0x0000000Cu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_DEST_QMGR_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_DEST_QNUM_MASK (0x00000FFFu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_DEST_QNUM_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RX_DEST_QNUM_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_A_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_B */

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_SRC_TAG_HI_MASK (0xFF000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_SRC_TAG_HI_SHIFT (0x00000018u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_SRC_TAG_HI_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_SRC_TAG_LO_MASK (0x00FF0000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_SRC_TAG_LO_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_SRC_TAG_LO_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_DEST_TAG_HI_MASK (0x0000FF00u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_DEST_TAG_HI_SHIFT (0x00000008u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_DEST_TAG_HI_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_DEST_TAG_LO_MASK (0x000000FFu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_DEST_TAG_LO_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RX_DEST_TAG_LO_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_B_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_C */

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_SRC_TAG_HI_SEL_MASK (0x70000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_SRC_TAG_HI_SEL_SHIFT (0x0000001Cu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_SRC_TAG_HI_SEL_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_SRC_TAG_LO_SEL_MASK (0x07000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_SRC_TAG_LO_SEL_SHIFT (0x00000018u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_SRC_TAG_LO_SEL_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_DEST_TAG_HI_SEL_MASK (0x00700000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_DEST_TAG_HI_SEL_SHIFT (0x00000014u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_DEST_TAG_HI_SEL_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_DEST_TAG_LO_SEL_MASK (0x00070000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_DEST_TAG_LO_SEL_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_DEST_TAG_LO_SEL_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_SIZE_THRESH_EN_MASK (0x0000000Fu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_SIZE_THRESH_EN_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RX_SIZE_THRESH_EN_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_C_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_D */

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QMGR_MASK (0x30000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QMGR_SHIFT (0x0000001Cu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QMGR_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QNUM_MASK (0x0FFF0000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QNUM_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ0_SZ0_QNUM_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ1_QMGR_MASK (0x00003000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ1_QMGR_SHIFT (0x0000000Cu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ1_QMGR_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ1_QNUM_MASK (0x00000FFFu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ1_QNUM_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RX_FDQ1_QNUM_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_D_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_E */

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ2_QMGR_MASK (0x30000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ2_QMGR_SHIFT (0x0000001Cu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ2_QMGR_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ2_QNUM_MASK (0x0FFF0000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ2_QNUM_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ2_QNUM_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ3_QMGR_MASK (0x00003000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ3_QMGR_SHIFT (0x0000000Cu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ3_QMGR_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ3_QNUM_MASK (0x00000FFFu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ3_QNUM_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RX_FDQ3_QNUM_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_E_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_F */

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_F_RX_SIZE_THRESH0_MASK (0xFFFF0000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_F_RX_SIZE_THRESH0_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_F_RX_SIZE_THRESH0_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_F_RX_SIZE_THRESH1_MASK (0x0000FFFFu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_F_RX_SIZE_THRESH1_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_F_RX_SIZE_THRESH1_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_F_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_G */

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_G_RX_SIZE_THRESH2_MASK (0xFFFF0000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_G_RX_SIZE_THRESH2_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_G_RX_SIZE_THRESH2_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QMGR_MASK (0x00003000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QMGR_SHIFT (0x0000000Cu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QMGR_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QNUM_MASK (0x00000FFFu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QNUM_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_G_RX_FDQ0_SZ1_QNUM_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_G_RESETVAL (0x00000000u)

/* RFLOW_CFG_REG_H */

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QMGR_MASK (0x30000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QMGR_SHIFT (0x0000001Cu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QMGR_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QNUM_MASK (0x0FFF0000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QNUM_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ2_QNUM_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QMGR_MASK (0x00003000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QMGR_SHIFT (0x0000000Cu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QMGR_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QNUM_MASK (0x00000FFFu)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QNUM_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RX_FDQ0_SZ3_QNUM_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_RFLOW_CFG_REG_H_RESETVAL (0x00000000u)

/* REVISION_REG */

#define CSL_BCP_CDMAHP_REVISION_REG_MODID_MASK (0xFFFF0000u)
#define CSL_BCP_CDMAHP_REVISION_REG_MODID_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_REVISION_REG_MODID_RESETVAL (0x00004E5Au)

#define CSL_BCP_CDMAHP_REVISION_REG_REVRTL_MASK (0x0000F800u)
#define CSL_BCP_CDMAHP_REVISION_REG_REVRTL_SHIFT (0x0000000Bu)
#define CSL_BCP_CDMAHP_REVISION_REG_REVRTL_RESETVAL (0x00000014u)

#define CSL_BCP_CDMAHP_REVISION_REG_REVMAJ_MASK (0x00000700u)
#define CSL_BCP_CDMAHP_REVISION_REG_REVMAJ_SHIFT (0x00000008u)
#define CSL_BCP_CDMAHP_REVISION_REG_REVMAJ_RESETVAL (0x00000001u)

#define CSL_BCP_CDMAHP_REVISION_REG_CUSTOM_MASK (0x000000C0u)
#define CSL_BCP_CDMAHP_REVISION_REG_CUSTOM_SHIFT (0x00000006u)
#define CSL_BCP_CDMAHP_REVISION_REG_CUSTOM_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_REVISION_REG_REVMIN_MASK (0x0000003Fu)
#define CSL_BCP_CDMAHP_REVISION_REG_REVMIN_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_REVISION_REG_REVMIN_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_REVISION_REG_RESETVAL (0x4E5AA100u)

/* PERF_CTRL_REG */

#define CSL_BCP_CDMAHP_PERF_CTRL_REG_WARB_FIFO_DEPTH_MASK (0x003F0000u)
#define CSL_BCP_CDMAHP_PERF_CTRL_REG_WARB_FIFO_DEPTH_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_PERF_CTRL_REG_WARB_FIFO_DEPTH_RESETVAL (0x00000020u)

#define CSL_BCP_CDMAHP_PERF_CTRL_REG_TIMEOUT_CNT_MASK (0x0000FFFFu)
#define CSL_BCP_CDMAHP_PERF_CTRL_REG_TIMEOUT_CNT_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_PERF_CTRL_REG_TIMEOUT_CNT_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_PERF_CTRL_REG_RESETVAL (0x00200000u)

/* EMU_CTRL_REG */

#define CSL_BCP_CDMAHP_EMU_CTRL_REG_LOOPBACK_EN_MASK (0x80000000u)
#define CSL_BCP_CDMAHP_EMU_CTRL_REG_LOOPBACK_EN_SHIFT (0x0000001Fu)
#define CSL_BCP_CDMAHP_EMU_CTRL_REG_LOOPBACK_EN_RESETVAL (0x00000001u)

#define CSL_BCP_CDMAHP_EMU_CTRL_REG_SOFT_MASK (0x00000002u)
#define CSL_BCP_CDMAHP_EMU_CTRL_REG_SOFT_SHIFT (0x00000001u)
#define CSL_BCP_CDMAHP_EMU_CTRL_REG_SOFT_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_EMU_CTRL_REG_FREE_MASK (0x00000001u)
#define CSL_BCP_CDMAHP_EMU_CTRL_REG_FREE_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_EMU_CTRL_REG_FREE_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_EMU_CTRL_REG_RESETVAL (0x80000000u)

/* PRI_CTRL_REG */

#define CSL_BCP_CDMAHP_PRI_CTRL_REG_RX_PRIORITY_MASK (0x00070000u)
#define CSL_BCP_CDMAHP_PRI_CTRL_REG_RX_PRIORITY_SHIFT (0x00000010u)
#define CSL_BCP_CDMAHP_PRI_CTRL_REG_RX_PRIORITY_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_PRI_CTRL_REG_TX_PRIORITY_MASK (0x00000007u)
#define CSL_BCP_CDMAHP_PRI_CTRL_REG_TX_PRIORITY_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_PRI_CTRL_REG_TX_PRIORITY_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_PRI_CTRL_REG_RESETVAL (0x00000000u)

/* QM0_BA_REG */

#define CSL_BCP_CDMAHP_QM0_BA_REG_QM0_BASE_MASK (0xFFFFFFFFu)
#define CSL_BCP_CDMAHP_QM0_BA_REG_QM0_BASE_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_QM0_BA_REG_QM0_BASE_RESETVAL (0x34020000u)

#define CSL_BCP_CDMAHP_QM0_BA_REG_RESETVAL (0x34020000u)

/* QM1_BA_REG */

#define CSL_BCP_CDMAHP_QM1_BA_REG_QM1_BASE_MASK (0xFFFFFFFFu)
#define CSL_BCP_CDMAHP_QM1_BA_REG_QM1_BASE_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_QM1_BA_REG_QM1_BASE_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_QM1_BA_REG_RESETVAL (0x00000000u)

/* QM2_BA_REG */

#define CSL_BCP_CDMAHP_QM2_BA_REG_QM2_BASE_MASK (0xFFFFFFFFu)
#define CSL_BCP_CDMAHP_QM2_BA_REG_QM2_BASE_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_QM2_BA_REG_QM2_BASE_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_QM2_BA_REG_RESETVAL (0x00000000u)

/* QM3_BA_REG */

#define CSL_BCP_CDMAHP_QM3_BA_REG_QM3_BASE_MASK (0xFFFFFFFFu)
#define CSL_BCP_CDMAHP_QM3_BA_REG_QM3_BASE_SHIFT (0x00000000u)
#define CSL_BCP_CDMAHP_QM3_BA_REG_QM3_BASE_RESETVAL (0x00000000u)

#define CSL_BCP_CDMAHP_QM3_BA_REG_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
