/*
 *   Copyright (c) Texas Instruments Incorporated 2018
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
 *  \file     dcc_app_v1.c
 *
 *  \brief    This example application demonstrates comparison of 2 clock
 *              sources.
 *
 *  \details    Different clock sources are provided to Counter 1 (Test Clock)
 *              and Counter 0 (Reference Clock).
 *              This application configures the DCC module to generate
 *              interrupt, when Counter 1 reaches 0.
 *              1. When Counter 0 + Valid Counter & Counter 1 reaches 0 at same
 *                   time, Completion Interrupt is generated.
 *              2. Error Interrupt is generated when
 *                  2.1. Counter 1 reaches 0 before Counter 0 reaches 0
 *
 *              Other Conditions where an error interrupt can be generated by
 *              DCC but not demonstrated by this demo application.
 *                  2.2. Counter 1 reaches 0 after Counter 1 & VALID0 reaches 0
 *                  2.3. Source sources to Counter 0 & Counter 1 are not present
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <stdint.h>
#include <stdio.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/cslr_dcc.h>
#include <ti/csl/csl_dcc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>

/* Interrupt Registrations */
#include <ti/osal/osal.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define APP_DCC_STR                     "CSL DCC Example"
/**< Example Common display string */

#define APP_DCC_MODULE_INST             (CSL_MCU_DCC0_BASE)
/**< Instance of DCC. While changing the instance, ensure update clock sources*/
#define APP_DCC_MODE                    (DCC_OPERATION_MODE_SINGLE_SHOT2)
/**< One Shot mode, Stop counting when Counter 1, reaches 0. */
#define APP_DCC_SRC0_MAX_VAL            (0xFFFFFU)
/**< Maximum value that can be held in the COUNT0 register (ref clock) */
#define APP_DCC_SRC0_VALID_MAX_VAL      (0x0FFFFU)
/**< Maximum value that can be held in the VALID0 register (ref clock) */
#define APP_DCC_SRC1_MAX_VAL            (0xFFFFFU)
/**< Maximum value that can be held in the COUNT1 register (test clock) */

/* Defines that control the clock inputs to DCC and allowed variance */
#define APP_DCC_REF_CLOCK_SRC_0         (DCC_DCCCLKSRC0_CLKSRC0_0)
/**< Clock source for Counter 0, 25 MHz for DRA80x/AM65x */
#define APP_DCC_TEST_CLOCK_SRC_1        (DCC_DCCCLKSRC1_CLKSRC_0)
/**< Clock source for Counter 1, 60 KHz for DRA80x/AM65x */
#define APP_DCC_TEST_CLOCK_SRC_1_DRIFT  (5U)
/**< Allowed drift in percentage (+/-) */
#define APP_DCC_TEST_CLOCK_SRC_1_HIGHER (DCC_DCCCLKSRC1_CLKSRC_1)
/**< Clock source for Counter 1, expected to be higher than
        APP_DCC_TEST_CLOCK_SRC_1, in this example to simulate an error.
        80 MHz for DRA80x/AM65x */

#define APP_DCC_REF_CLOCK_FREQ_IN_KHZ   (25000U)
/**< Expected reference clock frequency in KHz */
#define APP_DCC_TEST_CLOCK_FREQ_IN_KHZ  (60000U)
/**< Expected test clock frequency in KHz */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
volatile uint32_t isrFlag = 0U;
/**< Flag used to indicate occurrence of the completion interrupt */
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   Utility function to print on UART console/CCS console
 */
static void DCCAppPrint(const char * str);
/**
 * \brief   Initializes board/UART
 */
static void DCCAppInitUart(void);

/**
 * \brief   This function returns clock frequencies
 *
 * \param   dccInst     Instance of DCC
 * \param   clkSrc0     Clock source for counter 0
 * \param   clkSrc1     Clock source for counter 1
 * \param   clk0Freq    Clock frequency for counter 0 in KHz
 * \param   clk1Freq    Clock frequency for counter 1 in KHz
 *
 * \retval  status      Negative number in case of errors
 */
