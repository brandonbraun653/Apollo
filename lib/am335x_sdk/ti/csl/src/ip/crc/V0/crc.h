/*
 *   Copyright (c) Texas Instruments Incorporated 2015 - 2019
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
 *  \ingroup CSL_IP_MODULE
 *  \defgroup CSL_CRC CRC
 *
 *  @{
 */
/**
 *  \file     csl/src/ip/crc/V0/crc.h
 *
 *  \brief    This file contains the prototypes of the APIs present in the
 *            device abstraction layer file of CRC.
 *            This also contains some related macros.
 */

/**
 *         CRC programming sequence:
 *         1. CRCChannelReset()
 *         2. CRCInitialize()
 *         3. CRCConfigure()
 *         4. CRCEnableIntr() - if needed
 *         5. Transfer data to PSA signature for generation of signature value
 *             - DMA is utilized in Semi-CPU mode
 *             - CPU need to pump data into PSA register in Full CPU mode.
 *         6. CRCGetPSASectorSig()
 *             - After complete transfer read CRC signature.
 */
/**
 *         CRC signature generated depends on amount of data copied into
 *         PSA register at a time/in single write. Though data pattern can be
 *         8, 16, 32, or 64 bit, data copied into PSA register is always 64 bit
 *         wide. If data pattern is less than 64 bit, then it is padded with
 *         zeros to make it 64 bit write.
 */
#ifndef CRC_H_
#define CRC_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "ti/csl/cslr_crc.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @defgroup CSL_CRC_API CRC (CRC)
 */
/**
@defgroup CSL_CRC_DATATYPE CRC Data Types
@ingroup CSL_CRC_API
*/
/**
@defgroup CSL_CRC_DATASTRUCT CRC Data Structures
@ingroup CSL_CRC_API
*/
/**
@defgroup CSL_CRC_FUNCTION  CRC Functions
@ingroup CSL_CRC_API
*/

/** ===========================================================================
 *  @addtogroup CSL_CRC_DATATYPE
    @{
 * ============================================================================
 */

/* ========================================================================== */
/*                            Macros & Typedefs                               */
/* ========================================================================== */
/**
 * \brief  Macro defines mask for all the interrupts for a channel.
 */
#define CRC_CHANNEL_IRQSTATUS_RAW_MAIN_ALL   \
    (uint32_t) ((uint32_t)CRC_INTS_CH1_CCITENS_MASK |  \
                (uint32_t)CRC_INTR_CH1_FAILENR_MASK |  \
                (uint32_t)CRC_INTR_CH1_OVERENR_MASK |  \
                (uint32_t)CRC_INTR_CH1_UNDERENR_MASK | \
                (uint32_t)CRC_INTR_CH1_TIME_OUT_ENR_MASK)

/**
 * \brief  Macro defines maximum value of CRC Pattern Count.
 */
#define CRC_PATTERN_COUNT_MAX          (0x000FFFFFU)

/**
 * \brief  Macro defines maximum value of CRC Sector Count.
 */
#define CRC_SECTOR_COUNT_MAX           (0x0000FFFFU)

/**
 * \brief  Macro defines maximum value of CRC Block Complete Timeout Counter
 *         Preload.
 */
#define CRC_BCTOPLD_MAX                (0x00FFFFFFU)

/**
 * \brief  Macro defines maximum value of CRC Watchdog Timeout Counter Preload.
 */
#define CRC_WDTOPLD_MAX                (0x00FFFFFFU)

/**
 * \brief  Max number of channels supported in CRC.
 */
#define CRC_MAX_NUM_OF_CHANNELS        (4U)

/**
 *  \anchor crcOperationMode_t
 *  \name CRC Operation Mode
 *  @{
 */
/**
 * \brief  CRC operation mode supported. CRC can either operate
 *         in Semi-CPU, Full-CPU or Auto mode.
 */
typedef uint32_t crcOperationMode_t;

