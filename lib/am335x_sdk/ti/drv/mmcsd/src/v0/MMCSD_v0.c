/**
 *  \file   MMCSD_v0.c
 *
 *  \brief  IP version 0 specific MMCSD Driver APIs implementation.
 *
 *   This file contains the driver APIs for MMCSD controller.
 */

/*
 * Copyright (C) 2017 - 2018 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#include<stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_error.h>
#include <ti/csl/csl_chip.h>
#include <ti/csl/csl_mmcsd.h>
#include <ti/drv/mmcsd/src/MMCSD_drv_log.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_v0.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
#include <ti/drv/mmcsd/src/v0/MMCSD_v0_lld.h>
#include <ti/drv/mmcsd/src/MMCSD_osal.h>
#ifdef MMCSD_EDMA_ENABLED
#include <ti/sdo/edma3/drv/edma3_drv.h>
#endif

#define MMCSD_log                UART_printf

/** \brief Bit mask. */
#define BIT(x) (((uint32_t)1U) << (x))

/**
 * SD Card information structure
 */

/** \brief SD Commands enumeration. */
#define MMCSD_CMD(x)   (x)

/**
 * Command/Response flags for notifying some information to controller
 */

/** \brief To indicate no response. */
#define MMCSD_CMDRSP_NONE           (BIT(0U))

/** \brief Response to indicate stop condition. */
#define MMCSD_CMDRSP_STOP           (BIT(1U))

/** \brief Response to indicate stop condition. */
#define MMCSD_CMDRSP_FS             (BIT(2U))

/** \brief Response to indicate abort condition. */
#define MMCSD_CMDRSP_ABORT          (BIT(3U))

/** \brief Response to indicate bust state. */
#define MMCSD_CMDRSP_BUSY           (BIT(4U))

/** \brief Command to configure for 48bit R1 response */
#define MMCSD_CMDRSP_48BITS         (BIT(9U))

/** \brief Command to configure for 136 bits data width. */
#define MMCSD_CMDRSP_136BITS        (BIT(5U))

/** \brief Command to configure for data or response. */
#define MMCSD_CMDRSP_DATA           (BIT(6U))

/** \brief Command to configure for data read. */
#define MMCSD_CMDRSP_READ           (BIT(7U))

/** \brief Command to configure for data write. */
#define MMCSD_CMDRSP_WRITE          (BIT(8U))

/** \brief SD voltage enumeration as per VHS field, after the CHECK PATTERN FIELD */
#define MMCSD_VOLT_2P7_3P6          (0x000100U)
#define MMCSD_VOLT_LOW_RANGE        (0x000200U)

/**
 * SD OCR register definitions.
 */

/** \brief High capacity card type. */
#define MMCSD_OCR_HIGH_CAPACITY     (BIT(30U))

/** \brief MMCSD card busy bit */
#define MMCSD_CARD_BUSY_BIT          (BIT(31U))

#define MMCSD_OCR_S18R  (BIT(24U))
/**
 * Voltage configurations.
 */

#define MMCSD_DTOUT  (0xFFFF)
/**
 * Voltage configurations.
 */

/** \brief Configure for 2.7V to 2.8V VDD level. */
#define MMCSD_OCR_VDD_2P7_2P8       (BIT(15U))

/** \brief Configure for 2.8V to 2.9V VDD level. */
#define MMCSD_OCR_VDD_2P8_2P9       (BIT(16U))

/** \brief Configure for 2.9V to 3.0V VDD level. */
#define MMCSD_OCR_VDD_2P9_3P0       (BIT(17U))

/** \brief Configure for 3.0V to 3.1V VDD level. */
#define MMCSD_OCR_VDD_3P0_3P1       (BIT(18U))

/** \brief Configure for 3.1V to 3.2V VDD level. */
#define MMCSD_OCR_VDD_3P1_3P2       (BIT(19U))

/** \brief Configure for 3.2V to 3.3V VDD level. */
#define MMCSD_OCR_VDD_3P2_3P3       (BIT(20U))

/** \brief Configure for 3.3V to 3.4V VDD level. */
#define MMCSD_OCR_VDD_3P3_3P4       (BIT(21U))

/** \brief Configure for 3.4V to 3.5V VDD level. */
#define MMCSD_OCR_VDD_3P4_3P5       (BIT(22U))

/** \brief Configure for 3.5V to 3.6V VDD level. */
#define MMCSD_OCR_VDD_3P5_3P6       (BIT(23U))

/** \brief Wild card to configure for VDD level. */
#define MMCSD_OCR_VDD_WILDCARD      (((uint32_t)0x1FFU) << 15U)

/** \brief MMC Argument Register value for OCR command. */
#define MMCSD_OCR_AGRHL_REG_VAL      (0x00FF8000)

/** \brief MMC Relative Card Address. */
#define MMCSD_RELATIVE_CARD_ADDRESS  (2U)

/** \brief MMCSD Block Length. */
#define MMCSD_BLOCK_SIZE           (512U)
/**
 * SD CSD register definitions.
 */

/** \brief Card bus frequency configuration for 25 Mbps. */
#define MMCSD_TRANSPEED_25MBPS      (0x32U)

/** \brief Card bus frequency configuration for 50 Mbps. */
#define MMCSD_TRANSPEED_50MBPS      (0x5AU)
/** \brief Gives the card version. */
#define MMCSD_CARD_CMMCSD_VERSION(crd) \
    (((crd)->csd[3U] & 0xC0000000U) >> 30U)

/** \brief Extract the size of device for SD version 0. */
#define MMCSD_CSD0_DEV_SIZE(csd3, csd2, csd1, csd0) \
    ((uint64_t)(((csd2) & 0x000003FFU) << 2U) | (((csd1) & 0xC0000000U) >> 30U))

/** \brief TBD for SD version 0. */
#define MMCSD_CSD0_MULT(csd3, csd2, csd1, csd0) \
    (((csd1) & 0x00038000U) >> 15U)

/** \brief Extract the read block length for SD version 0. */
#define MMCSD_CSD0_RDBLKLEN(csd3, csd2, csd1, csd0) \
    (((csd2) & 0x000F0000U) >> 16U)

/** \brief Extract the card transfer speed for SD version 0. */
#define MMCSD_CSD0_TRANSPEED(csd3, csd2, csd1, csd0) \
    (((csd3) & 0x000000FFU) >> 0U)

/** \brief Extracts the size of card for SD version 0. */
#define MMCSD_CARD0_DEV_SIZE(crd) \
    (MMCSD_CSD0_DEV_SIZE((crd)->csd[3U], (crd)->csd[2U], \
    (crd)->csd[1U], (crd)->csd[0U]))

/** \brief TBD for SD version 0. */
#define MMCSD_CARD0_MULT(crd) \
    (MMCSD_CSD0_MULT((crd)->csd[3U], (crd)->csd[2U], \
    (crd)->csd[1U], (crd)->csd[0U]))

/** \brief Gives the card block length for SD version 0. */
#define MMCSD_CARD0_RDBLKLEN(crd) \
    (MMCSD_CSD0_RDBLKLEN((crd)->csd[3U], (crd)->csd[2U], \
    (crd)->csd[1U], (crd)->csd[0U]))

/** \brief Gives the card transfer speed for SD version 0. */
#define MMCSD_CARD0_TRANSPEED(crd) \
    (MMCSD_CSD0_TRANSPEED((crd)->csd[3U], (crd)->csd[2U], \
    (crd)->csd[1U], (crd)->csd[0U]))

/** \brief Gives number of blocks on card for SD version 0. */
#define MMCSD_CARD0_NUMBLK(crd) \
    ((MMCSD_CARD0_DEV_SIZE((crd)) + 1U) * \
    (((uint32_t)1U) << (MMCSD_CARD0_MULT((crd)) + 2U)))

/** \brief Gives the size of card for SD version 0. */
#define MMCSD_CARD0_SIZE(crd) ((MMCSD_CARD0_NUMBLK((crd))) * \
    (((uint32_t)1U) << (MMCSD_CARD0_RDBLKLEN(crd))))

/** \brief Extracts the size of card for SD version 1. */
#define MMCSD_CSD1_DEV_SIZE(csd3, csd2, csd1, csd0) \
    ((uint64_t)(((csd2) & 0x0000003FU) << 16U) | (((csd1) & 0xFFFF0000U) >> 16U))

/** \brief Extracts the card block length for SD version 1. */
#define MMCSD_CSD1_RDBLKLEN(csd3, csd2, csd1, csd0) \
    (((csd2) & 0x000F0000U) >> 16U)

/** \brief Extracts the card transfer speed for SD version 1. */
#define MMCSD_CSD1_TRANSPEED(csd3, csd2, csd1, csd0) \
    (((csd3) & 0x000000FFU) >> 0U)

/** \brief Gives the size of card for SD version 1. */
#define MMCSD_CARD1_DEV_SIZE(crd) \
    (MMCSD_CSD1_DEV_SIZE((crd)->csd[3U], (crd)->csd[2U], \
    (crd)->csd[1U], (crd)->csd[0U]))

/** \brief Reads the card block length for SD version 1. */
#define MMCSD_CARD1_RDBLKLEN(crd) \
    (MMCSD_CSD1_RDBLKLEN((crd)->csd[3U], (crd)->csd[2U], \
    (crd)->csd[1U], (crd)->csd[0U]))

/** \brief Reads the card transfer speed for SD version 1. */
#define MMCSD_CARD1_TRANSPEED(crd) \
    (MMCSD_CSD1_TRANSPEED((crd)->csd[3U], (crd)->csd[2U], \
    (crd)->csd[1U], (crd)->csd[0U]))

/** \brief Gives the size of card for SD version 1. */
#define MMCSD_CARD1_SIZE(crd) ((MMCSD_CARD1_DEV_SIZE((crd)) + 1U) * \
    (512U * 1024U))

/** \brief This is the timeout value for sending CMD13 to the card.
 * After every write, the CMD13 is sent this many times and wait for
 * the card to go to transfer state
 * */
#define MMCSD_CARD_TRANS_STATE_THRESHOLD  (10000U)

/* Card status value (Bits 9-12) as defined in physical layer  
 * specification section 4.10.1.
 */
#define MMCSD_CARD_STATE_TRANSFER  (4U)
/**
 * Check RCA/status.
 */

 /** \brief Command relative address. */
#define MMCSD_RCA_ADDR(rca)             (((rca) & 0xFFFF0000U) >> 16U)

/** \brief TBD. */
#define MMCSD_RCA_STAT(rca)             ((rca) & 0x0xFFFFU)

/** \brief Check pattern that can be used for card response validation. */
#define MMCSD_CHECK_PATTERN             (0xAAU)

/**
 * SD SCR related macros.
 */

/** \brief Card version 0. */
#define MMCSD_VERSION_1P0               (0U)

/** \brief Card version 1. */
#define MMCSD_VERSION_1P1               (1U)

/** \brief Card version 2. */
#define MMCSD_VERSION_2P0               (2U)

/**
 * Helper macros.
 * Note card registers are big endian.
 */

/** \brief Reads card version. */
#define MMCSD_CARD_VERSION(sdcard)      ((sdcard)->scr[0U] & 0xFU)

/** \brief Reads card bus width. */
#define MMCSD_CARD_BUSWIDTH(sdcard) (((sdcard)->scr[0U] & 0xF00U) >> 8U)

/** \brief Check for bus width. Give below values
 *         - MMCSD_BUS_WIDTH_1BIT for 1-bit.
 *         - MMCSD_BUS_WIDTH_4BIT for 4-bit.
 *         - 0xFFU                    for invalid bus width.
 */
#define MMCSD_GET_CARD_BUSWIDTH(sdcard) \
    (((((sdcard).busWidth) & 0x0FU) == 0x01) ? \
    0x1 : (((((sdcard).busWidth) & 0x04U) == 0x04U) ? 0x04U : 0xFFU))

/** \brief Check for bus width. Give below values
 *         - 50U for 50 MHz.
 *         - 25U for 25 Mhz.
 *         - 0U  for invalid bus width.
 */
