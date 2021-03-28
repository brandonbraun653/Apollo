/**
 * @file  csl_rat.c
 *
 * @brief
 *  CSL-FL implementation file for the ksbus_rat module.
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

#include <ti/csl/cslr_rat.h>
#include <ti/csl/csl_rat.h>
#include <ti/csl/csl_types.h>

/*=============================================================================
 *  Internal Functions Declarations
 *===========================================================================*/
static bool isPowerOf2(uint64_t v);
static uint32_t lmo(uint64_t v);
static bool CSL_ratGetRegionTranslationConfig(const CSL_ratRegs *pRatRegs, uint32_t regionIndex, CSL_RatTranslationCfgInfo *pTranslationCfg);
static bool CSL_ratIsRegionOverlap(const CSL_ratRegs *pRatRegs, uint32_t thisRegionIndex, const CSL_RatTranslationCfgInfo *pTranslationCfg);
static bool CSL_ratValidateTranslationConfig(const CSL_ratRegs *pRatRegs, uint32_t regionIndex, CSL_RatTranslationCfgInfo *pTranslationCfg );
static void CSL_ratSetExceptionLoggingEnable(CSL_ratRegs *pRatRegs, bool bEnable);
static void CSL_ratSetExceptionLoggingIntEnable(CSL_ratRegs *pRatRegs, bool bEnable);
static void CSL_ratSetIntEnable(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc, bool bEnable);
static bool CSL_ratSetRegionTranslationEnable(CSL_ratRegs *pRatRegs, uint32_t regionIndex, bool bEnable);

/*=============================================================================
 *  Internal Functions
 *===========================================================================*/
static bool isPowerOf2(uint64_t v)
{
    return ((v != 0UL) && ((v & (v - 1UL)) == 0UL))? ((bool)true) : ((bool)false);
}

static uint32_t lmo(uint64_t v)
{
    uint32_t r = 0U;  /* r will be lg(v) */
    uint64_t local_v = v;

    local_v = local_v >> 1UL;
    while (local_v != 0UL)
    {
      r++;
      local_v = local_v >> 1UL;
    }
    return r;
}

static bool CSL_ratGetRegionTranslationConfig(const CSL_ratRegs *pRatRegs, uint32_t regionIndex, CSL_RatTranslationCfgInfo *pTranslationCfg)
{
    bool retVal = (bool)false;

    if( regionIndex < CSL_ratGetMaxRegions(pRatRegs) )
    {
        uint32_t regVal, regVal1;
        /*---------------------------------------------------------------------
         * Read translation configuration parameters from registers into their
         * respective structure elements for this region
         *-------------------------------------------------------------------*/
        pTranslationCfg->sizeInBytes = (uint64_t)1 << CSL_REG32_FEXT( &pRatRegs->REGION[regionIndex].CTRL, RAT_REGION_CTRL_SIZE );
        pTranslationCfg->baseAddress = CSL_REG32_RD( &pRatRegs->REGION[regionIndex].BASE );
        regVal  = CSL_REG32_RD( &pRatRegs->REGION[regionIndex].TRANS_L );
        regVal1 = CSL_REG32_RD( &pRatRegs->REGION[regionIndex].TRANS_U );
        pTranslationCfg->translatedAddress  = (((uint64_t)regVal1 & 0x0000FFFFU) << 32U) | (uint64_t)regVal;
        retVal = (bool)true;
    }
    return retVal;
}

static bool CSL_ratIsRegionOverlap(const CSL_ratRegs *pRatRegs, uint32_t thisRegionIndex, const CSL_RatTranslationCfgInfo *pTranslationCfg)
{
    uint32_t                    regionIndex;
    CSL_RatTranslationCfgInfo   xlatCfg;
    bool                        bGetGetRegionTranslationConfig, retVal = (bool)false;

    for( regionIndex = ((uint32_t)0U); regionIndex < CSL_ratGetMaxRegions(pRatRegs); regionIndex++ )
    {
        if( (regionIndex != thisRegionIndex) && (CSL_ratIsRegionTranslationEnabled( pRatRegs, regionIndex ) == (bool)true) )
        {
            bGetGetRegionTranslationConfig = CSL_ratGetRegionTranslationConfig(pRatRegs, regionIndex, &xlatCfg);
            if( bGetGetRegionTranslationConfig == (bool)true )
            {
                uint64_t r0l, r0h, r1l, r1h;

                r0l = pTranslationCfg->baseAddress;
                r0h = r0l + pTranslationCfg->sizeInBytes;
                r1l = xlatCfg.baseAddress;
                r1h = r1l + xlatCfg.sizeInBytes;
                if( !((r0l >= r1h) || (r1l >= r0h)) )
                {
                    retVal = (bool)true;
                }
            }
        }
    }
    return retVal;
}

