/**  
 * @file cpsw_rateLimit_test.c
 *
 *   @n This example verifies the CPSW rate limit feature. It demostrates how to 
 *      configure the CPSW for rate limiting operation and then generates traffic 
 *      patterns to the CPSW according to the test scenario and then meausre the 
 *      bandwidth of the received packet stream per priority against the expected 
 *      results since the CPSW is set to internal or external loopback mode.
 *
 * @brief 
 *  Example to illustrate the usage of EMAC CPSW switch to perform egress traffic 
 *  rate limiting using CPPI, QMSS low level drivers and CSL.
 *
 * 	This example application does the following:
 * 	    (1) Initializes:
 * 	            (a) Queue Manager (QM) Subsystem 
 * 	            (b) Packet Accelerator (PA) CPPI DMA 
 * 	            (c) Ethernet Subsystem (Ethernet switch + CPTS + SGMII/RGMII + MDIO) 
 *                  - (Note: Applicable only for NO_BOOT mode)
 *
 * 	    (2) Sets up the CPPI descriptors and Queues required for sending and
 * 	        receiving data using Ethernet.
 * 	            (a) Uses Host descriptors
 *
 * 	    (3) Run CPSW rate limit test scenarios, for each test scenario
 *          - configure CPSW rate limit control registers
 *          - prepare and send multiple packet streams and process
 *            receive packets. Record Tx and Rx packet information.
 *          - Calculate the bandwidth of each receive data stream and
 *            verify against expected result.
 *
 *      (4) Clear all resources           
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2015, Texas Instruments, Inc.
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
#include <ti/board/board.h>
#include <ti/drv/emac/example/cpswRateLimitExample/src/cpsw_rateLimit_test.h>
#include <stdio.h>

/**************************************************************
************************** DEFINITIONS ************************
***************************************************************/
/*
 * Default test configuration for the silicon
 *
 * To run test at the CCS simulator
 *    cpswSimTest = 1
 *    cpswLpbkMode = CPSW_LOOPBACK_INTERNAL
 */
#ifdef  SIMULATOR_SUPPORT
int cpswSimTest = 1;
int cpswLpbkMode = CPSW_LOOPBACK_INTERNAL;
#else
int cpswSimTest = 0;
int cpswLpbkMode = CPSW_LOOPBACK_INTERNAL;
#endif

#ifdef __LINUX_USER_SPACE
uint32_t no_bootMode = FALSE;
/* Linux Specific global variables per process */
sock_h                 rmClientSocket;
sem_t                  mutex;
#else
uint32_t no_bootMode = TRUE;
#endif

#define DESC_ID_OFFSET         16

/* Define test packet templates, one per packet stream (priority) */

/* 
 * packet 0: priority 0
 * mac dest = 0a:0b:0c:0d:0e:0f
 */                         
static uint8_t pkt0[1518] = {
        0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x81, 0x00,                                       /* Ethertype = VLAN */
        0x0a, 0xaa,                                       /* VLAN ID = 0xaaa, PCP = 0 */
        0x00,                                             /* Group Id = priority */
        };    
        
/* 
 * packet 1: priority 1
 * mac dest = 0a:0b:0c:0d:0e:0f
 */                         
static uint8_t pkt1[1518] = {
        0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x81, 0x00,                                       /* Ethertype = VLAN */
        0x2a, 0xaa,                                       /* VLAN ID = 0xaaa, PCP = 0 */
        0x01,                                             /* Group Id = priority */
        };    
        
/* 
 * packet 2: priority 2
 * mac dest = 0a:0b:0c:0d:0e:0f
 */                         
static uint8_t pkt2[1518] = {
        0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x81, 0x00,                                       /* Ethertype = VLAN */
        0x4a, 0xaa,                                       /* VLAN ID = 0xaaa, PCP = 0 */
        0x02,                                             /* Group Id = priority */
        };    
        
/* 
 * packet 3: priority 3
 * mac dest = 0a:0b:0c:0d:0e:0f
 */                         
