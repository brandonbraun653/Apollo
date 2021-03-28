/********************************************************************
 * Copyright (C) 2013-2014 Texas Instruments Incorporated.
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
#ifndef CSLR_RTC_H_
#define CSLR_RTC_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>


/**************************************************************************
* Register Overlay Structure for __ALL__
**************************************************************************/
typedef struct {
    volatile Uint32 SECONDS;
    volatile Uint32 MINUTES;
    volatile Uint32 HOURS;
    volatile Uint32 DAYS;
    volatile Uint32 MONTHS;
    volatile Uint32 YEARS;
    volatile Uint32 WEEKS;
    volatile Uint8  RSVD0[4];
    volatile Uint32 ALARM_SECONDS;
    volatile Uint32 ALARM_MINUTES;
    volatile Uint32 ALARM_HOURS;
    volatile Uint32 ALARM_DAYS;
    volatile Uint32 ALARM_MONTHS;
    volatile Uint32 ALARM_YEARS;
    volatile Uint8  RSVD1[8];
    volatile Uint32 CTRL;
    volatile Uint32 STS;
    volatile Uint32 INTRS;
    volatile Uint32 COMP_LSB;
    volatile Uint32 COMP_MSB;
    volatile Uint32 OSC;
    volatile Uint8  RSVD2[8];
    volatile Uint32 SCRATCH0;
    volatile Uint32 SCRATCH1;
    volatile Uint32 SCRATCH2;
    volatile Uint32 KICK0;
    volatile Uint32 KICK1;
    volatile Uint32 REVISION;
    volatile Uint32 SYSCONFIG;
    volatile Uint32 IRQWAKEEN;
    volatile Uint32 ALARM2_SECONDS;
    volatile Uint32 ALARM2_MINUTES;
    volatile Uint32 ALARM2_HOURS;
    volatile Uint32 ALARM2_DAYS;
    volatile Uint32 ALARM2_MONTHS;
    volatile Uint32 ALARM2_YEARS;
    volatile Uint32 RTC_PMIC_REG;
    volatile Uint32 RTL_DEBOUNCE;
} CSL_RtcRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

/* SECONDS */
#define CSL_RTC_SECONDS                                         ((uint32_t)(0x0U))

/* MINUTES */
#define CSL_RTC_MINUTES                                         ((uint32_t)(0x4U))

/* HOURS */
#define CSL_RTC_HOURS                                           ((uint32_t)(0x8U))

/* DAYS */
#define CSL_RTC_DAYS                                            ((uint32_t)(0xCU))

/* MONTHS */
#define CSL_RTC_MONTHS                                          ((uint32_t)(0x10U))

/* YEARS */
#define CSL_RTC_YEARS                                           ((uint32_t)(0x14U))

/* WEEKS */
#define CSL_RTC_WEEKS                                           ((uint32_t)(0x18U))

/* ALARM_SECONDS */
#define CSL_RTC_ALARM_SECONDS                                   ((uint32_t)(0x20U))

/* ALARM_MINUTES */
#define CSL_RTC_ALARM_MINUTES                                   ((uint32_t)(0x24U))

/* ALARM_HOURS */
#define CSL_RTC_ALARM_HOURS                                     ((uint32_t)(0x28U))

/* ALARM_DAYS */
#define CSL_RTC_ALARM_DAYS                                      ((uint32_t)(0x2CU))

/* ALARM_MONTHS */
#define CSL_RTC_ALARM_MONTHS                                    ((uint32_t)(0x30U))

/* ALARM_YEARS */
#define CSL_RTC_ALARM_YEARS                                     ((uint32_t)(0x34U))

/* CTRL */
#define CSL_RTC_CTRL                                            ((uint32_t)(0x40U))

/* STS */
#define CSL_RTC_STS                                             ((uint32_t)(0x44U))

/* INTRS */
#define CSL_RTC_INTRS                                           ((uint32_t)(0x48U))

/* COMP_LSB */
#define CSL_RTC_COMP_LSB                                        ((uint32_t)(0x4CU))

/* COMP_MSB */
#define CSL_RTC_COMP_MSB                                        ((uint32_t)(0x50U))

/* OSC */
#define CSL_RTC_OSC                                             ((uint32_t)(0x54U))

/* SCRATCH0 */
#define CSL_RTC_SCRATCH0                                        ((uint32_t)(0x60U))

/* SCRATCH1 */
#define CSL_RTC_SCRATCH1                                        ((uint32_t)(0x64U))

/* SCRATCH2 */
#define CSL_RTC_SCRATCH2                                        ((uint32_t)(0x68U))

/* Kick0 data */
#define CSL_RTC_KICK0                                           ((uint32_t)(0x6CU))

/* Kick1 data */
#define CSL_RTC_KICK1                                           ((uint32_t)(0x70U))

/* REVISION */
#define CSL_RTC_REVISION                                        ((uint32_t)(0x74U))

/* SYSCONFIG */
#define CSL_RTC_SYSCONFIG                                       ((uint32_t)(0x78U))

/* IRQWAKEEN */
#define CSL_RTC_IRQWAKEEN                                       ((uint32_t)(0x7CU))

/* The ALARM2_SECONDS_REG is used to program the seconds value of the ALARM2
 * time */
#define CSL_RTC_ALARM2_SECONDS                                  ((uint32_t)(0x80U))

/* ALARM2_MINUTES */
#define CSL_RTC_ALARM2_MINUTES                                  ((uint32_t)(0x84U))

/* ALARM2_HOURS */
#define CSL_RTC_ALARM2_HOURS                                    ((uint32_t)(0x88U))

/* ALARM2_DAYS */
#define CSL_RTC_ALARM2_DAYS                                     ((uint32_t)(0x8CU))

/* ALARM2_MONTHS */
#define CSL_RTC_ALARM2_MONTHS                                   ((uint32_t)(0x90U))

/* ALARM2_YEARS */
#define CSL_RTC_ALARM2_YEARS                                    ((uint32_t)(0x94U))

/* RTC_PMIC_REG */
#define CSL_RTC_RTC_PMIC_REG                                    ((uint32_t)(0x98U))

/* RTL_DEBOUNCE */
#define CSL_RTC_RTL_DEBOUNCE                                    ((uint32_t)(0x9CU))


