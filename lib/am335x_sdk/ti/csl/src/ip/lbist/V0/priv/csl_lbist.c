/**
 * @file  csl_lbist.c
 *
 * @brief
 *  CSL-FL implementation file for the LBIST module.
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

#include <ti/csl/csl_lbist.h>
#include <ti/csl/csl_types.h>

/* Local Function prototypes */
static void CSL_LBIST_setLoadDiv(CSL_LBIST_regMapType *pRegMap);

static void CSL_LBIST_clearLoadDiv(CSL_LBIST_regMapType *pRegMap);

static void CSL_LBIST_setDivideRatio(CSL_LBIST_regMapType *pRegMap, uint32_t divideRatio);

static void CSL_LBIST_setNumStuckAtPatterns(CSL_LBIST_regMapType *pRegMap, uint32_t stuckAtPatterns);

static void CSL_LBIST_setNumSetPatterns(CSL_LBIST_regMapType *pRegMap, uint32_t setPatterns);

static void CSL_LBIST_setNumResetPatterns(CSL_LBIST_regMapType *pRegMap, uint32_t resetPatterns);

static void CSL_LBIST_setNumChainTestPatterns(CSL_LBIST_regMapType *pRegMap, uint32_t chainTestPatterns);

static void CSL_LBIST_setSeed(CSL_LBIST_regMapType *pRegMap, uint64_t seed);

static void CSL_LBIST_setClockDelay(CSL_LBIST_regMapType *pRegMap, uint32_t clockDelay);

int32_t CSL_LBIST_getMISR(CSL_LBIST_regMapType *pRegMap, uint32_t *pMISRValue)
{
    uint32_t regVal;
    uint32_t muxVal;
    int32_t status = CSL_PASS;

    if (pRegMap == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        regVal  = 0;     /* Setting to 0 also selects compact MISR in [7:0] */
        muxVal  = 0x2u;  /* The MISR value is available at two locations
                            0x2 or 0x3: Choosing location 0x2*/
        regVal |= (muxVal << 8);
        pRegMap->LBIST_STAT = regVal;
        *pMISRValue  = pRegMap->LBIST_MISR;
    }
    return status;
}

int32_t CSL_LBIST_getExpectedMISR(uint32_t *pLBISTSig, uint32_t *pEpectedMISRValue)
{
    int32_t status = CSL_PASS;

    if (pLBISTSig == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pEpectedMISRValue = *pLBISTSig;
    }
    return status;
}

int32_t CSL_LBIST_programConfig(CSL_LBIST_regMapType *pRegMap, const CSL_LBIST_config_t * const pConfig )
{
    int32_t status = CSL_PASS;

    if ((pRegMap == NULL) || (pConfig == NULL))
    {
        status = CSL_EBADARGS;
    }
    else
    {
        CSL_LBIST_setClockDelay( pRegMap, pConfig->dc_def );

        CSL_LBIST_setDivideRatio( pRegMap, pConfig->divide_ratio );

        CSL_LBIST_clearLoadDiv( pRegMap );
        CSL_LBIST_setLoadDiv( pRegMap );

        CSL_LBIST_setNumStuckAtPatterns  ( pRegMap, pConfig->static_pc_def );
        CSL_LBIST_setNumSetPatterns      ( pRegMap, pConfig->set_pc_def    );
        CSL_LBIST_setNumResetPatterns    ( pRegMap, pConfig->reset_pc_def  );
        CSL_LBIST_setNumChainTestPatterns( pRegMap, pConfig->scan_pc_def   );

        CSL_LBIST_setSeed( pRegMap, pConfig->prpg_def );
    }

    return status;
}

int32_t CSL_LBIST_enableIsolation(CSL_LBIST_regMapType *pRegMap)
{
    int32_t status = CSL_PASS;

    if (pRegMap == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        pRegMap->LBIST_SPARE0 |= 0x1u;
    }
    return status;
}

int32_t CSL_LBIST_disableIsolation(CSL_LBIST_regMapType *pRegMap)
{
    int32_t status = CSL_PASS;

    if (pRegMap == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        pRegMap->LBIST_SPARE0 &= ~(0x1u);
    }
    return status;
}

int32_t CSL_LBIST_reset(CSL_LBIST_regMapType *pRegMap)
{
    int32_t status = CSL_PASS;

    if (pRegMap == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        pRegMap->LBIST_CTRL &= ~(0x1u << 31);
    }
    return status;
}

