/********************************************************************
 * Copyright (C) 2013-2015 Texas Instruments Incorporated.
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
 *  Name        : cslr_rtc.h
 *  Description : RTC top level, Module
 *  Version     : 0.5.0.0
*/
#ifndef CSLR_RTC_H_
#define CSLR_RTC_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : rtc_regs registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t MOD_VER;                   /* Module ID and Version  */
    volatile uint32_t SUB_S_CNT;                 /* SubSecondCount */
    volatile uint32_t S_CNT_LSW;                 /* SecondCount_31_0 */
    volatile uint32_t S_CNT_MSW;                 /* SecondCount_47_32 */
    volatile uint32_t COMP;                      /* Compensation */
    volatile uint8_t  Resv_24[4];
    volatile uint32_t OFF_ON_S_CNT_LSW;          /* OffOnSCnt_31_0 */
    volatile uint32_t OFF_ON_S_CNT_MSW;          /* OffOnSCnt_47_32 */
    volatile uint32_t ON_OFF_S_CNT_LSW;          /* OnOffSCnt_31_0 */
    volatile uint32_t ON_OFF_S_CNT_MSW;          /* OnOffSCnt_47_32 */
    volatile uint32_t DEBOUNCE;                  /* Debounce */
    volatile uint32_t ANALOG;                    /* AnalogCfg */
    volatile uint32_t SCRATCH[8];               /* Scratch Storage X */
    volatile uint32_t GENRAL_CTL;                /* GeneralControl */
    volatile uint32_t IRQSTATUS_RAW_SYS;         /* Interrupt Raw Status Register */
    volatile uint32_t IRQSTATUS_SYS;             /* Interrupt Status Register */
    volatile uint32_t IRQENABLE_SET_SYS;         /* Interrupt Enable Set Register */
    volatile uint32_t IRQENABLE_CLR_SYS;         /* Interrupt Enable Clear Register */
    volatile uint8_t  Resv_104[4];
    volatile uint32_t SYNCPEND;                  /* SyncPending */
    volatile uint8_t  Resv_112[4];
    volatile uint32_t KICK0;                     /* Kick0 */
    volatile uint32_t KICK1;                     /* Kick1 */
    volatile uint8_t  Resv_128[8];
} CSL_rtcRegs;





/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_RTC_MOD_VER                                      (0x00000000U)
#define CSL_RTC_SUB_S_CNT                                    (0x00000004U)
#define CSL_RTC_S_CNT_LSW                                    (0x00000008U)
#define CSL_RTC_S_CNT_MSW                                    (0x0000000CU)
#define CSL_RTC_COMP                                         (0x00000010U)
#define CSL_RTC_OFF_ON_S_CNT_LSW                             (0x00000018U)
#define CSL_RTC_OFF_ON_S_CNT_MSW                             (0x0000001CU)
#define CSL_RTC_ON_OFF_S_CNT_LSW                             (0x00000020U)
#define CSL_RTC_ON_OFF_S_CNT_MSW                             (0x00000024U)
#define CSL_RTC_DEBOUNCE                                     (0x00000028U)
#define CSL_RTC_ANALOG                                       (0x0000002CU)
#define CSL_RTC_SCRATCH0                                    (0x00000030U)
#define CSL_RTC_SCRATCH1                                    (0x00000034U)
#define CSL_RTC_SCRATCH2                                    (0x00000038U)
#define CSL_RTC_SCRATCH3                                    (0x0000003CU)
#define CSL_RTC_SCRATCH4                                    (0x00000040U)
#define CSL_RTC_SCRATCH5                                    (0x00000044U)
#define CSL_RTC_SCRATCH6                                    (0x00000048U)
#define CSL_RTC_SCRATCH7                                    (0x0000004CU)
#define CSL_RTC_GENRAL_CTL                                   (0x00000050U)
#define CSL_RTC_IRQSTATUS_RAW_SYS                            (0x00000054U)
#define CSL_RTC_IRQSTATUS_SYS                                (0x00000058U)
#define CSL_RTC_IRQENABLE_SET_SYS                            (0x0000005CU)
#define CSL_RTC_IRQENABLE_CLR_SYS                            (0x00000060U)
#define CSL_RTC_SYNCPEND                                     (0x00000068U)
#define CSL_RTC_KICK0                                        (0x00000070U)
#define CSL_RTC_KICK1                                        (0x00000074U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* MOD_VER */

