/*
 *  Copyright (c) Texas Instruments Incorporated 2018
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
 */

/**
 *  \file st_dccCommon.c
 *
 *  \brief Common code that can be shared across test case files.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_dcc.h>
#include <ti/drv/sciclient/sciclient.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define SYS_CLK1_FREQ_KHZ                   ((uint32_t) 20000)
#define SYS_CLK2_FREQ_KHz                   ((uint32_t) 22579)
#define APP_DCC_REF_CLOCK_FREQ_IN_KHZ   (25000U)
/**< Expected reference clock frequency in KHz */
#define APP_DCC_TEST_CLOCK_FREQ_IN_KHZ  (60000U)
/**< Expected test clock frequency in KHz */



/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t DCCClockEnable(uint32_t module)
{
    int32_t status = CSL_EFAIL;

    switch (module)
    {
        case CSL_MCU_DCC0_BASE:
            /* Enable DCC module */
            status = Sciclient_pmSetModuleState(TISCI_DEV_MCU_DCC0,
                TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                TISCI_MSG_FLAG_AOP,
                SCICLIENT_SERVICE_WAIT_FOREVER);
            break;
        case CSL_MCU_DCC1_BASE:
            /* Enable DCC module */
            status = Sciclient_pmSetModuleState(TISCI_DEV_MCU_DCC1,
                TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                TISCI_MSG_FLAG_AOP,
                SCICLIENT_SERVICE_WAIT_FOREVER);
            break;
        case CSL_MCU_DCC2_BASE:
            /* Enable DCC module */
            status = Sciclient_pmSetModuleState(TISCI_DEV_MCU_DCC2,
                TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                TISCI_MSG_FLAG_AOP,
                SCICLIENT_SERVICE_WAIT_FOREVER);
            break;
        case CSL_DCC0_BASE:
            /* Enable DCC module */
            status = Sciclient_pmSetModuleState(TISCI_DEV_DCC0,
                TISCI_MSG_VALUE_DEVICE_SW_STATE_ON,
                TISCI_MSG_FLAG_AOP,
                SCICLIENT_SERVICE_WAIT_FOREVER);
            break;
        default:
            status = CSL_EFAIL;
            break;
    }
    return status;
}