static uint8_t pkt3[1518] = {
        0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x81, 0x00,                                       /* Ethertype = VLAN */
        0x6a, 0xaa,                                       /* VLAN ID = 0xaaa, PCP = 0 */
        0x03,                                             /* Group Id = priority */
        };    
        
/* 
 * packet 4: priority 4
 * mac dest = 0a:0b:0c:0d:0e:0f
 */                         
static uint8_t pkt4[1518] = {
        0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x81, 0x00,                                       /* Ethertype = VLAN */
        0x8a, 0xaa,                                       /* VLAN ID = 0xaaa, PCP = 0 */
        0x04,                                             /* Group Id = priority */
        };    
/* 
 * packet 5: priority 5
 * mac dest = 0a:0b:0c:0d:0e:0f
 */                         
static uint8_t pkt5[1518] = {
        0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x81, 0x00,                                       /* Ethertype = VLAN */
        0xaa, 0xaa,                                       /* VLAN ID = 0xaaa, PCP = 0 */
        0x05,                                             /* Group Id = priority */
        };    
        
/* 
 * packet 6: priority 6
 * mac dest = 0a:0b:0c:0d:0e:0f
 */                         
static uint8_t pkt6[1518] = {
        0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x81, 0x00,                                       /* Ethertype = VLAN */
        0xca, 0xaa,                                       /* VLAN ID = 0xaaa, PCP = 0 */
        0x06,                                             /* Group Id = priority */
        }; 
        
/* 
 * packet 7: priority 7
 * mac dest = 0a:0b:0c:0d:0e:0f
 */                         
static uint8_t pkt7[1518] = {
        0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f,               /* Dest MAC */
        0x00, 0xe0, 0xa6, 0x66, 0x57, 0x04,               /* Src MAC  */
        0x81, 0x00,                                       /* Ethertype = VLAN */
        0xea, 0xaa,                                       /* VLAN ID = 0xaaa, PCP = 0 */
        0x07,                                             /* Group Id = priority */
        };    
        
static uint8_t* testPkt[MAX_PKT_GEN_INSTANCES] =
{
    pkt0,
    pkt1,
    pkt2,
    pkt3,
    pkt4,
    pkt5,
    pkt6,
    pkt7
};    

/************************ GLOBAL VARIABLES ********************/
    
           
uint32_t core_speed  = CORE_SPEED;                        /* Initialize system clock to be the default value */
                                                          /* core_speed should be set to the actual system clock
                                                             before the test starts if it is not the default value */
pktGenEngList_t pktGenEngList;                            /* Packet generate engine list */
pktGenEngState_t pktGenEngStates[MAX_PKT_GEN_INSTANCES];  /* Packet generate engines */

/* Error counter */
uint32_t                  errorCount = 0;

/************************ EXTERN VARIABLES ********************/
extern   Qmss_QueueHnd gRxQHnd;

/** ============================================================================
 *   @n@b read_timer64
 *
 *   @b Description
 *   @n Utility function to get 64 bit timer
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return    uint64_t: timer value
 *               
 * =============================================================================
 */
static inline uint64_t read_timer64 ()
{
    uint32_t low = TSCL;
    uint32_t high = TSCH;
    return _itoll (high, low);
}

/** ============================================================================
 *   @n@b queue_divert_and_check
 *
 *   @b Description
 *   @n Utility function to move all entries from the source queue to the
 *      destination queue with error check.
 *
 *   @param[in]   src       The source queue handle
 *   @param[in]   dst       The destination queue handle
 * 
 *   @return    None
 * =============================================================================
 */
static void queue_divert_and_check (Qmss_QueueHnd src, Qmss_QueueHnd dst)
{
    Qmss_Result result;

    if ((result = Qmss_queueDivert (src, dst, Qmss_Location_TAIL)) != QMSS_SOK)
    {
        UInt32 corenum = CSL_chipReadReg(CSL_CHIP_DNUM); 
        errorCount++;
        System_printf("core %d: queue divert from %d to %d failed: %d\n", corenum, src, dst, result);
    }
}

