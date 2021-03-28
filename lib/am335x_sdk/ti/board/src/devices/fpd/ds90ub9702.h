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
 * \file  ds90ub9702.h
 *
 * \brief This file includes the structures, enums and register offsets
 *        for configuring the ds90ub9702 deserailizer hub.
 *
 */

#ifndef _DS90UB9702_H_
#define _DS90UB9702_H_

#include <ti/board/src/devices/common/common.h>

#ifdef __cplusplus
extern "C" {
#endif

#define BOARD_FPD_UB9702_I2C_DEVICE_ID_REG_ADDR                 (0x00U)
#define BOARD_FPD_UB9702_RESET_CTL_REG_ADDR                     (0x01U)
#define BOARD_FPD_UB9702_GENERAL_CFG_REG_ADDR                   (0x02U)

#define BOARD_FPD_UB9702_BCC_WATCHDOG_CONTROL_REG_ADDR          (0x07U)
#define BOARD_FPD_UB9702_RX_PORT_CTL_REG_ADDR                   (0x0CU)
#define BOARD_FPD_UB9702_IO_CTL_REG_ADDR                        (0x0DU)

#define BOARD_FPD_UB9702_FS_CTL_REG_ADDR                        (0x18U)
#define BOARD_FPD_UB9702_FS_HIGH_TIME_1_REG_ADDR                (0x19U)
#define BOARD_FPD_UB9702_FS_HIGH_TIME_0_REG_ADDR                (0x1AU)
#define BOARD_FPD_UB9702_FS_LOW_TIME_1_REG_ADDR                 (0x1BU)
#define BOARD_FPD_UB9702_FS_LOW_TIME_0_REG_ADDR                 (0x1CU)
#define BOARD_FPD_UB9702_MAX_FRM_HI_REG_ADDR                    (0x1DU)
#define BOARD_FPD_UB9702_MAX_FRM_LO_REG_ADDR                    (0x1EU)
#define BOARD_FPD_UB9702_CSI_PLL_CTL_REG_ADDR                   (0x1FU)
#define BOARD_FPD_UB9702_FWD_CTL1_REG_ADDR                      (0x20U)
#define BOARD_FPD_UB9702_FWD_CTL2_REG_ADDR                      (0x21U)
#define BOARD_FPD_UB9702_FWD_STS_REG_ADDR                       (0x22U)

#define BOARD_FPD_UB9702_CSI_PORT_SEL_REG_ADDR                  (0x32U)
#define BOARD_FPD_UB9702_CSI_CTL_REG_ADDR                       (0x33U)
#define BOARD_FPD_UB9702_CSI_CTL2_REG_ADDR                      (0x34U)
#define BOARD_FPD_UB9702_CSI_STS_REG_ADDR                       (0x35U)


#define BOARD_FPD_UB9702_FPD3_PORT_SEL_REG_ADDR                 (0x4CU)

#define BOARD_FPD_UB9702_BCC_STATUS_REG_ADDR                    (0x47U)
#define BOARD_FPD_UB9702_BCC_CONFIG_REG_ADDR                    (0x58U)

#define BOARD_FPD_UB9702_SER_ID_REG_ADDR                        (0x5BU)
#define BOARD_FPD_UB9702_SER_ALIAS_ID_REG_ADDR                  (0x5CU)

#define BOARD_FPD_UB9702_SlaveID_0_REG_ADDR                     (0x5DU)
#define BOARD_FPD_UB9702_SlaveID_1_REG_ADDR                     (0x5EU)
#define BOARD_FPD_UB9702_SlaveID_2_REG_ADDR                     (0x5FU)
#define BOARD_FPD_UB9702_SlaveID_3_REG_ADDR                     (0x60U)
#define BOARD_FPD_UB9702_SlaveID_4_REG_ADDR                     (0x61U)
#define BOARD_FPD_UB9702_SlaveID_5_REG_ADDR                     (0x62U)
#define BOARD_FPD_UB9702_SlaveID_6_REG_ADDR                     (0x63U)
#define BOARD_FPD_UB9702_SlaveID_7_REG_ADDR                     (0x64U)
#define BOARD_FPD_UB9702_SlaveAlias_0_REG_ADDR                  (0x65U)
#define BOARD_FPD_UB9702_SlaveAlias_1_REG_ADDR                  (0x66U)
#define BOARD_FPD_UB9702_SlaveAlias_2_REG_ADDR                  (0x67U)
#define BOARD_FPD_UB9702_SlaveAlias_3_REG_ADDR                  (0x68U)
#define BOARD_FPD_UB9702_SlaveAlias_4_REG_ADDR                  (0x69U)
#define BOARD_FPD_UB9702_SlaveAlias_5_REG_ADDR                  (0x6AU)
#define BOARD_FPD_UB9702_SlaveAlias_6_REG_ADDR                  (0x6BU)
#define BOARD_FPD_UB9702_SlaveAlias_7_REG_ADDR                  (0x6CU)

/** I2C_DEVICE_ID Register Field */
#define BOARD_FPD_UB9702_DEVICE_ID_SHIFT_CNT                    (0x01U)
#define BOARD_FPD_UB9702_DES_ID_SHIFT_CNT                       (0x00U)

/** I2C_DEVICE_ID Register Field */
#define BOARD_FPD_UB9702_DIGITAL_RESET1_SHIFT_CNT               (0x01U)
#define BOARD_FPD_UB9702_DIGITAL_RESET0_SHIFT_CNT               (0x00U)

/** GENERAL_CFG Register Field */
#define BOARD_FPD_UB9702_I2C_MASTER_EN_SHIFT_CNT                (0x05U)
#define BOARD_FPD_UB9702_OUTPUT_EN_MODE_SHIFT_CNT               (0x04U)
#define BOARD_FPD_UB9702_OUTPUT_ENABLE_SHIFT_CNT                (0x03U)
#define BOARD_FPD_UB9702_OUTPUT_SLEEP_STATE_SEL_SHIFT_CNT       (0x02U)
#define BOARD_FPD_UB9702_RX_PARITY_CHECK_EN_SHIFT_CNT           (0x01U)
#define BOARD_FPD_UB9702_FORCE_REFCLK_DET_SHIFT_CNT             (0x00U)

/** BCC_Watchdog_Control Register Fields */
#define BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_SHIFT_CNT           (0x01U)
#define BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_DISABLE_SHIFT_CNT   (0x00U)

/** SCL_High_Time Register Fields */
#define BOARD_FPD_UB9702_SCL_HIGH_TIME_SHIFT_CNT                (0x00U)
/** SCL_Low_Time Register Fields */
#define BOARD_FPD_UB9702_SCL_LOW_TIME_SHIFT_CNT                 (0x00U)

/** RX_PORT_CTL Register Fields */
#define BOARD_FPD_UB9702_BCC3_MAP_SHIFT_CNT                     (0x07U)
#define BOARD_FPD_UB9702_BCC2_MAP_SHIFT_CNT                     (0x06U)
#define BOARD_FPD_UB9702_BCC1_MAP_SHIFT_CNT                     (0x05U)
#define BOARD_FPD_UB9702_BCC0_MAP_SHIFT_CNT                     (0x04U)
#define BOARD_FPD_UB9702_PORT3_EN_SHIFT_CNT                     (0x03U)
#define BOARD_FPD_UB9702_PORT2_EN_SHIFT_CNT                     (0x02U)
#define BOARD_FPD_UB9702_PORT1_EN_SHIFT_CNT                     (0x01U)
#define BOARD_FPD_UB9702_PORT0_EN_SHIFT_CNT                     (0x00U)

/** IO_CTL Register Fields */
#define BOARD_FPD_UB9702_SEL3P3V_SHIFT_CNT                      (0x07U)
#define BOARD_FPD_UB9702_IO_SUPPLY_MODE_OV_SHIFT_CNT            (0x06U)
#define BOARD_FPD_UB9702_IO_SUPPLY_MODE_SHIFT_CNT               (0x04U)

/** FS_CTL Register Fields */
#define BOARD_FPD_UB9702_FS_MODE_SHIFT_CNT                      (0x04U)
#define BOARD_FPD_UB9702_FS_SINGLE_SHIFT_CNT                    (0x03U)
#define BOARD_FPD_UB9702_FS_INIT_STATE_SHIFT_CNT                (0x02U)
#define BOARD_FPD_UB9702_FS_GEN_MODE_SHIFT_CNT                  (0x01U)
#define BOARD_FPD_UB9702_FS_GEN_ENABLE_SHIFT_CNT                (0x00U)

/** FS_HIGH_TIME_1 Register Field */
#define BOARD_FPD_UB9702_FRAMESYNC_HIGH_TIME_1_SHIFT_CNT        (0x00U)

/** FS_HIGH_TIME_0 Register Field */
#define BOARD_FPD_UB9702_FRAMESYNC_HIGH_TIME_0_SHIFT_CNT        (0x00U)

/** FS_LOW_TIME_1 Register Field */
#define BOARD_FPD_UB9702_FRAMESYNC_LOW_TIME_1_SHIFT_CNT         (0x00U)

/** FS_LOW_TIME_0 Register Field */
#define BOARD_FPD_UB9702_FRAMESYNC_LOW_TIME_1_SHIFT_CNT         (0x00U)

/** MAX_FRM_HI Register Field */
#define BOARD_FPD_UB9702_MAX_FRM_HI_SHIFT_CNT                   (0x00U)

/** MAX_FRM_LO Register Field */
#define BOARD_FPD_UB9702_MAX_FRM_LO_SHIFT_CNT                   (0x00U)

/** CSI_PLL_CTL Register Fields */
#define BOARD_FPD_UB9702_SEL_OSC_200M_SHIFT_CNT                 (0x03U)
#define BOARD_FPD_UB9702_REF_CLK_MODE_SHIFT_CNT                 (0x02U)
#define BOARD_FPD_UB9702_CSI_TX_SPEED_SHIFT_CNT                 (0x00U)

/** FWD_CTL1 Register Fields */
#define BOARD_FPD_UB9702_FWD_PORT3_DIS_SHIFT_CNT                (0x07U)
#define BOARD_FPD_UB9702_FWD_PORT2_DIS_SHIFT_CNT                (0x06U)
#define BOARD_FPD_UB9702_FWD_PORT1_DIS_SHIFT_CNT                (0x05U)
#define BOARD_FPD_UB9702_FWD_PORT0_DIS_SHIFT_CNT                (0x04U)
#define BOARD_FPD_UB9702_RX3_MAP_SHIFT_CNT                      (0x03U)
#define BOARD_FPD_UB9702_RX2_MAP_SHIFT_CNT                      (0x02U)
#define BOARD_FPD_UB9702_RX1_MAP_SHIFT_CNT                      (0x01U)
#define BOARD_FPD_UB9702_RX0_MAP_SHIFT_CNT                      (0x00U)

/** FWD_CTL2 Register Fields */
#define BOARD_FPD_UB9702_FWD_SYNC_AS_AVAIL_SHIFT_CNT            (0x06U)
#define BOARD_FPD_UB9702_CSI1_SYNC_FWD_SHIFT_CNT                (0x04U)
#define BOARD_FPD_UB9702_CSI0_SYNC_FWD_SHIFT_CNT                (0x02U)
#define BOARD_FPD_UB9702_CSI1_RR_FWD_SHIFT_CNT                  (0x01U)
#define BOARD_FPD_UB9702_CSI0_RR_FWD_SHIFT_CNT                  (0x00U)

/** FWD_STS Register Fields */
#define BOARD_FPD_UB9702_FWD_SYNC_FAIL1_SHIFT_CNT               (0x03U)
#define BOARD_FPD_UB9702_FWD_SYNC_FAIL0_SHIFT_CNT               (0x02U)
#define BOARD_FPD_UB9702_FWD_SYNC1_SHIFT_CNT                    (0x01U)
#define BOARD_FPD_UB9702_FWD_SYNC0_SHIFT_CNT                    (0x00U)

/** CSI_PORT_SEL Register Fields */
#define BOARD_FPD_UB9702_TX_READ_PORT_SHIFT_CNT                 (0x04U)
#define BOARD_FPD_UB9702_TX_WRITE_PORT_1_SHIFT_CNT              (0x01U)
#define BOARD_FPD_UB9702_TX_WRITE_PORT_0_SHIFT_CNT              (0x00U)

/** CSI_CTL Register Fields */
#define BOARD_FPD_UB9702_CSI_CAL_EN_SHIFT_CNT                   (0x06U)
#define BOARD_FPD_UB9702_CSI_LANE_COUNT_SHIFT_CNT               (0x04U)
#define BOARD_FPD_UB9702_CSI_CONTS_CLOCK_SHIFT_CNT              (0x01U)
#define BOARD_FPD_UB9702_CSI_ENABLE_SHIFT_CNT                   (0x00U)

/** CSI_CTL2 Register Field */
#define BOARD_FPD_UB9702_CSI_PASS_MODE_SHIFT_CNT                (0x03U)

/** CSI_STS Register Fileds */
#define BOARD_FPD_UB9702_TX_PORT_SYNC_SHIFT_CNT                 (0x01U)

/** FPD3_PORT_SEL Register Fields*/
#define BOARD_FPD_UB9702_RX_READ_PORT_SHIFT_CNT                 (0x04U)
#define BOARD_FPD_UB9702_RX_WRITE_PORT_3_SHIFT_CNT              (0x03U)
#define BOARD_FPD_UB9702_RX_WRITE_PORT_2_SHIFT_CNT              (0x02U)
#define BOARD_FPD_UB9702_RX_WRITE_PORT_1_SHIFT_CNT              (0x01U)
#define BOARD_FPD_UB9702_RX_WRITE_PORT_0_SHIFT_CNT              (0x00U)

/** BCC_CONFIG Register Fields */
#define BOARD_FPD_UB9702_I2C_PASS_THROUGH_ALL_SHIFT_CNT         (0x07U)
#define BOARD_FPD_UB9702_I2C_PASS_THROUGH_SHIFT_CNT             (0x06U)
#define BOARD_FPD_UB9702_AUTO_ACK_ALL_SHIFT_CNT                 (0x05U)
#define BOARD_FPD_UB9702_BC_ALWAYS_ON_SHIFT_CNT                 (0x04U)
#define BOARD_FPD_UB9702_BC_CRC_GEN_ENABLE_SHIFT_CNT            (0x03U)
#define BOARD_FPD_UB9702_BC_FREQ_SELECT_SHIFT_CNT               (0x00U)

/** SER_ID Register Fields */
#define BOARD_FPD_UB9702_SER_ID_SHIFT_CNT                       (0x01U)
#define BOARD_FPD_UB9702_FREEZE_DEVICE_ID_SHIFT_CNT             (0x00U)

/** I2C_DEVICE_ID Register Field */
#define BOARD_FPD_UB9702_DEVICE_ID_BIT_MASK                    (0x7F << BOARD_FPD_UB9702_DEVICE_ID_SHIFT_CNT)
#define BOARD_FPD_UB9702_DES_ID_BIT_MASK                       (0x01 << BOARD_FPD_UB9702_DES_ID_SHIFT_CNT)

/** I2C_DEVICE_ID Register Field */
#define BOARD_FPD_UB9702_DIGITAL_RESET1_BIT_MASK               (0x01 << BOARD_FPD_UB9702_DIGITAL_RESET1_SHIFT_CNT)
#define BOARD_FPD_UB9702_DIGITAL_RESET0_BIT_MASK               (0x01 << BOARD_FPD_UB9702_DIGITAL_RESET0_SHIFT_CNT)

/** GENERAL_CFG Register Field */
#define BOARD_FPD_UB9702_I2C_MASTER_EN_BIT_MASK                (0x01 << BOARD_FPD_UB9702_I2C_MASTER_EN_SHIFT_CNT)
#define BOARD_FPD_UB9702_OUTPUT_EN_MODE_BIT_MASK               (0x01 << BOARD_FPD_UB9702_OUTPUT_EN_MODE_SHIFT_CNT)
#define BOARD_FPD_UB9702_OUTPUT_ENABLE_BIT_MASK                (0x01 << BOARD_FPD_UB9702_OUTPUT_ENABLE_SHIFT_CNT)
#define BOARD_FPD_UB9702_OUTPUT_SLEEP_STATE_SEL_BIT_MASK       (0x01 << BOARD_FPD_UB9702_OUTPUT_SLEEP_STATE_SEL_SHIFT_CNT)
#define BOARD_FPD_UB9702_RX_PARITY_CHECK_EN_BIT_MASK           (0x01 << BOARD_FPD_UB9702_RX_PARITY_CHECK_EN_SHIFT_CNT)
#define BOARD_FPD_UB9702_FORCE_REFCLK_DET_BIT_MASK             (0x01 << BOARD_FPD_UB9702_FORCE_REFCLK_DET_SHIFT_CNT)

/** BCC_Watchdog_Control Register Fields */
#define BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_BIT_MASK           (0x7F << BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_SHIFT_CNT)
#define BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_DISABLE_BIT_MASK   (0x01 << BOARD_FPD_UB9702_BCC_WATCHDOG_TIMER_DISABLE_SHIFT_CNT)

/** SCL_High_Time Register Fields */
#define BOARD_FPD_UB9702_SCL_HIGH_TIME_BIT_MASK                (0xFF << BOARD_FPD_UB9702_SCL_HIGH_TIME_SHIFT_CNT)
/** SCL_Low_Time Register Fields */
#define BOARD_FPD_UB9702_SCL_LOW_TIME_BIT_MASK                 (0xFF << BOARD_FPD_UB9702_SCL_LOW_TIME_SHIFT_CNT)

/** RX_PORT_CTL Register Fields */
#define BOARD_FPD_UB9702_BCC3_MAP_BIT_MASK                     (0x01 << BOARD_FPD_UB9702_BCC3_MAP_SHIFT_CNT)
#define BOARD_FPD_UB9702_BCC2_MAP_BIT_MASK                     (0x01 << BOARD_FPD_UB9702_BCC2_MAP_SHIFT_CNT)
#define BOARD_FPD_UB9702_BCC1_MAP_BIT_MASK                     (0x01 << BOARD_FPD_UB9702_BCC1_MAP_SHIFT_CNT)
#define BOARD_FPD_UB9702_BCC0_MAP_BIT_MASK                     (0x01 << BOARD_FPD_UB9702_BCC0_MAP_SHIFT_CNT)
#define BOARD_FPD_UB9702_PORT3_EN_BIT_MASK                     (0x01 << BOARD_FPD_UB9702_PORT3_EN_SHIFT_CNT)
#define BOARD_FPD_UB9702_PORT2_EN_BIT_MASK                     (0x01 << BOARD_FPD_UB9702_PORT2_EN_SHIFT_CNT)
#define BOARD_FPD_UB9702_PORT1_EN_BIT_MASK                     (0x01 << BOARD_FPD_UB9702_PORT1_EN_SHIFT_CNT)
#define BOARD_FPD_UB9702_PORT0_EN_BIT_MASK                     (0x01 << BOARD_FPD_UB9702_PORT0_EN_SHIFT_CNT)

/** IO_CTL Register Fields */
#define BOARD_FPD_UB9702_SEL3P3V_BIT_MASK                      (0x01 << BOARD_FPD_UB9702_SEL3P3V_SHIFT_CNT)
#define BOARD_FPD_UB9702_IO_SUPPLY_MODE_OV_BIT_MASK            (0x01 << BOARD_FPD_UB9702_IO_SUPPLY_MODE_OV_SHIFT_CNT)
#define BOARD_FPD_UB9702_IO_SUPPLY_MODE_BIT_MASK               (0x03 << BOARD_FPD_UB9702_IO_SUPPLY_MODE_SHIFT_CNT)

/** FS_CTL Register Fields */
#define BOARD_FPD_UB9702_FS_MODE_BIT_MASK                      (0x0F << BOARD_FPD_UB9702_FS_MODE_SHIFT_CNT)
#define BOARD_FPD_UB9702_FS_SINGLE_BIT_MASK                    (0x01 << BOARD_FPD_UB9702_FS_SINGLE_SHIFT_CNT)
#define BOARD_FPD_UB9702_FS_INIT_STATE_BIT_MASK                (0x01 << BOARD_FPD_UB9702_FS_INIT_STATE_SHIFT_CNT)
#define BOARD_FPD_UB9702_FS_GEN_MODE_BIT_MASK                  (0x01 << BOARD_FPD_UB9702_FS_GEN_MODE_SHIFT_CNT)
#define BOARD_FPD_UB9702_FS_GEN_ENABLE_BIT_MASK                (0x01 << BOARD_FPD_UB9702_FS_GEN_ENABLE_SHIFT_CNT)

/** FS_HIGH_TIME_1 Register Field */
#define BOARD_FPD_UB9702_FRAMESYNC_HIGH_TIME_1_BIT_MASK        (0xFF << BOARD_FPD_UB9702_FRAMESYNC_HIGH_TIME_1_SHIFT_CNT)

/** FS_HIGH_TIME_0 Register Field */
#define BOARD_FPD_UB9702_FRAMESYNC_HIGH_TIME_0_BIT_MASK        (0xFF << BOARD_FPD_UB9702_FRAMESYNC_HIGH_TIME_0_SHIFT_CNT)

/** FS_LOW_TIME_1 Register Field */
#define BOARD_FPD_UB9702_FRAMESYNC_LOW_TIME_1_BIT_MASK         (0xFF << BOARD_FPD_UB9702_FRAMESYNC_LOW_TIME_1_SHIFT_CNT)

/** FS_LOW_TIME_0 Register Field */
#define BOARD_FPD_UB9702_FRAMESYNC_LOW_TIME_1_BIT_MASK         (0xFF << BOARD_FPD_UB9702_FRAMESYNC_LOW_TIME_1_SHIFT_CNT)

/** MAX_FRM_HI Register Field */
#define BOARD_FPD_UB9702_MAX_FRM_HI_BIT_MASK                   (0xFF << BOARD_FPD_UB9702_MAX_FRM_HI_SHIFT_CNT)

/** MAX_FRM_LO Register Field */
#define BOARD_FPD_UB9702_MAX_FRM_LO_BIT_MASK                   (0x01 << BOARD_FPD_UB9702_MAX_FRM_LO_SHIFT_CNT)

/** CSI_PLL_CTL Register Fields */
#define BOARD_FPD_UB9702_SEL_OSC_200M_BIT_MASK                 (0x01 << BOARD_FPD_UB9702_SEL_OSC_200M_SHIFT_CNT)
#define BOARD_FPD_UB9702_REF_CLK_MODE_BIT_MASK                 (0x01 << BOARD_FPD_UB9702_REF_CLK_MODE_SHIFT_CNT)
#define BOARD_FPD_UB9702_CSI_TX_SPEED_BIT_MASK                 (0x03 << BOARD_FPD_UB9702_CSI_TX_SPEED_SHIFT_CNT)

/** FWD_CTL1 Register Fields */
#define BOARD_FPD_UB9702_FWD_PORT3_DIS_BIT_MASK                (0x01 << BOARD_FPD_UB9702_FWD_PORT3_DIS_SHIFT_CNT)
#define BOARD_FPD_UB9702_FWD_PORT2_DIS_BIT_MASK                (0x01 << BOARD_FPD_UB9702_FWD_PORT2_DIS_SHIFT_CNT)
#define BOARD_FPD_UB9702_FWD_PORT1_DIS_BIT_MASK                (0x01 << BOARD_FPD_UB9702_FWD_PORT1_DIS_SHIFT_CNT)
#define BOARD_FPD_UB9702_FWD_PORT0_DIS_BIT_MASK                (0x01 << BOARD_FPD_UB9702_FWD_PORT0_DIS_SHIFT_CNT)
#define BOARD_FPD_UB9702_RX3_MAP_BIT_MASK                      (0x01 << BOARD_FPD_UB9702_RX3_MAP_SHIFT_CNT)
#define BOARD_FPD_UB9702_RX2_MAP_BIT_MASK                      (0x01 << BOARD_FPD_UB9702_RX2_MAP_SHIFT_CNT)
#define BOARD_FPD_UB9702_RX1_MAP_BIT_MASK                      (0x01 << BOARD_FPD_UB9702_RX1_MAP_SHIFT_CNT)
#define BOARD_FPD_UB9702_RX0_MAP_BIT_MASK                      (0x01 << BOARD_FPD_UB9702_RX0_MAP_SHIFT_CNT)

/** FWD_CTL2 Register Fields */
#define BOARD_FPD_UB9702_FWD_SYNC_AS_AVAIL_BIT_MASK            (0x01 << BOARD_FPD_UB9702_FWD_SYNC_AS_AVAIL_SHIFT_CNT)
#define BOARD_FPD_UB9702_CSI1_SYNC_FWD_BIT_MASK                (0x03 << BOARD_FPD_UB9702_CSI1_SYNC_FWD_SHIFT_CNT)
#define BOARD_FPD_UB9702_CSI0_SYNC_FWD_BIT_MASK                (0x03 << BOARD_FPD_UB9702_CSI0_SYNC_FWD_SHIFT_CNT)
#define BOARD_FPD_UB9702_CSI1_RR_FWD_BIT_MASK                  (0x01 << BOARD_FPD_UB9702_CSI1_RR_FWD_SHIFT_CNT)
#define BOARD_FPD_UB9702_CSI0_RR_FWD_BIT_MASK                  (0x01 << BOARD_FPD_UB9702_CSI0_RR_FWD_SHIFT_CNT)

/** FWD_STS Register Fields */
#define BOARD_FPD_UB9702_FWD_SYNC_FAIL1_BIT_MASK               (0x01 << BOARD_FPD_UB9702_FWD_SYNC_FAIL1_SHIFT_CNT)
#define BOARD_FPD_UB9702_FWD_SYNC_FAIL0_BIT_MASK               (0x01 << BOARD_FPD_UB9702_FWD_SYNC_FAIL0_SHIFT_CNT)
#define BOARD_FPD_UB9702_FWD_SYNC1_BIT_MASK                    (0x01 << BOARD_FPD_UB9702_FWD_SYNC1_SHIFT_CNT)
#define BOARD_FPD_UB9702_FWD_SYNC0_BIT_MASK                    (0x01 << BOARD_FPD_UB9702_FWD_SYNC0_SHIFT_CNT)

/** CSI_PORT_SEL Register Fields */
#define BOARD_FPD_UB9702_TX_READ_PORT_BIT_MASK                 (0x01 << BOARD_FPD_UB9702_TX_READ_PORT_SHIFT_CNT)
#define BOARD_FPD_UB9702_TX_WRITE_PORT_1_BIT_MASK              (0x01 << BOARD_FPD_UB9702_TX_WRITE_PORT_1_SHIFT_CNT)
#define BOARD_FPD_UB9702_TX_WRITE_PORT_0_BIT_MASK              (0x01 << BOARD_FPD_UB9702_TX_WRITE_PORT_0_SHIFT_CNT)

/** CSI_CTL Register Fields */
#define BOARD_FPD_UB9702_CSI_CAL_EN_BIT_MASK                   (0x01 << BOARD_FPD_UB9702_CSI_CAL_EN_SHIFT_CNT)
#define BOARD_FPD_UB9702_CSI_LANE_COUNT_BIT_MASK               (0x03 << BOARD_FPD_UB9702_CSI_LANE_COUNT_SHIFT_CNT)
#define BOARD_FPD_UB9702_CSI_CONTS_CLOCK_BIT_MASK              (0x01 << BOARD_FPD_UB9702_CSI_CONTS_CLOCK_SHIFT_CNT)
#define BOARD_FPD_UB9702_CSI_ENABLE_BIT_MASK                   (0x01 << BOARD_FPD_UB9702_CSI_ENABLE_SHIFT_CNT)

/** CSI_CTL2 Register Field */
#define BOARD_FPD_UB9702_CSI_PASS_MODE_BIT_MASK                (0x01 << BOARD_FPD_UB9702_CSI_PASS_MODE_SHIFT_CNT)

/** CSI_STS Register Fileds */
#define BOARD_FPD_UB9702_TX_PORT_SYNC_BIT_MASK                 (0x01 << BOARD_FPD_UB9702_TX_PORT_SYNC_SHIFT_CNT)

/** FPD3_PORT_SEL Register Fields*/
#define BOARD_FPD_UB9702_RX_READ_PORT_BIT_MASK                 (0x03 << BOARD_FPD_UB9702_RX_READ_PORT_SHIFT_CNT)
#define BOARD_FPD_UB9702_RX_WRITE_PORT_3_BIT_MASK              (0x01 << BOARD_FPD_UB9702_RX_WRITE_PORT_3_SHIFT_CNT)
#define BOARD_FPD_UB9702_RX_WRITE_PORT_2_BIT_MASK              (0x01 << BOARD_FPD_UB9702_RX_WRITE_PORT_2_SHIFT_CNT)
#define BOARD_FPD_UB9702_RX_WRITE_PORT_1_BIT_MASK              (0x01 << BOARD_FPD_UB9702_RX_WRITE_PORT_1_SHIFT_CNT)
#define BOARD_FPD_UB9702_RX_WRITE_PORT_0_BIT_MASK              (0x01 << BOARD_FPD_UB9702_RX_WRITE_PORT_0_SHIFT_CNT)

/** BCC_CONFIG Register Fields */
#define BOARD_FPD_UB9702_I2C_PASS_THROUGH_ALL_BIT_MASK         (0x01 << BOARD_FPD_UB9702_I2C_PASS_THROUGH_ALL_SHIFT_CNT)
#define BOARD_FPD_UB9702_I2C_PASS_THROUGH_BIT_MASK             (0x01 << BOARD_FPD_UB9702_I2C_PASS_THROUGH_SHIFT_CNT)
#define BOARD_FPD_UB9702_AUTO_ACK_ALL_BIT_MASK                 (0x01 << BOARD_FPD_UB9702_AUTO_ACK_ALL_SHIFT_CNT)
#define BOARD_FPD_UB9702_BC_ALWAYS_ON_BIT_MASK                 (0x01 << BOARD_FPD_UB9702_BC_ALWAYS_ON_SHIFT_CNT)
#define BOARD_FPD_UB9702_BC_CRC_GEN_ENABLE_BIT_MASK            (0x01 << BOARD_FPD_UB9702_BC_CRC_GEN_ENABLE_SHIFT_CNT)
#define BOARD_FPD_UB9702_BC_FREQ_SELECT_BIT_MASK               (0x07 << BOARD_FPD_UB9702_BC_FREQ_SELECT_SHIFT_CNT)

/** SER_ID Register Fields */
#define BOARD_FPD_UB9702_SER_ID_BIT_MASK                       (0x7F << BOARD_FPD_UB9702_SER_ID_SHIFT_CNT)
#define BOARD_FPD_UB9702_FREEZE_DEVICE_ID_BIT_MASK             (0x01 << BOARD_FPD_UB9702_FREEZE_DEVICE_ID_SHIFT_CNT)

/** Board_fpdUb9702SetBCCI2CSlvPortMap */
#define BOARD_FPD_UB9702_BCC3_MAP                              (3U)
#define BOARD_FPD_UB9702_BCC2_MAP                              (2U)
#define BOARD_FPD_UB9702_BCC1_MAP                              (1U)
#define BOARD_FPD_UB9702_BCC0_MAP                              (0U)

#define BOARD_I2C_SLAVE_PORT0                                  (0U)
#define BOARD_I2C_SLAVE_PORT1                                  (1U)

/** Board_fpdUb9702SetRcvrPortEnModeCtrl */
#define BOARD_FPD_UB9702_PORT3_EN                              (3U)
#define BOARD_FPD_UB9702_PORT2_EN                              (2U)
#define BOARD_FPD_UB9702_PORT1_EN                              (1U)
#define BOARD_FPD_UB9702_PORT0_EN                              (0U)

/** Board_fpdUb9702SetIOPinSupply */
#define BOARD_FPD_UB9702_IO_PIN_SUPPLY_3V3                    (1U)
#define BOARD_FPD_UB9702_IO_PIN_SUPPLY_1V8                    (0U)

/** Board_fpdUb9702SetIOSupplyModeCtrl */
#define BOARD_FPD_UB9702_IO_SUPPLY_MODE_3V3                    (3U)
#define BOARD_FPD_UB9702_IO_SUPPLY_MODE_1V8                    (0U)

/** Board_fpdUb9702SetFSModeCtrl */
/** Internal generated framesync, use back channel frame clock from port0 */
#define BOARD_FPD_9702_INT_GEN_BC_FS_CLK_PORT0                (0x00U)
/** Internal generated framesync, use back channel frame clock from port1 */
#define BOARD_FPD_9702_INT_GEN_BC_FS_CLK_PORT1                (0x01U)
/** Internal generated framesync, use back channel frame clock from port2 */
#define BOARD_FPD_9702_INT_GEN_BC_FS_CLK_PORT2                (0x02U)
/** Internal generated framesync, use back channel frame clock from port3 */
#define BOARD_FPD_9702_INT_GEN_BC_FS_CLK_PORT3                (0x03U)
/** Internal generated framesync, use 25MHz clk */
#define BOARD_FPD_9702_INT_GEN_BC_FS_25MHZ_CLK_1              (0x04U)
#define BOARD_FPD_9702_INT_GEN_BC_FS_25MHZ_CLK_2              (0x05U)
#define BOARD_FPD_9702_INT_GEN_BC_FS_25MHZ_CLK_3              (0x06U)
#define BOARD_FPD_9702_INT_GEN_BC_FS_25MHZ_CLK_4              (0x07U)
#define BOARD_FPD_9702_EXT_GEN_BC_FS_GPIO0                    (0x08U)
#define BOARD_FPD_9702_EXT_GEN_BC_FS_GPIO1                    (0x09U)
#define BOARD_FPD_9702_EXT_GEN_BC_FS_GPIO2                    (0x0AU)
#define BOARD_FPD_9702_EXT_GEN_BC_FS_GPIO3                    (0x0BU)
#define BOARD_FPD_9702_EXT_GEN_BC_FS_GPIO4                    (0x0CU)
#define BOARD_FPD_9702_EXT_GEN_BC_FS_GPIO5                    (0x0DU)
#define BOARD_FPD_9702_EXT_GEN_BC_FS_GPIO6                    (0x0EU)
#define BOARD_FPD_9702_EXT_GEN_BC_FS_GPIO7                    (0x0FU)

/** Board_fpdUb9702SelOscClk */
/** Select external reference clock */
#define BOARD_FPD_9702_SEL_EXT_REF_CLK                        (0x00U)
/** Select internal always-on clock */
#define BOARD_FPD_9702_SEL_INT_REF_CLK                        (0x01U)

/** Board_fpdUb9702SetRefClkModeCtrl */
#define BOARD_FPD_9702_REf_CLK_200MHZ                         (0x00U)
#define BOARD_FPD_9702_REf_CLK_100MHZ                         (0x01U)

/** Board_fpdUb9702SelCSITxSpeed */
/** 1.6 Gbps serial rate */
#define BOARD_FPD_9702_SERIAL_RATE_1600_MBPS                  (0x00U)
/** 1.2 Gbps serial rate */
#define BOARD_FPD_9702_SERIAL_RATE_1200_MBPS                  (0x01U)
/** 800 Mbps serial rate */
#define BOARD_FPD_9702_SERIAL_RATE_800_MBPS                   (0x02U)
/** 400 Mbps serial rate */
#define BOARD_FPD_9702_SERIAL_RATE_400_MBPS                   (0x03U)

/** FWD_CTL1 */
/** Board_fpdUb9702FwdPortDisModeCtrl */
#define BOARD_FPD_9702_FWD_PORT_3                             (0x03U)
#define BOARD_FPD_9702_FWD_PORT_2                             (0x02U)
#define BOARD_FPD_9702_FWD_PORT_1                             (0x01U)
#define BOARD_FPD_9702_FWD_PORT_0                             (0x00U)

/** Board_fpdUb9702SetRxPortMap */
#define BOARD_FPD_9702_RX3_MAP                                (0x03U)
#define BOARD_FPD_9702_RX2_MAP                                (0x02U)
#define BOARD_FPD_9702_RX1_MAP                                (0x01U)
#define BOARD_FPD_9702_RX0_MAP                                (0x00U)

/** Board_fpdUb9702SelTxPortRdBackRegBlk */
#define BOARD_FPD_9702_TX_PORT_0_REG_BLK                      (0x00U)
#define BOARD_FPD_9702_TX_PORT_1_REG_BLK                      (0x01U)

/** Board_fpdUb9702SetCsiLaneCnt */
#define BOARD_FPD_9702_CSI_LANES_4                            (0x00U)
#define BOARD_FPD_9702_CSI_LANES_3                            (0x01U)
#define BOARD_FPD_9702_CSI_LANES_2                            (0x02U)
#define BOARD_FPD_9702_CSI_LANES_1                            (0x03U)

/** Board_fpdUb9702SelRxPortRdBackRegBlk */
#define BOARD_FPD_9702_RX_PORT_0_REG_BLK                      (0x00U)
#define BOARD_FPD_9702_RX_PORT_1_REG_BLK                      (0x01U)
#define BOARD_FPD_9702_RX_PORT_2_REG_BLK                      (0x02U)
#define BOARD_FPD_9702_RX_PORT_3_REG_BLK                      (0x03U)

/** Board_fpdUb9702SetRxPortWrEnModeCtrl */
#define BOARD_FPD_9702_RX_WR_PORT_3                             (0x03U)
#define BOARD_FPD_9702_RX_WR_PORT_2                             (0x02U)
#define BOARD_FPD_9702_RX_WR_PORT_1                             (0x01U)
#define BOARD_FPD_9702_RX_WR_PORT_0                             (0x00U)

/** Board_fpdUb9702SelBCFreq */
#define BOARD_FPD_9702_2500_KBPS                                (0x00U)
#define BOARD_FPD_9702_1562_KBPS                                (0x01U)
#define BOARD_FPD_9702_10_MBPS                                  (0x02U)
#define BOARD_FPD_9702_12_MBPS                                  (0x03U)
#define BOARD_FPD_9702_20_MBPS                                  (0x04U)
#define BOARD_FPD_9702_25_MBPS                                  (0x05U)
#define BOARD_FPD_9702_50_MBPS                                  (0x06U)
#define BOARD_FPD_9702_100_MBPS                                 (0x07U)

#define BOARD_FPD_9702_FORWARD_ENABLE                           (0x00U)
#define BOARD_FPD_9702_FORWARD_DISABLE                          (0x01U)

#define BOARD_FPD_9702_CSI2_DES_HUB1                            (0U)
#define BOARD_FPD_9702_CSI2_DES_HUB2                            (1U)
#define BOARD_FPD_9702_CSI2_DES_HUB3                            (2U)

#define BOARD_FPD_9702_CSI2_DES_HUB1_ADDR                       (0x3DU)
#define BOARD_FPD_9702_CSI2_DES_HUB2_ADDR                       (0x30U)
#define BOARD_FPD_9702_CSI2_DES_HUB3_ADDR                       (0x32U)

/**
 *  \anchor DESUB9702_patternType
 *  \name   Pattern type for generation
 *  \brief  Id for pattern generation.
 *
 *  @{
 */
/** \brief Pattern type: RAW12 1920x1080 30fps, 4 lanes@1.5Gbps */
#define BOARD_FPD_UB9702_PG_RAW12_1920_1080_30_FPS             ((uint32_t) 0x0U)
/** \brief Pattern type: RAW12 3840x2160 40fps, 4 lanes@1.5Gbps */
#define BOARD_FPD_UB9702_PG_RAW12_3840_2160_40_FPS             ((uint32_t) 0x1U)
/** \brief Pattern type: Maximum Val */
#define BOARD_FPD_UB9702_PG_MAX                                ((uint32_t) 0x2U)
/* @} */

/**
 * \brief  Set deserializer device Id
 *
 *  This function is used for configuring the deserializer
 *  device Id.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   devId         [IN]   device Id
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetDesDevId(void *handle,
                                        Board_FpdModuleObj *fpdModParams,
                                        uint8_t devId);

/**
 * \brief  Deserializer digital reset1 mode control
 *
 * This function is used for configuring the deserializer digital reset1 mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetDigitalRst1ModeCtrl(void *handle,
                                                   Board_FpdModuleObj *fpdModParams,
                                                   uint8_t cfgMode);

/**
 * \brief  I2C master enable mode control
 *
 * This function is used for configuring the I2C master enable mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetI2cMstrEnModeCtrl(void *handle,
                                                 Board_FpdModuleObj *fpdModParams,
                                                 uint8_t cfgMode);

/**
 * \brief  output enable mode select
 *
 * This function is used for configuring the output enable mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetOutputEnMode(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t cfgMode);

/**
 * \brief  Set output enable control mode
 *
 * This function is used for configuring the output enable control mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetOutputEnCtrlMode(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t cfgMode);

/**
 * \brief  Output sleep state select
 *
 * This function is used for configuring the output sleep state select mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetOSSSelModeCtrl(void *handle,
                                              Board_FpdModuleObj *fpdModParams,
                                              uint8_t cfgMode);

/**
 * \brief  Get force clock detect status
 *
 * This function is used for getting the status of force clock detect
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   clkDetSts     [IN]   Buffer to hold the clock detect status
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702GetForceRefClkDetSts(void *handle,
                                                 Board_FpdModuleObj *fpdModParams,
                                                 bool *clkDetSts);

/**
 * \brief  Set BCC watch dog timer
 *
 * This function is used to set the watch dog for user configurable
 * timeout in multiples of 2 milliseconds.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   timeoutCnt    [IN]   timeout value in units of 2 milliseconds
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetBCCWatchDogTImer(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t timeoutCnt);

/**
 * \brief  BCC I2C slave port map
 *
 * This function is used to map control channel to I2C slave port
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   BCCChNum      [IN]   Back channel control channel number
 * \param   I2CSlvPort    [IN]   I2C slave port either '0' or '1'
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetBCCI2CSlvPortMap(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t BCCChNum,
                                                uint8_t I2CSlvPort);

/**
 * \brief  Receiver port enable mode control
 *
 * This function is used to set the receiver port enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   RcvrPortNum    [IN]   Receiver port number
 * \param   cfgMode        [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetRcvrPortEnModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t RcvrPortNum,
                                                  uint8_t cfgMode);
/**
 * \brief  Set IO pin supply
 *
 * This function is used to set IO pin supply
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   ioLevel        [IN]   IO level to be configred i.e; 1.8V or 3.3V
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetIOPinSupply(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t ioLevel);
/**
 * \brief  Get IO pin supply
 *
 * This function is used to get IO pin supply
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   ioLevel        [IN]   IO level to be configred i.e; 1.8V or 3.3V
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702GetIOPinSupply(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t *ioLevel);

/**
 * \brief  Set IO supply voltage level
 *
 * This function is used to set IO supply voltage level
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates override Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetIOSupplyOverrideModeCtrl(void *handle,
                                                        Board_FpdModuleObj *fpdModParams,
                                                        uint8_t cfgMode);

/**
 * \brief  Set IO supply mode control
 *
 * This function is used to set IO supply mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   ioLevel        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetIOSupplyMode(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t ioLevel);

/**
 * \brief  Get IO pin supply mode
 *
 * This function is used to get the IO supply mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   ioLevel        [IN]   IO level to be configred i.e; 1.8V or 3.3V
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702GetIOSupplyMode(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t *ioLevel);

/**
 * \brief  Set frame sync mode control
 *
 * This function is used to set frame sync mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameSync      [IN]   Frame sync to be configured
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSModeCtrl(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t frameSync);

/**
 * \brief  Set frame sync pulse generate mode control
 *
 * This function is used to set single frame sync pulse generate mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSPulseGenModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode);

/**
 * \brief  Set Frame sync generate enable mode control
 *
 * This function is used to set frame sync generate mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSGenEnModeCtrl(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t cfgMode);

/**
 * \brief  Set Frame sync high time1
 *
 * This function is used to set frame sync high time1
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameSyncTime  [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSHighTime1(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t frameSyncTime);

/**
 * \brief  Set Frame sync high time0
 *
 * This function is used to set frame sync high time1
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameSyncTime  [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSHighTime0(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t frameSyncTime);

/**
 * \brief  Set Frame sync low time1
 *
 * This function is used to set frame sync low time1
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameSyncTime  [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSLowTime1(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t frameSyncTime);

/**
 * \brief  Set Frame sync low time1
 *
 * This function is used to set frame sync low time0
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameSyncTime  [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFSLowTime0(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t frameSyncTime);

/**
 * \brief  Set maximum frame high count
 *
 * This function is used to set maximum frame high count
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameCnt       [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetMaxFrameHiCnt(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t frameCnt);

/**
 * \brief  Set maximum frame low count
 *
 * This function is used to set maximum frame low count
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   frameCnt       [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetMaxFrameLoCnt(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t frameCnt);

/**
 * \brief  Select oscillator clock
 *
 * This function is used to set maximum frame low count
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   refClk         [IN]   Frame sync single mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SelOscClk(void *handle,
                                      Board_FpdModuleObj *fpdModParams,
                                      uint8_t refClk);

/**
 * \brief  Set reference clock mode control
 *
 * This function is used to set reference clock mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   refClk         [IN]   reference clock mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetRefClkModeCtrl(void *handle,
                                              Board_FpdModuleObj *fpdModParams,
                                              uint8_t refClk);

/**
 * \brief  Select CSI transmitter speed
 *
 * This function is used to select CSI transmitter speed
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   txSpeed        [IN]   Transmitter speed
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SelCSITxSpeed(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t txSpeed);

/**
 * \brief  Set forward port disable mode control
 *
 * This function is used to set forward port disable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   fwdPort        [IN]   forward port number
 * \param   cfgMode        [IN]   configured mode
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetFwdPortDisModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t fwdPort,
                                                  uint8_t cfgMode);

/**
 * \brief  Set recevie port map
 *
 * This function is used to set receive port map
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   rxPort         [IN]   receive port number
 * \param   csiPort        [IN]   csi port number
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetRxPortMap(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t rxPort,
                                         uint8_t csiPort);

/**
 * \brief  Select transmit port read back register block
 *
 * This function is used to select the transmit port read back register block
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   regBlk         [IN]   port0/port1 register blocks
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SelTxPortRdBackRegBlk(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t regBlk);

/**
 * \brief  Set transmit port1 write enable mode control
 *
 * This function is used to set transmit port1 write enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetTxPort1WrEnModeCtrl(void *handle,
                                                   Board_FpdModuleObj *fpdModParams,
                                                   uint8_t cfgMode);

/**
 * \brief  Set transmit port0 write enable mode control
 *
 * This function is used to set transmit port0 write enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetTxPort0WrEnModeCtrl(void *handle,
                                                   Board_FpdModuleObj *fpdModParams,
                                                   uint8_t cfgMode);

/**
 * \brief  Set CSI lane count
 *
 * This function is used to set CSI lane count
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   laneCnt        [IN]   CSI lane count
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetCSILaneCnt(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t laneCnt);

/**
 * \brief  Set CSI continuous clock mode control
 *
 * This function is used to set CSI continuous clock mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetCSIContsClkModeCtrl(void *handle,
                                                   Board_FpdModuleObj *fpdModParams,
                                                   uint8_t cfgMode);

/**
 * \brief  Set CSI output enable mode control
 *
 * This function is used to set CSI output enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetCSIEnableModeCtrl(void *handle,
                                                 Board_FpdModuleObj *fpdModParams,
                                                 uint8_t cfgMode);

/**
 * \brief  Set CSI pass mode control
 *
 * This function is used to set CSI pass mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetCSIPassModeCtrl(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t cfgMode);

/**
 * \brief  Get bi-directional control channel status
 *
 * This function is used to get bi-directional control status
 *
 * \param   handle         [IN]    Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   bccStatus      [OUT]   Buffer to hold BCC status
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702GetBCCStatus(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t *bccStatus);

/**
 * \brief  Select receive port read back register block
 *
 * This function is used to select the receive port register block for read back
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   regBlk         [IN]   port0/port1 register blocks
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SelRxPortRdBackRegBlk(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t regBlk);

/**
 * \brief  Set receive port write enable mode control
 *
 * This function is used to set receive port write enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   rxWrPort       [IN]   receive write port number
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetRxPortWrEnModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t rxWrPort,
                                                  uint8_t cfgMode);

/**
 * \brief  Set I2C pass through all mode control
 *
 * This function is used to set I2C pass through all mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetI2CPassThrAllModeCtrl(void *handle,
                                                     Board_FpdModuleObj *fpdModParams,
                                                     uint8_t cfgMode);

/**
 * \brief  Set I2C pass through mode control
 *
 * This function is used to set I2C pass through mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetI2CPassThrModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode);

/**
 * \brief  Set I2C Auto acknowledge mode control
 *
 * This function is used to set I2C auto acknowledge mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetI2CAutoAckModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode);

/**
 * \brief  Set back channel enable mode control
 *
 * This function is used to set back channel enable mode
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   cfgMode        [IN]   Config mode - Indicates Enable/Disable
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetBCCEnModeCtrl(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode);

/**
 * \brief  Select back channel frequency
 *
 * This function is used to select back channel frequency
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   bcFreq         [IN]   Back channel frequency
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SelBCFreq(void *handle,
                                      Board_FpdModuleObj *fpdModParams,
                                      uint8_t bcFreq);

/**
 * \brief  Select back channel frequency
 *
 * This function is used to select back channel frequency
 *
 * \param   handle         [IN]   Low level driver handle
 * \param   fpdModParams   [IN]   FPD module params
 * \param   rmtSerId       [IN]   Remote serializer slave address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702SetRmtSerId(void *handle,
                                        Board_FpdModuleObj *fpdModParams,
                                        uint8_t rmtSerId);

/**
 * \brief  Remote serializer slave device id config
 *
 * This function is used for configuring the remote serializer slave device ID
 *
 * \param   handle       [IN] Low level driver handle
 * \param   fpdModParams [IN] FPD module params
 * @param   fpdRmtParams [IN] structure holding the fpd params
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb9702RmtSerSlvDevAliasIdCfg(void *handle,
                                                   Board_FpdModuleObj *fpdModParams,
                                                   Board_FpdRmtDevObj *fpdRmtParams);

/**
 * \brief  Get ub9702 i2c address.
 *
 * This function is used to get the I2C address and
 * channel details of UB9702 module.
 * \param   hubInstance [IN]  instance of the csi hub
 * \param   domain      [IN]  I2C instance domain
 * \param   chNum       [IN]  buffer to hold i2c channel number
 * \param   i2cAddr     [IN]  buffer to hold i2c address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
void Board_fpdUb9702GetI2CAddr(uint8_t hubInstance,
                               uint8_t *domain,
                               uint8_t *chNum,
                               uint8_t *i2cAddr);

/**
 * \brief  FPD UB902 pattern generation configurations.
 *
 * This function is used for configuring the pattern generator for FPD UB9702
 *
 * \param   handle          [IN]  Low level driver handle
 * \param   fpdModParams    [IN]  FPD module params
 * \param   pgType          [IN]  Pattern Generation Type
 *                                See \ref DESUB9702_patternType for details.
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_fpdUb9702CfgPG(void *handle,
                                  Board_FpdModuleObj *fpdModParams,
                                  uint32_t pgType);
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DS90UB9702_H_ */

