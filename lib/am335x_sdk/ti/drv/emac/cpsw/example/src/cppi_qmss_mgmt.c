/**  
 * @file cppi_qmss_mgmt.c
 *
 * @brief 
 *  This file holds all the APIs required to configure CPPI/QMSS LLDs and 
 *  to send/receive data using PA/QM.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2009-2013, Texas Instruments, Inc.
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
#include <ti/drv/emac/cpsw/example/src/cpsw_singlecore.h>
#ifndef DEVICE_K2G
#include <ti/drv/pa/pa.h>
#include <ti/drv/pa/pasahost.h>
#endif
#ifdef __LINUX_USER_SPACE
#include "armv7/linux/fw_test.h"

extern uint8_t                                *gPaCmdBuf1;
extern uint8_t                                *gPaCmdBuf2;

#if defined(DEVICE_K2H)
#include <ti/drv/qmss/device/k2h/src/qmss_device.c>
#include <ti/drv/cppi/device/k2h/src/cppi_device.c>
#include <ti/drv/emac/nss_if.h>
#elif defined (DEVICE_K2K)
#include <ti/drv/qmss/device/k2k/src/qmss_device.c>
#include <ti/drv/cppi/device/k2k/src/cppi_device.c>
#include <ti/drv/pa/device/k2k/src/nss_device.c>
#elif defined (DEVICE_K2L)
#include <ti/drv/qmss/device/k2l/src/qmss_device.c>
#include <ti/drv/cppi/device/k2l/src/cppi_device.c>
#include <ti/drv/pa/device/k2l/src/nss_device.c>
#elif defined (DEVICE_K2E)
#include <ti/drv/qmss/device/k2e/src/qmss_device.c>
#include <ti/drv/cppi/device/k2e/src/cppi_device.c>
#include <ti/drv/pa/device/k2e/src/nss_device.c>
#elif defined (DEVICE_K2G)
#include <ti/drv/qmss/device/k2g/src/qmss_device.c>
#include <ti/drv/cppi/device/k2g/src/cppi_device.c>
#include <ti/drv/emac/nss_if.h>
#else /*Default */
#include <ti/drv/qmss/device/k2h/src/qmss_device.c>
#include <ti/drv/cppi/device/k2h/src/cppi_device.c>
#include <ti/drv/pa/device/k2h/src/nss_device.c>
#endif /* Device */


#else
#include <ti/drv/qmss/qmss_firmware.h>
#endif /*  __LINUX_USER_SPACE */

/* QMSS device specific configuration */
extern Qmss_GlobalConfigParams  qmssGblCfgParams;
/* CPPI device specific configuration */
extern Cppi_GlobalConfigParams  cppiGblCfgParams;


#if ( !defined( _LITTLE_ENDIAN ) && !defined( _BIG_ENDIAN ) ) \
||  ( defined(_LITTLE_ENDIAN ) && defined( _BIG_ENDIAN ) )
#error either _LITTLE_ENDIAN or _BIG_ENDIAN must be defined
#endif

/* Host Descriptor Region - [Size of descriptor * Number of descriptors] 
 *
 * MUST be 16 byte aligned.
 */
#ifdef __LINUX_USER_SPACE
uint8_t                                *gHostDesc = 0;
#else
#pragma DATA_ALIGN (gHostDesc, 128)
uint8_t                                 gHostDesc[SIZE_HOST_DESC * NUM_HOST_DESC];
#endif

/* CPPI/QMSS Handles used by the application */
Qmss_QueueHnd                           gGlobalFreeQHnd, gPaTxQHnd [MAX_PA_TX_QUEUES], gTxFreeQHnd, gRxFreeQHnd, gRxQHnd, gDivQHnd;
Cppi_Handle                             gCpdmaHnd;
Cppi_ChHnd                              gCpdmaTxChanHnd [MAX_PA_TX_CHANNELS], gCpdmaRxChanHnd [MAX_PA_RX_CHANNELS];
Cppi_FlowHnd                            gRxFlowHnd;

/* Number of Tx Free descriptors to allocate */
#define     NUM_TX_DESC                 NUM_HOST_DESC/2

/* Number of Rx Free descriptors to allocate */
#define     NUM_RX_DESC                 NUM_HOST_DESC/2

/* Tx/Rx packet counters */
volatile uint32_t						gTxCounter = 0, gRxCounter = 0;

/** ============================================================================
 *   @n@b Init_Qmss
 *
 *   @b Description
 *   @n This API initializes the QMSS LLD.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t Init_Qmss (void)
{
    int32_t                     result;
    Qmss_MemRegInfo             memCfg;
    Qmss_InitCfg                qmssInitConfig;
    Cppi_DescCfg                cppiDescCfg;
    uint32_t                    numAllocated;
    Qmss_GlobalConfigParams     *fw_qmssGblCfgParams;

    /* Initialize QMSS */
    memset (&qmssInitConfig, 0, sizeof (Qmss_InitCfg));

    /* Set up QMSS configuration */

    /* Use internal linking RAM */
    qmssInitConfig.linkingRAM0Base  =   0;   
    qmssInitConfig.linkingRAM0Size  =   NUM_HOST_DESC;
    qmssInitConfig.linkingRAM1Base  =   0x0;
    qmssInitConfig.maxDescNum       =   NUM_HOST_DESC;

    /* Provide the firmware for DSP use case */
#ifdef __LINUX_USER_SPACE
    /* Bypass hardware initialization as it is done within Kernel */
    qmssInitConfig.qmssHwStatus     =   QMSS_HW_INIT_COMPLETE;
#else
    if (no_bootMode == TRUE)
    {
#ifndef NSS_LITE    
       qmssInitConfig.pdspFirmware[0].pdspId = Qmss_PdspId_PDSP1;
#ifdef _LITTLE_ENDIAN    
       qmssInitConfig.pdspFirmware[0].firmware = (void *) &acc48_le;
       qmssInitConfig.pdspFirmware[0].size = sizeof (acc48_le);
#else
       qmssInitConfig.pdspFirmware[0].firmware = (void *) &acc48_be;
       qmssInitConfig.pdspFirmware[0].size = sizeof (acc48_be);
#endif
#endif
    }
    else
    {
        /* Bypass hardware initialization as it is done within Kernel */
        qmssInitConfig.qmssHwStatus     =   QMSS_HW_INIT_COMPLETE;
    }
#endif

#if RM
#ifdef __LINUX_USER_SPACE
    qmssGblCfgParams.qmRmServiceHandle = rmClientServiceHandle;
#else
    if (rmServiceHandle)
		qmssGblCfgParams.qmRmServiceHandle = rmServiceHandle;
#endif
#endif
    /* Initialize the Queue Manager */
    fw_qmssGblCfgParams = &qmssGblCfgParams;
    get_qmssGblCfgParamsRegsPhy2Virt(fw_qmssGblCfgParams);
    result = Qmss_init (&qmssInitConfig, fw_qmssGblCfgParams);
    if (result != QMSS_SOK)
    {
        System_printf ("Error initializing Queue Manager SubSystem, Error code : %d\n", result);
        return -1;
    }

    /* Start Queue manager on this core */
    Qmss_start ();

    /* Setup the descriptor memory regions. 
     *
     * The Descriptor base addresses MUST be global addresses and
     * all memory regions MUST be setup in ascending order of the
     * descriptor base addresses.
     */
#ifdef __LINUX_USER_SPACE
    gHostDesc = (uint8_t*)fw_memAlloc((NUM_HOST_DESC *
                                       SIZE_HOST_DESC),
                                       CACHE_LINESZ);
    gPaCmdBuf1 = (uint8_t*) fw_memAlloc(pa_ADD_LUT1_MIN_CMD_BUF_SIZE_BYTES, CACHE_LINESZ);
	gPaCmdBuf2 = (uint8_t*) fw_memAlloc(pa_ADD_LUT2_MIN_CMD_BUF_SIZE_BYTES, CACHE_LINESZ);

