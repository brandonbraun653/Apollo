/**
 * @file cpsw_mgmt.c
 *
 * @brief
 *  This file holds all the Ethernet subsystem (CPSW + MDIO + SGMII) components
 *  initialization and setup code.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2009-2014, Texas Instruments, Inc.
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
/* C Standard library Include */
#include <string.h>

/* Chip Level definitions include */
#include <ti/csl/csl_chip.h>

/* CSL EMAC include */
#include <ti/csl/csl_cpsw.h>
#include <ti/csl/csl_cpsgmii.h>
#include <ti/csl/csl_cpsgmiiAux.h>
#include <ti/csl/csl_mdio.h>
#include <ti/csl/csl_mdioAux.h>

/* BootCfg module include */
#include <ti/csl/csl_bootcfg.h>
#include <ti/csl/csl_bootcfgAux.h>

#include <ti/drv/emac/cpsw/example/src/cpsw_singlecore.h>
#include <ti/csl/csl_serdes_ethernet.h>

typedef uint32_t csl_serdes_refclk_t;
#define SERDES_REF_CLK_156250_KHZ       156250
#if defined(SOC_K2K) || defined(SOC_K2H)
#define PA_EMAC_EXAMPLE_REF_CLK_KHZ     SERDES_REF_CLK_156250_KHZ
#endif

#ifdef DEVICE_K2G

/* Galileo RGMII setting related definitions and functions */
#define DEVICE_REG32_W(addr, val)   *((volatile uint32_t *)(addr)) = (val)


/*  Ethernet configuration register
 *  
 *  /----------------------------------------------\
 *  | 31    5 |     4        | 3    2 | 1        0 |
 *  |   rsvd  |  rgmii delay |  rsvd  | interface  |
 *  \----------------------------------------------/
 */

#define DEVICE_BOOTCFG_REG_ADDR_ETH_CFG         0x2620e20

#define DEVICE_BOOTCFG_ETH_CFG_FIELD_IF_MSB         1
#define DEVICE_BOOTCFG_ETH_CFG_FIELD_IF_LSB         0
#define DEVICE_BOOTCFG_ETH_CFG_IF_SEL_GMII          0
#define DEVICE_BOOTCFG_ETH_CFG_IF_SEL_RMII          1
#define DEVICE_BOOTCFG_ETH_CFG_IF_SEL_RGMII         2

#define DEVICE_BOOTCFG_ETH_CFG_FIELD_DEL_MSB        4
#define DEVICE_BOOTCFG_ETH_CFG_FIELD_DEL_LSB        4
#define DEVICE_BOOTCFG_ETH_CFG_INT_DELAY_ENABLE     0
#define DEVICE_BOOTCFG_ETH_CFG_INT_DELAY_DISABLE    1
#define DEVICE_BOOTCFG_ETH_CFG_DEFAULT_INT_DELAY    DEVICE_BOOTCFG_ETH_CFG_INT_DELAY_ENABLE


/* BFG PAD configuration */
/*  Pad Config addresses */
#define DEVICE_PAD_CONFIG_BASE          0x2621000
#define DEVICE_PAD_REG_PAD_CONFIG(x)    (DEVICE_PAD_CONFIG_BASE + ((x) * 4))

/* RGMII */
#define DEVICE_PAD_RGMIIRXC                 72
#define DEVICE_PAD_RGMIIRXD(x)              (77 + 3 - (x))
#define DEVICE_PAD_RGMIIRXCTL               81
#define DEVICE_PAD_RGMIITXC                 85
#define DEVICE_PAD_RGMIITXD(x)              (91 + 3 - (x))
#define DEVICE_PAD_RGMIITXCTL               95

#define DEVICE_PAD_MDIODATA               98
#define DEVICE_PAD_MDIOCLK                99

/******************************************************************************
 * Galileo Pin mux definitions
 ******************************************************************************/
#define DEVICE_PIN_MUX_BUFFER_CLASS_00      0       /* type 50 B */
#define DEVICE_PIN_MUX_BUFFER_CLASS_01      1       /* type 40 C */
#define DEVICE_PIN_MUX_BUFFER_CLASS_10      2       /* type 40 D */
#define DEVICE_PIN_MUX_BUFFER_CLASS_11      3       /* type 40 E */

#define DEVICE_PIN_MUX_RX_DISABLED          0
#define DEVICE_PIN_MUX_RX_ENABLED           1

#define DEVICE_PIN_MUX_PULL_DOWN            0
#define DEVICE_PIN_MUX_PULL_UP              1

#define DEVICE_PIN_MUX_PULL_ENABLE          0
#define DEVICE_PIN_MUX_PULL_DISABLE         1

#define DEVICE_PIN_MUX_MODE_PRIMARY         0
#define DEVICE_PIN_MUX_MODE_SECONDARY       1
#define DEVICE_PIN_MUX_MODE_TERTIARY        2
#define DEVICE_PIN_MUX_MODE_QUATERNARY      3
#define DEVICE_PIN_MUX_MODE_QUINARY         4
#define DEVICE_PIN_MUX_MODE_SENARY          5


#define DEVICE_PIN_MUX_VALUE(class, rx, pull, pullEnable, mode)             \
                              ((class) << 19)                             | \
                              ((rx) << 18)                                | \
                              ((pull) << 17)                              | \
                              ((pullEnable) << 16)                        | \
                              (mode)      
            
            
typedef struct devicePinMux_s  {

    uint32_t    padConfigAddress;
    uint32_t    padValue;
    
} devicePinMux_t;    

