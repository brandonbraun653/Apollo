/**
 *  \file   MMCSD_v2.c
 *
 *  \brief  IP version 1 specific MMCSD Driver APIs implementation.
 *
 *   This file contains the driver APIs for MMCSD controller.
 */

/*
 * Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/csl/csl_mmcsd.h>
#include <ti/drv/mmcsd/src/MMCSD_drv_log.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_v2.h>
#include <ti/drv/mmcsd/src/v2/MMCSD_v2_lld.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
#include <ti/drv/mmcsd/src/MMCSD_osal.h>

#define MMCSD_log                UART_printf

#define MMCSD_DEBUG_TRAP   {while(mmcsd_emuwait_trap);}

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
#define MMCSD_CARD_VERSION(sdcard)      (((sdcard)->scr[0U] & 0x0F000000U) >> 24)

/** \brief Reads card bus width. */
#define MMCSD_CARD_BUSWIDTH(sdcard) (((sdcard)->scr[0U] & 0x000F0000U) >> 16)

/** \brief Reads if the SD Card supports CMD23. */
#define MMCSD_CARD_CMD23_SUPPORT(sdcard) (((sdcard)->scr[0U] & 0x00000002U) >> 1)

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


#define MMCSD_EMMC_ECSD_DEVICE_TYPE_INDEX  (196)
#define MMCSD_EMMC_ECSD_DEVICE_TYPE_DS       (0x0U)
#define MMCSD_EMMC_ECSD_DEVICE_TYPE_HS_26MHZ (0x1U)
#define MMCSD_EMMC_ECSD_DEVICE_TYPE_HS_52MHZ (0x2U)
#define MMCSD_EMMC_ECSD_DEVICE_TYPE_HS_DDR_52MHZ_1P8V (0x4U)
#define MMCSD_EMMC_ECSD_DEVICE_TYPE_HS_DDR_52MHZ_1P2V (0x8U)

#define MMCSD_EMMC_ECSD_DEVICE_TYPE_HS200_200MHZ_1P8V (0x10U)
#define MMCSD_EMMC_ECSD_DEVICE_TYPE_HS200_200MHZ_1P2V (0x20U)
#define MMCSD_EMMC_ECSD_DEVICE_TYPE_HS400_200MHZ_1P8V (0x40U)
#define MMCSD_EMMC_ECSD_DEVICE_TYPE_HS400_200MHZ_1P2V (0x80U)

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

#define MMCSD_ECSD_HS_TIMING_INDEX    (185U)
#define MMCSD_ECSD_HS_TIMING_BACKWARD_COMPATIBLE       (0U)
#define MMCSD_ECSD_HS_TIMING_HIGH_SPEED                (1U)
#define MMCSD_ECSD_HS_TIMING_HS200                     (2U)
#define MMCSD_ECSD_HS_TIMING_HS400                     (3U)

#define MMCSD_ECSD_STROBE_SUPPORT_INDEX         (184U)
#define MMCSD_ECSD_STROBE_SUPPORT_ENHANCED_DIS    (0U)
#define MMCSD_ECSD_STROBE_SUPPORT_ENHANCED_EN    (1U)



volatile uint32_t mmcsd_emuwait_trap=1;


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
/* Tuning pattern for HS200 mode */
static const uint8_t tuning_blk_pattern_8bit[] = {
	0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00,
	0xff, 0xff, 0xcc, 0xcc, 0xcc, 0x33, 0xcc, 0xcc,
	0xcc, 0x33, 0x33, 0xcc, 0xcc, 0xcc, 0xff, 0xff,
	0xff, 0xee, 0xff, 0xff, 0xff, 0xee, 0xee, 0xff,
	0xff, 0xff, 0xdd, 0xff, 0xff, 0xff, 0xdd, 0xdd,
	0xff, 0xff, 0xff, 0xbb, 0xff, 0xff, 0xff, 0xbb,
	0xbb, 0xff, 0xff, 0xff, 0x77, 0xff, 0xff, 0xff,
	0x77, 0x77, 0xff, 0x77, 0xbb, 0xdd, 0xee, 0xff,
	0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0x00,
	0x00, 0xff, 0xff, 0xcc, 0xcc, 0xcc, 0x33, 0xcc,
	0xcc, 0xcc, 0x33, 0x33, 0xcc, 0xcc, 0xcc, 0xff,
	0xff, 0xff, 0xee, 0xff, 0xff, 0xff, 0xee, 0xee,
	0xff, 0xff, 0xff, 0xdd, 0xff, 0xff, 0xff, 0xdd,
	0xdd, 0xff, 0xff, 0xff, 0xbb, 0xff, 0xff, 0xff,
	0xbb, 0xbb, 0xff, 0xff, 0xff, 0x77, 0xff, 0xff,
	0xff, 0x77, 0x77, 0xff, 0x77, 0xbb, 0xdd, 0xee,
};

#define BITMASK(n)      ((1 << (n)) - 1)        //!< Creates a bit mask with bits n:0 set


//! \brief insert a field into a 32 bit value using the CSL mask and shift fields
//! \param[in] val The initial value which will have the field inserted
//! \param[in] field The value to insert
//! \param[in] mask  The mask over the input value val where field will be inserted
//! \param[in] shift The least significant bit in the mask field
//! \return          The input parameter val with the value field inserted starting a bit shift
static inline uint32_t Bitfield_csl_set (uint32_t val, uint32_t field, uint32_t mask, int32_t shift)
{
    return ( (val & ~mask) | (field << shift) );
}

//! \brief Return the size of an integer field (number of values that a bitfield can have)
//! \param[in] msb The most significant bit of the field
//! \param[in] lsb The least significant bit of the field
//! \return        The number of values the bit field can have

/* MMC functions */
static MMCSD_Error MMCSD_v2_close(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v2_init(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v2_open(MMCSD_Handle handle, MMCSD_Params params);
static MMCSD_Error MMCSD_v2_write(MMCSD_Handle handle,
                                  uint8_t *buf,
                                  uint32_t block,
                                  uint32_t numBlks);
static MMCSD_Error MMCSD_v2_read(MMCSD_Handle handle,
                                 uint8_t *buf,
                                 uint32_t block,
                                 uint32_t numBlks);
static MMCSD_Error MMCSD_v2_transfer(MMCSD_Handle handle,
                                     MMCSD_v2_Transaction *transaction);
static MMCSD_Error MMCSD_v2_control(MMCSD_Handle handle, uint32_t cmd, const void *arg);
static MMCSD_Error MMCSD_v2_enableBootPartition(MMCSD_Handle handle, const uint8_t *partition);
static MMCSD_Error MMCSD_v2_initSd(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v2_initEmmc(MMCSD_Handle handle);
static MMCSD_Error MMCSD_v2_setBusWidth(MMCSD_Handle handle, const uint32_t *busWidth);
static MMCSD_Error MMCSD_v2_setBusFreq(MMCSD_Handle handle, const uint32_t *busFreq);
static MMCSD_Error MMCSD_v2_getBusWidth(MMCSD_Handle handle, uint32_t *busWidth);
static MMCSD_Error MMCSD_v2_getBusFreq(MMCSD_Handle handle, uint32_t *busFreq);
static MMCSD_Error MMCSD_v2_getMediaParams(MMCSD_Handle handle, MMCSD_mediaParams *params);
void MMCSD_v2_hwiFxn(uintptr_t arg);
static void MMCSD_v2_cmdStatusFxn(uintptr_t arg);
static void MMCSD_v2_xferStatusFxn(uintptr_t arg);

static MMCSD_Error mmcsd_tuning_procedure(MMCSD_Handle handle);
static void MMCSD_v2_xferStatusFxn_CMD19(uintptr_t arg);
static MMCSD_Error MMCSD_switch_card_speed(MMCSD_Handle handle,uint32_t cmd16_grp1_fn);
/* Delay function */
static void delay(uint32_t delayValue);

/* MMC function table for MMC implementation */
const MMCSD_FxnTable MMCSD_v2_FxnTable = {
    &MMCSD_v2_close,
    &MMCSD_v2_control,
    &MMCSD_v2_init,
    &MMCSD_v2_open,
    &MMCSD_v2_write,
    &MMCSD_v2_read
};
typedef struct {
  uint32_t params;
  uint32_t addrl;
  uint32_t addrh;
} adma2_desc_t;

adma2_desc_t adma2_desc;
#if defined(__ARM_ARCH_7A__) || defined(__aarch64__) || defined(__TI_ARM_V7R4__)
__attribute__((aligned(SOC_CACHELINE_SIZE))) // GCC way of aligning
#endif

void mmc_setupDescriptor(
    adma2_desc_t *desc,  ///< pointer to descriptor head, NOT pointer to the address value within the decriptor.
    uint32_t params,     ///< parameters for descriptor.
    uint64_t address     ///< physical address to pack into the descriptor.
    )
{
  desc->params = params;
  desc->addrl  = address & 0xffffffffu;
  desc->addrh  = (address >> 32) & 0xffffu;
}



/* Wait for DAT0 to go low */
static int32_t MMCSD_v2_waitDat0(MMCSD_v2_HwAttrs const *hwAttrs);
static int32_t MMCSD_v2_waitDat0(MMCSD_v2_HwAttrs const *hwAttrs)
{
  /* Check for DAT0 to go low */
  volatile uint32_t present_state_reg;
  do {
     present_state_reg= HW_RD_REG32(hwAttrs->baseAddr + MMC_PSTATE);
  } while( (present_state_reg & (1 << 20))!=(1<<20));

  return STW_SOK;
}

/* Waits for cmd inhibit to go low */
static int32_t MMCSD_v2_waitCmdInhibit(MMCSD_v2_HwAttrs const *hwAttrs);
static int32_t MMCSD_v2_waitCmdInhibit(MMCSD_v2_HwAttrs const *hwAttrs)
{
  uint32_t ready=1;
  do {
     ready=*((volatile uint32_t *)(hwAttrs->baseAddr + MMC_PSTATE)) & 0x1;
   } while(ready!=0);
   return STW_SOK;
}
/* Waits for data inhibit to go low */
static int32_t MMCSD_v2_waitDatInhibit(MMCSD_v2_HwAttrs const *hwAttrs);
static int32_t MMCSD_v2_waitDatInhibit(MMCSD_v2_HwAttrs const *hwAttrs)
{
  uint32_t ready=1;
  /* Check for  DAT inhibit */
  do {
    ready=*((volatile uint32_t *)(hwAttrs->baseAddr + MMC_PSTATE)) & 0x2;
  } while(ready!=0);
  return STW_SOK;
}
/* Waits for data inhibit to go low */
uint32_t MMCSD_v2_getCmdInhibit(MMCSD_v2_HwAttrs *hwAttrs)
{
  uint32_t cmd_inhibit;
  /* Check for  DAT inhibit */
  cmd_inhibit=*((volatile uint32_t *)(hwAttrs->baseAddr + MMC_PSTATE)) & 0x1;
  return cmd_inhibit;
}
/* Waits for data inhibit to go low */
uint32_t MMCSD_v2_getDatInhibit(MMCSD_v2_HwAttrs *hwAttrs)
{
  uint32_t dat_inhibit;
  /* Check for  DAT inhibit */
  dat_inhibit=*((volatile uint32_t *)(hwAttrs->baseAddr + MMC_PSTATE)) & 0x2;
  return dat_inhibit;
}

/* Function to check if the media is ready to accept read/write transfers */
static MMCSD_Error mmcsd_check_transfer_ready(MMCSD_Handle handle)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    uint32_t                    cmd13_try_count = 0U;
    uint32_t                    current_state = 0U;
    MMCSD_v2_Object            *object = NULL;
    MMCSD_v2_Transaction        transaction;

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;
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
        ret = MMCSD_v2_transfer(handle, &transaction);
        cmd13_try_count++;
        /* 'Current state' can be found from bits[9-12] of Card Status Register
         * in the response R1 */
        current_state=(transaction.response[0] >> (9U) & (0xFU));

        if(current_state==MMCSD_CARD_STATE_TRANSFER) {
		   ret = MMCSD_OK;
		   break;
		}
     } while(cmd13_try_count < MMCSD_CARD_TRANS_STATE_THRESHOLD);

     return(ret);
}
/* Function to send the block count prior to read/write transfers. This is 
used for better throughput */
static MMCSD_Error mmcsd_send_cmd23(MMCSD_Handle handle, uint32_t numBlks)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v2_Transaction        transaction;

     /*
      * Send CMD13 to check if the card is still in the programming state.
      * The card needs to go to transfer state before it can send/receive data
      */
		memset(&transaction,0,sizeof(transaction));
        transaction.cmd = MMCSD_CMD(23U);
        transaction.flags = MMCSD_CMDRSP_48BITS;
        transaction.arg = numBlks;
        ret = MMCSD_v2_transfer(handle, &transaction);

        return(ret);
}


/*
 *  ======== MMCSD_v2_write ========
 */
static MMCSD_Error MMCSD_v2_write(MMCSD_Handle handle,
                           uint8_t *buf,
                           uint32_t block,
                           uint32_t numBlks)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    uint32_t                    key;
    uint32_t                    address = 0U;
    MMCSD_v2_Object            *object = NULL;
    MMCSD_v2_Transaction        transaction;

    /* Input parameter validation */
    if ((handle != NULL) && (buf != NULL))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;

        object->writeBufIdx = buf;
        object->writeBlockCount = numBlks;

        /* Determine if the device index was already opened */
        key = MMCSD_osalHardwareIntDisable();
        if(0 != ((MMCSD_v2_Object *)(((MMCSD_Config *) handle)->object))->isOpen)
        {
            ret = MMCSD_OK;
        }
        MMCSD_osalHardwareIntRestore(key);
    }

     /*
      * Send CMD13 to check if the card is still in the programming state.
      * The card needs to go to transfer state before it can send/receive data
      */
    if(MMCSD_OK == ret)
    {
       ret = mmcsd_check_transfer_ready(handle);
    }
	
	if((MMCSD_OK == ret) && object->cmd23Supported)
	{
      ret = mmcsd_send_cmd23(handle,numBlks);
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
            // transaction.flags |= MMCSD_CMDRSP_ABORT;
        }
        else
        {
            transaction.cmd = MMCSD_CMD(24U);
        }

        ret = MMCSD_v2_transfer(handle, &transaction);
    } else {
		MMCSD_DEBUG_TRAP
	}	

    if(MMCSD_OK == ret && (!object->cmd23Supported))
    {
		/* Send a STOP */
        if (transaction.blockCount > 1U)
        {
			memset(&transaction,0,sizeof(transaction));
			transaction.cmd  = MMCSD_CMD(12U);
            transaction.flags = MMCSD_CMDRSP_BUSY;
            transaction.arg = 0U;

            ret = MMCSD_v2_transfer(handle, &transaction);
        }
    }

    return (ret);
}

/*
 *  ======== MMCSD_v2_read ========
 */
