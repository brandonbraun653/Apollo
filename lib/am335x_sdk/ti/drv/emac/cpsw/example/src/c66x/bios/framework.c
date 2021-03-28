/**
 * @file framework.c
 *
 * @brief
 *  This file holds all the platform specific framework
 *  initialization and setup code.
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

#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_psc.h>
#include <ti/csl/csl_pscAux.h>

//#define PASS_TEST_TX_CMD
/* High Priority Accumulation Interrupt Service Handler for this application */
void Cpsw_RxISR (void);

/* Constructed data packet to send. */
#pragma DATA_ALIGN(pktMatch, 16)
uint8_t pktMatch[] = {
							0x10, 0x11, 0x12, 0x13, 0x14, 0x15,                      /* Dest MAC */
                            0x00, 0x01, 0x02, 0x03, 0x04, 0x05,                      /* Src MAC  */
                            0x08, 0x00,                                              /* Ethertype = IPv4 */
                            0x45, 0x00, 0x00, 0x6c,                                  /* IP version, services, total length */
                            0x00, 0x00, 0x00, 0x00,                                  /* IP ID, flags, fragment offset */
                            0x05, 0x11, 0x32, 0x26,                                  /* IP ttl, protocol (UDP), header checksum */
                            0xc0, 0xa8, 0x01, 0x01,                                  /* Source IP address */
                            0xc0, 0xa8, 0x01, 0x0a,                                  /* Destination IP address */
                            0x12, 0x34, 0x56, 0x78,                                  /* UDP source port, dest port */
                            0x00, 0x58, 0x1d, 0x18,                                  /* UDP len, UDP checksum */
                            0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39,          /* 80 bytes of payload data */
                            0x3a, 0x3b, 0x3c, 0x3d, 0x3e, 0x3f, 0x40, 0x41,
                            0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,
                            0x4a, 0x4b, 0x4c, 0x4d, 0x4e, 0x4f, 0x50, 0x51,
                            0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
                            0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x5f, 0x60, 0x61,
                            0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69,
                            0x6a, 0x6b, 0x6c, 0x6d, 0x6e, 0x6f, 0x70, 0x71,
                            0x72, 0x73, 0x74, 0x75, 0x76, 0x77, 0x78, 0x79,
                            0x7a, 0x7b, 0x7c, 0x7d, 0x7e, 0x7f, 0x80, 0x81  };

uint8_t * DataBufAlloc(void)
{
    uint8_t* pDataBuffer = NULL;
    if ((pDataBuffer = (Ptr) Memory_alloc(NULL, PA_EMAC_EX_RXBUF_SIZE, 0, NULL)) == NULL)
    {
        System_printf ("Error allocating memory for Rx data buffer \n");
    }
    return (pDataBuffer);
}

/* Free Attached Buffers */
void DataBufFree(void* pDataBuffer, uint32_t size)
{
	Memory_free(NULL, pDataBuffer, size);
}

/** ============================================================================
 *   @n@b Convert_CoreLocal2GlobalAddr
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
uint32_t Convert_CoreLocal2GlobalAddr (uint32_t  addr)
{
	uint32_t coreNum;

    /* Get the core number. */
    coreNum = CSL_chipReadReg(CSL_CHIP_DNUM);

    /* Compute the global address. */
    return ((1 << 28) | (coreNum << 24) | (addr & 0x00ffffff));
}

/** ============================================================================
 *   @n@b Convert_CoreGlobal2L2Addr
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
uint32_t Convert_CoreGlobal2L2Addr (uint32_t  addr)
{
    /* Compute the local l2 address. */
    return (addr & 0x00ffffff);
}

/** ============================================================================
 *   @n@b get_qmssGblCfgParamsRegsPhy2Virt
 *
 *   @b Description
 *   @n This API updates the QMSS global configuration registers to global
 *      addressable space for that platform.
 *
 *   @param[in]
 *   @n addr            L2 address to be converted to global.
 *
 *   @return    uint32_t
 *   @n >0              Global L2 address
 * =============================================================================
 */
void get_qmssGblCfgParamsRegsPhy2Virt(Qmss_GlobalConfigParams     *fw_qmssGblCfgParams)
{
	/* Since all physical memory is accessible in DSP, nothing to be done */
	return;
}

/** ============================================================================
 *   @n@b get_cppiGblCfgParamsRegsPhy2Virt
 *
 *   @b Description
 *   @n This API updates the QMSS global configuration registers to global
 *      addressable space for that platform.
 *
 *   @param[in]
 *   @n addr            L2 address to be converted to global.
 *
 *   @return    uint32_t
 *   @n >0              Global L2 address
 * =============================================================================
 */
void get_cppiGblCfgParamsRegsPhy2Virt(Cppi_GlobalConfigParams     *fw_cppiGblCfgParams)
{
	/* Since all physical memory is accessible in DSP, nothing to be done */
	return;
}

Bool                                    gIsPingListUsed = 0;
uint8_t                                 accChannelNum;
/* High Priority Accumulator List - [((Interrupt Threshold + 1) * 2)]
 *
 * MUST be 16 byte aligned.
 *
 * The High priority accumulator list consists of 2 buffers Ping and
 * Pong each consisting of the following entries:
 *
 * (1)  Entry count -   specifies number of packets accumulated in
 *                      the list.
 * (2)  Descriptors -   an array of Rx packet descriptors accumulated
 *                      in this list.
 *
 * Hence the size of high priority accumulator list is calculated as
 * follows:
 *
 * (1)  Get the interrupt threshold, i.e., maximum number of Rx
 *      packets to accumulate before an interrupt is generated.
 * (2)  Add an extra entry to the threshold to track
 *      entry count of the list.
 * (3)  Double this to accomodate space for Ping/Pong lists.
 * (4)  Each accumulator entry is 4 bytes wide.
 *
 * size =   ((interrupt threshold + 1) * 2) * 4 bytes
 *
 * Lets allocate here assuming that interrupt threshold is 1, i.e.,
 * interrupt on every Rxed packet.
 */
#pragma DATA_ALIGN (gHiPriAccumList, 16)
uint32_t                                  gHiPriAccumList[(RX_INT_THRESHOLD + 1) * 2];

extern Qmss_QueueHnd gRxQHnd;

