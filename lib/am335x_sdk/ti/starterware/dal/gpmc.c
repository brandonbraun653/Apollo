/**
 * \file   gpmc.c
 *
 * \brief  This file contains the Device Abstraction Layer(DAL) APIs
 *         for GPMC module. These APIs are used for initialization and
 *         configuration to interface with the attached device.
 */

/**
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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
#include "hw_types.h"
#include "hw_gpmc.h"
#include "gpmc.h"


/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* ========================================================================== */
/*                           Function Definitions                             */
/* ========================================================================== */


uint32_t GPMCGetRevision(uint32_t baseAddr)
{
    return (HW_RD_FIELD32(baseAddr + GPMC_REVISION, GPMC_REVISION_REV));
}

void GPMCModuleReset(uint32_t baseAddr)
{
    /* Initiate the module reset for GPMC. */
    HW_WR_FIELD32(baseAddr + GPMC_SYSCONFIG, GPMC_SYSCONFIG_SOFTRESET,
        GPMC_SYSCONFIG_SOFTRESET_RESET);
}

uint32_t GPMCIsModuleResetDone(uint32_t baseAddr)
{
    uint32_t status = FALSE;

    if(GPMC_SYSSTATUS_RESETDONE_RSTDONE ==
        HW_RD_FIELD32(baseAddr + GPMC_SYSSTATUS, GPMC_SYSSTATUS_RESETDONE))
    {
        status = TRUE;
    }

    return status;
}

void GPMCSetAddrDataMuxType(uint32_t baseAddr, uint32_t csNum, uint32_t muxType)
{
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_MUXADDDATA,
        muxType);
}

void GPMCSetDevType(uint32_t baseAddr, uint32_t csNum, uint32_t devType)
{
    /* Selects the attached device type for the chip select number. */
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_DEVICETYPE,
        devType);
}

void GPMCSetDevSize(uint32_t baseAddr, uint32_t csNum, uint32_t devSize)
{
    /* Sets the device size attached for the chip select number. */
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_DEVICESIZE,
        devSize);
}

void GPMCSetDevPageLength(uint32_t baseAddr, uint32_t csNum, uint32_t pageLen)
{
    /*
    ** Sets the attached device page(burst) length for the chip select number.
    */
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum),
        GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH, pageLen);
}

void GPMCSetAccessMode(uint32_t baseAddr,
                       uint32_t csNum,
                       uint32_t operMode,
                       uint32_t accessMode)
{
    if(GPMC_OPER_MODE_READ == operMode)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_READMULTIPLE,
            accessMode);
    }
    else if(GPMC_OPER_MODE_WRITE == operMode)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum),
            GPMC_CONFIG1_WRITEMULTIPLE, accessMode);
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

void GPMCSetAccessType(uint32_t baseAddr,
                       uint32_t csNum,
                       uint32_t accessType)
{
    if(accessType == GPMC_ACCESS_TYPE_SYNC_READ)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_READTYPE,
            GPMC_CONFIG1_READTYPE_RDSYNC);
    }
    else if(accessType == GPMC_ACCESS_TYPE_SYNC_WRITE)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_WRITETYPE,
            GPMC_CONFIG1_WRITETYPE_WRSYNC);
    }
    else if(accessType == GPMC_ACCESS_TYPE_ASYNC_READ)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_READTYPE,
            GPMC_CONFIG1_READTYPE_RDASYNC);
    }
    else if(accessType == GPMC_ACCESS_TYPE_ASYNC_WRITE)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_WRITETYPE,
            GPMC_CONFIG1_WRITETYPE_WRASYNC);
    }
    else
    {
        /*
        ** It is expected of application to pass proper value as
        ** this function doesn't return error.
        */
    }
}

void GPMCSyncWrapBurstEnable(uint32_t baseAddr,
                             uint32_t csNum,
                             uint32_t enableWrapBurst)
{
    if(TRUE == enableWrapBurst)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_WRAPBURST,
            GPMC_CONFIG1_WRAPBURST_WRAPSUPP);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_WRAPBURST,
            GPMC_CONFIG1_WRAPBURST_WRAPNOTSUPP);
    }
}

void GPMCSetChipSelBaseAddr(uint32_t baseAddr, uint32_t csNum, uint32_t addr)
{
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG7(csNum), GPMC_CONFIG7_BASEADDRESS,
        addr);
}

