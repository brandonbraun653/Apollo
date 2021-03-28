/******************************************************************************
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *
 * \file   mcan_test.h
 *
 * \brief  This is the header file for mcan diagnostic test.
 *
 */

#ifndef _MCAN_TEST_H_
#define _MCAN_TEST_H_ 

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include <stdio.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/cslr_mcan.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/csl/csl_mcan.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#include "board.h"
#include "diag_common_cfg.h"

#if defined(SOC_J721E)
#include <ti/board/src/j721e_evm/include/board_pinmux.h>
#include "board_control.h"
#endif
#if !defined(am65xx_idk)
#include "board_i2c_io_exp.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#if defined(DIAG_STRESS_TEST) && ((defined(am65xx_idk)) || defined(SOC_J721E))
#define PKT_SEND_COUNT                  (10240U)
#else
#define PKT_SEND_COUNT                  (5U)
#endif

#define APP_MCAN_STD_ID_FILT_START_ADDR          (0U)
#define APP_MCAN_STD_ID_FILTER_NUM               (1U)
#define APP_MCAN_EXT_ID_FILT_START_ADDR          (48U)
#define APP_MCAN_EXT_ID_FILTER_NUM               (1U)
#define APP_MCAN_TX_EVENT_START_ADDR             (100U)
#define APP_MCAN_TX_EVENT_SIZE                   (5U)
#define APP_MCAN_TX_BUFF_START_ADDR              (148U)
#define APP_MCAN_TX_BUFF_SIZE                    (5U)
#define APP_MCAN_TX_FIFO_SIZE                    (5U)
#define APP_MCAN_FIFO_0_START_ADDR               (548U)
#define APP_MCAN_FIFO_0_NUM                      (5U)
#define APP_MCAN_FIFO_1_START_ADDR               (748U)
#define APP_MCAN_FIFO_1_NUM                      (5U)
#define APP_MCAN_RX_BUFF_START_ADDR              (948U)

#define APP_MCAN_TX_BUF_NUM                      (1U)

#define APP_MCAN_EXT_ID_AND_MASK                 (0x1FFFFFFFU)
#define MCAN_MAX_PAYLOAD_BYTES                   (64U)

#if defined(am65xx_idk)
#if defined (__aarch64__)
#define MCAN_DIAG_INTR_ENABLE                    (1)
#endif
#endif

#if defined(SOC_J721E)
#define MCAN_MAX_PORTS_EXP    (10U)
#define MCAN_MAX_PORTS_CP     (4U)
#define BOARD_NAME_LENGTH (12U)

/* Interrupt configurations */
#define MCU_MCAN0_TX_INT_NUM    (CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN0_MCANSS_MCAN_LVL_INT_0)
#define MCU_MCAN0_RX_INT_NUM    (CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN0_MCANSS_MCAN_LVL_INT_1)
#define MCU_MCAN0_TS_INT_NUM    (CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN0_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)

#define MCU_MCAN1_TX_INT_NUM    (CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN1_MCANSS_MCAN_LVL_INT_0)
#define MCU_MCAN1_RX_INT_NUM    (CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN1_MCANSS_MCAN_LVL_INT_1)
#define MCU_MCAN1_TS_INT_NUM    (CSLR_MCU_R5FSS0_CORE0_INTR_MCU_MCAN1_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)

#define MAIN_MCAN0_TX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN0_MCANSS_MCAN_LVL_INT_0)
#define MAIN_MCAN0_RX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN0_MCANSS_MCAN_LVL_INT_1)
#define MAIN_MCAN0_TS_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN0_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)

#define MAIN_MCAN2_TX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN2_MCANSS_MCAN_LVL_INT_0)
#define MAIN_MCAN2_RX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN2_MCANSS_MCAN_LVL_INT_1)
#define MAIN_MCAN2_TS_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN2_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)

#define MAIN_MCAN4_TX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN4_MCANSS_MCAN_LVL_INT_0)
#define MAIN_MCAN4_RX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN4_MCANSS_MCAN_LVL_INT_1)
#define MAIN_MCAN4_TS_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN4_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)

#define MAIN_MCAN5_TX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN5_MCANSS_MCAN_LVL_INT_0)
#define MAIN_MCAN5_RX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN5_MCANSS_MCAN_LVL_INT_1)
#define MAIN_MCAN5_TS_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN5_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)

#define MAIN_MCAN6_TX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN6_MCANSS_MCAN_LVL_INT_0)
#define MAIN_MCAN6_RX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN6_MCANSS_MCAN_LVL_INT_1)
#define MAIN_MCAN6_TS_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN6_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)

#define MAIN_MCAN7_TX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN7_MCANSS_MCAN_LVL_INT_0)
#define MAIN_MCAN7_RX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN7_MCANSS_MCAN_LVL_INT_1)
#define MAIN_MCAN7_TS_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN7_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)

