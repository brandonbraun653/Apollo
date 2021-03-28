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
 *  Name        : cslr_dptx.h
*/
#ifndef CSLR_DPTX_H_
#define CSLR_DPTX_H_

#ifdef __cplusplus
extern "C"
{
#endif
#include <ti/csl/cslr.h>
#include <stdint.h>

/**************************************************************************
* Hardware Region  : MMR Registers
**************************************************************************/


/**************************************************************************
* Register Overlay Structure
**************************************************************************/

typedef struct {
    volatile uint32_t REVISION;                  /* revision */
    volatile uint32_t DPTX_IPCFG;                /* dptx_ipcfg */
    volatile uint32_t ECC_MEM_CFG;               /* ecc_mem_cfg */
    volatile uint32_t DPTX_DSC_CFG;              /* dptx_dsc_cfg */
    volatile uint32_t DPTX_SRC_CFG;              /* dptx_src_cfg */
    volatile uint32_t DPTX_VIF_SECURE_MODE_CFG;   /* dptx_vif_secure_mode_cfg */
    volatile uint32_t DPTX_VIF_CONN_STATUS;      /* dptx_vif_conn_status */
    volatile uint32_t PHY_CLK_STATUS;            /* phy_clk_status */
} CSL_dptxRegs;


/**************************************************************************
* Register Macros
**************************************************************************/

#define CSL_DPTX_REVISION                                                      (0x00000000U)
#define CSL_DPTX_DPTX_IPCFG                                                    (0x00000004U)
#define CSL_DPTX_ECC_MEM_CFG                                                   (0x00000008U)
#define CSL_DPTX_DPTX_DSC_CFG                                                  (0x0000000CU)
#define CSL_DPTX_DPTX_SRC_CFG                                                  (0x00000010U)
#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG                                      (0x00000014U)
#define CSL_DPTX_DPTX_VIF_CONN_STATUS                                          (0x00000018U)
#define CSL_DPTX_PHY_CLK_STATUS                                                (0x0000001CU)

/**************************************************************************
* Field Definition Macros
**************************************************************************/


/* REVISION */

#define CSL_DPTX_REVISION_SCHEME_MASK                                          (0xC0000000U)
#define CSL_DPTX_REVISION_SCHEME_SHIFT                                         (0x0000001EU)
#define CSL_DPTX_REVISION_SCHEME_MAX                                           (0x00000003U)

#define CSL_DPTX_REVISION_BU_MASK                                              (0x30000000U)
#define CSL_DPTX_REVISION_BU_SHIFT                                             (0x0000001CU)
#define CSL_DPTX_REVISION_BU_MAX                                               (0x00000003U)

#define CSL_DPTX_REVISION_FUNC_MASK                                            (0x0FFF0000U)
#define CSL_DPTX_REVISION_FUNC_SHIFT                                           (0x00000010U)
#define CSL_DPTX_REVISION_FUNC_MAX                                             (0x00000FFFU)

#define CSL_DPTX_REVISION_RTL_MASK                                             (0x0000F800U)
#define CSL_DPTX_REVISION_RTL_SHIFT                                            (0x0000000BU)
#define CSL_DPTX_REVISION_RTL_MAX                                              (0x0000001FU)

#define CSL_DPTX_REVISION_MAJOR_MASK                                           (0x00000700U)
#define CSL_DPTX_REVISION_MAJOR_SHIFT                                          (0x00000008U)
#define CSL_DPTX_REVISION_MAJOR_MAX                                            (0x00000007U)

#define CSL_DPTX_REVISION_CUSTOM_MASK                                          (0x000000C0U)
#define CSL_DPTX_REVISION_CUSTOM_SHIFT                                         (0x00000006U)
#define CSL_DPTX_REVISION_CUSTOM_MAX                                           (0x00000003U)

#define CSL_DPTX_REVISION_MINOR_MASK                                           (0x0000003FU)
#define CSL_DPTX_REVISION_MINOR_SHIFT                                          (0x00000000U)
#define CSL_DPTX_REVISION_MINOR_MAX                                            (0x0000003FU)

/* DPTX_IPCFG */

#define CSL_DPTX_DPTX_IPCFG_FW_MEM_CLK_EN_MASK                                 (0x00000002U)
#define CSL_DPTX_DPTX_IPCFG_FW_MEM_CLK_EN_SHIFT                                (0x00000001U)
#define CSL_DPTX_DPTX_IPCFG_FW_MEM_CLK_EN_MAX                                  (0x00000001U)

#define CSL_DPTX_DPTX_IPCFG_APB_SECURE_REG_BLOCK_EN_MASK                       (0x00000001U)
#define CSL_DPTX_DPTX_IPCFG_APB_SECURE_REG_BLOCK_EN_SHIFT                      (0x00000000U)
#define CSL_DPTX_DPTX_IPCFG_APB_SECURE_REG_BLOCK_EN_MAX                        (0x00000001U)

/* ECC_MEM_CFG */

#define CSL_DPTX_ECC_MEM_CFG_CLK_EN_MASK                                       (0x00000001U)
#define CSL_DPTX_ECC_MEM_CFG_CLK_EN_SHIFT                                      (0x00000000U)
#define CSL_DPTX_ECC_MEM_CFG_CLK_EN_MAX                                        (0x00000001U)

/* DPTX_DSC_CFG */

#define CSL_DPTX_DPTX_DSC_CFG_DSC_1_10BPC_MASK                                 (0x00000020U)
#define CSL_DPTX_DPTX_DSC_CFG_DSC_1_10BPC_SHIFT                                (0x00000005U)
#define CSL_DPTX_DPTX_DSC_CFG_DSC_1_10BPC_MAX                                  (0x00000001U)

#define CSL_DPTX_DPTX_DSC_CFG_DSC_0_10BPC_MASK                                 (0x00000010U)
#define CSL_DPTX_DPTX_DSC_CFG_DSC_0_10BPC_SHIFT                                (0x00000004U)
#define CSL_DPTX_DPTX_DSC_CFG_DSC_0_10BPC_MAX                                  (0x00000001U)

#define CSL_DPTX_DPTX_DSC_CFG_BOTH_CLK_EN_MASK                                 (0x00000008U)
#define CSL_DPTX_DPTX_DSC_CFG_BOTH_CLK_EN_SHIFT                                (0x00000003U)
#define CSL_DPTX_DPTX_DSC_CFG_BOTH_CLK_EN_MAX                                  (0x00000001U)

#define CSL_DPTX_DPTX_DSC_CFG_SPLIT_PANEL_EN_MASK                              (0x00000004U)
#define CSL_DPTX_DPTX_DSC_CFG_SPLIT_PANEL_EN_SHIFT                             (0x00000002U)
#define CSL_DPTX_DPTX_DSC_CFG_SPLIT_PANEL_EN_MAX                               (0x00000001U)

#define CSL_DPTX_DPTX_DSC_CFG_MODE_SEL_MASK                                    (0x00000003U)
#define CSL_DPTX_DPTX_DSC_CFG_MODE_SEL_SHIFT                                   (0x00000000U)
#define CSL_DPTX_DPTX_DSC_CFG_MODE_SEL_MAX                                     (0x00000003U)

/* DPTX_SRC_CFG */

#define CSL_DPTX_DPTX_SRC_CFG_VIF_FMT_SEL_MASK                                 (0xF0000000U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_FMT_SEL_SHIFT                                (0x0000001CU)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_FMT_SEL_MAX                                  (0x0000000FU)

#define CSL_DPTX_DPTX_SRC_CFG_AIF_EN_MASK                                      (0x00010000U)
#define CSL_DPTX_DPTX_SRC_CFG_AIF_EN_SHIFT                                     (0x00000010U)
#define CSL_DPTX_DPTX_SRC_CFG_AIF_EN_MAX                                       (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_3_IN30B_MASK                                 (0x00000800U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_3_IN30B_SHIFT                                (0x0000000BU)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_3_IN30B_MAX                                  (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_2_IN30B_MASK                                 (0x00000400U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_2_IN30B_SHIFT                                (0x0000000AU)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_2_IN30B_MAX                                  (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_1_IN30B_MASK                                 (0x00000200U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_1_IN30B_SHIFT                                (0x00000009U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_1_IN30B_MAX                                  (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_0_IN30B_MASK                                 (0x00000100U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_0_IN30B_SHIFT                                (0x00000008U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_0_IN30B_MAX                                  (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_3_SEL_MASK                                   (0x00000080U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_3_SEL_SHIFT                                  (0x00000007U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_3_SEL_MAX                                    (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_2_SEL_MASK                                   (0x00000040U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_2_SEL_SHIFT                                  (0x00000006U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_2_SEL_MAX                                    (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_1_SEL_MASK                                   (0x00000020U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_1_SEL_SHIFT                                  (0x00000005U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_1_SEL_MAX                                    (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_0_SEL_MASK                                   (0x00000010U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_0_SEL_SHIFT                                  (0x00000004U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_0_SEL_MAX                                    (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_3_EN_MASK                                    (0x00000008U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_3_EN_SHIFT                                   (0x00000003U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_3_EN_MAX                                     (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_2_EN_MASK                                    (0x00000004U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_2_EN_SHIFT                                   (0x00000002U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_2_EN_MAX                                     (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_1_EN_MASK                                    (0x00000002U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_1_EN_SHIFT                                   (0x00000001U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_1_EN_MAX                                     (0x00000001U)

#define CSL_DPTX_DPTX_SRC_CFG_VIF_0_EN_MASK                                    (0x00000001U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_0_EN_SHIFT                                   (0x00000000U)
#define CSL_DPTX_DPTX_SRC_CFG_VIF_0_EN_MAX                                     (0x00000001U)

/* DPTX_VIF_SECURE_MODE_CFG */

#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_3_MASK                           (0x00000008U)
#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_3_SHIFT                          (0x00000003U)
#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_3_MAX                            (0x00000001U)

#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_2_MASK                           (0x00000004U)
#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_2_SHIFT                          (0x00000002U)
#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_2_MAX                            (0x00000001U)

#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_1_MASK                           (0x00000002U)
#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_1_SHIFT                          (0x00000001U)
#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_1_MAX                            (0x00000001U)

#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_0_MASK                           (0x00000001U)
#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_0_SHIFT                          (0x00000000U)
#define CSL_DPTX_DPTX_VIF_SECURE_MODE_CFG_VIF_0_MAX                            (0x00000001U)

/* DPTX_VIF_CONN_STATUS */

#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_3_MASK                               (0x00000008U)
#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_3_SHIFT                              (0x00000003U)
#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_3_MAX                                (0x00000001U)

#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_2_MASK                               (0x00000004U)
#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_2_SHIFT                              (0x00000002U)
#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_2_MAX                                (0x00000001U)

#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_1_MASK                               (0x00000002U)
#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_1_SHIFT                              (0x00000001U)
#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_1_MAX                                (0x00000001U)

#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_0_MASK                               (0x00000001U)
#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_0_SHIFT                              (0x00000000U)
#define CSL_DPTX_DPTX_VIF_CONN_STATUS_VIF_0_MAX                                (0x00000001U)

/* PHY_CLK_STATUS */

#define CSL_DPTX_PHY_CLK_STATUS_VALID_MASK                                     (0x00000001U)
#define CSL_DPTX_PHY_CLK_STATUS_VALID_SHIFT                                    (0x00000000U)
#define CSL_DPTX_PHY_CLK_STATUS_VALID_MAX                                      (0x00000001U)

#ifdef __cplusplus
}
#endif
#endif