/** ============================================================================
 *   @n@b pkt_gen_reinsert_engine
 *
 *   @b Description
 *   @n Utility function to Insert engine #idx into list based on updated head 
 *      engine's nextTime
 *      destination queue with error check.
 *
 *   @param[in]   
 *   @n None   
 * 
 *   @return    None
 * =============================================================================
 */
static void pkt_gen_reinsert_engine (void)
{
    uint32_t *list = pktGenEngList.idx;
    int      tableEnd = pktGenEngList.numPresent;
    uint32_t headIdx = list[0];
    uint64_t val = pktGenEngStates[headIdx].nextTime;
    uint32_t idx;

    /* Shift list and insert head back into correct location based on nextTime */
    for (idx = 1; idx < tableEnd; idx++)
    {
        if (val > pktGenEngStates[list[idx]].nextTime)
        {
            list[idx - 1] = list[idx];
        }
        else 
        {
            break;
        }
    }
    list[idx - 1] = headIdx;
}

/** ============================================================================
 *   @n@b ScenReceivePacket
 *
 *   @b Description
 *   @n This API is called to process Rx packets.
 *
 *   @param[in] fRecordTime    flag to indicate whether to record the packet 
 *                             receiving time
 *   @return    int32_t        
 *              1       -   One packet is received
 *              0       -   No packet received
 * =============================================================================
 */
int32_t ScenReceivePacket (int fRecordTime)
{
	Cppi_HostDesc       *pHostDesc;
    uint32_t outIdx;
    uint8_t*  pDataBuffer;
    
    /* Can only pop with size if something is there, else can
     * get 0 for size and a pointer for the next desc! */
    if (Qmss_getQueueEntryCount (gRxQHnd))
    {
        pHostDesc = (Cppi_HostDesc *)(((uint32_t)Qmss_queuePop (gRxQHnd)) & ~0xf);
        pDataBuffer = (uint8_t *) pHostDesc->buffPtr;
        
        if (fRecordTime)
        {
            outIdx = pDataBuffer[DESC_ID_OFFSET];
            pktGenEngStates[outIdx].packetsRx++;
            pktGenEngStates[outIdx].bytesRx += pHostDesc->buffLen;
            pktGenEngStates[outIdx].lastRxTime = read_timer64();
        }
    
        /* Reset the buffer lenght and put the descriptor back on the free queue */    
        pHostDesc->buffLen = pHostDesc->origBufferLen;
        Qmss_queuePush (gRxFreeQHnd, (Ptr)pHostDesc, pHostDesc->buffLen, SIZE_HOST_DESC, Qmss_Location_TAIL);
        
        return (1);
    }
    
    /* Verify packet done. Return success. */
	return 0;
}

/** ============================================================================
 *   @n@b sendScenarioModel
 *
 *   @b Description
 *   @n Execute use case scenarios as defined at the packet generation 
 *      configuration structure.
 *      - Prepare and generate the packet streams accodingly
 *      - Process receive packets
 *      - Record Tx and Rx packet information
 *
 *   @param[in]   pktGen        The traffic generation configuration
 *   @param[in]   startTime_p   The place to record traffic start time
 * 
 *   @return    
 *   @n None
 * =============================================================================
 */
