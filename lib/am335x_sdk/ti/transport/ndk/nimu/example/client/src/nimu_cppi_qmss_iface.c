/**
 * @file   nimu_cppi_qmss_iface.c
 *
 * @brief This file implements the common configuration of the QMSS and CPPI drivers for
 *      the application to use.
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

#include <ti/csl/cslr_pa_ss.h>

#include <ti/drv/qmss/qmss_firmware.h>
/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
/* Host Descriptor Region - [Size of descriptor * Number of descriptors]
 *
 * MUST be cache line byte aligned.
 */


#ifdef _TMS320C6X
#pragma DATA_SECTION(gHostDesc, ".resmgr_memregion");
#pragma DATA_ALIGN (gHostDesc, 128)
uint8_t     gHostDesc[MAX_DESC_SIZE * MAX_NUM_DESC];
#else
uint8_t      gHostDesc[MAX_DESC_SIZE * MAX_NUM_DESC] __attribute__ ((aligned (128)));
#endif



/* This is the global free queue for QMSS. It holds all free descriptors which can be used */
#pragma DATA_SECTION(gGlobalFreeQHnd, ".resmgr_handles");
Qmss_QueueHnd   gGlobalFreeQHnd;

/* Channels handles for CPPI DMA support of the Packet Accelerator (PA) */
#pragma DATA_SECTION(gPassCpdmaTxChanHnd, ".resmgr_handles");
#pragma DATA_SECTION(gPassCpdmaRxChanHnd, ".resmgr_handles");
#pragma DATA_SECTION(gPassCpdmaHnd, 	  ".resmgr_handles");
Cppi_ChHnd      gPassCpdmaTxChanHnd [NUM_PA_TX_QUEUES];
Cppi_ChHnd      gPassCpdmaRxChanHnd [NUM_PA_RX_CHANNELS];
Cppi_Handle     gPassCpdmaHnd;


/* Global debug counters */
#pragma DATA_SECTION(gQPopErrorCounter, ".resmgr_handles");
uint32_t gQPopErrorCounter;
#pragma DATA_SECTION(gQPushErrorCounter, ".resmgr_handles")
uint32_t gQPushErrorCounter;

/* Configuration Information */
NIMU_CPPI_CFG_T          gCppiCfg[NIMU_MAX_CPPI_CFG];



/*
 * The device specific configuration and initialization routines
 * for QMSS Low Level Driver. If the user wants to change the
 * default configurations, the below file needs to be modified.
 */
#if defined(DEVICE_K2H)
#include "ti/drv/qmss/device/k2h/src/qmss_device.c"
#elif defined(DEVICE_K2K)
#include "ti/drv/qmss/device/k2k/src/qmss_device.c"
#elif defined(DEVICE_K2L)
#include "ti/drv/qmss/device/k2l/src/qmss_device.c"
#elif defined(DEVICE_K2E)
#include "ti/drv/qmss/device/k2e/src/qmss_device.c"
#elif defined(DEVICE_C6678)
#include "ti/drv/qmss/device/c6678/src/qmss_device.c"
#else
#include "ti/drv/qmss/device/qmss_device.c"
#endif

/*
 * The device specific configuration and initialization routines
 * for CPPI Low Level Driver. If the user wants to change the
 * default configurations, the below file needs to be modified.
 */
#if defined(DEVICE_K2H)
#include "ti/drv/cppi/device/k2h/src/cppi_device.c"
#elif defined(DEVICE_K2K)
#include "ti/drv/cppi/device/k2k/src/cppi_device.c"
#elif defined(DEVICE_K2L)
#include "ti/drv/cppi/device/k2l/src/cppi_device.c"
#elif defined(DEVICE_K2E)
#include "ti/drv/cppi/device/k2e/src/cppi_device.c"
#elif defined(DEVICE_C6678)
#include "ti/drv/cppi/device/c6678/src/cppi_device.c"
#else
#include "ti/drv/cppi/device/cppi_device.c"
#endif

