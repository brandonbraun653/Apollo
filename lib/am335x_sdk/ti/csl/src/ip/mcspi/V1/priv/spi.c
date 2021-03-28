/**
 *
 *  \file  spi.c
 *
 *  \brief File provides functional level APIs for Keystone SPI interface.
 */

/*
* Copyright (C) 2015-2016 Texas Instruments Incorporated - http://www.ti.com/
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

#include <ti/csl/src/ip/mcspi/V1/spi.h>
#include <ti/csl/hw_types.h>

/*******************************************************************************
*                       INTERNAL MACRO DEFINITIONS
*******************************************************************************/

/*******************************************************************************
*                        API FUNCTION DEFINITIONS
*******************************************************************************/

/**
* \brief  This API will enable the chip select pin.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return none.
*
**/
void SPICSEnable(uint32_t baseAdd, uint32_t cs)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIPC0;
    HWREG(temp_addr) |= ((1U) << cs);
    temp_addr = baseAdd + CSL_SPI_SPIDEF;
    HWREG(temp_addr) |= ((1U) << cs);
}

/**
* \brief  This API will disable the chip select pin.
*
* \param  baseAdd        Memory Address of the SPI instance used.
* \param  cs             SPI chip select.
*
* \return none.
**/
void SPICSDisable(uint32_t baseAdd, uint32_t cs)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIPC0;
    HWREG(temp_addr) &= ~((1U) << cs);
    temp_addr = baseAdd + CSL_SPI_SPIDEF;
    HWREG(temp_addr) &= ~((1U) << cs);
}

/**
* \brief  This API will configure the Pin Control register.
*
* \param  baseAdd        Memory Address of the SPI instance used.
* \param  somiFun        Slave Out Master In pin function.
* \param  simoFun        Slave In Master Out pin function.
* \param  clkFun         Clock pin function.
*
* \return none.
*
**/
void SPIPinControlSetup(uint32_t baseAdd, uint32_t somiFun,
                        uint32_t simoFun, uint32_t clkFun)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIPC0;
    uint32_t temp_val;

    temp_val = HWREG(temp_addr);

    temp_val &= ~(CSL_SPI_SPIPC0_SOMIFUN_MASK |
                  CSL_SPI_SPIPC0_SIMOFUN_MASK |
                  CSL_SPI_SPIPC0_CLKFUN_MASK);

    temp_val |= ((somiFun) << CSL_SPI_SPIPC0_SOMIFUN_SHIFT) | \
                 ((simoFun) << CSL_SPI_SPIPC0_SIMOFUN_SHIFT) | \
                 ((clkFun) << CSL_SPI_SPIPC0_CLKFUN_SHIFT);
    HWREG(temp_addr) = temp_val;
}

/**
* \brief  This API will enable the SPI transfers.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return none.
*
**/
void SPIXferEnable(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIGCR1;
    HWREG(temp_addr) |= CSL_SPI_SPIGCR1_ENABLE_MASK;
}

/**
* \brief  This API will disable the SPI transfers.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return none.
**/
void SPIXferDisable(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIGCR1;
    HWREG(temp_addr) &= ~CSL_SPI_SPIGCR1_ENABLE_MASK;
}

/**
* \brief  This API will enable the SPI internal loopback test mode.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return none.
*
**/
void SPILoopbackEnable(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIGCR1;
    HWREG(temp_addr) |= CSL_SPI_SPIGCR1_LOOPBACK_MASK;
}

/**
* \brief  This API will disable the SPI internal loopback test mode.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return none.
**/
void SPILoopbackDisable(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIGCR1;
    HWREG(temp_addr) &= ~CSL_SPI_SPIGCR1_LOOPBACK_MASK;
}

/**
* \brief  This API will enable the SPI power down mode.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return none.
*
**/
void SPIPwrDownEnable(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIGCR1;
    HWREG(temp_addr) |= CSL_SPI_SPIGCR1_POWERDOWN_MASK;
}