static MMCSD_Error MMCSD_v2_read(MMCSD_Handle handle,
                          uint8_t *buf,
                          uint32_t block,
                          uint32_t numBlks)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    uint32_t                    key;
    uint32_t                    address = 0U;
    MMCSD_v2_Object            *object = NULL;
    MMCSD_v2_Transaction        transaction;

    /* Input parameter validation */
    if ((handle != NULL) && (buf != NULL))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;

        object->readBufIdx = buf;
        object->readBlockCount = numBlks;

        /* Determine if the device index was already opened */
        key = MMCSD_osalHardwareIntDisable();
        if(0 != ((MMCSD_v2_Object *)(((MMCSD_Config *) handle)->object))->isOpen)
        {
            ret = MMCSD_OK;
        }
        MMCSD_osalHardwareIntRestore(key);
    }

     /*
      * Send CMD13 to check if the card is still in the programming state.
      * The card needs to go to transfer state before it can send/receive data
      */
    if(MMCSD_OK == ret)
    {
       ret = mmcsd_check_transfer_ready(handle);
    }
	
	if((MMCSD_OK == ret) && object->cmd23Supported)
	{
      ret = mmcsd_send_cmd23(handle,numBlks);
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
        }
        else
        {
            transaction.cmd = MMCSD_CMD(17U);
        }

        ret = MMCSD_v2_transfer(handle, &transaction);
    } else {
		MMCSD_DEBUG_TRAP
	}	

	
    if((MMCSD_OK == ret)  && (!object->cmd23Supported))
    {
        /* Send a STOP */
        if (transaction.blockCount > 1U)
        {
		    memset(&transaction,0,sizeof(transaction));
		    transaction.cmd  = MMCSD_CMD(12U);
            transaction.flags = MMCSD_CMDRSP_BUSY;
            transaction.arg = 0U;
            ret = MMCSD_v2_transfer(handle, &transaction);
        }
    }
    return (ret);
}

/*
 *  ======== MMCSD_v2_close ========
 */
static MMCSD_Error MMCSD_v2_close(MMCSD_Handle handle)
{
    MMCSD_v2_Object        *object = NULL;
    MMCSD_v2_HwAttrs const *hwAttrs = NULL;
    MMCSD_Error             ret = MMCSD_OK;

    /* Input parameter validation */
    if (handle == NULL)
    {
        ret = MMCSD_ERR;
    }
    else
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;
        hwAttrs = (MMCSD_v2_HwAttrs const *)((MMCSD_Config *) handle)->hwAttrs;

        if(0U != hwAttrs->enableInterrupt)
        {
           /* Release the interrupt path */
           if (hwAttrs->configSocIntrPath!=NULL) {
              ret = hwAttrs->configSocIntrPath((const void *)hwAttrs,FALSE);
            }

           if(ret==MMCSD_OK) {
           /* Unregister the interrupt */
           MMCSD_osalHardwareIntDestruct(object->hwi,hwAttrs->eventId);
           }
        }

        if(object->switched_to_v18)
        {

          if(object->switched_to_v18 && hwAttrs->switchVoltageFxn!=NULL) {
            MMCSD_drv_log(Diags_USER1,"Switch to 1.8V indicated. Switching back to 3.3V\n");
              ret=hwAttrs->switchVoltageFxn(hwAttrs->instNum,MMCSD_BUS_VOLTAGE_3_3V);
          }

          HSMMCSDSwitchSignalVoltage (hwAttrs->baseAddr, MMC_AC12_V1V8_SIGEN_3V3);
          /* Wait for 5 ms */
          Osal_delay(5);

          /* wait if the signal voltage bit is set to 1 */
          if(HSMMCSDGetSignalVoltage (hwAttrs->baseAddr)==!MMC_AC12_V1V8_SIGEN_3V3) {
            MMCSD_DEBUG_TRAP
          }
        }
        /* Destruct the instance lock */
        MMCSD_osalDeleteBlockingLock(object->commandMutex);
        MMCSD_osalDeleteBlockingLock(object->transferMutex);
        MMCSD_osalDeleteBlockingLock(object->commandComplete);
        MMCSD_osalDeleteBlockingLock(object->dataBufferCopyComplete);
        MMCSD_osalDeleteBlockingLock(object->transferComplete);

        memset(object, 0, sizeof(MMCSD_v2_Object));

    #ifdef LOG_EN
        MMCSD_drv_log(Diags_USER1, "MMCSD: Object closed 0x%x", ((MMCSD_Config *) handle)->hwAttrs->baseAddr);
    #endif
    }
    return (ret);
}

/*
 *  ======== MMCSD_v2_init ========
 */
static MMCSD_Error MMCSD_v2_init(MMCSD_Handle handle)
{
    MMCSD_Error          ret = MMCSD_ERR;

    /* Input parameter validation */
    if (handle != NULL)
    {
        if (((MMCSD_Config *) handle)->object != NULL)
        {
            /* Initialize all variables to 0 */
            memset(((MMCSD_Config *) handle)->object,0,sizeof(MMCSD_v2_Object));
            ret = MMCSD_OK;
        }
    }
	
    return (ret);
}

/*
 *  ======== MMCSD_enableBootPartitionAccess ========
 */
static MMCSD_Error MMCSD_v2_enableBootPartition(MMCSD_Handle handle, const uint8_t *partition)
{
    MMCSD_v2_Transaction transaction;
    MMCSD_Error          ret = MMCSD_OK;
    uint32_t             argument = 0;
    uint8_t              bootAck = 1;
    uint8_t              bootPartition = 0;
    uint8_t              bootBusWidth = 0;

    if((*partition == 1) || (*partition == 2))
    {
        bootPartition = ((bootAck << 6) | (*partition << 3) | (*partition));
        /* Setting x8 bus width */
        bootBusWidth = 0x02;
        argument = (uint32_t)((bootPartition << 8) | (0xB3 << 16) | (0x03 << 24));

        if(MMCSD_OK == ret)
        {
            /* Used CMD6(Switch Command) for configuring the extended CSD register */
            transaction.cmd = MMCSD_CMD(6U);
            transaction.arg = argument;
            transaction.flags = 0U;
            ret = MMCSD_v2_transfer(handle, &transaction);
        }
        Osal_delay(5);

        if(MMCSD_OK == ret)
        {
            argument = (uint32_t)((bootBusWidth << 8) | (0xB1 << 16) | (0x03 << 24));
            /* Used CMD6(Switch Command) for configuring the extended CSD register */
            transaction.cmd = MMCSD_CMD(6U);
            transaction.arg = argument;
            transaction.flags = 0U;
            ret = MMCSD_v2_transfer(handle, &transaction);
        }
        Osal_delay(5);
    }
    else
    {
        return MMCSD_ERR;
    }

    return(ret);
}

/*
 *  ======== MMCSD_v2_open ========
 */
static MMCSD_Error MMCSD_v2_open(MMCSD_Handle handle, MMCSD_Params params)
{
    SemaphoreP_Params           semParams;
    MMCSD_Error                 ret = MMCSD_ERR;
    uint32_t                    key;
    MMCSD_v2_Object            *object = NULL;
    MMCSD_v2_HwAttrs           *hwAttrs = NULL;
    OsalRegisterIntrParams_t interruptRegParams;
    OsalInterruptRetCode_e interruptRegRet;

    /* Input parameter validation */
    if (handle != NULL)
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;
        hwAttrs = (MMCSD_v2_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

        /* Determine if the device index was already opened */
        key = MMCSD_osalHardwareIntDisable();
        if (0 == ((MMCSD_v2_Object *)(((MMCSD_Config *) handle)->object))->isOpen)
        {
            ret = MMCSD_OK;
        }
        MMCSD_osalHardwareIntRestore(key);
    }

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

           if(MMCSD_OK == ret && (hwAttrs->configSocIntrPath!=NULL)){
             ret = hwAttrs->configSocIntrPath(hwAttrs,TRUE);
           }
            /* Construct Hwi object for this MMCSD peripheral */

		    if(ret==MMCSD_OK) {
		    /* Initialize with defaults */
            Osal_RegisterInterrupt_initParams(&interruptRegParams);

            interruptRegParams.corepacConfig.isrRoutine = (&MMCSD_v2_hwiFxn);
            interruptRegParams.corepacConfig.arg = (uintptr_t)handle;

			/* Populate the interrupt parameters */
            interruptRegParams.corepacConfig.name=NULL;

            interruptRegParams.corepacConfig.corepacEventNum=hwAttrs->eventId; /* Event going in to CPU */
            interruptRegParams.corepacConfig.intVecNum=hwAttrs->intNum; /* Host Interrupt vector */

               /* Register interrupts */
            interruptRegRet=MMCSD_osalRegisterInterrupt(&interruptRegParams,&(object->hwi));
            if(interruptRegRet!=OSAL_INT_SUCCESS) {
              ret=MMCSD_ERR;
            }
           } else {
			   ret=MMCSD_ERR_SET_SOC_INTERRUPT_PATH;
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

    }

    if ((MMCSD_OK == ret) && (hwAttrs->inputClockControl)) {
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
            ret = MMCSD_v2_initSd(handle);
        }
        else if (MMCSD_CARD_EMMC == object->cardType)
        {
            ret = MMCSD_v2_initEmmc(handle);
        }
        else
        {
            ret = MMCSD_ERR; /*dummy statement for misra warning*/
        }
    }

    /* Mark the object as in use */
    if(MMCSD_OK == ret)
    {
        ((MMCSD_v2_Object *)(((MMCSD_Config *) handle)->object))->isOpen = 1;
    }

    return (ret);
}
/* Data buffer for message transmission, it is not stack allocated to allow cache aligning */
#if defined(__GNUC__) && !defined(__ti__)
CSL_SET_DALIGN(256)  /* GCC way of aligning */
#else
CSL_SET_DALIGN(dataBuffer, 256)
#endif
static uint8_t                     dataBuffer[512];

#if defined(__GNUC__) && !defined(__ti__)
CSL_SET_DALIGN(256)            /* GCC way of aligning */
#else
CSL_SET_DALIGN(cmd6_response_buf, 256)
#endif
static uint8_t                     cmd6_response_buf[512];






/*
 *  ======== MMCSD_v2_initSd ========
 */
static MMCSD_Error MMCSD_v2_initSd(MMCSD_Handle handle)
{
    MMCSD_Error                 ret = MMCSD_OK;
    uint32_t                    retry = 0xFFFFU;
    MMCSD_v2_Object            *object = NULL;
    MMCSD_v2_HwAttrs const     *hwAttrs = NULL;
    MMCSD_v2_Transaction        transaction;
    volatile int32_t            status = CSL_ESYS_FAIL;
    stSDMMCHCCapability         hcCap = {0U, 0U, 0U, 0U};
    bool support18V_host=FALSE;
	bool attempt_18V_switch=TRUE; /* Always be optimistic to start with, unless some cards do not work well with it */

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v2_HwAttrs const *)((MMCSD_Config *) handle)->hwAttrs;

    if(hwAttrs->switchVoltageFxn != NULL)
    {
        support18V_host=((hwAttrs->supportedBusVoltages & MMCSD_BUS_VOLTAGE_1_8V))?TRUE:FALSE;
    }
	memset(dataBuffer,0,sizeof(dataBuffer));

    MMCSD_socPhyInit(hwAttrs);
	
    if(MMCSD_OK == ret)
    {
        /*
         * Refer to the MMC Host and Bus configuration steps in TRM
         * controller Reset
         */
        status = HSMMCSDSoftReset(hwAttrs->baseAddr);

        if (STW_SOK != status)
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
        status = HSMMCSDLinesReset(hwAttrs->baseAddr, HS_MMCSD_ALL_RESET);
        if(status!=STW_SOK) {
            MMCSD_DEBUG_TRAP
        }

        /* Set the bus width */
        status = HSMMCSDBusWidthSet(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_1BIT);
        if(status!=STW_SOK) {
            MMCSD_DEBUG_TRAP
        }

        /* Set the bus voltage */
		if(hwAttrs->supportedBusVoltages & MMCSD_BUS_VOLTAGE_3_3V) {
           status=HSMMCSDBusVoltSet(hwAttrs->baseAddr, MMC_HCTL_SDVS_3V3); /* Default */
           if(status!=STW_SOK) {
               MMCSD_DEBUG_TRAP
           }

		} else  if((hwAttrs->supportedBusVoltages & MMCSD_BUS_VOLTAGE_1_8V) &&
                   (hwAttrs->switchVoltageFxn != NULL)) {
           status = HSMMCSDBusVoltSet (hwAttrs->baseAddr, MMC_HCTL_SDVS_1V8);
           if(status!=STW_SOK) {
               MMCSD_DEBUG_TRAP
           }

        }

      /* Card detection */
   if(MMCSD_OK == ret)
   {
      uint32_t slotType,reg=0,ins=0;
      slotType = CSL_MMC_CTLCFG_CAPABILITIES_SLOT_TYPE_VAL_REMOVABLE;

      reg = *(&(((CSL_mmc_sscfgRegs *)(hwAttrs->ssBaseAddr))->CTL_CFG_2_REG));
      reg = Bitfield_csl_set (reg, slotType,
                            CSL_MMC_SSCFG_CTL_CFG_2_REG_SLOTTYPE_MASK,
                            CSL_MMC_SSCFG_CTL_CFG_2_REG_SLOTTYPE_SHIFT);
       *(&(((CSL_mmc_sscfgRegs *)(hwAttrs->ssBaseAddr))->CTL_CFG_2_REG))=reg;

      //
      // Enable pins by setting the IO mux field in the phy to 0.
      //
      reg = *(&(((CSL_mmc_sscfgRegs *)(hwAttrs->ssBaseAddr))->PHY_CTRL_1_REG));
      reg = Bitfield_csl_set (reg, 0,
                            CSL_MMC_SSCFG_PHY_CTRL_1_REG_IOMUX_ENABLE_MASK,
                            CSL_MMC_SSCFG_PHY_CTRL_1_REG_IOMUX_ENABLE_SHIFT);
      *(&(((CSL_mmc_sscfgRegs *)(hwAttrs->ssBaseAddr))->PHY_CTRL_1_REG))=reg;

      //
      // Wait for card detect.
      //
       ins=0;
       do {
          ins = HSMMCSDIsCardInserted(hwAttrs->baseAddr);
       } while(ins==0);
    }
        /* Bus power on */
        status = ((int32_t)(HSMMCSDBusPower(hwAttrs->baseAddr, MMC_HCTL_SDBP_PWRON)));
        if(status!=STW_SOK) {
            MMCSD_DEBUG_TRAP
        }

         status= HSMMCSDDataTimeoutSet(hwAttrs->baseAddr, MMC_SYSCTL_DTO_15THDTO);
        if(status!=STW_SOK) {
            MMCSD_DEBUG_TRAP
        }
        hcCap.flag1=HS_MMCSD_CAPA_ALL;
        hcCap.flag2=HS_MMCSD_CAPA_ALL;
        status = HSMMCSDHostCapabilityGet(hwAttrs->baseAddr,&hcCap);
        if(status!=STW_SOK) {
            MMCSD_DEBUG_TRAP
        }

		object->switched_to_v18=FALSE;
        if (STW_SOK != status)
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
        status = HSMMCSDBusFreqSet(hwAttrs->baseAddr, hwAttrs->inputClk,hwAttrs->outputClk, FALSE);

         Osal_delay(10);
        if(status !=STW_SOK) {
		  MMCSD_DEBUG_TRAP
		}
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
            ret = MMCSD_v2_transfer(handle, &transaction);
        } else { MMCSD_DEBUG_TRAP}
	}

    /******************* Send Operating Voltage (CMD8) ************************/
