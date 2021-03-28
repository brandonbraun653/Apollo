/**
 *  \file  qspi_lib.c
 *
 *  \brief This file adds qspi library API's for read, write, erase
 *         from QSPI flash. This also initialise the QSPI controller
 *         to start transfers.
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
 */


/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "types.h"
#include "hw_types.h"
#include "qspi.h"
#include "qspi_flash.h"
#include "qspi_lib.h"
#include "error.h"
#include "console_utils.h"

/* ========================================================================== */
/*                          Macros and Typedefs                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This function will return the value of the QSPI flash status
 *        register.
 *
 * \param  pQspiLibInfo    Pointer to structure containing QSPI
 *                         controller and flash device Info.
 *
 * \retval flashStatus Value of flash status register.
 */
uint32_t QspiLibFlashStatus(qspiLibInfo_t *pQspiLibInfo);

/**
 * \brief  This function sends write enable command to the flash device.
 *
 * \param  pQspiLibInfo    Pointer to structure containing QSPI
 *                         controller and flash device Info.
 */
void QspiLibWriteEnable(qspiLibInfo_t *pQspiLibInfo);

/**
 * \brief This API allows flash to enter/exit 32 bit addressing mode
 *
 * \param  pQspiLibInfo    Pointer to structure containing QSPI controller
 *                         and flash device Info.
 * \param enable4ByteAddrMode  TRUE - Enter 4 byte addressing mode
 *                             FALSE  Exit four byte addressing mode
 */
void QspiLibEnable4ByteAddrMode(qspiLibInfo_t *pQspiLibInfo,
                             uint32_t enable4ByteAddrMode);

/**
 * \brief  This API writes data to flash device
 *         using QSPI controller in memory mapped mode.
 *
 * \param  pQspiLibInfo    Pointer to structure containing QSPI controller
 *                         and flash device Info.
 * \param dstOffsetAddr    destination offset address
 * \param srcAddr          Source address
 * \param length           length of data to be written.
 *
 */
void QspiLibMemMapWrite(qspiLibInfo_t *pQspiLibInfo,
                        uint32_t dstOffsetAddr,
                        uint32_t srcAddr,
                        uint32_t length);

/**
 * \brief  This API writes data to flash device
 *         using QSPI controller in config mode.
 *
 * \param  pQspiLibInfo       Pointer to structure containing QSPI controller and
 *                         Flash device Info.
 * \param dstOffsetAddr    destination offset address
 * \param srcAddr          Source address
 * \param length           length of data to be written.
 *
 */
void QspiLibCfgModeWrite(qspiLibInfo_t *pQspiLibInfo,
                         uint32_t dstOffsetAddr,
                         uint32_t srcAddr,
                         uint32_t length);

/**
 * \brief  This APIs reads length bytes of data from flash device
 *         using QSPI controller in memory mapped mode.
 *
 * \param  pQspiLibInfo    Pointer to structure containing QSPI controller
 *                         and flash device Info.
 * \param srcOffsetAddr    Source Offset address
 * \param dstAddr          destination address
 * \param length           length of data to be read.
 *
 */
void QspiLibMemMapRead(qspiLibInfo_t *pQspiLibInfo,
                       uint32_t srcOffsetAddr,
                       uint32_t dstAddr,
                       uint32_t length);

/**
 * \brief  This APIs reads length byte of data from flash device
 *         using QSPI controller in config mode.
 *
 * \param  pQspiLibInfo    Pointer to structure containing QSPI controller
 *                         and flash device Info.
 * \param srcOffsetAddr    Source Offset address
 * \param dstAddr          destination address
 * \param length           length of data to be read.
 *
 */
