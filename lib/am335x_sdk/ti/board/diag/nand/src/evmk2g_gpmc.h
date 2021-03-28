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
 * \file evmk2g_gpmc.h
 *
 * \brief This file is the header file for GPMC module
 *
 ******************************************************************************/

#ifndef	_EVMK2G_GPMC_H_
#define	_EVMK2G_GPMC_H_

/************************
 * Defines and Macros
 ************************/

/**
  *  Handle to access GPMC registers.
  */
#define hGpmcCfg  ((CSL_GpmcRegs *)CSL_GPMC_0_CFG_REGS)
typedef CSL_GpmcRegs * gpmcHandle;

#define GPMC_CMD_REG(cs)      ((uintptr_t)&hGpmcCfg->NAND_COMMAND_0 + (cs * (0x30)))
#define GPMC_ADDR_REG(cs)     ((uintptr_t)&hGpmcCfg->NAND_ADDR_0 + (cs * (0x30)))
#define GPMC_DATA_REG(cs)     ((uintptr_t)&hGpmcCfg->NAND_DATA_0 + (cs * (0x30)))

#define GPMC_BIT_SET_HIGH        (1)
#define GPMC_BIT_SET_LOW         (0)

#define GPMC_BIT_ENABLE          (1)
#define GPMC_BIT_DISABLE         (0)

/*****************************************************************************/
/*
** Macros which can be used as 'mode' parameter to GPMCIdleModeSelect API.
**
*/
#define GPMC_IDLEMODE_FORCEIDLE                       (0)
#define GPMC_IDLEMODE_NOIDLE                          (1)
#define GPMC_IDLEMODE_SMARTIDLE                       (2)

/*****************************************************************************/
/*
** Macros which can be used as 'configVal' parameter to GPMCAutoIdleConfig API.
**
*/
#define GPMC_AUTOIDLE_FREERUN                         (0)
#define GPMC_AUTOIDLE_AUTORUN                         (1)

/*****************************************************************************/
/*
** Macros which can be used as 'flag' parameter to GPMCIntStatusGet,
** GPMCIntStatusClear APIs.
**
*/
#define GPMC_FIFOEVENT_STATUS                         (0)
#define GPMC_TERMINALCOUNT_STATUS                     (1)
#define GPMC_WAIT0EDGEDETECTION_STATUS                (2)
#define GPMC_WAIT1EDGEDETECTION_STATUS                (3)

/*****************************************************************************/
/*
** Macros which can be used as 'flag' parameter to GPMCIntEnable, GPMCIntDisable
** APIs.
**
*/
#define GPMC_FIFOEVENT_INT                            (0)
#define GPMC_TERMINALCOUNT_INT                        (1)
#define GPMC_WAIT0EDGEDETECTION_INT                   (2)
#define GPMC_WAIT1EDGEDETECTION_INT                   (3)

/*****************************************************************************/
/*
** Macros which can be used as 'flag' parameter to GPMCTimeOutFeatureConfig API.
**
*/
#define GPMC_TIMEOUTFEATURE_ENABLE                    (1)
#define GPMC_TIMEOUTFEATURE_DISABLE                   (0)

/*****************************************************************************/
/*
** Macros which can be used as 'err' parameter to GPMCErrStatusGet API.
**
*/
#define GPMC_TIMEOUT_ERROR                            (0)
#define GPMC_NOTSUPPMCMD_ERROR                        (1)
#define GPMC_NOTSUPPADD_ERROR                         (2)

/*****************************************************************************/
/*
** Macros which can be used as 'pin' parameter to GPMCWaitPinPolaritySelect,
** GPMCWaitPinStatusGet APIs.
**
*/
#define GPMC_WAIT_PIN0                                (0)
#define GPMC_WAIT_PIN1                                (1)

/*****************************************************************************/
/*
** Macros which can be used as 'polarity' parameter to GPMCWaitPinPolaritySelect
** API.
**
*/
#define GPMC_WAIT_PIN_POLARITY_LOW                    (0)
#define GPMC_WAIT_PIN_POLARITY_HIGH                   (1)

/*****************************************************************************/
/*
** Macros which can be used as 'pinLevel' parameter to
** GPMCWriteProtectPinLevelCntrl API.
*/
#define GPMC_WP_PIN_LEVEL_LOW                         (0)
#define GPMC_WP_PIN_LEVEL_HIGH                        (1)

/*****************************************************************************/
/*
** Macros which can be used as 'flag' parameter to
** GPMCNANDForcePostedWriteFeatureConfig API.
*/
#define GPMC_FORCEPOSTEDWRITE_ENABLE                  (1)
#define GPMC_FORCEPOSTEDWRITE_DISABLE                 (0)

/*****************************************************************************/
/*
** Macros which can be used as 'flag' parameter to
** GPMCLimitedAddrDevSupportConfig API.
*/
#define GPMC_LIMITEDADDRESS_SUPPORT_ENABLE            (1)
#define GPMC_LIMITEDADDRESS_SUPPORT_DISABLE           (0)

