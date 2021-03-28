/**
 *  \file   nand_lib_gpmc.c
 *
 *  \brief  This file contains the NAND GPMC controller specific functions
 *          and these are provided as platform specific code
 *          to achieve the required functionality.
 *
 */

/**
 * \copyright  Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
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

#include "types.h"
#include "nand_lib_gpmc.h"
#include "hw_types.h"
#include "hw_gpmc.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief Macro which defines the ECC size value. */
#define NAND_LIB_GPMC_ECC_SIZE_VAL                       (0xFFU)

/** \brief Macro which defines the FIFO threshold for prefetch engine. */
#define NAND_LIB_GPMC_PREFETCH_FIFO_THRLD                (64U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function does the 1-bit hamming code ECC related initializes
 *          to the NAND controller.
 *
 * \param   pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                      flash device information.
 */
static void NandLibGpmcHammingCodeEccInit(nandLibInfo_t *pNandInfo);

/**
 * \brief   This function reads/calculates the 1-bit hamming code ECC values.
 *
 * \param  baseAddr      Base address of the GPMC controller.
 * \param  eccResReg     ECC Result register value.
 * \param  pEccData      Pointer where read ECC data has to store.
 */
static void NandLibGpmcHammingCodeEccCalculate(uint32_t baseAddr,
                                               uint32_t eccResReg,
                                               uint8_t *pEccData);

/**
 *  \brief    This function checks for ECC errors using 1-bit hamming code
 *            algorithm and correct if any ECC errors.
 *
 *  \param     pNandInfo  Pointer to the nandLibInfo_t structure containing the
 *                        flash device information.
 *  \param     pEccRead   Pointer to the ECC data which is read from the spare
 *                        area.
 *  \param     pData      Pointer to the data, where if an ecc error need to
 *                        correct.
 *
 * \retval    NAND_LIB_PASS      If no ecc errors detected.
 * \retval    NAND_LIB_ECC_ERR_CORRECTED     If errors are corrected.
 * \retval    NAND_LIB_ECC_UNCORRECTABLE     If errors are uncorrectable.
 */
static int32_t NandLibGpmcHamCodeEccCorrect(nandLibInfo_t *pNandInfo,
                                            uint8_t *pEccRead,
                                            uint8_t *pData);

/**
 * \brief   This function does the BCH ECC related initializes to the NAND
 *          controller.
 *
 * \param   pNandInfo  Pointer to the nandLibInfo_t structure containing the
 *                        flash device information.
 *
 * \retval  NAND_LIB_PASS     On Successful initialization.
 * \retval  NAND_LIB_FAIL     On Initialization failure.
 * \retval  NAND_LIB_INVALID_PARAM If unsupported ECC is used.
 */
static int32_t NandLibGpmcBchEccInit(nandLibInfo_t *pNandInfo);

/**
 * \brief   This Function configures the BCH ECC related setting for write
 *          operation.
 *
 * \param   pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                      flash device information.
 */
static void NandLibGpmcBchWriteSet(nandLibInfo_t *pNandInfo);

/**
 * \brief   This Function configures the BCH ECC related setting for read
 *          operation.
 *
 * \param   pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                      flash device information.
 */
static void NandLibGpmcBchReadSet(nandLibInfo_t *pNandInfo);

/**
 * \brief   This function reads/calculates the BCH 8-bit ECC values.
 *
 * \param  pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                      flash device information.
 * \param  pEccData     Pointer where read ECC data has to store.
 *
 */
static void NandLibGpmcBchEccCalculate(nandLibInfo_t *pNandInfo,
                                       uint8_t *pEccData);

/**
 * \brief   This function checks for ECC errors using BCH algorithm and corrects
 *          if any ECC errors.
 *
 * \param   pNandInfo    Pointer to the nandLibInfo_t structure containing the
 *                       flash device information.
 * \param   pEccRead     Pointer to the ECC data which is read from the spare
 *                       area.
 * \param   pData        Pointer to the data, for which error code correction
 *                       is to be performed.
 *
 * \retval  NAND_LIB_PASS       If no ecc errors detected.
 * \retval  NAND_LIB_ECC_ERR_CORRECTED      If errors are corrected.
 * \retval  NAND_LIB_ECC_UNCORRECTABLE  If errors are uncorrectable.
 */