/**************************************************************************
* Field Definition Macros
**************************************************************************/

/* SECONDS */

#define CSL_RTC_SECONDS_SEC0_MASK                               ((uint32_t)(0x0000000FU))
#define CSL_RTC_SECONDS_SEC0_SHIFT                              ((uint32_t)(0U))
#define CSL_RTC_SECONDS_SEC0_RESETVAL                           ((uint32_t)(0x00000000U))
#define CSL_RTC_SECONDS_SEC0_MAX                                ((uint32_t)(0x0000000fU))

#define CSL_RTC_SECONDS_SEC1_MASK                               ((uint32_t)(0x00000070U))
#define CSL_RTC_SECONDS_SEC1_SHIFT                              ((uint32_t)(4U))
#define CSL_RTC_SECONDS_SEC1_RESETVAL                           ((uint32_t)(0x00000000U))
#define CSL_RTC_SECONDS_SEC1_MAX                                ((uint32_t)(0x00000007U))

#define CSL_RTC_SECONDS_RESETVAL                                ((uint32_t)(0x00000000U))

/* MINUTES */

#define CSL_RTC_MINUTES_MIN0_MASK                               ((uint32_t)(0x0000000FU))
#define CSL_RTC_MINUTES_MIN0_SHIFT                              ((uint32_t)(0U))
#define CSL_RTC_MINUTES_MIN0_RESETVAL                           ((uint32_t)(0x00000000U))
#define CSL_RTC_MINUTES_MIN0_MAX                                ((uint32_t)(0x0000000fU))

#define CSL_RTC_MINUTES_MIN1_MASK                               ((uint32_t)(0x00000070U))
#define CSL_RTC_MINUTES_MIN1_SHIFT                              ((uint32_t)(4U))
#define CSL_RTC_MINUTES_MIN1_RESETVAL                           ((uint32_t)(0x00000000U))
#define CSL_RTC_MINUTES_MIN1_MAX                                ((uint32_t)(0x00000007U))

#define CSL_RTC_MINUTES_RESETVAL                                ((uint32_t)(0x00000000U))

/* HOURS */

#define CSL_RTC_HOURS_HOUR0_MASK                                ((uint32_t)(0x0000000FU))
#define CSL_RTC_HOURS_HOUR0_SHIFT                               ((uint32_t)(0U))
#define CSL_RTC_HOURS_HOUR0_RESETVAL                            ((uint32_t)(0x00000000U))
#define CSL_RTC_HOURS_HOUR0_MAX                                 ((uint32_t)(0x0000000fU))

#define CSL_RTC_HOURS_HOUR1_MASK                                ((uint32_t)(0x00000030U))
#define CSL_RTC_HOURS_HOUR1_SHIFT                               ((uint32_t)(4U))
#define CSL_RTC_HOURS_HOUR1_RESETVAL                            ((uint32_t)(0x00000000U))
#define CSL_RTC_HOURS_HOUR1_MAX                                 ((uint32_t)(0x00000003U))

#define CSL_RTC_HOURS_PM_NAM_MASK                               ((uint32_t)(0x00000080U))
#define CSL_RTC_HOURS_PM_NAM_SHIFT                              ((uint32_t)(7U))
#define CSL_RTC_HOURS_PM_NAM_RESETVAL                           ((uint32_t)(0x00000000U))
#define CSL_RTC_HOURS_PM_NAM_MAX                                ((uint32_t)(0x00000001U))

#define CSL_RTC_HOURS_RESETVAL                                  ((uint32_t)(0x00000000U))

/* DAYS */

#define CSL_RTC_DAYS_DAY0_MASK                                  ((uint32_t)(0x0000000FU))
#define CSL_RTC_DAYS_DAY0_SHIFT                                 ((uint32_t)(0U))
#define CSL_RTC_DAYS_DAY0_RESETVAL                              ((uint32_t)(0x00000001U))
#define CSL_RTC_DAYS_DAY0_MAX                                   ((uint32_t)(0x0000000fU))

#define CSL_RTC_DAYS_DAY1_MASK                                  ((uint32_t)(0x00000030U))
#define CSL_RTC_DAYS_DAY1_SHIFT                                 ((uint32_t)(4U))
#define CSL_RTC_DAYS_DAY1_RESETVAL                              ((uint32_t)(0x00000000U))
#define CSL_RTC_DAYS_DAY1_MAX                                   ((uint32_t)(0x00000003U))

#define CSL_RTC_DAYS_RESETVAL                                   ((uint32_t)(0x00000001U))

/* MONTHS */

#define CSL_RTC_MONTHS_MONTH0_MASK                              ((uint32_t)(0x0000000FU))
#define CSL_RTC_MONTHS_MONTH0_SHIFT                             ((uint32_t)(0U))
#define CSL_RTC_MONTHS_MONTH0_RESETVAL                          ((uint32_t)(0x00000001U))
#define CSL_RTC_MONTHS_MONTH0_MAX                               ((uint32_t)(0x0000000fU))

#define CSL_RTC_MONTHS_MONTH1_MASK                              ((uint32_t)(0x00000010U))
#define CSL_RTC_MONTHS_MONTH1_SHIFT                             ((uint32_t)(4U))
#define CSL_RTC_MONTHS_MONTH1_RESETVAL                          ((uint32_t)(0x00000000U))
#define CSL_RTC_MONTHS_MONTH1_MAX                               ((uint32_t)(0x00000001U))

#define CSL_RTC_MONTHS_RESETVAL                                 ((uint32_t)(0x00000001U))

/* YEARS */

#define CSL_RTC_YEARS_YEAR0_MASK                                ((uint32_t)(0x0000000FU))
#define CSL_RTC_YEARS_YEAR0_SHIFT                               ((uint32_t)(0U))
#define CSL_RTC_YEARS_YEAR0_RESETVAL                            ((uint32_t)(0x00000000U))
#define CSL_RTC_YEARS_YEAR0_MAX                                 ((uint32_t)(0x0000000fU))

#define CSL_RTC_YEARS_YEAR1_MASK                                ((uint32_t)(0x000000F0U))
#define CSL_RTC_YEARS_YEAR1_SHIFT                               ((uint32_t)(4U))
#define CSL_RTC_YEARS_YEAR1_RESETVAL                            ((uint32_t)(0x00000000U))
#define CSL_RTC_YEARS_YEAR1_MAX                                 ((uint32_t)(0x0000000fU))

