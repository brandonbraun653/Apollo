/**
 *  \file      qspi.h
 *
 *  \brief     This file contains the function prototypes for the hardware
 *             abstraction layer for QSPI IP V0 controller. It also contains
 *             some related macro definitions and some files to be included.
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

#ifndef QSPI_V0_H_
#define QSPI_V0_H_

#include <string.h>
#include <ti/csl/src/ip/qspi/V0/cslr_qspi.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 *  \brief    QSPI operation timeout value.
 */
#define QSPI_POLL_IDLE_TIMEOUT          (5000U * 1000U) /* in Microsecond */
#define QSPI_POLL_IDLE_DELAY            (100U)          /* in Microsecond */
#define QSPI_POLL_IDLE_RETRY            (3U)
#define QSPI_REG_RETRY                  (10000U)
#define QSPI_FIFO_WIDTH                 (4U)

/**
 *  \brief    QSPI Command default Length.
 */
#define QSPI_CMD_LEN_DEFAULT            (1U)            /*In bytes */

/**
 * \brief  Enumerates the four possible clock modes for QSPI.
 *         Each mode has different values of clock phase(CKPH)
 *         and clock polarity(CKP)
 */
typedef enum qspiClkMode
{
    QSPI_CLK_MODE_0 = (CSL_QSPI_CONFIG_REG_SEL_CLK_PHASE_FLD_RESETVAL) |
                      (CSL_QSPI_CONFIG_REG_SEL_CLK_POL_FLD_RESETVAL),
    /**< Mode 0 - Clock polarity = 0, clock phase = 0*/
    QSPI_CLK_MODE_1 = (CSL_QSPI_CONFIG_REG_SEL_CLK_PHASE_FLD_MASK) |
                      (CSL_QSPI_CONFIG_REG_SEL_CLK_POL_FLD_RESETVAL),
    /**< Mode 1 - clock polarity = 0, clock phase = 1*/
    QSPI_CLK_MODE_2 = (CSL_QSPI_CONFIG_REG_SEL_CLK_PHASE_FLD_RESETVAL) |
                      (CSL_QSPI_CONFIG_REG_SEL_CLK_POL_FLD_MASK),
    /**< Mode 2 - clock polarity = 1, clock phase = 0*/
    QSPI_CLK_MODE_3 = (CSL_QSPI_CONFIG_REG_SEL_CLK_PHASE_FLD_MASK) |
                      (CSL_QSPI_CONFIG_REG_SEL_CLK_POL_FLD_MASK)
    /**<Mode 3 - clock polarity = 1, clock phase = 1*/
}qspiClkMode_t;

/**
 * \brief   Enumerates the different chip selects available
 *          to QSPI. QSPI module have four chip selects to
 *          connect to four external devices.
 */
typedef enum qspiChipSelect
{
    QSPI_CHIP_SELECT_CS0 = 0x0U,
    /**< Chip select 0 */
    QSPI_CHIP_SELECT_CS1 = 0x1U,
    /**< Chip select 1 */
    QSPI_CHIP_SELECT_CS2 = 0x2U,
    /**< Chip select 2 */
    QSPI_CHIP_SELECT_CS3 = 0x3U
    /** Chip select 3 */
} qspiChipSelect_t;

#define QSPI_CHIP_SELECT(x)   ((~((1U) << (x))) & 0xFU)

/**
 *  \brief   Peripheral select decode
 */
typedef enum qspiDecSelect
{
    QSPI_DECODER_SELECT4 = 0x0U,
    /**< 1 of 4 decode */
    QSPI_DECODER_SELECT16 = 0x1U
    /**< allow external 4 - 16 decode */
} qspiDecSelect_t;

/**
 * \brief   QSPI controller master mode baud rate divisor.
 *          SPI bard rate = master_ref_clk/BD, where BD is:
 *          0000 = /2
 *          0001 = /4
 *          0010 = /6
 *          ...
 *          1111 = /32
 */
#define QSPI_BAUD_RATE_DIVISOR(x)        (((x) - 2U) >> 1U)
#define QSPI_BAUD_RATE_DIVISOR_DEFAULT   (QSPI_BAUD_RATE_DIVISOR(32U))

/**
 *  \brief   QSPI device delays in cycles of SPI master ref clock.
 */
