/**
 *  \file   qspi.c
 *
 *  \brief  QSPI IP V0 controller hardware abstraction APIs.
 *
 *   This file contains the hardware abstraction layer APIs for QSPI.
 */

/*
 * Copyright (C) 2016 - 2017 Texas Instruments Incorporated - http://www.ti.com/
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

#include "stdint.h"
#include <ti/csl/hw_types.h>
#if defined (_TMS320C6X)
#include <ti/csl/csl_chipAux.h>
#endif
#include <ti/csl/src/ip/qspi/V0/qspi.h>

/*******************************************************************************
*                        API FUNCTION DEFINITIONS
*******************************************************************************/

void QSPIEnable(uint32_t baseAddr)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_CONFIG_REG;
    HWREG(temp_addr) |= CSL_QSPI_CONFIG_REG_ENB_QSPI_FLD_MASK;
}

void QSPIDisable(uint32_t baseAddr)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_CONFIG_REG;
    HWREG(temp_addr) &= ~CSL_QSPI_CONFIG_REG_ENB_QSPI_FLD_MASK;
}

void QSPIDacEnable(uint32_t baseAddr)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_CONFIG_REG;
    HWREG(temp_addr) |= CSL_QSPI_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD_MASK;
}

void QSPIDacDisable(uint32_t baseAddr)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_CONFIG_REG;
    HWREG(temp_addr) &= ~CSL_QSPI_CONFIG_REG_ENB_DIR_ACC_CTLR_FLD_MASK;
}

#if defined(_TMS320C6X) || defined(gnu_targets_arm_A15F)
static uint32_t readTime32(void); /* for misra warnings */
static uint32_t readTime32(void)
{
    uint32_t timeVal;

#if defined (_TMS320C6X)
    timeVal = TSCL;
#else
    __asm__ __volatile__ ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(timeVal));
#endif
    return timeVal;
}
#endif

void QSPIdelay(uint32_t delayCount)
{
#if defined (_TMS320C6X) || defined(gnu_targets_arm_A15F)
    uint32_t start = readTime32();

    while ((readTime32() - start) < delayCount) {}
#else
    volatile uint32_t i;

    for (i = 0; i < delayCount; i++) {}
#endif
}

int32_t QSPIWaitIdle(uint32_t baseAddr)
{
	uint32_t idleStatus;
    uint32_t count = 0U;
    uint32_t timeOut = QSPI_POLL_IDLE_TIMEOUT;
    uint32_t temp_addr = 0;
    uint32_t retFlag = 0;
    int32_t  retVal = 0;

    while(timeOut)
    {
        QSPIdelay(QSPI_POLL_IDLE_DELAY);
        timeOut -= QSPI_POLL_IDLE_DELAY;

        temp_addr = baseAddr + CSL_QSPI_CONFIG_REG;
        /* Read STATUS read-only bit */
        idleStatus = HWREG(temp_addr) & \
            CSL_QSPI_CONFIG_REG_QSPI_IDLE_FLD_MASK;
        if (idleStatus) {
            /* Read few times in succession to ensure it does
               not transition low again */
            count++;
            if (count >= QSPI_POLL_IDLE_RETRY)
            {
                retFlag = 1U;
                retVal = 0;
                break;
            }
        }
        else
        {
            count = 0U;
	    }
    }
    if(retFlag == 0U)
    {
       retVal = -1; 
    }
    return (retVal);
}

void QSPISetPreScaler(uint32_t baseAddr, uint32_t clkDividerVal)
{
	uint32_t temp_addr = baseAddr + CSL_QSPI_CONFIG_REG;
    uint32_t configReg = HWREG(temp_addr);

    configReg &= ~(CSL_QSPI_CONFIG_REG_MSTR_BAUD_DIV_FLD_MASK);
    configReg |= (clkDividerVal << CSL_QSPI_CONFIG_REG_MSTR_BAUD_DIV_FLD_SHIFT);
    HWREG(temp_addr) = configReg;
}

