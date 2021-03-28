/*
 * Copyright (C) 2010-2017 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *   @file  test_main.c
 *
 *   @brief
 *      This is the Loopback test code for the EMAC Driver. The test code uses
 *      XDC/BIOS and showcases usage of the EMAC Driver exported API
 *      for sending/receiving Ethernet packets.
 */
#include <string.h>

#include <xdc/std.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Memory.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/heaps/HeapBuf.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <ti/sysbios/hal/Hwi.h>

#include <xdc/cfg/global.h>

/* CSL Chip Functional Layer */
#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_cache.h>
#include <ti/csl/csl_mdio.h>
#include <ti/csl/cslr_mdio.h>

#include <ti/drv/emac/soc/emac_soc_v0.h>

#include <ti/csl/cslr_emac.h>

#if defined(C6457) || defined(C6474) || defined(C6472)
#include <ti/csl/cslr_ddr2.h>
#endif

/* EMAC Driver Header File. */
#include <ti/drv/emac/emac_hwcfg.h>
#include <ti/drv/emac/emac_drv.h>

/* Test application local header file */
#include "test_loc.h"

#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
/* Board Level Header Files */
#include <ti/board/board.h>
#include <ti/drv/uart/UART_stdio.h>
#endif


extern void Osal_enterSingleCoreCriticalSection(Uint32      port_num);
extern void Osal_exitSingleCoreCriticalSection(Uint32      port_num);

extern void Osal_beginMemAccess(void*   addr, Uint32  size);
extern void Osal_endMemAccess(void*   addr, Uint32  size);

#define MDIOR   ((CSL_MdioRegs *) CSL_MDIO_0_REGS)

/**
 *
 *  EMAC port states
 */
#define APP_EMAC_PORT_STATE_CLOSE       0
#define APP_EMAC_PORT_STATE_OPEN        1
#define APP_EMAC_PORT_STATE_LINKUP      2
#define APP_EMAC_PORT_STATE_LINKDN      3
/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/* Memory allocated for the packet buffer. This is 128 bytes aligned. */
Uint8   app_pkt_buffer[APP_TOTAL_PKTBUF_SIZE];
#pragma DATA_SECTION(app_pkt_buffer, ".far:PKTBUF_L2MEM")
//#pragma DATA_SECTION(app_pkt_buffer, "msmc")
#pragma DATA_ALIGN(app_pkt_buffer, CACHE_L2_LINESIZE)

/* Memory allocated for the application control block */
APP_EMAC_MCB_T   app_mcb;
#pragma DATA_SECTION(app_mcb, ".far:APP_EMAC")

/**********************************************************************
 ****************** Test Configuration Variables **********************
 **********************************************************************/
/* Packet buffer allocated in external memory flag */
#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
Bool    pktbuf_extmem = TRUE;
#else
Bool    pktbuf_extmem = FALSE;
#endif

#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
#define DEBUG_printf   UART_printf
#else
#define DEBUG_printf   System_printf
#endif

/**********************************************************************
 ************************ EMAC TEST FUNCTIONS *************************
 **********************************************************************/


/**
 *  @b app_queue_pop
 *  @n
 *      Dequeues a packet descriptor from an app queue.
 *
 *  @param[in]  pq
 *      Packet queue of type APP_PKT_QUEUE_T .
 *
 *  @retval
 *      EMAC_Pkt popped from the queue.
 */
static EMAC_PKT_DESC_T*
app_queue_pop
(
    Uint32              port_num,
    APP_PKT_QUEUE_T*    pq
)
{
    EMAC_PKT_DESC_T*    pPktHdr;

    if (!pq->Count)
    {
        return 0;
    }

    Osal_enterSingleCoreCriticalSection(port_num);
    pPktHdr = pq->pHead;
    if( pPktHdr )
    {
        pq->pHead = pPktHdr->pNext;
        pq->Count--;
        pPktHdr->pPrev = pPktHdr->pNext = 0;
    }
    Osal_exitSingleCoreCriticalSection(port_num);

    return( pPktHdr );
}

/**
 *  @b app_queue_push
 *  @n
 *      Enqueues a packet in EMAC_Pkt queue.
 *
 *  @param[in]  pq
 *      Packet queue of type EMAC_PKT_QUEUE_T .
 *  @param[in]  pPktHdr
 *      EMAC_PKT_DESC_T type packet to push.
 *
 *  @retval
 *      void
 */
static void
app_queue_push
(
    Uint32              port_num,
    APP_PKT_QUEUE_T*    pq,
    EMAC_PKT_DESC_T*    pPktHdr
)
{
    Osal_enterSingleCoreCriticalSection(port_num);
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
    Osal_exitSingleCoreCriticalSection(port_num);
}