void GPMCSetChipSelMaskAddr(uint32_t baseAddr,
                            uint32_t csNum,
                            uint32_t maskAddr)
{
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG7(csNum), GPMC_CONFIG7_MASKADDRESS,
        maskAddr);
}

void GPMCChipSelEnable(uint32_t baseAddr,
                       uint32_t csNum,
                       uint32_t enableChipSelect)
{
    if(TRUE == enableChipSelect)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG7(csNum), GPMC_CONFIG7_CSVALID,
            GPMC_CONFIG7_CSVALID_CSENABLED);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG7(csNum), GPMC_CONFIG7_CSVALID,
            GPMC_CONFIG7_CSVALID_CSDISABLED);
    }
}

void GPMCSetFclkDivider(uint32_t baseAddr, uint32_t csNum, uint32_t dividerVal)
{
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_GPMCFCLKDIVIDER,
        dividerVal);
}

void GPMCSetTimeParaGranularity(uint32_t baseAddr,
                                uint32_t csNum,
                                uint32_t scaleFactor)
{
    /* Set the time para granularity factor. */
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum),
        GPMC_CONFIG1_TIMEPARAGRANULARITY, scaleFactor);
}

void GPMCSetClkActivationTime(uint32_t baseAddr,
                              uint32_t csNum,
                              uint32_t clkActTime)
{
    /* Sets the GPMC Clock Activation time. */
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum),
        GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH, clkActTime);
}

void GPMCChipSelectTimingConfig(uint32_t baseAddr,
                                uint32_t csNum,
                                gpmcChipSelTimingParams_t *pTimingParams)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + GPMC_CONFIG2(csNum));

    /* Set the Chip Select ON Time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG2_CSONTIME, pTimingParams->chipSelOnTime);

    /* Set the Chip Select Read Off time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG2_CSRDOFFTIME,
        pTimingParams->chipSelRdOffTime);

    /* Set the Chip Select Write Off time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG2_CSWROFFTIME,
        pTimingParams->chipSelWrOffTime);

    /*
    ** Configures the extra half GPMC clock cycle delay based on the user
    ** parameter.
    */
    if(TRUE == pTimingParams->addExtDelay)
    {
        HW_SET_FIELD(regVal, GPMC_CONFIG2_CSEXTRADELAY,
            GPMC_CONFIG2_CSEXTRADELAY_DELAYED);
    }
    else
    {
        HW_SET_FIELD(regVal, GPMC_CONFIG2_CSEXTRADELAY,
            GPMC_CONFIG2_CSEXTRADELAY_NOTDELAYED);
    }

    /* Write the final to configure the Chip Select timing parameters. */
    HW_WR_REG32(baseAddr + GPMC_CONFIG2(csNum), regVal);
}

void GPMCAdvSignalTimingConfig(uint32_t baseAddr,
                               uint32_t csNum,
                               gpmcAdvSignalTimingParams_t *pTimingParams)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + GPMC_CONFIG3(csNum));

    /* Set the ADV assertion time from start cycle time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG3_ADVONTIME, pTimingParams->advOnTime);

    /*
    ** Set the assertion for first address phase when using the AAD-multiplexed
    ** protocol.
    */
    HW_SET_FIELD(regVal, GPMC_CONFIG3_ADVAADMUXONTIME,
        pTimingParams->advAadMuxOnTime);

    /*
    ** ADV de-assertion for first address phase when using the AAD-Mux protocol.
    */
    HW_SET_FIELD(regVal, GPMC_CONFIG3_ADVAADMUXWROFFTIME,
        pTimingParams->advAadMuxWrOffTime);

    /* ADV assertion for first address phase when using the AAD-Mux protocol. */
    HW_SET_FIELD(regVal, GPMC_CONFIG3_ADVAADMUXRDOFFTIME,
        pTimingParams->advAadMuxRdOffTime);

    /* Set the ADV Write Off time in terms of GPMC Clock cycles. */
    HW_SET_FIELD(regVal, GPMC_CONFIG3_ADVWROFFTIME,
        pTimingParams->advWrOffTime);

    /* Set the ADV Read Off time in terms of GPMC Clock cycles. */
    HW_SET_FIELD(regVal, GPMC_CONFIG3_ADVRDOFFTIME,
        pTimingParams->advRdOffTime);

    /*
    ** Configures the extra half GPMC clock cycle delay to ADV signal based on
    ** the user passed parameter.
    */
    if( TRUE == pTimingParams->addExtDelay)
    {
        HW_SET_FIELD(regVal, GPMC_CONFIG3_ADVEXTRADELAY,
            GPMC_CONFIG3_ADVEXTRADELAY_DELAYED);
    }
    else
    {
        HW_SET_FIELD(regVal, GPMC_CONFIG3_ADVEXTRADELAY,
            GPMC_CONFIG3_ADVEXTRADELAY_NOTDELAYED);
    }

    /* Write the final to configure the ADV signal timing parameters. */
    HW_WR_REG32(baseAddr + GPMC_CONFIG3(csNum), regVal);
}

