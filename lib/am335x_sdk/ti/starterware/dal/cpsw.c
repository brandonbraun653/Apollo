/**
 *  \file   cpsw.c
 *
 *  \brief  This file contains the device abstraction layer API implementation
 *          corresponding to CPSW subsystem.
 *
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <math.h>
#include "types.h"
#include "hw_types.h"
#include "error.h"
#include "hw_cpsw_ale.h"
#include "hw_cpsw_cpdma.h"
#include "hw_cpsw_cpdma_stateram.h"
#include "hw_cpsw_port.h"
#include "hw_cpsw_sl.h"
#include "hw_cpsw_ss.h"
#include "hw_cpsw_wr.h"
#include "ethernet.h"
#include "cpsw.h"
#include "hw_mdio.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* TODO: This sub-module offset has to be auto-generated. This will be removed
         later. */

/** \brief CPSW Sub-system register offset. */
#define CPSW_SS                 (0x0000U)

/** \brief CPSW Port sub module register offset. */
#define CPSW_PORT               (0x0100U)

/** \brief CPSW CPDMA sub module register offset. */
#define CPSW_CPDMA              (0x0800U)

/** \brief CPSW Statistics sub module register offset. */
#define CPSW_STATS              (0x0900U)

/** \brief CPSW CPDMA state RAM sub module register offset. */
#define CPSW_CPDMA_STATERAM     (0x0A00U)

/** \brief CPSW CPTS sub module register offset. */
#define CPSW_CPTS               (0x0C00U)

/** \brief CPSW port Sliver sub module register offset. */
#define CPSW_SL(slavePort)      (0x0D80U + (0x40U * (slavePort)))

/** \brief CPSW MDIO sub module register offset. */
#define CPSW_MDIO               (0x1000U)

/** \brief CPSW Wrapper sub module register offset. */
#define CPSW_WR                 (0x1200U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void CPSWReset(uint32_t baseAddr, uint32_t noOfPort)
{
    uint32_t cnt = 0U;

    for(cnt = 1U; cnt <= noOfPort; cnt++)
    {
        CPSWSlReset(baseAddr, cnt);
    }

    CPSWCpdmaReset(baseAddr);
    CPSWWrReset(baseAddr);
    CPSWSsReset(baseAddr);
}

void CPSWSsReset(uint32_t baseAddr)
{
    /* Reset the subsystem. */
    HW_WR_FIELD32((baseAddr + CPSW_SS + CPSW_SS_SOFT_RESET),
        CPSW_SS_SOFT_RESET, CPSW_SS_SOFT_RESET_IN_PROGRESS);

    /* Wait till the reset completes */
    while(CPSW_SS_SOFT_RESET_IN_PROGRESS ==
        HW_RD_FIELD32((baseAddr + CPSW_SS + CPSW_SS_SOFT_RESET),
        CPSW_SS_SOFT_RESET));
}

void CPSWSlReset(uint32_t baseAddr, uint32_t slavePortNum)
{
    /* Reset the sliver. */
    HW_WR_FIELD32((baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_SOFT_RESET),
        CPSW_SL_SOFT_RESET, CPSW_SL_SOFT_RESET_IN_PROGRESS);

    /* Wait till the reset completes */
    while(CPSW_SL_SOFT_RESET_IN_PROGRESS ==
        HW_RD_FIELD32((baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_SOFT_RESET),
        CPSW_SL_SOFT_RESET));
}

void CPSWWrReset(uint32_t baseAddr)
{
    /* Reset the wrapper. */
    HW_WR_FIELD32((baseAddr + CPSW_WR + CPSW_WR_SOFT_RESET),
        CPSW_WR_SOFT_RESET, CPSW_WR_SOFT_RESET_IN_PROGRESS);

    /* Wait till the reset completes */
    while(CPSW_WR_SOFT_RESET_IN_PROGRESS ==
        HW_RD_FIELD32((baseAddr + CPSW_WR + CPSW_WR_SOFT_RESET),
        CPSW_WR_SOFT_RESET));
}

