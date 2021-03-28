/******************************************************************************
 * Copyright (c) 2016 - 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   emac_test.h
 *
 *  \brief  This file contains all Local definitions for EMAC test application.
 *
 */

#ifndef __EMAC_TEST_H__
#define __EMAC_TEST_H__

/* CSL Header files */
#include <string.h>
#if !(defined(SOC_J721E)) && !(defined(SOC_AM65XX))
#include <ti/csl/cslr_emac.h>
#include <ti/csl/csl_bootcfgAux.h>
#include <ti/csl/cslr_msmc.h>
#include <ti/csl/csl_cpsw.h>
#include <ti/csl/soc.h>
#include <ti/csl/csl_chip.h>
#include <ti/csl/cslr_xge_cpsw.h>
#include <ti/csl/cslr_ale.h>
#include <ti/csl/cslr_mdio.h>
#include <ti/csl/hw_types.h>
#else
#include <ti/csl/soc.h>
#include <ti/osal/osal.h>
#endif

#include "board.h"
#include "board_cfg.h"
#include "diag_common_cfg.h"
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* EMAC Driver Header File. */
#include <ti/drv/emac/emac_drv.h>
#if defined(SOC_K2G)
#include <ti/csl/csl_pscAux.h>
#include <ti/csl/csl_mdioAux.h>
#include <ti/board/src/iceK2G/include/iceK2G_ethernet_config.h>
#include <ti/drv/emac/soc/emac_soc_v1.h>
#else
#include <ti/board/src/j721e_evm/include/board_ethernet_config.h>
//#include <ti/drv/udma/udma.h>
#include <ti/drv/emac/soc/emac_soc_v5.h>
#include <ti/drv/emac/src/v5/emac_drv_v5.h>

#endif

#ifdef __cplusplus
extern "C" {
#endif
/**********************************************************************
 ************************** LOCAL Definitions *************************
 *********************************************************************/
#if defined(SOC_AM65XX) || defined(SOC_J721E)
/* local define until CSL get updated -begin*/
#define CPSW_STAT_PORT_EN_REG           (0x00020014U)
#define ALE_CONTROL_REG                 (0x0003E008U)
#define ALE_PORT0_CONTROL_REG           (0x0003E040U)
#define ALE_PORT1_CONTROL_REG           (0x0003E044U)
#define ENET_PN_MAC_CONTROL_REG         (0x00022330U)
#define ENET_PN_RX_MAXLEN_REG           (0x00022024U)
#define CPPI_P0_RX_MAXLEN_REG           (0x00021024U)
#define CPSW_CONTROL_REG                (0x00020004U)
#define MMR_LOCK1_KICK0_UNLOCK_VAL      (0x68EF3490U)
#define MMR_LOCK1_KICK1_UNLOCK_VAL      (0xD172BC5AU)
/* Ring definitions */
#define RING_TRCNT                      (128)   /* Number of ring entries */
/* Size (in bytes) of each ring entry (for 48-bit packet descriptor ptr) */
#define RING_TRSIZE                     (8U)
#define UDMAP_DESC_SIZE                 (128U)
#define CACHE_LINESZ                    (128U)
#endif

#ifdef DIAG_STRESS_TEST
#define PKT_SEND_COUNT                  (10240U)
#else
#define PKT_SEND_COUNT                  (10U)
#endif

/* Strap configuration Status register values */
#if defined(SOC_K2G)
#define EMAC_STRAP_STS1_VAL             (0x2000U)
#define EMAC_STRAP_STS2_VAL             (0x0U)
#define EMAC_MAX_NUM_EMAC_PORTS         (1U)
#else
#define EMAC_STRAP_STS1_VAL             (0x0U)
#define EMAC_STRAP_STS2_VAL             (0x0140U)
#endif


/* DO NOT CHANGE test_pkt UNLESS TEST_PKT_SIZE IS UPDATED */
#define TEST_PKT_SIZE                   (64U)

#define APP_NUM_HOST_DESC               (128U)

/**
 * @brief  Number of channels configured by a core on one port
 */
#define APP_EMAC_NUM_CHANS_PER_CORE     (1U)

/**
 * @brief  Number of EMAC MAC addresses configured per channel
 */
#define APP_EMAC_NUM_MACADDRS_PER_CHAN  (1U)
/**
 * @brief  Max EMAC packet size in bytes initialized for the driver
 */
#define APP_EMAC_INIT_PKT_SIZE           (128U)

/**
 * @brief  Max packet size in bytes used in the application,
 *         align to 128 byte cache line size
 */
#define APP_EMAC_MAX_PKT_SIZE            (256U)

/**
 * @brief  Total packet buffer size in bytes per core
 *
 */
#define APP_TOTAL_PKTBUF_SIZE           (EMAC_MAX_NUM_EMAC_PORTS*APP_MAX_PKTS* \
                                         APP_EMAC_MAX_PKT_SIZE)