void
DDR2Init
(
    void
)
{
#ifdef C6472
    // DDR2 init here
    /* Configure DDR for 533MHz operation (sequence is order dependent) */
    DDR2C->SDCFG        = 0x00538832; /* Unlock boot + timing, 32bit wide */
    DDR2C->SDRFC        = 0x0000073B; /* Refresh 533Mhz */
    DDR2C->SDTIM1       = 0x47245BD2; /* Timing 1 */
    DDR2C->SDTIM2       = 0x0125DC44; /* Timing 2 */
    DDR2C->DMCCTL       = 0x50001906; /* PHY read latency for CAS 5 is 5 + 2 - 1 */
    DDR2C->SDCFG        = 0x00530832; /* Lock, 32bit wide */
#endif

#ifdef C6457
    // Setup DDR2 timings @ 660.0 / 2 MHz (External clock * 10 / 2)
    DDR2C->SDCFG        =   0x00D38A32; // Unlock boot + timing, 32bit wide CAS: 5
    DDR2C->SDRFC        =   0x00000A0E; // (ddr2_freq / 2) * 7.8e-6 : ddr2_freq=660MHz
    DDR2C->SDTIM1       =   0x832474DA; // Timing 1
    DDR2C->SDTIM2       =   0x3D44C742; // Timing 2

    // PHY read	latency	for	CAS	5
    DDR2C->DMCCTL       =   (DDR2C->DMCCTL & 0xFFFFFFF8) | ( 5 + 1);
    DDR2C->SDCFG        =   0x00530A32; /* Lock, 32bit wide	*/
#endif

#ifdef C6474
    // Setup DDR2 timings @ 660.0 / 2 MHz (External clock * 10 / 2)
    DDR2C->SDCFG        =   0x00D38A32; // Unlock boot + timing, 32bit wide CAS: 5
    DDR2C->SDRFC        =   0x00000a29; // (ddr2_freq / 2) * 7.8e-6 : ddr2_freq=660MHz
    DDR2C->SDTIM1       =   0x4D246C9A; // Timing 1
    DDR2C->SDTIM2       =   0x00993c42; // Timing 2
    // PHY read latency for CAS 5
    DDR2C->DMCCTL       =   0x50001906;
    DDR2C->SDCFG        =   0x00538A32; /* Lock, 32bit wide */
#endif
}

#if defined(C6457) || defined(C6472) || defined(C6474)
/**
 *  @b EVM_pllc_init
 *  @n
 *     Configure PLL1, PLL2, PLL3.
 *
 *  @param[in]  count
 *           PLL multiplier
 *
 *  @retval
 *      void
 */
void EVM_pllc_init(int count)
{
    int i;
    /* Multiplier value */
    int PLLM_val = count;
    /* TPCC, TPTC, DMA SCR, CFG SCR, Boot, Bridges, Peripherals */
    int PLLDIV7_val = 3;
    /* PSC and SYSCLKOUT */
    int PLLDIV8_val = 4;
    /* SMC and memory */
    int PLLDIV9_val = 2;
    /* GEM trace logic */
    int PLLDIV10_val = 3;

    /** PLL 1 configuration *****************************************/

    /* In PLLCTL, write PLLENSRC = 0 (enable PLLEN bit).*/
    *(int *)PLLCTL_1 &= ~(0x00000020);
    /* In PLLCTL, write PLLEN = 0 (bypass mode).*/
    *(int *)PLLCTL_1 &= ~(0x00000001);
    /* Wait 4 cycles of the slowest of PLLOUT or reference clock source (CLKIN).*/
    for (i=0 ; i<100 ; i++);
    /*In PLLCTL, write PLLRST = 1 (PLL is reset).*/
    *(int *)PLLCTL_1 |= 0x00000008;
    /*If necessary, program PREDIV and PLLM.*/
    *(int *)PLLM_1 = PLLM_val - 1;

    /* Check that the GOSTAT bit in PLLSTAT is cleared to show that no GO
    operation is currently in progress.*/
    while( (*(int *)PLLSTAT_1) & 0x00000001);

    /* Program the RATIO field in PLLDIVn to the desired new divide-down rate.
    If the RATIO field changed, the PLL controller will flag the change
    in the corresponding bit of DCHANGE.*/
    *(int *)PLLDIV7_1 = (PLLDIV7_val - 1) | 0x8000;
    *(int *)PLLDIV8_1 = (PLLDIV8_val - 1) | 0x8000;
    *(int *)PLLDIV9_1 = (PLLDIV9_val - 1) | 0x8000;
    *(int *)PLLDIV10_1 = (PLLDIV10_val - 1) | 0x8000;

    /* Set the GOSET bit in PLLCMD to initiate the GO operation to change
    the divide values and align the SYSCLKs as programmed.*/
    *(int *)PLLCMD_1 |= 0x00000001;

    /* Read the GOSTAT bit in PLLSTAT to make sure the bit returns to 0
    to indicate that the GO operation has completed.*/
    while( (*(int *)PLLSTAT_1) & 0x00000001);

    /* Wait for PLL to properly reset.(128 CLKIN1 cycles).*/
    for (i=0 ; i<1000 ; i++);

    /* In PLLCTL, write PLLRST = 0 to bring PLL out of reset.*/
    *(int *)PLLCTL_1 &= ~(0x00000008);

    /* Wait for PLL to lock (2000 CLKIN1 cycles). */
    for (i=0 ; i<4000 ; i++);

    /* In PLLCTL, write PLLEN = 1 to enable PLL mode. */
    *(int *)PLLCTL_1 |= (0x00000001);


    /* PLL2 configuration (EMAC) */

    /* In PLLCTL, write PLLENSRC = 0 (enable PLLEN bit).*/
    *(int *)PLLCTL_2 &= ~(0x00000020);
    /* In PLLCTL, write PLLEN = 0 (bypass mode).*/
    *(int *)PLLCTL_2 &= ~(0x00000001);
    /* Wait 4 cycles of the slowest of PLLOUT or reference clock source (CLKIN).*/
    for (i=0 ; i<100 ; i++);
    /*In PLLCTL, write PLLRST = 1 (PLL is reset).*/
    *(int *)PLLCTL_2 |= 0x00000008;

    /* Wait for PLL to properly reset.*/
    for (i=0 ; i<4000 ; i++);

    /* In PLLCTL, write PLLRST = 0 to bring PLL out of reset.*/
    *(int *)PLLCTL_2 &= ~(0x00000008);

    /* Wait for PLL to lock */
    for (i=0 ; i<4000 ; i++);

    /* In PLLCTL, write PLLEN = 1 to enable PLL mode. */
    *(int *)PLLCTL_2 |= (0x00000001);

    for (i=0 ; i<10000 ; i++);


    /** PLL 3 configuration (DDR2) *****************************************/

    /* In PLLCTL, write PLLEN = 0 (bypass mode).*/
    *(int *)PLLCTL_3 &= ~(0x00000001);
    /* Wait 4 cycles of the slowest of PLLOUT or reference clock source (CLKIN).*/
    for (i=0 ; i<100 ; i++);
    /*In PLLCTL, write PLLRST = 1 (PLL is reset).*/
    *(int *)PLLCTL_3 |= 0x00000008;
    /*If necessary, program PREDIV and PLLM.*/
    *(int *)PLLM_3 = PLLM_val - 1;

    /* Check that the GOSTAT bit in PLLSTAT is cleared to show that no GO
    operation is currently in progress.*/
    while( (*(int *)PLLSTAT_3) & 0x00000001);

    /* Set the GOSET bit in PLLCMD to initiate the GO operation to change
    the divide values and align the SYSCLKs as programmed.*/
    *(int *)PLLCMD_3 |= 0x00000001;

    /* Read the GOSTAT bit in PLLSTAT to make sure the bit returns to 0
    to indicate that the GO operation has completed.*/
    while( (*(int *)PLLSTAT_3) & 0x00000001);

    /* Wait for PLL to properly reset.(128 CLKIN1 cycles).*/
    for (i=0 ; i<1000 ; i++);

    /* In PLLCTL, write PLLRST = 0 to bring PLL out of reset.*/
    *(int *)PLLCTL_3 &= ~(0x00000008);

    /* Wait for PLL to lock (2000 CLKIN1 cycles). */
    for (i=0 ; i<4000 ; i++);

    /* In PLLCTL, write PLLEN = 1 to enable PLL mode. */
    *(int *)PLLCTL_3 |= (0x00000001);

}
#endif

