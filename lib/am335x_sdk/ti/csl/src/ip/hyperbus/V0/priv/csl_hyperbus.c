/*
 *  Copyright (C) 2019 Texas Instruments Incorporated.
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
 *  \file     csl_hyperbus.c
 *
 *  \brief    This file contains the implementation of the APIs present in the
 *            device abstraction layer file of HyperBus.
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/csl_hyperbus.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/* None */

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

/* HyperBus subsystem registers */

/* Revision Register */

uint32_t CSL_hyperbusGetRevision(const CSL_hyperbus_syscfgRegs *pSyscfgRegs )
{
    uint32_t retVal=0;
    retVal = CSL_REG32_RD( &pSyscfgRegs->REVISION_REG);
    return retVal;
}

/* DLL Status Register */

int32_t CSL_hyperbusGetDllCode( const CSL_hyperbus_syscfgRegs *pSyscfgRegs,
                                CSL_HyperbusDllStatus *pDllStatus )
{
    pDllStatus->mdllCode = CSL_REG32_FEXT( &pSyscfgRegs->DLL_STAT_REG,
                                           HYPERBUS_SYSCFG_DLL_STAT_REG_MDLL_CODE );
    pDllStatus->mdllCodeValid = CSL_REG32_FEXT( &pSyscfgRegs->DLL_STAT_REG,
                                                HYPERBUS_SYSCFG_DLL_STAT_REG_MDLL_CODE_VALID );
    return CSL_PASS;
}

/* HyperBus Memory Control registers */

/* CSR */

int32_t CSL_hyperbusGetCtrlStatusReg( const CSL_hyperbus_coreRegs *pCoreRegs,
                                CSL_HyperbusCtrlStatusReg *pCtrlStatusReg )
{
    pCtrlStatusReg->readActive = CSL_REG32_FEXT( &pCoreRegs->CSR,
                                                 HYPERBUS_CORE_CSR_RACT );
    pCtrlStatusReg->readDecodeError = CSL_REG32_FEXT( &pCoreRegs->CSR,
                                                      HYPERBUS_CORE_CSR_RDECERR );
    pCtrlStatusReg->readTransactionError = CSL_REG32_FEXT( &pCoreRegs->CSR,
                                                           HYPERBUS_CORE_CSR_RTRSERR );
    pCtrlStatusReg->readRSTOError = CSL_REG32_FEXT( &pCoreRegs->CSR,
                                                    HYPERBUS_CORE_CSR_RRSTOERR );
    pCtrlStatusReg->rdsStall = CSL_REG32_FEXT( &pCoreRegs->CSR,
                                               HYPERBUS_CORE_CSR_RDSSTALL );
    pCtrlStatusReg->writeActive = CSL_REG32_FEXT( &pCoreRegs->CSR,
                                                  HYPERBUS_CORE_CSR_WACT );
    pCtrlStatusReg->writeDecodeError = CSL_REG32_FEXT( &pCoreRegs->CSR,
                                                       HYPERBUS_CORE_CSR_WDECERR );
    pCtrlStatusReg->writeTransactionError = CSL_REG32_FEXT( &pCoreRegs->CSR,
                                                            HYPERBUS_CORE_CSR_WTRSERR );
    pCtrlStatusReg->writeRSTOError = CSL_REG32_FEXT( &pCoreRegs->CSR,
                                                     HYPERBUS_CORE_CSR_WRSTOERR );

    return CSL_PASS;
}

/* IER */

int32_t CSL_hyperbusEnableIntr( CSL_hyperbus_coreRegs *pCoreRegs )
{
    CSL_REG32_FINS( &pCoreRegs->IER, HYPERBUS_CORE_IER_RPCINTE ,
                    CSL_HYPERBUS_INT_ENABLE );
    return CSL_PASS;
}

int32_t CSL_hyperbusDisableIntr( CSL_hyperbus_coreRegs *pCoreRegs )
{
    CSL_REG32_FINS( &pCoreRegs->IER, HYPERBUS_CORE_IER_RPCINTE ,
                    CSL_HYPERBUS_INT_DISABLE );
    return CSL_PASS;
}

/* ISR */

uint32_t CSL_hyperbusIsIntrPending( const CSL_hyperbus_coreRegs *pCoreRegs )
{
    uint32_t retVal;
    if ( CSL_REG32_FEXT( &pCoreRegs->ISR, 
                         HYPERBUS_CORE_ISR_RPCINTS ) == 1U )
    {
        retVal = TRUE;
    }
    else
    {
        retVal = FALSE;
    }

    return retVal;
}

/* MBAR */