static int32_t DCCAppGetClkfreqKHz(uint32_t dccInst,
                                    uint32_t clkSrc0, uint32_t clkSrc1,
                                    uint32_t *clk0Freq, uint32_t *clk1Freq);
/**
 * \brief   This function returns least integral ratio for given clocks.
 *
 * \param   refClkFreq      Reference clock frequency in KHz.
 * \param   testClkFreq     Test clock frequency in KHz.
 * \param   refClkRatioNum  Reference clock ratio number.
 * \param   testClkRatioNum Test clock ratio number.
 *
 * \retval  None.
 */
static void DCCAppGetClkRatio(uint32_t  refClkFreq,
                              uint32_t  testClkFreq,
                              uint32_t *refClkRatioNum,
                              uint32_t *testClkRatioNum);

/**
 * \brief   This function returns seed value for COUNT1.
 *
 * \param   refClkFreq      Reference clock frequency in KHz.
 * \param   testClkFreq     Test clock frequency in KHz.
 * \param   refClkRatioNum  Reference clock ratio number.
 * \param   testClkRatioNum Test clock ratio number.
 * \param   drfitPer        Allowed drift in test clock in percentage.
 * \param   configParams    DCC configuration parameters.
 *                          Refer enum #dccConfigParams_t.
 *
 * \retval  None.
 */
static void DCCAppSetSeedVals(uint32_t           refClkFreq,
                              uint32_t           testClkFreq,
                              uint32_t           refClkRatioNum,
                              uint32_t           testClkRatioNum,
                              uint32_t           drfitPer,
                              dccConfigParams_t *configParams);

/**
 * \brief   This function register ISR for a given instance of DCC
 *
 *
 * \param   dccInst     Instance of DCC
 *
 * \retval  CSL_PASS on successful interrupt handler registration.
 */
static int32_t DCCAppRegisterIsr(uint32_t dccInst);

/**
 * \brief   This function waits infinitely for DCC done interrupt
 *
 * \param   dccInst     Instance of DCC
 *
 * \retval  CSL_PASS on occurrence DCC completion and no error.
 *          CSL_EFAIL otherwise.
 */
static int32_t DCCAppWaitForCompletion(uint32_t dccBaseAddr);

/**
 * \brief   This function waits infinitely for DCC interrupt
 *
 * \param   dccInst     Instance of DCC
 *
 * \retval  CSL_PASS always
 */
static int32_t DCCAppWaitForCompletionWithError(uint32_t dccBaseAddr);

/**
 * \brief   ISR for done interrupt, set a global flag
 *
 * \retval  None
 */
