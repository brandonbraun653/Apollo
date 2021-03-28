/******************************************************************************
 * Copyright (c) 2016-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/
/**
 *  \file   emac_test.c
 *
 *  \brief  emac diagnostic test file
 *
 *  Targeted Functionality: Verification of basic functionality of
 *  Ethernet interface.
 *
 *  Operation: This is the Loopback test code for the Ethernet Interface.
 *  The test code showcases usage of the EMAC Driver exported API for
 *  sending/receiving Ethernet packets.
 *
 *  Supported SoCs: K2G, AM65XX & J721E.
 *
 *  Supported Platforms: iceK2G, am65xx_evm, am65xx_idk & j721e_evm.
 *
 */

/* Test application local header file */
#include "emac_test.h"

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
#if defined(SOC_K2G)
uint32_t baseAddr          = (CSL_NSS_0_CFG_REGS + 0x00200F00);
uint8_t  phyAddrs          = BOARD_GIGABIT_EMAC_PHY_ADDR;
uint8_t  maxEmacRegDump    = BOARD_GIGABIT_EMAC_REG_DUMP_MAX;
uint32_t emacStrapSts1Addr = BOARD_GIGABIT_EMAC_STRAP_STS1_ADDR;
uint32_t emacStrapSts2Addr = BOARD_GIGABIT_EMAC_STRAP_STS2_ADDR;
uint8_t  gHostDesc[EMAC_SIZE_HOST_DESC * APP_NUM_HOST_DESC] __attribute__ ((aligned (128)));
#else
uint32_t baseAddr          = (CSL_MCU_CPSW0_NUSS_BASE + 0x0F00);
uint8_t  phyAddrs          = BOARD_MCU_EMAC_PHY_ADDR;
uint8_t  maxEmacRegDump    = BOARD_MCU_EMAC_REG_DUMP_MAX;
uint32_t emacStrapSts1Addr = BOARD_MCU_EMAC_STRAP_STS1_ADDR;
uint32_t emacStrapSts2Addr = BOARD_MCU_EMAC_STRAP_STS2_ADDR;
/* TX/RX ring entries memory */



/*
 * UDMA driver objects
 */
struct Udma_DrvObj      gUdmaDrvObj;
struct Udma_ChObj       gUdmaTxChObj[EMAC_MAX_PORTS][4];
struct Udma_ChObj       gUdmaRxChObj[EMAC_MAX_PORTS][4];
struct Udma_EventObj    gUdmaRxCqEventObj[EMAC_MAX_PORTS][4];

Udma_DrvHandle          gDrvHandle = NULL;


uint8_t  app_pkt_buffer[APP_TOTAL_PKTBUF_SIZE] __attribute__ ((aligned (128)));
/* TX/RX ring entries memory */
uint8_t  gTxRingMem[EMAC_MAX_PORTS][RING_TRSIZE * RING_TRCNT] __attribute__ ((aligned (CACHE_LINESZ)));
uint8_t  gTxCompRingMem[EMAC_MAX_PORTS][RING_TRSIZE * RING_TRCNT] __attribute__ ((aligned (CACHE_LINESZ)));
uint8_t  gRxRingMem[EMAC_MAX_PORTS][RING_TRSIZE * RING_TRCNT] __attribute__ ((aligned (CACHE_LINESZ)));
uint8_t  gRxCompRingMem[EMAC_MAX_PORTS][RING_TRSIZE * RING_TRCNT] __attribute__ ((aligned (CACHE_LINESZ)));

/* TX/RX ring CPPI descriptor memory */
uint8_t gUdmapDescRamTx[RING_TRCNT][UDMAP_DESC_SIZE] __attribute__ ((aligned (CACHE_LINESZ)));
uint8_t gUdmapDescRamRx[RING_TRCNT][UDMAP_DESC_SIZE] __attribute__ ((aligned (CACHE_LINESZ)));
#endif
uint8_t  app_pkt_buffer[APP_TOTAL_PKTBUF_SIZE] __attribute__ ((aligned (128)));
static uint32_t pkt_rcv_count = 0;
volatile uint32_t pkt_rcvd = 0;
uint32_t timeout;
uint32_t gTxPktCount     = 0;
uint32_t linkCheckTime   = 0;
uint32_t linkUp          = 0;

APP_EMAC_MCB_T   app_mcb;
EMAC_LINK_INFO_T link_info;
EMAC_MAC_ADDR_T macTest;

/**********************************************************************
 ****************** Test Configuration Variables **********************
 **********************************************************************/

static const uint8_t test_pkt[TEST_PKT_SIZE] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* broadcast mac */
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x08, 0x06, 0x00, 0x01,
    0x08, 0x00, 0x06, 0x04, 0x00,0x01,
    0x01, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0xc0, 0xa8, 0x01, 0x16,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xa8,0x01, 0x02,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0x01,0x02,0x03,0x04,
    0xfe,0xfe
};


/**********************************************************************
 ************************ EMAC TEST FUNCTIONS *************************
 **********************************************************************/

/**
 * \brief  Ethernet control power up function
 *
 */
