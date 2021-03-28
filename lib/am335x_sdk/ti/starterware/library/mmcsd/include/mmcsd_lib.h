/**
 *  \file  mmcsd_lib.h
 *
 * \brief  This file contains the protocol implementation required to communicate
 *         with card (MMC/SD)
 *
 *  \copyright Copyright (C) 2013 - 2019 Texas Instruments Incorporated -
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

#ifndef MMCSDLIB_H_
#define MMCSDLIB_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdint.h>
#include "error.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief Bit mask. */
#define BIT(x) (1U << (x))

/**
 * SD Card information structure
 */

/** \brief Determines the type of card is SD. */
#define MMCSD_LIB_CARD_SD              (0U)

/** \brief Determines the type of card is MMC. */
#define MMCSD_LIB_CARD_MMC             (1U)

/** \brief SD Commands enumeration. */
#define MMCSD_LIB_CMD(x)   (x)

/**
 * Command/Response flags for notifying some information to controller
 */

/** \brief To indicate no response. */
#define MMCSD_LIB_CMDRSP_NONE           BIT(0U)

/** \brief Response to indicate stop condition. */
#define MMCSD_LIB_CMDRSP_STOP           BIT(1U)

/** \brief Response to indicate stop condition. */
#define MMCSD_LIB_CMDRSP_FS             BIT(2U)

/** \brief Response to indicate abort condition. */
#define MMCSD_LIB_CMDRSP_ABORT          BIT(3U)

/** \brief Response to indicate bust state. */
#define MMCSD_LIB_CMDRSP_BUSY           BIT(4U)

/** \brief Command to configure for 136 bits data width. */
#define MMCSD_LIB_CMDRSP_136BITS        BIT(5U)

/** \brief Command to configure for data or response. */
#define MMCSD_LIB_CMDRSP_DATA           BIT(6U)

/** \brief Command to configure for data read. */
#define MMCSD_LIB_CMDRSP_READ           BIT(7U)

/** \brief Command to configure for data write. */
#define MMCSD_LIB_CMDRSP_WRITE          BIT(8U)



/** \brief SD voltage enumeration as per VHS field of the interface command. */
#define MMCSD_LIB_VOLT_2P7_3P6          (0x000100U)

/**
 * SD OCR register definitions.
 */

/** \brief High capacity card type. */
#define MMCSD_LIB_OCR_HIGH_CAPACITY     BIT(30U)

/**
 * Voltage configurations.
 */

/** \brief Configure for 2.7V to 2.8V VDD level. */
#define MMCSD_LIB_OCR_VDD_2P7_2P8       BIT(15U)

/** \brief Configure for 2.8V to 2.9V VDD level. */
#define MMCSD_LIB_OCR_VDD_2P8_2P9       BIT(16U)

/** \brief Configure for 2.9V to 3.0V VDD level. */
#define MMCSD_LIB_OCR_VDD_2P9_3P0       BIT(17U)

/** \brief Configure for 3.0V to 3.1V VDD level. */
#define MMCSD_LIB_OCR_VDD_3P0_3P1       BIT(18U)

/** \brief Configure for 3.1V to 3.2V VDD level. */
#define MMCSD_LIB_OCR_VDD_3P1_3P2       BIT(19U)

/** \brief Configure for 3.2V to 3.3V VDD level. */
#define MMCSD_LIB_OCR_VDD_3P2_3P3       BIT(20U)

/** \brief Configure for 3.3V to 3.4V VDD level. */
#define MMCSD_LIB_OCR_VDD_3P3_3P4       BIT(21U)

/** \brief Configure for 3.4V to 3.5V VDD level. */
#define MMCSD_LIB_OCR_VDD_3P4_3P5       BIT(22U)

/** \brief Configure for 3.5V to 3.6V VDD level. */
#define MMCSD_LIB_OCR_VDD_3P5_3P6       BIT(23U)

/** \brief Wild card to configure for VDD level. */
#define MMCSD_LIB_OCR_VDD_WILDCARD      (0x1FFU << 15U)

/**
 * SD CSD register definitions.
 */

/** \brief Card bus frequency configuration for 25 Mbps. */
#define MMCSD_LIB_TRANSPEED_25MBPS      (0x32U)