void sendScenarioModel (packetGenCfg_t *pktGen, uint64_t *startTime_p)
{
    int gen;
    Cppi_Desc*          pCppiDesc;
    pktGenEngState_t    *genState;
    packetGenInstCfg_t  *genCfg;
    uint64_t            startTime, genEndTime, sampTime, thisTime, nextPlayTime, backlogTime;
    uint32_t            pktSize;
    Cppi_DescTag        tag;

    /* Generate the packets while simutaneosly checking the results */
    *startTime_p = startTime = read_timer64();

    pktGenEngList.numPresent = 0;
#if defined(RATE_LIMIT_FAST_SCENARIO)
    pktGen->genTime /= 100;
    pktGen->readTime /= 100;
#endif

    for (gen = 0; gen < MAX_PKT_GEN_INSTANCES; gen++)
    {
        genState = &pktGenEngStates[gen];
        genCfg   = &pktGen->inst[gen];
        
        if(genCfg->pps == 0)
            continue;
        
        genState->nextTime     = startTime;
        genState->deltaTime    = core_speed / genCfg->pps;
        genState->sizeIdx      = 0;
        genState->packetsRx    = 0;
        genState->bytesRx      = 0;
        genState->bytesTx      = 0;
        genState->packetsTx    = 0;
        genState->packetsYanked = 0;
        genState->packetsDropped = 0;
        genState->outputQ = gPaTxQHnd[NSS_CPSW_QUEUE_ETH_INDEX_LITE + gen];
        genState->pkt = testPkt[gen];
        pktGenEngList.idx[pktGenEngList.numPresent++] = gen;

        /* Check that valid sizes are given */
        if (genCfg->sizeMode == packet_GEN_SIZE_MODE_RANDOM)
        {
            if ((genCfg->nSizes != 2) || 
                (genCfg->pktSize[0] > genCfg->pktSize[1]))
            {
                System_printf("found invalid size mode configuration for gen %d\n", gen);
            }
        }
    }

    /* Generate the packets while simutaneosly checking the results */
    genEndTime   = startTime + (uint64_t)(core_speed / 1000) * pktGen->genTime;
    sampTime     = startTime + (uint64_t)(core_speed / 1000) * pktGen->readTime;
    nextPlayTime = startTime;
    genState     = &pktGenEngStates[pktGenEngList.idx[0]];
    genCfg       = &pktGen->inst[pktGenEngList.idx[0]];
    
    tag.srcTagHi  = 0;
    tag.srcTagLo  = 0;
    tag.destTagHi = 0;
    backlogTime   = 0;
                
    while ( ((thisTime = read_timer64()) < genEndTime) && (thisTime < sampTime))
    {
        /* Should we send packet on first (soonest) engine? */
        if (thisTime > nextPlayTime)
        {
            if((thisTime - nextPlayTime) > backlogTime)
                backlogTime = thisTime - nextPlayTime;
            
            if (Qmss_getQueueEntryCount (genState->outputQ) <= 5)
            {
                /* Get a free descriptor */
                if ((pCppiDesc = Qmss_queuePop (gTxFreeQHnd)) == NULL)
                {
                    System_printf ("No Tx free descriptor. Cant run sendScenarioModel \n");
                    break;
                }
            
                /* Decide the "size" of the packet (no real data is DMAd) */
                if (genCfg->sizeMode == packet_GEN_SIZE_MODE_ROUND_ROBIN)
                {
                    pktSize = genCfg->pktSize[genState->sizeIdx++];
                    if (genState->sizeIdx >= genCfg->nSizes)
                    {
                        genState->sizeIdx = 0;
                    }
                }
                else
                {
                    pktSize = (rand() % (genCfg->pktSize[1] - genCfg->pktSize[0])) + 
                                genCfg->pktSize[0];
                }
            
                /* The descriptor address returned from the hardware has the
                * descriptor size appended to the address in the last 4 bits.
                *
                * To get the true descriptor size, always mask off the last
                * 4 bits of the address.
                */
                pCppiDesc = (Ptr) ((uint32_t) pCppiDesc & 0xFFFFFFF0);

                Cppi_setData (  Cppi_DescType_HOST,
                                (Cppi_Desc *) pCppiDesc,
                                (uint8_t *) Convert_CoreLocal2GlobalAddr((uint32_t)genState->pkt),
                                pktSize
                            );
                Cppi_setPacketLen (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, pktSize);
        
                /* Clear PS Data */
                //Cppi_setPSLen (Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, 0);
                
                tag.destTagLo = EMAC_PORT_0;
                Cppi_setTag(Cppi_DescType_HOST, (Cppi_Desc *)pCppiDesc, (Cppi_DescTag *)&tag);
    
	            /* Send the packet out the mac. */
                Qmss_queuePush (genState->outputQ, pCppiDesc, pktSize, SIZE_HOST_DESC, Qmss_Location_TAIL);
            
                /* stats */
                genState->packetsTx ++;
                genState->bytesTx += pktSize;
            }
            else
            {
                /* There is no room to insert new packets */
                genState->packetsDropped++;
            }

            /* Reschedule the engine */
            genState->nextTime += genState->deltaTime;
            pkt_gen_reinsert_engine ();
            
            /* setup next generator */
            genState     = &pktGenEngStates[pktGenEngList.idx[0]];
            genCfg       = &pktGen->inst[pktGenEngList.idx[0]];
            nextPlayTime = genState->nextTime;
        }
        
        /* Try to drain the input */
        ScenReceivePacket (1);
    }
    
    /* Wait for sample time */
    while ( ((thisTime = read_timer64()) < sampTime))
    {
        ScenReceivePacket (1);
    }

    /* Remove any remaining input */
    for (gen = 0; gen < MAX_PKT_GEN_INSTANCES; gen++)
    {
        uint32_t bytes, entries;
        
        /* Skip unused channel */
        if(pktGen->inst[gen].pps == 0)
            continue; 
        
        queue_divert_and_check (pktGenEngStates[gen].outputQ, gDivQHnd);
        bytes = Qmss_getQueueByteCount (gDivQHnd);
        entries = Qmss_getQueueEntryCount (gDivQHnd);
        pktGenEngStates[gen].bytesTx -= bytes;
        pktGenEngStates[gen].packetsTx -= entries;
        pktGenEngStates[gen].packetsYanked += entries;
        queue_divert_and_check (gDivQHnd, gTxFreeQHnd);
    }

    /* Drain rest of output */
    CycleDelay (10000);
    while (ScenReceivePacket(0));

    if (backlogTime > 250000)
    {
        System_printf ("NOTE: packet generator got behind by 0x%x%08x cycles\n",
                       (uint32_t)(backlogTime >> 32), (uint32_t)backlogTime);
    }
}  /* sendScenarioModel */

