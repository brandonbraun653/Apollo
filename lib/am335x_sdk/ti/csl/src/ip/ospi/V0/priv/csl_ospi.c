/**
 *  \file   csl_ospi.c
 *
 *  \brief  OSPI IP V0 controller hardware abstraction APIs.
 *
 *   This file contains the hardware abstraction layer APIs for OSPI.
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
#include <csl_types.h>
#include <ti/csl/src/ip/ospi/V0/csl_ospi.h>

/*******************************************************************************
*                        API FUNCTION DEFINITIONS
*******************************************************************************/

void CSL_ospiEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                    uint32_t                      enable)
{
    CSL_REG32_FINS(&pRegs->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENB_SPI_FLD,
                   enable);
}

void CSL_ospiDacEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32_t                      enable)
{
    CSL_REG32_FINS(&pRegs->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD,
                   enable);
}

void CSL_ospiXipEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32_t                      enable)
{
    CSL_REG32_FINS(&pRegs->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENTER_XIP_MODE_FLD,
                   enable);
}

void CSL_ospiSetModeBits(const CSL_ospi_flash_cfgRegs *pRegs,
                          uint32_t                      flashModeVal)
{
    CSL_REG32_FINS(&pRegs->MODE_BIT_CONFIG_REG,
                   OSPI_FLASH_CFG_MODE_BIT_CONFIG_REG_MODE_FLD,
                   flashModeVal);

}

void CSL_ospiPhyEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32_t                      enable)
{
    CSL_REG32_FINS(&pRegs->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_PHY_MODE_ENABLE_FLD,
                   enable);
}

void CSL_ospiPipelinePhyEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t enable)
{
    CSL_REG32_FINS(&pRegs->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_PIPELINE_PHY_FLD,
                   enable);
}

void CSL_ospiDtrEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t enable)
{
    CSL_REG32_FINS(&pRegs->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_ENABLE_DTR_PROTOCOL_FLD,
                   enable);
    CSL_REG32_FINS(&pRegs->DEV_INSTR_RD_CONFIG_REG,
                   OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DDR_EN_FLD,
                   enable);
}

void CSL_ospiSetPreScaler(const CSL_ospi_flash_cfgRegs *pRegs,
                          uint32_t                      clkDividerVal)
{
    CSL_REG32_FINS(&pRegs->CONFIG_REG,
                   OSPI_FLASH_CFG_CONFIG_REG_MSTR_BAUD_DIV_FLD,
                   clkDividerVal);

}

void CSL_ospiSetClkMode(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32_t                      clkMode)
{
    uint32_t regVal = CSL_REG32_RD(&pRegs->CONFIG_REG);

    regVal &= ~(CSL_OSPI_FLASH_CFG_CONFIG_REG_SEL_CLK_PHASE_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_CONFIG_REG_SEL_CLK_POL_FLD_MASK);
    regVal |= clkMode;
    CSL_REG32_WR(&pRegs->CONFIG_REG, regVal);
}

void CSL_ospiSetChipSelect(const CSL_ospi_flash_cfgRegs *pRegs,
                           uint32_t                      chipSelect,
                           uint32_t                      decSelect)
{
    uint32_t regVal = CSL_REG32_RD(&pRegs->CONFIG_REG);
	uint32_t cs = CSL_OSPI_CHIP_SELECT(chipSelect);

    regVal &= ~(CSL_OSPI_FLASH_CFG_CONFIG_REG_PERIPH_SEL_DEC_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_CONFIG_REG_PERIPH_CS_LINES_FLD_MASK);
    regVal |= (decSelect << CSL_OSPI_FLASH_CFG_CONFIG_REG_PERIPH_SEL_DEC_FLD_SHIFT) | \
              (cs << CSL_OSPI_FLASH_CFG_CONFIG_REG_PERIPH_CS_LINES_FLD_SHIFT);
    CSL_REG32_WR(&pRegs->CONFIG_REG, regVal);
}

