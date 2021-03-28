/*
 * Copyright (c) 2016, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 *
 * \file    evmk2g_nand_gpmc.c
 *
 * \brief   This file contains functions for interfacing NAND device with
 *          GPMC controller.
 *
 ******************************************************************************/

#include "platform_internal.h"

/******************************************************************************
**                      INTERNAL FUNCTION DEFINITIONS
*******************************************************************************/

/**
* \brief This function does the 1-bit hamming code ECC related initialization
*        to the NAND controller.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return
*        NAND_STATUS_PASSED : On success.\n
*        NAND_STATUS_FAILED : On failure.\n
*
*/
static NandStatus_t nandHammingCodeECCInit(NandInfo_t *nandInfo)
{
    Uint32       cs;
    NandStatus_t retVal;
    gpmcHandle   hGpmc;

    retVal = NAND_STATUS_PASSED;
    cs     = nandInfo->hNandCtrlInfo->currChipSelect;
    hGpmc  = nandInfo->hNandCtrlInfo->hGpmc;

    GPMCECCAlgoSelect(hGpmc, GPMC_ECC_ALGORITHM_HAMMINGCODE);
    GPMCECCColumnSelect(hGpmc, GPMC_ECC_COLUMNS_8);
    GPMCECCCSSelect(hGpmc, cs);
    GPMCECCDisable(hGpmc);
    GPMCECCResultRegSelect(hGpmc, GPMC_ECCPOINTER_RESULT_1);
    GPMCECCResultRegClear(hGpmc);
    GPMCECCSizeValSet(hGpmc, GPMC_ECC_SIZE_0, GPMC_ECC_SIZE0_VAL);
    GPMCECCSizeValSet(hGpmc, GPMC_ECC_SIZE_1, GPMC_ECC_SIZE1_VAL);
    GPMCECCResultSizeSelect(hGpmc, GPMC_ECC_RESULT_1, GPMC_ECC_SIZE_0);

    nandInfo->hNandEccInfo->eccOffSet  = nandInfo->pageSize +
                                         NAND_ECC_1BIT_HAMMINGCODE_OOB_OFFSET;
    nandInfo->hNandEccInfo->eccByteCnt = NAND_ECC_1BIT_HAMMINGCODE_BYTECNT;

    return(retVal);
}

/**
* \brief  This Function does the Hamming code ECC related setting for write.\n
*
* \param   nandInfo     : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
static void nandHammingCodeWriteSet(NandInfo_t *nandInfo)
{
    /* No special setting required in Hamming code for write */
}

/**
* \brief  This Function does the Hamming code ECC related setting for Read.\n
*
* \param   nandInfo     : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
static void nandHammingCodeReadSet(NandInfo_t *nandInfo)
{
    /* No special setting required in Hamming code for Read */
}

/**
* \brief This function reads/calculates the 1-bit hamming code ECC values.\n
*
* \param  hGpmc         : Handle to base address of the GPMC controller.\n
*
* \param  eccResReg     : ECC Result register value.\n
*
* \param  ptrEccData    : Pointer where read ECC data has to store.\n
*
* \return none.\n
*
*/
static void nandHammingCodeECCCalculate(gpmcHandle hGpmc, Uint32 eccResReg,
                                        Uint8 *ptrEccData)
{
    Uint32 eccVal;

    eccVal = GPMCECCResultGet(hGpmc, eccResReg);

   /* Squeeze 4 bytes ECC into 3 bytes by removing RESERVED bits
    * and shifting. RESERVED bits are 31 to 28 and 15 to 12. */
    eccVal = (eccVal & 0x00000fff) | ((eccVal & 0x0fff0000) >> 4);
    /* Invert so that erased block ECC is correct */
    eccVal = ~eccVal;

    *ptrEccData++ = (Uint8)eccVal;
    *ptrEccData++ = (Uint8)eccVal >>  8;
    *ptrEccData++ = (Uint8)eccVal >> 16;
}

