/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 *  \file  evmc66x_qspi.c
 *
 *  \brief This file contains C66x QSPI specific functions.
 *
 ******************************************************************************/

#include "platform_internal.h"

#if (PLATFORM_QSPI_FLASH_IN)

#define QSPI_FIELD_INT_CLEAR_ALL  0x1fff
hQspiHandle hQspi = (hQspiHandle)CSL_QSPI_0_CFG_REGS;

/**
 * \brief     Enables or disables the QSPI Controller.
 *
 * \param     enable  [IN]  1 : Enables QSPI controller
 *                          0 : Disables QSPI Controller.
 *
 * \return    NONE.
 *
 **/
static void qspiControl(uint8_t enable)
{
    CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_ENB_QSPI_FLD,
         enable);
}

/**
 * \brief     To wait till the QSPI controller is IDLE.
 *
 * \param     NONE.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
static QSPI_STATUS qspiWaitIdle(void)
{
    uint8_t count = 0;
    uint32_t timeOut = QSPI_TIMEOUT_US;
    uint8_t status;

    while(timeOut)
    {
        platform_delay(10 * 1000);
        timeOut -= (10 * 1000);
        /* Read STATUS read-only bit */
        status = CSL_FEXT(hQspi->CONFIG_REG,
                QSPI_CONFIG_REG_QSPI_IDLE_FLD);
        if (status) {
            /* Read few times in succession to ensure it does
               not transition low again */
            count++;
            if (count >= QSPI_POLL_IDLE_RETRY) {
                return QSPI_SUCCESS;
            }
        } else {
            count = 0;
        }
    }
    IFPRINT (platform_write("QSPI is still busy after %dms timeout.\n",
                timeOut));
    return QSPI_ERR;
}

/**
 * \brief     To disable DAC and wait till QSPI is idle.
 *
 * \param     NONE.
 *
 * \return    QSPI_SUCCESS if success.
 *            QSPI_ERR     if error.
 *
 **/
static QSPI_STATUS qspiDacDisableAndIdle(void)
{
    /* Disable the DAC */
    CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD, 0);

        /* Poll for idle state */
    if (qspiWaitIdle()) {
        IFPRINT (platform_write("Poll for QSPI idle operation failed"));
        return QSPI_ERR;
    }
    return QSPI_SUCCESS;
}

/**
 * \brief     Selects chip select number and decoder enable.
 *
 * \param     chipSelect   [IN]  : Chip select number of flash device connected
 *            QSPI_CS0 - Chip select 0
 *            QSPI_CS1 - Chip select 1
 *            QSPI_CS2 - Chip select 2
 *            QSPI_CS3 - Chip select 3
 *
 * \param     decodeEnable [IN]  : Enables or disables the peripheral
 *                                 select decode.
 *
 * \return    NONE.
 *
 **/
static void qspiChipSelect(uint32_t chipSelect, uint32_t decoderEnable)
{
    /* Enable/disable peripheral select decode */
    CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_PERIPH_SEL_DEC_FLD,
         decoderEnable);

    /* Select chip select */
    CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_PERIPH_CS_LINES_FLD,
         chipSelect);
}

/**
 * \brief     Intialize the QSPI Controller and configures controller
 *            communication.
 *
 * \param     pageSize      : Page size of the FLASH device connected.
 *
 * \return    QSPI_SUCCESS  : if success.
 *            QSPI_ERR      : if error.
 *
 **/
