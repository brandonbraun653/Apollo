#ifndef _CSL_ARM64FUNC_H_
#define _CSL_ARM64FUNC_H_

/**
 *  @file csl_arm64func.h
 *
 *  @brief
 *     ARM General Maintainence Functions
 *  \par
 *   ================================================================================
 *
 *   @n   (C)  Copyright 2015 Texas Instruments Incorporated
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *      Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *      Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the
 *      distribution.
 *
 *      Neither the name of Texas Instruments Incorporated nor the names of
 *      its contributors may be used to endorse or promote products derived
 *      from this software without specific prior written permission.
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
 *  Code derived from ARM LTD examples and documentation found in the
 *  following documents.
 *
 *  ARM® Cortex® -A53 MPCore Processor
 *  Revision: r0p4
 *  Technical Reference Manual
 *
 *  ARM® Architecture Reference Manual
 *  ARMv8, for ARMv8-A architecture profile
 *  Beta
 */


#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

    /** ===========================================================================
     *
     * @defgroup CSL_ARM64FUNC_API (ARM64 Genearl Functions)
     * @ingroup CSL_ARM64FUNC_API
     *
     * @section Introduction
     *
     * @subsection xxx Overview
     *
     * @subsection References
     *    -# ARM Functional Specification
     * ============================================================================
     */

    /**
       @defgroup CSL_ARM64FUNC_DATASTRUCT ARM 64 Bit Mode General Data Structures
       @ingroup CSL_ARM64FUNC_API
    */
    /**
       @defgroup CSL_ARM64FUNC_FUNCTION ARM 64 Bit Mode General Functions
       @ingroup CSL_ARM64FUNC_API
    */
    /**
       @defgroup CSL_ARM64FUNC_ENUM ARM 64 Bit Mode General Enumerated Data Types
       @ingroup CSL_ARM64FUNC_API
    */


    /*Function Prototypes */

    /** ==========================================================================
        @addtogroup CSL_ARM64FUNC_FUNCTION
        @{
        *  ===========================================================================
        */
    /**
     * @n@b  CSL_a53v8GetAA64MemModFeature
     *
     * @b Description
     * @n  Get the value of the ID_AA64MMFR0_EL1 register (memory model feature reg)
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n uint64_6 feature   - register feature content
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     * uint64_t    feature;
     *
     *  feature =  CSL_a53v8GetAA64MemModFeature();
     * @endverbatim
     */



    uint64_t CSL_a53v8GetAA64MemModFeature();







    /**
     * @n@b  CSL_a53v8GetAA64FeatureReg0
     *
     * @b Description
     * @n  Get the value of the ID_AA64PFR0_EL1 register (memory model feature reg)
     *
     *
     *
     * @b Arguments
     * @n  None
     *
     * <b> Return Value </b>
     * @n uint64_6 feature   - register feature content
     *
     * <b> Pre Condition </b>
     * @n None
     *
     * <b> Post Condition </n>
     * @n None
     *
     * @b Reads
     * @n None
     *
     * @b Example
     * @verbatim
     * uint64_t    feature;
     *
     *  feature =  CSL_a53v8GetAA64FeatureReg0();
     * @endverbatim
     */


    uint64_t CSL_a53v8GetAA64FeatureReg0();


    /** @} */





#ifdef __cplusplus
}
#endif

#endif             /* end of _CSL_ARM64FUNCTION_H_ definition */
