/**
 *  \file   MMCSD_v1.c
 *
 *  \brief  IP version 1 specific MMCSD Driver APIs implementation.
 *
 *   This file contains the driver APIs for MMCSD controller.
 */

/*
 * Copyright (C) 2017 - 2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdint.h>
#include <stdbool.h>
#include <ti/csl/csl_utils.h>
#include <ti/csl/hw_types.h>
#include <ti/csl/csl_error.h>
#include <ti/csl/csl_chip.h>
#include <ti/drv/mmcsd/src/MMCSD_drv_log.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_v1.h>
#include <ti/drv/mmcsd/src/v1/MMCSD_v1_lld.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
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

#define MMCSD_OCR_S18R  (BIT(24U))
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
#define MMCSD_CARD1_SIZE(crd) (((MMCSD_CARD1_DEV_SIZE((crd)) + 1U) * \
    (512U * 1024U)))

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

#define MMCSD_ECSD_BUS_WIDTH_INDEX (183U)
#define MMCSD_ECSD_BUS_WIDTH_1BIT       (0U)
#define MMCSD_ECSD_BUS_WIDTH_4BIT       (1U)
#define MMCSD_ECSD_BUS_WIDTH_8BIT       (2U)
#define MMCSD_ECSD_BUS_WIDTH_4BIT_DDR   (5U)
#define MMCSD_ECSD_BUS_WIDTH_8BIT_DDR   (6U)

#define MMCSD_ECSD_BUS_WIDTH_BUSWIDTH_MASK    (0x0FU)
#define MMCSD_ECSD_BUS_WIDTH_BUSWIDTH_SHIFT   (0U)

#define MMCSD_ECSD_BUS_WIDTH_ES_ENABLE    (0x80U)

#define MMCSD_ECSD_BUS_WIDTH_ES_MASK    (0x80U)
#define MMCSD_ECSD_BUS_WIDTH_ES_SHIFT   (7U)

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

/* Tuning pattern for SDR104 mode */
static const uint8_t tuning_blk_pattern_4bit[] = {
	0xff, 0x0f, 0xff, 0x00, 0xff, 0xcc, 0xc3, 0xcc,
	0xc3, 0x3c, 0xcc, 0xff, 0xfe, 0xff, 0xfe, 0xef,
	0xff, 0xdf, 0xff, 0xdd, 0xff, 0xfb, 0xff, 0xfb,
	0xbf, 0xff, 0x7f, 0xff, 0x77, 0xf7, 0xbd, 0xef,
	0xff, 0xf0, 0xff, 0xf0, 0x0f, 0xfc, 0xcc, 0x3c,
	0xcc, 0x33, 0xcc, 0xcf, 0xff, 0xef, 0xff, 0xee,
	0xff, 0xfd, 0xff, 0xfd, 0xdf, 0xff, 0xbf, 0xff,
	0xbb, 0xff, 0xf7, 0xff, 0xf7, 0x7f, 0x7b, 0xde,
};

/* MMC functions */
static MMCSD_Error MMCSD_v1_close(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v1_init(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v1_open(MMCSD_Handle handle, MMCSD_Params params);
static MMCSD_Error MMCSD_v1_write(MMCSD_Handle handle,
                                  uint8_t *buf,
                                  uint32_t block,
                                  uint32_t numBlks);
static MMCSD_Error MMCSD_v1_read(MMCSD_Handle handle,
                                 uint8_t *buf,
                                 uint32_t block,
                                 uint32_t numBlks);
static MMCSD_Error MMCSD_v1_transfer(MMCSD_Handle handle,
                                     MMCSD_v1_Transaction *transaction);
static MMCSD_Error MMCSD_v1_control(MMCSD_Handle handle, uint32_t cmd, const void *arg);
static MMCSD_Error MMCSD_v1_initSd(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v1_initEmmc(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v1_setBusWidth(MMCSD_Handle handle, const uint32_t *busWidth);
static MMCSD_Error MMCSD_v1_setBusFreq(MMCSD_Handle handle, const uint32_t *busFreq);
static MMCSD_Error MMCSD_v1_getBusWidth(MMCSD_Handle handle, uint32_t *busWidth);
static MMCSD_Error MMCSD_v1_getBusFreq(MMCSD_Handle handle, uint32_t *busFreq);
static MMCSD_Error MMCSD_v1_getMediaParams(MMCSD_Handle handle, MMCSD_mediaParams *params);
void MMCSD_v1_hwiFxn(uintptr_t arg);
static void MMCSD_v1_cmdStatusFxn(uintptr_t arg);
static void MMCSD_v1_xferStatusFxn(uintptr_t arg);
#ifdef MMCSD_EDMA_ENABLED
static void MMCSDDMA_rxIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData);
static void MMCSDDMA_txIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData);
static void MMCSDDMA_doNothing(uint32_t tcc, EDMA3_RM_TccStatus edmaStatus, void* appData);
static void MMCSDDMA_writeSemCallback(MMCSD_Handle handle, void *buffer, size_t count);
static void MMCSDDMA_readSemCallback(MMCSD_Handle handle, void *buffer, size_t count);
#endif
static uint32_t mmcsd_send_tuning(MMCSD_Handle handle);
static MMCSD_Error mmcsd_tuning_procedure(MMCSD_Handle handle);
static void MMCSD_v1_xferStatusFxn_CMD19(uintptr_t arg);
static MMCSD_Error MMCSD_switch_card_speed(MMCSD_Handle handle,uint32_t cmd16_grp1_fn);
static MMCSD_Error MMCSD_switch_card_curr_limit(MMCSD_Handle handle,uint32_t cmd16_grp4_fn);
/* Delay function */
static void delay(uint32_t delayValue);

/* MMC function table for MMC implementation */
const MMCSD_FxnTable MMCSD_v1_FxnTable = {
    &MMCSD_v1_close,
    &MMCSD_v1_control,
    &MMCSD_v1_init,
    &MMCSD_v1_open,
    &MMCSD_v1_write,
    &MMCSD_v1_read
};

/* Function to check if the media is ready to accept read/write transfers */
static MMCSD_Error mmcsd_check_transfer_ready(MMCSD_Handle handle)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    uint32_t                    cmd13_try_count = 0U;
    uint32_t                    current_state = 0U;
    MMCSD_v1_Object            *object = NULL;
    MMCSD_v1_Transaction        transaction;
    
    /* Input parameter validation */
    if(handle != NULL)
    {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
    
    if(object!=NULL)
    {
     /* 
      * Send CMD13 to check if the card is still in the programming state.
      * The card needs to go to transfer state before it can send/receive data
      */
     cmd13_try_count=0;
     do {
		memset(&transaction,0,sizeof(transaction));
        transaction.cmd = MMCSD_CMD(13U);
        transaction.flags = MMCSD_CMDRSP_48BITS;
        transaction.arg = object->rca << 16U;
        ret = MMCSD_v1_transfer(handle, &transaction);
        cmd13_try_count++;
        /* 'Current state' can be found from bits[9-12] of Card Status Register 
         * in the response R1 */ 
        current_state=(transaction.response[0] >> (9U) & (0xFU));

        if(current_state==MMCSD_CARD_STATE_TRANSFER) {
		   ret = MMCSD_OK;
		   break;
		}
     } while(cmd13_try_count < MMCSD_CARD_TRANS_STATE_THRESHOLD);
    }
  }   
  return(ret);
}

/*
 *  ======== MMCSD_v1_write ========
 */
static MMCSD_Error MMCSD_v1_write(MMCSD_Handle handle,
                           uint8_t *buf,
                           uint32_t block,
                           uint32_t numBlks)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    uint32_t                    key;
    uint32_t                    address = 0U;
    MMCSD_v1_Object            *object = NULL;
    MMCSD_v1_Transaction        transaction;

    /* Input parameter validation */
    if( (handle != NULL) && (buf != NULL) )
    {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
    
    if(object!=NULL)
    {
    object->writeBufIdx = buf;
    object->writeBlockCount = numBlks;

    /* Determine if the device index was already opened */
    key = MMCSD_osalHardwareIntDisable();
    if(0 != ((MMCSD_v1_Object *)(((MMCSD_Config *) handle)->object))->isOpen)
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

        transaction.flags = MMCSD_CMDRSP_WRITE | MMCSD_CMDRSP_DATA;
        transaction.arg = address;
        transaction.blockCount = numBlks;
        transaction.blockSize = object->blockSize;
        transaction.dataBuf = buf;

        if (numBlks > 1U)
        {
            transaction.cmd = MMCSD_CMD(25U);
            transaction.flags |= MMCSD_CMDRSP_ABORT;
        }
        else
        {
            transaction.cmd = MMCSD_CMD(24U);
        }

        ret = MMCSD_v1_transfer(handle, &transaction);
    }

    if(MMCSD_OK == ret)
    {
		/* Send a STOP */
        if (transaction.blockCount > 1U)
        {
			memset(&transaction,0,sizeof(transaction));
			transaction.cmd  = MMCSD_CMD(12U);
            transaction.flags = MMCSD_CMDRSP_BUSY;
            transaction.arg = 0U;

            ret = MMCSD_v1_transfer(handle, &transaction);
        }
    }
   }
  }
    return (ret);
}

/*
 *  ======== MMCSD_v1_read ========
 */
static MMCSD_Error MMCSD_v1_read(MMCSD_Handle handle,
                          uint8_t *buf,
                          uint32_t block,
                          uint32_t numBlks)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    uint32_t                    key;
    uint32_t                    address = 0U;
    MMCSD_v1_Object            *object = NULL;
    MMCSD_v1_Transaction        transaction;

    /* Input parameter validation */
    if( (handle != NULL) && (buf != NULL) )
    {

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
    
    if(object!=NULL)
    {
    object->readBufIdx = buf;
    object->readBlockCount = numBlks;

    /* Determine if the device index was already opened */
    key = MMCSD_osalHardwareIntDisable();
    if(0 != ((MMCSD_v1_Object *)(((MMCSD_Config *) handle)->object))->isOpen)
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

        transaction.flags = MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
        transaction.arg = address;
        transaction.blockCount = numBlks;
        transaction.blockSize = object->blockSize;
        transaction.dataBuf = buf;

        if (numBlks > 1U)
        {
            transaction.cmd = MMCSD_CMD(18U);
            transaction.flags |= MMCSD_CMDRSP_ABORT;
        }
        else
        {
            transaction.cmd = MMCSD_CMD(17U);
        }

        ret = MMCSD_v1_transfer(handle, &transaction);
    }
    if(MMCSD_OK == ret)
    {
        /* Send a STOP */
        if (transaction.blockCount > 1U)
        {
		    memset(&transaction,0,sizeof(transaction));
		    transaction.cmd  = MMCSD_CMD(12U);
            transaction.flags = MMCSD_CMDRSP_BUSY;
            transaction.arg = 0U;
            ret = MMCSD_v1_transfer(handle, &transaction);
        }
    }
   } 
  }
  return (ret);
}

/*
 *  ======== MMCSD_v1_close ========
 */
static MMCSD_Error MMCSD_v1_close(MMCSD_Handle handle)
{
    MMCSD_v1_Object   *object = NULL;
    MMCSD_v1_HwAttrs  *hwAttrs = NULL;
    MMCSD_Error ret=MMCSD_OK;

    /* Input parameter validation */
    if(handle != NULL)
    {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v1_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

    if( (object!=NULL) && (hwAttrs!=NULL) )
    {
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
       /* Unregister the interrupt */
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

    memset(object, 0, sizeof(MMCSD_v1_Object));

#ifdef LOG_EN
    MMCSD_drv_log(Diags_USER1, "MMCSD: Object closed 0x%x", ((MMCSD_Config *) handle)->hwAttrs->baseAddr);
#endif
    }
  }
  return (ret);
}

/*
 *  ======== MMCSD_v1_init ========
 */
static MMCSD_Error MMCSD_v1_init(MMCSD_Handle handle)
{
    /* Input parameter validation */
    if( (handle != NULL) && (((MMCSD_Config *) handle)->object!=NULL) )
    {
	  /* Initialize all elements to 0 */
  	  memset(((MMCSD_Config *) handle)->object,0,sizeof(MMCSD_v1_Object));
  	}  

    return (MMCSD_OK);
}

/*
 *  ======== MMCSD_v1_open ========
 */
