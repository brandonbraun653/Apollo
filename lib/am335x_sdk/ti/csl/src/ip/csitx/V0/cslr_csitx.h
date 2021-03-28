/********************************************************************
 * Copyright (C) 2018 Texas Instruments Incorporated.
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
 *  Name        : cslr_csitx.h
*/
#ifndef CSLR_CSITX_H_
#define CSLR_CSITX_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : CSI2TX MMRs  CSI2TX is the core module of CSI_TX_IF
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t DEVICE_CONFIG;
    volatile uint32_t STATUS;
    volatile uint32_t IRQ;
    volatile uint32_t IRQ_MASK;
    volatile uint32_t DPHY_IRQ;
    volatile uint32_t DPHY_IRQ_MASK;
    volatile uint8_t  Resv_32[8];
    volatile uint32_t TX_CONF;
    volatile uint32_t WAIT_BURST_TIME;
    volatile uint32_t DPHY_CFG;
    volatile uint32_t DPHY_CLK_WAKEUP;
    volatile uint32_t DPHY_ULPS_WAKEUP;
    volatile uint8_t  Resv_64[12];
    volatile uint32_t VC0_CFG;
    volatile uint32_t VC1_CFG;
    volatile uint32_t VC2_CFG;
    volatile uint32_t VC3_CFG;
    volatile uint32_t VC4_CFG;
    volatile uint32_t VC5_CFG;
    volatile uint32_t VC6_CFG;
    volatile uint32_t VC7_CFG;
    volatile uint32_t VC8_CFG;
    volatile uint32_t VC9_CFG;
    volatile uint32_t VC10_CFG;
    volatile uint32_t VC11_CFG;
    volatile uint32_t VC12_CFG;
    volatile uint32_t VC13_CFG;
    volatile uint32_t VC14_CFG;
    volatile uint32_t VC15_CFG;
    volatile uint32_t DT0_CFG;
    volatile uint32_t DT0_FORMAT;
    volatile uint32_t DT1_CFG;
    volatile uint32_t DT1_FORMAT;
    volatile uint32_t DT2_CFG;
    volatile uint32_t DT2_FORMAT;
    volatile uint32_t DT3_CFG;
    volatile uint32_t DT3_FORMAT;
    volatile uint32_t DT4_CFG;
    volatile uint32_t DT4_FORMAT;
    volatile uint32_t DT5_CFG;
    volatile uint32_t DT5_FORMAT;
    volatile uint32_t DT6_CFG;
    volatile uint32_t DT6_FORMAT;
    volatile uint32_t DT7_CFG;
    volatile uint32_t DT7_FORMAT;
    volatile uint8_t  Resv_256[64];
    volatile uint32_t STREAM_IF_0_CFG;
    volatile uint32_t STREAM_IF_1_CFG;
    volatile uint32_t STREAM_IF_2_CFG;
    volatile uint32_t STREAM_IF_3_CFG;
    volatile uint32_t DEBUG_CFG;
    volatile uint32_t DEBUG_LN_FSM;
    volatile uint32_t DEBUG_CLK_LN_FSM;
    volatile uint32_t DEBUG_DATA_LN_FSM;
    volatile uint32_t DEBUG_PROT0_FSM;
    volatile uint32_t DEBUG_PROT1_FSM;
    volatile uint32_t DEBUG_PROT2_FSM;
    volatile uint32_t DEBUG_PROT3_FSM;
    volatile uint32_t DPHY_STATUS;
    volatile uint32_t DPHY_CFG1;
    volatile uint8_t  Resv_316[4];
    volatile uint32_t GENERIC;
    volatile uint8_t  Resv_512[192];
    volatile uint32_t ASF_INT_STATUS;
    volatile uint32_t ASF_INT_RAW_STATUS;
    volatile uint32_t ASF_INT_MASK;
    volatile uint32_t ASF_INT_TEST;
    volatile uint32_t ASF_FATAL_NONFATAL_SELECT;
    volatile uint8_t  Resv_544[12];
    volatile uint32_t ASF_SRAM_CORR_FAULT_STATUS;
    volatile uint32_t ASF_SRAM_UNCORR_FAULT_STATUS;
    volatile uint32_t ASF_SRAM_FAULT_STATS;
    volatile uint8_t  Resv_560[4];
    volatile uint32_t ASF_TRANS_TO_CTRL;
    volatile uint32_t ASF_TRANS_TO_FAULT_MASK;
    volatile uint32_t ASF_TRANS_TO_FAULT_STATUS;
    volatile uint8_t  Resv_576[4];
    volatile uint32_t ASF_PROTOCOL_FAULT_MASK;
    volatile uint32_t ASF_PROTOCOL_FAULT_STATUS;
    volatile uint8_t  Resv_4092[3508];
    volatile uint32_t ID_PROD_VER;
} CSL_csitxRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_CSITX_DEVICE_CONFIG                                                (0x00000000U)
#define CSL_CSITX_STATUS                                                       (0x00000004U)
#define CSL_CSITX_IRQ                                                          (0x00000008U)
#define CSL_CSITX_IRQ_MASK                                                     (0x0000000CU)
#define CSL_CSITX_DPHY_IRQ                                                     (0x00000010U)
#define CSL_CSITX_DPHY_IRQ_MASK                                                (0x00000014U)
#define CSL_CSITX_TX_CONF                                                      (0x00000020U)
#define CSL_CSITX_WAIT_BURST_TIME                                              (0x00000024U)
#define CSL_CSITX_DPHY_CFG                                                     (0x00000028U)
#define CSL_CSITX_DPHY_CLK_WAKEUP                                              (0x0000002CU)
#define CSL_CSITX_DPHY_ULPS_WAKEUP                                             (0x00000030U)
#define CSL_CSITX_VC0_CFG                                                      (0x00000040U)
#define CSL_CSITX_VC1_CFG                                                      (0x00000044U)
#define CSL_CSITX_VC2_CFG                                                      (0x00000048U)
#define CSL_CSITX_VC3_CFG                                                      (0x0000004CU)
#define CSL_CSITX_VC4_CFG                                                      (0x00000050U)
#define CSL_CSITX_VC5_CFG                                                      (0x00000054U)
#define CSL_CSITX_VC6_CFG                                                      (0x00000058U)
#define CSL_CSITX_VC7_CFG                                                      (0x0000005CU)
#define CSL_CSITX_VC8_CFG                                                      (0x00000060U)
#define CSL_CSITX_VC9_CFG                                                      (0x00000064U)
#define CSL_CSITX_VC10_CFG                                                     (0x00000068U)
#define CSL_CSITX_VC11_CFG                                                     (0x0000006CU)
#define CSL_CSITX_VC12_CFG                                                     (0x00000070U)
#define CSL_CSITX_VC13_CFG                                                     (0x00000074U)
#define CSL_CSITX_VC14_CFG                                                     (0x00000078U)
#define CSL_CSITX_VC15_CFG                                                     (0x0000007CU)
#define CSL_CSITX_DT0_CFG                                                      (0x00000080U)
#define CSL_CSITX_DT0_FORMAT                                                   (0x00000084U)
#define CSL_CSITX_DT1_CFG                                                      (0x00000088U)
#define CSL_CSITX_DT1_FORMAT                                                   (0x0000008CU)
#define CSL_CSITX_DT2_CFG                                                      (0x00000090U)
#define CSL_CSITX_DT2_FORMAT                                                   (0x00000094U)
#define CSL_CSITX_DT3_CFG                                                      (0x00000098U)
#define CSL_CSITX_DT3_FORMAT                                                   (0x0000009CU)
#define CSL_CSITX_DT4_CFG                                                      (0x000000A0U)
#define CSL_CSITX_DT4_FORMAT                                                   (0x000000A4U)
#define CSL_CSITX_DT5_CFG                                                      (0x000000A8U)
#define CSL_CSITX_DT5_FORMAT                                                   (0x000000ACU)
#define CSL_CSITX_DT6_CFG                                                      (0x000000B0U)
#define CSL_CSITX_DT6_FORMAT                                                   (0x000000B4U)
#define CSL_CSITX_DT7_CFG                                                      (0x000000B8U)
#define CSL_CSITX_DT7_FORMAT                                                   (0x000000BCU)
#define CSL_CSITX_STREAM_IF_0_CFG                                              (0x00000100U)
#define CSL_CSITX_STREAM_IF_1_CFG                                              (0x00000104U)
#define CSL_CSITX_STREAM_IF_2_CFG                                              (0x00000108U)
#define CSL_CSITX_STREAM_IF_3_CFG                                              (0x0000010CU)
#define CSL_CSITX_DEBUG_CFG                                                    (0x00000110U)
#define CSL_CSITX_DEBUG_LN_FSM                                                 (0x00000114U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM                                             (0x00000118U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM                                            (0x0000011CU)
#define CSL_CSITX_DEBUG_PROT0_FSM                                              (0x00000120U)
#define CSL_CSITX_DEBUG_PROT1_FSM                                              (0x00000124U)
#define CSL_CSITX_DEBUG_PROT2_FSM                                              (0x00000128U)
#define CSL_CSITX_DEBUG_PROT3_FSM                                              (0x0000012CU)
#define CSL_CSITX_DPHY_STATUS                                                  (0x00000130U)
#define CSL_CSITX_DPHY_CFG1                                                    (0x00000134U)
#define CSL_CSITX_GENERIC                                                      (0x0000013CU)
#define CSL_CSITX_ASF_INT_STATUS                                               (0x00000200U)
#define CSL_CSITX_ASF_INT_RAW_STATUS                                           (0x00000204U)
#define CSL_CSITX_ASF_INT_MASK                                                 (0x00000208U)
#define CSL_CSITX_ASF_INT_TEST                                                 (0x0000020CU)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT                                    (0x00000210U)
#define CSL_CSITX_ASF_SRAM_CORR_FAULT_STATUS                                   (0x00000220U)
#define CSL_CSITX_ASF_SRAM_UNCORR_FAULT_STATUS                                 (0x00000224U)
#define CSL_CSITX_ASF_SRAM_FAULT_STATS                                         (0x00000228U)
#define CSL_CSITX_ASF_TRANS_TO_CTRL                                            (0x00000230U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK                                      (0x00000234U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS                                    (0x00000238U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK                                      (0x00000240U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS                                    (0x00000244U)
#define CSL_CSITX_ID_PROD_VER                                                  (0x00000FFCU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* DEVICE_CONFIG */

#define CSL_CSITX_DEVICE_CONFIG_MAX_LANE_NB_MASK                               (0x00000007U)
#define CSL_CSITX_DEVICE_CONFIG_MAX_LANE_NB_SHIFT                              (0x00000000U)
#define CSL_CSITX_DEVICE_CONFIG_MAX_LANE_NB_MAX                                (0x00000007U)

#define CSL_CSITX_DEVICE_CONFIG_CDNS_PHY_PRESENT_MASK                          (0x00000008U)
#define CSL_CSITX_DEVICE_CONFIG_CDNS_PHY_PRESENT_SHIFT                         (0x00000003U)
#define CSL_CSITX_DEVICE_CONFIG_CDNS_PHY_PRESENT_MAX                           (0x00000001U)

#define CSL_CSITX_DEVICE_CONFIG_NUM_STREAMS_MASK                               (0x00000070U)
#define CSL_CSITX_DEVICE_CONFIG_NUM_STREAMS_SHIFT                              (0x00000004U)
#define CSL_CSITX_DEVICE_CONFIG_NUM_STREAMS_MAX                                (0x00000007U)

#define CSL_CSITX_DEVICE_CONFIG_DATAPATH_SIZE_MASK                             (0x00000180U)
#define CSL_CSITX_DEVICE_CONFIG_DATAPATH_SIZE_SHIFT                            (0x00000007U)
#define CSL_CSITX_DEVICE_CONFIG_DATAPATH_SIZE_MAX                              (0x00000003U)

#define CSL_CSITX_DEVICE_CONFIG_NUM_VCS_MASK                                   (0x00003E00U)
#define CSL_CSITX_DEVICE_CONFIG_NUM_VCS_SHIFT                                  (0x00000009U)
#define CSL_CSITX_DEVICE_CONFIG_NUM_VCS_MAX                                    (0x0000001FU)

#define CSL_CSITX_DEVICE_CONFIG_NUM_DTS_MASK                                   (0x0007C000U)
#define CSL_CSITX_DEVICE_CONFIG_NUM_DTS_SHIFT                                  (0x0000000EU)
#define CSL_CSITX_DEVICE_CONFIG_NUM_DTS_MAX                                    (0x0000001FU)

#define CSL_CSITX_DEVICE_CONFIG_ASF_PRESENT_MASK                               (0x00080000U)
#define CSL_CSITX_DEVICE_CONFIG_ASF_PRESENT_SHIFT                              (0x00000013U)
#define CSL_CSITX_DEVICE_CONFIG_ASF_PRESENT_MAX                                (0x00000001U)

/* STATUS */

#define CSL_CSITX_STATUS_BYPASS_MODE_ACTIVE_MASK                               (0x00000001U)
#define CSL_CSITX_STATUS_BYPASS_MODE_ACTIVE_SHIFT                              (0x00000000U)
#define CSL_CSITX_STATUS_BYPASS_MODE_ACTIVE_MAX                                (0x00000001U)

#define CSL_CSITX_STATUS_SOFT_RESET_ACTIVE_MASK                                (0x00000002U)
#define CSL_CSITX_STATUS_SOFT_RESET_ACTIVE_SHIFT                               (0x00000001U)
#define CSL_CSITX_STATUS_SOFT_RESET_ACTIVE_MAX                                 (0x00000001U)

#define CSL_CSITX_STATUS_CONFIGURATION_ACTIVE_MASK                             (0x00000004U)
#define CSL_CSITX_STATUS_CONFIGURATION_ACTIVE_SHIFT                            (0x00000002U)
#define CSL_CSITX_STATUS_CONFIGURATION_ACTIVE_MAX                              (0x00000001U)

#define CSL_CSITX_STATUS_RESERVED_3_MASK                                       (0x00000008U)
#define CSL_CSITX_STATUS_RESERVED_3_SHIFT                                      (0x00000003U)
#define CSL_CSITX_STATUS_RESERVED_3_MAX                                        (0x00000001U)

#define CSL_CSITX_STATUS_FRAME_TRANSMISSION_ACTIVE_MASK                        (0x00000010U)
#define CSL_CSITX_STATUS_FRAME_TRANSMISSION_ACTIVE_SHIFT                       (0x00000004U)
#define CSL_CSITX_STATUS_FRAME_TRANSMISSION_ACTIVE_MAX                         (0x00000001U)

#define CSL_CSITX_STATUS_HS_MODE_ACTIVE_MASK                                   (0x00000020U)
#define CSL_CSITX_STATUS_HS_MODE_ACTIVE_SHIFT                                  (0x00000005U)
#define CSL_CSITX_STATUS_HS_MODE_ACTIVE_MAX                                    (0x00000001U)

#define CSL_CSITX_STATUS_ULP_MODE_ACTIVE_MASK                                  (0x00000040U)
#define CSL_CSITX_STATUS_ULP_MODE_ACTIVE_SHIFT                                 (0x00000006U)
#define CSL_CSITX_STATUS_ULP_MODE_ACTIVE_MAX                                   (0x00000001U)