static void DCCAppDoneIntrISR(uintptr_t handle);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int main(void)
{
    int32_t status;
    uint32_t clk0Freq, clk1Freq, refClkRatioNum, testClkRatioNum;
    dccConfigParams_t configParams;

    DCCAppInitUart();

    DCCAppPrint("\r\n" APP_DCC_STR ": Start\r\n");
    /* Steps
    1. Determine the clock frequencies for the sources
    2. Figure out the seed values for successful completion
    3. Configure Interrupts for normal completion
    4. Configure DCC instance
    5. Enable DCC
    6. Wait for normal completion
    7. Change reference clock source to higher frequency source (to simulate
        clock change)
    8. Configure DCC and Enable
    9. Wait for error notification
    */
    /* Step 1 Determine the clock frequencies for the sources */
    status = DCCAppGetClkfreqKHz(APP_DCC_MODULE_INST,
                                      APP_DCC_REF_CLOCK_SRC_0,
                                      APP_DCC_TEST_CLOCK_SRC_1,
                                      &clk0Freq, &clk1Freq);
    if (CSL_PASS == status)
    {
        /* Step 2 Figure out the seed values for successful completion */
        /* Get clock ratio */
        DCCAppGetClkRatio(clk0Freq,
                      clk1Freq,
                      &refClkRatioNum,
                      &testClkRatioNum);

        configParams.mode    = APP_DCC_MODE;
        configParams.clkSrc0 = APP_DCC_REF_CLOCK_SRC_0;
        configParams.clkSrc1 = APP_DCC_TEST_CLOCK_SRC_1;
        configParams.alternateClkSrc1 = FALSE;
        /* Get the seed values for given clock selections and allowed drift */
        DCCAppSetSeedVals(clk0Freq,
                          clk1Freq,
                          refClkRatioNum,
                          testClkRatioNum,
                          APP_DCC_TEST_CLOCK_SRC_1_DRIFT,
                          &configParams);

        /* Step 3 Configure Interrupts for normal completion */
        DCCAppRegisterIsr(APP_DCC_MODULE_INST);

        /* Step 4 Configure DCC instance */
        status = DCCSetConfig(APP_DCC_MODULE_INST, &configParams);
        if (CSL_PASS == status)
        {
            /* Clear the interrupt flag, DCCAppWaitForCompletion () will pend
                on this */
            isrFlag = 0U;

            DCCAppPrint(APP_DCC_STR ": DCC configured \n");
            DCCEnableIntr(APP_DCC_MODULE_INST, DCC_INTERRUPTS_ERROR);
            DCCEnableIntr(APP_DCC_MODULE_INST, DCC_INTERRUPTS_DONE);

            DCCAppPrint(APP_DCC_STR ": Enabling DCC and waiting for "
                        "completion interrupt \n");
            /* 5 Enable DCC */
            DCCEnable(APP_DCC_MODULE_INST, TRUE);
        }

        /* Step 6. Wait for normal completion */
        if (CSL_PASS == DCCAppWaitForCompletion(APP_DCC_MODULE_INST))
        {
            DCCAppPrint(APP_DCC_STR ": DCC Generated completion interrupt \n");
            DCCAppPrint(APP_DCC_STR ": No Clock Drift was observed \n");
        }
        else
        {
            DCCAppPrint(APP_DCC_STR ": DCC Generated completion interrupt \n");
            DCCAppPrint(APP_DCC_STR ": Error : DCC Generated error interrupt\n");
            DCCAppPrint(APP_DCC_STR ": Error interrupt is not expected \n");
        }
        /* Step 7. Change reference clock source to higher frequency source */
        if (CSL_PASS == status)
        {
            /* Step 8. Configure DCC and Enable */
            /* Change reference clock source to higher frequency source */
            DCCAppPrint(APP_DCC_STR ": Changing the clock source \n");
            DCCEnable(APP_DCC_MODULE_INST, FALSE);
            configParams.clkSrc1 = APP_DCC_TEST_CLOCK_SRC_1_HIGHER;

            status = DCCSetConfig(APP_DCC_MODULE_INST, &configParams);
            DCCAppPrint(APP_DCC_STR ": Enabling DCC and waiting for "
                        "Error interrupt \n");
            DCCEnable(APP_DCC_MODULE_INST, TRUE);

            /* Step 9. Wait for error notification */
            DCCAppWaitForCompletionWithError(APP_DCC_MODULE_INST);
            DCCAppPrint(APP_DCC_STR ": DCC Generated Error interrupt \n");
            DCCAppPrint(APP_DCC_STR ": Indicating clock drift/change \n");
        }
    }
    else
    {
        DCCAppPrint(APP_DCC_STR ": Error : Could not derive clock "
                        "frequency!!!\r\n");
    }

    DCCAppPrint(APP_DCC_STR ": Completes!!!\r\n");

    return 0;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

static void DCCAppPrint(const char * str)
{
    printf(str);
    UART_printf(str);
}

static void DCCAppInitUart(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        DCCAppPrint("[Error] Board init failed!!\n");
    }
}

static int32_t DCCAppGetClkfreqKHz(uint32_t dccInst,
                                        uint32_t clkSrc0, uint32_t clkSrc1,
                                        uint32_t *clk0Freq, uint32_t *clk1Freq)
{
    int32_t retVal = CSL_EFAIL;
    switch (dccInst)
    {
        case CSL_MCU_DCC0_BASE :
            if (DCC_DCCCLKSRC0_CLKSRC0_0 == clkSrc0)
            {
                /* 25 MHz */
                *clk0Freq = APP_DCC_REF_CLOCK_FREQ_IN_KHZ;
                retVal = CSL_PASS;
            }
            if ((DCC_DCCCLKSRC1_CLKSRC_0 == clkSrc1) &&
                (CSL_PASS == retVal))
            {
                /* 60 MHz */
                *clk1Freq = APP_DCC_TEST_CLOCK_FREQ_IN_KHZ;
            }
            else
            {
                retVal = CSL_EFAIL;
            }
            if (CSL_PASS != retVal)
            {
                DCCAppPrint(APP_DCC_STR ": Error : Selected clock sources is"
                        "not supported in this example !!!\r\n");
            }
        break;

        default :
            DCCAppPrint(APP_DCC_STR ": Error : DCC Instance not supported in"
                        " this example !!!\r\n");
        break;
    }
    return (retVal);
}

