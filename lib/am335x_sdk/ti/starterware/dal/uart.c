/**
 * \file   uart.c
 *
 * \brief  This file contains the Device Abstraction Layer(DAL) APIs
 *         for UART module. These APIs are used for configuration
 *         of instance, transmission and reception of data.
 */

/**
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
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

#include "types.h"
#include "hw_types.h"
#include "error.h"
#include "hw_uart.h"
#include "uart.h"

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/**
 *  \name UART Register Access Modes
 */
/** @{ */
/** \brief Macro representing Register Access Mode A. */
#define UART_REG_MODE_A                  (0x80U)

/** \brief Macro representing Register Access Mode B.*/
#define UART_REG_MODE_B                  (0xBFU)

/** \brief Macro representing Register Access Operational Mode. */
#define UART_REG_MODE_OPER               (0x7FU)
/** @} */

/**
 *  \name UART operational modes and its corresponding divisor values for Baud
 *        Rate computation.
 */
/** @{ */
/** \brief Macro representing UART16X mode of operation. */
#define UART_16X_MODE                    (UART_MDR1_MODESELECT_MODE_16X)

/** \brief Macro representing UART16X mode divisor to calculate the Baud Rate.*/
#define UART_16X_MODE_DIVISOR            (16U)

/** \brief Macro representing UART13X mode of operation. */
#define UART_13X_MODE                    (UART_MDR1_MODESELECT_MODE_13X)

/** \brief Macro representing UART13X mode divisor to calculate the Baud Rate.*/
#define UART_13X_MODE_DIVISOR            (13U)
/** @} */

/**  \brief Macro representing the shift value for the MSB of Divisor value. */
#define UART_DLH_MSB_SHIFT                (8U)

/**  \brief Macro representing the Mask value to identify the triggerlevel
            to be set in TLR register. */
#define UART_FIFO_TLR_MASK                (0x003CU)

/**  \brief Macro representing the Mask value to identify the triggerlevel
            to be set in FCR register. */
#define UART_FIFO_FCR_MASK                (0x03U)

/*****************************************************************************
**                FUNCTION DEFINITIONS
*****************************************************************************/

uint16_t UARTGetRevision(uint32_t baseAddr)
{
    return (HW_RD_REG16(baseAddr + UART_MVR));
}

void UARTModuleReset(uint32_t baseAddr)
{
    /* Performing Software Reset of the module. */
    HW_WR_FIELD16(baseAddr + UART_SYSC, UART_SYSC_SOFTRESET,
                    UART_SYSC_SOFTRESET_RESET);

    /* Wait until the process of Module Reset is complete. */
    while(1U != HW_RD_FIELD16(baseAddr + UART_SYSS, UART_SYSS_RESETDONE));
}

uint16_t UARTSetRegAccessMode(uint32_t baseAddr, uint32_t accessMode)
{
    uint16_t lcrRegVal = 0U;
    uint16_t regVal = 0U;

    /* Save the Current value of LCR register */
    lcrRegVal = HW_RD_REG16(baseAddr + UART_LCR);
    regVal = lcrRegVal;

    switch(accessMode)
    {
        case UART_REG_ACCESS_MODE_A:
             /* Set LCR value to switch to Register Access Mode A */
             regVal = UART_REG_MODE_A;
        break;
        case UART_REG_ACCESS_MODE_B:
            /* Set LCR value to switch to Register Access Mode B */
            regVal = UART_REG_MODE_B;
        break;
        case UART_REG_ACCESS_MODE_OPER:
             /* Set LCR value to switch to Register Access Operational Mode */
             regVal = (regVal & UART_REG_MODE_OPER);
        break;

        default:
        break;
    }

    /* Write the value to the LCR to change the mode */
    HW_WR_REG16(baseAddr + UART_LCR, regVal);

    /* Return the original value of LCR. */
    return lcrRegVal;
}

void UARTSetBaudRate(uint32_t baseAddr, uint32_t moduleClk, uint32_t baudRate)
{
    uint16_t divisorVal = 0U;
    uint16_t operMode = 0U;
    uint16_t enhanFnBit = 0U;
    uint16_t sleepModeBit = 0U;
    uint16_t lcrRegVal = 0U;
    uint16_t lsbDivisorVal = 0U;
    uint16_t msbDivisorVal = 0U;

    /* Compute the divisor value */
    if((baudRate <= UART_BAUD_RATE_230400) ||
       (baudRate == UART_BAUD_RATE_3000000))
    {
        divisorVal = (uint16_t) (moduleClk/(UART_16X_MODE_DIVISOR * baudRate));
        operMode = UART_16X_MODE;
    }
    else
    {
        divisorVal = (uint16_t) (moduleClk/(UART_13X_MODE_DIVISOR * baudRate));
        operMode = UART_13X_MODE;
    }

    /* Extract the LSB and MSB values */
    lsbDivisorVal = (divisorVal & UART_DLL_CLOCK_LSB_MASK);
    msbDivisorVal = ((divisorVal & UART_DLH_CLOCK_MSB_MASK)
                        >> UART_DLH_MSB_SHIFT);

    /* Disable UART to access DLH and DLL registers */
    HW_WR_FIELD16(baseAddr + UART_MDR1, UART_MDR1_MODESELECT,
                    UART_MDR1_MODESELECT_MODE_DISABLE);

    /* Switch to Register Access Mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collecting the current value of EFR[4] and later setting it. */
    enhanFnBit = HW_RD_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN,
                    UART_EFR_ENHANCEDEN_ENABLE);

    /* Restore the value of LCR. */
    HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);

    /* Switch to Register Operational Mode. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    /*
    ** Collecting the current value of IER[4](SLEEPMODE bit) and later
    ** clearing it.
    */
    sleepModeBit = HW_RD_FIELD16(baseAddr + UART_IER, UART_IER_SLEEPMODE);
    HW_WR_FIELD16(baseAddr + UART_IER, UART_IER_SLEEPMODE,
                    UART_IER_SLEEPMODE_DISABLE);

    /* Restore the value of LCR. */
    HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);

    /* Switch to Register Access Mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Set the LSB and MSB value of the divisor value */
    HW_WR_FIELD16(baseAddr + UART_DLL, UART_DLL_CLOCK_LSB, lsbDivisorVal);
    HW_WR_FIELD16(baseAddr + UART_DLH, UART_DLH_CLOCK_MSB, msbDivisorVal);

    /* Restore the value of LCR. */
    HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);

    /* Switch to Register Operational Mode. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);
    HW_WR_FIELD16(baseAddr + UART_IER, UART_IER_SLEEPMODE, sleepModeBit);

    /* Restore the value of LCR. */
    HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);

    /* Switch to Register Access Mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN, enhanFnBit);

    /* Set the new operational mode for the corresponding Baud rate */
    HW_WR_FIELD16(baseAddr + UART_MDR1, UART_MDR1_MODESELECT, operMode);

    /* Restoring the value of LCR Register. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

void UARTIntrEnable(uint32_t baseAddr, uint32_t intrMask)
{
    uint16_t enhanFnBitVal = 0U;
    uint16_t lcrRegVal = 0U;

    if((intrMask & 0xF0U) > 0U)
    {
        /* Switch to Register Access Mode B. */
        lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

        /* Collecting the current value of EFR[4] and later setting it. */
        enhanFnBitVal = HW_RD_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN);
        HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN,
                        UART_EFR_ENHANCEDEN_ENABLE);

        /* Restore the value of LCR. */
        HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);

        /* Switch to Operational mode. */
        lcrRegVal =
             UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

        /* Programming the bits IER[7:4]. */
        HW_WR_REG16(baseAddr + UART_IER, intrMask & 0xF0U);

        /* Restore the value of LCR. */
        HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);

        /* Switch to Register Access Mode B. */
        lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

         /* Restore the value of EFR[4] to its original value */
        HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN, enhanFnBitVal);

        /* Restore the original value of LCR. */
        HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
    }

    /* Programming the bits IER[3:0]. */
    HW_WR_REG16(baseAddr + UART_IER, HW_RD_REG16(baseAddr + UART_IER) |
                (intrMask & 0x0FU));
}

