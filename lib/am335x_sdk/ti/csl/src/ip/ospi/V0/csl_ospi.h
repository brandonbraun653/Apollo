/**
 * @file  csl_ospi.h
 *
 * @brief
 *  Header file containing various enumerations, macro definitions and function
 *  declarations for the OSPI IP.
 *  \par
 *  ============================================================================
 * @n   Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef CSL_OSPI_V0_H_
#define CSL_OSPI_V0_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>
#include <ti/csl/cslr_ospi.h>

/** ===========================================================================
 *
 * @defgroup CSL_OSPI_API Octal SPI (OSPI) API
 * @ingroup CSL_OSPI_API
 *
 *  This is the CSL-FL for the OSPI. It provides the enums, macros
 *  and APIs needed to configure, initialize, and query the OSPI.
 *
 * ============================================================================
 */
/**
@defgroup CSL_OSPI_DATASTRUCT  OSPI Data Structures
@ingroup CSL_OSPI_API
*/
/**
@defgroup CSL_OSPI_FUNCTION  OSPI Functions
@ingroup CSL_OSPI_API
*/
/**
@defgroup CSL_OSPI_ENUM OSPI Enumerated Data Types
@ingroup CSL_OSPI_API
*/

/**
 *  \addtogroup CSL_OSPI_ENUM
 *  @{
 */

/** ---------------------------------------------------------------------------
 * @brief
 *  This enumerator defines the four possible clock modes, dach mode has
 *  different values of clock phase(CKPH) and clock polarity(CKP)
 *
 *  \anchor CSL_OspiClkMode
 *  \name OSPI clock mode
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_OspiClkMode;
#define CSL_OSPI_CLK_MODE_0   (0U)
/**< Mode 0 - Clock polarity = 0, clock phase = 0*/
#define CSL_OSPI_CLK_MODE_1   (CSL_OSPI_FLASH_CFG_CONFIG_REG_SEL_CLK_PHASE_FLD_MASK | \
                               0U)
/**< Mode 1 - clock polarity = 0, clock phase = 1*/
#define CSL_OSPI_CLK_MODE_2   (0U | \
                               CSL_OSPI_FLASH_CFG_CONFIG_REG_SEL_CLK_POL_FLD_MASK)
/**< Mode 2 - clock polarity = 1, clock phase = 0*/
#define CSL_OSPI_CLK_MODE_3   (CSL_OSPI_FLASH_CFG_CONFIG_REG_SEL_CLK_PHASE_FLD_MASK | \
                               CSL_OSPI_FLASH_CFG_CONFIG_REG_SEL_CLK_POL_FLD_MASK)
/**<Mode 3 - clock polarity = 1, clock phase = 1*/
/* @} */

/** ---------------------------------------------------------------------------
 * @brief
 *  This enumerator defines the chip selects available to OSPI.
 *  OSPI module have four chip selects to connect to four external devices.
 *
 *  \anchor CSL_OspiChipSelect
 *  \name OSPI chip select
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_OspiChipSelect;
#define CSL_OSPI_CS0          ((uint32_t) 0U)
/**< Chip select 0 */
#define CSL_OSPI_CS1          ((uint32_t) 1U)
/**< Chip select 1 */
#define CSL_OSPI_CS2          ((uint32_t) 2U)
/**< Chip select 2 */
#define CSL_OSPI_CS3          ((uint32_t) 3U)
/** Chip select 3 */
/* @} */

/** ---------------------------------------------------------------------------
 * @brief
 *  This enumerator defines the decoder select.
 *
 *  \anchor CSL_OspiDecSelect
 *  \name OSPI decoder select
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_OspiDecSelect;
#define CSL_OSPI_DECODER_SELECT4  ((uint32_t) 0U)
/**< 1 of 4 decode */
#define CSL_OSPI_DECODER_SELECT16 ((uint32_t) 1U)
/**< allow external 4 - 16 decode */
/* @} */

/** ---------------------------------------------------------------------------
 * @brief
 *  This enumerator defines the number of Address bytes to be sent before
 *  transfer in memory mapped mode for each chip select
 *
 *  \anchor CSL_OspiMemMapNumAddrBytes
 *  \name OSPI num of addr bytes in memory mapped mode
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_OspiMemMapNumAddrBytes;
#define CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_1    ((uint32_t) 0U)
/**< One address byte for Chip Select N*/
#define CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_2    ((uint32_t) 1U)
/**< Two address bytes for chip select N */
#define CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_3    ((uint32_t) 2U)
/**< Three address bytes for chip select N */
#define CSL_OSPI_MEM_MAP_NUM_ADDR_BYTES_4    ((uint32_t) 3U)
/**< Four address bytes for Chip select N */
/* @} */