static void DCCAppGetClkRatio(uint32_t  refClkFreq,
                              uint32_t  testClkFreq,
                              uint32_t *refClkRatioNum,
                              uint32_t *testClkRatioNum)
{
    uint32_t loopCnt, hcf = 1U;

    for (loopCnt = 1;
         (loopCnt <= refClkFreq) || (loopCnt <= testClkFreq);
         loopCnt++)
    {
        if ((refClkFreq % loopCnt == 0) && (testClkFreq % loopCnt == 0))
        {
            hcf = loopCnt;
        }
    }
    *refClkRatioNum  = (refClkFreq / hcf);
    *testClkRatioNum = (testClkFreq / hcf);
}

static void DCCAppSetSeedVals(uint32_t           refClkFreq,
                              uint32_t           testClkFreq,
                              uint32_t           refClkRatioNum,
                              uint32_t           testClkRatioNum,
                              uint32_t           drfitPer,
                              dccConfigParams_t *configParams)
{
    uint32_t maxFreqKHz, maxCntLimit;
    uint32_t maxRefCnt, minRefCnt;
    uint64_t mulVar;

    /* Find maximum frequency between test and reference clock */
    if (refClkFreq > testClkFreq)
    {
        maxFreqKHz  = refClkFreq;
        maxCntLimit = APP_DCC_SRC0_MAX_VAL;
    }
    else
    {
        maxFreqKHz  = testClkFreq;
        maxCntLimit = APP_DCC_SRC1_MAX_VAL;
    }
    /* Calculate seed values for 0% drift */
    if (maxFreqKHz == refClkFreq)
    {
        configParams->seedSrc0 = maxCntLimit / refClkRatioNum;
        configParams->seedSrc0 = configParams->seedSrc0 * refClkRatioNum;
        mulVar = ((uint64_t) (configParams->seedSrc0) *
                  (uint32_t) (testClkRatioNum));
        configParams->seedSrc1   = (uint32_t) (mulVar / refClkRatioNum);
        configParams->seedValid0 = refClkRatioNum;
    }
    else
    {
        configParams->seedSrc1 = maxCntLimit / testClkRatioNum;
        configParams->seedSrc1 = configParams->seedSrc1 * testClkRatioNum;
        mulVar = ((uint64_t) (configParams->seedSrc1) *
                  (uint32_t) (refClkRatioNum));
        configParams->seedSrc0   = (uint32_t) (mulVar / testClkRatioNum);
        configParams->seedValid0 = 1U;
    }
    /* Applying allowed drift */
    if (((APP_DCC_SRC0_MAX_VAL + APP_DCC_SRC0_VALID_MAX_VAL) <
         (configParams->seedSrc0 * (100U + drfitPer) / 100U)))
    {
        /* Seed values with drift exceeds maximum range */
        DCCAppPrint(APP_DCC_STR ": Seed values with drift exceeds"
                        " allowed range\n");
        DCCAppPrint(APP_DCC_STR ": Application will run with 0% "
                        " allowed drift\n");
    }
    else if (100U < drfitPer)
    {
        /* Error percentage is greater than 100 */
        DCCAppPrint(APP_DCC_STR ": Warning Wrong drift %,Not applying drift\n");
        DCCAppPrint(APP_DCC_STR ": Application will run with 0% drift\n");
    }
    else
    {
        maxRefCnt = (configParams->seedSrc0 * (100U + drfitPer) / 100U);
        minRefCnt = (configParams->seedSrc0 * (100U - drfitPer) / 100U);
        if (APP_DCC_SRC0_VALID_MAX_VAL < (maxRefCnt - minRefCnt))
        {
            DCCAppPrint(APP_DCC_STR ": Warning Seed value for valid count "
                        "exceeds allowed range.\n");
            DCCAppPrint(APP_DCC_STR "Application will run with 0% allowed"
                        " drift.\n");
        }
        else
        {
            if (maxRefCnt == minRefCnt)
            {
                configParams->seedValid0 = 1U;
            }
            else
            {
                configParams->seedSrc0   = minRefCnt;
                configParams->seedValid0 = (maxRefCnt - minRefCnt);
            }
        }
    }
    DCCAppPrint(APP_DCC_STR ": Seed values calculation done.\n");
}

