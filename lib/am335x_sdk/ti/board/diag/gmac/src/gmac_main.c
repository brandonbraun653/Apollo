/**
 *  \file   cpsw_test.c
 *
 *  \brief
 *
 *
 */

/* Copyright (C) 2012-2017 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 */
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/cslr_cpgmac_sl.h>
#include <ti/csl/src/ip/cpgmac/V2/cslr_cpgmac_sl.h>
#include <ti/csl/csl_cpgmac_sl.h>
#include <ti/csl/src/ip/emac/V2/csl_cpgmac_sl.h>
#include <ti/csl/csl_cpgmac_slAux.h>
#include <ti/csl/src/ip/emac/V2/csl_cpgmac_slAux.h>
#include <ti/csl/cslr_cpsw.h>
#include <ti/csl/src/ip/cpsw/V3/cslr_cpsw_3g.h>
#include <ti/csl/src/ip/cpsw/V3/cslr_wr.h>
#include <ti/csl/src/ip/cpdma/V0/cslr_cpdma.h>
#include <ti/csl/csl_cpsw.h>
#include <ti/csl/csl_cpswAux.h>
#include <ti/csl/src/ip/cpsw/V3/csl_cpswAux.h>
#include <ti/csl/cslr_mdio.h>
#include <ti/csl/src/ip/mdio/V2/cslr_mdio.h>
#include <ti/csl/csl_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdio.h>
#include <ti/csl/csl_mdioAux.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdioAux.h>

#include "hw_types.h"
#include <ti/csl/csl_armGicAux.h>
#include <ti/csl/soc.h>
#include "gmac_test.h"
#include <ti/board/board.h>
#include <ti/board/board_cfg.h>

/* Example/Board Header files */
#if defined (idkAM572x)
#include <ti/board/src/idkAM572x/device/enet_phy.h>
#endif
#if defined (idkAM571x)
#include <ti/board/src/idkAM571x/device/enet_phy.h>
#endif
#if defined (evmAM572x)
#include <ti/board/src/evmAM572x/device/enet_phy.h>
#endif
#if defined (idkAM574x)
#include <ti/board/src/idkAM574x/device/enet_phy.h>
#endif

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>


#define REG_IDX_SHIFT           (0x05)
#define REG_BIT_MASK            (0x1F)
#define NUM_BYTES_REG           4

#define MPU_XBAR_INSTANCE_GMAC_SW_IRQ_RX_PULSE  87
#define MPU_XBAR_INSTANCE_GMAC_SW_IRQ_TX_PULSE  88

#define GMAC_SW_IRQ_RX_PULSE_INT_NUM  92
#define GMAC_SW_IRQ_TX_PULSE_INT_NUM  93

/* Enable the below macro to have prints on the IO Console */
//#define IO_CONSOLE

#ifndef IO_CONSOLE
#define GMAC_log                UART_printf
#else
#define GMAC_log                printf
#endif

#define CPSW_INT_PACING_C0_RX_PULSE  (0x01 << CSL_WR_INT_CONTROL_INT_PACE_EN_SHIFT)
#define CPSW_INT_PACING_C0_TX_PULSE  (0x02 << CSL_WR_INT_CONTROL_INT_PACE_EN_SHIFT)

//*****************************************************************************
//  global variables
//*****************************************************************************
extern void Entry(void);
extern void UndefInstHandler(void);
extern void SVC_Handler(void);
extern void PrefetchAbortHandler(void);
extern void AbortHandler(void);
extern void ResvHandler(void);
extern void IRQHandler(void);
extern void FIQHandler(void);

static Uint32 const vecTbl[14]=
{
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF018,    /* Opcode for loading PC with the contents of [PC + 0x18] */
    0xE59FF014,    /* Opcode for loading PC with the contents of [PC + 0x14] */
    0xE24FF008,    /* Opcode for loading PC with (PC - 8) (eq. to while(1)) */
    0xE59FF010,    /* Opcode for loading PC with the contents of [PC + 0x10] */
    0xE59FF010,    /* Opcode for loading PC with the contents of [PC + 0x10] */
    (Uint32)Entry,
    (Uint32)UndefInstHandler,
    (Uint32)SVC_Handler,
    (Uint32)AbortHandler,
    (Uint32)IRQHandler,
    (Uint32)FIQHandler
};

Uint32 CpswBase =               (GMAC_BASEADDRESS);
Uint32 MdioBase =               (GMAC_BASEADDRESS + 0x1000);
Uint32 CpswWrBase =             (GMAC_BASEADDRESS + 0x1200);
Uint32 CpswCpdmaBase =          (GMAC_BASEADDRESS + 0x0800);
Uint32 CpswAleBase =            (GMAC_BASEADDRESS + 0x0D00);
Uint32 CpswStatBase =           (GMAC_BASEADDRESS + 0x0900);
Uint32 CpswStateBase =          (GMAC_BASEADDRESS + 0x0A00);
Uint32 CpswCptsBase =           (GMAC_BASEADDRESS + 0x0C00);
Uint32 CpswPort0Base =          (GMAC_BASEADDRESS + 0x0100);
Uint32 CpswPort1Base =          (GMAC_BASEADDRESS + 0x0200);
Uint32 CpswSl1Base =            (GMAC_BASEADDRESS + 0x0D80);
Uint32 CpswPort2Base =          (GMAC_BASEADDRESS + 0x0300);
Uint32 CpswSl2Base =            (GMAC_BASEADDRESS + 0x0DC0);
Uint32 CpswCppiRamBase =        (GMAC_BASEADDRESS + 0x2000);

Desc    *RxHead[8], *RxTail[8];
Desc    *TxHead[8], *TxTail[8];
Desc    *TxFreeHead, *TxFreeTail;
volatile Uint32  RxQueueCnt[8], TxQueueCnt[8], TxFreeCnt;
volatile Uint32  RxPackets[8]={0,0,0,0,0,0,0,0}, TxPackets[8]={0,0,0,0,0,0,0,0};
volatile Uint32  RxMisqueue[8]={0,0,0,0,0,0,0,0}, TxMisqueue[8]={0,0,0,0,0,0,0,0};
volatile Uint32  TxActive[8]={0,0,0,0,0,0,0,0};

volatile Uint32  fPacing=FALSE, fBlastTransmit=FALSE, fTxP=FALSE, fTxP2=FALSE;
Uint32  fExtRmiiClk=TRUE, fRMII=FALSE, fMII=FALSE, fRGMII=FALSE, fGig=FALSE;
Uint32  BoardType, Phy1Type, Phy2Type, Phy1Addr, Phy2Addr;

CSL_ArmGicIntrParams_t gRxIntrParams;
CSL_ArmGicIntrParams_t gTxIntrParams;

extern CSL_ArmGicDistIntrf distrIntrf;

extern CSL_ArmGicCpuIntrf gCpuIntrf;

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

static void copyVectorTable(void)
{
    Uint32 vectorBase = 0x40300000U;
    Uint32 ocmcRamSize = 512U * 1024U;

    vectorBase = vectorBase + ocmcRamSize - 0x400U;

    Uint32 *dest = (Uint32 *)vectorBase;
    Uint32 *src =  (Uint32 *)vecTbl;
    Uint32 count;

    CSL_a15SetVectorTable(vectorBase);

    for(count = 0; count < sizeof(vecTbl)/sizeof(vecTbl[0]); count++)
    {
        dest[count] = src[count];
    }
}

void startup(void)
{
    gCpuIntrf.gicDist = &distrIntrf;
    gCpuIntrf.cpuIntfBasePtr = (void *)0x48212000U;
    distrIntrf.distBasePtr = (void *)0x48211000U;
    gCpuIntrf.initStatus = FALSE;
    gCpuIntrf.gicDist->initStatus = FALSE;
    gCpuIntrf.pDefaultIntrHandlers = NULL;
    gCpuIntrf.pDefaultUserParameter = NULL;

    CSL_armGicInit(&gCpuIntrf);
}