#ifndef SIMULATOR // Skip CMD8 when VLAB is used
        if(MMCSD_OK == ret)
        {
            uint32_t curr_bus_voltage;
			/* CMD8 - send oper voltage */
            transaction.cmd = MMCSD_CMD(8U);
            transaction.flags = MMCSD_CMDRSP_48BITS;
            transaction.arg = MMCSD_CHECK_PATTERN ;


            curr_bus_voltage=HSMMCSDBusVoltGet(hwAttrs->baseAddr);

            if(curr_bus_voltage==MMC_HCTL_SDVS_1V8)  {
               transaction.arg |= MMCSD_VOLT_LOW_RANGE;
			} else
			{
               transaction.arg |= MMCSD_VOLT_2P7_3P6;
            }

            ret = MMCSD_v2_transfer(handle, &transaction);
        }  else { MMCSD_DEBUG_TRAP}
#endif // CMD8 does not for VLAB
        if (MMCSD_OK != ret)
        {
            /*
             * If the cmd fails  , it can be due to version < 2.0, since
             * we are currently supporting high voltage cards only
             */
             ret=MMCSD_OK;
		     MMCSD_DEBUG_TRAP

        }
        /******************************* Send OCR (ACMD41) *********************/
        if(MMCSD_OK == ret)
        {
            /* Poll until we get the card status (BIT31 of OCR) is powered up */
            do
            {
                /* APP cmd should be preceeded by a CMD55 */
                transaction.cmd = MMCSD_CMD(55U);
                transaction.flags = MMCSD_CMDRSP_48BITS;
                transaction.arg = 0; /* object->rca is zero as the card is in the idle state */
                ret = MMCSD_v2_transfer(handle, &transaction);

                if(MMCSD_OK == ret)
                {
                    transaction.cmd = MMCSD_CMD(41U);
                    transaction.flags = MMCSD_CMDRSP_48BITS;
                    transaction.arg = MMCSD_OCR_HIGH_CAPACITY | MMCSD_OCR_VDD_WILDCARD;
                    if(support18V_host) {
                    	/* Host supports 1.8V and seek if the card supports it */
                    	transaction.arg|= MMCSD_OCR_S18R;
                    }
                   ret= MMCSD_v2_transfer(handle, &transaction);
                }
                else
                {
                    ret = MMCSD_ERR;
                  { MMCSD_DEBUG_TRAP
			      }
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

        object->uhsCard=FALSE;
        /****************************** Switch to 1.8V if needed *********************************/
        if(MMCSD_OK == ret)
        {
            object->ocr = transaction.response[0U];
            /* Card capacity status (CCS) Bit 30 */
            object->highCap = (object->ocr & MMCSD_OCR_HIGH_CAPACITY) ? 1U : 0U;

            /* Bit32 of the response R3 (S18A)*/
            object->support1_8V = (transaction.response[0U] & MMCSD_OCR_S18R) ? 1U : 0U;

			if(HSMMCSDBusVoltGet(hwAttrs->baseAddr)==MMC_HCTL_SDVS_1V8) {
			   attempt_18V_switch=FALSE;
			   object->switched_to_v18=TRUE; /* Already in 1.8V mode */
			}

			/* If 1.8V is supported, configure the card accordingly to switch to SDR modes */
            if(object->support1_8V && support18V_host && attempt_18V_switch)
            {
                MMCSD_drv_log(Diags_USER1, "MMCSD: S18R indicates 1.8V support\n");

  			    bool falseloop_1p8V_switch=TRUE;
			    do
			    {

			      falseloop_1p8V_switch=FALSE;

                  MMCSD_drv_log(Diags_USER1, "MMCSD: Sending CMD11 \n");
				  /* Start the voltage switching procedure */
                  /* Send CMD11 */
                  transaction.cmd = MMCSD_CMD(11U);
                  transaction.flags = MMCSD_CMDRSP_48BITS;
                  transaction.arg = 0U;
                  ret = MMCSD_v2_transfer(handle, &transaction);


                  if(MMCSD_OK == ret)
				  {
                	   uint32_t retry_count,dataSigLevel;
                	   /* Voltage sequence acknowledge */
                	   MMCSD_drv_log(Diags_USER1,"MMCSD DRV:  Voltage sequence acknowledged via CMD11\n");

                	   MMCSD_drv_log(Diags_USER1,"MMCSD DRV:  Setting the SDVS and V1V8 SIGEN \n");

                       HSMMCSDSDClockDisable(hwAttrs->baseAddr); /* Disable clock to SD card */

                       /* Wait for CMD and DAT levels to go low */
                	   retry_count=10;

                       do {
						 dataSigLevel=HSMMCSDGetDataSignalLevel(hwAttrs->baseAddr);
                       } while(dataSigLevel!=0);

					   if(retry_count==0) {
					      /* CMD11 failed. Switch not possible */
					      ret=MMCSD_ERR_1P8V_SWITCH_CARD_CMD11_FAILURE;
					      MMCSD_DEBUG_TRAP
					   }


               	        /* Switch the board voltage to 1.8V */
					    if(hwAttrs->switchVoltageFxn!=NULL) {
						  ret = hwAttrs->switchVoltageFxn(hwAttrs->instNum,MMCSD_BUS_VOLTAGE_1_8V);
					    }  
                	    
						if(ret!=MMCSD_OK) {
						  ret=MMCSD_ERR_1P8V_SWITCH_MMCIO_SWITCH_FAILURE;
						   break;
						}
 
                       status=HSMMCSDBusVoltSet(hwAttrs->baseAddr, MMC_HCTL_SDVS_1V8);

					   HSMMCSDSwitchSignalVoltage (hwAttrs->baseAddr, MMC_AC12_V1V8_SIGEN_1V8);

					   /* Wait for 5 ms */
					   Osal_delay(5);
                       /* Set the bus voltage */

					   /* wait if the signal voltage bit is set to 1 */
					   if(HSMMCSDGetSignalVoltage (hwAttrs->baseAddr)==!MMC_AC12_V1V8_SIGEN_1V8) {
						   MMCSD_DEBUG_TRAP
					   }


                        HSMMCSDSDClockEnable(hwAttrs->baseAddr); /* Enable clock to SD card */
					    /* Wait for 1 ms */
					    Osal_delay(1);

                        /* Check if the dat[0-3] level has gone to 0x1111 */
                        do {
 	  					   dataSigLevel=HSMMCSDGetDataSignalLevel(hwAttrs->baseAddr);
                        } while(dataSigLevel!=0xf);



				 	    object->switched_to_v18=TRUE;
				 	    object->uhsCard=TRUE;
                 	    MMCSD_drv_log(Diags_USER1,"1.8V switching procedure complete\n");

					}
                } while(falseloop_1p8V_switch);

			    if(ret!=MMCSD_OK) {

				/* Reverse the voltage switch */
				  if(hwAttrs->switchVoltageFxn!=NULL) {
				     ret = hwAttrs->switchVoltageFxn(hwAttrs->instNum,MMCSD_BUS_VOLTAGE_3_3V);
				  }
				  
				  HSMMCSDSwitchSignalVoltage (hwAttrs->baseAddr, MMC_AC12_V1V8_SIGEN_3V3);
 	              /* Wait for 5 ms */
	              Osal_delay(5);
                  
	              /* wait if the signal voltage bit is set to 1 */
	              if(HSMMCSDGetSignalVoltage (hwAttrs->baseAddr)==!MMC_AC12_V1V8_SIGEN_3V3) {
  	                MMCSD_DEBUG_TRAP
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

            ret = MMCSD_v2_transfer(handle, &transaction);

            object->cid[3]= (transaction.response[3] << 8)| (transaction.response[2] >> 24);
            object->cid[2]= (transaction.response[2] << 8)| (transaction.response[1] >> 24);
            object->cid[1]= (transaction.response[1] << 8)| (transaction.response[0] >> 24);
            object->cid[0]= (transaction.response[0] << 8);

     }  else {MMCSD_DEBUG_TRAP}

     /************************ Get RCA (CMD3) **********************************/
     if(MMCSD_OK == ret)
     {
            /* Send CMD3, to get the card relative address */
            transaction.cmd = MMCSD_CMD(3U);
            transaction.flags = 0U;
            transaction.arg = 0U;

            ret = MMCSD_v2_transfer(handle, &transaction);

            object->rca = MMCSD_RCA_ADDR(transaction.response[0U]);
      }  else { MMCSD_DEBUG_TRAP}

        /******************* Get card specific data(CSD) via CMD9 ***********************/
        if(MMCSD_OK == ret)
        {
            /* Send CMD9, to get the card specific data */
            transaction.cmd = MMCSD_CMD(9U);
            transaction.flags = MMCSD_CMDRSP_136BITS;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v2_transfer(handle, &transaction);

            object->csd[3]= (transaction.response[3] << 8)| (transaction.response[2] >> 24);
            object->csd[2]= (transaction.response[2] << 8)| (transaction.response[1] >> 24);
            object->csd[1]= (transaction.response[1] << 8)| (transaction.response[0] >> 24);
            object->csd[0]= (transaction.response[0] << 8);
        }  else { MMCSD_DEBUG_TRAP }


      /************ Select the card (CMD7) ****************/

        if(MMCSD_OK == ret)
        {
            /* Select the card */
            transaction.cmd = MMCSD_CMD(7U);
            transaction.flags = MMCSD_CMDRSP_BUSY;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v2_transfer(handle, &transaction);
        }  else { MMCSD_DEBUG_TRAP }

	 /* Wait for DAT0 to go low */
	 MMCSD_v2_waitDat0(hwAttrs);

    /******** Set block len (CMD16) based on the CSD register *******/
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
                ret = MMCSD_v2_transfer(handle, &transaction);

                if(MMCSD_OK == ret)
                {
                    object->blockSize = 512U;
                }
            }
        }  else { MMCSD_DEBUG_TRAP }

    /************************ Get the SCR Register (ACMD51) *****************************/

        if(MMCSD_OK == ret)
        {
            /*
             * Send ACMD51, to get the SD Configuration register details.
             * Note, this needs data transfer (on data lines).
             */
            transaction.cmd = MMCSD_CMD(55U);
            transaction.flags = 0U;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v2_transfer(handle, &transaction);
        }  else { MMCSD_DEBUG_TRAP }



        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(51U);
            transaction.flags = MMCSD_CMDRSP_48BITS | MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
            transaction.arg = object->rca << 16U;
            transaction.blockCount = 1U;
            transaction.blockSize = 8U;
            transaction.dataBuf = dataBuffer;

            ret = MMCSD_v2_transfer(handle, &transaction);
        }  else { MMCSD_DEBUG_TRAP }

        if(MMCSD_OK == ret)
        {
             object->scr[0] = dataBuffer[0] << 24 | dataBuffer[1] << 16 | dataBuffer[2] << 8 | dataBuffer[3];
             object->scr[1] = dataBuffer[4] << 24 | dataBuffer[5] << 16 | dataBuffer[6] << 8 | dataBuffer[7];

            object->sdVer = MMCSD_CARD_VERSION(object);
            object->busWidth = MMCSD_CARD_BUSWIDTH(object);
			object->cmd23Supported = MMCSD_CARD_CMD23_SUPPORT(object);
        }  else { MMCSD_DEBUG_TRAP }

     /*****************  Set the bus width,1bit or 4 bit (ACMD6)   ********************/


        if(MMCSD_OK == ret)
        {
            /* APP cmd should be preceeded by a CMD55 */
            transaction.cmd = MMCSD_CMD(55U);
            transaction.flags = 0U;
            transaction.arg = object->rca << 16U;
            ret = MMCSD_v2_transfer(handle, &transaction);
        }  else { MMCSD_DEBUG_TRAP }

        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(6U);
            transaction.arg = MMCSD_BUS_WIDTH_1BIT;
            transaction.flags = 0U;

            if (((MMCSD_v2_HwAttrs *)(((MMCSD_Config *) handle)->hwAttrs))->supportedBusWidth & MMCSD_BUS_WIDTH_4BIT)
            {
                if (object->busWidth & MMCSD_BUS_WIDTH_4BIT)
                {
                    transaction.arg = MMCSD_BUS_WIDTH_4BIT;
                }
            }

            transaction.arg = transaction.arg >> 1U;
            ret = MMCSD_v2_transfer(handle, &transaction);


            if (MMCSD_OK == ret)
            {
                if (0U == transaction.arg)
                {
                    HSMMCSDBusWidthSet(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_1BIT);
                }
                else
                {
                    HSMMCSDBusWidthSet(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_4BIT);
                }
            }  else { MMCSD_DEBUG_TRAP }
         }



        /****************** Find out the speeds supported , to switch to high speeds **************/
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
            ret = MMCSD_v2_transfer(handle, &transaction);
        }  else { MMCSD_DEBUG_TRAP }

         /* Wait for DAT0 to go low */
         MMCSD_v2_waitDat0(hwAttrs);

		/* Perform the switch and see what function it switches to */
#ifndef SIMULATOR // Skip CMD8 when VLAB is used
        if(MMCSD_OK == ret)
        {
            uint32_t cmd16_grp1_fn = MMCSD_CMD6_GRP1_DEFAULT;
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
 			  if( (hwAttrs->supportedModes & MMCSD_SUPPORT_SD_SDR104) && (cmd6_groups[i]==MMCSD_CMD6_GRP1_SDR104) && object->switched_to_v18 && (hcCap.retValue2 & MMC_CAPA2_SDR104_MASK) && (dataBuffer[13] & (1<< MMCSD_CMD6_GRP1_SDR104))) {
                cmd16_grp1_fn=MMCSD_CMD6_GRP1_SDR104;
                MMCSD_drv_log(Diags_USER1,"CMD6 Says Card Supports SDR104\n");
              } else if ( (hwAttrs->supportedModes & MMCSD_SUPPORT_SD_SDR50) &&  (cmd6_groups[i]==MMCSD_CMD6_GRP1_SDR50) && object->switched_to_v18 &&  (hcCap.retValue2 & MMC_CAPA2_SDR50_MASK) && (dataBuffer[13] & (1<< MMCSD_CMD6_GRP1_SDR50))) {
                cmd16_grp1_fn=MMCSD_CMD6_GRP1_SDR50;
                MMCSD_drv_log(Diags_USER1,"CMD6 Says Card Supports SDR50\n");
			  } else
  			  if (  (hwAttrs->supportedModes & MMCSD_SUPPORT_SD_DDR50) &&   (cmd6_groups[i]==MMCSD_CMD6_GRP1_DDR50) && object->switched_to_v18 && (hcCap.retValue2 & MMC_CAPA2_DDR50_MASK) && (dataBuffer[13] & (1<< MMCSD_CMD6_GRP1_DDR50))) {
                cmd16_grp1_fn=MMCSD_CMD6_GRP1_DDR50;
                MMCSD_drv_log(Diags_USER1,"CMD6 Says Card Supports DDR50\n");
			  } else
			  if ( (hwAttrs->supportedModes & MMCSD_SUPPORT_SD_HS) &&  (cmd6_groups[i]==MMCSD_CMD6_GRP1_HS) && (dataBuffer[13] & (1<< MMCSD_CMD6_GRP1_HS))) {
                 cmd16_grp1_fn=MMCSD_CMD6_GRP1_HS;
                 MMCSD_drv_log(Diags_USER1,"CMD6 Says Card Supports HS\n");
  			  } else if ( (hwAttrs->supportedModes & MMCSD_SUPPORT_SD_DS) && (cmd6_groups[i]==MMCSD_CMD6_GRP1_DEFAULT) && (dataBuffer[13] & (1<< MMCSD_CMD6_GRP1_DEFAULT))) {
			     cmd16_grp1_fn=MMCSD_CMD6_GRP1_DEFAULT;
                 MMCSD_drv_log(Diags_USER1,"CMD6 Says Card Supports default\n");
			   } else {
				   continue;
			   }

 			  // ret=MMCSD_switch_card_curr_limit (handle,MMCSD_CMD6_GRP4_800mA);
 	           if(ret!=MMCSD_OK) {
 	           	   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Current switch not successful\n");
 			   }
              ret=MMCSD_switch_card_speed(handle,cmd16_grp1_fn);
			  if(ret==MMCSD_OK) {
			     MMCSD_drv_log(Diags_USER1," Successfully switched to the above speed");
			     break;/* Successful switching */
			  }
 		    }

        }  else {MMCSD_DEBUG_TRAP}
