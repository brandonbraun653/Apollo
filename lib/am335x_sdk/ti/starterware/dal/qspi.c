/**
 * \file       qspi.c
 *
 * \brief      This file contains the function definitions for the device
 *             abstraction layer for QSPI.
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
#include "qspi.h"
#include "hw_types.h"

/* ========================================================================== */
/*                          Macros and Typedefs                               */
/* ========================================================================== */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

void QSPISetIdleMode(uint32_t baseAddr, uint32_t idleMode)
{
    HW_WR_FIELD32(baseAddr + QSPI_SYSCONFIG, QSPI_SYSCONFIG_IDLE_MODE, idleMode);
}

void QSPISetPreScaler(uint32_t baseAddr, uint32_t clkDividerVal)
{
    /* Read the value of Clock control register */
    uint32_t regVal = HW_RD_REG32(baseAddr + QSPI_CLOCK_CNTRL_REG);
    /* wait for QSPI to be idle */
    while (TRUE == QSPIIsBusy(baseAddr));

    /* turn off QSPI data clock */
    HW_SET_FIELD(regVal, QSPI_CLOCK_CNTRL_REG_CLKEN,
        QSPI_CLOCK_CNTRL_REG_CLKEN_DCLOCK_OFF);
   /* Set the value of QSPI clock control register */
    HW_WR_REG32(baseAddr + QSPI_CLOCK_CNTRL_REG, regVal);

    /* Set the QSPI clock divider bit field value*/
    HW_SET_FIELD(regVal, QSPI_CLOCK_CNTRL_REG_DCLK_DIV, clkDividerVal);
    /* Set the value of QSPI clock control register */
    HW_WR_REG32(baseAddr + QSPI_CLOCK_CNTRL_REG, regVal);

    /* Enable the QSPI data clock */
    HW_SET_FIELD(regVal, QSPI_CLOCK_CNTRL_REG_CLKEN,
                QSPI_CLOCK_CNTRL_REG_CLKEN_DCLOCK_ON);
    /* Set the value of QSPI clock control register */
    HW_WR_REG32(baseAddr + QSPI_CLOCK_CNTRL_REG, regVal);
}

void QSPISetClkMode(uint32_t baseAddr,
                    uint32_t chipSelect,
                    uint32_t clkMode)
{
    /* read value of the device control register */
    uint32_t regVal = HW_RD_REG32(baseAddr + QSPI_DC_REG);

    /* Set the values of clock phase and clock polarity in the device
     * Control register for chip Select passed as the parameter to function.
     */
    /* The clock mode for different chip select are at a separation of
     * 8 bits in the device control register.
     * So 8U has been multiplied to the chip select value.
     */
    regVal &= ~(QSPI_CLK_MODE_3 << (8U * chipSelect));
    regVal |= (clkMode << (8U * chipSelect));
    /* wait for QSPI to be idle */
    while (TRUE == QSPIIsBusy(baseAddr));

    /* Set clock phase and clock polarity for required chip select
     * based on the mode selected
     */
    HW_WR_REG32(baseAddr + QSPI_DC_REG, regVal);
}

void QSPISetCsPol(uint32_t baseAddr,
          uint32_t chipSelect,
                  uint32_t csPol)
{
    /* Read value of device control register */
    uint32_t regVal = HW_RD_REG32(baseAddr + QSPI_DC_REG);
    /* wait for QSPI to be idle */
    while (TRUE == QSPIIsBusy(baseAddr));

    /* Set the chip select polarity for the required chip Select */
    /* The polarity for different chip select are at a separation of
     * 8 bits in the device control register.
     * So 8U has been multiplied to the chip select value.
     */
    regVal &= ~(QSPI_CS_POL_ACTIVE_HIGH << (QSPI_DC_REG_CSP0_SHIFT +
                                     (8U * chipSelect)));
    regVal |= (csPol << (QSPI_DC_REG_CSP0_SHIFT +
                                     (8U * chipSelect)));
    /* Set the value of the device control register to configure chip
     * polarity
     */
    HW_WR_REG32(baseAddr + QSPI_DC_REG, regVal);
}

