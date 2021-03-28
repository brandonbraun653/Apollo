/********************************************************************
*
* SOC ISC PROPERTIES. header file
*
* Copyright (C) 2015-2019 Texas Instruments Incorporated.
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
#ifndef CSLR_SOC_ISC_H_
#define CSLR_SOC_ISC_H_

#include <ti/csl/cslr.h>
#include <ti/csl/tistdtypes.h>
#ifdef __cplusplus
extern "C"
{
#endif

/*
* Auto-generated CSL definitions for SoC ISC Instances:
*/

#define CSL_ISC_DEFAULT                                                                            (0U)
#define CSL_ISC_CC                                                                                 (1U)

/* Properties of firewall at master: WKUP_DMSC0_CBASS_0 */
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_I_MST_TYPE                                              (CSL_ISC_DEFAULT)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_I_MST_ID                                                (32U)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_I_MST_DEFAULT_PRIV_ID                                   (202U)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_I_MST_MMR_BASE                                          (0x45808000ul)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_I_MST_REGION_COUNT                                      (1U)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_D_MST_TYPE                                              (CSL_ISC_DEFAULT)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_D_MST_ID                                                (33U)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_D_MST_DEFAULT_PRIV_ID                                   (202U)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_D_MST_MMR_BASE                                          (0x45808400ul)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_D_MST_REGION_COUNT                                      (1U)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_S_MST_TYPE                                              (CSL_ISC_DEFAULT)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_S_MST_ID                                                (34U)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_S_MST_DEFAULT_PRIV_ID                                   (202U)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_S_MST_MMR_BASE                                          (0x45808800ul)
#define CSL_ISC_WKUP_DMSC0_CBASS_0_IQUASAR_S_MST_REGION_COUNT                                      (1U)

/* Properties of firewall at master: MCU_R5FSS0 */
#define CSL_ISC_MCU_R5FSS0_CPU0_RMST_TYPE                                                          (CSL_ISC_DEFAULT)
#define CSL_ISC_MCU_R5FSS0_CPU0_RMST_ID                                                            (64U)
#define CSL_ISC_MCU_R5FSS0_CPU0_RMST_DEFAULT_PRIV_ID                                               (96U)
#define CSL_ISC_MCU_R5FSS0_CPU0_RMST_MMR_BASE                                                      (0x45810000ul)
#define CSL_ISC_MCU_R5FSS0_CPU0_RMST_REGION_COUNT                                                  (4U)
#define CSL_ISC_MCU_R5FSS0_CPU0_WMST_TYPE                                                          (CSL_ISC_DEFAULT)
#define CSL_ISC_MCU_R5FSS0_CPU0_WMST_ID                                                            (65U)
#define CSL_ISC_MCU_R5FSS0_CPU0_WMST_DEFAULT_PRIV_ID                                               (96U)
#define CSL_ISC_MCU_R5FSS0_CPU0_WMST_MMR_BASE                                                      (0x45810400ul)
#define CSL_ISC_MCU_R5FSS0_CPU0_WMST_REGION_COUNT                                                  (4U)
#define CSL_ISC_MCU_R5FSS0_CPU0_PMST_TYPE                                                          (CSL_ISC_DEFAULT)
#define CSL_ISC_MCU_R5FSS0_CPU0_PMST_ID                                                            (66U)
#define CSL_ISC_MCU_R5FSS0_CPU0_PMST_DEFAULT_PRIV_ID                                               (96U)
#define CSL_ISC_MCU_R5FSS0_CPU0_PMST_MMR_BASE                                                      (0x45810800ul)
#define CSL_ISC_MCU_R5FSS0_CPU0_PMST_REGION_COUNT                                                  (4U)
#define CSL_ISC_MCU_R5FSS0_CPU1_RMST_TYPE                                                          (CSL_ISC_DEFAULT)
#define CSL_ISC_MCU_R5FSS0_CPU1_RMST_ID                                                            (68U)
#define CSL_ISC_MCU_R5FSS0_CPU1_RMST_DEFAULT_PRIV_ID                                               (97U)
#define CSL_ISC_MCU_R5FSS0_CPU1_RMST_MMR_BASE                                                      (0x45811000ul)
#define CSL_ISC_MCU_R5FSS0_CPU1_RMST_REGION_COUNT                                                  (4U)
#define CSL_ISC_MCU_R5FSS0_CPU1_WMST_TYPE                                                          (CSL_ISC_DEFAULT)
#define CSL_ISC_MCU_R5FSS0_CPU1_WMST_ID                                                            (69U)
#define CSL_ISC_MCU_R5FSS0_CPU1_WMST_DEFAULT_PRIV_ID                                               (97U)
#define CSL_ISC_MCU_R5FSS0_CPU1_WMST_MMR_BASE                                                      (0x45811400ul)
#define CSL_ISC_MCU_R5FSS0_CPU1_WMST_REGION_COUNT                                                  (4U)
#define CSL_ISC_MCU_R5FSS0_CPU1_PMST_TYPE                                                          (CSL_ISC_DEFAULT)
#define CSL_ISC_MCU_R5FSS0_CPU1_PMST_ID                                                            (70U)
#define CSL_ISC_MCU_R5FSS0_CPU1_PMST_DEFAULT_PRIV_ID                                               (97U)
#define CSL_ISC_MCU_R5FSS0_CPU1_PMST_MMR_BASE                                                      (0x45811800ul)
#define CSL_ISC_MCU_R5FSS0_CPU1_PMST_REGION_COUNT                                                  (4U)