#endif	//CMD6 does not work for VLAB

        if(MMCSD_OK != ret)
        {
			MMCSD_DEBUG_TRAP
           MMCSD_v2_close(handle);
        }
        return (ret);
}
/***********************************************************************/
static MMCSD_Error MMCSD_switch_card_speed(MMCSD_Handle handle,uint32_t cmd16_grp1_fn)
{
   MMCSD_Error ret=MMCSD_ERR;
   MMCSD_v2_Object            *object = NULL;
   MMCSD_v2_HwAttrs           *hwAttrs = NULL;
   MMCSD_v2_Transaction        transaction;
   uint32_t uhsMode=0xFFFF; /* Undefined */
   stSDMMCHCCapability hcCapab={0,0,0,0};

   Bool sdr104_tuning_required=FALSE,switch_speed_approved=TRUE;
   uint32_t phy_mode=0,phy_driverType=0,phy_freq=0;
   int32_t retVal=STW_SOK;

   object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;
   hwAttrs = (MMCSD_v2_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

   //Reading the Capability Register
   hcCapab.flag1 = HS_MMCSD_CAPA_ALL;
   hcCapab.flag2 = HS_MMCSD_CAPA_ALL;

   HSMMCSDHostCapabilityGet(hwAttrs->baseAddr, &hcCapab);

#ifdef  MMCSD_CONFIGURE_PHY
   if(hcCapab.retValue2 & MMC_CAPA2_DTA_MASK)
   {
	 phy_driverType = PHY_IO_PADS_CTRL1_DR_TYPE_A;
   }
   if(hcCapab.retValue2 & MMC_CAPA2_DTD_MASK)
   {
	 phy_driverType = PHY_IO_PADS_CTRL1_DR_TYPE_D;
   }
   else
   {
	 phy_driverType = PHY_IO_PADS_CTRL1_DR_TYPE_C;
   }
#endif

   memset(cmd6_response_buf,0,sizeof(cmd6_response_buf));
   /* Send CMD16 to switch to the requested group */
   transaction.cmd = MMCSD_CMD(6U);
   transaction.arg = ((MMCSD_SWITCH_MODE & MMCSD_CMD6_GRP1_SEL) | cmd16_grp1_fn);
   transaction.flags = MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
   transaction.blockCount = 1U;
   transaction.blockSize = 64U;
   transaction.dataBuf = cmd6_response_buf;

   ret = MMCSD_v2_transfer(handle, &transaction);
   /* Wait for DAT0 to go low */
   MMCSD_v2_waitDat0(hwAttrs);

   if (MMCSD_OK == ret)
   {   /* Checking bits 379:376 of the CMD6 response  to see if the switch happened successfully */
     	uint32_t clk_freq,tranSpeed;

   	    if ((cmd6_response_buf[16U] & 0xFU) == MMCSD_CMD6_GRP1_SDR104 && (cmd16_grp1_fn==MMCSD_CMD6_GRP1_SDR104))
		{
		   tranSpeed = MMCSD_TRANSPEED_SDR104;
		   uhsMode=MMC_AC12_UHSMS_SDR104;
		   sdr104_tuning_required=TRUE;
		   clk_freq=208000000U; /* Max freq supported is 208MHz */
		   phy_freq=200000000U;
		   phy_mode=MODE_SDR104;
		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Request to switch to SDR104: 192Mhz\n");

        } else if  ( ((cmd6_response_buf[16U] & 0xFU) == MMCSD_CMD6_GRP1_SDR50 ) && (cmd16_grp1_fn==MMCSD_CMD6_GRP1_SDR50))
	    {
		   tranSpeed = MMCSD_TRANSPEED_SDR50;
  		   uhsMode=MMC_AC12_UHSMS_SDR50;
		   clk_freq=100000000U; /* 100MHz for SDR50  */
		   phy_freq=100000000U;
  		   phy_mode = MODE_SDR50;
  		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Request to switch to SDR50: 100Mhz\n");
		} else if  ( ((cmd6_response_buf[16U] & 0xFU) == MMCSD_CMD6_GRP1_DDR50) && (cmd16_grp1_fn==MMCSD_CMD6_GRP1_DDR50))
		{
		   tranSpeed = MMCSD_TRANSPEED_DDR50;
  		   uhsMode=MMC_AC12_UHSMS_DDR50;
		   clk_freq=50000000U; /* 50MHz for DDR50  */
		   phy_freq=50000000U;
		   phy_mode=MODE_DDR50;
   		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Request to switch to DDR50: 100Mhz\n");

		}  else if (((cmd6_response_buf[16U] & 0xFU) == MMCSD_CMD6_GRP1_HS) && (cmd16_grp1_fn==MMCSD_CMD6_GRP1_HS))
		{
            tranSpeed = MMCSD_TRANSPEED_50MBPS;
            if(object->uhsCard) {
			  uhsMode= MMC_AC12_UHSMS_SDR25;
			}
 		    clk_freq=50000000U; /* 50MHz for HS mode */
		    phy_freq=50000000U;
            phy_mode = MODE_SDR25;
    		MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Request to switch to HS: 50Mhz\n");
		} else if (((cmd6_response_buf[16U] & 0xFU) == MMCSD_CMD6_GRP1_DEFAULT) && (cmd16_grp1_fn==MMCSD_CMD6_GRP1_DEFAULT))
		{
           tranSpeed = MMCSD_TRANSPEED_25MBPS;
           if(object->uhsCard) {
  		     uhsMode=MMC_AC12_UHSMS_SDR12;
		   }
    	   clk_freq=25000000U;  /* 25MHz for SDR12 */
    	   phy_mode =  MODE_SDR12;
		   phy_freq=25000000U;
		   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Request to switch to SDR12: 25Mhz\n");

        } else {
		   /* Speed switch not approved */
    	   MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: Wrong Speed requested\n");
		   switch_speed_approved=FALSE;
		}

		if(switch_speed_approved)  {
          /* Set input clock to make sure that the input clock is equal or higher to the clock value
           * requested */
  	      if(NULL != hwAttrs->inputClockControl) {
  	    	  uint32_t inputClockRet = hwAttrs->inputClockControl(hwAttrs->instNum, &clk_freq, MMCSD_INPUT_CLOCK_CTRL_SET);
  	  	      if (inputClockRet != 0U) {
                hwAttrs->inputClk=inputClockRet;
  	  	      } else {
  	  	    	MMCSD_drv_log4(Diags_USER1,"Unable to change input clock to %d\n",clk_freq);
  	  	      }
  	      }

      if(!object->uhsCard) {
  	     /* For non UHS cards, it is the high speed/ Default speed mode */
  	      if(tranSpeed==MMCSD_TRANSPEED_50MBPS) {
		      /* For non-high speed modes the data should be on the falling edge */
		      HSMMCSDHSModeSet(hwAttrs->baseAddr,MMC_HCTL_HSPE_NORMALSPEED);
			  phy_mode = MODE_HS;
 	       }  else if(tranSpeed==MMCSD_TRANSPEED_25MBPS) {
		      /* For non-high speed modes the data should be on the falling edge */
			  HSMMCSDHSModeSet(hwAttrs->baseAddr,MMC_HCTL_HSPE_NORMALSPEED);
			  phy_mode = MODE_DS;
	       } else {
			 /* This shouldn't happen */
			 ret = MMCSD_ERR;
			 MMCSD_DEBUG_TRAP
		   }
	  } else {
		  /* Set the UHS mode accordingly */
		  if(uhsMode!=0xffff) {
		    HSMMCSDUhsModeSet(hwAttrs->baseAddr,uhsMode);
            if( (uhsMode==MMC_AC12_UHSMS_SDR12) || 
                (uhsMode==MMC_AC12_UHSMS_SDR25) ||
                (uhsMode==MMC_AC12_UHSMS_SDR50) )
            {
		      /* For non-high speed modes the data should be on the falling edge */
			  HSMMCSDHSModeSet(hwAttrs->baseAddr,MMC_HCTL_HSPE_NORMALSPEED);
            } else
            {
			  HSMMCSDHSModeSet(hwAttrs->baseAddr,MMC_HCTL_HSPE_HIGHSPEED);
            }
  
		  } else { MMCSD_DEBUG_TRAP }
	  }

	  
	  MMCSD_socPhyDisableDLL((MMCSD_v2_HwAttrs const *)hwAttrs);

         /* Change clock only if required */
       if(STW_SOK == HSMMCSDBusFreqSet(hwAttrs->baseAddr, hwAttrs->inputClk, clk_freq, 0U))
       {
          ret = MMCSD_OK;
       } else {
		  MMCSD_DEBUG_TRAP
		  return (MMCSD_ERR);
	   }
        Osal_delay(50);
        /* Configure the Phy accordignly */
        
        retVal = MMCSD_socPhyConfigure((MMCSD_v2_HwAttrs const *)hwAttrs,phy_mode, phy_freq, phy_driverType);
        
 	    if(retVal != MMCSD_OK)
	    {
		  MMCSD_DEBUG_TRAP
	    }

		if(hwAttrs->tuningType == MMCSD_AUTO_HW_TUNING) {
		  object->manualTuning=FALSE;
		} else if(hwAttrs->tuningType == MMCSD_MANUAL_SW_TUNING) {
		  object->manualTuning=TRUE;
		}	
 		  /* Tuning mandatory for SDR104 */
		  if(sdr104_tuning_required) {
		    MMCSD_drv_log(Diags_USER1,"MMCSD_switch_card_speed: About to execute Tuning procedure\n");
    		if(object->manualTuning) {
    	      ret=mmcsd_tuning_procedure_SD_manual(handle);
	       } else {
			  ret=mmcsd_tuning_procedure(handle);	
		   }

						
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

	return ret;
}

uint32_t mmcsd_send_tuning(MMCSD_Handle handle) {

    uint8_t                     dataBuffer[64] = {0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U,
                                                   0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U,
                                                   0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U,
                                                   0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U};
    MMCSD_Error                 ret = MMCSD_OK;
    MMCSD_v2_Transaction        transaction;
    Bool tuning_fail=FALSE;
	uint32_t i;
	uint32_t enableInterrupts,enableDma;
	MMCSD_v2_HwAttrs *hwAttrs;
	hwAttrs = (MMCSD_v2_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

	enableInterrupts=hwAttrs->enableInterrupt;
	enableDma=hwAttrs->enableDma;

    hwAttrs->enableInterrupt=0;
    hwAttrs->enableDma=0;

	/* Send CMD19 */
    transaction.cmd = MMCSD_CMD(19U);
    transaction.arg = 0;
    transaction.flags = MMCSD_CMDRSP_48BITS | MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
    transaction.blockCount = 1U;
    transaction.blockSize = sizeof(tuning_blk_pattern_4bit); /* 64 bytes */
    transaction.dataBuf = dataBuffer;/* Tuning data from the SD card comes here */
    ret = MMCSD_v2_transfer(handle, &transaction);

    if(ret==MMCSD_OK) {
	  /* Compare the data recieved from the card to the expected values*/
	  for(i = 0U; i < sizeof(tuning_blk_pattern_4bit); i++) {
	    if(dataBuffer[i]!=tuning_blk_pattern_4bit[i]) {
		   tuning_fail=TRUE;
		 break;
		}
	  }
	} else {
	   tuning_fail=TRUE;
    }

    hwAttrs->enableInterrupt=enableInterrupts;
    hwAttrs->enableDma=enableDma;
    return(tuning_fail);
}

uint32_t mmcsd_send_tuning_eMMC(MMCSD_Handle handle) {

    uint8_t                     dataBuffer[256U] = {0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U,
                                                   0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U,
                                                   0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U,
                                                   0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U, 0U,0U,0U,0U};

    MMCSD_Error                 ret = MMCSD_OK;
    MMCSD_v2_Transaction        transaction;
    Bool tuning_fail=FALSE;
	uint32_t i;
	uint32_t enableInterrupts,enableDma;
	MMCSD_v2_HwAttrs *hwAttrs;
	hwAttrs = (MMCSD_v2_HwAttrs *)((MMCSD_Config *) handle)->hwAttrs;

	enableInterrupts=hwAttrs->enableInterrupt;
	enableDma=hwAttrs->enableDma;
    hwAttrs->enableInterrupt=0;
    hwAttrs->enableDma=0;

	/* Send CMD21 */
    transaction.cmd = MMCSD_CMD(21U);
    transaction.arg = 0;
    transaction.flags = MMCSD_CMDRSP_48BITS | MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
    transaction.blockCount = 1U;
    transaction.blockSize = sizeof(tuning_blk_pattern_8bit); /* 128 bytes */
    transaction.dataBuf = dataBuffer;/* Tuning data from the SD card comes here */
    ret = MMCSD_v2_transfer(handle, &transaction);

    if(ret==MMCSD_OK) {
	  /* Compare the data recieved from the card to the expected values*/
	  for(i = 0U;i < sizeof(tuning_blk_pattern_8bit); i++) {
	    if(dataBuffer[i]!=tuning_blk_pattern_8bit[i]) {
		   tuning_fail=TRUE;
		 break;
		}
	  }
	} else {
	   tuning_fail=TRUE;
    }

    hwAttrs->enableInterrupt=enableInterrupts;
    hwAttrs->enableDma=enableDma;

    return(tuning_fail);
}


MMCSD_Error MMCSD_switch_eMMC_mode(MMCSD_Handle handle, MMCSD_SupportedMMCModes_e mode);
MMCSD_Error MMCSD_switch_eMMC_mode(MMCSD_Handle handle, MMCSD_SupportedMMCModes_e mode)
{
    volatile int32_t            ret=MMCSD_OK;
    uint8_t       HS_TIMING_val=0,HS_TIMING_index=185; /* EXT_CSD[185] holds HS_TIMING byte */
    uint32_t     phy_clk_freq=26000000,clk_freq=26000000; /* Default 26Mhz */
    uint32_t uhsMode=MMC_AC12_UHSMS_SDR12;
    uint32_t drvStrength=0;
    uint32_t phyDriverType=0; /* Default 60ohms */
    uint32_t phyMode= MODE_DS;
    bool tuning_required=FALSE;
    bool ddrMode=FALSE;
    uint32_t enhancedStrobe=0;
    MMCSD_v2_Object *object;
    MMCSD_v2_HwAttrs const *hwAttrs = NULL;
    MMCSD_v2_Transaction    transaction;
    uint32_t drvStrength_controller=0;

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v2_HwAttrs const *)((MMCSD_Config *) handle)->hwAttrs;

    drvStrength = object->ecsd[185] >> 4;/* To be obtained from the EXT_CSD */


   if((mode == MMCSD_SUPPORT_MMC_HS200) || (mode == MMCSD_SUPPORT_MMC_HS400))
   {
     /*
    * To switch to HS200, host has to perform the following steps:
    1) Select the device (through sending CMD7) and make sure it is unlocked (through CMD42)
    2) Read the DEVICE_TYPE [196] field of the Extended CSD register to validate
      if the device supports HS200 at the IO voltage appropriate for both host and device
    3) Read the DRIVER_STRENGTH [197] field of the Extended CSD register to find
      * the supported device Driver Strengths. Note: This step can be skipped if changes of driver strength is not needed
     4) Set HS200 bit and Driver Strength value in the HS_TIMING [185] field of
       * the Extended CSD register by issuing CMD6. If the host attempts to write an invalid value, the HS_TIMING byte is not changed, the HS200 interface timing is not enabled, the Driver Strength is not changed, and the SWITCH_ERROR bit is set. After the device responds with R1, it might assert Busy signal. Once the busy signal gets de-asserted, the host may send a SEND_STATUS Command (CMD13) using the HS200 timing and after it receives a Trans State indication and No Error it means that the device is set to HS200 timing and the Driver Strength is set to the selected settings.
     5) At this point, the host can set the frequency to ≤ 200 MHz.
     6) The host may invoke the HS200 tuning sequence,
     * by sending CMD21 to the device (see 6.6.5).
     NOTE The host should switch to the required bus width before starting the tuning operation to allow the
      *  tuning sequence to be done using the proper bus operating conditions.
      */

      /* Select the device CMD7 */
      /* EXT CSD already has been read, so just check if it is supported */
      /* Read the driver strength */

      /* Send Command 6 to switch the HS_TIMING MODE */
      HS_TIMING_val = MMCSD_ECSD_HS_TIMING_HS200;
      clk_freq = 200000000;
      phyMode = MODE_HS200;
      tuning_required=TRUE;
      uhsMode =MMC_AC12_UHSMS_SDR104;
    } else if ( (mode == MMCSD_SUPPORT_MMC_HS_SDR) || (mode == MMCSD_SUPPORT_MMC_HS_DDR) )
    {
      HS_TIMING_val = MMCSD_ECSD_HS_TIMING_HIGH_SPEED;
      tuning_required=FALSE;
      clk_freq = 52000000;
      if (mode == MMCSD_SUPPORT_MMC_HS_DDR)
      {
		  ddrMode=TRUE;
		  uhsMode =MMC_AC12_UHSMS_DDR50;
		  phyMode=MODE_HSDDR50;
	  } else {
		  uhsMode =MMC_AC12_UHSMS_SDR50;
          phyMode = MODE_HSSDR50;
	  }

	} else {
      phyMode = MODE_DS;
      HS_TIMING_val = MMCSD_ECSD_HS_TIMING_BACKWARD_COMPATIBLE;
      tuning_required=FALSE;
      clk_freq = 26000000;
	}


      /* Send the Switch command to change the HS TIMINIG bit of the EXT_CSD[185]  */
     if(MMCSD_OK == ret)
     {
        transaction.cmd = MMCSD_CMD(6U);
        transaction.arg = 0x03000000 | (HS_TIMING_index << 16) | (( (drvStrength <<4) | HS_TIMING_val) << 8);
        transaction.flags = MMCSD_CMDRSP_BUSY;
        ret = MMCSD_v2_transfer(handle, &transaction);
     }
     Osal_delay(50);
     if(MMCSD_OK == ret) {
  		/* Wait for DAT0 to go low */
       MMCSD_v2_waitDat0(hwAttrs);
	 }

     if(ddrMode==TRUE)
     {
       uint8_t ecsd_bus_width;
       if(object->busWidth==MMCSD_BUS_WIDTH_8BIT) {
		  ecsd_bus_width= MMCSD_ECSD_BUS_WIDTH_8BIT_DDR;
	   } else {
		  ecsd_bus_width= MMCSD_ECSD_BUS_WIDTH_4BIT_DDR;
	   }

       transaction.cmd = MMCSD_CMD(6U);
       transaction.arg = 0x03000000 | (MMCSD_ECSD_BUS_WIDTH_INDEX << 16) | (( (enhancedStrobe << MMCSD_ECSD_BUS_WIDTH_ES_SHIFT) | ecsd_bus_width) << 8);
       transaction.flags = MMCSD_CMDRSP_BUSY;
       ret = MMCSD_v2_transfer(handle, &transaction);

       Osal_delay(50);
       if(MMCSD_OK == ret) {
  	  	  /* Wait for DAT0 to go low */
          MMCSD_v2_waitDat0(hwAttrs);
       }
       phy_clk_freq=52000000;

     } else {
	  phy_clk_freq=clk_freq;
     }

    /* Configure the host controller and Phy */
	ret = HSMMCSDUhsModeSet(hwAttrs->baseAddr, uhsMode);

    MMCSD_socPhyDisableDLL(hwAttrs);

    ret = HSMMCSDBusFreqSet(hwAttrs->baseAddr, hwAttrs->inputClk, clk_freq, 0U);
    if(ret!=STW_SOK) {
		return MMCSD_ERR;
	}

    /* NEW: Enable DLL */
    Osal_delay(50);
     

    MMCSD_socPhyConfigure(hwAttrs,phyMode, phy_clk_freq, phyDriverType);

	if(hwAttrs->tuningType == MMCSD_AUTO_HW_TUNING) {
   	   object->manualTuning=FALSE;
	} else if(hwAttrs->tuningType == MMCSD_MANUAL_SW_TUNING) {
  	   object->manualTuning=TRUE;
	}
	
     /* Tuning mandatory for HS200 */
    if(tuning_required) {
		if(object->manualTuning) {
	      ret=mmcsd_tuning_procedure_EMMC_manual(handle);
	    } else {
	      ret=mmcsd_tuning_procedure(handle);	
		}
		
	   if(ret!=MMCSD_OK) {
          MMCSD_DEBUG_TRAP
	   }
     }

     if((mode == MMCSD_SUPPORT_MMC_HS400) || (mode == MMCSD_SUPPORT_MMC_HS400_ES))
     {
		if(mode ==MMCSD_SUPPORT_MMC_HS400_ES)
		{
			enhancedStrobe=1;
		}
		/*
		 Set the “Timing Interface” parameter in the HS_TIMING [185] field
		 * of the Extended CSD register to 0x1 to switch to High Speed mode and
		 * then set the clock frequency to a value not greater than 52 MHz,
         */
         HS_TIMING_val=MMCSD_ECSD_HS_TIMING_HIGH_SPEED;
         transaction.cmd = MMCSD_CMD(6U);
         transaction.arg = 0x03000000 | (MMCSD_ECSD_HS_TIMING_INDEX << 16) | (( (enhancedStrobe <<4) | HS_TIMING_val) << 8);
         transaction.flags = MMCSD_CMDRSP_BUSY;
         ret = MMCSD_v2_transfer(handle, &transaction);

       Osal_delay(50);



	  MMCSD_socPhyDisableDLL(hwAttrs);

       ret = HSMMCSDBusFreqSet(hwAttrs->baseAddr, hwAttrs->inputClk, 52000000, 0U);
       if(ret!=STW_SOK) {
		  return MMCSD_ERR;
	   }

       Osal_delay(50);

       phyMode = MODE_HSSDR50;
       
       MMCSD_socPhyConfigure(hwAttrs,phyMode, 50000000, phyDriverType);
      
       /*Set BUS_WIDTH[183] to 0x06 to select the dual data rate x8 bus mode */
       transaction.cmd = MMCSD_CMD(6U);
       transaction.arg = 0x03000000 | (MMCSD_ECSD_BUS_WIDTH_INDEX << 16) | (( (enhancedStrobe << MMCSD_ECSD_BUS_WIDTH_ES_SHIFT) | MMCSD_ECSD_BUS_WIDTH_8BIT_DDR) << 8);
       transaction.flags = MMCSD_CMDRSP_BUSY;
       ret = MMCSD_v2_transfer(handle, &transaction);

       Osal_delay(50);
       if(MMCSD_OK == ret) {
  	  	  /* Wait for DAT0 to go low */
          MMCSD_v2_waitDat0(hwAttrs);
       }

         /*Set the “Timing Interface” parameter in the HS_TIMING [185] field of the
         * Extended CSD register to 0x3 to switch to HS400 mode.
         */
        /* Send the Switch command to change the HS TIMINIG bit of the EXT_CSD[185]  */
        if(MMCSD_OK == ret)
        {
          transaction.cmd = MMCSD_CMD(6U);
          transaction.arg = 0x03000000 | (MMCSD_ECSD_HS_TIMING_INDEX << 16) | (( (enhancedStrobe <<4) | MMCSD_ECSD_HS_TIMING_HS400) << 8);
          transaction.flags = MMCSD_CMDRSP_BUSY;
          ret = MMCSD_v2_transfer(handle, &transaction);
        }
        Osal_delay(50);
        if(MMCSD_OK == ret) {
  		  /* Wait for DAT0 to go low */
          MMCSD_v2_waitDat0(hwAttrs);
	    }

        ret = HSMMCSDUhsModeSet(hwAttrs->baseAddr, MMC_AC12_UHSMS_HS400);

         if(enhancedStrobe)
         {
           HSMMCSDEnhancedStrobeSet(hwAttrs->baseAddr,MMC_VREG_STROBE_ENABLE);
		 }

        ret = HSMMCSDUhsDrvStrengthSet(hwAttrs->baseAddr, drvStrength_controller);

 	     MMCSD_socPhyDisableDLL(hwAttrs);


         /* Host may set the clock frequency to a value not greater than 200 MHz"*/
        ret = HSMMCSDBusFreqSet(hwAttrs->baseAddr, hwAttrs->inputClk, 200000000, 0U);

         /* NEW: Enable DLL */
        Osal_delay(50);
        phyMode = MODE_HS400;
        
        MMCSD_socPhyConfigure(hwAttrs,phyMode, 200000000, phyDriverType);

        
        if(ret!=STW_SOK) {
		  return MMCSD_ERR;
	    }
        Osal_delay(50);
	 }

     return (ret);

}

/*
 ***********************************************************************
 *  ======== Returns tuning status ========
 **********************************************************************/
static MMCSD_Error mmcsd_tuning_procedure(MMCSD_Handle handle) {

     MMCSD_v2_Object        *object = NULL;
     MMCSD_v2_HwAttrs const *hwAttrs = NULL;
     bool tuning_success = FALSE;
     uint32_t i;
     uint32_t state,samplingClock;

     /* Get the pointer to the object and hwAttrs */
     object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;
	 hwAttrs = (MMCSD_v2_HwAttrs const *)((MMCSD_Config *) handle)->hwAttrs;
     
     HSMMCSDCardTuningSet(hwAttrs->baseAddr,HS_MMCSD_EXEC_TUNING_ENABLE, HS_MMCSD_CLCK_SELECT_DISABLE);
	 /* Read the ET back until it is 1 */
	 {
		uint32_t state,samplingClock;
        do {
           HSMMCSDCardTuningGet(hwAttrs->baseAddr,&state, &samplingClock);
	    } while(state!=MMC_AC12_ET_EXECUTE);
     }
      for(i=0;i<40;i++)
     {

 	   /* Send CMD19 for SD card, CMD21 for eMMC */
       if(MMCSD_CARD_EMMC == object->cardType) {
	     mmcsd_send_tuning_eMMC(handle);
	   } else {
	     mmcsd_send_tuning(handle);
	   }
 	
   	   HSMMCSDCardTuningGet(hwAttrs->baseAddr,&state, &samplingClock);
	   if (state==MMC_AC12_ET_COMPLETED && samplingClock == MMC_AC12_SCLK_SEL_TUNED) 
	   {
		   /* Tuninig is succcessful. Return */
           tuning_success=TRUE;
           break;
	   }

    }

	if(!tuning_success) {
		MMCSD_DEBUG_TRAP
		HSMMCSDCardTuningSet(hwAttrs->baseAddr,HS_MMCSD_EXEC_TUNING_DISABLE, HS_MMCSD_CLCK_SELECT_DISABLE);
		return MMCSD_ERR;
	}


   HSMMCSDLinesReset(hwAttrs->baseAddr,HS_MMCSD_CMDLINE_RESET);
   HSMMCSDLinesReset(hwAttrs->baseAddr,HS_MMCSD_DATALINE_RESET);

	return MMCSD_OK;
}

/*
 *  ======== MMCSD_open ========
 */
static MMCSD_Error MMCSD_v2_initEmmc(MMCSD_Handle handle)
{
    MMCSD_Error                 ret = MMCSD_OK;
    uint32_t                    retry = 0xFFFFU;
    MMCSD_v2_Object            *object = NULL;
    MMCSD_v2_HwAttrs const     *hwAttrs = NULL;
    MMCSD_v2_Transaction        transaction;
    volatile int32_t            status = -1;
    uint32_t controller_buswidth = HS_MMCSD_BUS_WIDTH_1BIT;  /* Default */
    uint8_t ecsd_bus_with      = MMCSD_ECSD_BUS_WIDTH_1BIT; /* Default */

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;
    hwAttrs = (MMCSD_v2_HwAttrs const *)((MMCSD_Config *) handle)->hwAttrs;

    if(MMCSD_OK == ret)
    {
        /*
         * Refer to the MMC Host and Bus configuration ste/home/mahesh/ti/procsdk_keystone3_May7/pdk_am65xx_1_0_0/packages/ti/drv/mmcsdps in TRM
         * controller Reset
         */
        status = HSMMCSDSoftReset(hwAttrs->baseAddr);

        if (STW_SOK != status)
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
        status=HSMMCSDLinesReset(hwAttrs->baseAddr, HS_MMCSD_ALL_RESET);
        if(status!=STW_SOK) {
           MMCSD_DEBUG_TRAP
         }

        /* Set the bus width */
        status=HSMMCSDBusWidthSet(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_1BIT);
        if(status!=STW_SOK) {
           MMCSD_DEBUG_TRAP
         }

        /* Set the bus voltage */
        status=HSMMCSDBusVoltSet(hwAttrs->baseAddr, MMC_HCTL_SDVS_1V8);

        if(status!=STW_SOK) {
           MMCSD_DEBUG_TRAP
         }

   if(MMCSD_OK == ret)
   {
      uint32_t slotType,reg=0;
      slotType = CSL_MMC_CTLCFG_CAPABILITIES_SLOT_TYPE_VAL_EMBEDDED;

      reg = *(&(((CSL_mmc_sscfgRegs *)(hwAttrs->ssBaseAddr))->CTL_CFG_2_REG));
      reg = Bitfield_csl_set (reg, slotType,
                            CSL_MMC_SSCFG_CTL_CFG_2_REG_SLOTTYPE_MASK,
                            CSL_MMC_SSCFG_CTL_CFG_2_REG_SLOTTYPE_SHIFT);
       *(&(((CSL_mmc_sscfgRegs *)(hwAttrs->ssBaseAddr))->CTL_CFG_2_REG))=reg;
 
      //
      // Enable pins by setting the IO mux field in the phy to 0.
      //
      reg = *(&(((CSL_mmc_sscfgRegs *)(hwAttrs->ssBaseAddr))->PHY_CTRL_1_REG));
      reg = Bitfield_csl_set (reg, 0,
                            CSL_MMC_SSCFG_PHY_CTRL_1_REG_IOMUX_ENABLE_MASK,
                            CSL_MMC_SSCFG_PHY_CTRL_1_REG_IOMUX_ENABLE_SHIFT);
      *(&(((CSL_mmc_sscfgRegs *)(hwAttrs->ssBaseAddr))->PHY_CTRL_1_REG))=reg;

      //
      // Wait for card detect.
      //
       {
		   uint32_t ins=0;

	       do {
              ins = HSMMCSDIsCardInserted(hwAttrs->baseAddr);
           } while(ins==0);
       }
    }

        MMCSD_socPhyInit(hwAttrs);

        /* Bus power on */
        status = ((int32_t)(HSMMCSDBusPower(hwAttrs->baseAddr, MMC_HCTL_SDBP_PWRON)));
        if(status!=STW_SOK) {
           MMCSD_DEBUG_TRAP
         }

        if (STW_SOK != status)
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
        status = HSMMCSDBusFreqSet(hwAttrs->baseAddr, hwAttrs->inputClk,400000,FALSE);

        if (STW_SOK != status)
        {
#ifdef LOG_EN
        MMCSD_drv_log(Diags_USER1,
          "MMCSD:(%p) HS MMC/SD Bus Frequency set failed", hwAttrs->baseAddr);
#endif
            ret = MMCSD_ERR;
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
            ret = MMCSD_v2_transfer(handle, &transaction);
        }

        /* NOTE: Add delay */
        Osal_delay(50U);

        if(MMCSD_OK == ret)
        {
            stSDMMCHCCapability hcCapab={0,0,0,0};
            uint32_t hostOcr=0;
            #define MMC_VDD_27_33       				0x00FF8000U
            #define MMC_VDD_17_19       				0x00000080U
            #define SECTOR_MODE         				0x4U

      		//Reading the Capability Register
		    hcCapab.flag1 = HS_MMCSD_VOLT_3V3_SUPPORT;

	       HSMMCSDHostCapabilityGet(hwAttrs->baseAddr, &hcCapab);
	       if(hcCapab.retValue1)
	       {
	       	hostOcr |= MMC_VDD_27_33;
	       }

		   hcCapab.flag1 = HS_MMCSD_VOLT_3V0_SUPPORT;
	       HSMMCSDHostCapabilityGet(hwAttrs->baseAddr, &hcCapab);

	       if (hcCapab.retValue1)
	       {
		hostOcr |= MMC_VDD_27_33;
	       }
	       hostOcr |= MMC_VDD_17_19;

            /* Poll until we get the card status (BIT31 of OCR) is powered up */
            do
            {
                /* APP cmd should be preceeded by a CMD55 */
                transaction.cmd = MMCSD_CMD(1U);
                transaction.flags = MMCSD_CMDRSP_48BITS;
                // transaction.arg = 0xC0FF8080U;
                transaction.arg = ( (0x80000000) |  (SECTOR_MODE << 28U) | hostOcr );
                ret = MMCSD_v2_transfer(handle, &transaction);
                retry--;
            } while (((transaction.response[0U] & ((uint32_t)BIT(31U))) == 0U) && (retry != 0));

            if (0U == retry)
            {
                /* No point in continuing */
                ret = MMCSD_ERR;
            }
        }
  	    object->cmd23Supported = TRUE; /* MMC should always support CMD23 */

        if(MMCSD_OK == ret)
        {
            object->ocr = transaction.response[0U];

            object->highCap = (object->ocr & MMCSD_OCR_HIGH_CAPACITY) ? 1U : 0U;

            /* Send CMD2, to get the card identification register */
            transaction.cmd = MMCSD_CMD(2U);
            transaction.flags = MMCSD_CMDRSP_136BITS;
            transaction.arg = 0U;

            ret = MMCSD_v2_transfer(handle, &transaction);

            //  memcpy(object->cid, transaction.response, 16U);
            object->cid[3]= (transaction.response[3] << 8)| (transaction.response[2] >> 24);
            object->cid[2]= (transaction.response[2] << 8)| (transaction.response[1] >> 24);
            object->cid[1]= (transaction.response[1] << 8)| (transaction.response[0] >> 24);
            object->cid[0]= (transaction.response[0] << 8);
        }

        if(MMCSD_OK == ret)
        {
            object->rca = 2U;

            /* Send CMD3, to get the card relative address */
            transaction.cmd = MMCSD_CMD(3U);
            transaction.flags = 0U;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v2_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            /* Send CMD9, to get the card specific data */
            transaction.cmd = MMCSD_CMD(9U);
            transaction.flags = MMCSD_CMDRSP_136BITS;
            transaction.arg = object->rca << 16U;

            ret = MMCSD_v2_transfer(handle, &transaction);

            object->csd[3]= (transaction.response[3] << 8)| (transaction.response[2] >> 24);
            object->csd[2]= (transaction.response[2] << 8)| (transaction.response[1] >> 24);
            object->csd[1]= (transaction.response[1] << 8)| (transaction.response[0] >> 24);
            object->csd[0]= (transaction.response[0] << 8);
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

            ret = MMCSD_v2_transfer(handle, &transaction);
        }

        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(8U);
            transaction.flags = MMCSD_CMDRSP_READ | MMCSD_CMDRSP_DATA;
            transaction.arg = object->rca << 16U;
            transaction.blockCount = 1U;
            transaction.blockSize = 512U;
            transaction.dataBuf = object->ecsd;

            ret = MMCSD_v2_transfer(handle, &transaction);
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
          ret = MMCSD_v2_transfer(handle, &transaction);
        }
        object->busWidth = controller_buswidth;

        /* NOTE: Add delay */
        delay(100U);
        if (MMCSD_OK == ret)
        {
          HSMMCSDBusWidthSet(hwAttrs->baseAddr, controller_buswidth);
        }

        /* NOTE: Add delay */
        delay(100U);

        if(MMCSD_OK == ret)
        {
            transaction.cmd = MMCSD_CMD(6U);
            transaction.arg = 0x03A20100;
            transaction.flags = MMCSD_CMDRSP_BUSY;
            ret = MMCSD_v2_transfer(handle, &transaction);
        }

        /* NOTE: Add delay */
        delay(100U);
    }
#ifndef MMCSD_SUPPORT_MMC_HS400_DISABLED
    /* Read DEVICE_TYPE in the ECSD[196] to get the supported speeds */
    if( ( (hwAttrs->supportedModes & MMCSD_SUPPORT_MMC_HS400) || (hwAttrs->supportedModes & MMCSD_SUPPORT_MMC_HS400)) &&  (object->ecsd[MMCSD_EMMC_ECSD_DEVICE_TYPE_INDEX] & MMCSD_EMMC_ECSD_DEVICE_TYPE_HS400_200MHZ_1P8V))
    {

      if( (hwAttrs->supportedModes & MMCSD_SUPPORT_MMC_HS400_ES) && (object->ecsd[MMCSD_ECSD_STROBE_SUPPORT_INDEX] == MMCSD_ECSD_STROBE_SUPPORT_ENHANCED_EN) )
      {
         ret = MMCSD_switch_eMMC_mode(handle,MMCSD_SUPPORT_MMC_HS400_ES);
      }
      else if((hwAttrs->supportedModes & MMCSD_SUPPORT_MMC_HS400))
      {
         ret = MMCSD_switch_eMMC_mode(handle,MMCSD_SUPPORT_MMC_HS400);
	  }

      if(ret==MMCSD_OK) {
         object->tranSpeed=MMCSD_TRANSPEED_HS400;
       } else {
		   MMCSD_DEBUG_TRAP
	   }
	} /* Check for HS200 next */
	else
#endif
	if( (hwAttrs->supportedModes & MMCSD_SUPPORT_MMC_HS200) && (object->ecsd[MMCSD_EMMC_ECSD_DEVICE_TYPE_INDEX] & MMCSD_EMMC_ECSD_DEVICE_TYPE_HS200_200MHZ_1P8V))
    {
         ret = MMCSD_switch_eMMC_mode(handle,MMCSD_SUPPORT_MMC_HS200);
         if(ret==MMCSD_OK) {
         object->tranSpeed=MMCSD_TRANSPEED_HS200;
         } else {
		   MMCSD_DEBUG_TRAP
	     }
	} /* Check for HS-DDR next */
	else if ( (hwAttrs->supportedModes & MMCSD_SUPPORT_MMC_HS_DDR) && (object->ecsd[MMCSD_EMMC_ECSD_DEVICE_TYPE_INDEX] & MMCSD_EMMC_ECSD_DEVICE_TYPE_HS_DDR_52MHZ_1P8V))
	{
         ret = MMCSD_switch_eMMC_mode(handle,MMCSD_SUPPORT_MMC_HS_DDR);
         if(ret==MMCSD_OK) {
         object->tranSpeed=MMCSD_TRANSPEED_DDR50;
         } else {
		   MMCSD_DEBUG_TRAP
	     }
	}
	else if ( (hwAttrs->supportedModes & MMCSD_SUPPORT_MMC_HS_SDR) && (object->ecsd[MMCSD_EMMC_ECSD_DEVICE_TYPE_INDEX] & MMCSD_EMMC_ECSD_DEVICE_TYPE_HS_52MHZ))
	{
         ret = MMCSD_switch_eMMC_mode(handle,MMCSD_SUPPORT_MMC_HS_SDR);
         if(ret==MMCSD_OK) {
         object->tranSpeed=MMCSD_TRANSPEED_DDR50;
         } else {
		   MMCSD_DEBUG_TRAP
	     }
	} 	else if (hwAttrs->supportedModes & MMCSD_SUPPORT_MMC_DS)
	{
       ret = MMCSD_switch_eMMC_mode(handle,MMCSD_SUPPORT_MMC_DS);
       if(ret==MMCSD_OK) {
         object->tranSpeed=MMCSD_TRANSPEED_SDR25;
       } else {
		 MMCSD_DEBUG_TRAP
	   }
	 }


    if(MMCSD_OK != ret)
    {
        MMCSD_v2_close(handle);
    }

    return (ret);
}
/*
 *  ======== MMCSD_v2_transfer ========
 */
static MMCSD_Error MMCSD_v2_transfer(MMCSD_Handle handle,
                                     MMCSD_v2_Transaction *transaction)
{
    MMCSD_Error             ret = MMCSD_ERR;
    hsMmcsdCmdObj_t         cmdObj = {{0U, 0U, 0U, 0U}, 0U, 0U, 0U, 0U};
    MMCSD_v2_Object        *object = NULL;
    MMCSD_v2_HwAttrs const *hwAttrs = NULL;
    uint32_t params;

    if ((handle != NULL) && (transaction != NULL))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;
        hwAttrs = (MMCSD_v2_HwAttrs const *)((MMCSD_Config *) handle)->hwAttrs;

        ret = MMCSD_OK;

        if(hwAttrs->enableInterrupt==1) {
          /* Check the semaphre counts */
          int32_t count;
          count = SemaphoreP_getCount(object->commandComplete);
          if(count != 0U) {
              MMCSD_osalPendLock(object->commandComplete, SemaphoreP_WAIT_FOREVER);
          }
        }
    }

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
			HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFWRRDY);
            HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFRDRDY);
            HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_TRNFCOMP);

        } else {
			HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_SIGEN_ALL);
		}

        object->cmdComp = 0;
        object->cmdTimeout = 0;
        object->cmdCRCError = 0;
		object->cmdIndexError = 0;
		object->cmdEBError = 0;
        object->dataCRCError = 0;
		object->dataEBError = 0;
		object->cmdError = 0;
		object->xferInProgress = 0;
        object->xferComp = 0;
        object->xferTimeout = 0;

		
		if (0 != cmdObj.enableData)
        {

			   /* Acquire the lock for this particular MMCSD handle */
            MMCSD_osalPendLock(object->transferMutex, SemaphoreP_WAIT_FOREVER);
            MMCSD_osalPendLock(object->commandMutex, SemaphoreP_WAIT_FOREVER);

            /*  MMCSD_osalHardwareIntrDisable(hwAttrs->intNum); */

            object->dataBufIdx = (uint8_t*)transaction->dataBuf;


            object->dataBlockCount = transaction->blockCount;
            object->dataBlockSize = transaction->blockSize;
			

cmdObj.cmd.xferType = (transaction->flags & MMCSD_CMDRSP_READ) ? \
                HS_MMCSD_XFER_TYPE_RX : HS_MMCSD_XFER_TYPE_TX;
            cmdObj.numBlks = (TRUE == cmdObj.enableData) ? object->dataBlockCount : 0U;
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr, HS_MMCSD_INTR_TRNFCOMP);

            if (HS_MMCSD_XFER_TYPE_RX == cmdObj.cmd.xferType)
            {
                /* Configure the transfer for read operation */
                HSMMCSDIntrStatusClear(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFRDRDY);
                HSMMCSDIntrStatusEnable(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFRDRDY);
                HSMMCSDIntrStatusDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFWRRDY);

				object->readBlockCount=object->dataBlockCount;
            }
            else
            {
                /* Configure the transfer for write operation */
                HSMMCSDIntrStatusClear(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFWRRDY);
                HSMMCSDIntrStatusEnable(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFWRRDY);
                HSMMCSDIntrStatusDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFRDRDY);

                if(0U != hwAttrs->enableInterrupt)
                {
					HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFWRRDY);
                    HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFRDRDY);
                    HSMMCSDIntrDisable(hwAttrs->baseAddr, HS_MMCSD_INTR_TRNFCOMP);

                }
				object->writeBlockCount=object->dataBlockCount;
            }

            HSMMCSDBlkLenSet(hwAttrs->baseAddr, transaction->blockSize);

            HSMMCSDIntrStatusClear(hwAttrs->baseAddr, HS_MMCSD_INTR_TRNFCOMP);
            HSMMCSDDataTimeoutSet(hwAttrs->baseAddr, MMC_SYSCTL_DTO_15THDTO);

            HSMMCSDIntrStatusEnable(hwAttrs->baseAddr,
                (HS_MMCSD_INTR_CMDCOMP | HS_MMCSD_INTR_CMDTIMEOUT |
                 HS_MMCSD_INTR_DATATIMEOUT | HS_MMCSD_INTR_TRNFCOMP | 0x17ff0000));

            if(0U != hwAttrs->enableInterrupt)
            {
			   HSMMCSDIntrEnable(hwAttrs->baseAddr,
                    (HS_MMCSD_INTR_CMDCOMP | HS_MMCSD_INTR_CMDTIMEOUT |
                     HS_MMCSD_INTR_DATATIMEOUT));

			}

            cmdObj.cmd.cmdId = transaction->cmd;
            cmdObj.cmdArg = transaction->arg;

            MMCSD_osalCache_wbInv(object->dataBufIdx,(transaction->blockSize * transaction->blockCount));

            if(hwAttrs->enableDma)
            {
                /* Setup the adma descriptor */

                /* Lower16 bits of the size  in bits 16-32 */
                params = (transaction->blockCount * transaction->blockSize) << 16;
                /* Upper bits of size is in bits 6-16, followed by the ADMA transfer flags (bits 0-5)   */
                params= params | ((((transaction->blockCount * transaction->blockSize) >>16) <<6) | 0x0023);
                /* VER4 is enabled for 26 bit sizes */
                HSMMCSDHostVer4Select(hwAttrs->baseAddr, MMC_AC12_HOSTVER4_ENABLE);
                HSMMCSDAdmaLengthSelect(hwAttrs->baseAddr, MMC_ADMA2_LENGTH_MODE_26BIT);


                mmc_setupDescriptor(&adma2_desc,  ///< pointer to descriptor head, NOT pointer to the address value within the decriptor.
                                    params,     ///< parameters for descriptor.
                   (uint64_t)transaction->dataBuf); ///< physical address to pack into the descriptor.

                HSMMCSDDmaSelect(hwAttrs->baseAddr, MMC_HCTL_DMAS_ADMA2_32BIT);


                /* Write the descriptor address to ADMA2 address */
                HSMMCSDAdmaAddressSet(hwAttrs->baseAddr,(((uint64_t)&adma2_desc)&0xffffffff),(((uint64_t)&adma2_desc) >> 32));

                MMCSD_osalCache_wbInv(&adma2_desc,sizeof(adma2_desc));

                cmdObj.enableDma = 1U;
            } else
            {
                cmdObj.enableDma = 0U;
            }
		    /* Wait for command and data inhibit to go low before
		     * commands can be issued */
		
	        MMCSD_v2_waitCmdInhibit(hwAttrs);
            MMCSD_v2_waitDatInhibit(hwAttrs);
 
            if(0U != hwAttrs->enableInterrupt)
            {
               if (HS_MMCSD_XFER_TYPE_RX == cmdObj.cmd.xferType)   
			   {
                   HSMMCSDIntrEnable(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFRDRDY);
               } 
			    else 
			   {
                   HSMMCSDIntrEnable(hwAttrs->baseAddr, HS_MMCSD_INTR_BUFWRRDY);
               }
 		       HSMMCSDIntrEnable(hwAttrs->baseAddr, HS_MMCSD_INTR_TRNFCOMP);
            }

            HSMMCSDCommandSend(hwAttrs->baseAddr,
                               HS_MMCSD_CMD(cmdObj.cmd.cmdId, cmdObj.cmd.cmdType, cmdObj.cmd.rspType, cmdObj.cmd.xferType),
                               cmdObj.cmdArg,
                               (TRUE == cmdObj.enableData)?MMC_CMD_DP_DATA:MMC_CMD_DP_NODATA,
                               cmdObj.numBlks,
                               cmdObj.enableDma,
                               MMC_CMD_ACEN_DISABLE);
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

  		    if((object->manualTuning==FALSE) &&    ((cmdObj.cmd.cmdId==MMCSD_CMD(19U)) || (cmdObj.cmd.cmdId==MMCSD_CMD(21U)))    ) 
		    {
			   object->cmdComp=1;	
		    }     
		    else 
	   	    {
 		       if(0U != hwAttrs->enableInterrupt)
               {
			      MMCSD_osalPendLock(object->commandComplete, SemaphoreP_WAIT_FOREVER);
               }
	           else
               {
                    while ( (0 == object->cmdComp) && (0==object->cmdError) )
                    {
                        MMCSD_v2_cmdStatusFxn((uintptr_t) handle);
                    }
                }
            }
            	
