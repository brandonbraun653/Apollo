/**
 * \file   uart_app.c
 *
 * \brief  Source file containing the UART IP related configuration functions.
 *         These functions will be called by example application.
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "types.h"
#include "chipdb.h"
#include "pinmux.h"
#include "uart.h"
#include "error.h"
#include "dma.h"
#include "dma_utils.h"

/* Application header files */
#include "uart_app.h"
#include "prcm.h"

/* ========================================================================== */
/*                                Macros                                      */
/* ========================================================================== */

/** \brief UART module clock. */
#define UART_MODULE_INPUT_CLK      (48000000U)
#define UART_READ_SIZE_BYTES       (10U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */
/**
 * \brief   Perform the UART FIFO configurations.
 *
 * \param   pUartCfg        Pointer to the UART app configuration.
 */
static void UartAppFifoConfig(uartAppObj_t *pObj);

/**
 *  \brief   A Interrupt Service routine which is invoked when the UART
 *           interrupt is raised. The ISR handles different cases like Transmit,
 *           Receive threshold interrupts.
 *
 *  \param   intrNum    interrupt number to which the interrupt event is mapped.
 *  \param   cpuId      id of the CPU to which interrupt is raised.
 *  \param   userParam  parameter to be passed to the ISR.
 */
static void UartAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam);

/**
 *  \brief   Initializes the interrupt controller and configures it with
 *           different parameters like triggertype, Interrupt Priority
 *           and registers the Interrupt Service Routine to be invoked
 *           when the Interrupt is raised.
 *
 *  \param   pUartIntrConfig   Pointer to the interrupt configuration structure.
 */
static int32_t UartAppIntrConfig(uartAppObj_t *pObj);

/**
 * \brief   Set the baud rate for UART.
 *
 * \param   pObj        Pointer to the UART app configuration.
 * \param   baudRate    Baud rate to be configured.
 */
static void UartAppSetBaudRate(uartAppObj_t *pObj, uartBaudRate_t baudRate);

/**
 * \brief   Set the line characteristics for UART.
 *
 * \param   pObj        Pointer to the UART app configuration.
 * \param   charLen     Char length to be configured
 * \param   stopBits    Stop bits to be configured.
 * \param   parity      Parity to be configured.
 */
static void UartAppLineCharacteristicConfig(uartAppObj_t    *pObj,
                                            uartCharLength_t charLen,
                                            uartStopBit_t    stopBits,
                                            uartParity_t     parity);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief IP default configuration */
uartAppObj_t UARTAPPOBJ_DEFAULT =
{
    {
        UART_BAUD_RATE_115200, /* baudRate*/
        UART_CHAR_LENGTH_8BIT, /* charLen */
        UART_STOP_BIT_1, /* stopBits */
        UART_PARITY_NONE, /* parity */
        FALSE, /* enableIntr */
        {
            INTC_TRIG_HIGH_LEVEL,       /* trigType */
            0U,                         /* intrLine */
            /* The interrupt line shall be updated using ChipDB */
            0x20U,                       /* intrPriority */
            FALSE,                      /* isIntrSecure */
            NULL,                       /* pFnIntrhandler */
        }, /* uartAppIntrCfg_t*/
        FALSE, /* enableDma */
        {
            0U,                                        /* dmaType */
            {
                0U,                                    /* dmaType */
                0U,                                    /* instNum */
                DMA_UTILS_EVENT_MAP_TYPE_DIRECT,       /* evtToChMapType */
                0U,                                    /* evtNum */
                0U,                                    /* chNum */
                0U                                     /* xferIdx */
            }, /* dmaUtilsEvtInfo_t */
            {
                0U,                                    /* dmaType */
                0U,                                    /* instNum */
                DMA_UTILS_EVENT_MAP_TYPE_DIRECT,       /* evtToChMapType */
                0U,                                    /* evtNum */
                0U,                                    /* chNum */
                0U                                     /* xferIdx */
            } /* dmaUtilsEvtInfo_t */
        } /* uartAppDmaCfg_t */
    }, /* uartAppCfg_t */
    0U, /* instNum*/
    0U, /* instAddr*/
    UART_MODULE_INPUT_CLK, /* modClk */
    FALSE, /* isTxFifoEmpty */
    0U, /* numRdBytesISR */
    UART_READ_SIZE_BYTES /* numRdBytes */
}; /* uartAppObj_t */


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