void CSL_ospiSetDevDelay(const CSL_ospi_flash_cfgRegs *pRegs,
                         const uint32_t               *delays)
{
    uint32_t delay = ((delays[0] << CSL_OSPI_FLASH_CFG_DEV_DELAY_REG_D_INIT_FLD_SHIFT)  | \
	                  (delays[1] << CSL_OSPI_FLASH_CFG_DEV_DELAY_REG_D_AFTER_FLD_SHIFT) | \
	                  (delays[2] << CSL_OSPI_FLASH_CFG_DEV_DELAY_REG_D_BTWN_FLD_SHIFT)  | \
	                  (delays[3] << CSL_OSPI_FLASH_CFG_DEV_DELAY_REG_D_NSS_FLD_SHIFT));
    CSL_REG32_WR(&pRegs->DEV_DELAY_REG, delay);
}

void CSL_ospiSetDevSize(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32_t                      numAddrBytes,
                        uint32_t                      pageSize,
                        uint32_t                      blkSize)
{
    uint32_t regVal = CSL_REG32_RD(&pRegs->DEV_SIZE_CONFIG_REG);

    regVal &= ~(CSL_OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_NUM_ADDR_BYTES_FLD_MASK        | \
                CSL_OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_BYTES_PER_DEVICE_PAGE_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_BYTES_PER_SUBSECTOR_FLD_MASK);

    regVal |= (numAddrBytes << CSL_OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_NUM_ADDR_BYTES_FLD_SHIFT)    | \
              (pageSize << CSL_OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_BYTES_PER_DEVICE_PAGE_FLD_SHIFT) | \
              (blkSize << CSL_OSPI_FLASH_CFG_DEV_SIZE_CONFIG_REG_BYTES_PER_SUBSECTOR_FLD_SHIFT);

    CSL_REG32_WR(&pRegs->DEV_SIZE_CONFIG_REG, regVal);
}

void CSL_ospiSetIndTrigAddr(const CSL_ospi_flash_cfgRegs *pRegs,
                            uint32_t                      indTrigAddr)
{
    CSL_REG32_WR(&pRegs->IND_AHB_ADDR_TRIGGER_REG, indTrigAddr);
}

void CSL_ospiSetWrCompAutoPolling(const CSL_ospi_flash_cfgRegs *pRegs,
                                  uint32_t                      pollingState)
{
    if (pollingState)
    {
        CSL_REG32_FINS(&pRegs->WRITE_COMPLETION_CTRL_REG,
                       OSPI_FLASH_CFG_WRITE_COMPLETION_CTRL_REG_DISABLE_POLLING_FLD,
                       1U);
    }
    else
    {
        CSL_REG32_FINS(&pRegs->WRITE_COMPLETION_CTRL_REG,
                       OSPI_FLASH_CFG_WRITE_COMPLETION_CTRL_REG_DISABLE_POLLING_FLD,
                       0);
        CSL_REG32_FINS(&pRegs->WRITE_COMPLETION_CTRL_REG,
                       OSPI_FLASH_CFG_WRITE_COMPLETION_CTRL_REG_POLL_COUNT_FLD,
                       3U);
    }
}

void CSL_ospiSetSramPartition(const CSL_ospi_flash_cfgRegs *pRegs,
                              uint32_t                      partition)
{
    CSL_REG32_WR(&pRegs->SRAM_PARTITION_CFG_REG, partition);
}

void CSL_ospiIntrEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32_t                      intrFlag,
                        uint32_t                      enable)
{
    uint32_t regVal = CSL_REG32_RD(&pRegs->IRQ_MASK_REG);

    if (enable == TRUE)
    {
        regVal |= intrFlag;
    }
    else
    {
        regVal &= ~(intrFlag);
    }
    CSL_REG32_WR(&pRegs->IRQ_MASK_REG, regVal);
}

uint32_t CSL_ospiIntrStatus(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32_t regVal = CSL_REG32_RD(&pRegs->IRQ_STATUS_REG);
    return (regVal);
}

void CSL_ospiIntrClear(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32_t                      intrFlag)
{
    CSL_REG32_WR(&pRegs->IRQ_STATUS_REG, intrFlag);
}

