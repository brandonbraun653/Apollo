/******************************************************************************
 * Copyright (c) 2017 Texas Instruments Incorporated - http://www.ti.com
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

#include <ti/csl/soc.h>
#include <ti/csl/csl_gpio.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/src/ip/mdio/V2/cslr_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdio.h>
#include <ti/csl/src/ip/mdio/V2/csl_mdioAux.h>

#include "board_internal.h"
#include "board_cfg.h"
#include "board_tlkphy.h"

#include <ti/starterware/include/device.h>
#include <ti/starterware/include/hw/hw_icss_mii_mdio.h>

#define CSL_ICSSIEP_COUNT_REG0          CSL_ICSSM_IEP_COUNT
#define CSL_ICSSIEP_DIGIO_CTRL_REG      CSL_ICSSM_IEP_DIGIO_CTRL
#define CSL_ICSSIEP_DIGIO_EXP_REG       CSL_ICSSM_IEP_DIGIO_EXP
#define CSL_ICSSIEP_DIGIO_DATA_OUT_REG  CSL_ICSSM_IEP_DIGIO_DATA_OUT
#define CSL_ICSSMIIMDIO_LINK            CSL_ICSSM_MII_MDIO_LINK

/* PHY register offset definitions */
#define PHY_BCR                         (0u)
#define PHY_BSR                         (1u)
#define PHY_ID1                         (2u)
#define PHY_ID2                         (3u)
#define PHY_AUTONEG_ADV                 (4u)
#define PHY_LINK_PARTNER_ABLTY          (5u)
#define PHY_1000BT_CONTROL              (9u)
#define PHY_1000BT_STATUS               (0x0A)

/* PHY status definitions */
#define PHY_ID_SHIFT                    (16u)
#define PHY_SOFTRESET                   (0x8000)
#define PHY_AUTONEG_ENABLE              (0x1000u)
#define PHY_AUTONEG_RESTART             (0x0200u)
#define PHY_AUTONEG_COMPLETE            (0x0020u)
#define PHY_AUTONEG_INCOMPLETE          (0x0000u)
#define PHY_AUTONEG_STATUS              (0x0020u)
#define PHY_AUTONEG_ABLE                (0x0008u)
#define PHY_LPBK_ENABLE                 (0x4000u)
#define PHY_LINK_STATUS                 (0x0004u)

/* PHY ID. The LSB nibble will vary between different phy revisions */
#define PHY_ID_REV_MASK                 (0x0000000Fu)

/* Pause operations */
#define PHY_PAUSE_NIL                   (0x0000u)
#define PHY_PAUSE_SYM                   (0x0400u)
#define PHY_PAUSE_ASYM                  (0x0800u)
#define PHY_PAUSE_BOTH_SYM_ASYM         (0x0C00u)

/* 1000 Base-T capabilities */
#define PHY_NO_1000BT                   (0x0000u)
#define PHY_1000BT_HD                   (0x0100u)
#define PHY_1000BT_FD                   (0x0200u)

/* 100 Base TX Full Duplex capablity */
#define PHY_100BTX_HD                   (0x0000u)
#define PHY_100BTX_FD                   (0x0100u)

/* 100 Base TX capability */
#define PHY_NO_100BTX                   (0x0000u)
#define PHY_100BTX                      (0x0080u)

/* 10 BaseT duplex capabilities */
#define PHY_10BT_HD                     (0x0000u)
#define PHY_10BT_FD                     (0x0040u)

/* 10 BaseT ability*/
#define PHY_NO_10BT                     (0x0000u)
#define PHY_10BT                        (0x0020u)

#define PHY_LINK_PARTNER_1000BT_FD      (0x0800u)
#define PHY_LINK_PARTNER_1000BT_HD      (0x0400u)

/* Speed settings for BCR register */
#define PHY_SPEED_MASK                  (0xDFBF)
#define PHY_SPEED_10MBPS                (0x0000u)
#define PHY_SPEED_100MBPS               (0x2000u)
#define PHY_SPEED_1000MBPS              (0x0040)

/* Duplex settings for BCR register */
#define PHY_FULL_DUPLEX                 (0x0100)

