/**
 * \file   gpmc.h
 *
 * \brief  This file contains the prototypes of device abstraction layer APIs
 *         corresponding to the GPMC module. This also contains necessary
 *         structure, enum and macro definitions and the APIs are consolidated
 *         to make them more functional.
 *
 *  \details Programming sequence of GPMC is as follows:
 *           -# Enable Module Clocks for GPMC through PRCMModuleEnable API
 *           -# Configure the Pinmux for the GPMC module required through
 *              PINMUXModuleConfig API
 *           -# Perform a module reset of the GPMC instance through the API
 *              #GPMCModuleReset
 *           -# Set the device type to be interfaced with the GPMC through the
 *              API #GPMCSetDevType
 *           -# Set the size of the device to be interfaced with the GPMC
 *              through the API #GPMCSetDevSize
 *           -# Set the Address Data mux protocol type through the API
 *              #GPMCSetAddrDataMuxType
 *           -# Set the access mode of the GPMC for the device to be interfaced
 *              through the API #GPMCSetAccessMode for Read and Write operations
 *           -# Set the access type for Read and Write Operations to either
 *              Synchronous or Asynchronous through #GPMCSetAccessType API
 *           -# Set the Chip Select Base Address of the device to which the
 *              device is interfaced through the API #GPMCSetChipSelBaseAddr
 *           -# Set the Chip Select Mask Address of the device to which the
 *              device is interfaced through the API #GPMCSetChipSelMaskAddr
 *           -# Configure the Timing Parameters for the device selected through
 *              the following APIs for a particular chip select
 *              -# Configure the Chip Select Timing Parameters through the
 *                 API #GPMCChipSelectTimingConfig
 *              -# Configure the Address Valid(ADV)/Address Latch Enable(ALE)
 *                 signal timing Parameters through the API
 *                 #GPMCAdvSignalTimingConfig
 *              -# Configure the Output Enable(OE)/Write Enable(WE) signal
 *                 timing Parameters through the API
 *                 #GPMCWeOeSignalTimingConfig
 *              -# Configure the Read Access time timing Parameters through the
 *                 API #GPMCReadAccessTimingConfig
 *              -# Configure the Cycle to Cycle delay and bus turn around time
 *                 through the following API
 *                 #GPMCCycleDelayTimingConfig
 *              -# Configure the Write Access time timing Parameters through the
 *                 API #GPMCWriteAccessTimingConfig
 *           -# Enable the Chip Select to which the device is interfaced through
 *              the #GPMCChipSelEnable API
 *           -# To Configure the Prefetch Engine to perform Read/Write operation
 *              with the connected device do the following configurations
 *              -# Set the access mode of the Engine to either Read/Write
 *                 through the #GPMCSetPrefetchAccessMode API
 *              -# Select the Chip Select for which the Prefetch engine is to be
 *                 enabled through #GPMCSetPrefetchChipSel API
 *              -# Set the Fifo Threshold value through the
 *                 #GPMCSetPrefetchFifoThreshold API
 *              -# Set the transfer count value for the Prefetch engine
 *                 transaction through #GPMCSetPrefetchXferCountVal
 *              -# Select the Prefetch engine sync type to either Interrupt or
 *                 DMA through #GPMCSetPrefetchSyncType
 *              -# Set the Prefetch engine cycle time optimization through the
 *                 following API #GPMCSetPrefetchCycleTimeOptVal
 *              -# Enable the Prefetch engine for the operation through the
 *                 following API #GPMCPrefetchEngineEnable
 *              -# Start the Prefetch Engine for the Read/Write operation
 *                 through the #GPMCPrefetchEngineStart
 *           -# Wait Pin configurations can be done through the following APIs
 *              -# To set the Wait pin polarity the #GPMCSetWaitPinPol is to be
 *                 used as per the attached device requirements
 *              -# The monitoring time and related configurations for read and
 *                 Write access can be set through the following APIs
 *                 #GPMCWaitPinMonitoringEnable and
 *                 #GPMCSetWaitPinMonitoringTime
 *              -# The status of the Wait pin can be queried through the
 *                 following API #GPMCWaitPinStatus
 *           -# Configure the ECC engine for the chip select through the
 *              following APIs
 *              -# Select the ECC algorithm type to either Hamming Code or BCH
 *                 through #GPMCSetEccAlgorithm
 *              -# Set the column size for ECC computation for the device
 *                 through #GPMCSetEccColumnSize
 *              -# Select the Chip Select for which the ECC is to be enabled
 *                 #GPMCSetEccChipSel
 *              -# Select the ECC Result Register for storing the first ECC
 *                 Computation through #GPMCEccResultRegSelect
 *              -# Clear the ECC result registers with any previous stored data
 *                 through #GPMCEccResultRegClear
 *              -# Enable the ECC engine through #GPMCEccEnable
 *           -# Interrupts for the GPMC can be configured through the following
 *              APIs
 *              -# To enable and disable specific GPMC interrupts use
 *                 #GPMCIntrEnable and #GPMCIntrDisable
 *              -# Interrupt Status can be queried or cleared through the
 *                 following APIs #GPMCIntrStatus and #GPMCIntrClear
 *           -# GPMC error configurations and Status can be queried through the
 *              following APIs
 *              -# The #GPMCErrStatus API to get the Error Status
 *              -# The Error commands, Address can be queried through the
 *                 following APIs #GPMCGetErrAddr #GPMCGetErrSysCmd
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

#ifndef GPMC_H_
#define GPMC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "misc.h"
#include "hw_gpmc.h"

#ifdef __cplusplus
extern "C" {
#endif
#define GPMCRevisionGet                         GPMCGetRevision
#define GPMCModuleSoftReset                     GPMCModuleReset
#define GPMCModuleResetStatusGet                GPMCIsModuleResetDone
#define GPMCADVTimingConfig                     GPMCAdvSignalTimingConfig
#define GPMCWEAndOETimingConfig                 GPMCWeOeSignalTimingConfig
#define GPMCRdAccessAndCycleTimeTimingConfig    GPMCReadAccessTimingConfig
#define GPMCWrAccessAndWrDataOnADMUXBusTimingConfig GPMCWriteAccessTimingConfig
#define GPMCycle2CycleAndTurnArndTimeTimingConfig   GPMCCycleDelayTimingConfig
#define GPMCSNANDCmdWrite                       GPMCNandCmdWrite
#define GPMCNANDAddrWrite                       GPMCNandAddrWrite
#define GPMCNANDDataWrite                       GPMCNandDataWrite
#define GPMCNANDDataRead                        GPMCNandDataRead
#define GPMCLimitedAddrDevSupportConfig         GPMCLimitedAddrSupportEnable
#define GPMCNANDForcePostedWriteFeatureConfig   GPMCNandForcePostedWriteEnable
#define GPMCWaitPinPolaritySelect               GPMCWaitPinSelect
#define GPMCWaitPinStatusGet                    GPMCWaitPinStatusGet
#define GPMCWaitPinMonitoringConfig             GPMCWaitPinMonitoringEnable
#define GPMCWaitMonitoringTimeSelect            GPMCSetWaitPinMonitoringTime
#define GPMCWriteProtectPinLevelCtrl            GPMCSetWriteProtectPinLvl
#define GPMCEmptyWriteBuffStatusGet             GPMCIsWriteBufEmpty
#define GPMCIntStatusGet                        GPMCIntrStatus
#define GPMCIntStatusClear                      GPMCIntrClear
#define GPMCTimeOutFeatureConfig                GPMCTimeoutEnable
#define GPMCTimeOutStartValSet                  GPMCSetTimeoutVal
#define GPMCErrAddrGet                          GPMCGetErrAddr
#define GPMCErrSysCmdGet                        GPMCGetErrSysCmd
#define GPMCErrValStatusGet                     GPMCIsErrValid
#define GPMCErrStatusGet                        GPMCErrStatus
#define GPMCPrefetchAccessModeSelect            GPMCSetPrefetchAccessMode
#define GPMCPrefetchCSSelect                    GPMCSetPrefetchChipSel
#define GPMCPrefetchSyncTypeSelect              GPMCSetPrefetchSyncType
#define GPMCPrefetchSyncModeConfig              GPMCSetPrefetchSyncMode
#define GPMCPrefetchFifoThrldValSet             GPMCSetPrefetchFifoThreshold
#define GPMCPrefetchTrnsCntValSet               GPMCSetPrefetchXferCountVal
#define GPMCPrefetchRRArbitrationConfig         GPMCArbitrationEnable
#define GPMCPrefetchWeightedPrioSet             GPMCSetPrefetchEngNumAccess
#define GPMCPrefetchAccessCycleOptConfig        GPMCPrefetchOptAccessEnable
#define GPMCPrefetchCycleOptValSet              GPMCSetPrefetchCycleTimeOptVal
#define GPMCPrefetchEngineStop                  GPMCPrefetchEngineStop
#define GPMCPrefetchEngineStatusGet             GPMCIsPrefetchEngineRunning
#define GPMCPrefetchFifoThrldStatusGet          GPMCPrefetchFifoThresholdStatus
#define GPMCPrefetchCountValGet                 GPMCGetPrefetchFifoRemBytes
#define GPMCECCCSSelect                         GPMCSetEccChipSelect
#define GPMCECCColumnSelect                     GPMCSetEccColumnSize
#define GPMCECCBCHNumOfSectorsSelect            GPMCSetEccNumSectors
#define GPMCECCAlgoSelect                       GPMCSetEccAlgorithm
#define GPMCECCResultRegClear                   GPMCEccResultRegClear
#define GPMCECCResultRegSelect                  GPMCEccResultRegSelect
#define GPMCECCSizeValSet                       GPMCSetEccSize
#define GPMCECCResultSizeSelect                 GPMCSetEccResultSize
#define GPMCECCResultGet                        GPMCGetEccResult
#define GPMCECCBCHResultGet                     GPMCGetBchResult
#define GPMCECCBCHSWDataWrite                   GPMCSetEccBchSwData
#define GPMCECCBCHSWDataRead                    GPMCGetEccBchSwData
#define GPMCIdleModeSelect                      GPMCSetIdleMode
#define GPMCAutoIdleConfig                      GPMCAutoIdleEnable

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the different Chip select values of GPMC for interfacing
           different devices.*/
