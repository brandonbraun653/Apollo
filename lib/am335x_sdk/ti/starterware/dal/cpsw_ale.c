/**
 *  \file   cpsw_ale.c
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

#include "types.h"
#include "hw_types.h"
#include "hw_cpsw_ale.h"
#include "ethernet.h"
#include "cpsw_ale.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#define CPSW_ALE_TBLW1_ENTRY_TYPE_MASK                     (0x30000000U)
#define CPSW_ALE_TBLW1_ENTRY_TYPE_SHIFT                    (28U)
#define CPSW_ALE_TBLW1_ENTRY_VLAN_ID_MASK                  (0x0FFF0000U)
#define CPSW_ALE_TBLW1_ENTRY_VLAN_ID_SHIFT                 (16U)

/** \brief Multicast MAC address upper byte mask. */
#define CPSW_ALE_TBLW0_VLAN_MEMBER_LIST_MASK               (0x00000007U)
#define CPSW_ALE_TBLW0_VLAN_MEMBER_LIST_SHIFT              (0U)
#define CPSW_ALE_TBLW0_VLAN_UNREG_MCAST_FLOOD_MASK_MASK    (0x00000700U)
#define CPSW_ALE_TBLW0_VLAN_UNREG_MCAST_FLOOD_MASK_SHIFT   (8U)
#define CPSW_ALE_TBLW0_VLAN_REG_MCAST_FLOOD_MASK_MASK      (0x00070000U)
#define CPSW_ALE_TBLW0_VLAN_REG_MCAST_FLOOD_MASK_SHIFT     (16U)
#define CPSW_ALE_TBLW0_VLAN_FORCE_UNTAGGED_EGRESS_MASK     (0x07000000U)
#define CPSW_ALE_TBLW0_VLAN_FORCE_UNTAGGED_EGRESS_SHIFT    (24U)

/** \brief Multicast MAC address upper byte mask. */
#define CPSW_ALE_TBLW0_UNI_ADDR_31_0_MASK                  (0xFFFFFFFFU)
#define CPSW_ALE_TBLW0_UNI_ADDR_31_0_SHIFT                 (0U)
#define CPSW_ALE_TBLW1_UNI_ADDR_47_32_MASK                 (0x0000FFFFU)
#define CPSW_ALE_TBLW1_UNI_ADDR_47_32_SHIFT                (0U)
#define CPSW_ALE_TBLW1_UNI_ADDR_VLAN_ID_MASK               (0x0FFF0000U)
#define CPSW_ALE_TBLW1_UNI_ADDR_VLAN_ID_SHIFT              (16U)
#define CPSW_ALE_TBLW1_UNI_ADDR_TYPE_MASK                  (0xC0000000U)
#define CPSW_ALE_TBLW1_UNI_ADDR_TYPE_SHIFT                 (30U)
#define CPSW_ALE_TBLW2_UNI_ADDR_SECURE_MASK                (0x00000001U)
#define CPSW_ALE_TBLW2_UNI_ADDR_SECURE_SHIFT               (0U)
#define CPSW_ALE_TBLW2_UNI_ADDR_SECURE_ENABLE               (1U)
#define CPSW_ALE_TBLW2_UNI_ADDR_SECURE_DISABLE              (0U)
#define CPSW_ALE_TBLW2_UNI_ADDR_BLOCK_MASK                 (0x00000002U)
#define CPSW_ALE_TBLW2_UNI_ADDR_BLOCK_SHIFT                (1U)
#define CPSW_ALE_TBLW2_UNI_ADDR_BLOCK_ENABLE                (1U)
#define CPSW_ALE_TBLW2_UNI_ADDR_BLOCK_DISABLE               (0U)
#define CPSW_ALE_TBLW2_UNI_ADDR_PORT_NUM_MASK              (0x0000000CU)
#define CPSW_ALE_TBLW2_UNI_ADDR_PORT_NUM_SHIFT             (2U)
#define CPSW_ALE_TBLW2_UNI_ADDR_DLR_MASK                   (0x00000020U)
#define CPSW_ALE_TBLW2_UNI_ADDR_DLR_SHIFT                  (5U)
#define CPSW_ALE_TBLW2_UNI_ADDR_DLR_ENABLE                  (1U)
#define CPSW_ALE_TBLW2_UNI_ADDR_DLR_DISABLE                 (0U)