void CPSWCpdmaReset(uint32_t baseAddr)
{
    /* Reset the CPDMA */
    HW_WR_FIELD32((baseAddr + CPSW_CPDMA + CPSW_CPDMA_SOFT_RESET),
        CPSW_CPDMA_SOFT_RESET, CPSW_CPDMA_SOFT_RESET_EN_0x1);

    /* Wait till the reset completes */
    while(CPSW_CPDMA_SOFT_RESET_EN_0x1 ==
        HW_RD_FIELD32((baseAddr + CPSW_CPDMA + CPSW_CPDMA_SOFT_RESET),
        CPSW_CPDMA_SOFT_RESET));
}

void CPSWSlForceExtGigbitMode(uint32_t baseAddr,
                              uint32_t slavePortNum,
                              uint32_t forceGigMode)
{
    if(TRUE == forceGigMode)
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_GIG_FORCE, CPSW_SL_MACCTRL_GIG_FORCE_ENABLE);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_GIG_FORCE, CPSW_SL_MACCTRL_GIG_FORCE_DISABLE);
    }
}

void CPSWSlCtrlInbandEnable(uint32_t baseAddr,
                            uint32_t slavePortNum,
                            uint32_t enableInband)
{
    if(TRUE == enableInband)
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_EXT_EN, CPSW_SL_MACCTRL_EXT_EN_ENABLE);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_EXT_EN, CPSW_SL_MACCTRL_EXT_EN_DISABLE);
    }
}

void CPSWSlGigModeEnable(uint32_t baseAddr,
                         uint32_t slavePortNum,
                         uint32_t enableGigMode)
{
    if(TRUE == enableGigMode)
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_GIG, CPSW_SL_MACCTRL_GIG_ENABLE);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_GIG, CPSW_SL_MACCTRL_GIG_DISABLE);
    }
}

void CPSWSlSetDuplexMode(uint32_t baseAddr,
                         uint32_t slavePortNum,
                         uint32_t duplexMode)
{
    if(ETHERNET_DUPLEX_MODE_FULL == duplexMode)
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_FULLDUPLEX, CPSW_SL_MACCTRL_FULLDUPLEX_ENABLE);
    }
    else if(ETHERNET_DUPLEX_MODE_HALF == duplexMode)
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_FULLDUPLEX, CPSW_SL_MACCTRL_FULLDUPLEX_DISABLE);
    }
    else
    {
        /* This error does not happen because of check done already */
    }
}

void CPSWSlGmiiEnable(uint32_t baseAddr,
                      uint32_t slavePortNum,
                      uint32_t enableGmii)
{
    if(TRUE == enableGmii)
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_GMII_EN, CPSW_SL_MACCTRL_GMII_EN_ENABLE);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_GMII_EN, CPSW_SL_MACCTRL_GMII_EN_DISABLE);
    }
}

void CPSWSetSlRmiiSpeed(uint32_t baseAddr,
                        uint32_t slavePortNum,
                        uint32_t rmiiSpeed)
{
    if(ETHERNET_SPEED_10 == rmiiSpeed)
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_IFCTL_A, CPSW_SL_MACCTRL_IFCTL_A_10);
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_IFCTL_B, CPSW_SL_MACCTRL_IFCTL_B_10);
    }
    else if(ETHERNET_SPEED_100 == rmiiSpeed)
    {
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_IFCTL_A, CPSW_SL_MACCTRL_IFCTL_A_100);
        HW_WR_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACCTRL,
            CPSW_SL_MACCTRL_IFCTL_B, CPSW_SL_MACCTRL_IFCTL_B_100);
    }
    else
    {
        /* This error does not happen because of check done already */
    }
}

uint32_t CPSWSlIsExtSpeedGigabit(uint32_t baseAddr, uint32_t slavePortNum)
{
    return (HW_RD_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACSTS, CPSW_SL_MACSTS_EXT_GIG));
}

uint32_t CPSWSlIsExtFullDuplex(uint32_t baseAddr, uint32_t slavePortNum)
{
    return (HW_RD_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACSTS,
        CPSW_SL_MACSTS_EXT_FULLDUPLEX));
}

uint32_t CPSWSlIsMacIdle(uint32_t baseAddr, uint32_t slavePortNum)
{
    return (HW_RD_FIELD32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_MACSTS,
        CPSW_SL_MACSTS_IDLE));
}