void QspiLibCfgModeRead(qspiLibInfo_t *pQspiLibInfo,
                        uint32_t srcOffsetAddr,
                        uint32_t dstAddr,
                        uint32_t length);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void QSPILibInit(qspiLibInfo_t *pQspiLibInfo)
{
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    /** Setting IDLE mode for QSPI controller */
    QSPISetIdleMode(baseAddr,QSPI_SYSCONFIG_IDLE_MODE_NO);
    /** Set clock mode in mode 3 */
    QSPISetClkMode(baseAddr, chipSelect, QSPI_CLK_MODE_3);
    QSPISetCsPol(baseAddr, chipSelect, QSPI_CS_POL_ACTIVE_LOW);
    QSPISetDataDelay(baseAddr, chipSelect, QSPI_DATA_DELAY_0);
    /**
     *  Setting write command for memory mapped mode in init
     *  as there is only one write type possible i.e. single write
     */
    QSPISetMemMapWriteCmd(baseAddr, chipSelect, QSPI_LIB_CMD_PAGE_PRG);
    /* Default number of address bytes are 3 */
    QSPISetMemMapNumAddrBytes(baseAddr,
                      chipSelect,
                              QSPI_MEM_MAP_NUM_ADDR_BYTES_THREE);
    /* Enable clock and set divider value */
    QSPISetPreScaler(baseAddr, 0x0U);
    /* Enable memory mapped port */
    QSPISetMemAddrSpace(baseAddr,
                        chipSelect,
                        QSPI_MEM_MAP_PORT_SEL_MEM_MAP_PORT);
}

int32_t QSPILibRead(qspiLibInfo_t *pQspiLibInfo,
                 uint32_t srcOffsetAddr,
                 uint32_t dstAddr,
                 uint32_t length)
{
    int32_t retval = S_PASS;
    if (QSPI_LIB_TX_MODE_CONFIG_MODE ==
            pQspiLibInfo->qspiLibCtrlInfo.qspiLibTxMode)
    {
        QspiLibCfgModeRead(pQspiLibInfo, srcOffsetAddr, dstAddr, length);
    } else if (QSPI_LIB_TX_MODE_MEMORY_MAPPED ==
                   pQspiLibInfo->qspiLibCtrlInfo.qspiLibTxMode)
    {
        QspiLibMemMapRead(pQspiLibInfo, srcOffsetAddr, dstAddr, length);
    } else
    {
        retval = E_FAIL;
    }
    return retval;
}

int32_t QSPILibWrite(qspiLibInfo_t *pQspiLibInfo,
                  uint32_t dstOffsetAddr,
                  uint32_t srcAddr,
                  uint32_t length)
{
    int32_t retval = S_PASS;
    if(QSPI_LIB_TX_MODE_CONFIG_MODE ==
          pQspiLibInfo->qspiLibCtrlInfo.qspiLibTxMode)
    {
        /* Max number of bytes written at one time in config mode is 256
           This is taken care by the qspi lib. Application can pass any length
           to be written
         */
        while (length > 256U)
        {
             QspiLibCfgModeWrite(pQspiLibInfo, dstOffsetAddr,srcAddr, 256U);
             length -=256U;
             dstOffsetAddr += 256U;
             srcAddr += 256U;
        }
        if (length > 0U)
        {
             QspiLibCfgModeWrite(pQspiLibInfo, dstOffsetAddr,srcAddr, length);
        }
    } else if (QSPI_LIB_TX_MODE_MEMORY_MAPPED ==
                  pQspiLibInfo->qspiLibCtrlInfo.qspiLibTxMode)
    {
        QspiLibMemMapWrite(pQspiLibInfo, dstOffsetAddr,srcAddr, length);
    } else
    {
        retval = E_FAIL;
    }
    return retval;
}

void QSPILibBlockErase(qspiLibInfo_t *pQspiLibInfo, uint32_t blockNumber)
{

    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    uint32_t data;
    qspiTxCmd_t qspiTxCmd = {0};
    uint32_t eraseAddr       = blockNumber *
                               pQspiLibInfo->qspiLibFlashInfo.blockSize;
    uint32_t wordLength = 24U;
    /* If source offset address is greater than 24 bits
     * Enter 32 bit address mode */
    if(eraseAddr > 0xFFFFFFU)
    {
        /* Enter 32 bit address mode */
        QspiLibEnable4ByteAddrMode(pQspiLibInfo, TRUE);
        wordLength = 32U;

    }
    QspiLibWriteEnable(pQspiLibInfo);
    data = QSPI_LIB_CMD_BLOCK_ERASE;
    QSPIWriteData(baseAddr, &data, 1U);

    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    qspiTxCmd.frameLength = 2U;
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.chipSelect = chipSelect;
    QSPISetCfgModeTxCmd(baseAddr,qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));

    data = eraseAddr;

    QSPIWriteData(baseAddr, &data, 1U);
    qspiTxCmd.wordLength = wordLength;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr,qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));
    /* Wait while busy */
    while (1U == (QspiLibFlashStatus(pQspiLibInfo) & 0x1U));

    if(eraseAddr > 0xFFFFFFU)
    {
        /* Exit 32 bit address mode */
        QspiLibEnable4ByteAddrMode(pQspiLibInfo, FALSE);
    }
}


