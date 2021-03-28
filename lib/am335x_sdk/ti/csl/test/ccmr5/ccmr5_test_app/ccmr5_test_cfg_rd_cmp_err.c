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

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/* compare error test */
int32_t CSL_CCMR5_CmpErr_Test(void)
{
    int32_t                             cslRet, testResult;
    uint32_t                            i;
    uintptr_t                           ccmR5BaseAddress;
    uint32_t                            cmpErrRd[CSL_CCMR5_TOTAL_NUM_MODULE_ID];
    int32_t                             metaInfo;

    /* Set the base address */
    ccmR5BaseAddress   = (uintptr_t) CSL_MCU_ARMSS0_COMPARE_CFG_BASE;

    /* Trigger the compare error to be set for all modules,
       by writing to POLINV Register */
    {
        cslRet = CSL_armR5ConfigureCCMRegister (
                             ccmR5BaseAddress,
                             CSL_MCU_ARMSS_CCMR5_POLCNTRL_REGID,
                             1U,
                             &metaInfo);

        if (cslRet == CSL_PASS)
        {
            /* set testResult to pass */
            testResult    = CSL_CCMR5_TEST_PASS;
        }
        else
        {
            /* set testResult to fail */
            testResult    = CSL_CCMR5_TEST_FAIL;
        }
    }

    /* get the compare error regisers for all modules */
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        for ( 
              i = CSL_MCU_ARMSS_CCMR5_CPU_MODULE_ID; \
              i < CSL_CCMR5_TOTAL_NUM_MODULE_ID; \
              i++
            )
        {
           cslRet = CSL_armR5CCMGetCompareError(
                          ccmR5BaseAddress,
                         (CSL_McuArmssCcmR5ModuleId) (i), 
                          &cmpErrRd[i], 
                          &metaInfo);
           if (cslRet != CSL_PASS)
           {
               /* set testResult to fail */
               testResult    = CSL_CCMR5_TEST_FAIL;
               break;
           }
        }
    }
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        /* Output the compare error read */
        CSL_CCMR5AppPrint(" CPU/IM and VIM module Compare Error values are : \n");
        CSL_CCMR5AppPrint_arg(cmpErrRd[CSL_MCU_ARMSS_CCMR5_CPU_MODULE_ID]);
        CSL_CCMR5AppPrint_arg(cmpErrRd[CSL_MCU_ARMSS_CCMR5_INACTIVITY_MONITOR_MODULE_ID]);
        CSL_CCMR5AppPrint_arg(cmpErrRd[CSL_MCU_ARMSS_CCMR5_VIM_MODULE_ID]);
    }

   /* Clear the compare error API test */
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        for ( 
              i = CSL_MCU_ARMSS_CCMR5_CPU_MODULE_ID; \
              i < CSL_CCMR5_TOTAL_NUM_MODULE_ID; \
              i++
            )
        {
           cslRet = CSL_armR5CCMClearCompareError(
                          ccmR5BaseAddress,
                         (CSL_McuArmssCcmR5ModuleId) (i), 
                          &metaInfo);
           if (cslRet != CSL_PASS)
           {
               /* set testResult to fail */
               testResult    = CSL_CCMR5_TEST_FAIL;
               break;
           }
        }
    }
   return (testResult);

}

/* Nothing past this point */