/**********************************************************************
 ************ Resource Manager QMSS configuration Functions ************
 **********************************************************************/

/** ============================================================================
 *   @n@b res_mgr_qmss_freeq
 *
 *   @b Description
 *   @n This API returns the handle to the global free queue for QMSS. The global free
 *   queue maintains all usable descriptors for anyone using QMSS.
 *
 *   @param[in]  None
 *
 *   @return
 * =============================================================================
 */
Qmss_QueueHnd
NIMU_qmssGetFreeQ (void)
{
    return gGlobalFreeQHnd;
}

/** ============================================================================
 *   @n@b NIMU_convertCoreLocal2GlobalAddr
 *
 *   @b Description
 *   @n This API converts a core local L2 address to a global L2 address.
 *
 *   @param[in]
 *   @n addr            L2 address to be converted to global.
 *
 *   @return    uint32_t
 *   @n >0              Global L2 address
 * =============================================================================
 */
uint32_t NIMU_convertCoreLocal2GlobalAddr (uint32_t  addr)
{
    /* Get the core number. */
#ifdef _TMS320C6X
    uint32_t coreNum = CSL_chipReadReg (CSL_CHIP_DNUM);
#else
    uint32_t coreNum = 0;
#endif
    /* Check if the address is a valid Local L2 address to convert */

    if ( (addr >= (uint32_t) 0x800000) &&
         (addr <  (uint32_t) 0x900000) )
    {
         /* Compute the global address. */
         return ((1 << 28) | (coreNum << 24) | (addr & 0x00ffffff));
    }
    else
    {
        return (addr);
    }
}


/** ============================================================================
 *   @n@b NIMU_initQmss
 *
 *   @b Description
 *   @n This API initializes the QMSS LLD.
 *
 *   @param[in]  p_qmss_cfg
 *        Pointer to NIMU_QMSS_CFG_T
 *
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t 
NIMU_initQmss 
(
    NIMU_QMSS_CFG_T      *p_qmss_cfg
)
{
    int32_t                     result;
    Qmss_MemRegInfo             memCfg;
    Qmss_InitCfg                qmssInitConfig;
    Cppi_DescCfg                cppiDescCfg;
    uint32_t                    numAllocated;

    if (p_qmss_cfg->master_core)
    {
        /* Initialize QMSS */
        memset (&qmssInitConfig, 0, sizeof (Qmss_InitCfg));
        
        /* Set up QMSS configuration */
        
        /* Use internal linking RAM */
        qmssInitConfig.linkingRAM0Base  =   0;
        qmssInitConfig.linkingRAM0Size  =   0;
        qmssInitConfig.linkingRAM1Base  =   0x0;
        qmssInitConfig.maxDescNum       =   p_qmss_cfg->max_num_desc;
        
        qmssInitConfig.pdspFirmware[0].pdspId = Qmss_PdspId_PDSP1;
#ifdef _LITTLE_ENDIAN
        qmssInitConfig.pdspFirmware[0].firmware = (void *) &acc48_le;
        qmssInitConfig.pdspFirmware[0].size = sizeof (acc48_le);
#else
        qmssInitConfig.pdspFirmware[0].firmware = (void *) &acc48_be;
        qmssInitConfig.pdspFirmware[0].size = sizeof (acc48_be);
#endif

#if RM
    if (rmServiceHandle)
        qmssGblCfgParams.qmRmServiceHandle = rmServiceHandle;
#endif



        /* Initialize the Queue Manager */
#if defined(DEVICE_K2H) || defined(DEVICE_K2K) || defined(DEVICE_K2L) || defined(DEVICE_K2E) || defined(DEVICE_C6678)
        result = Qmss_init (&qmssInitConfig, &qmssGblCfgParams);
#else
        result = Qmss_init (&qmssInitConfig, &qmssGblCfgParams[0]);