typedef enum gpmcChipSel
{
    GPMC_CHIP_SEL_MIN = 0U,
    /**< Minimum possible chip select value. */
    GPMC_CHIP_SEL_0 = GPMC_CHIP_SEL_MIN,
    /**< Chip Select 0. */
    GPMC_CHIP_SEL_1,
    /**< Chip Select 1. */
    GPMC_CHIP_SEL_2,
    /**< Chip Select 2. */
    GPMC_CHIP_SEL_3,
    /**< Chip Select 3. */
    GPMC_CHIP_SEL_4,
    /**< Chip Select 4. */
    GPMC_CHIP_SEL_5,
    /**< Chip Select 5. */
    GPMC_CHIP_SEL_6,
    /**< Chip Select 6. */
    GPMC_CHIP_SEL_MAX = GPMC_CHIP_SEL_6
    /**< Maximum possible chip select value. */
}gpmcChipSel_t;

/** \brief Enumerates the GPMC Read and Write Access Operational modes. */
typedef enum gpmcOperMode
{
    GPMC_OPER_MODE_READ = 0U,
    /**< GPMC Access in Read mode. */
    GPMC_OPER_MODE_WRITE,
    /**< GPMC Access in Write mode. */
}gpmcOperMode_t;

/** \brief Enumerates the different Device Types that can be interfaced through
           the GPMC.*/
typedef enum gpmcDevType
{
    GPMC_DEV_TYPE_NOR = GPMC_CONFIG1_DEVICETYPE_NORLIKE,
    /**< NOR flash like asynchronous and synchronous devices. */
    GPMC_DEV_TYPE_NAND = GPMC_CONFIG1_DEVICETYPE_NANDLIKE,
    /**< NAND flash like devices, stream mode. */
}gpmcDevType_t;

/** \brief Enumerates the different Address and Data Multiplex types. */
typedef enum gpmcMuxType
{
    GPMC_MUX_TYPE_NONE = GPMC_CONFIG1_MUXADDDATA_NONMUX,
    /**< Non-Multiplexed attached device. */
    GPMC_MUX_TYPE_AAD = GPMC_CONFIG1_MUXADDDATA_AADMUX,
    /**< AAD-Multiplexed device. */
    GPMC_MUX_TYPE_ADDR_DATA = GPMC_CONFIG1_MUXADDDATA_MUX
    /**< Address and Data Multiplexed device. */
}gpmcMuxType_t;

/** \brief Enumerates the different Device sizes supported by the GPMC. */
typedef enum gpmcDevSize
{
    GPMC_DEV_SIZE_8BIT = GPMC_CONFIG1_DEVICESIZE_EIGHTBITS,
    /**< 8 Bit Device Size. */
    GPMC_DEV_SIZE_16BIT = GPMC_CONFIG1_DEVICESIZE_SIXTEENBITS,
    /**< 16 bit Device Size. */
}gpmcDevSize_t;

/** \brief Eumerates the different Device Page Lengths in words. */
typedef enum gpmcDevPageLen
{
    GPMC_DEV_PAGE_LEN_4_WORDS = GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH_FOUR,
    /**< Device Page length of 4 words. */
    GPMC_DEV_PAGE_LEN_8_WORDS = GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH_EIGHT,
    /**< Device Page length of 8 words. */
    GPMC_DEV_PAGE_LEN_16_WORDS = GPMC_CONFIG1_ATTACHEDDEVICEPAGELENGTH_SIXTEEN,
    /**< Device Page length of 16 Words. */
}gpmcDevPageLen_t;

/** \brief Enumerates the Access modes of the GPMC module.
 *
 *  \details Same macros will be used for setting both READ and WRITE access
 *           modes.
 *
 *  \note    The following are the similar macros,
 *           - Single Access Type macros
 *             GPMC_CONFIG1_WRITEMULTIPLE_WRSINGLE
 *             GPMC_CONFIG1_WRITEMULTIPLE_WRMULTIPLE
 *           - Multiple Access Type macros
 *             GPMC_CONFIG1_READMULTIPLE_RDSINGLE
 *             GPMC_CONFIG1_READMULTIPLE_RDMULTIPLE
 */
typedef enum gpmcAccessMode
{
    GPMC_ACCESS_MODE_SINGLE = GPMC_CONFIG1_WRITEMULTIPLE_WRSINGLE,
    /**< Single Access type of the GPMC. */
    GPMC_ACCESS_MODE_MULTIPLE = GPMC_CONFIG1_WRITEMULTIPLE_WRMULTIPLE,
    /**< Multiple Access type of the GPMC. */
}gpmcAccessMode_t;

/** \brief Enumerates the Access types for Read and Write operations of the GPMC
           module. */
typedef enum gpmcAccessType
{
    GPMC_ACCESS_TYPE_SYNC_READ = 0U,
    /**< Synchronous Read access mode of the GPMC. */
    GPMC_ACCESS_TYPE_SYNC_WRITE,
    /**< Synchronous Write access mode of the GPMC. */
    GPMC_ACCESS_TYPE_ASYNC_READ,
    /**< Asynchronous Read access mode of the GPMC. */
    GPMC_ACCESS_TYPE_ASYNC_WRITE,
    /**< Asynchronous Write access mode of the GPMC. */
}gpmcAccessType_t;

/** \brief Enumerates the different GPMC interrupts. */
typedef enum gpmcIntrMask
{
    GPMC_INTR_MASK_WAIT0_EDGE_DETECTION =
        GPMC_IRQENABLE_WAIT0EDGEDETECTIONENABLE_MASK,
    /**< WAIT0 signal edge detection event interrupt. */
    GPMC_INTR_MASK_WAIT1_EDGE_DETECTION =
        GPMC_IRQENABLE_WAIT1EDGEDETECTIONENABLE_MASK,
    /**< WAIT1 signal edge detection event interrupt. */
    GPMC_INTR_MASK_TERMINAL_COUNT_EVT =
        GPMC_IRQENABLE_TERMINALCOUNTEVENTENABLE_MASK,
    /**< Mask value for Terminal count event interrupt. */
    GPMC_INTR_MASK_FIFO_EVT = GPMC_IRQENABLE_FIFOEVENTENABLE_MASK,
    /**< FIFO Event Interrupt Mask. */
    GPMC_INTR_MASK_ALL = (GPMC_IRQENABLE_WAIT0EDGEDETECTIONENABLE_MASK |
        GPMC_IRQENABLE_WAIT1EDGEDETECTIONENABLE_MASK |
        GPMC_IRQENABLE_TERMINALCOUNTEVENTENABLE_MASK |
        GPMC_IRQENABLE_FIFOEVENTENABLE_MASK)
    /**< Interrupt mask to enable/disable for all the GPMC interrupts. */
}gpmcIntrMask_t;

/** \brief Enumerates the different Chip Select Mask Address values for defining
           the Chip Select size. */
typedef enum gpmcMaskAddr
{
    GPMC_MASK_ADDR_16MB = GPMC_CONFIG7_MASKADDRESS_SIZE16MB,
    /**< Mask Address for chip select size of 16MB. */
    GPMC_MASK_ADDR_32MB = GPMC_CONFIG7_MASKADDRESS_SIZE32MB,
    /**< Mask Address for chip select size of 32MB. */
    GPMC_MASK_ADDR_64MB = GPMC_CONFIG7_MASKADDRESS_SIZE64MB,
    /**< Mask Address for chip select size of 64MB. */
    GPMC_MASK_ADDR_128MB = GPMC_CONFIG7_MASKADDRESS_SIZE128MB,
    /**< Mask Address for chip select size of 128MB. */
    GPMC_MASK_ADDR_256MB = GPMC_CONFIG7_MASKADDRESS_SIZE256MB,
    /**< Mask Address for chip select size of 256MB. */
}gpmcMaskAddr_t;

/** \brief Enumerates the GPMC functional clock divider. */
typedef enum gpmcFclkDivider
{
    GPMC_FCLK_DIVIDER_1 = GPMC_CONFIG1_GPMCFCLKDIVIDER_DIVBY1,
    /**< GPMC Functional Clock divider value 1. */
    GPMC_FCLK_DIVIDER_2 = GPMC_CONFIG1_GPMCFCLKDIVIDER_DIVBY2,
    /**< GPMC Functional Clock divider value 2. */
    GPMC_FCLK_DIVIDER_3 = GPMC_CONFIG1_GPMCFCLKDIVIDER_DIVBY3,
    /**< GPMC Functional Clock divider value 3. */
    GPMC_FCLK_DIVIDER_4 = GPMC_CONFIG1_GPMCFCLKDIVIDER_DIVBY4
    /**< GPMC Functional Clock divider value 4. */
}gpmcFclkDivider_t;