int32_t UARTAppInit(uartAppObj_t *pObj)
{
    int32_t status = S_PASS;

    /* Clock Configuration  */
    status = PRCMModuleEnable(CHIPDB_MOD_ID_UART, pObj->instNum, FALSE);

    if(S_PASS == status)
    {
        /* PinMux Configuration */
        status = PINMUXModuleConfig(CHIPDB_MOD_ID_UART, pObj->instNum, NULL);

        if(S_PASS == status)
        {
            /* Resetting the UART module. */
            UARTModuleReset(pObj->instAddr);

            UartAppSetBaudRate(pObj, pObj->uartAppCfg.baudRate);

            UartAppLineCharacteristicConfig(pObj,
                pObj->uartAppCfg.charLen,
                pObj->uartAppCfg.stopBits,
                pObj->uartAppCfg.parity);

            /* Disabling Break Control. */
            UARTBreakCtrlEnable(pObj->instAddr, FALSE);

            if(TRUE == pObj->uartAppCfg.enableIntr)
            {
                /* Configure the RX and TX FIFOs */
                UartAppFifoConfig(pObj);

                /* Configure the interrupts for UART. */
                status = UartAppIntrConfig(pObj);
            }
        }
    }

    return status;
}

int32_t UARTAppDmaRxSetup(uartAppObj_t *pObj,
                          uint8_t *pBuf,
                          uint32_t bytesPerEvt,
                          uint32_t noOfBytes)
{
    int32_t retStat = E_FAIL;
    uartAppDmaCfg_t *pUartDmaCfg = &(pObj->uartAppCfg.dmaCfg);
    dmaUtilsDataObj_t fifoDataObj =
    {
        0U,                                        /* addr */
        DMA_XFER_DATA_ADDR_MODE_INC,               /* addrMode */
        0U,                                        /* fifoWidth */
        1U,                                        /* packetActSize */
        1U,                                        /* frameActSize */
        1U,                                        /* blockSize */
        0U,                                        /* packetInactSize */
        0U,                                        /* frameInactSize */
        DMA_UTILS_DATA_SYNC_PACKET                 /* syncMode */
    }; /* dmaUtilsDataObj_t */
    dmaUtilsDataObj_t bufDataObj =
    {
        0U,                                        /* addr */
        DMA_XFER_DATA_ADDR_MODE_INC,               /* addrMode */
        0U,                                        /* fifoWidth */
        1U,                                        /* packetActSize */
        1U,                                        /* frameActSize */
        1U,                                        /* blockSize */
        0U,                                        /* packetInactSize */
        0U,                                        /* frameInactSize */
        DMA_UTILS_DATA_SYNC_PACKET                 /* syncMode */
    }; /* dmaUtilsDataObj_t */
    dmaUtilsXferObj_t xferObj =
    {
        NULL,                                      /* pSrc */
        NULL,                                      /* pDest */
        DMA_UTILS_DATA_SYNC_MASK_BLOCK,            /* intrConfig */
        FALSE,                                     /* linkEnable */
        0U                                         /* nxtXferIdx */
    }; /* dmaUtilsXferObj_t */
    dmaUtilsChObj_t chObj =
    {
        DMA_XFER_TRIGGER_TYPE_EVENT,               /* triggerType */
        0U,                                        /* xferIdx */
        TRUE,                                      /* intrEnable */
        NULL,                                      /* callBack */
        0U                                         /* queueNum */
    }; /* dmaUtilsChObj_t */

    if(NULL != pBuf)
    {
        retStat = S_PASS;
    }

    if((S_PASS == retStat) && (NULL == xferObj.pSrc))
    {
        xferObj.pSrc = &bufDataObj;
    }

    if((S_PASS == retStat) && (NULL == xferObj.pDst))
    {
        xferObj.pDst = &fifoDataObj;
    }

    if(S_PASS == retStat)
    {
        if(1U == xferObj.pSrc->frameActSize)
        {
            xferObj.pSrc->frameActSize =
                noOfBytes / xferObj.pSrc->packetActSize;
            xferObj.pSrc->blockSize = 1U;
        }
        else
        {
            xferObj.pSrc->blockSize =
                noOfBytes / (xferObj.pSrc->packetActSize *
                xferObj.pSrc->frameActSize);
        }

        xferObj.pSrc->addr = (uint32_t)(pObj->instAddr + 0U);
        xferObj.pDst->addr = (uint32_t)pBuf;
        chObj.xferIdx = pUartDmaCfg->rxEvtInfo.xferIdx;
        chObj.queueNum = 0U;
        chObj.intrEnable = TRUE;
        chObj.callBack = pObj->uartAppCfg.dmaCfg.pFxnCallBack;
        chObj.triggerType = DMA_XFER_TRIGGER_TYPE_EVENT;

        DMAUtilsDataXferConfig(pUartDmaCfg->dmaType,
            pUartDmaCfg->rxEvtInfo.instNum,
            pUartDmaCfg->rxEvtInfo.xferIdx,
            &xferObj);
        DMAUtilsChConfig(pUartDmaCfg->dmaType,
            pUartDmaCfg->rxEvtInfo.instNum,
            pUartDmaCfg->rxEvtInfo.chNum,
            &chObj);
    }

    return retStat;
}

