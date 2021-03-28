/**
 * @file  csl_emif.c
 *
 * @brief
 *  C implementation file for the EMIF module CSL-FL.
 *
 *  Contains the different control command and status query functions definitions
 *
 *  \par
 *  ============================================================================
 *  @n   (C) Copyright 2015-2018, Texas Instruments, Inc.
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
#include <ti/csl/cslr_emif.h>
#include <ti/csl/csl_emif.h>

#ifndef CSL_EMIF_FAST_SIM
#define CSL_EMIF_FAST_SIM       (1)
#endif

#define CSL_EMIF_UNDEFINED      ((uint8_t)-1)

#define CSL_EMIF_PHYCFG_DXnGCR0(base,n)     ((base)+ CSL_EMIF_PHYCFG_DX0GCR0+(uint32_t)(n*0x100U))
#define CSL_EMIF_PHYCFG_DXnGCR1(base,n)     ((base)+ CSL_EMIF_PHYCFG_DX0GCR1+(uint32_t)(n*0x100U))
#define CSL_EMIF_PHYCFG_DXnGCR2(base,n)     ((base)+ CSL_EMIF_PHYCFG_DX0GCR2+(uint32_t)(n*0x100U))
#define CSL_EMIF_PHYCFG_DXnGCR3(base,n)     ((base)+ CSL_EMIF_PHYCFG_DX0GCR3+(uint32_t)(n*0x100U))
#define CSL_EMIF_PHYCFG_DXnGTR0(base,n)     ((base)+ CSL_EMIF_PHYCFG_DX0GTR0+(uint32_t)(n*0x100U))
#define CSL_EMIF_PHYCFG_DX8SLnIOCR(base,n)  ((base)+ CSL_EMIF_PHYCFG_DX8SL0IOCR+(uint32_t)(n*0x040U))
#define CSL_EMIF_PHYCFG_DX8SLnDQSCTL(base,n)    ((base)+ CSL_EMIF_PHYCFG_DX8SL0DQSCTL + (uint32_t)(n*0x040U))
#define CSL_EMIF_PHYCFG_DXnRSRx(base,n,x)   ((base)+ CSL_EMIF_PHYCFG_DX0RSR0+(uint32_t)(n*0x100U)+(uint32_t)(x*0x004U))

#define CSL_EMIF_FREQ_MODE_ADJUST(v)        (((v)+1U)/2U)
#define CSL_EMIF_NS_TO_CLKS(tns,clkmhz)     ((tns)*(clkmhz)/1000U)
#define CSL_EMIF_CLKS_TO_NS(clks,clkmhz)    ((clks)*1000)/(clkmhz))

#define CSL_EMIF_CTLCFG_STAT_SELFREF_TYPE_NOT_IN_SELFREF    (0U)
#define CSL_EMIF_CTLCFG_STAT_SELFREF_TYPE_PHY_MSTR_SELFREF  (1U)
#define CSL_EMIF_CTLCFG_STAT_SELFREF_TYPE_NON_AUTO_SELFREF  (2U)
#define CSL_EMIF_CTLCFG_STAT_SELFREF_TYPE_AUTO_SELFREF      (3U)

#if CSL_EMIF_FAST_SIM == 0
/* Timing values:                  DDR3 LPDDR2 LPDDR3   DDR4 LPDDR4 */
static uint32_t tDINIT0us[5] = {    500,     0,   200,   500,  2000 };
static uint32_t tDINIT1ns[5] = {    500,     0,   100,   500,  2000 };
static uint32_t tDINIT2us[5] = {    200,     0,    11,   200,   200 };
#endif

#define CSL_EMIF_DWC_PIPE_PHY2DFI    (1U)
#define CSL_EMIF_DWC_PIPE_DFI2PHY    (1U)
#define CSL_EMIF_DWC_PIPE_MCTL2DFI   (1U)
#define CSL_EMIF_DWC_PIPE_DFI2MCTL   (1U)
#define CSL_EMIF_DWC_PIPE_DFI2PUB    (1U)

/* All timings in picoseconds (ps) */
typedef struct
{
    uint32_t tCK;
    uint32_t tDQSCKmin;
    uint32_t tDQSCK;
    uint32_t writeLatency;
    uint32_t readLatency;
    uint32_t tphyWrdata;
    uint32_t tphyWrlat;
    uint32_t tphyWrcslat;
    uint32_t trddataEn;
    uint32_t tphyRdcslat;
    uint32_t tctrlDelay;
    uint32_t twrdataDelay;
    uint32_t tDramClkDisable;
    uint32_t tDramClkEnable;
    uint32_t tphyRdlat;
} CSL_EmifSdramTimings;

static CSL_EmifSdramTimings sdramTimings;

/*=============================================================================
 *  Internal function Prototype
 *===========================================================================*/
static uint32_t max( uint32_t a, uint32_t b );
static uint32_t CSL_emifEncodeDDR3CasLatency( uint32_t casLatency);
static uint32_t CSL_emifEncodeDDR3CasWriteLatency( uint32_t writeLatency);
static uint32_t CSL_encodeLPDDR4ReadLatency( uint32_t readLatency );
static uint32_t CSL_encodeLPDDR4WriteLatency( uint32_t writeLatency );
static uint32_t CSL_emifEncodeDDR4CasLatency( uint32_t casLatency);
static uint32_t CSL_emifEncodeDDR4WriteRecoveryToPrecharge( CSL_EmifConfig *pCfg);
static void CSL_emifToggleDqsEnable( CSL_EmifConfig *pCfg, uint_fast8_t dqsIndex, bool bEnable );
static uint32_t CSL_emifEncodeDDR4CasWriteLatency( uint32_t casWriteLatency);
static uint32_t CSL_emifGetDataBusWidthMode( CSL_EmifConfig *pCfg);
static uint32_t CSL_emifGetNumPhyDataMacros( CSL_EmifConfig *pCfg );
static uint32_t CSL_emifGetRequiredPhyDataMacrosMask( CSL_EmifConfig *pCfg );
static void CSL_emifConfigForceMemoryEccError( CSL_EmifConfig *pCfg );
static void CSL_emifCalcSdramTimings( CSL_EmifConfig *pCfg, CSL_EmifSdramTimings *pSdramTimings);
static uint32_t makeBitmask( uint32_t lsb, uint32_t msb);
static uint32_t numBits( uint32_t v );
static void CSL_emifCfgSdramAddrMapping( CSL_EmifConfig *pCfg);
static void CSL_emifConfigController( CSL_EmifConfig *pCfg, CSL_EmifSdramTimings *pSdramTimings);
static void CSL_emifConfigPhyModeRegs( CSL_EmifConfig *pCfg, CSL_EmifSdramTimings *pSdramTimings);
static void CSL_emifConfigPhyIOCRRegs( CSL_EmifConfig *pCfg );
static void CSL_emifConfigDqsResistors( CSL_EmifConfig *pCfg, uint32_t bEnable );
static void CSL_emifSelectRank( CSL_EmifConfig *pCfg, uint_least32_t RankId);
static void CSL_emifConfigDqsRegisters( CSL_EmifConfig *pCfg);
static void CSL_emifCfgPllFreqSel( CSL_EmifConfig *pCfg);
static void CSL_emifConfigPhy( CSL_EmifConfig *pCfg, CSL_EmifSdramTimings *pSdramTimings);
static void CSL_emifToggleCoreResetAssert( CSL_EmifConfig *pCfg, bool bVal);
static void CSL_emifAssertCoreReset( CSL_EmifConfig *pCfg);
static void CSL_emifDeassertCoreReset( CSL_EmifConfig *pCfg);
static bool CSL_emifIsControllerIdle( CSL_EmifConfig *pCfg);
static bool CSL_emifIsDataPipelineEmpty( CSL_EmifConfig *pCfg);
static void CSL_emifToggleAutoRefreshDisable(CSL_EmifConfig *pCfg, bool bVal);
static void CSL_emifDisableAutoRefresh( CSL_EmifConfig *pCfg);
static void CSL_emifEnableAutoRefresh( CSL_EmifConfig *pCfg);
static bool CSL_emifIsSwDone( CSL_EmifConfig *pCfg);
static void CSL_emifToggleSwDone( CSL_EmifConfig *pCfg, bool bVal);
static void CSL_emifStartSwProgramming( CSL_EmifConfig *pCfg);
static void CSL_emifEndSwProgramming( CSL_EmifConfig *pCfg);
static void CSL_emifToggleHifEnable( CSL_EmifConfig *pCfg, bool bEnable);
static void CSL_emifInitiateQuasiDynamicWrite( CSL_EmifConfig *pCfg, uint32_t group );
static void CSL_emifTerminateQuasiDynamicWrite( CSL_EmifConfig *pCfg, uint32_t group );
static void CSL_emifStartPhyInit( CSL_EmifConfig *pCfg, uint32_t phyInitFlags);
static uint32_t CSL_emifGetPhyStatus( CSL_EmifConfig *pCfg );
static bool CSL_emifIsPhyStatusSet( CSL_EmifConfig *pCfg, uint32_t phyStatusMask );
static void CSL_emifGetSetBitPositions( uint32_t bitMask, uint8_t bitPos[] );
static bool CSL_emifAreBitsContiguous(uint8_t bitPos[], uint8_t lsb, uint8_t msb);
static int32_t CSL_emifDoPhyInit( CSL_EmifConfig *pCfg );
static void CSL_emifDoSdramInit( CSL_EmifConfig *pCfg );
static int32_t CSL_emifDoDataTraining( CSL_EmifConfig *pCfg );
static void CSL_emifToggleSelfRefreshSwEnable( CSL_EmifConfig *pCfg, bool bVal);
static bool CSL_emifIsEmifConfigValid( CSL_EmifConfig *pCfg );
static void CSL_emifConfigSubsystem( CSL_EmifConfig *pCfg );
static void CSL_emifWaitForPhyInitDone( CSL_EmifConfig *pCfg, uint32_t doneMask );
static int32_t CSL_emifLpddr4Boot( CSL_EmifConfig *pCfg );

/*=============================================================================
 *  Internal functions
 *===========================================================================*/
static uint32_t max( uint32_t a, uint32_t b )
{
    uint32_t maxVal;

    if( a > b )
        { maxVal = a; }
    else
        { maxVal = b; }
    return maxVal;
}

static uint32_t CSL_emifEncodeDDR3CasLatency(uint32_t casLatency)
{
    uint32_t encodedCasLatency;

    if( casLatency < 5U )
        { encodedCasLatency = (5U-4U); }
    else if( casLatency > 14U )
        { encodedCasLatency = (14U-4U); }
    else
        { encodedCasLatency = casLatency - 4U; }
    return encodedCasLatency;
}

static uint32_t CSL_emifEncodeDDR3CasWriteLatency(uint32_t writeLatency)
{
    uint32_t encodedWriteLatency;

    if( writeLatency < 5U )
        { encodedWriteLatency = (5U-5U); }
    else if( writeLatency > 12U )
        { encodedWriteLatency = (12U-5U); }
    else
        { encodedWriteLatency = writeLatency - 5U; }
    return encodedWriteLatency;
}

static uint32_t CSL_encodeLPDDR4ReadLatency( uint32_t readLatency )
{
    uint32_t encodedReadLatency;

    if( readLatency <= 9U )
        { encodedReadLatency = 0; }
    else if( readLatency <= 13U )
        { encodedReadLatency = 1U; }
    else if( readLatency <= 19U )
        { encodedReadLatency = 2U; }
    else if( readLatency <= 23U )
        { encodedReadLatency = 3U; }
    else if( readLatency <= 27U )
        { encodedReadLatency = 4U; }
    else if( readLatency <= 31U )
        { encodedReadLatency = 5U; }
    else if( readLatency <= 35U )
        { encodedReadLatency = 6U; }
    else
        { encodedReadLatency = 7U; }
    return encodedReadLatency;
}

static uint32_t CSL_encodeLPDDR4WriteLatency( uint32_t writeLatency )
{
    return ((writeLatency >> 1) - 2U) & 0x7U;
}

#define CSL_EMIF_DDR4_CAS_LATENCY_MIN   (9U)
#define CSL_EMIF_DDR4_CAS_LATENCY_MAX   (32U)

static uint32_t CSL_emifEncodeDDR4CasLatency(uint32_t casLatency)
{
    static uint32_t encodedCasLatency[] = {0,1,2,3,4,5,6,7,13,8,14,9,15,10,12,11,16,17,18,19,20,21,22,23};
    uint32_t casLatencyIdx;

    if( casLatency < CSL_EMIF_DDR4_CAS_LATENCY_MIN )
    {
        casLatencyIdx = 0;
    }
    else if( casLatency > CSL_EMIF_DDR4_CAS_LATENCY_MAX )
    {
        casLatencyIdx = CSL_EMIF_DDR4_CAS_LATENCY_MAX - CSL_EMIF_DDR4_CAS_LATENCY_MIN;
    }
    else
    {
        casLatencyIdx = casLatency - CSL_EMIF_DDR4_CAS_LATENCY_MIN;
    }
    return encodedCasLatency[casLatencyIdx];
}

static uint32_t CSL_emifEncodeDDR4WriteRecoveryToPrecharge(CSL_EmifConfig *pCfg)
{
    uint32_t     encodedWr;
    uint32_t    tWRnsec = 15U;
    uint32_t    wr;

    wr = ((tWRnsec * pCfg->sdramClkFreqMHz) + (1000U-1U)) / 1000U;
    if( wr <= 10U )
        { encodedWr = 0U; }
    else if( wr <= 12U )
        { encodedWr = 1U; }
    else if( wr <= 14U )
        { encodedWr = 2U; }
    else if( wr <= 16U )
        { encodedWr = 3U; }
    else if( wr <= 18U )
        { encodedWr = 4U; }
    else if( wr <= 20U )
        { encodedWr = 5U; }
    else if( wr <= 22U )
        { encodedWr = 7U; }
    else if( wr <= 24U )
        { encodedWr = 6U; }
    else
        { encodedWr = 8U; }
    return encodedWr;
}

static uint32_t CSL_emifEncodeDDR4CasWriteLatency(uint32_t casWriteLatency)
{
    uint32_t encodedCasWriteLatency;

    if( casWriteLatency <= 9U )
        { encodedCasWriteLatency = 0U; }
    else if( casWriteLatency == 10U )
        { encodedCasWriteLatency = 1U; }
    else if( casWriteLatency == 11U )
        { encodedCasWriteLatency = 2U; }
    else if( casWriteLatency == 12U )
        { encodedCasWriteLatency = 3U; }
    else if( casWriteLatency <= 14U )
        { encodedCasWriteLatency = 4U; }
    else if( casWriteLatency <= 16U )
        { encodedCasWriteLatency = 5U; }
    else if( casWriteLatency <= 18U )
        { encodedCasWriteLatency = 6U; }
    else
        { encodedCasWriteLatency = 7U; }
    return encodedCasWriteLatency;
}

