/**
 * @file  csl_pat.c
 *
 * @brief
 *  Implementation file for the PAT module CSL.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2016-2019, Texas Instruments, Inc.
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
 *    Neither the name of Texas Instruments Incorpopated nor the names of
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

#include <ti/csl/cslr_pat.h>
#include <ti/csl/csl_pat.h>

static void CSL_patGetBlockAndPageIndex(uint32_t pageTableIdx, uint32_t *pBlockIndex, uint32_t *pPageIndex);
static uint32_t CSL_patGetPageTableIndex(const CSL_PatConfigParms *pPatCfg, uint64_t inputAddress);
static void CSL_patSetExceptionLoggingIntEnable(const CSL_PatConfigParms *pPatCfg, uint32_t bEnable);
static void CSL_patSetIntEnable(const CSL_PatConfigParms *pPatCfg, uint32_t errorType, uint32_t bEnable);

/*=============================================================================
 *  Internal functions
 *===========================================================================*/
#define CSL_PAT_NUM_PAGES_PER_BLOCK     (256U)

static void CSL_patGetBlockAndPageIndex(uint32_t pageTableIdx, uint32_t *pBlockIndex, uint32_t *pPageIndex)
{
    *pBlockIndex = pageTableIdx / CSL_PAT_NUM_PAGES_PER_BLOCK;
    *pPageIndex  = pageTableIdx & (CSL_PAT_NUM_PAGES_PER_BLOCK - 1U);
}

static uint32_t CSL_patGetPageTableIndex(const CSL_PatConfigParms *pPatCfg, uint64_t inputAddress)
{
    static const uint32_t   addrShift[] = { 12, 14, 16, 20 };   /* Address shift for 4KB, 16KB, 64KB, and 1MB page sizes */
    uint32_t                pageSize;
    uint32_t                pageTableIndex = (uint32_t)-1;      /* (uint32_t)-1 is error return value */

    pageSize = CSL_patGetPageSize(pPatCfg);
    if( pageSize < (sizeof(addrShift)/sizeof(uint32_t)) )
    {
        pageTableIndex = (uint32_t)(inputAddress >> addrShift[pageSize]);
    }
    return pageTableIndex;
}

static void CSL_patSetExceptionLoggingIntEnable(const CSL_PatConfigParms *pPatCfg, uint32_t bEnable)
{
    CSL_REG32_FINS( &pPatCfg->pPatRegs->EXCEPTION_LOGGING_CONTROL, PAT_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR, ((bEnable==0U) ? 1U : 0U ) );
}

static void CSL_patSetIntEnable(const CSL_PatConfigParms *pPatCfg, uint32_t errorType, uint32_t bEnable)
{
    if( errorType == (uint32_t)CSL_PAT_INTR_SRC_EXCEPTION )
    {
        if( bEnable==0U )
        {
             CSL_REG32_WR( &pPatCfg->pPatRegs->EXCEPTION_ENABLE_CLEAR, CSL_FMK( PAT_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR, 1U ) );
        }
        else
        {
            CSL_REG32_WR( &pPatCfg->pPatRegs->EXCEPTION_ENABLE_SET, CSL_FMK( PAT_EXCEPTION_ENABLE_SET_ENABLE_SET, 1U ) );
        }
    }
}

/*=============================================================================
 *  CSL-F functions
 *===========================================================================*/
uint32_t CSL_patGetRevision(const CSL_PatConfigParms *pPatCfg)
{
    return CSL_REG32_RD(&pPatCfg->pPatRegs->PID);
}

uint32_t CSL_patGetMaxPages(const CSL_PatConfigParms *pPatCfg)
{
    uint32_t regVal, maxPages=64U;

    regVal = CSL_patGetRevision(pPatCfg);
    if( CSL_FEXT(regVal, PAT_PID_RTL) > 1U )
    {
        maxPages = CSL_REG32_FEXT(&pPatCfg->pPatRegs->CONFIG, PAT_CONFIG_PAGES);
    }

    return maxPages;
}

uint32_t CSL_patGetArbitrationMode(const CSL_PatConfigParms *pPatCfg)
{
    return (uint32_t)CSL_REG32_FEXT(&pPatCfg->pPatRegs->CONTROL, PAT_CONTROL_ARB_MODE);
}