/** \brief Multicast MAC address upper byte mask. */
#define CPSW_ALE_TBLW0_MULTI_ADDR_31_0_MASK                (0xFFFFFFFFU)
#define CPSW_ALE_TBLW0_MULTI_ADDR_31_0_SHIFT               (0U)
#define CPSW_ALE_TBLW1_MULTI_ADDR_47_32_MASK               (0x0000FFFFU)
#define CPSW_ALE_TBLW1_MULTI_ADDR_47_32_SHIFT              (0U)
#define CPSW_ALE_TBLW1_MULTI_ADDR_FWD_STATE_MASK           (0xC0000000U)
#define CPSW_ALE_TBLW1_MULTI_ADDR_FWD_STATE_SHIFT          (30U)
#define CPSW_ALE_TBLW2_MULTI_ADDR_SUPER_MASK               (0x00000002U)
#define CPSW_ALE_TBLW2_MULTI_ADDR_SUPER_SHIFT              (1U)
#define CPSW_ALE_TBLW2_MULTI_ADDR_SUPER_ENABLE              (1U)
#define CPSW_ALE_TBLW2_MULTI_ADDR_SUPER_DISABLE             (0U)
#define CPSW_ALE_TBLW2_MULTI_ADDR_PORT_MASK_MASK           (0x0000001CU)
#define CPSW_ALE_TBLW2_MULTI_ADDR_PORT_MASK_SHIFT          (2U)

/* TODO: This sub-module offset has to be auto-generated. This will be removed
         later. */

/** \brief CPSW ALE sub module register offset. */
#define CPSW_ALE                (0x0D00U)

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

void CPSWAleInit(uint32_t baseAddr)
{
    CPSWAleEnable(baseAddr, TRUE);
    CPSWAleClearTable(baseAddr);
}

void CPSWAleEnable(uint32_t baseAddr, uint32_t enableAle)
{
    if(TRUE == enableAle)
    {
        /* Enable address lookup engine. */
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL), CPSW_ALE_CTRL_EN,
            CPSW_ALE_CTRL_EN_ENABLE);
    }
    else
    {
        /* Disable address lookup engine. */
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL), CPSW_ALE_CTRL_EN,
            CPSW_ALE_CTRL_EN_DISABLE);
    }
}

void CPSWAleClearTable(uint32_t baseAddr)
{
    /* Clear address lookup engine table. */
    HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL), CPSW_ALE_CTRL_CLR_TBL,
        CPSW_ALE_CTRL_CLR_TBL_IN_PROGRESS);

    /*
     * Wait till the lookup engine table is cleared. Access to all ALE registers
     * will be blocked (wait states) until the 64 clocks have completed.
     */
    while(CPSW_ALE_CTRL_CLR_TBL_IN_PROGRESS ==
        HW_RD_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
        CPSW_ALE_CTRL_CLR_TBL));
}

void CPSWAleAgeOut(uint32_t baseAddr)
{
    /* Enable age out of address lookup engine table. */
    HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
        CPSW_ALE_CTRL_AGE_OUT_NOW, CPSW_ALE_CTRL_AGE_OUT_NOW_IN_PROGRESS);

    /*
     * Wait till the untouched entries are aged out in lookup engine table.
     * The age out process takes 4096 clocks best case (no ale packet processing
     * during ageout) and 66550 clocks absolute worst case.
     */
    while(CPSW_ALE_CTRL_AGE_OUT_NOW_IN_PROGRESS ==
        HW_RD_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
        CPSW_ALE_CTRL_AGE_OUT_NOW));
}

void CPSWAleSetRateLimit(uint32_t baseAddr,
                         uint32_t portNum,
                         uint32_t pktType,
                         uint32_t pktRateLimit)
{
    if(ETHERNET_ADDR_TYPE_BROADCAST == pktType)
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_PORTCTL(portNum)),
            CPSW_ALE_PORTCTL_BCAST_LIMIT, pktRateLimit);
    }
    else if(ETHERNET_ADDR_TYPE_MULTICAST == pktType)
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_PORTCTL(portNum)),
            CPSW_ALE_PORTCTL_MCAST_LIMIT, pktRateLimit);
    }
    else
    {
        /* This error does not happen because of check done already */
    }
}

void CPSWAleVlanIdIngressCheckEnable(uint32_t baseAddr,
                                     uint32_t portNum,
                                     uint32_t enableIngressCheck)
{
    if(TRUE == enableIngressCheck)
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_PORTCTL(portNum)),
            CPSW_ALE_PORTCTL_VID_INGRESS_CHECK,
            CPSW_ALE_PORTCTL_VID_INGRESS_CHECK_EN_0x1);
    }
    else
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_PORTCTL(portNum)),
            CPSW_ALE_PORTCTL_VID_INGRESS_CHECK,
            CPSW_ALE_PORTCTL_VID_INGRESS_CHECK_EN_0x0);
    }
}