/*****************************************************************************/
/*
** Macros which can be used as 'csNum' parameter to GPMCFclkDividerSelect,
** GPMCTimeParaGranularitySelect, GPMCAddrDataMuxProtocolSelect,
** GPMCDevTypeSelect, GPMCDevSizeSelect, GPMCWaitPinSelect,
** GPMCWaitMonitoringTimeSelect, GPMCWaitPinMonitoringConfig,
** GPMCClkActivationTimeConfig, GPMCDevPageLenSet, GPMCWriteTypeSelect,
** GPMCReadTypeSelect, GPMCAccessTypeSelect, GPMCSyncWrapBurstConfig,
** GPMCCSTimingConfig, GPMCADVTimingConfig, GPMCWEAndOETimingConfig,
** GPMCRdAccessAndCycleTimeTimingConfig, GPMCCSConfig, GPMCBaseAddrSet,
** GPMCWrAccessAndWrDataOnADMUXBusTimingConfig, GPMCMaskAddrSet,
** GPMCycle2CycleAndTurnArndTimeTimingConfig, GPMCSNANDCmdWrite,
** GPMCNANDAddrWrite, GPMCNANDDataWrite, GPMCNANDDataRead, GPMCPrefetchCSSelect,
** GPMCECCCSSelect, GPMCECCBCHResultGet APIs.
**
*/
#define GPMC_CHIP_SELECT_0                            (0)
#define GPMC_CHIP_SELECT_1                            (1)
#define GPMC_CHIP_SELECT_2                            (2)
#define GPMC_CHIP_SELECT_3                            (3)
#define GPMC_CHIP_SELECT_4                            (4)
#define GPMC_CHIP_SELECT_5                            (5)
#define GPMC_CHIP_SELECT_6                            (6)
#define GPMC_CHIP_SELECT_7                            (7)

/*****************************************************************************/
/*
** Macros which can be used as 'divideVal' parameter to GPMCFclkDividerSelect
** API.
**
*/
#define GPMC_FCLK_DIV_BY_1                            (0)
#define GPMC_FCLK_DIV_BY_2                            (1)
#define GPMC_FCLK_DIV_BY_3                            (2)
#define GPMC_FCLK_DIV_BY_4                            (3)

/*****************************************************************************/
/*
** Macros which can be used as 'scaleftr' parameter to
** GPMCTimeparaGranularitySelect API.
**
*/
#define GPMC_TIMEPARAGRANULARITY_X1                   (0)
#define GPMC_TIMEPARAGRANULARITY_X2                   (1)

/*****************************************************************************/
/*
** Macros which can be used as 'protocol' parameter to
** GPMCAddrDataMuxProtocolSelect API.
**
*/
#define GPMC_MUXADDDATA_NOMUX                         (0)
#define GPMC_MUXADDDATA_AADMUX                        (1)
#define GPMC_MUXADDDATA_ADMUX                         (2)

/*****************************************************************************/
/*
** Macros which can be used as 'devType' parameter to GPMCDevTypeSelect API.
**
*/
#define GPMC_DEVICETYPE_NORLIKE                       (0)
#define GPMC_DEVICETYPE_NANDLIKE                      (2)

/*****************************************************************************/
/*
** Macros which can be used as 'devSize' parameter to GPMCDevSizeSelect API.
**
*/
#define GPMC_DEVICESIZE_8BITS                         (0)
#define GPMC_DEVICESIZE_16BITS                        (1)

/*****************************************************************************/
/*
** Macros which can be used as 'flag' parameter to GPMCWaitMonitoringTimeSelect
** API.
**
*/
#define GPMC_WAITMONITORINGTIME_WITH_VALIDDATA        (0)
#define GPMC_WAITMONITORINGTIME_ONECLKB4_VALIDDATA    (1)
#define GPMC_WAITMONITORINGTIME_TWOCLKB4_VALIDDATA    (2)

/*****************************************************************************/
/*
** Macros which can be used as 'mode' parameter to GPMCWaitPinMonitoringConfig
** API.
**
*/
#define GPMC_MODE_READ                                (0)
#define GPMC_MODE_WRITE                               (1)

/*****************************************************************************/
/*
** Macros which can be used as 'flag' parameter to GPMCWaitMonitoringTimeConfig
** API.
**
*/
#define GPMC_WAITMONITORING_ENABLE                    (1)
#define GPMC_WAITMONITORING_DISABLE                   (0)

/*****************************************************************************/
/*
** Macros which can be used as 'flag' parameter to GPMCClkActivationTimeConfig
** API.
**
*/
#define GPMC_CLKACTIVATIONTIME_ATSTART                (0)
#define GPMC_CLKACTIVATIONTIME_ONECLK_AFTR            (1)
#define GPMC_CLKACTIVATIONTIME_TWOCLK_AFTR            (2)

/*****************************************************************************/
/*
** Macros which can be used as 'pageLen' parameter to GPMCDevPageLenSet API.
**
*/
#define GPMC_DEV_PAGELENGTH_FOUR                      (0)
#define GPMC_DEV_PAGELENGTH_EIGHT                     (1)
#define GPMC_DEV_PAGELENGTH_SIXTEEN                   (2)