static MMCSD_Error MMCSD_v1_open(MMCSD_Handle handle, MMCSD_Params params)
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
    MMCSD_v1_Object            *object = NULL;
    MMCSD_v1_HwAttrs           *hwAttrs = NULL;
    OsalRegisterIntrParams_t interruptRegParams;
    OsalInterruptRetCode_e interruptRegRet;
    MuxIntcP_inParams       muxInParams;
    MuxIntcP_outParams      muxOutParams;

    /* Input parameter validation */
    if(handle != NULL)
    {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v1_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

    if( (object!=NULL)  && (hwAttrs!=NULL) )
    {
    /* Determine if the device index was already opened */
    key = MMCSD_osalHardwareIntDisable();
    if(0 != ((MMCSD_v1_Object *)(((MMCSD_Config *) handle)->object))->isOpen)
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
            /* Construct Hwi object for this MMCSD peripheral */
           
		    /* Initialize with defaults */
            Osal_RegisterInterrupt_initParams(&interruptRegParams); 
            
            if (hwAttrs->muxNum != MMCSD_INVALID_MUXNUM)
            {
              /* Setup the mux if enabled */
              muxInParams.arg         = (uintptr_t)handle;
              muxInParams.muxNum      = hwAttrs->muxNum;
              muxInParams.muxInEvent  = hwAttrs->muxInEvent;
              muxInParams.muxOutEvent = hwAttrs->muxOutEvent;
              muxInParams.muxIntcFxn  = (MuxIntcFxn)(&MMCSD_v1_hwiFxn);

              MuxIntcP_create(&muxInParams, &muxOutParams);

              interruptRegParams.corepacConfig.isrRoutine = muxOutParams.muxIntcFxn;
              interruptRegParams.corepacConfig.arg = (uintptr_t)muxOutParams.arg;
            }
            else
            {
               interruptRegParams.corepacConfig.isrRoutine = (&MMCSD_v1_hwiFxn);
               interruptRegParams.corepacConfig.arg = (uintptr_t)handle;
            }

			/* Populate the interrupt parameters */
            interruptRegParams.corepacConfig.name=NULL;
	        interruptRegParams.corepacConfig.priority=0x20U;
#if defined (__ARM_ARCH_7A__)
            interruptRegParams.corepacConfig.triggerSensitivity = 0x3; /* interrupt edge triggered */
#endif
            interruptRegParams.corepacConfig.corepacEventNum=hwAttrs->eventId; /* Event going in to CPU */
            interruptRegParams.corepacConfig.intVecNum=hwAttrs->intNum; /* Host Interrupt vector */

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

    if(hwAttrs->inputClockControl) {
       /* Get the input clock value from the system*/
    	uint32_t inputClockRet;
    	inputClockRet=hwAttrs->inputClockControl(hwAttrs->instNum,NULL,MMCSD_INPUT_CLOCK_CTRL_GET);
    	if(inputClockRet!=0) {

    	  if(inputClockRet!=hwAttrs->inputClk) {
    		  MMCSD_drv_log4(Diags_USER1,"Input clock[%d] to MMC is different from what is set in hwAttrs",inputClockRet);
    	     hwAttrs->inputClk=inputClockRet;
    	  }
    	} else {
     	 MMCSD_drv_log(Diags_USER1,"Something is wrong. Input clock is not enabled!!");
     	 ret = MMCSD_ERR;
       }
    }
    if(MMCSD_OK == ret)
    {
        object->cardType = hwAttrs->cardType;

        if (MMCSD_CARD_SD == object->cardType)
        {
            ret = MMCSD_v1_initSd(handle);
        }
        else if (MMCSD_CARD_EMMC == object->cardType)
        {
            ret = MMCSD_v1_initEmmc(handle);
        }
        else
        {
            ret = MMCSD_ERR; /*dummy statement for misra warning*/
        }
    }

    /* Mark the object as in use */
    if(MMCSD_OK == ret)
    {
        ((MMCSD_v1_Object *)(((MMCSD_Config *) handle)->object))->isOpen = 1;
    }
   }
  }
    return (ret);
}
/* Data buffer for message transmission, it is not stack allocated to allow cache aligning */
#if defined(__GNUC__) && !defined(__ti__)
CSL_SET_DALIGN(256)  /* GCC way of aligning */
#else
CSL_SET_DALIGN(dataBuffer, 256)
#endif
static uint8_t                     dataBuffer[64U];

#if defined(__GNUC__) && !defined(__ti__)
CSL_SET_DALIGN(256)            /* GCC way of aligning */
#else
CSL_SET_DALIGN(cmd6_response_buf, 256)
#endif
static uint8_t                     cmd6_response_buf[64U];






/*
 *  ======== MMCSD_v1_initSd ========
 */