#define CRC_OPERATION_MODE_DATA        (CRC_CTRL2_CH1_MODE_DATA)
/**< Configure CRC operation mode to Data Captures */
#define CRC_OPERATION_MODE_AUTO        (CRC_CTRL2_CH1_MODE_AUTO)
/**< Configure CRC operation mode to Auto */
#define CRC_OPERATION_MODE_SEMICPU     (CRC_CTRL2_CH1_MODE_SEMICPU)
/**< Configure CRC operation mode to Semi-CPU */
#define CRC_OPERATION_MODE_FULLCPU     (CRC_CTRL2_CH1_MODE_FULLCPU)
/**< Configure CRC operation mode to Full-CPU */
/* @} */

/**
 *  \anchor crcChannel_t
 *  \name CRC channel
 *  @{
 */
/**
 * \brief  CRC channel supported.
 */
typedef uint32_t crcChannel_t;

#define CRC_CHANNEL_1                  (0x1U)
/**< Select channel 1 for operation */
#define CRC_CHANNEL_2                  (0x2U)
/**< Select channel 2 for operation */
#define CRC_CHANNEL_3                  (0x3U)
/**< Select channel 3 for operation */
#define CRC_CHANNEL_4                  (0x4U)
/**< Select channel 4 for operation */

/* @} */

/**
 *  \anchor crcIntrPriority_t
 *  \name CRC Interrupt Priority
 *
 *  The offset for the highest pending priority interrupt. These interrupt
 *  offset returned in #CRCGetHighestPriorityIntrStatus function
 *
 *  @{
 */
/**
 * \brief  The offset for the highest pending priority interrupt. These interrupt
 *         offset returned in #CRCGetHighestPriorityIntrStatus function
 */
typedef uint32_t crcIntrPriority_t;

#define CRC_INTR_PRIORITY_CH1_FAIL                (0x1U)
/**< Offset return for channel 1 fail interrupt */
#define CRC_INTR_PRIORITY_CH2_FAIL                (0x2U)
/**< Offset return for channel 1 fail interrupt */
#define CRC_INTR_PRIORITY_CH3_FAIL                (0x3U)
/**< Offset return for channel 1 fail interrupt */
#define CRC_INTR_PRIORITY_CH4_FAIL                (0x4U)
/**< Offset return for channel 4 fail interrupt */
#define CRC_INTR_PRIORITY_CH1_COMPRESSION_DONE    (0x9U)
/**< Offset return for channel 1 compression done interrupt */
#define CRC_INTR_PRIORITY_CH2_COMPRESSION_DONE    (0xaU)
/**< Offset return for channel 2 compression done interrupt */
#define CRC_INTR_PRIORITY_CH3_COMPRESSION_DONE    (0xbU)
/**< Offset return for channel 3 compression done interrupt */
#define CRC_INTR_PRIORITY_CH4_COMPRESSION_DONE    (0xcU)
/**< Offset return for channel 4 compression done interrupt */
#define CRC_INTR_PRIORITY_CH1_OVERRUN             (0x11U)
/**< Offset return for channel 1 overrun interrupt */
#define CRC_INTR_PRIORITY_CH2_OVERRUN             (0x12U)
/**< Offset return for channel 2 overrun interrupt */
#define CRC_INTR_PRIORITY_CH3_OVERRUN             (0x13U)
/**< Offset return for channel 3 overrun interrupt */
#define CRC_INTR_PRIORITY_CH4_OVERRUN             (0x14U)
/**< Offset return for channel 4 overrun interrupt */
#define CRC_INTR_PRIORITY_CH1_UNDERRUN            (0x19U)
/**< Offset return for channel 1 underrun interrupt */
#define CRC_INTR_PRIORITY_CH2_UNDERRUN            (0x1aU)
/**< Offset return for channel 2 underrun interrupt */
#define CRC_INTR_PRIORITY_CH3_UNDERRUN            (0x1bU)
/**< Offset return for channel 3 underrun interrupt */
#define CRC_INTR_PRIORITY_CH4_UNDERRUN            (0x1cU)
/**< Offset return for channel 4 underrun interrupt */
#define CRC_INTR_PRIORITY_CH1_TIMEOUT             (0x21U)
/**< Offset return for channel 1 timeout interrupt */
#define CRC_INTR_PRIORITY_CH2_TIMEOUT             (0x22U)
/**< Offset return for channel 2 timeout interrupt */
#define CRC_INTR_PRIORITY_CH3_TIMEOUT             (0x23U)
/**< Offset return for channel 3 timeout interrupt */
#define CRC_INTR_PRIORITY_CH4_TIMEOUT             (0x24U)
/**< Offset return for channel 4 timeout interrupt */
/* @} */

