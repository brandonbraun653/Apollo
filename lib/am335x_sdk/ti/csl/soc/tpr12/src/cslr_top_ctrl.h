/********************************************************************
 * Copyright (C) 2020 Texas Instruments Incorporated.
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
 *  Name        : cslr_top_ctrl.h
*/
#ifndef CSLR_TOP_CTRL_H_
#define CSLR_TOP_CTRL_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  :
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t PID;
    volatile uint32_t MDO_CTRL;
    volatile uint32_t PROBE_BUS_SEL0;
    volatile uint32_t PROBE_BUS_SEL1;
    volatile uint8_t  Resv_512[496];
    volatile uint32_t EFUSE_DIEID0;
    volatile uint32_t EFUSE_DIEID1;
    volatile uint32_t EFUSE_DIEID2;
    volatile uint32_t EFUSE_DIEID3;
    volatile uint32_t EFUSE_UID0;
    volatile uint32_t EFUSE_UID1;
    volatile uint32_t EFUSE_UID2;
    volatile uint32_t EFUSE_UID3;
    volatile uint32_t EFUSE_DEVICE_TYPE;
    volatile uint32_t EFUSE_FROM0_CHECKSUM;
    volatile uint32_t EFUSE_ROM_SEQ_UPDATE0;
    volatile uint32_t EFUSE_ROM_SEQ_UPDATE1;
    volatile uint32_t EFUSE_ROM_SEQ_UPDATE2;
    volatile uint32_t EFUSE_ROM_SEQ_UPDATE3;
    volatile uint32_t EFUSE_ROM_SEQ_UPDATE4;
    volatile uint32_t EFUSE_ROM_SEQ_UPDATE5;
    volatile uint32_t EFUSE_ROM_SEQ_UPDATE6;
    volatile uint32_t EFUSE_ROM_SEQ_UPDATE7;
    volatile uint32_t EFUSE_ROM_SEQ_UPDATE8;
    volatile uint8_t  Resv_1024[436];
    volatile uint32_t EFUSE0_ROW_61;
    volatile uint32_t EFUSE0_ROW_62;
    volatile uint32_t EFUSE0_ROW_63;
    volatile uint32_t EFUSE1_ROW_5;
    volatile uint32_t EFUSE1_ROW_6;
    volatile uint32_t EFUSE1_ROW_7;
    volatile uint32_t EFUSE1_ROW_8;
    volatile uint32_t EFUSE1_ROW_9;
    volatile uint32_t EFUSE1_ROW_10;
    volatile uint32_t EFUSE1_ROW_11;
    volatile uint32_t EFUSE1_ROW_12;
    volatile uint32_t EFUSE1_ROW_13;
    volatile uint32_t EFUSE1_ROW_14;
    volatile uint32_t EFUSE1_ROW_15;
    volatile uint32_t EFUSE1_ROW_16;
    volatile uint32_t EFUSE1_ROW_17;
    volatile uint32_t EFUSE1_ROW_18;
    volatile uint32_t EFUSE1_ROW_19;
    volatile uint32_t EFUSE1_ROW_20;
    volatile uint32_t EFUSE1_ROW_21;
    volatile uint32_t EFUSE1_ROW_22;
    volatile uint32_t EFUSE1_ROW_23;
    volatile uint32_t EFUSE1_ROW_24;
    volatile uint32_t EFUSE1_ROW_25;
    volatile uint32_t EFUSE1_ROW_26;
    volatile uint32_t EFUSE1_ROW_27;
    volatile uint32_t EFUSE1_ROW_28;
    volatile uint32_t EFUSE1_ROW_29;
    volatile uint32_t EFUSE1_ROW_30;
    volatile uint32_t EFUSE1_ROW_31;
    volatile uint32_t EFUSE1_ROW_32;
    volatile uint32_t EFUSE1_ROW_33;
    volatile uint32_t EFUSE1_ROW_34;
    volatile uint32_t EFUSE1_ROW_35;
    volatile uint32_t EFUSE1_ROW_36;
    volatile uint32_t EFUSE1_ROW_37;
    volatile uint32_t EFUSE1_ROW_38;
    volatile uint32_t EFUSE1_ROW_39;
    volatile uint32_t EFUSE1_ROW_40;
    volatile uint32_t EFUSE1_ROW_41;
    volatile uint32_t EFUSE1_ROW_42;
    volatile uint32_t EFUSE1_ROW_43;
    volatile uint8_t  Resv_2048[856];
    volatile uint32_t EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN;
    volatile uint32_t EFUSE_OVERRIDE_MEM_MARGINCTRL;
    volatile uint32_t EFUSE_OVERRIDE_LVDS_BGAP_TRIM;
    volatile uint32_t EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT;
    volatile uint32_t EFUSE_OVERRIDE_SLICER_BIAS_RTRIM;
    volatile uint32_t EFUSE_OVERRIDE_XO_OUTPUT_DRIVE;
    volatile uint32_t EFUSE_OVERRIDE_RCOSC_TRIM_CODE;
    volatile uint32_t EFUSE_OVERRIDE_IP1_BG1_RTRIM;
    volatile uint32_t EFUSE_OVERRIDE_IP1_BG1_SLOPE;
    volatile uint32_t EFUSE_OVERRIDE_IP1_BG1_MAG;
    volatile uint32_t EFUSE_OVERRIDE_RS232_CLKMODE;
    volatile uint32_t EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM;
    volatile uint32_t EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM;
    volatile uint32_t EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM;
    volatile uint32_t EFUSE_OVERRIDE_VDD_VT_DET;
    volatile uint32_t EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL;
    volatile uint32_t EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL;
    volatile uint32_t EFUSE_OVERRIDE_EN_VOL_MON_FUNC;
    volatile uint8_t  Resv_4104[1984];
    volatile uint32_t LOCK0_KICK0;
    volatile uint32_t LOCK0_KICK1;
    volatile uint32_t INTR_RAW_STATUS;
    volatile uint32_t INTR_ENABLED_STATUS_CLEAR;
    volatile uint32_t INTR_ENABLE;
    volatile uint32_t INTR_ENABLE_CLEAR;
    volatile uint32_t EOI;
    volatile uint32_t FAULT_ADDRESS;
    volatile uint32_t FAULT_TYPE_STATUS;
    volatile uint32_t FAULT_ATTR_STATUS;
    volatile uint32_t FAULT_CLEAR;
} CSL_top_ctrlRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_TOP_CTRL_PID                                                       (0x00000000U)
#define CSL_TOP_CTRL_MDO_CTRL                                                  (0x00000004U)
#define CSL_TOP_CTRL_PROBE_BUS_SEL0                                            (0x00000008U)
#define CSL_TOP_CTRL_PROBE_BUS_SEL1                                            (0x0000000CU)
#define CSL_TOP_CTRL_EFUSE_DIEID0                                              (0x00000200U)
#define CSL_TOP_CTRL_EFUSE_DIEID1                                              (0x00000204U)
#define CSL_TOP_CTRL_EFUSE_DIEID2                                              (0x00000208U)
#define CSL_TOP_CTRL_EFUSE_DIEID3                                              (0x0000020CU)
#define CSL_TOP_CTRL_EFUSE_UID0                                                (0x00000210U)
#define CSL_TOP_CTRL_EFUSE_UID1                                                (0x00000214U)
#define CSL_TOP_CTRL_EFUSE_UID2                                                (0x00000218U)
#define CSL_TOP_CTRL_EFUSE_UID3                                                (0x0000021CU)
#define CSL_TOP_CTRL_EFUSE_DEVICE_TYPE                                         (0x00000220U)
#define CSL_TOP_CTRL_EFUSE_FROM0_CHECKSUM                                      (0x00000224U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE0                                     (0x00000228U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE1                                     (0x0000022CU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE2                                     (0x00000230U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE3                                     (0x00000234U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE4                                     (0x00000238U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE5                                     (0x0000023CU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE6                                     (0x00000240U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE7                                     (0x00000244U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE8                                     (0x00000248U)
#define CSL_TOP_CTRL_EFUSE0_ROW_61                                             (0x00000400U)
#define CSL_TOP_CTRL_EFUSE0_ROW_62                                             (0x00000404U)
#define CSL_TOP_CTRL_EFUSE0_ROW_63                                             (0x00000408U)
#define CSL_TOP_CTRL_EFUSE1_ROW_5                                              (0x0000040CU)
#define CSL_TOP_CTRL_EFUSE1_ROW_6                                              (0x00000410U)
#define CSL_TOP_CTRL_EFUSE1_ROW_7                                              (0x00000414U)
#define CSL_TOP_CTRL_EFUSE1_ROW_8                                              (0x00000418U)
#define CSL_TOP_CTRL_EFUSE1_ROW_9                                              (0x0000041CU)
#define CSL_TOP_CTRL_EFUSE1_ROW_10                                             (0x00000420U)
#define CSL_TOP_CTRL_EFUSE1_ROW_11                                             (0x00000424U)
#define CSL_TOP_CTRL_EFUSE1_ROW_12                                             (0x00000428U)
#define CSL_TOP_CTRL_EFUSE1_ROW_13                                             (0x0000042CU)
#define CSL_TOP_CTRL_EFUSE1_ROW_14                                             (0x00000430U)
#define CSL_TOP_CTRL_EFUSE1_ROW_15                                             (0x00000434U)
#define CSL_TOP_CTRL_EFUSE1_ROW_16                                             (0x00000438U)
#define CSL_TOP_CTRL_EFUSE1_ROW_17                                             (0x0000043CU)
#define CSL_TOP_CTRL_EFUSE1_ROW_18                                             (0x00000440U)
#define CSL_TOP_CTRL_EFUSE1_ROW_19                                             (0x00000444U)
#define CSL_TOP_CTRL_EFUSE1_ROW_20                                             (0x00000448U)
#define CSL_TOP_CTRL_EFUSE1_ROW_21                                             (0x0000044CU)
#define CSL_TOP_CTRL_EFUSE1_ROW_22                                             (0x00000450U)
#define CSL_TOP_CTRL_EFUSE1_ROW_23                                             (0x00000454U)
#define CSL_TOP_CTRL_EFUSE1_ROW_24                                             (0x00000458U)
#define CSL_TOP_CTRL_EFUSE1_ROW_25                                             (0x0000045CU)
#define CSL_TOP_CTRL_EFUSE1_ROW_26                                             (0x00000460U)
#define CSL_TOP_CTRL_EFUSE1_ROW_27                                             (0x00000464U)
#define CSL_TOP_CTRL_EFUSE1_ROW_28                                             (0x00000468U)
#define CSL_TOP_CTRL_EFUSE1_ROW_29                                             (0x0000046CU)
#define CSL_TOP_CTRL_EFUSE1_ROW_30                                             (0x00000470U)
#define CSL_TOP_CTRL_EFUSE1_ROW_31                                             (0x00000474U)
#define CSL_TOP_CTRL_EFUSE1_ROW_32                                             (0x00000478U)
#define CSL_TOP_CTRL_EFUSE1_ROW_33                                             (0x0000047CU)
#define CSL_TOP_CTRL_EFUSE1_ROW_34                                             (0x00000480U)
#define CSL_TOP_CTRL_EFUSE1_ROW_35                                             (0x00000484U)
#define CSL_TOP_CTRL_EFUSE1_ROW_36                                             (0x00000488U)
#define CSL_TOP_CTRL_EFUSE1_ROW_37                                             (0x0000048CU)
#define CSL_TOP_CTRL_EFUSE1_ROW_38                                             (0x00000490U)
#define CSL_TOP_CTRL_EFUSE1_ROW_39                                             (0x00000494U)
#define CSL_TOP_CTRL_EFUSE1_ROW_40                                             (0x00000498U)
#define CSL_TOP_CTRL_EFUSE1_ROW_41                                             (0x0000049CU)
#define CSL_TOP_CTRL_EFUSE1_ROW_42                                             (0x000004A0U)
#define CSL_TOP_CTRL_EFUSE1_ROW_43                                             (0x000004A4U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN                 (0x00000800U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL                             (0x00000804U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_LVDS_BGAP_TRIM                             (0x00000808U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT                     (0x0000080CU)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_SLICER_BIAS_RTRIM                          (0x00000810U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XO_OUTPUT_DRIVE                            (0x00000814U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RCOSC_TRIM_CODE                            (0x00000818U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_RTRIM                              (0x0000081CU)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_SLOPE                              (0x00000820U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_MAG                                (0x00000824U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RS232_CLKMODE                              (0x00000828U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM                        (0x0000082CU)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM                      (0x00000830U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM                         (0x00000834U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VDD_VT_DET                                 (0x00000838U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL             (0x0000083CU)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL             (0x00000840U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_EN_VOL_MON_FUNC                            (0x00000844U)
#define CSL_TOP_CTRL_LOCK0_KICK0                                               (0x00001008U)
#define CSL_TOP_CTRL_LOCK0_KICK1                                               (0x0000100CU)
#define CSL_TOP_CTRL_INTR_RAW_STATUS                                           (0x00001010U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR                                 (0x00001014U)
#define CSL_TOP_CTRL_INTR_ENABLE                                               (0x00001018U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR                                         (0x0000101CU)
#define CSL_TOP_CTRL_EOI                                                       (0x00001020U)
#define CSL_TOP_CTRL_FAULT_ADDRESS                                             (0x00001024U)
#define CSL_TOP_CTRL_FAULT_TYPE_STATUS                                         (0x00001028U)
#define CSL_TOP_CTRL_FAULT_ATTR_STATUS                                         (0x0000102CU)
#define CSL_TOP_CTRL_FAULT_CLEAR                                               (0x00001030U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_TOP_CTRL_PID_PID_MINOR_MASK                                        (0x0000003FU)
#define CSL_TOP_CTRL_PID_PID_MINOR_SHIFT                                       (0x00000000U)
#define CSL_TOP_CTRL_PID_PID_MINOR_RESETVAL                                    (0x00000013U)
#define CSL_TOP_CTRL_PID_PID_MINOR_MAX                                         (0x0000003FU)

