/******************************************************************************
 * Copyright (c) 2020 Texas Instruments Incorporated - http://www.ti.com
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
 * \file   fpd_csi_test.h
 *
 * \brief  This is the header file for fpd lib test *
 */
#ifndef _FPD_CSI_TEST_H_
#define _FPD_CSI_TEST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "fpd_common.h"

#define I2C_DEVICE_ID_REG_CMP_MASK                              (uint8_t)BOARD_FPD_UB9702_DEVICE_ID_BIT_MASK
#define GENERAL_CFG_REG_CMP_MASK                                (uint8_t)(BOARD_FPD_UB9702_I2C_MASTER_EN_BIT_MASK | BOARD_FPD_UB9702_OUTPUT_EN_MODE_BIT_MASK | BOARD_FPD_UB9702_OUTPUT_ENABLE_BIT_MASK | BOARD_FPD_UB9702_OUTPUT_SLEEP_STATE_SEL_BIT_MASK)
#define BCC_WATCHDOG_CONTROL_REG_CMP_MASK                       (uint8_t)BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_BIT_MASK
#define RX_PORT_CTL_REG_CMP_MASK                                (uint8_t)(BOARD_FPD_UB9702_BCC3_MAP_BIT_MASK | BOARD_FPD_UB9702_BCC2_MAP_BIT_MASK | BOARD_FPD_UB9702_BCC1_MAP_BIT_MASK | BOARD_FPD_UB9702_BCC0_MAP_BIT_MASK | BOARD_FPD_UB9702_PORT3_EN_BIT_MASK | BOARD_FPD_UB9702_PORT2_EN_BIT_MASK | BOARD_FPD_UB9702_PORT1_EN_BIT_MASK | BOARD_FPD_UB9702_PORT0_EN_BIT_MASK)
#define IO_CTL_REG_CMP_MASK                                     (uint8_t)(BOARD_FPD_UB9702_SEL3P3V_BIT_MASK | BOARD_FPD_UB9702_IO_SUPPLY_MODE_OV_BIT_MASK | BOARD_FPD_UB9702_IO_SUPPLY_MODE_BIT_MASK)
#define FS_CTL_REG_CMP_MASK                                     (uint8_t)(BOARD_FPD_UB9702_FS_MODE_BIT_MASK | BOARD_FPD_UB9702_FS_GEN_ENABLE_BIT_MASK)
#define FS_HIGH_TIME_1_REG_CMP_MASK                             (uint8_t)(0xFF)
#define FS_HIGH_TIME_0_REG_CMP_MASK                             (uint8_t)(0xFF)
#define FS_LOW_TIME_1_REG_CMP_MASK                              (uint8_t)(0xFF)
#define FS_LOW_TIME_0_REG_CMP_MASK                              (uint8_t)(0xFF)
#define MAX_FRM_HI_REG_CMP_MASK                                 (uint8_t)(0xFF)
#define MAX_FRM_LO_REG_CMP_MASK                                 (uint8_t)(0xFF)
#define CSI_PLL_CTL_REG_CMP_MASK                                (uint8_t)(BOARD_FPD_UB9702_SEL_OSC_200M_BIT_MASK | BOARD_FPD_UB9702_REF_CLK_MODE_BIT_MASK | BOARD_FPD_UB9702_CSI_TX_SPEED_BIT_MASK)
#define FWD_CTL1_REG_CMP_MASK                                   (uint8_t)(BOARD_FPD_UB9702_FWD_PORT3_DIS_BIT_MASK | BOARD_FPD_UB9702_FWD_PORT2_DIS_BIT_MASK | BOARD_FPD_UB9702_FWD_PORT1_DIS_BIT_MASK |BOARD_FPD_UB9702_FWD_PORT0_DIS_BIT_MASK | BOARD_FPD_UB9702_RX3_MAP_BIT_MASK | BOARD_FPD_UB9702_RX2_MAP_BIT_MASK | BOARD_FPD_UB9702_RX1_MAP_BIT_MASK | BOARD_FPD_UB9702_RX0_MAP_BIT_MASK)
#define CSI_PORT_SEL_REG_CMP_MASK                               (uint8_t)(BOARD_FPD_UB9702_TX_READ_PORT_BIT_MASK | BOARD_FPD_UB9702_TX_WRITE_PORT_1_BIT_MASK | BOARD_FPD_UB9702_TX_WRITE_PORT_0_BIT_MASK)
#define CSI_CTL_REG_CMP_MASK                                    (uint8_t)(BOARD_FPD_UB9702_CSI_LANE_COUNT_BIT_MASK | BOARD_FPD_UB9702_CSI_CONTS_CLOCK_BIT_MASK | BOARD_FPD_UB9702_CSI_ENABLE_BIT_MASK)
#define CSI_CTL2_REG_CMP_MASK                                   (uint8_t)BOARD_FPD_UB9702_CSI_PASS_MODE_BIT_MASK
#define FPD3_PORT_SEL_REG_CMP_MASK                              (uint8_t)(BOARD_FPD_UB9702_RX_READ_PORT_BIT_MASK | BOARD_FPD_UB9702_RX_WRITE_PORT_3_BIT_MASK | BOARD_FPD_UB9702_RX_WRITE_PORT_2_BIT_MASK | BOARD_FPD_UB9702_RX_WRITE_PORT_1_BIT_MASK | BOARD_FPD_UB9702_RX_WRITE_PORT_0_BIT_MASK)
#define BCC_CONFIG_REG_CMP_MASK                                 (uint8_t)(BOARD_FPD_UB9702_I2C_PASS_THROUGH_ALL_BIT_MASK | BOARD_FPD_UB9702_I2C_PASS_THROUGH_BIT_MASK | BOARD_FPD_UB9702_AUTO_ACK_ALL_BIT_MASK | BOARD_FPD_UB9702_BC_ALWAYS_ON_BIT_MASK | BOARD_FPD_UB9702_BC_FREQ_SELECT_BIT_MASK)

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _FPD_CSI_TEST_H_ */
