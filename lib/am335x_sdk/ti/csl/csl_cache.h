/**
 *   @file  csl_cache.h
 *
 *   @brief
 *      This is the CACHE Auxilary Header File which exposes the various
 *      CSL Functional Layer API's to configure the CACHE Module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2002, 2003, 2004, 2005, 2008, 2009, 2016 Texas Instruments, Inc.
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

/** @defgroup CSL_CACHE_API CACHE
 *
 * @section Introduction
 *
 * @subsection xxx Overview
 * This page describes the Functions, Data Structures, Enumerations and Macros
 * within CACHE module.
 *
 * This module uses three cache architectures, Level 1 Program (L1P), Level 1
 * Data (L1D) and Level 2 CACHE architectures, The L1P and L1D can be
 * configured as 0K, 4K, 8K, 16K, or 32K CACHE size. The L2 can be configured
 * as 32KB, 64KB, 128KB, or 256KB CACHE size. This CACHE module supports the
 * Block and Global Coherence Operations.
 *
 * @subsection References
 *    -# TMS320TCI6484 Data Sheet SPRS438 (Dec 2007)
 *
 */

#ifndef CSL_CACHE_H
#define CSL_CACHE_H

#ifdef __cplusplus
extern "C" {
#endif

#include <ti/csl/csl.h>
#include <ti/csl/cslr_cgem.h>
#include <ti/csl/soc.h>

/**
@defgroup CSL_CACHE_SYMBOL  CACHE Symbols Defined
@ingroup CSL_CACHE_API
*/
/**
@defgroup CSL_CACHE_ENUM  CACHE Enumerated Data Types
@ingroup CSL_CACHE_API
*/
/**
@defgroup CSL_CACHE_FUNCTION  CACHE Functions
@ingroup CSL_CACHE_API
*/


/**
@addtogroup CSL_CACHE_SYMBOL
@{
*/
/** L2 Line Size */
#define CACHE_L2_LINESIZE    ((uint32_t)128U)
/** L1D Line Size */
#define CACHE_L1D_LINESIZE    ((uint32_t)64)
/** L1P Line Size */
#define CACHE_L1P_LINESIZE    ((uint32_t)32)

/** Handle to the CGEM Register Layer */
#if defined (SOC_OMAPL137) || defined (SOC_OMAPL138)
#define hCache      ((CSL_CgemRegs *)CSL_INTC_0_REGS)
#else
#define hCache      ((CSL_CgemRegs *)CSL_C66X_COREPAC_REG_BASE_ADDRESS_REGS)
#endif

/** Cache Round to Line size */
#define CACHE_ROUND_TO_LINESIZE(CACHE,ELCNT,ELSIZE)\
( ( ( ( (ELCNT) * (ELSIZE)\
        + CACHE_##CACHE##_LINESIZE - 1\
      ) / CACHE_##CACHE##_LINESIZE\
      * CACHE_##CACHE##_LINESIZE\
    ) + (ELSIZE) - 1\
  ) / (ELSIZE)\
)
/**
@}
*/

/******************************************************************************\
* global macro declarations
\******************************************************************************/

/** @addtogroup CSL_CACHE_ENUM
 @{ */

/**
 *  \anchor CACHE_Wait
 *  \name Cache wait flags
 *
 *  @{
 */
typedef uint32_t CACHE_Wait;
/** \brief No blocking, the call exits after programmation of the
     *  control registers
     */
#define CACHE_NOWAIT                            ((uint32_t) 0U)

/** \brief Blocking Call, the call exits after the relevant cache
 *  status registers indicate completion. For block coherence
 *  this waits on the Word count register to be come 0 along
 *  with invalidating the prefetch buffer.
 */
#define CACHE_WAIT                              ((uint32_t) 1U)

/** \brief Blocking Call, For block coherence this uses the MFENCE to
 *  wait for completion, along with invalidating the prefetch
 *  buffer.
 */
#define CACHE_FENCE_WAIT                        ((uint32_t) 2U)

/** \brief Blocking Call, the call exits after the relevant cache
 *  status registers indicate completion. For block coherence
 *  this waits on the Word count register to be come 0.
 */
#define CACHE_ONLY_WAIT                         ((uint32_t) 3U)

/** \brief Blocking Call, For block coherence this uses the MFENCE only to
 * wait for completion
 */
#define CACHE_FENCE_ONLY_WAIT                   ((uint32_t) 4U)

/** @} */

/**
 *  \anchor CACHE_L1Size
 *  \name L1 (P or D) Sizes
 *
 *  @{
 */
typedef uint32_t CACHE_L1Size;
/** \brief No Cache    */
#define CACHE_L1_0KCACHE    ((uint32_t) 0U)
/** \brief 4KB Cache   */
#define CACHE_L1_4KCACHE    ((uint32_t) 1U)
/** \brief 8KB Cache   */
#define CACHE_L1_8KCACHE    ((uint32_t) 2U)
/** \brief 16KB Cache  */
#define CACHE_L1_16KCACHE   ((uint32_t) 3U)
/** \brief 32KB Cache  */
#define CACHE_L1_32KCACHE   ((uint32_t) 4U)
/** \brief MAX Cache Size */
#define CACHE_L1_MAXIM1     ((uint32_t) 5U)
/** \brief MAX Cache Size */
#define CACHE_L1_MAXIM2     ((uint32_t) 6U)
/** \brief MAX Cache Size */
#define CACHE_L1_MAXIM3     ((uint32_t) 7U)

/** @} */



/** For devices that have maximum caches less
 * than the defined values, setting a higher value
 * will map to maximum cache
 */
/**
 *  \anchor CACHE_L2Size
 *  \name L2 Sizes
 *
 *  @{
 */
typedef uint32_t CACHE_L2Size;
/** \brief No Cache     */
#define CACHE_0KCACHE       ((uint32_t) 0U)
/** \brief 32KB Cache   */
#define CACHE_32KCACHE      ((uint32_t) 1U)
/** \brief 64KB Cache   */
#define CACHE_64KCACHE      ((uint32_t) 2U)
/** \brief 128KB Cache  */
#define CACHE_128KCACHE     ((uint32_t) 3U)
/** \brief 256KB Cache  */
#define CACHE_256KCACHE     ((uint32_t) 4U)
/** \brief 512KB Cache  */
#define CACHE_512KCACHE     ((uint32_t) 5U)
/** \brief 1024KB Cache  */
#define CACHE_1024KCACHE    ((uint32_t) 6U)
/** @} */
/**
@}
*/

#ifdef __cplusplus
}
#endif

#endif /*CSL_CACHE_H*/