int32_t setup_rx_queue(Qmss_Queue *rxQInfo)
{

    uint8_t                       isAllocated;

#ifndef NSS_LITE
    Qmss_AccCmdCfg                accCfg;
    uint16_t                      numAccEntries, intThreshold;
    Qmss_Result                   result;
    int32_t                       eventId, vectId;
  	uint8_t                       coreNum = (uint8_t) CSL_chipReadReg(CSL_CHIP_DNUM);

	//if (linuxBoot == FALSE)
	if (1)
	{

	   /* Open a Receive (Rx) queue.
		*
		* This queue will be used to hold all the packets received by PASS/CPSW
		*
		* Open the next available High Priority Accumulation queue for Rx.
		*/
	   if ((gRxQHnd = Qmss_queueOpen (Qmss_QueueType_HIGH_PRIORITY_QUEUE, QMSS_PARAM_NOT_SPECIFIED, &isAllocated)) < 0)
	   {
		   System_printf ("Error opening a High Priority Accumulation Rx queue \n");
		   return -1;
	   }
	   *rxQInfo = Qmss_getQueueNumber (gRxQHnd);

       /* Setup high priority accumulation interrupts on the Rx queue.
        *
        * Let's configure the accumulator with the following settings:
        *      (1) Interrupt pacing disabled.
        *      (2) Interrupt on every received packet
        */
       intThreshold    =   RX_INT_THRESHOLD;
       numAccEntries   =   (intThreshold + 1) * 2;
       accChannelNum   =   PA_ACC_CHANNEL_NUM + coreNum;
   
       /* Initialize the accumulator list memory */
       memset ((void *) gHiPriAccumList, 0, numAccEntries * 4);

       /* Setup the accumulator settings */
       accCfg.channel             =   accChannelNum;
       accCfg.command             =   Qmss_AccCmd_ENABLE_CHANNEL;
       accCfg.queueEnMask         =   0;
       accCfg.listAddress         =   Convert_CoreLocal2GlobalAddr((uint32_t) gHiPriAccumList);
       accCfg.queMgrIndex         =   Qmss_getQIDFromHandle(gRxQHnd);
       accCfg.maxPageEntries      =   (intThreshold + 1); /* Add an extra entry for holding the entry count */
       accCfg.timerLoadCount      =   0;
       accCfg.interruptPacingMode =   Qmss_AccPacingMode_LAST_INTERRUPT;
       accCfg.listEntrySize       =   Qmss_AccEntrySize_REG_D;
       accCfg.listCountMode       =   Qmss_AccCountMode_ENTRY_COUNT;
       accCfg.multiQueueMode      =   Qmss_AccQueueMode_SINGLE_QUEUE;

       /* Program the accumulator */
       if ((result = Qmss_programAccumulator (Qmss_PdspId_PDSP1, &accCfg)) != QMSS_ACC_SOK)
       {
           System_printf ("Error Programming high priority accumulator for channel : %d queue : %d error code : %d\n",
                        accCfg.channel, accCfg.queMgrIndex, result);
           return -1;
       }

       /* Register interrupts for the system event corresponding to the
        * accumulator channel we are using.
        */
       /* System event 48 - Accumulator Channel 0 */
       eventId     	=   48;
   
       /* Pick a interrupt vector id to use */
       vectId          =   7;
   
       /* Register our ISR handle for this event */
       EventCombiner_dispatchPlug (eventId, (EventCombiner_FuncPtr)Cpsw_RxISR, (UArg)NULL, TRUE);
   
   	   /* Map the combiner's output event id (evevtId/32) to hardware interrupt 8. */
       /* The HW int 8 is slected via CM.eventGroupHwiNum[] specified at cpsw_example.cfg */
       Hwi_eventMap(vectId, 1);
   
       /* Enable interrupt 8. */
       Hwi_enableInterrupt(vectId);
	}
	else 
#endif    
    {
    
    	/* Open a Receive (Rx) queue.
         *
         * This queue will be used to hold all the packets received by PASS/CPSW
         *
         * Open the next available High Priority Accumulation queue for Rx.
         */
        if ((gRxQHnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, RX_QUEUE_NUM_INIT, &isAllocated)) < 0)
        {
            System_printf ("Error opening a Rx queue \n");
            return -1;
        }
        *rxQInfo = Qmss_getQueueNumber (gRxQHnd);		
	}
    
    /* Open a Divert queue.
     *
     * This queue will be used to hold the unsent packets from other queues to check
     * the number of pending bytes and packets 
     *
     */
    if ((gDivQHnd = Qmss_queueOpen (Qmss_QueueType_GENERAL_PURPOSE_QUEUE, RX_QUEUE_NUM_INIT + 1, &isAllocated)) < 0)
    {
        System_printf ("Error opening a Divert queue \n");
        return -1;
    }

    return (0);

}

#ifndef NSS_LITE
/** ============================================================================
 *   @n@b Cpsw_RxISR
 *
 *   @b Description
 *   @n This API is the example application's High Priority Accumulation interrupt
 *      Service Handler (ISR). This API is called in interrupt context. This API
 *      fetches the Received packet (descriptor) from the accumulator list and
 *      verifies the data received to ensure that it is correct. On success,
 *      this API recycles the Rx descriptor back to Rx free queue for use again.
 *      This API processes the Ping and Pong accumulator lists alternatively.
 *
 *   @param[in]
 *   @n None
 *
 *   @return
 *   @n None
 * =============================================================================
 */
