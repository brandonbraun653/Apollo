/**
 * @file  csl_pvu.c
 *
 * @brief
 *  CSL-FL implementation file for the PVU module.
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2017-2019, Texas Instruments, Inc.
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

#include <ti/csl/csl_pvu.h>

#define CSL_PVU_MAX_DMA_SUBCLASSES  (4U)    /* Max # of DMA subclasses */

static void CSL_pvuGetAndSaveCfg( CSL_PvuCfg *pPvuCfg );
static bool CSL_pvuIsTlbEnabled( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum );

/*=============================================================================
 *  Internal Functions
 *===========================================================================*/
static void CSL_pvuGetAndSaveCfg( CSL_PvuCfg *pPvuCfg )
{
    uint32_t regVal;

    regVal = CSL_REG32_RD( &pPvuCfg->pPvuRegs->CONFIG );
    pPvuCfg->numTlbs          = CSL_FEXT( regVal, PVU_CONFIG_TLBS );
    pPvuCfg->numEntriesPerTlb = CSL_FEXT( regVal, PVU_CONFIG_TLB_ENTRIES );
}

static bool CSL_pvuIsTlbEnabled( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum )
{
    return (CSL_REG32_FEXT( &pPvuCfg->pPvuTlbRegs->VIRT[tlbNum].CHAIN, PVU_TLB_VIRT_CHAIN_EN ) == 0U) ? (bool)false : (bool)true;
}

/*=============================================================================
 *  External CSL-FL Functions
 *===========================================================================*/

uint32_t CSL_pvuGetRevision( const CSL_PvuCfg *pPvuCfg )
{
    return CSL_REG32_RD( &pPvuCfg->pPvuRegs->PID );
}

void CSL_pvuGetCfg( CSL_PvuCfg *pPvuCfg, uint32_t *pNumTlbs, uint32_t *pNumEntriesPerTlb )
{
    CSL_pvuGetAndSaveCfg( pPvuCfg );
    *pNumTlbs          = pPvuCfg->numTlbs;
    *pNumEntriesPerTlb = pPvuCfg->numEntriesPerTlb;
}

int32_t CSL_pvuSetMaxVirtId( CSL_PvuCfg *pPvuCfg, uint32_t numVirtIds )
{
    int32_t retVal;

    CSL_pvuGetAndSaveCfg( pPvuCfg );
    if( numVirtIds <= pPvuCfg->numTlbs )
    {
        CSL_REG32_WR( &pPvuCfg->pPvuRegs->VIRTID_MAP2, CSL_FMK( PVU_VIRTID_MAP2_MAX_CNT, numVirtIds ) );
        pPvuCfg->numVirtIds = numVirtIds;
        retVal = 0;
    }
    else
    {
        retVal = -1;
    }
    return retVal;
}

int32_t CSL_pvuCfgDmaClassSupport( CSL_PvuCfg *pPvuCfg, uint32_t numDmaVirtIds, uint32_t mapSubClass0, uint32_t mapSubClass1, uint32_t mapSubClass2, uint32_t mapSubClass3 )
{
    int32_t retVal;

    if( numDmaVirtIds > pPvuCfg->numTlbs )
    {
        retVal = -1;
    }
    else if( (mapSubClass0 > CSL_PVU_VIRTID_MAP1_DMA_CL0_MAX)   ||
             (mapSubClass1 > CSL_PVU_VIRTID_MAP1_DMA_CL1_MAX)   ||
             (mapSubClass2 > CSL_PVU_VIRTID_MAP1_DMA_CL2_MAX)   ||
             (mapSubClass3 > CSL_PVU_VIRTID_MAP1_DMA_CL3_MAX) )
    {
        retVal = -2;
    }
    else
    {
        uint32_t regVal;

        regVal = CSL_FMK( PVU_VIRTID_MAP1_DMA_CNT, numDmaVirtIds )  |
                 CSL_FMK( PVU_VIRTID_MAP1_DMA_CL0, mapSubClass0 )   |
                 CSL_FMK( PVU_VIRTID_MAP1_DMA_CL1, mapSubClass1 )   |
                 CSL_FMK( PVU_VIRTID_MAP1_DMA_CL2, mapSubClass2 )   |
                 CSL_FMK( PVU_VIRTID_MAP1_DMA_CL3, mapSubClass3 );
        CSL_REG32_WR( &pPvuCfg->pPvuRegs->VIRTID_MAP1, regVal );
        pPvuCfg->numDmaVirtIds = numDmaVirtIds;
        retVal = 0;
    }
    return retVal;
}

