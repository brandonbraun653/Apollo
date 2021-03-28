    /**
 * @file  csl_arm_r5_hard_err_cache.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the ARM R5 hard error cache.
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
#ifndef CSL_ARM_R5_HARD_ERR_CACHE
#define CSL_ARM_R5_HARD_ERR_CACHE

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/** 
 *
 * @defgroup CSL_ARM_R5_HARD_ERR_CACHE_API R5 HARD ERROR CACHE API
 *
 * Provides APIs to enable/disable the Hard error and APIs to access
 * ATCM and BTCM region registers
 */

/**
@defgroup CSL_ARM_R5_HARD_ERR_CACHE_FUNCTION  R5 HARD_ERR_CACHE Functions
@ingroup CSL_ARM_R5_HARD_ERR_CACHE_API
*/

/* @} */

/**
 *  \addtogroup CSL_ARM_R5_HARD_ERR_CACHE_FUNCTION
 *  @{
 */


/**
 *  \brief Write BTCM Region Register
 *
 *  Requirement: REQ_TAG(PRSDK-1673)
 *  Design: did_csl_core_hard_err_cache_access
 *
 *  This function is used to write BTCM region register.
 *
 *  \param value   [IN]    BTCM register value to be written
 *
 *  \return None
 */
void CSL_armR5WriteBTCMRegionRegister(uint32_t value);

/**
 *  \brief Write ATCM Region Register
 *
 *  Requirement: REQ_TAG(PRSDK-1673)
 *  Design: did_csl_core_hard_err_cache_access
 *
 *  This function is used to write ATCM region register.
 *
 *  \param value   [IN]    ATCM register value to be written
 *
 *  \return None
 */
void CSL_armR5WriteATCMRegionRegister(uint32_t value);

/**
 *  \brief Read BTCM Region Register
 *
 *  Requirement: REQ_TAG(PRSDK-1673)
 *  Design: did_csl_core_hard_err_cache_access
 *
 *  This function is used to read BTCM region register.
 *
 *
 *  \return BTCM Region Register value
 */
uint32_t CSL_armR5ReadBTCMRegionRegister(void);

/**
 *  \brief Read ATCM Region Register
 *
 *  Requirement: REQ_TAG(PRSDK-1673)
 *  Design: did_csl_core_hard_err_cache_access
 *
 *  This function is used to read ATCM region register.
 *
 *
 *  \return ATCM Region Register value
 */
uint32_t CSL_armR5ReadATCMRegionRegister(void);

/**
 *  \brief Enable/disable hard error cache
 *
 *  Requirement: REQ_TAG(PRSDK-1673)
 *  Design: did_csl_core_hard_err_cache_access
 *
 *  This function is used to enable or disable hard error caches.
 *
 *  \param enable   [IN]    0=Hard error caches are disabled, otherwise
 *                          they are enabled
 *
 *  \return None
 */
void CSL_armR5CacheEnableHardErrCache( uint32_t enable );



/* @} */

#ifdef __cplusplus
}
#endif  /* extern "C" */

#endif  /* end of CSL_ARM_R5_H_ definition */
