/******************************************************************************
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   icssg_emac_test.c
 *
 *  \brief  icssg emac diagnostic test file
 *
 *  Targeted Functionality: Verification of basic functionality of icssg emac
 *  interface.
 *
 *  Operation: This is the port to port loopback test for verifying the
 *  icssg emac interface. Test is run with PRU port 0 and PRU port 1 of an ICSS
 *  instance connected with Ethernet cable. Packets are sent from PRU port 0
 *  and received on PRU port 1. Similarly packets are sent form PRU port 1 and
 *  received on PRU port 0. Test is run at 1000mpbs Ethernet speed.
 *
 *  Setup:
 *  AM65xx EVM
 *  Connect Ethernet cable between PRU2 ETH0 and ETH1 ports (J14) on CP board
 *
 *  AM65xx IDK
 *  Connect Ethernet cable between PRU0 ETH0 and ETH1 ports (J3) on IDK board
 *  Connect Ethernet cable between PRU1 ETH0 and ETH1 ports (J1) on IDK board
 *  Connect Ethernet cable between PRU2 ETH0 and ETH1 ports (J14) on CP board
 *
 *  Supported SoCs: AM65XX.
 *
 *  Supported Platforms: am65xx_evm am65xx_idk.
 *
 */

#include "icssg_emac_test.h"

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
uint32_t interposerCardPresent = 0;

Board_IDInfo_v2 gIcssEmacBoardInfo;

#define APP_TEST_AM65XX_PG1_0_VERSION (0x0BB5A02FU)
/* Maxwell PG version */
uint32_t gPgVersion;

/*
 * UDMA driver objects
 */
struct Udma_DrvObj      gUdmaDrvObj;
struct Udma_ChObj       gUdmaTxChObj[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][4];
struct Udma_ChObj       gUdmaRxChObj[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][4];
struct Udma_EventObj    gUdmaRxCqEventObj[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][4];

struct Udma_ChObj       gUdmaRxCfgPsiChObj[BOARD_DIAG_ICSS_EMAC_MAX_PORTS];
struct Udma_EventObj    gUdmaRxCfgPsiCqEventObj[BOARD_DIAG_ICSS_EMAC_MAX_PORTS];

Udma_DrvHandle          gDrvHandle = NULL;


uint8_t  app_pkt_buffer[BOARD_DIAG_ICSS_EMAC_TOTAL_PKTBUF_SIZE] __attribute__ ((aligned (128))) __attribute__ ((section (".data_buffer")));
/* TX/RX ring entries memory */
uint8_t  gTxRingMem[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][BOARD_DIAG_ICSS_EMAC_RING_TRSIZE * BOARD_DIAG_ICSS_EMAC_RING_TRCNT] __attribute__ ((aligned (BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ)));
uint8_t  gTxCompRingMem[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][BOARD_DIAG_ICSS_EMAC_RING_TRSIZE * BOARD_DIAG_ICSS_EMAC_RING_TRCNT] __attribute__ ((aligned (BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ)));
uint8_t  gRxRingMem[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][BOARD_DIAG_ICSS_EMAC_RING_TRSIZE * BOARD_DIAG_ICSS_EMAC_RING_TRCNT] __attribute__ ((aligned (BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ)));
uint8_t  gRxCompRingMem[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][BOARD_DIAG_ICSS_EMAC_RING_TRSIZE * BOARD_DIAG_ICSS_EMAC_RING_TRCNT] __attribute__ ((aligned (BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ)));
uint8_t gRxCfgPsiRingMem[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][BOARD_DIAG_ICSS_EMAC_RING_TRSIZE * BOARD_DIAG_ICSS_EMAC_RING_TRCNT] __attribute__ ((aligned(BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ)));
uint8_t gRxCfgPsiCompRingMem[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][BOARD_DIAG_ICSS_EMAC_RING_TRSIZE * BOARD_DIAG_ICSS_EMAC_RING_TRCNT] __attribute__ ((aligned(BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ)));



/* TX/RX ring CPPI descriptor memory */
uint8_t gUdmapDescRamTx[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][BOARD_DIAG_ICSS_EMAC_RING_TRCNT*BOARD_DIAG_ICSS_EMAC_UDMAP_DESC_SIZE] __attribute__ ((aligned (BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ)))__attribute__ ((section (".data_buffer"))); 
uint8_t gUdmapDescRamRx[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][BOARD_DIAG_ICSS_EMAC_RING_TRCNT*BOARD_DIAG_ICSS_EMAC_UDMAP_DESC_SIZE] __attribute__ ((aligned (BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ)))__attribute__ ((section (".data_buffer")));
uint8_t gUdmapDescRamRxCfgPsi[BOARD_DIAG_ICSS_EMAC_MAX_PORTS][BOARD_DIAG_ICSS_EMAC_RING_TRCNT * BOARD_DIAG_ICSS_EMAC_UDMAP_DESC_SIZE] __attribute__ ((aligned(BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ))) __attribute__ ((section (".data_buffer")));

static BOARD_DIAG_ICSSG_EMAC_PRUICSS_FW_T firmware_pg1[2] = {
    { PDSPcode_0, sizeof(PDSPcode_0), PDSP2code_0, sizeof(PDSP2code_0), NULL, 0},
    { PDSP3code_0, sizeof(PDSP3code_0), PDSP4code_0, sizeof(PDSP4code_0), NULL, 0}
};

static BOARD_DIAG_ICSSG_EMAC_PRUICSS_FW_T firmware_pg2[2] = {
    { PDSPcode_0_PG2, sizeof(PDSPcode_0_PG2), PDSP2code_0_PG2, sizeof(PDSP2code_0_PG2), PDSP5code_0_PG2, sizeof(PDSP5code_0_PG2)},
    { PDSP3code_0_PG2, sizeof(PDSP3code_0_PG2), PDSP4code_0_PG2, sizeof(PDSP4code_0_PG2),  PDSP6code_0_PG2, sizeof(PDSP6code_0_PG2)}
};

