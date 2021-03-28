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
 *  \file     ccmr5_test_cfg_rd_op_key.c
 *
 *  \brief    This file contains CCM test code for R5 core.
 *
 *  \details  CCM register read/write and configuration tests
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/test/ccmr5/ccmr5_test_app/ccmr5_test_main.h>
#include <ti/csl/test/ccmr5/ccmr5_test_app/ccmr5_test_cfg_rd_op_key.h>

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* CCMR5 OP KEY Read for various module Ids */
int32_t CSL_CCMR5_Reg_Rd_Op_Key_Test(void  *expectedVal)
{
    int32_t                                             csl_ret, testResult;
    uint32_t                                            i;
    CSL_McuArmssCcmR5ModuleId                           modId, modIdList[CSL_CCMR5_TOTAL_NUM_MODULE_ID];
    CSL_McuArmssCcmR5OpModeKey                         *pExpVal;
    uintptr_t                                           ccmR5BaseAddress;
    CSL_McuArmssCcmR5OpModeKey                          expVal, opModeKey;
    int32_t                                             metaInfo;

    /* Initialize the regiser values to be read to known value */
    if (expectedVal != (void *) NULL)
    {
        pExpVal       = ( CSL_McuArmssCcmR5OpModeKey*) expectedVal;
        expVal        = *pExpVal;
        testResult    = CSL_CCMR5_TEST_PASS;
    }
    else
    {
        testResult    = CSL_CCMR5_TEST_FAIL;
    }

    /* test Read the Op Key for all modules */
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        modIdList[0]      = CSL_MCU_ARMSS_CCMR5_CPU_MODULE_ID;
        modIdList[1]      = CSL_MCU_ARMSS_CCMR5_VIM_MODULE_ID;
        modIdList[2]      = CSL_MCU_ARMSS_CCMR5_INACTIVITY_MONITOR_MODULE_ID;

        for ( i = CSL_MCU_ARMSS_CCMR5_CPU_MODULE_ID; i < CSL_CCMR5_TOTAL_NUM_MODULE_ID; i++)
        {
           csl_ret = CSL_armR5CCMGetOperationModeKey(ccmR5BaseAddress, modIdList[i], &opModeKey, &metaInfo);
           if (csl_ret == CSL_PASS)
           {
               if (opModeKey != expVal)
               {
                   testResult = CSL_CCMR5_TEST_FAIL;
               }
               else
               {
                   testResult = CSL_CCMR5_TEST_PASS;
               }
           }
           else
           {
               /* set testResult to fail */
               testResult    = CSL_CCMR5_TEST_FAIL;
           }

           if (testResult == CSL_CCMR5_TEST_FAIL)
           {
               break;
           }
        }
    }

    /* Check for invalid module ID passed to CSL */
    if ( testResult == CSL_CCMR5_TEST_PASS)
    {
         modId      = CSL_MCU_ARMSS_CCMR5_INVALID_MODULE_ID; /* Some invalid module Id */
         testResult = CSL_armR5CCMGetOperationModeKey(ccmR5BaseAddress, modId, &opModeKey, &metaInfo);
         /* Expected failure operation return from CSL and hence Fail is basically test pass */
         if (testResult == CSL_CCMR5_TEST_FAIL)
         {
             testResult  = CSL_CCMR5_TEST_PASS;
         }
    }

    return (testResult);

}

/* Key Write test */
int32_t CSL_CCMR5_Reg_Cfg_Op_key_Test(void  *desiredVal)
{
    int32_t                                             testResult;
    uint32_t                                            i;
    CSL_McuArmssCcmR5ModuleId                           modIdList[CSL_CCMR5_TOTAL_NUM_MODULE_ID];
    uintptr_t                                           ccmR5BaseAddress;
    CSL_McuArmssCcmR5OpModeKey                          opModeKeySave[CSL_CCMR5_TOTAL_NUM_MODULE_ID];
    int32_t                                             metaInfo;

    testResult    = CSL_CCMR5_TEST_PASS;

    /* Save the original Op key value before the test, excercise GetKey API */
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        modIdList[0] = CSL_MCU_ARMSS_CCMR5_CPU_MODULE_ID;
        modIdList[1] = CSL_MCU_ARMSS_CCMR5_VIM_MODULE_ID;
        modIdList[2] = CSL_MCU_ARMSS_CCMR5_INACTIVITY_MONITOR_MODULE_ID;

        for ( i = CSL_MCU_ARMSS_CCMR5_CPU_MODULE_ID; i < CSL_CCMR5_TOTAL_NUM_MODULE_ID; i++)
        {
           testResult = CSL_armR5CCMGetOperationModeKey(ccmR5BaseAddress, modIdList[i], &opModeKeySave[i], &metaInfo);
           if (testResult != CSL_PASS)
           {
               /* set testResult to fail */
               testResult    = CSL_CCMR5_TEST_FAIL;
               break;
           }
        }
    }

    /* Restore the original Op key value before the test, excercise SetKey API */
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        for ( i = CSL_MCU_ARMSS_CCMR5_CPU_MODULE_ID; i < CSL_CCMR5_TOTAL_NUM_MODULE_ID; i++)
        {
           testResult = CSL_armR5CCMSetOperationModeKey(ccmR5BaseAddress, modIdList[i], opModeKeySave[i], &metaInfo);
           if (testResult != CSL_PASS)
           {
               /* set testResult to fail */
               testResult    = CSL_CCMR5_TEST_FAIL;
               break;
           }
           else
           {
               testResult    = CSL_CCMR5_TEST_PASS;
           }
        }
    }

   return (testResult);

}

/* Nothing past this point */
