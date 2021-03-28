/*
* hw_cpsw_wr.h
*
* Register-level header file for CPSW_WR
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

#ifndef HW_CPSW_WR_H_
#define HW_CPSW_WR_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/

#define CPSW_WR_C_RX_STAT(n)                                        (0x44U + ((n) * 0x10U))
#define CPSW_WR_C_RX_THRESH_STAT(n)                                 (0x40U + ((n) * 0x10U))
#define CPSW_WR_C_RX_EN(n)                                          (0x14U + ((n) * 0x10U))
#define CPSW_WR_C_RX_THRESH_EN(n)                                   (0x10U + ((n) * 0x10U))
#define CPSW_WR_C_RX_IMAX(n)                                        (0x70U + ((n) * 0x8U))
#define CPSW_WR_C_MISC_EN(n)                                        (0x1cU + ((n) * 0x10U))
#define CPSW_WR_CTRL                                                (0x8U)
#define CPSW_WR_SOFT_RESET                                          (0x4U)
#define CPSW_WR_C_TX_STAT(n)                                        (0x48U + ((n) * 0x10U))
#define CPSW_WR_IDVER                                               (0x0U)
#define CPSW_WR_RGMII_CTL                                           (0x88U)
#define CPSW_WR_C_TX_EN(n)                                          (0x18U + ((n) * 0x10U))
#define CPSW_WR_C_MISC_STAT(n)                                      (0x4cU + ((n) * 0x10U))
#define CPSW_WR_C_TX_IMAX(n)                                        (0x74U + ((n) * 0x8U))
#define CPSW_WR_INT_CTRL                                            (0xcU)

/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CPSW_WR_C_RX_STAT_SHIFT                                                         (0U)
#define CPSW_WR_C_RX_STAT_MASK                                                          (0x000000ffU)

#define CPSW_WR_C_RX_THRESH_STAT_SHIFT                                                  (0U)
#define CPSW_WR_C_RX_THRESH_STAT_MASK                                                   (0x000000ffU)

#define CPSW_WR_C_RX_EN_SHIFT                                                           (0U)
#define CPSW_WR_C_RX_EN_MASK                                                            (0x000000ffU)

#define CPSW_WR_C_RX_THRESH_EN_SHIFT                                                    (0U)
#define CPSW_WR_C_RX_THRESH_EN_MASK                                                     (0x000000ffU)

#define CPSW_WR_C_RX_IMAX_SHIFT                                                         (0U)
#define CPSW_WR_C_RX_IMAX_MASK                                                          (0x0000003fU)

#define CPSW_WR_C_MISC_EN_SHIFT                                                         (0U)
#define CPSW_WR_C_MISC_EN_MASK                                                          (0x0000001fU)
#define CPSW_WR_C_MISC_EN_EVT_PEND                                                       (0x10U)
#define CPSW_WR_C_MISC_EN_STS_PEND                                                       (0x08U)
#define CPSW_WR_C_MISC_EN_HOST_PEND                                                      (0x04U)
#define CPSW_WR_C_MISC_EN_MDIO_LINK                                                      (0x02U)
#define CPSW_WR_C_MISC_EN_MDIO_USER                                                      (0x01U)

#define CPSW_WR_CTRL_MMR_IDLEMODE_SHIFT                                                 (0U)
#define CPSW_WR_CTRL_MMR_IDLEMODE_MASK                                                  (0x00000003U)
#define CPSW_WR_CTRL_MMR_IDLEMODE_EN_0X1                                                 (1U)
#define CPSW_WR_CTRL_MMR_IDLEMODE_EN_0X2                                                 (2U)
#define CPSW_WR_CTRL_MMR_IDLEMODE_EN_0X3                                                 (3U)
#define CPSW_WR_CTRL_MMR_IDLEMODE_EN_0X0                                                 (0U)

#define CPSW_WR_CTRL_MMR_STDBYMODE_SHIFT                                                (2U)
#define CPSW_WR_CTRL_MMR_STDBYMODE_MASK                                                 (0x0000000cU)
#define CPSW_WR_CTRL_MMR_STDBYMODE_EN_0X0                                                (0U)
#define CPSW_WR_CTRL_MMR_STDBYMODE_EN_0X2                                                (2U)
#define CPSW_WR_CTRL_MMR_STDBYMODE_EN_0X3                                                (3U)
#define CPSW_WR_CTRL_MMR_STDBYMODE_EN_0X1                                                (1U)

#define CPSW_WR_SOFT_RESET_SHIFT                                                        (0U)
#define CPSW_WR_SOFT_RESET_MASK                                                         (0x00000001U)
#define CPSW_WR_SOFT_RESET_IN_PROGRESS                                                   (1U)
#define CPSW_WR_SOFT_RESET_DONE                                                          (0U)

#define CPSW_WR_C_TX_STAT_SHIFT                                                         (0U)
#define CPSW_WR_C_TX_STAT_MASK                                                          (0x000000ffU)

#define CPSW_WR_IDVER_MINOR_SHIFT                                                       (0U)
#define CPSW_WR_IDVER_MINOR_MASK                                                        (0x0000003fU)

#define CPSW_WR_IDVER_CUSTOM_SHIFT                                                      (6U)
#define CPSW_WR_IDVER_CUSTOM_MASK                                                       (0x000000c0U)

#define CPSW_WR_IDVER_MAJOR_SHIFT                                                       (8U)
#define CPSW_WR_IDVER_MAJOR_MASK                                                        (0x00000700U)

#define CPSW_WR_IDVER_RTL_SHIFT                                                         (11U)
#define CPSW_WR_IDVER_RTL_MASK                                                          (0x0000f800U)

#define CPSW_WR_IDVER_FUNCTION_SHIFT                                                    (16U)
#define CPSW_WR_IDVER_FUNCTION_MASK                                                     (0x0fff0000U)

#define CPSW_WR_IDVER_SCHEME_SHIFT                                                      (30U)
#define CPSW_WR_IDVER_SCHEME_MASK                                                       (0xc0000000U)

#define CPSW_WR_RGMII_CTL_RGMII1_LINK_SHIFT                                             (0U)
#define CPSW_WR_RGMII_CTL_RGMII1_LINK_MASK                                              (0x00000001U)

#define CPSW_WR_RGMII_CTL_RGMII1_SPEED_SHIFT                                            (1U)
#define CPSW_WR_RGMII_CTL_RGMII1_SPEED_MASK                                             (0x00000006U)

#define CPSW_WR_RGMII_CTL_RGMII1_FULLDUPLEX_SHIFT                                       (3U)
#define CPSW_WR_RGMII_CTL_RGMII1_FULLDUPLEX_MASK                                        (0x00000008U)

#define CPSW_WR_RGMII_CTL_RGMII2_LINK_SHIFT                                             (4U)
#define CPSW_WR_RGMII_CTL_RGMII2_LINK_MASK                                              (0x00000010U)

#define CPSW_WR_RGMII_CTL_RGMII2_SPEED_SHIFT                                            (5U)
#define CPSW_WR_RGMII_CTL_RGMII2_SPEED_MASK                                             (0x00000060U)

#define CPSW_WR_RGMII_CTL_RGMII2_FULLDUPLEX_SHIFT                                       (7U)
#define CPSW_WR_RGMII_CTL_RGMII2_FULLDUPLEX_MASK                                        (0x00000080U)

#define CPSW_WR_C_TX_EN_SHIFT                                                           (0U)
#define CPSW_WR_C_TX_EN_MASK                                                            (0x000000ffU)

#define CPSW_WR_C_MISC_STAT_SHIFT                                                       (0U)
#define CPSW_WR_C_MISC_STAT_MASK                                                        (0x0000001fU)

#define CPSW_WR_C_TX_IMAX_SHIFT                                                         (0U)
#define CPSW_WR_C_TX_IMAX_MASK                                                          (0x0000003fU)

#define CPSW_WR_INT_CTRL_PRESCALE_SHIFT                                                 (0U)
#define CPSW_WR_INT_CTRL_PRESCALE_MASK                                                  (0x00000fffU)

#define CPSW_WR_INT_CTRL_PACE_EN_SHIFT                                                  (16U)
#define CPSW_WR_INT_CTRL_PACE_EN_MASK                                                   (0x003f0000U)

#define CPSW_WR_INT_CTRL_TEST_SHIFT                                                     (31U)
#define CPSW_WR_INT_CTRL_TEST_MASK                                                      (0x80000000U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_CPSW_WR_H_ */