#endif
    /* Initialize and setup CPSW Host Descriptors required for example */
    memset (gHostDesc, 0, SIZE_HOST_DESC * NUM_HOST_DESC);
    memCfg.descBase             =   (uint32_t *) Convert_CoreLocal2GlobalAddr ((uint32_t) gHostDesc);
    memCfg.descSize             =   SIZE_HOST_DESC;
    memCfg.descNum              =   NUM_HOST_DESC;
    memCfg.manageDescFlag       =   Qmss_ManageDesc_MANAGE_DESCRIPTOR;
    memCfg.memRegion            =   Qmss_MemRegion_MEMORY_REGION0;
    memCfg.startIndex           =   0;

    /* Insert Host Descriptor memory region */
    result = Qmss_insertMemoryRegion(&memCfg);
    if (result == QMSS_MEMREGION_ALREADY_INITIALIZED)
    {
        System_printf ("Memory Region %d already Initialized \n", memCfg.memRegion);
    }
    else if (result < QMSS_SOK)
    {
        System_printf ("Error: Inserting memory region %d, Error code : %d\n", memCfg.memRegion, result);
        return -1;
    }    

    /* Initialize all the descriptors we just allocated on the
     * memory region above. Setup the descriptors with some well
     * known values before we use them for data transfers.
     */
    memset (&cppiDescCfg, 0, sizeof (cppiDescCfg));
    cppiDescCfg.queueGroup      =   0;
    cppiDescCfg.memRegion       =   Qmss_MemRegion_MEMORY_REGION0;
    cppiDescCfg.descNum         =   NUM_HOST_DESC;
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
    cppiDescCfg.returnQueue.qMgr            =   QMSS_PARAM_NOT_SPECIFIED;
    cppiDescCfg.returnQueue.qNum            =   QMSS_PARAM_NOT_SPECIFIED; 
    cppiDescCfg.epibPresent                 =   Cppi_EPIB_EPIB_PRESENT;
    
    /* Initialize the descriptors, create a free queue and push descriptors to a global free queue */
    if ((gGlobalFreeQHnd = Cppi_initDescriptor (&cppiDescCfg, &numAllocated)) <= 0)
    {
        System_printf ("Error Initializing Free Descriptors, Error: %d \n", gGlobalFreeQHnd);
        return -1;
    }        
   
    /* Queue Manager Initialization Done */
    return 0;
}

/** ============================================================================
 *   @n@b Init_Cppi
 *
 *   @b Description
 *   @n This API initializes the CPPI LLD, opens the PASS CPDMA and opens up
 *      the Tx, Rx channels required for data transfers.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t Init_Cppi (void)
{
    int32_t                       result, i;
    Cppi_CpDmaInitCfg           cpdmaCfg;
    uint8_t                       isAllocated;
    Cppi_TxChInitCfg            txChCfg;
    Cppi_RxChInitCfg            rxChInitCfg;
    Cppi_GlobalConfigParams         fw_cppiGblCfgParams;
#if RM
    Cppi_StartCfg     cppiStartCfg;
#endif
    uint32_t cppi_pa_tx_ch_disable_list[MAX_PA_TX_CHANNELS];
    uint32_t cppi_pa_rx_ch_disable_list[MAX_PA_RX_CHANNELS];
    uint32_t disable_list_flag = 0;

    /* Clear the list by default */
    memset (cppi_pa_tx_ch_disable_list, 0, sizeof (cppi_pa_tx_ch_disable_list));
    memset (cppi_pa_rx_ch_disable_list, 0, sizeof (cppi_pa_rx_ch_disable_list));

    fw_cppiGblCfgParams = cppiGblCfgParams;
    /* Initialize CPPI LLD */
    get_cppiGblCfgParamsRegsPhy2Virt(&fw_cppiGblCfgParams);
    result = Cppi_init (&fw_cppiGblCfgParams);
    if (result != CPPI_SOK)
    {
        System_printf ("Error initializing CPPI LLD, Error code : %d\n", result);
        return -1;
    }

#if RM
#ifdef __LINUX_USER_SPACE
	if (rmClientServiceHandle) {
	   /* Register RM with CPPI */
	   cppiStartCfg.rmServiceHandle = rmClientServiceHandle;
	   Cppi_startCfg(&cppiStartCfg);
	}
#else
	 if (rmServiceHandle)
	 {
        cppiStartCfg.rmServiceHandle = rmServiceHandle;
        Cppi_startCfg(&cppiStartCfg);
	 }