/**
* \brief This function checks for ECC errors using 1-bit hamming code algorithm
*        and correct if any ECC errors.\n
*
* \param   nandInfo     : Pointer to structure containing controller and
*                         device information.\n
*
* \param   eccRead      : Pointer to the ECC data which is read from the spare
*                         area.\n
*
* \param   data         : Pointer to the data, where if an ecc error need to
*                         correct.\n
*
* \return ECC correction Status.\n
*    NAND_STATUS_PASSED                        : If no ecc errors.\n
*    NAND_STATUS_READ_ECC_ERROR_CORRECTED      : If error are corrected.\n
*    NAND_STATUS_READ_ECC_UNCORRECTABLE_ERROR  : If errors are uncorrectable.\n
*
*/
static NandStatus_t nandHammingCodeECCCheckAndCorrect(NandInfo_t *nandInfo,
                                                      Uint8 *eccRead,
                                                      Uint8 *data)
{
    NandStatus_t retVal;
    Uint32       readEccVal;
    Uint32       calcEccVal;
    Uint32       eccDiffVal;
    Uint32       bitPos;
    Uint32       bytePos;
    Uint8        eccCalc[4];

    retVal = NAND_STATUS_PASSED;

    nandECCCalculate(nandInfo, &eccCalc[0]);

    readEccVal = eccRead[0] | (eccRead[1] << 8) | (eccRead[2] << 16);
    calcEccVal = eccCalc[0] | (eccCalc[1] << 8) | (eccCalc[2] << 16);
    eccDiffVal = readEccVal ^ calcEccVal;

    if(eccDiffVal)
    {
        /*
         * No error              : The ecc diff value (eccDiffVal) is 0.
         * Correctable error     : For 512-byte inputs, ecc diff value has
         *                         12 bits at 1. For 256 byte ecc diff value has
         *                         11 bits at 1.
         * ECC error             : The ecc diff value has only 1 bit at 1.
         * Non-correctable error : The ecc diff value provides all other results
         */

        /*
         * Beow condition checks for number of 1's in eccDiffValu.
         * Since Total ecc has 3bytes = 24 bits. Make 2 halfs and XOR.
         * If eccDiffVal has  12 1's, it produces the result 0xFFF.
        */
        if ((((eccDiffVal >> 12) ^ eccDiffVal) & 0xfff) == 0xfff)
        {
             /* Correctable error */
            /* Check bytePos is within NAND_BYTES_PER_TRNFS i.e 512 */
            if ((eccDiffVal >> (12 + 3)) < NAND_BYTES_PER_TRNFS)
            {
                bitPos  = 1 << ((eccDiffVal >> 12) & 7);
                bytePos = eccDiffVal >> (12 + 3);
                data[bytePos] ^= bitPos;
                retVal = NAND_STATUS_READ_ECC_ERROR_CORRECTED;
            }
            else
            {
                retVal = NAND_STATUS_READ_ECC_UNCORRECTABLE_ERROR;
            }
        }
        else if(!(eccDiffVal & (eccDiffVal - 1)))
        {
            /* Single bit ECC error in the ECC itself,nothing to fix */
            retVal = NAND_STATUS_READ_ECC_ERROR_CORRECTED;
        }
        else
        {
            retVal = NAND_STATUS_READ_ECC_UNCORRECTABLE_ERROR;
        }
    }

    return (retVal);
}

