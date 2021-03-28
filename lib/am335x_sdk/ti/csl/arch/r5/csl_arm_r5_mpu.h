    /**
 * @file  csl_arm_r5_mpu.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the ARM R5 MPU IP.
 *  ============================================================================
 *  @n   (C) Copyright 2019, Texas Instruments, Inc.
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
#ifndef CSL_ARM_R5_MPU_H
#define CSL_ARM_R5_MPU_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *
 * @defgroup CSL_ARM_R5_MPU_API R5 MPU API
 *
 * Provies APIs for enabling the Memory Protection Unit APIs for R5 Core
 */
/**
@defgroup CSL_ARM_R5_MPU_DATASTRUCT  R5 MPU Data Structures
@ingroup CSL_ARM_R5_MPU_API
*/
/**
@defgroup CSL_ARM_R5_MPU_FUNCTION  R5 MPU Functions
@ingroup CSL_ARM_R5_MPU_API
*/
/**
@defgroup CSL_ARM_R5_MPU_ENUM R5 MPU Enumerated Data Types
@ingroup CSL_ARM_R5_MPU_API
*/

/**
@defgroup CSL_ARM_R5_MPU_MACROS R5 MPU Macro defines
@ingroup CSL_ARM_R5_MPU_API
*/

/**
 *  @addtogroup CSL_ARM_R5_MPU_ENUM
 * @{
 * 
 */


/**
 * @brief This enumerator defines the possible MPU region sizes
 *
 *
 */
/**
 *  \anchor CSL_ArmR5MpuRegionSize
 *  \name R5 MPU region size
 *  @{
 */
/**
 * \brief  MPU region sizes supported.
 */
typedef uint32_t CSL_ArmR5MpuRegionSize;

#define CSL_ARM_R5_MPU_REGION_SIZE_32B   (4U)
/**< 32 bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_64B   (5U)
/**< 64 bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_128B  (6U)
/**< 128 bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_256B  (7U)
/**< 256 bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_512B  (8U)
/**< 512 bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_1KB   (9U)
/**< 1K bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_2KB   (10U)
/**< 2K bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_4KB   (11U)
/**< 4K bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_8KB   (12U)
/**< 8K bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_16KB  (13U)
/**< 16K bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_32KB  (14U)
/**< 32K bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_64KB  (15U)
/**< 64K bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_128KB (16U)
/**< 128K bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_256KB (17U)
/**< 256K bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_512KB (18U)
/**< 512K bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_1MB   (19U)
/**< 1M bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_2MB   (20U)
/**< 2M bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_4MB   (21U)
/**< 4M bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_8MB   (22U)
/**< 8M bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_16MB  (23U)
/**< 16M bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_32MB  (24U)
/**< 32M bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_64MB  (25U)
/**< 64M bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_128MB (26U)
/**< 128M bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_256MB (27U)
/**< 256M bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_512MB (28U)
/**< 512M bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_1GB   (29U)
/**< 1G bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_2GB   (30U)
/**< 2G bytes region size */
#define CSL_ARM_R5_MPU_REGION_SIZE_4GB   (31U)
/**< 4G bytes region size */
/* @} */


/* @} */

/**
 *  @addtogroup CSL_ARM_R5_MPU_MACROS
    @{
 * 
 */

/**
 *  \anchor CSL_ArmR5MpuRegionNum
 *  \name Maximum number of MPU regions available in R5F SS.
 *
 *  @{
 */
/** \brief Number of R5 MPU region  */
#define CSL_ARM_R5F_MPU_REGIONS_MAX                 ((uint32_t) 16U)
/* @} */

/**
 *  \anchor CSL_ArmR5SubRegionDisable
 *  \name   Arm R5F MPU sub-region disable control.
 *  \brief  Mask for R5 MPU sub-region disable.
 *
 *  @{
 */