#define CSL_RTC_YEARS_RESETVAL                                  ((uint32_t)(0x00000000U))

/* WEEKS */

#define CSL_RTC_WEEKS_WEEK_MASK                                 ((uint32_t)(0x00000007U))
#define CSL_RTC_WEEKS_WEEK_SHIFT                                ((uint32_t)(0U))
#define CSL_RTC_WEEKS_WEEK_RESETVAL                             ((uint32_t)(0x00000000U))
#define CSL_RTC_WEEKS_WEEK_MAX                                  ((uint32_t)(0x00000007U))

#define CSL_RTC_WEEKS_RESETVAL                                  ((uint32_t)(0x00000000U))

/* ALARM_SECONDS */

#define CSL_RTC_ALARM_SECONDS_ALARM_SEC0_MASK                   ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM_SECONDS_ALARM_SEC0_SHIFT                  ((uint32_t)(0U))
#define CSL_RTC_ALARM_SECONDS_ALARM_SEC0_RESETVAL               ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_SECONDS_ALARM_SEC0_MAX                    ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM_SECONDS_ALARM_SEC1_MASK                   ((uint32_t)(0x00000070U))
#define CSL_RTC_ALARM_SECONDS_ALARM_SEC1_SHIFT                  ((uint32_t)(4U))
#define CSL_RTC_ALARM_SECONDS_ALARM_SEC1_RESETVAL               ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_SECONDS_ALARM_SEC1_MAX                    ((uint32_t)(0x00000007U))

#define CSL_RTC_ALARM_SECONDS_RESETVAL                          ((uint32_t)(0x00000000U))

/* ALARM_MINUTES */

#define CSL_RTC_ALARM_MINUTES_ALARM_MIN0_MASK                   ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM_MINUTES_ALARM_MIN0_SHIFT                  ((uint32_t)(0U))
#define CSL_RTC_ALARM_MINUTES_ALARM_MIN0_RESETVAL               ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_MINUTES_ALARM_MIN0_MAX                    ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM_MINUTES_ALARM_MIN1_MASK                   ((uint32_t)(0x00000070U))
#define CSL_RTC_ALARM_MINUTES_ALARM_MIN1_SHIFT                  ((uint32_t)(4U))
#define CSL_RTC_ALARM_MINUTES_ALARM_MIN1_RESETVAL               ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_MINUTES_ALARM_MIN1_MAX                    ((uint32_t)(0x00000007U))

#define CSL_RTC_ALARM_MINUTES_RESETVAL                          ((uint32_t)(0x00000000U))

/* ALARM_HOURS */

#define CSL_RTC_ALARM_HOURS_ALARM_HOUR0_MASK                    ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM_HOURS_ALARM_HOUR0_SHIFT                   ((uint32_t)(0U))
#define CSL_RTC_ALARM_HOURS_ALARM_HOUR0_RESETVAL                ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_HOURS_ALARM_HOUR0_MAX                     ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM_HOURS_ALARM_HOUR1_MASK                    ((uint32_t)(0x00000030U))
#define CSL_RTC_ALARM_HOURS_ALARM_HOUR1_SHIFT                   ((uint32_t)(4U))
#define CSL_RTC_ALARM_HOURS_ALARM_HOUR1_RESETVAL                ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_HOURS_ALARM_HOUR1_MAX                     ((uint32_t)(0x00000003U))

#define CSL_RTC_ALARM_HOURS_ALARM_PM_NAM_MASK                   ((uint32_t)(0x00000080U))
#define CSL_RTC_ALARM_HOURS_ALARM_PM_NAM_SHIFT                  ((uint32_t)(7U))
#define CSL_RTC_ALARM_HOURS_ALARM_PM_NAM_RESETVAL               ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_HOURS_ALARM_PM_NAM_MAX                    ((uint32_t)(0x00000001U))

#define CSL_RTC_ALARM_HOURS_RESETVAL                            ((uint32_t)(0x00000000U))

/* ALARM_DAYS */

#define CSL_RTC_ALARM_DAYS_ALARM_DAY0_MASK                      ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM_DAYS_ALARM_DAY0_SHIFT                     ((uint32_t)(0U))
#define CSL_RTC_ALARM_DAYS_ALARM_DAY0_RESETVAL                  ((uint32_t)(0x00000001U))
#define CSL_RTC_ALARM_DAYS_ALARM_DAY0_MAX                       ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM_DAYS_ALARM_DAY1_MASK                      ((uint32_t)(0x00000030U))
#define CSL_RTC_ALARM_DAYS_ALARM_DAY1_SHIFT                     ((uint32_t)(4U))
#define CSL_RTC_ALARM_DAYS_ALARM_DAY1_RESETVAL                  ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_DAYS_ALARM_DAY1_MAX                       ((uint32_t)(0x00000003U))

#define CSL_RTC_ALARM_DAYS_RESETVAL                             ((uint32_t)(0x00000001U))

/* ALARM_MONTHS */

#define CSL_RTC_ALARM_MONTHS_ALARM_MONTH0_MASK                  ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM_MONTHS_ALARM_MONTH0_SHIFT                 ((uint32_t)(0U))
#define CSL_RTC_ALARM_MONTHS_ALARM_MONTH0_RESETVAL              ((uint32_t)(0x00000001U))
#define CSL_RTC_ALARM_MONTHS_ALARM_MONTH0_MAX                   ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM_MONTHS_ALARM_MONTH1_MASK                  ((uint32_t)(0x00000010U))
#define CSL_RTC_ALARM_MONTHS_ALARM_MONTH1_SHIFT                 ((uint32_t)(4U))
#define CSL_RTC_ALARM_MONTHS_ALARM_MONTH1_RESETVAL              ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_MONTHS_ALARM_MONTH1_MAX                   ((uint32_t)(0x00000001U))

#define CSL_RTC_ALARM_MONTHS_RESETVAL                           ((uint32_t)(0x00000001U))

/* ALARM_YEARS */

