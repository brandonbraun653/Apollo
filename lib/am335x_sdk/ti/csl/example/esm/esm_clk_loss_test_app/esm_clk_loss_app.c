/* =============================================================================
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
 *  \file     esm_clk_loss_app.c
 *
 *  \brief    This file contains ESM test application code for detecting error
 *            signals/interrupts such as clock loss
 *  \details  ESM operational mode is set to normal mode.
 *           Clock loss interrupt is enabled and detected by ESM.
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include <ti/csl/csl_esm.h>
#include <ti/csl/soc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>
/* Interrupt Registrations */
#include <ti/osal/osal.h>
/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

#define MAIN_ESM_INSTANCE   CSL_ESM0_CFG_BASE
#define MCU_ESM_INSTANCE    CSL_MCU_ESM0_CFG_BASE
#define WKUP_ESM_INSTANCE   CSL_WKUP_ESM0_CFG_BASE

#if defined (SOC_AM65XX)
#define MAIN_ESM_INTID      CSL_MCU0_INTR_ESM2_ESM_INT_HI_LVL
#define MCU_ESM_INTID       CSL_MCU0_INTR_ESM1_ESM_INT_HI_LVL
#define WKUP_ESM_INTID      CSL_MCU0_INTR_ESM0_ESM_INT_HI_LVL

#define MAIN_ESM_ERR_SIG    CSL_INTR_POL_GLUELOGIC_HFOSC0_CLKLOSS_GLUELOGIC_HFOSC0_CLKLOSS_BUS_REF_CLK_LOSS_DETECT_OUT
#define MCU_ESM_ERR_SIG     CSL_INTR_POL_GLUELOGIC_HFOSC0_CLKLOSS_GLUELOGIC_HFOSC0_CLKLOSS_BUS_REF_CLK_LOSS_DETECT_OUT
#define WKUP_ESM_ERR_SIG    CSL_INTR_POL_GLUELOGIC_HFOSC0_CLKLOSS_GLUELOGIC_HFOSC0_CLKLOSS_BUS_REF_CLK_LOSS_DETECT_OUT
#else
#define MCU_ESM_INTID       CSLR_MCU_R5FSS0_CORE0_INTR_MCU_ESM0_ESM_INT_HI_LVL_0
#define MCU_ESM_ERR_SIG     CSLR_MCU_ESM0_ESM_LVL_EVENT_MCU_MCAN0_MCANSS_ECC_CORR_LVL_INT_0
#endif
/*
* To change the ESM Instance as desired, use the following definitions:
* - ESM_INSTANCE
* - ESM_INTID
* - ESM_ERR_SIG
*/
#define ESM_INSTANCE        MCU_ESM_INSTANCE
#define ESM_INTID           MCU_ESM_INTID
#define ESM_ERR_SIG         MCU_ESM_ERR_SIG
/* Print buffer character limit for prints- UART or CCS Console */
#define APP_PRINT_BUFFER_SIZE                       (4000U)
/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
volatile Bool ESM_Error = false;
/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   API to initialize ESM
 *
 * \param   none.
 *
 * \retval  none.
 */static void ESMApp_init();

 /**
 * \brief   This is Interrupt Service Routine for ESM. Performs the following:
 *          - Set a boolean flag
 *          - Clear the interrupt in the ESM
 *          - Clear the error pin
 *          - Print a statement
 *          - Leave the ISR and return to main()
 * This can be changed to respond to the desired ESM and the respective error
 * signal, either by using the supplied macros at the top or the macros from
 * the AM65xx CSL.
 * \param   none.
 *
 * \retval  none.*/
static void ESMApp_intrISR(uintptr_t handle);

/**
 * \brief   This API will print on UART/CCS Console.
 *
 * \param   pcString        string to be printed.
 *
 * \return  None.
 */
static void ESMApp_consoleprintf(const char *pcString, ...);

/**
 * \brief   This function registers the ISR for a given instance of ESM
 *
 *
 * \param   None.
 *
 * \retval  CSL_PASS on successful interrupt handler registration.
 */