/** ---------------------------------------------------------------------------
 * @brief
 *  This enumerator defines the write completion auto polling control states
 *
 *  \anchor CSL_OspiWriteCompAutoPolling
 *  \name OSPI write completion auto polling state
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_OspiWriteCompAutoPolling;
#define CSL_OSPI_WRITE_COMP_AUTO_POLLING_ENABLE   ((uint32_t) 0U)
/**< Write completion auto polling state enable */
#define CSL_OSPI_WRITE_COMP_AUTO_POLLING_DISABLE  ((uint32_t) 1U)
/**< Write completion auto polling state disable */
/* @} */

/** ---------------------------------------------------------------------------
 * @brief
 *  This enumerator defines the flags of interrupt for OSPI module
 *
 *  \anchor CSL_OspiIntrMask
 *  \name OSPI interrupt mask flags
 *
 *  @{
 * ----------------------------------------------------------------------------
 */
typedef uint32_t CSL_OspiIntrMask;
#define CSL_OSPI_INTR_MASK_MODE_M_FAIL         (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_MODE_M_FAIL_FLD_MASK)
/**< Interrupt mask for mode fail interrupt */
#define CSL_OSPI_INTR_MASK_UNDERFLOW_DET       (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_UNDERFLOW_DET_FLD_MASK)
/**< Interrupt mask for underflow detected interrupt */
#define CSL_OSPI_INTR_MASK_IND_OP_DONE         (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_INDIRECT_OP_DONE_FLD_MASK)
/**< Interrupt mask for complete last triggered indirect operation interrupt */
#define CSL_OSPI_INTR_MASK_IND_RD_REJECT       (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_INDIRECT_READ_REJECT_FLD_MASK)
/**< Interrupt mask for indirect op request rejected interrupt */
#define CSL_OSPI_INTR_MASK_PROT_WR_ATTEMPT     (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_PROT_WR_ATTEMPT_FLD_MASK)
/**< Interrupt mask for write to protected area rejected interrupt */
#define CSL_OSPI_INTR_MASK_ILLEGAL_ACCESS_DET  (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_ILLEGAL_ACCESS_DET_FLD_MASK)
/**< Interrupt mask for illegal AHB access detected interrupt */
#define CSL_OSPI_INTR_MASK_IND_XFER_LVL_BREACH (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_INDIRECT_XFER_LEVEL_BREACH_FLD_MASK)
/**< Interrupt mask for indirect transfer watermark level breached interrupt */
#define CSL_OSPI_INTR_MASK_RECV_OVERFLOW_DET   (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_RECV_OVERFLOW_FLD_MASK)
/**< Interrupt mask for receive overflow interrupt */
#define CSL_OSPI_INTR_MASK_TX_FIFO_NOT_FULL    (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_TX_FIFO_NOT_FULL_FLD_MASK)
/**< Interrupt mask for small TX FIFO not full interrupt */
#define CSL_OSPI_INTR_MASK_TX_FIFO_FULL        (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_TX_FIFO_FULL_FLD_MASK)
/**< Interrupt mask for small TX FIFO full interrupt */
#define CSL_OSPI_INTR_MASK_RX_FIFO_NOT_EMPTY   (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_RX_FIFO_NOT_EMPTY_FLD_MASK)
/**< Interrupt mask for small RX FIFO not empty interrupt */
#define CSL_OSPI_INTR_MASK_RX_FIFO_FULL        (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_RX_FIFO_FULL_FLD_MASK)
/**< Interrupt mask for small RX FIFO full interrupt */
#define CSL_OSPI_INTR_MASK_IND_RD_SRAM_FULL    (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_INDRD_SRAM_FULL_FLD_MASK)
/**< Interrupt mask for indirect read partion of sram full interrupt */
#define CSL_OSPI_INTR_MASK_POLL_EXP_INT        (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_POLL_EXP_INT_FLD_MASK)
/**< Interrupt mask for max num of programmed polls cycles expired interrupt */
#define CSL_OSPI_INTR_MASK_IRQ_STAT_RESV       (CSL_OSPI_FLASH_CFG_IRQ_STATUS_REG_IRQ_STAT_RESV_FLD_MASK)
/**< Interrupt mask for reserved interrupts */
/* @} */

