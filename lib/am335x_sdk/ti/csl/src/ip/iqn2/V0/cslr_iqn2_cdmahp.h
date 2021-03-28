/*
 *
 * Copyright (C) 2012-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/********************************************************************
* file: cslr_iqn2_cdmahp.h
*
* Brief: This file contains the Register Description for iqn2_cdmahp
*
*********************************************************************/
#ifndef CSLR_IQN2_CDMAHP_H_
#define CSLR_IQN2_CDMAHP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Minimum unit = 1 byte */

/**************************************************************************\
* Register Overlay Structure for PKTDMA General register group
\**************************************************************************/
typedef struct  {
    volatile Uint32 PKTDMA_REVISION_REG; /*  Revision Register contains the major and minor revisions for the module. */
    volatile Uint32 PKTDMA_PERF_CTRL_REG; /*  performance control register contains fields which can be used to adjust the performance of the CDMAHP in the system. */
    volatile Uint32 PKTDMA_EMU_CTRL_REG; /*  emulation control register is used to control the behavior of the DMA when the emususp input is asserted. */
    volatile Uint32 PKTDMA_PRI_CTRL_REG; /*  priority control register is used to control the priority of the transactions which the DMA generates on it's master interface. */
    volatile Uint32 PKTDMA_QM0_BA_REG; /*  register is used to provide a pointer to the base address to the Queues region of Queue Manager 0. */
    volatile Uint32 PKTDMA_QM1_BA_REG; /*  register is used to provide a pointer to the base address to the Queues region of Queue Manager 1. */
    volatile Uint32 PKTDMA_QM2_BA_REG; /*  register is used to provide a pointer to the base address to the Queues region of Queue Manager 2. */
    volatile Uint32 PKTDMA_QM3_BA_REG; /*  register is used to provide a pointer to the base address to the Queues region of Queue Manager 3. */
} CSL_Iqn2_cdmahpPktdma; /* PKTDMA register not in other groups. */

/**************************************************************************\
* Register Overlay Structure for PKTDMA TCHAN
\**************************************************************************/
typedef struct  {
    volatile Uint32 PKTDMA_TCHAN_GCFG_REG_A; /*  Tx Channel Configuration Register A contains real-time control and status information for the Tx DMA channel. The fields in this register can safely be changed while the channel is in operation. */
    volatile Uint32 PKTDMA_TCHAN_GCFG_REG_B; /*  Tx Channel Configuration Register B is used to initialize the default return queue information for the Tx DMA channel. This register may only be written when the channel is disabled (tx_enable is 0). */
    volatile Uint8 RSVD0[24];
} CSL_Iqn2_cdmahpPktdma_tchanRegs;

/**************************************************************************\
* Register Overlay Structure for PKTDMA RCHAN
\**************************************************************************/
typedef struct  {
    volatile Uint32 PKTDMA_RCHAN_GCFG_REG_A; /*  Rx Channel Configuration Register A contains real-time control and status information for the Rx DMA channel. The fields in this register can safely be changed while the channel is in operation. */
    volatile Uint8 RSVD0[28];
} CSL_Iqn2_cdmahpPktdma_rchanRegs;

/**************************************************************************\
* Register Overlay Structure for PKTDMA TCHAN_SCHED
\**************************************************************************/
typedef struct  {
    volatile Uint32 PKTDMA_TCHAN_SCHED_CFG_REG; /*  Tx Channel N Scheduler Configuration Register contains static configuration information which affects the conditions under which each channel will be given an opportunity to use the Tx DMA unit(s). The fields in this register are as follows: */
} CSL_Iqn2_cdmahpPktdma_tchan_schedRegs;

