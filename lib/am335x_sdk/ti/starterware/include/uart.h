/**
 * \file   uart.h
 *
 * \brief  This file contains the prototypes of device abstraction layer APIs
 *         corresponding to the UART module. This also contains necessary
 *         structure, enum and macro definitions and the APIs are consolidated
 *         to make them more functional.
 *
 *  \details Programming sequence of UART is as follows:
 *           -# Enable Module Clocks for UART through PRCMModuleEnable API
 *           -# Configure the Pinmux for the UART instance required through
 *              PINMUXModuleConfig API
 *           -# Perform a module reset of the UART instance through the API
 *              #UARTModuleReset
 *           -# Configure the Fifo settings required through the following API
 *              #UARTFifoConfig
 *           -# Set the Baud rate required for the UART to function using the
 *              API #UARTSetBaudRate
 *           -# Configure the Line Characteristics like the Word Length, Parity,
 *              Stop Bits through the API #UARTLineCharacteristicConfig
 *           -# Disable the Break Control functionality through the following
 *              API #UARTBreakCtrlEnable
 *           -# Configure the UART Interrupts like Receive and Transmit through
 *              the following APIs #UARTIntrEnable and #UARTIntrDisable
 *           -# Configure the UART DMA feature through the following API
 *              #UARTDmaEnable and #UARTDmaDisable
 *           -# To read and write a character from the FIFO use the following
 *              APIs #UARTGetChar #UARTPutChar
 *           -# UART wakeup Events can be configured using the following APIs
 *              #UARTWakeupEventEnable and #UARTWakeupEventDisable
 *           -# FlowControl can be enabled through Hardware or Software methods
 *              -# Hardware Flow control can be controlled through the following
 *                 APIs #UARTAutoRtsEnable #UARTAutoCtsEnable to control
 *                 Auto-RTS and Auto-CTS feature respectively
 *              -# Software Flow control combinations can be configured through
 *                 the following APIs #UARTSwFlowCtrlConfig
 *              -# The XON and XOFF characters for software flow control are
 *                 configured using the following APIs #UARTSetXon1Xoff1Char
 *                 #UARTSetXon2Xoff2Char
 *              -# The trigger levels for the selected Flow control method can
 *                 be configured through #UARTSetFlowCtrlTriggerLvl API
 *           -# AutoBaud
 *              -# The AutoBaud feature can be enabled using the following
 *                 API #UARTEnableAutobaudMode
 *              -# The other AutoBaud Characteristics can be read using the
 *                 following APIs #UARTGetAutoBaudParity #UARTGetAutoBaudWordLen
 *                 #UARTGetAutoBaudSpeed
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

#ifndef UART_H_
#define UART_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "misc.h"
#include "hw_uart.h"

#ifdef __cplusplus
extern "C" {
#endif
/* ========================================================================== */
/*              API compatibility with Starterware 2.0                        */
/* ========================================================================== */
#define UARTModuleVersionNumberGet      UARTGetRevision
#define UARTDMADisable                  UARTDmaDisable
#define UARTTxDMAThresholdValConfig     UARTSetDmaTxThreshold
#define UARTXON1XOFF1ValProgram         UARTSetXon1Xoff1Char
#define UARTXON2XOFF2ValProgram         UARTSetXon2Xoff2Char
#define UARTResumeOperation             UARTResumeOper
#define UARTAutobaudParityGet           UARTGetAutoBaudParity
#define UARTAutobaudWordLenGet          UARTGetAutoBaudWordLen
#define UARTAutobaudSpeedGet            UARTGetAutoBaudSpeed
#define UARTScratchPadRegWrite          UARTSetScratchPadValue
#define UARTScratchPadRegRead           UARTGetScratchPadValue
/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/**
 *  \name UART FIFO Trigger levels minimum and maximum values.
 */
/** @{ */
/** \brief Macro representing Minimum FIFO Trigger level. */
#define UART_FIFO_TRIGGER_LVL_MIN        (1U)

/** \brief Macro representing Maximum FIFO Trigger level. */
#define UART_FIFO_TRIGGER_LVL_MAX        (63U)
/** @} */

/** \brief Macro to indicate the blocking feature for UART Get and Put APIs. */
#define UART_WAIT_FOREVER               (0xFFFFFFFFU)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the UART register access modes. */
typedef enum uartRegAccessMode
{
    UART_REG_ACCESS_MODE_MIN = 0U,
    /**< Minimum Register Access Mode. */
    UART_REG_ACCESS_MODE_A = UART_REG_ACCESS_MODE_MIN,
    /**< Value to Enable Register Access Mode A */
    UART_REG_ACCESS_MODE_B,
    /**< Value to Enable Register Access Mode B */
    UART_REG_ACCESS_MODE_OPER,
    /**< Value to Enable Register Operational Access mode */
    UART_REG_ACCESS_MODE_MAX = UART_REG_ACCESS_MODE_OPER
    /**< Maximum Register Access Mode. */
}uartRegAccessMode_t;

/** \brief Enumerates the different UART interrupts. */
typedef enum uartIntrMask
{
    UART_INTR_RX_THRESHOLD = UART_IER_RHRIT_MASK,
    /**< Interrupt mask to enable Rx Fifo threshold interrupt. */
    UART_INTR_TX_THRESHOLD = UART_IER_THRIT_MASK,
    /**< Interrupt mask to enable Tx Fifo threshold interrupt */
    UART_INTR_TIME_OUT = UART_IER_RHRIT_MASK,
    /**< Receive Time out indicating stale data in RX FIFO. */
    UART_INTR_LINE_STATUS = UART_IER_LINESTSIT_MASK,
    /**< Receiver Line Status Interrupt */
    UART_INTR_MODEM_STATUS = UART_IER_MODEMSTSIT_MASK,
    /**< Modem Status Register Interrupt */
    UART_INTR_SLEEP_MODE = UART_IER_SLEEPMODE_MASK,
    /**< Sleep Mode Interrupt */
    UART_INTR_XOFF = UART_IER_XOFFIT_MASK,
    /**< XOFF Character Interrupt */
    UART_INTR_RTS = UART_IER_RTSIT_MASK,
    /**< Request to Send Interrupt */
    UART_INTR_CTS = UART_IER_CTSIT_MASK,
    /**< Clear to Send Interrupt */
}uartIntrMask_t;

/** \brief Enumerates the UART interrupt Status values. */
typedef enum uartIntrStatus
{
    UART_INTR_STATUS_TX_THRESHOLD = UART_IIR_IT_TYPE_THR,
    /** Value to indicate TX FIFO threshold interrupt status. */
    UART_INTR_STATUS_RX_THRESHOLD = UART_IIR_IT_TYPE_RHR,
    /** Value to indicate RX FIFO threshold interrupt status. */
    UART_INTR_STATUS_TIMEOUT = UART_IIR_IT_TYPE_RX_TIMEOUT,
    /**< Value to indicate Receive Timeout Error Interrupt. */
    UART_INTR_STATUS_RX_LINE = UART_IIR_IT_TYPE_LINE_STS_ERR,
    /**< Value to indicate Line status Error Interrupt. */
    UART_INTR_STATUS_XOFF_CHAR = UART_IIR_IT_TYPE_XOFF,
    /**< Value to indicate Receive XOFF Character interrupt. */
    UART_INTR_STATUS_MODEM = UART_IIR_IT_TYPE_MODEM,
    /**< Value to indicate Modem Status Change interrupt. */
    UART_INTR_STATUS_MODEM_PINS = UART_IIR_IT_TYPE_CTS_RTS_DSR
    /**< Value to indicate Change inModem Control Pins RTS
         CTS, DSR pins change state from active to inactive state. */
}uartIntrStatus_t;