#ifdef LOG_EN
            MMCSD_drv_log4(Diags_USER1,
                       "MMCSD:(%p) Command transaction completed", hwAttrs->baseAddr);
#endif


            if( object->manualTuning && object->cmdError && ( (cmdObj.cmd.cmdId==MMCSD_CMD(19U)) || (cmdObj.cmd.cmdId==MMCSD_CMD(21U)) ) )  
		    {				   
               HSMMCSDLinesReset(hwAttrs->baseAddr,HS_MMCSD_CMDLINE_RESET);
               HSMMCSDLinesReset(hwAttrs->baseAddr,HS_MMCSD_DATALINE_RESET);
			   ret=MMCSD_ERR_TUNING_CMD_ERROR;
		    }
            else
		    {	
		     /* Command execution fail */
                if (1 == object->cmdTimeout)
                {
                    ret = MMCSD_ERR;
                    object->cmdTimeout = 0;
                    MMCSD_DEBUG_TRAP
                }


               /* Command execution fail */
               if (1 == object->cmdCRCError)
               {
                   ret = MMCSD_ERR;
                   object->cmdCRCError = 0;
                   MMCSD_DEBUG_TRAP
               }
            }
            
			/* Command execution successful */
            if (1 == object->cmdComp)
            {
                ret = MMCSD_OK;
                object->cmdComp = 0;

                if(0==hwAttrs->enableInterrupt) 
			    {
                   object->xferInProgress = 1;
                }

                if(1 == hwAttrs->enableInterrupt) 
			    {

#ifdef SEMAPHORE_EMUWAITS
			       while(dataBufferCopyComplete_emuwait);
#endif
			       MMCSD_osalPendLock(object->dataBufferCopyComplete, SemaphoreP_WAIT_FOREVER);

			    }

                /* Git response for command sent to MMC device */
                HSMMCSDResponseGet(hwAttrs->baseAddr, transaction->response);
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
			    if(0U != hwAttrs->enableInterrupt)
                {
			       MMCSD_osalPendLock(object->transferComplete, SemaphoreP_WAIT_FOREVER);
                }
                else
                {
                    if( (object->manualTuning==FALSE) && ( (cmdObj.cmd.cmdId==MMCSD_CMD(19U)) || (cmdObj.cmd.cmdId==MMCSD_CMD(21U)) ) )
			        {
				       while ((0 == object->xferComp) && (0 == object->xferTimeout))
                       {
                           MMCSD_v2_xferStatusFxn_CMD19((uintptr_t) handle);
                       }

				    }
			        else
				    {

				      while (  (0 == object->cmdError) 
						    && (0 == object->xferComp) 
						    && (0 == object->xferTimeout) 
							&& (0 == object->dataCRCError) 
							&& (0 == object->dataEBError) )
                      {
                        MMCSD_v2_xferStatusFxn((uintptr_t) handle);
                      }

				    }
			    }

            }
