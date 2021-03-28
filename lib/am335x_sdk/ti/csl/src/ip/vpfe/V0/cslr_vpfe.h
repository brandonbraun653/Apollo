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
 *  Name        : cslr_vpfe.h
*/
#ifndef CSLR_VPFE_H_
#define CSLR_VPFE_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : VPFE Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t REVISION;
    volatile uint32_t PCR;
    volatile uint32_t SYNMODE;
    volatile uint32_t HD_VD_WID;
    volatile uint32_t PIX_LINES;
    volatile uint32_t HORZ_INFO;
    volatile uint32_t VERT_START;
    volatile uint32_t VERT_LINES;
    volatile uint32_t CULLING;
    volatile uint32_t HSIZE_OFF;
    volatile uint32_t SDOFST;
    volatile uint32_t SDR_ADDR;
    volatile uint32_t CLAMP;
    volatile uint32_t DCSUB;
    volatile uint32_t COLPTN;
    volatile uint32_t BLKCMP;
    volatile uint8_t  Resv_72[8];
    volatile uint32_t VDINT;
    volatile uint32_t ALAW;
    volatile uint32_t REC656IF;
    volatile uint32_t CCDCFG;
    volatile uint8_t  Resv_152[64];
    volatile uint32_t DMA_CNTL;
    volatile uint8_t  Resv_260[104];
    volatile uint32_t SYSCONFIG;
    volatile uint32_t CONFIG;
    volatile uint8_t  Resv_272[4];
    volatile uint32_t IRQ_EOI;
    volatile uint32_t IRQ_STATUS_RAW;
    volatile uint32_t IRQ_STATUS;
    volatile uint32_t IRQ_ENABLE_SET;
    volatile uint32_t IRQ_ENABLE_CLR;
} CSL_vpfeRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_VPFE_REVISION                                                      (0x00000000U)
#define CSL_VPFE_PCR                                                           (0x00000004U)
#define CSL_VPFE_SYNMODE                                                       (0x00000008U)
#define CSL_VPFE_HD_VD_WID                                                     (0x0000000CU)
#define CSL_VPFE_PIX_LINES                                                     (0x00000010U)
#define CSL_VPFE_HORZ_INFO                                                     (0x00000014U)
#define CSL_VPFE_VERT_START                                                    (0x00000018U)
#define CSL_VPFE_VERT_LINES                                                    (0x0000001CU)
#define CSL_VPFE_CULLING                                                       (0x00000020U)
#define CSL_VPFE_HSIZE_OFF                                                     (0x00000024U)
#define CSL_VPFE_SDOFST                                                        (0x00000028U)
#define CSL_VPFE_SDR_ADDR                                                      (0x0000002CU)
#define CSL_VPFE_CLAMP                                                         (0x00000030U)
#define CSL_VPFE_DCSUB                                                         (0x00000034U)
#define CSL_VPFE_COLPTN                                                        (0x00000038U)
#define CSL_VPFE_BLKCMP                                                        (0x0000003CU)
#define CSL_VPFE_VDINT                                                         (0x00000048U)
#define CSL_VPFE_ALAW                                                          (0x0000004CU)
#define CSL_VPFE_REC656IF                                                      (0x00000050U)
#define CSL_VPFE_CCDCFG                                                        (0x00000054U)
#define CSL_VPFE_DMA_CNTL                                                      (0x00000098U)
#define CSL_VPFE_SYSCONFIG                                                     (0x00000104U)
#define CSL_VPFE_CONFIG                                                        (0x00000108U)
#define CSL_VPFE_IRQ_EOI                                                       (0x00000110U)
#define CSL_VPFE_IRQ_STATUS_RAW                                                (0x00000114U)
#define CSL_VPFE_IRQ_STATUS                                                    (0x00000118U)
#define CSL_VPFE_IRQ_ENABLE_SET                                                (0x0000011CU)
#define CSL_VPFE_IRQ_ENABLE_CLR                                                (0x00000120U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* REVISION */

#define CSL_VPFE_REVISION_Y_MINOR_MASK                                         (0x0000003FU)
#define CSL_VPFE_REVISION_Y_MINOR_SHIFT                                        (0x00000000U)
#define CSL_VPFE_REVISION_Y_MINOR_MAX                                          (0x0000003FU)

#define CSL_VPFE_REVISION_CUSTOM_MASK                                          (0x000000C0U)
#define CSL_VPFE_REVISION_CUSTOM_SHIFT                                         (0x00000006U)
#define CSL_VPFE_REVISION_CUSTOM_MAX                                           (0x00000003U)

#define CSL_VPFE_REVISION_X_MAJOR_MASK                                         (0x00000700U)
#define CSL_VPFE_REVISION_X_MAJOR_SHIFT                                        (0x00000008U)
#define CSL_VPFE_REVISION_X_MAJOR_MAX                                          (0x00000007U)