/** \brief Enumerates the different DMA modes supported by UART. */
typedef enum uartDmaMode
{
    UART_DMA_MODE_MODE0 = UART_SCR_DMAMODE2_MODE_0,
    /**< UART DMA mode-0 indicates the DMA feature is disabled. */
    UART_DMA_MODE_MODE1 = UART_SCR_DMAMODE2_MODE_1,
    /**< UART DMA mode-1 indicates the DMA mode is enabled
         In this mode UARTnDMAREQ[0] is reserved for Tx and
         UARTnDMAREQ[1] for Rx. */
    UART_DMA_MODE_MODE2 = UART_SCR_DMAMODE2_MODE_2,
    /**< UART DMA mode-2 is enabled. In this mode UARTnDMAREQ[0]
         is reserved for Rx. This is a Legacy mode in which only
         Rx DMA request is used */
    UART_DMA_MODE_MODE3 = UART_SCR_DMAMODE2_MODE_3,
    /**< UART DMA mode-3 is enabled. In this mode UARTnDMAREQ[0]
         is reserved for Tx. This is a Legacy mode in which only
         Tx DMA request is used */
}uartDmaMode_t;

/** \brief Enumerates the type of supported UART idle modes. */
typedef enum uartIdleMode
{
    UART_IDLE_MODE_FORCE_IDLE   = UART_SYSC_IDLEMODE_FORCE_IDLE,
    /**< Force Idle mode. */
    UART_IDLE_MODE_NO_IDLE      = UART_SYSC_IDLEMODE_NO_IDLE,
    /**< No idle mode. */
    UART_IDLE_MODE_SMART_IDLE  = UART_SYSC_IDLEMODE_SMART_IDLE,
    /**< Smart idle mode. */
    UART_IDLE_MODE_SMART_IDLE_WKUP = UART_SYSC_IDLEMODE_SMART_IDLE_WKUP
    /**< Smart idle wakeup. */
}uartIdleMode_t;

/** \brief Enumerates the different baud Rates supported by UART. */
typedef enum uartBaudRate
{
    UART_BAUD_RATE_MIN = 1200U,
    /**< Minimum Baud Rate supported by UART used for input validation */
    UART_BAUD_RATE_1200 = UART_BAUD_RATE_MIN,
    /**< Baud rate of 1200bps */
    UART_BAUD_RATE_2400 = 2400U,
    /**< Baud rate of 2400bps */
    UART_BAUD_RATE_4800 = 4800U,
    /**< Baud rate of 4800bps */
    UART_BAUD_RATE_9600 = 9600U,
    /**< Baud rate of 9600bps */
    UART_BAUD_RATE_14400 = 14400U,
    /**< Baud rate of 14400bps */
    UART_BAUD_RATE_19200 = 19200U,
    /**< Baud rate of 19200bps */
    UART_BAUD_RATE_28800 = 28800U,
    /**< Baud rate of 28800bps */
    UART_BAUD_RATE_38400 = 38400U,
    /**< Baud rate of 38400bps */
    UART_BAUD_RATE_57600 = 57600U,
    /**< Baud rate of 57600bps */
    UART_BAUD_RATE_115200 = 115200U,
    /**< Baud rate of 115200bps */
    UART_BAUD_RATE_230400 = 230400U,
    /**< Baud rate of 230400bps */
    UART_BAUD_RATE_460800 = 460800U,
    /**< Baud rate of 460800bps */
    UART_BAUD_RATE_921600 = 921600U,
    /**< Baud rate of 921600bps */
    UART_BAUD_RATE_1843000 = 1843000U,
    /**< Baud rate of 1.8Mbps */
    UART_BAUD_RATE_3000000 = 3000000U,
    /**< Baud rate of 3.0Mbps */
    UART_BAUD_RATE_3688400 = 3688400U,
    /**< Baud rate of 3.68Mbps*/
    UART_BAUD_RATE_MAX = UART_BAUD_RATE_3688400
    /**< Maximum Baud rate supported by UART */
}uartBaudRate_t;

/** \brief Enumerates different Character length per frame supported by UART */
typedef enum uartCharLength
{
    UART_CHAR_LENGTH_5BIT = UART_LCR_CHAR_LENGTH_BITS_5,
    /**< UART 5-bit Char length */
    UART_CHAR_LENGTH_6BIT = UART_LCR_CHAR_LENGTH_BITS_6,
    /**< UART 6-bit Char length */
    UART_CHAR_LENGTH_7BIT = UART_LCR_CHAR_LENGTH_BITS_7,
    /**< UART 7-bit Char length */
    UART_CHAR_LENGTH_8BIT = UART_LCR_CHAR_LENGTH_BITS_8
    /**< UART 8-bit Char length */
}uartCharLength_t;

/** \brief Enumerates different Stop Bits per frame supported by UART */
typedef enum uartStopBit
{
    UART_STOP_BIT_MIN = 0U,
    /**< UART Minimum Stop-bit value used for validation */
    UART_STOP_BIT_1 = UART_LCR_NB_STOP_BITS_1,
    /**< UART 1 Stop bits per frame length */
    UART_STOP_BIT_1_5 = UART_LCR_NB_STOP_BITS_1_5,
    /**< UART 1.5 Stop bits per frame length */
    UART_STOP_BIT_2 = UART_LCR_NB_STOP_BITS_1_5,
    /**< UART 2 Stop bits per frame length */
    UART_STOP_BIT_MAX = UART_STOP_BIT_2
    /**< UART Maximum Stop-bit value used for validation */
}uartStopBit_t;

/** \brief Enumerates the types of Parity feature per frame supported by UART */
typedef enum uartParity
{
    UART_PARITY_MIN = 0U,
    /**< UART Minimum Parity value used for validation */
    UART_PARITY_NONE = UART_PARITY_MIN,
    /**< UART No Parity bit in a frame */
    UART_PARITY_ODD,
    /**< UART Odd parity is enabled for a frame */
    UART_PARITY_EVEN,
    /**< UART Even parity is enabled for a frame */
    UART_PARITY_MARK,
    /**< UART Mark parity is enabled for a frame */
    UART_PARITY_SPACE,
    /**< UART Space parity is enabled for a frame */
    UART_PARITY_MAX = UART_PARITY_SPACE
    /**< UART Maximum Parity value used for validation of input */
}uartParity_t;

/** \brief Enumerates the different wakeup sources which generate a wakeup
           event. */
typedef enum uartWakeupEvent
{
    UART_WAKEUP_EVT_CTS_ACTIVITY = UART_WER_CTS_ACTIVITY_CAN_WKUP,
    /**< Wakeup on CTS(Clear to Send) pin activity */
    UART_WAKEUP_EVT_DSR_ACTIVITY = UART_WER_DSR_ACTIVITY_CAN_WKUP,
    /**< Wakeup on DSR(Data Set Ready) pin activity */
    UART_WAKEUP_EVT_RI_ACTIVITY = UART_WER_RI_ACTIVITY_CAN_WKUP,
    /**< Wakeup on RI(Ring Indicator) pin activity */
    UART_WAKEUP_EVT_DCD_ACTIVITY = UART_WER_DCD_ACTIVITY_CAN_WKUP,
    /**< Wakeup on DCD(Data Carrier Detect) pin activity */
    UART_WAKEUP_EVT_RX_ACTIVITY = UART_WER_RX_ACTIVITY_CAN_WKUP,
    /**< Wakeup on RX(Receive Line) pin activity */
    UART_WAKEUP_EVT_RHR_ACTIVITY = UART_WER_RHR_INTR_CAN_WKUP,
    /**< Wakeup on RHR interrupt(RX FIFO threshold reached) */
    UART_WAKEUP_EVT_RLS_ACTIVITY = UART_WER_RLS_INTR_CAN_WKUP,
    /**< Wakeup on RLS(Receive Line Status) interrupt */
    UART_WAKEUP_EVT_TX_INTR = UART_WER_TXWAKEUPEN_CAN_WKUP,
    /**< Enabling the THR, TXDMA and TXSTATUS interrupts to wakeup the system */
    UART_WAKEUP_EVT_ALL     = 0xFFU
    /**< Mask for all the UART Wakeup sources. Used to check the status
         of all the wakeup events. */
}uartWakeupEvent_t;