void UARTIntrDisable(uint32_t baseAddr, uint32_t intrMask)
{
    uint16_t enhanFnBitVal = 0U;
    uint16_t lcrRegVal = 0U;

    /* Switch to mode B only when the upper 4 bits of IER needs to be changed */
    if ((intrMask & 0xF0U) > 0U)
    {
        /* Switch to Register Access Mode B. */
        lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

        /* Collecting the current value of EFR[4] and later setting it. */
        enhanFnBitVal = HW_RD_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN);
        HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN,
                        UART_EFR_ENHANCEDEN_ENABLE);

        /* Restore the value of LCR. */
        HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);
    }

    /* Switch to Register Operational Mode of operation. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    HW_WR_REG16(baseAddr + UART_IER, HW_RD_REG16(baseAddr + UART_IER) &
                ~(intrMask & 0xFFU));

    /* Restore the value of LCR. */
    HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);

    /* Switch to mode B only when the upper 4 bits of IER needs to be changed */
    if ((intrMask & 0xF0U) > 0U)
    {
        /* Switching to Register Configuration Mode B. */
        lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

        /* Restore the value of EFR[4] to its original value. */
        HW_WR_FIELD32(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN, enhanFnBitVal);

        /* Restore the value of LCR. */
        HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);
    }
}

uint16_t UARTIntrStatus(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint16_t status = 0U;

    /* Switch to Register Operational Mode. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    status = HW_RD_FIELD16(baseAddr + UART_IIR, UART_IIR_IT_TYPE);

    /* Restore the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return status;
}

uint32_t UARTIsIntrPending(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint32_t status = FALSE;

    /* Switch to Register Operational Mode of operation. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    if(UART_IIR_IT_PENDING_TRUE ==
            HW_RD_FIELD16((baseAddr + UART_IIR), UART_IIR_IT_PENDING));
    {
        status = TRUE;
    }

    /* Restoring the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return status;
}

void UARTTxEmptyIntrEnable(uint32_t baseAddr, uint32_t enableTxEmptyIntr)
{
    if( TRUE == enableTxEmptyIntr)
    {
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_TXEMPTYCTLIT,
                            UART_SCR_TXEMPTYCTLIT_THR_INT);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_TXEMPTYCTLIT,
                            UART_SCR_TXEMPTYCTLIT_NORMAL);
    }
}

uint16_t UARTLineStatus(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint16_t status = 0U;

    /* Switch to Register Operational Mode of operation. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    status = HW_RD_REG16(baseAddr + UART_LSR);

    /* Restoring the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return status;
}

void UARTLineCharacteristicConfig(uint32_t baseAddr,
                                  uint32_t charLen,
                                  uint32_t stopBit,
                                  uint32_t parity)
{
    uint16_t regVal = 0U;

    /* Read the Line Control Register */
    regVal = HW_RD_REG16(baseAddr + UART_LCR);
    /* Set the Character length to be transmitted in a frame */
    HW_SET_FIELD(regVal, UART_LCR_CHAR_LENGTH, charLen);
    /* Set the number of Stop bits */
    HW_SET_FIELD(regVal, UART_LCR_NB_STOP, stopBit);

    /* Enable the Parity generation feature for UART */
    HW_SET_FIELD(regVal, UART_LCR_PARITY_EN, UART_LCR_PARITY_EN_GENERATED);

    switch(parity)
    {
        case UART_PARITY_NONE:
             HW_SET_FIELD(regVal, UART_LCR_PARITY_EN,
                            UART_LCR_PARITY_EN_NOT_GENERATED);
        break;

        case UART_PARITY_ODD:
             HW_SET_FIELD(regVal, UART_LCR_PARITY_TYPE1,
                            UART_LCR_PARITY_TYPE1_ODD);
        break;

        case UART_PARITY_EVEN:
              HW_SET_FIELD(regVal, UART_LCR_PARITY_TYPE1,
                            UART_LCR_PARITY_TYPE1_EVEN);
        break;

        case UART_PARITY_MARK:
            HW_SET_FIELD(regVal, UART_LCR_PARITY_TYPE2,
                            UART_LCR_PARITY_TYPE2_LCR5_1);

            HW_SET_FIELD(regVal, UART_LCR_PARITY_TYPE1,
                            UART_LCR_PARITY_TYPE1_ODD);

        break;

        case UART_PARITY_SPACE:
            HW_SET_FIELD(regVal, UART_LCR_PARITY_TYPE2,
                            UART_LCR_PARITY_TYPE2_LCR5_1);

            HW_SET_FIELD(regVal, UART_LCR_PARITY_TYPE1,
                            UART_LCR_PARITY_TYPE1_EVEN);

        break;

        default:
        break;
    }

    /* Configure the Line Characteristic for UART */
    HW_WR_REG16(baseAddr + UART_LCR, (uint16_t) regVal);
}

