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
#include "ecc_msmc.h"

/* ----------------- Constant definitions ----------------- */


/* -------------------------------------------------------- */

/* ----------------- Function prototypes ------------------ */
static void msmcEccInit(char option);
static int32_t msmcEccConfig(uint32_t eccMemType);
static int32_t msmcSecErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId);
static int32_t msmcDedErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId);
static int32_t msmcECCInjectError(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t err_pat,
                                  uint32_t err_chk, uint32_t isCorrectableError);
/* -------------------------------------------------------- */


/* ----------------- Global variables ----------------- */
CSL_ecc_aggrRegs * const cslAppEccAggrAddrTable[APP_ECC_AGGREGATOR_MAX_ENTRIES] =
{
    ((CSL_ecc_aggrRegs *) ((uintptr_t) CSL_COMPUTE_CLUSTER0_MSMC_ECC_AGGR0_BASE))
};

static volatile uint32_t gSecTestPass   = FALSE;
static volatile uint32_t gDedTestPass   = FALSE;

/* Function handles Emif test sub menu */
void mainSubMenuMsmcEccTest(char *pOption)
{
    char option;
    while (1)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\n\r\n**** MSMC ECC TEST ****", -1);
        UARTConfigPuts(gUartBaseAddr, "\r\nMenu:", -1);
        UARTConfigPuts(gUartBaseAddr, "\r\n1. MSMC SEC ERR ECC test", -1);
        UARTConfigPuts(gUartBaseAddr, "\r\n2. MSMC DED ERR ECC test", -1);
        UARTConfigPuts(gUartBaseAddr, "\r\nx. Exit", -1);
        UARTConfigPuts(gUartBaseAddr, "\r\nSelect ECC TEST : ", -1);
        /* Get option */
        UARTConfigGets(gUartBaseAddr, pOption, 1);

        option = *pOption;
        if ( (MSMC_ECC_SEC_ERR_TEST == option) ||
             (MSMC_ECC_DED_ERR_TEST == option) ||
             (MSMC_ECC_EXIT         == option) )
        {
            break;
        }
        else
        {
            UARTConfigPuts(gUartBaseAddr, "\r\nEnter Valid option\r\n", -1);
        }
    }
}