/** \brief Enumerates the GPMC Clock Activation time. */
typedef enum gpmcClkActTime
{
    GPMC_CLK_ACT_TIME_AT_START = GPMC_CONFIG1_CLKACTIVATIONTIME_ATSTART,
    /**< Clock Activation at first rising edge of GPMC Clock at start access
         time. */
    GPMC_CLK_ACT_TIME_1_CYCLE_AFTER_START_TIME =
        GPMC_CONFIG1_CLKACTIVATIONTIME_ONECLKB4,
    /**< Clock Activation at first rising edge of GPMC Clock one clock cycle
         after the start access time. */
    GPMC_CLK_ACT_TIME_2_CYCLE_AFTER_START_TIME =
        GPMC_CONFIG1_CLKACTIVATIONTIME_TWOCLKB4,
    /**< Clock Activation at first rising edge of GPMC Clock two cycle after the
         start access time. */
}gpmcClkActTime_t;

/** \brief Enumerates the Timing Granularity factor for GPMC access timings. */
typedef enum gpmcTimeGranularity
{
    GPMC_TIME_GRANULARITY_X1 = GPMC_CONFIG1_TIMEPARAGRANULARITY_X1,
    /**< Timing Latency factor of 1.*/
    GPMC_TIME_GRANULARITY_X2 = GPMC_CONFIG1_TIMEPARAGRANULARITY_X2
    /**< Timing Latency factor of 2. Multiplies all timing values by a factor
         of two. */
}gpmcTimeGranularity_t;

/** \brief Enumerates the values to control adding Cycle delay between 2
           successive accesses to the same chip select. */
typedef enum gpmcCycleDelaySameChipSel
{
    GPMC_CYCLE_DELAY_SAME_CHIP_SEL_NO_DELAY =
        GPMC_CONFIG6_CYCLE2CYCLESAMECSEN_NOC2CDELAY,
    /**<  Value indicating no delay to be added between 2 successive accesses to
          the same chip select. */
    GPMC_CYCLE_DELAY_SAME_CHIP_SEL_DELAY =
        GPMC_CONFIG6_CYCLE2CYCLESAMECSEN_C2CDELAY
    /**<  Value indicating a delay to be added between 2 successive accesses to
          the same chip select. */
}gpmcCycleDelaySameChipSel_t;

/** \brief Enumerates the values to control adding Cycle delay between 2
           successive accesses to different chip selects. */
typedef enum gpmcCycleDelayDiffChipSel
{
    GPMC_CYCLE_DELAY_DIFF_CHIP_SEL_NO_DELAY =
        GPMC_CONFIG6_CYCLE2CYCLESAMECSEN_NOC2CDELAY,
    /**<  Value indicating no delay to be added between 2 successive accesses to
          different chip select. */
    GPMC_CYCLE_DELAY_DIFF_CHIP_SEL_DELAY =
        GPMC_CONFIG6_CYCLE2CYCLESAMECSEN_C2CDELAY
    /**<  Value indicating a delay to be added between 2 successive accesses to
          different chip select. */
}gpmcCycleDelayDiffChipSel_t;

/** \brief Enumerates the different Wait Pins of the GPMC. */
typedef enum gpmcWaitPinNum
{
    GPMC_WAIT_PIN_NUM_0 = 0U,
    /**< Value specifying wait pin 0. */
    GPMC_WAIT_PIN_NUM_1,
    /**< Value specifying wait pin 1. */
}gpmcWaitPinNum_t;

/** \brief Enumerates the different Wait pin polarity levels.
 *
 *  \details Same macros will be used for setting of polarity of both WAITPIN0
 *           and WAITPIN1.
 *
 *  \note    The following are the similar macros,
 *           - Active Low polarity macros
 *             GPMC_CONFIG_WAIT0PINPOLARITY_W0ACTIVEL
 *             GPMC_CONFIG_WAIT1PINPOLARITY_W1ACTIVEL
 *           - Active High polarity macros
 *             GPMC_CONFIG_WAIT0PINPOLARITY_W0ACTIVEH
 *             GPMC_CONFIG_WAIT1PINPOLARITY_W1ACTIVEH
 */
typedef enum gpmcWaitPinPol
{
    GPMC_WAIT_PIN_POL_ACTIVE_LOW = GPMC_CONFIG_WAIT0PINPOLARITY_W0ACTIVEL,
    /**< Wait Pin Polarity of Active Low */
    GPMC_WAIT_PIN_POL_ACTIVE_HIGH = GPMC_CONFIG_WAIT0PINPOLARITY_W0ACTIVEH
    /**< Wait Pin Polarity of Active High */
}gpmcWaitPinPol_t;

/** \brief    Enumerates the values which control enabling/disabling of the wait
 *            pin monitoring.
 *
 *  \details  The same macros will be used for setting both Read and Write
 *            access waitpin monitoring.
 *
 *   \note    The following are the similar macros,
 *           - Wait pin monitoring for Read access
 *             GPMC_CONFIG1_WAITREADMONITORING_WNOTMONIT
 *             GPMC_CONFIG1_WAITREADMONITORING_WMONIT
 *           - Wait pin monitoring for Write access
 *             GPMC_CONFIG1_WAITWRITEMONITORING_WMONIT
 *             GPMC_CONFIG1_WAITWRITEMONITORING_WNOTMONIT
 */
typedef enum gpmcWaitPinMonitor
{
    GPMC_WAIT_PIN_MONITOR_ENABLE = GPMC_CONFIG1_WAITWRITEMONITORING_WMONIT,
    /**< Wait Pin monitored for Read/Write access. */
    GPMC_WAIT_PIN_MONITOR_DISABLE = GPMC_CONFIG1_WAITWRITEMONITORING_WNOTMONIT,
    /**< Wait Pin not monitored for Read/Write access. */
}gpmcWaitPinMonitor_t;

/** \brief    Enumerates the different states of WaitPin to indicate its status.
 *
 *  \details  The same macros will be used for checking both WaitPin0 and
 *            WaitPin1 status.
 *
 *   \note    The following are the similar macros,
 *           - Wait pin 0 Status values
 *             GPMC_STATUS_WAIT0STATUS_W0NOTASSERTED
 *             GPMC_STATUS_WAIT0STATUS_W0ASSERTED
 *           - Wait pin 1 Status values
 *             GPMC_STATUS_WAIT1STATUS_W1NOTASSERTED
 *             GPMC_STATUS_WAIT1STATUS_W1ASSERTED
 */
typedef enum gpmcWaitPinSts
{
    GPMC_WAIT_PIN_STS_DE_ASSERTED = GPMC_STATUS_WAIT0STATUS_W0NOTASSERTED,
    /**< Wait Pin is de-asserted. */
    GPMC_WAIT_PIN_STS_ASSERTED = GPMC_STATUS_WAIT0STATUS_W0ASSERTED,
    /**< Wait Pin is Asserted. */
}gpmcWaitPinSts_t;

/** \brief Enumerates the Waitpin monitoring times. */
typedef enum gpmcWaitPinTime
{
    GPMC_WAIT_PIN_TIME_WITH_VALID_DATA =
        GPMC_CONFIG1_WAITMONITORINGTIME_ATVALID,
    /**< Wait Pin is monitored with valid data. */
    GPMC_WAIT_PIN_TIME_ONE_CYCLE_BEFORE_VALID_DATA =
        GPMC_CONFIG1_WAITMONITORINGTIME_ONEDEVICEB4,
    /**< Wait Pin is monitored one GPMC Clk cycle before valid data. */
    GPMC_WAIT_PIN_TIME_TWO_CYCLE_BEFORE_VALID_DATA =
        GPMC_CONFIG1_WAITMONITORINGTIME_TWODEVICEB4,
    /**< Wait Pin is monitored two GPMC Clk cycle before valid data. */
}gpmcWaitPinTime_t;

/** \brief Enumerates the Write Protect Pin Levels. */
typedef enum gpmcWriteProtectPinLvl
{
    GPMC_WRITE_PROTECT_PIN_LVL_LOW = GPMC_CONFIG_WRITEPROTECT_WPLOW,
    /**< Write Protect Pin level low. */
    GPMC_WRITE_PROTECT_PIN_LVL_HIGH = GPMC_CONFIG_WRITEPROTECT_WPHIGH,
    /**< Write Protect Pin level high. */
}gpmcWriteProtectPinLvl_t;

/** \brief Enumerates the different PREFETCH engine access modes. */
typedef enum gpmcPrefetchEngMode
{
    GPMC_PREFETCH_ENG_MODE_READ = GPMC_PREFETCH_CONFIG1_ACCESSMODE_READ,
    /**< GPMC Access Engine Prefetch Read Mode. */
    GPMC_PREFETCH_ENG_MODE_WRITE =
        GPMC_PREFETCH_CONFIG1_ACCESSMODE_WRITE_POSTING,
    /**< GPMC Access Engine Post Writing Mode. */
}gpmcPrefetchEngMode_t;