void QSPISetClkMode(uint32_t baseAddr, uint32_t clkMode)
{
	uint32_t temp_addr = baseAddr + CSL_QSPI_CONFIG_REG;
    uint32_t configReg = HWREG(temp_addr);

    configReg &= ~(CSL_QSPI_CONFIG_REG_SEL_CLK_PHASE_FLD_MASK | \
                   CSL_QSPI_CONFIG_REG_SEL_CLK_POL_FLD_MASK);
    configReg |= clkMode;
    HWREG(temp_addr) = configReg;
}

void QSPISetChipSelect(uint32_t baseAddr, uint32_t chipSelect, uint32_t decSelect)
{
	uint32_t temp_addr = baseAddr + CSL_QSPI_CONFIG_REG;
    uint32_t configReg = HWREG(temp_addr);
	uint32_t cs = QSPI_CHIP_SELECT(chipSelect);

    configReg &= ~(CSL_QSPI_CONFIG_REG_PERIPH_SEL_DEC_FLD_MASK | \
                   CSL_QSPI_CONFIG_REG_PERIPH_CS_LINES_FLD_MASK);
    configReg |= (decSelect << CSL_QSPI_CONFIG_REG_PERIPH_SEL_DEC_FLD_SHIFT) | \
                 (cs << CSL_QSPI_CONFIG_REG_PERIPH_CS_LINES_FLD_SHIFT);
    HWREG(temp_addr) = configReg;
}

void QSPISetDevDelay(uint32_t baseAddr, const uint32_t *delays)
{
    uint32_t delay = ((delays[0] << CSL_QSPI_DEV_DELAY_REG_D_INIT_FLD_SHIFT)  | \
	                  (delays[1] << CSL_QSPI_DEV_DELAY_REG_D_AFTER_FLD_SHIFT) | \
	                  (delays[2] << CSL_QSPI_DEV_DELAY_REG_D_BTWN_FLD_SHIFT)  | \
	                  (delays[3] << CSL_QSPI_DEV_DELAY_REG_D_NSS_FLD_SHIFT));
    uint32_t temp_addr = baseAddr + CSL_QSPI_DEV_DELAY_REG;
    HWREG(temp_addr) = delay;
}

void QSPISetDevSize(uint32_t baseAddr, uint32_t numAddrBytes, uint32_t pageSize, uint32_t blkSize)
{
	uint32_t temp_addr = baseAddr + CSL_QSPI_DEV_SIZE_CONFIG_REG;
    uint32_t configReg = HWREG(temp_addr);

    configReg &= ~(CSL_QSPI_DEV_SIZE_CONFIG_REG_NUM_ADDR_BYTES_FLD_MASK        | \
                   CSL_QSPI_DEV_SIZE_CONFIG_REG_BYTES_PER_DEVICE_PAGE_FLD_MASK | \
                   CSL_QSPI_DEV_SIZE_CONFIG_REG_BYTES_PER_SUBSECTOR_FLD_MASK);

    configReg |= (numAddrBytes << CSL_QSPI_DEV_SIZE_CONFIG_REG_NUM_ADDR_BYTES_FLD_SHIFT)    | \
                 (pageSize << CSL_QSPI_DEV_SIZE_CONFIG_REG_BYTES_PER_DEVICE_PAGE_FLD_SHIFT) | \
                 (blkSize << CSL_QSPI_DEV_SIZE_CONFIG_REG_BYTES_PER_SUBSECTOR_FLD_SHIFT);

    HWREG(temp_addr) = configReg;
}

void QSPISetIndTrigAddr(uint32_t baseAddr, uint32_t indTrigAddr)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_IND_AHB_ADDR_TRIGGER_REG;
    HWREG(temp_addr) = indTrigAddr;
}

void QSPISetWrCompAutoPolling(uint32_t baseAddr, uint32_t pollingState)
{
	uint32_t temp_addr = baseAddr + CSL_QSPI_WRITE_COMPLETION_CTRL_REG;
    if (pollingState)
    {
	    HWREG(temp_addr) |= \
	        CSL_QSPI_WRITE_COMPLETION_CTRL_REG_DISABLE_POLLING_FLD_MASK;
    }
    else
    {
	    HWREG(temp_addr) &= \
	        ~CSL_QSPI_WRITE_COMPLETION_CTRL_REG_DISABLE_POLLING_FLD_MASK;
    }
}