void CPSWAleSetPortState(uint32_t baseAddr,
                         uint32_t portNum,
                         uint32_t portState)
{
    HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_PORTCTL(portNum)),
        CPSW_ALE_PORTCTL_PORT_STATE, portState);
}

void CPSWAleVlanAwareEnable(uint32_t baseAddr, uint32_t enableVlanAware)
{
    if(TRUE == enableVlanAware)
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
            CPSW_ALE_CTRL_VLAN_AWARE, CPSW_ALE_CTRL_VLAN_AWARE_ENA_0x1);
    }
    else
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
            CPSW_ALE_CTRL_VLAN_AWARE, CPSW_ALE_CTRL_VLAN_AWARE_ENA_0x0);
    }
}

void CPSWAleRateLimitEnable(uint32_t baseAddr, uint32_t xferMode)
{
    HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
        CPSW_ALE_CTRL_EN_RATE_LIMIT, CPSW_ALE_CTRL_EN_RATE_LIMIT_ENA_0x1);

    if(ETHERNET_XFER_MODE_TX == xferMode)
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
            CPSW_ALE_CTRL_RATE_LIMIT_TX, CPSW_ALE_CTRL_RATE_LIMIT_TX_ENA_0x1);
    }
    else if(ETHERNET_XFER_MODE_RX == xferMode)
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
            CPSW_ALE_CTRL_RATE_LIMIT_TX, CPSW_ALE_CTRL_RATE_LIMIT_TX_ENA_0x0);
    }
    else
    {
        /* This error does not happen because of check done already */
    }
}

void CPSWAleRateLimitDisable(uint32_t baseAddr)
{
    HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
        CPSW_ALE_CTRL_EN_RATE_LIMIT, CPSW_ALE_CTRL_EN_RATE_LIMIT_ENA_0x0);
}

void CPSWAleAuthModeEnable(uint32_t baseAddr, uint32_t enableMacAuth)
{
    if(TRUE == enableMacAuth)
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
            CPSW_ALE_CTRL_EN_AUTH_MODE, CPSW_ALE_CTRL_EN_AUTH_MODE_ENABLE);
    }
    else
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
            CPSW_ALE_CTRL_EN_AUTH_MODE, CPSW_ALE_CTRL_EN_AUTH_MODE_DISABLE);
    }
}

void CPSWAleBypassEnable(uint32_t baseAddr, uint32_t enableBypass)
{
    if(TRUE == enableBypass)
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
            CPSW_ALE_CTRL_BYPASS, CPSW_ALE_CTRL_BYPASS_ENABLE);
    }
    else
    {
        HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_CTRL),
            CPSW_ALE_CTRL_BYPASS, CPSW_ALE_CTRL_BYPASS_DISABLE);
    }
}

void CPSWAleSetTableEntry(uint32_t baseAddr,
                          uint32_t aleTblIdx,
                          uint32_t *pAleEntryPtr)
{
    uint32_t cnt = 0U;
    uint32_t regVal = 0U;

    for (cnt = 0U; cnt < 3U; cnt++)
    {
        HW_WR_REG32(baseAddr + CPSW_ALE + CPSW_ALE_TBLW(cnt),
        *(pAleEntryPtr + cnt));
    }

    HW_SET_FIELD(regVal, CPSW_ALE_TBLCTL_ENTRY_POINTER, aleTblIdx);
    HW_SET_FIELD(regVal, CPSW_ALE_TBLCTL_WRITE_RDZ,
        CPSW_ALE_TBLCTL_WRITE_RDZ_EN_0x1);
    HW_WR_REG32(baseAddr + CPSW_ALE + CPSW_ALE_TBLCTL, regVal);
}

void CPSWAleGetTableEntry(uint32_t baseAddr,
                          uint32_t aleTblIdx,
                          uint32_t *pAleEntryPtr)
{
    uint32_t cnt = 0U;

    HW_WR_REG32(baseAddr + CPSW_ALE + CPSW_ALE_TBLCTL, aleTblIdx);

    for (cnt = 0U; cnt < 3U; cnt++)
    {
        *(pAleEntryPtr + cnt) =
            HW_RD_REG32(baseAddr + CPSW_ALE + CPSW_ALE_TBLW(cnt));
    }
}