/**
 *  \anchor crcDataBusMask_t
 *  \name CRC data bus type mask
 *  @{
 */
/**
 * \brief  CRC data bus type mask selected for tracing control
 */
typedef uint32_t crcDataBusMask_t;

#define CRC_DATA_BUS_ITCM_MASK     (CRC_MCRC_BUS_SEL_ITC_MEN_MASK)
/**< Select tracing control of instruction TCM */
#define CRC_DATA_BUS_DTCM_MASK     (CRC_MCRC_BUS_SEL_DTC_MEN_MASK)
/**< Select tracing control of data TCM */
#define CRC_DATA_BUS_VBUSM_MASK    (CRC_MCRC_BUS_SEL_MEN_MASK)
/**< Select tracing control of VBUSM */
#define CRC_DATA_BUS_MASK_ALL      (CRC_MCRC_BUS_SEL_ITC_MEN_MASK | \
                                    CRC_MCRC_BUS_SEL_DTC_MEN_MASK | \
                                    CRC_MCRC_BUS_SEL_MEN_MASK)
/**< Select tracing control of all data buses */
/* @} */

/** @} */

/** ============================================================================
 *  @addtogroup CSL_CRC_DATASTRUCT
    @{
 * =============================================================================
 */

/* ========================================================================== */
/*                         Structure Declarations                             */
/* ========================================================================== */

/**
 * \brief  Structure for accessing CRC register data which are 64 bit wide.
 */
typedef struct crcSignature
{
    uint32_t regL;
    /**< Lower 32 bits of the 64 bit data of CRC Signature register */
    uint32_t regH;
    /**< Upper 32 bits of the 64 bit data of CRC Signature register */
}crcSignature_t;

/**
 * \brief  Structure for accessing CRC registers address which are 64 bit wide.
 */
typedef struct crcSigantureRegAddr
{
    uint32_t regL;
    /**< Lower 32 bits of the 64 bit CRC Signature register address */
    uint32_t regH;
    /**< Upper 32 bits of the 64 bit CRC Signature register address */
}crcSignatureRegAddr_t;

/**
 * \brief  CRC channel static registers list.
 */
typedef struct {
    volatile uint32_t PCOUNT;
    /**< Pattern Counter Preload Register */
    volatile uint32_t SCOUNT;
    /**< Sector Counter Preload Register */
    volatile uint32_t WDTOPLD;
    /**< Watchdog Timeout Counter Preload Register */
    volatile uint32_t BCTOPLD;
    /**< Block Complete Timeout Counter Preload Register */
} CSL_CrcChannelStaticRegs;

/**
 * \brief  CRC static registers list.
 */
typedef struct {
    CSL_CrcChannelStaticRegs channelRegs[CRC_MAX_NUM_OF_CHANNELS];
    /**< Channel Specific Static Registers */
    volatile uint32_t CTRL0;
    /**< CTRL0 Register */
    volatile uint32_t CTRL1;
    /**< CTRL1 Register */
    volatile uint32_t BUS_SEL;
    /**< Data Bus Tracing Select Register */
} CSL_CrcStaticRegs;

/** @} */

/** ===========================================================================
 *  @addtogroup CSL_CRC_FUNCTION
    @{
 * ============================================================================
 */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   Initialize CRC channel and will configure watchdog and
 *          block preload value for given channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 *
 * \param   channel         Channel number to be initializaed.
 *                          Values given by #crcChannel_t.
 * \param   crcWatchdogPreload
 *                          It is used to check if DMA does supply a block of
 *                          data responding to a request in a given time frame.
 * \param   crcBlockPreload
 *                          It is used to check if CRC for an entire block is
 *                          completed in a given time frame.
 *
 * \return  status          CRC channel initialization status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 *
 */