static int32_t NandLibGpmcBchEccCheckAndCorrect(nandLibInfo_t *pNandInfo,
                                                uint8_t *pEccRead,
                                                uint8_t *pData);



/* ========================================================================== */
/*                       Global Variables                                     */
/* ========================================================================== */

/* ========================================================================== */
/*                       Function Definitions                                 */
/* ========================================================================== */

int32_t NANDLibGpmcInit(nandLibInfo_t *pNandInfo)
{
    uint32_t baseAddr = pNandInfo->nandLibCtrlInfo.baseAddr;
    uint32_t chipSel = pNandInfo->nandLibCtrlInfo.chipSel;
    volatile uint32_t timeOut = 0xFFFU;
    uint32_t status = NAND_LIB_PASS;
    gpmcChipSelTimingParams_t csTimingParams;
    gpmcAdvSignalTimingParams_t advSignalTimingParams;
    gpmcOeWeSignalTimingParams_t oeWeSignalTimingParams;
    gpmcReadAccessTime_t readAccesParams;
    gpmcCycle2CycleDelay_t cycleDelayParams;

    /* GPMC Module configuration */
    GPMCModuleSoftReset(baseAddr);
    while((GPMCModuleResetStatusGet(baseAddr) != TRUE) && (timeOut != 0))
    {
        timeOut--;
    }
    if(timeOut == 0)
    {
        status = NAND_LIB_TIMEOUT;
    }

    if(NAND_LIB_PASS == status)
    {
        GPMCIdleModeSelect(baseAddr, GPMC_IDLE_MODE_NO_IDLE);

        /* Disable all interrupts */
        GPMCIntrDisable(baseAddr, GPMC_INTR_MASK_ALL);

        /* Timeout control disable */
        GPMCTimeOutFeatureConfig(baseAddr, FALSE);

        /* Set the wait pin polarity */
        GPMCWaitPinSelect(baseAddr, chipSel,
            pNandInfo->nandLibFlashInfo.waitPinNum);
        GPMCSetWaitPinPol(baseAddr, pNandInfo->nandLibFlashInfo.waitPinNum,
            pNandInfo->nandLibFlashInfo.waitPinPol);
        GPMCWriteProtectPinLevelCtrl(baseAddr,
            pNandInfo->nandLibFlashInfo.writeProtectPinLvl);
        GPMCLimitedAddrDevSupportConfig(baseAddr, TRUE);

        GPMCChipSelEnable(baseAddr, chipSel, FALSE);
        GPMCSetTimeParaGranularity(baseAddr, chipSel, GPMC_TIME_GRANULARITY_X2);

        GPMCSetDevType(baseAddr, chipSel, GPMC_DEV_TYPE_NAND);

        if(NAND_LIB_BUS_WIDTH_8BIT == pNandInfo->nandLibFlashInfo.busWidth)
        {
            GPMCSetDevSize(baseAddr, chipSel, GPMC_DEV_SIZE_8BIT);
        }
        else
        {
            GPMCSetDevSize(baseAddr, chipSel, GPMC_DEV_SIZE_16BIT);
        }
        GPMCSetAddrDataMuxType(baseAddr, chipSel, GPMC_MUX_TYPE_NONE);

        GPMCSetAccessType(baseAddr, chipSel, GPMC_ACCESS_TYPE_ASYNC_WRITE);
        GPMCSetAccessType(baseAddr, chipSel, GPMC_ACCESS_TYPE_ASYNC_READ);

        GPMCSetAccessMode(baseAddr, chipSel, GPMC_OPER_MODE_WRITE,
            GPMC_ACCESS_MODE_SINGLE);
        GPMCSetAccessMode(baseAddr, chipSel, GPMC_OPER_MODE_READ,
            GPMC_ACCESS_MODE_SINGLE);

        GPMCSetChipSelBaseAddr(baseAddr, chipSel, (0x10000000 >>24));

        GPMCSetChipSelMaskAddr(baseAddr, chipSel, GPMC_MASK_ADDR_256MB);

        csTimingParams.chipSelWrOffTime =
            pNandInfo->nandLibFlashInfo.timingParams.csWrOffTime;
        csTimingParams.chipSelRdOffTime =
            pNandInfo->nandLibFlashInfo.timingParams.csRdOffTime;
        csTimingParams.chipSelOnTime =
            pNandInfo->nandLibFlashInfo.timingParams.csOnTime;
        csTimingParams.addExtDelay = FALSE;

        GPMCChipSelectTimingConfig(baseAddr, chipSel, &csTimingParams);

        advSignalTimingParams.advOnTime =
            pNandInfo->nandLibFlashInfo.timingParams.advOnTime;
        advSignalTimingParams.advRdOffTime =
            pNandInfo->nandLibFlashInfo.timingParams.advRdOffTime;
        advSignalTimingParams.advWrOffTime =
            pNandInfo->nandLibFlashInfo.timingParams.advWrOffTime;
        /*
        ** ADV assertion and deassertion timings to be set to zero for
        ** AAD-Multiplexed protocol as NAND is a non multiplexed device.
        */
        advSignalTimingParams.advAadMuxWrOffTime = 0U;
        advSignalTimingParams.advAadMuxRdOffTime = 0U;
        advSignalTimingParams.advAadMuxOnTime = 0U;
        advSignalTimingParams.addExtDelay = FALSE;
        GPMCADVTimingConfig(baseAddr, chipSel, &advSignalTimingParams);

        oeWeSignalTimingParams.writeEnableOffTime =
            pNandInfo->nandLibFlashInfo.timingParams.weOffTime;
        oeWeSignalTimingParams.writeEnableOnTime =
            pNandInfo->nandLibFlashInfo.timingParams.weOnTtime;
        oeWeSignalTimingParams.oeOffTime =
            pNandInfo->nandLibFlashInfo.timingParams.oeOffTime;
        oeWeSignalTimingParams.oeOnTime =
            pNandInfo->nandLibFlashInfo.timingParams.oeOnTime;
        oeWeSignalTimingParams.oeAadMuxOffTime = 0U;
        oeWeSignalTimingParams.oeAadMuxOnTime = 5U;
        oeWeSignalTimingParams.addExtDelay = FALSE;
        GPMCWEAndOETimingConfig(baseAddr, chipSel, &oeWeSignalTimingParams);

        readAccesParams.readCycleTime =
            pNandInfo->nandLibFlashInfo.timingParams.rdCycleTime;
        readAccesParams.writeCycleTime =
            pNandInfo->nandLibFlashInfo.timingParams.wrCycleTime;

        readAccesParams.readAccessTime =
            pNandInfo->nandLibFlashInfo.timingParams.rdAccessTime;
        readAccesParams.pageBurstAccessTime =
            pNandInfo->nandLibFlashInfo.timingParams.pageBurstAccess;
        GPMCRdAccessAndCycleTimeTimingConfig(baseAddr, chipSel, &readAccesParams);

        GPMCWrAccessAndWrDataOnADMUXBusTimingConfig(baseAddr, chipSel,
            pNandInfo->nandLibFlashInfo.timingParams.wrAcessTime,
            pNandInfo->nandLibFlashInfo.timingParams.wrDataOnMuxBusTime);

        cycleDelayParams.cycle2CycleDelay =
            pNandInfo->nandLibFlashInfo.timingParams.cycleDelay;
        cycleDelayParams.cycleDelaySameChipSel =
            GPMC_CYCLE_DELAY_SAME_CHIP_SEL_NO_DELAY;
        cycleDelayParams.cycleDelayDiffChipSel =
            GPMC_CYCLE_DELAY_DIFF_CHIP_SEL_NO_DELAY;
        cycleDelayParams.busTurnAroundTime = 0U;
        GPMCycle2CycleAndTurnArndTimeTimingConfig(baseAddr, chipSel, &cycleDelayParams);

        GPMCChipSelEnable(baseAddr, chipSel, TRUE);
    }

    return status;
}