/** ============================================================================
 *   @n@b scenario_test
 *
 *   @b Description
 *   @n Execute each test scenario and check its results 
 *
 *   @param[in]   
 *   @n None
 * 
 *   @return    
 *   @n None
 * =============================================================================
 */
void scenario_test (void)
{
    packetGenCfg_t      pktGen;
    UInt32              corenum = CSL_chipReadReg(CSL_CHIP_DNUM); 
    int                 i, gen;
    packetGenInstCfg_t  *genCfg;
    pktGenEngState_t    *genState;
    uint64_t            startTime;
    uint32_t            actRxTimeMs;

    /* Read BOOTCFG_EFUSE_BOOTROM to determine core clock speed for EVM_K2G*/
#ifndef ICE_K2G
    core_speed = Board_getDEVSPEED() * 1000000;
#endif
    for (i = 0; rateLimitTestScenCfgs[i].fcn; i++)
    {
        /* Run the test case */
        System_printf ("Core %d: Running scenario %d: %s\n", corenum, i + 1, rateLimitTestScenCfgs[i].desc);
        System_flush();
        
        memset(&pktGen, 0, sizeof(pktGen));
        
        /* Test test scenario configuration */
        if (rateLimitTestScenCfgs[i].fcn (&pktGen))
        {
            errorCount++;
            continue;
        }
        
        /* Run the model */
        sendScenarioModel (&pktGen, &startTime);

        /* Check results */
        for (gen = 0; gen < MAX_PKT_GEN_INSTANCES; gen++)
        {
            uint32_t                actBPS;
            uint32_t                actError;

            genState = &pktGenEngStates[gen];
            genCfg   = &pktGen.inst[gen];
            
            /* Skip unused channel */
            if(genCfg->pps == 0)
                continue; 
            

            /* Check BPS */
            actRxTimeMs = (genState->lastRxTime - startTime) / (core_speed/1000);

            /* This reduces rounding error when packets go at low rate */
            if (actRxTimeMs < pktGen.genTime)
            {
                actRxTimeMs = pktGen.genTime;
            }
            actBPS = ((((uint64_t)genState->packetsRx * (ENET_DATA_PACKET_OVHD - 4)) + genState->bytesRx) * 8000) / actRxTimeMs;
            actError = abs(genCfg->bpsExp - actBPS);
            System_printf ("Core %d : stream %d : found %d bps, expected %d bps, error %d, allowed %d ", 
                           corenum, gen, actBPS, genCfg->bpsExp, actError, genCfg->bpsError);
                           
#ifndef SIMULATOR_SUPPORT
            if (actError > genCfg->bpsError)
            {
                System_printf ("(*** FAIL ***)\n");
                errorCount++;
            }
            else
            {
                System_printf ("(PASS)\n");
            }
#else
            System_printf ("(*** Timing check skipped on simulator ***)\n");
#endif

        }
        
        System_flush();

    }
} /* scenario_test */