/**
* \brief This function does the BCH ECC related initializes to the NAND
*        controller.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return
*        NAND_STATUS_PASSED          : On success.\n
*        NAND_STATUS_FAILED          : On failure.\n
*        NAND_STATUS_ECC_UNSUPPORTED : If unsupported ECC is used.\n
*
*/
static NandStatus_t nandBCHECCInit(NandInfo_t *nandInfo)
{
    gpmcHandle      hGpmc;
    elmHandle       hElm;
    NandStatus_t    retVal;
    Uint32          cs;
    volatile Uint32 timeOut;

    timeOut = 0xFFF;
    retVal  = NAND_STATUS_PASSED;
    cs      = nandInfo->hNandCtrlInfo->currChipSelect;
    hGpmc   = nandInfo->hNandCtrlInfo->hGpmc;
    hElm    = nandInfo->hNandEccInfo->hElm;

    GPMCECCDisable(hGpmc);
    GPMCECCAlgoSelect(hGpmc, GPMC_ECC_ALGORITHM_BCH);

    if(nandInfo->eccType != NAND_ECC_ALGO_BCH_8BIT)
    {
        retVal = NAND_STATUS_ECC_UNSUPPORTED;
    }
    else
    {
        GPMCECCBCHErrCorrectionCapSelect(hGpmc,
                                         GPMC_ECC_BCH_ERRCORRCAP_UPTO_8BITS);
        GPMCECCColumnSelect(hGpmc, nandInfo->busWidth);
        GPMCECCCSSelect(hGpmc, cs);
        GPMCECCBCHNumOfSectorsSelect(hGpmc, GPMC_ECC_BCH_NUMOFSECTS_1);
        GPMCECCBCHWrapModeValSet(hGpmc, 1);

        GPMCECCResultRegSelect(hGpmc, GPMC_ECCPOINTER_RESULT_1);
        GPMCECCResultRegClear(hGpmc);

        GPMCECCSizeValSet(hGpmc, GPMC_ECC_SIZE_0, GPMC_ECC_SIZE0_VAL);
        GPMCECCSizeValSet(hGpmc, GPMC_ECC_SIZE_1, GPMC_ECC_SIZE1_VAL);
        GPMCECCResultSizeSelect(hGpmc, GPMC_ECC_RESULT_1, GPMC_ECC_SIZE_0);

        /* ELM Module configuration */
        elmModuleReset(hElm);
        while((elmModuleResetStatusGet(hElm) != 1) && (timeOut != 0))
        {
            timeOut--;
        }

        if(timeOut == 0)
        {
            retVal = NAND_STATUS_FAILED;
        }
        else
        {
            elmAutoGatingConfig(hElm, ELM_AUTOGATING_OCP_FREE);
            elmIdleModeSelect(hElm, ELM_IDLEMODE_NOIDLE);
            elmOCPClkActivityConfig(hElm, ELM_CLOCKACTIVITYOCP_OCP_ON);
            elmIntStatusClear(hElm, ELM_LOC_VALID_0_STATUS);
            elmIntConfig(hElm, ELM_LOC_VALID_0_STATUS, ELM_INT_ENALBLE);
            elmErrCorrectionLevelSet(hElm, ELM_ECC_BCH_LEVEL_8BITS);
            elmECCSizeSet(hElm, 0x7FF);
            elmModeSet(hElm, ELM_MODE_PAGE, ELM_PAGEMODE_SECTOR_0);

            nandInfo->hNandEccInfo->eccOffSet  = NAND_ECC_BCH_8BIT_OOB_OFFSET +
                                                 nandInfo->pageSize;
            nandInfo->hNandEccInfo->eccByteCnt = NAND_ECC_BCH_8BIT_BYTECNT;
        }
    }

    return (retVal);
}

/**
* \brief  This Function does the BCH ECC related setting for write.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
static void nandBCHWriteSet(NandInfo_t *nandInfo)
{
    Uint32 size1;
    Uint32 size0;

    size1 = 0;
    size0 = 0;

    if(nandInfo->eccType == NAND_ECC_ALGO_BCH_4BIT)
    {
       /* Not Supported */
    }
    else if(nandInfo->eccType == NAND_ECC_ALGO_BCH_8BIT)
    {
        size1 = (NAND_ECC_BCH_8BIT_BYTECNT * 2);
        size0 = 0;
    }

    GPMCECCSizeValSet(nandInfo->hNandCtrlInfo->hGpmc, GPMC_ECC_SIZE_0, size0);
    GPMCECCSizeValSet(nandInfo->hNandCtrlInfo->hGpmc, GPMC_ECC_SIZE_1, size1);
}