int32_t CRCInitialize(uint32_t     baseAddr,
                      crcChannel_t channel,
                      uint32_t     crcWatchdogPreload,
                      uint32_t     crcBlockPreload);

/**
 * \brief   Verify the CRC watchdog and block preload value initialized for given
 *          channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 *
 * \param   channel         Channel number to be verified initialization.
 *                          Values given by #crcChannel_t.
 * \param   crcWatchdogPreload
 *                          It is used to check if DMA does supply a block of
 *                          data responding to a request in a given time frame.
 * \param   crcBlockPreload
 *                          It is used to check if CRC for an entire block is
 *                          completed in a given time frame.
 *
 * \return  status          CRC channel verfiy initialization status.
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *                          CSL_EFAIL:    failure, indicate verify initialization failed
 *
 *
 */
int32_t CRCVerifyInitialize(uint32_t     baseAddr,
                            crcChannel_t channel,
                            uint32_t     crcWatchdogPreload,
                            uint32_t     crcBlockPreload);

/**
 * \brief   This API will configure CRC mode, pattern and sector count for
 *          given channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number to be configured.
 *                          Values given by #crcChannel_t.
 * \param   crcPatternCount Number of data patterns in one sector to be compressed.
 * \param   crcSectorCount  Number of sectors in a block of memory.
 * \param   crcMode         CRC operational mode.
 *                          Refer #crcOperationMode_t.
 *
 * \return  status          CRC channel configuration status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 *
 */
int32_t CRCConfigure(uint32_t           baseAddr,
                     crcChannel_t       channel,
                     uint32_t           crcPatternCount,
                     uint32_t           crcSectorCount,
                     crcOperationMode_t crcMode);

/**
 * \brief   This API will verify the configure of CRC mode, pattern and sector
 *           count for given channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number to be verified configuration.
 *                          Values given by #crcChannel_t.
 * \param   crcPatternCount Number of data patterns in one sector to be compressed.
 * \param   crcSectorCount  Number of sectors in a block of memory.
 * \param   crcMode         CRC operational mode.
 *                          Refer #crcOperationMode_t.
 *
 * \return  status          CRC channel configuration status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *                          CSL_EFAIL:    failure, indicate verify configure failed
 *
 *
 */
int32_t CRCVerifyConfigure(uint32_t           baseAddr,
                           crcChannel_t       channel,
                           uint32_t           crcPatternCount,
                           uint32_t           crcSectorCount,
                           crcOperationMode_t crcMode);

/**
 * \brief   This API is used to reset the CRC channel
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which reset is to be done.
 *                          Values given by #crcChannel_t.
 *
 * \return  status          CRC channel reset status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCChannelReset(uint32_t     baseAddr,
                        crcChannel_t channel);

/**
 * \brief   This API is used to get the PSA register address for given Channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which PSA register address is
 *                          to get.
 *                          Values given by #crcChannel_t.
 * \param   pCRCRegAddr     Pointer to CRC PSA register address structure.
 *                          Refer structure #crcSignatureRegAddr_t.
 *
 * \return  status          CRC channel get PSA signature register address status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCGetPSASigRegAddr(uint32_t               baseAddr,
                            crcChannel_t           channel,
                            crcSignatureRegAddr_t *pCRCRegAddr);

/**
 * \brief   This API is used to get the PSA register value for given Channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which PSA register data is to get.
 *                          Values given by #crcChannel_t.
 * \param   pCRCPSASign     Pointer to CRC PSA signature values.
 *                          Refer struct #crcSignature_t.
 *
 * \return  status          CRC channel get PSA signature register value status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 *
 */
int32_t CRCGetPSASig(uint32_t        baseAddr,
                     crcChannel_t    channel,
                     crcSignature_t *pCRCPSASign);