static void BoardDiag_ethCtrlPowerUp(void)
{
#if defined(SOC_K2G)
    /* PASS power domain is turned OFF by default. It needs to be turned
     * on before doing any PASS device register access.
	 * This not required for the simulator. */

    /* Set NSS Power domain to ON */
    CSL_PSC_enablePowerDomain (CSL_PSC_PD_NSS);

    /* Enable the clocks for NSS modules */
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_NSS, PSC_MODSTATE_ENABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_NSS);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_NSS));
#else
    /* MAXIE_TBD:Need to update the power up configs for AM65X */
#endif
}

/**
 * \brief  Ethernet control power down function
 *
 */
static void BoardDiag_ethCtrlPowerDown(void)
{
#if defined(SOC_K2G)
    /* PASS power domain is turned OFF by default. It needs to be turned
     * on before doing any PASS device register access.
	 * This not required for the simulator. */

    /* Set NSS Power domain to ON */
    CSL_PSC_disablePowerDomain (CSL_PSC_PD_NSS);

    /* Enable the clocks for NSS modules */
    CSL_PSC_setModuleNextState (CSL_PSC_LPSC_NSS, PSC_MODSTATE_DISABLE);

    /* Start the state transition */
    CSL_PSC_startStateTransition (CSL_PSC_PD_NSS);

    /* Wait until the state transition process is completed. */
    while (!CSL_PSC_isStateTransitionDone (CSL_PSC_PD_NSS));
#else
    /* MAXIE_TBD:Need to update the power down configs for AM65X */
#endif
}

/**
 * \brief  Application queue pop function
 *
 * Dequeues a packet descriptor from an app queue.
 *
 * \param   port_num    [IN]      EMAC port number
 *          pq          [IN/OUT]  Packet queue
 *
 * \return  EMAC_Pkt popped from the queue
 *
 */
static EMAC_PKT_DESC_T* BoardDiag_appQueuePop(uint32_t port_num,
                                              APP_PKT_QUEUE_T   *pq)
{
    EMAC_PKT_DESC_T *pPktHdr;

    if (!pq->Count)
    {
        return 0;
    }

    pPktHdr = pq->pHead;
    if( pPktHdr )
    {
        pq->pHead = pPktHdr->pNext;
        pq->Count--;
        pPktHdr->pPrev = pPktHdr->pNext = 0;
    }

    return( pPktHdr );
}

/**
 * \brief  Application queue push function
 *
 * Enqueues a packet in EMAC_Pkt queue.
 *
 * \param   port_num    [IN]        EMAC port number
 *          pq          [OUT]       Packet queue
 *          pPktHdr     [IN]        Packet to push
 *
 */
static void BoardDiag_appQueuePush(uint32_t port_num, APP_PKT_QUEUE_T *pq,
                                   EMAC_PKT_DESC_T *pPktHdr)
{
    pPktHdr->pNext = 0;

    if( !pq->pHead )
    {
        /* Queue is empty - Initialize it with this one packet */
        pq->pHead = pPktHdr;
        pq->pTail = pPktHdr;
    }
    else
    {
        /* Queue is not empty - Push onto end */
        pq->pTail->pNext = pPktHdr;
        pq->pTail        = pPktHdr;
    }

    pq->Count++;
}

/**
 * \brief  Allocate packet descriptor function
 *
 * This function gets packet from the free Queue and returns to the application
 *
 * \param   port_num  [IN]  EMAC port number
 *          pkt_size  [IN]  size of the packet
 *
 * \return   pointer to the allocated packet descriptor.
 *
 */
EMAC_PKT_DESC_T* BoardDiag_AppAllocPkt(uint32_t  port_num, uint32_t pkt_size)
{
    EMAC_PKT_DESC_T    *p_pkt_desc = NULL;

    if (pkt_size < APP_EMAC_MAX_PKT_SIZE)
    {
        /* Get a packet descriptor from the free queue */
        p_pkt_desc              = BoardDiag_appQueuePop(port_num,
		                                &app_mcb.emac_pcb[port_num].freeQueue);
        if(p_pkt_desc != NULL)
        {
            p_pkt_desc->AppPrivate  = (uintptr_t)p_pkt_desc;
            p_pkt_desc->BufferLen   = APP_EMAC_MAX_PKT_SIZE;
            p_pkt_desc->DataOffset  = 0;
            p_pkt_desc->pPrev = NULL;
            p_pkt_desc->pNext = NULL;
        }
    }
    else
    {
        UART_printf ("BoardDiag_AppAllocPkt on port %d failed, packet size %d \
                      is big\n", port_num, pkt_size);
        return NULL;
    }
    return p_pkt_desc;
}

/**
 * \brief  Free packet function
 *
 * This function pushes the free packet descriptor into the queue
 *
 * \param   port_num  [IN]  EMAC port number
 *          p_desc    [IN]  Packet descriptor
 *
 */
void BoardDiag_AppFreePkt(uint32_t  port_num,
                          EMAC_PKT_DESC_T *p_pkt_desc)
{
    /* Free a packet descriptor to the free queue */
    BoardDiag_appQueuePush(port_num, &app_mcb.emac_pcb[port_num].freeQueue,
                   (EMAC_PKT_DESC_T *)p_pkt_desc->AppPrivate);
}

