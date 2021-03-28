/*
* hw_elm.h
*
* Register-level header file for ELM
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
#ifndef HW_ELM_H_
#define HW_ELM_H_

#ifdef __cplusplus
extern "C"
{
#endif


/****************************************************************************************************
* Register Definitions
****************************************************************************************************/
#define ELM_IRQSTS                                              (0x18U)
#define ELM_PAGE_CTRL                                           (0x80U)
#define ELM_IRQEN                                               (0x1cU)
#define ELM_SYSCONFIG                                           (0x10U)
#define ELM_LOCATION_CONFIG                                     (0x20U)
#define ELM_REVISION                                            (0x0U)
#define ELM_SYSSTS                                              (0x14U)
#define ELM_SYNDROME_FRAGMENT_1(m)                              ((uint32_t)0x404U + ((m) * 0x40U))
#define ELM_SYNDROME_FRAGMENT_1_NUM_ELEMS                       (8U)
#define ELM_SYNDROME_FRAGMENT_2(m)                              ((uint32_t)0x408U + ((m) * 0x40U))
#define ELM_SYNDROME_FRAGMENT_2_NUM_ELEMS                       (8U)
#define ELM_SYNDROME_FRAGMENT_4(m)                              ((uint32_t)0x410U + ((m) * 0x40U))
#define ELM_SYNDROME_FRAGMENT_4_NUM_ELEMS                       (8U)
#define ELM_SYNDROME_FRAGMENT_5(m)                              ((uint32_t)0x414U + ((m) * 0x40U))
#define ELM_SYNDROME_FRAGMENT_5_NUM_ELEMS                       (8U)
#define ELM_SYNDROME_FRAGMENT_3(m)                              ((uint32_t)0x40cU + ((m) * 0x40U))
#define ELM_SYNDROME_FRAGMENT_3_NUM_ELEMS                       (8U)
#define ELM_SYNDROME_FRAGMENT_6(m)                              ((uint32_t)0x418U + ((m) * 0x40U))
#define ELM_SYNDROME_FRAGMENT_6_NUM_ELEMS                       (8U)
#define ELM_SYNDROME_FRAGMENT_0(m)                              ((uint32_t)0x400U + ((m) * 0x40U))
#define ELM_SYNDROME_FRAGMENT_0_NUM_ELEMS                       (8U)
#define ELM_ERROR_LOCATION_5(m)                                 ((uint32_t)0x894U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_5_NUM_ELEMS                          (8U)
#define ELM_ERROR_LOCATION_14(m)                                ((uint32_t)0x8b8U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_14_NUM_ELEMS                         (8U)
#define ELM_ERROR_LOCATION_4(m)                                 ((uint32_t)0x890U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_4_NUM_ELEMS                          (8U)
#define ELM_ERROR_LOCATION_9(m)                                 ((uint32_t)0x8a4U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_9_NUM_ELEMS                          (8U)
#define ELM_ERROR_LOCATION_12(m)                                ((uint32_t)0x8b0U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_12_NUM_ELEMS                         (8U)
#define ELM_ERROR_LOCATION_7(m)                                 ((uint32_t)0x89cU + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_7_NUM_ELEMS                          (8U)
#define ELM_ERROR_LOCATION_1(m)                                 ((uint32_t)0x884U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_1_NUM_ELEMS                          (8U)
#define ELM_ERROR_LOCATION_0(m)                                 ((uint32_t)0x880U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_0_NUM_ELEMS                          (8U)
#define ELM_ERROR_LOCATION_8(m)                                 ((uint32_t)0x8a0U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_8_NUM_ELEMS                          (8U)
#define ELM_ERROR_LOCATION_13(m)                                ((uint32_t)0x8b4U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_13_NUM_ELEMS                         (8U)
#define ELM_LOCATION_STS(m)                                     ((uint32_t)0x800U + ((m) * 0x100U))
#define ELM_LOCATION_STS_NUM_ELEMS                              (8U)
#define ELM_ERROR_LOCATION_3(m)                                 ((uint32_t)0x88cU + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_3_NUM_ELEMS                          (8U)
#define ELM_ERROR_LOCATION_2(m)                                 ((uint32_t)0x888U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_2_NUM_ELEMS                          (8U)
#define ELM_ERROR_LOCATION_10(m)                                ((uint32_t)0x8a8U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_10_NUM_ELEMS                         (8U)
#define ELM_ERROR_LOCATION_6(m)                                 ((uint32_t)0x898U + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_6_NUM_ELEMS                          (8U)
#define ELM_ERROR_LOCATION_15(m)                                ((uint32_t)0x8bcU + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_15_NUM_ELEMS                         (8U)
#define ELM_ERROR_LOCATION_11(m)                                ((uint32_t)0x8acU + ((m) * 0x100U))
#define ELM_ERROR_LOCATION_11_NUM_ELEMS                         (8U)