void GPMCWeOeSignalTimingConfig(uint32_t baseAddr,
                                uint32_t csNum,
                                gpmcOeWeSignalTimingParams_t *pTimingParams)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + GPMC_CONFIG4(csNum));

    /* Sets the Write Enable Signal de-assertion time from start cycle time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG4_WEOFFTIME,
        pTimingParams->writeEnableOffTime);

    /* Sets the Write Enable Signal assertion time from start cycle time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG4_WEONTIME,
        pTimingParams->writeEnableOnTime);

    /*
    ** Configures the extra half GPMC clock cycle delay to WE signal based on
    ** the user passed parameter.
    */
    if(TRUE == pTimingParams->addExtDelay)
    {
        HW_SET_FIELD(regVal, GPMC_CONFIG4_WEEXTRADELAY,
            GPMC_CONFIG4_WEEXTRADELAY_DELAYED);
    }
    else
    {
        HW_SET_FIELD(regVal, GPMC_CONFIG4_WEEXTRADELAY,
            GPMC_CONFIG4_WEEXTRADELAY_NOTDELAYED);
    }

    /*
    ** Sets the Output Enable de-assertion time for the first address phase in
    ** an AAD-Multiplexed access
    */
    HW_SET_FIELD(regVal, GPMC_CONFIG4_OEAADMUXOFFTIME,
        pTimingParams->oeAadMuxOffTime);

    /*
    ** Sets the Output Enable assertion time for the first address phase in an
    ** AAD-Multiplexed access
    */
    HW_SET_FIELD(regVal, GPMC_CONFIG4_OEAADMUXONTIME,
        pTimingParams->oeAadMuxOnTime);

    /* Sets the Output Enable Off time from start cycle time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG4_OEOFFTIME, pTimingParams->oeOffTime);

    /* Sets the Output Enable On time from start cycle time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG4_OEONTIME,
        pTimingParams->oeOnTime);

    /* Write the new Write Enable/Output Enable signal timing value. */
    HW_WR_REG32(baseAddr + GPMC_CONFIG4(csNum), regVal);
}

void GPMCReadAccessTimingConfig(uint32_t baseAddr,
                                uint32_t csNum,
                                gpmcReadAccessTime_t *pTimingParams)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + GPMC_CONFIG5(csNum));

    /* Sets the total Read Cycle time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG5_RDCYCLETIME,
        pTimingParams->readCycleTime);

    /* Sets the total Write Cycle time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG5_WRCYCLETIME,
        pTimingParams->writeCycleTime);

    /* Set the Read Access time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG5_RDACCESSTIME,
        pTimingParams->readAccessTime);

    /* Set the Page Burst Access Time. */
    HW_SET_FIELD(regVal, GPMC_CONFIG5_PAGEBURSTACCESSTIME,
        pTimingParams->pageBurstAccessTime);

    /* Write the new Read Access timings. */
    HW_WR_REG32(baseAddr + GPMC_CONFIG5(csNum), regVal);
}

void GPMCWriteAccessTimingConfig(uint32_t baseAddr,
                                 uint32_t csNum,
                                 uint32_t wrAccessTime,
                                 uint32_t wrDataOnAdMuxBus)
{
    /* Set the Write Access Time. */
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG6(csNum), GPMC_CONFIG6_WRACCESSTIME,
        wrAccessTime);

    HW_WR_FIELD32(baseAddr + GPMC_CONFIG6(csNum), GPMC_CONFIG6_WRDATAONADMUXBUS,
        wrDataOnAdMuxBus);
}