/* Properties of firewall at master: MCU_SA2_UL0 */
#define CSL_ISC_MCU_SA2_UL0_CTXCACH_EXT_DMA_TYPE                                                   (CSL_ISC_DEFAULT)
#define CSL_ISC_MCU_SA2_UL0_CTXCACH_EXT_DMA_ID                                                     (76U)
#define CSL_ISC_MCU_SA2_UL0_CTXCACH_EXT_DMA_DEFAULT_PRIV_ID                                        (152U)
#define CSL_ISC_MCU_SA2_UL0_CTXCACH_EXT_DMA_MMR_BASE                                               (0x45813000ul)
#define CSL_ISC_MCU_SA2_UL0_CTXCACH_EXT_DMA_REGION_COUNT                                           (4U)

/* Properties of firewall at master: MCU_NAVSS0_PROXY0 */
#define CSL_ISC_MCU_NAVSS0_PROXY0_DST_TYPE                                                         (CSL_ISC_DEFAULT)
#define CSL_ISC_MCU_NAVSS0_PROXY0_DST_ID                                                           (96U)
#define CSL_ISC_MCU_NAVSS0_PROXY0_DST_DEFAULT_PRIV_ID                                              (80U)
#define CSL_ISC_MCU_NAVSS0_PROXY0_DST_MMR_BASE                                                     (0x45818000ul)
#define CSL_ISC_MCU_NAVSS0_PROXY0_DST_REGION_COUNT                                                 (1U)

/* Properties of firewall at master: MCU_NAVSS0_SEC_PROXY0 */
#define CSL_ISC_MCU_NAVSS0_SEC_PROXY0_DST_TYPE                                                     (CSL_ISC_DEFAULT)
#define CSL_ISC_MCU_NAVSS0_SEC_PROXY0_DST_ID                                                       (97U)
#define CSL_ISC_MCU_NAVSS0_SEC_PROXY0_DST_DEFAULT_PRIV_ID                                          (81U)
#define CSL_ISC_MCU_NAVSS0_SEC_PROXY0_DST_MMR_BASE                                                 (0x45818400ul)
#define CSL_ISC_MCU_NAVSS0_SEC_PROXY0_DST_REGION_COUNT                                             (1U)