/** \brief Card bus frequency configuration for 50 Mbps. */
#define MMCSD_LIB_TRANSPEED_50MBPS      (0x5AU)

/** \brief Gives the card version. */
#define MMCSD_LIB_CARD_CSD_VERSION(crd) \
    (((crd)->raw_csd[3U] & 0xC0000000) >> 30U)

/** \brief Extract the size of device for SD version 0. */
#define MMCSD_LIB_CSD0_DEV_SIZE(csd3, csd2, csd1, csd0) \
    (((csd2 & 0x000003FFU) << 2U) | ((csd1 & 0xC0000000U) >> 30U))

/** \brief TBD for SD version 0. */
#define MMCSD_LIB_CSD0_MULT(csd3, csd2, csd1, csd0) \
    ((csd1 & 0x00038000U) >> 15U)

/** \brief Extract the read block length for SD version 0. */
#define MMCSD_LIB_CSD0_RDBLKLEN(csd3, csd2, csd1, csd0) \
    ((csd2 & 0x000F0000U) >> 16U)

/** \brief Extract the card transfer speed for SD version 0. */
#define MMCSD_LIB_CSD0_TRANSPEED(csd3, csd2, csd1, csd0) \
    ((csd3 & 0x000000FFU) >> 0U)

/** \brief Extracts the size of card for SD version 0. */
#define MMCSD_LIB_CARD0_DEV_SIZE(crd) \
    MMCSD_LIB_CSD0_DEV_SIZE((crd)->raw_csd[3U], (crd)->raw_csd[2U], \
    (crd)->raw_csd[1U], (crd)->raw_csd[0U])

/** \brief TBD for SD version 0. */
#define MMCSD_LIB_CARD0_MULT(crd) \
    MMCSD_LIB_CSD0_MULT((crd)->raw_csd[3U], (crd)->raw_csd[2U], \
    (crd)->raw_csd[1U], (crd)->raw_csd[0U])

/** \brief Gives the card block length for SD version 0. */
#define MMCSD_LIB_CARD0_RDBLKLEN(crd) \
    MMCSD_LIB_CSD0_RDBLKLEN((crd)->raw_csd[3U], (crd)->raw_csd[2U], \
    (crd)->raw_csd[1U], (crd)->raw_csd[0U])

/** \brief Gives the card transfer speed for SD version 0. */
#define MMCSD_LIB_CARD0_TRANSPEED(crd) \
    MMCSD_LIB_CSD0_TRANSPEED((crd)->raw_csd[3U], (crd)->raw_csd[2U], \
    (crd)->raw_csd[1U], (crd)->raw_csd[0U])

/** \brief Gives number of blocks on card for SD version 0. */
#define MMCSD_LIB_CARD0_NUMBLK(crd) \
    ((MMCSD_LIB_CARD0_DEV_SIZE((crd)) + 1U) * \
    (1U << (MMCSD_LIB_CARD0_MULT((crd)) + 2U)))

/** \brief Gives the size of card for SD version 0. */
#define MMCSD_LIB_CARD0_SIZE(crd) ((MMCSD_LIB_CARD0_NUMBLK((crd))) * \
    (1U << (MMCSD_LIB_CARD0_RDBLKLEN(crd))))

/** \brief Extracts the size of card for SD version 1. */
#define MMCSD_LIB_CSD1_DEV_SIZE(csd3, csd2, csd1, csd0) \
    (((csd2 & 0x0000003FU) << 16U) | ((csd1 & 0xFFFF0000U) >> 16U))

/** \brief Extracts the card block length for SD version 1. */
#define MMCSD_LIB_CSD1_RDBLKLEN(csd3, csd2, csd1, csd0) \
    ((csd2 & 0x000F0000U) >> 16U)

/** \brief Extracts the card transfer speed for SD version 1. */
#define MMCSD_LIB_CSD1_TRANSPEED(csd3, csd2, csd1, csd0) \
    ((csd3 & 0x000000FFU) >> 0U)

