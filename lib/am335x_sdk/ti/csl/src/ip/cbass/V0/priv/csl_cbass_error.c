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
 *  \file     csl_cbass_error.c
 *
 *  \brief    This file contains the implementation of the APIs present in the
 *            device abstraction layer file of CBASS error reporting module.
 *            This also contains some related macros.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/csl_types.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/cslr_cbass.h>
#include <ti/csl/src/ip/cbass/V0/csl_cbass_error.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/**
 * Requirement: REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrGetRevision(const CSL_cbass_errRegs *pErrRegs,
                                uint32_t                *pRevInfo)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        (pRevInfo == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pRevInfo = pErrRegs->PID;
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5695)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrSetDestID(const CSL_cbass_errRegs *pErrRegs,
                              uint32_t                 destId)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        (destId > CSL_CBASS_ERR_DESTINATION_ID_DEST_ID_MAX))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        HW_WR_FIELD32(&pErrRegs->DESTINATION_ID,
                      CSL_CBASS_ERR_DESTINATION_ID_DEST_ID,
                      destId);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrGetDestID(const CSL_cbass_errRegs *pErrRegs,
                              uint32_t                *pDestId)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        (pDestId == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pDestId = HW_RD_FIELD32(&pErrRegs->DESTINATION_ID,
                                 CSL_CBASS_ERR_DESTINATION_ID_DEST_ID);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrGetExcepLogHdr(const CSL_cbass_errRegs   *pErrRegs,
                                   CSL_CbassErrExcepLogHdr_t *pExLogHdr)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        (pExLogHdr == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        pExLogHdr->header[0] = pErrRegs->EXCEPTION_LOGGING_HEADER0;
        pExLogHdr->header[1] = pErrRegs->EXCEPTION_LOGGING_HEADER1;
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrGetExcepLogData(const CSL_cbass_errRegs    *pErrRegs,
                                    CSL_CbassErrExcepLogData_t *pExLogData)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        (pExLogData == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        pExLogData->data[0] = pErrRegs->EXCEPTION_LOGGING_DATA0;
        pExLogData->data[1] = pErrRegs->EXCEPTION_LOGGING_DATA1;
        pExLogData->data[2] = pErrRegs->EXCEPTION_LOGGING_DATA2;
        pExLogData->data[3] = pErrRegs->EXCEPTION_LOGGING_DATA3;
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5695)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrSetIntrRawStatus(const CSL_cbass_errRegs *pErrRegs,
                                     uint32_t                 intrMask)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        ((intrMask & (~CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MASK)) != ((uint32_t)0U)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        HW_WR_FIELD32(&pErrRegs->ERR_INTR_RAW_STAT,
                      CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR,
                      intrMask);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrGetIntrRawStatus(const CSL_cbass_errRegs *pErrRegs,
                                     uint32_t                *pIntrStatus)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        (pIntrStatus == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pIntrStatus = HW_RD_FIELD32(&pErrRegs->ERR_INTR_RAW_STAT,
                                     CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5695)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrClearIntr(const CSL_cbass_errRegs *pErrRegs,
                              uint32_t                 intrMask)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        ((intrMask & (~CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MASK)) != ((uint32_t)0U)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        HW_WR_FIELD32(&pErrRegs->ERR_INTR_ENABLED_STAT,
                      CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR,
                      intrMask);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrGetIntrStatus(const CSL_cbass_errRegs *pErrRegs,
                                  uint32_t                *pIntrStatus)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        (pIntrStatus == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pIntrStatus = HW_RD_FIELD32(&pErrRegs->ERR_INTR_ENABLED_STAT,
                                     CSL_CBASS_ERR_ERR_INTR_ENABLED_STAT_ENABLED_INTR);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5695)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrEnableIntr(const CSL_cbass_errRegs *pErrRegs,
                               uint32_t                 intrMask)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        ((intrMask & (~CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MASK)) != ((uint32_t)0U)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        HW_WR_FIELD32(&pErrRegs->ERR_INTR_ENABLE_SET,
                      CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR,
                      intrMask);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5695)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrDisableIntr(const CSL_cbass_errRegs *pErrRegs,
                                uint32_t                 intrMask)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        ((intrMask & (~CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MASK)) != ((uint32_t)0U)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        HW_WR_FIELD32(&pErrRegs->ERR_INTR_ENABLE_CLR,
                      CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR,
                      intrMask);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5695)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrSetEOI(const CSL_cbass_errRegs *pErrRegs,
                           uint32_t                 eoi)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        (eoi > CSL_CBASS_ERR_EOI_WR_MAX))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        HW_WR_FIELD32(&pErrRegs->EOI,
                      CSL_CBASS_ERR_EOI_WR,
                      eoi);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrGetEOI(const CSL_cbass_errRegs *pErrRegs,
                           uint32_t                *pEoi)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        (pEoi == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pEoi = HW_RD_FIELD32(&pErrRegs->EOI,
                              CSL_CBASS_ERR_EOI_WR);
        status = CSL_PASS;
    }
    return status;
}

/**
 * Requirement: REQ_TAG(PRSDK-5257) REQ_TAG(PRSDK-5694)
 * Design: did_csl_cbass
 */
int32_t CSL_cbassErrReadStaticRegs (const CSL_cbass_errRegs *pErrRegs,
                                    CSL_CbassErrStaticRegs  *pStaticRegs)
{
    int32_t  status;

    if ((pErrRegs == (NULL_PTR))    ||
        (pStaticRegs == (NULL_PTR)))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        pStaticRegs->PID = pErrRegs->PID;
        pStaticRegs->DESTINATION_ID = pErrRegs->DESTINATION_ID & \
                                      CSL_CBASS_ERR_DESTINATION_ID_DEST_ID_MASK;
        status = CSL_PASS;
    }
    return status;
}
