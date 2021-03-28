/********************************************************************
*
* WKUP_ESM0 INTERRUPT MAP. header file
*
* Copyright (C) 2015-2019 Texas Instruments Incorporated.
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
#ifndef CSLR_WKUP_ESM0_INTERRUPT_MAP_H_
#define CSLR_WKUP_ESM0_INTERRUPT_MAP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* List of intr sources for receiver: WKUP_ESM0
*/

#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_DMSC0_DMTIMER_0_INTR_PEND_0                              (0U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_DMSC0_DMTIMER_1_INTR_PEND_0                              (1U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_DMSC0_DMTIMER_2_INTR_PEND_0                              (2U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_DMSC0_DMTIMER_3_INTR_PEND_0                              (3U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_DMSC0_RTI_0_INTR_WWD_0                                   (4U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_DMSC0_RAT_0_EXP_INTR_0                                   (5U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_DMSC0_ECC_AGGR_0_ECC_CORRECTED_ERR_LEVEL_0               (6U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_DMSC0_ECC_AGGR_0_ECC_UNCORRECTED_ERR_LEVEL_0             (7U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_VTM0_THERM_LVL_GT_TH1_INTR_0                             (8U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_VTM0_THERM_LVL_LT_TH0_INTR_0                             (9U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_VTM0_THERM_LVL_GT_TH2_INTR_0                             (10U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_VTM0_CORR_LEVEL_0                                        (11U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_VTM0_UNCORR_LEVEL_0                                      (12U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_GLUELOGIC_HFOSC0_CLKLOSS_GLUE_REF_CLK_LOSS_DETECT_OUT_0       (13U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_ECC_AGGR0_CORR_LEVEL_0                                   (14U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_ECC_AGGR0_UNCORR_LEVEL_0                                 (15U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_TIMEOUT_INFRA0_SAFEG_TRANS_ERR_LVL_0                     (16U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PORZ_SYNC0_PORZ_TIMEOUT_0                                (17U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_WAKEUP0_VDD_MCU_GLDTC_STAT_THRESH_LOW_FLAG_IPCFG_0       (20U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_WAKEUP0_VDD_MCU_GLDTC_STAT_THRESH_HI_FLAG_IPCFG_0        (21U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_WAKEUP0_VDDR_MCU_GLDTC_STAT_THRESH_LOW_FLAG_IPCFG_0      (22U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_WAKEUP0_VDDR_MCU_GLDTC_STAT_THRESH_HI_FLAG_IPCFG_0       (23U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_MAIN0_VDD_CORE_GLDTC_STAT_THRESH_LOW_FLAG_IPCFG_0             (24U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_MAIN0_VDD_CORE_GLDTC_STAT_THRESH_HI_FLAG_IPCFG_0              (25U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_MAIN0_VDDR_CORE_GLDTC_STAT_THRESH_LOW_FLAG_IPCFG_0            (26U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_MAIN0_VDDR_CORE_GLDTC_STAT_THRESH_HI_FLAG_IPCFG_0             (27U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_MAIN0_VDD_CPU_GLDTC_STAT_THRESH_LOW_FLAG_IPCFG_0              (28U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_MAIN0_VDD_CPU_GLDTC_STAT_THRESH_HI_FLAG_IPCFG_0               (29U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_MAIN0_VDDR_CPU_GLDTC_STAT_THRESH_LOW_FLAG_IPCFG_0             (30U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_MAIN0_VDDR_CPU_GLDTC_STAT_THRESH_HI_FLAG_IPCFG_0              (31U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_WKUP_ALWAYSON_CS1_CLKSTOP_REQ_0        (32U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_DMSC_CS1_CLKSTOP_REQ_0                 (33U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_DEBUG2DMSC_CS1_CLKSTOP_REQ_0           (34U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_WKUP_GPIO_CS1_CLKSTOP_REQ_0            (35U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_WKUPMCU2MAIN_CS1_CLKSTOP_REQ_0         (36U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MAIN2WKUPMCU_CS1_CLKSTOP_REQ_0         (37U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_TEST_CS1_CLKSTOP_REQ_0             (38U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_DEBUG_CS1_CLKSTOP_REQ_0            (39U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_MCAN_0_CS1_CLKSTOP_REQ_0           (40U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_MCAN_1_CS1_CLKSTOP_REQ_0           (41U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_OSPI_0_CS1_CLKSTOP_REQ_0           (42U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_OSPI_1_CS1_CLKSTOP_REQ_0           (43U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_HYPERBUS_CS1_CLKSTOP_REQ_0         (44U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_I3C_0_CS1_CLKSTOP_REQ_0            (45U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_I3C_1_CS1_CLKSTOP_REQ_0            (46U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_ADC_0_CS1_CLKSTOP_REQ_0            (47U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_ADC_1_CS1_CLKSTOP_REQ_0            (48U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_WKUP_SPARE0_CS1_CLKSTOP_REQ_0          (49U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_WKUP_SPARE1_CS1_CLKSTOP_REQ_0          (50U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_R5_0_CS1_CLKSTOP_REQ_0             (51U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_R5_1_CS1_CLKSTOP_REQ_0             (52U)
#define CSLR_WKUP_ESM0_ESM_LVL_EVENT_WKUP_PSC0_PSC_MOD_WKLP_MCU_PULSAR_PBIST_0_CS1_CLKSTOP_REQ_0   (53U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU_3POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_0              (64U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU_3POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_0              (64U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU_3POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_0              (64U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU_3POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_0              (65U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU_3POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_0              (65U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU_3POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_0              (65U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU_3POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_1              (66U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU_3POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_1              (66U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU_3POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_1              (66U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU_3POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_1              (67U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU_3POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_1              (67U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU_3POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_1              (67U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU_3POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_2              (68U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU_3POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_2              (68U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU_3POKS0_POK_PGOOD_UV_OUT_N_TO_ESM_2              (68U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU_3POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_2              (69U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU_3POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_2              (69U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU_3POKS0_POK_PGOOD_OV_OUT_N_TO_ESM_2              (69U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_0                    (72U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_0                    (72U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_0                    (72U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_1                    (74U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_1                    (74U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_1                    (74U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_2                    (76U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_2                    (76U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_2                    (76U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_3                    (78U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_3                    (78U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_3                    (78U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_4                    (80U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_4                    (80U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG_MCU0_POK_PGOOD_UV_OUT_N_TO_ESM_4                    (80U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_0                        (88U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_0                        (88U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_0                        (88U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_0                        (89U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_0                        (89U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_0                        (89U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_1                        (90U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_1                        (90U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_1                        (90U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_1                        (91U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_1                        (91U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_1                        (91U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_2                        (92U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_2                        (92U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_2                        (92U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_2                        (93U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_2                        (93U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_2                        (93U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_3                        (94U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_3                        (94U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_3                        (94U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_3                        (95U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_3                        (95U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_3                        (95U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_4                        (96U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_4                        (96U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_4                        (96U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_4                        (97U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_4                        (97U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_4                        (97U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_5                        (98U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_5                        (98U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_UV_OUT_N_TO_ESM_5                        (98U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_5                        (99U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_5                        (99U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_PRG0_POK_PGOOD_OV_OUT_N_TO_ESM_5                        (99U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_GPIOMUX_INTRTR0_OUTP_8                                  (120U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_GPIOMUX_INTRTR0_OUTP_8                                  (120U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_GPIOMUX_INTRTR0_OUTP_8                                  (120U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_GPIOMUX_INTRTR0_OUTP_9                                  (121U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_GPIOMUX_INTRTR0_OUTP_9                                  (121U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_GPIOMUX_INTRTR0_OUTP_9                                  (121U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_GPIOMUX_INTRTR0_OUTP_10                                 (122U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_GPIOMUX_INTRTR0_OUTP_10                                 (122U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_GPIOMUX_INTRTR0_OUTP_10                                 (122U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_GPIOMUX_INTRTR0_OUTP_11                                 (123U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_GPIOMUX_INTRTR0_OUTP_11                                 (123U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_GPIOMUX_INTRTR0_OUTP_11                                 (123U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_GPIOMUX_INTRTR0_OUTP_12                                 (124U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_GPIOMUX_INTRTR0_OUTP_12                                 (124U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_GPIOMUX_INTRTR0_OUTP_12                                 (124U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_GPIOMUX_INTRTR0_OUTP_13                                 (125U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_GPIOMUX_INTRTR0_OUTP_13                                 (125U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_GPIOMUX_INTRTR0_OUTP_13                                 (125U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_GPIOMUX_INTRTR0_OUTP_14                                 (126U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_GPIOMUX_INTRTR0_OUTP_14                                 (126U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_GPIOMUX_INTRTR0_OUTP_14                                 (126U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT0_WKUP_GPIOMUX_INTRTR0_OUTP_15                                 (127U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT1_WKUP_GPIOMUX_INTRTR0_OUTP_15                                 (127U)
#define CSLR_WKUP_ESM0_ESM_PLS_EVENT2_WKUP_GPIOMUX_INTRTR0_OUTP_15                                 (127U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_WKUP_ESM0_INTERRUPT_MAP_H_ */