#define CSL_TOP_CTRL_PID_PID_CUSTOM_MASK                                       (0x000000C0U)
#define CSL_TOP_CTRL_PID_PID_CUSTOM_SHIFT                                      (0x00000006U)
#define CSL_TOP_CTRL_PID_PID_CUSTOM_RESETVAL                                   (0x00000000U)
#define CSL_TOP_CTRL_PID_PID_CUSTOM_MAX                                        (0x00000003U)

#define CSL_TOP_CTRL_PID_PID_MAJOR_MASK                                        (0x00000700U)
#define CSL_TOP_CTRL_PID_PID_MAJOR_SHIFT                                       (0x00000008U)
#define CSL_TOP_CTRL_PID_PID_MAJOR_RESETVAL                                    (0x00000002U)
#define CSL_TOP_CTRL_PID_PID_MAJOR_MAX                                         (0x00000007U)

#define CSL_TOP_CTRL_PID_PID_MISC_MASK                                         (0x0000F800U)
#define CSL_TOP_CTRL_PID_PID_MISC_SHIFT                                        (0x0000000BU)
#define CSL_TOP_CTRL_PID_PID_MISC_RESETVAL                                     (0x00000000U)
#define CSL_TOP_CTRL_PID_PID_MISC_MAX                                          (0x0000001FU)

#define CSL_TOP_CTRL_PID_PID_MSB16_MASK                                        (0xFFFF0000U)
#define CSL_TOP_CTRL_PID_PID_MSB16_SHIFT                                       (0x00000010U)
#define CSL_TOP_CTRL_PID_PID_MSB16_RESETVAL                                    (0x00006180U)
#define CSL_TOP_CTRL_PID_PID_MSB16_MAX                                         (0x0000FFFFU)

#define CSL_TOP_CTRL_PID_RESETVAL                                              (0x61800213U)

/* MDO_CTRL */

#define CSL_TOP_CTRL_MDO_CTRL_MDO_CTRL_AURORATX_SRC_SELECT_MASK                (0x00000001U)
#define CSL_TOP_CTRL_MDO_CTRL_MDO_CTRL_AURORATX_SRC_SELECT_SHIFT               (0x00000000U)
#define CSL_TOP_CTRL_MDO_CTRL_MDO_CTRL_AURORATX_SRC_SELECT_RESETVAL            (0x00000000U)
#define CSL_TOP_CTRL_MDO_CTRL_MDO_CTRL_AURORATX_SRC_SELECT_MAX                 (0x00000001U)