/**
 * \brief  Application initialization function
 *
 * This function initialize the application control block and
 * free/rx packet queue.
 *
 */
static void BoardDiag_appInit(void)
{
    EMAC_PKT_DESC_T  *p_pkt_desc;
    uint32_t    index;
    uint32_t    count;
    uint8_t     *pktbuf_ptr;

    UART_printf ("EMAC loopback test application initialization\n");

    /* Reset application control block */
    memset(&app_mcb, 0, sizeof (APP_EMAC_MCB_T));

    app_mcb.core_num = 0;
    /* packet buffer stores in internal memory */
    pktbuf_ptr = (uint8_t *) (app_pkt_buffer) ;

    /* Initialize the free packet queue */
    for (index=0; index<EMAC_MAX_NUM_EMAC_PORTS; index++)
    {
        for (count=0; count<APP_MAX_PKTS; count++)
        {
            p_pkt_desc               = &app_mcb.emac_pcb[index].pkt_desc[count];
            p_pkt_desc->pDataBuffer  = pktbuf_ptr;
            p_pkt_desc->BufferLen    = APP_EMAC_MAX_PKT_SIZE;
            BoardDiag_appQueuePush(index, &app_mcb.emac_pcb[index].freeQueue,
                                   p_pkt_desc );
            pktbuf_ptr += APP_EMAC_MAX_PKT_SIZE;
        }
    }
}


/**
 * \brief  Send packet function
 *
 * This function is used to send packets to the specified emac port.
 * Functional test will send all the packets and receive but stress test will
 * send one packet and receive one packet due to poll packet limitation.
 *
 * \param   port_num [IN]   EMAC port number
 *
 */
static void BoardDiag_appTestSendPkts(uint32_t port_num)
{
#ifdef DIAG_STRESS_TEST
    if(gTxPktCount < PKT_SEND_COUNT)
    {
        EMAC_PKT_DESC_T *p_pkt_desc = BoardDiag_AppAllocPkt(port_num,
                                                            TEST_PKT_SIZE);
        if(p_pkt_desc != NULL)
        {
            UART_printf("Sending Packet: %d\n", (gTxPktCount+1));
            memcpy (p_pkt_desc->pDataBuffer, &test_pkt[0], TEST_PKT_SIZE);
            p_pkt_desc->AppPrivate   = (uintptr_t)p_pkt_desc;
            p_pkt_desc->Flags        = EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP;
            p_pkt_desc->ValidLen     = TEST_PKT_SIZE;
            p_pkt_desc->DataOffset   = 0;
            p_pkt_desc->PktChannel   = 0;
            p_pkt_desc->PktLength    = TEST_PKT_SIZE;
            p_pkt_desc->BufferLen    = TEST_PKT_SIZE;
            p_pkt_desc->PktFrags     = 1;
            p_pkt_desc->pNext        = NULL;
            p_pkt_desc->pPrev        = NULL;

            emac_send(port_num, p_pkt_desc);
            gTxPktCount++;
        }
        else
        {
            UART_printf("Packet Descriptor Allocation Failed!\n");
        }
    }
#else
    uint32_t index;
    uint32_t pkt_send_count =0;
    for (index = 0; index < PKT_SEND_COUNT; index++)
    {
        EMAC_PKT_DESC_T *p_pkt_desc = BoardDiag_AppAllocPkt(port_num,
                                                            TEST_PKT_SIZE);
        if(p_pkt_desc != NULL)
        {
            UART_printf("Sending Packet: %d\n", (index+1));
            memcpy (p_pkt_desc->pDataBuffer, &test_pkt[0], TEST_PKT_SIZE);
            p_pkt_desc->AppPrivate   = (uintptr_t)p_pkt_desc;
            p_pkt_desc->Flags        = EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP;
            p_pkt_desc->ValidLen     = TEST_PKT_SIZE;
            p_pkt_desc->DataOffset   = 0;
            p_pkt_desc->PktChannel   = 0;
            p_pkt_desc->PktLength    = TEST_PKT_SIZE;
            p_pkt_desc->BufferLen    = TEST_PKT_SIZE;
            p_pkt_desc->PktFrags     = 1;
            p_pkt_desc->pNext        = NULL;
            p_pkt_desc->pPrev        = NULL;

            emac_send(port_num, p_pkt_desc);
            pkt_send_count++;
        }
        else
        {
            UART_printf("Packet Descriptor Allocation Failed!\n");
        }
    }
#endif
}

/**
 * \brief  Receive call back function
 *
 * This function is used to call back the network application when a
 * packet is received.
 * In this function emac stress test will trigger test packet send function to
 * send one packet each time.
 * After receiving all the packets it will call emac close function to exit
 * from the poll pkt function.
 *
 * \param   port_num [IN]   EMAC port number
 *          p_desc   [IN]   Packet descriptor
 *
 */