void Delay(Uint32 delay)
{
    volatile Uint32 delay1 = delay;
    while (delay1--) asm("nop\n");
}

/**
 * \brief   Enables pacing of interrupts.
 *
 * \param   baseAddr    Base address of the CPSW Wrapper Module
 * \param   pacFlag     The interrpupts for which pacing to be enabled
 *    'pacFlag' can take any combination of the below values. \n
 *         CPSW_INT_PACING_C0_RX_PULSE  - Core 0 RX pulse interrupt pacing \n
 *         CPSW_INT_PACING_C0_TX_PULSE  - Core 0 TX pulse interrupt pacing \n
 *         CPSW_INT_PACING_C1_RX_PULSE  - Core 1 RX pulse interrupt pacing \n
 *         CPSW_INT_PACING_C1_TX_PULSE  - Core 1 TX pulse interrupt pacing \n
 *         CPSW_INT_PACING_C2_RX_PULSE  - Core 2 RX pulse interrupt pacing \n
 *         CPSW_INT_PACING_C2_TX_PULSE  - Core 2 TX pulse interrupt pacing \n
 *
 * \return  None
 **/
void CPSWWrIntPacingEnable(unsigned int baseAddr, unsigned int pacFlag)
{
    HWREG(baseAddr + CSL_WR_INT_CONTROL) &= ~CSL_WR_INT_CONTROL_INT_PACE_EN_MASK;
    HWREG(baseAddr + CSL_WR_INT_CONTROL) |= pacFlag;
}

/**
 * \brief   Sets the number of transmit interrupts per millisecond.
 *
 * \param   baseAddr    Base address of the CPSW Wrapper Module
 * \param   core        Core number
 * \param   txIntPerMs  The number of tx interrupts per millisecond
 *    The maximum value for 'txIntPerMs' is 0x3F.
 *
 * \return  None
 **/
void CPSWWrIntTxPerMsSet(unsigned int baseAddr, unsigned int core,
                         unsigned int txIntPerMs)
{
    HWREG(baseAddr + CSL_WR_TX_IMAX(core)) = txIntPerMs;
}

/**
 * \brief   Sets the number of receive interrupts per millisecond.
 *
 * \param   baseAddr    Base address of the CPSW Wrapper Module
 * \param   core        Core number
 * \param   rxIntPerMs  The number of rx interrupts per millisecond
 *    The maximum value for 'rxIntPerMs' is 0x3F.
 *
 * \return  None
 **/
void CPSWWrIntRxPerMsSet(unsigned int baseAddr, unsigned int core,
                         unsigned int rxIntPerMs)
{
    HWREG(baseAddr + CSL_WR_RX_IMAX(core)) = rxIntPerMs;
}

/**
 * \brief   Disables pacing of interrupts
 *
 * \param   baseAddr    Base address of the CPSW Wrapper Module
 * \param   pacFlag     The interrpupts for which pacing to be disabled
 *    'pacFlag' can take any combination of the below values. \n
 *         CPSW_INT_PACING_C0_RX_PULSE  - Core 0 RX pulse interrupt pacing \n
 *         CPSW_INT_PACING_C0_TX_PULSE  - Core 0 TX pulse interrupt pacing \n
 *         CPSW_INT_PACING_C1_RX_PULSE  - Core 1 RX pulse interrupt pacing \n
 *         CPSW_INT_PACING_C1_TX_PULSE  - Core 1 TX pulse interrupt pacing \n
 *         CPSW_INT_PACING_C2_RX_PULSE  - Core 2 RX pulse interrupt pacing \n
 *         CPSW_INT_PACING_C2_TX_PULSE  - Core 2 TX pulse interrupt pacing \n
 *
 * \return  None
 **/
void CPSWWrIntPacingDisable(unsigned int baseAddr, unsigned int pacFlag)
{
   HWREG(baseAddr + CSL_WR_INT_CONTROL) &= ~(pacFlag);
}

//-------------------------------------------------------------------------
// CPSW Interrupt init
//-------------------------------------------------------------------------
void CpswInterruptInit(void)
{
  CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_92, CSL_XBAR_GMAC_SW_IRQ_RX_PULSE);

  CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_93, CSL_XBAR_GMAC_SW_IRQ_TX_PULSE);

    /* Do the interrupt related configurations */
    gRxIntrParams.triggerType = CSL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
    gRxIntrParams.priority = 0x20U;

    /*
     * Assign the ISR to the function pointer to invoke when the
     * interrupt is raised.
     */
    gRxIntrParams.pFnIntrHandler = &ServiceRx;
    gRxIntrParams.pUserParam = NULL;

    /* Configure the interrupt Controller */
    CSL_armGicConfigIntr(&gCpuIntrf, (GMAC_SW_IRQ_RX_PULSE_INT_NUM + 32),
                         &gRxIntrParams);

  CpswIntEnable(RX);

    /* Do the interrupt related configurations */
    gTxIntrParams.triggerType = CSL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
    gTxIntrParams.priority = 0x20U;

    /*
     * Assign the ISR to the function pointer to invoke when the
     * interrupt is raised.
     */
    gTxIntrParams.pFnIntrHandler = &ServiceTx;
    gTxIntrParams.pUserParam = NULL;

    /* Configure the interrupt Controller */
    CSL_armGicConfigIntr(&gCpuIntrf, (GMAC_SW_IRQ_TX_PULSE_INT_NUM + 32),
                         &gTxIntrParams);

  CpswIntEnable(TX);

}