void UARTFifoConfig(uint32_t baseAddr, uartFifoCfg_t  *pFifoCfg)
{
    uint16_t fcrVal = 0U;
    uint16_t lcrRegVal = 0U;
    uint16_t enhanFnBitVal = 0U;
    uint16_t tcrTlrBitVal = 0U;
    uint16_t triggerVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collect the current value of EFR[4] bit and later set it. */
    enhanFnBitVal = HW_RD_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN,
                UART_EFR_ENHANCEDEN_ENABLE);

    /* Restore the value of LCR. */
    HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);

    /* Switch to Register Access mode A to access TCR/TLR registers */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    /* Collecting the bit value of MCR[6] bit . */
    tcrTlrBitVal = HW_RD_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR);

    /*
    ** Set the TCRTLR bit of MCR register to enable access to TCR/TLR register.
    */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR, UART_MCR_TCRTLR_ENABLE);

    /* Enable the FIFO mode of operation */
    HW_SET_FIELD(fcrVal, UART_FCR_FIFO_EN, UART_FCR_FIFO_EN_ENABLE);

    if(TRUE == pFifoCfg->enableDma)
    {
        /*
        ** Ensure the SCR[0] bit is cleared to enable DMA through FCR register.
        */
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_DMAMODECTL,
                        UART_SCR_DMAMODECTL_FCR_3);
        /* Enable the DMA mode for UART FIFO operation */
        HW_SET_FIELD(fcrVal, UART_FCR_DMA_MODE, UART_FCR_DMA_MODE_1);
    }
    else
    {
        /* Disable the DMA mode for UART FIFO operation */
         HW_SET_FIELD(fcrVal, UART_FCR_DMA_MODE, UART_FCR_DMA_MODE_0);
    }

    /* Clear the Tx Fifos */
    if(TRUE == pFifoCfg->clearTxFifo)
    {
        HW_SET_FIELD(fcrVal, UART_FCR_TX_FIFO_CLR, UART_FCR_TX_FIFO_CLR_CLEAR);
    }
    else
    {
        HW_SET_FIELD(fcrVal, UART_FCR_TX_FIFO_CLR,
                        UART_FCR_TX_FIFO_CLR_NO_CHANGE);
    }

    /* Clear the Rx Fifos */
    if(TRUE == pFifoCfg->clearRxFifo)
    {
        HW_SET_FIELD(fcrVal, UART_FCR_RX_FIFO_CLR, UART_FCR_RX_FIFO_CLR_CLEAR);
    }
    else
    {
        HW_SET_FIELD(fcrVal, UART_FCR_RX_FIFO_CLR,
                        UART_FCR_RX_FIFO_CLR_NO_CHANGE);
    }

    /* Set the Receive Trigger levels */
    if(UART_TRIGGER_LVL_GRAN_1 != pFifoCfg->uartRxGran)
    {
        /* Disable the Rx Trigger Level Granularity of 1 */
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_RXTRIGGRANU1,
                            UART_SCR_RXTRIGGRANU1_DISABLE);

        /*
        ** Rx Trigger level will be a multiple of 4. The trigger level is
        ** programmed through the TLR register.
        */
        HW_WR_FIELD16(baseAddr + UART_TLR, UART_TLR_RX_FIFO_TRIG_DMA,
                            pFifoCfg->uartRxTriggerLvl);
    }
    else
    {
        /* Collecting the bits uartRxTriggerLvl[5:2] corresponding to TLR value */
        triggerVal = (pFifoCfg->uartRxTriggerLvl & UART_FIFO_TLR_MASK) >> 2U;

        HW_WR_FIELD16(baseAddr + UART_TLR, UART_TLR_RX_FIFO_TRIG_DMA,
                        triggerVal);

        /*
        ** Rx Trigger shall be a 6-bit trigger value a concatenation of a
        ** RX_FIFO_TRIG_DMA and RX_FIFO_TRIG fields from TLR and FCR register.
        */
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_RXTRIGGRANU1,
                            UART_SCR_RXTRIGGRANU1_ENABLE);

        HW_SET_FIELD(fcrVal, UART_FCR_RX_FIFO_TRIG,
                            (pFifoCfg->uartRxTriggerLvl & UART_FIFO_FCR_MASK));
    }

    /* Set the Transmit Trigger levels */
    if(UART_TRIGGER_LVL_GRAN_1 != pFifoCfg->uartTxGran)
    {
        /* Disable the Rx Trigger Level Granularity of 1 */
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_TXTRIGGRANU1,
                            UART_SCR_TXTRIGGRANU1_DISABLE);

        /*
        ** Tx Trigger level will be a multiple of 4. The trigger level is
        ** programmed through the TLR register.
        */
        HW_WR_FIELD16(baseAddr + UART_TLR,  UART_TLR_TX_FIFO_TRIG_DMA,
                        pFifoCfg->uartTxTriggerLvl);
    }
    else
    {
        /* Collecting the bits rxTrig[5:2] corresponding to TLR value */
        triggerVal = (pFifoCfg->uartTxTriggerLvl & UART_FIFO_TLR_MASK) >> 2U;

        HW_WR_FIELD16(baseAddr + UART_TLR, UART_TLR_TX_FIFO_TRIG_DMA,
                        triggerVal);

        /*
        ** Tx Trigger shall be a 6-bit trigger value a concatenation of a
        ** TX_FIFO_TRIG_DMA and RX_FIFO_TRIG fields from TLR and FCR register.
        */
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_TXTRIGGRANU1,
                            UART_SCR_TXTRIGGRANU1_ENABLE);

        HW_SET_FIELD(fcrVal, UART_FCR_TX_FIFO_TRIG,
                        (pFifoCfg->uartTxTriggerLvl & UART_FIFO_FCR_MASK));
    }

    /* Write to the FCR register with the FIFO configuration */
    HW_WR_REG16(baseAddr + UART_FCR, (uint16_t) fcrVal);

    /* Restore the TCRTLR bit value saved earlier in Reg Access Mode A. */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR, tcrTlrBitVal);

    /* Restore the value of LCR. */
    HW_WR_REG32(baseAddr + UART_LCR, lcrRegVal);

    /* Switch to Register Access Mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restore the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

uint32_t UARTIsFifoEnabled(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint32_t status = FALSE;

    /* Switch to Register Operational Mode of operation. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    if(UART_IIR_FCR_MIRROR_MASK ==
        HW_RD_FIELD16((baseAddr + UART_IIR), UART_IIR_FCR_MIRROR))
    {
        status = TRUE;
    }

    /* Restoring the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return status;
}

void UARTWakeupEventEnable(uint32_t baseAddr, uint32_t wakeupEvent)
{
    uint32_t regVal = 0U;

    /*
    ** Check if the Wakeup feature is enabled, if not then enable it
    ** before enabling any wakeup source events.
    */
    if(0U == HW_RD_FIELD16(baseAddr + UART_SYSC, UART_SYSC_ENAWAKEUP))
    {
        /* Enable the Wakeup control feature */
        HW_WR_FIELD16(baseAddr + UART_SYSC, UART_SYSC_ENAWAKEUP,
                        UART_SYSC_ENAWAKEUP_ENABLED);
    }

    /* Enable the specific wakeup event source*/
    regVal = HW_RD_REG16(baseAddr + UART_WER);
    regVal |= wakeupEvent;
    HW_WR_REG16(baseAddr + UART_WER, (uint16_t) regVal);
}