static bool CSL_ratValidateTranslationConfig(const CSL_ratRegs *pRatRegs, uint32_t regionIndex, CSL_RatTranslationCfgInfo *pTranslationCfg )
{
    uint64_t    regionSize = pTranslationCfg->sizeInBytes;
    bool        retVal = (bool)true;

    /*-------------------------------------------------------------------------
     * If the region size is not a power-of-2, round-it-up to the next
     * power-of-2 size.
     *-----------------------------------------------------------------------*/
    if( isPowerOf2(regionSize) == (bool)false )
    {
        regionSize = (uint64_t)1 << (lmo(regionSize)+1U);
        pTranslationCfg->sizeInBytes = regionSize;
    }
    /*-------------------------------------------------------------------------
     * The region base address and translated base address must be aligned to
     * the defined region size. So if the region size is defined as 64KB, then
     * the two addresses must be 64KB aligned. The module does not check for
     * this so it is SW's responsibility. Regions that are not aligned will
     * have unpredictable results.
     *
     * Multiple region definitions must not overlap in their covered address
     * space. The module does not check for this so it is SW's responsibility.
     * If they do overlap, then there will be unpredictable results.
     *-----------------------------------------------------------------------*/
    if( (((uint64_t)pTranslationCfg->baseAddress & (regionSize-1UL)) != 0UL)  ||
        ((pTranslationCfg->translatedAddress     & (regionSize-1UL)) != 0UL)  ||
        (CSL_ratIsRegionOverlap(pRatRegs, regionIndex, pTranslationCfg )) )
    {
        retVal = (bool)false;
    }
    return retVal;
}

static void CSL_ratSetExceptionLoggingEnable(CSL_ratRegs *pRatRegs, bool bEnable)
{
    CSL_REG32_FINS(&pRatRegs->EXCEPTION_LOGGING_CONTROL, RAT_EXCEPTION_LOGGING_CONTROL_DISABLE_F, (bEnable ? 0U : 1U) );
}

static void CSL_ratSetExceptionLoggingIntEnable(CSL_ratRegs *pRatRegs, bool bEnable)
{
    CSL_REG32_FINS(&pRatRegs->EXCEPTION_LOGGING_CONTROL, RAT_EXCEPTION_LOGGING_CONTROL_DISABLE_INTR, (bEnable ? 0U : 1U));
}

static void CSL_ratSetIntEnable(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc, bool bEnable)
{
    if( intrSrc == CSL_RAT_INTR_SRC_EXCEPTION )
    {
        if( bEnable == (bool)true )
        {
            CSL_REG32_WR( &pRatRegs->EXCEPTION_ENABLE_SET, CSL_FMK( RAT_EXCEPTION_ENABLE_SET_ENABLE_SET, (uint32_t)1 ) );
        }
        else
        {
            CSL_REG32_WR( &pRatRegs->EXCEPTION_ENABLE_CLEAR, CSL_FMK( RAT_EXCEPTION_ENABLE_CLEAR_ENABLE_CLR, (uint32_t)1 ) );
        }
    }
}

static bool CSL_ratSetRegionTranslationEnable(CSL_ratRegs *pRatRegs, uint32_t regionIndex, bool bEnable)
{
    bool retVal = (bool)false;

    if( regionIndex < CSL_ratGetMaxRegions(pRatRegs) )
    {
        uint32_t regVal;

        if( bEnable == (bool)true )
        {
            regVal = ((uint32_t)1U);
        }
        else
        {
            regVal = ((uint32_t)0U);
        }
        CSL_REG32_FINS( &pRatRegs->REGION[regionIndex].CTRL, RAT_REGION_CTRL_EN, regVal );
        retVal = (bool)true;
    }
    return retVal;
}