static QSPI_STATUS qspiControllerInit(uint32_t pageSize)
{
    /* Disable QSPI controller */
    qspiControl(0);

    /* DAC s disabled and waiting for QSPI idle state */
    if (qspiDacDisableAndIdle()) {
        IFPRINT (platform_write("DAC disable operation failed\n"));
        return QSPI_ERR;
    }
    /* Delay Setup : Value referred from TI driver */

    /* Chip select start of transfer */
    CSL_FINS(hQspi->DEV_DELAY_REG, QSPI_DEV_DELAY_REG_D_INIT_FLD, 46);

    /* Chip select end transfer */
    CSL_FINS(hQspi->DEV_DELAY_REG, QSPI_DEV_DELAY_REG_D_AFTER_FLD, 46);

    /* Chip select De-Assert different slaves */
    CSL_FINS(hQspi->DEV_DELAY_REG, QSPI_DEV_DELAY_REG_D_BTWN_FLD, 192);

    /* Chip select De-Assert */
    CSL_FINS(hQspi->DEV_DELAY_REG, QSPI_DEV_DELAY_REG_D_NSS_FLD,
         (uint32_t)192);

    /* Disable all interrupts. */
    hQspi->IRQ_MASK_REG &= ~(0x1FFF);

    /* Chip select CS0 */
    qspiChipSelect(QSPI_CS0, QSPI_DECODER_SEL);

    /* The DAC enable is disabled through default, but explicitly set it
       anyway */
    CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD, 0);

    /* The SPI clock/data polarity settings: Value referred from TI driver*/
    CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_SEL_CLK_PHASE_FLD, 0);
    CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_SEL_CLK_POL_FLD, 0);

    /*****************Device read instruction register*****************/

    /* Number of dummy cycles is 0 */
    CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
            QSPI_DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD, 0);

        /* Mode byte disabled */
    CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
            QSPI_DEV_INSTR_RD_CONFIG_REG_MODE_BIT_ENABLE_FLD, 0);

    /* Set data IO width to SIO mode : Data is shifted to device on DQ0
       only */
    CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
            QSPI_DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD, 0);

    /* Address IO width : Address can be shifted to device on DQ0 only */
    CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
            QSPI_DEV_INSTR_RD_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD, 0);

    /* Instruction IO width : Use standard SPI mode (only on DQ0 ) */
    CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
            QSPI_DEV_INSTR_RD_CONFIG_REG_INSTR_TYPE_FLD, 0);

    CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
                QSPI_DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD, 0x3);

    /*******************Device write instruction register******************/

    /* Number of dummy cycles is 0 */
    CSL_FINS(hQspi->DEV_INSTR_WR_CONFIG_REG,
            QSPI_DEV_INSTR_WR_CONFIG_REG_DUMMY_WR_CLK_CYCLES_FLD, 0);

    /* Set data IO width to SIO mode : Data is shifted to device on DQ0
       only */
    CSL_FINS(hQspi->DEV_INSTR_WR_CONFIG_REG,
            QSPI_DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD, 0);

    /* Address IO width : Address can be shifted to device on DQ0 only */
    CSL_FINS(hQspi->DEV_INSTR_WR_CONFIG_REG,
            QSPI_DEV_INSTR_WR_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD, 0);

    CSL_FINS(hQspi->DEV_INSTR_WR_CONFIG_REG,
    		QSPI_DEV_INSTR_WR_CONFIG_REG_WEL_DIS_FLD, 1);

    CSL_FINS(hQspi->DEV_INSTR_WR_CONFIG_REG,
                QSPI_DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD, 0x2);
    /******************Device size configuration register******************/

    /* 4 byte address [A31 : A0] : For Flash device greater than 16MB */
    CSL_FINS(hQspi->DEV_SIZE_CONFIG_REG,
            QSPI_DEV_SIZE_CONFIG_REG_NUM_ADDR_BYTES_FLD, 3);

    /* Configure number of bytes per device page */
    CSL_FINS(hQspi->DEV_SIZE_CONFIG_REG,
            QSPI_DEV_SIZE_CONFIG_REG_BYTES_PER_DEVICE_PAGE_FLD,
         pageSize);

    /* SRAM partition register */
    CSL_FINS(hQspi->SRAM_PARTITION_CFG_REG,
            QSPI_SRAM_PARTITION_CFG_REG_ADDR_FLD, 128);

    hQspi->DEV_SIZE_CONFIG_REG = 0x102002;
    hQspi->IRQ_MASK_REG = (0x3FFFF);

    /**********************************************************************/

    /* Indirect AHB address trigger register */
    CSL_FINS(hQspi->IND_AHB_ADDR_TRIGGER_REG,
            QSPI_IND_AHB_ADDR_TRIGGER_REG_ADDR_FLD, (CSL_QSPI_0_DATA));

    /* Mode bits register, mode is unused */
    CSL_FINS(hQspi->MODE_BIT_CONFIG_REG,
            QSPI_MODE_BIT_CONFIG_REG_MODE_FLD, 0);

    /* Read data capture value set to 1 */
    CSL_FINS(hQspi->RD_DATA_CAPTURE_REG,
            QSPI_RD_DATA_CAPTURE_REG_BYPASS_FLD, 0);

    CSL_FINS(hQspi->RD_DATA_CAPTURE_REG,
            QSPI_RD_DATA_CAPTURE_REG_DELAY_FLD, 5);
    CSL_FINS(hQspi->RD_DATA_CAPTURE_REG,
            QSPI_RD_DATA_CAPTURE_REG_SAMPLE_EDGE_SEL_FLD, 1);

    /* Disable auto - polling on write */
    CSL_FINS(hQspi->WRITE_COMPLETION_CTRL_REG,
            QSPI_WRITE_COMPLETION_CTRL_REG_DISABLE_POLLING_FLD, 1);

    /* Configure the remap address register, no remap */
    CSL_FINS(hQspi->REMAP_ADDR_REG, QSPI_REMAP_ADDR_REG_VALUE_FLD, 0x0);

    CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_MSTR_BAUD_DIV_FLD, 1);

    CSL_FINS(hQspi->SRAM_PARTITION_CFG_REG,
                 QSPI_SRAM_PARTITION_CFG_REG_ADDR_FLD,
              QSPI_REG_SRAM_PARTITION_RD);

    /* Enable QSPI controller */
    qspiControl(1);

    return QSPI_SUCCESS;
}