/* RGMII */
const devicePinMux_t pinMuxRgmii[] =  {

    {   /* Rx clock */
        DEVICE_PAD_RGMIIRXC,
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_ENABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Rx data 0 */
        DEVICE_PAD_RGMIIRXD(0),
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_ENABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Rx data 1 */
        DEVICE_PAD_RGMIIRXD(1),
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_ENABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Rx data 2 */
        DEVICE_PAD_RGMIIRXD(2),
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_ENABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Rx data 3 */
        DEVICE_PAD_RGMIIRXD(3),
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_ENABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Receive control */
        DEVICE_PAD_RGMIIRXCTL,
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_ENABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Tx clock output */
        DEVICE_PAD_RGMIITXC,
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_DISABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Tx data 0 */
        DEVICE_PAD_RGMIITXD(0),
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_DISABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Tx data 1 */
        DEVICE_PAD_RGMIITXD(1),
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_DISABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Tx data 2 */
        DEVICE_PAD_RGMIITXD(2),
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_DISABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Tx data 3 */
        DEVICE_PAD_RGMIITXD(3),
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_DISABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    },

    {   /* Tx control */
        DEVICE_PAD_RGMIITXCTL,
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_DISABLED, DEVICE_PIN_MUX_PULL_DOWN, 
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_SECONDARY)
    }

};


/* MDIO */
const devicePinMux_t pinMuxMdio[] =  {

    {   /* MDIO Data */
        DEVICE_PAD_MDIODATA,
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_DISABLED, DEVICE_PIN_MUX_PULL_DOWN,
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_PRIMARY)
    },

    {   /* MDIO Clock */
        DEVICE_PAD_MDIOCLK,
        DEVICE_PIN_MUX_VALUE (DEVICE_PIN_MUX_BUFFER_CLASS_10, DEVICE_PIN_MUX_RX_DISABLED, DEVICE_PIN_MUX_PULL_DOWN,
                              DEVICE_PIN_MUX_PULL_DISABLE, DEVICE_PIN_MUX_MODE_PRIMARY)
    }

};

/*******************************************************************************************************
 * FUNCTION PURPOSE: Execute the pin mux
 *******************************************************************************************************
 * DESCRIPTION: The pin mux array is configured
 *******************************************************************************************************/
static void chip_pinmux (const devicePinMux_t *mux, int n)
{
    int i;

    for (i = 0; i < n; i++)  {

        DEVICE_REG32_W (DEVICE_PAD_REG_PAD_CONFIG(mux[i].padConfigAddress), mux[i].padValue);

    }

} /* chip_pinmux */

/** ============================================================================
 *   @n@b Mdio_PhyRegRead
 *
 *   @b Description
 *   @n Reads a PHY register using MDIO.
 *
 *   @param[in]
 *   phyAddr    PHY Adress.
 *   regNum     Register Number to be read.
 *   pData      Pointer where the read value shall be written.
 *
 *   @return    status of the read \n
 *              0  - read is successful.\n
 *              -1 - read is not acknowledged properly or
 *                      device is not accessible.
 *
 * =============================================================================
 */
static int Mdio_PhyRegRead(uint32_t phyAddr, uint32_t regNum, uint16_t *pData)
{
    CSL_MDIO_USERACCESS usrAccess;

    /* Verify whether the phy is active */
    if(!CSL_MDIO_isPhyAlive(phyAddr))
        return(-1);

    /* Wait till transaction completion if any */
    while (CSL_MDIO_isUserAccessPending(0));

    /* Initiate Register read access */
    usrAccess.phyAddr = phyAddr;
    usrAccess.regAddr = regNum;
    usrAccess.write = 0;
    usrAccess.go = 1;

    CSL_MDIO_setUserAccessRegister(0, &usrAccess);

    /* wait for command completion */
    while (CSL_MDIO_isUserAccessPending(0));

    /* Store the data if the read is acknowledged */
    CSL_MDIO_getUserAccessRegister(0, &usrAccess);

    if(usrAccess.ack)
    {
        *pData = usrAccess.data;
        return 0;
    }
    return -1;
}

/** ============================================================================
 *   @n@b Mdio_PhyRegWrite
 *
 *   @b Description
 *   @n Write a PHY register using MDIO.
 *
 *   @param[in]
 *   phyAddr    PHY Adress.
 *   regNum     Register Number to be read.
 *   regVal     Value to be written.
 *
 *   @return    status of the write \n
 *              0  - write is successful.\n
 *              -1 - write is not acknowledged properly or
 *                      device is not accessible.
 *
 * =============================================================================
 */
static int Mdio_PhyRegWrite(uint32_t phyAddr, uint32_t regNum, uint16_t regVal)
{
    CSL_MDIO_USERACCESS usrAccess;

    /* Verify whether the phy is active */
    if(!CSL_MDIO_isPhyAlive(phyAddr))
        return(-1);

    /* Wait till transaction completion if any */
    while (CSL_MDIO_isUserAccessPending(0));

    /* Initiate Register write access */
    usrAccess.phyAddr = phyAddr;
    usrAccess.regAddr = regNum;
    usrAccess.write = 1;
    usrAccess.go = 1;
    usrAccess.data = regVal;

    CSL_MDIO_setUserAccessRegister(0, &usrAccess);

    /* wait for command completion */
    while (CSL_MDIO_isUserAccessPending(0));

    /* Verify whether the write is acknowledged */
    CSL_MDIO_getUserAccessRegister(0, &usrAccess);

    if(usrAccess.ack)
    {
        return 0;
    }
    return -1;
}

#endif /* DEVICE_K2G */