#if defined(C6457) || defined(C6474) || defined(C6657)
/******************************************************************************
*
* Function:	readPhyReg
*
* Description:	Reads the phy register.
*
* Parameters:	Uint32 phynum - Address of the phy
*              Uint32 regnum - Phy register number
*
* Return Value: Uint16 - Register value read
******************************************************************************/
Uint16 readPhyReg(Uint32 phynum, Uint32 regnum)
{
    Uint16 value;

    MDIOR->USERACCESS0 = 0                  // Read Phy Id 1
        | ( 1 << 31 )                       // [31] Go
        | ( 0 << 30 )                       // [30] Read
        | ( 0 << 29 )                       // [29] Ack
        | (regnum << 21 )                   // [25-21] PHY register address
        | (phynum << 16 )                   // [20-16] PHY address
        | ( 0 << 0 )                        // [15-0] Data
        ;

    while( MDIOR->USERACCESS0 & 0x80000000 ); // Wait for Results

    value = MDIOR->USERACCESS0;

    return value;
}

/******************************************************************************
*
* Function:	writePhyReg
*
* Description:	Writes to the phy register.
*
* Parameters:	Uint32 phynum - Address of the phy
*              Uint32 regnum - Phy register number
*              Uint16 data   - Data to be written to register
*
* Return Value: void
******************************************************************************/
void writePhyReg(Uint32 phynum, Uint32 regnum, Uint16 data)
{
    MDIOR->USERACCESS0 = 0                  // Read Phy Id 1
        | ( 1 << 31 )                       // [31] Go
        | ( 1 << 30 )                       // [30] Write
        | ( 0 << 29 )                       // [29] Ack
        | (regnum << 21 )                   // [25-21] PHY register address
        | (phynum << 16 )                   // [20-16] PHY address
        | ( data << 0 );                    // [15-0] Data

    while( MDIOR->USERACCESS0 & 0x80000000 ); // Wait for Results
}