void GPMCCycleDelayTimingConfig(uint32_t baseAddr,
                                uint32_t csNum,
                                gpmcCycle2CycleDelay_t *pTimingParams)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + GPMC_CONFIG6(csNum));

    /* Set the Cycle to Cycle delay. */
    HW_SET_FIELD(regVal, GPMC_CONFIG6_CYCLE2CYCLEDELAY,
        pTimingParams->cycle2CycleDelay);

    HW_SET_FIELD(regVal, GPMC_CONFIG6_CYCLE2CYCLESAMECSEN,
        pTimingParams->cycleDelaySameChipSel);

    HW_SET_FIELD(regVal, GPMC_CONFIG6_CYCLE2CYCLEDIFFCSEN,
        pTimingParams->cycleDelayDiffChipSel);

    HW_SET_FIELD(regVal, GPMC_CONFIG6_BUSTURNAROUND,
        pTimingParams->busTurnAroundTime);

    HW_WR_REG32(baseAddr + GPMC_CONFIG6(csNum), regVal);
}

void GPMCNandCmdWrite(uint32_t baseAddr, uint32_t csNum, uint32_t command)
{
    HW_WR_REG32(baseAddr + GPMC_NAND_COMMAND(csNum), command);
}

void GPMCNandAddrWrite(uint32_t baseAddr, uint32_t csNum, uint32_t addr)
{
    HW_WR_REG32(baseAddr + GPMC_NAND_ADDRESS(csNum), addr);
}

void GPMCNandDataWrite(uint32_t baseAddr, uint32_t csNum, uint32_t data)
{
    HW_WR_REG32(baseAddr + GPMC_NAND_DATA(csNum), data);
}

uint32_t GPMCNandDataRead(uint32_t baseAddr, uint32_t csNum)
{
    uint32_t data = 0U;

    data = HW_RD_REG32(baseAddr + GPMC_NAND_DATA(csNum));

    return data;
}

void GPMCLimitedAddrSupportEnable(uint32_t baseAddr,
                                  uint32_t enableLimitAddrSupp)
{
    if(TRUE == enableLimitAddrSupp)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG, GPMC_CONFIG_LIMITEDADDRESS,
            GPMC_CONFIG_LIMITEDADDRESS_LIMITED);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG, GPMC_CONFIG_LIMITEDADDRESS,
            GPMC_CONFIG_LIMITEDADDRESS_NOLIMITED);
    }
}

void GPMCNandForcePostedWriteEnable(uint32_t baseAddr,
                                    uint32_t enableForcePostedWrite)
{
    if(TRUE == enableForcePostedWrite)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG, GPMC_CONFIG_NANDFORCEPOSTEDWRITE,
            GPMC_CONFIG_NANDFORCEPOSTEDWRITE_FORCEPWR);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG, GPMC_CONFIG_NANDFORCEPOSTEDWRITE,
            GPMC_CONFIG_NANDFORCEPOSTEDWRITE_NOFORCEPWR);
    }
}

void GPMCWaitPinSelect(uint32_t baseAddr, uint32_t csNum, uint32_t waitPinNum)
{
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum), GPMC_CONFIG1_WAITPINSELECT,
        waitPinNum);
}

void GPMCSetWaitPinPol(uint32_t baseAddr, uint32_t waitPin, uint32_t polarity)
{
    if(GPMC_WAIT_PIN_NUM_0 == waitPin)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG, GPMC_CONFIG_WAIT0PINPOLARITY,
            polarity);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG, GPMC_CONFIG_WAIT1PINPOLARITY,
            polarity);
    }
}

uint32_t GPMCWaitPinStatus(uint32_t baseAddr, uint32_t waitPin)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + GPMC_STATUS);
    uint32_t status = GPMC_WAIT_PIN_STS_DE_ASSERTED;

    /* Return the status of the Wait Pin passed. */
    if(GPMC_WAIT_PIN_NUM_0 == waitPin)
    {
        if(GPMC_STATUS_WAIT0STATUS_W0ASSERTED ==
            (regVal & GPMC_STATUS_WAIT0STATUS_MASK))
        {
            status = GPMC_WAIT_PIN_STS_ASSERTED;
        }
    }
    else
    {
        if(GPMC_STATUS_WAIT1STATUS_W1ASSERTED ==
            (regVal & GPMC_STATUS_WAIT1STATUS_MASK))
        {
            status = GPMC_WAIT_PIN_STS_ASSERTED;
        }
    }

    return status;
}

