/*
* hw_pl310.h
*
* Register-level header file for PL310
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

#ifndef HW_PL310_H_
#define HW_PL310_H_

#ifdef __cplusplus
extern "C"
{
#endif

#define PL310_CACHEID                                               (0x0U)
#define PL310_CACHETYPE                                             (0x4U)
#define PL310_CTRL                                                  (0x100U)
#define PL310_AUX_CTRL                                              (0x104U)
#define PL310_TAG_RAM_LAT_CTRL                                      (0x108U)
#define PL310_DATA_RAM_LAT_CTRL                                     (0x10cU)
#define PL310_EVT_CTR_CTRL                                          (0x200U)
#define PL310_EVT_CTR1_CONFIG                                       (0x204U)
#define PL310_EVT_CTR0_CONFIG                                       (0x208U)
#define PL310_EVT_CTR1_VALUE                                        (0x20cU)
#define PL310_EVT_CTR0_VALUE                                        (0x210U)
#define PL310_INTR_MASK                                             (0x214U)
#define PL310_MASKED_INTR_STS                                       (0x218U)
#define PL310_RAW_INTR_STS                                          (0x21cU)
#define PL310_INTR_CLR                                              (0x220U)
#define PL310_CACHE_SYNC                                            (0x730U)
#define PL310_INV_LINE_BY_PA                                        (0x770U)
#define PL310_INV_BY_WAY                                            (0x77cU)
#define PL310_CLEAN_LINE_BY_PA                                      (0x7b0U)
#define PL310_CLEAN_LINE_BY_IDX                                     (0x7b8U)
#define PL310_CLEAN_BY_WAY                                          (0x7bcU)
#define PL310_CLEAN_AND_INV_LINE_BY_PA                              (0x7f0U)
#define PL310_CLEAN_AND_INV_LINE_BY_IDX                             (0x7f8U)
#define PL310_CLEAN_AND_INV_BY_WAY                                  (0x7fcU)
#define PL310_DATA_LOCKDOWN_BY_WAY(m)                               (0x900U + ((m) * 0x8U))
#define PL310_INSTR_LOCKDOWN_BY_WAY(m)                              (0x904U + ((m) * 0x8U))
#define PL310_LOCKDOWN_BY_LINE_EN                                   (0x950U)
#define PL310_UNLOCK_ALL_LINES_BY_WAY                               (0x954U)
#define PL310_ADDR_FILTERING_START                                  (0xc00U)
#define PL310_ADDR_FILTERING_END                                    (0xc04U)
#define PL310_DBG_CTRL                                              (0xf40U)
#define PL310_PREFETCH_OFFSET                                       (0xf60U)
#define PL310_POWER_CTRL                                            (0xf80U)

/****************************************************************************************************
* Field Definition Macros 
****************************************************************************************************/

#define PL310_CACHEID_IMPLEMENTER_SHIFT                                                 (24U)
#define PL310_CACHEID_IMPLEMENTER_MASK                                                  (0xff000000U)

#define PL310_CACHEID_SHIFT                                                             (10U)
#define PL310_CACHEID_MASK                                                              (0x0000fc00U)

#define PL310_CACHEID_PART_NUMBER_SHIFT                                                 (6U)
#define PL310_CACHEID_PART_NUMBER_MASK                                                  (0x000003c0U)

#define PL310_CACHEID_RTL_RELEASE_SHIFT                                                 (0U)
#define PL310_CACHEID_RTL_RELEASE_MASK                                                  (0x0000003fU)

#define PL310_CACHETYPE_SBZ1_SHIFT                                                      (29U)
#define PL310_CACHETYPE_SBZ1_MASK                                                       (0x60000000U)

#define PL310_CACHETYPE_CTYPE_SHIFT                                                     (25U)
#define PL310_CACHETYPE_CTYPE_MASK                                                      (0x1e000000U)

#define PL310_CACHETYPE_H_SHIFT                                                         (24U)
#define PL310_CACHETYPE_H_MASK                                                          (0x01000000U)