#define MMCSD_GET_CARD_FRE(sdcard) ((((sdcard).tranSpeed) == 0x5AU) ? 50U : \
    ((((sdcard).tranSpeed) == 0x32U) ? 25U : \
    ((((sdcard).tranSpeed) == 0xBU) ? 100U : \
    ((((sdcard).tranSpeed) == 0x2BU) ? 200U : 0U))

/** \brief Define cache line size for buffer alignment. */
#ifndef SOC_CACHELINE_SIZE
#define SOC_CACHELINE_SIZE                  (128U)
#endif

/** \brief Command argument to configure for switch mode. */
#define MMCSD_SWITCH_MODE               (0x80FFFFFFU)
#define MMCSD_CHECK_MODE                (0x00FFFFFFU)
/** \brief Command argument width to configure for transfer speed. */
#define MMCSD_CMD6_GRP1_SEL             (0xFFFFFFF0U)
#define MMCSD_CMD6_GRP4_SEL             (0xFFFF0FFFU)

/** \brief Command argument to configure for default/SDR12 speed. */
#define MMCSD_CMD6_GRP1_DEFAULT         (0x0U)
/** \brief Command argument to configure for high/SDR25 speed. */
#define MMCSD_CMD6_GRP1_HS              (0x1U)
/** \brief Command argument to configure for SDR50 speed. */
#define MMCSD_CMD6_GRP1_SDR50           (0x2U)
/** \brief Command argument to configure for SDR104 speed. */
#define MMCSD_CMD6_GRP1_SDR104          (0x3U)
/** \brief Command argument to configure for DDR50 speed. */
#define MMCSD_CMD6_GRP1_DDR50           (0x4U)

#define MMCSD_CMD6_GRP4_200mA           (0x0U)
#define MMCSD_CMD6_GRP4_400mA           (0x1U)
#define MMCSD_CMD6_GRP4_600mA           (0x2U)
#define MMCSD_CMD6_GRP4_800mA           (0x3U)
#ifdef MMCSD_EDMA_ENABLED

#define MMCSD_OPT_TCINTEN_SHIFT              (0x00000014U)
/**< Interrupt enable bit in OPT register for edma                            */

#define MMCSD_OPT_TCINTEN          (1U)
/**< Interrupt enable bit value in OPT register for edma                      */

#define MMCSD_EDMA_BASE_ADDR                 (0x40000000U)
/**< EDMA_BASE_ADDR for DM814x DSP                                            */

#define MMCSD_EDMA3CC_OPT_TCC_MASK           (0x0003F000U)
/**< EDMA OPT TCC Mask value                                                  */

#define MMCSD_EDMA3CC_OPT_TCC_SHIFT          (0x0000000CU)
/**< EDMA OPT TCC Shift value                                                 */

#define MMCSD_ERROR_COUNT            (0x00FFFFFFU)
/**< Count Value to check error in the recieved byte                          */

#define MMCSD_EDMA3CC_OPT_FIFO_WIDTH         (0xFFFFF8FFU)
/**< Set FIFO Width for edma transfer                                         */

#define MMCSD_EDMA3CC_OPT_SAM_CONST_MODE         (0x00000001U)
/**< Set SAM in Constant Addressing Mode                                      */

#define MMCSD_EDMA3CC_OPT_DAM_CONST_MODE         (0x00000002U)
/**< Set DAM in Constant Addressing Mode                                      */

#define MMCSD_EDMA3CC_OPT_SAM_INCR_MODE          (0xFFFFFFFEU)
/**< Set SAM in Increment Mode                                                */

#define MMCSD_EDMA3CC_OPT_DAM_INCR_MODE          (0xFFFFFFFDU)
/**< Set DAM in Increment Mode                                                */

#define MMCSD_EDMA3CC_OPT_SYNC_AB            (0x00000004U)
/**< It is AB-synchronized                                                    */

#define MMCSD_EDMA3CC_OPT_SYNC_MASK_VALUE            (0xFFFFFFFFU)
/**< Mask Value for Transfer Synchronization                                  */

#define MMCSD_EDMA3CC_PARAM_LINK_ADDRESS         (0xFFFFU)
/**< Set link Address                                                         */

#define MMCSD_EDMA3CC_PARAM_LINK_ADDR_MASK_VALUE         (0x0000FFFFU)
/**< link Address Mask Value                                                  */

#define MMCSD_EDMA3CC_PARAM_ACNT         (1U)
/**< aCnt Value                                                               */

#define MMCSD_EDMA3CC_SRC_BINDEX         (1U)
/**< Src BIndex Value                                                         */

#define MMCSD_EDMA3CC_DST_BINDEX         (4U)
/**< Dst BIndex Value                                                         */

#define MMCSD_EDMA3CC_OPT_SYNC_A         (0x01U)
/**< It is A-synchronized                                                     */

#define MMCSD_EDMA3CC_OPT_SYNCDIM_SHIFT          (3U)
/**< Transfer synchronization dimension Shift Value                           */

#define MMCSD_EDMA3CC_COUNT_VALUE            (uint32_t) (0xFFFFU)
#endif

#define MMCSD_INT_MASK              (0x3EFFU)

/**< SD status size in bytes                                                  */
#define MMCSD_SCR_SIZE_BYTE         8U

/**< maximum response size in bytes in controller                             */
#define ONE_BLOCK_REQUEST                       1U

#define FIFO_LEVEL                (MMCSD_FIFO_SIZE_64_BYTES)

#define FIFO_WIDTH                  (4U)

/* Data buffer for message transmission, it is not stack allocated to allow cache aligning */
static uint8_t                     dataBuffer[64U];


/* MMC functions */
static MMCSD_Error MMCSD_v0_close(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v0_init(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v0_open(MMCSD_Handle handle, MMCSD_Params params);
static MMCSD_Error MMCSD_v0_write(MMCSD_Handle handle,
                                  uint8_t *buf,
                                  uint32_t block,
                                  uint32_t numBlks);
static MMCSD_Error MMCSD_v0_read(MMCSD_Handle handle,
                                 uint8_t *buf,
                                 uint32_t block,
                                 uint32_t numBlks);
static MMCSD_Error MMCSD_v0_transfer(MMCSD_Handle handle,
                                     MMCSD_v0_Transaction *transaction,  mmcsdCmd_t cmd);
static MMCSD_Error MMCSD_v0_control(MMCSD_Handle handle, uint32_t cmd, const void *arg);
static MMCSD_Error MMCSD_v0_initSd(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v0_initEmmc(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v0_setBusWidth(MMCSD_Handle handle, const uint32_t *busWidth);
static MMCSD_Error MMCSD_v0_getBusWidth(MMCSD_Handle handle, uint32_t *busWidth);
static MMCSD_Error MMCSD_v0_getBusFreq(MMCSD_Handle handle, uint32_t *busFreq);
static MMCSD_Error MMCSD_v0_getMediaParams(MMCSD_Handle handle, MMCSD_mediaParams *params);
static void MMCSD_sendCommand(MMCSD_Handle handle, mmcsdCmdObj_t *cmdObj, uint32_t arg);
void MMCSD_v0_hwiFxn(uintptr_t arg);
static void MMCSD_v0_cmdStatusFxn(uintptr_t arg, uint32_t status);
static void MMCSD_v0_xferStatusFxn2(uintptr_t arg, uint32_t status);
#ifdef MMCSD_EDMA_ENABLED
static void MMCSDDMA_rxIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData);
static void MMCSDDMA_txIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData);
static void MMCSDDMA_doNothing(uint32_t tcc, EDMA3_RM_TccStatus edmaStatus, void* appData);
static void MMCSDDMA_writeSemCallback(MMCSD_Handle handle, void *buffer, size_t count);
static void MMCSDDMA_readSemCallback(MMCSD_Handle handle, void *buffer, size_t count);
#endif
static MMCSD_Error mmcsd_calculateFreqForCard(MMCSD_Handle handle, Uint32 initReqFreq,
                                       Uint32 mmcReqFreq,
                                       Uint32 sdReqFreq,
                                       Uint32 sdhighReqFreq);
/* Delay function */
static void delay(uint32_t delayValue);

/* MMC function table for MMC implementation */
const MMCSD_FxnTable MMCSD_v0_FxnTable = {
    &MMCSD_v0_close,
    &MMCSD_v0_control,
    &MMCSD_v0_init,
    &MMCSD_v0_open,
    &MMCSD_v0_write,
    &MMCSD_v0_read
};

static void MMCSD_sendCommand(MMCSD_Handle handle, mmcsdCmdObj_t *cmdObj, uint32_t arg)
{
	MMCSD_v0_HwAttrs           *hwAttrs = NULL;

	hwAttrs = (MMCSD_v0_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

	uint32_t cmdType =0;

	cmdType |= CSL_MMCSD_MMCCMD_DCLR_NO;

	/*Set command Busy or not*/
	cmdType |= CSL_FMK(MMCSD_MMCCMD_BSYEXP, cmdObj->cmd.busy);

	/*Set command index*/
    cmdType |= CSL_FMK(MMCSD_MMCCMD_CMD, cmdObj->cmd.cmdId);

	/*Setting initialize clock*/
    if (0 == cmdObj->cmd.cmdId)
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_INITCK,INIT);
    }

#ifdef MMCSD_EDMA_ENABLED
    /*Set for generating DMA Xfer event*/
    if (((MMCSD_CMD(24U) == cmdObj->cmd.cmdId) ||
         (MMCSD_CMD(25U) == cmdObj->cmd.cmdId) ||
         (MMCSD_CMD(9U) == cmdObj->cmd.cmdId) ||
         (MMCSD_CMD(51U) == cmdObj->cmd.cmdId)))
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_DMATRIG, YES);
    }
    else
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_DMATRIG, NO);
    }
#endif

    /*Setting whether command involves data transfer or not*/
    if (MMCSD_CMDTYPE_ADTC == cmdObj->cmd.cmdType)
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_WDATX, DATA);
    }
    else
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_WDATX, NO);
    }

    /*Setting whether stream or block transfer*/
    if ((MMCSD_CMDTYPE_ADTC == cmdObj->cmd.cmdType) &&
        ((MMCSD_CMD(20U) == cmdObj->cmd.cmdId) ||
         (MMCSD_CMD(11U) == cmdObj->cmd.cmdId)))
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_STRMTP, STREAM);
    }
    else
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_STRMTP, NO);
    }

     /*Setting whether data read or write */
    if (MMCSD_DIR_READ == cmdObj->cmd.xferType)
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_DTRW, READ);
    }
    else if (MMCSD_DIR_WRITE == cmdObj->cmd.xferType)
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_DTRW, WRITE);
    }
    else
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_DTRW, NO);
    }

    /*Setting response type */
    switch (cmdObj->cmd.rspType)
    {
        case MMCSD_RESPTYPE_NO:
            cmdType |= CSL_FMKT(MMCSD_MMCCMD_RSPFMT, NORSP);
            break;

        case MMCSD_RESPTYPE_R1:
            cmdType |= CSL_FMKT(MMCSD_MMCCMD_RSPFMT, R1);
            break;

        case MMCSD_RESPTYPE_R2:
            cmdType |= CSL_FMKT(MMCSD_MMCCMD_RSPFMT, R2);
            break;

        case MMCSD_RESPTYPE_R3:
            cmdType |= CSL_FMKT(MMCSD_MMCCMD_RSPFMT, R3);
            break;

        case MMCSD_RESPTYPE_R4:
            cmdType |= CSL_FMKT(MMCSD_MMCCMD_RSPFMT, R4);
            break;

        case MMCSD_RESPTYPE_R5:
            cmdType |= CSL_FMKT(MMCSD_MMCCMD_RSPFMT, R5);
            break;

        case  MMCSD_RESPTYPE_R6:
            cmdType |= CSL_FMKT(MMCSD_MMCCMD_RSPFMT, R6);
            break;
        /*Klocwork throws "Code is unreachable" at this line which is not valid
        in this case*/
        default:
            cmdType |= CSL_FMKT(MMCSD_MMCCMD_RSPFMT, NORSP);
    }


    if (MMCSD_LINECHR_PUSHPULL == cmdObj->cmd.lineChr)
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_PPLEN, PP);
    }
    else
    {
        cmdType |= CSL_FMKT(MMCSD_MMCCMD_PPLEN, OD);
    }

    MMCSDCommandSend(hwAttrs->baseAddr, cmdType, arg);
}

/* Function to check if the media is ready to accept read/write transfers */
static MMCSD_Error mmcsd_check_transfer_ready(MMCSD_Handle handle)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    uint32_t                    cmd13_try_count = 0U;
    uint32_t                    current_state = 0U;
    MMCSD_v0_Object            *object = NULL;
    MMCSD_v0_Transaction        transaction;
    mmcsdCmdObj_t 		cmdObj = {0};

    /* Input parameter validation */
    MMCSD_osalAssert(!(handle != NULL));

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;
     /* 
      * Send CMD13 to check if the card is still in the programming state.
      * The card needs to go to transfer state before it can send/receive data
      */
     cmd13_try_count=0;
     do {
	memset(&transaction,0,sizeof(transaction));

        cmdObj.cmd.cmdId       = MMCSD_CMD(13U);
        cmdObj.cmd.rspType     = MMCSD_RESPTYPE_R1;
        cmdObj.cmd.busy        = MMCSD_RESPBUSY_NO;
        cmdObj.cmd.cmdType     = MMCSD_CMDTYPE_AC;
        cmdObj.cmd.xferType    = MMCSD_DIR_DONTCARE;
        cmdObj.cmd.lineChr     = MMCSD_LINECHR_PUSHPULL;

        transaction.arg = object->rca << 16U;
        transaction.flags       = MMCSD_CMDRSP_48BITS;
        transaction.checkStatus = MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;

        ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);

        cmd13_try_count++;
        /* 'Current state' can be found from bits[9-12] of Card Status Register 
         * in the response R1 */ 
        current_state=(transaction.response[3] >> (9U) & (0xFU));

        if(current_state==MMCSD_CARD_STATE_TRANSFER) {
		   ret = MMCSD_OK;
		   break;
		}
     } while(cmd13_try_count < MMCSD_CARD_TRANS_STATE_THRESHOLD);
     
     return(ret);
}
/*
 *  ======== MMCSD_v0_write ========
 */
static MMCSD_Error MMCSD_v0_write(MMCSD_Handle handle,
                           uint8_t *buf,
                           uint32_t block,
                           uint32_t numBlks)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    uint32_t                    key;
    uint32_t                    address = 0U;
    MMCSD_v0_Object            *object = NULL;
    MMCSD_v0_Transaction        transaction;
	mmcsdCmdObj_t 				cmdObj = {0};

    /* Input parameter validation */
    MMCSD_osalAssert(!((handle != NULL) && (buf != NULL)));

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;

    object->writeBufIdx = buf;
    object->writeBlockCount = numBlks;

    /* Determine if the device index was already opened */
    key = MMCSD_osalHardwareIntDisable();
    if(0 != ((MMCSD_v0_Object *)(((MMCSD_Config *) handle)->object))->isOpen)
    {
        ret = MMCSD_OK;
    }
    MMCSD_osalHardwareIntRestore(key);

     /* 
      * Send CMD13 to check if the card is still in the programming state.
      * The card needs to go to transfer state before it can send/receive data
      */
    if(MMCSD_OK == ret)
    {
       ret = mmcsd_check_transfer_ready(handle);
    } 
    if(MMCSD_OK == ret)
    {
        /*
         * Address is in blks for high cap cards and in actual bytes
         * for standard capacity cards
         */
        if (0 != object->highCap)
        {
            address = block;
        }
        else
        {
            address = block * object->blockSize;
        }

		cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
		cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
		cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_ADTC;
		cmdObj.cmd.xferType = MMCSD_DIR_WRITE;
		cmdObj.cmd.lineChr  = MMCSD_LINECHR_PUSHPULL;

        transaction.arg = address;

		transaction.blockCount = numBlks;
        transaction.blockSize = object->blockSize;
        transaction.dataBuf = buf;
        transaction.flags = MMCSD_CMDRSP_WRITE | MMCSD_CMDRSP_DATA;
        transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_WRITE;

        if (numBlks > 1U)
        {

			cmdObj.cmd.cmdId    = MMCSD_CMD(25U);
        }
        else
        {
			cmdObj.cmd.cmdId    = MMCSD_CMD(24U);
        }

        ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
    }

    if(MMCSD_OK == ret)
    {
		/* Send a STOP */
        if (transaction.blockCount > 1U)
        {
			cmdObj.cmd.cmdId    = MMCSD_CMD(12U);
			cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
			cmdObj.cmd.busy	    = MMCSD_RESPBUSY_YES;
			cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_AC;
			cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
			cmdObj.cmd.lineChr  = MMCSD_LINECHR_PUSHPULL;
            transaction.arg = 0U;
            transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_CARD_EXITBUSY;
            transaction.flags = MMCSD_CMDRSP_BUSY;

            ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
        }
    }

    return (ret);
}

