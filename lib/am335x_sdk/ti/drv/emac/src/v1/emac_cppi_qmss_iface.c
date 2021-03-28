/**
 *  \file   emac_cppi_qmss.c
 *
 *  \brief  EMAC Driver APIs implementation specific to K2G.
 *
 *   The file implements the Ethernet Driver API which are local of the EMAC driver and 
 *   setup the NSS sub-system.
 */

/*
 * Copyright (C) 2015-2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */


/**************************************************************************
 *************************** Include Files ********************************
 **************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CSL Headers */
#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_cache.h>
#include <ti/csl/csl_psc.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_pscAux.h>

#ifdef _TMS320C6X
#include <ti/csl/csl_chipAux.h>
#endif

/* EMAC LLD include */
#include <ti/drv/emac/nss_if.h>
#include <ti/drv/emac/src/v1/emac_v1.h>
#include <ti/drv/emac/src/emac_osal.h>

/* QMSS LLD include */

#include <ti/drv/qmss/qmss_firmware.h>

/* QMSS device specific configuration */
extern Qmss_GlobalConfigParams  qmssGblCfgParams;
/* CPPI device specific configuration */
extern Cppi_GlobalConfigParams  cppiGblCfgParams;



extern EMAC_MCB_V1_T      emac_mcb;
extern void EMAC_v1_hwiFxn(uintptr_t arg);

Qmss_MemRegion memoryRegion;
OsalRegisterIntrParams_t interruptRegParams;

/** ============================================================================
 *   @n@b emac_init_qmss
 *
 *   @b Description
 *   @n This function initializes the QMSS LLD.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t emac_init_qmss (uint32_t port_num,
                                           EMAC_OPEN_CONFIG_INFO_T*                  p_config,
                                           EMAC_HwAttrs_V1           *p_hwAttrs)
{
    int32_t                     result;
    Qmss_MemRegInfo             memCfg;
    Qmss_InitCfg                qmssInitConfig;
    Cppi_DescCfg                cppiDescCfg;
    uint32_t                    numAllocated;
    Qmss_GlobalConfigParams     *fw_qmssGblCfgParams;
    uint8_t                                *gHostDesc;
    uint32_t num_descriptors = p_config->num_of_rx_pkt_desc + p_config->num_of_tx_pkt_desc;


    /* Initialize QMSS */
    memset (&qmssInitConfig, 0, sizeof (Qmss_InitCfg));

    /* Set up QMSS configuration */

    /* Use internal linking RAM */
    qmssInitConfig.linkingRAM0Base  =   0;   
    qmssInitConfig.linkingRAM0Size  =   num_descriptors;
    qmssInitConfig.linkingRAM1Base  =   0x0;
    qmssInitConfig.maxDescNum       =  num_descriptors;

#if RM
    if (rmServiceHandle)
        qmssGblCfgParams.qmRmServiceHandle = rmServiceHandle;