uint32_t NANDLibGpmcWaitPinStatus(nandLibInfo_t *pNandInfo)
{
    uint32_t pinStatus = 0U;

    pinStatus = GPMCWaitPinStatus(pNandInfo->nandLibCtrlInfo.baseAddr,
                                     pNandInfo->nandLibFlashInfo.waitPinNum);
    return pinStatus;
}

uint32_t NANDLibGpmcFifoStatus(nandLibInfo_t *pNandInfo)
{
    uint32_t status = 0U;

    status = GPMCEmptyWriteBuffStatusGet(pNandInfo->nandLibCtrlInfo.baseAddr);

    return status;
}

uint32_t NANDLibGpmcGetData(nandLibInfo_t *pNandInfo)
{
    uint32_t data = 0;
    uint32_t baseAddr = pNandInfo->nandLibCtrlInfo.baseAddr;
    uint32_t chipSel = pNandInfo->nandLibCtrlInfo.chipSel;

    if(pNandInfo->nandLibFlashInfo.busWidth == NAND_LIB_BUS_WIDTH_8BIT)
    {
        data = (*(volatile uint8_t*)(baseAddr + GPMC_NAND_DATA(chipSel)));
    }
    else
    {
        data = (*(volatile uint16_t*)(baseAddr + GPMC_NAND_DATA(chipSel)));
    }

    return data;
}