#define CSL_CSITX_STATUS_UNUSED_MASK                                           (0xFFFFFF80U)
#define CSL_CSITX_STATUS_UNUSED_SHIFT                                          (0x00000007U)
#define CSL_CSITX_STATUS_UNUSED_MAX                                            (0x01FFFFFFU)

/* IRQ */

#define CSL_CSITX_IRQ_FRAME_START_IRQ0_MASK                                    (0x00000001U)
#define CSL_CSITX_IRQ_FRAME_START_IRQ0_SHIFT                                   (0x00000000U)
#define CSL_CSITX_IRQ_FRAME_START_IRQ0_MAX                                     (0x00000001U)

#define CSL_CSITX_IRQ_FRAME_END_IRQ0_MASK                                      (0x00000002U)
#define CSL_CSITX_IRQ_FRAME_END_IRQ0_SHIFT                                     (0x00000001U)
#define CSL_CSITX_IRQ_FRAME_END_IRQ0_MAX                                       (0x00000001U)

#define CSL_CSITX_IRQ_LINE_START_IRQ0_MASK                                     (0x00000004U)
#define CSL_CSITX_IRQ_LINE_START_IRQ0_SHIFT                                    (0x00000002U)
#define CSL_CSITX_IRQ_LINE_START_IRQ0_MAX                                      (0x00000001U)

#define CSL_CSITX_IRQ_LINE_END_IRQ0_MASK                                       (0x00000008U)
#define CSL_CSITX_IRQ_LINE_END_IRQ0_SHIFT                                      (0x00000003U)
#define CSL_CSITX_IRQ_LINE_END_IRQ0_MAX                                        (0x00000001U)

#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ0_MASK                                 (0x00000010U)
#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ0_SHIFT                                (0x00000004U)
#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ0_MAX                                  (0x00000001U)

#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ0_MASK                                  (0x00000020U)
#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ0_SHIFT                                 (0x00000005U)
#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ0_MAX                                   (0x00000001U)

#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ0_MASK                            (0x00000040U)
#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ0_SHIFT                           (0x00000006U)
#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ0_MAX                             (0x00000001U)

#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR0_MASK                                  (0x00000080U)
#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR0_SHIFT                                 (0x00000007U)
#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR0_MAX                                   (0x00000001U)

#define CSL_CSITX_IRQ_FRAME_START_IRQ1_MASK                                    (0x00000100U)
#define CSL_CSITX_IRQ_FRAME_START_IRQ1_SHIFT                                   (0x00000008U)
#define CSL_CSITX_IRQ_FRAME_START_IRQ1_MAX                                     (0x00000001U)

#define CSL_CSITX_IRQ_FRAME_END_IRQ1_MASK                                      (0x00000200U)
#define CSL_CSITX_IRQ_FRAME_END_IRQ1_SHIFT                                     (0x00000009U)
#define CSL_CSITX_IRQ_FRAME_END_IRQ1_MAX                                       (0x00000001U)

#define CSL_CSITX_IRQ_LINE_START_IRQ1_MASK                                     (0x00000400U)
#define CSL_CSITX_IRQ_LINE_START_IRQ1_SHIFT                                    (0x0000000AU)
#define CSL_CSITX_IRQ_LINE_START_IRQ1_MAX                                      (0x00000001U)

#define CSL_CSITX_IRQ_LINE_END_IRQ1_MASK                                       (0x00000800U)
#define CSL_CSITX_IRQ_LINE_END_IRQ1_SHIFT                                      (0x0000000BU)
#define CSL_CSITX_IRQ_LINE_END_IRQ1_MAX                                        (0x00000001U)

#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ1_MASK                                 (0x00001000U)
#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ1_SHIFT                                (0x0000000CU)
#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ1_MAX                                  (0x00000001U)

#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ1_MASK                                  (0x00002000U)
#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ1_SHIFT                                 (0x0000000DU)
#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ1_MAX                                   (0x00000001U)

#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ1_MASK                            (0x00004000U)
#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ1_SHIFT                           (0x0000000EU)
#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ1_MAX                             (0x00000001U)

#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR1_MASK                                  (0x00008000U)
#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR1_SHIFT                                 (0x0000000FU)
#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR1_MAX                                   (0x00000001U)

#define CSL_CSITX_IRQ_FRAME_START_IRQ2_MASK                                    (0x00010000U)
#define CSL_CSITX_IRQ_FRAME_START_IRQ2_SHIFT                                   (0x00000010U)
#define CSL_CSITX_IRQ_FRAME_START_IRQ2_MAX                                     (0x00000001U)

#define CSL_CSITX_IRQ_FRAME_END_IRQ2_MASK                                      (0x00020000U)
#define CSL_CSITX_IRQ_FRAME_END_IRQ2_SHIFT                                     (0x00000011U)
#define CSL_CSITX_IRQ_FRAME_END_IRQ2_MAX                                       (0x00000001U)

#define CSL_CSITX_IRQ_LINE_START_IRQ2_MASK                                     (0x00040000U)
#define CSL_CSITX_IRQ_LINE_START_IRQ2_SHIFT                                    (0x00000012U)
#define CSL_CSITX_IRQ_LINE_START_IRQ2_MAX                                      (0x00000001U)

#define CSL_CSITX_IRQ_LINE_END_IRQ2_MASK                                       (0x00080000U)
#define CSL_CSITX_IRQ_LINE_END_IRQ2_SHIFT                                      (0x00000013U)
#define CSL_CSITX_IRQ_LINE_END_IRQ2_MAX                                        (0x00000001U)

#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ2_MASK                                 (0x00100000U)
#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ2_SHIFT                                (0x00000014U)
#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ2_MAX                                  (0x00000001U)

#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ2_MASK                                  (0x00200000U)
#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ2_SHIFT                                 (0x00000015U)
#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ2_MAX                                   (0x00000001U)

#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ2_MASK                            (0x00400000U)
#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ2_SHIFT                           (0x00000016U)
#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ2_MAX                             (0x00000001U)

#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR2_MASK                                  (0x00800000U)
#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR2_SHIFT                                 (0x00000017U)
#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR2_MAX                                   (0x00000001U)

#define CSL_CSITX_IRQ_FRAME_START_IRQ3_MASK                                    (0x01000000U)
#define CSL_CSITX_IRQ_FRAME_START_IRQ3_SHIFT                                   (0x00000018U)
#define CSL_CSITX_IRQ_FRAME_START_IRQ3_MAX                                     (0x00000001U)

#define CSL_CSITX_IRQ_FRAME_END_IRQ3_MASK                                      (0x02000000U)
#define CSL_CSITX_IRQ_FRAME_END_IRQ3_SHIFT                                     (0x00000019U)
#define CSL_CSITX_IRQ_FRAME_END_IRQ3_MAX                                       (0x00000001U)

#define CSL_CSITX_IRQ_LINE_START_IRQ3_MASK                                     (0x04000000U)
#define CSL_CSITX_IRQ_LINE_START_IRQ3_SHIFT                                    (0x0000001AU)
#define CSL_CSITX_IRQ_LINE_START_IRQ3_MAX                                      (0x00000001U)

#define CSL_CSITX_IRQ_LINE_END_IRQ3_MASK                                       (0x08000000U)
#define CSL_CSITX_IRQ_LINE_END_IRQ3_SHIFT                                      (0x0000001BU)
#define CSL_CSITX_IRQ_LINE_END_IRQ3_MAX                                        (0x00000001U)

#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ3_MASK                                 (0x10000000U)
#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ3_SHIFT                                (0x0000001CU)
#define CSL_CSITX_IRQ_FIFO_UNDERFLOW_IRQ3_MAX                                  (0x00000001U)

#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ3_MASK                                  (0x20000000U)
#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ3_SHIFT                                 (0x0000001DU)
#define CSL_CSITX_IRQ_DATA_FLOW_ERR_IRQ3_MAX                                   (0x00000001U)

#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ3_MASK                            (0x40000000U)
#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ3_SHIFT                           (0x0000001EU)
#define CSL_CSITX_IRQ_BYTE_COUNT_MISMATCH_IRQ3_MAX                             (0x00000001U)

#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR3_MASK                                  (0x80000000U)
#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR3_SHIFT                                 (0x0000001FU)
#define CSL_CSITX_IRQ_LINE_NUMBER_ERROR3_MAX                                   (0x00000001U)

/* IRQ_MASK */

#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ0_MASK                          (0x00000001U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ0_SHIFT                         (0x00000000U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ0_MAX                           (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ0_MASK                            (0x00000002U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ0_SHIFT                           (0x00000001U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ0_MAX                             (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ0_MASK                           (0x00000004U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ0_SHIFT                          (0x00000002U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ0_MAX                            (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ0_MASK                             (0x00000008U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ0_SHIFT                            (0x00000003U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ0_MAX                              (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ0_MASK                       (0x00000010U)
#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ0_SHIFT                      (0x00000004U)
#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ0_MAX                        (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ0_MASK                        (0x00000020U)
#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ0_SHIFT                       (0x00000005U)
#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ0_MAX                         (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ0_MASK                  (0x00000040U)
#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ0_SHIFT                 (0x00000006U)
#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ0_MAX                   (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR0_MASK                        (0x00000080U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR0_SHIFT                       (0x00000007U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR0_MAX                         (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ1_MASK                          (0x00000100U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ1_SHIFT                         (0x00000008U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ1_MAX                           (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ1_MASK                            (0x00000200U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ1_SHIFT                           (0x00000009U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ1_MAX                             (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ1_MASK                           (0x00000400U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ1_SHIFT                          (0x0000000AU)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ1_MAX                            (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ1_MASK                             (0x00000800U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ1_SHIFT                            (0x0000000BU)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ1_MAX                              (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ1_MASK                       (0x00001000U)
#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ1_SHIFT                      (0x0000000CU)
#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ1_MAX                        (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ1_MASK                        (0x00002000U)
#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ1_SHIFT                       (0x0000000DU)
#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ1_MAX                         (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ1_MASK                  (0x00004000U)
#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ1_SHIFT                 (0x0000000EU)
#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ1_MAX                   (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR1_MASK                        (0x00008000U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR1_SHIFT                       (0x0000000FU)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR1_MAX                         (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ2_MASK                          (0x00010000U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ2_SHIFT                         (0x00000010U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ2_MAX                           (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ2_MASK                            (0x00020000U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ2_SHIFT                           (0x00000011U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ2_MAX                             (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ2_MASK                           (0x00040000U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ2_SHIFT                          (0x00000012U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ2_MAX                            (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ2_MASK                             (0x00080000U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ2_SHIFT                            (0x00000013U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ2_MAX                              (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ2_MASK                       (0x00100000U)
#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ2_SHIFT                      (0x00000014U)
#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ2_MAX                        (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ2_MASK                        (0x00200000U)
#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ2_SHIFT                       (0x00000015U)
#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ2_MAX                         (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ2_MASK                  (0x00400000U)
#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ2_SHIFT                 (0x00000016U)
#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ2_MAX                   (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR2_MASK                        (0x00800000U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR2_SHIFT                       (0x00000017U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR2_MAX                         (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ3_MASK                          (0x01000000U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ3_SHIFT                         (0x00000018U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_START_IRQ3_MAX                           (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ3_MASK                            (0x02000000U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ3_SHIFT                           (0x00000019U)
#define CSL_CSITX_IRQ_MASK_MASK_FRAME_END_IRQ3_MAX                             (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ3_MASK                           (0x04000000U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ3_SHIFT                          (0x0000001AU)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_START_IRQ3_MAX                            (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ3_MASK                             (0x08000000U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ3_SHIFT                            (0x0000001BU)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_END_IRQ3_MAX                              (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ3_MASK                       (0x10000000U)
#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ3_SHIFT                      (0x0000001CU)
#define CSL_CSITX_IRQ_MASK_MASK_FIFO_UNDERFLOW_IRQ3_MAX                        (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ3_MASK                        (0x20000000U)
#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ3_SHIFT                       (0x0000001DU)
#define CSL_CSITX_IRQ_MASK_MASK_DATA_FLOW_ERR_IRQ3_MAX                         (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ3_MASK                  (0x40000000U)
#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ3_SHIFT                 (0x0000001EU)
#define CSL_CSITX_IRQ_MASK_MASK_BYTE_COUNT_MISMATCH_IRQ3_MAX                   (0x00000001U)

#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR3_MASK                        (0x80000000U)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR3_SHIFT                       (0x0000001FU)
#define CSL_CSITX_IRQ_MASK_MASK_LINE_NUMBER_ERROR3_MAX                         (0x00000001U)

/* DPHY_IRQ */

#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX0_IRQ_MASK                               (0x00000010U)
#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX0_IRQ_SHIFT                              (0x00000004U)
#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX0_IRQ_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX1_IRQ_MASK                               (0x00000020U)
#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX1_IRQ_SHIFT                              (0x00000005U)
#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX1_IRQ_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX2_IRQ_MASK                               (0x00000040U)
#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX2_IRQ_SHIFT                              (0x00000006U)
#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX2_IRQ_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX3_IRQ_MASK                               (0x00000080U)
#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX3_IRQ_SHIFT                              (0x00000007U)
#define CSL_CSITX_DPHY_IRQ_ERR_SYNC_TX3_IRQ_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX0_IRQ_MASK                                (0x00000100U)
#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX0_IRQ_SHIFT                               (0x00000008U)
#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX0_IRQ_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX1_IRQ_MASK                                (0x00000200U)
#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX1_IRQ_SHIFT                               (0x00000009U)
#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX1_IRQ_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX2_IRQ_MASK                                (0x00000400U)
#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX2_IRQ_SHIFT                               (0x0000000AU)
#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX2_IRQ_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX3_IRQ_MASK                                (0x00000800U)
#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX3_IRQ_SHIFT                               (0x0000000BU)
#define CSL_CSITX_DPHY_IRQ_ERR_ESC_TX3_IRQ_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX0_IRQ_MASK                               (0x00001000U)
#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX0_IRQ_SHIFT                              (0x0000000CU)
#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX0_IRQ_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX1_IRQ_MASK                               (0x00002000U)
#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX1_IRQ_SHIFT                              (0x0000000DU)
#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX1_IRQ_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX2_IRQ_MASK                               (0x00004000U)
#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX2_IRQ_SHIFT                              (0x0000000EU)
#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX2_IRQ_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX3_IRQ_MASK                               (0x00008000U)
#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX3_IRQ_SHIFT                              (0x0000000FU)
#define CSL_CSITX_DPHY_IRQ_ERR_CTRL_TX3_IRQ_MAX                                (0x00000001U)