/*****************************************************************************/
/*
** Macros which can be used as 'writeType' parameter to GPMCWriteTypeSelect API.
**
*/
#define GPMC_WRITETYPE_ASYNC                          (0)
#define GPMC_WRITETYPE_SYNC                           (1)

/*****************************************************************************/
/*
** Macros which can be used as 'readType' parameter to GPMCReadTypeSelect API.
**
*/
#define GPMC_READTYPE_ASYNC                           (0)
#define GPMC_READTYPE_SYNC                            (1)

/*****************************************************************************/
/*
** Macros which can be used as 'AccessType' parameter to GPMCAccessTypeSelect
** API.
**
*/
#define GPMC_ACCESSTYPE_SINGLE                        (0)
#define GPMC_ACCESSTYPE_MULTIPLE                      (1)

/*****************************************************************************/
/*
** Macros which can be used as 'flag' parameter to GPMCSyncWrapBurstConfig API.
**
*/
#define GPMC_WRAPBURST_ENABLE                         (1)
#define GPMC_WRAPBURST_DISABLE                        (0)

/*****************************************************************************/
/*
** Macros which can be used as 'CSExtDelayFlag' parameter to
** GPMC_CS_TIMING_CONFIG macro
*/
#define GPMC_CS_EXTRA_DELAY                           (1)
#define GPMC_CS_EXTRA_NODELAY                         (0)

/*
* \brief  This macro used to make the conf value which is used to configure the
*         CS signal timing configuration.\n
*
* \param  CSWrOffTime    CS# de-assertion time from start cycle time for write
*                        accesses in GPMC_FCLK cycles.
*
*         CSRdOffTime    CS# de-assertion time from start cycle time for read
*                        accesses in GPMC_FCLK cycles
*
*         CSExtDelayFlag Flag to indicate whether to add half GPMC_FCLK delay to
*                        CS or not.
*                        This can take one of the following values :
*                        GPMC_CS_EXTRA_DELAY --   CS# Timing control
*                                                 signal is delayed of
*                                                 half GPMC_FCLK cycle.
*                        GPMC_CS_EXTRA_NODELAY -- CS# Timing control
*                                                 signal is not delayed
*
*         CSOnTime       CS# assertion time from start cycle time in GPMC_FCLK
*                        cycles.
*/

#define GPMC_CS_TIMING_CONFIG(CSWrOffTime, CSRdOffTime, CSExtDelayFlag, CSOnTime )   ((Uint32) \
							                                        (CSL_FMK(GPMC_CONFIG2_0_CSWROFFTIME, CSWrOffTime)) | \
							                                        (CSL_FMK(GPMC_CONFIG2_0_CSRDOFFTIME, CSRdOffTime)) | \
							                                        (CSL_FMK(GPMC_CONFIG2_0_CSEXTRADELAY, CSExtDelayFlag)) | \
							                                        (CSL_FMK(GPMC_CONFIG2_0_CSONTIME, CSOnTime)))

/*****************************************************************************/
/*
** Macros which can be used as 'ADVExtDelayFlag' parameter to
** GPMC_ADV_TIMING_CONFIG macro
*/
#define GPMC_ADV_EXTRA_DELAY                          (1)
#define GPMC_ADV_EXTRA_NODELAY                        (0)

/*
* \brief  This macro used to make the conf value which is used to configure the
*         ADV# signal timing configuration.\n
*
* \param  ADVAADMuxWrOffTime    ADV# de-assertion time in GPMC_FCLK cycles for
*                               first address phase when using the AAD-Mux
*                               prorocol.
*
*         ADVAADMuxRdOffTime    ADV# de-assertion time in GPMC_FCLK cycles for
*                               first address phase when using the AAD-Mux
*                               prorocol.
*
*         ADVWrOffTime          ADV# de-assertion time in GPMC_FCLK cycles from
*                               start cycle time for write accesses
*
*         ADVRdOffTime          ADV# de-assertion time in GPMC_FCLK cycles from
*                               start cycle time for write accesses
*
*         ADVExtDelayFlag       Flag to indicate whether to add half GPMC_FCLK
*                               delay to ADV or not.
*                               This can take one of the following values :
*                               GPMC_ADV_EXTRA_DELAY --   ADV# Timing control
*                                                         signal is delayed of
*                                                         half GPMC_FCLK cycle.
*                               GPMC_ADV_EXTRA_NODELAY -- ADV# Timing control
*                                                         signal is not delayed.
*
*         ADVAADMuxOnTime       ADV# assertion time in GPMC_FCLK cycles for
*                               first address phase when using the
*                               AAD-Multiplexed protocol.
*
*         ADVOnTime             ADV# assertion time from start cycle time in
*                               GPMC_FCLK cycles.
*/

#define GPMC_ADV_TIMING_CONFIG(ADVAADMuxWrOffTime, ADVAADMuxRdOffTime, ADVWrOffTime, ADVRdOffTime, ADVExtDelayFlag, ADVAADMuxOnTime, ADVOnTime)   ((Uint32) \
                                                  (CSL_FMK(GPMC_CONFIG3_0_ADVAADMUXWROFFTIME, ADVAADMuxWrOffTime)) | \
                                                  (CSL_FMK(GPMC_CONFIG3_0_ADVAADMUXRDOFFTIME, ADVAADMuxRdOffTime)) | \
                                                  (CSL_FMK(GPMC_CONFIG3_0_ADVWROFFTIME, ADVWrOffTime)) | \
                                                  (CSL_FMK(GPMC_CONFIG3_0_ADVRDOFFTIME, ADVRdOffTime)) | \
                                                  (CSL_FMK(GPMC_CONFIG3_0_ADVEXTRADELAY, ADVExtDelayFlag)) | \
                                                  (CSL_FMK(GPMC_CONFIG3_0_ADVAADMUXONTIME, ADVAADMuxOnTime)) | \
                                                  (CSL_FMK(GPMC_CONFIG3_0_ADVONTIME, ADVOnTime)))

/*****************************************************************************/
/*
** Macros which can be used as 'OEExtDelayFlag' parameter to
** GPMC_WE_OE_TIMING_CONFIG macro
*/
#define GPMC_OE_EXTRA_DELAY                           (1)
#define GPMC_OE_EXTRA_NODELAY                         (0)

/*****************************************************************************/
/*
** Macros which can be used as 'WEExtDelayFlag' parameter to
** GPMC_WE_OE_TIMING_CONFIG macro
*/
#define GPMC_WE_EXTRA_DELAY                           (1)
#define GPMC_WE_EXTRA_NODELAY                         (0)


/*
* \brief  This macro used to make the conf value which is used to configure the
*         WE# and OE# signal timing configuration.\n
*
* \param  WEOffTime             WE# de-assertion time in GPMC_FCLK cycles from
*                               start cycle time.
*
*         WEExtDelayFlag        Flag to indicate whether to add half GPMC_FCLK
*                               delay to WE or not.
*                               This can take one of the following values :
*                               GPMC_WE_EXTRA_DELAY --   WE# Timing control
*                                                        signal is delayed of
*                                                        half GPMC_FCLK cycle.
*                               GPMC_WE_EXTRA_NODELAY -- WE# Timing control
*                                                        signal is not delayed
*         WEOnTime              WE# assertion time in GPMC_FCLK cycles from
*                               start cycle time.
*
*         OEAADMuxOffTime       OE# de-assertion time in GPMC_FCLK cycles for
*                               first address phase when using the AAD-Mux
*                               prorocol.
*
*         OEOffTime             OE# de-assertion time in GPMC_FCLK cycles from
*                               start cycle time.
*
*         OEExtDelayFlag        Flag to indicate whether to add half GPMC_FCLK
*                               delay to OE or not.
*                               This can take one of the following values :
*                               GPMC_OE_EXTRA_DELAY --   OE# Timing control
*                                                        signal is delayed of
*                                                        half GPMC_FCLK cycle.
*                               GPMC_OE_EXTRA_NODELAY -- OE# Timing control
*                                                        signal is not delayed
*
*         OEAADMuxOnTime        OE# assertion time in GPMC_FCLK cycles for
*                               first address phase when using the AAD-Mux
*                               prorocol.
*
*         OEOnTime              OE# assertion time in GPMC_FCLK cycles from
*                               start cycle time.
*
*/

#define GPMC_WE_OE_TIMING_CONFIG(WEOffTime, WEExtDelayFlag, WEOnTime, OEAADMuxOffTime, OEOffTime, OEExtDelayFlag, OEAADMuxOnTime,OEOnTime )   ((Uint32) \
                                                             (CSL_FMK(GPMC_CONFIG4_0_WEOFFTIME, WEOffTime)) | \
                                                             (CSL_FMK(GPMC_CONFIG4_0_WEEXTRADELAY, WEExtDelayFlag)) | \
                                                             (CSL_FMK(GPMC_CONFIG4_0_WEONTIME, WEOnTime)) | \
                                                             (CSL_FMK(GPMC_CONFIG4_0_OEAADMUXOFFTIME, OEAADMuxOffTime)) | \
                                                             (CSL_FMK(GPMC_CONFIG4_0_OEOFFTIME, OEOffTime)) | \
                                                             (CSL_FMK(GPMC_CONFIG4_0_OEEXTRADELAY, OEExtDelayFlag)) | \
                                                             (CSL_FMK(GPMC_CONFIG4_0_OEAADMUXONTIME, OEAADMuxOnTime)) | \
                                                             (CSL_FMK(GPMC_CONFIG4_0_OEONTIME, OEOnTime)))

/*
* \brief  This macro used to make the conf value which is used to configure the
*         read access and cycle time timing configuration.\n
*
* \param  rdCycleTime           Total read cycle time in GPMC_FCLK cycles.
*
*         wrCycleTime           Total write cycle time in GPMC_FCLK cycles.
*
*         rdAccessTime          Read access time (Delay between start cycle time
*                               and first data valid) in GPMC_FCLK cycles.
*
*         pageBurstAccessTime   Page burest access time (Delay between
*                               successive words in a multiple access)in
*                               GPMC_FCLK cycles.
*
*/