void QSPISetSramPartition(uint32_t baseAddr, uint32_t partition)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_SRAM_PARTITION_CFG_REG;
    HWREG(temp_addr) = partition;
}

void QSPIIntrEnable(uint32_t baseAddr, uint32_t intrFlag)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_IRQ_MASK_REG;
    HWREG(temp_addr) |= intrFlag;
}

void QSPIIntrDisable(uint32_t baseAddr, uint32_t intrFlag)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_IRQ_MASK_REG;
    uint32_t regVal = HWREG(temp_addr);

    regVal &= ~(intrFlag);
    HWREG(temp_addr) = regVal;
}

uint32_t QSPIIntrStatus(uint32_t baseAddr)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_IRQ_STATUS_REG;
    return (HWREG(temp_addr));
}

void QSPIIntrClear(uint32_t baseAddr, uint32_t intrFlag)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_IRQ_STATUS_REG;
    HWREG(temp_addr) = intrFlag;
}

static uint32_t QSPICmd2Addr(const uint8_t *addrBuf, uint32_t addrWidth); /* for misra warnings */
static uint32_t QSPICmd2Addr(const uint8_t *addrBuf, uint32_t addrWidth)
{
    uint32_t addr;

    addr = ((uint32_t)addrBuf[0] << 16) | ((uint32_t)addrBuf[1] << 8) |
        addrBuf[2];

    /* Extended addressing : 4 byte address */
    if (addrWidth == 4U) {
        addr = (addr << 8) | (uint32_t)addrBuf[3];
    }

    return addr;
}

int32_t qspiFlashExecCmd(uint32_t baseAddr); /* for misra warnings */
int32_t qspiFlashExecCmd(uint32_t baseAddr)
{
    uint32_t retry = QSPI_REG_RETRY;
    uint32_t val;
    uint32_t temp_addr = baseAddr + CSL_QSPI_FLASH_CMD_CTRL_REG;
    int32_t  retVal = 0;

    /* Start to execute */
    HWREG(temp_addr) |= \
        CSL_QSPI_FLASH_CMD_CTRL_REG_CMD_EXEC_FLD_MASK;

    while (retry--) {
        /* Check the command execution in progess */
        val = HWREG(temp_addr) & \
            CSL_QSPI_FLASH_CMD_CTRL_REG_CMD_EXEC_STATUS_FLD_MASK;
        if (val == 0U) {
            break;
        }
        QSPIdelay(QSPI_POLL_IDLE_DELAY);
    }
    if (retry == 0U) {
        retVal = -1;
    }

    /* Polling QSPI idle status. */
    if (QSPIWaitIdle(baseAddr)) {
        retVal = -1;
    }

    return (retVal);
}

int32_t QSPICmdRead(uint32_t baseAddr,
                    uint32_t cmd,
                    uint8_t *rxBuf,
                    uint32_t rxLen)
{
    uint32_t rdData;
    uint32_t rdLen;
    uint32_t temp_addr = baseAddr + CSL_QSPI_FLASH_CMD_CTRL_REG;
    int32_t  retVal = 0;

    HWREG(temp_addr) =
        (cmd << CSL_QSPI_FLASH_CMD_CTRL_REG_CMD_OPCODE_FLD_SHIFT) | \
        (CSL_QSPI_FLASH_CMD_CTRL_REG_ENB_READ_DATA_FLD_MASK)      | \
        ((rxLen - 1U) << CSL_QSPI_FLASH_CMD_CTRL_REG_NUM_RD_DATA_BYTES_FLD_SHIFT);

    if (qspiFlashExecCmd(baseAddr))
    {
        retVal = -1;
    }
    else
    {
        temp_addr = baseAddr + CSL_QSPI_FLASH_RD_DATA_LOWER_REG;
        rdData = HWREG(temp_addr);

        /* Put the read value into rxBuf */
        rdLen = (rxLen > 4U) ? 4U : rxLen;
        memcpy(rxBuf, &rdData, rdLen);
        rxBuf += rdLen;

        if (rxLen > 4U) {
            temp_addr = baseAddr + CSL_QSPI_FLASH_RD_DATA_UPPER_REG;
            rdData = HWREG(temp_addr);
            rdLen = rxLen - rdLen;
            memcpy(rxBuf, &rdData, rdLen);
        }
    }
    return (retVal);
}