void GPMCWaitPinMonitoringEnable(uint32_t baseAddr,
                                 uint32_t csNum,
                                 uint32_t operMode,
                                 uint32_t waitPinMonitor)
{
    if(GPMC_OPER_MODE_READ == operMode)
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum),
            GPMC_CONFIG1_WAITREADMONITORING, waitPinMonitor);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum),
            GPMC_CONFIG1_WAITWRITEMONITORING, waitPinMonitor);
    }
}

void GPMCSetWaitPinMonitoringTime(uint32_t baseAddr,
                                  uint32_t csNum,
                                  uint32_t waitPinTime)
{
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG1(csNum),
        GPMC_CONFIG1_WAITMONITORINGTIME, waitPinTime);
}

void GPMCSetWriteProtectPinLvl(uint32_t baseAddr, uint32_t pinLevel)
{
    HW_WR_FIELD32(baseAddr + GPMC_CONFIG, GPMC_CONFIG_WRITEPROTECT, pinLevel);
}

uint32_t GPMCIsWriteBufEmpty(uint32_t baseAddr)
{
    uint32_t status = FALSE;

    if(GPMC_STATUS_EMPTYWRITEBUFFERSTATUS_EMPTY ==
        HW_RD_FIELD32(baseAddr + GPMC_STATUS,
        GPMC_STATUS_EMPTYWRITEBUFFERSTATUS))
    {
        status = TRUE;
    }

    return status;
}

void GPMCIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + GPMC_IRQENABLE);
    regVal |= intrMask;
    HW_WR_REG32(baseAddr + GPMC_IRQENABLE, intrMask);
}

void GPMCIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + GPMC_IRQENABLE);
    regVal &= ~intrMask;
    HW_WR_REG32(baseAddr + GPMC_IRQENABLE, regVal);
}

uint32_t GPMCIntrStatus(uint32_t baseAddr)
{
    uint32_t status = 0U;

    status =  HW_RD_REG32(baseAddr + GPMC_IRQSTATUS);

    return status;
}

void GPMCIntrClear(uint32_t baseAddr, uint32_t intrMask)
{
    HW_WR_REG32(baseAddr + GPMC_IRQSTATUS, intrMask);
}

void GPMCTimeoutEnable(uint32_t baseAddr, uint32_t enableTimeout)
{
    if(TRUE == enableTimeout)
    {
        HW_WR_FIELD32(baseAddr + GPMC_TIMEOUT_CONTROL,
            GPMC_TIMEOUT_CONTROL_TIMEOUTENABLE,
            GPMC_TIMEOUT_CONTROL_TIMEOUTENABLE_TOENABLED);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_TIMEOUT_CONTROL,
            GPMC_TIMEOUT_CONTROL_TIMEOUTENABLE,
            GPMC_TIMEOUT_CONTROL_TIMEOUTENABLE_TODISABLED);
    }
}

void GPMCSetTimeoutVal(uint32_t baseAddr, uint32_t timeoutVal)
{
    HW_WR_FIELD32(baseAddr + GPMC_TIMEOUT_CONTROL,
        GPMC_TIMEOUT_CONTROL_TIMEOUTSTARTVALUE, timeoutVal);
}

uint32_t GPMCGetErrAddr(uint32_t baseAddr)
{
    uint32_t errAddr = 0U;

    errAddr = HW_RD_REG32(baseAddr + GPMC_ERR_ADDRESS);

    return errAddr;
}

uint32_t GPMCGetErrSysCmd(uint32_t baseAddr)
{
    uint32_t sysCmd = 0U;

    sysCmd = HW_RD_FIELD32(baseAddr + GPMC_ERR_TYPE, GPMC_ERR_TYPE_ILLEGALMCMD);

    return sysCmd;
}

