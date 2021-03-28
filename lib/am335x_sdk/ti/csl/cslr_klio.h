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
#ifndef CSLR_KLIO_H_
#define CSLR_KLIO_H_

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
    volatile Uint32 EUR_CR_CLKGATECTL;
    volatile Uint32 EUR_CR_CLKGATECTL2;
    volatile Uint32 EUR_CR_CLKGATESTATUS;
    volatile Uint32 EUR_CR_CLKGATECTLOVR;
    volatile Uint32 EUR_CR_CLKGATECTLOVR2;
    volatile Uint8  RSVD0[8];
    volatile Uint32 EUR_CR_POWER;
    volatile Uint32 EUR_CR_CORE_ID;
    volatile Uint32 EUR_CR_CORE_REVISION;
    volatile Uint32 EUR_CR_DESIGNER_REV_FIELD1;
    volatile Uint32 EUR_CR_DESIGNER_REV_FIELD2;
    volatile Uint8  RSVD1[16];
    volatile Uint32 EUR_CR_PERF;
    volatile Uint32 EUR_CR_PERF_COUNTER0;
    volatile Uint32 EUR_CR_PERF_COUNTER1;
    volatile Uint32 EUR_CR_PERF_COUNTER2;
    volatile Uint32 EUR_CR_PERF_COUNTER3;
    volatile Uint32 EUR_CR_PERF_COUNTER4;
    volatile Uint32 EUR_CR_PERF_COUNTER5;
    volatile Uint32 EUR_CR_PERF_COUNTER6;
    volatile Uint32 EUR_CR_PERF_COUNTER7;
    volatile Uint32 EUR_CR_PERF_COUNTER_BIT;
    volatile Uint8  RSVD2[8];
    volatile Uint32 EUR_CR_DEBUG_REG0;
    volatile Uint32 EUR_CR_DEBUG_REG1;
    volatile Uint32 EUR_CR_PERF_DEBUG_CTRL;
    volatile Uint8  RSVD3[4];
    volatile Uint32 EUR_CR_SOFT_RESET;
    volatile Uint8  RSVD4[124];
    volatile Uint32 EUR_CR_TRIGGER;
    volatile Uint8  RSVD5[12];
    volatile Uint32 EUR_CR_EVENT_HOST_ENABLE2;
    volatile Uint32 EUR_CR_EVENT_HOST_CLEAR2;
    volatile Uint32 EUR_CR_EVENT_STATUS2;
    volatile Uint8  RSVD6[16];
    volatile Uint32 EUR_CR_EVENT_STATUS;
    volatile Uint32 EUR_CR_EVENT_HOST_ENABLE;
    volatile Uint32 EUR_CR_EVENT_HOST_CLEAR;
    volatile Uint32 EUR_CR_PDS_CACHE_STATUS;
    volatile Uint32 EUR_CR_PDS_CACHE_HOST_ENABLE;
    volatile Uint32 EUR_CR_PDS_CACHE_HOST_CLEAR;
    volatile Uint32 EUR_CR_TIMER;
    volatile Uint32 EUR_CR_DOUBLE_PIXEL_PARTITIONS;
    volatile Uint8  RSVD7[180];
    volatile Uint32 EUR_CR_VDM_START;
    volatile Uint32 EUR_CR_TE_AA;
    volatile Uint32 EUR_CR_TE_MTILE1;
    volatile Uint32 EUR_CR_TE_MTILE2;
    volatile Uint32 EUR_CR_TE_SCREEN;
    volatile Uint32 EUR_CR_TE_MTILE;
    volatile Uint32 EUR_CR_TE_PSG;
    volatile Uint32 EUR_CR_TE_PSGREGION_BASE;
    volatile Uint32 EUR_CR_TE_TPC_BASE;
    volatile Uint32 EUR_CR_TE_TPCCONTROL;
    volatile Uint32 EUR_CR_TE_RGNBBOX_X;
    volatile Uint32 EUR_CR_TE_RGNBBOX_Y;
    volatile Uint32 EUR_CR_MTE_OTPM_CSM_FLUSH_BASE;
    volatile Uint32 EUR_CR_MTE_OTPM_CSM_LOAD_BASE;
    volatile Uint32 EUR_CR_VDM_CTRL_STREAM_BASE;
    volatile Uint32 EUR_CR_MTE_CTRL;
    volatile Uint32 EUR_CR_MTE_WCOMPARE;
    volatile Uint32 EUR_CR_MTE_WCLAMP;
    volatile Uint32 EUR_CR_MTE_SCREEN;
    volatile Uint32 EUR_CR_MTE_OTPM_OP;
    volatile Uint32 EUR_CR_MTE_MULTISAMPLECTL;
    volatile Uint32 EUR_CR_TA_MEM_TE_PAD;
    volatile Uint32 EUR_CR_MTE_FIRST_PAGE;
    volatile Uint32 EUR_CR_MTE_SECOND_PAGE;
    volatile Uint32 EUR_CR_MTE_ABORT;
    volatile Uint8  RSVD8[8];
    volatile Uint32 EUR_CR_MTE_SIG1;
    volatile Uint32 EUR_CR_MTE_SIG2;
    volatile Uint32 EUR_CR_TE_STATE;
    volatile Uint8  RSVD9[8];
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_SNAPSHOT;
    volatile Uint32 EUR_CR_VDM_CONTEXT_LOAD_START;
    volatile Uint32 EUR_CR_VDM_CONTEXT_LOAD_STATUS;
    volatile Uint32 EUR_CR_VDM_CONTEXT_LOAD_STATUS_CLEAR;
    volatile Uint32 EUR_CR_VDM_TASK_KICK;
    volatile Uint32 EUR_CR_VDM_TASK_KICK_STATUS;
    volatile Uint32 EUR_CR_VDM_TASK_KICK_STATUS_CLEAR;
    volatile Uint32 EUR_CR_TE_SAFE;
    volatile Uint8  RSVD10[100];
    volatile Uint32 EUR_CR_CLIP_SIG1;
    volatile Uint8  RSVD11[4];
    volatile Uint32 EUR_CR_PBE_NONPIXEL_CHECKSUM;
    volatile Uint32 EUR_CR_TA_CLK_GATE;
    volatile Uint8  RSVD12[12];
    volatile Uint32 EUR_CR_VDM_BATCH_NUM;
    volatile Uint32 EUR_CR_VDM_BATCH_NUM_STATUS;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD0;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD1;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_START;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_STREAM;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_STATUS;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_STATE0;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_STATE1;
    volatile Uint32 EUR_CR_VDM_WAIT_FOR_KICK;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_WRAP_INDEX;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_WRAPPED;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX;
    volatile Uint32 EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME;
    volatile Uint8  RSVD13[28];
    volatile Uint32 EUR_CR_VDM_MTE;
    volatile Uint32 EUR_CR_MTE_STATE;
    volatile Uint32 EUR_CR_TE_RGNHDR_INIT;
    volatile Uint32 EUR_CR_MTE_STATE_FLUSH_BASE;
    volatile Uint32 EUR_CR_MTE_FIXED_POINT;
    volatile Uint32 EUR_CR_TA_CONTEXT;
    volatile Uint32 EUR_CR_VDM_FENCE;
    volatile Uint32 EUR_CR_VDM_FENCE_STATUS;
    volatile Uint32 EUR_CR_TA_CONTEXT_DRAIN_MTE;
    volatile Uint32 EUR_CR_TE_PRIMITIVE_BLOCK;
    volatile Uint8  RSVD14[96];
    volatile Uint32 EUR_CR_PIXELBE;
    volatile Uint32 EUR_CR_ISP_RENDER;
    volatile Uint32 EUR_CR_ISP_RGN_BASE;
    volatile Uint32 EUR_CR_ISP_RENDBOX1;
    volatile Uint32 EUR_CR_ISP_RENDBOX2;
    volatile Uint32 EUR_CR_ISP_IPFMISC;
    volatile Uint32 EUR_CR_ISP_OGL_MODE;
    volatile Uint32 EUR_CR_ISP_PERPENDICULAR;
    volatile Uint32 EUR_CR_ISP_CULLVALUE;
    volatile Uint32 EUR_CR_ISP_DBIAS;
    volatile Uint32 EUR_CR_ISP_START_RENDER;
    volatile Uint32 EUR_CR_THREED_AA_MODE;
    volatile Uint32 EUR_CR_ISP_BREAK;
    volatile Uint32 EUR_CR_ISP_3DCONTEXT;
    volatile Uint32 EUR_CR_ISP_FPU;
    volatile Uint32 EUR_CR_TSP_PARAMETER_CACHE;
    volatile Uint32 EUR_CR_TSP_PARAMETER_FETCH;
    volatile Uint32 EUR_CR_IFPU_ROUNDMODE;
    volatile Uint32 EUR_CR_ISP_START;
    volatile Uint32 EUR_CR_FOURKX4K_RENDER;
    volatile Uint32 EUR_CR_ISP_BREAK_INDEX;
    volatile Uint8  RSVD15[44];
    volatile Uint32 EUR_CR_ISP_ZLSCTL;
    volatile Uint32 EUR_CR_ISP_ZLOAD_BASE;
    volatile Uint32 EUR_CR_ISP_ZSTORE_BASE;
    volatile Uint32 EUR_CR_ISP_STENCIL_LOAD_BASE;
    volatile Uint32 EUR_CR_ISP_STENCIL_STORE_BASE;
    volatile Uint8  RSVD16[36];
    volatile Uint32 EUR_CR_ISP_BGOBJDEPTH;
    volatile Uint32 EUR_CR_ISP_BGOBJ;
    volatile Uint32 EUR_CR_ISP_VISREGBASE;
    volatile Uint32 EUR_CR_ISP_BGOBJTAG;
    volatile Uint32 EUR_CR_ISP_MULTISAMPLECTL;
    volatile Uint32 EUR_CR_ISP_MULTISAMPLECTL2;
    volatile Uint8  RSVD17[12];
    volatile Uint32 EUR_CR_ISP_TAGCTRL;
    volatile Uint8  RSVD18[4];
    volatile Uint32 EUR_CR_ISP_STATUS2;
    volatile Uint8  RSVD19[4];
    volatile Uint32 EUR_CR_PIXELBE_EMIT;
    volatile Uint8  RSVD20[16];
    volatile Uint32 EUR_CR_ISP_CONTEXT_RESUME;
    volatile Uint32 EUR_CR_ISP_CONTEXT_RESUME2;
    volatile Uint32 EUR_CR_ISP_CONTEXT_RESUME3;
    volatile Uint32 EUR_CR_ISP_ZLS_EXTZ_RGN_BASE;
    volatile Uint8  RSVD21[16];
    volatile Uint32 EUR_CR_ISP_MTILE1;
    volatile Uint32 EUR_CR_ISP_MTILE2;
    volatile Uint32 EUR_CR_ISP_MTILE;
    volatile Uint8  RSVD22[16];
    volatile Uint32 EUR_CR_ISP_ZLS_FALLBACK;
    volatile Uint32 EUR_CR_ISP_CONTEXT_SWITCH;
    volatile Uint32 EUR_CR_ISP_CONTEXT_SWITCH2;
    volatile Uint32 EUR_CR_ISP_CONTEXT_SWITCH3;
    volatile Uint32 EUR_CR_ISP_CONTEXT_SWITCH4;
    volatile Uint32 EUR_CR_ISP_CONTEXT_SWITCH5;
    volatile Uint32 EUR_CR_ISP_CONTEXT_SWITCH6;
    volatile Uint32 EUR_CR_ISP_CONTEXT_SWITCH7;
    volatile Uint32 EUR_CR_ISP_CONTEXT_SWITCH8;
    volatile Uint32 EUR_CR_ISP_CONTEXT_SWITCH9;
    volatile Uint32 EUR_CR_ISP_CONTEXT_SWITCH10;
    volatile Uint8  RSVD23[152];
    volatile Uint32 EUR_CR_DPM_3D_PAGE_TABLE_BASE;
    volatile Uint32 EUR_CR_DPM_3D_FREE_LIST;
    volatile Uint8  RSVD24[12];
    volatile Uint32 EUR_CR_DPM_PDS_PAGE_THRESHOLD;
    volatile Uint32 EUR_CR_DPM_TA_ALLOC_PAGE_TABLE_BASE;
    volatile Uint32 EUR_CR_DPM_TA_ALLOC_FREE_LIST;
    volatile Uint32 EUR_CR_DPM_TA_PAGE_THRESHOLD;
    volatile Uint32 EUR_CR_DPM_ZLS_PAGE_THRESHOLD;
    volatile Uint32 EUR_CR_DPM_TA_GLOBAL_LIST;
    volatile Uint32 EUR_CR_DPM_STATE_TABLE_BASE;
    volatile Uint32 EUR_CR_DPM_STATE_CONTEXT_ID;
    volatile Uint32 EUR_CR_DPM_CONTROL_TABLE_BASE;
    volatile Uint32 EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED;
    volatile Uint32 EUR_CR_DPM_3D_DEALLOCATE;
    volatile Uint32 EUR_CR_DPM_ALLOC;
    volatile Uint32 EUR_CR_DPM_DALLOC;
    volatile Uint32 EUR_CR_DPM_TA_ALLOC;
    volatile Uint32 EUR_CR_DPM_3D;
    volatile Uint8  RSVD25[8];
    volatile Uint32 EUR_CR_DPM_PARTIAL_RENDER;
    volatile Uint32 EUR_CR_DPM_LSS_PARTIAL_CONTEXT;
    volatile Uint32 EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED;
    volatile Uint32 EUR_CR_DPM_CONTEXT_PB_BASE;
    volatile Uint8  RSVD26[8];
    volatile Uint32 EUR_CR_DPM_PAGE_MANAGEOP;
    volatile Uint8  RSVD27[12];
    volatile Uint32 EUR_CR_DPM_TASK_3D_FREE;
    volatile Uint32 EUR_CR_DPM_TASK_TA_FREE;
    volatile Uint8  RSVD28[12];
    volatile Uint32 EUR_CR_DPM_TASK_STATE;
    volatile Uint32 EUR_CR_DPM_TASK_CONTROL;
    volatile Uint32 EUR_CR_DPM_OUTOFMEM;
    volatile Uint32 EUR_CR_DPM_FREE_CONTEXT;
    volatile Uint32 EUR_CR_DPM_3D_TIMEOUT;
    volatile Uint32 EUR_CR_DPM_TA_EVM;
    volatile Uint8  RSVD29[84];
    volatile Uint32 EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1;
    volatile Uint8  RSVD30[8];
    volatile Uint32 EUR_CR_DPM_3D_FREE_LIST_STATUS1;
    volatile Uint32 EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS2;
    volatile Uint8  RSVD31[8];
    volatile Uint32 EUR_CR_DPM_3D_FREE_LIST_STATUS2;
    volatile Uint32 EUR_CR_DPM_ABORT_STATUS_MTILE;
    volatile Uint32 EUR_CR_DPM_PAGE_STATUS;
    volatile Uint32 EUR_CR_DPM_PAGE;
    volatile Uint32 EUR_CR_DPM_GLOBAL_PAGE_STATUS;
    volatile Uint32 EUR_CR_DPM_GLOBAL_PAGE;
    volatile Uint32 EUR_CR_DPM_REQUESTING;
    volatile Uint32 EUR_CR_DPM_RGN_HDR_PARSER;
    volatile Uint32 EUR_CR_DPM_PIMSHARE;
    volatile Uint32 EUR_CR_DPM_CONTEXT_DRAIN_BASE;
    volatile Uint32 EUR_CR_DPM_CONTEXT_DRAIN_STATUS;
    volatile Uint32 EUR_CR_DPM_DRAIN_STATUS;
    volatile Uint32 EUR_CR_DPM_CONTEXT_DRAIN_BUF;
    volatile Uint32 EUR_CR_DPM_MTILE_ABORTED;
    volatile Uint32 EUR_CR_DPM_IDLE;
    volatile Uint8  RSVD32[24];
    volatile Uint32 EUR_CR_MTE_FORCEREISSUE;
    volatile Uint8  RSVD33[8];
    volatile Uint32 EUR_CR_DPM_PAGE_MANAGEOP_STATUS;
    volatile Uint8  RSVD34[4];
    volatile Uint32 EUR_CR_DPM_TSP_MTILEFREE;
    volatile Uint8  RSVD35[28];
    volatile Uint32 EUR_CR_DPM_DEALLOCATE_MASK;
    volatile Uint8  RSVD36[92];
    volatile Uint32 EUR_CR_TCU_CTRL;
    volatile Uint32 EUR_CR_TCU_ICTRL;
    volatile Uint8  RSVD37[4];
    volatile Uint32 EUR_CR_DCU_ICTRL;
    volatile Uint32 EUR_CR_DCU_PCTRL;
    volatile Uint32 EUR_CR_DCU_CTRL;
    volatile Uint8  RSVD38[228];
    volatile Uint32 EUR_CR_CLIP_CHECKSUM;
    volatile Uint32 EUR_CR_MTE_MEM_CHECKSUM;
    volatile Uint32 EUR_CR_MTE_TE_CHECKSUM;
    volatile Uint32 EUR_CR_TE_CHECKSUM;
    volatile Uint32 EUR_CR_ISP_FPU_CHECKSUM;
    volatile Uint32 EUR_CR_ISP_PRECALC_CHECKSUM;
    volatile Uint32 EUR_CR_ISP_EDGE_CHECKSUM;
    volatile Uint32 EUR_CR_ISP_TAGWRITE_CHECKSUM;
    volatile Uint32 EUR_CR_ISP_SPAN_CHECKSUM;
    volatile Uint32 EUR_CR_PBE_PIXEL_CHECKSUM;
    volatile Uint8  RSVD39[224];
    volatile Uint32 EUR_CR_USE_CACHE;
    volatile Uint8  RSVD40[68];
    volatile Uint32 EUR_CR_EVENT_PDS_ENABLE2;
    volatile Uint32 EUR_CR_PDS_CACHE_ENABLE;
    volatile Uint32 EUR_CR_EVENT_PDS_ENABLE;
    volatile Uint32 EUR_CR_EVENT_PIXEL_PDS_EXEC;
    volatile Uint32 EUR_CR_EVENT_PIXEL_PDS_DATA;
    volatile Uint32 EUR_CR_EVENT_PIXEL_PDS_INFO;
    volatile Uint32 EUR_CR_EVENT_OTHER_PDS_EXEC;
    volatile Uint32 EUR_CR_EVENT_OTHER_PDS_DATA;
    volatile Uint32 EUR_CR_EVENT_OTHER_PDS_INFO;
    volatile Uint32 EUR_CR_DMS_CTRL;
    volatile Uint8  RSVD41[4];
    volatile Uint32 EUR_CR_USE_G0;
    volatile Uint32 EUR_CR_USE_G1;
    volatile Uint8  RSVD42[40];
    volatile Uint32 EUR_CR_EVENT_KICK4;
    volatile Uint32 EUR_CR_EVENT_KICK1;
    volatile Uint8  RSVD43[4];
    volatile Uint32 EUR_CR_PDS_DMS_CTRL2;
    volatile Uint32 EUR_CR_PDS;
    volatile Uint32 EUR_CR_EVENT_KICK2;
    volatile Uint32 EUR_CR_EVENT_KICKER;
    volatile Uint32 EUR_CR_EVENT_KICK;
    volatile Uint32 EUR_CR_EVENT_TIMER;
    volatile Uint32 EUR_CR_PDS_INV0;
    volatile Uint32 EUR_CR_PDS_INV1;
    volatile Uint32 EUR_CR_EVENT_KICK3;
    volatile Uint32 EUR_CR_PDS_INV3;
    volatile Uint32 EUR_CR_PDS_INV_CSC;
    volatile Uint32 EUR_CR_PDS_DMS_DYNAMIC_SCHEDULE;
    volatile Uint8  RSVD44[28];
    volatile Uint32 EUR_CR_LOOPBACK;
    volatile Uint8  RSVD45[36];
    volatile Uint32 EUR_CR_PDS_EVDM_PC_BASE;
    volatile Uint8  RSVD46[8];
    volatile Uint32 EUR_CR_PDS_PDM_PC_BASE;
    volatile Uint8  RSVD47[104];
    volatile Uint32 EUR_CR_PDS_STATUS;
    volatile Uint32 EUR_CR_PDS_CONTEXT_STORE;
    volatile Uint32 EUR_CR_PDS_CONTEXT_RESUME;
    volatile Uint32 EUR_CR_MICRO_DATA_BASE;
    volatile Uint8  RSVD48[76];
    volatile Uint32 EUR_CR_BIF_CTRL;
    volatile Uint32 EUR_CR_BIF_INT_STAT;
    volatile Uint32 EUR_CR_BIF_FAULT;
    volatile Uint32 EUR_CR_BIF_TILE0;
    volatile Uint32 EUR_CR_BIF_TILE1;
    volatile Uint32 EUR_CR_BIF_TILE2;
    volatile Uint32 EUR_CR_BIF_TILE3;
    volatile Uint32 EUR_CR_BIF_TILE4;
    volatile Uint32 EUR_CR_BIF_TILE5;
    volatile Uint32 EUR_CR_BIF_TILE6;
    volatile Uint32 EUR_CR_BIF_TILE7;
    volatile Uint32 EUR_CR_BIF_TILE8;
    volatile Uint32 EUR_CR_BIF_TILE9;
    volatile Uint32 EUR_CR_BIF_CTRL_INVAL;
    volatile Uint32 EUR_CR_BIF_DIR_LIST_BASE1;
    volatile Uint32 EUR_CR_BIF_DIR_LIST_BASE2;
    volatile Uint32 EUR_CR_BIF_DIR_LIST_BASE3;
    volatile Uint32 EUR_CR_BIF_DIR_LIST_BASE4;
    volatile Uint32 EUR_CR_BIF_DIR_LIST_BASE5;
    volatile Uint32 EUR_CR_BIF_DIR_LIST_BASE6;
    volatile Uint32 EUR_CR_BIF_DIR_LIST_BASE7;
    volatile Uint8  RSVD49[32];
    volatile Uint32 EUR_CR_BIF_BANK_SET;
    volatile Uint32 EUR_CR_BIF_BANK0;
    volatile Uint32 EUR_CR_BIF_BANK1;
    volatile Uint8  RSVD50[4];
    volatile Uint32 EUR_CR_BIF_DIR_LIST_BASE0;
    volatile Uint8  RSVD51[8];
    volatile Uint32 EUR_CR_BIF_TA_REQ_BASE;
    volatile Uint8  RSVD52[20];
    volatile Uint32 EUR_CR_BIF_MEM_REQ_STAT;
    volatile Uint32 EUR_CR_BIF_3D_REQ_BASE;
    volatile Uint32 EUR_CR_BIF_ZLS_REQ_BASE;
    volatile Uint32 EUR_CR_BIF_BANK_STATUS;
    volatile Uint8  RSVD53[8];
    volatile Uint32 EUR_CR_BIF_SIG0;
    volatile Uint32 EUR_CR_BIF_SIG1;
    volatile Uint8  RSVD54[8];
    volatile Uint32 EUR_CR_BIF_MMU_CTRL;
    volatile Uint8  RSVD55[300];
    volatile Uint32 EUR_CR_TWOD_SIG;
    volatile Uint32 EUR_CR_TWOD_BLIT_STATUS;
    volatile Uint32 EUR_CR_TWOD_TEST_MODE;
    volatile Uint32 EUR_CR_TWOD_SIG_RESULT;
    volatile Uint32 EUR_CR_TWOD_VIRTUAL_FIFO_0;
    volatile Uint32 EUR_CR_TWOD_VIRTUAL_FIFO_1;
    volatile Uint8  RSVD56[104];
    volatile Uint32 EUR_CR_EMU_CYCLE_COUNT;
    volatile Uint32 EUR_CR_EMU_TA_PHASE;
    volatile Uint32 EUR_CR_EMU_3D_PHASE;
    volatile Uint32 EUR_CR_EMU_TA_CYCLE;
    volatile Uint32 EUR_CR_EMU_3D_CYCLE;
    volatile Uint32 EUR_CR_EMU_INITIAL_TA_CYCLE;
    volatile Uint32 EUR_CR_EMU_FINAL_3D_CYCLE;
    volatile Uint8  RSVD57[24];
    volatile Uint32 EUR_CR_EMU_MEM_READ;
    volatile Uint32 EUR_CR_EMU_TA_OR_3D_CYCLE;
    volatile Uint32 EUR_CR_EMU_MEM_WRITE;
    volatile Uint32 EUR_CR_EMU_MEM_BYTE_WRITE;
    volatile Uint32 EUR_CR_EMU_MEM_STALL;
    volatile Uint32 EUR_CR_BIF_CYCLE_COUNT;
    volatile Uint32 EUR_CR_BIF_MEM_READ_MMU;
    volatile Uint32 EUR_CR_BIF_MEM_READ_CACHE;
    volatile Uint32 EUR_CR_BIF_MEM_READ_TA;
    volatile Uint32 EUR_CR_BIF_MEM_WRITE_TA;
    volatile Uint32 EUR_CR_BIF_MEM_READ_VDM;
    volatile Uint32 EUR_CR_BIF_MEM_READ_PBE;
    volatile Uint32 EUR_CR_BIF_MEM_WRITE_PBE;
    volatile Uint32 EUR_CR_BIF_MEM_READ_TSP;
    volatile Uint32 EUR_CR_BIF_MEM_READ_ISP;
    volatile Uint32 EUR_CR_BIF_MEM_READ_ISPZ;
    volatile Uint32 EUR_CR_BIF_MEM_WRITE_ISPZ;
    volatile Uint32 EUR_CR_BIF_MEM_READ_USE0;
    volatile Uint32 EUR_CR_BIF_MEM_WRITE_USE0;
    volatile Uint32 EUR_CR_AXI_CACHE;
    volatile Uint32 EUR_CR_AXI_EXACCESS;
    volatile Uint32 EUR_CR_BIF_MEM_READ_USE1;
    volatile Uint32 EUR_CR_BIF_MEM_WRITE_USE1;
    volatile Uint32 EUR_CR_BIF_MEM_READ_USEC;
    volatile Uint32 EUR_CR_BIF_MEM_READ_PDS;
    volatile Uint32 EUR_CR_BIF_MEM_READ_USE2;
    volatile Uint32 EUR_CR_BIF_MEM_WRITE_USE2;
    volatile Uint32 EUR_CR_BIF_MEM_READ_USE3;
    volatile Uint32 EUR_CR_BIF_MEM_WRITE_USE3;
    volatile Uint32 EUR_CR_USEC_BIF_CYCLE_COUNT;
    volatile Uint32 EUR_CR_USEC_BIF_VERTEX_READ;
    volatile Uint32 EUR_CR_USEC_BIF_PIXEL_READ;
    volatile Uint32 EUR_CR_USEC_BIF_EVENT_READ;
    volatile Uint32 EUR_CR_BIF_MEM_THREE_D_COUNT;
    volatile Uint32 EUR_CR_BIF_MEM_OVER_LAPPED_TA_READ_COUNT;
    volatile Uint32 EUR_CR_BIF_MEM_OVER_LAPPED_TA_WRITE_COUNT;
    volatile Uint8  RSVD58[52];
    volatile Uint32 EUR_CR_PARTITION_BREAKPOINT_TRAP;
    volatile Uint32 EUR_CR_PARTITION_BREAKPOINT;
    volatile Uint32 EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO0;
    volatile Uint32 EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1;
    volatile Uint8  RSVD59[120];
    volatile Uint32 EUR_CR_SIM_3D_FRAME_COUNT;
    volatile Uint32 EUR_CR_SIM_TA_FRAME_COUNT;
    volatile Uint32 EUR_CR_SIM_USE_STATS;
    volatile Uint8  RSVD60[4];
} CSL_KlioRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* Core module clock gating controls: allows clocks to be forced off, forced
 * on or operate under automatic pipeline activity based clock gating. */
#define CSL_KLIO_EUR_CR_CLKGATECTL                              (0x0U)

/* Core module clock gating controls: allows clocks to be forced off, forced
 * on or operate under automatic pipeline activity based clock gating. */
#define CSL_KLIO_EUR_CR_CLKGATECTL2                             (0x4U)

/* Clock Gating Status reflects the condition of the clock gate controls for
 * each module. */
#define CSL_KLIO_EUR_CR_CLKGATESTATUS                           (0x8U)

/* Core module clock gating override controls: allows clocks to be enabled
 * temporarily for register writes by hosts. */
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR                           (0xCU)

/* Core module clock gating override controls: allows clocks to be enabled
 * temporarily for register writes by hosts. */
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2                          (0x10U)

/* Chip can be run with half the number of pipes enabled. Default is all pipes
 * enabled */
#define CSL_KLIO_EUR_CR_POWER                                   (0x1CU)

/* Core ID Register */
#define CSL_KLIO_EUR_CR_CORE_ID                                 (0x20U)

/* Core Revision Register identifies the specific core revision. */
#define CSL_KLIO_EUR_CR_CORE_REVISION                           (0x24U)

/* Designer Revision Field. The SOC designer can use this register for their
 * own revision control if required. */
#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD1                     (0x28U)

/* Designer Revision Field The SOC designer can use this register for their
 * own revision control if required. */
#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD2                     (0x2CU)

/* Within SGX there are a number of performance counters which enable
 * profiling of an application in terms of the low level hardware performance;
 * this register enables selection of specific groups of performance counters
 * and the ability to reset those counters. Full details can be found in the
 * performance profiling section of this document. Write a '1' followed by a
 * '0' to the _CLR fields to reset the specific counter */
#define CSL_KLIO_EUR_CR_PERF                                    (0x40U)

/* Performance counter 0 status register */
#define CSL_KLIO_EUR_CR_PERF_COUNTER0                           (0x44U)

/* Performance counter 1 status register */
#define CSL_KLIO_EUR_CR_PERF_COUNTER1                           (0x48U)

/* Performance counter 2 status register */
#define CSL_KLIO_EUR_CR_PERF_COUNTER2                           (0x4CU)

/* Performance counter 3 status register */
#define CSL_KLIO_EUR_CR_PERF_COUNTER3                           (0x50U)

/* Performance counter 4 status register */
#define CSL_KLIO_EUR_CR_PERF_COUNTER4                           (0x54U)

/* Performance counter 5 status register */
#define CSL_KLIO_EUR_CR_PERF_COUNTER5                           (0x58U)

/* Performance counter 6 status register */
#define CSL_KLIO_EUR_CR_PERF_COUNTER6                           (0x5CU)

/* Performance counter 7 status register */
#define CSL_KLIO_EUR_CR_PERF_COUNTER7                           (0x60U)

/* Selects the MSB of the 16-bits counter group to be sent to the counter. If
 * SELECT_7 = 9, then the bits {9:0} of the counter group will be outputted by
 * BIT SELECT, bits {15:10} will be tied to zero */
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT                        (0x64U)

/* Performance counter status register */
#define CSL_KLIO_EUR_CR_DEBUG_REG0                              (0x70U)

/* Performance counter status register */
#define CSL_KLIO_EUR_CR_DEBUG_REG1                              (0x74U)

/* Performance bus and debug bus control register */
#define CSL_KLIO_EUR_CR_PERF_DEBUG_CTRL                         (0x78U)

/* Soft reset control register which drives all modules except the register
 * bank. Write a '1' to reset and a '0' to clear Bits 31 : 16 are reserved */
#define CSL_KLIO_EUR_CR_SOFT_RESET                              (0x80U)

/* TA/3D Lockup counter timeout value (16K cycle granularity) */
#define CSL_KLIO_EUR_CR_TRIGGER                                 (0x100U)

/* This register enables interrupts. Writing a '1' to a bit field enables the
 * relevant Event. All the bit fields correspond exactly to those in the
 * EUR_CR_EVENT_STATUS2 register. The MASTER_INTERRUPT bit is a global enable
 * which overrides the Event enables, i.e. '1' - enable external interrupts,
 * '0' - disable external interrupts. */
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2                      (0x110U)

/* This register is used to clear event interrupts. Writing a '1' to a bit
 * field clears the relevant Event. All the bit fields correspond exactly to
 * those in the EUR_CR_EVENT_STATUS2 register. */
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2                       (0x114U)

/* There are 2 sources of external interrupts in the PowerVR SGX core: General
 * system events and PDS cache invalidation events. The event status2 register
 * indicates the source of any general event interrupt generated by PowerVR
 * SGX. These events only result in an external interrupt if the relevant bit
 * in the EUR_CR_EVENT_HOST_ENABLE register is set. Note1: This register must
 * be combined with the EUR_CR_PDS_CACHE_STATUS register information to
 * determine what has caused the external interrupt. Note2: The host can write
 * to this register in which case any bits written as a '1' are ORed into the
 * register i.e. the host can cause the core to generate an interrupt. (This
 * is typically for debug purposes only) */
#define CSL_KLIO_EUR_CR_EVENT_STATUS2                           (0x118U)

/* There are 2 sources of external interrupts in the PowerVR SGX core: General
 * system events and PDS cache invalidation events. The event status register
 * indicates the source of any general event interrupt generated by PowerVR
 * SGX. These events only result in an external interrupt if the relevant bit
 * in the EUR_CR_EVENT_HOST_ENABLE register is set. Note1: This register must
 * be combined with the EUR_CR_PDS_CACHE_STATUS register information to
 * determine what has caused the external interrupt. Note2: The host can write
 * to this register in which case any bits written as a '1' are ORed into the
 * register i.e. the host can cause the core to generate an interrupt. (This
 * is typically for debug purposes only) */
#define CSL_KLIO_EUR_CR_EVENT_STATUS                            (0x12CU)

/* This register enables interrupts. Writing a '1' to a bit field enables the
 * relevant Event. All the bit fields correspond exactly to those in the
 * EUR_CR_EVENT_STATUS register. The MASTER_INTERRUPT bit is a global enable
 * which overrides the Event enables, i.e. '1' - enable external interrupts,
 * '0' - disable external interrupts. */
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE                       (0x130U)

/* This register is used to clear event interrupts. Writing a '1' to a bit
 * field clears the relevant Event. All the bit fields correspond exactly to
 * those in the EUR_CR_EVENT_STATUS register. */
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR                        (0x134U)

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
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS                        (0x138U)

/* This register enables interrupts. Writing a '1' to a bit field enables the
 * relevant Event. All the bit fields correspond exactly to those in the
 * EUR_CR_PDS_CACHE_STATUS register. The MASTER_INTERRUPT bit contained in the
 * EUR_CR_EVENT_HOST_ENABLE register is a global enable which overrides the
 * Event enables, i.e. '1' - enable external interrupts, '0' - disable
 * external interrupts. */
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE                   (0x13CU)

/* This register is used to clear event interrupts. Writing a '1' to a bit
 * field clears the relevant Event. All the bit fields correspond exactly to
 * those in the EUR_CR_PDS_CACHE_STATUS register. */
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR                    (0x140U)

/* {This register return the value of the internal timer. The timer runs
 * continuously, and wraps at the top end. It counts 16 cycle lots of the core
 * clock frequency. This means that at 100 MHz: Period = 1/100MHz = 10 * 10^-9
 * seconds 1 count value = 16 * 10 * 10^-9 seconds = 0.16 us It is a 32 bit
 * counter so it will wrap every: 2^32 * 0.16 us = 687 seconds. at 100MHz */
#define CSL_KLIO_EUR_CR_TIMER                                   (0x144U)

/* Indicate whethers pixel output buffers should be 2 partitions (32bits wide)
 * or 4 partitions (64bits wide) */
#define CSL_KLIO_EUR_CR_DOUBLE_PIXEL_PARTITIONS                 (0x148U)

/* Any write to this register starts the Vertex Data Master DMA operation */
#define CSL_KLIO_EUR_CR_VDM_START                               (0x200U)

/* A write to this register initialises all the Region Headers addressed by
 * the values in the TE_AA, TE_MTILE1, TE_MTILE2 and TE_MTILE registers to
 * empty */
#define CSL_KLIO_EUR_CR_TE_RGNHDR_INIT                          (0x380U)

/* This register controls the anti-aliasing mode of the Tiling Co-Processor,
 * 2x or 4x antialiasing is available. 4x antialising is achieved by setting
 * both the X and Y fields to 1. 2x antialiasing can be achieved by only
 * setting the Y field to 1 and ensuring the X field is 0. Klio only supports
 * 2xmsaa in the Y plane. */
#define CSL_KLIO_EUR_CR_TE_AA                                   (0x204U)

/* The Tiling Co-Processor allocates memory in macrotiles, which is a group of
 * individual tiles. The number of macrotiles is selectable between 4 and 16,
 * the boundaries of the macrotiles in the X axis are defined in this
 * register. */
#define CSL_KLIO_EUR_CR_TE_MTILE1                               (0x208U)

/* The Tiling Co-Processor allocates memory in macrotiles, which is a group of
 * individual tiles. The number of macrotiles is selectable between 4 and 16,
 * the boundaries of the macrotiles in the Y axis are defined in this
 * register. */
#define CSL_KLIO_EUR_CR_TE_MTILE2                               (0x20CU)

/* In order to perform the tiling operation and generate the display list the
 * maximum screen size must be configured in terms of the number of tiles in X
 * and Y axis. */
#define CSL_KLIO_EUR_CR_TE_SCREEN                               (0x210U)

/* This register defines the number of individual tiles within the macrotiles.
 * This is used in the process of memory allocation. */
#define CSL_KLIO_EUR_CR_TE_MTILE                                (0x214U)

/* This register defines the global control for the Parameter Stream Generator
 * within the Tiling Co-Processor. This module formats the display list
 * generated by the Tiling Co-Processor. */
#define CSL_KLIO_EUR_CR_TE_PSG                                  (0x218U)

/* This register defines the base address in memory of the Region Header
 * writes by the TA. Region headers are the first part of the display list and
 * contain an entry per tile with information on global setup and a link
 * address to parameters. */
#define CSL_KLIO_EUR_CR_TE_PSGREGION_BASE                       (0x21CU)

/* This register defines the base address in memory of the Tail Pointer Cache.
 * A tail pointer is the current last address written to for a tiles
 * individual display list, an entry for active tiles is maintained as
 * primitives are processed by the TA. */
#define CSL_KLIO_EUR_CR_TE_TPC_BASE                             (0x220U)

/* The Tail Pointer Cache is used to keep track of the last address written to
 * for a particular tile, this is stored in a mixture of on chip cache and
 * external memory. Under certain circumstances it is neccesary to either
 * reset the cache or flush the on chip cache contents such that they are
 * visible in memory. */