static uint32_t CSL_ospiCmd2Addr(const uint8_t *addrBuf, uint32_t addrWidth); /* for misra warnings */
static uint32_t CSL_ospiCmd2Addr(const uint8_t *addrBuf, uint32_t addrWidth)
{
    uint32_t addr;

    addr = ((uint32_t)addrBuf[0] << 16U) | ((uint32_t)addrBuf[1] << 8U) |
        addrBuf[2];

    /* Extended addressing : 4 byte address */
    if (addrWidth == 4U) {
        addr = (addr << 8) | (uint32_t)addrBuf[3];
    }

    return addr;
}

void CSL_ospiFlashExecCmd(const CSL_ospi_flash_cfgRegs *pRegs)
{
    /* Start to execute */
    CSL_REG32_FINS(&pRegs->FLASH_CMD_CTRL_REG,
                   OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_CMD_EXEC_FLD,
                   1);
}

uint32_t CSL_ospiFlashExecCmdComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32_t status;
    uint32_t retVal;

    /* Check the command execution in progess */
    status = CSL_REG32_FEXT(&pRegs->FLASH_CMD_CTRL_REG,
                            OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_CMD_EXEC_STATUS_FLD);
    if (status == 0U)
    {
        retVal = TRUE;
    }
    else
    {
        retVal = FALSE;
    }

    return (retVal);
}

int32_t CSL_ospiCmdRead(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32_t                      cmd,
                        uint32_t                      rxLen)
{
    uint32_t regVal;
    uint32_t val;
    uint32_t dummyCycles;

    /* Check if DTR is enabled */
    val = CSL_REG32_FEXT(&pRegs->CONFIG_REG,
                         OSPI_FLASH_CFG_CONFIG_REG_ENABLE_DTR_PROTOCOL_FLD);
    if (val == 1U)
    {
        dummyCycles = 8U;
    }
    else
    {
        dummyCycles = 0U;
    }

    regVal =
        (cmd << CSL_OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_CMD_OPCODE_FLD_SHIFT) | \
        (CSL_OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_ENB_READ_DATA_FLD_MASK)      | \
        (rxLen << CSL_OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_RD_DATA_BYTES_FLD_SHIFT) | \
        (2U << CSL_OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_ADDR_BYTES_FLD_SHIFT) | \
        (dummyCycles << CSL_OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_DUMMY_CYCLES_FLD_SHIFT);
    CSL_REG32_WR(&pRegs->FLASH_CMD_CTRL_REG, regVal);

    return (CSL_PASS);
}

int32_t CSL_ospiCmdWrite(const CSL_ospi_flash_cfgRegs *pRegs,
                         const uint8_t                *cmdBuf,
                         uint32_t                      cmdLen,
                         const uint8_t                *txBuf,
                         uint32_t                      txLen)
{
    uint32_t regVal, cmdAddr, wrData, wrLen;

    regVal = (uint32_t)cmdBuf[0] << \
        CSL_OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_CMD_OPCODE_FLD_SHIFT;
    if (cmdLen > 1U)
    {
        /* Enable Command address in command control register */
        regVal |= CSL_OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_ENB_COMD_ADDR_FLD_MASK | \
            ((cmdLen - 2U) << CSL_OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_ADDR_BYTES_FLD_SHIFT);

        /* Set command address register */
        cmdAddr = CSL_ospiCmd2Addr(&cmdBuf[1], (cmdLen - 1U));
        CSL_REG32_WR(&pRegs->FLASH_CMD_ADDR_REG, cmdAddr);
    }

    if (txLen != 0U)
    {
        /* Enable write data in command control register */
        regVal |= CSL_OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_ENB_WRITE_DATA_FLD_MASK | \
            ((txLen - 1U) << CSL_OSPI_FLASH_CFG_FLASH_CMD_CTRL_REG_NUM_WR_DATA_BYTES_FLD_SHIFT);

        wrLen = txLen > 4U ? 4U : txLen;
        memcpy(&wrData, txBuf, wrLen);
        CSL_REG32_WR(&pRegs->FLASH_WR_DATA_LOWER_REG, wrData);


        if (txLen > 4U)
        {
            txBuf += wrLen;
            wrLen = txLen - wrLen;
            memcpy(&wrData, txBuf, wrLen);
            CSL_REG32_WR(&pRegs->FLASH_WR_DATA_UPPER_REG, wrData);
        }
    }
    CSL_REG32_WR(&pRegs->FLASH_CMD_CTRL_REG, regVal);
    return (CSL_PASS);
}