#define CSL_RTC_ALARM_YEARS_ALARM_YEAR0_MASK                    ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM_YEARS_ALARM_YEAR0_SHIFT                   ((uint32_t)(0U))
#define CSL_RTC_ALARM_YEARS_ALARM_YEAR0_RESETVAL                ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_YEARS_ALARM_YEAR0_MAX                     ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM_YEARS_ALARM_YEAR1_MASK                    ((uint32_t)(0x000000F0U))
#define CSL_RTC_ALARM_YEARS_ALARM_YEAR1_SHIFT                   ((uint32_t)(4U))
#define CSL_RTC_ALARM_YEARS_ALARM_YEAR1_RESETVAL                ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM_YEARS_ALARM_YEAR1_MAX                     ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM_YEARS_RESETVAL                            ((uint32_t)(0x00000000U))

/* CTRL */

#define CSL_RTC_CTRL_STOP_RTC_MASK                              ((uint32_t)(0x00000001U))
#define CSL_RTC_CTRL_STOP_RTC_SHIFT                             ((uint32_t)(0U))
#define CSL_RTC_CTRL_STOP_RTC_RESETVAL                          ((uint32_t)(0x00000000U))
#define CSL_RTC_CTRL_STOP_RTC_MAX                               ((uint32_t)(0x00000001U))

#define CSL_RTC_CTRL_ROUND_30S_MASK                             ((uint32_t)(0x00000002U))
#define CSL_RTC_CTRL_ROUND_30S_SHIFT                            ((uint32_t)(1U))
#define CSL_RTC_CTRL_ROUND_30S_RESETVAL                         ((uint32_t)(0x00000000U))
#define CSL_RTC_CTRL_ROUND_30S_MAX                              ((uint32_t)(0x00000001U))

#define CSL_RTC_CTRL_AUTO_COMP_MASK                             ((uint32_t)(0x00000004U))
#define CSL_RTC_CTRL_AUTO_COMP_SHIFT                            ((uint32_t)(2U))
#define CSL_RTC_CTRL_AUTO_COMP_RESETVAL                         ((uint32_t)(0x00000000U))
#define CSL_RTC_CTRL_AUTO_COMP_MAX                              ((uint32_t)(0x00000001U))

#define CSL_RTC_CTRL_MODE_12_24_MASK                            ((uint32_t)(0x00000008U))
#define CSL_RTC_CTRL_MODE_12_24_SHIFT                           ((uint32_t)(3U))
#define CSL_RTC_CTRL_MODE_12_24_RESETVAL                        ((uint32_t)(0x00000000U))
#define CSL_RTC_CTRL_MODE_12_24_MAX                             ((uint32_t)(0x00000001U))

#define CSL_RTC_CTRL_TEST_MODE_MASK                             ((uint32_t)(0x00000010U))
#define CSL_RTC_CTRL_TEST_MODE_SHIFT                            ((uint32_t)(4U))
#define CSL_RTC_CTRL_TEST_MODE_RESETVAL                         ((uint32_t)(0x00000000U))
#define CSL_RTC_CTRL_TEST_MODE_MAX                              ((uint32_t)(0x00000001U))

#define CSL_RTC_CTRL_SET_32_CTR_MASK                            ((uint32_t)(0x00000020U))
#define CSL_RTC_CTRL_SET_32_CTR_SHIFT                           ((uint32_t)(5U))
#define CSL_RTC_CTRL_SET_32_CTR_RESETVAL                        ((uint32_t)(0x00000000U))
#define CSL_RTC_CTRL_SET_32_CTR_MAX                             ((uint32_t)(0x00000001U))

#define CSL_RTC_CTRL_RTC_DISABLE_MASK                           ((uint32_t)(0x00000040U))
#define CSL_RTC_CTRL_RTC_DISABLE_SHIFT                          ((uint32_t)(6U))
#define CSL_RTC_CTRL_RTC_DISABLE_RESETVAL                       ((uint32_t)(0x00000000U))
#define CSL_RTC_CTRL_RTC_DISABLE_MAX                            ((uint32_t)(0x00000001U))

#define CSL_RTC_CTRL_RESETVAL                                   ((uint32_t)(0x00000000U))

/* STS */

#define CSL_RTC_STS_BUSY_MASK                                   ((uint32_t)(0x00000001U))
#define CSL_RTC_STS_BUSY_SHIFT                                  ((uint32_t)(0U))
#define CSL_RTC_STS_BUSY_RESETVAL                               ((uint32_t)(0x00000000U))
#define CSL_RTC_STS_BUSY_MAX                                    ((uint32_t)(0x00000001U))

#define CSL_RTC_STS_RUN_MASK                                    ((uint32_t)(0x00000002U))
#define CSL_RTC_STS_RUN_SHIFT                                   ((uint32_t)(1U))
#define CSL_RTC_STS_RUN_RESETVAL                                ((uint32_t)(0x00000000U))
#define CSL_RTC_STS_RUN_MAX                                     ((uint32_t)(0x00000001U))

#define CSL_RTC_STS_EVT_1S_MASK                                 ((uint32_t)(0x00000004U))
#define CSL_RTC_STS_EVT_1S_SHIFT                                ((uint32_t)(2U))
#define CSL_RTC_STS_EVT_1S_RESETVAL                             ((uint32_t)(0x00000000U))
#define CSL_RTC_STS_EVT_1S_MAX                                  ((uint32_t)(0x00000001U))

#define CSL_RTC_STS_EVT_1M_MASK                                 ((uint32_t)(0x00000008U))
#define CSL_RTC_STS_EVT_1M_SHIFT                                ((uint32_t)(3U))
#define CSL_RTC_STS_EVT_1M_RESETVAL                             ((uint32_t)(0x00000000U))
#define CSL_RTC_STS_EVT_1M_MAX                                  ((uint32_t)(0x00000001U))

#define CSL_RTC_STS_EVT_1H_MASK                                 ((uint32_t)(0x00000010U))
#define CSL_RTC_STS_EVT_1H_SHIFT                                ((uint32_t)(4U))
#define CSL_RTC_STS_EVT_1H_RESETVAL                             ((uint32_t)(0x00000000U))
#define CSL_RTC_STS_EVT_1H_MAX                                  ((uint32_t)(0x00000001U))