/**************************************************************************\
* Register Overlay Structure for PKTDMA RFLOW
\**************************************************************************/
typedef struct  {
    volatile Uint32 PKTDMA_RFLOW_CFG_REG_A; /*  Rx Flow N Configuration Register A contains static configuration information for the Rx DMA flow. The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled. The fields in this register are as follows: */
    volatile Uint32 PKTDMA_RFLOW_CFG_REG_B; /*  Rx Flow N Configuration Register B contains static configuration information for the Rx DMA flow. The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled. The fields in this register are as follows: */
    volatile Uint32 PKTDMA_RFLOW_CFG_REG_C; /*  Rx Flow N Configuration Register C contains static configuration information for the Rx DMA flow. The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled. The fields in this register are as follows: */
    volatile Uint32 PKTDMA_RFLOW_CFG_REG_D; /*  Rx Flow N Configuration Register D contains static configuration information for the Rx DMA flow. The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled. The fields in this register are as follows: */
    volatile Uint32 PKTDMA_RFLOW_CFG_REG_E; /*  Rx Flow N Configuration Register E contains static configuration information for the Rx DMA flow. The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled. The fields in this register are as follows: */
    volatile Uint32 PKTDMA_RFLOW_CFG_REG_F; /*  Rx Flow N Configuration Register F contains static configuration information for the Rx DMA flow. The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled. This register is OPTIONAL. The fields in this register are as follows: */
    volatile Uint32 PKTDMA_RFLOW_CFG_REG_G; /*  Rx Flow N Configuration Register G contains static configuration information for the Rx DMA flow. The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled. This register is OPTIONAL. The fields in this register are as follows: */
    volatile Uint32 PKTDMA_RFLOW_CFG_REG_H; /*  Rx Flow N Configuration Register H contains static configuration information for the Rx DMA flow. The fields in this register can only be changed when all of the DMA channels that use this flow have been disabled. This register is OPTIONAL. The fields in this register are as follows: */
} CSL_Iqn2_cdmahpPktdma_rflowRegs;

/**************************************************************************\
* Register Overlay Structure
\**************************************************************************/
typedef struct  {
    CSL_Iqn2_cdmahpPktdma PKTDMA_GENERAL;
    volatile Uint8 RSVD0[8160];
    CSL_Iqn2_cdmahpPktdma_tchanRegs PKTDMA_TCHAN[48];
    volatile Uint8 RSVD1[6656];
    CSL_Iqn2_cdmahpPktdma_rchanRegs PKTDMA_RCHAN[48];
    volatile Uint8 RSVD2[6656];
    CSL_Iqn2_cdmahpPktdma_tchan_schedRegs PKTDMA_TCHAN_SCHED[48];
    volatile Uint8 RSVD3[8000];
    CSL_Iqn2_cdmahpPktdma_rflowRegs PKTDMA_RFLOW[48];
/******************************************/
/*  TEMPORARY FIX: Manual addition till   */
/*  autogenerated file becomes available. */
    volatile Uint8 RSVD4[1014272];
/******************************************/
} CSL_Iqn2_cdmahpRegs;

/**************************************************************************\
* Field Definition Macros
\**************************************************************************/

/* pktdma_revision_reg */

#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAMODID_MASK (0xFFFF0000u)
#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAMODID_SHIFT (0x00000010u)
#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAMODID_RESETVAL (0x00004E5Au)

#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAREVRTL_MASK (0x0000F800u)
#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAREVRTL_SHIFT (0x0000000Bu)
#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAREVRTL_RESETVAL (0x0000001Au)

#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAREVMAJ_MASK (0x00000700u)
#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAREVMAJ_SHIFT (0x00000008u)
#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAREVMAJ_RESETVAL (0x00000001u)

#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMACUSTOM_MASK (0x000000C0u)
#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMACUSTOM_SHIFT (0x00000006u)
#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMACUSTOM_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAREVMIN_MASK (0x0000003Fu)
#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAREVMIN_SHIFT (0x00000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_PKTDMAREVMIN_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_REVISION_REG_RESETVAL (0x4E5AD100u)

/* pktdma_perf_ctrl_reg */

#define CSL_IQN2_CDMAHP_PKTDMA_PERF_CTRL_REG_PKTDMAWARB_FIFO_DEPTH_MASK (0x003F0000u)
#define CSL_IQN2_CDMAHP_PKTDMA_PERF_CTRL_REG_PKTDMAWARB_FIFO_DEPTH_SHIFT (0x00000010u)
#define CSL_IQN2_CDMAHP_PKTDMA_PERF_CTRL_REG_PKTDMAWARB_FIFO_DEPTH_RESETVAL (0x00000020u)

#define CSL_IQN2_CDMAHP_PKTDMA_PERF_CTRL_REG_PKTDMATIMEOUT_CNT_MASK (0x0000FFFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_PERF_CTRL_REG_PKTDMATIMEOUT_CNT_SHIFT (0x00000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_PERF_CTRL_REG_PKTDMATIMEOUT_CNT_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_PERF_CTRL_REG_RESETVAL (0x00200000u)

/* pktdma_emu_ctrl_reg */

