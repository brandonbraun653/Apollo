/******************************************************************************
 * Copyright (c) 2018-2020 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   icssg_emac_test.h
 *
 *  \brief  This file contains all Local definitions for ICSSG EMAC diag
 *  application.
 *
 */

#ifndef __ICSSG_EMAC_TEST_H__
#define __ICSSG_EMAC_TEST_H__

/* CSL Header files */
#include <string.h>
#include <ti/csl/soc.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>
#include <ti/drv/udma/udma.h>
#include "diag_common_cfg.h"
#include "board_cfg.h"

/* EMAC Driver Header File. */
#include <ti/drv/emac/emac_drv.h>
#include <ti/drv/emac/soc/emac_soc_v5.h>
#include <ti/drv/emac/src/v5/emac_drv_v5.h>

/* PRUSS Driver Header File. */
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/soc/pruicss_v1.h>

/* ICSSG EMAC firmware header files PG1.0 */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rxl2_txl2_rgmii0_bin.h>      /* PDSPcode */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rtu_test0_bin.h>             /* PDSP2code */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rxl2_txl2_rgmii1_bin.h>      /*PDSP3code */
#include <ti/drv/emac/firmware/icss_dualmac/bin/rtu_test1_bin.h>             /* PDSP4code */

/* ICSSG EMAC firmware header files PG2.0 */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/rxl2_rgmii0_bin.h>      /* PDSPcode */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/rtu_test0_bin.h>        /* PDSP2code */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/rxl2_rgmii1_bin.h>      /* PDSP3code */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/rtu_test1_bin.h>        /* PDSP4code */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/txl2_rgmii0_bin.h>      /* PDSP5code */
#include <ti/drv/emac/firmware/icss_dualmac/bin_pg2/txl2_rgmii1_bin.h>      /* PDSP6code */

/* EMAC firmware config header files */
#include <ti/drv/emac/firmware/icss_dualmac/config/emac_fw_config_dual_mac.h>

#ifdef __cplusplus
extern "C" {
#endif

extern void BOARD_delay(uint32_t usecs);

/**********************************************************************
 ************************** LOCAL Definitions *************************
 **********************************************************************/
#define BOARD_DIAG_ICSS_EMAC_MAX_PORTS_PER_INSTANCE     ((uint32_t)2U)
#define BOARD_DIAG_ICSS_EMAC_MAX_INTANCES               ((uint32_t)3U)
#define BOARD_DIAG_ICSS_EMAC_MAX_PORTS                  ((BOARD_DIAG_ICSS_EMAC_MAX_INTANCES)*(BOARD_DIAG_ICSS_EMAC_MAX_PORTS_PER_INSTANCE))

#define BOARD_DIAG_ICSS_EMAC_LINK_TIMEOUT_COUNT               (100U)

/* Ring definitions */
#define BOARD_DIAG_ICSS_EMAC_RING_TRCNT                      (128U)   /* Number of ring entries */
/* Size (in bytes) of each ring entry (for 48-bit packet descriptor ptr) */
#define BOARD_DIAG_ICSS_EMAC_RING_TRSIZE                     (8U)
#define BOARD_DIAG_ICSS_EMAC_UDMAP_DESC_SIZE                 (128U)
#define BOARD_DIAG_ICSS_EMAC_CACHE_LINESZ                    (128U)

#ifdef DIAG_STRESS_TEST
#define BOARD_DIAG_ICSS_EMAC_PKT_SEND_COUNT         (10240U)
#else
#define BOARD_DIAG_ICSS_EMAC_PKT_SEND_COUNT         (5U)
#endif

/* DO NOT CHANGE test_pkt UNLESS BOARD_DIAG_ICSS_EMAC_TEST_PKT_SIZE IS UPDATED */
#define BOARD_DIAG_ICSS_EMAC_TEST_PKT_SIZE          (64U)

#define BOARD_DIAG_ICSS_EMAC_NUM_HOST_DESC          (128U)

/**
 * @brief  Number of channels configured by a core on one port
 */
#define BOARD_DIAG_ICSS_EMAC_NUM_CHANS_PER_CORE     (1U)

/**
 * @brief  Number of EMAC MAC addresses configured per channel
 */
#define BOARD_DIAG_ICSS_EMAC_NUM_MACADDRS_PER_CHAN  (1U)
/**
 * @brief  Max EMAC packet size in bytes initialized for the driver
 */
#define BOARD_DIAG_ICSS_EMAC_INIT_PKT_SIZE          (128U)

/**
 * @brief  Max packet size in bytes used in the application,
 *         align to 128 byte cache line size
 */
#define BOARD_DIAG_ICSS_EMAC_MAX_PKT_SIZE           (128U)

/**
 * @brief  Total packet buffer size in bytes per core
 *
 */
#define BOARD_DIAG_ICSS_EMAC_TOTAL_PKTBUF_SIZE      (BOARD_DIAG_ICSS_EMAC_MAX_PORTS*BOARD_DIAG_ICSSG_EMAC_MAX_PKTS* \
                                                    BOARD_DIAG_ICSS_EMAC_MAX_PKT_SIZE)

/**
 * @brief  Max number of packets in the application free packet queue
 *
 */
#define BOARD_DIAG_ICSSG_EMAC_MAX_PKTS              (64U)