#define CSL_RTC_STS_EVT_1D_MASK                                 ((uint32_t)(0x00000020U))
#define CSL_RTC_STS_EVT_1D_SHIFT                                ((uint32_t)(5U))
#define CSL_RTC_STS_EVT_1D_RESETVAL                             ((uint32_t)(0x00000000U))
#define CSL_RTC_STS_EVT_1D_MAX                                  ((uint32_t)(0x00000001U))

#define CSL_RTC_STS_ALARM_MASK                                  ((uint32_t)(0x00000040U))
#define CSL_RTC_STS_ALARM_SHIFT                                 ((uint32_t)(6U))
#define CSL_RTC_STS_ALARM_RESETVAL                              ((uint32_t)(0x00000000U))
#define CSL_RTC_STS_ALARM_MAX                                   ((uint32_t)(0x00000001U))

#define CSL_RTC_STS_ALARM2_MASK                                 ((uint32_t)(0x00000080U))
#define CSL_RTC_STS_ALARM2_SHIFT                                ((uint32_t)(7U))
#define CSL_RTC_STS_ALARM2_RESETVAL                             ((uint32_t)(0x00000000U))
#define CSL_RTC_STS_ALARM2_MAX                                  ((uint32_t)(0x00000001U))

#define CSL_RTC_STS_RESETVAL                                    ((uint32_t)(0x00000000U))

/* INTRS */

#define CSL_RTC_INTRS_EVERY_MASK                                ((uint32_t)(0x00000003U))
#define CSL_RTC_INTRS_EVERY_SHIFT                               ((uint32_t)(0U))
#define CSL_RTC_INTRS_EVERY_RESETVAL                            ((uint32_t)(0x00000000U))
#define CSL_RTC_INTRS_EVERY_MAX                                 ((uint32_t)(0x00000003U))

#define CSL_RTC_INTRS_IT_TIMER_MASK                             ((uint32_t)(0x00000004U))
#define CSL_RTC_INTRS_IT_TIMER_SHIFT                            ((uint32_t)(2U))
#define CSL_RTC_INTRS_IT_TIMER_RESETVAL                         ((uint32_t)(0x00000000U))
#define CSL_RTC_INTRS_IT_TIMER_MAX                              ((uint32_t)(0x00000001U))

#define CSL_RTC_INTRS_IT_ALARM_MASK                             ((uint32_t)(0x00000008U))
#define CSL_RTC_INTRS_IT_ALARM_SHIFT                            ((uint32_t)(3U))
#define CSL_RTC_INTRS_IT_ALARM_RESETVAL                         ((uint32_t)(0x00000000U))
#define CSL_RTC_INTRS_IT_ALARM_MAX                              ((uint32_t)(0x00000001U))

#define CSL_RTC_INTRS_IT_ALARM2_MASK                            ((uint32_t)(0x00000010U))
#define CSL_RTC_INTRS_IT_ALARM2_SHIFT                           ((uint32_t)(4U))
#define CSL_RTC_INTRS_IT_ALARM2_RESETVAL                        ((uint32_t)(0x00000000U))
#define CSL_RTC_INTRS_IT_ALARM2_MAX                             ((uint32_t)(0x00000001U))

#define CSL_RTC_INTRS_RESETVAL                                  ((uint32_t)(0x00000000U))

/* COMP_LSB */

#define CSL_RTC_COMP_LSB_RTC_COMP_LSB_MASK                      ((uint32_t)(0x000000FFU))
#define CSL_RTC_COMP_LSB_RTC_COMP_LSB_SHIFT                     ((uint32_t)(0U))
#define CSL_RTC_COMP_LSB_RTC_COMP_LSB_RESETVAL                  ((uint32_t)(0x00000000U))
#define CSL_RTC_COMP_LSB_RTC_COMP_LSB_MAX                       ((uint32_t)(0x000000ffU))

#define CSL_RTC_COMP_LSB_RESETVAL                               ((uint32_t)(0x00000000U))

/* COMP_MSB */

#define CSL_RTC_COMP_MSB_RTC_COMP_MSB_MASK                      ((uint32_t)(0x000000FFU))
#define CSL_RTC_COMP_MSB_RTC_COMP_MSB_SHIFT                     ((uint32_t)(0U))
#define CSL_RTC_COMP_MSB_RTC_COMP_MSB_RESETVAL                  ((uint32_t)(0x00000000U))
#define CSL_RTC_COMP_MSB_RTC_COMP_MSB_MAX                       ((uint32_t)(0x000000ffU))

#define CSL_RTC_COMP_MSB_RESETVAL                               ((uint32_t)(0x00000000U))

/* OSC */

#define CSL_RTC_OSC_OSC32K_GZ_MASK                              ((uint32_t)(0x00000010U))
#define CSL_RTC_OSC_OSC32K_GZ_SHIFT                             ((uint32_t)(4U))
#define CSL_RTC_OSC_OSC32K_GZ_RESETVAL                          ((uint32_t)(0x00000001U))
#define CSL_RTC_OSC_OSC32K_GZ_MAX                               ((uint32_t)(0x00000001U))

#define CSL_RTC_OSC_SW1_MASK                                    ((uint32_t)(0x00000001U))
#define CSL_RTC_OSC_SW1_SHIFT                                   ((uint32_t)(0U))
#define CSL_RTC_OSC_SW1_RESETVAL                                ((uint32_t)(0x00000000U))
#define CSL_RTC_OSC_SW1_MAX                                     ((uint32_t)(0x00000001U))

#define CSL_RTC_OSC_SW2_MASK                                    ((uint32_t)(0x00000002U))
#define CSL_RTC_OSC_SW2_SHIFT                                   ((uint32_t)(1U))
#define CSL_RTC_OSC_SW2_RESETVAL                                ((uint32_t)(0x00000001U))
#define CSL_RTC_OSC_SW2_MAX                                     ((uint32_t)(0x00000001U))

#define CSL_RTC_OSC_RES_SELECT_MASK                             ((uint32_t)(0x00000004U))
#define CSL_RTC_OSC_RES_SELECT_SHIFT                            ((uint32_t)(2U))
#define CSL_RTC_OSC_RES_SELECT_RESETVAL                         ((uint32_t)(0x00000000U))
#define CSL_RTC_OSC_RES_SELECT_MAX                              ((uint32_t)(0x00000001U))