#define PL310_CACHETYPE_DSIZE_L2_CACHE_WAY_SIZE_SHIFT                                   (20U)
#define PL310_CACHETYPE_DSIZE_L2_CACHE_WAY_SIZE_MASK                                    (0x00700000U)

#define PL310_CACHETYPE_DSIZE_SBZORRAZ1_SHIFT                                           (23U)
#define PL310_CACHETYPE_DSIZE_SBZORRAZ1_MASK                                            (0x00800000U)

#define PL310_CACHETYPE_DSIZE_SBZORRAZ2_SHIFT                                           (19U)
#define PL310_CACHETYPE_DSIZE_SBZORRAZ2_MASK                                            (0x00080000U)

#define PL310_CACHETYPE_L2_ASSOCIATIVITY1_SHIFT                                         (18U)
#define PL310_CACHETYPE_L2_ASSOCIATIVITY1_MASK                                          (0x00040000U)

#define PL310_CACHETYPE_SBZ2_SHIFT                                                      (14U)
#define PL310_CACHETYPE_SBZ2_MASK                                                       (0x0003c000U)

#define PL310_CACHETYPE_L2_CACHE_LINE_LENGTH_SHIFT                                      (12U)
#define PL310_CACHETYPE_L2_CACHE_LINE_LENGTH_MASK                                       (0x00003000U)

#define PL310_CACHETYPE_ISIZE_SBZORRAZ1_SHIFT                                           (11U)
#define PL310_CACHETYPE_ISIZE_SBZORRAZ1_MASK                                            (0x00000800U)

#define PL310_CACHETYPE_ISIZE_L2_CACHE_WAY_SIZE_SHIFT                                   (8U)
#define PL310_CACHETYPE_ISIZE_L2_CACHE_WAY_SIZE_MASK                                    (0x00000700U)

#define PL310_CACHETYPE_ISIZE_SBZORRAZ2_SHIFT                                           (7U)
#define PL310_CACHETYPE_ISIZE_SBZORRAZ2_MASK                                            (0x00000080U)

#define PL310_CACHETYPE_L2_ASSOCIATIVITY2_SHIFT                                         (6U)
#define PL310_CACHETYPE_L2_ASSOCIATIVITY2_MASK                                          (0x00000040U)

#define PL310_CACHETYPE_SBZ3_SHIFT                                                      (2U)
#define PL310_CACHETYPE_SBZ3_MASK                                                       (0x0000003cU)

#define PL310_CACHETYPE_L2_CACHE_LINE_LENGHT_SHIFT                                      (0U)
#define PL310_CACHETYPE_L2_CACHE_LINE_LENGHT_MASK                                       (0x00000003U)

#define PL310_CACHETYPE_DATA_BANKING_SHIFT                                              (31U)
#define PL310_CACHETYPE_DATA_BANKING_MASK                                               (0x80000000U)

#define PL310_CTRL_L2_CACHE_EANBLE_SHIFT                                                (0U)
#define PL310_CTRL_L2_CACHE_EANBLE_MASK                                                 (0x00000001U)

#define PL310_AUX_CTRL_EXCLUSIVE_CACHE_CONFIG_SHIFT                                     (12U)
#define PL310_AUX_CTRL_EXCLUSIVE_CACHE_CONFIG_MASK                                      (0x00001000U)

#define PL310_AUX_CTRL_ASSOCIATIVITY_SHIFT                                              (16U)
#define PL310_AUX_CTRL_ASSOCIATIVITY_MASK                                               (0x00010000U)

#define PL310_AUX_CTRL_WAY_SIZE_SHIFT                                                   (17U)
#define PL310_AUX_CTRL_WAY_SIZE_MASK                                                    (0x000e0000U)

#define PL310_AUX_CTRL_EVT_MONITOR_BUS_EN_SHIFT                                         (20U)
#define PL310_AUX_CTRL_EVT_MONITOR_BUS_EN_MASK                                          (0x00100000U)

