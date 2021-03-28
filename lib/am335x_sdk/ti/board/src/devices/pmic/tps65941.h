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
 * \file   tps65941.h
 *
 * \brief  The macro definitions, structures and function prototypes for
 *         configuring TPS65941 PMIC.
 *
 *
 */
 
/**
 *
 *  \ingroup BOARD_LIB_DEVICES_POWER 
 *
 *  \defgroup BOARD_LIB_DEVICES_POWER_TPS65941 TPS65941 PMIC Library
 *
 *  Provides the interfaces for configuring TPS65941 PMIC device.
 *
 *  @{
 *
 */
/* @} */

#ifndef _TPS65941_H_
#define _TPS65941_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>

#include <ti/board/board.h>

#include <ti/board/src/devices/common/common.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_POWER_TPS65941 
 *
 *  \defgroup BOARD_LIB_DEVICES_POWER_TPS65941_TYPES Data Types
 *
 *  Data types used by TPS65941 PMIC device library.
 *
 *  @{
 *
 */
 
/** GPIO Register Offsets */
#define BOARD_TPS65941_GPIO1_CONF                           (0x31U)
#define BOARD_TPS65941_GPIO2_CONF                           (0x32U)
#define BOARD_TPS65941_GPIO3_CONF                           (0x33U)
#define BOARD_TPS65941_GPIO4_CONF                           (0x34U)
#define BOARD_TPS65941_GPIO5_CONF                           (0x35U)
#define BOARD_TPS65941_GPIO6_CONF                           (0x36U)
#define BOARD_TPS65941_GPIO7_CONF                           (0x37U)
#define BOARD_TPS65941_GPIO8_CONF                           (0x38U)
#define BOARD_TPS65941_GPIO9_CONF                           (0x39U)
#define BOARD_TPS65941_GPIO10_CONF                          (0x3AU)
#define BOARD_TPS65941_GPIO11_CONF                          (0x3BU)
#define BOARD_TPS65941_NPWRON_CONF                          (0x3CU)
#define BOARD_TPS65941_GPIO_OUT_1                           (0x3DU)
#define BOARD_TPS65941_GPIO_OUT_2                           (0x3EU)
#define BOARD_TPS65941_GPIO_IN_1                            (0x3FU)
#define BOARD_TPS65941_GPIO_IN_2                            (0x40U)

/** BUCK Power resource Register Offsets */
#define BOARD_TPS65941_BUCK1_CTRL                           (0x04U)
#define BOARD_TPS65941_BUCK2_CTRL                           (0x06U)
#define BOARD_TPS65941_BUCK3_CTRL                           (0x08U)
#define BOARD_TPS65941_BUCK4_CTRL                           (0x0AU)
#define BOARD_TPS65941_BUCK5_CTRL                           (0x0CU)
#define BOARD_TPS65941_BUCK1_CONF                           (0x05U)
#define BOARD_TPS65941_BUCK2_CONF                           (0x07U)
#define BOARD_TPS65941_BUCK3_CONF                           (0x09U)
#define BOARD_TPS65941_BUCK4_CONF                           (0x0BU)
#define BOARD_TPS65941_BUCK5_CONF                           (0x0DU)
#define BOARD_TPS65941_BUCK1_VOUT_1                         (0x0EU)
#define BOARD_TPS65941_BUCK1_VOUT_2                         (0x0FU)
#define BOARD_TPS65941_BUCK2_VOUT_1                         (0x10U)
#define BOARD_TPS65941_BUCK2_VOUT_2                         (0x11U)
#define BOARD_TPS65941_BUCK3_VOUT_1                         (0x12U)
#define BOARD_TPS65941_BUCK3_VOUT_2                         (0x13U)
#define BOARD_TPS65941_BUCK4_VOUT_1                         (0x14U)
#define BOARD_TPS65941_BUCK4_VOUT_2                         (0x15U)
#define BOARD_TPS65941_BUCK5_VOUT_1                         (0x16U)
#define BOARD_TPS65941_BUCK5_VOUT_2                         (0x17U)
#define BOARD_TPS65941_BUCK1_PG_WIN                         (0x18U)
#define BOARD_TPS65941_BUCK2_PG_WIN                         (0x19U)
#define BOARD_TPS65941_BUCK3_PG_WIN                         (0x1AU)
#define BOARD_TPS65941_BUCK4_PG_WIN                         (0x1BU)
#define BOARD_TPS65941_BUCK5_PG_WIN                         (0x1CU)

/** LDO Power resource Register Offsets */
#define BOARD_TPS65941_LDO1_CTRL                            (0x1DU)
#define BOARD_TPS65941_LDO2_CTRL                            (0x1EU)
#define BOARD_TPS65941_LDO3_CTRL                            (0x1FU)
#define BOARD_TPS65941_LDO4_CTRL                            (0x20U)
#define BOARD_TPS65941_LDO1_VOUT                            (0x23U)
#define BOARD_TPS65941_LDO2_VOUT                            (0x24U)
#define BOARD_TPS65941_LDO3_VOUT                            (0x25U)
#define BOARD_TPS65941_LDO4_VOUT                            (0x26U)
#define BOARD_TPS65941_LDO1_PG_WIN                          (0x27U)
#define BOARD_TPS65941_LDO2_PG_WIN                          (0x28U)
#define BOARD_TPS65941_LDO3_PG_WIN                          (0x29U)
#define BOARD_TPS65941_LDO4_PG_WIN                          (0x2AU)

/** VCCA Voltage monitor Register Offsets */
#define BOARD_TPS65941_VCCA_VMON_CTRL                       (0x2BU)
#define BOARD_TPS65941_VCCA_PG_WINDOW                       (0x2CU)

/** Interrupt Mask Register Offsets */
#define BOARD_TPS65941_BUCK_MASK                            (0x49)
#define BOARD_TPS65941_LDO_MASK                             (0x4C)
#define BOARD_TPS65941_GPIO_MASK                            (0x4F)
#define BOARD_TPS65941_STARTUP_MASK                         (0x52)
#define BOARD_TPS65941_MISC_WARN_MASK                       (0x53)
#define BOARD_TPS65941_MOD_ERR_MASK                         (0x54)
#define BOARD_TPS65941_FSM_ERR_MASK                         (0x56)

/** Interrupt Register Offsets */
#define BOARD_TPS65941_INT_TOP                              (0x5A)
#define BOARD_TPS65941_BUCK_INT                             (0x5C)
#define BOARD_TPS65941_LDO_VMON_INT                         (0x60)
#define BOARD_TPS65941_GPIO_INT                             (0x63)
#define BOARD_TPS65941_STARTUP_INT                          (0x65)
#define BOARD_TPS65941_MISC_INT                             (0x66)
#define BOARD_TPS65941_MOD_ERR_INT                          (0x67)
#define BOARD_TPS65941_SEV_ERR_INT                          (0x68)
#define BOARD_TPS65941_FSM_ERR_INT                          (0x69)

/** Status Register Offset */
#define BOARD_TPS65941_STAT_MISC                            (0x74U)
#define BOARD_TPS65941_STAT_MODERATE_ERR                    (0x75U)
#define BOARD_TPS65941_STAT_SEVERE_ERR                      (0x76U)

/** PGOOD Register Offsets */
#define BOARD_TPS65941_PGOOD_1                              (0x78U)
#define BOARD_TPS65941_PGOOD_2                              (0x79U)
#define BOARD_TPS65941_PGOOD_3                              (0x7AU)
#define BOARD_TPS65941_PGOOD_4                              (0x7BU)
 
/** TPS65941 Configuration Register Offsets */
#define BOARD_TPS65941_CONFIG_1                             (0x7DU)
#define BOARD_TPS65941_CONFIG_2                             (0x7EU)

/** TPS65941 ESM Register Offsets */
#define BOARD_TPS65941_ESM_MCU_START                        (0x8FU)
#define BOARD_TPS65941_ESM_MCU_DELAY1                       (0x90U)
#define BOARD_TPS65941_ESM_MCU_DELAY2                       (0x91U)
#define BOARD_TPS65941_ESM_MCU_MODE_CFG                     (0x92U)
#define BOARD_TPS65941_ESM_MCU_HMAX                         (0x93U)
#define BOARD_TPS65941_ESM_MCU_HMIN                         (0x94U)
#define BOARD_TPS65941_ESM_MCU_LMAX                         (0x95U)
#define BOARD_TPS65941_ESM_MCU_LMIN                         (0x96U)
#define BOARD_TPS65941_ESM_MCU_ERR_CNT                      (0x97U)
#define BOARD_TPS65941_ESM_SOC_START                        (0x98U)
#define BOARD_TPS65941_ESM_SOC_DELAY1                       (0x99U)
#define BOARD_TPS65941_ESM_SOC_DELAY2                       (0x9AU)
#define BOARD_TPS65941_ESM_SOC_MODE_CFG                     (0x9BU)
#define BOARD_TPS65941_ESM_SOC_HMAX                         (0x9CU)
#define BOARD_TPS65941_ESM_SOC_HMIN                         (0x9DU)
#define BOARD_TPS65941_ESM_SOC_LMAX                         (0x9EU)
#define BOARD_TPS65941_ESM_SOC_LMIN                         (0x9FU)
#define BOARD_TPS65941_ESM_SOC_ERR_CNT                      (0xA0U)

/** TPS65941 RTC time and date Register Offsets */
#define BOARD_TPS65941_RTC_SECONDS                          (0xB5U)
#define BOARD_TPS65941_RTC_MINUTES                          (0xB6U)
#define BOARD_TPS65941_RTC_HOURS                            (0xB7U)
#define BOARD_TPS65941_RTC_DAYS                             (0xB8U)
#define BOARD_TPS65941_RTC_MONTHS                           (0xB9U)
#define BOARD_TPS65941_RTC_YEARS                            (0xBAU)
#define BOARD_TPS65941_RTC_WEEKS                            (0xBBU)

/** TPS65941 Alarm time and date Register Offsets */
#define BOARD_TPS65941_ALARM_SECONDS                        (0xBCU)
#define BOARD_TPS65941_ALARM_MINUTES                        (0xBDU)
#define BOARD_TPS65941_ALARM_HOURS                          (0xBEU)
#define BOARD_TPS65941_ALARM_DAYS                           (0xBFU)
#define BOARD_TPS65941_ALARM_MONTHS                         (0xC0U)
#define BOARD_TPS65941_ALARM_YEARS                          (0xC1U)

/** TPS65941 RTC Register Offsets */
#define BOARD_TPS65941_RTC_CTRL_1                           (0xC2U)
#define BOARD_TPS65941_RTC_CTRL_2                           (0xC3U)
#define BOARD_TPS65941_RTC_STATUS                           (0xC4U)
#define BOARD_TPS65941_RTC_INTR                             (0xC5U)

/** TPS65941 WDT Register Offsets */
#define BOARD_TPS65941_WDT_ANSW_REG                         (0x01U)
#define BOARD_TPS65941_WDT_QUES_ANSW_CNT                    (0x02U)
#define BOARD_TPS65941_WDT_WIN1_CFG                         (0x03U)
#define BOARD_TPS65941_WDT_WIN2_CFG                         (0x04U)
#define BOARD_TPS65941_WDT_LONGWIN_CFG                      (0x05U)
#define BOARD_TPS65941_WDT_MODE_REG                         (0x06U)
#define BOARD_TPS65941_WDT_QA_CFG                           (0x07U)
#define BOARD_TPS65941_WDT_ERR_STAT                         (0x08U)
#define BOARD_TPS65941_WDT_THR_CFG                          (0x09U)
#define BOARD_TPS65941_WDT_FAIL_CNT_REG                     (0x0AU)

/** GPIO Register bit fields */
#define BOARD_TPS65941_GPIO_SEL_SHIFT                       (0x05U)
#define BOARD_TPS65941_GPIO_DEGLITCH_EN_SHIFT               (0x04U)
#define BOARD_TPS65941_GPIO_PU_PD_EN_SHIFT                  (0x03U)
#define BOARD_TPS65941_GPIO_PU_SEL_SHIFT                    (0x02U)
#define BOARD_TPS65941_GPIO_OD_SHIFT                        (0x01U)
#define BOARD_TPS65941_GPIO_DIR_SHIFT                       (0x00U)

/** NPWRON Register bit fields */
#define BOARD_TPS65941_NPWRON_SEL_SHIFT                     (0x06U)
#define BOARD_TPS65941_NPWRON_POL_SHIFT                     (0x05U)
#define BOARD_TPS65941_NPWRON_PU_PD_EN_SHIFT                (0x03U)
#define BOARD_TPS65941_NPWRON_PU_SEL_SHIFT                  (0x02U)
#define BOARD_TPS65941_NPWRON_OD_SHIFT                      (0x00U)

/** GPIO IN/OUT Register bit fields */
#define BOARD_TPS65941_GPIO1_IN_OUT_SHIFT                   (0x00U)
#define BOARD_TPS65941_GPIO2_IN_OUT_SHIFT                   (0x01U)
#define BOARD_TPS65941_GPIO3_IN_OUT_SHIFT                   (0x02U)
#define BOARD_TPS65941_GPIO4_IN_OUT_SHIFT                   (0x03U)
#define BOARD_TPS65941_GPIO5_IN_OUT_SHIFT                   (0x04U)
#define BOARD_TPS65941_GPIO6_IN_OUT_SHIFT                   (0x05U)
#define BOARD_TPS65941_GPIO7_IN_OUT_SHIFT                   (0x06U)
#define BOARD_TPS65941_GPIO8_IN_OUT_SHIFT                   (0x07U)
#define BOARD_TPS65941_GPIO9_IN_OUT_SHIFT                   (0x00U)
#define BOARD_TPS65941_GPIO10_IN_OUT_SHIFT                  (0x01U)
#define BOARD_TPS65941_GPIO11_IN_OUT_SHIFT                  (0x02U)
#define BOARD_TPS65941_NPWRON_IN_OUT_SHIFT                  (0x03U)

/** BUCK Power resource bit fields */
#define BOARD_TPS65941_BUCK_VSEL_SHIFT                      (0x03U)
#define BOARD_TPS65941_BUCK_EN_SHIFT                        (0x00U)
#define BOARD_TPS65941_BUCK_ILIM_SHIFT                      (0x03U)

/** LDO Power resource bit field */
#define BOARD_TPS65941_LDO_EN_SHIFT                         (0x00U)

/** BUCK Voltage set bit field */
#define BOARD_TPS65941_BUCK_VSET_SHIFT                      (0x00U)

/** LDO Voltage set bit fields */
#define BOARD_TPS65941_LDO_123_VSET_SHIFT                   (0x01U)
#define BOARD_TPS65941_LDO4_VSET_SHIFT                      (0x00U)

/** Power resource voltage monitor set bit field */
#define BOARD_TPS65941_PWR_VMON_EN_SHIFT                    (0x04U)

/** Power resource PG Window set bit fields */
#define BOARD_TPS65941_PWR_UV_THR_SHIFT                     (0x03U)
#define BOARD_TPS65941_PWR_OV_THR_SHIFT                     (0x00U)

/** Power resource PGOOD bit fields */
#define BOARD_TPS65941_BUCK1_PG_SEL_SHIFT                   (0x00U)
#define BOARD_TPS65941_BUCK2_PG_SEL_SHIFT                   (0x02U)
#define BOARD_TPS65941_BUCK3_PG_SEL_SHIFT                   (0x04U)
#define BOARD_TPS65941_BUCK4_PG_SEL_SHIFT                   (0x06U)
#define BOARD_TPS65941_BUCK5_PG_SEL_SHIFT                   (0x00U)
#define BOARD_TPS65941_LDO1_PG_SEL_SHIFT                    (0x00U)
#define BOARD_TPS65941_LDO2_PG_SEL_SHIFT                    (0x02U)
#define BOARD_TPS65941_LDO3_PG_SEL_SHIFT                    (0x04U)
#define BOARD_TPS65941_LDO4_PG_SEL_SHIFT                    (0x06U)

/** VCCA voltage monitor bit fields */
#define BOARD_TPS65941_VCCA_VMON_EN_SHIFT                   (0x00U)
#define BOARD_TPS65941_VCCA_PG_SET_SHIFT                    (0x06U)
#define BOARD_TPS65941_VCCA_UV_THR_SHIFT                    (0x03U)
#define BOARD_TPS65941_VCCA_OV_THR_SHIFT                    (0x00U)

/** Status register bit fields */
#define BOARD_TPS65941_TWARN_STAT_SHIFT                     (0x03U)
#define BOARD_TPS65941_TSD_ORD_STAT_SHIFT                   (0x00U)
#define BOARD_TPS65941_TSD_IMM_STAT_SHIFT                   (0x00U)

/** PGOOD signal bit fields */
#define BOARD_TPS65941_PGOOD_WINDOW_SHIFT                   (0x07U)
#define BOARD_TPS65941_PGOOD_POL_SHIFT                      (0x06U)
#define BOARD_TPS65941_PGOOD_NRSTOUT_SOC_SHIFT              (0x05U)
#define BOARD_TPS65941_PGOOD_NRSTOUT_SHIFT                  (0x04U)
#define BOARD_TPS65941_PGOOD_TDIE_WARN_SHIFT                (0x03U)
#define BOARD_TPS65941_PGOOD_VCCA_SEL_SHIFT                 (0x00U)

/** Thermal threshold value bit fields */
#define BOARD_TPS65941_TWARN_LVL_SHIFT                      (0x00U)

/** ESM MCU and SOC bit fields */
#define BOARD_TPS65941_ESM_START_SHIFT                      (0x00U)
#define BOARD_TPS65941_ESM_DLY1_SHIFT                       (0x00U)
#define BOARD_TPS65941_ESM_DLY2_SHIFT                       (0x00U)
#define BOARD_TPS65941_ESM_MODE_SHIFT                       (0x07U)
#define BOARD_TPS65941_ESM_EN_SHIFT                         (0x06U)
#define BOARD_TPS65941_ESM_ERR_THR_SHIFT                    (0x00U)
#define BOARD_TPS65941_ESM_HMAX_SHIFT                       (0x00U)
#define BOARD_TPS65941_ESM_HMIN_SHIFT                       (0x00U)
#define BOARD_TPS65941_ESM_LMAX_SHIFT                       (0x00U)
#define BOARD_TPS65941_ESM_LMIN_SHIFT                       (0x00U)
#define BOARD_TPS65941_ESM_ERR_CNT_SHIFT                    (0x00U)

/** RTC and alarm time and date bit fields */
#define BOARD_TPS65941_RTC_ALRM_SEC_1_SHIFT                 (0x04U)
#define BOARD_TPS65941_RTC_ALRM_SEC_0_SHIFT                 (0x00U)
#define BOARD_TPS65941_RTC_ALRM_MIN_1_SHIFT                 (0x04U)
#define BOARD_TPS65941_RTC_ALRM_MIN_0_SHIFT                 (0x00U)
#define BOARD_TPS65941_RTC_ALRM_AM_PM_SHIFT                 (0x07U)
#define BOARD_TPS65941_RTC_ALRM_HR_1_SHIFT                  (0x04U)
#define BOARD_TPS65941_RTC_ALRM_HR_0_SHIFT                  (0x00U)
#define BOARD_TPS65941_RTC_ALRM_DAY_1_SHIFT                 (0x04U)
#define BOARD_TPS65941_RTC_ALRM_DAY_0_SHIFT                 (0x00U)
#define BOARD_TPS65941_RTC_ALRM_MON_1_SHIFT                 (0x04U)
#define BOARD_TPS65941_RTC_ALRM_MON_0_SHIFT                 (0x00U)
#define BOARD_TPS65941_RTC_ALRM_YR_1_SHIFT                  (0x04U)
#define BOARD_TPS65941_RTC_ALRM_YR_0_SHIFT                  (0x00U)
#define BOARD_TPS65941_RTC_WEEK_SHIFT                       (0x00U)

/** RTC CTRL bit fields */
#define BOARD_TPS65941_RTC_REG_OPT_SHIFT                    (0x07U)
#define BOARD_TPS65941_GET_TIME_SHIFT                       (0x06U)
#define BOARD_TPS65941_HOUR_MODE_SHIFT                      (0x03U)
#define BOARD_TPS65941_ROUND_30S_SHIFT                      (0x01U)
#define BOARD_TPS65941_STOP_RTC_SHIFT                       (0x00U)

/** RTC Status bit fields */
#define BOARD_TPS65941_ALRM_STAT_SHIFT                      (0x06U)
#define BOARD_TPS65941_TIMER_STAT_SHIFT                     (0x05U)
#define BOARD_TPS65941_RUN_SHIFT                            (0x01U)

/** RTC Interrupt bit fields */
#define BOARD_TPS65941_ALARM_INTR_SHIFT                     (0x03U)
#define BOARD_TPS65941_TIMER_INTR_SHIFT                     (0x02U)

/** RTC Timer periods bit fields */
#define BOARD_TPS65941_TIMER_PERIOD_SHIFT                   (0x00U)

/** WDT configuration bit fields */
#define BOARD_TPS65941_WDT_ANSW_SHIFT                       (0x00U)
#define BOARD_TPS65941_WDT_ANSW_CNT_SHIFT                   (0x04U)
#define BOARD_TPS65941_WDT_QUES_SHIFT                       (0x00U)
#define BOARD_TPS65941_WDT_WIN1_CFG_SHIFT                   (0x00U)
#define BOARD_TPS65941_WDT_WIN2_CFG_SHIFT                   (0x00U)
#define BOARD_TPS65941_WDT_LONGWIN_CFG_SHIFT                (0x00U)
#define BOARD_TPS65941_WDT_MODE_SHIFT                       (0x01U)
#define BOARD_TPS65941_WDT_LONGWIN_RET_SHIFT                (0x00U)

/** WDT Error status bit fields */
#define BOARD_TPS65941_WDT_RST_STAT_SHIFT                   (0x07U)
#define BOARD_TPS65941_WDT_FAIL_STAT_SHIFT                  (0x06U)
#define BOARD_TPS65941_WDT_ANSW_ERR_SHIFT                   (0x05U)
#define BOARD_TPS65941_WDT_SEQ_ERR_SHIFT                    (0x04U)
#define BOARD_TPS65941_WDT_ANSW_ERLY_SHIFT                  (0x03U)
#define BOARD_TPS65941_WDT_TRIG_ERLY_SHIFT                  (0x02U)
#define BOARD_TPS65941_WDT_TIMEOUT_SHIFT                    (0x01U)
#define BOARD_TPS65941_WDT_LNGWIN_TIMEOUT_SHIFT             (0x00U)

/** WDT Threshold bit fields */
#define BOARD_TPS65941_WDT_RST_EN_SHIFT                     (0x07U)
#define BOARD_TPS65941_WDT_EN_SHIFT                         (0x06U)
#define BOARD_TPS65941_WDT_FAIL_THR_SHIFT                   (0x03U)
#define BOARD_TPS65941_WDT_RST_THR_SHIFT                    (0x00U)

/** WDT Fail count bit fields */
#define BOARD_TPS65941_WDT_BAD_EVT_SHIFT                    (0x06U)
#define BOARD_TPS65941_WDT_FIRST_OK_SHIFT                   (0x05U)
#define BOARD_TPS65941_WDT_FAIL_CNT_SHIFT                   (0x00U)

/** GPIO Register bit mask */
#define BOARD_TPS65941_GPIO_SEL_BIT_MASK                    (uint8_t)(0x01 << BOARD_TPS65941_GPIO_SEL_SHIFT)
#define BOARD_TPS65941_GPIO_DEGLITCH_EN_BIT_MASK            (uint8_t)(0x01 << BOARD_TPS65941_GPIO_DEGLITCH_EN_SHIFT)
#define BOARD_TPS65941_GPIO_PU_PD_EN_BIT_MASK               (uint8_t)(0x01 << BOARD_TPS65941_GPIO_PU_PD_EN_SHIFT)
#define BOARD_TPS65941_GPIO_PU_SEL_BIT_MASK                 (uint8_t)(0x01 << BOARD_TPS65941_GPIO_PU_SEL_SHIFT)
#define BOARD_TPS65941_GPIO_OD_BIT_MASK                     (uint8_t)(0x01 << BOARD_TPS65941_GPIO_OD_SHIFT)
#define BOARD_TPS65941_GPIO_DIR_BIT_MASK                    (uint8_t)(0x01 << BOARD_TPS65941_GPIO_DIR_SHIFT)

/** NPWRON Register bit mask */
#define BOARD_TPS65941_NPWRON_SEL_BIT_MASK                  (uint8_t)(0x01 << BOARD_TPS65941_NPWRON_SEL_SHIFT)
#define BOARD_TPS65941_NPWRON_POL_BIT_MASK                  (uint8_t)(0x01 << BOARD_TPS65941_NPWRON_POL_SHIFT)
#define BOARD_TPS65941_NPWRON_PU_PD_EN_BIT_MASK             (uint8_t)(0x01 << BOARD_TPS65941_NPWRON_PU_PD_EN_SHIFT)
#define BOARD_TPS65941_NPWRON_PU_SEL_BIT_MASK               (uint8_t)(0x01 << BOARD_TPS65941_NPWRON_PU_SEL_SHIFT)
#define BOARD_TPS65941_NPWRON_OD_BIT_MASK                   (uint8_t)(0x01 << BOARD_TPS65941_NPWRON_OD_SHIFT)

/** GPIO IN/OUT Register bit mask */
#define BOARD_TPS65941_GPIO1_IN_OUT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_GPIO1_IN_OUT_SHIFT)  
#define BOARD_TPS65941_GPIO2_IN_OUT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_GPIO2_IN_OUT_SHIFT)  
#define BOARD_TPS65941_GPIO3_IN_OUT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_GPIO3_IN_OUT_SHIFT)  
#define BOARD_TPS65941_GPIO4_IN_OUT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_GPIO4_IN_OUT_SHIFT)  
#define BOARD_TPS65941_GPIO5_IN_OUT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_GPIO5_IN_OUT_SHIFT)  
#define BOARD_TPS65941_GPIO6_IN_OUT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_GPIO6_IN_OUT_SHIFT)  
#define BOARD_TPS65941_GPIO7_IN_OUT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_GPIO7_IN_OUT_SHIFT)
#define BOARD_TPS65941_GPIO8_IN_OUT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_GPIO8_IN_OUT_SHIFT) 
#define BOARD_TPS65941_GPIO9_IN_OUT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_GPIO9_IN_OUT_SHIFT) 
#define BOARD_TPS65941_GPIO10_IN_OUT_BIT_MASK               (uint8_t)(0x01 << BOARD_TPS65941_GPIO10_IN_OUT_SHIFT)
#define BOARD_TPS65941_GPIO11_IN_OUT_BIT_MASK               (uint8_t)(0x01 << BOARD_TPS65941_GPIO11_IN_OUT_SHIFT)
#define BOARD_TPS65941_NPWRON_IN_OUT_BIT_MASK               (uint8_t)(0x01 << BOARD_TPS65941_NPWRON_IN_OUT_SHIFT)

/** BUCK Power resource bit mask */
#define BOARD_TPS65941_BUCK_VSEL_BIT_MASK                   (uint8_t)(0x01 << BOARD_TPS65941_BUCK_VSEL_SHIFT)
#define BOARD_TPS65941_BUCK_EN_BIT_MASK                     (uint8_t)(0x01 << BOARD_TPS65941_BUCK_EN_SHIFT)
#define BOARD_TPS65941_BUCK_ILIM_BIT_MASK                   (uint8_t)(0x07 << BOARD_TPS65941_BUCK_ILIM_SHIFT)

/** LDO Power resource bit mask */
#define BOARD_TPS65941_LDO_EN_BIT_MASK                      (uint8_t)(0x01 << BOARD_TPS65941_LDO_EN_SHIFT)

/** BUCK Voltage set bit mask */
#define BOARD_TPS65941_BUCK_VSET_BIT_MASK                   (uint8_t)(0xFF << BOARD_TPS65941_BUCK_VSET_SHIFT)

/** LDO Voltage set bit mask */
#define BOARD_TPS65941_LDO_123_VSET_BIT_MASK                (uint8_t)(0x3F << BOARD_TPS65941_LDO_123_VSET_SHIFT)
#define BOARD_TPS65941_LDO4_VSET_BIT_MASK                   (uint8_t)(0x3F << BOARD_TPS65941_LDO4_VSET_SHIFT)

/** Power resource voltage monitor set bit mask */
#define BOARD_TPS65941_PWR_VMON_EN_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_PWR_VMON_EN_SHIFT)

/** Power resource PG Window set bit mask */
#define BOARD_TPS65941_PWR_UV_THR_BIT_MASK                  (uint8_t)(0x07 << BOARD_TPS65941_PWR_UV_THR_SHIFT)
#define BOARD_TPS65941_PWR_OV_THR_BIT_MASK                  (uint8_t)(0x07 << BOARD_TPS65941_PWR_OV_THR_SHIFT)

/** Voltage monitor set bit mask */
#define BOARD_TPS65941_BUCK1_PG_SEL_BIT_MASK                (uint8_t)(0x03 << BOARD_TPS65941_BUCK1_PG_SEL_SHIFT)
#define BOARD_TPS65941_BUCK2_PG_SEL_BIT_MASK                (uint8_t)(0x03 << BOARD_TPS65941_BUCK2_PG_SEL_SHIFT)
#define BOARD_TPS65941_BUCK3_PG_SEL_BIT_MASK                (uint8_t)(0x03 << BOARD_TPS65941_BUCK3_PG_SEL_SHIFT)
#define BOARD_TPS65941_BUCK4_PG_SEL_BIT_MASK                (uint8_t)(0x03 << BOARD_TPS65941_BUCK4_PG_SEL_SHIFT)
#define BOARD_TPS65941_BUCK5_PG_SEL_BIT_MASK                (uint8_t)(0x03 << BOARD_TPS65941_BUCK5_PG_SEL_SHIFT)
#define BOARD_TPS65941_LDO1_PG_SEL_BIT_MASK                 (uint8_t)(0x03 << BOARD_TPS65941_LDO1_PG_SEL_SHIFT)
#define BOARD_TPS65941_LDO2_PG_SEL_BIT_MASK                 (uint8_t)(0x03 << BOARD_TPS65941_LDO2_PG_SEL_SHIFT)
#define BOARD_TPS65941_LDO3_PG_SEL_BIT_MASK                 (uint8_t)(0x03 << BOARD_TPS65941_LDO3_PG_SEL_SHIFT)
#define BOARD_TPS65941_LDO4_PG_SEL_BIT_MASK                 (uint8_t)(0x03 << BOARD_TPS65941_LDO4_PG_SEL_SHIFT)

/** VCCA voltage monitor set bit mask */
#define BOARD_TPS65941_VCCA_VMON_EN_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_VCCA_VMON_EN_SHIFT)
#define BOARD_TPS65941_VCCA_PG_SET_BIT_MASK                 (uint8_t)(0x01 << BOARD_TPS65941_VCCA_PG_SET_SHIFT)
#define BOARD_TPS65941_VCCA_UV_THR_BIT_MASK                 (uint8_t)(0x07 << BOARD_TPS65941_VCCA_UV_THR_SHIFT)
#define BOARD_TPS65941_VCCA_OV_THR_BIT_MASK                 (uint8_t)(0x07 << BOARD_TPS65941_VCCA_OV_THR_SHIFT)

/** Status register bit mask */
#define BOARD_TPS65941_TWARN_STAT_BIT_MASK                  (uint8_t)(0x01 << BOARD_TPS65941_TWARN_STAT_SHIFT)
#define BOARD_TPS65941_TSD_ORD_STAT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_TSD_ORD_STAT_SHIFT)
#define BOARD_TPS65941_TSD_IMM_STAT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_TSD_IMM_STAT_SHIFT)

/** PGOOD signal bit mask */
#define BOARD_TPS65941_PGOOD_WINDOW_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_PGOOD_WINDOW_SHIFT)
#define BOARD_TPS65941_PGOOD_POL_BIT_MASK                   (uint8_t)(0x01 << BOARD_TPS65941_PGOOD_POL_SHIFT)
#define BOARD_TPS65941_PGOOD_NRSTOUT_SOC_BIT_MASK           (uint8_t)(0x01 << BOARD_TPS65941_PGOOD_NRSTOUT_SOC_SHIFT)
#define BOARD_TPS65941_PGOOD_NRSTOUT_BIT_MASK               (uint8_t)(0x01 << BOARD_TPS65941_PGOOD_NRSTOUT_SHIFT)
#define BOARD_TPS65941_PGOOD_TDIE_WARN_BIT_MASK             (uint8_t)(0x01 << BOARD_TPS65941_PGOOD_TDIE_WARN_SHIFT)
#define BOARD_TPS65941_PGOOD_VCCA_SEL_BIT_MASK              (uint8_t)(0x01 << BOARD_TPS65941_PGOOD_VCCA_SEL_SHIFT)

/** Thermal threshold value bit mask */
#define BOARD_TPS65941_TWARN_LVL_BIT_MASK                   (uint8_t)(0x01 << BOARD_TPS65941_TWARN_LVL_SHIFT)

/** ESM bit mask */
#define BOARD_TPS65941_ESM_START_BIT_MASK                   (uint8_t)(0x01 << BOARD_TPS65941_ESM_START_SHIFT)
#define BOARD_TPS65941_ESM_DLY1_BIT_MASK                    (uint8_t)(0xFF << BOARD_TPS65941_ESM_DLY1_SHIFT)
#define BOARD_TPS65941_ESM_DLY2_BIT_MASK                    (uint8_t)(0xFF << BOARD_TPS65941_ESM_DLY2_SHIFT)
#define BOARD_TPS65941_ESM_MODE_BIT_MASK                    (uint8_t)(0x01 << BOARD_TPS65941_ESM_MODE_SHIFT)
#define BOARD_TPS65941_ESM_EN_BIT_MASK                      (uint8_t)(0x01 << BOARD_TPS65941_ESM_EN_SHIFT)
#define BOARD_TPS65941_ESM_ERR_THR_BIT_MASK                 (uint8_t)(0x0F << BOARD_TPS65941_ESM_ERR_THR_SHIFT)
#define BOARD_TPS65941_ESM_HMAX_BIT_MASK                    (uint8_t)(0xFF << BOARD_TPS65941_ESM_HMAX_SHIFT)
#define BOARD_TPS65941_ESM_HMIN_BIT_MASK                    (uint8_t)(0xFF << BOARD_TPS65941_ESM_HMIN_SHIFT)
#define BOARD_TPS65941_ESM_LMAX_BIT_MASK                    (uint8_t)(0xFF << BOARD_TPS65941_ESM_LMAX_SHIFT)
#define BOARD_TPS65941_ESM_LMIN_BIT_MASK                    (uint8_t)(0xFF << BOARD_TPS65941_ESM_LMIN_SHIFT)
#define BOARD_TPS65941_ESM_ERR_CNT_BIT_MASK                 (uint8_t)(0x1F << BOARD_TPS65941_ESM_ERR_CNT_SHIFT)

/** RTC and alarm time and date bit mask */
#define BOARD_TPS65941_RTC_ALRM_SEC_1_BIT_MASK              (uint8_t)(0x07 << BOARD_TPS65941_RTC_ALRM_SEC_1_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_SEC_0_BIT_MASK              (uint8_t)(0x0F << BOARD_TPS65941_RTC_ALRM_SEC_0_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_MIN_1_BIT_MASK              (uint8_t)(0x07 << BOARD_TPS65941_RTC_ALRM_MIN_1_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_MIN_0_BIT_MASK              (uint8_t)(0x0F << BOARD_TPS65941_RTC_ALRM_MIN_0_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_AM_PM_BIT_MASK              (uint8_t)(0x01 << BOARD_TPS65941_RTC_ALRM_AM_PM_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_HR_1_BIT_MASK               (uint8_t)(0x03 << BOARD_TPS65941_RTC_ALRM_HR_1_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_HR_0_BIT_MASK               (uint8_t)(0x0F << BOARD_TPS65941_RTC_ALRM_HR_0_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_DAY_1_BIT_MASK              (uint8_t)(0x03 << BOARD_TPS65941_RTC_ALRM_DAY_1_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_DAY_0_BIT_MASK              (uint8_t)(0x0F << BOARD_TPS65941_RTC_ALRM_DAY_0_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_MON_1_BIT_MASK              (uint8_t)(0x01 << BOARD_TPS65941_RTC_ALRM_MON_1_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_MON_0_BIT_MASK              (uint8_t)(0x0F << BOARD_TPS65941_RTC_ALRM_MON_0_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_YR_1_BIT_MASK               (uint8_t)(0x0F << BOARD_TPS65941_RTC_ALRM_YR_1_SHIFT)
#define BOARD_TPS65941_RTC_ALRM_YR_0_BIT_MASK               (uint8_t)(0x0F << BOARD_TPS65941_RTC_ALRM_YR_0_SHIFT)
#define BOARD_TPS65941_RTC_WEEK_BIT_MASK                    (uint8_t)(0x07 << BOARD_TPS65941_RTC_WEEK_SHIFT)

/** RTC CTRL bit mask */
#define BOARD_TPS65941_RTC_REG_OPT_BIT_MASK                 (uint8_t)(0x01 << BOARD_TPS65941_RTC_REG_OPT_SHIFT)
#define BOARD_TPS65941_GET_TIME_BIT_MASK                    (uint8_t)(0x01 << BOARD_TPS65941_GET_TIME_SHIFT)
#define BOARD_TPS65941_HOUR_MODE_BIT_MASK                   (uint8_t)(0x01 << BOARD_TPS65941_HOUR_MODE_SHIFT)
#define BOARD_TPS65941_ROUND_30S_BIT_MASK                   (uint8_t)(0x01 << BOARD_TPS65941_ROUND_30S_SHIFT)
#define BOARD_TPS65941_STOP_RTC_BIT_MASK                    (uint8_t)(0x01 << BOARD_TPS65941_STOP_RTC_SHIFT)

/** RTC Status bit mask */
#define BOARD_TPS65941_ALRM_STAT_BIT_MASK                   (uint8_t)(0x01 << BOARD_TPS65941_ALRM_STAT_SHIFT)
#define BOARD_TPS65941_TIMER_STAT_BIT_MASK                  (uint8_t)(0x01 << BOARD_TPS65941_TIMER_STAT_SHIFT)
#define BOARD_TPS65941_RUN_BIT_MASK                         (uint8_t)(0x01 << BOARD_TPS65941_RUN_SHIFT)

/** RTC Interrupt bit mask */
#define BOARD_TPS65941_ALARM_INTR_BIT_MASK                  (uint8_t)(0x01 << BOARD_TPS65941_ALARM_INTR_SHIFT)
#define BOARD_TPS65941_TIMER_INTR_BIT_MASK                  (uint8_t)(0x01 << BOARD_TPS65941_TIMER_INTR_SHIFT)

/** RTC Timer period bit mask */
#define BOARD_TPS65941_TIMER_PERIOD_BIT_MASK                (uint8_t)(0x03 << BOARD_TPS65941_TIMER_PERIOD_SHIFT)

/** WDT configuration bit fields */
#define BOARD_TPS65941_WDT_ANSW_BIT_MASK                    (uint8_t)(0xFF << BOARD_TPS65941_WDT_ANSW_SHIFT)
#define BOARD_TPS65941_WDT_ANSW_CNT_BIT_MASK                (uint8_t)(0x03 << BOARD_TPS65941_WDT_ANSW_CNT_SHIFT)
#define BOARD_TPS65941_WDT_QUES_BIT_MASK                    (uint8_t)(0x0F << BOARD_TPS65941_WDT_QUES_SHIFT)
#define BOARD_TPS65941_WDT_WIN1_CFG_BIT_MASK                (uint8_t)(0x7F << BOARD_TPS65941_WDT_WIN1_CFG_SHIFT)
#define BOARD_TPS65941_WDT_WIN2_CFG_BIT_MASK                (uint8_t)(0x7F << BOARD_TPS65941_WDT_WIN2_CFG_SHIFT)
#define BOARD_TPS65941_WDT_LONGWIN_CFG_BIT_MASK             (uint8_t)(0xFF << BOARD_TPS65941_WDT_LONGWIN_CFG_SHIFT)
#define BOARD_TPS65941_WDT_MODE_BIT_MASK                    (uint8_t)(0x01 << BOARD_TPS65941_WDT_MODE_SHIFT)
#define BOARD_TPS65941_WDT_LONGWIN_RET_BIT_MASK             (uint8_t)(0x01 << BOARD_TPS65941_WDT_LONGWIN_RET_SHIFT)

/** WDT Error status bit fields */
#define BOARD_TPS65941_WDT_RST_STAT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_WDT_RST_STAT_SHIFT)
#define BOARD_TPS65941_WDT_FAIL_STAT_BIT_MASK               (uint8_t)(0x01 << BOARD_TPS65941_WDT_FAIL_STAT_SHIFT)
#define BOARD_TPS65941_WDT_ANSW_ERR_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_WDT_ANSW_ERR_SHIFT)
#define BOARD_TPS65941_WDT_SEQ_ERR_BIT_MASK                 (uint8_t)(0x01 << BOARD_TPS65941_WDT_SEQ_ERR_SHIFT)
#define BOARD_TPS65941_WDT_ANSW_ERLY_BIT_MASK               (uint8_t)(0x01 << BOARD_TPS65941_WDT_ANSW_ERLY_SHIFT)
#define BOARD_TPS65941_WDT_TRIG_ERLY_BIT_MASK               (uint8_t)(0x01 << BOARD_TPS65941_WDT_TRIG_ERLY_SHIFT)
#define BOARD_TPS65941_WDT_TIMEOUT_BIT_MASK                 (uint8_t)(0x01 << BOARD_TPS65941_WDT_TIMEOUT_SHIFT)
#define BOARD_TPS65941_WDT_LNGWIN_TIMEOUT_BIT_MASK          (uint8_t)(0x01 << BOARD_TPS65941_WDT_LNGWIN_TIMEOUT_SHIFT)

/** WDT Threshold bit fields */
#define BOARD_TPS65941_WDT_RST_EN_BIT_MASK                  (uint8_t)(0x01 << BOARD_TPS65941_WDT_RST_EN_SHIFT)
#define BOARD_TPS65941_WDT_EN_BIT_MASK                      (uint8_t)(0x01 << BOARD_TPS65941_WDT_EN_SHIFT)
#define BOARD_TPS65941_WDT_FAIL_THR_BIT_MASK                (uint8_t)(0x07 << BOARD_TPS65941_WDT_FAIL_THR_SHIFT)
#define BOARD_TPS65941_WDT_RST_THR_BIT_MASK                 (uint8_t)(0x07 << BOARD_TPS65941_WDT_RST_THR_SHIFT)

/** WDT Fail count bit fields */
#define BOARD_TPS65941_WDT_BAD_EVT_BIT_MASK                 (uint8_t)(0x01 << BOARD_TPS65941_WDT_BAD_EVT_SHIFT)
#define BOARD_TPS65941_WDT_FIRST_OK_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_WDT_FIRST_OK_SHIFT)
#define BOARD_TPS65941_WDT_FAIL_CNT_BIT_MASK                (uint8_t)(0x01 << BOARD_TPS65941_WDT_FAIL_CNT_SHIFT)

/** GPIO functionality enable/disable */
#define BOARD_TPS65941_DISABLE                              (0U)
#define BOARD_TPS65941_ENABLE                               (1U)

/** GPIO type */
#define BOARD_TPS65941_PULLUP_DOWN                          (0U)
#define BOARD_TPS65941_OPEN_DRAIN                           (1U)

/** GPIO signal level */
#define BOARD_TPS65941_GPIO_LOW                             (0U)
#define BOARD_TPS65941_GPIO_HIGH                            (1U)

/** GPIO Direction */
#define BOARD_TPS65941_GPIO_DIR_IN                          (0U)
#define BOARD_TPS65941_GPIO_DIR_OUT                         (1U)

#define BOARD_TPS65941_GPIO_MODE                            (0x0U)
#define BOARD_TPS65941_GPIO_PIN_MAX                         (11U)
#define BOARD_TPS65941_NPWRON_PIN                           (0)

/** TPS65941 Power resource */
#define BOARD_TPS65941_BUCK1_RESOURCE                       (0U)
#define BOARD_TPS65941_BUCK2_RESOURCE                       (1U)
#define BOARD_TPS65941_BUCK3_RESOURCE                       (2U)
#define BOARD_TPS65941_BUCK4_RESOURCE                       (3U)
#define BOARD_TPS65941_BUCK5_RESOURCE                       (4U)
#define BOARD_TPS65941_LDO1_RESOURCE                        (5U)
#define BOARD_TPS65941_LDO2_RESOURCE                        (6U)
#define BOARD_TPS65941_LDO3_RESOURCE                        (7U)
#define BOARD_TPS65941_LDO4_RESOURCE                        (8U)

/** Interrupt type */
#define BOARD_TPS65941_INTR_TYPE_BUCK_ERR                   (0U)
#define BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR               (1U)
#define BOARD_TPS65941_INTR_TYPE_SEVERE_ERR                 (2U)
#define BOARD_TPS65941_INTR_TYPE_MODERATE_ERR               (3U)
#define BOARD_TPS65941_INTR_TYPE_MISC_WARN                  (4U)
#define BOARD_TPS65941_INTR_TYPE_STARTUP_SRC                (5U)
#define BOARD_TPS65941_INTR_TYPE_GPIO                       (6U)
#define BOARD_TPS65941_INTR_TYPE_FSM_ERR                    (7U)

/** Interrupt IDs */
/* Upper 8-bit indicates the interrupt type and lower 8-bits are interrupt
   number mapped based on the register offsets */
#define BOARD_TPS65941_INTR_ID_BUCK1_OV                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x00U)
#define BOARD_TPS65941_INTR_ID_BUCK1_UV                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x01U)
#define BOARD_TPS65941_INTR_ID_BUCK1_SC                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (1 << 8) | 0x02U)
#define BOARD_TPS65941_INTR_ID_BUCK1_ILIM                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x03U)
#define BOARD_TPS65941_INTR_ID_BUCK2_OV                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x04U)
#define BOARD_TPS65941_INTR_ID_BUCK2_UV                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x05U)
#define BOARD_TPS65941_INTR_ID_BUCK2_SC                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (1 << 8) | 0x06U)
#define BOARD_TPS65941_INTR_ID_BUCK2_ILIM                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x07U)
#define BOARD_TPS65941_INTR_ID_BUCK3_OV                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x08U)
#define BOARD_TPS65941_INTR_ID_BUCK3_UV                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x09U)
#define BOARD_TPS65941_INTR_ID_BUCK3_SC                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (1 << 8) | 0x0AU)
#define BOARD_TPS65941_INTR_ID_BUCK3_ILIM                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x0BU)
#define BOARD_TPS65941_INTR_ID_BUCK4_OV                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x0CU)
#define BOARD_TPS65941_INTR_ID_BUCK4_UV                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x0DU)
#define BOARD_TPS65941_INTR_ID_BUCK4_SC                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (1 << 8) | 0x0EU)
#define BOARD_TPS65941_INTR_ID_BUCK4_ILIM                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x0FU)
#define BOARD_TPS65941_INTR_ID_BUCK5_OV                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x10U)
#define BOARD_TPS65941_INTR_ID_BUCK5_UV                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x11U)
#define BOARD_TPS65941_INTR_ID_BUCK5_SC                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (1 << 8) | 0x12U)
#define BOARD_TPS65941_INTR_ID_BUCK5_ILIM                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_BUCK_ERR) << 16) | (0 << 8) | 0x13U)

#define BOARD_TPS65941_INTR_ID_LDO1_OV                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x00U)
#define BOARD_TPS65941_INTR_ID_LDO1_UV                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x01U)
#define BOARD_TPS65941_INTR_ID_LDO1_SC                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (1 << 8) | 0x02U)
#define BOARD_TPS65941_INTR_ID_LDO1_ILIM                    ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x03U)
#define BOARD_TPS65941_INTR_ID_LDO2_OV                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x04U)
#define BOARD_TPS65941_INTR_ID_LDO2_UV                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x05U)
#define BOARD_TPS65941_INTR_ID_LDO2_SC                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (1 << 8) | 0x06U)
#define BOARD_TPS65941_INTR_ID_LDO2_ILIM                    ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x07U)
#define BOARD_TPS65941_INTR_ID_LDO3_OV                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x08U)
#define BOARD_TPS65941_INTR_ID_LDO3_UV                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x09U)
#define BOARD_TPS65941_INTR_ID_LDO3_SC                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (1 << 8) | 0x0AU)
#define BOARD_TPS65941_INTR_ID_LDO3_ILIM                    ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x0BU)
#define BOARD_TPS65941_INTR_ID_LDO4_OV                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x0CU)
#define BOARD_TPS65941_INTR_ID_LDO4_UV                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x0DU)
#define BOARD_TPS65941_INTR_ID_LDO4_SC                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (1 << 8) | 0x0EU)
#define BOARD_TPS65941_INTR_ID_LDO4_ILIM                    ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x0FU)
#define BOARD_TPS65941_INTR_ID_VCCA_OV                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x10U)
#define BOARD_TPS65941_INTR_ID_VCCA_UV                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_LDO_VMON_ERR) << 16) | (0 << 8) | 0x11U)

#define BOARD_TPS65941_INTR_ID_GPIO1_FALL                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x00U)
#define BOARD_TPS65941_INTR_ID_GPIO2_FALL                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x01U)
#define BOARD_TPS65941_INTR_ID_GPIO3_FALL                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x02U)
#define BOARD_TPS65941_INTR_ID_GPIO4_FALL                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x03U)
#define BOARD_TPS65941_INTR_ID_GPIO5_FALL                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x04U)
#define BOARD_TPS65941_INTR_ID_GPIO6_FALL                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x05U)
#define BOARD_TPS65941_INTR_ID_GPIO7_FALL                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x06U)
#define BOARD_TPS65941_INTR_ID_GPIO8_FALL                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x07U)
#define BOARD_TPS65941_INTR_ID_GPIO9_FALL                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x10U)
#define BOARD_TPS65941_INTR_ID_GPIO10_FALL                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x11U)
#define BOARD_TPS65941_INTR_ID_GPIO11_FALL                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x12U)

#define BOARD_TPS65941_INTR_ID_GPIO1_RISE                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x08U)
#define BOARD_TPS65941_INTR_ID_GPIO2_RISE                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x09U)
#define BOARD_TPS65941_INTR_ID_GPIO3_RISE                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x0AU)
#define BOARD_TPS65941_INTR_ID_GPIO4_RISE                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x0BU)
#define BOARD_TPS65941_INTR_ID_GPIO5_RISE                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x0CU)
#define BOARD_TPS65941_INTR_ID_GPIO6_RISE                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x0DU)
#define BOARD_TPS65941_INTR_ID_GPIO7_RISE                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x0EU)
#define BOARD_TPS65941_INTR_ID_GPIO8_RISE                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x0FU)
#define BOARD_TPS65941_INTR_ID_GPIO9_RISE                   ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x13U)
#define BOARD_TPS65941_INTR_ID_GPIO10_RISE                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x14U)
#define BOARD_TPS65941_INTR_ID_GPIO11_RISE                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_GPIO) << 16) | (0 << 8) | 0x15U)

#define BOARD_TPS65941_INTR_ID_FSD                          ((((uint32_t)BOARD_TPS65941_INTR_TYPE_STARTUP_SRC) << 16) | (0 << 8) | 0x04U)
#define BOARD_TPS65941_INTR_ID_RTC                          ((((uint32_t)BOARD_TPS65941_INTR_TYPE_STARTUP_SRC) << 16) | (1 << 8) | 0x02U)
#define BOARD_TPS65941_INTR_ID_ENABLE                       ((((uint32_t)BOARD_TPS65941_INTR_TYPE_STARTUP_SRC) << 16) | (0 << 8) | 0x01U)
#define BOARD_TPS65941_INTR_ID_NPWRON_START                 ((((uint32_t)BOARD_TPS65941_INTR_TYPE_STARTUP_SRC) << 16) | (0 << 8) | 0x00U)

#define BOARD_TPS65941_INTR_ID_TWARN                        ((((uint32_t)BOARD_TPS65941_INTR_TYPE_MISC_WARN) << 16) | (0 << 8) | 0x03U)
#define BOARD_TPS65941_INTR_ID_EXT_CLK                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_MISC_WARN) << 16) | (0 << 8) | 0x01U)
#define BOARD_TPS65941_INTR_ID_BIST_PASS                    ((((uint32_t)BOARD_TPS65941_INTR_TYPE_MISC_WARN) << 16) | (0 << 8) | 0x00U)

#define BOARD_TPS65941_INTR_ID_RECOV_CNT                    ((((uint32_t)BOARD_TPS65941_INTR_TYPE_MODERATE_ERR) << 16) | (1 << 8) | 0x06U)
#define BOARD_TPS65941_INTR_ID_NPWRON_LONG                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_MODERATE_ERR) << 16) | (0 << 8) | 0x05U)
#define BOARD_TPS65941_INTR_ID_SPMI_ERR                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_MODERATE_ERR) << 16) | (0 << 8) | 0x04U)
#define BOARD_TPS65941_INTR_ID_PFSM_ERR                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_MODERATE_ERR) << 16) | (0 << 8) | 0x03U)
#define BOARD_TPS65941_INTR_ID_REG_CRC_ERR                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_MODERATE_ERR) << 16) | (0 << 8) | 0x02U)
#define BOARD_TPS65941_INTR_ID_BIST_FAIL                    ((((uint32_t)BOARD_TPS65941_INTR_TYPE_MODERATE_ERR) << 16) | (0 << 8) | 0x01U)
#define BOARD_TPS65941_INTR_ID_TSD_ORD                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_MODERATE_ERR) << 16) | (1 << 8) | 0x00U)

#define BOARD_TPS65941_INTR_ID_VCCA_OVP                     ((((uint32_t)BOARD_TPS65941_INTR_TYPE_SEVERE_ERR) << 16) | (1 << 8) | 0x01U)
#define BOARD_TPS65941_INTR_ID_TSD_IMM                      ((((uint32_t)BOARD_TPS65941_INTR_TYPE_SEVERE_ERR) << 16) | (1 << 8) | 0x00U)

#define BOARD_TPS65941_INTR_ID_IMM_SHUTDOWN                 ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x00U)
#define BOARD_TPS65941_INTR_ID_ORD_SHUTDOWN                 ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x01U)
#define BOARD_TPS65941_INTR_ID_MCU_PWR_ERR                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x02U)
#define BOARD_TPS65941_INTR_ID_SOC_PWR_ERR                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x03U)
#define BOARD_TPS65941_INTR_ID_COMM_FRM_ERR                 ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x08U)
#define BOARD_TPS65941_INTR_ID_COMM_CRC_ERR                 ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x09U)
#define BOARD_TPS65941_INTR_ID_COMM_ADR_ERR                 ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x0BU)
#define BOARD_TPS65941_INTR_ID_I2C2_CRC_ERR                 ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x0DU)
#define BOARD_TPS65941_INTR_ID_I2C2_ADR_ERR                 ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x0FU)
#define BOARD_TPS65941_INTR_ID_EN_DRV_RDBACK                ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x10U)
#define BOARD_TPS65941_INTR_ID_NINT_RDBACK                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x11U)
#define BOARD_TPS65941_INTR_ID_NRSTOUT_RDBACK               ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x12U)
#define BOARD_TPS65941_INTR_ID_NRSTOUT_SOC_RDBACK           ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x13U)
#define BOARD_TPS65941_INTR_ID_ESM_SOC_PIN                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x18U)
#define BOARD_TPS65941_INTR_ID_ESM_SOC_FAIL                 ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x19U)
#define BOARD_TPS65941_INTR_ID_ESM_SOC_RST                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x1AU)
#define BOARD_TPS65941_INTR_ID_ESM_MCU_PIN                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x1BU)
#define BOARD_TPS65941_INTR_ID_ESM_MCU_FAIL                 ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x1CU)
#define BOARD_TPS65941_INTR_ID_ESM_MCU_RST                  ((((uint32_t)BOARD_TPS65941_INTR_TYPE_FSM_ERR) << 16) | (0 << 8) | 0x1DU)

#define BOARD_TPS65941_INTR_REG_WIDTH                       (0x8U)

/** Interrupt Enable/Disable */
#define BOARD_TPS65941_INTR_ENABLE                          (0)
#define BOARD_TPS65941_INTR_DISABLE                         (1)

/** Interrupt Set/UnSet */
#define BOARD_TPS65941_INTR_SET                             (1)
#define BOARD_TPS65941_INTR_UNSET                           (0)

/** Voltage monitor PGOOD level values */
#define BOARD_TPS65941_PG_3V3_LEVEL                         (0)
#define BOARD_TPS65941_PG_5V_LEVEL                          (1)

/** Voltage monitor PGOOD threshold values */
#define BOARD_TPS65941_PG_THR_3_PERCENT                     (0x0U)
#define BOARD_TPS65941_PG_THR_3_5_PERCENT                   (0x1U)
#define BOARD_TPS65941_PG_THR_4_PERCENT                     (0x2U)
#define BOARD_TPS65941_PG_THR_5_PERCENT                     (0x3U)
#define BOARD_TPS65941_PG_THR_6_PERCENT                     (0x4U)
#define BOARD_TPS65941_PG_THR_7_PERCENT                     (0x5U)
#define BOARD_TPS65941_PG_THR_8_PERCENT                     (0x6U)
#define BOARD_TPS65941_PG_THR_10_PERCENT                    (0x7U)

/** Peak Current limit of BUCK power resources */
#define BOARD_TPS65941_ILIM_2_5A                            (0x2U)
#define BOARD_TPS65941_ILIM_3_5A                            (0x3U)
#define BOARD_TPS65941_ILIM_4_5A                            (0x4U)
#define BOARD_TPS65941_ILIM_5_5A                            (0x5U)

/** Voltage monitor OV and UV Enable/Disable */
#define BOARD_TPS65941_OV_UV_DISABLE                        (0)
#define BOARD_TPS65941_OV_UV_ENABLE                         (1)

/** PGOOD Mask Enable/Disable */
#define BOARD_TPS65941_PGOOD_MASK                           (0U)
#define BOARD_TPS65941_PGOOD_UNMASK                         (1U)

/** PGOOD Window Value */
#define BOARD_TPS65941_UV_MONITOR                           (0U)
#define BOARD_TPS65941_UV_OV_MONITOR                        (1U)

/** Thermal error status value */
#define BOARD_TPS65941_TDIE_NO_WARN                         (0)
#define BOARD_TPS65941_TDIE_WARN                            (1)
#define BOARD_TPS65941_TDIE_WARN_ORD_SD                     (2)
#define BOARD_TPS65941_TDIE_WARN_IMM_SD                     (3)

/** Thermal threshold value */
#define BOARD_TPS65941_THERMAL_TEMP_120C                    (0x0U)
#define BOARD_TPS65941_THERMAL_TEMP_130C                    (0x1U)

/** ESM Start/Stop value */
#define BOARD_TPS65941_ESM_STOP                             (0x0)
#define BOARD_TPS65941_ESM_START                            (0x1)

/** ESM Enable/Disable value */
#define BOARD_TPS65941_ESM_DISABLE                          (0x0)
#define BOARD_TPS65941_ESM_ENABLE                           (0x1)

/** RTC timer Periods */
#define BOARD_TPS65941_SECOND_INTR_PERIOD                   (0x0U)
#define BOARD_TPS65941_MINUTE_INTR_PERIOD                   (0x1U)
#define BOARD_TPS65941_HOUR_INTR_PERIOD                     (0x2U)
#define BOARD_TPS65941_DAY_INTR_PERIOD                      (0x3U)

/** RTC alarm and timer interrupt */
#define BOARD_TPS65941_ALARM_INTR_ENABLE                    (0x1U)
#define BOARD_TPS65941_ALARM_INTR_DISABLE                   (0x0U)
#define BOARD_TPS65941_TIMER_INTR_ENABLE                    (0x1U)
#define BOARD_TPS65941_TIMER_INTR_DISABLE                   (0x0U)

/** Watchdog timer Mode */
#define BOARD_TPS65941_WDT_DISABLE                          (0x1U)
#define BOARD_TPS65941_WDT_ENABLE                           (0x0U)

/** Watchdog config mode */
#define BOARD_TPS65941_WDT_TRIGGER_MODE                     (0x0U)
#define BOARD_TPS65941_WDT_QA_MODE                          (0x1U)

/** Watchdog reset Enable/Disable */
#define BOARD_TPS65941_WDT_RST_DISABLE                      (0x0U)
#define BOARD_TPS65941_WDT_RST_ENABLE                       (0x1U)

/** ESM configuration */
#define BOARD_TPS65941_ESM_SOC                              (0x0U)
#define BOARD_TPS65941_ESM_MCU                              (0x1U)

/** ESM configuration mode */
#define BOARD_TPS65941_ESM_LEVEL_MODE                       (0x0U)
#define BOARD_TPS65941_ESM_PWM_MODE                         (0x1U)

/** RTC time mode */
#define BOARD_TPS65941_12_HOUR_MODE                         (1)
#define BOARD_TPS65941_24_HOUR_MODE                         (0)

/** RTC Meridien mode */
#define BOARD_TPS65941_AM_MODE                              (0)
#define BOARD_TPS65941_PM_MODE                              (1)

/** RTC Week days */
#define BOARD_TPS65941_SUNDAY                               (0)
#define BOARD_TPS65941_MONDAY                               (1)
#define BOARD_TPS65941_TUESDAY                              (2)
#define BOARD_TPS65941_WEDNESDAY                            (3)
#define BOARD_TPS65941_THURSDAY                             (4)
#define BOARD_TPS65941_FRIDAY                               (5)
#define BOARD_TPS65941_SATURDAY                             (6)

/** RTC State */
#define BOARD_TPS65941_RTC_FROZEN                           (0)
#define BOARD_TPS65941_RTC_START                            (1)

/** WDT Error status values */
#define BOARD_TPS65941_WDT_RST_INT                          (0)
#define BOARD_TPS65941_WDT_FAIL_INT                         (1)
#define BOARD_TPS65941_WDT_ANSW_ERR                         (2)
#define BOARD_TPS65941_WDT_SEQ_ERR                          (3)
#define BOARD_TPS65941_WDT_ANSW_ERLY_ERR                    (4)
#define BOARD_TPS65941_WDT_TRIG_ERLY_ERR                    (5)
#define BOARD_TPS65941_WDT_TIMEOUT_ERR                      (6)
#define BOARD_TPS65941_WDT_LNGWIN_TIMEOUT_ERR               (7)
#define BOARD_TPS65941_WDT_ERR_LATCHED                      (1)
#define BOARD_TPS65941_WDT_NO_ERR                           (0)

/** I2C number of bytes */
#define BOARD_I2C_NUM_OF_BYTES_01                           (1U)

/* @} */

/**
 *
 *  \ingroup BOARD_LIB_DEVICES_POWER_TPS65941 
 *
 *  \defgroup BOARD_LIB_DEVICES_POWER_TPS65941_APIS Application Interfaces
 *
 *  Application interfaces provided by TPS65941 PMIC device library.
 *
 *  @{
 *
 */

/**
 * \brief   TPS65941 gpio details object structure 
 */
typedef struct Board_Tps65941GpioRegCfg_s
{
    uint8_t regAddr;
    /** Register Address of the gpio */
    uint8_t outRegAddr;
    /** Register Address of the output buffer of gpio */
    uint8_t inRegAddr;
    /** Register Address of the input buffer of gpio */
    uint8_t inOutRegBitPos;
    /** Register bit position of the input/output buffer of gpio */
}Board_Tps65941GpioRegCfg;

/**
 * \brief   TPS65941 power resource details object structure 
 */
typedef struct Board_Tps65941PwrResourceRegCfg_s
{
    uint8_t cntrRegAddr;
    /** Register address of the power resource control */
    uint8_t cfgRegAddr;
    /** Register address of the power resource configuration */
    uint8_t voltageRegAddr;
    /** Register address of the power resource voltage */
    uint8_t pgRegAddr;
    /** Register address of the power resource power good */
}Board_Tps65941PwrResourceRegCfg;

/**
 * \brief   TPS65941 power resource details object structure
 */
typedef struct Board_Tps65941IntrRegMap_s
{
    uint8_t maskRegAddr;
    /** Register address of the interrupt mask register */
    uint8_t intrRegAddr;
    /** Register address of the interrupt status register */
    uint8_t maxReg;
    /** Maximum register count */
}Board_Tps65941IntrRegMap;

/**
 * \brief   TPS65941 voltage monitoring details object structure
 */
typedef struct Board_Tps65941VoltMonitorCfg_s
{
    uint8_t monitortype;
	/** Value to represent type of monitor (voltage/current) */
    uint8_t regularEnable;
	/** Value to represent regulator enable/disable */
    uint8_t currentLimit;
	/** Value to represent current limit */
    uint8_t voltOverLimit;
	/** Value to represent voltage over limit */
    uint8_t voltUnderLimit;
	/** Value to represent voltage under limit */
    uint8_t pgoodEnable;
	/** Value to represent PGood enable/disable */
    uint8_t overVoltEnable;
    /** Value to represent overvoltage monitor enable */
}Board_Tps65941VoltMonitorCfg;

/**
 * \brief   TPS65941 RTC time object structure
 */
typedef struct Board_Tps65941RtcTime_s
{
    uint8_t seconds;
    /** Time value in minutes. */
    uint8_t minutes;
    /** Time value in seconds */
    uint8_t hour;
	/** Time value in hour */
    uint8_t timeMode;
	/** Hour Mode to represent either
        12 Hour mode or 24 Hour mode. */
    uint8_t meridienMode;
	/** Meridien type to indicate either AM mode or PM mode */
}Board_Tps65941RtcTime;

/**
 * \brief   TPS65941 RTC Date object structure
 */
typedef struct Board_Tps65941RtcDate_s
{
    uint8_t date;
	/** Value to represent the Date. */
    uint8_t month;
	/** Value to represent the Month. */
    uint8_t year;    
	/** Value to represent the Year. */
    uint8_t week;
    /** Value to represent the week of the year */
}Board_Tps65941RtcDate;

/**
 * \brief   TPS65941 WDT configuration parameters object structure
 */
typedef struct Board_Tps65941WdtCfg_s
{
    uint8_t longWinDuration;
    /** Value to represent Long Window duration */
    uint8_t win1Duration;
    /** Value to represent Window-1 duration */
    uint8_t win2Duration;
    /** Value to represent Window-2 duration */
    uint8_t failThreshold;
    /** Value to represent fail threshold */
    uint8_t rstThreshold;
    /** Value to represent reset threshold */
    uint8_t rstEnable;
    /** Value to represent to enable TPS65941 reset on fail */
}Board_Tps65941WdtCfg;

/**
 * \brief   TPS65941 ESM configuration parameters object structure
 */
typedef struct Board_Tps65941EsmCfg_s
{
    uint8_t delay1TimeInterval;
    /** Value to represent delay-1 timer */
    uint8_t delay2TimeInterval;
    /** Value to represent delay-2 timer */
    uint8_t maxHPTimeThreshold;
    /** Value to represent max high-pulse time-duration threshold */
    uint8_t minHPTimeThreshold;
    /** Value to represent min high-pulse time-duration threshold */
    uint8_t maxLPTimeThreshold;
    /** Value to represent max low-pulse time-duration threshold */
    uint8_t minLPTimeThreshold;
    /** Value to represent min low-pulse time-duration threshold */
}Board_Tps65941EsmCfg;

/**
 * \brief   TPS65941 GPIO read function.
 *
 * This function is used to read the gpio signal level of the TPS65941
 * device.
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 * \param   pinNum      [IN]    TPS65941 GPIO number
 * \param   pinValue    [OUT]   TPS65941 GPIO signal level High/Low
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GpioRead(void *handle,
                                    uint8_t slaveAddr,
                                    uint8_t pinNum,
                                    uint8_t *pinValue);

/**
 * \brief   TPS65941 GPIO write function.
 *
 * This function is used to write the gpio signal level to the TPS65941
 * device.
 *
 * \param   handle      [IN]    Low level driver 
 * \param   slaveAddr   [IN]    TPS65941 slave address
 * \param   pinNum      [IN]    TPS65941 GPIO number
 * \param   pinValue    [IN]    TPS65941 GPIO signal level High/Low
 *                              Valid values: BOARD_TPS65941_GPIO_HIGH
 *                                            BOARD_TPS65941_GPIO_LOW
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GpioWrite(void *handle,
                                     uint8_t slaveAddr,
                                     uint8_t pinNum, 
                                     uint8_t pinValue);

/**
 * \brief   TPS65941 set voltage function.
 *
 * This function is used to set the voltage to the power resource of
 * the TPS65941.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   powerResource   [IN]    TPS65941 Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   millivolt       [IN]    Voltage in millivolt
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetVoltage(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t powerResource,
                                      uint16_t millivolt);

/**
 * \brief   TPS65941 read voltage function.
 *
 * This function is used to read the voltage to the power resource of
 * the TPS65941.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   powerResource   [IN]    TPS65941 Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   millivolt       [OUT]   Voltage in millivolt
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetVoltage(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t powerResource,
                                      uint16_t *millivolt);

/**
 * \brief   Conversion of VOUT code to millivolt.
 *
 * This function is used to convert the VOUT code read from the PMIC
 * registers to millivolt.
 *
 * \param   voutCode        [IN]    VOUT code in hexadecimal
 * \param   powerResource   [IN]    PMIC Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   millivolt       [OUT]   Voltage in millivolt
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941ConvertVolt(uint8_t voutCode,
                                       uint8_t powerResource,
                                       uint16_t *millivolt);

/**
 * \brief   Conversion of millivolt to VOUT code.
 *
 * This function is used to convert the millivolt value to VOUT code
 * to write into the TPS65941 registers.
 *
 * \param   millivolt       [IN]    Voltage in millivolt
 * \param   powerResource   [IN]    TPS65941 Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   voutCode        [OUT]   VOUT code in hexadecimal
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941ConvertVoutCode(uint16_t millivolt,
                                           uint8_t powerResource,
                                           uint8_t *voutCode);

/**
 * \brief   TPS65941 enable/disable interrupt function.
 *
 * This function is used to enable/disable the interrupt of the TPS65941.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   intrID    	    [IN]    TPS65941 Interrupt ID
 *                                  Use the macros BOARD_TPS65941_INTR_ID_XXX
 * \param   intrEnable  	[IN]    Enable/Disable the interrupt
 *                                  Valid values: BOARD_TPS65941_INTR_ENABLE 
 *                                                BOARD_TPS65941_INTR_DISABLE
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941ConfigIntr(void *handle,
                                      uint8_t slaveAddr,
                                      uint32_t intrID,
                                      uint8_t intrEnable);

/**
 * \brief   Get the TPS65941 interrupt function.
 *
 * This function is used to get the interrupt status of the TPS65941.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   intrID    	    [IN]    TPS65941 Interrupt ID
 *                                  Use the macros BOARD_TPS65941_INTR_ID_XXX
 * \param   intrStatus      [OUT]   Interrupt status
 *                                  Valid value:
 *                                  BOARD_TPS65941_INTR_SET
 *                                  BOARD_TPS65941_INTR_UNSET
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetIntrStatus(void *handle,
                                         uint8_t slaveAddr,
                                         uint32_t intrID,
                                         uint8_t *intrStatus);

/**
 * \brief   Clears the TPS65941 interrupt function.
 *
 * This function is used to clear the interrupt of the TPS65941.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   intrID          [IN]    TPS65941 Interrupt ID
 *                                  Use the macros BOARD_TPS65941_INTR_ID_XXX
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941ClearIntr(void *handle,
                                     uint8_t slaveAddr,
                                     uint32_t intrID);

/**
 * \brief   Set the TPS65941 thermal threshold value function.
 *
 * This function is used to set the thermal temperature threshold
 * value for the TPS65941.
 *
 * \param   handle                  [IN]    Low level driver handle
 * \param   slaveAddr               [IN]    TPS65941 slave address
 * \param   thermalThresholdVal     [IN]    Thermal temperature threshold value
 *                                          Valid Values: BOARD_TPS65941_THERMAL_TEMP_120C
 *                                                        BOARD_TPS65941_THERMAL_TEMP_130C
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetThermalThresVal(void *handle,
                                              uint8_t slaveAddr,
                                              uint32_t thermalThresholdVal);

/**
 * \brief   Get the TPS65941 thermal status function.
 *
 * This function is used to read the thermal status of the TPS65941.
 *
 * \param   handle              [IN]    Low level driver handle
 * \param   slaveAddr           [IN]    TPS65941 slave address
 * \param   thermalStatus       [OUT]   TPS65941 Thermal status
 *                                      Valid Value:
 *                                      BOARD_TPS65941_TDIE_NO_WARN    
 *                                      BOARD_TPS65941_TDIE_WARN       
 *                                      BOARD_TPS65941_TDIE_WARN_ORD_SD
 *                                      BOARD_TPS65941_TDIE_WARN_IMM_SD
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetThermalStatus(void *handle,
                                            uint8_t slaveAddr,
                                            uint32_t *thermalStatus);

/**
 * \brief   Set the thermal monitoring function.
 *
 * This function is used to set the thermal temperature monitoring
 * function with PGOOD signal.
 *
 * \param   handle              [IN]    Low level driver handle
 * \param   slaveAddr           [IN]    TPS65941 slave address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetThermalMonitor(void *handle,
                                             uint8_t slaveAddr);

/**
 * \brief   Set the voltage monitoring function.
 *
 * This function is used to set the voltage monitoring function to
 * the BUCK and LDO power resources with PGOOD signal.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   powerResource   [IN]    TPS65941 Power resource
 *                                  Valid values: BOARD_TPS65941_BUCK1_RESOURCE
                                                  BOARD_TPS65941_BUCK2_RESOURCE
                                                  BOARD_TPS65941_BUCK3_RESOURCE
                                                  BOARD_TPS65941_BUCK4_RESOURCE
                                                  BOARD_TPS65941_BUCK5_RESOURCE
                                                  BOARD_TPS65941_LDO1_RESOURCE
                                                  BOARD_TPS65941_LDO2_RESOURCE
                                                  BOARD_TPS65941_LDO3_RESOURCE
                                                  BOARD_TPS65941_LDO4_RESOURCE
 * \param   voltMonCfg      [IN]    TPS65941 voltage monitor details
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetVoltageMonitor(void *handle,
                                             uint8_t slaveAddr,
                                             uint8_t powerResource,
                                             Board_Tps65941VoltMonitorCfg *voltMonCfg);

/**
 * \brief   Set the Vcca voltage monitoring function.
 *
 * This function is used to set the voltage monitoring function to
 * the Vcca with PGOOD signal.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   vccaPgLevel     [IN]    TPS65941 Vcca Power good level
 *                                  Valid values:
 *                                  BOARD_TPS65941_PG_3V3_LEVEL
 *                                  BOARD_TPS65941_PG_5V_LEVEL
 * \param   voltMonitorCfg  [IN]    TPS65941 voltage monitor details
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetVccaMonitor(void *handle,
                                          uint8_t slaveAddr,
                                          uint8_t vccaPgLevel,
                                          Board_Tps65941VoltMonitorCfg *voltMonitorCfg);

/**
 * \brief   Set the TPS65941 RTC date and time function.
 *
 * This function is used to set the date and time parameters in
 * RTC present in the TPS65941.
 *
 * \param   handle              [IN]    Low level driver handle
 * \param   slaveAddr           [IN]    TPS65941 slave address
 * \param   timeCfg             [IN]    TPS65941 RTC time configuration
 * \param   dateCfg             [IN]    TPS65941 RTC date configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetRtc(void *handle,
                                  uint8_t slaveAddr,
                                  Board_Tps65941RtcTime *timeCfg,
                                  Board_Tps65941RtcDate *dateCfg);

/**
 * \brief   Get the TPS65941 RTC date and time function.
 *
 * This function is used to get the current date and time parameters
 * in RTC present in the TPS65941.
 *
 * \param   handle              [IN]    Low level driver handle
 * \param   slaveAddr           [IN]    TPS65941 slave address
 * \param   timeCfg             [OUT]   TPS65941 RTC time configuration
 * \param   dateCfg             [OUT]   TPS65941 RTC date configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetRtc(void *handle,
                                  uint8_t slaveAddr,
                                  Board_Tps65941RtcTime *timeCfg,
                                  Board_Tps65941RtcDate *dateCfg);

/**
 * \brief   Set the alarm interrupt in TPS65941 RTC function.
 *
 * This function is used to set the alarm date and time interrupt
 * in RTC present in the TPS65941.
 *
 * \param   handle           [IN]    Low level driver handle
 * \param   slaveAddr        [IN]    TPS65941 slave address
 * \param   timeCfg          [IN]    TPS65941 RTC time configuration
 * \param   dateCfg          [IN]    TPS65941 RTC date configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetAlarmIntr(void *handle,
                                        uint8_t slaveAddr,
                                        Board_Tps65941RtcTime *timeCfg,
                                        Board_Tps65941RtcDate *dateCfg);

/**
 * \brief   Set the timer interrupt in TPS65941 RTC function.
 *
 * This function is used to set the timer interrupt in RTC present
 * in the TPS65941.
 *
 * \param   handle              [IN]    Low level driver handle
 * \param   slaveAddr           [IN]    TPS65941 slave address
 * \param   timerPeriod         [IN]    Timer interrupt periods
 *                                      Valid values:
 *                                      BOARD_TPS65941_SECOND_INTR_PERIOD
 *                                      BOARD_TPS65941_MINUTE_INTR_PERIOD
 *                                      BOARD_TPS65941_HOUR_INTR_PERIOD
 *                                      BOARD_TPS65941_DAY_INTR_PERIOD
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941SetTimerIntr(void *handle,
                                        uint8_t slaveAddr,
                                        uint8_t timerPeriod);

/**
 * \brief   Enable/Disable the TPS65941 Watchdog function.
 *
 * This function is used to enable/disable the watchdog function in the
 * TPS65941.
 *
 * \param   handle          [IN]    Low level driver 
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtDisable      [IN]    Enable/Disable the watchdog
 *                                  Valid values:
 *                                  BOARD_TPS65941_WDT_DISABLE
 *                                  BOARD_TPS65941_WDT_ENABLE
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941WdtDisable(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t wdtDisable);

/**
 * \brief   TPS65941 watchdog configuration function.
 *
 * This function is used to configure the watchdog function parameters
 * in the TPS65941 in either trigger mode or Q&A (question and answer) mode.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtCfgMode      [IN]    Watchdog configuration mode
 *                                  Valid values:
 *                                  BOARD_TPS65941_WDT_QA_MODE
 *                                  BOARD_TPS65941_WDT_TRIGGER_MODE
 * \param   wdtCfg          [IN]    TPS65941 watchdog configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941WdtConfig(void *handle,
                                     uint8_t slaveAddr,
                                     uint8_t wdtCfgMode,
                                     Board_Tps65941WdtCfg *wdtCfg);

/**
 * \brief   TPS65941 watchdog error status function.
 *
 * This function is used to get the error status from the TPS65941 watchdog.
 *
 * \param   handle          [IN]    Low level driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   wdtErrType      [IN]    TPS65941 Watchdog error type
 *                                  Valid Values:
 *                                  BOARD_TPS65941_WDT_RST_INT
 *                                  BOARD_TPS65941_WDT_FAIL_INT
 *                                  BOARD_TPS65941_WDT_ANSW_ERR
 *                                  BOARD_TPS65941_WDT_SEQ_ERR
 *                                  BOARD_TPS65941_WDT_ANSW_ERLY_ERR
 *                                  BOARD_TPS65941_WDT_TRIG_ERLY_ERR
 *                                  BOARD_TPS65941_WDT_TIMEOUT_ERR
 *                                  BOARD_TPS65941_WDT_LNGWIN_TIMEOUT_ERR
 * \param   wdtErrStat      [OUT]   TPS65941 Watchdog error status
 *                                  Valid Values:
 *                                  BOARD_TPS65941_WDT_ERR_LATCHED
 *                                  BOARD_TPS65941_WDT_NO_ERR
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetWdtStat(void *handle,
                                      uint8_t slaveAddr,
                                      uint8_t wdtErrType,
                                      uint8_t *wdtErrStat);

/**
 * \brief   Start TPS65941 ESM function.
 *
 * This function is used the start the TPS65941 ESM for SoC or MCU in either
 * level or PWM mode.
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 * \param   esmCfg      [IN]    ESM configuration
 *                              Valid values:
 *                              BOARD_TPS65941_ESM_SOC
 *                              BOARD_TPS65941_ESM_MCU
 * \param   esmMode     [IN]    ESM configuration mode
 *                              Valid values:
 *                              BOARD_TPS65941_ESM_LEVEL_MODE
 *                              BOARD_TPS65941_ESM_PWM_MODE
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941StartEsm(void *handle,
                                    uint8_t slaveAddr,
                                    uint8_t esmCfg,
                                    uint8_t esmMode);

/**
 * \brief   Stop TPS65941 ESM function.
 *
 * This function is used the stop the TPS65941 ESM for SoC or MCU.
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 * \param   esmCfg      [IN]    ESM configuration
 *                              Valid values:
 *                              BOARD_TPS65941_ESM_SOC
 *                              BOARD_TPS65941_ESM_MCU
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941StopEsm(void *handle,
                                   uint8_t slaveAddr,
                                   uint8_t esmCfg);
                               
/**
 * \brief   TPS65941 ESM configuration function.
 *
 * This function is used to configure the TPS65941 ESM parameters.
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 * \param   esmCfgType  [IN]    ESM configuration type
 *                              Valid values:
 *                              BOARD_TPS65941_ESM_SOC
 *                              BOARD_TPS65941_ESM_MCU
 * \param   esmCfg      [IN]    TPS65941 ESM configuration
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941ConfigEsm(void *handle,
                                     uint8_t slaveAddr,
                                     uint8_t esmCfgType,
                                     Board_Tps65941EsmCfg *esmCfg);

/**
 * \brief   Get the ESM error count function.
 *
 * This function is used to get the number error count events for the
 * TPS65941 ESM for SoC or MCU.
 *
 * \param   handle      [IN]    Low level driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 * \param   esmCfg      [IN]    ESM configuration
 *                              Valid values:
 *                              BOARD_TPS65941_ESM_SOC
 *                              BOARD_TPS65941_ESM_MCU
 * \param   esmErrCnt   [OUT]   TPS65941 ESM error count
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
Board_STATUS Board_tps65941GetEsmCount(void *handle,
                                       uint8_t slaveAddr,
                                       uint8_t esmCfg,
                                       uint8_t *esmErrCnt);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _TPS65941_H_ */

/* @} */

/* Nothing past this point */