#define GPMC_RDACCESS_CYCLETIME_TIMING_CONFIG(rdCycleTime, wrCycleTime, rdAccessTime, pageBurstAccessTime )   ((Uint32) \
                                                    (CSL_FMK(GPMC_CONFIG5_0_RDCYCLETIME, rdCycleTime)) | \
                                                    (CSL_FMK(GPMC_CONFIG5_0_WRCYCLETIME, wrCycleTime)) | \
                                                    (CSL_FMK(GPMC_CONFIG5_0_RDACCESSTIME, rdAccessTime)) | \
                                                    (CSL_FMK(GPMC_CONFIG5_0_PAGEBURSTACCESSTIME, pageBurstAccessTime)))

/*****************************************************************************/
/*
** Macros which can be used as 'cycle2CycleDelaySameCSCfg' parameter to
** GPMC_CYCLE2CYCLE_BUSTURNAROUND_TIMING_CONFIG macro
*/
#define GPMC_CYCLE2CYCLESAMECSEN_C2CDELAY             (1)
#define GPMC_CYCLE2CYCLESAMECSEN_NOC2CDELAY           (0)

/*****************************************************************************/
/*
** Macros which can be used as 'cycle2CycleDelayDiffCSCfg' parameter to
** GPMC_CYCLE2CYCLE_BUSTURNAROUND_TIMING_CONFIG macro
*/
#define GPMC_CYCLE2CYCLEDIFFCSEN_C2CDELAY             (1)
#define GPMC_CYCLE2CYCLEDIFFCSEN_NOC2CDELAY           (0)

/*
* \brief  This macro used to make the conf value which is used to configure the
*         cycle to cycle and bus turn around time timing configuration.\n
*
* \param  cycle2CycleDelay       Cycle to cycle delay (Chip select high pulse
*                                delay between two successive accesses)in
*                                GPMC_FCLK cycles.
*
*      cycle2CycleDelaySameCSCfg Specified whether to add the cycle to cycle
*                                delay between two successive accesses or not
*                                (to the same chip-select).
*                                This can take one of the following values :
*                                GPMC_CYCLE2CYCLESAMECSEN_C2CDELAY   -- To add
*                                                                     the delay.
*                                GPMC_CYCLE2CYCLESAMECSEN_NOC2CDELAY -- Don't
*                                                                 add the delay.
*
*      cycle2CycleDelayDiffCSCfg Specified whether to add the cycle to cycle
*                                delay between two successive accesses or not
*                                (to the diffrent chip-select).
*                                This can take one of the following values :
*                                GPMC_CYCLE2CYCLEDIFFCSEN_C2CDELAY   -- To add
*                                                                     the delay.
*                                GPMC_CYCLE2CYCLEDIFFCSEN_NOC2CDELAY -- Don't
*                                                                 add the delay.
*
*         busTAtime             Bus turn aroung time between two successive
*                               accesses to the same chip-select (read to write)
*                               or to a diff chip-select in GPMC_FCLK cycles.
*
*
*/

#define GPMC_CYCLE2CYCLE_BUSTURNAROUND_TIMING_CONFIG(cycle2CycleDelay, cycle2CycleDelaySameCSCfg, cycle2CycleDelayDiffCSCfg, busTAtime )   ((Uint32) \
                                          (CSL_FMK(GPMC_CONFIG6_0_CYCLE2CYCLEDELAY, cycle2CycleDelay)) | \
                                          (CSL_FMK(GPMC_CONFIG6_0_CYCLE2CYCLESAMECSEN, cycle2CycleDelaySameCSCfg)) | \
                                          (CSL_FMK(GPMC_CONFIG6_0_CYCLE2CYCLEDIFFCSEN, cycle2CycleDelayDiffCSCfg)) | \
                                          (CSL_FMK(GPMC_CONFIG6_0_BUSTURNAROUND, busTAtime)))

/*****************************************************************************/
/*
** Macros which can be used as 'conf' parameter to GPMCCSConfig API.
**
*/
#define GPMC_CS_ENABLE                                (1)
#define GPMC_CS_DISABLE                               (0)

/*****************************************************************************/
/*
** Macros which can be used as 'addrMask' parameter to GPMCSMaskAddrSet API.
**
*/
#define GPMC_CS_SIZE_256MB                            (0x00)
#define GPMC_CS_SIZE_128MB                            (0x08)
#define GPMC_CS_SIZE_64MB                             (0x0c)
#define GPMC_CS_SIZE_32MB                             (0x0e)
#define GPMC_CS_SIZE_16MB                             (0x0f)

/*****************************************************************************/
/*
** Macros which can be used as 'accessMode' parameter to
** GPMCPREFETCHAccessModeSelect API.
*/
#define GPMC_PREFETCH_ACCESSMODE_READ                 (0)
#define GPMC_PREFETCH_ACCESSMODE_WRITE                (1)

/*****************************************************************************/
/*
** Macros which can be used as 'syncType' parameter to
** GPMCPREFETCHSyncTypeSelect API.
**
*/
#define GPMC_PREFETCH_SYNCTYPE_DMA                    (1)
#define GPMC_PREFETCH_SYNCTYPE_INT                    (0)

/*****************************************************************************/
/*
** Macros which can be used as 'flag' parameter to GPMCPrefetchSyncModeConfig
** API.
**
*/
#define GPMC_PREFETCH_ACCESSCS_AT_START               (0)
#define GPMC_PREFETCH_ACCESSCS_AT_STARTANDWAIT        (1)

