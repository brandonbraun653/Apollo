/**
 * \file   elm.c
 *
 * \brief  This file contains the Device Abstraction Layer(DAL) APIs
 *         for ELM module. These APIs are used for configuration
 *         of the module and Error location processing from the given input
 *         syndrome polynomial.
 */

/**
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

#include "types.h"
#include "hw_types.h"
#include "hw_elm.h"
#include "elm.h"

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None. */

/*****************************************************************************
**                FUNCTION DEFINITIONS
*****************************************************************************/

uint32_t ELMGetRevision(uint32_t baseAddr)
{
    uint32_t revision;

    revision = HW_RD_REG32(baseAddr + ELM_REVISION);

    /* Return the IP revision of the ELM. */
    return revision;
}

void ELMModuleReset(uint32_t baseAddr)
{
    /* Initiate the soft reset of the module. */
    HW_WR_FIELD32(baseAddr + ELM_SYSCONFIG, ELM_SYSCONFIG_SOFTRESET,
        ELM_SYSCONFIG_SOFTRESET_RESET);

    /* Wait until the process of Module Reset is complete. */
    while(ELM_SYSSTS_RESETDONE_RST_DONE !=
        HW_RD_FIELD32(baseAddr + ELM_SYSSTS, ELM_SYSSTS_RESETDONE));
}

uint32_t ELMModuleIsResetDone(uint32_t baseAddr)
{
    uint32_t status = FALSE;

    if(ELM_SYSSTS_RESETDONE_RST_DONE ==
        HW_RD_FIELD32(baseAddr + ELM_SYSSTS, ELM_SYSSTS_RESETDONE))
    {
        status = TRUE;
    }

    return status;
}

void ELMSetBchEccLevel(uint32_t baseAddr, uint32_t eccLevel)
{
    /* Set the Error Correction Level for the BCH algorithm. */
    HW_WR_FIELD32(baseAddr + ELM_LOCATION_CONFIG,
        ELM_LOCATION_CONFIG_ECC_BCH_LEVEL, eccLevel);
}

void ELMSetEccBufSize(uint32_t baseAddr, uint32_t eccBufSize)
{
    /* Set the maximum buffer size for which the ECC engine is to be used. */
    HW_WR_FIELD32(baseAddr + ELM_LOCATION_CONFIG, ELM_LOCATION_CONFIG_ECC_SIZE,
        eccBufSize);
}

void ELMSetContinuousMode(uint32_t baseAddr)
{
    /* Clear the sector bits to enable the Continuous mode. */
    HW_WR_REG32(baseAddr + ELM_PAGE_CTRL, 0x00);
}

void ELMSetPageMode(uint32_t baseAddr, uint32_t sectorNum)
{
    uint32_t regVal = 0U;
    /*
    ** Set the ELM in page mode and enable the sector to link a polynomial
    ** to a particular page.
    */
    regVal = HW_RD_REG32(baseAddr + ELM_PAGE_CTRL);
    regVal |= sectorNum;
    HW_WR_REG32(baseAddr + ELM_PAGE_CTRL, regVal);
}

void ELMSetSyndromeFragment(uint32_t baseAddr,
                            uint32_t syndromeFragment,
                            uint32_t syndromePolyNum,
                            uint32_t fragmentId)
{
    /* If the fragment id is not 6 then use the same mask for all fragments. */
    if(6U != fragmentId)
    {
        HW_WR_FIELD32(baseAddr +
            ELM_SYNDROME_FRAGMENT(fragmentId, syndromePolyNum),
            ELM_SYNDROME_FRAGMENT_0, syndromeFragment);
    }
    else
    {
        HW_WR_FIELD32(baseAddr +
            ELM_SYNDROME_FRAGMENT(fragmentId, syndromePolyNum),
            ELM_SYNDROME_FRAGMENT_6, syndromeFragment);
    }
}

void ELMErrLocProcessingStart(uint32_t baseAddr, uint32_t syndromePolyNum)
{
    /* Initiate the processing of syndrome polynomial. */
    HW_WR_FIELD32(baseAddr + ELM_SYNDROME_FRAGMENT_6(syndromePolyNum),
        ELM_SYNDROME_FRAGMENT_6_VALID,
        ELM_SYNDROME_FRAGMENT_6_VALID_ENABLE_PROCESS);
}

uint32_t ELMErrLocProcessStatus(uint32_t baseAddr, uint32_t syndromePolyNum)
{
    uint32_t status = 0U;

    /* Get the status of the Error location process. */
    status = HW_RD_FIELD32(baseAddr + ELM_LOCATION_STS(syndromePolyNum),
                ELM_LOCATION_STS_ECC_CORRECTABL);

    return status;
}

uint32_t ELMGetNumErrors(uint32_t baseAddr, uint32_t syndromePolyNum)
{
    uint32_t errNum = 0U;

    /* The number of errors located for the particular syndrome polynomial. */
    errNum  = HW_RD_FIELD32(baseAddr + ELM_LOCATION_STS(syndromePolyNum),
                ELM_LOCATION_STS_ECC_NB_ERRORS);

    return errNum;
}

uint32_t ELMGetErrAddress(uint32_t baseAddr,
                          uint32_t syndromePolyNum,
                          uint32_t errRegNum)
{
    uint32_t errAddr = 0U;

    /* The number of errors located for the particular syndrome polynomial. */
    errAddr  = HW_RD_FIELD32(baseAddr +
                ELM_ERROR_LOCATION(errRegNum, syndromePolyNum),
                ELM_LOCATION_STS_ECC_NB_ERRORS);

    return errAddr;
}

void ELMIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    /* Enable the specified interrupt. */
    regVal = HW_RD_REG32(baseAddr + ELM_IRQEN);
    regVal |= intrMask;
    HW_WR_REG32(baseAddr + ELM_IRQEN, regVal);
}

void ELMIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    /* Disable the specified interrupt. */
    regVal = HW_RD_REG32(baseAddr + ELM_IRQEN);
    regVal &= ~intrMask;
    HW_WR_REG32(baseAddr + ELM_IRQEN, regVal);
}

uint32_t ELMIntrStatus(uint32_t baseAddr)
{
    uint32_t status = 0U;

    /* Get the ELM interrupt status. */
    status = HW_RD_REG32(baseAddr + ELM_IRQSTS);

    return status;
}

void ELMIntrClear(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    /* Clear the specific interrupt. */
    regVal = HW_RD_REG32(baseAddr + ELM_IRQSTS);
    regVal |= intrMask;
    HW_WR_REG32(baseAddr + ELM_IRQSTS, regVal);
}

void ELMAutoGatingEnable(uint32_t baseAddr, uint32_t enableAutoGating)
{
    if(TRUE == enableAutoGating)
    {
        HW_WR_FIELD32(baseAddr + ELM_SYSCONFIG, ELM_SYSCONFIG_AUTOGATING,
            ELM_SYSCONFIG_AUTOGATING_OCP_FREE);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + ELM_SYSCONFIG, ELM_SYSCONFIG_AUTOGATING,
            ELM_SYSCONFIG_AUTOGATING_OCP_GATING);
    }
}

void ELMSetIdleMode(uint32_t baseAddr, uint32_t idleMode)
{
    HW_WR_FIELD32(baseAddr + ELM_SYSCONFIG, ELM_SYSCONFIG_SIDLEMODE, idleMode);
}

void ELMSetIdleModeOcpClkActivity(uint32_t baseAddr, uint32_t clkActivity)
{
    /* Set the OCP clock activity in idle Mode. */
    HW_WR_FIELD32(baseAddr + ELM_SYSCONFIG, ELM_SYSCONFIG_CLOCKACTIVITYOCPZ,
        clkActivity);
}