#define QSPI_DEV_DELAY_CSSOT     (46U)  /* Chip Select Start of Transfer Delay */
#define QSPI_DEV_DELAY_CSEOT     (46U)  /* Chip Select End of Transfer Delay */
#define QSPI_DEV_DELAY_CSDADS    (192U) /* Chip Select De-Assert Different Slaves Delay */
#define QSPI_DEV_DELAY_CSDA      (192U) /* Chip Select De-Assert Delay */

/**
 *  \brief  Enumerates the number of Address bytes to be sent before
 *          transfer in memory mapped mode for each chip select
 */
typedef enum qspiMemMapNumAddrBytes
{
    QSPI_MEM_MAP_NUM_ADDR_BYTES_ONE = 0U,
    /**< One address byte for Chip Select N*/
    QSPI_MEM_MAP_NUM_ADDR_BYTES_TWO = 1U,
    /**< Two address bytes for chip select N */
    QSPI_MEM_MAP_NUM_ADDR_BYTES_THREE = 2U,
    /**< Three address bytes for chip select N */
    QSPI_MEM_MAP_NUM_ADDR_BYTES_FOUR = 3U
    /**< Four address bytes for Chip select N */
} qspiMemMapNumAddrBytes_t;

/**
 *  \brief  Enumerates the write completion auto polling control states
 */
typedef enum qspiWriteCompAutoPolling
{
    QSPI_WRITE_COMP_AUTO_POLLING_ENABLE = 0U,
    /**< One address byte for Chip Select N*/
    QSPI_WRITE_COMP_AUTO_POLLING_DISABLE = 1U
} qspiWriteCompAutoPolling_t;

/**
 *  \brief  SRAM partition configuration definitions
 */

/** size of the indirect read/write partition in the SRAM,
    in units of SRAM locations */
#define QSPI_SRAM_SIZE_WORDS        (128U)
#define QSPI_SRAM_PARTITION_RD      (64U)
#define QSPI_SRAM_PARTITION_WR      (QSPI_SRAM_SIZE_WORDS - \
                                     QSPI_SRAM_PARTITION_RD)
/* Default value for SRAM PARTITION register */
#define QSPI_SRAM_PARTITION_DEFAULT (QSPI_SRAM_PARTITION_RD -  1U)

/**
 *  \brief  SRAM fill level watermark
 */
/* Read watermark fill level in words, will generate DMA request or
   interrupt when the SRAM fill level is above the watermark */
#define QSPI_SRAM_WARERMARK_RD_LVL  (QSPI_SRAM_PARTITION_RD / 4U)
/* Write watermark fill level in words, will generate DMA request or
   interrupt when the SRAM fill level is below the watermark */
#define QSPI_SRAM_WATERMARK_WR_LVL  (QSPI_SRAM_PARTITION_WR / 4U)

/**
 * \brief  This enumerates the flags of interrupt for QSPI module
 */
