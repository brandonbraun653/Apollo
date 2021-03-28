/*
 *  Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
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

/**
 *  \file   hw_mpu_cm_core_aon.h
 *
 *  \brief  Register-level header file for PRCM
 *
**/

#ifndef HW_MPU_CM_CORE_AON_H_
#define HW_MPU_CM_CORE_AON_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define CM_MPU_CLKSTCTRL                                        (0x0U)
#define CM_MPU_STATICDEP                                        (0x4U)
#define CM_MPU_DYNAMICDEP                                       (0x8U)
#define CM_MPU_MPU_CLKCTRL                                      (0x20U)
#define CM_MPU_MPU_MPU_DBG_CLKCTRL                              (0x28U)


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define CM_MPU_CLKSTCTRL_CLKTRCTRL_SHIFT                        (0U)
#define CM_MPU_CLKSTCTRL_CLKTRCTRL_MASK                         (0x00000003U)
#define CM_MPU_CLKSTCTRL_CLKTRCTRL_NO_SLEEP                      (0U)
#define CM_MPU_CLKSTCTRL_CLKTRCTRL_RESERVED_1                    (1U)
#define CM_MPU_CLKSTCTRL_CLKTRCTRL_SW_WKUP                       (2U)
#define CM_MPU_CLKSTCTRL_CLKTRCTRL_HW_AUTO                       (3U)

#define CM_MPU_CLKSTCTRL_CLKACTIVITY_MPU_GCLK_SHIFT             (8U)
#define CM_MPU_CLKSTCTRL_CLKACTIVITY_MPU_GCLK_MASK              (0x00000100U)
#define CM_MPU_CLKSTCTRL_CLKACTIVITY_MPU_GCLK_INACT              (0U)
#define CM_MPU_CLKSTCTRL_CLKACTIVITY_MPU_GCLK_ACT                (1U)

#define CM_MPU_STATICDEP_IPU2_STATDEP_SHIFT                     (0U)
#define CM_MPU_STATICDEP_IPU2_STATDEP_MASK                      (0x00000001U)
#define CM_MPU_STATICDEP_IPU2_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_IPU2_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_DSP1_STATDEP_SHIFT                     (1U)
#define CM_MPU_STATICDEP_DSP1_STATDEP_MASK                      (0x00000002U)
#define CM_MPU_STATICDEP_DSP1_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_DSP1_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_IVA_STATDEP_SHIFT                      (2U)
#define CM_MPU_STATICDEP_IVA_STATDEP_MASK                       (0x00000004U)
#define CM_MPU_STATICDEP_IVA_STATDEP_ENABLED                     (1U)
#define CM_MPU_STATICDEP_IVA_STATDEP_DISABLED                    (0U)

#define CM_MPU_STATICDEP_EMIF_STATDEP_SHIFT                     (4U)
#define CM_MPU_STATICDEP_EMIF_STATDEP_MASK                      (0x00000010U)
#define CM_MPU_STATICDEP_EMIF_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_EMIF_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_L3MAIN1_STATDEP_SHIFT                  (5U)
#define CM_MPU_STATICDEP_L3MAIN1_STATDEP_MASK                   (0x00000020U)
#define CM_MPU_STATICDEP_L3MAIN1_STATDEP_ENABLED                 (1U)
#define CM_MPU_STATICDEP_L3MAIN1_STATDEP_DISABLED                (0U)

#define CM_MPU_STATICDEP_L3INIT_STATDEP_SHIFT                   (7U)
#define CM_MPU_STATICDEP_L3INIT_STATDEP_MASK                    (0x00000080U)
#define CM_MPU_STATICDEP_L3INIT_STATDEP_ENABLED                  (1U)
#define CM_MPU_STATICDEP_L3INIT_STATDEP_DISABLED                 (0U)