//-------------------------------------------------------------------------
// Link setup
//-------------------------------------------------------------------------
Uint32 LinkSetup(Uint32 port, Uint32 speed)
{
    Uint32 val, retries;
    Uint32 phy_addr=0, SlBase=0;
    Uint32 val16, debug_data;
    Uint32 speed_duplex=0, speed_detected=100, loopback=0;
    CSL_CPSW_ALE_PORTCONTROL pPortControlInfo;
    ENETPHY_DEVICE phyDev;

    phyDev.miibase = MdioBase;
    if(port==1)
    {
        phy_addr=Phy1Addr;
        SlBase=CpswSl1Base;
    }
    else if(port==2)
    {
        phy_addr=Phy2Addr;
        SlBase=CpswSl2Base;
    }
    else
    {
        GMAC_log("                                ");
        return 1;
    }

    //put port into a disabled state in ale and mac_sl
    CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) CpswBase, port, &pPortControlInfo);
    pPortControlInfo.portState = 0x00U;
    CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) CpswBase, port, &pPortControlInfo);

    CSL_CPGMAC_SL_disableGMII((CSL_cpgmacSlHandle) SlBase);

    //set the mac to non-gig mode to start with incase we error out later
    switch(speed)
    {
        case SPEED_10H:
            CSL_CPGMAC_SL_disableGigabit((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_disableFullDuplex((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_disableTxFlowControl((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_disableRxFlowControl((CSL_cpgmacSlHandle) SlBase);
            if(fRMII)
                CSL_CPGMAC_SL_disableIFCTLA((CSL_cpgmacSlHandle) SlBase);
            if(fRGMII)
                CSL_CPGMAC_SL_enableExtControl((CSL_cpgmacSlHandle) SlBase);
            break;
        case SPEED_100H:
            CSL_CPGMAC_SL_disableGigabit((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_disableFullDuplex((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_disableTxFlowControl((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_disableRxFlowControl((CSL_cpgmacSlHandle) SlBase);
            if(fRMII)
                CSL_CPGMAC_SL_enableIFCTLA((CSL_cpgmacSlHandle) SlBase);
            if(fRGMII)
                CSL_CPGMAC_SL_disableExtControl((CSL_cpgmacSlHandle) SlBase);
            break;
        case SPEED_10F:
            CSL_CPGMAC_SL_disableGigabit((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_enableFullDuplex((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_enableTxFlowControl((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_enableRxFlowControl((CSL_cpgmacSlHandle) SlBase);
            if(fRMII)
                CSL_CPGMAC_SL_disableIFCTLA((CSL_cpgmacSlHandle) SlBase);
            if(fRGMII)
                CSL_CPGMAC_SL_enableExtControl((CSL_cpgmacSlHandle) SlBase);
            break;
        case SPEED_100F:    
            CSL_CPGMAC_SL_disableGigabit((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_enableFullDuplex((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_enableTxFlowControl((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_enableRxFlowControl((CSL_cpgmacSlHandle) SlBase);
            if(fRMII)
                CSL_CPGMAC_SL_enableIFCTLA((CSL_cpgmacSlHandle) SlBase);
            if(fRGMII)
                CSL_CPGMAC_SL_disableExtControl((CSL_cpgmacSlHandle) SlBase);
            break;
        case SPEED_1000F:
        case SPEED_LB:
            CSL_CPGMAC_SL_enableGigabit((CSL_cpgmacSlHandle) SlBase);
            CSL_CPGMAC_SL_enableFullDuplex((CSL_cpgmacSlHandle) SlBase);
            if(fRGMII)
                CSL_CPGMAC_SL_disableExtControl((CSL_cpgmacSlHandle) SlBase);
            break;
    }
  
    Delay(100000);

    //check phy is alive
    if(!CSL_MDIO_isPhyAlive((CSL_mdioHandle) MdioBase, phy_addr))
    {
        GMAC_log("                                ");
        return 2;
    }

    //reset phy
    ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, 0x8000);
    do
    {
        ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, &val16);
    } while(val16>>15);


    //force phy into desired mode
    ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, &val16);
    val16 &= ~(1<<12);        //disable auto-negotiate
    val16 &= ~(1<<14);        //disable loopback

    switch(speed)
    {
        case SPEED_10H:
            val16 &= ~(1<<13);    //clear speed LSB
            val16 &= ~(1<<6);     //clear speed MSB
            val16 &= ~(1<<8);     //clear duplex bit
            break;
        case SPEED_100H:
            val16 |= (1<<13);     //set speed LSB
            val16 &= ~(1<<6);     //clear speed MSB
            val16 &= ~(1<<8);     //clear duplex bit
            break;
        case SPEED_10F:
            val16 &= ~(1<<13);     //clear speed LSB
            val16 &= ~(1<<6);     //clear speed MSB
            val16 |= (1<<8);      //set duplex bit
            break;
        case SPEED_100F:
            val16 |= (1<<13);     //set speed LSB
            val16 &= ~(1<<6);     //clear speed MSB
            val16 |= (1<<8);      //set duplex bit
            break;
        case SPEED_1000F:
            val16 &= ~(1<<13);    //clear speed LSB
            val16 |= (1<<6);      //set speed MSB
            val16 |= (1<<8);      //set duplex bit
            break;
        case SPEED_LB:
            //val16 |= (1<<13);     //set speed LSB
            //val16 &= ~(1<<6);     //clear speed MSB
            //val16 |= (1<<8);      //set duplex bit
            val16 &= ~(1<<13);    //clear speed LSB
            val16 |= (1<<6);      //set speed MSB
            val16 |= (1<<8);      //set duplex bit

            val16 |= (1<<14);     //set loopback
            break;
    }
    ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, val16);

    /* Clock Skew */
    ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_MMD_CTRL, phy_addr, ENETPHY_MMD_DEVICE_ADDR_2);
    ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_MMD_DATA, phy_addr, ENETPHY_MMD_CLOCK_SKEW_REG);
    ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_MMD_CTRL, phy_addr, 0x4002);
    ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_MMD_DATA, phy_addr, (0x18 << 5) | 0x18);

    if(speed==SPEED_LB)  //PHY_MICREL_KSZ9031RNX: for 1000M Loopback mode
    {
        ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_1000BT_CONTROL, phy_addr, &debug_data);
        debug_data |= (1<<12);     //Enable master-slave manual configuration
        debug_data &= ~(1<<11);     //select slave configuration(required for loopback mode)
        ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_1000BT_CONTROL, phy_addr, debug_data);
    }
    else
    {
        ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_1000BT_CONTROL, phy_addr, &debug_data);
        debug_data &= ~(1<<12);     //Disable master-slave manual configuration  
        ENETPHY_UserAccessWrite((ENETPHY_Handle) &phyDev, ENETPHY_1000BT_CONTROL, phy_addr, debug_data);
    }

    Delay(100000);

    //make sure link is up
    val = 0;
    retries = 2000;
    while (retries)
    {
        /* First read the BSR of the PHY */
        ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BSR, phy_addr, &val16);

        if(val16 & ENETPHY_LINK_STATUS)
        {
            val = 1;
        }

        retries--;
    }

    GMAC_log("%s    ", val?"Up":"Down                        " );
    if(!val)
    {
        mdioDump();
        return 3;
    }

    //determine if in loopback
    Delay(100000);
    ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, ENETPHY_BCR, phy_addr, &val16);
    if(val16&(1<<14))
    {
        loopback=1;
    }

    //use phy specific registers to detect link status
    // speed_duplex = (speed1, speed0, duplex) where speed 00 = 10mpbs, speed 01 = 100mbps, speed 10 = 1000mbps
    //PHY_MICREL_KSZ9031RNX:
    ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, 0x1F, phy_addr, &val16);

    speed_duplex=(val16>>3)&1 ;         //duplex bit
    speed_duplex|=((val16>>5)&1)<<1;    //speed[0] bit
    speed_duplex|=((val16>>6)&1)<<2;    //speed[1] bit

    switch(speed_duplex)
    {
        case 0:
            GMAC_log("10Mbps Half duplex      ");
            speed_detected=SPEED_10H;
            break;
        case 1:
            GMAC_log("10Mbps Full duplex      ");
            speed_detected=SPEED_10F;
            break;
        case 2:
            GMAC_log("100Mbps Half duplex     ");
            speed_detected=SPEED_100H;
            break;
        case 3:
            if(loopback)
            {
                GMAC_log("Phy Loopback            ");
                speed_detected=SPEED_LB;
            }
            else
            {
                GMAC_log("100Mbps Full duplex     ");
                speed_detected=SPEED_100F;
            }
            break;
        case 5:
            if(loopback)
            {
                GMAC_log("Phy Loopback            ");
                speed_detected=SPEED_LB;
            }
            else
            {
                GMAC_log("1000Mbps Full duplex    ");
                speed_detected=SPEED_1000F;
            }
            break;
        default:
            GMAC_log("Unknown                 ");
            speed_detected=100;
            break;
    }

    // check speed requested vs detected
    if(speed!=speed_detected)
        return 4;

    //if we made it this far successfully, we can enable mac and ale port now
    CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) CpswBase, port, &pPortControlInfo);
    pPortControlInfo.portState = 0x03U;
    CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) CpswBase, port, &pPortControlInfo);

    CSL_CPGMAC_SL_enableGMII((CSL_cpgmacSlHandle) SlBase);

    return 0;
}

//-------------------------------------------------------------------------
// ALE Dump table
//-------------------------------------------------------------------------
void CPSWAleDumpTable(void)
{
  Uint32  entry;
  Uint32  word2, word1, word0;
  Uint32  fIsEmpty=TRUE;

  GMAC_log("CPSW3G ALE Table:  \n");
  GMAC_log("Entry:          Word2:          Word1:          Word0:          \n");
  GMAC_log("----------      ----------      ----------      ----------      \n");

  for(entry=0;entry<1024;entry++)
  {
    CSL_CPSW_getAleTableEntry((CSL_cpswHandle) CpswBase, entry, &word0, &word1, &word2);
    if ( word2 || word1 || word0 )
      if( !(word2==0x7f && word1==0xffffffff && word0==0xffffffff) )
      {
        fIsEmpty=FALSE;
        GMAC_log("%10d      0x%08x      0x%08x      0x%08x\n", entry, word2, word1, word0 );
      }
  }
  if ( fIsEmpty )
    GMAC_log("ALE table is empty.\n");
}

// dump switch stats
void CPSWStatsDump(void)
{
  GMAC_log("CPSW3G Stats:  \n");
  GMAC_log("Stat:                               \n");
  GMAC_log("---------------------     ----------\n");
  GMAC_log("RxGoodFrames              %10u      \n",   HWREG(CpswStatBase+0x00));
  GMAC_log("RxBroadcastFrames         %10u      \n",   HWREG(CpswStatBase+0x04));
  GMAC_log("RxMulticastFrames         %10u      \n",   HWREG(CpswStatBase+0x08));
  GMAC_log("RxPauseFrames             %10u      \n",   HWREG(CpswStatBase+0x0c));
  GMAC_log("RxCRCErrors               %10u      \n",   HWREG(CpswStatBase+0x10));
  GMAC_log("RxAlignCodeErrors         %10u      \n",   HWREG(CpswStatBase+0x14));
  GMAC_log("RxOversizedFrames         %10u      \n",   HWREG(CpswStatBase+0x18));
  GMAC_log("RxJabberFrames            %10u      \n",   HWREG(CpswStatBase+0x1c));
  GMAC_log("RxUndersizedFrames        %10u      \n",   HWREG(CpswStatBase+0x20));
  GMAC_log("RxFragments               %10u      \n",   HWREG(CpswStatBase+0x24));
  GMAC_log("RxOctets                  %10u      \n",   HWREG(CpswStatBase+0x30));
  GMAC_log("TxGoodFrames              %10u      \n",   HWREG(CpswStatBase+0x34));
  GMAC_log("TxBroadcastFrames         %10u      \n",   HWREG(CpswStatBase+0x38));
  GMAC_log("TxMulticastFrames         %10u      \n",   HWREG(CpswStatBase+0x3c));
  GMAC_log("TxPauseFrames             %10u      \n",   HWREG(CpswStatBase+0x40));
  GMAC_log("TxDeferredFrames          %10u      \n",   HWREG(CpswStatBase+0x44));
  GMAC_log("TxCollisionFrames         %10u      \n",   HWREG(CpswStatBase+0x48));
  GMAC_log("TxSingleCollFrames        %10u      \n",   HWREG(CpswStatBase+0x4c));
  GMAC_log("TxMultCollFrames          %10u      \n",   HWREG(CpswStatBase+0x50));
  GMAC_log("TxExcessiveCollisions     %10u      \n",   HWREG(CpswStatBase+0x54));
  GMAC_log("TxLateCollisions          %10u      \n",   HWREG(CpswStatBase+0x58));
  GMAC_log("TxUnderrun                %10u      \n",   HWREG(CpswStatBase+0x5c));
  GMAC_log("TxCarrierSenseErrors      %10u      \n",   HWREG(CpswStatBase+0x60));
  GMAC_log("TxOctets                  %10u      \n",   HWREG(CpswStatBase+0x64));
  GMAC_log("64octetFrames             %10u      \n",   HWREG(CpswStatBase+0x68));
  GMAC_log("65t127octetFrames         %10u      \n",   HWREG(CpswStatBase+0x6c));
  GMAC_log("128t255octetFrames        %10u      \n",   HWREG(CpswStatBase+0x70));
  GMAC_log("256t511octetFrames        %10u      \n",   HWREG(CpswStatBase+0x74));
  GMAC_log("512t1023octetFrames       %10u      \n",   HWREG(CpswStatBase+0x78));
  GMAC_log("1024UPoctetFrames         %10u      \n",   HWREG(CpswStatBase+0x7c));
  GMAC_log("NetOctets                 %10u      \n",   HWREG(CpswStatBase+0x80));
  GMAC_log("SOF Overrun               %10u      \n",   HWREG(CpswStatBase+0x84));
  GMAC_log("MOF Overrun               %10u      \n",   HWREG(CpswStatBase+0x88));
  GMAC_log("DMA Overrun               %10u      \n",   HWREG(CpswStatBase+0x8c));
}

// clear switch stats
void CPSWStatsClear(void)
{
  //GMAC_log("Clearing CPSW_3G stats....");
  HWREG(CpswStatBase+0x00) = 0xffffffff;
  HWREG(CpswStatBase+0x04) = 0xffffffff;
  HWREG(CpswStatBase+0x08) = 0xffffffff;
  HWREG(CpswStatBase+0x0c) = 0xffffffff;
  HWREG(CpswStatBase+0x10) = 0xffffffff;
  HWREG(CpswStatBase+0x14) = 0xffffffff;
  HWREG(CpswStatBase+0x18) = 0xffffffff;
  HWREG(CpswStatBase+0x1c) = 0xffffffff;
  HWREG(CpswStatBase+0x20) = 0xffffffff;
  HWREG(CpswStatBase+0x24) = 0xffffffff;
  HWREG(CpswStatBase+0x30) = 0xffffffff;
  HWREG(CpswStatBase+0x34) = 0xffffffff;
  HWREG(CpswStatBase+0x38) = 0xffffffff;
  HWREG(CpswStatBase+0x3c) = 0xffffffff;
  HWREG(CpswStatBase+0x40) = 0xffffffff;
  HWREG(CpswStatBase+0x44) = 0xffffffff;
  HWREG(CpswStatBase+0x48) = 0xffffffff;
  HWREG(CpswStatBase+0x4c) = 0xffffffff;
  HWREG(CpswStatBase+0x50) = 0xffffffff;
  HWREG(CpswStatBase+0x54) = 0xffffffff;
  HWREG(CpswStatBase+0x58) = 0xffffffff;
  HWREG(CpswStatBase+0x5c) = 0xffffffff;
  HWREG(CpswStatBase+0x60) = 0xffffffff;
  HWREG(CpswStatBase+0x64) = 0xffffffff;
  HWREG(CpswStatBase+0x68) = 0xffffffff;
  HWREG(CpswStatBase+0x6c) = 0xffffffff;
  HWREG(CpswStatBase+0x70) = 0xffffffff;
  HWREG(CpswStatBase+0x74) = 0xffffffff;
  HWREG(CpswStatBase+0x78) = 0xffffffff;
  HWREG(CpswStatBase+0x7c) = 0xffffffff;
  HWREG(CpswStatBase+0x80) = 0xffffffff;
  HWREG(CpswStatBase+0x84) = 0xffffffff;
  HWREG(CpswStatBase+0x88) = 0xffffffff;
  HWREG(CpswStatBase+0x8c) = 0xffffffff;
  //GMAC_log("done\n");
}

// CPSW init
void CpswInit(Uint32 base)
{
  CSL_CPSW_PORTSTAT       portStatsCfg;
  Uint32 pPortTxPriMap = 0x0U;

  portStatsCfg.p0StatEnable   =   1;
  portStatsCfg.p1StatEnable   =   1;
  portStatsCfg.p2StatEnable   =   1;

  //enable stats
  CSL_CPSW_setPortStatsEnableReg ((CSL_cpswHandle) base, &portStatsCfg);

  //configure rx->cpdma channel mapping
  //  port 1, pri 0 ---> cpdma channel 0
  //  port 1, pri 1 ---> cpdma channel 1
  //  port 1, pri 2 ---> cpdma channel 2
  //  port 1, pri 3 ---> cpdma channel 3
  //  port 2, pri 0 ---> cpdma channel 4
  //  port 2, pri 1 ---> cpdma channel 5
  //  port 2, pri 2 ---> cpdma channel 6
  //  port 2, pri 3 ---> cpdma channel 7
  HWREG(CpswPort0Base + CSL_CPSW_3G_P0_CPDMA_RX_CH_MAP) = 0x00000000;
  CSL_CPSW_setPortTxPriMapReg((CSL_cpswHandle) CpswBase, 0, &pPortTxPriMap);
}

// ALE init
void AleInit(Uint32 base)
{
  CSL_CPSW_ALE_PORTCONTROL pPortControlInfo;
  //init
  CSL_CPSW_clearAleTable((CSL_cpswHandle) base);

  //enable learning
  CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 0, &pPortControlInfo);
  pPortControlInfo.noLearnModeEnable = 0x1;
  CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 0, &pPortControlInfo);
  CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 1, &pPortControlInfo);
  pPortControlInfo.noLearnModeEnable = 0x1;
  CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 1, &pPortControlInfo);
  CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 2, &pPortControlInfo);
  pPortControlInfo.noLearnModeEnable = 0x1;
  CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 2, &pPortControlInfo);
  //add ale entries for port 0,1,2
  CSL_CPSW_setAleTableEntry((CSL_cpswHandle) base, 0, 0xadbeef00, 0xd00000de, 0x0);
  CSL_CPSW_setAleTableEntry((CSL_cpswHandle) base, 1, 0xadbeef01, 0xd00000de, 0x4);
  CSL_CPSW_setAleTableEntry((CSL_cpswHandle) base, 2, 0xadbeef02, 0xd00000de, 0x8);

  CSL_CPSW_enableAle((CSL_cpswHandle) base);
  //port into forwarding mode
  CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 0, &pPortControlInfo);
  pPortControlInfo.portState = 0x03U;
  CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 0, &pPortControlInfo);
}