/**************************************************************
**************** EXAMPLE APP FUNCTIONS ************************
***************************************************************/


/** ============================================================================
 *   @n@b Cpsw_RateLimitTestApp
 *
 *   @b Description
 *   @n Example application that sets up the application, run the rate limit
 *      test scenarios and then clear all resources.
 *
 *   @param[in]  
 *   @n None
 * 
 *   @return
 *   @n None
 *
 * =============================================================================
 */
#ifdef __LINUX_USER_SPACE
void* Cpsw_RateLimitTestApp (void *args)
#else
void Cpsw_RateLimitTestApp (void)
#endif
{

    System_printf ("**************************************************\n");
    System_printf ("********** CPSW Rate Limit Test Starts ***********\n");
    System_printf ("**************************************************\n");
    System_flush();

#if RM
    if (setupRm ())
    {
      System_printf ("Function setupRm failed\n");
      System_flush();
      return;
    }
#endif

    /* Initialize the components required to run the example:
     *  (1) QMSS
     *  (2) CPPI
     *  (3) Ethernet switch subsystem + MDIO + SGMII
     */
    
    /* Initialize QMSS */
    if (Init_Qmss () != 0)
    {
        System_printf ("QMSS init failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("QMSS successfully initialized \n");
        System_flush();
    }

    /* Initialize CPPI */
    if (Init_Cppi () != 0)
    {
        System_printf ("CPPI init failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("CPPI successfully initialized \n");
        System_flush();
    }
 
#ifndef __LINUX_USER_SPACE
    if (no_bootMode == TRUE)
    {
        /* Initialize the CPSW switch */
        if (Init_Cpsw () != 0)
        {
            System_printf ("Ethernet subsystem init failed \n");
            System_flush();
            APP_exit (-1);
        }
        else
        {
            System_printf ("Ethernet subsystem successfully initialized \n");
            System_flush();
        }
    }
#endif

    /* Setup Tx */
    if (Setup_Tx () != 0)
    {
        System_printf ("Tx setup failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("Tx setup successfully done \n");
        System_flush();
    }

    /* Setup Rx */
    if (Setup_Rx () != 0)
    {
        System_printf ("Rx setup failed \n");
        System_flush();
        APP_exit (-1);
    }
    else
    {
        System_printf ("Rx setup successfully done \n");
        System_flush();
    }
    
    System_printf ("Running CPSW Rate Limit Scenarios!\n");
    System_flush();
    
    /* run all test scenarios */
    scenario_test ();

    if(!errorCount)
        System_printf("All tests have passed!\n");
    System_printf ("**************************************************\n");
    System_printf ("*********** CPSW Rate Limit Test Ends ************\n");
    System_printf ("**************************************************\n");
    System_flush();

    /* Clear framework */
	if (clearFramework() < 0) 
	{
        System_printf ("Failed to Clean the example application \n");
        System_flush();
	}

#if (RM) && !defined(__LINUX_USER_SPACE)
    {
        int32_t rmResult;

        if ((rmResult = Rm_resourceStatus(rmHandle, FALSE)) != 0)
        {
            System_printf ("Error : Number of unfreed resources : %d\n", rmResult);
            System_flush();
        }
        else
        {
            System_printf ("All resources freed successfully\n");
            System_flush();
        }
    }
#endif
    /* Example application done. Return success */
    APP_exit (0);
}

/* Nothing past this point */

