/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_HYDRA2_H_
#define CSLR_HYDRA2_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for ALL
**************************************************************************/
typedef struct {
    volatile Uint32 EUR_CR_MASTER_CORE;
    volatile Uint32 EUR_CR_MASTER_CLKGATECTL;
    volatile Uint32 EUR_CR_MASTER_CLKGATESTATUS;
    volatile Uint32 EUR_CR_MASTER_CLKGATECTLOVR;
    volatile Uint32 EUR_CR_MASTER_CORE_ID;
    volatile Uint32 EUR_CR_MASTER_CORE_REVISION;
    volatile Uint32 EUR_CR_MASTER_DESIGNER_REV_FIELD1;
    volatile Uint32 EUR_CR_MASTER_DESIGNER_REV_FIELD2;
    volatile Uint32 EUR_CR_MASTER_CLKGATECTL2;
    volatile Uint32 EUR_CR_MASTER_CLKGATESTATUS2;
    volatile Uint32 EUR_CR_MASTER_CLKGATECTLOVR2;
    volatile Uint8  RSVD0[84];
    volatile Uint32 EUR_CR_MASTER_SOFT_RESET;
    volatile Uint8  RSVD1[12];
    volatile Uint32 EUR_CR_MASTER_DEBUG;
    volatile Uint8  RSVD2[124];
    volatile Uint32 EUR_CR_MASTER_EVENT_HOST_ENABLE2;
    volatile Uint32 EUR_CR_MASTER_EVENT_HOST_CLEAR2;
    volatile Uint32 EUR_CR_MASTER_EVENT_STATUS2;
    volatile Uint8  RSVD3[16];
    volatile Uint32 EUR_CR_MASTER_EVENT_STATUS;
    volatile Uint32 EUR_CR_MASTER_EVENT_HOST_ENABLE;
    volatile Uint32 EUR_CR_MASTER_EVENT_HOST_CLEAR;
    volatile Uint32 EUR_CR_MASTER_PDS_CACHE_STATUS;
    volatile Uint32 EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE;
    volatile Uint32 EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR;
    volatile Uint32 EUR_CR_MASTER_MP_PRIMITIVE;
    volatile Uint32 EUR_CR_MASTER_MP_PRIMITIVE_CG;
    volatile Uint32 EUR_CR_MASTER_MP_TILE;
    volatile Uint8  RSVD4[36];
    volatile Uint32 EUR_CR_MASTER_PTLA_MEMORY_THROTTLE;
    volatile Uint32 EUR_CR_MASTER_PTLA_STATUS;
    volatile Uint32 EUR_CR_MASTER_PTLA_REQUEST;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_00;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_01;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_02;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_03;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_04;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_05;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_06;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_07;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_08;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_09;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_10;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_11;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_12;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_13;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_14;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_15;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_16;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_17;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_18;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_19;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_20;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_21;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_22;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_23;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_24;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_25;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_26;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_27;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_28;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_29;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_30;
    volatile Uint32 EUR_CR_MASTER_PTLA_SLAVE_CMD_31;
    volatile Uint32 EUR_CR_MASTER_VDM_START;
    volatile Uint32 EUR_CR_MASTER_TE_AA;
    volatile Uint8  RSVD5[12];
    volatile Uint32 EUR_CR_MASTER_TE_MTILE;
    volatile Uint8  RSVD6[32];
    volatile Uint32 EUR_CR_MASTER_VDM_CTRL_STREAM_BASE;
    volatile Uint8  RSVD7[28];
    volatile Uint32 EUR_CR_MASTER_MTE_FIRST_PAGE;
    volatile Uint32 EUR_CR_MASTER_MTE_SECOND_PAGE;
    volatile Uint8  RSVD8[32];
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_STORE_SNAPSHOT;
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_LOAD_START;
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS;
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_CLEAR;
    volatile Uint32 EUR_CR_MASTER_VDM_TASK_KICK;
    volatile Uint32 EUR_CR_MASTER_VDM_TASK_KICK_STATUS;
    volatile Uint32 EUR_CR_MASTER_VDM_TASK_KICK_STATUS_CLEAR;
    volatile Uint8  RSVD9[132];
    volatile Uint32 EUR_CR_MASTER_VDM_BATCH_NUM;
    volatile Uint32 EUR_CR_MASTER_VDM_BATCH_NUM_STATUS;
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD0;
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD1;
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_STORE_START;
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_STORE_STREAM;
    volatile Uint8  RSVD10[4];
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS;
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0;
    volatile Uint32 EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1;
    volatile Uint32 EUR_CR_MASTER_VDM_WAIT_FOR_KICK;
    volatile Uint8  RSVD11[16];
    volatile Uint32 EUR_CR_MASTER_VDM_PIM;
    volatile Uint32 EUR_CR_MASTER_VDM_PIM_STATUS;
    volatile Uint32 EUR_CR_MASTER_VDM_PIM_MAX;
    volatile Uint32 EUR_CR_MASTER_DPM_TASK_DPLIST;
    volatile Uint32 EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT;
    volatile Uint32 EUR_CR_MASTER_VDM_CORE;
    volatile Uint8  RSVD12[24];
    volatile Uint32 EUR_CR_MASTER_VDM_FENCE;
    volatile Uint32 EUR_CR_MASTER_VDM_FENCE_STATUS;
    volatile Uint8  RSVD13[104];
    volatile Uint32 EUR_CR_MASTER_ISP_STATUS;
    volatile Uint32 EUR_CR_MASTER_ISP_RENDER;
    volatile Uint32 EUR_CR_MASTER_ISP_RGN_BASE;
    volatile Uint32 EUR_CR_MASTER_ISP_RENDBOX1;
    volatile Uint32 EUR_CR_MASTER_ISP_RENDBOX2;
    volatile Uint8  RSVD14[20];
    volatile Uint32 EUR_CR_MASTER_ISP_START_RENDER;
    volatile Uint32 EUR_CR_MASTER_THREED_AA_MODE;
    volatile Uint32 EUR_CR_MASTER_ISP_BREAK;
    volatile Uint32 EUR_CR_MASTER_ISP_3DCONTEXT;
    volatile Uint8  RSVD15[216];
    volatile Uint32 EUR_CR_MASTER_ISP_RGN_BASE1;
    volatile Uint32 EUR_CR_MASTER_ISP_RGN_BASE2;
    volatile Uint32 EUR_CR_MASTER_ISP_RGN_BASE3;
    volatile Uint32 EUR_CR_MASTER_ISP_RGN;
    volatile Uint8  RSVD16[64];
    volatile Uint32 EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME4;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME4;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME4;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME4;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8;
    volatile Uint32 EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9;
    volatile Uint8  RSVD17[48];
    volatile Uint32 EUR_CR_MASTER_DPM_3D_PAGE_TABLE_BASE;
    volatile Uint32 EUR_CR_MASTER_DPM_3D_FREE_LIST;
    volatile Uint8  RSVD18[12];
    volatile Uint32 EUR_CR_MASTER_DPM_PDS_PAGE_THRESHOLD;
    volatile Uint32 EUR_CR_MASTER_DPM_TA_ALLOC_PAGE_TABLE_BASE;
    volatile Uint32 EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST;
    volatile Uint32 EUR_CR_MASTER_DPM_TA_PAGE_THRESHOLD;
    volatile Uint32 EUR_CR_MASTER_DPM_ZLS_PAGE_THRESHOLD;
    volatile Uint32 EUR_CR_MASTER_DPM_TA_GLOBAL_LIST;
    volatile Uint32 EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT0_BASE;
    volatile Uint32 EUR_CR_MASTER_DPM_STATE_CONTEXT_ID;
    volatile Uint8  RSVD19[4];
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED;
    volatile Uint32 EUR_CR_MASTER_DPM_3D_DEALLOCATE;
    volatile Uint32 EUR_CR_MASTER_DPM_ALLOC;
    volatile Uint32 EUR_CR_MASTER_DPM_DALLOC;
    volatile Uint32 EUR_CR_MASTER_DPM_TA_ALLOC;
    volatile Uint32 EUR_CR_MASTER_DPM_3D;
    volatile Uint8  RSVD20[8];
    volatile Uint32 EUR_CR_MASTER_DPM_PARTIAL_RENDER;
    volatile Uint32 EUR_CR_MASTER_DPM_LSS_PARTIAL_CONTEXT;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED;
    volatile Uint32 EUR_CR_MASTER_DPM_CONTEXT_PB_BASE;
    volatile Uint8  RSVD21[8];
    volatile Uint32 EUR_CR_MASTER_DPM_PAGE_MANAGEOP;
    volatile Uint32 EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT1_BASE;
    volatile Uint8  RSVD22[8];
    volatile Uint32 EUR_CR_MASTER_DPM_TASK_3D_FREE;
    volatile Uint32 EUR_CR_MASTER_DPM_TASK_TA_FREE;
    volatile Uint32 EUR_CR_MASTER_DPM_TASK_HOST_FREE;
    volatile Uint8  RSVD23[8];
    volatile Uint32 EUR_CR_MASTER_DPM_TASK_STATE;
    volatile Uint8  RSVD24[4];
    volatile Uint32 EUR_CR_MASTER_DPM_OUTOFMEM;
    volatile Uint32 EUR_CR_MASTER_DPM_FREE_CONTEXT;
    volatile Uint32 EUR_CR_MASTER_DPM_3D_TIMEOUT;
    volatile Uint32 EUR_CR_MASTER_DPM_TA_EVM;
    volatile Uint8  RSVD25[84];
    volatile Uint32 EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1;
    volatile Uint8  RSVD26[8];
    volatile Uint32 EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1;
    volatile Uint32 EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS2;
    volatile Uint8  RSVD27[8];
    volatile Uint32 EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS2;
    volatile Uint32 EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE;
    volatile Uint32 EUR_CR_MASTER_DPM_PAGE_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_PAGE;
    volatile Uint32 EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_GLOBAL_PAGE;
    volatile Uint32 EUR_CR_MASTER_DPM_REQUESTING;
    volatile Uint8  RSVD28[4];
    volatile Uint32 EUR_CR_MASTER_DPM_DPLIST_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_DPLIST_START_OF;
    volatile Uint32 EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_DRAIN_STATUS;
    volatile Uint8  RSVD29[4];
    volatile Uint32 EUR_CR_MASTER_DPM_PAGE_MANAGEOP_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_IDLE;
    volatile Uint32 EUR_CR_MASTER_DPM_DEBUG_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM0_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM1_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM2_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM3_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM4_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM5_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM6_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM7_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM8_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM9_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM10_STATUS;
    volatile Uint8  RSVD30[4];
    volatile Uint32 EUR_CR_MASTER_DPM_NCPIM11_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM0;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM1;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM2;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM3;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM4;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM5;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM6;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM7;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM8;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM9;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM10;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_NCPIM11;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM;
    volatile Uint32 EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC;
    volatile Uint32 EUR_CR_MASTER_DPM_MTILE_PARTI_PIM_TABLE_BASE_ADDR;
    volatile Uint32 EUR_CR_MASTER_DPM_PIMSHARE_RESERVE_PAGES;
    volatile Uint32 EUR_CR_MASTER_DPM_DRAIN_HEAP;
    volatile Uint32 EUR_CR_MASTER_DPM_DRAIN_HEAP_FREE;
    volatile Uint32 EUR_CR_MASTER_DPM_DRAIN;
    volatile Uint32 EUR_CR_MASTER_DPM_CONTEXT_DRAIN;
    volatile Uint32 EUR_CR_MASTER_MTE_FORCEREISSUE;
    volatile Uint32 EUR_CR_MASTER_DPM_MTILE_ABORTED;
    volatile Uint32 EUR_CR_MASTER_DPM_TSP0_MTILEFREE;
    volatile Uint32 EUR_CR_MASTER_DPM_TSP1_MTILEFREE;
    volatile Uint32 EUR_CR_MASTER_DPM_TSP2_MTILEFREE;
    volatile Uint32 EUR_CR_MASTER_DPM_TSP3_MTILEFREE;
    volatile Uint32 EUR_CR_MASTER_DPM_TSP0_START_OF_MTILEFREE;
    volatile Uint32 EUR_CR_MASTER_DPM_TSP1_START_OF_MTILEFREE;
    volatile Uint32 EUR_CR_MASTER_DPM_TSP2_START_OF_MTILEFREE;
    volatile Uint32 EUR_CR_MASTER_DPM_TSP3_START_OF_MTILEFREE;
    volatile Uint32 EUR_CR_MASTER_DPM_DEALLOCATE_MASK;
    volatile Uint32 EUR_CR_MASTER_DPM_START_OF_DEALLOCATE_MASK;
    volatile Uint8  RSVD31[180];
    volatile Uint32 EUR_CR_MASTER_CLIP_CHECKSUM;
    volatile Uint32 EUR_CR_MASTER_MTE_MEM_CHECKSUM;
    volatile Uint32 EUR_CR_MASTER_MTE_TE_CHECKSUM;
    volatile Uint32 EUR_CR_MASTER_TE_CHECKSUM;
    volatile Uint32 EUR_CR_MASTER_ISP_FPU_CHECKSUM;
    volatile Uint32 EUR_CR_MASTER_ISP_PRECALC_CHECKSUM;
    volatile Uint32 EUR_CR_MASTER_ISP_EDGE_CHECKSUM;
    volatile Uint32 EUR_CR_MASTER_ISP_TAGWRITE_CHECKSUM;
    volatile Uint32 EUR_CR_MASTER_ISP_SPAN_CHECKSUM;
    volatile Uint32 EUR_CR_MASTER_PBE_CHECKSUM;
    volatile Uint8  RSVD32[296];
    volatile Uint32 EUR_CR_MASTER_EVENT_PDS_ENABLE2;
    volatile Uint8  RSVD33[4];
    volatile Uint32 EUR_CR_MASTER_EVENT_PDS_ENABLE;
    volatile Uint8  RSVD34[420];
    volatile Uint32 EUR_CR_MASTER_BIF_CTRL;
    volatile Uint32 EUR_CR_MASTER_BIF_INT_STAT;
    volatile Uint32 EUR_CR_MASTER_BIF_FAULT;
    volatile Uint8  RSVD35[40];
    volatile Uint32 EUR_CR_MASTER_BIF_CTRL_INVAL;
    volatile Uint32 EUR_CR_MASTER_BIF_DIR_LIST_BASE1;
    volatile Uint32 EUR_CR_MASTER_BIF_DIR_LIST_BASE2;
    volatile Uint32 EUR_CR_MASTER_BIF_DIR_LIST_BASE3;
    volatile Uint32 EUR_CR_MASTER_BIF_DIR_LIST_BASE4;
    volatile Uint32 EUR_CR_MASTER_BIF_DIR_LIST_BASE5;
    volatile Uint32 EUR_CR_MASTER_BIF_DIR_LIST_BASE6;
    volatile Uint32 EUR_CR_MASTER_BIF_DIR_LIST_BASE7;
    volatile Uint8  RSVD36[32];
    volatile Uint32 EUR_CR_MASTER_BIF_BANK_SET;
    volatile Uint32 EUR_CR_MASTER_BIF_BANK0;
    volatile Uint32 EUR_CR_MASTER_BIF_BANK1;
    volatile Uint8  RSVD37[4];
    volatile Uint32 EUR_CR_MASTER_BIF_DIR_LIST_BASE0;
    volatile Uint8  RSVD38[32];
    volatile Uint32 EUR_CR_MASTER_BIF_MEM_REQ_STAT;
    volatile Uint32 EUR_CR_MASTER_BIF_3D_REQ_BASE;
    volatile Uint8  RSVD39[4];
    volatile Uint32 EUR_CR_MASTER_BIF_BANK_STATUS;
    volatile Uint8  RSVD40[24];
    volatile Uint32 EUR_CR_MASTER_BIF_MMU_CTRL;
    volatile Uint8  RSVD41[44];
    volatile Uint32 EUR_CR_MASTER_SLC_CTRL;
    volatile Uint32 EUR_CR_MASTER_SLC_CTRL_BYPASS;
    volatile Uint32 EUR_CR_MASTER_SLC_CTRL_USSE_INVAL;
    volatile Uint32 EUR_CR_MASTER_SLC_STATUS;
    volatile Uint32 EUR_CR_MASTER_SLC_EVENT_STATUS;
    volatile Uint32 EUR_CR_MASTER_SLC_EVENT_CLEAR;
    volatile Uint32 EUR_CR_MASTER_SLC_STATS0;
    volatile Uint32 EUR_CR_MASTER_SLC_STATS0_OUTPUT;
    volatile Uint32 EUR_CR_MASTER_SLC_STATS1;
    volatile Uint32 EUR_CR_MASTER_SLC_STATS1_OUTPUT;
    volatile Uint32 EUR_CR_MASTER_SLC_CTRL_INVAL;
    volatile Uint32 EUR_CR_MASTER_SLC_CTRL_FLUSH;
    volatile Uint32 EUR_CR_MASTER_SLC_STATUS2;
    volatile Uint32 EUR_CR_MASTER_SLC_CTRL_FLUSH_INV;
    volatile Uint8  RSVD42[328];
    volatile Uint32 EUR_CR_MASTER_EMU_CYCLE_COUNT;
    volatile Uint32 EUR_CR_MASTER_EMU_TA_PHASE;
    volatile Uint32 EUR_CR_MASTER_EMU_3D_PHASE;
    volatile Uint32 EUR_CR_MASTER_EMU_TA_CYCLE;
    volatile Uint32 EUR_CR_MASTER_EMU_3D_CYCLE;
    volatile Uint32 EUR_CR_MASTER_EMU_INITIAL_TA_CYCLE;
    volatile Uint32 EUR_CR_MASTER_EMU_FINAL_3D_CYCLE;
    volatile Uint8  RSVD43[24];
    volatile Uint32 EUR_CR_MASTER_EMU_MEM_READ;
    volatile Uint32 EUR_CR_MASTER_EMU_TA_OR_3D_CYCLE;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM_WRITE;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM_BYTE_WRITE;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM1_READ;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM1_WRITE;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM1_BYTE_WRITE;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM2_READ;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM2_WRITE;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM2_BYTE_WRITE;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM3_READ;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM3_WRITE;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM3_BYTE_WRITE;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT0_START;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT0_END;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT0;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT1_START;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT1_END;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT1;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT2_START;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT2_END;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT2;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT3_START;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT3_END;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT3;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT_READ;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT_TRAP;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT_TRAP_INFO0;
    volatile Uint32 EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1;
    volatile Uint8  RSVD44[4];
    volatile Uint32 EUR_CR_MASTER_EMU_MEM_STALLS;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM1_STALLS;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM2_STALLS;
    volatile Uint32 EUR_CR_MASTER_EMU_MEM3_STALLS;
    volatile Uint8  RSVD45[4];
} CSL_Hydra2Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Allows cores to be enabled or disabled. At least 1 core must always be
 * enabled. This register should not be programmed whilst the cores are
 * active. Once programmed individual SGX Cores may need to be reinitialised. */
#define CSL_HYDRA2_EUR_CR_MASTER_CORE                           (0x0U)

/* Core module clock gating controls: allows clocks to be forced off, forced
 * on or operate under automatic pipeline activity based clock gating. */
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL                     (0x4U)