/**
 * \brief     Convert command buffer to address.
 *
 * \param     addrBuf   [IN] : Buffer which has the address received from
 *                             FLASH device.
 * \param     addrWidth [IN] : Address width in bytes.
 *
 * \return    32 bit address.
 *
 **/
static uint32_t qspiCmd2Addr(uint8_t *addrBuf, uint32_t addrWidth)
{
    uint32_t addr;

    addr = ((uint32_t)addrBuf[0] << 16) | ((uint32_t)addrBuf[1] << 8) |
        addrBuf[2];

    /* Extended addressing : 4 byte address */
    if (addrWidth == 4) {
        addr = (addr << 8) | (uint32_t)addrBuf[3];
    }

    return addr;
}

/**
 * \brief     Start flash command execution.This command is used for
 *            STIG read and writes.
 *
 * \param     NONE.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
static QSPI_STATUS qspiFlashExecCmd(void)
{
    uint32_t retry = QSPI_REG_RETRY;
    uint32_t val;

    /* Start to execute */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
            QSPI_FLASH_CMD_CTRL_REG_CMD_EXEC_FLD, 1);
    while (retry--) {
        /* Check the command execution in progess */
        val = CSL_FEXT(hQspi->FLASH_CMD_CTRL_REG,
                QSPI_FLASH_CMD_CTRL_REG_CMD_EXEC_STATUS_FLD);
        if (!val) {
            break;
        }
        platform_delay(1);
    }
    if (!retry) {
        IFPRINT (platform_write("QSPI: flash command execution timeout\n"));
        return QSPI_ERR;
    }

    /* Polling QSPI idle status. */
    if (qspiWaitIdle()) {
        IFPRINT (platform_write("Poll for QSPI idle operation failed"));
        return QSPI_ERR;
    }

    return QSPI_SUCCESS;
}

/**
 * \brief     Read the data from SRAM FIFO.
 *
 * \param     dest  [IN]  : Data read from FIFO will be placed starting from
 *                          this address.
 * \param     bytes [IN]  : Number of bytes to be read.
 *
 * \return    NONE.
 *
 **/
static void qspiReadFifoData(void *dest, uint32_t bytes)
{
    uint32_t temp;
    uint32_t remaining = bytes;
    uint32_t *destPtr = (uint32_t *)dest;

    while(remaining > 0)
    {
        if (remaining >= QSPI_FIFO_WIDTH) {
            *destPtr = QSPI_0_DATA;
            remaining -= QSPI_FIFO_WIDTH;
        } else {
            temp = QSPI_0_DATA;
            memcpy(destPtr, &temp, remaining);
            break;
        }
        destPtr++;
    }
}

/**
 * \brief     Write the data into SRAM FIFO.
 *
 * \param     src   [IN] : Data starting from this address is written
 *                         into the FIFO.
 * \param     bytes [IN] : Number of bytes to be written.
 *
 * \return    NONE.
 *
 **/
static void qspiWriteFifoData(void *src, uint32_t bytes)
{
    uint32_t temp;
    uint32_t remaining = bytes;
    uint32_t *srcPtr = (uint32_t *)src;

    while (remaining > 0) {
        if (remaining >= QSPI_FIFO_WIDTH) {
            QSPI_0_DATA = *srcPtr;
            remaining -= QSPI_FIFO_WIDTH;
        } else {
            /* dangling bytes */
            memcpy(&temp, srcPtr, remaining);
            QSPI_0_DATA = temp;
            break;
        }
        srcPtr++;
    }
}

