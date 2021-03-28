/* =============================================================================
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
#include <stdint.h>
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>

#include <ti/osal/osal.h>
#include "esm_app.h"


/* static global variables */
HwiP_Handle gEsmHiHwiPHandle;
HwiP_Handle gEsmLoHwiPHandle;
HwiP_Handle gEsmCfgHwiPHandle;

/* ----------------- local Function prototypes ------------------ */
static int32_t cslAppClearESMIntrStatus(uint32_t baseAddr, int32_t intNum);
static int32_t cslAppEnableIntr(uint32_t baseAddr, int32_t intNum);
static int32_t cslAppSetPri(uint32_t baseAddr, uint32_t pri, int32_t intNum);
static int32_t cslAppEnableEsmGlobalIntr(uint32_t baseAddr);
static int32_t cslAppEsmSetupHighPriHandler(uint32_t baseAddr);
static int32_t cslAppEsmSetupLowPriHandler(uint32_t baseAddr);
static void    cslAppEsmHighInterruptHandler(uintptr_t arg);
static void    cslAppEsmLowInterruptHandler(uintptr_t arg);
static void    cslAppEsmInterruptHandler (esmIntrPriorityLvl_t esmIntrPriorityLvlType,
                                           uintptr_t arg );
static void    cslAppEsmProcessInterruptSource(uintptr_t arg, uint32_t intSrc);

/* local function implementation */
static void cslAppEsmProcessInterruptSource(uintptr_t arg, uint32_t intSrc)
{

    if (intSrc != NO_EVENT_VALUE)
    {
        /* Clear this error */
        (void)ESMClearIntrStatus(((uint32_t)ESM_CFG_BASE), intSrc);
    }
    return;
}

static void cslAppEsmInterruptHandler (esmIntrPriorityLvl_t esmIntrPriorityLvlType,
                                           uintptr_t arg )
{
    uint32_t             intSrc1, intSrc2;
    esmGroupIntrStatus_t localEsmGroupIntrStatus;

    /* Check if the Interrupt caused by the RAM ID expected
       CC_MSMC_WRAP_ECC_AGGR0_MSMC_DATA_RAM_ID (56) is under Register offset 0x44
     */
      cslAppChkIsExpectedRamId(arg);

    /* Check on the highest priority event and handle it */
    do {
        (void)ESMGetGroupIntrStatus(((uint32_t)ESM_CFG_BASE), (uint32_t)esmIntrPriorityLvlType,
                              &localEsmGroupIntrStatus);
        intSrc1 = localEsmGroupIntrStatus.highestPendPlsIntNum;
        cslAppEsmProcessInterruptSource(arg, intSrc1);
        if (intSrc1 == (uint32_t) arg)
        {
            break;
        }
        intSrc2 = localEsmGroupIntrStatus.highestPendLvlIntNum;
        cslAppEsmProcessInterruptSource(arg, intSrc2);
        if (intSrc2 == (uint32_t) arg)
        {
            break;
        }
    } while ((intSrc1 != (uint32_t)(NO_EVENT_VALUE)) || (intSrc2 != (uint32_t)(NO_EVENT_VALUE)));

    return;
}

void cslAppEsmHighInterruptHandler (uintptr_t arg)
{

    /* Call common Interrupt handler */
     cslAppEsmInterruptHandler(ESM_INTR_PRIORITY_LEVEL_HIGH, MSMC_ECC_AGGR0_DED_ERR_EVENT);

    /* Write end of interrupt */
    (void)ESMWriteEOI(((uint32_t)ESM_CFG_BASE), (uint32_t) ESM_INTR_TYPE_HIGH_PRIO_ERROR);
    return ;
}

void cslAppEsmLowInterruptHandler (uintptr_t arg)
{

    /* Call common Interrupt handler */
     cslAppEsmInterruptHandler(ESM_INTR_PRIORITY_LEVEL_LOW, MSMC_ECC_AGGR0_SEC_ERR_EVENT);

    /* Write end of interrupt */
    (void)ESMWriteEOI(((uint32_t)ESM_CFG_BASE), (uint32_t) ESM_INTR_TYPE_LOW_PRIO_ERROR);

    return ;
}