void CPSWSetSlRxMaxLen(uint32_t baseAddr,
                       uint32_t slavePortNum,
                       uint32_t rxMaxLen)
{
    if(CPSW_MAX_PACKET_LEN >= rxMaxLen)
    {
        HW_WR_REG32(baseAddr + CPSW_SL(slavePortNum - 1U) + CPSW_SL_RX_MAXLEN,
            rxMaxLen);
    }
}

void CPSWWrChIntrEnable(uint32_t baseAddr,
                        uint32_t intrCore,
                        uint32_t chNum,
                        uint32_t chIntrMask)
{
    uint32_t regVal = 0U;

    if(CPSW_CH_INTR_RX_THR == (chIntrMask & CPSW_CH_INTR_RX_THR))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_C_RX_THRESH_EN(intrCore));
        regVal |= (1U << chNum);
        HW_WR_REG32(baseAddr + CPSW_WR + CPSW_WR_C_RX_THRESH_EN(intrCore), regVal);
    }

    if(CPSW_CH_INTR_RX == (chIntrMask & CPSW_CH_INTR_RX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_C_RX_EN(intrCore));
        regVal |= (1U << chNum);
        HW_WR_REG32(baseAddr + CPSW_WR + CPSW_WR_C_RX_EN(intrCore), regVal);
    }

    if(CPSW_CH_INTR_TX == (chIntrMask & CPSW_CH_INTR_TX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_C_TX_EN(intrCore));
        regVal |= (1U << chNum);
        HW_WR_REG32(baseAddr + CPSW_WR + CPSW_WR_C_TX_EN(intrCore), regVal);
    }
}

void CPSWWrMiscIntrEnable(uint32_t baseAddr,
                          uint32_t intrCore,
                          uint32_t miscIntrMask)
{
    uint32_t regFieldVal = 0U;

    regFieldVal = HW_GET_FIELD(baseAddr + CPSW_WR + CPSW_WR_C_MISC_EN(intrCore),
        CPSW_WR_C_MISC_EN);
    regFieldVal |= miscIntrMask;
    HW_WR_FIELD32(baseAddr + CPSW_WR + CPSW_WR_C_MISC_EN(intrCore),
        CPSW_WR_C_MISC_EN,
        regFieldVal);
}

void CPSWWrChIntrDisable(uint32_t baseAddr,
                         uint32_t intrCore,
                         uint32_t chNum,
                         uint32_t chIntrMask)
{
    uint32_t regVal = 0U;

    if(CPSW_CH_INTR_RX_THR == (chIntrMask & CPSW_CH_INTR_RX_THR))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_C_RX_THRESH_EN(intrCore));
        regVal &= ~(1U << chNum);
        HW_WR_REG32(baseAddr + CPSW_WR + CPSW_WR_C_RX_THRESH_EN(intrCore), regVal);
    }

    if(CPSW_CH_INTR_RX == (chIntrMask & CPSW_CH_INTR_RX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_C_RX_EN(intrCore));
        regVal &= ~(1U << chNum);
        HW_WR_REG32(baseAddr + CPSW_WR + CPSW_WR_C_RX_EN(intrCore), regVal);
    }

    if(CPSW_CH_INTR_TX == (chIntrMask & CPSW_CH_INTR_TX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_C_TX_EN(intrCore));
        regVal &= ~(1U << chNum);
        HW_WR_REG32(baseAddr + CPSW_WR + CPSW_WR_C_TX_EN(intrCore), regVal);
    }
}

void CPSWWrMiscIntrDisable(uint32_t baseAddr,
                           uint32_t intrCore,
                           uint32_t miscIntrMask)
{
    uint32_t regFieldVal = 0U;

    regFieldVal = HW_GET_FIELD(baseAddr + CPSW_WR + CPSW_WR_C_MISC_EN(intrCore),
        CPSW_WR_C_MISC_EN);
    regFieldVal &= ~miscIntrMask;
    HW_WR_FIELD32(baseAddr + CPSW_WR + CPSW_WR_C_MISC_EN(intrCore),
        CPSW_WR_C_MISC_EN,
        regFieldVal);
}

uint32_t CPSWWrchIntrStatus(uint32_t baseAddr,
                            uint32_t intrCore,
                            uint32_t chIntr)
{
    return (HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_C_MISC_STAT(intrCore) +
        4U * chIntr));
}