/* Properties of firewall at master: MCU_NAVSS0_RINGACC0 */
#define CSL_ISC_MCU_NAVSS0_RINGACC0_RINGACC0_DST_TYPE                                              (CSL_ISC_DEFAULT)
#define CSL_ISC_MCU_NAVSS0_RINGACC0_RINGACC0_DST_ID                                                (98U)
#define CSL_ISC_MCU_NAVSS0_RINGACC0_RINGACC0_DST_DEFAULT_PRIV_ID                                   (82U)
#define CSL_ISC_MCU_NAVSS0_RINGACC0_RINGACC0_DST_MMR_BASE                                          (0x45818800ul)
#define CSL_ISC_MCU_NAVSS0_RINGACC0_RINGACC0_DST_REGION_COUNT                                      (1U)

/* Properties of firewall at master: NAVSS0_PROXY_0 */
#define CSL_ISC_NAVSS0_PROXY_0_DST_TYPE                                                            (CSL_ISC_DEFAULT)
#define CSL_ISC_NAVSS0_PROXY_0_DST_ID                                                              (256U)
#define CSL_ISC_NAVSS0_PROXY_0_DST_DEFAULT_PRIV_ID                                                 (64U)
#define CSL_ISC_NAVSS0_PROXY_0_DST_MMR_BASE                                                        (0x45840000ul)
#define CSL_ISC_NAVSS0_PROXY_0_DST_REGION_COUNT                                                    (1U)

/* Properties of firewall at master: NAVSS0_SEC_PROXY_0 */
#define CSL_ISC_NAVSS0_SEC_PROXY_0_DST_TYPE                                                        (CSL_ISC_DEFAULT)
#define CSL_ISC_NAVSS0_SEC_PROXY_0_DST_ID                                                          (257U)
#define CSL_ISC_NAVSS0_SEC_PROXY_0_DST_DEFAULT_PRIV_ID                                             (65U)
#define CSL_ISC_NAVSS0_SEC_PROXY_0_DST_MMR_BASE                                                    (0x45840400ul)
#define CSL_ISC_NAVSS0_SEC_PROXY_0_DST_REGION_COUNT                                                (1U)

