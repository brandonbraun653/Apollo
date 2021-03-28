/*
 *   Copyright (c) Texas Instruments Incorporated 2019
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
 *  \file     cbass_test_err.c
 *
 *  \brief    This file contains CBASS Error module test code for R5 core.
 *
 *  \details  CBASS Error module tests
 **/

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <ti/csl/csl_types.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/csl/soc/am65xx/src/cslr_soc_baseaddress.h>
#include <ti/csl/csl_cbass.h>

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

static int32_t CBASS_errNegtiveTest(CSL_cbass_errRegs *pErrRegs)
{
    int32_t                    testResult = CSL_PASS;
    uint32_t                   val;
    CSL_CbassErrExcepLogHdr_t  logHdr;
    CSL_CbassErrExcepLogData_t logData;
    CSL_CbassErrStaticRegs     staticRegs;

    /* CSL_cbassErrGetRevision() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetRevision(NULL,
                                    &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetRevision(pErrRegs,
                                    NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrSetDestID() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrSetDestID(NULL,
                                  0U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrSetDestID(pErrRegs,
                                  CSL_CBASS_ERR_DESTINATION_ID_DEST_ID_MAX + 1U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassQosGetOrderID() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetDestID(NULL,
                                  &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetDestID(pErrRegs,
                                  NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrGetExcepLogHdr() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetExcepLogHdr(NULL,
                                       &logHdr) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetExcepLogHdr(pErrRegs,
                                       NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrGetExcepLogData() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetExcepLogData(NULL,
                                        &logData) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetExcepLogData(pErrRegs,
                                       NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrSetIntrRawStatus() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrSetIntrRawStatus(NULL,
                                         CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrSetIntrRawStatus(pErrRegs,
                                         0x2U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrGetIntrRawStatus() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetIntrRawStatus(NULL,
                                         &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetIntrRawStatus(pErrRegs,
                                         NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrSetIntrRawStatus() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrSetIntrRawStatus(NULL,
                                         CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrSetIntrRawStatus(pErrRegs,
                                         0x2U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrClearIntr() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrClearIntr(NULL,
                                  CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrClearIntr(pErrRegs,
                                  0x2U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrGetIntrStatus() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetIntrStatus(NULL,
                                      &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetIntrStatus(pErrRegs,
                                      NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrEnableIntr() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrEnableIntr(NULL,
                                   CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrEnableIntr(pErrRegs,
                                   0x2U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrDisableIntr() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrDisableIntr(NULL,
                                    CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrDisableIntr(pErrRegs,
                                    0x2U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrSetEOI() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrSetEOI(NULL,
                               CSL_CBASS_ERR_EOI_WR_MAX) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrSetEOI(pErrRegs,
                               CSL_CBASS_ERR_EOI_WR_MAX + 1U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrGetEOI() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetEOI(NULL, &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrGetEOI(pErrRegs, NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassErrReadStaticRegs() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrReadStaticRegs(NULL,
                                       &staticRegs) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassErrReadStaticRegs(pErrRegs,
                                       NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    return (testResult);
}

static int32_t CBASS_errApiTest(CSL_cbass_errRegs *pErrRegs)
{
    int32_t                    testResult;
    CSL_CbassErrExcepLogHdr_t  logHdr;
    CSL_CbassErrExcepLogData_t logData;
    uint32_t                   wrVal, rdVal;
    CSL_CbassErrStaticRegs     staticRegs;

    /* CSL_cbassErrGetRevision() API */
    rdVal = 0U;
    testResult = CSL_cbassErrGetRevision(pErrRegs,
                                         &rdVal);

    /* CSL_cbassErrSetDestID() and CSL_cbassErrGetDestID API */
    if (testResult == CSL_PASS)
    {
        wrVal = CSL_CBASS_ERR_DESTINATION_ID_DEST_ID_MAX;
        testResult = CSL_cbassErrSetDestID(pErrRegs,
                                           wrVal);
    }
    if (testResult == CSL_PASS)
    {
        rdVal = 0U;
        testResult = CSL_cbassErrGetDestID(pErrRegs,
                                           &rdVal);
       if  (testResult == CSL_PASS)
       {
           if (wrVal != rdVal)
           {
               testResult = CSL_EFAIL;
           }
       }
    }

    /* CSL_cbassErrGetExcepLogHdr() API */
    if (testResult == CSL_PASS)
    {
        testResult = CSL_cbassErrGetExcepLogHdr(pErrRegs,
                                                 &logHdr);
    }

    /* CSL_cbassErrGetExcepLogHdr() API */
    if (testResult == CSL_PASS)
    {
        testResult = CSL_cbassErrGetExcepLogData(pErrRegs,
                                                 &logData);
    }

    /* CSL_cbassErrSetIntrRawStatus() and CSL_cbassErrGetIntrRawStatus() API */
    if (testResult == CSL_PASS)
    {
        wrVal = CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX;
        testResult = CSL_cbassErrSetIntrRawStatus(pErrRegs, wrVal);
    }
    if (testResult == CSL_PASS)
    {
        rdVal = 0U;
        testResult = CSL_cbassErrGetIntrRawStatus(pErrRegs, &rdVal);
       if  (testResult == CSL_PASS)
       {
           if (wrVal != rdVal)
           {
               testResult = CSL_EFAIL;
           }
       }
    }


    /* CSL_cbassErrClearIntr() API */
    if (testResult == CSL_PASS)
    {
        testResult = CSL_cbassErrClearIntr(pErrRegs,
                                           CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX);
    }

    /* CSL_cbassErrGetIntrStatus() API */
    if (testResult == CSL_PASS)
    {
        testResult = CSL_cbassErrGetIntrStatus(pErrRegs, &rdVal);
    }

    /* CSL_cbassErrEnableIntr() API */
    if (testResult == CSL_PASS)
    {
        testResult = CSL_cbassErrEnableIntr(pErrRegs,
                                            CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX);
    }

    /* CSL_cbassErrDisableIntr() API */
    if (testResult == CSL_PASS)
    {
        testResult = CSL_cbassErrDisableIntr(pErrRegs,
                                             CSL_CBASS_ERR_ERR_INTR_RAW_STAT_INTR_MAX);
    }

    /* CSL_cbassErrSetEOI() API */
    if (testResult == CSL_PASS)
    {
        wrVal = CSL_CBASS_ERR_EOI_WR_MAX;
        testResult = CSL_cbassErrSetEOI(pErrRegs, wrVal);
    }

    /* CSL_cbassErrGetEOI() API */
    if (testResult == CSL_PASS)
    {
        rdVal = 0U;
        testResult = CSL_cbassErrGetEOI(pErrRegs, &rdVal);
        if  (testResult == CSL_PASS)
        {
            if (wrVal != rdVal)
            {
                testResult = CSL_EFAIL;
            }
        }
    }

    /* CSL_cbassErrReadStaticRegs() API */
    if (testResult == CSL_PASS)
    {
        testResult = CSL_cbassErrReadStaticRegs(pErrRegs,
                                                &staticRegs);
    }

    return (testResult);
}

/* CBASS Error module test */
int32_t CBASS_errTest(void)
{
    int32_t    testResult;

    testResult = CBASS_errNegtiveTest((CSL_cbass_errRegs *)CSL_MCU_CBASS0_ERR_BASE);
    if (testResult == CSL_PASS)
    {
        testResult = CBASS_errApiTest((CSL_cbass_errRegs *)CSL_MCU_CBASS0_ERR_BASE);
    }

    return (testResult);
}


/* Nothing past this point */