#ifdef LOG_EN
                MMCSD_drv_log(Diags_USER1,
                           "MMCSD:(%p) Data transaction completed", hwAttrs->baseAddr);
#endif

            if( object->manualTuning && object->cmdError && ( (cmdObj.cmd.cmdId==MMCSD_CMD(19U)) || (cmdObj.cmd.cmdId==MMCSD_CMD(21U)) ) )  
		    {				   
               /* In case of manual tuning, any of these errors could mean that the CMD lines & data lines are reset and move on to the next 
			      tuning sequence */
			    HSMMCSDLinesReset(hwAttrs->baseAddr,HS_MMCSD_CMDLINE_RESET);
                HSMMCSDLinesReset(hwAttrs->baseAddr,HS_MMCSD_DATALINE_RESET);
                ret=MMCSD_ERR_TUNING_CMD_ERROR;

   		    }
		    else 
		    { /* Data transfer successful */
                if (1 == object->xferTimeout)
                {
                   ret = MMCSD_ERR;
                   MMCSD_DEBUG_TRAP
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
            object->cmdError = 0;
			object->cmdCRCError = 0;
			
            cmdObj.cmd.cmdId = transaction->cmd;
            cmdObj.cmdArg = transaction->arg;
            cmdObj.enableDma = 0;

            HSMMCSDIntrStatusEnable(hwAttrs->baseAddr,
                (HS_MMCSD_INTR_CMDCOMP | HS_MMCSD_INTR_CMDTIMEOUT));

            if(0U != hwAttrs->enableInterrupt)
            {
                HSMMCSDIntrEnable(hwAttrs->baseAddr,
                    (HS_MMCSD_INTR_CMDCOMP | HS_MMCSD_INTR_CMDTIMEOUT));
            }
            else
            {
			   HSMMCSDIntrEnable(hwAttrs->baseAddr, ~(HS_MMCSD_SIGEN_ALL));
		    }

		   /* Wait for command and data inhibit to go low before
		    * commands can be issued */
		    MMCSD_v2_waitCmdInhibit(hwAttrs);

            HSMMCSDCommandSend(hwAttrs->baseAddr,
                               HS_MMCSD_CMD(cmdObj.cmd.cmdId, cmdObj.cmd.cmdType, cmdObj.cmd.rspType, cmdObj.cmd.xferType),
                               cmdObj.cmdArg,
                               (TRUE == cmdObj.enableData)?MMC_CMD_DP_DATA:MMC_CMD_DP_NODATA,
                               cmdObj.numBlks,
                               cmdObj.enableDma,
                               MMC_CMD_ACEN_DISABLE);
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
                    MMCSD_v2_cmdStatusFxn((uintptr_t) handle);
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
            HSMMCSDResponseGet(hwAttrs->baseAddr, transaction->response);

            /* Release the lock for this particular MMCSD handle */
            MMCSD_osalPostLock(object->commandMutex);
        }
    
    }
    /* Return the transaction status */
    return (ret);
}