uint32_t GPMCIsErrValid(uint32_t baseAddr)
{
    uint32_t status = FALSE;

    if(GPMC_ERR_TYPE_ERRORVALID_ERRDETECT ==
        HW_RD_FIELD32(baseAddr + GPMC_ERR_TYPE, GPMC_ERR_TYPE_ERRORVALID))
    {
        status = TRUE;
    }

    return status;
}

uint32_t GPMCErrStatus(uint32_t baseAddr)
{
    uint32_t status = 0U;

    status = HW_RD_REG32(baseAddr + GPMC_ERR_TYPE);

    return status;
}

void GPMCSetPrefetchAccessMode(uint32_t baseAddr, uint32_t accessMode)
{
    HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
        GPMC_PREFETCH_CONFIG1_ACCESSMODE, accessMode);
}

void GPMCSetPrefetchChipSel(uint32_t baseAddr, uint32_t prefetchCSNum)
{
    HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
        GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR, prefetchCSNum);
}

void GPMCSetPrefetchSyncType(uint32_t baseAddr, uint32_t syncType)
{
    HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
        GPMC_PREFETCH_CONFIG1_DMAMODE, syncType);
}

void GPMCSetPrefetchSyncMode(uint32_t baseAddr, uint32_t syncMode)
{
    HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
        GPMC_PREFETCH_CONFIG1_SYNCHROMODE, syncMode);
}

void GPMCSetPrefetchFifoThreshold(uint32_t baseAddr, uint32_t thresholdVal)
{
    HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
        GPMC_PREFETCH_CONFIG1_FIFOTHRESHOLD, thresholdVal);
}

void GPMCSetPrefetchXferCountVal(uint32_t baseAddr, uint32_t xferCountVal)
{
    HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG2,
        GPMC_PREFETCH_CONFIG1_FIFOTHRESHOLD, xferCountVal);
}

void GPMCArbitrationEnable(uint32_t baseAddr, uint32_t enableArbitration)
{
    if(TRUE == enableArbitration)
    {
        HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
            GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN,
            GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_ENABLED);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
            GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN,
            GPMC_PREFETCH_CONFIG1_PFPWENROUNDROBIN_DISABLED);
    }
}

void GPMCSetPrefetchEngNumAccess(uint32_t baseAddr, uint32_t accessNum)
{
    HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
            GPMC_PREFETCH_CONFIG1_PFPWWEIGHTEDPRIO, accessNum);
}

void GPMCPrefetchOptAccessEnable(uint32_t baseAddr, uint32_t enableOptAccess)
{
    if(TRUE == enableOptAccess)
    {
        HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
            GPMC_PREFETCH_CONFIG1_ENABLEOPTIMIZEDACCESS,
            GPMC_PREFETCH_CONFIG1_ENABLEOPTIMIZEDACCESS_ENABLED);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
            GPMC_PREFETCH_CONFIG1_ENABLEOPTIMIZEDACCESS,
            GPMC_PREFETCH_CONFIG1_ENABLEOPTIMIZEDACCESS_DISABLED);
    }
}

void GPMCSetPrefetchCycleTimeOptVal(uint32_t baseAddr, uint32_t optVal)
{
    HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
            GPMC_PREFETCH_CONFIG1_CYCLEOPTIMIZATION, optVal);
}

void GPMCPrefetchEngineEnable(uint32_t baseAddr, uint32_t enablePrefetchEngine)
{
    if(TRUE == enablePrefetchEngine)
    {
        HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
            GPMC_PREFETCH_CONFIG1_ENABLEENGINE,
            GPMC_PREFETCH_CONFIG1_ENABLEENGINE_ENABLED);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONFIG1,
            GPMC_PREFETCH_CONFIG1_ENABLEENGINE,
            GPMC_PREFETCH_CONFIG1_ENABLEENGINE_DISABLED);
    }
}

void GPMCPrefetchEngineStart(uint32_t baseAddr)
{
    HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONTROL,
        GPMC_PREFETCH_CONTROL_STARTENGINE,
        GPMC_PREFETCH_CONTROL_STARTENGINE_START);
}

void GPMCPrefetchEngineStop(uint32_t baseAddr)
{
    HW_WR_FIELD32(baseAddr + GPMC_PREFETCH_CONTROL,
        GPMC_PREFETCH_CONTROL_STARTENGINE,
        GPMC_PREFETCH_CONTROL_STARTENGINE_STOP);
}