static uint32_t gPktRcvCount = 0;
volatile uint32_t gPktRcvd = 0;
uint32_t gTxPktCount     = 0;
uint32_t gLinkCheckTime   = 0;
uint32_t linkUp          = 0;
uint8_t icss_tx_port_queue[3][100352] __attribute__ ((aligned (BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ)));

PRUICSS_Handle prussHandle[BOARD_DIAG_ICSS_EMAC_MAX_INTANCES] = {NULL, NULL, NULL};
BOARD_DIAG_ICSSG_EMAC_MCB_T   app_mcb;
EMAC_LINK_INFO_T link_info;
EMAC_MAC_ADDR_T  macTest;

EMAC_HwAttrs_V5         emac_cfg;
EMAC_CHAN_MAC_ADDR_T    chan_cfg[BOARD_DIAG_ICSS_EMAC_NUM_CHANS_PER_CORE];

BOARD_DIAG_MDIO_INFO_T  gBoardDiagMdioInfo[BOARD_DIAG_ICSS_EMAC_MAX_PORTS] = {{(CSL_PRU_ICSSG0_DRAM0_SLV_RAM_BASE+CSL_ICSS_MDIO_CFG_BASE), BOARD_ICSS0_EMAC_PHY0_ADDR, 0x6000, 0x0500},
                                                          {(CSL_PRU_ICSSG0_DRAM0_SLV_RAM_BASE+CSL_ICSS_MDIO_CFG_BASE), BOARD_ICSS0_EMAC_PHY1_ADDR, 0x6003, 0x0500},
                                                          {(CSL_PRU_ICSSG1_DRAM0_SLV_RAM_BASE+CSL_ICSS_MDIO_CFG_BASE), BOARD_ICSS1_EMAC_PHY0_ADDR, 0x6000, 0x0500},
                                                          {(CSL_PRU_ICSSG1_DRAM0_SLV_RAM_BASE+CSL_ICSS_MDIO_CFG_BASE), BOARD_ICSS1_EMAC_PHY1_ADDR, 0x6003, 0x0500},
                                                          {(CSL_PRU_ICSSG2_DRAM0_SLV_RAM_BASE+CSL_ICSS_MDIO_CFG_BASE), BOARD_ICSS2_EMAC_PHY0_ADDR, 0, 0x100},
                                                          {(CSL_PRU_ICSSG2_DRAM0_SLV_RAM_BASE+CSL_ICSS_MDIO_CFG_BASE), BOARD_ICSS2_EMAC_PHY1_ADDR, 3, 0x100},
                                                        };

/**********************************************************************
 ****************** Test Configuration Variables **********************
 **********************************************************************/

static const uint8_t test_pkt[BOARD_DIAG_ICSS_EMAC_TEST_PKT_SIZE] = {
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
 * \brief  Detect presence of interposer card
 *
 *
 * \param   none
 *
 * \return  TRUE if present, FALSE if NOT present
 *
 */
bool BoardDiag_DetectInterposerCard(void)
{
    EMAC_HwAttrs_V5 emac_cfg;
    EMAC_socGetInitCfg(0, &emac_cfg);
    CSL_MdioRegs *pBaseAddr = (CSL_MdioRegs*) emac_cfg.portCfg[2].mdioRegsBaseAddr;
    if ((CSL_MDIO_isPhyAlive(pBaseAddr,emac_cfg.portCfg[2].phyAddr)) ||(CSL_MDIO_isPhyAlive(pBaseAddr,emac_cfg.portCfg[3].phyAddr)))
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}

/**
 * \brief  Application queue pop function
 *
 * Dequeues a packet descriptor from an app queue.
 *
 * \param   pq         [IN/OUT]  Packet queue
 *
 * \return  EMAC_Pkt popped from the queue
 *
 */
static EMAC_PKT_DESC_T* BoardDiag_appQueuePop(BOARD_DIAG_ICSSG_EMAC_PKT_QUEUE_T   *pq)
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
 * \param   pq          [OUT]       Packet queue
 *          pPktHdr     [IN]        Packet to push
 *
 */
static void BoardDiag_appQueuePush(BOARD_DIAG_ICSSG_EMAC_PKT_QUEUE_T *pq,
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
 * \param   portNum   [IN]  EMAC port number
 *          pktSize   [IN]  size of the packet
 *
 * \return   pointer to the allocated packet descriptor.
 *
 */
EMAC_PKT_DESC_T* BoardDiag_AppAllocPkt(uint32_t  portNum, uint32_t pktSize)
{
    EMAC_PKT_DESC_T    *p_pkt_desc = NULL;

    if (pktSize <= BOARD_DIAG_ICSS_EMAC_MAX_PKT_SIZE)
    {
        /* Get a packet descriptor from the free queue */
        p_pkt_desc              = BoardDiag_appQueuePop(&app_mcb.emac_pcb[portNum].freeQueue);
        if(p_pkt_desc != NULL)
        {
            p_pkt_desc->AppPrivate  = (uint32_t)p_pkt_desc;
            p_pkt_desc->BufferLen   = BOARD_DIAG_ICSS_EMAC_MAX_PKT_SIZE;
            p_pkt_desc->DataOffset  = 0;
            p_pkt_desc->pPrev = NULL;
            p_pkt_desc->pNext = NULL;
        }
    }
    else
    {
        UART_printf ("BoardDiag_AppAllocPkt on port %d failed, packet size %d \
                      is big\n", portNum, pktSize);
        return NULL;
    }

    return p_pkt_desc;
}

/**
 * \brief  Free packet function
 *
 * This function pushes the free packet descriptor into the queue
 *
 * \param   portNum    [IN]  EMAC port number
 *          pPktDesc   [IN]  Packet descriptor
 *
 */
void BoardDiag_AppFreePkt(uint32_t  portNum,
                          EMAC_PKT_DESC_T *pPktDesc)
{
    /* Free a packet descriptor to the free queue */
    BoardDiag_appQueuePush(&app_mcb.emac_pcb[portNum].freeQueue,
                   (EMAC_PKT_DESC_T *)pPktDesc->AppPrivate);
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
    BoardDiag_emacPhyRegWrite(baseAddr, phyAddr, 0x0D, 0x001F);
	BoardDiag_emacPhyRegWrite(baseAddr, phyAddr, 0x0E, regNum);
	BoardDiag_emacPhyRegWrite(baseAddr, phyAddr, 0x0D, 0x401F);
	BoardDiag_emacPhyRegRead(baseAddr, phyAddr, 0x0E, pData);
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
    uint32_t         index;
    uint32_t         count;
    uint8_t          *pktbuf_ptr;

    UART_printf ("\nEMAC loopback test application initialization\n");

    /* Reset application control block */
    memset(&app_mcb, 0, sizeof (BOARD_DIAG_ICSSG_EMAC_MCB_T));

    app_mcb.core_num = 0;
    /* packet buffer stores in internal memory */
    pktbuf_ptr = (uint8_t *) ((uint32_t) app_pkt_buffer) ;

    /* Initialize the free packet queue */
    for (index = 0; index < EMAC_MAX_NUM_EMAC_PORTS; index++)
    {
        for (count = 0; count < BOARD_DIAG_ICSSG_EMAC_MAX_PKTS; count++)
        {
            p_pkt_desc               = &app_mcb.emac_pcb[index].pkt_desc[count];
            p_pkt_desc->pDataBuffer  = pktbuf_ptr;
            p_pkt_desc->BufferLen    = BOARD_DIAG_ICSS_EMAC_MAX_PKT_SIZE;
            BoardDiag_appQueuePush(&app_mcb.emac_pcb[index].freeQueue,
                                   p_pkt_desc );
            pktbuf_ptr += BOARD_DIAG_ICSS_EMAC_MAX_PKT_SIZE;
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
 * \param   portNum [IN]   EMAC port number
 *
 */
static void BoardDiag_appTestSendPkts(uint32_t portNum)
{
    if(gTxPktCount < BOARD_DIAG_ICSS_EMAC_PKT_SEND_COUNT)
    {
        EMAC_PKT_DESC_T *p_pkt_desc = BoardDiag_AppAllocPkt(portNum,
                                                            BOARD_DIAG_ICSS_EMAC_TEST_PKT_SIZE);
        if(p_pkt_desc!=NULL)
        {
          memcpy (p_pkt_desc->pDataBuffer, &test_pkt[0], BOARD_DIAG_ICSS_EMAC_TEST_PKT_SIZE);
          p_pkt_desc->AppPrivate   = (uint32_t)p_pkt_desc;
          p_pkt_desc->ValidLen     = BOARD_DIAG_ICSS_EMAC_TEST_PKT_SIZE;
          p_pkt_desc->DataOffset   = 0;
          p_pkt_desc->PktChannel   = 0;
          p_pkt_desc->PktLength    = BOARD_DIAG_ICSS_EMAC_TEST_PKT_SIZE;
          p_pkt_desc->BufferLen    = BOARD_DIAG_ICSS_EMAC_TEST_PKT_SIZE;
          p_pkt_desc->PktFrags     = 1;
          p_pkt_desc->pNext        = NULL;
          p_pkt_desc->pPrev        = NULL;
          emac_send(portNum, p_pkt_desc);
          gTxPktCount++;
        }  
    }

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
 * \param   portNum  [IN]   EMAC port number
 *          pDesc    [IN]   Packet descriptor
 *
 */
void BoardDiag_AppTestRxPktCb(uint32_t portNum, EMAC_PKT_DESC_T *pDesc)
{
	/* Change buffer length to not compare checksum data */
	pDesc->BufferLen = BOARD_DIAG_ICSS_EMAC_TEST_PKT_SIZE;
    if (memcmp(pDesc->pDataBuffer, test_pkt, pDesc->BufferLen) == 0)
    {
        gPktRcvd = 1;
        gPktRcvCount++;
    }
    else
    {
        UART_printf("packet match failed\n");
    }

    BoardDiag_AppFreePkt(portNum,  (EMAC_PKT_DESC_T*) pDesc->AppPrivate);
}

/**
 * \brief  Link detect function
 *
 * This function used to detect the PRU ICSSG EMAC link status
 *
 * \param   portNum  [IN]   EMAC port number
 *
 * \return  int8_t
 *              0  - in case of link detect
 *             -1  - in case of failure
 *
 */
static int8_t BoardDiag_icssgEmacLinkDetect(uint32_t portNum)
{
    gLinkCheckTime = 0;

    do
    {
        emac_poll(portNum, &link_info);
		BOARD_delay(10);
		gLinkCheckTime++;
		if(gLinkCheckTime > BOARD_DIAG_ICSS_EMAC_LINK_TIMEOUT_COUNT)
		{
			return (-1);
		}
    } while(link_info.link_status == EMAC_LINKSTATUS_NOLINK);

    return (0);
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
    HW_WR_REG32((baseAddr + 0x4), (CSL_FMKT(MDIO_CONTROL_REG_ENABLE, YES)  |
                CSL_FMK(MDIO_CONTROL_REG_CLKDIV,0xFF)));
}

/**
 * \brief  PHY register dump test function
 *
 * This function used to read Ethernet PHY status and strapping registers
 * for debug purpose
 *
  * \param   portNum  [IN]   EMAC port number
 *
 * \return  int8_t
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
static int8_t BoardDiag_getPhyRegDump(uint32_t portNum)
{
    uint16_t regAddr;
    uint16_t regVal = 0;
    int8_t   ret    = 0;
    uint32_t baseAddr = gBoardDiagMdioInfo[portNum].mdioBaseAddrs;
    uint8_t phyAddr = gBoardDiagMdioInfo[portNum].phyAddrs;

    /* Initialize MDIO module. MDIO will get initialized multiple times
       by keeping this function call here which should be OK. Will help
       while calling BoardDiag_getPhyRegDump for differe MDIO instances */
    BoardDiag_mdioInit(baseAddr);

    /* On some of the AM65xx boards it is observed that ICSSG EMAC test is
       failing due to master-slave handshake failure as both the PHYs
       are trying to be in master mode. Forcing one of the PHYs to be master
       and other one to be a slave by default. */
    if((portNum % 2) == 0)
    {
        BoardDiag_emacPhyRegWrite(baseAddr,phyAddr,0x0009,0x1B00);
        BoardDiag_emacPhyRegRead(baseAddr, phyAddr, 0, &regVal);
        regVal |= 0x200; /* Restart Auto negotiation */
    }
    else
    {
        BoardDiag_emacPhyRegWrite(baseAddr,phyAddr,0x0009,0x1300);
        BoardDiag_emacPhyRegRead(baseAddr, phyAddr, 0, &regVal);
        regVal |= 0x200; /* Restart Auto negotiation */
        BoardDiag_emacPhyRegWrite(baseAddr,phyAddr, 0, regVal);

        do
        {
            BoardDiag_emacPhyRegRead(baseAddr, phyAddr, 1, &regVal);
        } while ((regVal & 0x20) == 0);
    }

    UART_printf("\n\nRegister Dump for PHY Addr - 0x%04X\n", phyAddr);

    for (regAddr = 0; regAddr < BOARD_DIAG_ICSS_EMAC_REG_DUMP_MAX; regAddr++)
    {
        BoardDiag_emacPhyRegRead(baseAddr, phyAddr, regAddr, &regVal);
        UART_printf("PHY Register 0x%04X - 0x%04X\n", regAddr, regVal);
    }

    BoardDiag_emacPhyRegRead(baseAddr, phyAddr, 0x31, &regVal);
    UART_printf("PHY Configuration Register(CFG4) 0x%04X - 0x%04X\n",
                0x31, regVal);

    BoardDiag_emacPhyExtendedRegRead(baseAddr, phyAddr,
                            BOARD_ICSS_EMAC_STRAP_STS1_ADDR, &regVal);
    if(regVal != gBoardDiagMdioInfo[portNum].strapst1)
    {
        UART_printf("Default PHY Register(STRAP1) Data mismatch\n");
        ret = -1;
    }

    UART_printf("PHY Register(STRAP1) 0x%04X - 0x%04X\n",
                BOARD_ICSS_EMAC_STRAP_STS1_ADDR, regVal);

    BoardDiag_emacPhyExtendedRegRead(baseAddr, phyAddr,
                            BOARD_ICSS_EMAC_STRAP_STS2_ADDR, &regVal);
    if(regVal != gBoardDiagMdioInfo[portNum].strapst2)
    {
        UART_printf("Default PHY Register(STRAP2) Data mismatch\n");
        ret = -1;
    }

    UART_printf("PHY Register(STRAP2) 0x%04X - 0x%04X\n",
                BOARD_ICSS_EMAC_STRAP_STS2_ADDR, regVal);

    BoardDiag_emacPhyExtendedRegRead(baseAddr, phyAddr, 0x32, &regVal);
    UART_printf("RGMII Control Register (RGMIICTL) Value - 0x%04X\n", regVal);
    UART_printf("  --- RGMII_RX_CLK_DELAY - 0x%04X\n", (regVal & 0x1));
    UART_printf("  --- RGMII_TX_CLK_DELAY - 0x%04X\n", ((regVal >> 1) & 0x1));

    BoardDiag_emacPhyExtendedRegRead(baseAddr, phyAddr, 0x86, &regVal);
    UART_printf("RGMII Delay Control Register (RGMIIDCTL) Value - 0x%04X\n", regVal);

    return ret;
}

/**
 * \brief  PRU disable test function
 *
 * This function used to disable the PRU subsystem
 *
 * \param   instance [IN]  PRU-ICSS port number
 *
 */
static int32_t  BoardDiag_disablePruss(uint32_t portNum)
{
    PRUICSS_Handle prussDrvHandle;
    uint8_t pru_n, rtu_n, txpru_n, slice_n;

    if (portNum > 5)
        return -1;

    prussDrvHandle =prussHandle[portNum >> 1];
    if (prussDrvHandle == NULL)
        return -1;

    slice_n = (portNum & 1);
    pru_n = (slice_n) ? PRUICCSS_PRU1 : PRUICCSS_PRU0;
    rtu_n = (slice_n) ? PRUICCSS_RTU1 : PRUICCSS_RTU0;
    txpru_n = (slice_n) ? PRUICCSS_TPRU1 : PRUICCSS_TPRU0;

    if (PRUICSS_pruDisable(prussDrvHandle, pru_n) != 0)
        UART_printf("PRUICSS_pruDisable for PRUICCSS_PRU%d failed\n", slice_n);

    if (PRUICSS_pruDisable(prussDrvHandle, rtu_n) != 0)
        UART_printf("PRUICSS_pruDisable for PRUICCSS_RTU%d failed\n", slice_n);

    /* pg version check: only disable txpru if NOT version PG1.0 */
    if (gPgVersion != APP_TEST_AM65XX_PG1_0_VERSION)
    {
        if (PRUICSS_pruDisable(prussDrvHandle, txpru_n) != 0)
            UART_printf("PRUICSS_pruDisable for PRUICCSS_RTU%d failed\n", slice_n);
    }

    /* CLEAR SHARED MEM which is used for host/firmware handshake */
    PRUICSS_pruInitMemory(prussDrvHandle, PRU_ICSS_SHARED_RAM);

    return 0;
}

/**
 * \brief  PRU initialization test function
 *
 * This function used to initialize the PRU subsystem
 *
 * \param   instance [IN]  PRU-ICSS port number
 *
 */
static int32_t BoardDiag_initPruss(uint32_t portNum)
{
    PRUICSS_Handle prussDrvHandle;
    uint8_t pru_n, rtu_n, txpru_n, slice_n;
    BOARD_DIAG_ICSSG_EMAC_PRUICSS_FW_T *firmware;

    if (portNum > 5)
        return -1;

    prussDrvHandle =prussHandle[portNum >> 1];
    if (prussDrvHandle == NULL)
        return -1;
    slice_n = (portNum & 1);
    pru_n = (slice_n) ? PRUICCSS_PRU1 : PRUICCSS_PRU0;
    rtu_n = (slice_n) ? PRUICCSS_RTU1 : PRUICCSS_RTU0;
    txpru_n = (slice_n) ? PRUICCSS_TPRU1 : PRUICCSS_TPRU0;
    txpru_n = txpru_n;
    firmware = (gPgVersion == APP_TEST_AM65XX_PG1_0_VERSION)?firmware_pg1:firmware_pg2;

    if (PRUICSS_pruWriteMemory(prussDrvHandle,PRU_ICSS_IRAM_PRU(slice_n), 0,
                               firmware[slice_n].pru, firmware[slice_n].pru_size) == 0)
    {
         UART_printf("PRUICSS_pruWriteMemory(port %d) for PRUICCSS_PRU%d failed\n", portNum, slice_n);
         return -1;
    }
    if (PRUICSS_pruWriteMemory(prussDrvHandle,PRU_ICSS_IRAM_RTU(slice_n), 0,
                                   firmware[slice_n].rtu, firmware[slice_n].rtu_size) == 0)
    {
        UART_printf("PRUICSS_pruWriteMemory(port %d) for PRUICCSS_RTU%d failed\n", portNum, slice_n);
        return -1;
    }
    if (gPgVersion != APP_TEST_AM65XX_PG1_0_VERSION)
    {
        if (PRUICSS_pruWriteMemory(prussDrvHandle,PRU_ICSS_IRAM_TXPRU(slice_n), 0,
                               firmware[slice_n].txpru, firmware[slice_n].txpru_size) == 0)
        {
            UART_printf("PRUICSS_pruWriteMemory(port %d) for PRUICCSS_TXPRU%d failed\n", portNum, slice_n);
            return -1;
        }
    }
    if (PRUICSS_pruEnable(prussDrvHandle, pru_n) != 0)
    {
        UART_printf("PRUICSS_pruEnable(port: %d) for PRUICCSS_PRU%d failed\n", portNum, slice_n);
        return -1;
    }
    if (PRUICSS_pruEnable(prussDrvHandle, rtu_n) != 0)
    {
        UART_printf("PRUICSS_pruEnable(port: %d) for PRUICCSS_RTU%d failed\n",portNum, slice_n);
        return -1;
    }
    if (gPgVersion != APP_TEST_AM65XX_PG1_0_VERSION)
    {
        if (PRUICSS_pruEnable(prussDrvHandle, txpru_n) != 0)
        {
            UART_printf("PRUICSS_pruEnable(port: %d) for PRUICCSS_TXPRU%d failed\n", portNum, slice_n);
            return -1;
        }
    }

    return 0;
}

void BoardDiag_setupFwDualmac(uint32_t port_num, EMAC_HwAttrs_V5 *pEmacCfg)
{
    EMAC_FW_APP_CONFIG *pFwAppCfg;
    emacGetDualMacFwAppInitCfg(port_num, &pFwAppCfg);
    if ((port_num % 2) == 0)
    {
        pFwAppCfg->txPortQueueLowAddr = 0xFFFFFFFF & ((uint32_t) &icss_tx_port_queue[port_num >> 1][0]);
    }
    else
    {
        pFwAppCfg->txPortQueueLowAddr = 0xFFFFFFFF & ((uint32_t) &icss_tx_port_queue[port_num >> 1][TX_BUFF_POOL_TOTAL_DUAL_MAC]);
    }

    pFwAppCfg->txPortQueueHighAddr = 0;

    emacSetDualMacFwAppInitCfg(port_num, pFwAppCfg);

    /* Need to update the emac configuraiton with  function required by the driver to get the FW configuration to write to shared mem */
    pEmacCfg->portCfg[port_num].getFwCfg = &emacGetDualMacFwConfig;
}

/**
 * \brief  ICSSG emac loopback test function
 *
 * This test is used to verify the Ethernet interface by sending and receiving
 * the same number of packets using external loopback cable.
 *
 * \param   portNum [IN] EMAC port number
 *
 * \return  int8_t
 *              0  - in case of success
 *             -1  - in case of failure
 *
 */
static int8_t BoardDiag_icssgemacLoopbackTest(uint32_t portNum)
{
    EMAC_OPEN_CONFIG_INFO_T open_cfg;
    EMAC_CONFIG_INFO_T      cfg_info;
    EMAC_DRV_ERR_E          open_ret;
    int8_t   ret    = 0;
    int32_t chanNum = 0;
    int32_t subChanNum = 0;

    EMAC_socGetInitCfg(0, &emac_cfg);
    emac_cfg.portCfg[portNum].nTxChans = 1;
    emac_cfg.portCfg[portNum].rxChannel.nsubChan = 1;
    emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.nsubChan = 1;
    emac_cfg.portCfg[portNum].rxChannel2CfgOverPSI.nsubChan = 0;

    emac_cfg.portCfg[portNum].txChannel[chanNum].chHandle = (void *)&gUdmaTxChObj[portNum];
    emac_cfg.portCfg[portNum].txChannel[chanNum].freeRingMem= (void*)&gTxRingMem[portNum][0];
    emac_cfg.portCfg[portNum].txChannel[chanNum].compRingMem= (void*)&gTxCompRingMem[portNum][0];
    emac_cfg.portCfg[portNum].txChannel[chanNum].hPdMem = (void*)&gUdmapDescRamTx[portNum][0];

    emac_cfg.portCfg[portNum].rxChannel.chHandle = (void *)&gUdmaRxChObj[portNum];
    emac_cfg.portCfg[portNum].rxChannel.subChan[subChanNum].freeRingMem[0] = (void*)&gRxRingMem[portNum][0];
    emac_cfg.portCfg[portNum].rxChannel.subChan[subChanNum].compRingMem= (void*)&gRxCompRingMem[portNum][0];
    emac_cfg.portCfg[portNum].rxChannel.subChan[subChanNum].hPdMem[0] = (void*)&gUdmapDescRamRx[portNum][0];
    emac_cfg.portCfg[portNum].rxChannel.subChan[subChanNum].eventHandle = (void *)&gUdmaRxCqEventObj[portNum];


    emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.chHandle = (void *)&gUdmaRxCfgPsiChObj[portNum];
    emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.subChan[subChanNum].freeRingMem[0] = (void*)&gRxCfgPsiRingMem[portNum][0];
    emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.subChan[subChanNum].compRingMem= (void*)&gRxCfgPsiCompRingMem[portNum][0];
    emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.subChan[subChanNum].hPdMem[0] = (void*)&gUdmapDescRamRxCfgPsi[portNum][0];
    emac_cfg.portCfg[portNum].rxChannelCfgOverPSI.subChan[subChanNum].eventHandle = (void *)&gUdmaRxCfgPsiCqEventObj[portNum];

    /* Firmware config */
    BoardDiag_setupFwDualmac(portNum, &emac_cfg);

    /* Now set the config*/
    EMAC_socSetInitCfg(0, &emac_cfg);

    BoardDiag_appInit();

    memset(&open_cfg, 0, sizeof(EMAC_OPEN_CONFIG_INFO_T));
    open_cfg.hwAttrs            = (void*)&emac_cfg;
    open_cfg.alloc_pkt_cb       = BoardDiag_AppAllocPkt;
    open_cfg.free_pkt_cb        = BoardDiag_AppFreePkt;
    open_cfg.loop_back          = 0;
    open_cfg.master_core_flag   = 1;
    open_cfg.max_pkt_size       = BOARD_DIAG_ICSS_EMAC_INIT_PKT_SIZE;
    open_cfg.mdio_flag          = 1;
    open_cfg.num_of_chans       = 1;
    open_cfg.num_of_rx_pkt_desc = BOARD_DIAG_ICSS_EMAC_TX_PKT_DESC_COUNT;
    open_cfg.num_of_tx_pkt_desc = BOARD_DIAG_ICSS_EMAC_RX_PKT_DESC_COUNT;
    open_cfg.phy_addr           = gBoardDiagMdioInfo[portNum].phyAddrs;
    open_cfg.p_chan_mac_addr    = &chan_cfg[0];
    open_cfg.rx_pkt_cb          = BoardDiag_AppTestRxPktCb;
    open_cfg.mode_of_operation  = EMAC_MODE_POLL;
    open_cfg.udmaHandle = (void*)gDrvHandle;

    /* Set the channel configuration */
    chan_cfg[0].chan_num         = 0;
    chan_cfg[0].num_of_mac_addrs = 1;

    macTest.addr[0] = 0x48;
    macTest.addr[1] = 0x93;
    macTest.addr[2] = 0xfe;
    macTest.addr[3] = 0xfa;
    macTest.addr[4] = 0x18;
    macTest.addr[5] = 0x44;
    chan_cfg[0].p_mac_addr = & macTest;

    open_ret = emac_open(portNum, &open_cfg);
    if (open_ret == EMAC_DRV_RESULT_OPEN_PORT_ERR)
    {
        UART_printf("main: emac_open failure: %d\n", open_ret);
        return (-1);
    }
    else
        UART_printf("main: emac_open success\n");


    BoardDiag_initPruss(portNum);

    cfg_info.mcast_cnt    = 0;
    cfg_info.p_mcast_list = NULL;
    cfg_info.rx_filter    = EMAC_PKTFLT_MULTICAST;;
    emac_config(portNum, &cfg_info);

    UART_printf("\n\nWaiting for LINK UP, Make sure to plugin loopback cable\n");
    if(BoardDiag_icssgEmacLinkDetect(portNum))
    {
        UART_printf("PRU_ICSS port %d LINK TIMEOUT!!\n",portNum);
    }
    else
    {
        UART_printf("PRU_ICSS port %d LINK IS UP!\n",portNum);
    }

    return (ret);
}

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
void BoardDiag_IcssgUdmaInit(void)
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
    initPrms.rmInitPrms.numIrIntr = BOARD_DIAG_ICSS_EMAC_MAX_PORTS;
    retVal = Udma_init(&gUdmaDrvObj, &initPrms);
    if(UDMA_SOK == retVal)
    {
        gDrvHandle = &gUdmaDrvObj;
    }
}


/**
 * \brief  emac test BoardDiag_IcssgEmacTestDisplayResults
 *
 * This function displays results and returns test results per port
 *
 * \param   
            portNum         port humber
            pktRcvCount     pakckets received per port
 *
 * \return  void
 *              0  - in case of success
 *              1  - in case of failure
 *
 */

int8_t BoardDiag_IcssgEmacTestDisplayResults(uint32_t portNum, uint32_t pktRcvCount)
{
    int8_t retVal;
    UART_printf("\nPackets Sent: %d, Packets Received: %d\n",
                BOARD_DIAG_ICSS_EMAC_PKT_SEND_COUNT, pktRcvCount);
    if (pktRcvCount == BOARD_DIAG_ICSS_EMAC_PKT_SEND_COUNT)
    {
        if (portNum == (BOARD_DIAG_ICSS_EMAC_MAX_PORTS -1))
            UART_printf("Port %d Send to Port %d Receive Test Passed!!\n",
                    portNum, (portNum  -1));
        else
            UART_printf("Port %d Send to Port %d Receive Test Passed!!\n",
                    portNum, (portNum  +1));
        retVal = 0;
    }
    else
    {
        if (portNum == (BOARD_DIAG_ICSS_EMAC_MAX_PORTS-1))
            UART_printf("Port %d Send to Port %d Receive Test Failed!!\n",
                    portNum, (portNum  -1));
        else
            UART_printf("Port %d Send to Port %d Receive Test Failed!!\n",
                    portNum, (portNum  +1));
        retVal = -1;
    }
    return retVal;
}



/**
 * \brief  emac test function
 *
 * This function executes emac diagnostic test on interposer
 *
 * \param   portNum [IN] EMAC port number
 *
 * \return  int8_t
 *              0  - in case of success
 *              1  - in case of failure
 *
 */
int8_t BoardDiag_IcssgEmacTestInterposer(void)
{
    int8_t  ret;
    uint32_t portNum;
    uint8_t startInstance = 0;
    uint32_t startPort;
    PRUICSS_Config  *prussCfg;

    UART_printf  ("***************************************\n");
    UART_printf  ("*           ICSSG EMAC TEST           *\n");
    UART_printf  ("***************************************\n");

    startInstance = startInstance;
#if defined (am65xx_idk)
    startInstance = PRUICCSS_INSTANCE_ONE;
    startPort     = 0;
#else
    startInstance = PRUICCSS_INSTANCE_THREE;
    startPort     = 4;
#endif

    UART_printf("\n\nPerforming UDMA driver init...\n");
    BoardDiag_IcssgUdmaInit();

    UART_printf("\n\nReading Ethernet PHY Register Dump...\n");
    for(portNum = startPort; portNum < BOARD_DIAG_ICSS_EMAC_MAX_PORTS; portNum++)
    {
        if((portNum == 2) || (portNum == 3))
            continue;
        ret = BoardDiag_getPhyRegDump(portNum);
        if(ret != 0)
        {
            UART_printf("Strapping Registers data mismatch\n");
        }
    }

    PRUICSS_socGetInitCfg(&prussCfg);
    prussHandle[0] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_ONE);
    prussHandle[1] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_TWO);
    prussHandle[2] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_THREE);

    for(portNum = startPort; portNum < BOARD_DIAG_ICSS_EMAC_MAX_PORTS; portNum++)
    {
        BoardDiag_disablePruss(portNum);
    }

    for(portNum = startPort; portNum < BOARD_DIAG_ICSS_EMAC_MAX_PORTS; portNum++)
    {
        ret = BoardDiag_icssgemacLoopbackTest(portNum);
        if(ret != 0)
        {
            return ret;
        }
    }
    uint32_t index;
    for(portNum = startPort; portNum < BOARD_DIAG_ICSS_EMAC_MAX_PORTS;portNum++)
    {
        gTxPktCount = 0;
        gPktRcvCount = 0;
        /* with presence of interposer card, we dont send on ports 0 and 2 */
        if((portNum == 0) || (portNum == 2))
             continue;
        UART_printf("\n\nSending Packets on Port - %d\n", portNum);
        for (index = 0; index < BOARD_DIAG_ICSS_EMAC_PKT_SEND_COUNT; index++)
        {
            BoardDiag_appTestSendPkts(portNum);
            /* Wait to allow packets to come back */
            BOARD_delay(1000);
                if (portNum == 1)
                {
                    emac_poll_pkt(portNum-1);
                }
                else if (portNum == 3)
                {
                    emac_poll_pkt(portNum-1);
                }
                else if (portNum == 4)
                {
                    emac_poll_pkt(portNum + 1);
                }
                else if (portNum == 5)
                {
                    emac_poll_pkt(portNum - 1);
                }
        }

        ret = BoardDiag_IcssgEmacTestDisplayResults(portNum, gPktRcvCount);
        if (ret == -1)
        {
            break;
        }
    }

    for(portNum = startPort; portNum < BOARD_DIAG_ICSS_EMAC_MAX_PORTS; portNum++)
    {
        emac_close(portNum);
    }

    Udma_deinit(&gUdmaDrvObj);

    if(ret)
    {
        UART_printf("\n\nICSSG Ethernet Port to Port Test Failed!!\n");
    }
    else
    {
        UART_printf("\n\nICSSG Ethernet Port to Port Test Passed!\n");
    }

    UART_printf("All Tests Completed\n");

    return ret;
}

/**
 * \brief  emac test function
 *
 * This function executes emac diagnostic test
 *
 * \param   portNum [IN] EMAC port number
 *
 * \return  int8_t
 *              0  - in case of success
 *              1  - in case of failure
 *
 */
int8_t BoardDiag_IcssgEmacTest(void)
{
    int8_t  ret;
    uint32_t portNum;
    uint32_t startPort;
    PRUICSS_Config  *prussCfg;
    uint32_t index;


#ifdef DIAG_STRESS_TEST
    UART_printf  ("**********************************************\n");
    UART_printf  ("*           ICSSG EMAC STRESS TEST           *\n");
    UART_printf  ("**********************************************\n");
#else
    UART_printf  ("***************************************\n");
    UART_printf  ("*           ICSSG EMAC TEST           *\n");
    UART_printf  ("***************************************\n");
#endif

#if defined (am65xx_idk)
    startPort     = 0;

    /* Check for the IDK board version
       If Board_getIDInfo_v2 function fails, it indicates
       intial version of boards withour board ID for which
       no need to change the strapping details */
    if(!Board_getIDInfo_v2(&gIcssEmacBoardInfo,
                           BOARD_ICSS_EMAC_APP_BOARDID_ADDR))
    {
        /* HW Strapping is different on E4 IDK.
           Update the expected default strap values */
        if(gIcssEmacBoardInfo.boardInfo.pcbRev[1] >= '4')
        {
            for(portNum = startPort; portNum < BOARD_ICSS_MAX_PORTS_IDK; portNum++)
            {
                gBoardDiagMdioInfo[portNum].strapst1 &= ~0x6000;
            }
        }
    }
#else
    startPort     = 4;
#endif

    UART_printf("\n\nPerforming UDMA driver init...\n");
    BoardDiag_IcssgUdmaInit();

    UART_printf("\n\nReading Ethernet PHY Register Dump...\n");
    for(portNum = startPort; portNum < BOARD_DIAG_ICSS_EMAC_MAX_PORTS; portNum++)
    {
        ret = BoardDiag_getPhyRegDump(portNum);
        if(ret != 0)
        {
            UART_printf("Strapping Registers data mismatch\n");
        }
    }

    PRUICSS_socGetInitCfg(&prussCfg);
    prussHandle[0] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_ONE);
    prussHandle[1] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_TWO);
    prussHandle[2] =  PRUICSS_create((PRUICSS_Config*)prussCfg,PRUICCSS_INSTANCE_THREE);

    for(portNum = startPort; portNum < BOARD_DIAG_ICSS_EMAC_MAX_PORTS; portNum++)
    {
        BoardDiag_disablePruss(portNum);
    }

    for(portNum = startPort; portNum < BOARD_DIAG_ICSS_EMAC_MAX_PORTS; portNum++)
    {
        ret = BoardDiag_icssgemacLoopbackTest(portNum);
        if(ret != 0)
        {
            return ret;
        }
    }
    for(portNum = startPort; portNum < BOARD_DIAG_ICSS_EMAC_MAX_PORTS;portNum++)
    {
        uint32_t timeout;
        UART_printf("\n\nSending Packets on Port - %d\n", portNum);
        if ((portNum % 2U) == 0)
            UART_printf("Receiving Packets on Port - %d\n\n", (portNum +1));
        else
            UART_printf("Receiving Packets on Port - %d\n\n", (portNum - 1));
        gTxPktCount = 0;
        gPktRcvCount = 0;
        for (index = 0; index < BOARD_DIAG_ICSS_EMAC_PKT_SEND_COUNT; index++)
        {
            gPktRcvd = 0;
            timeout  = 0;

            BoardDiag_appTestSendPkts(portNum);

            while(gPktRcvd == 0)
            {
                if ((portNum % 2U) == 0)
                    emac_poll_pkt(portNum +1);
                else
                    emac_poll_pkt(portNum - 1);
                /* Wait 1msec */
                BOARD_delay(1000);
                timeout++;
                if(timeout >= BOARD_DIAG_ICSSEMAC_TEST_TIMEOUT)
                {
                    UART_printf("\nReceive Timeout!\n");
                    ret = -1;
                    break;
                }
            }
#if defined(DIAG_STRESS_TEST)
            char rdBuf = 'y';
            /* Check if there a input from console to break the test */
            rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
            if((rdBuf == 'b') || (rdBuf == 'B'))
            {
                UART_printf("Received Test Termination... Exiting the Test\n\n");
                UART_printf("\nPackets Sent: %d, Packets Received: %d\n",
                            gTxPktCount, gPktRcvCount);

                if (gPktRcvCount != gTxPktCount)
                {
                    UART_printf("Port %d Send to Port %d Receive Test Failed!!\n",
                                portNum, (portNum + 1));
                    ret = -1;
                }
                else
                {
                    UART_printf("Port %d Send to Port %d Receive Test Passed!\n",
                                portNum, (portNum + 1));
                    ret = 0;
                }
                goto end_test;
            }
#endif
        }

        ret = BoardDiag_IcssgEmacTestDisplayResults(portNum, gPktRcvCount);
        if (ret == -1)
        {
            break;
        }
    }

#if defined(DIAG_STRESS_TEST)
end_test:
#endif
    for(portNum = startPort; portNum < BOARD_DIAG_ICSS_EMAC_MAX_PORTS; portNum++)
    {
        emac_close(portNum);
    }

    Udma_deinit(&gUdmaDrvObj);

    if(ret)
    {
        UART_printf("\n\nICSSG Ethernet Port to Port Test Failed!!\n");
    }
    else
    {
        UART_printf("\n\nICSSG Ethernet Port to Port Test Passed!\n");
    }

    UART_printf("All Tests Completed\n");

    return ret;
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

    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO |
               BOARD_INIT_ICSS_ETH_PHY;

    Board_init(boardCfg);
    gPgVersion = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_JTAGID);
    if (gPgVersion == APP_TEST_AM65XX_PG1_0_VERSION)
    {
        if (BoardDiag_DetectInterposerCard() == TRUE)
        {
            UART_printf("Interposer card is  present\n");
            interposerCardPresent = 1;
            return BoardDiag_IcssgEmacTestInterposer();
        }
        else
        {
            UART_printf("Interposer card is  not present\n");
            return BoardDiag_IcssgEmacTest();
        }
    }
    else
    {
        UART_printf("Interposer card is NOT present\n");
        return BoardDiag_IcssgEmacTest();
    }

}