void QSPISetDataDelay(uint32_t baseAddr,
                      uint32_t chipSelect,
                      uint32_t dataDelay)
{
    /* Read the value of device control register */
    uint32_t regVal = HW_RD_REG32(baseAddr + QSPI_DC_REG);
    /* wait for QSPI to be idle */
    while (TRUE == QSPIIsBusy(baseAddr));

    /** Set the Data Delay value for the required chip Select */
    /* The Data delay for different chip select are at a separation of
     * 8 bits in the device control register.
     * So 8U has been multiplied to the chip select value.
     */
    regVal &= ~(QSPI_DATA_DELAY_3 << (QSPI_DC_REG_DD0_SHIFT +
                            (8U * chipSelect)));
    regVal |= (dataDelay << (QSPI_DC_REG_DD0_SHIFT +
                            (8U * chipSelect)));

    /* Set the value of the device control register to configure data
       delay */
    HW_WR_REG32(baseAddr + QSPI_DC_REG, regVal);
}

void QSPISetMemMapNumAddrBytes(uint32_t baseAddr,
                               uint32_t chipSelect,
                               uint32_t numAddrBytes)
{
    uint32_t addr = baseAddr + QSPI_SETUP_REG(chipSelect);
    HW_WR_FIELD32(addr, QSPI_SETUP_REG_NUM_A_BYTES, numAddrBytes);
}

void QSPISetMemMapNumDummyBits(uint32_t baseAddr,
                               uint32_t chipSelect,
                               uint32_t numDummyBits)
{
    uint32_t addr = baseAddr + QSPI_SETUP_REG(chipSelect);
    /* Read the value of setup register for given chip select */
    uint32_t regVal = HW_RD_REG32(addr);
    uint32_t numDummyBytes;
    /* set number of dummy bits or bytes in setup register for transfer of
     * data in memory mapped mode
     */
    numDummyBytes = numDummyBits / 8U;
    numDummyBits = numDummyBits % 8U;
    HW_SET_FIELD(regVal, QSPI_SETUP_REG_NUM_D_BITS, numDummyBits);
    HW_SET_FIELD(regVal,
                QSPI_SETUP_REG_NUM_D_BYTES,
                numDummyBytes);
    HW_WR_REG32(addr, regVal);
}

void QSPISetMemMapReadType(uint32_t baseAddr,
                           uint32_t chipSelect,
                           uint32_t readType)
{
    uint32_t addr = baseAddr + QSPI_SETUP_REG(chipSelect);
    HW_WR_FIELD32(addr, QSPI_SETUP_REG_READ_TYPE, readType);
}

void QSPISetMemMapWriteCmd(uint32_t baseAddr,
                           uint32_t chipSelect,
                           uint32_t writeCmd)
{
    uint32_t addr = baseAddr + QSPI_SETUP_REG(chipSelect);
    HW_WR_FIELD32(addr, QSPI_SETUP_REG_WCMD, writeCmd);
}

void QSPISetMemMapReadCmd(uint32_t baseAddr,
                          uint32_t chipSelect,
                          uint32_t readCmd)
{
    uint32_t addr = baseAddr + QSPI_SETUP_REG(chipSelect);
    HW_WR_FIELD32(addr, QSPI_SETUP_REG_RCMD, readCmd);
}

void QSPIWriteData(uint32_t baseAddr, const uint32_t *pData, uint32_t length)
{
    /* Data is written to the DATA register 0 */
    HW_WR_REG32(baseAddr + QSPI_DATA_REG, *pData);
    pData++;
    length--;
    if (length > 0U)
    {
        /* Data is written to data register 1 */
        HW_WR_REG32(baseAddr + QSPI_DATA_REG_1, *pData);
        length--;
        pData++;
    }
    if (length > 0U)
    {
        /* Data is written to data register 2 */
        HW_WR_REG32(baseAddr + QSPI_DATA_REG_2, *pData);
        length--;
        pData++;
    }
    if (length > 0U)
    {
        /* Data is written to data register 3 */
        HW_WR_REG32(baseAddr + QSPI_DATA_REG_3, *pData);
    }
}