void UARTWakeupEventDisable(uint32_t baseAddr, uint32_t wakeupEvent)
{
    uint32_t regVal = 0U;

    /* Disable the specific wakeup event source */
    regVal = HW_RD_REG16(baseAddr + UART_WER);
    regVal &= ~wakeupEvent;
    HW_WR_REG16(baseAddr + UART_WER, (uint16_t) regVal);

    regVal = HW_RD_REG16(baseAddr + UART_WER);

    /* Disable the specific wakeup event source */
    if(1U != (regVal & UART_WAKEUP_EVT_ALL))
    {
        /* Disable the Wakeup control feature */
        HW_WR_FIELD16(baseAddr + UART_SYSC, UART_SYSC_ENAWAKEUP,
                        UART_SYSC_ENAWAKEUP_DISABLED);
    }
}

void UARTWakeupIntrEnable(uint32_t baseAddr, uint32_t enableWakeupIntr)
{
    if( TRUE == enableWakeupIntr)
    {
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SSR_RXCTSDSRWAKEUPSTS,
                        UART_SSR_RXCTSDSRWAKEUPSTS_FALLING_EDGE_EVT);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SSR_RXCTSDSRWAKEUPSTS,
                        UART_SSR_RXCTSDSRWAKEUPSTS_NO_FALLING_EDGE_EVT);
    }
}

void UARTAutoIdleEnable(uint32_t baseAddr, uint32_t enableIdleMode)
{
    if(TRUE == enableIdleMode)
    {
        HW_WR_FIELD16(baseAddr + UART_SYSC, UART_SYSC_AUTOIDLE,
                        UART_SYSC_AUTOIDLE_RUNNING);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_SYSC, UART_SYSC_AUTOIDLE,
                        UART_SYSC_AUTOIDLE_RSVD);
    }
}

void UARTSetIdleMode(uint32_t baseAddr, uint32_t idleMode)
{
    HW_WR_FIELD16((baseAddr + UART_SYSC), UART_SYSC_IDLEMODE, idleMode);
}

void UARTLoopbackEnable(uint32_t baseAddr, uint32_t enableLoopBack)
{
    if(TRUE == enableLoopBack)
    {
        HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_LOOPBACKEN,
                        UART_MCR_LOOPBACKEN_ENABLE);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_SYSC, UART_MCR_LOOPBACKEN,
                        UART_MCR_LOOPBACKEN_NORMAL);
    }
}

void UARTBreakCtrlEnable(uint32_t baseAddr, uint32_t enableBrkCtrl)
{
    if(TRUE == enableBrkCtrl)
    {
        HW_WR_FIELD16(baseAddr + UART_LCR, UART_LCR_BREAK_EN,
                        UART_LCR_BREAK_EN_FORCE_OUTPUT);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_LCR, UART_LCR_BREAK_EN,
                        UART_LCR_BREAK_EN_NORMAL);
    }
}

uint16_t UARTGetFifoLevel(uint32_t baseAddr, uint32_t fifoType)
{
    uint16_t status = 0U;

    if(UART_FIFO_TX == fifoType)
    {
        /* Return the TX Fifo status */
        status = HW_RD_REG16(baseAddr + UART_TXFIFO_LVL);
    }
    else
    {
        /* Return the RX Fifo status */
        status = HW_RD_REG16(baseAddr + UART_RXFIFO_LVL);
    }

    return status;
}

uint32_t UARTIsTxFifoFull(uint32_t baseAddr)
{
    uint32_t status = FALSE;

    if(1U == HW_RD_FIELD16((baseAddr + UART_SSR), UART_SSR_TXFIFOFULL))
    {
        status = TRUE;
    }

    return status;
}