void QSPILibChipErase(qspiLibInfo_t * pQspiLibInfo)
{
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    uint32_t data;
    qspiTxCmd_t qspiTxCmd = {0};

    /* Write enable flash device by sending write enable command */
    QspiLibWriteEnable(pQspiLibInfo);

    /* This is for sending full erase command for QSPI flash device */
    data = QSPI_LIB_CMD_FULL_ERASE;
    QSPIWriteData(baseAddr, &data, 1U);
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    qspiTxCmd.frameLength = 1U;
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.chipSelect = chipSelect;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    /* Wait while flash is getting erased */
    while (1U == (QspiLibFlashStatus(pQspiLibInfo) & 0x1U));
}

void QSPILibPrintId(qspiLibInfo_t * pQspiLibInfo)
{
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    qspiTxCmd_t qspiTxCmd = {0};
    uint32_t deviceId, mfgId;
    uint32_t writeVal;

    /* Write Command */
    writeVal = QSPI_LIB_CMD_READ_MFG_ID;
    QSPIWriteData(baseAddr, &writeVal, 1U);
    qspiTxCmd.frameLength = 4U;
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.chipSelect = chipSelect;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));

    /* Write Address Bytes */
    writeVal = 0x0U;
    QSPIWriteData(baseAddr, &writeVal, 1U);
    qspiTxCmd.wordLength = 24U;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));

    /* Read Manufacturer ID
     * The manufacturer ID is of 1 byte(8 bits)
     */
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_READ_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));
    QSPIReadData(baseAddr, &mfgId, 1U);
    CONSOLEUtilsPrintf("Flash Manufacturer ID = %x\n",mfgId);

    /* Read Device ID */
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_READ_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));

    QSPIReadData(baseAddr, &deviceId, 1U);
    CONSOLEUtilsPrintf("Device ID = %x\n",deviceId);
    /* Note - This ID is the device ID of the flash device.
     * This ID is read from the flash
     */
}

void QSPILibQuadEnable(qspiLibInfo_t *pQspiLibInfo,
                       qspiFlashDeviceData_t *qspiFlashDeviceData)
{
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    uint32_t data;
    uint32_t norStatus;
    qspiTxCmd_t qspiTxCmd = {0};

    /* Read Status register */
    data = qspiFlashDeviceData->quadReadCmd;
    QSPIWriteData(baseAddr, &data, 1U);
    qspiTxCmd.frameLength = 2U;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    qspiTxCmd.wordLength  = 8U;
    qspiTxCmd.chipSelect = chipSelect;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_READ_SINGLE;
    qspiTxCmd.wordLength  = 8U;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));
    QSPIReadData(baseAddr, &norStatus, 1U);

    /* Send Write Enable before writing status register Quad enable bit */
    QspiLibWriteEnable(pQspiLibInfo);

    /* Send write status register command */
    data = qspiFlashDeviceData->quadWriteCmd;
    QSPIWriteData(baseAddr, &data, 1U);
    qspiTxCmd.frameLength = 2U;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    qspiTxCmd.wordLength  = 8U;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));

    /* Set status register 6th bit to 1 for Quad enable
     * Write this value to the status register.
     */
    norStatus &= ~(1U << qspiFlashDeviceData->quadEnableBit);
    norStatus |= (qspiFlashDeviceData->quadValue << qspiFlashDeviceData->quadEnableBit);
    QSPIWriteData(baseAddr, &norStatus, 1U);
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    qspiTxCmd.wordLength  = 8U;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    /* wait till the command is being send */
    while (TRUE == QSPIIsBusy(baseAddr));
    /* Wait till the status register is being written */
    while (1U == (QspiLibFlashStatus(pQspiLibInfo) & 0x1U));
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */
void QspiLibMemMapWrite(qspiLibInfo_t *pQspiLibInfo,
                     uint32_t dstOffsetAddr,
                     uint32_t srcAddr,
                     uint32_t length)
{
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    uint32_t dstAddr = pQspiLibInfo->qspiLibCtrlInfo.memMapBaseAddr +
                       dstOffsetAddr;
    uint32_t *pDestAddr = (uint32_t *) (dstAddr);
    uint32_t *pSrcAddr = (uint32_t *) (srcAddr);
    uint32_t i;

   /* If destination offset address is greater than 24 bits
    * Enter 32 bit address mode */
    if(dstOffsetAddr > 0xFFFFFFU)
    {
        /* Enter 32 bit address mode */
        QspiLibEnable4ByteAddrMode(pQspiLibInfo, TRUE);
        QSPISetMemMapNumAddrBytes(baseAddr,
                                  chipSelect,
                                  QSPI_MEM_MAP_NUM_ADDR_BYTES_FOUR);
    }

    for (i = 0U; i < (length/4U); i++)
    {
        QspiLibWriteEnable(pQspiLibInfo);
        *pDestAddr = *pSrcAddr;
        pDestAddr++;
        pSrcAddr++;
        while ((QspiLibFlashStatus(pQspiLibInfo) & 0x1U));
    }
    if (0U != (length % 4U))
    {
        /* In case number of bytes is not a multiple of 4
         * One extra word is written to ensure complete data is written
         * and no data is lost.
         */
        QspiLibWriteEnable(pQspiLibInfo);
        *pDestAddr = *pSrcAddr;
        pDestAddr++;
        pSrcAddr++;
        while ((QspiLibFlashStatus(pQspiLibInfo) & 0x1U));
    }
    if(dstOffsetAddr > 0xFFFFFF)
    {
        /* Exit 32 bit address mode */
        QspiLibEnable4ByteAddrMode(pQspiLibInfo, FALSE);
        QSPISetMemMapNumAddrBytes(baseAddr,
                                 chipSelect,
                                 QSPI_MEM_MAP_NUM_ADDR_BYTES_THREE);
    }
}