#define CSL_VPFE_REVISION_R_RTL_MASK                                           (0x0000F800U)
#define CSL_VPFE_REVISION_R_RTL_SHIFT                                          (0x0000000BU)
#define CSL_VPFE_REVISION_R_RTL_MAX                                            (0x0000001FU)

#define CSL_VPFE_REVISION_FUNC_MASK                                            (0x0FFF0000U)
#define CSL_VPFE_REVISION_FUNC_SHIFT                                           (0x00000010U)
#define CSL_VPFE_REVISION_FUNC_MAX                                             (0x00000FFFU)

#define CSL_VPFE_REVISION_SCHEME_MASK                                          (0xC0000000U)
#define CSL_VPFE_REVISION_SCHEME_SHIFT                                         (0x0000001EU)
#define CSL_VPFE_REVISION_SCHEME_MAX                                           (0x00000003U)

/* PCR */

#define CSL_VPFE_PCR_ENABLE_MASK                                               (0x00000001U)
#define CSL_VPFE_PCR_ENABLE_SHIFT                                              (0x00000000U)
#define CSL_VPFE_PCR_ENABLE_MAX                                                (0x00000001U)

#define CSL_VPFE_PCR_BUSY_MASK                                                 (0x00000002U)
#define CSL_VPFE_PCR_BUSY_SHIFT                                                (0x00000001U)
#define CSL_VPFE_PCR_BUSY_MAX                                                  (0x00000001U)

#define CSL_VPFE_PCR_PG_EN_MASK                                                (0x00000004U)
#define CSL_VPFE_PCR_PG_EN_SHIFT                                               (0x00000002U)
#define CSL_VPFE_PCR_PG_EN_MAX                                                 (0x00000001U)

#define CSL_VPFE_PCR_EXPG_EN_MASK                                              (0x00000008U)
#define CSL_VPFE_PCR_EXPG_EN_SHIFT                                             (0x00000003U)
#define CSL_VPFE_PCR_EXPG_EN_MAX                                               (0x00000001U)

/* SYNMODE */

#define CSL_VPFE_SYNMODE_VDHDOUT_MASK                                          (0x00000001U)
#define CSL_VPFE_SYNMODE_VDHDOUT_SHIFT                                         (0x00000000U)
#define CSL_VPFE_SYNMODE_VDHDOUT_MAX                                           (0x00000001U)

#define CSL_VPFE_SYNMODE_FLDOUT_MASK                                           (0x00000002U)
#define CSL_VPFE_SYNMODE_FLDOUT_SHIFT                                          (0x00000001U)
#define CSL_VPFE_SYNMODE_FLDOUT_MAX                                            (0x00000001U)

#define CSL_VPFE_SYNMODE_VDPOL_MASK                                            (0x00000004U)
#define CSL_VPFE_SYNMODE_VDPOL_SHIFT                                           (0x00000002U)
#define CSL_VPFE_SYNMODE_VDPOL_MAX                                             (0x00000001U)

#define CSL_VPFE_SYNMODE_HDPOL_MASK                                            (0x00000008U)
#define CSL_VPFE_SYNMODE_HDPOL_SHIFT                                           (0x00000003U)
#define CSL_VPFE_SYNMODE_HDPOL_MAX                                             (0x00000001U)

#define CSL_VPFE_SYNMODE_FLDPOL_MASK                                           (0x00000010U)
#define CSL_VPFE_SYNMODE_FLDPOL_SHIFT                                          (0x00000004U)
#define CSL_VPFE_SYNMODE_FLDPOL_MAX                                            (0x00000001U)

#define CSL_VPFE_SYNMODE_EXWEN_MASK                                            (0x00000020U)
#define CSL_VPFE_SYNMODE_EXWEN_SHIFT                                           (0x00000005U)
#define CSL_VPFE_SYNMODE_EXWEN_MAX                                             (0x00000001U)

#define CSL_VPFE_SYNMODE_DATAPOL_MASK                                          (0x00000040U)
#define CSL_VPFE_SYNMODE_DATAPOL_SHIFT                                         (0x00000006U)
#define CSL_VPFE_SYNMODE_DATAPOL_MAX                                           (0x00000001U)

#define CSL_VPFE_SYNMODE_FLDMODE_MASK                                          (0x00000080U)
#define CSL_VPFE_SYNMODE_FLDMODE_SHIFT                                         (0x00000007U)
#define CSL_VPFE_SYNMODE_FLDMODE_MAX                                           (0x00000001U)