int32_t CSL_pvuGetTlbNum( const CSL_PvuCfg *pPvuCfg, uint32_t virtId, uint32_t dmaSubClass )
{
    int32_t retVal;

    if( virtId >= pPvuCfg->numTlbs )
    {
        retVal = -1;
    }
    else if( dmaSubClass >= CSL_PVU_MAX_DMA_SUBCLASSES )
    {
        retVal = -2;
    }
    else
    {
        uint32_t tlbNum, numDmaVirtIds = pPvuCfg->numDmaVirtIds;

        if( virtId < numDmaVirtIds )
        {
            tlbNum = (virtId * CSL_PVU_MAX_DMA_SUBCLASSES) + dmaSubClass;
        }
        else
        {
            tlbNum = (numDmaVirtIds * CSL_PVU_MAX_DMA_SUBCLASSES) + (virtId - numDmaVirtIds);
        }
        retVal = (int32_t)tlbNum;
    }
    return retVal;
}

/**
 *  \brief Configure a TLB entry
 *
 *  This function is used to configure the specified TLB entry.
 *
 *  Note that the TLB must be disabled before it can be configured.
 *
 *  Call the #CSL_pvuGetTlbNum function to get the TLB number associated with
 *  a given virtId and dmaSubClass (if virtId belongs to a DMA class).
 *
 *  \param pPvuCfg      [IN]    Pointer to the CSL_PvuCfg config structure
 *  \param tlbNum       [IN]    TLB number
 *  \param entryNum     [IN]    TLB entry number
 *  \param pTlbCfg      [IN]    Pointer to TLB configuration structure (see
 *                              #CSL_PvuTlbCfg)
 *
 *  \return  0 = success
 *          -1 = tlbNum or entryNum arguments are invalid
 *          -2 = TLB is currently enabled (disable it first)
 */
int32_t CSL_pvuCfgTlb( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum, uint32_t entryNum, const CSL_PvuTlbCfg *pTlbCfg )
{
    int32_t retVal;

    if( (tlbNum >= pPvuCfg->numTlbs) || (entryNum >= pPvuCfg->numEntriesPerTlb) )
    {
        retVal = -1;
    }
    else if( CSL_pvuIsTlbEnabled( pPvuCfg, tlbNum ) == (bool)true )
    {
        retVal = -2;
    }
    else
    {
        uint32_t regVal;
        CSL_pvu_tlbRegs_VIRT_TLB *pTlb = &(pPvuCfg->pPvuTlbRegs->VIRT[tlbNum].TLB[entryNum]);

        regVal = CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY0_VBASE_L, (uint32_t)(pTlbCfg->virtBaseAddr & 0xFFFFFFFFU) );
        CSL_REG32_WR( &pTlb->ENTRY0, regVal );
        regVal = CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY1_VBASE_H, (uint32_t)(pTlbCfg->virtBaseAddr >> 32U) );
        CSL_REG32_WR( &pTlb->ENTRY1, regVal );

        regVal = CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_MODE,         (uint32_t)pTlbCfg->mode )                                    |
                 CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_SEC_DEM,      (pTlbCfg->bEnableSecDemote) ? (uint32_t)1U : (uint32_t)0U )      |
                 CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_PSECURE,      (pTlbCfg->bPageSecure) ? (uint32_t)1U : (uint32_t)0U )           |
                 CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_PSIZE,        (uint32_t)pTlbCfg->pageSize )                                |
                 CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_PPERM,        pTlbCfg->pagePerms )            |
                 CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_PMEMTYPE,     (uint32_t)pTlbCfg->pageMemType )                             |
                 CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_PPREFETCH,    (pTlbCfg->bPagePrefetch ) ? (uint32_t)1U : (uint32_t)0U )      |
                 CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_PISABLE,      (pTlbCfg->bPageInnerShareable ) ? (uint32_t)1U : (uint32_t)0U )|
                 CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_POSABLE,      (pTlbCfg->bPageOuterShareable ) ? (uint32_t)1U : (uint32_t)0U )|
                 CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_PIALLOCPOL,   (uint32_t)pTlbCfg->pageInnerAllocPolicy )|
                 CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY2_POALLOCPOL,   (uint32_t)pTlbCfg->pageOuterAllocPolicy );
        CSL_REG32_WR( &pTlb->ENTRY2, regVal );

        regVal = CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY4_PBASE_L, (uint32_t)(pTlbCfg->physBaseAddr & 0xFFFFFFFFU) );
        CSL_REG32_WR( &pTlb->ENTRY4, regVal );
        regVal = CSL_FMK( PVU_TLB_VIRT_TLB_ENTRY5_PBASE_H, (uint32_t)(pTlbCfg->physBaseAddr >> 32U) );
        CSL_REG32_WR( &pTlb->ENTRY5, regVal );
        retVal = 0;
    }
    return retVal;
}