#define CSL_IQN2_CDMAHP_PKTDMA_EMU_CTRL_REG_PKTDMALOOPBACK_EN_MASK (0x80000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_EMU_CTRL_REG_PKTDMALOOPBACK_EN_SHIFT (0x0000001Fu)
#define CSL_IQN2_CDMAHP_PKTDMA_EMU_CTRL_REG_PKTDMALOOPBACK_EN_RESETVAL (0x00000001u)

#define CSL_IQN2_CDMAHP_PKTDMA_EMU_CTRL_REG_PKTDMASOFT_MASK (0x00000002u)
#define CSL_IQN2_CDMAHP_PKTDMA_EMU_CTRL_REG_PKTDMASOFT_SHIFT (0x00000001u)
#define CSL_IQN2_CDMAHP_PKTDMA_EMU_CTRL_REG_PKTDMASOFT_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_EMU_CTRL_REG_PKTDMAFREE_MASK (0x00000001u)
#define CSL_IQN2_CDMAHP_PKTDMA_EMU_CTRL_REG_PKTDMAFREE_SHIFT (0x00000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_EMU_CTRL_REG_PKTDMAFREE_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_EMU_CTRL_REG_RESETVAL (0x80000000u)

/* pktdma_pri_ctrl_reg */

#define CSL_IQN2_CDMAHP_PKTDMA_PRI_CTRL_REG_PKTDMARX_PRIORITY_MASK (0x00070000u)
#define CSL_IQN2_CDMAHP_PKTDMA_PRI_CTRL_REG_PKTDMARX_PRIORITY_SHIFT (0x00000010u)
#define CSL_IQN2_CDMAHP_PKTDMA_PRI_CTRL_REG_PKTDMARX_PRIORITY_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_PRI_CTRL_REG_PKTDMATX_PRIORITY_MASK (0x00000007u)
#define CSL_IQN2_CDMAHP_PKTDMA_PRI_CTRL_REG_PKTDMATX_PRIORITY_SHIFT (0x00000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_PRI_CTRL_REG_PKTDMATX_PRIORITY_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_PRI_CTRL_REG_RESETVAL (0x00000000u)

/* pktdma_qm0_ba_reg */

#define CSL_IQN2_CDMAHP_PKTDMA_QM0_BA_REG_PKTDMAQM0_BASE_MASK (0xFFFFFFFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_QM0_BA_REG_PKTDMAQM0_BASE_SHIFT (0x00000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_QM0_BA_REG_PKTDMAQM0_BASE_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_QM0_BA_REG_RESETVAL (0x00000000u)

/* pktdma_qm1_ba_reg */

#define CSL_IQN2_CDMAHP_PKTDMA_QM1_BA_REG_PKTDMAQM1_BASE_MASK (0xFFFFFFFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_QM1_BA_REG_PKTDMAQM1_BASE_SHIFT (0x00000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_QM1_BA_REG_PKTDMAQM1_BASE_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_QM1_BA_REG_RESETVAL (0x00000000u)

/* pktdma_qm2_ba_reg */

#define CSL_IQN2_CDMAHP_PKTDMA_QM2_BA_REG_PKTDMAQM2_BASE_MASK (0xFFFFFFFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_QM2_BA_REG_PKTDMAQM2_BASE_SHIFT (0x00000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_QM2_BA_REG_PKTDMAQM2_BASE_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_QM2_BA_REG_RESETVAL (0x00000000u)

/* pktdma_qm3_ba_reg */

#define CSL_IQN2_CDMAHP_PKTDMA_QM3_BA_REG_PKTDMAQM3_BASE_MASK (0xFFFFFFFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_QM3_BA_REG_PKTDMAQM3_BASE_SHIFT (0x00000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_QM3_BA_REG_PKTDMAQM3_BASE_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_QM3_BA_REG_RESETVAL (0x00000000u)

/* pktdma_tchan_gcfg_reg_a */

#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_A_PKTDMATX_ENABLE_MASK (0x80000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_A_PKTDMATX_ENABLE_SHIFT (0x0000001Fu)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_A_PKTDMATX_ENABLE_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_A_PKTDMATX_TEARDOWN_MASK (0x40000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_A_PKTDMATX_TEARDOWN_SHIFT (0x0000001Eu)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_A_PKTDMATX_TEARDOWN_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_A_PKTDMATX_PAUSE_MASK (0x20000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_A_PKTDMATX_PAUSE_SHIFT (0x0000001Du)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_A_PKTDMATX_PAUSE_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_A_RESETVAL (0x00000000u)

/* pktdma_tchan_gcfg_reg_b */