void AlePortDisable(Uint32 base)
{
  CSL_CPSW_ALE_PORTCONTROL pPortControlInfo;
  CSL_CPSW_disableAle((CSL_cpswHandle) base);
  CSL_CPSW_clearAleTable((CSL_cpswHandle) base);
  //port into forwarding mode
  CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 0, &pPortControlInfo);
  pPortControlInfo.portState = 0x00U;
  CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 0, &pPortControlInfo);
  CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 1, &pPortControlInfo);
  pPortControlInfo.portState = 0x00U;
  CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 1, &pPortControlInfo);
  CSL_CPSW_getAlePortControlReg((CSL_cpswHandle) base, 2, &pPortControlInfo);
  pPortControlInfo.portState = 0x00U;
  CSL_CPSW_setAlePortControlReg((CSL_cpswHandle) base, 2, &pPortControlInfo);
}

// CPDMA init
void CpswCpdmaInit(Uint32 base)
{
  Uint32 chan;

  // clear interrupts to start clean
  CSL_CPSW_setCpdmaTxEndOfIntVector((CSL_cpdmaHandle) base);
  CSL_CPSW_setCpdmaRxEndOfIntVector((CSL_cpdmaHandle) base);

  CSL_CPSW_setCpdmaRxBufOffset((CSL_cpdmaHandle) base, 0x0);

  // enable rx and tx
  CSL_CPSW_enableCpdmaTx((CSL_cpdmaHandle) base);
  CSL_CPSW_enableCpdmaRx((CSL_cpdmaHandle) base);

  // enable rx and tx interrupts for all channels
  for(chan=0;chan<8;chan++)
  {
	CSL_CPSW_enableCpdmaTxInt((CSL_cpdmaHandle) base, chan);
	CSL_CPSW_enableCpdmaRxInt((CSL_cpdmaHandle) base, chan);
  }
}