uint32_t UARTIsCharAvail(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint32_t status = FALSE;
    uint16_t regVal = 0U;

    /* Switch to Register Operational Mode of operation. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    /* Checking if the RHR(or RX FIFO) has at least one byte to be read. */
    regVal = HW_RD_FIELD16(baseAddr + UART_LSR, UART_LSR_RXFIFOE);
    if(UART_LSR_RXFIFOE_ATLEAST_ONE_DATA_CHAR == regVal)
    {
        status = TRUE;
    }

    /* Restoring the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return status;
}

uint32_t UARTIsSpaceAvail(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint32_t status = FALSE;
    uint16_t regVal = 0U;

    /* Switch to Register Operational Mode of operation. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    /*
    ** Checking if either TXFIFOE or TXSRE bits of Line Status Register(LSR)
    ** are set. TXFIFOE bit is set if TX FIFO(or THR in non-FIFO mode) is
    ** empty. TXSRE is set if both the TX FIFO(or THR in non-FIFO mode) and
    ** the transmitter shift register are empty.
    */
    regVal = HW_RD_REG16(baseAddr + UART_LSR);
    if(0U != (regVal & (UART_LSR_TXFIFOE_MASK | UART_LSR_TXSRE_MASK)))
    {
        status = TRUE;
    }

    /* Restoring the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return status;
}

int32_t UARTGetChar(uint32_t baseAddr, uint8_t *pRxChar, uint32_t timeout)
{
    uint16_t lcrRegVal = 0U;
    uint32_t status = S_PASS;

    /* Switch to Register Operational Mode of operation. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    if(UART_WAIT_FOREVER == timeout)
    {
        /* Waits indefinitely until a character arrives in the RX FIFO. */
        while(UART_LSR_RXFIFOE_NO_DATA ==
                    HW_RD_FIELD16(baseAddr + UART_LSR, UART_LSR_RXFIFOE));

        *pRxChar = HW_RD_REG8(baseAddr + UART_RHR);
    }
    else if(0U ==timeout)
    {
        /* Check once if a character is available to read */
        if(UART_LSR_RXFIFOE_ATLEAST_ONE_DATA_CHAR ==
                HW_RD_FIELD16(baseAddr + UART_LSR, UART_LSR_RXFIFOE))
        {
            *pRxChar = HW_RD_REG8(baseAddr + UART_RHR);
            status = S_PASS;
        }
        else
        {
            /* Return failure if no data byte available to read */
            status = E_FAIL;
        }
    }
    else
    {
        /*
        ** Wait until the specified timeout value to timeout for a character to
        ** be received through the FIFO.
        */
        while((0U == HW_RD_FIELD16(baseAddr + UART_LSR, UART_LSR_RXFIFOE)) &&
                 (timeout))
        {
            timeout--;
        }

        if(0U != timeout)
        {
            *pRxChar = HW_RD_REG8(baseAddr + UART_RHR);
        }
        else
        {
            status = E_TIMEOUT;
        }
    }

    /* Restoring the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return status;
}

int32_t UARTPutChar(uint32_t baseAddr, uint8_t txChar, uint32_t timeout)
{
    uint16_t lcrRegVal = 0U;
    uint32_t regVal = 0U;
    int32_t status = S_PASS;

    /* Switch to Register Operational Mode of operation. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    regVal = HW_RD_REG16(baseAddr + UART_LSR);

    if(UART_WAIT_FOREVER == timeout)
    {
        /*
        ** Waits indefinitely until the THR and Transmitter Shift Registers are
        ** empty.
        */
        while(0U == (regVal & (UART_LSR_TXFIFOE_MASK | UART_LSR_TXSRE_MASK)))
        {
            regVal = HW_RD_REG16(baseAddr + UART_LSR);
        }
        /* Write the byte into the Register */
        HW_WR_REG8(baseAddr + UART_THR, txChar);
    }
    else if(0U == timeout)
    {
        /*
        ** Check once if there is space in the FIFO for a character to be
        ** written else return an error.
        */
        if(0U != (regVal & (UART_LSR_TXFIFOE_MASK | UART_LSR_TXSRE_MASK)))
        {
            /* Write the byte into the Register */
            HW_WR_REG8(baseAddr + UART_THR, txChar);
        }
        else
        {
            status = E_FAIL;
        }
    }
    else
    {
        /*
        ** Wait until the specified timeout value for a space in the UART FIFO
        ** for a character to write.
        */
        while((0U == (regVal & (UART_LSR_TXFIFOE_MASK | UART_LSR_TXSRE_MASK))
                && (timeout)))
        {
            regVal = HW_RD_REG16(baseAddr + UART_LSR);
            timeout--;
        }
        if(0U != timeout)
        {
            /* Write the byte into the Register */
            HW_WR_REG8(baseAddr + UART_THR, txChar);
        }
        else
        {
            status = E_TIMEOUT;
        }
    }

    /* Restoring the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return status;
}

void UARTFifoWrite(uint32_t baseAddr, uint8_t *pBuf, uint32_t numTxBytes)
{
    uint32_t index = 0U;

    /* Write to the specified bytes to the Tx FIFO */
    for(index = 0U; index < numTxBytes; index++)
    {
        HW_WR_REG8(baseAddr + UART_THR, *pBuf++);
    }
}

uint8_t UARTFifoRead(uint32_t baseAddr)
{
    uint8_t rxByte = 0;

    rxByte = HW_RD_REG8(baseAddr + UART_RHR);

    return rxByte;
}

void UARTDmaEnable(uint32_t baseAddr, uint32_t dmaMode)
{
    uint32_t regVal = 0U;

    regVal = HW_RD_REG16(baseAddr + UART_SCR);

    /* Set the DMA mode control bit */
    HW_SET_FIELD(regVal, UART_SCR_DMAMODECTL, UART_SCR_DMAMODECTL_2_1);
    /* Set the DMA mode */
    HW_SET_FIELD(regVal, UART_SCR_DMAMODE2, dmaMode);
    /* Configure the DMA mode selection */
    HW_WR_REG16(baseAddr + UART_SCR, (uint16_t) regVal);
}

void UARTDmaDisable(uint32_t baseAddr)
{
    /* Disable the DMA mode for UART module */
    HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_DMAMODECTL,
                    UART_SCR_DMAMODECTL_2_1);

    /* Clear the DMA mode type field */
    HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_DMAMODE2,
                        UART_SCR_DMAMODE2_MODE_0);
}