#define CSL_RTC_MOD_VER_MODULE_ID_MASK                        (0xFFFF0000U)
#define CSL_RTC_MOD_VER_MODULE_ID_SHIFT                       (0x00000010U)
#define CSL_RTC_MOD_VER_MODULE_ID_RESETVAL                    (0x00000044U)
#define CSL_RTC_MOD_VER_MODULE_ID_MAX                         (0x0000FFFFU)

#define CSL_RTC_MOD_VER_RTL_VERSION_MASK                      (0x0000F800U)
#define CSL_RTC_MOD_VER_RTL_VERSION_SHIFT                     (0x0000000BU)
#define CSL_RTC_MOD_VER_RTL_VERSION_RESETVAL                  (0x00000000U)
#define CSL_RTC_MOD_VER_RTL_VERSION_MAX                       (0x0000001FU)

#define CSL_RTC_MOD_VER_MAJOR_REVISION_MASK                   (0x00000700U)
#define CSL_RTC_MOD_VER_MAJOR_REVISION_SHIFT                  (0x00000008U)
#define CSL_RTC_MOD_VER_MAJOR_REVISION_RESETVAL               (0x00000001U)
#define CSL_RTC_MOD_VER_MAJOR_REVISION_MAX                    (0x00000007U)

#define CSL_RTC_MOD_VER_CUSTOM_REVISION_MASK                  (0x000000C0U)
#define CSL_RTC_MOD_VER_CUSTOM_REVISION_SHIFT                 (0x00000006U)
#define CSL_RTC_MOD_VER_CUSTOM_REVISION_RESETVAL              (0x00000000U)
#define CSL_RTC_MOD_VER_CUSTOM_REVISION_MAX                   (0x00000003U)

#define CSL_RTC_MOD_VER_MINOR_REVISION_MASK                   (0x0000003FU)
#define CSL_RTC_MOD_VER_MINOR_REVISION_SHIFT                  (0x00000000U)
#define CSL_RTC_MOD_VER_MINOR_REVISION_RESETVAL               (0x00000000U)
#define CSL_RTC_MOD_VER_MINOR_REVISION_MAX                    (0x0000003FU)

#define CSL_RTC_MOD_VER_RESETVAL                              (0x00440100U)

/* SUB_S_CNT */

#define CSL_RTC_SUB_S_CNT_VAL_MASK                      (0x00007FFFU)
#define CSL_RTC_SUB_S_CNT_VAL_SHIFT                     (0x00000000U)
#define CSL_RTC_SUB_S_CNT_VAL_RESETVAL                  (0x00000000U)
#define CSL_RTC_SUB_S_CNT_VAL_MAX                       (0x00007FFFU)

#define CSL_RTC_SUB_S_CNT_RESETVAL                            (0x00000000U)

/* S_CNT_LSW */

#define CSL_RTC_S_CNT_LSW_VAL_MASK                      (0xFFFFFFFFU)
#define CSL_RTC_S_CNT_LSW_VAL_SHIFT                     (0x00000000U)
#define CSL_RTC_S_CNT_LSW_VAL_RESETVAL                  (0x00000000U)
#define CSL_RTC_S_CNT_LSW_VAL_MAX                       (0xFFFFFFFFU)

#define CSL_RTC_S_CNT_LSW_RESETVAL                            (0x00000000U)

/* S_CNT_MSW */

#define CSL_RTC_S_CNT_MSW_VAL_MASK                      (0x0000FFFFU)
#define CSL_RTC_S_CNT_MSW_VAL_SHIFT                     (0x00000000U)
#define CSL_RTC_S_CNT_MSW_VAL_RESETVAL                  (0x00000000U)
#define CSL_RTC_S_CNT_MSW_VAL_MAX                       (0x0000FFFFU)

#define CSL_RTC_S_CNT_MSW_RESETVAL                            (0x00000000U)

/* COMP */

#define CSL_RTC_COMP_MSB_MASK                            (0x0000FF00U)
#define CSL_RTC_COMP_MSB_SHIFT                           (0x00000008U)
#define CSL_RTC_COMP_MSB_RESETVAL                        (0x00000000U)
#define CSL_RTC_COMP_MSB_MAX                             (0x000000FFU)