#define ELM_SYNDROME_FRAGMENT(m,n)                              ((uint32_t)(0x400U + ((m) * 4U) + \
                                                                ((n) * 0x40U)))

#define ELM_ERROR_LOCATION(m,n)                                 ((uint32_t)(0x880U + ((m) * 4U) + \
                                                                ((m) * 0x100U)))


/****************************************************************************************************
* Field Definition Macros
****************************************************************************************************/

#define ELM_IRQSTS_LOC_VALID_0_SHIFT                            (0U)
#define ELM_IRQSTS_LOC_VALID_0_MASK                             (0x00000001U)
#define ELM_IRQSTS_LOC_VALID_0_COMPLETED                         (1U)
#define ELM_IRQSTS_LOC_VALID_0_NO_EFFECT                         (0U)
#define ELM_IRQSTS_LOC_VALID_0_NO_SYNDROME                       (0U)
#define ELM_IRQSTS_LOC_VALID_0_CLR_INT                           (1U)

#define ELM_IRQSTS_LOC_VALID_1_SHIFT                            (1U)
#define ELM_IRQSTS_LOC_VALID_1_MASK                             (0x00000002U)
#define ELM_IRQSTS_LOC_VALID_1_CLR_INT                           (1U)
#define ELM_IRQSTS_LOC_VALID_1_COMPLETED                         (1U)
#define ELM_IRQSTS_LOC_VALID_1_NO_SYNDROME                       (0U)
#define ELM_IRQSTS_LOC_VALID_1_NO_EFFECT                         (0U)

#define ELM_IRQSTS_LOC_VALID_2_SHIFT                            (2U)
#define ELM_IRQSTS_LOC_VALID_2_MASK                             (0x00000004U)
#define ELM_IRQSTS_LOC_VALID_2_CLR_INT                           (1U)
#define ELM_IRQSTS_LOC_VALID_2_COMPLETED                         (1U)
#define ELM_IRQSTS_LOC_VALID_2_NO_SYNDROME                       (0U)
#define ELM_IRQSTS_LOC_VALID_2_NO_EFFECT                         (0U)

#define ELM_IRQSTS_LOC_VALID_3_SHIFT                            (3U)
#define ELM_IRQSTS_LOC_VALID_3_MASK                             (0x00000008U)
#define ELM_IRQSTS_LOC_VALID_3_CLR_INT                           (1U)
#define ELM_IRQSTS_LOC_VALID_3_COMPLETED                         (1U)
#define ELM_IRQSTS_LOC_VALID_3_NO_SYNDROME                       (0U)
#define ELM_IRQSTS_LOC_VALID_3_NO_EFFECT                         (0U)

#define ELM_IRQSTS_LOC_VALID_4_SHIFT                            (4U)
#define ELM_IRQSTS_LOC_VALID_4_MASK                             (0x00000010U)
#define ELM_IRQSTS_LOC_VALID_4_CLR_INT                           (1U)
#define ELM_IRQSTS_LOC_VALID_4_COMPLETED                         (1U)
#define ELM_IRQSTS_LOC_VALID_4_NO_SYNDROME                       (0U)
#define ELM_IRQSTS_LOC_VALID_4_NO_EFFECT                         (0U)