void NANDLibGpmcSetData(nandLibInfo_t *pNandInfo, uint32_t data)
{
    uint32_t baseAddr = pNandInfo->nandLibCtrlInfo.baseAddr;
    uint32_t chipSel = pNandInfo->nandLibCtrlInfo.chipSel;

    if(pNandInfo->nandLibFlashInfo.busWidth == NAND_LIB_BUS_WIDTH_8BIT)
    {
        (*(volatile uint8_t *)(baseAddr + GPMC_NAND_DATA(chipSel))) =
            (uint8_t) data;
    }
    else
    {
        (*(volatile uint16_t *)(baseAddr + GPMC_NAND_DATA(chipSel))) =
            (uint16_t) data;
    }
}

void NANDLibGpmcSetCommand(nandLibInfo_t *pNandInfo, uint32_t command)
{
    uint32_t baseAddr = pNandInfo->nandLibCtrlInfo.baseAddr;
    uint32_t chipSel = pNandInfo->nandLibCtrlInfo.chipSel;

    (*(volatile uint8_t*)(baseAddr + GPMC_NAND_COMMAND(chipSel))) =
         (uint8_t) command;
}

void NANDLibGpmcSetAddr(nandLibInfo_t *pNandInfo, uint32_t addr)
{
    uint32_t baseAddr = pNandInfo->nandLibCtrlInfo.baseAddr;
    uint32_t chipSel = pNandInfo->nandLibCtrlInfo.chipSel;

    (*(volatile uint8_t*)(baseAddr + GPMC_NAND_ADDRESS(chipSel))) =
        (uint8_t) addr;
}

int32_t NANDLibGpmcEccInit(nandLibInfo_t *pNandInfo)
{
    int32_t status = NAND_LIB_PASS;

    if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_HAMMING_1BIT)
    {
        NandLibGpmcHammingCodeEccInit(pNandInfo);
    }
    else if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_4BIT ||
            pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_8BIT)
    {
        status = NandLibGpmcBchEccInit(pNandInfo);
    }

    return status;
}

void NANDLibGpmcEccEnable(nandLibInfo_t *pNandInfo)
{
    uint32_t baseAddr = pNandInfo->nandLibCtrlInfo.baseAddr;

    GPMCECCResultRegClear(baseAddr);

    GPMCECCResultRegSelect(baseAddr, GPMC_ECC_RESULT_REG_1);

    GPMCEccEnable(baseAddr, TRUE);
}

void NANDLibGpmcEccDisable(nandLibInfo_t *pNandInfo)
{
    uint32_t baseAddr = pNandInfo->nandLibCtrlInfo.baseAddr;

    GPMCEccEnable(baseAddr, FALSE);
}

void NANDLibGpmcEccWriteSet(nandLibInfo_t *pNandInfo)
{
    if(NAND_LIB_ECC_ALGO_BCH_8BIT == pNandInfo->nandLibCtrlInfo.eccAlgo)
    {
        NandLibGpmcBchWriteSet(pNandInfo);
    }
}

void NANDLibGpmcEccReadSet(nandLibInfo_t *pNandInfo)
{
    if(NAND_LIB_ECC_ALGO_BCH_8BIT == pNandInfo->nandLibCtrlInfo.eccAlgo)
    {
        NandLibGpmcBchReadSet(pNandInfo);
    }
}

void NANDLibGpmcEccCalculate(nandLibInfo_t *pNandInfo, uint8_t *pEccData)
{
    if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_HAMMING_1BIT)
    {
        NandLibGpmcHammingCodeEccCalculate(pNandInfo->nandLibCtrlInfo.baseAddr,
                                    GPMC_ECC_RESULT_REG_1, pEccData);
    }
    else if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_4BIT ||
            pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_8BIT)
    {
        NandLibGpmcBchEccCalculate(pNandInfo, pEccData);
    }
}