#endif
#endif
    /* Initialize PASS CPDMA */
    memset (&cpdmaCfg, 0, sizeof (Cppi_CpDmaInitCfg));
    cpdmaCfg.dmaNum     = Cppi_CpDma_PASS_CPDMA;
    if ((gCpdmaHnd = Cppi_open (&cpdmaCfg)) == NULL)
    {
        System_printf ("Error initializing CPPI for PASS CPDMA %d \n", cpdmaCfg.dmaNum);
        return -1;
    }    

    /* Open all CPPI Tx Channels. These will be used to send data to PASS/CPSW */             
    for (i = 0, disable_list_flag = 0; i < NSS_NUM_TX_PKTDMA_CHANNELS; i ++)
    {
        txChCfg.channelNum      =   i;       /* CPPI channels are mapped one-one to the PA Tx queues */
        txChCfg.txEnable        =   Cppi_ChState_CHANNEL_DISABLE;  /* Disable the channel for now. */
        txChCfg.filterEPIB      =   0;
        txChCfg.filterPS        =   0;
        txChCfg.aifMonoMode     =   0;
        txChCfg.priority        =   2;
        if ((gCpdmaTxChanHnd[i] = Cppi_txChannelOpen (gCpdmaHnd, &txChCfg, &isAllocated)) == NULL)
        {
            if (no_bootMode == TRUE)
            {
        	   System_printf ("Error opening Tx channel %d\n", txChCfg.channelNum);
               return -1;
            }
            else
            {
            	cppi_pa_tx_ch_disable_list[i] = 1;
            	disable_list_flag = 1;
            	continue;
            }
        }

        Cppi_channelEnable (gCpdmaTxChanHnd[i]);
    }

    /* Print if there are any CPPI Tx channels that are not enabled by above code, presuming linux enabled it */
    if (disable_list_flag)
    {
    	System_printf ("Unable to open below cppi tx channels...presuming linux has already enabled it \n");
		for (i = 0; i<NSS_NUM_TX_QUEUES; i++)
		{
			 if (cppi_pa_tx_ch_disable_list[i])
				 System_printf ("%d ", i);
		}
		System_printf (" \n ");
    }

    /* Open all CPPI Rx channels. These will be used by PA to stream data out. */
    for (i = 0, disable_list_flag = 0; i < NSS_NUM_RX_PKTDMA_CHANNELS; i++)
    {
        /* Open a CPPI Rx channel that will be used by PA to stream data out. */
        rxChInitCfg.channelNum  =   i; 
        rxChInitCfg.rxEnable    =   Cppi_ChState_CHANNEL_DISABLE; 
        if ((gCpdmaRxChanHnd[i] = Cppi_rxChannelOpen (gCpdmaHnd, &rxChInitCfg, &isAllocated)) == NULL)
        {
            if (no_bootMode == TRUE)
            {
            	System_printf ("Error opening Rx channel: %d \n", rxChInitCfg.channelNum);
                return -1;
            }
            else
            {
            	cppi_pa_rx_ch_disable_list[i] = 1;
            	disable_list_flag = 1;
            	continue;
            }
        }

        /* Also enable Rx Channel */
        Cppi_channelEnable (gCpdmaRxChanHnd[i]);    
    }
    
    /* Print if there are any CPPI Rx channels that are not enabled by above code, presuming linux enabled it */
    if (disable_list_flag)
    {
    	System_printf ("Unable to open below cppi Rx channels...presuming linux has already enabled it \n");
		for (i = 0; i<NSS_NUM_RX_PKTDMA_CHANNELS; i++)
		{
			 if (cppi_pa_rx_ch_disable_list[i])
				 System_printf ("%d ", i);
		}
		System_printf (" \n ");
    }

    /* Clear CPPI Loobpack bit in PASS CDMA Global Emulation Control Register */
    Cppi_setCpdmaLoopback(gCpdmaHnd, 0);   

    /* CPPI Init Done. Return success */
    return 0;
}    