#define ELM_IRQSTS_LOC_VALID_5_SHIFT                            (5U)
#define ELM_IRQSTS_LOC_VALID_5_MASK                             (0x00000020U)
#define ELM_IRQSTS_LOC_VALID_5_CLR_INT                           (1U)
#define ELM_IRQSTS_LOC_VALID_5_COMPLETED                         (1U)
#define ELM_IRQSTS_LOC_VALID_5_NO_SYNDROME                       (0U)
#define ELM_IRQSTS_LOC_VALID_5_NO_EFFECT                         (0U)

#define ELM_IRQSTS_LOC_VALID_6_SHIFT                            (6U)
#define ELM_IRQSTS_LOC_VALID_6_MASK                             (0x00000040U)
#define ELM_IRQSTS_LOC_VALID_6_CLR_INT                           (1U)
#define ELM_IRQSTS_LOC_VALID_6_COMPLETED                         (1U)
#define ELM_IRQSTS_LOC_VALID_6_NO_SYNDROME                       (0U)
#define ELM_IRQSTS_LOC_VALID_6_NO_EFFECT                         (0U)

#define ELM_IRQSTS_LOC_VALID_7_SHIFT                            (7U)
#define ELM_IRQSTS_LOC_VALID_7_MASK                             (0x00000080U)
#define ELM_IRQSTS_LOC_VALID_7_CLR_INT                           (1U)
#define ELM_IRQSTS_LOC_VALID_7_COMPLETED                         (1U)
#define ELM_IRQSTS_LOC_VALID_7_NO_SYNDROME                       (0U)
#define ELM_IRQSTS_LOC_VALID_7_NO_EFFECT                         (0U)

#define ELM_IRQSTS_PAGE_VALID_SHIFT                             (8U)
#define ELM_IRQSTS_PAGE_VALID_MASK                              (0x00000100U)
#define ELM_IRQSTS_PAGE_VALID_CLR_INT                            (1U)
#define ELM_IRQSTS_PAGE_VALID_INVALID                            (0U)
#define ELM_IRQSTS_PAGE_VALID                                    (1U)
#define ELM_IRQSTS_PAGE_VALID_NO_EFFECT                          (0U)

#define ELM_PAGE_CTRL_SECTOR_0_SHIFT                            (0U)
#define ELM_PAGE_CTRL_SECTOR_0_MASK                             (0x00000001U)

#define ELM_PAGE_CTRL_SECTOR_1_SHIFT                            (1U)
#define ELM_PAGE_CTRL_SECTOR_1_MASK                             (0x00000002U)

#define ELM_PAGE_CTRL_SECTOR_2_SHIFT                            (2U)
#define ELM_PAGE_CTRL_SECTOR_2_MASK                             (0x00000004U)

#define ELM_PAGE_CTRL_SECTOR_3_SHIFT                            (3U)
#define ELM_PAGE_CTRL_SECTOR_3_MASK                             (0x00000008U)

#define ELM_PAGE_CTRL_SECTOR_4_SHIFT                            (4U)
#define ELM_PAGE_CTRL_SECTOR_4_MASK                             (0x00000010U)

#define ELM_PAGE_CTRL_SECTOR_5_SHIFT                            (5U)
#define ELM_PAGE_CTRL_SECTOR_5_MASK                             (0x00000020U)

#define ELM_PAGE_CTRL_SECTOR_6_SHIFT                            (6U)
#define ELM_PAGE_CTRL_SECTOR_6_MASK                             (0x00000040U)

#define ELM_PAGE_CTRL_SECTOR_7_SHIFT                            (7U)
#define ELM_PAGE_CTRL_SECTOR_7_MASK                             (0x00000080U)