/**
 * \brief     To poll the SRAM FIFO and read the FLASH data.
 *
 * \param     destAddr  [IN]  : Pointer to the read data.
 * \param     numBytes  [IN]  : Number of bytes to be read.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
static QSPI_STATUS qspiReadSramFifoPoll(void *destAddr, uint32_t numBytes)
{
    uint32_t remaining = numBytes;
    uint32_t retry;
    uint32_t sramLevel = 0;
    uint8_t * dest = (uint8_t *)destAddr;

    while(remaining > 0)
    {
        retry = QSPI_REG_RETRY;
        while(retry--) {
            sramLevel = CSL_FEXT(hQspi->SRAM_FILL_REG,
                    QSPI_SRAM_FILL_REG_SRAM_FILL_INDAC_READ_FLD);
            if (sramLevel) {
                break;
            }
            platform_delay(10);
        }
        if (!retry) {
            IFPRINT (platform_write("QSPI: No receive data after"
                        " polling for %d times\n",
                        QSPI_REG_RETRY));
            return QSPI_ERR;
        }
        sramLevel *= QSPI_FIFO_WIDTH;
        sramLevel = sramLevel > remaining ? remaining : sramLevel;

        /* Read data from FIFO. */
        qspiReadFifoData(dest, sramLevel);

        dest += sramLevel;
        remaining -= sramLevel;
        platform_delay(1);
    }
    return QSPI_SUCCESS;
}

/**
 * \brief     To poll and push the data into SRAM FIFO to write into
 *            FLASH device.
 *
 * \param     srcAddr  [IN]  : Pointer to the data to be written.
 * \param     numBytes [IN]  : Number of bytes to be written.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 **/
static QSPI_STATUS qpsiWriteSramFifoPush(void *srcAddr, uint32_t numBytes)
{
    uint32_t retry = QSPI_REG_RETRY;
    uint32_t sramLevel;
    uint32_t sramThresholdWords = QSPI_REG_SRAM_THRESHOLD_WORDS;
    uint8_t *src = (uint8_t *)srcAddr;

    if (numBytes > 0) {
        retry = QSPI_REG_RETRY;
        while(retry--) {
            sramLevel = CSL_FEXT(hQspi->SRAM_FILL_REG,
                    QSPI_SRAM_FILL_REG_SRAM_FILL_INDAC_WRITE_FLD);
            if (sramLevel <= sramThresholdWords) {
                break;
            }
        }
        if (!retry) {
            IFPRINT (platform_write("QSPI: SRAM fill level (0x%08x)"
                        " not hit lower expected level"
                        " (0x%08x)",sramLevel,
                        sramThresholdWords));
            return QSPI_ERR;
        }

        /* Write a page data into FIFO */
        qspiWriteFifoData(src, numBytes);
    }
    return QSPI_SUCCESS;
}

#if (PLATFORM_QSPI_FLASH_READ_IN)
/**
 * \brief     To send the command buffer to FLASH device before doing an
 *            Indirect read transfer.
 *
 * \param     readAddr [IN] : Data is read from the FLASH device starting
 *                                from this address.
 * \param     cmdBuf [IN]   : Pointer to the command sent to FLASH device.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
static QSPI_STATUS qspiIndirectReadSetup(uint32_t readAddr, uint8_t *cmdBuf)
{
    /* Opcode + Mode value + dummyCycles */
    if (cmdBuf == NULL) {
        platform_write("QSPI: Invalid input argument - cmdBuf\n");
        return QSPI_ERR;
    }

    /* Clear all status flags */
    CSL_FINS(hQspi->IRQ_STATUS_REG,
            QSPI_IRQ_STATUS_REG_INDRD_SRAM_FULL_FLD,
            QSPI_FIELD_INT_CLEAR_ALL);




    CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
                QSPI_DEV_INSTR_RD_CONFIG_REG_INSTR_TYPE_FLD, 0);

    CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
                QSPI_DEV_INSTR_RD_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD, 0);

    CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
            QSPI_DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD,
         cmdBuf[2]);

        CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
                QSPI_DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD,
             cmdBuf[1]);

    /* Configure Read Opcode */
      CSL_FINS(hQspi->DEV_INSTR_RD_CONFIG_REG,
              QSPI_DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD, cmdBuf[0]);

    /* Get Address */
        CSL_FINS(hQspi->INDIRECT_READ_XFER_START_REG,
                QSPI_INDIRECT_READ_XFER_START_REG_ADDR_FLD, readAddr);


    return QSPI_SUCCESS;
}

