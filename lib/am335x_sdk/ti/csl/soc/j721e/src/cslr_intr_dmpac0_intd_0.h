/********************************************************************
*
* DMPAC0_INTD_0 INTERRUPT MAP. header file
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
#ifndef CSLR_DMPAC0_INTD_0_INTERRUPT_MAP_H_
#define CSLR_DMPAC0_INTD_0_INTERRUPT_MAP_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* List of intr sources for receiver: DMPAC0_INTD_0
*/

#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DOF_0_DOF_ROW_DONE_INTR_0                                (0U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DOF_0_DOF_FRAME_DONE_INTR_0                              (1U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DOF_0_DOF_READ_ERROR_INTR_0                              (2U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DOF_0_DOF_WRITE_ERROR_INTR_0                             (3U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DOF_0_DOF_MP0_RD_STATUS_ERROR_0                          (4U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_SDE_0_SDE_BLK_DONE_INTR_0                                (16U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_SDE_0_SDE_FRAME_DONE_INTR_0                              (17U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_SDE_0_SDE_READ_ERROR_INTR_0                              (18U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_SDE_0_SDE_WRITE_ERROR_INTR_0                             (19U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_FOCO_0_FOCO_FR_DONE_EVT_0                                (20U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_FOCO_0_FOCO_SL2_RD_ERR_0                                 (21U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_FOCO_0_FOCO_SL2_WR_ERR_0                                 (22U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_FOCO_1_FOCO_FR_DONE_EVT_0                                (23U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_FOCO_1_FOCO_SL2_RD_ERR_0                                 (24U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_FOCO_1_FOCO_SL2_WR_ERR_0                                 (25U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_PIPE_DONE_0                                        (32U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_PIPE_DONE_1                                        (33U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_PIPE_DONE_2                                        (34U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_PIPE_DONE_3                                        (35U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_SPARE_DEC_0                                        (40U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_SPARE_DEC_1                                        (41U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_SPARE_PEND_PULSE_0                                 (48U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_SPARE_PEND_LEVEL_0                                 (49U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_SPARE_PEND_PULSE_1                                 (50U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_SPARE_PEND_LEVEL_1                                 (51U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_TDONE_0                                            (56U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_TDONE_1                                            (57U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_TDONE_7                                            (58U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_TDONE_8                                            (59U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_WATCHDOGTIMER_ERR_0                                (64U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_WATCHDOGTIMER_ERR_1                                (65U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_WATCHDOGTIMER_ERR_7                                (66U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_HTS_0_WATCHDOGTIMER_ERR_8                                (67U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_0                                        (96U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_1                                        (97U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_2                                        (98U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_3                                        (99U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_4                                        (100U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_5                                        (101U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_6                                        (102U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_7                                        (103U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_8                                        (104U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_9                                        (105U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_10                                       (106U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_11                                       (107U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_12                                       (108U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_13                                       (109U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_14                                       (110U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_15                                       (111U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_16                                       (112U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_17                                       (113U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_18                                       (114U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_19                                       (115U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_20                                       (116U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_21                                       (117U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_22                                       (118U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_23                                       (119U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_24                                       (120U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_25                                       (121U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_26                                       (122U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_27                                       (123U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_28                                       (124U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_29                                       (125U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_30                                       (126U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_ERROR_31                                       (127U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_0                                     (128U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_1                                     (129U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_2                                     (130U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_3                                     (131U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_4                                     (132U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_5                                     (133U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_6                                     (134U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_7                                     (135U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_8                                     (136U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_9                                     (137U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_10                                    (138U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_11                                    (139U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_12                                    (140U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_13                                    (141U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_14                                    (142U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_15                                    (143U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_16                                    (144U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_17                                    (145U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_18                                    (146U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_19                                    (147U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_20                                    (148U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_21                                    (149U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_22                                    (150U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_23                                    (151U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_24                                    (152U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_25                                    (153U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_26                                    (154U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_27                                    (155U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_28                                    (156U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_29                                    (157U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_30                                    (158U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_COMPLETE_31                                    (159U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_0                              (160U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_1                              (161U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_2                              (162U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_3                              (163U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_4                              (164U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_5                              (165U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_6                              (166U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_7                              (167U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_8                              (168U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_9                              (169U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_10                             (170U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_11                             (171U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_12                             (172U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_13                             (173U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_14                             (174U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_15                             (175U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_16                             (176U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_17                             (177U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_18                             (178U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_19                             (179U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_20                             (180U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_21                             (181U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_22                             (182U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_23                             (183U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_24                             (184U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_25                             (185U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_26                             (186U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_27                             (187U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_28                             (188U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_29                             (189U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_30                             (190U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_LOCAL_OUT_EVENT_31                             (191U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_DRU_0_DRU_PROT_ERROR_0                                   (192U)
#define CSLR_DMPAC0_INTD_0_IP_INTR_DMPAC0_CTSET_0_CTSET_PULSE_0                                    (193U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_DMPAC0_INTD_0_INTERRUPT_MAP_H_ */

