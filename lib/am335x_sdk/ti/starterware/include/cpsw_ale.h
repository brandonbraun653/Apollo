/**
 *  \file       cpsw_ale.h
 *
 *  \brief      This file contains the function prototypes for the device
 *              contains some abstraction layer for ALE module of CPSW subsystem.
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

#ifndef CPSW_ALE_H_
#define CPSW_ALE_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*              API compatibility with Starterware 2.0                        */
/* ========================================================================== */
#define CPSWALEInit             CPSWAleInit
#define CPSWALEPortStateSet     CPSWAleSetPortState
#define CPSWALETableEntrySet    CPSWAleSetTableEntry
#define CPSWALETableEntryGet    CPSWAleGetTableEntry
#define CPSWALEPrescaleGet      CPSWAleGetRateLimitPrescale
#define CPSWALEPrescaleSet      CPSWAleSetRateLimitPrescale

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief ALE entry length in words. */
#define CPSW_ALE_ENTRY_MAX                                 (1024U)

/** \brief ALE entry length in words. */
#define CPSW_ALE_ENTRY_NUM_WORDS                           (3U)

/** \brief Broadcast MAC address byte mask. */
#define CPSW_ALE_BROADCAST_MAC_ADDR_MASK                   (0xFFU)

/** \brief Multicast MAC address upper byte mask. */
#define CPSW_ALE_MULTICAST_MAC_ADDR_MASK                   (0x01U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates types of ALE table entry. */
typedef enum cpswAleTblEntryType
{
    CPSW_ALE_TBL_ENTRY_TYPE_FREE      = 0x0U,
    /**< Free entry. */
    CPSW_ALE_TBL_ENTRY_TYPE_ADDR      = 0x1U,
    /**< Address type ALE entry. */
    CPSW_ALE_TBL_ENTRY_TYPE_VLAN      = 0x2U,
    /**< VLAN type ALE entry. */
    CPSW_ALE_TBL_ENTRY_TYPE_VLAN_ADDR = 0x3U,
    /**< VLAN Address type ALE entry. */
}cpswAleTblEntryType_t;

/** \brief Enumerates types of Unicast ALE table entry. */
typedef enum cpswAleTblUnicastType
{
    CPSW_ALE_TBL_UNICAST_TYPE_NOT_AGEABLE       = 0x0U,
    /**< Unicast address that is not ageable. */
    CPSW_ALE_TBL_UNICAST_TYPE_AGEABLE_UNTOUCH   = 0x1U,
    /**< Ageable unicast address that has not been touched. */
    CPSW_ALE_TBL_UNICAST_TYPE_OUI               = 0x2U,
    /**< Non ageable OUI address. */
    CPSW_ALE_TBL_UNICAST_TYPE_AGEABLE_TOUCH     = 0x3U,
    /**< Ageable unicast address that has been touched. */
}cpswAleTblUnicastType_t;

/** \brief Enumerates port state configuration values in address lookup engine. */
typedef enum cpswAlePortState
{
    CPSW_ALE_PORT_STATE_DISABLED   = 0x00U,
    /**< Port is disabled in address lookup engine. */
    CPSW_ALE_PORT_STATE_BLOCKED    = 0x01U,
    /**< Port is blocked in address lookup engine. */
    CPSW_ALE_PORT_STATE_LEARN      = 0x02U,
    /**< Port is configured for learning in address lookup engine. */
    CPSW_ALE_PORT_STATE_FWD        = 0x03U
    /**< Port is configured to forward in address lookup engine. */
}cpswAlePortState_t;

/** \brief Structure holding the I2C register context .*/
typedef struct cpswAleTblEntry
{
    uint32_t word0;
    /**< Pre-scalar register value.*/
    uint32_t word1;
    /**< SCL low time register value.*/
    uint32_t word2;
    /**< SCL high time register value.*/
}cpswAleTblEntry_t;

/** \brief Structure holding the I2C register context .*/
typedef struct cpswAleVlanConfigParams
{
    uint32_t enableUnregMcastFlood;
    /**< Mask used for multicast when the multicast address is not found.*/
    uint32_t enableRegMcastFlood;
    /**< Mask used for multicast when the multicast address is found.*/
    uint32_t enableForceUntaggedEgress;
    /**< This field causes the packet VLAN tag to be removed on egress (except on port 0).*/
 }cpswAleVlanConfigParams_t;