/**
 * \brief     To start the Indirect read command execution and
 *            to receive data from FLASH device.
 *
 * \param     rxBuf [IN]  : Pointer to the data to be received.
 * \param     rxLen [IN]  : Length of the data to be received in bytes.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
static QSPI_STATUS qspiIndirectReadExecute(uint8_t *rxBuf, uint32_t rxLen)
{
    uint32_t val;

    /* Indirect number of bytes */
    CSL_FINS(hQspi->INDIRECT_READ_XFER_NUM_BYTES_REG,
            QSPI_INDIRECT_READ_XFER_NUM_BYTES_REG_VALUE_FLD, rxLen);

    /* Indirect number of bytes */
    CSL_FINS(hQspi->INDIRECT_READ_XFER_WATERMARK_REG,
            QSPI_INDIRECT_READ_XFER_WATERMARK_REG_LEVEL_FLD, (rxLen >> 2));

    /* Start the indirect read transfer */
    CSL_FINS(hQspi->INDIRECT_READ_XFER_CTRL_REG,
            QSPI_INDIRECT_READ_XFER_CTRL_REG_START_FLD, 1);

    /* Read from SRAM FIFO with polling SRAM fill level */
    if (qspiReadSramFifoPoll((void *)rxBuf, rxLen)) {
        IFPRINT (platform_write("Reading SRAM FIFO failed"));
        goto err;
    }

    /* Check flash indirect controller completion status */
    val = CSL_FEXT(hQspi->INDIRECT_READ_XFER_CTRL_REG,
            QSPI_INDIRECT_READ_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD);
    if (!val) {
        IFPRINT (platform_write("Read operation is not completed\n"));
        goto err;
    }

    /* Clear indirect completion status */
    CSL_FINS(hQspi->INDIRECT_READ_XFER_CTRL_REG,
            QSPI_INDIRECT_READ_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD,
         1);

    /* Clear the interrupt status */
    CSL_FINS(hQspi->IRQ_STATUS_REG,
            QSPI_IRQ_STATUS_REG_INDIRECT_XFER_LEVEL_BREACH_FLD, 1);

    return QSPI_SUCCESS;

err :
    /* Cancel the indirect read */
    CSL_FINS(hQspi->INDIRECT_READ_XFER_CTRL_REG,
            QSPI_INDIRECT_READ_XFER_CTRL_REG_CANCEL_FLD, 1);

    return QSPI_ERR;
}

#endif /* #if (PLATFORM_QSPI_FLASH_READ_IN) */

#if (PLATFORM_QSPI_FLASH_WRITE_IN)
/**
 * \brief     To send the command buffer to FLASH device before doing an
 *            Indirect write transfer.
 *
 * \param     writeAddr [IN] : Data is written to the FLASH device
 *                             starting from this address.
 * \param     cmdBuf [IN]    : Pointer to the command sent to FLASH device
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
static QSPI_STATUS qspiIndirectWriteSetup(uint32_t writeAddr, uint8_t *cmdBuf)
{
    /* Opcode + Mode value */
    if (cmdBuf == NULL) {
        platform_write("QSPI: Invalid input argument - cmdBuf\n");
        return QSPI_ERR;
    }

    /* Set opcode */
    CSL_FINS(hQspi->DEV_INSTR_WR_CONFIG_REG,
            QSPI_DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD, cmdBuf[0]);

    CSL_FINS(hQspi->DEV_INSTR_WR_CONFIG_REG,
            QSPI_DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD,
         cmdBuf[1]);

    CSL_FINS(hQspi->DEV_INSTR_WR_CONFIG_REG,
                QSPI_DEV_INSTR_WR_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD, 0);

    CSL_FINS(hQspi->DEV_INSTR_WR_CONFIG_REG,
            QSPI_DEV_INSTR_WR_CONFIG_REG_DUMMY_WR_CLK_CYCLES_FLD,
             0);

    /* Set Indirect write transfer start address */
    CSL_FINS(hQspi->INDIRECT_WRITE_XFER_START_REG,
            QSPI_INDIRECT_WRITE_XFER_START_REG_ADDR_FLD, writeAddr);

    return QSPI_SUCCESS;
}