static int32_t cslAppEsmSetupHighPriHandler(uint32_t baseAddr)
{
    HwiP_Params       hwiParams;
    uint32_t          intNumHi = ESM_HI_INT;

    HwiP_disableInterrupt(intNumHi);
    hwiParams.arg = intNumHi;
    /* register the call back function for ESM Hi interrupt */
    gEsmHiHwiPHandle = HwiP_create(intNumHi,
                                   (HwiP_Fxn) cslAppEsmHighInterruptHandler,
                                   (void *)&hwiParams);
    HwiP_enableInterrupt(intNumHi);

    return (CSL_PASS);
}

static int32_t cslAppEsmSetupLowPriHandler(uint32_t baseAddr)
{
    HwiP_Params       hwiParams;
    uint32_t          intNumLo = ESM_LO_INT;

    HwiP_disableInterrupt(intNumLo);
    hwiParams.arg = intNumLo;
    /* register the call back function for ESM Hi interrupt */
    gEsmHiHwiPHandle = HwiP_create(intNumLo,
                                   (HwiP_Fxn) cslAppEsmLowInterruptHandler,
                                   (void *)&hwiParams);
    HwiP_enableInterrupt(intNumLo);
    return (CSL_PASS);
}

/* This function clears the ESM interrrupt status */
static int32_t cslAppClearESMIntrStatus(uint32_t baseAddr, int32_t intNum)
{
    int32_t   cslRet;
    uint32_t  intStatus;

    /* Clear interrupt status, so that we start with clean state */
    cslRet = ESMClearIntrStatus(baseAddr, intNum);

    if (cslRet == CSL_PASS)
    {
        cslRet = ESMGetIntrStatus(baseAddr, intNum, &intStatus);
    }
    if (cslRet == CSL_PASS)
    {
        if (intStatus != ((uint32_t)0U))
        {
            cslRet = CSL_EFAIL;
        }
    }
    return (cslRet);
}

/* Enable the ESM event */
static int32_t cslAppEnableIntr(uint32_t baseAddr, int32_t intNum)
{
    int32_t   cslRet;
    uint32_t  intStatus;

    /* Enable interrupt and verify if interrupt status is enabled */
    cslRet = ESMEnableIntr(baseAddr, intNum);

    if (cslRet == CSL_PASS)
    {
        cslRet = ESMIsEnableIntr(baseAddr, intNum, &intStatus);
    }
    if (cslRet == CSL_PASS)
    {
        if (intStatus != ((uint32_t)1U))
        {
            cslRet = CSL_EFAIL;
        }
    }
    return (cslRet);
}


/* Set the ESM Pri for that event */
static int32_t cslAppSetPri(uint32_t baseAddr, uint32_t pri, int32_t intNum)
{
    int32_t    cslRet;
    esmIntrPriorityLvl_t intrPriorityLvlWr, intrPriorityLvlRd;

    intrPriorityLvlWr = pri;

    cslRet = ESMSetIntrPriorityLvl(baseAddr, intNum, intrPriorityLvlWr);

    if (cslRet == CSL_PASS)
    {
        cslRet = ESMGetIntrPriorityLvl(baseAddr,
                                       intNum,
                                       &intrPriorityLvlRd);
    }
    if (cslRet == CSL_PASS)
    {
        if (intrPriorityLvlWr != intrPriorityLvlRd)
        {
            cslRet = CSL_EFAIL;
        }
    }
    return (cslRet);
}

/* Enable the global interrupt */
static int32_t cslAppEnableEsmGlobalIntr(uint32_t baseAddr)
{
    int32_t     cslRet;
    uint32_t    intStatus;

    /* Enable Global interrupt and verify if global interrupt is enabled for ESM */
    cslRet = ESMEnableGlobalIntr(baseAddr);

    if (cslRet == CSL_PASS)
    {
        cslRet = ESMGetGlobalIntrEnabledStatus(baseAddr, &intStatus);
    }
    if (cslRet == CSL_PASS)
    {
        if (intStatus != CSL_TEST_ESM_EN_KEY_ENBALE_VAL)
        {
            cslRet = CSL_EFAIL;
        }
    }
    return (cslRet);
}