static uint32_t CSL_emifGetDataBusWidthMode(CSL_EmifConfig *pCfg)
{
    uint32_t dataBusWidthMode;

    if( pCfg->pSdramParms->sdramDataWidth == pCfg->memcDramDataWidthBits )
        { dataBusWidthMode = 0; }           /* Full-width mode  */
    else if( pCfg->pSdramParms->sdramDataWidth == (pCfg->memcDramDataWidthBits/2U) )
        { dataBusWidthMode = 1U; }          /* Half-width mode  */
    else if( pCfg->pSdramParms->sdramDataWidth == (pCfg->memcDramDataWidthBits/4U) )
        { dataBusWidthMode = 2U; }          /* Quarter-width mode  */
    else
        { dataBusWidthMode = 0; }
    return dataBusWidthMode;
}

static uint32_t CSL_emifGetNumPhyDataMacros( CSL_EmifConfig *pCfg )
{
    return ((uint32_t)pCfg->memcDramDataWidthBits / 8U ) + 1U;
}

static uint32_t CSL_emifGetRequiredPhyDataMacrosMask( CSL_EmifConfig *pCfg )
{
    uint32_t    mask = 0;

    mask = ( (uint32_t)1U << ( pCfg->pSdramParms->sdramDataWidth / 8U ) ) - 1U;
    if( pCfg->bEnableMemoryECC == (bool)true )
    {
        /*---------------------------------------------------------------------
         *  For ddr39ss half-width LPDDR4 with ECC, data macro 2 is used for
         *  training and data macro 3 is used for ECC
         *-------------------------------------------------------------------*/
        if( ( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4 )                   &&
            ( pCfg->pSdramParms->sdramDataWidth == (pCfg->memcDramDataWidthBits/2U) )   &&
            ( pCfg->memcDramDataWidthBits == 32U ) )
        {
            mask |= ((1U<<3U) | (1U<<2U));
        }
        /*---------------------------------------------------------------------
         *  Otherwise, ECC byte lane uses last data macro
         *-------------------------------------------------------------------*/
        else
        {
            mask |= ( (uint32_t)1U << ( pCfg->memcDramDataWidthBits / 8U ) );
        }
    }
    return mask;
}

static void CSL_emifConfigForceMemoryEccError( CSL_EmifConfig *pCfg )
{
    CSL_EmifForceMemEccErrorCfg *pForceEccCfg = pCfg->pForceMemEccErrorCfg;

    /* For MEMC_BURST_LENGTH = 16, Full-width mode: col[3:0]=0, half-width mode: col[4:0]=0, quarter-width mode: col[5:0]=0 */
    pForceEccCfg->colAddr &= ~((1U<<(CSL_emifGetDataBusWidthMode(pCfg)+4U)) - 1U);

    CSL_REG32_WR( &pCfg->pEmifCtlRegs->ECCPOISONADDR0,
        CSL_FMK( EMIF_CTLCFG_ECCPOISONADDR0_ECC_POISON_COL,  (uint32_t)pForceEccCfg->colAddr )         |
        CSL_FMK( EMIF_CTLCFG_ECCPOISONADDR0_ECC_POISON_RANK, (uint32_t)pForceEccCfg->rankAddr ) );
    CSL_REG32_WR( &pCfg->pEmifCtlRegs->ECCPOISONADDR1,
        CSL_FMK( EMIF_CTLCFG_ECCPOISONADDR1_ECC_POISON_ROW,  (uint32_t)pForceEccCfg->rowAddr )         |
        CSL_FMK( EMIF_CTLCFG_ECCPOISONADDR1_ECC_POISON_BANK, (uint32_t)pForceEccCfg->bankAddr )        |
        CSL_FMK( EMIF_CTLCFG_ECCPOISONADDR1_ECC_POISON_BG,   (uint32_t)pForceEccCfg->bankGroupAddr ) );
}

static void CSL_emifCalcSdramTimings(CSL_EmifConfig *pCfg, CSL_EmifSdramTimings *pSdramTimings)
{
    pSdramTimings->tCK = 1000000U / pCfg->sdramClkFreqMHz;
    if( (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_DDR3) ||
        (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_DDR4) )
    {
        pSdramTimings->tDQSCK          = 0;
        pSdramTimings->writeLatency    = (uint32_t)pCfg->pSdramParms->casWriteLatency + (uint32_t)pCfg->pSdramParms->additionalLatency;
        pSdramTimings->readLatency     = (uint32_t)pCfg->pSdramParms->casLatency + (uint32_t)pCfg->pSdramParms->additionalLatency;
    }
    else if( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4 )
    {
        pSdramTimings->tDQSCKmin = 1500;
        /*---------------------------------------------------------------------
         *  For LPDDR3 or LPDDR4 operation with gate training enabled...
         *  a) for operation below 1600 Mbps, set this to 1
         *  b) for operation at or above 1600 Mbps, set this to (tDQSCKmin/tCK)
         *     rounded down to the nearest whole number
         *-------------------------------------------------------------------*/
        if( pCfg->sdramClkFreqMHz < 800U )
        {
            pSdramTimings->tDQSCK          = 1;
        } else
        {
            pSdramTimings->tDQSCK          = pSdramTimings->tDQSCKmin / pSdramTimings->tCK;
        }
        pSdramTimings->writeLatency    = pCfg->pSdramParms->casWriteLatency + (uint32_t)1U;
        pSdramTimings->readLatency     = pCfg->pSdramParms->casLatency + pSdramTimings->tDQSCK;
    }
    else
    {
         /* No action required */
    }
    pSdramTimings->tphyWrdata      = 2U;
    pSdramTimings->tphyWrlat       = pSdramTimings->writeLatency - 3U;
    pSdramTimings->tphyWrcslat     = pSdramTimings->tphyWrlat - 2U;
    pSdramTimings->trddataEn       = pSdramTimings->readLatency - 4U;
    pSdramTimings->tphyRdcslat     = pSdramTimings->trddataEn - 2U;
    pSdramTimings->tctrlDelay      = 2U + CSL_EMIF_DWC_PIPE_DFI2PHY + CSL_EMIF_DWC_PIPE_MCTL2DFI;
    pSdramTimings->twrdataDelay    = 5U + CSL_EMIF_DWC_PIPE_DFI2PHY + CSL_EMIF_DWC_PIPE_MCTL2DFI + ((uint32_t)pCfg->pSdramParms->burstLength/4U);
    pSdramTimings->tDramClkDisable = 1U + CSL_EMIF_DWC_PIPE_DFI2PHY + CSL_EMIF_DWC_PIPE_MCTL2DFI;
    pSdramTimings->tDramClkEnable  = 1U + CSL_EMIF_DWC_PIPE_DFI2PHY + CSL_EMIF_DWC_PIPE_MCTL2DFI;
    pSdramTimings->tphyRdlat       = 18U+ (2U*(CSL_EMIF_DWC_PIPE_PHY2DFI+CSL_EMIF_DWC_PIPE_DFI2PHY+CSL_EMIF_DWC_PIPE_MCTL2DFI+CSL_EMIF_DWC_PIPE_DFI2MCTL));
}

/*=============================================================================
 *  This internal function configures the default SDRAM address mapping.
 *
 *  For DDR3 and LPDDR4, the mapping places the following address bits from
 *  lsb to msb SDRAM bit order:
 *      - Column bits
 *      - Bank bits
 *      - Rank bits
 *      - Row bits
 *
 *      For example, assuming numColBits=11 and numRowBits=16, the following
 *      mapping would be configured for DDR3 or LPDDR4:
 *
 *      ----------------------------------------------------------------------------------------------------------------------
 *      VBUSMC (72-bit): 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
 *      VBUSMC (39-bit): 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
 *      VBUSMC (22-bit): 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
 *      HIF addr bit:    30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
 *      DDR3 addr map:  |15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00|00|02 01 00|10 09 08 07 06 05 04 03 02 01 00|
 *                      |                row bits                       |rk|bankbits|       column bits              |
 *      ----------------------------------------------------------------------------------------------------------------------
 *
 *  For DDR4, the mapping places the following address bits from
 *  lsb to msb SDRAM bit order:
 *      - Column bits
 *      - Bank bits
 *      - Bank group bits
 *      - Rank bits
 *      - Row bits
 *
 *      For example, assuming numColBits=11 and numRowBits=16, the following
 *      mapping would be configured for DDR4:
 *
 *      -------------------------------------------------------------------------------------------------------------------------
 *      VBUSMC (72-bit): 34 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
 *      VBUSMC (39-bit): 33 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
 *      VBUSMC (22-bit): 32 31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
 *      HIF addr bit:    31 30 29 28 27 26 25 24 23 22 21 20 19 18 17 16 15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00
 *      DDR3 addr map:  |15 14 13 12 11 10 09 08 07 06 05 04 03 02 01 00|00|01 00|01 00|10 09 08 07 06 05 04 03 02 01 00|
 *                      |                   row bits                    |rk| bg  |bank |       column bits              |
 *      -------------------------------------------------------------------------------------------------------------------------
 *===========================================================================*/
static uint32_t makeBitmask(uint32_t lsb, uint32_t msb)
{
    return (((uint32_t)1U<<((msb-lsb)+1U))-1U) << lsb;
}

static uint32_t numBits( uint32_t v )
{
  uint32_t b=0;

  if( v != 0U )
  {
    uint32_t vLocal = v - 1U;
    do {
        vLocal >>= 1;
        if( vLocal != 0U )
        {
            b++;
        }
    } while( vLocal != 0U );
    b++;
  }
  return b;
}

static void CSL_emifCfgSdramAddrMapping(CSL_EmifConfig *pCfg)
{
    uint32_t startBitNum, endBitNum;

    /* Column bits */
    startBitNum = 0;
    endBitNum   = startBitNum + pCfg->pSdramParms->numColBits - 1U;
    CSL_emifMapSdramAddrBits(pCfg, CSL_EMIF_SDRAM_ADDR_BITS_COLUMN,  makeBitmask(startBitNum, endBitNum) );
    /* Bank bits */
    startBitNum = endBitNum + 1U;
    endBitNum   = startBitNum + numBits(pCfg->pSdramParms->numBanks) - 1U;
    CSL_emifMapSdramAddrBits(pCfg, CSL_EMIF_SDRAM_ADDR_BITS_BANK,    makeBitmask(startBitNum, endBitNum) );
    /* Group bits (not used for DDR3 or LPDDR4) */
    if( (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_DDR3)       ||
        (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4) )
    {
        CSL_emifMapSdramAddrBits(pCfg, CSL_EMIF_SDRAM_ADDR_BITS_GROUP,   0 );
    }
    else
    {
        startBitNum = endBitNum + 1U;
        endBitNum   = startBitNum + numBits(pCfg->pSdramParms->numBankGroups) - 1U;
        CSL_emifMapSdramAddrBits(pCfg, CSL_EMIF_SDRAM_ADDR_BITS_GROUP,    makeBitmask(startBitNum, endBitNum) );
    }
    /* Rank bits */
    startBitNum = endBitNum + 1U;
    endBitNum   = startBitNum + numBits(pCfg->pSdramParms->numRanks) - 1U;
    CSL_emifMapSdramAddrBits(pCfg, CSL_EMIF_SDRAM_ADDR_BITS_RANK,    makeBitmask(startBitNum, endBitNum) );
    /* Row bits */
    startBitNum = endBitNum + 1U;
    endBitNum   = startBitNum + pCfg->pSdramParms->numRowBits - 1U;
    CSL_emifMapSdramAddrBits(pCfg, CSL_EMIF_SDRAM_ADDR_BITS_ROW,     makeBitmask(startBitNum, endBitNum) );
}

/*=============================================================================
 *  This internal function minimally configures the Synopsys Enhanced Universal
 *  DDR Memory Controller (uMCTL2). It then calls a user-provided function (if
 *  specified) that performs additional configurations.
 *===========================================================================*/
static void CSL_emifConfigController(CSL_EmifConfig *pCfg, CSL_EmifSdramTimings *pSdramTimings)
{
    uint32_t    regVal;

    /*-------------------------------------------------------------------------
     *  Configure MSTR
     *-----------------------------------------------------------------------*/
    regVal =
        CSL_FMK( EMIF_CTLCFG_MSTR_DDR3,   (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_DDR3) ?   (uint32_t)1U : (uint32_t)0U )     |
        CSL_FMK( EMIF_CTLCFG_MSTR_LPDDR2, (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR2) ? (uint32_t)1U : (uint32_t)0U )     |
        CSL_FMK( EMIF_CTLCFG_MSTR_LPDDR3, (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR3) ? (uint32_t)1U : (uint32_t)0U )     |
        CSL_FMK( EMIF_CTLCFG_MSTR_DDR4,   (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_DDR4) ?   (uint32_t)1U : (uint32_t)0U )     |
        CSL_FMK( EMIF_CTLCFG_MSTR_LPDDR4, (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4) ? (uint32_t)1U : (uint32_t)0U )     |
        CSL_FMK( EMIF_CTLCFG_MSTR_BURST_MODE, (uint32_t)0 )                                                                         |
        CSL_FMK( EMIF_CTLCFG_MSTR_BURSTCHOP, (uint32_t)0 )                                                                          |
        CSL_FMK( EMIF_CTLCFG_MSTR_EN_2T_TIMING_MODE, (uint32_t)0 )                                                                  |
        CSL_FMK( EMIF_CTLCFG_MSTR_GEARDOWN_MODE, (uint32_t)0 )                                                                      |
        CSL_FMK( EMIF_CTLCFG_MSTR_DATA_BUS_WIDTH, (uint32_t)CSL_emifGetDataBusWidthMode(pCfg) )                                     |
        CSL_FMK( EMIF_CTLCFG_MSTR_DLL_OFF_MODE, (uint32_t)0 )                                                                       |
        CSL_FMK( EMIF_CTLCFG_MSTR_BURST_RDWR, (uint32_t)(pCfg->pSdramParms->burstLength)/2U )                                       |
        CSL_FMK( EMIF_CTLCFG_MSTR_ACTIVE_RANKS, (((uint32_t)1U<<(pCfg->pSdramParms->numRanks))-1U) )                                    |
        CSL_FMK( EMIF_CTLCFG_MSTR_FREQUENCY_MODE, (uint32_t)0 )                                                                     |
        CSL_FMK( EMIF_CTLCFG_MSTR_DEVICE_CONFIG, pCfg->pSdramParms->config ) ;
    CSL_REG32_WR( &pCfg->pEmifCtlRegs->MSTR, regVal );
    /*-------------------------------------------------------------------------
     *  Configure ECC related registers
     *-----------------------------------------------------------------------*/
    if( pCfg->bEnableMemoryECC == (bool)true )
    {
        /* dis_scrub=1, test_mode=0, ecc_mode=4 */
        regVal =
            CSL_FMK( EMIF_CTLCFG_ECCCFG0_DIS_SCRUB, 1U )          |
            CSL_FMK( EMIF_CTLCFG_ECCCFG0_ECC_MODE, 0x4U ) ;
        CSL_REG32_WR( &pCfg->pEmifCtlRegs->ECCCFG0, regVal );
    }
    else
    {
        /* dis_scrub=1, test_mode=0, ecc_mode=0 */
        CSL_REG32_WR( &pCfg->pEmifCtlRegs->ECCCFG0, CSL_FMK( EMIF_CTLCFG_ECCCFG0_DIS_SCRUB, 1U ) );
    }
    if( pCfg->pForceMemEccErrorCfg != (void *)0 )
    {
        CSL_emifConfigForceMemoryEccError( pCfg );
    }

    /* SDRAM Intialization routine is skipped after power-up. Controller starts up in Normal Mode */
    CSL_REG32_FINS( &pCfg->pEmifCtlRegs->INIT0, EMIF_CTLCFG_INIT0_SKIP_DRAM_INIT, 1 );
    /*-------------------------------------------------------------------------
     *  Reference 4.9.14 - DFI Timing Parameters in "LPDDR4 multiPHY Utility
     *  Block (PUB) Databook"
     *-----------------------------------------------------------------------*/
    regVal =
        CSL_FMK( EMIF_CTLCFG_DFITMG0_DFI_TPHY_WRLAT, pSdramTimings->tphyWrlat )                 |
        CSL_FMK( EMIF_CTLCFG_DFITMG0_DFI_TPHY_WRDATA, pSdramTimings->tphyWrdata )               |
        CSL_FMK( EMIF_CTLCFG_DFITMG0_DFI_WRDATA_USE_DFI_PHY_CLK, (uint32_t)1U )                            |
        CSL_FMK( EMIF_CTLCFG_DFITMG0_DFI_T_RDDATA_EN, pSdramTimings->trddataEn )                |
        CSL_FMK( EMIF_CTLCFG_DFITMG0_DFI_RDDATA_USE_DFI_PHY_CLK, (uint32_t)1U )                            |
        CSL_FMK( EMIF_CTLCFG_DFITMG0_DFI_T_CTRL_DELAY, pSdramTimings->tctrlDelay ) ;
    CSL_REG32_WR( &pCfg->pEmifCtlRegs->DFITMG0, regVal );

    regVal =
        CSL_FMK( EMIF_CTLCFG_DFITMG1_DFI_T_DRAM_CLK_ENABLE, pSdramTimings->tDramClkEnable )     |
        CSL_FMK( EMIF_CTLCFG_DFITMG1_DFI_T_DRAM_CLK_DISABLE, pSdramTimings->tDramClkDisable )   |
        CSL_FMK( EMIF_CTLCFG_DFITMG1_DFI_T_WRDATA_DELAY, pSdramTimings->twrdataDelay )          |
        CSL_FMK( EMIF_CTLCFG_DFITMG1_DFI_T_PARIN_LAT, (uint32_t)0U )                             |
        CSL_FMK( EMIF_CTLCFG_DFITMG1_DFI_T_CMD_LAT, (uint32_t)0U ) ;
    CSL_REG32_WR( &pCfg->pEmifCtlRegs->DFITMG1, regVal );

    regVal =
        CSL_FMK( EMIF_CTLCFG_DFITMG2_DFI_TPHY_WRCSLAT, pSdramTimings->tphyWrcslat )             |
        CSL_FMK( EMIF_CTLCFG_DFITMG2_DFI_TPHY_RDCSLAT, pSdramTimings->tphyRdcslat ) ;
    CSL_REG32_WR( &pCfg->pEmifCtlRegs->DFITMG2, regVal );

    regVal = CSL_REG32_RD( &pCfg->pEmifCtlRegs->CRCPARCTL1 );
    CSL_FINS( regVal, EMIF_CTLCFG_CRCPARCTL1_DFI_T_PHY_RDLAT, pSdramTimings->tphyRdlat );
    CSL_REG32_WR( &pCfg->pEmifCtlRegs->CRCPARCTL1, regVal );
    /*-------------------------------------------------------------------------
     *  Configure DRAM timing registers
     *-----------------------------------------------------------------------*/
    regVal = CSL_REG32_RD( &pCfg->pEmifCtlRegs->DRAMTMG2 );
    CSL_FINS( regVal, EMIF_CTLCFG_DRAMTMG2_WRITE_LATENCY, CSL_EMIF_FREQ_MODE_ADJUST(pSdramTimings->writeLatency) );
    CSL_FINS( regVal, EMIF_CTLCFG_DRAMTMG2_READ_LATENCY, CSL_EMIF_FREQ_MODE_ADJUST(pSdramTimings->readLatency) );
    CSL_REG32_WR( &pCfg->pEmifCtlRegs->DRAMTMG2, regVal );
    regVal = CSL_REG32_RD( &pCfg->pEmifCtlRegs->DRAMTMG3 );
    CSL_FINS( regVal, EMIF_CTLCFG_DRAMTMG2_WRITE_LATENCY, pSdramTimings->tDQSCK );
    CSL_REG32_WR( &pCfg->pEmifCtlRegs->DRAMTMG3, regVal );
    /*-------------------------------------------------------------------------
     *  Configure default SDRAM address mapping
     *-----------------------------------------------------------------------*/
    CSL_emifCfgSdramAddrMapping(pCfg);
    /*-------------------------------------------------------------------------
     *  Perform any optional controller configuration if a callback function
     *  is defined.
     *-----------------------------------------------------------------------*/
    if( pCfg->sdramCtrlCfgCbFxnPtr != NULL )
    {
        pCfg->sdramCtrlCfgCbFxnPtr(pCfg);
    }
}

static void CSL_emifConfigPhyModeRegs(CSL_EmifConfig *pCfg, CSL_EmifSdramTimings *pSdramTimings)
{
    uint32_t regVal;
    uint32_t  encVal;
    if( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_DDR3 )
    {
        encVal = CSL_emifEncodeDDR3CasLatency(pCfg->pSdramParms->casLatency);
        regVal = CSL_FMK( EMIF_PHYCFG_MR0_DDR3_BL, (uint32_t)1U)                  |   /* Burst Length: 01 = 4 or 8 (on-the-fly via A12)   */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR3_CL_2,((uint32_t)encVal>>3)&0x1U)   |   /* CAS Latency: encVal[3] */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR3_BT, (uint32_t)1U)                  |   /* Burst Type: 1 = Interleaved */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR3_CL_6_4,((uint32_t)encVal&0x7U))    |   /* CAS Latency: encVal[2:0] */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR3_TM, (uint32_t)0U)                  |   /* Test Mode: 0 = normal operating mode */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR3_DR, (uint32_t)0U)                  |   /* DLL reset: 0 = don't reset */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR3_WR, (uint32_t)6U)                      |   /* Write Recovery */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR3_PD, (uint32_t)1U);                    /* Power Down: 1 = fast exit */
        CSL_REG32_WR(&pCfg->pEmifPhyRegs->u0.MR0_DDR3, regVal);

        regVal = CSL_FMK( EMIF_PHYCFG_MR1_DDR3_DE, (uint32_t)0U)                   |   /* DLL Disable: 0 = not disabled (DLL is enabled) */
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR3_DIC_1, (uint32_t)0U)                |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR3_RTT_2, (uint32_t)1U)                |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR3_AL, (uint32_t)pCfg->pSdramParms->additionalLatency)    |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR3_DIC_5, (uint32_t)0U)                |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR3_RTT_6, (uint32_t)0U)                |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR3_LEVEL, (uint32_t)0U)                |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR3_RTT_9,(uint32_t)0U)                 |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR3_TDQS, (uint32_t)0U)                 |   /* Termination Data Strobe: 0 = no additional termination resistance */
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR3_QOFF, (uint32_t)0U);                    /* Output Enable/Disable: 0 = all output functions normal */
        CSL_REG32_WR(&pCfg->pEmifPhyRegs->u1.MR1_DDR3, regVal);

        encVal = CSL_emifEncodeDDR3CasWriteLatency(pCfg->pSdramParms->casWriteLatency);
        regVal = CSL_FMK( EMIF_PHYCFG_MR2_DDR3_PASR, (uint32_t)0U)                 |   /* Partial Array Self Refresh: 0 = full array */
                 CSL_FMK( EMIF_PHYCFG_MR2_DDR3_CWL, (uint32_t)encVal)             |   /* CAS Write Latency */
                 CSL_FMK( EMIF_PHYCFG_MR2_DDR3_ASR, (uint32_t)0U)                  |   /* Auto Self-Refresh: 0 = not automatic */
                 CSL_FMK( EMIF_PHYCFG_MR2_DDR3_SRT, (uint32_t)0U)                  |   /* Self-Refresh Temperature Range: 0 = normal */
                 CSL_FMK( EMIF_PHYCFG_MR2_DDR3_RTTWR,(uint32_t)0U);                   /* Dynamic ODT: 00 = Dynamic ODT off */
        CSL_REG32_WR(&pCfg->pEmifPhyRegs->u2.MR2_DDR3, regVal);

        regVal = 0;
        CSL_REG32_WR(&pCfg->pEmifPhyRegs->u3.MR3_DDR3, regVal);
    }
    else if( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_DDR4 )
    {
        uint32_t encWr = CSL_emifEncodeDDR4WriteRecoveryToPrecharge(pCfg);
        encVal = CSL_emifEncodeDDR4CasLatency(pCfg->pSdramParms->casLatency);

        regVal = CSL_FMK( EMIF_PHYCFG_MR0_DDR4_BL, (uint32_t)0U )                          |   /* Burst Length: 00 = 8 */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR4_CL_2, ((uint32_t)encVal&0x1U) )            |   /* CAS Latency: encVal[0] */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR4_CL_6_4, (((uint32_t)encVal>>1U)&0x7U) )    |   /* CAS Latency: encVal[3:1] */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR4_CL_12, (((uint32_t)encVal>>4U)&0x1U) )     |   /* CAS Latency: encVal[4] */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR4_BT, (uint32_t)0U )                          |   /* Burst Type: 0 = Sequential */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR4_TM, (uint32_t)0U )                          |   /* Test Mode: 0 = normal operating mode */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR4_DR, (uint32_t)0U )                          |   /* DLL reset: 0 = don't reset */
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR4_WR_11_9, ((uint32_t)encWr&0x7U) )          |   /* Write Recovery [2:0]*/
                 CSL_FMK( EMIF_PHYCFG_MR0_DDR4_WR_13, (((uint32_t)encWr>>3U)&0x1U) );         /* Write Recovery [3] */
        CSL_REG32_WR(&pCfg->pEmifPhyRegs->u0.MR0_DDR4, regVal);

        regVal = CSL_FMK( EMIF_PHYCFG_MR1_DDR4_DE, (uint32_t)1U )                   |   /* DLL Enable: 1 = enabled (DLL is enabled) */
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR4_DIC, (uint32_t)0U )                  |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR4_AL, (uint32_t)pCfg->pSdramParms->additionalLatency)    |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR4_LEVEL, (uint32_t)0U )                |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR4_RTT, (uint32_t)0U )                  |
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR4_TDQS, (uint32_t)0U )                 |   /* Termination Data Strobe: 0 = no additional termination resistance */
                 CSL_FMK( EMIF_PHYCFG_MR1_DDR4_QOFF, (uint32_t)0U );                    /* Output Enable/Disable: 0 = all output functions normal */
        CSL_REG32_WR(&pCfg->pEmifPhyRegs->u1.MR1_DDR4, (uint32_t)regVal);

        encVal = CSL_emifEncodeDDR4CasWriteLatency(pCfg->pSdramParms->casWriteLatency);
        if( encVal != 0U )
        {
            regVal = CSL_FMK( EMIF_PHYCFG_MR2_DDR4_CWL, encVal);    /* CAS Write Latency */
            CSL_REG32_WR(&pCfg->pEmifPhyRegs->u2.MR2_DDR4, regVal);
        }
        CSL_REG32_FINS(&pCfg->pEmifPhyRegs->u3.MR3_DDR4, EMIF_PHYCFG_MR3_DDR4_PDA, 0);
        regVal = CSL_FMK( EMIF_PHYCFG_MR5_DDR4_DM, (uint32_t)1U );
        CSL_REG32_WR(&pCfg->pEmifPhyRegs->u5.MR5_DDR4, regVal);   /* Enable data mask functionality */
    }
    else if( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4 )
    {
        regVal = CSL_REG32_RD(&pCfg->pEmifPhyRegs->u1.MR1);
        CSL_FINS( regVal, EMIF_PHYCFG_MR1_BL, 2U);                           /* Burst Length: 2 = 16 or 32 sequential (on-the-fly) */
        CSL_REG32_WR(&pCfg->pEmifPhyRegs->u1.MR1, regVal);

        regVal = CSL_REG32_RD(&pCfg->pEmifPhyRegs->u2.MR2);
        CSL_FINS( regVal, EMIF_PHYCFG_MR2_RL, CSL_encodeLPDDR4ReadLatency(pSdramTimings->readLatency) );    /* Read Latency */
        CSL_FINS( regVal, EMIF_PHYCFG_MR2_WL, CSL_encodeLPDDR4WriteLatency(pSdramTimings->writeLatency) );  /* Write Latency */
        CSL_REG32_WR(&pCfg->pEmifPhyRegs->u2.MR2, regVal);
    }
    else
    {
         /* No action required */
    }
}

static void CSL_emifConfigPhyIOCRRegs( CSL_EmifConfig *pCfg )
{
    uintptr_t   phyBaseAddr = (uintptr_t)pCfg->pEmifPhyRegs;
    uint32_t    i, regVal, ioModeSelect, numPhyDataMacros, phyDataMacrosMask;

    /* Set AC Power Down Receiver mode for AC CK, CK_N to always OFF */
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->ACIOCR0, EMIF_PHYCFG_ACIOCR0_ACPDRMODE, 2U );

    switch( pCfg->pSdramParms->type )
    {
        case CSL_EMIF_SDRAM_TYPE_DDR3:
            ioModeSelect = 0;
            /*-----------------------------------------------------------------
             *  Disable AC22 (BG[1]) and AC23 (PAR) IOs
             *---------------------------------------------------------------*/
            CSL_REG32_WR( &pCfg->pEmifPhyRegs->ACIOCR3,
                CSL_FMK(EMIF_PHYCFG_ACIOCR3_BGOEMODE, (uint32_t)(2U<<2))  |
                CSL_FMK(EMIF_PHYCFG_ACIOCR3_PAROEMODE, (uint32_t)2U) );
            break;
        case CSL_EMIF_SDRAM_TYPE_LPDDR3:
            ioModeSelect = 2;
            break;
        case CSL_EMIF_SDRAM_TYPE_DDR4:
            ioModeSelect = 2;
            break;
        case CSL_EMIF_SDRAM_TYPE_LPDDR4:
        default:
            ioModeSelect = 4;
            /*-----------------------------------------------------------------
             *  Disable the following IOs:
             *      AC16 (RAS_N)
             *      AC17 (A[17])
             *      AC18 (ACT_N)
             *      AC19 (BA[0])
             *      AC20 (BA[1])
             *      AC21 (BG[0])
             *      AC22 (BG[1])
             *      AC23 (PAR)
             *      AC25 (ODT[0]) ?
             *      AC28 (ODT[1]) ?
             *---------------------------------------------------------------*/
            CSL_REG32_WR( &pCfg->pEmifPhyRegs->ACIOCR3,
                CSL_FMK(EMIF_PHYCFG_ACIOCR3_A16OEMODE, (uint32_t)2U)          |
                CSL_FMK(EMIF_PHYCFG_ACIOCR3_A17OEMODE, (uint32_t)2U)          |
                CSL_FMK(EMIF_PHYCFG_ACIOCR3_ACTOEMODE, (uint32_t)2U)          |
                CSL_FMK(EMIF_PHYCFG_ACIOCR3_BAOEMODE, (uint32_t)((2U<<2)|2U)) |
                CSL_FMK(EMIF_PHYCFG_ACIOCR3_BGOEMODE, (uint32_t)((2U<<2)|2U)) |
                CSL_FMK(EMIF_PHYCFG_ACIOCR3_PAROEMODE, (uint32_t)2U) );
            break;
    }
    /*-------------------------------------------------------------------------
     *  Configure IOM registers
     *-----------------------------------------------------------------------*/
    regVal =    CSL_FMK(EMIF_PHYCFG_ACIOCR5_ACXIOM, ioModeSelect)           |
                CSL_FMK(EMIF_PHYCFG_ACIOCR5_ACVREFIOM, ioModeSelect);
    CSL_REG32_WR(&pCfg->pEmifPhyRegs->ACIOCR5, regVal);
    /*-------------------------------------------------------------------------
     *  Configure DX8SLnIOCR registers
     *-----------------------------------------------------------------------*/
    regVal =    CSL_FMK(EMIF_PHYCFG_DX8SL0IOCR_DXIOM, ioModeSelect)         |
                CSL_FMK(EMIF_PHYCFG_DX8SL0IOCR_DXVREFIOM, ioModeSelect);
    phyDataMacrosMask = CSL_emifGetRequiredPhyDataMacrosMask( pCfg );
    numPhyDataMacros = CSL_emifGetNumPhyDataMacros( pCfg );
    for( i=0; i<numPhyDataMacros; i++ )
    {
        if( (phyDataMacrosMask & ((uint32_t)1U << i)) != 0U )
        {
            CSL_REG32_WR( CSL_EMIF_PHYCFG_DX8SLnIOCR(phyBaseAddr, i), regVal );
        }
    }
}

static void CSL_emifConfigDqsResistors( CSL_EmifConfig *pCfg, uint32_t bEnable )
{
    uintptr_t   phyBaseAddr = (uintptr_t)pCfg->pEmifPhyRegs;
    uint32_t    i, regVal, numPhyDataMacros;

    /*-------------------------------------------------------------------------
     *  Configure DX8SLnDQSCTL registers
     *-----------------------------------------------------------------------*/
    numPhyDataMacros = CSL_emifGetNumPhyDataMacros( pCfg );
    for( i=0; i<numPhyDataMacros; i++ )
    {
        regVal = CSL_REG32_RD( CSL_EMIF_PHYCFG_DX8SLnDQSCTL( phyBaseAddr, i ) );
        if( bEnable == 0U )
        {
            /* Set both DQS and DQS# resistors off */
            CSL_FINS( regVal, EMIF_PHYCFG_DX8SL0DQSCTL_DQSRES,  0U );
            CSL_FINS( regVal, EMIF_PHYCFG_DX8SL0DQSCTL_DQSNRES, 0U );
        }
        else
        {
            /* Set DQS resistor to 620Ohm PD and DQS# resistor to 620Ohm PU */
            CSL_FINS( regVal, EMIF_PHYCFG_DX8SL0DQSCTL_DQSRES,  0x4U );
            CSL_FINS( regVal, EMIF_PHYCFG_DX8SL0DQSCTL_DQSNRES, 0xCU );
        }
        CSL_REG32_WR( CSL_EMIF_PHYCFG_DX8SLnDQSCTL( phyBaseAddr, i ), regVal );
    }
}

static void CSL_emifSelectRank(CSL_EmifConfig *pCfg, uint_least32_t RankId)
{
    CSL_REG32_WR(&pCfg->pEmifPhyRegs->RANKIDR,
        CSL_FMK( EMIF_PHYCFG_RANKIDR_RANKWID, RankId )    |
        CSL_FMK( EMIF_PHYCFG_RANKIDR_RANKRID, RankId ) );
}

static void CSL_emifToggleDqsEnable( CSL_EmifConfig *pCfg, uint_fast8_t dqsIndex, bool bEnable )
{
    uintptr_t   phyBaseAddr = (uintptr_t)pCfg->pEmifPhyRegs;
    uint32_t    oeMask, pdMask, regVal;

    oeMask = CSL_EMIF_PHYCFG_DX0GCR0_DQSGOE_MASK;
    pdMask = CSL_EMIF_PHYCFG_DX0GCR0_DQSGPDR_MASK    |
             CSL_EMIF_PHYCFG_DX0GCR0_DQSRPD_MASK     |
             CSL_EMIF_PHYCFG_DX0GCR0_DQSSEPDR_MASK   |
             CSL_EMIF_PHYCFG_DX0GCR0_DQSNSEPDR_MASK;
    regVal = CSL_REG32_RD( CSL_EMIF_PHYCFG_DXnGCR0(phyBaseAddr, dqsIndex) );
    if( bEnable== (bool)true )
    {
        regVal |= oeMask;
        regVal &= ~pdMask;
    }
    else
    {
        regVal &= ~oeMask;
        regVal |= pdMask;
    }
    CSL_REG32_WR( CSL_EMIF_PHYCFG_DXnGCR0(phyBaseAddr, dqsIndex), regVal );
    if( !bEnable )
    {
        /*---------------------------------------------------------------------
         *  Save maximum power for a disabled byte lane (per section 4.9.10
         *  of the Synopsys PUB spec)
         *-------------------------------------------------------------------*/
        regVal = CSL_REG32_RD( CSL_EMIF_PHYCFG_DXnGCR1(phyBaseAddr, dqsIndex) );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR1_DQEN, (uint32_t)0U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR1_DMEN, (uint32_t)0U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR1_DSEN, (uint32_t)0U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR1_TEEN, (uint32_t)0U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR1_PDREN,(uint32_t)0U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR1_OEEN, (uint32_t)0U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR1_DXPDRMODE, (uint32_t)0x5555U );
        CSL_REG32_WR( CSL_EMIF_PHYCFG_DXnGCR1(phyBaseAddr,(uint32_t)dqsIndex), regVal );

        regVal = CSL_REG32_RD( CSL_EMIF_PHYCFG_DXnGCR2(phyBaseAddr, dqsIndex) );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR2_DXOEMODE, (uint32_t)0xAAAAU );
        CSL_REG32_WR( CSL_EMIF_PHYCFG_DXnGCR2(phyBaseAddr, dqsIndex), regVal );

        regVal = CSL_REG32_RD( CSL_EMIF_PHYCFG_DXnGCR3(phyBaseAddr, dqsIndex) );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR3_DSPDRMODE, (uint32_t)1U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR3_DSOEMODE,  (uint32_t)2U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR3_DMPDRMODE, (uint32_t)1U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR3_DMOEMODE,  (uint32_t)2U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR3_DSNPDRMODE,(uint32_t)1U );
        CSL_FINS( regVal, EMIF_PHYCFG_DX0GCR3_DSNOEMODE, (uint32_t)2U );
        CSL_REG32_WR( CSL_EMIF_PHYCFG_DXnGCR3(phyBaseAddr, dqsIndex), regVal );
    }
}

static void CSL_emifConfigDqsRegisters(CSL_EmifConfig *pCfg)
{
    uint32_t    phyDataMacroNum, phyDataMacrosMask, enableLane, numPhyDataMacros;

    phyDataMacrosMask   = CSL_emifGetRequiredPhyDataMacrosMask( pCfg );
    numPhyDataMacros    = CSL_emifGetNumPhyDataMacros( pCfg );
    for( phyDataMacroNum = 0; phyDataMacroNum < numPhyDataMacros; phyDataMacroNum++ )
    {
        if( (phyDataMacrosMask & ((uint32_t)1U << phyDataMacroNum)) == 0U)
        {
            enableLane = 0;
        }
        else
        {
            enableLane = 1U;
        }
        CSL_emifToggleDqsEnable( pCfg, phyDataMacroNum, ((enableLane==0U)?(bool)false:(bool)true));
    }
    /*-------------------------------------------------------------------------
     *  If Read DQS gate training is not being done, then set the DQS Gating
     *  System Latency to 1 for all byte lanes.
     *-----------------------------------------------------------------------*/
    if( (pCfg->dataTraining & CSL_EMIF_PHYCFG_PIR_QSGATE_MASK) == 0U )
    {
        uint32_t    rank, dgsl=1, wlsl=2;
        uintptr_t   phyBaseAddr = (uintptr_t)pCfg->pEmifPhyRegs;
        if( pCfg->pSdramParms->type ==  CSL_EMIF_SDRAM_TYPE_DDR4 )
        {
            dgsl = 2;
            wlsl = 2;
        }
        for( rank=0; rank<pCfg->pSdramParms->numRanks; rank++ )
        {
            CSL_emifSelectRank(pCfg, rank);
            for( phyDataMacroNum = 0; phyDataMacroNum < numPhyDataMacros; phyDataMacroNum++ )
            {
                if( (phyDataMacrosMask & ((uint32_t)1U << phyDataMacroNum)) != 0U )
                {
                    CSL_REG32_WR( CSL_EMIF_PHYCFG_DXnGTR0(phyBaseAddr, phyDataMacroNum),
                        CSL_FMK(EMIF_PHYCFG_DX0GTR0_DGSL, dgsl)   |
                        CSL_FMK(EMIF_PHYCFG_DX0GTR0_WLSL, wlsl) );
                }
            }
        }
    }
}

static void CSL_emifCfgPllFreqSel(CSL_EmifConfig *pCfg)
{
    uint32_t pllFreqSel, pllRefClkMhz = (uint32_t)(pCfg->sdramClkFreqMHz) / 2U;

    if( pllRefClkMhz < 197U )      { pllFreqSel = 7U; }
    else if( pllRefClkMhz < 235U ) { pllFreqSel = 6U; }
    else if( pllRefClkMhz < 279U ) { pllFreqSel = 5U; }
    else if( pllRefClkMhz < 332U ) { pllFreqSel = 4U; }
    else if( pllRefClkMhz < 396U ) { pllFreqSel = 3U; }
    else if( pllRefClkMhz < 471U ) { pllFreqSel = 2U; }
    else if( pllRefClkMhz < 560U ) { pllFreqSel = 1U; }
    else if( pllRefClkMhz < 668U ) { pllFreqSel = 0U; }
    else                           { pllFreqSel = 8U; }
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->PLLCR0, EMIF_PHYCFG_PLLCR0_FRQSEL, pllFreqSel );
}

/*=============================================================================
 *  This internal function minimally configures the Synopsys LPDDR4 multiPHY
 *  Utility Block (PUB).
 *===========================================================================*/
static void CSL_emifConfigPhy(CSL_EmifConfig *pCfg, CSL_EmifSdramTimings *pSdramTimings)
{
    uint16_t    phyCtlClkFreqMHz = pCfg->sdramClkFreqMHz / 2U;
    uint32_t    regVal, ddrMode, tREFPRD;
    uint32_t    tREFIns = 7800;
#if CSL_EMIF_FAST_SIM == 0
    uint16_t    dramClkFreqMHz = pCfg->sdramClkFreqMHz;
#endif

    switch( pCfg->pSdramParms->type )
    {
        case CSL_EMIF_SDRAM_TYPE_DDR3:
            ddrMode = 3;
            break;
        case CSL_EMIF_SDRAM_TYPE_LPDDR3:
            ddrMode = 1;
            break;
        case CSL_EMIF_SDRAM_TYPE_DDR4:
            ddrMode = 4;
            break;
        case CSL_EMIF_SDRAM_TYPE_LPDDR4:
        default:
            ddrMode = 5;
            break;
    }
    /*-------------------------------------------------------------------------
     *  Configure DCR
     *-----------------------------------------------------------------------*/
    regVal = CSL_REG32_RD(&pCfg->pEmifPhyRegs->DCR);
    CSL_FINS(regVal, EMIF_PHYCFG_DCR_DDRMD, ddrMode);
    CSL_REG32_WR(&pCfg->pEmifPhyRegs->DCR, regVal);
    /*-------------------------------------------------------------------------
     *  Configure PHY PLL timing registers
     *-----------------------------------------------------------------------*/
    regVal =    CSL_FMK(EMIF_PHYCFG_PTR0_TPHYRST, (uint32_t)16U)                       |
                CSL_FMK(EMIF_PHYCFG_PTR0_TPLLGS,  ((uint32_t)4U * phyCtlClkFreqMHz))   |
                CSL_FMK(EMIF_PHYCFG_PTR0_TPLLPD,  ((uint32_t)1U * phyCtlClkFreqMHz));
    CSL_REG32_WR(&pCfg->pEmifPhyRegs->PTR0, regVal);

    regVal =    CSL_FMK(EMIF_PHYCFG_PTR1_TPLLRST, ((uint32_t)9U * phyCtlClkFreqMHz) )        |
                CSL_FMK(EMIF_PHYCFG_PTR1_TPLLLOCK,((uint32_t)25U * phyCtlClkFreqMHz) );
    CSL_REG32_WR(&pCfg->pEmifPhyRegs->PTR1, regVal);
#if CSL_EMIF_FAST_SIM == 1
    regVal = CSL_FMK( EMIF_PHYCFG_PTR3_TDINIT0, 1024U );
#else
    regVal = CSL_FMK( EMIF_PHYCFG_PTR3_TDINIT0, (dramClkFreqMHz*tDINIT0us[pCfg->pSdramParms->type]) );
#endif
    CSL_REG32_WR(&pCfg->pEmifPhyRegs->PTR3, regVal);
#if CSL_EMIF_FAST_SIM == 1
    regVal = CSL_FMK( EMIF_PHYCFG_PTR4_TDINIT1, 1024U );
#else
    regVal = CSL_FMK( EMIF_PHYCFG_PTR4_TDINIT1, (dramClkFreqMHz*tDINIT1ns[pCfg->pSdramParms->type]/1000U) );
#endif
    CSL_REG32_WR(&pCfg->pEmifPhyRegs->PTR4, regVal);
#if CSL_EMIF_FAST_SIM == 1
    regVal = CSL_FMK( EMIF_PHYCFG_PTR5_TDINIT2, 1024U );
#else
    regVal = CSL_FMK( EMIF_PHYCFG_PTR5_TDINIT2, (dramClkFreqMHz*tDINIT2us[pCfg->pSdramParms->type]) );
#endif
    CSL_REG32_WR(&pCfg->pEmifPhyRegs->PTR5, regVal);

    regVal = CSL_FMK(EMIF_PHYCFG_PTR6_TDINIT3, (uint32_t)pCfg->sdramClkFreqMHz)       |
             CSL_FMK(EMIF_PHYCFG_PTR6_TDINIT4, max(CSL_EMIF_NS_TO_CLKS((uint32_t)30U,pCfg->sdramClkFreqMHz),(uint32_t)8U)+3U );
    CSL_REG32_WR(&pCfg->pEmifPhyRegs->PTR6, regVal);

    CSL_emifCfgPllFreqSel(pCfg);
    /*-------------------------------------------------------------------------
     *  Configure PHY DRAM timing registers
     *-----------------------------------------------------------------------*/
    regVal = CSL_REG32_RD(&pCfg->pEmifPhyRegs->DTPR3);
    CSL_FINS(regVal, EMIF_PHYCFG_DTPR3_TDQSCK, pSdramTimings->tDQSCK);
    CSL_REG32_WR(&pCfg->pEmifPhyRegs->DTPR3, regVal);
    /*-------------------------------------------------------------------------
     *  Configure ACIOCR and DX8SLnIOCR registers
     *-----------------------------------------------------------------------*/
    CSL_emifConfigPhyIOCRRegs(pCfg);
    /*-------------------------------------------------------------------------
     *  Configure the PHY mode registers
     *-----------------------------------------------------------------------*/
    CSL_emifConfigPhyModeRegs(pCfg, pSdramTimings);
    /*-------------------------------------------------------------------------
     *  Configure refresh related registers
     *-----------------------------------------------------------------------*/
    regVal = CSL_REG32_FEXT( &pCfg->pEmifPhyRegs->DTCR0, EMIF_PHYCFG_DTCR0_RFSHDT );
    if( (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_DDR4) || (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4) )
    {
        tREFPRD = ((regVal * tREFIns * pCfg->sdramClkFreqMHz) / 1000U) - 800U;
    }
    else
    {
        tREFPRD = ((regVal * tREFIns * pCfg->sdramClkFreqMHz) / 1000U) - 400U;
    }
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->PGCR2, EMIF_PHYCFG_PGCR2_TREFPRD, tREFPRD );
#if CSL_EMIF_FAST_SIM == 1
    /*-------------------------------------------------------------------------
     *  Configure DTCR0 register:
     *  1. Clear DTWBDDM (Data Training Write Bit Deskew Data Mask)
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->DTCR0, EMIF_PHYCFG_DTCR0_DTWBDDM, 0U );
#endif
    /*-------------------------------------------------------------------------
     *  Configure DTCR1 register:
     *  1. Configure training rank enables
     *  2. In LPDDR4 mode, disable basic gate training by setting DTCR1.BSTEN=0
     *-----------------------------------------------------------------------*/
    regVal = CSL_REG32_RD( &pCfg->pEmifPhyRegs->DTCR1 );
    CSL_FINS( regVal, EMIF_PHYCFG_DTCR1_RANKEN, ((1U << pCfg->pSdramParms->numRanks)-1U) );
    if( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4 )
    {
        CSL_FINS( regVal, EMIF_PHYCFG_DTCR1_BSTEN, 0U );
    }
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->DTCR1, regVal );
    /*-------------------------------------------------------------------------
     *  Give some delay for all writes to complete
     *-----------------------------------------------------------------------*/
    pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CFG, 100U );
}

static void CSL_emifToggleCoreResetAssert(CSL_EmifConfig *pCfg, bool bVal)
{
    CSL_REG32_FINS( &pCfg->pEmifSsRegs->SS_CTL_REG, EMIF_SSCFG_SS_CTL_REG_CTL_ARST, (bVal==(bool)true?(uint32_t)1U:(uint32_t)0U) );   /* Set reset to controller and phy   */
}

static void CSL_emifAssertCoreReset(CSL_EmifConfig *pCfg)
{
    CSL_emifToggleCoreResetAssert(pCfg, (bool)true);
}

static void CSL_emifDeassertCoreReset(CSL_EmifConfig *pCfg)
{
    CSL_emifToggleCoreResetAssert(pCfg, (bool)false);
}

static bool CSL_emifIsControllerIdle( CSL_EmifConfig *pCfg )
{
    return (bool)true;
}

static bool CSL_emifIsDataPipelineEmpty(CSL_EmifConfig *pCfg)
{
    uint32_t regVal;
    bool     wrQueueEmpty, rdQueueEmpty, wrDataPipelineEmpty, rdDataPipelineEmpty;

    regVal = CSL_REG32_RD( &pCfg->pEmifCtlRegs->DBGCAM );
    wrQueueEmpty        = (CSL_FEXT( regVal, EMIF_CTLCFG_DBGCAM_DBG_WR_Q_EMPTY )==0U) ? (bool)false : (bool)true;
    rdQueueEmpty        = (CSL_FEXT( regVal, EMIF_CTLCFG_DBGCAM_DBG_RD_Q_EMPTY )==0U) ? (bool)false : (bool)true;
    wrDataPipelineEmpty = (CSL_FEXT( regVal, EMIF_CTLCFG_DBGCAM_WR_DATA_PIPELINE_EMPTY )==0U) ? (bool)false : (bool)true;
    rdDataPipelineEmpty = (CSL_FEXT( regVal, EMIF_CTLCFG_DBGCAM_RD_DATA_PIPELINE_EMPTY )==0U) ? (bool)false : (bool)true;
    return ((wrQueueEmpty && rdQueueEmpty && wrDataPipelineEmpty && rdDataPipelineEmpty) ? (bool)true : (bool)false);
}

static void CSL_emifToggleAutoRefreshDisable(CSL_EmifConfig *pCfg, bool bVal)
{
    CSL_REG32_FINS( &pCfg->pEmifCtlRegs->RFSHCTL3, EMIF_CTLCFG_RFSHCTL3_DIS_AUTO_REFRESH, (bVal==(bool)true ? (uint32_t)1U : (uint32_t)0U) );  /* Set auto-refresh */
}

static void CSL_emifDisableAutoRefresh(CSL_EmifConfig *pCfg)
{
    CSL_emifToggleAutoRefreshDisable(pCfg, (bool)true);
}

static void CSL_emifEnableAutoRefresh(CSL_EmifConfig *pCfg)
{
    CSL_emifToggleAutoRefreshDisable(pCfg, (bool)false);
}

static bool CSL_emifIsSwDone(CSL_EmifConfig *pCfg)
{
    return (CSL_REG32_FEXT( &pCfg->pEmifCtlRegs->SWSTAT, EMIF_CTLCFG_SWSTAT_SW_DONE_ACK ) == 0U) ? (bool)false : (bool)true;
}

static void CSL_emifToggleSwDone(CSL_EmifConfig *pCfg, bool bVal)
{
    CSL_REG32_FINS( &pCfg->pEmifCtlRegs->SWCTL, EMIF_CTLCFG_SWCTL_SW_DONE, (bVal==(bool)true ? (uint32_t)1U :(uint32_t)0U) );
}

static void CSL_emifStartSwProgramming(CSL_EmifConfig *pCfg)
{
    CSL_emifToggleSwDone(pCfg, (bool)false);
}

static void CSL_emifEndSwProgramming(CSL_EmifConfig *pCfg)
{
    CSL_emifToggleSwDone(pCfg, (bool)true);
    while( CSL_emifIsSwDone(pCfg) == (bool)false ) { }
}

static void CSL_emifToggleHifEnable(CSL_EmifConfig *pCfg, bool bEnable)
{
    CSL_REG32_FINS( &pCfg->pEmifCtlRegs->DBG1, EMIF_CTLCFG_DBG1_DIS_HIF, (bEnable==(bool)true ? (uint32_t)1U : (uint32_t)0U) );
}

static void CSL_emifInitiateQuasiDynamicWrite( CSL_EmifConfig *pCfg, uint32_t group )
{
    if( group == 3U )
    {
        CSL_emifToggleHifEnable(pCfg, (bool)false);
        while( CSL_emifIsControllerIdle(pCfg) == (bool)false ) { }
        while( CSL_emifIsDataPipelineEmpty(pCfg) == (bool)false ) { }
    }
    CSL_emifStartSwProgramming(pCfg);
}

static void CSL_emifTerminateQuasiDynamicWrite( CSL_EmifConfig *pCfg, uint32_t group )
{
    CSL_emifEndSwProgramming(pCfg);
    if( group == 3U )
    {
        CSL_emifToggleHifEnable(pCfg, (bool)true);
    }
}

static void CSL_emifStartPhyInit(CSL_EmifConfig *pCfg, uint32_t phyInitFlags)
{
    /*-------------------------------------------------------------------------
     *  It is recommended that the INIT bit be set in a separate config write
     *  step after other bits in this register have been programmed to avoid
     *  any race condition.
     *-----------------------------------------------------------------------*/
    uint32_t phyInitFlagsLocal = phyInitFlags;
    if( phyInitFlagsLocal != 0U )
    {
        phyInitFlagsLocal &= ~CSL_FMK( EMIF_PHYCFG_PIR_INIT, 1U );    /* Make sure INIT bit is 0 */
        CSL_REG32_WR( &pCfg->pEmifPhyRegs->PIR, phyInitFlagsLocal );
        phyInitFlagsLocal |= CSL_FMK( EMIF_PHYCFG_PIR_INIT, 1U );     /* Set INIT bit to 1 */
        CSL_REG32_WR( &pCfg->pEmifPhyRegs->PIR, phyInitFlagsLocal );
        /*-------------------------------------------------------------------------
         *  Note that PGSR0[IDONE] is not cleared immediately after PIR[INIT] is
         *  set, and therefore software must wait a minimum of 10 configuration
         *  clock cycles from when PIR[INIT] is set to when it starts polling for
         *  PGSR0[IDONE].
         *-----------------------------------------------------------------------*/
        pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CFG, 100 );
    }
}

static uint32_t CSL_emifGetPhyStatus( CSL_EmifConfig *pCfg )
{
    return CSL_REG32_RD(&pCfg->pEmifPhyRegs->PGSR0);
}

static bool CSL_emifIsPhyStatusSet( CSL_EmifConfig *pCfg, uint32_t phyStatusMask )
{
    return ((CSL_emifGetPhyStatus(pCfg) & phyStatusMask) == phyStatusMask)? (bool)true : (bool)false;
}

static void CSL_emifGetSetBitPositions( uint32_t bitMask, uint8_t bitPos[] )
{
    uint8_t i, j=0;

    for( i=0; i<32U; i++ )
    {
        if( (bitMask & ((uint32_t)1U<<i)) != 0U )
        {
            bitPos[j] = i;
            j++;
        }
    }
    for( i=j; i<32U; i++ )
    {
        bitPos[i] = CSL_EMIF_UNDEFINED;
    }
}

static bool CSL_emifAreBitsContiguous(uint8_t bitPos[], uint8_t lsb, uint8_t msb)
{
    uint8_t i;
    uint8_t lsbLocal = lsb;
    uint8_t msbLocal = msb;
    bool retVal = (bool)true;

    if(msbLocal < lsbLocal)
    {
        i = lsbLocal;
        lsbLocal = msbLocal;
        msbLocal = i;
    }
    if(lsbLocal < msbLocal)
    {
        for(i=lsbLocal; i<msbLocal; i++)
        {
            if( bitPos[i] != (bitPos[i+1U]-1U) )
            {
                retVal = (bool)false;
                break;
    }
        }
    }
    return retVal;
}

static int32_t CSL_emifDoPhyInit( CSL_EmifConfig *pCfg )
{
    uint32_t regVal, expDone;
    int32_t retVal = 0;

    if(pCfg->pPhyParms != (void *)0)
    {
        regVal = 0;
        expDone = 0;
        if((pCfg->pPhyParms->bZCAL)==(bool)true)         { regVal |= CSL_FMK( EMIF_PHYCFG_PIR_ZCAL,     1U ); expDone |= CSL_EMIF_PHYCFG_PGSR0_ZCDONE_MASK; }
        if((pCfg->pPhyParms->bCA)==(bool)true)           { regVal |= CSL_FMK( EMIF_PHYCFG_PIR_CA,       1U ); expDone |= CSL_EMIF_PHYCFG_PGSR0_CADONE_MASK; }
        if((pCfg->pPhyParms->bPLLInit)==(bool)true)      { regVal |= CSL_FMK( EMIF_PHYCFG_PIR_PLLINIT,  1U ); expDone |= (CSL_EMIF_PHYCFG_PGSR0_PLDONE_MASK | CSL_EMIF_PHYCFG_PGSR0_APLOCK_MASK); }
        if((pCfg->pPhyParms->bDCAL)==(bool)true)         { regVal |= CSL_FMK( EMIF_PHYCFG_PIR_DCAL,     1U ); expDone |= CSL_EMIF_PHYCFG_PGSR0_DCDONE_MASK; }
        if((pCfg->pPhyParms->bPhyReset)==(bool)true)     { regVal |= CSL_FMK( EMIF_PHYCFG_PIR_PHYRST,   1U ); expDone |= CSL_EMIF_PHYCFG_PGSR0_ZCDONE_MASK; }
        if((pCfg->pPhyParms->bDramReset)==(bool)true)    { regVal |= CSL_FMK( EMIF_PHYCFG_PIR_DRAMRST,  1U ); expDone |= CSL_EMIF_PHYCFG_PGSR0_ZCDONE_MASK; }
    }
    else
    {
        regVal =    CSL_FMK( EMIF_PHYCFG_PIR_ZCAL, 1U )          |
                    CSL_FMK( EMIF_PHYCFG_PIR_PLLINIT, 1U)        |
                    CSL_FMK( EMIF_PHYCFG_PIR_DCAL, 1U )          |
                    CSL_FMK( EMIF_PHYCFG_PIR_PHYRST, 1U );
        expDone =   CSL_EMIF_PHYCFG_PGSR0_PLDONE_MASK           |
                    CSL_EMIF_PHYCFG_PGSR0_DCDONE_MASK           |
                    CSL_EMIF_PHYCFG_PGSR0_ZCDONE_MASK           |
                    CSL_EMIF_PHYCFG_PGSR0_APLOCK_MASK;

    }
    expDone |= CSL_EMIF_PHYCFG_PGSR0_IDONE_MASK;
    if( regVal != 0U)
    {
        CSL_emifStartPhyInit( pCfg, regVal );
        do {
            pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CFG, 100U );
            regVal = CSL_emifGetPhyStatus(pCfg);
        } while((regVal & CSL_EMIF_PHYCFG_PGSR0_IDONE_MASK) == 0U );
        if( (regVal & expDone) != expDone )
        {
            retVal = CSL_EMIF_CONFIG_RETURN_PHY_INIT_FAIL;
        }
    }
    return retVal;
}