#define CM_MPU_STATICDEP_DSS_STATDEP_SHIFT                      (8U)
#define CM_MPU_STATICDEP_DSS_STATDEP_MASK                       (0x00000100U)
#define CM_MPU_STATICDEP_DSS_STATDEP_ENABLED                     (1U)
#define CM_MPU_STATICDEP_DSS_STATDEP_DISABLED                    (0U)

#define CM_MPU_STATICDEP_CAM_STATDEP_SHIFT                      (9U)
#define CM_MPU_STATICDEP_CAM_STATDEP_MASK                       (0x00000200U)
#define CM_MPU_STATICDEP_CAM_STATDEP_ENABLED                     (1U)
#define CM_MPU_STATICDEP_CAM_STATDEP_DISABLED                    (0U)

#define CM_MPU_STATICDEP_GPU_STATDEP_SHIFT                      (10U)
#define CM_MPU_STATICDEP_GPU_STATDEP_MASK                       (0x00000400U)
#define CM_MPU_STATICDEP_GPU_STATDEP_ENABLED                     (1U)
#define CM_MPU_STATICDEP_GPU_STATDEP_DISABLED                    (0U)

#define CM_MPU_STATICDEP_L4CFG_STATDEP_SHIFT                    (12U)
#define CM_MPU_STATICDEP_L4CFG_STATDEP_MASK                     (0x00001000U)
#define CM_MPU_STATICDEP_L4CFG_STATDEP_ENABLED                   (1U)
#define CM_MPU_STATICDEP_L4CFG_STATDEP_DISABLED                  (0U)

#define CM_MPU_STATICDEP_L4PER_STATDEP_SHIFT                    (13U)
#define CM_MPU_STATICDEP_L4PER_STATDEP_MASK                     (0x00002000U)
#define CM_MPU_STATICDEP_L4PER_STATDEP_ENABLED                   (1U)
#define CM_MPU_STATICDEP_L4PER_STATDEP_DISABLED                  (0U)

#define CM_MPU_STATICDEP_L4SEC_STATDEP_SHIFT                    (14U)
#define CM_MPU_STATICDEP_L4SEC_STATDEP_MASK                     (0x00004000U)
#define CM_MPU_STATICDEP_L4SEC_STATDEP_ENABLED                   (1U)
#define CM_MPU_STATICDEP_L4SEC_STATDEP_DISABLED                  (0U)

#define CM_MPU_STATICDEP_COREAON_STATDEP_SHIFT                  (16U)
#define CM_MPU_STATICDEP_COREAON_STATDEP_MASK                   (0x00010000U)
#define CM_MPU_STATICDEP_COREAON_STATDEP_DISABLED                (0U)

#define CM_MPU_STATICDEP_CUSTEFUSE_STATDEP_SHIFT                (17U)
#define CM_MPU_STATICDEP_CUSTEFUSE_STATDEP_MASK                 (0x00020000U)
#define CM_MPU_STATICDEP_CUSTEFUSE_STATDEP_DISABLED              (0U)

#define CM_MPU_STATICDEP_SDMA_STATDEP_SHIFT                     (11U)
#define CM_MPU_STATICDEP_SDMA_STATDEP_MASK                      (0x00000800U)
#define CM_MPU_STATICDEP_SDMA_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_WKUPAON_STATDEP_SHIFT                  (15U)
#define CM_MPU_STATICDEP_WKUPAON_STATDEP_MASK                   (0x00008000U)
#define CM_MPU_STATICDEP_WKUPAON_STATDEP_ENABLED                 (1U)
#define CM_MPU_STATICDEP_WKUPAON_STATDEP_DISABLED                (0U)

#define CM_MPU_STATICDEP_L4PER2_STATDEP_SHIFT                   (26U)
#define CM_MPU_STATICDEP_L4PER2_STATDEP_MASK                    (0x04000000U)
#define CM_MPU_STATICDEP_L4PER2_STATDEP_ENABLED                  (1U)
#define CM_MPU_STATICDEP_L4PER2_STATDEP_DISABLED                 (0U)

