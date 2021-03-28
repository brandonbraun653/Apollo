/**
 * @file  csl_slv_tog.h
 *
 * @brief
 *  Header file containing various enumerations, structure definitions and function
 *  declarations for the VBUSM Slave Timeout Gasket IP.
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
 *    Neither the name of Texas Instruments Incorposlv_toged nor the names of
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
#ifndef CSL_SLV_TOG_H_
#define CSL_SLV_TOG_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/cslr_tog.h>
#include <ti/csl/csl_types.h>

/** ===========================================================================
 *
 * @defgroup CSL_SLV_TOG_API SLV_TOG API
 *
 * @section Introduction
 *
 * @subsection Overview
 *  This is the CSL-FL API documentation for the VBUSM Slave Timeout Gasket module.
 *
 *  The following procedure describes how to properly use this CSL-FL API:
 *
 *  1. Call #CSL_slvTogSetTimeoutVal to configure the desired timeout
 *     counter value if you wish a shorter timeout than the default maximum
 *     timeout.
 *  2. Enable/disable interrupt sources as needed by calling
 *     #CSL_slvTogSetIntrEnable. Note that all interrupt sources are
 *     enabled by default.
 *  3. Call #CSL_slvTogStart to start the timer counting
 *  4. If an interrupt is signaled from the gasket, then...
 *     a) Call #CSL_slvTogGetIntrPending to determine the pending interrupt
 *        sources
 *     b) Clear interrupt source(s) by calling #CSL_slvTogClrIntrPending
 *     c) Service the cause of the interrupt as needed. If the system
 *        determines that it needs to flush all outstanding transactions
 *        (for instance, because the main SoC is in an error condition and is
 *        going to be reset), software may do this by calling
 *        #CSL_slvTogSetFlushModeEnable with true. Once all transactions
 *        are flushed, software should exit Flush mode by calling
 *        #CSL_slvTogSetFlushModeEnable with false. If the destination side
 *        is in reset, this should trigger hardware flush, keeping the gasket
 *        returning any transactions that arrive.
 *     d) The #CSL_slvTogGetErrInfo function can be called to get detailed
 *        information about the error if needed. 
 *     e) Ack the interrupt by calling #CSL_slvTogGetIntrCount and
 *        #CSL_slvTogAckIntr
 * ============================================================================
 */
/**
@defgroup CSL_SLV_TOG_DATASTRUCT  SLV_TOG Data Structures
@ingroup CSL_SLV_TOG_API
*/
/**
@defgroup CSL_SLV_TOG_FUNCTION  SLV_TOG Functions
@ingroup CSL_SLV_TOG_API
*/
/**
@defgroup CSL_SLV_TOG_ENUM SLV_TOG Enumerated Data Types
@ingroup CSL_SLV_TOG_API
*/

/** ===========================================================================
 *  @addtogroup CSL_SLV_TOG_ENUM
    @{
 * ============================================================================
 */
 
 /** ---------------------------------------------------------------------------
 * @brief This enumerator defines the possible timeout interrupt sources
 *
 *  \anchor CSL_SlvTogIntrSrc
 *  \name Timeout interrupt sources
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_SlvTogIntrSrc;
    /** Transaction timeout */
#define CSL_SLV_TOG_INTRSRC_TRANSACTION_TIMEOUT ((uint32_t) 1U<<0)
    /** Unexpected response */
#define CSL_SLV_TOG_INTRSRC_UNEXPECTED_RESPONSE ((uint32_t) 1U<<1)
    /** Command timeout */
#define CSL_SLV_TOG_INTRSRC_COMMAND_TIMEOUT     ((uint32_t) 1U<<2)
    /** All interrupt sources */
#define CSL_SLV_TOG_INTRSRC_ALL                 (CSL_SLV_TOG_INTRSRC_TRANSACTION_TIMEOUT | CSL_SLV_TOG_INTRSRC_UNEXPECTED_RESPONSE | CSL_SLV_TOG_INTRSRC_COMMAND_TIMEOUT)
/* @} */

/** @} */

/** ============================================================================
 *  @addtogroup CSL_SLV_TOG_DATASTRUCT
    @{
 * =============================================================================
 */

/** ---------------------------------------------------------------------------
 * @brief   This structure contains timeout error information 
 *
 * ----------------------------------------------------------------------------
 */
typedef struct
{
    /** Route ID - This indicates the Route ID of the captured transaction */
    uint32_t    routeId;
    /** Order ID - This indicates the Order ID of the captured transaction */
    uint32_t    orderId;
    /** Direction - This indicates whether the captured transaction was a read (1) or a write (0) */
    uint32_t    dir;
    /** Type - This indicates the error type: 0=Transaction Timeout, 1=Unexpected Response */
    uint32_t    type;
    /** Tag - This indicates the CID/RID/SID of the transaction */
    uint32_t    tag;
    /** Command ID - This indicates the original Command ID (SID/RID) of the command.
        This field is only valid on a Timeout Error, not on an Unexpected Transaction Error */
    uint32_t    commandId;
    /** Original Byte Count - If this is a timed out transaction, then this field
        represents the CBYTECNT value of the original command.  If this is an
        unexpected response transaction, then this field contains the value of
        the bytecnt of the unexpected transaction (sbytecnt or rbytecnt). */
    uint32_t    orgByteCnt;
    /** Current Byte Count - If this is a timed out transaction, this is the number of
        bytes that were not returned as of the time the transaction timed out.  If this
        is an unexpected response transaction, then this field is not applicable. */
    uint32_t    currByteCnt;
    /** Address - If the captured transaction was a Timeout Error, this field represents
        the address of the original transaction. If the error was an Unexpected Response
        error, then this field is not applicable. */
    uint64_t    address;
} CSL_SlvTogErrInfo;

/** @} */


/** ===========================================================================
 *  @addtogroup CSL_SLV_TOG_FUNCTION
    @{
 * ============================================================================
 */

/**
 *  \brief Get module revision information
 *
 *  This function returns the revision information for the module.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param pRev         [OUT]   Pointer where revision value is returned
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs or pRev are NULL
 */
extern int32_t CSL_slvTogGetRevision( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pRev );

/**
 *  \brief Get module configuration information
 *
 *  This function returns the total number of read and write scoreboard slots
 *  configured in the module. 
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param pTotalReads  [OUT]   Pointer where the total number of read slots
 *                              is returned
 *  \param pTotalWrites [OUT]   Pointer where the total number of write slots
 *                              is returned
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs, pTotalReads, or pTotalWrites are NULL
 */
extern int32_t CSL_slvTogGetCfg( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pTotalReads, uint32_t *pTotalWrites );

/**
 *  \brief Get module status information
 *
 *  This function returns the current number of occupied read and write
 *  scoreboard slots. 
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param pCurrReads   [OUT]   Pointer where the current number of occupied
 *                              read slots is returned
 *  \param pCurrWrites  [OUT]   Pointer where the current number of occupied
 *                              write slots is returned
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs, pCurrReads, or pCurrWrites are NULL
 */
extern int32_t CSL_slvTogGetStatus( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pCurrReads, uint32_t *pCurrWrites );

/**
 *  \brief Get timeout error information
 *
 *  This function returns information about a captured transaction.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param pErrInfo     [OUT]   Pointer where the current number of occupied
 *                              read slots is returned
 *
 *  \return CSL_PASS    The function completed successfully and pErrInfo
 *                      contains valid information
 *          CSL_EFAIL   The function failed and there is no valid information
 *                      in pErrInfo. This is because...
 *                      a) pRegs or pErrInfo are NULL
 *                      b) there is no error pending
 *                      c) the error pending did not have any captured
 *                         information because there was an error pending in front
 *                         of it that had already captured information.
 */
extern int32_t CSL_slvTogGetErrInfo( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogErrInfo *pErrInfo );

/**
 *  \brief Get masked (enabled) pending interrupt sources
 *
 *  This function returns the masked (enabled) pending interrupt sources.
 *
 *  The value returned is a logical OR of the masked pending interrupt sources
 *  defined in #CSL_SlvTogIntrSrc.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param pPendInts    [OUT]   Pointer where pending interrupt sources is returned
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs or pPendInts are NULL
 */
extern int32_t CSL_slvTogGetIntrPending( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pPendInts );

/**
 *  \brief Get raw pending interrupt sources
 *
 *  This function returns the raw pending interrupt sources.
 *
 *  The value returned is a logical OR of the raw pending interrupt sources
 *  defined in #CSL_SlvTogIntrSrc.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param pRawPendInts [OUT]   Pointer where raw pending interrupt sources is returned
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs or pRawPendInts are NULL
 */
extern int32_t CSL_slvTogGetRawIntrPending( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pRawPendInts );

/**
 *  \brief Set interrupt source(s)
 *
 *  This function allows software to set the specified interrupt source(s).
 *
 *  The intrSrcs value is composed of a logical OR of the desired interrupt
 *  sources defined in #CSL_SlvTogIntrSrc.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param intrSrcs     [IN]    Interrupt source(s) to set
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs is NULL or intrSrcs is 0
 */
extern int32_t CSL_slvTogSetIntrPending( CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogIntrSrc intrSrcs );

/**
 *  \brief Clear pending interrupt source(s)
 *
 *  This function allows software to clear the specified pending interrupt
 *  source(s).
 *
 *  The intrSrcs value is composed of a logical OR of the desired interrupt
 *  sources defined in #CSL_SlvTogIntrSrc.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param intrSrcs     [IN]    Interrupt source(s) to clear
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs is NULL or intrSrcs is 0
 */
extern int32_t CSL_slvTogClrIntrPending( CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogIntrSrc intrSrcs );

/**
 *  \brief Enable/disable interrupt source(s)
 *
 *  This function allows software to enable or disable the specified interrupt
 *  source(s).
 *
 *  The intrSrcs value is composed of a logical OR of the desired interrupt
 *  sources defined in #CSL_SlvTogIntrSrc.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param intrSrcs     [IN]    Interrupt source(s) to clear
 *  \param bEnable      [IN]    If true, the interrupt source(s) are enabled.
 *                              If false, they are disabled.
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs is NULL or intrSrcs is 0
 */
extern int32_t CSL_slvTogSetIntrEnable( CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogIntrSrc intrSrcs, bool bEnable );

/**
 *  \brief Get interrupt count
 *
 *  This function returns the number of pending interrupts corresponding to
 *  the specified interrupt source intrSrc as follows:
 *      0 = No pending interrupts
 *      1 = One pending interrupt
 *      2 = Two pending interrupts
 *      3 = Three or more pending interrupts
 *
 *  Valid values of intrSrc are:
 *      - CSL_SLV_TOG_INTRSRC_TRANSACTION_TIMEOUT
 *      - CSL_SLV_TOG_INTRSRC_UNEXPECTED_RESPONSE
 *  
 *  CSL_EFAIL is returned if intrSrc is:
 *      - CSL_SLV_TOG_INTRSRC_COMMAND_TIMEOUT
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param intrSrc      [IN]    Interrupt source
 *  \param pIntrCnt     [OUT]   Pointer where interrupt count is returned
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs or pIntrCnt are NULL, or intrSrc is invalid
 */
extern int32_t CSL_slvTogGetIntrCount( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogIntrSrc intrSrc, uint32_t *pIntrCnt );

/**
 *  \brief Ack interrupt source
 *
 *  This function acknowledges an interrupt source by decrementing the number
 *  of pending interrupts corresponding to the specified interrupt source
 *  intrSrc by the specified ackCnt count.
 *
 *  Valid values of intrSrc are:
 *      - CSL_SLV_TOG_INTRSRC_TRANSACTION_TIMEOUT
 *      - CSL_SLV_TOG_INTRSRC_UNEXPECTED_RESPONSE
 *  
 *  CSL_EFAIL is returned if intrSrc is:
 *      - CSL_SLV_TOG_INTRSRC_COMMAND_TIMEOUT
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param intrSrc      [IN]    Interrupt source
 *  \param ackCnt       [IN]    Decrement count
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs is NULL, intrSrc is invalid, or
 *                                  ackCnt == 0 or is > # of pending interrupts
 */
extern int32_t CSL_slvTogAckIntr( CSL_ksbus_vbusm_to_gasketRegs *pRegs, CSL_SlvTogIntrSrc intrSrc, uint32_t ackCnt );

/**
 *  \brief Set the timeout value
 *
 *  This function sets the desired timeout value.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param timeoutVal   [IN]    Timeout count value
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs is NULL
 */
extern int32_t CSL_slvTogSetTimeoutVal( CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t timeoutVal );

/**
 *  \brief Start the timer counter
 *
 *  This function starts the timer counter.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs is NULL
 */
extern int32_t CSL_slvTogStart( CSL_ksbus_vbusm_to_gasketRegs *pRegs );

/**
 *  \brief Stop the timer counter
 *
 *  This function stops the timer counter.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs is NULL
 */
extern int32_t CSL_slvTogStop( CSL_ksbus_vbusm_to_gasketRegs *pRegs );

/**
 *  \brief Reset the timeout functionality
 *
 *  This function resets the timeout functionality by stopping the timer
 *  counter and clearing the timer and eon counters to 0. 
 *
 *  Note that the timeout value set via the #CSL_slvTogSetTimeoutVal
 *  function is unaffected by this function.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs is NULL
 */
extern int32_t CSL_slvTogReset( CSL_ksbus_vbusm_to_gasketRegs *pRegs );

/**
 *  \brief Get the current timer count value
 *
 *  This function returns the current timer count value. This value includes
 *  the eon value in bits [31:30] and the free-running counter in bits [29:0].
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param pTimerCnt    [OUT]   Pointer where the current timer count value
 *                              is returned
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs or pTimerCnt are NULL
 */
extern int32_t CSL_slvTogGetCurrTimerCnt( const CSL_ksbus_vbusm_to_gasketRegs *pRegs, uint32_t *pTimerCnt );

/**
 *  \brief Enable/disable flush mode
 *
 *  This function allows software to enable/disable flush mode.
 *
 *  \param pRegs        [IN]    Pointer to the Timeout gasket registers
 *  \param bEnable      [IN]    If true, flush mode is enabled.
 *                              If false, it is disabled.
 *
 *  \return             CSL_PASS    The function completed successfully
 *                      CSL_EFAIL   pRegs is NULL
 */
extern int32_t CSL_slvTogSetFlushModeEnable( CSL_ksbus_vbusm_to_gasketRegs *pRegs, bool bEnable );

/** @} */

#ifdef __cplusplus
}
#endif

#endif