void UARTDmaTxThresholdEnable(uint32_t baseAddr, uint32_t enableTxThreshold)
{
    if (TRUE == enableTxThreshold)
    {
        /* Enable setting the Tx Dma Threshold */
        HW_WR_FIELD32(baseAddr + UART_MDR3, UART_MDR3_SET_DMA_TX_THR,
                        UART_MDR3_SET_DMA_TX_THR_ENABLE);
    }
    else
    {
        /* Disable setting the Tx Dma Threshold */
        HW_WR_FIELD32(baseAddr + UART_MDR3, UART_MDR3_SET_DMA_TX_THR,
                        UART_MDR3_SET_DMA_TX_THR_DISABLE);
    }
}

void UARTSetDmaTxThreshold(uint32_t baseAddr, uint32_t thresholdVal)
{
    /* Set the Tx DMA threshold value */
    HW_WR_FIELD32(baseAddr + UART_TX_DMA_THR, UART_TX_DMA_THR, thresholdVal);
}

void UARTDmaCounterResetEnable(uint32_t baseAddr, uint32_t enableCounterReset)
{
    if (TRUE == enableCounterReset)
    {
        /* enable resetting the DMA counter */
        HW_WR_FIELD16(baseAddr + UART_SSR, UART_SSR_DMACTRRST,
                        UART_SSR_DMACTRRST_RESET);
    }
    else
    {
        /* Disable resetting the DMA counter */
        HW_WR_FIELD16(baseAddr + UART_SSR, UART_SSR_DMACTRRST,
                        UART_SSR_DMACTRRST_NOT_RESET);
    }
}

void UARTAutoRtsEnable(uint32_t baseAddr, uint32_t enableAutoRts)
{
    uint16_t lcrRegVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    if(TRUE == enableAutoRts)
    {
        HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_AUTORTSEN,
                        UART_EFR_AUTORTSEN_ENABLE);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_AUTORTSEN,
                        UART_EFR_AUTORTSEN_DISABLE);
    }

    /* Restore the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

void UARTAutoCtsEnable(uint32_t baseAddr, uint32_t enableAutoCts)
{
    uint16_t lcrRegVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    if(TRUE == enableAutoCts)
    {
        HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_AUTOCTSEN,
                        UART_EFR_AUTOCTSEN_ENABLE);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_AUTOCTSEN,
                        UART_EFR_AUTOCTSEN_DISABLE);
    }

    /* Restore the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

void UARTSetFlowCtrlTriggerLvl(uint32_t baseAddr,
                               uint32_t rxHaltTriggerLvl,
                               uint32_t rxStartTriggerLvl)
{
    uint16_t lcrRegVal = 0U;
    uint16_t enhanFnBitVal = 0U;
    uint16_t tcrTlrBitVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Switch to Register Access mode A to access TCR/TLR registers */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    /* Collect the value of MCR[6] bit . */
    tcrTlrBitVal = HW_RD_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR);

    /* Collect the current value of EFR[4] bit and later set it. */
    enhanFnBitVal = HW_RD_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN,
                UART_EFR_ENHANCEDEN_ENABLE);

    /* set the Rx FIFO trigger level to Halt transmission */
    HW_WR_FIELD16(baseAddr + UART_TCR, UART_TCR_RXFIFOTRIGHALT,
                    (uint16_t) rxHaltTriggerLvl);
    /* set the Rx FIFO trigger level to restore transmission */
    HW_WR_FIELD16(baseAddr + UART_TCR, UART_TCR_RXFIFOTRIGSTART,
                    (uint16_t) rxStartTriggerLvl);

    /* Restore the TCRTLR bit value saved earlier in Reg Access Mode A. */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR, tcrTlrBitVal);

    /* Switch to Register Access Mode B. */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);
    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restoring the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

void UARTSwFlowCtrlConfig(uint32_t baseAddr, uint32_t flowCtrlCfg)
{
    uint16_t lcrRegVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Configure the different Software flow control combinations */
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_SWFLOWCTRL, flowCtrlCfg);

    /* Restore the value of LCR */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

void UARTSetXon1Xoff1Char(uint32_t baseAddr,
                          uint8_t xon1Char,
                          uint8_t xoff1Char)
{
    uint16_t lcrRegVal = 0U;
    uint32_t tcrTlrBitVal = 0U;
    uint32_t enhanFnBitVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collect the current value of EFR[4] bit and later set it. */
    enhanFnBitVal = HW_RD_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN,
                UART_EFR_ENHANCEDEN_ENABLE);

    /* Switch to Register Access mode A to access TCR/TLR registers */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    /* Collecting the bit value of MCR[6] bit . */
    tcrTlrBitVal = HW_RD_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR);

    /*
    ** Clear the TCRTLR bit of MCR register to enable access to XOFF register.
    */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR,
                    UART_MCR_TCRTLR_NO_ACTION);

    /* Program the Xon1 and Xoff1 characters */
    HW_WR_FIELD16(baseAddr + UART_XON1_ADDR1, UART_XON1_ADDR1_XONWORD1,
                    xon1Char);
    HW_WR_FIELD16(baseAddr + UART_XOFF1, UART_XOFF1_XOFFWORD1, xoff1Char);

    /* Restore the TCRTLR bit value saved earlier in Reg Access Mode A. */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR, tcrTlrBitVal);

    /* Switch to Register Access Mode B. */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);
    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restore the value of LCR. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