uint32_t CPSWGetAleRateLimitPrescale(uint32_t baseAddr)
{
    return (HW_RD_FIELD32(baseAddr + CPSW_ALE + CPSW_ALE_PRESCALE, CPSW_ALE_PRESCALE));
}

void CPSWAleSetRateLimitPrescale(uint32_t baseAddr, uint32_t preScalarVal)
{
    HW_WR_FIELD32((baseAddr + CPSW_ALE + CPSW_ALE_PRESCALE),
        CPSW_ALE_PRESCALE, preScalarVal);
}

uint32_t CPSWAleValidateMacAddr(uint8_t *pMacAddr, uint32_t addrType)
{
    uint32_t cnt = 0U;
    uint32_t retVal = FALSE;

    for (cnt = 0U; cnt < ETHERNET_MAC_ADDR_LEN; cnt++)
    {
        if (CPSW_ALE_BROADCAST_MAC_ADDR_MASK !=
            (pMacAddr[cnt] & CPSW_ALE_BROADCAST_MAC_ADDR_MASK))
        {
            break;
        }
    }

    if ((ETHERNET_MAC_ADDR_LEN == cnt) && (ETHERNET_ADDR_TYPE_BROADCAST == addrType))
    {
        retVal = TRUE;
    }
    else if (ETHERNET_MAC_ADDR_LEN == cnt)
    {
        retVal = FALSE;
    }
    else if (ETHERNET_ADDR_TYPE_BROADCAST == addrType)
    {
        retVal = FALSE;
    }
    else
    {
        if (ETHERNET_ADDR_TYPE_MULTICAST == addrType)
        {
            if (CPSW_ALE_MULTICAST_MAC_ADDR_MASK ==
                (pMacAddr[0U] & CPSW_ALE_MULTICAST_MAC_ADDR_MASK))
            {
                retVal = TRUE;
            }
        }
        else if (ETHERNET_ADDR_TYPE_UNICAST == addrType)
        {
            if (CPSW_ALE_MULTICAST_MAC_ADDR_MASK !=
                (pMacAddr[0U] & CPSW_ALE_MULTICAST_MAC_ADDR_MASK))
            {
                retVal = TRUE;
            }
        }
        else
        {
        }
    }
    return retVal;
}

uint32_t CPSWAleGetFreeEntry(uint32_t baseAddr)
{
    uint32_t aleEntry[CPSW_ALE_ENTRY_NUM_WORDS];
    uint32_t idx = CPSW_ALE_ENTRY_MAX;
    uint32_t retVal = CPSW_ALE_ENTRY_MAX;

    /* Check which ALE entry is free starting from 0th entry */
    for (idx = 0U; idx < CPSW_ALE_ENTRY_MAX; idx++)
    {
        CPSWAleGetTableEntry(baseAddr, idx, aleEntry);

        /* Break if the table entry is free */
        if (CPSW_ALE_TBL_ENTRY_TYPE_FREE == HW_GET_FIELD(aleEntry[1U],
            CPSW_ALE_TBLW1_ENTRY_TYPE))
        {
            retVal = idx;
            break;
        }
    }

  return retVal;
}

uint32_t CPSWAleGetUntouchEntry(uint32_t baseAddr)
{
    uint32_t aleEntry[CPSW_ALE_ENTRY_NUM_WORDS];
    uint32_t entryType = 0U;
    uint32_t idx = CPSW_ALE_ENTRY_MAX;
    uint32_t retVal = CPSW_ALE_ENTRY_MAX;

    /* Check which ALE entry is free starting from 0th entry */
    for (idx = 0U; idx < CPSW_ALE_ENTRY_MAX; idx++)
    {
        CPSWAleGetTableEntry(baseAddr, idx, aleEntry);

        entryType = HW_GET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE);

        /* Goto next entry if the ale entry is not valid address */
        if ((CPSW_ALE_TBL_ENTRY_TYPE_FREE != entryType) &&
            (CPSW_ALE_TBL_ENTRY_TYPE_VLAN != entryType))
        {
            if (TRUE == CPSWAleValidateMacAddr((uint8_t *)aleEntry,
                ETHERNET_ADDR_TYPE_UNICAST))
            {
                entryType = HW_GET_FIELD(aleEntry[1U],
                    CPSW_ALE_TBLW1_UNI_ADDR_TYPE);

                if (CPSW_ALE_TBL_UNICAST_TYPE_AGEABLE_UNTOUCH == entryType)
                {
                    retVal = idx;
                    break;
                }
            }
       }
    }

    return retVal;
}