int32_t UARTAppDmaTxSetup(uartAppObj_t *pObj,
                          uint8_t *pBuf,
                          uint32_t bytesPerEvt,
                          uint32_t noOfBytes)
{
    int32_t retStat = E_FAIL;
    uartAppDmaCfg_t *pUartDmaCfg = &(pObj->uartAppCfg.dmaCfg);
    dmaUtilsDataObj_t fifoDataObj =
    {
        0U,                                        /* addr */
        DMA_XFER_DATA_ADDR_MODE_INC,               /* addrMode */
        0U,                                        /* fifoWidth */
        1U,                                        /* packetActSize */
        1U,                                        /* frameActSize */
        1U,                                        /* blockSize */
        0U,                                        /* packetInactSize */
        0U,                                        /* frameInactSize */
        DMA_UTILS_DATA_SYNC_PACKET                 /* syncMode */
    }; /* dmaUtilsDataObj_t */
    dmaUtilsDataObj_t bufDataObj =
    {
        0U,                                        /* addr */
        DMA_XFER_DATA_ADDR_MODE_INC,               /* addrMode */
        0U,                                        /* fifoWidth */
        1U,                                        /* packetActSize */
        1U,                                        /* frameActSize */
        1U,                                        /* blockSize */
        0U,                                        /* packetInactSize */
        0U,                                        /* frameInactSize */
        DMA_UTILS_DATA_SYNC_PACKET                 /* syncMode */
    }; /* dmaUtilsDataObj_t */
    dmaUtilsXferObj_t xferObj =
    {
        NULL,                                      /* pSrc */
        NULL,                                      /* pDest */
        DMA_UTILS_DATA_SYNC_MASK_BLOCK,            /* intrConfig */
        FALSE,                                     /* linkEnable */
        0U                                         /* nxtXferIdx */
    }; /* dmaUtilsXferObj_t */
    dmaUtilsChObj_t chObj =
    {
        DMA_XFER_TRIGGER_TYPE_EVENT,               /* triggerType */
        0U,                                        /* xferIdx */
        TRUE,                                      /* intrEnable */
        NULL,                                      /* callBack */
        0U                                         /* queueNum */
    }; /* dmaUtilsChObj_t */

    if(NULL != pBuf)
    {
        retStat = S_PASS;
    }

    if((S_PASS == retStat) && (NULL == xferObj.pSrc))
    {
        xferObj.pSrc = &fifoDataObj;
    }

    if((S_PASS == retStat) && (NULL == xferObj.pDst))
    {
        xferObj.pDst = &bufDataObj;
    }

    if(S_PASS == retStat)
    {
        if(1U == xferObj.pSrc->frameActSize)
        {
            xferObj.pSrc->frameActSize =
                noOfBytes / xferObj.pSrc->packetActSize;
            xferObj.pSrc->blockSize = 1U;
        }
        else
        {
            xferObj.pSrc->blockSize =
                noOfBytes / (xferObj.pSrc->packetActSize *
                xferObj.pSrc->frameActSize);
        }

        xferObj.pSrc->addr = (uint32_t)pBuf;
        xferObj.pDst->addr = (uint32_t)(pObj->instAddr + 0U);
        chObj.xferIdx = pUartDmaCfg->txEvtInfo.xferIdx;
        chObj.queueNum = 0U;
        chObj.intrEnable = TRUE;
        chObj.callBack = pObj->uartAppCfg.dmaCfg.pFxnCallBack;
        chObj.triggerType = DMA_XFER_TRIGGER_TYPE_EVENT;

        DMAUtilsDataXferConfig(pUartDmaCfg->dmaType,
            pUartDmaCfg->txEvtInfo.instNum,
            pUartDmaCfg->txEvtInfo.xferIdx,
            &xferObj);
        DMAUtilsChConfig(pUartDmaCfg->dmaType,
            pUartDmaCfg->txEvtInfo.instNum,
            pUartDmaCfg->txEvtInfo.chNum,
            &chObj);
    }

    return retStat;
}