void Cpsw_RxISR (void)
{
    Cppi_Desc*                  pCppiDesc;
    uint32_t                  	count, i;

    /* Process ISR.
     *
     * Get the number of entries in accumulator list.
	 * The hardware enqueues data alternatively to Ping/Pong buffer lists in
     * the accumulator. Hence, we need to track which list (Ping/Pong)
     * we serviced the last time and accordingly process the other one
     * this time around.
     */
     if (!gIsPingListUsed)
     {
		/* Serviced Pong list last time. So read off the Ping list now */
    	count   =   gHiPriAccumList[0];
     }
     else
     {
		/* Serviced Ping list last time. So read off the Pong list now */
    	count   =   gHiPriAccumList[RX_INT_THRESHOLD + 1];
     }

    /* Process all the Results received
     *
     * Skip the first entry in the list that contains the
     * entry count and proceed processing results.
     */
    for (i = 1; i <= count; i ++)
    {
        /* Get the result descriptor.
         *
         * The hardware enqueues data alternatively to Ping/Pong buffer lists in
         * the accumulator. Hence, we need to track which list (Ping/Pong)
         * we serviced the last time and accordingly process the other one
         * this time around.
         */
        if (!gIsPingListUsed)
        {
            /* Serviced Pong list last time. So read off the Ping list now */
            pCppiDesc   =   (Cppi_Desc *) gHiPriAccumList [i];
        }
        else
        {
            /* Serviced Ping list last time. So read off the Pong list now
             *
             * Skip over Ping list length to arrive at Pong list start.
             */
            pCppiDesc   =   (Cppi_Desc *) gHiPriAccumList [i + RX_INT_THRESHOLD + 1];
        }

        /* Descriptor size appended to the address in the last 4 bits.
         *
         * To get the true descriptor size, always mask off the last
         * 4 bits of the address.
         */
	    pCppiDesc = (Ptr) ((uint32_t) pCppiDesc & 0xFFFFFFF0);

        VerifyPacket (pCppiDesc, dest_emac_port_id);
    }

    /* Clear the accumulator list and save whether we used Ping/Pong
     * list information for next time around.
     */
    if (!gIsPingListUsed)
    {
        /* Just processed Ping list */
        gIsPingListUsed  =   1;

        /* Clear the accumulator list after processing */
        memset ((void *) &gHiPriAccumList [0], 0, sizeof (uint32_t) * (RX_INT_THRESHOLD + 1));
    }
    else
    {
        /* Just processed Pong list */
        gIsPingListUsed  =   0;

        /* Clear the accumulator list after processing */
        memset ((void *) &gHiPriAccumList[RX_INT_THRESHOLD + 1], 0, sizeof (uint32_t) * (RX_INT_THRESHOLD + 1));
    }

	/* Clear INTD */
	Qmss_ackInterrupt(accChannelNum, 1);
	Qmss_setEoiVector(Qmss_IntdInterruptType_HIGH, accChannelNum);

    /* Done processing interrupt. Return */
    return;
}

#endif

/***************************************************************************************
 * FUNCTION PURPOSE: Power up PA subsystem
 ***************************************************************************************
 * DESCRIPTION: this function powers up the PA subsystem domains
 ***************************************************************************************/
void passPowerUp (void)
{

#ifndef NSS_LITE
    /* PASS power domain is turned OFF by default. It needs to be turned on before doing any
     * PASS device register access. This not required for the simulator. */

    /* Set PASS Power domain to ON */
    CSL_PSC_enablePowerDomain (CSL_PSC_PD_NETCP);

    /* Enable the clocks for PASS modules */
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_PA, PSC_MODSTATE_ENABLE);
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_CPGMAC,  PSC_MODSTATE_ENABLE);
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_SA,  PSC_MODSTATE_ENABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_NETCP);
    
    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_NETCP));
    
#else

    /* Set NSS Power domain to ON */        
    CSL_PSC_enablePowerDomain (CSL_PSC_PD_NSS);

    /* Enable the clocks for NSS modules */
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_NSS, PSC_MODSTATE_ENABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_NSS);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_NSS));
    
    /* Set SA Power domain to ON */        
    CSL_PSC_enablePowerDomain (CSL_PSC_PD_SA);

    /* Enable the clocks for SA modules */
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_SA, PSC_MODSTATE_ENABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_SA);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_SA));
    
#endif
}