/* @} */

/**
 *  \addtogroup CSL_OSPI_DATASTRUCT
 *  @{
 */
/**
 *  \brief    OSPI operation timeout value.
 */
#define CSL_OSPI_POLL_IDLE_TIMEOUT          (5000U)         /* in millisecond */
#define CSL_OSPI_POLL_IDLE_DELAY            (1U)            /* in Millisecond */
#define CSL_OSPI_POLL_IDLE_RETRY            (3U)
#define CSL_OSPI_REG_RETRY                  (10U)
#define CSL_OSPI_FIFO_WIDTH                 (4U)

/**
 *  \brief    OSPI Command default Length.
 */
#define CSL_OSPI_CMD_LEN_DEFAULT            (1U)            /*In bytes */
#define CSL_OSPI_CHIP_SELECT(x)   ((~((1U) << (x))) & 0xFU)

/**
 * \brief   OSPI controller master mode baud rate divisor.
 *          SPI bard rate = master_ref_clk/BD, where BD is:
 *          0000 = /2
 *          0001 = /4
 *          0010 = /6
 *          ...
 *          1111 = /32
 */
#define CSL_OSPI_BAUD_RATE_DIVISOR(x)        (((x) - 2U) >> 1U)
#define CSL_OSPI_BAUD_RATE_DIVISOR_DEFAULT   (CSL_OSPI_BAUD_RATE_DIVISOR(32U))

/**
 *  \brief   OSPI device delay parameter array size.
 */
#define CSL_OSPI_DEV_DELAY_ARRAY_SIZE  (4U)

/**
 *  \brief   OSPI device delays in cycles of SPI master ref clock.
 */
#define CSL_OSPI_DEV_DELAY_CSSOT     (46U)  /* Chip Select Start of Transfer Delay */
#define CSL_OSPI_DEV_DELAY_CSEOT     (46U)  /* Chip Select End of Transfer Delay */
#define CSL_OSPI_DEV_DELAY_CSDADS    (192U) /* Chip Select De-Assert Different Slaves Delay */
#define CSL_OSPI_DEV_DELAY_CSDA      (192U) /* Chip Select De-Assert Delay */

/**
 *  \brief  SRAM partition configuration definitions
 */

/** size of the indirect read/write partition in the SRAM,
    in units of SRAM locations */
#define CSL_OSPI_SRAM_SIZE_WORDS        (128U)
#define CSL_OSPI_SRAM_PARTITION_RD      (64U)
#define CSL_OSPI_SRAM_PARTITION_WR      (CSL_OSPI_SRAM_SIZE_WORDS - \
                                         CSL_OSPI_SRAM_PARTITION_RD)
/* Default value for SRAM PARTITION register */
#define CSL_OSPI_SRAM_PARTITION_DEFAULT (CSL_OSPI_SRAM_PARTITION_RD -  1U)

/**
 *  \brief  SRAM fill level watermark
 */
/* Read watermark fill level in words, will generate DMA request or
   interrupt when the SRAM fill level is above the watermark */
#define CSL_OSPI_SRAM_WARERMARK_RD_LVL  (CSL_OSPI_SRAM_PARTITION_RD / 4U)
/* Write watermark fill level in words, will generate DMA request or
   interrupt when the SRAM fill level is below the watermark */
#define CSL_OSPI_SRAM_WATERMARK_WR_LVL  (CSL_OSPI_SRAM_PARTITION_WR / 4U)


#define CSL_OSPI_INTR_MASK_IND_XFER (CSL_OSPI_INTR_MASK_IND_OP_DONE         | \
                                     CSL_OSPI_INTR_MASK_IND_XFER_LVL_BREACH | \
                                     CSL_OSPI_INTR_MASK_IND_RD_SRAM_FULL)

#define CSL_OSPI_INTR_MASK_ALL  (CSL_OSPI_INTR_MASK_MODE_M_FAIL         | \
                                 CSL_OSPI_INTR_MASK_UNDERFLOW_DET       | \
                                 CSL_OSPI_INTR_MASK_IND_OP_DONE         | \
                                 CSL_OSPI_INTR_MASK_IND_RD_REJECT       | \
                                 CSL_OSPI_INTR_MASK_PROT_WR_ATTEMPT     | \
                                 CSL_OSPI_INTR_MASK_ILLEGAL_ACCESS_DET  | \
                                 CSL_OSPI_INTR_MASK_IND_XFER_LVL_BREACH | \
                                 CSL_OSPI_INTR_MASK_IND_RD_SRAM_FULL    | \
                                 CSL_OSPI_INTR_MASK_POLL_EXP_INT)