void BoardDiag_AppTestRxPktCb(uint32_t port_num, EMAC_PKT_DESC_T *p_desc)
{
	/* Change buffer length to not compare checksum data */
	p_desc->BufferLen = TEST_PKT_SIZE;

    if (memcmp(p_desc->pDataBuffer, test_pkt, p_desc->BufferLen) == 0)
    {
        pkt_rcvd = 1;
        pkt_rcv_count++;
        UART_printf("Received Packet: %d\n", pkt_rcv_count);
    }
    else
    {
        UART_printf("packet match failed\n");
    }

    BoardDiag_AppFreePkt(port_num,  (EMAC_PKT_DESC_T*) p_desc->AppPrivate);
}

/**
 * \brief  Function to initialize MDIO
 *
 * \param   baseAddr [IN]   MDIO base address
 *
 * \return  uint32_t
            TRUE     Read is successful.
 *          FALSE    Read is not acknowledged properly.
 */
static void BoardDiag_mdioInit(uint32_t baseAddr)
{
#if defined (SOC_AM65XX) || defined(SOC_J721E)
    HW_WR_REG32((baseAddr + 0x4), (CSL_FMKT(MDIO_CONTROL_REG_ENABLE, YES)  |
                CSL_FMK(MDIO_CONTROL_REG_CLKDIV,0xFF)));
#else
    CSL_MDIO_init(baseAddr,
                  BOARD_SWITCH_DEFAULT_MDIOCLOCKFREQ,
                  BOARD_SWITCH_DEFAULT_MDIOBUSFREQ);
#endif
}

/**
 * \brief  PHY register write function
 *
 * This function is used to Read a PHY register using MDIO.
 *
 * \param   baseAddr [IN]   MDIO base address
 *          phyAddr  [IN]   PHY Address
 *          regAddr  [IN]   Register offset to be written
 *          regData  [OUT]  Pointer where the read value shall be written
 *
 * \return  uint32_t
            TRUE     Read is successful.
 *          FALSE    Read is not acknowledged properly.
 */
static uint32_t BoardDiag_emacPhyRegRead(uint32_t baseAddr, uint32_t phyAddr,
                                         uint32_t regAddr, uint16_t *regData)
{
#if defined(SOC_AM65XX) || defined(SOC_J721E)
    uint32_t regVal = 0U;
    uint32_t retVal = 0U;

    /* Wait till transaction completion if any */
    while(HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
        CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO) == 1)
    {}
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO,1);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_WRITE, 0);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_PHYADR, phyAddr);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_REGADR, regAddr);
    HW_WR_REG32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U), regVal);

    /* wait for command completion */
    while(HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
          CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO) == 1)
    {}

    /* Store the data if the read is acknowledged */
    if(HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
        CSL_MDIO_USER_GROUP_USER_ACCESS_REG_ACK) == 1)
    {
        *regData = (uint16_t)(HW_RD_FIELD32(baseAddr + \
                    CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
                    CSL_MDIO_USER_GROUP_USER_ACCESS_REG_DATA));
        retVal = (uint32_t)TRUE;
    }
    else
    {
        retVal = (uint32_t)FALSE;
    }
    return(retVal);

#else
    return CSL_MDIO_phyRegRead(baseAddr, phyAddr, regAddr, regData);
#endif
}

/**
 * \brief  PHY register write function
 *
 * This function is used to writes a PHY register using MDIO.
 *
 * \param   baseAddr [IN]   MDIO base address
 *          phyAddr  [IN]   PHY Address
 *          regAddr  [IN]   Register offset to be written
 *          data     [IN]   Value to be written
 *
 */
static void BoardDiag_emacPhyRegWrite(uint32_t baseAddr, uint32_t phyAddr,
                                      uint32_t regAddr, uint16_t data)
{
#if defined(SOC_AM65XX) || defined(SOC_J721E)
    uint32_t regVal = 0U;

    /* Wait till transaction completion if any */
    while(HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
          CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO) == 1)
    {}

    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO, 1);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_WRITE, 1);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_PHYADR, phyAddr);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_REGADR, regAddr);
    HW_SET_FIELD(regVal, CSL_MDIO_USER_GROUP_USER_ACCESS_REG_DATA, data);
    HW_WR_REG32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U), regVal);

    /* wait for command completion */
    while(HW_RD_FIELD32(baseAddr + CSL_MDIO_USER_GROUP_USER_ACCESS_REG(0U),
          CSL_MDIO_USER_GROUP_USER_ACCESS_REG_GO) == 1)
    {}

#else
    CSL_MDIO_phyRegWrite(baseAddr, phyAddr, regAddr, data);
#endif
}

/**
 * \brief  Function to write extended address registers of Ethernet PHY
 *
 * \param   baseAddr [IN]    MDIO base address
 * \param   phyAddr  [IN]    Ethernet PHY address
 * \param   regNum   [IN]    PHY Register address
 * \param   regVal   [IN]    Register value to be written
 *
 * \return  none
 */
static void Mdio_PhyExtendedRegWrite(uint32_t baseAddr,
                                     uint32_t phyAddr,
                                     uint32_t regNum,
                                     uint16_t regVal)
{
    BoardDiag_emacPhyRegWrite(baseAddr, phyAddr, 0x0D, 0x001F);
    BoardDiag_emacPhyRegWrite(baseAddr, phyAddr, 0x0E, regNum);
    BoardDiag_emacPhyRegWrite(baseAddr, phyAddr, 0x0D, 0x401F);
    BoardDiag_emacPhyRegWrite(baseAddr, phyAddr, 0x0E, regVal);
}

