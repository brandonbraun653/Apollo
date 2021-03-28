/**
 * @file   uart.c
 *
 * @brief  This file contains the UART Device Abstraction Layer(DAL) APIs
 *         specific to IP version v0.
 */

/*
* Copyright (C) 2015-2017 Texas Instruments Incorporated - http://www.ti.com/
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

#include <stdint.h>
#include <ti/csl/src/ip/uart/V0/cslr_uart.h>
#include <ti/csl/src/ip/uart/V0/uart.h>
#include <ti/csl/hw_types.h>

/*****************************************************************************
**                FUNCTION DEFINITIONS
*****************************************************************************/

/**
 * \brief  This API configures the operating mode for the UART instance.
 *         The different operating modes are:
 *         - UART 16x\n
 *         - UART 13x\n
 *
 * \param   baseAdd   Memory address of the UART instance being used.
 * \param   modeFlag  A value which holds the mode number. This mode
 *                    number is referred from the MODESELECT field in MDR.
 *
 * 'modeFlag' can take one of the following values:
 * - UART16x_OPER_MODE - to switch to UART 16x operating mode\n
 * - UART13x_OPER_MODE - to switch to UART 13x operating mode\n
 *
 * \return  The mode number in the MODESELECT field of MDR before it
 *          was  modified.
 */
uint32_t UART_operatingModeSelect_v0(uint32_t baseAdd,
                                     uint32_t modeFlag)
{
    uint32_t operMode = 0;
    uint32_t temp_addr = baseAdd + CSL_UART_MDR;

    operMode = (HWREG(temp_addr) & CSL_UART_MDR_OSM_SEL_MASK);
    HWREG(temp_addr) = operMode;

    return operMode;
}

static inline uint32_t UART_divideRoundCloset(uint32_t divident,
                                              uint32_t divisor)
{
    return ((divident + (divisor/2U))/divisor);
}

/**
 * \brief   This API computes the divisor value for the specified operating
 *          mode. Not part of this API, the divisor value returned is written
 *          to the Divisor Latches to configure the Baud Rate.
 *
 * \param   moduleClk        The frequency of the input clock to the UART module
 * \param   modeFlag         A value which represents the current operating mode
 * \param   baudRate         The required baud rate of communication in bits
 *                           per second(bps)
 *
 * 'modeFlag' can take one of the following values:\n
 * - UART16x_OPER_MODE - indicating 16x operating mode\n
 * - UART13x_OPER_MODE - indicating 13x operating mode\n
 *
 * \return The divisor value computed for the specified mode.
 *
 * \note   Refer to the section in the user guide that specifies the baud rate
 *         computation method to find the supported values of baud rates.
 */
uint32_t UART_divisorValCompute_v0(uint32_t moduleClk,
                                   uint32_t baudRate,
                                   uint32_t modeFlag)
{
    uint32_t divisorValue = 0;

    modeFlag &= CSL_UART_MDR_OSM_SEL_MASK;

    switch(modeFlag)
    {
        case UART16x_OPER_MODE:
            divisorValue = UART_divideRoundCloset(moduleClk, 16U * baudRate);
        break;

        case UART13x_OPER_MODE:
            divisorValue = UART_divideRoundCloset(moduleClk, 13U * baudRate);
        break;

        default:
        break;
    }

    return divisorValue;
}

/**
 * \brief  This API is used to write the specified divisor value to Divisor
 *         Latch registers DLL and DLH.
 *
 * \param  baseAdd       Memory address of the UART instance being used.
 * \param  divisorValue  The 16-bit value whose least 8 bits go to DLL
 *                       and highest 8 bits go to DLH.
 *
 * \return A concatenated value of DLH and DLL registers(DLH:DLL, a 16-bit
 *         value) before they are modified in the current API.
 */
uint32_t UART_divisorLatchWrite_v0(uint32_t baseAdd,
                                   uint32_t divisorValue)
{
    volatile uint32_t lcrRegValue = 0;
    uint32_t divRegVal = 0;
    uint32_t temp_addr = 0;

    /* Switching to Register Configuration Mode B. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_CONFIG_MODE_B);

    temp_addr = baseAdd + CSL_UART_DLL;
    /* Collecting the current value of Divisor Latch Registers. */
    divRegVal = HWREG(temp_addr) & 0xFFU;
    temp_addr = baseAdd + CSL_UART_DLH;
    divRegVal |= ((HWREG(temp_addr) & 0xFFU) << 8U);

    /* Writing to Divisor Latch Low(DLL) register. */
    temp_addr = baseAdd + CSL_UART_DLL;
    HWREG(temp_addr) = (divisorValue & 0x00FFU);

    /* Writing to Divisor Latch High(DLH) register. */
    temp_addr = baseAdd + CSL_UART_DLH;
    HWREG(temp_addr) = ((divisorValue & 0xFF00U) >> 8);

    /* Switching to Register Configuration Mode B. */
    UART_regConfigModeEnable_v0(baseAdd, UART_REG_CONFIG_MODE_B);

    /* Restoring the value of LCR Register. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;

    return divRegVal;
}

/**
 * \brief  This API enables write access to Divisor Latch registers DLL and
 *         DLH.
 *
 * \param  baseAdd   Memory address of the UART instance being used.
 *
 * \return None.
 */
void UART_divisorLatchEnable_v0(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_UART_LCR;

    /* Enable access to Divisor Latch registers by setting LCR[7] bit. */
    HWREG(temp_addr) |= (CSL_UART_LCR_DLAB_ENABLE << CSL_UART_LCR_DLAB_SHIFT);
}

/**
 * \brief  This API disables write access to Divisor Latch registers DLL and
 *         DLH.
 *
 * \param  baseAdd   Memory address of the UART instance being used.
 *
 * \return None.
 *
 * \note   Disabling write access to Divisor Latch Registers enables access to
 *         MCR, FCR, IER, BLR, EBLR, RHR registers.
 */
void UART_divisorLatchDisable_v0(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_UART_LCR;

    /* Disabling access to Divisor Latch registers by clearing LCR[7] bit. */
    HWREG(temp_addr) &= ~(CSL_UART_LCR_DLAB_ENABLE << CSL_UART_LCR_DLAB_SHIFT);
}

/**
 * \brief  This API configures the specified Register Configuration mode for
 *         the UART.
 *
 * \param  baseAdd   Memory address of the UART instance being used.
 * \param  modeFlag  This specifies the register configuration mode to be
 *                   enabled.
 *
 * 'modeFlag' can take one of the following values:
 * - UART_REG_CONFIG_MODE_A - to enable Register Configuration Mode A\n
 * - UART_REG_CONFIG_MODE_B - to enable Register Configuration Mode B\n
 * - UART_REG_OPERATIONAL_MODE - to enable Register Operational Mode\n
 *
 * \return The contents of the Line Control Register(LCR) before it was
 *         modified.
 *
 * \note   Since the UART module registers that can be accessed at any time
 *         depends on the value in the Line Control Register(LCR), three
 *         register configuration modes have been defined, each corresponding
 *         to a specific state of the LCR. The three register configuration
 *         modes are:\n
 *         - Configuration Mode A: LCR[7] = 1 and LCR[7:0] != 0xBF.\n
 *         - Configuration Mode B: LCR[7:0] = 0xBF.\n
 *         - Operational Mode    : LCR[7] = 0.\n
 *
 *         Refer to the Register Listing in the UART peripheral
 *         document for more information.\n
 *
 */
uint32_t UART_regConfigModeEnable_v0(uint32_t baseAdd, uint32_t modeFlag)
{
    uint32_t lcrRegValue = 0;
    uint32_t temp_addr = baseAdd + CSL_UART_LCR;

    /* Preserving the current value of LCR. */
    lcrRegValue = HWREG(temp_addr);

    switch(modeFlag)
    {
        case UART_REG_CONFIG_MODE_A:
        case UART_REG_CONFIG_MODE_B:
            HWREG(temp_addr) = (modeFlag & 0xFFU);
        break;

        case UART_REG_OPERATIONAL_MODE:
            HWREG(temp_addr) &= 0x7FU;
        break;

        default:
        break;
    }

    return lcrRegValue;
}

/**
 * \brief  This API is used to introduce or to remove a Break condition.
 *
 * \param  baseAdd     Memory address of the UART instance being used.
 * \param  breakState  This specifies whether the break condition should be
 *                     introduced or removed.
 *
 * 'breakState' can take one of the following two values:
 * - UART_BREAK_COND_DISABLE - to disable the Break condition if it has
 *   already been enabled\n
 * - UART_BREAK_COND_ENABLE - to enable the Break condition\n
 *
 * \return None
 *
 * \note  When the Break Condition is imposed, the Transmitter output line TX
 *        goes low to alert the communication terminal.
 */
void UART_breakCtl_v0(uint32_t baseAdd, uint32_t breakState)
{
    uint32_t temp_addr = baseAdd + CSL_UART_LCR;

    /* Clearing the BREAK_EN bit in LCR. */
    HWREG(temp_addr) &= ~(CSL_UART_LCR_BC_ENABLE << CSL_UART_LCR_BC_SHIFT);

    /* Programming the BREAK_EN bit in LCR. */
    HWREG(temp_addr) |= (breakState & (CSL_UART_LCR_BC_ENABLE <<  CSL_UART_LCR_BC_SHIFT));
}

/**
 * \brief  This API configures the Line Characteristics for the
 *         UART instance. The Line Characteristics include:
 *         - Word length per frame\n
 *         - Number of Stop Bits per frame\n
 *         - Parity feature configuration\n
 *
 * \param   baseAdd     Memory address of the UART instance being used.
 * \param   wLenStbFlag Bit mask value of the bits pertaining to word
 *                      length selection and stop bits selection in LCR.
 * \param   parityFlag  Bit mask value of the bits pertaining to parity
 *                      feature selection in LCR.
 *
 * 'wLenStbFlag' can take one of the following macros:
 *  - (UART_FRAME_WORD_LENGTH_n | UART_FRAME_NUM_STB_1), where
 *    n = 5,6,7 or 8. -- This signifies that 1 stop bit and
 *    one among 5,6,7 and 8 bits are chosen as the word length
 *    per frame.
 *  - (UART_FRAME_WORD_LENGTH_n | UART_FRAME_NUM_STB_1_5_2), where
 *    n = 5,6,7 or 8. -- This signifies that the word length and
 *    number of stop bits per frame could be one among the below
 *    four choices:
 *    --- WL = 5          NUM_STB = 1.5
 *    --- WL = 6,7 or 8   NUM_STB = 2
 *
 * 'parityFlag' can take one of the following macros:
 *  - (UART_ODD_PARITY) - signifying that odd parity be enabled and the
 *     parity bit be represented in a default manner.\n
 *  - (UART_EVEN_PARITY) - signifying that even parity be enabled and the
 *     parity bit be represented in a default manner.\n
 *  - (UART_PARITY_REPR_1) - signifying that the parity bit be represented
 *     by a logic 1 in the transmitted and received data.\n
 *  - (UART_PARITY_REPR_0) - signifying that the parity bit be represented
 *     by a logic 0 in the transmitted and received data.\n
 *  - (UART_PARITY_NONE) - signifying that no parity be enabled.\n
 *
 * \return  None.
 */
void UART_lineCharacConfig_v0(uint32_t baseAdd,
                          uint32_t wLenStbFlag,
                          uint32_t parityFlag)
{
    uint32_t temp_addr = baseAdd + CSL_UART_LCR;

    /* Clearing the CHAR_LENGTH and NB_STOP fields in LCR.*/
    HWREG(temp_addr) &= ~(CSL_UART_LCR_STB_MASK | CSL_UART_LCR_WLS_MASK);
    /* Programming the CHAR_LENGTH and NB_STOP fields in LCR. */
    HWREG(temp_addr) |= (wLenStbFlag &
                                  (CSL_UART_LCR_STB_MASK | CSL_UART_LCR_WLS__8BITS));

    /* Clearing the PARITY_EN, PARITY_TYPE1 and PARITY_TYPE2 fields in LCR. */
    HWREG(temp_addr) &= ~(CSL_UART_LCR_SP_MASK |
                                   CSL_UART_LCR_EPS_MASK |
                                   CSL_UART_LCR_PEN_MASK);
    /* Programming the PARITY_EN, PARITY_TYPE1 and PARITY_TYPE2 fields in LCR.*/
    HWREG(temp_addr) |= (parityFlag & (CSL_UART_LCR_SP_MASK |
            CSL_UART_LCR_EPS_MASK |
            CSL_UART_LCR_PEN_MASK));

}

/**
 * \brief  This API configures the Parity feature for the UART.
 *
 * \param  baseAdd     Memory address of the UART instance being used
 * \param  parityFlag  This specifies the parity configuration to be
 *                     programmed to the Line Control Register(LCR)
 *
 * 'parityFlag' can take one of the following values:
 *  - (UART_ODD_PARITY) - signifying that odd parity be enabled and the parity
 *     bit be represented in a default manner\n
 *  - (UART_EVEN_PARITY) - signifying that even parity be enabled and the
 *     parity bit be represented in a default manner\n
 *  - (UART_ODD_PARITY_REPR_1) - signifying that odd parity be enabled and the
 *     parity bit be represented by a logic 1\n
 *  - (UART_EVEN_PARITY_REPR_0)- signifying that even parity be enabled and the
 *     parity bit be represented by a logic 0\n
 *  - (UART_PARITY_NONE) - signifying that no parity be enabled\n
 *
 * \return None
 */
void UART_parityModeSet_v0(uint32_t baseAdd, uint32_t parityFlag)
{
    uint32_t temp_addr = baseAdd + CSL_UART_LCR;

    HWREG(temp_addr) &= ~((CSL_UART_LCR_SP_MASK |
            CSL_UART_LCR_EPS_MASK |
            CSL_UART_LCR_PEN_MASK));

    /* Programming the PARITY_TYPE2, PARITY_TYPE1 and PARITY_EN fields of LCR. */
    HWREG(temp_addr) |= (parityFlag & (CSL_UART_LCR_SP_MASK |
            CSL_UART_LCR_EPS_MASK |
            CSL_UART_LCR_PEN_MASK));
}

/**
 * \brief  This API reads the Parity configuration being set in the UART.
 *
 * \param  baseAdd     Memory address of the UART instance being used
 *
 * \return This returs one of the following values:
 *  - (UART_ODD_PARITY) - signifying that odd parity is enabled and the parity
 *     bit is represented in a default manner\n
 *  - (UART_EVEN_PARITY) - signifying that even parity is enabled and the
 *     parity bit is represented in a default manner\n
 *  - (UART_ODD_PARITY_REPR_1) - signifying that odd parity is enabled and the
 *     parity bit is represented by a logic 1\n
 *  - (UART_EVEN_PARITY_REPR_0)- signifying that even parity is enabled and the
 *     parity bit is represented by a logic 0\n
 *  - (UART_PARITY_NONE) - signifying that no parity is enabled\n
 *
 */
uint32_t UART_parityModeGet_v0(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_UART_LCR;
    return (HWREG(temp_addr) & (CSL_UART_LCR_SP_MASK |
                                         CSL_UART_LCR_EPS_MASK |
                                         CSL_UART_LCR_PEN_MASK));
}

/**
 * \brief  This API configures the FIFO settings for the UART instance.
 *         Specifically, this does the following configurations:
 *         1> Configures the Receiver FIFO Trigger Level\n
 *         2> Configures the bits which clear/not clear the TX and RX FIFOs\n
 *         3> Configures the DMA mode of operation\n
 *
 * \param  baseAdd       Memory address of the UART instance being used.
 * \param  fifoConfig    This specifies the desired FIFO configurations.
 *                       Use the macro UART_FIFO_CONFIG to pass the required
 *                       FIFO settings.
 *
 * The parameters of UART_FIFO_CONFIG can take the following values:\n
 * -- rxTrig - the Receiver FIFO Trigger level\n
 * -- txClr - the Transmitter FIFO clear flag\n
 * -- rxClr - the Receiver FIFO clear flag\n
 *
 *    These can take the following values:
 *    0 - to not clear the FIFO\n
 *    1 - to clear the FIFO. Clearing the FIFO also results in resetting the
 *        FIFO counter logic to 0.\n
 *
 * -- dmaEnPath - specifies whether DMA Mode settings should be configured
 *    through FCR or SCR. This can take one of the following two values:
 *    UART_DMA_EN_PATH_FCR - to configure DMA through FCR\n
 *    UART_DMA_EN_PATH_SCR - to configure DMA through SCR\n
 *
 * -- dmaMode - specifies the DMA Mode to be used\n
 *    This can take one of the following four values:
 *    - UART_DMA_MODE_m_ENABLE, where m = 0, 1, 2 or 3.
 *
 * \return  The value that was written to the FIFO Control Register(FCR).
 *
 * \note    1> FIFO Control Register(FCR) is a write-only register and its
 *             contents cannot be read. Hence, it is  not possible for a
 *             read-modify-write operation on this register. Therefore it is
 *             expected that the FIFO configuration is done at once for both
 *             TX and RX directions and always the entire FCR related information is
 *             required during modification of the FIFO settings.
 *             Also the FIFO related settings are valid only when the FIFO is
 *             enabled. This means that FIFO mode of operation should be enabled for
 *             FIFO related settings to take effect.
 */
uint32_t UART_fIFOConfig_v0(uint32_t baseAdd,
                            uint32_t fifoConfig)
{
    uint32_t rxTrig = (fifoConfig & UART_FIFO_CONFIG_RXTRIG) >> 6U;
    uint32_t txClr = (fifoConfig & UART_FIFO_CONFIG_TXCLR) >> 5;
    uint32_t rxClr = (fifoConfig & UART_FIFO_CONFIG_RXCLR) >> 4;
    uint32_t dmaMode1 = (fifoConfig & UART_FIFO_CONFIG_DMAMODE1);
    uint32_t fcrValue;

    /* Writing 'fcrValue' to the FIFO Control Register(FCR). */
    fcrValue = UART_FCR_PROGRAM(rxTrig, dmaMode1, txClr, rxClr, UART_FIFO_ENABLE);
    UART_fIFORegisterWrite_v0(baseAdd, fcrValue);

    return fcrValue;
}

/**
 * \brief  This API is used to write a specified value to the FIFO Control
 *         Register(FCR).
 *
 * \param  baseAdd     Memory address of the UART instance being used.
 * \param  fcrValue    This specifies the value to be written to the
 *                     FCR.
 *
 * 'fcrValue' can be determined using a parameterized macro named
 * 'UART_FCR_PROGRAM'.
 * The parameters of 'UART_FCR_PROGRAM' are described below:
 * - rxFIFOTrig - specifies the Receiver FIFO Trigger Level\n
 * - dmaMode - specifies the DMA Mode of operation to be selected:\n
 *   Write 0 - for DMA Mode 1 disabled\n
 *         1 - for DMA Mode 1 enabled\n
 * - txClr - specifies whether or not to clear the Transmitter FIFO
 *   and resetting the counter logic to 0.\n
 * - rxClr - specifies whether or not to clear the Receiver FIFO and resetting
 *   the counter logic to 0.
 * - fifoEn - specifies whether to enable the FIFO mode for the UART or not\n
 *   0 - to enable Non-FIFO mode of operation\n
 *   1 - to enable FIFO mode of operation\n
 *
 * \return  None
 *
 * \note  1> The FIFO_EN and DMA_MODE bits of FCR can be written to only when
 *           the Baud Clock is not running(DLL and DLH register are cleared
 *           to 0). Modifying DLL and DLH registers in turn requires that the
 *           UART be operated in Disabled Mode(MDR[2:0] = 0x7).\n
 *        Prior to writing to the FCR, this API does the above operation.
 *        It also restores the respective bit values after FCR has been
 *        written to.\n
 */
void UART_fIFORegisterWrite_v0(uint32_t baseAdd, uint32_t fcrValue)
{
    uint32_t divLatchRegVal = 0;
    uint32_t lcrRegValue = 0;
    uint32_t temp_addr = 0;

    /* Switching to Register Configuration Mode A of operation. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_CONFIG_MODE_A);

    /* Clearing the contents of Divisor Latch Registers. */
    divLatchRegVal = UART_divisorLatchWrite_v0(baseAdd, 0x0000);

    /* Writing the 'fcrValue' to the FCR register. */
    temp_addr = baseAdd + CSL_UART_FCR;
    HWREG(temp_addr) = fcrValue;

    /* Programming the Divisor Latch Registers with the collected value. */
    UART_divisorLatchWrite_v0(baseAdd, divLatchRegVal);

    /* Reinstating LCR with its original value. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;
}

/**
 * \brief   This API enables the specified interrupts in the UART mode of
 *          operation.
 *
 * \param   baseAdd   Memory address of the UART instance being used.
 * \param   intFlag   Bit mask value of the bits corresponding to Interrupt
 *                    Enable Register(IER). This specifies the UART interrupts
 *                    to be enabled.
 *
 *  'intFlag' can take one or a combination of the following macros:
 *  - UART_INT_MODEM_STAT - to enable Modem Status interrupt,
 *  - UART_INT_LINE_STAT - to enable Line Status interrupt,
 *  - UART_INT_THR - to enable Transmitter Holding Register Empty interrupt,
 *  - UART_INT_RHR_CTI - to enable Receiver Data available interrupt and
 *                       Character timeout indication interrupt.
 *
 * \return  None.
 *
 * \note    This API modifies the contents of UART Interrupt Enable Register
 *          (IER).
 *          This API does the needful before it accesses IER.
 *          Moreover, this API should be called when UART is operating in
 *          UART 16x Mode, UART 13x Mode or UART 16x Auto-baud mode.\n
 *
 */
void UART_intEnable_v0(uint32_t baseAdd, uint32_t intFlag)
{
    uint32_t lcrRegValue;
    uint32_t temp_addr = 0;

    /* Switching to Register Operational Mode. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_OPERATIONAL_MODE);

    /*
    ** It is suggested that the System Interrupts for UART in the
    ** Interrupt Controller are enabled after enabling the peripheral
    ** interrupts of the UART using this API. If done otherwise, there
    ** is a risk of LCR value not getting restored and illicit characters
    ** transmitted or received from/to the UART. The situation is explained
    ** below.
    ** The scene is that the system interrupt for UART is already enabled and
    ** the current API is invoked. Executing the remaining statements is
    ** critical in that the LCR value is restored in them.
    ** However, there seems to be no risk in this API for enabling interrupts
    ** corresponding to IER[3:0] because it is done at the end and no
    ** statements follow that.
    */

    /* Programming the bits IER[3:0]. */
    temp_addr = baseAdd + CSL_UART_IER;
    HWREG(temp_addr) |= (intFlag & 0x0FU);

    /* Restoring the value of LCR. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;
}

/**
 * \brief   This API disables the specified interrupts in the UART mode of
 *          operation.
 *
 * \param   baseAdd   Memory address of the UART instance being used.
 * \param   intFlag   Bit mask value of the bits corresponding to Interrupt
 *                    Enable Register(IER). This specifies the UART interrupts
 *                    to be disabled.
 *
 *  'intFlag' can take one or a combination of the following macros:
 *  - UART_INT_MODEM_STAT - to disable Modem Status interrupt,
 *  - UART_INT_LINE_STAT - to disable Line Status interrupt,
 *  - UART_INT_THR - to disable Transmitter Holding Register Empty interrupt,
 *  - UART_INT_RHR_CTI - to disable Receiver Data available interrupt and
 *                       Character timeout indication interrupt.
 *
 * \return  None
 *
 * \note  The note section of UARTIntEnable() also applies to this API.
 */
void UART_intDisable_v0(uint32_t baseAdd, uint32_t intFlag)
{
    uint32_t lcrRegValue;
    uint32_t temp_addr = 0;

    /* Switching to Register Operational Mode. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_OPERATIONAL_MODE);
    temp_addr = baseAdd + CSL_UART_IER;
    HWREG(temp_addr) &= ~(intFlag & 0x0FU);

    /* Restoring the value of LCR. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;
}

/**
 * \brief    This API reads a byte from the Receiver Buffer Register
 *           (RBR). It checks once if any character is ready to be read.
 *
 * \param    baseAdd     Memory address of the UART instance being used.
 *
 * \return   If the RX FIFO was found to have atleast one byte of
 *           data, then this API reads and returns that byte. Else it
 *           returns -1.
 */
int8_t UART_charGetNonBlocking_v0(uint32_t baseAdd)
{
    uint32_t lcrRegValue = 0;
    int8_t retVal = (int8_t)-1;
    uint32_t temp_addr = 0;

    /* Switching to Register Operational Mode of operation. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_OPERATIONAL_MODE);

    /* Checking if the RX FIFO(or RHR) has atleast one byte of data. */
    temp_addr = baseAdd + CSL_UART_LSR;
    if(HWREG(temp_addr) & CSL_UART_LSR_DR_MASK)
    {
        temp_addr = baseAdd + CSL_UART_RBR;
        retVal = (int8_t)HWREG(temp_addr);
    }

    /* Restoring the value of LCR. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;

    return retVal;
}

/**
 * \brief    This API waits indefinitely for the arrival of a byte in
 *           the receiver FIFO. Once a byte has arrived, it returns that
 *           byte.
 *
 * \param    baseAdd     Memory address of the UART instance being used.
 *
 * \return   This returns the read byte.
 */
int8_t UART_charGet_v0(uint32_t baseAdd)
{
    uint32_t lcrRegValue = 0;
    int8_t retVal = 0;
    uint32_t temp_addr = 0;

    /* Switching to Register Operational Mode of operation. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_OPERATIONAL_MODE);

    /* Waits indefinitely until a byte arrives in the RX FIFO(or RHR). */
    temp_addr = baseAdd + CSL_UART_LSR;
    while(0U == (HWREG(temp_addr) & CSL_UART_LSR_DR_MASK))
    {}

    temp_addr = baseAdd + CSL_UART_RBR;
    retVal = ((int8_t)HWREG(temp_addr));

    /* Restoring the value of LCR. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;

    return retVal;
}

/**
 * \brief   This API waits for the arrival of atleast one byte into the
 *          Receiver FIFO or until a specified timeout value gets decremented
 *          to zero, whichever happens first.
 *
 * \param   baseAdd     Memory address of the UART instance being used.
 * \param   timeOutVal  The timeout value that is to be used. This timeout
 *                      value gets decremented once per iteration of the
 *                      wait loop.
 *
 * \return  This returns either of the below two values:\n
 *          1) If a character was keyed in before the timeout value gets
 *             decremented to zero, this API returns the entered byte.\n
 *          2) If no character was input within the timeout value getting
 *             decremented to zero, this API returns -1.\n
 */
int32_t UART_charGetTimeout_v0(uint32_t baseAdd, uint32_t timeOutVal)
{
    uint32_t lcrRegValue = 0;
    int32_t retVal = -1;
    uint32_t temp_addr = 0;
    uint32_t temp_val = 0;

    /* Switching to Register Operational Mode of operation. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_OPERATIONAL_MODE);

    /*
    ** Wait until either data is not received or the time out value is greater
    ** than zero.
    */
    temp_addr = baseAdd + CSL_UART_LSR;
    while((0U == (HWREG(temp_addr) & CSL_UART_LSR_DR_MASK)) && (timeOutVal != 0U))
    {
        timeOutVal--;
    }

    if(timeOutVal)
    {
        temp_addr = baseAdd + CSL_UART_RBR;
        temp_val = (HWREG(temp_addr) & 0x0FFU);
        retVal = (int32_t)(temp_val);
    }

    /* Restoring the value of LCR. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;

    return retVal;
}

/**
 * \brief   This API waits indefinitely until the Transmitter FIFO
 *          (THR register in non-FIFO mode) and Transmitter Shift
 *          Register are empty. On empty, it writes a byte to the THR.
 *
 * \param   baseAdd     Memory address of the UART instance being used
 * \param   byteTx      The byte to be transmitted by the UART.
 *
 * \return  None
 */
void UART_charPut_v0(uint32_t baseAdd, uint8_t byteTx)
{
    uint32_t lcrRegValue = 0;
    uint32_t temp_addr = 0;

    /* Switching to Register Operational Mode of operation. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_OPERATIONAL_MODE);

    /*
    ** Waits indefinitely until the THR and Transmitter Shift Registers are
    ** empty.
    */
    UART_fifoWait_v0(baseAdd);

    temp_addr = baseAdd + CSL_UART_THR;
    HWREG(temp_addr) = byteTx;

    /* Restoring the value of LCR. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;
}

/**
 * \brief   This API checks if the Transmitter FIFO and Transmitter
 *          Shift Register are empty.
 *
 * \param   baseAdd     Memory address of the UART instance being used
 *
 * \return  None
 */
uint32_t UART_fifoEmpty_v0(uint32_t baseAdd)
{
    uint32_t ret_val = 0;    
    uint32_t temp_addr = baseAdd + CSL_UART_LSR;
    if ((CSL_UART_LSR_TEMT_MASK | CSL_UART_LSR_THRE_MASK) ==
        (HWREG(temp_addr) & (CSL_UART_LSR_TEMT_MASK | CSL_UART_LSR_THRE_MASK)))
    {
        ret_val = (uint32_t)TRUE;
    }
    else
    {
        ret_val = (uint32_t)FALSE;
    }
    return(ret_val);
}


/**
 * \brief   This API waits indefinitely until the Transmitter FIFO
 *          (THR register in non-FIFO mode) and Transmitter Shift
 *          Register are empty.
 *
 * \param   baseAdd     Memory address of the UART instance being used
 *
 * \return  None
 */
void UART_fifoWait_v0(uint32_t baseAdd)
{
    while(UART_fifoEmpty_v0(baseAdd) != TRUE)
    {}
}

/**
 * \brief   This API writes a byte to the Transmitter FIFO without checking for
 *          the emptiness of the Transmitter FIFO or the Transmitter Shift
 *          Register(TSR).
 *
 * \param   baseAdd     Memory address of the UART instance being used.
 * \param   byteTx      The byte to be transmitted by the UART.
 *
 * \return  None
 *
 * \note    Unlike the APIs UARTCharPut() or UARTCharPutNonBlocking(), this
 *          API does not check for the emptiness of the TX FIFO or TSR. This
 *          API is ideal for use in FIFO mode of operation where the 64-byte
 *          TX FIFO has to be written with successive bytes. If transmit
 *          interrupt is enabled, it provides a mechanism to control the
 *          writes to the TX FIFO.
 */
void UART_fIFOCharPut_v0(uint32_t baseAdd, uint8_t byteTx)
{
   uint32_t temp_addr = baseAdd + CSL_UART_THR;
   /* Write the byte to the Transmit Holding Register(or TX FIFO). */
   HWREG(temp_addr) = byteTx;
}

/**
 * \brief   This API reads the data present at the top of the RX FIFO, that
 *          is, the data in the Receive Buffer Register(RBR). However
 *          before reading the data from RBR, it does not check whether
 *          RBR has fresh data or not.
 *
 * \param   baseAdd     Memory address of the UART instance being used.
 *
 * \return  The data read from the RHR.
 *
 * \note    1) Since this API does not check whether RX FIFO(RBR) has fresh
 *             data before reading the same, the application should ensure
 *             that RX FIFO has data before calling this API. The API
 *             UARTCharsAvail() can be used to check if the RX FIFO has
 *             atleast one byte of data.\n
 *          2) If the RX FIFO did not have any fresh data and this API is
 *             called, this API would return an unknown value.\n
 */
int8_t UART_fIFOCharGet_v0(uint32_t baseAdd)
{
    uint32_t temp_addr = baseAdd + CSL_UART_RBR;

    return((int8_t)HWREG(temp_addr));
}

/**
 * \brief  This API copies the requested amount of data from the
 *         pointed data block to the UART Transmit FIFO.
 *
 * \param  baseAdd     Memory address of the UART instance being used.
 * \param  pBuffer     The starting address of the data block.
 * \param  numTxBytes  The number of data bytes to be transmitted.
 *
 * \return The number of data bytes that were written to the TX FIFO.
 *
 * \note   This API does not check for the emptiness of the TX FIFO or for
 *         its space availability before writing to it. The application
 *         calling this API has the responsibility of checking the TX
 *         FIFO status before using this API.\n
 */
uint32_t UART_fIFOWrite_v0(uint32_t baseAdd, const uint8_t *pBuffer,
                           uint32_t numTxBytes)
{
    uint32_t lIndex = 0;
    uint32_t temp_addr = baseAdd + CSL_UART_THR;

    for(lIndex = 0; lIndex < numTxBytes; lIndex++)
    {
        /* Writing data to the TX FIFO. */
        HWREG(temp_addr) = *pBuffer;
        pBuffer++;
    }

    return lIndex;
}

/**
 * \brief  This API determines the UART Interrupt Status.
 *
 * \param  baseAdd   Memory address of the UART instance being used.
 *
 * \return This returns one or a combination of the following macros:
 *         - UART_INTID_MODEM_STAT - indicating the occurence of a Modem Status
 *           interrupt\n
 *         - UART_INTID_TX_THRES_REACH - indicating that the TX FIFO Threshold
 *           number of bytes can be written to the TX FIFO.
 *         - UART_INTID_RX_THRES_REACH - indicating that the RX FIFO has
 *           reached its programmed Trigger Level\n
 *         - UART_INTID_RX_LINE_STAT_ERROR - indicating the occurence of a
 *           receiver Line Status error\n
 *         - UART_INTID_CHAR_TIMEOUT - indicating the occurence of a Receiver
 *           Timeout\n
 *         - UART_INTID_XOFF_SPEC_CHAR_DETECT - indicating the detection of XOFF
 *           or a Special character\n
 *         - UART_INTID_MODEM_SIG_STATE_CHANGE - indicating that atleast one of
 *           the Modem signals among CTSn, RTSn and DSRn have changed states
 *           from active(low) to inactive(high)\n
 */
uint32_t UART_intIdentityGet_v0(uint32_t baseAdd)
{
    uint32_t lcrRegValue = 0;
    uint32_t retVal = 0;
    uint32_t temp_addr = baseAdd + CSL_UART_IIR;

    /* Switching to Register Operational Mode of operation. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_OPERATIONAL_MODE);

    retVal = (HWREG(temp_addr) & CSL_UART_IIR_INITD_MASK);

    /* Restoring the value of LCR. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;

    return retVal;
}

/**
 * \brief  This API configures the power and emulation management for the UART instance.
 *         Specifically, this does the following configurations:
 *         1> Reset and enable the UART transmitter\n
 *         2> Reset and enable the UART receiver\n
 *         3> enable free-running mode\n
 *
 * \param  baseAdd       Memory address of the UART instance being used.
 * \param  pwremuConfig  This specifies the desired power and emulation
 *                       management configurations.
 *
 * \return  The value that was written to the power emuluation management Register(PWREMU_MGMT).
 *
 */
uint32_t UART_pwremuConfig_v0(uint32_t baseAdd,
                            uint32_t pwremuConfig)
{
    uint32_t temp_addr = 0;
    temp_addr = baseAdd + CSL_UART_PWREMU_MGMT;
    HWREG(temp_addr) = pwremuConfig;

    return pwremuConfig;
}

/**
 * \brief  This API reads the line status register value.
 *
 * \param  baseAddr     Memory address of the UART instance being used.
 *
 *
 * \return This returns the line status register value.
 *
 */
uint32_t UART_readLineStatus_v0(uint32_t baseAddr)
{
    uint32_t lcrRegValue = 0;
    uint32_t retVal      = 0;

    /* Switching to Register Operational Mode of operation. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAddr, UART_REG_OPERATIONAL_MODE);

    retVal = HWREG(baseAddr + CSL_UART_LSR);

    /* Restoring the value of LCR. */
    HWREG(baseAddr + CSL_UART_LCR) = lcrRegValue;

    return retVal;
}

void UART_loopbackModeControl_v0(uint32_t baseAddr, uint32_t controlFlag)
{
    uint32_t temp_addr = baseAddr + CSL_UART_MCR;

    HWREG(temp_addr) &= ~CSL_UART_MCR_LOOP_MASK;

    /* Programming the LOOP bit in MCR. */
    HWREG(temp_addr) |= controlFlag;
}

uint32_t UART_charGetNonBlocking2_v0(uint32_t baseAdd, uint8_t *pChar)
{
    uint32_t lcrRegValue = 0;
    uint32_t retVal = FALSE;
    uint32_t temp_addr = 0;

    /* Switching to Register Operational Mode of operation. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_OPERATIONAL_MODE);

    /* Checking if the RX FIFO(or RHR) has atleast one byte of data. */
    temp_addr = baseAdd + CSL_UART_LSR;
    if(HWREG(temp_addr) & CSL_UART_LSR_DR_MASK)
    {
        temp_addr = baseAdd + CSL_UART_RBR;
        *pChar = (uint8_t)HWREG(temp_addr);
        retVal = TRUE;
    }

    /* Restoring the value of LCR. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;

    return retVal;
}

uint32_t UART_charGetTimeout2_v0(uint32_t baseAdd, uint32_t timeOutVal, uint8_t *pChar)
{
    uint32_t lcrRegValue = 0;
    uint32_t retVal = FALSE;
    uint32_t temp_addr = 0;
    uint32_t temp_val = 0;

    /* Switching to Register Operational Mode of operation. */
    lcrRegValue = UART_regConfigModeEnable_v0(baseAdd, UART_REG_OPERATIONAL_MODE);

    /*
    ** Wait until either data is not received or the time out value is greater
    ** than zero.
    */
    temp_addr = baseAdd + CSL_UART_LSR;
    while((0U == (HWREG(temp_addr) & CSL_UART_LSR_DR_MASK)) && (timeOutVal != 0U))
    {
        timeOutVal--;
    }

    if(timeOutVal)
    {
        temp_addr = baseAdd + CSL_UART_RBR;
        temp_val = (HWREG(temp_addr) & 0x0FFU);
        *pChar = (uint8_t)(temp_val);
        retVal = TRUE;
    }

    /* Restoring the value of LCR. */
    temp_addr = baseAdd + CSL_UART_LCR;
    HWREG(temp_addr) = lcrRegValue;

    return retVal;
}
/********************************* End of File ******************************/