void QspiLibCfgModeWrite(qspiLibInfo_t *pQspiLibInfo,
                      uint32_t dstOffsetAddr,
                      uint32_t srcAddr,
                      uint32_t length)
{
    /* Config mode write */
    qspiTxCmd_t qspiTxCmd = {0};
    uint32_t writeVal;
    uint32_t i;
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    uint32_t addrWordLength = 24U;

    /* If destination offset address is greater than 24 bits
     * Enter 32 bit address mode */
    if(dstOffsetAddr > 0xFFFFFFU)
    {
        QspiLibEnable4ByteAddrMode(pQspiLibInfo, TRUE);
        addrWordLength = 32U;
    }

    QspiLibWriteEnable(pQspiLibInfo);
    /* Write Command */
    writeVal = QSPI_LIB_CMD_PAGE_PRG;
    QSPIWriteData(baseAddr, &writeVal, 1U);
    qspiTxCmd.frameLength = (length / 4U) + 2U;
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.chipSelect = chipSelect;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));

    /* Write Address Bytes */
    writeVal = dstOffsetAddr;
    QSPIWriteData(baseAddr, &writeVal, 1U);
    qspiTxCmd.wordLength = addrWordLength;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));

    qspiTxCmd.wordLength = 32U;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    for(i = 0U; i < (length/4U); i++)
    {
        QSPIWriteData(baseAddr, (uint32_t *)srcAddr, 1U);
        srcAddr += 4U;
        QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
        while (TRUE == QSPIIsBusy(baseAddr));
    }
    if(0U != (length % 4U))
    {
        /* In case number of bytes is not a multiple of 4
         * Remaining bytes are written to the flash device
         */
        qspiTxCmd.wordLength = (length % 32U);
        qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
        QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
        QSPIWriteData(baseAddr, (uint32_t *)srcAddr, 1U);
        while (TRUE == QSPIIsBusy(baseAddr));
    }
    while ((QspiLibFlashStatus(pQspiLibInfo) & 0x1U));
    if(dstOffsetAddr > 0xFFFFFFU)
    {
        /* Exit 32 bit address mode */
        QspiLibEnable4ByteAddrMode(pQspiLibInfo, FALSE);
    }
}