/* @} */

/**
 *  \addtogroup CSL_OSPI_FUNCTION
 *  @{
 */
/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function enables/disables the OSPI
 *          By definition, target can handle read/write transaction as
 *          long as it is enabled
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   enable        [IN] TRUE: enable OSPI to handle read/write transaction
 *                             FALSE: disable OSPI once current transaction of
 *                                    the data word is complete
 *
 * \retval  none
 *
 */
void CSL_ospiEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t enable);

/**
 * \brief   This function enables/disables the OSPI Direct Access Controller
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   enable        [IN] TRUE: enable OSPI DAC, FALSE: disable OSPI DAC
 *
 * \retval  none
 *
 */
void CSL_ospiDacEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t enable);

/**
 * \brief   This function enables/disables the OSPI XIP Controller
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   enable        [IN] TRUE: enable OSPI XIP, FALSE: disable OSPI XIP
 *
 * \retval  none
 *
 */
void CSL_ospiXipEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t enable);

/**
 * \brief   This function sets the Mode bits which are sent to the device following address 
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   enable        [IN] Mode bit value to be set
 *
 * \retval  none
 *
 */
void CSL_ospiSetModeBits(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t flashModeVal);

/**
 * \brief   This function enables/disables the OSPI PHY mode
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   enable        [IN] TRUE: enable OSPI PHY mode
 *                             FALSE: disable OSPI PHY mode
 *
 * \retval  none
 *
 */
void CSL_ospiPhyEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t enable);

/**
 * \brief   This function enables/disables the OSPI pipeline PHY mode
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   enable        [IN] TRUE: enable OSPI pipeline PHY mode
 *                             FALSE: disable OSPI pipeline PHY mode
 *
 * \retval  none
 *
 */
void CSL_ospiPipelinePhyEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t enable);

/**
 * \brief   This function enables/disables the OSPI DTR protocol
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   enable        [IN] TRUE: enable OSPI DTR protocol
 *                             FALSE: disable OSPI DTR protocol
 *
 * \retval  none
 *
 */
void CSL_ospiDtrEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t enable);

/**
 * \brief   Set the OSPI clock register divider value.
 *
 * \details This function sets the OSPI clock control register
 *          with serial data clock divider ratio (DCLK_DIV)
 *          according to the input clock provided and the output clock
 *          required.
 *          DCLK_DIV = ((input clock) / (output clock)) - 1.
 *          This function also enables the clock for OSPI module.
 *          This can only be done if OSPI module is not busy.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   clkDividerVal [IN] clock divider value to be set.
 *
 * \retval  none
 *
 */
void CSL_ospiSetPreScaler(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t clkDividerVal);

/**
 * \brief   This function configures the OSPI to work in different clock modes.
 *
 * \details The combination of Clock phase
 *          and clock polarity creates the SPI mode. Most serial flash
 *          devices support only mode 0 and mode 3. Changing the clock polarity
 *          also swaps the transmit/receive clock edge relationship.
 *          If a slave device states that it receives data on the
 *          rising edge and transmits on the falling edge of the clock,
 *          then it can only support mode 0 or 3.
 *          This can only be done if OSPI module is not busy.
 *
 *          The 4 possible modes are :
 *
 *          CKP             CKPH         Description
 *          0               0            Data input captured on rising edge of
 *                                       ospi1_sclk clock. Data output generated
 *                                       on falling edge of ospi1_sclk clock
 *          0               1            Data input captured on falling edge of
 *                                       ospi1_sclk clock. Data output generate
 *                                       on rising edge of ospi1_sclk clock
 *          1               0            Data input captured on falling edge of
 *                                       ospi1_sclk clock. Data output generated
 *                                       on rising edge of ospi1_sclk clock
 *          1               1            Data input captured on rising edge of
 *                                       ospi1_sclk clock. Data output generated
 *                                       on falling edge of ospi1_sclk clock
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   clkMode       [IN] Mode required to be selected.
 *                             Supported values given by \ref CSL_OspiClkMode_t
 *
 * \retval  none
 *
 */
void CSL_ospiSetClkMode(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t clkMode);

/**
 * \brief   This function configures the chip select polarity for
 *          a selected chip select.
 *          This can only be done if OSPI module is not busy.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   chipSelect    [IN] Peripheral chip select lines. Supported values are
 *                             according to \ref CSL_OspiChipSelect_t.
 * \param   decSelect     [IN] Peripheral select decode. Supported values are
 *                             according to \ref CSL_OspiDecSelect_t.
 *
 * \retval  none
 *
 */
void CSL_ospiSetChipSelect(const CSL_ospi_flash_cfgRegs *pRegs,
                           uint32_t chipSelect,
                           uint32_t decSelect);

/**
 * \brief   This function configures the device delays
 *          This can only be done if OSPI controller is idle.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   delays        [IN] Pointer to the device delay array
 *
 * \retval  none
 *
 */
void CSL_ospiSetDevDelay(const CSL_ospi_flash_cfgRegs *pRegs, const uint32_t *delays);

/**
 * \brief   Set device size configrations.
 *
 * \details This function configures the number af Address Bytes, device
 *          page size and block size.
 *          This can only be done if OSPI module is not busy.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   numAddrBytes  [IN] Number of Address bytes to be sent for
 *                             memory mapped protocol translator.
 *                             Supported values are given by \ref
 *                             CSL_OspiMemMapNumAddrBytes_t.
 * \param   pageSize      [IN] Device page size in bytes.
 * \param   blkSize       [IN] Device block size in bytes.
 *
 * \retval  none
 *
 */
void CSL_ospiSetDevSize(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32_t numAddrBytes,
                        uint32_t pageSize,
                        uint32_t blkSize);

/**
 * \brief   Set Indirect Trigger Address.
 *
 * \details This function sets the base address that will be used by the
 *          AHB controller. This can only be done if OSPI module is not busy.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   indTrigAddr   [IN] Indirect Trigger Address, base address used by
 *                             the AHB controller.
 *
 * \retval  none
 *
 */
void CSL_ospiSetIndTrigAddr(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t indTrigAddr);

/**
 * \brief   Set write completion auto polling configuration.
 *
 * \details This function configures the write compltion auto polling state.
 *          This can only be done if OSPI module is not busy.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   pollingState  [IN] Auto polling state.
 *                             Supported values are given by
 *                             \ref CSL_OspiWriteCompAutoPolling_t.
 *
 * \retval  none
 *
 */
void CSL_ospiSetWrCompAutoPolling(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t pollingState);

/**
 * \brief   Set SRAM partition configuration.
 *
 * \details This function configures the size of the indirect read partition
 *          in the SRAM, in units of SRAM locations.
 *          This can only be done if OSPI module is not busy.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   partition     [IN] Auto polling state.
 *                             Supported values are given by
 *                             \ref CSL_OspiWriteCompAutoPolling_t.
 *
 * \retval  none
 *
 */
void CSL_ospiSetSramPartition(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t partition);

/**
 * \brief   This Function enables/diables only specified OSPI interrupts
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   intrMask      [IN] mask value for the interrupts to be enabled.
 *                             Supported values are given by the
 *                             \ref CSL_OspiIntrMask_t.
 * \param   enable        [IN] TRUE: enable the specified OSPI interrupts
 *                             FALSE: disable the specified OSPI interrupts
 *
 * \retval  none
 *
 */
void CSL_ospiIntrEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t intrFlag, uint32_t enable);

/**
 * \brief   This function returns the status of interrupts.
 *          It specifies whether an interrupt is active or inactive.
 *          After an interrupt is serviced, the software must set to 0
 *          the corresponding flag in the interrupt status register.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 *
 * \retval  status        All the interrupt status.
 *                        The return status can take value from the
 *                        \ref CSL_OspiIntrMask_t.
 */
uint32_t CSL_ospiIntrStatus(const CSL_ospi_flash_cfgRegs *pRegs);

/**
 * \brief   This Function clears the status of specified interrupts.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   intrMask      [IN] mask value for the interrupts to be cleared.
 *                             given by  \ref CSL_OspiIntrMask_t.
 *
 * \retval  none
 *
 */
void CSL_ospiIntrClear(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t intrFlag);

/**
 * \brief   This Function gets the OSPI SRAM FIFO fill level bytes
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   read          [IN] TRUE: indirect read, FALSE: indirect write
 *
 * \retval  SRAM fifo fill level in bytes
 *
 */
uint32_t CSL_ospiGetSramLvl(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t read);

/**
 * \brief   Read operation in config mode
 *
 * \details This function performs the read operation in config mode.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   cmd           [IN] Flash command opcode.
 * \param   rxLen         [IN] Number of read data bytes
 *
 * \retval \ref CSL_ErrType_t
 *
 */
int32_t CSL_ospiCmdRead(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32_t cmd,
                        uint32_t rxLen);

/**
 * \brief   Write operation in config mode
 *
 * \details This function performs the write operation in config mode.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   cmd           [IN] Pointer to the flash command buffer.
 * \param   cmdLen        [IN] Command buffer size in bytes.
 * \param   txBuf         [IN] Pointer to the write data buffer
 * \param   txLen         [IN] Number of write data bytes
 *
 * \retval \ref CSL_ErrType_t
 *
 */
int32_t CSL_ospiCmdWrite(const CSL_ospi_flash_cfgRegs *pRegs,
                         const uint8_t *cmdBuf,
                         uint32_t cmdLen,
                         const uint8_t *txBuf,
                         uint32_t txLen);
/**
 * \brief   Setup read operation transfer mode
 *
 * \details This function setup the configurations for read operation
 *          transfer mode.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   cmd           [IN] command opcode.
 * \param   mode          [IN] data transfer mode (single/dual/quad mode)
 * \param   dummyClk      [IN] Number of dummy clock cycles required for read op
 *
 * \retval  none
 *
 */
void CSL_ospiConfigRead(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32_t cmd,
                        uint32_t mode,
                        uint32_t dummyClk);

/**
 * \brief   Execute read operation in indirect transfer mode
 *
 * \details This function kicks off the read operation
 *          in indirect transfer mode.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   rxLen         [IN] read length in bytes.
 *
 * \retval  none
 *
 */
void CSL_ospiIndReadExecute(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t rxLen);

/**
 * \brief   Clear indirect read operation done status
 *
 * \details This function clears the indirect completion status
 *          in the Indirect Read Transfer Control Register.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 *
 * \retval  none
 *
 */
void CSL_ospiClrIndReadComplete(const CSL_ospi_flash_cfgRegs *pRegs);

/**
 * \brief   Check if indirect read operation is done
 *
 * \details This function checks if indirect read operation is done
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 *
 * \retval  status        TRUE: read is done, FALSE: read is in progress
 *
 */
uint32_t CSL_ospiIndReadComplete(const CSL_ospi_flash_cfgRegs *pRegs);

/**
 * \brief   Read data from the SRAM FIFO
 *
 * \details This function reads the data from the SRAM FIFO
 *          in indirect transfer mode.
 *
 * \param   indAddr       [IN] OSPI indirect AHB base address.
 * \param   dest          [IN] Destination address to copy the read data
 * \param   rdLen         [IN] read length in bytes
 *
 * \retval  none
 *
 */
void CSL_ospiReadFifoData(uintptr_t indAddr, uint8_t *dest, uint32_t rdLen);

/**
 * \brief   Setup write operation transfer mode
 *
 * \details This function setup the configurations for write operation
 *          transfer mode.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   cmd           [IN] command opcode.
 * \param   mode          [IN] data transfer mode (single/dual/quad mode)
 *
 * \retval  none
 *
 */
void CSL_ospiWriteSetup(const CSL_ospi_flash_cfgRegs *pRegs,
                        uint32_t cmd,
                        uint32_t mode);

/**
 * \brief   Check if indirect write operation is done
 *
 * \details This function checks if indirect write operation is done
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 *
 * \retval  status        TRUE: write is done, FALSE: write is in progress
 *
 */
uint32_t CSL_ospiIsIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs);

/**
 * \brief   Clear indirect write operation done status
 *
 * \details This function clears the indirect completion status
 *          in the Indirect Write Transfer Control Register.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 *
 * \retval  none
 *
 */
void CSL_ospiClrIndWriteComplete(const CSL_ospi_flash_cfgRegs *pRegs);

/**
 * \brief   Execute write operation in indirect transfer mode
 *
 * \details This function performs the write operation
 *          in indirect transfer mode.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   txLen         [IN] write length in bytes.
 *
 * \retval  none
 *
 */
void CSL_ospiIndWriteExecute(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t txLen);

/**
 * \brief   Cancel write operation in indirect transfer mode
 *
 * \details This function cancels the write operation
 *          in indirect transfer mode.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 *
 * \retval  none
 *
 */
void CSL_ospiIndWriteCancel(const CSL_ospi_flash_cfgRegs *pRegs);

/**
 * \brief    Write data to the SRAM FIFO
 *
 * \details  This function writes the data to the SRAM FIFO
 *           in indirect transfer mode.
 *
 * \param    indAddr           OSPI Indirect AHB base address
 * \param    src               Source address to copy the write data
 * \param    wrLen             write length in bytes
 *
 * \retval   none
 */
void CSL_ospiWriteFifoData(uintptr_t indAddr, const uint8_t *src, uint32_t wrLen);

/**
 * \brief   Enable the adapted loopback clock circuit
 *
 * \details This function enables the loopback mode.
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   enable        [IN] TRUE: enable OSPI loopback clock
 *                             FALSE: disable OSPI loopback clock
 *
 * \retval  none
 *
 */
void CSL_ospiLoopbackClkEnable(const CSL_ospi_flash_cfgRegs *pRegs, uint32_t enable);

/**
 * \brief   Check if OSPI is idle or not
 *
 * \details This function checks the OSPI idle status
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 *
 * \retval  idle status   TRUE: OSPI is idle, FALSE: OSPI is busy
 *
 */
uint32_t CSL_ospiIsIdle(const CSL_ospi_flash_cfgRegs *pRegs);

/**
 * \brief   Excecute the flash read/write command
 *
 * \details This function excecute the flash read/write command
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 *
 * \retval  none
 *
 */
void CSL_ospiFlashExecCmd(const CSL_ospi_flash_cfgRegs *pRegs);

/**
 * \brief   Check the flash command execution status
 *
 * \details This function checks the execution status of the flash read/write command
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 *
 * \retval  status        TRUE: command execution completed
 *                        FALSE: command execution in progress
 *
 */
uint32_t CSL_ospiFlashExecCmdComplete(const CSL_ospi_flash_cfgRegs *pRegs);

/**
 * \brief   Configure the PHY
 *
 * \details This function configures and calibrates the PHY
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   masterDelay   [IN] Initial number of delay elements for Master DLL
 * \param   pDelay        [IN] Point to initial number of delay elements for Slave DLL
 *                             if pDelay == NULL, do calibration operation
 *
 * \retval  none
 *
 */
void CSL_ospiConfigPhy(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32_t                      masterDelay,
                       const uint32_t               *pSlaveDelay);

/**
 * \brief   Set configurations for a flash STIG command
 *
 * \details This function sets the command address, data and contorl for a generic STIG command
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 *
 * \retval  none
 *
 */
void CSL_ospiFlashStig(const CSL_ospi_flash_cfgRegs *pRegs,
                       uint32_t                      cmd,
                       uint32_t                      addr,
                       uint32_t                      data);

/**
 * \brief   Configure the read or wrtie start address in Indirect mode
 *
 * \details This function configures indac read or write start address
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   startAddr     [IN] Indirect access start address
 * \param   read          [IN] TRUE: read operation; FALSE: write operation
 *
 * \retval  none
 *
 */
void CSL_ospiIndSetStartAddr(const CSL_ospi_flash_cfgRegs *pRegs,
                             uint32_t                      startAddr,
                             uint32_t                      read);

/**
 * \brief   Set the read data capture delay
 *
 * \details This function sets the read data capture delay in # of ref_clk cycles
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   delay         [IN] delay in # of ref_clk cycle
 *
 * \retval  none
 *
 */
void CSL_ospiSetDataReadCapDelay(const CSL_ospi_flash_cfgRegs *pRegs,
                                 uint32_t                      delay);

/**
 * \brief   Set the Chip Select Start of Transfer delay
 *
 * \details This function sets the Chip Select Start of Transfer delay in # of ref_clk cycles
 *
 * \param   pRegs         [IN] OSPI flash config register base.
 * \param   delay         [IN] delay in # of ref_clk cycle
 *
 * \retval  none
 *
 */
void CSL_ospiSetCsSotDelay(const CSL_ospi_flash_cfgRegs *pRegs,
                           uint32_t                      delay);

/* @} */

#ifdef __cplusplus
}
#endif

#endif /* #ifndef CSL_OSPI_V0_H_ */