/** \brief Structure holding the I2C register context .*/
typedef struct cpswAleMcastConfigParams
{
    uint32_t fwdState;
    /**<
     *  Indicates the port state(s) required for the received port on a
     *  destination address lookup in order for the multicast packet to be
     *  forwarded to the transmit port(s). A transmit port must be in the
     *  Forwarding state in order to forward the packet. If the transmit
     *  port_mask has multiple set bits then each forward decision is
     *  independent of the other transmit port(s) forward decision.
     */
    uint32_t enableSuper;
    /**<
     *  This field indicates that the packet with a matching multicast
     *  destination address is a supervisory packet.
     */
}cpswAleMcastConfigParams_t;

/** \brief Structure holding the I2C register context .*/
typedef struct cpswAleUcastConfigParams
{
    uint32_t unicastType;
    /**< This field indicates the type of unicast address the table entry contains. */
    uint32_t enableSecure;
    /**<
     *  This bit indicates that a packet with a matching source address should
     *  be dropped if the received port number is not equal to the table entry
     *  port_number.
     */
    uint32_t enableBlock;
    /**<
     *  The block bit indicates that a packet with a matching source or
     *  destination address should be dropped (block the address).
     */
    uint32_t enableDlr;
    /**<
     *  This indicates that the address is a Device Level Ring (DLR) unicast
     *  address. Received packets with a matching destination address will be
     *  flooded to the vlan_member_list (minus the receive port and the host port).
     */
}cpswAleUcastConfigParams_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This API initializes ALE. It clears the ALE table and enables packet
 *          processing by ALE.
 *
 * \param   baseAddr    Base address of the CPSW.
 */
void CPSWAleInit(uint32_t baseAddr);

/**
 * \brief   This API enables/disables packet processing by ALE.
 *
 * \param   baseAddr    Base address of the CPSW.
 * \param   aleEnable   ALE packet processing.
 *                      # TRUE  - Enable ALE packet processing.
 *                      # FALSE - Drop all packets.
 */
void CPSWAleEnable(uint32_t baseAddr, uint32_t aleEnable);

/**
 * \brief   This API clears the entries of address lookup table.
 *
 * \param   baseAddr    Base address of the CPSW.
 */
void CPSWAleClearTable(uint32_t baseAddr);

/**
 * \brief   This API removes any ageable ALE table entries that does not have a
 *          touch bit set.
 *
 * \param   baseAddr    Base address of the CPSW.
 */
void CPSWAleAgeOut(uint32_t baseAddr);

/**
 * \brief   This API sets the packet rate Limit for given packet type in ALE.
 *
 * \param   baseAddr      Base Address of the ALE module
 * \param   portNum       Port number.
 * \param   pktType       Type of packet takes following values
 *                        -# #ETHERNET_ADDR_TYPE_MULTICAST
 *                        -# #ETHERNET_ADDR_TYPE_BROADCAST
 * \param   pktRateLimit  Packet rate limit.
 *
 * \note    Rate limiting is enabled by a non-zero value.
 */
void CPSWAleSetRateLimit(uint32_t baseAddr,
                         uint32_t portNum,
                         uint32_t pktType,
                         uint32_t pktRateLimit);

/**
 * \brief   This API enables/disables dropping of packets in ALE module for
 *          given port with unknown (default) or no VLAN ID in ALE module.
 *
 * \param   baseAddr           Base Address of the CPSW.
 * \param   portNum            Port number.
 * \param   enableIngressCheck Configure VLAN ingress check
 *                             -# TRUE  - Enable VLAN ingress check.
 *                             -# FALSE - Disable VLAN ingress check.
 */
void CPSWAleVlanIdIngressCheckEnable(uint32_t baseAddr,
                                     uint32_t portNum,
                                     uint32_t enableIngressCheck);

/**
 * \brief   This API configures the port state for a given port in the ALE.
 *
 * \param   baseAddr    Base address of the CPSW.
 * \param   portNum     The port number
 * \param   portState   The port state takes values #cpswAlePortState_t.
 */
void CPSWAleSetPortState(uint32_t baseAddr,
                         uint32_t portNum,
                         uint32_t portState);

/**
 * \brief   This API configures VLAN Aware in ALE module to determine what
 *          to be done if VLAN is not found.
 *
 * \param   baseAddr        Base Address of the CPSW.
 * \param   enableVlanAware ALE VLAN Aware configuration for packet.
 *                          -# TRUE  - Drop packet if VLAN not found
 *                          -# FALSE - Flood if VLAN not found
 */
void CPSWAleVlanAwareEnable(uint32_t baseAddr, uint32_t enableVlanAware);

/**
 * \brief   This enables broadcast/multicast rate Limit for given transfer mode
 *          in ALE module.
 *
 * \param   baseAddr    Base address of the CPSW.
 * \param   xferMode    Transfer mode to be configured for rate limit and it
 *                      takes values #ethernetXferMode_t.
 */