#define CM_MPU_STATICDEP_L4PER3_STATDEP_SHIFT                   (27U)
#define CM_MPU_STATICDEP_L4PER3_STATDEP_MASK                    (0x08000000U)
#define CM_MPU_STATICDEP_L4PER3_STATDEP_ENABLED                  (1U)
#define CM_MPU_STATICDEP_L4PER3_STATDEP_DISABLED                 (0U)

#define CM_MPU_STATICDEP_VPE_STATDEP_SHIFT                      (28U)
#define CM_MPU_STATICDEP_VPE_STATDEP_MASK                       (0x10000000U)
#define CM_MPU_STATICDEP_VPE_STATDEP_ENABLED                     (1U)
#define CM_MPU_STATICDEP_VPE_STATDEP_DISABLED                    (0U)

#define CM_MPU_STATICDEP_PCIE_STATDEP_SHIFT                     (29U)
#define CM_MPU_STATICDEP_PCIE_STATDEP_MASK                      (0x20000000U)
#define CM_MPU_STATICDEP_PCIE_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_PCIE_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_DSP2_STATDEP_SHIFT                     (18U)
#define CM_MPU_STATICDEP_DSP2_STATDEP_MASK                      (0x00040000U)
#define CM_MPU_STATICDEP_DSP2_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_DSP2_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_EVE1_STATDEP_SHIFT                     (19U)
#define CM_MPU_STATICDEP_EVE1_STATDEP_MASK                      (0x00080000U)
#define CM_MPU_STATICDEP_EVE1_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_EVE1_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_EVE2_STATDEP_SHIFT                     (20U)
#define CM_MPU_STATICDEP_EVE2_STATDEP_MASK                      (0x00100000U)
#define CM_MPU_STATICDEP_EVE2_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_EVE2_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_EVE3_STATDEP_SHIFT                     (21U)
#define CM_MPU_STATICDEP_EVE3_STATDEP_MASK                      (0x00200000U)
#define CM_MPU_STATICDEP_EVE3_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_EVE3_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_EVE4_STATDEP_SHIFT                     (22U)
#define CM_MPU_STATICDEP_EVE4_STATDEP_MASK                      (0x00400000U)
#define CM_MPU_STATICDEP_EVE4_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_EVE4_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_GMAC_STATDEP_SHIFT                     (25U)
#define CM_MPU_STATICDEP_GMAC_STATDEP_MASK                      (0x02000000U)
#define CM_MPU_STATICDEP_GMAC_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_GMAC_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_IPU1_STATDEP_SHIFT                     (23U)
#define CM_MPU_STATICDEP_IPU1_STATDEP_MASK                      (0x00800000U)
#define CM_MPU_STATICDEP_IPU1_STATDEP_ENABLED                    (1U)
#define CM_MPU_STATICDEP_IPU1_STATDEP_DISABLED                   (0U)

#define CM_MPU_STATICDEP_IPU_STATDEP_SHIFT                      (24U)
#define CM_MPU_STATICDEP_IPU_STATDEP_MASK                       (0x01000000U)
#define CM_MPU_STATICDEP_IPU_STATDEP_ENABLED                     (1U)
#define CM_MPU_STATICDEP_IPU_STATDEP_DISABLED                    (0U)

#define CM_MPU_DYNAMICDEP_EMIF_DYNDEP_SHIFT                     (4U)
#define CM_MPU_DYNAMICDEP_EMIF_DYNDEP_MASK                      (0x00000010U)
#define CM_MPU_DYNAMICDEP_EMIF_DYNDEP_ENABLED                    (1U)

#define CM_MPU_DYNAMICDEP_L3MAIN1_DYNDEP_SHIFT                  (5U)
#define CM_MPU_DYNAMICDEP_L3MAIN1_DYNDEP_MASK                   (0x00000020U)
#define CM_MPU_DYNAMICDEP_L3MAIN1_DYNDEP_ENABLED                 (1U)