uint32_t CPSWWrMiscIntrStatus(uint32_t baseAddr, uint32_t intrCore)
{
    return (HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_C_MISC_STAT(intrCore)));
}

uint32_t CPSWGetWrRgmiiInbandSpeed(uint32_t baseAddr, uint32_t slavePortNum)
{
    return (((HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_RGMII_CTL) >> \
        (4U * (slavePortNum - 1U) + 3U))) &
        CPSW_WR_RGMII_CTL_RGMII1_SPEED_MASK);
}

uint32_t CPSWGetWrRgmiiInbandDuplexMode(uint32_t baseAddr, uint32_t slavePortNum)
{
    return (((HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_RGMII_CTL) >>
        (4U * (slavePortNum - 1U) + 3U))) &
        CPSW_WR_RGMII_CTL_RGMII1_FULLDUPLEX_MASK);
}

uint32_t CPSWWrRgmiiInbandLinkStatus(uint32_t baseAddr, uint32_t slavePortNum)
{
    return (((HW_RD_REG32(baseAddr + CPSW_WR + CPSW_WR_RGMII_CTL) >>
        4U * (slavePortNum - 1U))) &
        CPSW_WR_RGMII_CTL_RGMII1_LINK_MASK);
}

void CPSWSsRxFlowCtrlEnable(uint32_t baseAddr,
                            uint32_t portNum,
                            uint32_t enableRxFlowCtrl)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + CPSW_SS + CPSW_SS_FLOW_CTRL);

    if(TRUE == enableRxFlowCtrl)
    {
        regVal |= (1U << portNum);
    }
    else
    {
        regVal &= ~(1U << portNum);
    }

    HW_WR_REG32(baseAddr + CPSW_SS + CPSW_SS_FLOW_CTRL, regVal);
}

void CPSWSsSwIdleEnable(uint32_t baseAddr, uint32_t enableSwIdle)
{
    if(TRUE == enableSwIdle)
    {
        HW_WR_FIELD32((baseAddr + CPSW_SS + CPSW_SS_SOFT_IDLE),
            CPSW_SS_SOFT_IDLE, CPSW_SS_SOFT_IDLE_EN_0x1);
    }
    else
    {
        HW_WR_FIELD32((baseAddr + CPSW_SS + CPSW_SS_SOFT_IDLE),
            CPSW_SS_SOFT_IDLE, CPSW_SS_SOFT_IDLE_EN_0x0);
    }
}

void CPSWSsStatsEnable(uint32_t baseAddr,
                       uint32_t portNum,
                       uint32_t enableStats)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + CPSW_SS + CPSW_SS_STAT_PORT_EN);

    if(TRUE == enableStats)
    {
        regVal |= (1U << portNum);
    }
    else
    {
        regVal &= ~(1U << portNum);
    }

    HW_WR_REG32(baseAddr + CPSW_SS + CPSW_SS_STAT_PORT_EN, regVal);
}

void CPSWSsVlanAwareEnable(uint32_t baseAddr, uint32_t enableVlanAware)
{
    if(TRUE == enableVlanAware)
    {
        HW_WR_FIELD32((baseAddr + CPSW_SS + CPSW_SS_CTRL),
            CPSW_SS_CTRL_VLAN_AWARE, CPSW_SS_CTRL_VLAN_AWARE_EN_0x1);
    }
    else
    {
        HW_WR_FIELD32((baseAddr + CPSW_SS + CPSW_SS_CTRL),
            CPSW_SS_CTRL_VLAN_AWARE, CPSW_SS_CTRL_VLAN_AWARE_EN_0x0);
    }
}

void CPSWSetPortSrcAddr(uint32_t baseAddr,
                        uint32_t slavePortNum,
                        uint8_t *pMacAddr)
{
    HW_WR_REG32((baseAddr + CPSW_PORT + CPSW_PORT_P_SA_HI(slavePortNum)),
        pMacAddr[0]
        | (pMacAddr[1] << CPSW_PORT_P_SA_HI_MACSRCADDR_39_32_SHIFT)
        | (pMacAddr[2] << CPSW_PORT_P_SA_HI_MACSRCADDR_31_24_SHIFT)
        | (pMacAddr[3] << CPSW_PORT_P_SA_HI_MACSRCADDR_23_16_SHIFT));

    HW_WR_REG32((baseAddr + CPSW_PORT + CPSW_PORT_P_SA_LO(slavePortNum)),
        pMacAddr[4]
        | (pMacAddr[5] << CPSW_PORT_P_SA_LO_MACSRCADDR_7_0_SHIFT));
}