#define ELM_IRQEN_LOCATION_MASK_0_SHIFT                         (0U)
#define ELM_IRQEN_LOCATION_MASK_0_MASK                          (0x00000001U)
#define ELM_IRQEN_LOCATION_MASK_0_DISABLE                        (0U)
#define ELM_IRQEN_LOCATION_MASK_0_ENABLE                         (1U)

#define ELM_IRQEN_LOCATION_MASK_1_SHIFT                         (1U)
#define ELM_IRQEN_LOCATION_MASK_1_MASK                          (0x00000002U)
#define ELM_IRQEN_LOCATION_MASK_1_DISABLE                        (0U)
#define ELM_IRQEN_LOCATION_MASK_1_ENABLE                         (1U)

#define ELM_IRQEN_LOCATION_MASK_2_SHIFT                         (2U)
#define ELM_IRQEN_LOCATION_MASK_2_MASK                          (0x00000004U)
#define ELM_IRQEN_LOCATION_MASK_2_DISABLE                        (0U)
#define ELM_IRQEN_LOCATION_MASK_2_ENABLE                         (1U)

#define ELM_IRQEN_LOCATION_MASK_3_SHIFT                         (3U)
#define ELM_IRQEN_LOCATION_MASK_3_MASK                          (0x00000008U)
#define ELM_IRQEN_LOCATION_MASK_3_DISABLE                        (0U)
#define ELM_IRQEN_LOCATION_MASK_3_ENABLE                         (1U)

#define ELM_IRQEN_LOCATION_MASK_4_SHIFT                         (4U)
#define ELM_IRQEN_LOCATION_MASK_4_MASK                          (0x00000010U)
#define ELM_IRQEN_LOCATION_MASK_4_DISABLE                        (0U)
#define ELM_IRQEN_LOCATION_MASK_4_ENABLE                         (1U)

#define ELM_IRQEN_LOCATION_MASK_5_SHIFT                         (5U)
#define ELM_IRQEN_LOCATION_MASK_5_MASK                          (0x00000020U)
#define ELM_IRQEN_LOCATION_MASK_5_DISABLE                        (0U)
#define ELM_IRQEN_LOCATION_MASK_5_ENABLE                         (1U)

#define ELM_IRQEN_LOCATION_MASK_6_SHIFT                         (6U)
#define ELM_IRQEN_LOCATION_MASK_6_MASK                          (0x00000040U)
#define ELM_IRQEN_LOCATION_MASK_6_DISABLE                        (0U)
#define ELM_IRQEN_LOCATION_MASK_6_ENABLE                         (1U)

#define ELM_IRQEN_LOCATION_MASK_7_SHIFT                         (7U)
#define ELM_IRQEN_LOCATION_MASK_7_MASK                          (0x00000080U)
#define ELM_IRQEN_LOCATION_MASK_7_DISABLE                        (0U)
#define ELM_IRQEN_LOCATION_MASK_7_ENABLE                         (1U)

#define ELM_IRQEN_PAGE_MASK_SHIFT                               (8U)
#define ELM_IRQEN_PAGE_MASK_MASK                                (0x00000100U)
#define ELM_IRQEN_PAGE_MASK_DISABLE                              (0U)
#define ELM_IRQEN_PAGE_MASK_ENABLE                               (1U)

#define ELM_SYSCONFIG_AUTOGATING_SHIFT                          (0U)
#define ELM_SYSCONFIG_AUTOGATING_MASK                           (0x00000001U)
#define ELM_SYSCONFIG_AUTOGATING_OCP_FREE                        (0U)
#define ELM_SYSCONFIG_AUTOGATING_OCP_GATING                      (1U)

#define ELM_SYSCONFIG_SOFTRESET_SHIFT                           (1U)
#define ELM_SYSCONFIG_SOFTRESET_MASK                            (0x00000002U)
#define ELM_SYSCONFIG_SOFTRESET_RESET                            (1U)
#define ELM_SYSCONFIG_SOFTRESET_NORMAL                           (0U)

