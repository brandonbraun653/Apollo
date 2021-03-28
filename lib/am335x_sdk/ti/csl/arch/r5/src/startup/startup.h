    /**
 * @file  startup.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the ARM R5 Startup code. For internal use only.
 *  This file may have duplicated information from 'csl_arch'. This is done
 *  to avoid dependency of 'csl_init' on 'csl_arch.'
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017-2019, Texas Instruments, Inc.
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
#ifndef CSL_ARM_R5_STARTUP_H_
#define CSL_ARM_R5_STARTUP_H_

#include <stdlib.h>
#include <stdint.h>
#include <csl_arm_r5.h>
#include <csl_arm_r5_mpu.h>
#include <interrupt.h>
#include <csl_vim.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/**
 *  \brief Enable/disable instruction and data caches
 *
 *  This function is used to enable or disable instruction and data caches.
 *
 *  \param enable   [IN]    0=All caches are disabled, otherwise
 *                          they are enabled
 *
 *  \return None
 */
void CSL_armR5StartupCacheEnableAllCache( uint32_t enable );

/**
 *  \brief Enable/disable force write-through (WT) for write-back (WB) regions
 *
 *  This function is used to enable or disable force write-through (WT) for
 *  write-back (WB) regions.
 *
 *  \param enable   [IN]    0=No forcing of WT, otherwise WT forced for WB
 *                          regions
 *
 *  \return None
 */
void CSL_armR5StartupCacheEnableForceWrThru( uint32_t enable );

/**
 *  \brief Invalidate all instruction caches
 *
 *  This function is used to invalidate all instruction cache.
 *
 *  \param None
 *
 *  \return None
 */
void CSL_armR5StartupCacheInvalidateAllIcache( void );

/**
 *  \brief Invalidate all data caches
 *
 *  This function is used to invalidate all data caches.
 *
 *  \param None
 *
 *  \return None
 */
void CSL_armR5StartupCacheInvalidateAllDcache( void );

/**
 *  \brief Invalidate all instruction and data caches
 *
 *  This function is used to invalidate all instruction and data caches.
 *
 *  \param None
 *
 *  \return None
 */
void CSL_armR5StartupCacheInvalidateAllCache( void );

/**
 *  \brief Get the cluster group and CPU ID for current R5 Core
 *
 *  \param cpuInfo          Pointer to CPU info structure
 *                          Refer struct #CSL_ArmR5CPUInfo
 *
 *  \return None
 * Please NOTE that this function has to be called in privileged mode only
 */
void CSL_armR5StartupGetCpuID( CSL_ArmR5CPUInfo *cpuInfo );

/**
 *  \brief Enable/disable instruction caches
 *
 *  This function is used to enable or disable instruction caches.
 *
 *  \param enable   [IN]    0=Instruction caches are disabled, otherwise
 *                          they are enabled
 *
 *  \return None
 */
void CSL_armR5StartupCacheEnableICache( uint32_t enable );

/**
 *  \brief Enable/disable data caches
 *
 *  This function is used to enable or disable data caches.
 *
 *  \param enable   [IN]    0=Data cache are disabled, otherwise
 *                          they are enabled
 *
 *  \return None
 */
void CSL_armR5StartupCacheEnableDCache( uint32_t enable );

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
void CSL_armR5StartupMpuEnable( uint32_t enable );

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
void CSL_armR5StartupMpuCfgRegion(uint32_t regionNum,
                                         uint32_t baseAddrRegVal,
                                         uint32_t sizeRegVal,
                                         uint32_t accessCtrlRegVal );

/**
 *  \brief Get the contents fo MPIDR register
 *
 *  \param None
 *
 *  \return                 contents of MPIDR register
 * Please NOTE that this function has to be called in privileged mode only
 */
uint32_t CSL_armR5StartupReadMpidrReg( void );

/**
 *  \brief Enable/disable the Floating Point Unit (FPU)
 *
 *  This function is used to enable or disable the FPU.
 *
 *  \param enable   [IN]    0=FPU is disabled, otherwise FPU is enabled
 *
 *  \return None
 */
void CSL_armR5StartupFpuEnable( uint32_t enable );

/**
 *  \brief Enable/disable VIC
 *
 *  This function is used to enable or disable the VIC.
 *
 *  \param enable   [IN]    0=VIC is disabled, otherwise
 *                          it is enabled
 *
 *  \return None
 */
void CSL_armR5StartupIntrEnableVic( uint32_t enable );

/**
 *  \brief Enable/disable FIQ interrupt generation
 *
 *  This function is used to enable or disable FIQ interrupt generation.
 *
 *  \param enable   [IN]    0=Interrupt generation is disabled, otherwise
 *                          it is enabled
 *
 *  \return None
 */
void CSL_armR5StartupIntrEnableFiq( uint32_t enable );

/**
 *  \brief Enable/disable IRQ interrupt generation
 *
 *  This function is used to enable or disable IRQ interrupt generation.
 *
 *  \param enable   [IN]    0=Interrupt generation is disabled, otherwise
 *                          it is enabled
 *
 *  \return None
 */
void CSL_armR5StartupIntrEnableIrq( uint32_t enable );

/**
 * \brief PDK-4356/PDK-4570 FIX - set to DLFO bit in ACTRL register of R5F
 *
 * This API uses assembly instruction to set DLFO bit in ACTRL register
 * of R5F.
 * This should be called from the Core reset callback.
 *
 */
void CSL_armR5SetDLFOBit( void );

int32_t CSL_startupVimSetIntrEnable(CSL_vimRegs *pRegs,
                             uint32_t intrNum,
                             bool bEnable );

int32_t CSL_startupVimClrIntrPending( CSL_vimRegs *pRegs, uint32_t intrNum );

#ifdef __cplusplus
}
#endif  /* extern "C" */

#endif  /* end of CSL_ARM_R5_STARTUP_H_ definition */