/*
 *  ======== MMCSD_v2_control ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v2_control(MMCSD_Handle handle, uint32_t cmd, const void *arg)
{
    MMCSD_Error        ret = MMCSD_ERR;

    /* Input parameter validation */
    if (handle != NULL)
    {
        switch (cmd)
        {
            case MMCSD_CMD_SETBUSWIDTH:
            {
                ret = MMCSD_v2_setBusWidth(handle, (const uint32_t *)arg);
                break;
            }

            case MMCSD_CMD_SETFREQUENCY:
            {
                ret = MMCSD_v2_setBusFreq(handle, (const uint32_t *)arg);
                break;
            }

            case MMCSD_CMD_GETBUSWIDTH:
            {
                ret = MMCSD_v2_getBusWidth(handle, (uint32_t *)arg);
                break;
            }

            case MMCSD_CMD_GETFREQUENCY:
            {
                ret = MMCSD_v2_getBusFreq(handle, (uint32_t *)arg);
                break;
            }

            case MMCSD_CMD_GETMEDIAPARAMS:
            {
                ret = MMCSD_v2_getMediaParams(handle, (MMCSD_mediaParams *)arg);
                break;
            }

            case MMCSD_CMD_ENABLEBOOTPARTITION:
            {
                ret = MMCSD_v2_enableBootPartition(handle, (const uint8_t *)arg);
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
 *  ======== MMCSD_v2_setBusWidth ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v2_setBusWidth(MMCSD_Handle handle, const uint32_t *busWidth)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v2_Object            *object = NULL;
    MMCSD_v2_HwAttrs const     *hwAttrs = NULL;
    MMCSD_v2_Transaction        transaction;

    /* Input parameter validation */
    if ((handle != NULL) && (busWidth != NULL))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;
        hwAttrs = (MMCSD_v2_HwAttrs const *)((MMCSD_Config *) handle)->hwAttrs;

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
                ret = MMCSD_v2_transfer(handle, &transaction);
            }

            if(MMCSD_OK == ret)
            {
                transaction.cmd = MMCSD_CMD(6U);
                transaction.arg = MMCSD_BUS_WIDTH_1BIT;
                transaction.flags = 0U;

                if (hwAttrs->supportedBusWidth & MMCSD_BUS_WIDTH_4BIT)
                {
                    if (MMCSD_BUS_WIDTH_4BIT == *busWidth)
                    {
                        transaction.arg = MMCSD_BUS_WIDTH_4BIT;
                    }
                }

                transaction.arg = transaction.arg >> 1U;
                ret = MMCSD_v2_transfer(handle, &transaction);

                if (MMCSD_OK == ret)
                {
                    if (MMCSD_BUS_WIDTH_4BIT == *busWidth)
                    {
                        object->busWidth = MMCSD_BUS_WIDTH_4BIT;
                        HSMMCSDBusWidthSet(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_4BIT);
                    }
                    else
                    {
                        object->busWidth = MMCSD_BUS_WIDTH_1BIT;
                        HSMMCSDBusWidthSet(hwAttrs->baseAddr, HS_MMCSD_BUS_WIDTH_1BIT);
                    }
                }
            }
        }
    }
    return(ret);
}

/*
 *  ======== MMCSD_v2_setBusFreq ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v2_setBusFreq(MMCSD_Handle handle, const uint32_t *busFreq)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v2_Object            *object = NULL;
	uint32_t cmd16_grp1_fn;

    /* Input parameter validation */
    if ((handle != NULL) && (busFreq != NULL))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;

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
    return(ret);
}

