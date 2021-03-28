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

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

/* CCMR5 register read test */
int32_t CSL_CCMR5_Reg_Rd_Test(void *expectedVal)
{
    int32_t                                             cslRet;
    int32_t                                             testResult = CSL_CCMR5_TEST_PASS;
    CSL_mcu_armss_ccmr5_compare_wrapper_cfg_mmrsRegs    ccmR5RdRegs = {0}, ccmR5TmpRegs = {0};
    CSL_mcu_armss_ccmr5_compare_wrapper_cfg_mmrsRegs    *pExpVal;
    uintptr_t                                           ccmR5BaseAddress;
    CSL_McuArmssCcmR5RegId                              regId;
    uint32_t                                            regVal;
    int32_t                                             metaInfo;

    /* Initialize the regiser values to be read to known value */
    if (expectedVal != (void *) NULL)
    {
        pExpVal       = ( CSL_mcu_armss_ccmr5_compare_wrapper_cfg_mmrsRegs *) expectedVal;
        ccmR5TmpRegs = *pExpVal;
    }

    /* Read the CCM Status registers */
    if ( testResult == CSL_CCMR5_TEST_PASS )
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMSR1_REGID;
        cslRet             = CSL_armR5ReadCCMRegister(ccmR5BaseAddress, regId, &regVal, &metaInfo);
        if (cslRet    == CSL_PASS)
        {
             testResult     = CSL_CCMR5_TEST_PASS;
             ccmR5RdRegs.CCMSR1 = regVal;
        }
        else
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMSR1 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    if ( testResult == CSL_CCMR5_TEST_PASS )
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMSR2_REGID;
        testResult         = CSL_armR5ReadCCMRegister(ccmR5BaseAddress, regId, &regVal, &metaInfo);
        if (testResult    == CSL_PASS)
        {
             ccmR5RdRegs.CCMSR2 = regVal;
        }
        else
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMSR2 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    if ( testResult == CSL_CCMR5_TEST_PASS )
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMSR3_REGID;
        testResult         = CSL_armR5ReadCCMRegister(ccmR5BaseAddress, regId, &regVal, &metaInfo);
        if (testResult    == CSL_PASS)
        {
             ccmR5RdRegs.CCMSR3 = regVal;
        }
        else
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMSR3 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    /* Read the Op Key registers */
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMKEYR1_REGID;
        testResult         = CSL_armR5ReadCCMRegister(ccmR5BaseAddress, regId, &regVal, &metaInfo);
        if (testResult    == CSL_PASS)
        {
             ccmR5RdRegs.CCMKEYR1 = regVal;
        }
        else
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMKEYR1 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    if ( testResult == CSL_CCMR5_TEST_PASS )
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMKEYR2_REGID;
        testResult         = CSL_armR5ReadCCMRegister(ccmR5BaseAddress, regId, &regVal, &metaInfo);
        if (testResult    == CSL_PASS)
        {
             ccmR5RdRegs.CCMKEYR2 = regVal;
        }
        else
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMKEYR2 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    if ( testResult == CSL_CCMR5_TEST_PASS )
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMKEYR3_REGID;
        testResult         = CSL_armR5ReadCCMRegister(ccmR5BaseAddress, regId, &regVal, &metaInfo);
        if (testResult    == CSL_PASS)
        {
             ccmR5RdRegs.CCMKEYR3 = regVal;
        }
        else
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMKEYR3 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    /* Read the CCM Polarity inversion control registers */
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_POLCNTRL_REGID;
        testResult         = CSL_armR5ReadCCMRegister(ccmR5BaseAddress, regId, &regVal, &metaInfo);
        if (testResult    == CSL_PASS)
        {
             ccmR5RdRegs.CCMPOLCNTRL = regVal;
        }
        else
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMPOLCNTRL register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    /* Check if any of the registers are unexpected values , make the test as fail */
    if ( (ccmR5RdRegs.CCMKEYR1      != ccmR5TmpRegs.CCMKEYR1) ||
         (ccmR5RdRegs.CCMKEYR2      != ccmR5TmpRegs.CCMKEYR2) ||
         (ccmR5RdRegs.CCMKEYR3      != ccmR5TmpRegs.CCMKEYR3) ||
         (ccmR5RdRegs.CCMPOLCNTRL   != ccmR5TmpRegs.CCMPOLCNTRL) )
     {
         testResult = CSL_CCMR5_TEST_FAIL;
     }

    return (testResult);

}

