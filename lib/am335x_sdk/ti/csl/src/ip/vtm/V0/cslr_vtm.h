/********************************************************************
 * Copyright (C) 2017-2018 Texas Instruments Incorporated.
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
 *  Name        : cslr_vtm.h
*/
#ifndef CSLR_VTM_H_
#define CSLR_VTM_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : MMRs in region 0
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t PID;                       /* PID register */
} CSL_vtm_cfg0Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_VTM_CFG0_PID                                                (0x00000000U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* PID */

#define CSL_VTM_CFG0_PID_MINOR_MASK                                     (0x0000003FU)
#define CSL_VTM_CFG0_PID_MINOR_SHIFT                                    (0x00000000U)
#define CSL_VTM_CFG0_PID_MINOR_MAX                                      (0x0000003FU)

#define CSL_VTM_CFG0_PID_CUSTOM_MASK                                    (0x000000C0U)
#define CSL_VTM_CFG0_PID_CUSTOM_SHIFT                                   (0x00000006U)
#define CSL_VTM_CFG0_PID_CUSTOM_MAX                                     (0x00000003U)

#define CSL_VTM_CFG0_PID_MAJOR_MASK                                     (0x00000700U)
#define CSL_VTM_CFG0_PID_MAJOR_SHIFT                                    (0x00000008U)
#define CSL_VTM_CFG0_PID_MAJOR_MAX                                      (0x00000007U)

#define CSL_VTM_CFG0_PID_MISC_MASK                                      (0x0000F800U)
#define CSL_VTM_CFG0_PID_MISC_SHIFT                                     (0x0000000BU)
#define CSL_VTM_CFG0_PID_MISC_MAX                                       (0x0000001FU)

#define CSL_VTM_CFG0_PID_MSB16_MASK                                     (0xFFFF0000U)
#define CSL_VTM_CFG0_PID_MSB16_SHIFT                                    (0x00000010U)
#define CSL_VTM_CFG0_PID_MSB16_MAX                                      (0x0000FFFFU)

/**************************************************************************
* Hardware Region  : MMRs in region 1
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t CTRL;
    volatile uint32_t TRIM;
    volatile uint32_t STAT;
    volatile uint8_t  Resv_16[4];
} CSL_vtm_cfg1Regs_TMPSENS;

typedef struct {
    volatile uint32_t DEVINFO;
    volatile uint32_t OPPVID;
    volatile uint32_t EVT_STAT;
    volatile uint32_t EVT_SET;
    volatile uint32_t EVT_CLR;
    volatile uint8_t  Resv_32[12];
} CSL_vtm_cfg1Regs_VD;

typedef struct {
    volatile uint32_t PID;
    volatile uint32_t DEVINFO_PWR0;
    volatile uint32_t CLK_CTRL;
    volatile uint32_t MISC_CTRL;
    volatile uint8_t  Resv_128[112];
    CSL_vtm_cfg1Regs_TMPSENS TMPSENS[8];
    CSL_vtm_cfg1Regs_VD VD[8];
    volatile uint8_t  Resv_516[4];
    volatile uint32_t GT_TH1_INT_RAW_STAT_SET;
    volatile uint32_t GT_TH1_INT_EN_STAT_CLR;
    volatile uint8_t  Resv_532[8];
    volatile uint32_t GT_TH1_INT_EN_SET;
    volatile uint32_t GT_TH1_INT_EN_CLR;
    volatile uint8_t  Resv_548[8];
    volatile uint32_t GT_TH2_INT_RAW_STAT_SET;
    volatile uint32_t GT_TH2_INT_EN_STAT_CLR;
    volatile uint8_t  Resv_564[8];
    volatile uint32_t GT_TH2_INT_EN_SET;
    volatile uint32_t GT_TH2_INT_EN_CLR;
    volatile uint8_t  Resv_580[8];
    volatile uint32_t LT_TH0_INT_RAW_STAT_SET;
    volatile uint32_t LT_TH0_INT_EN_STAT_CLR;
    volatile uint8_t  Resv_596[8];
    volatile uint32_t LT_TH0_INT_EN_SET;
    volatile uint32_t LT_TH0_INT_EN_CLR;
} CSL_vtm_cfg1Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_VTM_CFG1_PID                                                (0x00000000U)
#define CSL_VTM_CFG1_DEVINFO_PWR0                                       (0x00000004U)
#define CSL_VTM_CFG1_CLK_CTRL                                           (0x00000008U)
#define CSL_VTM_CFG1_MISC_CTRL                                          (0x0000000CU)
#define CSL_VTM_CFG1_TMPSENS_CTRL(TMPSENS)                              (0x00000080U+((TMPSENS)*0x10U))
#define CSL_VTM_CFG1_TMPSENS_TRIM(TMPSENS)                              (0x00000084U+((TMPSENS)*0x10U))
#define CSL_VTM_CFG1_TMPSENS_STAT(TMPSENS)                              (0x00000088U+((TMPSENS)*0x10U))
#define CSL_VTM_CFG1_VD_DEVINFO(VD)                                     (0x00000100U+((VD)*0x20U))
#define CSL_VTM_CFG1_VD_OPPVID(VD)                                      (0x00000104U+((VD)*0x20U))
#define CSL_VTM_CFG1_VD_EVT_STAT(VD)                                    (0x00000108U+((VD)*0x20U))
#define CSL_VTM_CFG1_VD_EVT_SET(VD)                                     (0x0000010CU+((VD)*0x20U))
#define CSL_VTM_CFG1_VD_EVT_CLR(VD)                                     (0x00000110U+((VD)*0x20U))
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET                            (0x00000204U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR                             (0x00000208U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET                                  (0x00000214U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR                                  (0x00000218U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET                            (0x00000224U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR                             (0x00000228U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET                                  (0x00000234U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR                                  (0x00000238U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET                            (0x00000244U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR                             (0x00000248U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET                                  (0x00000254U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR                                  (0x00000258U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* VTM_CFG1_PID */

#define CSL_VTM_CFG1_PID_Y_MINOR_MASK                                   (0x0000003FU)
#define CSL_VTM_CFG1_PID_Y_MINOR_SHIFT                                  (0x00000000U)
#define CSL_VTM_CFG1_PID_Y_MINOR_MAX                                    (0x0000003FU)

#define CSL_VTM_CFG1_PID_CUSTOM_MASK                                    (0x000000C0U)
#define CSL_VTM_CFG1_PID_CUSTOM_SHIFT                                   (0x00000006U)
#define CSL_VTM_CFG1_PID_CUSTOM_MAX                                     (0x00000003U)

#define CSL_VTM_CFG1_PID_X_MAJOR_MASK                                   (0x00000700U)
#define CSL_VTM_CFG1_PID_X_MAJOR_SHIFT                                  (0x00000008U)
#define CSL_VTM_CFG1_PID_X_MAJOR_MAX                                    (0x00000007U)

#define CSL_VTM_CFG1_PID_R_RTL_MASK                                     (0x0000F800U)
#define CSL_VTM_CFG1_PID_R_RTL_SHIFT                                    (0x0000000BU)
#define CSL_VTM_CFG1_PID_R_RTL_MAX                                      (0x0000001FU)

#define CSL_VTM_CFG1_PID_FUNC_MASK                                      (0x0FFF0000U)
#define CSL_VTM_CFG1_PID_FUNC_SHIFT                                     (0x00000010U)
#define CSL_VTM_CFG1_PID_FUNC_MAX                                       (0x00000FFFU)

#define CSL_VTM_CFG1_PID_BU_MASK                                        (0x30000000U)
#define CSL_VTM_CFG1_PID_BU_SHIFT                                       (0x0000001CU)
#define CSL_VTM_CFG1_PID_BU_MAX                                         (0x00000003U)

#define CSL_VTM_CFG1_PID_SCHEME_MASK                                    (0xC0000000U)
#define CSL_VTM_CFG1_PID_SCHEME_SHIFT                                   (0x0000001EU)
#define CSL_VTM_CFG1_PID_SCHEME_MAX                                     (0x00000003U)

/* VTM_CFG1_DEVINFO_PWR0 */

#define CSL_VTM_CFG1_DEVINFO_PWR0_CVD_CT_MASK                           (0x0000000FU)
#define CSL_VTM_CFG1_DEVINFO_PWR0_CVD_CT_SHIFT                          (0x00000000U)
#define CSL_VTM_CFG1_DEVINFO_PWR0_CVD_CT_MAX                            (0x0000000FU)

#define CSL_VTM_CFG1_DEVINFO_PWR0_TMPSENS_CT_MASK                       (0x000000F0U)
#define CSL_VTM_CFG1_DEVINFO_PWR0_TMPSENS_CT_SHIFT                      (0x00000004U)
#define CSL_VTM_CFG1_DEVINFO_PWR0_TMPSENS_CT_MAX                        (0x0000000FU)

#define CSL_VTM_CFG1_DEVINFO_PWR0_VDD_RTC_MASK                          (0x00001000U)
#define CSL_VTM_CFG1_DEVINFO_PWR0_VDD_RTC_SHIFT                         (0x0000000CU)
#define CSL_VTM_CFG1_DEVINFO_PWR0_VDD_RTC_MAX                           (0x00000001U)

#define CSL_VTM_CFG1_DEVINFO_PWR0_EXT_WKUP_VDD_MASK                     (0x00002000U)
#define CSL_VTM_CFG1_DEVINFO_PWR0_EXT_WKUP_VDD_SHIFT                    (0x0000000DU)
#define CSL_VTM_CFG1_DEVINFO_PWR0_EXT_WKUP_VDD_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_DEVINFO_PWR0_VTM_VD_MAP_MASK                       (0x000F0000U)
#define CSL_VTM_CFG1_DEVINFO_PWR0_VTM_VD_MAP_SHIFT                      (0x00000010U)
#define CSL_VTM_CFG1_DEVINFO_PWR0_VTM_VD_MAP_MAX                        (0x0000000FU)

/* VTM_CFG1_CLK_CTRL */

#define CSL_VTM_CFG1_CLK_CTRL_TSENS_CLK_DIV_MASK                        (0x0000003FU)
#define CSL_VTM_CFG1_CLK_CTRL_TSENS_CLK_DIV_SHIFT                       (0x00000000U)
#define CSL_VTM_CFG1_CLK_CTRL_TSENS_CLK_DIV_MAX                         (0x0000003FU)

/* VTM_CFG1_MISC_CTRL */

#define CSL_VTM_CFG1_MISC_CTRL_ANY_MAXT_OUTRG_ALERT_EN_MASK             (0x00000001U)
#define CSL_VTM_CFG1_MISC_CTRL_ANY_MAXT_OUTRG_ALERT_EN_SHIFT            (0x00000000U)
#define CSL_VTM_CFG1_MISC_CTRL_ANY_MAXT_OUTRG_ALERT_EN_MAX              (0x00000001U)

/* VTM_CFG1_TMPSENS_CTRL */

#define CSL_VTM_CFG1_TMPSENS_CTRL_CBIASSEL_MASK                         (0x00000001U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_CBIASSEL_SHIFT                        (0x00000000U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_CBIASSEL_MAX                          (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_TMPSOFF_MASK                          (0x00000002U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_TMPSOFF_SHIFT                         (0x00000001U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_TMPSOFF_MAX                           (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_BGROFF_MASK                           (0x00000004U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_BGROFF_SHIFT                          (0x00000002U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_BGROFF_MAX                            (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_AIPOFF_MASK                           (0x00000008U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_AIPOFF_SHIFT                          (0x00000003U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_AIPOFF_MAX                            (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_SOC_MASK                              (0x00000020U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_SOC_SHIFT                             (0x00000005U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_SOC_MAX                               (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_CLRZ_MASK                             (0x00000040U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_CLRZ_SHIFT                            (0x00000006U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_CLRZ_MAX                              (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_CLKON_REQ_MASK                        (0x00000080U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_CLKON_REQ_SHIFT                       (0x00000007U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_CLKON_REQ_MAX                         (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_GT_TH1_EN_MASK                        (0x00000100U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_GT_TH1_EN_SHIFT                       (0x00000008U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_GT_TH1_EN_MAX                         (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_GT_TH2_EN_MASK                        (0x00000200U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_GT_TH2_EN_SHIFT                       (0x00000009U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_GT_TH2_EN_MAX                         (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_LT_TH0_EN_MASK                        (0x00000400U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_LT_TH0_EN_SHIFT                       (0x0000000AU)
#define CSL_VTM_CFG1_TMPSENS_CTRL_LT_TH0_EN_MAX                         (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_MAXT_OUTRG_EN_MASK                    (0x00000800U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_MAXT_OUTRG_EN_SHIFT                   (0x0000000BU)
#define CSL_VTM_CFG1_TMPSENS_CTRL_MAXT_OUTRG_EN_MAX                     (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_CTRL_TH1_VAL_MASK                          (0x003FF000U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_TH1_VAL_SHIFT                         (0x0000000CU)
#define CSL_VTM_CFG1_TMPSENS_CTRL_TH1_VAL_MAX                           (0x000003FFU)

#define CSL_VTM_CFG1_TMPSENS_CTRL_TH2_INC_VAL_MASK                      (0x0F000000U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_TH2_INC_VAL_SHIFT                     (0x00000018U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_TH2_INC_VAL_MAX                       (0x0000000FU)

#define CSL_VTM_CFG1_TMPSENS_CTRL_TH0_DEC_VAL_MASK                      (0xF0000000U)
#define CSL_VTM_CFG1_TMPSENS_CTRL_TH0_DEC_VAL_SHIFT                     (0x0000001CU)
#define CSL_VTM_CFG1_TMPSENS_CTRL_TH0_DEC_VAL_MAX                       (0x0000000FU)

/* VTM_CFG1_TMPSENS_TRIM */

#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_TEMPS_MASK                        (0x000000FFU)
#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_TEMPS_SHIFT                       (0x00000000U)
#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_TEMPS_MAX                         (0x000000FFU)

#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_TEMPSC_MASK                       (0x0000FF00U)
#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_TEMPSC_SHIFT                      (0x00000008U)
#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_TEMPSC_MAX                        (0x000000FFU)

#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_BGAPC_MASK                        (0x00FF0000U)
#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_BGAPC_SHIFT                       (0x00000010U)
#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_BGAPC_MAX                         (0x000000FFU)

#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_BGAPV_MASK                        (0xFF000000U)
#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_BGAPV_SHIFT                       (0x00000018U)
#define CSL_VTM_CFG1_TMPSENS_TRIM_DTR_BGAPV_MAX                         (0x000000FFU)

/* VTM_CFG1_TMPSENS_STAT */

#define CSL_VTM_CFG1_TMPSENS_STAT_DTEMP_MASK                            (0x000003FFU)
#define CSL_VTM_CFG1_TMPSENS_STAT_DTEMP_SHIFT                           (0x00000000U)
#define CSL_VTM_CFG1_TMPSENS_STAT_DTEMP_MAX                             (0x000003FFU)

#define CSL_VTM_CFG1_TMPSENS_STAT_EOCZ_MASK                             (0x00000400U)
#define CSL_VTM_CFG1_TMPSENS_STAT_EOCZ_SHIFT                            (0x0000000AU)
#define CSL_VTM_CFG1_TMPSENS_STAT_EOCZ_MAX                              (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_STAT_EOC_FC_UPDATE_MASK                    (0x00000800U)
#define CSL_VTM_CFG1_TMPSENS_STAT_EOC_FC_UPDATE_SHIFT                   (0x0000000BU)
#define CSL_VTM_CFG1_TMPSENS_STAT_EOC_FC_UPDATE_MAX                     (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_STAT_GT_TH1_ALERT_MASK                     (0x00001000U)
#define CSL_VTM_CFG1_TMPSENS_STAT_GT_TH1_ALERT_SHIFT                    (0x0000000CU)
#define CSL_VTM_CFG1_TMPSENS_STAT_GT_TH1_ALERT_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_STAT_GT_TH2_ALERT_MASK                     (0x00002000U)
#define CSL_VTM_CFG1_TMPSENS_STAT_GT_TH2_ALERT_SHIFT                    (0x0000000DU)
#define CSL_VTM_CFG1_TMPSENS_STAT_GT_TH2_ALERT_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_STAT_LT_TH0_ALERT_MASK                     (0x00004000U)
#define CSL_VTM_CFG1_TMPSENS_STAT_LT_TH0_ALERT_SHIFT                    (0x0000000EU)
#define CSL_VTM_CFG1_TMPSENS_STAT_LT_TH0_ALERT_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_STAT_MAXT_OUTRG_ALERT_MASK                 (0x00008000U)
#define CSL_VTM_CFG1_TMPSENS_STAT_MAXT_OUTRG_ALERT_SHIFT                (0x0000000FU)
#define CSL_VTM_CFG1_TMPSENS_STAT_MAXT_OUTRG_ALERT_MAX                  (0x00000001U)

#define CSL_VTM_CFG1_TMPSENS_STAT_VD_MAP_MASK                           (0x000F0000U)
#define CSL_VTM_CFG1_TMPSENS_STAT_VD_MAP_SHIFT                          (0x00000010U)
#define CSL_VTM_CFG1_TMPSENS_STAT_VD_MAP_MAX                            (0x0000000FU)

#define CSL_VTM_CFG1_TMPSENS_STAT_CLKON_ACK_MASK                        (0x00100000U)
#define CSL_VTM_CFG1_TMPSENS_STAT_CLKON_ACK_SHIFT                       (0x00000014U)
#define CSL_VTM_CFG1_TMPSENS_STAT_CLKON_ACK_MAX                         (0x00000001U)

/* VTM_CFG1_DEVINFO */

#define CSL_VTM_CFG1_DEVINFO_TSENS_EVT_SEL_DFLT_MASK                    (0x000000FFU)
#define CSL_VTM_CFG1_DEVINFO_TSENS_EVT_SEL_DFLT_SHIFT                   (0x00000000U)
#define CSL_VTM_CFG1_DEVINFO_TSENS_EVT_SEL_DFLT_MAX                     (0x000000FFU)

#define CSL_VTM_CFG1_DEVINFO_VD_MAP_MASK                                (0x00000F00U)
#define CSL_VTM_CFG1_DEVINFO_VD_MAP_SHIFT                               (0x00000008U)
#define CSL_VTM_CFG1_DEVINFO_VD_MAP_MAX                                 (0x0000000FU)

#define CSL_VTM_CFG1_DEVINFO_AVS0_SUP_MASK                              (0x00001000U)
#define CSL_VTM_CFG1_DEVINFO_AVS0_SUP_SHIFT                             (0x0000000CU)
#define CSL_VTM_CFG1_DEVINFO_AVS0_SUP_MAX                               (0x00000001U)

/* VTM_CFG1_OPPVID */

#define CSL_VTM_CFG1_OPPVID_OPP_LOW_DFLT_MASK                           (0x000000FFU)
#define CSL_VTM_CFG1_OPPVID_OPP_LOW_DFLT_SHIFT                          (0x00000000U)
#define CSL_VTM_CFG1_OPPVID_OPP_LOW_DFLT_MAX                            (0x000000FFU)

#define CSL_VTM_CFG1_OPPVID_OPP_NOM_DFLT_MASK                           (0x0000FF00U)
#define CSL_VTM_CFG1_OPPVID_OPP_NOM_DFLT_SHIFT                          (0x00000008U)
#define CSL_VTM_CFG1_OPPVID_OPP_NOM_DFLT_MAX                            (0x000000FFU)

#define CSL_VTM_CFG1_OPPVID_OPP_ODR_DFLT_MASK                           (0x00FF0000U)
#define CSL_VTM_CFG1_OPPVID_OPP_ODR_DFLT_SHIFT                          (0x00000010U)
#define CSL_VTM_CFG1_OPPVID_OPP_ODR_DFLT_MAX                            (0x000000FFU)

#define CSL_VTM_CFG1_OPPVID_OPP_TRB_DFLT_MASK                           (0xFF000000U)
#define CSL_VTM_CFG1_OPPVID_OPP_TRB_DFLT_SHIFT                          (0x00000018U)
#define CSL_VTM_CFG1_OPPVID_OPP_TRB_DFLT_MAX                            (0x000000FFU)

/* VTM_CFG1_EVT_STAT */

#define CSL_VTM_CFG1_EVT_STAT_GT_TH1_ALERT_MASK                         (0x00000001U)
#define CSL_VTM_CFG1_EVT_STAT_GT_TH1_ALERT_SHIFT                        (0x00000000U)
#define CSL_VTM_CFG1_EVT_STAT_GT_TH1_ALERT_MAX                          (0x00000001U)

#define CSL_VTM_CFG1_EVT_STAT_GT_TH2_ALERT_MASK                         (0x00000002U)
#define CSL_VTM_CFG1_EVT_STAT_GT_TH2_ALERT_SHIFT                        (0x00000001U)
#define CSL_VTM_CFG1_EVT_STAT_GT_TH2_ALERT_MAX                          (0x00000001U)

#define CSL_VTM_CFG1_EVT_STAT_LT_TH0_ALERT_MASK                         (0x00000004U)
#define CSL_VTM_CFG1_EVT_STAT_LT_TH0_ALERT_SHIFT                        (0x00000002U)
#define CSL_VTM_CFG1_EVT_STAT_LT_TH0_ALERT_MAX                          (0x00000001U)

/* VTM_CFG1_EVT_SET */

#define CSL_VTM_CFG1_EVT_SET_LT_TH0_OR_MASK                             (0x00000008U)
#define CSL_VTM_CFG1_EVT_SET_LT_TH0_OR_SHIFT                            (0x00000003U)
#define CSL_VTM_CFG1_EVT_SET_LT_TH0_OR_MAX                              (0x00000001U)

#define CSL_VTM_CFG1_EVT_SET_TSENS_EVT_SEL_MASK                         (0x00FF0000U)
#define CSL_VTM_CFG1_EVT_SET_TSENS_EVT_SEL_SHIFT                        (0x00000010U)
#define CSL_VTM_CFG1_EVT_SET_TSENS_EVT_SEL_MAX                          (0x000000FFU)

/* VTM_CFG1_EVT_CLR */

#define CSL_VTM_CFG1_EVT_CLR_LT_TH0_OR_MASK                             (0x00000008U)
#define CSL_VTM_CFG1_EVT_CLR_LT_TH0_OR_SHIFT                            (0x00000003U)
#define CSL_VTM_CFG1_EVT_CLR_LT_TH0_OR_MAX                              (0x00000001U)

#define CSL_VTM_CFG1_EVT_CLR_TSENS_EVT_SEL_MASK                         (0x00FF0000U)
#define CSL_VTM_CFG1_EVT_CLR_TSENS_EVT_SEL_SHIFT                        (0x00000010U)
#define CSL_VTM_CFG1_EVT_CLR_TSENS_EVT_SEL_MAX                          (0x000000FFU)

/* VTM_GT_TH1_INT_RAW_STAT_SET */

#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD0_MASK               (0x00000001U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD0_SHIFT              (0x00000000U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD0_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD1_MASK               (0x00000002U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD1_SHIFT              (0x00000001U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD1_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD2_MASK               (0x00000004U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD2_SHIFT              (0x00000002U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD2_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD3_MASK               (0x00000008U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD3_SHIFT              (0x00000003U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD3_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD4_MASK               (0x00000010U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD4_SHIFT              (0x00000004U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD4_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD5_MASK               (0x00000020U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD5_SHIFT              (0x00000005U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD5_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD6_MASK               (0x00000040U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD6_SHIFT              (0x00000006U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD6_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD7_MASK               (0x00000080U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD7_SHIFT              (0x00000007U)
#define CSL_VTM_CFG1_GT_TH1_INT_RAW_STAT_SET_INT_VD7_MAX                (0x00000001U)

/* VTM_GT_TH1_INT_EN_STAT_CLR */

#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD0_MASK                (0x00000001U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD0_SHIFT               (0x00000000U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD0_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD1_MASK                (0x00000002U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD1_SHIFT               (0x00000001U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD1_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD2_MASK                (0x00000004U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD2_SHIFT               (0x00000002U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD2_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD3_MASK                (0x00000008U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD3_SHIFT               (0x00000003U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD3_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD4_MASK                (0x00000010U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD4_SHIFT               (0x00000004U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD4_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD5_MASK                (0x00000020U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD5_SHIFT               (0x00000005U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD5_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD6_MASK                (0x00000040U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD6_SHIFT               (0x00000006U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD6_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD7_MASK                (0x00000080U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD7_SHIFT               (0x00000007U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_STAT_CLR_INT_VD7_MAX                 (0x00000001U)

/* VTM_GT_TH1_INT_EN_SET */

#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD0_MASK                     (0x00000001U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD0_SHIFT                    (0x00000000U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD0_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD1_MASK                     (0x00000002U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD1_SHIFT                    (0x00000001U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD1_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD2_MASK                     (0x00000004U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD2_SHIFT                    (0x00000002U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD2_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD3_MASK                     (0x00000008U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD3_SHIFT                    (0x00000003U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD3_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD4_MASK                     (0x00000010U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD4_SHIFT                    (0x00000004U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD4_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD5_MASK                     (0x00000020U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD5_SHIFT                    (0x00000005U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD5_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD6_MASK                     (0x00000040U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD6_SHIFT                    (0x00000006U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD6_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD7_MASK                     (0x00000080U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD7_SHIFT                    (0x00000007U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_SET_INT_VD7_MAX                      (0x00000001U)

/* VTM_GT_TH1_INT_EN_CLR */

#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD0_MASK                     (0x00000001U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD0_SHIFT                    (0x00000000U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD0_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD1_MASK                     (0x00000002U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD1_SHIFT                    (0x00000001U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD1_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD2_MASK                     (0x00000004U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD2_SHIFT                    (0x00000002U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD2_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD3_MASK                     (0x00000008U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD3_SHIFT                    (0x00000003U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD3_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD4_MASK                     (0x00000010U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD4_SHIFT                    (0x00000004U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD4_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD5_MASK                     (0x00000020U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD5_SHIFT                    (0x00000005U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD5_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD6_MASK                     (0x00000040U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD6_SHIFT                    (0x00000006U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD6_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD7_MASK                     (0x00000080U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD7_SHIFT                    (0x00000007U)
#define CSL_VTM_CFG1_GT_TH1_INT_EN_CLR_INT_VD7_MAX                      (0x00000001U)

/* VTM_GT_TH2_INT_RAW_STAT_SET */

#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD0_MASK               (0x00000001U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD0_SHIFT              (0x00000000U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD0_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD1_MASK               (0x00000002U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD1_SHIFT              (0x00000001U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD1_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD2_MASK               (0x00000004U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD2_SHIFT              (0x00000002U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD2_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD3_MASK               (0x00000008U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD3_SHIFT              (0x00000003U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD3_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD4_MASK               (0x00000010U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD4_SHIFT              (0x00000004U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD4_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD5_MASK               (0x00000020U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD5_SHIFT              (0x00000005U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD5_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD6_MASK               (0x00000040U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD6_SHIFT              (0x00000006U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD6_MAX                (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD7_MASK               (0x00000080U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD7_SHIFT              (0x00000007U)
#define CSL_VTM_CFG1_GT_TH2_INT_RAW_STAT_SET_INT_VD7_MAX                (0x00000001U)

/* VTM_GT_TH2_INT_EN_STAT_CLR */

#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD0_MASK                (0x00000001U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD0_SHIFT               (0x00000000U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD0_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD1_MASK                (0x00000002U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD1_SHIFT               (0x00000001U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD1_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD2_MASK                (0x00000004U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD2_SHIFT               (0x00000002U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD2_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD3_MASK                (0x00000008U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD3_SHIFT               (0x00000003U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD3_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD4_MASK                (0x00000010U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD4_SHIFT               (0x00000004U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD4_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD5_MASK                (0x00000020U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD5_SHIFT               (0x00000005U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD5_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD6_MASK                (0x00000040U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD6_SHIFT               (0x00000006U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD6_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD7_MASK                (0x00000080U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD7_SHIFT               (0x00000007U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_STAT_CLR_INT_VD7_MAX                 (0x00000001U)

/* VTM_GT_TH2_INT_EN_SET */

#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD0_MASK                     (0x00000001U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD0_SHIFT                    (0x00000000U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD0_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD1_MASK                     (0x00000002U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD1_SHIFT                    (0x00000001U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD1_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD2_MASK                     (0x00000004U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD2_SHIFT                    (0x00000002U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD2_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD3_MASK                     (0x00000008U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD3_SHIFT                    (0x00000003U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD3_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD4_MASK                     (0x00000010U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD4_SHIFT                    (0x00000004U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD4_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD5_MASK                     (0x00000020U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD5_SHIFT                    (0x00000005U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD5_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD6_MASK                     (0x00000040U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD6_SHIFT                    (0x00000006U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD6_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD7_MASK                     (0x00000080U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD7_SHIFT                    (0x00000007U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_SET_INT_VD7_MAX                      (0x00000001U)

/* VTM_GT_TH2_INT_EN_CLR */

#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD0_MASK                     (0x00000001U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD0_SHIFT                    (0x00000000U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD0_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD1_MASK                     (0x00000002U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD1_SHIFT                    (0x00000001U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD1_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD2_MASK                     (0x00000004U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD2_SHIFT                    (0x00000002U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD2_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD3_MASK                     (0x00000008U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD3_SHIFT                    (0x00000003U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD3_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD4_MASK                     (0x00000010U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD4_SHIFT                    (0x00000004U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD4_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD5_MASK                     (0x00000020U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD5_SHIFT                    (0x00000005U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD5_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD6_MASK                     (0x00000040U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD6_SHIFT                    (0x00000006U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD6_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD7_MASK                     (0x00000080U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD7_SHIFT                    (0x00000007U)
#define CSL_VTM_CFG1_GT_TH2_INT_EN_CLR_INT_VD7_MAX                      (0x00000001U)

/* VTM_LT_TH0_INT_RAW_STAT_SET */

#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD0_MASK               (0x00000001U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD0_SHIFT              (0x00000000U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD0_MAX                (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD1_MASK               (0x00000002U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD1_SHIFT              (0x00000001U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD1_MAX                (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD2_MASK               (0x00000004U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD2_SHIFT              (0x00000002U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD2_MAX                (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD3_MASK               (0x00000008U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD3_SHIFT              (0x00000003U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD3_MAX                (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD4_MASK               (0x00000010U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD4_SHIFT              (0x00000004U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD4_MAX                (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD5_MASK               (0x00000020U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD5_SHIFT              (0x00000005U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD5_MAX                (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD6_MASK               (0x00000040U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD6_SHIFT              (0x00000006U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD6_MAX                (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD7_MASK               (0x00000080U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD7_SHIFT              (0x00000007U)
#define CSL_VTM_CFG1_LT_TH0_INT_RAW_STAT_SET_INT_VD7_MAX                (0x00000001U)

/* VTM_LT_TH0_INT_EN_STAT_CLR */

#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD0_MASK                (0x00000001U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD0_SHIFT               (0x00000000U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD0_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD1_MASK                (0x00000002U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD1_SHIFT               (0x00000001U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD1_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD2_MASK                (0x00000004U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD2_SHIFT               (0x00000002U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD2_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD3_MASK                (0x00000008U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD3_SHIFT               (0x00000003U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD3_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD4_MASK                (0x00000010U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD4_SHIFT               (0x00000004U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD4_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD5_MASK                (0x00000020U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD5_SHIFT               (0x00000005U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD5_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD6_MASK                (0x00000040U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD6_SHIFT               (0x00000006U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD6_MAX                 (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD7_MASK                (0x00000080U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD7_SHIFT               (0x00000007U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_STAT_CLR_INT_VD7_MAX                 (0x00000001U)

/* VTM_LT_TH0_INT_EN_SET */

#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD0_MASK                     (0x00000001U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD0_SHIFT                    (0x00000000U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD0_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD1_MASK                     (0x00000002U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD1_SHIFT                    (0x00000001U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD1_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD2_MASK                     (0x00000004U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD2_SHIFT                    (0x00000002U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD2_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD3_MASK                     (0x00000008U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD3_SHIFT                    (0x00000003U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD3_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD4_MASK                     (0x00000010U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD4_SHIFT                    (0x00000004U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD4_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD5_MASK                     (0x00000020U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD5_SHIFT                    (0x00000005U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD5_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD6_MASK                     (0x00000040U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD6_SHIFT                    (0x00000006U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD6_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD7_MASK                     (0x00000080U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD7_SHIFT                    (0x00000007U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_SET_INT_VD7_MAX                      (0x00000001U)

/* VTM_LT_TH0_INT_EN_CLR */

#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD0_MASK                     (0x00000001U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD0_SHIFT                    (0x00000000U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD0_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD1_MASK                     (0x00000002U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD1_SHIFT                    (0x00000001U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD1_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD2_MASK                     (0x00000004U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD2_SHIFT                    (0x00000002U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD2_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD3_MASK                     (0x00000008U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD3_SHIFT                    (0x00000003U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD3_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD4_MASK                     (0x00000010U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD4_SHIFT                    (0x00000004U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD4_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD5_MASK                     (0x00000020U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD5_SHIFT                    (0x00000005U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD5_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD6_MASK                     (0x00000040U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD6_SHIFT                    (0x00000006U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD6_MAX                      (0x00000001U)

#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD7_MASK                     (0x00000080U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD7_SHIFT                    (0x00000007U)
#define CSL_VTM_CFG1_LT_TH0_INT_EN_CLR_INT_VD7_MAX                      (0x00000001U)

/**************************************************************************
* Hardware Region  : MMRs in region 2
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t SDPA_PID;
    volatile uint32_t SDPA_BYPASS_OVR;
    volatile uint8_t  Resv_16[8];
    volatile uint32_t SDPA_INHIBITSLEEP_ACK_SET;
    volatile uint32_t SDPA_INHIBITSLEEP_ACK_CLR;
    volatile uint32_t SDPA_INHIBITSLEEP_PORT_STAT;
    volatile uint8_t  Resv_32[4];
    volatile uint32_t SDPA_FORCEACTIVE_ACK_SET;
    volatile uint32_t SDPA_FORCEACTIVE_ACK_CLR;
    volatile uint32_t SDPA_FORCEACTIVE_PORT_STAT;
    volatile uint8_t  Resv_48[4];
    volatile uint32_t SDPA_INT_EN_SET;
    volatile uint32_t SDPA_INT_EN_CLR;
    volatile uint8_t  Resv_64[8];
    volatile uint32_t SDPA_INHIBITSLEEP_INT_RAW_STAT_SET;
    volatile uint32_t SDPA_INHIBITSLEEP_INT_EN_STAT_CLR;
    volatile uint8_t  Resv_80[8];
    volatile uint32_t SDPA_FORCEACTIVE_INT_RAW_STAT_SET;
    volatile uint32_t SDPA_FORCEACTIVE_INT_EN_STAT_CLR;
} CSL_vtm_cfg2Regs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_VTM_CFG2_SDPA_PID                                           (0x00000000U)
#define CSL_VTM_CFG2_SDPA_BYPASS_OVR                                    (0x00000004U)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_ACK_SET                          (0x00000010U)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_ACK_CLR                          (0x00000014U)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_PORT_STAT                        (0x00000018U)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_ACK_SET                           (0x00000020U)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_ACK_CLR                           (0x00000024U)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_PORT_STAT                         (0x00000028U)
#define CSL_VTM_CFG2_SDPA_INT_EN_SET                                    (0x00000030U)
#define CSL_VTM_CFG2_SDPA_INT_EN_CLR                                    (0x00000034U)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_INT_RAW_STAT_SET                 (0x00000040U)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_INT_EN_STAT_CLR                  (0x00000044U)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_INT_RAW_STAT_SET                  (0x00000050U)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_INT_EN_STAT_CLR                   (0x00000054U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* SDPA_PID */

#define CSL_VTM_CFG2_SDPA_PID_Y_MINOR_MASK                              (0x0000003FU)
#define CSL_VTM_CFG2_SDPA_PID_Y_MINOR_SHIFT                             (0x00000000U)
#define CSL_VTM_CFG2_SDPA_PID_Y_MINOR_MAX                               (0x0000003FU)

#define CSL_VTM_CFG2_SDPA_PID_CUSTOM_MASK                               (0x000000C0U)
#define CSL_VTM_CFG2_SDPA_PID_CUSTOM_SHIFT                              (0x00000006U)
#define CSL_VTM_CFG2_SDPA_PID_CUSTOM_MAX                                (0x00000003U)

#define CSL_VTM_CFG2_SDPA_PID_X_MAJOR_MASK                              (0x00000700U)
#define CSL_VTM_CFG2_SDPA_PID_X_MAJOR_SHIFT                             (0x00000008U)
#define CSL_VTM_CFG2_SDPA_PID_X_MAJOR_MAX                               (0x00000007U)

#define CSL_VTM_CFG2_SDPA_PID_R_RTL_MASK                                (0x0000F800U)
#define CSL_VTM_CFG2_SDPA_PID_R_RTL_SHIFT                               (0x0000000BU)
#define CSL_VTM_CFG2_SDPA_PID_R_RTL_MAX                                 (0x0000001FU)

#define CSL_VTM_CFG2_SDPA_PID_FUNC_MASK                                 (0x0FFF0000U)
#define CSL_VTM_CFG2_SDPA_PID_FUNC_SHIFT                                (0x00000010U)
#define CSL_VTM_CFG2_SDPA_PID_FUNC_MAX                                  (0x00000FFFU)

#define CSL_VTM_CFG2_SDPA_PID_BU_MASK                                   (0x30000000U)
#define CSL_VTM_CFG2_SDPA_PID_BU_SHIFT                                  (0x0000001CU)
#define CSL_VTM_CFG2_SDPA_PID_BU_MAX                                    (0x00000003U)

#define CSL_VTM_CFG2_SDPA_PID_SCHEME_MASK                               (0xC0000000U)
#define CSL_VTM_CFG2_SDPA_PID_SCHEME_SHIFT                              (0x0000001EU)
#define CSL_VTM_CFG2_SDPA_PID_SCHEME_MAX                                (0x00000003U)

/* SDPA_BYPASS_OVR */

#define CSL_VTM_CFG2_SDPA_BYPASS_OVR_APPRT_MASK                         (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_BYPASS_OVR_APPRT_SHIFT                        (0x00000000U)
#define CSL_VTM_CFG2_SDPA_BYPASS_OVR_APPRT_MAX                          (0xFFFFFFFFU)

/* SDPA_INHIBITSLEEP_ACK_SET */

#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_ACK_SET_APPRT_MASK               (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_ACK_SET_APPRT_SHIFT              (0x00000000U)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_ACK_SET_APPRT_MAX                (0xFFFFFFFFU)

/* SDPA_INHIBITSLEEP_ACK_CLR */

#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_ACK_CLR_APPRT_MASK               (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_ACK_CLR_APPRT_SHIFT              (0x00000000U)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_ACK_CLR_APPRT_MAX                (0xFFFFFFFFU)

/* SDPA_INHIBITSLEEP_PORT_STAT */

#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_PORT_STAT_APPRT_MASK             (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_PORT_STAT_APPRT_SHIFT            (0x00000000U)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_PORT_STAT_APPRT_MAX              (0xFFFFFFFFU)

/* SDPA_FORCEACTIVE_ACK_SET */

#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_ACK_SET_APPRT_MASK                (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_ACK_SET_APPRT_SHIFT               (0x00000000U)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_ACK_SET_APPRT_MAX                 (0xFFFFFFFFU)

/* SDPA_FORCEACTIVE_ACK_CLR */

#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_ACK_CLR_APPRT_MASK                (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_ACK_CLR_APPRT_SHIFT               (0x00000000U)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_ACK_CLR_APPRT_MAX                 (0xFFFFFFFFU)

/* SDPA_FORCEACTIVE_PORT_STAT */

#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_PORT_STAT_APPRT_MASK              (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_PORT_STAT_APPRT_SHIFT             (0x00000000U)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_PORT_STAT_APPRT_MAX               (0xFFFFFFFFU)

/* SDPA_INT_EN_SET */

#define CSL_VTM_CFG2_SDPA_INT_EN_SET_APPRT_MASK                         (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_INT_EN_SET_APPRT_SHIFT                        (0x00000000U)
#define CSL_VTM_CFG2_SDPA_INT_EN_SET_APPRT_MAX                          (0xFFFFFFFFU)

/* SDPA_INT_EN_CLR */

#define CSL_VTM_CFG2_SDPA_INT_EN_CLR_APPRT_MASK                         (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_INT_EN_CLR_APPRT_SHIFT                        (0x00000000U)
#define CSL_VTM_CFG2_SDPA_INT_EN_CLR_APPRT_MAX                          (0xFFFFFFFFU)

/* SDPA_INHIBITSLEEP_INT_RAW_STAT_SET */

#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_INT_RAW_STAT_SET_APPRT_MASK      (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_INT_RAW_STAT_SET_APPRT_SHIFT     (0x00000000U)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_INT_RAW_STAT_SET_APPRT_MAX       (0xFFFFFFFFU)

/* SDPA_INHIBITSLEEP_INT_EN_STAT_CLR */

#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_INT_EN_STAT_CLR_APPRT_MASK       (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_INT_EN_STAT_CLR_APPRT_SHIFT      (0x00000000U)
#define CSL_VTM_CFG2_SDPA_INHIBITSLEEP_INT_EN_STAT_CLR_APPRT_MAX        (0xFFFFFFFFU)

/* SDPA_FORCEACTIVE_INT_RAW_STAT_SET */

#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_INT_RAW_STAT_SET_APPRT_MASK       (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_INT_RAW_STAT_SET_APPRT_SHIFT      (0x00000000U)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_INT_RAW_STAT_SET_APPRT_MAX        (0xFFFFFFFFU)

/* SDPA_FORCEACTIVE_INT_EN_STAT_CLR */

#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_INT_EN_STAT_CLR_APPRT_MASK        (0xFFFFFFFFU)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_INT_EN_STAT_CLR_APPRT_SHIFT       (0x00000000U)
#define CSL_VTM_CFG2_SDPA_FORCEACTIVE_INT_EN_STAT_CLR_APPRT_MAX         (0xFFFFFFFFU)

#ifdef __cplusplus
}
#endif
#endif