/** \brief Enumerates the Line Status register values indicating the
           Status of the UART RX/TX transfer. */
typedef enum uartLineStsMask
{
    UART_LINE_STS_MASK_ONE_CHAR_IN_RX_FIFO = UART_LSR_RXFIFOE_MASK,
    /**< Mask value to indicate at least one character in RX FIFO. */
    UART_LINE_STS_MASK_OVERRUN_ERROR = UART_LSR_RXOE_MASK,
    /**< Mask Value indicating Overrun Error */
    UART_LINE_STS_MASK_PARITY_ERROR = UART_LSR_RXPE_MASK,
    /**< Mask Value indicating Parity Error in data read from RX FIFO */
    UART_LINE_STS_MASK_FRAME_ERROR = UART_LSR_RXFE_MASK,
    /**< Mask Value indicating Framing Error in data read from RX FIFO */
    UART_LINE_STS_MASK_BRK_CONDITION_DETECT = UART_LSR_RXBI_MASK,
    /**< Mask Value indicating Break Condition detection on data read from RX
         FIFO */
    UART_LINE_STS_MASK_TX_THR_EMPTY = UART_LSR_TXFIFOE_MASK,
    /**< Mask Value indicating Transmit Holding register is empty */
    UART_LINE_STS_MASK_TX_THR_SHIFT_REG_EMPTY = UART_LSR_TXSRE_MASK,
    /**< Mask Value indicating Transmit and shift registers are empty */
    UART_LINE_STS_MASK_RX_FIFO_ERR_STATUS = UART_LSR_RXFIFOSTS_MASK
    /**< Mask Value indicating at least one Parity Error, Framing Error or
         Break Condition in the RX FIFO. */
}uartLineStsMask_t;

/** \brief Enumerates the different fifo types supported by the module */
typedef enum uartFifo
{
    UART_FIFO_TX  = 0U,
    /**< Flag to indicate Transmit FIFO of UART module. */
    UART_FIFO_RX,
    /**< Flag to indicate Receive FIFO of UART module. */
}uartFifo_t;

/**  \brief Enumerates the different Trigger Level Granularities of the FIFO. */
typedef enum uartTriggerLvlGran
{
    UART_TRIGGER_LVL_GRAN_MIN = 0U,
    /**< Minimum Trigger level granularity */
    UART_TRIGGER_LVL_GRAN_1 = UART_TRIGGER_LVL_GRAN_MIN,
    /**< Trigger Level granularity 1 */
    UART_TRIGGER_LVL_GRAN_4,
    /**< Trigger Level granularity 4 */
    UART_TRIGGER_LVL_GRAN_MAX = UART_TRIGGER_LVL_GRAN_4
    /**< Maximum Trigger level granularity */
}uartTriggerLvlGran_t;

/** TODO: These values need to be updated with the Auto generated Macros. */
/**  \brief Enumerates the different Software Flow control combinations. */
typedef enum uartSwFlowCtrlCfg
{
    UART_SW_FLOW_CTRL_CFG_NO_TX_FLOW_CTRL = 0x03U,
    /**< No Transmit flow control. */
    UART_SW_FLOW_CTRL_CFG_TX_XON1_XOFF1 = 0x08U,
    /**< Transmit XON1 and XOFF1 */
    UART_SW_FLOW_CTRL_CFG_TX_XON2_XOFF2 = 0x04U,
    /**< Transmit XON2 and XOFF2 characters */
    UART_SW_FLOW_CTRL_CFG_TX_XON1_XOFF1_XON2_XOFF2 = 0x0CU,
    /**< Transmit both XON1, XOFF1 and XON2, XOFF2 characters */
    UART_SW_FLOW_CTRL_CFG_NO_RX_FLOW_CTRL = 0x00U,
    /**< No Receive flow control. */
    UART_SW_FLOW_CTRL_CFG_RX_XON1_XOFF1 = 0x02U,
    /**< Receiver Compares XON1 and XOFF1 characters */
    UART_SW_FLOW_CTRL_CFG_RX_XON2_XOFF2 = 0x01U,
    /**< Receiver Compares XON2 and XOFF2 characters */
    UART_SW_FLOW_CTRL_CFG_RX_XON1_XOFF1_XON2_XOFF2 = 0x03U,
    /**< Receiver Compares both XON1,XOFF1 and XON2, XOFF2 characters */
}uartSwFlowCtrlCfg_t;

/** \brief Enumerates the different Modem Control Pins */
typedef enum uartModemCtrlPin
{
    UART_MODEM_CTRL_PIN_MIN = 0U,
    /**< Minimum value of Modem Control pin */
    UART_MODEM_CTRL_PIN_DTR = UART_MODEM_CTRL_PIN_MIN,
    /**< Value to denote the DTR(Data Terminal Ready) pin */
    UART_MODEM_CTRL_PIN_RTS,
    /**< Value to denote the RTS(Request to Send) pin */
    UART_MODEM_CTRL_PIN_RI,
    /**< Value to denote the RI(Ring Indicator) pin */
    UART_MODEM_CTRL_PIN_DCD,
    /**< Value to denote the DCD(Data Carrier Detect) pin */
    UART_MODEM_CTRL_PIN_MAX = UART_MODEM_CTRL_PIN_DCD,
    /**< Minimum value of Modem Control pin */
}uartModemCtrlPin_t;

/** \brief Enumerates the status of different Modem Control Pins */
typedef enum uartModemSts
{
    UART_MODEM_STS_CTS_PIN = UART_MSR_CTS_STS_MASK,
    /**< Mask value to denote change in CTS(Clear to Send) pin Status. */
    UART_MODEM_STS_DSR_PIN = UART_MSR_DSR_STS_MASK,
    /**< Mask Value to denote change in DSR(Data Set Ready) pin Status. */
    UART_MODEM_STS_RI_PIN = UART_MSR_RI_STS_MASK,
    /**< Mask Value to denote change in RI(Ring Indicator) pin status. */
    UART_MODEM_STS_DCD_PIN = UART_MSR_DCD_STS_MASK,
    /**< Mask Value to denote change in DCD(Data Carrier Detect) pin Status. */
    UART_MODEM_STS_CTS_PIN_COMPLMNT = UART_MSR_NCTS_STS_MASK,
    /**< Mask Value which indicates the complement of the CTS pin status. */
    UART_MODEM_STS_DSR_PIN_COMPLMNT = UART_MSR_NDSR_STS_MASK,
    /**< Mask Value which indicates the complement of the DSR pin status. */
    UART_MODEM_STS_RI_PIN_COMPLMNT = UART_MSR_NRI_STS_MASK,
    /**< Mask Value which indicates the complement of the RI pin status. */
    UART_MODEM_STS_DCD_PIN_COMPLMNT = UART_MSR_NCD_STS_MASK,
    /**< Mask Value which indicates the complement of the DCD pin status. */
}uartModemSts_t;

/**\brief Enumerates the different baud rates supported by UART in AutoBaud
          mode */