void CPSWHostPortDualMacModeEnable(uint32_t baseAddr,
                                   uint32_t enableDualMacMode)
{
    HW_WR_FIELD32((baseAddr + CPSW_PORT + CPSW_PORT_P_TX_IN_CTL(0U)),
        CPSW_PORT_P_TX_IN_CTL_SEL, CPSW_PORT_P_TX_IN_CTL_SEL_EN_0x1);
}

void CPSWPortVlanConfig(uint32_t baseAddr,
                        uint32_t portNum,
                        uint32_t vlanId,
                        uint32_t cfiBit,
                        uint32_t vlanPri)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + CPSW_PORT + CPSW_PORT_P_VLAN(portNum));
    HW_SET_FIELD(regVal, CPSW_PORT_P_VLAN_CFI, cfiBit);
    HW_SET_FIELD(regVal, CPSW_PORT_P_VLAN_PRI, vlanPri);
    HW_SET_FIELD(regVal, CPSW_PORT_P_VLAN_VID, vlanId);
    HW_WR_REG32(baseAddr + CPSW_PORT + CPSW_PORT_P_VLAN(portNum), regVal);
}

void CPSWCpdmaChIntrEnable(uint32_t baseAddr,
                           uint32_t chNum,
                           uint32_t chIntrMask)
{
    uint32_t regVal = 0U;

    if(CPSW_CH_INTR_RX == (chIntrMask & CPSW_CH_INTR_RX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTMASK_SET);
        regVal |= (1U << chNum);
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTMASK_SET, regVal);
    }

    if(CPSW_CH_INTR_RX_THR == (chIntrMask & CPSW_CH_INTR_RX_THR))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTMASK_SET);
        regVal |= (1 << (chNum + 0x8U));
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTMASK_SET, regVal);
    }

    if(CPSW_CH_INTR_TX == (chIntrMask & CPSW_CH_INTR_TX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_TX_INTMASK_SET);
        regVal |= (1U << chNum);
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_TX_INTMASK_SET, regVal);
    }
}

void CPSWCpdmaChIntrDisable(uint32_t baseAddr,
                            uint32_t chNum,
                            uint32_t chIntrMask)
{
    uint32_t regVal = 0U;

    if(CPSW_CH_INTR_RX == (chIntrMask & CPSW_CH_INTR_RX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTMASK_CLR);
        regVal |= (1U << chNum);
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTMASK_CLR, regVal);
    }

    if(CPSW_CH_INTR_RX_THR == (chIntrMask & CPSW_CH_INTR_RX_THR))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMA_INTMASK_CLR);
        regVal |= (1 << (chNum + 0x8U));
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMA_INTMASK_CLR, regVal);
    }

    if(CPSW_CH_INTR_TX == (chIntrMask & CPSW_CH_INTR_TX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_TX_INTMASK_CLR);
        regVal |= (1U << chNum);
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_TX_INTMASK_CLR, regVal);
    }
}

void CPSWCpdmaXferEnable(uint32_t baseAddr, uint32_t xferMode)
{
    if(ETHERNET_XFER_MODE_RX == xferMode)
    {
        HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_CTRL,
            CPSW_CPDMA_RX_CTRL_EN, CPSW_CPDMA_RX_CTRL_EN_EN_0x1);
    }
    else if(ETHERNET_XFER_MODE_TX == xferMode)
    {
        HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_TX_CTRL,
            CPSW_CPDMA_TX_CTRL_EN, CPSW_CPDMA_TX_CTRL_EN_EN_0x1);
    }
    else
    {
        /* This error does not happen because of check done already */
    }
}