/**
*      Configure PHY in AutoNeg mode
*/
#define PHY_CONFIG_AUTONEG              0u
/**
*      Force PHY to 100 FullDuplex
*/
#define PHY_CONFIG_100FD                1u
/**
*      Force PHY to 10 FullDuplex
*/
#define PHY_CONFIG_10FD                 2u
/**
*      Force PHY to 100 halfDuplex
*/
#define PHY_CONFIG_100HD                3u
/**
*      Force PHY to 100 halfDuplex
*/
#define PHY_CONFIG_10HD                 4u

/* MDIO register value to select MLINk mode of Link detection */
#define MDIO_LINKSEL_ENABLE             1
/* MDIO register value to select MDIO mode of Link detection */
#define MDIO_LINKSEL_DISABLE            0

#define AMIC110_PHY1                    1
#define AMIC110_PHY2                    13

/* Structure holding the GPIO pin object data structure. */
typedef struct gpioPinObj
{
    uint32_t     pinNum;
    /**< GPIO pin number. */
    uint32_t     instNum;
    /**< GPIO instance number. */
    uint32_t     instAddr;
    /**< GPIO instance address. */
}gpioPinObj_t;

/**
 * \brief  Local Delay function
 *
 * \return  none
 */
static void Board_delay(uint32_t ix);/* for misra warning */
static void Board_delay(uint32_t ix)
{
    while (ix--) {
        asm("   NOP");
    }
}

/**
* @brief Function does the  MLED Configuration of TLK 105
*
* @param mdioBaseAddress MDIO Base Address
* @param phyNum Phy address of the port
* @param mode MLed Config mode
* @param mdioSemhandle Semaphore handle if thread safe MDIO access is used

* @retval none
*/
void Board_phyMLEDConfig(uint32_t mdioBaseAddress, uint32_t phyNum,
                         uint16_t mode)
{
    uint16_t phyregval = 0;


    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_REGCR_REG,
                         EXT_REG_ADDRESS_ACCESS);

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_ADDR_REG,
                         TLK105_EXT_MLEDCR_REG);

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_REGCR_REG,
                         EXT_REG_DATA_NORMAL_ACCESS);

    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, TLKPHY_ADDR_REG, &phyregval);

    switch(mode)
    {
        case PHY_MLED_100:
            /*Bit10: MLED Pin29 Route and Enable (COL disable)
              Bit6:3: 0101 : High for 100 base TX 
              Bit 0:1 : 0 MLED Pin17 routing disable (LINK_LED) */
            phyregval |= ((1 << 10) | (5 << 3));
            phyregval &= ~(3);
            break;

        case PHY_RXTX_ACT:
            /*Bit10: MLED Pin29 Route and Enable (COL disable)
              Bit9: MLED polarity - important to keep it ACTIVE HIGH(PD) due to IDK HW errata
              Bit6:3: 0001 :RX/TX activity
              Bit 0:1 : 0 MLED Pin17 routing disable (LINK_LED) */
            phyregval |= ((1 << 10) | (1 << 3));
            phyregval &= ~((1 << 9) | 3);/*Bit 9 clear,LED on */
            break;

        case PHY_DIS_MLED:
            /*Bit10: MLED Pin29 Route and Disable (COL enable)
              Bit9: MLED polarity - important to keep it ACTIVE HIGH(PD) due to IDK HW errata
              Bit6:3: XXXX : Don;t care
              Bit 0:1 : 0 MLED Pin17 routing disable (LINK_LED) */
            phyregval &= ~((1 << 10) |(1 << 9) | 3); /*Bit 9 clear,LED on */
            break;
    }

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_ADDR_REG, phyregval);
}

void Board_enablePhyAutoMDIX(uint32_t mdioBaseAddress, uint32_t phyNum)
{
    uint16_t phyregval = 0;
    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, TLKPHY_PHYCR_REG, &phyregval);
    phyregval |= TLKPHY_AUTOMDIX_ENABLE;
    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_PHYCR_REG, phyregval);
}

uint8_t Board_getPhyIdentifyStat(uint32_t mdioBaseAddress, uint32_t phyAddr)
{
    uint16_t regStatus = 0;

    CSL_MDIO_phyRegRead(mdioBaseAddress, phyAddr, PHY_ID1_REG, &regStatus);

    if(regStatus == 0x2000)
    {
        return TRUE;
    }

    else
    {
        return FALSE;
    }
}

void Board_phyExtFDEnable(uint32_t mdioBaseAddress, uint32_t phyNum)
{
    uint16_t phyregval = 0;

    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, TLKPHY_CR2_REG, &phyregval);
    phyregval |= EXT_FD_ENABLE;
    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_CR2_REG, phyregval);
}

void Board_phyODDNibbleDetEnable(uint32_t mdioBaseAddress, uint32_t phyNum)
{
    uint16_t phyregval = 0;
    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, TLKPHY_CR2_REG, &phyregval);
    phyregval |= ODDNIBBLE_DET_ENABLE;
    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_CR2_REG, phyregval);
}

void Board_phyRxErrIdleEnable(uint32_t mdioBaseAddress, uint32_t phyNum)
{
    uint16_t phyregval = 0;

    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, TLKPHY_CR2_REG, &phyregval);
    phyregval |= RXERROR_IDLE_ENABLE;
    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_CR2_REG, phyregval);
}

/**
* @brief Function does the  LED Configuration of TLK 105
*
* @param mdioBaseAddress MDIO Base Address
* @param phyNum Phy address of the port
* @param mode Led Config mode
* @param mdioSemhandle Semaphore handle if thread safe MDIO access is used

* @retval none
*/
void Board_phyLedConfig(uint32_t mdioBaseAddress, uint32_t phyNum,
                        uint8_t mode)
{
    uint16_t phyregval = 0;

    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, TLKPHY_PHYCR_REG, &phyregval);

    switch(mode)
    {
        case LED_CFG_MODE1:
            phyregval |= (1 << 5);   /*Set LED_CFG[0] to 1*/
            break;

        case LED_CFG_MODE2:
            phyregval &= ~(1 << 5);   /*Set LED_CFG[0] to 0*/
            break;
    }

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_PHYCR_REG, phyregval);
}

void Board_phyLedBlinkConfig(uint32_t mdioBaseAddress, uint32_t phyNum,
                             uint16_t val)
{
    uint16_t phyregval = 0;

    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, TLKPHY_LEDCR_REG, &phyregval);

    switch(val)
    {
        case LED_BLINK_500:
            phyregval &= 0xF9FF;
            phyregval |= 0x0600;
            break;

        case LED_BLINK_200:
            phyregval &= 0xF9FF;
            phyregval |= 0x0400;
            break;

        case LED_BLINK_100:
            phyregval &= 0xF9FF;
            phyregval |= 0x0200;
            break;

        case LED_BLINK_50:
            phyregval &= 0xF9FF;
            break;
    }

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_LEDCR_REG, phyregval);
}

void Board_phyFastLinkDownDetEnable(uint32_t mdioBaseAddress, uint32_t phyNum,
                                    uint8_t val)
{
    uint16_t phyregval = 0;
    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, TLKPHY_CR3_REG, &phyregval);
    phyregval |= val;
    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_CR3_REG, phyregval);
}

/**
* @brief Function does the  LED_1 Configuration of DP83822
*
* @param mdioBaseAddress MDIO Base Address
* @param phyNum Phy address of the port
* @param mode LED_1 Config mode
* @param mdioSemhandle Semaphore handle if thread safe MDIO access is used

* @retval none
*/
void Board_phyLED1Config(uint32_t mdioBaseAddress, uint32_t phyNum,
                         uint16_t mode)
{
    uint16_t phyregval = 0;


    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_REGCR_REG,
                         EXT_REG_ADDRESS_ACCESS);

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_ADDR_REG,
                         DP83822_EXT_IOCTRL1_REG);

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_REGCR_REG,
                         EXT_REG_DATA_NORMAL_ACCESS);

    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, TLKPHY_ADDR_REG, &phyregval);
    phyregval &= ~(0x0007);
    phyregval |= (0x1);
    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_ADDR_REG, phyregval);




    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_REGCR_REG,
                         EXT_REG_ADDRESS_ACCESS);

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_ADDR_REG,
                         DP83822_EXT_LEDCFG1_REG);

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_REGCR_REG,
                         EXT_REG_DATA_NORMAL_ACCESS);

    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, TLKPHY_ADDR_REG, &phyregval);

    switch(mode)
    {
        case LED_CFG_MODE0: /* LINK OK */
            phyregval &= ~(0x0F00);
            phyregval |= (0x0);
            break;

        case LED_CFG_MODE1: /* RX/TX Activity */
            phyregval &= ~(0x0F00);
            phyregval |= (0x8 << 8);
            break;
    }

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, TLKPHY_ADDR_REG, phyregval);

}