#define ELM_SYSCONFIG_SIDLEMODE_SHIFT                           (3U)
#define ELM_SYSCONFIG_SIDLEMODE_MASK                            (0x00000018U)
#define ELM_SYSCONFIG_SIDLEMODE_SMART_IDLE                       (2U)
#define ELM_SYSCONFIG_SIDLEMODE_FORCE_IDLE                       (0U)
#define ELM_SYSCONFIG_SIDLEMODE_NO_IDLE                          (1U)
#define ELM_SYSCONFIG_SIDLEMODE_RESERVED                         (3U)

#define ELM_SYSCONFIG_CLOCKACTIVITYOCPZ_SHIFT                   (8U)
#define ELM_SYSCONFIG_CLOCKACTIVITYOCPZ_MASK                    (0x00000100U)
#define ELM_SYSCONFIG_CLOCKACTIVITYOCPZ_OCP_OFF                  (0U)
#define ELM_SYSCONFIG_CLOCKACTIVITYOCPZ_OCP_ON                   (1U)

#define ELM_LOCATION_CONFIG_ECC_BCH_LEVEL_SHIFT                 (0U)
#define ELM_LOCATION_CONFIG_ECC_BCH_LEVEL_MASK                  (0x00000003U)
#define ELM_LOCATION_CONFIG_ECC_BCH_LEVEL_EIGHT_BITS             (1U)
#define ELM_LOCATION_CONFIG_ECC_BCH_LEVEL_SIXTEEN_BITS           (2U)
#define ELM_LOCATION_CONFIG_ECC_BCH_LEVEL_FOUR_BITS              (0U)
#define ELM_LOCATION_CONFIG_ECC_BCH_LEVEL_RESERVED               (3U)

#define ELM_LOCATION_CONFIG_ECC_SIZE_SHIFT                      (16U)
#define ELM_LOCATION_CONFIG_ECC_SIZE_MASK                       (0x07ff0000U)

#define ELM_REVISION_SHIFT                                      (0U)
#define ELM_REVISION_MASK                                       (0xffffffffU)

#define ELM_SYSSTS_RESETDONE_SHIFT                              (0U)
#define ELM_SYSSTS_RESETDONE_MASK                               (0x00000001U)
#define ELM_SYSSTS_RESETDONE_RST_DONE                            (1U)
#define ELM_SYSSTS_RESETDONE_RST_ONGOING                         (0U)

#define ELM_SYNDROME_FRAGMENT_1_SHIFT                           (0U)
#define ELM_SYNDROME_FRAGMENT_1_MASK                            (0xffffffffU)

#define ELM_SYNDROME_FRAGMENT_2_SHIFT                           (0U)
#define ELM_SYNDROME_FRAGMENT_2_MASK                            (0xffffffffU)

#define ELM_SYNDROME_FRAGMENT_4_SHIFT                           (0U)
#define ELM_SYNDROME_FRAGMENT_4_MASK                            (0xffffffffU)

#define ELM_SYNDROME_FRAGMENT_5_SHIFT                           (0U)
#define ELM_SYNDROME_FRAGMENT_5_MASK                            (0xffffffffU)

#define ELM_SYNDROME_FRAGMENT_3_SHIFT                           (0U)
#define ELM_SYNDROME_FRAGMENT_3_MASK                            (0xffffffffU)

#define ELM_SYNDROME_FRAGMENT_6_SHIFT                           (0U)
#define ELM_SYNDROME_FRAGMENT_6_MASK                            (0x0000ffffU)

#define ELM_SYNDROME_FRAGMENT_6_VALID_SHIFT                     (16U)
#define ELM_SYNDROME_FRAGMENT_6_VALID_MASK                      (0x00010000U)
#define ELM_SYNDROME_FRAGMENT_6_VALID_ENABLE_PROCESS            (1U)
#define ELM_SYNDROME_FRAGMENT_6_VALID_DISABLE_PROCESS           (0U)

