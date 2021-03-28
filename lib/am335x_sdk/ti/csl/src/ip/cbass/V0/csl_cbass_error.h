/*
 *   Copyright (c) Texas Instruments Incorporated 2019
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
 *  \ingroup CSL_CBASS
 *  \defgroup CSL_CBASS_ERR CBASS Error
 *
 *  @{
 */
/**
 *  \file     csl_cbass_error.h
 *
 *  \brief    This file contains the prototypes of the APIs present in the
 *            device abstraction layer file of CBASS Error reporting and interrupt.
 *            This also contains some related macros.
 */

#ifndef CBASS_ERR_H_
#define CBASS_ERR_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "ti/csl/cslr_cbass.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CSL_CBASS_ERR_API CBASS Error API
 */
/**
@defgroup CSL_CBASS_ERR_DATATYPE CBASS Error Data Types
@ingroup CSL_CBASS_ERR_API
*/
/**
@defgroup CSL_CBASS_ERR_DATASTRUCT CBASS Error Data Structures
@ingroup CSL_CBASS_ERR_API
*/
/**
@defgroup CSL_CBASS_ERR_FUNCTION  CBASS Error Functions
@ingroup CSL_CBASS_ERR_API
*/

/** ===========================================================================
 *  @addtogroup CSL_CBASS_ERR_DATATYPE
    @{
 * ============================================================================
 */

/* ========================================================================== */
/*                            Macros & Typedefs                               */
/* ========================================================================== */

/** @} */

/** ============================================================================
 *  @addtogroup CSL_CBASS_ERR_DATASTRUCT
    @{
 * =============================================================================
 */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/**
 * \brief  Structure for accessing CBASS error module
 *         exception logging header registers.
 */
typedef struct CSL_CbassErrExcepLogHdr
{
    uint32_t header[2U];
    /**< Exception logging header0 and header 1 */
}CSL_CbassErrExcepLogHdr_t;

/**
 * \brief  Structure for accessing CBASS error module
 *         exception logging data registers.
 */
typedef struct CSL_CbassErrExcepLogData
{
    uint32_t data[4U];
    /**< Exception logging data0 - data3 */
}CSL_CbassErrExcepLogData_t;

/**
 * \brief  Structure for accessing CBASS error module
 *         static registers.
 */
typedef struct {
    volatile uint32_t PID;
    /**< Revision Register */
    volatile uint32_t DESTINATION_ID;
    /**< Destination ID Register */
} CSL_CbassErrStaticRegs;


/** @} */

/** ===========================================================================
 *  @addtogroup CSL_CBASS_ERR_FUNCTION
    @{
 * ============================================================================
 */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Get the revision info of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 * \param   pRevInfo        Pointer to revision info
 *
 * \return  status          CBASS error module get revision status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrGetRevision(const CSL_cbass_errRegs *pErrRegs,
                                uint32_t                *pRevInfo);

/**
 * \brief   Set the destination ID of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 * \param   destId          Destination ID
 *
 * \return  status          CBASS error module set destination ID status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrSetDestID(const CSL_cbass_errRegs *pErrRegs,
                              uint32_t                 destId);

/**
 * \brief   Get the destination ID of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 * \param   pDestId         Pointer to destination ID
 *
 * \return  status          CBASS error module get destination ID status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrGetDestID(const CSL_cbass_errRegs *pErrRegs,
                              uint32_t                *pDestId);

/**
 * \brief   Get the exception logging header of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 * \param   pExLogHdr       Pointer to exception logging header,
 *                          ref #CSL_CbassErrExcepLogHdr_t
 *
 * \return  status          CBASS error module get exception logging header status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrGetExcepLogHdr(const CSL_cbass_errRegs   *pErrRegs,
                                   CSL_CbassErrExcepLogHdr_t *pExLogHdr);

/**
 * \brief   Get the exception logging data of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 * \param   pExLogData      Pointer to exception logging data,
 *                          ref #CSL_CbassErrExcepLogData_t
 *
 * \return  status          CBASS error module get exception logging data status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrGetExcepLogData(const CSL_cbass_errRegs    *pErrRegs,
                                    CSL_CbassErrExcepLogData_t *pExLogData);

/**
 * \brief  Set raw interrupt status of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 *
 * \param   intrMask        raw interrupts to set.
 *
 * \return  status          CBASS error module set raw interrupt status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrSetIntrRawStatus(const CSL_cbass_errRegs *pErrRegs,
                                     uint32_t                 intrMask);

/**
 * \brief   Get the pending raw interrupt of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 *
 * \param   pIntrStatus     Pointer to pending raw interrupt status/occurred.
 *
 * \return  status          CBASS error module get pending raw interrupt status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrGetIntrRawStatus(const CSL_cbass_errRegs *pErrRegs,
                                     uint32_t                *pIntrStatus);

/**
 * \brief  Clear interrupts of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 *
 * \param   intrMask        Interrupts to clear.
 *
 * \return  status          CBASS error module clear interrupt status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrClearIntr(const CSL_cbass_errRegs *pErrRegs,
                              uint32_t                 intrMask);

/**
 * \brief   Get the pending interrupt of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 *
 * \param   pIntrStatus     Pointer to pending interrupt status/occurred.
 *
 * \return  status          CBASS error module get pending interrupt status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrGetIntrStatus(const CSL_cbass_errRegs *pErrRegs,
                                  uint32_t                *pIntrStatus);

/**
 * \brief  Enable interrupts of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 *
 * \param   intrMask        Interrupts to enable.
 *
 * \return  status          CBASS error module enalbe interrupt status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrEnableIntr(const CSL_cbass_errRegs *pErrRegs,
                               uint32_t                 intrMask);

/**
 * \brief  Disable interrupts of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 *
 * \param   intrMask        Interrupts to disable.
 *
 * \return  status          CBASS error module disable interrupt status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrDisableIntr(const CSL_cbass_errRegs *pErrRegs,
                                uint32_t                 intrMask);

/**
 * \brief  Set the ERR_EOI register of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 *
 * \param   eoi             EOI value to set to ERR_EOI register.
 *
 * \return  status          CBASS error module set EOI status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrSetEOI(const CSL_cbass_errRegs *pErrRegs,
                           uint32_t                 eoi);

/**
 * \brief   Get the EOI value of CBASS Error reporting module
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_errRegs *) to the base
 *                          address of the CBASS error reporting module.
 *
 * \param   pEoi            Pointer to EOI value.
 *
 * \return  status          CBASS error module get EOI value status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 */
int32_t CSL_cbassErrGetEOI(const CSL_cbass_errRegs *pErrRegs,
                           uint32_t                *pEoi);

/**
 * \brief   This API is used to read static registers of CBASS QoS module.
 *          This API needs to be called after the initial configuration is done and
 *          hence mutliple read between static registers do not change the values
 *
 * \param   pErrRegs        Pointer (of type CSL_cbass_qosRegs_ep *) to the base
 *                          address of the CBASS QoS module.
 * \param   pStaticRegs     pointer to static registers to be read
 *                          ref #CSL_CbassErrStaticRegs
 *
 * \return                  CSL_PASS - success
 *                          CSL_EBADARGS - API fails due to bad input arguments
 */
int32_t CSL_cbassErrReadStaticRegs (const CSL_cbass_errRegs *pErrRegs,
                                    CSL_CbassErrStaticRegs  *pStaticRegs);

/** @} */

#ifdef __cplusplus
}

#endif /*extern "C" */

#endif
 /** @} */