/* Properties of firewall at master: R5FSS0 */
#define CSL_ISC_R5FSS0_PBDG_RMST0_TYPE                                                             (CSL_ISC_DEFAULT)
#define CSL_ISC_R5FSS0_PBDG_RMST0_ID                                                               (480U)
#define CSL_ISC_R5FSS0_PBDG_RMST0_DEFAULT_PRIV_ID                                                  (212U)
#define CSL_ISC_R5FSS0_PBDG_RMST0_MMR_BASE                                                         (0x45878000ul)
#define CSL_ISC_R5FSS0_PBDG_RMST0_REGION_COUNT                                                     (4U)
#define CSL_ISC_R5FSS0_PBDG_WMST0_TYPE                                                             (CSL_ISC_DEFAULT)
#define CSL_ISC_R5FSS0_PBDG_WMST0_ID                                                               (481U)
#define CSL_ISC_R5FSS0_PBDG_WMST0_DEFAULT_PRIV_ID                                                  (212U)
#define CSL_ISC_R5FSS0_PBDG_WMST0_MMR_BASE                                                         (0x45878400ul)
#define CSL_ISC_R5FSS0_PBDG_WMST0_REGION_COUNT                                                     (4U)
#define CSL_ISC_R5FSS0_PBDG_RMST1_TYPE                                                             (CSL_ISC_DEFAULT)
#define CSL_ISC_R5FSS0_PBDG_RMST1_ID                                                               (482U)
#define CSL_ISC_R5FSS0_PBDG_RMST1_DEFAULT_PRIV_ID                                                  (213U)
#define CSL_ISC_R5FSS0_PBDG_RMST1_MMR_BASE                                                         (0x45878800ul)
#define CSL_ISC_R5FSS0_PBDG_RMST1_REGION_COUNT                                                     (4U)
#define CSL_ISC_R5FSS0_PBDG_WMST1_TYPE                                                             (CSL_ISC_DEFAULT)
#define CSL_ISC_R5FSS0_PBDG_WMST1_ID                                                               (483U)
#define CSL_ISC_R5FSS0_PBDG_WMST1_DEFAULT_PRIV_ID                                                  (213U)
#define CSL_ISC_R5FSS0_PBDG_WMST1_MMR_BASE                                                         (0x45878c00ul)
#define CSL_ISC_R5FSS0_PBDG_WMST1_REGION_COUNT                                                     (4U)
#define CSL_ISC_R5FSS0_CPU0_RMST_TYPE                                                              (CSL_ISC_DEFAULT)
#define CSL_ISC_R5FSS0_CPU0_RMST_ID                                                                (800U)
#define CSL_ISC_R5FSS0_CPU0_RMST_DEFAULT_PRIV_ID                                                   (212U)
#define CSL_ISC_R5FSS0_CPU0_RMST_MMR_BASE                                                          (0x458c8000ul)
#define CSL_ISC_R5FSS0_CPU0_RMST_REGION_COUNT                                                      (4U)
#define CSL_ISC_R5FSS0_CPU0_WMST_TYPE                                                              (CSL_ISC_DEFAULT)
#define CSL_ISC_R5FSS0_CPU0_WMST_ID                                                                (801U)
#define CSL_ISC_R5FSS0_CPU0_WMST_DEFAULT_PRIV_ID                                                   (212U)
#define CSL_ISC_R5FSS0_CPU0_WMST_MMR_BASE                                                          (0x458c8400ul)
#define CSL_ISC_R5FSS0_CPU0_WMST_REGION_COUNT                                                      (4U)
#define CSL_ISC_R5FSS0_CPU1_RMST_TYPE                                                              (CSL_ISC_DEFAULT)
#define CSL_ISC_R5FSS0_CPU1_RMST_ID                                                                (802U)
#define CSL_ISC_R5FSS0_CPU1_RMST_DEFAULT_PRIV_ID                                                   (213U)
#define CSL_ISC_R5FSS0_CPU1_RMST_MMR_BASE                                                          (0x458c8800ul)
#define CSL_ISC_R5FSS0_CPU1_RMST_REGION_COUNT                                                      (4U)
#define CSL_ISC_R5FSS0_CPU1_WMST_TYPE                                                              (CSL_ISC_DEFAULT)
#define CSL_ISC_R5FSS0_CPU1_WMST_ID                                                                (803U)
#define CSL_ISC_R5FSS0_CPU1_WMST_DEFAULT_PRIV_ID                                                   (213U)
#define CSL_ISC_R5FSS0_CPU1_WMST_MMR_BASE                                                          (0x458c8c00ul)
#define CSL_ISC_R5FSS0_CPU1_WMST_REGION_COUNT                                                      (4U)

/* Properties of firewall at master: MMCSD0 */
#define CSL_ISC_MMCSD0_EMMCSS_RD_TYPE                                                              (CSL_ISC_DEFAULT)
#define CSL_ISC_MMCSD0_EMMCSS_RD_ID                                                                (520U)
#define CSL_ISC_MMCSD0_EMMCSS_RD_DEFAULT_PRIV_ID                                                   (128U)
#define CSL_ISC_MMCSD0_EMMCSS_RD_MMR_BASE                                                          (0x45882000ul)
#define CSL_ISC_MMCSD0_EMMCSS_RD_REGION_COUNT                                                      (1U)
#define CSL_ISC_MMCSD0_EMMCSS_WR_TYPE                                                              (CSL_ISC_DEFAULT)
#define CSL_ISC_MMCSD0_EMMCSS_WR_ID                                                                (521U)
#define CSL_ISC_MMCSD0_EMMCSS_WR_DEFAULT_PRIV_ID                                                   (128U)
#define CSL_ISC_MMCSD0_EMMCSS_WR_MMR_BASE                                                          (0x45882400ul)
#define CSL_ISC_MMCSD0_EMMCSS_WR_REGION_COUNT                                                      (1U)