/** ============================================================================
 *   @n@b SendPacket
 *
 *   @b Description
 *   @n This API is called to actually send out data onto wire using ethernet.
 *      On success, this API increments a global Tx counter to indicate the same.
 *
 *   @param[in]
 *   @n None
 *
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t SendPacket (int emac_dest_port)
{
    Cppi_Desc*      pCppiDesc;
    uint32_t        dataBufferSize;
    char            psFlags = (cpswSimTest)?EMAC_PORT_NOT_SPECIFIED:(char)(emac_dest_port + EMAC_PORT_0);
#ifdef PASS_TEST_TX_CMD
    paCmdInfo_t     cmdInfo;
    uint32_t        cmdBuf[4];
    uint16_t        cmdSize = sizeof(cmdBuf);
    
    paCmdNextRoute_t routeCmdEth = {
                                    #ifndef NSS_GEN2
                                    0,              /*  ctrlBitfield */
                                    #else
                                    pa_NEXT_ROUTE_RPT_TX_TIMESTAMP,
                                    #endif
                                    pa_DEST_EMAC,   /* Route - host       */
                                    0,              /* pktType don't care */
                                    0,              /* flow Id              */
                                    0,  			/* Queue                */
                                    0,              /* SWInfo 0             */
                                    0,              /* SWInfo 1 */       
                                    0               /* multiRouteIndex (not used) */
                                 };   
    
    routeCmdEth.pktType_emacCtrl = psFlags;
#if defined(NSS_GEN2)    
    routeCmdEth.swInfo0 = EMAC_FORMAT_REPORT_TIMESTAMP_INFO(0x88, 0x5, (uint16_t)gTxCounter); 
#endif    
    
    /* Command : Next route */
    cmdInfo.cmd = pa_CMD_NEXT_ROUTE;
    cmdInfo.params.route = routeCmdEth;
#else
    Cppi_DescTag    tag;
#endif    
    
    /* Get a free descriptor from the global free queue we setup
     * during initialization.
     */
    if ((pCppiDesc = Qmss_queuePop (gTxFreeQHnd)) == NULL)
    {
        System_printf ("No Tx free descriptor. Cant run send/rcv test \n");
        return -1;
    }

    /* The descriptor address returned from the hardware has the
     * descriptor size appended to the address in the last 4 bits.
     *
     * To get the true descriptor size, always mask off the last
     * 4 bits of the address.
     */
    pCppiDesc = (Ptr) ((uint32_t) pCppiDesc & 0xFFFFFFF0);

    dataBufferSize  =   sizeof (pktMatch);
    Cppi_setData (  Cppi_DescType_HOST,
                    (Cppi_Desc *) pCppiDesc,
                    (uint8_t *) Convert_CoreLocal2GlobalAddr((uint32_t)pktMatch),
                    dataBufferSize
                 );
    Cppi_setPacketLen (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, dataBufferSize);
    
#ifndef PASS_TEST_TX_CMD

#if 0
    /* Force the packet to the specific EMAC port */
    if (!nssGblCfgParams.layout.fNssGen2)
    {
        Cppi_setPSFlags(Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, psFlags);
    }
    else
#endif
    {
        Cppi_HostDesc   *descPtr = (Cppi_HostDesc *) pCppiDesc;
        descPtr->softwareInfo0 = EMAC_FORMAT_REPORT_TIMESTAMP_INFO(0x88, 0x5, (uint16_t)gTxCounter);
        
        tag.srcTagHi  = 0;
        tag.srcTagLo  = 0;
        tag.destTagHi = 0;
        tag.destTagLo = psFlags;
        Cppi_setTag(Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, (Cppi_DescTag *)&tag);
    }
    
    /* Clear PS Data */
    Cppi_setPSLen (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, 0);
    
	/* Send the packet out the mac. It will loop back to NSS if the mac/switch
     * have been configured properly
     */