uint8_t Board_getAutoNegStat(uint32_t mdioBaseAddress, uint32_t phyAddr)
{
    uint16_t regStatus = 0;
    uint16_t i;
    uint16_t phyRegVal[32];

    for(i = 0; i < 32; i++)
        CSL_MDIO_phyRegRead(mdioBaseAddress, phyAddr, i, &phyRegVal[i]);

    CSL_MDIO_phyRegRead(mdioBaseAddress, phyAddr, PHY_BCR_REG, &regStatus);

    if(regStatus & MII_AUTO_NEGOTIATE_EN)
    {
        return TRUE;
    }

    else
    {
        return FALSE;
    }
}

void Board_phyAutoNegAdvConfig(uint32_t mdioBaseAddress, uint32_t phyNum)
{
    uint16_t regStatus = 0;

    CSL_MDIO_phyRegRead(mdioBaseAddress, phyNum, PHY_AUTONEG_ADV_REG, &regStatus);

    regStatus |= PHY_ANAR_100FD;
    regStatus |= PHY_ANAR_100HD;
    regStatus |= PHY_ANAR_10FD;
    regStatus |= PHY_ANAR_10HD;

    CSL_MDIO_phyRegWrite(mdioBaseAddress, phyNum, PHY_AUTONEG_ADV_REG, regStatus);

}

/**
* @internal
* @brief Function to write into MDIOUSERPHYSEL0/MDIOUSERPHYSEL1 TODO Temp- PDK doesn't have this API
*
* @param baseAddr   [IN] MDIO Base Address
* @param phyinst    [IN] MDIOUSERPHYSEL0/MDIOUSERPHYSEL1
* @param val        [IN] value to be written
*
*  @retval none
*/
void MDIO_userPhySel(unsigned int baseAddr, unsigned int phyinst,
                     unsigned int val)
{
    HWREG(baseAddr + CSL_MDIO_USER_PHY_SEL_REG(0) + (phyinst * 8)) = val;
}

/**
* @brief Function to enable the MDIO Link interrupt TODO Temp- PDK doesn't have this API
*
*       Used to enable MDIO Link Interrupt.
*
* @param mdioBaseAddress    [IN] MDIO Base Address
* @param phyInst            [IN] O/1 to select the User phy select option
* @param phyNum             [IN] Phy address of the port
* @param linkSel            [IN] Flag to select to use MDIO mode or MLINK mode
*
*  @retval none
*/
void MDIO_enableLinkInterrupt(uint32_t mdioBaseAddress, uint32_t phyInst,
                              uint32_t phyNum, uint8_t linkSel)
{
    uint32_t PhySel;

    PhySel = phyNum;
    PhySel |=  0x40;

    if(MDIO_LINKSEL_ENABLE == linkSel)
    {
        PhySel |= 0x80;
    }

    MDIO_userPhySel(mdioBaseAddress, phyInst, PhySel);
}

/**
 * \brief  Board specific configurations for ICSS  Ethernet PHYs
 *
 *  This function takes care of making several board level configurations
 *  required for ICSS EMAC PHY as listed below.
 *   - MDIO initialization
 *   - Setting the GPIOs for PHY reset, routing ICSS signals to PHYs,
 *     PHY interrupt lines.
 *   - Resetting the PHYs for proper address latching

 *
 * \return  none
 */
Board_STATUS Board_icssEthConfig(void);  /* for misra warning */
Board_STATUS Board_icssEthConfig(void)
{
    gpioPinObj_t PhyResetInfo[13];
    uint32_t i = 0;

    //BootConfigBusSwitch SYSBOOT7- active high
    PhyResetInfo[0].pinNum = 13;
    PhyResetInfo[0].instAddr = SOC_GPIO_2_REGS;

    //BootConfigMux - active high
    PhyResetInfo[1].pinNum = 19;
    PhyResetInfo[1].instAddr = SOC_GPIO_2_REGS;

    //phy1 reset - active high
    PhyResetInfo[2].pinNum = 13;
    PhyResetInfo[2].instAddr = SOC_GPIO_1_REGS;

    //phy 2 reset - active high
    PhyResetInfo[3].pinNum = 27;
    PhyResetInfo[3].instAddr = SOC_GPIO_0_REGS;

    //BootConfigFET - active high
    PhyResetInfo[4].pinNum = 18;
    PhyResetInfo[4].instAddr = SOC_GPIO_2_REGS;

    //ECAT fault - active low
    PhyResetInfo[5].pinNum = 20;
    PhyResetInfo[5].instAddr = SOC_GPIO_3_REGS;

    //ECAT run - active low
    PhyResetInfo[6].pinNum = 18;
    PhyResetInfo[6].instAddr = SOC_GPIO_3_REGS;

    //phy1 LED2  - active low
    PhyResetInfo[7].pinNum = 14;
    PhyResetInfo[7].instAddr = SOC_GPIO_1_REGS;

    //phy2 LED2  - active low
    PhyResetInfo[8].pinNum = 15;
    PhyResetInfo[8].instAddr = SOC_GPIO_1_REGS;

    //BootConfigBusSwitch SYSBOOT6- active low --not set
    PhyResetInfo[9].pinNum = 12;
    PhyResetInfo[9].instAddr = SOC_GPIO_2_REGS;

    //PHY1_LED1
    PhyResetInfo[10].pinNum = 8;
    PhyResetInfo[10].instAddr = SOC_GPIO_0_REGS;

    //PHY2_LED1
    PhyResetInfo[11].pinNum = 28;
    PhyResetInfo[11].instAddr = SOC_GPIO_1_REGS;

    //AM_PHY1_RXCK
    PhyResetInfo[12].pinNum = 10;
    PhyResetInfo[12].instAddr = SOC_GPIO_0_REGS;

    for(i=0; i<4; i++)
    {
        GPIOModuleEnable(PhyResetInfo[i].instAddr);
        GPIODirModeSet(PhyResetInfo[i].instAddr, PhyResetInfo[i].pinNum, GPIO_DIR_OUTPUT);

        GPIOPinWrite(PhyResetInfo[i].instAddr, PhyResetInfo[i].pinNum, GPIO_PIN_LOW);
        Board_delay(100);

        GPIOPinWrite(PhyResetInfo[i].instAddr, PhyResetInfo[i].pinNum, GPIO_PIN_HIGH);
        Board_delay(1000);
    }

    /* skip FET switch Info[4] until phy init and led1/rxclk1 is complete */

    for(i=5; i<9; i++)
    {
        GPIOModuleEnable(PhyResetInfo[i].instAddr);
        GPIODirModeSet(PhyResetInfo[i].instAddr, PhyResetInfo[i].pinNum, GPIO_DIR_OUTPUT);

        GPIOPinWrite(PhyResetInfo[i].instAddr, PhyResetInfo[i].pinNum, GPIO_PIN_LOW);
        Board_delay(1000);

    }

    CSL_MDIO_init(SOC_PRU_ICSS_MII_MDIO_REG, 200000000, 2200000u);
    Board_enablePhyAutoMDIX(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1);
    Board_enablePhyAutoMDIX(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2);
    uint16_t phyregval = 0;
    CSL_MDIO_phyRegRead(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1, TLKPHY_PHYCR_REG, &phyregval);
    phyregval |= TLKPHY_AUTOMDIX_ENABLE;
    CSL_MDIO_phyRegWrite(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1, TLKPHY_PHYCR_REG, phyregval);

    CSL_MDIO_phyRegRead(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2, TLKPHY_PHYCR_REG, &phyregval);
    phyregval |= TLKPHY_AUTOMDIX_ENABLE;
    CSL_MDIO_phyRegWrite(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2, TLKPHY_PHYCR_REG, phyregval);

    /* Turning OFF RMII mode and selecting MII mode */
    phyregval = 0;
    CSL_MDIO_phyRegWrite(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1, TLKPHY_RCSR_REG, phyregval);

    /* Turning OFF RMII mode and selecting MII mode */
    phyregval = 0;
    CSL_MDIO_phyRegWrite(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2, TLKPHY_RCSR_REG, phyregval);

    /* bsp_ethphy_init */
    Board_phyMLEDConfig(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1, PHY_MLED_100);
    Board_phyMLEDConfig(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2, PHY_MLED_100);
    while(!Board_getPhyIdentifyStat(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1))
    {
        continue;
    }

    while(!Board_getPhyIdentifyStat(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2))
    {
        continue;
    }
    //SWSCR2
    //Bit2: Enable RXERR during IDLE detection
    //Bit1: Disable detection of transmit error in odd-nibble boundary for odd nibble insertion)
    //Bit5: Force Full-Duplex while working with link partner in forced 100B-TX. When the
    //PHY is set to Auto-Negotiation or Force 100B-TX and the link partner is operated
    //in Force 100B-TX, the link is always Full Duplex
    //For EtherCAT : Disable enhanced LED link function

    Board_phyExtFDEnable(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1);
    Board_phyExtFDEnable(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2);
    Board_phyODDNibbleDetEnable(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1);
    Board_phyODDNibbleDetEnable(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2);
    Board_phyRxErrIdleEnable(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1);
    Board_phyRxErrIdleEnable(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2);

    //Enable enhanced link detection in TLK110 for EtherCAT
    //Bit3: Drop the link based on RX Error count of the MII interface, when a predefined number
    // of 32 RX Error occurrences in a 10us interval is reached, the link will be dropped
    // Bit0: Drop the link based on Signal/Energy loss indication, when the Energy detector
    //indicates Energy Loss, the link will be dropped. Typical reaction time is 10us.
    Board_phyLedConfig(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1, LED_CFG_MODE1);
    Board_phyLedConfig(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2, LED_CFG_MODE1);
    Board_phyLedBlinkConfig(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1, LED_BLINK_200);
    Board_phyLedBlinkConfig(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2, LED_BLINK_200);

    Board_phyFastLinkDownDetEnable(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1,
                                   FAST_LINKDOWN_SIGENERGY | FAST_LINKDOWN_RXERR);
    Board_phyFastLinkDownDetEnable(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2,
                                   FAST_LINKDOWN_SIGENERGY | FAST_LINKDOWN_RXERR);

    Board_phyLED1Config(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1, LED_CFG_MODE1);
    Board_phyLED1Config(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2, LED_CFG_MODE1);

    Board_getAutoNegStat(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1);
    Board_getAutoNegStat(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2);

    Board_phyAutoNegAdvConfig(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY1);
    Board_phyAutoNegAdvConfig(SOC_PRU_ICSS_MII_MDIO_REG, AMIC110_PHY2);

    /* per Paul's comment */
    GPIODirModeSet(PhyResetInfo[10].instAddr, PhyResetInfo[10].pinNum, GPIO_DIR_INPUT);
    GPIODirModeSet(PhyResetInfo[12].instAddr, PhyResetInfo[12].pinNum, GPIO_DIR_INPUT);

    GPIOModuleEnable(PhyResetInfo[4].instAddr);
    GPIODirModeSet(PhyResetInfo[4].instAddr, PhyResetInfo[4].pinNum, GPIO_DIR_OUTPUT);

    GPIOPinWrite(PhyResetInfo[4].instAddr, PhyResetInfo[4].pinNum, GPIO_PIN_LOW);
    Board_delay(100);

    GPIOPinWrite(PhyResetInfo[4].instAddr, PhyResetInfo[4].pinNum, GPIO_PIN_HIGH);
    Board_delay(1000);
    /* end bsp_ethphy_init */

    MDIO_enableLinkInterrupt(SOC_PRU_ICSS_MII_MDIO_REG, 0, AMIC110_PHY1, MDIO_LINKSEL_ENABLE);
    MDIO_enableLinkInterrupt(SOC_PRU_ICSS_MII_MDIO_REG, 1, AMIC110_PHY2, MDIO_LINKSEL_ENABLE);
 
    return BOARD_SOK;
}

