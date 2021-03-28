/**
 * @file   nimu_pa_iface.c
 *
 * @brief   This file implements the common configuration of the QMSS and CPPI drivers
 */
/*
 * Copyright (c) 2015-2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#include <ti/transport/ndk/nimu/example/client/src/nimu_cppi_qmss_iface.h>

/* PASS RL file */
#include <ti/csl/cslr_pa_ss.h>

/* Firmware images */
#ifdef NSS_GEN2
#include "ti/drv/pa/fw/v1/pa2_eg0_pdsp0_bin.c"
#include "ti/drv/pa/fw/v1/pa2_eg0_pdsp1_bin.c"
#include "ti/drv/pa/fw/v1/pa2_eg0_pdsp2_bin.c"
#include "ti/drv/pa/fw/v1/pa2_eg1_pdsp0_bin.c"
#include "ti/drv/pa/fw/v1/pa2_eg2_pdsp0_bin.c"
#include "ti/drv/pa/fw/v1/pa2_in0_pdsp0_bin.c"
#include "ti/drv/pa/fw/v1/pa2_in0_pdsp1_bin.c"
#include "ti/drv/pa/fw/v1/pa2_in1_pdsp0_bin.c"
#include "ti/drv/pa/fw/v1/pa2_in1_pdsp1_bin.c"
#include "ti/drv/pa/fw/v1/pa2_in2_pdsp0_bin.c"
#include "ti/drv/pa/fw/v1/pa2_in3_pdsp0_bin.c"
#include "ti/drv/pa/fw/v1/pa2_in4_pdsp0_bin.c"
#include "ti/drv/pa/fw/v1/pa2_in4_pdsp1_bin.c"
#include "ti/drv/pa/fw/v1/pa2_post_pdsp0_bin.c"
#include "ti/drv/pa/fw/v1/pa2_post_pdsp1_bin.c"
#else
#if defined(DEVICE_K2H) || defined(DEVICE_K2K) || defined(DEVICE_K2L) || defined(DEVICE_K2E) || defined(DEVICE_C6678)
#include "ti/drv/pa/fw/v0/classify1_0_bin.c"
#include "ti/drv/pa/fw/v0/classify1_1_bin.c"
#include "ti/drv/pa/fw/v0/classify1_2_bin.c"
#include "ti/drv/pa/fw/v0/classify2_bin.c"
#include "ti/drv/pa/fw/v0/pam_bin.c"
#else
#include <ti/drv/pa/fw/classify1_bin.c>
#include <ti/drv/pa/fw/classify2_bin.c>
#include <ti/drv/pa/fw/pam_bin.c>
#endif
#endif
/* PA definitions */
#define     MAX_NUM_L2_HANDLES          10
#define     MAX_NUM_L3_HANDLES          20
#define     MAX_NUM_L4_HANDLES          40

#define     BUFSIZE_PA_INST             512
#define     BUFSIZE_L2_TABLE            1000
#define     BUFSIZE_L3_TABLE            4000

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
/* PA Driver Handle */
#pragma DATA_SECTION(gPAInstHnd, ".resmgr_handles");
Pa_Handle       gPAInstHnd;


#ifdef _TMS320C6X
#pragma DATA_SECTION(gPAInst, ".resmgr_pa");
#pragma DATA_ALIGN(gPAInst, 8)
uint8_t         gPAInst[BUFSIZE_PA_INST];

/* Memory used for PA handles */
#pragma DATA_ALIGN(gMemL2Ram, 8)
uint8_t     gMemL2Ram[BUFSIZE_L2_TABLE];

#pragma DATA_ALIGN(gMemL3Ram, CACHE_LINESZ)
uint8_t     gMemL3Ram[BUFSIZE_L3_TABLE];
#else
uint8_t gPAInst[SYS_ROUND_UP(BUFSIZE_PA_INST, CACHE_LINESZ)] __attribute__ ((aligned (CACHE_LINESZ)));
uint8_t gMemL2Ram[SYS_ROUND_UP(BUFSIZE_L2_TABLE, CACHE_LINESZ)] __attribute__ ((aligned (CACHE_LINESZ)));
uint8_t gMemL3Ram[SYS_ROUND_UP(BUFSIZE_L3_TABLE, CACHE_LINESZ)] __attribute__ ((aligned (CACHE_LINESZ)));
#endif













