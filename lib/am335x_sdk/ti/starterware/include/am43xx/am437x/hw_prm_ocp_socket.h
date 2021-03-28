/*
* hw_prm_ocp_socket.h
*
* Register-level header file for PRM_OCP_SOCKET
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

#ifndef HW_PRM_OCP_SOCKET_H_
#define HW_PRM_OCP_SOCKET_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define PRCM_OCP_SOCKET_REVISION_PRM                                (0x0U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU                              (0x4U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU                               (0x8U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3                               (0xcU)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3                                (0x10U)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define PRCM_OCP_SOCKET_REVISION_PRM_CUSTOM_SHIFT                                       (6U)
#define PRCM_OCP_SOCKET_REVISION_PRM_CUSTOM_MASK                                        (0x000000c0U)
#define PRCM_OCP_SOCKET_REVISION_PRM_CUSTOM_STANDARD                                     (0U)

#define PRCM_OCP_SOCKET_REVISION_PRM_R_RTL_SHIFT                                        (11U)
#define PRCM_OCP_SOCKET_REVISION_PRM_R_RTL_MASK                                         (0x0000f800U)

#define PRCM_OCP_SOCKET_REVISION_PRM_FUNC_SHIFT                                         (16U)
#define PRCM_OCP_SOCKET_REVISION_PRM_FUNC_MASK                                          (0x0fff0000U)

#define PRCM_OCP_SOCKET_REVISION_PRM_SCHEME_SHIFT                                       (30U)
#define PRCM_OCP_SOCKET_REVISION_PRM_SCHEME_MASK                                        (0xc0000000U)
#define PRCM_OCP_SOCKET_REVISION_PRM_SCHEME_H08                                          (1U)
#define PRCM_OCP_SOCKET_REVISION_PRM_SCHEME_LEGACY                                       (0U)

#define PRCM_OCP_SOCKET_REVISION_PRM_X_MAJOR_SHIFT                                      (8U)
#define PRCM_OCP_SOCKET_REVISION_PRM_X_MAJOR_MASK                                       (0x00000700U)
#define PRCM_OCP_SOCKET_REVISION_PRM_X_MAJOR_RSVD1                                       (0U)
#define PRCM_OCP_SOCKET_REVISION_PRM_X_MAJOR_AEGIS1                                      (1U)

#define PRCM_OCP_SOCKET_REVISION_PRM_Y_MINOR_SHIFT                                      (0U)
#define PRCM_OCP_SOCKET_REVISION_PRM_Y_MINOR_MASK                                       (0x0000003fU)
#define PRCM_OCP_SOCKET_REVISION_PRM_Y_MINOR_ES1_0                                       (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_TRANSITION_ST_SHIFT                              (8U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_TRANSITION_ST_MASK                               (0x00000100U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_TRANSITION_ST_IRQ_TRU                             (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_TRANSITION_ST_IRQ_FAL                             (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_FORCEWKUP_ST_SHIFT                               (10U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_FORCEWKUP_ST_MASK                                (0x00000400U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_FORCEWKUP_ST_IRQ_TRU                              (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_FORCEWKUP_ST_IRQ_FAL                              (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_RECAL_ST_SHIFT                              (11U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_RECAL_ST_MASK                               (0x00000800U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_RECAL_ST_EN                                  (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_RECAL_ST_DIS                                 (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_CORE_RECAL_ST_SHIFT                         (12U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_CORE_RECAL_ST_MASK                          (0x00001000U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_CORE_RECAL_ST_EN                             (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_CORE_RECAL_ST_DIS                            (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_DISP_RECAL_ST_SHIFT                         (13U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_DISP_RECAL_ST_MASK                          (0x00002000U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_DISP_RECAL_ST_EN                             (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_DISP_RECAL_ST_DIS                            (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_DDR_RECAL_ST_SHIFT                          (14U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_DDR_RECAL_ST_MASK                           (0x00004000U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_DDR_RECAL_ST_EN                              (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_DDR_RECAL_ST_DIS                             (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_PER_RECAL_ST_SHIFT                          (15U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_PER_RECAL_ST_MASK                           (0x00008000U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_PER_RECAL_ST_EN                              (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_PER_RECAL_ST_DIS                             (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_IO_ST_SHIFT                                      (9U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_IO_ST_MASK                                       (0x00000200U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_IO_ST_IRQ_TRU                                     (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_IO_ST_IRQ_FAL                                     (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_FREQ_UPDATE_ST_SHIFT                             (0U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_FREQ_UPDATE_ST_MASK                              (0x00000001U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_FREQ_UPDATE_ST_IRQ_TRU                            (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_FREQ_UPDATE_ST_IRQ_FAL                            (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_EXTDEV_RECAL_ST_SHIFT                       (16U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_EXTDEV_RECAL_ST_MASK                        (0x00010000U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_EXTDEV_RECAL_ST_EN                           (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_MPU_DPLL_EXTDEV_RECAL_ST_DIS                          (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_TRANSITION_EN_SHIFT                               (8U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_TRANSITION_EN_MASK                                (0x00000100U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_TRANSITION_EN_IRQ_MSK                              (0U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_TRANSITION_EN_IRQ                                  (1U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_FORCEWKUP_EN_SHIFT                                (10U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_FORCEWKUP_EN_MASK                                 (0x00000400U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_FORCEWKUP_EN_IRQ_MSK                               (0U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_FORCEWKUP_EN_IRQ                                   (1U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_RECAL_EN_SHIFT                               (11U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_RECAL_EN_MASK                                (0x00000800U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_RECAL_EN                                      (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_RECAL_EN_DIS                                  (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_CORE_RECAL_EN_SHIFT                          (12U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_CORE_RECAL_EN_MASK                           (0x00001000U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_CORE_RECAL_EN                                 (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_CORE_RECAL_EN_DIS                             (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_PER_RECAL_EN_SHIFT                           (13U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_PER_RECAL_EN_MASK                            (0x00002000U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_PER_RECAL_EN                                  (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_PER_RECAL_EN_DIS                              (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_DDR_RECAL_EN_SHIFT                           (14U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_DDR_RECAL_EN_MASK                            (0x00004000U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_DDR_RECAL_EN                                  (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_DDR_RECAL_EN_DIS                              (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_DISP_RECAL_EN_SHIFT                          (15U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_DISP_RECAL_EN_MASK                           (0x00008000U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_DISP_RECAL_EN                                 (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_DISP_RECAL_EN_DIS                             (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_IO_EN_SHIFT                                       (9U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_IO_EN_MASK                                        (0x00000200U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_IO_EN_IRQ_MSK                                      (0U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_IO_EN_IRQ                                          (1U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_FREQ_UPDATE_EN_SHIFT                              (0U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_FREQ_UPDATE_EN_MASK                               (0x00000001U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_FREQ_UPDATE_EN_IRQ_MSK                             (0U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_FREQ_UPDATE_EN_IRQ                                 (1U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_EXTDEV_RECAL_EN_SHIFT                        (16U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_EXTDEV_RECAL_EN_MASK                         (0x00010000U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_EXTDEV_RECAL_EN                               (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_MPU_DPLL_EXTDEV_RECAL_EN_DIS                           (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_TRANSITION_ST_SHIFT                               (8U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_TRANSITION_ST_MASK                                (0x00000100U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_TRANSITION_ST_IRQ_TRU                              (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_TRANSITION_ST_IRQ_FAL                              (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_FORCEWKUP_ST_SHIFT                                (10U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_FORCEWKUP_ST_MASK                                 (0x00000400U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_FORCEWKUP_ST_IRQ_TRU                               (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_FORCEWKUP_ST_IRQ_FAL                               (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_MPU_RECAL_ST_SHIFT                           (11U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_MPU_RECAL_ST_MASK                            (0x00000800U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_MPU_RECAL_ST_EN                               (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_MPU_RECAL_ST_DIS                              (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_CORE_RECAL_ST_SHIFT                          (12U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_CORE_RECAL_ST_MASK                           (0x00001000U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_CORE_RECAL_ST_EN                              (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_CORE_RECAL_ST_DIS                             (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_DISP_RECAL_ST_SHIFT                          (13U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_DISP_RECAL_ST_MASK                           (0x00002000U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_DISP_RECAL_ST_EN                              (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_DISP_RECAL_ST_DIS                             (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_DDR_RECAL_ST_SHIFT                           (14U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_DDR_RECAL_ST_MASK                            (0x00004000U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_DDR_RECAL_ST_EN                               (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_DDR_RECAL_ST_DIS                              (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_PER_RECAL_ST_SHIFT                           (15U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_PER_RECAL_ST_MASK                            (0x00008000U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_PER_RECAL_ST_EN                               (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_PER_RECAL_ST_DIS                              (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_IO_ST_SHIFT                                       (9U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_IO_ST_MASK                                        (0x00000200U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_IO_ST_IRQ_TRU                                      (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_IO_ST_IRQ_FAL                                      (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_FREQ_UPDATE_ST_SHIFT                              (0U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_FREQ_UPDATE_ST_MASK                               (0x00000001U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_FREQ_UPDATE_ST_IRQ_TRU                             (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_FREQ_UPDATE_ST_IRQ_FAL                             (0U)

#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_EXTDEV_RECAL_ST_SHIFT                        (16U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_EXTDEV_RECAL_ST_MASK                         (0x00010000U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_EXTDEV_RECAL_ST_EN                            (1U)
#define PRCM_OCP_SOCKET_PRM_IRQSTS_M3_DPLL_EXTDEV_RECAL_ST_DIS                           (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_TRANSITION_EN_SHIFT                                (8U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_TRANSITION_EN_MASK                                 (0x00000100U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_TRANSITION_EN_IRQ_MSK                               (0U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_TRANSITION_EN_IRQ                                   (1U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_FORCEWKUP_EN_SHIFT                                 (10U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_FORCEWKUP_EN_MASK                                  (0x00000400U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_FORCEWKUP_EN_IRQ_MSK                                (0U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_FORCEWKUP_EN_IRQ                                    (1U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_MPU_RECAL_EN_SHIFT                            (11U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_MPU_RECAL_EN_MASK                             (0x00000800U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_MPU_RECAL_EN                                   (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_MPU_RECAL_EN_DIS                               (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_CORE_RECAL_EN_SHIFT                           (12U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_CORE_RECAL_EN_MASK                            (0x00001000U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_CORE_RECAL_EN                                  (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_CORE_RECAL_EN_DIS                              (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_PER_RECAL_EN_SHIFT                            (13U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_PER_RECAL_EN_MASK                             (0x00002000U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_PER_RECAL_EN                                   (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_PER_RECAL_EN_DIS                               (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_DDR_RECAL_EN_SHIFT                            (14U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_DDR_RECAL_EN_MASK                             (0x00004000U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_DDR_RECAL_EN                                   (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_DDR_RECAL_EN_DIS                               (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_DISP_RECAL_EN_SHIFT                           (15U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_DISP_RECAL_EN_MASK                            (0x00008000U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_DISP_RECAL_EN                                  (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_DISP_RECAL_EN_DIS                              (0U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_IO_EN_SHIFT                                        (9U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_IO_EN_MASK                                         (0x00000200U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_IO_EN_IRQ_MSK                                       (0U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_IO_EN_IRQ                                           (1U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_FREQ_UPDATE_EN_SHIFT                               (0U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_FREQ_UPDATE_EN_MASK                                (0x00000001U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_FREQ_UPDATE_EN_IRQ_MSK                              (0U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_FREQ_UPDATE_EN_IRQ                                  (1U)

#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_EXTDEV_RECAL_EN_SHIFT                         (16U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_EXTDEV_RECAL_EN_MASK                          (0x00010000U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_EXTDEV_RECAL_EN                                (1U)
#define PRCM_OCP_SOCKET_PRM_IRQEN_M3_DPLL_EXTDEV_RECAL_EN_DIS                            (0U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_PRM_OCP_SOCKET_H_ */