typedef enum uartAutoBaudSpeed
{
    UART_AUTO_BAUD_SPEED_NONE = UART_UASR_SPEED_NONE_IDENTIFIED,
    /**< No Speed identified in Auto Baud mode */
    UART_AUTO_BAUD_SPEED_1200 = UART_UASR_SPEED_BAUD_1200,
    /**< Baud rate of 1200bps in AutoBaud mode */
    UART_AUTO_BAUD_SPEED_2400 = UART_UASR_SPEED_BAUD_2400,
    /**< Baud rate of 2400bps in AutoBaud mode */
    UART_AUTO_BAUD_SPEED_4800 = UART_UASR_SPEED_BAUD_4800,
    /**< Baud rate of 4800bps in AutoBaud mode */
    UART_AUTO_BAUD_SPEED_9600 = UART_UASR_SPEED_BAUD_9600,
    /**< Baud rate of 9600bps in AutoBaud mode */
    UART_AUTO_BAUD_SPEED_14400 = UART_UASR_SPEED_BAUD_14400,
    /**< Baud rate of 14400bps in AutoBaud mode */
    UART_AUTO_BAUD_SPEED_19200 = UART_UASR_SPEED_BAUD_19200,
    /**< Baud rate of 19200bps in AutoBaud mode */
    UART_AUTO_BAUD_SPEED_28800 = UART_UASR_SPEED_BAUD_28800,
    /**< Baud rate of 28800bps in AutoBaud mode */
    UART_AUTO_BAUD_SPEED_38400 = UART_UASR_SPEED_BAUD_38400,
    /**< Baud rate of 38400bps in AutoBaud mode */
    UART_AUTO_BAUD_SPEED_57600 = UART_UASR_SPEED_BAUD_57600,
    /**< Baud rate of 57600bps in AutoBaud mode */
    UART_AUTO_BAUD_SPEED_115200 = UART_UASR_SPEED_BAUD_115200
    /**< Baud rate of 115200bps in AutoBaud mode */
}uartAutoBaudSpeed_t;

/**\brief Enumerates the different word lengths supported by UART in AutoBaud
          mode */
typedef enum uartAutoBaudWordLen
{
    UART_AUTO_BAUD_WORD_LEN_7 = UART_UASR_BITBYCHAR_BIT_7,
    /**< Indicates the word Length of 7-bit in AutoBaud mode */
    UART_AUTO_BAUD_WORD_LEN_8 = UART_UASR_BITBYCHAR_BIT_8
    /**< Indicates the word Length of 8-bit in AutoBaud mode */
}uartAutoBaudWordLen_t;

/**\brief Enumerates the parity bit detected in Auto-Baud mode */
typedef enum uartAutoBaudParity
{
    UART_AUTO_BAUD_PARITY_NONE = UART_UASR_PARITYTYPE_NONE,
    /**< Indicates No Parity in AutoBaud mode */
    UART_AUTO_BAUD_PARITY_SPACE = UART_UASR_PARITYTYPE_SPACE,
    /**< Indicates Space Parity in AutoBaud mode */
    UART_AUTO_BAUD_PARITY_EVEN = UART_UASR_PARITYTYPE_EVEN,
    /**< Indicates Even Parity in AutoBaud mode */
    UART_AUTO_BAUD_PARITY_ODD = UART_UASR_PARITYTYPE_ODD,
    /**< Indicates Odd parity in AutoBaud mode */
}uartAutoBaudParity_t;

/** \brief Enumerates the UART DMA events. */
typedef enum uartDmaEvt
{
    UART_DMA_EVT_TX = 0U,
    /**< RX DMA events. */
    UART_DMA_EVT_RX,
    /**< RX DMA events. */
    UART_DMA_EVT_MAX
    /**< Maximum DMA events. */
}uartDmaEvt_t;

/** \brief    Structure which formulates the parameters of uartFifoCfg API.
              These parameters represent the overall parameters required to
              configure the FIFO for different settings. */
typedef struct uartFifoCfg
{
    uartTriggerLvlGran_t uartTxGran;
    /**< The value to denote the Tx Trigger Level Granularity.
         The granularity can be any of the two values from
         the following enum #uartTriggerLvlGran_t */
    uartTriggerLvlGran_t uartRxGran;
    /**< The value to denote the Rx Trigger Level Granularity.
         The granularity can be any of the two values from
         the following enum #uartTriggerLvlGran_t */
    uint32_t  uartTxTriggerLvl;
    /**< Value to represent the Transmit Trigger Level setting used to
         configure Transmit FIFO threshold in bytes. The trigger level can be
         any of the possible values from #UART_FIFO_TRIGGER_LVL_MIN to
         #UART_FIFO_TRIGGER_LVL_MAX */
    uint32_t uartRxTriggerLvl;
    /**< Value to represent the Receive Trigger Level setting to be used to
         configure Receive FIFO threshold in bytes. The trigger level can be any
         any of the possible values from #UART_FIFO_TRIGGER_LVL_MIN to
         #UART_FIFO_TRIGGER_LVL_MAX. */
    uint32_t clearTxFifo;
    /**< Value to specify whether Transmit FIFO has to be cleared.
         clearTxFifo can take any of the 2 values
         TRUE to clear the Transmit FIFO
         FALSE to not clear the Transmit FIFO */
    uint32_t clearRxFifo;
    /**< Value to specify whether Receiver FIFO has to be cleared.
         clearTxFifo can take any of the 2 values
         TRUE to clear the Receive FIFO
         FALSE to not clear the Receive FIFO */
    uint32_t  enableDma;
    /**< Indicates whether DMA needs to be enabled.
         Possible values are as follows
         TRUE to enable the DMA
         FALSE to disable the DMA */
}uartFifoCfg_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This API returns the Revision Number of the UART module.
 *
 * \param  baseAddr   Memory address of the UART instance being used
 *
 * \retval revision   The value holding the Revision Number of the module.
 */
uint16_t UARTGetRevision(uint32_t baseAddr);

/**
 * \brief  This API performs a module reset of the UART instance. It also waits
 *         until the reset process is complete.
 *
 * \param  baseAddr  Memory address of the UART instance being used.
 */
void UARTModuleReset(uint32_t baseAddr);

/**
 * \brief  This API configures the specified Register Access mode of UART to
 *         allow access to certain registers.
 *
 * \param  baseAddr       Memory address of the UART instance being used.
 * \param  accessMode     This specifies the register access mode to be enabled
 *         'accessMode' can take one of the macros from following enum
 *         - #uartRegAccessMode_t
 *
 * \retval lcrRegVal    The contents of the Line Control Register(LCR) before it
 *                      was modified.
 */
uint16_t UARTSetRegAccessMode(uint32_t baseAddr, uint32_t accessMode);

/**
 * \brief  This API sets the baud rate value for the UART operation according
 *         to the value passed by the user.
 *
 * \param  baseAddr    Memory address of the UART instance being used.
 * \param  moduleClk   The frequency of the input clock to the UART module.
 * \param  baudRate    It specifies the baudRate to be set for the device.
 *         'baudRate' takes one of the macro values from the following enum
 *          - #uartBaudRate_t
 *
 * \note As per the baudRate value specified the API configures the UART to
 *       operate in UART 16x mode or UART 13x mode.
 */
void UARTSetBaudRate(uint32_t baseAddr, uint32_t moduleClk, uint32_t baudRate);

/**
 * \brief   This API enables the specified interrupts for UART module.
 *
 * \param   baseAddr   Memory address of the UART instance being used.
 * \param   intrMask   Bit mask value specifying the UART interrupts
 *                     to be enabled.
 *          'intrMask' can take one or a combination of the following macros
 *           from the following enum -#uartIntrMask_t
 */
void UARTIntrEnable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief   This API disables the specified interrupts in the UART mode of
 *          operation.
 *
 * \param   baseAddr   Memory address of the UART instance being used.
 * \param   intrMask   Bit mask value specifying the UART interrupts
 *                     to be enabled.
 *          'intrMask' can take one or a combination of the following macros
 *          from the following enum -#uartIntrMask_t
 */
void UARTIntrDisable(uint32_t baseAddr, uint32_t intrMask);

/**
 * \brief  This API returns the status of UART Interrupts.
 *
 * \param  baseAddr   Memory address of the UART instance being used.
 *
 * \retval status     The status of the active and enabled interrupt which
 *                    will be one of the values from the enum
 *                    - #uartIntrStatus_t
 *
 * \note   To Check the status of a specific interrupt AND the return value
 *         of the API with specific interrupt value from the following enum.
 *         #uartIntrStatus_t
 */
uint16_t UARTIntrStatus(uint32_t baseAddr);

/**
 * \brief  This API determines whether any UART interrupt condition is
 *         pending to be serviced.
 *
 * \param  baseAddr   Memory address of the UART instance being used.
 *
 * \retval TRUE   If servicing an interrupt is still pending.
 * \retval FALSE  If there are no interrupts to be serviced.
 */
uint32_t UARTIsIntrPending(uint32_t baseAddr);

/**
 * \brief  This API is used to enable/disable the feature to get Transmit
 *         interrupts when both the Tx FIFO and the Shift register become empty.
 *
 * \param  baseAddr           Memory address of the UART instance being used.
 * \param  enableTxEmptyIntr  This specifies whether the Tx Empty Interrupt
 *                            condition should be enabled or disabled.
 *         'enableTxEmptyIntr' can take one of the following two values:
 *         - TRUE  to enable the Tx Empty Interrupt feature.
 *         - FALSE to disable the Tx Empty Interrupt feature.
 */
void UARTTxEmptyIntrEnable(uint32_t baseAddr, uint32_t enableTxEmptyIntr);

/**
 * \brief  This API returns the Line status of UART including errors and FIFO
 *         status.
 *
 * \param  baseAddr   Memory address of the UART instance being used.
 *
 * \retval status     This returns the line status. This can be one or a
 *                    combination of the below values from the enum:
 *                    - #uartLineStsMask_t
 */
uint16_t UARTLineStatus(uint32_t baseAddr);

/**
 * \brief    This API configures the Line Characteristics for the UART instance.
 *
 *  \details The Line Characteristics include:
 *           - Character length per frame
 *           - Number of Stop Bits per frame
 *           - Parity type per frame
 *
 * \param   baseAddr    Memory address of the UART instance being used.
 * \param   charLength  Bit mask value of the bits pertaining to character
 *                      length selection per frame.
 *          'charLength' can take one of the following values from the enum:
 *          -#uartCharLength_t
 * \param   stopBit     Takes a macro value to indicate the StopBit to be used
 *                      per frame in the UART transmission/reception.
 *          'stopBit' can take one of the following values from the enum:
 *          -#uartStopBit_t
 * \param   parity      Bit mask value of the bits pertaining to parity
 *                      type for a frame in UART.
 *          'parity' can take one of the following values from the enum:
 *          - #uartParity_t
 *
 * \note    Please note the following points about Stop Bit configuration
 *          - The 1.5 Stop bits per frame is applicable only for a char length
 *            of 5 bits per frame.
 *          - Similarly the 2 Stop bits per frame is applicable only for a char
 *            length of 6,7 and 8 bits per frame.
 */
void UARTLineCharacteristicConfig(uint32_t baseAddr,
                                  uint32_t charLength,
                                  uint32_t stopBit,
                                  uint32_t parity);

/**
 * \brief  This API configures the FIFO settings for the UART instance.
 *
 * \details This API provides a common interface for configuring the FIFO
 *          related settings through both the FCR and TLR/TCR registers.
 *          The following Fifo related configuration are done by the API.
 *          -# Enables the FIFO mode of UART
 *          -# Transmitter and Receiver FIFO Trigger Level granularity setting
 *          -# Transmitter and Receiver FIFO Trigger Level configuration
 *          -# Clearing of the Tx and Rx FIFOs
 *          -# Enables/Disables the DMA mode of operation
 *
 * \param   baseAddr  Memory address of the UART instance being used.
 * \param   pFifoCfg  Pointer to the structure #uartFifoCfg_t holding the fifo
 *          configuration parameters.
 *
 * \note    Please note the following points regarding the FIFO configuration
 *          parameters
 *          - For a trigger level granularity of 1(#UART_TRIGGER_LVL_GRAN_1)
 *            the acceptable trigger level values will range from 1 to 63.
 *          - For a trigger level granularity of 4(#UART_TRIGGER_LVL_GRAN_4)
 *            the acceptable trigger level values will range from 1 to 15.
 *          - FCR is a write-only register and its contents cannot be read
 *            Hence, it is  not possible for a read-modify-write operation
 *            on this register. Therefore it is expected that the FIFO
 *            configuration is done at once for both Tx and Rx.
 */
void UARTFifoConfig(uint32_t baseAddr, uartFifoCfg_t *pFifoCfg);

/**
 * \brief  This API determines whether FIFO mode of operation is enabled
 *         for the UART instance or not.
 *
 * \param  baseAddr  Memory address of the UART instance being used.
 *
 * \retval TRUE      If FIFO mode of operation is enabled
 * \retval FALSE     If FIFO mode of operation is disabled
 */
uint32_t UARTIsFifoEnabled(uint32_t baseAddr);

/**
 * \brief    This API enables the Wakeup capability for the specified events.
 *
 * \details  If wakeup mechanism is not enabled then this API enables the wakeup
 *           mechanism before selecting the wakeup source. On enabling Wakeup
 *           capability for them, the occurrence of the corresponding event
 *           shall wakeup the system.
 *
 * \param  baseAddr     Memory address of the UART instance being used.
 * \param  wakeupEvent  This specifies the event(s) for which Wakeup
 *                      capability needs to be enabled.
 *         'wakeupEvent' can take one or a combination of the following values
 *          from the following enum:
 *          -#uartWakeupEvent_t
 */
void UARTWakeupEventEnable(uint32_t baseAddr, uint32_t wakeupEvent);

/**
 * \brief    This API disables the Wakeup capability for the specified events.
 *
 * \details  On disabling Wakeup capability for them, the occurrence of the
 *           corresponding event shall not wake up the system. If all the wakeup
 *           sources are disabled then it disables the wakeup mechanism.
 *
 * \param  baseAddr     Memory address of the UART instance being used.
 * \param  wakeupEvent  This specifies the event(s) for which Wakeup
 *                      capability needs to be disabled.
 *         'wakeupEvent' can take one or a combination of the following values
 *          from the following enum:
 *          -#uartWakeupEvent_t
 */
void UARTWakeupEventDisable(uint32_t baseAddr, uint32_t wakeupEvent);

/**
 * \brief  This API enables/disables the wakeup interrupt feature.
 *
 * \param  baseAddr          Memory address of the UART instance being used.
 * \param  enableWakeupIntr  This specifies whether the wakeup interrupt is to
 *                           enabled/disabled.
 *         'enableWakeupIntr' can take any of the two values
 *          - TRUE  to enable the wakeup interrupt feature.
 *          - FALSE to disable the wakeup interrupt feature.
 */
void UARTWakeupIntrEnable(uint32_t baseAddr, uint32_t enableWakeupIntr);

/**
 * \brief  This API is used to control(enable/disable) the Auto-Idle mode
 *         of operation of the UART.
 *
 * \param  baseAddr       Memory address of the UART instance being used.
 * \param  enableIdleMode This specifies whether to enable or disable the
 *                        Auto-Idle mode of the UART
 *         'enableIdleMode' can take one of the following two values:
 *         - TRUE to enable Auto-Idle mode
 *         - FALSE to disable Auto-Idle mode
 */
void UARTAutoIdleEnable(uint32_t baseAddr, uint32_t enableIdleMode);

/**
 * \brief   This API sets UART to one of the idle modes.
 *
 * \param   baseAddr    It is the Memory address of the UART instance used.
 * \param   idleMode    It is the value which determines the type of idle
 *                      mode operation.
 *          'idleMode' can take macros from the following enum
 *          - #uartIdleMode_t.
 */
void UARTSetIdleMode(uint32_t baseAddr, uint32_t idleMode);

/**
 * \brief  This API controls(enables/disables) the Loopback mode of operation
 *         for the UART instance.
 *
 * \param  baseAddr         Memory address of the UART instance being used
 * \param  enableLoopBack   This specifies whether to enable or disable Loopback
 *                          mode of operation
 *         'enableLoopBack' can take one of the following values:
 *        - TRUE  To enable Loopback mode of operation
 *        - FALSE To disable Loopback mode and thus resulting
 *                in switching to Normal operating mode
 */