void cpsw_getStats(CSL_CPSW_STATS*   stats, int clear)
{

   int numBlocks;
   CSL_CPSW_STATS* pStats = stats;
   
   CSL_CPSW_getStats(stats);
   for (numBlocks = 0; numBlocks < CSL_CPSW_NUMSTATBLOCKS; numBlocks++)
   {
	   System_printf ("Stats for block number: %d \n", numBlocks);
	   System_printf ("********************************************\n");
	   System_printf("	Good Frames Received                      %d\n", stats->RxGoodFrames);

	   System_printf("	Good Broadcast Frames Received            %d\n", stats->RxBCastFrames);

	   System_printf("	Good Multicast Frames Received            %d\n", stats->RxMCastFrames);

	   System_printf("	PauseRx Frames Received                   %d\n", stats->RxPauseFrames);

	   System_printf("	Frames Received with CRC Errors           %d\n", stats->RxCRCErrors);

	   System_printf("	Frames Received with Alignment/Code Errors%d\n", stats->RxAlignCodeErrors);

	   System_printf("	Oversized Frames Received                 %d\n", stats->RxOversized);

	   System_printf("	Jabber Frames Received                    %d\n", stats->RxJabber);

	   System_printf("	Undersized Frames Received                %d\n", stats->RxUndersized);

	   System_printf("	Rx Frame Fragments Received               %d\n", stats->RxFragments);

	   System_printf("	Total Received Bytes in Good Frames       %d\n", stats->RxOctets);

	   System_printf("	Good Frames Sent                          %d\n", stats->TxGoodFrames);

	   System_printf("	Good Broadcast Frames Sent                %d\n", stats->TxBCastFrames);

	   System_printf("	Good Multicast Frames Sent                %d\n", stats->TxMCastFrames);

	   System_printf("	PauseTx Frames Sent                       %d\n", stats->TxPauseFrames);

	   System_printf("	Frames Where Transmission was Deferred    %d\n", stats->TxDeferred);

	   System_printf("	Total Frames Sent With Collision          %d\n", stats->TxCollision);

	   System_printf("	Frames Sent with Exactly One Collision    %d\n", stats->TxSingleColl);

	   System_printf("	Frames Sent with Multiple Colisions       %d\n", stats->TxMultiColl);

	   System_printf("	Tx Frames Lost Due to Excessive Collisions%d\n", stats->TxExcessiveColl);

	   System_printf("	Tx Frames Lost Due to a Late Collision    %d\n", stats->TxLateColl);

	   System_printf("	Tx Frames Lost Due to Carrier Sense Loss  %d\n", stats->TxCarrierSLoss);

	   System_printf("	Total Transmitted Bytes in Good Frames    %d\n", stats->TxOctets);

	   System_printf("	Total Tx&Rx with Octet Size of 64         %d\n", stats->Frame64);

	   System_printf("	Total Tx&Rx with Octet Size of 65 to 127  %d\n", stats->Frame65t127);

	   System_printf("	Total Tx&Rx with Octet Size of 128 to 255 %d\n", stats->Frame128t255);

	   System_printf("	Total Tx&Rx with Octet Size of 256 to 511 %d\n", stats->Frame256t511);

	   System_printf("	Total Tx&Rx with Octet Size of 512 to 1023 %d\n",  stats->Frame512t1023);

	   System_printf("	Total Tx&Rx with Octet Size of >=1024     %d\n", stats->Frame1024tUp);

	   System_printf("	Sum of all Octets Tx or Rx on the Network %d\n", stats->NetOctets);

	   System_printf ("********************************************\n");
       System_flush();
	   stats++;
   }
   
   if (clear)
   {
        memset(pStats, 0, sizeof(CSL_CPSW_STATS)*CSL_CPSW_NUMSTATBLOCKS);
   }

}

#ifdef DEVICE_K2G
/** ============================================================================
 *   @n@b Init_RGMII
 *
 *   @b Description
 *   @n RGMII initialization code.
 *
 *   @param[in]
 *   @n None
 *
 *   @return
 *   @n None
 * =============================================================================
 */
Int32 Init_RGMII (void)
{

    /* Select RGMII as EMAC intercae */
    DEVICE_REG32_W (DEVICE_BOOTCFG_REG_ADDR_ETH_CFG, DEVICE_BOOTCFG_ETH_CFG_IF_SEL_RGMII);
    
    /* Setup pin Mux */
    chip_pinmux(pinMuxRgmii, sizeof(pinMuxRgmii) / sizeof(devicePinMux_t));
    
    return (0);

}

#endif

/** ============================================================================
 *   @n@b Init_SGMII
 *
 *   @b Description
 *   @n SGMII peripheral initialization code.
 *
 *   @param[in]
 *   @n macPortNum      MAC port number for which the SGMII port setup must
 *                      be performed.
 *
 *   @return
 *   @n None
 * =============================================================================
 */