void CSL_ospiConfigRead(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32_t                      cmd,
                        uint32_t                      mode,
                        uint32_t                      dummyClk)
{
    uint32_t regVal = CSL_REG32_RD(&pRegs->DEV_INSTR_RD_CONFIG_REG);
    uint32_t dtr;
    uint32_t instType;

    /* Set instruction type to standard SPI mode for SDR mode */
    dtr = CSL_REG32_FEXT(&pRegs->CONFIG_REG,
                         OSPI_FLASH_CFG_CONFIG_REG_ENABLE_DTR_PROTOCOL_FLD);
    if (dtr == 1U)
    {
        instType = mode;
    }
    else
    {
        instType = 0U;
    }

    /* Configure the Device Write Instruction Configuration Register */
    regVal &= ~(CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_INSTR_TYPE_FLD_MASK              | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD_MASK       | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DDR_EN_FLD_MASK                  | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD_MASK);
    regVal |= (cmd << CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD_SHIFT)        | \
              (mode << CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_SHIFT) | \
              (mode << CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_SHIFT) | \
              (instType << CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_INSTR_TYPE_FLD_SHIFT)          | \
              (dummyClk << CSL_OSPI_FLASH_CFG_DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD_SHIFT);
    CSL_REG32_WR(&pRegs->DEV_INSTR_RD_CONFIG_REG, regVal);
}

void CSL_ospiReadFifoData(uintptr_t indAddr, uint8_t *dest, uint32_t rdLen)
{
    uint32_t temp;
    uint32_t remaining = rdLen;
    uint32_t *destPtr = (uint32_t *)dest;

    while(remaining > 0)
    {
        if (remaining >= CSL_OSPI_FIFO_WIDTH)
        {
            *destPtr = CSL_REG32_RD(indAddr);
            remaining -= CSL_OSPI_FIFO_WIDTH;
        }
        else
        {
            temp = CSL_REG32_RD(indAddr);
            memcpy(destPtr, &temp, remaining);
            break;
        }
        destPtr++;
    }
}

uint32_t CSL_ospiGetSramLvl(const CSL_ospi_flash_cfgRegs *pRegs,
                            uint32_t                      read)
{
    uint32_t sramLevel;

    if (read == TRUE)
    {
        sramLevel = CSL_REG32_RD(&pRegs->SRAM_FILL_REG) &
            CSL_OSPI_FLASH_CFG_SRAM_FILL_REG_SRAM_FILL_INDAC_READ_FLD_MASK;
    }
    else
    {
        sramLevel = CSL_REG32_RD(&pRegs->SRAM_FILL_REG) >> \
            CSL_OSPI_FLASH_CFG_SRAM_FILL_REG_SRAM_FILL_INDAC_WRITE_FLD_SHIFT;
    }

    return (sramLevel);
}

void CSL_ospiClrIndReadComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    CSL_REG32_FINS(&pRegs->INDIRECT_READ_XFER_CTRL_REG,
                   OSPI_FLASH_CFG_INDIRECT_READ_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD,
                   1);
}

uint32_t CSL_ospiIndReadComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32_t val;
    uint32_t retVal;

    /* Check flash indirect read controller status */
    val = CSL_REG32_FEXT(&pRegs->INDIRECT_READ_XFER_CTRL_REG,
                         OSPI_FLASH_CFG_INDIRECT_READ_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD);
    if (val == 1U)
    {
        retVal = TRUE;
    }
    else
    {
        retVal = FALSE;
    }

    return(retVal);
}