int32_t CSL_pvuSetTlbEnable( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum, bool bEnable )
{
    int32_t retVal;

    if( tlbNum >= pPvuCfg->numTlbs )
    {
        retVal = -1;
    }
    else
    {
        CSL_REG32_FINS( &pPvuCfg->pPvuTlbRegs->VIRT[tlbNum].CHAIN, PVU_TLB_VIRT_CHAIN_EN, (bEnable ? (uint32_t)1U : (uint32_t)0U));
        retVal = 0;
    }
    return retVal;
}

int32_t CSL_pvuChainToTlb( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum, uint32_t chainToTlbNum )
{
    int32_t retVal;

    if( (tlbNum >= pPvuCfg->numTlbs) || (chainToTlbNum >= pPvuCfg->numTlbs) || (tlbNum == chainToTlbNum) )
    {
        retVal = -1;
    }
    else
    {
        CSL_REG32_FINS( &pPvuCfg->pPvuTlbRegs->VIRT[tlbNum].CHAIN, PVU_TLB_VIRT_CHAIN_CHAIN, chainToTlbNum );
        retVal = 0;
    }
    return retVal;
}

int32_t CSL_pvuSetTlbFaultLogging( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum, bool bEnable )
{
    int32_t retVal;

    if( tlbNum >= pPvuCfg->numTlbs )
    {
        retVal = -1;
    }
    else
    {
        CSL_REG32_FINS( &pPvuCfg->pPvuTlbRegs->VIRT[tlbNum].CHAIN, PVU_TLB_VIRT_CHAIN_LOG_DIS, (bEnable ? (uint32_t)0U : (uint32_t)1U) );
        retVal = 0;
    }
    return retVal;
}

void CSL_pvuSetExceptionTypeLoggingEnable( const CSL_PvuCfg *pPvuCfg, uint32_t exceptionTypes, bool bEnable )
{
    uint32_t regVal;

    regVal = CSL_REG32_RD( &pPvuCfg->pPvuRegs->EXCEPTION_LOGGING_DISABLE );
    if( bEnable == (bool)true )
    {
        /* Clear disable bits corresponding with specified exceptionTypes */
        regVal &= ~exceptionTypes;
    }
    else
    {
        /* Set disable bits corresponding with specified exceptionTypes */
        regVal |= exceptionTypes;
    }
    CSL_REG32_WR( &pPvuCfg->pPvuRegs->EXCEPTION_LOGGING_DISABLE, regVal );
}

void CSL_pvuSetErrMsgDestId( const CSL_PvuCfg *pPvuCfg, uint32_t destId )
{
    CSL_REG32_WR( &pPvuCfg->pPvuRegs->DESTINATION_ID, CSL_FMK( PVU_DESTINATION_ID_DEST_ID, destId ) );
}

