/*
 * @file  csl_ecc_aggr.c
 *
 * @brief
 *  C implementation file for the ECC Aggregator module CSL.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2015-2019, Texas Instruments, Inc.
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
#include <ti/csl/csl_ecc_aggr.h>

/*===========================================================================*/
/*  Internal Functions                                                       */
/*===========================================================================*/
static bool CSL_ecc_aggrIsEccRamReadDone(const CSL_ecc_aggrRegs *pEccAggrRegs);
static bool CSL_ecc_aggrIsValidRamId(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId);
static bool CSL_ecc_aggrIsValidEccRamRegOffset(uint32_t regOffset);
static bool CSL_ecc_aggrIsValidIntrSrc(const CSL_Ecc_AggrIntrSrc intrSrc);
static bool CSL_ecc_aggrIsValidInstSel(uint32_t instSelect, uint32_t maxInst);
static bool CSL_ecc_aggrToggleEccRamIntrPending(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc, bool bSet);
static bool CSL_ecc_aggrToggleIntrEnable(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc, bool bEnable);
static bool CSL_ecc_aggrToggleIntrsEnable(const CSL_ecc_aggrRegs *pEccAggrRegs, CSL_Ecc_AggrIntrSrc intrSrc, bool bEnable);
static uintptr_t CSL_ecc_aggrStatusRegAddr(uintptr_t base, uint32_t n, uint32_t et);
static uintptr_t CSL_ecc_aggrSecStatusRegAddr(uintptr_t base, uint32_t n);
static uintptr_t CSL_ecc_aggrDedStatusRegAddr(uintptr_t base, uint32_t n);
static uintptr_t CSL_ecc_aggrDedEnableSetRegAddr(uintptr_t base, uint32_t n);
static uintptr_t CSL_ecc_aggrSecEnableSetRegAddr(uintptr_t base, uint32_t n);
static uintptr_t CSL_ecc_aggrDedEnableClrRegAddr(uintptr_t base, uint32_t n);
static uintptr_t CSL_ecc_aggrSecEnableClrRegAddr(uintptr_t base, uint32_t n);
static uintptr_t CSL_ecc_aggrEnableSetRegAddr(uintptr_t base, uint32_t n, uint32_t et);
static uintptr_t CSL_ecc_aggrEnableClrRegAddr(uintptr_t base, uint32_t n, uint32_t et);


static uintptr_t CSL_ecc_aggrDedEnableClrRegAddr(uintptr_t base, uint32_t n) 
{
    return ((base)+CSL_ECC_AGGR_DED_ENABLE_CLR_REG0+ (uint32_t)((n)*4U));
}

static uintptr_t CSL_ecc_aggrSecEnableClrRegAddr(uintptr_t base, uint32_t n) 
{ 
    return ((base)+CSL_ECC_AGGR_SEC_ENABLE_CLR_REG0+ (uint32_t)((n)*4U));
}

static uintptr_t CSL_ecc_aggrDedEnableSetRegAddr(uintptr_t base, uint32_t n) 
{
    return ((base)+CSL_ECC_AGGR_DED_ENABLE_SET_REG0+ (uint32_t)((n)*4U));
}

static uintptr_t CSL_ecc_aggrSecEnableSetRegAddr(uintptr_t base, uint32_t n) 
{ 
    return ((base)+CSL_ECC_AGGR_SEC_ENABLE_SET_REG0+ (uint32_t)((n)*4U));
}

static uintptr_t CSL_ecc_aggrEnableSetRegAddr(uintptr_t base, uint32_t n, uint32_t et) 
{
    uintptr_t addr;

    if (et == CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT)
    {
        addr = CSL_ecc_aggrSecEnableSetRegAddr(base,n);
    }
    else
    {
        addr = CSL_ecc_aggrDedEnableSetRegAddr(base,n);
    }
    return (addr);
}

static uintptr_t CSL_ecc_aggrEnableClrRegAddr(uintptr_t base, uint32_t n, uint32_t et)
{
    uintptr_t addr;

    if (et == CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT)
    {
        addr = CSL_ecc_aggrSecEnableClrRegAddr(base,n);
    }
    else
    {
        addr = CSL_ecc_aggrDedEnableClrRegAddr(base,n);
    }
    return (addr);
}

static uintptr_t  CSL_ecc_aggrSecStatusRegAddr(uintptr_t base, uint32_t n)
{
    return ((base)+CSL_ECC_AGGR_SEC_STATUS_REG0+(uint32_t)((n)*4U));
}

static uintptr_t  CSL_ecc_aggrDedStatusRegAddr(uintptr_t base, uint32_t n)
{
    return ((base)+CSL_ECC_AGGR_DED_STATUS_REG0+(uint32_t)((n)*4U));
}