/* Properties of firewall at master: MMCSD1 */
#define CSL_ISC_MMCSD1_EMMCSDSS_RD_TYPE                                                            (CSL_ISC_DEFAULT)
#define CSL_ISC_MMCSD1_EMMCSDSS_RD_ID                                                              (522U)
#define CSL_ISC_MMCSD1_EMMCSDSS_RD_DEFAULT_PRIV_ID                                                 (129U)
#define CSL_ISC_MMCSD1_EMMCSDSS_RD_MMR_BASE                                                        (0x45882800ul)
#define CSL_ISC_MMCSD1_EMMCSDSS_RD_REGION_COUNT                                                    (1U)
#define CSL_ISC_MMCSD1_EMMCSDSS_WR_TYPE                                                            (CSL_ISC_DEFAULT)
#define CSL_ISC_MMCSD1_EMMCSDSS_WR_ID                                                              (523U)
#define CSL_ISC_MMCSD1_EMMCSDSS_WR_DEFAULT_PRIV_ID                                                 (129U)
#define CSL_ISC_MMCSD1_EMMCSDSS_WR_MMR_BASE                                                        (0x45882c00ul)
#define CSL_ISC_MMCSD1_EMMCSDSS_WR_REGION_COUNT                                                    (1U)

/* Properties of firewall at master: COMPUTE_CLUSTER0 */
#define CSL_ISC_COMPUTE_CLUSTER0_GIC_MEM_RD_VBUSM_TYPE                                             (CSL_ISC_DEFAULT)
#define CSL_ISC_COMPUTE_CLUSTER0_GIC_MEM_RD_VBUSM_ID                                               (536U)
#define CSL_ISC_COMPUTE_CLUSTER0_GIC_MEM_RD_VBUSM_DEFAULT_PRIV_ID                                  (154U)
#define CSL_ISC_COMPUTE_CLUSTER0_GIC_MEM_RD_VBUSM_MMR_BASE                                         (0x45886000ul)
#define CSL_ISC_COMPUTE_CLUSTER0_GIC_MEM_RD_VBUSM_REGION_COUNT                                     (1U)
#define CSL_ISC_COMPUTE_CLUSTER0_GIC_MEM_WR_VBUSM_TYPE                                             (CSL_ISC_DEFAULT)
#define CSL_ISC_COMPUTE_CLUSTER0_GIC_MEM_WR_VBUSM_ID                                               (537U)
#define CSL_ISC_COMPUTE_CLUSTER0_GIC_MEM_WR_VBUSM_DEFAULT_PRIV_ID                                  (154U)
#define CSL_ISC_COMPUTE_CLUSTER0_GIC_MEM_WR_VBUSM_MMR_BASE                                         (0x45886400ul)
#define CSL_ISC_COMPUTE_CLUSTER0_GIC_MEM_WR_VBUSM_REGION_COUNT                                     (1U)

/* Properties of firewall at master: LED0 */
#define CSL_ISC_LED0_VBUSP_TYPE                                                                    (CSL_ISC_DEFAULT)
#define CSL_ISC_LED0_VBUSP_ID                                                                      (544U)
#define CSL_ISC_LED0_VBUSP_DEFAULT_PRIV_ID                                                         (176U)
#define CSL_ISC_LED0_VBUSP_MMR_BASE                                                                (0x45888000ul)
#define CSL_ISC_LED0_VBUSP_REGION_COUNT                                                            (1U)