/** \brief Enumerates the different PREFETCH engine Synchronization types. */
typedef enum gpmcPrefetchSyncType
{
    GPMC_PREFETCH_SYNC_TYPE_INTR = GPMC_PREFETCH_CONFIG1_DMAMODE_INTERRUPTSYNC,
    /**< Enables Prefetch Engine Interrupt request synchronization. */
    GPMC_PREFETCH_SYNC_TYPE_DMA = GPMC_PREFETCH_CONFIG1_DMAMODE_DMAENABLED,
    /**< Enables Prefetch Engine DMA request synchronization. */
}gpmcPrefetchSyncType_t;

/** \brief Enumerates the PREFETCH engine synchronous mode. */
typedef enum gpmcSyncMode
{
    GPMC_SYNC_MODE_START_ACCESS = GPMC_PREFETCH_CONFIG1_SYNCHROMODE_ATSTART,
    /**< Prefetch Engine Starts Access to Chip select as soon as STARTENGINE is
         set. */
    GPMC_SYNC_MODE_START_AND_WAITPIN_ACCESS =
        GPMC_PREFETCH_CONFIG1_SYNCHROMODE_ATSTARTANDWAIT,
    /**< Prefetch Engine Starts Access to Chip select as soon as STARTENGINE is
         set and wait for non wait edge detection on the selected wait pin. */
}gpmcSyncMode_t;

/** \brief Enumerates the Chip Select numbers for which the PREFETCH
           engine can be set active. */
typedef enum gpmcPrefetchChipSel
{
    GPMC_PREFETCH_CHIP_SEL_0 = GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS0,
    /**< Chip Select 0 Prefetch/Postwrite Engine. */
    GPMC_PREFETCH_CHIP_SEL_1 = GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS1,
    /**< Chip Select 1 for Prefetch/Postwrite engine. */
    GPMC_PREFETCH_CHIP_SEL_2 = GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS2,
    /**< Chip Select 2 for Prefetch/Postwrite engine. */
    GPMC_PREFETCH_CHIP_SEL_3 = GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS3,
    /**< Chip Select 3 for Prefetch/Postwrite engine. */
    GPMC_PREFETCH_CHIP_SEL_4 = GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS4,
    /**< Chip Select 4 for Prefetch/Postwrite engine. */
    GPMC_PREFETCH_CHIP_SEL_5 = GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS5,
    /**< Chip Select 5 for Prefetch/Postwrite engine. */
    GPMC_PREFETCH_CHIP_SEL_6 = GPMC_PREFETCH_CONFIG1_ENGINECSSELECTOR_CS6
    /**< Chip Select 6 for Prefetch/Postwrite engine. */
}gpmcPrefetchChipSel_t;

/** \brief Enumerates the different Error types of GPMC. */
typedef enum gpmcErrMask
{
    GPMC_ERR_MASK_TIMEOUT = GPMC_ERR_TYPE_ERRORTIMEOUT_MASK,
    /**< Timeout Error. */
    GPMC_ERR_MASK_NOT_SUPPORTED_CMD = GPMC_ERR_TYPE_ERRORNOTSUPPMCMD_MASK,
    /**< Not Supported Command Error. */
    GPMC_ERR_MASK_NOT_SUPPORTED_ADDR = GPMC_ERR_TYPE_ERRORNOTSUPPADD_MASK,
    /**< Not Supported Address Error. */
}gpmcErrMask_t;

/** \brief Enumerates the different Error Correcting Code (ECC) calculation
           Algorithms. */
typedef enum gpmcEccAlgo
{
    GPMC_ECC_ALGO_HAMMING_CODE = GPMC_ECC_CONFIG_ECCALGORITHM_HAMMING_CODE,
    /**< Hamming Code Algorithm for ECC calculation. */
    GPMC_ECC_ALGO_BCH_CODE = GPMC_ECC_CONFIG_ECCALGORITHM_BCH_CODE,
    /**< BCH algorithm for ECC calculation. */
}gpmcEccAlgo_t;

/** \brief Enumerates the different columns for ECC computation. */
typedef enum gpmcEccColumn
{
    GPMC_ECC_COLUMN_8 = GPMC_ECC_CONFIG_ECC16B_EIGHTCOL,
    /**< ECC Calculation for 8 columns. */
    GPMC_ECC_COLUMN_16 = GPMC_ECC_CONFIG_ECC16B_SIXTEENCOL
    /**< ECC Calculation for 16 columns. */
}gpmcEccColumn_t;

/** \brief Enumerates the different BCH ECC correction levels. */
typedef enum gpmcBchCapLvl
{
    GPMC_BCH_CAP_LVL_4_BITS = GPMC_ECC_CONFIG_ECCBCHTSEL_UPTO_4BITS,
    /**< GPMC BCH Error Correction up to 4 bits. */
    GPMC_BCH_CAP_LVL_8_BITS = GPMC_ECC_CONFIG_ECCBCHTSEL_UPTO_8BITS,
    /**< GPMC BCH Error Correction up to 8 bits. */
    GPMC_BCH_CAP_LVL_16_BITS = GPMC_ECC_CONFIG_ECCBCHTSEL_UPTO_16BITS
    /**< GPMC BCH Error Correction up to 16 bits. */
}gpmcBchCapLvl_t;

/** \brief Enumerates the different ECC Size values. */
typedef enum gpmcEccSizeNum
{
    GPMC_ECC_SIZE_NUM_0 = GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_SIZE0SEL,
    /**< Value to identify the ECC Size 0. */
    GPMC_ECC_SIZE_NUM_1 = GPMC_ECC_SIZE_CONFIG_ECC1RESULTSIZE_SIZE1SEL
    /**< Value to identify the ECC Size 1. */
}gpmcEccSizeNum_t;

/** \brief Enumerates the different ECC result registers where the
           first ECC computation will be stored. */
typedef enum gpmcEccResultReg
{
    GPMC_ECC_RESULT_REG_MIN = 1U,
    /**< Minimum value of the ECC result register. */
    GPMC_ECC_RESULT_REG_1 = GPMC_ECC_RESULT_REG_MIN,
    /**< ECC result register 1. */
    GPMC_ECC_RESULT_REG_2,
    /**< ECC result register 2. */
    GPMC_ECC_RESULT_REG_3,
    /**< ECC result register 3. */
    GPMC_ECC_RESULT_REG_4,
    /**< ECC result register 4. */
    GPMC_ECC_RESULT_REG_5,
    /**< ECC result register 5. */
    GPMC_ECC_RESULT_REG_6,
    /**< ECC result register 6. */
    GPMC_ECC_RESULT_REG_7,
    /**< ECC result register 7. */
    GPMC_ECC_RESULT_REG_8,
    /**< ECC result register 8. */
    GPMC_ECC_RESULT_REG_9,
    /**< ECC result register 9. */
    GPMC_ECC_RESULT_REG_MAX = GPMC_ECC_RESULT_REG_9,
    /**< Maximum ECC result register. */
}gpmcEccResultReg_t;

/** \brief Enumerates the different Idle modes of GPMC. */
typedef enum gpmcIdleMode
{
    GPMC_IDLE_MODE_FORCE_IDLE = GPMC_SYSCONFIG_SIDLEMODE_FORCEIDLE,
    /**< Force Idle Mode. */
    GPMC_IDLE_MODE_NO_IDLE = GPMC_SYSCONFIG_SIDLEMODE_NOIDLE,
    /**< No Idle Mode. */
    GPMC_IDLE_MODE_SMART_IDLE = GPMC_SYSCONFIG_SIDLEMODE_SMARTIDLE,
    /**< Smart Idle Mode. */
}gpmcIdleMode_t;

/** \brief Structure defining the Chip Select Signal Timing parameters. */
typedef struct gpmcChipSelTimingParams
{
    uint32_t    chipSelWrOffTime;
    /**< Chip Select de-assertion time from start cycle time for write
         accesses in GPMC_FCLK cycles.
         It can take any values in the range 0x0 to 0xF */
    uint32_t    chipSelRdOffTime;
    /**< Chip Select de-assertion time from start cycle time for write
         accesses in GPMC_FCLK cycles.
         It can take any values in the range 0x0 to 0xF */
    uint32_t    addExtDelay;
    /**< Flag to indicate whether to add half GPMC_FCLK delay to CS or not.
         This can take any of the following two values
         - TRUE to add half GPMC_FCLK cycle delay to timing control signal
         - FALSE to not add a half GPMC_FCLK cycle delay to timing control
           signal. */
    uint32_t    chipSelOnTime;
    /**< Chip Select Assertion time from start cycle time in GPMC_FCLK
         cycles.
         It can take any values in the range 0x0 to 0xF */
}gpmcChipSelTimingParams_t;

/** \brief Structure defining the Address Latch Enable(ALE)/ Address Valid(ADV)
           Signal Timing parameters. */
typedef struct gpmcAdvSignalTimingParams
{
    uint32_t    advAadMuxWrOffTime;
    /**< ADV de-assertion time in GPMC_FCLK cycles for first address phase
         when using the AAD-mux protocol.
         It can take any values in the range 0x0 to 0xF */
    uint32_t    advAadMuxRdOffTime;
    /**< ADV assertion time in GPMC_FCLK cycles for first address phase
         when using the AAD-mux protocol.
         It can take any values in the range 0x0 to 0xF */
    uint32_t    advWrOffTime;
    /**<  de-assertion time in GPMC_FCLK cycles from start cycle time for write
          accesses.
          It can take any values in the range 0x0 to 0xF */
    uint32_t    advRdOffTime;
    /**<  de-assertion time in GPMC_FCLK cycles from start cycle time for read
          accesses.
          It can take any values in the range 0x0 to 0xF */
    uint32_t    addExtDelay;
    /**< Flag to indicate whether to add half GPMC_FCLK delay to ADV signal
         or not. This can take any of the following two values
         - TRUE to add half GPMC_FCLK cycle delay to timing control signal
         - FALSE to not add a half GPMC_FCLK cycle delay to timing control
           signal. */
    uint32_t    advAadMuxOnTime;
    /**< Assertion time in GPMC_FCLK cycles for first address phase when using
         the AAD-mux protocol.
         It can take any values in the range 0x0 to 0xF */
    uint32_t    advOnTime;
    /**< ADV/ALE Assertion time from start cycle time in GPMC_FCLK cycles.
         It can take any values in the range 0x0 to 0xF */
}gpmcAdvSignalTimingParams_t;

/** \brief Structure defining the Output Enable(OE)/Write Enable(WE) Signal
           timing parameters. */
typedef struct gpmcOeWeSignalTimingParams
{
    uint32_t    writeEnableOffTime;
    /**< de-assertion time in GPMC_FCLK cycles from start cycle time.
        It can take any values in the range 0x0 to 0xF */
    uint32_t    writeEnableOnTime;
    /**< Write enable signal On time in GPMC_FCLK cycles.
        It can take any values in the range 0x0 to 0xF */
    uint32_t    oeAadMuxOffTime;
    /**<  OE signal de-assertion time in GPMC_FCLK cycles for first address
          phase when using the AAD-Mux protocol.
          It can take any values in the range 0x0 to 0xF */
    uint32_t    oeOffTime;
    /**<  Output Enable off time in GPMC_FCLK cycles.
          It can take any values in the range 0x0 to 0xF */
    uint32_t    addExtDelay;
    /**< Flag to indicate whether to add half GPMC_FCLK delay to WE/OE signal
         or not. This can take any of the following two values
         - TRUE to add half GPMC_FCLK cycle delay to timing control signal
         - FALSE to not add a half GPMC_FCLK cycle delay to timing control
           signal. */
    uint32_t    oeAadMuxOnTime;
    /**< Assertion time in GPMC_FCLK cycles for first address phase when using
         the AAD-mux protocol.
         It can take any values in the range 0x0 to 0xF */
    uint32_t    oeOnTime;
    /**< OE Assertion time from start cycle time in GPMC_FCLK cycles.
         It can take any values in the range 0x0 to 0xF */
}gpmcOeWeSignalTimingParams_t;

/** \brief Structure defining the Read access and cycle timing parameters for a
           Chip select. */
typedef struct gpmcReadAccessTime
{
    uint32_t    readCycleTime;
    /**< Total read cycle time in GPMC_FCLK cycles.
         It can take any values in the range 0x0 to 0xF */
    uint32_t    writeCycleTime;
    /**< Total write cycle time in GPMC_FCLK cycles.
         It can take any values in the range 0x0 to 0xF */
    uint32_t    readAccessTime;
    /**< Read access time (Delay between start cycle time
         and first data valid) in GPMC_FCLK cycles.
         It can take any values in the range 0x0 to 0xF */
    uint32_t    pageBurstAccessTime;
    /**< Page burst access time (Delay between successive words in a multiple
         access)in GPMC_FCLK cycles.
         It can take any values in the range 0x0 to 0xF */
}gpmcReadAccessTime_t;

/** \brief Structure defining the Cycle to Cycle delay and Bus turn around
           time for a chip select. */
typedef struct gpmcCycle2CycleDelay
{
    uint32_t    cycle2CycleDelay;
    /**< Cycle to cycle delay value to be set(Chip select high pulse delay
         between two successive accesses)in GPMC_FCLK cycles.
         It can take any values in the range 0x0 to 0xF */
    gpmcCycleDelaySameChipSel_t    cycleDelaySameChipSel;
    /**< Value to control adding of cycle2cycle delay between two successive
         accesses to the same chip select. This can take any of the values
         from the following enum #gpmcCycleDelaySameChipSel_t */
    gpmcCycleDelayDiffChipSel_t    cycleDelayDiffChipSel;
    /**< Value to control adding of cycle2cycle delay between two successive
         accesses to the different chip select. This can take any of the values
         from the following enum #gpmcCycleDelayDiffChipSel_t */
    uint32_t    busTurnAroundTime;
    /**< Bus turn around time between two successive
         accesses to the same chip-select (read to write)
         or to a different chip-select(read to read and read to write)
         in GPMC_FCLK cycles.
         It can take any values in the range 0x0 to 0xF */
}gpmcCycle2CycleDelay_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This API returns the Revision Number of the GPMC module.
 *
 * \param  baseAddr   Memory address of the GPMC module.
 *
 * \retval revision   The value holding the Revision Number of the module
 *                    including the major and minor revision number.
 */
uint32_t GPMCGetRevision(uint32_t baseAddr);

/**
 * \brief    This API performs a module reset of the GPMC module.
 *
 * \param    baseAddr    Memory address of the GPMC module.
 */
void GPMCModuleReset(uint32_t baseAddr);

/**
 * \brief    This API returns the status of the Module reset operation.
 *
 * \param    baseAddr    Memory address of the GPMC module.
 *
 * \retval   TRUE   if the module reset is complete.
 * \retval   FALSE  if the module reset is on going.
 */
uint32_t GPMCIsModuleResetDone(uint32_t baseAddr);

/**
 *  \brief    This API sets the Address/Data Mux type.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    muxType     is the Address/Data mux type to be set.
 *            'muxType' can take any of the values from the following enum
 *            - #gpmcMuxType_t
 */
void GPMCSetAddrDataMuxType(uint32_t baseAddr,
                            uint32_t csNum,
                            uint32_t muxType);

/**
 *  \brief    This API sets the Device type for a particular chip select of the
 *            the GPMC module
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    devType     The type of the device which has to be interfaced.
 *            'devType' can take any of the values from the following enum
 *            - #gpmcDevType_t
 */
void GPMCSetDevType(uint32_t baseAddr, uint32_t csNum, uint32_t devType);

/**
 *  \brief    This API sets the Device size for a particular chip select of the
 *            the GPMC module.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    devSize     The size of the device which is interfaced.
 *            'devSize' can take any of the values from the following enum
 *            - #gpmcDevSize_t
 */
void GPMCSetDevSize(uint32_t baseAddr, uint32_t csNum, uint32_t devSize);

/**
 *  \brief    This API sets the device Page Length.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    pageLen   Device Page Length
 *            'pageLen' can take any of the values from the following enum
 *            - #gpmcDevPageLen_t
 */
void GPMCSetDevPageLength(uint32_t baseAddr, uint32_t csNum, uint32_t pageLen);

/**
 *  \brief    This API sets the GPMC access mode to Single/Multiple Access for
 *            the Read/Write operations of the GPMC.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    csNum         Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    operMode      The GPMC operational mode for which the access mode
 *                          is to be set.
 *            'operMode' can take any of the values from the following enum
 *            - #gpmcOperMode_t
 *  \param    accessMode    The mode to be set for the Read/Write operation.
 *            'accessMode' can take any of the values from the following enum
 *            - #gpmcAccessMode_t
 */
void GPMCSetAccessMode(uint32_t baseAddr,
                       uint32_t csNum,
                       uint32_t operMode,
                       uint32_t accessMode);

/**
 *  \brief    This API sets the access type to either the Synchronous or
 *            Asynchronous for the Read/Write operations of the GPMC.
 *
 *  \param    baseAddr     Memory address of the GPMC module.
 *  \param    csNum        Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    accessType   The access type for read/write operations
 *            'accessType' can take any of the values from the following enum
 *            - #gpmcAccessType_t
 */
void GPMCSetAccessType(uint32_t baseAddr,
                       uint32_t csNum,
                       uint32_t accessType);

/**
 *  \brief    This API enables/disables the Synchronous Wrap burst capability.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    csNum        Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    enableWrapBurst   Value to control enabling/disabling of Wrap
 *            burst feature.
 *            'enableWrapBurst' can take any of the following two values
 *            - TRUE to enable the Wrap burst feature.
 *            - FALSE to disable the Wrap busrt feature.
 */
void GPMCSyncWrapBurstEnable(uint32_t baseAddr,
                             uint32_t csNum,
                             uint32_t enableWrapBurst);

/**
 *  \brief    This API sets the base Address for the selected chip select
 *            number.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    addr        The chip select Base Address to be set.
 *            'addr' can take any of the values from the following
 *             from 0 to 0x3F
 */
void GPMCSetChipSelBaseAddr(uint32_t baseAddr, uint32_t csNum, uint32_t addr);

/**
 *  \brief    This API sets the Mask Address for the selected chip select
 *            number.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    maskAddr    The chip select Mask Address to be set.
 *            'maskAddr' can take any of the values from the following enum
 *            - #gpmcMaskAddr_t
 */