/*
 *  ======== MMCSD_v2_getBusWidth ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v2_getBusWidth(MMCSD_Handle handle, uint32_t *busWidth)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v2_Object            *object = NULL;

    /* Input parameter validation */
    if ((handle != NULL) && (busWidth != NULL))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;

        if (MMCSD_CARD_SD == object->cardType)
        {
            *busWidth = object->busWidth;
            ret = MMCSD_OK;
        }
    }

    return(ret);
}

/*
 *  ======== MMCSD_v2_getBusFreq ========
 */
/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              MMCSD_control().
 */
static MMCSD_Error MMCSD_v2_getBusFreq(MMCSD_Handle handle, uint32_t *busFreq)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v2_Object            *object = NULL;

    /* Input parameter validation */
    if ((handle != NULL) && (busFreq != NULL))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;

        if (MMCSD_CARD_SD == object->cardType)
        {
            *busFreq = object->tranSpeed;
            ret = MMCSD_OK;
        }
    }
    return(ret);
}


/*
 *  ======== MMCSD_v2_getMediaParams ========
 */
/*!
 *  @brief      This function returns the media (SD/eMMC/MMC)'s parameters
 *              such as size, blockCount and blockSize  .
 */
static MMCSD_Error MMCSD_v2_getMediaParams(MMCSD_Handle handle, MMCSD_mediaParams *params)
{
    MMCSD_Error                 ret = MMCSD_ERR;
    MMCSD_v2_Object            *object = NULL;

    /* Input parameter validation */
    if ((handle != NULL) && (params != NULL))
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object *)((MMCSD_Config *) handle)->object;

        params->blockSize = object->blockSize;
        params->blockCount = object->blockCount;
        params->size = object->size;

        ret = MMCSD_OK;
    }
    return(ret);
}

/*
 *  ======== MMCSD_v2_hwiFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */
void MMCSD_v2_hwiFxn(uintptr_t arg)
{
    int32_t                 err = STW_SOK;
    uint32_t                errStatus;
    uint32_t                dataLen = 0U;
    uint32_t                status = 0U;
    volatile uint32_t       intrMask = 0U;
    uint32_t                temp = 0U;
    volatile uint32_t       cnt = 0U;
    MMCSD_v2_Object        *object = NULL;
    MMCSD_v2_HwAttrs const *hwAttrs = NULL;
    uint32_t                blocks_remaining,offset;
    uint32_t                retFlag = FALSE;

    /* Input parameter validation */
    if ((void *)arg == NULL)
    {
        retFlag = TRUE;
    }
    else
    {
        /* Get the pointer to the object and hwAttrs */
        object = (MMCSD_v2_Object*)(((MMCSD_Config *)arg)->object);
        hwAttrs = (MMCSD_v2_HwAttrs const *)(((MMCSD_Config *)arg)->hwAttrs);

        // status = HSMMCSDIntrStatus(hwAttrs->baseAddr);
        err = HSMMCSDIntrStatusGet(hwAttrs->baseAddr, HS_MMCSD_INTR_ALL, &status);
        if(err != STW_SOK)
        {
            retFlag = TRUE;
        }
        else
        {
            errStatus = status & 0xFFFF0000U;
            intrMask = HSMMCSDIntrGet(hwAttrs->baseAddr);
        }
    }

    /* Command execution is complete */
    if ((retFlag == FALSE) &&
        ((status & HS_MMCSD_INTR_CMDCOMP) != 0U))
    {
        HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_CMDCOMP);
        object->cmdComp = 1;

		/* Indicate command complete */
        if (intrMask & HS_MMCSD_SIGEN_CMDCOMP)
        {
			MMCSD_osalPostLock(object->commandComplete);
        }

    }    /* Error occurred in execution of command */

    if ((retFlag == FALSE) && (errStatus != 0U))
    {


        if (errStatus & HS_MMCSD_INTR_CMDTIMEOUT)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                       HS_MMCSD_INTR_CMDTIMEOUT);
            object->cmdTimeout = 1;

			/* Indicate command complete */
            if (intrMask & HS_MMCSD_SIGEN_CMDTIMEOUT)
            {
                MMCSD_osalPostLock(object->commandComplete);
            }
        }

    }

    /* Read data received from card */
    if ((retFlag == FALSE)                           &&
        ((status & HS_MMCSD_INTR_BUFRDRDY) != 0U)    &&
        ((intrMask & HS_MMCSD_INTR_BUFRDRDY) != 0U))
    {

    	HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                               HS_MMCSD_INTR_BUFRDRDY);

        if (object->dataBufIdx != NULL && object->readBlockCount)
        {
		object->xferInProgress=1;
            dataLen=object->dataBlockSize;
			blocks_remaining=object->readBlockCount;
            offset=(object->dataBlockCount-blocks_remaining)*object->dataBlockSize;
            for (cnt = 0U; cnt < dataLen; cnt += 4U)
            {
			    HSMMCSDDataGet(hwAttrs->baseAddr, (uint8_t *)&temp, 4U);
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
    if ((retFlag == FALSE)                        &&
        ((status & HS_MMCSD_INTR_BUFWRRDY) != 0U) &&
        ((intrMask & HS_MMCSD_INTR_BUFWRRDY) != 0U))
    {
        HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                               HS_MMCSD_INTR_BUFWRRDY);


		if (object->dataBufIdx != NULL && object->writeBlockCount)
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
                // HW_WR_REG32((hwAttrs->baseAddr + CSL_MMCHS_DATA), temp);
                   HSMMCSDDataSet(hwAttrs->baseAddr,(uint8_t *)&temp,4);

            }
			object->writeBlockCount--;
           if (object->writeBlockCount==0)
           {
		       MMCSD_osalPostLock(object->dataBufferCopyComplete);
           }

        }
    }

    /* Data transfer is complete */
    if ((retFlag == FALSE)                        &&
        ((status & HS_MMCSD_INTR_TRNFCOMP) != 0U) &&
        ((intrMask & HS_MMCSD_INTR_TRNFCOMP) != 0U))
    {
        if((1 == object->xferInProgress) ||  (hwAttrs->enableDma==1))
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_TRNFCOMP);
            object->xferComp = 1;
            object->xferInProgress = 0;
            if (hwAttrs->enableDma==1)
            {
                MMCSD_osalPostLock(object->dataBufferCopyComplete);
            }

            /* Indicate transfer complete */
            if (intrMask & HS_MMCSD_INTR_TRNFCOMP)
            {
				MMCSD_osalPostLock(object->transferComplete);
            }
        }
    }

    /* Error occurred in data transfer */
    if ((retFlag == FALSE)                           &&
        ((status & HS_MMCSD_INTR_DATATIMEOUT) != 0U) &&
        ((status & HS_MMCSD_INTR_TRNFCOMP) == 0U))
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_DATATIMEOUT);
            object->xferTimeout = 1;
            object->xferInProgress = 0;

            /* Indicate transfer complete */
            if (intrMask & HS_MMCSD_SIGEN_DATATIMEOUT)
            {
                MMCSD_osalPostLock(object->transferComplete);
            }

        }
    }
    return;
}

/*
 *  ======== MMCSD_v2_cmdStatusFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */
static void MMCSD_v2_cmdStatusFxn(uintptr_t arg)
{
    int32_t err = STW_SOK;
    volatile uint32_t        errStatus;
    uint32_t        status = 0U;
    MMCSD_v2_Object         *object = NULL;
    MMCSD_v2_HwAttrs const  *hwAttrs = NULL;

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v2_Object*)(((MMCSD_Config *)arg)->object);
    hwAttrs = (MMCSD_v2_HwAttrs const *)(((MMCSD_Config *)arg)->hwAttrs);

    // status = HSMMCSDIntrStatus(hwAttrs->baseAddr);
    err = HSMMCSDIntrStatusGet(hwAttrs->baseAddr, HS_MMCSD_INTR_ALL, &status);
	if(err != STW_SOK)
	{
	   return;
	}

    /* Command execution is complete */
    if (status & HS_MMCSD_INTR_CMDCOMP)
    {
        HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_CMDCOMP);
        object->cmdComp = 1;
    }

    /* Error occurred in execution of command */
    errStatus = status & 0xFFFF0000U;
    if (errStatus)
    {
        
		object->cmdError = 1;
		
		if (errStatus & HS_MMCSD_INTR_CMDTIMEOUT)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                       HS_MMCSD_INTR_CMDTIMEOUT);
            object->cmdTimeout = 1;
        }
        if (errStatus & HS_MMCSD_INTR_CMDCRCERR)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                       HS_MMCSD_INTR_CMDCRCERR);
            object->cmdCRCError = 1;
        }

        if (errStatus & HS_MMCSD_INTR_CMDINDXERR)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                       HS_MMCSD_INTR_CMDINDXERR);
            object->cmdIndexError = 1;
        }

        if (errStatus & HS_MMCSD_INTR_CMDBITERR)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                       HS_MMCSD_INTR_CMDBITERR);
            object->cmdEBError = 1;
        }
		
    }

    return;
}
/*
 *  ======== MMCSD_v2_xferStatusFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */
static void MMCSD_v2_xferStatusFxn(uintptr_t arg)
{
    int32_t err = STW_SOK;
    volatile uint32_t        dataLen = 0U;
    uint32_t                 status = 0U;
    uint32_t                 temp = 0U;
    volatile uint32_t        cnt = 0U;
    MMCSD_v2_Object         *object = NULL;
    MMCSD_v2_HwAttrs const  *hwAttrs = NULL;
    uint32_t blocks_remaining,offset;
    volatile uint32_t errStatus=0;

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v2_Object*)(((MMCSD_Config *)arg)->object);
    hwAttrs = (MMCSD_v2_HwAttrs const *)(((MMCSD_Config *)arg)->hwAttrs);

    // status = HSMMCSDIntrStatus(hwAttrs->baseAddr);
    err = HSMMCSDIntrStatusGet(hwAttrs->baseAddr, HS_MMCSD_INTR_ALL, &status);
	/* Error occurred in execution of command */
    errStatus = status & 0xFFFF0000U;
	if(err != STW_SOK)
	{
	   return;
	}

    /* Read data received from card */
    if (status & HS_MMCSD_INTR_BUFRDRDY)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_BUFRDRDY);

            if (object->dataBufIdx != NULL && object->readBlockCount)
            {
                dataLen=object->dataBlockSize;
				blocks_remaining=object->readBlockCount;
				offset=(object->dataBlockCount-blocks_remaining)*object->dataBlockSize;

                for (cnt = 0U; cnt < dataLen; cnt += 4U)
                {
                    HSMMCSDDataGet(hwAttrs->baseAddr, (uint8_t *)&temp, 4U);
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
    if (status & HS_MMCSD_INTR_BUFWRRDY)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_BUFWRRDY);

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
                     HW_WR_REG32((hwAttrs->baseAddr + MMC_DATA), temp);

                     //HSMMCSDDataSet(hwAttrs->baseAddr,(uint8_t *)&temp,4);
                }
				object->writeBlockCount--;
            }
        }
    }


    /* Data transfer is complete */
    if (status & HS_MMCSD_INTR_TRNFCOMP)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_TRNFCOMP);
            object->xferComp = 1;
            object->xferInProgress = 0;
        }
    }

	
    /* Error occurred in execution of command */
    errStatus = status & 0xFFFF0000U;
    if (errStatus)
    {
       object->cmdError=TRUE;
	}
	
    if (status & HS_MMCSD_INTR_DATACRCERR)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_DATACRCERR);
            object->dataCRCError = 1;
            object->xferInProgress = 0;
        }
    }

	if (status & HS_MMCSD_INTR_DATABITERR)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_DATABITERR);
            object->dataEBError = 1;
            object->xferInProgress = 0;
        }
    }

	
        /* Error occurred in data transfer */
    if (status & HS_MMCSD_INTR_DATATIMEOUT && !(status & HS_MMCSD_INTR_TRNFCOMP))
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_DATATIMEOUT);
            object->xferTimeout = 1;
            object->xferInProgress = 0;
        }
    }

    return;
}

/*
 *  ======== MMCSD_v2_xferStatusFxn ========
 *  Hwi interrupt handler to service the MMCSD peripheral
 *
 *  The handler is a generic handler for a MMCSD object.
 */

static void MMCSD_v2_xferStatusFxn_CMD19(uintptr_t arg)
{
    int32_t err = STW_SOK;
    volatile uint32_t        dataLen = 0U;
    uint32_t                 status = 0U;
    uint32_t                 temp = 0U;
    volatile uint32_t        cnt = 0U;
    MMCSD_v2_Object         *object = NULL;
    MMCSD_v2_HwAttrs const  *hwAttrs = NULL;

    /* Get the pointer to the object and hwAttrs */
    object = (MMCSD_v2_Object*)(((MMCSD_Config *)arg)->object);
    hwAttrs = (MMCSD_v2_HwAttrs const *)(((MMCSD_Config *)arg)->hwAttrs);

    // status = HSMMCSDIntrStatus(hwAttrs->baseAddr);
    err = HSMMCSDIntrStatusGet(hwAttrs->baseAddr, HS_MMCSD_INTR_ALL, &status);
	if(err != STW_SOK)
	{
	   return;
	}

    /* Read data received from card */
    if (status & HS_MMCSD_INTR_BUFRDRDY)
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_BUFRDRDY);

            if (object->dataBufIdx != NULL)
            {
                dataLen = object->dataBlockCount * object->dataBlockSize;

                for (cnt = 0U; cnt < dataLen; cnt += 4U)
                {
                    HSMMCSDDataGet(hwAttrs->baseAddr, (uint8_t *)&temp, 4U);
                    object->dataBufIdx[cnt] = *((uint8_t*)&temp);
                    object->dataBufIdx[cnt + 1U] = *((uint8_t*)&temp + 1U);
                    object->dataBufIdx[cnt + 2U] = *((uint8_t*)&temp + 2U);
                    object->dataBufIdx[cnt + 3U] = *((uint8_t*)&temp + 3U);
                }
            }
			HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
            HS_MMCSD_INTR_TRNFCOMP);
            object->xferComp = 1;
            object->xferInProgress = 0;
        }
    }
    /* Error occurred in data transfer */
    if (status & HS_MMCSD_INTR_DATATIMEOUT && !(status & HS_MMCSD_INTR_TRNFCOMP))
    {
        if(1 == object->xferInProgress)
        {
            HSMMCSDIntrStatusClear(hwAttrs->baseAddr,
                                   HS_MMCSD_INTR_DATATIMEOUT);
            object->xferTimeout = 1;
            object->xferInProgress = 0;
        }
    }

    /* Data transfer is complete */

    return;
}

/**
 * \brief  This API gets the SoC level of MMCSD intial configuration
 *
 * \param  index     MMC instance index.
 * \param  cfg       Pointer to MMCSD SOC initial config.
 *
 * \return 0 success: -1: error
 *
 */
int32_t MMCSD_socGetInitCfg(uint32_t index, MMCSD_v2_HwAttrs *cfg)
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
int32_t MMCSD_socSetInitCfg(uint32_t index, const MMCSD_v2_HwAttrs *cfg)
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