/**
* \brief  This API will disable the SPI power down mode.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return none.
**/
void SPIPwrDownDisable(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIGCR1;
    HWREG(temp_addr) &= ~CSL_SPI_SPIGCR1_POWERDOWN_MASK;
}

/**
* \brief  This API will reset the SPI peripheral.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return none.
**/
void SPIReset(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIGCR0;
    /* Reset SPI. */
    HWREG(temp_addr) = CSL_SPI_SPIGCR0_RESET_IN_RESET;

    /* Bring SPI out of reset. */
    HWREG(temp_addr) = CSL_SPI_SPIGCR0_RESET_OUT_OF_RESET;

    temp_addr = baseAdd + CSL_SPI_SPIDEF;
    HWREG(temp_addr) = 0;
}

/**
* \brief  This API will initialize SPI interrupt configuration.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return none.
*
**/
void SPIIntInit(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPILVL;
    /* Map SPI interrupts to interrupt line 0 by default. */
    HWREG(temp_addr) = 0;

    temp_addr = baseAdd + CSL_SPI_SPIINT0;
    /* Disable all interrupts on interrupt line 0 */
    HWREG(temp_addr) = 0;

    /* Clear all the interrupt status */
    SPIIntStatusClear(baseAdd, SPI_INT_RX_FULL | SPI_INT_RX_OVERRUN | SPI_INT_TX_BITERR);
}

/**
* \brief  This API will initialize SPI interrupt configuration.
*
*  This API provides the additonal paramter for interrupt level
*  configuration
*
* \param  baseAdd        Memory Address of the SPI instance used.
* \param  intrLine       Interupt line configuration
*                        SPI_INT_LINE_INT0 - Interrupt line configured to INT0
*                        SPI_INT_LINE_INT1 - Interrupt line configured to INT1
*
* \return none.
*
**/
void SPIIntInit2(uint32_t baseAdd, uint32_t intrLine)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPILVL;

    /* Map SPI interrupts to an interrupt line. */
    if(intrLine == SPI_INT_LINE_INT1)
    {
        HWREG(temp_addr) = SPI_INT_LEVEL_INT1;
    }
    else
    {
        HWREG(temp_addr) = SPI_INT_LEVEL_INT0;
    }

    temp_addr = baseAdd + CSL_SPI_SPIINT0;
    /* Disable all interrupts */
    HWREG(temp_addr) = 0;

    /* Clear all the interrupt status */
    SPIIntStatusClear(baseAdd, SPI_INT_RX_FULL | SPI_INT_RX_OVERRUN | SPI_INT_TX_BITERR);
}

/**
* \brief  This API will enable the SPI Interrupts.
*
* \param  baseAdd        Memory Address of the SPI instance used.
* \param  intFlags       Represents the various interrupts to be enabled.
* \param  csNum          Chip select number of the SPI instance used.\n
*
*         'intFlags' can take the following values.\n
*         SPI_INT_TX_EMPTY    - Transmitter empty \n
*         SPI_INT_RX_FULL     - Receiver full\n
*         SPI_INT_TX_OVERRUN  - Receiver buffer overrun \n
*         SPI_INT_BITERR      - Bit error \n
*
* \return none.
*
* \note   Please ensure the proper channel number is passed while using the
*         macros.
**/
void SPIIntEnable(uint32_t baseAdd, uint32_t intFlags)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIINT0;
    /* Enable the Interrupts. */
    HWREG(temp_addr) |= intFlags;
}

/**
* \brief  This API will disable the SPI Interrupts.
*
* \param  baseAdd        Memory Address of the SPI instance used.
* \param  intFlags       Represents the various interrupts to be disabled.
*
*         'intFlags' can take the following values.\n
*         SPI_INT_TX_EMPTY    - Transmitter empty \n
*         SPI_INT_RX_FULL     - Receiver full\n
*         SPI_INT_TX_OVERRUN  - Receiver buffer overrun \n
*         SPI_INT_BITERR      - Bit error \n
*
* \return none.
*
* \note   Please ensure the proper channel number is passed while using the
*         macros.
**/
void SPIIntDisable(uint32_t baseAdd, uint32_t intFlags)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIINT0;
    /* Disable the interrupts. */
    HWREG(temp_addr) &= ~intFlags;
}