uint32_t GPMCIsPrefetchEngRunning(uint32_t baseAddr)
{
    uint32_t status = FALSE;

    if(GPMC_PREFETCH_CONTROL_STARTENGINE_RUNNING ==
        HW_RD_FIELD32(baseAddr + GPMC_PREFETCH_CONTROL,
        GPMC_PREFETCH_CONTROL_STARTENGINE))
    {
        status = TRUE;
    }

    return status;
}

uint32_t GPMCPrefetchFifoThresholdStatus(uint32_t baseAddr)
{
    uint32_t status = FALSE;

    if(GPMC_PREFETCH_STATUS_FIFOTHRESHOLDSTATUS_GREATERTHANTHRES ==
        HW_RD_FIELD32(baseAddr + GPMC_PREFETCH_CONTROL,
        GPMC_PREFETCH_STATUS_FIFOTHRESHOLDSTATUS))
    {
        status = TRUE;
    }

    return status;
}

uint32_t GPMCGetPrefetchFifoPtr(uint32_t baseAddr)
{
    uint32_t fifoPtr = 0U;

    fifoPtr = HW_RD_FIELD32(baseAddr + GPMC_PREFETCH_STATUS,
        GPMC_PREFETCH_STATUS_FIFOPOINTER);

    return fifoPtr;
}

uint32_t GPMCGetPrefetchFifoRemBytes(uint32_t baseAddr)
{
    uint32_t countVal = 0U;

    countVal = HW_RD_FIELD32(baseAddr + GPMC_PREFETCH_STATUS,
        GPMC_PREFETCH_STATUS_COUNTVALUE);

    return countVal;
}

void GPMCSetEccChipSel(uint32_t baseAddr, uint32_t csNum)
{
    HW_WR_FIELD32(baseAddr + GPMC_ECC_CONFIG, GPMC_ECC_CONFIG_ECCCS, csNum);
}

void GPMCSetEccColumnSize(uint32_t baseAddr, uint32_t columnSize)
{
    HW_WR_FIELD32(baseAddr + GPMC_ECC_CONFIG, GPMC_ECC_CONFIG_ECC16B,
        columnSize);
}

void GPMCSetEccNumSectors(uint32_t baseAddr, uint32_t numSectors)
{
    HW_WR_FIELD32(baseAddr + GPMC_ECC_CONFIG, GPMC_ECC_CONFIG_ECCTOPSECTOR,
        numSectors);
}

void GPMCSetEccAlgorithm(uint32_t baseAddr, uint32_t eccAlgorithm)
{
    HW_WR_FIELD32(baseAddr + GPMC_ECC_CONFIG, GPMC_ECC_CONFIG_ECCALGORITHM,
        eccAlgorithm);
}

void GPMCSetBchEccCapability(uint32_t baseAddr, uint32_t eccBchCapLvl)
{
    HW_WR_FIELD32(baseAddr + GPMC_ECC_CONFIG, GPMC_ECC_CONFIG_ECCBCHTSEL,
        eccBchCapLvl);
}

void GPMCSetBchWrapModeVal(uint32_t baseAddr, uint32_t wrapModeVal)
{
    HW_WR_FIELD32(baseAddr + GPMC_ECC_CONFIG, GPMC_ECC_CONFIG_ECCWRAPMODE,
        wrapModeVal);
}

void GPMCEccEnable(uint32_t baseAddr, uint32_t enableEcc)
{
    if(TRUE == enableEcc)
    {
        HW_WR_FIELD32(baseAddr + GPMC_ECC_CONFIG, GPMC_ECC_CONFIG_ECCENABLE,
            GPMC_ECC_CONFIG_ECCENABLE_ENABLED);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_ECC_CONFIG, GPMC_ECC_CONFIG_ECCENABLE,
            GPMC_ECC_CONFIG_ECCENABLE_DISABLED);
    }
}

void GPMCEccResultRegClear(uint32_t baseAddr)
{
    HW_WR_FIELD32(baseAddr + GPMC_ECC_CONTROL, GPMC_ECC_CONTROL_ECCCLEAR,
        GPMC_ECC_CONTROL_ECCCLEAR_CLR);
}

