/**
 *  \file   timer_test.c
 *
 *  \brief  Example application main file for 1 millisecond (1msec) timer test.
 *
 *  Targeted Functionality: Demonstrating the 1msec clock tick
 *  generation by timer module on Sitara platforms.
 *
 *  Operation: Test configures the timer module to generate 1msec tick.
 *  Interrupts are enabled and test waits till timer generates
 *  'TIMER_1MS_TICK_DURATION' number of interrupts. Test is considered
 *  as PASS if wait for interrupt generation equals the number of msecs
 *  defined by 'TIMER_1MS_TICK_DURATION'
 *
 *  Supported SoCs: AM572x, AM571x, AM437x & AM335x
 *
 *  Supported platforms: evmAM572x, idkAM571x, evmAM437x & evmAM335x
 *
 *  Note: Timer configurations are SoC specific and test should run fine
 *  on different HW platforms of a given SoC without any code changes.
 *  New platform support can be added by adding build setup under
 *  'timer/build' folder.
 *
 */

/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#include <timer_test.h>

#if defined (SOC_AM572x) || defined (SOC_AM571x)
extern CSL_ArmGicDistIntrf distrIntrf;
extern CSL_ArmGicCpuIntrf gCpuIntrf;
#endif

CSL_ArmGicIntrParams_t gTimerIntrParams;

/** \brief global flag updated in Interrupt service routine to indicate timer
 *  overflow.*/
static volatile uint32_t gDmtimerIsrFlag = 0;

/**
 * \brief   Function to configure functional clock source for timer module.
 *          32KHz clock source will be used for 1ms tick timer functionality
 *
 */
static void BoardDiag_timerClkCfg(void)
{
    uint32_t regVal;

#if defined (SOC_AM572x) || defined (SOC_AM571x)
    /* Select the 32K Clock source for the timer to generate 1ms tick. */
    HW_WR_FIELD32(CSL_MPU_WKUPAON_CM_REGS + CM_WKUPAON_TIMER1_CLKCTRL,
                  CSL_WKUPAON_CM_CM_WKUPAON_TIMER1_CLKCTRL_REG_CLKSEL,
                  CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK);

    while (((HW_RD_REG32(CSL_MPU_WKUPAON_CM_REGS + CM_WKUPAON_TIMER1_CLKCTRL) &
             CSL_WKUPAON_CM_CM_WKUPAON_TIMER1_CLKCTRL_REG_CLKSEL_MASK) >> \
             CSL_WKUPAON_CM_CM_WKUPAON_TIMER1_CLKCTRL_REG_CLKSEL_SHIFT) != \
             CM_WKUPAON_TIMER1_CLKCTRL_CLKSEL_SEL_SYS_CLK1_32K_CLK);
#else

#if defined (SOC_AM335x)
    regVal = HW_RD_REG32(SOC_CM_WKUP_REGS + CM_WKUP_TIMER1_CLKCTRL);
    regVal |= CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_ENABLE;
    HW_WR_REG32((SOC_CM_WKUP_REGS + CM_WKUP_TIMER1_CLKCTRL), regVal);
    while ((HW_RD_REG32(SOC_CM_WKUP_REGS + CM_WKUP_TIMER1_CLKCTRL) & \
           CM_WKUP_TIMER1_CLKCTRL_MODULEMODE) != \
           CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_ENABLE);

    HW_WR_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER1MS_CLK, 1);
    while ((HW_RD_REG32(SOC_CM_DPLL_REGS + CM_DPLL_CLKSEL_TIMER1MS_CLK) & 0x1) != 0x1);

#endif

#if defined (SOC_AM437x)
    regVal = HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_WKUP_TIMER1_CLKCTRL);
    regVal |= PRCM_CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_ENABLE;
    HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_WKUP_TIMER1_CLKCTRL), regVal);
    while ((HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_WKUP_TIMER1_CLKCTRL) & \
           PRCM_CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_MASK) != \
           PRCM_CM_WKUP_TIMER1_CLKCTRL_MODULEMODE_ENABLE);

    HW_WR_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER1_CLK, 1);
    while ((HW_RD_REG32(SOC_CM_DPLL_REG + PRCM_CM_DPLL_CLKSEL_TIMER1_CLK) & 0x1) != 0x1);
#endif

#endif  /* #if defined (SOC_AM572x) || defined (SOC_AM571x) */
}

