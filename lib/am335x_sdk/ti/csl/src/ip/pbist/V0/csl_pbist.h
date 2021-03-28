/********************************************************************
 * Copyright (C) 2019 Texas Instruments Incorporated.
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
 *
 *   @file  csl_pbist.h
 *
 *   @path  $(CSLPATH)/src/ip/lbist/V0
 *
 *   @desc  This file contains the CSL-FL API's for PBIST.
 *
 *   @defgroup CSL_PBIST_API PBIST API
 *
 *   This is the CSL-FL API documentation for the Programmable Built-In Self Test
 *   (PBIST) module.
 *
 *
 *
 */

#ifndef CSL_PBIST_H_
#define CSL_PBIST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_pbist.h>

/**
@defgroup CSL_PBIST_DATASTRUCT  PBIST Data Structures
@ingroup CSL_PBIST_API
*/
/**
@defgroup CSL_PBIST_FUNCTION  PBIST Functions
@ingroup CSL_PBIST_API
*/
/**
@defgroup CSL_PBIST_ENUM PBIST Enumerated Data Types
@ingroup CSL_PBIST_API
*/

/** ===========================================================================
 *  @addtogroup CSL_PBIST_ENUM
    @{
 *
 */


/** @} */

/**  ===========================================================================
 *  @addtogroup CSL_PBIST_DATASTRUCT
    @{
 *
 */

/** ---------------------------------------------------------------------------
 * @brief   This structure contains the different configuration used for LBIST
 *
 * ----------------------------------------------------------------------------
 */

typedef struct CSL_PBIST_config
{
    uint32_t algorithmsBitMap;
    /**< Bitmap to select algorithms to use for test
        NOTE: For a given PBIST instance, there is a selected
        set of memory groups a particular Algorithm can be run
        Looks up SOC documentation for the supported memory group */
    uint32_t override;
    /**< Override value for memory configuration */
    uint64_t memoryGroupsBitMap;
    /**< Bitmap to select memory groups to run test on */
    uint64_t scrambleValue;
    /**< Scramble value to be used for test */

} CSL_PBIST_config_t;

/** @} */

/** ===========================================================================
 *  @addtogroup CSL_PBIST_FUNCTION
    @{
 *
 */
/** ===========================================================================
 *  \brief PBIST Soft reset
 *
 *  This function resets PBIST Module. In general called before running a new
 *  test
 *
 *
 *  \param pPBISTRegs       [IN]  Pointer to PBIST registers base
 *
 *  \return The CSL error code for the API.
 *                                 Success: CSL_PASS
 *                                 Fail   : CSL_EFAIL
 */
CSL_ErrType_t CSL_PBIST_softReset(CSL_pbistRegs *pPBISTRegs);

/** ===========================================================================
 *  \brief PBIST Start
 *
 *  This function configures the paramters for PBIST and starts execution
 *
 *
 *  \param pPBISTRegs       [IN]  Pointer to PBIST registers base
 *  \param pConfig          [IN]  Pointer to PBIST configuration
 *
 *  \return The CSL error code for the API.
 *                                 Success: CSL_PASS
 *                                 Fail   : CSL_EFAIL
 */
CSL_ErrType_t CSL_PBIST_start(CSL_pbistRegs *pPBISTRegs,
                        const CSL_PBIST_config_t * const pConfig);


/** ===========================================================================
 *  \brief PBIST check result
 *
 *  This function checks if PBIST test has passed
 *
 *
 *  \param pPBISTRegs       [IN]  Pointer to PBIST registers base
 *  \param pResult          [OUT] Pointer to variable to indicate result
 *
 *  \return The CSL error code for the API.
 *                                 Success: CSL_PASS
 *                                 Fail   : CSL_EFAIL
 */
CSL_ErrType_t CSL_PBIST_checkResult (CSL_pbistRegs *pPBISTRegs, Bool *pResult);

/** ===========================================================================
 *  \brief PBIST Release Test mode
 *
 *  This function releases test mode. In general called after test is complete
 *  to switch back to normal operation
 *
 *
 *  \param pPBISTRegs       [IN]  Pointer to PBIST registers base
 *
 *  \return The CSL error code for the API.
 *                                 Success: CSL_PASS
 *                                 Fail   : CSL_EFAIL
 */
CSL_ErrType_t CSL_PBIST_releaseTestMode(CSL_pbistRegs *pPBISTRegs);

/** @} */

#ifdef __cplusplus
}
#endif

#endif /* CSL_PBIST_H_ */