#define CSL_RTC_OSC_K32CLK_SEL_MASK                             ((uint32_t)(0x00000008U))
#define CSL_RTC_OSC_K32CLK_SEL_SHIFT                            ((uint32_t)(3U))
#define CSL_RTC_OSC_K32CLK_SEL_RESETVAL                         ((uint32_t)(0x00000000U))
#define CSL_RTC_OSC_K32CLK_SEL_MAX                              ((uint32_t)(0x00000001U))

#define CSL_RTC_OSC_K32CLK_EN_MASK                              ((uint32_t)(0x00000040U))
#define CSL_RTC_OSC_K32CLK_EN_SHIFT                             ((uint32_t)(6U))
#define CSL_RTC_OSC_K32CLK_EN_RESETVAL                          ((uint32_t)(0x00000000U))
#define CSL_RTC_OSC_K32CLK_EN_MAX                               ((uint32_t)(0x00000001U))

#define CSL_RTC_OSC_RESETVAL                                    ((uint32_t)(0x00000012U))

/* SCRATCH0 */

#define CSL_RTC_SCRATCH0_RTCSCRATCH0_MASK                       ((uint32_t)(0xFFFFFFFFU))
#define CSL_RTC_SCRATCH0_RTCSCRATCH0_SHIFT                      ((uint32_t)(0U))
#define CSL_RTC_SCRATCH0_RTCSCRATCH0_RESETVAL                   ((uint32_t)(0x00000000U))
#define CSL_RTC_SCRATCH0_RTCSCRATCH0_MAX                        ((uint32_t)(0xffffffffU))

#define CSL_RTC_SCRATCH0_RESETVAL                               ((uint32_t)(0x00000000U))

/* SCRATCH1 */

#define CSL_RTC_SCRATCH1_RTCSCRATCH1_MASK                       ((uint32_t)(0xFFFFFFFFU))
#define CSL_RTC_SCRATCH1_RTCSCRATCH1_SHIFT                      ((uint32_t)(0U))
#define CSL_RTC_SCRATCH1_RTCSCRATCH1_RESETVAL                   ((uint32_t)(0x00000000U))
#define CSL_RTC_SCRATCH1_RTCSCRATCH1_MAX                        ((uint32_t)(0xffffffffU))

#define CSL_RTC_SCRATCH1_RESETVAL                               ((uint32_t)(0x00000000U))

/* SCRATCH2 */

#define CSL_RTC_SCRATCH2_RTCSCRATCH2_MASK                       ((uint32_t)(0xFFFFFFFFU))
#define CSL_RTC_SCRATCH2_RTCSCRATCH2_SHIFT                      ((uint32_t)(0U))
#define CSL_RTC_SCRATCH2_RTCSCRATCH2_RESETVAL                   ((uint32_t)(0x00000000U))
#define CSL_RTC_SCRATCH2_RTCSCRATCH2_MAX                        ((uint32_t)(0xffffffffU))

#define CSL_RTC_SCRATCH2_RESETVAL                               ((uint32_t)(0x00000000U))

/* KICK0 */

#define CSL_RTC_KICK0_KICK0_MASK                                ((uint32_t)(0xFFFFFFFFU))
#define CSL_RTC_KICK0_KICK0_SHIFT                               ((uint32_t)(0U))
#define CSL_RTC_KICK0_KICK0_RESETVAL                            ((uint32_t)(0x00000000U))
#define CSL_RTC_KICK0_KICK0_MAX                                 ((uint32_t)(0xffffffffU))

#define CSL_RTC_KICK0_RESETVAL                                  ((uint32_t)(0x00000000U))

/* KICK1 */

#define CSL_RTC_KICK1_KICK1_MASK                                ((uint32_t)(0xFFFFFFFFU))
#define CSL_RTC_KICK1_KICK1_SHIFT                               ((uint32_t)(0U))
#define CSL_RTC_KICK1_KICK1_RESETVAL                            ((uint32_t)(0x00000000U))
#define CSL_RTC_KICK1_KICK1_MAX                                 ((uint32_t)(0xffffffffU))

#define CSL_RTC_KICK1_RESETVAL                                  ((uint32_t)(0x00000000U))

/* REVISION */

#define CSL_RTC_REVISION_Y_MINOR_MASK                           ((uint32_t)(0x0000003FU))
#define CSL_RTC_REVISION_Y_MINOR_SHIFT                          ((uint32_t)(0U))
#define CSL_RTC_REVISION_Y_MINOR_RESETVAL                       ((uint32_t)(0x00000008U))
#define CSL_RTC_REVISION_Y_MINOR_MAX                            ((uint32_t)(0x0000003fU))

#define CSL_RTC_REVISION_CUSTOM_MASK                            ((uint32_t)(0x000000C0U))
#define CSL_RTC_REVISION_CUSTOM_SHIFT                           ((uint32_t)(6U))
#define CSL_RTC_REVISION_CUSTOM_RESETVAL                        ((uint32_t)(0x00000000U))
#define CSL_RTC_REVISION_CUSTOM_MAX                             ((uint32_t)(0x00000003U))

#define CSL_RTC_REVISION_X_MAJOR_MASK                           ((uint32_t)(0x00000700U))
#define CSL_RTC_REVISION_X_MAJOR_SHIFT                          ((uint32_t)(8U))
#define CSL_RTC_REVISION_X_MAJOR_RESETVAL                       ((uint32_t)(0x00000000U))
#define CSL_RTC_REVISION_X_MAJOR_MAX                            ((uint32_t)(0x00000007U))

#define CSL_RTC_REVISION_R_RTL_MASK                             ((uint32_t)(0x0000F800U))
#define CSL_RTC_REVISION_R_RTL_SHIFT                            ((uint32_t)(11U))
#define CSL_RTC_REVISION_R_RTL_RESETVAL                         ((uint32_t)(0x00000000U))
#define CSL_RTC_REVISION_R_RTL_MAX                              ((uint32_t)(0x0000001fU))

#define CSL_RTC_REVISION_FUNC_MASK                              ((uint32_t)(0x0FFF0000U))
#define CSL_RTC_REVISION_FUNC_SHIFT                             ((uint32_t)(16U))
#define CSL_RTC_REVISION_FUNC_RESETVAL                          ((uint32_t)(0x00000000U))
#define CSL_RTC_REVISION_FUNC_MAX                               ((uint32_t)(0x00000fffU))

