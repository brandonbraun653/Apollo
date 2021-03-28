/**
 *  \file  uart_app.h
 *
 *  \brief This file contains the function declarations and data structures
 *         corresponding to the uart.
 *
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

#ifndef UART_APP_H_
#define UART_APP_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "uart.h"
#include "interrupt.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/* None */


/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Structure holding UART interrupt configuration parameters. */
typedef struct uartAppIntrCfgObj
{
    intcTrigType_t intrTrigType;
    /**< Type of interrupt Edge/Level. */
    uint32_t intrLine;
    /**< Interrupt line number. */
    uint32_t intrPriority;
    /**< Interrupt priority level. */
    uint32_t isIntrSecure;
    /**< Secure Interrupt or not */
    void (*pFnIntrHandler)(uint32_t intrId, uint32_t cpuId, void* pUserParam);
    /**< Function pointer to Interrupt handler which needs to be
     *  registered with the interrupt Controller.- Application needs
     *  to initialize this. If set to null then polling Mode is assumed
     */
} uartAppIntrCfg_t;

/** \brief Structure holding UART Transfer Status information. */
typedef struct uartAppXferStatus
{
    uint32_t intrId;
    /**< Value holding the Identity of the interrupt occurred. */
    uint32_t  lineStatus;
    /**< Value holding the UART Line Status */
}uartAppXferStatus_t;

/**
 *  \brief Structure defining the parameters for data, interrupt, chain and link
 *         configuration of a transfer.
 */
typedef struct uartAppDmaCfg
{
    uint32_t             dmaType;
    /**< Type of DMA. */
    dmaUtilsEvtInfo_t    rxEvtInfo;
    /**< UART RX event configuration. */
    dmaUtilsEvtInfo_t    txEvtInfo;
    /**< UART RX event configuration. */
    DMACallBackFxn       pFxnCallBack;
    /**< Call back function to handle DMA status. */
} uartAppDmaCfg_t;

/**< /brief Structure holdig the UART application related configuration */
typedef struct uartAppCfg
{
    uartBaudRate_t      baudRate;
    /**< Baud rate */
    uartCharLength_t    charLen;
    /**< Char Length */
    uartStopBit_t       stopBits;
    /**< Number of stop bits */
    uartParity_t        parity;
    /**< Parity */
    uint32_t            enableIntr;
    /**< Enable Interrupt */
    uartAppIntrCfg_t    uartAppIntrCfg;
    /**< UART interrupt Configuration Structure */
    uint32_t            enableDma;
    /**< Enable Interrupt */
    uartAppDmaCfg_t     dmaCfg;
    /**< UART DMA Configuration Structure */
} uartAppCfg_t;

/**< /brief Structure holdig the UART application related data */
typedef struct uartAppObj
{
    uartAppCfg_t         uartAppCfg;
    /**< UART application Configuration Structure */
    uint32_t             instNum;
    /**< UART instance number */
    uint32_t             instAddr;
    /**< UART instance address */
    uint32_t             modClk;
    /**< UART module clock. */
    volatile uint32_t    isTxFifoEmpty;
    /**< A flag used to signify the application to transmit data to UART TX
         FIFO. Takes TRUE/FALSE values */
    volatile uint32_t    numRdBytesISR;
    /**< Number of bytes read in the ISR. */
    uint32_t    numRdBytes;
    /**< Number of bytes read */
} uartAppObj_t;


/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* Global structure containing the IP configuration defaults */
extern uartAppObj_t UARTAPPOBJ_DEFAULT;


/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief   UART IP configuration initialization api.
 *
 * \param   pUartCfg        Pointer to the UART app configuration.
 *
 * \retval  S_PASS      IP configuration is successful.
 * \retval  E_FAIL      IP configuration is failed (either Pinmux or Clock
 *                      configuration is failed).
 */
int32_t UARTAppInit(uartAppObj_t *pObj);

/**
 * \brief   Setup EDMA for UART RX.
 *
 * \param   pObj          Pointer to the UART app configuration.
 * \param   pBuf          Buffer to which received bytes shall be copied.
 * \param   bytesPerEvt   Number bytes for which a Uart DMA event is generated.
 * \param   noOfBytes     Number of bytes to be received. It shall be in
 *                        multiples of bytesPerEvt else reminder bytes are not
 *                        received.
 *
 * \retval  S_PASS        EDMA configuration for UART RX is successful.
 * \retval  E_FAIL        Failed to configure EDMA for UART RX.
 *
 * \Note    noOfBytes shall be in multiples of bytesPerEvt else reminder bytes
 *          are not read.
 */
int32_t UARTAppDmaRxSetup(uartAppObj_t *pObj,
                          uint8_t *pBuf,
                          uint32_t bytesPerEvt,
                          uint32_t noOfBytes);

/**
 * \brief   Setup EDMA for UART RX.
 *
 * \param   pObj          Pointer to the UART app configuration.
 * \param   pBuf          Buffer from which bytes shall be transmitted.
 * \param   bytesPerEvt   Number bytes for which a Uart DMA event is generated.
 * \param   noOfBytes     Number of bytes to be transmitted. It shall be in
 *                        multiples of bytesPerEvt else reminder bytes are not
 *                        transmitted.
 *
 * \retval  S_PASS        EDMA configuration for UART TX is successful.
 * \retval  E_FAIL        Failed to configure EDMA for UART TX.
 *
 * \Note    noOfBytes shall be in multiples of bytesPerEvt else reminder bytes
 *          are not transmitted.
 */
int32_t UARTAppDmaTxSetup(uartAppObj_t *pObj,
                          uint8_t *pBuf,
                          uint32_t bytesPerEvt,
                          uint32_t noOfBytes);

/**
 * \brief   Start UART EDMA transfer.
 *
 * \param   pObj        Pointer to the UART app configuration.
 * \param   evt         UART transfer event to be initiated.
 *
 * \retval  S_PASS      UART transfer initiation successful.
 * \retval  E_FAIL      Failed to initiate UART transfer.
 */
int32_t UARTAppDmaXferStart(uartAppObj_t *pObj, uint32_t evt);

/**
 * \brief   Stop UART EDMA transfer.
 *
 * \param   pObj        Pointer to the UART app configuration.
 * \param   evt         UART transfer event to be terminated.
 *
 * \retval  S_PASS      UART transfer termination successful.
 * \retval  E_FAIL      Failed to terminate UART transfer.
 */
int32_t UARTAppDmaXferStop(uartAppObj_t *pObj, uint32_t evt);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef UART_APP_H_ */
