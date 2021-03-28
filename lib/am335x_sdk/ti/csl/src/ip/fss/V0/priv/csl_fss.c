/**
 * @file  csl_fss.c
 *
 * @brief
 *  Implementation file for the FSS IP module CSL.
 *
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
#include <ti/csl/csl_fss.h>
#include <ti/csl/csl_types.h>
#include <stdbool.h>

#define CSL_FSS_INTR_IS_NOT_PENDING     ((int32_t) 0U)
#define CSL_FSS_INTR_IS_PENDING         ((int32_t) 1U)

/*-----------------------------------------------------------------------------
 *  This structure mirrors the OTFA region configuration registers in the
 *  FSS CSL-RL file. The CSL-RL does not use arrays, so this structure is
 *  provided to make the CSL-FL implementation more straightforward.
 *---------------------------------------------------------------------------*/
typedef struct
{
    volatile uint32_t RGCFG;            /* RegionCfg */
    volatile uint32_t RGMACST;          /* RegionMacStart */
    volatile uint32_t RGST;             /* RegionStart */
    volatile uint32_t RGSI;             /* RegionSize */
    volatile uint32_t RKEYE[8];         /* RegionKeyE */
    volatile uint32_t RKEYEP[8];        /* RegionKeyEP */
    volatile uint32_t RKEYA[4];         /* RegionKeyA */
    volatile uint32_t RKEYAP[4];        /* RegionKeyAP */
    volatile uint32_t RIV[4];           /* RegionIV */
} CSL_fss_fsas_otfa_regionRegs;

/*=============================================================================
 *  Static functions
 *===========================================================================*/
static bool CSL_fssIsValidInterfaceSelect( uint32_t selection );
static bool CSL_fssIsValidPathSelect( uint32_t selection );
static bool CSL_fssIsValidIntrSelect( uint32_t selection );
static bool CSL_fssIsValidRegionSelect( uint32_t selection );
static bool CSL_fssIsValidOutputIntrSelect( uint32_t selection );
static CSL_fss_fsas_otfa_regionRegs *CSL_fssOtfaGetRegionRegs( const CSL_FssCfg *pFssCfg, uint32_t regionNum );
static uint32_t CSL_fssOtfaGetIntrBitMask( uint32_t regionSelect, uint32_t intrSelect );

static bool CSL_fssIsValidInterfaceSelect( uint32_t selection )
{
    bool bIsValid = (bool)true;

#if CSL_FSS_IS_FULL_FEATURED
    if( selection > CSL_FSS_INTERFACE_SELECT_FSS )
#else
    if( selection > CSL_FSS_INTERFACE_SELECT_FSAS )
#endif
    {
        bIsValid = (bool)false;
    }
    return bIsValid;
}

static bool CSL_fssIsValidPathSelect( uint32_t selection )
{
    bool bIsValid = (bool)true;

#if CSL_FSS_IS_FULL_FEATURED
    if( selection > CSL_FSS_FSAS_INTERFACE_PATH_SELECT_HYPERBUS )
#else
    if( selection > CSL_FSS_FSAS_INTERFACE_PATH_SELECT_OSPI0 )
#endif
    {
        bIsValid = (bool)false;
    }
    return bIsValid;
}

static bool CSL_fssIsValidIntrSelect( uint32_t selection )
{
    bool bIsValid = (bool)true;

    if( selection > CSL_FSS_INTERRUPT_SOURCE_SELECT_ECC_WRITE_NONALIGN )
    {
        bIsValid = (bool)false;
    }
    return bIsValid;
}

static bool CSL_fssIsValidRegionSelect( uint32_t selection )
{
    bool bIsValid = (bool)true;

    if( selection >= CSL_FSS_MAX_ECC_PROTECTED_MEMORY_REGIONS )
    {
        bIsValid = (bool)false;
    }
    return bIsValid;
}

static bool CSL_fssIsValidOutputIntrSelect( uint32_t selection )
{
    bool bIsValid = (bool)true;

    if( selection > CSL_FSS_OUTPUT_INTERRUPT_ECC_ERROR )
    {
        bIsValid = (bool)false;
    }
    return bIsValid;
}

static CSL_fss_fsas_otfa_regionRegs *CSL_fssOtfaGetRegionRegs( const CSL_FssCfg *pFssCfg, uint32_t regionNum )
{
    CSL_fss_fsas_otfa_regionRegs *pOtfaRegionRegs;
    switch( regionNum )
    {
        case 0:
            pOtfaRegionRegs = (CSL_fss_fsas_otfa_regionRegs *)((uintptr_t)&pFssCfg->pOtfaRegs->RGCFG0);
            break;
        case 1:
            pOtfaRegionRegs = (CSL_fss_fsas_otfa_regionRegs *)((uintptr_t)&pFssCfg->pOtfaRegs->RGCFG1);
            break;
        case 2:
            pOtfaRegionRegs = (CSL_fss_fsas_otfa_regionRegs *)((uintptr_t)&pFssCfg->pOtfaRegs->RGCFG2);
            break;
        case 3:
            pOtfaRegionRegs = (CSL_fss_fsas_otfa_regionRegs *)((uintptr_t)&pFssCfg->pOtfaRegs->RGCFG3);
            break;
        default:
            pOtfaRegionRegs = NULL;
            break;
    }
    return pOtfaRegionRegs;
}

static uint32_t CSL_fssOtfaGetIntrBitMask( uint32_t regionSelect, uint32_t intrSelect )
{
    uint32_t intrBitMask = ((uint32_t)1U) << ((intrSelect * 4U) + regionSelect);
    return intrBitMask;
}

