/**
 * \file       qspi.h
 *
 * \brief      This file contains the function prototypes for the device
 *             abstraction layer for QSPI. It also contains some
 *             related macro definitions and enum definitions.
 *
 *             The QSPI module support single, dual and quad read mode
 *             in interrupt and polling mode using QSPI data registers
 *             and also support memory mapped mode.
 *
 * \details    Programming sequence of QSPI is as follows:
 *             -# Enable the functional clock for required QSPI instance.
 *             -# Perform the pin multiplexing for required QSPI instance.
 *             -# Set the QSPI idle mode using the API #QSPISetIdleMode.
 *             -# Set the QSPI clock register divider value and enable the
 *                QSPI clock using the API #QSPISetPreScaler.
 *             -# Set the QSPI clock mode using the API
 *                #QSPISetClkMode.
 *             -# Set the QSPI chip select polarity using the API
 *                #QSPISetCsPol.
 *             -# Set the QSPI data delay using the API #QSPISetDataDelay.
 *             -# Sequence for memory mapped read/write
 *                -# Set the number of address bytes for QSPI in memory mapped
 *                   mode using the API #QSPISetMemMapNumAddrBytes.
 *                -# Set the number of dummy bits for QSPI in memory mapped
 *                   mode using the API #QSPISetMemMapNumDummyBits.
 *                -# Set the QSPI read type for memory mapped mode using the
 *                   API #QSPISetMemMapReadType.
 *                -# Set the QSPI write command for memory mapped mode
 *                   using the API #QSPISetMemMapWriteCmd.
 *                -# Set the QSPI flash read command for memory mapped mode
 *                   using the API #QSPISetMemMapReadCmd.
 *             -# Sequence for config mode read/write
 *                -# Set the transfer command for QSPI in config mode using the
 *                   API #QSPISetCfgModeTxCmd.
 *                -# Read data from QSPI data registers using the API
 *                   #QSPIReadData.
 *                -# Write data into QSPI data registers by using the API
 *                   #QSPIWriteData.
 *                -# Check busy status of QSPI using the API #QSPIIsBusy.
 *             -# Switch between memory mapped and config mode of QSPI
 *                using the API #QSPISetMemAddrSpace.
 */

/**
 * \copyright  Copyright (C) 2013 Texas Instruments Incorporated -
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

#ifndef QSPI_H_
#define QSPI_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "hw_qspi.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                          Macros and typedefs                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/**
 *  \brief    Enumerates the different IDLE modes available for
 *            QSPI module.
 */
typedef enum qspiSysConfigIdleMode
{
    QSPI_SYS_CONFIG_IDLE_MODE_FORCE = QSPI_SYSCONFIG_IDLE_MODE_FORCE,
    /**< Force IDLE Mode.*/
    QSPI_SYS_CONFIG_IDLE_MODE_NO = QSPI_SYSCONFIG_IDLE_MODE_NO,
    /**< No IDLE mode. QSPI_FCLK is never gated by QSPI.*/
    QSPI_SYS_CONFIG_IDLE_MODE_SMART = QSPI_SYSCONFIG_IDLE_MODE_SMART,
    /**< Smart IDLE Mode.*/
    QSPI_SYS_CONFIG_IDLE_MODE_SMART_WAKEUP_CAPABLE =
        QSPI_SYSCONFIG_IDLE_MODE_SMART_WAKEUP_CAPABLE,
    /**< Smart Wakeup Capable Idle Mode.*/
} qspiSysConfigIdleMode_t;

/**
 * \brief  Enumerates the four possible clock modes for QSPI.
 *         Each mode has different values of clock phase(CKPH)
 *         and clock polarity(CKP)
 */