/** \brief Enable all sub-regions */
#define CSL_ARM_R5_MPU_SUB_REGION_ENABLE_ALL              ((uint32_t) 0x0U)
/** \brief Disable sub-region 0 */
#define CSL_ARM_R5_MPU_SUB_REGION_0_DISABLE               ((uint32_t) 0x1U)
/** \brief Disable sub-region 1 */
#define CSL_ARM_R5_MPU_SUB_REGION_1_DISABLE               ((uint32_t) 0x2U)
/** \brief Disable sub-region 2 */
#define CSL_ARM_R5_MPU_SUB_REGION_2_DISABLE               ((uint32_t) 0x4U)
/** \brief Disable sub-region 3 */
#define CSL_ARM_R5_MPU_SUB_REGION_3_DISABLE               ((uint32_t) 0x8U)
/** \brief Disable sub-region 4 */
#define CSL_ARM_R5_MPU_SUB_REGION_4_DISABLE               ((uint32_t) 0x10U)
/** \brief Disable sub-region 5 */
#define CSL_ARM_R5_MPU_SUB_REGION_5_DISABLE               ((uint32_t) 0x20U)
/** \brief Disable sub-region 6 */
#define CSL_ARM_R5_MPU_SUB_REGION_6_DISABLE               ((uint32_t) 0x40U)
/** \brief Disable sub-region 7 */
#define CSL_ARM_R5_MPU_SUB_REGION_8_DISABLE               ((uint32_t) 0x80U)
/* @} */

/**
 *  \anchor CSL_ArmR5AccessPerm
 *  \name   Arm R5F MPU region access permissions.
 *  \brief  Access permissions for R5 MPU regions.
 *
 *  @{
 */
/** \brief No accesses are permitted to MPU region */
#define CSL_ARM_R5_ACC_PERM_NO_ACCESS               ((uint32_t) 0x0U)
/** \brief Privileged accesses only */
#define CSL_ARM_R5_ACC_PERM_PRIV_RD_WR              ((uint32_t) 0x1U)
/** \brief Privileged read/write accesses and user read only */
#define CSL_ARM_R5_ACC_PERM_PRIV_RD_WR_USR_RD       ((uint32_t) 0x2U)
/** \brief Full access to privileged and user modes */
#define CSL_ARM_R5_ACC_PERM_PRIV_USR_RD_WR          ((uint32_t) 0x3U)
/** \brief Privileged read accesses only */
#define CSL_ARM_R5_ACC_PERM_PRIV_RD_ONLY            ((uint32_t) 0x5U)
/** \brief Read only accesses to privileged and user modes */
#define CSL_ARM_R5_ACC_PERM_PRIV_USR_RD             ((uint32_t) 0x6U)
/* @} */

/**
 *  \anchor CSL_ArmR5CachePolicy
 *  \name   Arm R5F MPU region cache policy.
 *  \brief  Inner and outer cache policy for R5 MPU region.
 *
 *  @{
 */
/** \brief  Cache Policy: Non-cacheable */
#define CSL_ARM_R5_CACHE_POLICY_NON_CACHEABLE               ((uint32_t) 0x0U)
/** \brief  Cache Policy: Write-back, write-allocate */
#define CSL_ARM_R5_CACHE_POLICY_WB_WA                       ((uint32_t) 0x1U)
/** \brief  Cache Policy: Write-through, no write-allocate */
#define CSL_ARM_R5_CACHE_POLICY_WT_NO_WA                    ((uint32_t) 0x2U)
/** \brief  Cache Policy: Write-back, no write-allocate */
#define CSL_ARM_R5_CACHE_POLICY_WB_NO_WA                    ((uint32_t) 0x3U)
/* @} */

/**
 *  \anchor CSL_ArmR5MemAttr
 *  \name   Arm R5F MPU region attributes.
 *  \brief  Memory attributes: TEX[2:0], C, and B encodings.
 *
 *  @{
 */
/** \brief  Memory type and cache policies: Strongly-ordered. */
#define CSL_ARM_R5_MEM_ATTR_STRONGLY_ORDERED               ((uint32_t) 0x0U)
/** \brief  Memory type and cache policies: Shareable. */
#define CSL_ARM_R5_MEM_ATTR_SHAREABLE                      ((uint32_t) 0x1U)
/** \brief  Memory type and cache policies:
            Outer and Inner write-through, no write-allocate. */