void GPMCSetChipSelMaskAddr(uint32_t baseAddr,
                            uint32_t csNum,
                            uint32_t maskAddr);

/**
 *  \brief    This API controls enabling/disabling of a particular chip select
 *            number.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip Select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    enableChipSel  Value to control enabling/disabling of the chip
 *            select number.
 *            'enableChipSel' can take any of the following two macros
 *            - TRUE to enable the particular chip select number
 *            - FALSE to disable the particular chip select number
 */
void GPMCChipSelEnable(uint32_t baseAddr,
                       uint32_t csNum,
                       uint32_t enableChipSel);

/**
 *  \brief    This API sets the clock divider for GPMC functional clock
 *            which is used as the base for all timing values for read/write
 *            accesses.
 *
 *  \param    baseAddr       Memory address of the GPMC module.
 *  \param    csNum          Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    dividerVal     The divider value for the functional clock.
 *            'dividerVal' can take any of the values from the following enum
 *            - #gpmcFclkDivider_t
 */
void GPMCSetFclkDivider(uint32_t baseAddr, uint32_t csNum, uint32_t dividerVal);

/**
 *  \brief    This API sets the Time Granularity scaling factor which sets the
 *            latency for all the timing signal values.
 *
 *  \param    baseAddr       Memory address of the GPMC module.
 *  \param    csNum          Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    scaleFactor    the value to decide the latency factor for all the
 *            timing values for GPMC.
 *            'scaleFactor' can take any of the values from the following
 *            enum #gpmcTimeGranularity_t
 */
void GPMCSetTimeParaGranularity(uint32_t baseAddr,
                                uint32_t csNum,
                                uint32_t scaleFactor);

/**
 *  \brief    This API sets the Output Clock Activation time for the selected
 *            chip select Number.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    clkActTime  value to set the clock activation time.
 *            'clkActTime' can take any of the values from the following
 *            enum #gpmcClkActTime_t
 */
void GPMCSetClkActivationTime(uint32_t baseAddr,
                              uint32_t csNum,
                              uint32_t clkActTime);

/**
 *  \brief    This API configures the Timing Parameters for the Chip Select
 *            signal.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    csNum         Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    pTimingParams  Pointer to the structure #gpmcChipSelTimingParams_t
 *                           holding the chip select timing parameters.
 */
void GPMCChipSelectTimingConfig(uint32_t baseAddr,
                                uint32_t csNum,
                                gpmcChipSelTimingParams_t *pTimingParams);

/**
 *  \brief    This API configures the Timing Parameters for the Address Latch
 *            Enable(ALE)/ Address Valid(ADV) signal parameters.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    csNum         Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    pTimingParams  Pointer to the structure
 *                           #gpmcAdvSignalTimingParams_t holding the ADV/ALE
 *                           timing parameters.
 */
void GPMCAdvSignalTimingConfig(uint32_t baseAddr,
                               uint32_t csNum,
                               gpmcAdvSignalTimingParams_t *pTimingParams);

/**
 *  \brief    This API configures the Timing Parameters for the Write Enable(WE)
 *            Output Enable(OE) signal timing parameters.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    csNum         Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    pTimingParams  Pointer to the structure
 *                           #gpmcOeWeSignalTimingParams_t holding the
 *                           Output Enable/Write Enable timing parameters.
 */
void GPMCWeOeSignalTimingConfig(uint32_t baseAddr,
                                uint32_t csNum,
                                gpmcOeWeSignalTimingParams_t *pTimingParams);

/**
 *  \brief    This API configures the ReadAccessTime for the chip select.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    pTimingParams  Pointer to the structure
 *                           #gpmcReadAccessTime_t holding the read access
 *                           timing parameters.
 */
void GPMCReadAccessTimingConfig(uint32_t baseAddr,
                                uint32_t csNum,
                                gpmcReadAccessTime_t *pTimingParams);

/**
 *  \brief    This API configures the WriteAccessTime for the chip select.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    wrAccessTime  Write Access time(Delay from StartAccessTime to the
 *                          GPMC_FCLK rising edge corresponding to the GPMC_FCLK
 *                          used by the attached memory for the first data
 *                          capture.
 *            'wrAccessTime' can take any values in the range 0x0 to 0xF
 *  \param    wrDataOnAdMuxBus Specifies on which GPMC_FCLK rising edge the
 *                             first data of the synchronous burst write is
 *                             driven in the addr/data multiplexed bus.
 *            'wrDataOnAdMuxBuse' can take any values in the range 0x0 to 0xF
 */
void GPMCWriteAccessTimingConfig(uint32_t baseAddr,
                                    uint32_t csNum,
                                    uint32_t wrAccessTime,
                                    uint32_t wrDataOnAdMuxBus);

/**
 *  \brief    This API configures the Cycle2Cycle delay and Bus turn around
 *            time for two successive accesses to the selected chip select.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    pTimingParams  Pointer to the structure
 *                           #gpmcCycle2CycleDelay_t holding the
 *                           Output Enable/Write Enable timing parameters.
 */
void GPMCCycleDelayTimingConfig(uint32_t baseAddr,
                                uint32_t csNum,
                                gpmcCycle2CycleDelay_t *pTimingParams);

/**
 *  \brief    This API writes the NAND device command to the command register.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    command     The NAND device command to write.
 */
void GPMCNandCmdWrite(uint32_t baseAddr, uint32_t csNum, uint32_t command);

/**
 *  \brief    This API writes the NAND address to the Address register.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    addr        The NAND device address to write.
 */
void GPMCNandAddrWrite(uint32_t baseAddr, uint32_t csNum, uint32_t addr);

/**
 *  \brief    This API writes the NAND data to the data register.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    data     The data to be written to the NAND device.
 */
void GPMCNandDataWrite(uint32_t baseAddr, uint32_t csNum, uint32_t data);

/**
 *  \brief    This API reads the NAND data from the data register.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *
 *  \retval   data     The data read from the NAND data register.
 */
uint32_t GPMCNandDataRead(uint32_t baseAddr, uint32_t csNum);

/**
 *  \brief    This API controls enabling/disabling of the limited device address
 *            support feature.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    enableLimitAddrSupp       Value to control enabling/disabling
 *            of limited address support.
 *            'enableLimitAddrSupp' can take any of the following values
 *            - TRUE to enable limited address device support
 *            - FALSE to disable limited address device support
 */
void GPMCLimitedAddrSupportEnable(uint32_t baseAddr,
                                  uint32_t enableLimitAddrSupp);

/**
 *  \brief    This API controls enabling/disabling of the NAND force posted
 *            write feature.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    enableForcePostedWrite     Value to control enabling/disabling
 *                                       of force posted write feature
 *            'enableLimitAddrSupp' can take any of the following values
 *            - TRUE to enable force posted write feature
 *            - FALSE to disable force posted write feature
 */
void GPMCNandForcePostedWriteEnable(uint32_t baseAddr,
                                    uint32_t enableForcePostedWrite);

/**
 *  \brief    This API selects the Wait pin for the chip select.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    waitPinNum  The Wait pin to be configured.
 *            'waitPinNum' can take any of the values from the following enum
 *            - #gpmcWaitPinNum_t
 */
void GPMCWaitPinSelect(uint32_t baseAddr, uint32_t csNum, uint32_t waitPinNum);

/**
 *  \brief    This API sets the Wait pin polarity.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    waitPin     The Wait pin to be configured.
 *            'waitPin' can take any of the values from the following enum
 *            - #gpmcWaitPinNum_t
 *  \param    polarity    The polarity of the wait pin to be configured.
 *            'polarity' can take any of the values from the following enum
 *            - #gpmcWaitPinPol_t
 */
void GPMCSetWaitPinPol(uint32_t baseAddr, uint32_t waitPin, uint32_t polarity);

/**
 *  \brief    This API returns the Wait pin status, i.e. whether the pin is
 *            asserted to high or low state.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    waitPin     The Wait pin whose status is to be known
 *            'waitPin' can take any of the values from the following enum
 *            - #gpmcWaitPinNum_t
 *
 *  \retval   status    The status of the particular waitpin passed.
 *            'status' can be any of the values from the following enum
 *            - #gpmcWaitPinSts_t
 */
uint32_t GPMCWaitPinStatus(uint32_t baseAddr, uint32_t waitPin);

/**
 *  \brief    This API controls enabling/disabling of the Wait pin monitoring
 *            feature for Read and Write access of the GPMC.
 *
 *  \param    baseAddr      Memory address of the GPMC.
 *  \param    csNum         Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    operMode      Read/Write Operational mode for which pin monitoring
 *                          is to be enabled/disabled
 *            'operMode' can take any of the values from the following enum
 *             #gpmcOperMode_t
 *  \param    waitPinMonitor  is the value which controls whether the monitoring
 *            of the waitpin monitoring is to be enabled for Read/Write access.
 *            'waitPinMonitor' can take any of the following values from the
 *            following enum -#gpmcWaitPinMonitor_t
 */
void GPMCWaitPinMonitoringEnable(uint32_t baseAddr,
                                 uint32_t csNum,
                                 uint32_t operMode,
                                 uint32_t waitPinMonitor);

/**
 *  \brief    This API sets the waitpin monitoring time for the selected
 *            chip select Number.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *  \param    waitPinTime  value to set the wait pin monitoring time.
 *            'waitPinTime' can take any of the values from the following
 *            enum #gpmcWaitPinTime_t
 */
void GPMCSetWaitPinMonitoringTime(uint32_t baseAddr,
                                  uint32_t csNum,
                                  uint32_t waitPinTime);

/**
 *  \brief    This API sets the Write Protect Pin level to either high or low.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    pinLevel    pin level to be set
 *            'pinLevel' can take any of the values from the following enum
 *            - #gpmcWriteProtectPinLvl_t
 */
void GPMCSetWriteProtectPinLvl(uint32_t baseAddr, uint32_t pinLevel);

/**
 *  \brief    This API returns the empty status of the write buffer.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *
 *  \retval   TRUE  If the Write Buffer is empty
 *  \retval   FALSE If the Write Buffer is not empty
 */
uint32_t GPMCIsWriteBufEmpty(uint32_t baseAddr);

/**
 *  \brief    This API enables the specified interrupts for GPMC module.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    intrMask    Mask value specifying the GPMC interrupts to be
 *                        enabled.
 *            'intrMask' can take any of the values from the following enum
 *            - #gpmcIntrMask_t
 */
void GPMCIntrEnable(uint32_t baseAddr, uint32_t intrMask);

/**
 *  \brief    This API disables the specified interrupts for GPMC module.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    intrMask    Mask value specifying the GPMC interrupts to be
 *                        disabled.
 *            'intrMask' can take any of the values from the following enum
 *            - #gpmcIntrMask_t
 */
void GPMCIntrDisable(uint32_t baseAddr, uint32_t intrMask);

/**
 *  \brief    This API returns the status of GPMC interrupts.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *
 *  \retval   status     The status of GPMC interrupts. This can be any of the
 *                       values from the following enum #gpmcIntrMask_t
 *
 *  \note    To Check the status of a specific interrupt AND the return value
 *           of the API with specific macro from the following enum
 *           - #gpmcIntrMask_t
 */
uint32_t GPMCIntrStatus(uint32_t baseAddr);

/**
 *  \brief    This API clears the status of GPMC interrupts.
 *
 *  \param    baseAddr   Memory address of the GPMC module.
 *  \param    intrMask   Mask specifying which interrupts have to be cleared.
 *            'intrMask' can take any of the values from the following enum
 *            - #gpmcIntrMask_t
 */
void GPMCIntrClear(uint32_t baseAddr, uint32_t intrMask);

/**
 *  \brief    This API controls the enabling/disabling of the timeout feature.
 *
 *  \details  When enabled the counter starts at start-cycle time until it
 *            reaches 0 and if data is not responded to from the memory a
 *            timeout error occurs.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    enableTimeout  The value to specifying enabling/disabling of the
 *            timeout feature of the GPMC.
 *            'enableTimeout' can take any of the following values
 *            - TRUE to enable the timeout feature.
 *            - FALSE to disable the timeout feature.
 */
void GPMCTimeoutEnable(uint32_t baseAddr, uint32_t enableTimeout);

/**
 *  \brief    This API sets the timeout value for the timeout counter of GPMC.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    timeoutVal    The timeout value in GPMC_FCLK cycles
 *            'timeoutVal' can take any of the values in the range
 *             0x01 to 0x1FF
 */
void GPMCSetTimeoutVal(uint32_t baseAddr, uint32_t timeoutVal);

/**
 *  \brief    This API returns the address of illegal access where an error
 *            occurred.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *
 *  \retval   errAddr       Address of illegal access.
 */
uint32_t GPMCGetErrAddr(uint32_t baseAddr);

/**
 *  \brief    This API returns the system command of the transaction that caused
 *            the error.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *
 *  \retval   sysCmd        System command that caused the error.
 */
uint32_t GPMCGetErrSysCmd(uint32_t baseAddr);

/**
 *  \brief    This API checks whether the error fields set are valid or
 *            not and returns the status.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *
 *  \retval   TRUE  If all the error fields are valid.
 *  \retval   FALSE If all the error fields are not valid.
 */
uint32_t GPMCIsErrValid(uint32_t baseAddr);

/**
 *  \brief    This API returns the Error status.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *
 *  \retval   errStatus     The error Status.
 *            'errStatus' can be any of the values from the following enum
 *            - #gpmcErrMask_t
 */
uint32_t GPMCErrStatus(uint32_t baseAddr);

/**
 *  \brief    This API sets the access modes to either PREFETCH read or
 *            POSTWRITE mode.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    accessMode  The access mode to be set for the engine.
 *            'accessMode' can take any of the values from the following enum
 *            - #gpmcPrefetchEngMode_t
 */
void GPMCSetPrefetchAccessMode(uint32_t baseAddr, uint32_t accessMode);

/**
 *  \brief    This API selects the Chip Select(CS) for which the
 *            PREFETCH/POSTWRITE engine must be active.
 *
 *  \param    baseAddr        Memory address of the GPMC module.
 *  \param    prefetchCSNum   The chip select number for which the PREFETCH
 *                            POSTWRITE engine must be active.
 *            'prefetchCSNum' can take any of the values from the following enum
 *            - #gpmcPrefetchChipSel_t
 */
void GPMCSetPrefetchChipSel(uint32_t baseAddr, uint32_t prefetchCSNum);

/**
 *  \brief    This API enables the synchronization type of the Prefetch engine
 *            to either DMA request or an Interrupt request after the data in
 *            the FIFO crosses the threshold.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    syncType    The value to set the appropriate synchronisation type.
 *            'syncType' can take any of the values from the following enum
 *            - #gpmcPrefetchSyncType_t
 */
void GPMCSetPrefetchSyncType(uint32_t baseAddr, uint32_t syncType);

/**
 *  \brief    This API controls the start of access to a particular chip select.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    syncMode    the synchronization mode.
 *            'syncMode' can take any of the values from the following enum
 *            - #gpmcSyncMode_t
 */
void GPMCSetPrefetchSyncMode(uint32_t baseAddr, uint32_t syncMode);

/**
 *  \brief    This API sets the FIFO threshold for the PREFETCH/POSTWRITE
 *            engine.
 *
 *  \param    baseAddr        Memory address of the GPMC module.
 *  \param    thresholdVal    The FIFO Threshold value
 *            'thresholdVal' can take any of the values in the range
 *            0x0 to 0x40
 */
void GPMCSetPrefetchFifoThreshold(uint32_t baseAddr, uint32_t thresholdVal);

/**
 *  \brief    This API sets the number of bytes to be read or written by the
 *            PREFETCH/POSTWRITE engine to the desired chip select.
 *
 *  \param    baseAddr        Memory address of the GPMC module.
 *  \param    xferCountVal    The FIFO Threshold value
 *            'xferCountVal' can take any of the values in the range
 *            0x0 to 0x2000 i.e. 8KB
 */
void GPMCSetPrefetchXferCountVal(uint32_t baseAddr, uint32_t xferCountVal);

/**
 *  \brief    This API controls the enabling/disabling the Round Robin
 *            Arbitration for Prefetch/Postwrite Engine.
 *
 *  \param    baseAddr           Memory address of the GPMC module.
 *  \param    enableArbitration  The value which controls the enabling/disabling
 *                               of the Round-Robin Arbitration.
 *            'enableArbitration' can take any of the following two values
 *             - TRUE to enable the Round Robin Arbitration.
 *             - FALSE to disable the Round Robin Arbitration.
 */
void GPMCArbitrationEnable(uint32_t baseAddr, uint32_t enableArbitration);

/**
 *  \brief    This API sets the number of accesses to be granted to the
 *            Prefetch/Postwrite Engine when the Round Robin Arbitration is
 *            enabled.
 *
 *  \details  The number of accesses granted to the Prefetch/Postwrite Engine is
 *            one more than the value set through this API.
 *
 *  \param    baseAddr       Memory address of the GPMC module.
 *  \param    accessNum      It sets the number of access to be allowed to the
 *                           Prefetch/Postwrite engine after DMA is serviced.
 *            'accessNum' can take any of the values in the following range
 *            0x0 to 0xF
 */
void GPMCSetPrefetchEngNumAccess(uint32_t baseAddr, uint32_t accessNum);

/**
 *  \brief   This API controls enabling/disabling of access cycle optimization.
 *
 *  \param   baseAddr         Memory address of GPMC module
 *  \param   enableOptAccess  The value which controls enabling/disabling of the
 *                            access cycle optimization.
 *           'enableOptAccess' can take any of the following two values
 *           - TRUE to enable the cycle access optimization
 *           - FALSE to disable the cycle access optimization
 */
void GPMCPrefetchOptAccessEnable(uint32_t baseAddr, uint32_t enableOptAccess);

/**
 *  \brief   This function sets the number of GPMC_FCLK cycles to be subtracted
 *           from RdCycleTime,WrCycleTime, AccessTime, CSRdOffTime, CSWrOffTime,
 *           ADVRdOffTime,ADVWrOffTime, OEOffTime, WEOffTime for PREFETCH
 *           engine cycle optimization.
 *
 *  \param   baseAddr    Memory address of GPMC module
 *  \param   optVal      Cycle optimization value. This can take value from
 *                       0 to 7.
 */
void GPMCSetPrefetchCycleTimeOptVal(uint32_t baseAddr, uint32_t optVal);