#define PL310_AUX_CTRL_PARITY_EN_SHIFT                                                  (21U)
#define PL310_AUX_CTRL_PARITY_EN_MASK                                                   (0x00200000U)

#define PL310_AUX_CTRL_SHARED_ATTR_OVERRIDE_EN_SHIFT                                    (22U)
#define PL310_AUX_CTRL_SHARED_ATTR_OVERRIDE_EN_MASK                                     (0x00400000U)

#define PL310_AUX_CTRL_FORCE_WRITE_ALLOCATE_SHIFT                                       (23U)
#define PL310_AUX_CTRL_FORCE_WRITE_ALLOCATE_MASK                                        (0x01800000U)

#define PL310_AUX_CTRL_CACHE_REPLACEMENT_POLICY_SHIFT                                   (25U)
#define PL310_AUX_CTRL_CACHE_REPLACEMENT_POLICY_MASK                                    (0x02000000U)

#define PL310_AUX_CTRL_NS_LOCKDOWN_EN_SHIFT                                             (26U)
#define PL310_AUX_CTRL_NS_LOCKDOWN_EN_MASK                                              (0x04000000U)

#define PL310_AUX_CTRL_NS_INTR_ACCESS_SHIFT                                             (27U)
#define PL310_AUX_CTRL_NS_INTR_ACCESS_MASK                                              (0x08000000U)

#define PL310_AUX_CTRL_DATA_PREFETCH_EN_SHIFT                                           (28U)
#define PL310_AUX_CTRL_DATA_PREFETCH_EN_MASK                                            (0x10000000U)

#define PL310_AUX_CTRL_INSTR_PREFETCH_EN_SHIFT                                          (29U)
#define PL310_AUX_CTRL_INSTR_PREFETCH_EN_MASK                                           (0x20000000U)

#define PL310_AUX_CTRL_FULL_LINE_OF_ZERO_EN_SHIFT                                       (0U)
#define PL310_AUX_CTRL_FULL_LINE_OF_ZERO_EN_MASK                                        (0x00000001U)

#define PL310_AUX_CTRL_HIGH_PRIORITY_SO_AND_DEV_READS_EN_SHIFT                          (10U)
#define PL310_AUX_CTRL_HIGH_PRIORITY_SO_AND_DEV_READS_EN_MASK                           (0x00000400U)

#define PL310_AUX_CTRL_STORE_BUFFER_DEVICE_LIMITATION_EN_SHIFT                          (11U)
#define PL310_AUX_CTRL_STORE_BUFFER_DEVICE_LIMITATION_EN_MASK                           (0x00000800U)

#define PL310_AUX_CTRL_SHARED_BUFFER_DEVICE_LIMITATION_EN_SHIFT                         (13U)
#define PL310_AUX_CTRL_SHARED_BUFFER_DEVICE_LIMITATION_EN_MASK                          (0x00002000U)

#define PL310_AUX_CTRL_EARLY_BRESP_EN_SHIFT                                             (30U)
#define PL310_AUX_CTRL_EARLY_BRESP_EN_MASK                                              (0x40000000U)

#define PL310_TAG_RAM_LAT_CTRL_SETUP_SHIFT                                              (0U)
#define PL310_TAG_RAM_LAT_CTRL_SETUP_MASK                                               (0x00000007U)

#define PL310_TAG_RAM_LAT_CTRL_READ_ACCESS_SHIFT                                        (4U)
#define PL310_TAG_RAM_LAT_CTRL_READ_ACCESS_MASK                                         (0x00000070U)

#define PL310_TAG_RAM_LAT_CTRL_WRITE_ACCESS_SHIFT                                       (8U)
#define PL310_TAG_RAM_LAT_CTRL_WRITE_ACCESS_MASK                                        (0x00000700U)