#define CSL_VPFE_SYNMODE_DATSIZ_MASK                                           (0x00000700U)
#define CSL_VPFE_SYNMODE_DATSIZ_SHIFT                                          (0x00000008U)
#define CSL_VPFE_SYNMODE_DATSIZ_MAX                                            (0x00000007U)

#define CSL_VPFE_SYNMODE_PACK8_MASK                                            (0x00000800U)
#define CSL_VPFE_SYNMODE_PACK8_SHIFT                                           (0x0000000BU)
#define CSL_VPFE_SYNMODE_PACK8_MAX                                             (0x00000001U)

#define CSL_VPFE_SYNMODE_INPMOD_MASK                                           (0x00003000U)
#define CSL_VPFE_SYNMODE_INPMOD_SHIFT                                          (0x0000000CU)
#define CSL_VPFE_SYNMODE_INPMOD_MAX                                            (0x00000003U)

#define CSL_VPFE_SYNMODE_LPF_MASK                                              (0x00004000U)
#define CSL_VPFE_SYNMODE_LPF_SHIFT                                             (0x0000000EU)
#define CSL_VPFE_SYNMODE_LPF_MAX                                               (0x00000001U)

#define CSL_VPFE_SYNMODE_FLDSTAT_MASK                                          (0x00008000U)
#define CSL_VPFE_SYNMODE_FLDSTAT_SHIFT                                         (0x0000000FU)
#define CSL_VPFE_SYNMODE_FLDSTAT_MAX                                           (0x00000001U)

#define CSL_VPFE_SYNMODE_VDHDEN_MASK                                           (0x00010000U)
#define CSL_VPFE_SYNMODE_VDHDEN_SHIFT                                          (0x00000010U)
#define CSL_VPFE_SYNMODE_VDHDEN_MAX                                            (0x00000001U)

#define CSL_VPFE_SYNMODE_WEN_MASK                                              (0x00020000U)
#define CSL_VPFE_SYNMODE_WEN_SHIFT                                             (0x00000011U)
#define CSL_VPFE_SYNMODE_WEN_MAX                                               (0x00000001U)

#define CSL_VPFE_SYNMODE_RESERVED_RW_MASK                                      (0x000C0000U)
#define CSL_VPFE_SYNMODE_RESERVED_RW_SHIFT                                     (0x00000012U)
#define CSL_VPFE_SYNMODE_RESERVED_RW_MAX                                       (0x00000003U)

/* HD_VD_WID */

#define CSL_VPFE_HD_VD_WID_VDW_MASK                                            (0x00000FFFU)
#define CSL_VPFE_HD_VD_WID_VDW_SHIFT                                           (0x00000000U)
#define CSL_VPFE_HD_VD_WID_VDW_MAX                                             (0x00000FFFU)

#define CSL_VPFE_HD_VD_WID_HDW_MASK                                            (0x0FFF0000U)
#define CSL_VPFE_HD_VD_WID_HDW_SHIFT                                           (0x00000010U)
#define CSL_VPFE_HD_VD_WID_HDW_MAX                                             (0x00000FFFU)

/* PIX_LINES */

#define CSL_VPFE_PIX_LINES_HLPFR_MASK                                          (0x0000FFFFU)
#define CSL_VPFE_PIX_LINES_HLPFR_SHIFT                                         (0x00000000U)
#define CSL_VPFE_PIX_LINES_HLPFR_MAX                                           (0x0000FFFFU)

#define CSL_VPFE_PIX_LINES_PPLN_MASK                                           (0xFFFF0000U)
#define CSL_VPFE_PIX_LINES_PPLN_SHIFT                                          (0x00000010U)
#define CSL_VPFE_PIX_LINES_PPLN_MAX                                            (0x0000FFFFU)

/* HORZ_INFO */

#define CSL_VPFE_HORZ_INFO_NPH_MASK                                            (0x00007FFFU)
#define CSL_VPFE_HORZ_INFO_NPH_SHIFT                                           (0x00000000U)
#define CSL_VPFE_HORZ_INFO_NPH_MAX                                             (0x00007FFFU)

#define CSL_VPFE_HORZ_INFO_SPH_MASK                                            (0x7FFF0000U)
#define CSL_VPFE_HORZ_INFO_SPH_SHIFT                                           (0x00000010U)
#define CSL_VPFE_HORZ_INFO_SPH_MAX                                             (0x00007FFFU)

/* VERT_START */

#define CSL_VPFE_VERT_START_SLV1_MASK                                          (0x00007FFFU)
#define CSL_VPFE_VERT_START_SLV1_SHIFT                                         (0x00000000U)
#define CSL_VPFE_VERT_START_SLV1_MAX                                           (0x00007FFFU)