#define CSL_ARM_R5_MEM_ATTR_CACHED_WT_NO_WA                ((uint32_t) 0x2U)
/** \brief  Memory type and cache policies:
            Outer and Inner write-back, no write-allocate. */
#define CSL_ARM_R5_MEM_ATTR_CACHED_WB_NO_WA                ((uint32_t) 0x3U)
/** \brief  Memory type and cache policies: Non cacheable. */
#define CSL_ARM_R5_MEM_ATTR_STRONGLY_NON_CACHED            ((uint32_t) 0x4U)
/** \brief  Memory type and cache policies:
            Outer and Inner write-back, write-allocate. */
#define CSL_ARM_R5_MEM_ATTR_CACHED_WB_WA                   ((uint32_t) 0x5U)
/** \brief  Memory type and cache policies: Non-shareable Device. */
#define CSL_ARM_R5_MEM_ATTR_NON_SHAREABLE                  ((uint32_t) 0x6U)
/** \brief  This should be passed to configuration. */
#define CSL_ARM_R5_MEM_ATTR_MAX                            ((uint32_t) 0x7U)

/* @} */


/* @} */


/* MPU_REGION_BASE */

#define CSL_ARM_R5_MPU_REGION_BASE_ADDR_MASK                                       (0xFFFFFFFEU)
#define CSL_ARM_R5_MPU_REGION_BASE_ADDR_SHIFT                                      (0x00000005U)
#define CSL_ARM_R5_MPU_REGION_BASE_ADDR_RESETVAL                                   (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_BASE_ADDR_MAX                                        (0x07FFFFFFU)

/* MPU_REGION_SZEN */

#define CSL_ARM_R5_MPU_REGION_SZEN_EN_MASK                                         (0x00000001U)
#define CSL_ARM_R5_MPU_REGION_SZEN_EN_SHIFT                                        (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_SZEN_EN_RESETVAL                                     (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_SZEN_EN_MAX                                          (0x00000001U)

#define CSL_ARM_R5_MPU_REGION_SZEN_SZ_MASK                                         (0x00000037U)
#define CSL_ARM_R5_MPU_REGION_SZEN_SZ_SHIFT                                        (0x00000001U)
#define CSL_ARM_R5_MPU_REGION_SZEN_SZ_RESETVAL                                     (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_SZEN_SZ_MAX                                          (0x0000001FU)

#define CSL_ARM_R5_MPU_REGION_SZEN_SRD_MASK                                        (0x0000FF00U)
#define CSL_ARM_R5_MPU_REGION_SZEN_SRD_SHIFT                                       (0x00000008U)
#define CSL_ARM_R5_MPU_REGION_SZEN_SRD_RESETVAL                                    (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_SZEN_SRD_MAX                                         (0x000000FFU)

/* MPU_REGION_AC */

#define CSL_ARM_R5_MPU_REGION_AC_B_MASK                                            (0x00000001U)
#define CSL_ARM_R5_MPU_REGION_AC_B_SHIFT                                           (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_AC_B_RESETVAL                                        (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_AC_B_MAX                                             (0x00000001U)

#define CSL_ARM_R5_MPU_REGION_AC_CB_MASK                                           (0x00000003U)
#define CSL_ARM_R5_MPU_REGION_AC_CB_SHIFT                                          (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_AC_CB_RESETVAL                                       (0x00000000U)

#define CSL_ARM_R5_MPU_REGION_AC_C_MASK                                            (0x00000002U)
#define CSL_ARM_R5_MPU_REGION_AC_C_SHIFT                                           (0x00000001U)
#define CSL_ARM_R5_MPU_REGION_AC_C_RESETVAL                                        (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_AC_C_MAX                                             (0x00000001U)

#define CSL_ARM_R5_MPU_REGION_AC_S_MASK                                            (0x00000004U)
#define CSL_ARM_R5_MPU_REGION_AC_S_SHIFT                                           (0x00000002U)
#define CSL_ARM_R5_MPU_REGION_AC_S_RESETVAL                                        (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_AC_S_MAX                                             (0x00000001U)