#define PL310_DATA_RAM_LAT_CTRL_SETUP_SHIFT                                             (0U)
#define PL310_DATA_RAM_LAT_CTRL_SETUP_MASK                                              (0x00000007U)

#define PL310_DATA_RAM_LAT_CTRL_READ_ACCESS_SHIFT                                       (4U)
#define PL310_DATA_RAM_LAT_CTRL_READ_ACCESS_MASK                                        (0x00000070U)

#define PL310_DATA_RAM_LAT_CTRL_WRITE_ACCESS_SHIFT                                      (8U)
#define PL310_DATA_RAM_LAT_CTRL_WRITE_ACCESS_MASK                                       (0x00000700U)

#define PL310_EVT_CTR_CTRL_EN_SHIFT                                                     (0U)
#define PL310_EVT_CTR_CTRL_EN_MASK                                                      (0x00000001U)

#define PL310_EVT_CTR_CTRL_RESET_SHIFT                                                  (1U)
#define PL310_EVT_CTR_CTRL_RESET_MASK                                                   (0x00000006U)

#define PL310_EVT_CTR1_CONFIG_INTR_GENERATION_SHIFT                                     (0U)
#define PL310_EVT_CTR1_CONFIG_INTR_GENERATION_MASK                                      (0x00000003U)

#define PL310_EVT_CTR1_CONFIG_SOURCE_SHIFT                                              (2U)
#define PL310_EVT_CTR1_CONFIG_SOURCE_MASK                                               (0x0000003cU)

#define PL310_EVT_CTR0_CONFIG_INTR_GENERATION_SHIFT                                     (0U)
#define PL310_EVT_CTR0_CONFIG_INTR_GENERATION_MASK                                      (0x00000003U)

#define PL310_EVT_CTR0_CONFIG_SOURCE_SHIFT                                              (2U)
#define PL310_EVT_CTR0_CONFIG_SOURCE_MASK                                               (0x0000003cU)

#define PL310_EVT_CTR1_VALUE_SHIFT                                                      (0U)
#define PL310_EVT_CTR1_VALUE_MASK                                                       (0xffffffffU)

#define PL310_EVT_CTR0_VALUE_SHIFT                                                      (0U)
#define PL310_EVT_CTR0_VALUE_MASK                                                       (0xffffffffU)

#define PL310_INTR_MASK_ECNTR_SHIFT                                                     (0U)
#define PL310_INTR_MASK_ECNTR_MASK                                                      (0x00000001U)

#define PL310_INTR_MASK_PARRT_SHIFT                                                     (1U)
#define PL310_INTR_MASK_PARRT_MASK                                                      (0x00000002U)

#define PL310_INTR_MASK_PARRD_SHIFT                                                     (2U)
#define PL310_INTR_MASK_PARRD_MASK                                                      (0x00000004U)

#define PL310_INTR_MASK_ERRWT_SHIFT                                                     (3U)
#define PL310_INTR_MASK_ERRWT_MASK                                                      (0x00000008U)

#define PL310_INTR_MASK_ERRWD_SHIFT                                                     (4U)
#define PL310_INTR_MASK_ERRWD_MASK                                                      (0x00000010U)

#define PL310_INTR_MASK_ERRRT_SHIFT                                                     (5U)
#define PL310_INTR_MASK_ERRRT_MASK                                                      (0x00000020U)

#define PL310_INTR_MASK_ERRRD_SHIFT                                                     (6U)
#define PL310_INTR_MASK_ERRRD_MASK                                                      (0x00000040U)

#define PL310_INTR_MASK_SLVERR_SHIFT                                                    (7U)
#define PL310_INTR_MASK_SLVERR_MASK                                                     (0x00000080U)

#define PL310_INTR_MASK_DECERR_SHIFT                                                    (8U)
#define PL310_INTR_MASK_DECERR_MASK                                                     (0x00000100U)

#define PL310_MASKED_INTR_STS_ECNTR_SHIFT                                               (0U)
#define PL310_MASKED_INTR_STS_ECNTR_MASK                                                (0x00000001U)