#define ELM_SYNDROME_FRAGMENT_0_SHIFT                           (0U)
#define ELM_SYNDROME_FRAGMENT_0_MASK                            (0xffffffffU)

#define ELM_ERROR_LOCATION_5_ECC_SHIFT                          (0U)
#define ELM_ERROR_LOCATION_5_ECC_MASK                           (0x00001fffU)

#define ELM_ERROR_LOCATION_14_ECC_SHIFT                         (0U)
#define ELM_ERROR_LOCATION_14_ECC_MASK                          (0x00001fffU)

#define ELM_ERROR_LOCATION_4_ECC_SHIFT                          (0U)
#define ELM_ERROR_LOCATION_4_ECC_MASK                           (0x00001fffU)

#define ELM_ERROR_LOCATION_9_ECC_SHIFT                          (0U)
#define ELM_ERROR_LOCATION_9_ECC_MASK                           (0x00001fffU)

#define ELM_ERROR_LOCATION_12_ECC_SHIFT                         (0U)
#define ELM_ERROR_LOCATION_12_ECC_MASK                          (0x00001fffU)

#define ELM_ERROR_LOCATION_7_ECC_SHIFT                          (0U)
#define ELM_ERROR_LOCATION_7_ECC_MASK                           (0x00001fffU)

#define ELM_ERROR_LOCATION_1_ECC_SHIFT                          (0U)
#define ELM_ERROR_LOCATION_1_ECC_MASK                           (0x00001fffU)

#define ELM_ERROR_LOCATION_0_ECC_SHIFT                          (0U)
#define ELM_ERROR_LOCATION_0_ECC_MASK                           (0x00001fffU)

#define ELM_ERROR_LOCATION_8_ECC_SHIFT                          (0U)
#define ELM_ERROR_LOCATION_8_ECC_MASK                           (0x00001fffU)

#define ELM_ERROR_LOCATION_13_ECC_SHIFT                         (0U)
#define ELM_ERROR_LOCATION_13_ECC_MASK                          (0x00001fffU)

#define ELM_LOCATION_STS_ECC_NB_ERRORS_SHIFT                    (0U)
#define ELM_LOCATION_STS_ECC_NB_ERRORS_MASK                     (0x0000001fU)

#define ELM_LOCATION_STS_ECC_CORRECTABL_SHIFT                   (8U)
#define ELM_LOCATION_STS_ECC_CORRECTABL_MASK                    (0x00000100U)
#define ELM_LOCATION_STS_ECC_CORRECTABL_SUCCESS                  (1U)
#define ELM_LOCATION_STS_ECC_CORRECTABL_FAIL                     (0U)

#define ELM_ERROR_LOCATION_3_ECC_SHIFT                          (0U)
#define ELM_ERROR_LOCATION_3_ECC_MASK                           (0x00001fffU)

#define ELM_ERROR_LOCATION_2_ECC_SHIFT                          (0U)
#define ELM_ERROR_LOCATION_2_ECC_MASK                           (0x00001fffU)

#define ELM_ERROR_LOCATION_10_ECC_SHIFT                         (0U)
#define ELM_ERROR_LOCATION_10_ECC_MASK                          (0x00001fffU)

#define ELM_ERROR_LOCATION_6_ECC_SHIFT                          (0U)
#define ELM_ERROR_LOCATION_6_ECC_MASK                           (0x00001fffU)

#define ELM_ERROR_LOCATION_15_ECC_SHIFT                         (0U)
#define ELM_ERROR_LOCATION_15_ECC_MASK                          (0x00001fffU)

#define ELM_ERROR_LOCATION_11_ECC_SHIFT                         (0U)
#define ELM_ERROR_LOCATION_11_ECC_MASK                          (0x00001fffU)

#ifdef __cplusplus
}
#endif

#endif /* HW_ELM_H_ */