static void CSL_emifDoSdramInit( CSL_EmifConfig *pCfg )
{
    uint32_t regVal;

    regVal = CSL_FMK( EMIF_PHYCFG_PIR_DRAMINIT, (uint32_t)1 )     |
             CSL_FMK( EMIF_PHYCFG_PIR_DRAMRST, (uint32_t)1 );
    CSL_emifStartPhyInit( pCfg, regVal );

    regVal = CSL_FMK( EMIF_PHYCFG_PGSR0_IDONE, (uint32_t)1 ) | CSL_FMK( EMIF_PHYCFG_PGSR0_DIDONE, (uint32_t)1 );
    while( CSL_emifIsPhyStatusSet( pCfg, regVal ) == (bool)false )
    {
        pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CFG, 100 );
    }
}

typedef struct
{
    const char  *pName;
    uint32_t    enMask;
    uint32_t    doneMask;
    uint32_t    errMask;
} CSL_EmifDataTraining;

static CSL_EmifDataTraining emifDataTraining[] =
{
    { "WL",     CSL_EMIF_PHYCFG_PIR_WL_MASK,     CSL_EMIF_PHYCFG_PGSR0_WLDONE_MASK,     CSL_EMIF_PHYCFG_PGSR0_WLERR_MASK     },
    { "QSGATE", CSL_EMIF_PHYCFG_PIR_QSGATE_MASK, CSL_EMIF_PHYCFG_PGSR0_QSGDONE_MASK,    CSL_EMIF_PHYCFG_PGSR0_QSGERR_MASK    },
    { "DQS2DQ", CSL_EMIF_PHYCFG_PIR_DQS2DQ_MASK, CSL_EMIF_PHYCFG_PGSR0_DQS2DQDONE_MASK, CSL_EMIF_PHYCFG_PGSR0_DQS2DQERR_MASK },
    { "WLA",    CSL_EMIF_PHYCFG_PIR_WLADJ_MASK,  CSL_EMIF_PHYCFG_PGSR0_WLADONE_MASK,    CSL_EMIF_PHYCFG_PGSR0_WLAERR_MASK    },
    { "RDDSKW", CSL_EMIF_PHYCFG_PIR_RDDSKW_MASK, CSL_EMIF_PHYCFG_PGSR0_RDDONE_MASK,     CSL_EMIF_PHYCFG_PGSR0_RDERR_MASK     },
    { "WRDSKW", CSL_EMIF_PHYCFG_PIR_WRDSKW_MASK, CSL_EMIF_PHYCFG_PGSR0_WDDONE_MASK,     CSL_EMIF_PHYCFG_PGSR0_WDERR_MASK     },
    { "RDEYE",  CSL_EMIF_PHYCFG_PIR_RDEYE_MASK,  CSL_EMIF_PHYCFG_PGSR0_REDONE_MASK,     CSL_EMIF_PHYCFG_PGSR0_REERR_MASK     },
    { "WREYE",  CSL_EMIF_PHYCFG_PIR_WREYE_MASK,  CSL_EMIF_PHYCFG_PGSR0_WEDONE_MASK,     CSL_EMIF_PHYCFG_PGSR0_WEERR_MASK     },
    { "VREF",   CSL_EMIF_PHYCFG_PIR_VREF_MASK,   CSL_EMIF_PHYCFG_PGSR0_VDONE_MASK,      CSL_EMIF_PHYCFG_PGSR0_VERR_MASK      }
};

static int32_t CSL_emifDoDataTraining( CSL_EmifConfig *pCfg )
{
    uint32_t i, regVal=0, trainingTypes=pCfg->dataTraining;
    int32_t retVal = 0;

    if( trainingTypes != 0U )
    {
        /*---------------------------------------------------------------------
         *  Enable DATX8 slice DQS pull-downs and DQSN pull-ups for DDR3 mode
         *-------------------------------------------------------------------*/
        if( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_DDR3 )
        {
            CSL_emifConfigDqsResistors( pCfg, 1U );
        }
        /*---------------------------------------------------------------------
         *  Kick-off data training, wait for training to complete, and read
         *  the training results.
         *-------------------------------------------------------------------*/
        CSL_emifStartPhyInit( pCfg, trainingTypes );
        while( !CSL_emifIsPhyStatusSet( pCfg, 1U ) )
        {
            pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CFG, 100 );
        }
        regVal = CSL_emifGetPhyStatus(pCfg);
        /*---------------------------------------------------------------------
         *  Disable DATX8 slice DQS pull-downs and DQSN pull-ups for DDR3 mode
         *-------------------------------------------------------------------*/
        if( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_DDR3 )
        {
            CSL_emifConfigDqsResistors( pCfg, 0U );
        }
        /*---------------------------------------------------------------------
         *  Construct the return value based on training results
         *-------------------------------------------------------------------*/
        for( i=0; i<(sizeof(emifDataTraining)/sizeof(CSL_EmifDataTraining)); i++ )
        {
            if((trainingTypes & emifDataTraining[i].enMask) != 0U)
            {
                if( ((regVal & emifDataTraining[i].doneMask) != 0U) && ((regVal & emifDataTraining[i].errMask) != 0U) )
                {
                    retVal = -((int32_t)i+2);
                }
            }
        }
    }
    return retVal;
}

static void CSL_emifToggleSelfRefreshSwEnable(CSL_EmifConfig *pCfg, bool bVal)
{
    CSL_REG32_FINS( &pCfg->pEmifCtlRegs->PWRCTL, EMIF_CTLCFG_PWRCTL_SELFREF_SW, (bVal==(bool)true ? (uint32_t)1U : (uint32_t)0U) );        /*Set self-refresh  */
}

static bool CSL_emifIsEmifConfigValid( CSL_EmifConfig *pCfg )
{
    bool bParmsOk = (bool)true;

    /*-------------------------------------------------------------------------
     *  Validate memc and sdram data widths
     *-----------------------------------------------------------------------*/
    if( !(  (pCfg->memcDramDataWidthBits == 64U)        ||
            (pCfg->memcDramDataWidthBits == 32U)        ||
            (pCfg->memcDramDataWidthBits == 16U) ) )
    { bParmsOk = (bool)false; }
    if( !(  (pCfg->pSdramParms->sdramDataWidth == pCfg->memcDramDataWidthBits)          ||
            (pCfg->pSdramParms->sdramDataWidth == (pCfg->memcDramDataWidthBits / 2U))   ||
            (pCfg->pSdramParms->sdramDataWidth == (pCfg->memcDramDataWidthBits / 4U)) ) )
    { bParmsOk = (bool)false; }
    /*-------------------------------------------------------------------------
     *  For LPDDR4 mode:
     *  o Full-width mode is only supported without memory ECC
     *  o Quarter-width mode is not supported
     *-----------------------------------------------------------------------*/
    if( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4 )
    {
        if( (pCfg->pSdramParms->sdramDataWidth == pCfg->memcDramDataWidthBits)  &&
            (pCfg->bEnableMemoryECC == (bool)true) )
        { bParmsOk = (bool)false; }
        if( pCfg->pSdramParms->sdramDataWidth == (pCfg->memcDramDataWidthBits / 4U ) )
        { bParmsOk = (bool)false; }
    }
    /*-------------------------------------------------------------------------
     *  Validate burst lengths
     *-----------------------------------------------------------------------*/
    if( !(  (pCfg->pSdramParms->burstLength == 4U)      ||
            (pCfg->pSdramParms->burstLength == 8U)      ||
            ((pCfg->pSdramParms->burstLength == 16U) && ((pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR2) || (pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4))) )
       )
    { bParmsOk = (bool)false; }
    /*-------------------------------------------------------------------------
     *  Confirm clock cycle delay callback is provided
     *-----------------------------------------------------------------------*/
    if( pCfg->delayClockCyclesCbFxnPtr == NULL )
    { bParmsOk = (bool)false; }
    return bParmsOk;
}

static void CSL_emifConfigSubsystem( CSL_EmifConfig *pCfg )
{
    uint32_t regVal;

    if( pCfg->bEnableBusECC || pCfg->bEnableMemoryECC )
    {
        regVal = CSL_REG32_RD( &pCfg->pEmifSsRegs->V2H_CTL_REG );
        CSL_FINS( regVal, EMIF_SSCFG_V2H_CTL_REG_RMW_EN, (pCfg->bEnableMemoryECC==(bool)true ? (uint32_t)1U : (uint32_t)0U) );           /* Enable or disable ECC per configuration parm */
        CSL_REG32_WR( &pCfg->pEmifSsRegs->V2H_CTL_REG, regVal );
    }
    if( ( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4 )                   &&
        ( pCfg->bEnableMemoryECC == (bool)true )                                          &&
        ( pCfg->pSdramParms->sdramDataWidth == (pCfg->memcDramDataWidthBits/2U) ) )
    {
        CSL_REG32_FINS( &pCfg->pEmifSsRegs->SS_CTL_REG, EMIF_SSCFG_SS_CTL_REG_X22_LPDDR4, 1U );     /* Enable ECC mux logic for half-width LPDDR4 mode */
    }
}

static void CSL_emifWaitForPhyInitDone( CSL_EmifConfig *pCfg, uint32_t doneMask )
{
    uint32_t regVal;

    do {
        pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CFG, 100U );
        regVal = CSL_emifGetPhyStatus(pCfg);
    } while((regVal & doneMask) != doneMask );
}