void CSL_pvuSetExceptionLoggingEnable( const CSL_PvuCfg *pPvuCfg, bool bEnable )
{
    uint32_t bLoggingDisable = (bEnable==(bool)true) ? (uint32_t)0U : (uint32_t)1U;
    
    CSL_REG32_WR( &pPvuCfg->pPvuRegs->EXCEPTION_LOGGING_CONTROL,
        CSL_FMK( PVU_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR, bLoggingDisable )      |
        CSL_FMK( PVU_EXCEPTION_LOGGING_CONTROL_DISABLE_F,    bLoggingDisable ) );
}

int32_t CSL_pvuSetEnable( const CSL_PvuCfg *pPvuCfg, bool bEnable )
{
    int32_t retVal;

    if( (bEnable == (bool)true) && (pPvuCfg->numVirtIds == 0U) )
    {
        retVal = -1;
    }
    else
    {
        CSL_REG32_WR( &pPvuCfg->pPvuRegs->ENABLE, CSL_FMK( PVU_ENABLE_EN, (bEnable ? (uint32_t)1U : (uint32_t)0U ) ) );
        retVal = 0;
    }
    return retVal;
}

int32_t CSL_pvuIsTlbFaultSet( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum )
{
    int32_t retVal;

    if( tlbNum >= pPvuCfg->numTlbs )
    {
        retVal = -1;
    }
    else
    {
        retVal = (int32_t)CSL_REG32_FEXT( &pPvuCfg->pPvuTlbRegs->VIRT[tlbNum].CHAIN, PVU_TLB_VIRT_CHAIN_FAULT );
    }
    return retVal;
}

int32_t CSL_pvuClrTlbFault( const CSL_PvuCfg *pPvuCfg, uint32_t tlbNum )
{
    int32_t retVal;

    if( tlbNum >= pPvuCfg->numTlbs )
    {
        retVal = -1;
    }
    else
    {
        CSL_REG32_FINS( &pPvuCfg->pPvuTlbRegs->VIRT[tlbNum].CHAIN, PVU_TLB_VIRT_CHAIN_FAULT, (uint32_t)1U );
        retVal = 0;
    }
    return retVal;
}

bool CSL_pvuIsExceptionIntrPending( const CSL_PvuCfg *pPvuCfg )
{
    return (CSL_REG32_FEXT( &pPvuCfg->pPvuRegs->EXCEPTION_PEND_SET, PVU_EXCEPTION_PEND_SET_PEND_SET )==0U) ? (bool)false : (bool)true ;
}

void CSL_pvuSetExceptionIntrPendingSet( const CSL_PvuCfg *pPvuCfg, bool bSet )
{
    if( bSet == (bool)true )
    {
        CSL_REG32_WR( &pPvuCfg->pPvuRegs->EXCEPTION_PEND_SET, CSL_FMK( PVU_EXCEPTION_PEND_SET_PEND_SET, (uint32_t)1U ) );
    }
    else
    {
        CSL_REG32_WR( &pPvuCfg->pPvuRegs->EXCEPTION_PEND_CLEAR, CSL_FMK( PVU_EXCEPTION_PEND_CLEAR_PEND_CLR, (uint32_t)1U ) );
    }
}

void CSL_pvuAckExceptionIntr( const CSL_PvuCfg *pPvuCfg )
{
    CSL_REG32_WR( &pPvuCfg->pPvuRegs->EOI_REG, 0 );
}

void CSL_pvuSetExceptionIntrEnable( const CSL_PvuCfg *pPvuCfg, bool bEnable )
{
    if( bEnable == (bool)true )
    {
        CSL_pvuSetExceptionLoggingEnable( pPvuCfg, (bool)true );
        CSL_REG32_WR( &pPvuCfg->pPvuRegs->EXCEPTION_ENABLE_SET, CSL_FMK( PVU_EXCEPTION_ENABLE_SET_ENABLE_SET, (uint32_t)1U ) );
    }
    else
    {
        CSL_REG32_WR( &pPvuCfg->pPvuRegs->EXCEPTION_ENABLE_CLEAR, CSL_FMK( PVU_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR, (uint32_t)1U ) );
    }
}