int32_t CSL_patSetArbitrationMode(const CSL_PatConfigParms *pPatCfg, uint32_t arbitrationMode)
{
    int32_t retVal = -1;

    if( (arbitrationMode == (uint32_t)CSL_PAT_ARBITRATION_MODE_UPDATES_FIRST) || (arbitrationMode == (uint32_t)CSL_PAT_ARBITRATION_MODE_ROUND_ROBIN) )
    {
        CSL_REG32_FINS(&pPatCfg->pPatRegs->CONTROL, PAT_CONTROL_ARB_MODE, arbitrationMode);
        retVal = 0;
    }
    return retVal;
}

uint32_t CSL_patGetPageSize(const CSL_PatConfigParms *pPatCfg)
{
    return (uint32_t)CSL_REG32_FEXT(&pPatCfg->pPatRegs->CONTROL, PAT_CONTROL_PAGE_SIZE);
}

int32_t CSL_patSetPageSize(const CSL_PatConfigParms *pPatCfg, uint32_t pageSize)
{
    int32_t retVal = -1;

    if( pageSize <= CSL_PAT_PAGE_SIZE_1MB )
    {
        CSL_REG32_FINS(&pPatCfg->pPatRegs->CONTROL, PAT_CONTROL_PAGE_SIZE, pageSize);
        retVal = 0;
    }
    return retVal;
}

void CSL_patSetReplaceOrderIdEnable(const CSL_PatConfigParms *pPatCfg, uint32_t bEnable)
{
    CSL_REG32_FINS( &pPatCfg->pPatRegs->CONTROL, PAT_CONTROL_REPLACE_ORDERID_ENABLE, bEnable );
}

void CSL_patSetPatEnable(const CSL_PatConfigParms *pPatCfg, uint32_t bEnable)
{
    CSL_REG32_FINS( &pPatCfg->pPatRegs->CONTROL, PAT_CONTROL_ENABLE, bEnable );
}

void CSL_patEnablePat(const CSL_PatConfigParms *pPatCfg)
{
    CSL_patSetPatEnable(pPatCfg, true);
}

void CSL_patDisablePat(const CSL_PatConfigParms *pPatCfg)
{
    CSL_patSetPatEnable(pPatCfg, false);
}

void CSL_patSetExceptionLoggingEnable(const CSL_PatConfigParms *pPatCfg, uint32_t bEnable)
{
    CSL_patSetExceptionLoggingIntEnable(pPatCfg, bEnable);
    CSL_REG32_FINS( &pPatCfg->pPatRegs->EXCEPTION_LOGGING_CONTROL, PAT_EXCEPTION_LOGGING_CONTROL_DISABLE_F, ((bEnable==0U) ? 1U : 0U) );
}

void CSL_patEnableExceptionLogging(const CSL_PatConfigParms *pPatCfg)
{
    CSL_patSetExceptionLoggingEnable(pPatCfg, true);
}

void CSL_patDisableExceptionLogging(const CSL_PatConfigParms *pPatCfg)
{
    CSL_patSetExceptionLoggingEnable(pPatCfg, false);
}

uint32_t CSL_patIsIntrPending(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc)
{
    uint32_t retVal = false;

    if( (intrSrc == (uint32_t)CSL_PAT_INTR_SRC_EXCEPTION)     &&
        (CSL_REG32_FEXT(&pPatCfg->pPatRegs->EXCEPTION_PEND_SET, PAT_EXCEPTION_PEND_SET_PEND_SET) == 1U) )
    {
       retVal = true;
    }
    return retVal;
}

int32_t CSL_patSetIntrPending(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc)
{
    int32_t retVal = -1;

    if( intrSrc == CSL_PAT_INTR_SRC_EXCEPTION )
    {
        CSL_REG32_WR( &pPatCfg->pPatRegs->EXCEPTION_PEND_SET, CSL_FMK( PAT_EXCEPTION_PEND_SET_PEND_SET, 1U ) );
        retVal = 0;
    }
    return retVal;
}

int32_t CSL_patClrIntrPending(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc)
{
    int32_t retVal = -1;

    if( intrSrc == CSL_PAT_INTR_SRC_EXCEPTION )
    {
        CSL_REG32_WR( &pPatCfg->pPatRegs->EXCEPTION_PEND_CLEAR, CSL_FMK( PAT_EXCEPTION_PEND_CLEAR_PEND_CLR, 1U ) );
        retVal = 0;
    }
    return retVal;
}