/**
 * \brief   Set up the Timer Module for Countdown timer operation.
 *
 *
 */
void BoardDiag_TimerSetup(void)
{
    /* Setup the clock source for timer */
    BoardDiag_timerClkCfg();

#if defined (SOC_AM572x) || defined (SOC_AM571x)

    TIMERReset(TIMER_BASE_ADDR);

    TIMERCounterSet(TIMER_BASE_ADDR, TIMER_INITIAL_COUNT);

    TIMERReloadSet(TIMER_BASE_ADDR, TIMER_RLD_COUNT);

    TIMERTPIRSet(TIMER_BASE_ADDR, TPIR_VALUE);

    TIMERTNIRSet(TIMER_BASE_ADDR, TNIR_VALUE);

    TIMERModeConfigure(TIMER_BASE_ADDR, TIMER_AUTORLD_NOCMP_ENABLE);

    TIMERTOWRSet(TIMER_BASE_ADDR, INTR_MASK_COUNT);

    TIMERIntEnable(TIMER_BASE_ADDR, TIMER_INT_OVF_EN_FLAG);

#else

    DMTIMER1MSReset(TIMER_BASE_ADDR);

    DMTIMER1MSCounterSet(TIMER_BASE_ADDR, TIMER_INITIAL_COUNT);

    DMTIMER1MSReloadSet(TIMER_BASE_ADDR, TIMER_RLD_COUNT);

    DMTIMER1MSTPIRSet(TIMER_BASE_ADDR, TPIR_VALUE);

    DMTIMER1MSTNIRSet(TIMER_BASE_ADDR, TNIR_VALUE);

    DMTIMER1MSModeConfigure(TIMER_BASE_ADDR, TIMER_AUTORLD_NOCMP_ENABLE);

    DMTIMER1MSTOWRSet(TIMER_BASE_ADDR, INTR_MASK_COUNT);

    DMTIMER1MSIntEnable(TIMER_BASE_ADDR, TIMER_INT_OVF_EN_FLAG);

#endif  /* #if defined (SOC_AM572x) || defined (SOC_AM571x) */

    UART_printf("Timer Configured for 1msec interrupt\n");
}

/**
 * \brief    Function Starts the Timer and tracks the count.
 *
 */
void BoardDiag_TimerRun(void)
{
    uint32_t countVal = TIMER_1MS_TICK_DURATION;

    UART_printf("Enabling Timer Interrupts\n");
    UART_printf("Test waits till Timer generates %d (~%dsecs) interrupts \n",
                countVal, (countVal/1000));

#if defined (SOC_AM572x) || defined (SOC_AM571x)
    /* Start the Timer. */
    TIMEREnable(TIMER_BASE_ADDR);
#else
    /* Start the Timer. */
    DMTIMER1MSEnable(TIMER_BASE_ADDR);
#endif

    /* Timer triggers an interrupt for 1-msec.
       Wait till all the interrupts are triggered based on 'countVal' value */
    while(countVal)
    {
        if(gDmtimerIsrFlag == 1)
        {
            countVal--;
            gDmtimerIsrFlag = 0U;
        }
    }

#if defined (SOC_AM572x) || defined (SOC_AM571x)
    TIMERIntDisable(TIMER_BASE_ADDR, TIMER_INT_OVF_EN_FLAG);
    TIMERDisable(TIMER_BASE_ADDR);
#else
    DMTIMER1MSIntDisable(TIMER_BASE_ADDR, TIMER_INT_OVF_EN_FLAG);
    DMTIMER1MSDisable(TIMER_BASE_ADDR);
#endif
}

/**
 * \brief    Function to initialize ARM interrupt module
 *
 */
void BoardDiag_TimerIntrInit(void)
{
#if defined (SOC_AM572x) || defined (SOC_AM571x)
    gCpuIntrf.gicDist = &distrIntrf;
    gCpuIntrf.cpuIntfBasePtr = (void *)SOC_INTC_MPU_PHYS_CPU_IF_BASE;
    distrIntrf.distBasePtr = (void *)SOC_INTC_MPU_DISTRIBUTOR_BASE;
    gCpuIntrf.initStatus = FALSE;
    gCpuIntrf.gicDist->initStatus = FALSE;
    gCpuIntrf.pDefaultIntrHandlers = NULL;
    gCpuIntrf.pDefaultUserParameter = NULL;

    CSL_armGicInit(&gCpuIntrf);
#else
    INTCInit(FALSE);
#endif

}

/**
 * \brief    Function configures the Interrupt Controller for Timer module
 *           operation.
 *
 */
void BoardDiag_TimerIntrConfig(void)
{
#if defined (SOC_AM572x) || defined (SOC_AM571x)
    gTimerIntrParams.pFnIntrHandler = &BoardDiag_TimerIsr;
    gTimerIntrParams.pUserParam = NULL;
    /* Do the interrupt related configurations */
    gTimerIntrParams.triggerType = CSL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL;
    gTimerIntrParams.priority = 0x20U;

    /* Configure the interrupt Controller */
    CSL_armGicConfigIntr(&gCpuIntrf, (TIMER_INTR_NUM + 32),
                         &gTimerIntrParams);
#else
    intcIntrParams_t intrParams;
    intrParams.triggerType = INTC_TRIG_HIGH_LEVEL;

    /* Currently hard coded priority number */
    intrParams.priority = 0x20U;
    intrParams.pFnIntrHandler = BoardDiag_TimerIsr;
    /* Pointer to the app object being passed to handler */
    intrParams.pUserParam = NULL;
    /* Currently hard coded - non secure mode */
    intrParams.isIntrSecure = FALSE;

    INTCConfigIntr(TIMER_INTR_NUM, &intrParams, FALSE);
#endif
}

/*
* DMTimer interrupt service routine. This ISR sets the shared variable on
* hitting an overflow interrupt - this is not a generic ISR
*/
#if defined (SOC_AM572x) || defined (SOC_AM571x)
void BoardDiag_TimerIsr(void* pUserParam)
#else
void BoardDiag_TimerIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
#endif
{
#if defined (SOC_AM572x) || defined (SOC_AM571x)
    /* Disable the DMTimer interrupts */
    TIMERIntDisable(TIMER_BASE_ADDR, TIMER_INT_OVF_EN_FLAG);

    /* Clear the status of the interrupt flags */
    TIMERIntStatusClear(TIMER_BASE_ADDR, TIMER_INT_OVF_EN_FLAG);
    gDmtimerIsrFlag = 1U;

    /* Enable the DMTimer interrupts */
    TIMERIntEnable(TIMER_BASE_ADDR, TIMER_INT_OVF_EN_FLAG);
#else
    /* Disable the DMTimer interrupts */
    DMTIMER1MSIntDisable(TIMER_BASE_ADDR, TIMER_INT_OVF_EN_FLAG);

    /* Clear the status of the interrupt flags */
    DMTIMER1MSIntStatusClear(TIMER_BASE_ADDR, TIMER_INT_OVF_EN_FLAG);
    gDmtimerIsrFlag = 1U;

    /* Enable the DMTimer interrupts */
    DMTIMER1MSIntEnable(TIMER_BASE_ADDR, TIMER_INT_OVF_EN_FLAG);
#endif
}

/**
 * \brief    Function to demonstrate the working of Timer module.
 *
 * \retval   0    on success.
 * \retval   -1    on failure.
 */
int BoardDiag_TimerTest(void)
{
    int ret = 0;
    char input;

    UART_printf("\n*********************************************\n");
    UART_printf  ("*              1MSEC TIMER Test             *\n");
    UART_printf  ("*********************************************\n\n");

    /* Configure and setup the timer for 1ms tick */
    BoardDiag_TimerIntrConfig();
    BoardDiag_TimerSetup();

    /* Start the timer and wait for timer interrupts */
    BoardDiag_TimerRun();

    UART_printf("\nPress 'y' if timer ran for correct duration, else any other key:");
    UART_scanFmt("%c", &input);
    if ( (input == 'y') || (input == 'Y') )
    {
        UART_printf("\nTest PASSED!\n");
    }
    else
    {
        UART_printf("\nTest FAILED!\n");
        ret = -1;
    }

    return ret;
}

/*
 *  ======== main ========
 */
int main(void)
{
    Board_initCfg boardCfg;

#if defined (SOC_AM572x) || defined (SOC_AM571x)
    /* Copy the vector table to desired location.  */
    CSL_A15_INIT_copyVectorTable();
#else
    CopyVectorTable();
#endif

    /* Initialize interrupt module */
    BoardDiag_TimerIntrInit();

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

    return BoardDiag_TimerTest();
}