/** \brief Gives the size of card for SD version 1. */
#define MMCSD_LIB_CARD1_DEV_SIZE(crd) \
    MMCSD_LIB_CSD1_DEV_SIZE((crd)->raw_csd[3U], (crd)->raw_csd[2U], \
    (crd)->raw_csd[1U], (crd)->raw_csd[0U])

/** \brief Reads the card block length for SD version 1. */
#define MMCSD_LIB_CARD1_RDBLKLEN(crd) \
    MMCSD_LIB_CSD1_RDBLKLEN((crd)->raw_csd[3U], (crd)->raw_csd[2U], \
    (crd)->raw_csd[1U], (crd)->raw_csd[0U])

/** \brief Reads the card transfer speed for SD version 1. */
#define MMCSD_LIB_CARD1_TRANSPEED(crd) \
    MMCSD_LIB_CSD1_TRANSPEED((crd)->raw_csd[3U], (crd)->raw_csd[2U], \
    (crd)->raw_csd[1U], (crd)->raw_csd[0U])

/** \brief Gives the size of card for SD version 1. */
#define MMCSD_LIB_CARD1_SIZE(crd) ((MMCSD_LIB_CARD1_DEV_SIZE((crd)) + 1U) * \
    (512U * 1024U))

/**
 * Check RCA/status.
 */

 /** \brief Command relative address. */
#define MMCSD_LIB_RCA_ADDR(rca)             ((rca & 0xFFFF0000U) >> 16U)

/** \brief TBD. */
#define MMCSD_LIB_RCA_STAT(rca)             (rca & 0x0xFFFFU)

/** \brief Check pattern that can be used for card response validation. */
#define MMCSD_LIB_CHECK_PATTERN             (0xAAU)

/**
 * SD SCR related macros.
 */

/** \brief Card version 0. */
#define MMCSD_LIB_VERSION_1P0               (0U)

/** \brief Card version 1. */
#define MMCSD_LIB_VERSION_1P1               (1U)

/** \brief Card version 2. */
#define MMCSD_LIB_VERSION_2P0               (2U)

/** \brief Card bus width configuration for 1-bit mode. */
#define MMCSD_LIB_BUS_WIDTH_1BIT            (1U)

/** \brief Card bus width configuration for 4-bit mode. */
#define MMCSD_LIB_BUS_WIDTH_4BIT            (4U)

/**
 * Helper macros.
 * Note card registers are big endian.
 */

/** \brief Reads card version. */
#define MMCSD_LIB_CARD_VERSION(sdcard)      ((sdcard)->raw_scr[0U] & 0xFU)

/** \brief Reads card bus width. */
#define MMCSD_LIB_CARD_BUSWIDTH(sdcard) (((sdcard)->raw_scr[0U] & 0xF00U) >> 8U)

/** \brief Check for bus width. Give below values
 *         - MMCSD_LIB_BUS_WIDTH_1BIT for 1-bit.
 *         - MMCSD_LIB_BUS_WIDTH_4BIT for 4-bit.
 *         - 0xFFU                    for invalid bus width.
 */
#define MMCSD_LIB_GET_CARD_BUSWIDTH(sdcard) \
    ((((sdcard.busWidth) & 0x0FU) == 0x01) ? \
    0x1 : ((((sdcard).busWidth & 0x04U) == 0x04U) ? 0x04U : 0xFFU))

/** \brief Check for bus width. Give below values
 *         - 50U for 50 MHz.
 *         - 25U for 25 Mhz.
 *         - 0U  for invalid bus width.
 */
#define MMCSD_LIB_GET_CARD_FRE(sdcard) (((sdcard.tranSpeed) == 0x5AU) ? 50U : \
    (((sdcard.tranSpeed) == 0x32U) ? 25U : 0U))

/** \brief Define cache line size for buffer alignment. */
#ifndef SOC_CACHELINE_SIZE
#define SOC_CACHELINE_SIZE                  (128U)
#endif

/** \brief Command argument to configure for switch mode. */
#define MMCSD_LIB_SWITCH_MODE               (0x80FFFFFFU)

/** \brief Command argument width to configure for transfer speed. */
#define MMCSD_LIB_CMD6_GRP1_SEL             (0xFFFFFFF0U)

/** \brief Command argument to configure for high speed. */
#define MMCSD_LIB_CMD6_GRP1_HS              (0x1U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