static int32_t ESMApp_registerIsr( );
/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int main(void)
{
    /*Initialize UART*/
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        ESMApp_consoleprintf("[Error] Board init failed!!\n");
    }
    ESMApp_consoleprintf("\n Starting Application...\n");
    ESMApp_consoleprintf("\n***** MCU R5F Interrupt + ESM example code *****\n");

    /* Initialize the ESM. */
    ESMApp_consoleprintf("Initializing ESM\n");
    ESMApp_init();
    ESMApp_consoleprintf("ESM initialized.\n");

    /* Interrupt hook up */
    ESMApp_consoleprintf("Hooking up ESM High Priority interrupt to VIM\n");
    /* Initialize and Configure Interrupts */
    ESMApp_registerIsr();
    ESMApp_consoleprintf("Interrupts configured\n");

    ESMApp_consoleprintf("    Intentionally setting the ESM error for Clock loss interrupt.\n");
    /*intentionally trip the ESM*/
    ESMSetIntrStatusRAW(ESM_INSTANCE, ESM_ERR_SIG);
    /*See what happens. The ISR should fire off*/
    while(!ESM_Error)
    {
        ESMApp_consoleprintf("Waiting for ESM to receive error\n");
    }
    /*Once Error is recieved by ESM*/
    ESMApp_consoleprintf("ESM has received the error.\n");


    return CSL_PASS;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */
static void ESMApp_consoleprintf(const char *pcString, ...)
{
    static char printBuffer[APP_PRINT_BUFFER_SIZE];
    va_list arguments;

    /* Start the varargs processing. */
    va_start(arguments, pcString);
    vsnprintf(printBuffer, sizeof(printBuffer), pcString, arguments);
    UART_printf(printBuffer);
    printf(printBuffer);
    /* End the varargs processing. */
    va_end(arguments);
}

static void ESMApp_init()
{
    /* ESM Variables */
    esmInfo_t appEsmInfo;

    /* Check INFO register for ESM last reset cause */
    ESMGetInfo(ESM_INSTANCE, &appEsmInfo);
    ESMReset(ESM_INSTANCE);

    /* The below function can be changed to force an error for diagnostic
     * reasons. */
    /* make sure we're not in force error mode */
    ESMSetMode(ESM_INSTANCE, ESM_OPERATION_MODE_NORMAL);

    /* Enable this ESM Error Signal */
    ESMEnableIntr(ESM_INSTANCE, ESM_ERR_SIG);

    /* Set the output interrupt priority level */
    ESMSetIntrPriorityLvl(ESM_INSTANCE, ESM_ERR_SIG, ESM_INTR_PRIORITY_LEVEL_HIGH);

    /* Enable Error Pin on this ESM Error Signal */
    ESMSetInfluenceOnErrPin(ESM_INSTANCE, ESM_ERR_SIG, TRUE);

    /* Enable for all ESM Error Signals */
    ESMEnableGlobalIntr(ESM_INSTANCE);
}

static void ESMApp_intrISR(uintptr_t handle)
{
    ESM_Error = true;
    ESMClearIntrStatus(ESM_INSTANCE, ESM_ERR_SIG);
    ESMResetErrPin(ESM_INSTANCE);
}

static int32_t ESMApp_registerIsr( )
{
    int32_t retVal = CSL_EFAIL;
    uint32_t EsmInt;
    OsalRegisterIntrParams_t intrPrms;
    OsalInterruptRetCode_e osalRetVal;
    HwiP_Handle hwiHandle;

    Osal_RegisterInterrupt_initParams(&intrPrms);
    intrPrms.corepacConfig.arg          = (uintptr_t)0;
    intrPrms.corepacConfig.priority     = 1U;
    intrPrms.corepacConfig.corepacEventNum = 0U; /* NOT USED ? */

    EsmInt = ESM_INTID;
    intrPrms.corepacConfig.isrRoutine   = &ESMApp_intrISR;
    retVal = CSL_PASS;
    intrPrms.corepacConfig.intVecNum = EsmInt;
    osalRetVal = Osal_RegisterInterrupt(&intrPrms, &hwiHandle);
    if(OSAL_INT_SUCCESS != osalRetVal)
    {
        retVal = CSL_EFAIL;
        ESMApp_consoleprintf("Error Could not register ISR !!!\n");
    }
    return (retVal);
}
/********************************* End of file ******************************/