/* CCMR5 register configuration test */
int32_t CSL_CCMR5_Reg_Cfg_Test(void *desiredVal)
{
    int32_t                                             testResult = CSL_CCMR5_TEST_PASS;
    CSL_mcu_armss_ccmr5_compare_wrapper_cfg_mmrsRegs    ccmR5TmpRegs = {0};
    CSL_mcu_armss_ccmr5_compare_wrapper_cfg_mmrsRegs    *pDesVal;
    uintptr_t                                           ccmR5BaseAddress;
    CSL_McuArmssCcmR5RegId                              regId;
    uint32_t                                            regVal;
    int32_t                                             metaInfo;

    /* Initialize the regiser values to be read to known value */
    if (desiredVal != (void *) NULL)
    {
        pDesVal      = (CSL_mcu_armss_ccmr5_compare_wrapper_cfg_mmrsRegs *) desiredVal;
        ccmR5TmpRegs = *pDesVal;
    }

    /* Configure the CCM Status registers */
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMSR1_REGID;
        regVal             = ccmR5TmpRegs.CCMSR1;
        testResult         = CSL_armR5ConfigureCCMRegister(ccmR5BaseAddress, regId, regVal, &metaInfo);
        if (testResult    != CSL_PASS)
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMSR1 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMSR2_REGID;
        regVal             = ccmR5TmpRegs.CCMSR2;
        testResult         = CSL_armR5ConfigureCCMRegister(ccmR5BaseAddress, regId, regVal, &metaInfo);
        if (testResult    != CSL_PASS)
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMSR2 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMSR3_REGID;
        regVal             = ccmR5TmpRegs.CCMSR3;
        testResult         = CSL_armR5ConfigureCCMRegister(ccmR5BaseAddress, regId, regVal, &metaInfo);
        if (testResult    != CSL_PASS)
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMSR3 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    /* Configure the Op Key registers */
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMKEYR1_REGID;
        regVal             = ccmR5TmpRegs.CCMKEYR1;
        testResult         = CSL_armR5ConfigureCCMRegister(ccmR5BaseAddress, regId, regVal, &metaInfo);
        if (testResult    != CSL_PASS)
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMKEYR1 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMKEYR2_REGID;
        regVal             = ccmR5TmpRegs.CCMKEYR2;
        testResult         = CSL_armR5ConfigureCCMRegister(ccmR5BaseAddress, regId, regVal, &metaInfo);
        if (testResult    != CSL_PASS)
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMKEYR2 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_CCMKEYR3_REGID;
        regVal             = ccmR5TmpRegs.CCMKEYR3;
        testResult         = CSL_armR5ConfigureCCMRegister(ccmR5BaseAddress, regId, regVal, &metaInfo);
        if (testResult    != CSL_PASS)
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMKEYR3 register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    /* Configure the CCM Polarity inversion control registers */
    if (testResult == CSL_CCMR5_TEST_PASS)
    {
        ccmR5BaseAddress   = CSL_MCU_ARMSS0_COMPARE_CFG_BASE;
        regId              = CSL_MCU_ARMSS_CCMR5_POLCNTRL_REGID;
        regVal             = ccmR5TmpRegs.CCMPOLCNTRL;
        testResult         = CSL_armR5ConfigureCCMRegister(ccmR5BaseAddress, regId, regVal, &metaInfo);
        if (testResult    != CSL_PASS)
        {
            testResult     = CSL_CCMR5_TEST_FAIL;
            CSL_CCMR5AppPrint (" CCMPOLCNTRL register read test failed : fail code value is ");
            CSL_CCMR5AppPrint_arg((uint32_t)metaInfo);
            CSL_CCMR5AppPrint("\r\n");
        }
    }

    return (testResult);
}

/* Nothing past this point */