/* DPHY_IRQ_MASK */

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX0_IRQ_MASK                     (0x00000010U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX0_IRQ_SHIFT                    (0x00000004U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX0_IRQ_MAX                      (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX1_IRQ_MASK                     (0x00000020U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX1_IRQ_SHIFT                    (0x00000005U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX1_IRQ_MAX                      (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX2_IRQ_MASK                     (0x00000040U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX2_IRQ_SHIFT                    (0x00000006U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX2_IRQ_MAX                      (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX3_IRQ_MASK                     (0x00000080U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX3_IRQ_SHIFT                    (0x00000007U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_SYNC_TX3_IRQ_MAX                      (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX0_IRQ_MASK                      (0x00000100U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX0_IRQ_SHIFT                     (0x00000008U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX0_IRQ_MAX                       (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX1_IRQ_MASK                      (0x00000200U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX1_IRQ_SHIFT                     (0x00000009U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX1_IRQ_MAX                       (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX2_IRQ_MASK                      (0x00000400U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX2_IRQ_SHIFT                     (0x0000000AU)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX2_IRQ_MAX                       (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX3_IRQ_MASK                      (0x00000800U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX3_IRQ_SHIFT                     (0x0000000BU)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_ESC_TX3_IRQ_MAX                       (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX0_IRQ_MASK                     (0x00001000U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX0_IRQ_SHIFT                    (0x0000000CU)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX0_IRQ_MAX                      (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX1_IRQ_MASK                     (0x00002000U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX1_IRQ_SHIFT                    (0x0000000DU)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX1_IRQ_MAX                      (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX2_IRQ_MASK                     (0x00004000U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX2_IRQ_SHIFT                    (0x0000000EU)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX2_IRQ_MAX                      (0x00000001U)

#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX3_IRQ_MASK                     (0x00008000U)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX3_IRQ_SHIFT                    (0x0000000FU)
#define CSL_CSITX_DPHY_IRQ_MASK_MASK_ERR_CTRL_TX3_IRQ_MAX                      (0x00000001U)

/* TX_CONF */

#define CSL_CSITX_TX_CONF_BYPASS_MODE_ENABLE_MASK                              (0x00000001U)
#define CSL_CSITX_TX_CONF_BYPASS_MODE_ENABLE_SHIFT                             (0x00000000U)
#define CSL_CSITX_TX_CONF_BYPASS_MODE_ENABLE_MAX                               (0x00000001U)

#define CSL_CSITX_TX_CONF_SOFT_RESET_REQUEST_MASK                              (0x00000002U)
#define CSL_CSITX_TX_CONF_SOFT_RESET_REQUEST_SHIFT                             (0x00000001U)
#define CSL_CSITX_TX_CONF_SOFT_RESET_REQUEST_MAX                               (0x00000001U)

#define CSL_CSITX_TX_CONF_CONFIGURATION_REQUEST_MASK                           (0x00000004U)
#define CSL_CSITX_TX_CONF_CONFIGURATION_REQUEST_SHIFT                          (0x00000002U)
#define CSL_CSITX_TX_CONF_CONFIGURATION_REQUEST_MAX                            (0x00000001U)

#define CSL_CSITX_TX_CONF_IRQ_ENABLE_MASK                                      (0x80000000U)
#define CSL_CSITX_TX_CONF_IRQ_ENABLE_SHIFT                                     (0x0000001FU)
#define CSL_CSITX_TX_CONF_IRQ_ENABLE_MAX                                       (0x00000001U)

/* WAIT_BURST_TIME */

#define CSL_CSITX_WAIT_BURST_TIME_WAIT_BURST_TIME_CNT_MASK                     (0x000000FFU)
#define CSL_CSITX_WAIT_BURST_TIME_WAIT_BURST_TIME_CNT_SHIFT                    (0x00000000U)
#define CSL_CSITX_WAIT_BURST_TIME_WAIT_BURST_TIME_CNT_MAX                      (0x000000FFU)

#define CSL_CSITX_WAIT_BURST_TIME_TX_CLOCK_EXIT_TIME_MASK                      (0x00FF0000U)
#define CSL_CSITX_WAIT_BURST_TIME_TX_CLOCK_EXIT_TIME_SHIFT                     (0x00000010U)
#define CSL_CSITX_WAIT_BURST_TIME_TX_CLOCK_EXIT_TIME_MAX                       (0x000000FFU)

/* DPHY_CFG */

#define CSL_CSITX_DPHY_CFG_DPHY_LN_0_ENABLE_MASK                               (0x00000001U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_0_ENABLE_SHIFT                              (0x00000000U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_0_ENABLE_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_LN_1_ENABLE_MASK                               (0x00000002U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_1_ENABLE_SHIFT                              (0x00000001U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_1_ENABLE_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_LN_2_ENABLE_MASK                               (0x00000004U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_2_ENABLE_SHIFT                              (0x00000002U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_2_ENABLE_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_LN_3_ENABLE_MASK                               (0x00000008U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_3_ENABLE_SHIFT                              (0x00000003U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_3_ENABLE_MAX                                (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_CLK_ENABLE_MASK                                (0x00000010U)
#define CSL_CSITX_DPHY_CFG_DPHY_CLK_ENABLE_SHIFT                               (0x00000004U)
#define CSL_CSITX_DPHY_CFG_DPHY_CLK_ENABLE_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_MODE_MASK                                      (0x00000300U)
#define CSL_CSITX_DPHY_CFG_DPHY_MODE_SHIFT                                     (0x00000008U)
#define CSL_CSITX_DPHY_CFG_DPHY_MODE_MAX                                       (0x00000003U)

#define CSL_CSITX_DPHY_CFG_DPHY_CLOCK_MODE_MASK                                (0x00000400U)
#define CSL_CSITX_DPHY_CFG_DPHY_CLOCK_MODE_SHIFT                               (0x0000000AU)
#define CSL_CSITX_DPHY_CFG_DPHY_CLOCK_MODE_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_CAL_ENABLE_MASK                                (0x00000800U)
#define CSL_CSITX_DPHY_CFG_DPHY_CAL_ENABLE_SHIFT                               (0x0000000BU)
#define CSL_CSITX_DPHY_CFG_DPHY_CAL_ENABLE_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_LN_0_RESET_MASK                                (0x00001000U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_0_RESET_SHIFT                               (0x0000000CU)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_0_RESET_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_LN_1_RESET_MASK                                (0x00002000U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_1_RESET_SHIFT                               (0x0000000DU)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_1_RESET_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_LN_2_RESET_MASK                                (0x00004000U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_2_RESET_SHIFT                               (0x0000000EU)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_2_RESET_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_LN_3_RESET_MASK                                (0x00008000U)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_3_RESET_SHIFT                               (0x0000000FU)
#define CSL_CSITX_DPHY_CFG_DPHY_LN_3_RESET_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_CFG_DPHY_CLK_RESET_MASK                                 (0x00010000U)
#define CSL_CSITX_DPHY_CFG_DPHY_CLK_RESET_SHIFT                                (0x00000010U)
#define CSL_CSITX_DPHY_CFG_DPHY_CLK_RESET_MAX                                  (0x00000001U)

/* DPHY_CLK_WAKEUP */

#define CSL_CSITX_DPHY_CLK_WAKEUP_ULPS_CLK_LANE_WAKEUP_MASK                    (0x0000FFFFU)
#define CSL_CSITX_DPHY_CLK_WAKEUP_ULPS_CLK_LANE_WAKEUP_SHIFT                   (0x00000000U)
#define CSL_CSITX_DPHY_CLK_WAKEUP_ULPS_CLK_LANE_WAKEUP_MAX                     (0x0000FFFFU)

/* DPHY_ULPS_WAKEUP */

#define CSL_CSITX_DPHY_ULPS_WAKEUP_ULPS_DATA_LANE_WAKEUP_MASK                  (0x0000FFFFU)
#define CSL_CSITX_DPHY_ULPS_WAKEUP_ULPS_DATA_LANE_WAKEUP_SHIFT                 (0x00000000U)
#define CSL_CSITX_DPHY_ULPS_WAKEUP_ULPS_DATA_LANE_WAKEUP_MAX                   (0x0000FFFFU)

/* VC0_CFG */

#define CSL_CSITX_VC0_CFG_VC_0_FRAME_COUNT_EN_MASK                             (0x00000001U)
#define CSL_CSITX_VC0_CFG_VC_0_FRAME_COUNT_EN_SHIFT                            (0x00000000U)
#define CSL_CSITX_VC0_CFG_VC_0_FRAME_COUNT_EN_MAX                              (0x00000001U)

#define CSL_CSITX_VC0_CFG_VC_0_MAX_FRAME_NUMBER_MASK                           (0xFFFF0000U)
#define CSL_CSITX_VC0_CFG_VC_0_MAX_FRAME_NUMBER_SHIFT                          (0x00000010U)
#define CSL_CSITX_VC0_CFG_VC_0_MAX_FRAME_NUMBER_MAX                            (0x0000FFFFU)

/* VC1_CFG */

#define CSL_CSITX_VC1_CFG_VC_1_FRAME_COUNT_EN_MASK                             (0x00000001U)
#define CSL_CSITX_VC1_CFG_VC_1_FRAME_COUNT_EN_SHIFT                            (0x00000000U)
#define CSL_CSITX_VC1_CFG_VC_1_FRAME_COUNT_EN_MAX                              (0x00000001U)

#define CSL_CSITX_VC1_CFG_VC_1_MAX_FRAME_NUMBER_MASK                           (0xFFFF0000U)
#define CSL_CSITX_VC1_CFG_VC_1_MAX_FRAME_NUMBER_SHIFT                          (0x00000010U)
#define CSL_CSITX_VC1_CFG_VC_1_MAX_FRAME_NUMBER_MAX                            (0x0000FFFFU)

/* VC2_CFG */

#define CSL_CSITX_VC2_CFG_VC_2_FRAME_COUNT_EN_MASK                             (0x00000001U)
#define CSL_CSITX_VC2_CFG_VC_2_FRAME_COUNT_EN_SHIFT                            (0x00000000U)
#define CSL_CSITX_VC2_CFG_VC_2_FRAME_COUNT_EN_MAX                              (0x00000001U)

#define CSL_CSITX_VC2_CFG_VC_2_MAX_FRAME_NUMBER_MASK                           (0xFFFF0000U)
#define CSL_CSITX_VC2_CFG_VC_2_MAX_FRAME_NUMBER_SHIFT                          (0x00000010U)
#define CSL_CSITX_VC2_CFG_VC_2_MAX_FRAME_NUMBER_MAX                            (0x0000FFFFU)

/* VC3_CFG */

#define CSL_CSITX_VC3_CFG_VC_3_FRAME_COUNT_EN_MASK                             (0x00000001U)
#define CSL_CSITX_VC3_CFG_VC_3_FRAME_COUNT_EN_SHIFT                            (0x00000000U)
#define CSL_CSITX_VC3_CFG_VC_3_FRAME_COUNT_EN_MAX                              (0x00000001U)

#define CSL_CSITX_VC3_CFG_VC_3_MAX_FRAME_NUMBER_MASK                           (0xFFFF0000U)
#define CSL_CSITX_VC3_CFG_VC_3_MAX_FRAME_NUMBER_SHIFT                          (0x00000010U)
#define CSL_CSITX_VC3_CFG_VC_3_MAX_FRAME_NUMBER_MAX                            (0x0000FFFFU)

/* VC4_CFG */

#define CSL_CSITX_VC4_CFG_VC_4_FRAME_COUNT_EN_MASK                             (0x00000001U)
#define CSL_CSITX_VC4_CFG_VC_4_FRAME_COUNT_EN_SHIFT                            (0x00000000U)
#define CSL_CSITX_VC4_CFG_VC_4_FRAME_COUNT_EN_MAX                              (0x00000001U)

#define CSL_CSITX_VC4_CFG_VC_4_MAX_FRAME_NUMBER_MASK                           (0xFFFF0000U)
#define CSL_CSITX_VC4_CFG_VC_4_MAX_FRAME_NUMBER_SHIFT                          (0x00000010U)
#define CSL_CSITX_VC4_CFG_VC_4_MAX_FRAME_NUMBER_MAX                            (0x0000FFFFU)

/* VC5_CFG */

#define CSL_CSITX_VC5_CFG_VC_5_FRAME_COUNT_EN_MASK                             (0x00000001U)
#define CSL_CSITX_VC5_CFG_VC_5_FRAME_COUNT_EN_SHIFT                            (0x00000000U)
#define CSL_CSITX_VC5_CFG_VC_5_FRAME_COUNT_EN_MAX                              (0x00000001U)

#define CSL_CSITX_VC5_CFG_VC_5_MAX_FRAME_NUMBER_MASK                           (0xFFFF0000U)
#define CSL_CSITX_VC5_CFG_VC_5_MAX_FRAME_NUMBER_SHIFT                          (0x00000010U)
#define CSL_CSITX_VC5_CFG_VC_5_MAX_FRAME_NUMBER_MAX                            (0x0000FFFFU)

/* VC6_CFG */

#define CSL_CSITX_VC6_CFG_VC_6_FRAME_COUNT_EN_MASK                             (0x00000001U)
#define CSL_CSITX_VC6_CFG_VC_6_FRAME_COUNT_EN_SHIFT                            (0x00000000U)
#define CSL_CSITX_VC6_CFG_VC_6_FRAME_COUNT_EN_MAX                              (0x00000001U)

#define CSL_CSITX_VC6_CFG_VC_6_MAX_FRAME_NUMBER_MASK                           (0xFFFF0000U)
#define CSL_CSITX_VC6_CFG_VC_6_MAX_FRAME_NUMBER_SHIFT                          (0x00000010U)
#define CSL_CSITX_VC6_CFG_VC_6_MAX_FRAME_NUMBER_MAX                            (0x0000FFFFU)

/* VC7_CFG */

#define CSL_CSITX_VC7_CFG_VC_7_FRAME_COUNT_EN_MASK                             (0x00000001U)
#define CSL_CSITX_VC7_CFG_VC_7_FRAME_COUNT_EN_SHIFT                            (0x00000000U)
#define CSL_CSITX_VC7_CFG_VC_7_FRAME_COUNT_EN_MAX                              (0x00000001U)

#define CSL_CSITX_VC7_CFG_VC_7_MAX_FRAME_NUMBER_MASK                           (0xFFFF0000U)
#define CSL_CSITX_VC7_CFG_VC_7_MAX_FRAME_NUMBER_SHIFT                          (0x00000010U)
#define CSL_CSITX_VC7_CFG_VC_7_MAX_FRAME_NUMBER_MAX                            (0x0000FFFFU)

/* VC8_CFG */

#define CSL_CSITX_VC8_CFG_VC_8_FRAME_COUNT_EN_MASK                             (0x00000001U)
#define CSL_CSITX_VC8_CFG_VC_8_FRAME_COUNT_EN_SHIFT                            (0x00000000U)
#define CSL_CSITX_VC8_CFG_VC_8_FRAME_COUNT_EN_MAX                              (0x00000001U)

#define CSL_CSITX_VC8_CFG_VC_8_MAX_FRAME_NUMBER_MASK                           (0xFFFF0000U)
#define CSL_CSITX_VC8_CFG_VC_8_MAX_FRAME_NUMBER_SHIFT                          (0x00000010U)
#define CSL_CSITX_VC8_CFG_VC_8_MAX_FRAME_NUMBER_MAX                            (0x0000FFFFU)

/* VC9_CFG */

#define CSL_CSITX_VC9_CFG_VC_9_FRAME_COUNT_EN_MASK                             (0x00000001U)
#define CSL_CSITX_VC9_CFG_VC_9_FRAME_COUNT_EN_SHIFT                            (0x00000000U)
#define CSL_CSITX_VC9_CFG_VC_9_FRAME_COUNT_EN_MAX                              (0x00000001U)

#define CSL_CSITX_VC9_CFG_VC_9_MAX_FRAME_NUMBER_MASK                           (0xFFFF0000U)
#define CSL_CSITX_VC9_CFG_VC_9_MAX_FRAME_NUMBER_SHIFT                          (0x00000010U)
#define CSL_CSITX_VC9_CFG_VC_9_MAX_FRAME_NUMBER_MAX                            (0x0000FFFFU)

/* VC10_CFG */

#define CSL_CSITX_VC10_CFG_VC_10_FRAME_COUNT_EN_MASK                           (0x00000001U)
#define CSL_CSITX_VC10_CFG_VC_10_FRAME_COUNT_EN_SHIFT                          (0x00000000U)
#define CSL_CSITX_VC10_CFG_VC_10_FRAME_COUNT_EN_MAX                            (0x00000001U)

#define CSL_CSITX_VC10_CFG_VC_10_MAX_FRAME_NUMBER_MASK                         (0xFFFF0000U)
#define CSL_CSITX_VC10_CFG_VC_10_MAX_FRAME_NUMBER_SHIFT                        (0x00000010U)
#define CSL_CSITX_VC10_CFG_VC_10_MAX_FRAME_NUMBER_MAX                          (0x0000FFFFU)

/* VC11_CFG */

#define CSL_CSITX_VC11_CFG_VC_11_FRAME_COUNT_EN_MASK                           (0x00000001U)
#define CSL_CSITX_VC11_CFG_VC_11_FRAME_COUNT_EN_SHIFT                          (0x00000000U)
#define CSL_CSITX_VC11_CFG_VC_11_FRAME_COUNT_EN_MAX                            (0x00000001U)

#define CSL_CSITX_VC11_CFG_VC_11_MAX_FRAME_NUMBER_MASK                         (0xFFFF0000U)
#define CSL_CSITX_VC11_CFG_VC_11_MAX_FRAME_NUMBER_SHIFT                        (0x00000010U)
#define CSL_CSITX_VC11_CFG_VC_11_MAX_FRAME_NUMBER_MAX                          (0x0000FFFFU)

/* VC12_CFG */

#define CSL_CSITX_VC12_CFG_VC_12_FRAME_COUNT_EN_MASK                           (0x00000001U)
#define CSL_CSITX_VC12_CFG_VC_12_FRAME_COUNT_EN_SHIFT                          (0x00000000U)
#define CSL_CSITX_VC12_CFG_VC_12_FRAME_COUNT_EN_MAX                            (0x00000001U)

#define CSL_CSITX_VC12_CFG_VC_12_MAX_FRAME_NUMBER_MASK                         (0xFFFF0000U)
#define CSL_CSITX_VC12_CFG_VC_12_MAX_FRAME_NUMBER_SHIFT                        (0x00000010U)
#define CSL_CSITX_VC12_CFG_VC_12_MAX_FRAME_NUMBER_MAX                          (0x0000FFFFU)

/* VC13_CFG */

#define CSL_CSITX_VC13_CFG_VC_13_FRAME_COUNT_EN_MASK                           (0x00000001U)
#define CSL_CSITX_VC13_CFG_VC_13_FRAME_COUNT_EN_SHIFT                          (0x00000000U)
#define CSL_CSITX_VC13_CFG_VC_13_FRAME_COUNT_EN_MAX                            (0x00000001U)

#define CSL_CSITX_VC13_CFG_VC_13_MAX_FRAME_NUMBER_MASK                         (0xFFFF0000U)
#define CSL_CSITX_VC13_CFG_VC_13_MAX_FRAME_NUMBER_SHIFT                        (0x00000010U)
#define CSL_CSITX_VC13_CFG_VC_13_MAX_FRAME_NUMBER_MAX                          (0x0000FFFFU)

/* VC14_CFG */

#define CSL_CSITX_VC14_CFG_VC_14_FRAME_COUNT_EN_MASK                           (0x00000001U)
#define CSL_CSITX_VC14_CFG_VC_14_FRAME_COUNT_EN_SHIFT                          (0x00000000U)
#define CSL_CSITX_VC14_CFG_VC_14_FRAME_COUNT_EN_MAX                            (0x00000001U)

#define CSL_CSITX_VC14_CFG_VC_14_MAX_FRAME_NUMBER_MASK                         (0xFFFF0000U)
#define CSL_CSITX_VC14_CFG_VC_14_MAX_FRAME_NUMBER_SHIFT                        (0x00000010U)
#define CSL_CSITX_VC14_CFG_VC_14_MAX_FRAME_NUMBER_MAX                          (0x0000FFFFU)

/* VC15_CFG */

#define CSL_CSITX_VC15_CFG_VC_15_FRAME_COUNT_EN_MASK                           (0x00000001U)
#define CSL_CSITX_VC15_CFG_VC_15_FRAME_COUNT_EN_SHIFT                          (0x00000000U)
#define CSL_CSITX_VC15_CFG_VC_15_FRAME_COUNT_EN_MAX                            (0x00000001U)

#define CSL_CSITX_VC15_CFG_VC_15_MAX_FRAME_NUMBER_MASK                         (0xFFFF0000U)
#define CSL_CSITX_VC15_CFG_VC_15_MAX_FRAME_NUMBER_SHIFT                        (0x00000010U)
#define CSL_CSITX_VC15_CFG_VC_15_MAX_FRAME_NUMBER_MAX                          (0x0000FFFFU)

/* DT0_CFG */

#define CSL_CSITX_DT0_CFG_DT_0_LINE_COUNT_EN_MASK                              (0x00000001U)
#define CSL_CSITX_DT0_CFG_DT_0_LINE_COUNT_EN_SHIFT                             (0x00000000U)
#define CSL_CSITX_DT0_CFG_DT_0_LINE_COUNT_EN_MAX                               (0x00000001U)

#define CSL_CSITX_DT0_CFG_DT_0_LSLE_GENERATION_EN_MASK                         (0x00000002U)
#define CSL_CSITX_DT0_CFG_DT_0_LSLE_GENERATION_EN_SHIFT                        (0x00000001U)
#define CSL_CSITX_DT0_CFG_DT_0_LSLE_GENERATION_EN_MAX                          (0x00000001U)

#define CSL_CSITX_DT0_CFG_DT_0_DATA_TYPE_MASK                                  (0x000000FCU)
#define CSL_CSITX_DT0_CFG_DT_0_DATA_TYPE_SHIFT                                 (0x00000002U)
#define CSL_CSITX_DT0_CFG_DT_0_DATA_TYPE_MAX                                   (0x0000003FU)

#define CSL_CSITX_DT0_CFG_DT_0_EXTD_DATA_TYPE_MASK                             (0x00000100U)
#define CSL_CSITX_DT0_CFG_DT_0_EXTD_DATA_TYPE_SHIFT                            (0x00000008U)
#define CSL_CSITX_DT0_CFG_DT_0_EXTD_DATA_TYPE_MAX                              (0x00000001U)

#define CSL_CSITX_DT0_CFG_DT_0_PACKED_ENABLE_MASK                              (0x00000200U)
#define CSL_CSITX_DT0_CFG_DT_0_PACKED_ENABLE_SHIFT                             (0x00000009U)
#define CSL_CSITX_DT0_CFG_DT_0_PACKED_ENABLE_MAX                               (0x00000001U)

/* DT0_FORMAT */

#define CSL_CSITX_DT0_FORMAT_DT_0_MAX_LINE_NUMBER_MASK                         (0x0000FFFFU)
#define CSL_CSITX_DT0_FORMAT_DT_0_MAX_LINE_NUMBER_SHIFT                        (0x00000000U)
#define CSL_CSITX_DT0_FORMAT_DT_0_MAX_LINE_NUMBER_MAX                          (0x0000FFFFU)

#define CSL_CSITX_DT0_FORMAT_DT_0_BYTES_LINE_NUMBER_MASK                       (0xFFFF0000U)
#define CSL_CSITX_DT0_FORMAT_DT_0_BYTES_LINE_NUMBER_SHIFT                      (0x00000010U)
#define CSL_CSITX_DT0_FORMAT_DT_0_BYTES_LINE_NUMBER_MAX                        (0x0000FFFFU)

/* DT1_CFG */

#define CSL_CSITX_DT1_CFG_DT_1_LINE_COUNT_EN_MASK                              (0x00000001U)
#define CSL_CSITX_DT1_CFG_DT_1_LINE_COUNT_EN_SHIFT                             (0x00000000U)
#define CSL_CSITX_DT1_CFG_DT_1_LINE_COUNT_EN_MAX                               (0x00000001U)

#define CSL_CSITX_DT1_CFG_DT_1_LSLE_GENERATION_EN_MASK                         (0x00000002U)
#define CSL_CSITX_DT1_CFG_DT_1_LSLE_GENERATION_EN_SHIFT                        (0x00000001U)
#define CSL_CSITX_DT1_CFG_DT_1_LSLE_GENERATION_EN_MAX                          (0x00000001U)

#define CSL_CSITX_DT1_CFG_DT_1_DATA_TYPE_MASK                                  (0x000000FCU)
#define CSL_CSITX_DT1_CFG_DT_1_DATA_TYPE_SHIFT                                 (0x00000002U)
#define CSL_CSITX_DT1_CFG_DT_1_DATA_TYPE_MAX                                   (0x0000003FU)

#define CSL_CSITX_DT1_CFG_DT_1_EXTD_DATA_TYPE_MASK                             (0x00000100U)
#define CSL_CSITX_DT1_CFG_DT_1_EXTD_DATA_TYPE_SHIFT                            (0x00000008U)
#define CSL_CSITX_DT1_CFG_DT_1_EXTD_DATA_TYPE_MAX                              (0x00000001U)

#define CSL_CSITX_DT1_CFG_DT_1_PACKED_ENABLE_MASK                              (0x00000200U)
#define CSL_CSITX_DT1_CFG_DT_1_PACKED_ENABLE_SHIFT                             (0x00000009U)
#define CSL_CSITX_DT1_CFG_DT_1_PACKED_ENABLE_MAX                               (0x00000001U)

/* DT1_FORMAT */

#define CSL_CSITX_DT1_FORMAT_DT_1_MAX_LINE_NUMBER_MASK                         (0x0000FFFFU)
#define CSL_CSITX_DT1_FORMAT_DT_1_MAX_LINE_NUMBER_SHIFT                        (0x00000000U)
#define CSL_CSITX_DT1_FORMAT_DT_1_MAX_LINE_NUMBER_MAX                          (0x0000FFFFU)

#define CSL_CSITX_DT1_FORMAT_DT_1_BYTES_LINE_NUMBER_MASK                       (0xFFFF0000U)
#define CSL_CSITX_DT1_FORMAT_DT_1_BYTES_LINE_NUMBER_SHIFT                      (0x00000010U)
#define CSL_CSITX_DT1_FORMAT_DT_1_BYTES_LINE_NUMBER_MAX                        (0x0000FFFFU)

/* DT2_CFG */

#define CSL_CSITX_DT2_CFG_DT_2_LINE_COUNT_EN_MASK                              (0x00000001U)
#define CSL_CSITX_DT2_CFG_DT_2_LINE_COUNT_EN_SHIFT                             (0x00000000U)
#define CSL_CSITX_DT2_CFG_DT_2_LINE_COUNT_EN_MAX                               (0x00000001U)

#define CSL_CSITX_DT2_CFG_DT_2_LSLE_GENERATION_EN_MASK                         (0x00000002U)
#define CSL_CSITX_DT2_CFG_DT_2_LSLE_GENERATION_EN_SHIFT                        (0x00000001U)
#define CSL_CSITX_DT2_CFG_DT_2_LSLE_GENERATION_EN_MAX                          (0x00000001U)

#define CSL_CSITX_DT2_CFG_DT_2_DATA_TYPE_MASK                                  (0x000000FCU)
#define CSL_CSITX_DT2_CFG_DT_2_DATA_TYPE_SHIFT                                 (0x00000002U)
#define CSL_CSITX_DT2_CFG_DT_2_DATA_TYPE_MAX                                   (0x0000003FU)

#define CSL_CSITX_DT2_CFG_DT_2_EXTD_DATA_TYPE_MASK                             (0x00000100U)
#define CSL_CSITX_DT2_CFG_DT_2_EXTD_DATA_TYPE_SHIFT                            (0x00000008U)
#define CSL_CSITX_DT2_CFG_DT_2_EXTD_DATA_TYPE_MAX                              (0x00000001U)

#define CSL_CSITX_DT2_CFG_DT_2_PACKED_ENABLE_MASK                              (0x00000200U)
#define CSL_CSITX_DT2_CFG_DT_2_PACKED_ENABLE_SHIFT                             (0x00000009U)
#define CSL_CSITX_DT2_CFG_DT_2_PACKED_ENABLE_MAX                               (0x00000001U)

/* DT2_FORMAT */

#define CSL_CSITX_DT2_FORMAT_DT_2_MAX_LINE_NUMBER_MASK                         (0x0000FFFFU)
#define CSL_CSITX_DT2_FORMAT_DT_2_MAX_LINE_NUMBER_SHIFT                        (0x00000000U)
#define CSL_CSITX_DT2_FORMAT_DT_2_MAX_LINE_NUMBER_MAX                          (0x0000FFFFU)

#define CSL_CSITX_DT2_FORMAT_DT_2_BYTES_LINE_NUMBER_MASK                       (0xFFFF0000U)
#define CSL_CSITX_DT2_FORMAT_DT_2_BYTES_LINE_NUMBER_SHIFT                      (0x00000010U)
#define CSL_CSITX_DT2_FORMAT_DT_2_BYTES_LINE_NUMBER_MAX                        (0x0000FFFFU)

/* DT3_CFG */

#define CSL_CSITX_DT3_CFG_DT_3_LINE_COUNT_EN_MASK                              (0x00000001U)
#define CSL_CSITX_DT3_CFG_DT_3_LINE_COUNT_EN_SHIFT                             (0x00000000U)
#define CSL_CSITX_DT3_CFG_DT_3_LINE_COUNT_EN_MAX                               (0x00000001U)

#define CSL_CSITX_DT3_CFG_DT_3_LSLE_GENERATION_EN_MASK                         (0x00000002U)
#define CSL_CSITX_DT3_CFG_DT_3_LSLE_GENERATION_EN_SHIFT                        (0x00000001U)
#define CSL_CSITX_DT3_CFG_DT_3_LSLE_GENERATION_EN_MAX                          (0x00000001U)

#define CSL_CSITX_DT3_CFG_DT_3_DATA_TYPE_MASK                                  (0x000000FCU)
#define CSL_CSITX_DT3_CFG_DT_3_DATA_TYPE_SHIFT                                 (0x00000002U)
#define CSL_CSITX_DT3_CFG_DT_3_DATA_TYPE_MAX                                   (0x0000003FU)

#define CSL_CSITX_DT3_CFG_DT_3_EXTD_DATA_TYPE_MASK                             (0x00000100U)
#define CSL_CSITX_DT3_CFG_DT_3_EXTD_DATA_TYPE_SHIFT                            (0x00000008U)
#define CSL_CSITX_DT3_CFG_DT_3_EXTD_DATA_TYPE_MAX                              (0x00000001U)

#define CSL_CSITX_DT3_CFG_DT_3_PACKED_ENABLE_MASK                              (0x00000200U)
#define CSL_CSITX_DT3_CFG_DT_3_PACKED_ENABLE_SHIFT                             (0x00000009U)
#define CSL_CSITX_DT3_CFG_DT_3_PACKED_ENABLE_MAX                               (0x00000001U)

/* DT3_FORMAT */

#define CSL_CSITX_DT3_FORMAT_DT_3_MAX_LINE_NUMBER_MASK                         (0x0000FFFFU)
#define CSL_CSITX_DT3_FORMAT_DT_3_MAX_LINE_NUMBER_SHIFT                        (0x00000000U)
#define CSL_CSITX_DT3_FORMAT_DT_3_MAX_LINE_NUMBER_MAX                          (0x0000FFFFU)

#define CSL_CSITX_DT3_FORMAT_DT_3_BYTES_LINE_NUMBER_MASK                       (0xFFFF0000U)
#define CSL_CSITX_DT3_FORMAT_DT_3_BYTES_LINE_NUMBER_SHIFT                      (0x00000010U)
#define CSL_CSITX_DT3_FORMAT_DT_3_BYTES_LINE_NUMBER_MAX                        (0x0000FFFFU)

/* DT4_CFG */

#define CSL_CSITX_DT4_CFG_DT_4_LINE_COUNT_EN_MASK                              (0x00000001U)
#define CSL_CSITX_DT4_CFG_DT_4_LINE_COUNT_EN_SHIFT                             (0x00000000U)
#define CSL_CSITX_DT4_CFG_DT_4_LINE_COUNT_EN_MAX                               (0x00000001U)

#define CSL_CSITX_DT4_CFG_DT_4_LSLE_GENERATION_EN_MASK                         (0x00000002U)
#define CSL_CSITX_DT4_CFG_DT_4_LSLE_GENERATION_EN_SHIFT                        (0x00000001U)
#define CSL_CSITX_DT4_CFG_DT_4_LSLE_GENERATION_EN_MAX                          (0x00000001U)

#define CSL_CSITX_DT4_CFG_DT_4_DATA_TYPE_MASK                                  (0x000000FCU)
#define CSL_CSITX_DT4_CFG_DT_4_DATA_TYPE_SHIFT                                 (0x00000002U)
#define CSL_CSITX_DT4_CFG_DT_4_DATA_TYPE_MAX                                   (0x0000003FU)

#define CSL_CSITX_DT4_CFG_DT_4_EXTD_DATA_TYPE_MASK                             (0x00000100U)
#define CSL_CSITX_DT4_CFG_DT_4_EXTD_DATA_TYPE_SHIFT                            (0x00000008U)
#define CSL_CSITX_DT4_CFG_DT_4_EXTD_DATA_TYPE_MAX                              (0x00000001U)

#define CSL_CSITX_DT4_CFG_DT_4_PACKED_ENABLE_MASK                              (0x00000200U)
#define CSL_CSITX_DT4_CFG_DT_4_PACKED_ENABLE_SHIFT                             (0x00000009U)
#define CSL_CSITX_DT4_CFG_DT_4_PACKED_ENABLE_MAX                               (0x00000001U)

/* DT4_FORMAT */

#define CSL_CSITX_DT4_FORMAT_DT_4_MAX_LINE_NUMBER_MASK                         (0x0000FFFFU)
#define CSL_CSITX_DT4_FORMAT_DT_4_MAX_LINE_NUMBER_SHIFT                        (0x00000000U)
#define CSL_CSITX_DT4_FORMAT_DT_4_MAX_LINE_NUMBER_MAX                          (0x0000FFFFU)

#define CSL_CSITX_DT4_FORMAT_DT_4_BYTES_LINE_NUMBER_MASK                       (0xFFFF0000U)
#define CSL_CSITX_DT4_FORMAT_DT_4_BYTES_LINE_NUMBER_SHIFT                      (0x00000010U)
#define CSL_CSITX_DT4_FORMAT_DT_4_BYTES_LINE_NUMBER_MAX                        (0x0000FFFFU)

/* DT5_CFG */

#define CSL_CSITX_DT5_CFG_DT_5_LINE_COUNT_EN_MASK                              (0x00000001U)
#define CSL_CSITX_DT5_CFG_DT_5_LINE_COUNT_EN_SHIFT                             (0x00000000U)
#define CSL_CSITX_DT5_CFG_DT_5_LINE_COUNT_EN_MAX                               (0x00000001U)

#define CSL_CSITX_DT5_CFG_DT_5_LSLE_GENERATION_EN_MASK                         (0x00000002U)
#define CSL_CSITX_DT5_CFG_DT_5_LSLE_GENERATION_EN_SHIFT                        (0x00000001U)
#define CSL_CSITX_DT5_CFG_DT_5_LSLE_GENERATION_EN_MAX                          (0x00000001U)

#define CSL_CSITX_DT5_CFG_DT_5_DATA_TYPE_MASK                                  (0x000000FCU)
#define CSL_CSITX_DT5_CFG_DT_5_DATA_TYPE_SHIFT                                 (0x00000002U)
#define CSL_CSITX_DT5_CFG_DT_5_DATA_TYPE_MAX                                   (0x0000003FU)

#define CSL_CSITX_DT5_CFG_DT_5_EXTD_DATA_TYPE_MASK                             (0x00000100U)
#define CSL_CSITX_DT5_CFG_DT_5_EXTD_DATA_TYPE_SHIFT                            (0x00000008U)
#define CSL_CSITX_DT5_CFG_DT_5_EXTD_DATA_TYPE_MAX                              (0x00000001U)

#define CSL_CSITX_DT5_CFG_DT_5_PACKED_ENABLE_MASK                              (0x00000200U)
#define CSL_CSITX_DT5_CFG_DT_5_PACKED_ENABLE_SHIFT                             (0x00000009U)
#define CSL_CSITX_DT5_CFG_DT_5_PACKED_ENABLE_MAX                               (0x00000001U)

/* DT5_FORMAT */

#define CSL_CSITX_DT5_FORMAT_DT_5_MAX_LINE_NUMBER_MASK                         (0x0000FFFFU)
#define CSL_CSITX_DT5_FORMAT_DT_5_MAX_LINE_NUMBER_SHIFT                        (0x00000000U)
#define CSL_CSITX_DT5_FORMAT_DT_5_MAX_LINE_NUMBER_MAX                          (0x0000FFFFU)

#define CSL_CSITX_DT5_FORMAT_DT_5_BYTES_LINE_NUMBER_MASK                       (0xFFFF0000U)
#define CSL_CSITX_DT5_FORMAT_DT_5_BYTES_LINE_NUMBER_SHIFT                      (0x00000010U)
#define CSL_CSITX_DT5_FORMAT_DT_5_BYTES_LINE_NUMBER_MAX                        (0x0000FFFFU)

/* DT6_CFG */

#define CSL_CSITX_DT6_CFG_DT_6_LINE_COUNT_EN_MASK                              (0x00000001U)
#define CSL_CSITX_DT6_CFG_DT_6_LINE_COUNT_EN_SHIFT                             (0x00000000U)
#define CSL_CSITX_DT6_CFG_DT_6_LINE_COUNT_EN_MAX                               (0x00000001U)

#define CSL_CSITX_DT6_CFG_DT_6_LSLE_GENERATION_EN_MASK                         (0x00000002U)
#define CSL_CSITX_DT6_CFG_DT_6_LSLE_GENERATION_EN_SHIFT                        (0x00000001U)
#define CSL_CSITX_DT6_CFG_DT_6_LSLE_GENERATION_EN_MAX                          (0x00000001U)

#define CSL_CSITX_DT6_CFG_DT_6_DATA_TYPE_MASK                                  (0x000000FCU)
#define CSL_CSITX_DT6_CFG_DT_6_DATA_TYPE_SHIFT                                 (0x00000002U)
#define CSL_CSITX_DT6_CFG_DT_6_DATA_TYPE_MAX                                   (0x0000003FU)

#define CSL_CSITX_DT6_CFG_DT_6_EXTD_DATA_TYPE_MASK                             (0x00000100U)
#define CSL_CSITX_DT6_CFG_DT_6_EXTD_DATA_TYPE_SHIFT                            (0x00000008U)
#define CSL_CSITX_DT6_CFG_DT_6_EXTD_DATA_TYPE_MAX                              (0x00000001U)

#define CSL_CSITX_DT6_CFG_DT_6_PACKED_ENABLE_MASK                              (0x00000200U)
#define CSL_CSITX_DT6_CFG_DT_6_PACKED_ENABLE_SHIFT                             (0x00000009U)
#define CSL_CSITX_DT6_CFG_DT_6_PACKED_ENABLE_MAX                               (0x00000001U)

/* DT6_FORMAT */

#define CSL_CSITX_DT6_FORMAT_DT_6_MAX_LINE_NUMBER_MASK                         (0x0000FFFFU)
#define CSL_CSITX_DT6_FORMAT_DT_6_MAX_LINE_NUMBER_SHIFT                        (0x00000000U)
#define CSL_CSITX_DT6_FORMAT_DT_6_MAX_LINE_NUMBER_MAX                          (0x0000FFFFU)

#define CSL_CSITX_DT6_FORMAT_DT_6_BYTES_LINE_NUMBER_MASK                       (0xFFFF0000U)
#define CSL_CSITX_DT6_FORMAT_DT_6_BYTES_LINE_NUMBER_SHIFT                      (0x00000010U)
#define CSL_CSITX_DT6_FORMAT_DT_6_BYTES_LINE_NUMBER_MAX                        (0x0000FFFFU)

/* DT7_CFG */

#define CSL_CSITX_DT7_CFG_DT_7_LINE_COUNT_EN_MASK                              (0x00000001U)
#define CSL_CSITX_DT7_CFG_DT_7_LINE_COUNT_EN_SHIFT                             (0x00000000U)
#define CSL_CSITX_DT7_CFG_DT_7_LINE_COUNT_EN_MAX                               (0x00000001U)

#define CSL_CSITX_DT7_CFG_DT_7_LSLE_GENERATION_EN_MASK                         (0x00000002U)
#define CSL_CSITX_DT7_CFG_DT_7_LSLE_GENERATION_EN_SHIFT                        (0x00000001U)
#define CSL_CSITX_DT7_CFG_DT_7_LSLE_GENERATION_EN_MAX                          (0x00000001U)

#define CSL_CSITX_DT7_CFG_DT_7_DATA_TYPE_MASK                                  (0x000000FCU)
#define CSL_CSITX_DT7_CFG_DT_7_DATA_TYPE_SHIFT                                 (0x00000002U)
#define CSL_CSITX_DT7_CFG_DT_7_DATA_TYPE_MAX                                   (0x0000003FU)

#define CSL_CSITX_DT7_CFG_DT_7_EXTD_DATA_TYPE_MASK                             (0x00000100U)
#define CSL_CSITX_DT7_CFG_DT_7_EXTD_DATA_TYPE_SHIFT                            (0x00000008U)
#define CSL_CSITX_DT7_CFG_DT_7_EXTD_DATA_TYPE_MAX                              (0x00000001U)

#define CSL_CSITX_DT7_CFG_DT_7_PACKED_ENABLE_MASK                              (0x00000200U)
#define CSL_CSITX_DT7_CFG_DT_7_PACKED_ENABLE_SHIFT                             (0x00000009U)
#define CSL_CSITX_DT7_CFG_DT_7_PACKED_ENABLE_MAX                               (0x00000001U)

/* DT7_FORMAT */

#define CSL_CSITX_DT7_FORMAT_DT_7_MAX_LINE_NUMBER_MASK                         (0x0000FFFFU)
#define CSL_CSITX_DT7_FORMAT_DT_7_MAX_LINE_NUMBER_SHIFT                        (0x00000000U)
#define CSL_CSITX_DT7_FORMAT_DT_7_MAX_LINE_NUMBER_MAX                          (0x0000FFFFU)

#define CSL_CSITX_DT7_FORMAT_DT_7_BYTES_LINE_NUMBER_MASK                       (0xFFFF0000U)
#define CSL_CSITX_DT7_FORMAT_DT_7_BYTES_LINE_NUMBER_SHIFT                      (0x00000010U)
#define CSL_CSITX_DT7_FORMAT_DT_7_BYTES_LINE_NUMBER_MAX                        (0x0000FFFFU)

/* STREAM_IF_0_CFG */

#define CSL_CSITX_STREAM_IF_0_CFG_STREAM_IF_0_FILL_LEVEL_MASK                  (0x0000FFFFU)
#define CSL_CSITX_STREAM_IF_0_CFG_STREAM_IF_0_FILL_LEVEL_SHIFT                 (0x00000000U)
#define CSL_CSITX_STREAM_IF_0_CFG_STREAM_IF_0_FILL_LEVEL_MAX                   (0x0000FFFFU)

/* STREAM_IF_1_CFG */

#define CSL_CSITX_STREAM_IF_1_CFG_STREAM_IF_1_FILL_LEVEL_MASK                  (0x0000FFFFU)
#define CSL_CSITX_STREAM_IF_1_CFG_STREAM_IF_1_FILL_LEVEL_SHIFT                 (0x00000000U)
#define CSL_CSITX_STREAM_IF_1_CFG_STREAM_IF_1_FILL_LEVEL_MAX                   (0x0000FFFFU)

#define CSL_CSITX_STREAM_IF_1_CFG_STREAM_IF_1_SLAVE_MODE_MASK                  (0x00800000U)
#define CSL_CSITX_STREAM_IF_1_CFG_STREAM_IF_1_SLAVE_MODE_SHIFT                 (0x00000017U)
#define CSL_CSITX_STREAM_IF_1_CFG_STREAM_IF_1_SLAVE_MODE_MAX                   (0x00000001U)

/* STREAM_IF_2_CFG */

#define CSL_CSITX_STREAM_IF_2_CFG_STREAM_IF_2_FILL_LEVEL_MASK                  (0x0000FFFFU)
#define CSL_CSITX_STREAM_IF_2_CFG_STREAM_IF_2_FILL_LEVEL_SHIFT                 (0x00000000U)
#define CSL_CSITX_STREAM_IF_2_CFG_STREAM_IF_2_FILL_LEVEL_MAX                   (0x0000FFFFU)

#define CSL_CSITX_STREAM_IF_2_CFG_STREAM_IF_2_SLAVE_MODE_MASK                  (0x00800000U)
#define CSL_CSITX_STREAM_IF_2_CFG_STREAM_IF_2_SLAVE_MODE_SHIFT                 (0x00000017U)
#define CSL_CSITX_STREAM_IF_2_CFG_STREAM_IF_2_SLAVE_MODE_MAX                   (0x00000001U)

/* STREAM_IF_3_CFG */

#define CSL_CSITX_STREAM_IF_3_CFG_STREAM_IF_3_FILL_LEVEL_MASK                  (0x0000FFFFU)
#define CSL_CSITX_STREAM_IF_3_CFG_STREAM_IF_3_FILL_LEVEL_SHIFT                 (0x00000000U)
#define CSL_CSITX_STREAM_IF_3_CFG_STREAM_IF_3_FILL_LEVEL_MAX                   (0x0000FFFFU)

#define CSL_CSITX_STREAM_IF_3_CFG_STREAM_IF_3_SLAVE_MODE_MASK                  (0x00800000U)
#define CSL_CSITX_STREAM_IF_3_CFG_STREAM_IF_3_SLAVE_MODE_SHIFT                 (0x00000017U)
#define CSL_CSITX_STREAM_IF_3_CFG_STREAM_IF_3_SLAVE_MODE_MAX                   (0x00000001U)

/* DEBUG_CFG */

#define CSL_CSITX_DEBUG_CFG_DBG_EN_MASK                                        (0x00000001U)
#define CSL_CSITX_DEBUG_CFG_DBG_EN_SHIFT                                       (0x00000000U)
#define CSL_CSITX_DEBUG_CFG_DBG_EN_MAX                                         (0x00000001U)

/* DEBUG_LN_FSM */

#define CSL_CSITX_DEBUG_LN_FSM_LANE_MGR_FSM_ST_MASK                            (0x00000007U)
#define CSL_CSITX_DEBUG_LN_FSM_LANE_MGR_FSM_ST_SHIFT                           (0x00000000U)
#define CSL_CSITX_DEBUG_LN_FSM_LANE_MGR_FSM_ST_MAX                             (0x00000007U)

#define CSL_CSITX_DEBUG_LN_FSM_START_HS_TRANS_MASK                             (0x00000010U)
#define CSL_CSITX_DEBUG_LN_FSM_START_HS_TRANS_SHIFT                            (0x00000004U)
#define CSL_CSITX_DEBUG_LN_FSM_START_HS_TRANS_MAX                              (0x00000001U)

#define CSL_CSITX_DEBUG_LN_FSM_TRANS_ACTIVE_MASK                               (0x00000020U)
#define CSL_CSITX_DEBUG_LN_FSM_TRANS_ACTIVE_SHIFT                              (0x00000005U)
#define CSL_CSITX_DEBUG_LN_FSM_TRANS_ACTIVE_MAX                                (0x00000001U)

#define CSL_CSITX_DEBUG_LN_FSM_END_OF_BURST_MASK                               (0x00000040U)
#define CSL_CSITX_DEBUG_LN_FSM_END_OF_BURST_SHIFT                              (0x00000006U)
#define CSL_CSITX_DEBUG_LN_FSM_END_OF_BURST_MAX                                (0x00000001U)

#define CSL_CSITX_DEBUG_LN_FSM_PACKET_VALID_IN_MASK                            (0x00000080U)
#define CSL_CSITX_DEBUG_LN_FSM_PACKET_VALID_IN_SHIFT                           (0x00000007U)
#define CSL_CSITX_DEBUG_LN_FSM_PACKET_VALID_IN_MAX                             (0x00000001U)

#define CSL_CSITX_DEBUG_LN_FSM_PACKET_VALID_R_MASK                             (0x00000100U)
#define CSL_CSITX_DEBUG_LN_FSM_PACKET_VALID_R_SHIFT                            (0x00000008U)
#define CSL_CSITX_DEBUG_LN_FSM_PACKET_VALID_R_MAX                              (0x00000001U)

#define CSL_CSITX_DEBUG_LN_FSM_NEW_BURST_ALLOWED_MASK                          (0x00000200U)
#define CSL_CSITX_DEBUG_LN_FSM_NEW_BURST_ALLOWED_SHIFT                         (0x00000009U)
#define CSL_CSITX_DEBUG_LN_FSM_NEW_BURST_ALLOWED_MAX                           (0x00000001U)

/* DEBUG_CLK_LN_FSM */

#define CSL_CSITX_DEBUG_CLK_LN_FSM_HS_CLK_FSM_MASK                             (0x00000003U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_HS_CLK_FSM_SHIFT                            (0x00000000U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_HS_CLK_FSM_MAX                              (0x00000003U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_CLK_FSM_MASK                           (0x0000000CU)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_CLK_FSM_SHIFT                          (0x00000002U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_CLK_FSM_MAX                            (0x00000003U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_HS_MODE_REQ_MASK                            (0x00000010U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_HS_MODE_REQ_SHIFT                           (0x00000004U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_HS_MODE_REQ_MAX                             (0x00000001U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_REQUEST_CLK_MASK                       (0x00000020U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_REQUEST_CLK_SHIFT                      (0x00000005U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_REQUEST_CLK_MAX                        (0x00000001U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_WAKEUP_COUNT_DONE_CL_MASK              (0x00000040U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_WAKEUP_COUNT_DONE_CL_SHIFT             (0x00000006U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_WAKEUP_COUNT_DONE_CL_MAX               (0x00000001U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_READY_HS_CLK_MASK                           (0x00000080U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_READY_HS_CLK_SHIFT                          (0x00000007U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_READY_HS_CLK_MAX                            (0x00000001U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_REQUEST_HS_CLK_PPI_MASK                     (0x00000100U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_REQUEST_HS_CLK_PPI_SHIFT                    (0x00000008U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_REQUEST_HS_CLK_PPI_MAX                      (0x00000001U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_HS_MODE_ACTIVE_CLK_MASK                     (0x00000200U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_HS_MODE_ACTIVE_CLK_SHIFT                    (0x00000009U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_HS_MODE_ACTIVE_CLK_MAX                      (0x00000001U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_REQUEST_CLK_PPI_MASK                   (0x00000400U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_REQUEST_CLK_PPI_SHIFT                  (0x0000000AU)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_REQUEST_CLK_PPI_MAX                    (0x00000001U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_EXIT_CLK_PPI_MASK                      (0x00000800U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_EXIT_CLK_PPI_SHIFT                     (0x0000000BU)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_EXIT_CLK_PPI_MAX                       (0x00000001U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_MODE_ACTIVE_MASK                       (0x00001000U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_MODE_ACTIVE_SHIFT                      (0x0000000CU)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_MODE_ACTIVE_MAX                        (0x00000001U)

#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_ACTIVE_CLK_MASK                        (0x00002000U)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_ACTIVE_CLK_SHIFT                       (0x0000000DU)
#define CSL_CSITX_DEBUG_CLK_LN_FSM_ULPS_ACTIVE_CLK_MAX                         (0x00000001U)

/* DEBUG_DATA_LN_FSM */

#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_DATA_LANE_FSM_MASK                    (0x00000003U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_DATA_LANE_FSM_SHIFT                   (0x00000000U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_DATA_LANE_FSM_MAX                     (0x00000003U)

#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_REQ_SYNC_MASK                         (0x00000010U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_REQ_SYNC_SHIFT                        (0x00000004U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_REQ_SYNC_MAX                          (0x00000001U)

#define CSL_CSITX_DEBUG_DATA_LN_FSM_HS_MODE_REQ_SYNC_MASK                      (0x00000020U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_HS_MODE_REQ_SYNC_SHIFT                     (0x00000005U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_HS_MODE_REQ_SYNC_MAX                       (0x00000001U)

#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_ACTIVE_N_MASK                         (0x000003C0U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_ACTIVE_N_SHIFT                        (0x00000006U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_ACTIVE_N_MAX                          (0x0000000FU)

#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_WAKEUP_COUNT_DONE_DL_MASK             (0x00000400U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_WAKEUP_COUNT_DONE_DL_SHIFT            (0x0000000AU)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_WAKEUP_COUNT_DONE_DL_MAX              (0x00000001U)

#define CSL_CSITX_DEBUG_DATA_LN_FSM_TX_REQUEST_ESC_MASK                        (0x00001000U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_TX_REQUEST_ESC_SHIFT                       (0x0000000CU)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_TX_REQUEST_ESC_MAX                         (0x00000001U)

#define CSL_CSITX_DEBUG_DATA_LN_FSM_TX_ULPS_ESC_MASK                           (0x00002000U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_TX_ULPS_ESC_SHIFT                          (0x0000000DU)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_TX_ULPS_ESC_MAX                            (0x00000001U)

#define CSL_CSITX_DEBUG_DATA_LN_FSM_TX_ULPS_EXIT_ESC_MASK                      (0x00004000U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_TX_ULPS_EXIT_ESC_SHIFT                     (0x0000000EU)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_TX_ULPS_EXIT_ESC_MAX                       (0x00000001U)

#define CSL_CSITX_DEBUG_DATA_LN_FSM_DATA_ULPS_ACTIVE_MASK                      (0x00008000U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_DATA_ULPS_ACTIVE_SHIFT                     (0x0000000FU)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_DATA_ULPS_ACTIVE_MAX                       (0x00000001U)

#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_ACTIVE_MASK                           (0x00010000U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_ACTIVE_SHIFT                          (0x00000010U)
#define CSL_CSITX_DEBUG_DATA_LN_FSM_ULPS_ACTIVE_MAX                            (0x00000001U)

/* DEBUG_PROT0_FSM */

#define CSL_CSITX_DEBUG_PROT0_FSM_PROT_FSM_IF0_MASK                            (0x0000007FU)
#define CSL_CSITX_DEBUG_PROT0_FSM_PROT_FSM_IF0_SHIFT                           (0x00000000U)
#define CSL_CSITX_DEBUG_PROT0_FSM_PROT_FSM_IF0_MAX                             (0x0000007FU)

#define CSL_CSITX_DEBUG_PROT0_FSM_PAYLOAD_FIFO_EMPTY_IF0_MASK                  (0x00000080U)
#define CSL_CSITX_DEBUG_PROT0_FSM_PAYLOAD_FIFO_EMPTY_IF0_SHIFT                 (0x00000007U)
#define CSL_CSITX_DEBUG_PROT0_FSM_PAYLOAD_FIFO_EMPTY_IF0_MAX                   (0x00000001U)

#define CSL_CSITX_DEBUG_PROT0_FSM_LAST_PAYLOAD_DATA_IF0_MASK                   (0x00000100U)
#define CSL_CSITX_DEBUG_PROT0_FSM_LAST_PAYLOAD_DATA_IF0_SHIFT                  (0x00000008U)
#define CSL_CSITX_DEBUG_PROT0_FSM_LAST_PAYLOAD_DATA_IF0_MAX                    (0x00000001U)

#define CSL_CSITX_DEBUG_PROT0_FSM_LINE_VALID_IF0_MASK                          (0x00000400U)
#define CSL_CSITX_DEBUG_PROT0_FSM_LINE_VALID_IF0_SHIFT                         (0x0000000AU)
#define CSL_CSITX_DEBUG_PROT0_FSM_LINE_VALID_IF0_MAX                           (0x00000001U)

#define CSL_CSITX_DEBUG_PROT0_FSM_FRAME_VALID_IF0_MASK                         (0x00000800U)
#define CSL_CSITX_DEBUG_PROT0_FSM_FRAME_VALID_IF0_SHIFT                        (0x0000000BU)
#define CSL_CSITX_DEBUG_PROT0_FSM_FRAME_VALID_IF0_MAX                          (0x00000001U)

#define CSL_CSITX_DEBUG_PROT0_FSM_DATA_TYPE_IF0_MASK                           (0x00007000U)
#define CSL_CSITX_DEBUG_PROT0_FSM_DATA_TYPE_IF0_SHIFT                          (0x0000000CU)
#define CSL_CSITX_DEBUG_PROT0_FSM_DATA_TYPE_IF0_MAX                            (0x00000007U)

#define CSL_CSITX_DEBUG_PROT0_FSM_VIRTUAL_CHANNEL_IF0_MASK                     (0x00078000U)
#define CSL_CSITX_DEBUG_PROT0_FSM_VIRTUAL_CHANNEL_IF0_SHIFT                    (0x0000000FU)
#define CSL_CSITX_DEBUG_PROT0_FSM_VIRTUAL_CHANNEL_IF0_MAX                      (0x0000000FU)

/* DEBUG_PROT1_FSM */

#define CSL_CSITX_DEBUG_PROT1_FSM_PROT_FSM_IF1_MASK                            (0x0000007FU)
#define CSL_CSITX_DEBUG_PROT1_FSM_PROT_FSM_IF1_SHIFT                           (0x00000000U)
#define CSL_CSITX_DEBUG_PROT1_FSM_PROT_FSM_IF1_MAX                             (0x0000007FU)

#define CSL_CSITX_DEBUG_PROT1_FSM_PAYLOAD_FIFO_EMPTY_IF1_MASK                  (0x00000080U)
#define CSL_CSITX_DEBUG_PROT1_FSM_PAYLOAD_FIFO_EMPTY_IF1_SHIFT                 (0x00000007U)
#define CSL_CSITX_DEBUG_PROT1_FSM_PAYLOAD_FIFO_EMPTY_IF1_MAX                   (0x00000001U)

#define CSL_CSITX_DEBUG_PROT1_FSM_LAST_PAYLOAD_DATA_IF1_MASK                   (0x00000100U)
#define CSL_CSITX_DEBUG_PROT1_FSM_LAST_PAYLOAD_DATA_IF1_SHIFT                  (0x00000008U)
#define CSL_CSITX_DEBUG_PROT1_FSM_LAST_PAYLOAD_DATA_IF1_MAX                    (0x00000001U)

#define CSL_CSITX_DEBUG_PROT1_FSM_LINE_VALID_IF1_MASK                          (0x00000400U)
#define CSL_CSITX_DEBUG_PROT1_FSM_LINE_VALID_IF1_SHIFT                         (0x0000000AU)
#define CSL_CSITX_DEBUG_PROT1_FSM_LINE_VALID_IF1_MAX                           (0x00000001U)

#define CSL_CSITX_DEBUG_PROT1_FSM_FRAME_VALID_IF1_MASK                         (0x00000800U)
#define CSL_CSITX_DEBUG_PROT1_FSM_FRAME_VALID_IF1_SHIFT                        (0x0000000BU)
#define CSL_CSITX_DEBUG_PROT1_FSM_FRAME_VALID_IF1_MAX                          (0x00000001U)

#define CSL_CSITX_DEBUG_PROT1_FSM_DATA_TYPE_IF1_MASK                           (0x00007000U)
#define CSL_CSITX_DEBUG_PROT1_FSM_DATA_TYPE_IF1_SHIFT                          (0x0000000CU)
#define CSL_CSITX_DEBUG_PROT1_FSM_DATA_TYPE_IF1_MAX                            (0x00000007U)

#define CSL_CSITX_DEBUG_PROT1_FSM_VIRTUAL_CHANNEL_IF1_MASK                     (0x00078000U)
#define CSL_CSITX_DEBUG_PROT1_FSM_VIRTUAL_CHANNEL_IF1_SHIFT                    (0x0000000FU)
#define CSL_CSITX_DEBUG_PROT1_FSM_VIRTUAL_CHANNEL_IF1_MAX                      (0x0000000FU)

/* DEBUG_PROT2_FSM */

#define CSL_CSITX_DEBUG_PROT2_FSM_PROT_FSM_IF2_MASK                            (0x0000007FU)
#define CSL_CSITX_DEBUG_PROT2_FSM_PROT_FSM_IF2_SHIFT                           (0x00000000U)
#define CSL_CSITX_DEBUG_PROT2_FSM_PROT_FSM_IF2_MAX                             (0x0000007FU)

#define CSL_CSITX_DEBUG_PROT2_FSM_PAYLOAD_FIFO_EMPTY_IF2_MASK                  (0x00000080U)
#define CSL_CSITX_DEBUG_PROT2_FSM_PAYLOAD_FIFO_EMPTY_IF2_SHIFT                 (0x00000007U)
#define CSL_CSITX_DEBUG_PROT2_FSM_PAYLOAD_FIFO_EMPTY_IF2_MAX                   (0x00000001U)

#define CSL_CSITX_DEBUG_PROT2_FSM_LAST_PAYLOAD_DATA_IF2_MASK                   (0x00000100U)
#define CSL_CSITX_DEBUG_PROT2_FSM_LAST_PAYLOAD_DATA_IF2_SHIFT                  (0x00000008U)
#define CSL_CSITX_DEBUG_PROT2_FSM_LAST_PAYLOAD_DATA_IF2_MAX                    (0x00000001U)

#define CSL_CSITX_DEBUG_PROT2_FSM_LINE_VALID_IF2_MASK                          (0x00000400U)
#define CSL_CSITX_DEBUG_PROT2_FSM_LINE_VALID_IF2_SHIFT                         (0x0000000AU)
#define CSL_CSITX_DEBUG_PROT2_FSM_LINE_VALID_IF2_MAX                           (0x00000001U)

#define CSL_CSITX_DEBUG_PROT2_FSM_FRAME_VALID_IF2_MASK                         (0x00000800U)
#define CSL_CSITX_DEBUG_PROT2_FSM_FRAME_VALID_IF2_SHIFT                        (0x0000000BU)
#define CSL_CSITX_DEBUG_PROT2_FSM_FRAME_VALID_IF2_MAX                          (0x00000001U)

#define CSL_CSITX_DEBUG_PROT2_FSM_DATA_TYPE_IF2_MASK                           (0x00007000U)
#define CSL_CSITX_DEBUG_PROT2_FSM_DATA_TYPE_IF2_SHIFT                          (0x0000000CU)
#define CSL_CSITX_DEBUG_PROT2_FSM_DATA_TYPE_IF2_MAX                            (0x00000007U)

#define CSL_CSITX_DEBUG_PROT2_FSM_VIRTUAL_CHANNEL_IF2_MASK                     (0x00078000U)
#define CSL_CSITX_DEBUG_PROT2_FSM_VIRTUAL_CHANNEL_IF2_SHIFT                    (0x0000000FU)
#define CSL_CSITX_DEBUG_PROT2_FSM_VIRTUAL_CHANNEL_IF2_MAX                      (0x0000000FU)

/* DEBUG_PROT3_FSM */

#define CSL_CSITX_DEBUG_PROT3_FSM_PROT_FSM_IF3_MASK                            (0x0000007FU)
#define CSL_CSITX_DEBUG_PROT3_FSM_PROT_FSM_IF3_SHIFT                           (0x00000000U)
#define CSL_CSITX_DEBUG_PROT3_FSM_PROT_FSM_IF3_MAX                             (0x0000007FU)

#define CSL_CSITX_DEBUG_PROT3_FSM_PAYLOAD_FIFO_EMPTY_IF3_MASK                  (0x00000080U)
#define CSL_CSITX_DEBUG_PROT3_FSM_PAYLOAD_FIFO_EMPTY_IF3_SHIFT                 (0x00000007U)
#define CSL_CSITX_DEBUG_PROT3_FSM_PAYLOAD_FIFO_EMPTY_IF3_MAX                   (0x00000001U)

#define CSL_CSITX_DEBUG_PROT3_FSM_LAST_PAYLOAD_DATA_IF3_MASK                   (0x00000100U)
#define CSL_CSITX_DEBUG_PROT3_FSM_LAST_PAYLOAD_DATA_IF3_SHIFT                  (0x00000008U)
#define CSL_CSITX_DEBUG_PROT3_FSM_LAST_PAYLOAD_DATA_IF3_MAX                    (0x00000001U)

#define CSL_CSITX_DEBUG_PROT3_FSM_LINE_VALID_IF3_MASK                          (0x00000400U)
#define CSL_CSITX_DEBUG_PROT3_FSM_LINE_VALID_IF3_SHIFT                         (0x0000000AU)
#define CSL_CSITX_DEBUG_PROT3_FSM_LINE_VALID_IF3_MAX                           (0x00000001U)

#define CSL_CSITX_DEBUG_PROT3_FSM_FRAME_VALID_IF3_MASK                         (0x00000800U)
#define CSL_CSITX_DEBUG_PROT3_FSM_FRAME_VALID_IF3_SHIFT                        (0x0000000BU)
#define CSL_CSITX_DEBUG_PROT3_FSM_FRAME_VALID_IF3_MAX                          (0x00000001U)

#define CSL_CSITX_DEBUG_PROT3_FSM_DATA_TYPE_IF3_MASK                           (0x00007000U)
#define CSL_CSITX_DEBUG_PROT3_FSM_DATA_TYPE_IF3_SHIFT                          (0x0000000CU)
#define CSL_CSITX_DEBUG_PROT3_FSM_DATA_TYPE_IF3_MAX                            (0x00000007U)

#define CSL_CSITX_DEBUG_PROT3_FSM_VIRTUAL_CHANNEL_IF3_MASK                     (0x00078000U)
#define CSL_CSITX_DEBUG_PROT3_FSM_VIRTUAL_CHANNEL_IF3_SHIFT                    (0x0000000FU)
#define CSL_CSITX_DEBUG_PROT3_FSM_VIRTUAL_CHANNEL_IF3_MAX                      (0x0000000FU)

/* DPHY_STATUS */

#define CSL_CSITX_DPHY_STATUS_DPHY_STOPSTATE_DL_MASK                           (0x0000000FU)
#define CSL_CSITX_DPHY_STATUS_DPHY_STOPSTATE_DL_SHIFT                          (0x00000000U)
#define CSL_CSITX_DPHY_STATUS_DPHY_STOPSTATE_DL_MAX                            (0x0000000FU)

#define CSL_CSITX_DPHY_STATUS_DPHY_STOPSTATE_CLK_MASK                          (0x00000010U)
#define CSL_CSITX_DPHY_STATUS_DPHY_STOPSTATE_CLK_SHIFT                         (0x00000004U)
#define CSL_CSITX_DPHY_STATUS_DPHY_STOPSTATE_CLK_MAX                           (0x00000001U)

#define CSL_CSITX_DPHY_STATUS_DPHY_ULPS_ACTIVE_N_DL_MASK                       (0x00000F00U)
#define CSL_CSITX_DPHY_STATUS_DPHY_ULPS_ACTIVE_N_DL_SHIFT                      (0x00000008U)
#define CSL_CSITX_DPHY_STATUS_DPHY_ULPS_ACTIVE_N_DL_MAX                        (0x0000000FU)

#define CSL_CSITX_DPHY_STATUS_DPHY_ULPS_ACTIVE_N_CLK_MASK                      (0x00001000U)
#define CSL_CSITX_DPHY_STATUS_DPHY_ULPS_ACTIVE_N_CLK_SHIFT                     (0x0000000CU)
#define CSL_CSITX_DPHY_STATUS_DPHY_ULPS_ACTIVE_N_CLK_MAX                       (0x00000001U)

/* DPHY_CFG1 */

#define CSL_CSITX_DPHY_CFG1_FORCE_STOP_MODE_TX0_MASK                           (0x0000000FU)
#define CSL_CSITX_DPHY_CFG1_FORCE_STOP_MODE_TX0_SHIFT                          (0x00000000U)
#define CSL_CSITX_DPHY_CFG1_FORCE_STOP_MODE_TX0_MAX                            (0x0000000FU)

#define CSL_CSITX_DPHY_CFG1_SWAP_DP_DN_TX0_MASK                                (0x000000F0U)
#define CSL_CSITX_DPHY_CFG1_SWAP_DP_DN_TX0_SHIFT                               (0x00000004U)
#define CSL_CSITX_DPHY_CFG1_SWAP_DP_DN_TX0_MAX                                 (0x0000000FU)

#define CSL_CSITX_DPHY_CFG1_SWAP_DP_DN_CTX_MASK                                (0x00000100U)
#define CSL_CSITX_DPHY_CFG1_SWAP_DP_DN_CTX_SHIFT                               (0x00000008U)
#define CSL_CSITX_DPHY_CFG1_SWAP_DP_DN_CTX_MAX                                 (0x00000001U)

#define CSL_CSITX_DPHY_CFG1_D_POWERDOWN_MASK                                   (0x00F00000U)
#define CSL_CSITX_DPHY_CFG1_D_POWERDOWN_SHIFT                                  (0x00000014U)
#define CSL_CSITX_DPHY_CFG1_D_POWERDOWN_MAX                                    (0x0000000FU)

#define CSL_CSITX_DPHY_CFG1_C_POWERDOWN_MASK                                   (0x01000000U)
#define CSL_CSITX_DPHY_CFG1_C_POWERDOWN_SHIFT                                  (0x00000018U)
#define CSL_CSITX_DPHY_CFG1_C_POWERDOWN_MAX                                    (0x00000001U)

#define CSL_CSITX_DPHY_CFG1_GEN_POWERDOWN_MASK                                 (0x0E000000U)
#define CSL_CSITX_DPHY_CFG1_GEN_POWERDOWN_SHIFT                                (0x00000019U)
#define CSL_CSITX_DPHY_CFG1_GEN_POWERDOWN_MAX                                  (0x00000007U)

/* GENERIC */

#define CSL_CSITX_GENERIC_TEST_GENERIC_CTRL_MASK                               (0x0000FFFFU)
#define CSL_CSITX_GENERIC_TEST_GENERIC_CTRL_SHIFT                              (0x00000000U)
#define CSL_CSITX_GENERIC_TEST_GENERIC_CTRL_MAX                                (0x0000FFFFU)

#define CSL_CSITX_GENERIC_TEST_GENERIC_STATUS_MASK                             (0xFFFF0000U)
#define CSL_CSITX_GENERIC_TEST_GENERIC_STATUS_SHIFT                            (0x00000010U)
#define CSL_CSITX_GENERIC_TEST_GENERIC_STATUS_MAX                              (0x0000FFFFU)

/* ASF_INT_STATUS */

#define CSL_CSITX_ASF_INT_STATUS_ASF_SRAM_CORR_ERR_MASK                        (0x00000001U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_SRAM_CORR_ERR_SHIFT                       (0x00000000U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_SRAM_CORR_ERR_MAX                         (0x00000001U)

#define CSL_CSITX_ASF_INT_STATUS_ASF_SRAM_UNCORR_ERR_MASK                      (0x00000002U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_SRAM_UNCORR_ERR_SHIFT                     (0x00000001U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_SRAM_UNCORR_ERR_MAX                       (0x00000001U)

#define CSL_CSITX_ASF_INT_STATUS_ASF_DAP_ERR_MASK                              (0x00000004U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_DAP_ERR_SHIFT                             (0x00000002U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_DAP_ERR_MAX                               (0x00000001U)

#define CSL_CSITX_ASF_INT_STATUS_ASF_CSR_ERR_MASK                              (0x00000008U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_CSR_ERR_SHIFT                             (0x00000003U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_CSR_ERR_MAX                               (0x00000001U)

#define CSL_CSITX_ASF_INT_STATUS_ASF_TRANS_TO_ERR_MASK                         (0x00000010U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_TRANS_TO_ERR_SHIFT                        (0x00000004U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_TRANS_TO_ERR_MAX                          (0x00000001U)

#define CSL_CSITX_ASF_INT_STATUS_ASF_PROTOCOL_ERR_MASK                         (0x00000020U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_PROTOCOL_ERR_SHIFT                        (0x00000005U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_PROTOCOL_ERR_MAX                          (0x00000001U)

#define CSL_CSITX_ASF_INT_STATUS_ASF_INTEGRITY_ERR_MASK                        (0x00000040U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_INTEGRITY_ERR_SHIFT                       (0x00000006U)
#define CSL_CSITX_ASF_INT_STATUS_ASF_INTEGRITY_ERR_MAX                         (0x00000001U)

#define CSL_CSITX_ASF_INT_STATUS_RESERVED_31_7_MASK                            (0xFFFFFF80U)
#define CSL_CSITX_ASF_INT_STATUS_RESERVED_31_7_SHIFT                           (0x00000007U)
#define CSL_CSITX_ASF_INT_STATUS_RESERVED_31_7_MAX                             (0x01FFFFFFU)

/* ASF_INT_RAW_STATUS */

#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_SRAM_CORR_ERR_MASK                    (0x00000001U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_SRAM_CORR_ERR_SHIFT                   (0x00000000U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_SRAM_CORR_ERR_MAX                     (0x00000001U)

#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_SRAM_UNCORR_ERR_MASK                  (0x00000002U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_SRAM_UNCORR_ERR_SHIFT                 (0x00000001U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_SRAM_UNCORR_ERR_MAX                   (0x00000001U)

#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_DAP_ERR_MASK                          (0x00000004U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_DAP_ERR_SHIFT                         (0x00000002U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_DAP_ERR_MAX                           (0x00000001U)

#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_CSR_ERR_MASK                          (0x00000008U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_CSR_ERR_SHIFT                         (0x00000003U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_CSR_ERR_MAX                           (0x00000001U)

#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_TRANS_TO_ERR_MASK                     (0x00000010U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_TRANS_TO_ERR_SHIFT                    (0x00000004U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_TRANS_TO_ERR_MAX                      (0x00000001U)

#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_PROTOCOL_ERR_MASK                     (0x00000020U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_PROTOCOL_ERR_SHIFT                    (0x00000005U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_PROTOCOL_ERR_MAX                      (0x00000001U)

#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_INTEGRITY_ERR_MASK                    (0x00000040U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_INTEGRITY_ERR_SHIFT                   (0x00000006U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_ASF_INTEGRITY_ERR_MAX                     (0x00000001U)

#define CSL_CSITX_ASF_INT_RAW_STATUS_RESERVED_31_7_MASK                        (0xFFFFFF80U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_RESERVED_31_7_SHIFT                       (0x00000007U)
#define CSL_CSITX_ASF_INT_RAW_STATUS_RESERVED_31_7_MAX                         (0x01FFFFFFU)

/* ASF_INT_MASK */

#define CSL_CSITX_ASF_INT_MASK_ASF_SRAM_CORR_ERR_MASK_MASK                     (0x00000001U)
#define CSL_CSITX_ASF_INT_MASK_ASF_SRAM_CORR_ERR_MASK_SHIFT                    (0x00000000U)
#define CSL_CSITX_ASF_INT_MASK_ASF_SRAM_CORR_ERR_MASK_MAX                      (0x00000001U)

#define CSL_CSITX_ASF_INT_MASK_ASF_SRAM_UNCORR_ERR_MASK_MASK                   (0x00000002U)
#define CSL_CSITX_ASF_INT_MASK_ASF_SRAM_UNCORR_ERR_MASK_SHIFT                  (0x00000001U)
#define CSL_CSITX_ASF_INT_MASK_ASF_SRAM_UNCORR_ERR_MASK_MAX                    (0x00000001U)

#define CSL_CSITX_ASF_INT_MASK_ASF_DAP_ERR_MASK_MASK                           (0x00000004U)
#define CSL_CSITX_ASF_INT_MASK_ASF_DAP_ERR_MASK_SHIFT                          (0x00000002U)
#define CSL_CSITX_ASF_INT_MASK_ASF_DAP_ERR_MASK_MAX                            (0x00000001U)

#define CSL_CSITX_ASF_INT_MASK_ASF_CSR_ERR_MASK_MASK                           (0x00000008U)
#define CSL_CSITX_ASF_INT_MASK_ASF_CSR_ERR_MASK_SHIFT                          (0x00000003U)
#define CSL_CSITX_ASF_INT_MASK_ASF_CSR_ERR_MASK_MAX                            (0x00000001U)

#define CSL_CSITX_ASF_INT_MASK_ASF_TRANS_TO_ERR_MASK_MASK                      (0x00000010U)
#define CSL_CSITX_ASF_INT_MASK_ASF_TRANS_TO_ERR_MASK_SHIFT                     (0x00000004U)
#define CSL_CSITX_ASF_INT_MASK_ASF_TRANS_TO_ERR_MASK_MAX                       (0x00000001U)

#define CSL_CSITX_ASF_INT_MASK_ASF_PROTOCOL_ERR_MASK_MASK                      (0x00000020U)
#define CSL_CSITX_ASF_INT_MASK_ASF_PROTOCOL_ERR_MASK_SHIFT                     (0x00000005U)
#define CSL_CSITX_ASF_INT_MASK_ASF_PROTOCOL_ERR_MASK_MAX                       (0x00000001U)

#define CSL_CSITX_ASF_INT_MASK_ASF_INTEGRITY_ERR_MASK_MASK                     (0x00000040U)
#define CSL_CSITX_ASF_INT_MASK_ASF_INTEGRITY_ERR_MASK_SHIFT                    (0x00000006U)
#define CSL_CSITX_ASF_INT_MASK_ASF_INTEGRITY_ERR_MASK_MAX                      (0x00000001U)

#define CSL_CSITX_ASF_INT_MASK_RESERVED_31_7_MASK                              (0xFFFFFF80U)
#define CSL_CSITX_ASF_INT_MASK_RESERVED_31_7_SHIFT                             (0x00000007U)
#define CSL_CSITX_ASF_INT_MASK_RESERVED_31_7_MAX                               (0x01FFFFFFU)

/* ASF_INT_TEST */

#define CSL_CSITX_ASF_INT_TEST_ASF_SRAM_CORR_ERR_TEST_MASK                     (0x00000001U)
#define CSL_CSITX_ASF_INT_TEST_ASF_SRAM_CORR_ERR_TEST_SHIFT                    (0x00000000U)
#define CSL_CSITX_ASF_INT_TEST_ASF_SRAM_CORR_ERR_TEST_MAX                      (0x00000001U)

#define CSL_CSITX_ASF_INT_TEST_ASF_SRAM_UNCORR_ERR_TEST_MASK                   (0x00000002U)
#define CSL_CSITX_ASF_INT_TEST_ASF_SRAM_UNCORR_ERR_TEST_SHIFT                  (0x00000001U)
#define CSL_CSITX_ASF_INT_TEST_ASF_SRAM_UNCORR_ERR_TEST_MAX                    (0x00000001U)

#define CSL_CSITX_ASF_INT_TEST_ASF_DAP_ERR_TEST_MASK                           (0x00000004U)
#define CSL_CSITX_ASF_INT_TEST_ASF_DAP_ERR_TEST_SHIFT                          (0x00000002U)
#define CSL_CSITX_ASF_INT_TEST_ASF_DAP_ERR_TEST_MAX                            (0x00000001U)

#define CSL_CSITX_ASF_INT_TEST_ASF_CSR_ERR_TEST_MASK                           (0x00000008U)
#define CSL_CSITX_ASF_INT_TEST_ASF_CSR_ERR_TEST_SHIFT                          (0x00000003U)
#define CSL_CSITX_ASF_INT_TEST_ASF_CSR_ERR_TEST_MAX                            (0x00000001U)

#define CSL_CSITX_ASF_INT_TEST_ASF_TRANS_TO_ERR_TEST_MASK                      (0x00000010U)
#define CSL_CSITX_ASF_INT_TEST_ASF_TRANS_TO_ERR_TEST_SHIFT                     (0x00000004U)
#define CSL_CSITX_ASF_INT_TEST_ASF_TRANS_TO_ERR_TEST_MAX                       (0x00000001U)

#define CSL_CSITX_ASF_INT_TEST_ASF_PROTOCOL_ERR_TEST_MASK                      (0x00000020U)
#define CSL_CSITX_ASF_INT_TEST_ASF_PROTOCOL_ERR_TEST_SHIFT                     (0x00000005U)
#define CSL_CSITX_ASF_INT_TEST_ASF_PROTOCOL_ERR_TEST_MAX                       (0x00000001U)

#define CSL_CSITX_ASF_INT_TEST_ASF_INTEGRITY_ERR_TEST_MASK                     (0x00000040U)
#define CSL_CSITX_ASF_INT_TEST_ASF_INTEGRITY_ERR_TEST_SHIFT                    (0x00000006U)
#define CSL_CSITX_ASF_INT_TEST_ASF_INTEGRITY_ERR_TEST_MAX                      (0x00000001U)

#define CSL_CSITX_ASF_INT_TEST_RESERVED_31_7_MASK                              (0xFFFFFF80U)
#define CSL_CSITX_ASF_INT_TEST_RESERVED_31_7_SHIFT                             (0x00000007U)
#define CSL_CSITX_ASF_INT_TEST_RESERVED_31_7_MAX                               (0x01FFFFFFU)

/* ASF_FATAL_NONFATAL_SELECT */

#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_CORR_ERR_MASK             (0x00000001U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_CORR_ERR_SHIFT            (0x00000000U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_CORR_ERR_MAX              (0x00000001U)

#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_UNCORR_ERR_MASK           (0x00000002U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_UNCORR_ERR_SHIFT          (0x00000001U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_SRAM_UNCORR_ERR_MAX            (0x00000001U)

#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_DAP_ERR_MASK                   (0x00000004U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_DAP_ERR_SHIFT                  (0x00000002U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_DAP_ERR_MAX                    (0x00000001U)

#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_CSR_ERR_MASK                   (0x00000008U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_CSR_ERR_SHIFT                  (0x00000003U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_CSR_ERR_MAX                    (0x00000001U)

#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_TRANS_TO_ERR_MASK              (0x00000010U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_TRANS_TO_ERR_SHIFT             (0x00000004U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_TRANS_TO_ERR_MAX               (0x00000001U)

#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_PROTOCOL_ERR_MASK              (0x00000020U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_PROTOCOL_ERR_SHIFT             (0x00000005U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_PROTOCOL_ERR_MAX               (0x00000001U)

#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_INTEGRITY_ERR_MASK             (0x00000040U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_INTEGRITY_ERR_SHIFT            (0x00000006U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_ASF_INTEGRITY_ERR_MAX              (0x00000001U)

#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_RESERVED_31_7_MASK                 (0xFFFFFF80U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_RESERVED_31_7_SHIFT                (0x00000007U)
#define CSL_CSITX_ASF_FATAL_NONFATAL_SELECT_RESERVED_31_7_MAX                  (0x01FFFFFFU)

/* ASF_SRAM_CORR_FAULT_STATUS */

#define CSL_CSITX_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_ADDR_MASK     (0x00FFFFFFU)
#define CSL_CSITX_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_ADDR_SHIFT    (0x00000000U)
#define CSL_CSITX_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_ADDR_MAX      (0x00FFFFFFU)

#define CSL_CSITX_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_INST_MASK     (0xFF000000U)
#define CSL_CSITX_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_INST_SHIFT    (0x00000018U)
#define CSL_CSITX_ASF_SRAM_CORR_FAULT_STATUS_ASF_SRAM_CORR_FAULT_INST_MAX      (0x000000FFU)

/* ASF_SRAM_UNCORR_FAULT_STATUS */

#define CSL_CSITX_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_ADDR_MASK (0x00FFFFFFU)
#define CSL_CSITX_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_ADDR_SHIFT (0x00000000U)
#define CSL_CSITX_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_ADDR_MAX  (0x00FFFFFFU)

#define CSL_CSITX_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_INST_MASK (0xFF000000U)
#define CSL_CSITX_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_INST_SHIFT (0x00000018U)
#define CSL_CSITX_ASF_SRAM_UNCORR_FAULT_STATUS_ASF_SRAM_UNCORR_FAULT_INST_MAX  (0x000000FFU)

/* ASF_SRAM_FAULT_STATS */

#define CSL_CSITX_ASF_SRAM_FAULT_STATS_ASF_SRAM_FAULT_CORR_STATS_MASK          (0x0000FFFFU)
#define CSL_CSITX_ASF_SRAM_FAULT_STATS_ASF_SRAM_FAULT_CORR_STATS_SHIFT         (0x00000000U)
#define CSL_CSITX_ASF_SRAM_FAULT_STATS_ASF_SRAM_FAULT_CORR_STATS_MAX           (0x0000FFFFU)

#define CSL_CSITX_ASF_SRAM_FAULT_STATS_RESERVED_31_16_MASK                     (0xFFFF0000U)
#define CSL_CSITX_ASF_SRAM_FAULT_STATS_RESERVED_31_16_SHIFT                    (0x00000010U)
#define CSL_CSITX_ASF_SRAM_FAULT_STATS_RESERVED_31_16_MAX                      (0x0000FFFFU)

/* ASF_TRANS_TO_CTRL */

#define CSL_CSITX_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_CTRL_MASK                     (0x0000FFFFU)
#define CSL_CSITX_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_CTRL_SHIFT                    (0x00000000U)
#define CSL_CSITX_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_CTRL_MAX                      (0x0000FFFFU)

#define CSL_CSITX_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_EN_MASK                       (0x80000000U)
#define CSL_CSITX_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_EN_SHIFT                      (0x0000001FU)
#define CSL_CSITX_ASF_TRANS_TO_CTRL_ASF_TRANS_TO_EN_MAX                        (0x00000001U)

/* ASF_TRANS_TO_FAULT_MASK */

#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_0_MASK_MASK       (0x00000001U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_0_MASK_SHIFT      (0x00000000U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_0_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_1_MASK_MASK       (0x00000002U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_1_MASK_SHIFT      (0x00000001U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_1_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_2_MASK_MASK       (0x00000004U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_2_MASK_SHIFT      (0x00000002U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_2_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_3_MASK_MASK       (0x00000008U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_3_MASK_SHIFT      (0x00000003U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_3_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_4_MASK_MASK       (0x00000010U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_4_MASK_SHIFT      (0x00000004U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_MASK_ASF_TRANS_TO_FAULT_4_MASK_MAX        (0x00000001U)

/* ASF_TRANS_TO_FAULT_STATUS */

#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_0_STATUS_MASK   (0x00000001U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_0_STATUS_SHIFT  (0x00000000U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_0_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_1_STATUS_MASK   (0x00000002U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_1_STATUS_SHIFT  (0x00000001U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_1_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_2_STATUS_MASK   (0x00000004U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_2_STATUS_SHIFT  (0x00000002U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_2_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_3_STATUS_MASK   (0x00000008U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_3_STATUS_SHIFT  (0x00000003U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_3_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_4_STATUS_MASK   (0x00000010U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_4_STATUS_SHIFT  (0x00000004U)
#define CSL_CSITX_ASF_TRANS_TO_FAULT_STATUS_ASF_TRANS_TO_FAULT_4_STATUS_MAX    (0x00000001U)

/* ASF_PROTOCOL_FAULT_MASK */

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_0_MASK_MASK       (0x00000001U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_0_MASK_SHIFT      (0x00000000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_0_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_1_MASK_MASK       (0x00000002U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_1_MASK_SHIFT      (0x00000001U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_1_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_2_MASK_MASK       (0x00000004U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_2_MASK_SHIFT      (0x00000002U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_2_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_3_MASK_MASK       (0x00000008U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_3_MASK_SHIFT      (0x00000003U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_3_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_4_MASK_MASK       (0x00000010U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_4_MASK_SHIFT      (0x00000004U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_4_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_5_MASK_MASK       (0x00000020U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_5_MASK_SHIFT      (0x00000005U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_5_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_6_MASK_MASK       (0x00000040U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_6_MASK_SHIFT      (0x00000006U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_6_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_7_MASK_MASK       (0x00000080U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_7_MASK_SHIFT      (0x00000007U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_7_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_8_MASK_MASK       (0x00000100U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_8_MASK_SHIFT      (0x00000008U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_8_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_9_MASK_MASK       (0x00000200U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_9_MASK_SHIFT      (0x00000009U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_9_MASK_MAX        (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_10_MASK_MASK      (0x00000400U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_10_MASK_SHIFT     (0x0000000AU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_10_MASK_MAX       (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_11_MASK_MASK      (0x00000800U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_11_MASK_SHIFT     (0x0000000BU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_11_MASK_MAX       (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_12_MASK_MASK      (0x00001000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_12_MASK_SHIFT     (0x0000000CU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_12_MASK_MAX       (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_13_MASK_MASK      (0x00002000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_13_MASK_SHIFT     (0x0000000DU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_13_MASK_MAX       (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_14_MASK_MASK      (0x00004000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_14_MASK_SHIFT     (0x0000000EU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_14_MASK_MAX       (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_15_MASK_MASK      (0x00008000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_15_MASK_SHIFT     (0x0000000FU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_15_MASK_MAX       (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_16_MASK_MASK      (0x00010000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_16_MASK_SHIFT     (0x00000010U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_MASK_ASF_PROTOCOL_FAULT_16_MASK_MAX       (0x00000001U)

/* ASF_PROTOCOL_FAULT_STATUS */

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_0_STATUS_MASK   (0x00000001U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_0_STATUS_SHIFT  (0x00000000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_0_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_1_STATUS_MASK   (0x00000002U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_1_STATUS_SHIFT  (0x00000001U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_1_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_2_STATUS_MASK   (0x00000004U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_2_STATUS_SHIFT  (0x00000002U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_2_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_3_STATUS_MASK   (0x00000008U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_3_STATUS_SHIFT  (0x00000003U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_3_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_4_STATUS_MASK   (0x00000010U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_4_STATUS_SHIFT  (0x00000004U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_4_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_5_STATUS_MASK   (0x00000020U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_5_STATUS_SHIFT  (0x00000005U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_5_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_6_STATUS_MASK   (0x00000040U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_6_STATUS_SHIFT  (0x00000006U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_6_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_7_STATUS_MASK   (0x00000080U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_7_STATUS_SHIFT  (0x00000007U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_7_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_8_STATUS_MASK   (0x00000100U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_8_STATUS_SHIFT  (0x00000008U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_8_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_9_STATUS_MASK   (0x00000200U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_9_STATUS_SHIFT  (0x00000009U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_9_STATUS_MAX    (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_10_STATUS_MASK  (0x00000400U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_10_STATUS_SHIFT (0x0000000AU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_10_STATUS_MAX   (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_11_STATUS_MASK  (0x00000800U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_11_STATUS_SHIFT (0x0000000BU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_11_STATUS_MAX   (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_12_STATUS_MASK  (0x00001000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_12_STATUS_SHIFT (0x0000000CU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_12_STATUS_MAX   (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_13_STATUS_MASK  (0x00002000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_13_STATUS_SHIFT (0x0000000DU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_13_STATUS_MAX   (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_14_STATUS_MASK  (0x00004000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_14_STATUS_SHIFT (0x0000000EU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_14_STATUS_MAX   (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_15_STATUS_MASK  (0x00008000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_15_STATUS_SHIFT (0x0000000FU)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_15_STATUS_MAX   (0x00000001U)

#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_16_STATUS_MASK  (0x00010000U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_16_STATUS_SHIFT (0x00000010U)
#define CSL_CSITX_ASF_PROTOCOL_FAULT_STATUS_ASF_PROTOCOL_FAULT_16_STATUS_MAX   (0x00000001U)

/* ID_PROD_VER */

#define CSL_CSITX_ID_PROD_VER_VERSION_ID_MASK                                  (0x0000FFFFU)
#define CSL_CSITX_ID_PROD_VER_VERSION_ID_SHIFT                                 (0x00000000U)
#define CSL_CSITX_ID_PROD_VER_VERSION_ID_MAX                                   (0x0000FFFFU)

#define CSL_CSITX_ID_PROD_VER_PRODUCT_ID_MASK                                  (0xFFFF0000U)
#define CSL_CSITX_ID_PROD_VER_PRODUCT_ID_SHIFT                                 (0x00000010U)
#define CSL_CSITX_ID_PROD_VER_PRODUCT_ID_MAX                                   (0x0000FFFFU)

#ifdef __cplusplus
}
#endif
#endif
