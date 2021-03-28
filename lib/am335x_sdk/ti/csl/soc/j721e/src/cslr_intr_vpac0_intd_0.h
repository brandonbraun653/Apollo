/********************************************************************
*
* VPAC0_INTD_0 INTERRUPT MAP. header file
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
#ifndef CSLR_VPAC0_INTD_0_INTERRUPT_MAP_H_
#define CSLR_VPAC0_INTD_0_INTERRUPT_MAP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* List of intr sources for receiver: VPAC0_INTD_0
*/

#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_RAWFE_CFG_ERR_INTR_0                                (0U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_NSF4V_LINEMEM_CFG_ERR_INTR_0                        (1U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_GLBCE_CFG_ERR_INTR_0                                (2U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_FCFA_CFG_ERR_INTR_0                                 (3U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_FCC_CFG_ERR_INTR_0                                  (4U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_EE_CFG_ERR_0                                        (5U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_EE_SYNCOVF_ERR_0                                    (6U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_FCC_HIST_READ_ERR_INTR_0                            (7U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_NSF4V_HBLANK_ERR_INTR_0                             (8U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_NSF4V_VBLANK_ERR_INTR_0                             (9U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_GLBCE_HSYNC_ERR_INTR_0                              (10U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_GLBCE_VSYNC_ERR_INTR_0                              (11U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_GLBCE_VP_ERR_INTR_0                                 (12U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_LSE_CAL_VP_ERR_INTR_0                               (13U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_LSE_SL2_RD_ERR_INTR_0                               (14U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_LSE_SL2_WR_ERR_INTR_0                               (15U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_FCC_OUTIF_OVF_ERR_INTR_0                            (16U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_RAWFE_AEW_PULSE_INTR_0                              (17U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_RAWFE_AF_PULSE_INTR_0                               (18U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_RAWFE_H3A_PULSE_INTR_0                              (19U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_RAWFE_H3A_BUF_OVRFLOW_PULSE_INTR_0                  (20U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_GLBCE_FILT_START_INTR_0                             (21U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_GLBCE_FILT_DONE_INTR_0                              (22U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_LSE_FR_DONE_EVT_INTR_0                              (23U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VISS_0_LSE_OUT_FR_START_EVT_INTR_0                         (24U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_LDC_0_LDC_PIX_IBLK_OUTOFBOUND_INTR_0                       (32U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_LDC_0_LDC_MESH_IBLK_OUTOFBOUND_INTR_0                      (33U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_LDC_0_LDC_PIX_IBLK_MEMOVF_INTR_0                           (34U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_LDC_0_LDC_MESH_IBLK_MEMOVF_INTR_0                          (35U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_LDC_0_LDC_IFR_OUTOFBOUND_INTR_0                            (36U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_LDC_0_LDC_INT_SZOVF_INTR_0                                 (37U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_LDC_0_LDC_FR_DONE_EVT_INTR_0                               (38U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_LDC_0_LDC_SL2_WR_ERR_INTR_0                                (39U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_LDC_0_LDC_VBUSM_RD_ERR_INTR_0                              (40U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_MSC_0_MSC_LSE_FR_DONE_EVT_0_INTR_0                         (64U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_MSC_0_MSC_LSE_FR_DONE_EVT_1_INTR_0                         (65U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_MSC_0_MSC_LSE_SL2_RD_ERR_INTR_0                            (66U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_MSC_0_MSC_LSE_SL2_WR_ERR_INTR_0                            (67U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VPAC_NF_0_NF_FR_DONE_INTR_0                                (72U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VPAC_NF_0_NF_SL2_WR_ERR_INTR_0                             (73U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_VPAC_NF_0_NF_SL2_RD_ERR_INTR_0                             (74U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_PIPE_DONE_0                                          (96U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_PIPE_DONE_1                                          (97U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_PIPE_DONE_2                                          (98U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_PIPE_DONE_3                                          (99U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_PIPE_DONE_4                                          (100U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_PIPE_DONE_5                                          (101U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_PIPE_DONE_6                                          (102U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_TDONE_0                                              (103U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_TDONE_2                                              (105U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_TDONE_4                                              (107U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_TDONE_5                                              (108U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_TDONE_6                                              (109U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_SPARE_DEC_0                                          (110U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_SPARE_DEC_1                                          (111U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_SPARE_PEND_PULSE_0                                   (112U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_SPARE_PEND_LEVEL_0                                   (113U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_SPARE_PEND_PULSE_1                                   (114U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_SPARE_PEND_LEVEL_1                                   (115U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_WATCHDOGTIMER_ERR_0                                  (116U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_WATCHDOGTIMER_ERR_2                                  (118U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_WATCHDOGTIMER_ERR_4                                  (120U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_WATCHDOGTIMER_ERR_5                                  (121U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_HTS_0_WATCHDOGTIMER_ERR_6                                  (122U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_0                              (128U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_1                              (129U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_2                              (130U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_3                              (131U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_4                              (132U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_5                              (133U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_6                              (134U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_7                              (135U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_8                              (136U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_9                              (137U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_10                             (138U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_11                             (139U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_12                             (140U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_13                             (141U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_14                             (142U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_15                             (143U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_16                             (144U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_17                             (145U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_18                             (146U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_19                             (147U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_20                             (148U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_21                             (149U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_22                             (150U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_23                             (151U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_24                             (152U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_25                             (153U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_26                             (154U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_27                             (155U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_28                             (156U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_29                             (157U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_30                             (158U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_COMPLETE_INTR_31                             (159U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_0                             (160U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_1                             (161U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_2                             (162U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_3                             (163U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_4                             (164U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_5                             (165U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_6                             (166U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_7                             (167U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_8                             (168U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_9                             (169U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_10                            (170U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_11                            (171U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_12                            (172U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_13                            (173U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_14                            (174U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_15                            (175U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_16                            (176U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_17                            (177U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_18                            (178U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_19                            (179U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_20                            (180U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_21                            (181U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_22                            (182U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_23                            (183U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_24                            (184U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_25                            (185U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_26                            (186U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_27                            (187U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_28                            (188U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_29                            (189U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_30                            (190U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_31                            (191U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_32                            (192U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_33                            (193U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_34                            (194U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_35                            (195U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_36                            (196U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_37                            (197U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_38                            (198U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_39                            (199U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_40                            (200U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_41                            (201U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_42                            (202U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_43                            (203U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_44                            (204U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_45                            (205U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_46                            (206U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_47                            (207U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_48                            (208U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_49                            (209U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_50                            (210U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_51                            (211U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_52                            (212U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_53                            (213U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_54                            (214U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_55                            (215U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_56                            (216U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_57                            (217U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_58                            (218U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_59                            (219U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_60                            (220U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_61                            (221U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_62                            (222U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_COMPLETE_INTR_63                            (223U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_ERR_0                                        (224U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_ERR_0                                       (225U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_RT_0_DRU0_PROT_ERR_INTR_0                              (226U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_UTC_NRT_0_DRU1_PROT_ERR_INTR_0                             (227U)
#define CSLR_VPAC0_INTD_0_IP_INTR_VPAC0_CTSET_0_CTM_PULSE_INTR_0                                   (228U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_VPAC0_INTD_0_INTERRUPT_MAP_H_ */

