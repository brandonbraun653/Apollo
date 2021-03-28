/*
* hw_rtc.h
*
* Register-level header file for RTCSS
*
* Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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
#ifndef HW_RTC_H_
#define HW_RTC_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define RTCSS_ALARM2_SECONDS_REG                                (0x80U)
#define RTCSS_SECONDS_REG                                       (0x0U)
#define RTCSS_SYSCONFIG                                         (0x78U)
#define RTCSS_ALARM_MONTHS_REG                                  (0x30U)
#define RTCSS_CTRL_REG                                          (0x40U)
#define RTCSS_MONTHS_REG                                        (0x10U)
#define RTCSS_WEEKS_REG                                         (0x18U)
#define RTCSS_DAYS_REG                                          (0xcU)
#define RTCSS_ALARM_DAYS_REG                                    (0x2cU)
#define RTCSS_SCRATCH1_REG                                      (0x64U)
#define RTCSS_DEBOUNCE                                          (0x9cU)
#define RTCSS_ALARM2_YEARS_REG                                  (0x94U)
#define RTCSS_MINUTES_REG                                       (0x4U)
#define RTCSS_ALARM_MINUTES_REG                                 (0x24U)
#define RTCSS_HOURS_REG                                         (0x8U)
#define RTCSS_ALARM2_MONTHS_REG                                 (0x90U)
#define RTCSS_ALARM_HOURS_REG                                   (0x28U)
#define RTCSS_ALARM2_MINUTES_REG                                (0x84U)
#define RTCSS_PMIC                                              (0x98U)
#define RTCSS_OSC_REG                                           (0x54U)
#define RTCSS_ALARM_YEARS_REG                                   (0x34U)
#define RTCSS_IRQWAKEEN                                         (0x7cU)
#define RTCSS_ALARM2_DAYS_REG                                   (0x8cU)
#define RTCSS_COMP_MSB_REG                                      (0x50U)
#define RTCSS_SCRATCH0_REG                                      (0x60U)
#define RTCSS_YEARS_REG                                         (0x14U)
#define RTCSS_KICK1R                                            (0x70U)
#define RTCSS_INTRS_REG                                         (0x48U)
#define RTCSS_KICK0R                                            (0x6cU)
#define RTCSS_ALARM2_HOURS_REG                                  (0x88U)
#define RTCSS_REVISION                                          (0x74U)
#define RTCSS_STS_REG                                           (0x44U)
#define RTCSS_COMP_LSB_REG                                      (0x4cU)
#define RTCSS_ALARM_SECONDS_REG                                 (0x20U)
#define RTCSS_SCRATCH2_REG                                      (0x68U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define RTCSS_ALARM2_SECONDS_REG_SEC0_SHIFT                     (0U)
#define RTCSS_ALARM2_SECONDS_REG_SEC0_MASK                      (0x0000000fU)

#define RTCSS_ALARM2_SECONDS_REG_SEC1_SHIFT                     (4U)
#define RTCSS_ALARM2_SECONDS_REG_SEC1_MASK                      (0x00000070U)

#define RTCSS_SECONDS_REG_SEC0_SHIFT                            (0U)
#define RTCSS_SECONDS_REG_SEC0_MASK                             (0x0000000fU)

#define RTCSS_SECONDS_REG_SEC1_SHIFT                            (4U)
#define RTCSS_SECONDS_REG_SEC1_MASK                             (0x00000070U)

#define RTCSS_SYSCONFIG_IDLEMODE_SHIFT                          (0U)
#define RTCSS_SYSCONFIG_IDLEMODE_MASK                           (0x00000003U)
#define RTCSS_SYSCONFIG_IDLEMODE_FORCE_IDLE                      (0U)
#define RTCSS_SYSCONFIG_IDLEMODE_SMART_IDLE_WAKEUP               (3U)
#define RTCSS_SYSCONFIG_IDLEMODE_SMART_IDLE                      (2U)
#define RTCSS_SYSCONFIG_IDLEMODE_NO_IDLE                         (1U)

#define RTCSS_ALARM_MONTHS_REG_MONTH0_SHIFT                     (0U)
#define RTCSS_ALARM_MONTHS_REG_MONTH0_MASK                      (0x0000000fU)

#define RTCSS_ALARM_MONTHS_REG_MONTH1_SHIFT                     (4U)
#define RTCSS_ALARM_MONTHS_REG_MONTH1_MASK                      (0x00000010U)

#define RTCSS_CTRL_REG_STOP_RTC_SHIFT                           (0U)
#define RTCSS_CTRL_REG_STOP_RTC_MASK                            (0x00000001U)
#define RTCSS_CTRL_REG_STOP_RTC_FROZEN                           (0U)
#define RTCSS_CTRL_REG_STOP_RTC_RUNNING                          (1U)

#define RTCSS_CTRL_REG_ROUND_30S_SHIFT                          (1U)
#define RTCSS_CTRL_REG_ROUND_30S_MASK                           (0x00000002U)
#define RTCSS_CTRL_REG_ROUND_30S_NO_UPDATE                       (0U)
#define RTCSS_CTRL_REG_ROUND_30S_ROUNDED                         (1U)

#define RTCSS_CTRL_REG_AUTO_COMP_SHIFT                          (2U)
#define RTCSS_CTRL_REG_AUTO_COMP_MASK                           (0x00000004U)
#define RTCSS_CTRL_REG_AUTO_COMP_DISABLED                        (0U)
#define RTCSS_CTRL_REG_AUTO_COMP_ENABLED                         (1U)

#define RTCSS_CTRL_REG_MODE_12_24_SHIFT                         (3U)
#define RTCSS_CTRL_REG_MODE_12_24_MASK                          (0x00000008U)
#define RTCSS_CTRL_REG_MODE_12_24_HOUR12                         (1U)
#define RTCSS_CTRL_REG_MODE_12_24_HOUR24                         (0U)

#define RTCSS_CTRL_REG_TEST_MODE_SHIFT                          (4U)
#define RTCSS_CTRL_REG_TEST_MODE_MASK                           (0x00000010U)
#define RTCSS_CTRL_REG_TEST_MODE_FUNC                            (0U)
#define RTCSS_CTRL_REG_TEST_MODE                                 (1U)

#define RTCSS_CTRL_REG_SET_32_CTR_SHIFT                         (5U)
#define RTCSS_CTRL_REG_SET_32_CTR_MASK                          (0x00000020U)
#define RTCSS_CTRL_REG_SET_32_CTR_NO_ACTION                      (0U)
#define RTCSS_CTRL_REG_SET_32_CTR                                (1U)

#define RTCSS_CTRL_REG_RTC_DISABLE_SHIFT                        (6U)
#define RTCSS_CTRL_REG_RTC_DISABLE_MASK                         (0x00000040U)
#define RTCSS_CTRL_REG_RTC_DISABLE                               (1U)
#define RTCSS_CTRL_REG_RTC_DISABLE_ENABLE                        (0U)

#define RTCSS_MONTHS_REG_MONTH0_SHIFT                           (0U)
#define RTCSS_MONTHS_REG_MONTH0_MASK                            (0x0000000fU)

#define RTCSS_MONTHS_REG_MONTH1_SHIFT                           (4U)
#define RTCSS_MONTHS_REG_MONTH1_MASK                            (0x00000010U)

#define RTCSS_WEEKS_REG_WEEK_SHIFT                              (0U)
#define RTCSS_WEEKS_REG_WEEK_MASK                               (0x00000007U)

#define RTCSS_DAYS_REG_DAY0_SHIFT                               (0U)
#define RTCSS_DAYS_REG_DAY0_MASK                                (0x0000000fU)

#define RTCSS_DAYS_REG_DAY1_SHIFT                               (4U)
#define RTCSS_DAYS_REG_DAY1_MASK                                (0x00000030U)

#define RTCSS_ALARM_DAYS_REG_DAY0_SHIFT                         (0U)
#define RTCSS_ALARM_DAYS_REG_DAY0_MASK                          (0x0000000fU)

#define RTCSS_ALARM_DAYS_REG_DAY1_SHIFT                         (4U)
#define RTCSS_ALARM_DAYS_REG_DAY1_MASK                          (0x00000030U)

#define RTCSS_SCRATCH1_REG_RTCSCRATCH1_SHIFT                    (0U)
#define RTCSS_SCRATCH1_REG_RTCSCRATCH1_MASK                     (0xffffffffU)

#define RTCSS_DEBOUNCE_REG_SHIFT                                (0U)
#define RTCSS_DEBOUNCE_REG_MASK                                 (0x000000ffU)
#define RTCSS_DEBOUNCE_REG_TIME                                  (0U)

#define RTCSS_ALARM2_YEARS_REG_YEAR0_SHIFT                      (0U)
#define RTCSS_ALARM2_YEARS_REG_YEAR0_MASK                       (0x0000000fU)

#define RTCSS_ALARM2_YEARS_REG_YEAR1_SHIFT                      (4U)
#define RTCSS_ALARM2_YEARS_REG_YEAR1_MASK                       (0x000000f0U)

#define RTCSS_MINUTES_REG_MIN0_SHIFT                            (0U)
#define RTCSS_MINUTES_REG_MIN0_MASK                             (0x0000000fU)

#define RTCSS_MINUTES_REG_MIN1_SHIFT                            (4U)
#define RTCSS_MINUTES_REG_MIN1_MASK                             (0x00000070U)

#define RTCSS_ALARM_MINUTES_REG_MIN0_SHIFT                      (0U)
#define RTCSS_ALARM_MINUTES_REG_MIN0_MASK                       (0x0000000fU)

#define RTCSS_ALARM_MINUTES_REG_MIN1_SHIFT                      (4U)
#define RTCSS_ALARM_MINUTES_REG_MIN1_MASK                       (0x00000070U)

#define RTCSS_HOURS_REG_HOUR0_SHIFT                             (0U)
#define RTCSS_HOURS_REG_HOUR0_MASK                              (0x0000000fU)

#define RTCSS_HOURS_REG_HOUR1_SHIFT                             (4U)
#define RTCSS_HOURS_REG_HOUR1_MASK                              (0x00000030U)

#define RTCSS_HOURS_REG_PM_NAM_SHIFT                            (7U)
#define RTCSS_HOURS_REG_PM_NAM_MASK                             (0x00000080U)
#define RTCSS_HOURS_REG_PM_NAM_MODE                              (1U)
#define RTCSS_HOURS_REG_PM_NAM_AM_MODE                           (0U)

#define RTCSS_ALARM2_MONTHS_REG_MONTH0_SHIFT                    (0U)
#define RTCSS_ALARM2_MONTHS_REG_MONTH0_MASK                     (0x0000000fU)

#define RTCSS_ALARM2_MONTHS_REG_MONTH1_SHIFT                    (4U)
#define RTCSS_ALARM2_MONTHS_REG_MONTH1_MASK                     (0x00000010U)

#define RTCSS_ALARM_HOURS_REG_HOUR0_SHIFT                       (0U)
#define RTCSS_ALARM_HOURS_REG_HOUR0_MASK                        (0x0000000fU)

#define RTCSS_ALARM_HOURS_REG_HOUR1_SHIFT                       (4U)
#define RTCSS_ALARM_HOURS_REG_HOUR1_MASK                        (0x00000030U)

#define RTCSS_ALARM_HOURS_REG_PM_NAM_SHIFT                      (7U)
#define RTCSS_ALARM_HOURS_REG_PM_NAM_MASK                       (0x00000080U)
#define RTCSS_ALARM_HOURS_REG_PM_NAM_MODE                        (1U)
#define RTCSS_ALARM_HOURS_REG_PM_NAM_AM_MODE                     (0U)

#define RTCSS_ALARM2_MINUTES_REG_MIN0_SHIFT                     (0U)
#define RTCSS_ALARM2_MINUTES_REG_MIN0_MASK                      (0x0000000fU)

#define RTCSS_ALARM2_MINUTES_REG_MIN1_SHIFT                     (4U)
#define RTCSS_ALARM2_MINUTES_REG_MIN1_MASK                      (0x00000070U)

#define RTCSS_PMIC_EXT_WAKEUP_EN_SHIFT                          (0U)
#define RTCSS_PMIC_EXT_WAKEUP_EN_MASK                           (0x0000000fU)
#define RTCSS_PMIC_EXT_WAKEUP_EN_ENABLED                         (1U)
#define RTCSS_PMIC_EXT_WAKEUP_EN_DISABLED                        (0U)

#define RTCSS_PMIC_EXT_WAKEUP_POL_SHIFT                         (4U)
#define RTCSS_PMIC_EXT_WAKEUP_POL_MASK                          (0x000000f0U)
#define RTCSS_PMIC_EXT_WAKEUP_POL_ACTIVE_HIGH                    (0U)
#define RTCSS_PMIC_EXT_WAKEUP_POL_ACTIVE_LOW                     (1U)

#define RTCSS_PMIC_EXT_WAKEUP_DB_EN_SHIFT                       (8U)
#define RTCSS_PMIC_EXT_WAKEUP_DB_EN_MASK                        (0x00000f00U)
#define RTCSS_PMIC_EXT_WAKEUP_DB_EN_DISABLE                      (0U)
#define RTCSS_PMIC_EXT_WAKEUP_DB_EN_ENABLE                       (1U)

#define RTCSS_PMIC_EXT_WAKEUP_STS_SHIFT                         (12U)
#define RTCSS_PMIC_EXT_WAKEUP_STS_MASK                          (0x0000f000U)
#define RTCSS_PMIC_EXT_WAKEUP_STS_NOT_OCCURRED                   (0U)
#define RTCSS_PMIC_EXT_WAKEUP_STS_OCCURED                        (1U)

#define RTCSS_PMIC_PWR_EN_SHIFT                                 (16U)
#define RTCSS_PMIC_PWR_EN_MASK                                  (0x00010000U)
#define RTCSS_PMIC_PWR_EN_DISABLE                                (0U)
#define RTCSS_PMIC_PWR_EN_ENABLE                                 (1U)

#define RTCSS_PMIC_PWR_EN_SM_SHIFT                              (17U)
#define RTCSS_PMIC_PWR_EN_SM_MASK                               (0x00060000U)
#define RTCSS_PMIC_PWR_EN_SM_IDLE                                (0U)
#define RTCSS_PMIC_PWR_EN_SM_SHUTDOWN                            (1U)
#define RTCSS_PMIC_PWR_EN_SM_EXT_WAKEUP                          (17U)
#define RTCSS_PMIC_PWR_EN_SM_TIME_WAKEUP                         (16U)

#define RTCSS_OSC_REG_SW1_SHIFT                                 (0U)
#define RTCSS_OSC_REG_SW1_MASK                                  (0x00000001U)

#define RTCSS_OSC_REG_SW2_SHIFT                                 (1U)
#define RTCSS_OSC_REG_SW2_MASK                                  (0x00000002U)

#define RTCSS_OSC_REG_RES_SELECT_SHIFT                          (2U)
#define RTCSS_OSC_REG_RES_SELECT_MASK                           (0x00000004U)
#define RTCSS_OSC_REG_RES_SELECT_INTERNAL                        (0U)
#define RTCSS_OSC_REG_RES_SELECT_EXTERNAL                        (1U)

#define RTCSS_OSC_REG_OSC32K_GZ_SHIFT                           (4U)
#define RTCSS_OSC_REG_OSC32K_GZ_MASK                            (0x00000010U)
#define RTCSS_OSC_REG_OSC32K_GZ_ENABLE                           (0U)
#define RTCSS_OSC_REG_OSC32K_GZ_DISABLE                          (1U)

#define RTCSS_OSC_REG_32KCLK_SEL_SHIFT                          (3U)
#define RTCSS_OSC_REG_32KCLK_SEL_MASK                           (0x00000008U)
#define RTCSS_OSC_REG_32KCLK_SEL_INTERNAL                        (0U)
#define RTCSS_OSC_REG_32KCLK_SEL_EXTERNAL                        (1U)

#define RTCSS_OSC_REG_32KCLK_EN_SHIFT                           (6U)
#define RTCSS_OSC_REG_32KCLK_EN_MASK                            (0x00000040U)
#define RTCSS_OSC_REG_32KCLK_EN_ENABLE                           (1U)
#define RTCSS_OSC_REG_32KCLK_EN_DISABLE                          (0U)

#define RTCSS_ALARM_YEARS_REG_YEAR0_SHIFT                       (0U)
#define RTCSS_ALARM_YEARS_REG_YEAR0_MASK                        (0x0000000fU)

#define RTCSS_ALARM_YEARS_REG_YEAR1_SHIFT                       (4U)
#define RTCSS_ALARM_YEARS_REG_YEAR1_MASK                        (0x000000f0U)

#define RTCSS_IRQWAKEEN_TIMER_WAKEEN_SHIFT                      (0U)
#define RTCSS_IRQWAKEEN_TIMER_WAKEEN_MASK                       (0x00000001U)
#define RTCSS_IRQWAKEEN_TIMER_WAKEEN_ENABLED                     (1U)
#define RTCSS_IRQWAKEEN_TIMER_WAKEEN_DISABLED                    (0U)

#define RTCSS_IRQWAKEEN_ALARM_WAKEEN_SHIFT                      (1U)
#define RTCSS_IRQWAKEEN_ALARM_WAKEEN_MASK                       (0x00000002U)
#define RTCSS_IRQWAKEEN_ALARM_WAKEEN_ENABLED                     (1U)
#define RTCSS_IRQWAKEEN_ALARM_WAKEEN_DISABLED                    (0U)

#define RTCSS_ALARM2_DAYS_REG_DAY0_SHIFT                        (0U)
#define RTCSS_ALARM2_DAYS_REG_DAY0_MASK                         (0x0000000fU)

#define RTCSS_ALARM2_DAYS_REG_DAY1_SHIFT                        (4U)
#define RTCSS_ALARM2_DAYS_REG_DAY1_MASK                         (0x00000030U)

#define RTCSS_COMP_MSB_REG_RTC_SHIFT                            (0U)
#define RTCSS_COMP_MSB_REG_RTC_MASK                             (0x000000ffU)

#define RTCSS_SCRATCH0_REG_RTCSCRATCH0_SHIFT                    (0U)
#define RTCSS_SCRATCH0_REG_RTCSCRATCH0_MASK                     (0xffffffffU)

#define RTCSS_YEARS_REG_YEAR0_SHIFT                             (0U)
#define RTCSS_YEARS_REG_YEAR0_MASK                              (0x0000000fU)

#define RTCSS_YEARS_REG_YEAR1_SHIFT                             (4U)
#define RTCSS_YEARS_REG_YEAR1_MASK                              (0x000000f0U)

#define RTCSS_KICK1R_KICK1_SHIFT                                (0U)
#define RTCSS_KICK1R_KICK1_MASK                                 (0xffffffffU)

#define RTCSS_INTRS_REG_EVERY_SHIFT                             (0U)
#define RTCSS_INTRS_REG_EVERY_MASK                              (0x00000003U)
#define RTCSS_INTRS_REG_EVERY_MIN                                (1U)
#define RTCSS_INTRS_REG_EVERY_DAY                                (3U)
#define RTCSS_INTRS_REG_EVERY_SEC                                (0U)
#define RTCSS_INTRS_REG_EVERY_HOUR                               (2U)

#define RTCSS_INTRS_REG_IT_TIMER_SHIFT                          (2U)
#define RTCSS_INTRS_REG_IT_TIMER_MASK                           (0x00000004U)
#define RTCSS_INTRS_REG_IT_TIMER_DISABLED                        (0U)
#define RTCSS_INTRS_REG_IT_TIMER_ENABLED                         (1U)

#define RTCSS_INTRS_REG_IT_ALARM_SHIFT                          (3U)
#define RTCSS_INTRS_REG_IT_ALARM_MASK                           (0x00000008U)
#define RTCSS_INTRS_REG_IT_ALARM_DISABLED                        (0U)
#define RTCSS_INTRS_REG_IT_ALARM_ENABLED                         (1U)

#define RTCSS_INTRS_REG_IT_ALARM2_SHIFT                         (4U)
#define RTCSS_INTRS_REG_IT_ALARM2_MASK                          (0x00000010U)
#define RTCSS_INTRS_REG_IT_ALARM2_DISABLED                       (0U)
#define RTCSS_INTRS_REG_IT_ALARM2_ENABLED                        (1U)

#define RTCSS_KICK0R_KICK0_SHIFT                                (0U)
#define RTCSS_KICK0R_KICK0_MASK                                 (0xffffffffU)

#define RTCSS_ALARM2_HOURS_REG_HOUR0_SHIFT                      (0U)
#define RTCSS_ALARM2_HOURS_REG_HOUR0_MASK                       (0x0000000fU)

#define RTCSS_ALARM2_HOURS_REG_HOUR1_SHIFT                      (4U)
#define RTCSS_ALARM2_HOURS_REG_HOUR1_MASK                       (0x00000030U)

#define RTCSS_ALARM2_HOURS_REG_PM_NAM_SHIFT                     (7U)
#define RTCSS_ALARM2_HOURS_REG_PM_NAM_MASK                      (0x00000080U)
#define RTCSS_ALARM2_HOURS_REG_PM_NAM_MODE                       (1U)
#define RTCSS_ALARM2_HOURS_REG_PM_NAM_AM_MODE                    (0U)

#define RTCSS_REVISION_Y_MINOR_SHIFT                            (0U)
#define RTCSS_REVISION_Y_MINOR_MASK                             (0x0000003fU)

#define RTCSS_REVISION_CUSTOM_SHIFT                             (6U)
#define RTCSS_REVISION_CUSTOM_MASK                              (0x000000c0U)

#define RTCSS_REVISION_X_MAJOR_SHIFT                            (8U)
#define RTCSS_REVISION_X_MAJOR_MASK                             (0x00000700U)

#define RTCSS_REVISION_R_RTL_SHIFT                              (11U)
#define RTCSS_REVISION_R_RTL_MASK                               (0x0000f800U)

#define RTCSS_REVISION_FUNC_SHIFT                               (16U)
#define RTCSS_REVISION_FUNC_MASK                                (0x0fff0000U)

#define RTCSS_REVISION_SCHEME_SHIFT                             (30U)
#define RTCSS_REVISION_SCHEME_MASK                              (0xc0000000U)

#define RTCSS_STS_REG_BUSY_SHIFT                                (0U)
#define RTCSS_STS_REG_BUSY_MASK                                 (0x00000001U)
#define RTCSS_STS_REG_BUSY_UPDATE_EVT                            (1U)
#define RTCSS_STS_REG_BUSY_UPDATE_EVT_15                         (0U)

#define RTCSS_STS_REG_RUN_SHIFT                                 (1U)
#define RTCSS_STS_REG_RUN_MASK                                  (0x00000002U)
#define RTCSS_STS_REG_RUN_FROZEN                                 (0U)
#define RTCSS_STS_REG_RUN_RUNNING                                (1U)

#define RTCSS_STS_REG_ALARM_SHIFT                               (6U)
#define RTCSS_STS_REG_ALARM_MASK                                (0x00000040U)

#define RTCSS_STS_REG_ALARM2_SHIFT                              (7U)
#define RTCSS_STS_REG_ALARM2_MASK                               (0x00000080U)

#define RTCSS_STS_REG_1S_EVT_SHIFT                              (2U)
#define RTCSS_STS_REG_1S_EVT_MASK                               (0x00000004U)

#define RTCSS_STS_REG_1M_EVT_SHIFT                              (3U)
#define RTCSS_STS_REG_1M_EVT_MASK                               (0x00000008U)

#define RTCSS_STS_REG_1H_EVT_SHIFT                              (4U)
#define RTCSS_STS_REG_1H_EVT_MASK                               (0x00000010U)

#define RTCSS_STS_REG_1D_EVT_SHIFT                              (5U)
#define RTCSS_STS_REG_1D_EVT_MASK                               (0x00000020U)

#define RTCSS_COMP_LSB_REG_RTC_SHIFT                            (0U)
#define RTCSS_COMP_LSB_REG_RTC_MASK                             (0x000000ffU)

#define RTCSS_ALARM_SECONDS_REG_ALARMSEC0_SHIFT                 (0U)
#define RTCSS_ALARM_SECONDS_REG_ALARMSEC0_MASK                  (0x0000000fU)

#define RTCSS_ALARM_SECONDS_REG_ALARMSEC1_SHIFT                 (4U)
#define RTCSS_ALARM_SECONDS_REG_ALARMSEC1_MASK                  (0x00000070U)

#define RTCSS_SCRATCH2_REG_RTCSCRATCH2_SHIFT                    (0U)
#define RTCSS_SCRATCH2_REG_RTCSCRATCH2_MASK                     (0xffffffffU)

#ifdef __cplusplus
}
#endif

#endif /* HW_RTC_H_ */