/*=============================================================================
 *  External CSL-F Functions
 *===========================================================================*/

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_read
 */
uint32_t CSL_ratGetRevision(const CSL_ratRegs *pRatRegs)
{
    uint32_t rev = 0x0U;

    if (pRatRegs != NULL_PTR)
    {
        rev = CSL_REG32_RD(&pRatRegs->PID);
    }

    return rev;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_read
 */
uint32_t CSL_ratGetMaxRegions(const CSL_ratRegs *pRatRegs)
{
    uint32_t   rtlRev;
    uint32_t   maxRegions = 0U;

    if (pRatRegs != NULL_PTR)
    {
        rtlRev = CSL_REG32_FEXT( &pRatRegs->PID, RAT_PID_RTL );
        /* Read max regions from CONFIG register only if rtlRev > 1 */
        if( rtlRev > 1U )
        {
            maxRegions = CSL_REG32_FEXT( &pRatRegs->CONFIG, RAT_CONFIG_REGIONS );
        }
        else
        {
            maxRegions = ((uint32_t)16U);
        }
    }
    return maxRegions;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_read
 */
bool CSL_ratIsRegionTranslationEnabled(const CSL_ratRegs *pRatRegs, uint32_t regionIndex)
{
    bool retVal = (bool)false;

    if (pRatRegs != NULL_PTR)
    {
        if( (regionIndex < CSL_ratGetMaxRegions(pRatRegs))  &&
            (CSL_REG32_FEXT(&pRatRegs->REGION[regionIndex].CTRL, RAT_REGION_CTRL_EN) != 0U) )
        {
            retVal = (bool)true;
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
int32_t CSL_ratSetErrMsgDestId(CSL_ratRegs *pRatRegs, uint32_t destId)
{
    int32_t retVal = CSL_EFAIL;

    if ((pRatRegs != NULL_PTR) && (destId <= CSL_RAT_DESTINATION_ID_DEST_ID_MAX))
    {
        CSL_REG32_WR(&pRatRegs->DESTINATION_ID, CSL_FMK(RAT_DESTINATION_ID_DEST_ID, destId));
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_read
 */
int32_t CSL_ratGetErrMsgDestId(const CSL_ratRegs *pRatRegs, uint32_t *pDestId)
{
    int32_t retVal = CSL_EFAIL;

    if ((pRatRegs != NULL_PTR) && (pDestId != NULL_PTR))
    {
        *pDestId = CSL_REG32_FEXT(&pRatRegs->DESTINATION_ID, RAT_DESTINATION_ID_DEST_ID);
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
int32_t CSL_ratEnableExceptionLogging(CSL_ratRegs *pRatRegs)
{
    int32_t retVal = CSL_EFAIL;

    if (pRatRegs != NULL_PTR)
    {
        CSL_ratSetExceptionLoggingEnable(pRatRegs, (bool)true);
        CSL_ratSetExceptionLoggingIntEnable(pRatRegs, (bool)true);
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
int32_t CSL_ratDisableExceptionLogging(CSL_ratRegs *pRatRegs)
{
    int32_t retVal = CSL_EFAIL;

    if (pRatRegs != NULL_PTR)
    {
        CSL_ratSetExceptionLoggingEnable(pRatRegs, (bool)false);
        CSL_ratSetExceptionLoggingIntEnable(pRatRegs, (bool)false);
        retVal = CSL_PASS;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_read
 */
uint32_t CSL_ratIsExceptionLoggingEnabled(const CSL_ratRegs *pRatRegs)
{
    uint32_t status, retVal;
    status = CSL_REG32_FEXT(&pRatRegs->EXCEPTION_LOGGING_CONTROL, RAT_EXCEPTION_LOGGING_CONTROL_DISABLE_F);
    /* since 0 indicates enable and 1 indicates disable, toggle the lsb */
    if (status == 0u)
    {
        retVal = ((uint32_t)1u);
    }
    else
    {
        retVal = ((uint32_t)0u);
    }
    return (retVal);
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_read
 */
bool CSL_ratIsIntrPending(const CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc)
{
    bool retVal = (bool)false;

    if ((pRatRegs != NULL_PTR) && (intrSrc == CSL_RAT_INTR_SRC_EXCEPTION))
    {
        retVal = (CSL_REG32_FEXT( &pRatRegs->EXCEPTION_PEND_SET, RAT_EXCEPTION_PEND_SET_PEND_SET ) == 1U)?(bool)true:(bool)false;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
bool CSL_ratSetIntrPending(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc)
{
    bool retVal = (bool)false;

    if ((pRatRegs != NULL_PTR) && (intrSrc == CSL_RAT_INTR_SRC_EXCEPTION))
    {
        CSL_REG32_WR( &pRatRegs->EXCEPTION_PEND_SET, CSL_FMK( RAT_EXCEPTION_PEND_SET_PEND_SET, 1U ) );
        retVal = (bool)true;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
bool CSL_ratClrIntrPending(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc)
{
    bool retVal = (bool)false;

    if ((pRatRegs != NULL_PTR) && (intrSrc == CSL_RAT_INTR_SRC_EXCEPTION))
    {
        CSL_REG32_WR( &pRatRegs->EXCEPTION_PEND_CLEAR, CSL_FMK( RAT_EXCEPTION_PEND_CLEAR_PEND_CLR, 1U ) );
        retVal = (bool)true;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
bool CSL_ratAckIntr(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc)
{
    bool retVal = (bool)false;

    if ((pRatRegs != NULL_PTR) && (intrSrc == CSL_RAT_INTR_SRC_EXCEPTION))
    {
        CSL_REG32_WR( &pRatRegs->EOI_REG, 0 );
        retVal = (bool)true;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
bool CSL_ratEnableIntr(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc)
{
    bool retVal = (bool)false;

    if ((intrSrc == CSL_RAT_INTR_SRC_EXCEPTION)    &&
        (CSL_ratEnableExceptionLogging(pRatRegs) == CSL_PASS))
    {
        CSL_ratSetIntEnable(pRatRegs, intrSrc, (bool)true);
        retVal = (bool)true;
    }

    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
bool CSL_ratDisableIntr(CSL_ratRegs *pRatRegs, CSL_RatIntrSrcTypes intrSrc)
{
    bool retVal = (bool)false;

    if ((pRatRegs != NULL_PTR) && (intrSrc == CSL_RAT_INTR_SRC_EXCEPTION))
    {
        CSL_ratSetIntEnable(pRatRegs, intrSrc, (bool)false);
        retVal = (bool)true;
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_read
 */
bool CSL_ratGetExceptionInfo(CSL_ratRegs *pRatRegs, CSL_RatExceptionInfo *pExceptionInfo)
{
    uint32_t val, val2;
    bool retVal = (bool)false;

    if ((pRatRegs != NULL_PTR) && (pExceptionInfo != NULL_PTR))
    {
        val = CSL_REG32_RD(&pRatRegs->EXCEPTION_LOGGING_HEADER0);
        pExceptionInfo->type        = CSL_FEXT(val, RAT_EXCEPTION_LOGGING_HEADER0_TYPE_F);
        pExceptionInfo->destId      = CSL_FEXT(val, RAT_EXCEPTION_LOGGING_HEADER0_DEST_ID);
        pExceptionInfo->srcId       = CSL_FEXT(val, RAT_EXCEPTION_LOGGING_HEADER0_SRC_ID);

        val = CSL_REG32_RD(&pRatRegs->EXCEPTION_LOGGING_HEADER1);
        pExceptionInfo->code        = CSL_FEXT(val, RAT_EXCEPTION_LOGGING_HEADER1_CODE);
        pExceptionInfo->group       = CSL_FEXT(val, RAT_EXCEPTION_LOGGING_HEADER1_GROUP);

        val = CSL_REG32_FEXT(&pRatRegs->EXCEPTION_LOGGING_DATA0, RAT_EXCEPTION_LOGGING_DATA0_ADDR_L);
        val2= CSL_REG32_FEXT(&pRatRegs->EXCEPTION_LOGGING_DATA1, RAT_EXCEPTION_LOGGING_DATA1_ADDR_H);
        pExceptionInfo->address     = (((uint64_t)val2) << 32) | (uint64_t)val;

        val = CSL_REG32_RD(&pRatRegs->EXCEPTION_LOGGING_DATA2);
        pExceptionInfo->routeId     = CSL_FEXT(val, RAT_EXCEPTION_LOGGING_DATA2_ROUTEID);
        pExceptionInfo->privId      = CSL_FEXT(val, RAT_EXCEPTION_LOGGING_DATA2_PRIV_ID);

        pExceptionInfo->bWrite      = (CSL_FEXT(val, RAT_EXCEPTION_LOGGING_DATA2_WRITE) == 0U) ?        (bool)false : (bool)true;
        pExceptionInfo->bRead       = (CSL_FEXT(val, RAT_EXCEPTION_LOGGING_DATA2_READ) == 0U) ?         (bool)false : (bool)true;
        pExceptionInfo->bDebug      = (CSL_FEXT(val, RAT_EXCEPTION_LOGGING_DATA2_DEBUG) == 0U) ?        (bool)false : (bool)true;
        pExceptionInfo->bCacheable  = (CSL_FEXT(val, RAT_EXCEPTION_LOGGING_DATA2_CACHEABLE) == 0U) ?    (bool)false : (bool)true;
        pExceptionInfo->bPriv       = (CSL_FEXT(val, RAT_EXCEPTION_LOGGING_DATA2_PRIV) == 0U) ?         (bool)false : (bool)true;
        pExceptionInfo->bSecure     = (CSL_FEXT(val, RAT_EXCEPTION_LOGGING_DATA2_SECURE) == 0U) ?       (bool)false : (bool)true;

        val = CSL_REG32_RD(&pRatRegs->EXCEPTION_LOGGING_DATA3);
        pExceptionInfo->byteCnt     = CSL_FEXT(val, RAT_EXCEPTION_LOGGING_DATA3_BYTECNT);

        /* Clear the interrupt status bit just to make sure the log is cleared for the next exception */
        retVal = CSL_ratClrIntrPending(pRatRegs, CSL_RAT_INTR_SRC_EXCEPTION);
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
bool CSL_ratEnableRegionTranslation(CSL_ratRegs *pRatRegs, uint32_t regionIndex)
{
    bool retVal = (bool)false;

    if ((pRatRegs != NULL_PTR) && (regionIndex < CSL_ratGetMaxRegions(pRatRegs)))
    {
        CSL_RatTranslationCfgInfo   xlatCfg;
        /*---------------------------------------------------------------------
         * Validate translation configuration parameters
         *-------------------------------------------------------------------*/
        retVal =  CSL_ratGetRegionTranslationConfig(pRatRegs, regionIndex, &xlatCfg);
        if(retVal == (bool)true)
        {
            retVal = CSL_ratValidateTranslationConfig(pRatRegs, regionIndex, &xlatCfg);
            if( retVal == (bool)true)
            {
                retVal = CSL_ratSetRegionTranslationEnable(pRatRegs, regionIndex, (bool)true);
            }
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
bool CSL_ratDisableRegionTranslation(CSL_ratRegs *pRatRegs, uint32_t regionIndex)
{
    bool retVal = (bool)false;

    if ((pRatRegs != NULL_PTR) && (regionIndex < CSL_ratGetMaxRegions(pRatRegs)))
    {
        retVal = CSL_ratSetRegionTranslationEnable(pRatRegs, regionIndex, (bool)false);
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_setup_ctrl
 */
bool CSL_ratConfigRegionTranslation(CSL_ratRegs *pRatRegs, uint32_t regionIndex, CSL_RatTranslationCfgInfo *pTranslationCfg)
{
    bool retVal = (bool)false;

    if ((pRatRegs != NULL_PTR)                         &&
        (regionIndex < CSL_ratGetMaxRegions(pRatRegs)) &&
        (pTranslationCfg != NULL_PTR))
    {
        /*---------------------------------------------------------------------
         * Validate translation configuration parameters
         *-------------------------------------------------------------------*/
        if( CSL_ratValidateTranslationConfig(pRatRegs, regionIndex, pTranslationCfg) == (bool)true )
        {
            /*-----------------------------------------------------------------
             * Write translation configuration parameters into respective
             * registers for this region
             *---------------------------------------------------------------*/
            retVal = CSL_ratDisableRegionTranslation(pRatRegs, regionIndex);
            if (retVal == (bool)true)
            {
                CSL_REG32_WR( &pRatRegs->REGION[regionIndex].CTRL, lmo(pTranslationCfg->sizeInBytes) );
                CSL_REG32_WR( &pRatRegs->REGION[regionIndex].BASE,  pTranslationCfg->baseAddress );
                CSL_REG32_WR( &pRatRegs->REGION[regionIndex].TRANS_L, pTranslationCfg->translatedAddress & 0xFFFFFFFFU );
                CSL_REG32_WR( &pRatRegs->REGION[regionIndex].TRANS_U, (pTranslationCfg->translatedAddress >> 32UL) & 0xFFFFFFFFU );
                /*-----------------------------------------------------------------
                 * Enable the region translation
                 *---------------------------------------------------------------*/
                retVal = CSL_ratEnableRegionTranslation(pRatRegs, regionIndex);
            }
        }
    }
    return retVal;
}

/**
 * Requirement: REQ_TAG(PRSDK-1666)  REQ_TAG(PRSDK-2539)
 * Design: did_csl_core_rat_check
 */
int32_t CSL_ratVerifyConfigRegionTranslation(CSL_ratRegs *pRatRegs, uint32_t regionIndex, CSL_RatTranslationCfgInfo *pTranslationCfg)
{
    bool    retVal;
    int32_t check = CSL_EFAIL;
    uint32_t ctrl, base, trans_l, trans_u;
    uint32_t ctrl_r, base_r, trans_l_r, trans_u_r;

    if ((pRatRegs != NULL_PTR)                         &&
        (regionIndex < CSL_ratGetMaxRegions(pRatRegs)) &&
        (pTranslationCfg != NULL_PTR))
    {
        /*---------------------------------------------------------------------
         * Validate translation configuration parameters
         *-------------------------------------------------------------------*/
        if( CSL_ratValidateTranslationConfig(pRatRegs, regionIndex, pTranslationCfg) == (bool)true )
        {
            {
                ctrl    = lmo(pTranslationCfg->sizeInBytes);
                base    = pTranslationCfg->baseAddress;
                trans_l = (uint32_t) (pTranslationCfg->translatedAddress & 0xFFFFFFFFU);
                trans_u = (uint32_t) ((pTranslationCfg->translatedAddress >> 32UL) & 0xFFFFFFFFU);

                /* read the programmed values */
                ctrl_r = CSL_REG32_FEXT( &pRatRegs->REGION[regionIndex].CTRL, RAT_REGION_CTRL_SIZE );
                base_r = CSL_REG32_FEXT( &pRatRegs->REGION[regionIndex].BASE, RAT_REGION_BASE_BASE);
                trans_l_r = CSL_REG32_FEXT( &pRatRegs->REGION[regionIndex].TRANS_L, RAT_REGION_TRANS_L_LOWER );
                trans_u_r = CSL_REG32_FEXT( &pRatRegs->REGION[regionIndex].TRANS_U, RAT_REGION_TRANS_U_UPPER);

                /*-----------------------------------------------------------------
                 * Check Enable the region translation
                 *---------------------------------------------------------------*/
                retVal = CSL_ratIsRegionTranslationEnabled(pRatRegs, regionIndex);
                if (retVal == (bool)true)
                {
                    if ( (ctrl == ctrl_r) &&
                         (base == base_r) &&
                         (trans_l == trans_l_r) &&
                         (trans_u == trans_u_r) )
                    {
                        check = CSL_PASS;
                    }
                }
            }
        }
    }
    return (check);

}

/* Nothing past this point */