void CSL_ospiIndReadExecute(const CSL_ospi_flash_cfgRegs *pRegs,
                            uint32_t                      rxLen)
{
    /* Set the Indirect Write Transfer Start Address Register */
    CSL_REG32_WR(&pRegs->INDIRECT_READ_XFER_NUM_BYTES_REG, rxLen);

    /* Set the Indirect Write Transfer Watermark Register */
    CSL_REG32_WR(&pRegs->INDIRECT_READ_XFER_WATERMARK_REG,
                 CSL_OSPI_SRAM_WARERMARK_RD_LVL);

    /* Start the indirect read transfer */
    CSL_REG32_FINS(&pRegs->INDIRECT_READ_XFER_CTRL_REG,
                   OSPI_FLASH_CFG_INDIRECT_READ_XFER_CTRL_REG_START_FLD,
                   1);
}

void CSL_ospiWriteSetup(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32_t                      cmd,
                        uint32_t                      mode)
{
    uint32_t regVal = CSL_REG32_RD(&pRegs->DEV_INSTR_WR_CONFIG_REG);

    /* Configure the Device Write Instruction Configuration Register */
    regVal &= ~(CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD_MASK               | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_MASK | \
                CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_DUMMY_WR_CLK_CYCLES_FLD_MASK);
    regVal |= (cmd << CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD_SHIFT) | \
              (mode << CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_SHIFT) | \
              (mode << CSL_OSPI_FLASH_CFG_DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_SHIFT);
    CSL_REG32_WR(&pRegs->DEV_INSTR_WR_CONFIG_REG, regVal);
}

void CSL_ospiWriteFifoData(uintptr_t indAddr, const uint8_t *src, uint32_t wrLen)
{
    uint32_t temp;
    uint32_t remaining = wrLen;
    uint32_t *srcPtr = (uint32_t *)src;

    while (remaining > 0)
    {
        if (remaining >= CSL_OSPI_FIFO_WIDTH)
        {
            CSL_REG32_WR(indAddr, *srcPtr);
            remaining -= CSL_OSPI_FIFO_WIDTH;
        }
        else
        {
            /* dangling bytes */
            memcpy(&temp, srcPtr, remaining);
            CSL_REG32_WR(indAddr, temp);
            break;
        }
        srcPtr++;
    }
}

void CSL_ospiClrIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    CSL_REG32_FINS(&pRegs->INDIRECT_WRITE_XFER_CTRL_REG,
                   OSPI_FLASH_CFG_INDIRECT_WRITE_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD,
                   1);
}

uint32_t CSL_ospiIsIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32_t val;
    uint32_t retVal;

    /* Check flash indirect read controller status */
    val = CSL_REG32_FEXT(&pRegs->INDIRECT_WRITE_XFER_CTRL_REG,
                         OSPI_FLASH_CFG_INDIRECT_WRITE_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD);
    if (val == 1U)
    {
        retVal = TRUE;
    }
    else
    {
        retVal = FALSE;
    }

    return(retVal);
}


void CSL_ospiIndWriteExecute(const CSL_ospi_flash_cfgRegs *pRegs,
                             uint32_t                      txLen)
{
    /* Set the Indirect Write Transfer Start Address Register */
    CSL_REG32_WR(&pRegs->INDIRECT_WRITE_XFER_NUM_BYTES_REG, txLen);

    /* Reset watermark register */
    CSL_REG32_WR(&pRegs->INDIRECT_WRITE_XFER_WATERMARK_REG, 0);

    /* Set the Indirect Write Transfer Watermark Register */
    CSL_REG32_WR(&pRegs->INDIRECT_WRITE_XFER_WATERMARK_REG,
                 CSL_OSPI_SRAM_WATERMARK_WR_LVL);

    /* Start the indirect write transfer */
    CSL_REG32_FINS(&pRegs->INDIRECT_WRITE_XFER_CTRL_REG,
                   OSPI_FLASH_CFG_INDIRECT_WRITE_XFER_CTRL_REG_START_FLD,
                   1);
}

void CSL_ospiIndWriteCancel(const CSL_ospi_flash_cfgRegs *pRegs)
{
    /* Cancel the indirect write */
    CSL_REG32_FINS(&pRegs->INDIRECT_WRITE_XFER_CTRL_REG,
                   OSPI_FLASH_CFG_INDIRECT_WRITE_XFER_CTRL_REG_CANCEL_FLD,
                   1);
}