/*****************************************************************************/
/*
** Macros which can be used as 'waitPin' parameter to GPMCPrefetchWaitPinSelect
** API.
**
*/
#define GPMC_PREFETCH_WAITPINSELECTOR_W0              (0)
#define GPMC_PREFETCH_WAITPINSELECTOR_W1              (1)

/*****************************************************************************/
/*
** Macros which can be used as 'configVal' GPMCPrefetchAccessCycleOptConfig API.
**
*/
#define GPMC_PREFETCH_OPTIMIZED_ACCESS_ENABLE         (1)
#define GPMC_PREFETCH_OPTIMIZED_ACCESS_DISABLE        (0)

/*****************************************************************************/
/*
** Macros which can be used as 'configVal' parameter to
** GPMCPrefetchRRArbitrationConfig API.
*/
#define GPMC_PREFETCH_RR_ARBITRATION_ENABLE           (1)
#define GPMC_PREFETCH_RR_ARBITRATION_DISABLE          (0)

/*****************************************************************************/
/*
** Macros which can be used as 'algo' parameter to GPMCECCAlgoSelect API.
**
*/
#define GPMC_ECC_ALGORITHM_HAMMINGCODE                (0)
#define GPMC_ECC_ALGORITHM_BCH                        (1)

/*****************************************************************************/
/*
** Macros which can be used as 'errCorrCapVal' parameter to
** GPMCECCBCHErrCorrectionCapSelect API.
**
*/
#define GPMC_ECC_BCH_ERRCORRCAP_UPTO_4BITS            (0)
#define GPMC_ECC_BCH_ERRCORRCAP_UPTO_8BITS            (1)
#define GPMC_ECC_BCH_ERRCORRCAP_UPTO_16BITS           (2)

/*****************************************************************************/
/*
** Macros which can be used as 'eccColVal' parameter to GPMCECCColumnSelect API.
**
*/
#define GPMC_ECC_COLUMNS_8                            (0)
#define GPMC_ECC_COLUMNS_16                           (1)

/*****************************************************************************/
/*
** Macros which can be used as 'numOfSects' parameter to
** GPMCECCBCHNumOfSectorsSelect API.
** Here 1 SECTOR = 512 bytes.
**
*/
#define GPMC_ECC_BCH_NUMOFSECTS_1                     (0)
#define GPMC_ECC_BCH_NUMOFSECTS_2                     (1)
#define GPMC_ECC_BCH_NUMOFSECTS_3                     (2)
#define GPMC_ECC_BCH_NUMOFSECTS_4                     (3)
#define GPMC_ECC_BCH_NUMOFSECTS_5                     (4)
#define GPMC_ECC_BCH_NUMOFSECTS_6                     (5)
#define GPMC_ECC_BCH_NUMOFSECTS_7                     (6)
#define GPMC_ECC_BCH_NUMOFSECTS_8                     (7)

/*****************************************************************************/
/*
** Macros which can be used as 'eccResReg' parameter to GPMCECCResultRegSelect
** API.
**
*/
#define GPMC_ECCPOINTER_RESULT_1                      (1)
#define GPMC_ECCPOINTER_RESULT_2                      (2)
#define GPMC_ECCPOINTER_RESULT_3                      (3)
#define GPMC_ECCPOINTER_RESULT_4                      (4)
#define GPMC_ECCPOINTER_RESULT_5                      (5)
#define GPMC_ECCPOINTER_RESULT_6                      (6)
#define GPMC_ECCPOINTER_RESULT_7                      (7)
#define GPMC_ECCPOINTER_RESULT_8                      (8)
#define GPMC_ECCPOINTER_RESULT_9                      (9)

/*****************************************************************************/
/*
** Macros which can be used as 'eccSize' parameter to GPMCECCSizeValSet API.
**
*/
#define GPMC_ECC_SIZE_0                               (0)
#define GPMC_ECC_SIZE_1                               (1)

/*****************************************************************************/
/*
** Macros which can be used as 'eccResReg' parameter to GPMCECCResultSizeSelect
** API.
**
*/
#define GPMC_ECC_RESULT_1                             (1)
#define GPMC_ECC_RESULT_2                             (2)
#define GPMC_ECC_RESULT_3                             (3)
#define GPMC_ECC_RESULT_4                             (4)
#define GPMC_ECC_RESULT_5                             (5)
#define GPMC_ECC_RESULT_6                             (6)
#define GPMC_ECC_RESULT_7                             (7)
#define GPMC_ECC_RESULT_8                             (8)
#define GPMC_ECC_RESULT_9                             (9)

/*****************************************************************************/
/*
** Macros which can be used as 'resIndex' parameter to GPMCECCBCHResultGet API.
**
*/
#define GPMC_BCH_RESULT_0                             (0)
#define GPMC_BCH_RESULT_1                             (1)
#define GPMC_BCH_RESULT_2                             (2)
#define GPMC_BCH_RESULT_3                             (3)
#define GPMC_BCH_RESULT_4                             (4)
#define GPMC_BCH_RESULT_5                             (5)
#define GPMC_BCH_RESULT_6                             (6)