static int32_t CSL_emifLpddr4Boot( CSL_EmifConfig *pCfg )
{
    int32_t retVal = 0;
    uint32_t regVal, regVal2;

    /*-------------------------------------------------------------------------
     *  The below register writes are recommended before starting the slow boot
     *  sequence.
     *-----------------------------------------------------------------------*/
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->RIOCR4, 0x00000005U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->RIOCR2, 0x00000005U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->ACIOCR1, 0x55000000U );
    /*-------------------------------------------------------------------------
     *  The following Pseudo code can be used as a reference for the programming
     *  sequence needed for LPDDR4 DRAM initialization using boot clock.
     *-----------------------------------------------------------------------*/

    /*-------------------------------------------------------------------------
     *  STEP 1.a : Program PUB to operate in FA
     *  Host programs PGCR5.DDLPGRW/PGCR5.DDLPGACT = 1'b0 for Frequency A (FA)
     *-----------------------------------------------------------------------*/
    regVal = CSL_REG32_RD( &pCfg->pEmifPhyRegs->PGCR5 );
    CSL_FINS( regVal, EMIF_PHYCFG_PGCR5_DDLPGRW, 0U );
    CSL_FINS( regVal, EMIF_PHYCFG_PGCR5_DDLPGACT, 0U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->PGCR5, regVal );
    /*-------------------------------------------------------------------------
     *  STEP 1.b : Program PUB MR registers
     *  Host programs the following for FA
     *      i. Program PUB MR1, 2, 3, 11, 13, 12, 14, 22 registers based on FA
     *     ii. Program PUB MR13[6] (FSP-WR) = 1'b1.
     *    iii. Program all other applicable PUB specific registers for FA
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->u10.MR13, EMIF_PHYCFG_MR13_FSPWR, 1U );
    /*-------------------------------------------------------------------------
     *  STEP 1.c : Disabling dfi_init_complete
     *  Host disables dfi_init_complete generation, PGCR1[17] (DISDIC) = 1'b1
     *
     *  STEP 1.d : Disabling DFI i/f pass through
     *  Host Programs PGCR1[6](PUBMODE) = 1'b1 to disable DFI interface
     *-----------------------------------------------------------------------*/
    regVal = CSL_REG32_RD( &pCfg->pEmifPhyRegs->PGCR1 );
    CSL_FINS( regVal, EMIF_PHYCFG_PGCR1_DISDIC, 1U );
    CSL_FINS( regVal, EMIF_PHYCFG_PGCR1_PUBMODE, 1U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->PGCR1, regVal );
    /*-------------------------------------------------------------------------
     *  Place PLL in bypass mode
     *  Place PLL in bypass mode using phy_ctl_byp_clk period equal to 2*tCKb
     *-----------------------------------------------------------------------*/
    regVal = CSL_REG32_RD( &pCfg->pEmifPhyRegs->PLLCR0 );
    CSL_FINS( regVal, EMIF_PHYCFG_PLLCR0_PLLBYP, 1U );
    CSL_FINS( regVal, EMIF_PHYCFG_PLLCR0_PLLRST, 1U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->PLLCR0, regVal );
    CSL_FINS( regVal, EMIF_PHYCFG_PLLCR0_PLLRST, 0U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->PLLCR0, regVal );
    regVal2 = CSL_REG32_RD( &pCfg->pEmifPhyRegs->PGCR1 );
    CSL_FINS( regVal2, EMIF_PHYCFG_PGCR1_PHYHRST, 0U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->PGCR1, regVal2 );
    CSL_FINS( regVal2, EMIF_PHYCFG_PGCR1_PHYHRST, 1U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->PGCR1, regVal2 );
    CSL_FINS( regVal, EMIF_PHYCFG_PLLCR0_PLLPD, 1U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->PLLCR0, regVal );
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->DX8SLBPLLCR0, EMIF_PHYCFG_DX8SLBPLLCR0_PLLPD, 1U );
    /*-------------------------------------------------------------------------
     *  STEP 3 : Trigger PIR[ZCAL,DCAL, DRAMINIT,DRAMRST]
     *  Host triggers DCAL, ZCAL, DRAM Initialization and DRAM reset using PIR
     *  register
     *-----------------------------------------------------------------------*/
    regVal = CSL_EMIF_PHYCFG_PIR_ZCAL_MASK          |
             CSL_EMIF_PHYCFG_PIR_DCAL_MASK          |
             CSL_EMIF_PHYCFG_PIR_DRAMINIT_MASK      |
             CSL_EMIF_PHYCFG_PIR_DRAMRST_MASK;
    CSL_emifStartPhyInit( pCfg, regVal );
    /*-------------------------------------------------------------------------
     *  STEP 4 : Wait for PGSR0[IDONE] = 1\
     *  Host waits for PGSR0.IDONE = 1'b1
     *-----------------------------------------------------------------------*/
    CSL_emifWaitForPhyInitDone( pCfg, CSL_EMIF_PHYCFG_PGSR0_IDONE_MASK );
    /*-------------------------------------------------------------------------
     *  STEP 5 : Ensure DFI interface is quiet
     *  Host ensures DFI interface is quiet (i.e. controller CKE and RESET are in
     *  inactive state)
     *-----------------------------------------------------------------------*/
    /*-------------------------------------------------------------------------
     *  STEP 6 : Pause MDL calibrations
     *  Host programs PIR[29] (DCALPSE) = 1'b1 to pause the MDL calibrations
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->PIR, EMIF_PHYCFG_PIR_DCALPSE, 1U );
    /*-------------------------------------------------------------------------
     *  STEP 7 : Enable VT inhibit
     *  Host enables VT Inhibit by programming register bit PGCR6[0] (INHVT) = 1'b1
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->PGCR6, EMIF_PHYCFG_PGCR6_INHVT, 1U );
    /*-------------------------------------------------------------------------
     *  STEP 8 : Load mode MR13 FSP-OP, FSP-WR and VRCG to 1 from schcr1.
     *  (MR13[FSP-OP]=1, MR13[FSP-WR]= 1 and MR13[VRCG]=1)
     *  Host Programs PUB MR13[7](FSP-OP) = 1'b1.
     *  Host programs SCHCR1.ADDR= 20'h0C80D to set MR13[7]-FSPOP back to 1'b1,
     *  SCHCR0.CMD = LOAD_MODE and SCHCR0.SCHTRIG to 1.
     *  Wait for tMRD to complete the command execution
     *-----------------------------------------------------------------------*/
    regVal = CSL_FMK( EMIF_PHYCFG_SCHCR1_ALLRANK, 1U )      |
             CSL_FMK( EMIF_PHYCFG_SCHCR1_SCADDR, 0xC80DU );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->SCHCR1, regVal );
    regVal = CSL_FMK( EMIF_PHYCFG_SCHCR0_CMD, 1U )          |
             CSL_FMK( EMIF_PHYCFG_SCHCR0_SCHTRIG, 1U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->SCHCR0, regVal );
    /*-------------------------------------------------------------------------
     *  STEP 9 : Program SCHCR0[SP_CMD] = CKE_LOW
     *  Host Programs SCHCR1[2] (ALLRANK)= 1'b1, SCHCR0[7:4](CMD) = SPECIAL_COMMAND,
     *  SCHCR0[11:8](SP_CMD) = CKE_LO and SCHCR0.SCHTRIG to 1 to bring dram CKE low
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->SCHCR1, EMIF_PHYCFG_SCHCR1_ALLRANK, 1U );
    regVal = CSL_FMK( EMIF_PHYCFG_SCHCR0_CMD, 7U )          |
             CSL_FMK( EMIF_PHYCFG_SCHCR0_SP_CMD, 2U )       |
             CSL_FMK( EMIF_PHYCFG_SCHCR0_SCHTRIG, 1U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->SCHCR0, regVal );
    /*-------------------------------------------------------------------------
     *  STEP 10 : Wait for 16 ctrl_clks to allow CKE to go low
     *      wait 16 @ctrl_clk;
     *-----------------------------------------------------------------------*/
    pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CTL, 16U );
    /*-------------------------------------------------------------------------
     *  STEP 11 : If FA requires PLL, remove PLL Bypass
     *-----------------------------------------------------------------------*/
    regVal = CSL_REG32_RD( &pCfg->pEmifPhyRegs->PLLCR0 );
    CSL_FINS( regVal, EMIF_PHYCFG_PLLCR0_PLLBYP, 0U );
    CSL_FINS( regVal, EMIF_PHYCFG_PLLCR0_PLLPD, 0U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->PLLCR0, regVal );
    regVal = CSL_REG32_RD( &pCfg->pEmifPhyRegs->DX8SLBPLLCR0 );
    CSL_FINS( regVal, EMIF_PHYCFG_DX8SLBPLLCR0_PLLBYP, 0U );
    CSL_FINS( regVal, EMIF_PHYCFG_DX8SLBPLLCR0_PLLPD, 0U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->DX8SLBPLLCR0, regVal );
    /*-------------------------------------------------------------------------
     *  STEP 12 : Switching to FA frequency
     *  Host/System switch from tCKb (boot clock) to FA (functional clock)
     *-----------------------------------------------------------------------*/
    if( pCfg->sdramPhyCfgCbFxnPtr != NULL )
    {
        pCfg->sdramPhyCfgCbFxnPtr( pCfg );
    }
    /*-------------------------------------------------------------------------
     *  STEP 13 : Unpause MDL calibrations
     *  Host programs PIR[29] (DCALPSE) = 1'b0 to resume the MDL calibrations
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->PIR, EMIF_PHYCFG_PIR_DCALPSE, 0U );
    /*-------------------------------------------------------------------------
     *  STEP 14 : Clear PGCR2.CLRZCAL and trigger PIR[PLLINIT, DCAL, PHYRST] for FA
     *  Host programs PGCR2.CLRZCAL=1 to perform ZQ calibration and performs DCAL,
     *  PLL init (if required) and phyrst using PIR
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->PGCR2, EMIF_PHYCFG_PGCR2_CLRZCAL, 1U );
    regVal = CSL_EMIF_PHYCFG_PIR_PLLINIT_MASK       |
             CSL_EMIF_PHYCFG_PIR_DCAL_MASK          |
             CSL_EMIF_PHYCFG_PIR_PHYRST_MASK;
    CSL_emifStartPhyInit( pCfg, regVal );
    /*-------------------------------------------------------------------------
     *  STEP 15 : Wait for PGSR0[IDONE] and PGSR0[ZCDONE]
     *  Host waits for PGSR0.IDONE=1 and PGSR0.ZCDONE=1'b1.
     *-----------------------------------------------------------------------*/
    CSL_emifWaitForPhyInitDone( pCfg, CSL_EMIF_PHYCFG_PGSR0_IDONE_MASK | CSL_EMIF_PHYCFG_PGSR0_ZCDONE_MASK );
    /*-------------------------------------------------------------------------
     *  STEP 16 : Disable Inhibit VT drift (enable VT drift)
     *  Host disables VT Inhibit by programming register bit PGCR6[0] (INHVT) = 1'b0
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->PGCR6, EMIF_PHYCFG_PGCR6_INHVT, 0U );
    /*-------------------------------------------------------------------------
     *  STEP 17 : SCHCR0[SP_CMD] = CKE_HI
     *  Host Programs SCHCR1[2](ALLRANK) = 1'b1, SCHCR0.SCHTRIG to 1,
     *  SCHCR0[7:4](CMD) = SPECIAL_COMMAND and SCHCR0[11:8](SP_CMD) = CKE_HI
     *  to bring CKE high.
     *  Wait for 16 ctrl_clks to complete the command execution
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->SCHCR1, EMIF_PHYCFG_SCHCR1_ALLRANK, 1U );
    regVal = CSL_FMK( EMIF_PHYCFG_SCHCR0_CMD, 7U )          |
             CSL_FMK( EMIF_PHYCFG_SCHCR0_SP_CMD, 3U )       |
             CSL_FMK( EMIF_PHYCFG_SCHCR0_SCHTRIG, 1U );
    CSL_REG32_WR( &pCfg->pEmifPhyRegs->SCHCR0, regVal );
    pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CTL, 16U );
    /*-------------------------------------------------------------------------
     *  STEP 18 : PGCR1[PUBMODE] = 1, to allow controller traffic
     *  Host Programs PGCR1[6](PUBMODE) = 1'b0 to allow controller traffic
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->PGCR1, EMIF_PHYCFG_PGCR1_PUBMODE, 0U );
    /*-------------------------------------------------------------------------
     *  To prevent X's driven on DQS bus for unused lanes (reference Solvnet
     *  8000993071) we configure the DQS registers here after a good clock
     *  has been established.
     *-----------------------------------------------------------------------*/
    CSL_emifConfigDqsRegisters( pCfg );
    /*-------------------------------------------------------------------------
     *  STEP 19 : Host performs all required trainings
     *  Host performs all required trainings (except dram init) on FA using PIR
     *  registers
     *-----------------------------------------------------------------------*/
    if( pCfg->dataTraining != 0U )
    {
        retVal = CSL_emifDoDataTraining( pCfg );
    }
    /*-------------------------------------------------------------------------
     *  Controller write RFSHCTL3
     *-----------------------------------------------------------------------*/
    CSL_emifEnableAutoRefresh( pCfg );
    /*-------------------------------------------------------------------------
     *  STEP 20 : Enable dfi_init_complete
     *  Host enables dfi_init_complete generation PGCR1[17](DISDIC) = 1'b0
     *-----------------------------------------------------------------------*/
    CSL_REG32_FINS( &pCfg->pEmifPhyRegs->PGCR1, EMIF_PHYCFG_PGCR1_DISDIC, 0U );
    return retVal;
}

/*=============================================================================
 *  CSL_emifGetRevision
 *
 *  This function returns the revision of the EMIF subsystem module.
 *===========================================================================*/
uint32_t CSL_emifGetRevision(CSL_EmifConfig *pCfg)
{
    return CSL_REG32_RD(&pCfg->pEmifSsRegs->SS_ID_REV_REG);
}

/*=============================================================================
 *  CSL_emifGetOperatingMode
 *
 *  This function returns the current operating mode of the EMIF.
 *===========================================================================*/
CSL_EmifOperatingMode CSL_emifGetOperatingMode(CSL_EmifConfig *pCfg)
{
    return (CSL_EmifOperatingMode)CSL_REG32_FEXT( &pCfg->pEmifCtlRegs->STAT, EMIF_CTLCFG_STAT_OPERATING_MODE );
}

/*=============================================================================
 *  CSL_emifMapSdramAddrBits
 *
 *  This function maps HIF address bits (specified by a bitmask) to the
 *  specified type of DDR address bits.
 *===========================================================================*/
void CSL_emifMapSdramAddrBits(CSL_EmifConfig *pCfg, CSL_EmifSdramAddrBits ddrAddrBitType, uint32_t hifAddrBitMask)
{
    uint8_t bitPos[32];
    bool    bContiguous;

    CSL_emifGetSetBitPositions( hifAddrBitMask, bitPos );
    switch( ddrAddrBitType )
    {
        case CSL_EMIF_SDRAM_ADDR_BITS_COLUMN:
           CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP2,
                CSL_FMK( EMIF_CTLCFG_ADDRMAP2_ADDRMAP_COL_B2, (bitPos[2]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[2]-2U) )        |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP2_ADDRMAP_COL_B3, (bitPos[3]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[3]-3U) )        |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP2_ADDRMAP_COL_B4, (bitPos[4]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[4]-4U) )        |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP2_ADDRMAP_COL_B5, (bitPos[5]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[5]-5U) ) );
            CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP3,
                CSL_FMK( EMIF_CTLCFG_ADDRMAP3_ADDRMAP_COL_B6, (bitPos[6]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[6]-6U) )        |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP3_ADDRMAP_COL_B7, (bitPos[7]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[7]-7U) )        |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP3_ADDRMAP_COL_B8, (bitPos[8]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[8]-8U) )        |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP3_ADDRMAP_COL_B9, (bitPos[9]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[9]-9U) ) );
            CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP4,
                CSL_FMK( EMIF_CTLCFG_ADDRMAP4_ADDRMAP_COL_B10, (bitPos[10]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[10]-10U) )    |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP4_ADDRMAP_COL_B11, (bitPos[11]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[11]-11U)) );
            break;
        case CSL_EMIF_SDRAM_ADDR_BITS_BANK:
            CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP1,
                CSL_FMK( EMIF_CTLCFG_ADDRMAP1_ADDRMAP_BANK_B0, (bitPos[0]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0x1FU) : ((uint32_t)bitPos[0]-2U) )      |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP1_ADDRMAP_BANK_B1, (bitPos[1]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0x1FU) : ((uint32_t)bitPos[1]-3U) )      |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP1_ADDRMAP_BANK_B2, (bitPos[2]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0x1FU) : ((uint32_t)bitPos[2]-4U) ) );
            break;
        case CSL_EMIF_SDRAM_ADDR_BITS_ROW:
            bContiguous = CSL_emifAreBitsContiguous(bitPos,2,10);
            CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP5,
                CSL_FMK( EMIF_CTLCFG_ADDRMAP5_ADDRMAP_ROW_B0, (bitPos[0]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[0]-6U) )        |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP5_ADDRMAP_ROW_B1, (bitPos[1]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[1]-7U) )        |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP5_ADDRMAP_ROW_B2_10, (bContiguous)                ? ((uint32_t)bitPos[2]-8U) : (uint32_t)(0xF) )       |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP5_ADDRMAP_ROW_B11, (bitPos[11]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[11]-17U) ) );
            CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP6,
                CSL_FMK( EMIF_CTLCFG_ADDRMAP6_ADDRMAP_ROW_B12, (bitPos[12]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[12]-18U) )    |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP6_ADDRMAP_ROW_B13, (bitPos[13]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[13]-19U) )    |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP6_ADDRMAP_ROW_B14, (bitPos[14]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[14]-20U) )    |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP6_ADDRMAP_ROW_B15, (bitPos[15]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[15]-21U) )    |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP6_LPDDR3_6GB_12GB, (uint32_t)0 ) );
            CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP7,
                CSL_FMK( EMIF_CTLCFG_ADDRMAP7_ADDRMAP_ROW_B16, (bitPos[16]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[16]-22U) )    |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP7_ADDRMAP_ROW_B17, (bitPos[17]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[17]-23U) ) );
            if( !bContiguous )
            {
                CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP9,
                    CSL_FMK( EMIF_CTLCFG_ADDRMAP9_ADDRMAP_ROW_B2, (bitPos[2]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[2]-8U) )    |
                    CSL_FMK( EMIF_CTLCFG_ADDRMAP9_ADDRMAP_ROW_B3, (bitPos[3]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[3]-9U) )    |
                    CSL_FMK( EMIF_CTLCFG_ADDRMAP9_ADDRMAP_ROW_B4, (bitPos[4]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[4]-10U) )   |
                    CSL_FMK( EMIF_CTLCFG_ADDRMAP9_ADDRMAP_ROW_B5, (bitPos[5]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[5]-11U) ) );
                CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP10,
                    CSL_FMK( EMIF_CTLCFG_ADDRMAP10_ADDRMAP_ROW_B6, (bitPos[6]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[6]-12U) )  |
                    CSL_FMK( EMIF_CTLCFG_ADDRMAP10_ADDRMAP_ROW_B7, (bitPos[7]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[7]-13U) )  |
                    CSL_FMK( EMIF_CTLCFG_ADDRMAP10_ADDRMAP_ROW_B8, (bitPos[8]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[8]-14U) )  |
                    CSL_FMK( EMIF_CTLCFG_ADDRMAP10_ADDRMAP_ROW_B9, (bitPos[9]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[9]-15U) ) );
                CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP11,
                    CSL_FMK( EMIF_CTLCFG_ADDRMAP11_ADDRMAP_ROW_B10,(bitPos[10]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0xFU) : ((uint32_t)bitPos[10]-16U) ) );
            }
            break;
        case CSL_EMIF_SDRAM_ADDR_BITS_RANK:
            CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP0,
                CSL_FMK( EMIF_CTLCFG_ADDRMAP0_ADDRMAP_CS_BIT0, (bitPos[0]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0x1FU) : ((uint32_t)bitPos[0]-6U) ) );
            break;
        case CSL_EMIF_SDRAM_ADDR_BITS_GROUP:
            CSL_REG32_WR(&pCfg->pEmifCtlRegs->ADDRMAP8,
                CSL_FMK( EMIF_CTLCFG_ADDRMAP8_ADDRMAP_BG_B0, (bitPos[0]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0x1FU) : ((uint32_t)bitPos[0]-2U) )      |
                CSL_FMK( EMIF_CTLCFG_ADDRMAP8_ADDRMAP_BG_B1, (bitPos[1]==CSL_EMIF_UNDEFINED) ? (uint32_t)(0x1FU) : ((uint32_t)bitPos[1]-3U) ) );
            break;
        case CSL_EMIF_SDRAM_ADDR_BITS_INVALID:
        default:
            break;
    }
}