int32_t NANDLibGpmcEccCheckAndCorrect(nandLibInfo_t *pNandInfo,
                                      uint8_t *pEccRead,
                                      uint8_t *pData)
{
    int32_t status = NAND_LIB_PASS;

    if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_HAMMING_1BIT)
    {
        status = NandLibGpmcHamCodeEccCorrect(pNandInfo, pEccRead, pData);
    }
    else if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_4BIT ||
            pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_8BIT)
    {
        status = NandLibGpmcBchEccCheckAndCorrect(pNandInfo, pEccRead, pData);
    }

    return status;
}

/* ========================================================================== */
/*                 Internal Function Definitions                              */
/* ========================================================================== */

static void NandLibGpmcHammingCodeEccInit(nandLibInfo_t *pNandInfo)
{
    uint32_t baseAddr = pNandInfo->nandLibCtrlInfo.baseAddr;
    uint32_t chipSel = pNandInfo->nandLibCtrlInfo.chipSel;

    GPMCECCAlgoSelect(baseAddr, GPMC_ECC_ALGO_HAMMING_CODE);
    GPMCECCColumnSelect(baseAddr, GPMC_ECC_COLUMN_8);
    GPMCSetEccChipSel(baseAddr, chipSel);
    GPMCEccEnable(baseAddr, FALSE);
    GPMCECCResultRegSelect(baseAddr, GPMC_ECC_RESULT_REG_1);
    GPMCECCResultRegClear(baseAddr);
    GPMCECCSizeValSet(baseAddr, GPMC_ECC_SIZE_NUM_0, NAND_LIB_GPMC_ECC_SIZE_VAL);
    GPMCECCSizeValSet(baseAddr, GPMC_ECC_SIZE_NUM_1, NAND_LIB_GPMC_ECC_SIZE_VAL);
    GPMCECCResultSizeSelect(baseAddr, GPMC_ECC_RESULT_REG_1, GPMC_ECC_SIZE_NUM_0);
}

static void NandLibGpmcHammingCodeEccCalculate(uint32_t baseAddr,
                                               uint32_t eccResReg,
                                               uint8_t *pEccData)
{
    uint32_t eccVal;

    eccVal  = GPMCECCResultGet(baseAddr, eccResReg);
    /*
    ** Squeeze 4 bytes ECC into 3 bytes by removing RESERVED bits
    ** and shifting. RESERVED bits are 31 to 28 and 15 to 12.
    */
    eccVal = (eccVal & 0x00000FFF) | ((eccVal & 0x0FFF0000) >> 4);
    /* Invert so that erased block ECC is correct */
    eccVal = ~eccVal;

    *pEccData++ = (uint8_t)eccVal;
    *pEccData++ = (uint8_t)(eccVal >>  8U);
    *pEccData++ = (uint8_t)(eccVal >> 16U);
}

static int32_t NandLibGpmcHamCodeEccCorrect(nandLibInfo_t *pNandInfo,
                                            uint8_t *pEccRead,
                                            uint8_t *pData)
{
    int32_t status = NAND_LIB_PASS;
    uint8_t eccCalc[4];
    uint32_t readEccVal = 0U;
    uint32_t calcEccVal = 0U;
    uint32_t eccDiffVal = 0U;
    uint32_t bitPos = 0U;
    uint32_t bytePos = 0U;

    NandLibGpmcHammingCodeEccCalculate(pNandInfo->nandLibCtrlInfo.baseAddr,
                                    GPMC_ECC_RESULT_REG_1, &eccCalc[0]);

    readEccVal = pEccRead[0] | (pEccRead[1] << 8) | (pEccRead[2] << 16);
    calcEccVal = eccCalc[0] | (eccCalc[1] << 8) | (eccCalc[2] << 16);
    eccDiffVal = readEccVal ^ calcEccVal;

    if(eccDiffVal)
    {
        /*
        ** No error              : The ecc diff value (eccDiffVal) is 0.
        ** Correctable error     : For 512-byte inputs, ecc diff value has
        **                         12 bits at 1. For 256 byte ecc diff value has
        **                         11 bits at 1.
        ** ECC error             : The ecc diff value has only 1 bit at 1.
        ** Non-correctable error : The ecc diff value provides all other results
        */

        /*
        ** Below condition checks for number of 1's in eccDiffValu.
        ** Since Total ecc has 3bytes = 24 bits. Make 2 halfs and XOR.
        ** If eccDiffVal has  12 1's, it produces the result 0xFFF.
        */
        if ((((eccDiffVal >> 12) ^ eccDiffVal) & 0xfff) == 0xfff)
        {
             /* Correctable error
             ** Check bytePos is within NAND_BYTES_PER_TRNFS i.e 512
             */
            if ((eccDiffVal >> (12 + 3)) < NAND_LIB_BYTES_PER_TRNFS)
            {
                bitPos  = 1 << ((eccDiffVal >> 12) & 7);
                bytePos = eccDiffVal >> (12 + 3);
                pData[bytePos] ^= bitPos;
                status = NAND_LIB_ECC_ERR_CORRECTED;
            }
            else
            {
                status = NAND_LIB_ECC_UNCORRECTABLE;
            }
        }
        else if(!(eccDiffVal & (eccDiffVal - 1)))
        {
            /* Single bit ECC error in the ECC itself,nothing to fix */
            status = NAND_LIB_ECC_ERR_CORRECTED;
        }
        else
        {
            status = NAND_LIB_ECC_UNCORRECTABLE;
        }
    }

    return (status);
}

static int32_t NandLibGpmcBchEccInit(nandLibInfo_t *pNandInfo)
{
    uint32_t baseAddr = pNandInfo->nandLibCtrlInfo.baseAddr;
    uint32_t elmBaseAddr = pNandInfo->nandLibCtrlInfo.elmAddr;
    uint32_t chipSel = pNandInfo->nandLibCtrlInfo.chipSel;
    volatile uint32_t timeOut = 0xFFFU;
    int32_t status = NAND_LIB_PASS;

    GPMCEccEnable(baseAddr, FALSE);
    GPMCECCAlgoSelect(baseAddr, GPMC_ECC_ALGO_BCH_CODE);

    if(pNandInfo->nandLibCtrlInfo.eccAlgo != NAND_LIB_ECC_ALGO_BCH_8BIT)
    {
        status = NAND_LIB_INVALID_PARAM;
    }
    else
    {
        GPMCSetBchEccCapability(baseAddr, GPMC_BCH_CAP_LVL_8_BITS);

        GPMCECCColumnSelect(baseAddr, pNandInfo->nandLibFlashInfo.busWidth);
        GPMCSetEccChipSel(baseAddr, chipSel);
        GPMCECCBCHNumOfSectorsSelect(baseAddr, 0U);
        GPMCSetBchWrapModeVal(baseAddr, 0x1U);

        GPMCECCResultRegSelect(baseAddr, GPMC_ECC_RESULT_REG_1);
        GPMCECCResultRegClear(baseAddr);

        GPMCECCSizeValSet(baseAddr, GPMC_ECC_SIZE_NUM_0,
            NAND_LIB_GPMC_ECC_SIZE_VAL);
        GPMCECCSizeValSet(baseAddr, GPMC_ECC_SIZE_NUM_1,
            NAND_LIB_GPMC_ECC_SIZE_VAL);
        GPMCECCResultSizeSelect(baseAddr, GPMC_ECC_RESULT_REG_1,
            GPMC_ECC_SIZE_NUM_0);

        /* ELM Module configuration */
        ELMModuleReset(elmBaseAddr);
        while((ELMModuleResetStatusGet(elmBaseAddr) != 1) && (timeOut != 0))
        {
            timeOut--;
        }
        if(timeOut == 0)
        {
            status = NAND_LIB_TIMEOUT;
        }
        else
        {
            ELMCAutoGatingConfig(elmBaseAddr, TRUE);
            ELMCIdleModeSelect(elmBaseAddr, ELM_IDLE_MODE_NO_IDLE);
            ELMOCPClkActivityConfig(elmBaseAddr, ELM_OCP_CLK_ACTIVITY_ON);
            ELMIntStatusClear(elmBaseAddr, ELM_INTR_MASK_SYNDR_POLY_0);
            ELMIntrEnable(elmBaseAddr, ELM_INTR_MASK_SYNDR_POLY_0);
            ELMErrCorrectionLevelSet(elmBaseAddr, ELM_BCH_ECC_LEVEL_8_BITS);
            ELMECCSizeSet(elmBaseAddr, 0x7FFU);
            ELMSetPageMode(elmBaseAddr, ELM_SECTOR_MASK_NUM_0);
        }
    }

    return status;
}