/*
** Macros which defines the ECC size values.
*/
#define GPMC_ECC_SIZE0_VAL                      (0xFF)
#define GPMC_ECC_SIZE1_VAL                      (0xFF)

/***************************************************************************/
/*
** Function Prototypes
*/
extern void GPMCECCEnable(gpmcHandle hGpmc);
extern void GPMCECCDisable(gpmcHandle hGpmc);
extern void  GPMCModuleSoftReset(gpmcHandle hGpmc);
extern void GPMCECCResultRegClear(gpmcHandle hGpmc);
extern void GPMCPrefetchEngineStop(gpmcHandle hGpmc);
extern void GPMCPrefetchEngineStart(gpmcHandle hGpmc);
extern Uint32  GPMCErrAddrGet(gpmcHandle hGpmc);
extern void GPMCPrefetchEngineEnable(gpmcHandle hGpmc);
extern Uint32  GPMCRevisionGet(gpmcHandle hGpmc);
extern void GPMCPrefetchEngineDisable(gpmcHandle hGpmc);
extern Uint32  GPMCErrSysCmdGet(gpmcHandle hGpmc);
extern Uint32 GPMCECCBCHSWDataRead(gpmcHandle hGpmc);
extern Uint32  GPMCErrValStatusGet(gpmcHandle hGpmc);
extern Uint32  GPMCPREFETCHCountValGet(gpmcHandle hGpmc);
extern void  GPMCIntEnable(gpmcHandle hGpmc, Uint32 flag);
extern Uint32  GPMCModuleResetStatusGet(gpmcHandle hGpmc);
extern Uint32 GPMCPrefetchFIFOPtrValGet(gpmcHandle hGpmc);
extern void  GPMCIntDisable(gpmcHandle hGpmc, Uint32 flag);
extern void GPMCECCCSSelect(gpmcHandle hGpmc, Uint32 csNum);
extern Uint32  GPMCPrefetchEngineStatusGet(gpmcHandle hGpmc);
extern void GPMCECCAlgoSelect(gpmcHandle hGpmc, Uint32 algo);
extern void  GPMCIntStatusClear(gpmcHandle hGpmc, Uint32 flag);
extern void  GPMCIdleModeSelect(gpmcHandle hGpmc, Uint32 mode);
extern Uint32  GPMCPrefetchFIFOThrldStatusGet(gpmcHandle hGpmc);
extern void GPMCPrefetchCSSelect(gpmcHandle hGpmc, Uint32 csNum);
extern void GPMCECCBCHSWDataWrite(gpmcHandle hGpmc,Uint32 bchData);
extern Uint32  GPMCErrStatusGet(gpmcHandle hGpmc, Uint32 err);
extern void  GPMCAutoIdleConfig(gpmcHandle hGpmc, Uint32 configVal);
extern void GPMCECCColumnSelect(gpmcHandle hGpmc, Uint32 eccColVal);
extern Uint32  GPMCIntStatusGet(gpmcHandle hGpmc, Uint32 flag);
extern void  GPMCTimeOutFeatureConfig(gpmcHandle hGpmc, Uint32 flag);
extern void GPMCPrefetchSyncModeConfig(gpmcHandle hGpmc,Uint32 flag);
extern void GPMCECCResultRegSelect(gpmcHandle hGpmc,
                                   Uint32 eccResReg);
extern Uint32  GPMCSNANDDataRead(gpmcHandle hGpmc,
                                       Uint32 csNum);
extern Uint32 GPMCECCResultGet(gpmcHandle hGpmc,
                                     Uint32 eccResReg);
extern void GPMCPrefetchWaitPinSelect(gpmcHandle hGpmc,
                                      Uint32 waitPin);
extern Uint32  GPMCWaitPinStatusGet(gpmcHandle hGpmc,
                                          Uint32 pin);
extern void GPMCPrefetchSyncTypeSelect(gpmcHandle hGpmc,
                                       Uint32 syncType);
extern void  GPMCTimeOutStartValSet(gpmcHandle hGpmc,
                                    Uint32 timeoutVal);
extern void GPMCPrefetchCycleOptValSet(gpmcHandle hGpmc,
                                       Uint32 cleOptVal);
extern void GPMCECCBCHWrapModeValSet(gpmcHandle hGpmc,
                                     Uint32 wrapModeVal);
extern void GPMCPrefetchTrnsCntValSet(gpmcHandle hGpmc,
                                      Uint32 trnsCntVal);
extern void GPMCPrefetchWeightedPrioSet(gpmcHandle hGpmc,
                                        Uint32 accessVal);
extern void  GPMCLimitedAddrDevSupportConfig(gpmcHandle hGpmc,
                                             Uint32 flag);
extern void GPMCPrefetchAccessCycleOptConfig(gpmcHandle hGpmc,
                                             Uint32 configVal);
extern void GPMCECCBCHNumOfSectorsSelect(gpmcHandle hGpmc,
                                         Uint32 numOfSects);
extern void GPMCPrefetchAccessModeSelect(gpmcHandle hGpmc,
                                         Uint32 accessMode);
