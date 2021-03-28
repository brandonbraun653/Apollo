/*
 *  Copyright (C) 2019 Texas Instruments Incorporated
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
 *  \file st_crcFullCPU.c
 *
 *  \brief Common across test-cases using CRC Full-CPU mode.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include <st_crc.h>

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */
#define ITERATION_COUNT                  (20U)

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
int32_t st_crcFullCPU_main(st_CRCTestcaseParams_t *testParams)
{
    /*      Declaration of variables      */
    uint32_t              forLoopCount, srcBuffer;
    int32_t               retVal = CSL_PASS;
    uint32_t              dataSize;
    uint32_t             *crcSourceMemory;
    uint64_t              timeStampBeforeCrcConfig,
                          timeStampAfterCrcComplete;
    uint32_t              crcCompletionTime;
    uint32_t              crcPatterCount, crcSectorCount, crcModuleBaseAddress;
    uint32_t              crcWatchdogPreload, crcBlockPreload, crcPatternSize;
    crcChannel_t          crcChannelNumber;
    crcOperationMode_t    crcMode;
    crcSignature_t        sectSignVal[CRC_MAX_NUM_OF_CHANNELS], refSignVal[CRC_MAX_NUM_OF_CHANNELS];
    crcSignatureRegAddr_t crcPSASignatureRegAddress[CRC_MAX_NUM_OF_CHANNELS];
    Float32               crcFullCPUPerformance;
    uint32_t              crcFullCPUPerformanceInt;
    uint32_t              i;

    /*      Initialization of variables     */
    crcSourceMemory = (uint32_t *) testParams->sourceMemory;
    srcBuffer       = testParams->sourceMemory;
    for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
    {
        sectSignVal[i].regL = 0U;
        sectSignVal[i].regH = 0U;
    }

    /*      Configure CRC parameters      */
    crcModuleBaseAddress = testParams->crcConfigParams.crcInstBaseAddr;
    crcPatternSize       = testParams->crcConfigParams.crcPatternSize;
    crcPatterCount       = (testParams->dataSize) / crcPatternSize;
    crcSectorCount       = testParams->crcConfigParams.crcSectorCount;
    crcWatchdogPreload   = testParams->crcConfigParams.crcWatchdogPreload;
    crcBlockPreload      = testParams->crcConfigParams.crcBlockPreload;
    crcChannelNumber     = testParams->crcConfigParams.crcChannelNumber;
    crcMode = testParams->crcConfigParams.crcMode;

    /*      Get CRC PSA signature register address    */
    for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
    {
        if (crcChannelNumber == 0U)
        {
            /* Get PSA reg address for all the 4 channels */
            retVal = CRCGetPSASigRegAddr(crcModuleBaseAddress,
                                         CRC_CHANNEL_1 + i,
                                         &crcPSASignatureRegAddress[i]);
            if (retVal != CSL_PASS)
            {
                break;
            }
        }
        else
        {
            /* Get PSA reg address for only 1 channel */
            retVal = CRCGetPSASigRegAddr(crcModuleBaseAddress,
                                         crcChannelNumber,
                                         &crcPSASignatureRegAddress[0]);
            break;
        }
    }

    if (retVal == CSL_PASS)
    {
        dataSize = (testParams->dataSize);

        /*  Initialize source memory with reference data */
        if (0x4a002100U != testParams->sourceMemory)
        {
            for (forLoopCount = 0; forLoopCount < (dataSize / 4); forLoopCount++)
            {
                crcSourceMemory[forLoopCount] = forLoopCount;
            }
            UART_printf("\nCopied reference data into memory @%x.", srcBuffer);
        }

        /* Initialize CRC channel(s) */
        for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
        {
            if (crcChannelNumber == 0U)
            {
                /* Initialize all the 4 channels */
                retVal = CRCInitialize(crcModuleBaseAddress,
                                       CRC_CHANNEL_1 + i,
                                       crcWatchdogPreload,
                                       crcBlockPreload);
                if (retVal != CSL_PASS)
                {
                    break;
                }
            }
            else
            {
                /* Initialize only 1 channel */
                retVal = CRCInitialize(crcModuleBaseAddress,
                                       crcChannelNumber,
                                       crcWatchdogPreload,
                                       crcBlockPreload);
                break;
            }
        }
    }

    if (retVal == CSL_PASS)
    {
        if ((0U == testParams->crcConfigParams.crcSignHigh) &&
            (0U == testParams->crcConfigParams.crcSignLow))
        {
            UART_printf("\nCalculating Reference CRC signature Value.");
            /* Get Reference CRC signature value first. */
            {
                /* Reset CRC channel(s) */
                for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                {
                    if (crcChannelNumber == 0U)
                    {
                        /* Reset all the 4 channels */
                        retVal = CRCChannelReset(crcModuleBaseAddress,
                                                 CRC_CHANNEL_1 + i);
                        if (retVal != CSL_PASS)
                        {
                            break;
                        }
                    }
                    else
                    {
                        /* Reset only 1 channel */
                        retVal = CRCChannelReset(crcModuleBaseAddress,
                                                 crcChannelNumber);
                        break;
                    }
                }

                if (retVal == CSL_PASS)
                {
                    /* Configure CRC channel(s) */
                    for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                    {
                        if (crcChannelNumber == 0U)
                        {
                            /* Configure all the 4 channels */
                            retVal = CRCConfigure(crcModuleBaseAddress,
                                                  CRC_CHANNEL_1 + i,
                                                  crcPatterCount,
                                                  crcSectorCount,
                                                  crcMode);
                            if (retVal != CSL_PASS)
                            {
                                break;
                            }
                        }
                        else
                        {
                            /* Configure only 1 channel */
                            retVal = CRCConfigure(crcModuleBaseAddress,
                                                  crcChannelNumber,
                                                  crcPatterCount,
                                                  crcSectorCount,
                                                  crcMode);
                            break;
                        }
                    }
                }

                if (retVal == CSL_PASS)
                {
                    for (forLoopCount = 0;
                         forLoopCount < (dataSize / crcPatternSize);
                         forLoopCount++)
                    {
                        for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                        {
                            if (crcChannelNumber == 0U)
                            {
                                /* Write for all the 4 channels */
                                HW_WR_REG32(crcPSASignatureRegAddress[i].regL,
                                            crcSourceMemory[forLoopCount]);
                            }
                            else
                            {
                                /* Write for only 1 channel */
                                HW_WR_REG32(crcPSASignatureRegAddress[0].regL,
                                            crcSourceMemory[forLoopCount]);
                                break;
                            }
                        }
                    }
                    /* Fetch CRC signature value */
                    for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                    {
                        if (crcChannelNumber == 0U)
                        {
                            /* Fetch for all the 4 channels */
                            retVal = CRCGetPSASectorSig(crcModuleBaseAddress,
                                                        CRC_CHANNEL_1 + i,
                                                        &refSignVal[i]);
                            if (retVal != CSL_PASS)
                            {
                                break;
                            }
                        }
                        else
                        {
                            /* Fetch for only 1 channel */
                            retVal = CRCGetPSASectorSig(crcModuleBaseAddress,
                                                        crcChannelNumber,
                                                        &refSignVal[0]);
                            break;
                        }
                    }
                }
                if (retVal == CSL_PASS)
                {
                    for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                    {
                        if (crcChannelNumber == 0U)
                        {
                            /* Print for all the 4 channels */
                            UART_printf("\n CRC channel %d signature value : 0x%x%xU",
                                        CRC_CHANNEL_1 + i,
                                        refSignVal[i].regH,
                                        refSignVal[i].regL);
                        }
                        else
                        {
                            /* Print for only 1 channel */
                            UART_printf("\n CRC channel %d signature value : 0x%x%xU",
                                        crcChannelNumber,
                                        refSignVal[0].regH,
                                        refSignVal[0].regL);
                            break;
                        }
                    }
                }
            }
        }
        else
        {
            UART_printf("\nUsing Pre-Defined Reference CRC signature Value.");
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                if (crcChannelNumber == 0U)
                {
                    /* Set for all the 4 channels */
                    refSignVal[i].regH = testParams->crcConfigParams.crcSignHigh;
                    refSignVal[i].regL = testParams->crcConfigParams.crcSignLow;
                }
                else
                {
                    /* Set for only 1 channel */
                    refSignVal[0].regH = testParams->crcConfigParams.crcSignHigh;
                    refSignVal[0].regL = testParams->crcConfigParams.crcSignLow;
                    break;
                }

            }
        }
    }

    if (retVal == CSL_PASS)
    {
        /* Get time-stamp */
        timeStampBeforeCrcConfig = TimerP_getTimeInUsecs();

        for (forLoopCount = 0U; forLoopCount < ITERATION_COUNT; forLoopCount++)
        {
            /* CRC channel RESET before initialization/configuration */
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                if (crcChannelNumber == 0U)
                {
                    /* Reset all the 4 channels */
                    retVal = CRCChannelReset(crcModuleBaseAddress,
                                             CRC_CHANNEL_1 + i);
                    if (retVal != CSL_PASS)
                    {
                        break;
                    }
                }
                else
                {
                    /* Reset only 1 channel */
                    retVal = CRCChannelReset(crcModuleBaseAddress,
                                             crcChannelNumber);
                    break;
                }
            }

            if (retVal == CSL_PASS)
            {
                /* Configure CRC channel */
                /* Configure CRC channel(s) */
                for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                {
                    if (crcChannelNumber == 0U)
                    {
                        /* Configure all the 4 channels */
                        retVal = CRCConfigure(crcModuleBaseAddress,
                                              CRC_CHANNEL_1 + i,
                                              crcPatterCount,
                                              crcSectorCount,
                                              crcMode);
                        if (retVal != CSL_PASS)
                        {
                            break;
                        }
                    }
                    else
                    {
                        /* Configure only 1 channel */
                        retVal = CRCConfigure(crcModuleBaseAddress,
                                              crcChannelNumber,
                                              crcPatterCount,
                                              crcSectorCount,
                                              crcMode);
                        break;
                    }
                }
            }

            if (retVal == CSL_PASS)
            {
                for (forLoopCount = 0;
                     forLoopCount < (dataSize / crcPatternSize);
                     forLoopCount++)
                {
                    for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                    {
                        if (crcChannelNumber == 0U)
                        {
                            /* Write for all the 4 channels */
                            HW_WR_REG32(crcPSASignatureRegAddress[i].regL,
                                        crcSourceMemory[forLoopCount]);
                        }
                        else
                        {
                            /* Write for only 1 channel */
                            HW_WR_REG32(crcPSASignatureRegAddress[0].regL,
                                        crcSourceMemory[forLoopCount]);
                            break;
                        }
                    }
                }

                for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                {
                    if (crcChannelNumber == 0U)
                    {
                        /* Fetch for all the 4 channels */
                        retVal = CRCGetPSASectorSig(crcModuleBaseAddress,
                                                    CRC_CHANNEL_1 + i,
                                                    &sectSignVal[i]);
                        if (retVal != CSL_PASS)
                        {
                            break;
                        }
                    }
                    else
                    {
                        /* Fetch for only 1 channel */
                        retVal = CRCGetPSASectorSig(crcModuleBaseAddress,
                                                    crcChannelNumber,
                                                    &sectSignVal[0]);
                        break;
                    }
                }
            }

            if (retVal == CSL_PASS)
            {
                /* Compare CRC signature value against reference CRC signature*/
                for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                {
                    if (crcChannelNumber == 0U)
                    {
                        /* Compare for all the 4 channels */
                        if ((sectSignVal[i].regH != refSignVal[i].regH)  ||
                            (sectSignVal[i].regL != refSignVal[i].regL))
                        {
                            retVal = CSL_EFAIL;
                            break;
                        }
                    }
                    else
                    {
                        /* Fetch for only 1 channel */
                        if ((sectSignVal[0].regH != refSignVal[0].regH)  ||
                            (sectSignVal[0].regL != refSignVal[0].regL))
                        {
                            retVal = CSL_EFAIL;
                        }
                        break;
                    }
                }
                if (retVal != CSL_PASS)
                {
                    if (crcChannelNumber == 0U)
                    {
                        UART_printf("\nCRC channel %d sector signature does not match.",
                                    i);
                        UART_printf("\nExpected CRC signature value : 0x%x%xU",
                                    refSignVal[i].regH,
                                    refSignVal[i].regL);
                        UART_printf("\nCalculated CRC signature value : 0x%08x%08xU",
                                    sectSignVal[i].regH,
                                    sectSignVal[i].regL);
                    }
                    else
                    {
                        UART_printf("\nCRC channel %d sector signature does not match.",
                                    crcChannelNumber);
                        UART_printf("\nExpected CRC signature value : 0x%x%xU",
                                    refSignVal[0].regH,
                                    refSignVal[0].regL);
                        UART_printf("\nCalculated CRC signature value : 0x%08x%08xU",
                                    sectSignVal[0].regH,
                                    sectSignVal[0].regL);
                    }
                    break;
                }
            }
            else
            {
                break;
            }
        }
    }

    if (retVal == CSL_PASS)
    {
        /*      get the time-stamp       */
        timeStampAfterCrcComplete = TimerP_getTimeInUsecs();
    }

    if (retVal == CSL_PASS)
    {
        UART_printf("\nCRC signature verification done successfully.");
        if (ST_TT_PERFORMANCE ==
            (testParams->testType & ST_TT_PERFORMANCE))
        {
            crcCompletionTime = (uint32_t) ((timeStampAfterCrcComplete -
                                  timeStampBeforeCrcConfig) / 1000U);
            crcFullCPUPerformance =
                (Float32) (((Float32) dataSize) / crcCompletionTime) * 1000U ;
            crcFullCPUPerformance = ((Float32) crcFullCPUPerformance) *
                                    ((Float32) ITERATION_COUNT);
            crcFullCPUPerformance = (Float32) crcFullCPUPerformance /
                                    (1024U * 1024U);
            crcFullCPUPerformanceInt = (uint32_t) crcFullCPUPerformance;
            UART_printf("\nProcessed data of size %u Bytes %d times in %u ms."
                   , testParams->dataSize, ITERATION_COUNT,
                   crcCompletionTime);
            UART_printf("\nCRC performance: %u MB/s", crcFullCPUPerformanceInt);
        }
        testParams->testResult = CSL_PASS;
    }
    else
    {
        UART_printf("\nCRC signature verification failed.");
        testParams->testResult = CSL_EFAIL;
    }
    return retVal;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */
/* None */