/*
 *  ======== MMCSD_v0_read ========
 */
static MMCSD_Error MMCSD_v0_read(MMCSD_Handle handle,
                          uint8_t *buf,
                          uint32_t block,
                          uint32_t numBlks)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    uint32_t                    key;
    uint32_t                    address = 0U;
    MMCSD_v0_Object            *object = NULL;
    MMCSD_v0_Transaction        transaction;
	mmcsdCmdObj_t 				cmdObj = {0};

    /* Input parameter validation */
    MMCSD_osalAssert(!((handle != NULL) && (buf != NULL)));

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;

    object->readBufIdx = buf;
    object->readBlockCount = numBlks;

    /* Determine if the device index was already opened */
    key = MMCSD_osalHardwareIntDisable();
    if(0 != ((MMCSD_v0_Object *)(((MMCSD_Config *) handle)->object))->isOpen)
    {
        ret = MMCSD_OK;
    }
    MMCSD_osalHardwareIntRestore(key);

     /* 
      * Send CMD13 to check if the card is still in the programming state.
      * The card needs to go to transfer state before it can send/receive data
      */
    if(MMCSD_OK == ret)
    {
       ret = mmcsd_check_transfer_ready(handle);
    }   
    if(MMCSD_OK == ret)
    {
        /*
         * Address is in blks for high cap cards and in actual bytes
         * for standard capacity cards
         */
        if (0 != object->highCap)
        {
            address = block;
        }
        else
        {
            address = block * object->blockSize;
        }

		cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
		cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
		cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_ADTC;
		cmdObj.cmd.xferType = MMCSD_DIR_READ;
		cmdObj.cmd.lineChr  = MMCSD_LINECHR_PUSHPULL;
        transaction.arg = address;
        transaction.flags = MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
        transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_READ;

        transaction.blockCount = numBlks;
        transaction.blockSize = object->blockSize;
        transaction.dataBuf = buf;

        if (numBlks > 1U)
        {
			cmdObj.cmd.cmdId    = MMCSD_CMD(18U);
        }
        else
        {
			cmdObj.cmd.cmdId    = MMCSD_CMD(17U);
        }

        ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
    }

    if(MMCSD_OK == ret)
    {
        /* Send a STOP */
        if (transaction.blockCount > 1U)
        {
			cmdObj.cmd.cmdId    = MMCSD_CMD(12U);
			cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
			cmdObj.cmd.busy	    = MMCSD_RESPBUSY_YES;
			cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_AC;
			cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
			cmdObj.cmd.lineChr  = MMCSD_LINECHR_PUSHPULL;
            transaction.arg         = 0U;
            transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_CARD_EXITBUSY;
            transaction.flags       = MMCSD_CMDRSP_BUSY;

            ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
        }
    }
    return (ret);
}

/*
 *  ======== MMCSD_v0_close ========
 */
static MMCSD_Error MMCSD_v0_close(MMCSD_Handle handle)
{
    MMCSD_v0_Object   *object = NULL;
    MMCSD_v0_HwAttrs  *hwAttrs = NULL;
    MMCSD_Error ret=MMCSD_OK;

    /* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v0_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

#ifdef MMCSD_EDMA_ENABLED
    EDMA3_DRV_unlinkChannel(hwAttrs->edmaHandle,
            object->edmaLinkChId);

    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle,
                object->edmaLinkChId);

    /* Free the DMA TX/RX channels */
    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle,
                          hwAttrs->rxDmaEventNumber);

    EDMA3_DRV_freeChannel(hwAttrs->edmaHandle,
                          hwAttrs->txDmaEventNumber);
#endif

    if(0U != hwAttrs->enableInterrupt)
    {
        /* Destruct the Hwi */
        MMCSD_osalHardwareIntDestruct(object->hwi,hwAttrs->eventId);
    }

    if(object->switched_to_v18 && hwAttrs->switchVoltageFxn!=NULL) {
        MMCSD_drv_log(Diags_USER1,"Switch to 1.8V indicated. Switching back to 3.0V\n");
		ret = hwAttrs->switchVoltageFxn(hwAttrs->instNum,MMCSD_BUS_VOLTAGE_3_0V);
	}
    /* Destruct the instance lock */
    MMCSD_osalDeleteBlockingLock(object->commandMutex);
    MMCSD_osalDeleteBlockingLock(object->transferMutex);
    MMCSD_osalDeleteBlockingLock(object->commandComplete);
	MMCSD_osalDeleteBlockingLock(object->dataBufferCopyComplete);
    MMCSD_osalDeleteBlockingLock(object->transferComplete);

#ifdef MMCSD_EDMA_ENABLED
    MMCSD_osalDeleteBlockingLock(object->writeSem);
    MMCSD_osalDeleteBlockingLock(object->readSem);
#endif

    memset(object, 0, sizeof(MMCSD_v0_Object));

#ifdef LOG_EN
    MMCSD_drv_log(Diags_USER1, "MMCSD: Object closed 0x%x", ((MMCSD_Config *) handle)->hwAttrs->baseAddr);
#endif

    return (ret);
}

/*
 *  ======== MMCSD_v0_init ========
 */
static MMCSD_Error MMCSD_v0_init(MMCSD_Handle handle)
{
    /* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

    MMCSD_osalAssert(((MMCSD_Config *) handle)->object==NULL);
	
	/* Initialize all elements to 0 */
	memset(((MMCSD_Config *) handle)->object,0,sizeof(MMCSD_v0_Object));

    return (MMCSD_OK);
}

/*
 *  ======== MMCSD_v0_open ========
 */
static MMCSD_Error MMCSD_v0_open(MMCSD_Handle handle, MMCSD_Params params)
{
    SemaphoreP_Params           semParams;
    MMCSD_Error                 ret = MMCSD_OK;
#ifdef MMCSD_EDMA_ENABLED
    uint32_t                    result = EDMA3_DRV_SOK;
    uint32_t                    rxDmaEventNumber = 0U;
    uint32_t                    txDmaEventNumber = 0U;
    uint32_t                    tcc = 0;
#endif
    uint32_t                    key;
    MMCSD_v0_Object            *object = NULL;
    MMCSD_v0_HwAttrs           *hwAttrs = NULL;
    OsalRegisterIntrParams_t interruptRegParams;
    OsalInterruptRetCode_e interruptRegRet;

    /* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v0_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

    /* Determine if the device index was already opened */
    key = MMCSD_osalHardwareIntDisable();
    if(0 != ((MMCSD_v0_Object *)(((MMCSD_Config *) handle)->object))->isOpen)
    {
        ret = MMCSD_ERR;
    }
    MMCSD_osalHardwareIntRestore(key);

    if(MMCSD_OK == ret)
    {
        /* Store the MMC parameters */
        if (params == NULL)
        {
            /* No params passed in, so use the defaults */
            MMCSD_Params_init(&(object->MMCSDConfigParams));
        }
        else
        {
            /* Copy the params contents */
            object->MMCSDConfigParams.custom = ((MMCSD_ConfigParams *) params)->custom;
        }
    }

    if(MMCSD_OK == ret)
    {
        if(0U != hwAttrs->enableInterrupt)
        {
	    /* Initialize with defaults */
            Osal_RegisterInterrupt_initParams(&interruptRegParams);

            /* Construct Hwi object for this MMCSD peripheral */
            interruptRegParams.corepacConfig.name=NULL;
            interruptRegParams.corepacConfig.arg=(uintptr_t)handle;
            interruptRegParams.corepacConfig.corepacEventNum = hwAttrs->eventId;
#if defined (__TI_ARM_V5__)
            interruptRegParams.corepacConfig.triggerSensitivity= OSAL_ARM_GIC_TRIG_TYPE_HIGH_LEVEL; /* interrupt edge triggered */
#endif
#if defined (__TI_ARM_V5__)
            interruptRegParams.corepacConfig.priority= hwAttrs->intNum;
#else
            interruptRegParams.corepacConfig.priority= 0x20U;
#endif
		interruptRegParams.corepacConfig.isrRoutine=MMCSD_v0_hwiFxn;
	    interruptRegParams.corepacConfig.intVecNum=hwAttrs->intNum;

	       /* Register interrupts */
            interruptRegRet=MMCSD_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));
            if(interruptRegRet!=OSAL_INT_SUCCESS) {
              ret=MMCSD_ERR;
            }
        }

        /*
         * Construct thread safe handles for this MMCSD peripheral
         * Semaphore to provide exclusive access to the MMCSD peripheral
         */
        MMCSD_osalSemParamsInit(&semParams);
        semParams.mode = SemaphoreP_Mode_BINARY;
        object->commandMutex = MMCSD_osalCreateBlockingLock(1U, &semParams);
        object->transferMutex = MMCSD_osalCreateBlockingLock(1U, &semParams);
        object->commandComplete = MMCSD_osalCreateBlockingLock(0, &semParams);
		object->dataBufferCopyComplete = MMCSD_osalCreateBlockingLock(0, &semParams);
        object->transferComplete = MMCSD_osalCreateBlockingLock(0, &semParams);
#ifdef MMCSD_EDMA_ENABLED
        semParams.name = "write";
        object->writeSem = MMCSD_osalCreateBlockingLock(0, &semParams);
        semParams.name = "read";
        object->readSem = MMCSD_osalCreateBlockingLock(0, &semParams);
        if (MMCSD_OK == ret)
        {
            rxDmaEventNumber = hwAttrs->rxDmaEventNumber;
            txDmaEventNumber = hwAttrs->txDmaEventNumber;
            tcc = EDMA3_DRV_TCC_ANY;

            result = ((uint32_t)(EDMA3_DRV_requestChannel(
                                (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                &rxDmaEventNumber,
                                &tcc,
                                (EDMA3_RM_EventQueue) hwAttrs->edmaRxTC,
                                &MMCSDDMA_rxIsrHandler,
                                (void *) handle)));
            if (result != ((uint32_t) EDMA3_DRV_SOK))
            {
                ret = MMCSD_ERR;
            }

            if (MMCSD_OK == ret)
            {
                object->Txtcc = EDMA3_DRV_TCC_ANY;
                result = ((uint32_t)(EDMA3_DRV_requestChannel(
                                                (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                                &txDmaEventNumber,
                                                &object->Txtcc,
                                                (EDMA3_RM_EventQueue) 0,
                                                &MMCSDDMA_txIsrHandler,
                                                (void *) handle)));
                if (result != ((uint32_t) EDMA3_DRV_SOK))
                {
                    ret = MMCSD_ERR;
                }
            }

            if (MMCSD_OK == ret)
            {
                tcc = EDMA3_DRV_TCC_ANY;
                object->edmaLinkChId = EDMA3_DRV_LINK_CHANNEL;
                result = ((uint32_t)(EDMA3_DRV_requestChannel(
                                hwAttrs->edmaHandle,
                                &object->edmaLinkChId,
                                &tcc,
                                0,
                                &MMCSDDMA_doNothing,
                                NULL)));
                if (result != ((uint32_t) EDMA3_DRV_SOK))
                {
                    ret = MMCSD_ERR;
                }
            }

            if (MMCSD_OK == ret)
            {
                result = ((uint32_t)(EDMA3_DRV_getPaRAMPhyAddr(
                                    hwAttrs->edmaHandle,
                                    object->edmaLinkChId,
                                &object->edmaLinkChPhyAddr)));
                if (result != ((uint32_t) EDMA3_DRV_SOK))
                {
                    ret = MMCSD_ERR;
                }
            }
        }

#endif
    }

	mmcsd_calculateFreqForCard(handle,  MMCSD_INIT_CLOCK,
                             MMC_CLOCK,
                             SD_CLOCK,
                             SD_HIGH_SPEED_CLOCK);
    if(MMCSD_OK == ret)
    {
        object->cardType = hwAttrs->cardType;

        if (MMCSD_CARD_SD == object->cardType)
        {
            ret = MMCSD_v0_initSd(handle);
        }
        else if (MMCSD_CARD_EMMC == object->cardType)
        {
            ret = MMCSD_v0_initEmmc(handle);
        }
        else
        {
            ret = MMCSD_ERR; /*dummy statement for misra warning*/
        }
    }

    /* Mark the object as in use */
    if(MMCSD_OK == ret)
    {
        ((MMCSD_v0_Object *)(((MMCSD_Config *) handle)->object))->isOpen = 1;
    }

    return (ret);
}