static void NandLibGpmcBchWriteSet(nandLibInfo_t *pNandInfo)
{
    uint32_t size1 = 0U;
    uint32_t size0 = 0U;

    if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_4BIT)
    {
       /* Not Supported */
    }
    else if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_8BIT)
    {
        size1 = (NAND_LIB_ECC_BCH_8BIT_BYTECNT * 2);
        size0 = 0U;
    }
    GPMCECCSizeValSet(pNandInfo->nandLibCtrlInfo.baseAddr, GPMC_ECC_SIZE_NUM_0,
        size0);
    GPMCECCSizeValSet(pNandInfo->nandLibCtrlInfo.baseAddr, GPMC_ECC_SIZE_NUM_1,
        size1);
}

static void NandLibGpmcBchReadSet(nandLibInfo_t *pNandInfo)
{
    uint32_t size1 = 0U;
    uint32_t size0 = 0U;

    if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_4BIT)
    {
       /* Not Supported */
    }
    else if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_8BIT)
    {
        size0 = ((NAND_LIB_ECC_BCH_8BIT_BYTECNT * 2) -
                  NAND_LIB_ECC_BCH_8BIT_UNUSED_BYTECNT);
        size1 = NAND_LIB_ECC_BCH_8BIT_UNUSED_BYTECNT;
    }
    GPMCECCSizeValSet(pNandInfo->nandLibCtrlInfo.baseAddr, GPMC_ECC_SIZE_NUM_0,
        size0);
    GPMCECCSizeValSet(pNandInfo->nandLibCtrlInfo.baseAddr, GPMC_ECC_SIZE_NUM_1,
        size1);
}

static void NandLibGpmcBchEccCalculate(nandLibInfo_t *pNandInfo,
                                       uint8_t *pEccData)
{
    uint32_t eccRes = 0U;
    uint32_t baseAddr = pNandInfo->nandLibCtrlInfo.baseAddr;
    uint32_t eccAlgo = pNandInfo->nandLibCtrlInfo.eccAlgo;
    uint32_t chipSel = pNandInfo->nandLibCtrlInfo.chipSel;

    if(eccAlgo == NAND_LIB_ECC_ALGO_BCH_4BIT)
    {
       /* Not Supported */
    }
    else if(eccAlgo == NAND_LIB_ECC_ALGO_BCH_8BIT)
    {
        eccRes = GPMCECCBCHResultGet(baseAddr, 3, chipSel);
        pEccData[0] = (eccRes & 0xFF);
        eccRes = GPMCECCBCHResultGet(baseAddr, 2, chipSel);
        pEccData[1] = ((eccRes >> 24) & 0xFF);
        pEccData[2] = ((eccRes >> 16) & 0xFF);
        pEccData[3] = ((eccRes >> 8) & 0xFF);
        pEccData[4] = (eccRes & 0xFF);
        eccRes = GPMCECCBCHResultGet(baseAddr, 1, chipSel);
        pEccData[5] = ((eccRes >> 24) & 0xFF);
        pEccData[6] = ((eccRes >> 16) & 0xFF);
        pEccData[7] = ((eccRes >> 8) & 0xFF);
        pEccData[8] = (eccRes & 0xFF);
        eccRes = GPMCECCBCHResultGet(baseAddr, 0, chipSel);
        pEccData[9] = ((eccRes >> 24) & 0xFF);
        pEccData[10] = ((eccRes >> 16) & 0xFF);
        pEccData[11] = ((eccRes >> 8) & 0xFF);
        pEccData[12] = (eccRes & 0xFF);
    }
}

static int32_t NandLibGpmcBchEccCheckAndCorrect(nandLibInfo_t *pNandInfo,
                                                uint8_t *pEccRead,
                                                uint8_t *pData)
{
    int32_t status = NAND_LIB_PASS;
    uint32_t elmBaseAddr = pNandInfo->nandLibCtrlInfo.elmAddr;
    uint32_t intrStatus = 0U;
    uint32_t eccVal = 0U;
    uint32_t i = 0U;
    uint32_t errNum = 0U;
    uint32_t numOfErrs = 0U;
    uint32_t errLoc = 0U;
    uint32_t lastECCBit = 0U;
    uint32_t lastDataBit = 0U;
    uint32_t errBitMask = 0U;
    uint32_t errBytePos = 0U;
    uint32_t numBytes = 0U;
    uint8_t eccCalc[NAND_LIB_ECC_BCH_8BIT_BYTECNT * 4] = {0, 0, 0, 0};
    uint8_t syndrome[NAND_LIB_ECC_BCH_8BIT_BYTECNT * 4];
    uint32_t j = 0U;
    uint32_t result = 0U;

    if(NAND_LIB_ECC_ALGO_BCH_8BIT == pNandInfo->nandLibCtrlInfo.eccAlgo)
    {

        numBytes    = ((NAND_LIB_ECC_BCH_8BIT_BYTECNT) - 1);
        lastECCBit  = NAND_LIB_ECC_BCH_8BIT_LASTECCBIT;
        lastDataBit = NAND_LIB_ECC_BCH_8BIT_LASTDATABIT;
    }

    NandLibGpmcBchEccCalculate(pNandInfo, &eccCalc[0]);

    /*
    ** While reading ECC result we read it in big endian.
    ** Hence while loading to ELM we have rotate to get the right endian.
    */

    /* Rotate the syndrome bytes */
    for (i = 0, j = (numBytes-1); i < numBytes; i++, j--)
          syndrome[i] = eccCalc[j];

    /* Load the BCH syndrome */
    eccVal = (syndrome[0] | (syndrome[1] << 8) | (syndrome[2] << 16) |
              (syndrome[3] << 24));
    ELMSyndromeFrgmtSet(elmBaseAddr, eccVal, 0U, 0U);

    eccVal = (syndrome[4] | (syndrome[5] << 8) | (syndrome[6] << 16) |
              (syndrome[7] << 24));
    ELMSyndromeFrgmtSet(elmBaseAddr, eccVal, 0U, 1U);

    if(pNandInfo->nandLibCtrlInfo.eccAlgo == NAND_LIB_ECC_ALGO_BCH_8BIT)
    {
        eccVal = (syndrome[8] | (syndrome[9] << 8) | (syndrome[10] << 16) |
                 (syndrome[11] << 24));
        ELMSyndromeFrgmtSet(elmBaseAddr, eccVal, 0U, 2U);

        eccVal = (syndrome[12] | (syndrome[13] << 8) | (syndrome[14] << 16) |
                 (syndrome[15] << 24));
        ELMSyndromeFrgmtSet(elmBaseAddr, eccVal, 0U, 3U);
    }

    ELMErrLocProcessingStart(elmBaseAddr, 0);

    while(intrStatus == 0)
    {
        intrStatus = ELMIntStatusGet(elmBaseAddr);
    }

    ELMIntStatusClear(elmBaseAddr, ELM_INTR_MASK_SYNDR_POLY_0);

    result = ELMErrLocProcessingStatusGet(elmBaseAddr, 0);

    if(ELM_ERR_LOC_PROCESS_STS_FAIL == result)
    {
        status = NAND_LIB_ECC_UNCORRECTABLE;
    }
    else
    {
        numOfErrs = ELMNumOfErrsGet(elmBaseAddr, 0);
        if(numOfErrs == 0)
        {
            status = NAND_LIB_PASS;
        }
        else
        {
            errNum = 0U;
             /* Get the error location and correct the same */
            for(i = 0; i < numOfErrs; i++)
            {
                errLoc = ELMErrLocBitAddrGet(elmBaseAddr, 0, errNum);
                if (errLoc >= (lastECCBit - 1))
                {
                   /* Error is at the Data bytes */
                    errBytePos = ((lastDataBit - 1) - errLoc) / 8;
                    /* Error Bit mask */
                    errBitMask = 0x1 << (errLoc % 8);
                    /* Toggle the error bit to make the correction. */
                    pData[errBytePos] ^= errBitMask;
                    status = NAND_LIB_ECC_ERR_CORRECTED;
                }
                else
                {
                    /* Error is at the ECC bytes which we are not handling */
                }
                errNum++;
            }
        }
    }

    return status;
}