void UARTLoopbackEnable(uint32_t baseAddr, uint32_t enableLoopBack);

/**
 * \brief  This API is used to enable/disable a Break condition where the
 *         transmitter output goes low to alert the communication terminal.
 *
 * \param  baseAddr       Memory address of the UART instance being used.
 * \param  enableBrkCtrl  This specifies whether the break condition should be
 *                        enabled or disabled.
 *         'enableBrkCtrl' can take one of the following two values:
 *         - TRUE  to enable the Break condition
 *         - FALSE to disable the Break condition if it has already been enabled
 */
void UARTBreakCtrlEnable(uint32_t baseAddr, uint32_t enableBrkCtrl);

/**
 * \brief   This API determines the current level of the Transmitter FIFO.
 *
 * \param   baseAddr   Memory address of the UART instance being used.
 * \param   fifoType   It specifies the fifo type i.e. can be RX or TX.
 *
 * \retval  fifoStatus The current level of the FIFO in bytes.
 */
uint16_t UARTGetFifoLevel(uint32_t baseAddr, uint32_t fifoType);

/**
 * \brief  This API determines whether the Transmitter FIFO is full or not.
 *
 * \param  baseAddr     Memory address of the UART instance being used
 *
 * \retval  TRUE indicating that the TX FIFO is full.
 * \retval  FALSE indicating that the TX FIFO is not full.
 */
uint32_t UARTIsTxFifoFull(uint32_t baseAddr);

/**
 * \brief  This API checks if the RX FIFO has atleast one byte of data to be
 *         read.
 *
 * \param  baseAddr    Memory address of the UART instance being used.
 *
 * \retval TRUE   If there is atleast one byte present in the RX FIFO
 * \retval FALSE  If there are no data bytes present in the RX FIFO
 */
uint32_t UARTIsCharAvail(uint32_t baseAddr);

/**
 * \brief  This API checks whether the TX FIFO is empty or not.
 *
 * \param   baseAddr  Memory address of the UART instance being used.
 *
 * \retval  TRUE   if the Transmitter FIFO is empty.
 * \retval  FALSE  if the Transmitter FIFO is not empty.
 */
uint32_t UARTIsSpaceAvail(uint32_t baseAddr);

/**
 * \brief    This API reads a character from the UART.
 *
 * \details  The API provides an interface to read a character with three
 *           different options Blocking where the API waits continuously till
 *           the character is received.
 *           Non-blocking where the API checks once for the arrival of a
 *           character and returns error if no byte is received.
 *           Timeout approach where the API waits for the reception of a
 *           character till a timeout occurs.
 *
 * \param    baseAddr    Memory address of the UART instance being used.
 * \param    pRxChar     Pointer to a character where the read character needs
 *                       to be stored.
 * \param    timeout     The value which denotes the timeout required which can
 *                       take any values from 0 to FFFFFFFF.
 *
 * \retval   S_PASS    on successfully reading a character.
 * \retval   E_FAIL    on Failure if a character is not available to read.
 * \retval   E_TIMEOUT if a timeout occurs before arrival of a character.
 *
 * \note     timeout can take any of the following values
 *           - 0 value specifies non-blocking approach where the API checks
 *             once if a character is received and returns the byte else returns
 *             failure.
 *           - accepts the #UART_WAIT_FOREVER and waits indefinitely till the
 *             arrival of a character.
 *           - a finite timeout value less than FFFFFFFF to denote the timeout
 *             period till which it will wait for the reception of a character
 *             or else return a timeout error.
 */
int32_t UARTGetChar(uint32_t baseAddr, uint8_t *pRxChar, uint32_t timeout);

/**
 * \brief    This API puts a character to the UART FIFO for transmission.
 *
 * \details  The API provides an interface to write a character with three
 *           different options.
 *           Blocking where the API waits continuously till the UART FIFO
 *           is empty or holds enough space to write a character and writes the
 *           character to the FIFO.
 *           Non-blocking where the API checks once if there is space in FIFO
 *           for a character to be written else returns an error.
 *           Timeout approach where the API waits for FIFO to be empty to
 *           write a character till a timeout occurs.
 *
 * \param    baseAddr    Memory address of the UART instance being used.
 * \param    txChar      character which needs to be transmitted.
 * \param    timeout     the value which denotes the timeout required which can
 *                       take any values from 0 to FFFFFFFF.
 *
 * \retval   S_PASS    On successfully writing a character.
 * \retval   E_FAIL    On Failure if there is no space to write a character.
 * \retval   E_TIMEOUT If a timeout occurs before enough space becomes available
 *                     in the FIFO for a character to be written.
 *
 * \note    'timeout' can take any of the following values
 *           - 0 value specifies non-blocking approach where the API checks
 *             once if a character is received and returns the Character else
 *             returns failure.
 *           - accepts the macro #UART_WAIT_FOREVER and waits indefinitely till
 *             the arrival of a character.
 *           - a finite timeout value less than 0xFFFFFFFF to denote the timeout
 *             period, it decrements the timeout value till it reaches zero and
 *             within that period checks if there is space for a character to be
 *             written in the FIFO, if not then it returns a timeout error.
 */
int32_t UARTPutChar(uint32_t baseAddr, uint8_t txChar, uint32_t timeout);

/**
 * \brief  This API copies the requested amount of data from the
 *         specified data block to the UART Transmit FIFO.
 *
 * \param  baseAddr    Memory address of the UART instance being used.
 * \param  pBuf        The starting address of the data block.
 * \param  numTxBytes  The number of data bytes to be transmitted.
 *
 * \note   This API does not check for the emptiness of the TX FIFO or for
 *         its space availability before writing to it. The application
 *         calling this API has the responsibility of checking the TX
 *         FIFO status earlier by using #UARTIsSpaceAvail API.
 */
void UARTFifoWrite(uint32_t baseAddr, uint8_t *pBuf, uint32_t numTxBytes);

/**
 * \brief  This API reads the character at the top of the Receive FIFO.
 *
 * \param  baseAddr    Memory address of the UART instance being used.
 *
 * \retval rxByte      The byte read from the Receive FIFO.
 *
 * \note   This API does not check if the Receive FIFO contains any fresh
 *         data or availability of a character to read. The application
 *         calling this API has the responsibility of checking whether
 *         atleast a single character is available to read by using
 *         #UARTIsCharAvail API.
 */
uint8_t UARTFifoRead(uint32_t baseAddr);

/**
 * \brief   This API Enables the DMA mode and configures the DMA mode
 *          for the UART module.
 *
 * \param   baseAddr    It is the Memory address of the UART instance used.
 * \param   dmaMode     This specifies the DMA mode to be configured for the
 *                      UART instance.
 *          dmaMode can take one of the macros from the following enum:
 *         - #uartDmaMode_t
 */
void UARTDmaEnable(uint32_t baseAddr, uint32_t dmaMode);

/**
 * \brief  This API disables the DMA mode of operation and clears the DMA mode
 *         set for the UART instance.
 *
 * \param  baseAddr      Memory address of the UART instance being used.
 */
void UARTDmaDisable(uint32_t baseAddr);

/**
 * \brief   This function enables/disables the setting the TX_DMA_THRESHOLD
 *          register which holds Transmit DMA Threshold value to be used.
 *          This is used when Direct method of setting Tx DMA threshold is used
 *          instead of the TLR register.
 *
 * \param   baseAddr            Memory address of the UART instance being used.
 * \param   enableTxThreshold   Value to specify setting DMA threshold for Tx.
 *          'enableTxThreshold' can take any of the values from the following
 *          - TRUE to enable setting Tx Threshold for DMA.
 *          - FALSE to disable setting Tx Thresholf for DMA.
 */
void UARTDmaTxThresholdEnable(uint32_t baseAddr, uint32_t enableTxThreshold);