typedef enum qspiIntrMask
{
    QSPI_INTR_MASK_MODE_M_FAIL = CSL_QSPI_IRQ_STATUS_REG_MODE_M_FAIL_FLD_MASK,
    /**< Interrupt mask for mode fail interrupt */
    QSPI_INTR_MASK_UNDERFLOW_DET = CSL_QSPI_IRQ_STATUS_REG_UNDERFLOW_DET_FLD_MASK,
    /**< Interrupt mask for underflow detected interrupt */
    QSPI_INTR_MASK_IND_OP_DONE = CSL_QSPI_IRQ_STATUS_REG_INDIRECT_OP_DONE_FLD_MASK,
    /**< Interrupt mask for complete last triggered indirect operation interrupt */
    QSPI_INTR_MASK_IND_RD_REJECT = CSL_QSPI_IRQ_STATUS_REG_INDIRECT_READ_REJECT_FLD_MASK,
    /**< Interrupt mask for indirect op request rejected interrupt */
    QSPI_INTR_MASK_PROT_WR_ATTEMPT = CSL_QSPI_IRQ_STATUS_REG_PROT_WR_ATTEMPT_FLD_MASK,
    /**< Interrupt mask for write to protected area rejected interrupt */
    QSPI_INTR_MASK_ILLEGAL_ACCESS_DET = CSL_QSPI_IRQ_STATUS_REG_ILLEGAL_ACCESS_DET_FLD_MASK,
    /**< Interrupt mask for illegal AHB access detected interrupt */
    QSPI_INTR_MASK_IND_XFER_LVL_BREACH = CSL_QSPI_IRQ_STATUS_REG_INDIRECT_XFER_LEVEL_BREACH_FLD_MASK,
    /**< Interrupt mask for indirect transfer watermark level breached interrupt */
    QSPI_INTR_MASK_RECV_OVERFLOW_DET = CSL_QSPI_IRQ_STATUS_REG_RECV_OVERFLOW_FLD_MASK,
    /**< Interrupt mask for receive overflow interrupt */
    QSPI_INTR_MASK_TX_FIFO_NOT_FULL = CSL_QSPI_IRQ_STATUS_REG_TX_FIFO_NOT_FULL_FLD_MASK,
    /**< Interrupt mask for small TX FIFO not full interrupt */
    QSPI_INTR_MASK_TX_FIFO_FULL = CSL_QSPI_IRQ_STATUS_REG_TX_FIFO_FULL_FLD_MASK,
    /**< Interrupt mask for small TX FIFO full interrupt */
    QSPI_INTR_MASK_RX_FIFO_NOT_EMPTY = CSL_QSPI_IRQ_STATUS_REG_RX_FIFO_NOT_EMPTY_FLD_MASK,
    /**< Interrupt mask for small RX FIFO not empty interrupt */
    QSPI_INTR_MASK_RX_FIFO_FULL = CSL_QSPI_IRQ_STATUS_REG_RX_FIFO_FULL_FLD_MASK,
    /**< Interrupt mask for small RX FIFO full interrupt */
    QSPI_INTR_MASK_IND_RD_SRAM_FULL = CSL_QSPI_IRQ_STATUS_REG_INDRD_SRAM_FULL_FLD_MASK,
    /**< Interrupt mask for indirect read partion of sram full interrupt */
    QSPI_INTR_MASK_POLL_EXP_INT = CSL_QSPI_IRQ_STATUS_REG_POLL_EXP_INT_FLD_MASK,
    /**< Interrupt mask for max num of programmed polls cycles expired interrupt */
    QSPI_INTR_MASK_IRQ_STAT_RESV = CSL_QSPI_IRQ_STATUS_REG_IRQ_STAT_RESV_FLD_MASK
    /**< Interrupt mask for reserved interrupts */
} qspiIntrMask_t;

#define QSPI_INTR_MASK_IND_XFER (QSPI_INTR_MASK_IND_OP_DONE         | \
                                 QSPI_INTR_MASK_IND_XFER_LVL_BREACH | \
                                 QSPI_INTR_MASK_IND_RD_SRAM_FULL)

#define QSPI_INTR_MASK_ALL      (QSPI_INTR_MASK_MODE_M_FAIL         | \
                                 QSPI_INTR_MASK_UNDERFLOW_DET       | \
                                 QSPI_INTR_MASK_IND_OP_DONE         | \
                                 QSPI_INTR_MASK_IND_RD_REJECT       | \
                                 QSPI_INTR_MASK_PROT_WR_ATTEMPT     | \
                                 QSPI_INTR_MASK_ILLEGAL_ACCESS_DET  | \
                                 QSPI_INTR_MASK_IND_XFER_LVL_BREACH | \
                                 QSPI_INTR_MASK_IND_RD_SRAM_FULL    | \
                                 QSPI_INTR_MASK_POLL_EXP_INT)

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function enables the QSPI
 *          By definition, target can handle read/write transaction as
 *          long as it is enabled
 *
 * \param   baseAddr      Base Address of the QSPI Module Registers.
 *
 *
 * \retval  none
 *
 */
void QSPIEnable(uint32_t baseAddr);

/**
 * \brief   This function disables the QSPI once current transfer of the data word is complete
 *
 * \param   baseAddr      Base Address of the QSPI Module Registers.
 *
 *
 * \retval  none
 *
 */
void QSPIDisable(uint32_t baseAddr);

/**
 * \brief   This function enables the QSPI Direct Access Controller
 *
 * \param   baseAddr      Base Address of the QSPI Module Registers.
 *
 *
 * \retval  none
 *
 */
void QSPIDacEnable(uint32_t baseAddr);

/**
 * \brief   This function disables the QSPI Direct Access Controller
 *
 * \param   baseAddr      Base Address of the QSPI Module Registers.
 *
 *
 * \retval  none
 *
 */
void QSPIDacDisable(uint32_t baseAddr);

/**
 * \brief   This function waits until the QSPI Controller is idle
 *
 * \param   baseAddr      Base Address of the QSPI Module Registers.
 *
 * \retval  status        0: success; 1: error
 */