void CPSWCpdmaXferDisable(uint32_t baseAddr, uint32_t xferMode)
{
    if(ETHERNET_XFER_MODE_RX == xferMode)
    {
        HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_CTRL,
            CPSW_CPDMA_RX_CTRL_EN, CPSW_CPDMA_RX_CTRL_EN_EN_0x0);
    }
    else if(ETHERNET_XFER_MODE_TX == xferMode)
    {
        HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_CTRL,
            CPSW_CPDMA_TX_CTRL_EN, CPSW_CPDMA_TX_CTRL_EN_EN_0x0);
    }
    else
    {
        /* This error does not happen because of check done already */
    }
}

void CPSWCpdmaXferHdrDescPtrWrite(uint32_t baseAddr,
                                  uint32_t xferMode,
                                  uint32_t descHdr,
                                  uint32_t chNum)
{
    if(ETHERNET_XFER_MODE_RX == xferMode)
    {
        HW_WR_REG32(baseAddr + CPSW_CPDMA_STATERAM + CPSW_CPDMA_STATERAM_RX_HDP(chNum),
            descHdr);
    }
    else if(ETHERNET_XFER_MODE_TX == xferMode)
    {
        HW_WR_REG32(baseAddr + CPSW_CPDMA_STATERAM + CPSW_CPDMA_STATERAM_TX_HDP(chNum),
            descHdr);
    }
    else
    {
        /* This error does not happen because of check done already */
    }
}

void CPSWCpdmaXferCpWrite(uint32_t baseAddr,
                          uint32_t xferMode,
                          uint32_t chNum,
                          uint32_t comPtr)
{
    if(ETHERNET_XFER_MODE_RX == xferMode)
    {
        HW_WR_REG32(baseAddr + CPSW_CPDMA_STATERAM + CPSW_CPDMA_STATERAM_RX_CP(chNum),
            comPtr);
    }
    else if(ETHERNET_XFER_MODE_TX == xferMode)
    {
        HW_WR_REG32(baseAddr + CPSW_CPDMA_STATERAM + CPSW_CPDMA_STATERAM_TX_CP(chNum),
            comPtr);
    }
    else
    {
        /* This error does not happen because of check done already */
    }
}

void CPSWCpdmaWriteEoiVector(uint32_t baseAddr, uint32_t intrLine)
{
    if(CPSW_WR_INTR_LINE_RX == intrLine)
    {
        HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_EOI_VECTOR,
            CPSW_CPDMA_EOI_VECTOR_DMA, 0x01U);
    }
    else if(CPSW_WR_INTR_LINE_RX_THR == intrLine)
    {
        HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_EOI_VECTOR,
            CPSW_CPDMA_EOI_VECTOR_DMA, 0x00U);
    }
    else if(CPSW_WR_INTR_LINE_TX == intrLine)
    {
        HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_EOI_VECTOR,
            CPSW_CPDMA_EOI_VECTOR_DMA, 0x02U);
    }
    else if(CPSW_WR_INTR_LINE_MISC == intrLine)
    {
        HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_EOI_VECTOR,
            CPSW_CPDMA_EOI_VECTOR_DMA, 0x03U);
    }
    else
    {
        /* This error does not happen because of check done already */
    }
}

void CPSWSetCpdmaNumFreeBuf(uint32_t baseAddr,
                            uint32_t chNum,
                            uint32_t numFreeBuf)
{
    HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_FREEBUFFER(chNum),
        numFreeBuf);
}

uint32_t CPSWIsCpdmaIdle(uint32_t baseAddr)
{
    return (HW_RD_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMASTS,
        CPSW_CPDMA_DMASTS_IDLE));
}

uint32_t CPSWGetCpdmaHostErrorCode(uint32_t baseAddr, uint32_t xferMode)
{
    uint32_t regVal = 0U;

    if(ETHERNET_XFER_MODE_RX == xferMode)
    {
        regVal = HW_RD_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMASTS,
            CPSW_CPDMA_DMASTS_RX_HOST_ERR_CODE);
    }
    else if(ETHERNET_XFER_MODE_TX == xferMode)
    {
        regVal = HW_RD_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMASTS,
            CPSW_CPDMA_DMASTS_TX_HOST_ERR_CODE);
    }
    else
    {
        /* This error does not happen because of check done already */
    }

    return regVal;
}