Int32 Init_SGMII (UInt32 macPortNum)
{
    CSL_SGMII_ADVABILITY    sgmiiCfg;
    CSL_SGMII_STATUS        sgmiiStatus;

#ifdef DEVICE_K2G

    /* The SOG simulator only supports SGMII where the K2G device support RGMII */
    if(cpswSimTest)
    {
        /* Reset the port before configuring it */
        CSL_SGMII_doSoftReset (macPortNum);
        while (CSL_SGMII_getSoftResetStatus (macPortNum) != 0);

        /* Hold the port in soft reset and set up
        * the SGMII control register:
        *      (1) Enable Master Mode (default)
        *      (2) Enable Auto-negotiation
        */
        CSL_SGMII_startRxTxSoftReset (macPortNum);
        if (cpswLpbkMode == CPSW_LOOPBACK_NONE)
        {
            CSL_SGMII_disableMasterMode (macPortNum);
        }
        else
        {
            CSL_SGMII_enableMasterMode (macPortNum);

            if (cpswLpbkMode == CPSW_LOOPBACK_INTERNAL)
            {
                CSL_SGMII_enableLoopback (macPortNum);
            }
        }

        /* Setup the Advertised Ability register for this port:
        *      (1) Enable Full duplex mode
        *      (2) Enable Auto Negotiation
        */
        sgmiiCfg.linkSpeed      =   CSL_SGMII_1000_MBPS;
        sgmiiCfg.duplexMode     =   CSL_SGMII_FULL_DUPLEX;
        CSL_SGMII_setAdvAbility (macPortNum, &sgmiiCfg);

        CSL_SGMII_enableAutoNegotiation (macPortNum);
        CSL_SGMII_endRxTxSoftReset (macPortNum);

    }

#else    
    
#if !defined(DEVICE_K2K) && !defined(DEVICE_K2H)  && !defined(DEVICE_K2L)  && !defined(DEVICE_K2E)
    /* Configure SGMII Port 1 only since it is connected to RJ45 at all known EVMs */
    if(cpswSimTest || (macPortNum == 1))
    {
#endif
        /* Reset the port before configuring it */
        CSL_SGMII_doSoftReset (macPortNum);
        while (CSL_SGMII_getSoftResetStatus (macPortNum) != 0);

        /* Hold the port in soft reset and set up
        * the SGMII control register:
        *      (1) Enable Master Mode (default)
        *      (2) Enable Auto-negotiation
        */
        CSL_SGMII_startRxTxSoftReset (macPortNum);
        if (cpswLpbkMode == CPSW_LOOPBACK_NONE)
        {
            CSL_SGMII_disableMasterMode (macPortNum);
        }
        else
        {
            CSL_SGMII_enableMasterMode (macPortNum);

            if (cpswLpbkMode == CPSW_LOOPBACK_INTERNAL)
            {
                CSL_SGMII_enableLoopback (macPortNum);
            }
        }

        /* Setup the Advertised Ability register for this port:
        *      (1) Enable Full duplex mode
        *      (2) Enable Auto Negotiation
        */
        sgmiiCfg.linkSpeed      =   CSL_SGMII_1000_MBPS;
        sgmiiCfg.duplexMode     =   CSL_SGMII_FULL_DUPLEX;
        CSL_SGMII_setAdvAbility (macPortNum, &sgmiiCfg);

        CSL_SGMII_enableAutoNegotiation (macPortNum);
        CSL_SGMII_endRxTxSoftReset (macPortNum);

        /* Wait for SGMII Link */
        if (!cpswSimTest)
        {
            do
            {
                CSL_SGMII_getStatus(macPortNum, &sgmiiStatus);
            } while (sgmiiStatus.bIsLinkUp != 1);

            /* Wait for SGMII Autonegotiation to complete without error */
            do
            {
                CSL_SGMII_getStatus(macPortNum, &sgmiiStatus);
                if (sgmiiStatus.bIsAutoNegError != 0)
                    return -1;
            } while (sgmiiStatus.bIsAutoNegComplete != 1);

            /*
             * May need to wait some more time for the external PHY to be ready to transmit packets reliabily.
             * It is possible to access the PHY status register through the MDIO interface to check when
             * the PHY is ready.
             * To avoid platform-dependent code, we just introduce about 2ms wait here
             */
            if((cpswLpbkMode == CPSW_LOOPBACK_EXTERNAL) || (cpswLpbkMode == CPSW_LOOPBACK_NONE))
                CycleDelay(2000000);
        }
#if !defined(DEVICE_K2K) && !defined(DEVICE_K2H)  && !defined(DEVICE_K2L)  && !defined(DEVICE_K2E)
    }
#endif

#endif
    /* All done with configuration. Return Now. */
    return 0;
}

/** ============================================================================
 *   @n@b Init_MAC
 *
 *   @b Description
 *   @n This API initializes the CPGMAC Sliver (MAC Port) port.
 *
 *   @param[in]
 *   @n macPortNum      MAC port number for which the initialization must be done.
 *
 *   @param[in]
 *   @n macAddress      MAC address to configure on this port.
 *
 *   @param[in]
 *   @n mtu             Maximum Frame length to configure on this port.
 *
 *   @return
 *   @n None
 * =============================================================================
 */
int Init_MAC (UInt32 macPortNum, UInt8 macAddress[6], UInt32 mtu)
{

#if defined (NSS_GEN2) || defined (NSS_LITE) 
    CSL_CPSW_TSCONFIG  tsCfg;
    
    memset(&tsCfg, 0, sizeof(CSL_CPSW_TSCONFIG));
#endif    


    /* Reset MAC Sliver 0 */
    CSL_CPGMAC_SL_resetMac (macPortNum);
    while (CSL_CPGMAC_SL_isMACResetDone (macPortNum) != TRUE);

    /* Setup the MAC Control Register for this port:
     *      (1) Enable Full duplex
     *      (2) Enable GMII
     *      (3) Enable Gigabit
     *      (4) Enable External Configuration. This enables
     *          the "Full duplex" and "Gigabit" settings to be
     *          controlled externally from SGMII
     *      (5) Don't enable any control/error/short frames
     */
    CSL_CPGMAC_SL_enableFullDuplex (macPortNum);
    CSL_CPGMAC_SL_enableGMII (macPortNum);
    CSL_CPGMAC_SL_enableGigabit (macPortNum);
#ifndef DEVICE_K2G    
    CSL_CPGMAC_SL_enableExtControl (macPortNum);
#else    
    //CSL_CPGMAC_SL_enableGigForceMode(macPortNum);
#endif    
    
//#ifdef DEVICE_K2G
#if 0
    if (cpswLpbkMode == CPSW_LOOPBACK_INTERNAL)
    {
        CSL_CPGMAC_SL_enableLoopback (macPortNum);    
    }
#endif

    /* Configure VLAN ID/CFI/Priority.
     *
     * For now, we are not using VLANs so just configure them
     * to all zeros.
     */
    CSL_CPSW_setPortVlanReg (macPortNum, 0, 0, 0);

    /* Configure the Receive Maximum length on this port,
     * i.e., the maximum size the port can receive without
     * any errors.
     *
     * Set the Rx Max length to the MTU configured for the
     * interface.
     */
    CSL_CPGMAC_SL_setRxMaxLen (macPortNum, mtu);
    
#if defined (NSS_GEN2) || defined (NSS_LITE) 
    /*
     * Enable Port Time sync transmit host timestamp
     */
    tsCfg.tsRxAnnexDEnable = 1;
    tsCfg.tsRxAnnexEEnable = 1;
    tsCfg.tsRxAnnexFEnable = 1;
    tsCfg.tsRxVlanLType1Enable = 1;
    tsCfg.tsRxVlanLType2Enable = 1;
    tsCfg.tsTxAnnexDEnable = 1;
    tsCfg.tsTxAnnexEEnable = 1;
    tsCfg.tsTxAnnexFEnable = 1;
    tsCfg.tsTxVlanLType1Enable = 1;
    tsCfg.tsTxVlanLType2Enable = 1;
    tsCfg.tsTxHostEnable = 1;
    tsCfg.tsLType2Enable = 1;
    tsCfg.tsMsgTypeEnable = 0xFFFF;
    tsCfg.tsLType1= 0x88f7;
    tsCfg.tsLType2= 0x88b8;
    tsCfg.tsVlanLType1= 0x88a8;
    tsCfg.tsVlanLType2= 0x8100;
    tsCfg.tsUniEnable = 1; /* All addresses are enabled, including multicast */
    tsCfg.ts319Enable = 1;    
    tsCfg.ts320Enable = 1;  
    tsCfg.tsTTLNonzeroEnable = 1;
    tsCfg.tsSeqIdOffset = 30;
    tsCfg.tsDomainOffset = 4;
    CSL_CPSW_setPortTimeSyncConfig (macPortNum+1, &tsCfg);
    
    /*
     * Map all input packet priority to 0 so that it will be delivered by CPPI flow 0
     */
    { 
        Uint32 rxPriMap[8];
        
        memset (rxPriMap, 0, sizeof(rxPriMap));
        CSL_CPSW_setPortRxPriMapReg(macPortNum+1, rxPriMap); 
    }               
     
#endif      
    
    /* Done setting up the MAC port */
    return 0;
}