#define CSL_RTC_COMP_LSB_MASK                            (0x000000FFU)
#define CSL_RTC_COMP_LSB_SHIFT                           (0x00000000U)
#define CSL_RTC_COMP_LSB_RESETVAL                        (0x00000000U)
#define CSL_RTC_COMP_LSB_MAX                             (0x000000FFU)

#define CSL_RTC_COMP_RESETVAL                                 (0x00000000U)

/* OFF_ON_S_CNT_LSW */

#define CSL_RTC_OFF_ON_S_CNT_LSW_VAL_MASK        (0xFFFFFFFFU)
#define CSL_RTC_OFF_ON_S_CNT_LSW_VAL_SHIFT       (0x00000000U)
#define CSL_RTC_OFF_ON_S_CNT_LSW_VAL_RESETVAL    (0x00000000U)
#define CSL_RTC_OFF_ON_S_CNT_LSW_VAL_MAX         (0xFFFFFFFFU)

#define CSL_RTC_OFF_ON_S_CNT_LSW_RESETVAL                     (0x00000000U)

/* OFF_ON_S_CNT_MSW */

#define CSL_RTC_OFF_ON_S_CNT_MSW_VAL_MASK        (0x0000FFFFU)
#define CSL_RTC_OFF_ON_S_CNT_MSW_VAL_SHIFT       (0x00000000U)
#define CSL_RTC_OFF_ON_S_CNT_MSW_VAL_RESETVAL    (0x00000000U)
#define CSL_RTC_OFF_ON_S_CNT_MSW_VAL_MAX         (0x0000FFFFU)

#define CSL_RTC_OFF_ON_S_CNT_MSW_RESETVAL                     (0x00000000U)

/* ON_OFF_S_CNT_LSW */

#define CSL_RTC_ON_OFF_S_CNT_LSW_VAL_MASK        (0xFFFFFFFFU)
#define CSL_RTC_ON_OFF_S_CNT_LSW_VAL_SHIFT       (0x00000000U)
#define CSL_RTC_ON_OFF_S_CNT_LSW_VAL_RESETVAL    (0x00000000U)
#define CSL_RTC_ON_OFF_S_CNT_LSW_VAL_MAX         (0xFFFFFFFFU)

#define CSL_RTC_ON_OFF_S_CNT_LSW_RESETVAL                     (0x00000000U)

/* ON_OFF_S_CNT_MSW */

#define CSL_RTC_ON_OFF_S_CNT_MSW_VAL_MASK        (0x0000FFFFU)
#define CSL_RTC_ON_OFF_S_CNT_MSW_VAL_SHIFT       (0x00000000U)
#define CSL_RTC_ON_OFF_S_CNT_MSW_VAL_RESETVAL    (0x00000000U)
#define CSL_RTC_ON_OFF_S_CNT_MSW_VAL_MAX         (0x0000FFFFU)

#define CSL_RTC_ON_OFF_S_CNT_MSW_RESETVAL                     (0x00000000U)

/* DEBOUNCE */

#define CSL_RTC_DEBOUNCE_VAL_MASK                        (0x000000FFU)
#define CSL_RTC_DEBOUNCE_VAL_SHIFT                       (0x00000000U)
#define CSL_RTC_DEBOUNCE_VAL_RESETVAL                    (0x00000000U)
#define CSL_RTC_DEBOUNCE_VAL_MAX                         (0x000000FFU)

#define CSL_RTC_DEBOUNCE_RESETVAL                             (0x00000000U)

/* ANALOG */

#define CSL_RTC_ANALOG_VAL_MASK                            (0xFFFFFFFFU)
#define CSL_RTC_ANALOG_VAL_SHIFT                           (0x00000000U)
#define CSL_RTC_ANALOG_VAL_RESETVAL                        (0x00000000U)
#define CSL_RTC_ANALOG_VAL_MAX                             (0xFFFFFFFFU)

#define CSL_RTC_ANALOG_RESETVAL                               (0x00000000U)

/* SCRATCH */

#define CSL_RTC_SCRATCH_VAL_MASK                        (0xFFFFFFFFU)
#define CSL_RTC_SCRATCH_VAL_SHIFT                       (0x00000000U)
#define CSL_RTC_SCRATCH_VAL_RESETVAL                    (0x00000000U)
#define CSL_RTC_SCRATCH_VAL_MAX                         (0xFFFFFFFFU)