/******************************************************************************
*
* Function:	phyInit
*
* Description:	Initialize the phy in loopback mode
*
* Parameters:	uiLoopback - 0 - Phy loopback on port 6
* 						   - 1 - RJ45 loopback enable port 1
*						   - 2 - SGMII loopback on AMC edge
* Return Value: void
******************************************************************************/
void phyInit(Uint32 uiLoopback)
{
    // Enable MDIO interface
    MDIOR->CONTROL = 0x400000A5;

#if defined(C6457) || defined(C6472) || defined(C6474)
    // Disable auto-negotiate
    writePhyReg(24, 0, 0x8140);




    // Turn PPU off to make copper PHY visible at SMI address 0x01
    writePhyReg(27, 4, 0x0081);

    // Configure Marvell 88E6122 PHY
    writePhyReg(0xe, 26, 0x47);    	// Set PHY port 6 SERDES to 0.7V swing
    writePhyReg(0x0e, 0, 0x8140);  	// Configure PHY port 6 SERDES --> C6474 1 at 1000mpbs, full duplex
    writePhyReg(0x16, 0x1, 0x043e); // Force internal switch --> port 6 SERDES to 1000MBPS, full Duplex

    if (uiLoopback == PHY_LOOPBACK)
    {
        // Force 1000mps at port 6 SERDES, line loopback
        writePhyReg(0x0e, 16, 0x106b); 	// 1000mbps

    }
    else if (uiLoopback == COPPER_LOOPBACK)
    {
        // Force 1000mps at copper PHY - port 1, disable auto-negotiate
        writePhyReg(1, 0, 0x8100); 		// 0x8100 = 1000mbps

        //power down port 4
        writePhyReg(0x0c, 0, 0x0800);
    }
    else if (uiLoopback == AMC_MODE)
    {
        // Power down port 1
        writePhyReg(1,0, 0x0800);
        writePhyReg(1, 16, 0x0040);

        // configure port 4
        writePhyReg(0xc, 26, 0x47);    	// Set PHY port 4 SERDES to 0.7V swing
        writePhyReg(0x0c, 0, 0x8140);  	// Configure PHY port 4 SERDES --> AMC port at 1000mbps, full duplex
        writePhyReg(0x14, 0x1, 0x043e); // Force internal switch --> port 4 SERDES to 1000MBPS, full Duplex
    }
    else
    {
        /* Force the PHY to negotiate at 100Mbps link speed */
#ifdef PHY_MODE_1000MBPS
        // Force 1000mps at copper PHY, disable auto-negotiate
        writePhyReg(1, 0, 0x8140); // 0x8140 = 1000mbps
#else
#ifdef PHY_MODE_100MBPS
        //Force 100mps at copper PHY, disable auto-negotiate
        writePhyReg(1, 0, 0xa100); // 0xa100 = 100mbps
#else
        // Enable auto-negotiate
        writePhyReg(1, 0, 0x9140);
#endif
#endif
    }
#endif
}
#endif /* defined(C6457) || defined(C6474) || defined(C6657) */

/**
 *  @b Description
 *  @n
 *      Utility function that is required by the IPC module to set the proc Id.
 *      The proc Id is set via this function instead of hard coding it in the .cfg file
 *
 *  @retval
 *      Not Applicable.
 */
Void myStartupFxn (Void)
{
    DDR2Init();

    /* Initialize the EMAC clock */
#ifdef C6472
    EVM_pllc_init(28);
#endif

#ifdef C6457
    EVM_pllc_init(16);
    phyInit(NORMAL_PHY_MODE);
#endif

#ifdef C6474
    EVM_pllc_init(20);
    phyInit(NORMAL_PHY_MODE);
#endif

#ifdef C6657
    phyInit(NORMAL_PHY_MODE);
#endif
    //CACHE_setL1dSize(CACHE_L1_32KCACHE);
    //CACHE_setL2Size(CACHE_256KCACHE);
}


/**
 *  @b Description
 *  @n
 *      Call back function provided by application for EMAC driver
 *      to allocate a packet descriptor.
 *
 *  @retval
 *      pointer to the allocated packet descriptor.
 */
static EMAC_PKT_DESC_T*
app_alloc_pkt
(
    Uint32              port_num,
    Uint32              pkt_size
)
{
    EMAC_PKT_DESC_T*    p_pkt_desc = NULL;

    if (pkt_size < APP_EMAC_MAX_PKT_SIZE)
    {
        /* Get a packet descriptor from the free queue */
        p_pkt_desc              = app_queue_pop(port_num, &app_mcb.emac_pcb[port_num].freeQueue);
        p_pkt_desc->AppPrivate  = (Uint32)p_pkt_desc;
        p_pkt_desc->BufferLen   = pkt_size;
        p_pkt_desc->DataOffset  = 0;
    }
    else
    {
        DEBUG_printf ("app_alloc_pkt on port %d failed, packet size %d is too big\n", port_num, pkt_size);
    }

    return p_pkt_desc;
}

/**
 *  @b Description
 *  @n
 *      Call back function provided by application for EMAC driver
 *      to free a packet descriptor.
 *
 *  @retval
 *      None.
 */
static void
app_free_pkt
(
    Uint32              port_num,
    EMAC_PKT_DESC_T*    p_pkt_desc
)
{
    /* Free a packet descriptor to the free queue */
    app_queue_push(port_num, &app_mcb.emac_pcb[port_num].freeQueue,
                   (EMAC_PKT_DESC_T *)p_pkt_desc->AppPrivate);
}

/**
 *  @b Description
 *  @n
 *      Call back function provided by application for EMAC driver
 *      to report a received packet descriptor.
 *
 *  @retval
 *      None.
 */
static void
app_rx_pkt
(
    Uint32              port_num,
    EMAC_PKT_DESC_T*    p_pkt_desc
)
{
    EMAC_PKT_DESC_T*    p_pkt_enq;

    p_pkt_enq = (EMAC_PKT_DESC_T *)p_pkt_desc->AppPrivate;
    memcpy(p_pkt_enq, p_pkt_desc, sizeof(EMAC_PKT_DESC_T));

    /* enqueue the received packet descriptor to the channel specific RX queue */
    app_queue_push(port_num, &app_mcb.emac_pcb[port_num].rxQueue[p_pkt_enq->PktChannel],
                  (EMAC_PKT_DESC_T *)p_pkt_enq);
}

/**
 *  @b app_display_linkstatus
 *  @n
 *      This function is called whenever there is a change in link state on
 *      master core.
 *
 *  @param[in]  port_num
 *      EMAC port number.
 *  @param[in]  link_status
 *      Status of the link.
 *
 *  @retval
 *      void
 */
