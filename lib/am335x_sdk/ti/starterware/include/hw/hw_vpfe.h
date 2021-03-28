/*
* hw_vpfe.h
*
* Register-level header file for VPFE
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
#ifndef HW_VPFE_H_
#define HW_VPFE_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define VPFE_REVISION                                           (0x0U)
#define VPFE_PCR                                                (0x4U)
#define VPFE_SYNMODE                                            (0x8U)
#define VPFE_HD_VD_WID                                          (0xcU)
#define VPFE_PIX_LINES                                          (0x10U)
#define VPFE_HORZ_INFO                                          (0x14U)
#define VPFE_VERT_START                                         (0x18U)
#define VPFE_VERT_LINES                                         (0x1cU)
#define VPFE_CULLING                                            (0x20U)
#define VPFE_HSIZE_OFF                                          (0x24U)
#define VPFE_SDOFST                                             (0x28U)
#define VPFE_SDR_ADDR                                           (0x2cU)
#define VPFE_CLAMP                                              (0x30U)
#define VPFE_DCSUB                                              (0x34U)
#define VPFE_COLPTN                                             (0x38U)
#define VPFE_BLKCMP                                             (0x3cU)
#define VPFE_VDINT                                              (0x48U)
#define VPFE_ALAW                                               (0x4cU)
#define VPFE_REC656IF                                           (0x50U)
#define VPFE_CCDCFG                                             (0x54U)
#define VPFE_DMA_CNTL                                           (0x98U)
#define VPFE_SYSCONFIG                                          (0x104U)
#define VPFE_CONFIG                                             (0x108U)
#define VPFE_IRQ_EOI                                            (0x110U)
#define VPFE_IRQ_STS_RAW                                        (0x114U)
#define VPFE_IRQ_STS                                            (0x118U)
#define VPFE_IRQ_EN_SET                                         (0x11cU)
#define VPFE_IRQ_EN_CLR                                         (0x120U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define VPFE_REVISION_Y_MINOR_SHIFT                             (0U)
#define VPFE_REVISION_Y_MINOR_MASK                              (0x0000003fU)

#define VPFE_REVISION_CUSTOM_SHIFT                              (6U)
#define VPFE_REVISION_CUSTOM_MASK                               (0x000000c0U)

#define VPFE_REVISION_X_MAJOR_SHIFT                             (8U)
#define VPFE_REVISION_X_MAJOR_MASK                              (0x00000700U)

#define VPFE_REVISION_R_RTL_SHIFT                               (11U)
#define VPFE_REVISION_R_RTL_MASK                                (0x0000f800U)

#define VPFE_REVISION_FUNC_SHIFT                                (16U)
#define VPFE_REVISION_FUNC_MASK                                 (0x0fff0000U)

#define VPFE_REVISION_SCHEME_SHIFT                              (30U)
#define VPFE_REVISION_SCHEME_MASK                               (0xc0000000U)

#define VPFE_PCR_EN_SHIFT                                       (0U)
#define VPFE_PCR_EN_MASK                                        (0x00000001U)
#define VPFE_PCR_EN_DISABLE                                      (0U)
#define VPFE_PCR_EN_ENABLE                                       (1U)

#define VPFE_PCR_BUSY_SHIFT                                     (1U)
#define VPFE_PCR_BUSY_MASK                                      (0x00000002U)
#define VPFE_PCR_BUSY_NOT                                        (0U)
#define VPFE_PCR_BUSY                                            (1U)

#define VPFE_PCR_PG_EN_SHIFT                                    (2U)
#define VPFE_PCR_PG_EN_MASK                                     (0x00000004U)
#define VPFE_PCR_PG_EN_DISABLE                                   (0U)
#define VPFE_PCR_PG_EN_ENABLE                                    (1U)

#define VPFE_PCR_EXPG_EN_SHIFT                                  (3U)
#define VPFE_PCR_EXPG_EN_MASK                                   (0x00000008U)
#define VPFE_PCR_EXPG_EN_DISABLE                                 (0U)
#define VPFE_PCR_EXPG_EN_ENABLE                                  (1U)

#define VPFE_SYNMODE_VDHDOUT_SHIFT                              (0U)
#define VPFE_SYNMODE_VDHDOUT_MASK                               (0x00000001U)
#define VPFE_SYNMODE_VDHDOUT_INPUT                               (0U)
#define VPFE_SYNMODE_VDHDOUT_OUTPUT                              (1U)

#define VPFE_SYNMODE_FLDOUT_SHIFT                               (1U)
#define VPFE_SYNMODE_FLDOUT_MASK                                (0x00000002U)
#define VPFE_SYNMODE_FLDOUT_INPUT                                (0U)
#define VPFE_SYNMODE_FLDOUT_OUTPUT                               (1U)

#define VPFE_SYNMODE_VDPOL_SHIFT                                (2U)
#define VPFE_SYNMODE_VDPOL_MASK                                 (0x00000004U)
#define VPFE_SYNMODE_VDPOL_POSITIVE                              (0U)
#define VPFE_SYNMODE_VDPOL_NEGATIVE                              (1U)

#define VPFE_SYNMODE_HDPOL_SHIFT                                (3U)
#define VPFE_SYNMODE_HDPOL_MASK                                 (0x00000008U)
#define VPFE_SYNMODE_HDPOL_POSITIVE                              (0U)
#define VPFE_SYNMODE_HDPOL_NEGATIVE                              (1U)

#define VPFE_SYNMODE_FLDPOL_SHIFT                               (4U)
#define VPFE_SYNMODE_FLDPOL_MASK                                (0x00000010U)
#define VPFE_SYNMODE_FLDPOL_POSITIVE                             (0U)
#define VPFE_SYNMODE_FLDPOL_NEGATIVE                             (1U)

#define VPFE_SYNMODE_EXWEN_SHIFT                                (5U)
#define VPFE_SYNMODE_EXWEN_MASK                                 (0x00000020U)
#define VPFE_SYNMODE_EXWEN_NOT_EX                                (0U)
#define VPFE_SYNMODE_EXWEN_EX                                    (1U)

#define VPFE_SYNMODE_DATAPOL_SHIFT                              (6U)
#define VPFE_SYNMODE_DATAPOL_MASK                               (0x00000040U)
#define VPFE_SYNMODE_DATAPOL_NORMAL                              (0U)
#define VPFE_SYNMODE_DATAPOL_ONES_COMPLEMENT                     (1U)

#define VPFE_SYNMODE_FLDMODE_SHIFT                              (7U)
#define VPFE_SYNMODE_FLDMODE_MASK                               (0x00000080U)
#define VPFE_SYNMODE_FLDMODE_NON_INTERLACED                      (0U)
#define VPFE_SYNMODE_FLDMODE_INTERLACED                          (1U)

#define VPFE_SYNMODE_DATSIZ_SHIFT                               (8U)
#define VPFE_SYNMODE_DATSIZ_MASK                                (0x00000700U)
#define VPFE_SYNMODE_DATSIZ_B16                                  (0U)
#define VPFE_SYNMODE_DATSIZ_B15                                  (1U)
#define VPFE_SYNMODE_DATSIZ_B14                                  (2U)
#define VPFE_SYNMODE_DATSIZ_B13                                  (3U)
#define VPFE_SYNMODE_DATSIZ_B12                                  (4U)
#define VPFE_SYNMODE_DATSIZ_B11                                  (5U)
#define VPFE_SYNMODE_DATSIZ_B10                                  (6U)
#define VPFE_SYNMODE_DATSIZ_B8                                   (7U)

#define VPFE_SYNMODE_PACK8_SHIFT                                (11U)
#define VPFE_SYNMODE_PACK8_MASK                                 (0x00000800U)
#define VPFE_SYNMODE_PACK8_NORMAL                                (0U)
#define VPFE_SYNMODE_PACK8                                       (1U)

#define VPFE_SYNMODE_INPMOD_SHIFT                               (12U)
#define VPFE_SYNMODE_INPMOD_MASK                                (0x00003000U)
#define VPFE_SYNMODE_INPMOD_CCD_RAW                              (0U)
#define VPFE_SYNMODE_INPMOD_YCBCR16                              (1U)
#define VPFE_SYNMODE_INPMOD_YCBCR8                               (2U)
#define VPFE_SYNMODE_INPMOD_RESERVED                             (3U)

#define VPFE_SYNMODE_LPF_SHIFT                                  (14U)
#define VPFE_SYNMODE_LPF_MASK                                   (0x00004000U)
#define VPFE_SYNMODE_LPF_OFF                                     (0U)
#define VPFE_SYNMODE_LPF_ON                                      (1U)

#define VPFE_SYNMODE_FLDSTAT_SHIFT                              (15U)
#define VPFE_SYNMODE_FLDSTAT_MASK                               (0x00008000U)
#define VPFE_SYNMODE_FLDSTAT_ODD                                 (0U)
#define VPFE_SYNMODE_FLDSTAT_EVEN                                (1U)

#define VPFE_SYNMODE_VDHDEN_SHIFT                               (16U)
#define VPFE_SYNMODE_VDHDEN_MASK                                (0x00010000U)
#define VPFE_SYNMODE_VDHDEN_DISABLE                              (0U)
#define VPFE_SYNMODE_VDHDEN_ENABLE                               (1U)

#define VPFE_SYNMODE_WEN_SHIFT                                  (17U)
#define VPFE_SYNMODE_WEN_MASK                                   (0x00020000U)
#define VPFE_SYNMODE_WEN_DISABLE                                 (0U)
#define VPFE_SYNMODE_WEN_ENABLE                                  (1U)

#define VPFE_HD_VD_WID_VDW_SHIFT                                (0U)
#define VPFE_HD_VD_WID_VDW_MASK                                 (0x00000fffU)

#define VPFE_HD_VD_WID_HDW_SHIFT                                (16U)
#define VPFE_HD_VD_WID_HDW_MASK                                 (0x0fff0000U)

#define VPFE_PIX_LINES_HLPFR_SHIFT                              (0U)
#define VPFE_PIX_LINES_HLPFR_MASK                               (0x0000ffffU)

#define VPFE_PIX_LINES_PPLN_SHIFT                               (16U)
#define VPFE_PIX_LINES_PPLN_MASK                                (0xffff0000U)

#define VPFE_HORZ_INFO_NPH_SHIFT                                (0U)
#define VPFE_HORZ_INFO_NPH_MASK                                 (0x00007fffU)

#define VPFE_HORZ_INFO_SPH_SHIFT                                (16U)
#define VPFE_HORZ_INFO_SPH_MASK                                 (0x7fff0000U)

#define VPFE_VERT_START_SLV1_SHIFT                              (0U)
#define VPFE_VERT_START_SLV1_MASK                               (0x00007fffU)

#define VPFE_VERT_START_SLV0_SHIFT                              (16U)
#define VPFE_VERT_START_SLV0_MASK                               (0x7fff0000U)

#define VPFE_VERT_LINES_NLV_SHIFT                               (0U)
#define VPFE_VERT_LINES_NLV_MASK                                (0x00007fffU)

#define VPFE_CULLING_CULV_SHIFT                                 (0U)
#define VPFE_CULLING_CULV_MASK                                  (0x000000ffU)
#define VPFE_CULLING_CULV                                        (0U)
#define VPFE_CULLING_CULV_RETAIN                                 (1U)

#define VPFE_CULLING_CULHODD_SHIFT                              (16U)
#define VPFE_CULLING_CULHODD_MASK                               (0x00ff0000U)
#define VPFE_CULLING_CULHODD                                     (0U)
#define VPFE_CULLING_CULHODD_RETAIN                              (1U)

#define VPFE_CULLING_CULHEVN_SHIFT                              (24U)
#define VPFE_CULLING_CULHEVN_MASK                               (0xff000000U)
#define VPFE_CULLING_CULHEVN                                     (0U)
#define VPFE_CULLING_CULHEVN_RETAIN                              (1U)

#define VPFE_HSIZE_OFF_LNOFST_SHIFT                             (0U)
#define VPFE_HSIZE_OFF_LNOFST_MASK                              (0x0000ffffU)

#define VPFE_SDOFST_LOFTS3_SHIFT                                (0U)
#define VPFE_SDOFST_LOFTS3_MASK                                 (0x00000007U)
#define VPFE_SDOFST_LOFTS3_PLUS_L1                               (0U)
#define VPFE_SDOFST_LOFTS3_PLUS_L2                               (1U)
#define VPFE_SDOFST_LOFTS3_PLUS_L3                               (2U)
#define VPFE_SDOFST_LOFTS3_PLUS_L4                               (3U)
#define VPFE_SDOFST_LOFTS3_MINUS_L1                              (4U)
#define VPFE_SDOFST_LOFTS3_MINUS_L2                              (5U)
#define VPFE_SDOFST_LOFTS3_MINUS_L3                              (6U)
#define VPFE_SDOFST_LOFTS3_MINUS_L4                              (7U)

#define VPFE_SDOFST_LOFTS2_SHIFT                                (3U)
#define VPFE_SDOFST_LOFTS2_MASK                                 (0x00000038U)
#define VPFE_SDOFST_LOFTS2_PLUS_L1                               (0U)
#define VPFE_SDOFST_LOFTS2_PLUS_L2                               (1U)
#define VPFE_SDOFST_LOFTS2_PLUS_L3                               (2U)
#define VPFE_SDOFST_LOFTS2_PLUS_L4                               (3U)
#define VPFE_SDOFST_LOFTS2_MINUS_L1                              (4U)
#define VPFE_SDOFST_LOFTS2_MINUS_L2                              (5U)
#define VPFE_SDOFST_LOFTS2_MINUS_L3                              (6U)
#define VPFE_SDOFST_LOFTS2_MINUS_L4                              (7U)

#define VPFE_SDOFST_LOFTS1_SHIFT                                (6U)
#define VPFE_SDOFST_LOFTS1_MASK                                 (0x000001c0U)
#define VPFE_SDOFST_LOFTS1_PLUS_L1                               (0U)
#define VPFE_SDOFST_LOFTS1_PLUS_L2                               (1U)
#define VPFE_SDOFST_LOFTS1_PLUS_L3                               (2U)
#define VPFE_SDOFST_LOFTS1_PLUS_L4                               (3U)
#define VPFE_SDOFST_LOFTS1_MINUS_L1                              (4U)
#define VPFE_SDOFST_LOFTS1_MINUS_L2                              (5U)
#define VPFE_SDOFST_LOFTS1_MINUS_L3                              (6U)
#define VPFE_SDOFST_LOFTS1_MINUS_L4                              (7U)

#define VPFE_SDOFST_LOFTS0_SHIFT                                (9U)
#define VPFE_SDOFST_LOFTS0_MASK                                 (0x00000e00U)
#define VPFE_SDOFST_LOFTS0_PLUS_L1                               (0U)
#define VPFE_SDOFST_LOFTS0_PLUS_L2                               (1U)
#define VPFE_SDOFST_LOFTS0_PLUS_L3                               (2U)
#define VPFE_SDOFST_LOFTS0_PLUS_L4                               (3U)
#define VPFE_SDOFST_LOFTS0_MINUS_L1                              (4U)
#define VPFE_SDOFST_LOFTS0_MINUS_L2                              (5U)
#define VPFE_SDOFST_LOFTS0_MINUS_L3                              (6U)
#define VPFE_SDOFST_LOFTS0_MINUS_L4                              (7U)

#define VPFE_SDOFST_FOFST_SHIFT                                 (12U)
#define VPFE_SDOFST_FOFST_MASK                                  (0x00003000U)
#define VPFE_SDOFST_FOFST_PLUS_L1                                (0U)
#define VPFE_SDOFST_FOFST_PLUS_L2                                (1U)
#define VPFE_SDOFST_FOFST_PLUS_L3                                (2U)
#define VPFE_SDOFST_FOFST_PLUS_L4                                (3U)

#define VPFE_SDOFST_FIINV_SHIFT                                 (14U)
#define VPFE_SDOFST_FIINV_MASK                                  (0x00004000U)
#define VPFE_SDOFST_FIINV_NONINVERSE                             (0U)
#define VPFE_SDOFST_FIINV_INVERSE                                (1U)

#define VPFE_SDR_ADDR_ADR_SHIFT                                 (0U)
#define VPFE_SDR_ADDR_ADR_MASK                                  (0xffffffffU)

#define VPFE_CLAMP_OBGAIN_SHIFT                                 (0U)
#define VPFE_CLAMP_OBGAIN_MASK                                  (0x0000001fU)

#define VPFE_CLAMP_OBST_SHIFT                                   (10U)
#define VPFE_CLAMP_OBST_MASK                                    (0x01fffc00U)

#define VPFE_CLAMP_OBSLN_SHIFT                                  (25U)
#define VPFE_CLAMP_OBSLN_MASK                                   (0x0e000000U)
#define VPFE_CLAMP_OBSLN_LINE1                                   (0U)
#define VPFE_CLAMP_OBSLN_LINE2                                   (1U)
#define VPFE_CLAMP_OBSLN_LINE4                                   (2U)
#define VPFE_CLAMP_OBSLN_LINE8                                   (3U)
#define VPFE_CLAMP_OBSLN_LINE16                                  (4U)
#define VPFE_CLAMP_OBSLN_RESERVED1                               (5U)
#define VPFE_CLAMP_OBSLN_RESERVED2                               (6U)
#define VPFE_CLAMP_OBSLN_RESERVED3                               (7U)

#define VPFE_CLAMP_OBSLEN_SHIFT                                 (28U)
#define VPFE_CLAMP_OBSLEN_MASK                                  (0x70000000U)
#define VPFE_CLAMP_OBSLEN_PIXEL1                                 (0U)
#define VPFE_CLAMP_OBSLEN_PIXEL2                                 (1U)
#define VPFE_CLAMP_OBSLEN_PIXEL4                                 (2U)
#define VPFE_CLAMP_OBSLEN_PIXEL8                                 (3U)
#define VPFE_CLAMP_OBSLEN_PIXEL16                                (4U)
#define VPFE_CLAMP_OBSLEN_RESERVED1                              (5U)
#define VPFE_CLAMP_OBSLEN_RESERVED2                              (6U)
#define VPFE_CLAMP_OBSLEN_RESERVED3                              (7U)

#define VPFE_CLAMP_CLAMPEN_SHIFT                                (31U)
#define VPFE_CLAMP_CLAMPEN_MASK                                 (0x80000000U)
#define VPFE_CLAMP_CLAMPEN_DISABLE                               (0U)
#define VPFE_CLAMP_CLAMPEN_ENABLE                                (1U)

#define VPFE_DCSUB_SHIFT                                        (0U)
#define VPFE_DCSUB_MASK                                         (0x00003fffU)

#define VPFE_COLPTN_CP0LPC0_SHIFT                               (0U)
#define VPFE_COLPTN_CP0LPC0_MASK                                (0x00000003U)
#define VPFE_COLPTN_CP0LPC0_RYE                                  (0U)
#define VPFE_COLPTN_CP0LPC0_GRCY                                 (1U)
#define VPFE_COLPTN_CP0LPC0_GBG                                  (2U)
#define VPFE_COLPTN_CP0LPC0_BMG                                  (3U)

#define VPFE_COLPTN_CP0LPC1_SHIFT                               (2U)
#define VPFE_COLPTN_CP0LPC1_MASK                                (0x0000000cU)
#define VPFE_COLPTN_CP0LPC1_RYE                                  (0U)
#define VPFE_COLPTN_CP0LPC1_GRCY                                 (1U)
#define VPFE_COLPTN_CP0LPC1_GBG                                  (2U)
#define VPFE_COLPTN_CP0LPC1_BMG                                  (3U)

#define VPFE_COLPTN_CP0LPC2_SHIFT                               (4U)
#define VPFE_COLPTN_CP0LPC2_MASK                                (0x00000030U)
#define VPFE_COLPTN_CP0LPC2_RYE                                  (0U)
#define VPFE_COLPTN_CP0LPC2_GRCY                                 (1U)
#define VPFE_COLPTN_CP0LPC2_GBG                                  (2U)
#define VPFE_COLPTN_CP0LPC2_BMG                                  (3U)

#define VPFE_COLPTN_CP0LPC3_SHIFT                               (6U)
#define VPFE_COLPTN_CP0LPC3_MASK                                (0x000000c0U)
#define VPFE_COLPTN_CP0LPC3_RYE                                  (0U)
#define VPFE_COLPTN_CP0LPC3_GRCY                                 (1U)
#define VPFE_COLPTN_CP0LPC3_GBG                                  (2U)
#define VPFE_COLPTN_CP0LPC3_BMG                                  (3U)

#define VPFE_COLPTN_CP1LPC0_SHIFT                               (8U)
#define VPFE_COLPTN_CP1LPC0_MASK                                (0x00000300U)
#define VPFE_COLPTN_CP1LPC0_RYE                                  (0U)
#define VPFE_COLPTN_CP1LPC0_GRCY                                 (1U)
#define VPFE_COLPTN_CP1LPC0_GBG                                  (2U)
#define VPFE_COLPTN_CP1LPC0_BMG                                  (3U)

#define VPFE_COLPTN_CP1LPC1_SHIFT                               (10U)
#define VPFE_COLPTN_CP1LPC1_MASK                                (0x00000c00U)
#define VPFE_COLPTN_CP1LPC1_RYE                                  (0U)
#define VPFE_COLPTN_CP1LPC1_GRCY                                 (1U)
#define VPFE_COLPTN_CP1LPC1_GBG                                  (2U)
#define VPFE_COLPTN_CP1LPC1_BMG                                  (3U)

#define VPFE_COLPTN_CP1LPC2_SHIFT                               (12U)
#define VPFE_COLPTN_CP1LPC2_MASK                                (0x00003000U)
#define VPFE_COLPTN_CP1LPC2_RYE                                  (0U)
#define VPFE_COLPTN_CP1LPC2_GRCY                                 (1U)
#define VPFE_COLPTN_CP1LPC2_GBG                                  (2U)
#define VPFE_COLPTN_CP1LPC2_BMG                                  (3U)

#define VPFE_COLPTN_CP1LPC3_SHIFT                               (14U)
#define VPFE_COLPTN_CP1LPC3_MASK                                (0x0000c000U)
#define VPFE_COLPTN_CP1LPC3_RYE                                  (0U)
#define VPFE_COLPTN_CP1LPC3_GRCY                                 (1U)
#define VPFE_COLPTN_CP1LPC3_GBG                                  (2U)
#define VPFE_COLPTN_CP1LPC3_BMG                                  (3U)

#define VPFE_COLPTN_CP2LPC0_SHIFT                               (16U)
#define VPFE_COLPTN_CP2LPC0_MASK                                (0x00030000U)
#define VPFE_COLPTN_CP2LPC0_RYE                                  (0U)
#define VPFE_COLPTN_CP2LPC0_GRCY                                 (1U)
#define VPFE_COLPTN_CP2LPC0_GBG                                  (2U)
#define VPFE_COLPTN_CP2LPC0_BMG                                  (3U)

#define VPFE_COLPTN_CP2LPC1_SHIFT                               (18U)
#define VPFE_COLPTN_CP2LPC1_MASK                                (0x000c0000U)
#define VPFE_COLPTN_CP2LPC1_RYE                                  (0U)
#define VPFE_COLPTN_CP2LPC1_GRCY                                 (1U)
#define VPFE_COLPTN_CP2LPC1_GBG                                  (2U)
#define VPFE_COLPTN_CP2LPC1_BMG                                  (3U)

#define VPFE_COLPTN_CP2LPC2_SHIFT                               (20U)
#define VPFE_COLPTN_CP2LPC2_MASK                                (0x00300000U)
#define VPFE_COLPTN_CP2LPC2_RYE                                  (0U)
#define VPFE_COLPTN_CP2LPC2_GRCY                                 (1U)
#define VPFE_COLPTN_CP2LPC2_GBG                                  (2U)
#define VPFE_COLPTN_CP2LPC2_BMG                                  (3U)

#define VPFE_COLPTN_CP2LPC3_SHIFT                               (22U)
#define VPFE_COLPTN_CP2LPC3_MASK                                (0x00c00000U)
#define VPFE_COLPTN_CP2LPC3_RYE                                  (0U)
#define VPFE_COLPTN_CP2LPC3_GRCY                                 (1U)
#define VPFE_COLPTN_CP2LPC3_GBG                                  (2U)
#define VPFE_COLPTN_CP2LPC3_BMG                                  (3U)

#define VPFE_COLPTN_CP3LPC0_SHIFT                               (24U)
#define VPFE_COLPTN_CP3LPC0_MASK                                (0x03000000U)
#define VPFE_COLPTN_CP3LPC0_RYE                                  (0U)
#define VPFE_COLPTN_CP3LPC0_GRCY                                 (1U)
#define VPFE_COLPTN_CP3LPC0_GBG                                  (2U)
#define VPFE_COLPTN_CP3LPC0_BMG                                  (3U)

#define VPFE_COLPTN_CP3LPC1_SHIFT                               (26U)
#define VPFE_COLPTN_CP3LPC1_MASK                                (0x0c000000U)
#define VPFE_COLPTN_CP3LPC1_RYE                                  (0U)
#define VPFE_COLPTN_CP3LPC1_GRCY                                 (1U)
#define VPFE_COLPTN_CP3LPC1_GBG                                  (2U)
#define VPFE_COLPTN_CP3LPC1_BMG                                  (3U)

#define VPFE_COLPTN_CP3LPC2_SHIFT                               (28U)
#define VPFE_COLPTN_CP3LPC2_MASK                                (0x30000000U)
#define VPFE_COLPTN_CP3LPC2_RYE                                  (0U)
#define VPFE_COLPTN_CP3LPC2_GRCY                                 (1U)
#define VPFE_COLPTN_CP3LPC2_GBG                                  (2U)
#define VPFE_COLPTN_CP3LPC2_BMG                                  (3U)

#define VPFE_COLPTN_CP3LPC3_SHIFT                               (30U)
#define VPFE_COLPTN_CP3LPC3_MASK                                (0xc0000000U)
#define VPFE_COLPTN_CP3LPC3_RYE                                  (0U)
#define VPFE_COLPTN_CP3LPC3_GRCY                                 (1U)
#define VPFE_COLPTN_CP3LPC3_GBG                                  (2U)
#define VPFE_COLPTN_CP3LPC3_BMG                                  (3U)

#define VPFE_BLKCMP_BMG_SHIFT                                   (0U)
#define VPFE_BLKCMP_BMG_MASK                                    (0x000000ffU)

#define VPFE_BLKCMP_GBG_SHIFT                                   (8U)
#define VPFE_BLKCMP_GBG_MASK                                    (0x0000ff00U)

#define VPFE_BLKCMP_GRCY_SHIFT                                  (16U)
#define VPFE_BLKCMP_GRCY_MASK                                   (0x00ff0000U)

#define VPFE_BLKCMP_RYE_SHIFT                                   (24U)
#define VPFE_BLKCMP_RYE_MASK                                    (0xff000000U)

#define VPFE_VDINT_VDINT1_SHIFT                                 (0U)
#define VPFE_VDINT_VDINT1_MASK                                  (0x00007fffU)

#define VPFE_VDINT_VDINT0_SHIFT                                 (16U)
#define VPFE_VDINT_VDINT0_MASK                                  (0x7fff0000U)

#define VPFE_ALAW_GWDI_SHIFT                                    (0U)
#define VPFE_ALAW_GWDI_MASK                                     (0x00000007U)
#define VPFE_ALAW_GWDI_BITS15_6                                  (0U)
#define VPFE_ALAW_GWDI_BITS14_5                                  (1U)
#define VPFE_ALAW_GWDI_BITS13_4                                  (2U)
#define VPFE_ALAW_GWDI_BITS12_3                                  (3U)
#define VPFE_ALAW_GWDI_BITS11_2                                  (4U)
#define VPFE_ALAW_GWDI_BITS10_1                                  (5U)
#define VPFE_ALAW_GWDI_BITS9_0                                   (6U)

#define VPFE_ALAW_CCDTBL_SHIFT                                  (3U)
#define VPFE_ALAW_CCDTBL_MASK                                   (0x00000008U)
#define VPFE_ALAW_CCDTBL_DISABLE                                 (0U)
#define VPFE_ALAW_CCDTBL_ENABLE                                  (1U)

#define VPFE_REC656IF_R656ON_SHIFT                              (0U)
#define VPFE_REC656IF_R656ON_MASK                               (0x00000001U)
#define VPFE_REC656IF_R656ON_DISABLE                             (0U)
#define VPFE_REC656IF_R656ON_ENABLE                              (1U)

#define VPFE_REC656IF_ECCFVH_SHIFT                              (1U)
#define VPFE_REC656IF_ECCFVH_MASK                               (0x00000002U)
#define VPFE_REC656IF_ECCFVH_DISABLE                             (0U)
#define VPFE_REC656IF_ECCFVH_ENABLE                              (1U)

#define VPFE_CCDCFG_YCOUTSWP_SHIFT                              (2U)
#define VPFE_CCDCFG_YCOUTSWP_MASK                               (0x00000004U)

#define VPFE_CCDCFG_YCINSWP_SHIFT                               (4U)
#define VPFE_CCDCFG_YCINSWP_MASK                                (0x00000010U)

#define VPFE_CCDCFG_BW656_SHIFT                                 (5U)
#define VPFE_CCDCFG_BW656_MASK                                  (0x00000020U)
#define VPFE_CCDCFG_BW656_BITS8                                  (0U)
#define VPFE_CCDCFG_BW656_BITS10                                 (1U)

#define VPFE_CCDCFG_WENLOG_SHIFT                                (8U)
#define VPFE_CCDCFG_WENLOG_MASK                                 (0x00000100U)
#define VPFE_CCDCFG_WENLOG_AND                                   (0U)
#define VPFE_CCDCFG_WENLOG_OR                                    (1U)

#define VPFE_CCDCFG_Y8POS_SHIFT                                 (11U)
#define VPFE_CCDCFG_Y8POS_MASK                                  (0x00000800U)
#define VPFE_CCDCFG_Y8POS_EVEN                                   (0U)
#define VPFE_CCDCFG_Y8POS_ODD                                    (1U)

#define VPFE_CCDCFG_BSWD_SHIFT                                  (12U)
#define VPFE_CCDCFG_BSWD_MASK                                   (0x00001000U)
#define VPFE_CCDCFG_BSWD_NORMAL                                  (0U)
#define VPFE_CCDCFG_BSWD_SWAP                                    (1U)

#define VPFE_CCDCFG_MSBINVI_SHIFT                               (13U)
#define VPFE_CCDCFG_MSBINVI_MASK                                (0x00002000U)
#define VPFE_CCDCFG_MSBINVI_NORMAL                               (0U)
#define VPFE_CCDCFG_MSBINVI_MSB_INV                              (1U)

#define VPFE_CCDCFG_MSBINVO_SHIFT                               (14U)
#define VPFE_CCDCFG_MSBINVO_MASK                                (0x00004000U)
#define VPFE_CCDCFG_MSBINVO_NORMAL                               (0U)
#define VPFE_CCDCFG_MSBINVO_MSB_INV                              (1U)

#define VPFE_CCDCFG_VDLC_SHIFT                                  (15U)
#define VPFE_CCDCFG_VDLC_MASK                                   (0x00008000U)
#define VPFE_CCDCFG_VDLC_LATCHED                                 (0U)
#define VPFE_CCDCFG_VDLC_NOT_LATCHED                             (1U)

#define VPFE_DMA_CNTL_PRIORITY_SHIFT                            (0U)
#define VPFE_DMA_CNTL_PRIORITY_MASK                             (0x00000007U)

#define VPFE_DMA_CNTL_OVERFLOW_SHIFT                            (31U)
#define VPFE_DMA_CNTL_OVERFLOW_MASK                             (0x80000000U)
#define VPFE_DMA_CNTL_OVERFLOW_NOT_OCCURED                       (0U)
#define VPFE_DMA_CNTL_OVERFLOW_OCCURED                           (1U)

#define VPFE_SYSCONFIG_IDLEMODE_SHIFT                           (2U)
#define VPFE_SYSCONFIG_IDLEMODE_MASK                            (0x0000000cU)
#define VPFE_SYSCONFIG_IDLEMODE_FORCE_IDLE                       (0U)
#define VPFE_SYSCONFIG_IDLEMODE_NO_IDLE                          (1U)
#define VPFE_SYSCONFIG_IDLEMODE_SMART_IDLE                       (2U)
#define VPFE_SYSCONFIG_IDLEMODE_SMART_IDLE_WAKEUP_CAPABLE        (3U)

#define VPFE_SYSCONFIG_STANDBYMODE_SHIFT                        (4U)
#define VPFE_SYSCONFIG_STANDBYMODE_MASK                         (0x00000030U)
#define VPFE_SYSCONFIG_STANDBYMODE_FORCE_STANDBY                 (0U)
#define VPFE_SYSCONFIG_STANDBYMODE_NO_STANDBY                    (1U)
#define VPFE_SYSCONFIG_STANDBYMODE_SMART_STANDBY                 (2U)
#define VPFE_SYSCONFIG_STANDBYMODE_SMART_STANDBY_WAKEUP_CAPABLE  (3U)

#define VPFE_CONFIG_PCLK_INV_SHIFT                              (0U)
#define VPFE_CONFIG_PCLK_INV_MASK                               (0x00000001U)
#define VPFE_CONFIG_PCLK_INV_NOT                                 (0U)
#define VPFE_CONFIG_PCLK_INV                                     (1U)

#define VPFE_CONFIG_EN_SHIFT                                    (1U)
#define VPFE_CONFIG_EN_MASK                                     (0x00000002U)
#define VPFE_CONFIG_EN_DISABLE                                   (0U)
#define VPFE_CONFIG_EN_ENABLE                                    (1U)

#define VPFE_CONFIG_ST_SHIFT                                    (2U)
#define VPFE_CONFIG_ST_MASK                                     (0x00000004U)
#define VPFE_CONFIG_ST_OCP_ACTIVE                                (0U)
#define VPFE_CONFIG_ST_OCP_STANDBY                               (1U)

#define VPFE_IRQ_EOI_SHIFT                                      (0U)
#define VPFE_IRQ_EOI_MASK                                       (0x00000001U)

#define VPFE_IRQ_STS_RAW_VD0_INT_SHIFT                          (0U)
#define VPFE_IRQ_STS_RAW_VD0_INT_MASK                           (0x00000001U)

#define VPFE_IRQ_STS_RAW_VD1_INT_SHIFT                          (1U)
#define VPFE_IRQ_STS_RAW_VD1_INT_MASK                           (0x00000002U)

#define VPFE_IRQ_STS_RAW_VD2_INT_SHIFT                          (2U)
#define VPFE_IRQ_STS_RAW_VD2_INT_MASK                           (0x00000004U)

#define VPFE_IRQ_STS_VD0_INT_SHIFT                              (0U)
#define VPFE_IRQ_STS_VD0_INT_MASK                               (0x00000001U)

#define VPFE_IRQ_STS_VD1_INT_SHIFT                              (1U)
#define VPFE_IRQ_STS_VD1_INT_MASK                               (0x00000002U)

#define VPFE_IRQ_STS_VD2_INT_SHIFT                              (2U)
#define VPFE_IRQ_STS_VD2_INT_MASK                               (0x00000004U)

#define VPFE_IRQ_EN_SET_VD0_INT_SHIFT                           (0U)
#define VPFE_IRQ_EN_SET_VD0_INT_MASK                            (0x00000001U)

#define VPFE_IRQ_EN_SET_VD1_INT_SHIFT                           (1U)
#define VPFE_IRQ_EN_SET_VD1_INT_MASK                            (0x00000002U)

#define VPFE_IRQ_EN_SET_VD2_INT_SHIFT                           (2U)
#define VPFE_IRQ_EN_SET_VD2_INT_MASK                            (0x00000004U)

#define VPFE_IRQ_EN_CLR_VD0_INT_DIS_SHIFT                       (0U)
#define VPFE_IRQ_EN_CLR_VD0_INT_DIS_MASK                        (0x00000001U)

#define VPFE_IRQ_EN_CLR_VD1_INT_DIS_SHIFT                       (1U)
#define VPFE_IRQ_EN_CLR_VD1_INT_DIS_MASK                        (0x00000002U)

#define VPFE_IRQ_EN_CLR_VD2_INT_DIS_SHIFT                       (2U)
#define VPFE_IRQ_EN_CLR_VD2_INT_DIS_MASK                        (0x00000004U)

#ifdef __cplusplus
}
#endif

#endif /* HW_VPFE_H_ */