#define CM_MPU_DYNAMICDEP_WINDOWSIZE_SHIFT                      (24U)
#define CM_MPU_DYNAMICDEP_WINDOWSIZE_MASK                       (0x0f000000U)

#define CM_MPU_MPU_CLKCTRL_MODULEMODE_SHIFT                     (0U)
#define CM_MPU_MPU_CLKCTRL_MODULEMODE_MASK                      (0x00000003U)
#define CM_MPU_MPU_CLKCTRL_MODULEMODE_AUTO                       (1U)

#define CM_MPU_MPU_CLKCTRL_STBYST_SHIFT                         (18U)
#define CM_MPU_MPU_CLKCTRL_STBYST_MASK                          (0x00040000U)
#define CM_MPU_MPU_CLKCTRL_STBYST_FUNC                           (0U)
#define CM_MPU_MPU_CLKCTRL_STBYST_STANDBY                        (1U)

#define CM_MPU_MPU_CLKCTRL_IDLEST_SHIFT                         (16U)
#define CM_MPU_MPU_CLKCTRL_IDLEST_MASK                          (0x00030000U)
#define CM_MPU_MPU_CLKCTRL_IDLEST_DISABLE                        (3U)
#define CM_MPU_MPU_CLKCTRL_IDLEST_IDLE                           (2U)
#define CM_MPU_MPU_CLKCTRL_IDLEST_FUNC                           (0U)
#define CM_MPU_MPU_CLKCTRL_IDLEST_TRANS                          (1U)

#define CM_MPU_MPU_CLKCTRL_CLKSEL_EMIF_DIV_MODE_SHIFT           (24U)
#define CM_MPU_MPU_CLKCTRL_CLKSEL_EMIF_DIV_MODE_MASK            (0x03000000U)
#define CM_MPU_MPU_CLKCTRL_CLKSEL_EMIF_DIV_MODE_DIV4A            (0U)
#define CM_MPU_MPU_CLKCTRL_CLKSEL_EMIF_DIV_MODE_DIV4             (1U)
#define CM_MPU_MPU_CLKCTRL_CLKSEL_EMIF_DIV_MODE_DIV8             (2U)
#define CM_MPU_MPU_CLKCTRL_CLKSEL_EMIF_DIV_MODE_DIV8B            (3U)

#define CM_MPU_MPU_CLKCTRL_CLKSEL_ABE_DIV_MODE_SHIFT            (26U)
#define CM_MPU_MPU_CLKCTRL_CLKSEL_ABE_DIV_MODE_MASK             (0x04000000U)
#define CM_MPU_MPU_CLKCTRL_CLKSEL_ABE_DIV_MODE_DIV8              (0U)
#define CM_MPU_MPU_CLKCTRL_CLKSEL_ABE_DIV_MODE_DIV16             (1U)

#define CM_MPU_MPU_MPU_DBG_CLKCTRL_IDLEST_SHIFT                 (16U)
#define CM_MPU_MPU_MPU_DBG_CLKCTRL_IDLEST_MASK                  (0x00030000U)
#define CM_MPU_MPU_MPU_DBG_CLKCTRL_IDLEST_DISABLE                (3U)
#define CM_MPU_MPU_MPU_DBG_CLKCTRL_IDLEST_IDLE                   (2U)
#define CM_MPU_MPU_MPU_DBG_CLKCTRL_IDLEST_FUNC                   (0U)
#define CM_MPU_MPU_MPU_DBG_CLKCTRL_IDLEST_TRANS                  (1U)

#define CM_MPU_MPU_MPU_DBG_CLKCTRL_MODULEMODE_SHIFT             (0U)
#define CM_MPU_MPU_MPU_DBG_CLKCTRL_MODULEMODE_MASK              (0x00000003U)
#define CM_MPU_MPU_MPU_DBG_CLKCTRL_MODULEMODE_AUTO               (1U)

#ifdef __cplusplus
}
#endif

#endif /* HW_MPU_CM_CORE_AON_H_ */