#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_B_PKTDMATX_FILT_EINFO_MASK (0x40000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_B_PKTDMATX_FILT_EINFO_SHIFT (0x0000001Eu)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_B_PKTDMATX_FILT_EINFO_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_B_PKTDMATX_FILT_PSWORDS_MASK (0x20000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_B_PKTDMATX_FILT_PSWORDS_SHIFT (0x0000001Du)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_B_PKTDMATX_FILT_PSWORDS_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_B_PKTDMATX_AIF_MONO_MODE_MASK (0x01000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_B_PKTDMATX_AIF_MONO_MODE_SHIFT (0x00000018u)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_B_PKTDMATX_AIF_MONO_MODE_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_GCFG_REG_B_RESETVAL (0x00000000u)

/* pktdma_rchan_gcfg_reg_a */

#define CSL_IQN2_CDMAHP_PKTDMA_RCHAN_GCFG_REG_A_PKTDMARX_ENABLE_MASK (0x80000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RCHAN_GCFG_REG_A_PKTDMARX_ENABLE_SHIFT (0x0000001Fu)
#define CSL_IQN2_CDMAHP_PKTDMA_RCHAN_GCFG_REG_A_PKTDMARX_ENABLE_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RCHAN_GCFG_REG_A_PKTDMARX_TEARDOWN_MASK (0x40000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RCHAN_GCFG_REG_A_PKTDMARX_TEARDOWN_SHIFT (0x0000001Eu)
#define CSL_IQN2_CDMAHP_PKTDMA_RCHAN_GCFG_REG_A_PKTDMARX_TEARDOWN_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RCHAN_GCFG_REG_A_PKTDMARX_PAUSE_MASK (0x20000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RCHAN_GCFG_REG_A_PKTDMARX_PAUSE_SHIFT (0x0000001Du)
#define CSL_IQN2_CDMAHP_PKTDMA_RCHAN_GCFG_REG_A_PKTDMARX_PAUSE_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RCHAN_GCFG_REG_A_RESETVAL (0x00000000u)

/* pktdma_tchan_sched_cfg_reg */

#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_SCHED_CFG_REG_PKTDMAPRIORITY_MASK (0x00000003u)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_SCHED_CFG_REG_PKTDMAPRIORITY_SHIFT (0x00000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_SCHED_CFG_REG_PKTDMAPRIORITY_RESETVAL (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_TCHAN_SCHED_CFG_REG_RESETVAL (0x00000000u)