typedef enum qspiClkMode
{
    QSPI_CLK_MODE_0 = (QSPI_DC_REG_CKPH0_CKP_0_SHIFT_OUT_FALLING_EDGE <<
                       QSPI_DC_REG_CKPH0_SHIFT) |
                      (QSPI_DC_REG_CKP0_DATA_INACTIVE <<
                       QSPI_DC_REG_CKP0_SHIFT),
    /**< Mode 0 - Clock polarity = 0, clock phase = 0*/
    QSPI_CLK_MODE_1 = (QSPI_DC_REG_CKPH0_CKP_0_SHIFT_OUT_RISING_EDGE <<
                       QSPI_DC_REG_CKPH0_SHIFT) |
                      (QSPI_DC_REG_CKP0_DATA_INACTIVE <<
                       QSPI_DC_REG_CKP0_SHIFT),
    /**< Mode 1 - clock polarity = 0, clock phase = 1*/
    QSPI_CLK_MODE_2 = (QSPI_DC_REG_CKPH0_CKP_1_SHIFT_OUT_RISING_EDGE <<
                       QSPI_DC_REG_CKPH0_SHIFT) |
                      (QSPI_DC_REG_CKP0_DATA_ACTIVE <<
                       QSPI_DC_REG_CKP0_SHIFT),
    /**< Mode 2 - clock polarity = 1, clock phase = 0*/
    QSPI_CLK_MODE_3 = (QSPI_DC_REG_CKPH0_CKP_1_SHIFT_OUT_FALLING_EDGE <<
                       QSPI_DC_REG_CKPH0_SHIFT) |
                      (QSPI_DC_REG_CKP0_DATA_ACTIVE <<
                       QSPI_DC_REG_CKP0_SHIFT),
    /**<Mode 3 - clock polarity = 1, clock phase = 1*/
}qspiClkMode_t;

/**
 *
 * \brief   Enumerates the various transfer commands to be set in the
 *          command register for transfer using configuration registers.
 */
typedef enum qspiCfgModeTxCmd
{
    QSPI_CFG_MODE_TX_CMD_FOUR_PIN_READ_SINGLE =
        QSPI_CMD_REG_FOUR_PIN_READ_SINGLE,
    /**< Four Pin single read command .*/
    QSPI_CFG_MODE_TX_CMD_FOUR_PIN_WRITE_SINGLE =
        QSPI_CMD_REG_FOUR_PIN_WRITE_SINGLE,
    /**<Four pin single write command .*/
    QSPI_CFG_MODE_TX_CMD_FOUR_PIN_READ_DUAL =
        QSPI_CMD_REG_FOUR_PIN_READ_DUAL,
    /**< Four pin dual read command.*/
    QSPI_CFG_MODE_TX_CMD_THREE_PIN_READ_SINGLE =
        QSPI_CMD_REG_THREE_PIN_READ_SINGLE,
    /**< Three pin single read command.*/
    QSPI_CFG_MODE_TX_CMD_THREE_PIN_WRITE_SINGLE =
        QSPI_CMD_REG_THREE_PIN_WRITE_SINGLE,
    /**< Three pin single write command.*/
    QSPI_CFG_MODE_TX_CMD_SIX_PIN_READ_QUAD =
        QSPI_CMD_REG_SIX_PIN_READ_QUAD,
    /**< Six pin quad read command.*/
} qspiCfgModeTxCmd_t;

/**
 * \brief   Enumerates the differenct chip selects available
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
    QSPI_CHIP_SELECT_CS3 = 0x3U,
    /** Chip select 3 */
} qspiChipSelect_t;

/**
 * /brief  Enumerates the polarities for different chip select
 *         available. (Chip Select 0 to Chip Select 3)
 */
typedef enum qspiCsPol
{
    QSPI_CS_POL_ACTIVE_LOW = QSPI_DC_REG_CSP0_ACTIVE_LOW,
    /**< Chip select polarity active low */
    QSPI_CS_POL_ACTIVE_HIGH = QSPI_DC_REG_CSP0_ACTIVE_HIGH,
    /**< Chip select polarity active high */
} qspiCsPol_t;

/**
 *  \brief   Enumerates the value of Data delay value for
 *           each chip select. Data is output on the same cycle as
 *           CS_N goes active, or 1, 2 or 3 DCLK cycles after the
 *           CS_N goes active depending on the data delay provided.
 */
