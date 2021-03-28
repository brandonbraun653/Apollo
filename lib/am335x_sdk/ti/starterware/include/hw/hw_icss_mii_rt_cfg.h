/*
* hw_icss_mii_rt_cfg.h
*
* Register-level header file for HW_ICSS_MII_RT_CFG
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
#ifndef HW_ICSS_MII_RT_CFG_H_
#define HW_ICSS_MII_RT_CFG_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define HW_ICSS_MII_RT_CFG_RXCFG0                              (0x0U)
#define HW_ICSS_MII_RT_CFG_RXCFG1                              (0x4U)
#define HW_ICSS_MII_RT_CFG_TXCFG0                              (0x10U)
#define HW_ICSS_MII_RT_CFG_TXCFG1                              (0x14U)
#define HW_ICSS_MII_RT_CFG_TX_CRC0                             (0x20U)
#define HW_ICSS_MII_RT_CFG_TX_CRC1                             (0x24U)
#define HW_ICSS_MII_RT_CFG_TX_IPG0                             (0x30U)
#define HW_ICSS_MII_RT_CFG_TX_IPG1                             (0x34U)
#define HW_ICSS_MII_RT_CFG_PRS0                                (0x38U)
#define HW_ICSS_MII_RT_CFG_PRS1                                (0x3cU)
#define HW_ICSS_MII_RT_CFG_RX_FRMS0                            (0x40U)
#define HW_ICSS_MII_RT_CFG_RX_FRMS1                            (0x44U)
#define HW_ICSS_MII_RT_CFG_RX_PCNT0                            (0x48U)
#define HW_ICSS_MII_RT_CFG_RX_PCNT1                            (0x4cU)
#define HW_ICSS_MII_RT_CFG_RX_ERR0                             (0x50U)
#define HW_ICSS_MII_RT_CFG_RX_ERR1                             (0x54U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_ENABLE_SHIFT              (0U)
#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_ENABLE_MASK               (0x00000001U)

#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_CUT_PREAMBLE_SHIFT        (2U)
#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_CUT_PREAMBLE_MASK         (0x00000004U)

#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_MUX_SEL_SHIFT             (3U)
#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_MUX_SEL_MASK              (0x00000008U)

#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_L2_EN_SHIFT               (4U)
#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_L2_EN_MASK                (0x00000010U)

#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_BYTE_SWAP_SHIFT           (5U)
#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_BYTE_SWAP_MASK            (0x00000020U)

#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_AUTO_FWD_PRE_SHIFT        (6U)
#define HW_ICSS_MII_RT_CFG_RXCFG0_RX_AUTO_FWD_PRE_MASK         (0x00000040U)

#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_ENABLE_SHIFT              (0U)
#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_ENABLE_MASK               (0x00000001U)

#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_CUT_PREAMBLE_SHIFT        (2U)
#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_CUT_PREAMBLE_MASK         (0x00000004U)

#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_MUX_SEL_SHIFT             (3U)
#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_MUX_SEL_MASK              (0x00000008U)

#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_L2_EN_SHIFT               (4U)
#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_L2_EN_MASK                (0x00000010U)

#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_BYTE_SWAP_SHIFT           (5U)
#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_BYTE_SWAP_MASK            (0x00000020U)

#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_AUTO_FWD_PRE_SHIFT        (6U)
#define HW_ICSS_MII_RT_CFG_RXCFG1_RX_AUTO_FWD_PRE_MASK         (0x00000040U)

#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_ENABLE_SHIFT              (0U)
#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_ENABLE_MASK               (0x00000001U)

#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_AUTO_PREAMBLE_SHIFT       (1U)
#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_AUTO_PREAMBLE_MASK        (0x00000002U)

#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_EN_MODE_SHIFT             (2U)
#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_EN_MODE_MASK              (0x00000004U)

#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_BYTE_SWAP_SHIFT           (3U)
#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_BYTE_SWAP_MASK            (0x00000008U)

#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_MUX_SEL_SHIFT             (8U)
#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_MUX_SEL_MASK              (0x00000100U)

#define HW_ICSS_MII_RT_CFG_TXCFG0_PRE_TX_AUTO_SEQUENCE_SHIFT   (9U)
#define HW_ICSS_MII_RT_CFG_TXCFG0_PRE_TX_AUTO_SEQUENCE_MASK    (0x00000200U)

#define HW_ICSS_MII_RT_CFG_TXCFG0_PRE_TX_AUTO_ESC_ERR_SHIFT    (10U)
#define HW_ICSS_MII_RT_CFG_TXCFG0_PRE_TX_AUTO_ESC_ERR_MASK     (0x00000400U)

#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_START_DELAY_SHIFT         (16U)
#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_START_DELAY_MASK          (0x03ff0000U)

#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_CLK_DELAY_SHIFT           (28U)
#define HW_ICSS_MII_RT_CFG_TXCFG0_TX_CLK_DELAY_MASK            (0x70000000U)

#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_ENABLE_SHIFT              (0U)
#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_ENABLE_MASK               (0x00000001U)

#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_AUTO_PREAMBLE_SHIFT       (1U)
#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_AUTO_PREAMBLE_MASK        (0x00000002U)

#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_EN_MODE_SHIFT             (2U)
#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_EN_MODE_MASK              (0x00000004U)

#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_BYTE_SWAP_SHIFT           (3U)
#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_BYTE_SWAP_MASK            (0x00000008U)

#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_MUX_SEL_SHIFT             (8U)
#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_MUX_SEL_MASK              (0x00000100U)

#define HW_ICSS_MII_RT_CFG_TXCFG1_PRE_TX_AUTO_SEQUENCE_SHIFT   (9U)
#define HW_ICSS_MII_RT_CFG_TXCFG1_PRE_TX_AUTO_SEQUENCE_MASK    (0x00000200U)

#define HW_ICSS_MII_RT_CFG_TXCFG1_PRE_TX_AUTO_ESC_ERR_SHIFT    (10U)
#define HW_ICSS_MII_RT_CFG_TXCFG1_PRE_TX_AUTO_ESC_ERR_MASK     (0x00000400U)

#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_START_DELAY_SHIFT         (16U)
#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_START_DELAY_MASK          (0x03ff0000U)

#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_CLK_DELAY_SHIFT           (28U)
#define HW_ICSS_MII_RT_CFG_TXCFG1_TX_CLK_DELAY_MASK            (0x70000000U)

#define HW_ICSS_MII_RT_CFG_TX_CRC0_CRC_SHIFT                   (0U)
#define HW_ICSS_MII_RT_CFG_TX_CRC0_CRC_MASK                    (0xffffffffU)

#define HW_ICSS_MII_RT_CFG_TX_CRC1_CRC_SHIFT                   (0U)
#define HW_ICSS_MII_RT_CFG_TX_CRC1_CRC_MASK                    (0xffffffffU)

#define HW_ICSS_MII_RT_CFG_TX_IPG0_IPG_SHIFT                   (0U)
#define HW_ICSS_MII_RT_CFG_TX_IPG0_IPG_MASK                    (0x000003ffU)

#define HW_ICSS_MII_RT_CFG_TX_IPG1_IPG_SHIFT                   (0U)
#define HW_ICSS_MII_RT_CFG_TX_IPG1_IPG_MASK                    (0x000003ffU)

#define HW_ICSS_MII_RT_CFG_PRS0_COL_SHIFT                      (0U)
#define HW_ICSS_MII_RT_CFG_PRS0_COL_MASK                       (0x00000001U)

#define HW_ICSS_MII_RT_CFG_PRS0_CRS_SHIFT                      (1U)
#define HW_ICSS_MII_RT_CFG_PRS0_CRS_MASK                       (0x00000002U)

#define HW_ICSS_MII_RT_CFG_PRS1_COL_SHIFT                      (0U)
#define HW_ICSS_MII_RT_CFG_PRS1_COL_MASK                       (0x00000001U)

#define HW_ICSS_MII_RT_CFG_PRS1_CRS_SHIFT                      (1U)
#define HW_ICSS_MII_RT_CFG_PRS1_CRS_MASK                       (0x00000002U)

#define HW_ICSS_MII_RT_CFG_RX_FRMS0_MIN_FRM_SHIFT              (0U)
#define HW_ICSS_MII_RT_CFG_RX_FRMS0_MIN_FRM_MASK               (0x0000ffffU)

#define HW_ICSS_MII_RT_CFG_RX_FRMS0_MAX_FRM_SHIFT              (16U)
#define HW_ICSS_MII_RT_CFG_RX_FRMS0_MAX_FRM_MASK               (0xffff0000U)

#define HW_ICSS_MII_RT_CFG_RX_FRMS1_MIN_FRM_SHIFT              (0U)
#define HW_ICSS_MII_RT_CFG_RX_FRMS1_MIN_FRM_MASK               (0x0000ffffU)

#define HW_ICSS_MII_RT_CFG_RX_FRMS1_MAX_FRM_SHIFT              (16U)
#define HW_ICSS_MII_RT_CFG_RX_FRMS1_MAX_FRM_MASK               (0xffff0000U)

#define HW_ICSS_MII_RT_CFG_RX_PCNT0_MIN_PCNT_SHIFT             (0U)
#define HW_ICSS_MII_RT_CFG_RX_PCNT0_MIN_PCNT_MASK              (0x0000000fU)

#define HW_ICSS_MII_RT_CFG_RX_PCNT0_MAX_PCNT_SHIFT             (4U)
#define HW_ICSS_MII_RT_CFG_RX_PCNT0_MAX_PCNT_MASK              (0x000000f0U)

#define HW_ICSS_MII_RT_CFG_RX_PCNT1_MIN_PCNT_SHIFT             (0U)
#define HW_ICSS_MII_RT_CFG_RX_PCNT1_MIN_PCNT_MASK              (0x0000000fU)

#define HW_ICSS_MII_RT_CFG_RX_PCNT1_MAX_PCNT_SHIFT             (4U)
#define HW_ICSS_MII_RT_CFG_RX_PCNT1_MAX_PCNT_MASK              (0x000000f0U)

#define HW_ICSS_MII_RT_CFG_RX_ERR0_MIN_PCNT_ERR_SHIFT          (0U)
#define HW_ICSS_MII_RT_CFG_RX_ERR0_MIN_PCNT_ERR_MASK           (0x00000001U)

#define HW_ICSS_MII_RT_CFG_RX_ERR0_MAX_PCNT_ERR_SHIFT          (1U)
#define HW_ICSS_MII_RT_CFG_RX_ERR0_MAX_PCNT_ERR_MASK           (0x00000002U)

#define HW_ICSS_MII_RT_CFG_RX_ERR0_MIN_FRM_ERR_SHIFT           (2U)
#define HW_ICSS_MII_RT_CFG_RX_ERR0_MIN_FRM_ERR_MASK            (0x00000004U)

#define HW_ICSS_MII_RT_CFG_RX_ERR0_MAX_FRM_ERR_SHIFT           (3U)
#define HW_ICSS_MII_RT_CFG_RX_ERR0_MAX_FRM_ERR_MASK            (0x00000008U)

#define HW_ICSS_MII_RT_CFG_RX_ERR1_MIN_PCNT_ERR_SHIFT          (0U)
#define HW_ICSS_MII_RT_CFG_RX_ERR1_MIN_PCNT_ERR_MASK           (0x00000001U)

#define HW_ICSS_MII_RT_CFG_RX_ERR1_MAX_PCNT_ERR_SHIFT          (1U)
#define HW_ICSS_MII_RT_CFG_RX_ERR1_MAX_PCNT_ERR_MASK           (0x00000002U)

#define HW_ICSS_MII_RT_CFG_RX_ERR1_MIN_FRM_ERR_SHIFT           (2U)
#define HW_ICSS_MII_RT_CFG_RX_ERR1_MIN_FRM_ERR_MASK            (0x00000004U)

#define HW_ICSS_MII_RT_CFG_RX_ERR1_MAX_FRM_ERR_SHIFT           (3U)
#define HW_ICSS_MII_RT_CFG_RX_ERR1_MAX_FRM_ERR_MASK            (0x00000008U)

#ifdef __cplusplus
}
#endif

#endif /* HW_ICSS_MII_RT_CFG_H_ */
