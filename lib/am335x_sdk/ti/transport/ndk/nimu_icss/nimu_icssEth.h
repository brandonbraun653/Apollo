/**
 *   @file nimu_icssEth.h
 *   @brief
 *      Include file for NDK NIMU transport driver interface for ICSS
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

#ifndef ICSS_NIMU_ETH_H_
#define ICSS_NIMU_ETH_H_

#include <stdint.h>
#include "ti/ndk/inc/stkmain.h"
#include "ti/drv/icss_emac/icss_emacDrv.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
* @def NIMU_ICSS_PKT_PREPAD
*      Pre-Pad Packet Data Offset
*      The TCP/IP stack library requires that every packet device
*      include enough L2 header room for all supported headers. In
*      order to support PPPoE, this requires a 22 byte L2 header.
*      Thus, since standard Ethernet is only 14 bytes, we must add
*      on an additional 8 byte offset, or PPPoE can not function
*      with our driver.
*/
#define     NIMU_ICSS_PKT_PREPAD                      ((uint32_t)0U)

/**
* @def NIMU_ICSS_MAX_MCAST
*      Multicast Address List Size
*/
#define     NIMU_ICSS_MAX_MCAST                    ((uint32_t)31U)




/**
* @brief NIMU_ICSS Driver Status
*/
typedef enum NIMU_IcssStatus_e {
    NIMU_STAT_UNKNOWN=0, /**< Unknown status */
    NIMU_STAT_DOWN,       /**< NDK driver is not up */
    NIMU_STAT_UP,         /**< NDK driver is up  */
    NIMU_STAT_PROGRESS  /**< Driver init in progress  */
} NIMU_IcssStatus;

/** 
 * @brief 
 *  Packet device information
 *
 * @details
 *  Packet device information
 */
typedef struct NIMU_IcssPdInfo_s 
{

    uint32_t            PhysIdx;      /**< Physical index of this device (0 to n-1) */
    void*          hEther;       /**< Handle to logical driver */
    void* hEvent;            /**< Semaphore handle used by NDK stack and driver to communicate any
                                         pending Rx events that need to be serviced by NDK ethernet stack */
    uint8_t           bMacAddr[6U];    /**< MAC Address*/
    uint32_t            Filter;            /**< Current RX filter */
    uint32_t            OldMCastCnt;    /**< Previous MCast Address Countr */
    uint8_t             bOldMCast[6U*NIMU_ICSS_MAX_MCAST];    /**< Previous Multicast list configured by the Application */
    uint32_t            MCastCnt;                    /**< Current MCast Address Countr */
    uint8_t           bMCast[6U*NIMU_ICSS_MAX_MCAST];    /**< Multicast list configured by the Application */
    uint32_t            TxFree;                        /**< Transmitter "free" flag */
    PBMQ            PBMQ_tx;                    /**< Tx queue (one for each PKT device) */
    PBMQ            PBMQ_rx;                     /**< Rx queue (one for each PKT device) */
    ICSS_EmacHandle nimuDrvHandle;                            /**< Stores any PRU sepecific data prussMemoryHandle_t */
} NIMU_IcssPdInfo;


/**
* @brief The EMAC Initialization Function
* @details The function is used to initialize and register the EMAC
*  with the Network Interface Management Unit (NIMU)
*
* @internal
*
* @param[in]  hEvent Stack Event Handle.
*
* @retval Success -   0
*         Error   -   <0
*/
int32_t NIMU_ICSS_EmacInit (STKEVENT_Handle hEvent);

/* For backward compatibility */
#define EmacInit  (NIMU_ICSS_EmacInit)


/**
* @brief The function is used to get the status of ndk driver
*
* @param[in]  instID Stack Driver instance(0 in the implementation)
*
* @retval ndk driver status
*/
uint32_t NIMU_ICSS_getNdkStatus(uint8_t instID);

/* For backward compatibility */
#define GetNdkStatus  (NIMU_ICSS_getNdkStatus)

#ifdef __cplusplus
}
#endif

#endif /* ICSS_NIMU_ETH_H_ */