#define CSL_ARM_R5_MPU_REGION_AC_TEX_MASK                                          (0x00000038U)
#define CSL_ARM_R5_MPU_REGION_AC_TEX_SHIFT                                         (0x00000003U)
#define CSL_ARM_R5_MPU_REGION_AC_TEX_RESETVAL                                      (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_AC_TEX_MAX                                           (0x00000007U)

#define CSL_ARM_R5_MPU_REGION_AC_AP_MASK                                           (0x00000700U)
#define CSL_ARM_R5_MPU_REGION_AC_AP_SHIFT                                          (0x00000008U)
#define CSL_ARM_R5_MPU_REGION_AC_AP_RESETVAL                                       (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_AC_AP_MAX                                            (0x00000007U)
#define CSL_ARM_R5_MPU_REGION_AC_AP_VAL_NO_ACCESS                                  (0U)
#define CSL_ARM_R5_MPU_REGION_AC_AP_VAL_RW                                         (3U)
#define CSL_ARM_R5_MPU_REGION_AC_AP_VAL_RO                                         (6U)

#define CSL_ARM_R5_MPU_REGION_AC_XN_MASK                                           (0x00001000U)
#define CSL_ARM_R5_MPU_REGION_AC_XN_SHIFT                                          (0x0000000CU)
#define CSL_ARM_R5_MPU_REGION_AC_XN_RESETVAL                                       (0x00000000U)
#define CSL_ARM_R5_MPU_REGION_AC_XN_MAX                                            (0x00000001U)

/**
 *  \addtogroup CSL_ARM_R5_MPU_DATASTRUCT
 *  @{
 */
/**
 * \brief  Structure containing the region configuration parameters.
 *         If application wants to do it's own MPU region configuration
 *         (override the default one), then it needs to define this variable
 *         and initialize that to desired values:
 *         Var: 'const CSL_ArmR5MpuRegionCfg gCslR5MpuCfg[CSL_ARM_R5F_MPU_REGIONS_MAX]'
 *         With above application can have it's own MPU configuration, but
 *         MPU configuration will still happen at boot/startup time.
 *         Default configurations for MPU regions is present under file:
 *         "\src\startup\startup.c"
 */
typedef struct
{
    uint32_t regionId;
    /**< Region number to configure.
     *   Range: 0 to (CSL_ARM_R5F_MPU_REGIONS_MAX     1U) */
    uint32_t enable;
    /**< Region enable control.
     *   0: Memory region disabled.
     *   1: Memory region enabled. */
    uint32_t baseAddr;
    /**< Region base address: 32 bytes aligned. */
    CSL_ArmR5MpuRegionSize size;
    /**< Region size
     *   Refer #CSL_ArmR5MpuRegionSize */
    uint32_t subRegionEnable;
    /**< Sub-region enable
     *   See \ref CSL_ArmR5SubRegionDisable for details.
     *   Multiple sub-regions can disabled by ORing multiple masks from above */
    uint32_t exeNeverControl;
    /**< Region execute control.
     *   0: all instruction fetches enabled
     *   1: no instruction fetches enabled */
    uint32_t accessPermission;
    /**< Access permissions
      *  See \ref CSL_ArmR5AccessPerm for more details */
    uint32_t shareable;
    /**< Region share attribute.
     *   0: non-shared
     *   1: shared */
    uint32_t cacheable;
    /**< Region cache control.
     *   FALSE: Memory region is non-cached.
     *   TRUE:  Memory  region is cached. */
    uint32_t cachePolicy;
    /**< Inner and outer cache policy.
     *   This field is valid only if cacheable = TRUE
     *   See \ref CSL_ArmR5CachePolicy for more details */
    uint32_t memAttr;
    /**< Memory region attributes.
     *   This field is valid only if cacheable = FALSE
     *   See \ref CSL_ArmR5MemAttr for more details */
}CSL_ArmR5MpuRegionCfg;
/* @} */

/**
 *  \addtogroup CSL_ARM_R5_MPU_FUNCTION
 *  @{
 */

/**
 *  \brief Enable/disable the Memory Protection Unit (MPU)
 *
 *  Requirement: REQ_TAG(PRSDK-1663)
 *  Design: did_csl_core_mpu_configure
 *
 *  This function is used to enable or disable the MPU.
 *
 *  \param enable   [IN]    0=MPU is disabled, otherwise MPU is enabled
 *
 *  \return None
 */