/**********************************************************************
 ************ Resource Manager PA configuration Functions ************
 **********************************************************************/
/** ============================================================================
 *   @n@b Download_PAFirmware
 *
 *   @b Description
 *   @n This API downloads the PA firmware required for PDSP operation.
 *
 *   @param[in]
 *   @n None
 *
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
static int32_t Download_PAFirmware (Void)
{
    extern Pa_Handle       gPAInstHnd;
#ifndef NSS_GEN2
    /* Hold the PA in reset state during download */
    Pa_resetControl (gPAInstHnd, pa_STATE_RESET);

#if defined(DEVICE_K2H) || defined(DEVICE_K2K) || defined(DEVICE_K2L) || defined(DEVICE_K2E) || defined(DEVICE_C6678)
    /* PDPSs 0-2 use image c1_x */
    Pa_downloadImage (gPAInstHnd, 0, (Ptr)c1_0, sizeof(c1_0));
    Pa_downloadImage (gPAInstHnd, 1, (Ptr)c1_1, sizeof(c1_1));
    Pa_downloadImage (gPAInstHnd, 2, (Ptr)c1_2, sizeof(c1_2));
#else
    /* PDPSs 0-2 use image c1 */
    Pa_downloadImage (gPAInstHnd, 0, (Ptr)c1, sizeof(c1));
    Pa_downloadImage (gPAInstHnd, 1, (Ptr)c1, sizeof(c1));
    Pa_downloadImage (gPAInstHnd, 2, (Ptr)c1, sizeof(c1));
#endif

    /* PDSP 3 uses image c2 */
    Pa_downloadImage (gPAInstHnd, 3, (Ptr)c2, sizeof(c2));

    /* PDSPs 4-5 use image m */
    Pa_downloadImage (gPAInstHnd, 4, (Ptr)m, sizeof(m));
    Pa_downloadImage (gPAInstHnd, 5, (Ptr)m, sizeof(m));
#else
    Pa_resetControl (gPAInstHnd, pa_STATE_RESET);

    Pa_downloadImage (gPAInstHnd, 0, (Ptr)in0_pdsp0, in0_pdsp0Size);
    Pa_downloadImage (gPAInstHnd, 1, (Ptr)in0_pdsp1, in0_pdsp1Size);
    Pa_downloadImage (gPAInstHnd, 2, (Ptr)in1_pdsp0, in1_pdsp0Size);
    Pa_downloadImage (gPAInstHnd, 3, (Ptr)in1_pdsp1, in1_pdsp1Size);
    Pa_downloadImage (gPAInstHnd, 4, (Ptr)in2_pdsp0, in2_pdsp0Size);
    Pa_downloadImage (gPAInstHnd, 5, (Ptr)in3_pdsp0, in3_pdsp0Size);
    Pa_downloadImage (gPAInstHnd, 6, (Ptr)in4_pdsp0, in4_pdsp0Size);
    Pa_downloadImage (gPAInstHnd, 7, (Ptr)in4_pdsp1, in4_pdsp1Size);
    Pa_downloadImage (gPAInstHnd, 8, (Ptr)post_pdsp0, post_pdsp0Size);
    Pa_downloadImage (gPAInstHnd, 9, (Ptr)post_pdsp1, post_pdsp1Size);
    Pa_downloadImage (gPAInstHnd, 10, (Ptr)eg0_pdsp0, eg0_pdsp0Size);
    Pa_downloadImage (gPAInstHnd, 11, (Ptr)eg0_pdsp1, eg0_pdsp1Size);
    Pa_downloadImage (gPAInstHnd, 12, (Ptr)eg0_pdsp2, eg0_pdsp2Size);
    Pa_downloadImage (gPAInstHnd, 13, (Ptr)eg1_pdsp0, eg1_pdsp0Size);
    Pa_downloadImage (gPAInstHnd, 14, (Ptr)eg2_pdsp0, eg2_pdsp0Size);
#endif

    /* Enable the PA back */
    Pa_resetControl (gPAInstHnd, pa_STATE_ENABLE);

    return 0;
}

/** ============================================================================
 *   @n@b Get_PAInstance
 *
 *   @b Description
 *   @n This API returns the handle to the PA.
 *
 *   @param[in]  None
 *
 *   @return  Pa_Handle
 * =============================================================================
 */