/**
* \brief  This API will return the status of the SPI peripheral interrupts.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return This API will return the status of the SPI peripheral interrupts.
*         User can use the following macros to check the status \n
*         SPI_INT_TX_EMPTY    - Transmitter empty \n
*         SPI_INT_RX_FULL     - Receiver full\n
*         SPI_INT_TX_OVERRUN  - Receiver buffer overrun \n
*         SPI_INT_BITERR      - Bit error \n
*
**/
uint32_t SPIIntStatusGet(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIFLG;
    /* Return the interrupt status present in the SPI_CSL_SPI_SPILVL register. */
    return(HWREG(temp_addr));
}

/**
* \brief  This API will clear the status of SPI Interrupts.
*
* \param  baseAdd        Memory Address of the SPI instance used.
* \param  intFlags       Represents the various interrupts to be cleared.
*
* \return none.
*
* \note   Please ensure the proper channel number is used while passing the
*         macros passed.\n
**/
void SPIIntStatusClear(uint32_t baseAdd, uint32_t intFlags)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIFLG;
    /* Clear the interrupt status. */
    HWREG(temp_addr) = intFlags;
}

/**
* \brief  This API will put the data on to the SPIDAT1
*         transmit register.
*
* \param  baseAdd        Memory Address of the SPI instance used.
* \param  csHold         Chip Select hold mode.
* \param  txData         32 bit data sent by the user which is put on
*                        to the SPIDAT1 register.
*
* \return none.
**/
void SPITransmitData(uint32_t baseAdd, uint32_t csHold, uint32_t txData)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIDAT1;
	uint32_t spidat1 = HWREG(temp_addr);

	spidat1 &= ~(CSL_SPI_SPIDAT1_TXDATA_MASK | CSL_SPI_SPIDAT1_CSHOLD_MASK);
	spidat1 |= (csHold << CSL_SPI_SPIDAT1_CSHOLD_SHIFT) | txData;

    /* Load the SPI_TX register with the data to be transmitted */
    HWREG(temp_addr) = spidat1;
}

/**
* \brief  This API will return the data present in the SPIBUF register.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return This API will return the data received in the SPI_RX register.
**/
uint32_t SPIReceiveData(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIBUF;
    /* Return the data present in the SPI_RX register. */
    return(HWREG(temp_addr));
}

/**
 * \brief  This call will setup the SPIGCR1 register
 *         of the SPI peripheral.
 *
 * \param  baseAdd        Memory address of the SPI instance used.
 * \param  loopback       Loop back configuration.
 * \param  powerdown      Power down control.
 * \param  clk_master     clk mode, master mode..
 *
 *         'loopback' can take the following values.\n
 *         SPI_LOOPBACK_ON  - Internal loop-back test mode enabled.
 *         SPI_LOOPBACK_OFF - Internal loop-back test mode disabled.
 *
 *         'powerdown' can take the following values.\n
 *         SPI_POWERDOWN_ON  - The SPI is in power-down mode.\n
 *         SPI_POWERDOWN_OFF - The SPI is in active mode.\n
 *
 *         'clk_master' can take the following values.\n
 *         SPI_MASTER_MODE - MASTER MODE. SPICLK is an output and the SPI initiates transfers.\n
 *         SPI_SLAVE_MODE  - SLAVE MODE. SPICLK is an input and the SPI is an slave.\n
 *
 * \return none.
 **/
void SPIGlobalControlSetup(uint32_t baseAdd, uint32_t loopback,
                           uint32_t powerdown, uint32_t clk_master)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIGCR1;
    HWREG(temp_addr) = (loopback << CSL_SPI_SPIGCR1_LOOPBACK_SHIFT) | \
                                       (powerdown << CSL_SPI_SPIGCR1_POWERDOWN_SHIFT) | \
                                       (clk_master << CSL_SPI_SPIGCR1_MASTER_SHIFT);
}

/**
 * \brief  This call will setup the SPIFMTn register
 *         of the SPI peripheral.
 *
 * \param  baseAdd        Memory address of the SPI instance used.
 * \param  df_sel         SPI data format register selection.
 * \param  spiInClk       Clock frequency given to the SPI module.
 * \param  spiOutClk      Clock frequency on the SPI bus.
 * \param  shiftDir       Bit shift direction, 0: MSB first, 1: LSB first.
 * \param  clockMode      SPI clock polarity and phase.
 * \param  charLen        SPI data word length in bits.
 *
 * \return none.
 **/
void SPIDataFormatSetup(uint32_t baseAdd, uint32_t df_sel, uint32_t inputClkFreq,
                        uint32_t spiOutClk, uint32_t clockMode, uint32_t charLen)
{
    uint32_t prescale;
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIFMT(df_sel);

    /* SPI prescaler */
    prescale = (inputClkFreq / spiOutClk) - 1U;

    /* Clear the DFSEL field of SPI_SPIDAT1 register. */
    HWREG(temp_addr) = \
        ((charLen << CSL_SPI_SPIFMT_CHARLEN_SHIFT) & CSL_SPI_SPIFMT_CHARLEN_MASK) | \
        ((prescale << CSL_SPI_SPIFMT_PRESCALE_SHIFT) & CSL_SPI_SPIFMT_PRESCALE_MASK) | \
        clockMode;

    temp_addr = baseAdd + CSL_SPI_SPIDAT1;
    /* Clear the DFSEL field of SPI_SPIDAT1 register. */
    HWREG(temp_addr) &= ~CSL_SPI_SPIDAT1_DFSEL_MASK;

    /* Set the DFSEL field with the user sent value. */
    HWREG(temp_addr) |=
        (df_sel << CSL_SPI_SPIDAT1_DFSEL_SHIFT);
}

/**
 * \brief  This call will setup the SPIFMTn register
 *         of the SPI slave peripheral.
 *
 * \param  baseAdd        Memory address of the SPI instance used.
 * \param  df_sel         SPI data format register selection.
 * \param  charLen        SPI data word length in bits.
 *
 * \return none.
 **/
void SPIDataFormatSetupSlave(uint32_t baseAdd, uint32_t df_sel, uint32_t charLen)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIFMT(df_sel);

    /* Clear the DFSEL field of SPI_SPIDAT1 register. */
    HWREG(temp_addr) = \
        ((charLen << CSL_SPI_SPIFMT_CHARLEN_SHIFT) & CSL_SPI_SPIFMT_CHARLEN_MASK);

    temp_addr = baseAdd + CSL_SPI_SPIDAT1;
    /* Clear the DFSEL field of SPI_SPIDAT1 register. */
    HWREG(temp_addr) &= ~CSL_SPI_SPIDAT1_DFSEL_MASK;

    /* Set the DFSEL field with the user sent value. */
    HWREG(temp_addr) |=
        (df_sel << CSL_SPI_SPIDAT1_DFSEL_SHIFT);
}

/**
 * \brief  This call will setup clock polarity and phase in SPIFMTn register
 *         of the SPI peripheral.
 *
 * \param  baseAdd        Memory address of the SPI instance used.
 * \param  df_sel         SPI data format register selection.
 * \param  clockMode      SPI clock polarity and phase.
 *
 * \return none.
 **/
void SPIClockModeSetup(uint32_t baseAdd, uint32_t df_sel, uint32_t clockMode)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIFMT(df_sel);
    uint32_t temp_val;

    /* Get SPIFMTn register value */
    temp_val = HWREG(temp_addr);

    /* Clear the phase/polarity field of SPIFMTn register. */
    temp_val &= ~(CSL_SPI_SPIFMT_PHASE_MASK | CSL_SPI_SPIFMT_POLARITY_MASK);

    /* Set the phase/polarity field with the user sent value. */
    HWREG(temp_addr) = temp_val | clockMode;
}

/**
 * \brief  This call will setup the chip select delays
 *         of the SPI peripheral.
 *
 * \param  baseAdd        Memory address of the SPI instance used.
 * \param  c2tDelay       Chip-select-active-to-transmit-start delay.
 * \param  t2cDelay       Transmit-end-to-chip-select-inactive delay.
 *
 * \return none.
 **/
void SPIDelaySetup(uint32_t baseAdd, uint32_t c2tDelay, uint32_t t2cDelay)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIDELAY;
    HWREG(temp_addr) = \
        ((c2tDelay << CSL_SPI_SPIDELAY_C2TDELAY_SHIFT) & CSL_SPI_SPIDELAY_C2TDELAY_MASK) | \
        ((t2cDelay << CSL_SPI_SPIDELAY_T2CDELAY_SHIFT) & CSL_SPI_SPIDELAY_T2CDELAY_MASK);

    temp_addr = baseAdd + CSL_SPI_SPIFMT(0);
	if ((c2tDelay != 0U) && (t2cDelay != 0U))
	{
        HWREG(temp_addr) &= ~CSL_SPI_SPIFMT_DISCSTIMERS_MASK;
	}
	else
    {
        HWREG(temp_addr) |= CSL_SPI_SPIFMT_DISCSTIMERS_MASK;
    }
}

/**
 * \brief  This call will setup the chip select delays
 *         of the SPI peripheral.
 *
 * \param  baseAdd        Memory address of the SPI instance used.
 * \param  shift_dir      Bit shift direction (0: MSB shifted out first, 1: LSB first).
 * \param  t2cDelay       Transmit-end-to-chip-select-inactive delay.
 *
 * \return none.
 **/
void SPISetShiftDir(uint32_t baseAdd, uint32_t shift_dir)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIFMT(0);
	if (shift_dir)
	{
        HWREG(temp_addr) |= CSL_SPI_SPIFMT_SHIFTDIR_MASK;
	}
	else
    {
        HWREG(temp_addr) &= ~CSL_SPI_SPIFMT_SHIFTDIR_MASK;
    }
}

/**
 * \brief  This call will setup the SPIData1 register
 *         of the SPI peripheral.
 *
 * \param  baseAdd        Memory address of the SPI instance used.
 * \param  delay_enable   Enable the delay counter at the end of the current transaction.
 * \param  cs             Chip select number.
 *
 * \return none.
 **/
void SPIData1Setup(uint32_t baseAdd, uint32_t delay_enable, uint32_t cs)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIDAT1;
    HWREG(temp_addr) = \
        CSL_SPI_SPIDAT1_CSHOLD_MASK |
        ((delay_enable << CSL_SPI_SPIDAT1_WDEL_SHIFT) & CSL_SPI_SPIDAT1_WDEL_MASK) | \
        ((cs << CSL_SPI_SPIDAT1_CSNR_SHIFT) & CSL_SPI_SPIDAT1_CSNR_MASK);
}

/**
* \brief  This API will check if data receive buffer is full.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return This API will return the boolean value if data is received or not
*
**/
Bool SPIRxFull(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIFLG;
    Bool ret_val = FALSE;
    uint32_t flag = HWREG(temp_addr);

    if(flag & CSL_SPI_SPIFLG_RXINTFLG_MASK)
    {
        ret_val = TRUE;
    }
    else
    {
        ret_val = FALSE;
    }
    return(ret_val);
}

/**
* \brief  This API will check if transmit buffer is empty.
*
* \param  baseAdd        Memory Address of the SPI instance used.
*
* \return This API will return the boolean value if data is received or not
*
**/
Bool SPITxEmpty(uint32_t baseAdd)
{
    Bool ret_val = FALSE;
    uint32_t temp_addr = baseAdd + CSL_SPI_SPIFLG;
    uint32_t flag = HWREG(temp_addr);

    if(flag & CSL_SPI_SPIFLG_TXINTFLG_MASK)
    {
        ret_val = TRUE;
    }
    else
    {
        ret_val = FALSE;
    }
    return(ret_val);
}