extern void CSL_armR5MpuEnable( uint32_t enable );

/**
 *  \brief Get the number of unified MPU regions supported
 *
 *  Requirement: REQ_TAG(PRSDK-1663)
 *  Design: did_csl_core_mpu_read
 *
 *  This function is used to get the number of unified MPU regions supported.
 *
 *
 *  \return The number of unified MPU regions supported
 */
extern uint32_t CSL_armR5MpuGetNumRegions( void );

/**
 *  \brief Configure an MPU region
 *
 *  Requirement: REQ_TAG(PRSDK-1663)
 *  Design: did_csl_core_mpu_configure
 *
 *  This function is used to configure an MPU region.
 *
 *  The value arguments provided to this function are directly written into
 *  the corresponding R5 system register. As a result, the values must be
 *  constructed per the expected register format.
 *
 *  See the "MPU memory region programming registers" section of the ARM Cortex
 *  R5 TRM for more information.
 *
 *  \param regionNum        [IN]    Region number
 *  \param baseAddrRegVal   [IN]    Value written to the MPU Region Base
 *                                  Address Register
 *  \param sizeRegVal       [IN]    Value written to the MPU Size and Enable
 *                                  Register
 *  \param accessCtrlRegVal [IN]    Value written to the MPU Region Access
 *                                  Control Register
 *
 *  \return None
 */
extern void CSL_armR5MpuCfgRegion( uint32_t regionNum, uint32_t baseAddrRegVal, uint32_t sizeRegVal, uint32_t accessCtrlRegVal );

/**
 *  \brief Verify an MPU region that is previously configured
 *
 *  Requirement: REQ_TAG(PRSDK-1663)
 *  Design: did_csl_core_mpu_check
 *
 *  This function is used to verify the previous configure an MPU region API.
 *
 *  The value arguments provided to this function are directly verfied against
 *  the corresponding R5 system register. As a result, the values must be
 *  constructed per the expected register format.
 *
 *  See the "MPU memory region programming registers" section of the ARM Cortex
 *  R5 TRM for more information.
 *
 *  \param regionNum        [IN]    Region number
 *  \param baseAddrRegVal   [IN]    Value written to the MPU Region Base
 *                                  Address Register
 *  \param sizeRegVal       [IN]    Value written to the MPU Size and Enable
 *                                  Register
 *  \param accessCtrlRegVal [IN]    Value written to the MPU Region Access
 *                                  Control Register
 *
 *  \return None
 */
extern int32_t CSL_armR5MpuVerifyCfgRegion( uint32_t regionNum, uint32_t baseAddrRegVal, uint32_t sizeRegVal, uint32_t accessCtrlRegVal );

/**
 *  \brief Enable/disable an MPU region
 *
 *  Requirement: REQ_TAG(PRSDK-1663)
 *  Design: did_csl_core_mpu_configure
 *
 *  This function is used to enable or disable an MPU region.
 *
 *  \param regionNum        [IN]    Region number
 *  \param enable           [IN]    0=The specified MPU region is disabled,
 *                                  otherwise it is enabled
 *
 *  \return None
 */
extern void CSL_armR5MpuEnableRegion( uint32_t regionNum, uint32_t enable );

/**
 *  \brief Verifies the previously called Enable/disable an MPU region API
 *
 *  Requirement: REQ_TAG(PRSDK-1663)
 *  Design: did_csl_core_mpu_check
 *
 *  This function is used to verify enable or disable an MPU region.
 *
 *  \param regionNum        [IN]    Region number
 *  \param enable   [IN]    0=The specified MPU region is disabled, otherwise
 *                          it is enabled
 *
 *  \return CSL_PASS for success otherwise CSL_EFAIL
 */
extern int32_t CSL_armR5MpuVerifyEnableRegion( uint32_t regionNum, uint32_t enable );


/* @} */

#ifdef __cplusplus
}
#endif  /* extern "C" */

#endif  /* end of CSL_ARM_R5_MPU_H definition */
