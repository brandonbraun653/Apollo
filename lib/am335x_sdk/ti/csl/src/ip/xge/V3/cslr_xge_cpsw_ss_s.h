/********************************************************************
 * Copyright (C) 2017-2019 Texas Instruments Incorporated.
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
 *  Name        : cslr_xge_cpsw_ss_s.h
*/
#ifndef CSLR_XGE_CPSW_SS_S_H_
#define CSLR_XGE_CPSW_SS_S_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : CPSW_NUSS Subsystem registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/


typedef struct {
    volatile uint32_t IDVER_REG;                 /* ID Version Register */
    volatile uint32_t SYNCE_COUNT_REG;           /* SyncE Count Register */
    volatile uint32_t SYNCE_MUX_REG;             /* SyncE Mux Register */
    volatile uint32_t CONTROL_REG;               /* Control Register */
    volatile uint32_t SGMII_MODE_REG;            /* SyncE Mux Register */
    volatile uint8_t  Resv_28[8];
    volatile uint32_t SUBSSYSTEM_STATUS_REG;     /* Subsystem Status Register */
    volatile uint8_t  Resv_48[16];
    volatile uint32_t RGMII_STATUS_REG;          /* RGMII Status Register */
} CSL_Xge_cpsw_ss_sRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_XGE_CPSW_SS_S_IDVER_REG                                            (0x00000000U)
#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG                                      (0x00000004U)
#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG                                        (0x00000008U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG                                          (0x0000000CU)
#define CSL_XGE_CPSW_SS_S_SGMII_MODE_REG                                       (0x00000010U)
#define CSL_XGE_CPSW_SS_S_SUBSSYSTEM_STATUS_REG                                (0x0000001CU)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG                                     (0x00000030U)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* IDVER_REG */

#define CSL_XGE_CPSW_SS_S_IDVER_REG_MINOR_VER_MASK                   (0x000000FFU)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MINOR_VER_SHIFT                  (0x00000000U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MINOR_VER_MAX                    (0x000000FFU)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_MAJOR_VER_MASK                   (0x00000700U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MAJOR_VER_SHIFT                  (0x00000008U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_MAJOR_VER_MAX                    (0x00000007U)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_RTL_VER_MASK                     (0x0000F800U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_RTL_VER_SHIFT                    (0x0000000BU)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_RTL_VER_MAX                      (0x0000001FU)

#define CSL_XGE_CPSW_SS_S_IDVER_REG_IDENT_MASK                       (0xFFFF0000U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_IDENT_SHIFT                      (0x00000010U)
#define CSL_XGE_CPSW_SS_S_IDVER_REG_IDENT_MAX                        (0x0000FFFFU)

/* SYNCE_COUNT_REG */

#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_SYNCE_CNT_MASK                       (0xFFFFFFFFU)
#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_SYNCE_CNT_SHIFT                      (0x00000000U)
#define CSL_XGE_CPSW_SS_S_SYNCE_COUNT_REG_SYNCE_CNT_MAX                        (0xFFFFFFFFU)

/* SYNCE_MUX_REG */

#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_SYNCE_SEL_MASK                         (0x0000003FU)
#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_SYNCE_SEL_SHIFT                        (0x00000000U)
#define CSL_XGE_CPSW_SS_S_SYNCE_MUX_REG_SYNCE_SEL_MAX                          (0x0000003FU)

/* CONTROL_REG */

#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_EN_MASK                              (0x00000001U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_EN_SHIFT                             (0x00000000U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_EN_MAX                               (0x00000001U)

#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_PHY_ONLY_MASK                        (0x00000002U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_PHY_ONLY_SHIFT                       (0x00000001U)
#define CSL_XGE_CPSW_SS_S_CONTROL_REG_EEE_PHY_ONLY_MAX                         (0x00000001U)

/* SGMII_MODE_REG */

#define CSL_XGE_CPSW_SS_S_SGMII_MODE_REG_SYNCE_SEL_MASK                        (0x00000001U)
#define CSL_XGE_CPSW_SS_S_SGMII_MODE_REG_SYNCE_SEL_SHIFT                       (0x00000000U)
#define CSL_XGE_CPSW_SS_S_SGMII_MODE_REG_SYNCE_SEL_MAX                         (0x00000001U)

/* RGMII_STATUS_REG */

#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_LINK_MASK                           (0x00000001U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_LINK_SHIFT                          (0x00000000U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_LINK_MAX                            (0x00000001U)

#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_SPEED_MASK                          (0x00000006U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_SPEED_SHIFT                         (0x00000001U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_SPEED_MAX                           (0x00000003U)

#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_FULLDUPLEX_MASK                     (0x00000008U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_FULLDUPLEX_SHIFT                    (0x00000003U)
#define CSL_XGE_CPSW_SS_S_RGMII_STATUS_REG_FULLDUPLEX_MAX                      (0x00000001U)

/* SUBSSYSTEM_STATUS_REG */

#define CSL_XGE_CPSW_SS_S_SUBSSYSTEM_STATUS_REG_EEE_CLKSTOP_ACK_MASK           (0x00000001U)
#define CSL_XGE_CPSW_SS_S_SUBSSYSTEM_STATUS_REG_EEE_CLKSTOP_ACK_SHIFT          (0x00000000U)
#define CSL_XGE_CPSW_SS_S_SUBSSYSTEM_STATUS_REG_EEE_CLKSTOP_ACK_MAX            (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif
