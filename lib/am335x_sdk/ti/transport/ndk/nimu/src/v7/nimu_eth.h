/**
 *  \ingroup TRANSPORT_NIMU_MODULE
 *  \defgroup TRANSPORT_NIMU_API_V7_MODULE NIMU Driver V7 API
 *            This file defines the interface applications can use when
 *            integrating the Network Interface Module Ethernet driver adaptation layer
 *  @{
 */

/**
 * @file   nimu/src/v7/nimu_eth.h
 */
/*
 * Copyright (c) 2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#ifndef NIMU_ETH_H_
#define NIMU_ETH_H_

#include <ti/csl/tistdtypes.h>
#include <ti/ndk/inc/stkmain.h>

#ifdef __cplusplus
extern "C" {
#endif

/*
 * Pre-Pad Packet Data Offset
 *
 *   The TCP/IP stack library requires that every packet device
 *   include enough L2 header room for all supported headers. In
 *   order to support PPPoE, this requires a 22 byte L2 header.
 *   Thus, since standard Ethernet is only 14 bytes, we must add
 *   on an additional 8 byte offset, or PPPoE can not function
 *   with our driver.
*/
#define     NIMU_PKT_PREPAD                      ((uint32_t)0U)

/* Indicates whether RAM based multicast lists are suported for this
 * EMAC peripheral.
 */
#define     RAM_MCAST                       ((uint32_t)0U)

/* Indicates whether HASH based multicasting is suported for this
 * EMAC peripheral.
 */
#define     HASH_MCAST                      ((uint32_t)0U)

/* Multicast Address List Size */
#define     PKT_MAX_MCAST                   ((uint32_t)31U)


/* Multicast Address List Size */
#define     MAC_ADDR_SIZE                   ((uint32_t)6U)

/* Max Number of EMAC ports */
#define NIMU_NUM_EMAC_PORTS                  ((uint32_t)9U)
typedef void *EMAC_Handle;

/**
 * @brief
 *  Packet device information
 *
 * @details
 *  This structure caches the device info.
 */
typedef struct NIMU_PdInfo_s
{
    /**
     * @brief      port number of this interface
     */
    uint32_t            portNum;
    /*
     * @brief       Handle to logical driver.
     */
    void*          hEther;
    /*
     * @brief       Semaphore handle used by NDK stack and driver
     *              to communicate any pending Rx events that need
     *              to be serviced by NDK ethernet stack.
     */
    STKEVENT_Handle hEvent;
    /*
     * @brief       MAC Address
     */
    uint8_t           bMacAddr[MAC_ADDR_SIZE];
    /*
     * @brief       Current RX filter
     */
    uint32_t            rxFilter;
    /*
     * @brief       Current MCast Address Countr
     */
    uint32_t            mCastCnt;
    /*
     * @brief       Transmitter "free" flag
     */
    uint32_t            txFree;
    /*
     * @brief       Tx queue (one for each PKT device)
     */
    PBMQ            PBMQTx;
    /*
     * @brief       Rx queue (one for each PKT device)
     */
    PBMQ            PBMQRx;
    /*
     * @brief       number of interfaces
     */
    uint32_t            gNumEmacInterfaces;
} NIMU_PdInfo;


typedef struct NIMU_MacAddr_s {
  uint8_t macAddr[6];
} NIMU_MacAddr;

#ifdef NIMU_ICSSG
/* EMAC firmware header files */
typedef struct NIMU_PruRtuFw_s{
    const uint32_t *pru;
    uint32_t pru_size;
    const uint32_t *rtu;
    uint32_t rtu_size;
} NIMU_PruRtuFw;
#endif
#ifdef __cplusplus
}
#endif

#endif /* NIMU_ETH_H_ */

/* @} */