/**
 * \brief   This API is used to set the PSA seed value without compression
 *          for given Channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which PSA seed value to be set.
 *                          Values given by #crcChannel_t.
 * \param   pCRCPSASeedSign Pointer to CRC PSA seed signature values.
 *                          Refer struct #crcSignature_t for details.
 *
 * \return  status          CRC channel set PSA seed value status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCSetPSASeedSig(uint32_t              baseAddr,
                         crcChannel_t          channel,
                         const crcSignature_t *pCRCPSASeedSign);

/**
 * \brief   This API is used to get sector signature Value/
 *          CRC value for given channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number which was configured for CRC calculation.
 *                          Values given by #crcChannel_t.
 * \param   pCRCSectorSign  Pointer to CRC PSA sector signature values
 *                          Refer struct #crcSignature_t.
 *
 * \return  status          CRC channel get PSA sector signaure value status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCGetPSASectorSig(uint32_t        baseAddr,
                           crcChannel_t    channel,
                           crcSignature_t *pCRCSectorSign);

/**
 * \brief   This API is used to get the pending interrupt with highest priority
 *
 * \param   baseAddr        Base address of the CRC registers.
 *
 * \param   pIntVecAddr     Pointer to highest priority pending interrupt vector address
 *                          defined in #crcIntrPriority_t
 *
 * \return  status          CRC get interrupt vector address status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCGetHighestPriorityIntrStatus(uint32_t baseAddr, uint32_t *pIntVecAddr);

/**
 * \brief   This API is used to get the pending interrupts for given Channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which pending interrupt is to get.
 *                          Values given by #crcChannel_t.
 *
 * \param   pIntrStatus     Pointer to pending interrupt status/occurred.
 *
 * \return  status          CRC get pending interrupts status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCGetIntrStatus(uint32_t      baseAddr,
                         crcChannel_t  channel,
                         uint32_t     *pIntrStatus);

/**
 * \brief   This API is used to enable interrupts for given Channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which interrupt is to enable.
 *                          Values given by #crcChannel_t.
 * \param   intrMask        Interrupts to enable.
 *
 * \return  status          CRC enable interrupts status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCEnableIntr(uint32_t     baseAddr,
                      crcChannel_t channel,
                      uint32_t     intrMask);

/**
 * \brief   This API is used to disable interrupts for given Channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which interrupt is to disable.
 *                          Values given by #crcChannel_t.
 * \param   intrMask        Interrupts to disable.
 *
 * \return  status          CRC disable interrupts status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCDisableIntr(uint32_t     baseAddr,
                       crcChannel_t channel,
                       uint32_t     intrMask);

/**
 * \brief   This API is used to clear interrupts for given Channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which interrupt is to clear.
 *                          Values given by #crcChannel_t.
 * \param   intrMask        Interrupts to clear status.
 *
 * \return  status          CRC clear interrupts status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCClearIntr(uint32_t     baseAddr,
                     crcChannel_t channel,
                     uint32_t     intrMask);

/**
 * \brief   This API is used to control the power down of the CRC module
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   ctrlFlag        Pointer to power control flag.
 *                          CSL_TRUE:  power down the CRC.
 *                          CSL_FALSE: power on the CRC.
 *
 * \return  status          CRC power control status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCPowerDownCtrl(uint32_t baseAddr,
                         uint32_t ctrlFlag);

/**
 * \brief   This API is used to check if CRC is busy for given Channel.
 *
 *   @n  During Auto or Semi-CPU mode, the busy flag is set when the first data
 *       pattern of the block is compressed and remains set until the the last
 *       data pattern of the block is compressed. The flag is cleared when the
 *       last data pattern of the block is compressed.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which busy status is to get.
 *                          Values given by #crcChannel_t.
 *
 * \param   pBusyFlag       Pointer to busy flag.
 *                          CSL_TRUE:  CRC channel is busy.
 *                          CSL_FALSE: CRC channel is free.
 *
 * \return  status          CRC channel check busy status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCIsBusy(uint32_t      baseAddr,
                  crcChannel_t  channel,
                  uint32_t     *pBusyFlag);

/**
 * \brief   This API is used to get the current sector number of which the
 *          signature verification fails in AUTO mode for given channel
 *
 *   @n  When a sector fails, the erroneous sector number is logged and the CRC
 *       fail interrupt is generated.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which the curent sector number is to get.
 *                          Values given by #crcChannel_t.
 * \param   pCurSecNum      Pointer to current sector number.
 *
 * \return  status          CRC channel get current sector number status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCGetCurSecNum(uint32_t        baseAddr,
                        crcChannel_t    channel,
                        uint32_t       *pCurSecNum);

/**
 * \brief   This API is used to get current known good signature value/
 *          CRC value for given channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which current CRC value is to get.
 *                          Values given by #crcChannel_t.
 * \param   pCurPSASig      Pointer to current CRC PSA signature values
 *                          Refer struct #crcSignature_t.
 *
 * \return  status          CRC channel get current PSA signaure value status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCGetCurPSASig(uint32_t        baseAddr,
                        crcChannel_t    channel,
                        crcSignature_t *pCurPSASig);

/**
 * \brief   This API is used to get the uncompressed raw data value for given channel.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   channel         Channel number for which raw data value is to get.
 *                          Values given by #crcChannel_t.
 * \param   pRawData        Pointer to raw data value
 *                          Refer struct #crcSignature_t.
 *
 * \return  status          CRC channel get raw data value status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCGetRawData(uint32_t        baseAddr,
                      crcChannel_t    channel,
                      crcSignature_t *pRawData);

/**
 * \brief   This API is used to control the CRC data bus tracing.
 *
 *   @n  Data tracing is only available on channel 1, when it is enabled, the
 *       operation mode is automatically reset to data capture mode on channel 1
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   ctrlFlag        Data bus tracing control flag.
 *                          CSL_TRUE:  enable data tracing.
 *                          CSL_FALSE: disable data tracing.
 * \param   dataBusMask     Data bus mask bits for which what data buses are to be
 *                          selected. Values given by #crcDataBusMask_t.
 * \param   busEnableMask   Data bus enable mask bits for which what data buses are to
 *                          be enabled or disabled. Values given by #crcDataBusMask_t.
 *
 * \return  status          CRC data bus tracing control status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *
 */