/*
 *  ======== mmcsd_calculateFreqForCard ========
 */
 static MMCSD_Error mmcsd_calculateFreqForCard(MMCSD_Handle handle, Uint32 initReqFreq,
                                       Uint32 mmcReqFreq,
                                       Uint32 sdReqFreq,
                                       Uint32 sdhighReqFreq)
 {
	MMCSD_Error                 ret = MMCSD_OK;
    MMCSD_v0_HwAttrs           *hwAttrs = NULL;
	uint32_t mmcFreq, sdFreq, sdHighFreq, cpuClk = 0;

	/* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

	/* Get the pointer to the object and hwAttrs */
    hwAttrs = (MMCSD_v0_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

	if ((((initReqFreq > MMCSD_INIT_FREQ_MAX) ||
       (mmcReqFreq > MMC_CLOCK)) ||
       (sdReqFreq > SD_CLOCK)) ||
       (sdhighReqFreq > SD_HIGH_SPEED_CLOCK))
    {
        ret = MMCSD_ERR;
    }
    else
    {
		hwAttrs->mmcsdClockInfo.isOpenDrainDivBy4Reqd = FALSE;
		cpuClk = hwAttrs->inputClk;
		hwAttrs->mmcsdClockInfo.openDrain = ((uint32_t)cpuClk /
								(2U * initReqFreq)) - 1U;

		if(hwAttrs->mmcsdClockInfo.openDrain > 0xFFU)
		{
			hwAttrs->mmcsdClockInfo.isOpenDrainDivBy4Reqd = TRUE;
			hwAttrs->mmcsdClockInfo.openDrain = ((uint32_t)cpuClk /
								(4U * initReqFreq)) - 1U;

			if(hwAttrs->mmcsdClockInfo.openDrain > 0xFFU)
			{
				hwAttrs->mmcsdClockInfo.openDrain = 0xFFU;
			}
		}

	}

	if(cpuClk > (2U * sdReqFreq))
	{
		hwAttrs->mmcsdClockInfo.sdPushPull = ((uint32_t)cpuClk /
								(2U * sdReqFreq)) - 1U;
	}
	else
	{
		hwAttrs->mmcsdClockInfo.sdPushPull = 0;
	}

	if(cpuClk > (2U * mmcReqFreq))
	{
		hwAttrs->mmcsdClockInfo.mmcPushPull = ((uint32_t)cpuClk /
								(2U * mmcReqFreq)) - 1U;
	}
	else
	{
		hwAttrs->mmcsdClockInfo.mmcPushPull = 0;
	}

	if(cpuClk > (2U * sdhighReqFreq))
	{
		hwAttrs->mmcsdClockInfo.sdPushPullHighSpeed = ((uint32_t)cpuClk /
								(2U * sdhighReqFreq)) - 1U;
	}
	else
	{
		hwAttrs->mmcsdClockInfo.sdPushPullHighSpeed = 0;
	}

	mmcFreq = (Uint32)cpuClk /
                      (2U * (hwAttrs->mmcsdClockInfo.mmcPushPull + 1U));
	sdFreq = (Uint32)cpuClk /
				 (2U * (hwAttrs->mmcsdClockInfo.sdPushPull + 1U));
	sdHighFreq = (Uint32)cpuClk / (2U *
					 (hwAttrs->mmcsdClockInfo.sdPushPullHighSpeed + 1U));

	if (mmcFreq > mmcReqFreq)
	{
		hwAttrs->mmcsdClockInfo.mmcPushPull =
			hwAttrs->mmcsdClockInfo.mmcPushPull + 1U;
	}

	if (sdFreq > sdReqFreq)
	{
	   hwAttrs->mmcsdClockInfo.sdPushPull =
			hwAttrs->mmcsdClockInfo.sdPushPull + 1U;
	}

	if (sdHighFreq > sdhighReqFreq)
	{
		hwAttrs->mmcsdClockInfo.sdPushPullHighSpeed =
			hwAttrs->mmcsdClockInfo.sdPushPullHighSpeed + 1U;
	}

    if ((((hwAttrs->mmcsdClockInfo.mmcPushPull > 0xFFU) ||
       (hwAttrs->mmcsdClockInfo.sdPushPull > 0xFFU)) ||
       (hwAttrs->mmcsdClockInfo.sdPushPullHighSpeed > 0xFFU)) ||
       (hwAttrs->mmcsdClockInfo.openDrain > 0xFFU))
    {
        MMCSD_drv_log(Diags_USER1,"\r\nMMCSD - CalculateFreqForCard - freq value"
                         " overflow");
    }

    return ret;
 }

/* Data buffer for message transmission, it is not stack allocated to allow cache aligning */
static uint8_t                     dataBuffer[64U];

/*
 *  ======== MMCSD_v0_initSd ========
 */
static MMCSD_Error MMCSD_v0_initSd(MMCSD_Handle handle)
{
    MMCSD_Error                 ret = MMCSD_OK;
    MMCSD_v0_Object            *object = NULL;
    MMCSD_v0_HwAttrs           *hwAttrs = NULL;
    MMCSD_v0_Transaction        transaction = {0};
    volatile int32_t            status = CSL_ESYS_FAIL;
	volatile int32_t            intrStatus = CSL_ESYS_FAIL;
	mmcsdCmdObj_t 				cmdObj={0};
	uint32_t 					cnt = MMCSD_NUM_OF_TRIES;

    /* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v0_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

	memset(dataBuffer,0,sizeof(dataBuffer));

    /* Controller Reset */
    MMCSDLineReset(hwAttrs->baseAddr, (MMCSD_MMCCTL_CMDRST_MASK | MMCSD_MMCCTL_DATRST_MASK));

    if (MMCSD_OK == ret)
    {
		intrStatus = MMCSDIntrGet(hwAttrs->baseAddr);

		MMCSDIntrDisable(hwAttrs->baseAddr, MMCSD_INT_MASK);

		MMCSDFreqSet(hwAttrs->baseAddr, hwAttrs->mmcsdClockInfo.openDrain,
					hwAttrs->mmcsdClockInfo.isOpenDrainDivBy4Reqd);
		MMCSDSendInitSeq(hwAttrs->baseAddr);
		status = 0;

		while (0 == (status & (MMCSD_INTR_MASK_RSPDONE | MMCSD_EVENT_ERROR)))
        {
            status = MMCSDGetIntrStatus(hwAttrs->baseAddr);
        }

        if ((0 == (status & MMCSD_INTR_MASK_RSPDONE)) ||
            ((MMCSD_EVENT_ERROR & status) != 0))
		{
			 MMCSDIntrEnable(hwAttrs->baseAddr, intrStatus);
		}

		cmdObj.cmd.cmdId    = MMCSD_CMD(0U);
		cmdObj.cmd.rspType  = MMCSD_RESPTYPE_NO;
		cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
		cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_BC;
		cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
		cmdObj.cmd.lineChr  = MMCSD_LINECHR_OPENDRAIN;
		
        transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
		transaction.arg         = 0U;
        transaction.flags       = MMCSD_CMDRSP_NONE;
		ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);

		if(MMCSD_OK == ret)
		{
			cmdObj.cmd.cmdId    = MMCSD_CMD(8U);
			cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R3;
			cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
			cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_BCR;
			cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
			cmdObj.cmd.lineChr  = MMCSD_LINECHR_OPENDRAIN;
			transaction.arg         = MMCSD_VOLT_2P7_3P6 | MMCSD_CHECK_PATTERN;
			transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
			transaction.flags       = MMCSD_CMDRSP_NONE;
			ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
			if(MMCSD_OK == ret)
			{
				while(0 != cnt)
				{
					cmdObj.cmd.cmdId    = MMCSD_CMD(55U);
					cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
					cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
					cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_AC;
					cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
					cmdObj.cmd.lineChr  = MMCSD_LINECHR_OPENDRAIN;
					transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
					transaction.arg         = 0U;
					transaction.flags       = MMCSD_CMDRSP_NONE;
					ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);

					if(MMCSD_OK != ret)
					{
                        /* SD card should respond to CMD55. Break in case of error */
						break;
					}
					cmdObj.cmd.cmdId    = MMCSD_CMD(41U);
					cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R3;
					cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
					cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_BCR;
					cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
					cmdObj.cmd.lineChr  = MMCSD_LINECHR_OPENDRAIN;
					
                    transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
					transaction.arg         = MMCSD_OCR_HIGH_CAPACITY | 
                                              MMCSD_OCR_VDD_3P2_3P3 | 
                                              MMCSD_OCR_VDD_3P3_3P4;
					transaction.flags       = MMCSD_CMDRSP_NONE;
                    
					ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
					if(MMCSD_OK != ret)
					{
						break;
					}

                    /* Check the card busy bit. Need to send ACMD41 multiple times
                       till the card comes out of busy state */
					if((transaction.response[3] & MMCSD_CARD_BUSY_BIT) != 0)
					{
						object->ocr = transaction.response[3];

						if((transaction.response[3] & MMCSD_OCR_HIGH_CAPACITY) != 0)
						{
							object->highCap = TRUE;
						}
						else
						{
							object->highCap = FALSE;
						}
						break;
					}

					cnt--;
				}//while loop
                
                if(0 == cnt)
                {
                    /* No point in continuing */
                    ret = MMCSD_ERR;
                }                
			}
			else
			{
                /* Card has not repsonded for CMD8 which means:
                   Ver2.00 or later SD Memory Card(voltage mismatch)
                   or Ver1.X SD Memory Card or not SD Memory Card.                
                   Check if card responds for ACMD41 */
				cmdObj.cmd.cmdId    = MMCSD_CMD(0U);
				cmdObj.cmd.rspType  = MMCSD_RESPTYPE_NO;
				cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
				cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_BC;
				cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
				cmdObj.cmd.lineChr  = MMCSD_LINECHR_OPENDRAIN;
				
                transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
				transaction.arg         = 0;
				transaction.flags       = MMCSD_CMDRSP_NONE;
				ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
				if (MMCSD_OK == ret)
				{
					while(0 != cnt)
					{
						cmdObj.cmd.cmdId    = MMCSD_CMD(55U);
						cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
						cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
						cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_AC;
						cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
						cmdObj.cmd.lineChr  = MMCSD_LINECHR_OPENDRAIN;

						transaction.arg         = 0U;
						transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
						transaction.flags       = MMCSD_CMDRSP_NONE;
						ret = MMCSD_v0_transfer(handle, &transaction, 
									cmdObj.cmd);
						if(MMCSD_OK != ret)
						{
							break;
						}
						cmdObj.cmd.cmdId    = MMCSD_CMD(41U);
						cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R3;
						cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
						cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_BCR;
						cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
						cmdObj.cmd.lineChr  = MMCSD_LINECHR_OPENDRAIN;
						
                        transaction.arg         = 0x0U | MMCSD_OCR_VDD_3P2_3P3 | 
                                                  MMCSD_OCR_VDD_3P3_3P4;
						transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
						transaction.flags       = MMCSD_CMDRSP_NONE;
						ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
						if(MMCSD_OK != ret)
						{
							break;
						}

                        /* Check the card busy bit. Need to send ACMD41 multiple times
                        till the card comes out of busy state */
						if((transaction.response[3] & MMCSD_CARD_BUSY_BIT) != 0)
						{
							object->ocr = transaction.response[3];
							object->isHighCapacitySDCard = FALSE;
							break;
						}
            
						cnt--;
					}//while loop
                    
					if(0 == cnt)
					{
                        /* No point in continuing */
                        ret = MMCSD_ERR;
					}
				}
			}
		}
    }

	/* Send CID command */
	if(MMCSD_OK == ret)
	{
		cmdObj.cmd.cmdId    = MMCSD_CMD(02U);
		cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R2;
		cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
		cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_BCR;
		cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
		cmdObj.cmd.lineChr  = MMCSD_LINECHR_OPENDRAIN;
        
		transaction.arg         = 0U;
		transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
        transaction.flags       = MMCSD_CMDRSP_136BITS;
		ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
		if(MMCSD_OK == ret)
		{
			memcpy(object->cid, transaction.response, 16U);
		}
	}

	if(MMCSD_OK == ret)
	{
		/* Send RCA command */
		cmdObj.cmd.cmdId    = MMCSD_CMD(03U);
		cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R6;
		cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
		cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_BCR;
		cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
		cmdObj.cmd.lineChr  = MMCSD_LINECHR_OPENDRAIN;
		
        transaction.arg         = 0U;
		transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
		transaction.flags       = MMCSD_CMDRSP_NONE;
		ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
		/* Verify the interchanging is proper or not */
		if(transaction.response[3] != 0)
		{
			object->rca = (uint32_t)((transaction.response[3] & 0xFFFF0000u) >> 16U);
		}
	}

	/* Send CSD command */
	if(MMCSD_OK == ret)
	{
		cmdObj.cmd.cmdId    = MMCSD_CMD(9U);
		cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R2;
		cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
		cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_AC;
		cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
		cmdObj.cmd.lineChr  = MMCSD_LINECHR_OPENDRAIN;
        
		transaction.arg         = object->rca << 16U;
		transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
        transaction.flags       = MMCSD_CMDRSP_136BITS;

		ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
		if(MMCSD_OK == ret)
		{
			memcpy(object->csd, transaction.response, 16U);
		}
	}	

	if(MMCSD_OK == ret)
	{
		if (MMCSD_CARD_CMMCSD_VERSION(object))
		{
			object->tranSpeed = MMCSD_CARD1_TRANSPEED(object);
			object->blockSize = ((uint32_t)1U) << (MMCSD_CARD1_RDBLKLEN(object));
			object->size = MMCSD_CARD1_SIZE(object);
			object->blockCount = object->size / object->blockSize;
		}
		else
		{
			object->tranSpeed = MMCSD_CARD0_TRANSPEED(object);
			object->blockSize = ((uint32_t)1U) << (MMCSD_CARD0_RDBLKLEN(object));
			object->size = MMCSD_CARD0_SIZE(object);
			object->blockCount = MMCSD_CARD0_NUMBLK(object);
		}

		/* Select and deselect the card. This command puts the card into
           transfer mode. Selecting the card is mandatory before issueing
           any data transfer commands */
		if(MMCSD_OK == ret)
		{
			cmdObj.cmd.cmdId    = MMCSD_CMD(7U);
			cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
			cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
			cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_AC;
			cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
			cmdObj.cmd.lineChr  = MMCSD_LINECHR_PUSHPULL;
			
            transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
			transaction.arg         = object->rca << 16U;
            transaction.flags       = MMCSD_CMDRSP_BUSY;
			ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
		}

        if(MMCSD_OK == ret)
		{
            /* Send ACMD6 for setting the bus width */
			cmdObj.cmd.cmdId    = MMCSD_CMD(55U);
			cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
			cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
			cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_AC;
			cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
			cmdObj.cmd.lineChr  = MMCSD_LINECHR_PUSHPULL;
			
			transaction.flags       = MMCSD_CMDRSP_NONE;
			transaction.arg         = object->rca << 16U;
			transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;

			ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);

			/* Required to configure SD card in 4 bit mode of operation*/
			/*Set bus width*/
			cmdObj.cmd.cmdId       = MMCSD_CMD(6U);
			cmdObj.cmd.rspType     = MMCSD_RESPTYPE_R1;
			cmdObj.cmd.busy        = MMCSD_RESPBUSY_NO;
			cmdObj.cmd.cmdType     = MMCSD_CMDTYPE_AC;
			cmdObj.cmd.xferType    = MMCSD_DIR_DONTCARE;
			cmdObj.cmd.lineChr     = MMCSD_LINECHR_PUSHPULL;

			transaction.arg         = 0x02U;
			transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
			transaction.flags       = MMCSD_CMDRSP_NONE;
			ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
            if(MMCSD_OK == ret)
            {
                MMCSDSetBusWidth(hwAttrs->baseAddr, MMCSD_BUSWIDTH_4BIT);
            }			
		}

		/* Set data block length to 512. Note that setting the block
           length is required for standard capacity cards. Block length
           for high capacity cards is fixed to 512 bytes */
		if((object->highCap) == 0U)
		{
			cmdObj.cmd.cmdId    = MMCSD_CMD(16U);
			cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
			cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
			cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_AC;
			cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
			cmdObj.cmd.lineChr  = MMCSD_LINECHR_PUSHPULL;
			
            transaction.arg         = MMCSD_BLOCK_SIZE;
			transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
			transaction.flags       = MMCSD_CMDRSP_NONE;
			ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);

			if(MMCSD_OK == ret)
			{
				object->blockSize = MMCSD_BLOCK_SIZE;
			}
		}
        
        /* Card intialization sequence is complete. Now the operating clock can be
           increased for data transfers */
        MMCSDFreqSet(hwAttrs->baseAddr, hwAttrs->mmcsdClockInfo.sdPushPull, FALSE);
	}

	if(MMCSD_OK != ret)
	{
	   MMCSD_v0_close(handle);
	}

     return (ret);
}