// Cpsw wrapper init
void CpswWrInit(Uint32 base)
{
  // set prescaler and interrupts per ms
  HWREG(base + CSL_WR_INT_CONTROL) = 500;
  CPSWWrIntRxPerMsSet(base, 0, 2);
  CPSWWrIntTxPerMsSet(base, 0, 2);
  //enable interrupt pacing
  if(fPacing)
    CPSWWrIntPacingEnable(base, CPSW_INT_PACING_C0_RX_PULSE | CPSW_INT_PACING_C0_TX_PULSE );
}

// Enable cpsw level interrupts
void CpswIntEnable(Uint32 dir)
{
  Uint32 chan;

  if(dir==RX)
    for(chan=0;chan<8;chan++)
	  CSL_CPSW_enableWrRxInt((CSL_wrHandle) CpswWrBase, 0, chan);
  else
    for(chan=0;chan<8;chan++)
	  CSL_CPSW_enableWrTxInt((CSL_wrHandle) CpswWrBase, 0, chan);
}

// Disable cpsw level interrupts
int CpswIntDisable(Uint32 dir)
{
  Uint32 chan, ret_val=0;

  if(dir==RX)
  {
    if( HWREG(CpswWrBase + CSL_WR_RX_EN(0)) )
      ret_val=1;
    for(chan=0;chan<8;chan++)
	  CSL_CPSW_disableWrRxInt((CSL_wrHandle) CpswWrBase, 0, chan);
  }
  else
  {
    if( HWREG(CpswWrBase + CSL_WR_TX_EN(0)) )
      ret_val=1;
    for(chan=0;chan<8;chan++)
	  CSL_CPSW_disableWrRxInt((CSL_wrHandle) CpswWrBase, 0, chan);
  }
  return ret_val;
}

// Descriptor init
void DescInit(void)
{
  Uint32 num_desc, i;
  Uint32 chan;
  Desc *rd;
  Desc *td;
  Uint32 tmp;

  //RX descriptor init
  //GMAC_log("Initializing RX descriptors\n");
  num_desc=RX_NUM_DESC;
  rd=(Desc *)CpswCppiRamBase;
  //for(chan=0;chan<8;chan++)
  for(chan=0;chan<1;chan++)
  {
    RxHead[chan]=rd;
    for(i=0;i<num_desc;i++)
    {
      if(i!=(num_desc-1))
        rd->NextDesc    = (Uint32)rd+sizeof(*rd);
      else
        rd->NextDesc    = 0;
      rd->BufPtr        = BUFFER_BASE + ((chan*num_desc)+i)*0x800;
      rd->Off_BufLen    = BUFFER_SIZE;
      rd->Flags_PktLen  = OWNERSHIP_BIT;
      rd->OrigQueue     = chan;

      RxTail[chan]=rd;
      tmp=(Uint32)rd+sizeof(*rd);
      rd=(Desc*)tmp;
    }
  //GMAC_log("RxHead[%d]:  0x%08x    RxTail[%d]:  0x%08x\n", chan, RxHead[chan], chan, RxTail[chan]);
  RxQueueCnt[chan]=RX_NUM_DESC;
  CSL_CPSW_setCpdmaRxHdrDescPtr((CSL_cpdmaHandle) CpswCpdmaBase, (Uint32)RxHead[chan], chan);
  }

  //TX descriptor init
  num_desc=TX_NUM_DESC;
  //GMAC_log("Initializing free TX descriptors\n");
  td=(Desc*)rd;
  TxFreeHead=td;
  for(i=0;i<num_desc;i++)
  {
    if(i!=(num_desc-1))
      td->NextDesc    = (Uint32)td+sizeof(*td);
    else
      td->NextDesc    = 0;
    td->BufPtr        = BUFFER_BASE + ((chan*num_desc)+i)*0x800;
    td->Off_BufLen    = BUFFER_SIZE;
    td->Flags_PktLen  = SOF_AND_EOF_BIT;
    td->OrigQueue     = 8;

    TxFreeTail=td;
    tmp=(Uint32)td+sizeof(*td);
    td=(Desc*)tmp;
  }
  TxFreeCnt=TX_NUM_DESC;
  //GMAC_log("TxFreeHead:  0x%08x    TxFreeTail:  0x%08x\n", TxFreeHead, TxFreeTail);
}

// build and transmit packet
int TransmitPacket(Uint32 pkt_len, Uint32 port)
{
  Uint32 data_len;
  Desc *pDesc;
  ETH_PKT *pPkt;
  Uint8 *data;
  int i, ret_val=0;

  fTxP=TRUE;

  //get descriptor
  pDesc=TxFreeHead;
  if(pDesc!=NULL)
  {
    TxFreeCnt--;
    TxFreeHead=(Desc *)pDesc->NextDesc;
    if(TxFreeHead==NULL)
      TxFreeTail=NULL;

    fTxP=FALSE;

    pPkt = (ETH_PKT *)(pDesc->BufPtr);
    pkt_len = pkt_len-4;
    data_len = pkt_len-sizeof(ETH_HEADER);

    //Update descriptor for transmit
    pDesc->NextDesc = 0;
    pDesc->Flags_PktLen = SOF_AND_EOF_BIT | OWNERSHIP_BIT | pkt_len;

    //Build actual packet data
    if(port==1)
    {
      pPkt->Eth.UpperDstMac = 0xde00;
      pPkt->Eth.LowerDstMac = 0x01efbead;
    }
    else
    {
      pPkt->Eth.UpperDstMac = 0xde00;
      pPkt->Eth.LowerDstMac = 0x02efbead;
    }
    pPkt->Eth.UpperSrcMac = 0xde00;
    pPkt->Eth.LowerSrcMac = 0x00efbead;
    pPkt->Eth.Type = 0x0008;

    data=(Uint8 *)&pPkt->Data;
    for(i=0;i<data_len;i++)
    {
      *data=i&0xff;
      data++;
    }

    TxPacket(pDesc);
  }
  else
  {
    fTxP=FALSE;
    ret_val = 1;
  }
  return ret_val;
}

