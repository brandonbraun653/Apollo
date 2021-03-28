/*
 *   Copyright (c) 2019 Texas Instruments Incorporated
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
 *  \file     st_rtiSingleShot.c
 *
 *  \brief    This file contains RTI DWWD test code.
 *
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_rti.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */
#define RTI_CLOCK_SOURCE_32KHZ_FREQ_KHZ        (32U)
/**< RTI Clock Source Selection */
#define RTI_NO_INTERRUPT                    (0U)
#define RTI_CPU_INTERRUPT                   (1U)
#define RTI_ESM_INTERRUPT                   (2U)

#define MCU_ESM_RTI0_INTR                   (104U)
#define MCU_ESM_RTI1_INTR                   (105U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
volatile uint32_t isrFlag = RTI_NO_INTERRUPT;
/**< Flag used to indicate interrupt is generated */

static uint32_t gEsmInst, gEsmEvtNum;
static HwiP_Handle gHwiHandleIntr = NULL;
static st_RTITestcaseParams_t *gCurrentTestParams;

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   This API to select clock source for RTI module.
 *
 * \param   rtiModuleSelect       RTI module instance
 *
 * \param   rtiClockSourceSelect  RTI module clock source
 *                                Values given by enum #rtiClockSource_t
 *
 * \return  none.
 */
static void RTISetClockSource(uint32_t rtiModuleSelect,
                              uint32_t rtiClockSourceSelect);
/**
 * \brief   This API to calculate preload value from given time-out value.
 *
 * \param   rtiClkSource    RTI module clock source
 *                          Values given by enum #rtiClockSource_t
 *
 * \param   timeoutVal      RTI DWWD time-out value in mili-seconds.
 *
 * \return  Preload value   Time-out value in RTI source clock cycles.
 */
static uint32_t RTIGetPreloadValue(uint32_t rtiClkSource, uint32_t timeoutVal);
/**
 * \brief   This API to register interrupt for a given instance.
 *
 * \param   rtiModuleSelect RTI module instance
 *
 * \return  None.
 */
static void RTIInterruptRegister(uint32_t rtiModuleSelect, rtiIntrType_t intrType);
/**
 * \brief   This API to register interrupt for a given instance.
 *
 * \return  None.
 */
static void RTIInterruptUnregister(void);
/**
 * \brief   ISR after interrupt generation, sets global flag
 *
 * \param   handle Object handle
 *
 * \retval  None
 */
static void RTIAppCpuISR(uintptr_t handle);
/**
 * \brief   ISR function for reset (ESM interrupt) generation, sets global flag
 *
 * \param   handle Object handle
 *
 * \retval  None
 */
static void RTIAppEsmISR(uintptr_t handle);
/**
 * \brief   Function services the RTI after end time violation.
 *
 * \param   rtiModule           RTI module instance
 *
 * \param   rtiWindow_size      RTI Window size
 *
 * \retval  None
 */
static void RTIAppExpiredDwwdService(uint32_t rtiModule, uint32_t rtiWindow_size);
/**
 * \brief   Enable ESM module to generate interrupt.
 *
 * \param   esmInst         ESM Instance connected to the RTI Module
 *
 * \param   esmEvtNum       ESM event based on the RTI module used
 *
 * \retval  None
 */