int32_t CSL_LBIST_enableRunBISTMode(CSL_LBIST_regMapType *pRegMap)
{
    int32_t status = CSL_PASS;

    if (pRegMap == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        pRegMap->LBIST_CTRL |= (0xfu << 12);
    }
    return status;
}

int32_t CSL_LBIST_clearRunBISTMode(CSL_LBIST_regMapType *pRegMap)
{
    int32_t status = CSL_PASS;

    if (pRegMap == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        pRegMap->LBIST_CTRL &= ~(0xfu << 12);
    }
    return status;
}

int32_t CSL_LBIST_start(CSL_LBIST_regMapType *pRegMap)
{
    int32_t status = CSL_PASS;

    if (pRegMap == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        pRegMap->LBIST_CTRL |= (0x1u << 31);  /* Deassert reset */
        pRegMap->LBIST_CTRL |= (0xfu << 24);
    }
    return status;
}

int32_t CSL_LBIST_stop(CSL_LBIST_regMapType *pRegMap)
{
    int32_t status = CSL_PASS;

    if (pRegMap == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        pRegMap->LBIST_CTRL &= ~(0xfu << 24);
    }
    return status;
}


int32_t CSL_LBIST_isRunning (CSL_LBIST_regMapType *pRegMap, Bool *pIsRunning)
{
    int32_t status = CSL_PASS;

    if (pRegMap == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pIsRunning = ((pRegMap->LBIST_STAT >> 15) & 0x1u) ? CSL_TRUE : CSL_FALSE;
    }
    return status;
}

int32_t CSL_LBIST_isDone (CSL_LBIST_regMapType *pRegMap, Bool *pIsDone)
{
    int32_t status = CSL_PASS;

    if (pRegMap == NULL)
    {
        status = CSL_EBADARGS;
    }
    else
    {
        *pIsDone = ((pRegMap->LBIST_STAT >> 31) & 0x1u) ? CSL_TRUE : CSL_FALSE;
    }
    return status;
}

static void CSL_LBIST_setLoadDiv(CSL_LBIST_regMapType *pRegMap)
{
    pRegMap->LBIST_CTRL |= (0x1u << 7);
}

static void CSL_LBIST_clearLoadDiv(CSL_LBIST_regMapType *pRegMap)
{
    pRegMap->LBIST_CTRL &= ~(0x1u << 7);
}

static void CSL_LBIST_setDivideRatio(CSL_LBIST_regMapType *pRegMap,
                                     uint32_t divideRatio)
{
    pRegMap->LBIST_CTRL &= ~0x1fu;
    pRegMap->LBIST_CTRL |= (divideRatio & 0x1fu);
}

static void CSL_LBIST_setNumStuckAtPatterns(CSL_LBIST_regMapType *pRegMap,
                                            uint32_t stuckAtPatterns)
{
    pRegMap->LBIST_PATCOUNT &= ~(0x3fffu << 16);
    pRegMap->LBIST_PATCOUNT |= ((stuckAtPatterns & 0x3fffu) << 16);
}

static void CSL_LBIST_setNumSetPatterns(CSL_LBIST_regMapType *pRegMap,
                                        uint32_t setPatterns)
{
    pRegMap->LBIST_PATCOUNT &= ~(0xfu << 8);
    pRegMap->LBIST_PATCOUNT |= ((setPatterns & 0xfu) << 8);
}

static void CSL_LBIST_setNumResetPatterns(CSL_LBIST_regMapType *pRegMap,
                                          uint32_t resetPatterns)
{
    pRegMap->LBIST_PATCOUNT &= ~(0xfu << 4);
    pRegMap->LBIST_PATCOUNT |= ((resetPatterns & 0xfu) << 4);
}

static void CSL_LBIST_setNumChainTestPatterns(CSL_LBIST_regMapType *pRegMap,
                                              uint32_t chainTestPatterns)
{
    pRegMap->LBIST_PATCOUNT &= ~(0xfu << 0);
    pRegMap->LBIST_PATCOUNT |= ((chainTestPatterns & 0xfu) << 0);
}

static void CSL_LBIST_setSeed(CSL_LBIST_regMapType *pRegMap, uint64_t seed)
{
    pRegMap->LBIST_SEED0 = seed & 0xffffffffu;
    pRegMap->LBIST_SEED1 = (seed >> 32) & 0x1fffffu;
}

static void CSL_LBIST_setClockDelay(CSL_LBIST_regMapType *pRegMap,
                                    uint32_t clockDelay)
{
    pRegMap->LBIST_CTRL &= (0x3u << 8);
    pRegMap->LBIST_CTRL |= ((clockDelay & 0x3u) << 8);
}

/* Nothing past this point */