static MMCSD_Error MMCSD_v1_initSd(MMCSD_Handle handle)
{
    MMCSD_Error                 ret = MMCSD_OK;
    uint32_t                    retry = 0xFFFFU;
    MMCSD_v1_Object            *object = NULL;
    MMCSD_v1_HwAttrs           *hwAttrs = NULL;
    MMCSD_v1_Transaction        transaction;
    volatile int32_t            status = CSL_ESYS_FAIL;
    hsMmcsdSysCfg_t             sysCfg = {HS_MMCSD_CLK_ACT_ICLK_FCLK_OFF,
                                          HS_MMCSD_STANDBY_MODE_FORCE,
                                          HS_MMCSD_IDLE_MODE_FORCE,
                                          FALSE,
                                          TRUE};
    bool support18V_host=FALSE; 
	bool attempt_18V_switch=TRUE; /* Always be optimistic to start with, unless some cards do not work well with it */
    MMCSD_v1_IodelayParams      iodelayParams = {MMCSD_CARD_SD, MMCSD_TRANSPEED_25MBPS, MMCSD_VOLTAGE_ANY, MMCSD_LOOPBACK_ANY};

    /* Input parameter validation */
    if(handle != NULL)
    {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v1_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;
    
    if((object != NULL) && (hwAttrs!=NULL))
    {
	support18V_host=(hwAttrs->supportedBusVoltages & MMCSD_BUS_VOLTAGE_1_8V)?TRUE:FALSE;
	memset(dataBuffer,0,sizeof(dataBuffer));
	
    if(MMCSD_OK == ret)
    {
        /*
         * Refer to the MMC Host and Bus configuration steps in TRM
         * controller Reset
         */
        status = HSMMCSDSoftReset(hwAttrs->baseAddr);

        if (CSL_SOK != status)
        {
#ifdef LOG_EN
            MMCSD_drv_log(Diags_USER1,
                    "MMCSD:(%p) HS MMC/SD Reset failed", hwAttrs->baseAddr);
#endif
            ret = MMCSD_ERR;
        }
        else
        {
            ret = MMCSD_OK;
        }
    }

    if (MMCSD_OK == ret)
    {
        /* Lines Reset */
        HSMMCSDLinesReset(hwAttrs->baseAddr, HS_MMCSD_RESET_LINE_MASK_ALL);

        /* Set supported voltage list */
        HSMMCSDSetSupportedVoltage(hwAttrs->baseAddr,
            (HS_MMCSD_SUPP_VOLT_1P8 | HS_MMCSD_SUPP_VOLT_3P0));

        HSMMCSDSystemConfig(hwAttrs->baseAddr, &sysCfg);

        /* Set the bus width */
        HSMMCSDSetBusWidth(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_1BIT);

        /* Set the bus voltage */
		if(hwAttrs->supportedBusVoltages & MMCSD_BUS_VOLTAGE_3_0V) {
           HSMMCSDSetBusVolt(hwAttrs->baseAddr, HS_MMCSD_BUS_VOLT_3P0); /* Default */
		} else  if(hwAttrs->supportedBusVoltages & MMCSD_BUS_VOLTAGE_1_8V) {
           HSMMCSDSetBusVolt(hwAttrs->baseAddr, HS_MMCSD_BUS_VOLT_1P8); 
        }		   
        /* Bus power on */
        status = ((int32_t)(HSMMCSDBusPowerOnCtrl(hwAttrs->baseAddr, HS_MMCSD_PWR_CTRL_ON)));
		object->switched_to_v18=FALSE;
        if (CSL_SOK != status)
        {
#ifdef LOG_EN
            MMCSD_drv_log(Diags_USER1,
                    "MMCSD:(%p) HS MMC/SD Power on failed", hwAttrs->baseAddr);
#endif
            ret = MMCSD_ERR;
        }
    }

    if (MMCSD_OK == ret)
    {
        /* Set the initialization frequency */
        status = HSMMCSDSetBusFreq(hwAttrs->baseAddr, hwAttrs->inputClk,
            hwAttrs->outputClk, FALSE);
        if(NULL != hwAttrs->iodelayFxn)
        {
            iodelayParams.transferSpeed = MMCSD_TRANSPEED_25MBPS;
            hwAttrs->iodelayFxn(hwAttrs->instNum, &iodelayParams);
        }

        if (CSL_SOK != status)
        {
#ifdef LOG_EN
        MMCSD_drv_log(Diags_USER1,
          "MMCSD:(%p) HS MMC/SD Bus Frequency set failed", hwAttrs->baseAddr);
#endif
            ret = MMCSD_ERR;
        }

        if (MMCSD_OK == ret)
        {
            HSMMCSDInitStreamSend(hwAttrs->baseAddr);
        }
    }

    if(MMCSD_OK == ret)
    {
        /* CMD0 - reset card */
        transaction.cmd = MMCSD_CMD(0U);
        transaction.flags = MMCSD_CMDRSP_NONE;
        transaction.arg = 0U;
        ret = MMCSD_v1_transfer(handle, &transaction);
    }

    if(MMCSD_OK == ret)
    {
        /* APP cmd should be preceeded by a CMD55 */
        transaction.cmd = MMCSD_CMD(55U);
        transaction.flags = 0U;
        transaction.arg = object->rca << 16U;
        ret = MMCSD_v1_transfer(handle, &transaction);
    }

    if(MMCSD_OK == ret)
    {
        /*
         * Card type can be found by sending CMD55. If the card responds,
         * it is a SD card. Else, we assume it is a MMC Card
         */
        transaction.cmd = MMCSD_CMD(55U);
        transaction.flags = 0U;
        transaction.arg = 0U;
        ret = MMCSD_v1_transfer(handle, &transaction);
    }

    /* SD Card */
    if(MMCSD_OK == ret)
    {
        object->cardType = MMCSD_CARD_SD;

        /* CMD0 - reset card */
        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(0U);
            transaction.flags = MMCSD_CMDRSP_NONE;
            transaction.arg = 0U;
            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            uint32_t curr_bus_voltage;
			/* CMD8 - send oper voltage */
            transaction.cmd = MMCSD_CMD(8U);
            transaction.flags = 0U;
            transaction.arg = MMCSD_CHECK_PATTERN ;
            curr_bus_voltage=HSMMCSDGetBusVolt(hwAttrs->baseAddr);

            if(curr_bus_voltage==HS_MMCSD_BUS_VOLT_1P8)  {
               transaction.arg |= MMCSD_VOLT_LOW_RANGE;
			} else {
               transaction.arg |= MMCSD_VOLT_2P7_3P6;
            }			

            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if (MMCSD_OK != ret)
        {
            /*
             * If the cmd fails, it can be due to version < 2.0, since
             * we are currently supporting high voltage cards only
             */
        }

        if(MMCSD_OK == ret)
        {
            /* APP cmd should be preceeded by a CMD55 */
            transaction.cmd = MMCSD_CMD(55U);
            transaction.flags = 0U;
            transaction.arg = 0; /* object->rca is zero as the card is in the idle state */
            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            /* Go ahead and send ACMD41, with host capabilities */
            transaction.cmd = MMCSD_CMD(41U);
            transaction.flags = 0U;
            transaction.arg = MMCSD_OCR_HIGH_CAPACITY | MMCSD_OCR_VDD_WILDCARD;
            if(support18V_host) {
            	/* Host supports 1.8V and seek if the card supports it */
            	transaction.arg|= MMCSD_OCR_S18R;
            }
            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            /* Poll until we get the card status (BIT31 of OCR) is powered up */
            do
            {
                /* APP cmd should be preceeded by a CMD55 */
                transaction.cmd = MMCSD_CMD(55U);
                transaction.flags = 0U;
                transaction.arg = object->rca << 16U;
                ret = MMCSD_v1_transfer(handle, &transaction);

                if(MMCSD_OK == ret)
                {
                    transaction.cmd = MMCSD_CMD(41U);
                    transaction.flags = 0U;
                    transaction.arg = MMCSD_OCR_HIGH_CAPACITY | MMCSD_OCR_VDD_WILDCARD;
                    if(support18V_host) {
                    	/* Host supports 1.8V and seek if the card supports it */
                    	transaction.arg|= MMCSD_OCR_S18R;
                    }
                    MMCSD_v1_transfer(handle, &transaction);
                }
                else
                {
                    ret = MMCSD_ERR;
                    break;
                }
                retry--;
            } while (((transaction.response[0U] & ((uint32_t)BIT(31U))) == 0U) && (retry != 0));

            if (0U == retry)
            {
                /* No point in continuing */
                ret = MMCSD_ERR;
            }
        }

        if(MMCSD_OK == ret)
        {
            object->ocr = transaction.response[0U];
            /* Card capacity status (CCS) Bit 30 */  
            object->highCap = (object->ocr & MMCSD_OCR_HIGH_CAPACITY) ? 1U : 0U;

            /* Bit32 of the response R3 (S18A)*/
            object->support1_8V = (transaction.response[0U] & MMCSD_OCR_S18R) ? 1U : 0U;

			if(HSMMCSDGetBusVolt(hwAttrs->baseAddr)==HS_MMCSD_BUS_VOLT_1P8) {
			   attempt_18V_switch=FALSE;
			   object->switched_to_v18=TRUE; /* Already in 1.8V mode */
			} 
			/* If 1.8V is supported, configure the card accordingly to switch to SDR modes */
            if(object->support1_8V && support18V_host && attempt_18V_switch &&  (hwAttrs->switchVoltageFxn!=NULL) )
            {
                MMCSD_drv_log(Diags_USER1, "MMCSD: S18R indicates 1.8V support\n");

  			    bool falseloop_1p8V_switch=TRUE;
			    do 
			    {
			      int32_t retry_count=0;

			      falseloop_1p8V_switch=FALSE;
				  HSMMCSDSetCLKEXTFree(hwAttrs->baseAddr,CSL_MMCHS_CON_CLKEXTFREE_AUTOGATING);
				  HSMMCSDSetPAD(hwAttrs->baseAddr,CSL_MMCHS_CON_PADEN_ENABLE);
  			      
                  MMCSD_drv_log(Diags_USER1, "MMCSD: Sending CMD11 \n");
				  /* Start the voltage switching procedure */
                  /* Send CMD11 */
                  transaction.cmd = MMCSD_CMD(11U);
                  transaction.flags = MMCSD_CMDRSP_48BITS;
                  transaction.arg = 0U;
                  ret = MMCSD_v1_transfer(handle, &transaction);


                  if(MMCSD_OK == ret) 
				  {
                	   /* Voltage sequence acknowledge */
                	   MMCSD_drv_log(Diags_USER1,"MMCSD DRV:  Voltage sequence acknowledged via CMD11\n");

                       /* Wait for CMD and DAT levels to go low */
                	   retry_count=10;
                       do {
   				          delay(10);
					      retry_count--;
                       } while( (retry_count >0) && ((HSMMCSDGetCmdSignalLevel(hwAttrs->baseAddr)) ||  (HSMMCSDGetCmdSignalLevel(hwAttrs->baseAddr))));
                    
					   if(retry_count==0) {
					      /* CMD11 failed. Switch not possible */
					      ret=MMCSD_ERR_1P8V_SWITCH_CARD_CMD11_FAILURE;
					   }
                	
					
                	   MMCSD_drv_log(Diags_USER1,"MMCSD DRV:  Setting the SDVS and V1V8 SIGEN \n");

					   /* Enable 1.8V signalling. Set MMCHS_AC12[19] V1V8_SIGEN = 0x1
						Set MMCHS_HCTL[11:9] SDVS = 0x5 */
					   HSMMCSDSetBusVolt(hwAttrs->baseAddr, CSL_MMCHS_HCTL_SDVS__1V8);
					   /* Bus power on */
					   HSMMCSDBusPowerOnCtrl(hwAttrs->baseAddr, HS_MMCSD_PWR_CTRL_ON);

					   HSMMCSDV18SigSet(hwAttrs->baseAddr, CSL_MMCHS_AC12_V1V8_SIGEN__1V8); 

                	   /* Switch the voltage to 1.8V */
					    if(hwAttrs->switchVoltageFxn!=NULL) {
                   	      MMCSD_drv_log(Diags_USER1,"MMCSD DRV:  Calling the PBAIS and PMIC 1.8V switch \n");
						  ret = hwAttrs->switchVoltageFxn(hwAttrs->instNum,MMCSD_BUS_VOLTAGE_1_8V);
					    }  
                	    
						if(ret!=MMCSD_OK) {
                   	      MMCSD_drv_log(Diags_USER1,"PMIC/PBAIS switch failed\n");
						  ret=MMCSD_ERR_1P8V_SWITCH_MMCIO_SWITCH_FAILURE;
						   break;
						}
						
                        delay(100U); 
					    /* Force SD Card free running clock */
					    HSMMCSDSetCLKEXTFree(hwAttrs->baseAddr,CSL_MMCHS_CON_CLKEXTFREE_FREERUNNING);
					    delay(500U);
					    /* Check CMD and DAT Sig Levels. Wait until CLEV=1 and DLEV=1 */
                	    do {
   				          delay(10);
					      retry_count--;
                        } while( retry_count>0 && (!(HSMMCSDGetCmdSignalLevel(hwAttrs->baseAddr)) ||  !(HSMMCSDGetCmdSignalLevel(hwAttrs->baseAddr))));

					    if(retry_count==0) {
					      /* CMD11 failed. Switch not possible */
                   	      MMCSD_drv_log(Diags_USER1,"CMD and DAT levels still down, card not responding well to the switch..\n");
					      ret=MMCSD_ERR_1P8V_SWITCH_CARD_NOT_RESPONDING;
						  break;
					    }
                	
					    
						HSMMCSDSetPAD(hwAttrs->baseAddr,CSL_MMCHS_CON_PADEN_DISABLE);
					    HSMMCSDSetCLKEXTFree(hwAttrs->baseAddr,CSL_MMCHS_CON_CLKEXTFREE_AUTOGATING);
				 	    object->switched_to_v18=TRUE;
                 	    MMCSD_drv_log(Diags_USER1,"1.8V switching procedure complete\n");

					}  
                } while(falseloop_1p8V_switch);

			    if(ret!=MMCSD_OK) {
			      /* Reverse the voltage switch */
			      if(hwAttrs->switchVoltageFxn!=NULL) {
                     MMCSD_drv_log(Diags_USER1,"1.8V switching procedure FAILED. Switching back to 3.0V\n");
				     hwAttrs->switchVoltageFxn(hwAttrs->instNum,MMCSD_BUS_VOLTAGE_3_0V);
			      }
			    }
            } 
			
		}
	}   

    if(MMCSD_OK == ret) 
	{
            /* Send CMD2, to get the card identification register */
            transaction.cmd = MMCSD_CMD(2U);
            transaction.flags = MMCSD_CMDRSP_136BITS;
            transaction.arg = 0U;

            ret = MMCSD_v1_transfer(handle, &transaction);

            memcpy(object->cid, transaction.response, 16U);
        }

        if(MMCSD_OK == ret)
        {
            /* Send CMD3, to get the card relative address */
            transaction.cmd = MMCSD_CMD(3U);
            transaction.flags = 0U;
            transaction.arg = 0U;

            ret = MMCSD_v1_transfer(handle, &transaction);

            object->rca = MMCSD_RCA_ADDR(transaction.response[0U]);
        }
        uint8_t break_val = 0U;
        if(MMCSD_OK == ret)
        {
            do
            {
                /* Send CMD9, to get the card specific data */
                transaction.cmd = MMCSD_CMD(16U);
                transaction.flags = MMCSD_CMDRSP_NONE;
                transaction.arg = ((uint32_t)1U) << 10U;

                ret = MMCSD_v1_transfer(handle, &transaction);

                if(MMCSD_OK == ret)
                {
                    object->blockSize = 1024U;
                    object->blockCount = object->size / object->blockSize;
                    break_val = 1U;
                }

                if(break_val == 0U) 
                {
                      /* Send CMD9, to get the card specific data */
                      transaction.cmd = MMCSD_CMD(16U);
                      transaction.flags = MMCSD_CMDRSP_NONE;
                      transaction.arg = ((uint32_t)1U) << 9U;

                      ret = MMCSD_v1_transfer(handle, &transaction);

                      if(MMCSD_OK == ret)
                      {
                          object->blockSize = 1024U;
                          object->size = object->blockSize;
                          object->blockCount = object->size / object->blockSize;
                          object->blockSize = 512U;
                          object->blockCount = object->size / object->blockSize;
                          break_val = 1U;
                      }
                }

                if(break_val == 1U)
                {
                    break;
                }
            } while (0);
        }

        if(MMCSD_OK == ret)
        {
            /* Send CMD9, to get the card specific data */
            transaction.cmd = MMCSD_CMD(9U);
            transaction.flags = MMCSD_CMDRSP_136BITS;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v1_transfer(handle, &transaction);

            memcpy(object->csd, transaction.response, 16U);
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

            /* Set data block length to 512 (for byte addressing cards) */
            if((object->highCap) == 0U)
            {
                transaction.cmd = MMCSD_CMD(16U);
                transaction.flags = MMCSD_CMDRSP_NONE;
                transaction.arg = 512U;
                ret = MMCSD_v1_transfer(handle, &transaction);

                if(MMCSD_OK == ret)
                {
                    object->blockSize = 512U;
                }
            }
        }

        if(MMCSD_OK == ret)
        {
            /* Select the card */
            transaction.cmd = MMCSD_CMD(7U);
            transaction.flags = MMCSD_CMDRSP_BUSY;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            /*
             * Send ACMD51, to get the SD Configuration register details.
             * Note, this needs data transfer (on data lines).
             */
            transaction.cmd = MMCSD_CMD(55U);
            transaction.flags = 0U;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(51U);
            transaction.flags = MMCSD_CMDRSP_48BITS | MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
            transaction.arg = object->rca << 16U;
            transaction.blockCount = 1U;
            transaction.blockSize = 8U;
            transaction.dataBuf = dataBuffer;

            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            object->scr[0U] = (((uint32_t)(dataBuffer[3U])) << 24U) | (((uint32_t)(dataBuffer[2U])) << 16U) | \
                              (((uint32_t)(dataBuffer[1U])) << 8U) | (((uint32_t)(dataBuffer[0U])));
            object->scr[1U] = (((uint32_t)(dataBuffer[7U])) << 24U) | (((uint32_t)(dataBuffer[6U])) << 16U) | \
                              (((uint32_t)(dataBuffer[5U])) << 8U) | (((uint32_t)(dataBuffer[4U])));

            object->sdVer = MMCSD_CARD_VERSION(object);
            object->busWidth = MMCSD_CARD_BUSWIDTH(object);
        }

        if(MMCSD_OK == ret)
        {
            /* APP cmd should be preceeded by a CMD55 */
            transaction.cmd = MMCSD_CMD(55U);
            transaction.flags = 0U;
            transaction.arg = object->rca << 16U;
            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(6U);
            transaction.arg = MMCSD_BUS_WIDTH_1BIT;
            transaction.flags = 0U;

            if (((MMCSD_v1_HwAttrs *)(((MMCSD_Config *) handle)->hwAttrs))->supportedBusWidth & MMCSD_BUS_WIDTH_4BIT)
            {
                if (object->busWidth & MMCSD_BUS_WIDTH_4BIT)
                {
                    transaction.arg = MMCSD_BUS_WIDTH_4BIT;
                }
            }

            transaction.arg = transaction.arg >> 1U;
            ret = MMCSD_v1_transfer(handle, &transaction);

            if (MMCSD_OK == ret)
            {
                if (0U == transaction.arg)
                {
                    HSMMCSDSetBusWidth(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_1BIT);
                }
                else
                {
                    HSMMCSDSetBusWidth(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_4BIT);
                }
            }
        }

        MMCSD_drv_log(Diags_USER1,"Checking with CMD6 to see the capabilities\n");

		/* Check the CMD6 to see what function could be switched to */
        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(6U);
            transaction.arg = ((MMCSD_CHECK_MODE & MMCSD_CMD6_GRP1_SEL) |
                (MMCSD_CMD6_GRP1_DEFAULT));
            transaction.flags = MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
            transaction.blockCount = 1U;
            transaction.blockSize = 64U;
            transaction.dataBuf = dataBuffer;
            ret = MMCSD_v1_transfer(handle, &transaction);
        }

		
		/* Perform the switch and see what function it switches to */
        if(MMCSD_OK == ret)
        {
            uint32_t cmd16_grp1_fn;
			int32_t i;
			uint32_t cmd6_groups[5]={MMCSD_CMD6_GRP1_SDR104,MMCSD_CMD6_GRP1_SDR50,MMCSD_CMD6_GRP1_DDR50,MMCSD_CMD6_GRP1_HS,MMCSD_CMD6_GRP1_DEFAULT}; 

            MMCSD_drv_log(Diags_USER1,"With the response from CMD6, Trying each speed starting with preferable ones..\n");

			/* Go through the groups in a preferential manner and select the highest speed possible */
			for(i=0;i<5;i++) 
			{

             /* Go through the capabilites register and match with the card's speed 
                to arrive at an agreeable speed */
             /* See if 104 is available in response bits 415-400,  i.e bytes[12] and bytest[13] */
			 /* Please refer to the status response to CMD6 in the physical specification */

 			  if((cmd6_groups[i]==MMCSD_CMD6_GRP1_SDR104) && object->switched_to_v18 && HSMMCSDIsUHSSDR104Supported(hwAttrs->baseAddr) && (dataBuffer[13] & (1<< MMCSD_CMD6_GRP1_SDR104))) {
                cmd16_grp1_fn=MMCSD_CMD6_GRP1_SDR104;
                MMCSD_drv_log(Diags_USER1,"CMD6 Says Card Supports SDR104\n");
              } else if ((cmd6_groups[i]==MMCSD_CMD6_GRP1_SDR50) && object->switched_to_v18 &&  HSMMCSDIsUHSDDR50Supported(hwAttrs->baseAddr) && (dataBuffer[13] & (1<< MMCSD_CMD6_GRP1_SDR50))) {
                cmd16_grp1_fn=MMCSD_CMD6_GRP1_SDR50;			    
                MMCSD_drv_log(Diags_USER1,"CMD6 Says Card Supports SDR50\n");
  			  } else if ((cmd6_groups[i]==MMCSD_CMD6_GRP1_DDR50) && object->switched_to_v18 && HSMMCSDIsUHSSDR50Supported(hwAttrs->baseAddr) && (dataBuffer[13] & (1<< MMCSD_CMD6_GRP1_DDR50))) {
                cmd16_grp1_fn=MMCSD_CMD6_GRP1_DDR50;			    
                MMCSD_drv_log(Diags_USER1,"CMD6 Says Card Supports DDR50\n");
  			  } else if ((cmd6_groups[i]==MMCSD_CMD6_GRP1_HS) && HSMMCSDIsHighSpeedSupported(hwAttrs->baseAddr) && (dataBuffer[13] & (1<< MMCSD_CMD6_GRP1_HS))) { 			   
                 cmd16_grp1_fn=MMCSD_CMD6_GRP1_HS;			    
                 MMCSD_drv_log(Diags_USER1,"CMD6 Says Card Supports HS\n");
  			  } else if ((cmd6_groups[i]==MMCSD_CMD6_GRP1_DEFAULT) && (dataBuffer[13] & (1<< MMCSD_CMD6_GRP1_DEFAULT))) {
			     cmd16_grp1_fn=MMCSD_CMD6_GRP1_DEFAULT;
                 MMCSD_drv_log(Diags_USER1,"CMD6 Says Card Supports default\n");
			   } else {
				   continue;
			   }
 			   ret=MMCSD_switch_card_curr_limit (handle,MMCSD_CMD6_GRP4_800mA);
 	           if(ret!=MMCSD_OK) {
 	           	   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Current switch not successful\n");
 			   }
              ret=MMCSD_switch_card_speed(handle,cmd16_grp1_fn);
			  if(ret==MMCSD_OK) {
			     MMCSD_drv_log(Diags_USER1," Successfully switched to the above speed");
			     break;/* Successful switching */
			  }
 		    }
        }
 
        if(MMCSD_OK != ret)
        {
           MMCSD_v1_close(handle);
        }
     }   
   }     
        return (ret);
}
/***********************************************************************/
static MMCSD_Error MMCSD_switch_card_speed(MMCSD_Handle handle,uint32_t cmd16_grp1_fn)
{
   MMCSD_Error ret=MMCSD_ERR;
   MMCSD_v1_Object            *object = NULL;
   MMCSD_v1_HwAttrs           *hwAttrs = NULL;
   MMCSD_v1_Transaction        transaction;
   uint32_t uhsMode;
   Bool sdr104_tuning_required=FALSE,switch_speed_approved=TRUE;
   MMCSD_v1_IodelayParams      iodelayParams = {MMCSD_CARD_SD, MMCSD_TRANSPEED_25MBPS, MMCSD_VOLTAGE_ANY, MMCSD_LOOPBACK_ANY};

   if(handle!=NULL) 
   {
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
	hwAttrs = (MMCSD_v1_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;
   
   if( (object!=NULL) && (hwAttrs!=NULL) )
   { 
   memset(cmd6_response_buf,0,sizeof(cmd6_response_buf));
   /* Send CMD16 to switch to the requested group */
   transaction.cmd = MMCSD_CMD(6U);
   transaction.arg = ((MMCSD_SWITCH_MODE & MMCSD_CMD6_GRP1_SEL) | cmd16_grp1_fn);
   transaction.flags = MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
   transaction.blockCount = 1U;
   transaction.blockSize = 64U;
   transaction.dataBuf = cmd6_response_buf;
   
   ret = MMCSD_v1_transfer(handle, &transaction);
   
   if (MMCSD_OK == ret)
   {   /* Checking bits 379:376 of the CMD6 response  to see if the switch happened successfully */
     	uint32_t clk_freq,tranSpeed;
		
   	    if ((cmd6_response_buf[16U] & 0xFU) == MMCSD_CMD6_GRP1_SDR104 && (cmd16_grp1_fn==MMCSD_CMD6_GRP1_SDR104))
		{
		   tranSpeed = MMCSD_TRANSPEED_SDR104;
		   uhsMode=CSL_MMCHS_AC12_UHSMS_SDR104;
		   sdr104_tuning_required=TRUE;
		   clk_freq=208000000U; /* Max freq supported is 208MHz */
		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Request to switch to SDR104\n");

        } else if  ( ((cmd6_response_buf[16U] & 0xFU) == MMCSD_CMD6_GRP1_SDR50 ) && (cmd16_grp1_fn==MMCSD_CMD6_GRP1_SDR50))
	    {
		   tranSpeed = MMCSD_TRANSPEED_SDR50;
  		   uhsMode=CSL_MMCHS_AC12_UHSMS_SDR50;
		   clk_freq=100000000U; /* 100MHz for SDR50  */
		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Request to switch to SDR50\n");
		} else if  ( ((cmd6_response_buf[16U] & 0xFU) == MMCSD_CMD6_GRP1_DDR50) && (cmd16_grp1_fn==MMCSD_CMD6_GRP1_DDR50))
		{
		   tranSpeed = MMCSD_TRANSPEED_DDR50;
  		   uhsMode=CSL_MMCHS_AC12_UHSMS_DDR50;
		   clk_freq=50000000U; /* 50MHz for DDR50  */
           MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Request to switch to DDR50\n");

		}  else if (((cmd6_response_buf[16U] & 0xFU) == MMCSD_CMD6_GRP1_HS) && (cmd16_grp1_fn==MMCSD_CMD6_GRP1_HS))
		{
            tranSpeed = MMCSD_TRANSPEED_50MBPS;
		    uhsMode=CSL_MMCHS_AC12_UHSMS_SDR25;
 		    clk_freq=50000000U; /* 50MHz for HS mode */
 		    MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Request to switch to HS\n");
		} else if (((cmd6_response_buf[16U] & 0xFU) == MMCSD_CMD6_GRP1_DEFAULT) && (cmd16_grp1_fn==MMCSD_CMD6_GRP1_DEFAULT))
		{
           tranSpeed = MMCSD_TRANSPEED_25MBPS;
  		   uhsMode=CSL_MMCHS_AC12_UHSMS_SDR12;
    	   clk_freq=25000000U;  /* 25MHz for SDR12 */
		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Request to switch to SDR12\n");
	   
        } else {
		   /* Speed switch not approved */
    	   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Wrong Speed requested\n");
		   switch_speed_approved=FALSE;
		}

		if(switch_speed_approved)  {
		
			HSMMCSDSetDLLSWT(hwAttrs->baseAddr,0);
			 HSMMCSDDisableTuning(hwAttrs->baseAddr);
             HSMMCSDLinesReset(hwAttrs->baseAddr,CSL_MMCHS_SYSCTL_SRC_MASK);
             HSMMCSDLinesReset(hwAttrs->baseAddr,CSL_MMCHS_SYSCTL_SRD_MASK);
          /* Set input clock to make sure that the input clock is equal or higher to the clock value
           * requested */
  	      if(NULL != hwAttrs->inputClockControl) {
  	    	  uint32_t inputClockRet;
  	  	      if((inputClockRet=hwAttrs->inputClockControl(hwAttrs->instNum,&clk_freq,MMCSD_INPUT_CLOCK_CTRL_SET))!=0) {
                hwAttrs->inputClk=inputClockRet;
  	  	      } else {
  	  	    	MMCSD_drv_log4(Diags_USER1,"Unable to change input clock to %d\n",clk_freq);
  	  	      }
  	      }
 		  if(CSL_SOK == HSMMCSDSetBusFreq(hwAttrs->baseAddr, hwAttrs->inputClk, clk_freq, 0U))
          {
 	    	   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Setting Bus Frequency Succeeded \n");

 			  if(NULL != hwAttrs->iodelayFxn)
             {
               iodelayParams.transferSpeed = tranSpeed;
               MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Setting I/O delay \n");
               ret= hwAttrs->iodelayFxn(hwAttrs->instNum, &iodelayParams);
               if(ret==MMCSD_OK) {
            	   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Setting I/O delay succeeded\n");
               } else {
            	   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Setting I/O delay failed\n");
               }
             } else {
               ret = MMCSD_OK;
             }
          }
		  HW_WR_FIELD32((hwAttrs->baseAddr + CSL_MMCHS_SYSCTL), CSL_MMCHS_SYSCTL_CEN,
        0);
		  HSMMCSDSetAC12UHSMode(hwAttrs->baseAddr,uhsMode);
		  HW_WR_FIELD32((hwAttrs->baseAddr + CSL_MMCHS_SYSCTL), CSL_MMCHS_SYSCTL_CEN,
        1);
  		  /* Tuning mandatory for SDR104 */
		  if(sdr104_tuning_required) {
		    MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: About to execute Tuning procedure\n");
		    ret=mmcsd_tuning_procedure(handle);
			if(ret!=MMCSD_OK) {
			   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Tuning failed!\n");
			} else {
	           MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Tuning Successfully completed\n");
			}
          }
		  
   		  if(ret==MMCSD_OK) {
 		    MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: All OK so far\n");
		    object->tranSpeed=tranSpeed;
		  }

		} else {
		  MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Error!!\n");
 		  ret=MMCSD_ERR;
		}
	  }
	} 
   }
   return ret;
}

static MMCSD_Error MMCSD_switch_card_curr_limit(MMCSD_Handle handle,uint32_t cmd16_grp4_fn)
{
   MMCSD_Error ret=MMCSD_OK;
   MMCSD_v1_Transaction        transaction;

   memset(cmd6_response_buf,0,sizeof(cmd6_response_buf));
   /* Send CMD16 to switch to the requested group */
   transaction.cmd = MMCSD_CMD(6U);
   transaction.arg = ((MMCSD_SWITCH_MODE & MMCSD_CMD6_GRP4_SEL) | (cmd16_grp4_fn << 12 ) );
   transaction.flags = MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
   transaction.blockCount = 1U;
   transaction.blockSize = 64U;
   transaction.dataBuf = cmd6_response_buf;
   ret = MMCSD_v1_transfer(handle, &transaction);
   
   
   if (MMCSD_OK == ret)
   {   /* Checking bits 379:376 of the CMD6 response  to see if the switch happened successfully */
		
   	    if ((cmd6_response_buf[15U] >> 4) == MMCSD_CMD6_GRP4_200mA && (cmd16_grp4_fn==MMCSD_CMD6_GRP4_200mA))
		{
		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_curr_limit: Request to switch to 200mA successful\n");
        } else if  ( ((cmd6_response_buf[15U] >> 4) == MMCSD_CMD6_GRP4_400mA ) && (cmd16_grp4_fn==MMCSD_CMD6_GRP4_400mA))
	    {
		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_curr_limit: Request to switch to 400mA successful\n");
		} else if  ( ((cmd6_response_buf[15U] >> 4) == MMCSD_CMD6_GRP4_600mA) && (cmd16_grp4_fn==MMCSD_CMD6_GRP4_600mA))
		{
		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_curr_limit: Request to switch to 600mA successful\n");
		}  else if (((cmd6_response_buf[15U] >> 4) == MMCSD_CMD6_GRP4_800mA) && (cmd16_grp4_fn==MMCSD_CMD6_GRP4_800mA))
		{
		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_curr_limit: Request to switch to 700mA successful\n");
		} else {
		   /* Current not approved */
    	   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_curr_limit: Wrong current speed requested\n");
		   ret=MMCSD_ERR;
		}
   }

   return ret;
}
static uint32_t mmcsd_send_tuning(MMCSD_Handle handle) {

    uint8_t                     dataBuffer[64U] = {0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U,
                                                   0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U,
                                                   0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U,
                                                   0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U};
    MMCSD_Error                 ret = MMCSD_OK;
    MMCSD_v1_Transaction        transaction;
    Bool tuning_fail=FALSE;
	int i;
	uint32_t enableInterrupts;
	MMCSD_v1_HwAttrs *hwAttrs;
	hwAttrs = (MMCSD_v1_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

	enableInterrupts=hwAttrs->enableInterrupt;

	/* Send CMD19 */
    transaction.cmd = MMCSD_CMD(19U);
    transaction.arg = 0;
    transaction.flags = MMCSD_CMDRSP_48BITS | MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
    transaction.blockCount = 1U;
    transaction.blockSize = sizeof(tuning_blk_pattern_4bit); /* 64 bytes */
    transaction.dataBuf = dataBuffer;/* Tuning data from the SD card comes here */
    ret = MMCSD_v1_transfer(handle, &transaction);
		  
    if(ret==MMCSD_OK) {
	  /* Compare the data recieved from the card to the expected values*/
	  for(i=0;i<sizeof(tuning_blk_pattern_4bit);i++) {
	    if(dataBuffer[i]!=tuning_blk_pattern_4bit[i]) {
		   tuning_fail=TRUE;
		 break;
		}
	  }
	} else {
	   tuning_fail=TRUE;
    }	
	
    hwAttrs->enableInterrupt=enableInterrupts;
    return(tuning_fail);
}

/*
 ***********************************************************************
 *  ======== Returns tuning status ========
 **********************************************************************/
#define TUNING_MAX_PHASE_DELAY (0x7CU)
static MMCSD_Error mmcsd_tuning_procedure(MMCSD_Handle handle) {

     uint32_t phase_delay,length=0,max_len=0,start_window=0,max_window=0,cur_match=0,prev_match=0;
       
	 MMCSD_v1_HwAttrs *hwAttrs;
	 hwAttrs = (MMCSD_v1_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;
     /* Set MMCHS_DLL[20] SWT to 0x1 */
     HSMMCSDSetDLLSWT(hwAttrs->baseAddr,1);

     phase_delay=0;
     while (phase_delay <= TUNING_MAX_PHASE_DELAY) {
	 /*
		   Set MMCHS_DLL[12] FORCE_VAL to 1 
		   Set MMCHS_DLL[19:13] FORCE_SR_C to 0x0 ( in increments of 4)
		   Set MMCHS_DLL[1] DLL_CALIB to 0x1. This transfers the FORCE_SR_C value to the slave delay line.
		   Set MMCHS_DLL[12] DLL_CALIB to 0
	  */
	   HSMMCSDSetDLL(hwAttrs->baseAddr, phase_delay);
           
       /* Send CMD19 for SD card */
	   cur_match =  !mmcsd_send_tuning(handle);
	   if (cur_match) {
		  if (prev_match) {
			 length++;
		  } else {
			 start_window = phase_delay;
			 length = 1;
		  }
  	    }

	    if (length > max_len) {
	 	  max_window = start_window;
		  max_len = length;
 	    }

	    prev_match = cur_match;
	    phase_delay += 4;
    }
		
	/*  Check if MMCHS_AC12[23] SCLK_SEL= 0x1 */
	if(HSMMCSDGetAC12SCLKSEL(hwAttrs->baseAddr)!=1) {
	  return MMCSD_ERR; /* Error */
	}

	if(max_len==0) {
		return MMCSD_ERR;
	}

	/* Select the centred delay of the largest set of successful try
	 and program it in to the MMCHS_DLL[19:13} FORCE_SR_C bit field */
  	/* Set the MMCSHS DLL[1] DLL_CALIB to 0x1 so that the DLL takes in to account
      the new FORCE_SR_C value */
	phase_delay = max_window + 4 * (max_len >> 1);
  	HSMMCSDSetDLL(hwAttrs->baseAddr, phase_delay);
		   
   /* Reset the DAT and CMD lines by setting to 0x1 both the
      MMCHS_SYSCTRL[26] SRD and MMCHS_SYSCTRL[25] SRC bits   in order to
      clear any pending interrupt sources that were masked during the tuning sequence
   */
		
   HSMMCSDLinesReset(hwAttrs->baseAddr,CSL_MMCHS_SYSCTL_SRC_MASK);
   HSMMCSDLinesReset(hwAttrs->baseAddr,CSL_MMCHS_SYSCTL_SRD_MASK);
		/* Ensure that MMCHS_DLL[20] SWT remains 0x1 at exit */
   if(!HSMMCSDGetDLLSWT(hwAttrs->baseAddr))
     return MMCSD_ERR; /* Error */
	return MMCSD_OK;		 
}

/*
 *  ======== MMCSD_open ========
 */
static MMCSD_Error MMCSD_v1_initEmmc(MMCSD_Handle handle)
{
    MMCSD_Error                 ret = MMCSD_OK;
    uint32_t                    retry = 0xFFFFU;
    MMCSD_v1_Object            *object = NULL;
    MMCSD_v1_HwAttrs           *hwAttrs = NULL;
    MMCSD_v1_Transaction        transaction;
    volatile int32_t            status = CSL_ESYS_FAIL;
    hsMmcsdSysCfg_t             sysCfg = {HS_MMCSD_CLK_ACT_ICLK_FCLK_OFF,
                                          HS_MMCSD_STANDBY_MODE_FORCE,
                                          HS_MMCSD_IDLE_MODE_FORCE,
                                          FALSE,
                                          TRUE};
    MMCSD_v1_IodelayParams      iodelayParams = {MMCSD_CARD_EMMC, MMCSD_TRANSPEED_25MBPS, MMCSD_VOLTAGE_ANY, MMCSD_LOOPBACK_ANY};
    uint32_t controller_buswidth = HS_MMCSD_BUS_WIDTH_1BIT;  /* Default */
    uint8_t ecsd_bus_with      = MMCSD_ECSD_BUS_WIDTH_1BIT; /* Default */

    /* Input parameter validation */
    if(handle != NULL)
    {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v1_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

    if( (object !=NULL) && (hwAttrs!=NULL) )
    {
    if(MMCSD_OK == ret)
    {
        /*
         * Refer to the MMC Host and Bus configuration steps in TRM
         * controller Reset
         */
        status = HSMMCSDSoftReset(hwAttrs->baseAddr);

        if (CSL_SOK != status)
        {
#ifdef LOG_EN
            MMCSD_drv_log(Diags_USER1,
                    "MMCSD:(%p) HS MMC/SD Reset failed", hwAttrs->baseAddr);
#endif
            ret = MMCSD_ERR;
        }
        else
        {
            ret = MMCSD_OK;
        }
    }

    if (MMCSD_OK == ret)
    {
        /* Lines Reset */
        HSMMCSDLinesReset(hwAttrs->baseAddr, HS_MMCSD_RESET_LINE_MASK_ALL);

        /* Set supported voltage list */
        HSMMCSDSetSupportedVoltage(hwAttrs->baseAddr,
            (HS_MMCSD_SUPP_VOLT_1P8 | HS_MMCSD_SUPP_VOLT_3P0));

        HSMMCSDSystemConfig(hwAttrs->baseAddr, &sysCfg);

        /* Set the bus width */
        HSMMCSDSetBusWidth(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_1BIT);

        /* Set the bus voltage */
        HSMMCSDSetBusVolt(hwAttrs->baseAddr, HS_MMCSD_BUS_VOLT_3P0);

        /* Bus power on */
        status = ((int32_t)(HSMMCSDBusPowerOnCtrl(hwAttrs->baseAddr, HS_MMCSD_PWR_CTRL_ON)));

        if (CSL_SOK != status)
        {
#ifdef LOG_EN
            MMCSD_drv_log(Diags_USER1,
                    "MMCSD:(%p) HS MMC/SD Power on failed", hwAttrs->baseAddr);
#endif
            ret = MMCSD_ERR;
        }
    }

    if (MMCSD_OK == ret)
    {
        /* Set the initialization frequency */
        status = HSMMCSDSetBusFreq(hwAttrs->baseAddr, hwAttrs->inputClk,
            hwAttrs->outputClk, FALSE);
        if(NULL != hwAttrs->iodelayFxn)
        {
            iodelayParams.transferSpeed = MMCSD_TRANSPEED_25MBPS;
            hwAttrs->iodelayFxn(hwAttrs->instNum, &iodelayParams);
        }

        if (CSL_SOK != status)
        {
#ifdef LOG_EN
        MMCSD_drv_log(Diags_USER1,
          "MMCSD:(%p) HS MMC/SD Bus Frequency set failed", hwAttrs->baseAddr);
#endif
            ret = MMCSD_ERR;
        }

        if (MMCSD_OK == ret)
        {
            HSMMCSDInitStreamSend(hwAttrs->baseAddr);
        }
    }

    if(MMCSD_OK == ret)
    {
        /* CMD0 - reset card */
        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(0U);
            transaction.flags = MMCSD_CMDRSP_NONE;
            transaction.arg = 0U;
            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        /* NOTE: Add delay */
        delay(5U);

        if(MMCSD_OK == ret)
        {
            /* Poll until we get the card status (BIT31 of OCR) is powered up */
            do
            {
                /* APP cmd should be preceeded by a CMD55 */
                transaction.cmd = MMCSD_CMD(1U);
                transaction.flags = 0U;
                transaction.arg = 0xC0FF8080U;
                ret = MMCSD_v1_transfer(handle, &transaction);
                retry--;
            } while (((transaction.response[0U] & ((uint32_t)BIT(31U))) == 0U) && (retry != 0));

            if (0U == retry)
            {
                /* No point in continuing */
                ret = MMCSD_ERR;
            }
        }

        if(MMCSD_OK == ret)
        {
            object->ocr = transaction.response[0U];

            object->highCap = (object->ocr & MMCSD_OCR_HIGH_CAPACITY) ? 1U : 0U;

            /* Send CMD2, to get the card identification register */
            transaction.cmd = MMCSD_CMD(2U);
            transaction.flags = MMCSD_CMDRSP_136BITS;
            transaction.arg = 0U;

            ret = MMCSD_v1_transfer(handle, &transaction);

            memcpy(object->cid, transaction.response, 16U);
        }

        if(MMCSD_OK == ret)
        {
            object->rca = 2U;

            /* Send CMD3, to get the card relative address */
            transaction.cmd = MMCSD_CMD(3U);
            transaction.flags = 0U;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            /* Send CMD9, to get the card specific data */
            transaction.cmd = MMCSD_CMD(9U);
            transaction.flags = MMCSD_CMDRSP_136BITS;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v1_transfer(handle, &transaction);

            memcpy(object->csd, transaction.response, 16U);
        }

        if(MMCSD_OK == ret)
        {
            object->tranSpeed = ((object->csd[3] & 0x000000FFU));
            object->blockSize = (((uint32_t)2U)<<(((object->csd[0] & 0x03C00000U) >> 22)-1U));

            if (((object->csd[3] & 0x3C000000U) >> 26) != 0x04U)
            {
                ret = MMCSD_ERR;
            }
        }

        if(MMCSD_OK == ret)
        {
            /* Select the card */
            transaction.cmd = MMCSD_CMD(7U);
            transaction.flags = MMCSD_CMDRSP_BUSY;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(8U);
            transaction.flags = MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
            transaction.arg = object->rca << 16U;
            transaction.blockCount = 1U;
            transaction.blockSize = 512U;
            transaction.dataBuf = object->ecsd;

            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        /* NOTE: Add delay */
        delay(100U);

        if(MMCSD_OK == ret)
        {
            object->blockCount = (((uint32_t)(object->ecsd[215])) << 24) +
                                 (((uint32_t)(object->ecsd[214])) << 16) +
                                 (((uint32_t)(object->ecsd[213])) << 8) +
                                 (((uint32_t)(object->ecsd[212])));
            object->size = (object->blockCount * object->blockSize);
            object->busWidth = MMCSD_BUS_WIDTH_8BIT;
            object->sdVer = object->ecsd[192];
        }

        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(6U);
            transaction.arg = 0x03B90100;
            transaction.flags = MMCSD_CMDRSP_BUSY;
            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if (MMCSD_OK == ret)
        {
            if (MMCSD_TRANSPEED_50MBPS == object->tranSpeed)
            {
                if(CSL_SOK == HSMMCSDSetBusFreq(hwAttrs->baseAddr, hwAttrs->inputClk, 52000000U, 0U))
                {
                    if(NULL != hwAttrs->iodelayFxn)
                    {
                        iodelayParams.transferSpeed = MMCSD_TRANSPEED_50MBPS;
                        hwAttrs->iodelayFxn(hwAttrs->instNum, &iodelayParams);
                    }
                    ret = MMCSD_OK;
                }
            }
            else
            {
                if(CSL_SOK == HSMMCSDSetBusFreq(hwAttrs->baseAddr, hwAttrs->inputClk, 26000000U, 0U))
                {
                    if(NULL != hwAttrs->iodelayFxn)
                    {
                        iodelayParams.transferSpeed = MMCSD_TRANSPEED_25MBPS;
                        hwAttrs->iodelayFxn(hwAttrs->instNum, &iodelayParams);
                    }
                    ret = MMCSD_OK;
                }
            }
        }

        /* NOTE: Add delay */
        delay(100U);
       /* Setting the bus width as per the allowed configuration */
       if(hwAttrs->supportedBusWidth & MMCSD_BUS_WIDTH_8BIT) {
          controller_buswidth = HS_MMCSD_BUS_WIDTH_8BIT;
          ecsd_bus_with = MMCSD_ECSD_BUS_WIDTH_8BIT;
	   } else if(hwAttrs->supportedBusWidth & MMCSD_BUS_WIDTH_4BIT) {
          controller_buswidth = HS_MMCSD_BUS_WIDTH_4BIT;
          ecsd_bus_with = MMCSD_ECSD_BUS_WIDTH_4BIT;
	   } else if(hwAttrs->supportedBusWidth & MMCSD_BUS_WIDTH_1BIT) {
          controller_buswidth = HS_MMCSD_BUS_WIDTH_1BIT;
          ecsd_bus_with = MMCSD_ECSD_BUS_WIDTH_1BIT;
       }
        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(6U);
          transaction.arg = 0x03000000 | (MMCSD_ECSD_BUS_WIDTH_INDEX << 16) | (( (0 << MMCSD_ECSD_BUS_WIDTH_ES_SHIFT) | ecsd_bus_with) << 8);
            transaction.flags = MMCSD_CMDRSP_BUSY;

            ret = MMCSD_v1_transfer(handle, &transaction);
        }
        object->busWidth = controller_buswidth;

        /* NOTE: Add delay */
        delay(100U);

        if (MMCSD_OK == ret)
        {
          HSMMCSDSetBusWidth(hwAttrs->baseAddr, controller_buswidth);
        }

        /* NOTE: Add delay */
        delay(100U);

        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(6U);
            transaction.arg = 0x03A20100;
            transaction.flags = MMCSD_CMDRSP_BUSY;
            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        /* NOTE: Add delay */
        delay(100U);
    }

    if(MMCSD_OK != ret)
    {
        MMCSD_v1_close(handle);
    }
   } 
  }
    return (ret);
}

/*
 *  ======== MMCSD_v1_transfer ========
 */
static MMCSD_Error MMCSD_v1_transfer(MMCSD_Handle handle,
                                     MMCSD_v1_Transaction *transaction)
{
    MMCSD_Error           ret = MMCSD_ERR;
#ifdef MMCSD_EDMA_ENABLED
    uint32_t              result = EDMA3_DRV_SOK;
    EDMA3_DRV_PaRAMRegs   paramSet   = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    EDMA3_DRV_PaRAMRegs   paramSetDummy   = {0, 0, 0, 0, 0, 0xFFFF, 0, 0, 0, 0, 0, 0, 0};
#endif
    hsMmcsdCmdObj_t       cmdObj = {{0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U};
    MMCSD_v1_Object      *object = NULL;
    MMCSD_v1_HwAttrs     *hwAttrs = NULL;

    if((handle != NULL) && (transaction != NULL))
    {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v1_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;
    
    if( (object!=NULL) && (hwAttrs!=NULL) )
    {
    ret = MMCSD_OK;
	
    if(MMCSD_OK == ret)
    {
        /* Configure the command type to be executed from the command flags */
        if (transaction->flags & MMCSD_CMDRSP_STOP)
        {
            cmdObj.cmd.cmdType = HS_MMCSD_CMD_TYPE_BUS_SUSPEND;
        }
        else if (transaction->flags & MMCSD_CMDRSP_FS)
        {
            cmdObj.cmd.cmdType = HS_MMCSD_CMD_TYPE_FUNC_SEL;
        }
        else if (transaction->flags & MMCSD_CMDRSP_ABORT)
        {
            cmdObj.cmd.cmdType = HS_MMCSD_CMD_TYPE_IO_ABORT;
        }
        else
        {
            cmdObj.cmd.cmdType = 0U; /*dummy statement for misra warning*/
        }

        /* Configure the response type from the command flags */
        if (transaction->flags & MMCSD_CMDRSP_NONE)
        {
            cmdObj.cmd.rspType = HS_MMCSD_RSP_TYPE_NONE;
        }
        else if (transaction->flags & MMCSD_CMDRSP_136BITS)
        {
            cmdObj.cmd.rspType = HS_MMCSD_RSP_TYPE_LEN_136;
        }
        else if (transaction->flags & MMCSD_CMDRSP_BUSY)
        {
            cmdObj.cmd.rspType = HS_MMCSD_RSP_TYPE_LEN_48_BUSY;
        }
        else
        {
            cmdObj.cmd.rspType = HS_MMCSD_RSP_TYPE_LEN_48;
        }

        /* Configure the transfer type */
        cmdObj.enableData = (transaction->flags & MMCSD_CMDRSP_DATA) ? (uint32_t)TRUE : (uint32_t)FALSE;

        if(0U != hwAttrs->enableInterrupt)
        {
			HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFWRRDY);
            HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFRDRDY);
            HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_TRNFCOMP);

        }
		
		if (0 != cmdObj.enableData)
        {
            
			   /* Acquire the lock for this particular MMCSD handle */
            MMCSD_osalPendLock(object->transferMutex, SemaphoreP_WAIT_FOREVER);
            MMCSD_osalPendLock(object->commandMutex, SemaphoreP_WAIT_FOREVER);

            /*  MMCSD_osalHardwareIntrDisable(hwAttrs->intNum); */

            object->dataBufIdx = (uint8_t*)transaction->dataBuf;
			
			
            object->dataBlockCount = transaction->blockCount;
            object->dataBlockSize = transaction->blockSize;
            object->cmdComp = 0;
            object->cmdTimeout = 0;
            object->xferInProgress = 0;
            object->xferComp = 0;
            object->xferTimeout = 0;
			
cmdObj.cmd.xferType = (transaction->flags & MMCSD_CMDRSP_READ) ? \
                HS_MMCSD_XFER_TYPE_RX : HS_MMCSD_XFER_TYPE_TX;
            cmdObj.numBlks = (TRUE == cmdObj.enableData) ? object->dataBlockCount : 0U;
            HSMMCSDIntrClear(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_TRNFCOMP);

            if (HS_MMCSD_XFER_TYPE_RX == cmdObj.cmd.xferType)
            {
                /* Configure the transfer for read operation */
                HSMMCSDIntrClear(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFRDRDY);
                HSMMCSDIntrStatusEnable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFRDRDY);
                HSMMCSDIntrStatusDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFWRRDY);

				object->readBlockCount=object->dataBlockCount;
#ifdef MMCSD_EDMA_ENABLED
                if(0U != hwAttrs->enableDma && transaction->cmd!=MMCSD_CMD(19U))
                {
                    /* Maintaining cache coherency. Write back the cache line and invalidate */
                    MMCSD_osalCache_wbInv(object->dataBufIdx,(transaction->blockSize * transaction->blockCount));
                    /* Get the PaRAM set for default parameters                               */
                    EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                            (uint32_t) hwAttrs->rxDmaEventNumber, &paramSet);

                    /* Fill the PaRAM Set with transfer specific information */
                    paramSet.destAddr  = (uint32_t)MMCSD_soc_l2_global_addr((uint32_t)object->dataBufIdx);

                    paramSet.srcAddr = (uint32_t) ((hwAttrs->baseAddr)
                                     + CSL_MMCHS_DATA);

                    /**
                    * Be Careful !!!
                    * Valid values for SRCBIDX/DSTBIDX are between –32768 and 32767
                    * Valid values for SRCCIDX/DSTCIDX are between –32768 and 32767
                    */
                    paramSet.aCnt       = 4;
                    paramSet.bCnt       = (uint16_t) (transaction->blockSize / 4);
                    paramSet.cCnt       = (uint16_t) object->dataBlockCount;
                    paramSet.srcBIdx    = 0;
                    paramSet.srcCIdx    = 0;

                    paramSet.destBIdx   = 4;
                    paramSet.destCIdx   = transaction->blockSize;

                    /* For AB-synchronized transfers, BCNTRLD is not used. */

                    paramSet.linkAddr   = 0xFFFFu;

                    paramSet.bCntReload = (uint16_t) 0;

                    /* Src is in INCR mode & Dest is in FIFO modes                        */
                    paramSet.opt &= MMCSD_EDMA3CC_OPT_DAM_INCR_MODE;
                    paramSet.opt |= MMCSD_EDMA3CC_OPT_SAM_CONST_MODE;

                    /* FIFO width is 8 bit                                                */
                    paramSet.opt |= (((uint32_t)2U) << 8);

                    /* EDMA3_DRV_SYNC_AB                                                  */
                    paramSet.opt &= MMCSD_EDMA3CC_OPT_SYNC_MASK_VALUE;
                    paramSet.opt |= MMCSD_EDMA3CC_OPT_SYNC_AB;

                    /* EDMA3_DRV_OPT_FIELD_TCINTEN                                        */
                    paramSet.opt |= ((uint32_t) 1U << MMCSD_OPT_TCINTEN_SHIFT);


                    /* ADDED FOR ARM PLATFORM                                             */
                    /* update the transfer completion code                                */
                    paramSet.opt &= (~MMCSD_EDMA3CC_OPT_TCC_MASK);
                    paramSet.opt |= (( hwAttrs->edmaRxTCC) << MMCSD_EDMA3CC_OPT_TCC_SHIFT);

                    result = (uint32_t)EDMA3_DRV_setPaRAM(hwAttrs->edmaHandle, hwAttrs->rxDmaEventNumber, &paramSet);
                    if (result != ((uint32_t) EDMA3_DRV_SOK))
                    {
                        ret = MMCSD_ERR;
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
                /* Configure the transfer for write operation */
                HSMMCSDIntrClear(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFWRRDY);
                HSMMCSDIntrStatusEnable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFWRRDY);
                HSMMCSDIntrStatusDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFRDRDY);

                if(0U != hwAttrs->enableInterrupt)
                {
					HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFWRRDY);
                    HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFRDRDY);
                    HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_TRNFCOMP);
					
                }
				object->writeBlockCount=object->dataBlockCount;
#ifdef MMCSD_EDMA_ENABLED
                if(0U != hwAttrs->enableDma && transaction->cmd!=MMCSD_CMD(19U))
                {
                    /* Maintaining cache coherency */
                    MMCSD_osalCache_wb(object->dataBufIdx,(transaction->blockSize * transaction->blockCount));
                    /* Get the PaRAM set for default parameters                               */
                    EDMA3_DRV_getPaRAM((EDMA3_DRV_Handle) hwAttrs->edmaHandle,
                                            (uint32_t) hwAttrs->txDmaEventNumber, &paramSet);

                    /* Fill the PaRAM Set with transfer specific information */
                    paramSet.srcAddr = (uint32_t)MMCSD_soc_l2_global_addr((uint32_t)object->dataBufIdx);

                    paramSet.destAddr = (uint32_t) ((hwAttrs->baseAddr)
                                     + CSL_MMCHS_DATA);

                    /**
                    * Be Careful !!!
                    * Valid values for SRCBIDX/DSTBIDX are between –32768 and 32767
                    * Valid values for SRCCIDX/DSTCIDX are between –32768 and 32767
                    */
                    paramSet.aCnt       = 4;
                    paramSet.bCnt       = (uint16_t) (transaction->blockSize / 4);
                    paramSet.cCnt       = (uint16_t) object->dataBlockCount;
                    paramSet.srcBIdx    = 4;
                    paramSet.srcCIdx    = transaction->blockSize;

                    paramSet.destBIdx   = 0;
                    paramSet.destCIdx   = 0;

                    /* For AB-synchronized transfers, BCNTRLD is not used. */

                    paramSet.linkAddr   = 0xFFFFu;

                    paramSet.bCntReload = (uint16_t) 0;

                    /* Src is in INCR mode & Dest is in FIFO modes                        */
                    paramSet.opt &= MMCSD_EDMA3CC_OPT_SAM_INCR_MODE;
                    paramSet.opt |= MMCSD_EDMA3CC_OPT_DAM_CONST_MODE;

                    /* FIFO width is 8 bit                                                */
                    paramSet.opt |= (((uint32_t)2U) << 8);

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

            HSMMCSDSetBlkLength(hwAttrs->baseAddr, transaction->blockSize);

            HSMMCSDIntrClear(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_TRNFCOMP);
            HSMMCSDSetDataTimeout(hwAttrs->baseAddr, 27U);

            HSMMCSDIntrStatusEnable(hwAttrs->baseAddr,
                (HS_MMCSD_INTR_MASK_CMDCOMP | HS_MMCSD_INTR_MASK_CMDTIMEOUT |
                 HS_MMCSD_INTR_MASK_DATATIMEOUT | HS_MMCSD_INTR_MASK_TRNFCOMP));

            if(0U != hwAttrs->enableInterrupt)
            {
			HSMMCSDIntrEnable(hwAttrs->baseAddr,
                    (HS_MMCSD_INTR_MASK_CMDCOMP | HS_MMCSD_INTR_MASK_CMDTIMEOUT |
                     HS_MMCSD_INTR_MASK_DATATIMEOUT));

					 }

            cmdObj.cmd.cmdId = transaction->cmd;
            cmdObj.cmdArg = transaction->arg;
#ifdef MMCSD_EDMA_ENABLED			
            if(0U != hwAttrs->enableDma && transaction->cmd!=MMCSD_CMD(19U))
            {
                cmdObj.enableDma = 1U;
            }
            else
#endif			
            {
                cmdObj.enableDma = 0U;
            }
 			HSMMCSDCommandSend(hwAttrs->baseAddr, &cmdObj);
            
            /*  MMCSD_osalHardwareIntrEnable(hwAttrs->intNum); */

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
                    MMCSD_v1_cmdStatusFxn((uintptr_t) handle);
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
#if 0
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
					
                    if (HS_MMCSD_XFER_TYPE_RX == cmdObj.cmd.xferType)	{	 
					  HSMMCSDIntrEnable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFRDRDY);
					  } else {
					  HSMMCSDIntrEnable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_BUFWRRDY);
				     }	
