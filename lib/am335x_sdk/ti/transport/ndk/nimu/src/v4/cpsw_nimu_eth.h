/**
 *   @file  cpsw_nimu_eth.h
 *   @brief
 *      Include file for cpsw nimu implementation for AMxxx SOCs
 */

/* Copyright (C) {2012-2018} Texas Instruments Incorporated - http://www.ti.com/ 
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

#ifndef CPSW_NIMU_ETH_H_
#define CPSW_NIMU_ETH_H_

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

typedef void *EMAC_Handle;

/**
 * @brief
 *  Packet device information
 *
 * @details
 *  This structure caches the device info.
 */
typedef struct NIMU_CpswPdInfo_s
{
    /**
     * @brief       Physical index of this device (0 to n-1).
     */
    uint32_t       PhysIdx;
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
    uint32_t            Filter;
    /*
     * @brief       Previous MCast Address Countr
     */
    uint32_t	        OldMCastCnt;
    /*
     * @brief       Previous Multicast list configured by the Application.
     */
    uint8_t 	        bOldMCast[MAC_ADDR_SIZE*PKT_MAX_MCAST];
    /*
     * @brief       Current MCast Address Countr
     */
    uint32_t        MCastCnt;
    /*
     * @brief       Multicast list configured by the Application.
     */
    uint8_t           bMCast[MAC_ADDR_SIZE*PKT_MAX_MCAST];
    /*
     * @brief       Transmitter "free" flag
     */
    uint32_t            TxFree;
    /*
     * @brief       Tx queue (one for each PKT device)
     */
    PBMQ            PBMQ_tx;
    /*
     * @brief       Rx queue (one for each PKT device)
     */
    PBMQ            PBMQ_rx;

    EMAC_Handle     EmacCfgParams;
} NIMU_CpswPdInfo;


typedef struct NIMU_CpswMacAddr_s {
  uint8_t macAddr[6];
} NIMU_CpswMacAddr;

#ifdef __cplusplus
}
#endif

#endif /* CPSW_NIMU_ETH_H_ */