uint32_t CPSWGetCpdmaHostErrorCh(uint32_t baseAddr, uint32_t xferMode)
{
    uint32_t regVal = 0U;

    if(ETHERNET_XFER_MODE_RX == xferMode)
    {
        regVal = HW_RD_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMASTS,
            CPSW_CPDMA_DMASTS_RX_ERR_CH);
    }
    else if(ETHERNET_XFER_MODE_TX == xferMode)
    {
        regVal = HW_RD_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMASTS,
            CPSW_CPDMA_DMASTS_TX_ERR_CH);
    }
    else
    {
        /* This error does not happen because of check done already */
    }

    return regVal;
}

void CPSWCpdmaTxRateLimitChBusConfig(uint32_t baseAddr, uint32_t rateLimitChBus)
{
    HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMACTRL,
        CPSW_CPDMA_DMACTRL_TX_RLIM, rateLimitChBus);
}

void CPSWCpdmaIdleEnable(uint32_t baseAddr, uint32_t enableCpdmaIdle)
{
    if(TRUE == enableCpdmaIdle)
    {
        /* Enable command idle for CPDMA. */
        HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMACTRL,
            CPSW_CPDMA_DMACTRL_CMD_IDLE, CPSW_CPDMA_DMASTS_IDLE_EN_0x1);

        /* Wait till the state changes to idle */
        while(CPSW_CPDMA_DMASTS_IDLE_EN_0x1 ==
            HW_RD_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMASTS,
            CPSW_CPDMA_DMASTS_IDLE));
    }
    else
    {
        HW_WR_FIELD32((baseAddr + CPSW_CPDMA + CPSW_CPDMA_DMACTRL),
            CPSW_CPDMA_DMACTRL_CMD_IDLE, CPSW_CPDMA_DMACTRL_CMD_IDLE_DISABLE);
    }
}

void CPSWSetCpdmaRxBufOffset(uint32_t baseAddr, uint32_t bufOffset)
{
    HW_WR_FIELD32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_BUFFER_OFFSET,
        CPSW_CPDMA_RX_BUFFER_OFFSET, bufOffset);
}

uint32_t CPSWCpdmachIntrStatus(uint32_t baseAddr, uint32_t chIntr)
{
    uint32_t regVal = 0U;
    uint32_t retVal = 0U;

    if(CPSW_CH_INTR_RX == (chIntr & CPSW_CH_INTR_RX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTSTAT_MASKED);
        retVal = regVal & (0xFFU);
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTSTAT_MASKED, regVal);
    }
    else if(CPSW_CH_INTR_RX_THR == (chIntr & CPSW_CH_INTR_RX_THR))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTSTAT_MASKED);
        regVal = (regVal >> 8U);
        retVal = regVal & (0xFFU);
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTSTAT_MASKED, regVal);
    }
    else if(CPSW_CH_INTR_TX == (chIntr & CPSW_CH_INTR_TX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_TX_INTSTAT_MASKED);
        retVal = regVal & (0xFFU);
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_TX_INTSTAT_MASKED, regVal);
    }
    else
    {
        /* This error does not happen because of check done already */
    }

    return retVal;
}

void CPSWCpdmaChIntrRawStatus(uint32_t baseAddr, uint32_t chIntr)
{
    uint32_t regVal = 0U;

    if(CPSW_CH_INTR_RX == (chIntr & CPSW_CH_INTR_RX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTSTAT_RAW);
        regVal &= (0xFFU);
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTSTAT_RAW, regVal);
    }
    else if(CPSW_CH_INTR_RX_THR == (chIntr & CPSW_CH_INTR_RX_THR))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTSTAT_RAW);
        regVal = (regVal >> 0x8U);
        regVal &= (0xFFU);
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_RX_INTSTAT_RAW, regVal);
    }
    else if(CPSW_CH_INTR_TX == (chIntr & CPSW_CH_INTR_TX))
    {
        regVal = HW_RD_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_TX_INTSTAT_RAW);
        regVal &= (0xFFU);
        HW_WR_REG32(baseAddr + CPSW_CPDMA + CPSW_CPDMA_TX_INTSTAT_RAW, regVal);
    }
    else
    {
        /* This error does not happen because of check done already */
    }
}