/*
 *  ======== MMCSD_open ========
 */

/**\brief initialise MMC Card*/
static Int32 MMCSD_v0_initEmmc(MMCSD_Handle handle)
{
    MMCSD_Error                 ret = MMCSD_OK;
    uint32_t                    retry = 0xFFFFU;
    MMCSD_v0_Object            *object = NULL;
    MMCSD_v0_HwAttrs           *hwAttrs = NULL;
    MMCSD_v0_Transaction        transaction;
    volatile int32_t            status = CSL_ESYS_FAIL;
	volatile int32_t            intrStatus = CSL_ESYS_FAIL;
	/*This has to be mmc obj*/
	mmcsdCmdObj_t 				cmdObj={0};

    /* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v0_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

	memset(dataBuffer,0,sizeof(dataBuffer));

    if (MMCSD_OK == ret)
    {
		intrStatus = MMCSDGetIntrStatus(hwAttrs->baseAddr);

		MMCSDIntrDisable(hwAttrs->baseAddr, 0U);

		MMCSDFreqSet(hwAttrs->baseAddr, hwAttrs->mmcsdClockInfo.openDrain,
					hwAttrs->mmcsdClockInfo.isOpenDrainDivBy4Reqd);
		MMCSDSendInitSeq(hwAttrs->baseAddr);
		status = 0;

		while (0 == (status & (MMCSD_INTR_MASK_RSPDONE | MMCSD_EVENT_ERROR)))
        {
            status = MMCSDGetIntrStatus(hwAttrs->baseAddr);
        }

        if ((0 == (status & MMCSD_INTR_MASK_RSPDONE)) ||
            ((MMCSD_EVENT_ERROR & status) != 0))
		{
			MMCSDIntrEnable(hwAttrs->baseAddr, intrStatus);
		}

		/*Sedinding command reser card(0U) i.e, putting system to idle state is add extra
		  before sending op_command(1U) as per k2g*/
		if(MMCSD_OK == ret)
		{
			/* send ocr*/
			cmdObj.cmd.cmdId       = MMCSD_CMD(0U);
			cmdObj.cmd.rspType     = MMCSD_RESPTYPE_NO;
			cmdObj.cmd.busy        = MMCSD_RESPBUSY_NO;
			cmdObj.cmd.cmdType     = MMCSD_CMDTYPE_BC;
			cmdObj.cmd.xferType    = MMCSD_DIR_DONTCARE;
			cmdObj.cmd.lineChr     = MMCSD_LINECHR_OPENDRAIN;
			transaction.arg    = 0U;
			transaction.checkStatus = MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
			transaction.flags       = MMCSD_CMDRSP_NONE;

			ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
		}

         /* NOTE: Add delay */
        delay(5U);

		if(MMCSD_OK == ret)
		{
            /* Poll until we get the card status (BIT31 of OCR) is powered up */
            do
            {
			   /* send ocr*/
			   cmdObj.cmd.cmdId      = MMCSD_CMD(1U);
			   cmdObj.cmd.rspType    = MMCSD_RESPTYPE_R3;
			   cmdObj.cmd.busy       = MMCSD_RESPBUSY_NO;
			   cmdObj.cmd.cmdType    = MMCSD_CMDTYPE_BCR;
			   cmdObj.cmd.xferType   = MMCSD_DIR_DONTCARE;
			   cmdObj.cmd.lineChr    = MMCSD_LINECHR_OPENDRAIN;
			   transaction.arg    = MMCSD_OCR_AGRHL_REG_VAL;

			   ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
			   retry--;
            } while (((transaction.response[3U] & ((uint32_t)BIT(31U))) == 0U) && (retry != 0));

			if (0U == retry)
			{
				/* No point in continuing */
				ret = MMCSD_ERR;
			}

		}


        /* CMD0 - reset card */
        if(MMCSD_OK == ret)
        {
            object->ocr = transaction.response[3U];

            object->highCap = (object->ocr & MMCSD_OCR_HIGH_CAPACITY) ? 1U : 0U;

            /*Send CID*/
            cmdObj.cmd.cmdId         = MMCSD_CMD(2U);
            cmdObj.cmd.rspType    = MMCSD_RESPTYPE_R2;
            cmdObj.cmd.busy        = MMCSD_RESPBUSY_NO;
            cmdObj.cmd.cmdType        = MMCSD_CMDTYPE_BCR;
            cmdObj.cmd.xferType    = MMCSD_DIR_DONTCARE;
            cmdObj.cmd.lineChr     = MMCSD_LINECHR_OPENDRAIN;
            transaction.arg    = 0U;
            transaction.checkStatus = MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
            transaction.flags       = MMCSD_CMDRSP_BUSY;
            ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
            if(MMCSD_OK == ret)
            {
               memcpy(object->cid, transaction.response, 16U);
            }
        }

        if(MMCSD_OK == ret)
        {
            object->rca = MMCSD_RELATIVE_CARD_ADDRESS;

            /* Send CMD3, to get the card relative address */
            cmdObj.cmd.cmdId      = MMCSD_CMD(3U);
            cmdObj.cmd.rspType    = MMCSD_RESPTYPE_R1;
            cmdObj.cmd.busy       = MMCSD_RESPBUSY_NO;
            cmdObj.cmd.cmdType    = MMCSD_CMDTYPE_AC;
            cmdObj.cmd.xferType   = MMCSD_DIR_DONTCARE;
            cmdObj.cmd.lineChr    = MMCSD_LINECHR_OPENDRAIN;
            transaction.arg    = object->rca << 16U;
            transaction.checkStatus = MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
            transaction.flags       = MMCSD_CMDRSP_BUSY;
            ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
        }

        if(MMCSD_OK == ret)
        {
            /* Send CMD9, to get the card specific data */
            cmdObj.cmd.cmdId       = MMCSD_CMD(9U);
			cmdObj.cmd.busy        = MMCSD_RESPBUSY_NO;
            cmdObj.cmd.rspType     = MMCSD_RESPTYPE_R2;
            cmdObj.cmd.cmdType     = MMCSD_CMDTYPE_AC;
            cmdObj.cmd.xferType    = MMCSD_DIR_DONTCARE;
            cmdObj.cmd.lineChr     = MMCSD_LINECHR_OPENDRAIN;
            transaction.arg    = object->rca << 16U;
            transaction.checkStatus = MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
            transaction.flags       = MMCSD_CMDRSP_NONE;

            ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);

            if(MMCSD_OK == ret)
            {
               memcpy(object->csd, transaction.response, 16U);
            }
        }

#ifdef ENABLE_EMMC
        if(MMCSD_OK == ret)
        {
            object->tranSpeed = ((object->csd[3] & 0x000000FFU));
            object->blockSize = (((uint32_t)2U)<<(((object->csd[0] & 0x03C00000U) >> 22)-1U));

            if (((object->csd[3] & 0x3C000000U) >> 26) != 0x04U)
            {
                ret = MMCSD_ERR;
            }
        }
#else
        if(MMCSD_OK == ret)
        {
            if (MMCSD_CARD_CMMCSD_VERSION(object))
            {
                object->tranSpeed = MMCSD_CARD1_TRANSPEED(object);
                object->blockSize = ((uint32_t)1U) << (MMCSD_CARD1_RDBLKLEN(object));
                object->size = MMCSD_CARD1_SIZE(object);
                object->blockCount = object->size / object->blockSize;
            }
            else
            {
                object->tranSpeed = MMCSD_CARD0_TRANSPEED(object);
                object->blockSize = ((uint32_t)1U) << (MMCSD_CARD0_RDBLKLEN(object));
                object->size = MMCSD_CARD0_SIZE(object);
                object->blockCount = MMCSD_CARD0_NUMBLK(object);
            }
        }
#endif
        /* Block size other than 512 is not supported by the driver.
         * Setting the block length to 512 by default which will be
		 * supported by all the cards.		*/
        object->blockSize = MMCSD_BLOCK_SIZE;

        if(MMCSD_OK == ret)
        {
            /* Select the card */
            cmdObj.cmd.cmdId       = MMCSD_CMD(7U);
            cmdObj.cmd.rspType     = MMCSD_RESPTYPE_R1;
            cmdObj.cmd.busy        = MMCSD_RESPBUSY_NO;
            cmdObj.cmd.cmdType     = MMCSD_CMDTYPE_AC;
            cmdObj.cmd.xferType    = MMCSD_DIR_DONTCARE;
            cmdObj.cmd.lineChr     = MMCSD_LINECHR_PUSHPULL;
            transaction.arg    = object->rca << 16U;
            transaction.flags       = MMCSD_CMDRSP_NONE;

            ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
        }
        if(MMCSD_OK == ret)
        {
            cmdObj.cmd.cmdId       = MMCSD_CMD(16U);
            cmdObj.cmd.rspType     = MMCSD_RESPTYPE_R1;
            cmdObj.cmd.busy        = MMCSD_RESPBUSY_NO;
            cmdObj.cmd.cmdType     = MMCSD_CMDTYPE_AC;
            cmdObj.cmd.xferType    = MMCSD_DIR_DONTCARE;
            cmdObj.cmd.lineChr     = MMCSD_LINECHR_PUSHPULL;
            transaction.arg         = object->blockSize;
            transaction.checkStatus = MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
            transaction.flags       = MMCSD_CMDRSP_NONE;
            ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
        }

#ifdef ENABLE_EMMC
        /* NOTE: Add delay */
        delay(100U);

        if(MMCSD_OK == ret)
        {
            cmdObj.cmd.cmdId        = MMCSD_CMD(8U);
            cmdObj.cmd.rspType      = MMCSD_RESPTYPE_R1;
            cmdObj.cmd.busy         = MMCSD_RESPBUSY_NO;
            cmdObj.cmd.cmdType      = MMCSD_CMDTYPE_ADTC;
            cmdObj.cmd.xferType     = MMCSD_DIR_DONTCARE;
            cmdObj.cmd.lineChr      = MMCSD_LINECHR_PUSHPULL;
            transaction.arg         = object->rca << 16U;
            transaction.blockCount  = 1U;
            transaction.blockSize   = 512U;
            transaction.checkStatus = MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;
            transaction.flags       = MMCSD_CMDRSP_READ | MMCSD_CMDRSP_WRITE;
            transaction.dataBuf     = object->ecsd;
            ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);

            object->blockCount = (((uint32_t)(object->ecsd[215])) << 24) +
                                 (((uint32_t)(object->ecsd[214])) << 16) +
                                 (((uint32_t)(object->ecsd[213])) << 8) +
                                 (((uint32_t)(object->ecsd[212])));
            object->size = (object->blockCount * object->blockSize);
            object->busWidth = MMCSD_BUS_WIDTH_8BIT;
            object->sdVer = object->ecsd[192];
        }
