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
 *  \file st_crcCodeCover.c
 *
 *  \brief Common across test-cases for code coverage.
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
static int32_t st_crcNegtivetest(st_CRCTestcaseParams_t *testParams)
{
    int32_t               retVal = CSL_PASS;
    uint32_t              baseAddr;
    uint32_t              wdPreload;
    uint32_t              blkPreload;
    uint32_t              patCount;
    uint32_t              secCount;
    crcOperationMode_t    crcMode;
    crcSignature_t        sigVal;
    crcSignature_t        rawData;
    crcSignatureRegAddr_t sigRegAddr;
    uint32_t              intVecAddr;
    uint32_t              intrStatus;
    uint32_t              busyFlag;
    uint32_t              secNum;
    CSL_CrcStaticRegs     staticRegs;

    baseAddr   = testParams->crcConfigParams.crcInstBaseAddr;
    wdPreload  = testParams->crcConfigParams.crcWatchdogPreload;
    blkPreload = testParams->crcConfigParams.crcBlockPreload;
    patCount   = testParams->dataSize / testParams->crcConfigParams.crcPatternSize;
    secCount   = testParams->crcConfigParams.crcSectorCount;
    crcMode    = CRC_OPERATION_MODE_FULLCPU;

    /* CRCPowerDownCtrl() API */
    if (CRCPowerDownCtrl(0U, CSL_TRUE) != CSL_EBADARGS)
    {
        retVal = CSL_EFAIL;
    }
    if (retVal == CSL_PASS)
    {
        if (CRCPowerDownCtrl(baseAddr, 0x2U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCChannelReset() API */
    if (retVal == CSL_PASS)
    {
        if (CRCChannelReset(0U, CRC_CHANNEL_1) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCChannelReset(baseAddr, 0U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCInitialize() API */
    if (retVal == CSL_PASS)
    {
        if (CRCInitialize(0U, CRC_CHANNEL_1, wdPreload, blkPreload) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCInitialize(baseAddr, 0U, wdPreload, blkPreload) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCInitialize(baseAddr, CRC_CHANNEL_1, CRC_WDTOPLD_MAX + 1U, blkPreload) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCInitialize(baseAddr, CRC_CHANNEL_1, wdPreload, CRC_BCTOPLD_MAX + 1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCVerifyInitialize() API */
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyInitialize(0U, CRC_CHANNEL_1, wdPreload, blkPreload) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyInitialize(baseAddr, 0U, wdPreload, blkPreload) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyInitialize(baseAddr, CRC_CHANNEL_1, CRC_WDTOPLD_MAX + 1U, blkPreload) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyInitialize(baseAddr, CRC_CHANNEL_1, wdPreload, CRC_BCTOPLD_MAX + 1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCConfigure() API */
    if (retVal == CSL_PASS)
    {
        if (CRCConfigure(0U, CRC_CHANNEL_1, patCount, secCount, crcMode) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCConfigure(baseAddr, 0U, patCount, secCount, crcMode) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCConfigure(baseAddr, CRC_CHANNEL_1, CRC_PATTERN_COUNT_MAX + 1U, secCount, crcMode) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCConfigure(baseAddr, CRC_CHANNEL_1, patCount, CRC_SECTOR_COUNT_MAX + 1U, crcMode) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCConfigure(baseAddr, CRC_CHANNEL_1, patCount, secCount, crcMode + 1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCVerifyConfigure() API */
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyConfigure(0U, CRC_CHANNEL_1, patCount, secCount, crcMode) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyConfigure(baseAddr, 0U, patCount, secCount, crcMode) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyConfigure(baseAddr, CRC_CHANNEL_1, CRC_PATTERN_COUNT_MAX + 1U, secCount, crcMode) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyConfigure(baseAddr, CRC_CHANNEL_1, patCount, CRC_SECTOR_COUNT_MAX + 1U, crcMode) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyConfigure(baseAddr, CRC_CHANNEL_1, patCount, secCount, crcMode + 1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCGetPSASigRegAddr() API */
    if (retVal == CSL_PASS)
    {
        if (CRCGetPSASigRegAddr(0U, CRC_CHANNEL_1, &sigRegAddr) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetPSASigRegAddr(baseAddr, 0U, &sigRegAddr) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetPSASigRegAddr(baseAddr, CRC_CHANNEL_1, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCGetPSASig() API */
    if (retVal == CSL_PASS)
    {
        if (CRCGetPSASig(0U, CRC_CHANNEL_1, &sigVal) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetPSASig(baseAddr, 0U, &sigVal) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetPSASig(baseAddr, CRC_CHANNEL_1, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCSetPSASeedSig() API */
    if (retVal == CSL_PASS)
    {
        if (CRCSetPSASeedSig(0U, CRC_CHANNEL_1, &sigVal) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCSetPSASeedSig(baseAddr, 0U, &sigVal) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCSetPSASeedSig(baseAddr, CRC_CHANNEL_1, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCGetPSASectorSig() API */
    if (retVal == CSL_PASS)
    {
        if (CRCGetPSASectorSig(0U, CRC_CHANNEL_1, &sigVal) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetPSASectorSig(baseAddr, 0U, &sigVal) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetPSASectorSig(baseAddr, CRC_CHANNEL_1, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCGetHighestPriorityIntrStatus() API */
    if (retVal == CSL_PASS)
    {
        if (CRCGetHighestPriorityIntrStatus(0U, &intVecAddr) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetHighestPriorityIntrStatus(baseAddr, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCGetIntrStatus() API */
    if (retVal == CSL_PASS)
    {
        if (CRCGetIntrStatus(0U, CRC_CHANNEL_1, &intrStatus) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetIntrStatus(baseAddr, 0U, &intrStatus) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetIntrStatus(baseAddr, CRC_CHANNEL_1, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCEnableIntr() API */
    if (retVal == CSL_PASS)
    {
        if (CRCEnableIntr(0U, CRC_CHANNEL_1, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCEnableIntr(baseAddr, 0U, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCEnableIntr(baseAddr, CRC_CHANNEL_1, 0x20U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCDisableIntr() API */
    if (retVal == CSL_PASS)
    {
        if (CRCDisableIntr(0U, CRC_CHANNEL_1, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCDisableIntr(baseAddr, 0U, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCDisableIntr(baseAddr, CRC_CHANNEL_1, 0x20U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCClearIntr() API */
    if (retVal == CSL_PASS)
    {
        if (CRCClearIntr(0U, CRC_CHANNEL_1, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCClearIntr(baseAddr, 0U, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCClearIntr(baseAddr, CRC_CHANNEL_1, 0x20U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCIsBusy() API */
    if (retVal == CSL_PASS)
    {
        if (CRCIsBusy(0U, CRC_CHANNEL_1, &busyFlag) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCIsBusy(baseAddr, 0U, &busyFlag) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCIsBusy(baseAddr, CRC_CHANNEL_1, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCGetCurSecNum() API */
    if (retVal == CSL_PASS)
    {
        if (CRCGetCurSecNum(0U, CRC_CHANNEL_1, &secNum) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetCurSecNum(baseAddr, 0U, &secNum) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetCurSecNum(baseAddr, CRC_CHANNEL_1, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCGetCurPSASig() API */
    if (retVal == CSL_PASS)
    {
        if (CRCGetCurPSASig(0U, CRC_CHANNEL_1, &sigVal) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetCurPSASig(baseAddr, 0U, &sigVal) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetCurPSASig(baseAddr, CRC_CHANNEL_1, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCGetRawData() API */
    if (retVal == CSL_PASS)
    {
        if (CRCGetRawData(0U, CRC_CHANNEL_1, &rawData) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetRawData(baseAddr, 0U, &rawData) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCGetRawData(baseAddr, CRC_CHANNEL_1, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCDataBusTracingCtrl() API */
    if (retVal == CSL_PASS)
    {
        if (CRCDataBusTracingCtrl(0U, CSL_TRUE, 0x1U, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCDataBusTracingCtrl(baseAddr, 0x2U, 0x1U, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCDataBusTracingCtrl(baseAddr, CSL_FALSE, 0xfU, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCDataBusTracingCtrl(baseAddr, CSL_FALSE, 0x1U, 0xfU) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCVerifyBusTracingCtrl() API */
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyBusTracingCtrl(0U, CSL_TRUE, 0x1U, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyBusTracingCtrl(baseAddr, 0x2U, 0x1U, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyBusTracingCtrl(baseAddr, CSL_FALSE, 0xfU, 0x1U) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCVerifyBusTracingCtrl(baseAddr, CSL_FALSE, 0x1U, 0xfU) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    /* CRCReadStaticRegs() API */
    if (retVal == CSL_PASS)
    {
        if (CRCReadStaticRegs (0U, &staticRegs) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }
    if (retVal == CSL_PASS)
    {
        if (CRCReadStaticRegs (baseAddr, NULL) != CSL_EBADARGS)
        {
            retVal = CSL_EFAIL;
        }
    }

    return (retVal);
}

static int32_t st_crcCompareStaticRegs(CSL_CrcStaticRegs *pReg1, CSL_CrcStaticRegs *pReg2)
{
    int32_t     retVal = CSL_PASS;
    uint32_t    i;

    if ((pReg1->CTRL0 != pReg2->CTRL0) ||
        (pReg1->CTRL1 != pReg2->CTRL1) ||
        (pReg1->BUS_SEL != pReg2->BUS_SEL))
    {
        retVal = CSL_EFAIL;
    }

    if (retVal == CSL_PASS)
    {
        for (i = 0; i < CRC_MAX_NUM_OF_CHANNELS; i++)
        {
            if ((pReg1->channelRegs[i].PCOUNT != pReg2->channelRegs[i].PCOUNT)     ||
                (pReg1->channelRegs[i].SCOUNT != pReg2->channelRegs[i].SCOUNT)     ||
                (pReg1->channelRegs[i].WDTOPLD != pReg2->channelRegs[i].WDTOPLD)   ||
                (pReg1->channelRegs[i].BCTOPLD != pReg2->channelRegs[i].BCTOPLD))
            {
                retVal = CSL_EFAIL;
                break;
            }
        }
    }

    return (retVal);
}

int32_t st_crcCodeCover_main(st_CRCTestcaseParams_t *testParams)
{
    /*      Declaration of variables      */
    uint32_t              forLoopCount, srcBuffer;
    int32_t               retVal = CSL_PASS;
    uint32_t              dataSize;
    uint32_t             *crcSourceMemory;
    uint32_t              crcPatterCount, crcSectorCount, crcModuleBaseAddress;
    uint32_t              crcWatchdogPreload, crcBlockPreload, crcPatternSize;
    crcChannel_t          crcChannelNumber;
    crcSignature_t        curSignVal[CRC_MAX_NUM_OF_CHANNELS];
    crcSignature_t        refSignVal[CRC_MAX_NUM_OF_CHANNELS];
    crcSignature_t        curRawData[CRC_MAX_NUM_OF_CHANNELS];
    crcSignatureRegAddr_t crcPSASignatureRegAddress[CRC_MAX_NUM_OF_CHANNELS];
    CSL_CrcStaticRegs     staticRegs[2];
    uint32_t              intrStatus[CRC_MAX_NUM_OF_CHANNELS];
    uint32_t              intVecAddr;
    uint32_t              busyFlag[CRC_MAX_NUM_OF_CHANNELS];
    uint32_t              i;
    uint32_t              secNum[CRC_MAX_NUM_OF_CHANNELS];

    /*      Initialization of variables     */
    crcSourceMemory = (uint32_t *) testParams->sourceMemory;
    srcBuffer       = testParams->sourceMemory;

    /*      Configure CRC parameters      */
    crcModuleBaseAddress = testParams->crcConfigParams.crcInstBaseAddr;
    crcPatternSize       = testParams->crcConfigParams.crcPatternSize;
    crcPatterCount       = (testParams->dataSize) / crcPatternSize;
    crcSectorCount       = testParams->crcConfigParams.crcSectorCount;
    crcWatchdogPreload   = testParams->crcConfigParams.crcWatchdogPreload;
    crcBlockPreload      = testParams->crcConfigParams.crcBlockPreload;
    crcChannelNumber     = testParams->crcConfigParams.crcChannelNumber;

    retVal = st_crcNegtivetest(testParams);
    if (retVal == CSL_PASS)
    {
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
    }

    if (retVal == CSL_PASS)
    {
        /* Power down CRC module */
        retVal = CRCPowerDownCtrl(crcModuleBaseAddress, CSL_TRUE);
        if (retVal == CSL_PASS)
        {
            /* Power on CRC module */
            retVal = CRCPowerDownCtrl(crcModuleBaseAddress, CSL_FALSE);
        }

    }

    if (retVal == CSL_PASS)
    {
        dataSize = (testParams->dataSize);
        /*  Initialize source memory with reference data */
        for (forLoopCount = 0; forLoopCount < (dataSize / 4); forLoopCount++)
        {
            crcSourceMemory[forLoopCount] = forLoopCount;
        }
        UART_printf("\nCopied reference data into memory @%x.", srcBuffer);

        /* Initialize all the CRC channels */
        for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
        {
            retVal = CRCInitialize(crcModuleBaseAddress,
                                   CRC_CHANNEL_1 + i,
                                   crcWatchdogPreload,
                                   crcBlockPreload);
            if (retVal != CSL_PASS)
            {
                break;
            }
        }

        if (retVal == CSL_PASS)
        {
            /* Verify initialization of all the 4 channels */
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                retVal = CRCVerifyInitialize(crcModuleBaseAddress,
                                       CRC_CHANNEL_1 + i,
                                       crcWatchdogPreload,
                                       crcBlockPreload);
                if (retVal != CSL_PASS)
                {
                    break;
                }
            }
        }

        if (retVal == CSL_PASS)
        {
            /* Verify initialization of all the 4 channels with wrong initialized values */
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                retVal = CRCVerifyInitialize(crcModuleBaseAddress,
                                       CRC_CHANNEL_1 + i,
                                       crcWatchdogPreload - 1U,
                                       crcBlockPreload - 1U);
                if (retVal == CSL_PASS)
                {
                    break;
                }
            }

            if (retVal == CSL_PASS)
            {
                retVal = CSL_EFAIL;
            }
            else
            {
                retVal = CSL_PASS;
            }
        }
    }

    if (retVal == CSL_PASS)
    {
        /* Reset all the CRC channels */
        for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
        {
            retVal = CRCChannelReset(crcModuleBaseAddress,
                                     CRC_CHANNEL_1 + i);
            if (retVal != CSL_PASS)
            {
                break;
            }
        }

        if (retVal == CSL_PASS)
        {
            /* Configure all the CRC channels to Semi-CPU mode */
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                retVal = CRCConfigure(crcModuleBaseAddress,
                                      CRC_CHANNEL_1 + i,
                                      crcPatterCount,
                                      crcSectorCount,
                                      CRC_OPERATION_MODE_SEMICPU);
                if (retVal != CSL_PASS)
                {
                    break;
                }
            }
            if (retVal == CSL_PASS)
            {
                /* Verify configuration of all the CRC channels */
                for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                {
                    retVal = CRCVerifyConfigure(crcModuleBaseAddress,
                                          CRC_CHANNEL_1 + i,
                                          crcPatterCount,
                                          crcSectorCount,
                                          CRC_OPERATION_MODE_SEMICPU);
                    if (retVal != CSL_PASS)
                    {
                        break;
                    }
                }
            }

            if (retVal == CSL_PASS)
            {
                /* Configure all the CRC channels to Auto mode */
                for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                {
                    retVal = CRCConfigure(crcModuleBaseAddress,
                                          CRC_CHANNEL_1 + i,
                                          crcPatterCount,
                                          crcSectorCount,
                                          CRC_OPERATION_MODE_AUTO);
                    if (retVal != CSL_PASS)
                    {
                        break;
                    }
                }
                if (retVal == CSL_PASS)
                {
                    /* Verify configuration of all the CRC channels */
                    for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                    {
                        retVal = CRCVerifyConfigure(crcModuleBaseAddress,
                                              CRC_CHANNEL_1 + i,
                                              crcPatterCount,
                                              crcSectorCount,
                                              CRC_OPERATION_MODE_AUTO);
                        if (retVal != CSL_PASS)
                        {
                            break;
                        }
                    }
                }
            }

            if (retVal == CSL_PASS)
            {
                /* Configure all the CRC channels to FULL CPU mode */
                for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                {
                    retVal = CRCConfigure(crcModuleBaseAddress,
                                          CRC_CHANNEL_1 + i,
                                          crcPatterCount,
                                          crcSectorCount,
                                          CRC_OPERATION_MODE_FULLCPU);
                    if (retVal != CSL_PASS)
                    {
                        break;
                    }
                }
                if (retVal == CSL_PASS)
                {
                    /* Verify configuration of all the CRC channels */
                    for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                    {
                        retVal = CRCVerifyConfigure(crcModuleBaseAddress,
                                              CRC_CHANNEL_1 + i,
                                              crcPatterCount,
                                              crcSectorCount,
                                              CRC_OPERATION_MODE_FULLCPU);
                        if (retVal != CSL_PASS)
                        {
                            break;
                        }
                    }
                }
            }
        }
        if (retVal == CSL_PASS)
        {
            /* Verify configuration of all the CRC channels with wrong configured values */
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                retVal = CRCVerifyConfigure(crcModuleBaseAddress,
                                      CRC_CHANNEL_1 + i,
                                      crcPatterCount - 1U,
                                      crcSectorCount - 1U,
                                      CRC_OPERATION_MODE_AUTO);
                if (retVal == CSL_PASS)
                {
                    break;
                }
            }
            if (retVal == CSL_PASS)
            {
                retVal = CSL_EFAIL;
            }
            else
            {
                retVal = CSL_PASS;
            }
        }

        if (retVal == CSL_PASS)
        {
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                /* Enable interrupts for all the 4 channels */
                retVal = CRCEnableIntr(crcModuleBaseAddress,
                                       CRC_CHANNEL_1 + i,
                                       (uint32_t)CRC_CHANNEL_IRQSTATUS_RAW_MAIN_ALL);
                if (retVal != CSL_PASS)
                {
                    break;
                }
            }
        }

        if (retVal == CSL_PASS)
        {
            retVal = CRCReadStaticRegs (crcModuleBaseAddress, &staticRegs[0]);
        }

        if (retVal == CSL_PASS)
        {
            for (forLoopCount = 0;
                 forLoopCount < (dataSize / crcPatternSize);
                 forLoopCount++)
            {
                for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
                {
                    /* Write for all the 4 channels */
                    HW_WR_REG32(crcPSASignatureRegAddress[i].regL,
                                crcSourceMemory[forLoopCount]);
                }
            }

            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                retVal = CRCGetCurPSASig(crcModuleBaseAddress,
                                         CRC_CHANNEL_1 + i,
                                         &curSignVal[i]);
                if (retVal == CSL_PASS)
                {
                    retVal = CRCGetRawData(crcModuleBaseAddress,
                                           CRC_CHANNEL_1 + i,
                                           &curRawData[i]);
                    if (retVal != CSL_PASS)
                    {
                        break;
                    }
                }

                if (retVal == CSL_PASS)
                {
                    /* Get interrupts for all the 4 channels */
                    retVal = CRCGetIntrStatus(crcModuleBaseAddress,
                                              CRC_CHANNEL_1 + i,
                                              &intrStatus[i]);
                    if (retVal != CSL_PASS)
                    {
                        break;
                    }
                }

                if (retVal == CSL_PASS)
                {
                    /* Clear interrupts for all the 4 channels */
                    retVal = CRCClearIntr(crcModuleBaseAddress,
                                          CRC_CHANNEL_1 + i,
                                          CRC_CHANNEL_IRQSTATUS_RAW_MAIN_ALL);
                    if (retVal != CSL_PASS)
                    {
                        break;
                    }
                }

                if (retVal == CSL_PASS)
                {
                    retVal = CRCGetHighestPriorityIntrStatus(crcModuleBaseAddress,
                                                             &intVecAddr);
                    if (retVal != CSL_PASS)
                    {
                        break;
                    }
                }

                if (retVal == CSL_PASS)
                {
                    /* Clear interrupts for all the 4 channels */
                    retVal = CRCClearIntr(crcModuleBaseAddress,
                                          CRC_CHANNEL_1 + i,
                                          (uint32_t)CRC_CHANNEL_IRQSTATUS_RAW_MAIN_ALL);
                    if (retVal != CSL_PASS)
                    {
                        break;
                    }
                }

                if (retVal == CSL_PASS)
                {
                    retVal = CRCIsBusy(crcModuleBaseAddress,
                                       CRC_CHANNEL_1 + i,
                                       &busyFlag[i]);
                    if (retVal != CSL_PASS)
                    {
                        break;
                    }
                }
            }
        }

        if (retVal == CSL_PASS)
        {
            /* Fetch CRC signature values for all the channels */
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
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
        }
        if (retVal == CSL_PASS)
        {
            /* Print signature values for all the 4 channels */
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                UART_printf("\n CRC channel %d sector signature value : 0x%x%xU",
                            CRC_CHANNEL_1 + i,
                            refSignVal[i].regH,
                            refSignVal[i].regL);
            }
        }

        if (retVal == CSL_PASS)
        {
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                retVal = CRCGetPSASig(crcModuleBaseAddress,
                                      CRC_CHANNEL_1 + i,
                                      &refSignVal[i]);
                if (retVal != CSL_PASS)
                {
                    break;
                }
            }
        }
        if (retVal == CSL_PASS)
        {
            /* Print signature values for all the 4 channels */
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                UART_printf("\n CRC channel %d signature value : 0x%x%xU",
                            CRC_CHANNEL_1 + i,
                            refSignVal[i].regH,
                            refSignVal[i].regL);
            }
        }

        if (retVal == CSL_PASS)
        {
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                /* Disable interrupts for all the 4 channels */
                retVal = CRCDisableIntr(crcModuleBaseAddress,
                                        CRC_CHANNEL_1 + i,
                                        (uint32_t)CRC_CHANNEL_IRQSTATUS_RAW_MAIN_ALL);
                if (retVal != CSL_PASS)
                {
                    break;
                }
            }
        }

        if (retVal == CSL_PASS)
        {
            for (i = 0U; i < CRC_MAX_NUM_OF_CHANNELS; i++)
            {
                retVal = CRCGetCurSecNum(crcModuleBaseAddress,
                                         CRC_CHANNEL_1 + i,
                                         &secNum[i]);
                if (retVal != CSL_PASS)
                {
                    break;
                }
            }
        }

        if (retVal == CSL_PASS)
        {
            retVal = CRCReadStaticRegs (crcModuleBaseAddress, &staticRegs[1]);
            if (retVal == CSL_PASS)
            {
                retVal = st_crcCompareStaticRegs(&staticRegs[0], &staticRegs[1]);
            }
        }
    }

    if (retVal == CSL_PASS)
    {
        UART_printf("\nCRC code coverage test done successfully.");
        testParams->testResult = CSL_PASS;
    }
    else
    {
        UART_printf("\nCRC code coverage test failed.");
        testParams->testResult = CSL_EFAIL;
    }
    return retVal;
}