#define CSL_VPFE_VERT_START_SLV0_MASK                                          (0x7FFF0000U)
#define CSL_VPFE_VERT_START_SLV0_SHIFT                                         (0x00000010U)
#define CSL_VPFE_VERT_START_SLV0_MAX                                           (0x00007FFFU)

/* VERT_LINES */

#define CSL_VPFE_VERT_LINES_NLV_MASK                                           (0x00007FFFU)
#define CSL_VPFE_VERT_LINES_NLV_SHIFT                                          (0x00000000U)
#define CSL_VPFE_VERT_LINES_NLV_MAX                                            (0x00007FFFU)

/* CULLING */

#define CSL_VPFE_CULLING_CULV_MASK                                             (0x000000FFU)
#define CSL_VPFE_CULLING_CULV_SHIFT                                            (0x00000000U)
#define CSL_VPFE_CULLING_CULV_MAX                                              (0x000000FFU)

#define CSL_VPFE_CULLING_CULHODD_MASK                                          (0x00FF0000U)
#define CSL_VPFE_CULLING_CULHODD_SHIFT                                         (0x00000010U)
#define CSL_VPFE_CULLING_CULHODD_MAX                                           (0x000000FFU)

#define CSL_VPFE_CULLING_CULHEVN_MASK                                          (0xFF000000U)
#define CSL_VPFE_CULLING_CULHEVN_SHIFT                                         (0x00000018U)
#define CSL_VPFE_CULLING_CULHEVN_MAX                                           (0x000000FFU)

/* HSIZE_OFF */

#define CSL_VPFE_HSIZE_OFF_LNOFST_MASK                                         (0x0000FFFFU)
#define CSL_VPFE_HSIZE_OFF_LNOFST_SHIFT                                        (0x00000000U)
#define CSL_VPFE_HSIZE_OFF_LNOFST_MAX                                          (0x0000FFFFU)

/* SDOFST */

#define CSL_VPFE_SDOFST_LOFTS3_MASK                                            (0x00000007U)
#define CSL_VPFE_SDOFST_LOFTS3_SHIFT                                           (0x00000000U)
#define CSL_VPFE_SDOFST_LOFTS3_MAX                                             (0x00000007U)

#define CSL_VPFE_SDOFST_LOFTS2_MASK                                            (0x00000038U)
#define CSL_VPFE_SDOFST_LOFTS2_SHIFT                                           (0x00000003U)
#define CSL_VPFE_SDOFST_LOFTS2_MAX                                             (0x00000007U)

#define CSL_VPFE_SDOFST_LOFTS1_MASK                                            (0x000001C0U)
#define CSL_VPFE_SDOFST_LOFTS1_SHIFT                                           (0x00000006U)
#define CSL_VPFE_SDOFST_LOFTS1_MAX                                             (0x00000007U)

#define CSL_VPFE_SDOFST_LOFTS0_MASK                                            (0x00000E00U)
#define CSL_VPFE_SDOFST_LOFTS0_SHIFT                                           (0x00000009U)
#define CSL_VPFE_SDOFST_LOFTS0_MAX                                             (0x00000007U)

#define CSL_VPFE_SDOFST_FOFST_MASK                                             (0x00003000U)
#define CSL_VPFE_SDOFST_FOFST_SHIFT                                            (0x0000000CU)
#define CSL_VPFE_SDOFST_FOFST_MAX                                              (0x00000003U)

#define CSL_VPFE_SDOFST_FIINV_MASK                                             (0x00004000U)
#define CSL_VPFE_SDOFST_FIINV_SHIFT                                            (0x0000000EU)
#define CSL_VPFE_SDOFST_FIINV_MAX                                              (0x00000001U)

/* SDR_ADDR */

#define CSL_VPFE_SDR_ADDR_ADR_LSB_MASK                                         (0x0000001FU)
#define CSL_VPFE_SDR_ADDR_ADR_LSB_SHIFT                                        (0x00000000U)
#define CSL_VPFE_SDR_ADDR_ADR_LSB_MAX                                          (0x0000001FU)

#define CSL_VPFE_SDR_ADDR_ADR_MSB_MASK                                         (0xFFFFFFE0U)
#define CSL_VPFE_SDR_ADDR_ADR_MSB_SHIFT                                        (0x00000005U)
#define CSL_VPFE_SDR_ADDR_ADR_MSB_MAX                                          (0x07FFFFFFU)

/* CLAMP */

#define CSL_VPFE_CLAMP_OBGAIN_MASK                                             (0x0000001FU)
#define CSL_VPFE_CLAMP_OBGAIN_SHIFT                                            (0x00000000U)
#define CSL_VPFE_CLAMP_OBGAIN_MAX                                              (0x0000001FU)