/*=============================================================================
 *  FSS/FSAS CSL-FL functions
 *===========================================================================*/
int32_t CSL_fssGetRevision( const CSL_FssCfg *pFssCfg, uint32_t *pRev )
{
    int32_t retVal = CSL_PASS;

    if( (pFssCfg == NULL) || (pRev == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        *pRev = CSL_REG32_RD( &pFssCfg->pFssRegs->REVISION );
    }
    return retVal;
}

int32_t CSL_fssSelectInterfacePath( CSL_FssCfg *pFssCfg, uint32_t pathSelect )
{
    int32_t retVal = CSL_PASS;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else if( CSL_fssIsValidPathSelect( pathSelect ) == (bool)true )
    {
#if CSL_FSS_IS_FULL_FEATURED
        CSL_REG32_FINS( &pFssCfg->pFssRegs->SYSCONFIG, FSS_GENREGS_SYSCONFIG_HB_OSPI, pathSelect );
#endif
    }
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;
}

int32_t CSL_fssCfgEcc( CSL_FssCfg *pFssCfg, uint32_t ifSelect, bool bEccEnable, bool bIncludeBlockAddrInEcc )
{
    int32_t retVal = CSL_PASS;
    uint32_t regVal;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
    {
        regVal = CSL_REG32_RD( &pFssCfg->pFsasRegs->SYSCONFIG );
        CSL_FINS( regVal, FSS_FSAS_GENREGS_SYSCONFIG_ECC_EN,          (bEccEnable             == (bool)false) ? (uint32_t)0U : (uint32_t)1U );
        CSL_FINS( regVal, FSS_FSAS_GENREGS_SYSCONFIG_ECC_DISABLE_ADR, (bIncludeBlockAddrInEcc == (bool)false) ? (uint32_t)0U : (uint32_t)1U );
        CSL_REG32_WR( &pFssCfg->pFsasRegs->SYSCONFIG, regVal );
    }
#if CSL_FSS_IS_FULL_FEATURED
    else if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSS )
    {
        regVal = CSL_REG32_RD( &pFssCfg->pFssRegs->SYSCONFIG );
        CSL_FINS( regVal, FSS_GENREGS_SYSCONFIG_ECC_EN,          (bEccEnable             == (bool)false) ? (uint32_t)0U : (uint32_t)1U );
        CSL_FINS( regVal, FSS_GENREGS_SYSCONFIG_ECC_DISABLE_ADR, (bIncludeBlockAddrInEcc == (bool)false) ? (uint32_t)0U : (uint32_t)1U );
        CSL_REG32_WR( &pFssCfg->pFssRegs->SYSCONFIG, regVal );
    }
#endif
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;
}

int32_t CSL_fssCfgHyperBusFragmentation( CSL_FssCfg *pFssCfg, uint32_t fragAddr, bool bFragLo, bool bFragHi )
{
    int32_t retVal = CSL_PASS;
    uint32_t regVal = 0;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        CSL_REG32_FINS( &pFssCfg->pFsasRegs->FRAG_ADR, FSS_FSAS_GENREGS_FRAG_ADR_FRAG_ADDR, fragAddr );

        CSL_FINS( regVal, FSS_FSAS_GENREGS_FRAG_CTL_FRAG_LO, (bFragLo == (bool)false) ? (uint32_t)0U : (uint32_t)1U );
        CSL_FINS( regVal, FSS_FSAS_GENREGS_FRAG_CTL_FRAG_HI, (bFragHi == (bool)false) ? (uint32_t)0U : (uint32_t)1U );
        CSL_REG32_WR( &pFssCfg->pFsasRegs->FRAG_CTL, regVal );
    }
    return retVal;
}

int32_t CSL_fssCfgEccRegion( CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t regionNum, uint32_t regionAddrStart, uint32_t regionSizeBytes )
{
    int32_t retVal = CSL_PASS;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        uint32_t encodedRegionAddrStart, encodedRegionSizeBytes;
        uint64_t regionEnd;

        /* Truncate the regionAddrStart parameter to the required 4Kbyte aligned boundary */
        encodedRegionAddrStart = regionAddrStart & ~0xFFFU;
        /* Round-up the regionSizeBytes parameter to the required 4Kbyte alignment */
        encodedRegionSizeBytes = (regionSizeBytes + 0xFFFU) & ~0xFFFU;
        regionEnd = (uint64_t)encodedRegionAddrStart + (uint64_t)encodedRegionSizeBytes;
        if( regionEnd >= (uint64_t)0x100000000UL )
        {
            retVal = CSL_EINVALID_PARAMS;
        }
        else
        {
            if( (CSL_fssIsValidInterfaceSelect( ifSelect ) == (bool)true) &&
                (CSL_fssIsValidRegionSelect( regionNum ) == (bool)true) )
            {
                /* Encode the region start address and size to 4Kbyte quantities */
                encodedRegionAddrStart >>= 12U;
                encodedRegionSizeBytes >>= 12U;
                if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
                {
                    CSL_REG32_FINS( &pFssCfg->pFsasRegs->ECC_REGCTRL[regionNum].ECC_RGSTRT, FSS_FSAS_GENREGS_ECC_REGCTRL_ECC_RGSTRT_R_START, encodedRegionAddrStart );
                    CSL_REG32_FINS( &pFssCfg->pFsasRegs->ECC_REGCTRL[regionNum].ECC_RGSIZ,  FSS_FSAS_GENREGS_ECC_REGCTRL_ECC_RGSIZ_R_SIZE,   encodedRegionSizeBytes );
                }
#if CSL_FSS_IS_FULL_FEATURED
                else
                {
                    CSL_REG32_FINS( &pFssCfg->pFssRegs->ECC_REGCTRL[regionNum].ECC_RGSTRT, FSS_GENREGS_ECC_REGCTRL_ECC_RGSTRT_R_START, encodedRegionAddrStart );
                    CSL_REG32_FINS( &pFssCfg->pFssRegs->ECC_REGCTRL[regionNum].ECC_RGSIZ,  FSS_GENREGS_ECC_REGCTRL_ECC_RGSIZ_R_SIZE,   encodedRegionSizeBytes );
                }
#endif
            }
            else
            {
                retVal = CSL_EOUT_OF_RANGE;
            }
        }
    }
    return retVal;
}

int32_t CSL_fssSetIntrEnable( CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t intrSelect, bool bEnable )
{
    int32_t retVal = CSL_PASS;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else if( (CSL_fssIsValidInterfaceSelect( ifSelect ) == (bool)true) &&
             (CSL_fssIsValidIntrSelect( intrSelect ) == (bool)true) )
    {
        uint32_t intrBitMask = ((uint32_t)1U) << intrSelect;

        if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
        {
            if( bEnable == (bool)true )
            {
                CSL_REG32_WR( &pFssCfg->pFsasRegs->IRQ.ENABLE_SET, intrBitMask );
            }
            else
            {
                CSL_REG32_WR( &pFssCfg->pFsasRegs->IRQ.ENABLE_CLR, intrBitMask );
            }
        }
#if CSL_FSS_IS_FULL_FEATURED
        else
        {
            if( bEnable == (bool)true )
            {
                CSL_REG32_WR( &pFssCfg->pFssRegs->IRQ.ENABLE_SET, intrBitMask );
            }
            else
            {
                CSL_REG32_WR( &pFssCfg->pFssRegs->IRQ.ENABLE_CLR, intrBitMask );
            }
        }
#endif
    }
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;
}

int32_t CSL_fssSetIntrPendingStatus( CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t intrSelect, bool bPend )
{
    int32_t retVal = CSL_PASS;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else if( (CSL_fssIsValidInterfaceSelect( ifSelect ) == (bool)true) &&
             (CSL_fssIsValidIntrSelect( intrSelect ) == (bool)true) )
    {
        uint32_t intrBitMask = ((uint32_t)1U) << intrSelect;

        if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
        {
            if( bPend == (bool)true )
            {
                CSL_REG32_WR( &pFssCfg->pFsasRegs->IRQ.STATUS_RAW, intrBitMask );
            }
            else
            {
                CSL_REG32_WR( &pFssCfg->pFsasRegs->IRQ.STATUS, intrBitMask );
            }
        }
#if CSL_FSS_IS_FULL_FEATURED
        else
        {
            if( bPend == (bool)true )
            {
                CSL_REG32_WR( &pFssCfg->pFssRegs->IRQ.STATUS_RAW, intrBitMask );
            }
            else
            {
                CSL_REG32_WR( &pFssCfg->pFssRegs->IRQ.STATUS, intrBitMask );
            }
        }
#endif
    }
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;
}

int32_t CSL_fssIsIntrPending( const CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t intrSelect )
{
    int32_t retVal;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else if( (CSL_fssIsValidInterfaceSelect( ifSelect ) == (bool)true) &&
             (CSL_fssIsValidIntrSelect( intrSelect ) == (bool)true) )
    {
        uint32_t regVal, intrBitMask = ((uint32_t)1U) << intrSelect;

        if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
        {
            regVal = CSL_REG32_RD( &pFssCfg->pFsasRegs->IRQ.STATUS );
        }
#if CSL_FSS_IS_FULL_FEATURED
        else
        {
            regVal = CSL_REG32_RD( &pFssCfg->pFssRegs->IRQ.STATUS );
        }
#endif
        if( (regVal & intrBitMask) == 0U )
        {
            retVal = CSL_FSS_INTR_IS_NOT_PENDING;   /* Interrupt is not pending */
        }
        else
        {
            retVal = CSL_FSS_INTR_IS_PENDING;       /* Interrupt is pending */
        }
    }
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;
}

int32_t CSL_fssIsRawIntrPending( const CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t intrSelect )
{
    int32_t retVal;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else if( (CSL_fssIsValidInterfaceSelect( ifSelect ) == (bool)true) &&
             (CSL_fssIsValidIntrSelect( intrSelect ) == (bool)true) )
    {
        uint32_t regVal, intrBitMask = ((uint32_t)1U) << intrSelect;

        if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
        {
            regVal = CSL_REG32_RD( &pFssCfg->pFsasRegs->IRQ.STATUS_RAW );
        }
#if CSL_FSS_IS_FULL_FEATURED
        else
        {
            regVal = CSL_REG32_RD( &pFssCfg->pFssRegs->IRQ.STATUS_RAW );
        }
#endif
        if( (regVal & intrBitMask) == 0U )
        {
            retVal = CSL_FSS_INTR_IS_NOT_PENDING;   /* Interrupt is not pending */
        }
        else
        {
            retVal = CSL_FSS_INTR_IS_PENDING;       /* Interrupt is pending */
        }
    }
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;
}