void cslAppChkIsExpectedRamId(uint32_t testId)
{
    uint32_t    val, bitNo, mask, statusRegOffset;
    uint32_t    expectedRamId = CC_MSMC_WRAP_ECC_AGGR0_MSMC_DATA_RAM_ID;
    CSL_ecc_aggrRegs *eccAggrRegs;
 
    eccAggrRegs = cslAppEccAggrAddrTable[APP_ECC_MEMTYPE_MSMC];

    /* Check if the Interrupt caused by the RAM ID expected 
       CC_MSMC_WRAP_ECC_AGGR0_MSMC_DATA_RAM_ID (56) is under Register offset 0x44 
     */
     if (testId == MSMC_ECC_AGGR0_DED_ERR_EVENT)
     {
         /* ECC_DED_STATUS_REG1 Register (Offset = 144h)
          * holds the staus of RAM56_PEND for uncorrectable errors
          * RAM ID 56 is the one for MSMC ECC
          */
         statusRegOffset = 0x140U + ((uint32_t) (expectedRamId / 32U )) * 4U;
     }
     else
     {
         /* ECC_SEC_STATUS_REG1 Register (Offset = 44h)
          * holds the staus of RAM56_PEND for Correctable errors
          * RAM ID 56 is the one for MSMC ECC
          */
         statusRegOffset = 0x40U + ((uint32_t) (expectedRamId / 32U )) * 4U;
     }
     val   = CSL_REG32_RD((uintptr_t)eccAggrRegs + statusRegOffset);
     bitNo = expectedRamId % 32u;
     mask  = 1u << bitNo;
     val  &= mask;

     if (testId == MSMC_ECC_AGGR0_DED_ERR_EVENT)
     {

         if (mask == val)
         {
            /* Bit      : 15-14
               Field    : INJ_UNC_PEND_CLR
               Description: Number of injected uncorrected pending interrupts 
                            (same value as UNC_PEND). 
                            Writing decrements INJ_UNC_PEND by that value.
               as there is one DED error injected, write 1 to the field to Ack
             */
             val = 1 << 14u;
             CSL_ecc_aggrWriteEccRamErrStatReg(eccAggrRegs, expectedRamId,0u, val);
             gDedTestPass = TRUE;
         }
         /* Write end of interrupt */
         CSL_ecc_aggrAckIntr(eccAggrRegs, CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);

     }
     else
     {
         if (mask == val)
         {
            /* Bit      : 13-12
               Field    : INJ_COR_PEND_CLR
               Description: Number of injected uncorrected pending interrupts 
                            (same value as COR_PEND). 
                            Writing decrements INJ_COR_PEND by that value.
               as there is one SEC error injected, write 1 to the field to Ack
             */
             val = 1 << 12u;
             CSL_ecc_aggrWriteEccRamErrStatReg(eccAggrRegs, expectedRamId,0u, val);
             gSecTestPass = TRUE;
         }

         /* Write end of interrupt */
         CSL_ecc_aggrAckIntr(eccAggrRegs, CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);
     }
     return;
}
/* Function executes Emif ECC Test */
int32_t msmcEccTest(void)
{
    int32_t retVal;
    char    mainSubMenuOption;
    CSL_ecc_aggrRegs *eccAggrRegs;
    uint32_t skipMsmcTest;
    uint32_t   ramId = ECC_AGGR_UNKNOWN_RAM_ID;

    /* initialize the ESM */
    retVal = cslAppEsmSetup((uint32_t) ESM_CFG_BASE );

    if (retVal == CSL_PASS)
    {
        skipMsmcTest = FALSE;
    }
    else
    {
        /* Skip the test as ESM setup Failed */
        skipMsmcTest = TRUE;
        UARTConfigPuts(gUartBaseAddr, "\r\n ESM Setup Failed...", -1);
    }


    while (1)
    {
        if (skipMsmcTest == FALSE)
        {
            mainSubMenuMsmcEccTest(&mainSubMenuOption);
            msmcEccInit(mainSubMenuOption);
        }
        else
        {
            /* select exit option */
            mainSubMenuOption = 'x';
        }

        if (MSMC_ECC_SEC_ERR_TEST == mainSubMenuOption)
        {
            ramId = CC_MSMC_WRAP_ECC_AGGR0_MSMC_DATA_RAM_ID;
            eccAggrRegs = cslAppEccAggrAddrTable[APP_ECC_MEMTYPE_MSMC];
            retVal = msmcSecErrTest(eccAggrRegs, ramId);
        }
        else if (MSMC_ECC_DED_ERR_TEST == mainSubMenuOption)
        {
            ramId = CC_MSMC_WRAP_ECC_AGGR0_MSMC_DATA_RAM_ID;
            eccAggrRegs = cslAppEccAggrAddrTable[APP_ECC_MEMTYPE_MSMC];
            retVal = msmcDedErrTest(eccAggrRegs, ramId);
        }
        else
        {
            UARTConfigPuts(gUartBaseAddr, "\r\nMSMC ECC test exiting...", -1);
            break;
        }
    }

    if (gSecTestPass)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nMSMC ECC SEC ECC TESTS PASSED", -1);
    }
    else
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nMSMC ECC SEC ECC TESTS FAILED", -1);
    }

    if (gDedTestPass)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nMSMC ECC DED ECC TESTS PASSED", -1);
    }
    else
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nMSMC ECC DED ECC TESTS FAILED", -1);
    }
    if (gDedTestPass & gSecTestPass)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nALL TESTS PASS", -1);
    }
    return retVal;
}

/* Function initialized MSMC ECC */
static void msmcEccInit(char option)
{
    int32_t cslRet;

    /* Ecc config */
    cslRet = msmcEccConfig(APP_ECC_MEMTYPE_MSMC);

    if (cslRet != CSL_PASS)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nECC Config failed...", -1);
    }
    return;
}

/* Enable ECC and */
static int32_t msmcECCInjectError(CSL_ecc_aggrRegs *pEccAggrRegs, uint32_t ramId, uint32_t err_pat,
                                  uint32_t err_chk, uint32_t isCorrectableError)
{
    int32_t    retVal;
    uint32_t   val;

    retVal = CSL_ecc_aggrReadEccRamCtrlReg(pEccAggrRegs, ramId, &val);
    if (retVal == CSL_PASS )
    {
        APP_TEST_FINS(val, TEST_ECC_AGGR_CTRL_ECC_PATTERN, err_pat );
        if ( isCorrectableError == 0u)
        {
            /* Force Double Error */
            APP_TEST_FINS(val, TEST_ECC_AGGR_CTRL_FORCE_DE,  1u );
        }
        else
        {
            /* Force Single Error */
            APP_TEST_FINS(val, TEST_ECC_AGGR_CTRL_FORCE_SE,  1u );
        }
        APP_TEST_FINS(val, TEST_ECC_AGGR_CTRL_ECC_CHK, err_chk );
        retVal = CSL_ecc_aggrWriteEccRamCtrlReg(pEccAggrRegs, ramId, val);
    }
    return retVal;
}