void
app_display_linkstatus
(
    Uint32              port_num,
    Uint32              link_status
)
{
    /* This string array corresponds to link state as defined in csl_mdio.h */
    char *LinkStr[] = { "No Link",
                        "10Mb/s Half Duplex",
                        "10Mb/s Full Duplex",
                        "100Mb/s Half Duplex",
                        "100Mb/s Full Duplex",
                        "1000Mb/s Full Duplex" };

    if (app_mcb.core_num == APP_MASTER_CORE_NUM)
    {
        //DEBUG_printf("Port %d Link Status: %s on PHY %d\n",
         //             port_num, LinkStr[link_status],
         //             app_mcb.emac_pcb[port_num].phy_addr);
    }
}

/**
 *  @b Description
 *  @n
 *     This timer function polls the EMAC ports every 100 msec, it is called from a DSP/BIOS
 *     clock module, see evmc6472.cfg
 *
 *  @retval
 *      Not Applicable.
 */
void
app_timer
(
    void
)
{
    Uint32                  port_num;
    EMAC_LINK_INFO_T        link_info;

    for (port_num=0; port_num<MAX_NUM_EMAC_PORTS; port_num++)
    {
        if(app_mcb.emac_pcb[port_num].emac_state != APP_EMAC_PORT_STATE_CLOSE)
        {
            if (emac_poll(port_num, &link_info) == EMAC_DRV_RESULT_OK)
            {
                if (link_info.link_status_change)
                {
                    if (link_info.link_status == EMAC_LINKSTATUS_NOLINK)
                    {
                        app_mcb.emac_pcb[port_num].emac_state = APP_EMAC_PORT_STATE_LINKDN;
                    }
                    else
                    {
                        app_mcb.emac_pcb[port_num].emac_state = APP_EMAC_PORT_STATE_LINKUP;
                    }
                    app_display_linkstatus(port_num, link_info.link_status);
                }
            }

            if(port_num == 0)
            {
                app_mcb.timer_count++;
            }
        }
    }
}

/**
 *  @b app_verify_packet
 *  @n
 *      Perform a sanity check validation on the packet received
 *
 *  @retval
 *      True on success or False on failure
 */
static Bool
app_verify_packet
(
    EMAC_PKT_DESC_T*    p_pkt_desc,
    Uint32              port_num,
    Uint32              chan_num,
    Uint32              count
)
{
    int         i;
    Uint32      size = count + APP_EMAC_MIN_PL_SIZE + APP_EMAC_HEADER_SIZE;
    Uint8*      pBuf;

    if( (p_pkt_desc->Flags & (EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP)) !=
        (EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP) )
    {
        DEBUG_printf("Verify: Bad Flags %08x\n", p_pkt_desc->Flags);
        return(FALSE);
    }

    if (size > APP_EMAC_MAX_LB_TX_PKT_SIZE)
    {
        size =  APP_EMAC_MAX_LB_TX_PKT_SIZE;
    }

    if(p_pkt_desc->ValidLen != size)
    {
        DEBUG_printf("Verify: Bad ValidLen %d %d\n",p_pkt_desc->ValidLen,count);
        return(FALSE);
    }

    if(p_pkt_desc->DataOffset != 0)
    {
        DEBUG_printf("Verify: Bad DataOffset %d\n",p_pkt_desc->DataOffset);
        return(FALSE);
    }

    if(p_pkt_desc->PktChannel != chan_num)
    {
        DEBUG_printf("Verify: Bad Channel %d\n",p_pkt_desc->PktChannel);
        return(FALSE);
    }

    if(p_pkt_desc->PktLength != size)
    {
        DEBUG_printf("Verify: Bad PktLength %d\n",p_pkt_desc->PktLength);
        return(FALSE);
    }

    if(p_pkt_desc->PktFrags != 1)
    {
        DEBUG_printf("Verify: Bad Frag Count %d\n",p_pkt_desc->PktFrags);
        return(FALSE);
    }

    /* Invalidate cache if data in external memory */
    Osal_beginMemAccess((void*)p_pkt_desc->pDataBuffer, size);

    /* Validate destination address */
    pBuf = p_pkt_desc->pDataBuffer+p_pkt_desc->DataOffset;
    if (strncmp((const char *)pBuf,
        (const char *)app_mcb.emac_pcb[port_num].mac_addr[chan_num][1].addr,
        EMAC_MAC_ADDR_LENTH)!=0)
    {
            DEBUG_printf("Verify: Bad destination address.\n");
            return(FALSE);
    }
    pBuf += EMAC_MAC_ADDR_LENTH;

    /* Validate source address */
    if (strncmp((const char *)pBuf,
        (const char *)app_mcb.emac_pcb[port_num].mac_addr[chan_num][0].addr,
        EMAC_MAC_ADDR_LENTH)!=0)
    {
            DEBUG_printf("Verify: Bad source address.\n");
            return(FALSE);
    }
    pBuf += EMAC_MAC_ADDR_LENTH;

    /* Validate Ether Type and payload */
    for(i=EMAC_MAC_ADDR_LENTH*2; i<size; i++, pBuf++)
    {
        if(*pBuf != (Uint8)count)
        {
            DEBUG_printf("Verify: Bad data at %d (%d)(%d)\n",i,*pBuf,(Uint8)count);
            return(FALSE);
        }
    }

    return(TRUE);
}


/**
 *  @b app_test_task
 *  @n
 *      This is the main UNIT Test Task which executes all the test cases.
 *
 *  @retval
 *      Not Applicable.
 */