/* pktdma_rflow_cfg_reg_a */

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_EINFO_PRESENT_MASK (0x40000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_EINFO_PRESENT_SHIFT (0x0000001Eu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_PSINFO_PRESENT_MASK (0x20000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_PSINFO_PRESENT_SHIFT (0x0000001Du)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_ERROR_HANDLING_MASK (0x10000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_ERROR_HANDLING_SHIFT (0x0000001Cu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_DESC_TYPE_MASK (0x0C000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_DESC_TYPE_SHIFT (0x0000001Au)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_PS_LOCATION_MASK (0x02000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_PS_LOCATION_SHIFT (0x00000019u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_SOP_OFFSET_MASK (0x01FF0000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_SOP_OFFSET_SHIFT (0x00000010u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_DEST_QMGR_MASK (0x00003000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_DEST_QMGR_SHIFT (0x0000000Cu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_DEST_QNUM_MASK (0x00000FFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_PKTDMARX_DEST_QNUM_SHIFT (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_A_RESETVAL (0x00000000u)

/* pktdma_rflow_cfg_reg_b */

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_B_PKTDMARX_SRC_TAG_HI_MASK (0xFF000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_B_PKTDMARX_SRC_TAG_HI_SHIFT (0x00000018u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_B_PKTDMARX_SRC_TAG_LO_MASK (0x00FF0000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_B_PKTDMARX_SRC_TAG_LO_SHIFT (0x00000010u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_B_PKTDMARX_DEST_TAG_HI_MASK (0x0000FF00u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_B_PKTDMARX_DEST_TAG_HI_SHIFT (0x00000008u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_B_PKTDMARX_DEST_TAG_LO_MASK (0x000000FFu)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_B_PKTDMARX_DEST_TAG_LO_SHIFT (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_B_RESETVAL (0x00000000u)

/* pktdma_rflow_cfg_reg_c */

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_PKTDMARX_SRC_TAG_HI_SEL_MASK (0x70000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_PKTDMARX_SRC_TAG_HI_SEL_SHIFT (0x0000001Cu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_PKTDMARX_SRC_TAG_LO_SEL_MASK (0x07000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_PKTDMARX_SRC_TAG_LO_SEL_SHIFT (0x00000018u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_PKTDMARX_DEST_TAG_HI_SEL_MASK (0x00700000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_PKTDMARX_DEST_TAG_HI_SEL_SHIFT (0x00000014u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_PKTDMARX_DEST_TAG_LO_SEL_MASK (0x00070000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_PKTDMARX_DEST_TAG_LO_SEL_SHIFT (0x00000010u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_PKTDMARX_SIZE_THRESH_EN_MASK (0x0000000Fu)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_PKTDMARX_SIZE_THRESH_EN_SHIFT (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_C_RESETVAL (0x00000000u)

/* pktdma_rflow_cfg_reg_d */

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_D_PKTDMARX_FDQ0_SZ0_QMGR_MASK (0x30000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_D_PKTDMARX_FDQ0_SZ0_QMGR_SHIFT (0x0000001Cu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_D_PKTDMARX_FDQ0_SZ0_QNUM_MASK (0x0FFF0000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_D_PKTDMARX_FDQ0_SZ0_QNUM_SHIFT (0x00000010u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_D_PKTDMARX_FDQ1_QMGR_MASK (0x00003000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_D_PKTDMARX_FDQ1_QMGR_SHIFT (0x0000000Cu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_D_PKTDMARX_FDQ1_QNUM_MASK (0x00000FFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_D_PKTDMARX_FDQ1_QNUM_SHIFT (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_D_RESETVAL (0x00000000u)

/* pktdma_rflow_cfg_reg_e */

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_E_PKTDMARX_FDQ2_QMGR_MASK (0x30000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_E_PKTDMARX_FDQ2_QMGR_SHIFT (0x0000001Cu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_E_PKTDMARX_FDQ2_QNUM_MASK (0x0FFF0000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_E_PKTDMARX_FDQ2_QNUM_SHIFT (0x00000010u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_E_PKTDMARX_FDQ3_QMGR_MASK (0x00003000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_E_PKTDMARX_FDQ3_QMGR_SHIFT (0x0000000Cu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_E_PKTDMARX_FDQ3_QNUM_MASK (0x00000FFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_E_PKTDMARX_FDQ3_QNUM_SHIFT (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_E_RESETVAL (0x00000000u)

/* pktdma_rflow_cfg_reg_f */

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_F_PKTDMARX_SIZE_THRESH0_MASK (0xFFFF0000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_F_PKTDMARX_SIZE_THRESH0_SHIFT (0x00000010u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_F_PKTDMARX_SIZE_THRESH1_MASK (0x0000FFFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_F_PKTDMARX_SIZE_THRESH1_SHIFT (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_F_RESETVAL (0x00000000u)

/* pktdma_rflow_cfg_reg_g */

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_G_PKTDMARX_SIZE_THRESH2_MASK (0xFFFF0000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_G_PKTDMARX_SIZE_THRESH2_SHIFT (0x00000010u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_G_PKTDMARX_FDQ0_SZ1_QMGR_MASK (0x00003000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_G_PKTDMARX_FDQ0_SZ1_QMGR_SHIFT (0x0000000Cu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_G_PKTDMARX_FDQ0_SZ1_QNUM_MASK (0x00000FFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_G_PKTDMARX_FDQ0_SZ1_QNUM_SHIFT (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_G_RESETVAL (0x00000000u)

/* pktdma_rflow_cfg_reg_h */

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_H_PKTDMARX_FDQ0_SZ2_QMGR_MASK (0x30000000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_H_PKTDMARX_FDQ0_SZ2_QMGR_SHIFT (0x0000001Cu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_H_PKTDMARX_FDQ0_SZ2_QNUM_MASK (0x0FFF0000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_H_PKTDMARX_FDQ0_SZ2_QNUM_SHIFT (0x00000010u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_H_PKTDMARX_FDQ0_SZ3_QMGR_MASK (0x00003000u)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_H_PKTDMARX_FDQ0_SZ3_QMGR_SHIFT (0x0000000Cu)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_H_PKTDMARX_FDQ0_SZ3_QNUM_MASK (0x00000FFFu)
#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_H_PKTDMARX_FDQ0_SZ3_QNUM_SHIFT (0x00000000u)

#define CSL_IQN2_CDMAHP_PKTDMA_RFLOW_CFG_REG_H_RESETVAL (0x00000000u)


#ifdef __cplusplus
}
#endif

#endif