uint32_t CPSWAleGetAddrEntry(uint32_t baseAddr,
                             uint8_t *pMacAddr,
                             uint32_t vlanId)
{
    uint32_t aleEntry[CPSW_ALE_ENTRY_NUM_WORDS];
    uint32_t entryType = 0U;
    uint32_t idx = CPSW_ALE_ENTRY_MAX, cnt = 0U;
    uint32_t retVal = CPSW_ALE_ENTRY_MAX;

    /* Check which ALE entry is free starting from 0th entry */
    for (idx = 0U; ((idx < CPSW_ALE_ENTRY_MAX) && (CPSW_ALE_ENTRY_MAX == retVal)); idx++)
    {
        CPSWAleGetTableEntry(baseAddr, idx, aleEntry);

        entryType = HW_GET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE);

        /* Goto next entry if the ale entry is not valid address */
        if ((CPSW_ALE_TBL_ENTRY_TYPE_FREE != entryType) &&
            (CPSW_ALE_TBL_ENTRY_TYPE_VLAN != entryType))
        {
            if (HW_GET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_VLAN_ID) == vlanId)
            {
                for (cnt = 0U; cnt < ETHERNET_MAC_ADDR_LEN; cnt++)
                {
                    if (*(((uint8_t *)aleEntry) + cnt) !=
                        pMacAddr[ETHERNET_MAC_ADDR_LEN - cnt -1])
                    {
                        break;
                    }
                    else if (ETHERNET_MAC_ADDR_LEN == (cnt + 1))
                    {
                        retVal = idx;
                    }
                    else
                    {
                    }
                }
            }
        }
    }

    return retVal;
}

uint32_t CPSWAleGetVlanEntry(uint32_t baseAddr, uint32_t vlanId)
{
    uint32_t aleEntry[CPSW_ALE_ENTRY_NUM_WORDS];
    uint32_t entryType = 0U;
    uint32_t idx = CPSW_ALE_ENTRY_MAX;
    uint32_t retVal = CPSW_ALE_ENTRY_MAX;

    /* Check which ALE entry is free starting from 0th entry */
    for (idx = 0; idx < CPSW_ALE_ENTRY_MAX; idx++)
    {
        CPSWAleGetTableEntry(baseAddr, idx, aleEntry);

        entryType = HW_GET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE);

        /* Goto next entry if the ale entry is not valid vlan */
        if (CPSW_ALE_TBL_ENTRY_TYPE_VLAN == entryType)
        {
            if (HW_GET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_VLAN_ID) == vlanId)
            {
                retVal = idx;
            }
        }
    }

    return retVal;
}

uint32_t CPSWAleUnicastEntryAdd(uint32_t baseAddr,
                                 uint8_t *pMacAddr,
                                 uint32_t vlanId,
                                 uint32_t portNum,
                                 cpswAleUcastConfigParams_t unicastParams)
{
    uint32_t aleEntry[CPSW_ALE_ENTRY_NUM_WORDS] = {0U, 0U, 0U};
    uint32_t cnt = 0U;
    uint32_t idx = CPSW_ALE_ENTRY_MAX;
    uint32_t retVal = CPSW_ALE_ENTRY_MAX;

    if (TRUE == CPSWAleValidateMacAddr(pMacAddr, ETHERNET_ADDR_TYPE_UNICAST))
    {
        idx = CPSWAleGetAddrEntry(baseAddr, pMacAddr, vlanId);
        if (CPSW_ALE_ENTRY_MAX == idx)
        {
            idx = CPSWAleGetFreeEntry(baseAddr);
            if (CPSW_ALE_ENTRY_MAX == idx)
            {
                idx = CPSWAleGetUntouchEntry(baseAddr);
            }
        }
        else
        {
            CPSWAleGetTableEntry(baseAddr, idx, aleEntry);
        }
    }

    if (CPSW_ALE_ENTRY_MAX != idx)
    {
        retVal = idx;

        if(0U == vlanId)
        {
            HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE,
                CPSW_ALE_TBL_ENTRY_TYPE_ADDR);
            HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_VLAN_ID,
                0U);
        }
        else
        {
            HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE,
                CPSW_ALE_TBL_ENTRY_TYPE_VLAN_ADDR);
            HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_VLAN_ID,
                vlanId);
        }

        HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_UNI_ADDR_TYPE,
            unicastParams.unicastType);

        for(cnt = 0U; cnt < ETHERNET_MAC_ADDR_LEN; cnt++)
        {
            *(((uint8_t *)aleEntry) + cnt) =
                pMacAddr[ETHERNET_MAC_ADDR_LEN - cnt - 1U];
        }

        HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_UNI_ADDR_PORT_NUM, portNum);

        if(TRUE == unicastParams.enableSecure)
        {
            HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_UNI_ADDR_SECURE,
                CPSW_ALE_TBLW2_UNI_ADDR_SECURE_ENABLE);
        }
        else
        {
            HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_UNI_ADDR_SECURE,
                CPSW_ALE_TBLW2_UNI_ADDR_SECURE_DISABLE);
        }

        if(TRUE == unicastParams.enableBlock)
        {
            HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_UNI_ADDR_BLOCK,
                CPSW_ALE_TBLW2_UNI_ADDR_BLOCK_ENABLE);
        }
        else
        {
            HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_UNI_ADDR_BLOCK,
                CPSW_ALE_TBLW2_UNI_ADDR_BLOCK_DISABLE);
        }

        if(TRUE == unicastParams.enableDlr)
        {
            HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_UNI_ADDR_DLR,
                CPSW_ALE_TBLW2_UNI_ADDR_DLR_ENABLE);
        }
        else
        {
            HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_UNI_ADDR_DLR,
                CPSW_ALE_TBLW2_UNI_ADDR_DLR_DISABLE);
        }

        CPSWAleSetTableEntry(baseAddr, idx, aleEntry);
    }

    return retVal;
}