void RTIEnableEsm(uint32_t esmInst, uint32_t esmEvtNum);
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t st_rtiSingleShot_main(st_RTITestcaseParams_t *testParams)
{
    uint32_t rtiModule, rtiWindow_size, rtiPreload_value, rtiReaction;
    uint32_t closedWinStatus;
    int32_t  retVal = STW_SOK;

    /* Register Interrupt */
    isrFlag = RTI_NO_INTERRUPT;
    RTIInterruptRegister(testParams->rtiConfigParams.rtiModule,
                         testParams->rtiConfigParams.rtiIntrType);

    gCurrentTestParams = testParams;
    /* Configure RTI parameters */
    rtiModule        = testParams->rtiConfigParams.rtiModule;
    rtiWindow_size   = testParams->rtiConfigParams.dwwdWindowSize;
    rtiReaction      = RTI_DWWD_REACTION_GENERATE_NMI;
    rtiPreload_value = RTIGetPreloadValue(testParams->rtiConfigParams.rtiClkSrc,
                                          testParams->rtiConfigParams.rtiTimeoutVal);

    /* Select RTI module clock source */
    RTISetClockSource(rtiModule, testParams->rtiConfigParams.rtiClkSrc);
    retVal = RTIDwwdWindowConfig(rtiModule, rtiReaction,
                                    rtiPreload_value,
                                    rtiWindow_size);
    if (retVal == CSL_EFAIL)
    {
        UART_printf("Error during Window configuration.\n");
    }

    /* Verify the config */
    retVal = RTIDwwdWindowVerifyConfig(rtiModule, rtiReaction,
                                    rtiPreload_value,
                                    rtiWindow_size);
    if (retVal == CSL_EFAIL)
    {
        UART_printf("Error during Window Verify configuration.\n");
    }

    if (retVal == CSL_PASS)
    {
        /* Configure RTI and do not service. Generates End time violation. */
        UART_printf("DWWD is configured for %u ms time-out \n",
            testParams->rtiConfigParams.rtiTimeoutVal);
        UART_printf("DWWD will generate interrupt after "
            "above time-out period.\n");
        RTIDwwdCounterEnable(rtiModule);
        /* Let DWWD expire here */
        UART_printf("Wait for %u ms for interrupt "
            "to be generated by DWWD.\n", testParams->rtiConfigParams.rtiTimeoutVal);

        while (RTI_NO_INTERRUPT == isrFlag)
        {
            /* Wait for interrupt */
        }
        isrFlag = RTI_NO_INTERRUPT;

        RTIAppExpiredDwwdService(rtiModule, rtiWindow_size);
        if (retVal == STW_SOK)
        {
            UART_printf("RTI End time violation test successful. \n\n");
        }
        else
        {
            UART_printf("RTI End time violation test failed. \n");
        }
    }
    if ((retVal == STW_SOK) &&
        (rtiWindow_size != RTI_DWWD_WINDOWSIZE_100_PERCENT))
    {
        /* RTI is serviced in closed window. Generates DWWD violation.
         * Closed window violation cant be generated for 100% window size.
         */
        volatile uint32_t loopBreak = FALSE;
        isrFlag = RTI_NO_INTERRUPT;
        while (loopBreak == FALSE)
        {
            UART_printf("RTI DWWD closed window violation test running. \n");
            RTIDwwdIsClosedWindow(rtiModule, &closedWinStatus);
            if (closedWinStatus == TRUE)
            {
                loopBreak = TRUE;
                RTIDwwdService(rtiModule);
                while (RTI_NO_INTERRUPT == isrFlag)
                {
                    /* Wait for interrupt */
                }
            }
            else
            {
                /* DWWD is in open window, just service it. */
                RTIDwwdService(rtiModule);
            }
        }
        if (retVal == STW_SOK)
        {
            UART_printf("RTI DWWD closed window violation test successful. \n\n");
        }
        else
        {
            UART_printf("RTI DWWD closed window violation test failed. \n");
        }
    }
    if (retVal == STW_SOK)
    {
        int32_t numIteration = 3;
        UART_printf("RTI DWWD proper servicing test running. \n");
        UART_printf("Please wait for max %d ms. \n", 3 * testParams->rtiConfigParams.rtiTimeoutVal);
        isrFlag = RTI_NO_INTERRUPT;
        /* Service DWWD in open window multiple times. Should not generate interrupt.
         * servicing 3 times, will run RTI for more than configured timeout for all window sizes. */
        while (numIteration-- >= 0)
        {
            RTIDwwdIsClosedWindow(rtiModule, &closedWinStatus);
            while (closedWinStatus == TRUE)
            {
                RTIDwwdIsClosedWindow(rtiModule, &closedWinStatus);
                /* Keep checking till window is open. */
                Osal_delay(1U);
            }
            RTIDwwdService(rtiModule);
        }
        if (isrFlag != RTI_NO_INTERRUPT)
        {
            /* DWWD interrupt is generated when it is not expected to. */
            retVal = STW_EFAIL;
        }
        if (retVal == STW_SOK)
        {
            UART_printf("RTI DWWD proper servicing test successful. \n\n");
        }
        else
        {
            UART_printf("RTI DWWD proper servicing test failed. \n");
        }
    }
    RTIInterruptUnregister();

    return retVal;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */
static void RTIAppExpiredDwwdService(uint32_t rtiModule, uint32_t rtiWindow_size)
{
    /* Set dwwd window size to 100 percent. */
    RTIDwwdSetWindowSize(rtiModule, RTI_DWWD_WINDOWSIZE_100_PERCENT);
    Osal_delay(1U);
    /* Servicing watchdog will generate error. */
    RTIDwwdService(rtiModule);
    RTIDwwdSetWindowSize(rtiModule, rtiWindow_size);
    Osal_delay(1U);
    /* Service watchdog again. */
    RTIDwwdService(rtiModule);
}

static void RTISetClockSource(uint32_t rtiModuleSelect,
                              uint32_t rtiClockSourceSelect)
{
    switch (rtiModuleSelect) {
        case CSL_MCU_RTI0_CFG_BASE:
            HW_WR_FIELD32(CSL_MCU_CTRL_MMR0_CFG0_BASE +
                          CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL,
                          CSL_MCU_CTRL_MMR_CFG0_MCU_RTI0_CLKSEL_CLK_SEL,
                          rtiClockSourceSelect);
            break;
        case CSL_MCU_RTI1_CFG_BASE:
            HW_WR_FIELD32(CSL_MCU_CTRL_MMR0_CFG0_BASE +
                          CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL,
                          CSL_MCU_CTRL_MMR_CFG0_MCU_RTI1_CLKSEL_CLK_SEL,
                          rtiClockSourceSelect);
            break;
        default:
            UART_printf("Error : RTI Instance not supported "
                "!!!\r\n");
            break;
    }
}

static void RTIInterruptRegister(uint32_t rtiModuleSelect, rtiIntrType_t intrType)
{
    OsalRegisterIntrParams_t intrPrmsIntr;
    OsalInterruptRetCode_e osalRetVal;
    HwiP_Handle gHwiHandleIntr;
    uint32_t rtiIntNum;

    Osal_RegisterInterrupt_initParams(&intrPrmsIntr);
    intrPrmsIntr.corepacConfig.arg          = (uintptr_t)0;
    intrPrmsIntr.corepacConfig.priority     = 1U;
    intrPrmsIntr.corepacConfig.corepacEventNum = 0U; /* NOT USED ? */

    switch (rtiModuleSelect)
    {
        case CSL_MCU_RTI0_CFG_BASE :
            if (intrType == RTI_CORE_INTERRUPT)
            {
                rtiIntNum = CSL_MCU0_INTR_RTI0_INTR_WWD;
                intrPrmsIntr.corepacConfig.isrRoutine   = &RTIAppCpuISR;
            }
            else
            {
                gEsmInst = CSL_MCU_ESM0_CFG_BASE;
                gEsmEvtNum = MCU_ESM_RTI0_INTR;
                RTIEnableEsm(gEsmInst, gEsmEvtNum);
                rtiIntNum = CSL_MCU0_INTR_ESM1_ESM_INT_HI_LVL;
                intrPrmsIntr.corepacConfig.isrRoutine   = &RTIAppEsmISR;
            }
        break;
        case CSL_MCU_RTI1_CFG_BASE :
            if (intrType == RTI_CORE_INTERRUPT)
            {
                rtiIntNum = CSL_MCU0_INTR_RTI1_INTR_WWD;
                intrPrmsIntr.corepacConfig.isrRoutine   = &RTIAppCpuISR;
            }
            else
            {
                gEsmInst = CSL_MCU_ESM0_CFG_BASE;
                gEsmEvtNum = MCU_ESM_RTI1_INTR;
                RTIEnableEsm(gEsmInst, gEsmEvtNum);
                rtiIntNum  = CSL_MCU0_INTR_ESM1_ESM_INT_HI_LVL;
                intrPrmsIntr.corepacConfig.isrRoutine   = &RTIAppEsmISR;
            }
        break;
        default :
            UART_printf("Error : RTI Instance not supported "
                "!!!\r\n");
        break;
    }

    
    intrPrmsIntr.corepacConfig.intVecNum    = rtiIntNum;

    osalRetVal = Osal_RegisterInterrupt(&intrPrmsIntr, &gHwiHandleIntr);
    if(OSAL_INT_SUCCESS != osalRetVal)
    {
        UART_printf("Error Could not register ISR !!!\n");
    }

    return;
}

static void RTIInterruptUnregister(void)
{
    if (gHwiHandleIntr != NULL)
    {
        Osal_DeleteInterrupt(gHwiHandleIntr, 0U);
        gHwiHandleIntr = NULL;
    }
    return;
}

void RTIEnableEsm(uint32_t esmInst, uint32_t esmEvtNum)
{
    ESMReset(esmInst);

    /* The below function can be changed to force an error for diagnostic
     * reasons. */
    /* make sure we're not in force error mode */
    ESMSetMode(esmInst, ESM_OPERATION_MODE_NORMAL);

    /* Enable this ESM Error Signal */
    ESMEnableIntr(esmInst, esmEvtNum);

    /* Set the output interrupt priority level */
    ESMSetIntrPriorityLvl(esmInst, esmEvtNum, ESM_INTR_PRIORITY_LEVEL_HIGH);

    /* Enable Error Pin on this ESM Error Signal */
    ESMSetInfluenceOnErrPin(esmInst, esmEvtNum, TRUE);

    /* Enable for all ESM Error Signals */
    ESMEnableGlobalIntr(esmInst);
}

static uint32_t RTIGetPreloadValue(uint32_t rtiClkSource, uint32_t timeoutVal)
{
    uint32_t clkFreqKHz       = (uint32_t) RTI_CLOCK_SOURCE_32KHZ_FREQ_KHZ,
             timeoutNumCycles = 0;

    switch (rtiClkSource)
    {
        case RTI_CLOCK_SOURCE_32KHZ:
            clkFreqKHz = (uint32_t) RTI_CLOCK_SOURCE_32KHZ_FREQ_KHZ;
            break;
        default:
            break;
    }
    /* Get the clock ticks for given time-out value */
    timeoutNumCycles = timeoutVal * clkFreqKHz;
    return timeoutNumCycles;
}

static void RTIAppCpuISR(uintptr_t handle)
{
    uint32_t intrStatus;
    uint32_t rtiModule = gCurrentTestParams->rtiConfigParams.rtiModule;

    RTIDwwdGetStatus(rtiModule, &intrStatus);
    RTIDwwdClearStatus(rtiModule, intrStatus);
    isrFlag  |= RTI_CPU_INTERRUPT;
}

static void RTIAppEsmISR(uintptr_t handle)
{
    uint32_t intrStatus;
    uint32_t rtiModule = gCurrentTestParams->rtiConfigParams.rtiModule;

    RTIDwwdGetStatus(rtiModule, &intrStatus);
    RTIDwwdClearStatus(rtiModule, intrStatus);

    /* Clear ESM registers. */
    ESMClearIntrStatus(gEsmInst, gEsmEvtNum);
    ESMResetErrPin(gEsmInst);

    isrFlag  |= RTI_ESM_INTERRUPT;
}

/********************************* End of file ******************************/