// Service Rx completion queue
void ServiceRx(void *arg) 
{
  Uint32 chan=0, serviced=0, pend_int;
  Desc *curr,*next,*last,*processed = NULL;

  //disable switch and clear system interrupt
  CpswIntDisable(RX);
  CSL_CPSW_setCpdmaRxEndOfIntVector((CSL_cpdmaHandle) CpswCpdmaBase);
  pend_int=CSL_CPSW_getCpdmaRxIntStatMasked((CSL_cpdmaHandle) CpswCpdmaBase);
  while(pend_int && serviced<=NUM_RX_SERVICE)
  {
    for(chan=0;chan<8;chan++)
    {
      //update pending interrupts
      if((pend_int>>chan)&1)
      {
        CSL_a15InvDataCache(RxHead[chan], sizeof(Desc));
        CSL_a15InvDataCache(RxTail[chan], sizeof(Desc));
        curr=RxHead[chan];
        last=RxTail[chan];
        if((curr == NULL) || (last == NULL))
        {
            GMAC_log("Invalid Descriptor\n");
            break;
        }

        CSL_a15InvDataCache(curr->BufPtr, BUFFER_SIZE);
        if(curr!=NULL)
        {
          while( (curr->Flags_PktLen & OWNERSHIP_BIT)==0 )
          {
            if( (curr->Flags_PktLen & SOF_AND_EOF_BIT)==0 )
            {
              GMAC_log("ERROR, SOF and EOF not set\n");
              break;
            }
            processed=curr;
            RxPackets[chan]++;
            serviced++;

            //reset queue head
            next = (Desc*)curr->NextDesc;
            RxHead[chan] = next;

            //detect misqueue
            if( (curr->Flags_PktLen & EOQ_BIT) )
              if(next!=NULL)
              {
                CSL_CPSW_setCpdmaRxHdrDescPtr((CSL_cpdmaHandle) CpswCpdmaBase, (Uint32)RxHead[chan], chan);
                RxMisqueue[chan]++;
              }

            //reset queue tail
            last->NextDesc = (Uint32)curr;
            RxTail[chan] = curr;

            //reset descriptor for recycling
            curr->NextDesc      = 0;
            curr->Off_BufLen    = BUFFER_SIZE;
            curr->Flags_PktLen  = OWNERSHIP_BIT;

            // update curr and last to repeat loop
            if(next!=NULL)
            {
              curr=RxHead[chan];
              last=RxTail[chan];
            }
            else
            {
              RxTail[chan]=NULL;
              break;
            }
          }

          if(processed != NULL)
          {
            // write last processed descriptor
            CSL_CPSW_setCpdmaRxCp((CSL_cpdmaHandle) CpswCpdmaBase, chan, (Uint32)processed);
          }
        }
      }
	  pend_int=CSL_CPSW_getCpdmaRxIntStatMasked((CSL_cpdmaHandle) CpswCpdmaBase);
    }
  }
  // re-enable switch interrupt
  CpswIntEnable(RX);
}

// Service TX completion queue
void ServiceTx(void *arg) 
{
  Uint32 pend_int, chan, orig_queue, serviced=0;
  Desc *curr,*next,*last,*processed;
  Uint32 fMisQ=FALSE;
  Uint32 last_process = 0;

  pend_int=CSL_CPSW_getCpdmaTxIntStatMasked((CSL_cpdmaHandle) CpswCpdmaBase);

  //disable switch and clear system interrupt
  CpswIntDisable(TX);
  CSL_CPSW_setCpdmaTxEndOfIntVector((CSL_cpdmaHandle) CpswCpdmaBase);

  //begin processing
  while(pend_int && serviced<=NUM_TX_SERVICE)
  {
    for(chan=0;chan<8;chan++)
    {
      fMisQ=FALSE;
      if((pend_int>>chan)&1)
      {
        processed=TxHead[chan];
        serviced++;
        if(processed!=NULL)
        {
          //Normal processing
          while( (processed->Flags_PktLen & OWNERSHIP_BIT)==0 && !fMisQ)
          {
            TxPackets[chan]++;
            //serviced++;
            TxQueueCnt[chan]--;

            //reset queue head
            next=(Desc*)processed->NextDesc;
            TxHead[chan] = next;

            if( (processed->Flags_PktLen & EOQ_BIT) )
              if(next!=NULL)
              {
                CSL_CPSW_setCpdmaTxHdrDescPtr((CSL_cpdmaHandle) CpswCpdmaBase, (Uint32)TxHead[chan], chan);
                fMisQ=TRUE;
                TxMisqueue[chan]++;
              }

            orig_queue = processed->OrigQueue;
            //original packet came from RX
            if(orig_queue<8)
            {
              //update descriptor for recycling
              processed->NextDesc      = 0;
              processed->Off_BufLen    = BUFFER_SIZE;
              processed->Flags_PktLen  = OWNERSHIP_BIT;

              curr=RxHead[orig_queue];
              last=RxTail[orig_queue];
              if(curr!=NULL && last!=NULL)
                last->NextDesc = (Uint32)processed;
              else
              {
                RxHead[orig_queue]=processed;
                CSL_CPSW_setCpdmaRxHdrDescPtr((CSL_cpdmaHandle) CpswCpdmaBase, (Uint32)RxHead[orig_queue], orig_queue);
              }
              //update queue tail
              RxTail[orig_queue] = processed;
              RxQueueCnt[orig_queue]++;
            }
            //original packet came from TX
            else
            {
              //if((Uint32)processed<0x4a103400)
              //  GMAC_log("service tx: orig_queue error, processed: 0x%08x, orig_queue: %d\n", processed, orig_queue);
              processed->NextDesc      = 0;
              processed->Off_BufLen    = BUFFER_SIZE;
              processed->Flags_PktLen  = SOF_AND_EOF_BIT;
              //processed->OrigQueue     = 8;

              curr=TxFreeHead;
              last=TxFreeTail;
              if(curr!=NULL && last!=NULL)
                last->NextDesc = (Uint32)processed;
              else
                TxFreeHead=processed;
              TxFreeTail=processed;
              TxFreeCnt++;
            }
            last_process=(Uint32)processed;

            //advance to next descriptor or exit if there is none
            if(next!=NULL)
              processed=next;
            else
            {
              TxTail[chan]=NULL;
              break;
            }
          }
          //write last processed descriptor
          CSL_CPSW_setCpdmaTxCp((CSL_cpdmaHandle) CpswCpdmaBase, chan, last_process);
        }
      }
      //update pending interrupts
      pend_int=CSL_CPSW_getCpdmaTxIntStatMasked((CSL_cpdmaHandle) CpswCpdmaBase);
    }
  }
  //re-enable switch interrupt
  CpswIntEnable(TX);
}