#define PL310_MASKED_INTR_STS_PARRT_SHIFT                                               (1U)
#define PL310_MASKED_INTR_STS_PARRT_MASK                                                (0x00000002U)

#define PL310_MASKED_INTR_STS_PARRD_SHIFT                                               (2U)
#define PL310_MASKED_INTR_STS_PARRD_MASK                                                (0x00000004U)

#define PL310_MASKED_INTR_STS_ERRWT_SHIFT                                               (3U)
#define PL310_MASKED_INTR_STS_ERRWT_MASK                                                (0x00000008U)

#define PL310_MASKED_INTR_STS_ERRWD_SHIFT                                               (4U)
#define PL310_MASKED_INTR_STS_ERRWD_MASK                                                (0x00000010U)

#define PL310_MASKED_INTR_STS_ERRRT_SHIFT                                               (5U)
#define PL310_MASKED_INTR_STS_ERRRT_MASK                                                (0x00000020U)

#define PL310_MASKED_INTR_STS_ERRRD_SHIFT                                               (6U)
#define PL310_MASKED_INTR_STS_ERRRD_MASK                                                (0x00000040U)

#define PL310_MASKED_INTR_STS_SLVERR_SHIFT                                              (7U)
#define PL310_MASKED_INTR_STS_SLVERR_MASK                                               (0x00000080U)

#define PL310_MASKED_INTR_STS_DECERR_SHIFT                                              (8U)
#define PL310_MASKED_INTR_STS_DECERR_MASK                                               (0x00000100U)

#define PL310_RAW_INTR_STS_ECNTR_SHIFT                                                  (0U)
#define PL310_RAW_INTR_STS_ECNTR_MASK                                                   (0x00000001U)

#define PL310_RAW_INTR_STS_PARRT_SHIFT                                                  (1U)
#define PL310_RAW_INTR_STS_PARRT_MASK                                                   (0x00000002U)

#define PL310_RAW_INTR_STS_PARRD_SHIFT                                                  (2U)
#define PL310_RAW_INTR_STS_PARRD_MASK                                                   (0x00000004U)

#define PL310_RAW_INTR_STS_ERRWT_SHIFT                                                  (3U)
#define PL310_RAW_INTR_STS_ERRWT_MASK                                                   (0x00000008U)

#define PL310_RAW_INTR_STS_ERRWD_SHIFT                                                  (4U)
#define PL310_RAW_INTR_STS_ERRWD_MASK                                                   (0x00000010U)

#define PL310_RAW_INTR_STS_ERRRT_SHIFT                                                  (5U)
#define PL310_RAW_INTR_STS_ERRRT_MASK                                                   (0x00000020U)

#define PL310_RAW_INTR_STS_ERRRD_SHIFT                                                  (6U)
#define PL310_RAW_INTR_STS_ERRRD_MASK                                                   (0x00000040U)

#define PL310_RAW_INTR_STS_SLVERR_SHIFT                                                 (7U)
#define PL310_RAW_INTR_STS_SLVERR_MASK                                                  (0x00000080U)

#define PL310_RAW_INTR_STS_DECERR_SHIFT                                                 (8U)
#define PL310_RAW_INTR_STS_DECERR_MASK                                                  (0x00000100U)

#define PL310_INTR_CLR_ECNTR_SHIFT                                                      (0U)
#define PL310_INTR_CLR_ECNTR_MASK                                                       (0x00000001U)

#define PL310_INTR_CLR_PARRT_SHIFT                                                      (1U)
#define PL310_INTR_CLR_PARRT_MASK                                                       (0x00000002U)

#define PL310_INTR_CLR_PARRD_SHIFT                                                      (2U)
#define PL310_INTR_CLR_PARRD_MASK                                                       (0x00000004U)

#define PL310_INTR_CLR_ERRWT_SHIFT                                                      (3U)
#define PL310_INTR_CLR_ERRWT_MASK                                                       (0x00000008U)