#endif
    /* Initialize the Queue Manager */
    fw_qmssGblCfgParams = &qmssGblCfgParams;

    result = Qmss_init (&qmssInitConfig, fw_qmssGblCfgParams);
    if (result != QMSS_SOK)
    {
        return -1;
    }

    /* Start Queue manager on this core */
    Qmss_start ();

    /*Setup the descriptor memory regions. 
     *
     * The Descriptor base addresses MUST be global addresses and
     * all memory regions MUST be setup in ascending order of the
     * descriptor base addresses.
     */

     gHostDesc = (uint8_t*) p_hwAttrs->p_desc_base;
    /* Initialize and setup CPSW Host Descriptors required for example */
    memset (gHostDesc, 0, EMAC_SIZE_HOST_DESC * num_descriptors);
    memCfg.descBase             =   (uint32_t *) p_hwAttrs->local2GlobalAddr((uint32_t) gHostDesc);
    memCfg.descSize             =   EMAC_SIZE_HOST_DESC;
    memCfg.descNum              =   num_descriptors;
    memCfg.manageDescFlag       =   Qmss_ManageDesc_MANAGE_DESCRIPTOR;
    memCfg.memRegion            =   p_hwAttrs->qmssMemoryRegion;
    memCfg.startIndex           =   0;

    /* Insert Host Descriptor memory region */
    memoryRegion = (Qmss_MemRegion)Qmss_insertMemoryRegion(&memCfg);
    if (memoryRegion < QMSS_SOK)
    {
        return EMAC_DRV_RESULT_OPEN_PORT_ERR;
    }    

    /* Initialize all the descriptors we just allocated on the
     * memory region above. Setup the descriptors with some well
     * known values before we use them for data transfers.
     */
    memset (&cppiDescCfg, 0, sizeof (cppiDescCfg));
    cppiDescCfg.queueGroup      =   0;

    cppiDescCfg.memRegion       =   (Qmss_MemRegion)memoryRegion;
    cppiDescCfg.descNum         =   num_descriptors;
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
    cppiDescCfg.epibPresent                 =   Cppi_EPIB_NO_EPIB_PRESENT;
    
    /* Initialize the descriptors, create a free queue and push descriptors to a global free queue */
    if ((EMAC_GLOBAL_FREE_QUEUE= Cppi_initDescriptor (&cppiDescCfg, &numAllocated)) <= 0)
    {
        return -1;
    }
   
    /* Queue Manager Initialization Done */
    return EMAC_DRV_RESULT_OK;
}

/** ============================================================================
 *   @n@b emac_deinit_qmss
 *
 *   @b Description
 *   @n This function de-initializes the QMSS LLD.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */

int32_t emac_deinit_qmss(uint32_t port_num)
{
    int32_t i;
    uint32_t count;
    Cppi_Desc*        pCppiDesc = NULL;
    Cppi_HostDesc*    pHostDesc = NULL;
    uintptr_t                      *appPtr;
    EMAC_PKT_DESC_T*       p_rx_pkt_desc;
    
    count = Qmss_getQueueEntryCount(EMAC_GLOBAL_RX_QUEUE_HND);

    for (i =0; i < count;i++)
    {
        emac_qmss_qpop(EMAC_GLOBAL_RX_QUEUE_HND, (Cppi_HostDesc**) (&pCppiDesc));

        pHostDesc = (Cppi_HostDesc *)pCppiDesc;
        if(pHostDesc == NULL)
        {
            break;
        }
        appPtr = (uintptr_t *)(((char *)pHostDesc) + EMAC_SIZE_HOST_DESC - sizeof(*appPtr));
        /* Update the software desciptor being passed to application */
        p_rx_pkt_desc = (EMAC_PKT_DESC_T*) *appPtr;
        p_rx_pkt_desc->BufferLen = pHostDesc->buffLen;
        /* Call the callback */
        EMAC_RX_PKT(0, (EMAC_PKT_DESC_T*)*appPtr);
    }

    count = Qmss_getQueueEntryCount(EMAC_GLOBAL_RX_FREE_QUEUE_HND);
    for (i =0; i < count;i++)
    {
        emac_qmss_qpop(EMAC_GLOBAL_RX_FREE_QUEUE_HND, (Cppi_HostDesc**) (&pCppiDesc));
     }

    count = Qmss_getQueueEntryCount(EMAC_GLOBAL_TX_FREE_QUEUE_HND);
    for (i =0; i < count;i++)
    {
        emac_qmss_qpop(EMAC_GLOBAL_TX_FREE_QUEUE_HND, (Cppi_HostDesc**) (&pCppiDesc));
     }

    count = Qmss_getQueueEntryCount(EMAC_GLOBAL_TX_RETURN_QUEUE_HND);
    for (i =0; i < count;i++)
    {
        emac_qmss_qpop(EMAC_GLOBAL_TX_RETURN_QUEUE_HND, (Cppi_HostDesc**) (&pCppiDesc));
     }
    Qmss_queueClose(EMAC_GLOBAL_FREE_QUEUE);
    Qmss_queueClose(EMAC_GLOBAL_TX_FREE_QUEUE_HND);
    Qmss_queueClose(EMAC_GLOBAL_RX_QUEUE_HND);
    Qmss_queueClose(EMAC_GLOBAL_RX_FREE_QUEUE_HND);
    Qmss_queueClose(EMAC_GLOBAL_TX_RETURN_QUEUE_HND);

    for (i = 0; i <NSS_NUM_TX_QUEUES; i ++)
    {
        Qmss_queueClose(EMAC_GLOBAL_TX_QUEUE_HND(i));
    }

    Qmss_removeMemoryRegion(memoryRegion,0U);
    Qmss_exit();
    return 0;    

    
}
/** ============================================================================
 *   @n@b emac_setup_tx_subsysem
 *
 *   @b Description
 *   @n This function sets up all relevant data structures and configuration required
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
 int32_t emac_setup_tx_subsysem (uint32_t port_num,
                                                            EMAC_OPEN_CONFIG_INFO_T* p_config,
                                                            EMAC_HwAttrs_V1       *hwAttrs)
{
    uint8_t                     isAllocated;
    uint32_t                    i;
    Qmss_Queue                  qRetInfo;
    Cppi_Desc*                           pCppiDesc;

    /* Open all Transmit (Tx) queues. 
     *
     * These queues are used to send data to PA PDSP/CPSW.
     */
    for (i = 0; i <NSS_NUM_TX_QUEUES; i ++)
    {
        if ((EMAC_GLOBAL_TX_QUEUE_HND( i)  = Qmss_queueOpen (Qmss_QueueType_PASS_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
            
        {
            //printf ("Error opening PA Tx queue, err:%d \n", EMAC_GLOBAL_TX_QUEUE_HND( i));
            return -1;
        }
    }

    /* Open a Tx Free Descriptor Queue (Tx FDQ). 
     *
     * This queue will be used to hold Tx free decriptors that can be filled
     * later with data buffers for transmission onto wire.
     */
    if ((EMAC_GLOBAL_TX_FREE_QUEUE_HND = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        return -1;
    }

    /* Open a Tx Return Descriptor Queue (Tx Transmit CompletionQ).
     *
     * This queue will be used to hold Tx completed decriptors that can be filled
     * later with data buffers for transmission onto wire.
     */
    if ((EMAC_GLOBAL_TX_RETURN_QUEUE_HND = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        return -1;
    }

    qRetInfo = Qmss_getQueueNumber (EMAC_GLOBAL_TX_RETURN_QUEUE_HND);


    /* Attach some free descriptors to the Tx free queue we just opened. */
    for (i=0; i < p_config->num_of_tx_pkt_desc;i++)
    {
        /* Get a free descriptor from the global free queue we setup 
         * during initialization above
         */

        if ((emac_qmss_qpop (EMAC_GLOBAL_FREE_QUEUE, (Cppi_HostDesc **)&pCppiDesc )) != 0)
        {
            break;
        }

        /* Setup the Completion queue:
         *
         * Setup the return policy for this desc to return to the free q we just
         * setup instead of the global free queue.
         */
        Cppi_setReturnQueue ((Cppi_DescType) Cppi_DescType_HOST, pCppiDesc, qRetInfo);

        /* Push descriptor to Tx free queue */
         emac_qmss_qpush_descsize (EMAC_GLOBAL_TX_FREE_QUEUE_HND, pCppiDesc, EMAC_SIZE_HOST_DESC);
    }
    if (i != p_config->num_of_tx_pkt_desc)
    {
        return -1;
    }
    EMAC_NUM_TX_PKTS(port_num) = p_config->num_of_tx_pkt_desc;

    /* All done with Rx configuration. Return success. */
    return 0;
}



int32_t emac_setup_rx_queue_internal(uint32_t port_num,
                                Qmss_Queue *rxQInfo)
{
    uint8_t                       isAllocated;
    {
    
        /* Open a Receive (Rx) queue.
         *
         * This queue will be used to hold all the packets received by PASS/CPSW
         *
         * Open the next available Qmss_QueueType_RECEIVE_QUEUE for RX.
         */
        if ((EMAC_GLOBAL_RX_QUEUE_HND = Qmss_queueOpen (Qmss_QueueType_RECEIVE_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
        
        {
            //printf ("Error opening a Rx queue \n");
            return -1;
        }
        *rxQInfo = Qmss_getQueueNumber (EMAC_GLOBAL_RX_QUEUE_HND);
    }
    
    /* Open a Divert queue.
     *
     * This queue will be used to hold the unsent packets from other queues to check
     * the number of pending bytes and packets 
     *
     */
    if ((EMAC_GLOBAL_DIV_QUEUE_HND= Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, EMAC_RX_QUEUE_NUM_INIT + 1, &isAllocated)) < 0)
    {
        //printf ("Error opening a Divert queue \n");
        return -1;
    }

    return (0);
}



/** ============================================================================
 *   @n@b emac_setup_rx_subsysem
 *
 *   @b Description
 *   @n This API sets up all relevant data structures and configuration required
 *      for receiving data from NSS/Ethernet. It sets up a Rx free descriptor queue
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
 int32_t emac_setup_rx_subsysem (uint32_t port_num,
                                                            EMAC_OPEN_CONFIG_INFO_T* p_config,
                                                            EMAC_HwAttrs_V1       *hwAttrs)
{
    uint8_t                     isAllocated;
    uint32_t                    i;
    Qmss_Queue                  rxFreeQInfo, rxQInfo;
    Cppi_Desc*                           pCppiDesc;
    Cppi_RxFlowCfg              rxFlowCfg;
    EMAC_PKT_DESC_T*                        p_rx_pkt_desc;
    uintptr_t                      *appPtr;
  

    /* Initialize with defaults */
    Osal_RegisterInterrupt_initParams(&interruptRegParams);
    
    if ((emac_setup_rx_queue_internal(port_num, &rxQInfo)) < 0)
    {
        //printf (" Error in setting up receive queue information\n");
        return -1;
    }

   interruptRegParams.corepacConfig.arg  = (uintptr_t)port_num;

#ifdef _TMS320C6X
         /* Populate the interrupt parameters */
    interruptRegParams.corepacConfig.corepacEventNum = rxQInfo.qNum + hwAttrs->eventIdOffset; /* idOffset is 7 for K2G */;
#else
    interruptRegParams.corepacConfig.corepacEventNum = 0;
#endif
    interruptRegParams.corepacConfig.priority = 15;

    /* for arm, hwAttrs->intNum should be CSL_ARM_GIC_NSS_QPEND0 + 32, evenId should be 0 */

    interruptRegParams.corepacConfig.intVecNum = hwAttrs->intNum;
    interruptRegParams.corepacConfig.isrRoutine = EMAC_v1_hwiFxn;
    
    EMAC_osalRegisterInterrupt(&interruptRegParams,&(EMAC_GLOBAL_RX_HWI_HANDLE(port_num)));

    if (EMAC_GLOBAL_RX_HWI_HANDLE(port_num) == NULL )
    {
        return -1;
    }
    /* Open a Rx Free Descriptor Queue (Rx FDQ). 
     *
     * This queue will hold all the Rx free decriptors. These descriptors will be
     * used by the NSS CPDMA to hold data received via CPSW.
     */
    if ((EMAC_GLOBAL_RX_FREE_QUEUE_HND = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
    {
        return -1;
    }
    rxFreeQInfo = Qmss_getQueueNumber (EMAC_GLOBAL_RX_FREE_QUEUE_HND);
    /* Attach some free descriptors to the RX free queue we just opened. */
    for (i = 0; i < p_config->num_of_rx_pkt_desc; i++)
    {
        /* Get a free descriptor from the global free queue we setup 
         * during initialization.
         */

        if ((emac_qmss_qpop (EMAC_GLOBAL_FREE_QUEUE, (Cppi_HostDesc **)&pCppiDesc )) != 0)
        {
            break;
        }

        /* The descriptor address returned from the hardware has the 
         * descriptor size appended to the address in the last 4 bits.
         *
         * To get the true descriptor size, always mask off the last 
         * 4 bits of the address.
         */
        
#ifdef EXT_DEBUG
        //printf ("@Alloc Time:%d, pCppiDesc:%x \n", i, pCppiDesc);
#endif
        /* Allocate a buffer/descriptor from the application */
        if ((p_rx_pkt_desc = p_config->alloc_pkt_cb(port_num, p_config->max_pkt_size)) == NULL)
        {
           printf (" Failed to allocate data buffer for the Rx Descriptor\n");
           /* need to do cleanup and return error */
        }
        /* Populate the Rx free descriptor with the buffer we just allocated. */
        Cppi_setData (Cppi_DescType_HOST,
                            pCppiDesc, (uint8_t *)hwAttrs->local2GlobalAddr((uint32_t)p_rx_pkt_desc->pDataBuffer),p_rx_pkt_desc->BufferLen);

        /* Save original buffer information */
       
        Cppi_setOriginalBufInfo (Cppi_DescType_HOST, pCppiDesc, 
                            (uint8_t *)hwAttrs->local2GlobalAddr((uint32_t)p_rx_pkt_desc->pDataBuffer),p_rx_pkt_desc->BufferLen);

        /* Setup the Completion queue:
         *
         * Setup the return policy for this desc to return to the free q we just
         * setup instead of the global free queue.
         */
        Cppi_setReturnQueue (Cppi_DescType_HOST, pCppiDesc, rxFreeQInfo);
        appPtr = (uintptr_t *)(((char *)pCppiDesc) + EMAC_SIZE_HOST_DESC - sizeof(*appPtr));
        *appPtr =(uintptr_t)p_rx_pkt_desc;

        Cppi_setPacketLen    (Cppi_DescType_HOST, pCppiDesc, p_rx_pkt_desc->BufferLen);
        
        /* Push descriptor to Rx free queue */
        emac_qmss_qpush_descsize (EMAC_GLOBAL_RX_FREE_QUEUE_HND, pCppiDesc, EMAC_SIZE_HOST_DESC);

    }
    if (i != p_config->num_of_rx_pkt_desc)
    {
        //printf ("Error allocating Rx free descriptors \n");
        return -1;
    }
        EMAC_NUM_RX_PKTS(port_num) = p_config->num_of_rx_pkt_desc;


    /* Setup a Rx Flow.
     *
     * A Rx flow encapsulates all relevant data properties that CPDMA would
     * have to know in order to succefully receive data.
     */
    /* Initialize the flow configuration */
    memset (&rxFlowCfg, 0, sizeof(Cppi_RxFlowCfg));
    rxFreeQInfo = Qmss_getQueueNumber (EMAC_GLOBAL_RX_FREE_QUEUE_HND);

    rxFlowCfg.flowIdNum             =   0;

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
    if ((EMAC_GLOBAL_CPPI_FLOW_HND = Cppi_configureRxFlow (EMAC_CPDMA_GLOBAL_HND, &rxFlowCfg, &isAllocated)) == NULL)
    {
        //printf ("Error configuring Rx flow \n");
        return -1;
    }

    /* All done with Rx configuration. Return success. */
    return 0;
}


/** ============================================================================
 *   @n@b emac_init_cppi
 *
 *   @b Description
 *   @n This API initializes the CPPI LLD, opens the NSS CPDMA and opens up
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
 int32_t emac_init_cppi (uint32_t port_num,
                                            EMAC_OPEN_CONFIG_INFO_T* p_config,
                                            EMAC_HwAttrs_V1* p_hwAttrs)
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


    fw_cppiGblCfgParams = cppiGblCfgParams;
    /* Initialize CPPI LLD */
    result = Cppi_init (&fw_cppiGblCfgParams);
    if (result != CPPI_SOK)
    {
        return -1;
    }

#if RM
     if (rmServiceHandle)
     {
        cppiStartCfg.rmServiceHandle = rmServiceHandle;
        Cppi_startCfg(&cppiStartCfg);
     }
#endif
    /* Initialize NSS CPDMA */
    memset (&cpdmaCfg, 0, sizeof (Cppi_CpDmaInitCfg));
    cpdmaCfg.dmaNum     = Cppi_CpDma_PASS_CPDMA;
    if ((EMAC_CPDMA_GLOBAL_HND  = Cppi_open (&cpdmaCfg)) == NULL)
    {
        return -1;
    }

    /* Open all CPPI Tx Channels. These will be used to send data to NSS/CPSW */
    for (i = 0; i < NSS_NUM_TX_PKTDMA_CHANNELS; i ++)

    {
        txChCfg.channelNum      =   i;       /* CPPI channels are mapped one-one to the PA Tx queues */
        txChCfg.txEnable        =   Cppi_ChState_CHANNEL_DISABLE;  /* Disable the channel for now. */
        txChCfg.filterEPIB      =   0;
        txChCfg.filterPS        =   0;
        txChCfg.aifMonoMode     =   0;
        txChCfg.priority        =   2;
        if ((EMAC_CPDMA_TX_CHAN_HND(i) = Cppi_txChannelOpen (EMAC_CPDMA_GLOBAL_HND, &txChCfg, &isAllocated)) == NULL)
        {
            return -1;
        }
        Cppi_channelEnable(EMAC_CPDMA_TX_CHAN_HND( i));
    }

    /* Open all CPPI Rx channels. These will be used by PA to stream data out. */
    for (i = 0; i <NSS_NUM_RX_PKTDMA_CHANNELS; i++)
    {
        /* Open a CPPI Rx channel that will be used by PA to stream data out. */
        rxChInitCfg.channelNum  =   i; 
        rxChInitCfg.rxEnable    =   Cppi_ChState_CHANNEL_DISABLE; 
        if ((EMAC_CPDMA_RX_CHAN_HND(i) = Cppi_rxChannelOpen (EMAC_CPDMA_GLOBAL_HND, &rxChInitCfg, &isAllocated)) == NULL)
        {
            return -1;
        }
        Cppi_channelEnable (EMAC_CPDMA_RX_CHAN_HND(i));
    }


    /* Clear CPPI Loobpack bit in NSS CDMA Global Emulation Control Register if loopback config is disabled */
    if (p_config->loop_back == 0)
        Cppi_setCpdmaLoopback(EMAC_CPDMA_GLOBAL_HND, 0);

    return 0;
}

/** ============================================================================
 *   @n@b emac_deinit_cppi
 *
 *   @b Description
 *   @n This local function de-initializes the  CPPI  resouces allocated during emac_open()
 *
 *   @param[in]  
 *   @n port_num port number
 * 
 *   @return    int32_t
 *              0       -   Success
 * =============================================================================
*/
int32_t emac_deinit_cppi (uint32_t port_num)
{
    int32_t i;
    
    for (i = 0; i < NSS_NUM_TX_PKTDMA_CHANNELS; i ++)
    {
        Cppi_channelClose(EMAC_CPDMA_TX_CHAN_HND(i));
    }
    /* Close all CPPI Rx channels */
    for (i = 0; i <NSS_NUM_RX_PKTDMA_CHANNELS; i++)
    {
        Cppi_channelClose(EMAC_CPDMA_RX_CHAN_HND(i));
    }

    Cppi_close(EMAC_CPDMA_GLOBAL_HND);
    Cppi_exit();
    return 0;

}