/**
 * \brief   This function sets the Transmit DMA Threshold value to be used.
 *          This is used when Direct method of setting Tx DMA threshold is used.
 *
 * \param   baseAddr       Memory address of the UART instance being used.
 * \param   thresholdVal   The Transmit DMA Threshold Value in terms of bytes.
 *          'thresholdVal' can take one of the values from (0 to 63).
 *
 * \note    Before calling this API to set the DMA threshold the Direct Method
 *          of setting the threshold should be enabled earlier through the API
 *          #UARTDmaTxThresholdEnable
 */
void UARTSetDmaTxThreshold(uint32_t baseAddr, uint32_t thresholdVal);

/**
 * \brief  This API controls enabling/disabling the DMA Counter Reset when
 *         the FIFO reset option is selected.
 *
 * \param  baseAddr            Memory address of the UART instance being used
 * \param  enableCounterReset  This specifies the DMA Counter Reset options
 *         'enableCounterReset' can take any of the 2 values:
 *         TRUE -  indicating that the DMA counter
 *                 shall be reset if the corresponding FIFO is reset
 *         FALSE - indicating that the DMA counter shall not
 *                 be reset if the corresponding FIFO is reset.
 */
void UARTDmaCounterResetEnable(uint32_t baseAddr, uint32_t enableCounterReset);

/**
 * \brief  This API enables/disables the Auto-RTS (Request to Send) hardware
 *         flow control feature.
 *
 * \param  baseAddr       Memory address of the UART instance being used.
 * \param  enableAutoRts  This specifies whether to enable or disable
 *                        Auto-RTS functionality.
 *         'enableAutoRts' can take any of the two values
 *         - TRUE  to enable the Auto-RTS feature.
 *         - FALSE to enable the Auto-RTS feature.
 */
void UARTAutoRtsEnable(uint32_t baseAddr, uint32_t enableAutoRts);

/**
 * \brief  This API enables/disables the Auto-CTS (Clear to Send) hardware flow
 *         control feature.
 *
 * \param  baseAddr       Memory address of the UART instance being used.
 * \param  enableAutoCts  This specifies whether to enable or disable
 *                        Auto-CTS functionality.
 *         'enablAutoCts' can take any of the two values
 *         - TRUE  to enable the Auto-CTS feature.
 *         - FALSE to enable the Auto-CTS feature.
 */
void UARTAutoCtsEnable(uint32_t baseAddr, uint32_t enableAutoCts);

/**
 * \brief  This API configures the Receiver FIFO trigger levels to
 *         start/stop transmission when flow control feature of UART is enabled.
 *
 * \param  baseAddr           Memory address of the UART instance being used.
 * \param  rxHaltTriggerLvl   The receiver FIFO trigger level to HALT
 *                            transmission
 *         'rxHaltTriggerLvl' can take any of the values from 0 to 15.
 *         The actual trigger levels would then (rxHaltTriggerLvl * 4)
 * \param  rxStartTriggerLvl  The receiver FIFO trigger level to restore the
 *                            transmission.
 *         'rxStartTriggerLvl' can take any of the values from 0 to 15.
 *         The actual trigger levels would then (rxStartTriggerLvl * 4)
 *
 * \note    When Flow control is enabled following conditions need to be taken
 *          care
 *        - RX FIFO Threshold Level to Halt Transmission should be greater
 *          than the RX Threshold level to Restore the transmission
 *        - In FIFO Interrupt mode with Flow Control, the RX FIFO trigger
 *          level to Halt Transmission should be greater than or equal to the
 *          Receiver FIFO trigger level.
 */
void UARTSetFlowCtrlTriggerLvl(uint32_t baseAddr,
                               uint32_t rxHaltTriggerLvl,
                               uint32_t rxStartTriggerLvl);

/**
 * \brief  This API configures the Software Flow Control combinations.
 *
 * \param  baseAddr     Memory address of the UART instance being used.
 * \param  flowCtrlCfg  This specifies the different software flow control
 *                      combinations possible.
 *         'flowCtrlCfg' can take any of the values from the following enum
 *         - #uartSwFlowCtrlCfg_t
 */
void UARTSwFlowCtrlConfig(uint32_t baseAddr, uint32_t flowCtrlCfg);

/**
 * \brief  This API sets the XON1 and XOFF1 characters required to indicate
 *         the Start/Stop of transmission when software flow control is enabled.
 *
 * \param  baseAddr     Memory address of the UART instance being used.
 * \param  xon1Char     The XON1 character to be set.
 * \param  xoff1Char    The XOFF1 character to be set.
 */
void UARTSetXon1Xoff1Char(uint32_t baseAddr,
                          uint8_t xon1Char,
                          uint8_t xoff1Char);

/**
 \brief  This API sets the XON2 and XOFF2 characters required to indicate
 *       the Start/Stop of transmission when software flow control is enabled.
 *
 * \param  baseAddr   Memory address of the UART instance being used.
 * \param  xon2Char   The XON2 character to be set.
 * \param  xoff2Char  The XOFF2 character to be set.
 */
void UARTSetXon2Xoff2Char(uint32_t baseAddr,
                          uint8_t xon2Char,
                          uint8_t xoff2Char);

/**
 * \brief    This API Enables/Disables the XON any feature of Software Flow
 *           Control.
 *
 * \details  When XON-any feature is enabled, the transmission will resume after
 *           receiving any character after recognizing the XOFF character. The
 *           XON-any character is written into the RX FIFO even if it is a
 *           software flow character.
 *
 * \param  baseAddr             Memory address of the UART instance being used.
 * \param  enableXonAnyFeature  This specifies whether to enable or disable XON
 *                              any feature.
 *         'enableXonAnyFeature' can take one of the following values:
 *         - TRUE  to enable XON any functionality
 *         - FALSE to disable XON any functionality
 */
void UARTXonAnyFeatureEnable(uint32_t baseAddr, uint32_t enableXonAnyFeature);

/**
 * \brief  This API controls enabling/disabling the feature of detecting a
 *         Special Character through the UART receiver.
 *
 * \param   baseAddr           Memory address of the UART instance being used.
 * \param   enableSpecCharDtct This specifies whether to enable or disable
 *                             special character detect feature.
 *          'enableSpecCharDtct' can take either of the following two values:
 *          - TRUE  to enable Special Character detect functionality
 *          - FALSE to disable Special Character detect functionality
 */
void UARTSpecialCharDetectEnable(uint32_t baseAddr,
                                 uint32_t enableSpecCharDtct);

/**
 * \brief  This API controls enabling/disabling the Pulse Shaping feature of
 *         the UART.
 *
 * \param   baseAddr           Memory address of the UART instance being used.
 * \param   enablePulseShaping This specifies whether to enable or disable
 *                             pulse shaping feature in the UART.
 *          'enablePulseShaping' can take either of the following two values:
 *          - TRUE  to enable UART Pulse Shaping feature.
 *          - FALSE to disable UART Pulse Shaping feature.
 */
void UARTPulseShapingEnable(uint32_t baseAddr, uint32_t enablePulseShaping);

/**
 * \brief    This API clears the interrupt flags to resume UART transmission
 *           when halted due to overflow/underrun errors.
 *
 * \details  This API does a dummy read of Resume register to clear the interrupt
 *           flags.
 *
 * \param  baseAddr    Memory address of the UART instance being used.
 */
void UARTResumeOper(uint32_t baseAddr);

/**
 * \brief   This API switches the specified Modem Control Signals to active
 *          or inactive state depending on the option passed by user.
 *
 * \details The Modem Control signals in context are:
 *          - Data Carrier Detect(DCD)
 *          - Ring Indicator(RI)
 *          - Data Set Ready(DSR)
 *          - Clear To Send(CTS)
 *
 * \param  baseAddr    Memory address of the UART instance being used.
 * \param  modemPin    This specifies the signals that are required to be
 *                     switched to active/inactive state.
 *         'modemPin' can take any of the values from the following enum
 *         - #uartModemCtrlPin_t
 * \param  enableCtrlPin  value to control the Modem feature
 *         'enableCtrlPin' can take any of the two values
 *         - TRUE to set the modem pin to active state
 *         - FALSE to set the modem pin to inactive state
 */