/**
 * \brief  Function to write extended address registers of Ethernet PHY
 *
 * \param   baseAddr [IN]    MDIO base address
 *          phyAddr  [IN]    Ethernet PHY address
 *          regNum   [IN]    PHY Register address
 *          pData    [OUT]   Values read from register
 *
 */
static void BoardDiag_emacPhyExtendedRegRead (uint32_t baseAddr,
                                              uint32_t phyAddr, uint32_t regNum,
                                              uint16_t *pData)
{
#if defined(SOC_AM65XX) || defined(SOC_J721E)
    BoardDiag_emacPhyRegWrite(baseAddr, phyAddr, 0x0D, 0x001F);
	BoardDiag_emacPhyRegWrite(baseAddr, phyAddr, 0x0E, regNum);
	BoardDiag_emacPhyRegWrite(baseAddr, phyAddr, 0x0D, 0x401F);
	BoardDiag_emacPhyRegRead(baseAddr, phyAddr, 0x0E, pData);
#else
    Mdio_PhyExtendedRegRead(baseAddr, phyAddr, regNum, pData);
#endif
}

/**
 * \brief  Ethernet PHY initialization
 *
 * This function initializes the PHY to enter external loopback mode
 *
 * \return  int8_t
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
static int8_t BoardDiag_initEthPhy (void)
{
	uint16_t regData;

	linkCheckTime = 0;

	/*
     * Configure Ethernet PHY to enter External Loopback mode
     * reg 0: 0x3100
     * reg 9: 0x1000
     */
	UART_printf("Configuring Phy\n");
	/* MDIO is not reinitialized here as it is done by Board_gigEthConfig */
    BoardDiag_emacPhyRegWrite(baseAddr, phyAddrs, 0, 0x3100);
    BoardDiag_emacPhyRegWrite(baseAddr, phyAddrs, 9, 0x1000);

	UART_printf("Waiting for Link Status\n");
	regData = 0;
	while ((regData & 0x400) == 0)
	{
		BoardDiag_emacPhyRegRead(baseAddr, phyAddrs, 0x11,
                            &regData);
		BOARD_delay(10000);

		linkCheckTime++;
		if(linkCheckTime > 1000)
		{
			return (-1);
		}
	}

	UART_printf("Link is UP!!\n\n");
	return (0);
}

/**
 * \brief  PHY register dump test function
 *
 * This function used to read Ethernet PHY status and strapping registers
 * for debug purpose
 *
 * \param   baseAddr [IN]  Base address to get the register details
 *          phyAddr  [IN]  PHY address
 *
 * \return  int8_t
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
static int8_t BoardDiag_getPhyRegDump(uint32_t baseAddr, uint32_t phyAddr)
{
    uint16_t regAddr;
    uint16_t regVal = 0;
    int8_t   ret    = 0;

    /* Initialize MDIO module. MDIO will get initialized multiple times
       by keeping this function call here which should be OK. Will help
       while calling BoardDiag_getPhyRegDump for differe MDIO instances */
    BoardDiag_mdioInit(baseAddr);

    UART_printf("Register Dump for PHY Addr - 0x%04X\n", phyAddr);

    for (regAddr = 0; regAddr < maxEmacRegDump; regAddr++)
    {
        BoardDiag_emacPhyRegRead(baseAddr, phyAddr, regAddr, &regVal);
        UART_printf("PHY Register 0x%04X - 0x%04X\n", regAddr, regVal);
    }

    BoardDiag_emacPhyExtendedRegRead(baseAddr, phyAddr, emacStrapSts1Addr,
                                        &regVal);
    if(regVal != EMAC_STRAP_STS1_VAL)
    {
        UART_printf("Default PHY Register(STRAP1) Data mismatch\n");
        UART_printf("PHY Register(STRAP2) 0x%04X - 0x%04X\n",emacStrapSts1Addr,
                                                             regVal);
        ret = -1;
    }
    else
    {
        UART_printf("PHY Register(STRAP1) 0x%04X - 0x%04X\n",emacStrapSts1Addr,
                                                             regVal);
        ret = 0;
    }

    BoardDiag_emacPhyExtendedRegRead(baseAddr, phyAddr, emacStrapSts2Addr,
                                     &regVal);
    if(regVal != EMAC_STRAP_STS2_VAL)
    {
        UART_printf("Default PHY Register(STRAP2) Data mismatch\n");
        UART_printf("PHY Register(STRAP2) 0x%04X - 0x%04X\n",emacStrapSts2Addr,
                                                             regVal);
        ret = -1;
    }
    else
    {
        UART_printf("PHY Register(STRAP2) 0x%04X - 0x%04X\n",emacStrapSts2Addr,
                                                             regVal);
    }

    BoardDiag_emacPhyExtendedRegRead(baseAddr, phyAddr, 0x32, &regVal);
    UART_printf("RGMII Control Register (RGMIICTL) Value - 0x%04X\n", regVal);
    UART_printf("  --- RGMII_RX_CLK_DELAY - 0x%04X\n", (regVal & 0x1));
    UART_printf("  --- RGMII_TX_CLK_DELAY - 0x%04X\n", ((regVal >> 1) & 0x1));

    BoardDiag_emacPhyExtendedRegRead(baseAddr, phyAddr, 0x86, &regVal);
    UART_printf("RGMII Delay Control Register (RGMIIDCTL) Value - 0x%04X\n", regVal);

    return ret;
}