uint32_t CPSWAleUnicastEntryDel(uint32_t baseAddr,
                             uint8_t *pMacAddr,
                             uint32_t vlanId,
                             uint32_t portNum)
{
    uint32_t aleEntry[CPSW_ALE_ENTRY_NUM_WORDS] = {0U, 0U, 0U};
    uint32_t idx = CPSW_ALE_ENTRY_MAX;
    uint32_t retVal = CPSW_ALE_ENTRY_MAX;

    if (TRUE == CPSWAleValidateMacAddr(pMacAddr, ETHERNET_ADDR_TYPE_UNICAST))
    {
        idx = CPSWAleGetAddrEntry(baseAddr, pMacAddr, vlanId);

        while(CPSW_ALE_ENTRY_MAX != idx)
        {
            CPSWAleGetTableEntry(baseAddr, idx, aleEntry);

            if(portNum == HW_GET_FIELD(aleEntry[1U],
                CPSW_ALE_TBLW2_UNI_ADDR_PORT_NUM))
            {
                break;
            }
            idx = CPSWAleGetAddrEntry(baseAddr, pMacAddr, vlanId);
        }
    }

    if(CPSW_ALE_ENTRY_MAX != idx)
    {
        HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE,
            CPSW_ALE_TBL_ENTRY_TYPE_FREE);
        CPSWAleSetTableEntry(baseAddr, idx, aleEntry);
        retVal = idx;
    }

    return retVal;
}

uint32_t CPSWAleMulticastEntryPortAdd(uint32_t baseAddr,
                                   uint8_t *pMacAddr,
                                   uint32_t vlanId,
                                   uint32_t portNum,
                                   cpswAleMcastConfigParams_t multicastParams)
{
    uint32_t aleEntry[CPSW_ALE_ENTRY_NUM_WORDS] = {0U, 0U, 0U};
    uint32_t cnt = 0U;
    uint32_t idx = CPSW_ALE_ENTRY_MAX;
    uint32_t regFieldVal = 0U;
    uint32_t retVal = CPSW_ALE_ENTRY_MAX;

    if ((TRUE == CPSWAleValidateMacAddr(pMacAddr, ETHERNET_ADDR_TYPE_MULTICAST))
        || (TRUE == CPSWAleValidateMacAddr(pMacAddr, ETHERNET_ADDR_TYPE_BROADCAST)))
    {
        idx = CPSWAleGetAddrEntry(baseAddr, pMacAddr, vlanId);
        if (CPSW_ALE_ENTRY_MAX == idx)
        {
            idx = CPSWAleGetFreeEntry(baseAddr);
            if (CPSW_ALE_ENTRY_MAX == idx)
            {
                idx = CPSWAleGetUntouchEntry(baseAddr);
            }
        }
        else
        {
            CPSWAleGetTableEntry(baseAddr, idx, aleEntry);
        }
    }

    if (CPSW_ALE_ENTRY_MAX != idx)
    {
        CPSWAleGetTableEntry(baseAddr, idx, aleEntry);
        retVal = idx;

        if(0U == vlanId)
        {
            HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE,
                CPSW_ALE_TBL_ENTRY_TYPE_ADDR);
            HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_VLAN_ID,
                0U);
        }
        else
        {
            HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE,
                CPSW_ALE_TBL_ENTRY_TYPE_VLAN_ADDR);
            HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_VLAN_ID,
                vlanId);
        }

        for(cnt = 0U; cnt < ETHERNET_MAC_ADDR_LEN; cnt++)
        {
            *(((uint8_t *)aleEntry) + cnt) = pMacAddr[ETHERNET_MAC_ADDR_LEN - cnt - 1U];
        }

        regFieldVal = HW_GET_FIELD(aleEntry[2U],
            CPSW_ALE_TBLW2_MULTI_ADDR_PORT_MASK);
        regFieldVal |= (1U << portNum);
        HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_MULTI_ADDR_PORT_MASK,
            regFieldVal);

        HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_MULTI_ADDR_FWD_STATE,
            multicastParams.fwdState);

        if(TRUE == multicastParams.enableSuper)
        {
            HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_MULTI_ADDR_SUPER,
                CPSW_ALE_TBLW2_MULTI_ADDR_SUPER_ENABLE);
        }
        else
        {
            HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_MULTI_ADDR_SUPER,
                CPSW_ALE_TBLW2_MULTI_ADDR_SUPER_DISABLE);
        }

        CPSWAleSetTableEntry(baseAddr, idx, aleEntry);
    }

    return retVal;
}

