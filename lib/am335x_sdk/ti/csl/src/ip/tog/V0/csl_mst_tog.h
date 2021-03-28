/**
 * @file  csl_mst_tog.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the VBUSM Master Timeout Gasket IP.
 *  \par
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
 *    Neither the name of Texas Instruments Incorpomst_toged nor the names of
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
#ifndef CSL_MST_TOG_H_
#define CSL_MST_TOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr.h>

/** ===========================================================================
 *
 * @defgroup CSL_MST_TOG_API MST_TOG API
 *
 * @section Introduction
 *
 * @subsection Overview
 *  This is the CSL-FL API documentation for the VBUSM Master Timeout Gasket module.
 *
 *  The following procedure describes how to properly use this CSL-FL API:
 *
 *  1. Call #CSL_mstTogSetTimeoutVal to configure the desired timeout
 *     counter value
 *  2. Call #CSL_mstTogStart to start the timeout functionality
 *
 *  Whenever a read return or write status return is pending without being
 *  accepted, an internal timer increments by 1. Whenever the counter value
 *  meets or exceeds the programmed value, the gasket is in a timed out state
 *  and the following actions are taken:
 *  - timed_out_intr is set
 *  - All requests from the master are blocked
 *  - All readies from the master are set high
 *  - Once all transactions are returned, the gasket indicates idle
 *
 *  Following servicing of the timeout interrupt, software should...
 *
 *  3. Call #CSL_mstTogReset to reset the timeout interrupt and timeout counter
 *  4. Call #CSL_mstTogStart to start the timeout functionality
 * ============================================================================
 */
/**
@defgroup CSL_MST_TOG_DATASTRUCT  MST_TOG Data Structures
@ingroup CSL_MST_TOG_API
*/
/**
@defgroup CSL_MST_TOG_FUNCTION  MST_TOG Functions
@ingroup CSL_MST_TOG_API
*/
/**
@defgroup CSL_MST_TOG_ENUM MST_TOG Enumerated Data Types
@ingroup CSL_MST_TOG_API
*/

/** ===========================================================================
 *  @addtogroup CSL_MST_TOG_ENUM
    @{
 * ============================================================================
 */
 
 /** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible timeout values
 *
 *  \anchor CSL_MstTogVal
 *  \name Timeout values
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_MstTogVal;
    /** 1024 clock cycles */
#define CSL_MST_TOG_VAL_1K          ((uint32_t) 0U)
    /** 4096 clock cycles */
#define CSL_MST_TOG_VAL_4K          ((uint32_t) 1U)
    /** 16,384 clock cycles */
#define CSL_MST_TOG_VAL_16K         ((uint32_t) 2U)
    /** 65,536 clock cycles */
#define CSL_MST_TOG_VAL_64K         ((uint32_t) 3U)
    /** 262,144 clock cycles */
#define CSL_MST_TOG_VAL_256K        ((uint32_t) 4U)
    /** 1,048,576 clock cycles */
#define CSL_MST_TOG_VAL_1M          ((uint32_t) 5U)
    /** 2,097,152 clock cycles */
#define CSL_MST_TOG_VAL_2M          ((uint32_t) 6U)
    /** 4,194,303 clock cycles */
#define CSL_MST_TOG_VAL_4M_MINUS_1  ((uint32_t) 7U)
/* @} */

/** @} */

/** ===========================================================================
 *  @addtogroup CSL_MST_TOG_FUNCTION
    @{
 * ============================================================================
 */

/**
 *  \brief Set the timeout value
 *
 *  This function sets the desired timeout value. This function should only be
 *  called when the timeout is disabled.
 *
 *  \param baseAddr     [IN]    The address of the desired VBUSM Master Timeout
 *                              Gasket Control register
 *  \param timeoutVal   [IN]    Timeout count value. See #CSL_MstTogVal for
 *                              a list of valid timeout values.
 *
 *  \return CSL_PASS    Function completed successfully
 *          CSL_EFAIL   Timeout value cannot be set when the timeout counter is
 *                      running. Call #CSL_mstTogReset first.
 */
extern int32_t CSL_mstTogSetTimeoutVal( uintptr_t baseAddr, CSL_MstTogVal timeoutVal );

/**
 *  \brief Start the timeout function
 *
 *  This function starts the timeout counter functionality.
 *
 *  \param baseAddr     [IN]    The address of the desired VBUSM Master Timeout
 *                              Gasket Control register
 *
 *  \return None
 */
extern void CSL_mstTogStart( uintptr_t baseAddr );

/**
 *  \brief Stop the timeout function
 *
 *  This function stops the timeout counter functionality.
 *
 *  \param baseAddr     [IN]    The address of the desired VBUSM Master Timeout
 *                              Gasket Control register
 *
 *  \return None
 */
extern void CSL_mstTogStop( uintptr_t baseAddr );

/**
 *  \brief Force a timeout
 *
 *  This function enables software to force a timeout and flush of
 *  the interface transactions.
 *
 *  \param baseAddr     [IN]    The address of the desired VBUSM Master Timeout
 *                              Gasket Control register

 *  \return CSL_PASS    Function completed successfully
 *          CSL_EFAIL   Timeout function is disabled. Call
 *                      #CSL_mstTogStart first.
 */
extern int32_t CSL_mstTogForceTimeout( uintptr_t baseAddr );

/**
 *  \brief Reset the timeout functionality
 *
 *  This function resets the timeout functionality by clearing the timeout
 *  interrupt and timeout counter. It should be called after servicing a
 *  timeout interrupt and before re-enabling the timeout counter via the
 *  #CSL_mstTogStart function.
 *
 *  Note that the timeout value set via the #CSL_mstTogSetTimeoutVal
 *  function is unaffected.
 *
 *  \param baseAddr     [IN]    The address of the desired VBUSM Master Timeout
 *                              Gasket Control register
 *
 *  \return None
 */
extern void CSL_mstTogReset( uintptr_t baseAddr );

/** @} */

#ifdef __cplusplus
}
#endif

#endif