/**
 * \brief  CPSW configuration function
 *
 */
#if defined(SOC_AM65XX) || defined(SOC_J721E)
/**
 * \brief  emac test function
 *
 * This function does UDMA init
 *
 * \param   void
 *
 * \return  void
 *              0  - in case of success
 *              1  - in case of failure
 *
 */
void BoardDiag_udmaInit(void)
{
    int32_t         retVal = UDMA_SOK;
    Udma_InitPrms   initPrms;
    uint32_t        instId;
    /* UDMA driver init */
#if defined (__aarch64__)
    instId = UDMA_INST_ID_MAIN_0;
#else
    instId = UDMA_INST_ID_MCU_0;
#endif
    UdmaInitPrms_init(instId, &initPrms);
    initPrms.rmInitPrms.numIrIntr = EMAC_MAX_PORTS;
    retVal = Udma_init(&gUdmaDrvObj, &initPrms);
    if(UDMA_SOK == retVal)
    {
        gDrvHandle = &gUdmaDrvObj;
    }
}

/**
 * \brief  CPSW speed configuration function
 *
 */
static void BoardDiag_setupCpswSpeed(void)
{
    uintptr_t rgmii_speed;
    uint32_t regVal;

    /* Set the speed to 100mbps */
    rgmii_speed = 0x46022330;
    regVal = CSL_REG32_RD(rgmii_speed);
    regVal &= ~0x80;
    CSL_REG32_WR(rgmii_speed , regVal);
}

/**
 * \brief  Enabled LED pin functionality for AM65xx  and j7 evm board
 * TODO: Move this function to board library
 *
 */
static void BoardDiag_enablePhyLed(void)
{
    uint16_t regData;

    BoardDiag_mdioInit(baseAddr);
    BoardDiag_emacPhyExtendedRegRead(baseAddr, 0, 0x172, &regData);
    regData  = (regData & ~0xF) | 0x6;
    Mdio_PhyExtendedRegWrite(baseAddr, 0, 0x172, regData);
    regData = 0;
    BoardDiag_emacPhyExtendedRegRead(baseAddr, 0, 0x172, &regData);

    BoardDiag_emacPhyRegRead(baseAddr, 0, 0x18, &regData);
    regData  = (regData & ~0xF000) | 0x8000;
    BoardDiag_emacPhyRegWrite(baseAddr, 0, 0x18, regData);
    regData = 0;
    BoardDiag_emacPhyRegRead(baseAddr, 0, 0x18, &regData);
}
#endif
/**
 * \brief  emac loopback test function
 *
 * This test is used to verify the Ethernet interface by sending and receiving
 * the same number of packets using external loopback cable.
 *
 * \param   port_num [IN] EMAC port number
 *
 * \return  int8_t
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
static int8_t BoardDiag_emacLoopbackTest(uint32_t port_num)
{
#if defined(SOC_AM65XX) || defined(SOC_J721E)
    EMAC_HwAttrs_V5         emac_cfg;
    int32_t chanNum = 0;
    int32_t subChanNum = 0;
#else
    EMAC_HwAttrs_V1         emac_cfg;
    uint32_t mac1 = 0;
    uint32_t mac2 = 0;
#endif
#ifdef DIAG_STRESS_TEST
    char rdBuf = 'y';
#endif
    EMAC_OPEN_CONFIG_INFO_T open_cfg;
    EMAC_CONFIG_INFO_T      cfg_info;
    EMAC_DRV_ERR_E          open_ret;
    EMAC_CHAN_MAC_ADDR_T    chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE];
    int8_t ret  = 0;
    uint32_t index;

    UART_printf("\n\nReading Ethernet PHY Register Dump...\n");
    ret = BoardDiag_getPhyRegDump(baseAddr, phyAddrs);
    if(ret != 0)
    {
        UART_printf("Strapping Registers data mismatch\n");
    }

    EMAC_socGetInitCfg(0, &emac_cfg);
#if defined(SOC_AM65XX) || defined(SOC_J721E)

    BoardDiag_udmaInit();
    BoardDiag_enablePhyLed();

    emac_cfg.portCfg[port_num].txChannel[chanNum].chHandle = (void *)&gUdmaTxChObj[port_num];
    emac_cfg.portCfg[port_num].txChannel[chanNum].freeRingMem= (void*)&gTxRingMem[port_num][0];
    emac_cfg.portCfg[port_num].txChannel[chanNum].compRingMem= (void*)&gTxCompRingMem[port_num][0];
    emac_cfg.portCfg[port_num].txChannel[chanNum].hPdMem = (void*)&gUdmapDescRamTx[port_num][0];

    emac_cfg.portCfg[port_num].rxChannel.chHandle = (void *)&gUdmaRxChObj[port_num];
    emac_cfg.portCfg[port_num].rxChannel.subChan[subChanNum].freeRingMem[0] = (void*)&gRxRingMem[port_num][0];
    emac_cfg.portCfg[port_num].rxChannel.subChan[subChanNum].compRingMem= (void*)&gRxCompRingMem[port_num][0];
    emac_cfg.portCfg[port_num].rxChannel.subChan[subChanNum].hPdMem[0] = (void*)&gUdmapDescRamRx[port_num][0];
    emac_cfg.portCfg[port_num].rxChannel.subChan[subChanNum].eventHandle = (void *)&gUdmaRxCqEventObj[port_num];

#else
    /* Need to update the descriptor base address */
    emac_cfg.p_desc_base = &gHostDesc;