/**
 * \brief     To start the Indirect write command execution and
 *            transfer data to FLASH device.
 *
 * \param     txBuf [IN]  : Pointer to the data to be transferred.
 * \param     txLen [IN]  : Length of the data to be transferred in bytes.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
static QSPI_STATUS qspiIndirectWriteExecute(uint8_t *txBuf, uint32_t txLen)
{
    uint32_t sramLevel;
    uint32_t val;
    uint32_t retry;

    /* Configure the indirect write transfer bytes */
    CSL_FINS(hQspi->INDIRECT_WRITE_XFER_NUM_BYTES_REG,
            QSPI_INDIRECT_WRITE_XFER_NUM_BYTES_REG_VALUE_FLD, txLen);

    /* Indirect number of bytes */
        CSL_FINS(hQspi->INDIRECT_WRITE_XFER_WATERMARK_REG,
                QSPI_INDIRECT_WRITE_XFER_WATERMARK_REG_LEVEL_FLD, (txLen >> 2));
        /* Start the indirect write transfer */
    CSL_FINS(hQspi->INDIRECT_WRITE_XFER_CTRL_REG,
            QSPI_INDIRECT_WRITE_XFER_CTRL_REG_START_FLD, 1);



        /* Write to SRAM FIFO with polling SRAM fill level. */
    if (qpsiWriteSramFifoPush((void *)txBuf, txLen)) {
        IFPRINT (platform_write("Writing into SRAM FIFO failed"));
        goto err;
    }

    /* Wait until last write is completed (FIFO empty) */
    retry = QSPI_REG_RETRY;
    while (retry--) {
        sramLevel = CSL_FEXT(hQspi->SRAM_FILL_REG,
                QSPI_SRAM_FILL_REG_SRAM_FILL_INDAC_WRITE_FLD);
        if (sramLevel == 0) {
            break;
        }
        platform_delay(1);
    }

    if (sramLevel != 0) {
        IFPRINT (platform_write("QSPI: timeout for indirect write\n"));
        goto err;
    }

    /* Check flash indirect write controller status */
    retry = QSPI_REG_RETRY;
    while (retry--) {
        val = CSL_FEXT(hQspi->INDIRECT_WRITE_XFER_CTRL_REG,
                QSPI_INDIRECT_WRITE_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD);
        if (val) {
            break;
        }
        platform_delay(1);
    }

    if (!val) {
        IFPRINT (platform_write("QSPI: indirect completion status error"
                     " with reg 0x%08x\n", val));
        goto err;
    }

    /* Clear indirect completion status */
    CSL_FINS(hQspi->INDIRECT_WRITE_XFER_CTRL_REG,
            QSPI_INDIRECT_WRITE_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD, 1);

    return QSPI_SUCCESS;

err :
    /* Cancel the indirect write */
    CSL_FINS(hQspi->INDIRECT_WRITE_XFER_CTRL_REG,
            QSPI_INDIRECT_WRITE_XFER_CTRL_REG_CANCEL_FLD, 1);

    return QSPI_ERR;
}

#endif /* #if (PLATFORM_QSPI_FLASH_WRITE_IN) */