int32_t QSPIWaitIdle(uint32_t baseAddr);

/**
 * \brief   Set the QSPI clock register divider value.
 *
 * \details This function sets the QSPI clock control register
 *          with serial data clock divider ratio (DCLK_DIV)
 *          according to the input clock provided and the output clock
 *          required.
 *          DCLK_DIV = ((input clock) / (output clock)) - 1.
 *          This function also enables the clock for QSPI module.
 *          This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr      Base Address for QSPI module registers.
 * \param   clkDividerVal clock divider value to be set.
 *
 * \retval  none
 *
 */
void QSPISetPreScaler(uint32_t baseAddr, uint32_t clkDividerVal);

/**
 * \brief   This function configures the QSPI to work in different clock modes.
 *
 * \details The combination of Clock phase
 *          and clock polarity creates the SPI mode. Most serial flash
 *          devices support only mode 0 and mode 3. Changing the clock polarity
 *          also swaps the transmit/receive clock edge relationship.
 *          If a slave device states that it receives data on the
 *          rising edge and transmits on the falling edge of the clock,
 *          then it can only support mode 0 or 3.
 *          This can only be done if QSPI module is not busy.
 *
 *          The 4 possible modes are :
 *
 *          CKP             CKPH         Description
 *          0               0            Data input captured on rising edge of
 *                                       qspi1_sclk clock. Data output generated
 *                                       on falling edge of qspi1_sclk clock
 *          0               1            Data input captured on falling edge of
 *                                       qspi1_sclk clock. Data output generate
 *                                       on rising edge of qspi1_sclk clock
 *          1               0            Data input captured on falling edge of
 *                                       qspi1_sclk clock. Data output generated
 *                                       on rising edge of qspi1_sclk clock
 *          1               1            Data input captured on rising edge of
 *                                       qspi1_sclk clock. Data output generated
 *                                       on falling edge of qspi1_sclk clock
 *
 * \param  baseAddr        Base Address of QSPI module registers.
 * \param  clkMode       Mode required to be selected.
 *                         Supported values given by enum #qspiClkMode_t
 *
 * \retval  none
 *
 */
void QSPISetClkMode(uint32_t baseAddr, uint32_t clkMode);

/**
 * \brief   This function configures the chip select polarity for
 *          a selected chip select.
 *          This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr            Base Address for QSPI module registers.
 * \param   chipSelect          Peripheral chip select lines. Supported values are
 *                              according to enum qspiChipSelect_t.
 * \param   decSelect           Peripheral select decode. Supported values are
 *                              according to enum qspiDecSelect_t.
 *
 * \retval  none
 *
 */
void QSPISetChipSelect(uint32_t baseAddr, uint32_t chipSelect, uint32_t decSelect);

/**
 * \brief   This function configures the device delays
 *          This can only be done if QSPI controller is idle.
 *
 * \param   baseAddr     Base Address for QSPI module registers.
 * \param   delays       Pointer to the device delay array
 *
 * \retval  none
 *
 */
void QSPISetDevDelay(uint32_t baseAddr, const uint32_t *delays);

/**
 * \brief   Set device size configrations.
 *
 * \details This function configures the number af Address Bytes, device
 *          page size and block size.
 *          This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr           Base Address for QSPI module registers.
 * \param   numAddrBytes       Number of Address bytes to be sent for
 *                             memory mapped protocol translator.
 *                             Supported values are given by enum
 *                             #qspiMemMapNumAddrBytes_t.
 * \param   pageSize           Device page size in bytes.
 * \param   blkSize            Device page size in bytes.
 *
 * \retval  none
 *
 */
void QSPISetDevSize(uint32_t baseAddr,
                    uint32_t numAddrBytes,
                    uint32_t pageSize,
                    uint32_t blkSize);

/**
 * \brief   Set Indirect Trigger Address.
 *
 * \details This function sets the base address that will be used by the
 *          AHB controller. This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr           Base Address for QSPI module registers.
 * \param   indTrigAddr        Indirect Trigger Address, base address used by
 *                             the AHB controller.
 *
 * \retval  none
 *
 */
void QSPISetIndTrigAddr(uint32_t baseAddr, uint32_t indTrigAddr);

/**
 * \brief   Set write completion auto polling configuration.
 *
 * \details This function configures the write compltion auto polling state.
 *          This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr           Base Address for QSPI module registers.
 * \param   pollingState       Auto polling state.
 *                             Supported values are given by enum
 *                             #qspiWriteCompAutoPolling_t.
 *
 * \retval  none
 *
 */
void QSPISetWrCompAutoPolling(uint32_t baseAddr, uint32_t pollingState);

/**
 * \brief   Set SRAM partition configuration.
 *
 * \details This function configures the size of the indirect read partition
 *          in the SRAM, in units of SRAM locations.
 *          This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr           Base Address for QSPI module registers.
 * \param   partition          Auto polling state.
 *                             Supported values are given by enum
 *                             #qspiWriteCompAutoPolling_t.
 *
 * \retval  none
 *
 */
void QSPISetSramPartition(uint32_t baseAddr, uint32_t partition);

/**
 * \brief     This Function enables only specified QSPI interrupts
 *
 * \param     baseAddr         Base Address for QSPI module registers.
 * \param     intrMask         mask value for the interrupts to be enabled.
 *                             Supported values are given by the enum
 *                             #qspiIntrMask_t.
 *
 * \retval    none
 *
 */
void QSPIIntrEnable(uint32_t baseAddr, uint32_t intrFlag);

/**
 * \brief     This Function disables only specified QSPI interrupts
 *
 * \param     baseAddr         Base Address for QSPI module registers.
 * \param     intrMask         mask value for the interrupts to be disabled.
 *                             Supported values are given by enum
 *                             #qspiIntrMask_t.
 *
 * \retval    none
 *
 */
void QSPIIntrDisable(uint32_t baseAddr, uint32_t intrFlag);

/**
 * \brief     This function returns the status of interrupts.
 *            It specifies whether an interrupt is active or inactive.
 *            After an interrupt is serviced, the software must set to 0
 *            the corresponding flag in the interrupt status register.
 *
 * \param     baseAddr         Base Address for QSPI module registers.
 *
 * \retval    status           All the interrupt status.
 *                             The return status can take value from the enum
 *                             #qspiIntrMask_t.
 */
uint32_t QSPIIntrStatus(uint32_t baseAddr);

/**
 * \brief     This Function clears the status of specified interrupts.
 *
 * \param     baseAddr         Base Address for QSPI module registers.
 * \param     intrMask         mask value for the interrupts to be cleared.
 *                             given by enum - #qspiIntrMask_t.
 *
 * \retval    none
 *
 */
void QSPIIntrClear(uint32_t baseAddr, uint32_t intrFlag);

/**
 * \brief     This Function delays CPU cycle counts of time
 *
 * \param     delayCount       delay in cpu cycle count.
 *
 * \retval    none
 *
 */
void QSPIdelay(uint32_t delayCount);

/**
 * \brief     This Function gets the QSPI SRAM FIFO fill level bytes
 *
 * \param     baseAddr         Base Address for QSPI module registers.
 * \param     rd               1: indirect read, 0: indirect write
 *
 * \retval    SRAM fifo fill level in bytes
 *
 */
uint32_t QSPIGetSramLvl(uint32_t baseAddr, uint32_t rd);

/**
 * \brief    Read operation in config mode
 *
 * \details  This function performs the read operation in config mode.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 * \param    cmd               Flash command opcode.
 * \param    rxBuf             Pointer to the read data buffer
 * \param    rxLen             Number of read data bytes
 *
 * \retval   0: success, 1: failure
 *
 */
int32_t QSPICmdRead(uint32_t baseAddr,
                    uint32_t cmd,
                    uint8_t *rxBuf,
                    uint32_t rxLen);

/**
 * \brief    Write operation in config mode
 *
 * \details  This function performs the write operation in config mode.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 * \param    cmd               Pointer to the flash command buffer.
 * \param    cmdLen            Command buffer size in bytes.
 * \param    txBuf             Pointer to the write data buffer
 * \param    txLen             Number of write data bytes
 *
 * \retval   0: success, 1: failure
 *
 */
int32_t QSPICmdWrite(uint32_t baseAddr,
                     const uint8_t *cmdBuf,
                     uint32_t cmdLen,
                     const uint8_t *txBuf,
                     uint32_t txLen);
/**
 * \brief    Setup read operation in indirect transfer mode
 *
 * \details  This function setup the configurations for read operation
 *           in indirect transfer mode.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 * \param    offsetAddr        Offset address of the flash memory to read.
 * \param    cmd               command opcode.
 * \param    mode              data transfer mode (single/dual/quad mode)
 * \param    dummyClk          Number of dummy clock cycles required for read op
 *
 * \retval   none
 *
 */
void QSPIIndReadSetup(uint32_t baseAddr,
                      uint32_t offsetAddr,
                      uint32_t cmd,
                      uint32_t mode,
                      uint32_t dummyClk);

/**
 * \brief    Execute read operation in indirect transfer mode
 *
 * \details  This function kicks off the read operation
 *           in indirect transfer mode.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 * \param    rxLen             read length in bytes.
 *
 * \retval   none
 *
 */
void QSPIIndReadExecute(uint32_t baseAddr, uint32_t rxLen);

/**
 * \brief    Clear indirect read operation done status
 *
 * \details  This function clears the indirect completion status
 *           in the Indirect Read Transfer Control Register.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 *
 * \retval   none
 *
 */
void QSPIClrIndReadComplete(uint32_t baseAddr);

/**
 * \brief    Wait and clear indirect read operation done
 *
 * \details  This function waits indirect read operation done
 *           and clears the indirect completion status.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 *
 * \retval   none
 *
 */
int32_t QSPIWaitIndReadComplete(uint32_t baseAddr);

/**
 * \brief    Read data from the SRAM FIFO
 *
 * \details  This function reads the data from the SRAM FIFO
 *           in indirect transfer mode.
 *
 * \param    indAddr           QSPI Indirect AHB base address
 * \param    dest              Destination address to copy the read data
 * \param    rdLen             read length in bytes
 *
 * \retval   0: success, 1: failure
 *
 */
void QSPIReadFifoData(uint32_t indAddr, uint8_t *dest, uint32_t rdLen);

/**
 * \brief    Setup write operation in indirect transfer mode
 *
 * \details  This function setup the configurations for write operation
 *           in indirect transfer mode.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 * \param    offsetAddr        Offset address of the flash memory to write.
 * \param    cmd               command opcode.
 * \param    mode              data transfer mode (single/dual/quad mode)
 *
 * \retval   none
 *
 */
void QSPIIndWriteSetup(uint32_t baseAddr,
                       uint32_t offsetAddr,
                       uint32_t cmd,
                       uint32_t mode);

/**
 * \brief    Clear indirect write operation done status
 *
 * \details  This function clears the indirect completion status
 *           in the Indirect Write Transfer Control Register.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 *
 * \retval   none
 *
 */
void QSPIClrIndWriteComplete(uint32_t baseAddr);

/**
 * \brief    Wait and clear indirect write operation done
 *
 * \details  This function waits indirect write operation done
 *           and clears the indirect completion status.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 *
 * \retval   none
 *
 */
int32_t QSPIWaitIndWriteComplete(uint32_t baseAddr);

/**
 * \brief    Execute write operation in indirect transfer mode
 *
 * \details  This function performs the write operation
 *           in indirect transfer mode.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 * \param    txLen             write length in bytes.
 *
 * \retval   none
 *
 */
void QSPIIndWriteExecute(uint32_t baseAddr, uint32_t txLen);

/**
 * \brief    Cancel write operation in indirect transfer mode
 *
 * \details  This function cancels the write operation
 *           in indirect transfer mode.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 *
 * \retval   none
 *
 */
void QSPIIndWriteCancel(uint32_t baseAddr);

/**
 * \brief    Write data to the SRAM FIFO
 *
 * \details  This function writes the data to the SRAM FIFO
 *           in indirect transfer mode.
 *
 * \param    indAddr           QSPI Indirect AHB base address
 * \param    src               Source address to copy the write data
 * \param    wrLen             write length in bytes
 *
 * \retval   0: success, 1: failure
 *
 */
void QSPIWriteFifoData(uint32_t indAddr, uint8_t *src, uint32_t wrLen);

/**
 * \brief    Enable the loopback mode
 *
 * \details  This function enables the loopback mode.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 *
 * \retval   none
 *
 */
void QSPILoopbackEnable(uint32_t baseAddr);

/**
 * \brief    Disable the loopback mode
 *
 * \details  This function disables the loopback mode.
 *
 * \param    baseAddr          Base Address for QSPI module registers
 *
 * \retval   none
 *
 */
void QSPILoopbackDisable(uint32_t baseAddr);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef QSPI_V0_H_ */