#define PL310_INTR_CLR_ERRWD_SHIFT                                                      (4U)
#define PL310_INTR_CLR_ERRWD_MASK                                                       (0x00000010U)

#define PL310_INTR_CLR_ERRRT_SHIFT                                                      (5U)
#define PL310_INTR_CLR_ERRRT_MASK                                                       (0x00000020U)

#define PL310_INTR_CLR_ERRRD_SHIFT                                                      (6U)
#define PL310_INTR_CLR_ERRRD_MASK                                                       (0x00000040U)

#define PL310_INTR_CLR_SLVERR_SHIFT                                                     (7U)
#define PL310_INTR_CLR_SLVERR_MASK                                                      (0x00000080U)

#define PL310_INTR_CLR_DECERR_SHIFT                                                     (8U)
#define PL310_INTR_CLR_DECERR_MASK                                                      (0x00000100U)

#define PL310_CACHE_SYNC_SHIFT                                                          (0U)
#define PL310_CACHE_SYNC_MASK                                                           (0x00000001U)

#define PL310_CACHE_SYNC_SBZ_SHIFT                                                      (1U)
#define PL310_CACHE_SYNC_SBZ_MASK                                                       (0xfffffffeU)

#define PL310_INV_LINE_BY_PA_C_SHIFT                                                    (0U)
#define PL310_INV_LINE_BY_PA_C_MASK                                                     (0x00000001U)

#define PL310_INV_LINE_BY_PA_SBZ_SHIFT                                                  (1U)
#define PL310_INV_LINE_BY_PA_SBZ_MASK                                                   (0x0000001eU)

#define PL310_INV_LINE_BY_PA_IDX_SHIFT                                                  (5U)
#define PL310_INV_LINE_BY_PA_IDX_MASK                                                   (0x00000fe0U)

#define PL310_INV_LINE_BY_PA_TAG_SHIFT                                                  (12U)
#define PL310_INV_LINE_BY_PA_TAG_MASK                                                   (0xfffff000U)

#define PL310_INV_BY_WAY_WAYBITS_SHIFT                                                  (0U)
#define PL310_INV_BY_WAY_WAYBITS_MASK                                                   (0x0000ffffU)

#define PL310_INV_BY_WAY_SBZ_SHIFT                                                      (16U)
#define PL310_INV_BY_WAY_SBZ_MASK                                                       (0xffff0000U)

#define PL310_CLEAN_LINE_BY_PA_C_SHIFT                                                  (0U)
#define PL310_CLEAN_LINE_BY_PA_C_MASK                                                   (0x00000001U)

#define PL310_CLEAN_LINE_BY_PA_SBZ_SHIFT                                                (1U)
#define PL310_CLEAN_LINE_BY_PA_SBZ_MASK                                                 (0x0000001eU)

#define PL310_CLEAN_LINE_BY_PA_IDX_SHIFT                                                (5U)
#define PL310_CLEAN_LINE_BY_PA_IDX_MASK                                                 (0x00000fe0U)

#define PL310_CLEAN_LINE_BY_PA_TAG_SHIFT                                                (12U)
#define PL310_CLEAN_LINE_BY_PA_TAG_MASK                                                 (0xfffff000U)

#define PL310_CLEAN_LINE_BY_IDX_C_SHIFT                                                 (0U)
#define PL310_CLEAN_LINE_BY_IDX_C_MASK                                                  (0x00000001U)

#define PL310_CLEAN_LINE_BY_IDX_SBZ1_SHIFT                                              (1U)
#define PL310_CLEAN_LINE_BY_IDX_SBZ1_MASK                                               (0x0000001eU)

#define PL310_CLEAN_LINE_BY_IDX_SHIFT                                                   (5U)
#define PL310_CLEAN_LINE_BY_IDX_MASK                                                    (0x00000fe0U)