/* Clock Gating Status reflects the condition of the clock gate controls for
 * each module. */
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS                  (0x8U)

/* Core module clock gating override controls: allows clocks to be enabled
 * temporarily for register writes by hosts. */
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR                  (0xCU)

/* Core ID Register */
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID                        (0x10U)

/* Core Revision Register identifies the specific core revision. */
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION                  (0x14U)

/* Designer Revision Field. The SOC designer can use this register for their
 * own revision control if required. */
#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD1            (0x18U)

/* Designer Revision Field The SOC designer can use this register for their
 * own revision control if required. */
#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD2            (0x1CU)

/* Soft reset control register which drives all modules except the register
 * bank. Write a '1' to reset and a '0' to clear Bits 31 : 10 are reserved */
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET                     (0x80U)

/* EUR_CR_MASTER_DEBUG */
#define CSL_HYDRA2_EUR_CR_MASTER_DEBUG                          (0x90U)

/* There are 2 sources of external interrupts in the PowerVR SGX core: General
 * system events and PDS cache invalidation events. The event status register
 * indicates the source of any general event interrupt generated by PowerVR
 * SGX. These events only result in an external interrupt if the relevant bit
 * in the EUR_CR_EVENT_HOST_ENABLE register is set. Note1: This register must
 * be combined with the EUR_CR_PDS_CACHE_STATUS register information to
 * determine what has caused the external interrupt. Note2: The host can write
 * to this register in which case any bits written as a '1' are ORed into the
 * register i.e. the host can cause the core to generate an interrupt. (This
 * is typically for debug purposes only) Note3: Due to the number of interrupt
 * sources in PowerVR SGX, it is not possible to fit all bits within one 32
 * bit register and therefore there is in addition to the main status, enable
 * and clear registers 3 further registers: EVENT_STATUS2, EVENT_ENABLE2 and
 * EVENT_CLEAR2 registers. These additional sources all contribute to the
 * master hardware interrupt signal contained in EVENT_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS                   (0x12CU)

/* EUR_CR_MASTER_EVENT_STATUS2 */
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2                  (0x118U)

/* This register enables interrupts. Writing a '1' to a bit field enables the
 * relevant Event. All the bit fields correspond exactly to those in the
 * EUR_CR_EVENT_STATUS register. The MASTER_INTERRUPT bit is a global enable
 * which overrides the Event enables, i.e. '1' - enable external interrupts,
 * '0' - disable external interrupts. */
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE              (0x130U)

/* This register enables interrupts. Writing a '1' to a bit field enables the
 * relevant Event. All the bit fields correspond exactly to those in the
 * EUR_CR_EVENT_STATUS2 register. The MASTER_INTERRUPT bit is a global enable
 * which overrides the Event enables, i.e. '1' - enable external interrupts,
 * '0' - disable external interrupts. */
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2             (0x110U)

/* This register is used to clear event interrupts. Writing a '1' to a bit
 * field clears the relevant Event. All the bit fields correspond exactly to
 * those in the EUR_CR_EVENT_STATUS register. */
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR               (0x134U)

/* This register is used to clear event interrupts. Writing a '1' to a bit
 * field clears the relevant Event. All the bit fields correspond exactly to
 * those in the EUR_CR_EVENT_STATUS2 register. */
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2              (0x114U)

/* There are 2 sources of external interrupts in the PowerVR SGX core: General
 * system events and PDS cache invalidation events. The PDS cache status
 * register indicates the source of any PDS cache invalidation event
 * interrupts generated by PowerVR SGX. These events only result in an
 * external interrupt if the relevant bit in the EUR_CR_PDS_CACHE_HOST_ENABLE
 * register is set. Note1: This register must be combined with the
 * EUR_CR_EVENT_STATUS register information to determine what has caused the
 * external interrupt. Note2: The host can write to this register in which
 * case any bits written as a '1' are ORed into the register i.e. the host can
 * cause the core to generate an interrupt. (This is typically for debug
 * purposes only) */
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS               (0x138U)

/* This register enables interrupts. Writing a '1' to a bit field enables the
 * relevant Event. All the bit fields correspond exactly to those in the
 * EUR_CR_PDS_CACHE_STATUS register. The MASTER_INTERRUPT bit contained in the
 * EUR_CR_EVENT_HOST_ENABLE register is a global enable which overrides the
 * Event enables, i.e. '1' - enable external interrupts, '0' - disable
 * external interrupts. */
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE          (0x13CU)

/* This register is used to clear event interrupts. Writing a '1' to a bit
 * field clears the relevant Event. All the bit fields correspond exactly to
 * those in the EUR_CR_PDS_CACHE_STATUS register. */
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR           (0x140U)

/* The TA context(reissue side) is drained out to memory on a context switch
 * and restored on a resume. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS       (0x744U)

/* A write to this register cause the dpm drained/resumed register clear */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_STATUS               (0x748U)

/* EUR_CR_MASTER_CLIP_CHECKSUM */
#define CSL_HYDRA2_EUR_CR_MASTER_CLIP_CHECKSUM                  (0x900U)

/* EUR_CR_MASTER_MTE_MEM_CHECKSUM */
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_MEM_CHECKSUM               (0x904U)

/* EUR_CR_MASTER_MTE_TE_CHECKSUM */
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_TE_CHECKSUM                (0x908U)

/* EUR_CR_MASTER_TE_CHECKSUM */
#define CSL_HYDRA2_EUR_CR_MASTER_TE_CHECKSUM                    (0x90CU)

/* EUR_CR_MASTER_ISP_FPU_CHECKSUM */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_FPU_CHECKSUM               (0x910U)

/* EUR_CR_MASTER_ISP_PRECALC_CHECKSUM */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_PRECALC_CHECKSUM           (0x914U)

/* EUR_CR_MASTER_ISP_EDGE_CHECKSUM */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_EDGE_CHECKSUM              (0x918U)

/* EUR_CR_MASTER_ISP_TAGWRITE_CHECKSUM */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_TAGWRITE_CHECKSUM          (0x91CU)

/* EUR_CR_MASTER_ISP_SPAN_CHECKSUM */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_SPAN_CHECKSUM              (0x920U)

/* EUR_CR_MASTER_PBE_CHECKSUM */
#define CSL_HYDRA2_EUR_CR_MASTER_PBE_CHECKSUM                   (0x924U)

/* Enables general event bits into the PDS event data master for processing by
 * the PDS Micro Controller */
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE               (0xA58U)

/* Enables general event bits into the PDS event data master for processing by
 * the PDS Micro Controller */
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2              (0xA50U)

/* PTLA Request counter */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE           (0x174U)

/* PTLA STATUS Register */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_STATUS                    (0x178U)