void QspiLibMemMapRead(qspiLibInfo_t *pQspiLibInfo,
                    uint32_t srcOffsetAddr,
                    uint32_t dstAddr,
                    uint32_t length)
{
    /* Read from QSPI in memory mapped mode */
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    uint32_t srcAddr = pQspiLibInfo->qspiLibCtrlInfo.memMapBaseAddr +
                       srcOffsetAddr;
    uint32_t *pDestAddr = (uint32_t *) (dstAddr);
    uint32_t *pSrcAddr = (uint32_t *) (srcAddr);
    uint32_t i;

    switch(pQspiLibInfo->qspiLibCtrlInfo.qspiLibReadType)
    {
        case QSPI_LIB_READ_TYPE_SINGLE:
            /**< Single read mode */
            QSPISetMemMapReadCmd(baseAddr,
                                 chipSelect,
                                 QSPI_LIB_CMD_READ_SINGLE);
            QSPISetMemMapReadType(baseAddr,
                                  chipSelect,
                                  QSPI_MEM_MAP_READ_TYPE_NORMAL);
            QSPISetMemMapNumDummyBits(baseAddr, chipSelect, 0x0U);
            break;

        case QSPI_LIB_READ_TYPE_DUAL:
        /**< Dual read mode */
            QSPISetMemMapReadCmd(baseAddr, chipSelect, QSPI_LIB_CMD_READ_DUAL);
            QSPISetMemMapReadType(baseAddr,
                                  chipSelect,
                                  QSPI_MEM_MAP_READ_TYPE_DUAL);
            QSPISetMemMapNumDummyBits(baseAddr, chipSelect, 0x8U);
            break;

        case QSPI_LIB_READ_TYPE_QUAD:
            /**< Quad read mode */
            QSPISetMemMapReadCmd(baseAddr, chipSelect, QSPI_LIB_CMD_READ_QUAD);
            QSPISetMemMapReadType(baseAddr,
                                  chipSelect,
                                  QSPI_MEM_MAP_READ_TYPE_QUAD);
            QSPISetMemMapNumDummyBits(baseAddr, chipSelect, 0x8U);
            break;
    }

   /* If source offset address is greater than 24 bits
    * Enter 32 bit address mode */
    if(srcOffsetAddr > 0xFFFFFF)
    {
        /* Enter 32 bit address mode */
        QspiLibEnable4ByteAddrMode(pQspiLibInfo, TRUE);
        QSPISetMemMapNumAddrBytes(baseAddr,
                                  chipSelect,
                                  QSPI_MEM_MAP_NUM_ADDR_BYTES_FOUR);
    }
    for (i = 0U; i < (length/4U); i++)
    {
        *pDestAddr = *pSrcAddr;
        pDestAddr++;
        pSrcAddr++;
    }
    if ((length % 4U) != 0U)
    {
        /* In case number of bytes is not a multiple of 4
         * One extra word is read from the flash to ensure that no
         * data is lost.
         */
        *pDestAddr = *pSrcAddr;
        pDestAddr++;
        pSrcAddr++;
    }
    if(srcOffsetAddr > 0xFFFFFFU)
    {
        /* Exit 32 bit address mode */
        QspiLibEnable4ByteAddrMode(pQspiLibInfo, FALSE);
        QSPISetMemMapNumAddrBytes(baseAddr,
                                  chipSelect,
                                  QSPI_MEM_MAP_NUM_ADDR_BYTES_THREE);
    }

}

