/*
 * Copyright (C) 2008-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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

/**
 *   @file  nimu_eth.h
 *
 *   @brief
 *      Network Interface Module Ethernet driver adaptation layer
 *
 */


#ifndef _NIMU_ETH_H_
#define _NIMU_ETH_H_

/* Standard C-native includes  */
#include <stdlib.h>
#include <string.h>

#include <ti/csl/tistdtypes.h>
#include <ti/drv/emac/emac_drv.h>
#include <ti/ndk/inc/stkmain.h>
#include <ti/csl/cslr_device.h>

#ifdef __cplusplus
extern "C" {
#endif

#define NIMU_LIB_VERSION "1.00.00.01"

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
#define     PKT_PREPAD                      8

/* Indicates whether RAM based multicast lists are suported for this
 * EMAC peripheral.
 */
#define     RAM_MCAST                       0

/* Indicates whether HASH based multicasting is suported for this
 * EMAC peripheral.
 */
#define     HASH_MCAST                      0

/* Multicast Address List Size */
#define     PKT_MAX_MCAST                   31

/* Rx queue (one for all PKT devices) */
#if 1
//#ifndef _INCLUDE_NIMU_CODE
extern PBMQ    PBMQ_rx;
#endif

#define NIMU_NUM_EMAC_PORTS                 2

#define NIMU_PORT_NUM_USED                  0

/**
 * @brief   Number of channels configured by a core on one port
 */
#define     NIMU_EMAC_NUM_CHANS_PER_CORE    1

/**
 * @brief   Number of MAC addresses configured per channel
 */
#define     NIMU_EMAC_NUM_MACADDRS_PER_CHAN 1

/**
 * @brief   Max number of packet descriptors initialized
 *          for EMAC TX/RX queue per port
 */
#define     NIMU_MAX_EMAC_INIT_PKTS         64

/**
 * @brief   Max number of packet descriptors per port initialized
 *          for driver managed RX queue
 */
#define     NIMU_EMAC_INIT_RX_PKTS          (16*NIMU_EMAC_NUM_CHANS_PER_CORE)

/**
 * @brief   Max number of packet descriptors per port initialized
 *          for driver managed TX queue
 */
#define     NIMU_EMAC_INIT_TX_PKTS          (NIMU_MAX_EMAC_INIT_PKTS-NIMU_EMAC_INIT_RX_PKTS)


/**
 * @brief   EMAC packet size in bytes
 */
#define     NIMU_EMAC_PKT_SIZE              1518



/*@{*/
#define NIMU_CPPI_HW_SEM            1               /**< CPPI Driver - Used by OSAL layer */
#define NIMU_QMSS_HW_SEM            2              /**< QMSS Driver - Used by OSAL Layer */
#define NIMU_SPI_HW_SEM             3               /**< SPI BUS arbitration - Used by platform library */
/*@}*/  /* defgroup */

#define CACHE_LINESZ (128)


/**
 * @brief   EMAC TX/RX Interrupt Definitions
 */

/* Consecutive interrupts are used for TX and RX */
#define     NIMU_EMAC0_INT_VAL          9
/* Setting flag for consecutive interrupts */
#define     NIMU_EMAC0_INT_FLAG         (3<<NIMU_EMAC0_INT_VAL)
/* Consecutive interrupts are used for TX and RX */
#define     NIMU_EMAC1_INT_VAL          11
/* Setting flag for consecutive interrupts */
#define     NIMU_EMAC1_INT_FLAG         (3<<NIMU_EMAC1_INT_VAL)

/**
 * @brief   External memory start address
 */
#if defined(EVMC6474) | defined(C6657)
#define     EMAC_EXTMEM                          0x80000000
#else
#define     EMAC_EXTMEM                          0xe0000000
#endif

#if defined(C6657) || defined(SOC_C6657)
#define EMAC_MSMCMEM 		0x0C000000
#endif

/**
 * @brief
 *  Packet device information
 *
 * @details
 *  This structure caches the device info.
 */
typedef struct _pdinfo
{
    /**
     * @brief       Physical index of this device (0 to n-1).
     */
    uint32_t            PhysIdx;
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
    uint8_t           bMacAddr[6];
    /*
     * @brief       Current RX filter
     */
    uint32_t            Filter;
    /*
     * @brief       Current MCast Address Countr
     */
    uint32_t            MCastCnt;
    /*
     * @brief       Multicast list configured by the Application.
     */
    uint8_t           bMCast[6*PKT_MAX_MCAST];
    /*
     * @brief       Transmitter "free" flag
     */
    uint32_t            TxFree;
    /*
     * @brief       Tx queue (one for each PKT device)
     */
    PBMQ            PBMQ_tx;

    /*
     * @brief       Raw Pkt Tx queue (one for each PKT device)
     */
    PBMQ            PBMQ_rawtx;

//#ifdef _INCLUDE_NIMU_CODE
#if 1
    /*
     * @brief       Rx queue (one for each PKT device)
     */
    PBMQ            PBMQ_rx;

    /*
     * @brief       Raw Pkt Rx queue (one for each PKT device)
     */
	PBMQ        PBMQ_rawrx;
#endif
} PDINFO;

/**
 * @brief
 *   EMAC_DATA
 *
 * @details
 *  The structure is used to store the private data for the
 *  EMAC controller.
 */
typedef struct EMAC_DATA
{
/**
  * @brief   Private Information
  */
    PDINFO      pdi;
}EMAC_DATA;


cregister volatile unsigned int  IER;

/* The EMAC Initialization Function. */
static int EmacInit (STKEVENT_Handle hEvent);
static int EMACInit_Core (STKEVENT_Handle hEvent);

static EMAC_PKT_DESC_T*
EmacAllocPkt
(
    uint32_t              port_num,
    uint32_t              pkt_size
);

static void
EmacFreePkt
(
    uint32_t              port_num,
    EMAC_PKT_DESC_T*    p_desc
);

static void
EmacRxPkt
(
    uint32_t              port_num,
    EMAC_PKT_DESC_T*    p_desc
);

extern void
Osal_emacEnterSingleCoreCriticalSection
(
    uint32_t      port_num
);

extern void
Osal_emacExitSingleCoreCriticalSection
(
    uint32_t      port_num
);

#ifdef __cplusplus
}
#endif

#endif /* _NIMU_ETH_H_ */