#define CSL_KLIO_EUR_CR_TE_TPCCONTROL                           (0x224U)

/* Reset or enabled by the MTE_RESETBBOX and MTE_UPDATEBBOX fields in the
 * MTEControl word of the Input Parameter format. This is the maximum extent
 * in X of the post transformed, clipped data before region clipping. */
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_X                            (0x228U)

/* Reset or enabled by the MTE_RESETBBOX and MTE_UPDATEBBOX fields in the MTE
 * Control word of the Input Parameter format. This is the maximum extent in Y
 * of the post transformed, clipped data before region clipping. */
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_Y                            (0x22CU)

/* The TA maintains internal state of the current information for each macro
 * tile and global list regarding the vertex blocks written to memory. In
 * certain circumstances during a context switch it is neccessary to flush
 * this information to external memory. */
#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_FLUSH_BASE                 (0x230U)

/* The TA maintains internal state of the current information for each macro
 * tile and global list regarding the vertex blocks written to memory. In
 * certain circumstances during a context switch it is neccessary to load this
 * information from external memory. */
#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_LOAD_BASE                  (0x234U)

/* PowerVR SGX masters information from memory using advanced DMA, this
 * register defines the base address of the Vertex Data input control stream
 * in memory. */
#define CSL_KLIO_EUR_CR_VDM_CTRL_STREAM_BASE                    (0x238U)

/* Controls Master VDM BATCH_NUM value */
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM                           (0x320U)

/* Reports Master VDM BATCH_NUM status */
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_STATUS                    (0x324U)

/* Generic Control Word 0 to be optionally loaded with context switching tasks */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD0         (0x328U)

/* Generic Control Word 1 to be optionally loaded with context switching tasks */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD1         (0x32CU)

/* Start VDM Context store, pulse kicks off the store operation. Status flags
 * when this is complete and the stream and index position registers are valid */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_START                 (0x330U)

/* Stores the stream position when the context store occured */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STREAM                (0x334U)

/* Stores the index position when the context store occured */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR            (0x338U)

/* Stores the index position when the context store occured */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_INDEX            (0x34CU)

/* Stores the index position when the context store occured */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAPPED               (0x350U)

/* Stores the index position when the context store occured */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX             (0x354U)

/* Stores the index position when the context store occured */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME           (0x358U)

/* Signals when a context store is complete and the stream and index location
 * registers are valid */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS                (0x33CU)

/* Terminate state control registers used for creating the terminate PDS task. */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0                (0x340U)

/* Terminate state control registers used for creating the terminate PDS task. */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1                (0x344U)

/* Indicates the status on the control stream fetch */
#define CSL_KLIO_EUR_CR_VDM_WAIT_FOR_KICK                       (0x348U)

/* EUR_CR_VDM_MTE */
#define CSL_KLIO_EUR_CR_VDM_MTE                                 (0x378U)

/* Increment the VDM's fence count */
#define CSL_KLIO_EUR_CR_VDM_FENCE                               (0x390U)

/* Reports the VDM's fence count */
#define CSL_KLIO_EUR_CR_VDM_FENCE_STATUS                        (0x394U)

/* This register controls the global setup of the Tiling Process. */
#define CSL_KLIO_EUR_CR_MTE_CTRL                                (0x23CU)

/* EUR_CR_MTE_WCOMPARE */
#define CSL_KLIO_EUR_CR_MTE_WCOMPARE                            (0x240U)

/* EUR_CR_MTE_WCLAMP */
#define CSL_KLIO_EUR_CR_MTE_WCLAMP                              (0x244U)

/* In order to perform the tiling operation and generate the display list the
 * maximum screen size must be configured in terms of the number of pixels in
 * X and Y axis since this may not be the same as the number of tiles defined
 * in the EUR_CR_TE_SCREEN register. */
#define CSL_KLIO_EUR_CR_MTE_SCREEN                              (0x248U)

/* The TA maintains internal state of the current information for each macro
 * tile and global list regarding the vertex blocks written to memory. In
 * certain circumstances during a context switch it is necessary to load or
 * flush this information to external memory. */
#define CSL_KLIO_EUR_CR_MTE_OTPM_OP                             (0x24CU)

/* This applies when anti-aliasing is enabled. This is used to calculate
 * whether an anti-aliased triangle can be perfect small object culled. */
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL                      (0x250U)

/* EUR_CR_TA_MEM_TE_PAD */
#define CSL_KLIO_EUR_CR_TA_MEM_TE_PAD                           (0x254U)

/* EUR_CR_MTE_FIRST_PAGE */
#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE                          (0x258U)

/* EUR_CR_MTE_SECOND_PAGE */
#define CSL_KLIO_EUR_CR_MTE_SECOND_PAGE                         (0x25CU)

/* EUR_CR_MTE_ABORT */
#define CSL_KLIO_EUR_CR_MTE_ABORT                               (0x260U)

/* EUR_CR_MTE_SIG1 */
#define CSL_KLIO_EUR_CR_MTE_SIG1                                (0x26CU)

/* EUR_CR_MTE_SIG2 */
#define CSL_KLIO_EUR_CR_MTE_SIG2                                (0x270U)

/* This register is read on VDM_START_PULSE and should be saved and updated by
 * the driver app by app */
#define CSL_KLIO_EUR_CR_TE_STATE                                (0x274U)

/* This register defines the base address in memory of the snapshot buffer for
 * the VDM context store. This buffer store the information of the VDM
 * pipeline. For the moment, the buffer is 4K bytes size */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_SNAPSHOT              (0x280U)

/* Any write to this register starts the Vertex Data Master Loading the
 * pipeline status from the snapshot buffer */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_START                  (0x284U)

/* EUR_CR_VDM_CONTEXT_LOAD_STATUS */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS                 (0x288U)

/* EUR_CR_VDM_CONTEXT_LOAD_STATUS_CLEAR */
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_CLEAR           (0x28CU)

/* Any write to this register starts the Vertex Data Master sending a task to
 * the vertex pipeline which is configured by the
 * eur_cr_vdm_context_store_state* register */
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK                           (0x290U)

/* EUR_CR_VDM_TASK_KICK_STATUS */
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS                    (0x294U)

/* EUR_CR_VDM_TASK_KICK_STATUS_CLEAR */
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_CLEAR              (0x298U)

/* EUR_CR_TE_SAFE */
#define CSL_KLIO_EUR_CR_TE_SAFE                                 (0x29CU)

/* EUR_CR_CLIP_SIG1 */
#define CSL_KLIO_EUR_CR_CLIP_SIG1                               (0x304U)

/* EUR_CR_PBE_NONPIXEL_CHECKSUM */
#define CSL_KLIO_EUR_CR_PBE_NONPIXEL_CHECKSUM                   (0x30CU)

/* EUR_CR_TA_CLK_GATE */
#define CSL_KLIO_EUR_CR_TA_CLK_GATE                             (0x310U)

/* The MTE state is flushed out to memory so that it can be written back more
 * easily. */
#define CSL_KLIO_EUR_CR_MTE_STATE                               (0x37CU)

/* The MTE state is flushed out to memory so that it can be written back more
 * easily. */
#define CSL_KLIO_EUR_CR_MTE_STATE_FLUSH_BASE                    (0x384U)

/* Fixed point format in the internal parameter stream can be 13.3 or 12.4. */
#define CSL_KLIO_EUR_CR_MTE_FIXED_POINT                         (0x388U)

/* The TA context is drained out to memory on a context switch and restored on
 * a resume. */
#define CSL_KLIO_EUR_CR_TA_CONTEXT                              (0x38CU)

/* The TA context is drained out to memory on a context switch and restored on
 * a resume. */
#define CSL_KLIO_EUR_CR_TA_CONTEXT_DRAIN_MTE                    (0x398U)

/* The progress in Tiles through the Primitive Block the TE has made on
 * context switch. Should be sampled by the driver and restored before Resume. */
#define CSL_KLIO_EUR_CR_TE_PRIMITIVE_BLOCK                      (0x39CU)

/* The PixelBE module formats the pixel data before writing to memory, this
 * register contains global control signals. */
#define CSL_KLIO_EUR_CR_PIXELBE                                 (0x400U)

/* The Image Synthesis Processor can be configured to operate in 3 different
 * render modes */
#define CSL_KLIO_EUR_CR_ISP_RENDER                              (0x404U)

/* This register defines the base address in memory of the Region Header reads
 * by the ISP. Region headers are the first part of the display list and
 * contain an entry per tile with information on global setup and a link
 * address to parameters. */
#define CSL_KLIO_EUR_CR_ISP_RGN_BASE                            (0x408U)

/* When the render type is set to Fast 2D Render or Fast Scale Render, no
 * region headers are read from memory. Instead, region headers are internally
 * generated for all tiles enclosed in the bounding box defined by this
 * register and the EUR_CR_ISP_RENDBOX2 register. */
#define CSL_KLIO_EUR_CR_ISP_RENDBOX1                            (0x40CU)

/* When the render type is set to Fast 2D Render or Fast Scale Render, no
 * region headers are read from memory. Instead, region headers are internally
 * generated for all tiles enclosed in the bounding box defined by this
 * register and the EUR_CR_ISP_RENDBOX1 register. */
#define CSL_KLIO_EUR_CR_ISP_RENDBOX2                            (0x410U)

/* Global control register for the ISP parameter fetch. */
#define CSL_KLIO_EUR_CR_ISP_IPFMISC                             (0x414U)

/* Global control register which modifies the pixel sample position to comply
 * with OGL requirements. */
#define CSL_KLIO_EUR_CR_ISP_OGL_MODE                            (0x418U)

/* EUR_CR_ISP_PERPENDICULAR */
#define CSL_KLIO_EUR_CR_ISP_PERPENDICULAR                       (0x41CU)

/* EUR_CR_ISP_CULLVALUE */
#define CSL_KLIO_EUR_CR_ISP_CULLVALUE                           (0x420U)

/* EUR_CR_ISP_DBIAS */
#define CSL_KLIO_EUR_CR_ISP_DBIAS                               (0x424U)

/* Any write to this register starts a 3D Render. */
#define CSL_KLIO_EUR_CR_ISP_START_RENDER                        (0x428U)

/* Indicates to the 3D pipeline whether anti-aliasing is enabled or disabled,
 * and if enabled whether it is in 2x or 4x mode */
#define CSL_KLIO_EUR_CR_THREED_AA_MODE                          (0x42CU)

/* Object breakpoints can be inserted by the driver to interrupt a render part
 * way and then resume the render from the point of interrupt at a later time,
 * this register controls what happens when a breakpoint has been encountered. */
#define CSL_KLIO_EUR_CR_ISP_BREAK                               (0x430U)

/* EUR_CR_ISP_3DCONTEXT */
#define CSL_KLIO_EUR_CR_ISP_3DCONTEXT                           (0x434U)

/* EUR_CR_ISP_FPU */
#define CSL_KLIO_EUR_CR_ISP_FPU                                 (0x438U)

/* EUR_CR_TSP_PARAMETER_CACHE */
#define CSL_KLIO_EUR_CR_TSP_PARAMETER_CACHE                     (0x43CU)

/* EUR_CR_TSP_PARAMETER_FETCH */
#define CSL_KLIO_EUR_CR_TSP_PARAMETER_FETCH                     (0x440U)

/* EUR_CR_IFPU_ROUNDMODE */
#define CSL_KLIO_EUR_CR_IFPU_ROUNDMODE                          (0x444U)

/* EUR_CR_ISP_START */
#define CSL_KLIO_EUR_CR_ISP_START                               (0x448U)

/* EUR_CR_FOURKX4K_RENDER */
#define CSL_KLIO_EUR_CR_FOURKX4K_RENDER                         (0x44CU)

/* EUR_CR_ISP_BREAK_INDEX */
#define CSL_KLIO_EUR_CR_ISP_BREAK_INDEX                         (0x450U)

/* Image Synthesis Processor Z Load/Store and format global control register */
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL                              (0x480U)

/* This register defines the base address in memory of the Z Buffer base
 * address to load into the ISP for non-compressed ZLS formats. */
#define CSL_KLIO_EUR_CR_ISP_ZLOAD_BASE                          (0x484U)

/* This register defines the base address in memory of the Z Buffer base
 * address to store data from the ISP for non-compressed ZLS formats. */
#define CSL_KLIO_EUR_CR_ISP_ZSTORE_BASE                         (0x488U)

/* This register defines the base address in memory of the Stencil Buffer base
 * address to load into the ISP for Int24 and IEEE ZLS formats. This alternate
 * stencil buffer base address is selectable based on the enable bit. */
#define CSL_KLIO_EUR_CR_ISP_STENCIL_LOAD_BASE                   (0x48CU)

/* This register defines the base address in memory of the Stencil Buffer base
 * address to store data from the ISP for Int24 and IEEE ZLS formats. This
 * alternate stencil buffer base address is selectable based on the enable
 * bit. */
#define CSL_KLIO_EUR_CR_ISP_STENCIL_STORE_BASE                  (0x490U)

/* The base address that the visibility test results are read/written to. */
#define CSL_KLIO_EUR_CR_ISP_VISREGBASE                          (0x4C0U)

/* The ISP operates by comparing depth values of incoming objects with the
 * results of previous depth compares, in order to make sure there are no
 * unitialised values at the start of the tile or to cover pixels where there
 * are no objects in the scene a default background object is configured under
 * register control. This register provides the floating point depth value for
 * this background object. */
#define CSL_KLIO_EUR_CR_ISP_BGOBJDEPTH                          (0x4B8U)

/* The ISP operates by comparing depth values of incoming objects with the
 * results of previous depth compares, in order to make sure there is no
 * unitialised values at the start of the tile or to cover pixels where there
 * are no objects in the scene a default background object is configured under
 * register control. This register provides tag, mask and stencil information
 * for this background object. */
#define CSL_KLIO_EUR_CR_ISP_BGOBJ                               (0x4BCU)

/* The ISP operates by comparing depth values of incoming objects with the
 * results of previous depth compares, in order to make sure there are no
 * unitialised values at the start of the tile or to cover pixels where there
 * are no objects in the scene a default background object is configured under
 * register control. This register provides TSP and Vertex information for
 * this background object. */
#define CSL_KLIO_EUR_CR_ISP_BGOBJTAG                            (0x4C4U)

/* This applies when anti-aliasing is enabled. This is used by the ISP to
 * adjust the sample positions. */
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL                      (0x4C8U)

/* This applies when centroid sampling is not enabled and MSAA is enabled.
 * This is 5th sampling position added to TSPFU */
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2                     (0x4CCU)

/* EUR_CR_ISP_TAGCTRL */
#define CSL_KLIO_EUR_CR_ISP_TAGCTRL                             (0x4DCU)

/* EUR_CR_ISP_STATUS2 */
#define CSL_KLIO_EUR_CR_ISP_STATUS2                             (0x4E4U)

/* This register indicates if the PixelBE would stall the USE if there were
 * another emit. '0' indicates that the PixelBE would stall the USE. '1'
 * indicates that the PixelBE would not stall the USE. */
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT                            (0x4ECU)

/* On resuming a given context the ISP2 needs to be passed the memory address
 * that was used when the context was stored off in order to reload the data. */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME                      (0x500U)

/* On resuming a given context the ISP2 needs to read back the flags that were
 * set when the context was stored off such that it knows the status of the
 * current tile. These flags will have been stored in memory and will be
 * identical to what was originally stored off with one exception, the
 * pt_in_flight register which is described later in more detail. */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2                     (0x504U)

/* On resuming a given context the ISP2 ZLS module needs any zstore commands
 * which were ignored due to the context switch reissuing so that they will be
 * performed once the tile is completed. */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3                     (0x508U)

/* This register defines the base address in memory of where the zls stores
 * out the tile starting address and the number of bursts of the current tile
 * when using an external z buffer. */
#define CSL_KLIO_EUR_CR_ISP_ZLS_EXTZ_RGN_BASE                   (0x50CU)

/* The number of macrotiles is selectable between 4 and 16, the boundaries of
 * the macrotiles in the X axis are defined in this register. */
#define CSL_KLIO_EUR_CR_ISP_MTILE1                              (0x520U)

/* The number of macrotiles is selectable between 4 and 16, the boundaries of
 * the macrotiles in the Y axis are defined in this register. */
#define CSL_KLIO_EUR_CR_ISP_MTILE2                              (0x524U)

/* This register defines the number of individual tiles within the macrotiles.
 * This is used in the process of memory allocation. */
#define CSL_KLIO_EUR_CR_ISP_MTILE                               (0x528U)

/* EUR_CR_ISP_ZLS_FALLBACK */
#define CSL_KLIO_EUR_CR_ISP_ZLS_FALLBACK                        (0x53CU)

/* The ISP2 needs to have an area of memory allocated to it such that when a
 * context switch is issued the current context can be stored off to memory by
 * the ZLS module such that it can be resumed at some point in the future. */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH                      (0x540U)

/* On a context switch ISP2 sets a number of flags based on its interpretation
 * of whereabout in a given scene or tile the context switch has occurred and
 * whether or not any objects require feedback from the USSE. Other
 * information required by the driver includes the number of dwords written
 * out by the ZLS module during the zstore process. These flags are then
 * stored off and processed by the driver such that when we resume the
 * respective flags in the resume registers are set and the ISP2 can
 * seamlessly continue from where it left off. */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2                     (0x544U)

/* On a context switch the ISP2 ZLS module will normally override the contents
 * of its command FIFO and store off the tile to the context store base
 * address regardless of whether a zstore had been scheduled or not. In order
 * to ensure that when the chip resumes this context the scheduled zstore is
 * performed we need to store off the zstore operation such that it can be
 * reissued when we return to this tile/context. */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3                     (0x548U)

/* EUR_CR_ISP_CONTEXT_SWITCH4 */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH4                     (0x54CU)

/* EUR_CR_ISP_CONTEXT_SWITCH5 */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH5                     (0x550U)

/* EUR_CR_ISP_CONTEXT_SWITCH6 */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH6                     (0x554U)

/* EUR_CR_ISP_CONTEXT_SWITCH7 */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH7                     (0x558U)

/* EUR_CR_ISP_CONTEXT_SWITCH8 */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH8                     (0x55CU)

/* EUR_CR_ISP_CONTEXT_SWITCH9 */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH9                     (0x560U)

/* EUR_CR_ISP_CONTEXT_SWITCH10 */
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH10                    (0x564U)

/* Effective on load 3D context, this register defines the base address of the
 * page table being referenced in the process of de-allocating pages during a
 * 3D render. */
#define CSL_KLIO_EUR_CR_DPM_3D_PAGE_TABLE_BASE                  (0x600U)

/* Between the FREE_LIST_HEAD and FREE_LIST_TAIL there must be a valid chain
 * of linked pages. The linked list is stored in memory, at the
 * EUR_CR_DPM_3D_PAGE_TABLE_BASE_ADDRESS and is effective on load 3D context. */
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST                        (0x604U)

/* EUR_CR_DPM_PDS_PAGE_THRESHOLD */
#define CSL_KLIO_EUR_CR_DPM_PDS_PAGE_THRESHOLD                  (0x614U)

/* Effective on Loading the TA Page Table Context, this register defines the
 * base address of the page table being referenced in the process of
 * allocating pages by the TE and MTE. */
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_PAGE_TABLE_BASE            (0x618U)

/* Between the FREE_LIST_HEAD and FREE_LIST_TAIL there must be a valid chain
 * of linked pages. The linked list is stored in memory, at the
 * EUR_CR_DPM_TA_ALLOC_PAGE_TABLE_BASE_ADDRESS and is effective on Loading the
 * TA Page Table Context. */
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST                  (0x61CU)

/* EUR_CR_DPM_TA_PAGE_THRESHOLD */
#define CSL_KLIO_EUR_CR_DPM_TA_PAGE_THRESHOLD                   (0x620U)

/* EUR_CR_DPM_ZLS_PAGE_THRESHOLD */
#define CSL_KLIO_EUR_CR_DPM_ZLS_PAGE_THRESHOLD                  (0x624U)

/* EUR_CR_DPM_TA_GLOBAL_LIST */
#define CSL_KLIO_EUR_CR_DPM_TA_GLOBAL_LIST                      (0x628U)

/* Effective immediately, this register defines the base address of the state
 * table when it is read and written to/from memory. The state table itself
 * contains the head, tail and number of pages allocated to every macrotile,
 * and the global list. Each context needs a separate state page table. */
#define CSL_KLIO_EUR_CR_DPM_STATE_TABLE_BASE                    (0x62CU)

/* EUR_CR_DPM_STATE_CONTEXT_ID */
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID                    (0x630U)

/* Effective immediately, this register defines the base address of the
 * control table when it is read and written to/from memory. The control table
 * itself contains the current offset into the page, and whether a page has
 * been allocated, for each macrotile. Each context needs a separate state
 * page table. */
#define CSL_KLIO_EUR_CR_DPM_CONTROL_TABLE_BASE                  (0x634U)

/* EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED */
#define CSL_KLIO_EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED    (0x638U)

/* EUR_CR_DPM_3D_DEALLOCATE */
#define CSL_KLIO_EUR_CR_DPM_3D_DEALLOCATE                       (0x63CU)

/* A write to this register invalidates the current contents and causes a new
 * allocation cycle */
#define CSL_KLIO_EUR_CR_DPM_ALLOC                               (0x640U)

/* A write to this register invalidates the current contents and causes a new
 * de-allocation cycle */
#define CSL_KLIO_EUR_CR_DPM_DALLOC                              (0x644U)

/* EUR_CR_DPM_TA_ALLOC */
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC                            (0x648U)

/* EUR_CR_DPM_3D */
#define CSL_KLIO_EUR_CR_DPM_3D                                  (0x64CU)

/* EUR_CR_DPM_PARTIAL_RENDER */
#define CSL_KLIO_EUR_CR_DPM_PARTIAL_RENDER                      (0x658U)

/* EUR_CR_DPM_LSS_PARTIAL_CONTEXT */
#define CSL_KLIO_EUR_CR_DPM_LSS_PARTIAL_CONTEXT                 (0x65CU)

/* EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED */
#define CSL_KLIO_EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED  (0x660U)

/* EUR_CR_DPM_CONTEXT_PB_BASE */
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_PB_BASE                     (0x664U)

/* EUR_CR_DPM_TASK_3D_FREE */
#define CSL_KLIO_EUR_CR_DPM_TASK_3D_FREE                        (0x680U)

/* EUR_CR_DPM_TASK_TA_FREE */
#define CSL_KLIO_EUR_CR_DPM_TASK_TA_FREE                        (0x684U)

/* This register controls the DPM module task state for page tables. The
 * normal order of operation is Store context, Clear context, Load new
 * context. */
#define CSL_KLIO_EUR_CR_DPM_TASK_STATE                          (0x694U)

/* This register controls the DPM module task state for control page tables.
 * The normal order of operation is Store context, Clear context, Load new
 * context. */
#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL                        (0x698U)

/* EUR_CR_DPM_OUTOFMEM */
#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM                            (0x69CU)

/* EUR_CR_DPM_FREE_CONTEXT */
#define CSL_KLIO_EUR_CR_DPM_FREE_CONTEXT                        (0x6A0U)

/* EUR_CR_DPM_3D_TIMEOUT */
#define CSL_KLIO_EUR_CR_DPM_3D_TIMEOUT                          (0x6A4U)

/* EUR_CR_DPM_TA_EVM */
#define CSL_KLIO_EUR_CR_DPM_TA_EVM                              (0x6A8U)

/* This status register is read for a context switch, and reprogrammed on a
 * context load. */
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1          (0x700U)

/* This status register is read for a context switch, and reprogrammed on a
 * context load. */
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS1                (0x70CU)

/* This status register is read for a context switch, and reprogrammed on a
 * context load. */
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS2          (0x710U)

/* This status register is read for a context switch, and reprogrammed on a
 * context load. */
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS2                (0x71CU)

/* This status register is read for a context switch, and reprogrammed on a
 * context load. */
#define CSL_KLIO_EUR_CR_DPM_ABORT_STATUS_MTILE                  (0x720U)

/* This status register is read for a context switch, and reprogrammed on a
 * context load. */
#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS                         (0x724U)

/* This status register is read for a context switch, and reprogrammed on a
 * context load. */
#define CSL_KLIO_EUR_CR_DPM_PAGE                                (0x728U)

/* This status register is read for a context switch, and reprogrammed on a
 * context load. */
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS                  (0x72CU)

/* This status register is read for a context switch, and reprogrammed on a
 * context load. */
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE                         (0x730U)

/* EUR_CR_DPM_REQUESTING */
#define CSL_KLIO_EUR_CR_DPM_REQUESTING                          (0x734U)

/* EUR_CR_DPM_RGN_HDR_PARSER */
#define CSL_KLIO_EUR_CR_DPM_RGN_HDR_PARSER                      (0x738U)

/* EUR_CR_DPM_PIMSHARE */
#define CSL_KLIO_EUR_CR_DPM_PIMSHARE                            (0x73CU)

/* The TA context is drained out to memory on a context switch and restored on
 * a resume. */
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BASE                  (0x740U)

/* The TA context(reissue side) is drained out to memory on a context switch
 * and restored on a resume. */
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_STATUS                (0x744U)

/* A write to this register cause the dpm drained/resumed register clear */
#define CSL_KLIO_EUR_CR_DPM_DRAIN_STATUS                        (0x748U)

/* The TA context buffer size is drained out to memory on a context switch and
 * restored on a resume. */
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BUF                   (0x74CU)

/* report the mtile has been aborted in the particular TA
 * context,load/store/clear at the standard display list load/store/clear */
#define CSL_KLIO_EUR_CR_DPM_MTILE_ABORTED                       (0x750U)

/* EUR_CR_DPM_IDLE */
#define CSL_KLIO_EUR_CR_DPM_IDLE                                (0x754U)

/* EUR_CR_DPM_PAGE_MANAGEOP */
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP                       (0x670U)

/* report the mtile status TSP has reported which can be freed by DPM */
#define CSL_KLIO_EUR_CR_DPM_DEALLOCATE_MASK                     (0x7A4U)

/* enable MTE could force dpm to reissue page outstanding in MTE */
#define CSL_KLIO_EUR_CR_MTE_FORCEREISSUE                        (0x770U)

/* EUR_CR_DPM_PAGE_MANAGEOP_STATUS */
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_STATUS                (0x77CU)

/* report the mtile status TSP has requested which can be freed by DPM */
#define CSL_KLIO_EUR_CR_DPM_TSP_MTILEFREE                       (0x784U)

/* TCU global control register */
#define CSL_KLIO_EUR_CR_TCU_CTRL                                (0x804U)

/* TCU invalidate global control register */
#define CSL_KLIO_EUR_CR_TCU_ICTRL                               (0x808U)

/* Data Cache Unit Invalidate control register */
#define CSL_KLIO_EUR_CR_DCU_ICTRL                               (0x810U)

/* Data Cache Unit Partition control register */
#define CSL_KLIO_EUR_CR_DCU_PCTRL                               (0x814U)

/* Data Cache Unit Bypass/Cache off control register */
#define CSL_KLIO_EUR_CR_DCU_CTRL                                (0x818U)

/* EUR_CR_CLIP_CHECKSUM */
#define CSL_KLIO_EUR_CR_CLIP_CHECKSUM                           (0x900U)

/* EUR_CR_MTE_MEM_CHECKSUM */
#define CSL_KLIO_EUR_CR_MTE_MEM_CHECKSUM                        (0x904U)

/* EUR_CR_MTE_TE_CHECKSUM */
#define CSL_KLIO_EUR_CR_MTE_TE_CHECKSUM                         (0x908U)

/* EUR_CR_TE_CHECKSUM */
#define CSL_KLIO_EUR_CR_TE_CHECKSUM                             (0x90CU)

/* EUR_CR_ISP_FPU_CHECKSUM */
#define CSL_KLIO_EUR_CR_ISP_FPU_CHECKSUM                        (0x910U)

/* EUR_CR_ISP_PRECALC_CHECKSUM */
#define CSL_KLIO_EUR_CR_ISP_PRECALC_CHECKSUM                    (0x914U)

/* EUR_CR_ISP_EDGE_CHECKSUM */
#define CSL_KLIO_EUR_CR_ISP_EDGE_CHECKSUM                       (0x918U)

/* EUR_CR_ISP_TAGWRITE_CHECKSUM */
#define CSL_KLIO_EUR_CR_ISP_TAGWRITE_CHECKSUM                   (0x91CU)

/* EUR_CR_ISP_SPAN_CHECKSUM */
#define CSL_KLIO_EUR_CR_ISP_SPAN_CHECKSUM                       (0x920U)

/* EUR_CR_PBE_PIXEL_CHECKSUM */
#define CSL_KLIO_EUR_CR_PBE_PIXEL_CHECKSUM                      (0x924U)

/* EUR_CR_USE_CACHE */
#define CSL_KLIO_EUR_CR_USE_CACHE                               (0xA08U)

/* Enables general event bits into the PDS event data master for processing by
 * the PDS Micro Controller */
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2                       (0xA50U)

/* Enables PDS cache invalidation events bits into the PDS event data master
 * for processing by the PDS Micro Controller */
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE                        (0xA54U)

/* Enables general event bits into the PDS event data master for processing by
 * the PDS Micro Controller */
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE                        (0xA58U)

/* EUR_CR_EVENT_PIXEL_PDS_EXEC */
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_EXEC                    (0xA5CU)

/* EUR_CR_EVENT_PIXEL_PDS_DATA */
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_DATA                    (0xA60U)

/* EUR_CR_EVENT_PIXEL_PDS_INFO */
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_INFO                    (0xA64U)

/* EUR_CR_EVENT_OTHER_PDS_EXEC */
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_EXEC                    (0xA68U)

/* EUR_CR_EVENT_OTHER_PDS_DATA */
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_DATA                    (0xA6CU)

/* EUR_CR_EVENT_OTHER_PDS_INFO */
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO                    (0xA70U)

/* Control register used to disable individual data masters - '1' - disable
 * data master, '0' - enable data master */
#define CSL_KLIO_EUR_CR_DMS_CTRL                                (0xA74U)

/* EUR_CR_USE_G0 */
#define CSL_KLIO_EUR_CR_USE_G0                                  (0xA7CU)

/* EUR_CR_USE_G1 */
#define CSL_KLIO_EUR_CR_USE_G1                                  (0xA80U)

/* PDS Control Register 2 */
#define CSL_KLIO_EUR_CR_PDS_DMS_CTRL2                           (0xAB8U)

/* EUR_CR_PDS */
#define CSL_KLIO_EUR_CR_PDS                                     (0xABCU)

/* EUR_CR_PDS_INV0 */
#define CSL_KLIO_EUR_CR_PDS_INV0                                (0xAD0U)

/* EUR_CR_PDS_INV1 */
#define CSL_KLIO_EUR_CR_PDS_INV1                                (0xAD4U)

/* EUR_CR_PDS_INV3 */
#define CSL_KLIO_EUR_CR_PDS_INV3                                (0xADCU)

/* EUR_CR_PDS_INV_CSC */
#define CSL_KLIO_EUR_CR_PDS_INV_CSC                             (0xAE0U)

/* EUR_CR_PDS_DMS_DYNAMIC_SCHEDULE */
#define CSL_KLIO_EUR_CR_PDS_DMS_DYNAMIC_SCHEDULE                (0xAE4U)

/* Base Address in memory where the Kick Synchronisation data will be read
 * from */
#define CSL_KLIO_EUR_CR_EVENT_KICKER                            (0xAC4U)

/* EUR_CR_EVENT_KICK */
#define CSL_KLIO_EUR_CR_EVENT_KICK                              (0xAC8U)

/* EUR_CR_EVENT_KICK1 */
#define CSL_KLIO_EUR_CR_EVENT_KICK1                             (0xAB0U)

/* EUR_CR_EVENT_KICK2 */
#define CSL_KLIO_EUR_CR_EVENT_KICK2                             (0xAC0U)

/* EUR_CR_EVENT_KICK3 */
#define CSL_KLIO_EUR_CR_EVENT_KICK3                             (0xAD8U)

/* Load/Store Address for PDS Micro */
#define CSL_KLIO_EUR_CR_MICRO_DATA_BASE                         (0xBB0U)

/* EUR_CR_EVENT_KICK4 */
#define CSL_KLIO_EUR_CR_EVENT_KICK4                             (0xAACU)

/* The timer which runs at the core clock when enabled, decrementing from the
 * loaded value. Wraps when it hits 0 back to the starting value. A transition
 * through 0 creates an event, which can be enabled into either the PDS or the
 * Host status register. The timer can also be read/written from within the
 * PDS program. */
#define CSL_KLIO_EUR_CR_EVENT_TIMER                             (0xACCU)

/* This USE can issue loopback tasks through the PDS back to itself. This bit
 * indicates the status of this interface. A value of 1 indicates that there
 * are no pending loopback requests (for any USE pipeline), A value of 0
 * indicates that a loop task is pending, and that further loopback events may
 * cause the USE pipeline to wait until new resource becomes available.
 * Issuing loopback events when tasks are already pending is not recommended,
 * as this may result in system lockups. */
#define CSL_KLIO_EUR_CR_LOOPBACK                                (0xB04U)

/* EUR_CR_PDS_EVDM_PC_BASE */
#define CSL_KLIO_EUR_CR_PDS_EVDM_PC_BASE                        (0xB2CU)

/* EUR_CR_PDS_PDM_PC_BASE */
#define CSL_KLIO_EUR_CR_PDS_PDM_PC_BASE                         (0xB38U)

/* EUR_CR_PDS_STATUS */
#define CSL_KLIO_EUR_CR_PDS_STATUS                              (0xBA4U)

/* EUR_CR_PDS_CONTEXT_STORE */
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE                       (0xBA8U)

/* EUR_CR_PDS_CONTEXT_RESUME */
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_RESUME                      (0xBACU)

/* EUR_CR_BIF_CTRL */
#define CSL_KLIO_EUR_CR_BIF_CTRL                                (0xC00U)

/* EUR_CR_BIF_INT_STAT */
#define CSL_KLIO_EUR_CR_BIF_INT_STAT                            (0xC04U)

/* EUR_CR_BIF_FAULT */
#define CSL_KLIO_EUR_CR_BIF_FAULT                               (0xC08U)

/* EUR_CR_BIF_CTRL_INVAL */
#define CSL_KLIO_EUR_CR_BIF_CTRL_INVAL                          (0xC34U)

/* There are 2 internal request sources which can use memory tiling to improve
 * page break efficiency, these tiling regions are defined by an address range
 * and an enable. Any request address falling within the tiling range from the
 * 2 requesters will be translated. Tiled Memory Requestors: Texture Cache /
 * Pixel Cache, PixelBE The Tiling algorithm transposes address bits before
 * arbitration and MMU translation based on the X Tile Stride field defined in
 * this register: Address bits (n:8) are transposed with the next highest 4
 * address bits (n+4:n+1) where n = X Tile Stride, see the diagram in the
 * Memory Map and MMU Section of the TRM for more details */
#define CSL_KLIO_EUR_CR_BIF_TILE0                               (0xC0CU)

/* There are 2 internal request sources which can use memory tiling to improve
 * page break efficiency, these tiling regions are defined by an address range
 * and an enable. Any request address falling within the tiling range from the
 * 2 requesters will be translated. Tiled Memory Requestors: Texture Cache /
 * Pixel Cache, PixelBE */
#define CSL_KLIO_EUR_CR_BIF_TILE1                               (0xC10U)

/* There are 2 internal request sources which can use memory tiling to improve
 * page break efficiency, these tiling regions are defined by an address range
 * and an enable. Any request address falling within the tiling range from the
 * 2 requesters will be translated. Tiled Memory Requestors: Texture Cache /
 * Pixel Cache, PixelBE */
#define CSL_KLIO_EUR_CR_BIF_TILE2                               (0xC14U)

/* There are 2 internal request sources which can use memory tiling to improve
 * page break efficiency, these tiling regions are defined by an address range
 * and an enable. Any request address falling within the tiling range from the
 * 2 requesters will be translated. Tiled Memory Requestors: Texture Cache /
 * Pixel Cache, PixelBE */
#define CSL_KLIO_EUR_CR_BIF_TILE3                               (0xC18U)

/* There are 2 internal request sources which can use memory tiling to improve
 * page break efficiency, these tiling regions are defined by an address range
 * and an enable. Any request address falling within the tiling range from the
 * 2 requesters will be translated. Tiled Memory Requestors: Texture Cache /
 * Pixel Cache, PixelBE */
#define CSL_KLIO_EUR_CR_BIF_TILE4                               (0xC1CU)

/* There are 2 internal request sources which can use memory tiling to improve
 * page break efficiency, these tiling regions are defined by an address range
 * and an enable. Any request address falling within the tiling range from the
 * 2 requesters will be translated. Tiled Memory Requestors: Texture Cache /
 * Pixel Cache, PixelBE */
#define CSL_KLIO_EUR_CR_BIF_TILE5                               (0xC20U)

/* There are 2 internal request sources which can use memory tiling to improve
 * page break efficiency, these tiling regions are defined by an address range
 * and an enable. Any request address falling within the tiling range from the
 * 2 requesters will be translated. Tiled Memory Requestors: Texture Cache /
 * Pixel Cache, PixelBE */
#define CSL_KLIO_EUR_CR_BIF_TILE6                               (0xC24U)

/* There are 2 internal request sources which can use memory tiling to improve
 * page break efficiency, these tiling regions are defined by an address range
 * and an enable. Any request address falling within the tiling range from the
 * 2 requesters will be translated. Tiled Memory Requestors: Texture Cache /
 * Pixel Cache, PixelBE */
#define CSL_KLIO_EUR_CR_BIF_TILE7                               (0xC28U)

/* There are 2 internal request sources which can use memory tiling to improve
 * page break efficiency, these tiling regions are defined by an address range
 * and an enable. Any request address falling within the tiling range from the
 * 2 requesters will be translated. Tiled Memory Requestors: Texture Cache /
 * Pixel Cache, PixelBE */
#define CSL_KLIO_EUR_CR_BIF_TILE8                               (0xC2CU)

/* There are 2 internal request sources which can use memory tiling to improve
 * page break efficiency, these tiling regions are defined by an address range
 * and an enable. Any request address falling within the tiling range from the
 * 2 requesters will be translated. Tiled Memory Requestors: Texture Cache /
 * Pixel Cache, PixelBE */
#define CSL_KLIO_EUR_CR_BIF_TILE9                               (0xC30U)