#endif
        /* NOTE: Add delay */
        delay(100U);

        if (MMCSD_OK == ret)
        {
            MMCSDSetBusWidth(hwAttrs->baseAddr, MMCSD_BUS_WIDTH_8BIT);
        }

        /* NOTE: Add delay */
        delay(100U);

    }

    /* Card intialization sequence is complete. Now the operating clock can be
       increased for data transfers */
     MMCSDFreqSet(hwAttrs->baseAddr, hwAttrs->mmcsdClockInfo.mmcPushPull, FALSE);

    if(MMCSD_OK != ret)
    {
        MMCSD_v0_close(handle);
    }

    return (ret);
}

/*
 *  ======== MMCSD_v0_transfer ========
 */
static MMCSD_Error MMCSD_v0_transfer(MMCSD_Handle handle,
                                     MMCSD_v0_Transaction *transaction, mmcsdCmd_t cmd)
{
    MMCSD_Error           ret = MMCSD_ERR;
#ifdef MMCSD_EDMA_ENABLED
    uint32_t              result = EDMA3_DRV_SOK;
    uint32_t              paRAM_cCount = 0;
    EDMA3_DRV_PaRAMRegs   paramSet   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    EDMA3_DRV_PaRAMRegs   paramSetDummy   = {0, 0, 0, 0, 0, 0xFFFF, 0, 0, 0, 0, 0, 0, 0};
#endif
    mmcsdCmdObj_t       cmdObj = {{0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U};
    MMCSD_v0_Object      *object = NULL;
    MMCSD_v0_HwAttrs     *hwAttrs = NULL;
    uint32_t			cnt = MMCSD_TIME_OUT_COUNT;
    uint32_t status;
    Bool readFlag;

    MMCSD_osalAssert(!((handle != NULL) && (transaction != NULL)));

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v0_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;
	cmdObj.cmd = cmd;

    ret = MMCSD_OK;

    if(MMCSD_OK == ret)
    {
        /* Configure the transfer type */
        cmdObj.enableData = (transaction->flags & MMCSD_CMDRSP_DATA) ? (uint32_t)TRUE : (uint32_t)FALSE;

        if(0U != hwAttrs->enableInterrupt)
        {
			MMCSDIntrDisable(hwAttrs->baseAddr, MMCSD_INTR_MASK_DXRDY);
            MMCSDIntrDisable(hwAttrs->baseAddr, MMCSD_INTR_MASK_DRRDY);
            MMCSDIntrDisable(hwAttrs->baseAddr, MMCSD_INTR_MASK_TRNDNE);
        }

		if (0 != cmdObj.enableData)
        {

			   /* Acquire the lock for this particular MMCSD handle */
            MMCSD_osalPendLock(object->transferMutex, SemaphoreP_WAIT_FOREVER);
            MMCSD_osalPendLock(object->commandMutex, SemaphoreP_WAIT_FOREVER);

            /*  MMCSD_osalHardwareIntrDisable(hwAttrs->intNum); */

            object->dataBufIdx = transaction->dataBuf;


            object->dataBlockCount = transaction->blockCount;
            object->dataBlockSize = transaction->blockSize;
            object->cmdComp = 0;
            object->cmdTimeout = 0;
            object->xferInProgress = 0;
            object->xferComp = 0;
            object->xferTimeout = 0;

            cmdObj.numBlks = (TRUE == cmdObj.enableData) ? object->dataBlockCount : 0U;

            if (MMCSD_DIR_READ == cmdObj.cmd.xferType)
            {
                /* Configure the transfer for read operation */
                MMCSDIntrEnable(hwAttrs->baseAddr, MMCSD_INTR_MASK_DRRDY);
                MMCSDIntrDisable(hwAttrs->baseAddr, MMCSD_INTR_MASK_DXRDY);

				object->readBlockCount=object->dataBlockCount;
                object->readBytesRemaining = (object->dataBlockCount * transaction->blockSize);
                readFlag = 1;
                
#ifdef MMCSD_EDMA_ENABLED
                if(0U != hwAttrs->enableDma && cmdObj.cmd.cmdId!=MMCSD_CMD(19U))
                {
                    /* Maintaining cache coherency. Write back the cache line and invalidate */
                    MMCSD_osalCache_wbInv(object->dataBufIdx,(transaction->blockSize * transaction->blockCount));
                    /* Get the PaRAM set for default parameters                               */
                    EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                            (uint32_t) hwAttrs->rxDmaEventNumber, &paramSet);

                    /* Fill the PaRAM Set with transfer specific information */
                    paramSet.destAddr  = (uint32_t)MMCSD_soc_l2_global_addr((uint32_t)object->dataBufIdx);

                    paramSet.srcAddr = (uint32_t) ((hwAttrs->baseAddr)
                                     + MMCSD_MMCDRR);

                    /**
                     * Validate the cCount value of EDMA3 PaRAM set is less than 65535
                     */
                    paRAM_cCount        = (object->dataBlockCount * \
                                             (MMCSD_BLOCK_SIZE / FIFO_LEVEL));
                    if(paRAM_cCount >= MMCSD_EDMA3CC_COUNT_VALUE)
					{
                        ret = MMCSD_ERR;
                    }

                    /**
                    * Be Careful !!!
                    * Valid values for SRCBIDX/DSTBIDX are between -32768 and 32767
                    * Valid values for SRCCIDX/DSTCIDX are between -32768 and 32767
                    */
                    paramSet.aCnt       = FIFO_WIDTH;
                    paramSet.bCnt       = FIFO_LEVEL/FIFO_WIDTH;
                    paramSet.cCnt       = (uint16_t) paRAM_cCount;
                    paramSet.srcBIdx    = 0;
                    paramSet.srcCIdx    = 0;

                    paramSet.destBIdx   = 4;
                    paramSet.destCIdx   = FIFO_LEVEL;

                    /* For AB-synchronized transfers, BCNTRLD is not used. */

                    paramSet.linkAddr   = 0xFFFFu;

                    paramSet.bCntReload = (uint16_t) 0;

                    /* Src is in INCR mode & Dest is in FIFO modes                        */
                    paramSet.opt &= MMCSD_EDMA3CC_OPT_DAM_INCR_MODE;
                    paramSet.opt &= MMCSD_EDMA3CC_OPT_SAM_INCR_MODE;

                    /* FIFO width is 8 bit                                                */
                    paramSet.opt |= (((uint32_t)0U) << 8);

                    /* EDMA3_DRV_SYNC_AB                                                  */
                    paramSet.opt &= MMCSD_EDMA3CC_OPT_SYNC_MASK_VALUE;
                    paramSet.opt |= MMCSD_EDMA3CC_OPT_SYNC_AB;

                    /* EDMA3_DRV_OPT_FIELD_TCINTEN                                        */
                    paramSet.opt |= ((uint32_t) 1U << MMCSD_OPT_TCINTEN_SHIFT);


                    /* ADDED FOR ARM PLATFORM                                             */
                    /* update the transfer completion code                                */
                    paramSet.opt &= (~MMCSD_EDMA3CC_OPT_TCC_MASK);
                    paramSet.opt |= (( hwAttrs->edmaRxTCC) << MMCSD_EDMA3CC_OPT_TCC_SHIFT);

                    if (MMCSD_OK == ret)
                    {
                        result = (uint32_t)EDMA3_DRV_setPaRAM(hwAttrs->edmaHandle, hwAttrs->rxDmaEventNumber, &paramSet);
                        if (result != ((uint32_t) EDMA3_DRV_SOK))
                        {
                            ret = MMCSD_ERR;
                        }
                    }

                    /* Disabling all the pending EDMA transfers to avoid unwanted Read DMA  */
                    /* event or a DMA miss                                                  */

                    if (MMCSD_OK == ret)
                    {
                        result = (uint32_t)EDMA3_DRV_disableTransfer(
                                (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                (uint32_t) hwAttrs->rxDmaEventNumber,
                                (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_EVENT);
                        if (result != ((uint32_t) EDMA3_DRV_SOK))
                        {
                            ret = MMCSD_ERR;
                        }
                    }

                    if (MMCSD_OK == ret)
                    {
                        result = (uint32_t)EDMA3_DRV_enableTransfer(
                                (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                (uint32_t) hwAttrs->rxDmaEventNumber,
                                (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_EVENT);
                        if (result != ((uint32_t) EDMA3_DRV_SOK))
                        {
                            ret = MMCSD_ERR;
                        }
                    }
                }
#endif
            }
            else
            {
#ifndef MMCSD_EDMA_ENABLED
                /* Configure the transfer for write operation */
                MMCSDIntrEnable(hwAttrs->baseAddr, MMCSD_INTR_MASK_DRRDY);
                MMCSDIntrDisable(hwAttrs->baseAddr, MMCSD_INTR_MASK_DXRDY);
#endif
                if(0U != hwAttrs->enableInterrupt)
                {
					MMCSDIntrDisable(hwAttrs->baseAddr, MMCSD_INTR_MASK_DXRDY);
                    MMCSDIntrDisable(hwAttrs->baseAddr, MMCSD_INTR_MASK_DRRDY);
                    MMCSDIntrDisable(hwAttrs->baseAddr, MMCSD_INTR_MASK_TRNDNE);

                }
				object->writeBlockCount=object->dataBlockCount;
                object->writeBytesRemaining = (object->dataBlockCount * transaction->blockSize);
                readFlag = 0;
                
#ifdef MMCSD_EDMA_ENABLED
                if(0U != hwAttrs->enableDma)
                {
                    /* Maintaining cache coherency */
                    MMCSD_osalCache_wb(object->dataBufIdx,(transaction->blockSize * transaction->blockCount));
                    /* Get the PaRAM set for default parameters                               */
                    EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                            (uint32_t) hwAttrs->txDmaEventNumber, &paramSet);

                    /* Fill the PaRAM Set with transfer specific information */
                    paramSet.srcAddr = (uint32_t)MMCSD_soc_l2_global_addr((uint32_t)object->dataBufIdx);

                    paramSet.destAddr = (uint32_t) ((hwAttrs->baseAddr)
                                     + MMCSD_MMCDXR);

                    /**
                     * Validate the cCount value of EDMA3 PaRAM set is less than 65535
                     */
                    paRAM_cCount        = (object->dataBlockCount * \
                                             (MMCSD_BLOCK_SIZE / FIFO_LEVEL));
                    if(paRAM_cCount >= MMCSD_EDMA3CC_COUNT_VALUE)
					{
                        ret = MMCSD_ERR;
                    }

                    /**
                    * Be Careful !!!
                    * Valid values for SRCBIDX/DSTBIDX are between -32768 and 32767
                    * Valid values for SRCCIDX/DSTCIDX are between -32768 and 32767
                    */
                    paramSet.aCnt       = FIFO_WIDTH;
                    paramSet.bCnt       = FIFO_LEVEL/FIFO_WIDTH;
                    paramSet.cCnt       = (uint16_t) paRAM_cCount;
                    paramSet.srcBIdx    = 4;
                    paramSet.srcCIdx    = FIFO_LEVEL;

                    paramSet.destBIdx   = 0;
                    paramSet.destCIdx   = 0;

                    /* For AB-synchronized transfers, BCNTRLD is not used. */

                    paramSet.linkAddr   = 0xFFFFu;

                    paramSet.bCntReload = (uint16_t) 0;

                    /* Src is in INCR mode & Dest is in FIFO modes                        */
                    paramSet.opt &= MMCSD_EDMA3CC_OPT_SAM_INCR_MODE;
                    paramSet.opt &= MMCSD_EDMA3CC_OPT_DAM_INCR_MODE;

                    /* FIFO width is 8 bit                                                */
                    paramSet.opt |= (((uint32_t)0U) << 8);

                    /* EDMA3_DRV_SYNC_AB                                                  */
                    paramSet.opt &= MMCSD_EDMA3CC_OPT_SYNC_MASK_VALUE;
                    paramSet.opt |= MMCSD_EDMA3CC_OPT_SYNC_AB;

                    /* EDMA3_DRV_OPT_FIELD_TCINTEN                                        */
                    paramSet.opt |= ((uint32_t) 1U << MMCSD_OPT_TCINTEN_SHIFT);

                    /* ADDED FOR ARM PLATFORM                                             */
                    /* update the transfer completion code                                */
                    paramSet.opt &= (~MMCSD_EDMA3CC_OPT_TCC_MASK);
                    paramSet.opt |= (( object->Txtcc) << MMCSD_EDMA3CC_OPT_TCC_SHIFT);

                    result = (uint32_t)EDMA3_DRV_setPaRAM(hwAttrs->edmaHandle, hwAttrs->txDmaEventNumber, &paramSet);
                    if (result != ((uint32_t) EDMA3_DRV_SOK))
                    {
                        ret = MMCSD_ERR;
                    }

                    if (MMCSD_OK == ret)
                    {
                        /* Get the PaRAM set for default parameters                               */
                        EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                                (uint32_t) object->edmaLinkChId, &paramSetDummy);

                        result = (uint32_t)EDMA3_DRV_setPaRAM(hwAttrs->edmaHandle, object->edmaLinkChId, &paramSetDummy);
                        if (result != ((uint32_t) EDMA3_DRV_SOK))
                        {
                            ret = MMCSD_ERR;
                        }
                    }

                    if (MMCSD_OK == ret)
                    {
                        result = (uint32_t)EDMA3_DRV_linkChannel(hwAttrs->edmaHandle, hwAttrs->txDmaEventNumber, object->edmaLinkChId);
                        if (result != ((uint32_t) EDMA3_DRV_SOK))
                        {
                            ret = MMCSD_ERR;
                        }
                    }

                    /* Disabling all the pending EDMA transfers to avoid unwanted Write DMA */
                    /* event or a DMA miss                                                  */

                    if (MMCSD_OK == ret)
                    {
                        result = (uint32_t)EDMA3_DRV_disableTransfer(
                                (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                (uint32_t) hwAttrs->txDmaEventNumber,
                                (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_EVENT);
                        if (result != ((uint32_t) EDMA3_DRV_SOK))
                        {
                            ret = MMCSD_ERR;
                        }
                    }

                    if (MMCSD_OK == ret)
                    {
                        result = (uint32_t)EDMA3_DRV_enableTransfer(
                                (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                (uint32_t) hwAttrs->txDmaEventNumber,
                                (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_EVENT);
                        if (result != ((uint32_t) EDMA3_DRV_SOK))
                        {
                            ret = MMCSD_ERR;
                        }
                    }
                }
#endif
            }

            MMCSDSetBlkLength(hwAttrs->baseAddr, transaction->blockSize);
            MMCSDSetNumBlocks(hwAttrs->baseAddr, object->dataBlockCount);
			/* Configure the FIFO level & dierction */
            MMCSDConfigureFIFO(hwAttrs->baseAddr, FIFO_LEVEL, readFlag);
            
            MMCSDSetDataTimeout(hwAttrs->baseAddr, MMCSD_DTOUT);

#ifndef MMCSD_EDMA_ENABLED
            MMCSDIntrEnable(hwAttrs->baseAddr,
                (MMCSD_INTR_MASK_CCS | MMCSD_INTR_MASK_TOUTRS |
                 MMCSD_INTR_MASK_TOUTRD | MMCSD_INTR_MASK_TRNDNE |
                 MMCSD_INTR_MASK_DXRDY | MMCSD_INTR_MASK_DATADONE));
#else
            MMCSDIntrEnable(hwAttrs->baseAddr, MMCSD_INTR_MASK_RSPDONE);
#endif

            cmdObj.cmdArg = transaction->arg;
#ifdef MMCSD_EDMA_ENABLED
            if(0U != hwAttrs->enableDma)
            {
                cmdObj.enableDma = 1U;
            }
            else
#endif
            {
                cmdObj.enableDma = 0U;
            }

#ifndef MMCSD_EDMA_ENABLED
            /* In case of write operation in CPU mode, need to load the FIFO with data befor 
               sending the command. */
            if ((MMCSD_DIR_WRITE == cmdObj.cmd.xferType))
            {
                MMCSDSetData(hwAttrs->baseAddr, (uint8_t *)transaction->dataBuf, FIFO_LEVEL);
                object->writeBytesRemaining -= FIFO_LEVEL;
                object->xferInProgress = 1;
            }            
#endif

			MMCSD_sendCommand(handle, &cmdObj, transaction->arg);

#ifdef LOG_EN
            MMCSD_drv_log(Diags_USER1,
                       "MMCSD:(%p) Pending on commandComplete semaphore",
                       hwAttrs->baseAddr);
#endif

            /*
             * Wait for the transfer to complete here.
             * It's OK to block from here because the MMCSD's Hwi will unblock
             * upon errors
             */

  			if(0U != hwAttrs->enableInterrupt)
            {
				MMCSD_osalPendLock(object->commandComplete, SemaphoreP_WAIT_FOREVER);

            }
			else
            {
                while ((0 == object->cmdComp) && (0 == object->cmdTimeout))
				{
					status = MMCSDGetIntrStatus(hwAttrs->baseAddr);
				    MMCSD_v0_cmdStatusFxn((uintptr_t) handle, status);
				}
            }

#ifdef LOG_EN
            MMCSD_drv_log4(Diags_USER1,
                       "MMCSD:(%p) Command transaction completed", hwAttrs->baseAddr);
#endif

            /* Command execution fail */
            if (1 == object->cmdTimeout)
            {
                ret = MMCSD_ERR;
                object->cmdTimeout = 0;
#ifdef LOG_EN
                MMCSD_drv_log4(Diags_USER1,
                        "MMCSD:(%p) Command Execution Failed", hwAttrs->baseAddr);
#endif
            }

            /* Command execution successful */
            if (1 == object->cmdComp)
            {
                ret = MMCSD_OK;
                object->cmdComp = 0;

                if(0==hwAttrs->enableInterrupt) {
                    object->xferInProgress = 1;
                }

				if(1 == hwAttrs->enableInterrupt) {

                    if (MMCSD_DIR_READ == cmdObj.cmd.xferType)	{
					  MMCSDIntrEnable(hwAttrs->baseAddr, MMCSD_INTR_MASK_DRRDY);
					  } else {
					  MMCSDIntrEnable(hwAttrs->baseAddr, MMCSD_INTR_MASK_DXRDY);
				     }
#ifdef SEMAPHORE_EMUWAITS
					 while(dataBufferCopyComplete_emuwait);
#endif
					 MMCSD_osalPendLock(object->dataBufferCopyComplete, SemaphoreP_WAIT_FOREVER);



 					 MMCSDIntrEnable(hwAttrs->baseAddr, MMCSD_INTR_MASK_TRNDNE);
				 }

                /* Git response for command sent to MMC device */
                MMCSDGetResponse(hwAttrs->baseAddr, cmdObj.cmd.rspType, transaction->response);
#ifdef LOG_EN
                MMCSD_drv_log(Diags_USER1,
                        "MMCSD:(%p) Command Execution Failed", hwAttrs->baseAddr);
#endif
            }


		   /* Release the lock for this particular MMCSD handle */
            MMCSD_osalPostLock(object->commandMutex);

            if(MMCSD_OK == ret)
            {
#ifdef LOG_EN
                MMCSD_drv_log(Diags_USER1,
                           "MMCSD:(%p) Pending on transferComplete semaphore",
                           hwAttrs->baseAddr);
#endif

                /*
                 * Wait for the transfer to complete here.
                 * It's OK to block from here because the MMCSD's Hwi will unblock
                 * upon errors
                 */
#ifdef MMCSD_EDMA_ENABLED
				 if(0U != hwAttrs->enableDma  && cmdObj.cmd.cmdId!=MMCSD_CMD(19U))
                {
                    if (MMCSD_DIR_READ == cmdObj.cmd.xferType)
                    {
                        MMCSD_osalPendLock(object->readSem, SemaphoreP_WAIT_FOREVER);
                    }
                    else
                    {
                        MMCSD_osalPendLock(object->writeSem, SemaphoreP_WAIT_FOREVER);
                    }
                }
#endif
				if(0U != hwAttrs->enableInterrupt)
                {
				   MMCSD_osalPendLock(object->transferComplete, SemaphoreP_WAIT_FOREVER);
                }
                else
                {
                    while ((0 == object->xferComp) && (0 == object->xferTimeout))
                    {
                        MMCSD_v0_xferStatusFxn2((uintptr_t) handle, status);
                        status = MMCSDGetIntrStatus(hwAttrs->baseAddr);
                    }
				}

#ifdef LOG_EN
                MMCSD_drv_log(Diags_USER1,
                           "MMCSD:(%p) Data transaction completed", hwAttrs->baseAddr);
#endif

                /* Data transfer successful */
                if (1 == object->xferTimeout)
                {
                    ret = MMCSD_ERR;
                    object->xferTimeout = 0;
#ifdef LOG_EN
                    MMCSD_drv_log(Diags_USER1,
                            "MMCSD:(%p) Data Transfer Failed", hwAttrs->baseAddr);
#endif
                }

                /* Data transfer fail */
                if (1 == object->xferComp)
                {
                    ret = MMCSD_OK;
                    object->xferComp = 0;
#ifdef LOG_EN
                    MMCSD_drv_log(Diags_USER1,
                            "MMCSD:(%p) Data Transfer Successful", hwAttrs->baseAddr);
#endif
                }
            }

               /* Release the lock for this particular MMCSD handle */
               MMCSD_osalPostLock(object->transferMutex);
        }
        else
        {
            /* Acquire the lock for this particular MMCSD handle */
            MMCSD_osalPendLock(object->commandMutex, SemaphoreP_WAIT_FOREVER);

            /* MMCSD_osalHardwareIntrDisable(hwAttrs->intNum); */

            object->cmdComp = 0;
            object->cmdTimeout = 0;

            cmdObj.cmdArg = transaction->arg;
            cmdObj.enableDma = 0;
            MMCSD_sendCommand(handle, &cmdObj, transaction->arg);

            if(0U != hwAttrs->enableInterrupt)
            {
                MMCSDIntrEnable(hwAttrs->baseAddr,
                    (MMCSD_INTR_MASK_CCS | MMCSD_INTR_MASK_TOUTRS | MMCSD_INTR_MASK_RSPDONE));
            }

            /* MMCSD_osalHardwareIntrEnable(hwAttrs->intNum); */

#ifdef LOG_EN
            MMCSD_drv_log(Diags_USER1,
                       "MMCSD:(%p) Pending on commandComplete semaphore",
                       hwAttrs->baseAddr);
#endif

            /*
             * Wait for the transfer to complete here.
             * It's OK to block from here because the MMCSD's Hwi will unblock
             * upon errors
             */
            if(0U != hwAttrs->enableInterrupt)
            {
                MMCSD_osalPendLock(object->commandComplete, SemaphoreP_WAIT_FOREVER);
            }
            else
            {
            	uint32_t status =0;
            	cnt = MMCSD_TIME_OUT_COUNT;
            	while(0 == (status & transaction->checkStatus) && (cnt != 0))
            	{
            		status = MMCSDGetIntrStatus(hwAttrs->baseAddr);
            		MMCSD_v0_cmdStatusFxn((uintptr_t) handle, status);
            		cnt--;
            	}
            }

#ifdef LOG_EN
            MMCSD_drv_log(Diags_USER1,
                       "MMCSD:(%p) Command transaction completed", hwAttrs->baseAddr);
#endif

            /* Command execution successful */
            if (1 == object->cmdComp)
            {
                ret = MMCSD_OK;
                object->cmdComp = 0;
            }

            /* Command execution fail */
            if (1 == object->cmdTimeout)
            {
                ret = MMCSD_ERR;
                object->cmdTimeout = 0;
#ifdef LOG_EN
                MMCSD_drv_log(Diags_USER1,
                        "MMCSD:(%p) Command Execution Failed", hwAttrs->baseAddr);
#endif
            }

            /* Git response for command sent to MMC device */
            MMCSDGetResponse(hwAttrs->baseAddr, cmdObj.cmd.rspType, transaction->response);

            /* Release the lock for this particular MMCSD handle */
            MMCSD_osalPostLock(object->commandMutex);
        }
    }
    
    /* Return the transaction status */
    return (ret);
}

/*
 *  ======== MMCSD_v0_control ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v0_control(MMCSD_Handle handle, uint32_t cmd, const void *arg)
{
    MMCSD_Error        ret = MMCSD_ERR;

    /* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

    switch (cmd)
    {
        case MMCSD_CMD_SETBUSWIDTH:
        {
            ret = MMCSD_v0_setBusWidth(handle, (uint32_t *)arg);
            break;
        }

        case MMCSD_CMD_GETBUSWIDTH:
        {
            ret = MMCSD_v0_getBusWidth(handle, (uint32_t *)arg);
            break;
        }

        case MMCSD_CMD_GETFREQUENCY:
        {
            ret = MMCSD_v0_getBusFreq(handle, (uint32_t *)arg);
            break;
        }

        case MMCSD_CMD_GETMEDIAPARAMS:
        {
            ret = MMCSD_v0_getMediaParams(handle, (MMCSD_mediaParams *)arg);
            break;
        }

        default:
        ret = MMCSD_UNDEFINEDCMD;
        break;
    }

    return ret;
}

/*
 *  ======== MMCSD_v0_setBusWidth ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v0_setBusWidth(MMCSD_Handle handle, const uint32_t *busWidth)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v0_Object            *object = NULL;
    MMCSD_v0_HwAttrs           *hwAttrs = NULL;
    MMCSD_v0_Transaction        transaction;
	mmcsdCmdObj_t				cmdObj = {0};

    /* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v0_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

    if (MMCSD_CARD_SD == object->cardType)
    {
        if ((MMCSD_BUS_WIDTH_4BIT == *busWidth) || (MMCSD_BUS_WIDTH_1BIT == *busWidth))
        {
            ret = MMCSD_OK;
        }

        /*Set BusWidth, Required to configure SD card in 4 bit mode of operation*/
        if(MMCSD_OK == ret)
        {
			/*Sending the  App commanad(55) before sending Bus Width
			  as both k2g and pspion using the same sequence*/
			cmdObj.cmd.cmdId    = MMCSD_CMD(55U);
			cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
			cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
			cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_AC;
			cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
			cmdObj.cmd.lineChr  = MMCSD_LINECHR_PUSHPULL;

			transaction.arg = object->rca << 16U;
			transaction.flags       = MMCSD_CMDRSP_NONE;
			transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;

			ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);
		}

		if(MMCSD_OK == ret)
		{
			/*Sending the set bus width command*/
			cmdObj.cmd.cmdId    = MMCSD_CMD(6U);
			cmdObj.cmd.rspType  = MMCSD_RESPTYPE_R1;
			cmdObj.cmd.busy	    = MMCSD_RESPBUSY_NO;
			cmdObj.cmd.cmdType  = MMCSD_CMDTYPE_AC;
			cmdObj.cmd.xferType = MMCSD_DIR_DONTCARE;
			cmdObj.cmd.lineChr  = MMCSD_LINECHR_PUSHPULL;

			transaction.arg = object->rca << 16U;
			transaction.flags       = MMCSD_CMDRSP_NONE;
			transaction.checkStatus	= MMCSD_EVENT_EOFCMD | MMCSD_EVENT_ERROR;

			/*Transcation args are used a k2g only as finally both the
			  pspion and k2g are finally sending 0x2U only as there args*/
			transaction.arg = MMCSD_BUS_WIDTH_1BIT;

			if (((MMCSD_v0_HwAttrs *)(((MMCSD_Config *) handle)->hwAttrs))->supportedBusWidth & MMCSD_BUS_WIDTH_4BIT)
			{
				if (object->busWidth & MMCSD_BUS_WIDTH_4BIT)
				{
					transaction.arg = MMCSD_BUS_WIDTH_4BIT;
				}
			}

			transaction.arg = transaction.arg >> 1U;
			ret = MMCSD_v0_transfer(handle, &transaction, cmdObj.cmd);

			if (MMCSD_OK == ret)
			{
				if (0U == transaction.arg)
				{
					MMCSDSetBusWidth(hwAttrs->baseAddr, MMCSD_MMCCTL_WIDTH1_WIDTH0_1BIT);
				}
				else
				{
					MMCSDSetBusWidth(hwAttrs->baseAddr, MMCSD_MMCCTL_WIDTH1_WIDTH0_4BIT);
				}
			}
		}
    }

    return(ret);
}

/*
 *  ======== MMCSD_v0_getBusWidth ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v0_getBusWidth(MMCSD_Handle handle, uint32_t *busWidth)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v0_Object            *object = NULL;

    /* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;

    if (MMCSD_CARD_SD == object->cardType)
    {
        *busWidth = object->busWidth;
        ret = MMCSD_OK;
    }

    return(ret);
}

/*
 *  ======== MMCSD_v0_getBusFreq ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v0_getBusFreq(MMCSD_Handle handle, uint32_t *busFreq)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v0_Object            *object = NULL;

    /* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;

    if (MMCSD_CARD_SD == object->cardType)
    {
        *busFreq = object->tranSpeed;
        ret = MMCSD_OK;
    }

    return(ret);
}

/*
 *  ======== MMCSD_v0_getMediaParams ========
 */
/*!
 *  @brief      This function returns the media (SD/eMMC/MMC)'s parameters
 *              such as size, blockCount and blockSize  .
 */
static MMCSD_Error MMCSD_v0_getMediaParams(MMCSD_Handle handle, MMCSD_mediaParams *params)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v0_Object            *object = NULL;

    /* Input parameter validation */
    MMCSD_osalAssert(handle == NULL);

    /* Input parameter validation */
    MMCSD_osalAssert(params == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v0_Object *)((MMCSD_Config *) handle)->object;

    params->blockSize = object->blockSize;
    params->blockCount = object->blockCount;
    params->size = object->size;
    
    ret = MMCSD_OK;
    
    return(ret);
}
/*
 *  ======== MMCSD_v0_hwiFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */
void MMCSD_v0_hwiFxn(uintptr_t arg)
{
    uint32_t                   errStatus;
    volatile uint32_t          status = 0U;
    volatile uint32_t          intrMask = 0U;
    volatile uint32_t          temp = 0U;
    volatile uint32_t          cnt = 0U;
    MMCSD_v0_Object           *object = NULL;
    MMCSD_v0_HwAttrs const    *hwAttrs = NULL;
    uint32_t offset;
    /* Input parameter validation */
    MMCSD_osalAssert((void *) arg == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = ((MMCSD_Config *)arg)->object;
    hwAttrs = ((MMCSD_Config *)arg)->hwAttrs;


    status = MMCSDGetIntrStatus(hwAttrs->baseAddr);
    intrMask = MMCSDIntrGet(hwAttrs->baseAddr);
    /* Command execution is complete */
    if (status & MMCSD_INTR_MASK_CCS)
    {
        object->cmdComp = 1;

		/* Indicate command complete */
        if (intrMask & MMCSD_INTR_MASK_CCS)
        {
			MMCSD_osalPostLock(object->commandComplete);
        }

    }    /* Error occurred in execution of command */

	errStatus = status & 0xFFFF0000U;

	if (errStatus & MMCSD_INTR_MASK_TOUTRS)
	{
		object->cmdTimeout = 1;

		/* Indicate command complete */
		if (intrMask & MMCSD_INTR_MASK_TOUTRS)
		{
			MMCSD_osalPostLock(object->commandComplete);
		}
	}

    if (status & MMCSD_INTR_MASK_RSPDONE)
    {
        object->cmdComp = 1;

        /* Indicate command complete */
        if (intrMask & MMCSD_INTR_MASK_RSPDONE)
        {
            MMCSD_osalPostLock(object->commandComplete);
        }
    }

    /* Read data received from card */
    if ((status & MMCSD_INTR_MASK_DRRDY) && (intrMask & MMCSD_INTR_MASK_DRRDY))
    {
        if ((object->dataBufIdx != NULL) && (object->readBytesRemaining > 0))
        {
		object->xferInProgress=1;
            offset=((object->dataBlockCount * object->dataBlockSize) - object->readBytesRemaining);
            MMCSDGetData(hwAttrs->baseAddr, ((uint8_t *)object->dataBufIdx + offset), FIFO_LEVEL);
            object->readBytesRemaining -= FIFO_LEVEL;

            if (object->readBytesRemaining==0)
            {

              MMCSD_osalPostLock(object->dataBufferCopyComplete);
            }
        }
    }

    /* Write data received from card */
    if (( status & MMCSD_INTR_MASK_DXRDY) && (intrMask & MMCSD_INTR_MASK_DXRDY))
    {
		if ((object->dataBufIdx != NULL) && (object->writeBytesRemaining > 0))
        {
            object->xferInProgress=1;
            offset=((object->dataBlockCount * object->dataBlockSize) - object->writeBytesRemaining);
            MMCSDSetData(hwAttrs->baseAddr, ((uint8_t *)object->dataBufIdx + offset), FIFO_LEVEL);
            object->writeBytesRemaining -= FIFO_LEVEL;

           if (object->writeBytesRemaining == 0)
           {
               object->writeBytesRemaining = 0;
               MMCSD_osalPostLock(object->dataBufferCopyComplete);
           }

        }
    }

    /*Data done is set, the data has been fully transmitter*/
    if (status & MMCSD_INTR_MASK_DATADONE)
    {
        if(1 == object->xferInProgress)
        {
            object->xferComp = 1;
            object->xferInProgress = 0;

            /* Indicate transfer complete */
            if (intrMask & MMCSD_INTR_MASK_DATADONE)
            {
                MMCSD_osalPostLock(object->transferComplete);
            }

        }
    }

    /* Error occurred in data transfer */
    if (status & MMCSD_INTR_MASK_TOUTRD)
    {
        if(1 == object->xferInProgress)
        {
            object->xferTimeout = 1;
            object->xferInProgress = 0;

            /* Indicate transfer complete */
            if (intrMask & MMCSD_INTR_MASK_TOUTRD)
            {
                MMCSD_osalPostLock(object->transferComplete);
            }

        }
    }

    /* Data transfer is complete */
    if ((status & MMCSD_INTR_MASK_TRNDNE) && (intrMask & MMCSD_INTR_MASK_TRNDNE))
    {
        if(1 == object->xferInProgress)
        {
            object->xferComp = 1;
            object->xferInProgress = 0;

            /* Indicate transfer complete */
            if (intrMask & MMCSD_INTR_MASK_TRNDNE)
            {
				MMCSD_osalPostLock(object->transferComplete);
            }
        }
    }
}

/*
 *  ======== MMCSD_v0_cmdStatusFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */
static void MMCSD_v0_cmdStatusFxn(uintptr_t arg, uint32_t status)
{
    MMCSD_v0_Object         *object = NULL;

    /* Input parameter validation */
    MMCSD_osalAssert((void *) arg == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = ((MMCSD_Config *)arg)->object;

    /* Command execution is complete */
    if ((status & MMCSD_EVENT_EOFCMD) || (status & MMCSD_INTR_MASK_RSPDONE))
    {
        object->cmdComp = 1;
    }

    if (status & MMCSD_EVENT_ERROR)
	{
		object->cmdTimeout = 1;
	}

    return;
}
/*
 *  ======== MMCSD_v0_xferStatusFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */
static void MMCSD_v0_xferStatusFxn2(uintptr_t arg, uint32_t status)
{
    volatile uint32_t        dataLen = 0U;
    //volatile uint32_t        status = 0U;
    volatile uint32_t        temp = 0U;
    volatile uint32_t        cnt = 0U;
    MMCSD_v0_Object         *object = NULL;
    MMCSD_v0_HwAttrs const  *hwAttrs = NULL;
    uint32_t offset;

    /* Input parameter validation */
    MMCSD_osalAssert((void *) arg == NULL);

    /* Get the pointer to the object and hwAttrs */
    object = ((MMCSD_Config *)arg)->object;
    hwAttrs = ((MMCSD_Config *)arg)->hwAttrs;

    //status = MMCSDGetIntrStatus(hwAttrs->baseAddr);

     /* Read data received from card */
    if (status & MMCSD_INTR_MASK_DRRDY)
    {
        if(1 == object->xferInProgress)
        {
            if ((object->dataBufIdx != NULL) && (object->readBytesRemaining > 0))
            {
                offset=((object->dataBlockCount * object->dataBlockSize) - object->readBytesRemaining);
                MMCSDGetData(hwAttrs->baseAddr, ((uint8_t *)object->dataBufIdx + offset), FIFO_LEVEL);
                object->readBytesRemaining -= FIFO_LEVEL;
            }
        }
    }

    /* Write data received from card */
    if (status & MMCSD_INTR_MASK_DXRDY)
    {
        if(1 == object->xferInProgress)
        {
            if ((object->dataBufIdx != NULL) && (object->writeBytesRemaining > 0))
            {
				offset=((object->dataBlockCount * object->dataBlockSize) - object->writeBytesRemaining);                
                MMCSDSetData(hwAttrs->baseAddr, ((uint8_t *)object->dataBufIdx + offset), FIFO_LEVEL);				
                object->writeBytesRemaining -= FIFO_LEVEL;
            }
        }
    }

    /* Data transfer is complete */
    if (status & MMCSD_INTR_MASK_DATADONE)
    {
        if(1 == object->xferInProgress)
        {
            object->xferComp = 1;
            object->xferInProgress = 0;
        }
    }

    return;
}

#ifdef MMCSD_EDMA_ENABLED
static void MMCSDDMA_rxIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData)
{
    MMCSD_Handle              handle;
    MMCSD_v0_HwAttrs    const *hwAttrs;
    MMCSD_v0_Object           *object ;

    if(appData != NULL) {
        handle = (MMCSD_Handle)appData;
        hwAttrs = ((MMCSD_Config *) handle)->hwAttrs;
        object = ((MMCSD_Config *) handle)->object;

        EDMA3_DRV_disableLogicalChannel(
                (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                (uint32_t) hwAttrs->rxDmaEventNumber,
                (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_EVENT);

        if (EDMA3_RM_XFER_COMPLETE != status) {
             /* Ensure to clear the error bits of EDMA channel                 */
               EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                       hwAttrs->rxDmaEventNumber);
        }

        object->dataBlockCount = 0;
        MMCSDDMA_readSemCallback((MMCSD_Handle)handle, object->dataBufIdx,
                    object->dataBlockCount);
    }

}

static void MMCSDDMA_txIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData)
{
    MMCSD_Handle                  handle;
    MMCSD_v0_HwAttrs const    *hwAttrs;
    MMCSD_v0_Object           *object ;


    if(appData != NULL) {

        handle = (MMCSD_Handle)appData;
        hwAttrs = ((MMCSD_Config *) handle)->hwAttrs;
        object = ((MMCSD_Config *) handle)->object;

      /*  if (EDMA3_RM_XFER_COMPLETE == status)*/
        {
              EDMA3_DRV_disableLogicalChannel(
                            (EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                            (uint32_t) hwAttrs->txDmaEventNumber,
                            (EDMA3_DRV_TrigMode) EDMA3_DRV_TRIG_MODE_EVENT);
         }
         if (EDMA3_RM_XFER_COMPLETE != status) {

             /* Ensure to clear the error bits of EDMA channel                 */
               EDMA3_DRV_clearErrorBits((EDMA3_DRV_Handle)hwAttrs->edmaHandle,
                       hwAttrs->txDmaEventNumber);
         }
        object->dataBlockCount = 0;
        MMCSDDMA_writeSemCallback((MMCSD_Handle)handle, (uint8_t*)object->dataBufIdx,
                                object->dataBlockCount);
    }

}

/*
 *  ======== writeSemCallback ========
 *  Simple callback to post a lock for the blocking mode.
 */
static void MMCSDDMA_writeSemCallback(MMCSD_Handle handle, void *buffer, size_t count)
{
    MMCSD_v0_Object *object = ((MMCSD_Config *) handle)->object;
    MMCSD_osalPostLock(object->writeSem);
}

/*
 *  ======== readSemCallback ========
 *  Simple callback to post a lock for the blocking mode.
 */
static void MMCSDDMA_readSemCallback(MMCSD_Handle handle, void *buffer, size_t count)
{
     MMCSD_v0_Object *object = ((MMCSD_Config *) handle)->object;
     MMCSD_osalPostLock(object->readSem);
}

#endif
/**
 * \brief  This API gets the SoC level of MMCSD intial configuration
 *
 * \param  index     MMC instance index.
 * \param  cfg       Pointer to MMCSD SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t MMCSD_socGetInitCfg(uint32_t index, MMCSD_v0_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < MMCSD_CNT)
    {
        *cfg = MMCSDInitCfg[index];
    }
    else
    {
        ret = -1;
    }

    return ret;
}
/**
 * \brief  This API sets the SoC level of MMCSD intial configuration
 *
 * \param  index     MMC instance index.
 * \param  cfg       Pointer to MMC SOC initial config.
 *
 * \return           0 success: -1: error
 *
 */
int32_t MMCSD_socSetInitCfg(uint32_t index, const MMCSD_v0_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < MMCSD_CNT)
    {
        MMCSDInitCfg[index] = *cfg;
    }
    else
    {
        ret = -1;
    }

    return ret;
}
/*
 *  ======== Delay function ========
 */
static void delay(uint32_t delayValue)
{
    volatile uint32_t delay1 = delayValue*10000U;
    while (delay1--) {}
}

#ifdef MMCSD_EDMA_ENABLED
static void MMCSDDMA_doNothing(uint32_t tcc, EDMA3_RM_TccStatus edmaStatus, void* appData)
{

}
#endif