#endif
        if (result != QMSS_SOK)
        {
            NIMU_testLog ("Error initializing Queue Manager SubSystem, Error code : %d\n", result);
            return -1;
        }
    }
    /* Start Queue manager on this core */
    Qmss_start ();

    /* Setup the descriptor memory regions.
     *
     * The Descriptor base addresses MUST be global addresses and
     * all memory regions MUST be setup in ascending order of the
     * descriptor base addresses.
     */

    /* Initialize and setup CPSW Host Descriptors required for example */
    memset (gHostDesc, 0, p_qmss_cfg->desc_size * p_qmss_cfg->max_num_desc);
    memCfg.descBase             =   (uint32_t *) NIMU_convertCoreLocal2GlobalAddr ((uint32_t) gHostDesc);
    memCfg.descSize             =   p_qmss_cfg->desc_size;
    memCfg.descNum              =   p_qmss_cfg->max_num_desc;
    memCfg.manageDescFlag       =   Qmss_ManageDesc_MANAGE_DESCRIPTOR;
    memCfg.memRegion            =   p_qmss_cfg->mem_region;
    memCfg.startIndex           =   0;

    /* Insert Host Descriptor memory region */
    result = Qmss_insertMemoryRegion(&memCfg);
    if (result == QMSS_MEMREGION_ALREADY_INITIALIZED)
    {
    	NIMU_testLog ("Memory Region %d already Initialized \n", memCfg.memRegion);
    }
    else if (result < QMSS_SOK)
    {
    	NIMU_testLog ("Error: Inserting memory region %d, Error code : %d\n", memCfg.memRegion, result);
        return -1;
    }

    /* Initialize all the descriptors we just allocated on the
     * memory region above. Setup the descriptors with some well
     * known values before we use them for data transfers.
     */
    memset (&cppiDescCfg, 0, sizeof (cppiDescCfg));
    cppiDescCfg.memRegion       =   p_qmss_cfg->mem_region;
    cppiDescCfg.descNum         =   p_qmss_cfg->max_num_desc;
    cppiDescCfg.destQueueNum    =   QMSS_PARAM_NOT_SPECIFIED;
    cppiDescCfg.queueType       =   Qmss_QueueType_GENERAL_PURPOSE_QUEUE;
    cppiDescCfg.initDesc        =   Cppi_InitDesc_INIT_DESCRIPTOR;
    cppiDescCfg.descType        =   Cppi_DescType_HOST;

    /* By default:
     *      (1) Return descriptors to tail of queue
     *      (2) Always return entire packet to this free queue
     *      (3) Set that PS Data is always present in start of SOP buffer
     *      (4) Configure free q num < 4K, hence qMgr = 0
     *      (5) Recycle back to the same Free queue by default.
     */
    cppiDescCfg.returnPushPolicy            =   Qmss_Location_TAIL;
    cppiDescCfg.cfg.host.returnPolicy       =   Cppi_ReturnPolicy_RETURN_ENTIRE_PACKET;
    cppiDescCfg.cfg.host.psLocation         =   Cppi_PSLoc_PS_IN_DESC;
    cppiDescCfg.returnQueue.qMgr            =   0;
    cppiDescCfg.returnQueue.qNum            =   QMSS_PARAM_NOT_SPECIFIED;
    cppiDescCfg.epibPresent                 =   Cppi_EPIB_EPIB_PRESENT;

    /* Initialize the descriptors, create a free queue and push descriptors to a global free queue */
    if ((gGlobalFreeQHnd = Cppi_initDescriptor (&cppiDescCfg, &numAllocated)) <= 0)
    {
        NIMU_testLog ("Error Initializing Free Descriptors, Error: %d \n", gGlobalFreeQHnd);
        return -1;
    }

    if (numAllocated != cppiDescCfg.descNum)  {
        NIMU_testLog ("function NIMU_initQmss: expected %d descriptors to be initialized, only %d are initialized\n", cppiDescCfg.descNum, numAllocated);
      return (-1);
    }

    /* Queue Manager Initialization Done */
    return 0;
}