/* PTLA Request counter */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_REQUEST                   (0x17CU)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_00              (0x180U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_01              (0x184U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_02              (0x188U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_03              (0x18CU)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_04              (0x190U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_05              (0x194U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_06              (0x198U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_07              (0x19CU)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_08              (0x1A0U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_09              (0x1A4U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_10              (0x1A8U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_11              (0x1ACU)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_12              (0x1B0U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_13              (0x1B4U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_14              (0x1B8U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_15              (0x1BCU)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_16              (0x1C0U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_17              (0x1C4U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_18              (0x1C8U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_19              (0x1CCU)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_20              (0x1D0U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_21              (0x1D4U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_22              (0x1D8U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_23              (0x1DCU)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_24              (0x1E0U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_25              (0x1E4U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_26              (0x1E8U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_27              (0x1ECU)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_28              (0x1F0U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_29              (0x1F4U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_30              (0x1F8U)

/* PTLA Command Interface */
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_31              (0x1FCU)

/* Core module clock gating controls: allows clocks to be forced off, forced
 * on or operate under automatic pipeline activity based clock gating. */
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2                    (0x20U)

/* Clock Gating Status reflects the condition of the clock gate controls for
 * each module. */
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2                 (0x24U)

/* Core module clock gating override controls: allows clocks to be enabled
 * temporarily for register writes by hosts. */
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2                 (0x28U)

/* This register defines the MP mode for allocating vertex blocks, and the
 * threshold at which vertex blocks are split up. */
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE                   (0x144U)

/* This register defines the MP mode for allocating vertex blocks, and the
 * threshold at which vertex blocks are split up in complex geometry mode. */
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_CG                (0x148U)

/* EUR_CR_MASTER_MP_TILE */
#define CSL_HYDRA2_EUR_CR_MASTER_MP_TILE                        (0x14CU)

/* Any write to this register starts the Vertex Data Master DMA operation */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_START                      (0x200U)

/* This register controls the anti-aliasing mode of the Tiling Co-Processor,
 * independent control is provided in both X and Y axis. */
#define CSL_HYDRA2_EUR_CR_MASTER_TE_AA                          (0x204U)

/* This register defines the number of individual tiles within the macrotiles.
 * This is used in the process of memory allocation. */
#define CSL_HYDRA2_EUR_CR_MASTER_TE_MTILE                       (0x214U)

/* PowerVR SGX masters information from memory using advanced DMA, this
 * register defines the base address of the Vertex Data input control stream
 * in memory. */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CTRL_STREAM_BASE           (0x238U)

/* EUR_CR_MASTER_MTE_FIRST_PAGE */
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE                 (0x258U)

/* EUR_CR_MASTER_MTE_SECOND_PAGE */
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_SECOND_PAGE                (0x25CU)

/* This register defines the base address in memory of the snapshot buffer for
 * the VDM context store. This buffer store the information of the VDM
 * pipeline. For the moment, the buffer is 4K bytes size */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_SNAPSHOT     (0x280U)

/* Any write to this register starts the Vertex Data Master Loading the
 * pipeline status from the snapshot buffer */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_START         (0x284U)

/* EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS        (0x288U)

/* EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_CLEAR */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_CLEAR  (0x28CU)

/* Any write to this register starts the Vertex Data Master sending a task to
 * the vertex pipeline which is configured by the
 * eur_cr_vdm_context_store_state* register */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK                  (0x290U)

/* EUR_CR_MASTER_VDM_TASK_KICK_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS           (0x294U)

/* EUR_CR_MASTER_VDM_TASK_KICK_STATUS_CLEAR */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_CLEAR     (0x298U)

/* Controls Master VDM BATCH_NUM value */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM                  (0x320U)

/* Reports Master VDM BATCH_NUM status */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_STATUS           (0x324U)

/* Generic Control Word 0 to be optionally loaded with context switching tasks */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD0  (0x328U)

/* Generic Control Word 1 to be optionally loaded with context switching tasks */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD1  (0x32CU)

/* Start VDM Context store, pulse kicks off the store operation. Status flags
 * when this is complete and the stream and index position registers are valid */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_START        (0x330U)

/* Stores the stream position when the context store occured */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STREAM       (0x334U)

/* Signals when a context store is complete and the stream and index location
 * registers are valid */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS       (0x33CU)

/* Terminate state control registers used for creating the terminate PDS task. */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0       (0x340U)

/* Terminate state control registers used for creating the terminate PDS task. */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1       (0x344U)

/* Indicates the status on the control stream fetch */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_WAIT_FOR_KICK              (0x348U)

/* Controls Master VDM PIM value */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM                        (0x35CU)

/* Reports Master VDM PIM status */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS                 (0x360U)

/* The maximum value that the PIM can hold */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_MAX                    (0x364U)

/* EUR_CR_MASTER_DPM_TASK_DPLIST */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST                (0x368U)

/* EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS        (0x36CU)

/* EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT         (0x370U)

/* EUR_CR_MASTER_VDM_CORE */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CORE                       (0x374U)

/* Increment the VDM's fence count */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE                      (0x390U)

/* Reports the VDM's fence count */
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_STATUS               (0x394U)

/* Status bits for the Master IPF */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_STATUS                     (0x400U)

/* The Image Synthesis Processor can be configured to operate in 3 different
 * render modes */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER                     (0x404U)

/* This register defines the base address in memory of the Region Header reads
 * by the ISP. Region headers are the first part of the display list and
 * contain an entry per tile with information on global setup and a link
 * address to parameters. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE                   (0x408U)

/* When the render type is set to Fast 2D Render or Fast Scale Render, no
 * region headers are read from memory. Instead, region headers are internally
 * generated for all tiles enclosed in the bounding box defined by this
 * register and the EUR_CR_ISP_RENDBOX2 register. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX1                   (0x40CU)

/* When the render type is set to Fast 2D Render or Fast Scale Render, no
 * region headers are read from memory. Instead, region headers are internally
 * generated for all tiles enclosed in the bounding box defined by this
 * register and the EUR_CR_ISP_RENDBOX1 register. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX2                   (0x410U)

/* Any write to this register starts a 3D Render. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_START_RENDER               (0x428U)

/* Indicates to the 3D pipeline whether anti-aliasing is enabled or disabled */
#define CSL_HYDRA2_EUR_CR_MASTER_THREED_AA_MODE                 (0x42CU)

/* Object breakpoints can be inserted by the driver to interrupt a render part
 * way and then resume the render from the point of interrupt at a later time,
 * this register controls what happens when a breakpoint has been encountered. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_BREAK                      (0x430U)

/* EUR_CR_MASTER_ISP_3DCONTEXT */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_3DCONTEXT                  (0x434U)

/* This register defines the base address in memory of the Region Header reads
 * by the ISP. Region headers are the first part of the display list and
 * contain an entry per tile with information on global setup and a link
 * address to parameters. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE1                  (0x510U)

/* This register defines the base address in memory of the Region Header reads
 * by the ISP. Region headers are the first part of the display list and
 * contain an entry per tile with information on global setup and a link
 * address to parameters. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE2                  (0x514U)

/* This register defines the base address in memory of the Region Header reads
 * by the ISP. Region headers are the first part of the display list and
 * contain an entry per tile with information on global setup and a link
 * address to parameters. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE3                  (0x518U)

/* This register defines the size of the allocation used for Region Headers in
 * each of the cores, this is used by the Master IPF in order to read the
 * correct number of words from memory without the risk of over-fetching which
 * risks causing page faults. Region headers are the first part of the display
 * list and contain an entry per tile with information on global setup and a
 * link address to parameters. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN                        (0x51CU)

/* On resuming a given context the ISP2 needs to read back the flags that were
 * set when the context was stored off such that it knows the status of the
 * current tile. These flags will have been stored in memory and will be
 * identical to what was originally stored off with one exception, the
 * pt_in_flight register which is described later in more detail. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2      (0x560U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME4 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME4      (0x564U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5      (0x568U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6      (0x56CU)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7      (0x570U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8      (0x574U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9      (0x578U)

/* On resuming a given context the ISP2 needs to read back the flags that were
 * set when the context was stored off such that it knows the status of the
 * current tile. These flags will have been stored in memory and will be
 * identical to what was originally stored off with one exception, the
 * pt_in_flight register which is described later in more detail. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2      (0x57CU)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME4 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME4      (0x580U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5      (0x584U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6      (0x588U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7      (0x58CU)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8      (0x590U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9      (0x594U)

/* On resuming a given context the ISP2 needs to read back the flags that were
 * set when the context was stored off such that it knows the status of the
 * current tile. These flags will have been stored in memory and will be
 * identical to what was originally stored off with one exception, the
 * pt_in_flight register which is described later in more detail. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2      (0x598U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME4 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME4      (0x59CU)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5      (0x5A0U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6      (0x5A4U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7      (0x5A8U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8      (0x5ACU)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9      (0x5B0U)

/* On resuming a given context the ISP2 needs to read back the flags that were
 * set when the context was stored off such that it knows the status of the
 * current tile. These flags will have been stored in memory and will be
 * identical to what was originally stored off with one exception, the
 * pt_in_flight register which is described later in more detail. */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2      (0x5B4U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME4 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME4      (0x5B8U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5      (0x5BCU)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6      (0x5C0U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7      (0x5C4U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8      (0x5C8U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9 */
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9      (0x5CCU)

/* Effective on load 3D context, this register defines the base address of the
 * page table being referenced in the process of de-allocating pages during a
 * 3D render. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_PAGE_TABLE_BASE         (0x600U)

/* Between the FREE_LIST_HEAD and FREE_LIST_TAIL there must be a valid chain
 * of linked pages. The linked list is stored in memory, at the
 * EUR_CR_DPM_3D_PAGE_TABLE_BASE_ADDRESS and is effective on load 3D context. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST               (0x604U)

/* This is the threshold in 4KB pages at which the hardware will stop double
 * buffering the internal vertex processing buffers (and drop to single
 * buffered mode). This is required in order to guarantee that a 3D render can
 * run when running in dynamic parameter management mode. It should be set to
 * 0.25MB less (in pages 0x40) than the ZLS threshold (or 0 in very small
 * memory systems). */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PDS_PAGE_THRESHOLD         (0x614U)

/* Effective on Loading the TA Page Table Context, this register defines the
 * base address of the page table being referenced in the process of
 * allocating pages by the TE and MTE. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_PAGE_TABLE_BASE   (0x618U)

/* Between the FREE_LIST_HEAD and FREE_LIST_TAIL there must be a valid chain
 * of linked pages. The linked list is stored in memory, at the
 * EUR_CR_DPM_TA_ALLOC_PAGE_TABLE_BASE_ADDRESS and is effective on Loading the
 * TA Page Table Context. (Defined in 4K pages) */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST         (0x61CU)

/* EUR_CR_MASTER_DPM_TA_PAGE_THRESHOLD */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_PAGE_THRESHOLD          (0x620U)

/* EUR_CR_MASTER_DPM_ZLS_PAGE_THRESHOLD */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ZLS_PAGE_THRESHOLD         (0x624U)

/* EUR_CR_MASTER_DPM_TA_GLOBAL_LIST */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_GLOBAL_LIST             (0x628U)

/* Effective immediately, this register defines the base address of the state
 * table when it is read and written to/from memory. The state table itself
 * contains the head, tail and number of pages allocated to every macrotile,
 * and the global list. Each context needs a separate state page table. The
 * data is stored in memory in 64bit words with the following bit field
 * definitions: 63:48 Count of the number of pages allocated to the Zbuffer
 * for that macrotile 47:32 The tail of the allocated link list for that
 * macrotile 31:16 Count of number of pages (used to determine the busiest
 * macro tile) 15:0 The head of the allocated link list for that macrotile The
 * stride of the table data is 8 bytes (64 bits) */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT0_BASE  (0x62CU)

/* EUR_CR_MASTER_DPM_STATE_CONTEXT_ID */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID           (0x630U)

/* EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED  (0x638U)

/* EUR_CR_MASTER_DPM_3D_DEALLOCATE */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_DEALLOCATE              (0x63CU)

/* A write to this register invalidates the current contents and causes a new
 * allocation cycle */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC                      (0x640U)

/* A write to this register invalidates the current contents and causes a new
 * de-allocation cycle */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DALLOC                     (0x644U)

/* EUR_CR_MASTER_DPM_TA_ALLOC */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC                   (0x648U)

/* EUR_CR_MASTER_DPM_3D */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D                         (0x64CU)

/* EUR_CR_MASTER_DPM_PARTIAL_RENDER */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PARTIAL_RENDER             (0x658U)

/* EUR_CR_MASTER_DPM_LSS_PARTIAL_CONTEXT */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_LSS_PARTIAL_CONTEXT        (0x65CU)

/* EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED  (0x660U)

/* EUR_CR_MASTER_DPM_CONTEXT_PB_BASE */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_PB_BASE            (0x664U)

/* EUR_CR_MASTER_DPM_PAGE_MANAGEOP */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP              (0x670U)

/* Effective immediately, this register defines the base address of the state
 * table for context 0 when it is read and written to/from memory. The state
 * table itself contains the head, tail and number of pages allocated to every
 * macrotile, and the global list. Each context needs a separate state page
 * table. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT1_BASE  (0x674U)

/* EUR_CR_MASTER_DPM_TASK_3D_FREE */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_3D_FREE               (0x680U)

/* EUR_CR_MASTER_DPM_TASK_TA_FREE */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_TA_FREE               (0x684U)

/* EUR_CR_MASTER_DPM_TASK_HOST_FREE */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_HOST_FREE             (0x688U)

/* This register controls the DPM module task state for page tables. The
 * normal order of operation is Store context, Clear context, Load new
 * context. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE                 (0x694U)

/* EUR_CR_MASTER_DPM_OUTOFMEM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM                   (0x69CU)

/* EUR_CR_MASTER_DPM_FREE_CONTEXT */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_FREE_CONTEXT               (0x6A0U)

/* EUR_CR_MASTER_DPM_3D_TIMEOUT */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_TIMEOUT                 (0x6A4U)

/* EUR_CR_MASTER_DPM_TA_EVM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_EVM                     (0x6A8U)

/* This status register is read for a context switch. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1  (0x700U)

/* This status register is read for a context switch. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1       (0x70CU)

/* This status register is read for a context switch. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS2  (0x710U)

/* This status register is read for a context switch. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS2       (0x71CU)

/* This status register is read for a context switch. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE         (0x720U)

/* This status register is read for a context switch. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS                (0x724U)

/* This status register is read for a context switch. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE                       (0x728U)

/* This status register is read for a context switch. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS         (0x72CU)

/* This status register is read for a context switch. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE                (0x730U)

/* EUR_CR_MASTER_DPM_REQUESTING */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTING                 (0x734U)

/* EUR_CR_MASTER_DPM_DPLIST_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS              (0x73CU)

/* EUR_CR_MASTER_DPM_DPLIST_START_OF */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF            (0x740U)

/* EUR_CR_MASTER_DPM_PAGE_MANAGEOP_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_STATUS       (0x750U)

/* EUR_CR_MASTER_DPM_IDLE */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_IDLE                       (0x754U)

/* EUR_CR_MASTER_DPM_DEBUG_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS               (0x758U)

/* EUR_CR_MASTER_DPM_NCPIM0_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS              (0x75CU)

/* EUR_CR_MASTER_DPM_NCPIM1_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS              (0x760U)

/* EUR_CR_MASTER_DPM_NCPIM2_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS              (0x764U)

/* EUR_CR_MASTER_DPM_NCPIM3_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS              (0x768U)

/* EUR_CR_MASTER_DPM_NCPIM4_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS              (0x76CU)

/* EUR_CR_MASTER_DPM_NCPIM5_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS              (0x770U)

/* EUR_CR_MASTER_DPM_NCPIM6_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS              (0x774U)

/* EUR_CR_MASTER_DPM_NCPIM7_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS              (0x778U)

/* EUR_CR_MASTER_DPM_NCPIM8_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS              (0x77CU)

/* EUR_CR_MASTER_DPM_NCPIM9_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS              (0x780U)

/* EUR_CR_MASTER_DPM_NCPIM10_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS             (0x784U)

/* EUR_CR_MASTER_DPM_NCPIM11_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS             (0x78CU)

/* EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS      (0x790U)

/* EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS      (0x794U)

/* EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS      (0x798U)

/* EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS      (0x79CU)

/* EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS      (0x7A0U)

/* EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS      (0x7A4U)

/* EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS      (0x7A8U)

/* EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS      (0x7ACU)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM0 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0            (0x7B0U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM1 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1            (0x7B4U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM2 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2            (0x7B8U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM3 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3            (0x7BCU)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM4 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4            (0x7C0U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM5 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5            (0x7C4U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM6 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6            (0x7C8U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM7 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7            (0x7CCU)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM8 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8            (0x7D0U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM9 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9            (0x7D4U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM10 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10           (0x7D8U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM11 */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11           (0x7DCU)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM    (0x7E0U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM    (0x7E4U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM    (0x7E8U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM    (0x7ECU)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM    (0x7F0U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM    (0x7F4U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM    (0x7F8U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM    (0x7FCU)

/* EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC         (0x800U)

/* EUR_CR_MASTER_DPM_MTILE_PARTI_PIM_TABLE_BASE_ADDR */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_PARTI_PIM_TABLE_BASE_ADDR  (0x804U)

/* EUR_CR_MASTER_DPM_PIMSHARE_RESERVE_PAGES */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PIMSHARE_RESERVE_PAGES     (0x808U)

/* Between the HEAD and TAIL is a Circular Buffer.DPM will put the MTE data
 * into the drain buffer */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP                 (0x80CU)

/* Between the HEAD and TAIL is a Circular Buffer. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_FREE            (0x810U)

/* The TA context is drained out to memory on a context switch and restored on
 * a resume. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN                      (0x814U)

/* The TA context is drained out to memory on a context switch and restored on
 * a resume. */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN              (0x818U)

/* enable MTE could force dpm to reissue page outstanding in MTE */
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FORCEREISSUE               (0x81CU)

/* report the mtile has been aborted in the particular TA
 * context,load/store/clear at the standard display list load/store/clear */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_ABORTED              (0x820U)

/* report the mtile status TSP has requested which can be freed by DPM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_MTILEFREE             (0x824U)

/* report the mtile status TSP has requested which can be freed by DPM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_MTILEFREE             (0x828U)

/* report the mtile status TSP has requested which can be freed by DPM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_MTILEFREE             (0x82CU)

/* report the mtile status TSP has requested which can be freed by DPM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_MTILEFREE             (0x830U)

/* report the mtile status TSP has reported which can be freed by DPM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_START_OF_MTILEFREE    (0x834U)

/* report the mtile status TSP has reported which can be freed by DPM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_START_OF_MTILEFREE    (0x838U)

/* report the mtile status TSP has reported which can be freed by DPM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_START_OF_MTILEFREE    (0x83CU)

/* report the mtile status TSP has reported which can be freed by DPM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_START_OF_MTILEFREE    (0x840U)

/* report the mtile status TSP has reported which can be freed by DPM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEALLOCATE_MASK            (0x844U)

/* report the mtile status TSP has reported which can be freed by DPM */
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_DEALLOCATE_MASK   (0x848U)

/* EUR_CR_MASTER_BIF_CTRL */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL                       (0xC00U)

/* EUR_CR_MASTER_BIF_INT_STAT */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT                   (0xC04U)

/* EUR_CR_MASTER_BIF_FAULT */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT                      (0xC08U)

/* EUR_CR_MASTER_BIF_CTRL_INVAL */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_INVAL                 (0xC34U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE0 */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE0             (0xC84U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE1 */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE1             (0xC38U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE2 */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE2             (0xC3CU)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE3 */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE3             (0xC40U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE4 */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE4             (0xC44U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE5 */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE5             (0xC48U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE6 */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE6             (0xC4CU)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE7 */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE7             (0xC50U)

/* Sets which bank of directories defined by the EUR_CR_BIF_BANK0/1 registers
 * is selected per requestor group, this allows for double buffered operation.
 * The 3D request group can optionally toggle banks based on an
 * ISP_START_RENDER event. The TA request group can optionally toggle banks
 * based on a VDM_START event. */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET                   (0xC74U)

/* EUR_CR_MASTER_BIF_BANK0 */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0                      (0xC78U)

/* EUR_CR_MASTER_BIF_BANK1 */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK1                      (0xC7CU)

/* EUR_CR_MASTER_BIF_BANK_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_STATUS                (0xCB4U)

/* EUR_CR_MASTER_BIF_MEM_REQ_STAT */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MEM_REQ_STAT               (0xCA8U)

/* EUR_CR_MASTER_BIF_3D_REQ_BASE */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_3D_REQ_BASE                (0xCACU)

/* EUR_CR_MASTER_BIF_MMU_CTRL */
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL                   (0xCD0U)

/* EUR_CR_MASTER_SLC_CTRL */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL                       (0xD00U)

/* EUR_CR_MASTER_SLC_CTRL_BYPASS */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS                (0xD04U)

/* EUR_CR_MASTER_SLC_CTRL_USSE_INVAL */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL            (0xD08U)

/* EUR_CR_MASTER_SLC_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS                     (0xD0CU)

/* EUR_CR_MASTER_SLC_STATUS2 */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS2                    (0xD30U)

/* EUR_CR_MASTER_SLC_EVENT_STATUS */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS               (0xD10U)

/* EUR_CR_MASTER_SLC_EVENT_CLEAR */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR                (0xD14U)

/* EUR_CR_MASTER_SLC_STATS0 */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0                     (0xD18U)

/* EUR_CR_MASTER_SLC_STATS0_OUTPUT */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_OUTPUT              (0xD1CU)

/* EUR_CR_MASTER_SLC_STATS1 */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1                     (0xD20U)

/* EUR_CR_MASTER_SLC_STATS1_OUTPUT */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_OUTPUT              (0xD24U)

/* EUR_CR_MASTER_SLC_CTRL_INVAL */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL                 (0xD28U)

/* EUR_CR_MASTER_SLC_CTRL_FLUSH */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH                 (0xD2CU)

/* EUR_CR_MASTER_SLC_CTRL_FLUSH_INV */
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV             (0xD34U)

/* EUR_CR_MASTER_EMU_CYCLE_COUNT */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_CYCLE_COUNT                (0xE80U)

/* EUR_CR_MASTER_EMU_TA_PHASE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_PHASE                   (0xE84U)

/* EUR_CR_MASTER_EMU_3D_PHASE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_PHASE                   (0xE88U)

/* EUR_CR_MASTER_EMU_TA_CYCLE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_CYCLE                   (0xE8CU)

/* EUR_CR_MASTER_EMU_3D_CYCLE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_CYCLE                   (0xE90U)

/* EUR_CR_MASTER_EMU_INITIAL_TA_CYCLE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_INITIAL_TA_CYCLE           (0xE94U)

/* EUR_CR_MASTER_EMU_FINAL_3D_CYCLE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_FINAL_3D_CYCLE             (0xE98U)

/* EUR_CR_MASTER_EMU_MEM_READ */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_READ                   (0xEB4U)

/* EUR_CR_MASTER_EMU_TA_OR_3D_CYCLE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_OR_3D_CYCLE             (0xEB8U)

/* EUR_CR_MASTER_EMU_MEM_WRITE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_WRITE                  (0xEBCU)

/* EUR_CR_MASTER_EMU_MEM_BYTE_WRITE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_BYTE_WRITE             (0xEC0U)

/* EUR_CR_MASTER_EMU_MEM1_READ */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_READ                  (0xEC4U)

/* EUR_CR_MASTER_EMU_MEM1_WRITE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_WRITE                 (0xEC8U)

/* EUR_CR_MASTER_EMU_MEM1_BYTE_WRITE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_BYTE_WRITE            (0xECCU)

/* EUR_CR_MASTER_EMU_MEM2_READ */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_READ                  (0xED0U)

/* EUR_CR_MASTER_EMU_MEM2_WRITE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_WRITE                 (0xED4U)

/* EUR_CR_MASTER_EMU_MEM2_BYTE_WRITE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_BYTE_WRITE            (0xED8U)

/* EUR_CR_MASTER_EMU_MEM3_READ */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_READ                  (0xEDCU)

/* EUR_CR_MASTER_EMU_MEM3_WRITE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_WRITE                 (0xEE0U)

/* EUR_CR_MASTER_EMU_MEM3_BYTE_WRITE */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_BYTE_WRITE            (0xEE4U)

/* EUR_CR_MASTER_BREAKPOINT0_START */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_START              (0xEE8U)

/* EUR_CR_MASTER_BREAKPOINT0_END */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_END                (0xEECU)

/* EUR_CR_MASTER_BREAKPOINT0 */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0                    (0xEF0U)

/* EUR_CR_MASTER_BREAKPOINT1_START */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_START              (0xEF4U)

/* EUR_CR_MASTER_BREAKPOINT1_END */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_END                (0xEF8U)

/* EUR_CR_MASTER_BREAKPOINT1 */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1                    (0xEFCU)

/* EUR_CR_MASTER_BREAKPOINT2_START */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_START              (0xF00U)

/* EUR_CR_MASTER_BREAKPOINT2_END */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_END                (0xF04U)

/* EUR_CR_MASTER_BREAKPOINT2 */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2                    (0xF08U)

/* EUR_CR_MASTER_BREAKPOINT3_START */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_START              (0xF0CU)

/* EUR_CR_MASTER_BREAKPOINT3_END */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_END                (0xF10U)

/* EUR_CR_MASTER_BREAKPOINT3 */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3                    (0xF14U)

/* EUR_CR_MASTER_BREAKPOINT_READ */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_READ                (0xF18U)

/* EUR_CR_MASTER_BREAKPOINT_TRAP */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP                (0xF1CU)

/* EUR_CR_MASTER_BREAKPOINT */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT                     (0xF20U)

/* EUR_CR_MASTER_BREAKPOINT_TRAP_INFO0 */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO0          (0xF24U)

/* EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1 */
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1          (0xF28U)

/* EUR_CR_MASTER_EMU_MEM_STALLS */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_STALLS                 (0xF30U)

/* EUR_CR_MASTER_EMU_MEM1_STALLS */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_STALLS                (0xF34U)

/* EUR_CR_MASTER_EMU_MEM2_STALLS */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_STALLS                (0xF38U)

/* EUR_CR_MASTER_EMU_MEM3_STALLS */
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_STALLS                (0xF3CU)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* EUR_CR_MASTER_CORE */

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ENABLE_MASK               (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ENABLE_SHIFT              (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ENABLE_RESETVAL           (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ENABLE_MAX                (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_RESETVAL                  (0x00000003U)

/* EUR_CR_MASTER_CLKGATECTL */

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE3_CLKG_MASK     (0x000000C0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE3_CLKG_SHIFT    (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE3_CLKG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE3_CLKG_MAX      (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE2_CLKG_MASK     (0x00000030U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE2_CLKG_SHIFT    (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE2_CLKG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE2_CLKG_MAX      (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE1_CLKG_MASK     (0x0000000CU)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE1_CLKG_SHIFT    (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE1_CLKG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE1_CLKG_MAX      (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE0_CLKG_MASK     (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE0_CLKG_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE0_CLKG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_CORE0_CLKG_MAX      (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL_RESETVAL            (0x00000000U)

/* EUR_CR_MASTER_CLKGATESTATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE3_CLKS_MASK  (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE3_CLKS_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE3_CLKS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE3_CLKS_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE2_CLKS_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE2_CLKS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE2_CLKS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE2_CLKS_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE1_CLKS_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE1_CLKS_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE1_CLKS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE1_CLKS_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE0_CLKS_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE0_CLKS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE0_CLKS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_CORE0_CLKS_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_CLKGATECTLOVR */

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE3_CLKO_MASK  (0x000000C0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE3_CLKO_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE3_CLKO_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE3_CLKO_MAX   (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE2_CLKO_MASK  (0x00000030U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE2_CLKO_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE2_CLKO_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE2_CLKO_MAX   (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE1_CLKO_MASK  (0x0000000CU)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE1_CLKO_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE1_CLKO_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE1_CLKO_MAX   (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE0_CLKO_MASK  (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE0_CLKO_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE0_CLKO_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_CORE0_CLKO_MAX   (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_CORE_ID */

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_ID_MASK                (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_ID_SHIFT               (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_ID_RESETVAL            (0x00000119U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_ID_MAX                 (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_SLC_MASK        (0x0000F000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_SLC_SHIFT       (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_SLC_RESETVAL    (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_SLC_MAX         (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_CORES_MASK      (0x00000F00U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_CORES_SHIFT     (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_CORES_RESETVAL  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_CORES_MAX       (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_MASK            (0x000000FCU)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_SHIFT           (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_MAX             (0x0000003fU)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_BASE_MASK       (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_BASE_SHIFT      (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_BASE_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_BASE_MAX        (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_MULTI_MASK      (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_MULTI_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_MULTI_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_CONFIG_MULTI_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_ID_RESETVAL               (0x01191201U)

/* EUR_CR_MASTER_CORE_REVISION */

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_DESIGNER_MASK    (0xFF000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_DESIGNER_SHIFT   (24U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_DESIGNER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_DESIGNER_MAX     (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MAJOR_MASK       (0x00FF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MAJOR_SHIFT      (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MAJOR_RESETVAL   (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MAJOR_MAX        (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MINOR_MASK       (0x0000FF00U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MINOR_SHIFT      (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MINOR_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MINOR_MAX        (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MAINTENANCE_MASK  (0x000000FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MAINTENANCE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MAINTENANCE_RESETVAL  (0x00000005U)
#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_MAINTENANCE_MAX  (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_CORE_REVISION_RESETVAL         (0x00010005U)

/* EUR_CR_MASTER_DESIGNER_REV_FIELD1 */

#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD1_DESIGNER_REV_FIELD1_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD1_DESIGNER_REV_FIELD1_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD1_DESIGNER_REV_FIELD1_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD1_DESIGNER_REV_FIELD1_MAX  (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD1_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DESIGNER_REV_FIELD2 */

#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD2_DESIGNER_REV_FIELD2_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD2_DESIGNER_REV_FIELD2_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD2_DESIGNER_REV_FIELD2_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD2_DESIGNER_REV_FIELD2_MAX  (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DESIGNER_REV_FIELD2_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_SOFT_RESET */

#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_PTLA_RESET_MASK     (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_PTLA_RESET_SHIFT    (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_PTLA_RESET_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_PTLA_RESET_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_MCI_RESET_MASK      (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_MCI_RESET_SHIFT     (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_MCI_RESET_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_MCI_RESET_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_BIF_RESET_MASK      (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_BIF_RESET_SHIFT     (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_BIF_RESET_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_BIF_RESET_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_SLC_RESET_MASK      (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_SLC_RESET_SHIFT     (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_SLC_RESET_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_SLC_RESET_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_VDM_RESET_MASK      (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_VDM_RESET_SHIFT     (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_VDM_RESET_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_VDM_RESET_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_DPM_RESET_MASK      (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_DPM_RESET_SHIFT     (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_DPM_RESET_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_DPM_RESET_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_IPF_RESET_MASK      (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_IPF_RESET_SHIFT     (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_IPF_RESET_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_IPF_RESET_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_CORE_RESET_MASK     (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_CORE_RESET_SHIFT    (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_CORE_RESET_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_CORE_RESET_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SOFT_RESET_RESETVAL            (0x00000000U)

/* EUR_CR_MASTER_DEBUG */

#define CSL_HYDRA2_EUR_CR_MASTER_DEBUG_DUMMY_FIELD_MASK         (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DEBUG_DUMMY_FIELD_SHIFT        (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DEBUG_DUMMY_FIELD_RESETVAL     (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DEBUG_DUMMY_FIELD_MAX          (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DEBUG_RESETVAL                 (0x00000000U)

/* EUR_CR_MASTER_EVENT_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_MASTER_INTERRUPT_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_MASTER_INTERRUPT_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_MASTER_INTERRUPT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_MASTER_INTERRUPT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_PCU_INVALCOMPLETE_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_PCU_INVALCOMPLETE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_PCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_PCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TIMER_MASK        (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TIMER_SHIFT       (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TIMER_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TIMER_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_DPM_FAULT_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_DPM_FAULT_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_DPM_FAULT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_DPM_FAULT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TWOD_COMPLETE_MASK  (0x08000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TWOD_COMPLETE_SHIFT  (27U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TWOD_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TWOD_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TCU_INVALCOMPLETE_MASK  (0x04000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TCU_INVALCOMPLETE_SHIFT  (26U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_ZLS_MASK  (0x02000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_ZLS_SHIFT  (25U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_ZLS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_ZLS_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_TA_MEM_FREE_MASK  (0x01000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_TA_MEM_FREE_SHIFT  (24U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_TA_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_TA_MEM_FREE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_END_TILE_MASK  (0x00800000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_END_TILE_SHIFT  (23U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_END_TILE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_END_TILE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_INITEND_MASK  (0x00400000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_INITEND_SHIFT  (22U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_INITEND_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_INITEND_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_LOADED_MASK  (0x00200000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_LOADED_SHIFT  (21U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_LOADED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_LOADED_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_INV_MASK     (0x00100000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_INV_SHIFT    (20U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_INV_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_INV_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_FLUSHED_MASK  (0x00080000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_FLUSHED_SHIFT  (19U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_OTPM_FLUSHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_PIXELBE_END_RENDER_MASK  (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_PIXELBE_END_RENDER_SHIFT  (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_PIXELBE_END_RENDER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_PIXELBE_END_RENDER_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_HALT_MASK     (0x00020000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_HALT_SHIFT    (17U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_HALT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_HALT_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_VISIBILITY_FAIL_MASK  (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_VISIBILITY_FAIL_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_VISIBILITY_FAIL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_ISP_VISIBILITY_FAIL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_BREAKPOINT_MASK   (0x00008000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_BREAKPOINT_SHIFT  (15U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_BREAKPOINT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_BREAKPOINT_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_SW_EVENT_MASK     (0x00004000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_SW_EVENT_SHIFT    (14U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_SW_EVENT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_SW_EVENT_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_FINISHED_MASK  (0x00002000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_FINISHED_SHIFT  (13U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_FINISHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_FINISHED_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_TERMINATE_MASK  (0x00001000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_TERMINATE_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_TERMINATE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TA_TERMINATE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TPC_CLEAR_MASK    (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TPC_CLEAR_SHIFT   (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TPC_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TPC_CLEAR_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TPC_FLUSH_MASK    (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TPC_FLUSH_SHIFT   (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TPC_FLUSH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_TPC_FLUSH_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_CLEAR_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_CLEAR_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_LOAD_MASK  (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_LOAD_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_STORE_MASK  (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_STORE_SHIFT  (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_STORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_CONTROL_STORE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_CLEAR_MASK  (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_CLEAR_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_LOAD_MASK  (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_LOAD_SHIFT  (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_STORE_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_STORE_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_STORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_STATE_STORE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_REACHED_MEM_THRESH_MASK  (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_REACHED_MEM_THRESH_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_REACHED_MEM_THRESH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_REACHED_MEM_THRESH_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_GBL_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_GBL_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_GBL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_GBL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_MT_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_MT_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_MT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_OUT_OF_MEMORY_MT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_3D_MEM_FREE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_3D_MEM_FREE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_3D_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_DPM_3D_MEM_FREE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_EVENT_STATUS2 */

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DATA_BREAKPOINT_UNTRAPPED_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DATA_BREAKPOINT_UNTRAPPED_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DATA_BREAKPOINT_UNTRAPPED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DATA_BREAKPOINT_UNTRAPPED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DATA_BREAKPOINT_TRAPPED_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DATA_BREAKPOINT_TRAPPED_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DATA_BREAKPOINT_TRAPPED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DATA_BREAKPOINT_TRAPPED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_MTE_CONTEXT_DRAINED_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_MTE_CONTEXT_DRAINED_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_MTE_CONTEXT_DRAINED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_MTE_CONTEXT_DRAINED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_ISP2_ZLS_CSW_FINISHED_MASK  (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_ISP2_ZLS_CSW_FINISHED_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_ISP2_ZLS_CSW_FINISHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_ISP2_ZLS_CSW_FINISHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DCU_INVALCOMPLETE_MASK  (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DCU_INVALCOMPLETE_SHIFT  (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_MTE_STATE_FLUSHED_MASK  (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_MTE_STATE_FLUSHED_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_MTE_STATE_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_MTE_STATE_FLUSHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TE_RGNHDR_INIT_COMPLETE_MASK  (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TE_RGNHDR_INIT_COMPLETE_SHIFT  (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TE_RGNHDR_INIT_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TE_RGNHDR_INIT_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_TA_MASK     (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_TA_SHIFT    (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_TA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_TA_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_3D_MASK     (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_3D_SHIFT    (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_3D_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_3D_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_DL_MASK     (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_DL_SHIFT    (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_DL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_TRIG_DL_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DPM_3D_FREE_LOAD_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DPM_3D_FREE_LOAD_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DPM_3D_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DPM_3D_FREE_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DPM_TA_FREE_LOAD_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DPM_TA_FREE_LOAD_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DPM_TA_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_DPM_TA_FREE_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_STATUS2_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_EVENT_HOST_ENABLE */

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_MASTER_INTERRUPT_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_MASTER_INTERRUPT_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_MASTER_INTERRUPT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_MASTER_INTERRUPT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_PCU_INVALCOMPLETE_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_PCU_INVALCOMPLETE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_PCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_PCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TIMER_MASK   (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TIMER_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TIMER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TIMER_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_DPM_FAULT_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_DPM_FAULT_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_DPM_FAULT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_DPM_FAULT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TWOD_COMPLETE_MASK  (0x08000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TWOD_COMPLETE_SHIFT  (27U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TWOD_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TWOD_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TCU_INVALCOMPLETE_MASK  (0x04000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TCU_INVALCOMPLETE_SHIFT  (26U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_ZLS_MASK  (0x02000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_ZLS_SHIFT  (25U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_ZLS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_ZLS_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_TA_MEM_FREE_MASK  (0x01000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_TA_MEM_FREE_SHIFT  (24U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_TA_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_TA_MEM_FREE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_END_TILE_MASK  (0x00800000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_END_TILE_SHIFT  (23U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_END_TILE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_END_TILE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_INITEND_MASK  (0x00400000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_INITEND_SHIFT  (22U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_INITEND_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_INITEND_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_LOADED_MASK  (0x00200000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_LOADED_SHIFT  (21U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_LOADED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_LOADED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_INV_MASK  (0x00100000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_INV_SHIFT  (20U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_INV_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_INV_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_FLUSHED_MASK  (0x00080000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_FLUSHED_SHIFT  (19U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_OTPM_FLUSHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_PIXELBE_END_RENDER_MASK  (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_PIXELBE_END_RENDER_SHIFT  (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_PIXELBE_END_RENDER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_PIXELBE_END_RENDER_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_HALT_MASK  (0x00020000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_HALT_SHIFT  (17U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_HALT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_HALT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_VISIBILITY_FAIL_MASK  (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_VISIBILITY_FAIL_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_VISIBILITY_FAIL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_ISP_VISIBILITY_FAIL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_BREAKPOINT_MASK  (0x00008000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_BREAKPOINT_SHIFT  (15U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_BREAKPOINT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_BREAKPOINT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_SW_EVENT_MASK  (0x00004000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_SW_EVENT_SHIFT  (14U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_SW_EVENT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_SW_EVENT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_FINISHED_MASK  (0x00002000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_FINISHED_SHIFT  (13U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_FINISHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_FINISHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_TERMINATE_MASK  (0x00001000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_TERMINATE_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_TERMINATE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TA_TERMINATE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TPC_CLEAR_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TPC_CLEAR_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TPC_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TPC_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TPC_FLUSH_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TPC_FLUSH_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TPC_FLUSH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_TPC_FLUSH_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_CLEAR_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_CLEAR_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_LOAD_MASK  (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_LOAD_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_STORE_MASK  (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_STORE_SHIFT  (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_STORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_CONTROL_STORE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_CLEAR_MASK  (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_CLEAR_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_LOAD_MASK  (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_LOAD_SHIFT  (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_STORE_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_STORE_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_STORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_STATE_STORE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_REACHED_MEM_THRESH_MASK  (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_REACHED_MEM_THRESH_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_REACHED_MEM_THRESH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_REACHED_MEM_THRESH_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_GBL_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_GBL_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_GBL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_GBL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_MT_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_MT_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_MT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_MT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_3D_MEM_FREE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_3D_MEM_FREE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_3D_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_DPM_3D_MEM_FREE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_EVENT_HOST_ENABLE2 */

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_TRAPPED_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_TRAPPED_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_TRAPPED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_TRAPPED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_MTE_CONTEXT_DRAINED_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_MTE_CONTEXT_DRAINED_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_MTE_CONTEXT_DRAINED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_MTE_CONTEXT_DRAINED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_ISP2_ZLS_CSW_FINISHED_MASK  (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_ISP2_ZLS_CSW_FINISHED_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_ISP2_ZLS_CSW_FINISHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_ISP2_ZLS_CSW_FINISHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DCU_INVALCOMPLETE_MASK  (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DCU_INVALCOMPLETE_SHIFT  (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_MTE_STATE_FLUSHED_MASK  (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_MTE_STATE_FLUSHED_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_MTE_STATE_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_MTE_STATE_FLUSHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TE_RGNHDR_INIT_COMPLETE_MASK  (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TE_RGNHDR_INIT_COMPLETE_SHIFT  (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TE_RGNHDR_INIT_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TE_RGNHDR_INIT_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_TA_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_TA_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_TA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_TA_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_3D_MASK  (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_3D_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_3D_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_3D_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_DL_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_DL_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_DL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_TRIG_DL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DPM_3D_FREE_LOAD_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DPM_3D_FREE_LOAD_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DPM_3D_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DPM_3D_FREE_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DPM_TA_FREE_LOAD_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DPM_TA_FREE_LOAD_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DPM_TA_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_DPM_TA_FREE_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_ENABLE2_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_EVENT_HOST_CLEAR */

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_MASTER_INTERRUPT_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_MASTER_INTERRUPT_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_MASTER_INTERRUPT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_MASTER_INTERRUPT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_PCU_INVALCOMPLETE_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_PCU_INVALCOMPLETE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_PCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_PCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TIMER_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TIMER_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TIMER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TIMER_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_DPM_FAULT_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_DPM_FAULT_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_DPM_FAULT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_DPM_FAULT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TWOD_COMPLETE_MASK  (0x08000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TWOD_COMPLETE_SHIFT  (27U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TWOD_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TWOD_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TCU_INVALCOMPLETE_MASK  (0x04000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TCU_INVALCOMPLETE_SHIFT  (26U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_ZLS_MASK  (0x02000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_ZLS_SHIFT  (25U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_ZLS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_ZLS_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_TA_MEM_FREE_MASK  (0x01000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_TA_MEM_FREE_SHIFT  (24U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_TA_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_TA_MEM_FREE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_END_TILE_MASK  (0x00800000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_END_TILE_SHIFT  (23U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_END_TILE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_END_TILE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_INITEND_MASK  (0x00400000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_INITEND_SHIFT  (22U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_INITEND_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_INITEND_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_LOADED_MASK  (0x00200000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_LOADED_SHIFT  (21U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_LOADED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_LOADED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_INV_MASK  (0x00100000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_INV_SHIFT  (20U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_INV_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_INV_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_FLUSHED_MASK  (0x00080000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_FLUSHED_SHIFT  (19U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_OTPM_FLUSHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_PIXELBE_END_RENDER_MASK  (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_PIXELBE_END_RENDER_SHIFT  (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_PIXELBE_END_RENDER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_PIXELBE_END_RENDER_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_HALT_MASK  (0x00020000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_HALT_SHIFT  (17U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_HALT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_HALT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_VISIBILITY_FAIL_MASK  (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_VISIBILITY_FAIL_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_VISIBILITY_FAIL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_ISP_VISIBILITY_FAIL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_BREAKPOINT_MASK  (0x00008000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_BREAKPOINT_SHIFT  (15U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_BREAKPOINT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_BREAKPOINT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_SW_EVENT_MASK  (0x00004000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_SW_EVENT_SHIFT  (14U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_SW_EVENT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_SW_EVENT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_FINISHED_MASK  (0x00002000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_FINISHED_SHIFT  (13U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_FINISHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_FINISHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_TERMINATE_MASK  (0x00001000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_TERMINATE_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_TERMINATE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TA_TERMINATE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TPC_CLEAR_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TPC_CLEAR_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TPC_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TPC_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TPC_FLUSH_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TPC_FLUSH_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TPC_FLUSH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_TPC_FLUSH_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_CLEAR_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_CLEAR_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_LOAD_MASK  (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_LOAD_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_STORE_MASK  (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_STORE_SHIFT  (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_STORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_CONTROL_STORE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_CLEAR_MASK  (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_CLEAR_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_LOAD_MASK  (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_LOAD_SHIFT  (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_STORE_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_STORE_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_STORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_STATE_STORE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_REACHED_MEM_THRESH_MASK  (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_REACHED_MEM_THRESH_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_REACHED_MEM_THRESH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_REACHED_MEM_THRESH_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_GBL_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_GBL_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_GBL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_GBL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_MT_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_MT_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_MT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_MT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_3D_MEM_FREE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_3D_MEM_FREE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_3D_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_DPM_3D_MEM_FREE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_EVENT_HOST_CLEAR2 */

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_UNTRAPPED_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_UNTRAPPED_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_UNTRAPPED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_UNTRAPPED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_TRAPPED_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_TRAPPED_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_TRAPPED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_TRAPPED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_MTE_CONTEXT_DRAINED_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_MTE_CONTEXT_DRAINED_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_MTE_CONTEXT_DRAINED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_MTE_CONTEXT_DRAINED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_ISP2_ZLS_CSW_FINISHED_MASK  (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_ISP2_ZLS_CSW_FINISHED_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_ISP2_ZLS_CSW_FINISHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_ISP2_ZLS_CSW_FINISHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DCU_INVALCOMPLETE_MASK  (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DCU_INVALCOMPLETE_SHIFT  (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_MTE_STATE_FLUSHED_MASK  (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_MTE_STATE_FLUSHED_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_MTE_STATE_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_MTE_STATE_FLUSHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TE_RGNHDR_INIT_COMPLETE_MASK  (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TE_RGNHDR_INIT_COMPLETE_SHIFT  (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TE_RGNHDR_INIT_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TE_RGNHDR_INIT_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_TA_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_TA_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_TA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_TA_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_3D_MASK  (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_3D_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_3D_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_3D_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_DL_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_DL_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_DL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_TRIG_DL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DPM_3D_FREE_LOAD_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DPM_3D_FREE_LOAD_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DPM_3D_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DPM_3D_FREE_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DPM_TA_FREE_LOAD_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DPM_TA_FREE_LOAD_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DPM_TA_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_DPM_TA_FREE_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_HOST_CLEAR2_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PDS_CACHE_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV3_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV3_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV3_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV3_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV1_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV1_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV1_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV1_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV0_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV0_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV0_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_DSC_INV0_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_CSC_INV_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_CSC_INV_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_CSC_INV_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_CSC_INV_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_STATUS_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE */

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV3_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV3_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV3_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV3_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV1_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV1_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV1_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV1_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV0_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV0_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV0_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_DSC_INV0_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_CSC_INV_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_CSC_INV_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_CSC_INV_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_CSC_INV_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_ENABLE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR */

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV3_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV3_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV3_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV3_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV1_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV1_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV1_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV1_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV0_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV0_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV0_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_DSC_INV0_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_CSC_INV_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_CSC_INV_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_CSC_INV_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_CSC_INV_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PDS_CACHE_HOST_CLEAR_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS_RESUMED_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS_RESUMED_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS_RESUMED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS_RESUMED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS_DRAINED_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS_DRAINED_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS_DRAINED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS_DRAINED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_DRAIN_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_STATUS_RESUME_CLEAR_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_STATUS_RESUME_CLEAR_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_STATUS_RESUME_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_STATUS_RESUME_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_STATUS_DRAIN_CLEAR_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_STATUS_DRAIN_CLEAR_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_STATUS_DRAIN_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_STATUS_DRAIN_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_STATUS_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_CLIP_CHECKSUM */

#define CSL_HYDRA2_EUR_CR_MASTER_CLIP_CHECKSUM_VALUE_MASK       (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_CLIP_CHECKSUM_VALUE_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLIP_CHECKSUM_VALUE_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLIP_CHECKSUM_VALUE_MAX        (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_CLIP_CHECKSUM_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_MTE_MEM_CHECKSUM */

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_MEM_CHECKSUM_VALUE_MASK    (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_MEM_CHECKSUM_VALUE_SHIFT   (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_MEM_CHECKSUM_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_MEM_CHECKSUM_VALUE_MAX     (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_MEM_CHECKSUM_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_MTE_TE_CHECKSUM */

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_TE_CHECKSUM_VALUE_MASK     (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_TE_CHECKSUM_VALUE_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_TE_CHECKSUM_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_TE_CHECKSUM_VALUE_MAX      (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_TE_CHECKSUM_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_TE_CHECKSUM */

#define CSL_HYDRA2_EUR_CR_MASTER_TE_CHECKSUM_VALUE_MASK         (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_CHECKSUM_VALUE_SHIFT        (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_CHECKSUM_VALUE_RESETVAL     (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_CHECKSUM_VALUE_MAX          (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_TE_CHECKSUM_RESETVAL           (0x00000000U)

/* EUR_CR_MASTER_ISP_FPU_CHECKSUM */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_FPU_CHECKSUM_VALUE_MASK    (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_FPU_CHECKSUM_VALUE_SHIFT   (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_FPU_CHECKSUM_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_FPU_CHECKSUM_VALUE_MAX     (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_FPU_CHECKSUM_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_ISP_PRECALC_CHECKSUM */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_PRECALC_CHECKSUM_VALUE_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_PRECALC_CHECKSUM_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_PRECALC_CHECKSUM_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_PRECALC_CHECKSUM_VALUE_MAX  (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_PRECALC_CHECKSUM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_EDGE_CHECKSUM */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_EDGE_CHECKSUM_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_EDGE_CHECKSUM_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_EDGE_CHECKSUM_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_EDGE_CHECKSUM_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_EDGE_CHECKSUM_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_ISP_TAGWRITE_CHECKSUM */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_TAGWRITE_CHECKSUM_VALUE_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_TAGWRITE_CHECKSUM_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_TAGWRITE_CHECKSUM_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_TAGWRITE_CHECKSUM_VALUE_MAX  (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_TAGWRITE_CHECKSUM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_SPAN_CHECKSUM */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_SPAN_CHECKSUM_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_SPAN_CHECKSUM_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_SPAN_CHECKSUM_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_SPAN_CHECKSUM_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_SPAN_CHECKSUM_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PBE_CHECKSUM */

#define CSL_HYDRA2_EUR_CR_MASTER_PBE_CHECKSUM_VALUE_MASK        (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PBE_CHECKSUM_VALUE_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PBE_CHECKSUM_VALUE_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PBE_CHECKSUM_VALUE_MAX         (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PBE_CHECKSUM_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_EVENT_PDS_ENABLE */

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TWOD_COMPLETE_MASK  (0x08000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TWOD_COMPLETE_SHIFT  (27U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TWOD_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TWOD_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_PIXELBE_END_RENDER_MASK  (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_PIXELBE_END_RENDER_SHIFT  (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_PIXELBE_END_RENDER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_PIXELBE_END_RENDER_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TA_FINISHED_MASK  (0x00002000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TA_FINISHED_SHIFT  (13U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TA_FINISHED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TA_FINISHED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TA_TERMINATE_MASK  (0x00001000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TA_TERMINATE_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TA_TERMINATE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_TA_TERMINATE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_REACHED_MEM_THRESH_MASK  (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_REACHED_MEM_THRESH_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_REACHED_MEM_THRESH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_REACHED_MEM_THRESH_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_GBL_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_GBL_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_GBL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_GBL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_MT_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_MT_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_MT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_MT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_3D_MEM_FREE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_3D_MEM_FREE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_3D_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_DPM_3D_MEM_FREE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_EVENT_PDS_ENABLE2 */

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_TRAPPED_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_TRAPPED_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_TRAPPED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_TRAPPED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_MTE_CONTEXT_DRAINED_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_MTE_CONTEXT_DRAINED_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_MTE_CONTEXT_DRAINED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_MTE_CONTEXT_DRAINED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EVENT_PDS_ENABLE2_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_MEMORY_THROTTLE */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_ENABLE_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_ENABLE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_ENABLE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_DOWNTIME_MASK  (0x3FFF8000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_DOWNTIME_SHIFT  (15U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_DOWNTIME_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_DOWNTIME_MAX  (0x00007fffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_UPTIME_MASK  (0x00007FFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_UPTIME_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_UPTIME_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_UPTIME_MAX  (0x00007fffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_MEMORY_THROTTLE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_PTLA_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_STATUS_FIFO_FULLNESS_MASK  (0x0000007EU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_STATUS_FIFO_FULLNESS_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_STATUS_FIFO_FULLNESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_STATUS_FIFO_FULLNESS_MAX  (0x0000003fU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_STATUS_BUSY_MASK          (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_STATUS_BUSY_SHIFT         (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_STATUS_BUSY_RESETVAL      (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_STATUS_BUSY_MAX           (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_STATUS_RESETVAL           (0x00000000U)

/* EUR_CR_MASTER_PTLA_REQUEST */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_REQUEST_STATUS_MASK       (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_REQUEST_STATUS_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_REQUEST_STATUS_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_REQUEST_STATUS_MAX        (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_REQUEST_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_00 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_00_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_00_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_00_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_00_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_00_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_01 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_01_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_01_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_01_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_01_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_01_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_02 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_02_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_02_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_02_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_02_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_02_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_03 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_03_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_03_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_03_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_03_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_03_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_04 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_04_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_04_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_04_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_04_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_04_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_05 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_05_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_05_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_05_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_05_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_05_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_06 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_06_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_06_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_06_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_06_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_06_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_07 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_07_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_07_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_07_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_07_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_07_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_08 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_08_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_08_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_08_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_08_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_08_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_09 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_09_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_09_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_09_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_09_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_09_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_10 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_10_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_10_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_10_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_10_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_10_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_11 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_11_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_11_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_11_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_11_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_11_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_12 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_12_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_12_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_12_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_12_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_12_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_13 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_13_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_13_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_13_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_13_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_13_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_14 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_14_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_14_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_14_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_14_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_14_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_15 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_15_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_15_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_15_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_15_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_15_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_16 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_16_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_16_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_16_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_16_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_16_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_17 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_17_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_17_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_17_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_17_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_17_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_18 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_18_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_18_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_18_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_18_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_18_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_19 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_19_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_19_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_19_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_19_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_19_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_20 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_20_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_20_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_20_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_20_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_20_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_21 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_21_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_21_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_21_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_21_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_21_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_22 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_22_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_22_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_22_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_22_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_22_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_23 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_23_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_23_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_23_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_23_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_23_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_24 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_24_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_24_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_24_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_24_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_24_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_25 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_25_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_25_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_25_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_25_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_25_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_26 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_26_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_26_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_26_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_26_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_26_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_27 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_27_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_27_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_27_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_27_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_27_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_28 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_28_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_28_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_28_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_28_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_28_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_29 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_29_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_29_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_29_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_29_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_29_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_30 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_30_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_30_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_30_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_30_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_30_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_PTLA_SLAVE_CMD_31 */

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_31_VALUE_MASK   (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_31_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_31_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_31_VALUE_MAX    (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_PTLA_SLAVE_CMD_31_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_CLKGATECTL2 */

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_AUTO_MAN_REG_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_AUTO_MAN_REG_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_AUTO_MAN_REG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_AUTO_MAN_REG_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_PTLA_CLKG_MASK     (0x00000300U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_PTLA_CLKG_SHIFT    (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_PTLA_CLKG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_PTLA_CLKG_MAX      (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_VDM_CLKG_MASK      (0x000000C0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_VDM_CLKG_SHIFT     (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_VDM_CLKG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_VDM_CLKG_MAX       (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_IPF_CLKG_MASK      (0x00000030U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_IPF_CLKG_SHIFT     (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_IPF_CLKG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_IPF_CLKG_MAX       (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_DPM_CLKG_MASK      (0x0000000CU)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_DPM_CLKG_SHIFT     (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_DPM_CLKG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_DPM_CLKG_MAX       (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_BIF_CLKG_MASK      (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_BIF_CLKG_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_BIF_CLKG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_BIF_CLKG_MAX       (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTL2_RESETVAL           (0x00000000U)

/* EUR_CR_MASTER_CLKGATESTATUS2 */

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_PTLA_CLKS_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_PTLA_CLKS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_PTLA_CLKS_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_PTLA_CLKS_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_VDM_CLKS_MASK   (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_VDM_CLKS_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_VDM_CLKS_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_VDM_CLKS_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_IPF_CLKS_MASK   (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_IPF_CLKS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_IPF_CLKS_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_IPF_CLKS_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_DPM_CLKS_MASK   (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_DPM_CLKS_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_DPM_CLKS_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_DPM_CLKS_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_BIF_CLKS_MASK   (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_BIF_CLKS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_BIF_CLKS_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_BIF_CLKS_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATESTATUS2_RESETVAL        (0x0000001fU)

/* EUR_CR_MASTER_CLKGATECTLOVR2 */

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_PTLA_CLKO_MASK  (0x00000300U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_PTLA_CLKO_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_PTLA_CLKO_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_PTLA_CLKO_MAX   (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_VDM_CLKO_MASK   (0x000000C0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_VDM_CLKO_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_VDM_CLKO_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_VDM_CLKO_MAX    (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_IPF_CLKO_MASK   (0x00000030U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_IPF_CLKO_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_IPF_CLKO_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_IPF_CLKO_MAX    (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_DPM_CLKO_MASK   (0x0000000CU)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_DPM_CLKO_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_DPM_CLKO_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_DPM_CLKO_MAX    (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_BIF_CLKO_MASK   (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_BIF_CLKO_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_BIF_CLKO_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_BIF_CLKO_MAX    (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_CLKGATECTLOVR2_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_MP_PRIMITIVE */

#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_MAX_BLOCKS_MASK   (0x00F00000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_MAX_BLOCKS_SHIFT  (20U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_MAX_BLOCKS_RESETVAL  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_MAX_BLOCKS_MAX    (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_SPLIT_MODE_MASK   (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_SPLIT_MODE_SHIFT  (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_SPLIT_MODE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_SPLIT_MODE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_OMIT_OPT_WORDS_MASK  (0x00020000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_OMIT_OPT_WORDS_SHIFT  (17U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_OMIT_OPT_WORDS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_OMIT_OPT_WORDS_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_MODE_MASK         (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_MODE_SHIFT        (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_MODE_RESETVAL     (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_MODE_MAX          (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_SPLIT_THRESHOLD_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_SPLIT_THRESHOLD_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_SPLIT_THRESHOLD_RESETVAL  (0x000003e8U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_SPLIT_THRESHOLD_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_RESETVAL          (0x004003e8U)

/* EUR_CR_MASTER_MP_PRIMITIVE_CG */

#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_CG_SPLIT_THRESHOLD_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_CG_SPLIT_THRESHOLD_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_CG_SPLIT_THRESHOLD_RESETVAL  (0x000003e8U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_CG_SPLIT_THRESHOLD_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_MP_PRIMITIVE_CG_RESETVAL       (0x000003e8U)

/* EUR_CR_MASTER_MP_TILE */

#define CSL_HYDRA2_EUR_CR_MASTER_MP_TILE_MODE_MASK              (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_TILE_MODE_SHIFT             (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_TILE_MODE_RESETVAL          (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MP_TILE_MODE_MAX               (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_MP_TILE_RESETVAL               (0x00000000U)

/* EUR_CR_MASTER_VDM_START */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_START_PULSE_MASK           (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_START_PULSE_SHIFT          (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_START_PULSE_RESETVAL       (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_START_PULSE_MAX            (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_START_RESETVAL             (0x00000000U)

/* EUR_CR_MASTER_TE_AA */

#define CSL_HYDRA2_EUR_CR_MASTER_TE_AA_X_MASK                   (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_AA_X_SHIFT                  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_AA_X_RESETVAL               (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_AA_X_MAX                    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_TE_AA_Y_MASK                   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_AA_Y_SHIFT                  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_AA_Y_RESETVAL               (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_AA_Y_MAX                    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_TE_AA_RESETVAL                 (0x00000000U)

/* EUR_CR_MASTER_TE_MTILE */

#define CSL_HYDRA2_EUR_CR_MASTER_TE_MTILE_STRIDE_MASK           (0x0003FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_MTILE_STRIDE_SHIFT          (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_MTILE_STRIDE_RESETVAL       (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_TE_MTILE_STRIDE_MAX            (0x0003ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_TE_MTILE_RESETVAL              (0x00000000U)

/* EUR_CR_MASTER_VDM_CTRL_STREAM_BASE */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CTRL_STREAM_BASE_ADDR_MASK  (0xFFFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CTRL_STREAM_BASE_ADDR_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CTRL_STREAM_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CTRL_STREAM_BASE_ADDR_MAX  (0x3fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CTRL_STREAM_BASE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_MTE_FIRST_PAGE */

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_VALID_MASK      (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_VALID_SHIFT     (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_VALID_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_MACROTILE_MASK  (0x001F0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_MACROTILE_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_MACROTILE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_MACROTILE_MAX   (0x0000001fU)

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_DATA_MASK       (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_DATA_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_DATA_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_DATA_MAX        (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FIRST_PAGE_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_MTE_SECOND_PAGE */

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_SECOND_PAGE_VALID_MASK     (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_SECOND_PAGE_VALID_SHIFT    (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_SECOND_PAGE_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_SECOND_PAGE_VALID_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_SECOND_PAGE_DATA_MASK      (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_SECOND_PAGE_DATA_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_SECOND_PAGE_DATA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_SECOND_PAGE_DATA_MAX       (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_SECOND_PAGE_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_STORE_SNAPSHOT */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_SNAPSHOT_BASE_ADDR_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_SNAPSHOT_BASE_ADDR_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_SNAPSHOT_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_SNAPSHOT_BASE_ADDR_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_SNAPSHOT_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_LOAD_START */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_START_PULSE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_START_PULSE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_START_PULSE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_START_PULSE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_START_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_PROCESSING_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_PROCESSING_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_PROCESSING_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_PROCESSING_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_COMPLETE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_COMPLETE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_CLEAR */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_CLEAR_PULSE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_CLEAR_PULSE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_CLEAR_PULSE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_CLEAR_PULSE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_LOAD_STATUS_CLEAR_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_TASK_KICK */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_PULSE_MASK       (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_PULSE_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_PULSE_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_PULSE_MAX        (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_VDM_TASK_KICK_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_PROCESSING_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_PROCESSING_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_PROCESSING_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_PROCESSING_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_COMPLETE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_COMPLETE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_TASK_KICK_STATUS_CLEAR */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_CLEAR_PULSE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_CLEAR_PULSE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_CLEAR_PULSE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_CLEAR_PULSE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_TASK_KICK_STATUS_CLEAR_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_BATCH_NUM */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_VALUE_MASK       (0x00003FFEU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_VALUE_SHIFT      (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_VALUE_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_VALUE_MAX        (0x00001fffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_LOAD_MASK        (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_LOAD_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_LOAD_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_LOAD_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_VDM_BATCH_NUM_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_STATUS_VALUE_MASK  (0x00001FFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_STATUS_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_STATUS_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_STATUS_VALUE_MAX  (0x00001fffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_BATCH_NUM_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD0 */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD0_DATA_MASK  (0x00FFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD0_DATA_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD0_DATA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD0_DATA_MAX  (0x00ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD0_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD1 */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD1_DATA_MASK  (0x00FFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD1_DATA_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD1_DATA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD1_DATA_MAX  (0x00ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_GENERIC_WORD1_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_STORE_START */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_START_PULSE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_START_PULSE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_START_PULSE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_START_PULSE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_START_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_STORE_STREAM */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STREAM_ADDR_MASK  (0xFFFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STREAM_ADDR_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STREAM_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STREAM_ADDR_MAX  (0x3fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STREAM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_NA_MASK  (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_NA_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_NA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_NA_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_PROCESS_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_PROCESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_PROCESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_PROCESS_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_COMPLETE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_COMPLETE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0 */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_TERMINATE_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_TERMINATE_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_TERMINATE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_TERMINATE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_COMPLEX_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_COMPLEX_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_COMPLEX_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_COMPLEX_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_BASEADDR_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_BASEADDR_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_BASEADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_BASEADDR_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE0_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1 */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_DATASIZE_MASK  (0xF8000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_DATASIZE_SHIFT  (27U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_DATASIZE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_DATASIZE_MAX  (0x0000001fU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SD_MASK  (0x02000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SD_SHIFT  (25U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_GENERIC_PRESENT_MASK  (0x00180000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_GENERIC_PRESENT_SHIFT  (19U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_GENERIC_PRESENT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_GENERIC_PRESENT_MAX  (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_FENCE_ENABLE_MASK  (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_FENCE_ENABLE_SHIFT  (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_FENCE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_FENCE_ENABLE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_MTE_EMIT_MASK  (0x00020000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_MTE_EMIT_SHIFT  (17U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_MTE_EMIT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_MTE_EMIT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEPIPE_MASK  (0x0001E000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEPIPE_SHIFT  (13U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEPIPE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEPIPE_MAX  (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTIAL_MASK  (0x00001000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTIAL_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTIAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTIAL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTITIONS_MASK  (0x00000E00U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTITIONS_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTITIONS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTITIONS_MAX  (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SECONDARY_MASK  (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SECONDARY_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SECONDARY_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SECONDARY_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEATTRIBUTESIZE_MASK  (0x000000FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEATTRIBUTESIZE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEATTRIBUTESIZE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEATTRIBUTESIZE_MAX  (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CONTEXT_STORE_STATE1_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_WAIT_FOR_KICK */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_WAIT_FOR_KICK_STATUS_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_WAIT_FOR_KICK_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_WAIT_FOR_KICK_STATUS_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_WAIT_FOR_KICK_STATUS_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_WAIT_FOR_KICK_RESETVAL     (0x00000001U)

/* EUR_CR_MASTER_VDM_PIM */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_VALUE_MASK             (0x3FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_VALUE_SHIFT            (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_VALUE_RESETVAL         (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_VALUE_MAX              (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_LOAD_MASK              (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_LOAD_SHIFT             (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_LOAD_RESETVAL          (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_LOAD_MAX               (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_CLEAR_MASK             (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_CLEAR_SHIFT            (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_CLEAR_RESETVAL         (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_CLEAR_MAX              (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_RESETVAL               (0x00000000U)

/* EUR_CR_MASTER_VDM_PIM_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_VALUE_MASK      (0x3FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_VALUE_SHIFT     (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_VALUE_MAX       (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_LOADED_MASK     (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_LOADED_SHIFT    (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_LOADED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_LOADED_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_CLEARED_MASK    (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_CLEARED_SHIFT   (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_CLEARED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_CLEARED_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_STATUS_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_VDM_PIM_MAX */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_MAX_VALUE_MASK         (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_MAX_VALUE_SHIFT        (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_MAX_VALUE_RESETVAL     (0x0fffffffU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_MAX_VALUE_MAX          (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_PIM_MAX_RESETVAL           (0x0fffffffU)

/* EUR_CR_MASTER_DPM_TASK_DPLIST */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_STORE_MASK     (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_STORE_SHIFT    (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_STORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_STORE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_LOAD_MASK      (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_LOAD_SHIFT     (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_LOAD_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_CLEAR_MASK     (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_CLEAR_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_CLEAR_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_DPLIST_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_STORED_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_STORED_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_STORED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_STORED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_LOADED_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_LOADED_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_LOADED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_LOADED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_CLEARED_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_CLEARED_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_CLEARED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_CLEARED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_EVENT_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_STORE_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_STORE_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_STORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_STORE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_LOAD_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_LOAD_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_LOAD_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_CLEAR_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_CLEAR_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_CLEAR_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_CLEAR_EVENT_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_VDM_CORE */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CORE_NUM_MASK              (0x00000006U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CORE_NUM_SHIFT             (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CORE_NUM_RESETVAL          (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CORE_NUM_MAX               (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CORE_LOAD_MASK             (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CORE_LOAD_SHIFT            (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CORE_LOAD_RESETVAL         (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CORE_LOAD_MAX              (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_CORE_RESETVAL              (0x00000000U)

/* EUR_CR_MASTER_VDM_FENCE */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_INCREMENT_MASK       (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_INCREMENT_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_INCREMENT_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_INCREMENT_MAX        (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_RESETVAL             (0x00000000U)

/* EUR_CR_MASTER_VDM_FENCE_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_STATUS_COUNT_MASK    (0x000000FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_STATUS_COUNT_SHIFT   (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_STATUS_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_STATUS_COUNT_MAX     (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_VDM_FENCE_STATUS_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_ISP_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_STATUS_EOR_MASK            (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_STATUS_EOR_SHIFT           (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_STATUS_EOR_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_STATUS_EOR_MAX             (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_STATUS_RESETVAL            (0x00000000U)

/* EUR_CR_MASTER_ISP_RENDER */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_FAST_SCANDIR_MASK   (0x00000030U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_FAST_SCANDIR_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_FAST_SCANDIR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_FAST_SCANDIR_TL2BR  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_FAST_SCANDIR_TR2BL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_FAST_SCANDIR_BL2TR  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_FAST_SCANDIR_BR2TL  (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_CONTEXT_RESUMED_MASK  (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_CONTEXT_RESUMED_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_CONTEXT_RESUMED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_CONTEXT_RESUMED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_TYPE_MASK           (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_TYPE_SHIFT          (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_TYPE_RESETVAL       (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_TYPE_MAX            (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDER_RESETVAL            (0x00000000U)

/* EUR_CR_MASTER_ISP_RGN_BASE */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE_ADDR_MASK         (0xFFFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE_ADDR_SHIFT        (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE_ADDR_RESETVAL     (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE_ADDR_MAX          (0x3fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_ISP_RENDBOX1 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX1_X_MASK            (0x00FF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX1_X_SHIFT           (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX1_X_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX1_X_MAX             (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX1_Y_MASK            (0x000000FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX1_Y_SHIFT           (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX1_Y_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX1_Y_MAX             (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX1_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_ISP_RENDBOX2 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX2_X_MASK            (0x00FF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX2_X_SHIFT           (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX2_X_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX2_X_MAX             (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX2_Y_MASK            (0x000000FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX2_Y_SHIFT           (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX2_Y_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX2_Y_MAX             (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RENDBOX2_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_ISP_START_RENDER */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_START_RENDER_PULSE_MASK    (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_START_RENDER_PULSE_SHIFT   (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_START_RENDER_PULSE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_START_RENDER_PULSE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_START_RENDER_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_THREED_AA_MODE */

#define CSL_HYDRA2_EUR_CR_MASTER_THREED_AA_MODE_VALUE_MASK      (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_THREED_AA_MODE_VALUE_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_THREED_AA_MODE_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_THREED_AA_MODE_VALUE_MAX       (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_THREED_AA_MODE_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_ISP_BREAK */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_BREAK_RESUME_MASK          (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_BREAK_RESUME_SHIFT         (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_BREAK_RESUME_RESETVAL      (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_BREAK_RESUME_MAX           (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_BREAK_HALT_MASK            (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_BREAK_HALT_SHIFT           (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_BREAK_HALT_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_BREAK_HALT_MAX             (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_BREAK_RESETVAL             (0x00000000U)

/* EUR_CR_MASTER_ISP_3DCONTEXT */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_3DCONTEXT_STORE_MASK       (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_3DCONTEXT_STORE_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_3DCONTEXT_STORE_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_3DCONTEXT_STORE_MAX        (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_3DCONTEXT_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_ISP_RGN_BASE1 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE1_ADDR_MASK        (0xFFFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE1_ADDR_SHIFT       (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE1_ADDR_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE1_ADDR_MAX         (0x3fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE1_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_ISP_RGN_BASE2 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE2_ADDR_MASK        (0xFFFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE2_ADDR_SHIFT       (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE2_ADDR_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE2_ADDR_MAX         (0x3fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE2_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_ISP_RGN_BASE3 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE3_ADDR_MASK        (0xFFFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE3_ADDR_SHIFT       (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE3_ADDR_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE3_ADDR_MAX         (0x3fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_BASE3_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_ISP_RGN */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_SIZE_MASK              (0x00FFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_SIZE_SHIFT             (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_SIZE_RESETVAL          (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_SIZE_MAX               (0x003fffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_RGN_RESETVAL               (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_TILE_X_MASK  (0xFF000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_TILE_X_SHIFT  (24U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_TILE_X_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_TILE_X_MAX  (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_TILE_Y_MASK  (0x00FF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_TILE_Y_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_TILE_Y_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_TILE_Y_MAX  (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_CORE_ACTIVE_MASK  (0x00001000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_CORE_ACTIVE_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_CORE_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_CORE_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_END_OF_TILE_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_END_OF_TILE_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_END_OF_TILE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_END_OF_TILE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_END_OF_RENDER_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_END_OF_RENDER_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_END_OF_RENDER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_END_OF_RENDER_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_PT_IN_FLIGHT_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_PT_IN_FLIGHT_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_PT_IN_FLIGHT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_PT_IN_FLIGHT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_ZLS_BURST_MASK  (0x000001FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_ZLS_BURST_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_ZLS_BURST_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_ZLS_BURST_MAX  (0x000001ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME2_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME4 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME4_PIM_ID_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME4_PIM_ID_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME4_PIM_ID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME4_PIM_ID_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME4_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5_EMPTY_STATUS_MASK  (0x000000F0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5_EMPTY_STATUS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5_EMPTY_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5_EMPTY_STATUS_MAX  (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5_STREAM_ID_MASK  (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5_STREAM_ID_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5_STREAM_ID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5_STREAM_ID_MAX  (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME5_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME6_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME7_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME8_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE0_CONTEXT_RESUME9_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_TILE_X_MASK  (0xFF000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_TILE_X_SHIFT  (24U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_TILE_X_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_TILE_X_MAX  (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_TILE_Y_MASK  (0x00FF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_TILE_Y_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_TILE_Y_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_TILE_Y_MAX  (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_CORE_ACTIVE_MASK  (0x00001000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_CORE_ACTIVE_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_CORE_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_CORE_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_END_OF_TILE_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_END_OF_TILE_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_END_OF_TILE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_END_OF_TILE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_END_OF_RENDER_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_END_OF_RENDER_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_END_OF_RENDER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_END_OF_RENDER_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_PT_IN_FLIGHT_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_PT_IN_FLIGHT_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_PT_IN_FLIGHT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_PT_IN_FLIGHT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_ZLS_BURST_MASK  (0x000001FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_ZLS_BURST_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_ZLS_BURST_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_ZLS_BURST_MAX  (0x000001ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME2_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME4 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME4_PIM_ID_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME4_PIM_ID_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME4_PIM_ID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME4_PIM_ID_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME4_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5_EMPTY_STATUS_MASK  (0x000000F0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5_EMPTY_STATUS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5_EMPTY_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5_EMPTY_STATUS_MAX  (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5_STREAM_ID_MASK  (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5_STREAM_ID_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5_STREAM_ID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5_STREAM_ID_MAX  (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME5_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME6_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME7_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME8_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE1_CONTEXT_RESUME9_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_TILE_X_MASK  (0xFF000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_TILE_X_SHIFT  (24U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_TILE_X_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_TILE_X_MAX  (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_TILE_Y_MASK  (0x00FF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_TILE_Y_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_TILE_Y_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_TILE_Y_MAX  (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_CORE_ACTIVE_MASK  (0x00001000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_CORE_ACTIVE_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_CORE_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_CORE_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_END_OF_TILE_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_END_OF_TILE_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_END_OF_TILE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_END_OF_TILE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_END_OF_RENDER_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_END_OF_RENDER_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_END_OF_RENDER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_END_OF_RENDER_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_PT_IN_FLIGHT_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_PT_IN_FLIGHT_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_PT_IN_FLIGHT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_PT_IN_FLIGHT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_ZLS_BURST_MASK  (0x000001FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_ZLS_BURST_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_ZLS_BURST_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_ZLS_BURST_MAX  (0x000001ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME2_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME4 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME4_PIM_ID_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME4_PIM_ID_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME4_PIM_ID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME4_PIM_ID_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME4_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5_EMPTY_STATUS_MASK  (0x000000F0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5_EMPTY_STATUS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5_EMPTY_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5_EMPTY_STATUS_MAX  (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5_STREAM_ID_MASK  (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5_STREAM_ID_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5_STREAM_ID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5_STREAM_ID_MAX  (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME5_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME6_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME7_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME8_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE2_CONTEXT_RESUME9_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_TILE_X_MASK  (0xFF000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_TILE_X_SHIFT  (24U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_TILE_X_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_TILE_X_MAX  (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_TILE_Y_MASK  (0x00FF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_TILE_Y_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_TILE_Y_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_TILE_Y_MAX  (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_CORE_ACTIVE_MASK  (0x00001000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_CORE_ACTIVE_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_CORE_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_CORE_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_END_OF_TILE_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_END_OF_TILE_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_END_OF_TILE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_END_OF_TILE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_END_OF_RENDER_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_END_OF_RENDER_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_END_OF_RENDER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_END_OF_RENDER_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_PT_IN_FLIGHT_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_PT_IN_FLIGHT_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_PT_IN_FLIGHT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_PT_IN_FLIGHT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_ZLS_BURST_MASK  (0x000001FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_ZLS_BURST_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_ZLS_BURST_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_ZLS_BURST_MAX  (0x000001ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME2_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME4 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME4_PIM_ID_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME4_PIM_ID_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME4_PIM_ID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME4_PIM_ID_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME4_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5_EMPTY_STATUS_MASK  (0x000000F0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5_EMPTY_STATUS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5_EMPTY_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5_EMPTY_STATUS_MAX  (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5_STREAM_ID_MASK  (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5_STREAM_ID_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5_STREAM_ID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5_STREAM_ID_MAX  (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME5_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6_RGN0_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6_RGN0_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME6_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7_RGN1_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7_RGN1_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME7_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8_RGN2_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8_RGN2_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME8_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9 */

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9_RGN3_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9_RGN3_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_ISP_CORE3_CONTEXT_RESUME9_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_3D_PAGE_TABLE_BASE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_PAGE_TABLE_BASE_ADDR_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_PAGE_TABLE_BASE_ADDR_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_PAGE_TABLE_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_PAGE_TABLE_BASE_ADDR_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_PAGE_TABLE_BASE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_3D_FREE_LIST */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_TAIL_MASK     (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_TAIL_SHIFT    (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_TAIL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_TAIL_MAX      (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_HEAD_MASK     (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_HEAD_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_HEAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_HEAD_MAX      (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_DPM_PDS_PAGE_THRESHOLD */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PDS_PAGE_THRESHOLD_VALUE_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PDS_PAGE_THRESHOLD_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PDS_PAGE_THRESHOLD_VALUE_RESETVAL  (0x00002000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PDS_PAGE_THRESHOLD_VALUE_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PDS_PAGE_THRESHOLD_RESETVAL  (0x00002000U)

/* EUR_CR_MASTER_DPM_TA_ALLOC_PAGE_TABLE_BASE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_PAGE_TABLE_BASE_ADDR_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_PAGE_TABLE_BASE_ADDR_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_PAGE_TABLE_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_PAGE_TABLE_BASE_ADDR_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_PAGE_TABLE_BASE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_TAIL_MASK  (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_TAIL_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_TAIL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_TAIL_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_HEAD_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_HEAD_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_HEAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_HEAD_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_TA_PAGE_THRESHOLD */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_PAGE_THRESHOLD_VALUE_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_PAGE_THRESHOLD_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_PAGE_THRESHOLD_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_PAGE_THRESHOLD_VALUE_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_PAGE_THRESHOLD_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_ZLS_PAGE_THRESHOLD */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ZLS_PAGE_THRESHOLD_VALUE_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ZLS_PAGE_THRESHOLD_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ZLS_PAGE_THRESHOLD_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ZLS_PAGE_THRESHOLD_VALUE_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ZLS_PAGE_THRESHOLD_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_TA_GLOBAL_LIST */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_GLOBAL_LIST_POLICY_MASK  (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_GLOBAL_LIST_POLICY_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_GLOBAL_LIST_POLICY_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_GLOBAL_LIST_POLICY_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_GLOBAL_LIST_SIZE_MASK   (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_GLOBAL_LIST_SIZE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_GLOBAL_LIST_SIZE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_GLOBAL_LIST_SIZE_MAX    (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_GLOBAL_LIST_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT0_BASE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT0_BASE_ADDR_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT0_BASE_ADDR_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT0_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT0_BASE_ADDR_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT0_BASE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_STATE_CONTEXT_ID */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_NCOP_MASK  (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_NCOP_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_NCOP_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_NCOP_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_ALLOC_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_ALLOC_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_ALLOC_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_ALLOC_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_DALLOC_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_DALLOC_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_DALLOC_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_DALLOC_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_LS_MASK   (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_LS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_LS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_LS_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_CONTEXT_ID_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_GLOBAL_MASK  (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_GLOBAL_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_GLOBAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_GLOBAL_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_LOCAL_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_LOCAL_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_LOCAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_LOCAL_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_3D_DEALLOCATE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_DEALLOCATE_ENABLE_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_DEALLOCATE_ENABLE_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_DEALLOCATE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_DEALLOCATE_ENABLE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_DEALLOCATE_GLOBAL_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_DEALLOCATE_GLOBAL_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_DEALLOCATE_GLOBAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_DEALLOCATE_GLOBAL_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_DEALLOCATE_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_ALLOC */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_OUTOFMEMORY_MASK  (0x00020000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_OUTOFMEMORY_SHIFT  (17U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_OUTOFMEMORY_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_OUTOFMEMORY_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_VALID_MASK      (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_VALID_SHIFT     (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_VALID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_VALID_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_MASK            (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_SHIFT           (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_PAGE_MAX             (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ALLOC_RESETVAL             (0x00000000U)

/* EUR_CR_MASTER_DPM_DALLOC */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DALLOC_PAGE_FREE_MASK      (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DALLOC_PAGE_FREE_SHIFT     (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DALLOC_PAGE_FREE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DALLOC_PAGE_FREE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DALLOC_PAGE_MASK           (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DALLOC_PAGE_SHIFT          (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DALLOC_PAGE_RESETVAL       (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DALLOC_PAGE_MAX            (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DALLOC_RESETVAL            (0x00000000U)

/* EUR_CR_MASTER_DPM_TA_ALLOC */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_PREVIOUS_MASK  (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_PREVIOUS_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_PREVIOUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_PREVIOUS_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_DPM_3D */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_PREVIOUS_MASK  (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_PREVIOUS_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_PREVIOUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_PREVIOUS_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_RESETVAL                (0x00000000U)

/* EUR_CR_MASTER_DPM_PARTIAL_RENDER */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PARTIAL_RENDER_ENABLE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PARTIAL_RENDER_ENABLE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PARTIAL_RENDER_ENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PARTIAL_RENDER_ENABLE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PARTIAL_RENDER_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_DPM_LSS_PARTIAL_CONTEXT */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_LSS_PARTIAL_CONTEXT_OPERATION_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_LSS_PARTIAL_CONTEXT_OPERATION_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_LSS_PARTIAL_CONTEXT_OPERATION_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_LSS_PARTIAL_CONTEXT_OPERATION_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_LSS_PARTIAL_CONTEXT_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_GLOBAL_MASK  (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_GLOBAL_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_GLOBAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_GLOBAL_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_LOCAL_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_LOCAL_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_LOCAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_LOCAL_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_CONTEXT_PB_BASE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_PB_BASE_CMP_MASK   (0x00000007U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_PB_BASE_CMP_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_PB_BASE_CMP_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_PB_BASE_CMP_MAX    (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_PB_BASE_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_PAGE_MANAGEOP */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_SERIAL_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_SERIAL_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_SERIAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_SERIAL_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_DISABLE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_DISABLE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_DISABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_DISABLE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT1_BASE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT1_BASE_ADDR_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT1_BASE_ADDR_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT1_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT1_BASE_ADDR_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_STATE_TABLE_CONTEXT1_BASE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_TASK_3D_FREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_3D_FREE_LOAD_MASK     (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_3D_FREE_LOAD_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_3D_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_3D_FREE_LOAD_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_3D_FREE_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_DPM_TASK_TA_FREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_TA_FREE_LOAD_MASK     (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_TA_FREE_LOAD_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_TA_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_TA_FREE_LOAD_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_TA_FREE_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_DPM_TASK_HOST_FREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_HOST_FREE_LOAD_MASK   (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_HOST_FREE_LOAD_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_HOST_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_HOST_FREE_LOAD_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_HOST_FREE_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_DPM_TASK_STATE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_LOAD_MASK       (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_LOAD_SHIFT      (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_LOAD_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_LOAD_MAX        (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_CLEAR_MASK      (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_CLEAR_SHIFT     (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_CLEAR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_CLEAR_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_STORE_MASK      (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_STORE_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_STORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_STORE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TASK_STATE_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_DPM_OUTOFMEM */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_ABORTALL_MASK     (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_ABORTALL_SHIFT    (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_ABORTALL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_ABORTALL_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_ABORT_MASK        (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_ABORT_SHIFT       (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_ABORT_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_ABORT_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_RESTART_MASK      (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_RESTART_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_RESTART_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_RESTART_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_OUTOFMEM_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_DPM_FREE_CONTEXT */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_FREE_CONTEXT_NOW_MASK      (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_FREE_CONTEXT_NOW_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_FREE_CONTEXT_NOW_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_FREE_CONTEXT_NOW_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_FREE_CONTEXT_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_DPM_3D_TIMEOUT */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_TIMEOUT_NOW_MASK        (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_TIMEOUT_NOW_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_TIMEOUT_NOW_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_TIMEOUT_NOW_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_TIMEOUT_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_DPM_TA_EVM */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_EVM_INIT_MASK           (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_EVM_INIT_SHIFT          (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_EVM_INIT_RESETVAL       (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_EVM_INIT_MAX            (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_EVM_RESETVAL            (0x00000000U)

/* EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1_TAIL_MASK  (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1_TAIL_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1_TAIL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1_TAIL_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1_HEAD_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1_HEAD_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1_HEAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1_HEAD_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS1_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1_TAIL_MASK  (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1_TAIL_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1_TAIL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1_TAIL_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1_HEAD_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1_HEAD_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1_HEAD_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1_HEAD_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS1_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS2 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS2_PREVIOUS_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS2_PREVIOUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS2_PREVIOUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS2_PREVIOUS_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TA_ALLOC_FREE_LIST_STATUS2_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS2 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS2_PREVIOUS_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS2_PREVIOUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS2_PREVIOUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS2_PREVIOUS_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_3D_FREE_LIST_STATUS2_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_CORE_MASK  (0x000000E0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_CORE_SHIFT  (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_CORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_CORE_MAX  (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_GLOBAL_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_GLOBAL_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_GLOBAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_GLOBAL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_INDEX_MASK  (0x0000000FU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_INDEX_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_INDEX_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_INDEX_MAX  (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_ABORT_STATUS_MTILE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_PAGE_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_TA_MASK        (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_TA_SHIFT       (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_TA_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_TA_MAX         (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_TOTAL_MASK     (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_TOTAL_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_TOTAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_TOTAL_MAX      (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_DPM_PAGE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_3D_MASK        (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_3D_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_3D_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_STATUS_3D_MAX         (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_RESETVAL              (0x00000000U)

/* EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_TA_MASK  (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_TA_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_TA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_TA_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_TOTAL_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_TOTAL_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_TOTAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_TOTAL_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_GLOBAL_PAGE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_3D_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_3D_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_3D_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_STATUS_3D_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_GLOBAL_PAGE_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_DPM_REQUESTING */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTING_SOURCE_MASK     (0x00000003U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTING_SOURCE_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTING_SOURCE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTING_SOURCE_MAX      (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTING_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_DPM_DPLIST_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_ACTIVE_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_ACTIVE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_CORE_MASK    (0x30000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_CORE_SHIFT   (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_CORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_CORE_MAX     (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_PIM_MASK     (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_PIM_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_PIM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_PIM_MAX      (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_DPLIST_START_OF */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_ACTIVE_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_ACTIVE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_CORE_MASK  (0x30000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_CORE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_CORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_CORE_MAX   (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_PIM_MASK   (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_PIM_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_PIM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_PIM_MAX    (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DPLIST_START_OF_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_PAGE_MANAGEOP_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_STATUS_DISABLED_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_STATUS_DISABLED_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_STATUS_DISABLED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_STATUS_DISABLED_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PAGE_MANAGEOP_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_IDLE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_IDLE_STATUS_MASK           (0x000000FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_IDLE_STATUS_SHIFT          (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_IDLE_STATUS_RESETVAL       (0x000000ffU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_IDLE_STATUS_MAX            (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_IDLE_RESETVAL              (0x000000ffU)

/* EUR_CR_MASTER_DPM_DEBUG_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_WAIT_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_WAIT_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_WAIT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_WAIT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_SLEEP_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_SLEEP_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_SLEEP_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_SLEEP_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_DEADLOCK_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_DEADLOCK_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_DEADLOCK_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_OUTOFMEM_DEADLOCK_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEBUG_STATUS_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM0_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_MTE_MASK     (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_MTE_SHIFT    (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_MTE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_TE_MASK      (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_TE_SHIFT     (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_TE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_STATUS_MAX   (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM0_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM1_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_MTE_MASK     (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_MTE_SHIFT    (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_MTE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_TE_MASK      (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_TE_SHIFT     (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_TE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_STATUS_MAX   (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM1_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM2_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_MTE_MASK     (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_MTE_SHIFT    (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_MTE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_TE_MASK      (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_TE_SHIFT     (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_TE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_STATUS_MAX   (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM2_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM3_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_MTE_MASK     (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_MTE_SHIFT    (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_MTE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_TE_MASK      (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_TE_SHIFT     (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_TE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_STATUS_MAX   (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM3_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM4_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_MTE_MASK     (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_MTE_SHIFT    (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_MTE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_TE_MASK      (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_TE_SHIFT     (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_TE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_STATUS_MAX   (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM4_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM5_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_MTE_MASK     (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_MTE_SHIFT    (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_MTE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_TE_MASK      (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_TE_SHIFT     (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_TE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_STATUS_MAX   (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM5_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM6_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_MTE_MASK     (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_MTE_SHIFT    (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_MTE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_TE_MASK      (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_TE_SHIFT     (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_TE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_STATUS_MAX   (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM6_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM7_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_MTE_MASK     (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_MTE_SHIFT    (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_MTE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_TE_MASK      (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_TE_SHIFT     (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_TE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_STATUS_MAX   (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM7_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM8_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_MTE_MASK     (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_MTE_SHIFT    (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_MTE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_TE_MASK      (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_TE_SHIFT     (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_TE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_STATUS_MAX   (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM8_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM9_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_MTE_MASK     (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_MTE_SHIFT    (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_MTE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_TE_MASK      (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_TE_SHIFT     (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_TE_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_ACTIVE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_STATUS_MAX   (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM9_STATUS_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM10_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_MTE_MASK    (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_MTE_SHIFT   (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_MTE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_TE_MASK     (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_TE_SHIFT    (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_TE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM10_STATUS_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_DPM_NCPIM11_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_MTE_MASK    (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_MTE_SHIFT   (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_MTE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_TE_MASK     (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_TE_SHIFT    (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_TE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_NCPIM11_STATUS_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR0_PIM_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR1_PIM_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR2_PIM_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR3_PIM_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR4_PIM_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR5_PIM_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR6_PIM_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_REQUESTOR7_PIM_STATUS_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM0 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_MTE_MASK   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_MTE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_TE_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_TE_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_TE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM0_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM1 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_MTE_MASK   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_MTE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_TE_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_TE_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_TE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM1_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM2 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_MTE_MASK   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_MTE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_TE_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_TE_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_TE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM2_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM3 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_MTE_MASK   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_MTE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_TE_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_TE_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_TE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM3_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM4 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_MTE_MASK   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_MTE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_TE_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_TE_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_TE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM4_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM5 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_MTE_MASK   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_MTE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_TE_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_TE_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_TE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM5_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM6 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_MTE_MASK   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_MTE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_TE_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_TE_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_TE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM6_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM7 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_MTE_MASK   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_MTE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_TE_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_TE_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_TE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM7_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM8 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_MTE_MASK   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_MTE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_TE_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_TE_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_TE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM8_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM9 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_MTE_MASK   (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_MTE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_TE_MASK    (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_TE_SHIFT   (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_TE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM9_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM10 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_MTE_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_MTE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_TE_MASK   (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_TE_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_TE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM10_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_NCPIM11 */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_MTE_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_MTE_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_MTE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_MTE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_TE_MASK   (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_TE_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_TE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_TE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_NCPIM11_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR0_PIM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR1_PIM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR2_PIM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR3_PIM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR4_PIM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR5_PIM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR6_PIM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_PIM_END_MASK  (0x40000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_PIM_END_SHIFT  (30U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_PIM_END_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_PIM_END_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_TERM_MASK  (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_TERM_SHIFT  (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_TERM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_TERM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_ACTIVE_MASK  (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_ACTIVE_SHIFT  (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_ACTIVE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_ACTIVE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_STATUS_MASK  (0x0FFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_REQUESTOR7_PIM_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC_EN_N_MASK  (0x80000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC_EN_N_SHIFT  (31U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC_EN_N_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC_EN_N_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC_TIMOUT_CNT_MASK  (0x00001FFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC_TIMOUT_CNT_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC_TIMOUT_CNT_RESETVAL  (0x00001fffU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC_TIMOUT_CNT_MAX  (0x00001fffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PROACTIVE_PIM_SPEC_RESETVAL  (0x00001fffU)

/* EUR_CR_MASTER_DPM_MTILE_PARTI_PIM_TABLE_BASE_ADDR */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_PARTI_PIM_TABLE_BASE_ADDR_STATUS_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_PARTI_PIM_TABLE_BASE_ADDR_STATUS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_PARTI_PIM_TABLE_BASE_ADDR_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_PARTI_PIM_TABLE_BASE_ADDR_STATUS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_PARTI_PIM_TABLE_BASE_ADDR_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_PIMSHARE_RESERVE_PAGES */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PIMSHARE_RESERVE_PAGES_STATUS_MASK  (0x0001FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PIMSHARE_RESERVE_PAGES_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PIMSHARE_RESERVE_PAGES_STATUS_RESETVAL  (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PIMSHARE_RESERVE_PAGES_STATUS_MAX  (0x0001ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_PIMSHARE_RESERVE_PAGES_RESETVAL  (0x00010000U)

/* EUR_CR_MASTER_DPM_DRAIN_HEAP */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_TAIL_MASK       (0xFFFF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_TAIL_SHIFT      (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_TAIL_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_TAIL_MAX        (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_HEAD_MASK       (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_HEAD_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_HEAD_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_HEAD_MAX        (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_DPM_DRAIN_HEAP_FREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_FREE_PTR_MASK   (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_FREE_PTR_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_FREE_PTR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_FREE_PTR_MAX    (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_HEAP_FREE_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_DRAIN */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_RESUME_PULSE_MASK    (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_RESUME_PULSE_SHIFT   (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_RESUME_PULSE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_RESUME_PULSE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_START_PULSE_MASK     (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_START_PULSE_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_START_PULSE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_START_PULSE_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DRAIN_RESETVAL             (0x00000000U)

/* EUR_CR_MASTER_DPM_CONTEXT_DRAIN */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_BASE_ADDR_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_BASE_ADDR_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_BASE_ADDR_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_CONTEXT_DRAIN_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_MTE_FORCEREISSUE */

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FORCEREISSUE_ENABLE_N_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FORCEREISSUE_ENABLE_N_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FORCEREISSUE_ENABLE_N_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FORCEREISSUE_ENABLE_N_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_MTE_FORCEREISSUE_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_DPM_MTILE_ABORTED */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_ABORTED_MASK_MASK    (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_ABORTED_MASK_SHIFT   (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_ABORTED_MASK_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_ABORTED_MASK_MAX     (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_MTILE_ABORTED_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_DPM_TSP0_MTILEFREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_MTILEFREE_STATUS_MASK  (0x0001FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_MTILEFREE_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_MTILEFREE_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_MTILEFREE_STATUS_MAX  (0x0001ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_MTILEFREE_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_DPM_TSP1_MTILEFREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_MTILEFREE_STATUS_MASK  (0x0001FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_MTILEFREE_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_MTILEFREE_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_MTILEFREE_STATUS_MAX  (0x0001ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_MTILEFREE_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_DPM_TSP2_MTILEFREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_MTILEFREE_STATUS_MASK  (0x0001FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_MTILEFREE_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_MTILEFREE_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_MTILEFREE_STATUS_MAX  (0x0001ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_MTILEFREE_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_DPM_TSP3_MTILEFREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_MTILEFREE_STATUS_MASK  (0x0001FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_MTILEFREE_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_MTILEFREE_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_MTILEFREE_STATUS_MAX  (0x0001ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_MTILEFREE_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_DPM_TSP0_START_OF_MTILEFREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_START_OF_MTILEFREE_STATUS_MASK  (0x0001FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_START_OF_MTILEFREE_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_START_OF_MTILEFREE_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_START_OF_MTILEFREE_STATUS_MAX  (0x0001ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP0_START_OF_MTILEFREE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_TSP1_START_OF_MTILEFREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_START_OF_MTILEFREE_STATUS_MASK  (0x0001FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_START_OF_MTILEFREE_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_START_OF_MTILEFREE_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_START_OF_MTILEFREE_STATUS_MAX  (0x0001ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP1_START_OF_MTILEFREE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_TSP2_START_OF_MTILEFREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_START_OF_MTILEFREE_STATUS_MASK  (0x0001FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_START_OF_MTILEFREE_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_START_OF_MTILEFREE_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_START_OF_MTILEFREE_STATUS_MAX  (0x0001ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP2_START_OF_MTILEFREE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_TSP3_START_OF_MTILEFREE */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_START_OF_MTILEFREE_STATUS_MASK  (0x0001FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_START_OF_MTILEFREE_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_START_OF_MTILEFREE_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_START_OF_MTILEFREE_STATUS_MAX  (0x0001ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_TSP3_START_OF_MTILEFREE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_DPM_DEALLOCATE_MASK */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEALLOCATE_MASK_STATUS_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEALLOCATE_MASK_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEALLOCATE_MASK_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEALLOCATE_MASK_STATUS_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_DEALLOCATE_MASK_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_DPM_START_OF_DEALLOCATE_MASK */

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_DEALLOCATE_MASK_STATUS_MASK  (0x0000FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_DEALLOCATE_MASK_STATUS_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_DEALLOCATE_MASK_STATUS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_DEALLOCATE_MASK_STATUS_MAX  (0x0000ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_DPM_START_OF_DEALLOCATE_MASK_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_BIF_CTRL */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_DPM_MASK  (0x00080000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_DPM_SHIFT  (19U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_DPM_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_DPM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_IPF_MASK  (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_IPF_SHIFT  (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_IPF_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_IPF_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_VDM_MASK  (0x00020000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_VDM_SHIFT  (17U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_VDM_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_MASTER_VDM_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_PTLA_MASK  (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_PTLA_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_PTLA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_MMU_BYPASS_PTLA_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_CLEAR_FAULT_MASK      (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_CLEAR_FAULT_SHIFT     (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_CLEAR_FAULT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_CLEAR_FAULT_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_PAUSE_MASK            (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_PAUSE_SHIFT           (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_PAUSE_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_PAUSE_MAX             (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_NOREORDER_MASK        (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_NOREORDER_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_NOREORDER_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_NOREORDER_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_RESETVAL              (0x000e0000U)

/* EUR_CR_MASTER_BIF_INT_STAT */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FLUSH_COMPLETE_MASK  (0x00080000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FLUSH_COMPLETE_SHIFT  (19U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FLUSH_COMPLETE_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FLUSH_COMPLETE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FAULT_TYPE_MASK   (0x00070000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FAULT_TYPE_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FAULT_TYPE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FAULT_TYPE_MAX    (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FAULT_REQ_MASK    (0x00003FFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FAULT_REQ_SHIFT   (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FAULT_REQ_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_FAULT_REQ_MAX     (0x00003fffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_INT_STAT_RESETVAL          (0x00080000U)

/* EUR_CR_MASTER_BIF_FAULT */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_ADDR_MASK            (0xFFFFF000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_ADDR_SHIFT           (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_ADDR_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_ADDR_MAX             (0x000fffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_SB_MASK              (0x000001F0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_SB_SHIFT             (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_SB_RESETVAL          (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_SB_MAX               (0x0000001fU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_CID_MASK             (0x0000000FU)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_CID_SHIFT            (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_CID_RESETVAL         (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_CID_MAX              (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_FAULT_RESETVAL             (0x00000000U)

/* EUR_CR_MASTER_BIF_CTRL_INVAL */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_INVAL_ALL_MASK        (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_INVAL_ALL_SHIFT       (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_INVAL_ALL_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_INVAL_ALL_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_INVAL_PTE_MASK        (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_INVAL_PTE_SHIFT       (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_INVAL_PTE_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_INVAL_PTE_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_CTRL_INVAL_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE0 */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE0_ADDR_MASK   (0xFFFFF000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE0_ADDR_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE0_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE0_ADDR_MAX    (0x000fffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE0_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE1 */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE1_ADDR_MASK   (0xFFFFF000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE1_ADDR_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE1_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE1_ADDR_MAX    (0x000fffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE1_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE2 */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE2_ADDR_MASK   (0xFFFFF000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE2_ADDR_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE2_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE2_ADDR_MAX    (0x000fffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE2_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE3 */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE3_ADDR_MASK   (0xFFFFF000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE3_ADDR_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE3_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE3_ADDR_MAX    (0x000fffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE3_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE4 */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE4_ADDR_MASK   (0xFFFFF000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE4_ADDR_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE4_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE4_ADDR_MAX    (0x000fffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE4_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE5 */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE5_ADDR_MASK   (0xFFFFF000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE5_ADDR_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE5_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE5_ADDR_MAX    (0x000fffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE5_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE6 */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE6_ADDR_MASK   (0xFFFFF000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE6_ADDR_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE6_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE6_ADDR_MAX    (0x000fffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE6_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_BIF_DIR_LIST_BASE7 */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE7_ADDR_MASK   (0xFFFFF000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE7_ADDR_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE7_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE7_ADDR_MAX    (0x000fffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_DIR_LIST_BASE7_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_BIF_BANK_SET */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_DPM_LSS_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_DPM_LSS_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_DPM_LSS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_DPM_LSS_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_TA_MASK    (0x000000C0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_TA_SHIFT   (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_TA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_TA_MAX     (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_3D_MASK    (0x0000000CU)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_3D_SHIFT   (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_3D_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_SELECT_3D_MAX     (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_SET_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_BIF_BANK0 */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_PTLA_MASK      (0x000F0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_PTLA_SHIFT     (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_PTLA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_PTLA_MAX       (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_3D_MASK        (0x0000F000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_3D_SHIFT       (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_3D_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_3D_MAX         (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_TA_MASK        (0x000000F0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_TA_SHIFT       (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_TA_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_INDEX_TA_MAX         (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK0_RESETVAL             (0x00000000U)

/* EUR_CR_MASTER_BIF_BANK1 */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK1_INDEX_3D_MASK        (0x0000F000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK1_INDEX_3D_SHIFT       (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK1_INDEX_3D_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK1_INDEX_3D_MAX         (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK1_INDEX_TA_MASK        (0x000000F0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK1_INDEX_TA_SHIFT       (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK1_INDEX_TA_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK1_INDEX_TA_MAX         (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK1_RESETVAL             (0x00000000U)

/* EUR_CR_MASTER_BIF_BANK_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_STATUS_TA_CURRENT_BANK_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_STATUS_TA_CURRENT_BANK_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_STATUS_TA_CURRENT_BANK_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_STATUS_TA_CURRENT_BANK_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_STATUS_THREED_CURRENT_BANK_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_STATUS_THREED_CURRENT_BANK_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_STATUS_THREED_CURRENT_BANK_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_STATUS_THREED_CURRENT_BANK_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_BANK_STATUS_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_BIF_MEM_REQ_STAT */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MEM_REQ_STAT_READS_MASK    (0x000000FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MEM_REQ_STAT_READS_SHIFT   (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MEM_REQ_STAT_READS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MEM_REQ_STAT_READS_MAX     (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MEM_REQ_STAT_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_BIF_3D_REQ_BASE */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_3D_REQ_BASE_ADDR_MASK      (0xFFF00000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_3D_REQ_BASE_ADDR_SHIFT     (20U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_3D_REQ_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_3D_REQ_BASE_ADDR_MAX       (0x00000fffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_3D_REQ_BASE_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_BIF_MMU_CTRL */

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_ENABLE_DC_TLB_MASK  (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_ENABLE_DC_TLB_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_ENABLE_DC_TLB_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_ENABLE_DC_TLB_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_ADDR_HASH_MODE_MASK  (0x00000006U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_ADDR_HASH_MODE_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_ADDR_HASH_MODE_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_ADDR_HASH_MODE_MAX  (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_PREFETCHING_ON_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_PREFETCHING_ON_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_PREFETCHING_ON_RESETVAL  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_PREFETCHING_ON_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BIF_MMU_CTRL_RESETVAL          (0x00000013U)

/* EUR_CR_MASTER_SLC_CTRL */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DISABLE_REORDERING_MASK  (0x00800000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DISABLE_REORDERING_SHIFT  (23U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DISABLE_REORDERING_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DISABLE_REORDERING_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DISABLE_BURST_EXP_MASK  (0x00400000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DISABLE_BURST_EXP_SHIFT  (22U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DISABLE_BURST_EXP_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DISABLE_BURST_EXP_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ3_MASK  (0x00200000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ3_SHIFT  (21U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ3_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ3_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ2_MASK  (0x00100000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ2_SHIFT  (20U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ2_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ2_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ1_MASK  (0x00080000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ1_SHIFT  (19U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ1_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ1_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ0_MASK  (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ0_SHIFT  (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ0_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_REQ0_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DM_REF_SET_ALL_MASK   (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DM_REF_SET_ALL_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DM_REF_SET_ALL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_DM_REF_SET_ALL_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_ARB_PAGE_SIZE_MASK    (0x0000F000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_ARB_PAGE_SIZE_SHIFT   (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_ARB_PAGE_SIZE_RESETVAL  (0x0000000cU)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_ARB_PAGE_SIZE_MAX     (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_ADDR_DECODE_MODE_MASK  (0x00000E00U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_ADDR_DECODE_MODE_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_ADDR_DECODE_MODE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_ADDR_DECODE_MODE_MAX  (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_PAUSE_MASK            (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_PAUSE_SHIFT           (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_PAUSE_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_PAUSE_MAX             (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_RESETVAL              (0x0000c000U)

/* EUR_CR_MASTER_SLC_CTRL_BYPASS */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_BYP_CC_N_MASK  (0x08000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_BYP_CC_N_SHIFT  (27U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_BYP_CC_N_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_BYP_CC_N_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_BYP_CC_MASK    (0x04000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_BYP_CC_SHIFT   (26U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_BYP_CC_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_BYP_CC_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE4_MASK     (0x02000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE4_SHIFT    (25U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE4_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE4_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE3_MASK     (0x01000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE3_SHIFT    (24U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE3_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE3_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE2_MASK     (0x00800000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE2_SHIFT    (23U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE2_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE2_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE1_MASK     (0x00400000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE1_SHIFT    (22U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE1_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE1_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE0_MASK     (0x00200000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE0_SHIFT    (21U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE0_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_CORE0_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PTLA_MASK  (0x00100000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PTLA_SHIFT  (20U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PTLA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PTLA_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_ISP2_RCIF_MASK  (0x00080000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_ISP2_RCIF_SHIFT  (19U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_ISP2_RCIF_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_ISP2_RCIF_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_ZLS_MASK   (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_ZLS_SHIFT  (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_ZLS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_ZLS_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PBE_MASK   (0x00020000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PBE_SHIFT  (17U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PBE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PBE_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_VDM_MASK   (0x00010000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_VDM_SHIFT  (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_VDM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_VDM_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_IPF_MASK   (0x00008000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_IPF_SHIFT  (15U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_IPF_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_IPF_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PDS_MASK   (0x00004000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PDS_SHIFT  (14U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PDS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_PDS_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USEC_MASK  (0x00002000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USEC_SHIFT  (13U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USEC_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USEC_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE3_MASK  (0x00001000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE3_SHIFT  (12U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE3_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE3_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE2_MASK  (0x00000800U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE2_SHIFT  (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE2_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE2_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE1_MASK  (0x00000400U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE1_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE1_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE1_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE0_MASK  (0x00000200U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE0_SHIFT  (9U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE0_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_USE0_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_IPF_OBJ_MASK  (0x00000100U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_IPF_OBJ_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_IPF_OBJ_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_IPF_OBJ_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_TPF_MASK   (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_TPF_SHIFT  (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_TPF_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_TPF_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_TA_MASK    (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_TA_SHIFT   (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_TA_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_TA_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_CACHE_MASK  (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_CACHE_SHIFT  (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_CACHE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_CACHE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_MMU_MASK   (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_MMU_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_MMU_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_REQ_MMU_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_EVENT_MASK  (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_EVENT_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_EVENT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_EVENT_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_PIXEL_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_PIXEL_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_PIXEL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_PIXEL_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_VERTEX_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_VERTEX_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_VERTEX_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_DM_VERTEX_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_ALL_MASK       (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_ALL_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_ALL_RESETVAL   (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_ALL_MAX        (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_BYPASS_RESETVAL       (0x00000001U)

/* EUR_CR_MASTER_SLC_CTRL_USSE_INVAL */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_ADDR_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_ADDR_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_ADDR_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_ADDR_MAX   (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_USSE_INVAL_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_SLC_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS3_MASK         (0xFF000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS3_SHIFT        (24U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS3_RESETVAL     (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS3_MAX          (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS2_MASK         (0x00FF0000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS2_SHIFT        (16U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS2_RESETVAL     (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS2_MAX          (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS1_MASK         (0x0000FF00U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS1_SHIFT        (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS1_RESETVAL     (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS1_MAX          (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS0_MASK         (0x000000FFU)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS0_SHIFT        (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS0_RESETVAL     (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_READS0_MAX          (0x000000ffU)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS_RESETVAL            (0x00000000U)

/* EUR_CR_MASTER_SLC_STATUS2 */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS2_BYPASS_MASK        (0x20000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS2_BYPASS_SHIFT       (29U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS2_BYPASS_RESETVAL    (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS2_BYPASS_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS2_PAUSED_MASK        (0x10000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS2_PAUSED_SHIFT       (28U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS2_PAUSED_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS2_PAUSED_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATUS2_RESETVAL           (0x20000000U)

/* EUR_CR_MASTER_SLC_EVENT_STATUS */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_FLUSH_INV_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_FLUSH_INV_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_FLUSH_INV_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_FLUSH_INV_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_FLUSH_MASK    (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_FLUSH_SHIFT   (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_FLUSH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_FLUSH_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_INVAL_MASK    (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_INVAL_SHIFT   (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_INVAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_INVAL_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_STATUS_RESETVAL      (0x00000000U)

/* EUR_CR_MASTER_SLC_EVENT_CLEAR */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_FLUSH_INV_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_FLUSH_INV_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_FLUSH_INV_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_FLUSH_INV_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_FLUSH_MASK     (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_FLUSH_SHIFT    (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_FLUSH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_FLUSH_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_INVAL_MASK     (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_INVAL_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_INVAL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_INVAL_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_EVENT_CLEAR_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_SLC_STATS0 */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_STOP_MASK           (0x00100000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_STOP_SHIFT          (20U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_STOP_RESETVAL       (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_STOP_MAX            (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_RESET_MASK          (0x00080000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_RESET_SHIFT         (19U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_RESET_RESETVAL      (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_RESET_MAX           (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_RNW_MASK            (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_RNW_SHIFT           (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_RNW_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_RNW_MAX             (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_NC_MASK             (0x00020000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_NC_SHIFT            (17U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_NC_RESETVAL         (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_NC_MAX              (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_DM_MASK             (0x00018000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_DM_SHIFT            (15U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_DM_RESETVAL         (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_DM_MAX              (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TAG_ID_MASK         (0x00007800U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TAG_ID_SHIFT        (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TAG_ID_RESETVAL     (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TAG_ID_MAX          (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_CORE_ID_MASK        (0x00000700U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_CORE_ID_SHIFT       (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_CORE_ID_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_CORE_ID_MAX         (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_CORE_MASK    (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_CORE_SHIFT   (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_CORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_CORE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_TAGID_MASK   (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_TAGID_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_TAGID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_TAGID_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_DM_MASK      (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_DM_SHIFT     (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_DM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_DM_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_NC_MASK      (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_NC_SHIFT     (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_NC_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_NC_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_RNW_MASK     (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_RNW_SHIFT    (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_RNW_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_SELECT_RNW_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_FLUSH_MASK     (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_FLUSH_SHIFT    (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_FLUSH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_FLUSH_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_MISS_MASK      (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_MISS_SHIFT     (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_MISS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_MISS_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_HIT_MASK       (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_HIT_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_HIT_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_TYPE_HIT_MAX        (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_RESETVAL            (0x00000000U)

/* EUR_CR_MASTER_SLC_STATS0_OUTPUT */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_OUTPUT_VALUE_MASK   (0x0003FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_OUTPUT_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_OUTPUT_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_OUTPUT_VALUE_MAX    (0x0003ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS0_OUTPUT_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_SLC_STATS1 */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_STOP_MASK           (0x00100000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_STOP_SHIFT          (20U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_STOP_RESETVAL       (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_STOP_MAX            (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_RESET_MASK          (0x00080000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_RESET_SHIFT         (19U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_RESET_RESETVAL      (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_RESET_MAX           (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_RNW_MASK            (0x00040000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_RNW_SHIFT           (18U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_RNW_RESETVAL        (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_RNW_MAX             (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_NC_MASK             (0x00020000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_NC_SHIFT            (17U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_NC_RESETVAL         (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_NC_MAX              (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_DM_MASK             (0x00018000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_DM_SHIFT            (15U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_DM_RESETVAL         (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_DM_MAX              (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TAG_ID_MASK         (0x00007800U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TAG_ID_SHIFT        (11U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TAG_ID_RESETVAL     (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TAG_ID_MAX          (0x0000000fU)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_CORE_ID_MASK        (0x00000700U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_CORE_ID_SHIFT       (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_CORE_ID_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_CORE_ID_MAX         (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_CORE_MASK    (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_CORE_SHIFT   (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_CORE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_CORE_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_TAGID_MASK   (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_TAGID_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_TAGID_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_TAGID_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_DM_MASK      (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_DM_SHIFT     (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_DM_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_DM_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_NC_MASK      (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_NC_SHIFT     (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_NC_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_NC_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_RNW_MASK     (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_RNW_SHIFT    (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_RNW_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_SELECT_RNW_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_FLUSH_MASK     (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_FLUSH_SHIFT    (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_FLUSH_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_FLUSH_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_MISS_MASK      (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_MISS_SHIFT     (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_MISS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_MISS_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_HIT_MASK       (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_HIT_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_HIT_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_TYPE_HIT_MAX        (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_RESETVAL            (0x00000000U)

/* EUR_CR_MASTER_SLC_STATS1_OUTPUT */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_OUTPUT_VALUE_MASK   (0x0003FFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_OUTPUT_VALUE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_OUTPUT_VALUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_OUTPUT_VALUE_MAX    (0x0003ffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_STATS1_OUTPUT_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_SLC_CTRL_INVAL */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_EVENT_MASK   (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_EVENT_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_EVENT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_EVENT_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_PIXEL_MASK   (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_PIXEL_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_PIXEL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_PIXEL_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_VERTEX_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_VERTEX_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_VERTEX_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_DM_VERTEX_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_ALL_MASK        (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_ALL_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_ALL_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_ALL_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_INVAL_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_SLC_CTRL_FLUSH */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_EVENT_MASK   (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_EVENT_SHIFT  (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_EVENT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_EVENT_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_PIXEL_MASK   (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_PIXEL_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_PIXEL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_PIXEL_MAX    (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_VERTEX_MASK  (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_VERTEX_SHIFT  (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_VERTEX_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_DM_VERTEX_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_ALL_MASK        (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_ALL_SHIFT       (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_ALL_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_ALL_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_SLC_CTRL_FLUSH_INV */

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_EVENT_MASK  (0x00000080U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_EVENT_SHIFT  (7U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_EVENT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_EVENT_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_PIXEL_MASK  (0x00000040U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_PIXEL_SHIFT  (6U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_PIXEL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_PIXEL_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_VERTEX_MASK  (0x00000020U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_VERTEX_SHIFT  (5U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_VERTEX_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_DM_VERTEX_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_ALL_MASK    (0x00000010U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_ALL_SHIFT   (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_ALL_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_ALL_MAX     (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_SLC_CTRL_FLUSH_INV_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_EMU_CYCLE_COUNT */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_CYCLE_COUNT_RESET_MASK     (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_CYCLE_COUNT_RESET_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_CYCLE_COUNT_RESET_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_CYCLE_COUNT_RESET_MAX      (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_CYCLE_COUNT_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_EMU_TA_PHASE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_PHASE_COUNT_MASK        (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_PHASE_COUNT_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_PHASE_COUNT_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_PHASE_COUNT_MAX         (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_PHASE_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_EMU_3D_PHASE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_PHASE_COUNT_MASK        (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_PHASE_COUNT_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_PHASE_COUNT_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_PHASE_COUNT_MAX         (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_PHASE_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_EMU_TA_CYCLE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_CYCLE_COUNT_MASK        (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_CYCLE_COUNT_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_CYCLE_COUNT_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_CYCLE_COUNT_MAX         (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_CYCLE_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_EMU_3D_CYCLE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_CYCLE_COUNT_MASK        (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_CYCLE_COUNT_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_CYCLE_COUNT_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_CYCLE_COUNT_MAX         (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_3D_CYCLE_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_EMU_INITIAL_TA_CYCLE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_INITIAL_TA_CYCLE_COUNT_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_INITIAL_TA_CYCLE_COUNT_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_INITIAL_TA_CYCLE_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_INITIAL_TA_CYCLE_COUNT_MAX  (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_INITIAL_TA_CYCLE_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_EMU_FINAL_3D_CYCLE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_FINAL_3D_CYCLE_COUNT_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_FINAL_3D_CYCLE_COUNT_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_FINAL_3D_CYCLE_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_FINAL_3D_CYCLE_COUNT_MAX   (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_FINAL_3D_CYCLE_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM_READ */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_READ_COUNT_MASK        (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_READ_COUNT_SHIFT       (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_READ_COUNT_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_READ_COUNT_MAX         (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_READ_RESETVAL          (0x00000000U)

/* EUR_CR_MASTER_EMU_TA_OR_3D_CYCLE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_OR_3D_CYCLE_COUNT_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_OR_3D_CYCLE_COUNT_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_OR_3D_CYCLE_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_OR_3D_CYCLE_COUNT_MAX   (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_TA_OR_3D_CYCLE_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM_WRITE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_WRITE_COUNT_MASK       (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_WRITE_COUNT_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_WRITE_COUNT_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_WRITE_COUNT_MAX        (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_WRITE_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM_BYTE_WRITE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_BYTE_WRITE_COUNT_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_BYTE_WRITE_COUNT_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_BYTE_WRITE_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_BYTE_WRITE_COUNT_MAX   (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_BYTE_WRITE_RESETVAL    (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM1_READ */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_READ_COUNT_MASK       (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_READ_COUNT_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_READ_COUNT_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_READ_COUNT_MAX        (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_READ_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM1_WRITE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_WRITE_COUNT_MASK      (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_WRITE_COUNT_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_WRITE_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_WRITE_COUNT_MAX       (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_WRITE_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM1_BYTE_WRITE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_BYTE_WRITE_COUNT_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_BYTE_WRITE_COUNT_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_BYTE_WRITE_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_BYTE_WRITE_COUNT_MAX  (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_BYTE_WRITE_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM2_READ */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_READ_COUNT_MASK       (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_READ_COUNT_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_READ_COUNT_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_READ_COUNT_MAX        (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_READ_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM2_WRITE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_WRITE_COUNT_MASK      (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_WRITE_COUNT_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_WRITE_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_WRITE_COUNT_MAX       (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_WRITE_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM2_BYTE_WRITE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_BYTE_WRITE_COUNT_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_BYTE_WRITE_COUNT_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_BYTE_WRITE_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_BYTE_WRITE_COUNT_MAX  (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_BYTE_WRITE_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM3_READ */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_READ_COUNT_MASK       (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_READ_COUNT_SHIFT      (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_READ_COUNT_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_READ_COUNT_MAX        (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_READ_RESETVAL         (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM3_WRITE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_WRITE_COUNT_MASK      (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_WRITE_COUNT_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_WRITE_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_WRITE_COUNT_MAX       (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_WRITE_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM3_BYTE_WRITE */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_BYTE_WRITE_COUNT_MASK  (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_BYTE_WRITE_COUNT_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_BYTE_WRITE_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_BYTE_WRITE_COUNT_MAX  (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_BYTE_WRITE_RESETVAL   (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT0_START */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_START_ADDRESS_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_START_ADDRESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_START_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_START_ADDRESS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_START_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT0_END */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_END_ADDRESS_MASK   (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_END_ADDRESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_END_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_END_ADDRESS_MAX    (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_END_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT0 */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_MASK_DM_MASK       (0x00000070U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_MASK_DM_SHIFT      (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_MASK_DM_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_MASK_DM_MAX        (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_TRAPENABLE_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_TRAPENABLE_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_TRAPENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_TRAPENABLE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_WENABLE_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_WENABLE_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_WENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_WENABLE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_RENABLE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_RENABLE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_RENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_CTRL_RENABLE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT0_RESETVAL           (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT1_START */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_START_ADDRESS_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_START_ADDRESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_START_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_START_ADDRESS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_START_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT1_END */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_END_ADDRESS_MASK   (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_END_ADDRESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_END_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_END_ADDRESS_MAX    (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_END_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT1 */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_MASK_DM_MASK       (0x00000070U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_MASK_DM_SHIFT      (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_MASK_DM_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_MASK_DM_MAX        (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_TRAPENABLE_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_TRAPENABLE_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_TRAPENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_TRAPENABLE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_WENABLE_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_WENABLE_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_WENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_WENABLE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_RENABLE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_RENABLE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_RENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_CTRL_RENABLE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT1_RESETVAL           (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT2_START */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_START_ADDRESS_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_START_ADDRESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_START_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_START_ADDRESS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_START_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT2_END */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_END_ADDRESS_MASK   (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_END_ADDRESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_END_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_END_ADDRESS_MAX    (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_END_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT2 */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_MASK_DM_MASK       (0x00000070U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_MASK_DM_SHIFT      (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_MASK_DM_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_MASK_DM_MAX        (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_TRAPENABLE_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_TRAPENABLE_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_TRAPENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_TRAPENABLE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_WENABLE_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_WENABLE_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_WENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_WENABLE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_RENABLE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_RENABLE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_RENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_CTRL_RENABLE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT2_RESETVAL           (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT3_START */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_START_ADDRESS_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_START_ADDRESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_START_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_START_ADDRESS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_START_RESETVAL     (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT3_END */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_END_ADDRESS_MASK   (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_END_ADDRESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_END_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_END_ADDRESS_MAX    (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_END_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT3 */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_MASK_DM_MASK       (0x00000070U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_MASK_DM_SHIFT      (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_MASK_DM_RESETVAL   (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_MASK_DM_MAX        (0x00000007U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_TRAPENABLE_MASK  (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_TRAPENABLE_SHIFT  (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_TRAPENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_TRAPENABLE_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_WENABLE_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_WENABLE_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_WENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_WENABLE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_RENABLE_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_RENABLE_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_RENABLE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_CTRL_RENABLE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT3_RESETVAL           (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT_READ */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_READ_ADDRESS_MASK   (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_READ_ADDRESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_READ_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_READ_ADDRESS_MAX    (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_READ_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT_TRAP */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_CONTINUE_MASK  (0x00000002U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_CONTINUE_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_CONTINUE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_CONTINUE_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_WRNOTIFY_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_WRNOTIFY_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_WRNOTIFY_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_WRNOTIFY_MAX   (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_ID_MASK             (0x00000030U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_ID_SHIFT            (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_ID_RESETVAL         (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_ID_MAX              (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_UNTRAPPED_MASK      (0x00000008U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_UNTRAPPED_SHIFT     (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_UNTRAPPED_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_UNTRAPPED_MAX       (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAPPED_MASK        (0x00000004U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAPPED_SHIFT       (2U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAPPED_RESETVAL    (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAPPED_MAX         (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_RESETVAL            (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT_TRAP_INFO0 */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO0_ADDRESS_MASK  (0xFFFFFFF0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO0_ADDRESS_SHIFT  (4U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO0_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO0_ADDRESS_MAX  (0x0fffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO0_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1 */

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_SIZE_MASK  (0x00007C00U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_SIZE_SHIFT  (10U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_SIZE_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_SIZE_MAX  (0x0000001fU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_NUMBER_MASK  (0x00000300U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_NUMBER_SHIFT  (8U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_NUMBER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_NUMBER_MAX  (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_TAG_MASK  (0x000000F8U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_TAG_SHIFT  (3U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_TAG_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_TAG_MAX  (0x0000001fU)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_DATA_MASTER_MASK  (0x00000006U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_DATA_MASTER_SHIFT  (1U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_DATA_MASTER_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_DATA_MASTER_MAX  (0x00000003U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_RNW_MASK  (0x00000001U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_RNW_SHIFT  (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_RNW_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_RNW_MAX  (0x00000001U)

#define CSL_HYDRA2_EUR_CR_MASTER_BREAKPOINT_TRAP_INFO1_RESETVAL  (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM_STALLS */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_STALLS_COUNT_MASK      (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_STALLS_COUNT_SHIFT     (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_STALLS_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_STALLS_COUNT_MAX       (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM_STALLS_RESETVAL        (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM1_STALLS */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_STALLS_COUNT_MASK     (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_STALLS_COUNT_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_STALLS_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_STALLS_COUNT_MAX      (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM1_STALLS_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM2_STALLS */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_STALLS_COUNT_MASK     (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_STALLS_COUNT_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_STALLS_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_STALLS_COUNT_MAX      (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM2_STALLS_RESETVAL       (0x00000000U)

/* EUR_CR_MASTER_EMU_MEM3_STALLS */

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_STALLS_COUNT_MASK     (0xFFFFFFFFU)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_STALLS_COUNT_SHIFT    (0U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_STALLS_COUNT_RESETVAL  (0x00000000U)
#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_STALLS_COUNT_MAX      (0xffffffffU)

#define CSL_HYDRA2_EUR_CR_MASTER_EMU_MEM3_STALLS_RESETVAL       (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