void GPMCEccResultRegSelect(uint32_t baseAddr, uint32_t eccRegNum)
{
    HW_WR_FIELD32(baseAddr + GPMC_ECC_CONTROL, GPMC_ECC_CONTROL_ECCPOINTER,
        eccRegNum);
}

void GPMCSetEccSize(uint32_t baseAddr,
                    uint32_t eccSizeNum,
                    uint32_t eccSizeVal)
{
    if(GPMC_ECC_SIZE_NUM_0 == eccSizeNum)
    {
        HW_WR_FIELD32(baseAddr + GPMC_ECC_SIZE_CONFIG,
            GPMC_ECC_SIZE_CONFIG_ECCSIZE0, eccSizeVal);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_ECC_SIZE_CONFIG,
            GPMC_ECC_SIZE_CONFIG_ECCSIZE1, eccSizeVal);
    }
}

void GPMCSetEccResultSize(uint32_t baseAddr,
                          uint32_t eccResRegNum,
                          uint32_t eccSizeNum)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG32(baseAddr + GPMC_ECC_SIZE_CONFIG);
    regVal &= ~(1U << (eccResRegNum -1));
    regVal |= (eccSizeNum << (eccResRegNum -1));
    HW_WR_REG32(baseAddr + GPMC_ECC_SIZE_CONFIG, regVal);
}

uint32_t GPMCGetEccResult(uint32_t baseAddr, uint32_t eccResRegNum)
{
    uint32_t eccResult = 0U;

    eccResult = HW_RD_REG32(baseAddr + GPMC_ECC_RESULT(eccResRegNum));

    return eccResult;
}

uint32_t GPMCGetBchResult(uint32_t baseAddr, uint32_t csNum, uint32_t resIndex)
{
    uint32_t bchResult = 0U;

    switch (resIndex)
    {
        case 0U:
             bchResult = HW_RD_REG32(baseAddr + GPMC_BCH_RESULT0(csNum));
        break;
        case 1U:
             bchResult = HW_RD_REG32(baseAddr + GPMC_BCH_RESULT1(csNum));
        break;
        case 2U:
             bchResult = HW_RD_REG32(baseAddr + GPMC_BCH_RESULT2(csNum));
        break;
        case 3U:
             bchResult = HW_RD_REG32(baseAddr + GPMC_BCH_RESULT3(csNum));
        break;
        case 4U:
             bchResult = HW_RD_REG32(baseAddr + GPMC_BCH_RESULT4(csNum));
        break;
        case 5U:
             bchResult = HW_RD_REG32(baseAddr + GPMC_BCH_RESULT5(csNum));
        break;
        case 6U:
             bchResult = HW_RD_REG32(baseAddr + GPMC_BCH_RESULT6(csNum));
        break;
        default:
        break;
    }

    return bchResult;
}

void GPMCSetEccBchSwData(uint32_t baseAddr, uint16_t bchData)
{
    HW_WR_FIELD32(baseAddr + GPMC_BCH_SWDATA, GPMC_BCH_SWDATA_DATA, bchData);
}

uint16_t GPMCGetEccBchSwData(uint32_t baseAddr)
{
    uint16_t bchData = 0U;

    bchData = HW_RD_FIELD32(baseAddr + GPMC_BCH_SWDATA, GPMC_BCH_SWDATA_DATA);

    return bchData;
}

void GPMCSetIdleMode(uint32_t baseAddr, uint32_t idleMode)
{
    HW_WR_FIELD32(baseAddr + GPMC_SYSCONFIG, GPMC_SYSCONFIG_SIDLEMODE,
        idleMode);
}

void GPMCAutoIdleEnable(uint32_t baseAddr, uint32_t enableAutoIdle)
{
    if(TRUE == enableAutoIdle)
    {
        HW_WR_FIELD32(baseAddr + GPMC_SYSCONFIG, GPMC_SYSCONFIG_AUTOIDLE,
            GPMC_SYSCONFIG_AUTOIDLE_AUTORUN);
    }
    else
    {
        HW_WR_FIELD32(baseAddr + GPMC_SYSCONFIG, GPMC_SYSCONFIG_AUTOIDLE,
            GPMC_SYSCONFIG_AUTOIDLE_FREERUN);
    }
}