#define CSL_RTC_SCRATCH_RESETVAL                             (0x00000000U)

/* GENRAL_CTL */

#define CSL_RTC_GENRAL_CTL_CNT_FMODE_MASK                     (0x03000000U)
#define CSL_RTC_GENRAL_CTL_CNT_FMODE_SHIFT                    (0x00000018U)
#define CSL_RTC_GENRAL_CTL_CNT_FMODE_RESETVAL                 (0x00000000U)
#define CSL_RTC_GENRAL_CTL_CNT_FMODE_MAX                      (0x00000003U)

#define CSL_RTC_GENRAL_CTL_UNLOCK_MASK                        (0x00800000U)
#define CSL_RTC_GENRAL_CTL_UNLOCK_SHIFT                       (0x00000017U)
#define CSL_RTC_GENRAL_CTL_UNLOCK_RESETVAL                    (0x00000000U)
#define CSL_RTC_GENRAL_CTL_UNLOCK_MAX                         (0x00000001U)

#define CSL_RTC_GENRAL_CTL_O32K_OSC_DEP_EN_MASK               (0x00200000U)
#define CSL_RTC_GENRAL_CTL_O32K_OSC_DEP_EN_SHIFT              (0x00000015U)
#define CSL_RTC_GENRAL_CTL_O32K_OSC_DEP_EN_RESETVAL           (0x00000000U)
#define CSL_RTC_GENRAL_CTL_O32K_OSC_DEP_EN_MAX                (0x00000001U)

#define CSL_RTC_GENRAL_CTL_SW_OFF_MASK                        (0x00020000U)
#define CSL_RTC_GENRAL_CTL_SW_OFF_SHIFT                       (0x00000011U)
#define CSL_RTC_GENRAL_CTL_SW_OFF_RESETVAL                    (0x00000000U)
#define CSL_RTC_GENRAL_CTL_SW_OFF_MAX                         (0x00000001U)

#define CSL_RTC_GENRAL_CTL_PWR_OFF_EN_MASK                    (0x00010000U)
#define CSL_RTC_GENRAL_CTL_PWR_OFF_EN_SHIFT                   (0x00000010U)
#define CSL_RTC_GENRAL_CTL_PWR_OFF_EN_RESETVAL                (0x00000000U)
#define CSL_RTC_GENRAL_CTL_PWR_OFF_EN_MAX                     (0x00000001U)

#define CSL_RTC_GENRAL_CTL_WKUP_DB_EN_MASK                    (0x00000F00U)
#define CSL_RTC_GENRAL_CTL_WKUP_DB_EN_SHIFT                   (0x00000008U)
#define CSL_RTC_GENRAL_CTL_WKUP_DB_EN_RESETVAL                (0x00000000U)
#define CSL_RTC_GENRAL_CTL_WKUP_DB_EN_MAX                     (0x0000000FU)

#define CSL_RTC_GENRAL_CTL_WKUP_POL_MASK                      (0x000000F0U)
#define CSL_RTC_GENRAL_CTL_WKUP_POL_SHIFT                     (0x00000004U)
#define CSL_RTC_GENRAL_CTL_WKUP_POL_RESETVAL                  (0x00000000U)
#define CSL_RTC_GENRAL_CTL_WKUP_POL_MAX                       (0x0000000FU)

#define CSL_RTC_GENRAL_CTL_WKUP_EN_MASK                       (0x0000000FU)
#define CSL_RTC_GENRAL_CTL_WKUP_EN_SHIFT                      (0x00000000U)
#define CSL_RTC_GENRAL_CTL_WKUP_EN_RESETVAL                   (0x00000000U)
#define CSL_RTC_GENRAL_CTL_WKUP_EN_MAX                        (0x0000000FU)

#define CSL_RTC_GENRAL_CTL_RESETVAL                           (0x00000000U)

/* IRQSTATUS_RAW_SYS */

#define CSL_RTC_IRQSTATUS_RAW_SYS_EVENT_OFF_ON_MASK           (0x00000002U)
#define CSL_RTC_IRQSTATUS_RAW_SYS_EVENT_OFF_ON_SHIFT          (0x00000001U)
#define CSL_RTC_IRQSTATUS_RAW_SYS_EVENT_OFF_ON_RESETVAL       (0x00000000U)
#define CSL_RTC_IRQSTATUS_RAW_SYS_EVENT_OFF_ON_MAX            (0x00000001U)