void CSL_ospiLoopbackClkEnable(const CSL_ospi_flash_cfgRegs *pRegs,
                               uint32_t                      enable)
{
    uint32_t enVal = enable?0:1;

    CSL_REG32_FINS(&pRegs->RD_DATA_CAPTURE_REG,
                   OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_BYPASS_FLD,
                   enVal);
}

uint32_t CSL_ospiIsIdle(const CSL_ospi_flash_cfgRegs *pRegs)
{
    uint32_t status;

    /* Read STATUS read-only bit */
    status = CSL_REG32_FEXT(&pRegs->CONFIG_REG,
                            OSPI_FLASH_CFG_CONFIG_REG_IDLE_FLD);
    return (status);
}

static void CSL_ospiPhyResyncDll(const CSL_ospi_flash_cfgRegs *pRegs);
static void CSL_ospiPhyResyncDll(const CSL_ospi_flash_cfgRegs *pRegs)
{
    /* Re-sync DLL */
    CSL_REG32_FINS(&pRegs->PHY_CONFIGURATION_REG,
                   OSPI_FLASH_CFG_PHY_CONFIGURATION_REG_PHY_CONFIG_RESYNC_FLD,
                   0U);
    CSL_REG32_FINS(&pRegs->PHY_CONFIGURATION_REG,
                   OSPI_FLASH_CFG_PHY_CONFIGURATION_REG_PHY_CONFIG_RESYNC_FLD,
                   1U);
}

void CSL_ospiConfigPhy(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32_t                      masterDelay,
                       const uint32_t               *pSlaveDelay)
{
    uint8_t                  twentyFivePercent;
    uint32_t                 rxDelay;
    uint32_t                 dtr;
    uint32_t                 dqsEnable;

    if (pSlaveDelay != NULL)
    {
        /* Set the initial DLL delay */

        /* Enable PHY */
        CSL_ospiPhyEnable(pRegs, TRUE);

        /* Reset DLL */
        CSL_REG32_FINS(&pRegs->PHY_CONFIGURATION_REG,
                       OSPI_FLASH_CFG_PHY_CONFIGURATION_REG_PHY_CONFIG_RESET_FLD,
                       0U);

        /* Configure sample edge */
        dtr = CSL_REG32_FEXT(&pRegs->CONFIG_REG,
                             OSPI_FLASH_CFG_CONFIG_REG_ENABLE_DTR_PROTOCOL_FLD);
        if (dtr == 1U)
        {
            dqsEnable  = 1U; /* DQS enabled */
        }
        else
        {
            dqsEnable  = 0U; /* DQS disabled */
        }
        /* sampled on rising edge of the ref_clk */
        CSL_REG32_FINS(&pRegs->RD_DATA_CAPTURE_REG,
                       OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_SAMPLE_EDGE_SEL_FLD,
                       CSL_OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_SAMPLE_EDGE_SEL_FLD_MAX);

        CSL_REG32_FINS(&pRegs->RD_DATA_CAPTURE_REG,
                       OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_DQS_ENABLE_FLD,
                       dqsEnable);

        twentyFivePercent = masterDelay / 4U; /* TX DLL delay, 25% of masterDelay */

        /* Set Initial delay for the master DLL */
        CSL_REG32_FINS(&pRegs->PHY_MASTER_CONTROL_REG,
                       OSPI_FLASH_CFG_PHY_MASTER_CONTROL_REG_PHY_MASTER_INITIAL_DELAY_FLD,
                       4U);

        /* Set TX DLL delay */
        CSL_REG32_FINS(&pRegs->PHY_CONFIGURATION_REG,
                       OSPI_FLASH_CFG_PHY_CONFIGURATION_REG_PHY_CONFIG_TX_DLL_DELAY_FLD,
                       twentyFivePercent);

        /* Re-sync DLL */
        CSL_ospiPhyResyncDll(pRegs);

        /* DLL out of reset */
        CSL_REG32_FINS(&pRegs->PHY_CONFIGURATION_REG,
                       OSPI_FLASH_CFG_PHY_CONFIGURATION_REG_PHY_CONFIG_RESET_FLD,
                       1U);

        /* Wait DLL lock done */
        while (CSL_REG32_FEXT(&pRegs->DLL_OBSERVABLE_LOWER_REG,
               OSPI_FLASH_CFG_DLL_OBSERVABLE_LOWER_REG_DLL_OBSERVABLE_LOWER_LOOPBACK_LOCK_FLD) == 0U);

        /* Re-sync slave DLLs */
        twentyFivePercent = 127U/4U + CSL_REG32_RD(pSlaveDelay);

        /* Set TX DLL delay */
        CSL_REG32_FINS(&pRegs->PHY_CONFIGURATION_REG,
                       OSPI_FLASH_CFG_PHY_CONFIGURATION_REG_PHY_CONFIG_TX_DLL_DELAY_FLD,
                       twentyFivePercent);
        /* Set RX DLL delay */
        CSL_REG32_FINS(&pRegs->PHY_CONFIGURATION_REG,
                       OSPI_FLASH_CFG_PHY_CONFIGURATION_REG_PHY_CONFIG_RX_DLL_DELAY_FLD,
                       twentyFivePercent);
        /* Re-sync DLL */
        CSL_ospiPhyResyncDll(pRegs);
    }
    else
    {
        /* Calibrate PHY */
        rxDelay = CSL_REG32_FEXT(&pRegs->PHY_CONFIGURATION_REG,
                                 OSPI_FLASH_CFG_PHY_CONFIGURATION_REG_PHY_CONFIG_RX_DLL_DELAY_FLD);
        if (rxDelay == 127U)
        {
            rxDelay = 0U;
        }
        else
        {
            rxDelay++;
        }

        /* Set TX DLL delay */
        CSL_REG32_FINS(&pRegs->PHY_CONFIGURATION_REG,
                       OSPI_FLASH_CFG_PHY_CONFIGURATION_REG_PHY_CONFIG_TX_DLL_DELAY_FLD,
                       rxDelay);
        /* Set RX DLL delay */
        CSL_REG32_FINS(&pRegs->PHY_CONFIGURATION_REG,
                       OSPI_FLASH_CFG_PHY_CONFIGURATION_REG_PHY_CONFIG_RX_DLL_DELAY_FLD,
                       rxDelay);
        /* Re-sync DLL */
        CSL_ospiPhyResyncDll(pRegs);
    }
}