/**
* \brief  This Function does the BCH ECC related setting for read.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
static void nandBCHReadSet(NandInfo_t *nandInfo)
{
    Uint32 size1;
    Uint32 size0;

    size1 = 0;
    size0 = 0;

    if(nandInfo->eccType == NAND_ECC_ALGO_BCH_4BIT)
    {
       /* Not Supported */
    }
    else if(nandInfo->eccType == NAND_ECC_ALGO_BCH_8BIT)
    {
        size0 = ((NAND_ECC_BCH_8BIT_BYTECNT * 2) -
                  NAND_ECC_BCH_8BIT_UNUSED_BYTECNT);
        size1 = NAND_ECC_BCH_8BIT_UNUSED_BYTECNT;
    }

    GPMCECCSizeValSet(nandInfo->hNandCtrlInfo->hGpmc, GPMC_ECC_SIZE_0, size0);
    GPMCECCSizeValSet(nandInfo->hNandCtrlInfo->hGpmc, GPMC_ECC_SIZE_1, size1);
}

/**
* \brief This function reads/calculates the BCH 4-bit andc 8-bit ECC values.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \param  ptrEccData    : Pointer where read ECC data has to store.\n
*
*
* \return none.\n
*
*/
static void nandBCHECCCalculate(NandInfo_t *nandInfo, Uint8 *ptrEccData)
{
	gpmcHandle hGpmc;
    Uint32     eccRes;
    Uint32     eccType;
    Uint32     cs;

    cs      = nandInfo->hNandCtrlInfo->currChipSelect;
    hGpmc   = nandInfo->hNandCtrlInfo->hGpmc;
    eccType = nandInfo->eccType;

    if(eccType == NAND_ECC_ALGO_BCH_4BIT)
    {
       /* Not Supported */
    }
    else if(eccType == NAND_ECC_ALGO_BCH_8BIT)
    {
        eccRes = GPMCECCBCHResultGet(hGpmc, GPMC_BCH_RESULT_3, cs);
        ptrEccData[0] = (eccRes & 0xFF);
        eccRes = GPMCECCBCHResultGet(hGpmc, GPMC_BCH_RESULT_2, cs);
        ptrEccData[1] = ((eccRes >> 24) & 0xFF);
        ptrEccData[2] = ((eccRes >> 16) & 0xFF);
        ptrEccData[3] = ((eccRes >> 8) & 0xFF);
        ptrEccData[4] = (eccRes & 0xFF);
        eccRes = GPMCECCBCHResultGet(hGpmc, GPMC_BCH_RESULT_1, cs);
        ptrEccData[5] = ((eccRes >> 24) & 0xFF);
        ptrEccData[6] = ((eccRes >> 16) & 0xFF);
        ptrEccData[7] = ((eccRes >> 8) & 0xFF);
        ptrEccData[8] = (eccRes & 0xFF);
        eccRes = GPMCECCBCHResultGet(hGpmc, GPMC_BCH_RESULT_0, cs);
        ptrEccData[9] = ((eccRes >> 24) & 0xFF);
        ptrEccData[10] = ((eccRes >> 16) & 0xFF);
        ptrEccData[11] = ((eccRes >> 8) & 0xFF);
        ptrEccData[12] = (eccRes & 0xFF);
    }
}