#define MAIN_MCAN9_TX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN9_MCANSS_MCAN_LVL_INT_0)
#define MAIN_MCAN9_RX_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN9_MCANSS_MCAN_LVL_INT_1)
#define MAIN_MCAN9_TS_INT_NUM   (CSLR_R5FSS0_CORE0_INTR_MCAN9_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)

#define MAIN_MCAN11_TX_INT_NUM  (CSLR_R5FSS0_CORE0_INTR_MCAN11_MCANSS_MCAN_LVL_INT_0)
#define MAIN_MCAN11_RX_INT_NUM  (CSLR_R5FSS0_CORE0_INTR_MCAN11_MCANSS_MCAN_LVL_INT_1)
#define MAIN_MCAN11_TS_INT_NUM  (CSLR_R5FSS0_CORE0_INTR_MCAN11_MCANSS_EXT_TS_ROLLOVER_LVL_INT_0)
#else
#define MCAN_MAX_PORTS    (2U)
#endif
typedef struct mcanPortInfo
{
    uint32_t mcanBaseAddrs;
	uint8_t  mcanInstance;
    uint32_t mcanTxIntNum;
    uint32_t mcanRxIntNum;
    uint32_t mcanTsIntNum;
} mcanDiagportInfo;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

#if defined(MCAN_DIAG_INTR_ENABLE)

/**
 * \brief   This function will configure MCAN Tx interrupts
 *
 * \param   index  [IN]  - MCAN index number
 *
 */
static void BoardDiag_mcanTxIntrConfig(uint32_t index);

/**
 * \brief   This function will configure MCAN Rx interrupts
 *
 * \param   index  [IN]  - MCAN index number
 *
 */
static void BoardDiag_mcanRxIntrConfig(uint32_t index);

/**
 * \brief   This is Interrupt Service Routine for MCAN Tx interrupt.
 *
 */
static void BoardDiag_mcanTxIntrISR(void *handle);

/**
 * \brief   This is Interrupt Service Routine for MCAN Rx interrupt.
 *
 * \param   handle [IN/OUT] mcasp info structure
 *
 */
static void BoardDiag_mcanRxIntrISR(void *handle);

/**
 * \brief   This API will enables the TX interrupts
 *
 * \param   baseAddr  [IN]  MCAN base address
 *
 */
static int32_t BoardDiag_mcanTxIntEnable(uint32_t baseAddr);

/**
 * \brief   This API will enables the RX interrupts
 *
 * \param   baseAddr  [IN]  MCAN base address
 *
 */
static void BoardDiag_mcanRxIntEnable(uint32_t baseAddr);

/**
 * \brief   This API will disable the RX interrupts
 *
 * \param   baseAddr  [IN]  MCAN base address
 *
 */
static void BoardDiag_mcanRxIntDisable(uint32_t baseAddr);

/**
 * \brief   This API will disable the TX and RX interrupts
 *
 * \param   baseAddr  [IN]  MCAN base address
 *
 */
static void BoardDiag_mcanTxIntDisable(uint32_t baseAddr);


#endif

/**
 * \brief   This function will configure MCAN module
 *
 * \param   instance  [IN]  - MCAN instance number
 *
 * \return  int8_t
 *             0   - in case of success
 *            -1   - in case of failure
 *
 */
static int8_t BoardDiag_mcanConfig(uint8_t instance);

#if defined(BOARD_DEBUG_MCAN)
/**
 * \brief   This API will print MCAN Rx Msg.
 *
 */
static void BoardDiag_mcanPrintRxMsg(void);

/**
 * \brief   This API will print MCAN Tx Msg.
 *
 */
static void BoardDiag_mcanPrintTxMsg(void);
#endif

/**
 * \brief   This API will load the data to the message ram and checking
 *          the error status
 *
 * \param   instance  [IN]  - MCAN instance number
 *
 * \return  int8_t
 *             0   - in case of success
 *            -1   - in case of failure
 *
 */
static int8_t BoardDiag_mcanTxTest(uint8_t instance);

/**
 * \brief   This API will receive the data and compares with the transmit data
 *
 * \param   instance  [IN]  - MCAN instance number
 *
 * \return  int8_t
 *             0   - in case of success
 *            -1   - in case of failure
 *
 */
static int8_t BoardDiag_mcanRxTest(uint8_t instance);

/**
 * \brief   This function executes MCAN diagnostic test
 *
 * \return  int8_t
 *             0   - in case of success
 *            -1   - in case of failure
 *
 */
int8_t BoardDiag_McanTest(void);

/**
 * \brief   This API Initializes the GPIO module
 *
 * \param    gpioBaseAddrs [IN]  GPIO base address to configure
 * \param    port          [IN]  GPIO Port number
 *
 */
static void BoardDiag_mcanGpioConfig(uint32_t gpioBaseAddrs,uint32_t port);

#if defined(SOC_J721E)
/**
 * \brief   This function enables the Main CAN module and transceiver by setting
 *          the Enable and STB Pins
 *
 */
static void BoardDiag_mcanMainconfigs(void);
#endif

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MCAN_TEST_H_ */

