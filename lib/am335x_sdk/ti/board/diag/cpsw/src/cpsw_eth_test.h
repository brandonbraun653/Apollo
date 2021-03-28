/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   cpsw_eth_test.h
 *
 *  \brief  This file contains all Local definitions for CPSW 9G Ethernet test
 *          application.
 *
 */

#ifndef __CPSW_ETH_TEST_H__
#define __CPSW_ETH_TEST_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "board.h"
#include "board_cfg.h"
#include "board_ethernet_config.h"
#include "board_pinmux.h"
#include "board_control.h"

#include <ti/drv/sciclient/sciclient.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/osal/TimerP.h>
#include <ti/osal/osal.h>

#include <ti/drv/pm/include/dmsc/pmlib_clkrate.h>

#include <ti/drv/udma/udma.h>

#include <ti/drv/cpsw/cpsw.h>

#include <ti/drv/cpsw/soc/cpsw_soc.h>

#include <ti/drv/cpsw/include/cpsw_dma.h>
#include <ti/drv/cpsw/include/dp83867.h>
#include <ti/drv/cpsw/include/cpsw_queue.h>
#include <ti/drv/cpsw/include/cpsw_ale.h>
#include <ti/drv/cpsw/include/cpsw_cfg.h>
#include <ti/drv/cpsw/include/cpsw_types.h>
#include <ti/drv/cpsw/include/cpsw_rm.h>

#include <ti/drv/cpsw/examples/cpsw_apputils/inc/cpsw_apputils.h>
#include <ti/drv/cpsw/examples/cpsw_apputils/inc/cpsw_appsoc.h>
#include <ti/drv/cpsw/examples/cpsw_apputils/inc/cpsw_appmemutils_cfg.h>
#include <ti/drv/cpsw/examples/cpsw_apputils/inc/cpsw_appmemutils.h>
#include <ti/drv/cpsw/examples/cpsw_apputils/inc/cpsw_appboardutils.h>
#include <ti/drv/cpsw/examples/cpsw_apputils/inc/cpswapp_ethutils.h>

#include "diag_common_cfg.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

#define TEST_LEN                    (500U)

#define TEST_NUM_LOOP               (1U)
#define TEST_PTK_NUM                (128U)

#define PRG0_PORT_VERIFICATION      (1U)
#define PRG1_PORT_VERIFICATION      (2U)

#define CPSW_PHY_START_ADDRESS      (0U)
#define CPSW_PHY_END_ADDRESS        (31U)

typedef void *CpswApp_ClkHandle;

/**
 * \brief  CPSW device object structure
 */
typedef struct
{
    /* CPSW instance type */
    Cpsw_Type            cpswType;

    /* Core Id */
    uint32_t             coreId;
    /*Core Key */
    uint32_t             coreKey;

    /* MAC port number */
    Cpsw_MacPort         portNum0;

    /* MAC port number */
    Cpsw_MacPort         portNum1;

    /* CPSW driver handle */
    Cpsw_Handle          hCpsw;
    Udma_DrvHandle       hUdmaDrv;

    CpswDma_RxFlowHandle hRxFlow;
    CpswDma_PktInfoQ     rxFreeQ;
    CpswDma_PktInfoQ     rxReadyQ;

    CpswDma_TxChHandle   hTxCh;
    CpswDma_PktInfoQ     txFreePktInfoQ;

    /* TX Eth packet memory */
    uint8_t              txBufMem[CPSW_APPMEMUTILS_NUM_TX_PKTS][CPSWAPPUTILS_ALIGN(ETH_MAX_FRAME_LEN)]
                                __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
    /* TX DMA packet info memory */
    CpswDma_PktInfo      txFreePktInfo[CPSW_APPMEMUTILS_NUM_TX_PKTS];

    uint8_t              hostMacAddr[ETH_MAC_ADDR_LEN];

    uint8_t              hostMacAddr1[ETH_MAC_ADDR_LEN];

    /* Whether to print received Ethernet frames */
    bool printFrame;

    uint32_t             rxStartFlowIdx;

    uint32_t             rxFlowIdx;

    uint32_t             txChNum;
}cpsw_Obj;

/**
 *  \brief    This function runs CPSW9G ethernet test
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_CpswEthRunTest(void);

#ifdef __cplusplus
}
#endif
#endif /* __CPSW_ETH_TEST_H__ */