void UARTSetXon2Xoff2Char(uint32_t baseAddr,
                          uint8_t xon2Char,
                          uint8_t xoff2Char)
{
    uint16_t lcrRegVal = 0U;
    uint32_t tcrTlrBitVal = 0U;
    uint32_t enhanFnBitVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collect the current value of EFR[4] bit and later set it. */
    enhanFnBitVal = HW_RD_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN,
                UART_EFR_ENHANCEDEN_ENABLE);

    /* Switch to Register Access mode A to access TCR/TLR registers */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    /* Collecting the bit value of MCR[6] bit . */
    tcrTlrBitVal = HW_RD_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR);

    /*
    ** Clear the TCRTLR bit of MCR register to enable access to XOFF register.
    */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR,
                    UART_MCR_TCRTLR_NO_ACTION);

    HW_WR_FIELD16(baseAddr + UART_XON2_ADDR2, UART_XON2_ADDR2_XONWORD2,
                    xon2Char);

    HW_WR_FIELD16(baseAddr + UART_XOFF2, UART_XOFF2_XOFFWORD2, xoff2Char);

    /* Restore the TCRTLR bit value saved earlier in Reg Access Mode A. */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR, tcrTlrBitVal);

    /* Switch to Register Access Mode B. */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);
    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restoring LCR with the collected value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

void UARTXonAnyFeatureEnable(uint32_t baseAddr, uint32_t enableXonAnyFeature)
{
    uint16_t lcrRegVal = 0U;
    uint16_t enhanFnBitVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collect the current value of EFR[4] bit and later set it. */
    enhanFnBitVal = HW_RD_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN,
                    UART_EFR_ENHANCEDEN_ENABLE);

    if(TRUE == enableXonAnyFeature)
    {
        HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_XONEN,
                       UART_MCR_XONEN_ENABLE);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_XONEN,
                       UART_MCR_XONEN_DISABLE);
    }

    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restore the LCR register with the original value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

void UARTSpecialCharDetectEnable(uint32_t baseAddr,
                                 uint32_t enableSpecCharDtct)
{
    uint16_t lcrRegVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    if(TRUE == enableSpecCharDtct)
    {
        HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_SPECIALCHARDETECT,
                        UART_EFR_SPECIALCHARDETECT_ENABLE);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_SPECIALCHARDETECT,
                        UART_EFR_SPECIALCHARDETECT_DISABLE);
    }

    /* Restore the LCR register with the original value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

void UARTPulseShapingEnable(uint32_t baseAddr, uint32_t enablePulseShaping)
{
    if(TRUE == enablePulseShaping)
    {
        HW_WR_FIELD16(baseAddr + UART_MDR2, UART_MDR2_UARTPULSE,
                        UART_MDR2_UARTPULSE_PULSE_SHAPING_MODE);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_MDR2, UART_MDR2_UARTPULSE,
                        UART_MDR2_UARTPULSE_NORMAL_MODE);
    }
}

void UARTResumeOper(uint32_t baseAddr)
{
    /* Dummy Read to restart the UART Transmission and Reception */
    HW_RD_REG8(baseAddr + UART_RESUME);
}

void UARTModemCtrlEnable(uint32_t baseAddr,
                         uint32_t modemPin,
                         uint32_t enableCtrlPin)
{
    switch (modemPin)
    {
        case UART_MODEM_CTRL_PIN_DTR:
        {
            if(TRUE == enableCtrlPin)
            {
                HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_RTS,
                                UART_MCR_RTS_ACTIVE);
            }
            else
            {
                HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_RTS,
                                UART_MCR_RTS_INACTIVE);
            }
            break;
        }
        case UART_MODEM_CTRL_PIN_RTS:
        {
            if(TRUE == enableCtrlPin)
            {
                HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_RTS,
                                UART_MCR_RTS_ACTIVE);
            }
            else
            {
                HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_RTS,
                                UART_MCR_RTS_INACTIVE);
            }
            break;
        }
        case UART_MODEM_CTRL_PIN_RI:
        {
            if(TRUE == enableCtrlPin)
            {
                HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_RTS,
                                UART_MCR_RTS_ACTIVE);
            }
            else
            {
                HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_RTS,
                                UART_MCR_RTS_INACTIVE);
            }
            break;
        }
        case UART_MODEM_CTRL_PIN_DCD:
        {
            if(TRUE == enableCtrlPin)
            {
                HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_CDSTSCH,
                                UART_MCR_CDSTSCH_INPUT_LOW);
            }
            else
            {
                HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_CDSTSCH,
                                UART_MCR_CDSTSCH_INPUT_HIGH);
            }
            break;
        }

        default:
        break;
    }
}

uint16_t UARTModemStatus(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint16_t enhanFnBitVal = 0U;
    uint16_t status = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collect the current value of EFR[4] bit and later Clear it. */
    enhanFnBitVal = HW_RD_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN,
                    UART_EFR_ENHANCEDEN_DISABLE);

   /* Switch to Register Operational Mode. */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    status = HW_RD_REG16(baseAddr + UART_MSR);

    /* Switch back to Register Access Mode B. */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);
    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restore the LCR register with the original value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return status;
}

void UARTDsrPinIntrEnable(uint32_t baseAddr, uint32_t enableDsrIntr)
{
    if(TRUE == enableDsrIntr)
    {
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_DSRIT,
                        UART_SCR_DSRIT_ENABLE);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_SCR, UART_SCR_DSRIT,
                        UART_SCR_DSRIT_DISABLE);
    }
}

uint32_t UARTRxCtsDsrTransitionStatus(uint32_t baseAddr)
{
    uint32_t status = FALSE;
    uint16_t regVal = 0U;

    /* Read the CTS, DSR pin status */
    regVal = HW_RD_FIELD16(baseAddr + UART_SSR, UART_SSR_RXCTSDSRWAKEUPSTS);

    if(UART_SSR_RXCTSDSRWAKEUPSTS_FALLING_EDGE_EVT == regVal)
    {
        status = TRUE;
    }

    return status;
}

void UARTEnableAutobaudMode(uint32_t baseAddr, uint32_t enableAutobaud)
{
    if(TRUE == enableAutobaud)
    {
        HW_WR_FIELD16(baseAddr + UART_MDR1, UART_MDR1_MODESELECT,
                UART_MDR1_MODESELECT_MODE_16X_AUTO_BAUD);
    }
    else
    {
        HW_WR_FIELD16(baseAddr + UART_MDR1, UART_MDR1_MODESELECT,
                        UART_MDR1_MODESELECT_MODE_16X);
    }
}

uint16_t UARTGetAutoBaudParity(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint16_t parity = 0U;

    /* Switch to Register Access mode A. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    parity = HW_RD_FIELD16(baseAddr + UART_UASR, UART_UASR_PARITYTYPE);

    /* Restoring LCR with the collected value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return parity;
}

uint16_t UARTGetAutoBaudWordLen(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint16_t wordLen = 0U;

    /* Switch to Register Access mode A. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    wordLen = HW_RD_FIELD16(baseAddr + UART_UASR, UART_UASR_BITBYCHAR);

    /* Restoring LCR with the collected value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return wordLen;
}

uint16_t UARTGetAutoBaudSpeed(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint16_t speed = 0U;

    /* Switch to Register Access mode A. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    speed = HW_RD_FIELD16(baseAddr + UART_UASR, UART_UASR_SPEED);

    /* Restore LCR with the collected value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return speed;
}

void UARTSetScratchPadValue(uint32_t baseAddr, uint16_t scratchValue)
{
    uint16_t lcrRegVal = 0U;
    uint16_t enhanFnBitVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collect the current value of EFR[4] bit and later Clear it. */
    enhanFnBitVal = HW_RD_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN,
                    UART_EFR_ENHANCEDEN_DISABLE);

    /* Switch to Register Operational Mode. */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    /* Write the Scratch pad value. */
    HW_WR_FIELD16(baseAddr + UART_SPR, UART_SPR_WORD, scratchValue);

    /* Switch back to Register Access Mode B. */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restore LCR with the collected value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

uint16_t UARTGetScratchPadValue(uint32_t baseAddr)
{
    uint16_t lcrRegVal = 0U;
    uint16_t enhanFnBitVal = 0U;
    uint16_t scratchPadValue = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collect the current value of EFR[4] bit and later Clear it. */
    enhanFnBitVal = HW_RD_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN,
                    UART_EFR_ENHANCEDEN_DISABLE);

    /* Switch to Register Operational Mode. */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_OPER);

    /* Read the Scratch pad value. */
    scratchPadValue = HW_RD_FIELD16(baseAddr + UART_SPR, UART_SPR_WORD);

    /* Switch back to Register Access Mode B. */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16(baseAddr + UART_EFR, UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restore LCR with the collected value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return scratchPadValue;
}

/* -------------------------------------------------------------------------- */
/*                 Deprecated Function Definitions                            */
/* -------------------------------------------------------------------------- */

uint32_t UARTSubConfigMSRSPRModeEn(uint32_t baseAddr)
{
    uint32_t enhanFnBitVal = 0U;
    uint32_t tcrTlrVal = 0U;
    uint16_t lcrRegVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collecting the current value of EFR[4] and later setting it. */
    enhanFnBitVal = HW_RD_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN,
                    UART_EFR_ENHANCEDEN_ENABLE);

    /* Switch to Configuration Mode A of operation. */
    UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    /* Collecting the bit value of MCR[6]. */
    tcrTlrVal = HW_RD_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR);

    /* Clear the TCRTLR bit */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR,
                    UART_MCR_TCRTLR_NO_ACTION);

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restoring LCR with the collected value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return tcrTlrVal;
}

uint32_t UARTSubConfigTCRTLRModeEn(uint32_t baseAddr)
{
    uint32_t enhanFnBitVal = 0U;
    uint32_t tcrTlrVal = 0U;
    uint16_t lcrRegVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collecting the current value of EFR[4] and later setting it. */
    enhanFnBitVal = HW_RD_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN,
                    UART_EFR_ENHANCEDEN_ENABLE);

    /* Switch to Register Access mode A. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    /* Collecting the bit value of MCR[6]. */
    tcrTlrVal = HW_RD_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR);

    /* Set the TCRTLR bit */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR, UART_MCR_TCRTLR_ENABLE);

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restoring LCR with the collected value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return tcrTlrVal;
}

uint32_t UARTSubConfigXOFFModeEn(uint32_t baseAddr)
{
    uint32_t enhanFnBitVal = 0U;
    uint32_t tcrTlrVal = 0U;
    uint16_t lcrRegVal = 0U;

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collecting the current value of EFR[4] and later setting it. */
    enhanFnBitVal = HW_RD_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN,
                    UART_EFR_ENHANCEDEN_ENABLE);

    /* Switch to Register Access mode A. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    /* Collecting the bit value of TCRTLR(MCR[6]). */
    tcrTlrVal = HW_RD_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR);

    /* Clearing the TCRTLR bit in MCR register. */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR,
                    UART_MCR_TCRTLR_NO_ACTION);

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restoring LCR with the collected value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);

    return tcrTlrVal;
}

void UARTTCRTLRBitValRestore(uint32_t baseAddr, uint32_t tcrTlrBitVal)
{
    uint32_t enhanFnBitVal = 0U;
    uint16_t lcrRegVal = 0U;

    /* Switch to Register Access Mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Collecting the current value of EFR[4] and later setting it. */
    enhanFnBitVal = HW_RD_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN);
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN,
                    UART_EFR_ENHANCEDEN_ENABLE);

    /* Switch to Register Access mode A. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_A);

    /* Programming MCR[6] with the corresponding bit value in 'tcrTlrBitVal'. */
    HW_WR_FIELD16(baseAddr + UART_MCR, UART_MCR_TCRTLR, tcrTlrBitVal);

    /* Switch to Register Access mode B. */
    lcrRegVal = UARTSetRegAccessMode(baseAddr, UART_REG_ACCESS_MODE_B);

    /* Restore the value of EFR[4] to its original value */
    HW_WR_FIELD16((baseAddr + UART_EFR), UART_EFR_ENHANCEDEN, enhanFnBitVal);

    /* Restoring LCR with the collected value. */
    HW_WR_REG16(baseAddr + UART_LCR, lcrRegVal);
}

uint32_t UARTParityModeGet(uint32_t baseAddr)
{
    uint32_t parityType = 0U;

    parityType = HW_RD_REG16(baseAddr + UART_LCR);

    parityType = (parityType & (UART_LCR_PARITY_EN_MASK |
                               UART_LCR_PARITY_TYPE1_MASK |
                               UART_LCR_PARITY_TYPE2_MASK));

    return parityType;
}