Pa_Handle
NIMU_getPAInstance (void) {
    return gPAInstHnd;
}

/* ============================================================================
 *   @n@b Nimu_testInitPASS
 *
 *   @b Description
 *   @n This API initializes the PASS/PDSP.
 *
 *   @param[in]
 *   @n None
 *
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */

int32_t 
Nimu_testInitPASS 
(
    void
)
{
    paSizeInfo_t                paSize = {0};
    paConfig_t                  paCfg = {0};
    int32_t                     retVal;
    int32_t                     sizes[pa_N_BUFS];
    int32_t                     aligns[pa_N_BUFS];
    void*                       bases[pa_N_BUFS];
    
    /* Allocate space for the PA LLD buffers. The buffers we need to
    * allocate space are:
    *      (1) PA LLD Instance Info Handle
    *      (2) PA LLD L2 Handle database
    *      (3) PA LLD L3 Handle database
    */
    paSize.nMaxL2 = MAX_NUM_L2_HANDLES;
    paSize.nMaxL3 = MAX_NUM_L3_HANDLES;
    if ((retVal = Pa_getBufferReq(&paSize, sizes, aligns)) != pa_OK)
    {
        NIMU_testLog ("Pa_getBufferReq returned error %d\n", retVal);
        return -1;
    }
    
    /* Validate the buffer allocations */
    /* The first buffer is always the instance buffer */
    if ((uint32_t)gPAInst & (aligns[0] - 1))
    {
        NIMU_testLog("Pa_getBufferReq requires %d alignment for instance buffer, but address is 0x%08x\n", aligns[0], (uint32_t)gPAInst);
        return -1;
    }
    
    if (sizeof(gPAInst) < sizes[0])
    {
        NIMU_testLog ("Pa_getBufferReq requires %d bytes for instance buffer, have only %d\n", sizes[0], sizeof(gPAInst));
        return -1;
    }
    
    bases[0]    =   (Void *)gPAInst;
    
    /* The second buffer is the L2 table */
    if ((uint32_t)gMemL2Ram & (aligns[1] - 1))
    {
        NIMU_testLog ("Pa_getBufferReq requires %d alignment for buffer 1, but address is 0x%08x\n", aligns[1], (uint32_t)gMemL2Ram);
        return (-1);
    }
    
    if (sizeof(gMemL2Ram) < sizes[1])
    {
        NIMU_testLog ("Pa_getBufferReq requires %d bytes for buffer 1, have only %d\n", sizes[1], sizeof(gMemL2Ram));
        return -1;
    }
    
    bases[1]    =   (Void *)gMemL2Ram;
    
    /* The third buffer is the L3 table */
    if ((uint32_t)gMemL3Ram & (aligns[2] - 1))
    {
        NIMU_testLog ("Pa_alloc requires %d alignment for buffer 1, but address is 0x%08x\n", aligns[2], (uint32_t)gMemL3Ram);
        return (-1);
    }
    
    if (sizeof(gMemL3Ram) < sizes[2])
    {
        NIMU_testLog ("Pa_alloc requires %d bytes for buffer 1, have only %d\n", sizes[2], sizeof(gMemL3Ram));
        return (-1);
    }
    
    bases[2]    =   (Void *)gMemL3Ram;
    
    /* Finally initialize the PA LLD */
    paCfg.initTable =   TRUE;
    paCfg.initDefaultRoute = TRUE;
#if defined(DEVICE_K2H) || defined(DEVICE_K2K) || defined(DEVICE_K2L) || defined(DEVICE_K2E)
    paCfg.baseAddr = CSL_NETCP_CFG_REGS;
#else
    paCfg.baseAddr = CSL_PA_SS_CFG_REGS;
#endif

#if RM
    paCfg.rmServiceHandle = rmServiceHandle;
#endif /* RM */


    paCfg.sizeCfg   =   &paSize;
    if ((retVal = Pa_create (&paCfg, bases, &gPAInstHnd)) != pa_OK)
    {
        NIMU_testLog ("Pa_create returned with error code %d\n", retVal);
        return -1;
    }
    
    /* Download the PASS PDSP firmware */
    if (Download_PAFirmware ())
    {
        return -1;
    }
    
    
    /* PA Init Done. Return success */
    return 0;
}