uint32_t CPSWAleMulticastEntryPortDel(uint32_t baseAddr,
                                   uint8_t *pMacAddr,
                                   uint32_t vlanId,
                                   uint32_t portNum)
{
    uint32_t aleEntry[CPSW_ALE_ENTRY_NUM_WORDS] = {0U, 0U, 0U};
    uint32_t idx = CPSW_ALE_ENTRY_MAX;
    uint32_t regFieldVal = 0U;
    uint32_t retVal = CPSW_ALE_ENTRY_MAX;

    if (TRUE == CPSWAleValidateMacAddr(pMacAddr, ETHERNET_ADDR_TYPE_MULTICAST))
    {
        idx = CPSWAleGetAddrEntry(baseAddr, pMacAddr, vlanId);
    }

    if(CPSW_ALE_ENTRY_MAX != idx)
    {
        CPSWAleGetTableEntry(baseAddr, idx, aleEntry);

        regFieldVal = HW_GET_FIELD(aleEntry[2U],
            CPSW_ALE_TBLW2_MULTI_ADDR_PORT_MASK);
        regFieldVal &= ~(1U << portNum);

        if(0U == regFieldVal)
        {
            HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE,
                CPSW_ALE_TBL_ENTRY_TYPE_FREE);
            CPSWAleSetTableEntry(baseAddr, idx, aleEntry);
        }
        else
        {
            HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_MULTI_ADDR_PORT_MASK,
                regFieldVal);
        }
        retVal = idx;
    }

    return retVal;
}