/**
* \brief This function checks for ECC errors using BCH algorithm and corrects
*        if any ECC errors. \n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \param   eccRead      : Pointer to the ECC data which is read from the spare
*                         area.\n
*
* \param   data         : Pointer to the data, where if an ecc error need to
*                         correct.\n
*
* \return ECC correction Status.\n
*    NAND_STATUS_PASSED                        : If no ecc errors.\n
*    NAND_STATUS_READ_ECC_ERROR_CORRECTED      : If error are corrected.\n
*    NAND_STATUS_READ_ECC_UNCORRECTABLE_ERROR  : If errors are uncorrectable.\n
*
*/
static NandStatus_t nandBCHECCCheckAndCorrect(NandInfo_t *nandInfo,
                                              Uint8 *eccRead,
                                              Uint8 *data)
{
    NandStatus_t retVal;
    elmHandle    hElm;
    Uint32       intStatus;
    Uint32       eccVal;
    Uint32       count;
    Uint32       errNum;
    Uint32       numOfErrs;
    Uint32       errLoc;
    Uint32       lastECCBit;
    Uint32       lastDataBit;
    Uint32       errBitMask;
    Uint32       errBytePos;
    Uint32       numBytes;
    Uint32       index;
    Uint32       result;
    Uint32       cs;
    Uint8        eccCalc[NAND_ECC_BCH_8BIT_BYTECNT * 4];
    Uint8        syndrome[NAND_ECC_BCH_8BIT_BYTECNT * 4];

    retVal    = NAND_STATUS_PASSED;
    hElm      = nandInfo->hNandEccInfo->hElm;
    cs        = nandInfo->hNandCtrlInfo->currChipSelect;
    intStatus = 0;
    index     = 0;
    numBytes  = 0;

    if(nandInfo->eccType == NAND_ECC_ALGO_BCH_4BIT)
    {
       /* Not Supported */
    }
    else if(nandInfo->eccType == NAND_ECC_ALGO_BCH_8BIT)
    {
        numBytes    = ((NAND_ECC_BCH_8BIT_BYTECNT) - 1);
        lastECCBit  = NAND_ECC_BCH_8BIT_LASTECCBIT;
        lastDataBit = NAND_ECC_BCH_8BIT_LASTDATABIT;
    }

    nandECCCalculate(nandInfo, &eccCalc[0]);
    /* while reading ECC result we read it in big endian.
     * Hence while loading to ELM we have rotate to get the right endian.
     */

    /* Rotate the syndrome bytes */
    for (count = 0, index = (numBytes-1); count < numBytes; count++, index--)
    {
        syndrome[count] = eccCalc[index];
	}

    /* Load the BCH syndrome */
    eccVal = (syndrome[0] | (syndrome[1] << 8) | (syndrome[2] << 16) |
              (syndrome[3] << 24));
    elmSyndromeFrgmtSet(hElm, ELM_SYNDROME_FRGMT_0, eccVal, cs);

    eccVal = (syndrome[4] | (syndrome[5] << 8) | (syndrome[6] << 16) |
              (syndrome[7] << 24));
    elmSyndromeFrgmtSet(hElm, ELM_SYNDROME_FRGMT_1, eccVal, cs);

    if(nandInfo->eccType == NAND_ECC_ALGO_BCH_8BIT)
    {
        eccVal = (syndrome[8] | (syndrome[9] << 8) | (syndrome[10] << 16) |
                 (syndrome[11] << 24));
        elmSyndromeFrgmtSet(hElm, ELM_SYNDROME_FRGMT_2, eccVal, cs);

        eccVal = (syndrome[12] | (syndrome[13] << 8) | (syndrome[14] << 16) |
                 (syndrome[15] << 24));
        elmSyndromeFrgmtSet(hElm, ELM_SYNDROME_FRGMT_3, eccVal, cs);
    }

    elmErrLocProcessingStart(hElm, cs);

    while(intStatus == 0)
    {
        intStatus = elmIntStatusGet(hElm, ELM_LOC_VALID_0_STATUS);
    }

    elmIntStatusClear(hElm, ELM_LOC_VALID_0_STATUS);

    result = elmErrLocProcessingStatusGet(hElm, cs);

    if(result == 0)
    {
        retVal = NAND_STATUS_READ_ECC_UNCORRECTABLE_ERROR;
    }
    else
    {
        numOfErrs = elmNumOfErrsGet(hElm, cs);
        if(numOfErrs == 0)
        {
            retVal = NAND_STATUS_PASSED;
        }
        else
        {
            errNum = ELM_ERROR_NUM_0;
             /* Get the error location and correct the same */
            for(count=0; count < numOfErrs; count++)
            {
                errLoc = elmErrLocBitAddrGet(hElm, errNum, cs);
                if (errLoc >= (lastECCBit - 1))
                {
                   /* Error is at the Data bytes */
                    errBytePos = ((lastDataBit - 1) - errLoc) / 8;
                    /* Error Bit mask */
                    errBitMask = 0x1 << (errLoc % 8);
                    /* Toggle the error bit to make the correction. */
                    data[errBytePos] ^= errBitMask;
                    retVal = NAND_STATUS_READ_ECC_ERROR_CORRECTED;
                }
                else
                {
                    /* Error is at the ECC bytes which we are not handling */
                }

                errNum++;
            }
        }
    }

    return (retVal);
}


/******************************************************************************
**                       GLOBAL FUNCTION DEFINITIONS
*******************************************************************************/

/**
* \brief  Function to get the wait pin status.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return Wait pin status.\n
*
*         0 : If the status is active low.\n
*         1 : If the status is active high.\n
*
*/
Uint32 nandWaitPinStatusGet(NandInfo_t *nandInfo)
{
    Uint32 pinStatus;

    pinStatus = GPMCWaitPinStatusGet(nandInfo->hNandCtrlInfo->hGpmc,
                                     nandInfo->hNandCtrlInfo->waitPin);
    return(pinStatus);
}

/**
* \brief  Function to get the GPMC FIFO status.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return GPMC FIFO buffer status.\n
*
*         0 : If the FIFO is full.\n
*         1 : If the FIFO is empty and ready to accept data.\n
*
*/
Uint32 nandWriteBufReady(NandInfo_t *nandInfo)
{
    Uint32 status;

    status = GPMCEmptyWriteBuffStatusGet(nandInfo->hNandCtrlInfo->hGpmc);

    return(status);
}

/**
* \brief  Function to initialize the NAND controller.\n
*
* \param  nandCtrlInfo  : Pointer to structure containing controller info.\n
*
* \return
*
*        NAND_STATUS_PASSED          : On success.\n
*        NAND_STATUS_FAILED          : On failure.\n
*
*/
NandStatus_t nandCtrlInit(NandInfo_t *nandInfo)
{
    Uint32           conf;
    Uint32           cs;
    volatile Uint32  timeOut;
    NandTimingInfo_t *nandTimingInfo;
    gpmcHandle       hGpmc;

    cs = nandInfo->hNandCtrlInfo->currChipSelect;
    nandTimingInfo = (NandTimingInfo_t *) nandInfo->hNandCtrlInfo->hNandTimingInfo;

    conf     = 0;
    timeOut  = 0xFFF;
    hGpmc = nandInfo->hNandCtrlInfo->hGpmc;

    /* GPMC Module configuration */
    GPMCModuleSoftReset(hGpmc);
    while((GPMCModuleResetStatusGet(hGpmc) != 1) && (timeOut != 0))
    {
        timeOut--;
    }

    if(timeOut == 0)
    {
        return (NAND_STATUS_FAILED);
    }

    GPMCIdleModeSelect(hGpmc, GPMC_IDLEMODE_NOIDLE);

    /* Disable all interrupts */
    GPMCIntDisable(hGpmc, GPMC_FIFOEVENT_INT);
    GPMCIntDisable(hGpmc, GPMC_TERMINALCOUNT_INT);
    GPMCIntDisable(hGpmc, GPMC_WAIT0EDGEDETECTION_INT);
    GPMCIntDisable(hGpmc, GPMC_WAIT1EDGEDETECTION_INT);

    /* Timeout control disable */
    GPMCTimeOutFeatureConfig(hGpmc, GPMC_TIMEOUTFEATURE_DISABLE);

    /* Set the wait pin polarity */
    GPMCWaitPinSelect(hGpmc, cs, nandInfo->hNandCtrlInfo->waitPin);
    GPMCWaitPinPolaritySelect(hGpmc, nandInfo->hNandCtrlInfo->waitPin,
                              nandInfo->hNandCtrlInfo->waitPinPol);
    GPMCWriteProtectPinLevelCtrl(hGpmc, nandInfo->hNandCtrlInfo->wpPinPol);
    GPMCLimitedAddrDevSupportConfig(hGpmc,
                                    GPMC_LIMITEDADDRESS_SUPPORT_ENABLE);

    GPMCCSConfig(hGpmc, cs, GPMC_CS_DISABLE);
    //GPMCTimeParaGranularitySelect(hGpmc, cs, GPMC_TIMEPARAGRANULARITY_X2);
    GPMCDevTypeSelect(hGpmc, cs, GPMC_DEVICETYPE_NANDLIKE);
    if(nandInfo->busWidth == NAND_BUSWIDTH_8BIT)
    {
        GPMCDevSizeSelect(hGpmc, cs, GPMC_DEVICESIZE_8BITS);
    }
    else
    {
        GPMCDevSizeSelect(hGpmc, cs, GPMC_DEVICESIZE_16BITS);
    }
    GPMCAddrDataMuxProtocolSelect(hGpmc, cs, GPMC_MUXADDDATA_NOMUX);

    GPMCWriteTypeSelect(hGpmc, cs, GPMC_WRITETYPE_ASYNC);
    GPMCReadTypeSelect(hGpmc, cs, GPMC_READTYPE_ASYNC);
    GPMCAccessTypeSelect(hGpmc, cs, GPMC_MODE_WRITE, GPMC_ACCESSTYPE_SINGLE);
    GPMCAccessTypeSelect(hGpmc, cs, GPMC_MODE_READ, GPMC_ACCESSTYPE_SINGLE);

    GPMCBaseAddrSet(hGpmc, cs, (nandInfo->hNandCtrlInfo->chipSelectBaseAddr[cs]) >>
                                   NAND_BASE_ADDR_SHIFT);
    GPMCMaskAddrSet(hGpmc, cs, (nandInfo->hNandCtrlInfo->chipSelectRegionSize[cs]));

    conf = GPMC_CS_TIMING_CONFIG(nandTimingInfo->CSWrOffTime,
                                 nandTimingInfo->CSRdOffTime,
                                 nandTimingInfo->CSExtDelayFlag,
                                 nandTimingInfo->CSOnTime);
    GPMCCSTimingConfig(hGpmc, cs, conf);

    conf = GPMC_ADV_TIMING_CONFIG(nandTimingInfo->ADVAADMuxWrOffTime,
                                  nandTimingInfo->ADVAADMuxRdOffTime,
                                  nandTimingInfo->ADVWrOffTime,
                                  nandTimingInfo->ADVRdOffTime,
                                  nandTimingInfo->ADVExtDelayFlag,
                                  nandTimingInfo->ADVAADMuxOnTime,
                                  nandTimingInfo->ADVOnTime);
    GPMCADVTimingConfig(hGpmc, cs, conf);

    conf = GPMC_WE_OE_TIMING_CONFIG(nandTimingInfo->WEOffTime,
                                    nandTimingInfo->WEExtDelayFlag,
                                    nandTimingInfo->WEOnTime,
                                    nandTimingInfo->OEAADMuxOffTime,
                                    nandTimingInfo->OEOffTime,
                                    nandTimingInfo->OEExtDelayFlag,
                                    nandTimingInfo->OEAADMuxOnTime,
                                    nandTimingInfo->OEOnTime);
    GPMCWEAndOETimingConfig(hGpmc, cs, conf);

    conf = GPMC_RDACCESS_CYCLETIME_TIMING_CONFIG(
                                   nandTimingInfo->rdCycleTime,
                                   nandTimingInfo->wrCycleTime,
                                   nandTimingInfo->rdAccessTime,
                                   nandTimingInfo->pageBurstAccessTime);
    GPMCRdAccessAndCycleTimeTimingConfig(hGpmc, cs, conf);

    conf = GPMC_CYCLE2CYCLE_BUSTURNAROUND_TIMING_CONFIG(
                                  nandTimingInfo->cycle2CycleDelay,
                                  nandTimingInfo->cycle2CycleDelaySameCSCfg,
                                  nandTimingInfo->cycle2CycleDelayDiffCSCfg,
                                  nandTimingInfo->busTAtime);
    GPMCycle2CycleAndTurnArndTimeTimingConfig(hGpmc, cs, conf);

    GPMCWrAccessAndWrDataOnADMUXBusTimingConfig(hGpmc, cs,
                                                nandTimingInfo->wrAccessTime,
                                                nandTimingInfo->wrDataOnADMux);
    GPMCCSConfig(hGpmc, cs, GPMC_CS_ENABLE);

    return(NAND_STATUS_PASSED);
}

/**
* \brief This function does the ECC related initializes to the NAND controller
*        depending on the ecc type.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return
*        NAND_STATUS_PASSED : On success.\n
*        NAND_STATUS_FAILED : On failure.\n
*
*/
NandStatus_t nandECCInit(NandInfo_t *nandInfo)
{
    NandStatus_t retVal;

    retVal = NAND_STATUS_PASSED;

    if(nandInfo->eccType == NAND_ECC_ALGO_HAMMING_1BIT)
    {
        retVal = nandHammingCodeECCInit(nandInfo);
    }
    else if(nandInfo->eccType == NAND_ECC_ALGO_BCH_4BIT ||
            nandInfo->eccType == NAND_ECC_ALGO_BCH_8BIT)
    {
        retVal = nandBCHECCInit(nandInfo);
    }

    return(retVal);
}

/**
* \brief This function enables the ECC.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
void nandECCEnable(NandInfo_t *nandInfo)
{
    gpmcHandle hGpmc = nandInfo->hNandCtrlInfo->hGpmc;

    GPMCECCResultRegClear(hGpmc);
    GPMCECCEnable(hGpmc);
}

/**
* \brief This function disables the ECC.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
void nandECCDisable(NandInfo_t *nandInfo)
{
    gpmcHandle hGpmc = nandInfo->hNandCtrlInfo->hGpmc;

    GPMCECCDisable(hGpmc);
}

/**
* \brief  This Function does the ECC setting for write.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
void nandECCWriteSet(NandInfo_t *nandInfo)
{
    if(nandInfo->eccType == NAND_ECC_ALGO_HAMMING_1BIT)
    {
        nandHammingCodeWriteSet(nandInfo);
    }
    else
    {
        nandBCHWriteSet(nandInfo);
    }
}

/**
* \brief  This Function does the ECC setting for read.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
void nandECCReadSet(NandInfo_t *nandInfo)
{
    if(nandInfo->eccType == NAND_ECC_ALGO_HAMMING_1BIT)
    {
        nandHammingCodeReadSet(nandInfo);
    }
    else
    {
        nandBCHReadSet(nandInfo);
    }
}

/**
* \brief This function reads the ecc data.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \param  ptrEccData    : Pointer where read ECC data has to store.\n
*
* \return none.\n
*
*/
void nandECCCalculate(NandInfo_t *nandInfo, Uint8 *ptrEccData)
{
    if(nandInfo->eccType == NAND_ECC_ALGO_HAMMING_1BIT)
    {
        nandHammingCodeECCCalculate(nandInfo->hNandCtrlInfo->hGpmc,
                                    GPMC_ECC_RESULT_1, ptrEccData);
    }
    else if(nandInfo->eccType == NAND_ECC_ALGO_BCH_4BIT ||
            nandInfo->eccType == NAND_ECC_ALGO_BCH_8BIT)
    {
        nandBCHECCCalculate(nandInfo, ptrEccData);
    }
}