int32_t QSPICmdWrite(uint32_t baseAddr,
                     const uint8_t *cmdBuf,
                     uint32_t cmdLen,
                     const uint8_t *txBuf,
                     uint32_t txLen)
{
    uint32_t configReg, cmdAddr, wrData, wrLen;
    uint32_t temp_addr = 0;
    
    configReg = (uint32_t)cmdBuf[0] << \
        CSL_QSPI_FLASH_CMD_CTRL_REG_CMD_OPCODE_FLD_SHIFT;
    if (cmdLen > 1U)
    {
        /* Enable Command address in command control register */
        configReg |= CSL_QSPI_FLASH_CMD_CTRL_REG_ENB_COMD_ADDR_FLD_MASK | \
            ((cmdLen - 2U) << CSL_QSPI_FLASH_CMD_CTRL_REG_NUM_ADDR_BYTES_FLD_SHIFT);

        /* Set command address register */
        cmdAddr = QSPICmd2Addr(&cmdBuf[1], (cmdLen - 1U));
        temp_addr = baseAddr + CSL_QSPI_FLASH_CMD_ADDR_REG;
        HWREG(temp_addr) = cmdAddr;
    }

    if (txLen)
    {
        /* Enable write data in command control register */
        configReg |= CSL_QSPI_FLASH_CMD_CTRL_REG_ENB_WRITE_DATA_FLD_MASK | \
            ((txLen - 1U) << CSL_QSPI_FLASH_CMD_CTRL_REG_NUM_WR_DATA_BYTES_FLD_SHIFT);

        wrLen = txLen > 4U ? 4U : txLen;
        memcpy(&wrData, txBuf, wrLen);
        temp_addr = baseAddr + CSL_QSPI_FLASH_WR_DATA_LOWER_REG;
        HWREG(temp_addr) = wrData;


        if (txLen > 4U)
        {
            txBuf += wrLen;
            wrLen = txLen - wrLen;
            memcpy(&wrData, txBuf, wrLen);
            temp_addr = baseAddr + CSL_QSPI_FLASH_WR_DATA_UPPER_REG;
            HWREG(temp_addr) = wrData;
        }
    }
    temp_addr = baseAddr + CSL_QSPI_FLASH_CMD_CTRL_REG;
    HWREG(temp_addr) = configReg;
    return (qspiFlashExecCmd(baseAddr));
}

void QSPIIndReadSetup(uint32_t baseAddr, uint32_t offsetAddr,
                      uint32_t cmd, uint32_t mode, uint32_t dummyClk)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_DEV_INSTR_RD_CONFIG_REG;
    uint32_t configReg = HWREG(temp_addr);

    /* Configure the Device Write Instruction Configuration Register */
    configReg &= ~(CSL_QSPI_DEV_INSTR_RD_CONFIG_REG_INSTR_TYPE_FLD_MASK              | \
                   CSL_QSPI_DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD_MASK       | \
                   CSL_QSPI_DEV_INSTR_RD_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_MASK | \
                   CSL_QSPI_DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_MASK | \
                   CSL_QSPI_DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD_MASK);
    configReg |= (cmd << CSL_QSPI_DEV_INSTR_RD_CONFIG_REG_RD_OPCODE_NON_XIP_FLD_SHIFT)        | \
                 (mode << CSL_QSPI_DEV_INSTR_RD_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_SHIFT) | \
                 (dummyClk << CSL_QSPI_DEV_INSTR_RD_CONFIG_REG_DUMMY_RD_CLK_CYCLES_FLD_SHIFT);
    HWREG(temp_addr) = configReg;

    temp_addr = baseAddr + CSL_QSPI_INDIRECT_READ_XFER_START_REG;
    /* Configure the Indirect Write Transfer Start Address Register */
    HWREG(temp_addr) = offsetAddr;
}

void QSPIReadFifoData(uint32_t indAddr, uint8_t *dest, uint32_t rdLen)
{
    uint32_t temp;
    uint32_t remaining = rdLen;
    uint32_t *destPtr = (uint32_t *)dest;

    while(remaining > 0)
    {
        if (remaining >= QSPI_FIFO_WIDTH)
        {
            *destPtr = HWREG(indAddr);
            remaining -= QSPI_FIFO_WIDTH;
        }
        else
        {
            temp = HWREG(indAddr);
            memcpy(destPtr, &temp, remaining);
            break;
        }
        destPtr++;
    }
}

uint32_t QSPIGetSramLvl(uint32_t baseAddr, uint32_t rd)
{
    uint32_t sramLevel;
    uint32_t temp_addr = baseAddr + CSL_QSPI_SRAM_FILL_REG;
    
    if (rd)
    {
        sramLevel = HWREG(temp_addr) &
            CSL_QSPI_SRAM_FILL_REG_SRAM_FILL_INDAC_READ_FLD_MASK;
    }
    else
    {
        sramLevel = HWREG(temp_addr) >> \
            CSL_QSPI_SRAM_FILL_REG_SRAM_FILL_INDAC_WRITE_FLD_SHIFT;
    }

    return (sramLevel);
}

void QSPIClrIndReadComplete(uint32_t baseAddr)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_INDIRECT_READ_XFER_CTRL_REG;
    HWREG(temp_addr) |=
          CSL_QSPI_INDIRECT_READ_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD_MASK;
}

int32_t QSPIWaitIndReadComplete(uint32_t baseAddr)
{
    uint32_t val;
    uint32_t retry = QSPI_REG_RETRY;
    uint32_t temp_addr = baseAddr + CSL_QSPI_INDIRECT_READ_XFER_CTRL_REG;
    int32_t  retVal = 0;
   
    /* Check flash indirect read controller status */
    while (retry--)
    {
        val = HWREG(temp_addr);
        if (val & CSL_QSPI_INDIRECT_READ_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD_MASK)
        {
            break;
        }
        QSPIdelay(QSPI_POLL_IDLE_DELAY);
    }

    if (retry)
    {
        /* Clear indirect completion status */
        QSPIClrIndReadComplete(baseAddr);
        retVal = 0;
    }
    else
    {
        retVal = -1;
    }
    return(retVal);
}

void QSPIIndReadExecute(uint32_t baseAddr, uint32_t rxLen)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_INDIRECT_READ_XFER_NUM_BYTES_REG;
    
    /* Set the Indirect Write Transfer Start Address Register */
    HWREG(temp_addr) = rxLen;

    temp_addr = baseAddr + CSL_QSPI_INDIRECT_READ_XFER_WATERMARK_REG;
    /* Set the Indirect Write Transfer Watermark Register */
    HWREG(temp_addr) = QSPI_SRAM_WARERMARK_RD_LVL;

    temp_addr = baseAddr + CSL_QSPI_INDIRECT_READ_XFER_CTRL_REG;
    /* Start the indirect read transfer */
    HWREG(temp_addr) |= \
        CSL_QSPI_INDIRECT_READ_XFER_CTRL_REG_START_FLD_MASK;
}

void QSPIIndWriteSetup(uint32_t baseAddr, uint32_t offsetAddr, uint32_t cmd, uint32_t mode)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_DEV_INSTR_WR_CONFIG_REG;
    uint32_t configReg = HWREG(temp_addr);

    /* Configure the Device Write Instruction Configuration Register */
    configReg &= ~(CSL_QSPI_DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD_MASK               | \
                   CSL_QSPI_DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_MASK | \
                   CSL_QSPI_DEV_INSTR_WR_CONFIG_REG_ADDR_XFER_TYPE_STD_MODE_FLD_MASK | \
                   CSL_QSPI_DEV_INSTR_WR_CONFIG_REG_DUMMY_WR_CLK_CYCLES_FLD_MASK);
    configReg |= (cmd << CSL_QSPI_DEV_INSTR_WR_CONFIG_REG_WR_OPCODE_FLD_SHIFT) | \
                 (mode << CSL_QSPI_DEV_INSTR_WR_CONFIG_REG_DATA_XFER_TYPE_EXT_MODE_FLD_SHIFT);
    HWREG(temp_addr) = configReg;

    temp_addr = baseAddr + CSL_QSPI_INDIRECT_WRITE_XFER_START_REG;
    /* Configure the Indirect Write Transfer Start Address Register */
    HWREG(temp_addr) = offsetAddr;
}

void QSPIWriteFifoData(uint32_t indAddr, uint8_t *src, uint32_t wrLen)
{
    uint32_t temp;
    uint32_t remaining = wrLen;
    uint32_t *srcPtr = (uint32_t *)src;

    while (remaining > 0)
    {
        if (remaining >= QSPI_FIFO_WIDTH)
        {
            HWREG(indAddr) = *srcPtr;
            remaining -= QSPI_FIFO_WIDTH;
        }
        else
        {
            /* dangling bytes */
            memcpy(&temp, srcPtr, remaining);
            HWREG(indAddr) = temp;
            break;
        }
        srcPtr++;
    }
}

void QSPIClrIndWriteComplete(uint32_t baseAddr)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_INDIRECT_WRITE_XFER_CTRL_REG;
    HWREG(temp_addr) |=
          CSL_QSPI_INDIRECT_WRITE_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD_MASK;
}

int32_t QSPIWaitIndWriteComplete(uint32_t baseAddr)
{
    uint32_t val;
    uint32_t retry = QSPI_REG_RETRY;
    uint32_t temp_addr = baseAddr + CSL_QSPI_INDIRECT_WRITE_XFER_CTRL_REG;
    int32_t  retVal = 0;

    /* Check flash indirect write controller status */
    while (retry--)
    {
        val = HWREG(temp_addr);
        if (val & CSL_QSPI_INDIRECT_WRITE_XFER_CTRL_REG_IND_OPS_DONE_STATUS_FLD_MASK)
        {
            break;
        }
        QSPIdelay(QSPI_POLL_IDLE_DELAY);
    }

    if (retry)
    {
        /* Clear indirect completion status */
        QSPIClrIndWriteComplete(baseAddr);
        retVal = 0;
    }
    else
    {
        retVal = -1;
    }
    return(retVal);
}

void QSPIIndWriteExecute(uint32_t baseAddr, uint32_t txLen)
{
    uint32_t temp_addr = baseAddr + CSL_QSPI_INDIRECT_WRITE_XFER_NUM_BYTES_REG;
    
    /* Set the Indirect Write Transfer Start Address Register */
    HWREG(temp_addr) = txLen;

    temp_addr = baseAddr + CSL_QSPI_INDIRECT_WRITE_XFER_WATERMARK_REG;
    /* Set the Indirect Write Transfer Watermark Register */
    HWREG(temp_addr) = QSPI_SRAM_WATERMARK_WR_LVL;

    temp_addr = baseAddr + CSL_QSPI_INDIRECT_WRITE_XFER_CTRL_REG;
    /* Start the indirect write transfer */
    HWREG(temp_addr) |= \
        CSL_QSPI_INDIRECT_WRITE_XFER_CTRL_REG_START_FLD_MASK;
}

void QSPIIndWriteCancel(uint32_t baseAddr)
{
    /* Cancel the indirect write */
    uint32_t temp_addr = baseAddr + CSL_QSPI_INDIRECT_WRITE_XFER_CTRL_REG;
    HWREG(temp_addr) |=
        CSL_QSPI_INDIRECT_WRITE_XFER_CTRL_REG_CANCEL_FLD_MASK;
}

void QSPILoopbackEnable(uint32_t baseAddr)
{

    uint32_t temp_addr = baseAddr + CSL_QSPI_RD_DATA_CAPTURE_REG;
    HWREG(temp_addr) &=
        ~CSL_QSPI_RD_DATA_CAPTURE_REG_BYPASS_FLD_MASK;
}

void QSPILoopbackDisable(uint32_t baseAddr)
{
    /* Bypass the adapted loopback clock circuit. */
    uint32_t temp_addr = baseAddr + CSL_QSPI_RD_DATA_CAPTURE_REG;
    HWREG(temp_addr) |=
        CSL_QSPI_RD_DATA_CAPTURE_REG_BYPASS_FLD_MASK;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */
