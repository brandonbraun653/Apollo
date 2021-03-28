/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *   \file  board_ethernet_config.c
 *
 *   \brief
 *      This file contains the Ethernet PHY configurations for AM65xx IDK
 *
 */


#include "board_internal.h"
#include "board_cfg.h"
#include <ti/csl/soc.h>
#include <ti/csl/cslr_mdio.h>

extern pruicssMdioInfo  gPruicssMdioInfo[BOARD_ICSS_EMAC_PORT_MAX];

/**
 * \brief  Function to initialize MDIO
 *
 * \param   baseAddr [IN]   MDIO base address
 *
 * \return  uint32_t
            TRUE     Read is successful.
 *          FALSE    Read is not acknowledged properly.
 */
static void Board_mdioInit(uint32_t baseAddr)
{
    HW_WR_REG32((baseAddr + 0x4), (CSL_FMKT(MDIO_CONTROL_REG_ENABLE, YES)  |
                CSL_FMK(MDIO_CONTROL_REG_CLKDIV,0xFF)));
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
static void Board_ethPhyRegWrite(uint32_t baseAddr, uint32_t phyAddr,
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
 * \brief  PHY register read function
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
static uint32_t BoardDiag_ethPhyRegRead(uint32_t baseAddr, uint32_t phyAddr,
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
 * \brief  Function to write extended address registers of Ethernet PHY
 *
 * \param   baseAddr [IN]    MDIO base address
 *          phyAddr  [IN]    Ethernet PHY address
 *          regNum   [IN]    PHY Register address
 *          pData    [OUT]   Values read from register
 *
 */
static void Board_ethPhyExtendedRegRead (uint32_t baseAddr,
                                         uint32_t phyAddr,
                                         uint32_t regNum,
                                         uint16_t *pData)
{
    Board_ethPhyRegWrite(baseAddr, phyAddr,
                         BOARD_ETHPHY_REGCR_REG_ADDR,
                         BOARD_ETHPHY_REGCR_ADDR_EN);
    Board_ethPhyRegWrite(baseAddr, phyAddr,
                         BOARD_ETHPHY_ADDAR_REG_ADDR, regNum);
    Board_ethPhyRegWrite(baseAddr, phyAddr,
                         BOARD_ETHPHY_REGCR_REG_ADDR,
                         BOARD_ETHPHY_REGCR_DATA_EN);
    BoardDiag_ethPhyRegRead(baseAddr, phyAddr,
                            BOARD_ETHPHY_ADDAR_REG_ADDR, pData);
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
static void Board_ethPhyExtendedRegWrite(uint32_t baseAddr,
                                         uint32_t phyAddr,
                                         uint32_t regNum,
                                         uint16_t regVal)
{
    Board_ethPhyRegWrite(baseAddr, phyAddr,
                         BOARD_ETHPHY_REGCR_REG_ADDR,
                         BOARD_ETHPHY_REGCR_ADDR_EN);
    Board_ethPhyRegWrite(baseAddr, phyAddr,
                         BOARD_ETHPHY_ADDAR_REG_ADDR, regNum);
    Board_ethPhyRegWrite(baseAddr, phyAddr,
                         BOARD_ETHPHY_REGCR_REG_ADDR,
                         BOARD_ETHPHY_REGCR_DATA_EN);
    Board_ethPhyRegWrite(baseAddr, phyAddr,
                         BOARD_ETHPHY_ADDAR_REG_ADDR, regVal);
}

/**
 * \brief  Function to set the Ethernet PHY speed
 *
 * This is internal function to the board library to configure the
 * Ethernet PHY speed
 *
 * \return  none
 */
static Board_STATUS Board_setEthPhySpeed(uint32_t baseAddr,
                                         uint32_t phyAddr,
                                         uint8_t speed)
{
    uint16_t regData = 0;

    Board_mdioInit(baseAddr);
    BoardDiag_ethPhyRegRead(baseAddr, phyAddr, 0, &regData);

    /* Reset the speed bits and disable the auto negotiation */
    regData &= ~(BOARD_ETH_PHY_SPEED_MASK | BOARD_ETH_PHY_AUTONEG_MASK);

    if(speed)
    {
        /* Set the speed to 1000mbps */
        regData |= BOARD_ETH_PHY_SPEED_1000MPBS;
    }
    else
    {
        /* Set the speed to 100mbps */
        regData |= BOARD_ETH_PHY_SPEED_100MPBS;
    }

    Board_ethPhyRegWrite(baseAddr, phyAddr, 0, regData);

    return (BOARD_SOK);
}

/**
 * \brief  Configures the CPSW Subsytem for RGMII mode
 *
 * \return  none
 */
static Board_STATUS Board_setupCpswSs(void)
{
    uint32_t status;
    uintptr_t rgmii_mode;
    uintptr_t kick0, kick1;

    /* Unlock KICK0 & KICK1 registers for Partition 0 */
    kick0 = CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0;
    kick1 = CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1;
    CSL_REG32_WR(kick0, KICK0_UNLOCK_VAL);
    CSL_REG32_WR(kick1, KICK1_UNLOCK_VAL);

    /* Configure CPSW2g in RGMII mode-  Info: 00 - GMII , 01 -RMII , 10 - RGMII , 11-SGMII  */
    rgmii_mode = CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_MCU_ENET_CTRL;
    CSL_REG32_WR( rgmii_mode , 0x00000002);
    status = CSL_REG32_RD( rgmii_mode);
    if (status != 0x00000002)
    {
        return BOARD_FAIL;
    }

    return BOARD_SOK;
}

/**
 * \brief  Configures NAVSS THREADMAP configurations
 *
 * ICSSG firmware uses MSMC RAM to create internal buffer pools. 
 * ICSSG must have high priority and deterministic access. 
 * To provide that NB0 NAVSS_THREADMAP register shall be set to 
 * use thread 2 (real-time traffic).
 *
 * \return  none
 */
static void Board_navssThreadmapConfig(void)
{
    HW_WR_REG32(BOARD_NAVSS0_NBSS_NB0_CFG_ADDR, 0x2);
}

/**
 * \brief  Board specific configurations for MCU Ethernet PHY
 *
 * This function takes care of configuring the internal delays for MCU gigabit
 * Ethernet PHY
 *
 * \return  none
 */
Board_STATUS Board_mcuEthConfig(void)
{
    uint32_t baseAddr;
    uint16_t regData = 0;
    Board_STATUS ret;
  
    baseAddr = (CSL_MCU_CPSW0_NUSS_BASE + 0x0F00);

    ret = Board_setupCpswSs();
    if(ret != BOARD_SOK)
    {
        return ret;
    }

    Board_mdioInit(baseAddr);

    /* Enable PHY speed LED functionality */
    Board_ethPhyExtendedRegRead(baseAddr, BOARD_MCU_EMAC_PHY_ADDR,
                                BOARD_ETHPHY_GPIO_MUX_CTRL2_REG_ADDR, &regData);
    regData  = (regData & ~0xF) | 0x6;
    Board_ethPhyExtendedRegWrite(baseAddr, BOARD_MCU_EMAC_PHY_ADDR,
                                 BOARD_ETHPHY_GPIO_MUX_CTRL2_REG_ADDR, regData);

    regData = 0;
    BoardDiag_ethPhyRegRead(baseAddr, BOARD_MCU_EMAC_PHY_ADDR,
                            BOARD_ETHPHY_LEDCR1_REG_ADDR, &regData);
    regData  = (regData & ~0xF000) | 0x8000;
    Board_ethPhyRegWrite(baseAddr, BOARD_MCU_EMAC_PHY_ADDR,
                         BOARD_ETHPHY_LEDCR1_REG_ADDR, regData);

    /* When the Phy is strapped to enable Fast Link Drop (FLD) feature,
     * the detect threshold value becomes 0x2 in bit 2:0 instead of 0x1
     * in the  FLD_THRESH (0x2e) register  as in non strapped case.
     * This causes the phy link to be unstable.
     * As a workaround, write a value of 0x1 in this bit field if
     * bit 10 of STRAP_STS2 (0x6f) register is set (enable FLD).
     */
     regData = 0;
     Board_ethPhyExtendedRegRead(baseAddr, BOARD_MCU_EMAC_PHY_ADDR,
                                 BOARD_ETHPHY_STRAP_STS2_REG_ADDR, &regData);
     if (regData & 0x0400)
     {
         regData = 0;
         Board_ethPhyExtendedRegRead(baseAddr, BOARD_MCU_EMAC_PHY_ADDR,
                                     BOARD_ETHPHY_FLD_THRESH_REG_ADDR,
                                     &regData);
         if (regData == 0x222)
         {
             regData &= ~0x7;
             Board_ethPhyExtendedRegWrite(baseAddr, BOARD_MCU_EMAC_PHY_ADDR,
                                          BOARD_ETHPHY_FLD_THRESH_REG_ADDR,
                                          (regData | 0x1));
         }
     }

    /* Setting the PHY TX and RX delay configurations */
    Board_ethPhyExtendedRegRead(baseAddr, BOARD_MCU_EMAC_PHY_ADDR,
                                BOARD_ETHPHY_RGMIICTL_REG_ADDR, &regData);
    /* Disable Tx delay and enable Rx delay */
    regData &= ~(BOARD_ETHPHY_RGMIICTL_CLKDELAY_MASK);
    regData |= BOARD_ETHPHY_RGMIICTL_RXDELAY_EN;
    Board_ethPhyExtendedRegWrite(baseAddr, BOARD_MCU_EMAC_PHY_ADDR,
                                 BOARD_ETHPHY_RGMIICTL_REG_ADDR, regData);

    /* No Tx delay and 2ns Rx delay */
    Board_ethPhyExtendedRegWrite(baseAddr, BOARD_MCU_EMAC_PHY_ADDR,
                                 BOARD_ETHPHY_RGMIIDCTL_REG_ADDR, 0x07);

    return BOARD_SOK;
}

/**
 * \brief  Board specific configurations for ICSS EMAC Ethernet PHYs
 *
 * This function takes care of configuring the internal delays for ICSS 
 * Ethernet PHY
 *
 * \return  none
 */
Board_STATUS Board_icssEthConfig(void)
{
    uint32_t baseAddr;
    uint8_t  phyAddr;
    uint32_t index;
    uint16_t regData = 0;

    Board_unlockMMR();

    for(index = 0; index < BOARD_ICSS_EMAC_PORT_MAX; index++)
    {
        baseAddr = gPruicssMdioInfo[index].mdioBaseAddrs;
        phyAddr  = gPruicssMdioInfo[index].phyAddrs;
     
        Board_mdioInit(baseAddr);

        /* Enable PHY speed LED functionality */
        Board_ethPhyExtendedRegRead(baseAddr, phyAddr,
                                    BOARD_ETHPHY_GPIO_MUX_CTRL2_REG_ADDR, &regData);
        regData  = (regData & ~0xF) | 0x6;
        Board_ethPhyExtendedRegWrite(baseAddr, phyAddr,
                                     BOARD_ETHPHY_GPIO_MUX_CTRL2_REG_ADDR, regData);

        regData = 0;
        BoardDiag_ethPhyRegRead(baseAddr, phyAddr,
                                BOARD_ETHPHY_LEDCR1_REG_ADDR, &regData);
        regData  = (regData & ~0xF000) | 0x8000;
        Board_ethPhyRegWrite(baseAddr, phyAddr,
                             BOARD_ETHPHY_LEDCR1_REG_ADDR, regData);

       /* When the Phy is strapped to enable Fast Link Drop (FLD) feature,
        * the detect threshold value becomes 0x2 in bit 2:0 instead of 0x1
        * in the  FLD_THRESH (0x2e) register  as in non strapped case.
        * This causes the phy link to be unstable.
        * As a workaround, write a value of 0x1 in this bit field if
        * bit 10 of STRAP_STS2 (0x6f) register is set (enable FLD).
        */
        regData = 0;
        Board_ethPhyExtendedRegRead(baseAddr, phyAddr,
                                    BOARD_ETHPHY_STRAP_STS2_REG_ADDR, &regData);
        if (regData & 0x0400)
        {
            regData = 0;
            Board_ethPhyExtendedRegRead(baseAddr, phyAddr,
                                        BOARD_ETHPHY_FLD_THRESH_REG_ADDR,
                                        &regData);
            if (regData == 0x222)
            {
                regData &= ~0x7;
                Board_ethPhyExtendedRegWrite(baseAddr, phyAddr,
                                             BOARD_ETHPHY_FLD_THRESH_REG_ADDR,
                                             (regData | 0x1));
            }
        }

        /* Setting the PHY TX and RX delay configurations */
        Board_ethPhyExtendedRegRead(baseAddr, phyAddr,
                                    BOARD_ETHPHY_RGMIICTL_REG_ADDR, &regData);
        /* Disable Tx delay and enable Rx delay */
        regData &= ~(BOARD_ETHPHY_RGMIICTL_CLKDELAY_MASK);
        regData |= BOARD_ETHPHY_RGMIICTL_RXDELAY_EN;
        Board_ethPhyExtendedRegWrite(baseAddr, phyAddr,
                                     BOARD_ETHPHY_RGMIICTL_REG_ADDR, regData);

        /* No Tx delay and 2ns Rx delay */
        Board_ethPhyExtendedRegWrite(baseAddr, phyAddr,
                                     BOARD_ETHPHY_RGMIIDCTL_REG_ADDR, 0x07);

        Board_ethPhyExtendedRegRead(baseAddr, phyAddr, 0x32, &regData);
        regData |= 0x18; //Set Bits 4:3 to 3
        Board_ethPhyExtendedRegWrite(baseAddr, phyAddr, 0x32, regData);
    }


    Board_navssThreadmapConfig();

	return BOARD_SOK;
}

/**
 * \brief  Function to configure the Ethernet PHY speed
 *
 * This function takes care of configuring the speed of the
 * Ethernet ports connected to MCU and ICSSG MAC ports.
 *
 * Below are the ports supported on AM65xx boards
 *
 * ICSS0 PRU 0  - port 0
 * ICSS0 PRU 1  - port 1
 * ICSS1 PRU 0  - port 2
 * ICSS1 PRU 1  - port 3
 * ICSS2 PRU 0  - port 4
 * ICSS2 PRU 1  - port 5
 * MCU Ethernet - port 6
 * port 0 to 3 are not valid for AM65xx EVM
 *
 * \param   port [IN]    Ethernet PHY Port number (check above table)
 * \param   speed [IN]   Speed selection
 *                       0 -  100 mpbs
 *                       1 -  1000 mpbs
 *
 * \return  none
 */
Board_STATUS Board_ethPhySpeedConfig(int8_t port, uint8_t speed)
{
    Board_STATUS status = BOARD_SOK;
    uint32_t baseAddr;
    uint32_t phyAddr;

    if(port == BOARD_MCU_ETH_PORT)
    {
        baseAddr = (CSL_MCU_CPSW0_NUSS_BASE + 0x0F00);
        phyAddr  = BOARD_MCU_EMAC_PHY_ADDR;
    }
    else
    {
        if((port >= BOARD_ICSS_EMAC_PORT_START) &&
           (port <= BOARD_ICSS_EMAC_PORT_END))
        {
            port -= BOARD_ICSS_EMAC_PORT_START;
            baseAddr = gPruicssMdioInfo[port].mdioBaseAddrs;
            phyAddr  = gPruicssMdioInfo[port].phyAddrs;
        }
        else
        {
            return (BOARD_INVALID_PARAM);
        }
    }

    status = Board_setEthPhySpeed(baseAddr, phyAddr, speed);

    return (status);
}