#define CSL_VPFE_CLAMP_OBST_MASK                                               (0x01FFFC00U)
#define CSL_VPFE_CLAMP_OBST_SHIFT                                              (0x0000000AU)
#define CSL_VPFE_CLAMP_OBST_MAX                                                (0x00007FFFU)

#define CSL_VPFE_CLAMP_OBSLN_MASK                                              (0x0E000000U)
#define CSL_VPFE_CLAMP_OBSLN_SHIFT                                             (0x00000019U)
#define CSL_VPFE_CLAMP_OBSLN_MAX                                               (0x00000007U)

#define CSL_VPFE_CLAMP_OBSLEN_MASK                                             (0x70000000U)
#define CSL_VPFE_CLAMP_OBSLEN_SHIFT                                            (0x0000001CU)
#define CSL_VPFE_CLAMP_OBSLEN_MAX                                              (0x00000007U)

#define CSL_VPFE_CLAMP_CLAMPEN_MASK                                            (0x80000000U)
#define CSL_VPFE_CLAMP_CLAMPEN_SHIFT                                           (0x0000001FU)
#define CSL_VPFE_CLAMP_CLAMPEN_MAX                                             (0x00000001U)

/* DCSUB */

#define CSL_VPFE_DCSUB_DCSUB_MASK                                              (0x00003FFFU)
#define CSL_VPFE_DCSUB_DCSUB_SHIFT                                             (0x00000000U)
#define CSL_VPFE_DCSUB_DCSUB_MAX                                               (0x00003FFFU)

/* COLPTN */

#define CSL_VPFE_COLPTN_CP0LPC0_MASK                                           (0x00000003U)
#define CSL_VPFE_COLPTN_CP0LPC0_SHIFT                                          (0x00000000U)
#define CSL_VPFE_COLPTN_CP0LPC0_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP0LPC1_MASK                                           (0x0000000CU)
#define CSL_VPFE_COLPTN_CP0LPC1_SHIFT                                          (0x00000002U)
#define CSL_VPFE_COLPTN_CP0LPC1_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP0LPC2_MASK                                           (0x00000030U)
#define CSL_VPFE_COLPTN_CP0LPC2_SHIFT                                          (0x00000004U)
#define CSL_VPFE_COLPTN_CP0LPC2_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP0LPC3_MASK                                           (0x000000C0U)
#define CSL_VPFE_COLPTN_CP0LPC3_SHIFT                                          (0x00000006U)
#define CSL_VPFE_COLPTN_CP0LPC3_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP1LPC0_MASK                                           (0x00000300U)
#define CSL_VPFE_COLPTN_CP1LPC0_SHIFT                                          (0x00000008U)
#define CSL_VPFE_COLPTN_CP1LPC0_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP1LPC1_MASK                                           (0x00000C00U)
#define CSL_VPFE_COLPTN_CP1LPC1_SHIFT                                          (0x0000000AU)
#define CSL_VPFE_COLPTN_CP1LPC1_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP1LPC2_MASK                                           (0x00003000U)
#define CSL_VPFE_COLPTN_CP1LPC2_SHIFT                                          (0x0000000CU)
#define CSL_VPFE_COLPTN_CP1LPC2_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP1LPC3_MASK                                           (0x0000C000U)
#define CSL_VPFE_COLPTN_CP1LPC3_SHIFT                                          (0x0000000EU)
#define CSL_VPFE_COLPTN_CP1LPC3_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP2LPC0_MASK                                           (0x00030000U)
#define CSL_VPFE_COLPTN_CP2LPC0_SHIFT                                          (0x00000010U)
#define CSL_VPFE_COLPTN_CP2LPC0_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP2LPC1_MASK                                           (0x000C0000U)
#define CSL_VPFE_COLPTN_CP2LPC1_SHIFT                                          (0x00000012U)
#define CSL_VPFE_COLPTN_CP2LPC1_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP2LPC2_MASK                                           (0x00300000U)
#define CSL_VPFE_COLPTN_CP2LPC2_SHIFT                                          (0x00000014U)
#define CSL_VPFE_COLPTN_CP2LPC2_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP2LPC3_MASK                                           (0x00C00000U)
#define CSL_VPFE_COLPTN_CP2LPC3_SHIFT                                          (0x00000016U)
#define CSL_VPFE_COLPTN_CP2LPC3_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP3LPC0_MASK                                           (0x03000000U)
#define CSL_VPFE_COLPTN_CP3LPC0_SHIFT                                          (0x00000018U)
#define CSL_VPFE_COLPTN_CP3LPC0_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP3LPC1_MASK                                           (0x0C000000U)
#define CSL_VPFE_COLPTN_CP3LPC1_SHIFT                                          (0x0000001AU)
#define CSL_VPFE_COLPTN_CP3LPC1_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP3LPC2_MASK                                           (0x30000000U)
#define CSL_VPFE_COLPTN_CP3LPC2_SHIFT                                          (0x0000001CU)
#define CSL_VPFE_COLPTN_CP3LPC2_MAX                                            (0x00000003U)