int32_t CSL_hyperbusSetCSBaseAddr( CSL_hyperbus_coreRegs *pCoreRegs,
                                   uint32_t mbarIndex,
                                   uint32_t hyperbusCSBaseAddr )
{
    int32_t retVal = CSL_EFAIL;

    if (mbarIndex<CSL_HYPERBUS_NUM_CHIP_SELECTS)
    {
        uint32_t var_1;
        uint32_t var_2;
        var_2 = hyperbusCSBaseAddr;
        var_1 = (uint32_t)(var_2 >> 24);
        CSL_REG32_FINS( &pCoreRegs->MBAR[mbarIndex],
                        HYPERBUS_CORE_MBAR_A_MSB, var_1 );

        retVal = CSL_PASS;
    }
    return retVal;
}

/* MCR */

int32_t CSL_hyperbusSetMemConfig( CSL_hyperbus_coreRegs *pCoreRegs,
                                  uint32_t mcrIndex,
                                  const CSL_HyperbusMemConfigReg *pMemConfigReg )
{
    int32_t retVal = CSL_EFAIL;

    if (mcrIndex<CSL_HYPERBUS_NUM_CHIP_SELECTS)
    {
        /* Setting device type */
        CSL_REG32_FINS( &pCoreRegs->MCR[mcrIndex],
                        HYPERBUS_CORE_MCR_DEVTYPE, pMemConfigReg->deviceType );

        /* Setting wrap size */
        CSL_REG32_FINS( &pCoreRegs->MCR[mcrIndex],
                        HYPERBUS_CORE_MCR_WRAPSIZE, pMemConfigReg->wrapSize);

        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_hyperbusSetDeviceType( CSL_hyperbus_coreRegs *pCoreRegs,
                                   uint32_t mcrIndex,
                                   uint32_t deviceType )
{
    int32_t retVal = CSL_EFAIL;

    if (mcrIndex<CSL_HYPERBUS_NUM_CHIP_SELECTS)
    {
        /* Setting device type */
        CSL_REG32_FINS( &pCoreRegs->MCR[mcrIndex],
                        HYPERBUS_CORE_MCR_DEVTYPE, deviceType );
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_hyperbusSetMaxLen( CSL_hyperbus_coreRegs *pCoreRegs,
                               uint32_t mcrIndex,
                               const CSL_HyperbusCSMaxLength *pMaxLen )
{
    int32_t retVal = CSL_EFAIL;

    if (mcrIndex<CSL_HYPERBUS_NUM_CHIP_SELECTS)
    {
        uint32_t newBits;
        uint32_t regValue;
        uint32_t mask;
        uint32_t m;

        newBits = 0u;
        newBits |= ( pMaxLen->maxLength << CSL_HYPERBUS_CORE_MCR_MAXLEN_SHIFT );
        newBits |= ( pMaxLen->maxLengthEnable << CSL_HYPERBUS_CORE_MCR_MAXEN_SHIFT );

        regValue = CSL_REG32_RD( &pCoreRegs->MCR[mcrIndex] );

        mask = CSL_HYPERBUS_CORE_MCR_MAXEN_MASK | CSL_HYPERBUS_CORE_MCR_MAXLEN_MASK;

        m = regValue & mask; // Extract bits to be modified.
        regValue = m ^ regValue; // Zero out bits to be modified.
        regValue = regValue | newBits; // Insert new value to be written

        CSL_REG32_WR( &pCoreRegs->MCR[mcrIndex], regValue ); // Write updated value
        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_hyperbusGetMemConfig( const CSL_hyperbus_coreRegs *pCoreRegs,
                                  uint32_t mcrIndex,
                                  CSL_HyperbusMemConfigReg *pMemConfigReg )
{
    int32_t retVal = CSL_EFAIL;

    if (mcrIndex<CSL_HYPERBUS_NUM_CHIP_SELECTS)
    {
        pMemConfigReg->deviceType = CSL_REG32_FEXT( &pCoreRegs->MCR[mcrIndex],
                                                    HYPERBUS_CORE_MCR_DEVTYPE );
        
        pMemConfigReg->wrapSize = CSL_REG32_FEXT( &pCoreRegs->MCR[mcrIndex],
                                                  HYPERBUS_CORE_MCR_WRAPSIZE );

        pMemConfigReg->configRegTarget = CSL_REG32_FEXT( &pCoreRegs->MCR[mcrIndex],
                                         HYPERBUS_CORE_MCR_CRT );

        pMemConfigReg->asymCacheSupport = CSL_REG32_FEXT( &pCoreRegs->MCR[mcrIndex],
                                          HYPERBUS_CORE_MCR_ACS );

        pMemConfigReg->contdMerge = CSL_REG32_FEXT( &pCoreRegs->MCR[mcrIndex],
                                                    HYPERBUS_CORE_MCR_TCMO );

        retVal = CSL_PASS;
    }
    return retVal;
}

/* MTR */

int32_t CSL_hyperbusSetMemTiming( CSL_hyperbus_coreRegs *pCoreRegs,
                          uint32_t mtrIndex,
                          const CSL_HyperbusMemTimingReg *pMemTimingReg )
{
    int32_t retVal = CSL_EFAIL;

    if (mtrIndex<CSL_HYPERBUS_NUM_CHIP_SELECTS)
    {
        CSL_REG32_FINS( &pCoreRegs->MTR[mtrIndex],
                        HYPERBUS_CORE_MTR_LTCY, pMemTimingReg->latency );

        CSL_REG32_FINS( &pCoreRegs->MTR[mtrIndex],
                        HYPERBUS_CORE_MTR_WCSH, pMemTimingReg->writeCSHold );

        CSL_REG32_FINS( &pCoreRegs->MTR[mtrIndex],
                        HYPERBUS_CORE_MTR_RCSH, pMemTimingReg->readCSHold );

        CSL_REG32_FINS( &pCoreRegs->MTR[mtrIndex],
                        HYPERBUS_CORE_MTR_WCSS, pMemTimingReg->writeCSSetup );

        CSL_REG32_FINS( &pCoreRegs->MTR[mtrIndex],
                        HYPERBUS_CORE_MTR_RCSS, pMemTimingReg->readCSSetup );

        CSL_REG32_FINS( &pCoreRegs->MTR[mtrIndex],
                        HYPERBUS_CORE_MTR_WCSHI, pMemTimingReg->writeCSHigh );

        CSL_REG32_FINS( &pCoreRegs->MTR[mtrIndex],
                        HYPERBUS_CORE_MTR_RCSHI, pMemTimingReg->readCSHigh );

        retVal = CSL_PASS;
    }
    return retVal;
}

int32_t CSL_hyperbusGetMemTiming( const CSL_hyperbus_coreRegs *pCoreRegs,
                                  uint32_t mtrIndex,
                                  CSL_HyperbusMemTimingReg *pMemTimingReg )
{
    int32_t retVal = CSL_EFAIL;

    if( mtrIndex<CSL_HYPERBUS_NUM_CHIP_SELECTS )
    {
        pMemTimingReg->latency = CSL_REG32_FEXT( &pCoreRegs->MTR[mtrIndex],
                                                 HYPERBUS_CORE_MTR_LTCY );

        pMemTimingReg->writeCSHold = CSL_REG32_FEXT( &pCoreRegs->MTR[mtrIndex],
                                                     HYPERBUS_CORE_MTR_WCSH );

        pMemTimingReg->readCSHold = CSL_REG32_FEXT( &pCoreRegs->MTR[mtrIndex],
                                                    HYPERBUS_CORE_MTR_RCSH );

        pMemTimingReg->writeCSSetup = CSL_REG32_FEXT( &pCoreRegs->MTR[mtrIndex],
                                                      HYPERBUS_CORE_MTR_WCSS );

        pMemTimingReg->readCSSetup = CSL_REG32_FEXT( &pCoreRegs->MTR[mtrIndex],
                                                     HYPERBUS_CORE_MTR_RCSS );

        pMemTimingReg->writeCSHigh = CSL_REG32_FEXT( &pCoreRegs->MTR[mtrIndex],
                                                     HYPERBUS_CORE_MTR_WCSHI );

        pMemTimingReg->readCSHigh = CSL_REG32_FEXT( &pCoreRegs->MTR[mtrIndex],
                                                    HYPERBUS_CORE_MTR_RCSHI );

        retVal = CSL_PASS;
    }
    return retVal;
}

/* GPOR */

/* WPR */

int32_t CSL_hyperbusSetWriteProtection( CSL_hyperbus_coreRegs *pCoreRegs,
                                        uint32_t writeProtect )
{
    CSL_REG32_FINS( &pCoreRegs->WPR, HYPERBUS_CORE_WPR_WP, 
                    writeProtect);
    return CSL_PASS;
}

/* LBR */

int32_t CSL_hyperbusSetLoopBackMode( CSL_hyperbus_coreRegs *pCoreRegs,
                                     uint32_t loopBackMode )
{
    CSL_REG32_FINS( &pCoreRegs->LBR, HYPERBUS_CORE_LBR_LOOPBACK, 
                    loopBackMode );
    return CSL_PASS;
}