#define CSL_RTC_REVISION_SCHEME_MASK                            ((uint32_t)(0xC0000000U))
#define CSL_RTC_REVISION_SCHEME_SHIFT                           ((uint32_t)(30U))
#define CSL_RTC_REVISION_SCHEME_RESETVAL                        ((uint32_t)(0x00000001U))
#define CSL_RTC_REVISION_SCHEME_MAX                             ((uint32_t)(0x00000003U))

#define CSL_RTC_REVISION_RESETVAL                               ((uint32_t)(0x4eb0090cU))

/* SYSCONFIG */

#define CSL_RTC_SYSCONFIG_IDLEMODE_MASK                         ((uint32_t)(0x00000003U))
#define CSL_RTC_SYSCONFIG_IDLEMODE_SHIFT                        ((uint32_t)(0U))
#define CSL_RTC_SYSCONFIG_IDLEMODE_RESETVAL                     ((uint32_t)(0x00000000U))
#define CSL_RTC_SYSCONFIG_IDLEMODE_MAX                          ((uint32_t)(0x00000003U))

#define CSL_RTC_SYSCONFIG_RESETVAL                              ((uint32_t)(0x00000002U))

/* IRQWAKEEN */

#define CSL_RTC_IRQWAKEEN_TIMMER_WAKEEN_MASK                    ((uint32_t)(0x00000001U))
#define CSL_RTC_IRQWAKEEN_TIMMER_WAKEEN_SHIFT                   ((uint32_t)(0U))
#define CSL_RTC_IRQWAKEEN_TIMMER_WAKEEN_RESETVAL                ((uint32_t)(0x00000000U))
#define CSL_RTC_IRQWAKEEN_TIMMER_WAKEEN_MAX                     ((uint32_t)(0x00000001U))

#define CSL_RTC_IRQWAKEEN_ALARM_WAKEEN_MASK                     ((uint32_t)(0x00000002U))
#define CSL_RTC_IRQWAKEEN_ALARM_WAKEEN_SHIFT                    ((uint32_t)(1U))
#define CSL_RTC_IRQWAKEEN_ALARM_WAKEEN_RESETVAL                 ((uint32_t)(0x00000000U))
#define CSL_RTC_IRQWAKEEN_ALARM_WAKEEN_MAX                      ((uint32_t)(0x00000001U))

#define CSL_RTC_IRQWAKEEN_RESETVAL                              ((uint32_t)(0x00000000U))

/* ALARM2_SECONDS */

#define CSL_RTC_ALARM2_SECONDS_ALARM2_SEC0_MASK                 ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM2_SECONDS_ALARM2_SEC0_SHIFT                ((uint32_t)(0U))
#define CSL_RTC_ALARM2_SECONDS_ALARM2_SEC0_RESETVAL             ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_SECONDS_ALARM2_SEC0_MAX                  ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM2_SECONDS_ALARM2_SEC1_MASK                 ((uint32_t)(0x00000070U))
#define CSL_RTC_ALARM2_SECONDS_ALARM2_SEC1_SHIFT                ((uint32_t)(4U))
#define CSL_RTC_ALARM2_SECONDS_ALARM2_SEC1_RESETVAL             ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_SECONDS_ALARM2_SEC1_MAX                  ((uint32_t)(0x00000007U))

#define CSL_RTC_ALARM2_SECONDS_RESETVAL                         ((uint32_t)(0x00000000U))

/* ALARM2_MINUTES */

#define CSL_RTC_ALARM2_MINUTES_ALARM2_MIN0_MASK                 ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM2_MINUTES_ALARM2_MIN0_SHIFT                ((uint32_t)(0U))
#define CSL_RTC_ALARM2_MINUTES_ALARM2_MIN0_RESETVAL             ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_MINUTES_ALARM2_MIN0_MAX                  ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM2_MINUTES_ALARM2_MIN1_MASK                 ((uint32_t)(0x00000070U))
#define CSL_RTC_ALARM2_MINUTES_ALARM2_MIN1_SHIFT                ((uint32_t)(4U))
#define CSL_RTC_ALARM2_MINUTES_ALARM2_MIN1_RESETVAL             ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_MINUTES_ALARM2_MIN1_MAX                  ((uint32_t)(0x00000007U))

#define CSL_RTC_ALARM2_MINUTES_RESETVAL                         ((uint32_t)(0x00000000U))

/* ALARM2_HOURS */

#define CSL_RTC_ALARM2_HOURS_ALARM2_HOUR0_MASK                  ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM2_HOURS_ALARM2_HOUR0_SHIFT                 ((uint32_t)(0U))
#define CSL_RTC_ALARM2_HOURS_ALARM2_HOUR0_RESETVAL              ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_HOURS_ALARM2_HOUR0_MAX                   ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM2_HOURS_ALARM2_HOUR1_MASK                  ((uint32_t)(0x00000030U))
#define CSL_RTC_ALARM2_HOURS_ALARM2_HOUR1_SHIFT                 ((uint32_t)(4U))
#define CSL_RTC_ALARM2_HOURS_ALARM2_HOUR1_RESETVAL              ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_HOURS_ALARM2_HOUR1_MAX                   ((uint32_t)(0x00000003U))

#define CSL_RTC_ALARM2_HOURS_ALARM2_PM_NAM_MASK                 ((uint32_t)(0x00000080U))
#define CSL_RTC_ALARM2_HOURS_ALARM2_PM_NAM_SHIFT                ((uint32_t)(7U))
#define CSL_RTC_ALARM2_HOURS_ALARM2_PM_NAM_RESETVAL             ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_HOURS_ALARM2_PM_NAM_MAX                  ((uint32_t)(0x00000001U))

#define CSL_RTC_ALARM2_HOURS_RESETVAL                           ((uint32_t)(0x00000000U))

/* ALARM2_DAYS */