#define CSL_RTC_IRQSTATUS_RAW_SYS_EVENT_ON_OFF_MASK           (0x00000001U)
#define CSL_RTC_IRQSTATUS_RAW_SYS_EVENT_ON_OFF_SHIFT          (0x00000000U)
#define CSL_RTC_IRQSTATUS_RAW_SYS_EVENT_ON_OFF_RESETVAL       (0x00000000U)
#define CSL_RTC_IRQSTATUS_RAW_SYS_EVENT_ON_OFF_MAX            (0x00000001U)

#define CSL_RTC_IRQSTATUS_RAW_SYS_RESETVAL                    (0x00000000U)

/* IRQSTATUS_SYS */

#define CSL_RTC_IRQSTATUS_SYS_EVENT_OFF_ON_MASK               (0x00000002U)
#define CSL_RTC_IRQSTATUS_SYS_EVENT_OFF_ON_SHIFT              (0x00000001U)
#define CSL_RTC_IRQSTATUS_SYS_EVENT_OFF_ON_RESETVAL           (0x00000000U)
#define CSL_RTC_IRQSTATUS_SYS_EVENT_OFF_ON_MAX                (0x00000001U)

#define CSL_RTC_IRQSTATUS_SYS_EVENT_ON_OFF_MASK               (0x00000001U)
#define CSL_RTC_IRQSTATUS_SYS_EVENT_ON_OFF_SHIFT              (0x00000000U)
#define CSL_RTC_IRQSTATUS_SYS_EVENT_ON_OFF_RESETVAL           (0x00000000U)
#define CSL_RTC_IRQSTATUS_SYS_EVENT_ON_OFF_MAX                (0x00000001U)

#define CSL_RTC_IRQSTATUS_SYS_RESETVAL                        (0x00000000U)

/* IRQENABLE_SET_SYS */

#define CSL_RTC_IRQENABLE_SET_SYS_EN_EVENT_OFF_ON_MASK        (0x00000002U)
#define CSL_RTC_IRQENABLE_SET_SYS_EN_EVENT_OFF_ON_SHIFT       (0x00000001U)
#define CSL_RTC_IRQENABLE_SET_SYS_EN_EVENT_OFF_ON_RESETVAL    (0x00000000U)
#define CSL_RTC_IRQENABLE_SET_SYS_EN_EVENT_OFF_ON_MAX         (0x00000001U)

#define CSL_RTC_IRQENABLE_SET_SYS_EN_EVENT_ON_OFF_MASK        (0x00000001U)
#define CSL_RTC_IRQENABLE_SET_SYS_EN_EVENT_ON_OFF_SHIFT       (0x00000000U)
#define CSL_RTC_IRQENABLE_SET_SYS_EN_EVENT_ON_OFF_RESETVAL    (0x00000000U)
#define CSL_RTC_IRQENABLE_SET_SYS_EN_EVENT_ON_OFF_MAX         (0x00000001U)

#define CSL_RTC_IRQENABLE_SET_SYS_RESETVAL                    (0x00000000U)

/* IRQENABLE_CLR_SYS */

#define CSL_RTC_IRQENABLE_CLR_SYS_EN_EVENT_OFF_ON_MASK        (0x00000002U)
#define CSL_RTC_IRQENABLE_CLR_SYS_EN_EVENT_OFF_ON_SHIFT       (0x00000001U)
#define CSL_RTC_IRQENABLE_CLR_SYS_EN_EVENT_OFF_ON_RESETVAL    (0x00000000U)
#define CSL_RTC_IRQENABLE_CLR_SYS_EN_EVENT_OFF_ON_MAX         (0x00000001U)

#define CSL_RTC_IRQENABLE_CLR_SYS_EN_EVENT_ON_OFF_MASK        (0x00000001U)
#define CSL_RTC_IRQENABLE_CLR_SYS_EN_EVENT_ON_OFF_SHIFT       (0x00000000U)
#define CSL_RTC_IRQENABLE_CLR_SYS_EN_EVENT_ON_OFF_RESETVAL    (0x00000000U)
#define CSL_RTC_IRQENABLE_CLR_SYS_EN_EVENT_ON_OFF_MAX         (0x00000001U)