/* Function configures MSMC ECC
 * Also primes the memory area
 */
static int32_t msmcEccConfig(uint32_t eccMemType)
{
    int32_t    cslResult;
    CSL_ecc_aggrRegs *eccAggrRegs;

    eccAggrRegs = cslAppEccAggrAddrTable[APP_ECC_MEMTYPE_MSMC];

    /* Enable the single bit ECC interrupts */
    /* Note: The following statement enables interrupts for all RAMs */
    cslResult = CSL_ecc_aggrEnableIntrs(eccAggrRegs,
                            CSL_ECC_AGGR_INTR_SRC_SINGLE_BIT);

    if (cslResult == CSL_PASS)
    {
        /* Enable the Double bit ECC Interrupts */
        cslResult = CSL_ecc_aggrEnableIntrs(eccAggrRegs,
                            CSL_ECC_AGGR_INTR_SRC_DOUBLE_BIT);
    }
    else
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nECC AGGR SINGLE BIT Error Interrupt Enable failed...", -1);
    }

    if (cslResult != CSL_PASS)
    {
        UARTConfigPuts(gUartBaseAddr, "\r\nECC AGGR Configuration failed...", -1);
    }

    return (cslResult);
}

/* Function performs MSMC single bit error test
 * Configures ECC, Inserts single bit error
 * and waits for handler to finish
 */
static int32_t msmcSecErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId)
{
    int32_t  retVal = CSL_EFAIL;
    uint32_t val = 0u;
    uint32_t firstBitLocation = MSMC_ECC_ERR_BIT_1;

    /* set the test status to false */
    gSecTestPass = FALSE;

     APP_TEST_FINS(val, TEST_ECC_AGGR_ERR1_ECC_GRP, 0u );
     APP_TEST_FINS(val, TEST_ECC_AGGR_ERR1_ECC_BIT1, firstBitLocation );

     retVal = CSL_ecc_aggrWriteEccRamErrCtrlReg(eccAggrRegs, ramId, 0u, val);

     if (retVal == CSL_PASS)
     {
         /* Inject SEC Error */
         retVal = msmcECCInjectError(eccAggrRegs,
                                  CC_MSMC_WRAP_ECC_AGGR0_MSMC_DATA_RAM_ID, 2u, 1u, 1u);
    }

    /* wait until the test passes */
    UARTConfigPuts(gUartBaseAddr, "\r\n Waiting on SEC Interrupt...", -1);
    while (gSecTestPass == FALSE);
    UARTConfigPuts(gUartBaseAddr, "\r\n Got it (test pass)...", -1);
    /* return the test status */
    return retVal;
}

/* Function performs MSMC double bit error test
 * Inserts double bit error and waits for handler to finish
 */
static int32_t msmcDedErrTest(CSL_ecc_aggrRegs *eccAggrRegs, uint32_t ramId)
{
    int32_t  retVal = CSL_EFAIL;
    uint32_t val = 0u;
    uint32_t firstBitLocation = MSMC_ECC_ERR_BIT_1;
    uint32_t secBitLocation   = MSMC_ECC_ERR_BIT_2;

    gDedTestPass = FALSE;
     APP_TEST_FINS(val, TEST_ECC_AGGR_ERR1_ECC_GRP, 0u );
     APP_TEST_FINS(val, TEST_ECC_AGGR_ERR1_ECC_BIT1, firstBitLocation );

     retVal = CSL_ecc_aggrWriteEccRamErrCtrlReg(eccAggrRegs, ramId, 0u, val);

     if (retVal == CSL_PASS)
     {
          APP_TEST_FINS(val, TEST_ECC_AGGR_ERR2_ECC_BIT2, secBitLocation );
          retVal = CSL_ecc_aggrWriteEccRamErrCtrlReg(eccAggrRegs, ramId, 1u, val);
     }

     if (retVal == CSL_PASS)
     {
         /* Inject the DED errors */
         retVal = msmcECCInjectError(eccAggrRegs,
                                  CC_MSMC_WRAP_ECC_AGGR0_MSMC_DATA_RAM_ID, 2u, 1u, 0u);
    }

    /* wait until the test passes */
    UARTConfigPuts(gUartBaseAddr, "\r\n Waiting on DED interrupt...", -1);
    while (gDedTestPass == FALSE);
    UARTConfigPuts(gUartBaseAddr, "\r\n Got it...(test pass) ", -1);
    /* return the test status */
    return retVal;
}


/* Nothing past this point */