#if 0
    #ifndef NSS_LITE 
    if (no_bootMode == TRUE)
    	Qmss_queuePush (gPaTxQHnd[nssGblCfgParams.layout.qCpswEthIndex], pCppiDesc, dataBufferSize, SIZE_HOST_DESC, Qmss_Location_TAIL);
    else {
        Qmss_queuePush (gPaTxQHnd[nssGblCfgParams.layout.qPaInputIndex], pCppiDesc, dataBufferSize, SIZE_HOST_DESC, Qmss_Location_TAIL);
    }
    #else
#endif
    	Qmss_queuePush (gPaTxQHnd[NSS_CPSW_QUEUE_ETH_INDEX_LITE], pCppiDesc, dataBufferSize, SIZE_HOST_DESC, Qmss_Location_TAIL);
    
#endif
    
#else
    Pa_formatTxCmd (  1,        /* nCmd */
                      &cmdInfo,  /* command info */
                      0,        /* offset */
                      (Ptr)&cmdBuf[0],          /* Command buffer       */
                      &cmdSize);    /* Command size         */
    
    /* Attach the command in PS data */
    Cppi_setPSData (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, (uint8_t *)cmdBuf, cmdSize);
    
    Cppi_setPSFlags(Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, 0);
    
    Qmss_queuePush (gPaTxQHnd[nssGblCfgParams.layout.qPaTxCmdIndex], pCppiDesc, dataBufferSize, SIZE_HOST_DESC, Qmss_Location_TAIL);
    
    #endif
    
    /* Increment the application transmit counter */
    gTxCounter ++;

    /* Give some time for the PA to process the packet */
    CycleDelay (10000);

    return 0;
}

#ifdef NSS_LITE
/** ============================================================================
 *   @n@b ReceivePacket
 *
 *   @b Description
 *   @n This API is called to Receive packets.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
int32_t ReceivePacket (void)
{
	Cppi_Desc           *hd;
	int32_t             j;
    int32_t             status=0;
    extern              Qmss_QueueHnd gRxQHnd;
    
	/* Wait for a data packet from PA */
    for (j = 0; j < 100; j++)  
    {
      CycleDelay (1000);
      if (Qmss_getQueueEntryCount (gRxQHnd) > 0)   
      {
        hd = (Cppi_Desc *)(((uint32_t)Qmss_queuePop (gRxQHnd)) & ~0xf);
        if(VerifyPacket(hd,  dest_emac_port_id) != 0)
            status=-1;
      }
    } 
    
    return (status);
}

#endif

/** ============================================================================
 *   @n@b VerifyPacket
 *
 *   @b Description
 *   @n This API verifies a packet received against the expected data and 
 *      returns 0 to inidcate success and -1 to indicate a mismatch.
 *
 *   @param[in]  
 *   @n pCppiDesc           Packet descriptor received.
 * 
 *   @return    int32_t
 *              -1      -   Error
 *              0       -   Success
 * =============================================================================
 */
 