static uintptr_t CSL_ecc_aggrStatusRegAddr(uintptr_t base, uint32_t n, uint32_t et) 
{
     return (((et)==CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT)? \
                    CSL_ecc_aggrSecStatusRegAddr(base,n): \
                    CSL_ecc_aggrDedStatusRegAddr(base,n));
}

static bool CSL_ecc_aggrIsEccRamReadDone(const CSL_ecc_aggrRegs *pEccAggrRegs)
{
    bool retVal = (bool)false;

    if( CSL_REG32_FEXT(&pEccAggrRegs->VECTOR, ECC_AGGR_VECTOR_RD_SVBUS_DONE) == 1U )
    {
        retVal = (bool)true;
    }
    return retVal;
}

static bool CSL_ecc_aggrIsValidRamId(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId)
{
    bool       retVal = (bool)false;
    uint32_t   numRams;
    int32_t    cslRet;

    /* read number of Rams*/
    cslRet = CSL_ecc_aggrGetNumRams(pEccAggrRegs, &numRams);

    if (cslRet == CSL_PASS)
    {
        if( ramId < numRams )
        {
            retVal = (bool)true;
        }
    }
    return retVal;
}

static bool CSL_ecc_aggrIsValidEccRamRegOffset(uint32_t regOffset)
{
    bool retVal = (bool)true;

    if( (regOffset < CSL_ECC_RAM_WRAP_REV) ||
        (regOffset > CSL_ECC_RAM_ERR_STAT3) )
    {
        retVal = (bool)false;
    }
    return retVal;
}

static bool CSL_ecc_aggrIsValidIntrSrc(const CSL_Ecc_AggrIntrSrc intrSrc)
{
    bool retVal = (bool)true;

    if( (intrSrc < CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT)      ||
        (intrSrc > CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT) )
    {
        retVal = (bool)false;
    }
    return retVal;
}

static bool CSL_ecc_aggrIsValidInstSel(uint32_t instSelect, uint32_t maxInst)
{
    bool retVal = (bool)true;

    if( instSelect >= maxInst )
    {
        retVal = (bool)false;
    }
    return retVal;
}

static bool CSL_ecc_aggrToggleEccRamIntrPending(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc, bool bSet)
{
    bool retVal = (bool)false;
    int32_t cslRet = CSL_EBADARGS;
    if( CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId) == (bool)true )
    {
        uint32_t regVal;

        retVal = (bool)true;
        if( intrSrc == CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT )
        {
            if( bSet == (bool)true )
            {
                regVal = CSL_FMK(ECC_RAM_ERR_STAT1_ECC_SEC, (uint32_t)1U);
            }
            else
            {
                regVal = CSL_FMK(ECC_RAM_ERR_STAT1_CLR_ECC_SEC, (uint32_t)1U);
            }
        }
        else if( intrSrc == CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT )
        {
            if( bSet == (bool)true )
            {
                regVal = CSL_FMK(ECC_RAM_ERR_STAT1_ECC_DED, (uint32_t)1U);
            }
            else
            {
                regVal = CSL_FMK(ECC_RAM_ERR_STAT1_CLR_ECC_DED, (uint32_t)1U);
            }
        }
        else if( intrSrc == CSL_ECC_ADDR_ERROR_TYPE_SUCCESSIVE_SINGLE_BITS )
        {
            if( bSet == (bool)true )
            {
                regVal = CSL_FMK(ECC_RAM_ERR_STAT1_ECC_OTHER, (uint32_t)1U);
            }
            else
            {
                regVal = CSL_FMK(ECC_RAM_ERR_STAT1_CLR_ECC_OTHER, (uint32_t)1U);
            }
        }
        else
        {
            retVal = (bool)false;
        }
        if( retVal == (bool)true )
        {
            cslRet = CSL_ecc_aggrWriteEccRamErrStatReg(pEccAggrRegs, ramId, CSL_ECC_AGGR_SELECT_ERR_STAT1, regVal);
        }
    }

    if (cslRet == CSL_PASS)
    {
         retVal = (bool)true;
    }
    else
    {
         retVal = (bool)false;
    }
    return retVal;
}

static bool CSL_ecc_aggrToggleIntrEnable(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc, bool bEnable)
{
    bool retVal = (bool)true;

    if( (CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId) == (bool) true ) && 
        (CSL_ecc_aggrIsValidIntrSrc(intrSrc)           == (bool) true ) )
    {
        if(bEnable == (bool)true )
        {
            CSL_REG32_WR( CSL_ecc_aggrEnableSetRegAddr( (uintptr_t)pEccAggrRegs,(ramId >> 5U), intrSrc ), ((uint32_t)1U << (ramId & 0x1FU)) );
        }
        else
        {
            CSL_REG32_WR( CSL_ecc_aggrEnableClrRegAddr( (uintptr_t)pEccAggrRegs,(ramId >> 5U), intrSrc ), ((uint32_t)1U << (ramId & 0x1FU)) );
        }
    }
    else
    {
        retVal = (bool)false;
    }
    return retVal;
}