#define CSL_RTC_ALARM2_DAYS_ALARM_DAY0_MASK                     ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM2_DAYS_ALARM_DAY0_SHIFT                    ((uint32_t)(0U))
#define CSL_RTC_ALARM2_DAYS_ALARM_DAY0_RESETVAL                 ((uint32_t)(0x00000001U))
#define CSL_RTC_ALARM2_DAYS_ALARM_DAY0_MAX                      ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM2_DAYS_ALARM_DAY1_MASK                     ((uint32_t)(0x00000030U))
#define CSL_RTC_ALARM2_DAYS_ALARM_DAY1_SHIFT                    ((uint32_t)(4U))
#define CSL_RTC_ALARM2_DAYS_ALARM_DAY1_RESETVAL                 ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_DAYS_ALARM_DAY1_MAX                      ((uint32_t)(0x00000003U))

#define CSL_RTC_ALARM2_DAYS_RESETVAL                            ((uint32_t)(0x00000001U))

/* ALARM2_MONTHS */

#define CSL_RTC_ALARM2_MONTHS_ALARM2_MONTH0_MASK                ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM2_MONTHS_ALARM2_MONTH0_SHIFT               ((uint32_t)(0U))
#define CSL_RTC_ALARM2_MONTHS_ALARM2_MONTH0_RESETVAL            ((uint32_t)(0x00000001U))
#define CSL_RTC_ALARM2_MONTHS_ALARM2_MONTH0_MAX                 ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM2_MONTHS_ALARM2_MONTH1_MASK                ((uint32_t)(0x00000010U))
#define CSL_RTC_ALARM2_MONTHS_ALARM2_MONTH1_SHIFT               ((uint32_t)(4U))
#define CSL_RTC_ALARM2_MONTHS_ALARM2_MONTH1_RESETVAL            ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_MONTHS_ALARM2_MONTH1_MAX                 ((uint32_t)(0x00000001U))

#define CSL_RTC_ALARM2_MONTHS_RESETVAL                          ((uint32_t)(0x00000001U))

/* ALARM2_YEARS */

#define CSL_RTC_ALARM2_YEARS_ALARM2_YEAR0_MASK                  ((uint32_t)(0x0000000FU))
#define CSL_RTC_ALARM2_YEARS_ALARM2_YEAR0_SHIFT                 ((uint32_t)(0U))
#define CSL_RTC_ALARM2_YEARS_ALARM2_YEAR0_RESETVAL              ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_YEARS_ALARM2_YEAR0_MAX                   ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM2_YEARS_ALARM2_YEAR1_MASK                  ((uint32_t)(0x000000F0U))
#define CSL_RTC_ALARM2_YEARS_ALARM2_YEAR1_SHIFT                 ((uint32_t)(4U))
#define CSL_RTC_ALARM2_YEARS_ALARM2_YEAR1_RESETVAL              ((uint32_t)(0x00000000U))
#define CSL_RTC_ALARM2_YEARS_ALARM2_YEAR1_MAX                   ((uint32_t)(0x0000000fU))

#define CSL_RTC_ALARM2_YEARS_RESETVAL                           ((uint32_t)(0x00000000U))

/* RTC_PMIC_REG */

#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_EN_MASK                 ((uint32_t)(0x0000000FU))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_EN_SHIFT                ((uint32_t)(0U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_EN_RESETVAL             ((uint32_t)(0x00000000U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_EN_MAX                  ((uint32_t)(0x0000000fU))

#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_POL_MASK                ((uint32_t)(0x000000F0U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_POL_SHIFT               ((uint32_t)(4U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_POL_RESETVAL            ((uint32_t)(0x00000000U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_POL_MAX                 ((uint32_t)(0x0000000fU))

#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_DB_EN_MASK              ((uint32_t)(0x00000F00U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_DB_EN_SHIFT             ((uint32_t)(8U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_DB_EN_RESETVAL          ((uint32_t)(0x00000000U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_DB_EN_MAX               ((uint32_t)(0x0000000fU))

#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_STS_MASK                ((uint32_t)(0x0000F000U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_STS_SHIFT               ((uint32_t)(12U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_STS_RESETVAL            ((uint32_t)(0x00000000U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_STS_MAX                 ((uint32_t)(0x0000000fU))

#define CSL_RTC_RTC_PMIC_REG_PWR_EN_MASK                        ((uint32_t)(0x00010000U))
#define CSL_RTC_RTC_PMIC_REG_PWR_EN_SHIFT                       ((uint32_t)(16U))
#define CSL_RTC_RTC_PMIC_REG_PWR_EN_RESETVAL                    ((uint32_t)(0x00000000U))
#define CSL_RTC_RTC_PMIC_REG_PWR_EN_MAX                         ((uint32_t)(0x00000001U))

#define CSL_RTC_RTC_PMIC_REG_PWR_EN_SM_MASK                     ((uint32_t)(0x00060000U))
#define CSL_RTC_RTC_PMIC_REG_PWR_EN_SM_SHIFT                    ((uint32_t)(17U))
#define CSL_RTC_RTC_PMIC_REG_PWR_EN_SM_RESETVAL                 ((uint32_t)(0x00000000U))
#define CSL_RTC_RTC_PMIC_REG_PWR_EN_SM_MAX                      ((uint32_t)(0x00000003U))

#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_POL_HL_MASK             ((uint32_t)(0x00780000U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_POL_HL_SHIFT            ((uint32_t)(19U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_POL_HL_RESETVAL         ((uint32_t)(0x00000000U))
#define CSL_RTC_RTC_PMIC_REG_EXT_WAKEUP_POL_HL_MAX              ((uint32_t)(0x0000000fU))

#define CSL_RTC_RTC_PMIC_REG_RESETVAL                           ((uint32_t)(0x00000000U))

/* RTL_DEBOUNCE */

#define CSL_RTC_RTL_DEBOUNCE_DEBOUNCE_REG_MASK                  ((uint32_t)(0x000000FFU))
#define CSL_RTC_RTL_DEBOUNCE_DEBOUNCE_REG_SHIFT                 ((uint32_t)(0U))
#define CSL_RTC_RTL_DEBOUNCE_DEBOUNCE_REG_RESETVAL              ((uint32_t)(0x00000000U))
#define CSL_RTC_RTL_DEBOUNCE_DEBOUNCE_REG_MAX                   ((uint32_t)(0x000000ffU))

#define CSL_RTC_RTL_DEBOUNCE_RESETVAL                           ((uint32_t)(0x00000000U))

#ifdef __cplusplus
}
#endif
#endif