int32_t UARTAppDmaXferStart(uartAppObj_t *pObj, uint32_t evt)
{
    int32_t retStat = S_PASS;
    uartAppDmaCfg_t *pUartDmaCfg = &(pObj->uartAppCfg.dmaCfg);

    if(UART_DMA_EVT_TX == evt)
    {
        DMAUtilsXferStart(pUartDmaCfg->dmaType, pUartDmaCfg->txEvtInfo.instNum,
                          pUartDmaCfg->txEvtInfo.chNum,
                          DMA_XFER_TRIGGER_TYPE_EVENT);
    }
    else if(UART_DMA_EVT_RX == evt)
    {
        DMAUtilsXferStart(pUartDmaCfg->dmaType, pUartDmaCfg->rxEvtInfo.instNum,
                          pUartDmaCfg->rxEvtInfo.chNum,
                          DMA_XFER_TRIGGER_TYPE_EVENT);
    }
    else
    {
        retStat = E_FAIL;
    }

    if(S_PASS == retStat)
    {
        /* Disabling DMA feature in UART. */
        UARTDMADisable(pObj->instAddr);
    }

    return retStat;
}

int32_t UARTAppDmaXferStop(uartAppObj_t *pObj, uint32_t evt)
{
    int32_t retStat = S_PASS;
    uartAppDmaCfg_t *pUartDmaCfg = &(pObj->uartAppCfg.dmaCfg);

    if(UART_DMA_EVT_TX == evt)
    {
        DMAUtilsXferStop(pUartDmaCfg->dmaType, pUartDmaCfg->txEvtInfo.instNum,
                         pUartDmaCfg->txEvtInfo.chNum,
                         DMA_XFER_TRIGGER_TYPE_EVENT);
    }
    else if(UART_DMA_EVT_RX == evt)
    {
        DMAUtilsXferStop(pUartDmaCfg->dmaType, pUartDmaCfg->rxEvtInfo.instNum,
                         pUartDmaCfg->rxEvtInfo.chNum,
                         DMA_XFER_TRIGGER_TYPE_EVENT);
    }
    else
    {
        retStat = E_FAIL;
    }

    if(S_PASS == retStat)
    {
        /* Enabling UART in DMA Mode. */
        UARTDmaEnable(pObj->instAddr, UART_DMA_MODE_MODE1);
    }

    return retStat;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

void UartAppSetBaudRate(uartAppObj_t *pObj, uartBaudRate_t baudRate)
{
    UARTSetBaudRate(pObj->instAddr, UART_MODULE_INPUT_CLK, baudRate);
}

void UartAppLineCharacteristicConfig(uartAppObj_t    *pObj,
                                     uartCharLength_t charLen,
                                     uartStopBit_t    stopBits,
                                     uartParity_t     parity)
{
    /* Set the Line Characteristics for the UART Transmission. */
    UARTLineCharacteristicConfig(pObj->instAddr,
        charLen,
        stopBits,
        parity);
}

static void UartAppFifoConfig(uartAppObj_t *pObj)
{
    uartFifoCfg_t uartFifoCfg;

    uartFifoCfg.uartTxGran = UART_TRIGGER_LVL_GRAN_4;
    uartFifoCfg.uartRxGran = UART_TRIGGER_LVL_GRAN_1;

    /* Set the trigger levels for TX and RX. */
    uartFifoCfg.uartTxTriggerLvl = 56U;
    uartFifoCfg.uartRxTriggerLvl = 1U;
    uartFifoCfg.clearTxFifo = TRUE;
    uartFifoCfg.clearRxFifo = TRUE;
    uartFifoCfg.enableDma = FALSE;

    UARTFifoConfig(pObj->instAddr, &uartFifoCfg);
}

static int32_t UartAppIntrConfig(uartAppObj_t *pObj)
{
    int32_t status = S_PASS;
    intcIntrParams_t intrParams;
    uartAppIntrCfg_t *pUartIntrConfig = &(pObj->uartAppCfg.uartAppIntrCfg);

    /* Initialize the Interrupt Controller */
    if(TRUE == pUartIntrConfig->isIntrSecure)
    {
        INTCInit(INTC_SECURE_MODE);
    }
    else
    {
        INTCInit(INTC_NON_SECURE_MODE);
    }

    if(S_PASS == status)
    {
        /* Do the interrupt related configurations */
        intrParams.triggerType = pUartIntrConfig->intrTrigType;
        intrParams.priority = pUartIntrConfig->intrPriority;
        /*
        ** Assign the ISR to the function pointer to invoke when the
        ** interrupt is raised.
        */
        intrParams.pFnIntrHandler = &UartAppIsr;
        /* Assign the app object to pass to the generic ISR */
        intrParams.pUserParam =  pObj;
        intrParams.isIntrSecure = pUartIntrConfig->isIntrSecure;

        /* Configure the interrupt Controller */
        status = INTCConfigIntr(pUartIntrConfig->intrLine,
            &intrParams,
            pUartIntrConfig->isIntrSecure);
    }

    return status;
}

void UartAppIsr(uint32_t intrId, uint32_t cpuId, void* pUserParam)
{
    uartAppObj_t *pUartObj = (uartAppObj_t *) pUserParam;
    uint16_t status = 0U;
    uint8_t rxByte[UART_READ_SIZE_BYTES];
    /* Checking the source of UART interrupt. */
    status = UARTIntrStatus(pUartObj->instAddr);

    if(UART_INTR_STATUS_TX_THRESHOLD == status)
    {
        pUartObj->isTxFifoEmpty = TRUE;

        /* Disable the TX Threshold interrupt. */
        UARTIntrDisable(pUartObj->instAddr, UART_INTR_TX_THRESHOLD);
    }

    if(UART_INTR_STATUS_RX_THRESHOLD == status)
    {
        UARTGetChar(pUartObj->instAddr,
                    (rxByte +  pUartObj->numRdBytesISR++), 0U);
    }
    if (pUartObj->numRdBytesISR == pUartObj->numRdBytes)
    {
        /* Echo back the received bytes. */
        UARTFifoWrite(pUartObj->instAddr, rxByte, pUartObj->numRdBytes);
    }
}