void UARTModemCtrlEnable(uint32_t baseAddr,
                         uint32_t modemPin,
                         uint32_t enableCtrlPin);

/**
 * \brief   This API provides the current state of the control lines from the
 *          modem, data set or peripheral device.
 *
 * \details The Modem Signals in context are:
 *          - Data Carrier Detect(DCD)
 *          - Ring Indicator(RI)
 *          - Data Set Ready(DSR)
 *          - Clear To Send(CTS)
 *
 * \param  baseAddr   Memory address of the UART instance being used.
 *
 * \retval status     The status of all modem control pins.
 *
 * \note   To Check the status of a specific modem pin AND the return value
 *         of the API with specific modem control pin mask from the following
 *         enum - #uartModemSts_t.
 */
uint16_t UARTModemStatus(uint32_t baseAddr);

/**
 * \brief  This API enables/disables the DSR(Data Set Ready) pin status
 *         Interrupt feature.
 *
 * \param    baseAddr        Memory address of the UART instance being used.
 * \param    enableDsrIntr   It indicates whether the DSR Interrupt needs to
 *                           be enabled/disabled.
 *         'enableDsrIntr' can take any of the two values
 *         - TRUE  to enable the wakeup interrupt feature.
 *         - FALSE to disable the wakeup interrupt feature.
 */
void UARTDsrPinIntrEnable(uint32_t baseAddr, uint32_t enableDsrIntr);

/**
 * \brief  This API returns the status of falling edge signal status
 *         on the Receive, CTSn(Clear to Send) and DSRn(Data Set Ready) lines.
 *
 * \param  baseAddr  Memory address of the UART instance being used.
 *
 * \retval TRUE   To indicate a falling edge event occurred on CTS, DSR lines.
 * \retval FALSE  To indicate no falling edge event occurred on CTS, DSR lines.
 */
uint32_t UARTRxCtsDsrTransitionStatus(uint32_t baseAddr);

/**
 * \brief    This API enables/disables the Auto-Baud mode of the UART module.
 *
 * \param    baseAddr        Memory address of the UART instance being used.
 * \param    enableAutobaud  Value that controls enabling/disabling the Autobaud
 *                           mode.
 *          'enableAutobaud' can take any of the two values
 *          - TRUE to enable the Autobaud feature.
 *          - FALSE to disable the Autobaud feature.
 */
void UARTEnableAutobaudMode(uint32_t baseAddr, uint32_t enableAutobaud);

/**
 * \brief  This API returns the Parity mode detected by UART in Autobaud mode.
 *
 * \param  baseAddr       Memory address of the UART instance being used.
 *
 * \retval autoBaudParity This returns one of the following values from the enum
 *                        - #uartAutoBaudParity_t
 */
uint16_t UARTGetAutoBaudParity(uint32_t baseAddr);

/**
 * \brief  This API returns the word length per frame(character length)
 *         detected by UART in Autobaud mode.
 *
 * \param  baseAddr  Memory address of the UART instance being used.
 *
 * \retval wordLen   This returns one of the following two values from the enum
 *                   - #uartAutoBaudWordLen_t
 */
uint16_t UARTGetAutoBaudWordLen(uint32_t baseAddr);

/**
 * \brief  This API returns the baud rate detected by UART in Auto Baud Mode.
 *
 * \param  baseAddr  Memory address of the UART instance being used.
 *
 * \retval autoBaudSpeed  This returns one of the following values from the
 *                        enum -#uartAutoBaudSpeed_t
 */
uint16_t UARTGetAutoBaudSpeed(uint32_t baseAddr);

/**
 * \brief  This API programs the Scratch pad Register with the specified
 *         value.
 *
 * \param  baseAddr     Memory address of the UART instance being used
 * \param  scratchValue This is the scratch value(temporary data) to be loaded
 *                      to the Scratch pad Register
 */
void UARTSetScratchPadValue(uint32_t baseAddr, uint16_t scratchValue);

/**
 * \brief  This API reads the value in Scratch pad Register.
 *
 * \param  baseAddr      Memory address of the UART instance being used
 *
 * \retval scratchPadVal The value in Scratch pad Register
 */
uint16_t UARTGetScratchPadValue(uint32_t baseAddr);

/* ========================================================================== */
/*                     Deprecated Macros                                      */
/* ========================================================================== */

/**
 *  \name Deprecated Macros representing Parity type configured for UART.
 */
/** @{ */
/** \brief Macro representing UART Parity Type bit of Mark. */
#define UART_PARITY_REPR_1              (UART_LCR_PARITY_TYPE2_MASK | \
                                         (UART_LCR_PARITY_TYPE1_ODD << \
                                         UART_LCR_PARITY_TYPE1_SHIFT) | \
                                         UART_LCR_PARITY_EN_GENERATED)

/** \brief Macro representing UART Parity Type bit of Space. */
#define UART_PARITY_REPR_0              (UART_LCR_PARITY_TYPE2_MASK | \
                                         (UART_LCR_PARITY_TYPE1_EVEN << \
                                         UART_LCR_PARITY_TYPE1_SHIFT) | \
                                         UART_LCR_PARITY_EN_GENERATED)

/** \brief Macro representing UART Parity Type bit of Odd. */
#define UART_ODD_PARITY                 ((UART_LCR_PARITY_TYPE1_ODD << \
                                            UART_LCR_PARITY_TYPE2_SHIFT) | \
                                            UART_LCR_PARITY_EN_GENERATED)

/** \brief Macro representing UART Parity Type bit of Even. */
#define UART_EVEN_PARITY                ((UART_LCR_PARITY_TYPE1_EVEN << \
                                            UART_LCR_PARITY_TYPE2_SHIFT) | \
                                            UART_LCR_PARITY_EN_GENERATED)

/** \brief Macro representing No UART Parity type selection. */
#define UART_PARITY_NONE                (UART_LCR_PARITY_EN_NOT_GENERATED << \
                                            UART_LCR_PARITY_EN_SHIFT)
/** @} */

/* ========================================================================== */
/*                     Deprecated Function Declarations                       */
/* ========================================================================== */

/**
 * \brief  This API enables the MSR_SPR Sub-Configuration Mode of operation.
 *
 * \note   The current API enables access to Modem Status Register(MSR) and
 *         Scratch Pad Register(SPR). This is applicable for Register
 *         Configuration Mode A and Operational mode of operation.
 */
DEPRECATED(uint32_t UARTSubConfigMSRSPRModeEn(uint32_t baseAddr));

/**
 * \brief  This API enables the TCR_TLR Sub_Configuration Mode of operation.
 *
 * \note   The current API enables access to Transmission Control Register(TCR)
 *         and Trigger Level Register(TLR). This is applicable for all the
 *         three register configuration modes.
 */
DEPRECATED(uint32_t UARTSubConfigTCRTLRModeEn(uint32_t baseAddr));

/**
 * \brief  This API enables the XOFF Sub-Configuration Mode of operation.
 *
 * \note   The current API enables access to the XOFF (XOFF1 and XOFF2)
 *         registers. The XOFF registers can be accessed in Register
 *         Configuration Mode B of operation.
 */
DEPRECATED(uint32_t UARTSubConfigXOFFModeEn(uint32_t baseAddr));

/**
 * \brief  This API restores the TCRTLR bit(MCR[6]) value in Modem Control
 *         Register(MCR) to the corresponding bit value in 'tcrTlrBitVal'
 *         passed as a parameter to this API.
 */
DEPRECATED(void UARTTCRTLRBitValRestore(uint32_t baseAddr,
                                        uint32_t tcrTlrBitVal));

/**
 * \brief   This API returns the Parity type set for the UART transmission.
 */
DEPRECATED(uint32_t UARTParityModeGet(uint32_t baseAddr));

#ifdef __cplusplus
}
#endif

#endif