#define CSL_VPFE_COLPTN_CP3LPC3_MASK                                           (0xC0000000U)
#define CSL_VPFE_COLPTN_CP3LPC3_SHIFT                                          (0x0000001EU)
#define CSL_VPFE_COLPTN_CP3LPC3_MAX                                            (0x00000003U)

/* BLKCMP */

#define CSL_VPFE_BLKCMP_BMG_MASK                                               (0x000000FFU)
#define CSL_VPFE_BLKCMP_BMG_SHIFT                                              (0x00000000U)
#define CSL_VPFE_BLKCMP_BMG_MAX                                                (0x000000FFU)

#define CSL_VPFE_BLKCMP_GBG_MASK                                               (0x0000FF00U)
#define CSL_VPFE_BLKCMP_GBG_SHIFT                                              (0x00000008U)
#define CSL_VPFE_BLKCMP_GBG_MAX                                                (0x000000FFU)

#define CSL_VPFE_BLKCMP_GRCY_MASK                                              (0x00FF0000U)
#define CSL_VPFE_BLKCMP_GRCY_SHIFT                                             (0x00000010U)
#define CSL_VPFE_BLKCMP_GRCY_MAX                                               (0x000000FFU)

#define CSL_VPFE_BLKCMP_RYE_MASK                                               (0xFF000000U)
#define CSL_VPFE_BLKCMP_RYE_SHIFT                                              (0x00000018U)
#define CSL_VPFE_BLKCMP_RYE_MAX                                                (0x000000FFU)

/* VDINT */

#define CSL_VPFE_VDINT_VDINT1_MASK                                             (0x00007FFFU)
#define CSL_VPFE_VDINT_VDINT1_SHIFT                                            (0x00000000U)
#define CSL_VPFE_VDINT_VDINT1_MAX                                              (0x00007FFFU)

#define CSL_VPFE_VDINT_VDINT0_MASK                                             (0x7FFF0000U)
#define CSL_VPFE_VDINT_VDINT0_SHIFT                                            (0x00000010U)
#define CSL_VPFE_VDINT_VDINT0_MAX                                              (0x00007FFFU)

/* ALAW */

#define CSL_VPFE_ALAW_GWDI_MASK                                                (0x00000007U)
#define CSL_VPFE_ALAW_GWDI_SHIFT                                               (0x00000000U)
#define CSL_VPFE_ALAW_GWDI_MAX                                                 (0x00000007U)

#define CSL_VPFE_ALAW_CCDTBL_MASK                                              (0x00000008U)
#define CSL_VPFE_ALAW_CCDTBL_SHIFT                                             (0x00000003U)
#define CSL_VPFE_ALAW_CCDTBL_MAX                                               (0x00000001U)

/* REC656IF */

#define CSL_VPFE_REC656IF_R656ON_MASK                                          (0x00000001U)
#define CSL_VPFE_REC656IF_R656ON_SHIFT                                         (0x00000000U)
#define CSL_VPFE_REC656IF_R656ON_MAX                                           (0x00000001U)

#define CSL_VPFE_REC656IF_ECCFVH_MASK                                          (0x00000002U)
#define CSL_VPFE_REC656IF_ECCFVH_SHIFT                                         (0x00000001U)
#define CSL_VPFE_REC656IF_ECCFVH_MAX                                           (0x00000001U)

/* CCDCFG */

#define CSL_VPFE_CCDCFG_YCOUTSWP_MASK                                          (0x00000004U)
#define CSL_VPFE_CCDCFG_YCOUTSWP_SHIFT                                         (0x00000002U)
#define CSL_VPFE_CCDCFG_YCOUTSWP_MAX                                           (0x00000001U)

#define CSL_VPFE_CCDCFG_RESERVED_RW_MASK                                       (0x00000008U)
#define CSL_VPFE_CCDCFG_RESERVED_RW_SHIFT                                      (0x00000003U)
#define CSL_VPFE_CCDCFG_RESERVED_RW_MAX                                        (0x00000001U)

#define CSL_VPFE_CCDCFG_YCINSWP_MASK                                           (0x00000010U)
#define CSL_VPFE_CCDCFG_YCINSWP_SHIFT                                          (0x00000004U)
#define CSL_VPFE_CCDCFG_YCINSWP_MAX                                            (0x00000001U)

#define CSL_VPFE_CCDCFG_BW656_MASK                                             (0x00000020U)
#define CSL_VPFE_CCDCFG_BW656_SHIFT                                            (0x00000005U)
#define CSL_VPFE_CCDCFG_BW656_MAX                                              (0x00000001U)