static Void app_test_task(UArg arg0, UArg arg1)
{

    EMAC_OPEN_CONFIG_INFO_T     open_cfg;
    EMAC_CHAN_MAC_ADDR_T        chan_cfg[APP_EMAC_NUM_CHANS_PER_CORE];
    EMAC_MAC_ADDR_T             mac_addr[APP_EMAC_NUM_CHANS_PER_CORE*APP_EMAC_NUM_MACADDRS_PER_CHAN];
    EMAC_CONFIG_INFO_T          emac_cfg;
    Uint32                      port_num, chan_num, addr_num;
    Uint8                       def_mac_addr[EMAC_MAC_ADDR_LENTH] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05};
    Uint32                      rx_count[MAX_NUM_EMAC_PORTS][APP_EMAC_NUM_CHANS_PER_CORE];
    Uint32                      tx_count[MAX_NUM_EMAC_PORTS][APP_EMAC_NUM_CHANS_PER_CORE];
    Uint32                      total_rx_count = 0;
    Uint32                      total_tx_count = 0;
    Uint32                      size;
    Bool                        test_complete;
    EMAC_PKT_DESC_T*            p_pkt_desc;
    Uint32                      rx_wait_cnt;
    EMAC_HwAttrs_V0             emac_cfg_v0;

    /*
    *  Configures MAC addresses per channel/port/core
    *  Hardware gives support for 32 MAC addresses for 8 receive channels per EMAC port
    *  Here total 4 MAC addresses are assigned to 8 receive channels on one EMAC port per core
    *  4 MAC addresses per channel
    *
    *  MAC addresses and channels allocated are like mentioned below:
    *
    *  core #      port #      channel #       MAC address
    *  0           0           0               00.01.02.03.04.05
    *                                          00.01.02.03.04.15(address used for loopback test)
    *                                          00.01.02.03.04.25
    *                                          00.01.02.03.04.35
    *
    *  0           0           1               00.01.02.03.14.05
    *                                          00.01.02.03.14.15(address used for loopback test)
    *                                          00.01.02.03.14.25
    *                                          00.01.02.03.14.35
    *                          .
    *                          .
    *                          .
    *
    *  0           1           0               00.01.02.13.04.05
    *                                          00.01.02.13.04.15(address used for loopback test)
    *                                          00.01.02.13.04.25
    *                                          00.01.02.13.04.35
    *
    *  0           1           1               00.01.02.13.14.05
    *                                          00.01.02.13.14.15(address used for loopback test)
    *                                          00.01.02.13.14.25
    *                                          00.01.02.13.14.35
    *                          .
    *                          .
    *                          .
    *
    */

    /* Set the Core specific nibble in the default MAC address */
    def_mac_addr[2] += (Uint8)(app_mcb.core_num * 0x10);

    for (port_num=0; port_num<MAX_NUM_EMAC_PORTS; port_num++)
    {
        EMAC_socGetInitCfg(port_num, &emac_cfg_v0);
        open_cfg.hwAttrs = &emac_cfg_v0;

        /* Set the emac_open configuration */
        if (app_mcb.core_num == APP_MASTER_CORE_NUM)
        {
            open_cfg.master_core_flag   = TRUE;
            open_cfg.mdio_flag          = TRUE;
        }
        else
        {
            open_cfg.master_core_flag   = FALSE;
            open_cfg.mdio_flag          = FALSE;
        }
#if defined(SOC_OMAPL137) || defined (SOC_OMAPL138)
        open_cfg.loop_back              = FALSE;
#else
        open_cfg.loop_back              = TRUE;
#endif
        open_cfg.num_of_tx_pkt_desc     = APP_EMAC_INIT_TX_PKTS;
        open_cfg.num_of_rx_pkt_desc     = APP_EMAC_INIT_RX_PKTS;
        open_cfg.max_pkt_size           = APP_EMAC_INIT_PKT_SIZE;
        open_cfg.num_of_chans           = APP_EMAC_NUM_CHANS_PER_CORE;
        open_cfg.p_chan_mac_addr        = chan_cfg;
        open_cfg.rx_pkt_cb              = app_rx_pkt;
        open_cfg.alloc_pkt_cb           = app_alloc_pkt;
        open_cfg.free_pkt_cb            = app_free_pkt;

        if (port_num == 0)
        {
            open_cfg.phy_addr           = APP_PORT0_PHY_ADDR;
        }
#ifdef TWO_PORT_DEV
        else
        {
            open_cfg.phy_addr           = APP_PORT1_PHY_ADDR;
        }
#endif

        for (chan_num=0; chan_num<APP_EMAC_NUM_CHANS_PER_CORE; chan_num++)
        {
            /* Reset TX/RX count */
            tx_count[port_num][chan_num]           = 0;
            rx_count[port_num][chan_num]           = 0;

            /* Set the channel configuration */
            chan_cfg[chan_num].chan_num            = app_mcb.core_num*APP_EMAC_NUM_CHANS_PER_CORE+chan_num;
            chan_cfg[chan_num].num_of_mac_addrs    = APP_EMAC_NUM_MACADDRS_PER_CHAN;
            chan_cfg[chan_num].p_mac_addr          = &mac_addr[chan_num*APP_EMAC_NUM_MACADDRS_PER_CHAN];

            for (addr_num=0; addr_num<APP_EMAC_NUM_MACADDRS_PER_CHAN; addr_num++)
            {
                memcpy(chan_cfg[chan_num].p_mac_addr[addr_num].addr, def_mac_addr, EMAC_MAC_ADDR_LENTH);

                /* Set the port specific nibble in the MAC address */
                chan_cfg[chan_num].p_mac_addr[addr_num].addr[3] += (Uint8)(port_num * 0x10);

                /* Set the channel specific nibble in the MAC address */
                chan_cfg[chan_num].p_mac_addr[addr_num].addr[4] += (Uint8)(chan_cfg[chan_num].chan_num * 0x10);

                /* Set the MAC address specific nibble in the MAC address */
                chan_cfg[chan_num].p_mac_addr[addr_num].addr[5] += (Uint8)(addr_num * 0x10);

            }
        }



        /* Save the MAC address configuration */
        memcpy(app_mcb.emac_pcb[port_num].mac_addr, mac_addr,
               sizeof(EMAC_MAC_ADDR_T)*APP_EMAC_NUM_CHANS_PER_CORE*APP_EMAC_NUM_MACADDRS_PER_CHAN);

        /* Call low-level open function */
        if (emac_open(port_num, &open_cfg) == EMAC_DRV_RESULT_OK)
        {
            /* Set the 'initial' Receive Filter */
            emac_cfg.rx_filter       = EMAC_PKTFLT_MULTICAST;
            emac_cfg.mcast_cnt       = 0;
            emac_cfg.p_mcast_list    = NULL;

            emac_config(port_num, &emac_cfg);

            app_mcb.emac_pcb[port_num].emac_state = APP_EMAC_PORT_STATE_OPEN;

            /* Enable RX/TX interrupt */
            Osal_exitSingleCoreCriticalSection(port_num);
        }
        else
        {
            DEBUG_printf ("Application open EMAC port %d error \n", port_num);
        }
    }

    while (TRUE)
    {
        if (app_mcb.timer_count > 600)
        {
            /* Time out after 60 sec */
            DEBUG_printf ("Loopback Test failed on core %d\n", app_mcb.core_num);
            for (port_num=0; port_num<MAX_NUM_EMAC_PORTS; port_num++)
            {
                DEBUG_printf ("Packets TX/RX on port %d:\n", port_num);
                for (chan_num=0; chan_num<APP_EMAC_NUM_CHANS_PER_CORE; chan_num++)
                {
                    DEBUG_printf ("Channel %d TX pkts %d, RX pkts %d\n", chan_num,
                                   tx_count[port_num][chan_num],
                                   rx_count[port_num][chan_num]);
                }
            }
			DEBUG_printf ("Some tests have failed\n");
            Task_exit();
            return;
        }

        test_complete = TRUE;
        for (port_num=0; port_num<MAX_NUM_EMAC_PORTS; port_num++)
        {
            if (app_mcb.emac_pcb[port_num].emac_state!=APP_EMAC_PORT_STATE_LINKUP)
            {
                /* EMAC port not opened or link is down, check the next port */
                test_complete =  FALSE;
                continue;
            }

            for (chan_num=0; chan_num<APP_EMAC_NUM_CHANS_PER_CORE; chan_num++)
            {
                if(rx_count[port_num][chan_num] == APP_NUM_TEST_PKTS)
                {
                    /*
                     * The channel has received all the packets,
                     * check the next channel
                     */
                    continue;
                }

                /* Check if we should send a packet */
                if( (tx_count[port_num][chan_num]<APP_NUM_TEST_PKTS)                &&
                    (tx_count[port_num][chan_num]<(rx_count[port_num][chan_num]+8))
                    )
                {
                    /* First get a packet descriptor from the free queue */
                    p_pkt_desc = app_queue_pop(port_num, &app_mcb.emac_pcb[port_num].freeQueue);
                    if(p_pkt_desc)
                    {
                        /* Set the size to be min payload size + 2 bytes of Ether Type */
                        size = tx_count[port_num][chan_num]+APP_EMAC_MIN_PL_SIZE+APP_EMAC_HEADER_SIZE;
                        if (size > APP_EMAC_MAX_LB_TX_PKT_SIZE)
                        {
                            size = APP_EMAC_MAX_LB_TX_PKT_SIZE;
                        }

                        p_pkt_desc->AppPrivate   = (Uint32)p_pkt_desc;
                        p_pkt_desc->Flags        = EMAC_PKT_FLAG_SOP | EMAC_PKT_FLAG_EOP;
                        p_pkt_desc->ValidLen     = size;
                        p_pkt_desc->DataOffset   = 0;
                        p_pkt_desc->PktChannel   = chan_num;
                        p_pkt_desc->PktLength    = size;
                        p_pkt_desc->PktFrags     = 1;


                        /* Fill in the destination address as the loopback address */
                        memcpy(p_pkt_desc->pDataBuffer,
                               app_mcb.emac_pcb[port_num].mac_addr[chan_num][1].addr,
                               EMAC_MAC_ADDR_LENTH);
                        /* Fill in the source address  */
                        memcpy(&p_pkt_desc->pDataBuffer[EMAC_MAC_ADDR_LENTH],
                               app_mcb.emac_pcb[port_num].mac_addr[chan_num][0].addr,
                               EMAC_MAC_ADDR_LENTH);
                        /* Fill in the Ether Type and Payload with LSB of tx_count pattern */
                        memset(&p_pkt_desc->pDataBuffer[EMAC_MAC_ADDR_LENTH*2],
                               (Uint8)tx_count[port_num][chan_num],
                               size-EMAC_MAC_ADDR_LENTH*2);

                        /* Write back cache to memory if data in external memory */
                        Osal_endMemAccess((void*)p_pkt_desc->pDataBuffer, size);

                        emac_send(port_num, p_pkt_desc);

                        /* Increment the TX count */
                        tx_count[port_num][chan_num]++;
                        if ((tx_count[port_num][chan_num] & 0xfff) == 0)
                        {
                            DEBUG_printf ("Sent %d received & verified %d pkts on Core %d Port %d Channel %d \n",
                                           tx_count[port_num][chan_num], rx_count[port_num][chan_num],
                                           app_mcb.core_num, port_num, chan_num);
                        }
                        total_tx_count++;
                    } /* End of if(p_pkt_desc) */

                } /* End of if(tx_count[port_num][chan_num]<APP_NUM_TEST_PKTS) */

                /*
                 * Check if we received a packet
                 */
                rx_wait_cnt = app_mcb.timer_count;
                /* Wait for Rx packet here but not indefinitely.
                 * Use app_mcb.timer_count to wait at most 300msecs for the rx packet */
                while((rx_wait_cnt + 3) > app_mcb.timer_count)
                {

                    p_pkt_desc = app_queue_pop(port_num, &app_mcb.emac_pcb[port_num].rxQueue[chan_num]);
                    if(p_pkt_desc)
                    {
                        /* Validate this packet */
                        if(!app_verify_packet(p_pkt_desc, port_num, chan_num, rx_count[port_num][chan_num]))
                        {
                            DEBUG_printf("ERROR: Core %d Port %d Channel %d verify failure on received packet %d\n",
                                          app_mcb.core_num, port_num, chan_num, rx_count[port_num][chan_num]);
                            /* Free the packet */
                            app_queue_push(port_num, &app_mcb.emac_pcb[port_num].freeQueue, p_pkt_desc );
                            continue;
                        }

                        /* Free the packet */
                        app_queue_push(port_num, &app_mcb.emac_pcb[port_num].freeQueue, p_pkt_desc );

                        /* Increment the RX count */
                        rx_count[port_num][chan_num]++;
                        total_rx_count++;
                        break;
                    }
                }
                test_complete = FALSE;
            } /* End of for (chan_num=0; chan_num<APP_EMAC_NUM_CHANS_PER_CORE; chan_num++) */

        } /* End of for (port_num=0; port_num<MAX_NUM_EMAC_PORTS; port_num++) */

        if (test_complete)
        {
            break;
        }
    } /* End of while(TRUE) */

    /* All the tests passed. */
    DEBUG_printf ("Loopback Test completed successfully on core %d\n", app_mcb.core_num);
    DEBUG_printf ("Total TX packets %d, RX packets %d\n", total_tx_count, total_rx_count);
	DEBUG_printf ("All tests have passed\n");
    Task_exit();
}

/**
*  @b Description
*  @n
*      Intialize the application control block, free/rx packet queue.
*
*  @retval
*      None.
*/
void
app_init
(
    void
)
{
    Uint32              i, j;
    EMAC_PKT_DESC_T*    p_pkt_desc;
    Uint8*              pktbuf_ptr;

#if defined(SOC_OMAPL137)
    Board_init(BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UNLOCK_MMR | BOARD_INIT_UART_STDIO | BOARD_INIT_ETH_PHY);
#endif

#if defined(SOC_OMAPL138)
    Board_init(BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UNLOCK_MMR | BOARD_INIT_UART_STDIO);
#endif

    DEBUG_printf ("%s\n", emac_get_version());
    DEBUG_printf ("EMAC loopback test application initialization\n");

    /* Reset application control block */
    memset(&app_mcb, 0, sizeof (APP_EMAC_MCB_T));

#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
	/* Hardcoding core number to 0.
	 * DNUM returns value 1 for OMAPL13x platform which will enable
     * different buffer offsets configured based on app_mcb.core_num.
	 */
    app_mcb.core_num = 0;
#else
    app_mcb.core_num = CSL_chipReadReg (CSL_CHIP_DNUM);
#endif

    if (pktbuf_extmem)
    {
        /* If packet buffer stored in external memory */
        pktbuf_ptr = (Uint8 *)(APP_EXTMEM+app_mcb.core_num*APP_TOTAL_PKTBUF_SIZE);
    }
    else
    {
        pktbuf_ptr = (Uint8 *) ((Uint32) app_pkt_buffer | 0x10000000);
    }

    /* Initialize the free packet queue */
    for (i=0; i<MAX_NUM_EMAC_PORTS; i++)
    {
        if (i == 0)
        {
            app_mcb.emac_pcb[0].phy_addr   = APP_PORT0_PHY_ADDR;
        }
#ifdef TWO_PORT_DEV
        else
        {
            app_mcb.emac_pcb[1].phy_addr   = APP_PORT1_PHY_ADDR;
        }
#endif

        for (j=0; j<APP_MAX_PKTS; j++)
        {
            p_pkt_desc               = &app_mcb.emac_pcb[i].pkt_desc[j];
            p_pkt_desc->pDataBuffer  = pktbuf_ptr;
            p_pkt_desc->BufferLen    = APP_EMAC_MAX_PKT_SIZE;
            app_queue_push( i, &app_mcb.emac_pcb[i].freeQueue, p_pkt_desc );
            pktbuf_ptr += APP_EMAC_MAX_PKT_SIZE;
        }
    }
}

/**
*  @b Description
*  @n
*      Entry point for the application test code.
*
*  @retval
*      None.
*/
void main(void)
{
    Task_Params     taskParams;

    app_init();

    /* Create the UnitTest Task.*/
    Task_Params_init(&taskParams);
    Task_create(app_test_task, &taskParams, NULL);

    /* Start BIOS */
    BIOS_start();
}