/*=============================================================================
 *  CSL_emifForceMemoryEccError
 *
 *  This function enables the forcing of a memory ECC error whenever
 *  a memory address is written to that matches the CSL_EmifForceMemEccErrorCfg
 *  parameters provided to the CSL_emifConfig function.
 *===========================================================================*/
void CSL_emifForceMemoryEccError(CSL_EmifConfig *pCfg, bool bSecType)
{
    CSL_emifInitiateQuasiDynamicWrite(pCfg, 3);
    CSL_REG32_WR( &pCfg->pEmifCtlRegs->ECCCFG1,
            CSL_FMK( EMIF_CTLCFG_ECCCFG1_DATA_POISON_EN,  (uint32_t)1U )                |
            CSL_FMK( EMIF_CTLCFG_ECCCFG1_DATA_POISON_BIT, bSecType==(bool)true ? (uint32_t)1U : (uint32_t)0U )
    );
    CSL_emifTerminateQuasiDynamicWrite(pCfg, 3);
}

/*=============================================================================
 *  CSL_emifEnablePowerSaving
 *
 *  This function enables the power saving mode(s) specified in the provided
 *  CSL_EmifPowerSavingCfg structure.
 *===========================================================================*/
int32_t CSL_emifEnablePowerSaving( CSL_EmifConfig *pCfg, CSL_EmifPowerSavingCfg *pPowerSavingCfg )
{
    int32_t     retVal = 0;
    uint32_t    modes, timeoutClocksPowerDown, timeoutClocksSelfRefresh, bDisableSdramClk;

    /*-------------------------------------------------------------------------
     *  Initialize configuration options. Use defaults if pPowerSavingCfg
     *  is (void *)0.
     *-----------------------------------------------------------------------*/
    if( pPowerSavingCfg == (void *)0 )
    {
        modes                       = ((uint32_t)CSL_EMIF_POWER_SAVING_MODE_POWER_DOWN | (uint32_t)CSL_EMIF_POWER_SAVING_MODE_SELF_REFRESH);
        timeoutClocksPowerDown      = (uint32_t)0x10U << 5;
        timeoutClocksSelfRefresh    = (uint32_t)0x40U << 5;
        bDisableSdramClk            = (bool)true;
    }
    else
    {
        modes                       = pPowerSavingCfg->modes;
        timeoutClocksPowerDown      = pPowerSavingCfg->timeoutClocksPowerDown;
        timeoutClocksSelfRefresh    = pPowerSavingCfg->timeoutClocksSelfRefresh;
        bDisableSdramClk            = pPowerSavingCfg->bDisableSdramClk;
    }
    /*-------------------------------------------------------------------------
     *  Validate parameters:
     *  - At least one power saving mode must be specified
     *  - timeoutClocksSelfRefresh must be >= timeoutClocksPowerDown if both
     *    power down and self refresh modes are specified
     *-----------------------------------------------------------------------*/
    if( (modes == 0U)     ||
        ((modes == ((uint32_t)CSL_EMIF_POWER_SAVING_MODE_POWER_DOWN | (uint32_t)CSL_EMIF_POWER_SAVING_MODE_SELF_REFRESH)) &&
        (timeoutClocksSelfRefresh < timeoutClocksPowerDown)) )
    {
        retVal = -1;
    }
    else
    {
        uint32_t regVal;
        /*---------------------------------------------------------------------
         *  Configure PWRTMG
         *-------------------------------------------------------------------*/
        regVal = CSL_FMK( EMIF_CTLCFG_PWRTMG_POWERDOWN_TO_X32, (timeoutClocksPowerDown >> 5) )    |
                 CSL_FMK( EMIF_CTLCFG_PWRTMG_SELFREF_TO_X32,   (timeoutClocksSelfRefresh >> 5) );
        CSL_REG32_WR( &pCfg->pEmifCtlRegs->PWRTMG, regVal );
        /*---------------------------------------------------------------------
         *  Configure PWRCTL
         *-------------------------------------------------------------------*/
        regVal = 0;
        if( (modes & (uint32_t)CSL_EMIF_POWER_SAVING_MODE_POWER_DOWN) != 0U )
        {
            regVal |= CSL_FMK( EMIF_CTLCFG_PWRCTL_POWERDOWN_EN, 1U );
        }
        if( (modes & (uint32_t)CSL_EMIF_POWER_SAVING_MODE_SELF_REFRESH) != 0U )
        {
            regVal |= CSL_FMK( EMIF_CTLCFG_PWRCTL_SELFREF_EN, 1U );
        }
        regVal |= CSL_FMK( EMIF_CTLCFG_PWRCTL_EN_DFI_DRAM_CLK_DISABLE, (bDisableSdramClk==(bool)true) ? (uint32_t)1U : (uint32_t)0U );
        CSL_REG32_WR( &pCfg->pEmifCtlRegs->PWRCTL, regVal );
    }
    return retVal;
}

/*=============================================================================
 *  CSL_emifDisablePowerSaving
 *
 *  This function disables all power saving modes.
 *===========================================================================*/
void CSL_emifDisablePowerSaving( CSL_EmifConfig *pCfg )
{
    CSL_REG32_WR( &pCfg->pEmifCtlRegs->PWRTMG, 0 );
}

/*=============================================================================
 *  CSL_emifEnterSelfRefresh
 *
 *  This function is used to enter software self refresh mode.
 *===========================================================================*/
void CSL_emifEnterSelfRefresh(CSL_EmifConfig *pCfg)
{
    uint32_t statVal;

    CSL_emifToggleSelfRefreshSwEnable(pCfg, (bool)true);
    /*-------------------------------------------------------------------------
     *  Poll STAT until it is
     *  CSL_EMIF_CTLCFG_STAT_SELFREF_TYPE_NON_AUTO_SELFREF (3U) (none-auto self-refresh)
     *-----------------------------------------------------------------------*/
    do {
        pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CFG, 100 );
        statVal = CSL_REG32_RD( &pCfg->pEmifCtlRegs->STAT );
        if( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4 )
        {
            statVal = CSL_FEXT( statVal, EMIF_CTLCFG_STAT_SELFREF_STATE );
        }
        else
        {
            statVal = CSL_FEXT( statVal, EMIF_CTLCFG_STAT_SELFREF_TYPE );
        }
    } while( statVal != CSL_EMIF_CTLCFG_STAT_SELFREF_TYPE_NON_AUTO_SELFREF );
}

/*=============================================================================
 *  CSL_emifExitSelfRefresh
 *
 *  This function is used to exit software self refresh mode.
 *===========================================================================*/
void CSL_emifExitSelfRefresh(CSL_EmifConfig *pCfg)
{
    uint32_t statVal;

    CSL_emifToggleSelfRefreshSwEnable(pCfg, (bool)false);
    /*-------------------------------------------------------------------------
     *  Poll STAT.selfref_type until it is
     *  CSL_EMIF_CTLCFG_STAT_SELFREF_TYPE_NOT_IN_SELFREF (0) (no self-refresh)
     *-----------------------------------------------------------------------*/
    do {
        pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CFG, 100 );
        statVal = CSL_REG32_FEXT( &pCfg->pEmifCtlRegs->STAT, EMIF_CTLCFG_STAT_SELFREF_TYPE );
    } while( statVal != CSL_EMIF_CTLCFG_STAT_SELFREF_TYPE_NOT_IN_SELFREF );
}

/*=============================================================================
 *  CSL_emifConfig
 *
 *  This function performs the proper configuration sequence for the SDRAM
 *  controller and PHY per the specified configuration parameters.
 *===========================================================================*/
int32_t CSL_emifConfig(CSL_EmifConfig *pCfg)
{
    int32_t  retVal = CSL_EMIF_CONFIG_RETURN_OK;

    if( CSL_emifIsEmifConfigValid( pCfg ) == (bool)true )
    {
        /*---------------------------------------------------------------------
         *  Calculate SDRAM timings required for further configuration steps
         *-------------------------------------------------------------------*/
        CSL_emifCalcSdramTimings( pCfg, &sdramTimings );
        /*---------------------------------------------------------------------
         *  Configure the DDR Subsystem
         *-------------------------------------------------------------------*/
        CSL_emifConfigSubsystem( pCfg );
        /*---------------------------------------------------------------------
         *  0. Assert reset signal core_ddrc_rstn
         *-------------------------------------------------------------------*/
        CSL_emifAssertCoreReset( pCfg );
        /*---------------------------------------------------------------------
         *  1. Program the DWC_ddr_umctl2 registers
         *-------------------------------------------------------------------*/
        CSL_emifConfigController( pCfg, &sdramTimings );
        /*---------------------------------------------------------------------
         *  3. Disable auto-refreshes, self-refresh and powerdown by setting
         *     RFSHCTL3.dis_auto_refresh = 1 and PWRCTL.powerdown_en = 0
         *-------------------------------------------------------------------*/
        CSL_emifDisableAutoRefresh( pCfg );
        /*---------------------------------------------------------------------
         *  4. Set SWCTL.sw_done to 0
         *  5. Set DFIMISC.dfi_init_complete_en to 0 (mask transitions in
         *     phy_dfi_init_complete during initialization)
         *  6. Set SWCTL.sw_done to 1
         *-------------------------------------------------------------------*/
        /*---------------------------------------------------------------------
         *  2. Deassert reset signal core_ddrc_rstn (required to write to PHY
         *     registers). Wait 100 ctl cycles for reset deassertion to complete.
         *-------------------------------------------------------------------*/
        CSL_emifDeassertCoreReset( pCfg );
        pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CTL, 100 );
        /*---------------------------------------------------------------------
         *  7. Start PHY initialization by accessing relevant PUB registers
         *     (for example, DXnGCR, DCR, PTR*, MR*, DTPR*)
         *-------------------------------------------------------------------*/
        CSL_emifConfigPhy( pCfg, &sdramTimings );

        if( pCfg->pSdramParms->type == CSL_EMIF_SDRAM_TYPE_LPDDR4 )
        {
            /*---------------------------------------------------------------------
             *  If using an LPDDR4 device, perform the slow boot clock bring-up
             *  sequence.
             *-------------------------------------------------------------------*/
            retVal = CSL_emifLpddr4Boot( pCfg );
        }
        else
        {
            /*---------------------------------------------------------------------
             *  8. Trigger PHY initialization: PHY initialization is comprised of
             *     initializing the PHY PLL(s), running the initial impedance
             *     calibration, and running delay line calibration. These functions
             *     can all be triggerd at the same time by writing PIR = x0000_0033.
             *  9. Monitor PHY initialization status by polling the PUB register
             *     PGSR0.IDONE
             *-------------------------------------------------------------------*/
            retVal = CSL_emifDoPhyInit( pCfg );
            if( retVal == CSL_EMIF_CONFIG_RETURN_OK )
            {
                /*---------------------------------------------------------------------
                 *  Perform any optional post PHY init configuration if a callback function
                 *  is defined.
                 *-------------------------------------------------------------------*/
                if( pCfg->sdramPhyCfgCbFxnPtr != NULL )
                {
                    pCfg->sdramPhyCfgCbFxnPtr( pCfg );
                }
                /*---------------------------------------------------------------------
                 * 10. Indicate to the PUB that the controller performs SDRAM
                 *     initialization by setting PIR.INIT and PIR.CTLDINIT, and poll
                 *     PGSR0.IDONE
                 * 11. Set SWCTL.sw_done to 0 phy_init
                 * 12. Set DFIMISC.dfi_init_complete_en to 1. DWC_ddr_umctl2 waits
                 *     for phy_dfi_init_complete to be asserted.
                 * 13. Set SWCTL.sw_done to 1
                 *-------------------------------------------------------------------*/
                CSL_emifDoSdramInit( pCfg );
                /*---------------------------------------------------------------------
                 * 14. Wait for DWC_ddr_umctl2 to move to normal operating mode by
                 *     monitoring STAT.operating_mode signal
                 *-------------------------------------------------------------------*/
                while( CSL_emifGetOperatingMode(pCfg) != CSL_EMIF_OPERATING_MODE_NORMAL )
                {
                    pCfg->delayClockCyclesCbFxnPtr( CSL_EMIF_CLOCK_TYPE_CFG, 100 );
                }
                /*---------------------------------------------------------------------
                 *  To prevent X's driven on DQS bus for unused lanes (reference Solvnet
                 *  8000993071) we configure the DQS registers here after a good clock
                 *  has been established.
                 *-------------------------------------------------------------------*/
                CSL_emifConfigDqsRegisters( pCfg );
                /*---------------------------------------------------------------------
                 * 15. Program PUB's DTCR0 to enable refreshes during training
                 *     and to specify which ranks to train
                 * 16. Configure PUB PIR register to specify which training steps to run
                 * 17. Monitor PUB PGSR.IDONE to poll for completion of training sequence
                 *-------------------------------------------------------------------*/
                if( pCfg->dataTraining != 0U )
                {
                    retVal = CSL_emifDoDataTraining( pCfg );
                }
                /*---------------------------------------------------------------------
                 * 18. Set back registers in step 3 to the original values if desired
                 *-------------------------------------------------------------------*/
                CSL_emifEnableAutoRefresh( pCfg );
            }
        }
    }
    else
    {
        retVal = CSL_EMIF_CONFIG_RETURN_INVALID_CFG;
    }
    return retVal;
}