void CPSWAleRateLimitEnable(uint32_t baseAddr, uint32_t xferMode);

/**
 * \brief   This disables broadcast/multicast rate Limit in ALE module.
 *
 * \param   baseAddr    Base address of the CPSW.
 */
void CPSWAleRateLimitDisable(uint32_t baseAddr);

/**
 * \brief   This enables/disables MAC Authorization Mode of ALE.
 *
 * \details Mac authorization mode requires that all table entries be made by
 *          the host software. There are no learned address in authorization
 *          mode and the packet will be dropped if the source address is not
 *          found (and the destination address is not a multicast address with
 *          the super table entry bit set).
 *
 * \param   baseAddr      Base address of the CPSW.
 * \param   enableMacAuth MAC AUTH configuration takes values
 *                        -# TRUE  - Enable MAC AUTH mode
 *                        -# FALSE - Disable MAC AUTH mode
 */
void CPSWAleAuthModeEnable(uint32_t baseAddr, uint32_t enableMacAuth);

/**
 * \brief   This API enables/disables the bypassing of the ALE logic for all
 *          packets received on slave ports to the host port.
 *
 * \param   baseAddr     Base Address of the CPSW.
 * \param   enableBypass Bypass ALE logic configuration takes values
 *                       -# TRUE  - Enable bypass mode
 *                       -# FALSE - Disable bypass mode
 */
void CPSWAleBypassEnable(uint32_t baseAddr, uint32_t enableBypass);

/**
 * \brief   This API sets an ALE table entry at given index.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   aleTblIdx    The Index of the table entry.
 * \param   pAleEntryPtr The address of the entry to be set.
 */
void CPSWAleSetTableEntry(uint32_t baseAddr,
                          uint32_t aleTblIdx,
                          uint32_t *pAleEntryPtr);

/**
 * \brief   This API reads an ALE table entry at given index.
 *
 * \param   baseAddr     Base address of the CPSW.
 * \param   aleTblIdx    The Index of the table entry.
 * \param   pAleEntryPtr The address where the ALE entry to be read.
 */
void CPSWAleGetTableEntry(uint32_t baseAddr,
                          uint32_t aleTblIdx,
                          uint32_t *pAleEntryPtr);

/**
 * \brief   This API reads the prescale value for ALE.
 *
 * \details The input clock is divided by this value to use in the broadcast/
 *          multicast rate limiters. The minimum operating value is 0x10. The
 *          prescaler is off when the value is zero.
 *
 * \param   baseAddr      Base Address of the CPSW.
 */
uint32_t CPSWAleGetRateLimitPrescale(uint32_t baseAddr);

/**
 * \brief   This API sets the prescale value for ALE.
 *
 * \details The input clock is divided by this value to use in the broadcast/
 *          multicast rate limiters. The minimum operating value is 0x10. The
 *          prescaler is off when the value is zero.
 *
 * \param   baseAddr     Base Address of the CPSW
 * \param   preScalarVal The prescale value.
 */
void CPSWAleSetRateLimitPrescale(uint32_t baseAddr, uint32_t preScalarVal);

/**
 * \brief   This API checks the MAC address is of the specified type.
 *
 * \param   pMacAddr   Ethernet MAC address.
 * \param   addrType   Type of address takes values cpswPktType_t.
 *
 * \retval  TRUE       Ethernet MAC address is of the specified type.
 * \retval  FALSE      Ethernet MAC address is not of the specified type.
 */
uint32_t CPSWAleValidateMacAddr(uint8_t *pMacAddr, uint32_t addrType);

/**
 * \brief   Gives the index of the ALE entry which is free
 *
 * \param   baseAddr Base address of the CPSW.
 *
 * \retval  CPSW_ALE_ENTRY_MAX  Entry not found
 * \retval  index    Index of the ALE entry which is free.
 */
uint32_t CPSWAleGetFreeEntry(uint32_t baseAddr);

/**
 * \brief   Gives the index of the ALE entry which is untouched ageable
 *
 * \param   baseAddr Base address of the CPSW.
 *
 * \retval  CPSW_ALE_ENTRY_MAX  Entry not found
 * \retval  index    Index of the ageable Unicast ALE entry which is untouched.
 */
uint32_t CPSWAleGetUntouchEntry(uint32_t baseAddr);