/**
 *  \brief Get exception information
 *
 *  This function is used to get detailed exception information.
 *
 *  \param pPvuCfg        [IN]  Pointer to the CSL_PvuCfg config structure
 *  \param pExceptionInfo [IN]  Pointer to a #CSL_PvuExceptionInfo structure
 *                              where the exception information is written to
 *
 *  \return  None
 */
void CSL_pvuGetExceptionInfo( const CSL_PvuCfg *pPvuCfg, CSL_PvuExceptionInfo *pExceptionInfo )
{
    uint32_t val, val2;

    val = CSL_REG32_RD(&pPvuCfg->pPvuRegs->EXCEPTION_LOGGING_HEADER0);
    pExceptionInfo->type        = CSL_FEXT(val, PVU_EXCEPTION_LOGGING_HEADER0_TYPE_F);
    pExceptionInfo->destId      = CSL_FEXT(val, PVU_EXCEPTION_LOGGING_HEADER0_DEST_ID);
    pExceptionInfo->srcId       = CSL_FEXT(val, PVU_EXCEPTION_LOGGING_HEADER0_SRC_ID);

    val = CSL_REG32_RD(&pPvuCfg->pPvuRegs->EXCEPTION_LOGGING_HEADER1);
    pExceptionInfo->code        = CSL_FEXT(val, PVU_EXCEPTION_LOGGING_HEADER1_CODE);
    pExceptionInfo->group       = CSL_FEXT(val, PVU_EXCEPTION_LOGGING_HEADER1_GROUP);

    val = CSL_REG32_FEXT(&pPvuCfg->pPvuRegs->EXCEPTION_LOGGING_DATA0, PVU_EXCEPTION_LOGGING_DATA0_ADDR_L);
    val2= CSL_REG32_FEXT(&pPvuCfg->pPvuRegs->EXCEPTION_LOGGING_DATA1, PVU_EXCEPTION_LOGGING_DATA1_ADDR_H);
    pExceptionInfo->address     = (((uint64_t)val2) << 32) | ((uint64_t)val);

    val = CSL_REG32_RD(&pPvuCfg->pPvuRegs->EXCEPTION_LOGGING_DATA2);
    pExceptionInfo->routeId     = CSL_FEXT(val, PVU_EXCEPTION_LOGGING_DATA2_ROUTEID);
    pExceptionInfo->privId      = CSL_FEXT(val, PVU_EXCEPTION_LOGGING_DATA2_PRIV_ID);
    pExceptionInfo->bWrite      = (CSL_FEXT(val, PVU_EXCEPTION_LOGGING_DATA2_WRITE)==0U) ?     (bool)false : (bool)true;
    pExceptionInfo->bRead       = (CSL_FEXT(val, PVU_EXCEPTION_LOGGING_DATA2_READ)==0U) ?      (bool)false : (bool)true;
    pExceptionInfo->bDebug      = (CSL_FEXT(val, PVU_EXCEPTION_LOGGING_DATA2_DEBUG)==0U) ?     (bool)false : (bool)true;
    pExceptionInfo->bCacheable  = (CSL_FEXT(val, PVU_EXCEPTION_LOGGING_DATA2_CACHEABLE)==0U) ? (bool)false : (bool)true;
    pExceptionInfo->bPriv       = (CSL_FEXT(val, PVU_EXCEPTION_LOGGING_DATA2_PRIV)==0U) ?      (bool)false : (bool)true;
    pExceptionInfo->bSecure     = (CSL_FEXT(val, PVU_EXCEPTION_LOGGING_DATA2_SECURE)==0U) ?    (bool)false : (bool)true;

    val = CSL_REG32_RD(&pPvuCfg->pPvuRegs->EXCEPTION_LOGGING_DATA3);
    pExceptionInfo->byteCnt     = CSL_FEXT(val, PVU_EXCEPTION_LOGGING_DATA3_BYTECNT);

    /* Clear the interrupt status bit just to make sure the log is cleared for the next exception */
    CSL_pvuSetExceptionIntrPendingSet( pPvuCfg, (bool)false );
}