#define CSL_VPFE_CCDCFG_RESERVED_RW1_MASK                                      (0x000000C0U)
#define CSL_VPFE_CCDCFG_RESERVED_RW1_SHIFT                                     (0x00000006U)
#define CSL_VPFE_CCDCFG_RESERVED_RW1_MAX                                       (0x00000003U)

#define CSL_VPFE_CCDCFG_WENLOG_MASK                                            (0x00000100U)
#define CSL_VPFE_CCDCFG_WENLOG_SHIFT                                           (0x00000008U)
#define CSL_VPFE_CCDCFG_WENLOG_MAX                                             (0x00000001U)

#define CSL_VPFE_CCDCFG_Y8POS_MASK                                             (0x00000800U)
#define CSL_VPFE_CCDCFG_Y8POS_SHIFT                                            (0x0000000BU)
#define CSL_VPFE_CCDCFG_Y8POS_MAX                                              (0x00000001U)

#define CSL_VPFE_CCDCFG_BSWD_MASK                                              (0x00001000U)
#define CSL_VPFE_CCDCFG_BSWD_SHIFT                                             (0x0000000CU)
#define CSL_VPFE_CCDCFG_BSWD_MAX                                               (0x00000001U)

#define CSL_VPFE_CCDCFG_MSBINVI_MASK                                           (0x00002000U)
#define CSL_VPFE_CCDCFG_MSBINVI_SHIFT                                          (0x0000000DU)
#define CSL_VPFE_CCDCFG_MSBINVI_MAX                                            (0x00000001U)

#define CSL_VPFE_CCDCFG_MSBINVO_MASK                                           (0x00004000U)
#define CSL_VPFE_CCDCFG_MSBINVO_SHIFT                                          (0x0000000EU)
#define CSL_VPFE_CCDCFG_MSBINVO_MAX                                            (0x00000001U)

#define CSL_VPFE_CCDCFG_VDLC_MASK                                              (0x00008000U)
#define CSL_VPFE_CCDCFG_VDLC_SHIFT                                             (0x0000000FU)
#define CSL_VPFE_CCDCFG_VDLC_MAX                                               (0x00000001U)

/* DMA_CNTL */

#define CSL_VPFE_DMA_CNTL_RESERVED_MASK                                        (0x00000007U)
#define CSL_VPFE_DMA_CNTL_RESERVED_SHIFT                                       (0x00000000U)
#define CSL_VPFE_DMA_CNTL_RESERVED_MAX                                         (0x00000007U)

#define CSL_VPFE_DMA_CNTL_OVERFLOW_MASK                                        (0x80000000U)
#define CSL_VPFE_DMA_CNTL_OVERFLOW_SHIFT                                       (0x0000001FU)
#define CSL_VPFE_DMA_CNTL_OVERFLOW_MAX                                         (0x00000001U)

/* SYSCONFIG */

#define CSL_VPFE_SYSCONFIG_IDLEMODE_MASK                                       (0x0000000CU)
#define CSL_VPFE_SYSCONFIG_IDLEMODE_SHIFT                                      (0x00000002U)
#define CSL_VPFE_SYSCONFIG_IDLEMODE_MAX                                        (0x00000003U)

#define CSL_VPFE_SYSCONFIG_STANDBYMODE_MASK                                    (0x00000030U)
#define CSL_VPFE_SYSCONFIG_STANDBYMODE_SHIFT                                   (0x00000004U)
#define CSL_VPFE_SYSCONFIG_STANDBYMODE_MAX                                     (0x00000003U)

/* CONFIG */

#define CSL_VPFE_CONFIG_PCLK_INV_MASK                                          (0x00000001U)
#define CSL_VPFE_CONFIG_PCLK_INV_SHIFT                                         (0x00000000U)
#define CSL_VPFE_CONFIG_PCLK_INV_MAX                                           (0x00000001U)

#define CSL_VPFE_CONFIG_VPFE_EN_MASK                                           (0x00000002U)
#define CSL_VPFE_CONFIG_VPFE_EN_SHIFT                                          (0x00000001U)
#define CSL_VPFE_CONFIG_VPFE_EN_MAX                                            (0x00000001U)

#define CSL_VPFE_CONFIG_VPFE_ST_MASK                                           (0x00000004U)
#define CSL_VPFE_CONFIG_VPFE_ST_SHIFT                                          (0x00000002U)
#define CSL_VPFE_CONFIG_VPFE_ST_MAX                                            (0x00000001U)

/* IRQ_EOI */

#define CSL_VPFE_IRQ_EOI_EOI_MASK                                              (0x00000001U)
#define CSL_VPFE_IRQ_EOI_EOI_SHIFT                                             (0x00000000U)
#define CSL_VPFE_IRQ_EOI_EOI_MAX                                               (0x00000001U)