typedef enum qspiDataDelay
{
    QSPI_DATA_DELAY_0 = QSPI_DC_REG_DD0_CS_TO_DATA_DELAY_0,
    /**<Data is output on the same cycle as the CS N goes active. */
    QSPI_DATA_DELAY_1 = QSPI_DC_REG_DD0_CS_TO_DATA_DELAY_1,
    /**<Data is output 1 DCLK cycle after the CS N goes active. */
    QSPI_DATA_DELAY_2 = QSPI_DC_REG_DD0_CS_TO_DATA_DELAY_2,
    /**<Data is output 2 DCLK cycle after the CS N goes active. */
    QSPI_DATA_DELAY_3 = QSPI_DC_REG_DD0_CS_TO_DATA_DELAY_3,
    /**<Data is output 3 DCLK cycle after the CS N goes active. */
} qspiDataDelay_t;

/**
 *  \brief  Enumerates the number of Address bytes to be sent before
 *          transfer in memory mapped mode for each chip select
 */
typedef enum qspiMemMapNumAddrBytes
{
    QSPI_MEM_MAP_NUM_ADDR_BYTES_ONE = QSPI_SETUP_REG_NUM_A_BYTES_ONE_BYTE,
    /**< One address byte for Chip Select N*/
    QSPI_MEM_MAP_NUM_ADDR_BYTES_TWO = QSPI_SETUP_REG_NUM_A_BYTES_TWO,
    /**< Two address bytes for chip select N */
    QSPI_MEM_MAP_NUM_ADDR_BYTES_THREE = QSPI_SETUP_REG_NUM_A_BYTES_THREE,
    /**< Three address bytes for chip select N */
    QSPI_MEM_MAP_NUM_ADDR_BYTES_FOUR = QSPI_SETUP_REG_NUM_A_BYTES_FOUR,
    /**< Four address bytes for Chip select N */
} qspiMemMapNumAddrBytes_t;

/**
 * \brief  This enum Enumerates the different read types for each chip
 *         select for transfer in memory mapped mode.
 */
typedef enum qspiMemMapReadType
{
    QSPI_MEM_MAP_READ_TYPE_NORMAL = QSPI_SETUP_REG_READ_TYPE_NORMAL,
    /**< Normal read type for Chip select 0
     *   Normal means single read mode.
     */
    QSPI_MEM_MAP_READ_TYPE_DUAL = QSPI_SETUP_REG_READ_TYPE_DUAL,
    /**< Dual read type for chip select 0 */
    QSPI_MEM_MAP_READ_TYPE_NORMAL_READTYPE =
        QSPI_SETUP_REG_READ_TYPE_NORMAL_READTYPE,
    /**< Normal read type for Chip select 0 */
    QSPI_MEM_MAP_READ_TYPE_QUAD = QSPI_SETUP_REG_READ_TYPE_QUAD,
    /**< Quad read type for chip select 1 */
} qspiMemMapReadType_t;

/**
 *  \brief   This enumerates the values for switch to be set in the
 *           QSPI switch register for selection between config port
 *           and memory mapped port.
 *           If 0 (default) config port has is selected to control
 *           config of core SPI module module.
 *           If 1, Memory Mapped Protocol Translator is selected to
 *           control config port of core SPI module.
 */
typedef enum qspiMemMapPortSel
{
    QSPI_MEM_MAP_PORT_SEL_CFG_PORT = QSPI_SWITCH_REG_MMPT_S_SEL_CFG_PORT,
    /** < config port is selected to control config of core
          SPI module. */
    QSPI_MEM_MAP_PORT_SEL_MEM_MAP_PORT = QSPI_SWITCH_REG_MMPT_S_SEL_MM_PORT,
    /** < Memory Mapped Protocol Translator is selected to
          control config port of core SPI module.*/
} qspiMemMapPortSel_t;

/**
 * \brief  This enumerates the flags for
 *         word or frame interrupt for QSPI module
 */
typedef enum qspiIntrMask
{
    QSPI_INTR_MASK_FRAME = QSPI_INTR_EN_SET_REG_FIRQ_ENA_MASK,
    /**< Interrupt mask for frame interrupt. */
    QSPI_INTR_MASK_WORD = QSPI_INTR_EN_SET_REG_WIRQ_ENA_MASK
    /**< Interrupt mask for word interrupt . */
} qspiIntrMask_t;

/**
 * \brief  This structure defines the bitfields for
 *         transfer command to be set for transfers in
 *         configuration mode.
 */
typedef struct qspiTxCmd
{
    uint32_t frameLength : 12U;
    /**< Frame length to be transferred
     * This can take any value from 1 to 4096
     */
    uint32_t res1        :  2U;
    /**< Reserved bits */
    uint32_t wordCntIntrVal : 1U;
    /**< Word count interrupt value,
     *  Values can be TRUE or FALSE
     */
    uint32_t frameCntIntrVal : 1U;
    /**< Frame count interrupt value,
     *  Values can be TRUE or FALSE
     */
    uint32_t txCmd : 3U;
    /**< Transfer command to be set.
     * Values given by enum #qspiCfgModeTxCmd_t
     */
    uint32_t wordLength : 7U;
    /**< wordLength to be transferred.
     * This can take values from 1 to 128
     */
    uint32_t res2 : 2U;
    /**< Reserved bit fields */
    uint32_t chipSelect : 1U;
    /**< Chip select to be used.
     * Values given by enum #qspiChipSelect_t
     */
} qspiTxCmd_t;


/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   This function configures the idle mode of QSPI
 *          By definition, target can handle read/write transaction as
 *          long as it is out of IDLE state
 *
 * \param   baseAddr      Base Address of the QSPI Module Registers.
 * \param   idleMode      Idle mode to be configured.
 *                        It is of type enum #qspiSysConfigIdleMode_t.
 *
 */
void QSPISetIdleMode(uint32_t baseAddr, uint32_t idleMode);

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
 */
void QSPISetPreScaler(uint32_t baseAddr, uint32_t clkDividerVal);

/**
 * \brief   This function configures the QSPI to work in different clock modes
 *          for each output chip select.
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
 * \param  chipSelect      chipSelect for which the mode is to be configured.
 *                         Supported values according to enum
 *                         #qspiChipSelect_t.
 * \param  clkMode       Mode required to be selected.
 *                         Supported values given by enum #qspiClkMode_t
 */
void QSPISetClkMode(uint32_t baseAddr,
                    uint32_t chipSelect,
                    uint32_t clkMode);

/**
 * \brief   This function configures the chip select polarity for
 *          a selected chip select.
 *          This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr            Base Address for QSPI module registers.
 * \param   chipSelect          chip select for which polarity is to be
 *                              configured. Supported values are
 *                              according to enum
 *                              #qspiChipSelect_t.
 * \param   csPol               Polarity value of the chip select
 *                              selected.
 *                              Supported values are given by the enum
 *                              #qspiCsPol_t
 */
void QSPISetCsPol(uint32_t baseAddr,
                  uint32_t chipSelect,
                  uint32_t csPol);

/**
 * \brief   This function configures the Data delay for each chip select.
 *          This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr     Base Address for QSPI module registers.
 * \param   chipSelect   chip select for which polarity is to be configured.
 *                       Supported values are according to enum
 *                       #qspiChipSelect_t.
 * \param   dataDelay    Value of Data Delay.
 *                       Supported values are
 *                       given by enum #qspiDataDelay_t
 */
void QSPISetDataDelay(uint32_t baseAddr,
                      uint32_t chipSelect,
                      uint32_t dataDelay);

/**
 * \brief   Set number of address bytes for memory mapped mode.
 *
 * \details This function configures the number af Address Bytes to be
 *          sent for memory mapped protocol translator for selected chip
 *          select.By default, the device uses 3 address bytes.
 *          This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr           Base Address for QSPI module registers.
 * \param   chipSelect         chip select for which polarity is to be
 *                             configured.
 *                             Supported values are according to enum
 *                             #qspiChipSelect_t.
 * \param   numAddrBytes    Number of Address bytes to be sent for
 *                          memory mapped protocol translator.
 *                          Supported values are :
 *                          for each chip select given by enum
 *                          #qspiMemMapNumAddrBytes_t.
 */
void QSPISetMemMapNumAddrBytes(uint32_t baseAddr,
                               uint32_t chipSelect,
                               uint32_t numAddrBytes);

/**
 * \brief   Set Number of dummy bits for memory mapped mode.
 *
 * \details This function configures the number of Dummy Bits to be
 *          sent for memory mapped protocol translator for selected chip
 *          select for fast read mode.
 *          This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr        Base Address for QSPI module registers.
 * \param   chipSelect      chip select for which polarity is to be configured.
 *                          Supported values are according to enum
 *                          #qspiChipSelect_t.
 * \param   numDummyBits    Number of Dummy Bits to be sent for
 *                          memory mapped protocol translator.
 *                          User can pass any value from 0 to 32 bits.
 */
void QSPISetMemMapNumDummyBits(uint32_t baseAddr,
                               uint32_t chipSelect,
                               uint32_t numDummyBits);

/**
 * \brief   Set read type in memory mapped mode.
 *
 * \details This function configures the read type for QSPI in memory mapped
 *          mode for selected chip select.Determines if the read command
 *          is a single, dual or quad read mode.
 *          This can only be done if QSPI module is not busy.
 *
 * \param   baseAddr       Base Address for QSPI module registers.
 * \param   chipSelect     chip select for which polarity is to be configured.
 *                         Supported values are according to enum
 *                         #qspiChipSelect_t.
 * \param   readType       Read type to be chosen.
 *                         Supported values are given by enum
 *                         #qspiMemMapReadType_t.
 */

void QSPISetMemMapReadType(uint32_t baseAddr,
                           uint32_t chipSelect,
                           uint32_t readType);

/**
 * \brief    Set write command in memory mapped mode.
 *
 * \details  This function configures the write command for memory
 *           mapped protocol translator in memory mapped SPI setup register.
 *           The command send is according to the slave device connected.
 *           By default, the device uses a write command of 0x2.
 *           This can only be done if QSPI module is not busy.
 *
 * \param    baseAddr      Base Address for QSPI module registers.
 * \param    chipSelect    chip select for which polarity is to be configured.
 *                         Supported values are according to enum
 *                         #qspiChipSelect_t.
 * \param    writeCmd      Write Command to be sent to the flash device.
 *                         This command is specific to the flash device being
 *                         used.
 */
void QSPISetMemMapWriteCmd(uint32_t baseAddr,
                           uint32_t chipSelect,
                           uint32_t writeCmd);

/**
 * \brief    Set Read Command in memory mapped mode.
 *
 * \details  This function configures the read command for memory
 *           mapped protocol translator in memory mapped SPI setup register.
 *           The command send is according to the slave device connected.
 *           By default, the device uses a read command of 0x3.
 *           This can only be done if QSPI module is not busy.
 *
 * \param    baseAddr      Base Address for QSPI module registers.
 * \param    chipSelect    chip select for which polarity is to be configured.
 *                         Supported values are according to enum
 *                         #qspiChipSelect_t.
 * \param    readCmd       Read Command to be sent to the flash device.
 *                         This command is specific to the flash device being
 *                         used.
 */
void QSPISetMemMapReadCmd(uint32_t baseAddr,
                          uint32_t chipSelect,
                          uint32_t readCmd);

/**
 * \brief     This function reads value of data register
 *            (data, data1, data2, data3)
 *
 * \param     baseAddr   Base Address for QSPI module registers.
 * \param     pData      pointer to destination address.
 * \param     length     number of words to be read - accepted values from 1
 *                       to 4.
 *                       The length of data read is in multiples of 4 bytes.
 *                       1 means 4 bytes would be read.
 *                       4 means 16 bytes would be read.
 */
void QSPIReadData(uint32_t baseAddr, uint32_t *pData, uint32_t length);

/**
 *  \brief    This function writes to data register
 *            (data, data1, data2, data3).
 *
 * \param     baseAddr   Base Address for QSPI module registers.
 * \param     pData      pointer to source address.
 * \param     length     number of words ro be written - accepted values from 1
 *                       to 4.
 *                       The length of data read is in multiples of 4 bytes.
 *                       1 means 4 bytes would be written.
 *                       4 means 16 bytes would be written.
 */
void QSPIWriteData(uint32_t baseAddr, const uint32_t *pData, uint32_t length);

/**
 *  \brief    This function is blocking and waits till busy
 *            bit in status register is reset.
 *
 * \param     baseAddr   Base Address for QSPI module registers.
 *
 * \retval    status     value of busy bit of QSPI status register
 *                       TRUE : QSPI is busy
 *                       FALSE : QSPI is not busy
 */
uint32_t QSPIIsBusy(uint32_t baseAddr);

/**
 *  \brief    This function returns Word count value of Status register.
 *
 * \param     baseAddr   Base Address for QSPI module registers.
 *
 * \retval    wordCount  Word count field in Status register
 */
uint32_t QSPIGetStatusWordCount(uint32_t baseAddr);

/**
 * \brief     This Function enables only specified QSPI interrupts
 *
 * \param     baseAddr   Base Address for QSPI module registers.
 * \param     intrMask    mask value for the interrupts to be enabled.
 *                       Supported values are given by the enum
 *                       #qspiIntrMask_t.
 */
void QSPIIntrEnable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief     This Function disables only specified QSPI interrupts
 *
 * \param     baseAddr   Base Address for QSPI module registers.
 * \param     intrMask    mask value for the interrupts to be disabled.
 *                       Supported values are given by enum
 *                       #qspiIntrMask_t.
 */
void QSPIIntrDisable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief     This function returns the status of interrupts.
 *            It specifies whether an interrupt is active or inactive.
 *            After an interrupt is serviced, the software must set to 0
 *            the corresponding flag in the interrupt status register.
 *
 * \param     baseAddr   Base Address for QSPI module registers.
 *
 * \retval    status     All the interrupt status.
 *                       The return status can take value from the enum
 *                       #qspiIntrMask_t.
 */
uint32_t QSPIIntrStatus(uint32_t baseAddr);

/**
 * \brief     This Function clears the status of specified interrupts.
 *
 * \param     baseAddr   Base Address for QSPI module registers.
 * \param     intrMask    mask value for the interrupts to be cleared.
 *                       - given by enum - #qspiIntrMask_t.
 */
void QSPIIntrClear(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief     This function returns the raw status of interrupts.
 *
 * \param     baseAddr   Base Address for QSPI module registers.
 *
 * \retval    status     All the raw interrupt status.
 *                       The return status can take the value from the
 *                       enum #qspiIntrMask_t.
 */
uint32_t QSPIIntrRawStatus(uint32_t baseAddr);

/**
 * \brief    Set Memory address space
 *
 * \details  This function selects the memory mapped mode in
 *           SPI switch register and configures mapped address
 *           for different chip select in control module.
 *           It provides a functionality for
 *           remapping the memory mapped address space to one of
 *           the four supported chip selects or to the
 *           configuration registers.
 *
 * \param    baseAddr             Base Address for QSPI module registers
 * \param    memMapPortSwitch  Switch for selection of memory mapped port
 *                             and configuration port.
 *                             Supported values are given by enum
 *                             #qspiMemMapPortSel_t.
 * \param    chipSelect    chip select for which polarity is to be configured.
 *                         Supported values given by #qspiChipSelect_t.
 */
void QSPISetMemAddrSpace(uint32_t baseAddr,
                         uint32_t chipSelect,
                         uint32_t memMapPortSwitch);

/**
 * \brief    Set Transfer Command
 *
 * \details  This function sets the transfer command in the command
 *           for transfer of data in configuration mode.
 *
 * \param    baseAddr         Base Address of QSPI module registers
 * \param    qspiTxCmd        The transfer commnand to be set for initiating the
 *                            qspi transfer in config mode.
 *                            Value given by structure #qspiTxCmd_t
 */
void QSPISetCfgModeTxCmd(uint32_t baseAddr, qspiTxCmd_t qspiTxCmd);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef QSPI_H_ */
