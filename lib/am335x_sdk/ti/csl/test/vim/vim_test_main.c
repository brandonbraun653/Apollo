/* Copyright (c) 2019 Texas Instruments Incorporated
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
 *  \file     vim_test_main.c
 *
 *  \brief    This file contains VIM test code for R5 core.
 *
 *  \details  VIM register read/write and configuration tests
 **/

/*===========================================================================*/
/*                         Include files                                     */
/*===========================================================================*/
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <ti/csl/csl_types.h>
#include <ti/csl/soc.h>
#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/hw_types.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/board/board.h>
#include <vim_test_interrupt.h>

/*===========================================================================*/
/*                         Declarations                                      */
/*===========================================================================*/

/* Define the test interface */
typedef struct cslVimTest_s
{
    int32_t (*testFunction)(void);      /* The code that runs the test */
    char                *name;          /* The test name */
    int32_t              testStatus;    /* Test status */
} cslVimTest_t;

/*===========================================================================*/
/*                         Macros                                            */
/*===========================================================================*/
#define CSL_VIM_TEST_NOT_RUN        (-(int32_t) (2))
#define CSL_VIM_TEST_FAILED         (-(int32_t) (1))
#define CSL_VIM_TEST_PASS           ( (int32_t) (0))
#define CSL_VIM_DEFAULT_PRIORITY    ((uint32_t) 0x0FU)
#define CSL_VIM_TEST_INT_NUM_IRQ    ((uint32_t) 32u)
#define CSL_VIM_TEST_VIM_BASE_ADDR  ((uint32_t)(0x103E0u << 14u))
#define CSL_VIM_TEST_VEC_ADDR       (0U)
#define CSL_VIM_TEST_VEC_ADDR2      (4U)

#define CSL_VIM_INVALID_INT_NUM     (CSL_VIM_NUM_INTRS_PER_GROUP * CSL_VIM_MAX_INTR_GROUPS)
#define CSL_VIM_INVALID_PRI_VAL     (CSL_VIM_PRI_INT_VAL_MAX + 1U)
#define CSL_VIM_INVALID_INT_MAP     (CSL_VIM_INTR_MAP_FIQ + 1U)
#define CSL_VIM_INVALID_INT_TYPE    (CSL_VIM_INTR_TYPE_PULSE + 1U)
#define CSL_VIM_INVALID_VEC_ADDR    (1U)

/*===========================================================================*/
/*                         Internal function declarations                    */
/*===========================================================================*/
static int32_t cslVim_cfgTest(void);
static int32_t cslVim_rdBkRegs(void);
static int32_t cslVim_cfgDEDVec(void);
static int32_t cslApp_initBoard(void);
static int32_t cslVim_apisTest(void);
static int32_t cslVim_negTest(void);
static void cslApp_print(const char * str);

/*===========================================================================*/
/*                         Global Variables                                  */
/*===========================================================================*/
cslVimTest_t  cslVimTestList[] = {
    {cslVim_cfgTest,   "PRSDK-1698: VIM CFG TEST",       CSL_VIM_TEST_NOT_RUN },
    {cslVim_rdBkRegs,  "PRSDK-1699: VIM READ BACK REGS", CSL_VIM_TEST_NOT_RUN },
    {cslVim_cfgDEDVec, "PRSDK-1702: VIM CFG DED VEC",    CSL_VIM_TEST_NOT_RUN },
    {cslVim_apisTest,  "VIM LDRA APIS TEST",             CSL_VIM_TEST_NOT_RUN },
    {cslVim_negTest,   "VIM LDRA NEG TEST",              CSL_VIM_TEST_NOT_RUN },
    {NULL,             "TERMINATING CONDITION",          CSL_VIM_TEST_NOT_RUN }
};

/*===========================================================================*/
/*                   Local Function definitions                              */
/*===========================================================================*/

static void cslApp_print(const char * str)
{
    UART_printf(str);
}

static void cslApp_printArg(uint32_t value)
{
   UART_printf("0x%x \n", value);
}

/* initialize the board for the application */
static int32_t  cslApp_initBoard(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        cslApp_print("[Error] Board init failed!!\n");
    }
    return (boardStatus);
}

/* test isr */
static uint32_t cslVim_testIsrCount = 0;
static void cslVim_testIsr(void)
{
    cslVim_testIsrCount++;
}
/* Test case for PRSDK-1698: VIM Software to provide API to configure R5 VIM */
static int32_t cslVim_cfgTest(void)
{
    int32_t             retVal = CSL_PASS;
    int32_t             i, testStatus = CSL_VIM_TEST_FAILED;
    CSL_vimRegs        *pVimRegs;
    CSL_ArmR5CPUInfo    info;
    CSL_vimStaticRegs   sRegs1, sRegs2;
    uint32_t            intrNum = CSL_VIM_TEST_INT_NUM_IRQ;
    uint32_t            intrPending;
    uint32_t            mask;

    CSL_armR5GetCpuID(&info);
    if (info.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
    {
        /* MCU SS Pulsar R5 SS */
        pVimRegs = (CSL_vimRegs *)CSL_MCU_DOMAIN_VIM_BASE_ADDR;
    }
    else
    {
        /* MAIN SS Pulsar R5 SS */
        pVimRegs = (CSL_vimRegs *)CSL_MAIN_DOMAIN_VIM_BASE_ADDR;
    }

    /* initialize the VIM for the test interrupt */
    vimTest_Intc_Init();
    vimTest_Intc_IntSetSrcType(intrNum, CSL_VIM_INTR_TYPE_LEVEL);
    /* Registering the Interrupt Service Routine(ISR). */
    vimTest_Intc_IntRegister((uint16_t)intrNum, (IntrFuncPtr) cslVim_testIsr, (void *)NULL);
    /* Setting the priority for the UART interrupt in INTC. */
    vimTest_Intc_IntPrioritySet((uint16_t)intrNum, CSL_VIM_DEFAULT_PRIORITY, 0);
    /* Disabling the interrupt in INTC. */
    vimTest_Intc_IntDisable(intrNum);
    vimTest_Intc_SystemEnable();

    /* Set the interrupt pending to test using VIM APIs directly */
    retVal = CSL_vimSetIntrPending(pVimRegs, intrNum);
    if (retVal == CSL_PASS)
    {
        /* Read back the interrupt pending */
        intrPending = CSL_vimGetGroupIntrPending(pVimRegs,
                                                 CSL_VIM_INTR_MAP_IRQ,
                                                 intrNum / CSL_VIM_NUM_INTRS_PER_GROUP,
                                                 (bool)false);
        mask   = (((uint32_t)(1U)) << (intrNum & (CSL_VIM_NUM_INTRS_PER_GROUP-1U)));

        if ((intrPending & mask) != mask)
        {
            testStatus = CSL_VIM_TEST_FAILED;
        }
    }

    /* Enabling the interrupt in INTC to fire ISR */
    vimTest_Intc_IntEnable(intrNum);

    if (retVal == CSL_PASS)
    {
        /* check for interrupt fired */
        for (i = 0; i < 100; i++)
        {
            if (cslVim_testIsrCount != 0)
            {
                testStatus =  CSL_VIM_TEST_PASS;
                break;
            }
        }
    }
    
    vimTest_Intc_IntUnregister((uint16_t)intrNum);

    if (testStatus == CSL_VIM_TEST_PASS)
    {
        cslApp_print("\n cslVim_cfgTest : pass \n");
    }
    else
    {
        cslApp_print("\n cslVim_cfgTest : fail \n");
    }

    return (testStatus);
}

/* Test for PRSDK-1699: The CSL test is a basic test that verifies 
 * basic readback of the VIM registers
 * the acutual functionality test is done under Safety SDL
 */
static int32_t cslVim_rdBkRegs(void)
{
    int32_t              testStatus, cslRet, i;
    uint32_t             vimBaseAddr, isDifferent;
    uint32_t            *p1, *p2;
    CSL_ArmR5CPUInfo     info;
    CSL_vimStaticRegs    sRegs1, sRegs2;
    uint32_t             intrNum;
    CSL_VimIntrType      intrType;

    /* Clear the stack variables */
    memset(&sRegs1, 0, sizeof(CSL_vimStaticRegs));
    memset(&sRegs2, 0, sizeof(CSL_vimStaticRegs));

    CSL_armR5GetCpuID(&info);
    if (info.grpId == (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
    {
        /* MCU SS Pulsar R5 SS */
        vimBaseAddr = CSL_MCU_DOMAIN_VIM_BASE_ADDR;
    }
    else
    {
        /* MAIN SS Pulsar R5 SS */
        vimBaseAddr = CSL_MAIN_DOMAIN_VIM_BASE_ADDR;
    }

    /* Config and Check the VIM Cfg and Check VIM Cfg APIs */
    intrNum = CSL_VIM_TEST_INT_NUM_IRQ;
    intrType = CSL_VIM_INTR_TYPE_PULSE;
    cslRet = CSL_vimCfgIntr( (CSL_vimRegs *)(uintptr_t)vimBaseAddr, intrNum,
                    CSL_VIM_DEFAULT_PRIORITY, (CSL_VimIntrMap)CSL_VIM_INTR_MAP_IRQ,
                    intrType, (uint32_t)&cslVim_testIsr);

    if (cslRet == CSL_PASS)
    {
        cslRet = CSL_vimGetIntrType((CSL_vimRegs *)(uintptr_t)vimBaseAddr, intrNum);
        if (cslRet == ((int32_t)intrType))
        {
            cslRet = CSL_PASS;
        }
        else
        {
            cslRet = CSL_EFAIL;
        }
    }

    if (cslRet == CSL_PASS)
    {
         cslRet = CSL_vimReadBackStaticRegs((CSL_vimRegs *)(uintptr_t)vimBaseAddr,
                                      &sRegs1);

        /* Sample register read back example */
        /* Read the PID and Display */
        cslApp_print("\n cslVim_PID is : ");
        cslApp_printArg (sRegs1.PID);
        cslApp_print("\n");
        testStatus = CSL_VIM_TEST_PASS;
    }

    /* Read back the registers */
    if (cslRet == CSL_PASS)
    {
        cslRet = CSL_vimVerifyCfgIntr( (CSL_vimRegs *)(uintptr_t)vimBaseAddr, intrNum,
                    CSL_VIM_DEFAULT_PRIORITY, (CSL_VimIntrMap)CSL_VIM_INTR_MAP_IRQ,
                    intrType, (uint32_t)&cslVim_testIsr);
    }

    /* Verify ReadBack of Static registers API */
    if (cslRet == CSL_PASS)
    {
        cslRet = CSL_vimReadBackStaticRegs((CSL_vimRegs *)(uintptr_t)vimBaseAddr,
                                      &sRegs2);
    }

    /* Compare check the static register reads */
    p1 = (uint32_t *) (&sRegs1);
    p2 = (uint32_t *) (&sRegs2);
    for ( i = 0, isDifferent = 0u; i < (sizeof(CSL_vimStaticRegs)/4u); i++)
    {
         if (*p1++ != *p2++)
         {
             isDifferent = 1u;
             cslApp_print (" static register read back mismatch at offset: ");
             cslApp_printArg (i);
             cslApp_print("\n");
             break;
         }
    }


    if (cslRet == CSL_PASS)
    {
        testStatus = CSL_VIM_TEST_PASS;
    }
    else
    {
        testStatus = CSL_VIM_TEST_FAILED;
    }

    if (isDifferent != 0u)
    {
        testStatus = CSL_VIM_TEST_FAILED;
    }

    return (testStatus);
}

/* Test for PRSDK-1702: The CSL test is basic that verifies 
 * basic read/write of the registers
 * the acutual functionality test is done under Safety SDL
 */
static int32_t cslVim_cfgDEDVec(void)
{
    int32_t          retVal = 0, testStatus;
    CSL_vimRegs     *pVimRegs;
    uint32_t         testDEDVecAddr, dedVecRdAddr;

    /* initialize the address */
    pVimRegs        = (CSL_vimRegs *)(uintptr_t)CSL_VIM_TEST_VIM_BASE_ADDR;

    /* dummy DED vector address */
    testDEDVecAddr = (uint32_t) 0x12345678;
    CSL_vimSetDedVectorAddr(pVimRegs, testDEDVecAddr);

    testStatus = CSL_VIM_TEST_FAILED;

    /* Readback the register to check if it is set correctly from CSL */
    retVal = CSL_vimGetDedVectorAddr(pVimRegs, &dedVecRdAddr);
    if (retVal == CSL_PASS)
    {
        if (dedVecRdAddr == testDEDVecAddr)
        {
            testStatus = CSL_VIM_TEST_PASS;
        }
    }

    if (testStatus == CSL_VIM_TEST_PASS)
    {
        cslApp_print("\n cslVim_cfgDEDVec : pass \n");
    }
    else
    {
        cslApp_print("\n cslVim_cfgDEDVec : fail \n");
        testStatus = CSL_VIM_TEST_FAILED;
    }

    return (testStatus);
}

static int32_t cslVim_apisTest(void)
{
    int32_t          testStatus = CSL_VIM_TEST_PASS;
    CSL_vimRegs     *pVimRegs;
    uint32_t         irqVectAddr;
    uint32_t         fiqVectAddr;

    /* initialize the address */
    pVimRegs        = (CSL_vimRegs *)(uintptr_t)CSL_VIM_TEST_VIM_BASE_ADDR;

    if (CSL_vimGetRevision(pVimRegs) == 0U)
    {
        testStatus = CSL_VIM_TEST_FAILED;
    }

    if (testStatus == CSL_VIM_TEST_PASS)
    {
        if (CSL_vimGetNumIntrs(pVimRegs) == 0U)
        {
            testStatus = CSL_VIM_TEST_FAILED;
        }
    }

    if (testStatus == CSL_VIM_TEST_PASS)
    {
        irqVectAddr = CSL_vimGetIrqVectorAddress(pVimRegs);
        fiqVectAddr = CSL_vimGetFiqVectorAddress(pVimRegs);
    }

    if (testStatus == CSL_VIM_TEST_PASS)
    {
        if (CSL_vimGetGroupsIntrPending(pVimRegs, CSL_VIM_INTR_MAP_IRQ) != 0U)
        {
            testStatus = CSL_VIM_TEST_FAILED;
        }
    }

    if (testStatus == CSL_VIM_TEST_PASS)
    {
        cslApp_print("\n cslVim_apisTest : pass \n");
        cslApp_print (" IRQ Vector address is ");
        cslApp_printArg (irqVectAddr);
        cslApp_print (" FIQ Vector address is ");
        cslApp_printArg (fiqVectAddr);
        cslApp_print("\n");
    }
    else
    {
        cslApp_print("\n cslVim_apisTest : fail \n");
        testStatus = CSL_VIM_TEST_FAILED;
    }

    return (testStatus);
}

static int32_t cslVim_negTest(void)
{
    int32_t            testStatus = CSL_VIM_TEST_FAILED;
    CSL_vimRegs       *pVimRegs = (CSL_vimRegs *)(uintptr_t)CSL_VIM_TEST_VIM_BASE_ADDR;
    CSL_vimStaticRegs  staticRegs;
    uint32_t           val;
    uint32_t           val2;

    /* CSL_vimGetRevision negtive test */
    if (CSL_vimGetRevision(NULL) != 0U)
    {
        UART_printf("CSL_vimGetRevision: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimGetNumIntrs negtive test */
    if (CSL_vimGetNumIntrs(NULL) != 0U)
    {
        UART_printf("CSL_vimGetNumIntrs: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimCfgIntr negtive test */
    if (CSL_vimCfgIntr(NULL,
                       CSL_VIM_TEST_INT_NUM_IRQ,
                       CSL_VIM_PRI_INT_VAL_MAX,
                       CSL_VIM_INTR_MAP_IRQ,
                       CSL_VIM_INTR_TYPE_LEVEL,
                       CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimCfgIntr(pVimRegs,
                       CSL_VIM_INVALID_INT_NUM,
                       CSL_VIM_PRI_INT_VAL_MAX,
                       CSL_VIM_INTR_MAP_IRQ,
                       CSL_VIM_INTR_TYPE_LEVEL,
                       CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimCfgIntr(pVimRegs,
                       CSL_VIM_TEST_INT_NUM_IRQ,
                       CSL_VIM_INVALID_PRI_VAL,
                       CSL_VIM_INTR_MAP_IRQ,
                       CSL_VIM_INTR_TYPE_LEVEL,
                       CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimCfgIntr(pVimRegs,
                       CSL_VIM_TEST_INT_NUM_IRQ,
                       CSL_VIM_PRI_INT_VAL_MAX,
                       CSL_VIM_INVALID_INT_MAP,
                       CSL_VIM_INTR_TYPE_LEVEL,
                       CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimCfgIntr(pVimRegs,
                       CSL_VIM_TEST_INT_NUM_IRQ,
                       CSL_VIM_PRI_INT_VAL_MAX,
                       CSL_VIM_INTR_MAP_IRQ,
                       CSL_VIM_INVALID_INT_TYPE,
                       CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimCfgIntr(pVimRegs,
                       CSL_VIM_TEST_INT_NUM_IRQ,
                       CSL_VIM_PRI_INT_VAL_MAX,
                       CSL_VIM_INTR_MAP_IRQ,
                       CSL_VIM_INTR_TYPE_LEVEL,
                       CSL_VIM_INVALID_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimVerifyCfgIntr negtive test */
    if (CSL_vimVerifyCfgIntr(NULL,
                             CSL_VIM_TEST_INT_NUM_IRQ,
                             CSL_VIM_PRI_INT_VAL_MAX,
                             CSL_VIM_INTR_MAP_IRQ,
                             CSL_VIM_INTR_TYPE_LEVEL,
                             CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimVerifyCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimVerifyCfgIntr(pVimRegs,
                             CSL_VIM_INVALID_INT_NUM,
                             CSL_VIM_PRI_INT_VAL_MAX,
                             CSL_VIM_INTR_MAP_IRQ,
                             CSL_VIM_INTR_TYPE_LEVEL,
                             CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimVerifyCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimVerifyCfgIntr(pVimRegs,
                             CSL_VIM_TEST_INT_NUM_IRQ,
                             CSL_VIM_INVALID_PRI_VAL,
                             CSL_VIM_INTR_MAP_IRQ,
                             CSL_VIM_INTR_TYPE_LEVEL,
                             CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimVerifyCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimVerifyCfgIntr(pVimRegs,
                             CSL_VIM_TEST_INT_NUM_IRQ,
                             CSL_VIM_PRI_INT_VAL_MAX,
                             CSL_VIM_INVALID_INT_MAP,
                             CSL_VIM_INTR_TYPE_LEVEL,
                             CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimVerifyCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimVerifyCfgIntr(pVimRegs,
                             CSL_VIM_TEST_INT_NUM_IRQ,
                             CSL_VIM_PRI_INT_VAL_MAX,
                             CSL_VIM_INTR_MAP_IRQ,
                             CSL_VIM_INVALID_INT_TYPE,
                             CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimVerifyCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimVerifyCfgIntr(pVimRegs,
                             CSL_VIM_TEST_INT_NUM_IRQ,
                             CSL_VIM_PRI_INT_VAL_MAX,
                             CSL_VIM_INTR_MAP_IRQ,
                             CSL_VIM_INTR_TYPE_LEVEL,
                             CSL_VIM_INVALID_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimVerifyCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    if (CSL_vimCfgIntr(pVimRegs,
                       CSL_VIM_TEST_INT_NUM_IRQ,
                       CSL_VIM_PRI_INT_VAL_MAX,
                       CSL_VIM_INTR_MAP_IRQ,
                       CSL_VIM_INTR_TYPE_LEVEL,
                       CSL_VIM_TEST_VEC_ADDR) != CSL_PASS)
    {
        UART_printf("CSL_vimCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimVerifyCfgIntr(pVimRegs,
                             CSL_VIM_TEST_INT_NUM_IRQ,
                             CSL_VIM_PRI_INT_VAL_MAX - 1U,
                             CSL_VIM_INTR_MAP_IRQ,
                             CSL_VIM_INTR_TYPE_LEVEL,
                             CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimVerifyCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimVerifyCfgIntr(pVimRegs,
                             CSL_VIM_TEST_INT_NUM_IRQ,
                             CSL_VIM_PRI_INT_VAL_MAX,
                             CSL_VIM_INTR_MAP_FIQ,
                             CSL_VIM_INTR_TYPE_LEVEL,
                             CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimVerifyCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimVerifyCfgIntr(pVimRegs,
                             CSL_VIM_TEST_INT_NUM_IRQ,
                             CSL_VIM_PRI_INT_VAL_MAX,
                             CSL_VIM_INTR_MAP_IRQ,
                             CSL_VIM_INTR_TYPE_PULSE,
                             CSL_VIM_TEST_VEC_ADDR) != CSL_EFAIL)
    {
        UART_printf("CSL_vimVerifyCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimVerifyCfgIntr(pVimRegs,
                             CSL_VIM_TEST_INT_NUM_IRQ,
                             CSL_VIM_PRI_INT_VAL_MAX,
                             CSL_VIM_INTR_MAP_IRQ,
                             CSL_VIM_INTR_TYPE_LEVEL,
                             CSL_VIM_TEST_VEC_ADDR2) != CSL_EFAIL)
    {
        UART_printf("CSL_vimVerifyCfgIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimSetDedVectorAddr negtive test */
    CSL_vimSetDedVectorAddr(NULL, 0U);

    /* CSL_vimGetDedVectorAddr negtive test */
    if (CSL_vimGetDedVectorAddr(NULL, &val) != CSL_EFAIL)
    {
        UART_printf("CSL_vimGetDedVectorAddr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimGetDedVectorAddr(pVimRegs, NULL) != CSL_EFAIL)
    {
        UART_printf("CSL_vimGetDedVectorAddr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimGetActivePendingIntr negtive test */
    if (CSL_vimGetActivePendingIntr(NULL,
                                    CSL_VIM_INTR_MAP_IRQ,
                                    &val,
                                    &val2) != CSL_EFAIL)
    {
        UART_printf("CSL_vimGetActivePendingIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimGetActivePendingIntr(pVimRegs,
                                    CSL_VIM_INTR_MAP_ALL,
                                    &val,
                                    &val2) != CSL_EFAIL)
    {
        UART_printf("CSL_vimGetActivePendingIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimSetIntrEnable negtive test */
    if (CSL_vimSetIntrEnable(NULL,
                             CSL_VIM_TEST_INT_NUM_IRQ,
                             false) != CSL_EFAIL)
    {
        UART_printf("CSL_vimSetIntrEnable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimSetIntrEnable(pVimRegs,
                             CSL_VIM_INVALID_INT_NUM,
                             false) != CSL_EFAIL)
    {
        UART_printf("CSL_vimSetIntrEnable: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimGetIntrType negtive test */
    if (CSL_vimGetIntrType(NULL, CSL_VIM_TEST_INT_NUM_IRQ) != CSL_EFAIL)
    {
        UART_printf("CSL_vimGetIntrType: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimGetIntrType(pVimRegs, CSL_VIM_INVALID_INT_NUM) != CSL_EFAIL)
    {
        UART_printf("CSL_vimGetIntrType: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimGetIrqVectorAddress negtive test */
    if (CSL_vimGetIrqVectorAddress(NULL) != 0U)
    {
        UART_printf("CSL_vimGetIrqVectorAddress: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimGetFiqVectorAddress negtive test */
    if (CSL_vimGetFiqVectorAddress(NULL) != 0U)
    {
        UART_printf("CSL_vimGetFiqVectorAddress: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimGetGroupsIntrPending negtive test */
    if (CSL_vimGetGroupsIntrPending(NULL,
                                    CSL_VIM_INTR_MAP_IRQ) != 0U)
    {
        UART_printf("CSL_vimGetGroupsIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimGetGroupIntrPending negtive test */
    if (CSL_vimGetGroupIntrPending(NULL,
                                   CSL_VIM_INTR_MAP_IRQ,
                                   0U,
                                   false) != 0U)
    {
        UART_printf("CSL_vimGetGroupIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimGetGroupIntrPending(pVimRegs,
                                   CSL_VIM_INTR_MAP_IRQ,
                                   CSL_VIM_MAX_INTR_GROUPS,
                                   false) != 0U)
    {
        UART_printf("CSL_vimGetGroupIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimSetIntrPending negtive test */
    if (CSL_vimSetIntrPending(NULL, CSL_VIM_TEST_INT_NUM_IRQ) != CSL_EFAIL)
    {
        UART_printf("CSL_vimSetIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimSetIntrPending(pVimRegs, CSL_VIM_INVALID_INT_NUM) != CSL_EFAIL)
    {
        UART_printf("CSL_vimSetIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimClrIntrPending negtive test */
    if (CSL_vimClrIntrPending(NULL, CSL_VIM_TEST_INT_NUM_IRQ) != CSL_EFAIL)
    {
        UART_printf("CSL_vimClrIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimClrIntrPending(pVimRegs, CSL_VIM_INVALID_INT_NUM) != CSL_EFAIL)
    {
        UART_printf("CSL_vimClrIntrPending: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimAckIntr negtive test */
    if (CSL_vimAckIntr(NULL, CSL_VIM_INTR_MAP_IRQ) != CSL_EFAIL)
    {
        UART_printf("CSL_vimAckIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimAckIntr(pVimRegs, CSL_VIM_INTR_MAP_ALL) != CSL_EFAIL)
    {
        UART_printf("CSL_vimAckIntr: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    /* CSL_vimReadBackStaticRegs negtive test */
    if (CSL_vimReadBackStaticRegs(NULL, &staticRegs) != CSL_EFAIL)
    {
        UART_printf("CSL_vimReadBackStaticRegs: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }
    if (CSL_vimReadBackStaticRegs(pVimRegs, NULL) != CSL_EFAIL)
    {
        UART_printf("CSL_vimReadBackStaticRegs: failure on line no. %d \n", __LINE__);
        return (testStatus);
    }

    testStatus = CSL_VIM_TEST_PASS;
    cslApp_print("\n cslVim_negTest : pass \n");

    return (testStatus);
}
/*===========================================================================*/
/*                         Function definitions                              */
/*===========================================================================*/

int main(void)
{
    /* Declarations of variables */
    int32_t    testResult = CSL_VIM_TEST_PASS;
    int32_t    i;

    /* Init Board */
    cslApp_initBoard();

    cslApp_print("\nVIM R5 Test Application\r\n");

    for ( i = 0; cslVimTestList[i].testFunction != NULL; i++)
    {
        testResult = cslVimTestList[i].testFunction();
        /* stop the test if result is not successful */
        if (testResult != CSL_VIM_TEST_PASS)
        {
             break;
        }
    }

    if (testResult == CSL_VIM_TEST_PASS)
    {
        UART_printStatus("\n ALL TESTS PASSED \n");
    }
    else
    {
        UART_printStatus("\n Few/all tests Failed \n");
    }
    /* Stop the test and wait here */
    while (1);
}


/* Nothing past this point */