/* IRQ_STATUS_RAW */

#define CSL_VPFE_IRQ_STATUS_RAW_VD0_INT_RAW_MASK                               (0x00000001U)
#define CSL_VPFE_IRQ_STATUS_RAW_VD0_INT_RAW_SHIFT                              (0x00000000U)
#define CSL_VPFE_IRQ_STATUS_RAW_VD0_INT_RAW_MAX                                (0x00000001U)

#define CSL_VPFE_IRQ_STATUS_RAW_VD1_INT_RAW_MASK                               (0x00000002U)
#define CSL_VPFE_IRQ_STATUS_RAW_VD1_INT_RAW_SHIFT                              (0x00000001U)
#define CSL_VPFE_IRQ_STATUS_RAW_VD1_INT_RAW_MAX                                (0x00000001U)

#define CSL_VPFE_IRQ_STATUS_RAW_VD2_INT_RAW_MASK                               (0x00000004U)
#define CSL_VPFE_IRQ_STATUS_RAW_VD2_INT_RAW_SHIFT                              (0x00000002U)
#define CSL_VPFE_IRQ_STATUS_RAW_VD2_INT_RAW_MAX                                (0x00000001U)

/* IRQ_STATUS */

#define CSL_VPFE_IRQ_STATUS_VD0_INT_MASK                                       (0x00000001U)
#define CSL_VPFE_IRQ_STATUS_VD0_INT_SHIFT                                      (0x00000000U)
#define CSL_VPFE_IRQ_STATUS_VD0_INT_MAX                                        (0x00000001U)

#define CSL_VPFE_IRQ_STATUS_VD1_INT_MASK                                       (0x00000002U)
#define CSL_VPFE_IRQ_STATUS_VD1_INT_SHIFT                                      (0x00000001U)
#define CSL_VPFE_IRQ_STATUS_VD1_INT_MAX                                        (0x00000001U)

#define CSL_VPFE_IRQ_STATUS_VD2_INT_MASK                                       (0x00000004U)
#define CSL_VPFE_IRQ_STATUS_VD2_INT_SHIFT                                      (0x00000002U)
#define CSL_VPFE_IRQ_STATUS_VD2_INT_MAX                                        (0x00000001U)

/* IRQ_ENABLE_SET */

#define CSL_VPFE_IRQ_ENABLE_SET_VD0_INT_EN_MASK                                (0x00000001U)
#define CSL_VPFE_IRQ_ENABLE_SET_VD0_INT_EN_SHIFT                               (0x00000000U)
#define CSL_VPFE_IRQ_ENABLE_SET_VD0_INT_EN_MAX                                 (0x00000001U)

#define CSL_VPFE_IRQ_ENABLE_SET_VD1_INT_EN_MASK                                (0x00000002U)
#define CSL_VPFE_IRQ_ENABLE_SET_VD1_INT_EN_SHIFT                               (0x00000001U)
#define CSL_VPFE_IRQ_ENABLE_SET_VD1_INT_EN_MAX                                 (0x00000001U)

#define CSL_VPFE_IRQ_ENABLE_SET_VD2_INT_EN_MASK                                (0x00000004U)
#define CSL_VPFE_IRQ_ENABLE_SET_VD2_INT_EN_SHIFT                               (0x00000002U)
#define CSL_VPFE_IRQ_ENABLE_SET_VD2_INT_EN_MAX                                 (0x00000001U)

/* IRQ_ENABLE_CLR */

#define CSL_VPFE_IRQ_ENABLE_CLR_VD0_INT_DIS_MASK                               (0x00000001U)
#define CSL_VPFE_IRQ_ENABLE_CLR_VD0_INT_DIS_SHIFT                              (0x00000000U)
#define CSL_VPFE_IRQ_ENABLE_CLR_VD0_INT_DIS_MAX                                (0x00000001U)

#define CSL_VPFE_IRQ_ENABLE_CLR_VD1_INT_DIS_MASK                               (0x00000002U)
#define CSL_VPFE_IRQ_ENABLE_CLR_VD1_INT_DIS_SHIFT                              (0x00000001U)
#define CSL_VPFE_IRQ_ENABLE_CLR_VD1_INT_DIS_MAX                                (0x00000001U)

#define CSL_VPFE_IRQ_ENABLE_CLR_VD2_INT_DIS_MASK                               (0x00000004U)
#define CSL_VPFE_IRQ_ENABLE_CLR_VD2_INT_DIS_SHIFT                              (0x00000002U)
#define CSL_VPFE_IRQ_ENABLE_CLR_VD2_INT_DIS_MAX                                (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif
