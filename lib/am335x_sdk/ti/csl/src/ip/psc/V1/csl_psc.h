/**
 *   @file  csl_psc.h
 *
 *   @brief
 *      This is the main Header File for the PSC Module which defines all
 *      the data structures and exported API.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016 Texas Instruments, Inc.
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
/** @defgroup CSL_PSC_API PSC
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 *
 * The Power and Sleep Controller (PSC) is intended to be used on chips
 * that require granular power control to all the on-chip modules such as
 * peripherals, CPU, and controllers for power savings.
 *
 * @subsection References
 *   -# PSC User Guide.
 *
 * @subsection Assumptions
 *    The abbreviations PSC, psc and Psc have been used throughout this
 *    document to refer to Power and Sleep Controller.
 */
#ifndef CSL_PSC_H_
#define CSL_PSC_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/soc.h>
#include <ti/csl/csl.h>
#include <ti/csl/cslr_psc.h>

/**
@defgroup CSL_PSC_SYMBOL  PSC Symbols Defined
@ingroup CSL_PSC_API
*/
/**
@defgroup CSL_PSC_DATASTRUCT  PSC Data Structures
@ingroup CSL_PSC_API
*/
/**
@defgroup CSL_PSC_FUNCTION  PSC Functions
@ingroup CSL_PSC_API
*/
/**
@defgroup CSL_PSC_ENUM PSC Enumerated Data Types
@ingroup CSL_PSC_API
*/

/**
@addtogroup CSL_PSC_SYMBOL
@{
*/

/**
@}
*/

#define PSC0_MAX_LPSC_MODULE  (16)
#define PSC1_MAX_LPSC_MODULE  (32)

/** @addtogroup CSL_PSC_DATASTRUCT
 @{ */

/** Constants for passing parameters to the functions.
 */
/** @brief Pointer to the PSC overlay registers */
#define     hPscRegs0                            ((CSL_PscRegs *) (CSL_PSC_0_REGS))
#define     hPscRegs1                            ((CSL_PscRegs *) (CSL_PSC_1_REGS))
 
/** @brief
 *
 *  Possible PSC Power domain states
 */
typedef enum {
	/** Invalid Module Number **/
	PSC_PDSTATE_INVALID = -1,
	
    /** Power domain is Off */
    PSC_PDSTATE_OFF = 0,

    /** Power domain is On */
    PSC_PDSTATE_ON = 1
} CSL_PSC_PDSTATE;

/** @brief
 *
 *  Possible PSC Module states
 */
typedef enum {
	/**Invalid Module Number**/
	PSC_MODSTATE_INVALID = -1,

    /** Module is in Reset state. Clock is off. */
    PSC_MODSTATE_SWRSTDISABLE = 0,

    /** Module is in Sync Reset state. */
    PSC_MODSTATE_SYNCRST = 1,

    /** Module is in disable state. */
    PSC_MODSTATE_DISABLE = 2,

    /** Module is in enable state. */
    PSC_MODSTATE_ENABLE = 3,

    /** Module is in Auto sleep state */
    PSC_MODSTATE_AUTOSLP = 4,

    /** Module is in Auto wake state */
    PSC_MODSTATE_AUTOWK = 5
} CSL_PSC_MODSTATE;

/** @brief
 *
 *  Possible module local reset status
 */
typedef enum {
	/** Invalid Module Number **/
	PSC_MDLRST_INVALID = -1,

    /** Module local reset asserted */
    PSC_MDLRST_ASSERTED = 0,

    /** Module local reset deasserted */
    PSC_MDLRST_DEASSERTED = 1
} CSL_PSC_MDLRST;

/** @brief
 *
 *  Possible module reset status
 */
typedef enum {
	/** Invalid Module Number **/
	PSC_MDRST_INVALID = -1,

    /** Module reset asserted */
    PSC_MDRST_ASSERTED = 0,

    /** Module reset deasserted */
    PSC_MDRST_DEASSERTED = 1
} CSL_PSC_MDRST;

typedef enum {
	PSC1_MDUNUSED_NO_16 = 16,
	
	PSC1_MDUNUSED_NO_30 = 30,
	
	PSC1_MDUNUSED_NO_31 = 31,
	
	PSC1_MDUNUSED_NO_34 = 34,
	
	PSC1_MDUNUSED_NO_35 = 35,
	
	PSC1_MDUNUSED_NO_38 = 38,
	
	PSC1_MDUNUSED_NO_39 = 39,
	
	PSC1_MDUNUSED_NO_43 = 43,
	
	PSC1_MDUNUSED_NO_44 = 44,
	
	PSC1_MDUNUSED_NO_45 = 45,
	
	PSC1_MDUNUSED_NO_46 = 46
} CSL_PSC1_MDUNUSED;
 

#ifdef __cplusplus
}
#endif

#endif  /* CSL_PSC_H_ */