static bool CSL_ecc_aggrToggleIntrsEnable(const CSL_ecc_aggrRegs *pEccAggrRegs, CSL_Ecc_AggrIntrSrc intrSrc, bool bEnable)
{
    bool retVal = (bool)true;
    int32_t      cslRet = CSL_EBADARGS;

    if( CSL_ecc_aggrIsValidIntrSrc(intrSrc) == (bool)true )
    {
        uint32_t ramId;
        uint32_t numRams;

        cslRet = CSL_ecc_aggrGetNumRams(pEccAggrRegs, &numRams);
        if (cslRet == CSL_PASS)
        {
            for( ramId=((uint32_t)(0u)); ramId<numRams; ramId++ )
            {
                if( bEnable == (bool)true)
                {
                    cslRet = CSL_ecc_aggrEnableIntr( pEccAggrRegs, ramId, intrSrc );
                }
                else
                {
                    cslRet = CSL_ecc_aggrDisableIntr( pEccAggrRegs, ramId, intrSrc );
                }
            }
        }
    }

    if (cslRet == CSL_PASS)
    {
        retVal = (bool) true;
    }
    else
    {
        retVal = (bool) false;
    }
    return retVal;
}

/*===========================================================================*/
/*  External CSL-FL Functions                                                */
/*===========================================================================*/

/**
 * Requirement: REQ_TAG(PRSDK-2217)
 * Design: did_csl_ecc_aggr_read
 */
int32_t CSL_ecc_aggrGetRevision(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t *pRev)
{
    int32_t    retVal = CSL_EBADARGS;

    if ( pEccAggrRegs != NULL )
    {
        if (pRev  != NULL)
        {
            *pRev = CSL_REG32_RD(&pEccAggrRegs->REV);
            retVal = CSL_PASS;
        }
    }

    /* Return the API success/fail with value in the address provided by caller */
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2217)
 * Design: did_csl_ecc_aggr_read
 */
int32_t CSL_ecc_aggrGetNumRams(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t *pNumRams)
{
    int32_t    retVal = CSL_EBADARGS;

    if ( pEccAggrRegs != NULL )
    {
        if (pNumRams  != NULL)
        {
            *pNumRams = (uint32_t)CSL_REG32_FEXT(&pEccAggrRegs->STAT, ECC_AGGR_STAT_NUM_RAMS);
             retVal   = CSL_PASS;
        }
    }
    /* Return the API success/fail with value in the address provided by caller */
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2217)
 * Design: did_csl_ecc_aggr_read
 */
int32_t CSL_ecc_aggrReadEccRamReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t regOffset, uint32_t *pRegVal )
{
    int32_t    retVal = CSL_EBADARGS;

    if( (pEccAggrRegs                                   != NULL) &&
        (CSL_ecc_aggrIsValidEccRamRegOffset(regOffset)  == (bool) true )              &&
        (CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId)  == (bool) true) )
    {
        if (pRegVal  != NULL)
        {
            CSL_REG32_WR( &pEccAggrRegs->VECTOR,
                    CSL_FMK(ECC_AGGR_VECTOR_ECC_VECTOR, ramId)              |
                    CSL_FMK(ECC_AGGR_VECTOR_RD_SVBUS_ADDRESS, regOffset)    |
                    CSL_FMK(ECC_AGGR_VECTOR_RD_SVBUS, (uint32_t)1U) );
            while( !CSL_ecc_aggrIsEccRamReadDone(pEccAggrRegs) ) { }
            *pRegVal = CSL_REG32_RD(((uintptr_t)pEccAggrRegs)+regOffset);
            retVal = CSL_PASS;
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2217)
 * Design: did_csl_ecc_aggr_read
 */
int32_t CSL_ecc_aggrReadEccRamWrapRevReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t *pRegVal)
{
    return CSL_ecc_aggrReadEccRamReg(pEccAggrRegs, ramId, CSL_ECC_RAM_WRAP_REV, pRegVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2217)
 * Design: did_csl_ecc_aggr_read
 */
int32_t CSL_ecc_aggrReadEccRamCtrlReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t *pRegVal)
{
    return CSL_ecc_aggrReadEccRamReg(pEccAggrRegs, ramId, CSL_ECC_RAM_CTRL, pRegVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2217)
 * Design: (did_csl_ecc_aggr_read)
 */
int32_t CSL_ecc_aggrReadEccRamErrCtrlReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t instSelect, uint32_t *pRegVal)
{
    int32_t    retVal = CSL_EBADARGS;

    if( CSL_ecc_aggrIsValidInstSel(instSelect, CSL_ECC_AGGR_MAX_NUM_RAM_ERR_CTRL)== (bool)true )
    {
        retVal = CSL_ecc_aggrReadEccRamReg(pEccAggrRegs, ramId, CSL_ECC_RAM_ERR_CTRL1+((instSelect)*4U), pRegVal);
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2217)
 * Design: did_csl_ecc_aggr_read
 */
int32_t CSL_ecc_aggrReadEccRamErrStatReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t instSelect, uint32_t *pRegVal)
{
    int32_t    retVal = CSL_EBADARGS;

    if( CSL_ecc_aggrIsValidInstSel(instSelect, CSL_ECC_AGGR_MAX_NUM_RAM_ERR_STAT)==(bool)true )
    {
        retVal = CSL_ecc_aggrReadEccRamReg(pEccAggrRegs, ramId, CSL_ECC_RAM_ERR_STAT1+((instSelect)*4U), pRegVal);
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2219)
 * Design: did_csl_ecc_aggr_write
 */
int32_t CSL_ecc_aggrWriteEccRamReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t regOffset, uint32_t val )
{
    int32_t    retVal = CSL_EBADARGS;

    if( (pEccAggrRegs                                   != NULL) &&
        (CSL_ecc_aggrIsValidEccRamRegOffset(regOffset)  == (bool) true )              &&
        (CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId)  == (bool) true) )
    {
        CSL_REG32_WR(&pEccAggrRegs->VECTOR, CSL_FMK(ECC_AGGR_VECTOR_ECC_VECTOR, ramId));
        CSL_REG32_WR(((uintptr_t)pEccAggrRegs)+regOffset, val);
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2219)
 * Design: did_csl_ecc_aggr_write
 */