int32_t CSL_fssAckIntr( CSL_FssCfg *pFssCfg, uint32_t ifSelect, uint32_t outIntrSelect )
{
    int32_t retVal = CSL_PASS;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else if( (CSL_fssIsValidInterfaceSelect( ifSelect ) == (bool)true) &&
             (CSL_fssIsValidOutputIntrSelect( outIntrSelect ) == (bool)true) )
    {
        uint32_t eoiBitNum = ((uint32_t)1U) << outIntrSelect;

        if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
        {
            CSL_REG32_WR( &pFssCfg->pFsasRegs->IRQ.EOI, eoiBitNum );
        }
#if CSL_FSS_IS_FULL_FEATURED
        else
        {
            CSL_REG32_WR( &pFssCfg->pFssRegs->IRQ.EOI, eoiBitNum );
        }
#endif
    }
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;
}

int32_t CSL_fssGetEccBlockErrorInfo( CSL_FssCfg *pFssCfg, uint32_t ifSelect, CSL_FssEccBlockErrorInfo *pEccErrorInfo )
{
    int32_t retVal = CSL_PASS;

    if( (pFssCfg == NULL) || (pEccErrorInfo == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else if( CSL_fssIsValidInterfaceSelect( ifSelect ) == (bool)true )
    {
        uint32_t errorEccType, errorBlockAddr;
        bool bErrValid;

        if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
        {
            errorBlockAddr = CSL_REG32_FEXT( &pFssCfg->pFsasRegs->ERR.ECC_BLOCK_ADR, FSS_FSAS_GENREGS_ERR_ECC_BLOCK_ADR_ECC_ERROR_BLOCK_ADDR );
            errorEccType = CSL_REG32_RD( &pFssCfg->pFsasRegs->ERR.ECC_TYPE );
            bErrValid = (CSL_FEXT( errorEccType, FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_VALID ) == 0U) ? (bool)false : (bool)true;
        }
#if CSL_FSS_IS_FULL_FEATURED
        else
        {
            errorBlockAddr = CSL_REG32_FEXT( &pFssCfg->pFssRegs->ERR.ECC_BLOCK_ADR, FSS_GENREGS_ERR_ECC_BLOCK_ADR_ECC_ERROR_BLOCK_ADDR );
            errorEccType = CSL_REG32_RD( &pFssCfg->pFssRegs->ERR.ECC_TYPE );
            bErrValid = (CSL_FEXT( errorEccType, FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_VALID ) == 0U) ? (bool)false : (bool)true;
        }
#endif
        if( bErrValid == (bool)true )
        {
            pEccErrorInfo->blockAddr = errorBlockAddr;
            /* Field macro values are the same for FSS and FSAS, so we use FSAS names below */
            pEccErrorInfo->addr = CSL_FEXT( errorEccType, FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_ADR );
            pEccErrorInfo->mac = CSL_FEXT( errorEccType, FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_MAC );
            pEccErrorInfo->da1 = CSL_FEXT( errorEccType, FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA1 );
            pEccErrorInfo->da0 = CSL_FEXT( errorEccType, FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DA0 );
            pEccErrorInfo->ded = CSL_FEXT( errorEccType, FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_DED );
            pEccErrorInfo->sec = CSL_FEXT( errorEccType, FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_SEC );
            /* Pop error information off the top of the error stack */
            if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
            {
                CSL_REG32_WR( &pFssCfg->pFsasRegs->ERR.ECC_TYPE, CSL_FMK(FSS_FSAS_GENREGS_ERR_ECC_TYPE_ECC_ERR_VALID, (uint32_t)1U) );
            }
#if CSL_FSS_IS_FULL_FEATURED
            else
            {
                CSL_REG32_WR( &pFssCfg->pFssRegs->ERR.ECC_TYPE, CSL_FMK(FSS_GENREGS_ERR_ECC_TYPE_ECC_ERR_VALID, (uint32_t)1U) );
            }
#endif
        }
        else
        {
            retVal = CSL_EFAIL;     /* No valid error information available */
        }
    }
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;
}

int32_t CSL_fssGetWrErrorInfo( CSL_FssCfg *pFssCfg, uint32_t ifSelect, CSL_FssWrErrorInfo *pWrErrorInfo )
{
    int32_t retVal = CSL_PASS;

    if( (pFssCfg == NULL) || (pWrErrorInfo == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else if( CSL_fssIsValidInterfaceSelect( ifSelect ) == (bool)true )
    {
        uint32_t errorWrType;
        bool bErrValid;

        if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
        {
            errorWrType = CSL_REG32_RD( &pFssCfg->pFsasRegs->ERR.WRT_TYPE );
            bErrValid = (CSL_FEXT( errorWrType, FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_VALID ) == 0U) ? (bool)false : (bool)true;
        }
#if CSL_FSS_IS_FULL_FEATURED
        else
        {
            errorWrType = CSL_REG32_RD( &pFssCfg->pFssRegs->ERR.WRT_TYPE );
            bErrValid = (CSL_FEXT( errorWrType, FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_VALID ) == 0U) ? (bool)false : (bool)true;
        }
#endif
        if( bErrValid == (bool)true )
        {
            /* Field macro values are the same for FSS and FSAS, so we use FSAS names below */
            pWrErrorInfo->routeId       = CSL_FEXT( errorWrType, FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ROUTEID );
            pWrErrorInfo->byteEnable    = CSL_FEXT( errorWrType, FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_BEN );
            pWrErrorInfo->addr          = CSL_FEXT( errorWrType, FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_ADR );
            /* Pop error information off the top of the error stack */
            if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
            {
                CSL_REG32_WR( &pFssCfg->pFsasRegs->ERR.WRT_TYPE, CSL_FMK(FSS_FSAS_GENREGS_ERR_WRT_TYPE_WRT_ERR_VALID, (uint32_t)1U) );
            }
#if CSL_FSS_IS_FULL_FEATURED
            else
            {
                CSL_REG32_WR( &pFssCfg->pFssRegs->ERR.WRT_TYPE, CSL_FMK(FSS_GENREGS_ERR_WRT_TYPE_WRT_ERR_VALID, (uint32_t)1U) );
            }
#endif
        }
        else
        {
            retVal = CSL_EFAIL;     /* No valid error information available */
        }
    }
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;
}

/*=============================================================================
 *  OSPI CSL-FL functions
 *===========================================================================*/
int32_t CSL_fssOspiSetXipPrefetchEnable( CSL_FssCfg *pFssCfg, uint32_t ifSelect, bool bEnable )
{
    int32_t retVal = CSL_PASS;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else if( CSL_fssIsValidInterfaceSelect( ifSelect ) == (bool)true )
    {
#ifdef CSL_FSS_FSAS_GENREGS_SYSCONFIG_DISXIP_MASK
        uint32_t disableXipPrefetch;
        
        disableXipPrefetch = (bEnable == (bool)true) ? (uint32_t)0U : (uint32_t)1U;
        if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
        {
            CSL_REG32_FINS( &pFssCfg->pFsasRegs->SYSCONFIG, FSS_FSAS_GENREGS_SYSCONFIG_DISXIP, disableXipPrefetch );
        }
#if CSL_FSS_IS_FULL_FEATURED
        else
        {
            CSL_REG32_FINS( &pFssCfg->pFssRegs->SYSCONFIG, FSS_GENREGS_SYSCONFIG_DISXIP, disableXipPrefetch );
        }
#endif
#else
        retVal = CSL_EFAIL;
#endif
    }
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;
}

int32_t CSL_fssOspiSetDdrModeEnable( CSL_FssCfg *pFssCfg, uint32_t ifSelect, bool bEnable )
{
    int32_t retVal = CSL_PASS;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else if( CSL_fssIsValidInterfaceSelect( ifSelect ) == (bool)true )
    {
#ifdef CSL_FSS_FSAS_GENREGS_SYSCONFIG_OSPI_DDR_DISABLE_MODE_MASK
        uint32_t disableOspiDdrMode;
        
        disableOspiDdrMode = (bEnable == (bool)true) ? (uint32_t)0U : (uint32_t)1U;
        if( ifSelect == CSL_FSS_INTERFACE_SELECT_FSAS )
        {
            CSL_REG32_FINS( &pFssCfg->pFsasRegs->SYSCONFIG, FSS_FSAS_GENREGS_SYSCONFIG_OSPI_DDR_DISABLE_MODE, disableOspiDdrMode );
        }
#if CSL_FSS_IS_FULL_FEATURED
        else
        {
            CSL_REG32_FINS( &pFssCfg->pFssRegs->SYSCONFIG, FSS_GENREGS_SYSCONFIG_OSPI_DDR_DISABLE_MODE, disableOspiDdrMode );
        }
#endif
#else
        retVal = CSL_EFAIL;
#endif
    }
    else
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    return retVal;    
}

/*=============================================================================
 *  OTFA CSL-FL functions
 *===========================================================================*/
int32_t CSL_fssOtfaGetRevision( const CSL_FssCfg *pFssCfg, uint32_t *pRev )
{
    int32_t retVal = CSL_PASS;

    if( (pFssCfg == NULL) || (pRev == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        *pRev = CSL_REG32_RD( &pFssCfg->pOtfaRegs->REVID );
    }
    return retVal;
}

int32_t CSL_fssOtfaIsCryptoAvailable( const CSL_FssCfg *pFssCfg )
{
    int32_t retVal;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
#if CSL_FSS_IS_FULL_FEATURED
        retVal = (int32_t)CSL_REG32_FEXT( &pFssCfg->pFssRegs->SYSCONFIG, FSS_GENREGS_SYSCONFIG_FSS_AES_EN_IPCFG );
#else
        retVal = (int32_t)CSL_REG32_FEXT( &pFssCfg->pFsasRegs->SYSCONFIG, FSS_FSAS_GENREGS_SYSCONFIG_FSS_AES_EN_IPCFG );
#endif
    }
    return retVal;
}

int32_t CSL_fssOtfaIsBusy( const CSL_FssCfg *pFssCfg )
{
    int32_t retVal;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        retVal = (int32_t)CSL_REG32_FEXT( &pFssCfg->pOtfaRegs->CSTATUS, FSS_FSAS_OTFA_REGS_CSTATUS_BUSY );
    }
    return retVal;
}

int32_t CSL_fssOtfaIsCryptoBusy( const CSL_FssCfg *pFssCfg )
{
    int32_t retVal;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        retVal = (int32_t)CSL_REG32_FEXT( &pFssCfg->pOtfaRegs->CSTATUS, FSS_FSAS_OTFA_REGS_CSTATUS_CRYPTO_BUSY );
    }
    return retVal;
}

int32_t CSL_fssOtfaGetPipeStallEventCnts( CSL_FssCfg *pFssCfg, uint32_t *pRdStallEventCnt, uint32_t *pWrStallEventCnt )
{
    int32_t retVal = CSL_PASS;
    if( (pFssCfg == NULL) || (pFssCfg->pOtfaRegs == NULL) || (pRdStallEventCnt == NULL) || (pWrStallEventCnt == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        uint32_t regVal;
        regVal = CSL_REG32_RD( &pFssCfg->pOtfaRegs->CSTATUS );
        /* Read pipe stall event counters */
        *pRdStallEventCnt = CSL_FEXT( regVal, FSS_FSAS_OTFA_REGS_CSTATUS_RD_STALL_EVENT_CNT );
        *pWrStallEventCnt = CSL_FEXT( regVal, FSS_FSAS_OTFA_REGS_CSTATUS_WRT_STALL_EVENT_CNT );
        /* Clear pipe stall event counters (any write to CSTATUS will clear counters) */
        CSL_REG32_WR( &pFssCfg->pOtfaRegs->CSTATUS, 0x1U );
    }
    return retVal;
}

int32_t CSL_fssOtfaCfgCrypto( CSL_FssCfg *pFssCfg, const CSL_FssOtfaCryptoCfg *pCryptoCfg )
{
    int32_t retVal = CSL_PASS;
    if( (pFssCfg == NULL) || (pFssCfg->pOtfaRegs == NULL) || (pCryptoCfg == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else if( CSL_fssOtfaIsCryptoEnabled( pFssCfg ) == (int32_t)1 )
    {
        retVal = CSL_EFAIL; /* This function must only be called when the crypto engine is disabled */
    }
    else if( (pCryptoCfg->keySize > CSL_FSS_OTFA_KEY_SIZE_256_BITS) ||
             (pCryptoCfg->cryptoCoreAlloc > CSL_FSS_OTFA_CRYPTO_CORE_ALLOCATION_WR_OPTIMIZED) )
    {
        retVal = CSL_EINVALID_PARAMS;
    }
    else
    {
        uint32_t regVal;
        regVal = CSL_REG32_RD( &pFssCfg->pOtfaRegs->CCFG );
        CSL_FINS( regVal, FSS_FSAS_OTFA_REGS_CCFG_KEY_SIZE, pCryptoCfg->keySize );
        CSL_FINS( regVal, FSS_FSAS_OTFA_REGS_CCFG_RD_WRT_OPT, pCryptoCfg->cryptoCoreAlloc );
        CSL_FINS( regVal, FSS_FSAS_OTFA_REGS_CCFG_ERROR_RESP_EN, (pCryptoCfg->bErrRespEnable == (uint32_t)0U) ? (uint32_t)0U : (uint32_t)1U );
        CSL_REG32_WR( &pFssCfg->pOtfaRegs->CCFG, regVal );
        pFssCfg->otfaKeySizeWords = 4U + ((uint32_t)pCryptoCfg->keySize * 4U);  /* Save key size in state */
    }
    return retVal;
}

int32_t CSL_fssOtfaCfgCryptoRegion( CSL_FssCfg *pFssCfg, uint32_t regionNum, const CSL_FssOtfaCryptoRegionCfg *pRegionCfg )
{
    int32_t retVal = CSL_PASS;
    if( (pFssCfg == NULL) || (pFssCfg->pOtfaRegs == NULL) || (pRegionCfg == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else if( regionNum >= CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS )
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    else if( (pFssCfg->otfaKeySizeWords == 0U) ||
             (CSL_fssOtfaIsBusy(pFssCfg) == (int32_t)1) )
    {
        retVal = CSL_EFAIL;
    }
    else
    {
        uint32_t encodedRegionAddrStart, encodedRegionSizeBytes;
        uint64_t regionEnd;

        /* Truncate the regionAddrStart parameter to the required 4Kbyte aligned boundary */
        encodedRegionAddrStart = pRegionCfg->regionAddrStart & ~0xFFFU;
        /* Round-up the regionSizeBytes parameter to the required 4Kbyte alignment */
        encodedRegionSizeBytes = (pRegionCfg->regionSizeBytes + 0xFFFU) & ~0xFFFU;
        regionEnd = (uint64_t)encodedRegionAddrStart + (uint64_t)encodedRegionSizeBytes;
        if( (regionEnd >= (uint64_t)0x100000000UL)                  ||
            (pRegionCfg->macMode > CSL_FSS_OTFA_MAC_MODE_CBC_MAC )  ||
            (pRegionCfg->encMode > CSL_FSS_OTFA_ENC_MODE_AES_ECB )  ||
            ((pRegionCfg->macMode == CSL_FSS_OTFA_MAC_MODE_CBC_MAC) && (pRegionCfg->encMode == CSL_FSS_OTFA_ENC_MODE_DISABLED)) ||
            ((pRegionCfg->macMode == CSL_FSS_OTFA_MAC_MODE_CBC_MAC) && (pRegionCfg->encMode == CSL_FSS_OTFA_ENC_MODE_AES_ECB))  ||
            ((pRegionCfg->macMode == CSL_FSS_OTFA_MAC_MODE_GMAC)    && (pRegionCfg->encMode == CSL_FSS_OTFA_ENC_MODE_AES_ECB))
          )
        {
            retVal = CSL_EINVALID_PARAMS;
        }
        else
        {
            uint32_t regVal, i;
            CSL_fss_fsas_otfa_regionRegs *pOtfaRegionRegs;

            pOtfaRegionRegs = CSL_fssOtfaGetRegionRegs( pFssCfg, regionNum );
            /* RGCFG */
            regVal = CSL_REG32_RD( &pOtfaRegionRegs->RGCFG );
            CSL_FINS( regVal, FSS_FSAS_OTFA_REGS_RGCFG0_WRT_PROTECT0, (pRegionCfg->writeProtect == (uint32_t)0U) ? (uint32_t)0U : (uint32_t)1U );
            CSL_FINS( regVal, FSS_FSAS_OTFA_REGS_RGCFG0_MAC_MODE0,    pRegionCfg->macMode );
            CSL_FINS( regVal, FSS_FSAS_OTFA_REGS_RGCFG0_AES_MODE0,    pRegionCfg->encMode );
            CSL_REG32_WR( &pOtfaRegionRegs->RGCFG, regVal );
            /* RGMACST */
            regVal = pRegionCfg->macSignaturesBaseAddr >> 12U;  /* Encode the base address of the MAC signatures in 4KBytes steps */
            CSL_REG32_WR( &pOtfaRegionRegs->RGMACST, regVal );
            /* RGST */
            regVal = encodedRegionAddrStart >> 12U;     /* Encode the region start address to 4Kbyte quantity */
            CSL_REG32_WR( &pOtfaRegionRegs->RGST, regVal );
            /* RGSI */
            regVal = encodedRegionSizeBytes >> 12U;     /* Encode the region size to 4Kbyte quantity */
            CSL_REG32_WR( &pOtfaRegionRegs->RGSI, regVal );
            /* RKEYE */
            for( i=0; i<pFssCfg->otfaKeySizeWords; i++ )
            {
                CSL_REG32_WR( &pOtfaRegionRegs->RKEYE[i],  pRegionCfg->encKey[i] );
            }
            /* RKEYEP */
            for( i=0; i<pFssCfg->otfaKeySizeWords; i++ )
            {
                CSL_REG32_WR( &pOtfaRegionRegs->RKEYEP[i], pRegionCfg->encPrimeKey[i] );
            }
            /* RKEYA */
            for( i=0; i<4U; i++ )
            {
                CSL_REG32_WR( &pOtfaRegionRegs->RKEYA[i],  pRegionCfg->macKey[i] );
            }
            /* RKEYAP */
            for( i=0; i<4U; i++ )
            {
                CSL_REG32_WR( &pOtfaRegionRegs->RKEYAP[i],  pRegionCfg->macPrimeKey[i] );
            }
            /* RIV */
            for( i=0; i<4U; i++ )
            {
                CSL_REG32_WR( &pOtfaRegionRegs->RIV[i],  pRegionCfg->initializationVector[i] );
            }
        }
    }
    return retVal;
}

int32_t CSL_fssOtfaSetCryptoEnable( CSL_FssCfg *pFssCfg, bool bEnable )
{
    int32_t retVal = CSL_PASS;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        uint32_t fieldVal;
        fieldVal = (bEnable == (bool)false) ? 0U : 1U;
        CSL_REG32_FINS( &pFssCfg->pOtfaRegs->CCFG, FSS_FSAS_OTFA_REGS_CCFG_MASTER_EN_RD, fieldVal );
        /*---------------------------------------------------------------------
         * Wait for the value written to be reflected in the MMR. This prevents
         * an incorrect status to be returned from the
         * CSL_fssOtfaIsCryptoEnabled() function.
         *-------------------------------------------------------------------*/
        while( CSL_REG32_FEXT( &pFssCfg->pOtfaRegs->CCFG, FSS_FSAS_OTFA_REGS_CCFG_MASTER_EN_RD ) != fieldVal )
        {
        }
    }
    return retVal;
}

int32_t CSL_fssOtfaSetCryptoPause( CSL_FssCfg *pFssCfg, bool bPause )
{
    int32_t retVal = CSL_PASS;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        uint32_t fieldVal;
        if( bPause == (bool)false )
        {
            /* Wait de-assertion should only occur when CSTATUS.busy is cleared */
            while( CSL_fssOtfaIsBusy(pFssCfg) == (int32_t)1 ) { }
            fieldVal = 0U;
        }
        else
        {
            fieldVal = 1U;
        }
        CSL_REG32_FINS( &pFssCfg->pOtfaRegs->CCFG, FSS_FSAS_OTFA_REGS_CCFG_OTFA_WAIT, fieldVal );
    }
    return retVal;
}

int32_t CSL_fssOtfaIsCryptoEnabled( const CSL_FssCfg *pFssCfg )
{
    int32_t retVal;

    if( pFssCfg == NULL )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        retVal = (int32_t)CSL_REG32_FEXT( &pFssCfg->pOtfaRegs->CCFG, FSS_FSAS_OTFA_REGS_CCFG_MASTER_EN_RD );
    }
    return retVal;
}

int32_t CSL_fssOtfaSetIntrEnable( CSL_FssCfg *pFssCfg, uint32_t regionSelect, uint32_t intrSelect, bool bEnable )
{
    int32_t retVal = CSL_PASS;

    if( (pFssCfg == NULL) || (pFssCfg->pOtfaRegs == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else if( (regionSelect >= CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS) ||
             (intrSelect   > CSL_FSS_OTFA_INTERRUPT_SOURCE_SELECT_MAC_ERR)
           )
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    else
    {
        uint32_t intrBitMask;
        intrBitMask = CSL_fssOtfaGetIntrBitMask( regionSelect, intrSelect );
        if( bEnable == (bool)false )
        {
            CSL_REG32_WR( &pFssCfg->pOtfaRegs->IEC, intrBitMask );
        }
        else
        {
            CSL_REG32_WR( &pFssCfg->pOtfaRegs->IES, intrBitMask );
        }
    }
    return retVal;
}

int32_t CSL_fssOtfaSetIntrPendingStatus( CSL_FssCfg *pFssCfg, uint32_t regionSelect, uint32_t intrSelect, bool bPend )
{
    int32_t retVal = CSL_PASS;

    if( (pFssCfg == NULL) || (pFssCfg->pOtfaRegs == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else if( (regionSelect >= CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS) ||
             (intrSelect   > CSL_FSS_OTFA_INTERRUPT_SOURCE_SELECT_MAC_ERR)
           )
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    else
    {
        uint32_t intrBitMask;
        intrBitMask = CSL_fssOtfaGetIntrBitMask( regionSelect, intrSelect );
        if( bPend == (bool)false )
        {
            CSL_REG32_WR( &pFssCfg->pOtfaRegs->IS, intrBitMask );
        }
        else
        {
            CSL_REG32_WR( &pFssCfg->pOtfaRegs->ISR, intrBitMask );
        }
    }
    return retVal;
}

int32_t CSL_fssOtfaIsIntrPending( const CSL_FssCfg *pFssCfg, uint32_t regionSelect, uint32_t intrSelect )
{
    int32_t retVal;

    if( (pFssCfg == NULL) || (pFssCfg->pOtfaRegs == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else if( (regionSelect >= CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS) ||
             (intrSelect   > CSL_FSS_OTFA_INTERRUPT_SOURCE_SELECT_MAC_ERR)
           )
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    else
    {
        uint32_t regVal, intrBitMask;
        intrBitMask = CSL_fssOtfaGetIntrBitMask( regionSelect, intrSelect );
        regVal = CSL_REG32_RD( &pFssCfg->pOtfaRegs->IS );
        if( (regVal & intrBitMask) == 0U )
        {
            retVal = (int32_t)0;
        }
        else
        {
            retVal = (int32_t)1;
        }
    }
    return retVal;
}

int32_t CSL_fssOtfaIsRawIntrPending( const CSL_FssCfg *pFssCfg, uint32_t regionSelect, uint32_t intrSelect )
{
    int32_t retVal;

    if( (pFssCfg == NULL) || (pFssCfg->pOtfaRegs == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else if( (regionSelect >= CSL_FSS_OTFA_MAX_PROTECTED_MEMORY_REGIONS) ||
             (intrSelect   > CSL_FSS_OTFA_INTERRUPT_SOURCE_SELECT_MAC_ERR)
           )
    {
        retVal = CSL_EOUT_OF_RANGE;
    }
    else
    {
        uint32_t regVal, intrBitMask;
        intrBitMask = CSL_fssOtfaGetIntrBitMask( regionSelect, intrSelect );
        regVal = CSL_REG32_RD( &pFssCfg->pOtfaRegs->ISR );
        if( (regVal & intrBitMask) == 0U )
        {
            retVal = (int32_t)0;
        }
        else
        {
            retVal = (int32_t)1;
        }
    }
    return retVal;
}

int32_t CSL_fssOtfaGetIrqInfo( const CSL_FssCfg *pFssCfg, CSL_FssOtfaIrqInfo *pIrqInfo )
{
    int32_t retVal = CSL_PASS;

    if( (pFssCfg == NULL) || (pIrqInfo == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        uint32_t regVal;
        pIrqInfo->address   = CSL_REG32_RD( &pFssCfg->pOtfaRegs->IRQADDINFO0 );
        regVal = CSL_REG32_RD( &pFssCfg->pOtfaRegs->IRQADDINFO1 );
        pIrqInfo->length    = CSL_FEXT( regVal, FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MLEN );
        pIrqInfo->seq       = CSL_FEXT( regVal, FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MSEQ );
        pIrqInfo->cmd       = CSL_FEXT( regVal, FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MCMD );
        pIrqInfo->id        = CSL_FEXT( regVal, FSS_FSAS_OTFA_REGS_IRQADDINFO1_IRQ_MID );
    }
    return retVal;
}

int32_t CSL_fssOtfaGetStats( CSL_FssCfg *pFssCfg, CSL_FssOtfaStats *pStats )
{
    int32_t retVal = CSL_PASS;

    if( (pFssCfg == NULL) || (pStats == NULL) )
    {
        retVal = CSL_EBADARGS;
    }
    else
    {
        uint32_t regVal;
        pStats->cacheMissCnt    = CSL_REG32_FEXT( &pFssCfg->pOtfaRegs->MACCACHEINFO, FSS_FSAS_OTFA_REGS_MACCACHEINFO_CACHE_MISS_EVENT_CNT );
        CSL_REG32_WR( &pFssCfg->pOtfaRegs->MACCACHEINFO, 1U );  /* Clear counter */
        regVal = CSL_REG32_RD( &pFssCfg->pOtfaRegs->RMWRMCNT );
        CSL_REG32_WR( &pFssCfg->pOtfaRegs->RMWRMCNT, 1U );      /* Clear counters */
        pStats->rmEventCnt      = CSL_FEXT( regVal, FSS_FSAS_OTFA_REGS_RMWRMCNT_RM_EVENT_CNT );
        pStats->rmwEventCnt     = CSL_FEXT( regVal, FSS_FSAS_OTFA_REGS_RMWRMCNT_RMW_EVENT_CNT );
    }
    return retVal;
}