#define PL310_CLEAN_LINE_BY_IDX_SBZ2_SHIFT                                              (12U)
#define PL310_CLEAN_LINE_BY_IDX_SBZ2_MASK                                               (0x0ffff000U)

#define PL310_CLEAN_LINE_BY_IDX_WAY_SHIFT                                               (28U)
#define PL310_CLEAN_LINE_BY_IDX_WAY_MASK                                                (0xf0000000U)

#define PL310_CLEAN_BY_WAY_WAYBITS_SHIFT                                                (0U)
#define PL310_CLEAN_BY_WAY_WAYBITS_MASK                                                 (0x0000ffffU)

#define PL310_CLEAN_BY_WAY_SBZ_SHIFT                                                    (16U)
#define PL310_CLEAN_BY_WAY_SBZ_MASK                                                     (0xffff0000U)

#define PL310_CLEAN_AND_INV_LINE_BY_PA_C_SHIFT                                          (0U)
#define PL310_CLEAN_AND_INV_LINE_BY_PA_C_MASK                                           (0x00000001U)

#define PL310_CLEAN_AND_INV_LINE_BY_PA_SBZ_SHIFT                                        (1U)
#define PL310_CLEAN_AND_INV_LINE_BY_PA_SBZ_MASK                                         (0x0000001eU)

#define PL310_CLEAN_AND_INV_LINE_BY_PA_IDX_SHIFT                                        (5U)
#define PL310_CLEAN_AND_INV_LINE_BY_PA_IDX_MASK                                         (0x00000fe0U)

#define PL310_CLEAN_AND_INV_LINE_BY_PA_TAG_SHIFT                                        (12U)
#define PL310_CLEAN_AND_INV_LINE_BY_PA_TAG_MASK                                         (0xfffff000U)

#define PL310_CLEAN_AND_INV_LINE_BY_IDX_C_SHIFT                                         (0U)
#define PL310_CLEAN_AND_INV_LINE_BY_IDX_C_MASK                                          (0x00000001U)

#define PL310_CLEAN_AND_INV_LINE_BY_IDX_SBZ1_SHIFT                                      (1U)
#define PL310_CLEAN_AND_INV_LINE_BY_IDX_SBZ1_MASK                                       (0x0000001eU)

#define PL310_CLEAN_AND_INV_LINE_BY_IDX_SHIFT                                           (5U)
#define PL310_CLEAN_AND_INV_LINE_BY_IDX_MASK                                            (0x00000fe0U)

#define PL310_CLEAN_AND_INV_LINE_BY_IDX_SBZ2_SHIFT                                      (12U)
#define PL310_CLEAN_AND_INV_LINE_BY_IDX_SBZ2_MASK                                       (0x0ffff000U)

#define PL310_CLEAN_AND_INV_LINE_BY_IDX_WAY_SHIFT                                       (28U)
#define PL310_CLEAN_AND_INV_LINE_BY_IDX_WAY_MASK                                        (0xf0000000U)

#define PL310_CLEAN_AND_INV_BY_WAY_WAYBITS_SHIFT                                        (0U)
#define PL310_CLEAN_AND_INV_BY_WAY_WAYBITS_MASK                                         (0x0000ffffU)

#define PL310_CLEAN_AND_INV_BY_WAY_SBZ_SHIFT                                            (16U)
#define PL310_CLEAN_AND_INV_BY_WAY_SBZ_MASK                                             (0xffff0000U)

#define PL310_DATA_LOCKDOWN_BY_WAY_LOCK_SHIFT                                           (0U)
#define PL310_DATA_LOCKDOWN_BY_WAY_LOCK_MASK                                            (0x0000ffffU)

#define PL310_INSTR_LOCKDOWN_BY_WAY_LOCK_SHIFT                                          (0U)
#define PL310_INSTR_LOCKDOWN_BY_WAY_LOCK_MASK                                           (0x0000ffffU)