int32_t VerifyPacket (Cppi_Desc* pCppiDesc, int emac_dest_port)
{
	Cppi_HostDesc               *pHostDesc;
	uint8_t                     *pDataBuffer;
	int32_t                      i;
    #ifndef NSS_LITE
	uint32_t		      	     infoLen;
	pasahoLongInfo_t 	        *pinfo;
    uint8_t                      portNum;
    #endif
	
    pHostDesc = (Cppi_HostDesc *)pCppiDesc;
       
    #ifndef NSS_LITE
       
    /* Verify the application software info we received is same
     * as what we had sent earlier.
     */
    if (pHostDesc->softwareInfo0 != 0xaaaaaaaa)  
    {
        System_printf ("VerifyPacket: Found an entry in receive queue with swinfo0 = 0x%08x, expected 0x%08x\n", 
                        pHostDesc->softwareInfo0, 0xaaaaaaaa);
                   
        pHostDesc->buffLen = pHostDesc->origBufferLen;
        Qmss_queuePush (gRxFreeQHnd, (Ptr)pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);
          
        return -1;
    }
    
	/* Get the parse information, make sure there is an L4 offset */
	if (Cppi_getPSData (Cppi_DescType_HOST, Cppi_PSLoc_PS_IN_DESC, (Cppi_Desc *)pHostDesc, (uint8_t **)&pinfo, &infoLen) != CPPI_SOK)  {
		System_printf ("VerifyPacket: Error getting control info from received data packet\n");
		return (-1);
	}
    else if(!cpswSimTest)
    {
    	/* do not check the port number if linux boot is true */
        if (no_bootMode == TRUE)
        {
    	   /* Verify the input port number */
           portNum = PASAHO_LINFO_READ_INPORT(pinfo);
        
           if (portNum != (pa_EMAC_PORT_0 + emac_dest_port))
           {
		       System_printf ("VerifyPacket: receive packet from unexpected EMAC PORT %d (expected %d)\n", portNum - 1, emac_dest_port);
               System_flush();
           }
        }
    }
    
    #endif
    
    /* Verify the packet matches what we had sent */
    pDataBuffer = (uint8_t *) pHostDesc->buffPtr;
    for (i = 42; i < sizeof (pktMatch); i++)  
    {
        if (pktMatch[i] != pDataBuffer[i])  
        {
            System_printf ("VerifyPacket: Byte %d expected 0x%02x, found 0x%02x\n", i, pktMatch[i], pDataBuffer[i]);
            System_flush();

            /* Free the packet back to the Rx FDQ */
            pHostDesc->buffLen = pHostDesc->origBufferLen;
            Qmss_queuePush (gRxFreeQHnd, (Ptr)pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);
            return -1;
        }
    }
    
    if (1)
    {
        uint32_t   rxTimestamp, rxTimestampMSW;
        CSL_CPTS_EVENTINFO         cptsEventInfo;
    
        /* Extract Rx timestamps from the packet */
        Cppi_getTimeStamp (Cppi_DescType_HOST, (Cppi_Desc *)pHostDesc, &rxTimestamp);
        #ifndef NSS_LITE
        rxTimestampMSW = PASAHO_LINFO_READ_TSTAMP_MSB(pinfo); 
        #else
        rxTimestampMSW =  pHostDesc->softwareInfo0;
        #endif
    
        /* Extract Tx Timestamp from CPTS event */
        CSL_CPTS_getEventInfo(&cptsEventInfo);
        CSL_CPTS_popEvent(); 
    
        System_printf ("pkt %d: Rx timestamp 0x%08x%08x; Tx timestamp 0x%08x%08x\n", cptsEventInfo.seqId, rxTimestampMSW, rxTimestamp, cptsEventInfo.timeStampHi, cptsEventInfo.timeStamp);
    }    
        
    //System_printf ("Packet Received Verified Successfully!\n");
       
    /* Increment Rx counter to indicate the number of successfully
     * received packets by the example app.
     */
    gRxCounter ++;
    

    /* Reset the buffer lenght and put the descriptor back on the free queue */    
    pHostDesc->buffLen = pHostDesc->origBufferLen;
    Qmss_queuePush (gRxFreeQHnd, (Ptr)pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);


    /* Verify packet done. Return success. */
	return 0;
}

#ifndef NSS_LITE
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
int32_t Download_PAFirmware (void)
{

    extern Pa_Handle                               gPAInstHnd;
    
    int i;
    
    /* Hold the PA in reset state during download */
    Pa_resetControl (gPAInstHnd, pa_STATE_RESET);

    
	for ( i = 0; i < nssGblCfgParams.layout.numPaPdsps; i++)
    {
    
        Pa_downloadImage (gPAInstHnd, i, 
                          (Ptr)nssGblCfgParams.layout.paPdspImage[i], 
                          nssGblCfgParams.layout.paPdspImageSize[i]);
    }

    /* Enable the PA back */
    Pa_resetControl (gPAInstHnd, pa_STATE_ENABLE);

    return 0;
}

#endif

void CycleDelay (int32_t count)
{
    uint32_t                  TSCLin;

    if (count <= 0)
        return;

    /* Get the current TSCL  */
    TSCLin = TSCL ;

    while ((TSCL - TSCLin) < (uint32_t)count);
}

void APP_exit (int32_t code)
{
	BIOS_exit(code);
}

/* Nothing past this point */
