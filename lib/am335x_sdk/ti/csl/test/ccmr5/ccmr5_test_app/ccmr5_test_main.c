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
 *  \file     ccmr5_test.c
 *
 *  \brief    This file contains CCM test code for R5 core.
 *
 *  \details  CCM register read/write and configuration tests
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/test/ccmr5/ccmr5_test_app/ccmr5_test_main.h>
#include <ti/csl/test/ccmr5/ccmr5_test_app/ccmr5_test_cfg_rd_regs.h>
#include <ti/csl/test/ccmr5/ccmr5_test_app/ccmr5_test_cfg_rd_op_key.h>
#include <ti/csl/test/ccmr5/ccmr5_test_app/ccmr5_test_cfg_rd_cmp_err.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */



/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
static void CSL_CCMR5AppInitBoard(void);
static int32_t CSL_CCMR5_Test(uint32_t testId);

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t main(void)
{
    /* Declaration of variables */
    uint32_t testId;
    int32_t  testResult = CSL_CCMR5_TEST_PASS;

    /* Init Board */
    CSL_CCMR5AppInitBoard();

    CSL_CCMR5AppPrint("\nCCM R5 Test Application\r\n");

    for (testId = ((uint32_t)(0U)); testId < CSL_CCMR5_TOTAL_NUM_TESTS; testId++)
    {
        testResult = CSL_CCMR5_Test(testId);
        if (testResult != CSL_CCMR5_TEST_PASS)
        {
            break;
        }
    }

    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        UART_printStatus("\n\nCCM R5 All tests Pass successfully \n");
    }
    else
    {
        UART_printStatus("\n\nCCM R5 few/all tests failed \n");
    }

    return (0);
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

static void CSL_CCMR5AppInitBoard(void)
{
    Board_initCfg boardCfg;

    boardCfg = (Board_initCfg)( ( (uint32_t) BOARD_INIT_PINMUX_CONFIG ) |
                                ( (uint32_t) BOARD_INIT_UART_STDIO ));
    Board_init(boardCfg);
}

void CSL_CCMR5AppPrint(const uint8_t * pStr)
{
   const char* pUartStr = (const char *) pStr;
   (void) UART_printf(pUartStr);
}

void CSL_CCMR5AppPrint_arg(uint32_t value)
{
   (void) UART_printf("0x%x \n", value);
}

static int32_t CSL_CCMR5_Test(uint32_t testId)
{
    int32_t    testResult;
    CSL_mcu_armss_ccmr5_compare_wrapper_cfg_mmrsRegs ccmR5TmpRegs = {0};
    CSL_McuArmssCcmR5OpModeKey opModeKey;

    switch (testId)
    {
        case CSL_CCMR5_REG_CFG_READ_TEST_ID:

            /* Initialize the regiser values to be written to known value */
            ccmR5TmpRegs.CCMSR1     = ((uint32_t)(0x00000000u));
            ccmR5TmpRegs.CCMSR2     = ((uint32_t)(0x00000000u));
            ccmR5TmpRegs.CCMSR3     = ((uint32_t)(0x00000000u));
            ccmR5TmpRegs.CCMKEYR1   = ((uint32_t)CSL_MCU_ARMSS_CCMR5_MKEY_CMP_MODE_ACTIVE);
            ccmR5TmpRegs.CCMKEYR2   = ((uint32_t)CSL_MCU_ARMSS_CCMR5_MKEY_CMP_MODE_ACTIVE);
            ccmR5TmpRegs.CCMKEYR3   = ((uint32_t)CSL_MCU_ARMSS_CCMR5_MKEY_CMP_MODE_ACTIVE);
            ccmR5TmpRegs.CCMPOLCNTRL = ((uint32_t)(0x00000000u));

            CSL_CCMR5AppPrint("\nCCM R5 Test: Configure the CCM R5 Registers : ");
            testResult = CSL_CCMR5_Reg_Cfg_Test(&ccmR5TmpRegs);

            if (testResult == CSL_CCMR5_TEST_PASS)
            {
                CSL_CCMR5AppPrint(" Pass...\r\n");
            }

            if (testResult == CSL_CCMR5_TEST_PASS)
            {
                CSL_CCMR5AppPrint("\nCCM R5 Test: Read back the CCM R5 Registers : ");
                testResult = CSL_CCMR5_Reg_Rd_Test(&ccmR5TmpRegs);
                if (testResult == CSL_CCMR5_TEST_PASS)
                {
                    CSL_CCMR5AppPrint(" Pass...\r\n");
                }
                else
                {
                    CSL_CCMR5AppPrint(" Fail...\r\n");
                }
            }
            break;

        case CSL_CCMR5_REG_CFG_RD_OP_KEY_TEST_ID:
            opModeKey = CSL_MCU_ARMSS_CCMR5_MKEY_SELF_TEST_ERR_FORCE_MODE;
            CSL_CCMR5AppPrint("\nCCM R5 Test: Configure the CCM R5 Op Key Registers Test : ");
            /* This test configures the Op Key to below desired value and restors to orig value */
            testResult = CSL_CCMR5_Reg_Cfg_Op_key_Test(&opModeKey);
            if (testResult == CSL_CCMR5_TEST_PASS)
            {
                CSL_CCMR5AppPrint(" Pass...\r\n");
            }
            else
            {
                CSL_CCMR5AppPrint(" Fail...\r\n");
            }

            if (testResult == CSL_CCMR5_TEST_PASS)
            {
                CSL_CCMR5AppPrint("\nCCM R5 Test: Read the CCM R5 Op Key Registers Test : ");
                /* This would make sure the restoration is done correctly via read test*/
                opModeKey  = (CSL_McuArmssCcmR5OpModeKey) ccmR5TmpRegs.CCMKEYR1;
                testResult = CSL_CCMR5_Reg_Rd_Op_Key_Test(&opModeKey);
            }

            if (testResult == CSL_CCMR5_TEST_PASS)
            {
                CSL_CCMR5AppPrint(" Pass...\r\n");
            }
            else
            {
                CSL_CCMR5AppPrint(" Fail...\r\n");
            }
            break;

        case CSL_CCMR5_REG_CLR_RD_CMP_ERR_TEST_ID:
            CSL_CCMR5AppPrint("\nCCM R5 Test: CMP Err test : ");
            testResult = CSL_CCMR5_CmpErr_Test();
            if (testResult == CSL_CCMR5_TEST_PASS)
            {
                CSL_CCMR5AppPrint(" Pass...\r\n");
            }

            break;

        default:
            testResult = CSL_CCMR5_TEST_FAIL;
            break;
    }

    return (testResult);
}

/* Nothing past this point */