#define CSL_TOP_CTRL_MDO_CTRL_MDO_CTRL_SRC_SELECT_MASK                         (0x00000010U)
#define CSL_TOP_CTRL_MDO_CTRL_MDO_CTRL_SRC_SELECT_SHIFT                        (0x00000004U)
#define CSL_TOP_CTRL_MDO_CTRL_MDO_CTRL_SRC_SELECT_RESETVAL                     (0x00000000U)
#define CSL_TOP_CTRL_MDO_CTRL_MDO_CTRL_SRC_SELECT_MAX                          (0x00000001U)

#define CSL_TOP_CTRL_MDO_CTRL_RESETVAL                                         (0x00000000U)

/* PROBE_BUS_SEL0 */

#define CSL_TOP_CTRL_PROBE_BUS_SEL0_PROBE_BUS_SEL0_SEL_MASK                    (0xFFFFFFFFU)
#define CSL_TOP_CTRL_PROBE_BUS_SEL0_PROBE_BUS_SEL0_SEL_SHIFT                   (0x00000000U)
#define CSL_TOP_CTRL_PROBE_BUS_SEL0_PROBE_BUS_SEL0_SEL_RESETVAL                (0x00000000U)
#define CSL_TOP_CTRL_PROBE_BUS_SEL0_PROBE_BUS_SEL0_SEL_MAX                     (0xFFFFFFFFU)

#define CSL_TOP_CTRL_PROBE_BUS_SEL0_RESETVAL                                   (0x00000000U)

/* PROBE_BUS_SEL1 */

#define CSL_TOP_CTRL_PROBE_BUS_SEL1_PROBE_BUS_SEL1_SEL_MASK                    (0xFFFFFFFFU)
#define CSL_TOP_CTRL_PROBE_BUS_SEL1_PROBE_BUS_SEL1_SEL_SHIFT                   (0x00000000U)
#define CSL_TOP_CTRL_PROBE_BUS_SEL1_PROBE_BUS_SEL1_SEL_RESETVAL                (0x00000000U)
#define CSL_TOP_CTRL_PROBE_BUS_SEL1_PROBE_BUS_SEL1_SEL_MAX                     (0xFFFFFFFFU)

#define CSL_TOP_CTRL_PROBE_BUS_SEL1_RESETVAL                                   (0x00000000U)

/* EFUSE_DIEID0 */

#define CSL_TOP_CTRL_EFUSE_DIEID0_EFUSE_DIEID0_VAL_MASK                        (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_DIEID0_EFUSE_DIEID0_VAL_SHIFT                       (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_DIEID0_EFUSE_DIEID0_VAL_RESETVAL                    (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_DIEID0_EFUSE_DIEID0_VAL_MAX                         (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_DIEID0_RESETVAL                                     (0x00000000U)

/* EFUSE_DIEID1 */

#define CSL_TOP_CTRL_EFUSE_DIEID1_EFUSE_DIEID1_VAL_MASK                        (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_DIEID1_EFUSE_DIEID1_VAL_SHIFT                       (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_DIEID1_EFUSE_DIEID1_VAL_RESETVAL                    (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_DIEID1_EFUSE_DIEID1_VAL_MAX                         (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_DIEID1_RESETVAL                                     (0x00000000U)

/* EFUSE_DIEID2 */

#define CSL_TOP_CTRL_EFUSE_DIEID2_EFUSE_DIEID2_VAL_MASK                        (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_DIEID2_EFUSE_DIEID2_VAL_SHIFT                       (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_DIEID2_EFUSE_DIEID2_VAL_RESETVAL                    (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_DIEID2_EFUSE_DIEID2_VAL_MAX                         (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_DIEID2_RESETVAL                                     (0x00000000U)

/* EFUSE_DIEID3 */

#define CSL_TOP_CTRL_EFUSE_DIEID3_EFUSE_DIEID3_VAL_MASK                        (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_DIEID3_EFUSE_DIEID3_VAL_SHIFT                       (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_DIEID3_EFUSE_DIEID3_VAL_RESETVAL                    (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_DIEID3_EFUSE_DIEID3_VAL_MAX                         (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_DIEID3_RESETVAL                                     (0x00000000U)

/* EFUSE_UID0 */

#define CSL_TOP_CTRL_EFUSE_UID0_EFUSE_UID0_VAL_MASK                            (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_UID0_EFUSE_UID0_VAL_SHIFT                           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_UID0_EFUSE_UID0_VAL_RESETVAL                        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_UID0_EFUSE_UID0_VAL_MAX                             (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_UID0_RESETVAL                                       (0x00000000U)

/* EFUSE_UID1 */

#define CSL_TOP_CTRL_EFUSE_UID1_EFUSE_UID1_VAL_MASK                            (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_UID1_EFUSE_UID1_VAL_SHIFT                           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_UID1_EFUSE_UID1_VAL_RESETVAL                        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_UID1_EFUSE_UID1_VAL_MAX                             (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_UID1_RESETVAL                                       (0x00000000U)

/* EFUSE_UID2 */

#define CSL_TOP_CTRL_EFUSE_UID2_EFUSE_UID2_VAL_MASK                            (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_UID2_EFUSE_UID2_VAL_SHIFT                           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_UID2_EFUSE_UID2_VAL_RESETVAL                        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_UID2_EFUSE_UID2_VAL_MAX                             (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_UID2_RESETVAL                                       (0x00000000U)

/* EFUSE_UID3 */

#define CSL_TOP_CTRL_EFUSE_UID3_EFUSE_UID3_VAL_MASK                            (0x00FFFFFFU)
#define CSL_TOP_CTRL_EFUSE_UID3_EFUSE_UID3_VAL_SHIFT                           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_UID3_EFUSE_UID3_VAL_RESETVAL                        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_UID3_EFUSE_UID3_VAL_MAX                             (0x00FFFFFFU)

#define CSL_TOP_CTRL_EFUSE_UID3_RESETVAL                                       (0x00000000U)

/* EFUSE_DEVICE_TYPE */

#define CSL_TOP_CTRL_EFUSE_DEVICE_TYPE_EFUSE_DEVICE_TYPE_VAL_MASK              (0x0000FFFFU)
#define CSL_TOP_CTRL_EFUSE_DEVICE_TYPE_EFUSE_DEVICE_TYPE_VAL_SHIFT             (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_DEVICE_TYPE_EFUSE_DEVICE_TYPE_VAL_RESETVAL          (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_DEVICE_TYPE_EFUSE_DEVICE_TYPE_VAL_MAX               (0x0000FFFFU)

#define CSL_TOP_CTRL_EFUSE_DEVICE_TYPE_RESETVAL                                (0x00000000U)

/* EFUSE_FROM0_CHECKSUM */

#define CSL_TOP_CTRL_EFUSE_FROM0_CHECKSUM_EFUSE_FROM0_CHECKSUM_VAL_MASK        (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_FROM0_CHECKSUM_EFUSE_FROM0_CHECKSUM_VAL_SHIFT       (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_FROM0_CHECKSUM_EFUSE_FROM0_CHECKSUM_VAL_RESETVAL    (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_FROM0_CHECKSUM_EFUSE_FROM0_CHECKSUM_VAL_MAX         (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_FROM0_CHECKSUM_RESETVAL                             (0x00000000U)