/**
 * @brief  Max number of packet descriptors per port initialized
 *         for driver managed RX queue
 */
#define BOARD_DIAG_ICSS_EMAC_INIT_RX_PKTS           (8*BOARD_DIAG_ICSS_EMAC_NUM_CHANS_PER_CORE)

/**
 * @brief  Max number of packet descriptors per port initialized
 *         for driver managed TX queue
 */
#define BOARD_DIAG_ICSS_EMAC_INIT_TX_PKTS           (BOARD_DIAG_ICSSG_EMAC_MAX_PKTS-BOARD_DIAG_ICSS_EMAC_INIT_RX_PKTS)

/* Number of TX packet descriptor */
#define BOARD_DIAG_ICSS_EMAC_TX_PKT_DESC_COUNT          (16U)

/* Number of RX packet descriptor */
#define BOARD_DIAG_ICSS_EMAC_RX_PKT_DESC_COUNT          (16U)

#define BOARD_DIAG_ICSS_EMAC_REG_DUMP_MAX    (16U)

#define BOARD_DIAG_ICSSEMAC_TEST_TIMEOUT   (100U)
#define TX_BUFF_POOL_SIZE (0X1800U)
#define TX_BUFF_POOL_TOTAL_DUAL_MAC (TX_BUFF_POOL_SIZE + 0x80U) * 8U
#define TX_BUFF_POOL_NUM (16U)

#define BOARD_ICSS_EMAC_APP_BOARDID_ADDR   (0x52U)
#define BOARD_ICSS_MAX_PORTS_IDK           (4U)

typedef struct BOARD_DIAG_MDIO_INFO_tag
{
    uint32_t mdioBaseAddrs;
    uint8_t  phyAddrs;
    uint16_t strapst1;
    uint16_t strapst2;
} BOARD_DIAG_MDIO_INFO_T;

/**
 * @brief
 *  Application Queue Data Structure
 */
typedef struct BOARD_DIAG_ICSSG_EMAC_PKT_QUEUE_tag
{
    uint32_t            Count;
    /**< Number of packets in queue */
    EMAC_PKT_DESC_T*  pHead;
    /**< Pointer to the first packet */
    EMAC_PKT_DESC_T*  pTail;
    /**< Pointer to the last packet */
} BOARD_DIAG_ICSSG_EMAC_PKT_QUEUE_T;

/**
 * @brief
 *  Core specific EMAC port control block
 *
 * @details
 *  Maintains the EMAC port control information of a core
 */
typedef struct BOARD_DIAG_ICSSG_EMAC_EMAC_PCB_tag
{
    Uint32                          emac_state;
    /**< EMAC Port state */
    Uint32                          phy_addr;
    /**< Physical layer transceiver address mapped to the EMAC port */
    EMAC_PKT_DESC_T                 pkt_desc[BOARD_DIAG_ICSSG_EMAC_MAX_PKTS];
    /**< Pre-allocated/initialized packet descriptiors for both free queue and RX queues */
    BOARD_DIAG_ICSSG_EMAC_PKT_QUEUE_T                 freeQueue;
    /**< Free packet descriptor queue, one queue per channel */
    BOARD_DIAG_ICSSG_EMAC_PKT_QUEUE_T                 rxQueue[BOARD_DIAG_ICSS_EMAC_NUM_CHANS_PER_CORE];
    /**< Received packet descriptor queue, one queue per channel */
    EMAC_MAC_ADDR_T                 mac_addr[BOARD_DIAG_ICSS_EMAC_NUM_CHANS_PER_CORE][BOARD_DIAG_ICSS_EMAC_NUM_MACADDRS_PER_CHAN];
    /**< MAC address for all the channels */

} BOARD_DIAG_ICSSG_EMAC_EMAC_PCB_T;

/**
 * @brief
 *  EMAC Master Control Block
 *
 * @details
 *  Maintains the EMAC control information and error statistics.
 */
typedef struct BOARD_DIAG_ICSSG_EMAC_MCB_tag
{
    Uint32              core_num;
    /**< DSP core number */
    Uint32              timer_count;
    /**< 100 msec timer count */
    BOARD_DIAG_ICSSG_EMAC_EMAC_PCB_T      emac_pcb[EMAC_MAX_NUM_EMAC_PORTS];
    /**< EMAC port control block */
} BOARD_DIAG_ICSSG_EMAC_MCB_T;

typedef struct BOARD_DIAG_ICSSG_EMAC_PRUICSS_FW_tag {
    const uint32_t *pru;
    uint32_t pru_size;
    const uint32_t *rtu;
    uint32_t rtu_size;
    const uint32_t *txpru;
    uint32_t txpru_size;
} BOARD_DIAG_ICSSG_EMAC_PRUICSS_FW_T;

/**
 * \brief  ICSSG emac test function
 *
 * This function executes emac diagnostic test
 *
 * \return  int8_t
 *              0  - in case of success
 *              1  - in case of failure
 */
int8_t BoardDiag_IcssgEmacTest(void);

/**
* \brief  ICSSG emac test function
*
* This function executes emac diagnostic test with interposer card
*
* \return  int8_t
*              0  - in case of success
*              1  - in case of failure
*/
int8_t BoardDiag_IcssgEmacTestInterposer(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __ICSSG_EMAC_TEST_H__ */

