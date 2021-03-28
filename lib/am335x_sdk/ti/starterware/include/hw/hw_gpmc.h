/*
* hw_gpmc.h
*
* Register-level header file for GPMC
*
* Copyright (C) 2013 - 2019 Texas Instruments Incorporated - http://www.ti.com/
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
#ifndef HW_GPMC_H_
#define HW_GPMC_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define GPMC_IRQENABLE                                          (0x1cU)
#define GPMC_ERR_TYPE                                           (0x48U)
#define GPMC_IRQSTATUS                                          (0x18U)
#define GPMC_SYSSTATUS                                          (0x14U)
#define GPMC_STATUS                                             (0x54U)
#define GPMC_REVISION                                           (0x0U)
#define GPMC_SYSCONFIG                                          (0x10U)
#define GPMC_CONFIG                                             (0x50U)
#define GPMC_ERR_ADDRESS                                        (0x44U)
#define GPMC_TIMEOUT_CONTROL                                    (0x40U)
#define GPMC_CONFIG1(m)                                         ((uint32_t)0x60U + ((m) * 0x30U))
#define GPMC_CONFIG1_NUM_ELEMS                                  (7U)
#define GPMC_CONFIG2(m)                                         ((uint32_t)0x64U + ((m) * 0x30U))
#define GPMC_CONFIG2_NUM_ELEMS                                  (7U)
#define GPMC_CONFIG3(m)                                         ((uint32_t)0x68U + ((m) * 0x30U))
#define GPMC_CONFIG3_NUM_ELEMS                                  (7U)
#define GPMC_CONFIG4(m)                                         ((uint32_t)0x6cU + ((m) * 0x30U))
#define GPMC_CONFIG4_NUM_ELEMS                                  (7U)
#define GPMC_CONFIG5(m)                                         ((uint32_t)0x70U + ((m) * 0x30U))
#define GPMC_CONFIG5_NUM_ELEMS                                  (7U)
#define GPMC_CONFIG6(m)                                         ((uint32_t)0x74U + ((m) * 0x30U))
#define GPMC_CONFIG6_NUM_ELEMS                                  (7U)
#define GPMC_CONFIG7(m)                                         ((uint32_t)0x78U + ((m) * 0x30U))
#define GPMC_CONFIG7_NUM_ELEMS                                  (7U)
#define GPMC_NAND_COMMAND(m)                                    ((uint32_t)0x7cU + ((m) * 0x30U))
#define GPMC_NAND_COMMAND_NUM_ELEMS                             (7U)
#define GPMC_NAND_ADDRESS(m)                                    ((uint32_t)0x80U + ((m) * 0x30U))
#define GPMC_NAND_ADDRESS_NUM_ELEMS                             (7U)
#define GPMC_NAND_DATA(m)                                       ((uint32_t)0x84U + ((m) * 0x30U))
#define GPMC_NAND_DATA_NUM_ELEMS                                (7U)
#define GPMC_ECC_SIZE_CONFIG                                    (0x1fcU)
#define GPMC_PREFETCH_CONFIG2                                   (0x1e4U)
#define GPMC_PREFETCH_STATUS                                    (0x1f0U)
#define GPMC_ECC_CONTROL                                        (0x1f8U)
#define GPMC_ECC_CONFIG                                         (0x1f4U)
#define GPMC_PREFETCH_CONTROL                                   (0x1ecU)
#define GPMC_PREFETCH_CONFIG1                                   (0x1e0U)
#define GPMC_BCH_RESULT4_6                                      (0x360U)
#define GPMC_BCH_RESULT1_0                                      (0x244U)
#define GPMC_BCH_RESULT4_4                                      (0x340U)
#define GPMC_BCH_RESULT6_0                                      (0x308U)
#define GPMC_BCH_RESULT0_1                                      (0x250U)
#define GPMC_ECC7_RESULT                                        (0x218U)
#define GPMC_BCH_RESULT4_0                                      (0x300U)
#define GPMC_BCH_RESULT2_2                                      (0x268U)
#define GPMC_BCH_RESULT5_3                                      (0x334U)
#define GPMC_BCH_SWDATA                                         (0x2d0U)
#define GPMC_BCH_RESULT0_3                                      (0x270U)
#define GPMC_BCH_RESULT0_0                                      (0x240U)
#define GPMC_BCH_RESULT5_6                                      (0x364U)
#define GPMC_ECC8_RESULT                                        (0x21cU)
#define GPMC_BCH_RESULT0_5                                      (0x290U)
#define GPMC_ECC9_RESULT                                        (0x220U)
#define GPMC_BCH_RESULT4_2                                      (0x320U)
#define GPMC_BCH_RESULT3_1                                      (0x25cU)
#define GPMC_BCH_RESULT5_0                                      (0x304U)
#define GPMC_BCH_RESULT6_5                                      (0x358U)
#define GPMC_BCH_RESULT3_5                                      (0x29cU)
#define GPMC_ECC1_RESULT                                        (0x200U)
#define GPMC_ECC3_RESULT                                        (0x208U)
#define GPMC_BCH_RESULT0_6                                      (0x2a0U)
#define GPMC_BCH_RESULT6_6                                      (0x368U)
#define GPMC_ECC6_RESULT                                        (0x214U)
#define GPMC_BCH_RESULT1_2                                      (0x264U)
#define GPMC_BCH_RESULT2_1                                      (0x258U)
#define GPMC_BCH_RESULT5_4                                      (0x344U)
#define GPMC_BCH_RESULT1_5                                      (0x294U)
#define GPMC_BCH_RESULT3_3                                      (0x27cU)
#define GPMC_BCH_RESULT2_5                                      (0x298U)
#define GPMC_BCH_RESULT4_5                                      (0x350U)
#define GPMC_BCH_RESULT6_3                                      (0x338U)
#define GPMC_BCH_RESULT5_2                                      (0x324U)
#define GPMC_BCH_RESULT3_6                                      (0x2acU)
#define GPMC_BCH_RESULT4_1                                      (0x310U)
#define GPMC_BCH_RESULT6_1                                      (0x318U)
#define GPMC_ECC2_RESULT                                        (0x204U)
#define GPMC_BCH_RESULT6_4                                      (0x348U)
#define GPMC_BCH_RESULT0_4                                      (0x280U)
#define GPMC_BCH_RESULT1_6                                      (0x2a4U)
#define GPMC_BCH_RESULT3_0                                      (0x24cU)
#define GPMC_BCH_RESULT0_2                                      (0x260U)
#define GPMC_ECC5_RESULT                                        (0x210U)
#define GPMC_BCH_RESULT3_2                                      (0x26cU)
#define GPMC_BCH_RESULT4_3                                      (0x330U)
#define GPMC_BCH_RESULT1_4                                      (0x284U)
#define GPMC_BCH_RESULT2_4                                      (0x288U)
#define GPMC_BCH_RESULT3_4                                      (0x28cU)
#define GPMC_BCH_RESULT2_3                                      (0x278U)
#define GPMC_ECC4_RESULT                                        (0x20cU)
#define GPMC_BCH_RESULT2_6                                      (0x2a8U)
#define GPMC_BCH_RESULT5_1                                      (0x314U)
#define GPMC_BCH_RESULT1_3                                      (0x274U)
#define GPMC_BCH_RESULT1_1                                      (0x254U)
#define GPMC_BCH_RESULT5_5                                      (0x354U)
#define GPMC_BCH_RESULT2_0                                      (0x248U)
#define GPMC_BCH_RESULT6_2                                      (0x328U)

#define GPMC_ECC_RESULT(m)                                      ((uint32_t)(0x200 + (((m) - 1) * (0x4))))
#define GPMC_ECC_RESULT_NUM_ELEMS                               (9U)

#define GPMC_BCH_RESULT0(m)                                     ((uint32_t)0x240 + ((m) * 0x10U))

#define GPMC_BCH_RESULT1(m)                                     ((uint32_t)0x244 + ((m) * 0x10U))

#define GPMC_BCH_RESULT2(m)                                     ((uint32_t)0x248 + ((m) * 0x10U))

#define GPMC_BCH_RESULT3(m)                                     ((uint32_t)0x24C + ((m) * 0x10U))

#define GPMC_BCH_RESULT4(m)                                     ((uint32_t)0x300 + ((m) * 0x10U))

#define GPMC_BCH_RESULT5(m)                                     ((uint32_t)0x304 + ((m) * 0x10U))

#define GPMC_BCH_RESULT6(m)                                     ((uint32_t)0x308 + ((m) * 0x10U))

#define GPMC_BCH_RESULT_NUM_ELEMS                               (7U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define GPMC_IRQENABLE_FIFOEVENTENABLE_SHIFT                    (0U)
#define GPMC_IRQENABLE_FIFOEVENTENABLE_MASK                     (0x00000001U)
#define GPMC_IRQENABLE_FIFOEVENTENABLE_FIFOENABLED               (1U)
#define GPMC_IRQENABLE_FIFOEVENTENABLE_FIFOMASKED                (0U)

#define GPMC_IRQENABLE_TERMINALCOUNTEVENTENABLE_SHIFT           (1U)
#define GPMC_IRQENABLE_TERMINALCOUNTEVENTENABLE_MASK            (0x00000002U)
#define GPMC_IRQENABLE_TERMINALCOUNTEVENTENABLE_TCMASKED         (0U)
#define GPMC_IRQENABLE_TERMINALCOUNTEVENTENABLE_TCENABLED        (1U)

#define GPMC_IRQENABLE_WAIT0EDGEDETECTIONENABLE_SHIFT           (8U)
#define GPMC_IRQENABLE_WAIT0EDGEDETECTIONENABLE_MASK            (0x00000100U)
#define GPMC_IRQENABLE_WAIT0EDGEDETECTIONENABLE_W0ENABLED        (1U)
#define GPMC_IRQENABLE_WAIT0EDGEDETECTIONENABLE_W0MASKED         (0U)

#define GPMC_IRQENABLE_WAIT1EDGEDETECTIONENABLE_SHIFT           (9U)
#define GPMC_IRQENABLE_WAIT1EDGEDETECTIONENABLE_MASK            (0x00000200U)
#define GPMC_IRQENABLE_WAIT1EDGEDETECTIONENABLE_W1ENABLED        (1U)
#define GPMC_IRQENABLE_WAIT1EDGEDETECTIONENABLE_W1MASKED         (0U)

#define GPMC_ERR_TYPE_ERRORVALID_SHIFT                          (0U)
#define GPMC_ERR_TYPE_ERRORVALID_MASK                           (0x00000001U)
#define GPMC_ERR_TYPE_ERRORVALID_ERRDETECT                       (1U)
#define GPMC_ERR_TYPE_ERRORVALID_NOTVALID                        (0U)

#define GPMC_ERR_TYPE_ERRORTIMEOUT_SHIFT                        (2U)
#define GPMC_ERR_TYPE_ERRORTIMEOUT_MASK                         (0x00000004U)
#define GPMC_ERR_TYPE_ERRORTIMEOUT                               (1U)
#define GPMC_ERR_TYPE_ERRORTIMEOUT_NOERR                         (0U)

#define GPMC_ERR_TYPE_ERRORNOTSUPPMCMD_SHIFT                    (3U)
#define GPMC_ERR_TYPE_ERRORNOTSUPPMCMD_MASK                     (0x00000008U)
#define GPMC_ERR_TYPE_ERRORNOTSUPPMCMD                           (1U)
#define GPMC_ERR_TYPE_ERRORNOTSUPPMCMD_NOERR                     (0U)

#define GPMC_ERR_TYPE_ERRORNOTSUPPADD_SHIFT                     (4U)
#define GPMC_ERR_TYPE_ERRORNOTSUPPADD_MASK                      (0x00000010U)
#define GPMC_ERR_TYPE_ERRORNOTSUPPADD_NOERR                      (0U)
#define GPMC_ERR_TYPE_ERRORNOTSUPPADD                            (1U)

#define GPMC_ERR_TYPE_ILLEGALMCMD_SHIFT                         (8U)
#define GPMC_ERR_TYPE_ILLEGALMCMD_MASK                          (0x00000700U)

#define GPMC_IRQSTATUS_FIFOEVENTSTATUS_SHIFT                    (0U)
#define GPMC_IRQSTATUS_FIFOEVENTSTATUS_MASK                     (0x00000001U)
#define GPMC_IRQSTATUS_FIFOEVENTSTATUS_NO                        (0U)
#define GPMC_IRQSTATUS_FIFOEVENTSTATUS_ATLEAST                   (1U)
#define GPMC_IRQSTATUS_FIFOEVENTSTATUS_LESS                      (0U)
#define GPMC_IRQSTATUS_FIFOEVENTSTATUS_RESET                     (1U)

#define GPMC_IRQSTATUS_TERMINALCOUNTSTATUS_SHIFT                (1U)
#define GPMC_IRQSTATUS_TERMINALCOUNTSTATUS_MASK                 (0x00000002U)
#define GPMC_IRQSTATUS_TERMINALCOUNTSTATUS_RESET                 (1U)
#define GPMC_IRQSTATUS_TERMINALCOUNTSTATUS_GREATER_THAN_0        (0U)
#define GPMC_IRQSTATUS_TERMINALCOUNTSTATUS_NO                    (0U)
#define GPMC_IRQSTATUS_TERMINALCOUNTSTATUS_ZERO                  (1U)

#define GPMC_IRQSTATUS_WAIT0EDGEDETECTIONSTATUS_SHIFT           (8U)
#define GPMC_IRQSTATUS_WAIT0EDGEDETECTIONSTATUS_MASK            (0x00000100U)
#define GPMC_IRQSTATUS_WAIT0EDGEDETECTIONSTATUS_NOTDETECTED      (0U)
#define GPMC_IRQSTATUS_WAIT0EDGEDETECTIONSTATUS_NO               (0U)
#define GPMC_IRQSTATUS_WAIT0EDGEDETECTIONSTATUS_RESET            (1U)
#define GPMC_IRQSTATUS_WAIT0EDGEDETECTIONSTATUS_DETECTED         (1U)

#define GPMC_IRQSTATUS_WAIT1EDGEDETECTIONSTATUS_SHIFT           (9U)
#define GPMC_IRQSTATUS_WAIT1EDGEDETECTIONSTATUS_MASK            (0x00000200U)
#define GPMC_IRQSTATUS_WAIT1EDGEDETECTIONSTATUS_RESET            (1U)
#define GPMC_IRQSTATUS_WAIT1EDGEDETECTIONSTATUS_DETECTED         (1U)
#define GPMC_IRQSTATUS_WAIT1EDGEDETECTIONSTATUS_NOTDETECTED      (0U)
#define GPMC_IRQSTATUS_WAIT1EDGEDETECTIONSTATUS_NO               (0U)

#define GPMC_SYSSTATUS_RESETDONE_SHIFT                          (0U)
#define GPMC_SYSSTATUS_RESETDONE_MASK                           (0x00000001U)
#define GPMC_SYSSTATUS_RESETDONE_RSTONGOING                      (0U)
#define GPMC_SYSSTATUS_RESETDONE_RSTDONE                         (1U)

#define GPMC_STATUS_EMPTYWRITEBUFFERSTATUS_SHIFT                (0U)
#define GPMC_STATUS_EMPTYWRITEBUFFERSTATUS_MASK                 (0x00000001U)
#define GPMC_STATUS_EMPTYWRITEBUFFERSTATUS_EMPTY                 (1U)
#define GPMC_STATUS_EMPTYWRITEBUFFERSTATUS_NOTEMPTY              (0U)

#define GPMC_STATUS_WAIT0STATUS_SHIFT                           (8U)
#define GPMC_STATUS_WAIT0STATUS_MASK                            (0x00000100U)
#define GPMC_STATUS_WAIT0STATUS_W0ASSERTED                       (0U)
#define GPMC_STATUS_WAIT0STATUS_W0NOTASSERTED                    (1U)

#define GPMC_STATUS_WAIT1STATUS_SHIFT                           (9U)
#define GPMC_STATUS_WAIT1STATUS_MASK                            (0x00000200U)
#define GPMC_STATUS_WAIT1STATUS_W1NOTASSERTED                    (1U)
#define GPMC_STATUS_WAIT1STATUS_W1ASSERTED                       (0U)

#define GPMC_REVISION_REV_SHIFT                                 (0U)
#define GPMC_REVISION_REV_MASK                                  (0x000000ffU)

#define GPMC_SYSCONFIG_AUTOIDLE_SHIFT                           (0U)
#define GPMC_SYSCONFIG_AUTOIDLE_MASK                            (0x00000001U)
#define GPMC_SYSCONFIG_AUTOIDLE_FREERUN                          (0U)
#define GPMC_SYSCONFIG_AUTOIDLE_AUTORUN                          (1U)

#define GPMC_SYSCONFIG_SOFTRESET_SHIFT                          (1U)
#define GPMC_SYSCONFIG_SOFTRESET_MASK                           (0x00000002U)
#define GPMC_SYSCONFIG_SOFTRESET_NORMAL                          (0U)
#define GPMC_SYSCONFIG_SOFTRESET_RESET                           (1U)

#define GPMC_SYSCONFIG_SIDLEMODE_SHIFT                          (3U)
#define GPMC_SYSCONFIG_SIDLEMODE_MASK                           (0x00000018U)
#define GPMC_SYSCONFIG_SIDLEMODE_RSERVED                         (3U)
#define GPMC_SYSCONFIG_SIDLEMODE_SMARTIDLE                       (2U)
#define GPMC_SYSCONFIG_SIDLEMODE_FORCEIDLE                       (0U)
#define GPMC_SYSCONFIG_SIDLEMODE_NOIDLE                          (1U)

#define GPMC_CONFIG_NANDFORCEPOSTEDWRITE_SHIFT                  (0U)
#define GPMC_CONFIG_NANDFORCEPOSTEDWRITE_MASK                   (0x00000001U)
#define GPMC_CONFIG_NANDFORCEPOSTEDWRITE_FORCEPWR                (1U)
#define GPMC_CONFIG_NANDFORCEPOSTEDWRITE_NOFORCEPWR              (0U)

#define GPMC_CONFIG_LIMITEDADDRESS_SHIFT                        (1U)
#define GPMC_CONFIG_LIMITEDADDRESS_MASK                         (0x00000002U)
#define GPMC_CONFIG_LIMITEDADDRESS_NOLIMITED                     (0U)
#define GPMC_CONFIG_LIMITEDADDRESS_LIMITED                       (1U)

#define GPMC_CONFIG_WRITEPROTECT_SHIFT                          (4U)
#define GPMC_CONFIG_WRITEPROTECT_MASK                           (0x00000010U)
#define GPMC_CONFIG_WRITEPROTECT_WPLOW                           (0U)
#define GPMC_CONFIG_WRITEPROTECT_WPHIGH                          (1U)

#define GPMC_CONFIG_WAIT0PINPOLARITY_SHIFT                      (8U)
#define GPMC_CONFIG_WAIT0PINPOLARITY_MASK                       (0x00000100U)
#define GPMC_CONFIG_WAIT0PINPOLARITY_W0ACTIVEL                   (0U)
#define GPMC_CONFIG_WAIT0PINPOLARITY_W0ACTIVEH                   (1U)

#define GPMC_CONFIG_WAIT1PINPOLARITY_SHIFT                      (9U)
#define GPMC_CONFIG_WAIT1PINPOLARITY_MASK                       (0x00000200U)
#define GPMC_CONFIG_WAIT1PINPOLARITY_W1ACTIVEL                   (0U)
#define GPMC_CONFIG_WAIT1PINPOLARITY_W1ACTIVEH                   (1U)

#define GPMC_ERR_ADDRESS_ILLEGALADD_SHIFT                       (0U)
#define GPMC_ERR_ADDRESS_ILLEGALADD_MASK                        (0x7fffffffU)

#define GPMC_TIMEOUT_CONTROL_TIMEOUTENABLE_SHIFT                (0U)
#define GPMC_TIMEOUT_CONTROL_TIMEOUTENABLE_MASK                 (0x00000001U)
#define GPMC_TIMEOUT_CONTROL_TIMEOUTENABLE_TODISABLED            (0U)
#define GPMC_TIMEOUT_CONTROL_TIMEOUTENABLE_TOENABLED             (1U)

#define GPMC_TIMEOUT_CONTROL_TIMEOUTSTARTVALUE_SHIFT            (4U)
#define GPMC_TIMEOUT_CONTROL_TIMEOUTSTARTVALUE_MASK             (0x00001ff0U)

#define GPMC_CONFIG1_GPMCFCLKDIVIDER_SHIFT                      (0U)
#define GPMC_CONFIG1_GPMCFCLKDIVIDER_MASK                       (0x00000003U)
#define GPMC_CONFIG1_GPMCFCLKDIVIDER_DIVBY4                      (3U)
#define GPMC_CONFIG1_GPMCFCLKDIVIDER_DIVBY2                      (1U)
#define GPMC_CONFIG1_GPMCFCLKDIVIDER_DIVBY3                      (2U)
#define GPMC_CONFIG1_GPMCFCLKDIVIDER_DIVBY1                      (0U)

#define GPMC_CONFIG1_TIMEPARAGRANULARITY_SHIFT                  (4U)
#define GPMC_CONFIG1_TIMEPARAGRANULARITY_MASK                   (0x00000010U)
#define GPMC_CONFIG1_TIMEPARAGRANULARITY_X1                      (0U)
#define GPMC_CONFIG1_TIMEPARAGRANULARITY_X2                      (1U)

#define GPMC_CONFIG1_MUXADDDATA_SHIFT                           (8U)
#define GPMC_CONFIG1_MUXADDDATA_MASK                            (0x00000300U)
#define GPMC_CONFIG1_MUXADDDATA_MUX                              (2U)
#define GPMC_CONFIG1_MUXADDDATA_AADMUX                           (1U)
#define GPMC_CONFIG1_MUXADDDATA_RESERVED                         (3U)
#define GPMC_CONFIG1_MUXADDDATA_NONMUX                           (0U)

#define GPMC_CONFIG1_DEVICETYPE_SHIFT                           (10U)
#define GPMC_CONFIG1_DEVICETYPE_MASK                            (0x00000c00U)
#define GPMC_CONFIG1_DEVICETYPE_NORLIKE                          (0U)
#define GPMC_CONFIG1_DEVICETYPE_RESERVED2                        (3U)
#define GPMC_CONFIG1_DEVICETYPE_RESERVED1                        (1U)
#define GPMC_CONFIG1_DEVICETYPE_NANDLIKE                         (2U)

#define GPMC_CONFIG1_DEVICESIZE_SHIFT                           (12U)
#define GPMC_CONFIG1_DEVICESIZE_MASK                            (0x00003000U)
#define GPMC_CONFIG1_DEVICESIZE_EIGHTBITS                        (0U)
#define GPMC_CONFIG1_DEVICESIZE_SIXTEENBITS                      (1U)
#define GPMC_CONFIG1_DEVICESIZE_RESERVED1                        (2U)
#define GPMC_CONFIG1_DEVICESIZE_RESERVED2                        (3U)

#define GPMC_CONFIG1_WAITPINSELECT_SHIFT                        (16U)
#define GPMC_CONFIG1_WAITPINSELECT_MASK                         (0x00030000U)
#define GPMC_CONFIG1_WAITPINSELECT_W0                            (0U)
#define GPMC_CONFIG1_WAITPINSELECT_W1                            (1U)
#define GPMC_CONFIG1_WAITPINSELECT_RESERVED1                     (2U)
#define GPMC_CONFIG1_WAITPINSELECT_RESERVED2                     (3U)

#define GPMC_CONFIG1_WAITMONITORINGTIME_SHIFT                   (18U)
#define GPMC_CONFIG1_WAITMONITORINGTIME_MASK                    (0x000c0000U)
#define GPMC_CONFIG1_WAITMONITORINGTIME_ONEDEVICEB4              (1U)
#define GPMC_CONFIG1_WAITMONITORINGTIME_ATVALID                  (0U)
#define GPMC_CONFIG1_WAITMONITORINGTIME_RESERVED                 (3U)
#define GPMC_CONFIG1_WAITMONITORINGTIME_TWODEVICEB4              (2U)

#define GPMC_CONFIG1_WAITWRITEMONITORING_SHIFT                  (21U)
#define GPMC_CONFIG1_WAITWRITEMONITORING_MASK                   (0x00200000U)
#define GPMC_CONFIG1_WAITWRITEMONITORING_WMONIT                  (1U)
#define GPMC_CONFIG1_WAITWRITEMONITORING_WNOTMONIT               (0U)

#define GPMC_CONFIG1_WAITREADMONITORING_SHIFT                   (22U)
#define GPMC_CONFIG1_WAITREADMONITORING_MASK                    (0x00400000U)
#define GPMC_CONFIG1_WAITREADMONITORING_WNOTMONIT                (0U)
#define GPMC_CONFIG1_WAITREADMONITORING_WMONIT                   (1U)

#define GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH_SHIFT             (23U)
#define GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH_MASK              (0x01800000U)
#define GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH_EIGHT              (1U)
#define GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH_SIXTEEN            (2U)
#define GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH_RESERVED           (3U)
#define GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH_FOUR               (0U)

#define GPMC_CONFIG1_CLKACTIVATIONTIME_SHIFT                    (25U)
#define GPMC_CONFIG1_CLKACTIVATIONTIME_MASK                     (0x06000000U)
#define GPMC_CONFIG1_CLKACTIVATIONTIME_ATSTART                   (0U)
#define GPMC_CONFIG1_CLKACTIVATIONTIME_TWOCLKB4                  (2U)
#define GPMC_CONFIG1_CLKACTIVATIONTIME_RESERVED                  (3U)
#define GPMC_CONFIG1_CLKACTIVATIONTIME_ONECLKB4                  (1U)

#define GPMC_CONFIG1_WRITETYPE_SHIFT                            (27U)
#define GPMC_CONFIG1_WRITETYPE_MASK                             (0x08000000U)
#define GPMC_CONFIG1_WRITETYPE_WRASYNC                           (0U)
#define GPMC_CONFIG1_WRITETYPE_WRSYNC                            (1U)

#define GPMC_CONFIG1_WRITEMULTIPLE_SHIFT                        (28U)
#define GPMC_CONFIG1_WRITEMULTIPLE_MASK                         (0x10000000U)
#define GPMC_CONFIG1_WRITEMULTIPLE_WRSINGLE                      (0U)
#define GPMC_CONFIG1_WRITEMULTIPLE_WRMULTIPLE                    (1U)

#define GPMC_CONFIG1_READTYPE_SHIFT                             (29U)
#define GPMC_CONFIG1_READTYPE_MASK                              (0x20000000U)
#define GPMC_CONFIG1_READTYPE_RDSYNC                             (1U)
#define GPMC_CONFIG1_READTYPE_RDASYNC                            (0U)

#define GPMC_CONFIG1_READMULTIPLE_SHIFT                         (30U)
#define GPMC_CONFIG1_READMULTIPLE_MASK                          (0x40000000U)
#define GPMC_CONFIG1_READMULTIPLE_RDMULTIPLE                     (1U)
#define GPMC_CONFIG1_READMULTIPLE_RDSINGLE                       (0U)

#define GPMC_CONFIG1_WRAPBURST_SHIFT                            (31U)
#define GPMC_CONFIG1_WRAPBURST_MASK                             (0x80000000U)
#define GPMC_CONFIG1_WRAPBURST_WRAPNOTSUPP                       (0U)
#define GPMC_CONFIG1_WRAPBURST_WRAPSUPP                          (1U)

#define GPMC_CONFIG2_CSONTIME_SHIFT                             (0U)
#define GPMC_CONFIG2_CSONTIME_MASK                              (0x0000000fU)
#define GPMC_CONFIG2_CSONTIME_ZERO                               (0U)
#define GPMC_CONFIG2_CSONTIME_FIFTEEN                            (31U)
#define GPMC_CONFIG2_CSONTIME_ONE                                (1U)

#define GPMC_CONFIG2_CSEXTRADELAY_SHIFT                         (7U)
#define GPMC_CONFIG2_CSEXTRADELAY_MASK                          (0x00000080U)
#define GPMC_CONFIG2_CSEXTRADELAY_NOTDELAYED                     (0U)
#define GPMC_CONFIG2_CSEXTRADELAY_DELAYED                        (1U)

#define GPMC_CONFIG2_CSRDOFFTIME_SHIFT                          (8U)
#define GPMC_CONFIG2_CSRDOFFTIME_MASK                           (0x00001f00U)
#define GPMC_CONFIG2_CSRDOFFTIME_ZERO                            (0U)
#define GPMC_CONFIG2_CSRDOFFTIME_ONE                             (1U)
#define GPMC_CONFIG2_CSRDOFFTIME_THIRTYONE                       (31U)

#define GPMC_CONFIG2_CSWROFFTIME_SHIFT                          (16U)
#define GPMC_CONFIG2_CSWROFFTIME_MASK                           (0x001f0000U)
#define GPMC_CONFIG2_CSWROFFTIME_ZERO                            (0U)
#define GPMC_CONFIG2_CSWROFFTIME_ONE                             (1U)
#define GPMC_CONFIG2_CSWROFFTIME_THIRTYONE                       (31U)

#define GPMC_CONFIG3_ADVONTIME_SHIFT                            (0U)
#define GPMC_CONFIG3_ADVONTIME_MASK                             (0x0000000fU)
#define GPMC_CONFIG3_ADVONTIME_ZERO                              (0U)
#define GPMC_CONFIG3_ADVONTIME_ONE                               (1U)
#define GPMC_CONFIG3_ADVONTIME_FIFTEEN                           (15U)

#define GPMC_CONFIG3_ADVAADMUXONTIME_SHIFT                      (4U)
#define GPMC_CONFIG3_ADVAADMUXONTIME_MASK                       (0x00000070U)
#define GPMC_CONFIG3_ADVAADMUXONTIME_ZERO                        (0U)
#define GPMC_CONFIG3_ADVAADMUXONTIME_ONE                         (1U)
#define GPMC_CONFIG3_ADVAADMUXONTIME_SEVEN                       (7U)

#define GPMC_CONFIG3_ADVEXTRADELAY_SHIFT                        (7U)
#define GPMC_CONFIG3_ADVEXTRADELAY_MASK                         (0x00000080U)
#define GPMC_CONFIG3_ADVEXTRADELAY_DELAYED                       (1U)
#define GPMC_CONFIG3_ADVEXTRADELAY_NOTDELAYED                    (0U)

#define GPMC_CONFIG3_ADVRDOFFTIME_SHIFT                         (8U)
#define GPMC_CONFIG3_ADVRDOFFTIME_MASK                          (0x00001f00U)
#define GPMC_CONFIG3_ADVRDOFFTIME_ZERO                           (0U)
#define GPMC_CONFIG3_ADVRDOFFTIME_ONE                            (1U)
#define GPMC_CONFIG3_ADVRDOFFTIME_THIRTYONE                      (31U)

#define GPMC_CONFIG3_ADVWROFFTIME_SHIFT                         (16U)
#define GPMC_CONFIG3_ADVWROFFTIME_MASK                          (0x001f0000U)
#define GPMC_CONFIG3_ADVWROFFTIME_ZERO                           (0U)
#define GPMC_CONFIG3_ADVWROFFTIME_ONE                            (1U)
#define GPMC_CONFIG3_ADVWROFFTIME_THIRTYONE                      (31U)

#define GPMC_CONFIG3_ADVAADMUXRDOFFTIME_SHIFT                   (24U)
#define GPMC_CONFIG3_ADVAADMUXRDOFFTIME_MASK                    (0x07000000U)
#define GPMC_CONFIG3_ADVAADMUXRDOFFTIME_ZERO                     (0U)
#define GPMC_CONFIG3_ADVAADMUXRDOFFTIME_ONE                      (1U)
#define GPMC_CONFIG3_ADVAADMUXRDOFFTIME_SEVEN                    (7U)

#define GPMC_CONFIG3_ADVAADMUXWROFFTIME_SHIFT                   (28U)
#define GPMC_CONFIG3_ADVAADMUXWROFFTIME_MASK                    (0x70000000U)
#define GPMC_CONFIG3_ADVAADMUXWROFFTIME_ZERO                     (0U)
#define GPMC_CONFIG3_ADVAADMUXWROFFTIME_ONE                      (1U)
#define GPMC_CONFIG3_ADVAADMUXWROFFTIME_SEVEN                    (7U)

#define GPMC_CONFIG4_OEONTIME_SHIFT                             (0U)
#define GPMC_CONFIG4_OEONTIME_MASK                              (0x0000000fU)
#define GPMC_CONFIG4_OEONTIME_ZERO                               (0U)
#define GPMC_CONFIG4_OEONTIME_ONE                                (1U)
#define GPMC_CONFIG4_OEONTIME_FIFTEEN                            (15U)

#define GPMC_CONFIG4_OEAADMUXONTIME_SHIFT                       (4U)
#define GPMC_CONFIG4_OEAADMUXONTIME_MASK                        (0x00000070U)
#define GPMC_CONFIG4_OEAADMUXONTIME_ZERO                         (0U)
#define GPMC_CONFIG4_OEAADMUXONTIME_ONE                          (1U)
#define GPMC_CONFIG4_OEAADMUXONTIME_SEVEN                        (7U)

#define GPMC_CONFIG4_OEEXTRADELAY_SHIFT                         (7U)
#define GPMC_CONFIG4_OEEXTRADELAY_MASK                          (0x00000080U)
#define GPMC_CONFIG4_OEEXTRADELAY_NOTDELAYED                     (0U)
#define GPMC_CONFIG4_OEEXTRADELAY_DELAYED                        (1U)

#define GPMC_CONFIG4_OEOFFTIME_SHIFT                            (8U)
#define GPMC_CONFIG4_OEOFFTIME_MASK                             (0x00001f00U)
#define GPMC_CONFIG4_OEOFFTIME_ZERO                              (0U)
#define GPMC_CONFIG4_OEOFFTIME_ONE                               (1U)
#define GPMC_CONFIG4_OEOFFTIME_THIRTYONE                         (7U)

#define GPMC_CONFIG4_OEAADMUXOFFTIME_SHIFT                      (13U)
#define GPMC_CONFIG4_OEAADMUXOFFTIME_MASK                       (0x0000e000U)
#define GPMC_CONFIG4_OEAADMUXOFFTIME_ZERO                        (0U)
#define GPMC_CONFIG4_OEAADMUXOFFTIME_ONE                         (1U)
#define GPMC_CONFIG4_OEAADMUXOFFTIME_SEVEN                       (7U)

#define GPMC_CONFIG4_WEONTIME_SHIFT                             (16U)
#define GPMC_CONFIG4_WEONTIME_MASK                              (0x000f0000U)
#define GPMC_CONFIG4_WEONTIME_ZERO                               (0U)
#define GPMC_CONFIG4_WEONTIME_ONE                                (1U)
#define GPMC_CONFIG4_WEONTIME_FIFTEEN                            (15U)

#define GPMC_CONFIG4_WEEXTRADELAY_SHIFT                         (23U)
#define GPMC_CONFIG4_WEEXTRADELAY_MASK                          (0x00800000U)
#define GPMC_CONFIG4_WEEXTRADELAY_DELAYED                        (1U)
#define GPMC_CONFIG4_WEEXTRADELAY_NOTDELAYED                     (0U)

#define GPMC_CONFIG4_WEOFFTIME_SHIFT                            (24U)
#define GPMC_CONFIG4_WEOFFTIME_MASK                             (0x1f000000U)
#define GPMC_CONFIG4_WEOFFTIME_ZERO                              (0U)
#define GPMC_CONFIG4_WEOFFTIME_ONE                               (1U)
#define GPMC_CONFIG4_WEOFFTIME_THIRTYONE                         (31U)

#define GPMC_CONFIG5_RDCYCLETIME_SHIFT                          (0U)
#define GPMC_CONFIG5_RDCYCLETIME_MASK                           (0x0000001fU)
#define GPMC_CONFIG5_RDCYCLETIME_ZERO                            (0U)
#define GPMC_CONFIG5_RDCYCLETIME_ONE                             (1U)
#define GPMC_CONFIG5_RDCYCLETIME_THIRTYONE                       (31U)

#define GPMC_CONFIG5_WRCYCLETIME_SHIFT                          (8U)
#define GPMC_CONFIG5_WRCYCLETIME_MASK                           (0x00001f00U)
#define GPMC_CONFIG5_WRCYCLETIME_ZERO                            (0U)
#define GPMC_CONFIG5_WRCYCLETIME_ONE                             (1U)
#define GPMC_CONFIG5_WRCYCLETIME_THIRTYONE                       (31U)

#define GPMC_CONFIG5_RDACCESSTIME_SHIFT                         (16U)
#define GPMC_CONFIG5_RDACCESSTIME_MASK                          (0x001f0000U)
#define GPMC_CONFIG5_RDACCESSTIME_ZERO                           (0U)
#define GPMC_CONFIG5_RDACCESSTIME_ONE                            (1U)
#define GPMC_CONFIG5_RDACCESSTIME_THIRTYONE                      (31U)

#define GPMC_CONFIG5_PAGEBURSTACCESSTIME_SHIFT                  (24U)
#define GPMC_CONFIG5_PAGEBURSTACCESSTIME_MASK                   (0x0f000000U)
#define GPMC_CONFIG5_PAGEBURSTACCESSTIME_ZERO                    (0U)
#define GPMC_CONFIG5_PAGEBURSTACCESSTIME_ONE                     (1U)
#define GPMC_CONFIG5_PAGEBURSTACCESSTIME_FIFTEEN                 (15U)

#define GPMC_CONFIG6_BUSTURNAROUND_SHIFT                        (0U)
#define GPMC_CONFIG6_BUSTURNAROUND_MASK                         (0x0000000fU)
#define GPMC_CONFIG6_BUSTURNAROUND_ZERO                          (0U)
#define GPMC_CONFIG6_BUSTURNAROUND_ONE                           (1U)
#define GPMC_CONFIG6_BUSTURNAROUND_FIFTEEN                       (15U)

#define GPMC_CONFIG6_CYCLE2CYCLEDIFFCSEN_SHIFT                  (6U)
#define GPMC_CONFIG6_CYCLE2CYCLEDIFFCSEN_MASK                   (0x00000040U)
#define GPMC_CONFIG6_CYCLE2CYCLEDIFFCSEN_NOC2CDELAY              (0U)
#define GPMC_CONFIG6_CYCLE2CYCLEDIFFCSEN_C2CDELAY                (1U)

#define GPMC_CONFIG6_CYCLE2CYCLESAMECSEN_SHIFT                  (7U)
#define GPMC_CONFIG6_CYCLE2CYCLESAMECSEN_MASK                   (0x00000080U)
#define GPMC_CONFIG6_CYCLE2CYCLESAMECSEN_C2CDELAY                (1U)
#define GPMC_CONFIG6_CYCLE2CYCLESAMECSEN_NOC2CDELAY              (0U)

#define GPMC_CONFIG6_CYCLE2CYCLEDELAY_SHIFT                     (8U)
#define GPMC_CONFIG6_CYCLE2CYCLEDELAY_MASK                      (0x00000f00U)
#define GPMC_CONFIG6_CYCLE2CYCLEDELAY_ZERO                       (0U)
#define GPMC_CONFIG6_CYCLE2CYCLEDELAY_ONE                        (1U)
#define GPMC_CONFIG6_CYCLE2CYCLEDELAY_FIFTEEN                    (15U)

#define GPMC_CONFIG6_WRDATAONADMUXBUS_SHIFT                     (16U)
#define GPMC_CONFIG6_WRDATAONADMUXBUS_MASK                      (0x000f0000U)

#define GPMC_CONFIG6_WRACCESSTIME_SHIFT                         (24U)
#define GPMC_CONFIG6_WRACCESSTIME_MASK                          (0x1f000000U)
#define GPMC_CONFIG6_WRACCESSTIME_ZERO                           (0U)
#define GPMC_CONFIG6_WRACCESSTIME_ONE                            (1U)
#define GPMC_CONFIG6_WRACCESSTIME_THIRTYONE                      (31U)

#define GPMC_CONFIG7_BASEADDRESS_SHIFT                          (0U)
#define GPMC_CONFIG7_BASEADDRESS_MASK                           (0x0000003fU)

#define GPMC_CONFIG7_CSVALID_SHIFT                              (6U)
#define GPMC_CONFIG7_CSVALID_MASK                               (0x00000040U)
#define GPMC_CONFIG7_CSVALID_CSDISABLED                          (0U)
#define GPMC_CONFIG7_CSVALID_CSENABLED                           (1U)

#define GPMC_CONFIG7_MASKADDRESS_SHIFT                          (8U)
#define GPMC_CONFIG7_MASKADDRESS_MASK                           (0x00000f00U)
#define GPMC_CONFIG7_MASKADDRESS_SIZE16MB                        (15U)
#define GPMC_CONFIG7_MASKADDRESS_SIZE32MB                        (14U)
#define GPMC_CONFIG7_MASKADDRESS_SIZE128MB                       (8U)
#define GPMC_CONFIG7_MASKADDRESS_SIZE64MB                        (12U)
#define GPMC_CONFIG7_MASKADDRESS_SIZE256MB                       (0U)

#define GPMC_NAND_COMMAND_SHIFT                                 (0U)
#define GPMC_NAND_COMMAND_MASK                                  (0xffffffffU)

#define GPMC_NAND_ADDRESS_SHIFT                                 (0U)
#define GPMC_NAND_ADDRESS_MASK                                  (0xffffffffU)

#define GPMC_NAND_DATA_SHIFT                                    (0U)
#define GPMC_NAND_DATA_MASK                                     (0xffffffffU)

#define GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_SHIFT               (0U)
#define GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_MASK                (0x00000001U)
#define GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_SIZE1SEL             (1U)
#define GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_SIZE0SEL             (0U)

#define GPMC_ECC_SIZE_CONFIG_ECC2RESULTSIZE_SHIFT               (1U)
#define GPMC_ECC_SIZE_CONFIG_ECC2RESULTSIZE_MASK                (0x00000002U)
#define GPMC_ECC_SIZE_CONFIG_ECC2RESULTSIZE_SIZE1SEL             (1U)
#define GPMC_ECC_SIZE_CONFIG_ECC2RESULTSIZE_SIZE0SEL             (0U)

#define GPMC_ECC_SIZE_CONFIG_ECC3RESULTSIZE_SHIFT               (2U)
#define GPMC_ECC_SIZE_CONFIG_ECC3RESULTSIZE_MASK                (0x00000004U)
#define GPMC_ECC_SIZE_CONFIG_ECC3RESULTSIZE_SIZE1SEL             (1U)
#define GPMC_ECC_SIZE_CONFIG_ECC3RESULTSIZE_SIZE0SEL             (0U)

#define GPMC_ECC_SIZE_CONFIG_ECC4RESULTSIZE_SHIFT               (3U)
#define GPMC_ECC_SIZE_CONFIG_ECC4RESULTSIZE_MASK                (0x00000008U)
#define GPMC_ECC_SIZE_CONFIG_ECC4RESULTSIZE_SIZE1SEL             (1U)
#define GPMC_ECC_SIZE_CONFIG_ECC4RESULTSIZE_SIZE0SEL             (0U)

#define GPMC_ECC_SIZE_CONFIG_ECC5RESULTSIZE_SHIFT               (4U)
#define GPMC_ECC_SIZE_CONFIG_ECC5RESULTSIZE_MASK                (0x00000010U)
#define GPMC_ECC_SIZE_CONFIG_ECC5RESULTSIZE_SIZE1SEL             (1U)
#define GPMC_ECC_SIZE_CONFIG_ECC5RESULTSIZE_SIZE0SEL             (0U)

#define GPMC_ECC_SIZE_CONFIG_ECC6RESULTSIZE_SHIFT               (5U)
#define GPMC_ECC_SIZE_CONFIG_ECC6RESULTSIZE_MASK                (0x00000020U)
#define GPMC_ECC_SIZE_CONFIG_ECC6RESULTSIZE_SIZE1SEL             (1U)
#define GPMC_ECC_SIZE_CONFIG_ECC6RESULTSIZE_SIZE0SEL             (0U)

#define GPMC_ECC_SIZE_CONFIG_ECC7RESULTSIZE_SHIFT               (6U)
#define GPMC_ECC_SIZE_CONFIG_ECC7RESULTSIZE_MASK                (0x00000040U)
#define GPMC_ECC_SIZE_CONFIG_ECC7RESULTSIZE_SIZE1SEL             (1U)
#define GPMC_ECC_SIZE_CONFIG_ECC7RESULTSIZE_SIZE0SEL             (0U)

#define GPMC_ECC_SIZE_CONFIG_ECC8RESULTSIZE_SHIFT               (7U)
#define GPMC_ECC_SIZE_CONFIG_ECC8RESULTSIZE_MASK                (0x00000080U)
#define GPMC_ECC_SIZE_CONFIG_ECC8RESULTSIZE_SIZE1SEL             (1U)
#define GPMC_ECC_SIZE_CONFIG_ECC8RESULTSIZE_SIZE0SEL             (0U)

#define GPMC_ECC_SIZE_CONFIG_ECC9RESULTSIZE_SHIFT               (8U)
#define GPMC_ECC_SIZE_CONFIG_ECC9RESULTSIZE_MASK                (0x00000100U)
#define GPMC_ECC_SIZE_CONFIG_ECC9RESULTSIZE_SIZE1SEL             (1U)
#define GPMC_ECC_SIZE_CONFIG_ECC9RESULTSIZE_SIZE0SEL             (0U)

#define GPMC_ECC_SIZE_CONFIG_ECCSIZE0_SHIFT                     (12U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE0_MASK                      (0x000ff000U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE0_FIVE_TWELVE                (255U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE0_TWO                        (0U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE0_FOUR                       (1U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE0_SIX                        (2U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE0_EIGHT                      (3U)

#define GPMC_ECC_SIZE_CONFIG_ECCSIZE1_SHIFT                     (22U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE1_MASK                      (0x3fc00000U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE1_FIVE_TWELVE                (255U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE1_TWO                        (0U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE1_FOUR                       (1U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE1_SIX                        (2U)
#define GPMC_ECC_SIZE_CONFIG_ECCSIZE1_EIGHT                      (3U)

#define GPMC_PREFETCH_CONFIG2_TRANSFERCOUNT_SHIFT               (0U)
#define GPMC_PREFETCH_CONFIG2_TRANSFERCOUNT_MASK                (0x00003fffU)
#define GPMC_PREFETCH_CONFIG2_TRANSFERCOUNT_ONE_B                (1U)
#define GPMC_PREFETCH_CONFIG2_TRANSFERCOUNT_ZERO_B               (0U)
#define GPMC_PREFETCH_CONFIG2_TRANSFERCOUNT_EIGHT_KB             (8192U)

#define GPMC_PREFETCH_STATUS_COUNTVALUE_SHIFT                   (0U)
#define GPMC_PREFETCH_STATUS_COUNTVALUE_MASK                    (0x00003fffU)
#define GPMC_PREFETCH_STATUS_COUNTVALUE_ONE_B                    (1U)
#define GPMC_PREFETCH_STATUS_COUNTVALUE_EIGHT_KB                 (8192U)
#define GPMC_PREFETCH_STATUS_COUNTVALUE_ZERO_B                   (0U)

#define GPMC_PREFETCH_STATUS_FIFOTHRESHOLDSTATUS_SHIFT          (16U)
#define GPMC_PREFETCH_STATUS_FIFOTHRESHOLDSTATUS_MASK           (0x00010000U)
#define GPMC_PREFETCH_STATUS_FIFOTHRESHOLDSTATUS_SMALLERTHANTHRES  (0U)
#define GPMC_PREFETCH_STATUS_FIFOTHRESHOLDSTATUS_GREATERTHANTHRES  (1U)

#define GPMC_PREFETCH_STATUS_FIFOPOINTER_SHIFT                  (24U)
#define GPMC_PREFETCH_STATUS_FIFOPOINTER_MASK                   (0x7f000000U)
#define GPMC_PREFETCH_STATUS_FIFOPOINTER_SIXTYFOUR               (64U)
#define GPMC_PREFETCH_STATUS_FIFOPOINTER_ZERO                    (0U)

#define GPMC_ECC_CONTROL_ECCPOINTER_SHIFT                       (0U)
#define GPMC_ECC_CONTROL_ECCPOINTER_MASK                        (0x0000000fU)
#define GPMC_ECC_CONTROL_ECCPOINTER_ECCRES3                      (3U)
#define GPMC_ECC_CONTROL_ECCPOINTER_ECCRES9                      (9U)
#define GPMC_ECC_CONTROL_ECCPOINTER_ECCRES7                      (7U)
#define GPMC_ECC_CONTROL_ECCPOINTER_ECCRES8                      (8U)
#define GPMC_ECC_CONTROL_ECCPOINTER_NOEFFECT                     (0U)
#define GPMC_ECC_CONTROL_ECCPOINTER_ECCRES1                      (1U)
#define GPMC_ECC_CONTROL_ECCPOINTER_ECCRES2                      (2U)
#define GPMC_ECC_CONTROL_ECCPOINTER_ECCRES6                      (6U)
#define GPMC_ECC_CONTROL_ECCPOINTER_ECCRES4                      (4U)
#define GPMC_ECC_CONTROL_ECCPOINTER_ECCRES5                      (5U)

#define GPMC_ECC_CONTROL_ECCCLEAR_SHIFT                         (8U)
#define GPMC_ECC_CONTROL_ECCCLEAR_MASK                          (0x00000100U)
#define GPMC_ECC_CONTROL_ECCCLEAR_RETURN0                        (0U)
#define GPMC_ECC_CONTROL_ECCCLEAR_CLR                            (1U)
#define GPMC_ECC_CONTROL_ECCCLEAR_IGNORED                        (0U)

#define GPMC_ECC_CONFIG_ECCENABLE_SHIFT                         (0U)
#define GPMC_ECC_CONFIG_ECCENABLE_MASK                          (0x00000001U)
#define GPMC_ECC_CONFIG_ECCENABLE_DISABLED                       (0U)
#define GPMC_ECC_CONFIG_ECCENABLE_ENABLED                        (1U)

#define GPMC_ECC_CONFIG_ECCCS_SHIFT                             (1U)
#define GPMC_ECC_CONFIG_ECCCS_MASK                              (0x0000000eU)
#define GPMC_ECC_CONFIG_ECCCS_CS5                                (5U)
#define GPMC_ECC_CONFIG_ECCCS_CS1                                (1U)
#define GPMC_ECC_CONFIG_ECCCS_CS0                                (0U)
#define GPMC_ECC_CONFIG_ECCCS_RESERVED1                          (6U)
#define GPMC_ECC_CONFIG_ECCCS_RESERVED2                          (7U)
#define GPMC_ECC_CONFIG_ECCCS_CS2                                (2U)
#define GPMC_ECC_CONFIG_ECCCS_CS4                                (4U)
#define GPMC_ECC_CONFIG_ECCCS_CS3                                (3U)

#define GPMC_ECC_CONFIG_ECCTOPSECTOR_SHIFT                      (4U)
#define GPMC_ECC_CONFIG_ECCTOPSECTOR_MASK                       (0x00000070U)
#define GPMC_ECC_CONFIG_ECCTOPSECTOR_EIGHTSECT                   (7U)
#define GPMC_ECC_CONFIG_ECCTOPSECTOR_ONESECT                     (0U)
#define GPMC_ECC_CONFIG_ECCTOPSECTOR_FOURSECT                    (3U)
#define GPMC_ECC_CONFIG_ECCTOPSECTOR_TWOSECT                     (1U)

#define GPMC_ECC_CONFIG_ECC16B_SHIFT                            (7U)
#define GPMC_ECC_CONFIG_ECC16B_MASK                             (0x00000080U)
#define GPMC_ECC_CONFIG_ECC16B_SIXTEENCOL                        (1U)
#define GPMC_ECC_CONFIG_ECC16B_EIGHTCOL                          (0U)

#define GPMC_ECC_CONFIG_ECCWRAPMODE_SHIFT                       (8U)
#define GPMC_ECC_CONFIG_ECCWRAPMODE_MASK                        (0x00000f00U)

#define GPMC_ECC_CONFIG_ECCBCHTSEL_SHIFT                        (12U)
#define GPMC_ECC_CONFIG_ECCBCHTSEL_MASK                         (0x00003000U)
#define GPMC_ECC_CONFIG_ECCBCHTSEL_UPTO_4BITS                    (0U)
#define GPMC_ECC_CONFIG_ECCBCHTSEL_UPTO_8BITS                    (1U)
#define GPMC_ECC_CONFIG_ECCBCHTSEL_RESERVED                      (3U)
#define GPMC_ECC_CONFIG_ECCBCHTSEL_UPTO_16BITS                   (2U)

#define GPMC_ECC_CONFIG_ECCALGORITHM_SHIFT                      (16U)
#define GPMC_ECC_CONFIG_ECCALGORITHM_MASK                       (0x00010000U)
#define GPMC_ECC_CONFIG_ECCALGORITHM_HAMMING_CODE                (0U)
#define GPMC_ECC_CONFIG_ECCALGORITHM_BCH_CODE                    (1U)

#define GPMC_PREFETCH_CONTROL_STARTENGINE_SHIFT                 (0U)
#define GPMC_PREFETCH_CONTROL_STARTENGINE_MASK                  (0x00000001U)
#define GPMC_PREFETCH_CONTROL_STARTENGINE_STOP                   (0U)
#define GPMC_PREFETCH_CONTROL_STARTENGINE_STOPPED                (0U)
#define GPMC_PREFETCH_CONTROL_STARTENGINE_RUNNING                (1U)
#define GPMC_PREFETCH_CONTROL_STARTENGINE_START                  (1U)

#define GPMC_PREFETCH_CONFIG1_ACCESSMODE_SHIFT                  (0U)
#define GPMC_PREFETCH_CONFIG1_ACCESSMODE_MASK                   (0x00000001U)
#define GPMC_PREFETCH_CONFIG1_ACCESSMODE_READ                    (0U)
#define GPMC_PREFETCH_CONFIG1_ACCESSMODE_WRITE_POSTING           (1U)

#define GPMC_PREFETCH_CONFIG1_DMAMODE_SHIFT                     (2U)
#define GPMC_PREFETCH_CONFIG1_DMAMODE_MASK                      (0x00000004U)
#define GPMC_PREFETCH_CONFIG1_DMAMODE_DMAENABLED                 (1U)
#define GPMC_PREFETCH_CONFIG1_DMAMODE_INTERRUPTSYNC              (0U)

#define GPMC_PREFETCH_CONFIG1_SYNCHROMODE_SHIFT                 (3U)
#define GPMC_PREFETCH_CONFIG1_SYNCHROMODE_MASK                  (0x00000008U)
#define GPMC_PREFETCH_CONFIG1_SYNCHROMODE_ATSTART                (0U)
#define GPMC_PREFETCH_CONFIG1_SYNCHROMODE_ATSTARTANDWAIT         (1U)

#define GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_SHIFT             (4U)
#define GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_MASK              (0x00000030U)
#define GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_W1                 (1U)
#define GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_RESERVED1          (2U)
#define GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_RESERVED2          (3U)
#define GPMC_PREFETCH_CONFIG1_WAITPINSELECTOR_W0                 (0U)

#define GPMC_PREFETCH_CONFIG1_ENABLEENGINE_SHIFT                (7U)
#define GPMC_PREFETCH_CONFIG1_ENABLEENGINE_MASK                 (0x00000080U)
#define GPMC_PREFETCH_CONFIG1_ENABLEENGINE_DISABLED              (0U)
#define GPMC_PREFETCH_CONFIG1_ENABLEENGINE_ENABLED               (1U)

#define GPMC_PREFETCH_CONFIG1_FIFOTHRESHOLD_SHIFT               (8U)
#define GPMC_PREFETCH_CONFIG1_FIFOTHRESHOLD_MASK                (0x00007f00U)
#define GPMC_PREFETCH_CONFIG1_FIFOTHRESHOLD_ONE                  (1U)
#define GPMC_PREFETCH_CONFIG1_FIFOTHRESHOLD_ZERO                 (0U)
#define GPMC_PREFETCH_CONFIG1_FIFOTHRESHOLD_SIXTYFOUR            (64U)

#define GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO_SHIFT            (16U)
#define GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO_MASK             (0x000f0000U)
#define GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO_NEXT2ACC          (1U)
#define GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO_NEXT1ACC          (0U)
#define GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO_NEXT16ACC         (15U)

#define GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_SHIFT            (23U)
#define GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_MASK             (0x00800000U)
#define GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_ENABLED           (1U)
#define GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_DISABLED          (0U)

#define GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_SHIFT            (24U)
#define GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_MASK             (0x07000000U)
#define GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS6               (6U)
#define GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS5               (5U)
#define GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS1               (1U)
#define GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS4               (4U)
#define GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS3               (3U)
#define GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS0               (0U)
#define GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS2               (2U)

#define GPMC_PREFETCH_CONFIG1_ENABLEOPTIMIZEDACCESS_SHIFT       (27U)
#define GPMC_PREFETCH_CONFIG1_ENABLEOPTIMIZEDACCESS_MASK        (0x08000000U)
#define GPMC_PREFETCH_CONFIG1_ENABLEOPTIMIZEDACCESS_ENABLED      (1U)
#define GPMC_PREFETCH_CONFIG1_ENABLEOPTIMIZEDACCESS_DISABLED     (0U)

#define GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_SHIFT           (28U)
#define GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_MASK            (0x70000000U)
#define GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_ZERO             (0U)
#define GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_ONE              (1U)
#define GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION_SEVEN            (7U)

#define GPMC_BCH_RESULT4_6_SHIFT                                (0U)
#define GPMC_BCH_RESULT4_6_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT1_0_SHIFT                                (0U)
#define GPMC_BCH_RESULT1_0_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT4_4_SHIFT                                (0U)
#define GPMC_BCH_RESULT4_4_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT6_0_SHIFT                                (0U)
#define GPMC_BCH_RESULT6_0_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT0_1_SHIFT                                (0U)
#define GPMC_BCH_RESULT0_1_MASK                                 (0xffffffffU)

#define GPMC_ECC7_RESULT_P1E_SHIFT                              (0U)
#define GPMC_ECC7_RESULT_P1E_MASK                               (0x00000001U)

#define GPMC_ECC7_RESULT_P2E_SHIFT                              (1U)
#define GPMC_ECC7_RESULT_P2E_MASK                               (0x00000002U)

#define GPMC_ECC7_RESULT_P4E_SHIFT                              (2U)
#define GPMC_ECC7_RESULT_P4E_MASK                               (0x00000004U)

#define GPMC_ECC7_RESULT_P8E_SHIFT                              (3U)
#define GPMC_ECC7_RESULT_P8E_MASK                               (0x00000008U)

#define GPMC_ECC7_RESULT_P16E_SHIFT                             (4U)
#define GPMC_ECC7_RESULT_P16E_MASK                              (0x00000010U)

#define GPMC_ECC7_RESULT_P32E_SHIFT                             (5U)
#define GPMC_ECC7_RESULT_P32E_MASK                              (0x00000020U)

#define GPMC_ECC7_RESULT_P64E_SHIFT                             (6U)
#define GPMC_ECC7_RESULT_P64E_MASK                              (0x00000040U)

#define GPMC_ECC7_RESULT_P128E_SHIFT                            (7U)
#define GPMC_ECC7_RESULT_P128E_MASK                             (0x00000080U)

#define GPMC_ECC7_RESULT_P256E_SHIFT                            (8U)
#define GPMC_ECC7_RESULT_P256E_MASK                             (0x00000100U)

#define GPMC_ECC7_RESULT_P512E_SHIFT                            (9U)
#define GPMC_ECC7_RESULT_P512E_MASK                             (0x00000200U)

#define GPMC_ECC7_RESULT_P1024E_SHIFT                           (10U)
#define GPMC_ECC7_RESULT_P1024E_MASK                            (0x00000400U)

#define GPMC_ECC7_RESULT_P2048E_SHIFT                           (11U)
#define GPMC_ECC7_RESULT_P2048E_MASK                            (0x00000800U)

#define GPMC_ECC7_RESULT_P1O_SHIFT                              (16U)
#define GPMC_ECC7_RESULT_P1O_MASK                               (0x00010000U)

#define GPMC_ECC7_RESULT_P2O_SHIFT                              (17U)
#define GPMC_ECC7_RESULT_P2O_MASK                               (0x00020000U)

#define GPMC_ECC7_RESULT_P4O_SHIFT                              (18U)
#define GPMC_ECC7_RESULT_P4O_MASK                               (0x00040000U)

#define GPMC_ECC7_RESULT_P8O_SHIFT                              (19U)
#define GPMC_ECC7_RESULT_P8O_MASK                               (0x00080000U)

#define GPMC_ECC7_RESULT_P16O_SHIFT                             (20U)
#define GPMC_ECC7_RESULT_P16O_MASK                              (0x00100000U)

#define GPMC_ECC7_RESULT_P32O_SHIFT                             (21U)
#define GPMC_ECC7_RESULT_P32O_MASK                              (0x00200000U)

#define GPMC_ECC7_RESULT_P64O_SHIFT                             (22U)
#define GPMC_ECC7_RESULT_P64O_MASK                              (0x00400000U)

#define GPMC_ECC7_RESULT_P128O_SHIFT                            (23U)
#define GPMC_ECC7_RESULT_P128O_MASK                             (0x00800000U)

#define GPMC_ECC7_RESULT_P256O_SHIFT                            (24U)
#define GPMC_ECC7_RESULT_P256O_MASK                             (0x01000000U)

#define GPMC_ECC7_RESULT_P512O_SHIFT                            (25U)
#define GPMC_ECC7_RESULT_P512O_MASK                             (0x02000000U)

#define GPMC_ECC7_RESULT_P1024O_SHIFT                           (26U)
#define GPMC_ECC7_RESULT_P1024O_MASK                            (0x04000000U)

#define GPMC_ECC7_RESULT_P2048O_SHIFT                           (27U)
#define GPMC_ECC7_RESULT_P2048O_MASK                            (0x08000000U)

#define GPMC_BCH_RESULT4_0_SHIFT                                (0U)
#define GPMC_BCH_RESULT4_0_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT2_2_SHIFT                                (0U)
#define GPMC_BCH_RESULT2_2_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT5_3_SHIFT                                (0U)
#define GPMC_BCH_RESULT5_3_MASK                                 (0xffffffffU)

#define GPMC_BCH_SWDATA_DATA_SHIFT                              (0U)
#define GPMC_BCH_SWDATA_DATA_MASK                               (0x0000ffffU)

#define GPMC_BCH_RESULT0_3_SHIFT                                (0U)
#define GPMC_BCH_RESULT0_3_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT0_0_SHIFT                                (0U)
#define GPMC_BCH_RESULT0_0_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT5_6_SHIFT                                (0U)
#define GPMC_BCH_RESULT5_6_MASK                                 (0xffffffffU)

#define GPMC_ECC8_RESULT_P1E_SHIFT                              (0U)
#define GPMC_ECC8_RESULT_P1E_MASK                               (0x00000001U)

#define GPMC_ECC8_RESULT_P2E_SHIFT                              (1U)
#define GPMC_ECC8_RESULT_P2E_MASK                               (0x00000002U)

#define GPMC_ECC8_RESULT_P4E_SHIFT                              (2U)
#define GPMC_ECC8_RESULT_P4E_MASK                               (0x00000004U)

#define GPMC_ECC8_RESULT_P8E_SHIFT                              (3U)
#define GPMC_ECC8_RESULT_P8E_MASK                               (0x00000008U)

#define GPMC_ECC8_RESULT_P16E_SHIFT                             (4U)
#define GPMC_ECC8_RESULT_P16E_MASK                              (0x00000010U)

#define GPMC_ECC8_RESULT_P32E_SHIFT                             (5U)
#define GPMC_ECC8_RESULT_P32E_MASK                              (0x00000020U)

#define GPMC_ECC8_RESULT_P64E_SHIFT                             (6U)
#define GPMC_ECC8_RESULT_P64E_MASK                              (0x00000040U)

#define GPMC_ECC8_RESULT_P128E_SHIFT                            (7U)
#define GPMC_ECC8_RESULT_P128E_MASK                             (0x00000080U)

#define GPMC_ECC8_RESULT_P256E_SHIFT                            (8U)
#define GPMC_ECC8_RESULT_P256E_MASK                             (0x00000100U)

#define GPMC_ECC8_RESULT_P512E_SHIFT                            (9U)
#define GPMC_ECC8_RESULT_P512E_MASK                             (0x00000200U)

#define GPMC_ECC8_RESULT_P1024E_SHIFT                           (10U)
#define GPMC_ECC8_RESULT_P1024E_MASK                            (0x00000400U)

#define GPMC_ECC8_RESULT_P2048E_SHIFT                           (11U)
#define GPMC_ECC8_RESULT_P2048E_MASK                            (0x00000800U)

#define GPMC_ECC8_RESULT_P1O_SHIFT                              (16U)
#define GPMC_ECC8_RESULT_P1O_MASK                               (0x00010000U)

#define GPMC_ECC8_RESULT_P2O_SHIFT                              (17U)
#define GPMC_ECC8_RESULT_P2O_MASK                               (0x00020000U)

#define GPMC_ECC8_RESULT_P4O_SHIFT                              (18U)
#define GPMC_ECC8_RESULT_P4O_MASK                               (0x00040000U)

#define GPMC_ECC8_RESULT_P8O_SHIFT                              (19U)
#define GPMC_ECC8_RESULT_P8O_MASK                               (0x00080000U)

#define GPMC_ECC8_RESULT_P16O_SHIFT                             (20U)
#define GPMC_ECC8_RESULT_P16O_MASK                              (0x00100000U)

#define GPMC_ECC8_RESULT_P32O_SHIFT                             (21U)
#define GPMC_ECC8_RESULT_P32O_MASK                              (0x00200000U)

#define GPMC_ECC8_RESULT_P64O_SHIFT                             (22U)
#define GPMC_ECC8_RESULT_P64O_MASK                              (0x00400000U)

#define GPMC_ECC8_RESULT_P128O_SHIFT                            (23U)
#define GPMC_ECC8_RESULT_P128O_MASK                             (0x00800000U)

#define GPMC_ECC8_RESULT_P256O_SHIFT                            (24U)
#define GPMC_ECC8_RESULT_P256O_MASK                             (0x01000000U)

#define GPMC_ECC8_RESULT_P512O_SHIFT                            (25U)
#define GPMC_ECC8_RESULT_P512O_MASK                             (0x02000000U)

#define GPMC_ECC8_RESULT_P1024O_SHIFT                           (26U)
#define GPMC_ECC8_RESULT_P1024O_MASK                            (0x04000000U)

#define GPMC_ECC8_RESULT_P2048O_SHIFT                           (27U)
#define GPMC_ECC8_RESULT_P2048O_MASK                            (0x08000000U)

#define GPMC_BCH_RESULT0_5_SHIFT                                (0U)
#define GPMC_BCH_RESULT0_5_MASK                                 (0xffffffffU)

#define GPMC_ECC9_RESULT_P1E_SHIFT                              (0U)
#define GPMC_ECC9_RESULT_P1E_MASK                               (0x00000001U)

#define GPMC_ECC9_RESULT_P2E_SHIFT                              (1U)
#define GPMC_ECC9_RESULT_P2E_MASK                               (0x00000002U)

#define GPMC_ECC9_RESULT_P4E_SHIFT                              (2U)
#define GPMC_ECC9_RESULT_P4E_MASK                               (0x00000004U)

#define GPMC_ECC9_RESULT_P8E_SHIFT                              (3U)
#define GPMC_ECC9_RESULT_P8E_MASK                               (0x00000008U)

#define GPMC_ECC9_RESULT_P16E_SHIFT                             (4U)
#define GPMC_ECC9_RESULT_P16E_MASK                              (0x00000010U)

#define GPMC_ECC9_RESULT_P32E_SHIFT                             (5U)
#define GPMC_ECC9_RESULT_P32E_MASK                              (0x00000020U)

#define GPMC_ECC9_RESULT_P64E_SHIFT                             (6U)
#define GPMC_ECC9_RESULT_P64E_MASK                              (0x00000040U)

#define GPMC_ECC9_RESULT_P128E_SHIFT                            (7U)
#define GPMC_ECC9_RESULT_P128E_MASK                             (0x00000080U)

#define GPMC_ECC9_RESULT_P256E_SHIFT                            (8U)
#define GPMC_ECC9_RESULT_P256E_MASK                             (0x00000100U)

#define GPMC_ECC9_RESULT_P512E_SHIFT                            (9U)
#define GPMC_ECC9_RESULT_P512E_MASK                             (0x00000200U)

#define GPMC_ECC9_RESULT_P1024E_SHIFT                           (10U)
#define GPMC_ECC9_RESULT_P1024E_MASK                            (0x00000400U)

#define GPMC_ECC9_RESULT_P2048E_SHIFT                           (11U)
#define GPMC_ECC9_RESULT_P2048E_MASK                            (0x00000800U)

#define GPMC_ECC9_RESULT_P1O_SHIFT                              (16U)
#define GPMC_ECC9_RESULT_P1O_MASK                               (0x00010000U)

#define GPMC_ECC9_RESULT_P2O_SHIFT                              (17U)
#define GPMC_ECC9_RESULT_P2O_MASK                               (0x00020000U)

#define GPMC_ECC9_RESULT_P4O_SHIFT                              (18U)
#define GPMC_ECC9_RESULT_P4O_MASK                               (0x00040000U)

#define GPMC_ECC9_RESULT_P8O_SHIFT                              (19U)
#define GPMC_ECC9_RESULT_P8O_MASK                               (0x00080000U)

#define GPMC_ECC9_RESULT_P16O_SHIFT                             (20U)
#define GPMC_ECC9_RESULT_P16O_MASK                              (0x00100000U)

#define GPMC_ECC9_RESULT_P32O_SHIFT                             (21U)
#define GPMC_ECC9_RESULT_P32O_MASK                              (0x00200000U)

#define GPMC_ECC9_RESULT_P64O_SHIFT                             (22U)
#define GPMC_ECC9_RESULT_P64O_MASK                              (0x00400000U)

#define GPMC_ECC9_RESULT_P128O_SHIFT                            (23U)
#define GPMC_ECC9_RESULT_P128O_MASK                             (0x00800000U)

#define GPMC_ECC9_RESULT_P256O_SHIFT                            (24U)
#define GPMC_ECC9_RESULT_P256O_MASK                             (0x01000000U)

#define GPMC_ECC9_RESULT_P512O_SHIFT                            (25U)
#define GPMC_ECC9_RESULT_P512O_MASK                             (0x02000000U)

#define GPMC_ECC9_RESULT_P1024O_SHIFT                           (26U)
#define GPMC_ECC9_RESULT_P1024O_MASK                            (0x04000000U)

#define GPMC_ECC9_RESULT_P2048O_SHIFT                           (27U)
#define GPMC_ECC9_RESULT_P2048O_MASK                            (0x08000000U)

#define GPMC_BCH_RESULT4_2_SHIFT                                (0U)
#define GPMC_BCH_RESULT4_2_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT3_1_SHIFT                                (0U)
#define GPMC_BCH_RESULT3_1_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT5_0_SHIFT                                (0U)
#define GPMC_BCH_RESULT5_0_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT6_5_SHIFT                                (0U)
#define GPMC_BCH_RESULT6_5_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT3_5_SHIFT                                (0U)
#define GPMC_BCH_RESULT3_5_MASK                                 (0xffffffffU)

#define GPMC_ECC1_RESULT_P1E_SHIFT                              (0U)
#define GPMC_ECC1_RESULT_P1E_MASK                               (0x00000001U)

#define GPMC_ECC1_RESULT_P2E_SHIFT                              (1U)
#define GPMC_ECC1_RESULT_P2E_MASK                               (0x00000002U)

#define GPMC_ECC1_RESULT_P4E_SHIFT                              (2U)
#define GPMC_ECC1_RESULT_P4E_MASK                               (0x00000004U)

#define GPMC_ECC1_RESULT_P8E_SHIFT                              (3U)
#define GPMC_ECC1_RESULT_P8E_MASK                               (0x00000008U)

#define GPMC_ECC1_RESULT_P16E_SHIFT                             (4U)
#define GPMC_ECC1_RESULT_P16E_MASK                              (0x00000010U)

#define GPMC_ECC1_RESULT_P32E_SHIFT                             (5U)
#define GPMC_ECC1_RESULT_P32E_MASK                              (0x00000020U)

#define GPMC_ECC1_RESULT_P64E_SHIFT                             (6U)
#define GPMC_ECC1_RESULT_P64E_MASK                              (0x00000040U)

#define GPMC_ECC1_RESULT_P128E_SHIFT                            (7U)
#define GPMC_ECC1_RESULT_P128E_MASK                             (0x00000080U)

#define GPMC_ECC1_RESULT_P256E_SHIFT                            (8U)
#define GPMC_ECC1_RESULT_P256E_MASK                             (0x00000100U)

#define GPMC_ECC1_RESULT_P512E_SHIFT                            (9U)
#define GPMC_ECC1_RESULT_P512E_MASK                             (0x00000200U)

#define GPMC_ECC1_RESULT_P1024E_SHIFT                           (10U)
#define GPMC_ECC1_RESULT_P1024E_MASK                            (0x00000400U)

#define GPMC_ECC1_RESULT_P2048E_SHIFT                           (11U)
#define GPMC_ECC1_RESULT_P2048E_MASK                            (0x00000800U)

#define GPMC_ECC1_RESULT_P1O_SHIFT                              (16U)
#define GPMC_ECC1_RESULT_P1O_MASK                               (0x00010000U)

#define GPMC_ECC1_RESULT_P2O_SHIFT                              (17U)
#define GPMC_ECC1_RESULT_P2O_MASK                               (0x00020000U)

#define GPMC_ECC1_RESULT_P4O_SHIFT                              (18U)
#define GPMC_ECC1_RESULT_P4O_MASK                               (0x00040000U)

#define GPMC_ECC1_RESULT_P8O_SHIFT                              (19U)
#define GPMC_ECC1_RESULT_P8O_MASK                               (0x00080000U)

#define GPMC_ECC1_RESULT_P16O_SHIFT                             (20U)
#define GPMC_ECC1_RESULT_P16O_MASK                              (0x00100000U)

#define GPMC_ECC1_RESULT_P32O_SHIFT                             (21U)
#define GPMC_ECC1_RESULT_P32O_MASK                              (0x00200000U)

#define GPMC_ECC1_RESULT_P64O_SHIFT                             (22U)
#define GPMC_ECC1_RESULT_P64O_MASK                              (0x00400000U)

#define GPMC_ECC1_RESULT_P128O_SHIFT                            (23U)
#define GPMC_ECC1_RESULT_P128O_MASK                             (0x00800000U)

#define GPMC_ECC1_RESULT_P256O_SHIFT                            (24U)
#define GPMC_ECC1_RESULT_P256O_MASK                             (0x01000000U)

#define GPMC_ECC1_RESULT_P512O_SHIFT                            (25U)
#define GPMC_ECC1_RESULT_P512O_MASK                             (0x02000000U)

#define GPMC_ECC1_RESULT_P1024O_SHIFT                           (26U)
#define GPMC_ECC1_RESULT_P1024O_MASK                            (0x04000000U)

#define GPMC_ECC1_RESULT_P2048O_SHIFT                           (27U)
#define GPMC_ECC1_RESULT_P2048O_MASK                            (0x08000000U)

#define GPMC_ECC3_RESULT_P1E_SHIFT                              (0U)
#define GPMC_ECC3_RESULT_P1E_MASK                               (0x00000001U)

#define GPMC_ECC3_RESULT_P2E_SHIFT                              (1U)
#define GPMC_ECC3_RESULT_P2E_MASK                               (0x00000002U)

#define GPMC_ECC3_RESULT_P4E_SHIFT                              (2U)
#define GPMC_ECC3_RESULT_P4E_MASK                               (0x00000004U)

#define GPMC_ECC3_RESULT_P8E_SHIFT                              (3U)
#define GPMC_ECC3_RESULT_P8E_MASK                               (0x00000008U)

#define GPMC_ECC3_RESULT_P16E_SHIFT                             (4U)
#define GPMC_ECC3_RESULT_P16E_MASK                              (0x00000010U)

#define GPMC_ECC3_RESULT_P32E_SHIFT                             (5U)
#define GPMC_ECC3_RESULT_P32E_MASK                              (0x00000020U)

#define GPMC_ECC3_RESULT_P64E_SHIFT                             (6U)
#define GPMC_ECC3_RESULT_P64E_MASK                              (0x00000040U)

#define GPMC_ECC3_RESULT_P128E_SHIFT                            (7U)
#define GPMC_ECC3_RESULT_P128E_MASK                             (0x00000080U)

#define GPMC_ECC3_RESULT_P256E_SHIFT                            (8U)
#define GPMC_ECC3_RESULT_P256E_MASK                             (0x00000100U)

#define GPMC_ECC3_RESULT_P512E_SHIFT                            (9U)
#define GPMC_ECC3_RESULT_P512E_MASK                             (0x00000200U)

#define GPMC_ECC3_RESULT_P1024E_SHIFT                           (10U)
#define GPMC_ECC3_RESULT_P1024E_MASK                            (0x00000400U)

#define GPMC_ECC3_RESULT_P2048E_SHIFT                           (11U)
#define GPMC_ECC3_RESULT_P2048E_MASK                            (0x00000800U)

#define GPMC_ECC3_RESULT_P1O_SHIFT                              (16U)
#define GPMC_ECC3_RESULT_P1O_MASK                               (0x00010000U)

#define GPMC_ECC3_RESULT_P2O_SHIFT                              (17U)
#define GPMC_ECC3_RESULT_P2O_MASK                               (0x00020000U)

#define GPMC_ECC3_RESULT_P4O_SHIFT                              (18U)
#define GPMC_ECC3_RESULT_P4O_MASK                               (0x00040000U)

#define GPMC_ECC3_RESULT_P8O_SHIFT                              (19U)
#define GPMC_ECC3_RESULT_P8O_MASK                               (0x00080000U)

#define GPMC_ECC3_RESULT_P16O_SHIFT                             (20U)
#define GPMC_ECC3_RESULT_P16O_MASK                              (0x00100000U)

#define GPMC_ECC3_RESULT_P32O_SHIFT                             (21U)
#define GPMC_ECC3_RESULT_P32O_MASK                              (0x00200000U)

#define GPMC_ECC3_RESULT_P64O_SHIFT                             (22U)
#define GPMC_ECC3_RESULT_P64O_MASK                              (0x00400000U)

#define GPMC_ECC3_RESULT_P128O_SHIFT                            (23U)
#define GPMC_ECC3_RESULT_P128O_MASK                             (0x00800000U)

#define GPMC_ECC3_RESULT_P256O_SHIFT                            (24U)
#define GPMC_ECC3_RESULT_P256O_MASK                             (0x01000000U)

#define GPMC_ECC3_RESULT_P512O_SHIFT                            (25U)
#define GPMC_ECC3_RESULT_P512O_MASK                             (0x02000000U)

#define GPMC_ECC3_RESULT_P1024O_SHIFT                           (26U)
#define GPMC_ECC3_RESULT_P1024O_MASK                            (0x04000000U)

#define GPMC_ECC3_RESULT_P2048O_SHIFT                           (27U)
#define GPMC_ECC3_RESULT_P2048O_MASK                            (0x08000000U)

#define GPMC_BCH_RESULT0_6_SHIFT                                (0U)
#define GPMC_BCH_RESULT0_6_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT6_6_SHIFT                                (0U)
#define GPMC_BCH_RESULT6_6_MASK                                 (0xffffffffU)

#define GPMC_ECC6_RESULT_P1E_SHIFT                              (0U)
#define GPMC_ECC6_RESULT_P1E_MASK                               (0x00000001U)

#define GPMC_ECC6_RESULT_P2E_SHIFT                              (1U)
#define GPMC_ECC6_RESULT_P2E_MASK                               (0x00000002U)

#define GPMC_ECC6_RESULT_P4E_SHIFT                              (2U)
#define GPMC_ECC6_RESULT_P4E_MASK                               (0x00000004U)

#define GPMC_ECC6_RESULT_P8E_SHIFT                              (3U)
#define GPMC_ECC6_RESULT_P8E_MASK                               (0x00000008U)

#define GPMC_ECC6_RESULT_P16E_SHIFT                             (4U)
#define GPMC_ECC6_RESULT_P16E_MASK                              (0x00000010U)

#define GPMC_ECC6_RESULT_P32E_SHIFT                             (5U)
#define GPMC_ECC6_RESULT_P32E_MASK                              (0x00000020U)

#define GPMC_ECC6_RESULT_P64E_SHIFT                             (6U)
#define GPMC_ECC6_RESULT_P64E_MASK                              (0x00000040U)

#define GPMC_ECC6_RESULT_P128E_SHIFT                            (7U)
#define GPMC_ECC6_RESULT_P128E_MASK                             (0x00000080U)

#define GPMC_ECC6_RESULT_P256E_SHIFT                            (8U)
#define GPMC_ECC6_RESULT_P256E_MASK                             (0x00000100U)

#define GPMC_ECC6_RESULT_P512E_SHIFT                            (9U)
#define GPMC_ECC6_RESULT_P512E_MASK                             (0x00000200U)

#define GPMC_ECC6_RESULT_P1024E_SHIFT                           (10U)
#define GPMC_ECC6_RESULT_P1024E_MASK                            (0x00000400U)

#define GPMC_ECC6_RESULT_P2048E_SHIFT                           (11U)
#define GPMC_ECC6_RESULT_P2048E_MASK                            (0x00000800U)

#define GPMC_ECC6_RESULT_P1O_SHIFT                              (16U)
#define GPMC_ECC6_RESULT_P1O_MASK                               (0x00010000U)

#define GPMC_ECC6_RESULT_P2O_SHIFT                              (17U)
#define GPMC_ECC6_RESULT_P2O_MASK                               (0x00020000U)

#define GPMC_ECC6_RESULT_P4O_SHIFT                              (18U)
#define GPMC_ECC6_RESULT_P4O_MASK                               (0x00040000U)

#define GPMC_ECC6_RESULT_P8O_SHIFT                              (19U)
#define GPMC_ECC6_RESULT_P8O_MASK                               (0x00080000U)

#define GPMC_ECC6_RESULT_P16O_SHIFT                             (20U)
#define GPMC_ECC6_RESULT_P16O_MASK                              (0x00100000U)

#define GPMC_ECC6_RESULT_P32O_SHIFT                             (21U)
#define GPMC_ECC6_RESULT_P32O_MASK                              (0x00200000U)

#define GPMC_ECC6_RESULT_P64O_SHIFT                             (22U)
#define GPMC_ECC6_RESULT_P64O_MASK                              (0x00400000U)

#define GPMC_ECC6_RESULT_P128O_SHIFT                            (23U)
#define GPMC_ECC6_RESULT_P128O_MASK                             (0x00800000U)

#define GPMC_ECC6_RESULT_P256O_SHIFT                            (24U)
#define GPMC_ECC6_RESULT_P256O_MASK                             (0x01000000U)

#define GPMC_ECC6_RESULT_P512O_SHIFT                            (25U)
#define GPMC_ECC6_RESULT_P512O_MASK                             (0x02000000U)

#define GPMC_ECC6_RESULT_P1024O_SHIFT                           (26U)
#define GPMC_ECC6_RESULT_P1024O_MASK                            (0x04000000U)

#define GPMC_ECC6_RESULT_P2048O_SHIFT                           (27U)
#define GPMC_ECC6_RESULT_P2048O_MASK                            (0x08000000U)

#define GPMC_BCH_RESULT1_2_SHIFT                                (0U)
#define GPMC_BCH_RESULT1_2_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT2_1_SHIFT                                (0U)
#define GPMC_BCH_RESULT2_1_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT5_4_SHIFT                                (0U)
#define GPMC_BCH_RESULT5_4_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT1_5_SHIFT                                (0U)
#define GPMC_BCH_RESULT1_5_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT3_3_SHIFT                                (0U)
#define GPMC_BCH_RESULT3_3_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT2_5_SHIFT                                (0U)
#define GPMC_BCH_RESULT2_5_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT4_5_SHIFT                                (0U)
#define GPMC_BCH_RESULT4_5_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT6_3_SHIFT                                (0U)
#define GPMC_BCH_RESULT6_3_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT5_2_SHIFT                                (0U)
#define GPMC_BCH_RESULT5_2_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT3_6_SHIFT                                (0U)
#define GPMC_BCH_RESULT3_6_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT4_1_SHIFT                                (0U)
#define GPMC_BCH_RESULT4_1_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT6_1_SHIFT                                (0U)
#define GPMC_BCH_RESULT6_1_MASK                                 (0xffffffffU)

#define GPMC_ECC2_RESULT_P1E_SHIFT                              (0U)
#define GPMC_ECC2_RESULT_P1E_MASK                               (0x00000001U)

#define GPMC_ECC2_RESULT_P2E_SHIFT                              (1U)
#define GPMC_ECC2_RESULT_P2E_MASK                               (0x00000002U)

#define GPMC_ECC2_RESULT_P4E_SHIFT                              (2U)
#define GPMC_ECC2_RESULT_P4E_MASK                               (0x00000004U)

#define GPMC_ECC2_RESULT_P8E_SHIFT                              (3U)
#define GPMC_ECC2_RESULT_P8E_MASK                               (0x00000008U)

#define GPMC_ECC2_RESULT_P16E_SHIFT                             (4U)
#define GPMC_ECC2_RESULT_P16E_MASK                              (0x00000010U)

#define GPMC_ECC2_RESULT_P32E_SHIFT                             (5U)
#define GPMC_ECC2_RESULT_P32E_MASK                              (0x00000020U)

#define GPMC_ECC2_RESULT_P64E_SHIFT                             (6U)
#define GPMC_ECC2_RESULT_P64E_MASK                              (0x00000040U)

#define GPMC_ECC2_RESULT_P128E_SHIFT                            (7U)
#define GPMC_ECC2_RESULT_P128E_MASK                             (0x00000080U)

#define GPMC_ECC2_RESULT_P256E_SHIFT                            (8U)
#define GPMC_ECC2_RESULT_P256E_MASK                             (0x00000100U)

#define GPMC_ECC2_RESULT_P512E_SHIFT                            (9U)
#define GPMC_ECC2_RESULT_P512E_MASK                             (0x00000200U)

#define GPMC_ECC2_RESULT_P1024E_SHIFT                           (10U)
#define GPMC_ECC2_RESULT_P1024E_MASK                            (0x00000400U)

#define GPMC_ECC2_RESULT_P2048E_SHIFT                           (11U)
#define GPMC_ECC2_RESULT_P2048E_MASK                            (0x00000800U)

#define GPMC_ECC2_RESULT_P1O_SHIFT                              (16U)
#define GPMC_ECC2_RESULT_P1O_MASK                               (0x00010000U)

#define GPMC_ECC2_RESULT_P2O_SHIFT                              (17U)
#define GPMC_ECC2_RESULT_P2O_MASK                               (0x00020000U)

#define GPMC_ECC2_RESULT_P4O_SHIFT                              (18U)
#define GPMC_ECC2_RESULT_P4O_MASK                               (0x00040000U)

#define GPMC_ECC2_RESULT_P8O_SHIFT                              (19U)
#define GPMC_ECC2_RESULT_P8O_MASK                               (0x00080000U)

#define GPMC_ECC2_RESULT_P16O_SHIFT                             (20U)
#define GPMC_ECC2_RESULT_P16O_MASK                              (0x00100000U)

#define GPMC_ECC2_RESULT_P32O_SHIFT                             (21U)
#define GPMC_ECC2_RESULT_P32O_MASK                              (0x00200000U)

#define GPMC_ECC2_RESULT_P64O_SHIFT                             (22U)
#define GPMC_ECC2_RESULT_P64O_MASK                              (0x00400000U)

#define GPMC_ECC2_RESULT_P128O_SHIFT                            (23U)
#define GPMC_ECC2_RESULT_P128O_MASK                             (0x00800000U)

#define GPMC_ECC2_RESULT_P256O_SHIFT                            (24U)
#define GPMC_ECC2_RESULT_P256O_MASK                             (0x01000000U)

#define GPMC_ECC2_RESULT_P512O_SHIFT                            (25U)
#define GPMC_ECC2_RESULT_P512O_MASK                             (0x02000000U)

#define GPMC_ECC2_RESULT_P1024O_SHIFT                           (26U)
#define GPMC_ECC2_RESULT_P1024O_MASK                            (0x04000000U)

#define GPMC_ECC2_RESULT_P2048O_SHIFT                           (27U)
#define GPMC_ECC2_RESULT_P2048O_MASK                            (0x08000000U)

#define GPMC_BCH_RESULT6_4_SHIFT                                (0U)
#define GPMC_BCH_RESULT6_4_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT0_4_SHIFT                                (0U)
#define GPMC_BCH_RESULT0_4_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT1_6_SHIFT                                (0U)
#define GPMC_BCH_RESULT1_6_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT3_0_SHIFT                                (0U)
#define GPMC_BCH_RESULT3_0_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT0_2_SHIFT                                (0U)
#define GPMC_BCH_RESULT0_2_MASK                                 (0xffffffffU)

#define GPMC_ECC5_RESULT_P1E_SHIFT                              (0U)
#define GPMC_ECC5_RESULT_P1E_MASK                               (0x00000001U)

#define GPMC_ECC5_RESULT_P2E_SHIFT                              (1U)
#define GPMC_ECC5_RESULT_P2E_MASK                               (0x00000002U)

#define GPMC_ECC5_RESULT_P4E_SHIFT                              (2U)
#define GPMC_ECC5_RESULT_P4E_MASK                               (0x00000004U)

#define GPMC_ECC5_RESULT_P8E_SHIFT                              (3U)
#define GPMC_ECC5_RESULT_P8E_MASK                               (0x00000008U)

#define GPMC_ECC5_RESULT_P16E_SHIFT                             (4U)
#define GPMC_ECC5_RESULT_P16E_MASK                              (0x00000010U)

#define GPMC_ECC5_RESULT_P32E_SHIFT                             (5U)
#define GPMC_ECC5_RESULT_P32E_MASK                              (0x00000020U)

#define GPMC_ECC5_RESULT_P64E_SHIFT                             (6U)
#define GPMC_ECC5_RESULT_P64E_MASK                              (0x00000040U)

#define GPMC_ECC5_RESULT_P128E_SHIFT                            (7U)
#define GPMC_ECC5_RESULT_P128E_MASK                             (0x00000080U)

#define GPMC_ECC5_RESULT_P256E_SHIFT                            (8U)
#define GPMC_ECC5_RESULT_P256E_MASK                             (0x00000100U)

#define GPMC_ECC5_RESULT_P512E_SHIFT                            (9U)
#define GPMC_ECC5_RESULT_P512E_MASK                             (0x00000200U)

#define GPMC_ECC5_RESULT_P1024E_SHIFT                           (10U)
#define GPMC_ECC5_RESULT_P1024E_MASK                            (0x00000400U)

#define GPMC_ECC5_RESULT_P2048E_SHIFT                           (11U)
#define GPMC_ECC5_RESULT_P2048E_MASK                            (0x00000800U)

#define GPMC_ECC5_RESULT_P1O_SHIFT                              (16U)
#define GPMC_ECC5_RESULT_P1O_MASK                               (0x00010000U)

#define GPMC_ECC5_RESULT_P2O_SHIFT                              (17U)
#define GPMC_ECC5_RESULT_P2O_MASK                               (0x00020000U)

#define GPMC_ECC5_RESULT_P4O_SHIFT                              (18U)
#define GPMC_ECC5_RESULT_P4O_MASK                               (0x00040000U)

#define GPMC_ECC5_RESULT_P8O_SHIFT                              (19U)
#define GPMC_ECC5_RESULT_P8O_MASK                               (0x00080000U)

#define GPMC_ECC5_RESULT_P16O_SHIFT                             (20U)
#define GPMC_ECC5_RESULT_P16O_MASK                              (0x00100000U)

#define GPMC_ECC5_RESULT_P32O_SHIFT                             (21U)
#define GPMC_ECC5_RESULT_P32O_MASK                              (0x00200000U)

#define GPMC_ECC5_RESULT_P64O_SHIFT                             (22U)
#define GPMC_ECC5_RESULT_P64O_MASK                              (0x00400000U)

#define GPMC_ECC5_RESULT_P128O_SHIFT                            (23U)
#define GPMC_ECC5_RESULT_P128O_MASK                             (0x00800000U)

#define GPMC_ECC5_RESULT_P256O_SHIFT                            (24U)
#define GPMC_ECC5_RESULT_P256O_MASK                             (0x01000000U)

#define GPMC_ECC5_RESULT_P512O_SHIFT                            (25U)
#define GPMC_ECC5_RESULT_P512O_MASK                             (0x02000000U)

#define GPMC_ECC5_RESULT_P1024O_SHIFT                           (26U)
#define GPMC_ECC5_RESULT_P1024O_MASK                            (0x04000000U)

#define GPMC_ECC5_RESULT_P2048O_SHIFT                           (27U)
#define GPMC_ECC5_RESULT_P2048O_MASK                            (0x08000000U)

#define GPMC_BCH_RESULT3_2_SHIFT                                (0U)
#define GPMC_BCH_RESULT3_2_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT4_3_SHIFT                                (0U)
#define GPMC_BCH_RESULT4_3_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT1_4_SHIFT                                (0U)
#define GPMC_BCH_RESULT1_4_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT2_4_SHIFT                                (0U)
#define GPMC_BCH_RESULT2_4_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT3_4_SHIFT                                (0U)
#define GPMC_BCH_RESULT3_4_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT2_3_SHIFT                                (0U)
#define GPMC_BCH_RESULT2_3_MASK                                 (0xffffffffU)

#define GPMC_ECC4_RESULT_P1E_SHIFT                              (0U)
#define GPMC_ECC4_RESULT_P1E_MASK                               (0x00000001U)

#define GPMC_ECC4_RESULT_P2E_SHIFT                              (1U)
#define GPMC_ECC4_RESULT_P2E_MASK                               (0x00000002U)

#define GPMC_ECC4_RESULT_P4E_SHIFT                              (2U)
#define GPMC_ECC4_RESULT_P4E_MASK                               (0x00000004U)

#define GPMC_ECC4_RESULT_P8E_SHIFT                              (3U)
#define GPMC_ECC4_RESULT_P8E_MASK                               (0x00000008U)

#define GPMC_ECC4_RESULT_P16E_SHIFT                             (4U)
#define GPMC_ECC4_RESULT_P16E_MASK                              (0x00000010U)

#define GPMC_ECC4_RESULT_P32E_SHIFT                             (5U)
#define GPMC_ECC4_RESULT_P32E_MASK                              (0x00000020U)

#define GPMC_ECC4_RESULT_P64E_SHIFT                             (6U)
#define GPMC_ECC4_RESULT_P64E_MASK                              (0x00000040U)

#define GPMC_ECC4_RESULT_P128E_SHIFT                            (7U)
#define GPMC_ECC4_RESULT_P128E_MASK                             (0x00000080U)

#define GPMC_ECC4_RESULT_P256E_SHIFT                            (8U)
#define GPMC_ECC4_RESULT_P256E_MASK                             (0x00000100U)

#define GPMC_ECC4_RESULT_P512E_SHIFT                            (9U)
#define GPMC_ECC4_RESULT_P512E_MASK                             (0x00000200U)

#define GPMC_ECC4_RESULT_P1024E_SHIFT                           (10U)
#define GPMC_ECC4_RESULT_P1024E_MASK                            (0x00000400U)

#define GPMC_ECC4_RESULT_P2048E_SHIFT                           (11U)
#define GPMC_ECC4_RESULT_P2048E_MASK                            (0x00000800U)

#define GPMC_ECC4_RESULT_P1O_SHIFT                              (16U)
#define GPMC_ECC4_RESULT_P1O_MASK                               (0x00010000U)

#define GPMC_ECC4_RESULT_P2O_SHIFT                              (17U)
#define GPMC_ECC4_RESULT_P2O_MASK                               (0x00020000U)

#define GPMC_ECC4_RESULT_P4O_SHIFT                              (18U)
#define GPMC_ECC4_RESULT_P4O_MASK                               (0x00040000U)

#define GPMC_ECC4_RESULT_P8O_SHIFT                              (19U)
#define GPMC_ECC4_RESULT_P8O_MASK                               (0x00080000U)

#define GPMC_ECC4_RESULT_P16O_SHIFT                             (20U)
#define GPMC_ECC4_RESULT_P16O_MASK                              (0x00100000U)

#define GPMC_ECC4_RESULT_P32O_SHIFT                             (21U)
#define GPMC_ECC4_RESULT_P32O_MASK                              (0x00200000U)

#define GPMC_ECC4_RESULT_P64O_SHIFT                             (22U)
#define GPMC_ECC4_RESULT_P64O_MASK                              (0x00400000U)

#define GPMC_ECC4_RESULT_P128O_SHIFT                            (23U)
#define GPMC_ECC4_RESULT_P128O_MASK                             (0x00800000U)

#define GPMC_ECC4_RESULT_P256O_SHIFT                            (24U)
#define GPMC_ECC4_RESULT_P256O_MASK                             (0x01000000U)

#define GPMC_ECC4_RESULT_P512O_SHIFT                            (25U)
#define GPMC_ECC4_RESULT_P512O_MASK                             (0x02000000U)

#define GPMC_ECC4_RESULT_P1024O_SHIFT                           (26U)
#define GPMC_ECC4_RESULT_P1024O_MASK                            (0x04000000U)

#define GPMC_ECC4_RESULT_P2048O_SHIFT                           (27U)
#define GPMC_ECC4_RESULT_P2048O_MASK                            (0x08000000U)

#define GPMC_BCH_RESULT2_6_SHIFT                                (0U)
#define GPMC_BCH_RESULT2_6_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT5_1_SHIFT                                (0U)
#define GPMC_BCH_RESULT5_1_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT1_3_SHIFT                                (0U)
#define GPMC_BCH_RESULT1_3_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT1_1_SHIFT                                (0U)
#define GPMC_BCH_RESULT1_1_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT5_5_SHIFT                                (0U)
#define GPMC_BCH_RESULT5_5_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT2_0_SHIFT                                (0U)
#define GPMC_BCH_RESULT2_0_MASK                                 (0xffffffffU)

#define GPMC_BCH_RESULT6_2_SHIFT                                (0U)
#define GPMC_BCH_RESULT6_2_MASK                                 (0xffffffffU)

#ifdef __cplusplus
}
#endif

#endif /* HW_GPMC_H_ */

