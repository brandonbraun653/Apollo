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
 *  \file     cbass_test_qos.c
 *
 *  \brief    This file contains CBASS QoS module test code for R5 core.
 *
 *  \details  CBASS QoS tests
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

int32_t CBASS_qosNegtiveTest(CSL_cbass_qosRegs_ep *pQosEpRegs)
{
    int32_t               testResult = CSL_PASS;
    uint32_t              val;
    CSL_cbass_qosRegs_ep  staticRegs;

    /* CSL_cbassQosSetQos() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosSetQos(NULL,
                               0U,
                               0U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosSetQos(pQosEpRegs,
                               CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS,
                               0U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosSetQos(pQosEpRegs,
                               0U,
                               CSL_CBASS_QOS_EP_MAP_QOS_MAX + 1U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassQosGetQos() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosGetQos(NULL,
                               0U,
                               &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosGetQos(pQosEpRegs,
                               CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS,
                               &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosGetQos(pQosEpRegs,
                               0U,
                               NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassQosSetOrderID() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosSetOrderID(NULL,
                                   0U,
                                   0U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosSetOrderID(pQosEpRegs,
                                   CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS,
                                   0U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosSetOrderID(pQosEpRegs,
                                   0U,
                                   CSL_CBASS_QOS_EP_MAP_ORDERID_MAX + 1U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassQosGetOrderID() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosGetOrderID(NULL,
                                   0U,
                                   &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosGetOrderID(pQosEpRegs,
                                   CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS,
                                   &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosGetOrderID(pQosEpRegs,
                                   0U,
                                   NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassQosSetEpriority() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosSetEpriority(NULL,
                                     0U,
                                     0U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosSetEpriority(pQosEpRegs,
                                     CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS,
                                     0U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosSetEpriority(pQosEpRegs,
                                     0U,
                                     CSL_CBASS_QOS_EP_MAP_EPRIORITY_MAX + 1U) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassQosGetEpriority() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosGetEpriority(NULL,
                                     0U,
                                     &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosGetEpriority(pQosEpRegs,
                                     CSL_CBASS_QOS_MAX_NUM_OF_CHANNELS,
                                     &val) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosGetEpriority(pQosEpRegs,
                                     0U,
                                     NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    /* CSL_cbassQosReadStaticRegs() API */
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosReadStaticRegs(NULL,
                                       &staticRegs) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }
    if (testResult == CSL_PASS)
    {
        if (CSL_cbassQosReadStaticRegs(pQosEpRegs,
                                       NULL) != CSL_EBADARGS)
        {
            testResult = CSL_EFAIL;
        }
    }

    return (testResult);
}

int32_t CBASS_qosApiTest(CSL_cbass_qosRegs_ep *pQosEpRegs)
{
    int32_t               testResult;
    uint32_t              channel = 0U;
    uint32_t              wrVal, rdVal;
    CSL_cbass_qosRegs_ep  staticRegs;

    /* CSL_cbassQosSetQos() & CSL_cbassQosGetQos() APIs */
    wrVal = CSL_CBASS_QOS_EP_MAP_QOS_MAX;
    testResult = CSL_cbassQosSetQos(pQosEpRegs,
                                    channel,
                                    wrVal);
    if (testResult == CSL_PASS)
    {
        rdVal = 0U;
        testResult = CSL_cbassQosGetQos(pQosEpRegs,
                                        channel,
                                        &rdVal);
       if  (testResult == CSL_PASS)
       {
           if (wrVal != rdVal)
           {
               testResult = CSL_EFAIL;
           }
       }
    }

    /* CSL_cbassQosSetOrderID() & CSL_cbassQosGetOrderID() APIs */
    wrVal = CSL_CBASS_QOS_EP_MAP_ORDERID_MAX;
    testResult = CSL_cbassQosSetOrderID(pQosEpRegs,
                                        channel,
                                        wrVal);
    if (testResult == CSL_PASS)
    {
        rdVal = 0U;
        testResult = CSL_cbassQosGetOrderID(pQosEpRegs,
                                            channel,
                                            &rdVal);
       if  (testResult == CSL_PASS)
       {
           if (wrVal != rdVal)
           {
               testResult = CSL_EFAIL;
           }
       }
    }

    /* CSL_cbassQosSetEpriority() & CSL_cbassQosGetEpriority() APIs */
    wrVal = CSL_CBASS_QOS_EP_MAP_EPRIORITY_MAX;
    testResult = CSL_cbassQosSetEpriority(pQosEpRegs,
                                          channel,
                                          wrVal);
    if (testResult == CSL_PASS)
    {
        rdVal = 0U;
        testResult = CSL_cbassQosGetEpriority(pQosEpRegs,
                                              channel,
                                              &rdVal);
       if  (testResult == CSL_PASS)
       {
           if (wrVal != rdVal)
           {
               testResult = CSL_EFAIL;
           }
       }
    }

    if (testResult == CSL_PASS)
    {
        testResult = CSL_cbassQosReadStaticRegs (pQosEpRegs, &staticRegs);
    }

    return (testResult);
}

/* CBASS QoS test */
int32_t CBASS_qosTest(void)
{
    int32_t    testResult;

    testResult = CBASS_qosNegtiveTest((CSL_cbass_qosRegs_ep *)CSL_MCU_CBASS0_QOS_BASE);
    if (testResult == CSL_PASS)
    {
        testResult = CBASS_qosApiTest((CSL_cbass_qosRegs_ep *)CSL_MCU_CBASS0_QOS_BASE);
    }

    return (testResult);
}


/* Nothing past this point */
