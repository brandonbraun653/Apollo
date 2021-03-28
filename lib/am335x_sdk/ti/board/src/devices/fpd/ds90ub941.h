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
 * \file  ds90ub941.h
 *
 * \brief This file includes the structures, enums and register offsets
 *        for configuring the ds90ub941 serializer.
 *
 */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD 
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB941 DS90UB941 FPD-Link Library
 *
 *  Provides the interfaces for configuring DS90UB941 FPD-Link device.
 *
 *  @{
 *
 */
/* @} */

#ifndef _DS90UB941_H_
#define _DS90UB941_H_

#include <ti/board/src/devices/common/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD_DS90UB941
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB941_TYPES Data Types
 *
 *  Data types used by DS90UB941 FPD-Link device library.
 *
 *  @{
 *
 */

/** ub941 serializer i2c instance number */
#define BOARD_FPD_UB941_I2C_INSTANCE                                    (0x00U) /* TBD */

/** ub941 serializer i2c slave address */
#define BOARD_FPD_UB941_I2C_SLV_ADDR                                    (0x00U) /* TBD */

/** memory-mapped registers for the DS90UB941AS-Q1[Main Registers **/
/** RESET control register address */
#define BOARD_FPD_UB941_RESET_CTL_REG_ADDR                              (0x01U)
/** Device configuration register address */
#define BOARD_FPD_UB941_DEVICE_CFG_REG_ADDR                             (0x02U)
/** Generatl configuration register address */
#define BOARD_FPD_UB941_GENERAL_CFG_REG_ADDR                            (0x03U)
/** Deserializer ID register address */
#define BOARD_FPD_UB941_DES_ID_REG_ADDR                                 (0x06U)
/** Slave ID0 register address */
#define BOARD_FPD_UB941_SLAVE_ID0_REG_ADDR                              (0x07U)
/** Slave ID1 register address */
#define BOARD_FPD_UB941_SLAVE_ID1_REG_ADDR                              (0x70U)
/** Slave ID2 register address */
#define BOARD_FPD_UB941_SLAVE_ID2_REG_ADDR                              (0x71U)
/** Slave ID3 register address */
#define BOARD_FPD_UB941_SLAVE_ID3_REG_ADDR                              (0x72U)
/** Slave ID4 register address */
#define BOARD_FPD_UB941_SLAVE_ID4_REG_ADDR                              (0x73U)
/** Slave ID5 register address */
#define BOARD_FPD_UB941_SLAVE_ID5_REG_ADDR                              (0x74U)
/** Slave ID6 register address */
#define BOARD_FPD_UB941_SLAVE_ID6_REG_ADDR                              (0x75U)
/** Slave ID7 register address */
#define BOARD_FPD_UB941_SLAVE_ID7_REG_ADDR                              (0x76U)
/** Slave Alias0 register address */
#define BOARD_FPD_UB941_SLAVE_ALIAS_0_REG_ADDR                          (0x08U)
/** Slave Alias1 register address */
#define BOARD_FPD_UB941_SLAVE_ALIAS_1_REG_ADDR                          (0x77U)
/** Slave Alias2 register address */
#define BOARD_FPD_UB941_SLAVE_ALIAS_2_REG_ADDR                          (0x78U)
/** Slave Alias3 register address */
#define BOARD_FPD_UB941_SLAVE_ALIAS_3_REG_ADDR                          (0x79U)
/** Slave Alias4 register address */
#define BOARD_FPD_UB941_SLAVE_ALIAS_4_REG_ADDR                          (0x7AU)
/** Slave Alias5 register address */
#define BOARD_FPD_UB941_SLAVE_ALIAS_5_REG_ADDR                          (0x7BU)
/** Slave Alias6 register address */
#define BOARD_FPD_UB941_SLAVE_ALIAS_6_REG_ADDR                          (0x7CU)
/** Slave Alias7 register address */
#define BOARD_FPD_UB941_SLAVE_ALIAS_7_REG_ADDR                          (0x7DU)


/** General status register address */
#define BOARD_FPD_UB941_GENERAL_STS_REG_ADDR                            (0x0CU)
/** I2C control register address */
#define BOARD_FPD_UB941_I2C_CONTROL_REG_ADDR                            (0x17U)
/** Serial clock high time register address */
#define BOARD_FPD_UB941_SCL_HIGH_TIME_REG_ADDR                          (0x18U)
/** Serial clock low time register address */
#define BOARD_FPD_UB941_SCL_LOW_TIME_REG_ADDR                           (0x19U)
/** Transmission port register address */
#define BOARD_FPD_UB941_TX_PORT_SEL_REG_ADDR                            (0x1EU)
/** Indirect access control register address */
#define BOARD_FPD_UB941_IND_ACC_CTL_REG_ADDR                            (0x40U)
/** Indirect access address register address */
#define BOARD_FPD_UB941_IND_ACC_ADDR_REG_ADDR                           (0x41U)
/** Indirect access data register address */
#define BOARD_FPD_UB941_IND_ADD_DATA_REG_ADDR                           (0x42U)
/** Bridge control register address */
#define BOARD_FPD_UB941_BRIDGE_CTL_REG_ADDR                             (0x4FU)
/** Bridge configuraiton register address */
#define BOARD_FPD_UB941_BRIDGE_CFG_REG_ADDR                             (0x54U)
/** Bridge configuraiton2 register address */
#define BOARD_FPD_UB941_BRIDGE_CFG2_REG_ADDR                            (0x56U)
/** Dual status P1 register address */
#define BOARD_FPD_UB941_DUAL_STS_DUAL_STS_P1_REG_ADDR                   (0x5AU)
/** Dual control1 register address */
#define BOARD_FPD_UB941_DUAL_CTL1_REG_ADDR                              (0x5BU)
/** Dual control2 register address */
#define BOARD_FPD_UB941_DUAL_CTL2_REG_ADDR                              (0x5CU)
/** Pattern generation control P1 register address */
#define BOARD_FPD_UB941_PGCTL_PGCTL_P1_REG_ADDR                         (0x64U)
/** Pattern generation configuration P1 register address */
#define BOARD_FPD_UB941_PGCFG_PGCFG_P1_REG_ADDR                         (0x65U)
/** Pattern generation indirect address register address */
#define BOARD_FPD_UB941_PGIA_PGIA_P1_REG_ADDR                           (0x66U)
/** Pattern generation indirect data register address */
#define BOARD_FPD_UB941_PGID_PGID_P1_REG_ADDR                           (0x67U)
/** DPHY skip timing register address */
#define BOARD_FPD_UB941_DPHY_SKIP_TIMING_REG_ADDR                       (0x05U)
/** DSI config1 register address */
#define BOARD_FPD_UB941_DSI_CONFIG_1_REG_ADDR                           (0x21U)

/** Pattern generation clock divider configuration register address */
#define BOARD_FPD_UB941_PGCDC1_REG_ADDR                                 (0x03U)
/** Pattern generation total frame sync1 register address */
#define BOARD_FPD_UB941_PGTFS1_REG_ADDR                                 (0x04U)
/** Pattern generation total frame sync2 register address */
#define BOARD_FPD_UB941_PGTFS2_REG_ADDR                                 (0x05U)
/** Pattern generation total frame sync3 register address */
#define BOARD_FPD_UB941_PGTFS3_REG_ADDR                                 (0x06U)
/** Pattern generation active frame sync1 register address */
#define BOARD_FPD_UB941_PGAFS1_REG_ADDR                                 (0x07U)
/** Pattern generation active frame sync2 register address */
#define BOARD_FPD_UB941_PGAFS2_REG_ADDR                                 (0x08U)
/** Pattern generation active frame sync3 register address */
#define BOARD_FPD_UB941_PGAFS3_REG_ADDR                                 (0x09U)
/** Pattern generation horizontal back porch register address */
#define BOARD_FPD_UB941_PGHBP_REG_ADDR                                  (0x0CU)
/** Pattern generation vertical back porch register address */
#define BOARD_FPD_UB941_PGVBP_REG_ADDR                                  (0x0DU)

/** Active horizontal width register address */
#define BOARD_FPD_UB941_ACT_HOR_WIDTH_REG_ADDR                          (0x20U)
/** Active vertical width register address */
#define BOARD_FPD_UB941_ACT_VER_AND_HOR_WIDTH_REG_ADDR                  (0x03U)
/** Total vertical width register address */
#define BOARD_FPD_UB941_TOT_VER_WIDTH_REG_ADDR                          (0x09U)
/** Total vertical and horizontal width register address */
//#define BOARD_FPD_UB941_TOT_VER_AND_HOR_WIDTH_REG_ADDR                  (0x03U)
/** Total vertical and horizontal width register address */
#define BOARD_FPD_UB941_TOT_VER_AND_HOR_WIDTH_REG_ADDR                  (0xD4U)
/** Active horizontal width register address */
#define BOARD_FPD_UB941_TOT_HOR_AND_VER_WIDTH_REG_ADDR                  (0x20U)
/** Active horizontal width register address */
#define BOARD_FPD_UB941_HOR_BACK_PORCH_WIDTH_REG_ADDR                   (0xD8U)
/** Active horizontal width register address */
#define BOARD_FPD_UB941_VER_BACK_PORCH_WIDTH_REG_ADDR                   (0x23U)

/** RESET_CTL Register Fields */
/** Disable DSI field shift count */
#define BOARD_FPD_UB941_DISABLE_DSI_SHIFT_CNT                           (3U)
/** Digital Reset1 field shift count */
#define BOARD_FPD_UB941_DIGITAL_RESET1_SHIFT_CNT                        (1U)
/** Digital Reset0 field shift count */
#define BOARD_FPD_UB941_DIGITAL_RESET0_SHIFT_CNT                        (1U)

/** DEVICE_CFG Register Fields */
/** DSI1 clock P/N field shift count */
#define BOARD_FPD_UB941_DSI1_CLK_PN_SWAP_SHIFT_CNT                      (6U)
/** DSI1 data P/N field shift count */
#define BOARD_FPD_UB941_DSI1_DATA_PN_SWAP_SHIFT_CNT                     (5U)
/** DSI0 clock P/N field shift count */
#define BOARD_FPD_UB941_DSI0_CLK_PN_SWAP_SHIFT_CNT                      (2U)
/** DSI0 data P/N field shift count */
#define BOARD_FPD_UB941_DSI0_DATA_PN_SWAP_SHIFT_CNT                     (1U)

/** IND_ACC_CTL Register Fields */
/** Indirect access select field shift count */
#define BOARD_FPD_UB941_IND_ACC_SEL_SHIFT_CNT                           (2U)
/** Indirect access read field shift count */
#define BOARD_FPD_UB941_IND_ACC_READ_SHIFT_CNT                          (0U)

/** BRIDGE_CFG Register Fields */
/** DSI bytes per pixel field shift count */
#define BOARD_FPD_UB941_DSI_BYTES_PER_PIXEL_SHIFT_CNT                   (4U)

/** BRIDGE_CFG2 Register Fields */
/** Bridge clock mode field shift count */
#define BOARD_FPD_UB941_BRIDGE_LANE_MODE_SHIFT_CNT                       (2U) 

/** DUAL_CTL2 Register Fields */
/** Frequency stability threshold field shift count */
#define BOARD_FPD_UB941_FREQ_STBL_THR_SHIFT_CNT                         (3U)

/** DUAL_STS_DUAL_STS_P1 Register Fields */
/** FPD Link3 ready status field shift count */
#define BOARD_FPD_UB941_FPD3_LINK_RDY_SHIFT_CNT                         (7U)
/** FPD Link3 transmit status field shift count */
#define BOARD_FPD_UB941_FPD3_TX_STS_SHIFT_CNT                           (6U)
/** DSI clock detect field shift count */
#define BOARD_FPD_UB941_DSI_CLK_DET_SHIFT_CNT                           (3U)
/** No DSI clock detect field shift count */
#define BOARD_FPD_UB941_NO_DSI_CLK_SHIFT_CNT                            (1U)
/** DSI stable frequency detect field shift count */
#define BOARD_FPD_UB941_FREQ_STABLE_SHIFT_CNT                           (0U)

/** GENERAL_CFG Register Filed */
/** Receive CRC checker enable field shift count */
#define BOARD_FPD_UB941_RX_CRC_CHECKER_ENABLE_SHIFT_CNT                 (7U)
/** Filter enable field shift count */
#define BOARD_FPD_UB941_FILTER_ENABLE_SHIFT_CNT                         (4U)
/** I2C pass through field shift count */
#define BOARD_FPD_UB941_I2C_PASS_THROUGH_SHIFT_CNT                      (3U)
/** PCLK auto switch field shift count */
#define BOARD_FPD_UB941_PCLK_AUTO_SHIFT_CNT                             (1U)

/** DES_ID_DES_ID Register Filed */
/** Freeze device id field shift count */
#define BOARD_FPD_UB941_FREEZE_DEV_ID_SHIFT_CNT                         (0U)

/** GENERAL_STS Register Filed */
/** DSI Error field shift count */
#define BOARD_FPD_UB941_DSI_ERROR_SHIFT_CNT                             (6U)
/** DPHY Error field shift count */
#define BOARD_FPD_UB941_DPHY_ERROR_SHIFT_CNT                            (5U)
/** Link lost field shift count */
#define BOARD_FPD_UB941_LINK_LOST_SHIFT_CNT                             (4U)
/** Built In Self Test CRC field shift count */
#define BOARD_FPD_UB941_BIST_CRC_ERROR_SHIFT_CNT                        (3U)
/** PCLK detect field shift count */
#define BOARD_FPD_UB941_PCLK_DETECT_SHIFT_CNT                           (2U)
/** Deserailizer error field shift count */
#define BOARD_FPD_UB941_DES_ERROR_SHIFT_CNT                             (1U)
/** Link detect field shift count */
#define BOARD_FPD_UB941_LINK_DETECT_SHIFT_CNT                           (0U)

/** I2C_CONTROL Register Filed */
/** I2C pass all field shift count */
#define BOARD_FPD_UB941_I2C_PASS_ALL_SHIFT_CNT                          (7U)

/** Pattern generator field bit mask */
#define BOARD_FPD_UB941_PATTERN_GENERATOR_SHIFT_CNT                   (0U)
/** Color bars pattern select shift count */
#define BOARD_FPD_UB941_COLORS_BAR_PATTERN_SEL_SHIFT_CNT                (2U)
/** Pattern select shift count */
#define BOARD_FPD_UB941_PATTERN_SEL_SHIFT_CNT                           (4U)
/** Auto scroll Pattern field shift count */
#define BOARD_FPD_UB941_AUTO_SCROLL_PATTERN_SHIFT_CNT                   (0U)
/** Inverted color Pattern field shift count */
#define BOARD_FPD_UB941_INVERTED_COLOR_PATTERN_SHIFT_CNT                (1U)
/** Pattern generator 18-bit field shift count */
#define BOARD_FPD_UB941_PG_18B_SHIFT_CNT                                (4U)
/** Pattern generator external clock field shift count */
#define BOARD_FPD_UB941_PG_EXTCLK_SHIFT_CNT                             (5U)
/** Pattern generator timiing select field shift count */
#define BOARD_FPD_UB941_PG_TSEL_SHIFT_CNT                               (6U)

/** DISABLE DSI field bit mask */
#define BOARD_FPD_UB941_DISABLE_DSI_BIT_MASK                            (uint8_t)(0x01 << BOARD_FPD_UB941_DISABLE_DSI_SHIFT_CNT)
/** Digital reset1 field bit mask */
#define BOARD_FPD_UB941_DIGITAL_RESET1_BIT_MASK                         (uint8_t)(0x01 << BOARD_FPD_UB941_DIGITAL_RESET1_SHIFT_CNT)
/** Digital reset0 field bit mask */
#define BOARD_FPD_UB941_DIGITAL_RESET0_BIT_MASK                         (uint8_t)(0x01 << BOARD_FPD_UB941_DIGITAL_RESET0_SHIFT_CNT)

/** DSI1 clock P/N swap field bit mask */
#define BOARD_FPD_UB941_DSI1_CLK_PN_SWAP_BIT_MASK                       (uint8_t)(0x01 << BOARD_FPD_UB941_DSI1_CLK_PN_SWAP_SHIFT_CNT)
/** DSI1 data P/N swap field bit mask */
#define BOARD_FPD_UB941_DSI1_DATA_PN_SWAP_BIT_MASK                      (uint8_t)(0x01 << BOARD_FPD_UB941_DSI1_DATA_PN_SWAP_SHIFT_CNT)
/** DSI0 clock P/N swap field bit mask */
#define BOARD_FPD_UB941_DSI0_CLK_PN_SWAP_BIT_MASK                       (uint8_t)(0x01 << BOARD_FPD_UB941_DSI0_CLK_PN_SWAP_SHIFT_CNT)
/** DSI0 data P/N swap field bit mask */
#define BOARD_FPD_UB941_DSI0_DATA_PN_SWAP_BIT_MASK                      (uint8_t)(0x01 << BOARD_FPD_UB941_DSI0_DATA_PN_SWAP_SHIFT_CNT)

/** IND_ACC_CTL Register Fields */
/** Indirect access select field bit mask */
#define BOARD_FPD_UB941_IND_ACC_SEL_BIT_MASK                            (uint8_t)(0x07 << BOARD_FPD_UB941_IND_ACC_SEL_SHIFT_CNT)
/** Indirect access read field bit mask */
#define BOARD_FPD_UB941_IND_ACC_READ_BIT_MASK                           (uint8_t)(0x01 << BOARD_FPD_UB941_IND_ACC_READ_SHIFT_CNT)

/** GENERAL_CFG Register Filed */
/** Receive CRC checker enable field bit mask */
#define BOARD_FPD_UB941_RX_CRC_CHECKER_ENABLE_BIT_MASK                  (uint8_t)(0x01 << BOARD_FPD_UB941_RX_CRC_CHECKER_ENABLE_SHIFT_CNT)
/** Filter enable field bit mask */
#define BOARD_FPD_UB941_FILTER_ENABLE_BIT_MASK                          (uint8_t)(0x01 << BOARD_FPD_UB941_FILTER_ENABLE_SHIFT_CNT)
/** I2C pass through field bit mask */
#define BOARD_FPD_UB941_I2C_PASS_THROUGH_BIT_MASK                       (uint8_t)(0x01 << BOARD_FPD_UB941_I2C_PASS_THROUGH_SHIFT_CNT)
/** PCLK auto switch field bit mask */
#define BOARD_FPD_UB941_PCLK_AUTO_BIT_MASK                              (uint8_t)(0x01 << BOARD_FPD_UB941_PCLK_AUTO_SHIFT_CNT)

/** GENERAL_STS Register Filed */
/** DSI Error field bit mask */
#define BOARD_FPD_UB941_DSI_ERROR_BIT_MASK                              (uint8_t)(0x01 << BOARD_FPD_UB941_DSI_ERROR_SHIFT_CNT)
/** DPHY Error field bit mask */
#define BOARD_FPD_UB941_DPHY_ERROR_BIT_MASK                             (uint8_t)(0x01 << BOARD_FPD_UB941_DPHY_ERROR_SHIFT_CNT)
/** Link lost field bit mask */
#define BOARD_FPD_UB941_LINK_LOST_BIT_MASK                              (uint8_t)(0x01 << BOARD_FPD_UB941_LINK_LOST_SHIFT_CNT)
/** Built In Self Test CRC field bit mask */
#define BOARD_FPD_UB941_BIST_CRC_ERROR_BIT_MASK                         (uint8_t)(0x01 << BOARD_FPD_UB941_BIST_CRC_ERROR_SHIFT_CNT)
/** PCLK detect field bit mask */
#define BOARD_FPD_UB941_PCLK_DETECT_BIT_MASK                            (uint8_t)(0x01 << BOARD_FPD_UB941_PCLK_DETECT_SHIFT_CNT)
/** Deserailizer error field bit mask */
#define BOARD_FPD_UB941_DES_ERROR_BIT_MASK                              (uint8_t)(0x01 << BOARD_FPD_UB941_DES_ERROR_SHIFT_CNT)
/** Link detect field bit mask */
#define BOARD_FPD_UB941_LINK_DETECT_BIT_MASK                            (uint8_t)(0x01 << BOARD_FPD_UB941_LINK_DETECT_SHIFT_CNT)

/** I2C_CONTROL Register Filed */
/** I2C pass all field bit mask */
#define BOARD_FPD_UB941_I2C_PASS_ALL_BIT_MASK                           (uint8_t)(0x01 << BOARD_FPD_UB941_I2C_PASS_ALL_SHIFT_CNT)

/** DES_ID_DES_ID Register Filed */
/** Freeze device id field bit mask */
#define BOARD_FPD_UB941_FREEZE_DEV_ID_BIT_MASK                          (uint8_t)(0x01 << BOARD_FPD_UB941_FREEZE_DEV_ID_SHIFT_CNT)

/** BRIDGE_CFG Register Fields */
/** DSI bytes per pixel field bit mask */
#define BOARD_FPD_UB941_DSI_BYTES_PER_PIXEL_BIT_MASK                    (uint8_t)(0x03 << BOARD_FPD_UB941_DSI_BYTES_PER_PIXEL_SHIFT_CNT) 

/** BRIDGE_CFG2 Register Fields */
/** Bridge clock mode field bit mask */
#define BOARD_FPD_UB941_BRIDGE_LANE_MODE_BIT_MASK                        (uint8_t)(0x03 << BOARD_FPD_UB941_BRIDGE_LANE_MODE_SHIFT_CNT) 

/** DUAL_CTL2 Register Fields */
/** Frequency stability threshold field bit mask */
#define BOARD_FPD_UB941_FREQ_STBL_THR_BIT_MASK                          (uint8_t)(0x03 << BOARD_FPD_UB941_FREQ_STBL_THR_SHIFT_CNT) 

/** DUAL_STS_DUAL_STS_P1 Register Fields */
/** FPD Link3 ready status field bit mask */
#define BOARD_FPD_UB941_FPD3_LINK_RDY_BIT_MASK                          (uint8_t)(0x01 << BOARD_FPD_UB941_FPD3_LINK_RDY_SHIFT_CNT)
/** FPD Link3 transmit status field bit mask */
#define BOARD_FPD_UB941_FPD3_TX_STS_BIT_MASK                            (uint8_t)(0x01 << BOARD_FPD_UB941_FPD3_TX_STS_SHIFT_CNT)
/** DSI clock detect field bit mask */
#define BOARD_FPD_UB941_DSI_CLK_DET_BIT_MASK                            (uint8_t)(0x01 << BOARD_FPD_UB941_DSI_CLK_DET_SHIFT_CNT)
/** No DSI clock detect field bit mask */
#define BOARD_FPD_UB941_NO_DSI_CLK_BIT_MASK                             (uint8_t)(0x01 << BOARD_FPD_UB941_NO_DSI_CLK_SHIFT_CNT)
/** DSI stable frequency detect field bit mask */
#define BOARD_FPD_UB941_FREQ_STABLE_BIT_MASK                            (uint8_t)(0x01 << BOARD_FPD_UB941_FREQ_STABLE_SHIFT_CNT)

/** Pattern generator field bit mask */
#define BOARD_FPD_UB941_PATTERN_GENERATOR_BIT_MASK                      (uint8_t)(0x01 << BOARD_FPD_UB941_PATTERN_GENERATOR_SHIFT_CNT)
/** Color bars pattern select bit mask */
#define BOARD_FPD_UB941_COLORS_BAR_PATTERN_SEL_BIT_MASK                 (uint8_t)(0x01 << BOARD_FPD_UB941_COLORS_BAR_PATTERN_SEL_SHIFT_CNT)
/** Pattern select bit mask */
#define BOARD_FPD_UB941_PATTERN_SEL_BIT_MASK                            (uint8_t)(0x0F << BOARD_FPD_UB941_PATTERN_SEL_SHIFT_CNT)
/** Auto scroll Pattern field bit mask */
#define BOARD_FPD_UB941_AUTO_SCROLL_PATTERN_BIT_MASK                    (uint8_t)(0x01 << BOARD_FPD_UB941_AUTO_SCROLL_PATTERN_SHIFT_CNT)
/** Inverted color Pattern field bit mask */
#define BOARD_FPD_UB941_INVERTED_COLOR_PATTERN_BIT_MASK                 (uint8_t)(0x01 << BOARD_FPD_UB941_INVERTED_COLOR_PATTERN_SHIFT_CNT)
/** Pattern generator 18-bit field bit mask */
#define BOARD_FPD_UB941_PG_18B_BIT_MASK                                 (uint8_t)(0x01 << BOARD_FPD_UB941_PG_18B_SHIFT_CNT)
/** Pattern generator external clock field bit mask */
#define BOARD_FPD_UB941_PG_EXTCLK_BIT_MASK                              (uint8_t)(0x01 << BOARD_FPD_UB941_PG_EXTCLK_SHIFT_CNT)
/** Pattern generator timing select field bit mask */
#define BOARD_FPD_UB941_PG_TSEL_BIT_MASK                                (uint8_t)(0x01 << BOARD_FPD_UB941_PG_TSEL_SHIFT_CNT)


/** The DSI logic will assume the clock input is always in HS
        Mode and will bypass initialization requirements for the clock lane */
#define BOARD_FPD_UB941_DSI_CONTINUOUS_CLK_ENABLE                       (1U)
/** In Independent 2:2 mode, this controls the selected FPD-Link III port
        DSI_CONTINUOUS_CLK is initially loaded from the MODE_SEL1 strap options */
#define BOARD_FPD_UB941_DSI_CONTINUOUS_CLK_DISABLE                      (0U)
/** DSI Port 1 clock Lane P inputs mapped to P, N inputs mapped to N */
#define BOARD_FPD_UB941_CLK_LANE_PN_MAINTIAN                            (0U)
/** DSI Port 1 clock Lane P inputs mapped to N, N inputs mapped to P */
#define BOARD_FPD_UB941_CLK_LANE_PN_SWAP                                (1U)
/** DSI Port 1 Data Lane P inputs mapped to P, N inputs mapped to N */
#define BOARD_FPD_UB941_DATA_LANE_PN_MAINTIAN                           (0U)
/** DSI Port 1 Data Lane P inputs mapped to N, N inputs mapped to P */
#define BOARD_FPD_UB941_DATA_LANE_PN_SWAP                               (1U)
/** FPD Link error detected */
#define BOARD_FPD_UB941_LINK_DETECT                                     (0U)
/** FPD Link detect error status */
#define BOARD_FPD_UB941_DES_ERROR                                       (1U)
/** FPD Link detect error status */
#define BOARD_FPD_UB941_PCLK_DETECT                                     (2U)
/** FPD Link detect error status */
#define BOARD_FPD_UB941_BIST_CRC_ERROR                                  (3U)
/** FPD Link detect error status */
#define BOARD_FPD_UB941_LINK_LOST                                       (4U)
/** FPD Link detect error status */
#define BOARD_FPD_UB941_DPHY_ERROR                                      (5U)
/** FPD Link detect error status */
#define BOARD_FPD_UB941_DSI_ERROR                                       (6U)
/** FPD lane-1 select */
#define BOARD_FPD_UB941_LANES_1                                         (0U)
/** FPD lane-2 select */
#define BOARD_FPD_UB941_LANES_2                                         (1U)
/** FPD lane-3 select */
#define BOARD_FPD_UB941_LANES_3                                         (2U)
/** FPD lane-4 select */
#define BOARD_FPD_UB941_LANES_4                                         (3U)
/** FPD port-0 select */
#define BOARD_FPD_UB941_PORT0_SEL                                       (1U)
/** FPD port-1 select */
#define BOARD_FPD_UB941_PORT1_SEL                                       (2U)
/** FPD port-1 I2C enable */
#define BOARD_FPD_UB941_PORT1_I2C_EN                                    (4U)
/** DSI/D-PHY Port 0 indirect register access */
#define BOARD_FPD_UB941_DSI_PORT_INDIRECT_ACCESS                        (0U)
/** Pattern generator indirect register access */
#define BOARD_FPD_UB941_PATTERN_GEN_INDIRECT_ACESS                      (1U)
/** DSI/D-PHY Port 0 Digital Registers */
#define BOARD_FPD_UB941_DSI_PORT0_REG                                   (1U)
/** DSI/D-PHY Port 1 Digital Registers */                               
#define BOARD_FPD_UB941_DSI_PORT1_REG                                   (2U)
/** Reserved */                                                         
#define BOARD_FPD_UB941_RESEVED                                         (3U)
/** DSI Analog and PLL Control Registers */                             
#define BOARD_FPD_UB941_DSI_ANALOG_PLL_CNTRL_REG                        (4U)
/** FPD-Link III TX Port 0 Registers */                                 
#define BOARD_FPD_UB941_FPD_LINK_III_PORT0_REG                          (5U)
/** FPD-Link III TX Port 1 Registers */                                 
#define BOARD_FPD_UB941_FPD_LINK_III_PORT1_REG                          (6U)
/** Simultaneous access to FPD-Link III TX Port 0/1 Registers */
#define BOARD_FPD_UB941_FPD_LINK_III_PORT0_PORT1_REG                    (7U)
/** Select indirect read access mode */
#define BOARD_FPD_UB941_READ_ACCESS                                     (0U)
/** Select indirect write access mode */
#define BOARD_FPD_UB941_WRITE_ACCESS                                    (1U)
/** DSI Reference Clock Mode */
#define BOARD_FPD_UB941_DSI_REF_CLK_MODE                                (0U)    
/** External Reference Clock Mode. */                                   
#define BOARD_FPD_UB941_EXT_REF_CLK_MODE                                (1U)
/** Internal Reference Clock Mode. */                                   
#define BOARD_FPD_UB941_INT_REF_CLK_MODE                                (2U)
/** External Reference Clock Mode for Independent 2:2 Mode. */          
#define BOARD_FPD_UB941_EXT_REF_CLK_MODE_2_2                            (3U)
/** Confiures the FPD serializer freqency stability timing to 40 micro sec */
#define BOARD_FPD_UB941_FREQ_STBL_40                                    (0U)               
/** Confiures the FPD serializer freqency stability timing to 80 micro sec */
#define BOARD_FPD_UB941_FREQ_STBL_80                                    (1U)
/** Confiures the FPD serializer freqency stability timing to 320 micro sec */
#define BOARD_FPD_UB941_FREQ_STBL_320                                   (2U)
/** Confiures the FPD serializer freqency stability timing to 1280 micro sec */
#define BOARD_FPD_UB941_FREQ_STBL_1280                                  (3U)
/** Ready status unsuccessful */
#define BOARD_FPD_UB941_READY_STS_UNSUCCESSFUL                          (0U)
/** Ready status successful */                                          
#define BOARD_FPD_UB941_READY_STS_SUCCESSFUL                            (1U)
/** Transmit status unsuccessful */
#define BOARD_FPD_UB941_TX_STS_UNSUCCESFUL                              (0U)
/** Transmit status successful */                                       
#define BOARD_FPD_UB941_TX_STS_SUCCESSFUL                               (1U)
/** DSI clock detect status unsuccessful */
#define BOARD_FPD_UB941_DSI_CLK_DET_STS_UNSUCCESFUL                     (0U)   
/** DSI clock detect status successful */                               
#define BOARD_FPD_UB941_DSI_CLK_DET_STS_SUCCESSFUL                      (1U)
/** No DSI clock detected */
#define BOARD_FPD_UB941_NO_DSI_CLK_DETECTED                             (0U)     
/** DSI clock detected */                                               
#define BOARD_FPD_UB941_DSI_CLK_DETECTED                                (1U)
/** No DSI clock detected */
#define BOARD_FPD_UB941_DSI_FREQ_UNSTABLE                               (0U)
/** No DSI clock detected */                                            
#define BOARD_FPD_UB941_DSI_FREQ_STABLE                                 (1U)
/** No DSI clock detected */
#define BOARD_FPD_UB941_MODE_SEL_24                                     (0U)
/** No DSI clock detected */                                            
#define BOARD_FPD_UB941_MODE_SEL_18                                     (1U)
/** To select pattern generator internal clock source */
#define BOARD_FPD_UB941_INT_CLK_SRC                                     (0U)
/** To select pattern generator external clock source */                
#define BOARD_FPD_UB941_EXT_CLK_SRC                                     (1U)
/** To select pattern generator external video timing source */
#define BOARD_FPD_UB941_EXT_VIDEO_TIMING                                (0U)         
/** To select pattern generator internal clock source */               
#define BOARD_FPD_UB941_OWN_VIDEO_TIMING                                (1U)
/**To enable the indirect register read*/
#define BOARD_FPD_UB941_Indirect_Register_Read_ENABLE                   (1U)
/**To disable the indirect register read*/
#define BOARD_FPD_UB941_INDIRECT_REG_RD_DISABLE                  (0U)

/**Pattern - Checkerboard*/
#define BOARD_FPD_UB941_PATTERN_CHECKERBOARD                            (0U)
/**Pattern - White/Black*/  
#define BOARD_FPD_UB941_PATTERN_WHITE_BLACK                             (1U)
/**Pattern - Black/White*/                                              
#define BOARD_FPD_UB941_PATTERN_BLACK_WHITE                             (2U)
/**Pattern - Red/Cyan*/                                                 
#define BOARD_FPD_UB941_PATTERN_RED_CYAN                                (3U)
/**Pattern - Green/Magenta*/                                            
#define BOARD_FPD_UB941_PATTERN_GREEN_MAGNETA                           (4U)
/**Pattern - Blue/Yellow*/                                              
#define BOARD_FPD_UB941_PATTERN_BLUE_YELLOW                             (5U)
/**Pattern - Horizontally Scaled Black to White/White to Black*/        
#define BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2WHT_WHT2BLK      (6U)
/**Pattern - Horizontally Scaled Black to Red/White to Cyan*/           
#define BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2RED_WHT2CYN      (7U)
/**Pattern - Horizontally Scaled Black to Green/White to Magenta*/      
#define BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2GRN_WHT2MAG      (8U)
/**Pattern - Horizontally Scaled Black to Blue/White to Yellow*/        
#define BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2BLU_WHT2YEL      (9U)
/**Pattern - Vertically Scaled Black to White/White to Black*/          
#define BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2WHT_WHT2BLK        (10U)
/**Pattern - Vertically Scaled Black to Red/White to Cyan*/             
#define BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2RED_WHT2CYN        (11U)
/**Pattern - Vertically Scaled Black to Green/White to Magenta*/        
#define BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2GRN_WHT2MAG        (12U)
/**Pattern - Vertically Scaled Black to Blue/White to Yellow*/          
#define BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2BLU_WHT2YEL        (13U)
/**Pattern - Custom color (or its inversion) configured in PGRS, PGGS,PGBS registers*/
#define BOARD_FPD_UB941_PATTERN_CUSTOM_COLORS                           (14U)
/**Pattern - VCOM*/
#define BOARD_FPD_UB941_PATTERN_VCOM                                    (15U)

/**Indirect Access Register Read bit mask */
#define BOARD_FPD_UB941_IND_ACC_CTL_READ_WRITE_BIT_MASK                 (1U)
/**FPD-Link III TX Mode bit mask*/
#define BOARD_FPD_UB941_FPD3_TX_MODE_BIT_MASK                           (7U)
/**Auto-Detect FPD-Link III mode (Single, Dual, or Replicate)*/
#define BOARD_FPD_UB941_AUTO_DETECT_FPD3_MODE                           (0U)
/**Forced Single FPD-Link III Transmitter mode (Port 1 disabled)*/
#define BOARD_FPD_UB941_FORCED_SINGLE_FPD3_TRANSMITTER_MODE             (1U)
/**Forced Dual FPD-Link III Transmitter mode*/
#define BOARD_FPD_UB941_FORCED_DUAL_FPD3_TRANSMITTER_MODE               (3U)
/**Auto-Detect FPD-Link III mode (Single or Replicate only, Dual disabled)*/
#define BOARD_FPD_UB941_AUTO_DETECT_FPD3_SINGLE_MODE                    (4U)
/**Forced Independent 2:2 mode*/
#define BOARD_FPD_UB941_FORCED_INDEPENDENT_2_2_MODE                     (5U)
/**Forced Splitter Mode (half of video stream on each port)*/
#define BOARD_FPD_UB941_FORCED_SPLITTER_MODE                            (7U)
/**DSI Continuous Clock Mode shift count*/
#define BOARD_FPD_UB941_DSI_CONTINUOUS_CLK_SHIFT_CNT                    (7U)
/**DSI Continuous Clock Mode bit mask*/
#define BOARD_FPD_UB941_DSI_CONTINUOUS_CLK_BIT_MASK                     (uint8_t)(0x01 << BOARD_FPD_UB941_DSI_CONTINUOUS_CLK_SHIFT_CNT)
/**Digital reset 1 bit mask*/
#define BOARD_FPD_UB941_DIGITAL_RESET_BIT_MASK                          (uint8_t)(0x01 << BOARD_FPD_UB941_DIGITAL_RESET_SHIFT_CNT)
/**Digital reset 1 shift count*/
#define BOARD_FPD_UB941_DIGITAL_RESET_SHIFT_CNT                         (1U)
/**Select i2c access port mask */
#define BOARD_FPD_UB941_I2C_ACCESS_PORT_MASK                          (7U)

/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_FPD_DS90UB941
 *
 *  \defgroup BOARD_LIB_DEVICES_FPD_DS90UB941_APIS Application Interfaces
 *
 *  Application Interfaces provided by DS90UB941 FPD-Link device library.
 *
 *  @{
 *
 */

/**
 * \brief  DSI Reset mode control
 *
 * This function is used for configuring the analog (or)
 * digital DSI reset mode.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Normal operation (or) Reset
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetResetModeCtrl(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t cfgMode);

/**
 * \brief Digital reset1 mode control
 *
 * This function is used for configuring the operational
 * mode of Digital RESET1.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Normal operation (or) Reset
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetDigtialRst1ModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode);

/**
 * \brief Digital reset0 mode control
 *
 * This function is used for configuring the operational
 * mode of Digital RESET0.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Normal operation (or) Reset
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetDigtialRst0ModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode);

/**
 * \brief DSI1 clock lane pin order select
 *
 * This function is used to select the DSI1 clock lane pin order.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   operMode      [IN]   Operational mode to be configured
 *                               BOARD_FPD_UB941_CLK_LANE_PN_MAINTIAN - DSI Port1
 *                               Clock Lane P inputs mapped to P, N inputs
 *                               mapped to N
 *                               BOARD_FPD_UB941_CLK_LANE_PN_SWAP - DSI Port1
 *                               Clock Lane P inputs mapped to P, N inputs
 *                               mapped to P
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetDsi1ClkPinOrd(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t operMode);

/**
 * \brief DSI1 data lane pin order select
 *
 * This function is used to select the DSI1 data lane pin order.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   operMode      [IN]   Operational mode to be configured
 *                               BOARD_FPD_UB941_DATA_LANE_PN_MAINTIAN - DSI Port1
 *                               Data Lane P inputs mapped to P, N
 *                               input smapped to N
 *                               BOARD_FPD_UB941_DATA_LANE_PN_SWAP     - DSI Port1
 *                               Data Lane P inputs mapped to P, N
 *                               inputs mapped to P
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelDsi1DataPinOrd(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t operMode);

/**
 * \brief DSI0 clock lane pin order select
 *
 * This function is used to select the DSI0 clock lane pin order.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   operMode      [IN]   Operational mode to be configured
 *                               BOARD_FPD_UB941_CLK_LANE_PN_MAINTIAN - DSI Port0
 *                               Clock Lane P inputs mapped to P, N inputs
 *                               mapped to N
 *                               BOARD_FPD_UB941_CLK_LANE_PN_SWAP - DSI Port0
 *                               Clock Lane P inputs mapped to P, N inputs
 *                               mapped to P
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelDsi0ClkPinOrd(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t operMode);

/**
 * \brief DSI0 data lane pin order select
 *
 * This function is used to select the DSI0 data lane pin order.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   operMode      [IN]   Operational mode to be configured
 *                               BOARD_FPD_UB941_DATA_LANE_PN_MAINTIAN - DSI Port0
 *                               Data Lane P inputs mapped to P, N
 *                               input smapped to N
 *                               BOARD_FPD_UB941_DATA_LANE_PN_SWAP     - DSI Port0
 *                               Data Lane P inputs mapped to P, N
 *                               inputs mapped to P
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelDsi0DataPinOrd(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t operMode);

/**
 * \brief Set deserializer device Id
 *
 * This function is used for setting the user configurable
 * device ID for remote deserializer connected to serializer.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   serSlvAddr    [IN]   Deserailizer device ID.
 *
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941DevIdCfg(void *handle,
                                    Board_FpdModuleObj *fpdModParams,
                                    uint8_t serSlvAddr);

/**
 * \brief Get DSI general error status
 *
 * This function is used to read the general status of different err fileds.
 *
 * \param   handle         [IN]      Low level driver handle
 * \param   fpdModParams   [IN]      FPD module params
 * \param   errStatus      [IN/OUT]  Buffer to hold the error status
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetDsiGenSts(void *handle,
                                        Board_FpdModuleObj *fpdModParams,
                                        uint8_t *errStatus);

/**
 * \brief I2C pass all mode control
 *
 * This function is used to Enable/Disable the I2C Pass All mode.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetI2CPassAllModeCtrl(void *handle,
                                                 Board_FpdModuleObj *fpdModParams,
                                                 uint8_t cfgMode);

/**
 * \brief Select I2C Access port
 *
 * This function is used to selects Port for register access from
 * primary I2C address
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   portSel       [IN]   Port to be selected
 *                               BOARD_FPD_UB941_PORT0_SEL    - Port0 selected
 *                               BOARD_FPD_UB941_PORT1_SEL    - Port1 selected
 *                               BOARD_FPD_UB941_PORT1_I2C_EN - Enables the secondary
 *                               I2C address
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelI2CAccessPort(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            uint8_t portSel);

/**
 * \brief Indirect register acces block select
 *
 * This function is used to select indirect register access block.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   regBlk        [IN]   Register block to be selected
 *                               BOARD_FPD_UB941_DSI_PORT0_REG
 *                                    - DSI/D-PHY Port 0 Digital Registers
 *
 *                               BOARD_FPD_UB941_DSI_PORT1_REG
 *                                    - DSI/D-PHY Port 1 Digital Registers
 *
 *                               BOARD_FPD_UB941_DSI_ANALOG_PLL_CNTRL_REG     
 *                                    - DSI Analog and PLL Control Registers
 *
 *                               BOARD_FPD_UB941_FPD_LINK_III_PORT0_REG       
 *                                    - FPD-Link III TX Port 0 Registers
 *
 *                               BOARD_FPD_UB941_FPD_LINK_III_PORT1_REG       
 *                                    - FPD-Link III TX Port 1 Registers
 *
 *                               BOARD_FPD_UB941_FPD_LINK_III_PORT0_PORT1_REG 
 *                                    - Simultaneous access to FPD-Link III
 *                                      TX Port 0/1 Registers
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941IndirRegAccBlkSel(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t regBlk);

/**
 * \brief Indirect register access mode select
 *
 * This function is used to select indirect register access mode.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   accessMode    [IN]   Indirect access mode to be selected.
 *                               READ_ACCESS  - Read Access selected
 *                               WRITE_ACCESS - Write Access selected.
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941InDirRegAccModeSel(void *handle,
                                              Board_FpdModuleObj *fpdModParams,
                                              uint8_t accessMode);

/**
 * \brief Receive CRC checker enable
 *
 * This function is used to enable/disable CRC Checker.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetRxCRCCheckerEn(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode);

/**
 * \brief Set filter enable
 *
 * This function is used to enable/disable filter.
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetFilterEn(void *handle,
                                       Board_FpdModuleObj *fpdModParams,
                                       uint8_t cfgMode);
/**
 * \brief  configure I2C pass through mode
 *
 * This function is used to enable/disable pass through mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetI2CPassThrModeCfg(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t cfgMode);

/**
 * \brief  configure PCLK auto enable mode
 *
 * This function is used to enable/disable PCLK AUTO mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetPCLKAutoEnModeCfg(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t cfgMode);

/**
 * \brief  DSI indirect register write
 *
 * This function is used to write to the DSI indirect registers
 *
 * \param  handle        [IN]  Low level driver handle
 * \param  fpdModParams  [IN]   FPD module params
 * \param  regBlkType    [IN]  Indirect register block type
 *                             BOARD_FPD_UB941_DSI_PORT_INDIRECT_ACCESS
 *                                 - To enable DSI port register access
 *                             PATTERN_GEN_INDIRECT_ACESS
 *                                 - To enable Pattern Gen register access
 * \param  cfgRegAddr   [IN]   Register address to be accessed 
 * \param  cfgRegData   [IN]   Register data to be programmed
 *
 * \return Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941DsiIndirRegWr(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t regBlkType,
                                         uint8_t cfgRegAddr,
                                         uint8_t cfgRegData);

/**
 * \brief  Set DSI bytes per pixel
 *
 * This function is used to configure the DSI bytes per pixel
 *
 * \param  handle          [IN]  Low level driver handle
 * \param  fpdModParams    [IN]   FPD module params
 * \param  bytesPerPixel   [IN]  Number of DSI Bytes Per Pixel
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetPixelBytes(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t bytesPerPixel);

/**
 * \brief  Set FPD bridge clock mode
 *
 * This function is used to configure the bridge clocking mode
 *
 * \param  handle        [IN]  Low level driver handle
 * \param  fpdModParams  [IN]   FPD module params
 * \param  clkMode       [IN]  Bridge Clocking mode
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetBridgeClkModeCtrl(void *handle,
                                                Board_FpdModuleObj *fpdModParams,
                                                uint8_t clkMode);

/**
 * \brief  Set frequency stability threshold
 *
 * This function is used to configure the frequency stability threshold
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   freqStblThr   [IN]   Frequency Stability Threshold
 *                               BOARD_FPD_UB941_FREQ_STBL_40   - 40 micro sec
 *                               BOARD_FPD_UB941_FREQ_STBL_80   - 80 micro sec
 *                               BOARD_FPD_UB941_FREQ_STBL_320  - 320 micro sec
 *                               BOARD_FPD_UB941_FREQ_STBL_1280 - 1280 micro sec
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetFreqStblThr(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t freqStblThr);

/**
 * \brief  Get FPD Link-III link ready status
 *
 * This function is used to get the FPD Link-III ready status
 *
 * \param  handle        [IN]      Low level driver handle
 * \param  fpdModParams  [IN]      FPD module params
 * \param  stsFlag       [IN/OUT]  FPD LinkIII ready status
 *                                 False - FPD Link III module ready
 *                                 True  - FPD Link III module not ready
 *
 * \return Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetFpd3LinkRdySts(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             bool *stsFlag);

/**
 * \brief  Get FPD Link-III transmit status
 *
 * This function is used to get the FPD LinkIII transmit status.
 *
 * \param  handle        [IN]      Low level driver handle
 * \param  fpdModParams  [IN]      FPD module params
 * \param  stsFlag       [IN/OUT]  FPD LinkIII transmit status
 *                                 False - FPD Link III transmit unsuccessful
 *                                 True  - FPD Link III transmit successful
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetFpd3LinkTxSts(void *handle,
                                            Board_FpdModuleObj *fpdModParams,
                                            bool *stsFlag);

/**
 * \brief  Get DSI clock detect status
 *
 * This function is used to get DSI clock detect status.
 *
 * \param  handle        [IN]      Low level driver handle
 * \param  fpdModParams  [IN]      FPD module params
 * \param  stsFlag       [IN/OUT]  DSI clock detection status
 *                                 False - DSI clock detection failed
 *                                 True  - DSI clock detection successful
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetDsiClkDetSts(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           bool *stsFlag);

/**
 * \brief  Get selected port DSI clock detect status
 *
 *  This function is used to get DSI clock detect status 
 *  of selected port.
 *
 * \param  handle        [IN]      Low level driver handle
 * \param  fpdModParams  [IN]      FPD module params
 * \param  stsFlag       [IN/OUT]  DSI clock detection status of selected port
 *                                 False - DSI clock detection failed
 *                                 True  - DSI clock detection successful
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetSelPortDsiClkDetSts(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  bool *stsFlag);

/**
 * \brief  Get frequency stability status
 *
 * This function is used to get DSI frequency stability status
 *
 * \param  handle        [IN]       Low level driver handle
 * \param  fpdModParams  [IN]       FPD module params
 * \param  stsFlag       [IN/OUT]   Ferquency stability status
 *                                  False - Frequency status failed
 *                                  True  - Frequency status successful
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941GetFreqStabilitySts(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               bool *stsFlag);


/**
 * \brief  Select pattern generator clock source
 *
 * This function is used to select the pattern generator clk source
 *
 * \param  handle        [IN]  Low level driver handle
 * \param  fpdModParams  [IN]   FPD module params
 * \param  clkSrc        [IN]  Pattern generator clock src select
 *                             BOARD_FPD_UB941_INT_CLK_SRC - Internal divider clock
 *                             BOARD_FPD_UB941_EXT_CLK_SRC - External Pixel clock
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelPGClkSrc(void *handle,
                                       Board_FpdModuleObj *fpdModParams,
                                       uint8_t clkSrc);

/**
 * \brief  Select pattern generator mode
 *
 * This function is used to select the pattern generator mode
 *
 * \param  handle        [IN]  Low level driver handle
 * \param  fpdModParams  [IN]  FPD module params
 * \param  modeSel       [IN]  Pattern generator mode select
 *                             BOARD_FPD_UB941_MODE_SEL_24 - 24-bit mode
 *                             BOARD_FPD_UB941_MODE_SEL_18 - 18-bit mode
 *
 *  \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelPGMode(void *handle,
                                     Board_FpdModuleObj *fpdModParams,
                                     uint8_t modeSel);

/**
 * \brief  Pattern generator timing mode control
 *
 * This function is used to set the pattern generator vedio timing mode
 *
 * \param  handle        [IN]  Low level driver handle
 * \param  fpdModParams  [IN]  FPD module params
 * \param  pgTSel        [IN]  Pattern generator timing select
 *                             BOARD_FPD_UB941_EXT_VIDEO_TIMING
 *                             - Pattern Generator uses external video timing
 *                             BOARD_FPD_UB941_OWN_VIDEO_TIMING
 *                             - Pattern Generator creates its own video timing
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetPGTModeCtrl(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          uint8_t pgTSel);
/**
 * \brief  configure indirect register read enable mode
 *
 * This function is used to enable/disable PCLK AUTO mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetIndirRegRdEn(void *handle,
                                           Board_FpdModuleObj *fpdModParams,
                                           uint8_t cfgMode);

/**
 * \brief  configure transmit mode
 *
 * This function is used to confiure the transmit mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   operMode      [IN]   operMode - BOARD_FPD_UB941_AUTO_DETECT_FPD3_MODE 
 *                                          BOARD_FPD_UB941_FORCED_SINGLE_FPD3_TRANSMITTER_MODE
 *                                          BOARD_FPD_UB941_FORCED_DUAL_FPD3_TRANSMITTER_MODE
 *                                          BOARD_FPD_UB941_AUTO_DETECT_FPD3_SINGLE_MODE
 *                                          BOARD_FPD_UB941_FORCED_INDEPENDENT_2_2_MODE
 *                                          BOARD_FPD_UB941_FORCED_SPLITTER_MODE
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941Tx_Mode(void *handle,
                                   Board_FpdModuleObj *fpdModParams,
                                   uint8_t operMode);
                                        
/**
 * \brief  configure serializer clock mode control mode
 *
 * This function is used to enable/disable PCLK AUTO mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetSerClkModeCtrl(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode);
                                                
/**
 * \brief  configure clock lane mode control mode
 *
 * This function is used to enable/disable PCLK AUTO mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   laneMode       [IN]  lane mode sel:
 *                                  -BOARD_FPD_UB941_LANES_1
 *                                  -BOARD_FPD_UB941_LANES_2
 *                                  -BOARD_FPD_UB941_LANES_3
 *                                  -BOARD_FPD_UB941_LANES_4
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetDsiLaneModeCtrl(void *handle,
                                              Board_FpdModuleObj *fpdModParams,
                                              uint8_t laneMode);
                                                
/**
 * \brief  Digital Reset mode control
 *
 * Resets the entire digital block including registers
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Normal operation (or) Reset
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetDigitalRst1ModeCtrl(void *handle,
                                                  Board_FpdModuleObj *fpdModParams,
                                                  uint8_t cfgMode);
                                                  
/**
 * \brief  I2C bus frequency set
 *
 * This function is used for setting the deserializer I2C bus frequency
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgBitRate    [IN]   Indicates I2C serial clock frequency
 *                               config modes
 *                               BOARD_FPD_KBPS_100 - 100 KBPS
 *                               BOARD_FPD_KBPS_400 - 400 KBPS
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetI2CBusFreq(void *handle,
                                         Board_FpdModuleObj *fpdModParams,
                                         uint8_t cfgBitRate);

/**
 * \brief  Remote deserializer slave device id config
 *
 * This function is used for configuring the remote deserializer slave device ID
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   fpdRmtParams  [IN]   Remote device module params
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941RmtDesAliasCfg(void *handle,
                                          Board_FpdModuleObj *fpdModParams,
                                          Board_FpdRmtDevObj *fpdRmtParams);

/**
 * \brief  Inverted color pattern select
 *
 * This function is used to initialize the ub941 DSI module.
 *
 * \param   handle         [IN]  Low level driver handle
 * \param   fpdModParams   [IN]  FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return  Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetInvtdClrPattEn(void *handle,
                                             Board_FpdModuleObj *fpdModParams,
                                             uint8_t cfgMode);

/**
 * \brief  configure auto scroll for pattern
 *
 * This function is used to enable/disable pass through mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SetAutoScrollPattEn(void *handle,
                                               Board_FpdModuleObj *fpdModParams,
                                               uint8_t cfgMode);

/**
 * \brief  configure color bars
 *
 * This function is used to enable/disable pass through mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941ColorBarEn(void *handle,
                                      Board_FpdModuleObj *fpdModParams,
                                      uint8_t cfgMode);

/**
 * \brief  configure color bars
 *
 * This function is used to enable/disable pass through mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   patternSel    [IN]   Indicates the pattern to be displayed:
 *                                BOARD_FPD_UB941_PATTERN_CHECKERBOARD
 *                                BOARD_FPD_UB941_PATTERN_WHITE_BLACK
 *                                BOARD_FPD_UB941_PATTERN_BLACK_WHITE
 *                                BOARD_FPD_UB941_PATTERN_RED_CYAN
 *                                BOARD_FPD_UB941_PATTERN_GREEN_MAGNETA
 *                                BOARD_FPD_UB941_PATTERN_BLUE_YELLOW
 *                                BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2WHT_WHT2BLK
 *                                BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2RED_WHT2CYN
 *                                BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2GRN_WHT2MAG
 *                                BOARD_FPD_UB941_PATTERN_HORIZONTALLY_SCALE_BLK2BLU_WHT2YEL
 *                                BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2WHT_WHT2BLK
 *                                BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2RED_WHT2CYN
 *                                BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2GRN_WHT2MAG
 *                                BOARD_FPD_UB941_PATTERN_VERTICALLY_SCALE_BLK2BLU_WHT2YEL
 *                                BOARD_FPD_UB941_PATTERN_CUSTOM_COLORS
 *                                BOARD_FPD_UB941_PATTERN_VCOM
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941SelPatt(void *handle,
                                   Board_FpdModuleObj *fpdModParams,
                                   uint8_t patternSel);

/**
 * \brief  configure pattern display
 *
 * This function is used to enable/disable pass through mode
 *
 * \param   handle        [IN]   Low level driver handle
 * \param   fpdModParams  [IN]   FPD module params
 * \param   cfgMode       [IN]   Config mode - Indicates Enable or Disable
 *
 * \return   Board_STATUS in case of success or appropriate error code.
 *
 */
Board_STATUS Board_fpdUb941PattGenEn(void *handle,
                                     Board_FpdModuleObj *fpdModParams,
                                     uint8_t cfgMode);

/**
 * \brief  Get ub941 i2c address.
 *
 * This function is used to get the I2C address and
 * channel details of UB960 module.
 *
 * \param   domain    [IN]  I2C instance domain
 * \param   chNum     [IN]  buffer to hold i2c channel number
 * \param   i2cAddr   [IN]  buffer to hold i2c address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
void Board_fpdUb941GetI2CAddr(uint8_t *domain,
                              uint8_t *chNum,
                              uint8_t *i2cAddr);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _DS90UB941 */

/* @} */