extern void GPMCPrefetchFifoThrldValSet(gpmcHandle hGpmc,
                                        Uint32 fifoThrsld);
extern void GPMCECCBCHErrCorrectionCapSelect(gpmcHandle hGpmc,
                                             Uint32 errCorrCapVal);
extern void  GPMCWriteProtectPinLevelCtrl(gpmcHandle hGpmc,
                                          Uint32 pinLevel);
extern Uint32  GPMCEmptyWriteBuffStatusGet(gpmcHandle hGpmc);
extern void  GPMCNANDForcePostedWriteFeatureConfig(gpmcHandle hGpmc,
                                                   Uint32 flag);
extern void GPMCECCSizeValSet(gpmcHandle hGpmc,Uint32 eccSize,
                              Uint32 eccSizeVal);
extern void  GPMCCSConfig(gpmcHandle hGpmc, Uint32 csNum,
                          Uint32 conf);
extern void  GPMCBaseAddrSet(gpmcHandle hGpmc, Uint32 csNum,
                             Uint32 addr);
extern void  GPMCMaskAddrSet(gpmcHandle hGpmc, Uint32 csNum,
                             Uint32 maskaddr);
extern void  GPMNANDCmdWrite(gpmcHandle hGpmc, Uint32 csNum,
                             Uint32 cmd);
extern void  GPMCDevTypeSelect(gpmcHandle hGpmc, Uint32 csNum,
                               Uint32 devType);
extern void  GPMCDevSizeSelect(gpmcHandle hGpmc, Uint32 csNum,
                               Uint32 devSize);
extern void  GPMCWaitPinSelect(gpmcHandle hGpmc, Uint32 csNum,
                               Uint32 waitPin);
extern void  GPMCCSTimingConfig(gpmcHandle hGpmc, Uint32 csNum,
                                Uint32 conf);
extern void  GPMCNANDAddrWrite(gpmcHandle hGpmc, Uint32 csNum,
                               Uint32 addr);
extern void  GPMCNANDDataWrite(gpmcHandle hGpmc, Uint32 csNum,
                               Uint32 data);
extern void  GPMCReadTypeSelect(gpmcHandle hGpmc, Uint32 csNum,
                                Uint32 readType);
extern void  GPMCADVTimingConfig(gpmcHandle hGpmc, Uint32 csNum,
                                 Uint32 conf);
extern void  GPMCWriteTypeSelect(gpmcHandle hGpmc, Uint32 csNum,
                                 Uint32 writeType);
extern void  GPMCDevPageLenSet(gpmcHandle hGpmc, Uint32 csNum,
                               Uint32 pageLen);
extern void  GPMCFclkDividerSelect(gpmcHandle hGpmc, Uint32 csNum,
                                   Uint32 divideVal);
extern void  GPMCWaitPinPolaritySelect(gpmcHandle hGpmc, Uint32 pin,
                                       Uint32 polarity);
extern void GPMCECCResultSizeSelect(gpmcHandle hGpmc,Uint32 eccResReg,
                                    Uint32 eccSize);
extern void  GPMCWEAndOETimingConfig(gpmcHandle hGpmc, Uint32 csNum,
                                     Uint32 conf);
extern void  GPMCSyncWrapBurstConfig(gpmcHandle hGpmc, Uint32 csNum,
                                     Uint32 flag);
extern Uint32 GPMCECCBCHResultGet(gpmcHandle hGpmc,
                                        Uint32 resIndex,
                                        Uint32 csNum);
extern void  GPMCClkActivationTimeConfig(gpmcHandle hGpmc,
                                         Uint32 csNum,
                                         Uint32 flag);
extern void  GPMCWaitMonitoringTimeSelect(gpmcHandle hGpmc,
                                          Uint32 csNum,
                                          Uint32 flag);
extern void  GPMCAddrDataMuxProtocolSelect(gpmcHandle hGpmc,
                                           Uint32 csNum,
                                           Uint32 protocol);
extern void  GPMCTimeParaGranularitySelect(gpmcHandle hGpmc,
                                           Uint32 csNum,
                                           Uint32 scaleftr);
extern void  GPMCRdAccessAndCycleTimeTimingConfig(gpmcHandle hGpmc,
                                                  Uint32 csNum,
                                                  Uint32 conf);
extern void  GPMCycle2CycleAndTurnArndTimeTimingConfig(gpmcHandle hGpmc,
                                                       Uint32 csNum,
                                                       Uint32 conf);
extern void  GPMCAccessTypeSelect(gpmcHandle hGpmc, Uint32 csNum,
                                  Uint32 mode, Uint32 accessType);
extern void  GPMCWaitPinMonitoringConfig(gpmcHandle hGpmc, Uint32 csNum,
                                         Uint32 mode, Uint32 flag);
extern void  GPMCWrAccessAndWrDataOnADMUXBusTimingConfig(gpmcHandle hGpmc,
                                                         Uint32 csNum,
                                                         Uint32 wrAccessTime,
                                                         Uint32 wrDataOnADmuxBus);
extern Uint32 GPMCPrefetchFifoPtrValGet(gpmcHandle hGpmc);

#endif /* _EVMK2G_GPMC_H_ */