/**
 * \brief  Gives the index of the ALE entry which match address of VLAN
 *
 * \param  baseAddr  Base address of the CPSW.
 * \param  pMacAddr  Ethernet address
 * \param  vlanId    VLAN ID
 *
 * \retval index of the ALE entry which match address of VLAN
 * \retval CPSW_ALE_ENTRY_MAX if entry not found
 */
uint32_t CPSWAleGetAddrEntry(uint32_t baseAddr,
                             uint8_t *pMacAddr,
                             uint32_t vlanId);

/**
 * \brief  Gives the index of the ALE entry which match vlan
 *
 * \param  baseAddr  Base address of the CPSW.
 * \param  vlanId    VLAN ID
 *
 * \retval index of the ALE entry which match vlan
 * \retval CPSW_ALE_ENTRY_MAX if entry not found
 */
uint32_t CPSWAleGetVlanEntry(uint32_t baseAddr, uint32_t vlanId);

/**
 * \brief Adds an unicast entry in the ALE table.
 *
 * \param baseAddr      Base address of the CPSW.
 * \param pMacAddr      Ethernet address
 * \param vlanId        VLAN ID
 * \param portNum       The port number
 * \param unicastParams VLAN config parameters #cpswAleUcastConfigParams_t
 *
 * \retval index of the ALE entry added
 * \retval CPSW_ALE_ENTRY_MAX if table entry is not free
 */
uint32_t CPSWAleUnicastEntryAdd(uint32_t baseAddr,
                                uint8_t *pMacAddr,
                                uint32_t vlanId,
                                uint32_t portNum,
                                cpswAleUcastConfigParams_t unicastParams);

/**
 * \brief Deletes an unicast entry in the ALE table.
 *
 * \param baseAddr   Base address of the CPSW.
 * \param pMacAddr   Ethernet address
 * \param vlanId     VLAN ID
 * \param portNum    The port number
 *
 * \retval index of the ALE entry deleted
 * \retval CPSW_ALE_ENTRY_MAX if table entry is not present
 */
uint32_t CPSWAleUnicastEntryDel(uint32_t baseAddr,
                                uint8_t *pMacAddr,
                                uint32_t vlanId,
                                uint32_t portNum);

/**
 * \brief Adds a multicast entry in the ALE table
 *
 * \param baseAddr        Base address of the CPSW.
 * \param pMacAddr        Ethernet Address
 * \param vlanId          VLAN ID
 * \param portNum         The port number
 * \param multicastParams VLAN config parameters #cpswAleVlanConfigParams_t
 *
 * \retval index of the ALE entry added
 * \retval CPSW_ALE_ENTRY_MAX if table entry is not free
 */
uint32_t CPSWAleMulticastEntryPortAdd(uint32_t baseAddr,
                                   uint8_t *pMacAddr,
                                   uint32_t vlanId,
                                   uint32_t portNum,
                                   cpswAleMcastConfigParams_t multicastParams);

/**
 * \brief Deletes a multicast entry in the ALE table
 *
 * \param baseAddr   Base address of the CPSW.
 * \param pMacAddr   Ethernet Address
 * \param vlanId     VLAN ID
 * \param portNum    The port number
 *
 * \retval index of the ALE entry deleted
 * \retval CPSW_ALE_ENTRY_MAX if table entry is not present
 */
uint32_t CPSWAleMulticastEntryPortDel(uint32_t baseAddr,
                                   uint8_t *pMacAddr,
                                   uint32_t vlanId,
                                   uint32_t portNum);

/**
 * \brief Adds the VLAN entry in ALE table
 *
 * \param baseAddr    Base address of the CPSW.
 * \param vlanId      VLAN ID
 * \param portNum    The port number
 * \param vlanParams  VLAN configuration parameters #cpswAleVlanConfigParams_t
 *
 * \retval index of the ALE entry added
 * \retval CPSW_ALE_ENTRY_MAX if table entry is not free
 */
uint32_t CPSWAleVlanEntryPortAdd(uint32_t baseAddr,
                                 uint32_t vlanId,
                                 uint32_t portNum,
                                 cpswAleVlanConfigParams_t vlanParams);

/**
 * \brief Dlelete the VLAN entry in ALE table
 *
 * \param baseAddr   Base address of the CPSW.
 * \param vlanId     VLAN ID
 * \param portNum    The slave port number
 *
 * \retval index of the ALE entry deleted
 * \retval CPSW_ALE_ENTRY_MAX if table entry is not present
 */
uint32_t CPSWAleVlanEntryPortDel(uint32_t baseAddr,
                              uint32_t vlanId,
                              uint32_t portNum);

/* ========================================================================== */
/*                        Deprecated Function Declarations                    */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif /* #ifndef CPSW_ALE_H_ */