int32_t CSL_patAckIntr(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc)
{
    int32_t retVal = -1;

    if( intrSrc == CSL_PAT_INTR_SRC_EXCEPTION )
    {
        CSL_REG32_WR( &pPatCfg->pPatRegs->EOI_REG, 0U );
        retVal = 0;
    }
    return retVal;
}

int32_t CSL_patSetIntrEnable(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc, uint32_t bEnable)
{
    int32_t retVal = -1;

    if( intrSrc == (uint32_t)CSL_PAT_INTR_SRC_EXCEPTION )
    {
        if( bEnable != 0U )
        {
            /* If enabling CSL_PAT_INTR_SRC_EXCEPTION, also enable exception logging */
            CSL_patEnableExceptionLogging(pPatCfg);
        }
        CSL_patSetIntEnable(pPatCfg, intrSrc, bEnable);
        retVal = 0;
    }
    return retVal;
}

int32_t CSL_patEnableIntr(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc)
{
    return CSL_patSetIntrEnable(pPatCfg, intrSrc, true);
}

int32_t CSL_patDisableIntr(const CSL_PatConfigParms *pPatCfg, uint32_t intrSrc)
{
    return CSL_patSetIntrEnable(pPatCfg, intrSrc, false);
}

void CSL_patSetErrMsgDestId(const CSL_PatConfigParms *pPatCfg, uint32_t destId)
{
    CSL_REG32_WR(&pPatCfg->pPatRegs->DESTINATION_ID, CSL_FMK(PAT_DESTINATION_ID_DEST_ID, destId));
}

int32_t CSL_patGetExceptionInfo(const CSL_PatConfigParms *pPatCfg, CSL_PatExceptionInfo *pExceptionInfo)
{
    uint32_t val, val2;
    uint32_t addrH,addrL;
    int32_t retVal;

    val = CSL_REG32_RD(&pPatCfg->pPatRegs->EXCEPTION_LOGGING_HEADER0);
    pExceptionInfo->type        = CSL_FEXT(val, PAT_EXCEPTION_LOGGING_HEADER0_TYPE_F);
    pExceptionInfo->destId      = CSL_FEXT(val, PAT_EXCEPTION_LOGGING_HEADER0_DEST_ID);
    pExceptionInfo->srcId       = CSL_FEXT(val, PAT_EXCEPTION_LOGGING_HEADER0_SRC_ID);

    val = CSL_REG32_RD(&pPatCfg->pPatRegs->EXCEPTION_LOGGING_HEADER1);
    pExceptionInfo->code        = CSL_FEXT(val, PAT_EXCEPTION_LOGGING_HEADER1_CODE);
    pExceptionInfo->group       = CSL_FEXT(val, PAT_EXCEPTION_LOGGING_HEADER1_GROUP);

    val = CSL_REG32_RD(&pPatCfg->pPatRegs->EXCEPTION_LOGGING_DATA0);
    val2= CSL_REG32_RD(&pPatCfg->pPatRegs->EXCEPTION_LOGGING_DATA1);

    addrH = CSL_FEXT(val2, PAT_EXCEPTION_LOGGING_DATA1_ADDR_H);
    addrL = CSL_FEXT(val, PAT_EXCEPTION_LOGGING_DATA0_ADDR_L);
    pExceptionInfo->address     = (((uint64_t)addrH) << 32) | (uint64_t)addrL;

    val = CSL_REG32_RD(&pPatCfg->pPatRegs->EXCEPTION_LOGGING_DATA2);
    pExceptionInfo->routeId     = CSL_FEXT(val, PAT_EXCEPTION_LOGGING_DATA2_ROUTEID);
    pExceptionInfo->privId      = CSL_FEXT(val, PAT_EXCEPTION_LOGGING_DATA2_PRIV_ID);

    pExceptionInfo->bWrite      = (CSL_FEXT(val, PAT_EXCEPTION_LOGGING_DATA2_WRITE) == 0U) ? 0U : 1U;
    pExceptionInfo->bRead       = (CSL_FEXT(val, PAT_EXCEPTION_LOGGING_DATA2_READ) == 0U) ? 0U : 1U;
    pExceptionInfo->bDebug      = (CSL_FEXT(val, PAT_EXCEPTION_LOGGING_DATA2_DEBUG) == 0U) ? 0U : 1U;
    pExceptionInfo->bCacheable  = (CSL_FEXT(val, PAT_EXCEPTION_LOGGING_DATA2_CACHEABLE) == 0U) ? 0U : 1U;
    pExceptionInfo->bPriv       = (CSL_FEXT(val, PAT_EXCEPTION_LOGGING_DATA2_PRIV) == 0U) ? 0U : 1U;
    pExceptionInfo->bSecure     = (CSL_FEXT(val, PAT_EXCEPTION_LOGGING_DATA2_SECURE) == 0U) ? 0U : 1U;

    val = CSL_REG32_RD(&pPatCfg->pPatRegs->EXCEPTION_LOGGING_DATA3);
    pExceptionInfo->byteCnt     = CSL_FEXT(val, PAT_EXCEPTION_LOGGING_DATA3_BYTECNT);

    /* Clear the interrupt status bit just to make sure the log is cleared for the next exception */
    retVal = CSL_patClrIntrPending(pPatCfg, CSL_PAT_INTR_SRC_EXCEPTION);

    return retVal;
}