int32_t CSL_ecc_aggrWriteEccRamCtrlReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t val)
{
    return CSL_ecc_aggrWriteEccRamReg(pEccAggrRegs, ramId, CSL_ECC_RAM_CTRL, val);
}

/**
 * Requirement: REQ_TAG(PRSDK-2219)
 * Design: did_csl_ecc_aggr_write
 */
int32_t CSL_ecc_aggrWriteEccRamErrCtrlReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t instSelect, uint32_t val)
{
    int32_t    retVal = CSL_EBADARGS;

    if( CSL_ecc_aggrIsValidInstSel(instSelect, CSL_ECC_AGGR_MAX_NUM_RAM_ERR_CTRL) ==(bool)true )
    {
        retVal = CSL_ecc_aggrWriteEccRamReg(pEccAggrRegs, ramId, CSL_ECC_RAM_ERR_CTRL1+((instSelect)*4U), val);
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2219)
 * Design: did_csl_ecc_aggr_write
 */
int32_t CSL_ecc_aggrWriteEccRamErrStatReg(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t instSelect, uint32_t val)
{
    int32_t    retVal = CSL_EBADARGS;

    if( CSL_ecc_aggrIsValidInstSel(instSelect, CSL_ECC_AGGR_MAX_NUM_RAM_ERR_STAT) == (bool)true )
    {
        retVal = CSL_ecc_aggrWriteEccRamReg(pEccAggrRegs, ramId, CSL_ECC_RAM_ERR_STAT1+((instSelect)*4U), val);
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2219) REQ_TAG(PRSDK-1704)
 * Design: did_csl_ecc_aggr_config
 */
int32_t CSL_ecc_aggrConfigEccRam(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, bool bEnable, bool bEccCheck, bool bEnableRMW)
{
    int32_t    retVal = CSL_EBADARGS;

    if ( (pEccAggrRegs                                  != NULL)  &&
         (CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId) == (bool)true) )
    {
        uint32_t val;

        retVal = CSL_ecc_aggrReadEccRamCtrlReg(pEccAggrRegs, ramId, &val);
        if (retVal == CSL_PASS)
        {
            CSL_FINS(val, ECC_RAM_CTRL_ENABLE_RMW, (bEnableRMW ? (uint32_t)1U : (uint32_t)0) );
            CSL_FINS(val, ECC_RAM_CTRL_ECC_CHECK, (bEccCheck ? (uint32_t)1U : (uint32_t)0) );
            CSL_FINS(val, ECC_RAM_CTRL_ECC_ENABLE,(bEnable ? (uint32_t)1U : (uint32_t)0) );
            retVal = CSL_ecc_aggrWriteEccRamCtrlReg(pEccAggrRegs, ramId, val);
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2219) REQ_TAG(PRSDK-1704)
 * Design: did_csl_ecc_aggr_config
 */
int32_t CSL_ecc_aggrVerifyConfigEccRam(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, bool bEnable, bool bEccCheck, bool bEnableRMW)
{
    int32_t    retVal = CSL_EBADARGS;

    if ( (pEccAggrRegs != NULL)       &&
         (CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId) == (bool)true) )
    {
        uint32_t val, valExp = 0U;
        uint32_t mask = (CSL_ECC_RAM_CTRL_ECC_ENABLE_MASK |
                         CSL_ECC_RAM_CTRL_ECC_CHECK_MASK  |
                         CSL_ECC_RAM_CTRL_ENABLE_RMW_MASK);

        retVal = CSL_ecc_aggrReadEccRamCtrlReg(pEccAggrRegs, ramId, &val);
        if (retVal == CSL_PASS)
        {
            CSL_FINS(valExp, ECC_RAM_CTRL_ENABLE_RMW, (bEnableRMW ? (uint32_t)1U : (uint32_t)0) );
            CSL_FINS(valExp, ECC_RAM_CTRL_ECC_CHECK, (bEccCheck ? (uint32_t)1U : (uint32_t)0) );
            CSL_FINS(valExp, ECC_RAM_CTRL_ECC_ENABLE,(bEnable ? (uint32_t)1U : (uint32_t)0) );
            /* Get the bit fields for the expected values */
            valExp &= mask;
            val    &= mask;
            if (val == valExp)
            {
                retVal = CSL_PASS;
            }
            else
            {
                retVal = CSL_EFAIL;
            }
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2217)
 * Design: did_csl_ecc_aggr_read
 */
int32_t CSL_ecc_aggrGetEccRamGetErrorStatus(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrErrorInfo *pEccErrorStatus)
{
    int32_t    retVal = CSL_EBADARGS;

    if ( (pEccAggrRegs != NULL)       &&
         (pEccErrorStatus != NULL)       &&
         ( CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId) == (bool)true ) )
    {
        uint32_t  errorStatus1, errorStatus2;

        retVal = CSL_ecc_aggrReadEccRamErrStatReg(pEccAggrRegs, ramId, CSL_ECC_AGGR_SELECT_ERR_STAT1, &errorStatus1);
        if (retVal == CSL_PASS)
        {
            retVal = CSL_ecc_aggrReadEccRamErrStatReg(pEccAggrRegs, ramId, CSL_ECC_AGGR_SELECT_ERR_STAT2, &errorStatus2);
            if (retVal == CSL_PASS)
            {
                if(CSL_FEXT(errorStatus1,ECC_RAM_ERR_STAT1_ECC_SEC)==1U)
                {
                    pEccErrorStatus->intrSrc = CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT;
                }
                else if(CSL_FEXT(errorStatus1,ECC_RAM_ERR_STAT1_ECC_DED)==1U)
                {
                    pEccErrorStatus->intrSrc = CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT;
                }
                else if(CSL_FEXT(errorStatus1,ECC_RAM_ERR_STAT1_CLR_ECC_OTHER)==1U)
                {
                    pEccErrorStatus->intrSrc = CSL_ECC_ADDR_ERROR_TYPE_SUCCESSIVE_SINGLE_BITS;
                }
                else
                {
                    pEccErrorStatus->intrSrc = CSL_ECC_AGGR_INTR_SRC_NONE;
                }
                pEccErrorStatus->eccRow    = (pEccErrorStatus->intrSrc == CSL_ECC_AGGR_INTR_SRC_NONE) ? 0U : CSL_FEXT(errorStatus2,ECC_RAM_ERR_STAT2_ECC_ROW);
                pEccErrorStatus->eccBit1   = (pEccErrorStatus->intrSrc == CSL_ECC_AGGR_INTR_SRC_NONE) ? 0U : CSL_FEXT(errorStatus1,ECC_RAM_ERR_STAT1_ECC_BIT1);
            }
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2219)
 * Design: did_csl_ecc_aggr_write
 */
int32_t CSL_ecc_aggrForceEccRamError(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, const CSL_Ecc_AggrErrorInfo *pEccForceError)
{
    int32_t    retVal = CSL_EBADARGS;

    if ( (pEccAggrRegs != NULL)       &&
         (pEccForceError != NULL)       &&
         ( CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId) == (bool)true ) )
    {
        uint32_t regVal;

        retVal = CSL_ecc_aggrWriteEccRamErrCtrlReg(pEccAggrRegs, ramId, CSL_ECC_AGGR_SELECT_ERR_CTRL2,
            CSL_FMK(ECC_RAM_ERR_CTRL2_ECC_BIT1, pEccForceError->eccBit1)     |
            CSL_FMK(ECC_RAM_ERR_CTRL2_ECC_BIT2, pEccForceError->eccBit2) );
        if (retVal == CSL_PASS)
        {
            retVal = CSL_ecc_aggrWriteEccRamErrCtrlReg(pEccAggrRegs, ramId, CSL_ECC_AGGR_SELECT_ERR_CTRL1,
                CSL_FMK(ECC_RAM_ERR_CTRL1_ECC_ROW, pEccForceError->eccRow) );
            if (retVal == CSL_PASS)
            {
                retVal = CSL_ecc_aggrReadEccRamCtrlReg(pEccAggrRegs,ramId, &regVal);
                if (retVal == CSL_PASS)
                {
                    if(pEccForceError->intrSrc == CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT)
                    {
                        CSL_FINS(regVal, ECC_RAM_CTRL_FORCE_SEC, (uint32_t)1U);
                        CSL_FINS(regVal, ECC_RAM_CTRL_FORCE_DED, (uint32_t)0);
                    }
                    else if(pEccForceError->intrSrc == CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT)
                    {
                        CSL_FINS(regVal, ECC_RAM_CTRL_FORCE_SEC, (uint32_t)0);
                        CSL_FINS(regVal, ECC_RAM_CTRL_FORCE_DED, (uint32_t)1U);
                    }
                    else
                    {
                        CSL_FINS(regVal, ECC_RAM_CTRL_FORCE_SEC, (uint32_t)0);
                        CSL_FINS(regVal, ECC_RAM_CTRL_FORCE_DED, (uint32_t)0);
                    }
                    CSL_FINS(regVal, ECC_RAM_CTRL_FORCE_N_ROW, ((pEccForceError->bNextRow) ? (uint32_t)1U : (uint32_t)0) );
                    CSL_FINS(regVal, ECC_RAM_CTRL_ERROR_ONCE,  ((pEccForceError->bOneShotMode) ? (uint32_t)1U : (uint32_t)0) );
                    retVal = CSL_ecc_aggrWriteEccRamCtrlReg(pEccAggrRegs, ramId, regVal);
                }
            }
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrAckIntr(CSL_ecc_aggrRegs *pEccAggrRegs, CSL_Ecc_AggrIntrSrc intrSrc)
{
    int32_t    retVal = CSL_PASS;

    if ( pEccAggrRegs == NULL)
    {
         retVal = CSL_EBADARGS;
    }
    else
    {
        if( intrSrc == CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT )
        {
            CSL_REG32_WR( &pEccAggrRegs->SEC_EOI_REG, CSL_FMK(ECC_AGGR_SEC_EOI_REG_EOI_WR,(uint32_t)1U) );
        }
        else if( intrSrc == CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT )
        {
            CSL_REG32_WR( &pEccAggrRegs->DED_EOI_REG, CSL_FMK(ECC_AGGR_DED_EOI_REG_EOI_WR,(uint32_t)1U) );
        }
        else
        {
            retVal = CSL_EBADARGS;
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrIsEccRamIntrPending(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc, bool *pIsPend)
{
    bool        pend  = (bool)false;
    int32_t     retVal = CSL_EBADARGS;

    if ( (pEccAggrRegs != NULL)       &&
         ( CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId) == (bool)true ) )
    {
        uint32_t regVal;
        /* No need to check the return value from CSL as arguments are already checked above */
        retVal = CSL_ecc_aggrReadEccRamErrStatReg(pEccAggrRegs, ramId, CSL_ECC_AGGR_SELECT_ERR_STAT1, &regVal);
        if (retVal == CSL_PASS)
        {
            if( ((intrSrc == CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT) && (CSL_FEXT(regVal,ECC_RAM_ERR_STAT1_ECC_SEC) == 1U) )    ||
                ((intrSrc == CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT) && (CSL_FEXT(regVal,ECC_RAM_ERR_STAT1_ECC_DED) == 1U) )    ||
                ((intrSrc == CSL_ECC_ADDR_ERROR_TYPE_SUCCESSIVE_SINGLE_BITS) && (CSL_FEXT(regVal,ECC_RAM_ERR_STAT1_ECC_OTHER) == 1U) ) )
            {
                pend = (bool)true;
            }
        }
    }
    if (pIsPend != NULL)
    {
        *pIsPend = pend;
    }
    else
    {
        retVal = CSL_EBADARGS;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrSetEccRamIntrPending(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc)
{
    bool       ret = (bool) false;
    int32_t    retVal = CSL_EBADARGS;
    void       *pChkPtr = (void *) pEccAggrRegs;

    /* RAM ID and Interrupt Source is validated internally in below function */
    if ( (pChkPtr != NULL) )
    {
        ret = CSL_ecc_aggrToggleEccRamIntrPending(pEccAggrRegs, ramId, intrSrc, (bool)true);
    }

    if (ret == (bool) true)
    {
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrClrEccRamIntrPending(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc)
{
    bool       ret = (bool) false;
    int32_t    retVal = CSL_EBADARGS;

    /* RAM ID and Interrupt Source is validated internally in below function */
    if ( (pEccAggrRegs != NULL) )
    {
        ret = CSL_ecc_aggrToggleEccRamIntrPending(pEccAggrRegs, ramId, intrSrc, (bool)false);
    }

    if (ret == (bool) true)
    {
        retVal = CSL_PASS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrIsIntrPending(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc, bool *pIsPend)
{
    bool       pend = (bool) false;
    int32_t    retVal = CSL_EBADARGS;

    if ( (pEccAggrRegs != NULL) )
    {
        if( CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId) && CSL_ecc_aggrIsValidIntrSrc(intrSrc) )
        {
            uint32_t    regVal;
            uintptr_t   regAddr;

            retVal  = CSL_PASS;
            regAddr = CSL_ecc_aggrStatusRegAddr( (uintptr_t)pEccAggrRegs, (ramId >> 5U), intrSrc );
            regVal = CSL_REG32_RD( regAddr );
            regVal >>= (ramId & 0x1FU);                    // Shift bit corresponding to the ramId into bit 0
            if( (regVal & 1U) != 0U )
            {
                pend = (bool)true;
            }
        }
    }

    if (pIsPend != NULL)
    {
        *pIsPend = pend;
    }
    else
    {
        retVal = CSL_EBADARGS;
    }

    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrIsAnyIntrPending(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, bool *pIsPend)
{
    bool       pend = (bool) false;
    bool       sBitPend, dBitPend;
    int32_t    retVal;

    /* Argument verification is done at below APIs, hence do not need to check here */
    retVal = CSL_ecc_aggrIsIntrPending(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT, &sBitPend);
    if (retVal == CSL_PASS)
    {
        retVal = CSL_ecc_aggrIsIntrPending(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT, &dBitPend);
    }
    if (retVal == CSL_PASS)
    {
        if ( sBitPend || dBitPend ) 
        {
           pend = (bool)true;
        }
    }

    if (pIsPend != NULL)
    {
        *pIsPend = pend;
    }
    else
    {
        retVal = CSL_EBADARGS;
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrEnableIntr(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc)
{
    int32_t retVal = CSL_EBADARGS;
    bool    operation = (bool) false;

    if ( (pEccAggrRegs != NULL) )
    {
        /* other arguments are verified in below function */
        operation = CSL_ecc_aggrToggleIntrEnable(pEccAggrRegs, ramId, intrSrc, (bool)true);
    }

    if (operation == (bool) true)
    {
        retVal = CSL_PASS;
    }
    else
    {
        retVal = CSL_EBADARGS;
    }

    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrDisableIntr(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, CSL_Ecc_AggrIntrSrc intrSrc)
{
    int32_t retVal = CSL_EBADARGS;
    bool    operation = (bool) false;

    if ( (pEccAggrRegs != NULL) )
    {
        operation = CSL_ecc_aggrToggleIntrEnable(pEccAggrRegs, ramId, intrSrc, (bool)false);
    }

    if (operation == (bool) true)
    {
        retVal = CSL_PASS;
    }
    else
    {
        retVal = CSL_EBADARGS;
    }

    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrEnableAllIntr(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId)
{
    int32_t retVal = CSL_EBADARGS;

    if ( (pEccAggrRegs != NULL) )
    {
        if( CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId) == (bool)true )
        {
            /* Other Argument verification is done in below APIs */
            retVal = CSL_ecc_aggrEnableIntr(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
            if (retVal == CSL_PASS)
            {
                retVal = CSL_ecc_aggrEnableIntr(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
            }
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrDisableAllIntr(const CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId)
{
    int32_t retVal = CSL_EBADARGS;

    if ( (pEccAggrRegs != NULL) )
    {
        if( CSL_ecc_aggrIsValidRamId(pEccAggrRegs, ramId) == (bool)true )
        {
            /* Other Argument verification is done in below APIs */
            retVal = CSL_ecc_aggrDisableIntr(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
            if (retVal == CSL_PASS)
            {
                retVal = CSL_ecc_aggrDisableIntr(pEccAggrRegs, ramId, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
            }
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrEnableIntrs(const CSL_ecc_aggrRegs *pEccAggrRegs, CSL_Ecc_AggrIntrSrc intrSrc)
{
    int32_t retVal = CSL_EBADARGS;
    bool    operation = (bool) false;

    /* Other argument checks are done internal to below API */
    if ( (pEccAggrRegs != NULL) )
    {
        operation = CSL_ecc_aggrToggleIntrsEnable(pEccAggrRegs, intrSrc, (bool)true);
    }

    if (operation == (bool) true)
    {
        retVal = CSL_PASS;
    }
    else
    {
        retVal = CSL_EBADARGS;
    }

    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrDisableIntrs(const CSL_ecc_aggrRegs *pEccAggrRegs, CSL_Ecc_AggrIntrSrc intrSrc)
{
    int32_t retVal = CSL_EBADARGS;
    bool    operation = (bool) false;

    /* Other argument checks are done internal to below API */
    if ( (pEccAggrRegs != NULL) )
    {
        operation = CSL_ecc_aggrToggleIntrsEnable(pEccAggrRegs, intrSrc, (bool)false);
    }

    if (operation == (bool) true)
    {
        retVal = CSL_PASS;
    }
    else
    {
        retVal = CSL_EBADARGS;
    }

    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrEnableAllIntrs(const CSL_ecc_aggrRegs *pEccAggrRegs)
{
    int32_t retVal = CSL_EBADARGS;

    /* Other argument checks are done internal to below API */
    if ( (pEccAggrRegs != NULL) )
    {
        retVal = CSL_ecc_aggrEnableIntrs(pEccAggrRegs, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
        if (retVal == CSL_PASS)
        {
            retVal = CSL_ecc_aggrEnableIntrs(pEccAggrRegs, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
        }
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrDisableAllIntrs(const CSL_ecc_aggrRegs *pEccAggrRegs)
{
    int32_t retVal = CSL_EBADARGS;

    /* Other argument checks are done internal to below API */
    if ( (pEccAggrRegs != NULL) )
    {
        retVal = CSL_ecc_aggrDisableIntrs(pEccAggrRegs, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
        if (retVal == CSL_PASS)
        {
            retVal = CSL_ecc_aggrDisableIntrs(pEccAggrRegs, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
        }
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-2220)
 * Design: did_csl_ecc_aggr_intr
 */
int32_t CSL_ecc_aggrReadStaticRegs(CSL_ecc_aggrRegs *pEccAggrRegs, CSL_ecc_aggrStaticRegs *pEccAggrStaticRegs)
{
    int32_t  retVal = CSL_EBADARGS;
    uint32_t regOffset, *pRegPtr;
    uint32_t i;

    /* Read below static registers */
    retVal = CSL_ecc_aggrGetRevision((const CSL_ecc_aggrRegs *) pEccAggrRegs, &pEccAggrStaticRegs->REV);

    /* ECC Control register */
    if (retVal == CSL_PASS)
    {
        regOffset = CSL_ECC_RAM_CTRL;
        retVal = CSL_ecc_aggrReadEccRamReg(pEccAggrRegs, 0, regOffset, &pEccAggrStaticRegs->ECC_CTRL);
    }

    /* ECC Err Control1 register */
    if (retVal == CSL_PASS)
    {
        regOffset = CSL_ECC_RAM_ERR_CTRL1;
        retVal = CSL_ecc_aggrReadEccRamReg(pEccAggrRegs, 0, regOffset, &pEccAggrStaticRegs->ECC_ERR_CTRL1);
    }

    /* ECC Err Control2 register */
    if (retVal == CSL_PASS)
    {
        regOffset = CSL_ECC_RAM_ERR_CTRL2;
        retVal = CSL_ecc_aggrReadEccRamReg(pEccAggrRegs, 0, regOffset, &pEccAggrStaticRegs->ECC_ERR_CTRL2);
    }

    /* Other argument checks are done internal to below API */
    if ( (pEccAggrRegs != NULL) &&
         (pEccAggrStaticRegs != NULL) )
    {
        if (retVal == CSL_PASS)
        {
            for ( i = ((uint32_t) (0u)); i < (CSL_ECC_AGGR_NUM_ENABLE_REGISTERS); i++)
            {
                /* ECC_SEC_ENABLE_SET_REG registers */
                pRegPtr = (uint32_t *) CSL_ecc_aggrSecEnableSetRegAddr ((uintptr_t) pEccAggrRegs, i);
                pEccAggrStaticRegs->ECC_SEC_ENABLE_SET_REG[i] = CSL_REG_RD(pRegPtr);

                /* ECC_SEC_ENABLE_CLR_REG registers */
                pRegPtr = (uint32_t *) CSL_ecc_aggrSecEnableClrRegAddr ((uintptr_t) pEccAggrRegs, i);
                pEccAggrStaticRegs->ECC_SEC_ENABLE_CLR_REG[i] = CSL_REG_RD(pRegPtr);

                /* ECC_DED_ENABLE_SET_REG registers */
                pRegPtr = (uint32_t *) CSL_ecc_aggrDedEnableSetRegAddr ((uintptr_t) pEccAggrRegs, i);
                pEccAggrStaticRegs->ECC_DED_ENABLE_SET_REG[i] = CSL_REG_RD(pRegPtr);

                /* ECC_DED_ENABLE_CLR_REG registers */
                pRegPtr = (uint32_t *) CSL_ecc_aggrDedEnableClrRegAddr ((uintptr_t) pEccAggrRegs, i);
                pEccAggrStaticRegs->ECC_DED_ENABLE_CLR_REG[i] = CSL_REG_RD(pRegPtr);
            }
        }
    }

    return (retVal);
}