#endif
    /* Now set the config after updating desc base address */
    EMAC_socSetInitCfg(0, &emac_cfg);

    BoardDiag_appInit();

    memset(&open_cfg, 0, sizeof(EMAC_OPEN_CONFIG_INFO_T));
    open_cfg.hwAttrs            = (void*)&emac_cfg;
    open_cfg.alloc_pkt_cb       = BoardDiag_AppAllocPkt;
    open_cfg.free_pkt_cb        = BoardDiag_AppFreePkt;
    open_cfg.loop_back          = 0;
    open_cfg.master_core_flag   = 1;
    open_cfg.max_pkt_size       = APP_EMAC_INIT_PKT_SIZE;
    open_cfg.mdio_flag          = 1;
    open_cfg.num_of_chans       = 1;
    open_cfg.num_of_rx_pkt_desc = 16;
    open_cfg.num_of_tx_pkt_desc = 16;
    open_cfg.phy_addr           = phyAddrs;
    open_cfg.p_chan_mac_addr    = &chan_cfg[0];
    open_cfg.rx_pkt_cb          = BoardDiag_AppTestRxPktCb;

    /* Set the channel configuration */
    chan_cfg[0].chan_num         = 0;
    chan_cfg[0].num_of_mac_addrs = 1;
#if defined(SOC_AM65XX) || defined(SOC_J721E)
    open_cfg.mode_of_operation  = EMAC_MODE_POLL;
    open_cfg.udmaHandle = (void*)gDrvHandle;

    for (index=0;index<6;index++)
    {
        macTest.addr[index] = index + 2U;
    }
#else
    CSL_BootCfgGetMacIdentifier(&mac1, &mac2);

    macTest.addr[0] = ((mac2 & 0x0000ff00) >> 8);
    macTest.addr[1] =  (mac2 & 0x000000ff);
    macTest.addr[2] = ((mac1 & 0xff000000) >> 24);
    macTest.addr[3] = ((mac1 & 0x00ff0000) >> 16);
    macTest.addr[4] = ((mac1 & 0x0000ff00) >> 8);
    macTest.addr[5] =  (mac1 & 0x000000ff);
#endif
    chan_cfg[0].p_mac_addr = & macTest;

    if ((open_ret = emac_open(port_num, &open_cfg))
                              == EMAC_DRV_RESULT_OPEN_PORT_ERR)
    {
        UART_printf("main: emac_open failure: %d\n", open_ret);
        return (-1);
    }
    else
        UART_printf("main: emac_open success\n");

    cfg_info.mcast_cnt    = 0;
    cfg_info.p_mcast_list = NULL;
    cfg_info.rx_filter    = EMAC_PKTFLT_MULTICAST;;
    emac_config(port_num, &cfg_info);

    if(BoardDiag_initEthPhy() != 0 )
    {
        UART_printf("LINK Timeout!\n");
        UART_printf("EMAC Test Failed!!\n");
        emac_close(port_num);
#if defined(SOC_AM65XX)
        Udma_deinit(&gUdmaDrvObj);
#endif
        BoardDiag_ethCtrlPowerDown();
        return (-1);
    }

#if defined(SOC_AM65XX) || defined(SOC_J721E)
    BoardDiag_setupCpswSpeed();
#else
    CSL_CPGMAC_SL_disableGigabit(0);
#endif

#ifdef DIAG_STRESS_TEST

    for (index = 0; index < PKT_SEND_COUNT; index++)
    {
        pkt_rcvd = 0;
        timeout  = 0;

        BoardDiag_appTestSendPkts(port_num);
        while(pkt_rcvd == 0)
        {
            emac_poll_pkt(port_num);
            /* Wait 1msec */
            BOARD_delay(1000);
            timeout++;
            if(timeout >= BOARD_DIAG_EMAC_TEST_TIMEOUT)
            {
                UART_printf("\nReceive Timeout!\n");
                ret = -1;
                break;
            }
        }
        /* Check if there a input from console to break the test */
        rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("Received Test Termination... Exiting the Test\n\n");
            break;
        }
    }

    emac_close(port_num);
#if defined(SOC_AM65XX)
    Udma_deinit(&gUdmaDrvObj);
#endif
#else
    BoardDiag_appTestSendPkts(port_num);