//TxPacket
//  Packet is transmitted based on orig queue
//  Orig queue is channel packet was received on or tx free queue descriptor was popped off
void TxPacket(Desc *TxDesc)
{
  Uint32 chan, flags;
  Desc *curr, *last;

  fTxP2=TRUE;

  chan = TxDesc->OrigQueue;
  if(chan>=8)
    chan-=8;

  curr=TxHead[chan];
  last=TxTail[chan];

  __sync_synchronize();
  CSL_a15WbDataCache(TxDesc, sizeof(Desc));
  CSL_a15WbDataCache(TxDesc->BufPtr, BUFFER_SIZE);

  if(curr==NULL)
  {
    TxHead[chan]=TxDesc;
    TxTail[chan]=TxDesc;
    TxQueueCnt[chan]++;
    CSL_CPSW_setCpdmaTxHdrDescPtr((CSL_cpdmaHandle) CpswCpdmaBase, (Uint32)TxDesc, chan);
  }
  else
  {
    TxQueueCnt[chan]++;
    last->NextDesc = (Uint32)TxDesc;
    TxTail[chan]=TxDesc;

    flags=last->Flags_PktLen;
    if( (flags & EOQ_BIT) )
    {
      CSL_CPSW_setCpdmaTxHdrDescPtr((CSL_cpdmaHandle) CpswCpdmaBase, (Uint32)TxDesc, chan);
      TxMisqueue[chan]++;
      flags&=~EOQ_BIT;
      last->Flags_PktLen=flags;
    }
  }

  fTxP2=FALSE;
}

// Dump host port stats
void HostStats(void)
{
  Uint32 chan;

  GMAC_log("Channel      RxPackets       TxPackets       RxMisqueue      TxMisqueue      \n");
  GMAC_log("-------      ----------      ----------      ----------      ----------      \n");

  for(chan=0;chan<8;chan++)
    GMAC_log("%7d      %10d      %10d      %10d      %10d      \n", chan, RxPackets[chan], TxPackets[chan], RxMisqueue[chan], TxMisqueue[chan]);

}

// dump some internal stats
void DebugStats(void)
{
  Uint32 chan;

  GMAC_log("Channel      RxHead          RxTail          RxQueueCnt      RxHDP           TxHead          TxTail          TxQueueCnt      TxHDP           \n");
  GMAC_log("-------      ----------      ----------      ----------      ----------      ----------      ----------      ----------      ----------      \n");

  for(chan=0;chan<8;chan++)
    GMAC_log("%7d      0x%08x      0x%08x      0x%08x      0x%08x      0x%08x      0x%08x      0x%08x      0x%08x      \n",
                chan,
                RxHead[chan],
                RxTail[chan],
                RxQueueCnt[chan],
                HWREG(CpswCpdmaBase + CSL_CPDMA_RX_HDP(chan)),
                TxHead[chan],
                TxTail[chan],
                TxQueueCnt[chan],
                HWREG(CpswCpdmaBase + CSL_CPDMA_TX_HDP(chan)) );
  GMAC_log(" TxFree      N/A             N/A             N/A             N/A             0x%08x      0x%08x      0x%08x      N/A             \n", TxFreeHead, TxFreeTail, TxFreeCnt );
}

// dump queue chain
void DumpQueue(Uint32 channel)
{
  Uint32 cnt=0;
  Desc *pd;

  GMAC_log("dump queue %d\n", channel);
  GMAC_log("\nChannel      Descriptor      NextDesc        BufPtr          Off_BufLen      Flags_Pkt       Orig_Queue      \n");
  GMAC_log(  "-------      ----------      ----------      ----------      ----------      ----------      ----------      \n");
  if(channel<8)
    pd=RxHead[channel];
  else
    pd=TxFreeHead;
  while(pd!=NULL)
  {
    GMAC_log("%7d      0x%08x      0x%08x      0x%08x      0x%08x      0x%08x      0x%08x      \n", channel, pd, pd->NextDesc, pd->BufPtr, pd->Off_BufLen, pd->Flags_PktLen, pd->OrigQueue );
    pd=(Desc *)pd->NextDesc;
    cnt++;
  }
  GMAC_log("Channel %d queue cnt: %d\n", channel, cnt);
}

//*****************************************************************************
//  mdioDump
//****************************************************************************/
void mdioDump(void)
{
  unsigned int i, phy_addr1, phy_addr2;
  Uint32 val16, val16_b;
  ENETPHY_DEVICE phyDev;

  phyDev.miibase = MdioBase;

  phy_addr1=Phy1Addr;
  phy_addr2=Phy2Addr;

  GMAC_log("MDIO register dump\n");
  GMAC_log("Reg:     Port 1:     Port 2:     \n");
  for(i=0; i<32; i++)
  {
    ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, i+0, phy_addr1, &val16);
    ENETPHY_UserAccessRead((ENETPHY_Handle) &phyDev, i+0, phy_addr2, &val16_b);
    GMAC_log("0x%02x     0x%04x      0x%04x\n",  i+0, val16, val16_b);
  }
}

Uint32 CheckStats(Uint32 speed)
{
    int timeout=0;

    if(speed==SPEED_10H || speed==SPEED_100H)
    {
        while(1)
        {
            //if tx_exc_coll =TEST_NUM_PACKETS and rx_frag=512 and tx_coll=512, we're done
            if( HWREG(CpswStatBase+0x54)==TEST_NUM_PACKETS )
            {
                if( HWREG(CpswStatBase+0x48)==(TEST_NUM_PACKETS*16) )
                    return 0;
            }

            //if any rx errors or good we're done with error
            if( HWREG(CpswStatBase+0x10) ||
                HWREG(CpswStatBase+0x14) ||
                HWREG(CpswStatBase+0x18) ||
                HWREG(CpswStatBase+0x1c) ||
                HWREG(CpswStatBase+0x20) ||
                HWREG(CpswStatBase+0x00)
                )
                return 6;

            //if any tx good or errors we're done with error
            if( HWREG(CpswStatBase+0x34) ||
                HWREG(CpswStatBase+0x5c) ||
                HWREG(CpswStatBase+0x60)
                )
                return 5;

            Delay(1000000);
            timeout++;
            if(timeout==50)
                return 8;
        }
    }
    else
    {
        while(1)
        {
        //if tx good and rx good, we're done
        if( HWREG(CpswStatBase+0x34)==TEST_NUM_PACKETS )
        {
            if( HWREG(CpswStatBase+0x00)==TEST_NUM_PACKETS )
                return 0;
        }

        //if any rx errors we're done with error
        if( HWREG(CpswStatBase+0x10) ||
            HWREG(CpswStatBase+0x14) ||
            HWREG(CpswStatBase+0x18) ||
            HWREG(CpswStatBase+0x1c) ||
            HWREG(CpswStatBase+0x20) ||
            HWREG(CpswStatBase+0x24)
            )
            return 6;

        //if any tx collisions or errors we're done with error
        if( HWREG(CpswStatBase+0x44) ||
            HWREG(CpswStatBase+0x48) ||
            HWREG(CpswStatBase+0x4c) ||
            HWREG(CpswStatBase+0x50) ||
            HWREG(CpswStatBase+0x54) ||
            HWREG(CpswStatBase+0x58) ||
            HWREG(CpswStatBase+0x5c) ||
            HWREG(CpswStatBase+0x60)
            )
            return 5;

            Delay(1000000);
            timeout++;
            if(timeout==50)
                return 8;
        }
    }
}