int32_t CRCDataBusTracingCtrl(uint32_t         baseAddr,
                              uint32_t         ctrlFlag,
                              crcDataBusMask_t dataBusMask,
                              crcDataBusMask_t busEnableMask);

/**
 * \brief   This API is used to verify the control the CRC data bus tracing.
 *
 * \param   baseAddr        Base address of the CRC registers.
 * \param   ctrlFlag        Data bus tracing control flag.
 *                          CSL_TRUE:  enable data tracing.
 *                          CSL_FALSE: disable data tracing.
 * \param   dataBusMask     Data bus mask bits for which what data buses are to be
 *                          selected. Values given by #crcDataBusMask_t.
 * \param   busEnableMask   Data bus enable mask bits for which what data buses are to
 *                          be enabled or disabled. Values given by #crcDataBusMask_t.
 *
 * \return  status          CRC verify data bus tracing control status
 *                          CSL_PASS:     success
 *                          CSL_EBADARGS: failure, indicate the bad input arguments
 *                          CSL_EFAIL:    failure, indicate verify failed
 *
 */
int32_t CRCVerifyBusTracingCtrl(uint32_t         baseAddr,
                                uint32_t         ctrlFlag,
                                crcDataBusMask_t dataBusMask,
                                crcDataBusMask_t busEnableMask);

/**
 * \brief   This API is used to read static registers of CRC module.
 *          This API needs to be called after the initial configuration is done and
 *          hence mutliple read between static registers do not change the values
 *
 * \param   baseAddr        Base Address of the CRC Registers.
 *
 * \param   pStaticRegs     pointer to static registers to be read
 *
 * \return                  CSL_PASS - success
 * @n                       CSL_EBADARGS - API fails due to bad input arguments
 *
 */
int32_t CRCReadStaticRegs (uint32_t           baseAddr,
                           CSL_CrcStaticRegs *pStaticRegs);

/** @} */

#ifdef __cplusplus
}

#endif /*extern "C" */

#endif
 /** @} */