#if defined(SOC_K2G)
    /* Poll packet function supported on K2G platform waits
       indefinitely for the packets and does not return to application.
       Wait some time for the Ethernet packets to be loopback.
       Received packets will be flushed from FIFO during close
       which will trigger the application Rx callback function.
     */
    BOARD_delay(4000000);
#else
    emac_poll_pkt(port_num);
#endif
    emac_close(port_num);
#if defined(SOC_AM65XX)
    Udma_deinit(&gUdmaDrvObj);
#endif
#endif
#ifdef DIAG_STRESS_TEST
    if (pkt_rcv_count == gTxPktCount)
    {
        UART_printf("\nPackets sent: %d, Packets received: %d\n",
                     gTxPktCount, pkt_rcv_count);
        UART_printf("\nEthernet Loopback test passed\n");
        ret = 0;
    }
#else
    if (pkt_rcv_count == PKT_SEND_COUNT)
    {
        UART_printf("\nPackets sent: %d, Packets received: %d\n",
                     PKT_SEND_COUNT, pkt_rcv_count);
        UART_printf("\nEthernet Loopback test passed\n");
        ret = 0;
    }
#endif
    else
    {
        UART_printf("\nEthernet Loopback test failed!!\n");
        ret = -1;
    }
    pkt_rcv_count = 0;

	/* Powerdown the NSS so that re-configuration will be clean while
	   running the test multiple times */
	BoardDiag_ethCtrlPowerDown();

	UART_printf("All tests completed\n");

    return (ret);
}

#if defined (ENABLE_CABLE_DICONNECT_TEST)
#if defined(SOC_AM65XX) && !defined(DIAG_STRESS_TEST) && !defined(DIAG_COMPLIANCE_TEST)
/**
 * \brief  emac cable connect and disconnect test function
 *
 * This function verifies the Ethernet interface by disconnecting and
 * reconnecting the Ethernet loopback cable and re-running the test.
 *
 * \param   port_num [IN] EMAC port number
 *
 * \return  int8_t
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
static int8_t BoardDiag_emacCableDisconTest(uint32_t port_num)
{
    UART_printf("Please disconnect the loopback cable \n");
    /* Waiting to disconnect the Ethernet cable
     * After disconnecting the cable shows the link status
     */
    while(1)
    {
        emac_poll(port_num, &link_info);

        if((link_info.link_status_change) && (link_info.link_status ==
                                                    EMAC_LINKSTATUS_NOLINK))
        {
            UART_printf("Link is Down\n");
            break;
        }
    }

    UART_printf("Please reconnect the loopback cable \n");
    /* Waiting to reconnect the Ethernet cable
     * After connecting the cable shows the link status
     */
    while(1)
    {
        emac_poll(port_num, &link_info);

        if((link_info.link_status_change) && (link_info.link_status !=
                                                    EMAC_LINKSTATUS_NOLINK))
        {
            UART_printf("Link is UP\n");
            break;
        }
    }
    return BoardDiag_emacLoopbackTest(port_num);
}
#endif
#endif /* #if defined (ENABLE_CABLE_DICONNECT_TEST) */

/**
 * \brief  emac test function
 *
 * This function executes emac diagnostic test
 *
 * \param   port_num [IN] EMAC port number
 *
 * \return  int8_t
 *              0  - in case of success
 *              1  - in case of failure
 *
 */
int8_t BoardDiag_EmacTest(uint32_t port_num)
{
#ifdef DIAG_STRESS_TEST
    UART_printf  ("************************************************\n");
    UART_printf  ("*      ETHERNET LOOPBACK STRESS Test           *\n");
    UART_printf  ("************************************************\n");

    return BoardDiag_emacLoopbackTest(port_num);

#else
    int8_t ret;

    UART_printf  ("************************************************\n");
    UART_printf  ("*             ETHERNET LOOPBACK Test           *\n");
    UART_printf  ("************************************************\n");

    ret = BoardDiag_emacLoopbackTest(port_num);
    if(ret != 0)
    {
        return ret;
    }

#if defined (ENABLE_CABLE_DICONNECT_TEST)
#if defined(SOC_AM65XX) && !defined(DIAG_STRESS_TEST) && !defined(DIAG_COMPLIANCE_TEST)
    else
    {
        BoardDiag_ethCtrlPowerUp();
        Board_init(BOARD_INIT_ETH_PHY);
        ret = BoardDiag_emacCableDisconTest(port_num);
    }
#endif
#endif   /* #if defined (ENABLE_CABLE_DICONNECT_TEST) */

    return ret;
#endif
}

/**
 * \brief  main function
 *
 *  This function performs board initializations and calls emac test
 *
 * \return  int
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
int main(void)
{
    Board_initCfg boardCfg;
#if defined(SOC_AM65XX) || defined(SOC_J721E)
    uint32_t port_num = 6;
#else
    uint32_t port_num = 0;
#endif

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

    /* Power domain to be turned on before doing the board initializations */
    BoardDiag_ethCtrlPowerUp();

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO |
               BOARD_INIT_ETH_PHY;
#else
    boardCfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_ETH_PHY;
#endif

    Board_init(boardCfg);

    return BoardDiag_EmacTest(port_num);
}