/* EFUSE_ROM_SEQ_UPDATE0 */

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE0_EFUSE_ROM_SEQ_UPDATE0_VAL_MASK      (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE0_EFUSE_ROM_SEQ_UPDATE0_VAL_SHIFT     (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE0_EFUSE_ROM_SEQ_UPDATE0_VAL_RESETVAL  (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE0_EFUSE_ROM_SEQ_UPDATE0_VAL_MAX       (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE0_RESETVAL                            (0x00000000U)

/* EFUSE_ROM_SEQ_UPDATE1 */

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE1_EFUSE_ROM_SEQ_UPDATE1_VAL_MASK      (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE1_EFUSE_ROM_SEQ_UPDATE1_VAL_SHIFT     (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE1_EFUSE_ROM_SEQ_UPDATE1_VAL_RESETVAL  (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE1_EFUSE_ROM_SEQ_UPDATE1_VAL_MAX       (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE1_RESETVAL                            (0x00000000U)

/* EFUSE_ROM_SEQ_UPDATE2 */

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE2_EFUSE_ROM_SEQ_UPDATE2_VAL_MASK      (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE2_EFUSE_ROM_SEQ_UPDATE2_VAL_SHIFT     (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE2_EFUSE_ROM_SEQ_UPDATE2_VAL_RESETVAL  (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE2_EFUSE_ROM_SEQ_UPDATE2_VAL_MAX       (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE2_RESETVAL                            (0x00000000U)

/* EFUSE_ROM_SEQ_UPDATE3 */

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE3_EFUSE_ROM_SEQ_UPDATE3_VAL_MASK      (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE3_EFUSE_ROM_SEQ_UPDATE3_VAL_SHIFT     (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE3_EFUSE_ROM_SEQ_UPDATE3_VAL_RESETVAL  (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE3_EFUSE_ROM_SEQ_UPDATE3_VAL_MAX       (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE3_RESETVAL                            (0x00000000U)

/* EFUSE_ROM_SEQ_UPDATE4 */

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE4_EFUSE_ROM_SEQ_UPDATE4_VAL_MASK      (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE4_EFUSE_ROM_SEQ_UPDATE4_VAL_SHIFT     (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE4_EFUSE_ROM_SEQ_UPDATE4_VAL_RESETVAL  (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE4_EFUSE_ROM_SEQ_UPDATE4_VAL_MAX       (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE4_RESETVAL                            (0x00000000U)

/* EFUSE_ROM_SEQ_UPDATE5 */

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE5_EFUSE_ROM_SEQ_UPDATE5_VAL_MASK      (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE5_EFUSE_ROM_SEQ_UPDATE5_VAL_SHIFT     (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE5_EFUSE_ROM_SEQ_UPDATE5_VAL_RESETVAL  (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE5_EFUSE_ROM_SEQ_UPDATE5_VAL_MAX       (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE5_RESETVAL                            (0x00000000U)

/* EFUSE_ROM_SEQ_UPDATE6 */

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE6_EFUSE_ROM_SEQ_UPDATE6_VAL_MASK      (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE6_EFUSE_ROM_SEQ_UPDATE6_VAL_SHIFT     (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE6_EFUSE_ROM_SEQ_UPDATE6_VAL_RESETVAL  (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE6_EFUSE_ROM_SEQ_UPDATE6_VAL_MAX       (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE6_RESETVAL                            (0x00000000U)

/* EFUSE_ROM_SEQ_UPDATE7 */

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE7_EFUSE_ROM_SEQ_UPDATE7_VAL_MASK      (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE7_EFUSE_ROM_SEQ_UPDATE7_VAL_SHIFT     (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE7_EFUSE_ROM_SEQ_UPDATE7_VAL_RESETVAL  (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE7_EFUSE_ROM_SEQ_UPDATE7_VAL_MAX       (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE7_RESETVAL                            (0x00000000U)

/* EFUSE_ROM_SEQ_UPDATE8 */

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE8_EFUSE_ROM_SEQ_UPDATE8_VAL_MASK      (0xFFFFFFFFU)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE8_EFUSE_ROM_SEQ_UPDATE8_VAL_SHIFT     (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE8_EFUSE_ROM_SEQ_UPDATE8_VAL_RESETVAL  (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE8_EFUSE_ROM_SEQ_UPDATE8_VAL_MAX       (0xFFFFFFFFU)

#define CSL_TOP_CTRL_EFUSE_ROM_SEQ_UPDATE8_RESETVAL                            (0x00000000U)

/* EFUSE0_ROW_61 */

#define CSL_TOP_CTRL_EFUSE0_ROW_61_EFUSE0_ROW_61_EFUSE0_ROW_61_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE0_ROW_61_EFUSE0_ROW_61_EFUSE0_ROW_61_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE0_ROW_61_EFUSE0_ROW_61_EFUSE0_ROW_61_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE0_ROW_61_EFUSE0_ROW_61_EFUSE0_ROW_61_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE0_ROW_61_RESETVAL                                    (0x00000000U)

/* EFUSE0_ROW_62 */

#define CSL_TOP_CTRL_EFUSE0_ROW_62_EFUSE0_ROW_62_EFUSE0_ROW_62_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE0_ROW_62_EFUSE0_ROW_62_EFUSE0_ROW_62_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE0_ROW_62_EFUSE0_ROW_62_EFUSE0_ROW_62_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE0_ROW_62_EFUSE0_ROW_62_EFUSE0_ROW_62_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE0_ROW_62_RESETVAL                                    (0x00000000U)

/* EFUSE0_ROW_63 */

#define CSL_TOP_CTRL_EFUSE0_ROW_63_EFUSE0_ROW_63_EFUSE0_ROW_63_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE0_ROW_63_EFUSE0_ROW_63_EFUSE0_ROW_63_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE0_ROW_63_EFUSE0_ROW_63_EFUSE0_ROW_63_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE0_ROW_63_EFUSE0_ROW_63_EFUSE0_ROW_63_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE0_ROW_63_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_5 */

#define CSL_TOP_CTRL_EFUSE1_ROW_5_EFUSE1_ROW_5_EFUSE1_ROW_5_MASK               (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_5_EFUSE1_ROW_5_EFUSE1_ROW_5_SHIFT              (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_5_EFUSE1_ROW_5_EFUSE1_ROW_5_RESETVAL           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_5_EFUSE1_ROW_5_EFUSE1_ROW_5_MAX                (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_5_RESETVAL                                     (0x00000000U)

/* EFUSE1_ROW_6 */

#define CSL_TOP_CTRL_EFUSE1_ROW_6_EFUSE1_ROW_6_EFUSE1_ROW_6_MASK               (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_6_EFUSE1_ROW_6_EFUSE1_ROW_6_SHIFT              (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_6_EFUSE1_ROW_6_EFUSE1_ROW_6_RESETVAL           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_6_EFUSE1_ROW_6_EFUSE1_ROW_6_MAX                (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_6_RESETVAL                                     (0x00000000U)

/* EFUSE1_ROW_7 */

#define CSL_TOP_CTRL_EFUSE1_ROW_7_EFUSE1_ROW_7_EFUSE1_ROW_7_MASK               (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_7_EFUSE1_ROW_7_EFUSE1_ROW_7_SHIFT              (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_7_EFUSE1_ROW_7_EFUSE1_ROW_7_RESETVAL           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_7_EFUSE1_ROW_7_EFUSE1_ROW_7_MAX                (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_7_RESETVAL                                     (0x00000000U)

/* EFUSE1_ROW_8 */

#define CSL_TOP_CTRL_EFUSE1_ROW_8_EFUSE1_ROW_8_EFUSE1_ROW_8_MASK               (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_8_EFUSE1_ROW_8_EFUSE1_ROW_8_SHIFT              (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_8_EFUSE1_ROW_8_EFUSE1_ROW_8_RESETVAL           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_8_EFUSE1_ROW_8_EFUSE1_ROW_8_MAX                (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_8_RESETVAL                                     (0x00000000U)

/* EFUSE1_ROW_9 */

#define CSL_TOP_CTRL_EFUSE1_ROW_9_EFUSE1_ROW_9_EFUSE1_ROW_9_MASK               (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_9_EFUSE1_ROW_9_EFUSE1_ROW_9_SHIFT              (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_9_EFUSE1_ROW_9_EFUSE1_ROW_9_RESETVAL           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_9_EFUSE1_ROW_9_EFUSE1_ROW_9_MAX                (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_9_RESETVAL                                     (0x00000000U)

/* EFUSE1_ROW_10 */

#define CSL_TOP_CTRL_EFUSE1_ROW_10_EFUSE1_ROW_10_EFUSE1_ROW_10_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_10_EFUSE1_ROW_10_EFUSE1_ROW_10_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_10_EFUSE1_ROW_10_EFUSE1_ROW_10_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_10_EFUSE1_ROW_10_EFUSE1_ROW_10_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_10_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_11 */

#define CSL_TOP_CTRL_EFUSE1_ROW_11_EFUSE1_ROW_11_EFUSE1_ROW_11_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_11_EFUSE1_ROW_11_EFUSE1_ROW_11_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_11_EFUSE1_ROW_11_EFUSE1_ROW_11_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_11_EFUSE1_ROW_11_EFUSE1_ROW_11_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_11_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_12 */

#define CSL_TOP_CTRL_EFUSE1_ROW_12_EFUSE1_ROW_12_EFUSE1_ROW_12_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_12_EFUSE1_ROW_12_EFUSE1_ROW_12_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_12_EFUSE1_ROW_12_EFUSE1_ROW_12_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_12_EFUSE1_ROW_12_EFUSE1_ROW_12_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_12_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_13 */

#define CSL_TOP_CTRL_EFUSE1_ROW_13_EFUSE1_ROW_13_EFUSE1_ROW_13_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_13_EFUSE1_ROW_13_EFUSE1_ROW_13_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_13_EFUSE1_ROW_13_EFUSE1_ROW_13_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_13_EFUSE1_ROW_13_EFUSE1_ROW_13_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_13_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_14 */

#define CSL_TOP_CTRL_EFUSE1_ROW_14_EFUSE1_ROW_14_EFUSE1_ROW_14_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_14_EFUSE1_ROW_14_EFUSE1_ROW_14_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_14_EFUSE1_ROW_14_EFUSE1_ROW_14_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_14_EFUSE1_ROW_14_EFUSE1_ROW_14_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_14_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_15 */

#define CSL_TOP_CTRL_EFUSE1_ROW_15_EFUSE1_ROW_15_EFUSE1_ROW_15_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_15_EFUSE1_ROW_15_EFUSE1_ROW_15_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_15_EFUSE1_ROW_15_EFUSE1_ROW_15_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_15_EFUSE1_ROW_15_EFUSE1_ROW_15_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_15_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_16 */

#define CSL_TOP_CTRL_EFUSE1_ROW_16_EFUSE1_ROW_16_EFUSE1_ROW_16_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_16_EFUSE1_ROW_16_EFUSE1_ROW_16_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_16_EFUSE1_ROW_16_EFUSE1_ROW_16_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_16_EFUSE1_ROW_16_EFUSE1_ROW_16_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_16_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_17 */

#define CSL_TOP_CTRL_EFUSE1_ROW_17_EFUSE1_ROW_17_EFUSE1_ROW_17_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_17_EFUSE1_ROW_17_EFUSE1_ROW_17_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_17_EFUSE1_ROW_17_EFUSE1_ROW_17_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_17_EFUSE1_ROW_17_EFUSE1_ROW_17_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_17_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_18 */

#define CSL_TOP_CTRL_EFUSE1_ROW_18_EFUSE1_ROW_18_EFUSE1_ROW_18_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_18_EFUSE1_ROW_18_EFUSE1_ROW_18_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_18_EFUSE1_ROW_18_EFUSE1_ROW_18_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_18_EFUSE1_ROW_18_EFUSE1_ROW_18_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_18_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_19 */

#define CSL_TOP_CTRL_EFUSE1_ROW_19_EFUSE1_ROW_19_EFUSE1_ROW_19_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_19_EFUSE1_ROW_19_EFUSE1_ROW_19_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_19_EFUSE1_ROW_19_EFUSE1_ROW_19_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_19_EFUSE1_ROW_19_EFUSE1_ROW_19_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_19_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_20 */

#define CSL_TOP_CTRL_EFUSE1_ROW_20_EFUSE1_ROW_20_EFUSE1_ROW_20_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_20_EFUSE1_ROW_20_EFUSE1_ROW_20_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_20_EFUSE1_ROW_20_EFUSE1_ROW_20_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_20_EFUSE1_ROW_20_EFUSE1_ROW_20_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_20_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_21 */

#define CSL_TOP_CTRL_EFUSE1_ROW_21_EFUSE1_ROW_21_EFUSE1_ROW_21_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_21_EFUSE1_ROW_21_EFUSE1_ROW_21_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_21_EFUSE1_ROW_21_EFUSE1_ROW_21_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_21_EFUSE1_ROW_21_EFUSE1_ROW_21_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_21_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_22 */

#define CSL_TOP_CTRL_EFUSE1_ROW_22_EFUSE1_ROW_22_EFUSE1_ROW_22_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_22_EFUSE1_ROW_22_EFUSE1_ROW_22_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_22_EFUSE1_ROW_22_EFUSE1_ROW_22_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_22_EFUSE1_ROW_22_EFUSE1_ROW_22_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_22_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_23 */

#define CSL_TOP_CTRL_EFUSE1_ROW_23_EFUSE1_ROW_23_EFUSE1_ROW_23_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_23_EFUSE1_ROW_23_EFUSE1_ROW_23_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_23_EFUSE1_ROW_23_EFUSE1_ROW_23_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_23_EFUSE1_ROW_23_EFUSE1_ROW_23_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_23_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_24 */

#define CSL_TOP_CTRL_EFUSE1_ROW_24_EFUSE1_ROW_24_EFUSE1_ROW_24_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_24_EFUSE1_ROW_24_EFUSE1_ROW_24_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_24_EFUSE1_ROW_24_EFUSE1_ROW_24_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_24_EFUSE1_ROW_24_EFUSE1_ROW_24_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_24_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_25 */

#define CSL_TOP_CTRL_EFUSE1_ROW_25_EFUSE1_ROW_25_EFUSE1_ROW_25_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_25_EFUSE1_ROW_25_EFUSE1_ROW_25_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_25_EFUSE1_ROW_25_EFUSE1_ROW_25_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_25_EFUSE1_ROW_25_EFUSE1_ROW_25_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_25_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_26 */

#define CSL_TOP_CTRL_EFUSE1_ROW_26_EFUSE1_ROW_26_EFUSE1_ROW_26_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_26_EFUSE1_ROW_26_EFUSE1_ROW_26_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_26_EFUSE1_ROW_26_EFUSE1_ROW_26_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_26_EFUSE1_ROW_26_EFUSE1_ROW_26_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_26_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_27 */

#define CSL_TOP_CTRL_EFUSE1_ROW_27_EFUSE1_ROW_27_EFUSE1_ROW_27_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_27_EFUSE1_ROW_27_EFUSE1_ROW_27_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_27_EFUSE1_ROW_27_EFUSE1_ROW_27_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_27_EFUSE1_ROW_27_EFUSE1_ROW_27_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_27_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_28 */

#define CSL_TOP_CTRL_EFUSE1_ROW_28_EFUSE1_ROW_28_EFUSE1_ROW_28_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_28_EFUSE1_ROW_28_EFUSE1_ROW_28_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_28_EFUSE1_ROW_28_EFUSE1_ROW_28_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_28_EFUSE1_ROW_28_EFUSE1_ROW_28_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_28_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_29 */

#define CSL_TOP_CTRL_EFUSE1_ROW_29_EFUSE1_ROW_29_EFUSE1_ROW_29_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_29_EFUSE1_ROW_29_EFUSE1_ROW_29_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_29_EFUSE1_ROW_29_EFUSE1_ROW_29_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_29_EFUSE1_ROW_29_EFUSE1_ROW_29_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_29_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_30 */

#define CSL_TOP_CTRL_EFUSE1_ROW_30_EFUSE1_ROW_30_EFUSE1_ROW_30_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_30_EFUSE1_ROW_30_EFUSE1_ROW_30_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_30_EFUSE1_ROW_30_EFUSE1_ROW_30_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_30_EFUSE1_ROW_30_EFUSE1_ROW_30_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_30_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_31 */

#define CSL_TOP_CTRL_EFUSE1_ROW_31_EFUSE1_ROW_31_EFUSE1_ROW_31_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_31_EFUSE1_ROW_31_EFUSE1_ROW_31_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_31_EFUSE1_ROW_31_EFUSE1_ROW_31_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_31_EFUSE1_ROW_31_EFUSE1_ROW_31_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_31_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_32 */

#define CSL_TOP_CTRL_EFUSE1_ROW_32_EFUSE1_ROW_32_EFUSE1_ROW_32_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_32_EFUSE1_ROW_32_EFUSE1_ROW_32_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_32_EFUSE1_ROW_32_EFUSE1_ROW_32_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_32_EFUSE1_ROW_32_EFUSE1_ROW_32_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_32_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_33 */

#define CSL_TOP_CTRL_EFUSE1_ROW_33_EFUSE1_ROW_33_EFUSE1_ROW_33_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_33_EFUSE1_ROW_33_EFUSE1_ROW_33_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_33_EFUSE1_ROW_33_EFUSE1_ROW_33_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_33_EFUSE1_ROW_33_EFUSE1_ROW_33_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_33_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_34 */

#define CSL_TOP_CTRL_EFUSE1_ROW_34_EFUSE1_ROW_34_EFUSE1_ROW_34_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_34_EFUSE1_ROW_34_EFUSE1_ROW_34_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_34_EFUSE1_ROW_34_EFUSE1_ROW_34_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_34_EFUSE1_ROW_34_EFUSE1_ROW_34_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_34_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_35 */

#define CSL_TOP_CTRL_EFUSE1_ROW_35_EFUSE1_ROW_35_EFUSE1_ROW_35_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_35_EFUSE1_ROW_35_EFUSE1_ROW_35_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_35_EFUSE1_ROW_35_EFUSE1_ROW_35_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_35_EFUSE1_ROW_35_EFUSE1_ROW_35_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_35_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_36 */

#define CSL_TOP_CTRL_EFUSE1_ROW_36_EFUSE1_ROW_36_EFUSE1_ROW_36_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_36_EFUSE1_ROW_36_EFUSE1_ROW_36_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_36_EFUSE1_ROW_36_EFUSE1_ROW_36_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_36_EFUSE1_ROW_36_EFUSE1_ROW_36_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_36_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_37 */

#define CSL_TOP_CTRL_EFUSE1_ROW_37_EFUSE1_ROW_37_EFUSE1_ROW_37_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_37_EFUSE1_ROW_37_EFUSE1_ROW_37_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_37_EFUSE1_ROW_37_EFUSE1_ROW_37_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_37_EFUSE1_ROW_37_EFUSE1_ROW_37_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_37_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_38 */

#define CSL_TOP_CTRL_EFUSE1_ROW_38_EFUSE1_ROW_38_EFUSE1_ROW_38_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_38_EFUSE1_ROW_38_EFUSE1_ROW_38_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_38_EFUSE1_ROW_38_EFUSE1_ROW_38_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_38_EFUSE1_ROW_38_EFUSE1_ROW_38_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_38_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_39 */

#define CSL_TOP_CTRL_EFUSE1_ROW_39_EFUSE1_ROW_39_EFUSE1_ROW_39_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_39_EFUSE1_ROW_39_EFUSE1_ROW_39_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_39_EFUSE1_ROW_39_EFUSE1_ROW_39_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_39_EFUSE1_ROW_39_EFUSE1_ROW_39_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_39_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_40 */

#define CSL_TOP_CTRL_EFUSE1_ROW_40_EFUSE1_ROW_40_EFUSE1_ROW_40_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_40_EFUSE1_ROW_40_EFUSE1_ROW_40_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_40_EFUSE1_ROW_40_EFUSE1_ROW_40_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_40_EFUSE1_ROW_40_EFUSE1_ROW_40_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_40_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_41 */

#define CSL_TOP_CTRL_EFUSE1_ROW_41_EFUSE1_ROW_41_EFUSE1_ROW_41_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_41_EFUSE1_ROW_41_EFUSE1_ROW_41_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_41_EFUSE1_ROW_41_EFUSE1_ROW_41_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_41_EFUSE1_ROW_41_EFUSE1_ROW_41_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_41_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_42 */

#define CSL_TOP_CTRL_EFUSE1_ROW_42_EFUSE1_ROW_42_EFUSE1_ROW_42_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_42_EFUSE1_ROW_42_EFUSE1_ROW_42_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_42_EFUSE1_ROW_42_EFUSE1_ROW_42_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_42_EFUSE1_ROW_42_EFUSE1_ROW_42_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_42_RESETVAL                                    (0x00000000U)

/* EFUSE1_ROW_43 */

#define CSL_TOP_CTRL_EFUSE1_ROW_43_EFUSE1_ROW_43_EFUSE1_ROW_43_MASK            (0x03FFFFFFU)
#define CSL_TOP_CTRL_EFUSE1_ROW_43_EFUSE1_ROW_43_EFUSE1_ROW_43_SHIFT           (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_43_EFUSE1_ROW_43_EFUSE1_ROW_43_RESETVAL        (0x00000000U)
#define CSL_TOP_CTRL_EFUSE1_ROW_43_EFUSE1_ROW_43_EFUSE1_ROW_43_MAX             (0x03FFFFFFU)

#define CSL_TOP_CTRL_EFUSE1_ROW_43_RESETVAL                                    (0x00000000U)

/* EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_OVERRIDE_VAL_MASK (0x00000010U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_OVERRIDE_VAL_SHIFT (0x00000004U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_OVERRIDE_VAL_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_OVERRIDE_VAL_MAX (0x00000001U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_HSM_HALT_ON_ROM_ECC_ERR_EN_RESETVAL        (0x00000000U)

/* EFUSE_OVERRIDE_MEM_MARGINCTRL */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GLG_MARGIN_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GLG_MARGIN_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GLG_MARGIN_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GLG_MARGIN_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GLG_MARGIN_MASK (0x00000030U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GLG_MARGIN_SHIFT (0x00000004U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GLG_MARGIN_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GLG_MARGIN_MAX (0x00000003U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GWG_MARGIN_OVERRIDE_MASK (0x00000700U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GWG_MARGIN_OVERRIDE_SHIFT (0x00000008U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GWG_MARGIN_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GWG_MARGIN_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GWG_MARGIN_MASK (0x0000F000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GWG_MARGIN_SHIFT (0x0000000CU)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GWG_MARGIN_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_GWG_MARGIN_MAX (0x0000000FU)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BYG_MARGIN_OVERRIDE_MASK (0x00070000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BYG_MARGIN_OVERRIDE_SHIFT (0x00000010U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BYG_MARGIN_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BYG_MARGIN_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BYG_MARGIN_MASK (0x00300000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BYG_MARGIN_SHIFT (0x00000014U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BYG_MARGIN_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BYG_MARGIN_MAX (0x00000003U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BRG_MARGIN_OVERRIDE_MASK (0x07000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BRG_MARGIN_OVERRIDE_SHIFT (0x00000018U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BRG_MARGIN_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BRG_MARGIN_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BRG_MARGIN_MASK (0x30000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BRG_MARGIN_SHIFT (0x0000001CU)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BRG_MARGIN_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_BRG_MARGIN_MAX (0x00000003U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MEM_MARGINCTRL_RESETVAL                    (0x00000000U)

/* EFUSE_OVERRIDE_LVDS_BGAP_TRIM */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_OVERRIDE_VAL_MASK (0x000003F0U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_OVERRIDE_VAL_SHIFT (0x00000004U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_OVERRIDE_VAL_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_OVERRIDE_VAL_MAX (0x0000003FU)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_LVDS_BGAP_TRIM_RESETVAL                    (0x00000000U)

/* EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT_EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT_EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT_EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT_EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XTAL_STABLIZATION_WAIT_RESETVAL            (0x00000000U)

/* EFUSE_OVERRIDE_SLICER_BIAS_RTRIM */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_SLICER_BIAS_RTRIM_EFUSE_OVERRIDE_SLICER_BIAS_RTRIM_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_SLICER_BIAS_RTRIM_EFUSE_OVERRIDE_SLICER_BIAS_RTRIM_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_SLICER_BIAS_RTRIM_EFUSE_OVERRIDE_SLICER_BIAS_RTRIM_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_SLICER_BIAS_RTRIM_EFUSE_OVERRIDE_SLICER_BIAS_RTRIM_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_SLICER_BIAS_RTRIM_RESETVAL                 (0x00000000U)

/* EFUSE_OVERRIDE_XO_OUTPUT_DRIVE */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XO_OUTPUT_DRIVE_EFUSE_OVERRIDE_XO_OUTPUT_DRIVE_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XO_OUTPUT_DRIVE_EFUSE_OVERRIDE_XO_OUTPUT_DRIVE_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XO_OUTPUT_DRIVE_EFUSE_OVERRIDE_XO_OUTPUT_DRIVE_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XO_OUTPUT_DRIVE_EFUSE_OVERRIDE_XO_OUTPUT_DRIVE_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_XO_OUTPUT_DRIVE_RESETVAL                   (0x00000000U)

/* EFUSE_OVERRIDE_RCOSC_TRIM_CODE */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RCOSC_TRIM_CODE_EFUSE_OVERRIDE_RCOSC_TRIM_CODE_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RCOSC_TRIM_CODE_EFUSE_OVERRIDE_RCOSC_TRIM_CODE_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RCOSC_TRIM_CODE_EFUSE_OVERRIDE_RCOSC_TRIM_CODE_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RCOSC_TRIM_CODE_EFUSE_OVERRIDE_RCOSC_TRIM_CODE_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RCOSC_TRIM_CODE_RESETVAL                   (0x00000000U)

/* EFUSE_OVERRIDE_IP1_BG1_RTRIM */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_RTRIM_EFUSE_OVERRIDE_IP1_BG1_RTRIM_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_RTRIM_EFUSE_OVERRIDE_IP1_BG1_RTRIM_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_RTRIM_EFUSE_OVERRIDE_IP1_BG1_RTRIM_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_RTRIM_EFUSE_OVERRIDE_IP1_BG1_RTRIM_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_RTRIM_RESETVAL                     (0x00000000U)

/* EFUSE_OVERRIDE_IP1_BG1_SLOPE */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_SLOPE_EFUSE_OVERRIDE_IP1_BG1_SLOPE_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_SLOPE_EFUSE_OVERRIDE_IP1_BG1_SLOPE_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_SLOPE_EFUSE_OVERRIDE_IP1_BG1_SLOPE_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_SLOPE_EFUSE_OVERRIDE_IP1_BG1_SLOPE_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_SLOPE_RESETVAL                     (0x00000000U)

/* EFUSE_OVERRIDE_IP1_BG1_MAG */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_MAG_EFUSE_OVERRIDE_IP1_BG1_MAG_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_MAG_EFUSE_OVERRIDE_IP1_BG1_MAG_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_MAG_EFUSE_OVERRIDE_IP1_BG1_MAG_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_MAG_EFUSE_OVERRIDE_IP1_BG1_MAG_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_IP1_BG1_MAG_RESETVAL                       (0x00000000U)

/* EFUSE_OVERRIDE_RS232_CLKMODE */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RS232_CLKMODE_EFUSE_OVERRIDE_RS232_CLKMODE_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RS232_CLKMODE_EFUSE_OVERRIDE_RS232_CLKMODE_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RS232_CLKMODE_EFUSE_OVERRIDE_RS232_CLKMODE_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RS232_CLKMODE_EFUSE_OVERRIDE_RS232_CLKMODE_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RS232_CLKMODE_EFUSE_OVERRIDE_RS232_CLKMODE_OVERRIDE_VAL_MASK (0x00000010U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RS232_CLKMODE_EFUSE_OVERRIDE_RS232_CLKMODE_OVERRIDE_VAL_SHIFT (0x00000004U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RS232_CLKMODE_EFUSE_OVERRIDE_RS232_CLKMODE_OVERRIDE_VAL_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RS232_CLKMODE_EFUSE_OVERRIDE_RS232_CLKMODE_OVERRIDE_VAL_MAX (0x00000001U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_RS232_CLKMODE_RESETVAL                     (0x00000000U)

/* EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM_EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM_EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM_EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM_EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDD_OV_UV_TRIM_RESETVAL               (0x00000000U)

/* EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM_EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM_EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM_EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM_EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDS_3P3_UV_TRIM_RESETVAL             (0x00000000U)

/* EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM_EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM_EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM_EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM_EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VMON_VDDA_OSC_TRIM_RESETVAL                (0x00000000U)

/* EFUSE_OVERRIDE_VDD_VT_DET */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VDD_VT_DET_EFUSE_OVERRIDE_VDD_VT_DET_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VDD_VT_DET_EFUSE_OVERRIDE_VDD_VT_DET_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VDD_VT_DET_EFUSE_OVERRIDE_VDD_VT_DET_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VDD_VT_DET_EFUSE_OVERRIDE_VDD_VT_DET_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_VDD_VT_DET_RESETVAL                        (0x00000000U)

/* EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_VAL_RESETVAL    (0x00000000U)

/* EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_MASK_CPU_CLK_OUT_CTRL_LOWV_SEL_RESETVAL    (0x00000000U)

/* EFUSE_OVERRIDE_EN_VOL_MON_FUNC */

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_EN_VOL_MON_FUNC_EFUSE_OVERRIDE_EN_VOL_MON_FUNC_OVERRIDE_MASK (0x00000007U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_EN_VOL_MON_FUNC_EFUSE_OVERRIDE_EN_VOL_MON_FUNC_OVERRIDE_SHIFT (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_EN_VOL_MON_FUNC_EFUSE_OVERRIDE_EN_VOL_MON_FUNC_OVERRIDE_RESETVAL (0x00000000U)
#define CSL_TOP_CTRL_EFUSE_OVERRIDE_EN_VOL_MON_FUNC_EFUSE_OVERRIDE_EN_VOL_MON_FUNC_OVERRIDE_MAX (0x00000007U)

#define CSL_TOP_CTRL_EFUSE_OVERRIDE_EN_VOL_MON_FUNC_RESETVAL                   (0x00000000U)

/* LOCK0_KICK0 */

#define CSL_TOP_CTRL_LOCK0_KICK0_LOCK0_KICK0_MASK                              (0xFFFFFFFFU)
#define CSL_TOP_CTRL_LOCK0_KICK0_LOCK0_KICK0_SHIFT                             (0x00000000U)
#define CSL_TOP_CTRL_LOCK0_KICK0_LOCK0_KICK0_RESETVAL                          (0x00000000U)
#define CSL_TOP_CTRL_LOCK0_KICK0_LOCK0_KICK0_MAX                               (0xFFFFFFFFU)

#define CSL_TOP_CTRL_LOCK0_KICK0_RESETVAL                                      (0x00000000U)

/* LOCK0_KICK1 */

#define CSL_TOP_CTRL_LOCK0_KICK1_LOCK0_KICK1_MASK                              (0xFFFFFFFFU)
#define CSL_TOP_CTRL_LOCK0_KICK1_LOCK0_KICK1_SHIFT                             (0x00000000U)
#define CSL_TOP_CTRL_LOCK0_KICK1_LOCK0_KICK1_RESETVAL                          (0x00000000U)
#define CSL_TOP_CTRL_LOCK0_KICK1_LOCK0_KICK1_MAX                               (0xFFFFFFFFU)

#define CSL_TOP_CTRL_LOCK0_KICK1_RESETVAL                                      (0x00000000U)

/* INTR_RAW_STATUS */

#define CSL_TOP_CTRL_INTR_RAW_STATUS_PROT_ERR_MASK                             (0x00000001U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_PROT_ERR_SHIFT                            (0x00000000U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_PROT_ERR_RESETVAL                         (0x00000000U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_PROT_ERR_MAX                              (0x00000001U)

#define CSL_TOP_CTRL_INTR_RAW_STATUS_ADDR_ERR_MASK                             (0x00000002U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_ADDR_ERR_SHIFT                            (0x00000001U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_ADDR_ERR_RESETVAL                         (0x00000000U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_ADDR_ERR_MAX                              (0x00000001U)

#define CSL_TOP_CTRL_INTR_RAW_STATUS_KICK_ERR_MASK                             (0x00000004U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_KICK_ERR_SHIFT                            (0x00000002U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_KICK_ERR_RESETVAL                         (0x00000000U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_KICK_ERR_MAX                              (0x00000001U)

#define CSL_TOP_CTRL_INTR_RAW_STATUS_PROXY_ERR_MASK                            (0x00000008U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_PROXY_ERR_SHIFT                           (0x00000003U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_PROXY_ERR_RESETVAL                        (0x00000000U)
#define CSL_TOP_CTRL_INTR_RAW_STATUS_PROXY_ERR_MAX                             (0x00000001U)

#define CSL_TOP_CTRL_INTR_RAW_STATUS_RESETVAL                                  (0x00000000U)

/* INTR_ENABLED_STATUS_CLEAR */

#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROT_ERR_MASK           (0x00000001U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROT_ERR_SHIFT          (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROT_ERR_RESETVAL       (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROT_ERR_MAX            (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_ADDR_ERR_MASK           (0x00000002U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_ADDR_ERR_SHIFT          (0x00000001U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_ADDR_ERR_RESETVAL       (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_ADDR_ERR_MAX            (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_KICK_ERR_MASK           (0x00000004U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_KICK_ERR_SHIFT          (0x00000002U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_KICK_ERR_RESETVAL       (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_KICK_ERR_MAX            (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROXY_ERR_MASK          (0x00000008U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROXY_ERR_SHIFT         (0x00000003U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROXY_ERR_RESETVAL      (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_ENABLED_PROXY_ERR_MAX           (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLED_STATUS_CLEAR_RESETVAL                        (0x00000000U)

/* INTR_ENABLE */

#define CSL_TOP_CTRL_INTR_ENABLE_PROT_ERR_EN_MASK                              (0x00000001U)
#define CSL_TOP_CTRL_INTR_ENABLE_PROT_ERR_EN_SHIFT                             (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLE_PROT_ERR_EN_RESETVAL                          (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLE_PROT_ERR_EN_MAX                               (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLE_ADDR_ERR_EN_MASK                              (0x00000002U)
#define CSL_TOP_CTRL_INTR_ENABLE_ADDR_ERR_EN_SHIFT                             (0x00000001U)
#define CSL_TOP_CTRL_INTR_ENABLE_ADDR_ERR_EN_RESETVAL                          (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLE_ADDR_ERR_EN_MAX                               (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLE_KICK_ERR_EN_MASK                              (0x00000004U)
#define CSL_TOP_CTRL_INTR_ENABLE_KICK_ERR_EN_SHIFT                             (0x00000002U)
#define CSL_TOP_CTRL_INTR_ENABLE_KICK_ERR_EN_RESETVAL                          (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLE_KICK_ERR_EN_MAX                               (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLE_PROXY_ERR_EN_MASK                             (0x00000008U)
#define CSL_TOP_CTRL_INTR_ENABLE_PROXY_ERR_EN_SHIFT                            (0x00000003U)
#define CSL_TOP_CTRL_INTR_ENABLE_PROXY_ERR_EN_RESETVAL                         (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLE_PROXY_ERR_EN_MAX                              (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLE_RESETVAL                                      (0x00000000U)

/* INTR_ENABLE_CLEAR */

#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_PROT_ERR_EN_CLR_MASK                    (0x00000001U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_PROT_ERR_EN_CLR_SHIFT                   (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_PROT_ERR_EN_CLR_RESETVAL                (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_PROT_ERR_EN_CLR_MAX                     (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_ADDR_ERR_EN_CLR_MASK                    (0x00000002U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_ADDR_ERR_EN_CLR_SHIFT                   (0x00000001U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_ADDR_ERR_EN_CLR_RESETVAL                (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_ADDR_ERR_EN_CLR_MAX                     (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_KICK_ERR_EN_CLR_MASK                    (0x00000004U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_KICK_ERR_EN_CLR_SHIFT                   (0x00000002U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_KICK_ERR_EN_CLR_RESETVAL                (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_KICK_ERR_EN_CLR_MAX                     (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_PROXY_ERR_EN_CLR_MASK                   (0x00000008U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_PROXY_ERR_EN_CLR_SHIFT                  (0x00000003U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_PROXY_ERR_EN_CLR_RESETVAL               (0x00000000U)
#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_PROXY_ERR_EN_CLR_MAX                    (0x00000001U)

#define CSL_TOP_CTRL_INTR_ENABLE_CLEAR_RESETVAL                                (0x00000000U)

/* EOI */

#define CSL_TOP_CTRL_EOI_EOI_VECTOR_MASK                                       (0x000000FFU)
#define CSL_TOP_CTRL_EOI_EOI_VECTOR_SHIFT                                      (0x00000000U)
#define CSL_TOP_CTRL_EOI_EOI_VECTOR_RESETVAL                                   (0x00000000U)
#define CSL_TOP_CTRL_EOI_EOI_VECTOR_MAX                                        (0x000000FFU)

#define CSL_TOP_CTRL_EOI_RESETVAL                                              (0x00000000U)

/* FAULT_ADDRESS */

#define CSL_TOP_CTRL_FAULT_ADDRESS_FAULT_ADDR_MASK                             (0xFFFFFFFFU)
#define CSL_TOP_CTRL_FAULT_ADDRESS_FAULT_ADDR_SHIFT                            (0x00000000U)
#define CSL_TOP_CTRL_FAULT_ADDRESS_FAULT_ADDR_RESETVAL                         (0x00000000U)
#define CSL_TOP_CTRL_FAULT_ADDRESS_FAULT_ADDR_MAX                              (0xFFFFFFFFU)

#define CSL_TOP_CTRL_FAULT_ADDRESS_RESETVAL                                    (0x00000000U)

/* FAULT_TYPE_STATUS */

#define CSL_TOP_CTRL_FAULT_TYPE_STATUS_FAULT_TYPE_MASK                         (0x0000003FU)
#define CSL_TOP_CTRL_FAULT_TYPE_STATUS_FAULT_TYPE_SHIFT                        (0x00000000U)
#define CSL_TOP_CTRL_FAULT_TYPE_STATUS_FAULT_TYPE_RESETVAL                     (0x00000000U)
#define CSL_TOP_CTRL_FAULT_TYPE_STATUS_FAULT_TYPE_MAX                          (0x0000003FU)

#define CSL_TOP_CTRL_FAULT_TYPE_STATUS_FAULT_NS_MASK                           (0x00000040U)
#define CSL_TOP_CTRL_FAULT_TYPE_STATUS_FAULT_NS_SHIFT                          (0x00000006U)
#define CSL_TOP_CTRL_FAULT_TYPE_STATUS_FAULT_NS_RESETVAL                       (0x00000000U)
#define CSL_TOP_CTRL_FAULT_TYPE_STATUS_FAULT_NS_MAX                            (0x00000001U)

#define CSL_TOP_CTRL_FAULT_TYPE_STATUS_RESETVAL                                (0x00000000U)

/* FAULT_ATTR_STATUS */

#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_PRIVID_MASK                       (0x000000FFU)
#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_PRIVID_SHIFT                      (0x00000000U)
#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_PRIVID_RESETVAL                   (0x00000000U)
#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_PRIVID_MAX                        (0x000000FFU)

#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_ROUTEID_MASK                      (0x000FFF00U)
#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_ROUTEID_SHIFT                     (0x00000008U)
#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_ROUTEID_RESETVAL                  (0x00000000U)
#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_ROUTEID_MAX                       (0x00000FFFU)

#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_XID_MASK                          (0xFFF00000U)
#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_XID_SHIFT                         (0x00000014U)
#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_XID_RESETVAL                      (0x00000000U)
#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_FAULT_XID_MAX                           (0x00000FFFU)

#define CSL_TOP_CTRL_FAULT_ATTR_STATUS_RESETVAL                                (0x00000000U)

/* FAULT_CLEAR */

#define CSL_TOP_CTRL_FAULT_CLEAR_FAULT_CLR_MASK                                (0x00000001U)
#define CSL_TOP_CTRL_FAULT_CLEAR_FAULT_CLR_SHIFT                               (0x00000000U)
#define CSL_TOP_CTRL_FAULT_CLEAR_FAULT_CLR_RESETVAL                            (0x00000000U)
#define CSL_TOP_CTRL_FAULT_CLEAR_FAULT_CLR_MAX                                 (0x00000001U)

#define CSL_TOP_CTRL_FAULT_CLEAR_RESETVAL                                      (0x00000000U)

#ifdef __cplusplus
}
#endif
#endif