#define CSL_RTC_IRQENABLE_CLR_SYS_RESETVAL                    (0x00000000U)

/* SYNCPEND */

#define CSL_RTC_SYNCPEND_RELOAD_FROM_BBD_MASK                 (0x80000000U)
#define CSL_RTC_SYNCPEND_RELOAD_FROM_BBD_SHIFT                (0x0000001FU)
#define CSL_RTC_SYNCPEND_RELOAD_FROM_BBD_RESETVAL             (0x00000000U)
#define CSL_RTC_SYNCPEND_RELOAD_FROM_BBD_MAX                  (0x00000001U)

#define CSL_RTC_SYNCPEND_PWR_ENABLE_ST_MASK                   (0x00000100U)
#define CSL_RTC_SYNCPEND_PWR_ENABLE_ST_SHIFT                  (0x00000008U)
#define CSL_RTC_SYNCPEND_PWR_ENABLE_ST_RESETVAL               (0x00000000U)
#define CSL_RTC_SYNCPEND_PWR_ENABLE_ST_MAX                    (0x00000001U)

#define CSL_RTC_SYNCPEND_WKUP_DB_ST_MASK                      (0x000000F0U)
#define CSL_RTC_SYNCPEND_WKUP_DB_ST_SHIFT                     (0x00000004U)
#define CSL_RTC_SYNCPEND_WKUP_DB_ST_RESETVAL                  (0x00000000U)
#define CSL_RTC_SYNCPEND_WKUP_DB_ST_MAX                       (0x0000000FU)

#define CSL_RTC_SYNCPEND_WRT_ERR_MASK                         (0x00000008U)
#define CSL_RTC_SYNCPEND_WRT_ERR_SHIFT                        (0x00000003U)
#define CSL_RTC_SYNCPEND_WRT_ERR_RESETVAL                     (0x00000000U)
#define CSL_RTC_SYNCPEND_WRT_ERR_MAX                          (0x00000001U)

#define CSL_RTC_SYNCPEND_O32K_CLK_OBS_MASK                    (0x00000004U)
#define CSL_RTC_SYNCPEND_O32K_CLK_OBS_SHIFT                   (0x00000002U)
#define CSL_RTC_SYNCPEND_O32K_CLK_OBS_RESETVAL                (0x00000000U)
#define CSL_RTC_SYNCPEND_O32K_CLK_OBS_MAX                     (0x00000001U)

#define CSL_RTC_SYNCPEND_RD_PEND_MASK                         (0x00000002U)
#define CSL_RTC_SYNCPEND_RD_PEND_SHIFT                        (0x00000001U)
#define CSL_RTC_SYNCPEND_RD_PEND_RESETVAL                     (0x00000000U)
#define CSL_RTC_SYNCPEND_RD_PEND_MAX                          (0x00000001U)

#define CSL_RTC_SYNCPEND_WR_PEND_MASK                         (0x00000001U)
#define CSL_RTC_SYNCPEND_WR_PEND_SHIFT                        (0x00000000U)
#define CSL_RTC_SYNCPEND_WR_PEND_RESETVAL                     (0x00000000U)
#define CSL_RTC_SYNCPEND_WR_PEND_MAX                          (0x00000001U)

#define CSL_RTC_SYNCPEND_RESETVAL                             (0x00000000U)

/* KICK0 */

#define CSL_RTC_KICK0_VAL_MASK                              (0xFFFFFFFFU)
#define CSL_RTC_KICK0_VAL_SHIFT                             (0x00000000U)
#define CSL_RTC_KICK0_VAL_RESETVAL                          (0x00000000U)
#define CSL_RTC_KICK0_VAL_MAX                               (0xFFFFFFFFU)

#define CSL_RTC_KICK0_RESETVAL                                (0x00000000U)

/* KICK1 */

#define CSL_RTC_KICK1_VAL_MASK                              (0xFFFFFFFFU)
#define CSL_RTC_KICK1_VAL_SHIFT                             (0x00000000U)
#define CSL_RTC_KICK1_VAL_RESETVAL                          (0x00000000U)
#define CSL_RTC_KICK1_VAL_MAX                               (0xFFFFFFFFU)

#define CSL_RTC_KICK1_RESETVAL                                (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