/**
 * \brief     To perform STIG write.It sends command and writes data into
 *            FLASH device.This is used for sending commands WRR,WREN, WRDI, BE,
 *            SE etc..
 *
 * \param     cmdBuf [IN] : Command sent to FLASH device.
 * \param     cmdLen [IN] : Length of the command in bytes.
 * \param     txBuf  [IN] : Pointer to the data to be transferred.
 * \param     txLen  [IN] : Length of the data to be transferred in bytes.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
QSPI_STATUS qspiCommandWrite(uint8_t *cmdBuf, uint32_t cmdLen, uint8_t *txBuf,
                             uint32_t txLen)
{
    uint32_t wrData;
    uint32_t wrLen;
    uint32_t addrVal;

    if ((!cmdLen) || (cmdLen > 5) || (txLen > 8) || (cmdBuf == NULL)) {
        IFPRINT (platform_write("QSPI: Invalid input arguments cmdlen %d"
                    " txlen %d\n", cmdLen, txLen));
        return QSPI_ERR;
    }

    if (cmdBuf[0] == QSPI_FLASH_CMD_WREN)
    {
        CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD, 1);

        CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_ENB_QSPI_FLD, 1);
    }
    CSL_FINS(hQspi->CONFIG_REG, QSPI_CONFIG_REG_ENB_QSPI_FLD, 1);

    /* Opcode */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
         QSPI_FLASH_CMD_CTRL_REG_CMD_OPCODE_FLD, cmdBuf[0]);

    /* Disable reading of data */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
         QSPI_FLASH_CMD_CTRL_REG_ENB_READ_DATA_FLD, 0);

    /* Number of bytes to write. */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
        QSPI_FLASH_CMD_CTRL_REG_NUM_RD_DATA_BYTES_FLD, 0);

    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
         QSPI_FLASH_CMD_CTRL_REG_ENB_WRITE_DATA_FLD, 0);

    /* Number of bytes to write. */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
        QSPI_FLASH_CMD_CTRL_REG_NUM_WR_DATA_BYTES_FLD, 0);

    /* Command with address */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
         QSPI_FLASH_CMD_CTRL_REG_ENB_COMD_ADDR_FLD, 0);
    /* Number of bytes to write. */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
         QSPI_FLASH_CMD_CTRL_REG_NUM_ADDR_BYTES_FLD, 0);

    if ((cmdLen == 4) || (cmdLen == 5)) {

                /* We also can disable reading of data here. */
        if (cmdBuf[0] == QSPI_FLASH_CMD_SECTOR_ERASE)
        {
            /* Disable reading of data */
            CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
                    QSPI_FLASH_CMD_CTRL_REG_ENB_READ_DATA_FLD, 0);

            /* Number of bytes to write. */
            CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
                    QSPI_FLASH_CMD_CTRL_REG_NUM_RD_DATA_BYTES_FLD, 0);

            /* Command with address */
            CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
                 QSPI_FLASH_CMD_CTRL_REG_ENB_COMD_ADDR_FLD, 1);
            /* Number of bytes to write. */
            CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
                 QSPI_FLASH_CMD_CTRL_REG_NUM_ADDR_BYTES_FLD, 2);
        }
        else
        {
            /* Command with address */
            CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
                 QSPI_FLASH_CMD_CTRL_REG_ENB_COMD_ADDR_FLD, 1);
            /* Number of bytes to write. */
            CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
                 QSPI_FLASH_CMD_CTRL_REG_NUM_ADDR_BYTES_FLD,
                 (cmdLen - 2));
        }
        /* Get address */
        addrVal = qspiCmd2Addr(&cmdBuf[1], (cmdLen-1));
        CSL_FINS(hQspi->FLASH_CMD_ADDR_REG,
             QSPI_FLASH_CMD_ADDR_REG_ADDR_FLD, addrVal);

    }

    if (txLen) {
        /* Writing data */
        CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
             QSPI_FLASH_CMD_CTRL_REG_ENB_WRITE_DATA_FLD, 1);
        CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
             QSPI_FLASH_CMD_CTRL_REG_NUM_WR_DATA_BYTES_FLD,
             (txLen - 1));

        wrLen = txLen > 4 ? 4 : txLen;
        memcpy(&wrData, txBuf, wrLen);
        CSL_FINS(hQspi->FLASH_WR_DATA_LOWER_REG,
             QSPI_FLASH_WR_DATA_LOWER_REG_DATA_FLD, wrData);


        if (txLen > 4) {
            txBuf += wrLen;
            wrLen = txLen - wrLen;
            memcpy(&wrData, txBuf, wrLen);
            CSL_FINS(hQspi->FLASH_WR_DATA_UPPER_REG,
                 QSPI_FLASH_WR_DATA_UPPER_REG_DATA_FLD, wrData);

        }
    }
    /* Execute the command */
    return (qspiFlashExecCmd());
}