/* EUR_CR_BIF_DIR_LIST_BASE0 */
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE0                      (0xC84U)

/* EUR_CR_BIF_DIR_LIST_BASE1 */
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE1                      (0xC38U)

/* EUR_CR_BIF_DIR_LIST_BASE2 */
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE2                      (0xC3CU)

/* EUR_CR_BIF_DIR_LIST_BASE3 */
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE3                      (0xC40U)

/* EUR_CR_BIF_DIR_LIST_BASE4 */
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE4                      (0xC44U)

/* EUR_CR_BIF_DIR_LIST_BASE5 */
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE5                      (0xC48U)

/* EUR_CR_BIF_DIR_LIST_BASE6 */
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE6                      (0xC4CU)

/* EUR_CR_BIF_DIR_LIST_BASE7 */
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE7                      (0xC50U)

/* Sets which bank of directories defined by the EUR_CR_BIF_BANK0/1 registers
 * is selected per requestor group, this allows for double buffered operation.
 * The 3D request group can optionally toggle banks based on an
 * ISP_START_RENDER event. The TA request group can optionally toggle banks
 * based on a VDM_START event. The remaining request groups; 2D, Host and EDM
 * can be toggled under software control by setting the bank select bit to
 * either 0 or 1. */
#define CSL_KLIO_EUR_CR_BIF_BANK_SET                            (0xC74U)

/* EUR_CR_BIF_BANK0 */
#define CSL_KLIO_EUR_CR_BIF_BANK0                               (0xC78U)

/* EUR_CR_BIF_BANK1 */
#define CSL_KLIO_EUR_CR_BIF_BANK1                               (0xC7CU)

/* EUR_CR_BIF_TA_REQ_BASE */
#define CSL_KLIO_EUR_CR_BIF_TA_REQ_BASE                         (0xC90U)

/* EUR_CR_BIF_MEM_REQ_STAT */
#define CSL_KLIO_EUR_CR_BIF_MEM_REQ_STAT                        (0xCA8U)

/* EUR_CR_BIF_3D_REQ_BASE */
#define CSL_KLIO_EUR_CR_BIF_3D_REQ_BASE                         (0xCACU)

/* EUR_CR_BIF_ZLS_REQ_BASE */
#define CSL_KLIO_EUR_CR_BIF_ZLS_REQ_BASE                        (0xCB0U)

/* EUR_CR_BIF_BANK_STATUS */
#define CSL_KLIO_EUR_CR_BIF_BANK_STATUS                         (0xCB4U)

/* EUR_CR_BIF_SIG0 */
#define CSL_KLIO_EUR_CR_BIF_SIG0                                (0xCC0U)

/* EUR_CR_BIF_SIG1 */
#define CSL_KLIO_EUR_CR_BIF_SIG1                                (0xCC4U)

/* EUR_CR_BIF_MMU_CTRL */
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL                            (0xCD0U)

/* EUR_CR_TWOD_SIG */
#define CSL_KLIO_EUR_CR_TWOD_SIG                                (0xE00U)

/* EUR_CR_TWOD_BLIT_STATUS */
#define CSL_KLIO_EUR_CR_TWOD_BLIT_STATUS                        (0xE04U)

/* EUR_CR_TWOD_TEST_MODE */
#define CSL_KLIO_EUR_CR_TWOD_TEST_MODE                          (0xE08U)

/* EUR_CR_TWOD_SIG_RESULT */
#define CSL_KLIO_EUR_CR_TWOD_SIG_RESULT                         (0xE0CU)

/* EUR_CR_TWOD_VIRTUAL_FIFO_0 */
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0                     (0xE10U)

/* EUR_CR_TWOD_VIRTUAL_FIFO_1 */
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1                     (0xE14U)

/* EUR_CR_AXI_CACHE */
#define CSL_KLIO_EUR_CR_AXI_CACHE                               (0xF00U)

/* EUR_CR_AXI_EXACCESS */
#define CSL_KLIO_EUR_CR_AXI_EXACCESS                            (0xF04U)

/* EUR_CR_EMU_CYCLE_COUNT */
#define CSL_KLIO_EUR_CR_EMU_CYCLE_COUNT                         (0xE80U)

/* EUR_CR_EMU_TA_PHASE */
#define CSL_KLIO_EUR_CR_EMU_TA_PHASE                            (0xE84U)

/* EUR_CR_EMU_3D_PHASE */
#define CSL_KLIO_EUR_CR_EMU_3D_PHASE                            (0xE88U)

/* EUR_CR_EMU_TA_CYCLE */
#define CSL_KLIO_EUR_CR_EMU_TA_CYCLE                            (0xE8CU)

/* EUR_CR_EMU_3D_CYCLE */
#define CSL_KLIO_EUR_CR_EMU_3D_CYCLE                            (0xE90U)

/* EUR_CR_EMU_INITIAL_TA_CYCLE */
#define CSL_KLIO_EUR_CR_EMU_INITIAL_TA_CYCLE                    (0xE94U)

/* EUR_CR_EMU_FINAL_3D_CYCLE */
#define CSL_KLIO_EUR_CR_EMU_FINAL_3D_CYCLE                      (0xE98U)

/* EUR_CR_EMU_MEM_READ */
#define CSL_KLIO_EUR_CR_EMU_MEM_READ                            (0xEB4U)

/* EUR_CR_EMU_TA_OR_3D_CYCLE */
#define CSL_KLIO_EUR_CR_EMU_TA_OR_3D_CYCLE                      (0xEB8U)

/* EUR_CR_EMU_MEM_WRITE */
#define CSL_KLIO_EUR_CR_EMU_MEM_WRITE                           (0xEBCU)

/* EUR_CR_EMU_MEM_BYTE_WRITE */
#define CSL_KLIO_EUR_CR_EMU_MEM_BYTE_WRITE                      (0xEC0U)

/* EUR_CR_EMU_MEM_STALL */
#define CSL_KLIO_EUR_CR_EMU_MEM_STALL                           (0xEC4U)

/* EUR_CR_BIF_CYCLE_COUNT */
#define CSL_KLIO_EUR_CR_BIF_CYCLE_COUNT                         (0xEC8U)

/* EUR_CR_BIF_MEM_READ_MMU */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_MMU                        (0xECCU)

/* EUR_CR_BIF_MEM_READ_CACHE */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_CACHE                      (0xED0U)

/* EUR_CR_BIF_MEM_READ_TA */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TA                         (0xED4U)

/* EUR_CR_BIF_MEM_WRITE_TA */
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_TA                        (0xED8U)

/* EUR_CR_BIF_MEM_READ_VDM */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_VDM                        (0xEDCU)

/* EUR_CR_BIF_MEM_READ_PBE */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PBE                        (0xEE0U)

/* EUR_CR_BIF_MEM_WRITE_PBE */
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_PBE                       (0xEE4U)

/* EUR_CR_BIF_MEM_READ_TSP */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TSP                        (0xEE8U)

/* EUR_CR_BIF_MEM_READ_ISP */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISP                        (0xEECU)

/* EUR_CR_BIF_MEM_READ_ISPZ */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISPZ                       (0xEF0U)

/* EUR_CR_BIF_MEM_WRITE_ISPZ */
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_ISPZ                      (0xEF4U)

/* EUR_CR_BIF_MEM_READ_USE0 */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE0                       (0xEF8U)

/* EUR_CR_BIF_MEM_WRITE_USE0 */
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE0                      (0xEFCU)

/* EUR_CR_BIF_MEM_READ_USE1 */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE1                       (0xF08U)

/* EUR_CR_BIF_MEM_WRITE_USE1 */
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE1                      (0xF0CU)

/* EUR_CR_BIF_MEM_READ_USEC */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USEC                       (0xF10U)

/* EUR_CR_BIF_MEM_READ_PDS */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PDS                        (0xF14U)

/* EUR_CR_BIF_MEM_READ_USE2 */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE2                       (0xF18U)

/* EUR_CR_BIF_MEM_WRITE_USE2 */
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE2                      (0xF1CU)

/* EUR_CR_BIF_MEM_READ_USE3 */
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE3                       (0xF20U)

/* EUR_CR_BIF_MEM_WRITE_USE3 */
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE3                      (0xF24U)

/* EUR_CR_USEC_BIF_CYCLE_COUNT */
#define CSL_KLIO_EUR_CR_USEC_BIF_CYCLE_COUNT                    (0xF28U)

/* EUR_CR_USEC_BIF_VERTEX_READ */
#define CSL_KLIO_EUR_CR_USEC_BIF_VERTEX_READ                    (0xF2CU)

/* EUR_CR_USEC_BIF_PIXEL_READ */
#define CSL_KLIO_EUR_CR_USEC_BIF_PIXEL_READ                     (0xF30U)

/* EUR_CR_USEC_BIF_EVENT_READ */
#define CSL_KLIO_EUR_CR_USEC_BIF_EVENT_READ                     (0xF34U)

/* EUR_CR_BIF_MEM_THREE_D_COUNT */
#define CSL_KLIO_EUR_CR_BIF_MEM_THREE_D_COUNT                   (0xF38U)

/* EUR_CR_BIF_MEM_OVER_LAPPED_TA_READ_COUNT */
#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_READ_COUNT       (0xF3CU)

/* EUR_CR_BIF_MEM_OVER_LAPPED_TA_WRITE_COUNT */
#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_WRITE_COUNT      (0xF40U)

/* EUR_CR_PARTITION_BREAKPOINT_TRAP */
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP               (0xF78U)

/* EUR_CR_PARTITION_BREAKPOINT */
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT                    (0xF7CU)

/* EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO0 */
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO0         (0xF80U)

/* EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1 */
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1         (0xF84U)

/* EUR_CR_SIM_3D_FRAME_COUNT */
#define CSL_KLIO_EUR_CR_SIM_3D_FRAME_COUNT                      (0x1000U)

/* EUR_CR_SIM_TA_FRAME_COUNT */
#define CSL_KLIO_EUR_CR_SIM_TA_FRAME_COUNT                      (0x1004U)

/* EUR_CR_SIM_USE_STATS */
#define CSL_KLIO_EUR_CR_SIM_USE_STATS                           (0x1008U)


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* EUR_CR_CLKGATECTL */

#define CSL_KLIO_EUR_CR_CLKGATECTL_SYSTEM_CLKG_MASK             (0x10000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_SYSTEM_CLKG_SHIFT            (28U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_SYSTEM_CLKG_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_SYSTEM_CLKG_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_AUTO_MAN_REG_MASK            (0x01000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_AUTO_MAN_REG_SHIFT           (24U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_AUTO_MAN_REG_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_AUTO_MAN_REG_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_BIF_CORE_CLKG_MASK           (0x00300000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_BIF_CORE_CLKG_SHIFT          (20U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_BIF_CORE_CLKG_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_BIF_CORE_CLKG_MAX            (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_TA_CLKG_MASK                 (0x000C0000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_TA_CLKG_SHIFT                (18U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_TA_CLKG_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_TA_CLKG_MAX                  (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_IDXFIFO_CLKG_MASK            (0x00030000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_IDXFIFO_CLKG_SHIFT           (16U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_IDXFIFO_CLKG_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_IDXFIFO_CLKG_MAX             (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_PDS_CLKG_MASK                (0x0000C000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_PDS_CLKG_SHIFT               (14U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_PDS_CLKG_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_PDS_CLKG_MAX                 (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_VDM_CLKG_MASK                (0x00003000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_VDM_CLKG_SHIFT               (12U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_VDM_CLKG_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_VDM_CLKG_MAX                 (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_DPM_CLKG_MASK                (0x00000C00U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_DPM_CLKG_SHIFT               (10U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_DPM_CLKG_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_DPM_CLKG_MAX                 (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_MTE_CLKG_MASK                (0x00000300U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_MTE_CLKG_SHIFT               (8U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_MTE_CLKG_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_MTE_CLKG_MAX                 (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_TE_CLKG_MASK                 (0x000000C0U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_TE_CLKG_SHIFT                (6U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_TE_CLKG_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_TE_CLKG_MAX                  (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_TSP_CLKG_MASK                (0x00000030U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_TSP_CLKG_SHIFT               (4U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_TSP_CLKG_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_TSP_CLKG_MAX                 (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_ISP2_CLKG_MASK               (0x0000000CU)
#define CSL_KLIO_EUR_CR_CLKGATECTL_ISP2_CLKG_SHIFT              (2U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_ISP2_CLKG_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_ISP2_CLKG_MAX                (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_ISP_CLKG_MASK                (0x00000003U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_ISP_CLKG_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_ISP_CLKG_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL_ISP_CLKG_MAX                 (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL_RESETVAL                     (0x00000000U)

/* EUR_CR_CLKGATECTL2 */

#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU0_L0L1_CLKG_MASK         (0x0C000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU0_L0L1_CLKG_SHIFT        (26U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU0_L0L1_CLKG_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU0_L0L1_CLKG_MAX          (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU1_L0L1_CLKG_MASK         (0x03000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU1_L0L1_CLKG_SHIFT        (24U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU1_L0L1_CLKG_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU1_L0L1_CLKG_MAX          (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU_L2_CLKG_MASK            (0x00C00000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU_L2_CLKG_SHIFT           (22U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU_L2_CLKG_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_DCU_L2_CLKG_MAX             (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_TEX1_CLKG_MASK              (0x000C0000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_TEX1_CLKG_SHIFT             (18U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_TEX1_CLKG_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_TEX1_CLKG_MAX               (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_ITR1_CLKG_MASK              (0x00030000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_ITR1_CLKG_SHIFT             (16U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_ITR1_CLKG_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_ITR1_CLKG_MAX               (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_USE1_CLKG_MASK              (0x0000C000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_USE1_CLKG_SHIFT             (14U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_USE1_CLKG_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_USE1_CLKG_MAX               (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_TEX0_CLKG_MASK              (0x00000C00U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_TEX0_CLKG_SHIFT             (10U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_TEX0_CLKG_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_TEX0_CLKG_MAX               (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_ITR0_CLKG_MASK              (0x00000300U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_ITR0_CLKG_SHIFT             (8U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_ITR0_CLKG_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_ITR0_CLKG_MAX               (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_USE0_CLKG_MASK              (0x000000C0U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_USE0_CLKG_SHIFT             (6U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_USE0_CLKG_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_USE0_CLKG_MAX               (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_UCACHEL2_CLKG_MASK          (0x00000030U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_UCACHEL2_CLKG_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_UCACHEL2_CLKG_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_UCACHEL2_CLKG_MAX           (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_TCU_L2_CLKG_MASK            (0x0000000CU)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_TCU_L2_CLKG_SHIFT           (2U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_TCU_L2_CLKG_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_TCU_L2_CLKG_MAX             (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_PBE_CLKG_MASK               (0x00000003U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_PBE_CLKG_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_PBE_CLKG_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTL2_PBE_CLKG_MAX                (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTL2_RESETVAL                    (0x00000000U)