void CSL_ospiFlashStig(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32_t                      cmd,
                       uint32_t                      addr,
                       uint32_t                      data)
{
    CSL_REG32_WR(&pRegs->FLASH_CMD_ADDR_REG, addr);
    CSL_REG32_WR(&pRegs->FLASH_WR_DATA_LOWER_REG, data);
    CSL_REG32_WR(&pRegs->FLASH_CMD_CTRL_REG, cmd);
}

void CSL_ospiIndSetStartAddr(const CSL_ospi_flash_cfgRegs *pRegs,
                             uint32_t                      startAddr,
                             uint32_t                      read)
{
    if (read == TRUE)
    {
        /* Config the Indirect Read Transfer Start Address Register */
        CSL_REG32_WR(&pRegs->INDIRECT_READ_XFER_START_REG, startAddr);
    }
    else
    {
        /* Configure the Indirect Write Transfer Start Address Register */
        CSL_REG32_WR(&pRegs->INDIRECT_WRITE_XFER_START_REG, startAddr);
    }
}

void CSL_ospiSetDataReadCapDelay(const CSL_ospi_flash_cfgRegs *pRegs,
                                 uint32_t                      delay)
{
    /* Set delay in ref_clk cycle for data read capture */
    CSL_REG32_FINS(&pRegs->RD_DATA_CAPTURE_REG,
                   OSPI_FLASH_CFG_RD_DATA_CAPTURE_REG_DELAY_FLD,
                   delay);
}

void CSL_ospiSetCsSotDelay(const CSL_ospi_flash_cfgRegs *pRegs,
                           uint32_t                      delay)
{
    /* Set Chip Select Start of Transfer delay in ref_clk cycle */
    CSL_REG32_FINS(&pRegs->DEV_DELAY_REG,
                   OSPI_FLASH_CFG_DEV_DELAY_REG_D_INIT_FLD,
                   delay);
}