/** ============================================================================
 *   @n@b Setup_Tx
 *
 *   @b Description
 *   @n This API sets up all relevant data structures and configuration required
 *      for sending data to PASS/Ethernet. It sets up a Tx free descriptor queue,
 *      PASS Tx queues required for send.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t Setup_Tx (void)
{
    uint8_t                       isAllocated, i;
    Qmss_Queue                  qInfo;
    Ptr                   		pCppiDesc;

    /* Open all Transmit (Tx) queues. 
     *
     * These queues are used to send data to PA PDSP/CPSW.
     */
    for (i = 0; i < NSS_NUM_TX_QUEUES; i ++)
    {
            
        if ((gPaTxQHnd[i] = Qmss_queueOpen (Qmss_QueueType_PASS_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
        {
            System_printf ("Error opening PA Tx queue, err:%d \n", gPaTxQHnd[i]);
            return -1;
        }            
    }

    /* Open a Tx Free Descriptor Queue (Tx FDQ). 
     *
     * This queue will be used to hold Tx free decriptors that can be filled
     * later with data buffers for transmission onto wire.
     */
    #ifndef NSS_LITE 
    if ((gTxFreeQHnd = Qmss_queueOpen (Qmss_QueueType_STARVATION_COUNTER_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        System_printf ("Error opening Tx Free descriptor queue, err: %d \n", gTxFreeQHnd);
        return -1;
    }       
    #else
    if ((gTxFreeQHnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        System_printf ("Error opening Tx Free descriptor queue, err: %d \n", gTxFreeQHnd);
        return -1;
    }       
    #endif     

    qInfo = Qmss_getQueueNumber (gTxFreeQHnd);

    /* Attach some free descriptors to the Tx free queue we just opened. */
    for (i = 0; i < NUM_TX_DESC; i++)
    {
        /* Get a free descriptor from the global free queue we setup 
         * during initialization.
         */
        if ((pCppiDesc = Qmss_queuePop (gGlobalFreeQHnd)) == NULL)
        {
            break;                
        }

        /* The descriptor address returned from the hardware has the 
         * descriptor size appended to the address in the last 4 bits.
         *
         * To get the true descriptor size, always mask off the last 
         * 4 bits of the address.
         */
        pCppiDesc = (Ptr) ((uint32_t) pCppiDesc & 0xFFFFFFF0);

        /* Setup the Completion queue:
         *
         * Setup the return policy for this desc to return to the free q we just
         * setup instead of the global free queue.
         */
        Cppi_setReturnQueue ((Cppi_DescType) Cppi_DescType_HOST, pCppiDesc, qInfo);

        /* Push descriptor to Tx free queue */
        Qmss_queuePushDescSize (gTxFreeQHnd, pCppiDesc, SIZE_HOST_DESC);           
    }
    if (i != NUM_TX_DESC)
    {
        System_printf ("Error allocating Tx free descriptors \n");            
        return -1;
    }

    /* All done with Rx configuration. Return success. */
    return 0;
}

/** ============================================================================
 *   @n@b Setup_Rx
 *
 *   @b Description
 *   @n This API sets up all relevant data structures and configuration required
 *      for receiving data from PASS/Ethernet. It sets up a Rx free descriptor queue
 *      with some empty pre-allocated buffers to receive data, and an Rx queue
 *      to which the Rxed data is streamed for the example application. This API
 *      also sets up the QM high priority accumulation interrupts required to
 *      receive data from the Rx queue.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t Setup_Rx (void)
{
    uint8_t                     isAllocated, i;
    Qmss_Queue                  rxFreeQInfo, rxQInfo;
    Ptr                   		pCppiDesc;
    Cppi_RxFlowCfg              rxFlowCfg;
    Ptr                         pDataBuffer;
    uint32_t                    mySWInfo[] = {0x11112222, 0x33334444};

    if ((setup_rx_queue(&rxQInfo)) < 0)
    {
    	System_printf (" Error in setting up receive queue information\n");
    	return -1;
    }
    
    /* Open a Rx Free Descriptor Queue (Rx FDQ). 
     *
     * This queue will hold all the Rx free decriptors. These descriptors will be
     * used by the PASS CPDMA to hold data received via CPSW.
     */
    #ifndef NSS_LITE 
    if ((gRxFreeQHnd = Qmss_queueOpen (Qmss_QueueType_STARVATION_COUNTER_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        System_printf ("Error opening Rx Free descriptor queue \n");
        return -1;
    }            
    #else
    if ((gRxFreeQHnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        System_printf ("Error opening Rx Free descriptor queue \n");
        return -1;
    }            
    #endif
    rxFreeQInfo = Qmss_getQueueNumber (gRxFreeQHnd);

    /* Attach some free descriptors to the Rx free queue we just opened. */
    for (i = 0; i < NUM_RX_DESC; i++)
    {
        /* Get a free descriptor from the global free queue we setup 
         * during initialization.
         */
        if ((pCppiDesc = Qmss_queuePop (gGlobalFreeQHnd)) == NULL)
        {
            System_printf ("Error poping descriptor.\n");
            break;                
        }

        /* The descriptor address returned from the hardware has the 
         * descriptor size appended to the address in the last 4 bits.
         *
         * To get the true descriptor size, always mask off the last 
         * 4 bits of the address.
         */
        pCppiDesc = (Ptr) ((uint32_t) pCppiDesc & 0xFFFFFFF0);

#ifdef EXT_DEBUG
        System_printf ("@Alloc Time:%d, pCppiDesc:%x \n", i, pCppiDesc);
#endif
		pDataBuffer = DataBufAlloc();

		if (pDataBuffer == NULL)
		{
		   System_printf (" Failed to allocate data buffer for the Tx Descriptor\n");
		}
#ifdef EXT_DEBUG
		else
		{
		  System_printf ("Setup_Rx(): &pDataBuffer[%d]: %p \n", i, pDataBuffer);
		}
#endif
        /* Populate the Rx free descriptor with the buffer we just allocated. */
        Cppi_setData (Cppi_DescType_HOST, pCppiDesc, (uint8_t *)Convert_CoreLocal2GlobalAddr((uint32_t)pDataBuffer), PA_EMAC_EX_RXBUF_SIZE);

        /* Save original buffer information */
        Cppi_setOriginalBufInfo (Cppi_DescType_HOST, pCppiDesc, (uint8_t *)Convert_CoreLocal2GlobalAddr((uint32_t)pDataBuffer), PA_EMAC_EX_RXBUF_SIZE);

        /* Setup the Completion queue:
         *
         * Setup the return policy for this desc to return to the free q we just
         * setup instead of the global free queue.
         */
        Cppi_setReturnQueue (Cppi_DescType_HOST, pCppiDesc, rxFreeQInfo);

        Cppi_setSoftwareInfo (Cppi_DescType_HOST, pCppiDesc, (uint8_t *) mySWInfo);

        Cppi_setPacketLen    (Cppi_DescType_HOST, pCppiDesc, PA_EMAC_EX_RXBUF_SIZE);
        
        /* Push descriptor to Tx free queue */
        Qmss_queuePushDescSize (gRxFreeQHnd, pCppiDesc, SIZE_HOST_DESC);           
    }        
    if (i != NUM_RX_DESC)
    {
        System_printf ("Error allocating Rx free descriptors \n");
        return -1;
    }

    /* Setup a Rx Flow.
     *
     * A Rx flow encapsulates all relevant data properties that CPDMA would
     * have to know in order to succefully receive data.
     */
    /* Initialize the flow configuration */
    memset (&rxFlowCfg, 0, sizeof(Cppi_RxFlowCfg));
    rxFreeQInfo = Qmss_getQueueNumber (gRxFreeQHnd);

    /* Let CPPI pick the next available flow */
    #ifndef NSS_LITE
    rxFlowCfg.flowIdNum             =   CPPI_PARAM_NOT_SPECIFIED;
    #else
    rxFlowCfg.flowIdNum             =   0;
    #endif

    rxFlowCfg.rx_dest_qmgr          =   rxQInfo.qMgr;    
    rxFlowCfg.rx_dest_qnum          =   rxQInfo.qNum;  
    rxFlowCfg.rx_desc_type          =   Cppi_DescType_HOST; 

    rxFlowCfg.rx_ps_location        =   Cppi_PSLoc_PS_IN_DESC;  
    rxFlowCfg.rx_psinfo_present     =   1;    /* Enable PS info */
    
    rxFlowCfg.rx_error_handling     =   0;    /* Drop the packet, do not retry on starvation by default */       
    rxFlowCfg.rx_einfo_present      =   1;    /* EPIB info present */       
    
    rxFlowCfg.rx_dest_tag_lo_sel    =   0;    /* Disable tagging */
    rxFlowCfg.rx_dest_tag_hi_sel    =   0;    
    rxFlowCfg.rx_src_tag_lo_sel     =   0;    
    rxFlowCfg.rx_src_tag_hi_sel     =   0;    

    rxFlowCfg.rx_size_thresh0_en    =   0;    /* By default, we disable Rx Thresholds */
    rxFlowCfg.rx_size_thresh1_en    =   0;    /* By default, we disable Rx Thresholds */
    rxFlowCfg.rx_size_thresh2_en    =   0;    /* By default, we disable Rx Thresholds */
    rxFlowCfg.rx_size_thresh0       =   0x0;
    rxFlowCfg.rx_size_thresh1       =   0x0;
    rxFlowCfg.rx_size_thresh2       =   0x0;

    rxFlowCfg.rx_fdq0_sz0_qmgr      =   rxFreeQInfo.qMgr; /* Setup the Receive free queue for the flow */
    rxFlowCfg.rx_fdq0_sz0_qnum      =   rxFreeQInfo.qNum;    
    rxFlowCfg.rx_fdq0_sz1_qnum      =   0x0; 
    rxFlowCfg.rx_fdq0_sz1_qmgr      =   0x0;
    rxFlowCfg.rx_fdq0_sz2_qnum      =   0x0;
    rxFlowCfg.rx_fdq0_sz2_qmgr      =   0x0;
    rxFlowCfg.rx_fdq0_sz3_qnum      =   0x0;
    rxFlowCfg.rx_fdq0_sz3_qmgr      =   0x0;

    rxFlowCfg.rx_fdq1_qnum          =   rxFreeQInfo.qNum;  /* Use the Rx Queue to pick descriptors */
    rxFlowCfg.rx_fdq1_qmgr          =   rxFreeQInfo.qMgr;
    rxFlowCfg.rx_fdq2_qnum          =   rxFreeQInfo.qNum;  /* Use the Rx Queue to pick descriptors */
    rxFlowCfg.rx_fdq2_qmgr          =   rxFreeQInfo.qMgr;
    rxFlowCfg.rx_fdq3_qnum          =   rxFreeQInfo.qNum;  /* Use the Rx Queue to pick descriptors */
    rxFlowCfg.rx_fdq3_qmgr          =   rxFreeQInfo.qMgr;

    /* Configure the Rx flow */
    if ((gRxFlowHnd = Cppi_configureRxFlow (gCpdmaHnd, &rxFlowCfg, &isAllocated)) == NULL)
    {
        System_printf ("Error configuring Rx flow \n");
        return -1;
    }

    /* All done with Rx configuration. Return success. */
    return 0;
}

void closeAllOpenedQueues(void) {

	  int i;
	  extern Qmss_QueueHnd                           gPaCfgCmdRespQHnd;

	  /* The 10 PA transmit queues (corresponding to the 10 tx cdma channels */
	  for (i = 0; i < NSS_NUM_TX_QUEUES; i++)  {
	  	 Qmss_queueEmpty (gPaTxQHnd[i]);
	  	 Qmss_queueClose (gPaTxQHnd[i]);
	  }

	  /* Empty the remaining queues */
 	  Qmss_queueEmpty(gGlobalFreeQHnd);
 	  Qmss_queueClose(gGlobalFreeQHnd);

	  Qmss_queueEmpty (gTxFreeQHnd);
	  Qmss_queueEmpty (gRxFreeQHnd);
      #ifndef NSS_LITE
	  Qmss_queueEmpty (gPaCfgCmdRespQHnd);
      #endif
	  Qmss_queueEmpty (gRxQHnd);
	  Qmss_queueEmpty (gDivQHnd);

	  /* Close the remaining queues */
	  Qmss_queueClose (gTxFreeQHnd);
	  Qmss_queueClose (gRxFreeQHnd);
      #ifndef NSS_LITE
	  Qmss_queueClose (gPaCfgCmdRespQHnd);
      #endif
	  Qmss_queueClose (gRxQHnd);
	  Qmss_queueClose (gDivQHnd);

	  return;

}

uint32_t dbg_rx_buf2[NUM_RX_DESC];
uint32_t dbg_tx_buf2[NUM_TX_DESC];

/* The QM/CPDMA are cleared */
int freeAttachedBufs(void)
{
   int i;
   uint8_t *bufaddr;
   uint32_t buflen;
   void* 		pCppiDesc;

   /* Free Attached Buffers associated with Rx descriptors
    * Note that there are no attached buffers for the Tx Descriptors
    *
    */
   for (i = 0; i < NUM_RX_DESC; i++) {

       /* Get a free descriptor from the global free queue we setup
        * during initialization.
        */
       if ((pCppiDesc = Qmss_queuePop (gRxFreeQHnd)) == NULL)
       {
           System_printf ("Error poping descriptor.\n");
           break;
       }

       /* The descriptor address returned from the hardware has the
        * descriptor size appended to the address in the last 4 bits.
        *
        * To get the true descriptor size, always mask off the last
        * 4 bits of the address.
        */
       pCppiDesc = (Ptr) ((uint32_t) pCppiDesc & 0xFFFFFFF0);
       
       //dbg_rx_buf2[i] = (uint32_t)pCppiDesc;  
       
       Cppi_getOriginalBufInfo (Cppi_DescType_HOST, pCppiDesc, &bufaddr, &buflen);
       if (bufaddr != 0 && buflen != 0)
       {
    	   /* Clear the global conversion mask as the original buffer information
    	    * stored contains the global address - need to clear it since BIOS did
    	    * not provide that address during the allocation */
    	   bufaddr = (uint8_t *) Convert_CoreGlobal2L2Addr((uint32_t)bufaddr);
    	   DataBufFree((void*)bufaddr, buflen);
       }    
   }
   

   return (0);
}

int clearFramework(void)
{
	Qmss_Result qmss_result;
    Cppi_Result cppi_result;
    int i, accChannelNum;
#ifdef __LINUX_USER_SPACE
    uint8_t    coreNum = 0;
#else
  	uint8_t                       coreNum = (uint8_t) CSL_chipReadReg(CSL_CHIP_DNUM);
#endif

#ifndef NSS_LITE
	/* Delete the MAC Address added */
	if (Del_Port() < 0)
	{
		System_printf ("Failed to clean up the MAC address\n");
	}

	/* Delete the Ip Address added */
	if (Del_IPAddress() < 0)
	{
		System_printf ("Failed to clean up the MAC address\n");
	}

	/* Delete the MAC Address added */
	if (Del_MACAddress() < 0)
	{
		System_printf ("Failed to clean up the MAC address\n");
	}

#endif

	/* clear the flows */
	if ((cppi_result = Cppi_closeRxFlow (gRxFlowHnd)) != CPPI_SOK) {
	   	return (-1);
	}

	/* Free Attached Bufs */
	freeAttachedBufs();

#if  !defined(__LINUX_USER_SPACE) && !defined(NSS_LITE)
	/* Close the Accumulator Channel programmed */
    accChannelNum   =   PA_ACC_CHANNEL_NUM + coreNum;
    qmss_result = Qmss_disableAccumulator (Qmss_PdspId_PDSP1, accChannelNum);
    if (qmss_result != QMSS_ACC_SOK && qmss_result != QMSS_ACC_CHANNEL_NOT_ACTIVE)
    {
       System_printf ("Error Disabling high priority accumulator for channel : %d error code: %d\n",
                       accChannelNum, qmss_result);
       return -1;
    }
#endif
	/* Close the queues that were setup */
	closeAllOpenedQueues();

	/* Close the cpDma setup */
	for (i = 0; i < NSS_NUM_RX_PKTDMA_CHANNELS; i++)  {
		/* close the channel only if it was opened by it */
		 if (gCpdmaRxChanHnd[i] != NULL) {
			 if ((cppi_result = Cppi_channelClose (gCpdmaRxChanHnd[i])) != CPPI_SOK) {
				return (cppi_result);
			 }
		 }
	}
	for (i = 0; i < NSS_NUM_TX_PKTDMA_CHANNELS; i++)  {
		/* close the channel only if it was opened by it */
		 if (gCpdmaTxChanHnd[i] != NULL) {
			 if ((cppi_result = Cppi_channelClose (gCpdmaTxChanHnd[i])) != CPPI_SOK) {
				return (cppi_result);
			 }
		 }
	}

	/* Free the memory regions */
	if ((qmss_result = Qmss_removeMemoryRegion (Qmss_MemRegion_MEMORY_REGION0, 0)) != QMSS_SOK)
	{
	     System_printf ("Error Core : Remove memory region error code : %d\n", qmss_result);
	}

    while ((qmss_result = Qmss_exit()) != QMSS_SOK)
    {
        for (i=0; i<100; i++); /* Wait for QM Exit */
    }
	return (0);

}