/**
* \brief This function checks and corrects ECC errors.\n
*
* \param   nandInfo     : Pointer to structure containing controller and
*                         device information.\n
*
* \param   eccRead      : Pointer to the ECC data which is read from the spare
*                         area.\n
*
* \param   data         : Pointer to the data, where if an ecc error need to
*                         correct.\n
*
* \return ECC correction Status.\n
*    NAND_STATUS_PASSED                        : If no ecc errors.\n
*    NAND_STATUS_READ_ECC_ERROR_CORRECTED      : If error are corrected.\n
*    NAND_STATUS_READ_ECC_UNCORRECTABLE_ERROR  : If errors are uncorrectable.\n
*
*/
NandStatus_t nandECCCheckAndCorrect(NandInfo_t *nandInfo,
                                    Uint8 *eccRead,
                                    Uint8 *data)
{
    NandStatus_t retVal;

    retVal = NAND_STATUS_PASSED;

    if(nandInfo->eccType == NAND_ECC_ALGO_HAMMING_1BIT)
    {
        retVal = nandHammingCodeECCCheckAndCorrect(nandInfo, eccRead, data);
    }
    else if(nandInfo->eccType == NAND_ECC_ALGO_BCH_4BIT ||
            nandInfo->eccType == NAND_ECC_ALGO_BCH_8BIT)

    {
        retVal = nandBCHECCCheckAndCorrect(nandInfo, eccRead, data);
    }

    return(retVal);
}

/******************************************************************************
**                              END OF FILE
*******************************************************************************/