void CPSWMdioPhyRegRead(uint32_t baseAddr,
                        uint32_t phyAddr,
                        uint32_t regNum,
                        uint16_t *pData)
{
    uint32_t regVal = 0U;

    /* Wait till transaction completion if any */
    while(MDIO_USERACCESS_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + CPSW_MDIO + MDIO_USERACCESS(0U),
        MDIO_USERACCESS_GO));

    HW_SET_FIELD(regVal, MDIO_USERACCESS_GO, MDIO_USERACCESS_GO_EN_0x1);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_WRITE, MDIO_USERACCESS_READ);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_PHYADR, phyAddr);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_REGADR, regNum);
    HW_WR_REG32(baseAddr + CPSW_MDIO + MDIO_USERACCESS(0U), regVal);

    /* wait for command completion */
    while(MDIO_USERACCESS_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + CPSW_MDIO + MDIO_USERACCESS(0U),
        MDIO_USERACCESS_GO));

    /* Store the data if the read is acknowledged */
    if(MDIO_USERACCESS_ACK_PASS ==
        HW_RD_FIELD32(baseAddr + CPSW_MDIO + MDIO_USERACCESS(0U),
        MDIO_USERACCESS_ACK))
    {
        *pData = (uint16_t)(HW_RD_FIELD32(baseAddr + CPSW_MDIO +
            MDIO_USERACCESS(0U), MDIO_USERACCESS_DATA));
    }
}

void CPSWMdioPhyRegWrite(uint32_t baseAddr,
                         uint32_t phyAddr,
                         uint32_t regNum,
                         uint16_t wrVal)
{
    uint32_t regVal = 0U;

    /* Wait till transaction completion if any */
    while(MDIO_USERACCESS_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + CPSW_MDIO + MDIO_USERACCESS(0U),
        MDIO_USERACCESS_GO));

    HW_SET_FIELD(regVal, MDIO_USERACCESS_GO, MDIO_USERACCESS_GO_EN_0x1);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_WRITE, MDIO_USERACCESS_WRITE);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_PHYADR, phyAddr);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_REGADR, regNum);
    HW_SET_FIELD(regVal, MDIO_USERACCESS_DATA, wrVal);
    HW_WR_REG32(baseAddr + CPSW_MDIO + MDIO_USERACCESS(0U), regVal);

    /* wait for command completion */
    while(MDIO_USERACCESS_GO_EN_0x1 ==
        HW_RD_FIELD32(baseAddr + CPSW_MDIO + MDIO_USERACCESS(0U),
        MDIO_USERACCESS_GO));
}

uint32_t CPSWMdioPhyAliveStatus(uint32_t baseAddr, uint32_t phyAddr)
{
    uint32_t retVal = FALSE;

    if(0U != (HW_RD_REG32(baseAddr + CPSW_MDIO + MDIO_ALIVE) &
        (1U << phyAddr)))
    {
        retVal =  TRUE;
    }

    return retVal;
}

uint32_t CPSWMdioPhyLinkStatus(uint32_t baseAddr, uint32_t phyAddr)
{
    uint32_t retVal = FALSE;

    if(0U != (HW_RD_REG32(baseAddr + CPSW_MDIO + MDIO_LINK) &
        (1U << phyAddr)))
    {
        retVal =  TRUE;
    }

    return retVal;
}

void CPSWMdioInit(uint32_t baseAddr,
                  uint32_t mdioInputFreq,
                  uint32_t mdioOutputFreq)
{
    uint32_t clkDiv = (mdioInputFreq/mdioOutputFreq) - 1U;
    uint32_t regVal = 0U;

    HW_SET_FIELD(regVal, MDIO_CTRL_EN, MDIO_CTRL_EN_0X1);
    HW_SET_FIELD(regVal,  MDIO_CTRL_PREAMBLE, MDIO_CTRL_PREAMBLE_EN_0X1);
    HW_SET_FIELD(regVal, MDIO_CTRL_FAULTENB, MDIO_CTRL_FAULTENB_EN_0X1);
    HW_SET_FIELD(regVal, MDIO_CTRL_CLKDIV, clkDiv);
    HW_WR_REG32(baseAddr + CPSW_MDIO + MDIO_CTRL, regVal);
}

/* ========================================================================== */
/*                          Deprecated Function Definitions                   */
/* ========================================================================== */