/* EUR_CR_CLKGATESTATUS */

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_BIF_CORE_CLKS_MASK        (0x01000000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_BIF_CORE_CLKS_SHIFT       (24U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_BIF_CORE_CLKS_RESETVAL    (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_BIF_CORE_CLKS_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU1_L0L1_CLKS_MASK       (0x00800000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU1_L0L1_CLKS_SHIFT      (23U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU1_L0L1_CLKS_RESETVAL   (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU1_L0L1_CLKS_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU0_L0L1_CLKS_MASK       (0x00400000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU0_L0L1_CLKS_SHIFT      (22U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU0_L0L1_CLKS_RESETVAL   (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU0_L0L1_CLKS_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU_L2_CLKS_MASK          (0x00200000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU_L2_CLKS_SHIFT         (21U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU_L2_CLKS_RESETVAL      (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DCU_L2_CLKS_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TA_CLKS_MASK              (0x00100000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TA_CLKS_SHIFT             (20U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TA_CLKS_RESETVAL          (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TA_CLKS_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_IDXFIFO_CLKS_MASK         (0x00080000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_IDXFIFO_CLKS_SHIFT        (19U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_IDXFIFO_CLKS_RESETVAL     (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_IDXFIFO_CLKS_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TEX1_CLKS_MASK            (0x00020000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TEX1_CLKS_SHIFT           (17U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TEX1_CLKS_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TEX1_CLKS_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ITR1_CLKS_MASK            (0x00010000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ITR1_CLKS_SHIFT           (16U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ITR1_CLKS_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ITR1_CLKS_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_USE1_CLKS_MASK            (0x00008000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_USE1_CLKS_SHIFT           (15U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_USE1_CLKS_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_USE1_CLKS_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TEX0_CLKS_MASK            (0x00002000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TEX0_CLKS_SHIFT           (13U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TEX0_CLKS_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TEX0_CLKS_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ITR0_CLKS_MASK            (0x00001000U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ITR0_CLKS_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ITR0_CLKS_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ITR0_CLKS_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_USE0_CLKS_MASK            (0x00000800U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_USE0_CLKS_SHIFT           (11U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_USE0_CLKS_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_USE0_CLKS_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_UCACHEL2_CLKS_MASK        (0x00000400U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_UCACHEL2_CLKS_SHIFT       (10U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_UCACHEL2_CLKS_RESETVAL    (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_UCACHEL2_CLKS_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TCU_L2_CLKS_MASK          (0x00000200U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TCU_L2_CLKS_SHIFT         (9U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TCU_L2_CLKS_RESETVAL      (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TCU_L2_CLKS_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_PBE_CLKS_MASK             (0x00000100U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_PBE_CLKS_SHIFT            (8U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_PBE_CLKS_RESETVAL         (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_PBE_CLKS_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_PDS_CLKS_MASK             (0x00000080U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_PDS_CLKS_SHIFT            (7U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_PDS_CLKS_RESETVAL         (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_PDS_CLKS_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_VDM_CLKS_MASK             (0x00000040U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_VDM_CLKS_SHIFT            (6U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_VDM_CLKS_RESETVAL         (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_VDM_CLKS_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DPM_CLKS_MASK             (0x00000020U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DPM_CLKS_SHIFT            (5U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DPM_CLKS_RESETVAL         (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_DPM_CLKS_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_MTE_CLKS_MASK             (0x00000010U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_MTE_CLKS_SHIFT            (4U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_MTE_CLKS_RESETVAL         (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_MTE_CLKS_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TE_CLKS_MASK              (0x00000008U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TE_CLKS_SHIFT             (3U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TE_CLKS_RESETVAL          (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TE_CLKS_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TSP_CLKS_MASK             (0x00000004U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TSP_CLKS_SHIFT            (2U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TSP_CLKS_RESETVAL         (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_TSP_CLKS_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ISP2_CLKS_MASK            (0x00000002U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ISP2_CLKS_SHIFT           (1U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ISP2_CLKS_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ISP2_CLKS_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ISP_CLKS_MASK             (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ISP_CLKS_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ISP_CLKS_RESETVAL         (0x00000001U)
#define CSL_KLIO_EUR_CR_CLKGATESTATUS_ISP_CLKS_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_CLKGATESTATUS_RESETVAL                  (0x01fbbfffU)

/* EUR_CR_CLKGATECTLOVR */

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_BIF_CORE_CLKO_MASK        (0x00300000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_BIF_CORE_CLKO_SHIFT       (20U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_BIF_CORE_CLKO_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_BIF_CORE_CLKO_MAX         (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TA_CLKO_MASK              (0x000C0000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TA_CLKO_SHIFT             (18U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TA_CLKO_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TA_CLKO_MAX               (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_IDXFIFO_CLKO_MASK         (0x00030000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_IDXFIFO_CLKO_SHIFT        (16U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_IDXFIFO_CLKO_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_IDXFIFO_CLKO_MAX          (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_PDS_CLKO_MASK             (0x0000C000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_PDS_CLKO_SHIFT            (14U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_PDS_CLKO_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_PDS_CLKO_MAX              (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_VDM_CLKO_MASK             (0x00003000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_VDM_CLKO_SHIFT            (12U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_VDM_CLKO_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_VDM_CLKO_MAX              (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_DPM_CLKO_MASK             (0x00000C00U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_DPM_CLKO_SHIFT            (10U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_DPM_CLKO_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_DPM_CLKO_MAX              (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_MTE_CLKO_MASK             (0x00000300U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_MTE_CLKO_SHIFT            (8U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_MTE_CLKO_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_MTE_CLKO_MAX              (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TE_CLKO_MASK              (0x000000C0U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TE_CLKO_SHIFT             (6U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TE_CLKO_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TE_CLKO_MAX               (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TSP_CLKO_MASK             (0x00000030U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TSP_CLKO_SHIFT            (4U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TSP_CLKO_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_TSP_CLKO_MAX              (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_ISP2_CLKO_MASK            (0x0000000CU)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_ISP2_CLKO_SHIFT           (2U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_ISP2_CLKO_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_ISP2_CLKO_MAX             (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_ISP_CLKO_MASK             (0x00000003U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_ISP_CLKO_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_ISP_CLKO_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_ISP_CLKO_MAX              (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR_RESETVAL                  (0x00000000U)

/* EUR_CR_CLKGATECTLOVR2 */

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU1_L0L1_CLKO_MASK      (0x0C000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU1_L0L1_CLKO_SHIFT     (26U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU1_L0L1_CLKO_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU1_L0L1_CLKO_MAX       (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU0_L0L1_CLKO_MASK      (0x03000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU0_L0L1_CLKO_SHIFT     (24U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU0_L0L1_CLKO_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU0_L0L1_CLKO_MAX       (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU_L2_CLKO_MASK         (0x00C00000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU_L2_CLKO_SHIFT        (22U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU_L2_CLKO_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_DCU_L2_CLKO_MAX          (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TEX1_CLKO_MASK           (0x000C0000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TEX1_CLKO_SHIFT          (18U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TEX1_CLKO_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TEX1_CLKO_MAX            (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_ITR1_CLKO_MASK           (0x00030000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_ITR1_CLKO_SHIFT          (16U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_ITR1_CLKO_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_ITR1_CLKO_MAX            (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_USE1_CLKO_MASK           (0x0000C000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_USE1_CLKO_SHIFT          (14U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_USE1_CLKO_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_USE1_CLKO_MAX            (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TEX0_CLKO_MASK           (0x00000C00U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TEX0_CLKO_SHIFT          (10U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TEX0_CLKO_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TEX0_CLKO_MAX            (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_ITR0_CLKO_MASK           (0x00000300U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_ITR0_CLKO_SHIFT          (8U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_ITR0_CLKO_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_ITR0_CLKO_MAX            (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_USE0_CLKO_MASK           (0x000000C0U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_USE0_CLKO_SHIFT          (6U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_USE0_CLKO_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_USE0_CLKO_MAX            (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_UCACHEL2_CLKO_MASK       (0x00000030U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_UCACHEL2_CLKO_SHIFT      (4U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_UCACHEL2_CLKO_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_UCACHEL2_CLKO_MAX        (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TCU_L2_CLKO_MASK         (0x0000000CU)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TCU_L2_CLKO_SHIFT        (2U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TCU_L2_CLKO_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_TCU_L2_CLKO_MAX          (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_PBE_CLKO_MASK            (0x00000003U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_PBE_CLKO_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_PBE_CLKO_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_PBE_CLKO_MAX             (0x00000003U)

#define CSL_KLIO_EUR_CR_CLKGATECTLOVR2_RESETVAL                 (0x00000000U)

/* EUR_CR_POWER */

#define CSL_KLIO_EUR_CR_POWER_PIPE_DISABLE_MASK                 (0x00000001U)
#define CSL_KLIO_EUR_CR_POWER_PIPE_DISABLE_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_POWER_PIPE_DISABLE_RESETVAL             (0x00000001U)
#define CSL_KLIO_EUR_CR_POWER_PIPE_DISABLE_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_POWER_RESETVAL                          (0x00000001U)

/* EUR_CR_CORE_ID */

#define CSL_KLIO_EUR_CR_CORE_ID_ID_MASK                         (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_CORE_ID_ID_SHIFT                        (16U)
#define CSL_KLIO_EUR_CR_CORE_ID_ID_RESETVAL                     (0x00000119U)
#define CSL_KLIO_EUR_CR_CORE_ID_ID_MAX                          (0x0000ffffU)

#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_SLC_MASK                 (0x0000F000U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_SLC_SHIFT                (12U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_SLC_RESETVAL             (0x00000001U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_SLC_MAX                  (0x0000000fU)

#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_CORES_MASK               (0x00000F00U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_CORES_SHIFT              (8U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_CORES_RESETVAL           (0x00000002U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_CORES_MAX                (0x0000000fU)

#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_MASK                     (0x000000FCU)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_SHIFT                    (2U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_MAX                      (0x0000003fU)

#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_BASE_MASK                (0x00000002U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_BASE_SHIFT               (1U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_BASE_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_BASE_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_MULTI_MASK               (0x00000001U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_MULTI_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_MULTI_RESETVAL           (0x00000001U)
#define CSL_KLIO_EUR_CR_CORE_ID_CONFIG_MULTI_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_CORE_ID_RESETVAL                        (0x01191201U)

/* EUR_CR_CORE_REVISION */

#define CSL_KLIO_EUR_CR_CORE_REVISION_DESIGNER_MASK             (0xFF000000U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_DESIGNER_SHIFT            (24U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_DESIGNER_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_DESIGNER_MAX              (0x000000ffU)

#define CSL_KLIO_EUR_CR_CORE_REVISION_MAJOR_MASK                (0x00FF0000U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_MAJOR_SHIFT               (16U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_MAJOR_RESETVAL            (0x00000001U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_MAJOR_MAX                 (0x000000ffU)

#define CSL_KLIO_EUR_CR_CORE_REVISION_MINOR_MASK                (0x0000FF00U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_MINOR_SHIFT               (8U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_MINOR_RESETVAL            (0x00000001U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_MINOR_MAX                 (0x000000ffU)

#define CSL_KLIO_EUR_CR_CORE_REVISION_MAINTENANCE_MASK          (0x000000FFU)
#define CSL_KLIO_EUR_CR_CORE_REVISION_MAINTENANCE_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_MAINTENANCE_RESETVAL      (0x00000006U)
#define CSL_KLIO_EUR_CR_CORE_REVISION_MAINTENANCE_MAX           (0x000000ffU)

#define CSL_KLIO_EUR_CR_CORE_REVISION_RESETVAL                  (0x00010106U)

/* EUR_CR_DESIGNER_REV_FIELD1 */

#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD1_DESIGNER_REV_FIELD1_MASK  (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD1_DESIGNER_REV_FIELD1_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD1_DESIGNER_REV_FIELD1_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD1_DESIGNER_REV_FIELD1_MAX  (0xffffffffU)

#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD1_RESETVAL            (0x00000000U)

/* EUR_CR_DESIGNER_REV_FIELD2 */

#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD2_DESIGNER_REV_FIELD2_MASK  (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD2_DESIGNER_REV_FIELD2_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD2_DESIGNER_REV_FIELD2_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD2_DESIGNER_REV_FIELD2_MAX  (0xffffffffU)

#define CSL_KLIO_EUR_CR_DESIGNER_REV_FIELD2_RESETVAL            (0x00000000U)

/* EUR_CR_PERF */

#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_7_MASK             (0x00008000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_7_SHIFT            (15U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_7_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_7_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_6_MASK             (0x00004000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_6_SHIFT            (14U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_6_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_6_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_5_MASK             (0x00002000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_5_SHIFT            (13U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_5_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_5_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_4_MASK             (0x00001000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_4_SHIFT            (12U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_4_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_4_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_3_MASK             (0x00000800U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_3_SHIFT            (11U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_3_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_3_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_2_MASK             (0x00000400U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_2_SHIFT            (10U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_2_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_2_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_1_MASK             (0x00000200U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_1_SHIFT            (9U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_1_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_1_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_0_MASK             (0x00000100U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_0_SHIFT            (8U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_0_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_SUM_MUX_0_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_7_CLR_MASK                 (0x00000080U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_7_CLR_SHIFT                (7U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_7_CLR_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_7_CLR_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_6_CLR_MASK                 (0x00000040U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_6_CLR_SHIFT                (6U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_6_CLR_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_6_CLR_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_5_CLR_MASK                 (0x00000020U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_5_CLR_SHIFT                (5U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_5_CLR_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_5_CLR_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_4_CLR_MASK                 (0x00000010U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_4_CLR_SHIFT                (4U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_4_CLR_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_4_CLR_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_3_CLR_MASK                 (0x00000008U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_3_CLR_SHIFT                (3U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_3_CLR_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_3_CLR_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_2_CLR_MASK                 (0x00000004U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_2_CLR_SHIFT                (2U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_2_CLR_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_2_CLR_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_1_CLR_MASK                 (0x00000002U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_1_CLR_SHIFT                (1U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_1_CLR_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_1_CLR_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_0_CLR_MASK                 (0x00000001U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_0_CLR_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_0_CLR_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_0_CLR_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_RESETVAL                           (0x00000000U)

/* EUR_CR_PERF_COUNTER0 */

#define CSL_KLIO_EUR_CR_PERF_COUNTER0_ZERO_MASK                 (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_PERF_COUNTER0_ZERO_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER0_ZERO_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER0_ZERO_MAX                  (0xffffffffU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER0_RESETVAL                  (0x00000000U)

/* EUR_CR_PERF_COUNTER1 */

#define CSL_KLIO_EUR_CR_PERF_COUNTER1_ONE_MASK                  (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_PERF_COUNTER1_ONE_SHIFT                 (0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER1_ONE_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER1_ONE_MAX                   (0xffffffffU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER1_RESETVAL                  (0x00000000U)

/* EUR_CR_PERF_COUNTER2 */

#define CSL_KLIO_EUR_CR_PERF_COUNTER2_TWO_MASK                  (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_PERF_COUNTER2_TWO_SHIFT                 (0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER2_TWO_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER2_TWO_MAX                   (0xffffffffU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER2_RESETVAL                  (0x00000000U)

/* EUR_CR_PERF_COUNTER3 */

#define CSL_KLIO_EUR_CR_PERF_COUNTER3_THREE_MASK                (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_PERF_COUNTER3_THREE_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER3_THREE_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER3_THREE_MAX                 (0xffffffffU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER3_RESETVAL                  (0x00000000U)

/* EUR_CR_PERF_COUNTER4 */

#define CSL_KLIO_EUR_CR_PERF_COUNTER4_FOUR_MASK                 (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_PERF_COUNTER4_FOUR_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER4_FOUR_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER4_FOUR_MAX                  (0xffffffffU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER4_RESETVAL                  (0x00000000U)

/* EUR_CR_PERF_COUNTER5 */

#define CSL_KLIO_EUR_CR_PERF_COUNTER5_FIVE_MASK                 (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_PERF_COUNTER5_FIVE_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER5_FIVE_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER5_FIVE_MAX                  (0xffffffffU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER5_RESETVAL                  (0x00000000U)

/* EUR_CR_PERF_COUNTER6 */

#define CSL_KLIO_EUR_CR_PERF_COUNTER6_SIX_MASK                  (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_PERF_COUNTER6_SIX_SHIFT                 (0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER6_SIX_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER6_SIX_MAX                   (0xffffffffU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER6_RESETVAL                  (0x00000000U)

/* EUR_CR_PERF_COUNTER7 */

#define CSL_KLIO_EUR_CR_PERF_COUNTER7_SEVEN_MASK                (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_PERF_COUNTER7_SEVEN_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER7_SEVEN_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER7_SEVEN_MAX                 (0xffffffffU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER7_RESETVAL                  (0x00000000U)

/* EUR_CR_PERF_COUNTER_BIT */

#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_7_MASK          (0xF0000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_7_SHIFT         (28U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_7_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_7_MAX           (0x0000000fU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_6_MASK          (0x0F000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_6_SHIFT         (24U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_6_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_6_MAX           (0x0000000fU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_5_MASK          (0x00F00000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_5_SHIFT         (20U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_5_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_5_MAX           (0x0000000fU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_4_MASK          (0x000F0000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_4_SHIFT         (16U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_4_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_4_MAX           (0x0000000fU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_3_MASK          (0x0000F000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_3_SHIFT         (12U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_3_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_3_MAX           (0x0000000fU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_2_MASK          (0x00000F00U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_2_SHIFT         (8U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_2_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_2_MAX           (0x0000000fU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_1_MASK          (0x000000F0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_1_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_1_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_1_MAX           (0x0000000fU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_0_MASK          (0x0000000FU)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_0_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_0_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_SELECT_0_MAX           (0x0000000fU)

#define CSL_KLIO_EUR_CR_PERF_COUNTER_BIT_RESETVAL               (0x00000000U)

/* EUR_CR_DEBUG_REG0 */

#define CSL_KLIO_EUR_CR_DEBUG_REG0_ZERO_MASK                    (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_DEBUG_REG0_ZERO_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_DEBUG_REG0_ZERO_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_DEBUG_REG0_ZERO_MAX                     (0xffffffffU)

#define CSL_KLIO_EUR_CR_DEBUG_REG0_RESETVAL                     (0x00000000U)

/* EUR_CR_DEBUG_REG1 */

#define CSL_KLIO_EUR_CR_DEBUG_REG1_ZERO_MASK                    (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_DEBUG_REG1_ZERO_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_DEBUG_REG1_ZERO_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_DEBUG_REG1_ZERO_MAX                     (0xffffffffU)

#define CSL_KLIO_EUR_CR_DEBUG_REG1_RESETVAL                     (0x00000000U)

/* EUR_CR_PERF_DEBUG_CTRL */

#define CSL_KLIO_EUR_CR_PERF_DEBUG_CTRL_ENABLE_MASK             (0x00000001U)
#define CSL_KLIO_EUR_CR_PERF_DEBUG_CTRL_ENABLE_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_PERF_DEBUG_CTRL_ENABLE_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PERF_DEBUG_CTRL_ENABLE_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PERF_DEBUG_CTRL_RESETVAL                (0x00000000U)

/* EUR_CR_SOFT_RESET */

#define CSL_KLIO_EUR_CR_SOFT_RESET_DCU_L0L1_RESET_MASK          (0x00080000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_DCU_L0L1_RESET_SHIFT         (19U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_DCU_L0L1_RESET_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_DCU_L0L1_RESET_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_DCU_L2_RESET_MASK            (0x00040000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_DCU_L2_RESET_SHIFT           (18U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_DCU_L2_RESET_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_DCU_L2_RESET_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_TA_RESET_MASK                (0x00020000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TA_RESET_SHIFT               (17U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TA_RESET_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TA_RESET_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_IDXFIFO_RESET_MASK           (0x00010000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_IDXFIFO_RESET_SHIFT          (16U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_IDXFIFO_RESET_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_IDXFIFO_RESET_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_USE_RESET_MASK               (0x00008000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_USE_RESET_SHIFT              (15U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_USE_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_USE_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_TEX_RESET_MASK               (0x00004000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TEX_RESET_SHIFT              (14U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TEX_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TEX_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_ITR_RESET_MASK               (0x00002000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_ITR_RESET_SHIFT              (13U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_ITR_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_ITR_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_UCACHEL2_RESET_MASK          (0x00000800U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_UCACHEL2_RESET_SHIFT         (11U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_UCACHEL2_RESET_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_UCACHEL2_RESET_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_TCU_L2_RESET_MASK            (0x00000400U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TCU_L2_RESET_SHIFT           (10U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TCU_L2_RESET_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TCU_L2_RESET_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_PBE_RESET_MASK               (0x00000200U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_PBE_RESET_SHIFT              (9U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_PBE_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_PBE_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_PDS_RESET_MASK               (0x00000100U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_PDS_RESET_SHIFT              (8U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_PDS_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_PDS_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_TSP_RESET_MASK               (0x00000080U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TSP_RESET_SHIFT              (7U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TSP_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TSP_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_ISP2_RESET_MASK              (0x00000040U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_ISP2_RESET_SHIFT             (6U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_ISP2_RESET_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_ISP2_RESET_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_ISP_RESET_MASK               (0x00000020U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_ISP_RESET_SHIFT              (5U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_ISP_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_ISP_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_MTE_RESET_MASK               (0x00000010U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_MTE_RESET_SHIFT              (4U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_MTE_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_MTE_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_TE_RESET_MASK                (0x00000008U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TE_RESET_SHIFT               (3U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TE_RESET_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_TE_RESET_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_DPM_RESET_MASK               (0x00000004U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_DPM_RESET_SHIFT              (2U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_DPM_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_DPM_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_VDM_RESET_MASK               (0x00000002U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_VDM_RESET_SHIFT              (1U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_VDM_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_VDM_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_BIF_RESET_MASK               (0x00000001U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_BIF_RESET_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_BIF_RESET_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_SOFT_RESET_BIF_RESET_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_SOFT_RESET_RESETVAL                     (0x00000000U)

/* EUR_CR_TRIGGER */

#define CSL_KLIO_EUR_CR_TRIGGER_COUNT_MASK                      (0x0000003FU)
#define CSL_KLIO_EUR_CR_TRIGGER_COUNT_SHIFT                     (0U)
#define CSL_KLIO_EUR_CR_TRIGGER_COUNT_RESETVAL                  (0x0000000fU)
#define CSL_KLIO_EUR_CR_TRIGGER_COUNT_MAX                       (0x0000003fU)

#define CSL_KLIO_EUR_CR_TRIGGER_RESETVAL                        (0x0000000fU)

/* EUR_CR_EVENT_HOST_ENABLE2 */

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_MASK  (0x00000800U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_SHIFT  (11U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_TRAPPED_MASK  (0x00000400U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_TRAPPED_SHIFT  (10U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_TRAPPED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DATA_BREAKPOINT_TRAPPED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_MTE_CONTEXT_DRAINED_MASK  (0x00000200U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_MTE_CONTEXT_DRAINED_SHIFT  (9U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_MTE_CONTEXT_DRAINED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_MTE_CONTEXT_DRAINED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_ISP2_ZLS_CSW_FINISHED_MASK  (0x00000100U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_ISP2_ZLS_CSW_FINISHED_SHIFT  (8U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_ISP2_ZLS_CSW_FINISHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_ISP2_ZLS_CSW_FINISHED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DCU_INVALCOMPLETE_MASK  (0x00000080U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DCU_INVALCOMPLETE_SHIFT  (7U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_MTE_STATE_FLUSHED_MASK  (0x00000040U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_MTE_STATE_FLUSHED_SHIFT  (6U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_MTE_STATE_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_MTE_STATE_FLUSHED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TE_RGNHDR_INIT_COMPLETE_MASK  (0x00000020U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TE_RGNHDR_INIT_COMPLETE_SHIFT  (5U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TE_RGNHDR_INIT_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TE_RGNHDR_INIT_COMPLETE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_TA_MASK         (0x00000010U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_TA_SHIFT        (4U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_TA_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_TA_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_3D_MASK         (0x00000008U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_3D_SHIFT        (3U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_3D_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_3D_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_DL_MASK         (0x00000004U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_DL_SHIFT        (2U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_DL_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_TRIG_DL_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DPM_3D_FREE_LOAD_MASK  (0x00000002U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DPM_3D_FREE_LOAD_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DPM_3D_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DPM_3D_FREE_LOAD_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DPM_TA_FREE_LOAD_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DPM_TA_FREE_LOAD_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DPM_TA_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_DPM_TA_FREE_LOAD_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE2_RESETVAL             (0x00000000U)

/* EUR_CR_EVENT_HOST_CLEAR2 */

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_UNTRAPPED_MASK  (0x00000800U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_UNTRAPPED_SHIFT  (11U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_UNTRAPPED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_UNTRAPPED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_TRAPPED_MASK  (0x00000400U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_TRAPPED_SHIFT  (10U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_TRAPPED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DATA_BREAKPOINT_TRAPPED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_MTE_CONTEXT_DRAINED_MASK  (0x00000200U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_MTE_CONTEXT_DRAINED_SHIFT  (9U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_MTE_CONTEXT_DRAINED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_MTE_CONTEXT_DRAINED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_ISP2_ZLS_CSW_FINISHED_MASK  (0x00000100U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_ISP2_ZLS_CSW_FINISHED_SHIFT  (8U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_ISP2_ZLS_CSW_FINISHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_ISP2_ZLS_CSW_FINISHED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DCU_INVALCOMPLETE_MASK  (0x00000080U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DCU_INVALCOMPLETE_SHIFT  (7U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_MTE_STATE_FLUSHED_MASK  (0x00000040U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_MTE_STATE_FLUSHED_SHIFT  (6U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_MTE_STATE_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_MTE_STATE_FLUSHED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TE_RGNHDR_INIT_COMPLETE_MASK  (0x00000020U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TE_RGNHDR_INIT_COMPLETE_SHIFT  (5U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TE_RGNHDR_INIT_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TE_RGNHDR_INIT_COMPLETE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_TA_MASK          (0x00000010U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_TA_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_TA_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_TA_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_3D_MASK          (0x00000008U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_3D_SHIFT         (3U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_3D_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_3D_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_DL_MASK          (0x00000004U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_DL_SHIFT         (2U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_DL_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_TRIG_DL_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DPM_3D_FREE_LOAD_MASK  (0x00000002U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DPM_3D_FREE_LOAD_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DPM_3D_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DPM_3D_FREE_LOAD_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DPM_TA_FREE_LOAD_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DPM_TA_FREE_LOAD_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DPM_TA_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_DPM_TA_FREE_LOAD_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR2_RESETVAL              (0x00000000U)

/* EUR_CR_EVENT_STATUS2 */

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DATA_BREAKPOINT_UNTRAPPED_MASK  (0x00000800U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DATA_BREAKPOINT_UNTRAPPED_SHIFT  (11U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DATA_BREAKPOINT_UNTRAPPED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DATA_BREAKPOINT_UNTRAPPED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DATA_BREAKPOINT_TRAPPED_MASK  (0x00000400U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DATA_BREAKPOINT_TRAPPED_SHIFT  (10U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DATA_BREAKPOINT_TRAPPED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DATA_BREAKPOINT_TRAPPED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_MTE_CONTEXT_DRAINED_MASK  (0x00000200U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_MTE_CONTEXT_DRAINED_SHIFT  (9U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_MTE_CONTEXT_DRAINED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_MTE_CONTEXT_DRAINED_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_ISP2_ZLS_CSW_FINISHED_MASK  (0x00000100U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_ISP2_ZLS_CSW_FINISHED_SHIFT  (8U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_ISP2_ZLS_CSW_FINISHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_ISP2_ZLS_CSW_FINISHED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DCU_INVALCOMPLETE_MASK    (0x00000080U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DCU_INVALCOMPLETE_SHIFT   (7U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DCU_INVALCOMPLETE_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_MTE_STATE_FLUSHED_MASK    (0x00000040U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_MTE_STATE_FLUSHED_SHIFT   (6U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_MTE_STATE_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_MTE_STATE_FLUSHED_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TE_RGNHDR_INIT_COMPLETE_MASK  (0x00000020U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TE_RGNHDR_INIT_COMPLETE_SHIFT  (5U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TE_RGNHDR_INIT_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TE_RGNHDR_INIT_COMPLETE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_TA_MASK              (0x00000010U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_TA_SHIFT             (4U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_TA_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_TA_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_3D_MASK              (0x00000008U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_3D_SHIFT             (3U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_3D_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_3D_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_DL_MASK              (0x00000004U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_DL_SHIFT             (2U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_DL_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_TRIG_DL_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DPM_3D_FREE_LOAD_MASK     (0x00000002U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DPM_3D_FREE_LOAD_SHIFT    (1U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DPM_3D_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DPM_3D_FREE_LOAD_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DPM_TA_FREE_LOAD_MASK     (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DPM_TA_FREE_LOAD_SHIFT    (0U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DPM_TA_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS2_DPM_TA_FREE_LOAD_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS2_RESETVAL                  (0x00000000U)

/* EUR_CR_EVENT_STATUS */

#define CSL_KLIO_EUR_CR_EVENT_STATUS_MASTER_INTERRUPT_MASK      (0x80000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_MASTER_INTERRUPT_SHIFT     (31U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_MASTER_INTERRUPT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_MASTER_INTERRUPT_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_TIMER_MASK                 (0x20000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TIMER_SHIFT                (29U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TIMER_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TIMER_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_DPM_FAULT_MASK          (0x10000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_DPM_FAULT_SHIFT         (28U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_DPM_FAULT_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_DPM_FAULT_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_TCU_INVALCOMPLETE_MASK     (0x04000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TCU_INVALCOMPLETE_SHIFT    (26U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TCU_INVALCOMPLETE_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_ZLS_MASK  (0x02000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_ZLS_SHIFT  (25U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_ZLS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_ZLS_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_TA_MEM_FREE_MASK       (0x01000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_TA_MEM_FREE_SHIFT      (24U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_TA_MEM_FREE_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_TA_MEM_FREE_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_ISP_END_TILE_MASK          (0x00800000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_ISP_END_TILE_SHIFT         (23U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_ISP_END_TILE_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_ISP_END_TILE_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_INITEND_MASK           (0x00400000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_INITEND_SHIFT          (22U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_INITEND_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_INITEND_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_LOADED_MASK           (0x00200000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_LOADED_SHIFT          (21U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_LOADED_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_LOADED_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_INV_MASK              (0x00100000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_INV_SHIFT             (20U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_INV_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_INV_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_FLUSHED_MASK          (0x00080000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_FLUSHED_SHIFT         (19U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_FLUSHED_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_OTPM_FLUSHED_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_PIXELBE_END_RENDER_MASK    (0x00040000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_PIXELBE_END_RENDER_SHIFT   (18U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_PIXELBE_END_RENDER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_PIXELBE_END_RENDER_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_BREAKPOINT_MASK            (0x00008000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_BREAKPOINT_SHIFT           (15U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_BREAKPOINT_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_BREAKPOINT_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_SW_EVENT_MASK              (0x00004000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_SW_EVENT_SHIFT             (14U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_SW_EVENT_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_SW_EVENT_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_FINISHED_MASK           (0x00002000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_FINISHED_SHIFT          (13U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_FINISHED_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_FINISHED_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_TERMINATE_MASK          (0x00001000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_TERMINATE_SHIFT         (12U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_TERMINATE_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TA_TERMINATE_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_TPC_CLEAR_MASK             (0x00000800U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TPC_CLEAR_SHIFT            (11U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TPC_CLEAR_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TPC_CLEAR_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_TPC_FLUSH_MASK             (0x00000400U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TPC_FLUSH_SHIFT            (10U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TPC_FLUSH_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_TPC_FLUSH_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_CLEAR_MASK     (0x00000200U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_CLEAR_SHIFT    (9U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_CLEAR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_CLEAR_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_LOAD_MASK      (0x00000100U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_LOAD_SHIFT     (8U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_LOAD_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_STORE_MASK     (0x00000080U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_STORE_SHIFT    (7U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_STORE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_CONTROL_STORE_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_CLEAR_MASK       (0x00000040U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_CLEAR_SHIFT      (6U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_CLEAR_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_CLEAR_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_LOAD_MASK        (0x00000020U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_LOAD_SHIFT       (5U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_LOAD_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_LOAD_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_STORE_MASK       (0x00000010U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_STORE_SHIFT      (4U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_STORE_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_STATE_STORE_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_REACHED_MEM_THRESH_MASK  (0x00000008U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_REACHED_MEM_THRESH_SHIFT  (3U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_REACHED_MEM_THRESH_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_REACHED_MEM_THRESH_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_GBL_MASK  (0x00000004U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_GBL_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_GBL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_GBL_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_MT_MASK  (0x00000002U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_MT_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_MT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_OUT_OF_MEMORY_MT_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_3D_MEM_FREE_MASK       (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_3D_MEM_FREE_SHIFT      (0U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_3D_MEM_FREE_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_STATUS_DPM_3D_MEM_FREE_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_STATUS_RESETVAL                   (0x00000000U)

/* EUR_CR_EVENT_HOST_ENABLE */

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_MASTER_INTERRUPT_MASK  (0x80000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_MASTER_INTERRUPT_SHIFT  (31U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_MASTER_INTERRUPT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_MASTER_INTERRUPT_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TIMER_MASK            (0x20000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TIMER_SHIFT           (29U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TIMER_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TIMER_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_DPM_FAULT_MASK     (0x10000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_DPM_FAULT_SHIFT    (28U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_DPM_FAULT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_DPM_FAULT_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TCU_INVALCOMPLETE_MASK  (0x04000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TCU_INVALCOMPLETE_SHIFT  (26U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_ZLS_MASK  (0x02000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_ZLS_SHIFT  (25U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_ZLS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_ZLS_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_TA_MEM_FREE_MASK  (0x01000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_TA_MEM_FREE_SHIFT  (24U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_TA_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_TA_MEM_FREE_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_ISP_END_TILE_MASK     (0x00800000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_ISP_END_TILE_SHIFT    (23U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_ISP_END_TILE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_ISP_END_TILE_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_INITEND_MASK      (0x00400000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_INITEND_SHIFT     (22U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_INITEND_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_INITEND_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_LOADED_MASK      (0x00200000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_LOADED_SHIFT     (21U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_LOADED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_LOADED_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_INV_MASK         (0x00100000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_INV_SHIFT        (20U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_INV_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_INV_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_FLUSHED_MASK     (0x00080000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_FLUSHED_SHIFT    (19U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_OTPM_FLUSHED_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_PIXELBE_END_RENDER_MASK  (0x00040000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_PIXELBE_END_RENDER_SHIFT  (18U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_PIXELBE_END_RENDER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_PIXELBE_END_RENDER_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_BREAKPOINT_MASK       (0x00008000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_BREAKPOINT_SHIFT      (15U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_BREAKPOINT_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_BREAKPOINT_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_SW_EVENT_MASK         (0x00004000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_SW_EVENT_SHIFT        (14U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_SW_EVENT_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_SW_EVENT_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_FINISHED_MASK      (0x00002000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_FINISHED_SHIFT     (13U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_FINISHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_FINISHED_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_TERMINATE_MASK     (0x00001000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_TERMINATE_SHIFT    (12U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_TERMINATE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TA_TERMINATE_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TPC_CLEAR_MASK        (0x00000800U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TPC_CLEAR_SHIFT       (11U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TPC_CLEAR_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TPC_CLEAR_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TPC_FLUSH_MASK        (0x00000400U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TPC_FLUSH_SHIFT       (10U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TPC_FLUSH_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_TPC_FLUSH_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_CLEAR_MASK  (0x00000200U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_CLEAR_SHIFT  (9U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_CLEAR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_CLEAR_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_LOAD_MASK  (0x00000100U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_LOAD_SHIFT  (8U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_LOAD_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_STORE_MASK  (0x00000080U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_STORE_SHIFT  (7U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_STORE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_CONTROL_STORE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_CLEAR_MASK  (0x00000040U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_CLEAR_SHIFT  (6U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_CLEAR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_CLEAR_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_LOAD_MASK   (0x00000020U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_LOAD_SHIFT  (5U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_LOAD_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_STORE_MASK  (0x00000010U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_STORE_SHIFT  (4U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_STORE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_STATE_STORE_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_REACHED_MEM_THRESH_MASK  (0x00000008U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_REACHED_MEM_THRESH_SHIFT  (3U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_REACHED_MEM_THRESH_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_REACHED_MEM_THRESH_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_GBL_MASK  (0x00000004U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_GBL_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_GBL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_GBL_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_MT_MASK  (0x00000002U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_MT_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_MT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_OUT_OF_MEMORY_MT_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_3D_MEM_FREE_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_3D_MEM_FREE_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_3D_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_DPM_3D_MEM_FREE_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_ENABLE_RESETVAL              (0x00000000U)

/* EUR_CR_EVENT_HOST_CLEAR */

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_MASTER_INTERRUPT_MASK  (0x80000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_MASTER_INTERRUPT_SHIFT  (31U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_MASTER_INTERRUPT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_MASTER_INTERRUPT_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TIMER_MASK             (0x20000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TIMER_SHIFT            (29U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TIMER_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TIMER_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_DPM_FAULT_MASK      (0x10000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_DPM_FAULT_SHIFT     (28U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_DPM_FAULT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_DPM_FAULT_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TCU_INVALCOMPLETE_MASK  (0x04000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TCU_INVALCOMPLETE_SHIFT  (26U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_ZLS_MASK  (0x02000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_ZLS_SHIFT  (25U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_ZLS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_ZLS_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_TA_MEM_FREE_MASK   (0x01000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_TA_MEM_FREE_SHIFT  (24U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_TA_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_TA_MEM_FREE_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_ISP_END_TILE_MASK      (0x00800000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_ISP_END_TILE_SHIFT     (23U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_ISP_END_TILE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_ISP_END_TILE_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_INITEND_MASK       (0x00400000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_INITEND_SHIFT      (22U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_INITEND_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_INITEND_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_LOADED_MASK       (0x00200000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_LOADED_SHIFT      (21U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_LOADED_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_LOADED_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_INV_MASK          (0x00100000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_INV_SHIFT         (20U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_INV_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_INV_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_FLUSHED_MASK      (0x00080000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_FLUSHED_SHIFT     (19U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_OTPM_FLUSHED_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_PIXELBE_END_RENDER_MASK  (0x00040000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_PIXELBE_END_RENDER_SHIFT  (18U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_PIXELBE_END_RENDER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_PIXELBE_END_RENDER_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_BREAKPOINT_MASK        (0x00008000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_BREAKPOINT_SHIFT       (15U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_BREAKPOINT_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_BREAKPOINT_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_SW_EVENT_MASK          (0x00004000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_SW_EVENT_SHIFT         (14U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_SW_EVENT_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_SW_EVENT_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_FINISHED_MASK       (0x00002000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_FINISHED_SHIFT      (13U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_FINISHED_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_FINISHED_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_TERMINATE_MASK      (0x00001000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_TERMINATE_SHIFT     (12U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_TERMINATE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TA_TERMINATE_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TPC_CLEAR_MASK         (0x00000800U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TPC_CLEAR_SHIFT        (11U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TPC_CLEAR_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TPC_CLEAR_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TPC_FLUSH_MASK         (0x00000400U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TPC_FLUSH_SHIFT        (10U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TPC_FLUSH_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_TPC_FLUSH_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_CLEAR_MASK  (0x00000200U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_CLEAR_SHIFT  (9U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_CLEAR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_CLEAR_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_LOAD_MASK  (0x00000100U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_LOAD_SHIFT  (8U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_LOAD_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_STORE_MASK  (0x00000080U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_STORE_SHIFT  (7U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_STORE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_CONTROL_STORE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_CLEAR_MASK   (0x00000040U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_CLEAR_SHIFT  (6U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_CLEAR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_CLEAR_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_LOAD_MASK    (0x00000020U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_LOAD_SHIFT   (5U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_LOAD_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_STORE_MASK   (0x00000010U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_STORE_SHIFT  (4U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_STORE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_STATE_STORE_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_REACHED_MEM_THRESH_MASK  (0x00000008U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_REACHED_MEM_THRESH_SHIFT  (3U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_REACHED_MEM_THRESH_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_REACHED_MEM_THRESH_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_GBL_MASK  (0x00000004U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_GBL_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_GBL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_GBL_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_MT_MASK  (0x00000002U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_MT_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_MT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_OUT_OF_MEMORY_MT_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_3D_MEM_FREE_MASK   (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_3D_MEM_FREE_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_3D_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_DPM_3D_MEM_FREE_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_HOST_CLEAR_RESETVAL               (0x00000000U)

/* EUR_CR_PDS_CACHE_STATUS */

#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV3_MASK          (0x00000010U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV3_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV3_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV3_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV1_MASK          (0x00000004U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV1_SHIFT         (2U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV1_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV1_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV0_MASK          (0x00000002U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV0_SHIFT         (1U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV0_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_DSC_INV0_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_CSC_INV_MASK           (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_CSC_INV_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_CSC_INV_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_CSC_INV_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_STATUS_RESETVAL               (0x00000000U)

/* EUR_CR_PDS_CACHE_HOST_ENABLE */

#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV3_MASK     (0x00000010U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV3_SHIFT    (4U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV3_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV3_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV1_MASK     (0x00000004U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV1_SHIFT    (2U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV1_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV1_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV0_MASK     (0x00000002U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV0_SHIFT    (1U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV0_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_DSC_INV0_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_CSC_INV_MASK      (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_CSC_INV_SHIFT     (0U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_CSC_INV_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_CSC_INV_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_ENABLE_RESETVAL          (0x00000000U)

/* EUR_CR_PDS_CACHE_HOST_CLEAR */

#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV3_MASK      (0x00000010U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV3_SHIFT     (4U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV3_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV3_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV1_MASK      (0x00000004U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV1_SHIFT     (2U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV1_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV1_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV0_MASK      (0x00000002U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV0_SHIFT     (1U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV0_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_DSC_INV0_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_CSC_INV_MASK       (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_CSC_INV_SHIFT      (0U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_CSC_INV_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_CSC_INV_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_HOST_CLEAR_RESETVAL           (0x00000000U)

/* EUR_CR_TIMER */

#define CSL_KLIO_EUR_CR_TIMER_VALUE_MASK                        (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_TIMER_VALUE_SHIFT                       (0U)
#define CSL_KLIO_EUR_CR_TIMER_VALUE_RESETVAL                    (0x00000000U)
#define CSL_KLIO_EUR_CR_TIMER_VALUE_MAX                         (0xffffffffU)

#define CSL_KLIO_EUR_CR_TIMER_RESETVAL                          (0x00000000U)

/* EUR_CR_DOUBLE_PIXEL_PARTITIONS */

#define CSL_KLIO_EUR_CR_DOUBLE_PIXEL_PARTITIONS_VALUE_MASK      (0x00000001U)
#define CSL_KLIO_EUR_CR_DOUBLE_PIXEL_PARTITIONS_VALUE_SHIFT     (0U)
#define CSL_KLIO_EUR_CR_DOUBLE_PIXEL_PARTITIONS_VALUE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DOUBLE_PIXEL_PARTITIONS_VALUE_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_DOUBLE_PIXEL_PARTITIONS_RESETVAL        (0x00000000U)

/* EUR_CR_VDM_START */

#define CSL_KLIO_EUR_CR_VDM_START_PULSE_MASK                    (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_START_PULSE_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_VDM_START_PULSE_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_START_PULSE_MAX                     (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_START_RESETVAL                      (0x00000000U)

/* EUR_CR_TE_RGNHDR_INIT */

#define CSL_KLIO_EUR_CR_TE_RGNHDR_INIT_PULSE_MASK               (0x00000001U)
#define CSL_KLIO_EUR_CR_TE_RGNHDR_INIT_PULSE_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_TE_RGNHDR_INIT_PULSE_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_RGNHDR_INIT_PULSE_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_RGNHDR_INIT_RESETVAL                 (0x00000000U)

/* EUR_CR_TE_AA */

#define CSL_KLIO_EUR_CR_TE_AA_X_MASK                            (0x80000000U)
#define CSL_KLIO_EUR_CR_TE_AA_X_SHIFT                           (31U)
#define CSL_KLIO_EUR_CR_TE_AA_X_RESETVAL                        (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_AA_X_MAX                             (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_AA_Y_MASK                            (0x40000000U)
#define CSL_KLIO_EUR_CR_TE_AA_Y_SHIFT                           (30U)
#define CSL_KLIO_EUR_CR_TE_AA_Y_RESETVAL                        (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_AA_Y_MAX                             (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_AA_RESETVAL                          (0x00000000U)

/* EUR_CR_TE_MTILE1 */

#define CSL_KLIO_EUR_CR_TE_MTILE1_NUMBER_MASK                   (0x80000000U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_NUMBER_SHIFT                  (31U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_NUMBER_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_NUMBER_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_MTILE1_X1_MASK                       (0x3FC00000U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_X1_SHIFT                      (22U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_X1_RESETVAL                   (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_X1_MAX                        (0x000000ffU)

#define CSL_KLIO_EUR_CR_TE_MTILE1_X2_MASK                       (0x000FF000U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_X2_SHIFT                      (12U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_X2_RESETVAL                   (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_X2_MAX                        (0x000000ffU)

#define CSL_KLIO_EUR_CR_TE_MTILE1_X3_MASK                       (0x000000FFU)
#define CSL_KLIO_EUR_CR_TE_MTILE1_X3_SHIFT                      (0U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_X3_RESETVAL                   (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_MTILE1_X3_MAX                        (0x000000ffU)

#define CSL_KLIO_EUR_CR_TE_MTILE1_RESETVAL                      (0x00000000U)

/* EUR_CR_TE_MTILE2 */

#define CSL_KLIO_EUR_CR_TE_MTILE2_Y1_MASK                       (0x3FC00000U)
#define CSL_KLIO_EUR_CR_TE_MTILE2_Y1_SHIFT                      (22U)
#define CSL_KLIO_EUR_CR_TE_MTILE2_Y1_RESETVAL                   (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_MTILE2_Y1_MAX                        (0x000000ffU)

#define CSL_KLIO_EUR_CR_TE_MTILE2_Y2_MASK                       (0x000FF000U)
#define CSL_KLIO_EUR_CR_TE_MTILE2_Y2_SHIFT                      (12U)
#define CSL_KLIO_EUR_CR_TE_MTILE2_Y2_RESETVAL                   (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_MTILE2_Y2_MAX                        (0x000000ffU)

#define CSL_KLIO_EUR_CR_TE_MTILE2_Y3_MASK                       (0x000000FFU)
#define CSL_KLIO_EUR_CR_TE_MTILE2_Y3_SHIFT                      (0U)
#define CSL_KLIO_EUR_CR_TE_MTILE2_Y3_RESETVAL                   (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_MTILE2_Y3_MAX                        (0x000000ffU)

#define CSL_KLIO_EUR_CR_TE_MTILE2_RESETVAL                      (0x00000000U)

/* EUR_CR_TE_SCREEN */

#define CSL_KLIO_EUR_CR_TE_SCREEN_YMAX_MASK                     (0x000FF000U)
#define CSL_KLIO_EUR_CR_TE_SCREEN_YMAX_SHIFT                    (12U)
#define CSL_KLIO_EUR_CR_TE_SCREEN_YMAX_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_SCREEN_YMAX_MAX                      (0x000000ffU)

#define CSL_KLIO_EUR_CR_TE_SCREEN_XMAX_MASK                     (0x000000FFU)
#define CSL_KLIO_EUR_CR_TE_SCREEN_XMAX_SHIFT                    (0U)
#define CSL_KLIO_EUR_CR_TE_SCREEN_XMAX_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_SCREEN_XMAX_MAX                      (0x000000ffU)

#define CSL_KLIO_EUR_CR_TE_SCREEN_RESETVAL                      (0x00000000U)

/* EUR_CR_TE_MTILE */

#define CSL_KLIO_EUR_CR_TE_MTILE_STRIDE_MASK                    (0x0003FFFFU)
#define CSL_KLIO_EUR_CR_TE_MTILE_STRIDE_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_TE_MTILE_STRIDE_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_MTILE_STRIDE_MAX                     (0x0003ffffU)

#define CSL_KLIO_EUR_CR_TE_MTILE_RESETVAL                       (0x00000000U)

/* EUR_CR_TE_PSG */

#define CSL_KLIO_EUR_CR_TE_PSG_EXTERNALZBUFFER_MASK             (0x02000000U)
#define CSL_KLIO_EUR_CR_TE_PSG_EXTERNALZBUFFER_SHIFT            (25U)
#define CSL_KLIO_EUR_CR_TE_PSG_EXTERNALZBUFFER_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_PSG_EXTERNALZBUFFER_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_PSG_ENABLE_CONTEXT_STATE_RESTORE_MASK  (0x01000000U)
#define CSL_KLIO_EUR_CR_TE_PSG_ENABLE_CONTEXT_STATE_RESTORE_SHIFT  (24U)
#define CSL_KLIO_EUR_CR_TE_PSG_ENABLE_CONTEXT_STATE_RESTORE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_PSG_ENABLE_CONTEXT_STATE_RESTORE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_PSG_ZONLYRENDER_MASK                 (0x00800000U)
#define CSL_KLIO_EUR_CR_TE_PSG_ZONLYRENDER_SHIFT                (23U)
#define CSL_KLIO_EUR_CR_TE_PSG_ZONLYRENDER_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_PSG_ZONLYRENDER_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_PSG_COMPLETEONTERMINATE_MASK         (0x00400000U)
#define CSL_KLIO_EUR_CR_TE_PSG_COMPLETEONTERMINATE_SHIFT        (22U)
#define CSL_KLIO_EUR_CR_TE_PSG_COMPLETEONTERMINATE_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_PSG_COMPLETEONTERMINATE_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_PSG_ZLOADENABLE_MASK                 (0x00200000U)
#define CSL_KLIO_EUR_CR_TE_PSG_ZLOADENABLE_SHIFT                (21U)
#define CSL_KLIO_EUR_CR_TE_PSG_ZLOADENABLE_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_PSG_ZLOADENABLE_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_PSG_ZSTOREENABLE_MASK                (0x00100000U)
#define CSL_KLIO_EUR_CR_TE_PSG_ZSTOREENABLE_SHIFT               (20U)
#define CSL_KLIO_EUR_CR_TE_PSG_ZSTOREENABLE_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_PSG_ZSTOREENABLE_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_PSG_PADZEROS_MASK                    (0x00080000U)
#define CSL_KLIO_EUR_CR_TE_PSG_PADZEROS_SHIFT                   (19U)
#define CSL_KLIO_EUR_CR_TE_PSG_PADZEROS_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_PSG_PADZEROS_MAX                     (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_PSG_FORCENEWSTATE_MASK               (0x00040000U)
#define CSL_KLIO_EUR_CR_TE_PSG_FORCENEWSTATE_SHIFT              (18U)
#define CSL_KLIO_EUR_CR_TE_PSG_FORCENEWSTATE_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_PSG_FORCENEWSTATE_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_PSG_RESETVAL                         (0x00000000U)

/* EUR_CR_TE_PSGREGION_BASE */

#define CSL_KLIO_EUR_CR_TE_PSGREGION_BASE_ADDR_MASK             (0xFFFFFFC0U)
#define CSL_KLIO_EUR_CR_TE_PSGREGION_BASE_ADDR_SHIFT            (6U)
#define CSL_KLIO_EUR_CR_TE_PSGREGION_BASE_ADDR_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_PSGREGION_BASE_ADDR_MAX              (0x03ffffffU)

#define CSL_KLIO_EUR_CR_TE_PSGREGION_BASE_RESETVAL              (0x00000000U)

/* EUR_CR_TE_TPC_BASE */

#define CSL_KLIO_EUR_CR_TE_TPC_BASE_ADDR_MASK                   (0xFFFFFFC0U)
#define CSL_KLIO_EUR_CR_TE_TPC_BASE_ADDR_SHIFT                  (6U)
#define CSL_KLIO_EUR_CR_TE_TPC_BASE_ADDR_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_TPC_BASE_ADDR_MAX                    (0x03ffffffU)

#define CSL_KLIO_EUR_CR_TE_TPC_BASE_RESETVAL                    (0x00000000U)

/* EUR_CR_TE_TPCCONTROL */

#define CSL_KLIO_EUR_CR_TE_TPCCONTROL_CLEAR_MASK                (0x80000000U)
#define CSL_KLIO_EUR_CR_TE_TPCCONTROL_CLEAR_SHIFT               (31U)
#define CSL_KLIO_EUR_CR_TE_TPCCONTROL_CLEAR_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_TPCCONTROL_CLEAR_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_TPCCONTROL_FLUSH_MASK                (0x40000000U)
#define CSL_KLIO_EUR_CR_TE_TPCCONTROL_FLUSH_SHIFT               (30U)
#define CSL_KLIO_EUR_CR_TE_TPCCONTROL_FLUSH_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_TPCCONTROL_FLUSH_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_TPCCONTROL_RESETVAL                  (0x00000000U)

/* EUR_CR_TE_RGNBBOX_X */

#define CSL_KLIO_EUR_CR_TE_RGNBBOX_X_MAX_MASK                   (0x01FF0000U)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_X_MAX_SHIFT                  (16U)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_X_MAX_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_X_MAX_MAX                    (0x000001ffU)

#define CSL_KLIO_EUR_CR_TE_RGNBBOX_X_MIN_MASK                   (0x000001FFU)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_X_MIN_SHIFT                  (0U)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_X_MIN_RESETVAL               (0x000001ffU)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_X_MIN_MAX                    (0x000001ffU)

#define CSL_KLIO_EUR_CR_TE_RGNBBOX_X_RESETVAL                   (0x000001ffU)

/* EUR_CR_TE_RGNBBOX_Y */

#define CSL_KLIO_EUR_CR_TE_RGNBBOX_Y_MAX_MASK                   (0x01FF0000U)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_Y_MAX_SHIFT                  (16U)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_Y_MAX_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_Y_MAX_MAX                    (0x000001ffU)

#define CSL_KLIO_EUR_CR_TE_RGNBBOX_Y_MIN_MASK                   (0x000001FFU)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_Y_MIN_SHIFT                  (0U)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_Y_MIN_RESETVAL               (0x000001ffU)
#define CSL_KLIO_EUR_CR_TE_RGNBBOX_Y_MIN_MAX                    (0x000001ffU)

#define CSL_KLIO_EUR_CR_TE_RGNBBOX_Y_RESETVAL                   (0x000001ffU)

/* EUR_CR_MTE_OTPM_CSM_FLUSH_BASE */

#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_FLUSH_BASE_ADDR_MASK       (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_FLUSH_BASE_ADDR_SHIFT      (4U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_FLUSH_BASE_ADDR_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_FLUSH_BASE_ADDR_MAX        (0x0fffffffU)

#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_FLUSH_BASE_RESETVAL        (0x00000000U)

/* EUR_CR_MTE_OTPM_CSM_LOAD_BASE */

#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_LOAD_BASE_ADDR_MASK        (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_LOAD_BASE_ADDR_SHIFT       (4U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_LOAD_BASE_ADDR_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_LOAD_BASE_ADDR_MAX         (0x0fffffffU)

#define CSL_KLIO_EUR_CR_MTE_OTPM_CSM_LOAD_BASE_RESETVAL         (0x00000000U)

/* EUR_CR_VDM_CTRL_STREAM_BASE */

#define CSL_KLIO_EUR_CR_VDM_CTRL_STREAM_BASE_ADDR_MASK          (0xFFFFFFFCU)
#define CSL_KLIO_EUR_CR_VDM_CTRL_STREAM_BASE_ADDR_SHIFT         (2U)
#define CSL_KLIO_EUR_CR_VDM_CTRL_STREAM_BASE_ADDR_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CTRL_STREAM_BASE_ADDR_MAX           (0x3fffffffU)

#define CSL_KLIO_EUR_CR_VDM_CTRL_STREAM_BASE_RESETVAL           (0x00000000U)

/* EUR_CR_VDM_BATCH_NUM */

#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_VALUE_MASK                (0x00003FFEU)
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_VALUE_SHIFT               (1U)
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_VALUE_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_VALUE_MAX                 (0x00001fffU)

#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_LOAD_MASK                 (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_LOAD_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_LOAD_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_LOAD_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_RESETVAL                  (0x00000000U)

/* EUR_CR_VDM_BATCH_NUM_STATUS */

#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_STATUS_VALUE_MASK         (0x00001FFFU)
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_STATUS_VALUE_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_STATUS_VALUE_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_STATUS_VALUE_MAX          (0x00001fffU)

#define CSL_KLIO_EUR_CR_VDM_BATCH_NUM_STATUS_RESETVAL           (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD0 */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD0_DATA_MASK  (0x00FFFFFFU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD0_DATA_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD0_DATA_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD0_DATA_MAX  (0x00ffffffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD0_RESETVAL  (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD1 */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD1_DATA_MASK  (0x00FFFFFFU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD1_DATA_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD1_DATA_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD1_DATA_MAX  (0x00ffffffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_GENERIC_WORD1_RESETVAL  (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_START */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_START_PULSE_MASK      (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_START_PULSE_SHIFT     (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_START_PULSE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_START_PULSE_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_START_RESETVAL        (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_STREAM */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STREAM_ADDR_MASK      (0xFFFFFFFCU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STREAM_ADDR_SHIFT     (2U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STREAM_ADDR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STREAM_ADDR_MAX       (0x3fffffffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STREAM_RESETVAL       (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR_WINDING_ORDER_MASK  (0x00400000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR_WINDING_ORDER_SHIFT  (22U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR_WINDING_ORDER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR_WINDING_ORDER_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR_ADDR_MASK  (0x003FFFFFU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR_ADDR_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR_ADDR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR_ADDR_MAX   (0x003fffffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_INDEX_ADDR_RESETVAL   (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_WRAP_INDEX */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_INDEX_COUNT_MASK  (0x003FFFFFU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_INDEX_COUNT_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_INDEX_COUNT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_INDEX_COUNT_MAX  (0x003fffffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_INDEX_RESETVAL   (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_WRAPPED */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAPPED_COUNT_MASK    (0x003FFFFFU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAPPED_COUNT_SHIFT   (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAPPED_COUNT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAPPED_COUNT_MAX     (0x003fffffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAPPED_RESETVAL      (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_WINDING_MASK  (0x02000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_WINDING_SHIFT  (25U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_WINDING_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_WINDING_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_ENABLE_MASK  (0x01000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_ENABLE_SHIFT  (24U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_ENABLE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_ENABLE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_INDEX_MASK  (0x00FFFFFFU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_INDEX_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_INDEX_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_INDEX_MAX   (0x00ffffffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_FAN_INDEX_RESETVAL    (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_PLUSONE_MASK  (0x00800000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_PLUSONE_SHIFT  (23U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_PLUSONE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_PLUSONE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_ENABLE_MASK  (0x00400000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_ENABLE_SHIFT  (22U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_ENABLE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_ENABLE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_RESUME_MASK  (0x003FFFFFU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_RESUME_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_RESUME_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_RESUME_MAX  (0x003fffffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_WRAP_RESUME_RESETVAL  (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_STATUS */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_NA_MASK        (0x00000100U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_NA_SHIFT       (8U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_NA_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_NA_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_PROCESS_MASK   (0x00000010U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_PROCESS_SHIFT  (4U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_PROCESS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_PROCESS_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_COMPLETE_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_COMPLETE_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_COMPLETE_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATUS_RESETVAL       (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_STATE0 */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_TERMINATE_MASK  (0x20000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_TERMINATE_SHIFT  (29U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_TERMINATE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_TERMINATE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_COMPLEX_MASK  (0x10000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_COMPLEX_SHIFT  (28U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_COMPLEX_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_COMPLEX_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_BASEADDR_MASK  (0x0FFFFFFFU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_BASEADDR_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_BASEADDR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_TAPDSSTATE_BASEADDR_MAX  (0x0fffffffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE0_RESETVAL       (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_STATE1 */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_DATASIZE_MASK  (0xF8000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_DATASIZE_SHIFT  (27U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_DATASIZE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_DATASIZE_MAX  (0x0000001fU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SD_MASK  (0x02000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SD_SHIFT  (25U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SD_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_GENERIC_PRESENT_MASK  (0x00180000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_GENERIC_PRESENT_SHIFT  (19U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_GENERIC_PRESENT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_GENERIC_PRESENT_MAX  (0x00000003U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_FENCE_ENABLE_MASK  (0x00040000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_FENCE_ENABLE_SHIFT  (18U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_FENCE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_FENCE_ENABLE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_MTE_EMIT_MASK  (0x00020000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_MTE_EMIT_SHIFT  (17U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_MTE_EMIT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_MTE_EMIT_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEPIPE_MASK  (0x0000E000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEPIPE_SHIFT  (13U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEPIPE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEPIPE_MAX  (0x00000007U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTIAL_MASK  (0x00001000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTIAL_SHIFT  (12U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTIAL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTIAL_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTITIONS_MASK  (0x00000E00U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTITIONS_SHIFT  (9U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTITIONS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_PARTITIONS_MAX  (0x00000007U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SECONDARY_MASK  (0x00000100U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SECONDARY_SHIFT  (8U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SECONDARY_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_SECONDARY_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEATTRIBUTESIZE_MASK  (0x000000FFU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEATTRIBUTESIZE_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEATTRIBUTESIZE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_TAPDSSTATE_USEATTRIBUTESIZE_MAX  (0x000000ffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_STATE1_RESETVAL       (0x00000000U)

/* EUR_CR_VDM_WAIT_FOR_KICK */

#define CSL_KLIO_EUR_CR_VDM_WAIT_FOR_KICK_STATUS_MASK           (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_WAIT_FOR_KICK_STATUS_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_VDM_WAIT_FOR_KICK_STATUS_RESETVAL       (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_WAIT_FOR_KICK_STATUS_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_WAIT_FOR_KICK_RESETVAL              (0x00000001U)

/* EUR_CR_VDM_MTE */

#define CSL_KLIO_EUR_CR_VDM_MTE_SIG_MASK                        (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_VDM_MTE_SIG_SHIFT                       (0U)
#define CSL_KLIO_EUR_CR_VDM_MTE_SIG_RESETVAL                    (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_MTE_SIG_MAX                         (0xffffffffU)

#define CSL_KLIO_EUR_CR_VDM_MTE_RESETVAL                        (0x00000000U)

/* EUR_CR_VDM_FENCE */

#define CSL_KLIO_EUR_CR_VDM_FENCE_INCREMENT_MASK                (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_FENCE_INCREMENT_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_VDM_FENCE_INCREMENT_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_FENCE_INCREMENT_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_FENCE_RESETVAL                      (0x00000000U)

/* EUR_CR_VDM_FENCE_STATUS */

#define CSL_KLIO_EUR_CR_VDM_FENCE_STATUS_COUNT_MASK             (0x000000FFU)
#define CSL_KLIO_EUR_CR_VDM_FENCE_STATUS_COUNT_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_VDM_FENCE_STATUS_COUNT_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_FENCE_STATUS_COUNT_MAX              (0x000000ffU)

#define CSL_KLIO_EUR_CR_VDM_FENCE_STATUS_RESETVAL               (0x00000000U)

/* EUR_CR_MTE_CTRL */

#define CSL_KLIO_EUR_CR_MTE_CTRL_TE_PAD256_MASK                 (0x00000400U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_TE_PAD256_SHIFT                (10U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_TE_PAD256_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_TE_PAD256_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_CTRL_TE_PAD128_MASK                 (0x00000200U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_TE_PAD128_SHIFT                (9U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_TE_PAD128_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_TE_PAD128_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_CTRL_NUM_PARTITIONS_MASK            (0x00000100U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_NUM_PARTITIONS_SHIFT           (8U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_NUM_PARTITIONS_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_NUM_PARTITIONS_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_CTRL_OPENGL_MASK                    (0x00000080U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_OPENGL_SHIFT                   (7U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_OPENGL_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_OPENGL_MAX                     (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_CTRL_PSOCULL_DISABLE_MASK           (0x00000040U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_PSOCULL_DISABLE_SHIFT          (6U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_PSOCULL_DISABLE_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_PSOCULL_DISABLE_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_CTRL_WCLAMPEN_MASK                  (0x00000020U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_WCLAMPEN_SHIFT                 (5U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_WCLAMPEN_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_WCLAMPEN_MAX                   (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_CTRL_GLOBALMACROTILETHRESH_MASK     (0x0000001FU)
#define CSL_KLIO_EUR_CR_MTE_CTRL_GLOBALMACROTILETHRESH_SHIFT    (0U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_GLOBALMACROTILETHRESH_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_CTRL_GLOBALMACROTILETHRESH_MAX      (0x0000001fU)

#define CSL_KLIO_EUR_CR_MTE_CTRL_RESETVAL                       (0x00000100U)

/* EUR_CR_MTE_WCOMPARE */

#define CSL_KLIO_EUR_CR_MTE_WCOMPARE_VALUE_MASK                 (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_MTE_WCOMPARE_VALUE_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_MTE_WCOMPARE_VALUE_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_WCOMPARE_VALUE_MAX                  (0xffffffffU)

#define CSL_KLIO_EUR_CR_MTE_WCOMPARE_RESETVAL                   (0x00000000U)

/* EUR_CR_MTE_WCLAMP */

#define CSL_KLIO_EUR_CR_MTE_WCLAMP_VALUE_MASK                   (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_MTE_WCLAMP_VALUE_SHIFT                  (0U)
#define CSL_KLIO_EUR_CR_MTE_WCLAMP_VALUE_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_WCLAMP_VALUE_MAX                    (0xffffffffU)

#define CSL_KLIO_EUR_CR_MTE_WCLAMP_RESETVAL                     (0x00000000U)

/* EUR_CR_MTE_SCREEN */

#define CSL_KLIO_EUR_CR_MTE_SCREEN_PIXYMAX_MASK                 (0x00FFF000U)
#define CSL_KLIO_EUR_CR_MTE_SCREEN_PIXYMAX_SHIFT                (12U)
#define CSL_KLIO_EUR_CR_MTE_SCREEN_PIXYMAX_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_SCREEN_PIXYMAX_MAX                  (0x00000fffU)

#define CSL_KLIO_EUR_CR_MTE_SCREEN_PIXXMAX_MASK                 (0x00000FFFU)
#define CSL_KLIO_EUR_CR_MTE_SCREEN_PIXXMAX_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_MTE_SCREEN_PIXXMAX_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_SCREEN_PIXXMAX_MAX                  (0x00000fffU)

#define CSL_KLIO_EUR_CR_MTE_SCREEN_RESETVAL                     (0x00000000U)

/* EUR_CR_MTE_OTPM_OP */

#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_FLUSH_MASK              (0x00000004U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_FLUSH_SHIFT             (2U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_FLUSH_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_FLUSH_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_LOAD_MASK               (0x00000002U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_LOAD_SHIFT              (1U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_LOAD_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_LOAD_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_INV_MASK                (0x00000001U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_INV_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_INV_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_CSM_INV_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_OTPM_OP_RESETVAL                    (0x00000000U)

/* EUR_CR_MTE_MULTISAMPLECTL */

#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y3_MASK         (0xF0000000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y3_SHIFT        (28U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y3_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y3_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X3_MASK         (0x0F000000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X3_SHIFT        (24U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X3_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X3_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y2_MASK         (0x00F00000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y2_SHIFT        (20U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y2_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y2_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X2_MASK         (0x000F0000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X2_SHIFT        (16U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X2_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X2_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y1_MASK         (0x0000F000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y1_SHIFT        (12U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y1_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y1_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X1_MASK         (0x00000F00U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X1_SHIFT        (8U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X1_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X1_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y0_MASK         (0x000000F0U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y0_SHIFT        (4U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y0_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_Y0_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X0_MASK         (0x0000000FU)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X0_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X0_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_MSAA_X0_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_MTE_MULTISAMPLECTL_RESETVAL             (0x00000000U)

/* EUR_CR_TA_MEM_TE_PAD */

#define CSL_KLIO_EUR_CR_TA_MEM_TE_PAD_DWORD_MASK                (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_TA_MEM_TE_PAD_DWORD_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_TA_MEM_TE_PAD_DWORD_RESETVAL            (0xc0000000U)
#define CSL_KLIO_EUR_CR_TA_MEM_TE_PAD_DWORD_MAX                 (0xffffffffU)

#define CSL_KLIO_EUR_CR_TA_MEM_TE_PAD_RESETVAL                  (0xc0000000U)

/* EUR_CR_MTE_FIRST_PAGE */

#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_VALID_MASK               (0x80000000U)
#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_VALID_SHIFT              (31U)
#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_VALID_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_VALID_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_MACROTILE_MASK           (0x001F0000U)
#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_MACROTILE_SHIFT          (16U)
#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_MACROTILE_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_MACROTILE_MAX            (0x0000001fU)

#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_DATA_MASK                (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_DATA_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_DATA_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_DATA_MAX                 (0x0000ffffU)

#define CSL_KLIO_EUR_CR_MTE_FIRST_PAGE_RESETVAL                 (0x00000000U)

/* EUR_CR_MTE_SECOND_PAGE */

#define CSL_KLIO_EUR_CR_MTE_SECOND_PAGE_VALID_MASK              (0x80000000U)
#define CSL_KLIO_EUR_CR_MTE_SECOND_PAGE_VALID_SHIFT             (31U)
#define CSL_KLIO_EUR_CR_MTE_SECOND_PAGE_VALID_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_SECOND_PAGE_VALID_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_SECOND_PAGE_DATA_MASK               (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_MTE_SECOND_PAGE_DATA_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_MTE_SECOND_PAGE_DATA_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_SECOND_PAGE_DATA_MAX                (0x0000ffffU)

#define CSL_KLIO_EUR_CR_MTE_SECOND_PAGE_RESETVAL                (0x00000000U)

/* EUR_CR_MTE_ABORT */

#define CSL_KLIO_EUR_CR_MTE_ABORT_SETTLED_MASK                  (0x00000001U)
#define CSL_KLIO_EUR_CR_MTE_ABORT_SETTLED_SHIFT                 (0U)
#define CSL_KLIO_EUR_CR_MTE_ABORT_SETTLED_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_ABORT_SETTLED_MAX                   (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_ABORT_RESETVAL                      (0x00000000U)

/* EUR_CR_MTE_SIG1 */

#define CSL_KLIO_EUR_CR_MTE_SIG1_TE_SIGNATURE_MASK              (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_MTE_SIG1_TE_SIGNATURE_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_MTE_SIG1_TE_SIGNATURE_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_SIG1_TE_SIGNATURE_MAX               (0xffffffffU)

#define CSL_KLIO_EUR_CR_MTE_SIG1_RESETVAL                       (0x00000000U)

/* EUR_CR_MTE_SIG2 */

#define CSL_KLIO_EUR_CR_MTE_SIG2_MEM_SIGNATURE_MASK             (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_MTE_SIG2_MEM_SIGNATURE_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_MTE_SIG2_MEM_SIGNATURE_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_SIG2_MEM_SIGNATURE_MAX              (0xffffffffU)

#define CSL_KLIO_EUR_CR_MTE_SIG2_RESETVAL                       (0x00000000U)

/* EUR_CR_TE_STATE */

#define CSL_KLIO_EUR_CR_TE_STATE_ISP_STATE_ID_MASK              (0x001F0000U)
#define CSL_KLIO_EUR_CR_TE_STATE_ISP_STATE_ID_SHIFT             (16U)
#define CSL_KLIO_EUR_CR_TE_STATE_ISP_STATE_ID_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_STATE_ISP_STATE_ID_MAX               (0x0000001fU)

#define CSL_KLIO_EUR_CR_TE_STATE_ABORTED_MTILE_MASK             (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_TE_STATE_ABORTED_MTILE_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_TE_STATE_ABORTED_MTILE_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_STATE_ABORTED_MTILE_MAX              (0x0000ffffU)

#define CSL_KLIO_EUR_CR_TE_STATE_RESETVAL                       (0x00000000U)

/* EUR_CR_VDM_CONTEXT_STORE_SNAPSHOT */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_SNAPSHOT_BASE_ADDR_MASK  (0x0FFFFFFFU)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_SNAPSHOT_BASE_ADDR_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_SNAPSHOT_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_SNAPSHOT_BASE_ADDR_MAX  (0x0fffffffU)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_STORE_SNAPSHOT_RESETVAL     (0x00000000U)

/* EUR_CR_VDM_CONTEXT_LOAD_START */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_START_PULSE_MASK       (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_START_PULSE_SHIFT      (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_START_PULSE_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_START_PULSE_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_START_RESETVAL         (0x00000000U)

/* EUR_CR_VDM_CONTEXT_LOAD_STATUS */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_PROCESSING_MASK  (0x00000002U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_PROCESSING_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_PROCESSING_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_PROCESSING_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_COMPLETE_MASK   (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_COMPLETE_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_COMPLETE_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_RESETVAL        (0x00000000U)

/* EUR_CR_VDM_CONTEXT_LOAD_STATUS_CLEAR */

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_CLEAR_PULSE_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_CLEAR_PULSE_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_CLEAR_PULSE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_CLEAR_PULSE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_CONTEXT_LOAD_STATUS_CLEAR_RESETVAL  (0x00000000U)

/* EUR_CR_VDM_TASK_KICK */

#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_PULSE_MASK                (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_PULSE_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_PULSE_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_PULSE_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_RESETVAL                  (0x00000000U)

/* EUR_CR_VDM_TASK_KICK_STATUS */

#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_PROCESSING_MASK    (0x00000002U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_PROCESSING_SHIFT   (1U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_PROCESSING_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_PROCESSING_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_COMPLETE_MASK      (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_COMPLETE_SHIFT     (0U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_COMPLETE_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_RESETVAL           (0x00000000U)

/* EUR_CR_VDM_TASK_KICK_STATUS_CLEAR */

#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_CLEAR_PULSE_MASK   (0x00000001U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_CLEAR_PULSE_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_CLEAR_PULSE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_CLEAR_PULSE_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_VDM_TASK_KICK_STATUS_CLEAR_RESETVAL     (0x00000000U)

/* EUR_CR_TE_SAFE */

#define CSL_KLIO_EUR_CR_TE_SAFE_TO_DRAIN_MASK                   (0x00000001U)
#define CSL_KLIO_EUR_CR_TE_SAFE_TO_DRAIN_SHIFT                  (0U)
#define CSL_KLIO_EUR_CR_TE_SAFE_TO_DRAIN_RESETVAL               (0x00000001U)
#define CSL_KLIO_EUR_CR_TE_SAFE_TO_DRAIN_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_TE_SAFE_RESETVAL                        (0x00000001U)

/* EUR_CR_CLIP_SIG1 */

#define CSL_KLIO_EUR_CR_CLIP_SIG1_CLIP_SIGNATURE_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_CLIP_SIG1_CLIP_SIGNATURE_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_CLIP_SIG1_CLIP_SIGNATURE_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_CLIP_SIG1_CLIP_SIGNATURE_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_CLIP_SIG1_RESETVAL                      (0x00000000U)

/* EUR_CR_PBE_NONPIXEL_CHECKSUM */

#define CSL_KLIO_EUR_CR_PBE_NONPIXEL_CHECKSUM_VALUE_MASK        (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_PBE_NONPIXEL_CHECKSUM_VALUE_SHIFT       (0U)
#define CSL_KLIO_EUR_CR_PBE_NONPIXEL_CHECKSUM_VALUE_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_PBE_NONPIXEL_CHECKSUM_VALUE_MAX         (0xffffffffU)

#define CSL_KLIO_EUR_CR_PBE_NONPIXEL_CHECKSUM_RESETVAL          (0x00000000U)

/* EUR_CR_TA_CLK_GATE */

#define CSL_KLIO_EUR_CR_TA_CLK_GATE_START_TO_END_MASK           (0x00000001U)
#define CSL_KLIO_EUR_CR_TA_CLK_GATE_START_TO_END_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_TA_CLK_GATE_START_TO_END_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_TA_CLK_GATE_START_TO_END_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_TA_CLK_GATE_RESETVAL                    (0x00000000U)

/* EUR_CR_MTE_STATE */

#define CSL_KLIO_EUR_CR_MTE_STATE_FLUSH_MASK                    (0x00000001U)
#define CSL_KLIO_EUR_CR_MTE_STATE_FLUSH_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_MTE_STATE_FLUSH_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_STATE_FLUSH_MAX                     (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_STATE_RESETVAL                      (0x00000000U)

/* EUR_CR_MTE_STATE_FLUSH_BASE */

#define CSL_KLIO_EUR_CR_MTE_STATE_FLUSH_BASE_ADDR_MASK          (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_MTE_STATE_FLUSH_BASE_ADDR_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_MTE_STATE_FLUSH_BASE_ADDR_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_STATE_FLUSH_BASE_ADDR_MAX           (0x0fffffffU)

#define CSL_KLIO_EUR_CR_MTE_STATE_FLUSH_BASE_RESETVAL           (0x00000000U)

/* EUR_CR_MTE_FIXED_POINT */

#define CSL_KLIO_EUR_CR_MTE_FIXED_POINT_FORMAT_MASK             (0x00000001U)
#define CSL_KLIO_EUR_CR_MTE_FIXED_POINT_FORMAT_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_MTE_FIXED_POINT_FORMAT_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_FIXED_POINT_FORMAT_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_FIXED_POINT_RESETVAL                (0x00000000U)

/* EUR_CR_TA_CONTEXT */

#define CSL_KLIO_EUR_CR_TA_CONTEXT_RESUME_PULSE_MASK            (0x00000002U)
#define CSL_KLIO_EUR_CR_TA_CONTEXT_RESUME_PULSE_SHIFT           (1U)
#define CSL_KLIO_EUR_CR_TA_CONTEXT_RESUME_PULSE_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_TA_CONTEXT_RESUME_PULSE_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_TA_CONTEXT_DRAIN_PULSE_MASK             (0x00000001U)
#define CSL_KLIO_EUR_CR_TA_CONTEXT_DRAIN_PULSE_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_TA_CONTEXT_DRAIN_PULSE_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_TA_CONTEXT_DRAIN_PULSE_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_TA_CONTEXT_RESETVAL                     (0x00000000U)

/* EUR_CR_TA_CONTEXT_DRAIN_MTE */

#define CSL_KLIO_EUR_CR_TA_CONTEXT_DRAIN_MTE_BASE_ADDR_MASK     (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_TA_CONTEXT_DRAIN_MTE_BASE_ADDR_SHIFT    (4U)
#define CSL_KLIO_EUR_CR_TA_CONTEXT_DRAIN_MTE_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_TA_CONTEXT_DRAIN_MTE_BASE_ADDR_MAX      (0x0fffffffU)

#define CSL_KLIO_EUR_CR_TA_CONTEXT_DRAIN_MTE_RESETVAL           (0x00000000U)

/* EUR_CR_TE_PRIMITIVE_BLOCK */

#define CSL_KLIO_EUR_CR_TE_PRIMITIVE_BLOCK_PROGRESS_MASK        (0x0003FFFFU)
#define CSL_KLIO_EUR_CR_TE_PRIMITIVE_BLOCK_PROGRESS_SHIFT       (0U)
#define CSL_KLIO_EUR_CR_TE_PRIMITIVE_BLOCK_PROGRESS_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_PRIMITIVE_BLOCK_PROGRESS_MAX         (0x0003ffffU)

#define CSL_KLIO_EUR_CR_TE_PRIMITIVE_BLOCK_RESETVAL             (0x00000000U)

/* EUR_CR_PIXELBE */

#define CSL_KLIO_EUR_CR_PIXELBE_AA_EDGEOPT_OFF_MASK             (0x00000400U)
#define CSL_KLIO_EUR_CR_PIXELBE_AA_EDGEOPT_OFF_SHIFT            (10U)
#define CSL_KLIO_EUR_CR_PIXELBE_AA_EDGEOPT_OFF_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PIXELBE_AA_EDGEOPT_OFF_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PIXELBE_CHKSUM_INIT_MASK                (0x00000200U)
#define CSL_KLIO_EUR_CR_PIXELBE_CHKSUM_INIT_SHIFT               (9U)
#define CSL_KLIO_EUR_CR_PIXELBE_CHKSUM_INIT_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_PIXELBE_CHKSUM_INIT_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_PIXELBE_IDF_USE_FBADDR_MASK             (0x00000100U)
#define CSL_KLIO_EUR_CR_PIXELBE_IDF_USE_FBADDR_SHIFT            (8U)
#define CSL_KLIO_EUR_CR_PIXELBE_IDF_USE_FBADDR_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PIXELBE_IDF_USE_FBADDR_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_PIXELBE_ALPHATHRESHOLD_MASK             (0x000000FFU)
#define CSL_KLIO_EUR_CR_PIXELBE_ALPHATHRESHOLD_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_PIXELBE_ALPHATHRESHOLD_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_PIXELBE_ALPHATHRESHOLD_MAX              (0x000000ffU)

#define CSL_KLIO_EUR_CR_PIXELBE_RESETVAL                        (0x00000000U)

/* EUR_CR_ISP_RENDER */

#define CSL_KLIO_EUR_CR_ISP_RENDER_FAST_SCANDIR_MASK            (0x00000030U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_FAST_SCANDIR_SHIFT           (4U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_FAST_SCANDIR_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_FAST_SCANDIR_TL2BR           (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_FAST_SCANDIR_TR2BL           (0x00000001U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_FAST_SCANDIR_BL2TR           (0x00000002U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_FAST_SCANDIR_BR2TL           (0x00000003U)

#define CSL_KLIO_EUR_CR_ISP_RENDER_CONTEXT_RESUMED_MASK         (0x00000008U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_CONTEXT_RESUMED_SHIFT        (3U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_CONTEXT_RESUMED_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_CONTEXT_RESUMED_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_RENDER_TYPE_MASK                    (0x00000003U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_TYPE_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_TYPE_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_RENDER_TYPE_MAX                     (0x00000003U)

#define CSL_KLIO_EUR_CR_ISP_RENDER_RESETVAL                     (0x00000000U)

/* EUR_CR_ISP_RGN_BASE */

#define CSL_KLIO_EUR_CR_ISP_RGN_BASE_ADDR_MASK                  (0xFFFFFFFCU)
#define CSL_KLIO_EUR_CR_ISP_RGN_BASE_ADDR_SHIFT                 (2U)
#define CSL_KLIO_EUR_CR_ISP_RGN_BASE_ADDR_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_RGN_BASE_ADDR_MAX                   (0x3fffffffU)

#define CSL_KLIO_EUR_CR_ISP_RGN_BASE_RESETVAL                   (0x00000000U)

/* EUR_CR_ISP_RENDBOX1 */

#define CSL_KLIO_EUR_CR_ISP_RENDBOX1_X_MASK                     (0x00FF0000U)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX1_X_SHIFT                    (16U)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX1_X_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX1_X_MAX                      (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_RENDBOX1_Y_MASK                     (0x000000FFU)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX1_Y_SHIFT                    (0U)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX1_Y_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX1_Y_MAX                      (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_RENDBOX1_RESETVAL                   (0x00000000U)

/* EUR_CR_ISP_RENDBOX2 */

#define CSL_KLIO_EUR_CR_ISP_RENDBOX2_X_MASK                     (0x00FF0000U)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX2_X_SHIFT                    (16U)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX2_X_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX2_X_MAX                      (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_RENDBOX2_Y_MASK                     (0x000000FFU)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX2_Y_SHIFT                    (0U)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX2_Y_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_RENDBOX2_Y_MAX                      (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_RENDBOX2_RESETVAL                   (0x00000000U)

/* EUR_CR_ISP_IPFMISC */

#define CSL_KLIO_EUR_CR_ISP_IPFMISC_CONTEXT_STORE_TILE_ONLY_MASK  (0x01000000U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_CONTEXT_STORE_TILE_ONLY_SHIFT  (24U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_CONTEXT_STORE_TILE_ONLY_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_CONTEXT_STORE_TILE_ONLY_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_IPFMISC_UPASSSTART_MASK             (0x000F0000U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_UPASSSTART_SHIFT            (16U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_UPASSSTART_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_UPASSSTART_MAX              (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_IPFMISC_PROCESSEMPTY_MASK           (0x00000100U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_PROCESSEMPTY_SHIFT          (8U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_PROCESSEMPTY_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_PROCESSEMPTY_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_IPFMISC_VALIDID_MASK                (0x0000003FU)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_VALIDID_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_VALIDID_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_IPFMISC_VALIDID_MAX                 (0x0000003fU)

#define CSL_KLIO_EUR_CR_ISP_IPFMISC_RESETVAL                    (0x00000000U)

/* EUR_CR_ISP_OGL_MODE */

#define CSL_KLIO_EUR_CR_ISP_OGL_MODE_ENABLE_MASK                (0x00000001U)
#define CSL_KLIO_EUR_CR_ISP_OGL_MODE_ENABLE_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_ISP_OGL_MODE_ENABLE_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_OGL_MODE_ENABLE_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_OGL_MODE_RESETVAL                   (0x00000000U)

/* EUR_CR_ISP_PERPENDICULAR */

#define CSL_KLIO_EUR_CR_ISP_PERPENDICULAR_THRESHOLD_MASK        (0x7FFFFFF0U)
#define CSL_KLIO_EUR_CR_ISP_PERPENDICULAR_THRESHOLD_SHIFT       (4U)
#define CSL_KLIO_EUR_CR_ISP_PERPENDICULAR_THRESHOLD_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_PERPENDICULAR_THRESHOLD_MAX         (0x07ffffffU)

#define CSL_KLIO_EUR_CR_ISP_PERPENDICULAR_RESETVAL              (0x00000000U)

/* EUR_CR_ISP_CULLVALUE */

#define CSL_KLIO_EUR_CR_ISP_CULLVALUE_THRESHOLD_MASK            (0x7FFFFFF0U)
#define CSL_KLIO_EUR_CR_ISP_CULLVALUE_THRESHOLD_SHIFT           (4U)
#define CSL_KLIO_EUR_CR_ISP_CULLVALUE_THRESHOLD_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CULLVALUE_THRESHOLD_MAX             (0x07ffffffU)

#define CSL_KLIO_EUR_CR_ISP_CULLVALUE_RESETVAL                  (0x00000000U)

/* EUR_CR_ISP_DBIAS */

#define CSL_KLIO_EUR_CR_ISP_DBIAS_FACTORADJ_MASK                (0x0000FF00U)
#define CSL_KLIO_EUR_CR_ISP_DBIAS_FACTORADJ_SHIFT               (8U)
#define CSL_KLIO_EUR_CR_ISP_DBIAS_FACTORADJ_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_DBIAS_FACTORADJ_MAX                 (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_DBIAS_UNITSADJ_MASK                 (0x000000FFU)
#define CSL_KLIO_EUR_CR_ISP_DBIAS_UNITSADJ_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_ISP_DBIAS_UNITSADJ_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_DBIAS_UNITSADJ_MAX                  (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_DBIAS_RESETVAL                      (0x00000000U)

/* EUR_CR_ISP_START_RENDER */

#define CSL_KLIO_EUR_CR_ISP_START_RENDER_PULSE_MASK             (0x00000001U)
#define CSL_KLIO_EUR_CR_ISP_START_RENDER_PULSE_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_ISP_START_RENDER_PULSE_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_START_RENDER_PULSE_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_START_RENDER_RESETVAL               (0x00000000U)

/* EUR_CR_THREED_AA_MODE */

#define CSL_KLIO_EUR_CR_THREED_AA_MODE_VALUE_MASK               (0x00000003U)
#define CSL_KLIO_EUR_CR_THREED_AA_MODE_VALUE_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_THREED_AA_MODE_VALUE_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_THREED_AA_MODE_VALUE_DISABLED           (0x00000000U)
#define CSL_KLIO_EUR_CR_THREED_AA_MODE_VALUE__2X                (0x00000001U)
#define CSL_KLIO_EUR_CR_THREED_AA_MODE_VALUE__4X                (0x00000002U)
#define CSL_KLIO_EUR_CR_THREED_AA_MODE_VALUE_RESERVED_3         (0x00000003U)

#define CSL_KLIO_EUR_CR_THREED_AA_MODE_RESETVAL                 (0x00000000U)

/* EUR_CR_ISP_BREAK */

#define CSL_KLIO_EUR_CR_ISP_BREAK_RESUME_MASK                   (0x00000010U)
#define CSL_KLIO_EUR_CR_ISP_BREAK_RESUME_SHIFT                  (4U)
#define CSL_KLIO_EUR_CR_ISP_BREAK_RESUME_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_BREAK_RESUME_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_BREAK_HALT_MASK                     (0x00000001U)
#define CSL_KLIO_EUR_CR_ISP_BREAK_HALT_SHIFT                    (0U)
#define CSL_KLIO_EUR_CR_ISP_BREAK_HALT_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_BREAK_HALT_MAX                      (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_BREAK_RESETVAL                      (0x00000000U)

/* EUR_CR_ISP_3DCONTEXT */

#define CSL_KLIO_EUR_CR_ISP_3DCONTEXT_STORE_MASK                (0x00000001U)
#define CSL_KLIO_EUR_CR_ISP_3DCONTEXT_STORE_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_ISP_3DCONTEXT_STORE_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_3DCONTEXT_STORE_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_3DCONTEXT_RESETVAL                  (0x00000000U)

/* EUR_CR_ISP_FPU */

#define CSL_KLIO_EUR_CR_ISP_FPU_SIGNATURE_MASK                  (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_ISP_FPU_SIGNATURE_SHIFT                 (0U)
#define CSL_KLIO_EUR_CR_ISP_FPU_SIGNATURE_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_FPU_SIGNATURE_MAX                   (0xffffffffU)

#define CSL_KLIO_EUR_CR_ISP_FPU_RESETVAL                        (0x00000000U)

/* EUR_CR_TSP_PARAMETER_CACHE */

#define CSL_KLIO_EUR_CR_TSP_PARAMETER_CACHE_INVALIDATE_MASK     (0x00000001U)
#define CSL_KLIO_EUR_CR_TSP_PARAMETER_CACHE_INVALIDATE_SHIFT    (0U)
#define CSL_KLIO_EUR_CR_TSP_PARAMETER_CACHE_INVALIDATE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_TSP_PARAMETER_CACHE_INVALIDATE_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_TSP_PARAMETER_CACHE_RESETVAL            (0x00000000U)

/* EUR_CR_TSP_PARAMETER_FETCH */

#define CSL_KLIO_EUR_CR_TSP_PARAMETER_FETCH_REPLACE_MODE_MASK   (0x00000001U)
#define CSL_KLIO_EUR_CR_TSP_PARAMETER_FETCH_REPLACE_MODE_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_TSP_PARAMETER_FETCH_REPLACE_MODE_RESETVAL  (0x00000001U)
#define CSL_KLIO_EUR_CR_TSP_PARAMETER_FETCH_REPLACE_MODE_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_TSP_PARAMETER_FETCH_RESETVAL            (0x00000001U)

/* EUR_CR_IFPU_ROUNDMODE */

#define CSL_KLIO_EUR_CR_IFPU_ROUNDMODE_DEPTH_MASK               (0x00000003U)
#define CSL_KLIO_EUR_CR_IFPU_ROUNDMODE_DEPTH_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_IFPU_ROUNDMODE_DEPTH_RESETVAL           (0x00000001U)
#define CSL_KLIO_EUR_CR_IFPU_ROUNDMODE_DEPTH_MAX                (0x00000003U)

#define CSL_KLIO_EUR_CR_IFPU_ROUNDMODE_RESETVAL                 (0x00000001U)

/* EUR_CR_ISP_START */

#define CSL_KLIO_EUR_CR_ISP_START_CTRL_STREAM_POS_MASK          (0x7FFFFFE0U)
#define CSL_KLIO_EUR_CR_ISP_START_CTRL_STREAM_POS_SHIFT         (5U)
#define CSL_KLIO_EUR_CR_ISP_START_CTRL_STREAM_POS_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_START_CTRL_STREAM_POS_MAX           (0x03ffffffU)

#define CSL_KLIO_EUR_CR_ISP_START_PRIM_NUM_MASK                 (0x0000001FU)
#define CSL_KLIO_EUR_CR_ISP_START_PRIM_NUM_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_ISP_START_PRIM_NUM_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_START_PRIM_NUM_MAX                  (0x0000001fU)

#define CSL_KLIO_EUR_CR_ISP_START_RESETVAL                      (0x00000000U)

/* EUR_CR_FOURKX4K_RENDER */

#define CSL_KLIO_EUR_CR_FOURKX4K_RENDER_MODE_MASK               (0x00000001U)
#define CSL_KLIO_EUR_CR_FOURKX4K_RENDER_MODE_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_FOURKX4K_RENDER_MODE_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_FOURKX4K_RENDER_MODE_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_FOURKX4K_RENDER_RESETVAL                (0x00000000U)

/* EUR_CR_ISP_BREAK_INDEX */

#define CSL_KLIO_EUR_CR_ISP_BREAK_INDEX_ADDRESS_MASK            (0x03FFFFFFU)
#define CSL_KLIO_EUR_CR_ISP_BREAK_INDEX_ADDRESS_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_ISP_BREAK_INDEX_ADDRESS_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_BREAK_INDEX_ADDRESS_MAX             (0x03ffffffU)

#define CSL_KLIO_EUR_CR_ISP_BREAK_INDEX_RESETVAL                (0x00000000U)

/* EUR_CR_ISP_ZLSCTL */

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZSTOREFORMAT_MASK            (0x07000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZSTOREFORMAT_SHIFT           (24U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZSTOREFORMAT_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZSTOREFORMAT_MAX             (0x00000007U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLOADFORMAT_MASK             (0x00E00000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLOADFORMAT_SHIFT            (21U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLOADFORMAT_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLOADFORMAT_MAX              (0x00000007U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_EXTERNALZBUFFER_MASK         (0x00100000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_EXTERNALZBUFFER_SHIFT        (20U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_EXTERNALZBUFFER_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_EXTERNALZBUFFER_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_MSTOREEN_MASK                (0x00080000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_MSTOREEN_SHIFT               (19U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_MSTOREEN_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_MSTOREEN_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZSTOREEN_MASK                (0x00040000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZSTOREEN_SHIFT               (18U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZSTOREEN_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZSTOREEN_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_SSTOREEN_MASK                (0x00020000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_SSTOREEN_SHIFT               (17U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_SSTOREEN_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_SSTOREEN_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_STORETILED_MASK              (0x00010000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_STORETILED_SHIFT             (16U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_STORETILED_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_STORETILED_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_MLOADEN_MASK                 (0x00008000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_MLOADEN_SHIFT                (15U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_MLOADEN_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_MLOADEN_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLOADEN_MASK                 (0x00004000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLOADEN_SHIFT                (14U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLOADEN_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLOADEN_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_SLOADEN_MASK                 (0x00002000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_SLOADEN_SHIFT                (13U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_SLOADEN_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_SLOADEN_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_LOADTILED_MASK               (0x00001000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_LOADTILED_SHIFT              (12U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_LOADTILED_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_LOADTILED_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLSEXTENT_MASK               (0x000007F8U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLSEXTENT_SHIFT              (3U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLSEXTENT_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZLSEXTENT_MAX                (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_FORCEZSTORE_MASK             (0x00000004U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_FORCEZSTORE_SHIFT            (2U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_FORCEZSTORE_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_FORCEZSTORE_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_FORCEZLOAD_MASK              (0x00000002U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_FORCEZLOAD_SHIFT             (1U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_FORCEZLOAD_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_FORCEZLOAD_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZONLYRENDER_MASK             (0x00000001U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZONLYRENDER_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZONLYRENDER_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_ZONLYRENDER_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLSCTL_RESETVAL                     (0x00000000U)

/* EUR_CR_ISP_ZLOAD_BASE */

#define CSL_KLIO_EUR_CR_ISP_ZLOAD_BASE_ADDR_MASK                (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_ISP_ZLOAD_BASE_ADDR_SHIFT               (4U)
#define CSL_KLIO_EUR_CR_ISP_ZLOAD_BASE_ADDR_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLOAD_BASE_ADDR_MAX                 (0x0fffffffU)

#define CSL_KLIO_EUR_CR_ISP_ZLOAD_BASE_RESETVAL                 (0x00000000U)

/* EUR_CR_ISP_ZSTORE_BASE */

#define CSL_KLIO_EUR_CR_ISP_ZSTORE_BASE_ADDR_MASK               (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_ISP_ZSTORE_BASE_ADDR_SHIFT              (4U)
#define CSL_KLIO_EUR_CR_ISP_ZSTORE_BASE_ADDR_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZSTORE_BASE_ADDR_MAX                (0x0fffffffU)

#define CSL_KLIO_EUR_CR_ISP_ZSTORE_BASE_RESETVAL                (0x00000000U)

/* EUR_CR_ISP_STENCIL_LOAD_BASE */

#define CSL_KLIO_EUR_CR_ISP_STENCIL_LOAD_BASE_ADDR_MASK         (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_LOAD_BASE_ADDR_SHIFT        (4U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_LOAD_BASE_ADDR_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_LOAD_BASE_ADDR_MAX          (0x0fffffffU)

#define CSL_KLIO_EUR_CR_ISP_STENCIL_LOAD_BASE_ENABLE_MASK       (0x00000001U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_LOAD_BASE_ENABLE_SHIFT      (0U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_LOAD_BASE_ENABLE_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_LOAD_BASE_ENABLE_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_STENCIL_LOAD_BASE_RESETVAL          (0x00000000U)

/* EUR_CR_ISP_STENCIL_STORE_BASE */

#define CSL_KLIO_EUR_CR_ISP_STENCIL_STORE_BASE_ADDR_MASK        (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_STORE_BASE_ADDR_SHIFT       (4U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_STORE_BASE_ADDR_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_STORE_BASE_ADDR_MAX         (0x0fffffffU)

#define CSL_KLIO_EUR_CR_ISP_STENCIL_STORE_BASE_ENABLE_MASK      (0x00000001U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_STORE_BASE_ENABLE_SHIFT     (0U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_STORE_BASE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_STENCIL_STORE_BASE_ENABLE_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_STENCIL_STORE_BASE_RESETVAL         (0x00000000U)

/* EUR_CR_ISP_VISREGBASE */

#define CSL_KLIO_EUR_CR_ISP_VISREGBASE_ADDR_MASK                (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_ISP_VISREGBASE_ADDR_SHIFT               (4U)
#define CSL_KLIO_EUR_CR_ISP_VISREGBASE_ADDR_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_VISREGBASE_ADDR_MAX                 (0x0fffffffU)

#define CSL_KLIO_EUR_CR_ISP_VISREGBASE_RESETVAL                 (0x00000000U)

/* EUR_CR_ISP_BGOBJDEPTH */

#define CSL_KLIO_EUR_CR_ISP_BGOBJDEPTH_VALUE_MASK               (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_ISP_BGOBJDEPTH_VALUE_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJDEPTH_VALUE_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJDEPTH_VALUE_MAX                (0xffffffffU)

#define CSL_KLIO_EUR_CR_ISP_BGOBJDEPTH_RESETVAL                 (0x00000000U)

/* EUR_CR_ISP_BGOBJ */

#define CSL_KLIO_EUR_CR_ISP_BGOBJ_ENABLEBGTAG_MASK              (0x00000200U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJ_ENABLEBGTAG_SHIFT             (9U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJ_ENABLEBGTAG_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJ_ENABLEBGTAG_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_BGOBJ_MASK_MASK                     (0x00000100U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJ_MASK_SHIFT                    (8U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJ_MASK_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJ_MASK_MAX                      (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_BGOBJ_STENCIL_MASK                  (0x000000FFU)
#define CSL_KLIO_EUR_CR_ISP_BGOBJ_STENCIL_SHIFT                 (0U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJ_STENCIL_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJ_STENCIL_MAX                   (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_BGOBJ_RESETVAL                      (0x00000000U)

/* EUR_CR_ISP_BGOBJTAG */

#define CSL_KLIO_EUR_CR_ISP_BGOBJTAG_TSPDATASIZE_MASK           (0x3F000000U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJTAG_TSPDATASIZE_SHIFT          (24U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJTAG_TSPDATASIZE_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJTAG_TSPDATASIZE_MAX            (0x0000003fU)

#define CSL_KLIO_EUR_CR_ISP_BGOBJTAG_VERTEXPTR_MASK             (0x00FFFFFFU)
#define CSL_KLIO_EUR_CR_ISP_BGOBJTAG_VERTEXPTR_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJTAG_VERTEXPTR_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_BGOBJTAG_VERTEXPTR_MAX              (0x00ffffffU)

#define CSL_KLIO_EUR_CR_ISP_BGOBJTAG_RESETVAL                   (0x00000000U)

/* EUR_CR_ISP_MULTISAMPLECTL */

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y3_MASK         (0xF0000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y3_SHIFT        (28U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y3_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y3_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X3_MASK         (0x0F000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X3_SHIFT        (24U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X3_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X3_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y2_MASK         (0x00F00000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y2_SHIFT        (20U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y2_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y2_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X2_MASK         (0x000F0000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X2_SHIFT        (16U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X2_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X2_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y1_MASK         (0x0000F000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y1_SHIFT        (12U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y1_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y1_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X1_MASK         (0x00000F00U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X1_SHIFT        (8U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X1_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X1_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y0_MASK         (0x000000F0U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y0_SHIFT        (4U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y0_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_Y0_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X0_MASK         (0x0000000FU)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X0_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X0_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_MSAA_X0_MAX          (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL_RESETVAL             (0x00000000U)

/* EUR_CR_ISP_MULTISAMPLECTL2 */

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_XY4_EN_MASK    (0x00000100U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_XY4_EN_SHIFT   (8U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_XY4_EN_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_XY4_EN_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_Y4_MASK        (0x000000F0U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_Y4_SHIFT       (4U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_Y4_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_Y4_MAX         (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_X4_MASK        (0x0000000FU)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_X4_SHIFT       (0U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_X4_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_MSAA_X4_MAX         (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_MULTISAMPLECTL2_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_TAGCTRL */

#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_REUSE_TAGS_MASK             (0x00000004U)
#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_REUSE_TAGS_SHIFT            (2U)
#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_REUSE_TAGS_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_REUSE_TAGS_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_FORCE_PT_OFF_MASK           (0x00000002U)
#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_FORCE_PT_OFF_SHIFT          (1U)
#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_FORCE_PT_OFF_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_FORCE_PT_OFF_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_SAFE_MASK                   (0x00000001U)
#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_SAFE_SHIFT                  (0U)
#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_SAFE_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_SAFE_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_TAGCTRL_RESETVAL                    (0x00000200U)

/* EUR_CR_ISP_STATUS2 */

#define CSL_KLIO_EUR_CR_ISP_STATUS2_PRIM_NUM_MASK               (0x001F0000U)
#define CSL_KLIO_EUR_CR_ISP_STATUS2_PRIM_NUM_SHIFT              (16U)
#define CSL_KLIO_EUR_CR_ISP_STATUS2_PRIM_NUM_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_STATUS2_PRIM_NUM_MAX                (0x0000001fU)

#define CSL_KLIO_EUR_CR_ISP_STATUS2_TILE_Y_MASK                 (0x0000FF00U)
#define CSL_KLIO_EUR_CR_ISP_STATUS2_TILE_Y_SHIFT                (8U)
#define CSL_KLIO_EUR_CR_ISP_STATUS2_TILE_Y_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_STATUS2_TILE_Y_MAX                  (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_STATUS2_TILE_X_MASK                 (0x000000FFU)
#define CSL_KLIO_EUR_CR_ISP_STATUS2_TILE_X_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_ISP_STATUS2_TILE_X_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_STATUS2_TILE_X_MAX                  (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_STATUS2_RESETVAL                    (0x00000000U)

/* EUR_CR_PIXELBE_EMIT */

#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS3_MASK               (0x00000008U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS3_SHIFT              (3U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS3_RESETVAL           (0x00000001U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS3_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS2_MASK               (0x00000004U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS2_SHIFT              (2U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS2_RESETVAL           (0x00000001U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS2_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS1_MASK               (0x00000002U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS1_SHIFT              (1U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS1_RESETVAL           (0x00000001U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS1_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS0_MASK               (0x00000001U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS0_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS0_RESETVAL           (0x00000001U)
#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_STATUS0_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_PIXELBE_EMIT_RESETVAL                   (0x0000000fU)

/* EUR_CR_ISP_CONTEXT_RESUME */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME_ZLOAD_BASE_MASK      (0xFFFFFFE0U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME_ZLOAD_BASE_SHIFT     (5U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME_ZLOAD_BASE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME_ZLOAD_BASE_MAX       (0x07ffffffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME_RESETVAL             (0x00000000U)

/* EUR_CR_ISP_CONTEXT_RESUME2 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_TILE_X_MASK         (0xFF000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_TILE_X_SHIFT        (24U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_TILE_X_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_TILE_X_MAX          (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_TILE_Y_MASK         (0x00FF0000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_TILE_Y_SHIFT        (16U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_TILE_Y_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_TILE_Y_MAX          (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_END_OF_TILE_MASK    (0x00000800U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_END_OF_TILE_SHIFT   (11U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_END_OF_TILE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_END_OF_TILE_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_END_OF_RENDER_MASK  (0x00000400U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_END_OF_RENDER_SHIFT  (10U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_END_OF_RENDER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_END_OF_RENDER_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_PT_IN_FLIGHT_MASK   (0x00000200U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_PT_IN_FLIGHT_SHIFT  (9U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_PT_IN_FLIGHT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_PT_IN_FLIGHT_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_ZLS_BURST_MASK      (0x000001FFU)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_ZLS_BURST_SHIFT     (0U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_ZLS_BURST_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_ZLS_BURST_MAX       (0x000001ffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME2_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_CONTEXT_RESUME3 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_ZSTORE_CMD_MASK  (0x80000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_ZSTORE_CMD_SHIFT  (31U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_ZSTORE_CMD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_ZSTORE_CMD_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_MACROTILE_ID_MASK  (0x78000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_MACROTILE_ID_SHIFT  (27U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_MACROTILE_ID_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_MACROTILE_ID_MAX  (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_FIRST_TILE_IN_MT_MASK  (0x04000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_FIRST_TILE_IN_MT_SHIFT  (26U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_FIRST_TILE_IN_MT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_FIRST_TILE_IN_MT_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_CMP_BASE_MASK   (0x03FFFFFCU)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_CMP_BASE_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_CMP_BASE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_ZLS_CMP_BASE_MAX    (0x00ffffffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_RESUME3_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_ZLS_EXTZ_RGN_BASE */

#define CSL_KLIO_EUR_CR_ISP_ZLS_EXTZ_RGN_BASE_ADDR_MASK         (0xFFFFFFFCU)
#define CSL_KLIO_EUR_CR_ISP_ZLS_EXTZ_RGN_BASE_ADDR_SHIFT        (2U)
#define CSL_KLIO_EUR_CR_ISP_ZLS_EXTZ_RGN_BASE_ADDR_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLS_EXTZ_RGN_BASE_ADDR_MAX          (0x3fffffffU)

#define CSL_KLIO_EUR_CR_ISP_ZLS_EXTZ_RGN_BASE_RESETVAL          (0x00000000U)

/* EUR_CR_ISP_MTILE1 */

#define CSL_KLIO_EUR_CR_ISP_MTILE1_NUMBER_MASK                  (0x80000000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_NUMBER_SHIFT                 (31U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_NUMBER_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_NUMBER_MAX                   (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_MTILE1_X1_MASK                      (0x3FC00000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_X1_SHIFT                     (22U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_X1_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_X1_MAX                       (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_MTILE1_X2_MASK                      (0x000FF000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_X2_SHIFT                     (12U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_X2_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_X2_MAX                       (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_MTILE1_X3_MASK                      (0x000000FFU)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_X3_SHIFT                     (0U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_X3_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE1_X3_MAX                       (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_MTILE1_RESETVAL                     (0x00000000U)

/* EUR_CR_ISP_MTILE2 */

#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y1_MASK                      (0x3FC00000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y1_SHIFT                     (22U)
#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y1_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y1_MAX                       (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y2_MASK                      (0x000FF000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y2_SHIFT                     (12U)
#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y2_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y2_MAX                       (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y3_MASK                      (0x000000FFU)
#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y3_SHIFT                     (0U)
#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y3_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE2_Y3_MAX                       (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_MTILE2_RESETVAL                     (0x00000000U)

/* EUR_CR_ISP_MTILE */

#define CSL_KLIO_EUR_CR_ISP_MTILE_STRIDE_MASK                   (0x0003FFFFU)
#define CSL_KLIO_EUR_CR_ISP_MTILE_STRIDE_SHIFT                  (0U)
#define CSL_KLIO_EUR_CR_ISP_MTILE_STRIDE_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_MTILE_STRIDE_MAX                    (0x0003ffffU)

#define CSL_KLIO_EUR_CR_ISP_MTILE_RESETVAL                      (0x00000000U)

/* EUR_CR_ISP_ZLS_FALLBACK */

#define CSL_KLIO_EUR_CR_ISP_ZLS_FALLBACK_ENABLE_MASK            (0x80000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLS_FALLBACK_ENABLE_SHIFT           (31U)
#define CSL_KLIO_EUR_CR_ISP_ZLS_FALLBACK_ENABLE_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLS_FALLBACK_ENABLE_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_ZLS_FALLBACK_THRESHOLD_MASK         (0x000001FFU)
#define CSL_KLIO_EUR_CR_ISP_ZLS_FALLBACK_THRESHOLD_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_ISP_ZLS_FALLBACK_THRESHOLD_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_ZLS_FALLBACK_THRESHOLD_MAX          (0x000001ffU)

#define CSL_KLIO_EUR_CR_ISP_ZLS_FALLBACK_RESETVAL               (0x00000000U)

/* EUR_CR_ISP_CONTEXT_SWITCH */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH_ZSTORE_BASE_MASK     (0xFFFFFFE0U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH_ZSTORE_BASE_SHIFT    (5U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH_ZSTORE_BASE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH_ZSTORE_BASE_MAX      (0x07ffffffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH_RESETVAL             (0x00000000U)

/* EUR_CR_ISP_CONTEXT_SWITCH2 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_TILE_X_MASK         (0xFF000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_TILE_X_SHIFT        (24U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_TILE_X_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_TILE_X_MAX          (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_TILE_Y_MASK         (0x00FF0000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_TILE_Y_SHIFT        (16U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_TILE_Y_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_TILE_Y_MAX          (0x000000ffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_END_OF_TILE_MASK    (0x00000800U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_END_OF_TILE_SHIFT   (11U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_END_OF_TILE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_END_OF_TILE_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_END_OF_RENDER_MASK  (0x00000400U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_END_OF_RENDER_SHIFT  (10U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_END_OF_RENDER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_END_OF_RENDER_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_PT_IN_FLIGHT_MASK   (0x00000200U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_PT_IN_FLIGHT_SHIFT  (9U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_PT_IN_FLIGHT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_PT_IN_FLIGHT_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_ZLS_BURST_MASK      (0x000001FFU)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_ZLS_BURST_SHIFT     (0U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_ZLS_BURST_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_ZLS_BURST_MAX       (0x000001ffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH2_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_CONTEXT_SWITCH3 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_ZSTORE_CMD_MASK  (0x80000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_ZSTORE_CMD_SHIFT  (31U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_ZSTORE_CMD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_ZSTORE_CMD_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_MACROTILE_ID_MASK  (0x78000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_MACROTILE_ID_SHIFT  (27U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_MACROTILE_ID_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_MACROTILE_ID_MAX  (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_FIRST_TILE_IN_MT_MASK  (0x04000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_FIRST_TILE_IN_MT_SHIFT  (26U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_FIRST_TILE_IN_MT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_FIRST_TILE_IN_MT_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_CMP_BASE_MASK   (0x03FFFFFCU)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_CMP_BASE_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_CMP_BASE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_ZLS_CMP_BASE_MAX    (0x00ffffffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH3_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_CONTEXT_SWITCH4 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH4_PIM_ID_MASK         (0x0FFFFFFFU)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH4_PIM_ID_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH4_PIM_ID_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH4_PIM_ID_MAX          (0x0fffffffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH4_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_CONTEXT_SWITCH5 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH5_EMPTY_STATUS_MASK   (0x000000F0U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH5_EMPTY_STATUS_SHIFT  (4U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH5_EMPTY_STATUS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH5_EMPTY_STATUS_MAX    (0x0000000fU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH5_STREAM_ID_MASK      (0x00000003U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH5_STREAM_ID_SHIFT     (0U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH5_STREAM_ID_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH5_STREAM_ID_MAX       (0x00000003U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH5_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_CONTEXT_SWITCH6 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH6_RGN0_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH6_RGN0_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH6_RGN0_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH6_RGN0_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH6_RGN0_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH6_RGN0_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH6_RGN0_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH6_RGN0_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH6_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_CONTEXT_SWITCH7 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH7_RGN1_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH7_RGN1_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH7_RGN1_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH7_RGN1_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH7_RGN1_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH7_RGN1_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH7_RGN1_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH7_RGN1_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH7_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_CONTEXT_SWITCH8 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH8_RGN2_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH8_RGN2_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH8_RGN2_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH8_RGN2_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH8_RGN2_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH8_RGN2_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH8_RGN2_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH8_RGN2_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH8_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_CONTEXT_SWITCH9 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH9_RGN3_CTRL_STREAM_VALID_MASK  (0x80000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH9_RGN3_CTRL_STREAM_VALID_SHIFT  (31U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH9_RGN3_CTRL_STREAM_VALID_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH9_RGN3_CTRL_STREAM_VALID_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH9_RGN3_CTRL_STREAM_POS_MASK  (0x0FFFFFFCU)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH9_RGN3_CTRL_STREAM_POS_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH9_RGN3_CTRL_STREAM_POS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH9_RGN3_CTRL_STREAM_POS_MAX  (0x03ffffffU)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH9_RESETVAL            (0x00000000U)

/* EUR_CR_ISP_CONTEXT_SWITCH10 */

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH10_SUPPRESS_EOR_SWITCH_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH10_SUPPRESS_EOR_SWITCH_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH10_SUPPRESS_EOR_SWITCH_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH10_SUPPRESS_EOR_SWITCH_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_ISP_CONTEXT_SWITCH10_RESETVAL           (0x00000000U)

/* EUR_CR_DPM_3D_PAGE_TABLE_BASE */

#define CSL_KLIO_EUR_CR_DPM_3D_PAGE_TABLE_BASE_ADDR_MASK        (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_DPM_3D_PAGE_TABLE_BASE_ADDR_SHIFT       (4U)
#define CSL_KLIO_EUR_CR_DPM_3D_PAGE_TABLE_BASE_ADDR_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_3D_PAGE_TABLE_BASE_ADDR_MAX         (0x0fffffffU)

#define CSL_KLIO_EUR_CR_DPM_3D_PAGE_TABLE_BASE_RESETVAL         (0x00000000U)

/* EUR_CR_DPM_3D_FREE_LIST */

#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_TAIL_MASK              (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_TAIL_SHIFT             (16U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_TAIL_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_TAIL_MAX               (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_HEAD_MASK              (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_HEAD_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_HEAD_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_HEAD_MAX               (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_RESETVAL               (0x00000000U)

/* EUR_CR_DPM_PDS_PAGE_THRESHOLD */

#define CSL_KLIO_EUR_CR_DPM_PDS_PAGE_THRESHOLD_VALUE_MASK       (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_PDS_PAGE_THRESHOLD_VALUE_SHIFT      (0U)
#define CSL_KLIO_EUR_CR_DPM_PDS_PAGE_THRESHOLD_VALUE_RESETVAL   (0x00002000U)
#define CSL_KLIO_EUR_CR_DPM_PDS_PAGE_THRESHOLD_VALUE_MAX        (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_PDS_PAGE_THRESHOLD_RESETVAL         (0x00002000U)

/* EUR_CR_DPM_TA_ALLOC_PAGE_TABLE_BASE */

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_PAGE_TABLE_BASE_ADDR_MASK  (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_PAGE_TABLE_BASE_ADDR_SHIFT  (4U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_PAGE_TABLE_BASE_ADDR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_PAGE_TABLE_BASE_ADDR_MAX   (0x0fffffffU)

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_PAGE_TABLE_BASE_RESETVAL   (0x00000000U)

/* EUR_CR_DPM_TA_ALLOC_FREE_LIST */

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_TAIL_MASK        (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_TAIL_SHIFT       (16U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_TAIL_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_TAIL_MAX         (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_HEAD_MASK        (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_HEAD_SHIFT       (0U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_HEAD_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_HEAD_MAX         (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_RESETVAL         (0x00000000U)

/* EUR_CR_DPM_TA_PAGE_THRESHOLD */

#define CSL_KLIO_EUR_CR_DPM_TA_PAGE_THRESHOLD_VALUE_MASK        (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_TA_PAGE_THRESHOLD_VALUE_SHIFT       (0U)
#define CSL_KLIO_EUR_CR_DPM_TA_PAGE_THRESHOLD_VALUE_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_PAGE_THRESHOLD_VALUE_MAX         (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_TA_PAGE_THRESHOLD_RESETVAL          (0x00000000U)

/* EUR_CR_DPM_ZLS_PAGE_THRESHOLD */

#define CSL_KLIO_EUR_CR_DPM_ZLS_PAGE_THRESHOLD_VALUE_MASK       (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_ZLS_PAGE_THRESHOLD_VALUE_SHIFT      (0U)
#define CSL_KLIO_EUR_CR_DPM_ZLS_PAGE_THRESHOLD_VALUE_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_ZLS_PAGE_THRESHOLD_VALUE_MAX        (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_ZLS_PAGE_THRESHOLD_RESETVAL         (0x00000000U)

/* EUR_CR_DPM_TA_GLOBAL_LIST */

#define CSL_KLIO_EUR_CR_DPM_TA_GLOBAL_LIST_POLICY_MASK          (0x00010000U)
#define CSL_KLIO_EUR_CR_DPM_TA_GLOBAL_LIST_POLICY_SHIFT         (16U)
#define CSL_KLIO_EUR_CR_DPM_TA_GLOBAL_LIST_POLICY_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_GLOBAL_LIST_POLICY_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_TA_GLOBAL_LIST_SIZE_MASK            (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_TA_GLOBAL_LIST_SIZE_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_DPM_TA_GLOBAL_LIST_SIZE_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_GLOBAL_LIST_SIZE_MAX             (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_TA_GLOBAL_LIST_RESETVAL             (0x00000000U)

/* EUR_CR_DPM_STATE_TABLE_BASE */

#define CSL_KLIO_EUR_CR_DPM_STATE_TABLE_BASE_ADDR_MASK          (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_DPM_STATE_TABLE_BASE_ADDR_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_DPM_STATE_TABLE_BASE_ADDR_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_STATE_TABLE_BASE_ADDR_MAX           (0x0fffffffU)

#define CSL_KLIO_EUR_CR_DPM_STATE_TABLE_BASE_RESETVAL           (0x00000000U)

/* EUR_CR_DPM_STATE_CONTEXT_ID */

#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_NCOP_MASK          (0x00000008U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_NCOP_SHIFT         (3U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_NCOP_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_NCOP_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_ALLOC_MASK         (0x00000004U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_ALLOC_SHIFT        (2U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_ALLOC_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_ALLOC_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_DALLOC_MASK        (0x00000002U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_DALLOC_SHIFT       (1U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_DALLOC_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_DALLOC_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_LS_MASK            (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_LS_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_LS_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_LS_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_STATE_CONTEXT_ID_RESETVAL           (0x00000000U)

/* EUR_CR_DPM_CONTROL_TABLE_BASE */

#define CSL_KLIO_EUR_CR_DPM_CONTROL_TABLE_BASE_ADDR_MASK        (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_DPM_CONTROL_TABLE_BASE_ADDR_SHIFT       (4U)
#define CSL_KLIO_EUR_CR_DPM_CONTROL_TABLE_BASE_ADDR_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_CONTROL_TABLE_BASE_ADDR_MAX         (0x0fffffffU)

#define CSL_KLIO_EUR_CR_DPM_CONTROL_TABLE_BASE_RESETVAL         (0x00000000U)

/* EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED */

#define CSL_KLIO_EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_GLOBAL_MASK  (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_GLOBAL_SHIFT  (16U)
#define CSL_KLIO_EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_GLOBAL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_GLOBAL_MAX  (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_LOCAL_MASK  (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_LOCAL_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_LOCAL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_LOCAL_MAX  (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_START_OF_CONTEXT_PAGES_ALLOCATED_RESETVAL  (0x00000000U)

/* EUR_CR_DPM_3D_DEALLOCATE */

#define CSL_KLIO_EUR_CR_DPM_3D_DEALLOCATE_ENABLE_MASK           (0x00000002U)
#define CSL_KLIO_EUR_CR_DPM_3D_DEALLOCATE_ENABLE_SHIFT          (1U)
#define CSL_KLIO_EUR_CR_DPM_3D_DEALLOCATE_ENABLE_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_3D_DEALLOCATE_ENABLE_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_3D_DEALLOCATE_GLOBAL_MASK           (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_3D_DEALLOCATE_GLOBAL_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_DPM_3D_DEALLOCATE_GLOBAL_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_3D_DEALLOCATE_GLOBAL_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_3D_DEALLOCATE_RESETVAL              (0x00000000U)

/* EUR_CR_DPM_ALLOC */

#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_OUTOFMEMORY_MASK         (0x00020000U)
#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_OUTOFMEMORY_SHIFT        (17U)
#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_OUTOFMEMORY_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_OUTOFMEMORY_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_VALID_MASK               (0x00010000U)
#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_VALID_SHIFT              (16U)
#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_VALID_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_VALID_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_MASK                     (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_SHIFT                    (0U)
#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_ALLOC_PAGE_MAX                      (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_ALLOC_RESETVAL                      (0x00000000U)

/* EUR_CR_DPM_DALLOC */

#define CSL_KLIO_EUR_CR_DPM_DALLOC_PAGE_FREE_MASK               (0x00010000U)
#define CSL_KLIO_EUR_CR_DPM_DALLOC_PAGE_FREE_SHIFT              (16U)
#define CSL_KLIO_EUR_CR_DPM_DALLOC_PAGE_FREE_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_DALLOC_PAGE_FREE_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_DALLOC_PAGE_MASK                    (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_DALLOC_PAGE_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_DPM_DALLOC_PAGE_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_DALLOC_PAGE_MAX                     (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_DALLOC_RESETVAL                     (0x00000000U)

/* EUR_CR_DPM_TA_ALLOC */

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_PREVIOUS_MASK    (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_PREVIOUS_SHIFT   (16U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_PREVIOUS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_PREVIOUS_MAX     (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_RESETVAL                   (0x00000000U)

/* EUR_CR_DPM_3D */

#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_PREVIOUS_MASK          (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_PREVIOUS_SHIFT         (16U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_PREVIOUS_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_PREVIOUS_MAX           (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_3D_RESETVAL                         (0x00000000U)

/* EUR_CR_DPM_PARTIAL_RENDER */

#define CSL_KLIO_EUR_CR_DPM_PARTIAL_RENDER_ENABLE_MASK          (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_PARTIAL_RENDER_ENABLE_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_DPM_PARTIAL_RENDER_ENABLE_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_PARTIAL_RENDER_ENABLE_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_PARTIAL_RENDER_RESETVAL             (0x00000000U)

/* EUR_CR_DPM_LSS_PARTIAL_CONTEXT */

#define CSL_KLIO_EUR_CR_DPM_LSS_PARTIAL_CONTEXT_OPERATION_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_LSS_PARTIAL_CONTEXT_OPERATION_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_DPM_LSS_PARTIAL_CONTEXT_OPERATION_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_LSS_PARTIAL_CONTEXT_OPERATION_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_LSS_PARTIAL_CONTEXT_RESETVAL        (0x00000000U)

/* EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED */

#define CSL_KLIO_EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_GLOBAL_MASK  (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_GLOBAL_SHIFT  (16U)
#define CSL_KLIO_EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_GLOBAL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_GLOBAL_MAX  (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_LOCAL_MASK  (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_LOCAL_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_LOCAL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_LOCAL_MAX  (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_START_OF_3D_CONTEXT_PAGES_ALLOCATED_RESETVAL  (0x00000000U)

/* EUR_CR_DPM_CONTEXT_PB_BASE */

#define CSL_KLIO_EUR_CR_DPM_CONTEXT_PB_BASE_CMP_MASK            (0x00000007U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_PB_BASE_CMP_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_PB_BASE_CMP_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_PB_BASE_CMP_MAX             (0x00000007U)

#define CSL_KLIO_EUR_CR_DPM_CONTEXT_PB_BASE_RESETVAL            (0x00000000U)

/* EUR_CR_DPM_TASK_3D_FREE */

#define CSL_KLIO_EUR_CR_DPM_TASK_3D_FREE_LOAD_MASK              (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_TASK_3D_FREE_LOAD_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_DPM_TASK_3D_FREE_LOAD_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TASK_3D_FREE_LOAD_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_TASK_3D_FREE_RESETVAL               (0x00000000U)

/* EUR_CR_DPM_TASK_TA_FREE */

#define CSL_KLIO_EUR_CR_DPM_TASK_TA_FREE_LOAD_MASK              (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_TASK_TA_FREE_LOAD_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_DPM_TASK_TA_FREE_LOAD_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TASK_TA_FREE_LOAD_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_TASK_TA_FREE_RESETVAL               (0x00000000U)

/* EUR_CR_DPM_TASK_STATE */

#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_LOAD_MASK                (0x00000004U)
#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_LOAD_SHIFT               (2U)
#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_LOAD_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_LOAD_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_CLEAR_MASK               (0x00000002U)
#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_CLEAR_SHIFT              (1U)
#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_CLEAR_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_CLEAR_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_STORE_MASK               (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_STORE_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_STORE_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_STORE_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_TASK_STATE_RESETVAL                 (0x00000000U)

/* EUR_CR_DPM_TASK_CONTROL */

#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_LOAD_MASK              (0x00000004U)
#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_LOAD_SHIFT             (2U)
#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_LOAD_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_LOAD_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_CLEAR_MASK             (0x00000002U)
#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_CLEAR_SHIFT            (1U)
#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_CLEAR_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_CLEAR_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_STORE_MASK             (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_STORE_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_STORE_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_STORE_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_TASK_CONTROL_RESETVAL               (0x00000000U)

/* EUR_CR_DPM_OUTOFMEM */

#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_ABORTALL_MASK              (0x00000004U)
#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_ABORTALL_SHIFT             (2U)
#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_ABORTALL_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_ABORTALL_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_ABORT_MASK                 (0x00000002U)
#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_ABORT_SHIFT                (1U)
#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_ABORT_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_ABORT_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_RESTART_MASK               (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_RESTART_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_RESTART_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_RESTART_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_OUTOFMEM_RESETVAL                   (0x00000000U)

/* EUR_CR_DPM_FREE_CONTEXT */

#define CSL_KLIO_EUR_CR_DPM_FREE_CONTEXT_NOW_MASK               (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_FREE_CONTEXT_NOW_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_DPM_FREE_CONTEXT_NOW_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_FREE_CONTEXT_NOW_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_FREE_CONTEXT_RESETVAL               (0x00000000U)

/* EUR_CR_DPM_3D_TIMEOUT */

#define CSL_KLIO_EUR_CR_DPM_3D_TIMEOUT_NOW_MASK                 (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_3D_TIMEOUT_NOW_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_DPM_3D_TIMEOUT_NOW_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_3D_TIMEOUT_NOW_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_3D_TIMEOUT_RESETVAL                 (0x00000000U)

/* EUR_CR_DPM_TA_EVM */

#define CSL_KLIO_EUR_CR_DPM_TA_EVM_INIT_MASK                    (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_TA_EVM_INIT_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_DPM_TA_EVM_INIT_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_EVM_INIT_MAX                     (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_TA_EVM_RESETVAL                     (0x00000000U)

/* EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1 */

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1_TAIL_MASK  (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1_TAIL_SHIFT  (16U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1_TAIL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1_TAIL_MAX  (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1_HEAD_MASK  (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1_HEAD_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1_HEAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1_HEAD_MAX  (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS1_RESETVAL  (0x00000000U)

/* EUR_CR_DPM_3D_FREE_LIST_STATUS1 */

#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS1_TAIL_MASK      (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS1_TAIL_SHIFT     (16U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS1_TAIL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS1_TAIL_MAX       (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS1_HEAD_MASK      (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS1_HEAD_SHIFT     (0U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS1_HEAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS1_HEAD_MAX       (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS1_RESETVAL       (0x00000000U)

/* EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS2 */

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS2_PREVIOUS_MASK  (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS2_PREVIOUS_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS2_PREVIOUS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS2_PREVIOUS_MAX  (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_TA_ALLOC_FREE_LIST_STATUS2_RESETVAL  (0x00000000U)

/* EUR_CR_DPM_3D_FREE_LIST_STATUS2 */

#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS2_PREVIOUS_MASK  (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS2_PREVIOUS_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS2_PREVIOUS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS2_PREVIOUS_MAX   (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_3D_FREE_LIST_STATUS2_RESETVAL       (0x00000000U)

/* EUR_CR_DPM_ABORT_STATUS_MTILE */

#define CSL_KLIO_EUR_CR_DPM_ABORT_STATUS_MTILE_GLOBAL_MASK      (0x00000010U)
#define CSL_KLIO_EUR_CR_DPM_ABORT_STATUS_MTILE_GLOBAL_SHIFT     (4U)
#define CSL_KLIO_EUR_CR_DPM_ABORT_STATUS_MTILE_GLOBAL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_ABORT_STATUS_MTILE_GLOBAL_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_ABORT_STATUS_MTILE_INDEX_MASK       (0x0000000FU)
#define CSL_KLIO_EUR_CR_DPM_ABORT_STATUS_MTILE_INDEX_SHIFT      (0U)
#define CSL_KLIO_EUR_CR_DPM_ABORT_STATUS_MTILE_INDEX_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_ABORT_STATUS_MTILE_INDEX_MAX        (0x0000000fU)

#define CSL_KLIO_EUR_CR_DPM_ABORT_STATUS_MTILE_RESETVAL         (0x00000000U)

/* EUR_CR_DPM_PAGE_STATUS */

#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_TA_MASK                 (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_TA_SHIFT                (16U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_TA_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_TA_MAX                  (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_TOTAL_MASK              (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_TOTAL_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_TOTAL_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_TOTAL_MAX               (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_RESETVAL                (0x00000000U)

/* EUR_CR_DPM_PAGE */

#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_3D_MASK                 (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_3D_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_3D_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_STATUS_3D_MAX                  (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_PAGE_RESETVAL                       (0x00000000U)

/* EUR_CR_DPM_GLOBAL_PAGE_STATUS */

#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_TA_MASK          (0xFFFF0000U)
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_TA_SHIFT         (16U)
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_TA_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_TA_MAX           (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_TOTAL_MASK       (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_TOTAL_SHIFT      (0U)
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_TOTAL_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_TOTAL_MAX        (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_RESETVAL         (0x00000000U)

/* EUR_CR_DPM_GLOBAL_PAGE */

#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_3D_MASK          (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_3D_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_3D_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_STATUS_3D_MAX           (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_GLOBAL_PAGE_RESETVAL                (0x00000000U)

/* EUR_CR_DPM_REQUESTING */

#define CSL_KLIO_EUR_CR_DPM_REQUESTING_SOURCE_MASK              (0x00000003U)
#define CSL_KLIO_EUR_CR_DPM_REQUESTING_SOURCE_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_DPM_REQUESTING_SOURCE_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_REQUESTING_SOURCE_MAX               (0x00000003U)

#define CSL_KLIO_EUR_CR_DPM_REQUESTING_RESETVAL                 (0x00000000U)

/* EUR_CR_DPM_RGN_HDR_PARSER */

#define CSL_KLIO_EUR_CR_DPM_RGN_HDR_PARSER_IDLE_MASK            (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_RGN_HDR_PARSER_IDLE_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_DPM_RGN_HDR_PARSER_IDLE_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_RGN_HDR_PARSER_IDLE_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_RGN_HDR_PARSER_RESETVAL             (0x00000001U)

/* EUR_CR_DPM_PIMSHARE */

#define CSL_KLIO_EUR_CR_DPM_PIMSHARE_MTE_MODE_MASK              (0x00000002U)
#define CSL_KLIO_EUR_CR_DPM_PIMSHARE_MTE_MODE_SHIFT             (1U)
#define CSL_KLIO_EUR_CR_DPM_PIMSHARE_MTE_MODE_RESETVAL          (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_PIMSHARE_MTE_MODE_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_PIMSHARE_TAAC_MODE_MASK             (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_PIMSHARE_TAAC_MODE_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_DPM_PIMSHARE_TAAC_MODE_RESETVAL         (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_PIMSHARE_TAAC_MODE_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_PIMSHARE_RESETVAL                   (0x00000003U)

/* EUR_CR_DPM_CONTEXT_DRAIN_BASE */

#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BASE_ADDR_MASK        (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BASE_ADDR_SHIFT       (4U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BASE_ADDR_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BASE_ADDR_MAX         (0x0fffffffU)

#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BASE_RESETVAL         (0x00000000U)

/* EUR_CR_DPM_CONTEXT_DRAIN_STATUS */

#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_STATUS_RESUMED_MASK   (0x00000002U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_STATUS_RESUMED_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_STATUS_RESUMED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_STATUS_RESUMED_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_STATUS_DRAINED_MASK   (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_STATUS_DRAINED_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_STATUS_DRAINED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_STATUS_DRAINED_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_STATUS_RESETVAL       (0x00000000U)

/* EUR_CR_DPM_DRAIN_STATUS */

#define CSL_KLIO_EUR_CR_DPM_DRAIN_STATUS_RESUME_CLEAR_MASK      (0x00000002U)
#define CSL_KLIO_EUR_CR_DPM_DRAIN_STATUS_RESUME_CLEAR_SHIFT     (1U)
#define CSL_KLIO_EUR_CR_DPM_DRAIN_STATUS_RESUME_CLEAR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_DRAIN_STATUS_RESUME_CLEAR_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_DRAIN_STATUS_DRAIN_CLEAR_MASK       (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_DRAIN_STATUS_DRAIN_CLEAR_SHIFT      (0U)
#define CSL_KLIO_EUR_CR_DPM_DRAIN_STATUS_DRAIN_CLEAR_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_DRAIN_STATUS_DRAIN_CLEAR_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_DRAIN_STATUS_RESETVAL               (0x00000000U)

/* EUR_CR_DPM_CONTEXT_DRAIN_BUF */

#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BUF_SIZE_MASK         (0x000007FFU)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BUF_SIZE_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BUF_SIZE_RESETVAL     (0x00000100U)
#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BUF_SIZE_MAX          (0x000007ffU)

#define CSL_KLIO_EUR_CR_DPM_CONTEXT_DRAIN_BUF_RESETVAL          (0x00000100U)

/* EUR_CR_DPM_MTILE_ABORTED */

#define CSL_KLIO_EUR_CR_DPM_MTILE_ABORTED_MASK_MASK             (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_MTILE_ABORTED_MASK_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_DPM_MTILE_ABORTED_MASK_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_MTILE_ABORTED_MASK_MAX              (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_MTILE_ABORTED_RESETVAL              (0x00000000U)

/* EUR_CR_DPM_IDLE */

#define CSL_KLIO_EUR_CR_DPM_IDLE_STATUS_MASK                    (0x0000003FU)
#define CSL_KLIO_EUR_CR_DPM_IDLE_STATUS_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_DPM_IDLE_STATUS_RESETVAL                (0x0000001fU)
#define CSL_KLIO_EUR_CR_DPM_IDLE_STATUS_MAX                     (0x0000003fU)

#define CSL_KLIO_EUR_CR_DPM_IDLE_RESETVAL                       (0x0000001fU)

/* EUR_CR_DPM_PAGE_MANAGEOP */

#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_SERIAL_MASK           (0x00000002U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_SERIAL_SHIFT          (1U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_SERIAL_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_SERIAL_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_DISABLE_MASK          (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_DISABLE_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_DISABLE_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_DISABLE_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_RESETVAL              (0x00000000U)

/* EUR_CR_DPM_DEALLOCATE_MASK */

#define CSL_KLIO_EUR_CR_DPM_DEALLOCATE_MASK_STATUS_MASK         (0x0000FFFFU)
#define CSL_KLIO_EUR_CR_DPM_DEALLOCATE_MASK_STATUS_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_DPM_DEALLOCATE_MASK_STATUS_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_DEALLOCATE_MASK_STATUS_MAX          (0x0000ffffU)

#define CSL_KLIO_EUR_CR_DPM_DEALLOCATE_MASK_RESETVAL            (0x00000000U)

/* EUR_CR_MTE_FORCEREISSUE */

#define CSL_KLIO_EUR_CR_MTE_FORCEREISSUE_ENABLE_N_MASK          (0x00000001U)
#define CSL_KLIO_EUR_CR_MTE_FORCEREISSUE_ENABLE_N_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_MTE_FORCEREISSUE_ENABLE_N_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_FORCEREISSUE_ENABLE_N_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_MTE_FORCEREISSUE_RESETVAL               (0x00000000U)

/* EUR_CR_DPM_PAGE_MANAGEOP_STATUS */

#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_STATUS_DISABLED_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_STATUS_DISABLED_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_STATUS_DISABLED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_STATUS_DISABLED_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_DPM_PAGE_MANAGEOP_STATUS_RESETVAL       (0x00000000U)

/* EUR_CR_DPM_TSP_MTILEFREE */

#define CSL_KLIO_EUR_CR_DPM_TSP_MTILEFREE_STATUS_MASK           (0x0001FFFFU)
#define CSL_KLIO_EUR_CR_DPM_TSP_MTILEFREE_STATUS_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_DPM_TSP_MTILEFREE_STATUS_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_DPM_TSP_MTILEFREE_STATUS_MAX            (0x0001ffffU)

#define CSL_KLIO_EUR_CR_DPM_TSP_MTILEFREE_RESETVAL              (0x00000000U)

/* EUR_CR_TCU_CTRL */

#define CSL_KLIO_EUR_CR_TCU_CTRL_MAX_REQUEST_MASK               (0x00000FE0U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_MAX_REQUEST_SHIFT              (5U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_MAX_REQUEST_RESETVAL           (0x00000030U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_MAX_REQUEST_MAX                (0x0000007fU)

#define CSL_KLIO_EUR_CR_TCU_CTRL_L2OFF_MASK                     (0x00000010U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L2OFF_SHIFT                    (4U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L2OFF_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L2OFF_MAX                      (0x00000001U)

#define CSL_KLIO_EUR_CR_TCU_CTRL_L1P1OFF_MASK                   (0x00000008U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L1P1OFF_SHIFT                  (3U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L1P1OFF_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L1P1OFF_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_TCU_CTRL_L1P0OFF_MASK                   (0x00000004U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L1P0OFF_SHIFT                  (2U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L1P0OFF_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L1P0OFF_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_TCU_CTRL_L0P1OFF_MASK                   (0x00000002U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L0P1OFF_SHIFT                  (1U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L0P1OFF_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L0P1OFF_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_TCU_CTRL_L0P0OFF_MASK                   (0x00000001U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L0P0OFF_SHIFT                  (0U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L0P0OFF_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_TCU_CTRL_L0P0OFF_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_TCU_CTRL_RESETVAL                       (0x00000600U)

/* EUR_CR_TCU_ICTRL */

#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM3_MASK                 (0x00000010U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM3_SHIFT                (4U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM3_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM3_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM2_MASK                 (0x00000008U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM2_SHIFT                (3U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM2_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM2_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM1_MASK                 (0x00000004U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM1_SHIFT                (2U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM1_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM1_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM0_MASK                 (0x00000002U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM0_SHIFT                (1U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM0_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALDM0_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALTCU_MASK                 (0x00000001U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALTCU_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALTCU_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_TCU_ICTRL_INVALTCU_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_TCU_ICTRL_RESETVAL                      (0x00000000U)

/* EUR_CR_DCU_ICTRL */

#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM3_MASK            (0x00000010U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM3_SHIFT           (4U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM3_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM3_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM2_MASK            (0x00000008U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM2_SHIFT           (3U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM2_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM2_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM1_MASK            (0x00000004U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM1_SHIFT           (2U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM1_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM1_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM0_MASK            (0x00000002U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM0_SHIFT           (1U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM0_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATEDM0_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATE_MASK               (0x00000001U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATE_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATE_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_ICTRL_INVALIDATE_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_ICTRL_RESETVAL                      (0x00000000U)

/* EUR_CR_DCU_PCTRL */

#define CSL_KLIO_EUR_CR_DCU_PCTRL_DMTAG_OFF_MASK                (0x00010000U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_DMTAG_OFF_SHIFT               (16U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_DMTAG_OFF_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_DMTAG_OFF_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_PCTRL_PDS_VDM_MASK                  (0x0000F000U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_PDS_VDM_SHIFT                 (12U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_PDS_VDM_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_PDS_VDM_MAX                   (0x0000000fU)

#define CSL_KLIO_EUR_CR_DCU_PCTRL_USE_VDM_MASK                  (0x00000F00U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_USE_VDM_SHIFT                 (8U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_USE_VDM_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_USE_VDM_MAX                   (0x0000000fU)

#define CSL_KLIO_EUR_CR_DCU_PCTRL_PDM_MASK                      (0x000000F0U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_PDM_SHIFT                     (4U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_PDM_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_PDM_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_DCU_PCTRL_EDM_MASK                      (0x0000000FU)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_EDM_SHIFT                     (0U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_EDM_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_PCTRL_EDM_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_DCU_PCTRL_RESETVAL                      (0x00000000U)

/* EUR_CR_DCU_CTRL */

#define CSL_KLIO_EUR_CR_DCU_CTRL_L2OFF_MASK                     (0x00000400U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L2OFF_SHIFT                    (10U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L2OFF_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L2OFF_MAX                      (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_CTRL_L1P1OFF_MASK                   (0x00000200U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L1P1OFF_SHIFT                  (9U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L1P1OFF_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L1P1OFF_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_CTRL_L1P0OFF_MASK                   (0x00000100U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L1P0OFF_SHIFT                  (8U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L1P0OFF_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L1P0OFF_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_CTRL_L0P1OFF_MASK                   (0x00000002U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L0P1OFF_SHIFT                  (1U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L0P1OFF_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L0P1OFF_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_CTRL_L0P0OFF_MASK                   (0x00000001U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L0P0OFF_SHIFT                  (0U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L0P0OFF_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_DCU_CTRL_L0P0OFF_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_DCU_CTRL_RESETVAL                       (0x00000000U)

/* EUR_CR_CLIP_CHECKSUM */

#define CSL_KLIO_EUR_CR_CLIP_CHECKSUM_VALUE_MASK                (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_CLIP_CHECKSUM_VALUE_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_CLIP_CHECKSUM_VALUE_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_CLIP_CHECKSUM_VALUE_MAX                 (0xffffffffU)

#define CSL_KLIO_EUR_CR_CLIP_CHECKSUM_RESETVAL                  (0x00000000U)

/* EUR_CR_MTE_MEM_CHECKSUM */

#define CSL_KLIO_EUR_CR_MTE_MEM_CHECKSUM_VALUE_MASK             (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_MTE_MEM_CHECKSUM_VALUE_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_MTE_MEM_CHECKSUM_VALUE_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_MEM_CHECKSUM_VALUE_MAX              (0xffffffffU)

#define CSL_KLIO_EUR_CR_MTE_MEM_CHECKSUM_RESETVAL               (0x00000000U)

/* EUR_CR_MTE_TE_CHECKSUM */

#define CSL_KLIO_EUR_CR_MTE_TE_CHECKSUM_VALUE_MASK              (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_MTE_TE_CHECKSUM_VALUE_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_MTE_TE_CHECKSUM_VALUE_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_MTE_TE_CHECKSUM_VALUE_MAX               (0xffffffffU)

#define CSL_KLIO_EUR_CR_MTE_TE_CHECKSUM_RESETVAL                (0x00000000U)

/* EUR_CR_TE_CHECKSUM */

#define CSL_KLIO_EUR_CR_TE_CHECKSUM_VALUE_MASK                  (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_TE_CHECKSUM_VALUE_SHIFT                 (0U)
#define CSL_KLIO_EUR_CR_TE_CHECKSUM_VALUE_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_TE_CHECKSUM_VALUE_MAX                   (0xffffffffU)

#define CSL_KLIO_EUR_CR_TE_CHECKSUM_RESETVAL                    (0x00000000U)

/* EUR_CR_ISP_FPU_CHECKSUM */

#define CSL_KLIO_EUR_CR_ISP_FPU_CHECKSUM_VALUE_MASK             (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_ISP_FPU_CHECKSUM_VALUE_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_ISP_FPU_CHECKSUM_VALUE_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_FPU_CHECKSUM_VALUE_MAX              (0xffffffffU)

#define CSL_KLIO_EUR_CR_ISP_FPU_CHECKSUM_RESETVAL               (0x00000000U)

/* EUR_CR_ISP_PRECALC_CHECKSUM */

#define CSL_KLIO_EUR_CR_ISP_PRECALC_CHECKSUM_VALUE_MASK         (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_ISP_PRECALC_CHECKSUM_VALUE_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_ISP_PRECALC_CHECKSUM_VALUE_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_PRECALC_CHECKSUM_VALUE_MAX          (0xffffffffU)

#define CSL_KLIO_EUR_CR_ISP_PRECALC_CHECKSUM_RESETVAL           (0x00000000U)

/* EUR_CR_ISP_EDGE_CHECKSUM */

#define CSL_KLIO_EUR_CR_ISP_EDGE_CHECKSUM_VALUE_MASK            (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_ISP_EDGE_CHECKSUM_VALUE_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_ISP_EDGE_CHECKSUM_VALUE_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_EDGE_CHECKSUM_VALUE_MAX             (0xffffffffU)

#define CSL_KLIO_EUR_CR_ISP_EDGE_CHECKSUM_RESETVAL              (0x00000000U)

/* EUR_CR_ISP_TAGWRITE_CHECKSUM */

#define CSL_KLIO_EUR_CR_ISP_TAGWRITE_CHECKSUM_VALUE_MASK        (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_ISP_TAGWRITE_CHECKSUM_VALUE_SHIFT       (0U)
#define CSL_KLIO_EUR_CR_ISP_TAGWRITE_CHECKSUM_VALUE_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_TAGWRITE_CHECKSUM_VALUE_MAX         (0xffffffffU)

#define CSL_KLIO_EUR_CR_ISP_TAGWRITE_CHECKSUM_RESETVAL          (0x00000000U)

/* EUR_CR_ISP_SPAN_CHECKSUM */

#define CSL_KLIO_EUR_CR_ISP_SPAN_CHECKSUM_VALUE_MASK            (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_ISP_SPAN_CHECKSUM_VALUE_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_ISP_SPAN_CHECKSUM_VALUE_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_ISP_SPAN_CHECKSUM_VALUE_MAX             (0xffffffffU)

#define CSL_KLIO_EUR_CR_ISP_SPAN_CHECKSUM_RESETVAL              (0x00000000U)

/* EUR_CR_PBE_PIXEL_CHECKSUM */

#define CSL_KLIO_EUR_CR_PBE_PIXEL_CHECKSUM_VALUE_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_PBE_PIXEL_CHECKSUM_VALUE_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_PBE_PIXEL_CHECKSUM_VALUE_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_PBE_PIXEL_CHECKSUM_VALUE_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_PBE_PIXEL_CHECKSUM_RESETVAL             (0x00000000U)

/* EUR_CR_USE_CACHE */

#define CSL_KLIO_EUR_CR_USE_CACHE_INVALIDATE_MASK               (0x00000001U)
#define CSL_KLIO_EUR_CR_USE_CACHE_INVALIDATE_SHIFT              (0U)
#define CSL_KLIO_EUR_CR_USE_CACHE_INVALIDATE_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_USE_CACHE_INVALIDATE_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_USE_CACHE_RESETVAL                      (0x00000000U)

/* EUR_CR_EVENT_PDS_ENABLE2 */

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_MTE_STATE_FLUSHED_MASK  (0x00008000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_MTE_STATE_FLUSHED_SHIFT  (15U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_MTE_STATE_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_MTE_STATE_FLUSHED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_MASK  (0x00000800U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_SHIFT  (11U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_UNTRAPPED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_TRAPPED_MASK  (0x00000400U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_TRAPPED_SHIFT  (10U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_TRAPPED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DATA_BREAKPOINT_TRAPPED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_MTE_CONTEXT_DRAINED_MASK  (0x00000200U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_MTE_CONTEXT_DRAINED_SHIFT  (9U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_MTE_CONTEXT_DRAINED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_MTE_CONTEXT_DRAINED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_ISP2_ZLS_CSW_FINISHED_MASK  (0x00000100U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_ISP2_ZLS_CSW_FINISHED_SHIFT  (8U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_ISP2_ZLS_CSW_FINISHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_ISP2_ZLS_CSW_FINISHED_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DCU_INVALCOMPLETE_MASK  (0x00000080U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DCU_INVALCOMPLETE_SHIFT  (7U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TE_RGNHDR_INIT_COMPLETE_MASK  (0x00000020U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TE_RGNHDR_INIT_COMPLETE_SHIFT  (5U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TE_RGNHDR_INIT_COMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TE_RGNHDR_INIT_COMPLETE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_TA_MASK          (0x00000010U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_TA_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_TA_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_TA_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_3D_MASK          (0x00000008U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_3D_SHIFT         (3U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_3D_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_3D_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_DL_MASK          (0x00000004U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_DL_SHIFT         (2U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_DL_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_TRIG_DL_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DPM_3D_FREE_LOAD_MASK  (0x00000002U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DPM_3D_FREE_LOAD_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DPM_3D_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DPM_3D_FREE_LOAD_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DPM_TA_FREE_LOAD_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DPM_TA_FREE_LOAD_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DPM_TA_FREE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_DPM_TA_FREE_LOAD_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE2_RESETVAL              (0x00000000U)

/* EUR_CR_PDS_CACHE_ENABLE */

#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV3_MASK          (0x00000010U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV3_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV3_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV3_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV1_MASK          (0x00000004U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV1_SHIFT         (2U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV1_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV1_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV0_MASK          (0x00000002U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV0_SHIFT         (1U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV0_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_DSC_INV0_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_CSC_INV_MASK           (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_CSC_INV_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_CSC_INV_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_CSC_INV_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CACHE_ENABLE_RESETVAL               (0x00000000U)

/* EUR_CR_EVENT_PDS_ENABLE */

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TIMER_MASK             (0x20000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TIMER_SHIFT            (29U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TIMER_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TIMER_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_DPM_FAULT_MASK      (0x10000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_DPM_FAULT_SHIFT     (28U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_DPM_FAULT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_DPM_FAULT_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TCU_INVALCOMPLETE_MASK  (0x04000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TCU_INVALCOMPLETE_SHIFT  (26U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TCU_INVALCOMPLETE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TCU_INVALCOMPLETE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_ZLS_MASK  (0x02000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_ZLS_SHIFT  (25U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_ZLS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_ZLS_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_TA_MEM_FREE_MASK   (0x01000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_TA_MEM_FREE_SHIFT  (24U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_TA_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_TA_MEM_FREE_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_ISP_END_PASS_MASK      (0x00800000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_ISP_END_PASS_SHIFT     (23U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_ISP_END_PASS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_ISP_END_PASS_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_INITEND_MASK       (0x00400000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_INITEND_SHIFT      (22U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_INITEND_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_INITEND_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_LOADED_MASK       (0x00200000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_LOADED_SHIFT      (21U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_LOADED_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_LOADED_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_INV_MASK          (0x00100000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_INV_SHIFT         (20U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_INV_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_INV_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_FLUSHED_MASK      (0x00080000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_FLUSHED_SHIFT     (19U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_FLUSHED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_OTPM_FLUSHED_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_PIXELBE_END_RENDER_MASK  (0x00040000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_PIXELBE_END_RENDER_SHIFT  (18U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_PIXELBE_END_RENDER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_PIXELBE_END_RENDER_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_BREAKPOINT_MASK        (0x00008000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_BREAKPOINT_SHIFT       (15U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_BREAKPOINT_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_BREAKPOINT_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_SW_EVENT_MASK          (0x00004000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_SW_EVENT_SHIFT         (14U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_SW_EVENT_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_SW_EVENT_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_FINISHED_MASK       (0x00002000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_FINISHED_SHIFT      (13U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_FINISHED_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_FINISHED_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_TERMINATE_MASK      (0x00001000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_TERMINATE_SHIFT     (12U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_TERMINATE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TA_TERMINATE_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TPC_CLEAR_MASK         (0x00000800U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TPC_CLEAR_SHIFT        (11U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TPC_CLEAR_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TPC_CLEAR_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TPC_FLUSH_MASK         (0x00000400U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TPC_FLUSH_SHIFT        (10U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TPC_FLUSH_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_TPC_FLUSH_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_CLEAR_MASK  (0x00000200U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_CLEAR_SHIFT  (9U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_CLEAR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_CLEAR_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_LOAD_MASK  (0x00000100U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_LOAD_SHIFT  (8U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_LOAD_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_STORE_MASK  (0x00000080U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_STORE_SHIFT  (7U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_STORE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_CONTROL_STORE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_CLEAR_MASK   (0x00000040U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_CLEAR_SHIFT  (6U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_CLEAR_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_CLEAR_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_LOAD_MASK    (0x00000020U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_LOAD_SHIFT   (5U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_LOAD_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_LOAD_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_STORE_MASK   (0x00000010U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_STORE_SHIFT  (4U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_STORE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_STATE_STORE_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_REACHED_MEM_THRESH_MASK  (0x00000008U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_REACHED_MEM_THRESH_SHIFT  (3U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_REACHED_MEM_THRESH_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_REACHED_MEM_THRESH_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_GBL_MASK  (0x00000004U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_GBL_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_GBL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_GBL_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_MT_MASK  (0x00000002U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_MT_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_MT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_OUT_OF_MEMORY_MT_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_3D_MEM_FREE_MASK   (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_3D_MEM_FREE_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_3D_MEM_FREE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_DPM_3D_MEM_FREE_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_PDS_ENABLE_RESETVAL               (0x00000000U)

/* EUR_CR_EVENT_PIXEL_PDS_EXEC */

#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_EXEC_ADDR_MASK          (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_EXEC_ADDR_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_EXEC_ADDR_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_EXEC_ADDR_MAX           (0x0fffffffU)

#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_EXEC_RESETVAL           (0x00000000U)

/* EUR_CR_EVENT_PIXEL_PDS_DATA */

#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_DATA_SIZE_MASK          (0x0000001FU)
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_DATA_SIZE_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_DATA_SIZE_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_DATA_SIZE_MAX           (0x0000001fU)

#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_DATA_RESETVAL           (0x00000000U)

/* EUR_CR_EVENT_PIXEL_PDS_INFO */

#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_INFO_ATTRIBUTE_SIZE_MASK  (0x003FE000U)
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_INFO_ATTRIBUTE_SIZE_SHIFT  (13U)
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_INFO_ATTRIBUTE_SIZE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_INFO_ATTRIBUTE_SIZE_MAX  (0x000001ffU)

#define CSL_KLIO_EUR_CR_EVENT_PIXEL_PDS_INFO_RESETVAL           (0x00000000U)

/* EUR_CR_EVENT_OTHER_PDS_EXEC */

#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_EXEC_ADDR_MASK          (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_EXEC_ADDR_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_EXEC_ADDR_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_EXEC_ADDR_MAX           (0x0fffffffU)

#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_EXEC_RESETVAL           (0x00000000U)

/* EUR_CR_EVENT_OTHER_PDS_DATA */

#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_DATA_SIZE_MASK          (0x0000001FU)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_DATA_SIZE_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_DATA_SIZE_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_DATA_SIZE_MAX           (0x0000001fU)

#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_DATA_RESETVAL           (0x00000000U)

/* EUR_CR_EVENT_OTHER_PDS_INFO */

#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_ATTRIBUTE_SIZE_MASK  (0x001FE000U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_ATTRIBUTE_SIZE_SHIFT  (13U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_ATTRIBUTE_SIZE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_ATTRIBUTE_SIZE_MAX  (0x000000ffU)

#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_MULTIPLE_MASK      (0x00000400U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_MULTIPLE_SHIFT     (10U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_MULTIPLE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_MULTIPLE_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_USE_PIPELINE_MASK  (0x00000100U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_USE_PIPELINE_SHIFT  (8U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_USE_PIPELINE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_USE_PIPELINE__0    (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_USE_PIPELINE_TOGGLE  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_SD_MASK            (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_SD_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_SD_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_SD_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_OTHER_PDS_INFO_RESETVAL           (0x00000000U)

/* EUR_CR_DMS_CTRL */

#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_VERTEX_PARTITIONS_MASK  (0x3C000000U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_VERTEX_PARTITIONS_SHIFT  (26U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_VERTEX_PARTITIONS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_VERTEX_PARTITIONS_MAX  (0x0000000fU)

#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_PIXEL_PARTITIONS_MASK  (0x03C00000U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_PIXEL_PARTITIONS_SHIFT  (22U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_PIXEL_PARTITIONS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_PIXEL_PARTITIONS_MAX   (0x0000000fU)

#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_EDM_TASKS_MASK         (0x003F0000U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_EDM_TASKS_SHIFT        (16U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_EDM_TASKS_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_EDM_TASKS_MAX          (0x0000003fU)

#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_VERTEX_TASKS_MASK      (0x0000FC00U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_VERTEX_TASKS_SHIFT     (10U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_VERTEX_TASKS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_VERTEX_TASKS_MAX       (0x0000003fU)

#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_PIXEL_TASKS_MASK       (0x000003F0U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_PIXEL_TASKS_SHIFT      (4U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_PIXEL_TASKS_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_MAX_NUM_PIXEL_TASKS_MAX        (0x0000003fU)

#define CSL_KLIO_EUR_CR_DMS_CTRL_DISABLE_DM_MASK                (0x00000007U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_DISABLE_DM_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_DISABLE_DM_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_DMS_CTRL_DISABLE_DM_MAX                 (0x00000007U)

#define CSL_KLIO_EUR_CR_DMS_CTRL_RESETVAL                       (0x00000000U)

/* EUR_CR_USE_G0 */

#define CSL_KLIO_EUR_CR_USE_G0_P_MASK                           (0x000000FFU)
#define CSL_KLIO_EUR_CR_USE_G0_P_SHIFT                          (0U)
#define CSL_KLIO_EUR_CR_USE_G0_P_RESETVAL                       (0x00000000U)
#define CSL_KLIO_EUR_CR_USE_G0_P_MAX                            (0x000000ffU)

#define CSL_KLIO_EUR_CR_USE_G0_RESETVAL                         (0x00000000U)

/* EUR_CR_USE_G1 */

#define CSL_KLIO_EUR_CR_USE_G1_P_MASK                           (0x000000FFU)
#define CSL_KLIO_EUR_CR_USE_G1_P_SHIFT                          (0U)
#define CSL_KLIO_EUR_CR_USE_G1_P_RESETVAL                       (0x00000000U)
#define CSL_KLIO_EUR_CR_USE_G1_P_MAX                            (0x000000ffU)

#define CSL_KLIO_EUR_CR_USE_G1_RESETVAL                         (0x00000000U)

/* EUR_CR_PDS_DMS_CTRL2 */

#define CSL_KLIO_EUR_CR_PDS_DMS_CTRL2_MAX_PARTITIONS_MASK       (0x00000007U)
#define CSL_KLIO_EUR_CR_PDS_DMS_CTRL2_MAX_PARTITIONS_SHIFT      (0U)
#define CSL_KLIO_EUR_CR_PDS_DMS_CTRL2_MAX_PARTITIONS_RESETVAL   (0x00000004U)
#define CSL_KLIO_EUR_CR_PDS_DMS_CTRL2_MAX_PARTITIONS_MAX        (0x00000007U)

#define CSL_KLIO_EUR_CR_PDS_DMS_CTRL2_RESETVAL                  (0x00000004U)

/* EUR_CR_PDS */

#define CSL_KLIO_EUR_CR_PDS_DOUT_TIMEOUT_DISABLE_MASK           (0x00000040U)
#define CSL_KLIO_EUR_CR_PDS_DOUT_TIMEOUT_DISABLE_SHIFT          (6U)
#define CSL_KLIO_EUR_CR_PDS_DOUT_TIMEOUT_DISABLE_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_DOUT_TIMEOUT_DISABLE_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_ATTRIBUTE_CHUNK_START_MASK          (0x0000003FU)
#define CSL_KLIO_EUR_CR_PDS_ATTRIBUTE_CHUNK_START_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_PDS_ATTRIBUTE_CHUNK_START_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_ATTRIBUTE_CHUNK_START_MAX           (0x0000003fU)

#define CSL_KLIO_EUR_CR_PDS_RESETVAL                            (0x00000000U)

/* EUR_CR_PDS_INV0 */

#define CSL_KLIO_EUR_CR_PDS_INV0_DSC_MASK                       (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_INV0_DSC_SHIFT                      (0U)
#define CSL_KLIO_EUR_CR_PDS_INV0_DSC_RESETVAL                   (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_INV0_DSC_MAX                        (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_INV0_RESETVAL                       (0x00000000U)

/* EUR_CR_PDS_INV1 */

#define CSL_KLIO_EUR_CR_PDS_INV1_DSC_MASK                       (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_INV1_DSC_SHIFT                      (0U)
#define CSL_KLIO_EUR_CR_PDS_INV1_DSC_RESETVAL                   (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_INV1_DSC_MAX                        (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_INV1_RESETVAL                       (0x00000000U)

/* EUR_CR_PDS_INV3 */

#define CSL_KLIO_EUR_CR_PDS_INV3_DSC_MASK                       (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_INV3_DSC_SHIFT                      (0U)
#define CSL_KLIO_EUR_CR_PDS_INV3_DSC_RESETVAL                   (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_INV3_DSC_MAX                        (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_INV3_RESETVAL                       (0x00000000U)

/* EUR_CR_PDS_INV_CSC */

#define CSL_KLIO_EUR_CR_PDS_INV_CSC_KICK_MASK                   (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_INV_CSC_KICK_SHIFT                  (0U)
#define CSL_KLIO_EUR_CR_PDS_INV_CSC_KICK_RESETVAL               (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_INV_CSC_KICK_MAX                    (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_INV_CSC_RESETVAL                    (0x00000000U)

/* EUR_CR_PDS_DMS_DYNAMIC_SCHEDULE */

#define CSL_KLIO_EUR_CR_PDS_DMS_DYNAMIC_SCHEDULE_ENABLE_MASK    (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_DMS_DYNAMIC_SCHEDULE_ENABLE_SHIFT   (0U)
#define CSL_KLIO_EUR_CR_PDS_DMS_DYNAMIC_SCHEDULE_ENABLE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_DMS_DYNAMIC_SCHEDULE_ENABLE_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_DMS_DYNAMIC_SCHEDULE_RESETVAL       (0x00000000U)

/* EUR_CR_EVENT_KICKER */

#define CSL_KLIO_EUR_CR_EVENT_KICKER_ADDRESS_MASK               (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_EVENT_KICKER_ADDRESS_SHIFT              (4U)
#define CSL_KLIO_EUR_CR_EVENT_KICKER_ADDRESS_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICKER_ADDRESS_MAX                (0x0fffffffU)

#define CSL_KLIO_EUR_CR_EVENT_KICKER_RESETVAL                   (0x00000000U)

/* EUR_CR_EVENT_KICK */

#define CSL_KLIO_EUR_CR_EVENT_KICK_NOW_MASK                     (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_KICK_NOW_SHIFT                    (0U)
#define CSL_KLIO_EUR_CR_EVENT_KICK_NOW_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK_NOW_MAX                      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_KICK_RESETVAL                     (0x00000000U)

/* EUR_CR_EVENT_KICK1 */

#define CSL_KLIO_EUR_CR_EVENT_KICK1_NOW_MASK                    (0x000000FFU)
#define CSL_KLIO_EUR_CR_EVENT_KICK1_NOW_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_EVENT_KICK1_NOW_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK1_NOW_MAX                     (0x000000ffU)

#define CSL_KLIO_EUR_CR_EVENT_KICK1_RESETVAL                    (0x00000000U)

/* EUR_CR_EVENT_KICK2 */

#define CSL_KLIO_EUR_CR_EVENT_KICK2_NOW_MASK                    (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_KICK2_NOW_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_EVENT_KICK2_NOW_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK2_NOW_MAX                     (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_KICK2_RESETVAL                    (0x00000000U)

/* EUR_CR_EVENT_KICK3 */

#define CSL_KLIO_EUR_CR_EVENT_KICK3_NOW_MASK                    (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_KICK3_NOW_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_EVENT_KICK3_NOW_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK3_NOW_MAX                     (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_KICK3_RESETVAL                    (0x00000000U)

/* EUR_CR_MICRO_DATA_BASE */

#define CSL_KLIO_EUR_CR_MICRO_DATA_BASE_ADDRESS_MASK            (0xFFFFF000U)
#define CSL_KLIO_EUR_CR_MICRO_DATA_BASE_ADDRESS_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_MICRO_DATA_BASE_ADDRESS_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_MICRO_DATA_BASE_ADDRESS_MAX             (0x000fffffU)

#define CSL_KLIO_EUR_CR_MICRO_DATA_BASE_RESETVAL                (0x00000000U)

/* EUR_CR_EVENT_KICK4 */

#define CSL_KLIO_EUR_CR_EVENT_KICK4_PIXELBE_END_RENDER_MASK     (0x00040000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_PIXELBE_END_RENDER_SHIFT    (18U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_PIXELBE_END_RENDER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_PIXELBE_END_RENDER_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_KICK4_TA_FINISHED_MASK            (0x00002000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_TA_FINISHED_SHIFT           (13U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_TA_FINISHED_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_TA_FINISHED_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_KICK4_TA_TERMINATE_MASK           (0x00001000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_TA_TERMINATE_SHIFT          (12U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_TA_TERMINATE_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_TA_TERMINATE_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_REACHED_MEM_THRESH_MASK  (0x00000008U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_REACHED_MEM_THRESH_SHIFT  (3U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_REACHED_MEM_THRESH_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_REACHED_MEM_THRESH_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_OUT_OF_MEMORY_GBL_MASK  (0x00000004U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_OUT_OF_MEMORY_GBL_SHIFT  (2U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_OUT_OF_MEMORY_GBL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_OUT_OF_MEMORY_GBL_MAX   (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_OUT_OF_MEMORY_MT_MASK   (0x00000002U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_OUT_OF_MEMORY_MT_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_OUT_OF_MEMORY_MT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_OUT_OF_MEMORY_MT_MAX    (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_3D_MEM_FREE_MASK        (0x00000001U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_3D_MEM_FREE_SHIFT       (0U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_3D_MEM_FREE_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_KICK4_DPM_3D_MEM_FREE_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_KICK4_RESETVAL                    (0x00000000U)

/* EUR_CR_EVENT_TIMER */

#define CSL_KLIO_EUR_CR_EVENT_TIMER_ENABLE_MASK                 (0x01000000U)
#define CSL_KLIO_EUR_CR_EVENT_TIMER_ENABLE_SHIFT                (24U)
#define CSL_KLIO_EUR_CR_EVENT_TIMER_ENABLE_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_TIMER_ENABLE_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_EVENT_TIMER_VALUE_MASK                  (0x00FFFFFFU)
#define CSL_KLIO_EUR_CR_EVENT_TIMER_VALUE_SHIFT                 (0U)
#define CSL_KLIO_EUR_CR_EVENT_TIMER_VALUE_RESETVAL              (0x00000000U)
#define CSL_KLIO_EUR_CR_EVENT_TIMER_VALUE_MAX                   (0x00ffffffU)

#define CSL_KLIO_EUR_CR_EVENT_TIMER_RESETVAL                    (0x00000000U)

/* EUR_CR_LOOPBACK */

#define CSL_KLIO_EUR_CR_LOOPBACK_STATUS_MASK                    (0x00000001U)
#define CSL_KLIO_EUR_CR_LOOPBACK_STATUS_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_LOOPBACK_STATUS_RESETVAL                (0x00000001U)
#define CSL_KLIO_EUR_CR_LOOPBACK_STATUS_MAX                     (0x00000001U)

#define CSL_KLIO_EUR_CR_LOOPBACK_RESETVAL                       (0x00000001U)

/* EUR_CR_PDS_EVDM_PC_BASE */

#define CSL_KLIO_EUR_CR_PDS_EVDM_PC_BASE_ADDRESS_MASK           (0x3FFFFFFFU)
#define CSL_KLIO_EUR_CR_PDS_EVDM_PC_BASE_ADDRESS_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_PDS_EVDM_PC_BASE_ADDRESS_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_EVDM_PC_BASE_ADDRESS_MAX            (0x3fffffffU)

#define CSL_KLIO_EUR_CR_PDS_EVDM_PC_BASE_RESETVAL               (0x00000000U)

/* EUR_CR_PDS_PDM_PC_BASE */

#define CSL_KLIO_EUR_CR_PDS_PDM_PC_BASE_ADDRESS_MASK            (0x3FFFFFFFU)
#define CSL_KLIO_EUR_CR_PDS_PDM_PC_BASE_ADDRESS_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_PDS_PDM_PC_BASE_ADDRESS_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_PDM_PC_BASE_ADDRESS_MAX             (0x3fffffffU)

#define CSL_KLIO_EUR_CR_PDS_PDM_PC_BASE_RESETVAL                (0x00000000U)

/* EUR_CR_PDS_STATUS */

#define CSL_KLIO_EUR_CR_PDS_STATUS_IPF_COMPLETED_MASK           (0x00000010U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_IPF_COMPLETED_SHIFT          (4U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_IPF_COMPLETED_RESETVAL       (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_IPF_COMPLETED_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_STATUS_CSWITCH_COMPLETED_MASK       (0x00000008U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_CSWITCH_COMPLETED_SHIFT      (3U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_CSWITCH_COMPLETED_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_CSWITCH_COMPLETED_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_STATUS_RENDER_COMPLETED_MASK        (0x00000004U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_RENDER_COMPLETED_SHIFT       (2U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_RENDER_COMPLETED_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_RENDER_COMPLETED_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_STATUS_CSWITCH_STORE_END_RENDER_MASK  (0x00000002U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_CSWITCH_STORE_END_RENDER_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_CSWITCH_STORE_END_RENDER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_CSWITCH_STORE_END_RENDER_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_STATUS_RENDER_IN_PROGRESS_MASK      (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_RENDER_IN_PROGRESS_SHIFT     (0U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_RENDER_IN_PROGRESS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_STATUS_RENDER_IN_PROGRESS_MAX       (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_STATUS_RESETVAL                     (0x00000010U)

/* EUR_CR_PDS_CONTEXT_STORE */

#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_ADDRESS_MASK          (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_ADDRESS_SHIFT         (4U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_ADDRESS_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_ADDRESS_MAX           (0x0fffffffU)

#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_TILE_ONLY_MASK        (0x00000002U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_TILE_ONLY_SHIFT       (1U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_TILE_ONLY_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_TILE_ONLY_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_DISABLE_MASK          (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_DISABLE_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_DISABLE_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_DISABLE_MAX           (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CONTEXT_STORE_RESETVAL              (0x00000000U)

/* EUR_CR_PDS_CONTEXT_RESUME */

#define CSL_KLIO_EUR_CR_PDS_CONTEXT_RESUME_ADDRESS_MASK         (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_RESUME_ADDRESS_SHIFT        (4U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_RESUME_ADDRESS_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_RESUME_ADDRESS_MAX          (0x0fffffffU)

#define CSL_KLIO_EUR_CR_PDS_CONTEXT_RESUME_VALID_STREAM_MASK    (0x00000001U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_RESUME_VALID_STREAM_SHIFT   (0U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_RESUME_VALID_STREAM_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PDS_CONTEXT_RESUME_VALID_STREAM_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_PDS_CONTEXT_RESUME_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_CTRL */

#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_DPM_MASK     (0x00080000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_DPM_SHIFT    (19U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_DPM_RESETVAL  (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_DPM_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_IPF_MASK     (0x00040000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_IPF_SHIFT    (18U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_IPF_RESETVAL  (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_IPF_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_VDM_MASK     (0x00020000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_VDM_SHIFT    (17U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_VDM_RESETVAL  (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_MASTER_VDM_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_PTLA_MASK           (0x00010000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_PTLA_SHIFT          (16U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_PTLA_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_PTLA_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_USE_MASK            (0x00008000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_USE_SHIFT           (15U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_USE_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_USE_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_ISP_MASK            (0x00004000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_ISP_SHIFT           (14U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_ISP_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_ISP_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_TSPP_MASK           (0x00002000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_TSPP_SHIFT          (13U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_TSPP_RESETVAL       (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_TSPP_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_PBE_MASK            (0x00001000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_PBE_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_PBE_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_PBE_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_TA_MASK             (0x00000400U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_TA_SHIFT            (10U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_TA_RESETVAL         (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_TA_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_VDM_MASK            (0x00000200U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_VDM_SHIFT           (9U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_VDM_RESETVAL        (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_MMU_BYPASS_VDM_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_CLEAR_FAULT_MASK               (0x00000010U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_CLEAR_FAULT_SHIFT              (4U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_CLEAR_FAULT_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_CLEAR_FAULT_MAX                (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_PAUSE_MASK                     (0x00000002U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_PAUSE_SHIFT                    (1U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_PAUSE_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_PAUSE_MAX                      (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_NOREORDER_MASK                 (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_NOREORDER_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_NOREORDER_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_NOREORDER_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_RESETVAL                       (0x000ef600U)

/* EUR_CR_BIF_INT_STAT */

#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FLUSH_COMPLETE_MASK        (0x00080000U)
#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FLUSH_COMPLETE_SHIFT       (19U)
#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FLUSH_COMPLETE_RESETVAL    (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FLUSH_COMPLETE_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FAULT_TYPE_MASK            (0x00070000U)
#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FAULT_TYPE_SHIFT           (16U)
#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FAULT_TYPE_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FAULT_TYPE_MAX             (0x00000007U)

#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FAULT_REQ_MASK             (0x00003FFFU)
#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FAULT_REQ_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FAULT_REQ_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_INT_STAT_FAULT_REQ_MAX              (0x00003fffU)

#define CSL_KLIO_EUR_CR_BIF_INT_STAT_RESETVAL                   (0x00080000U)

/* EUR_CR_BIF_FAULT */

#define CSL_KLIO_EUR_CR_BIF_FAULT_ADDR_MASK                     (0xFFFFF000U)
#define CSL_KLIO_EUR_CR_BIF_FAULT_ADDR_SHIFT                    (12U)
#define CSL_KLIO_EUR_CR_BIF_FAULT_ADDR_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_FAULT_ADDR_MAX                      (0x000fffffU)

#define CSL_KLIO_EUR_CR_BIF_FAULT_SB_MASK                       (0x000001F0U)
#define CSL_KLIO_EUR_CR_BIF_FAULT_SB_SHIFT                      (4U)
#define CSL_KLIO_EUR_CR_BIF_FAULT_SB_RESETVAL                   (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_FAULT_SB_MAX                        (0x0000001fU)

#define CSL_KLIO_EUR_CR_BIF_FAULT_CID_MASK                      (0x0000000FU)
#define CSL_KLIO_EUR_CR_BIF_FAULT_CID_SHIFT                     (0U)
#define CSL_KLIO_EUR_CR_BIF_FAULT_CID_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_FAULT_CID_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_FAULT_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_CTRL_INVAL */

#define CSL_KLIO_EUR_CR_BIF_CTRL_INVAL_ALL_MASK                 (0x00000008U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_INVAL_ALL_SHIFT                (3U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_INVAL_ALL_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_INVAL_ALL_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_INVAL_PTE_MASK                 (0x00000004U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_INVAL_PTE_SHIFT                (2U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_INVAL_PTE_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_CTRL_INVAL_PTE_MAX                  (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CTRL_INVAL_RESETVAL                 (0x00000000U)

/* EUR_CR_BIF_TILE0 */

#define CSL_KLIO_EUR_CR_BIF_TILE0_CFG_MASK                      (0x0F000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE0_CFG_SHIFT                     (24U)
#define CSL_KLIO_EUR_CR_BIF_TILE0_CFG_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE0_CFG_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_TILE0_MAX_ADDRESS_MASK              (0x00FFF000U)
#define CSL_KLIO_EUR_CR_BIF_TILE0_MAX_ADDRESS_SHIFT             (12U)
#define CSL_KLIO_EUR_CR_BIF_TILE0_MAX_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE0_MAX_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE0_MIN_ADDRESS_MASK              (0x00000FFFU)
#define CSL_KLIO_EUR_CR_BIF_TILE0_MIN_ADDRESS_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_TILE0_MIN_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE0_MIN_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE0_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_TILE1 */

#define CSL_KLIO_EUR_CR_BIF_TILE1_CFG_MASK                      (0x0F000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE1_CFG_SHIFT                     (24U)
#define CSL_KLIO_EUR_CR_BIF_TILE1_CFG_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE1_CFG_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_TILE1_MAX_ADDRESS_MASK              (0x00FFF000U)
#define CSL_KLIO_EUR_CR_BIF_TILE1_MAX_ADDRESS_SHIFT             (12U)
#define CSL_KLIO_EUR_CR_BIF_TILE1_MAX_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE1_MAX_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE1_MIN_ADDRESS_MASK              (0x00000FFFU)
#define CSL_KLIO_EUR_CR_BIF_TILE1_MIN_ADDRESS_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_TILE1_MIN_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE1_MIN_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE1_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_TILE2 */

#define CSL_KLIO_EUR_CR_BIF_TILE2_CFG_MASK                      (0x0F000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE2_CFG_SHIFT                     (24U)
#define CSL_KLIO_EUR_CR_BIF_TILE2_CFG_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE2_CFG_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_TILE2_MAX_ADDRESS_MASK              (0x00FFF000U)
#define CSL_KLIO_EUR_CR_BIF_TILE2_MAX_ADDRESS_SHIFT             (12U)
#define CSL_KLIO_EUR_CR_BIF_TILE2_MAX_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE2_MAX_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE2_MIN_ADDRESS_MASK              (0x00000FFFU)
#define CSL_KLIO_EUR_CR_BIF_TILE2_MIN_ADDRESS_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_TILE2_MIN_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE2_MIN_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE2_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_TILE3 */

#define CSL_KLIO_EUR_CR_BIF_TILE3_CFG_MASK                      (0x0F000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE3_CFG_SHIFT                     (24U)
#define CSL_KLIO_EUR_CR_BIF_TILE3_CFG_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE3_CFG_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_TILE3_MAX_ADDRESS_MASK              (0x00FFF000U)
#define CSL_KLIO_EUR_CR_BIF_TILE3_MAX_ADDRESS_SHIFT             (12U)
#define CSL_KLIO_EUR_CR_BIF_TILE3_MAX_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE3_MAX_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE3_MIN_ADDRESS_MASK              (0x00000FFFU)
#define CSL_KLIO_EUR_CR_BIF_TILE3_MIN_ADDRESS_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_TILE3_MIN_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE3_MIN_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE3_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_TILE4 */

#define CSL_KLIO_EUR_CR_BIF_TILE4_CFG_MASK                      (0x0F000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE4_CFG_SHIFT                     (24U)
#define CSL_KLIO_EUR_CR_BIF_TILE4_CFG_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE4_CFG_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_TILE4_MAX_ADDRESS_MASK              (0x00FFF000U)
#define CSL_KLIO_EUR_CR_BIF_TILE4_MAX_ADDRESS_SHIFT             (12U)
#define CSL_KLIO_EUR_CR_BIF_TILE4_MAX_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE4_MAX_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE4_MIN_ADDRESS_MASK              (0x00000FFFU)
#define CSL_KLIO_EUR_CR_BIF_TILE4_MIN_ADDRESS_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_TILE4_MIN_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE4_MIN_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE4_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_TILE5 */

#define CSL_KLIO_EUR_CR_BIF_TILE5_CFG_MASK                      (0x0F000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE5_CFG_SHIFT                     (24U)
#define CSL_KLIO_EUR_CR_BIF_TILE5_CFG_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE5_CFG_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_TILE5_MAX_ADDRESS_MASK              (0x00FFF000U)
#define CSL_KLIO_EUR_CR_BIF_TILE5_MAX_ADDRESS_SHIFT             (12U)
#define CSL_KLIO_EUR_CR_BIF_TILE5_MAX_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE5_MAX_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE5_MIN_ADDRESS_MASK              (0x00000FFFU)
#define CSL_KLIO_EUR_CR_BIF_TILE5_MIN_ADDRESS_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_TILE5_MIN_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE5_MIN_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE5_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_TILE6 */

#define CSL_KLIO_EUR_CR_BIF_TILE6_CFG_MASK                      (0x0F000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE6_CFG_SHIFT                     (24U)
#define CSL_KLIO_EUR_CR_BIF_TILE6_CFG_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE6_CFG_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_TILE6_MAX_ADDRESS_MASK              (0x00FFF000U)
#define CSL_KLIO_EUR_CR_BIF_TILE6_MAX_ADDRESS_SHIFT             (12U)
#define CSL_KLIO_EUR_CR_BIF_TILE6_MAX_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE6_MAX_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE6_MIN_ADDRESS_MASK              (0x00000FFFU)
#define CSL_KLIO_EUR_CR_BIF_TILE6_MIN_ADDRESS_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_TILE6_MIN_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE6_MIN_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE6_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_TILE7 */

#define CSL_KLIO_EUR_CR_BIF_TILE7_CFG_MASK                      (0x0F000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE7_CFG_SHIFT                     (24U)
#define CSL_KLIO_EUR_CR_BIF_TILE7_CFG_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE7_CFG_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_TILE7_MAX_ADDRESS_MASK              (0x00FFF000U)
#define CSL_KLIO_EUR_CR_BIF_TILE7_MAX_ADDRESS_SHIFT             (12U)
#define CSL_KLIO_EUR_CR_BIF_TILE7_MAX_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE7_MAX_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE7_MIN_ADDRESS_MASK              (0x00000FFFU)
#define CSL_KLIO_EUR_CR_BIF_TILE7_MIN_ADDRESS_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_TILE7_MIN_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE7_MIN_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE7_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_TILE8 */

#define CSL_KLIO_EUR_CR_BIF_TILE8_CFG_MASK                      (0x0F000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE8_CFG_SHIFT                     (24U)
#define CSL_KLIO_EUR_CR_BIF_TILE8_CFG_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE8_CFG_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_TILE8_MAX_ADDRESS_MASK              (0x00FFF000U)
#define CSL_KLIO_EUR_CR_BIF_TILE8_MAX_ADDRESS_SHIFT             (12U)
#define CSL_KLIO_EUR_CR_BIF_TILE8_MAX_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE8_MAX_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE8_MIN_ADDRESS_MASK              (0x00000FFFU)
#define CSL_KLIO_EUR_CR_BIF_TILE8_MIN_ADDRESS_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_TILE8_MIN_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE8_MIN_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE8_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_TILE9 */

#define CSL_KLIO_EUR_CR_BIF_TILE9_CFG_MASK                      (0x0F000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE9_CFG_SHIFT                     (24U)
#define CSL_KLIO_EUR_CR_BIF_TILE9_CFG_RESETVAL                  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE9_CFG_MAX                       (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_TILE9_MAX_ADDRESS_MASK              (0x00FFF000U)
#define CSL_KLIO_EUR_CR_BIF_TILE9_MAX_ADDRESS_SHIFT             (12U)
#define CSL_KLIO_EUR_CR_BIF_TILE9_MAX_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE9_MAX_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE9_MIN_ADDRESS_MASK              (0x00000FFFU)
#define CSL_KLIO_EUR_CR_BIF_TILE9_MIN_ADDRESS_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_TILE9_MIN_ADDRESS_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TILE9_MIN_ADDRESS_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TILE9_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_DIR_LIST_BASE0 */

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE0_ADDR_MASK            (0xFFFFF000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE0_ADDR_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE0_ADDR_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE0_ADDR_MAX             (0x000fffffU)

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE0_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_DIR_LIST_BASE1 */

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE1_ADDR_MASK            (0xFFFFF000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE1_ADDR_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE1_ADDR_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE1_ADDR_MAX             (0x000fffffU)

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE1_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_DIR_LIST_BASE2 */

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE2_ADDR_MASK            (0xFFFFF000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE2_ADDR_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE2_ADDR_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE2_ADDR_MAX             (0x000fffffU)

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE2_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_DIR_LIST_BASE3 */

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE3_ADDR_MASK            (0xFFFFF000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE3_ADDR_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE3_ADDR_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE3_ADDR_MAX             (0x000fffffU)

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE3_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_DIR_LIST_BASE4 */

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE4_ADDR_MASK            (0xFFFFF000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE4_ADDR_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE4_ADDR_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE4_ADDR_MAX             (0x000fffffU)

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE4_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_DIR_LIST_BASE5 */

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE5_ADDR_MASK            (0xFFFFF000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE5_ADDR_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE5_ADDR_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE5_ADDR_MAX             (0x000fffffU)

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE5_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_DIR_LIST_BASE6 */

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE6_ADDR_MASK            (0xFFFFF000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE6_ADDR_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE6_ADDR_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE6_ADDR_MAX             (0x000fffffU)

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE6_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_DIR_LIST_BASE7 */

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE7_ADDR_MASK            (0xFFFFF000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE7_ADDR_SHIFT           (12U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE7_ADDR_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE7_ADDR_MAX             (0x000fffffU)

#define CSL_KLIO_EUR_CR_BIF_DIR_LIST_BASE7_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_BANK_SET */

#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_DPM_LSS_MASK        (0x00000200U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_DPM_LSS_SHIFT       (9U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_DPM_LSS_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_DPM_LSS_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_EDM_MASK            (0x00000100U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_EDM_SHIFT           (8U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_EDM_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_EDM_MAX             (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_TA_MASK             (0x000000C0U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_TA_SHIFT            (6U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_TA_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_TA_MAX              (0x00000003U)

#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_HOST_MASK           (0x00000010U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_HOST_SHIFT          (4U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_HOST_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_HOST_MAX            (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_3D_MASK             (0x0000000CU)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_3D_SHIFT            (2U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_3D_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_3D_MAX              (0x00000003U)

#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_2D_MASK             (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_2D_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_2D_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK_SET_SELECT_2D_MAX              (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_BANK_SET_RESETVAL                   (0x00000000U)

/* EUR_CR_BIF_BANK0 */

#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_PTLA_MASK               (0x000F0000U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_PTLA_SHIFT              (16U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_PTLA_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_PTLA_MAX                (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_3D_MASK                 (0x0000F000U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_3D_SHIFT                (12U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_3D_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_3D_MAX                  (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_TA_MASK                 (0x000000F0U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_TA_SHIFT                (4U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_TA_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_TA_MAX                  (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_EDM_MASK                (0x0000000FU)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_EDM_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_EDM_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK0_INDEX_EDM_MAX                 (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_BANK0_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_BANK1 */

#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_3D_MASK                 (0x0000F000U)
#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_3D_SHIFT                (12U)
#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_3D_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_3D_MAX                  (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_TA_MASK                 (0x000000F0U)
#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_TA_SHIFT                (4U)
#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_TA_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_TA_MAX                  (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_EDM_MASK                (0x0000000FU)
#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_EDM_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_EDM_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK1_INDEX_EDM_MAX                 (0x0000000fU)

#define CSL_KLIO_EUR_CR_BIF_BANK1_RESETVAL                      (0x00000000U)

/* EUR_CR_BIF_TA_REQ_BASE */

#define CSL_KLIO_EUR_CR_BIF_TA_REQ_BASE_ADDR_MASK               (0xFFF00000U)
#define CSL_KLIO_EUR_CR_BIF_TA_REQ_BASE_ADDR_SHIFT              (20U)
#define CSL_KLIO_EUR_CR_BIF_TA_REQ_BASE_ADDR_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_TA_REQ_BASE_ADDR_MAX                (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_TA_REQ_BASE_RESETVAL                (0x00000000U)

/* EUR_CR_BIF_MEM_REQ_STAT */

#define CSL_KLIO_EUR_CR_BIF_MEM_REQ_STAT_READS_MASK             (0x000000FFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_REQ_STAT_READS_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_REQ_STAT_READS_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_REQ_STAT_READS_MAX              (0x000000ffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_REQ_STAT_RESETVAL               (0x00000000U)

/* EUR_CR_BIF_3D_REQ_BASE */

#define CSL_KLIO_EUR_CR_BIF_3D_REQ_BASE_ADDR_MASK               (0xFFF00000U)
#define CSL_KLIO_EUR_CR_BIF_3D_REQ_BASE_ADDR_SHIFT              (20U)
#define CSL_KLIO_EUR_CR_BIF_3D_REQ_BASE_ADDR_RESETVAL           (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_3D_REQ_BASE_ADDR_MAX                (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_3D_REQ_BASE_RESETVAL                (0x00000000U)

/* EUR_CR_BIF_ZLS_REQ_BASE */

#define CSL_KLIO_EUR_CR_BIF_ZLS_REQ_BASE_ADDR_MASK              (0xFFF00000U)
#define CSL_KLIO_EUR_CR_BIF_ZLS_REQ_BASE_ADDR_SHIFT             (20U)
#define CSL_KLIO_EUR_CR_BIF_ZLS_REQ_BASE_ADDR_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_ZLS_REQ_BASE_ADDR_MAX               (0x00000fffU)

#define CSL_KLIO_EUR_CR_BIF_ZLS_REQ_BASE_RESETVAL               (0x00000000U)

/* EUR_CR_BIF_BANK_STATUS */

#define CSL_KLIO_EUR_CR_BIF_BANK_STATUS_TA_CURRENT_BANK_MASK    (0x00000002U)
#define CSL_KLIO_EUR_CR_BIF_BANK_STATUS_TA_CURRENT_BANK_SHIFT   (1U)
#define CSL_KLIO_EUR_CR_BIF_BANK_STATUS_TA_CURRENT_BANK_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK_STATUS_TA_CURRENT_BANK_MAX     (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_BANK_STATUS_THREED_CURRENT_BANK_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_BANK_STATUS_THREED_CURRENT_BANK_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_BIF_BANK_STATUS_THREED_CURRENT_BANK_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_BANK_STATUS_THREED_CURRENT_BANK_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_BANK_STATUS_RESETVAL                (0x00000000U)

/* EUR_CR_BIF_SIG0 */

#define CSL_KLIO_EUR_CR_BIF_SIG0_WDATA_SIGNATURE_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_SIG0_WDATA_SIGNATURE_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_BIF_SIG0_WDATA_SIGNATURE_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_SIG0_WDATA_SIGNATURE_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_SIG0_RESETVAL                       (0x00000000U)

/* EUR_CR_BIF_SIG1 */

#define CSL_KLIO_EUR_CR_BIF_SIG1_ADDR_SIGNATURE_MASK            (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_SIG1_ADDR_SIGNATURE_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_BIF_SIG1_ADDR_SIGNATURE_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_SIG1_ADDR_SIGNATURE_MAX             (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_SIG1_RESETVAL                       (0x00000000U)

/* EUR_CR_BIF_MMU_CTRL */

#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_DISABLE_BURST_EXP_MASK     (0x00000020U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_DISABLE_BURST_EXP_SHIFT    (5U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_DISABLE_BURST_EXP_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_DISABLE_BURST_EXP_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ENABLE_DC_TLB_MASK         (0x00000010U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ENABLE_DC_TLB_SHIFT        (4U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ENABLE_DC_TLB_RESETVAL     (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ENABLE_DC_TLB_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ENABLE_WRITE_BURST_COLLATE_MASK  (0x00000008U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ENABLE_WRITE_BURST_COLLATE_SHIFT  (3U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ENABLE_WRITE_BURST_COLLATE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ENABLE_WRITE_BURST_COLLATE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ADDR_HASH_MODE_MASK        (0x00000006U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ADDR_HASH_MODE_SHIFT       (1U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ADDR_HASH_MODE_RESETVAL    (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_ADDR_HASH_MODE_MAX         (0x00000003U)

#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_PREFETCHING_ON_MASK        (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_PREFETCHING_ON_SHIFT       (0U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_PREFETCHING_ON_RESETVAL    (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_PREFETCHING_ON_MAX         (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_MMU_CTRL_RESETVAL                   (0x00000013U)

/* EUR_CR_TWOD_SIG */

#define CSL_KLIO_EUR_CR_TWOD_SIG_RESULT_MASK                    (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_TWOD_SIG_RESULT_SHIFT                   (0U)
#define CSL_KLIO_EUR_CR_TWOD_SIG_RESULT_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_SIG_RESULT_MAX                     (0xffffffffU)

#define CSL_KLIO_EUR_CR_TWOD_SIG_RESETVAL                       (0x00000000U)

/* EUR_CR_TWOD_BLIT_STATUS */

#define CSL_KLIO_EUR_CR_TWOD_BLIT_STATUS_BUSY_MASK              (0x01000000U)
#define CSL_KLIO_EUR_CR_TWOD_BLIT_STATUS_BUSY_SHIFT             (24U)
#define CSL_KLIO_EUR_CR_TWOD_BLIT_STATUS_BUSY_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_BLIT_STATUS_BUSY_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_TWOD_BLIT_STATUS_COMPLETE_MASK          (0x00FFFFFFU)
#define CSL_KLIO_EUR_CR_TWOD_BLIT_STATUS_COMPLETE_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_TWOD_BLIT_STATUS_COMPLETE_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_BLIT_STATUS_COMPLETE_MAX           (0x00ffffffU)

#define CSL_KLIO_EUR_CR_TWOD_BLIT_STATUS_RESETVAL               (0x00000000U)

/* EUR_CR_TWOD_TEST_MODE */

#define CSL_KLIO_EUR_CR_TWOD_TEST_MODE_ENABLE_MASK              (0x00000003U)
#define CSL_KLIO_EUR_CR_TWOD_TEST_MODE_ENABLE_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_TWOD_TEST_MODE_ENABLE_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_TEST_MODE_ENABLE_MAX               (0x00000003U)

#define CSL_KLIO_EUR_CR_TWOD_TEST_MODE_RESETVAL                 (0x00000000U)

/* EUR_CR_TWOD_SIG_RESULT */

#define CSL_KLIO_EUR_CR_TWOD_SIG_RESULT_CLEAR_MASK              (0x00000001U)
#define CSL_KLIO_EUR_CR_TWOD_SIG_RESULT_CLEAR_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_TWOD_SIG_RESULT_CLEAR_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_SIG_RESULT_CLEAR_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_TWOD_SIG_RESULT_RESETVAL                (0x00000000U)

/* EUR_CR_TWOD_VIRTUAL_FIFO_0 */

#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_MUL_MASK   (0x0000F000U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_MUL_SHIFT  (12U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_MUL_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_MUL_MAX    (0x0000000fU)

#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_DIV_MASK   (0x00000FF0U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_DIV_SHIFT  (4U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_DIV_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_DIV_MAX    (0x000000ffU)

#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_MASK       (0x0000000EU)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_SHIFT      (1U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_FLOWRATE_MAX        (0x00000007U)

#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_ENABLE_MASK         (0x00000001U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_ENABLE_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_ENABLE_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_ENABLE_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_0_RESETVAL            (0x00000000U)

/* EUR_CR_TWOD_VIRTUAL_FIFO_1 */

#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MIN_METRIC_MASK     (0xFF000000U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MIN_METRIC_SHIFT    (24U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MIN_METRIC_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MIN_METRIC_MAX      (0x000000ffU)

#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MAX_ACC_MASK        (0x00FFF000U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MAX_ACC_SHIFT       (12U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MAX_ACC_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MAX_ACC_MAX         (0x00000fffU)

#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MIN_ACC_MASK        (0x00000FFFU)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MIN_ACC_SHIFT       (0U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MIN_ACC_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_MIN_ACC_MAX         (0x00000fffU)

#define CSL_KLIO_EUR_CR_TWOD_VIRTUAL_FIFO_1_RESETVAL            (0x00000000U)

/* EUR_CR_AXI_CACHE */

#define CSL_KLIO_EUR_CR_AXI_CACHE_WRITE_MASK                    (0x000000F0U)
#define CSL_KLIO_EUR_CR_AXI_CACHE_WRITE_SHIFT                   (4U)
#define CSL_KLIO_EUR_CR_AXI_CACHE_WRITE_RESETVAL                (0x00000000U)
#define CSL_KLIO_EUR_CR_AXI_CACHE_WRITE_MAX                     (0x0000000fU)

#define CSL_KLIO_EUR_CR_AXI_CACHE_READ_MASK                     (0x0000000FU)
#define CSL_KLIO_EUR_CR_AXI_CACHE_READ_SHIFT                    (0U)
#define CSL_KLIO_EUR_CR_AXI_CACHE_READ_RESETVAL                 (0x00000000U)
#define CSL_KLIO_EUR_CR_AXI_CACHE_READ_MAX                      (0x0000000fU)

#define CSL_KLIO_EUR_CR_AXI_CACHE_RESETVAL                      (0x00000000U)

/* EUR_CR_AXI_EXACCESS */

#define CSL_KLIO_EUR_CR_AXI_EXACCESS_ENABLE_MASK                (0x00000001U)
#define CSL_KLIO_EUR_CR_AXI_EXACCESS_ENABLE_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_AXI_EXACCESS_ENABLE_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_AXI_EXACCESS_ENABLE_MAX                 (0x00000001U)

#define CSL_KLIO_EUR_CR_AXI_EXACCESS_RESETVAL                   (0x00000000U)

/* EUR_CR_EMU_CYCLE_COUNT */

#define CSL_KLIO_EUR_CR_EMU_CYCLE_COUNT_RESET_MASK              (0x00000001U)
#define CSL_KLIO_EUR_CR_EMU_CYCLE_COUNT_RESET_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_EMU_CYCLE_COUNT_RESET_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_CYCLE_COUNT_RESET_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_EMU_CYCLE_COUNT_RESETVAL                (0x00000000U)

/* EUR_CR_EMU_TA_PHASE */

#define CSL_KLIO_EUR_CR_EMU_TA_PHASE_COUNT_MASK                 (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_TA_PHASE_COUNT_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_EMU_TA_PHASE_COUNT_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_TA_PHASE_COUNT_MAX                  (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_TA_PHASE_RESETVAL                   (0x00000000U)

/* EUR_CR_EMU_3D_PHASE */

#define CSL_KLIO_EUR_CR_EMU_3D_PHASE_COUNT_MASK                 (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_3D_PHASE_COUNT_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_EMU_3D_PHASE_COUNT_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_3D_PHASE_COUNT_MAX                  (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_3D_PHASE_RESETVAL                   (0x00000000U)

/* EUR_CR_EMU_TA_CYCLE */

#define CSL_KLIO_EUR_CR_EMU_TA_CYCLE_COUNT_MASK                 (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_TA_CYCLE_COUNT_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_EMU_TA_CYCLE_COUNT_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_TA_CYCLE_COUNT_MAX                  (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_TA_CYCLE_RESETVAL                   (0x00000000U)

/* EUR_CR_EMU_3D_CYCLE */

#define CSL_KLIO_EUR_CR_EMU_3D_CYCLE_COUNT_MASK                 (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_3D_CYCLE_COUNT_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_EMU_3D_CYCLE_COUNT_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_3D_CYCLE_COUNT_MAX                  (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_3D_CYCLE_RESETVAL                   (0x00000000U)

/* EUR_CR_EMU_INITIAL_TA_CYCLE */

#define CSL_KLIO_EUR_CR_EMU_INITIAL_TA_CYCLE_COUNT_MASK         (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_INITIAL_TA_CYCLE_COUNT_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_EMU_INITIAL_TA_CYCLE_COUNT_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_INITIAL_TA_CYCLE_COUNT_MAX          (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_INITIAL_TA_CYCLE_RESETVAL           (0x00000000U)

/* EUR_CR_EMU_FINAL_3D_CYCLE */

#define CSL_KLIO_EUR_CR_EMU_FINAL_3D_CYCLE_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_FINAL_3D_CYCLE_COUNT_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_EMU_FINAL_3D_CYCLE_COUNT_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_FINAL_3D_CYCLE_COUNT_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_FINAL_3D_CYCLE_RESETVAL             (0x00000000U)

/* EUR_CR_EMU_MEM_READ */

#define CSL_KLIO_EUR_CR_EMU_MEM_READ_COUNT_MASK                 (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_MEM_READ_COUNT_SHIFT                (0U)
#define CSL_KLIO_EUR_CR_EMU_MEM_READ_COUNT_RESETVAL             (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_MEM_READ_COUNT_MAX                  (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_MEM_READ_RESETVAL                   (0x00000000U)

/* EUR_CR_EMU_TA_OR_3D_CYCLE */

#define CSL_KLIO_EUR_CR_EMU_TA_OR_3D_CYCLE_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_TA_OR_3D_CYCLE_COUNT_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_EMU_TA_OR_3D_CYCLE_COUNT_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_TA_OR_3D_CYCLE_COUNT_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_TA_OR_3D_CYCLE_RESETVAL             (0x00000000U)

/* EUR_CR_EMU_MEM_WRITE */

#define CSL_KLIO_EUR_CR_EMU_MEM_WRITE_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_MEM_WRITE_COUNT_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_EMU_MEM_WRITE_COUNT_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_MEM_WRITE_COUNT_MAX                 (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_MEM_WRITE_RESETVAL                  (0x00000000U)

/* EUR_CR_EMU_MEM_BYTE_WRITE */

#define CSL_KLIO_EUR_CR_EMU_MEM_BYTE_WRITE_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_MEM_BYTE_WRITE_COUNT_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_EMU_MEM_BYTE_WRITE_COUNT_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_MEM_BYTE_WRITE_COUNT_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_MEM_BYTE_WRITE_RESETVAL             (0x00000000U)

/* EUR_CR_EMU_MEM_STALL */

#define CSL_KLIO_EUR_CR_EMU_MEM_STALL_COUNT_MASK                (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_EMU_MEM_STALL_COUNT_SHIFT               (0U)
#define CSL_KLIO_EUR_CR_EMU_MEM_STALL_COUNT_RESETVAL            (0x00000000U)
#define CSL_KLIO_EUR_CR_EMU_MEM_STALL_COUNT_MAX                 (0xffffffffU)

#define CSL_KLIO_EUR_CR_EMU_MEM_STALL_RESETVAL                  (0x00000000U)

/* EUR_CR_BIF_CYCLE_COUNT */

#define CSL_KLIO_EUR_CR_BIF_CYCLE_COUNT_RESET_MASK              (0x00000001U)
#define CSL_KLIO_EUR_CR_BIF_CYCLE_COUNT_RESET_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_CYCLE_COUNT_RESET_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_CYCLE_COUNT_RESET_MAX               (0x00000001U)

#define CSL_KLIO_EUR_CR_BIF_CYCLE_COUNT_RESETVAL                (0x00000000U)

/* EUR_CR_BIF_MEM_READ_MMU */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_MMU_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_MMU_COUNT_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_MMU_COUNT_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_MMU_COUNT_MAX              (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_MMU_RESETVAL               (0x00000000U)

/* EUR_CR_BIF_MEM_READ_CACHE */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_CACHE_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_CACHE_COUNT_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_CACHE_COUNT_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_CACHE_COUNT_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_CACHE_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_MEM_READ_TA */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TA_COUNT_MASK              (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TA_COUNT_SHIFT             (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TA_COUNT_RESETVAL          (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TA_COUNT_MAX               (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TA_RESETVAL                (0x00000000U)

/* EUR_CR_BIF_MEM_WRITE_TA */

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_TA_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_TA_COUNT_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_TA_COUNT_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_TA_COUNT_MAX              (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_TA_RESETVAL               (0x00000000U)

/* EUR_CR_BIF_MEM_READ_VDM */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_VDM_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_VDM_COUNT_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_VDM_COUNT_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_VDM_COUNT_MAX              (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_VDM_RESETVAL               (0x00000000U)

/* EUR_CR_BIF_MEM_READ_PBE */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PBE_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PBE_COUNT_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PBE_COUNT_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PBE_COUNT_MAX              (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PBE_RESETVAL               (0x00000000U)

/* EUR_CR_BIF_MEM_WRITE_PBE */

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_PBE_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_PBE_COUNT_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_PBE_COUNT_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_PBE_COUNT_MAX             (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_PBE_RESETVAL              (0x00000000U)

/* EUR_CR_BIF_MEM_READ_TSP */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TSP_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TSP_COUNT_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TSP_COUNT_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TSP_COUNT_MAX              (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_TSP_RESETVAL               (0x00000000U)

/* EUR_CR_BIF_MEM_READ_ISP */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISP_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISP_COUNT_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISP_COUNT_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISP_COUNT_MAX              (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISP_RESETVAL               (0x00000000U)

/* EUR_CR_BIF_MEM_READ_ISPZ */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISPZ_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISPZ_COUNT_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISPZ_COUNT_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISPZ_COUNT_MAX             (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_ISPZ_RESETVAL              (0x00000000U)

/* EUR_CR_BIF_MEM_WRITE_ISPZ */

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_ISPZ_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_ISPZ_COUNT_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_ISPZ_COUNT_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_ISPZ_COUNT_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_ISPZ_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_MEM_READ_USE0 */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE0_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE0_COUNT_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE0_COUNT_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE0_COUNT_MAX             (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE0_RESETVAL              (0x00000000U)

/* EUR_CR_BIF_MEM_WRITE_USE0 */

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE0_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE0_COUNT_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE0_COUNT_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE0_COUNT_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE0_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_MEM_READ_USE1 */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE1_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE1_COUNT_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE1_COUNT_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE1_COUNT_MAX             (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE1_RESETVAL              (0x00000000U)

/* EUR_CR_BIF_MEM_WRITE_USE1 */

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE1_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE1_COUNT_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE1_COUNT_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE1_COUNT_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE1_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_MEM_READ_USEC */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USEC_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USEC_COUNT_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USEC_COUNT_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USEC_COUNT_MAX             (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USEC_RESETVAL              (0x00000000U)

/* EUR_CR_BIF_MEM_READ_PDS */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PDS_COUNT_MASK             (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PDS_COUNT_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PDS_COUNT_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PDS_COUNT_MAX              (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_PDS_RESETVAL               (0x00000000U)

/* EUR_CR_BIF_MEM_READ_USE2 */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE2_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE2_COUNT_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE2_COUNT_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE2_COUNT_MAX             (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE2_RESETVAL              (0x00000000U)

/* EUR_CR_BIF_MEM_WRITE_USE2 */

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE2_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE2_COUNT_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE2_COUNT_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE2_COUNT_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE2_RESETVAL             (0x00000000U)

/* EUR_CR_BIF_MEM_READ_USE3 */

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE3_COUNT_MASK            (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE3_COUNT_SHIFT           (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE3_COUNT_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE3_COUNT_MAX             (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_READ_USE3_RESETVAL              (0x00000000U)

/* EUR_CR_BIF_MEM_WRITE_USE3 */

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE3_COUNT_MASK           (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE3_COUNT_SHIFT          (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE3_COUNT_RESETVAL       (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE3_COUNT_MAX            (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_WRITE_USE3_RESETVAL             (0x00000000U)

/* EUR_CR_USEC_BIF_CYCLE_COUNT */

#define CSL_KLIO_EUR_CR_USEC_BIF_CYCLE_COUNT_RESET_MASK         (0x00000001U)
#define CSL_KLIO_EUR_CR_USEC_BIF_CYCLE_COUNT_RESET_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_USEC_BIF_CYCLE_COUNT_RESET_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_USEC_BIF_CYCLE_COUNT_RESET_MAX          (0x00000001U)

#define CSL_KLIO_EUR_CR_USEC_BIF_CYCLE_COUNT_RESETVAL           (0x00000000U)

/* EUR_CR_USEC_BIF_VERTEX_READ */

#define CSL_KLIO_EUR_CR_USEC_BIF_VERTEX_READ_COUNT_MASK         (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_USEC_BIF_VERTEX_READ_COUNT_SHIFT        (0U)
#define CSL_KLIO_EUR_CR_USEC_BIF_VERTEX_READ_COUNT_RESETVAL     (0x00000000U)
#define CSL_KLIO_EUR_CR_USEC_BIF_VERTEX_READ_COUNT_MAX          (0xffffffffU)

#define CSL_KLIO_EUR_CR_USEC_BIF_VERTEX_READ_RESETVAL           (0x00000000U)

/* EUR_CR_USEC_BIF_PIXEL_READ */

#define CSL_KLIO_EUR_CR_USEC_BIF_PIXEL_READ_COUNT_MASK          (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_USEC_BIF_PIXEL_READ_COUNT_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_USEC_BIF_PIXEL_READ_COUNT_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_USEC_BIF_PIXEL_READ_COUNT_MAX           (0xffffffffU)

#define CSL_KLIO_EUR_CR_USEC_BIF_PIXEL_READ_RESETVAL            (0x00000000U)

/* EUR_CR_USEC_BIF_EVENT_READ */

#define CSL_KLIO_EUR_CR_USEC_BIF_EVENT_READ_COUNT_MASK          (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_USEC_BIF_EVENT_READ_COUNT_SHIFT         (0U)
#define CSL_KLIO_EUR_CR_USEC_BIF_EVENT_READ_COUNT_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_USEC_BIF_EVENT_READ_COUNT_MAX           (0xffffffffU)

#define CSL_KLIO_EUR_CR_USEC_BIF_EVENT_READ_RESETVAL            (0x00000000U)

/* EUR_CR_BIF_MEM_THREE_D_COUNT */

#define CSL_KLIO_EUR_CR_BIF_MEM_THREE_D_COUNT_COUNT_MASK        (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_THREE_D_COUNT_COUNT_SHIFT       (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_THREE_D_COUNT_COUNT_RESETVAL    (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_THREE_D_COUNT_COUNT_MAX         (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_THREE_D_COUNT_RESETVAL          (0x00000000U)

/* EUR_CR_BIF_MEM_OVER_LAPPED_TA_READ_COUNT */

#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_READ_COUNT_COUNT_MASK  (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_READ_COUNT_COUNT_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_READ_COUNT_COUNT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_READ_COUNT_COUNT_MAX  (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_READ_COUNT_RESETVAL  (0x00000000U)

/* EUR_CR_BIF_MEM_OVER_LAPPED_TA_WRITE_COUNT */

#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_WRITE_COUNT_COUNT_MASK  (0xFFFFFFFFU)
#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_WRITE_COUNT_COUNT_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_WRITE_COUNT_COUNT_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_WRITE_COUNT_COUNT_MAX  (0xffffffffU)

#define CSL_KLIO_EUR_CR_BIF_MEM_OVER_LAPPED_TA_WRITE_COUNT_RESETVAL  (0x00000000U)

/* EUR_CR_PARTITION_BREAKPOINT_TRAP */

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_CONTINUE_MASK  (0x00000002U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_CONTINUE_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_CONTINUE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_CONTINUE_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_WRNOTIFY_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_WRNOTIFY_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_WRNOTIFY_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_WRNOTIFY_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_RESETVAL      (0x00000000U)

/* EUR_CR_PARTITION_BREAKPOINT */

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_MODULE_ID_MASK     (0x000003C0U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_MODULE_ID_SHIFT    (6U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_MODULE_ID_RESETVAL  (0x0000000aU)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_MODULE_ID_MAX      (0x0000000fU)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_ID_MASK            (0x00000030U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_ID_SHIFT           (4U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_ID_RESETVAL        (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_ID_MAX             (0x00000003U)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_UNTRAPPED_MASK     (0x00000008U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_UNTRAPPED_SHIFT    (3U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_UNTRAPPED_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_UNTRAPPED_MAX      (0x00000001U)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAPPED_MASK       (0x00000004U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAPPED_SHIFT      (2U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAPPED_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAPPED_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_RESETVAL           (0x00000280U)

/* EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO0 */

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO0_ADDRESS_MASK  (0xFFFFFFF0U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO0_ADDRESS_SHIFT  (4U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO0_ADDRESS_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO0_ADDRESS_MAX  (0x0fffffffU)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO0_RESETVAL  (0x00000000U)

/* EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1 */

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_SIZE_MASK  (0x00007C00U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_SIZE_SHIFT  (10U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_SIZE_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_SIZE_MAX  (0x0000001fU)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_NUMBER_MASK  (0x00000300U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_NUMBER_SHIFT  (8U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_NUMBER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_NUMBER_MAX  (0x00000003U)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_TAG_MASK  (0x000000F8U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_TAG_SHIFT  (3U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_TAG_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_TAG_MAX  (0x0000001fU)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_DATA_MASTER_MASK  (0x00000006U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_DATA_MASTER_SHIFT  (1U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_DATA_MASTER_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_DATA_MASTER_MAX  (0x00000003U)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_RNW_MASK  (0x00000001U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_RNW_SHIFT  (0U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_RNW_RESETVAL  (0x00000000U)
#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_RNW_MAX  (0x00000001U)

#define CSL_KLIO_EUR_CR_PARTITION_BREAKPOINT_TRAP_INFO1_RESETVAL  (0x00000000U)

/* EUR_CR_SIM_3D_FRAME_COUNT */

#define CSL_KLIO_EUR_CR_SIM_3D_FRAME_COUNT_RESETVAL             (0x00000000U)

/* EUR_CR_SIM_TA_FRAME_COUNT */

#define CSL_KLIO_EUR_CR_SIM_TA_FRAME_COUNT_RESETVAL             (0x00000000U)

/* EUR_CR_SIM_USE_STATS */

#define CSL_KLIO_EUR_CR_SIM_USE_STATS_USE_PIPE_MASK             (0xF0000000U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_USE_PIPE_SHIFT            (28U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_USE_PIPE_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_USE_PIPE_MAX              (0x0000000fU)

#define CSL_KLIO_EUR_CR_SIM_USE_STATS_PER_RENDER_BIT_MASK       (0x04000000U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_PER_RENDER_BIT_SHIFT      (26U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_PER_RENDER_BIT_RESETVAL   (0x00000000U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_PER_RENDER_BIT_MAX        (0x00000001U)

#define CSL_KLIO_EUR_CR_SIM_USE_STATS_DATA_MASTER_MASK          (0x03000000U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_DATA_MASTER_SHIFT         (24U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_DATA_MASTER_RESETVAL      (0x00000000U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_DATA_MASTER_MAX           (0x00000003U)

#define CSL_KLIO_EUR_CR_SIM_USE_STATS_YTILEPOS_MASK             (0x00FFF000U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_YTILEPOS_SHIFT            (12U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_YTILEPOS_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_YTILEPOS_MAX              (0x00000fffU)

#define CSL_KLIO_EUR_CR_SIM_USE_STATS_XTILEPOS_MASK             (0x00000FFFU)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_XTILEPOS_SHIFT            (0U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_XTILEPOS_RESETVAL         (0x00000000U)
#define CSL_KLIO_EUR_CR_SIM_USE_STATS_XTILEPOS_MAX              (0x00000fffU)

#define CSL_KLIO_EUR_CR_SIM_USE_STATS_RESETVAL                  (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