uint32_t CPSWAleVlanEntryPortAdd(uint32_t baseAddr,
                              uint32_t vlanId,
                              uint32_t portNum,
                              cpswAleVlanConfigParams_t vlanParams)
{
    uint32_t aleEntry[CPSW_ALE_ENTRY_NUM_WORDS] = {0U, 0U, 0U};
    uint32_t idx = CPSW_ALE_ENTRY_MAX;
    uint32_t regFieldVal = 0U;
    uint32_t retVal = CPSW_ALE_ENTRY_MAX;

    idx = CPSWAleGetVlanEntry(baseAddr, vlanId);
    if (CPSW_ALE_ENTRY_MAX == idx)
    {
        idx = CPSWAleGetFreeEntry(baseAddr);
        if (CPSW_ALE_ENTRY_MAX == idx)
        {
            idx = CPSWAleGetUntouchEntry(baseAddr);
        }
    }
    else
    {
        CPSWAleGetTableEntry(baseAddr, idx, aleEntry);
    }

    if (CPSW_ALE_ENTRY_MAX != idx)
    {
        retVal = idx;

        HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE,
            CPSW_ALE_TBL_ENTRY_TYPE_VLAN);

        HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_VLAN_ID,
            vlanId);

        regFieldVal = HW_GET_FIELD(aleEntry[0U],
            CPSW_ALE_TBLW0_VLAN_MEMBER_LIST);
        regFieldVal |= (1U << portNum);
        HW_SET_FIELD(aleEntry[0U], CPSW_ALE_TBLW0_VLAN_MEMBER_LIST,
            regFieldVal);

        regFieldVal = HW_GET_FIELD(aleEntry[0U],
            CPSW_ALE_TBLW0_VLAN_UNREG_MCAST_FLOOD_MASK);
        if(TRUE == vlanParams.enableUnregMcastFlood)
        {
            regFieldVal |= (1U << portNum);
        }
        else
        {
            regFieldVal &= ~(1U << portNum);
        }
        HW_SET_FIELD(aleEntry[0U], CPSW_ALE_TBLW0_VLAN_UNREG_MCAST_FLOOD_MASK,
            regFieldVal);

        regFieldVal = HW_GET_FIELD(aleEntry[0U],
            CPSW_ALE_TBLW0_VLAN_REG_MCAST_FLOOD_MASK);
        if(TRUE == vlanParams.enableRegMcastFlood)
        {
            regFieldVal |= (1U << portNum);
        }
        else
        {
            regFieldVal &= ~(1U << portNum);
        }
        HW_SET_FIELD(aleEntry[0U], CPSW_ALE_TBLW0_VLAN_REG_MCAST_FLOOD_MASK,
            regFieldVal);

        regFieldVal = HW_GET_FIELD(aleEntry[0U],
            CPSW_ALE_TBLW0_VLAN_FORCE_UNTAGGED_EGRESS);
        if(TRUE == vlanParams.enableForceUntaggedEgress)
        {
            regFieldVal |= (1U << portNum);
        }
        else
        {
            regFieldVal &= ~(1U << portNum);
        }
        HW_SET_FIELD(aleEntry[0U], CPSW_ALE_TBLW0_VLAN_FORCE_UNTAGGED_EGRESS,
            regFieldVal);

        CPSWAleSetTableEntry(baseAddr, idx, aleEntry);
    }

    return retVal;
}

uint32_t CPSWAleVlanEntryPortDel(uint32_t baseAddr,
                              uint32_t vlanId,
                              uint32_t portNum)
{
    uint32_t aleEntry[CPSW_ALE_ENTRY_NUM_WORDS] = {0U, 0U, 0U};
    uint32_t idx = CPSW_ALE_ENTRY_MAX;
    uint32_t regFieldVal = 0U;
    uint32_t retVal = CPSW_ALE_ENTRY_MAX;

    idx = CPSWAleGetVlanEntry(baseAddr, vlanId);

    if(CPSW_ALE_ENTRY_MAX != idx)
    {
        CPSWAleGetTableEntry(baseAddr, idx, aleEntry);

        regFieldVal = HW_GET_FIELD(aleEntry[2U],
            CPSW_ALE_TBLW0_VLAN_MEMBER_LIST);
        regFieldVal &= ~(1U << portNum);

        if(0U == regFieldVal)
        {
            HW_SET_FIELD(aleEntry[1U], CPSW_ALE_TBLW1_ENTRY_TYPE,
                CPSW_ALE_TBL_ENTRY_TYPE_FREE);
            CPSWAleSetTableEntry(baseAddr, idx, aleEntry);
        }
        else
        {
            HW_SET_FIELD(aleEntry[2U], CPSW_ALE_TBLW2_MULTI_ADDR_PORT_MASK,
                regFieldVal);

            regFieldVal = HW_GET_FIELD(aleEntry[0U],
                CPSW_ALE_TBLW0_VLAN_UNREG_MCAST_FLOOD_MASK);
            regFieldVal &= ~(1U << portNum);
            HW_SET_FIELD(aleEntry[0U], CPSW_ALE_TBLW0_VLAN_UNREG_MCAST_FLOOD_MASK,
                regFieldVal);

            regFieldVal = HW_GET_FIELD(aleEntry[0U],
                CPSW_ALE_TBLW0_VLAN_REG_MCAST_FLOOD_MASK);
            regFieldVal &= ~(1U << portNum);
            HW_SET_FIELD(aleEntry[0U], CPSW_ALE_TBLW0_VLAN_REG_MCAST_FLOOD_MASK,
                regFieldVal);

            regFieldVal = HW_GET_FIELD(aleEntry[0U],
                CPSW_ALE_TBLW0_VLAN_FORCE_UNTAGGED_EGRESS);
            regFieldVal &= ~(1U << portNum);
            HW_SET_FIELD(aleEntry[0U], CPSW_ALE_TBLW0_VLAN_FORCE_UNTAGGED_EGRESS,
                regFieldVal);
        }
        retVal = idx;
    }

    return retVal;
}

/* ========================================================================== */
/*                          Deprecated Function Definitions                   */
/* ========================================================================== */