int32_t CSL_patSetPageTranslationEnable(const CSL_PatConfigParms *pPatCfg, uint64_t inputAddress, uint32_t bEnable)
{
    uint32_t pageTableIndex;
    int32_t  retVal = -1;

    pageTableIndex = CSL_patGetPageTableIndex(pPatCfg, inputAddress);
    if( pageTableIndex < CSL_patGetMaxPages(pPatCfg) )
    {
        uint32_t blockIndex, pageIndex;

        CSL_patGetBlockAndPageIndex( pageTableIndex, &blockIndex, &pageIndex );
        CSL_REG32_FINS( &pPatCfg->pPatTableRegs->BLOCK[blockIndex].PAGE[pageIndex].BASE_REG_H, PAT_TABLE_BLOCK_PAGE_BASE_REG_H_ENABLE, bEnable );
        retVal = 0;
    }
    return retVal;
}

int32_t CSL_patEnablePageTranslation(const CSL_PatConfigParms *pPatCfg, uint64_t inputAddress)
{
    return CSL_patSetPageTranslationEnable(pPatCfg, inputAddress, true);
}

int32_t CSL_patDisablePageTranslation(const CSL_PatConfigParms *pPatCfg, uint64_t inputAddress)
{
    return CSL_patSetPageTranslationEnable(pPatCfg, inputAddress, false);
}

int32_t CSL_patConfigPageTranslation(const CSL_PatConfigParms *pPatCfg, uint64_t inputAddress, uint64_t translatedAddress)
{
    uint32_t pageTableIndex;
    int32_t  retVal = -1;

    pageTableIndex = CSL_patGetPageTableIndex( pPatCfg, inputAddress );
    if( pageTableIndex < CSL_patGetMaxPages(pPatCfg) )
    {
        /*  Disable translation for this page */
        retVal = CSL_patDisablePageTranslation( pPatCfg, inputAddress );
        if( retVal == 0 )
        {
            uint32_t blockIndex, pageIndex;

            CSL_patGetBlockAndPageIndex( pageTableIndex, &blockIndex, &pageIndex );
            /*  Configure BASE_L_ADDR with translatedAddress[43:12] */
            CSL_REG32_WR( &pPatCfg->pPatTableRegs->BLOCK[blockIndex].PAGE[pageIndex].BASE_REG_L, CSL_FMK( PAT_TABLE_BLOCK_PAGE_BASE_REG_L_BASE_L, (uint32_t)(translatedAddress>>12) ) );
            /*  Configure BASE_H_ADDR with translatedAddress[47:44] */
            CSL_REG32_FINS( &pPatCfg->pPatTableRegs->BLOCK[blockIndex].PAGE[pageIndex].BASE_REG_H, PAT_TABLE_BLOCK_PAGE_BASE_REG_H_BASE_H, (uint32_t)(translatedAddress>>44) );
            /*  Enable translation for this page */
            retVal = CSL_patEnablePageTranslation( pPatCfg, inputAddress );
        }
    }
    return retVal;
}