/** ============================================================================
 *   @n@b NIMU_stopQmss
 *
 *   @b Description
 *   @n This API de-initializes the QMSS LLD.
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
NIMU_stopQmss (void)
{
    Qmss_queueClose (gGlobalFreeQHnd);

    return 0;
}

#if 1
/** ============================================================================
 *   @n@b NIMU_qmssQPushDescSize
 *
 *   @b Description
 *   @n This API implements a the queue push logic with the Cache Management
 *
 *   @param[in]  handler
 *        Queue handler
 *   @param[in]  descAddr
 *        Descriptor address
 *   @param[in]  descSize
 *        descriptor Size
 *   @return    
 *   @n None
 * =============================================================================
 */
void 
NIMU_qmssQPushDescSize 
(
    Qmss_QueueHnd          handler,
    void                   *descAddr, 
    uint32_t               descSize
)
{

    Cppi_HostDesc*         pHostDesc = (Cppi_HostDesc *) descAddr;

    if ( descAddr == NULL ) {
        //gQPushErrorCounter++;
        return;
    }
#ifdef _TMS320C6X
    /* Wb data cache */
    CACHE_wbL1d((void *)pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    CACHE_wbL2((void *) pHostDesc->buffPtr, pHostDesc->buffLen, CACHE_WAIT);
    CACHE_wbL1d((void *)pHostDesc, sizeof(Cppi_HostDesc), CACHE_WAIT);
    CACHE_wbL2((void *) pHostDesc, sizeof(Cppi_HostDesc), CACHE_WAIT);

    asm (" MFENCE " );
#endif
    Qmss_queuePushDescSize (handler, 
                    //pHostDesc,
                    descAddr,
                    descSize 
                   );
}
#endif


/**********************************************************************
 ************ Resoure Manager CPPI configuration Functions ************
 **********************************************************************/

/** ============================================================================
 *   @n@b res_mgr_cppi_get_passhandle
 *
 *   @b Description
 *   @n This API returns the handle to the the CPPI DMA for the Packet Accelerator (PA).
 *
 *   @param[in]  None
 *
 *   @return  Cppi_Handle
 * =============================================================================
 */
Cppi_Handle
NIMU_cppiGetPASSHandle (void){
	return gPassCpdmaHnd;
}


/** ============================================================================
 *   @n@b NIMU_initCppi
 *
 *   @b Description
 *   @n This API initializes the CPPI LLD, opens the PDMA and opens up
 *      the Tx, Rx channels required for data transfers.
 *
 *   @param[in]  p_qmss_cfg
 *        Pointer to NIMU_CPPI_CFG_T
 *
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t 
NIMU_initCppi 
(
    NIMU_CPPI_CFG_T      *p_cppi_cfg
)
{
    int32_t                     result, i;
    Cppi_CpDmaInitCfg           cpdmaCfg;
    uint8_t                     isAllocated;
    Cppi_TxChInitCfg            txChCfg;
    Cppi_RxChInitCfg            rxChInitCfg;
    Cppi_Handle                 *p_handle = NULL;
    Cppi_ChHnd                  *p_ch_handle = NULL;
#if RM
    Cppi_StartCfg     cppiStartCfg;
#endif
    if (p_cppi_cfg->master_core)
    {
        /* Initialize CPPI LLD */
#if defined(DEVICE_K2H) || defined(DEVICE_K2K) || defined(DEVICE_K2L) || defined(DEVICE_K2E) || defined(DEVICE_C6678)
        result = Cppi_init (&cppiGblCfgParams);
#else
        result = Cppi_init (&cppiGblCfgParams[0]);
#endif
        if (result != CPPI_SOK)
        {
            NIMU_testLog ("Error initializing CPPI LLD, Error code : %d\n", result);
            return -1;
        }
    }