/* Properties of firewall at master: USB0 */
#define CSL_ISC_USB0_MSTR0_TYPE                                                                    (CSL_ISC_DEFAULT)
#define CSL_ISC_USB0_MSTR0_ID                                                                      (611U)
#define CSL_ISC_USB0_MSTR0_DEFAULT_PRIV_ID                                                         (155U)
#define CSL_ISC_USB0_MSTR0_MMR_BASE                                                                (0x45898c00ul)
#define CSL_ISC_USB0_MSTR0_REGION_COUNT                                                            (8U)
#define CSL_ISC_USB0_MSTW0_TYPE                                                                    (CSL_ISC_DEFAULT)
#define CSL_ISC_USB0_MSTW0_ID                                                                      (612U)
#define CSL_ISC_USB0_MSTW0_DEFAULT_PRIV_ID                                                         (155U)
#define CSL_ISC_USB0_MSTW0_MMR_BASE                                                                (0x45899000ul)
#define CSL_ISC_USB0_MSTW0_REGION_COUNT                                                            (8U)

/* Properties of firewall at master: PCIE1 */
#define CSL_ISC_PCIE1_PCIE_MST_RD_TYPE                                                             (CSL_ISC_DEFAULT)
#define CSL_ISC_PCIE1_PCIE_MST_RD_ID                                                               (613U)
#define CSL_ISC_PCIE1_PCIE_MST_RD_DEFAULT_PRIV_ID                                                  (181U)
#define CSL_ISC_PCIE1_PCIE_MST_RD_MMR_BASE                                                         (0x45899400ul)
#define CSL_ISC_PCIE1_PCIE_MST_RD_REGION_COUNT                                                     (8U)
#define CSL_ISC_PCIE1_PCIE_MST_WR_TYPE                                                             (CSL_ISC_DEFAULT)
#define CSL_ISC_PCIE1_PCIE_MST_WR_ID                                                               (615U)
#define CSL_ISC_PCIE1_PCIE_MST_WR_DEFAULT_PRIV_ID                                                  (181U)
#define CSL_ISC_PCIE1_PCIE_MST_WR_MMR_BASE                                                         (0x45899c00ul)
#define CSL_ISC_PCIE1_PCIE_MST_WR_REGION_COUNT                                                     (8U)

/* Properties of firewall at master: DEBUGSS_WRAP0 */
#define CSL_ISC_DEBUGSS_WRAP0_VBUSMR_TYPE                                                          (CSL_ISC_DEFAULT)
#define CSL_ISC_DEBUGSS_WRAP0_VBUSMR_ID                                                            (640U)
#define CSL_ISC_DEBUGSS_WRAP0_VBUSMR_DEFAULT_PRIV_ID                                               (177U)
#define CSL_ISC_DEBUGSS_WRAP0_VBUSMR_MMR_BASE                                                      (0x458a0000ul)
#define CSL_ISC_DEBUGSS_WRAP0_VBUSMR_REGION_COUNT                                                  (1U)
#define CSL_ISC_DEBUGSS_WRAP0_VBUSMW_TYPE                                                          (CSL_ISC_DEFAULT)
#define CSL_ISC_DEBUGSS_WRAP0_VBUSMW_ID                                                            (641U)
#define CSL_ISC_DEBUGSS_WRAP0_VBUSMW_DEFAULT_PRIV_ID                                               (177U)
#define CSL_ISC_DEBUGSS_WRAP0_VBUSMW_MMR_BASE                                                      (0x458a0400ul)
#define CSL_ISC_DEBUGSS_WRAP0_VBUSMW_REGION_COUNT                                                  (1U)

/* Properties of firewall at master: NAVSS0_RINGACC_0 */
#define CSL_ISC_NAVSS0_RINGACC_0_DST_TYPE                                                          (CSL_ISC_DEFAULT)
#define CSL_ISC_NAVSS0_RINGACC_0_DST_ID                                                            (832U)
#define CSL_ISC_NAVSS0_RINGACC_0_DST_DEFAULT_PRIV_ID                                               (74U)
#define CSL_ISC_NAVSS0_RINGACC_0_DST_MMR_BASE                                                      (0x458d0000ul)
#define CSL_ISC_NAVSS0_RINGACC_0_DST_REGION_COUNT                                                  (1U)

#ifdef __cplusplus
}
#endif
#endif /* CSLR_SOC_ISC_H_ */