/**
 * \brief     To perform STIG read.It sends command and recieves the response
 *            data from FLASH device.This is used for sending command RDID,RDSR.
 *
 * \param     cmdBuf [IN] : Command sent to FLASH device.
 * \param     cmdLen [IN] : Length of the command in bytes.
 * \param     rxBuf  [IN] : Pointer to the received data.
 * \param     rxLen  [IN] : Length of the received data in bytes.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
QSPI_STATUS qspiCommandRead(uint8_t *cmdBuf, uint32_t cmdLen, uint8_t *rxBuf,
                            uint32_t rxLen)
{
    uint32_t read;
    uint32_t readLen;

    if ((!cmdLen) || (rxLen > 8) || (rxBuf == NULL)) {
        IFPRINT (platform_write("QSPI: Invalid input arguments cmdlen"
                    " %d rxlen %d\n", cmdLen, rxLen));
        return QSPI_ERR;
    }

    /* Opcode */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
         QSPI_FLASH_CMD_CTRL_REG_CMD_OPCODE_FLD, cmdBuf[0]);

    /* Enable reading of data */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
         QSPI_FLASH_CMD_CTRL_REG_ENB_READ_DATA_FLD, 1);

    /* Write (n - 1) byte. */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
         QSPI_FLASH_CMD_CTRL_REG_NUM_RD_DATA_BYTES_FLD, rxLen - 1);

    CSL_FINS(hQspi->FLASH_CMD_ADDR_REG,
                 QSPI_FLASH_CMD_ADDR_REG_ADDR_FLD, 0);

    /* Set Indirect number of bytes to 0*/
    CSL_FINS(hQspi->INDIRECT_READ_XFER_NUM_BYTES_REG,
            QSPI_INDIRECT_READ_XFER_NUM_BYTES_REG_VALUE_FLD, 0);

    /* Set Indirect read xfer watermark, which is set previously to 0 */
    CSL_FINS(hQspi->INDIRECT_READ_XFER_WATERMARK_REG,
            QSPI_INDIRECT_READ_XFER_WATERMARK_REG_LEVEL_FLD, 0);

    /* Set Address to 0*/
    CSL_FINS(hQspi->INDIRECT_READ_XFER_START_REG,
            QSPI_INDIRECT_READ_XFER_START_REG_ADDR_FLD, 0);

    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
         QSPI_FLASH_CMD_CTRL_REG_ENB_WRITE_DATA_FLD, 0);

    /* Set Number of bytes to write to 0. */
    CSL_FINS(hQspi->FLASH_CMD_CTRL_REG,
        QSPI_FLASH_CMD_CTRL_REG_NUM_WR_DATA_BYTES_FLD, 0);


    if (qspiFlashExecCmd()) {
        return QSPI_ERR;
    }

    read = CSL_FEXT(hQspi->FLASH_RD_DATA_LOWER_REG,
            QSPI_FLASH_RD_DATA_LOWER_REG_DATA_FLD);

    /* Put the read value into rxBuf */
    readLen = (rxLen > 4) ? 4 : rxLen;
    memcpy(rxBuf, &read, readLen);
    rxBuf += readLen;

    if (rxLen > 4) {
        read = CSL_FEXT(hQspi->FLASH_RD_DATA_UPPER_REG,
                QSPI_FLASH_RD_DATA_UPPER_REG_DATA_FLD);
        readLen = rxLen - readLen;
        memcpy(rxBuf, &read, readLen);
    }

    return QSPI_SUCCESS;
}

#if (PLATFORM_QSPI_FLASH_WRITE_IN)
/**
 * \brief     To perform Indirect Write Transfer.
 *
 * \param     addr    [IN] : FLASH device start address from where indirect
 *                           access will commence its write operation.
 * \param     cmd     [IN] : Command sent to FLASH device.
 * \param     txBuf   [IN] : Pointer to the data to be transferred.
 * \param     txLen   [IN] : Length of the data to be transferred in bytes.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
QSPI_STATUS qspiWrite(uint32_t addr, uint8_t* cmd, uint8_t* txBuf,
                      uint32_t txLen)
{
    QSPI_STATUS ret;

    ret = qspiIndirectWriteSetup(addr, cmd);
    if (ret) {
        IFPRINT (platform_write("Failed to do indirect write setup\n"));
        goto err;
    }
    ret = qspiIndirectWriteExecute(txBuf, txLen);
err :
    return ret;
}
#endif /* #if (PLATFORM_QSPI_FLASH_WRITE_IN) */

#if (PLATFORM_QSPI_FLASH_READ_IN)
/**
 * \brief     To perform Indirect Read Transfer.
 *
 * \param     addr    [IN] : FLASH device start address from where indirect
 *                           access will commence its read operation.
 * \param     cmd     [IN] : Command sent to FLASH device.
 * \param     rxBuf   [IN] : Pointer to the received data.
 * \param     rxLen   [IN] : Length of the received data in bytes.
 *
 * \return    QSPI_SUCCESS : if success.
 *            QSPI_ERR     : if error.
 *
 **/
QSPI_STATUS qspiRead(uint32_t addr, uint8_t* cmd, uint8_t* rxBuf,
                     uint32_t rxLen)
{
    QSPI_STATUS ret;

    ret = qspiIndirectReadSetup(addr, cmd);
    if (ret) {
        platform_write("Failed to do indirect read setup\n");
        goto err;
    }
    ret = qspiIndirectReadExecute(rxBuf, rxLen);
err :
    return ret;
}
#endif /* #if (PLATFORM_QSPI_FLASH_READ_IN) */

/**
 * \brief     To initialize QSPI module.This function should be called before
 *            using any other QSPI functions.
 *
 * \param     FlashpageSize : Page size of the FLASH device connected.
 *
 * \return    QSPI_SUCCESS  : if success.
 *            QSPI_ERR      : if error.
 */
QSPI_STATUS qspiInit(uint32_t FlashpageSize)
{
    QSPI_STATUS ret;

    /* Intialize the QSPI controller */
    ret = qspiControllerInit(FlashpageSize);

    return ret;
}

#endif /* #if (PLATFORM_QSPI_FLASH_IN) */

/* Nothing past this point */