void QspiLibCfgModeRead(qspiLibInfo_t *pQspiLibInfo,
                     uint32_t srcOffsetAddr,
                     uint32_t dstAddr,
                     uint32_t length)
{
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t addrWordLength = 24U;
    /** Config mode read */
    qspiTxCmd_t qspiTxCmd = {0};
    uint32_t readCmd = 0U, txCmd = 0U;
    uint32_t numDummyBits = 0U, frameLength = 0U;
    uint32_t writeVal;
    uint32_t i;

    /* If source offset address is greater than 24 bits
     * Enter 32 bit address mode */
    if(srcOffsetAddr > 0xFFFFFFU)
    {
        /* Enter 32 bit address mode */
        QspiLibEnable4ByteAddrMode(pQspiLibInfo, TRUE);
        addrWordLength = 32U;
    }
    /* The readCmd, txCmd, numDummyBits and the frameLength are
     * set according the the qspi read type
     */
    switch(pQspiLibInfo->qspiLibCtrlInfo.qspiLibReadType)
    {
        case QSPI_LIB_READ_TYPE_SINGLE:
            readCmd = QSPI_LIB_CMD_READ_SINGLE;
            txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_READ_SINGLE;
            numDummyBits = 0U;
            frameLength = (length / 4U) + 2U;
            break;
        case QSPI_LIB_READ_TYPE_DUAL:
            readCmd = QSPI_LIB_CMD_READ_DUAL;
            txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_READ_DUAL;
            numDummyBits = 8U;
            frameLength = (length / 4U) + 3U;
            break;
        case QSPI_LIB_READ_TYPE_QUAD:
            readCmd = QSPI_LIB_CMD_READ_QUAD;
            txCmd = QSPI_CFG_MODE_TX_CMD_SIX_PIN_READ_QUAD;
            numDummyBits = 8U;
            frameLength = (length / 4U) + 3U;
            break;
    }
    /* Write Command */
    writeVal = readCmd;
    QSPIWriteData(baseAddr, &writeVal, 1U);
    qspiTxCmd.frameLength = frameLength;
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.chipSelect = chipSelect;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));
    if(0U != numDummyBits)
    {
        /**< Write dummy bytes for fast read if required */
        writeVal = 0U;
        QSPIWriteData(baseAddr, &writeVal, 1U);
        qspiTxCmd.wordLength = numDummyBits;
        qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
        QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
        while (TRUE == QSPIIsBusy(baseAddr));
    }
    /* Write Address Bytes */
    writeVal = srcOffsetAddr;
    QSPIWriteData(baseAddr, &writeVal, 1U);
    qspiTxCmd.wordLength = addrWordLength;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));
    qspiTxCmd.wordLength = 32U;
    qspiTxCmd.txCmd = txCmd;
    for(i = 0U; i < (length/4U); i++)
    {
        QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
        while (TRUE == QSPIIsBusy(baseAddr));
        QSPIReadData(baseAddr, (uint32_t *)dstAddr, 1U);
        dstAddr += 4U;
    }
    if (0U != (length % 4U))
    {
        /* In case number of bytes is not a multiple of 4
         * Read remaining bytes from the flash device */
        qspiTxCmd.wordLength = (length % 32U);
        qspiTxCmd.txCmd = txCmd;
        QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
        while (TRUE == QSPIIsBusy(baseAddr));
        QSPIReadData(baseAddr, (uint32_t *)dstAddr, 1U);
    }
    if(srcOffsetAddr > 0xFFFFFFU)
    {
        /* Exit 32 bit address mode */
        QspiLibEnable4ByteAddrMode(pQspiLibInfo, FALSE);
    }
}

uint32_t QspiLibFlashStatus(qspiLibInfo_t *pQspiLibInfo)
{
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    qspiTxCmd_t qspiTxCmd = {0};
    uint32_t data, writeVal;
    /* Write Address Bytes */
    writeVal = QSPI_LIB_CMD_READ_STATUS_REG;
    QSPIWriteData(baseAddr, &writeVal, 1U);
    qspiTxCmd.frameLength = 2U;
    qspiTxCmd.chipSelect = chipSelect;
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));

    /* Read data status register to check write in progress bit */
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_READ_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));
    QSPIReadData(baseAddr, &data, 1U);
    return (data & 0xFFU);
}

void QspiLibWriteEnable(qspiLibInfo_t *pQspiLibInfo)
{
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    qspiTxCmd_t qspiTxCmd = {0};
    uint32_t data = QSPI_LIB_CMD_WRITE_ENABLE;
    /* Sets the write enable bit of the Serial flash device used */

    QSPIWriteData(baseAddr, &data, 1U);

    qspiTxCmd.frameLength = 1U;
    qspiTxCmd.chipSelect = chipSelect;
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));

}

void QspiLibEnable4ByteAddrMode(qspiLibInfo_t *pQspiLibInfo, uint32_t flag)
{
    uint32_t chipSelect = pQspiLibInfo->qspiLibCtrlInfo.chipSelect;
    uint32_t baseAddr = pQspiLibInfo->qspiLibCtrlInfo.cfgBaseAddr;
    qspiTxCmd_t qspiTxCmd = {0};
    uint32_t data;
    if(TRUE == flag)
    {
        data = QSPI_LIB_CMD_ENTER_4_BYTE_ADDR;
    }
    else if(FALSE == flag)
    {
        data = QSPI_LIB_CMD_EXIT_4_BYTE_ADDR;
    }

    QSPIWriteData(baseAddr, &data, 1U);

    qspiTxCmd.frameLength = 1U;
    qspiTxCmd.chipSelect = chipSelect;
    qspiTxCmd.wordLength = 8U;
    qspiTxCmd.txCmd = QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE;
    QSPISetCfgModeTxCmd(baseAddr, qspiTxCmd);
    while (TRUE == QSPIIsBusy(baseAddr));
}