#define PL310_LOCKDOWN_BY_LINE_EN_SHIFT                                                 (0U)
#define PL310_LOCKDOWN_BY_LINE_EN_MASK                                                  (0x00000001U)

#define PL310_UNLOCK_ALL_LINES_BY_WAY_OPERATION_SHIFT                                   (0U)
#define PL310_UNLOCK_ALL_LINES_BY_WAY_OPERATION_MASK                                    (0x0000ffffU)

#define PL310_ADDR_FILTERING_START_EN_SHIFT                                             (0U)
#define PL310_ADDR_FILTERING_START_EN_MASK                                              (0x00000001U)

#define PL310_ADDR_FILTERING_START_SHIFT                                                (20U)
#define PL310_ADDR_FILTERING_START_MASK                                                 (0xfff00000U)

#define PL310_ADDR_FILTERING_END_SHIFT                                                  (20U)
#define PL310_ADDR_FILTERING_END_MASK                                                   (0xfff00000U)

#define PL310_DBG_CTRL_DCL_SHIFT                                                        (0U)
#define PL310_DBG_CTRL_DCL_MASK                                                         (0x00000001U)

#define PL310_DBG_CTRL_DWB_SHIFT                                                        (1U)
#define PL310_DBG_CTRL_DWB_MASK                                                         (0x00000002U)

#define PL310_DBG_CTRL_SPNIDEN_SHIFT                                                    (2U)
#define PL310_DBG_CTRL_SPNIDEN_MASK                                                     (0x00000004U)

#define PL310_PREFETCH_OFFSET_VALUE_SHIFT                                               (0U)
#define PL310_PREFETCH_OFFSET_VALUE_MASK                                                (0x0000001fU)

#define PL310_PREFETCH_OFFSET_NOT_SAME_ID_ON_EXCLUSIVE_SEQUENCE_EN_SHIFT                (21U)
#define PL310_PREFETCH_OFFSET_NOT_SAME_ID_ON_EXCLUSIVE_SEQUENCE_EN_MASK                 (0x00200000U)

#define PL310_PREFETCH_OFFSET_INCR_DOUBLE_LINEFILL_EN_SHIFT                             (23U)
#define PL310_PREFETCH_OFFSET_INCR_DOUBLE_LINEFILL_EN_MASK                              (0x00800000U)

#define PL310_PREFETCH_OFFSET_DROP_EN_SHIFT                                             (24U)
#define PL310_PREFETCH_OFFSET_DROP_EN_MASK                                              (0x01000000U)

#define PL310_PREFETCH_OFFSET_DOUBLE_LINEFILL_ON_WRAP_READ_DISABLE_SHIFT                (27U)
#define PL310_PREFETCH_OFFSET_DOUBLE_LINEFILL_ON_WRAP_READ_DISABLE_MASK                 (0x08000000U)

#define PL310_PREFETCH_OFFSET_DATA_EN_SHIFT                                             (28U)
#define PL310_PREFETCH_OFFSET_DATA_EN_MASK                                              (0x10000000U)

#define PL310_PREFETCH_OFFSET_INSTR_EN_SHIFT                                            (29U)
#define PL310_PREFETCH_OFFSET_INSTR_EN_MASK                                             (0x20000000U)

#define PL310_PREFETCH_OFFSET_DOUBLE_LINEFILL_EN_SHIFT                                  (30U)
#define PL310_PREFETCH_OFFSET_DOUBLE_LINEFILL_EN_MASK                                   (0x40000000U)

#define PL310_POWER_CTRL_STANDBY_MODE_EN_SHIFT                                          (0U)
#define PL310_POWER_CTRL_STANDBY_MODE_EN_MASK                                           (0x00000001U)

#define PL310_POWER_CTRL_DYNAMIC_CLK_GATING_EN_SHIFT                                    (1U)
#define PL310_POWER_CTRL_DYNAMIC_CLK_GATING_EN_MASK                                     (0x00000002U)

#ifdef __cplusplus
}
#endif
#endif  /* HW_PL310_H_ */