/* ---------------------------------------------------- */

/* function initialized ESM */
int32_t cslAppEsmSetup(uint32_t  baseAddr)
{
    int32_t     cslRet;

    /* ESM reset and configure */
    cslRet = ESMReset((uint32_t)ESM_CFG_BASE);

    if (cslRet == CSL_PASS)
    {
        cslRet = cslAppClearESMIntrStatus((uint32_t) ESM_CFG_BASE, MSMC_ECC_AGGR0_DED_ERR_EVENT);
    }

    if (cslRet == CSL_PASS)
    {
        cslRet = cslAppClearESMIntrStatus((uint32_t) ESM_CFG_BASE, MSMC_ECC_AGGR0_SEC_ERR_EVENT);
    }

    /* Enable the esm_lvl_event_48 and esm_lvl_event_49
     * for monitoring msmc_eccaggr0_uncorrected and msmc_eccaggr0_corrected
     * events */
     /* Enable interrupt and verify if interrupt status is enabled */
     if (cslRet == CSL_PASS)
     {
         cslRet = cslAppEnableIntr(((uint32_t)ESM_CFG_BASE), MSMC_ECC_AGGR0_DED_ERR_EVENT);
     }
     else
     {
        UARTConfigPuts(gUartBaseAddr, "\r\nError in ESM Intr Enable for DED ERR Event...", -1);
     }

     if (cslRet == CSL_PASS)
     {
         cslRet = cslAppEnableIntr(((uint32_t)ESM_CFG_BASE), MSMC_ECC_AGGR0_SEC_ERR_EVENT);
     }
     else
     {
        UARTConfigPuts(gUartBaseAddr, "\r\nError in ESM Intr Enable for SEC Err Event...", -1);
     }

    /* Assign the priority for the events
     * as single bit errors are corrected, can be assigned to lo pri
     * and double bit errors are not corrected, can be assigned to hi pri
     */

     if (cslRet == CSL_PASS)
     {
         cslRet = cslAppSetPri(((uint32_t)ESM_CFG_BASE), ESM_INTR_PRIORITY_LEVEL_HIGH, MSMC_ECC_AGGR0_DED_ERR_EVENT);
     }
     else
     {
        UARTConfigPuts(gUartBaseAddr, "\r\nError in setting Pri for DED Err Event...", -1);
     }

     if (cslRet == CSL_PASS)
     {
         cslRet = cslAppSetPri(((uint32_t)ESM_CFG_BASE), ESM_INTR_PRIORITY_LEVEL_LOW, MSMC_ECC_AGGR0_SEC_ERR_EVENT);
     }
     else
     {
        UARTConfigPuts(gUartBaseAddr, "\r\nError in setting Pri for SEC Err Event...", -1);
     }
     if (cslRet == CSL_PASS)
     {
        cslRet = cslAppEnableEsmGlobalIntr((uint32_t) ESM_CFG_BASE);
     }
     else
     {
        UARTConfigPuts(gUartBaseAddr, "\r\nESM Enable Global Interrupt Failed...", -1);
     }

     if (cslRet == CSL_PASS)
     {
        cslRet = cslAppEsmSetupHighPriHandler((uint32_t) ESM_CFG_BASE);
     }
     else
     {
        UARTConfigPuts(gUartBaseAddr, "\r\nESM High Priority handler setup Failed...", -1);
     }

     if (cslRet == CSL_PASS)
     {
        cslRet = cslAppEsmSetupLowPriHandler((uint32_t) ESM_CFG_BASE);
     }
     else
     {
        UARTConfigPuts(gUartBaseAddr, "\r\nESM Lo Priority handler setup Failed...", -1);
     }

     if (cslRet == CSL_PASS)
     {
        UARTConfigPuts(gUartBaseAddr, "\r\n cslAppEsmInit...Done", -1);
     }
     return (cslRet);
}