void QSPIReadData(uint32_t baseAddr, uint32_t *pData, uint32_t length)
{
    /* Data is read from the QSPI data register 0*/
    *pData = HW_RD_REG32(baseAddr + QSPI_DATA_REG);
    pData++;
    length--;
    if (length > 0U)
    {
        /* Data is read from QSPI data register 1*/
        *pData = HW_RD_REG32(baseAddr + QSPI_DATA_REG_1);
        pData++;
        length--;
    }
    if (length > 0U)
    {
        /* Data is read from QSPI data register 2 */
        *pData = HW_RD_REG32(baseAddr + QSPI_DATA_REG_2);
        pData++;
        length--;
    }
    if (length > 0U)
    {
        /* Data is read from QSPI data register 3 */
        *pData = HW_RD_REG32(baseAddr + QSPI_DATA_REG_3);
    }
}

uint32_t QSPIIsBusy(uint32_t baseAddr)
{
    uint32_t retval = FALSE;
    /* Read busy bit of QSPI status register */
    uint32_t busyStatus = HW_RD_FIELD32((baseAddr + QSPI_STS_REG), QSPI_STS_REG_BUSY);
    if (1U == busyStatus)
    {
        retval = TRUE;
    }
    else
    {
        retval = FALSE;
    }
    return retval;
}


uint32_t QSPIGetStatusWordCount(uint32_t baseAddr)
{
    /* Read QSPI status register */
     return(HW_RD_FIELD32(baseAddr + QSPI_STS_REG, QSPI_STS_REG_WDCNT));
}

void QSPIIntrEnable(uint32_t baseAddr, uint32_t intrFlag)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + QSPI_INTR_EN_SET_REG);
    regVal |= intrFlag;
    /** Set specified interrupts */
    HW_WR_REG32(baseAddr + QSPI_INTR_EN_SET_REG, regVal);
}

void QSPIIntrDisable(uint32_t baseAddr, uint32_t intrFlag)
{
    uint32_t regVal =HW_RD_REG32(baseAddr + QSPI_INTR_EN_CLR_REG);
    regVal |= intrFlag;
    HW_WR_REG32(baseAddr + QSPI_INTR_EN_CLR_REG, regVal);
}

uint32_t QSPIIntrStatus(uint32_t baseAddr)
{
    return (HW_RD_REG32(baseAddr + QSPI_INTR_STS_EN_CLR));
}

void QSPIIntrClear(uint32_t baseAddr, uint32_t intrFlag)
{
    uint32_t regVal = HW_RD_REG32(baseAddr + QSPI_INTR_STS_EN_CLR);
    regVal |= intrFlag;
    HW_WR_REG32(baseAddr + QSPI_INTR_STS_EN_CLR, regVal);
}

uint32_t QSPIIntrRawStatus(uint32_t baseAddr)
{
    return (HW_RD_REG32(baseAddr + QSPI_INTR_STS_RAW_SET));
}

void QSPISetMemAddrSpace(uint32_t baseAddr,
                         uint32_t chipSelect,
                         uint32_t memMappedPortSwitch)
{
    HW_WR_FIELD32(baseAddr + QSPI_SWITCH_REG, QSPI_SWITCH_REG_MMPT_S, memMappedPortSwitch);
}

void QSPISetCfgModeTxCmd(uint32_t baseAddr, qspiTxCmd_t qspiTxCmd)
{
    /* wait for QSPI to be idle */
    while (TRUE == QSPIIsBusy(baseAddr));
    /* Read value of the qspi command register */
    uint32_t regVal = HW_RD_REG32(baseAddr + QSPI_CMD_REG);

    /* Set value of all the fields for qspi command */
    HW_SET_FIELD(regVal, QSPI_CMD_REG, qspiTxCmd.txCmd);
    HW_SET_FIELD(regVal, QSPI_CMD_REG_FIRQ, qspiTxCmd.frameCntIntrVal);
    HW_SET_FIELD(regVal, QSPI_CMD_REG_WIRQ, qspiTxCmd.wordCntIntrVal);
    HW_SET_FIELD(regVal, QSPI_CMD_REG_WLEN, qspiTxCmd.wordLength - 1);
    HW_SET_FIELD(regVal, QSPI_CMD_REG_FLEN, qspiTxCmd.frameLength - 1);
    HW_SET_FIELD(regVal, QSPI_CMD_REG_CSNUM, qspiTxCmd.chipSelect);

    /* Set the value of QSPI command in the command register */
    HW_WR_REG32(baseAddr + QSPI_CMD_REG, regVal);
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

/* None */