/**
 * @brief  EMAC port 0 phy address
 */
#define APP_PORT0_PHY_ADDR              (0U) /* FOR NOW SET THIS TO 0 */

/**
 * @brief  Max number of packets in the application free packet queue
 *
 */
#define APP_MAX_PKTS                    (128U)

/**
 * @brief  Max number of packet descriptors per port initialized
 *         for driver managed RX queue
 */
#define APP_EMAC_INIT_RX_PKTS           (8*APP_EMAC_NUM_CHANS_PER_CORE)

/**
 * @brief  Max number of packet descriptors per port initialized
 *         for driver managed TX queue
 */
#define APP_EMAC_INIT_TX_PKTS           (APP_MAX_PKTS-APP_EMAC_INIT_RX_PKTS)

#define BOARD_DIAG_EMAC_TEST_TIMEOUT    (100U)

#define ENABLE_CABLE_DICONNECT_TEST     (TRUE)

/**
 * @brief
 *  Application Queue Data Structure
 */
typedef struct APP_PKT_QUEUE_tag
{
    uint32_t            Count;
    /**< Number of packets in queue */
    EMAC_PKT_DESC_T*  pHead;
    /**< Pointer to the first packet */
    EMAC_PKT_DESC_T*  pTail;
    /**< Pointer to the last packet */
} APP_PKT_QUEUE_T;

/**
 * @brief
 *  Core specific EMAC port control block
 *
 * @details
 *  Maintains the EMAC port control information of a core
 */
typedef struct APP_EMAC_PCB_tag
{
    Uint32                          emac_state;
    /**< EMAC Port state */
    Uint32                          phy_addr;
    /**< Physical layer transceiver address mapped to the EMAC port */
    EMAC_PKT_DESC_T                 pkt_desc[APP_MAX_PKTS];
    /**< Pre-allocated/initialized packet descriptiors for both free queue and RX queues */
    APP_PKT_QUEUE_T                 freeQueue;
    /**< Free packet descriptor queue, one queue per channel */
    APP_PKT_QUEUE_T                 rxQueue[APP_EMAC_NUM_CHANS_PER_CORE];
    /**< Received packet descriptor queue, one queue per channel */
    EMAC_MAC_ADDR_T                 mac_addr[APP_EMAC_NUM_CHANS_PER_CORE][APP_EMAC_NUM_MACADDRS_PER_CHAN];
    /**< MAC address for all the channels */

} APP_EMAC_PCB_T;

/**
 * @brief
 *  EMAC Master Control Block
 *
 * @details
 *  Maintains the EMAC control information and error statistics.
 */
typedef struct APP_EMAC_MCB_tag
{
    Uint32              core_num;
    /**< DSP core number */
    Uint32              timer_count;
    /**< 100 msec timer count */
    APP_EMAC_PCB_T      emac_pcb[EMAC_MAX_NUM_EMAC_PORTS];
    /**< EMAC port control block */
} APP_EMAC_MCB_T;

extern void BOARD_delay(uint32_t usecs);

/**
 * \brief  emac test function
 *
 * This function executes emac diagnostic test
 *
 * \param   port_num [IN]   EMAC port number
 *
 * \return  int8_t
 *              0  - in case of success
 *              1  - in case of failure
 */
int8_t BoardDiag_EmacTest(uint32_t port_num);

#ifdef __cplusplus
}
#endif
#endif /* __EMAC_TEST_H__ */