int32_t DCCAppGetTestClkfreqKHz(uint32_t dccInst,
                                 uint32_t clk0Src, uint32_t *clk0Freq,
                                 uint32_t clk1Src, uint32_t *clk1Freq)
{
    int32_t retVal = CSL_PASS;
    uint64_t clk0Freq_64, clk1Freq_64;
    uint32_t tisciModuleId;
    uint32_t tisciClk0Src, tisciClk1Src;
    switch (dccInst)
    {
        case CSL_MCU_DCC0_BASE :
            tisciModuleId = TISCI_DEV_MCU_DCC0;
            switch (clk0Src)
            {
                case DCC_DCCCLKSRC0_CLKSRC0_0:
                    tisciClk0Src = TISCI_DEV_MCU_DCC0_BUS_DCC_INPUT00_CLK;
                    break;
                case DCC_DCCCLKSRC0_CLKSRC0_1:
                    tisciClk0Src = TISCI_DEV_MCU_DCC0_BUS_DCC_INPUT01_CLK;
                    break;
                case DCC_DCCCLKSRC0_CLKSRC0_2:
                    tisciClk0Src = TISCI_DEV_MCU_DCC0_BUS_DCC_INPUT02_CLK;
                    break;
                default:
                    retVal = CSL_EFAIL;
                    break;
            }
            switch (clk1Src)
            {
                case DCC_DCCCLKSRC1_CLKSRC_0:
                    tisciClk1Src = TISCI_DEV_MCU_DCC0_BUS_DCC_CLKSRC0_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_1:
                    tisciClk1Src = TISCI_DEV_MCU_DCC0_BUS_DCC_CLKSRC1_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_2:
                    tisciClk1Src = TISCI_DEV_MCU_DCC0_BUS_DCC_CLKSRC2_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_3:
                    tisciClk1Src = TISCI_DEV_MCU_DCC0_BUS_DCC_CLKSRC3_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_4:
                    tisciClk1Src = TISCI_DEV_MCU_DCC0_BUS_DCC_CLKSRC4_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_5:
                    tisciClk1Src = TISCI_DEV_MCU_DCC0_BUS_DCC_CLKSRC5_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_6:
                    tisciClk1Src = TISCI_DEV_MCU_DCC0_BUS_DCC_CLKSRC6_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_7:
                    tisciClk1Src = TISCI_DEV_MCU_DCC0_BUS_DCC_CLKSRC7_CLK;
                    break;
                default:
                    retVal = CSL_EFAIL;
                    break;
            }
            break;
        case CSL_MCU_DCC1_BASE :
            tisciModuleId = TISCI_DEV_MCU_DCC1;
            switch (clk0Src)
            {
                case DCC_DCCCLKSRC0_CLKSRC0_0:
                    tisciClk0Src = TISCI_DEV_MCU_DCC1_BUS_DCC_INPUT00_CLK;
                    break;
                case DCC_DCCCLKSRC0_CLKSRC0_1:
                    tisciClk0Src = TISCI_DEV_MCU_DCC1_BUS_DCC_INPUT01_CLK;
                    break;
                case DCC_DCCCLKSRC0_CLKSRC0_2:
                    tisciClk0Src = TISCI_DEV_MCU_DCC1_BUS_DCC_INPUT02_CLK;
                    break;
                default:
                    retVal = CSL_EFAIL;
                    break;
            }
            switch (clk1Src)
            {
                case DCC_DCCCLKSRC1_CLKSRC_0:
                    tisciClk1Src = TISCI_DEV_MCU_DCC1_BUS_DCC_CLKSRC0_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_1:
                    tisciClk1Src = TISCI_DEV_MCU_DCC1_BUS_DCC_CLKSRC1_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_2:
                    tisciClk1Src = TISCI_DEV_MCU_DCC1_BUS_DCC_CLKSRC2_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_3:
                    tisciClk1Src = TISCI_DEV_MCU_DCC1_BUS_DCC_CLKSRC3_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_4:
                    tisciClk1Src = TISCI_DEV_MCU_DCC1_BUS_DCC_CLKSRC4_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_5:
                    tisciClk1Src = TISCI_DEV_MCU_DCC1_BUS_DCC_CLKSRC5_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_6:
                    tisciClk1Src = TISCI_DEV_MCU_DCC1_BUS_DCC_CLKSRC6_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_7:
                    tisciClk1Src = TISCI_DEV_MCU_DCC1_BUS_DCC_CLKSRC7_CLK;
                    break;
                default:
                    retVal = CSL_EFAIL;
                    break;
            }
            break;
        case CSL_MCU_DCC2_BASE :
            tisciModuleId = TISCI_DEV_MCU_DCC2;
            switch (clk0Src)
            {
                case DCC_DCCCLKSRC0_CLKSRC0_0:
                    tisciClk0Src = TISCI_DEV_MCU_DCC2_BUS_DCC_INPUT00_CLK;
                    break;
                case DCC_DCCCLKSRC0_CLKSRC0_1:
                    tisciClk0Src = TISCI_DEV_MCU_DCC2_BUS_DCC_INPUT01_CLK;
                    break;
                case DCC_DCCCLKSRC0_CLKSRC0_2:
                    tisciClk0Src = TISCI_DEV_MCU_DCC2_BUS_DCC_INPUT02_CLK;
                    break;
                default:
                    retVal = CSL_EFAIL;
                    break;
            }
            switch (clk1Src)
            {
                case DCC_DCCCLKSRC1_CLKSRC_0:
                    tisciClk1Src = TISCI_DEV_MCU_DCC2_BUS_DCC_CLKSRC0_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_1:
                    tisciClk1Src = TISCI_DEV_MCU_DCC2_BUS_DCC_CLKSRC1_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_2:
                    tisciClk1Src = TISCI_DEV_MCU_DCC2_BUS_DCC_CLKSRC2_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_3:
                    tisciClk1Src = TISCI_DEV_MCU_DCC2_BUS_DCC_CLKSRC3_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_4:
                    tisciClk1Src = TISCI_DEV_MCU_DCC2_BUS_DCC_CLKSRC4_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_5:
                    tisciClk1Src = TISCI_DEV_MCU_DCC2_BUS_DCC_CLKSRC5_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_6:
                    tisciClk1Src = TISCI_DEV_MCU_DCC2_BUS_DCC_CLKSRC6_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_7:
                    tisciClk1Src = TISCI_DEV_MCU_DCC2_BUS_DCC_CLKSRC7_CLK;
                    break;
                default:
                    retVal = CSL_EFAIL;
                    break;
            }
            break;
        case CSL_DCC0_BASE :
            tisciModuleId = TISCI_DEV_DCC0;
            switch (clk0Src)
            {
                case DCC_DCCCLKSRC0_CLKSRC0_0:
                    tisciClk0Src = TISCI_DEV_DCC0_BUS_DCC_INPUT00_CLK;
                    break;
                case DCC_DCCCLKSRC0_CLKSRC0_1:
                    tisciClk0Src = TISCI_DEV_DCC0_BUS_DCC_INPUT01_CLK;
                    break;
                case DCC_DCCCLKSRC0_CLKSRC0_2:
                    tisciClk0Src = TISCI_DEV_DCC0_BUS_DCC_INPUT02_CLK;
                    break;
                default:
                    retVal = CSL_EFAIL;
                    break;
            }
            switch (clk1Src)
            {
                case DCC_DCCCLKSRC1_CLKSRC_0:
                    tisciClk1Src = TISCI_DEV_DCC0_BUS_DCC_CLKSRC0_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_1:
                    tisciClk1Src = TISCI_DEV_DCC0_BUS_DCC_CLKSRC1_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_2:
                    tisciClk1Src = TISCI_DEV_DCC0_BUS_DCC_CLKSRC2_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_3:
                    tisciClk1Src = TISCI_DEV_DCC0_BUS_DCC_CLKSRC3_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_4:
                    tisciClk1Src = TISCI_DEV_DCC0_BUS_DCC_CLKSRC4_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_5:
                    tisciClk1Src = TISCI_DEV_DCC0_BUS_DCC_CLKSRC5_CLK;
                    break;
                case DCC_DCCCLKSRC1_CLKSRC_6:
                    tisciClk1Src = TISCI_DEV_DCC0_BUS_DCC_CLKSRC6_CLK;
                    break;
                default:
                    retVal = CSL_EFAIL;
                    break;
            }
            break;
        default:
            retVal = CSL_EFAIL;
            break;
    }

    if (retVal == CSL_PASS)
    {
        retVal += Sciclient_pmGetModuleClkFreq(tisciModuleId,
            tisciClk0Src,
            &clk0Freq_64,
            SCICLIENT_SERVICE_WAIT_FOREVER);
        *clk0Freq = (uint32_t) (clk0Freq_64 / 1000U);
        retVal += Sciclient_pmGetModuleClkFreq(tisciModuleId,
            tisciClk1Src,
            &clk1Freq_64,
            SCICLIENT_SERVICE_WAIT_FOREVER);
        *clk1Freq = (uint32_t) (clk1Freq_64 / 1000U);
    }
            
    return (retVal);
}

uint32_t DCCAppGetSrc1SeedVal(uint32_t testClk,
                              uint32_t refClkCnt,
                              uint32_t testClkFreq)
{
    uint32_t testClkCnt;

    testClkCnt = refClkCnt * testClkFreq / testClk;
    return testClkCnt;
}

void DCCAppEnableEsm(uint32_t esmInst, uint32_t esmEvtNum)
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