//*****************************************************************************
//  Main
//****************************************************************************/
int main(void)
{
    Uint32 size, port=1, i, speed;
    Uint32 ret_val=0, error_code=0;
    Uint32 num_ports=2, phy_type;
    Uint32 fDone=FALSE;
    Uint32 timeout=0;
    Board_initCfg boardCfg;

    /* Copy the vector table to desired location.  */
    copyVectorTable();

    /* Configure system */
    startup();

    /* Call board init functions */
    boardCfg = BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    //Phy_clk_gen_config(0D
    fRGMII=TRUE;
    fGig=TRUE;
    fRMII=TRUE;

    Phy1Addr=GMAC_PORT1_ETHERNET_PHY_ADRESS;
    Phy2Addr=GMAC_PORT2_ETHERNET_PHY_ADRESS;

    UART_printf("\n*********************************************\n"); 
    UART_printf  ("*                 GMAC Test                 *\n");
    UART_printf  ("*********************************************\n");

    //basic clock, pin mux setup

    /* Select RGMII 2 ports GMIIx_SEL = 2 for RGMII */
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_1,
      CONTROL_CORE_CONTROL_IO_1_GMII1_SEL, 2U);
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_1,
      CONTROL_CORE_CONTROL_IO_1_GMII2_SEL, 2U);

    /*GMAC RESET ISOLATION Enable*/
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_2,
      CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE, 0U);
    CSL_FINS (((CSL_control_coreRegs *) CSL_MPU_CTRL_MODULE_CORE_CORE_REGISTERS_REGS)->CONTROL_IO_2,
      CONTROL_CORE_CONTROL_IO_2_GMAC_RESET_ISOLATION_ENABLE, 1U);

    //using the arm cycle counter for a sort of pseudo-random number generator
    CycleCountEnable();

    //test
    GMAC_log("Test                    Port    Link    Link-Speed              Status    Error\n");
    GMAC_log("--------------------    ----    ----    --------------------    ------    ---------------------------\n");
    for(port=1;port<=num_ports;port++)
    {
        phy_type=PHY_MICREL_KSZ9031RNX;

        speed=SPEED_LB;
        //speed=SPEED_1000F;
        fDone=FALSE;
        do
        {

            CSL_CPSW_reset((CSL_cpswHandle) CpswBase);
            while (FALSE == CSL_CPSW_isResetDone((CSL_cpswHandle) CpswBase));

            CSL_CPSW_resetWr((CSL_wrHandle) CpswWrBase);
            while (FALSE == CSL_CPSW_isWrResetDone((CSL_wrHandle) CpswWrBase));

            CSL_CPGMAC_SL_resetMac((CSL_cpgmacSlHandle) CpswSl1Base);
            while (FALSE == CSL_CPGMAC_SL_isMACResetDone((CSL_cpgmacSlHandle) CpswSl1Base));

            if(num_ports>1)
            {
                CSL_CPGMAC_SL_resetMac((CSL_cpgmacSlHandle) CpswSl2Base);
                while (FALSE == CSL_CPGMAC_SL_isMACResetDone((CSL_cpgmacSlHandle) CpswSl2Base));
            }

            CSL_CPSW_resetCpdma((CSL_cpdmaHandle) CpswCpdmaBase);
            while (FALSE == CSL_CPSW_isCpdmaResetDone((CSL_cpdmaHandle) CpswCpdmaBase));


            //enable mdio
            CSL_MDIO_setClkDivVal((CSL_mdioHandle) MdioBase, (MDIO_FREQ_INPUT/MDIO_FREQ_OUTPUT - 1));
            CSL_MDIO_enableFaultDetect((CSL_mdioHandle) MdioBase);
            CSL_MDIO_disablePreamble((CSL_mdioHandle) MdioBase);
            CSL_MDIO_enableStateMachine((CSL_mdioHandle) MdioBase);

            Delay(100000);

            AlePortDisable(CpswBase);

            //main switch init
            CpswInit(CpswBase);
            AleInit(CpswBase);
            CpswCpdmaInit(CpswCpdmaBase);
            CpswWrInit(CpswWrBase);

            DescInit();
            CpswInterruptInit();

                switch(speed)
                {
                    case SPEED_10H:
                        GMAC_log("10Mbps Half-Duplex      %4d    ", port);
                        break;
                    case SPEED_100H:
                        GMAC_log("100Mbps Half-Duplex     %4d    ", port);
                        break;
                    case SPEED_10F:
                        GMAC_log("10Mbps Full-Duplex      %4d    ", port);
                        break;
                    case SPEED_100F:
                        GMAC_log("100Mbps Full-Duplex     %4d    ", port);
                        break;
                    case SPEED_1000F:
                        GMAC_log("1000Mbps Full-Duplex    %4d    ", port);
                        break;
                    case SPEED_LB:
                        GMAC_log("Phy Loopback            %4d    ", port);
                        break;
                }

                error_code=LinkSetup(port, speed);
                if(!error_code)
                {
                    //send packets
                    //  if we're sending more than 10, make sure we hit some min, max, and random; else all random
                    if(TEST_NUM_PACKETS>10)
                    {
                        for(i=0;i<5;i++)
                        {
                            TransmitPacket(64, port);
                            Delay(100000);
                        }
                        for(i=0;i<5;i++)
                        {
                            TransmitPacket(1518, port);
                            Delay(100000);
                        }

                        for(i=0;i<(TEST_NUM_PACKETS-10);i++)
                        {
                            size=((CycleCounterRegRead()>>1)%1455)+64;
                            TransmitPacket(size, port);
                            Delay(100000);
                        }
                    }
                    else
                    {
                        for(i=0;i<(TEST_NUM_PACKETS);i++)
                        {
                            size=((CycleCounterRegRead()>>1)%1455)+64;
                            TransmitPacket(size, port);
                            Delay(100000);
                        }
                    }

                    timeout=0;
                    while((TxPackets[0]!=TEST_NUM_PACKETS) &&(timeout!=10)) // && !IsTimeout());//FIXME
                    {
                        Delay(10000000);
                    	timeout++;
                    }

                    if(timeout==10)
                    {
                        error_code=8;
                        timeout=0;
                    }
                    else
                        //check for errors
                        error_code=CheckStats(speed);
                }

                //print results from test
                if(!error_code)
                {
                    GMAC_log("PASS\n");
                }
                else
                {
                    ret_val=1;
                    GMAC_log("FAIL      ");
                    switch(error_code)
                    {
                        case 1:
                            GMAC_log("Invalid port number\n");
                            break;
                        case 2:
                            GMAC_log("Phy not alive\n");
                            break;
                        case 3:
                            GMAC_log("Link down\n");
                            break;
                        case 4:
                            GMAC_log("Detected speed mismatch\n");
                            break;
                        case 5:
                            GMAC_log("Transmit errors (see stats)\n");
                            HostStats();
                            DebugStats();
                            CPSWStatsDump();
                            CPSWAleDumpTable();
                            break;
                        case 6:
                            GMAC_log("Receive errors (see stats)\n");
                            HostStats();
                            DebugStats();
                            CPSWStatsDump();
                            CPSWAleDumpTable();
                            break;
                        case 7:
                            GMAC_log("User abort\n");
                            HostStats();
                            DebugStats();
                            CPSWStatsDump();
                            CPSWAleDumpTable();
                            break;
                        case 8:
                            GMAC_log("Test timeout\n");
                            HostStats();
                            DebugStats();
                            CPSWStatsDump();
                            CPSWAleDumpTable();
                            break;
                    }
                }

                //reset stats and transmitted stats for next run
                error_code=0;
                CPSWStatsClear();
                TxPackets[0]=0;

                //change speed
                if(speed==SPEED_LB)
                {
                    speed=SPEED_10H;
                    if(phy_type==PHY_MICREL_KSZ9031RNX) //10H is failing now
                        speed=SPEED_10F;
                }
                else if(speed==SPEED_10H)
                {
                    speed=SPEED_10F;
                }
                else if(speed==SPEED_10F)
                {
                    speed=SPEED_100H;
                }
                else if(speed==SPEED_100H)
                    speed=SPEED_100F;
                else if(speed==SPEED_100F)
                {
                    if(fGig && (phy_type!=PHY_MICREL_KSZ9031RNX))
                        speed=SPEED_1000F;
                else
                    fDone=TRUE;
                }
                else if(speed==SPEED_1000F)
                    fDone=TRUE;
            AlePortDisable(CpswBase);
        } while(!fDone);
    }

    /* disable interrupts */
    CSL_armGicDisableIntr(&gCpuIntrf, (GMAC_SW_IRQ_RX_PULSE_INT_NUM + 32));
    CSL_armGicDisableIntr(&gCpuIntrf, (GMAC_SW_IRQ_TX_PULSE_INT_NUM + 32));

    /* Disconnect the XBar */
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_92, 0U);
    CSL_xbarMpuIrqConfigure(CSL_XBAR_INST_MPU_IRQ_93, 0U);

    GMAC_log("Exiting\n");
    return ret_val;
}