#if RM
     if (rmServiceHandle)
    {
        cppiStartCfg.rmServiceHandle = rmServiceHandle;
        Cppi_startCfg(&cppiStartCfg);
    }
#endif

    /* Initialize CPDMA */
    memset (&cpdmaCfg, 0, sizeof (Cppi_CpDmaInitCfg));
    cpdmaCfg.dmaNum     = p_cppi_cfg->dma_num;
    if (cpdmaCfg.dmaNum == Cppi_CpDma_PASS_CPDMA)
    {
        p_handle = &gPassCpdmaHnd;
        memcpy(&gCppiCfg[CPPI_CFG_PASS], p_cppi_cfg, sizeof(NIMU_CPPI_CFG_T));
    }

    if (p_handle)
    {
        if ((*p_handle = Cppi_open (&cpdmaCfg)) == NULL)
        {
            NIMU_testLog ("Error initializing CPPI for CPDMA %d \n", cpdmaCfg.dmaNum);
            return -1;
        }
    }
    else
    {
        return -1;
    }

    /* Open all CPPI Tx Channels. These will be used to send data to PASS/CPSW */
    for (i = 0; i < p_cppi_cfg->num_tx_queues; i ++)
    {
        txChCfg.channelNum      =   i;       /* CPPI channels are mapped one-one to the PA Tx queues */
        txChCfg.txEnable        =   Cppi_ChState_CHANNEL_DISABLE;  /* Disable the channel for now. */
        txChCfg.filterEPIB      =   0;
        txChCfg.filterPS        =   0;
        txChCfg.aifMonoMode     =   0;
        txChCfg.priority        =   2;

        if (cpdmaCfg.dmaNum == Cppi_CpDma_PASS_CPDMA)
        {
            p_ch_handle = &gPassCpdmaTxChanHnd[i];
        }

        if (p_ch_handle == NULL)
        {
            return -1;
        }

        if ((*p_ch_handle = Cppi_txChannelOpen (*p_handle, &txChCfg, &isAllocated)) == NULL)
        {
            NIMU_testLog ("Error opening Tx channel %d\n", txChCfg.channelNum);
            return -1;
        }

        Cppi_channelEnable (*p_ch_handle);
    }

    /* Open all CPPI Rx channels. These will be used by PA to stream data out. */
    for (i = 0; i < p_cppi_cfg->num_rx_channels; i++)
    {
        /* Open a CPPI Rx channel that will be used by PA to stream data out. */
        rxChInitCfg.channelNum  =   i;
        rxChInitCfg.rxEnable    =   Cppi_ChState_CHANNEL_DISABLE;
        if ((gPassCpdmaRxChanHnd[i] = Cppi_rxChannelOpen (*p_handle, &rxChInitCfg, &isAllocated)) == NULL)
        {
        	NIMU_testLog("Error opening Rx channel: %d \n", rxChInitCfg.channelNum);
            return -1;
        }

        /* Also enable Rx Channel */
        Cppi_channelEnable (gPassCpdmaRxChanHnd[i]);
    }

    /* Clear CPPI Loobpack bit in PASS CDMA Global Emulation Control Register */
    Cppi_setCpdmaLoopback(*p_handle, 0);

    /* CPPI Init Done. Return success */
    return 0;
}

/** ============================================================================
 *   @n@b NIMU_stopCppi
 *
 *   @b Description
 *   @n This API de-initializes the CPPI LLD.
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
NIMU_stopCppi 
(
    NIMU_CPPI_CFG_TYPE       cfg_type
)
{
    uint32_t i;

    if (cfg_type == CPPI_CFG_PASS)
    {
        for (i = 0; i < gCppiCfg[cfg_type].num_rx_channels; i++)
            Cppi_channelClose (gPassCpdmaRxChanHnd[i]);
        
        for (i = 0; i < gCppiCfg[cfg_type].num_tx_queues; i++)
            Cppi_channelClose (gPassCpdmaTxChanHnd[i]);
    }

    return 0;
}