/**
 *  \brief    This API controls the enabling/disabling of the PREFETCH/POSTWRITE
 *            engine.
 *
 *  \param    baseAddr              Memory address of the GPMC module.
 *  \param    enablePrefetchEngine  value to control enabling/disabling of the
 *                                  Prefetch or Write-posting engine.
 *            'enablePrefetchEngine' can take any of the two values to control
 *            the access engine.
 *            - TRUE to enable the PREFETCH/POSTWRITE engine
 *            - FALSE to disable the PREFETCH/POSTWRITE engine
 */
void GPMCPrefetchEngineEnable(uint32_t baseAddr, uint32_t enablePrefetchEngine);

/**
 *  \brief    This API starts the PREFETCH Engine and Resets the Pointer to 0.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 */
void GPMCPrefetchEngineStart(uint32_t baseAddr);

/**
 *  \brief    This API stops the PREFETCH Engine.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 */
void GPMCPrefetchEngineStop(uint32_t baseAddr);

/**
 *  \brief    This API returns the status of PREFETCH/POSTWRITE engine.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *
 *  \retval   TRUE      If the engine is running
 *  \retval   FALSE     If the engine is stopped
 */
uint32_t GPMCIsPrefetchEngineRunning(uint32_t baseAddr);

/**
 *  \brief    This API returns the PREFETCH engine FIFO status.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *
 *  \retval   1     If FIFO pointer is greater than the threshold value.
 *  \retval   0     If FIFO pointer is smaller than the threshold value.
 */
uint32_t GPMCPrefetchFifoThresholdStatus(uint32_t baseAddr);

/**
 *  \brief    This API returns the PREFETCH engine FIFO pointer pointing
 *            to the number of bytes available to be read or free empty space
 *            to be written.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *
 *  \retval   fifoPtr       The FIFO pointer value indicating the no of bytes
 *                          available to read or empty space to write.
 */
uint32_t GPMCGetPrefetchFifoPtr(uint32_t baseAddr);

/**
 *  \brief    This function returns the remaining bytes to be read or to be
 *            written by the PREFETCH engine according to the TransferCount
 *            value.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *
 *  \retval   countVal      The remaining bytes to be read or written.
 */
uint32_t GPMCGetPrefetchFifoRemBytes(uint32_t baseAddr);

/**
 *  \brief    This API sets the Chip Select number for which the ECC computation
 *            is required.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    csNum       Chip select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 */
void GPMCSetEccChipSel(uint32_t baseAddr, uint32_t csNum);

/**
 *  \brief    This API selects the column size for ECC computation.
 *
 *  \param    baseAddr     Memory address of the GPMC module.
 *  \param    columnSize   Column size to be set for ECC computation.
 *            'columnSize' can take any of the following values from the
 *            following enum - #gpmcEccColumn_t
 */
void GPMCSetEccColumnSize(uint32_t baseAddr, uint32_t columnSize);

/**
 *  \brief    This API sets the number of sectors to process with the
 *            BCH algorithm.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    numSectors    The number of sectors to be processed using BCH
 *                          algorithm.
 *            'numSectors' can take any of the values in the following
 *            range 0 to 7 to process the sectors.
 */
void GPMCSetEccNumSectors(uint32_t baseAddr, uint32_t numSectors);

/**
 *  \brief    This API sets the BCH Error Correction Capability to be used.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    eccBchCapLvl  The Error correction level to be set.
 *            'eccBchCapLvl' can take any of the values from the following
 *             enum - #gpmcBchCapLvl_t
 */
void GPMCSetBchEccCapability(uint32_t baseAddr, uint32_t eccBchCapLvl);

/**
 *  \brief    This function sets the wrap mode
 *            (Spare area organization definition) for the ECC BCH algorithm.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    wrapModeVal   The wrap mode value to be set.
 *            'wrapModeVal' can take any value in the range 0x0U to 0xFU
 */
void GPMCSetBchWrapModeVal(uint32_t baseAddr, uint32_t wrapModeVal);

/**
 *  \brief    This API sets the Algorithm to be used for ECC calculation.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    eccAlgorithm  The value holding the Algorithm type to be used for
 *                          ECC calculation.
 *            'eccAlgorithm' can take any of the values from the following
 *            enum - #gpmcEccAlgo_t
 */
void GPMCSetEccAlgorithm(uint32_t baseAddr, uint32_t eccAlgorithm);

/**
 *  \brief    This API controls enabling/disabling of the Error Correcting Code
 *            (ECC) calculation feature of the GPMC.
 *
 *  \details  This enables on the fly ECC calculation during data read or data
 *            program operations.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    enableEcc     Controls enabling/disabling of the ECC feature
 *            'enableEcc' can take any of the following 2 values
 *            - TRUE to enable the ECC feature
 *            - FALSE to disable the ECC feature
 */
void GPMCEccEnable(uint32_t baseAddr, uint32_t enableEcc);

/**
 *  \brief    This API clears all the ECC result registers.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 */
void GPMCEccResultRegClear(uint32_t baseAddr);

/**
 *  \brief    This API selects the result register where the ECC computation is
 *            to be stored.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    eccRegNum     The value to select the result register
 *            'eccRegNum' can take any of the values from the following enum
 *            - #gpmcEccResultReg_t
 */
void GPMCEccResultRegSelect(uint32_t baseAddr, uint32_t eccRegNum);

/**
 *  \brief    This API sets the ECC size value.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    eccSizeNum    The ECC size number for which the size value is to
 *                          to be set.
 *            'eccSizeNum' can take any of the values from the following enum
 *            #gpmcEccSizeNum_t
 *  \param    eccSizeVal    The value to be set for the ECC size.
 *            'eccSizeVal' can take any of the values from the following range
 *            0x00 to 0xFF
 */
void GPMCSetEccSize(uint32_t baseAddr,
                    uint32_t eccSizeNum,
                    uint32_t eccSizeVal);

/**
 *  \brief    This API sets the ECC size number for the ECC result register.
 *
 *  \param    baseAddr        Memory address of the GPMC module.
 *  \param    eccResRegNum    The ecc result register number.
 *            'eccResRegNum' can be any of the values from the following enum
 *            - #gpmcEccResultReg_t
 *  \param    eccSizeNum      The ECC size number to be set for the result
 *                            register.
 *            'eccSizeNum' can take any of the values from the following enum
 *            - #gpmcEccSizeNum_t
 */
void GPMCSetEccResultSize(uint32_t baseAddr,
                          uint32_t eccResRegNum,
                          uint32_t eccSizeNum);

/**
 *  \brief    This API returns the ECC result stored in the particular result
 *            register.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    eccResRegNum  The ecc result register number.
 *            'eccResRegNum' can be any of the values from the following enum
 *            - #gpmcEccResultReg_t
 *
 *  \retval   eccResult     The ECC computed value stored in the result
 *                          register.
 */
uint32_t GPMCGetEccResult(uint32_t baseAddr, uint32_t eccResRegNum);

/**
 *  \brief    This API returns the BCH computation result.
 *
 *  \param    baseAddr      Memory address of the GPMC module.
 *  \param    csNum         Chip Select number.
 *            'csNum' can take any of the following values from the following
 *            enum - #gpmcChipSel_t
 *
 *  \param    resIndex      BCH ECC result register index.
 *            'resIndex' can take any value in the range 0 to 6
 *
 *  \retval   bchResult     The BCH ECC result value.
 */
uint32_t GPMCGetBchResult(uint32_t baseAddr, uint32_t csNum, uint32_t resIndex);

/**
* \brief   This API is used to directly pass the data to BCH ECC Calculator
*          without accessing the actual NAND flash interface.
*
* \param    baseAddr       Memory address of the GPMC module.
*
* \param    bchData        BCH data to be included in the BCH calculation.
*
* \note     Only bits 0 to 7 are taken into account, if the calculator is
*           configured to use 8 bits data through #GPMCSetEccColumnSize API.
*/
void GPMCSetEccBchSwData(uint32_t baseAddr, uint16_t bchData);

/**
* \brief   This API returns the data passed directly to the BCH calculator
*          bypassing the NAND flash interface.
*
* \param   baseAddr       Memory address of the GPMC module.
*
* \retval  bchData        The data passed to BCH calculator.
*/
uint16_t GPMCGetEccBchSwData(uint32_t baseAddr);

/**
 *  \brief    This API sets GPMC to one of the Idle modes.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    idleMode    It is the value which determines the type of idle
 *                        mode operation.
 *           'idleMode' can take any of the values from the following enum
 *           - #gpmcIdleMode_t
 */
void GPMCSetIdleMode(uint32_t baseAddr, uint32_t idleMode);

/**
 *  \brief    This API controls enabling/disabling of the the Auto Idle mode.
 *
 *  \param    baseAddr    Memory address of the GPMC module.
 *  \param    enableAutoIdle    Value to control enabling/disabling of
 *                              the auto idle mode.
 *            'enableAutoIdle' can take any of the two values
 *            - TRUE to enable Auto-Idle mode
 *            - FALSE to disable Auto-Idle mode
 */
void GPMCAutoIdleEnable(uint32_t baseAddr, uint32_t enableAutoIdle);


/* ========================================================================== */
/*                     Deprecated Macros                                      */
/* ========================================================================== */


/* ========================================================================== */
/*                     Deprecated Function Declarations                       */
/* ========================================================================== */


#ifdef __cplusplus
}
#endif

#endif