/** ============================================================================
 *   @n@b Init_MDIO
 *
 *   @b Description
 *   @n Not supported at moment. MDIO is not simulated yet.
 *
 *   @param[in]
 *   @n None
 *
 *   @return
 *   @n None
 * =============================================================================
 */
Void Init_MDIO (Void)
{
#ifdef DEVICE_K2G
    if (cpswLpbkMode == CPSW_LOOPBACK_INTERNAL)
    {
        /*
         * Configure Ethernet PHY to enter Gb Loopback mode
         * reg 0: 0x4140
         * reg 9: 0x1300
         */

        chip_pinmux(pinMuxMdio, sizeof(pinMuxMdio) / sizeof(devicePinMux_t));
        CSL_MDIO_disablePreamble();
        CSL_MDIO_enableStateMachine();
        CycleDelay(2000000);
        Mdio_PhyRegWrite(0, 0, 0x4140);
        Mdio_PhyRegWrite(0, 9, 0x1300);
    }
#endif

    /* Return success. */
    return;
}

/** ============================================================================
 *   @n@b Init_CPTS
 *
 *   @b Description
 *   @n Init and configure CPTS module
 *
 *   @param[in]
 *   @n None
 *
 *   @return
 *   @n None
 * =============================================================================
 */
Void Init_CPTS (Void)
{
#if defined (NSS_GEN2) || defined (NSS_LITE) 
    CSL_CPTS_CONTROL    ctrl;
    uint32_t            refClockSelect = 0;
    
    memset(&ctrl, 0, sizeof(CSL_CPTS_CONTROL));
    ctrl.cptsEn = 1;
    ctrl.tstampEn = 1;
    ctrl.seqEn = 0;
    ctrl.ts64bMode = 1;
    
    CSL_CPTS_disableCpts();
    
    CSL_CPTS_setRFTCLKSelectReg (refClockSelect);   
    
    CSL_CPTS_setCntlReg(&ctrl);
    
#endif

    /* Return success. */
    return;
}


/** ============================================================================
 *   @n@b Init_Switch
 *
 *   @b Description
 *   @n This API sets up the ethernet switch subsystem and its Address Lookup
 *      Engine (ALE) in "Switch" mode.
 *
 *   @param[in]
 *   @n mtu             Maximum Frame length to configure on the switch.
 *
 *   @return
 *   @n None
 * =============================================================================
 */
Void Init_Switch (UInt32 mtu)
{
    CSL_CPSW_PORTSTAT               portStatCfg;

    /* Enable the CPPI port, i.e., port 0 that does all
     * the data streaming in/out of EMAC.
     */
    CSL_CPSW_enablePort0 ();
    CSL_CPSW_disableVlanAware ();
    CSL_CPSW_setPort0VlanReg (0, 0, 0);
    CSL_CPSW_setPort0RxMaxLen (mtu);

    /* Enable statistics on both the port groups:
     *
     * MAC Sliver ports -   Port 1, Port 2
     * CPPI Port        -   Port 0
     */
    #if defined(DEVICE_K2K) || defined(DEVICE_K2H)
    portStatCfg.p0AStatEnable   =   1;
    portStatCfg.p0BStatEnable   =   1;
    portStatCfg.p1StatEnable    =   1;
    portStatCfg.p2StatEnable    =   1;
    #elif defined(DEVICE_K2G)
    portStatCfg.p0StatEnable    =   1;
    portStatCfg.p1StatEnable    =   1;
    #else
    portStatCfg.p0StatEnable    =   1;
    portStatCfg.p1StatEnable    =   1;
    portStatCfg.p2StatEnable    =   1;
    portStatCfg.p3StatEnable    =   1;
    portStatCfg.p4StatEnable    =   1;
    portStatCfg.p5StatEnable    =   1;
    portStatCfg.p6StatEnable    =   1;
    portStatCfg.p7StatEnable    =   1;
    portStatCfg.p8StatEnable    =   1;
    #endif
    CSL_CPSW_setPortStatsEnableReg (&portStatCfg);

    /* Setup the Address Lookup Engine (ALE) Configuration:
     *      (1) Enable ALE.
     *      (2) Clear stale ALE entries.
     *      (3) Disable VLAN Aware lookups in ALE since
     *          we are not using VLANs by default.
     *      (4) No Flow control
     *      (5) Configure the Unknown VLAN processing
     *          properties for the switch, i.e., which
     *          ports to send the packets to.
     */
    CSL_CPSW_enableAle ();
    CSL_CPSW_clearAleTable ();

    CSL_CPSW_disableAleVlanAware ();
    CSL_CPSW_disableAleTxRateLimit ();
    CSL_CPSW_setAlePrescaleReg (125000000u/1000u);
    CSL_CPSW_setAleUnkownVlanReg (7, 3, 3, 7);

    if(cpswLpbkMode != CPSW_LOOPBACK_NONE)
        CSL_CPSW_enableAleBypass();

    /* Done with switch configuration */
    return;
}


/** ============================================================================
 *   @n@b Switch_update_addr
 *
 *   @b Description
 *   @n This API add/delete entries in the Address Lookup Engine (ALE) in "Switch" mode.
 *
 *   @param[in]
 *   @n portNum         Switch port number.

 *   @param[in]
 *   @n macAddress      MAC address to configure on the switch.
 *
 *   @param[in]
 *   @n add             0:add; 1:delete.
 *
 *   @return
 *   @n None
 *
 *   @Note  It supports "add" operation only now.
 * =============================================================================
 */
int Switch_update_addr (Uint32 portNum, UInt8 macAddress[6], Uint16 add)
{
    Uint32                              i;
    CSL_CPSW_ALE_PORTCONTROL        alePortControlCfg;
    CSL_CPSW_ALE_UNICASTADDR_ENTRY  ucastAddrCfg;


    /* Configure the address in "Learning"/"Forward" state */
    alePortControlCfg.portState             =   ALE_PORTSTATE_FORWARD;
    alePortControlCfg.dropUntaggedEnable    =   0;
    alePortControlCfg.vidIngressCheckEnable =   0;
    alePortControlCfg.noLearnModeEnable     =   (cpswLpbkMode != CPSW_LOOPBACK_NONE)?1:0;
    alePortControlCfg.mcastLimit            =   0;
    alePortControlCfg.bcastLimit            =   0;

    CSL_CPSW_setAlePortControlReg (portNum, &alePortControlCfg);

    /*
     * The following code is required for device simulator only.
     * It is also served as an example of adding MAC address to the ALE table manually
     */

    if (cpswSimTest)
    {
        /* Program the ALE with the MAC address.
        *
        * The ALE entries determine the switch port to which any
        * matching received packet must be forwarded to.
        */
        /* Get the next free ALE entry to program */
        for (i = 0; i < CSL_CPSW_NUMALE_ENTRIES; i++)
        {
            if (CSL_CPSW_getALEEntryType (i) == ALE_ENTRYTYPE_FREE)
            {
                /* Found a free entry */
                break;
            }
        }
        if (i == CSL_CPSW_NUMALE_ENTRIES)
        {
            /* No free ALE entry found. return error. */
            return -1;
        }
        else
        {
            /* Found a free ALE entry to program our MAC address */
            memcpy (ucastAddrCfg.macAddress, macAddress, 6);    // Set the MAC address
            ucastAddrCfg.ucastType      =      ALE_UCASTTYPE_UCAST_NOAGE;   // Add a permanent unicast address entryALE_UCASTTYPE_UCAST_NOAGE.
            ucastAddrCfg.secureEnable   =      FALSE;
            ucastAddrCfg.blockEnable    =      FALSE;
            ucastAddrCfg.portNumber     =      portNum;   // Add the ALE entry for this port

            /* Setup the ALE entry for this port's MAC address */
            CSL_CPSW_setAleUnicastAddrEntry (i, &ucastAddrCfg);
        }
    }
    

    /* Done with upading address */
    return 0;
}


/** ============================================================================
 *   @n@b Init_SGMII_SERDES
 *
 *   @b Description
 *   @n This API sets up the configuration for the SGMII SERDES. Assumes a 125 MHz
 *       reference clock.
 *
 *   @param[in]
 *   @n None
 *
 *   @return
 *   @n None
 * =============================================================================
 */
Int32 Init_SGMII_SERDES(Void)
{

#ifndef DEVICE_K2G

	CSL_SERDES_LOOPBACK lpbk_mode = (cpswLpbkMode == CPSW_LOOPBACK_SERDES)?CSL_SERDES_LOOPBACK_ENABLED:CSL_SERDES_LOOPBACK_DISABLED;

	if(!cpswSimTest)
	{
#if defined(DEVICE_K2K) || defined(DEVICE_K2H)
    	uint32_t i;
    	CSL_SERDES_RESULT   csl_retval;
    	CSL_SERDES_LANE_ENABLE_STATUS lane_retval = CSL_SERDES_LANE_ENABLE_NO_ERR;
    	CSL_SERDES_STATUS   pllstat;

    	/* SB CMU and COMLANE and Lane Setup  */
    	csl_retval = CSL_EthernetSerdesInit(CSL_NETCP_SERDES_CFG_REGS, 
    	                                    CSL_SERDES_REF_CLOCK_156p25M, 
    	                                    CSL_SERDES_LINK_RATE_1p25G);

    	if (csl_retval != 0)
    	{
    	    System_printf ("Invalid Serdes Init Params\n");
    	}
        

    	//SB Lane Enable
    	for(i=0; i < NUM_MAC_PORTS; i++)
    	{
    	    lane_retval |= CSL_EthernetSerdesLaneEnable(CSL_NETCP_SERDES_CFG_REGS, 
    	                                                i, 
    	                                                lpbk_mode, 
    	                                                CSL_SERDES_LANE_QUARTER_RATE);
    	}

    	if (lane_retval != 0)
    	{
    	    System_printf ("Invalid Serdes Lane Rate\n");
    	}

    	/* SB PLL Enable */
    	CSL_EthernetSerdesPllEnable(CSL_NETCP_SERDES_CFG_REGS);

    	/* SB PLL Status Poll */
    	do
    	{
    	    pllstat = CSL_EthernetSerdesGetStatus(CSL_NETCP_SERDES_CFG_REGS, NUM_MAC_PORTS);
    	}while(pllstat == CSL_SERDES_STATUS_PLL_NOT_LOCKED);
#elif defined(DEVICE_K2E)
    	uint32_t i;
    	CSL_SERDES_RESULT   csl_retval;
    	CSL_SERDES_LANE_ENABLE_STATUS lane_retval = 0;
    	CSL_SERDES_STATUS   pllstat;
        int numPort1 = (NUM_MAC_PORTS > 4)?4:NUM_MAC_PORTS;
        int numPort2 = (NUM_MAC_PORTS > 4)?NUM_MAC_PORTS - 4:0;
        

    	/* SB CMU and COMLANE and Lane Setup */
    	csl_retval = CSL_EthernetSerdesInit(CSL_NETCP_SERDES_0_CFG_REGS, 
    	                                    CSL_SERDES_REF_CLOCK_156p25M, 
    	                                    CSL_SERDES_LINK_RATE_1p25G); /* 4 port switch1 */

        if (numPort2)
        {
    	    csl_retval |= CSL_EthernetSerdesInit(CSL_NETCP_SERDES_1_CFG_REGS, 
    	                                         CSL_SERDES_REF_CLOCK_156p25M, 
    	                                         CSL_SERDES_LINK_RATE_1p25G); /* 4 port switch2 */
        }    
                                         
    	if (csl_retval != 0)
    	{
    	    System_printf ("Invalid Serdes Init Params\n");
    	}  

    	//SB Lane Enable
    	for(i=0; i < numPort1; i++)
    	{
    	    lane_retval |= CSL_EthernetSerdesLaneEnable(CSL_NETCP_SERDES_0_CFG_REGS, 
    	                                                i, 
    	                                                lpbk_mode, 
    	                                                CSL_SERDES_LANE_QUARTER_RATE); /* 4 port switch1 */
    	}
        
    	for(i=0; i < numPort2; i++)
    	{
    	    lane_retval |= CSL_EthernetSerdesLaneEnable(CSL_NETCP_SERDES_1_CFG_REGS, 
    	                                                i, 
    	                                                lpbk_mode, 
    	                                                CSL_SERDES_LANE_QUARTER_RATE); /* 4 port switch2 */	
    	}

    	if (lane_retval != 0)
    	{
    	    System_printf ("Invalid Serdes Lane Rate\n");
    	}

    	/* SB PLL Enable */
    	CSL_EthernetSerdesPllEnable(CSL_NETCP_SERDES_0_CFG_REGS); /* 4 port switch1 */
        if(numPort2)
    	    CSL_EthernetSerdesPllEnable(CSL_NETCP_SERDES_1_CFG_REGS); /* 4 port switch2 */    

    	/* SB PLL Status Poll */
    	do
    	{
    	    pllstat = CSL_EthernetSerdesGetStatus(CSL_NETCP_SERDES_0_CFG_REGS, numPort1); /* 4 port switch1 */
            if(numPort2)
    	        pllstat &= CSL_EthernetSerdesGetStatus(CSL_NETCP_SERDES_1_CFG_REGS, numPort2); /* 4 port switch2 */	
    	}while(pllstat == CSL_SERDES_STATUS_PLL_NOT_LOCKED);

#elif defined(DEVICE_K2L)
    	uint32_t i;
    	CSL_SERDES_RESULT   csl_retval;
    	CSL_SERDES_LANE_ENABLE_STATUS lane_retval = CSL_SERDES_LANE_ENABLE_NO_ERR;
    	CSL_SERDES_STATUS   pllstat;
		uint32_t serdes_mux_ethernet_sel;
        int numPort1 = (NUM_MAC_PORTS > 2)?2:NUM_MAC_PORTS;
        int numPort2 = (NUM_MAC_PORTS > 2)?NUM_MAC_PORTS - 2:0;
        
	
		/* Check CSISC2_3_MUXSEL bit */
		if (CSL_FEXTR(*(volatile uint32_t *)(CSL_BOOT_CFG_REGS + 0x20), 28, 28) == 0)
			serdes_mux_ethernet_sel = 1;

    	/* SB CMU and COMLANE and Lane Setup */
    	csl_retval = CSL_EthernetSerdesInit(CSL_CSISC2_2_SERDES_CFG_REGS, 
    	                                    CSL_SERDES_REF_CLOCK_156p25M, 
    	                                    CSL_SERDES_LINK_RATE_1p25G); /* SGMII Lane 0 and Lane 1 */
    
		if (serdes_mux_ethernet_sel && numPort2)
		{
			csl_retval |= CSL_EthernetSerdesInit(CSL_CSISC2_3_SERDES_CFG_REGS, 
    		                                     CSL_SERDES_REF_CLOCK_156p25M, 
    		                                     CSL_SERDES_LINK_RATE_1p25G); /* SGMII Lane 2 and Lane 3 */
		}

    	if (csl_retval != 0)
    	{
    	    System_printf ("Invalid Serdes Init Params\n");
    	} 

    	//SB Lane Enable
    	for(i=0; i < numPort1; i++)
    	{
    	    lane_retval |= CSL_EthernetSerdesLaneEnable(CSL_CSISC2_2_SERDES_CFG_REGS, 
    	                                                i, 
    	                                                lpbk_mode, 
    	                                                CSL_SERDES_LANE_QUARTER_RATE); /* SGMII Lane 0 and Lane 1 */
    	}
        
		if (serdes_mux_ethernet_sel && numPort2)
        {
    	    for(i=0; i < numPort1; i++)
    	    {
    	        lane_retval |= CSL_EthernetSerdesLaneEnable(CSL_CSISC2_3_SERDES_CFG_REGS, 
    	                                                    i, 
    	                                                    lpbk_mode, 
    	    	                                            CSL_SERDES_LANE_QUARTER_RATE); /* SGMII Lane 2 and Lane 3 */	
    	    }
        }

    	if (lane_retval != 0)
    	{
    	    System_printf ("Invalid Serdes Lane Rate\n");
    	}

    	/* SB PLL Enable */
    	CSL_EthernetSerdesPllEnable(CSL_CSISC2_2_SERDES_CFG_REGS); /* SGMII Lane 0 and Lane 1 */
	
		/* Check CSISC2_3_MUXSEL bit */
		if (serdes_mux_ethernet_sel) 	
    		CSL_EthernetSerdesPllEnable(CSL_CSISC2_3_SERDES_CFG_REGS); /* SGMII Lane 2 and Lane 3 */    

    	/* SB PLL Status Poll */
    	do
    	{
    	    pllstat = CSL_EthernetSerdesGetStatus(CSL_CSISC2_2_SERDES_CFG_REGS, numPort1); /* SGMII Lane 0 and Lane 1 */	
    	}while(pllstat == CSL_SERDES_STATUS_PLL_NOT_LOCKED);
	
		/* Check CSISC2_3_MUXSEL bit */
		if (serdes_mux_ethernet_sel)
		{
    	    do
    	    {
    	        pllstat = CSL_EthernetSerdesGetMuxStatus(CSL_CSISC2_3_SERDES_CFG_REGS, numPort2); /* SGMII Lane 2 and Lane 3 */	
    	    }while(pllstat == CSL_SERDES_STATUS_PLL_NOT_LOCKED);
		}
#endif

	}
    
#endif    

    /* SGMII SERDES Configuration complete. Return. */
    return 0;
}
/** ============================================================================
 *   @n@b Init_Cpsw
 *
 *   @b Description
 *   @n This API sets up the entire ethernet subsystem and all its associated
 *      components.
 *
 *   @param[in]
 *   @n None
 *
 *   @return
 *   @n None
 * =============================================================================
 */
int dest_emac_port_id = 0;
Int32 Init_Cpsw (Void)
{
    Uint32       macPortNum, mtu = 1518;
    Uint8        macSrcAddress [][6] =  {{0x10, 0x11, 0x12, 0x13, 0x14, 0x15},
                                         {0x20, 0x21, 0x22, 0x23, 0x24, 0x25},
                                         {0x20, 0x21, 0x22, 0x23, 0x24, 0x35},
                                         {0x20, 0x21, 0x22, 0x23, 0x24, 0x45},
                                         {0x20, 0x21, 0x22, 0x23, 0x24, 0x55},
                                         {0x20, 0x21, 0x22, 0x23, 0x24, 0x65},
                                         {0x20, 0x21, 0x22, 0x23, 0x24, 0x75},
                                         {0x20, 0x21, 0x22, 0x23, 0x24, 0x85},
                                         };
                                         
    Uint8        macAddress[] [6] = {{0x00, 0x01, 0x02, 0x03, 0x04, 0x05},  /* MAC address for (CPPI) Port 0 */
                                     {0x10, 0x11, 0x12, 0x13, 0x14, 0x15},  /* MAC address for (EMAC) Port 1 */
                                     {0x20, 0x21, 0x22, 0x23, 0x24, 0x25},  /* MAC address for (EMAC) Port 2 */
                                     {0x30, 0x31, 0x32, 0x33, 0x34, 0x35},  /* MAC address for (EMAC) Port 3 */
                                     {0x40, 0x41, 0x42, 0x43, 0x44, 0x45},  /* MAC address for (EMAC) Port 4 */
                                     {0x50, 0x51, 0x52, 0x53, 0x54, 0x55},  /* MAC address for (EMAC) Port 5 */
                                     {0x60, 0x61, 0x62, 0x63, 0x64, 0x65},  /* MAC address for (EMAC) Port 6 */
                                     {0x70, 0x71, 0x72, 0x73, 0x74, 0x75},  /* MAC address for (EMAC) Port 7 */
                                     {0x80, 0x81, 0x82, 0x83, 0x84, 0x85}   /* MAC address for (EMAC) Port 8 */
                                     }; 
    Uint32       portNum;                                 
    

    /* Initialize the SERDES modules */
    Init_SGMII_SERDES();
    
#ifdef DEVICE_K2G
    /* Initialize the RGMII interface */
    if (Init_RGMII())
      return -1;
#endif        

    /* Initialize the SGMII/Sliver submodules for the
     * two corresponding MAC ports.
     */
    for (macPortNum = 0; macPortNum < NUM_MAC_PORTS; macPortNum++)
    {
        if (Init_SGMII (macPortNum))
          return -1;
        Init_MAC (macPortNum, &macSrcAddress[macPortNum][0], mtu);
    }

    /* Setup the Phys by initializing the MDIO */
    Init_MDIO ();
    
    Init_CPTS ();

    /* Setup the Ethernet switch finally. */
    Init_Switch (mtu);

    if(cpswLpbkMode == CPSW_LOOPBACK_NONE)
        Switch_update_addr(0, macAddress[0], 0);
    else
        Switch_update_addr(0, macAddress[1], 0);
    
    for (portNum = 1; portNum < NUM_PORTS; portNum++)
        Switch_update_addr(portNum, macAddress[portNum], 0);
    
    /* CPSW subsystem setup done. Return success */
    return 0;
}
