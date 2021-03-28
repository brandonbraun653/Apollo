/**
 *   @file nimu_icssSwitchEmac.h
 *   @brief
 *      Include file for helper and data types functions used to implement NDK NIMU transport interface for ICSS
 */

/* Copyright (C) 2015-2018 Texas Instruments Incorporated - http://www.ti.com/
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
#ifndef NIMU_ICSS_SWITCH_EMAC_H
#define NIMU_ICSS_SWITCH_EMAC_H

#include "ti/drv/icss_emac/icss_emacStatistics.h"
#include "ti/transport/ndk/nimu_icss/nimu_icssIoctl.h"
#include "ti/transport/ndk/nimu_icss/nimu_icssEth.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* @def NIMU_ICSS_NUM_PORTS
*      Port Count
*/
#define NIMU_ICSS_NUM_PORTS                    ((uint32_t)3U)
/**
* @def NIMU_ICSS_NUM_MAC_PORTS
*      MAC Port Count
*/
    #define NIMU_ICSS_NUM_MAC_PORTS                ((uint32_t)2U)


/**
* @def NIMU_ICSS_EMAC_PKT_FLAGS_SOP
*      Start of packet
*/
#define NIMU_ICSS_EMAC_PKT_FLAGS_SOP                  ((uint32_t)0x80000000U)
/**
* @def NIMU_ICSS_EMAC_PKT_FLAGS_EOP
*      End of packet
*/
#define NIMU_ICSS_EMAC_PKT_FLAGS_EOP                  ((uint32_t)0x40000000U)

/**
* @def NIMU_ICSS_DEFAULT_MDIOBUSFREQ
*      ICSS MDIO Bus Frequency
*/
#define NIMU_ICSS_DEFAULT_MDIOBUSFREQ                            ((uint32_t)2200000U)
/**
* @def NIMU_ICSS_DEFAULT_MDIOCLOCKFREQ
*      ICSS MDIO Clock Frequency
*/
#define NIMU_ICSS_DEFAULT_MDIOCLOCKFREQ                         ((uint32_t)200000000U)

/** Timeperiod (in ticks) after which Learning Age out function is called to age the table. This divided by 100
 * gives the number of BIOS ticks*/
#define NIMU_ICSS_ALE_AGE_OUT_TIME            ((uint32_t)300000)




/**
* @def NIMU_ICSS_SUCCESS
*      Success code
*/
#define NIMU_ICSS_SUCCESS                              ((uint32_t)0U)

/**
* @def NIMU_ICSS_INVALID_PARAM
*      Function or calling parameter is invalid
*/
#define NIMU_ICSS_INVALID_PARAM                         ((uint32_t)1U)


/**
* @def NIMU_ICSS_ERR_TX_OUT_OF_BD
*      Tx ran out of Buffer descriptors to use.
*/
#define NIMU_ICSS_ERR_TX_OUT_OF_BD                      ((uint32_t)2U)

/**
* @def NIMU_ICSS_ERR_BADPACKET
*      Supplied packet was invalid
*/
#define NIMU_ICSS_ERR_BADPACKET                         ((uint32_t)3U)

/**
* @def NIMU_ICSS_INTERNAL_FAILURE
*       EMAC Internal failure
*/
#define NIMU_ICSS_INTERNAL_FAILURE                     ((uint32_t)4U)

/**
* @def NIMU_ICSS_INVALID_PORT
*      Invalid Port Specified
*/
#define NIMU_ICSS_INVALID_PORT                         ((uint32_t)5U)



/*Phy register offset*/
#define NIMU_ICSS_PHY_BMCR_REG              ((uint32_t)(0x0U))
#define NIMU_ICSS_PHY_BMSR_REG              ((uint32_t)(0x1U))
#define NIMU_ICSS_PHY_PHYIDR1_REG           ((uint32_t)(0x2U))
#define NIMU_ICSS_PHY_ANER_REG              ((uint32_t)(0x6U))

#define NIMU_ICSS_MII_AUTO_NEGOTIATE_EN     (uint16_t)(((uint16_t)(1U)) << ((uint16_t)(12U)))
#define NIMU_ICSS_MII_SPEEDSEL_100         (uint16_t)(((uint16_t)(1U)) << ((uint16_t)(13U)))
#define NIMU_ICSS_MII_DUPLEXMODE_FULL      (uint16_t)(((uint16_t)(1U)) << ((uint16_t)(8U)))

/**
 *  @brief  NIMU_IcssEmacPkt
 *  @details The packet structure defines the basic unit of memory used to hold data
 *  packets for the EMAC device.
 *  A packet is comprised of one or more packet buffers. Each packet buffer
 *  contains a packet buffer header, and a pointer to the buffer data.
 *  The NIMU_IcssEmacPkt structure defines the packet buffer header.
 *
 *  The pDataBuffer field points to the packet data. This is set when the
 *  buffer is allocated, and is not altered.
 *
 *  BufferLen holds the the total length of the data buffer that is used to
 *  store the packet (or packet fragment). This size is set by the entity
 *  that originally allocates the buffer, and is not altered.
 *
 *  The Flags field contains additional information about the packet
 *
 *  ValidLen holds the length of the valid data currently contained in the
 *  data buffer.
 *
 *  DataOffset is the byte offset from the start of the data buffer to the
 *  first byte of valid data. Thus (ValidLen+DataOffet)<=BufferLen.
 *
 *  Note that for receive buffer packets, the DataOffset field may be
 *  assigned before there is any valid data in the packet buffer. This allows
 *  the application to reserve space at the top of data buffer for private
 *  use. In all instances, the DataOffset field must be valid for all packets
 *  handled by EMAC.
 *
 *  The data portion of the packet buffer represents a packet or a fragment
 *  of a larger packet. This is determined by the Flags parameter. At the
 *  start of every packet, the SOP bit is set in Flags. If the EOP bit is
 *  also set, then the packet is not fragmented. Otherwise; the next packet
 *  structure pointed to by the pNext field will contain the next fragment in
 *  the packet. On either type of buffer, when the SOP bit is set in Flags,
 *  then the PktChannel, PktLength, and PktFrags fields must also be valid.
 *  These fields contain additional information about the packet.
 *
 *  The PktChannel field detetmines what channel the packet has arrived on,
 *  or what channel it should be transmitted on. The EMAC library supports
 *  only a single receive channel, but allows for up to eight transmit
 *  channels. Transmit channels can be treated as round-robin or priority
 *  queues.
 *
 *  The PktLength field holds the size of the entire packet. On single frag
 *  packets (both SOP and EOP set in BufFlags), PktLength and ValidLen will
 *  be equal.
 *
 *  The PktFrags field holds the number of fragments (NIMU_IcssEmacPkt records) used
 *  to describe the packet. If more than 1 frag is present, the first record
 *  must have NIMU_ICSS_EMAC_PKT_FLAGS_SOP flag set, with corresponding fields validated.
 *  Each frag/record must be linked list using the pNext field, and the final
 *  frag/record must have NIMU_ICSS_EMAC_PKT_FLAGS_EOP flag set and pNext=0.
 *
 *  In systems where the packet resides in cacheable memory, the data buffer
 *  must start on a cache line boundary and be an even multiple of cache
 *  lines in size. The NIMU_IcssEmacPkt header must not appear in the same cache line
 *  as the data portion of the packet. On multi-fragment packets, some packet
 *  fragments may reside in cacheable memory where others do not.
 *
 *  It is up to the caller to assure that all packet buffers
 *   residing in cacheable memory are not currently stored in L1 or L2
 *   cache when passed to any EMAC function.
*/
typedef struct NIMU_IcssEmacPkt_s{
    uint32_t           AppPrivate;        /**< For use by the application                                         */
    struct NIMU_IcssEmacPkt_s *pPrev;            /**< Previous record                                                    */
    struct NIMU_IcssEmacPkt_s *pNext;            /**< Next record                                                        */
    uint8_t            *pDataBuffer;        /**< Pointer to Data Buffer (read only)                                 */
    uint32_t           BufferLen;            /**< Physical Length of buffer (read only)                              */
    uint32_t           Flags;                /**< Packet Flags                                                       */
    uint32_t           ValidLen;            /**< Length of valid data in buffer                                     */
    uint32_t           DataOffset;        /**< Byte offset to valid data                                          */
    uint32_t           PktChannel;         /**< Tx/Rx Channel/Priority 0-7 (SOP only)                              */
    uint32_t           PktLength;            /**< Length of Packet (SOP only) (same as ValidLen on single frag Pkt)  */
    uint32_t           PktFrags;            /**< No of frags in packet (SOP only) frag is NIMU_IcssEmacPkt record-normally 1*/
} NIMU_IcssEmacPkt;

/**
 *  @brief MAC addresses configuration Structure
 *
 */
typedef struct NIMU_IcssAddrConfig_s {
    uint8_t Addr[6];        /** MAC address specific to channel */
} NIMU_IcssAddrConfig;

/**
 *  @brief  EMAC Main Device Instance Structure
 *
 */
typedef struct NIMU_IcssDevice_s {

    NIMU_IcssPdInfo *              nimuPdInfo;
    uint32_t              aleTicks;                            /**< Ticks for this timer                                               */
    uint32_t               aleTimerActive;                        /**<ALE ageout timer active?                                            */
    uint32_t              RxFilter;                             /**<Receive Filter settings    */
    uint32_t              PktMTU;                                /**< Max physical packet size                                           */
    uint32_t              FatalError;                            /**< Fatal Error Code                                                   */
    NIMU_IcssStatistics *  nimuStat;        /**< Current running statistics                                         */
    NIMU_IcssEmacPkt* nimuPktRx;
    NIMU_IcssEmacPkt* nimuPktTx;
    NIMU_IcssEmacPkt *          (*pfcbRxPacket)(Handle hApplication, NIMU_IcssEmacPkt *pPacket);/**< Receive packet call back */
} NIMU_IcssDevice;


/* @} */
/**
* @brief  Opens the EMAC peripheral at the given physical index and initializes
*             it to an embryonic state.
* @details       The calling application must supply a operating configuration that
*             includes a callback function table. Data from this config structure is
*             copied into the device's internal instance structure so the structure
*             may be discarded after NIMU_ICSS_openPeripheral() returns. In order to change an item
*             in the configuration, the EMAC device must be closed and then
*             re-opened with the new configuration.
*
*                 The application layer may pass in an hApplication callback handle,
*             that will be supplied by the EMAC device when making calls to the
*             application callback functions.
*
*             An EMAC device handle is written to phEMAC. This handle must be saved
*             by the caller and then passed to other EMAC device functions.
*
*             The default receive filter prevents normal packets from being received
*             until the receive filter is specified by calling EMAC_receiveFilter().
*
*             A device reset is achieved by calling NIMU_ICSS_closePeripheral() followed by NIMU_ICSS_openPeripheral().
*
*             The function returns zero on success, or an error code on failure.
*
*             Possible error codes include:
*               SWITCH_ERR_DEV_ALREADY_OPEN   - The device is already open
*               NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
*
* @internal
*
* @param pi   pointer to ICSS EMAC Handle
*
* @retval     Success (0)
*            NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
*            SWITCH_ERR_DEV_ALREADY_OPEN   - The device is already open
*
*/
void NIMU_ICSS_openPeripheral(NIMU_IcssPdInfo *pi);
/**
* @brief Closed the EMAC peripheral indicated by the supplied instance handle.
*             When called, the EMAC device will shutdown both send and receive
*             operations, and free all pending transmit and receive packets.
* @details    The function returns zero on success, or an error code on failure.
*                 Possible error code include:
*                 NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
* @internal
* @param pi   handle to opened the EMAC device
*
* @retval     Success (0)
*            NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
* @pre      NIMU_ICSS_openPeripheral function must be called before calling this API.
*
*/
uint32_t NIMU_ICSS_closePeripheral(NIMU_IcssPdInfo *pi);
/**
* @brief     Called to get the current device statistics. The statistics structure
*             contains a collection of event counts for various packet sent and
*             receive properties. Reading the statistics also clears the current
*             statistic counters, so the values read represent a delta from the last
*             call.
* @details  The statistics information is copied into the structure pointed to
*                 by the pStatistics argument.
*                 The function returns zero on success, or an error code on failure.
*                 Possible error code include:
*                  NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
* @internal
* @param  hEMAC       handle to the opened EMAC device
* @param  pStatistics Pointer to the device statistics
* @param  portNo   port number
*
* @retval     Success (0)
*            NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
* @pre      EMAC peripheral instance must be opened before calling this API
*
*/
uint32_t NIMU_ICSS_getStatistics( NIMU_IcssPdInfo *pi, NIMU_IcssStatistics *pStatistics,uint8_t portNo);
/**
* @brief     Called to clear the current device statistics for a particular port
* @internal
* @param  pi       handle to the opened EMAC device
* @param  portNo   port to clear statistics
*
* @retval     Success (0)
*            NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
* @pre      EMAC peripheral instance must be opened before calling this API
*
*/
uint32_t NIMU_ICSS_clearStatistics(NIMU_IcssPdInfo *pi,uint8_t portNo);
/**
* @brief     This function is called to perform various get/set operations on the
*             EMAC ALE table, statistics counters etc.
* @internal
* @param  pi       handle to the opened EMAC device
* @param  pBuf        pointer to the buffer that holds the configuration
                      command and any data required.
* @param  size        size of the buffer
*
* @retval     Success (0)
*            NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
* @pre      EMAC peripheral instance must be opened before calling this API
*
*/
uint32_t NIMU_ICSS_setConfig(NIMU_IcssPdInfo *pi, void* pBuf, uint32_t size);
/**

* @brief     Sends a Ethernet data packet out the EMAC device. On a non-error return,
*             the EMAC device takes ownership of the packet. The packet is returned
*             to the application's free pool once it has been transmitted.
* @internal
* @param  hEMAC       handle to the opened EMAC device
* @param  pPkt        EMAC packet structure
*
* @retval     Success (0)
*            NIMU_ICSS_INVALID_PARAM   - A calling parameter is invalid
*            NIMU_ICSS_ERR_BADPACKET - The packet structure is invalid
* @pre      EMAC peripheral instance must be opened and get a packet
*              buffer from private queue
*
*/
uint32_t NIMU_ICSS_sendPacket(Handle hEMAC, NIMU_IcssEmacPkt *pPkt);
/**

* @brief     This function should be called every time there is an EMAC device Rx
*             interrupt to process the packet
* @details  Note that the application has the responsibility for mapping the
*             physical device index to the correct EMAC_serviceCheck() function. If
*             more than one EMAC device is on the same interrupt, the function must be
*             called for each device.
* @internal
* @param  hEMAC       handle to the opened EMAC device
* @param  prioQueue   Queue priority
*
* @retval     NIMU_ICSS_SUCCESS (0)
*                NIMU_ICSS_INTERNAL_FAILURE   - Packet provided by firmware has invalid length
* @pre     NIMU_ICSS_openPeripheral function must be called before calling this API.
*
*/
uint32_t NIMU_ICSS_rxServiceCheck(ICSS_EmacHandle hEMAC,int32_t prioQueue);
/**
* @brief The function initialize an NIMU_IcssEmacPkt to receive packets
* @internal
* @param pNimuPacket pointer to NDK packet buffer structure
*
* @retval none
*/
void NIMU_ICSS_packetInit(NIMU_IcssEmacPkt* pNimuPacket);


#ifdef __cplusplus
}
#endif
#endif /* NIMU_ICSS_SWITCH_EMAC_H_ */