struct mmcsdLibCtrlInfo;

/**
 * \brief Structure for SD Card information.
 */
typedef struct mmcsdLibCardInfo {
    struct mmcsdLibCtrlInfo *pCtrl;
    /**< Controller. */
    uint32_t cardType;
    /**< Type of card. */
    uint32_t rca;
    /**< Relative card address. */
    uint32_t raw_scr[2U];
    /**< First value of enumeration. Can be used used for validation. */
    uint32_t raw_csd[4U];
    /**< Card specific data. */
    uint32_t raw_cid[4U];
    /**< Card identification register. */
    uint32_t ocr;
    /**< Operation condition register. */
    uint8_t sdVer;
    /**< Version of card. */
    uint8_t busWidth;
    /**< Bus width. */
    uint8_t tranSpeed;
    /**< Transfer speed. */
    uint8_t highCap;
    /**< Is card of high capacity. */
    uint32_t blkLen;
    /**< Size of a block. */
    uint32_t nBlks;
    /**< Number of blocks. */
    uint32_t size;
    /**< Size of the card in K Blocks. */
} mmcsdLibCardInfo_t;

/**
 * \brief Structure for command.
 */
typedef struct mmcsdLibCmd {
    uint32_t idx;
    /**< Command. */
    uint32_t flags;
    /**< Command flags. */
    uint32_t arg;
    /**< Commad arguments. */
    signed char *pData;
    /**< Data buffer to transmit or receive. */
    uint32_t nBlks;
    /**< No of blocks to transmit or receive. */
    uint32_t rsp[4U];
    /**< Response. */
} mmcsdLibCmd_t;

/**
 * \brief Structure for controller information.
 */
typedef struct mmcsdLibCtrlInfo {
    uint32_t baseAddr;
    /**< Base address. */
    uint32_t ipClk;
    /**< Input clock. */
    uint32_t opClk;
    /**< output clock. */
    uint32_t (*pfnCtrlInit) (struct mmcsdLibCtrlInfo *pCtrl);
    /**< Initialize controller. */
    uint32_t (*pfnCmdSend) (struct mmcsdLibCtrlInfo *pCtrl, mmcsdLibCmd_t *pCmd);
    /**< Sends command. */
    uint32_t (*pfnBusWidthConfig) (struct mmcsdLibCtrlInfo *pCtrl, uint32_t busWidth);
    /**< Configure bus width. */
    int32_t(*pfnBusFreqConfig) (struct mmcsdLibCtrlInfo *pCtrl, uint32_t busFreq);
    /**< Configure frequency. */
    uint32_t (*pfnCmdStatusGet) (struct mmcsdLibCtrlInfo *pCtrl);
    /**< Get the status of command. */
    uint32_t (*pfnXferStatusGet) (struct mmcsdLibCtrlInfo *pCtrl);
    /**< Get the status of transfer. */
    void (*pfnXferSetup) (struct mmcsdLibCtrlInfo *pCtrl, uint8_t rwFlag,
                           void *pBuff, uint32_t blkSize, uint32_t nBlks);
    /**< Configure for data transfer. */
    uint32_t (*pfnCardPresent) (struct mmcsdLibCtrlInfo *pCtrl);
    /**< Check for card. */
    void (*pfnIntrEnable) (struct mmcsdLibCtrlInfo *pCtrl);
    /**< Enable interrupts. */
    uint32_t intrMask;
    /**< Interrupt mask value. */
    uint32_t dmaEnable;
    /**< Enable DMA. */
    uint32_t busWidth;
    /**< Bus width. */
    uint32_t highspeed;
    /**< High speed. */
    uint32_t ocr;
    /**< Operation condition register. */
    uint32_t cdPinNum;
    /**< Card detect pin number. */
    uint32_t wpPinNum;
    /**< Write protect pin number. */
    mmcsdLibCardInfo_t *pCard;
    /**< Card information. */
} mmcsdLibCtrlInfo_t;

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function sends the command to MMCSD.
 *
 * \param    pCtrl         It holds the mmcsd control information.
 * \param    pCmd          It determines the mmcsd cmd
 *
 * \retval   status        Status of the command.
 **/
uint32_t MMCSDLibCmdSend(mmcsdLibCtrlInfo_t *pCtrl, mmcsdLibCmd_t *pCmd);

/**
 * \brief    This function sends the application command to MMCSD.
 *
 * \param    pCtrl         It holds the mmcsd control information.
 * \param    pCmd          It determines the mmcsd cmd
 *
 * \retval   status        Status of the application command.
 **/
uint32_t MMCSDLibAppCmdSend(mmcsdLibCtrlInfo_t *pCtrl, mmcsdLibCmd_t *pCmd);

/**
 * \brief    Configure the MMC/SD bus width
 *
 * \param    pCtrl         It holds the mmcsd control information.
 **/
uint32_t MMCSDLibBusWidthSet(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    This function configures the transmission speed in MMCSD.
 *
 * \param    pCtrl         It holds the mmcsd control information.
 *
 * \retval   TRUE   Successful.
 * \retval   FALSE  Failed.
 **/
uint32_t MMCSDLibTranSpeedSet(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    This function resets the MMCSD card.
 *
 * \param    pCtrl         It holds the mmcsd control information.
 *
 * \retval   TRUE  Successful reset of card.
 * \retval   FALSE Fails to reset the card.
 **/
uint32_t MMCSDLibCardReset(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    This function sends the stop command to MMCSD card.
 *
 * \param    pCtrl         It holds the mmcsd control information.
 *
 * \retval   TRUE   Successfully sends stop command to card.
 * \retval   FALSE  Fails to send stop command to card.
 **/
uint32_t MMCSDLibStopCmdSend(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    This function determines the type of MMCSD card.
 *
 * \param    pCtrl         It holds the mmcsd control information.
 *
 * \retval   type          Type of the MMCSD card
 *
 **/
uint32_t MMCSDLibCardTypeCheck(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    This function initializes the mmcsd controller.
 *
 * \param    pCtrl          It holds the mmcsd control information.
 *
 * \retval   TRUE           Initialization is successful.
 * \retval   FALSE          Initialization is failed.
 **/
uint32_t MMCSDLibCtrlInit(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    This function determines whether card is persent or not.
 *
 * \param    pCtrl         It holds the mmcsd control information.
 *
 * \retval   TRUE          Card is present.
 * \retval   FALSE         Card is not present.
 **/
uint32_t MMCSDLibCardPresent(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    Enables the controller events to generate a h/w interrupt request
 *
 * \param    pCtrl         It holds the mmcsd control information.
 **/
void MMCSDLibIntrEnable(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    This function initializes the MMCSD Card.
 *
 * \param    pCtrl         It holds the mmcsd control information.
 *
 * \retval   TRUE          Initialization is successful.
 * \retval   FALSE         Initialization is failed.
 **/
uint32_t MMCSDLibCardInit(mmcsdLibCtrlInfo_t *pCtrl);

/**
 * \brief    This function sends the write command to MMCSD card.
 *
 * \param    pCtrl         It holds the mmcsd control information.
 * \param    pBuff         It determines the address from where data has to written
 * \param    block         It determines to which block data to be written
 * \param    nBlks         It determines the number of blocks to be written
 *
 * \retval   TRUE          Successfully written of data.
 * \retval   FALSE         Failure to write the data.
 **/
uint32_t MMCSDLibWriteCmdSend(mmcsdLibCtrlInfo_t *pCtrl, void *pBuff, uint32_t block,
                               uint32_t nBlks);

/**
 * \brief    This function sends the write command to MMCSD card.
 *
 * \param    pCtrl         It holds the mmcsd control information.
 * \param    pBuff         It determines the address to where data has to read
 * \param    block         It determines from which block data to be read
 * \param    nBlks         It determines the number of blocks to be read
 *
 * \retval   TRUE          Successful reading of data.
 * \retval   FALSE         Failure to read the data.
 **/
uint32_t MMCSDLibReadCmdSend(mmcsdLibCtrlInfo_t *pCtrl, void *pBuff, uint32_t block,
                              uint32_t nBlks);

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Declarations                           */
/* -------------------------------------------------------------------------- */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef MMCSDLIB_H_ */