static int32_t DCCAppRegisterIsr(uint32_t dccInst)
{
    int32_t retVal = CSL_EFAIL;
    uint32_t dccInt;
    OsalRegisterIntrParams_t intrPrms;
    OsalInterruptRetCode_e osalRetVal;
    HwiP_Handle hwiHandle;

    Osal_RegisterInterrupt_initParams(&intrPrms);
    intrPrms.corepacConfig.arg          = (uintptr_t)0;
    intrPrms.corepacConfig.priority     = 1U;
    intrPrms.corepacConfig.corepacEventNum = 0U; /* NOT USED ? */

    switch (dccInst)
    {
        case CSL_MCU_DCC0_BASE :
        #if defined (SOC_AM65XX)
            dccInt = CSL_MCU0_INTR_DCC0_INTR_DONE_LEVEL;
        #else
            dccInt = CSLR_MCU_R5FSS0_CORE0_INTR_MCU_DCC0_INTR_DONE_LEVEL_0;
        #endif
            intrPrms.corepacConfig.isrRoutine   = &DCCAppDoneIntrISR;

            retVal = CSL_PASS;
        break;

        default :
            DCCAppPrint(APP_DCC_STR ": Error : DCC Instance not supported in"
                        " this example !!!\r\n");
        break;
    }
    if (CSL_PASS == retVal)
    {
        intrPrms.corepacConfig.intVecNum = dccInt;

        osalRetVal = Osal_RegisterInterrupt(&intrPrms, &hwiHandle);
        if(OSAL_INT_SUCCESS != osalRetVal)
        {
            retVal = CSL_EFAIL;
            DCCAppPrint(APP_DCC_STR ": Error Could not register ISR !!!\n");
        }
    }
    return (retVal);
}

static int32_t DCCAppWaitForCompletion(uint32_t dccBaseAddr)
{
    int32_t retVal;
    volatile uint32_t intStatus = 0U;

    /* Wait for completion interrupt / or error flag*/
    while ((0U == isrFlag) &&
           (DCC_DCCSTAT_ERRFLG_MASK != (intStatus & DCC_DCCSTAT_ERRFLG_MASK)))
    {
        intStatus = DCCGetIntrStatus(dccBaseAddr);
    }

    /* Ensure no error */
    if (DCC_DCCSTAT_ERRFLG_MASK == (intStatus & DCC_DCCSTAT_ERRFLG_MASK))
    {
        retVal = CSL_EFAIL;
    }
    else
    {
        retVal = CSL_PASS;
    }
    return (retVal);
}

static int32_t DCCAppWaitForCompletionWithError(uint32_t dccBaseAddr)
{
    volatile uint32_t intStatus = 0U;

    while (DCC_DCCSTAT_ERRFLG_MASK != (intStatus & DCC_DCCSTAT_ERRFLG_MASK))
    {
        intStatus = DCCGetIntrStatus(dccBaseAddr);
    }
    DCCClearIntrStatus(APP_DCC_MODULE_INST, DCC_INTERRUPTS_ERROR);
    return (CSL_PASS);
}

static void DCCAppDoneIntrISR(uintptr_t handle)
{
    DCCClearIntrStatus(APP_DCC_MODULE_INST, DCC_INTERRUPTS_DONE);
    isrFlag  = 1U;
}

/********************************* End of file ******************************/