#ifdef SEMAPHORE_EMUWAITS
					 while(dataBufferCopyComplete_emuwait);
#endif
					 MMCSD_osalPendLock(object->dataBufferCopyComplete, SemaphoreP_WAIT_FOREVER);
					 
					 
					 
 					 HSMMCSDIntrEnable(hwAttrs->baseAddr, HS_MMCSD_INTR_MASK_TRNFCOMP);
				 }	
				
                /* Git response for command sent to MMC device */
                HSMMCSDGetResponse(hwAttrs->baseAddr, transaction->response);
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
				 if(0U != hwAttrs->enableDma  && transaction->cmd!=MMCSD_CMD(19U))
                {
                    if (HS_MMCSD_XFER_TYPE_RX == cmdObj.cmd.xferType)
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
                  if(cmdObj.cmd.cmdId!=MMCSD_CMD(19U)) 
				  {
				    while ((0 == object->xferComp) && (0 == object->xferTimeout))
                    {
                        MMCSD_v1_xferStatusFxn((uintptr_t) handle);
                    }
				  }	
				  else 
				  {
                    while ((0 == object->xferComp) && (0 == object->xferTimeout))
                    {
                        MMCSD_v1_xferStatusFxn_CMD19((uintptr_t) handle);
                    }
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

            cmdObj.cmd.cmdId = transaction->cmd;
            cmdObj.cmdArg = transaction->arg;
            cmdObj.enableDma = 0;
            HSMMCSDCommandSend(hwAttrs->baseAddr, &cmdObj);

            HSMMCSDIntrStatusEnable(hwAttrs->baseAddr,
                (HS_MMCSD_INTR_MASK_CMDCOMP | HS_MMCSD_INTR_MASK_CMDTIMEOUT));

            if(0U != hwAttrs->enableInterrupt)
            {
                HSMMCSDIntrEnable(hwAttrs->baseAddr,
                    (HS_MMCSD_INTR_MASK_CMDCOMP | HS_MMCSD_INTR_MASK_CMDTIMEOUT));
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
                while ((0 == object->cmdComp) && (0 == object->cmdTimeout))
                {
                    MMCSD_v1_cmdStatusFxn((uintptr_t) handle);
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
#ifdef LOG_EN
                MMCSD_drv_log(Diags_USER1,
                        "MMCSD:(%p) Command Execution Failed", hwAttrs->baseAddr);
#endif
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
            HSMMCSDGetResponse(hwAttrs->baseAddr, transaction->response);

            /* Release the lock for this particular MMCSD handle */
            MMCSD_osalPostLock(object->commandMutex);
        }
      }
     }
   }  

    /* Return the transaction status */
    return (ret);
}

/*
 *  ======== MMCSD_v1_control ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v1_control(MMCSD_Handle handle, uint32_t cmd, const void *arg)
{
    MMCSD_Error        ret = MMCSD_ERR;

    /* Input parameter validation */
    if(handle != NULL)
    {
    switch (cmd)
    {
        case MMCSD_CMD_SETBUSWIDTH:
        {
            ret = MMCSD_v1_setBusWidth(handle, (uint32_t *)arg);
            break;
        }

        case MMCSD_CMD_SETFREQUENCY:
        {
            ret = MMCSD_v1_setBusFreq(handle, (uint32_t *)arg);
            break;
        }

        case MMCSD_CMD_GETBUSWIDTH:
        {
            ret = MMCSD_v1_getBusWidth(handle, (uint32_t *)arg);
            break;
        }

        case MMCSD_CMD_GETFREQUENCY:
        {
            ret = MMCSD_v1_getBusFreq(handle, (uint32_t *)arg);
            break;
        }

        case MMCSD_CMD_GETMEDIAPARAMS:
        {
            ret = MMCSD_v1_getMediaParams(handle, (MMCSD_mediaParams *)arg);
            break;
        }

        default:
        ret = MMCSD_UNDEFINEDCMD;
        break;
    }
  } 
  
    return ret;
}

/*
 *  ======== MMCSD_v1_setBusWidth ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v1_setBusWidth(MMCSD_Handle handle, const uint32_t *busWidth)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v1_Object            *object = NULL;
    MMCSD_v1_HwAttrs           *hwAttrs = NULL;
    MMCSD_v1_Transaction        transaction;

    /* Input parameter validation */
    if((handle != NULL) && (((MMCSD_Config *) handle)->object !=NULL) && (((MMCSD_Config *) handle)->hwAttrs != NULL) )
    {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v1_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

    if( (object!=NULL) && (hwAttrs!=NULL) )
    {
    if (MMCSD_CARD_SD == object->cardType)
    {
        if ((MMCSD_BUS_WIDTH_4BIT == *busWidth) || (MMCSD_BUS_WIDTH_1BIT == *busWidth))
        {
            ret = MMCSD_OK;
        }

        if(MMCSD_OK == ret)
        {
            /* APP cmd should be preceeded by a CMD55 */
            transaction.cmd = MMCSD_CMD(55U);
            transaction.flags = 0U;
            transaction.arg = object->rca << 16U;
            ret = MMCSD_v1_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(6U);
            transaction.arg = MMCSD_BUS_WIDTH_1BIT;
            transaction.flags = 0U;

            if (((MMCSD_v1_HwAttrs *)(((MMCSD_Config *) handle)->hwAttrs))->supportedBusWidth & MMCSD_BUS_WIDTH_4BIT)
            {
                if (MMCSD_BUS_WIDTH_4BIT == *busWidth)
                {
                    transaction.arg = MMCSD_BUS_WIDTH_4BIT;
                }
            }

            transaction.arg = transaction.arg >> 1U;
            ret = MMCSD_v1_transfer(handle, &transaction);

            if (MMCSD_OK == ret)
            {
                if (MMCSD_BUS_WIDTH_4BIT == *busWidth)
                {
                    object->busWidth = MMCSD_BUS_WIDTH_4BIT;
                    HSMMCSDSetBusWidth(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_4BIT);
                }
                else
                {
                    object->busWidth = MMCSD_BUS_WIDTH_1BIT;
                    HSMMCSDSetBusWidth(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_1BIT);
                }
            }
        }
      }  
     }
   }
    return(ret);
}

/*
 *  ======== MMCSD_v1_setBusFreq ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v1_setBusFreq(MMCSD_Handle handle, const uint32_t *busFreq)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v1_Object            *object = NULL;
	uint32_t cmd16_grp1_fn;

    /* Input parameter validation */
    if(handle != NULL)
    {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
    
    if(object!=NULL)
    {
     if (MMCSD_CARD_SD == object->cardType)
     {
        if ((MMCSD_TRANSPEED_25MBPS == *busFreq) || 
		    (MMCSD_TRANSPEED_50MBPS == *busFreq) || 
			(MMCSD_TRANSPEED_SDR50  == *busFreq) || 
			(MMCSD_TRANSPEED_DDR50  == *busFreq) || 
			(MMCSD_TRANSPEED_SDR104 == *busFreq) )
        {
            ret = MMCSD_OK;
        }

        if(object->tranSpeed == *busFreq) {
             return MMCSD_OK;
        }

		switch(*busFreq) 
		{
		   case MMCSD_TRANSPEED_SDR104:
		       cmd16_grp1_fn=MMCSD_CMD6_GRP1_SDR104;
			   break;
		   case MMCSD_TRANSPEED_SDR50:
			   cmd16_grp1_fn=MMCSD_CMD6_GRP1_SDR50;
               break;
		   case MMCSD_TRANSPEED_DDR50:
		       cmd16_grp1_fn=MMCSD_CMD6_GRP1_DDR50;
               break;
		   case MMCSD_TRANSPEED_HS:
		       cmd16_grp1_fn=MMCSD_CMD6_GRP1_HS;
			   break;
		   case MMCSD_TRANSPEED_DEFAULT:
		   default:
		       cmd16_grp1_fn=MMCSD_CMD6_GRP1_DEFAULT;/*25MHz*/
			   break;
		}
		
		if(ret==MMCSD_OK){
          ret=MMCSD_switch_card_speed(handle,cmd16_grp1_fn);
		}
     }		
    }
   } 
    return(ret);
}

/*
 *  ======== MMCSD_v1_getBusWidth ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v1_getBusWidth(MMCSD_Handle handle, uint32_t *busWidth)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v1_Object            *object = NULL;

    /* Input parameter validation */
    if(handle != NULL)
    {
      /* Get the pointer to the object and hwAttrs */
      object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;

      if (MMCSD_CARD_SD == object->cardType)
      {
        *busWidth = object->busWidth;
        ret = MMCSD_OK;
      }
    }
    return(ret);
}

/*
 *  ======== MMCSD_v1_getBusFreq ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v1_getBusFreq(MMCSD_Handle handle, uint32_t *busFreq)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v1_Object            *object = NULL;

    /* Input parameter validation */
    if(handle != NULL)
    {
      /* Get the pointer to the object and hwAttrs */
      object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;
      if(object != NULL)
      {
        if (MMCSD_CARD_SD == object->cardType)
        {
          *busFreq = object->tranSpeed;
          ret = MMCSD_OK;
        }
      }  
    }  
    return(ret);
}


/*
 *  ======== MMCSD_v1_getMediaParams ========
 */
/*!
 *  @brief      This function returns the media (SD/eMMC/MMC)'s parameters
 *              such as size, blockCount and blockSize  .
 */
static MMCSD_Error MMCSD_v1_getMediaParams(MMCSD_Handle handle, MMCSD_mediaParams *params)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v1_Object            *object = NULL;

    /* Input parameter validation */
    if((handle != NULL) && (params != NULL))
    {
      /* Get the pointer to the object and hwAttrs */
      object = (MMCSD_v1_Object *)((MMCSD_Config *) handle)->object;

      params->blockSize = object->blockSize;
      params->blockCount = object->blockCount;
      params->size = object->size;
    
      ret = MMCSD_OK;
    }  

    return(ret);
}

/*
 *  ======== MMCSD_v1_hwiFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */
void MMCSD_v1_hwiFxn(uintptr_t arg)
{
    uint32_t                   errStatus;
    uint32_t                   dataLen = 0U;
    volatile uint32_t          status = 0U;
    volatile uint32_t          intrMask = 0U;
    volatile uint32_t          temp = 0U;
    volatile uint32_t          cnt = 0U;
    MMCSD_v1_Object           *object = NULL;
    MMCSD_v1_HwAttrs const    *hwAttrs = NULL;
    uint32_t blocks_remaining,offset;
    /* Input parameter validation */
   if((void *) arg != NULL)
   { 
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object*)(((MMCSD_Config *)arg)->object);
    hwAttrs = (MMCSD_v1_HwAttrs*)(((MMCSD_Config *)arg)->hwAttrs);
    
	if( (object!=NULL) && (hwAttrs!=NULL) )
	{
     status = HSMMCSDIntrStatus(hwAttrs->baseAddr);
     intrMask = HSMMCSDIntrGet(hwAttrs->baseAddr);
    /* Command execution is complete */
    if (status & HS_MMCSD_INTR_MASK_CMDCOMP)
    {
        HSMMCSDIntrClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_MASK_CMDCOMP);
        object->cmdComp = 1;

		/* Indicate command complete */
        if (intrMask & HS_MMCSD_INTR_MASK_CMDCOMP)
        {
			MMCSD_osalPostLock(object->commandComplete);
        }

    }    /* Error occurred in execution of command */

    if (status & HS_MMCSD_INTR_MASK_ERR)
    {
        errStatus = status & 0xFFFF0000U;

        if (errStatus & HS_MMCSD_INTR_MASK_CMDTIMEOUT)
        {
            HSMMCSDIntrClear(hwAttrs->baseAddr,
                                       HS_MMCSD_INTR_MASK_CMDTIMEOUT);
            object->cmdTimeout = 1;

			/* Indicate command complete */
            if (intrMask & HS_MMCSD_INTR_MASK_CMDTIMEOUT)
            {
                MMCSD_osalPostLock(object->commandComplete);
            }
        }
		
    } 

    /* Read data received from card */
    if ((status & HS_MMCSD_INTR_MASK_BUFRDRDY) && (intrMask & HS_MMCSD_INTR_MASK_BUFRDRDY))
    {

    	HSMMCSDIntrClear(hwAttrs->baseAddr,
                               HS_MMCSD_INTR_MASK_BUFRDRDY);
        
        if (object->dataBufIdx != NULL)
        {
		object->xferInProgress=1;
            dataLen=object->dataBlockSize;
			blocks_remaining=object->readBlockCount;
            offset=(object->dataBlockCount-blocks_remaining)*object->dataBlockSize;
            for (cnt = 0U; cnt < dataLen; cnt += 4U)
            {
			    HSMMCSDGetData(hwAttrs->baseAddr, (uint8_t *)&temp, 4U);
                object->dataBufIdx[offset+cnt] = *((uint8_t*)&temp);
                object->dataBufIdx[offset+cnt + 1U] = *((uint8_t*)&temp + 1U);
                object->dataBufIdx[offset+cnt + 2U] = *((uint8_t*)&temp + 2U);
                object->dataBufIdx[offset+cnt + 3U] = *((uint8_t*)&temp + 3U);
            }
			object->readBlockCount--;
           if (object->readBlockCount==0)
           {
 		      MMCSD_osalPostLock(object->dataBufferCopyComplete);
 	    }
         		

        }
    } 

    /* Write data received from card */
    if (( status & HS_MMCSD_INTR_MASK_BUFWRRDY) && (intrMask & HS_MMCSD_INTR_MASK_BUFWRRDY))
    {
        HSMMCSDIntrClear(hwAttrs->baseAddr,
                               HS_MMCSD_INTR_MASK_BUFWRRDY);

        
		if (object->dataBufIdx != NULL)
        {
            object->xferInProgress=1;
            dataLen=object->dataBlockSize;
            blocks_remaining=object->writeBlockCount;
			offset=(object->dataBlockCount-blocks_remaining)*object->dataBlockSize;			
			
            for (cnt = 0U; cnt < dataLen; cnt+=4U)
            {
  			    *((uint8_t*)&temp) = object->dataBufIdx[offset+cnt];
                *((uint8_t*)&temp + 1U) = object->dataBufIdx[offset + cnt + 1U];
                *((uint8_t*)&temp + 2U) = object->dataBufIdx[offset + cnt + 2U];
                *((uint8_t*)&temp + 3U) = object->dataBufIdx[offset + cnt + 3U];
                HW_WR_REG32((hwAttrs->baseAddr + CSL_MMCHS_DATA), temp);
				
            }
			object->writeBlockCount--;
           if (object->writeBlockCount==0)
           {
		       MMCSD_osalPostLock(object->dataBufferCopyComplete);
           }

        }
    } 

    /* Error occurred in data transfer */
    if (status & HS_MMCSD_INTR_MASK_DATATIMEOUT)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_MASK_DATATIMEOUT);
            object->xferTimeout = 1;
            object->xferInProgress = 0;

            /* Indicate transfer complete */
            if (intrMask & HS_MMCSD_INTR_MASK_DATATIMEOUT)
            {
                MMCSD_osalPostLock(object->transferComplete);
            }

        }
    } 

    /* Data transfer is complete */
    if ((status & HS_MMCSD_INTR_MASK_TRNFCOMP) && (intrMask & HS_MMCSD_INTR_MASK_TRNFCOMP))
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_MASK_TRNFCOMP);
            object->xferComp = 1;
            object->xferInProgress = 0;

            /* Indicate transfer complete */
            if (intrMask & HS_MMCSD_INTR_MASK_TRNFCOMP)
            {
				MMCSD_osalPostLock(object->transferComplete);
            }
        }
    }
   } 
  }
    return;
}

/*
 *  ======== MMCSD_v1_cmdStatusFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */
static void MMCSD_v1_cmdStatusFxn(uintptr_t arg)
{
    volatile uint32_t        errStatus;
    volatile uint32_t        status = 0U;
    MMCSD_v1_Object         *object = NULL;
    MMCSD_v1_HwAttrs const  *hwAttrs = NULL;

    /* Input parameter validation */
   if((void *) arg != NULL)
   {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object*)(((MMCSD_Config *)arg)->object);
    hwAttrs = (MMCSD_v1_HwAttrs*)(((MMCSD_Config *)arg)->hwAttrs);

    status = HSMMCSDIntrStatus(hwAttrs->baseAddr);

    /* Command execution is complete */
    if (status & HS_MMCSD_INTR_MASK_CMDCOMP)
    {
        HSMMCSDIntrClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_MASK_CMDCOMP);
        object->cmdComp = 1;
    }

    /* Error occurred in execution of command */
    if (status & HS_MMCSD_INTR_MASK_ERR)
    {
        errStatus = status & 0xFFFF0000U;

        if (errStatus & HS_MMCSD_INTR_MASK_CMDTIMEOUT)
        {
            HSMMCSDIntrClear(hwAttrs->baseAddr,
                                       HS_MMCSD_INTR_MASK_CMDTIMEOUT);
            object->cmdTimeout = 1;
        }
    }
  }
    return;
}
/*
 *  ======== MMCSD_v1_xferStatusFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */
static void MMCSD_v1_xferStatusFxn(uintptr_t arg)
{
    volatile uint32_t        dataLen = 0U;
    volatile uint32_t        status = 0U;
    volatile uint32_t        temp = 0U;
    volatile uint32_t        cnt = 0U;
    MMCSD_v1_Object         *object = NULL;
    MMCSD_v1_HwAttrs const  *hwAttrs = NULL;
    uint32_t blocks_remaining,offset;

    /* Input parameter validation */
    if((void *) arg != NULL)
    {
    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object*)(((MMCSD_Config *)arg)->object);
    hwAttrs = (MMCSD_v1_HwAttrs*)(((MMCSD_Config *)arg)->hwAttrs);

    if( (object!=NULL) && (hwAttrs!=NULL) )
    {
    status = HSMMCSDIntrStatus(hwAttrs->baseAddr);

    /* Read data received from card */
    if (status & HS_MMCSD_INTR_MASK_BUFRDRDY)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_MASK_BUFRDRDY);

            if (object->dataBufIdx != NULL)
            {
                dataLen=object->dataBlockSize;
				blocks_remaining=object->readBlockCount;
				offset=(object->dataBlockCount-blocks_remaining)*object->dataBlockSize;
			
                for (cnt = 0U; cnt < dataLen; cnt += 4U)
                {
                    HSMMCSDGetData(hwAttrs->baseAddr, (uint8_t *)&temp, 4U);
                    object->dataBufIdx[offset+cnt] = *((uint8_t*)&temp);
                    object->dataBufIdx[offset+cnt + 1U] = *((uint8_t*)&temp + 1U);
                    object->dataBufIdx[offset+cnt + 2U] = *((uint8_t*)&temp + 2U);
                    object->dataBufIdx[offset+cnt + 3U] = *((uint8_t*)&temp + 3U);
					}
				object->readBlockCount--;
            }
        }
    }

    /* Write data received from card */
    if (status & HS_MMCSD_INTR_MASK_BUFWRRDY)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_MASK_BUFWRRDY);

            if (object->dataBufIdx != NULL)
            {
				blocks_remaining=object->writeBlockCount;
				offset=(object->dataBlockCount-blocks_remaining)*object->dataBlockSize;
                dataLen = object->dataBlockSize; 
                for (cnt = 0U; cnt < dataLen; cnt+=4U)
                {
                    *((uint8_t*)&temp) = object->dataBufIdx[offset+cnt];
                    *((uint8_t*)&temp + 1U) = object->dataBufIdx[offset+cnt + 1U];
                    *((uint8_t*)&temp + 2U) = object->dataBufIdx[offset+cnt + 2U];
                    *((uint8_t*)&temp + 3U) = object->dataBufIdx[offset+cnt + 3U];
                    HW_WR_REG32((hwAttrs->baseAddr + CSL_MMCHS_DATA), temp);
                }
				object->writeBlockCount--;
            }
        }
    }

    /* Error occurred in data transfer */
    if (status & HS_MMCSD_INTR_MASK_DATATIMEOUT)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_MASK_DATATIMEOUT);
            object->xferTimeout = 1;
            object->xferInProgress = 0;
        }
    }
    /* Data transfer is complete */
    if (status & HS_MMCSD_INTR_MASK_TRNFCOMP)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_MASK_TRNFCOMP);
            object->xferComp = 1;
            object->xferInProgress = 0;
        }
      }  
    }
  }
    return;
}

/*
 *  ======== MMCSD_v1_xferStatusFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */

static void MMCSD_v1_xferStatusFxn_CMD19(uintptr_t arg)
{
    volatile uint32_t        dataLen = 0U;
    volatile uint32_t        status = 0U;
    volatile uint32_t        temp = 0U;
    volatile uint32_t        cnt = 0U;
    MMCSD_v1_Object         *object = NULL;
    MMCSD_v1_HwAttrs const  *hwAttrs = NULL;

    /* Input parameter validation */
    if((void *) arg != NULL)
    {

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v1_Object*)(((MMCSD_Config *)arg)->object);
    hwAttrs = (MMCSD_v1_HwAttrs*)(((MMCSD_Config *)arg)->hwAttrs);
    
    if( (object!=NULL) && (hwAttrs!=NULL) )
    {
    status = HSMMCSDIntrStatus(hwAttrs->baseAddr);

    /* Read data received from card */
    if (status & HS_MMCSD_INTR_MASK_BUFRDRDY)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_MASK_BUFRDRDY);

            if (object->dataBufIdx != NULL)
            {
                dataLen = object->dataBlockCount * object->dataBlockSize;

                for (cnt = 0U; cnt < dataLen; cnt += 4U)
                {
                    HSMMCSDGetData(hwAttrs->baseAddr, (uint8_t *)&temp, 4U);
                    object->dataBufIdx[cnt] = *((uint8_t*)&temp);
                    object->dataBufIdx[cnt + 1U] = *((uint8_t*)&temp + 1U);
                    object->dataBufIdx[cnt + 2U] = *((uint8_t*)&temp + 2U);
                    object->dataBufIdx[cnt + 3U] = *((uint8_t*)&temp + 3U);
                }
            }
			HSMMCSDIntrClear(hwAttrs->baseAddr,
            HS_MMCSD_INTR_MASK_TRNFCOMP);
            object->xferComp = 1;
            object->xferInProgress = 0;
        }
    }
    /* Error occurred in data transfer */
    if (status & HS_MMCSD_INTR_MASK_DATATIMEOUT)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_MASK_DATATIMEOUT);
            object->xferTimeout = 1;
            object->xferInProgress = 0;
        }
     }
   }
    /* Data transfer is complete */
  }
  return;
}

#ifdef MMCSD_EDMA_ENABLED
static void MMCSDDMA_rxIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData)
{
    MMCSD_Handle                         handle;
    MMCSD_v1_HwAttrs    const           *hwAttrs;
    MMCSD_v1_Object                  *object ;


    if(appData != NULL) {
        handle = (MMCSD_Handle)appData;
        hwAttrs = (MMCSD_v1_HwAttrs*)(((MMCSD_Config *) handle)->hwAttrs);
        object = (MMCSD_v1_Object*)(((MMCSD_Config *) handle)->object);
       
      if( (hwAttrs!=NULL) && (object!=NULL) )
      { 
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

}

static void MMCSDDMA_txIsrHandler(uint32_t tcc, EDMA3_RM_TccStatus status, void* appData)
{
    MMCSD_Handle                  handle;
    MMCSD_v1_HwAttrs const    *hwAttrs;
    MMCSD_v1_Object           *object ;


    if(appData != NULL) {

        handle = (MMCSD_Handle)appData;
        hwAttrs = (MMCSD_v1_HwAttrs*)(((MMCSD_Config *) handle)->hwAttrs);
        object = (MMCSD_v1_Object*)(((MMCSD_Config *) handle)->object);
        
	  if( (object!=NULL) && (hwAttrs!=NULL) )
      {
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

}

static void MMCSDDMA_doNothing(uint32_t tcc, EDMA3_RM_TccStatus edmaStatus, void* appData)
{

}

/*
 *  ======== writeSemCallback ========
 *  Simple callback to post a lock for the blocking mode.
 */
static void MMCSDDMA_writeSemCallback(MMCSD_Handle handle, void *buffer, size_t count)
{
   if (handle!=NULL)
   {
    MMCSD_v1_Object *object = (MMCSD_v1_Object*)(((MMCSD_Config *) handle)->object);
    if(object!=NULL)
    {
      MMCSD_osalPostLock(object->writeSem);
    }
  }    
}

/*
 *  ======== readSemCallback ========
 *  Simple callback to post a lock for the blocking mode.
 */
static void MMCSDDMA_readSemCallback(MMCSD_Handle handle, void *buffer, size_t count)
{
   if (handle!=NULL)
   {
     MMCSD_v1_Object *object = (MMCSD_v1_Object*)(((MMCSD_Config *) handle)->object);
     if(object!=NULL)
     {
       MMCSD_osalPostLock(object->readSem);
     }  
   }  
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
int32_t MMCSD_socGetInitCfg(uint32_t index, MMCSD_v1_HwAttrs *cfg)
{
    int32_t ret = 0;
   
    if (index < MMCSD_CNT)
    {
      if(cfg!=NULL)
      { 
        *cfg = MMCSDInitCfg[index];
      }  
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
int32_t MMCSD_socSetInitCfg(uint32_t index, const MMCSD_v1_HwAttrs *cfg)
{
    int32_t ret = 0;

    if (index < MMCSD_CNT)
    {
      if(cfg!=NULL)
      { 
        MMCSDInitCfg[index] = *cfg;
      }  
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
